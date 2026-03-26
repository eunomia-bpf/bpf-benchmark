// SPDX-License-Identifier: MIT
//! Bulk-memory optimization pass.

use std::collections::HashSet;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, LivenessAnalysis, LivenessResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};

const MEMCPY_TARGET: &str = "bpf_memcpy_bulk";
const MEMSET_TARGET: &str = "bpf_memset_bulk";
const MIN_BULK_BYTES: usize = 32;
const CHUNK_MAX_BYTES: usize = 128;
const BPF_ADD: u8 = 0x00;
const BPF_SUB: u8 = 0x10;
const BPF_XOR: u8 = 0xa0;
const STACK_PTR_REG: u8 = 10;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Const(u64),
}

#[derive(Clone, Debug)]
enum BulkSiteKind {
    Memcpy {
        dst_base: u8,
        src_base: u8,
        dst_off: i16,
        src_off: i16,
        width: u8,
        chunk_sizes: Vec<usize>,
    },
    Memset {
        base: u8,
        dst_off: i16,
        width: u8,
        fill_byte: u8,
        chunk_sizes: Vec<usize>,
    },
}

#[derive(Clone, Debug)]
struct BulkSite {
    start_pc: usize,
    old_len: usize,
    kind: BulkSiteKind,
}

impl BulkSite {
    fn target_name(&self) -> &'static str {
        match self.kind {
            BulkSiteKind::Memcpy { .. } => MEMCPY_TARGET,
            BulkSiteKind::Memset { .. } => MEMSET_TARGET,
        }
    }
}

#[derive(Default)]
struct ScanResult {
    sites: Vec<BulkSite>,
    skips: Vec<SkipReason>,
}

enum MatchOutcome {
    Apply(BulkSite),
    Skip { reason: String, advance: usize },
    NoMatch,
}

#[derive(Clone, Copy)]
struct MemcpyLane {
    width: u8,
    tmp_reg: u8,
    src_base: u8,
    src_off: i16,
    dst_base: u8,
    dst_off: i16,
}

#[derive(Clone, Copy)]
struct MemsetLane {
    width: u8,
    base: u8,
    off: i16,
    fill_byte: u8,
}

/// Recognize large scalarized memcpy/memset runs and lower them to bulk kinsn calls.
pub struct BulkMemoryPass;

impl BpfPass for BulkMemoryPass {
    fn name(&self) -> &str {
        "bulk_memory"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if program.insns.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![],
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let bt = analyses.get(&BranchTargetAnalysis, program);
        let liveness = analyses.get(&LivenessAnalysis, program);

        let scan = scan_sites(&program.insns, &bt, &liveness);
        let mut skipped = scan.skips;

        let memcpy_btf_id = ctx.kinsn_registry.btf_id_for_target_name(MEMCPY_TARGET);
        let memset_btf_id = ctx.kinsn_registry.btf_id_for_target_name(MEMSET_TARGET);

        let mut safe_sites = Vec::new();
        for site in scan.sites {
            if let BulkSiteKind::Memcpy {
                src_base, dst_base, ..
            } = &site.kind
            {
                if src_base != dst_base {
                    let src_stack = is_likely_stack_ptr(*src_base, site.start_pc, &program.insns);
                    let dst_stack = is_likely_stack_ptr(*dst_base, site.start_pc, &program.insns);
                    if src_stack == dst_stack {
                        skipped.push(SkipReason {
                            pc: site.start_pc,
                            reason: format!(
                                "different-base memcpy alias not provably safe (src r{src_base}, dst r{dst_base})"
                            ),
                        });
                        continue;
                    }
                }
            }

            let target = site.target_name();
            let btf_id = match target {
                MEMCPY_TARGET => memcpy_btf_id,
                MEMSET_TARGET => memset_btf_id,
                _ => -1,
            };

            if btf_id < 0 {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!("{target} kfunc not available"),
                });
                continue;
            }

            if !ctx.kinsn_registry.packed_supported_for_target_name(target) {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!("{target} packed ABI not available"),
                });
                continue;
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let memcpy_off = if memcpy_btf_id >= 0 {
            ctx.kinsn_registry
                .btf_fd_for_target_name(MEMCPY_TARGET)
                .map(|fd| ensure_btf_fd_slot(program, fd))
                .unwrap_or(0)
        } else {
            0
        };
        let memset_off = if memset_btf_id >= 0 {
            ctx.kinsn_registry
                .btf_fd_for_target_name(MEMSET_TARGET)
                .map(|fd| ensure_btf_fd_slot(program, fd))
                .unwrap_or(0)
        } else {
            0
        };

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;
        let mut site_idx = 0usize;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                let replacement = emit_site_replacement(
                    site,
                    memcpy_btf_id,
                    memcpy_off,
                    memset_btf_id,
                    memset_off,
                );
                new_insns.extend_from_slice(&replacement);
                for j in 1..site.old_len {
                    addr_map[pc + j] = new_pc;
                }
                pc += site.old_len;
                site_idx += 1;
                continue;
            }

            let insn = program.insns[pc];
            new_insns.push(insn);
            if insn.is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        let applied = safe_sites.len();
        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn scan_sites(insns: &[BpfInsn], bt: &BranchTargetResult, liveness: &LivenessResult) -> ScanResult {
    let mut scan = ScanResult::default();
    let mut regs = [RegValue::Unknown; 11];
    let mut pc = 0usize;

    while pc < insns.len() {
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            regs = [RegValue::Unknown; 11];
        }

        match try_match_memcpy_run_at(insns, pc, bt, liveness) {
            MatchOutcome::Apply(site) => {
                advance_reg_state_range(insns, pc, site.old_len, &mut regs);
                pc += site.old_len;
                scan.sites.push(site);
                continue;
            }
            MatchOutcome::Skip { reason, advance } => {
                let advance = advance.max(1);
                advance_reg_state_range(insns, pc, advance, &mut regs);
                scan.skips.push(SkipReason { pc, reason });
                pc += advance;
                continue;
            }
            MatchOutcome::NoMatch => {}
        }

        if let Some(site) = try_match_memset_run_at(insns, pc, bt, &regs) {
            advance_reg_state_range(insns, pc, site.old_len, &mut regs);
            pc += site.old_len;
            scan.sites.push(site);
            continue;
        }

        advance_reg_state(insns, pc, &mut regs);
        pc += insn_width(&insns[pc]);
    }

    scan
}

fn try_match_memcpy_run_at(
    insns: &[BpfInsn],
    pc: usize,
    bt: &BranchTargetResult,
    liveness: &LivenessResult,
) -> MatchOutcome {
    let Some(first) = memcpy_lane_at(insns, pc) else {
        return MatchOutcome::NoMatch;
    };
    if bt.is_target.get(pc + 1).copied().unwrap_or(false) {
        return MatchOutcome::NoMatch;
    }

    let lane_bytes = width_bytes(first.width);
    let mut cursor = pc + 2;
    let mut pair_count = 1usize;
    let mut tmp_regs = vec![first.tmp_reg];
    let mut next_src_off = first.src_off as i32 + lane_bytes as i32;
    let mut next_dst_off = first.dst_off as i32 + lane_bytes as i32;

    while cursor + 1 < insns.len() {
        if bt.is_target.get(cursor).copied().unwrap_or(false)
            || bt.is_target.get(cursor + 1).copied().unwrap_or(false)
        {
            break;
        }

        let Some(lane) = memcpy_lane_at(insns, cursor) else {
            break;
        };

        if lane.width != first.width
            || lane.src_base != first.src_base
            || lane.dst_base != first.dst_base
            || lane.src_off as i32 != next_src_off
            || lane.dst_off as i32 != next_dst_off
        {
            break;
        }

        pair_count += 1;
        tmp_regs.push(lane.tmp_reg);
        next_src_off += lane_bytes as i32;
        next_dst_off += lane_bytes as i32;
        cursor += 2;
    }

    let raw_len = pair_count * 2;
    let raw_bytes = pair_count * lane_bytes;
    let chunk_sizes = uniform_chunk_sizes(raw_bytes);
    if chunk_sizes.is_empty() {
        return MatchOutcome::NoMatch;
    }

    let consumed_bytes: usize = chunk_sizes.iter().sum();
    let consumed_pairs = consumed_bytes / lane_bytes;
    let old_len = consumed_pairs * 2;
    let last_pc = pc + old_len - 1;

    if first.src_base == first.dst_base && ranges_overlap(first.src_off, first.dst_off, raw_bytes) {
        return MatchOutcome::Skip {
            reason: "overlapping same-base memcpy run".into(),
            advance: raw_len,
        };
    }

    if let Some(live_after) = liveness.live_out.get(last_pc) {
        let mut seen = HashSet::new();
        for tmp_reg in tmp_regs.iter().take(consumed_pairs).copied() {
            if seen.insert(tmp_reg) && live_after.contains(&tmp_reg) {
                return MatchOutcome::Skip {
                    reason: format!("tmp_reg r{tmp_reg} is live after site"),
                    advance: raw_len,
                };
            }
        }
    }

    MatchOutcome::Apply(BulkSite {
        start_pc: pc,
        old_len,
        kind: BulkSiteKind::Memcpy {
            dst_base: first.dst_base,
            src_base: first.src_base,
            dst_off: first.dst_off,
            src_off: first.src_off,
            width: first.width,
            chunk_sizes,
        },
    })
}

fn try_match_memset_run_at(
    insns: &[BpfInsn],
    pc: usize,
    bt: &BranchTargetResult,
    regs: &[RegValue; 11],
) -> Option<BulkSite> {
    let first = memset_lane_at(insns, pc, regs)?;
    let mut cursor = pc + 1;
    let mut widths = vec![first.width];
    let mut next_off = first.off as i32 + width_bytes(first.width) as i32;

    while cursor < insns.len() {
        if bt.is_target.get(cursor).copied().unwrap_or(false) {
            break;
        }

        let Some(lane) = memset_lane_at(insns, cursor, regs) else {
            break;
        };

        if lane.base != first.base
            || lane.fill_byte != first.fill_byte
            || lane.off as i32 != next_off
        {
            break;
        }

        widths.push(lane.width);
        next_off += width_bytes(lane.width) as i32;
        cursor += 1;
    }

    let lane_bytes: Vec<usize> = widths.iter().map(|&width| width_bytes(width)).collect();
    let (chunk_sizes, consumed_lanes) = greedy_store_chunk_sizes(&lane_bytes);
    if chunk_sizes.is_empty() {
        return None;
    }

    let consumed_widths = &widths[..consumed_lanes];
    let payload_width = if consumed_widths
        .iter()
        .all(|&width| width == consumed_widths[0])
    {
        consumed_widths[0]
    } else {
        BPF_B
    };

    Some(BulkSite {
        start_pc: pc,
        old_len: consumed_lanes,
        kind: BulkSiteKind::Memset {
            base: first.base,
            dst_off: first.off,
            width: payload_width,
            fill_byte: first.fill_byte,
            chunk_sizes,
        },
    })
}

fn memcpy_lane_at(insns: &[BpfInsn], pc: usize) -> Option<MemcpyLane> {
    let load = insns.get(pc)?;
    let store = insns.get(pc + 1)?;
    let width = bpf_size(load.code);

    if !load.is_ldx_mem() || !is_supported_width(width) {
        return None;
    }
    if store.class() != BPF_STX || bpf_mode(store.code) != BPF_MEM || bpf_size(store.code) != width
    {
        return None;
    }
    if store.src_reg() != load.dst_reg() {
        return None;
    }
    if load.dst_reg() == load.src_reg() || load.dst_reg() == store.dst_reg() {
        return None;
    }

    Some(MemcpyLane {
        width,
        tmp_reg: load.dst_reg(),
        src_base: load.src_reg(),
        src_off: load.off,
        dst_base: store.dst_reg(),
        dst_off: store.off,
    })
}

fn memset_lane_at(insns: &[BpfInsn], pc: usize, regs: &[RegValue; 11]) -> Option<MemsetLane> {
    let insn = insns.get(pc)?;
    let width = bpf_size(insn.code);
    if !is_supported_width(width) || bpf_mode(insn.code) != BPF_MEM {
        return None;
    }

    let fill_byte = match insn.class() {
        BPF_ST => fill_byte_from_imm(width, insn.imm)?,
        BPF_STX => match regs[insn.src_reg() as usize] {
            RegValue::Const(value) => fill_byte_from_const(width, value)?,
            RegValue::Unknown => return None,
        },
        _ => return None,
    };
    if fill_byte != 0 {
        return None;
    }

    Some(MemsetLane {
        width,
        base: insn.dst_reg(),
        off: insn.off,
        fill_byte,
    })
}

fn emit_site_replacement(
    site: &BulkSite,
    memcpy_btf_id: i32,
    memcpy_off: i16,
    memset_btf_id: i32,
    memset_off: i16,
) -> Vec<BpfInsn> {
    match &site.kind {
        BulkSiteKind::Memcpy {
            dst_base,
            src_base,
            dst_off,
            src_off,
            width,
            chunk_sizes,
        } => {
            let mut out = Vec::with_capacity(chunk_sizes.len() * 2);
            let mut cur_dst_off = *dst_off as i32;
            let mut cur_src_off = *src_off as i32;
            for &chunk_size in chunk_sizes {
                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
                    pack_memcpy_payload(
                        *dst_base,
                        *src_base,
                        cur_dst_off as i16,
                        cur_src_off as i16,
                        chunk_size as u8,
                        *width,
                    ),
                    memcpy_btf_id,
                    memcpy_off,
                ));
                cur_dst_off += chunk_size as i32;
                cur_src_off += chunk_size as i32;
            }
            out
        }
        BulkSiteKind::Memset {
            base,
            dst_off,
            width,
            fill_byte,
            chunk_sizes,
        } => {
            let mut out = Vec::with_capacity(chunk_sizes.len() * 2);
            let mut cur_dst_off = *dst_off as i32;
            for &chunk_size in chunk_sizes {
                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
                    pack_memset_payload(
                        *base,
                        cur_dst_off as i16,
                        chunk_size as u8,
                        *width,
                        *fill_byte,
                    ),
                    memset_btf_id,
                    memset_off,
                ));
                cur_dst_off += chunk_size as i32;
            }
            out
        }
    }
}

fn pack_memcpy_payload(
    dst_base: u8,
    src_base: u8,
    dst_off: i16,
    src_off: i16,
    len: u8,
    width: u8,
) -> u64 {
    (dst_base as u64)
        | ((src_base as u64) << 4)
        | ((dst_off as u16 as u64) << 8)
        | ((src_off as u16 as u64) << 24)
        | (((len - 1) as u64) << 40)
        | (width_class(width) << 48)
}

fn pack_memset_payload(base: u8, dst_off: i16, len: u8, width: u8, fill_byte: u8) -> u64 {
    let zero_fill = fill_byte == 0;
    (base as u64)
        | ((dst_off as u16 as u64) << 8)
        | (((len - 1) as u64) << 24)
        | (width_class(width) << 32)
        | ((zero_fill as u64) << 35)
        | ((fill_byte as u64) << 36)
}

fn width_class(size: u8) -> u64 {
    match size {
        BPF_B => 0,
        BPF_H => 1,
        BPF_W => 2,
        BPF_DW => 3,
        _ => 0,
    }
}

fn uniform_chunk_sizes(total_bytes: usize) -> Vec<usize> {
    if total_bytes < MIN_BULK_BYTES {
        return Vec::new();
    }

    let full_chunks = total_bytes / CHUNK_MAX_BYTES;
    let tail = total_bytes % CHUNK_MAX_BYTES;
    let mut chunks = vec![CHUNK_MAX_BYTES; full_chunks];
    if tail >= MIN_BULK_BYTES {
        chunks.push(tail);
    } else if chunks.is_empty() {
        return Vec::new();
    }
    chunks
}

fn greedy_store_chunk_sizes(lane_bytes: &[usize]) -> (Vec<usize>, usize) {
    let mut chunks = Vec::new();
    let mut chunk_lanes = Vec::new();
    let mut current_bytes = 0usize;
    let mut current_lanes = 0usize;

    for &lane_bytes in lane_bytes {
        if current_bytes > 0 && current_bytes + lane_bytes > CHUNK_MAX_BYTES {
            chunks.push(current_bytes);
            chunk_lanes.push(current_lanes);
            current_bytes = 0;
            current_lanes = 0;
        }

        current_bytes += lane_bytes;
        current_lanes += 1;
    }

    if current_lanes > 0 {
        chunks.push(current_bytes);
        chunk_lanes.push(current_lanes);
    }

    if chunks.last().copied().unwrap_or(0) < MIN_BULK_BYTES {
        chunks.pop();
        chunk_lanes.pop();
    }

    (chunks, chunk_lanes.into_iter().sum())
}

fn fill_byte_from_imm(width: u8, imm: i32) -> Option<u8> {
    let value = match width {
        BPF_B => imm as u8 as u64,
        BPF_H => imm as i16 as u16 as u64,
        BPF_W => imm as u32 as u64,
        BPF_DW => imm as i64 as u64,
        _ => return None,
    };
    fill_byte_from_const(width, value)
}

fn fill_byte_from_const(width: u8, value: u64) -> Option<u8> {
    let lane_bytes = width_bytes(width);
    let fill = value as u8;
    for byte_idx in 0..lane_bytes {
        if ((value >> (byte_idx * 8)) & 0xff) as u8 != fill {
            return None;
        }
    }
    Some(fill)
}

fn ranges_overlap(src_off: i16, dst_off: i16, len: usize) -> bool {
    let src_start = src_off as i32;
    let dst_start = dst_off as i32;
    let len = len as i32;
    src_start < dst_start + len && dst_start < src_start + len
}

fn is_supported_width(width: u8) -> bool {
    matches!(width, BPF_B | BPF_H | BPF_W | BPF_DW)
}

fn width_bytes(width: u8) -> usize {
    match width {
        BPF_B => 1,
        BPF_H => 2,
        BPF_W => 4,
        BPF_DW => 8,
        _ => 0,
    }
}

fn is_likely_stack_ptr(reg: u8, before_pc: usize, insns: &[BpfInsn]) -> bool {
    if reg == STACK_PTR_REG {
        return true;
    }

    const LOOKBACK: usize = 32;
    let start = before_pc.saturating_sub(LOOKBACK);
    let mut target_reg = reg;
    let mut cursor = before_pc;

    for _ in 0..LOOKBACK {
        let mut found_def = false;
        for pc in (start..cursor).rev() {
            let insn = &insns[pc];
            if !writes_reg(insn, target_reg) {
                continue;
            }

            found_def = true;
            if insn.class() == BPF_ALU64
                && insn.dst_reg() == target_reg
                && bpf_src(insn.code) == BPF_X
                && bpf_op(insn.code) == BPF_MOV
            {
                let src_reg = insn.src_reg();
                if src_reg == STACK_PTR_REG {
                    return true;
                }
                target_reg = src_reg;
                cursor = pc;
                break;
            }

            if insn.class() == BPF_ALU64
                && insn.dst_reg() == target_reg
                && bpf_src(insn.code) == BPF_K
                && matches!(bpf_op(insn.code), BPF_ADD | BPF_SUB)
            {
                cursor = pc;
                break;
            }

            return false;
        }

        if !found_def {
            return false;
        }
    }

    false
}

fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.is_call() {
        return reg <= 5;
    }
    if insn.is_ldimm64() {
        return insn.dst_reg() == reg;
    }

    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        _ => false,
    }
}

fn advance_reg_state_range(
    insns: &[BpfInsn],
    start_pc: usize,
    len: usize,
    regs: &mut [RegValue; 11],
) {
    let end_pc = start_pc.saturating_add(len).min(insns.len());
    let mut pc = start_pc;
    while pc < end_pc {
        advance_reg_state(insns, pc, regs);
        pc += insn_width(&insns[pc]);
    }
}

fn advance_reg_state(insns: &[BpfInsn], pc: usize, regs: &mut [RegValue; 11]) {
    let insn = &insns[pc];

    if insn.is_call() {
        for reg in 0..=5 {
            regs[reg] = RegValue::Unknown;
        }
        return;
    }

    if insn.is_ldimm64() {
        let next = insns.get(pc + 1);
        regs[insn.dst_reg() as usize] = next
            .map(|hi| combine_ldimm64(insn, hi) as u64)
            .map(RegValue::Const)
            .unwrap_or(RegValue::Unknown);
        return;
    }

    match insn.class() {
        BPF_ALU64 => advance_alu64_state(insn, regs),
        BPF_ALU => advance_alu32_state(insn, regs),
        BPF_LDX | BPF_LD => regs[insn.dst_reg() as usize] = RegValue::Unknown,
        _ => {}
    }
}

fn advance_alu64_state(insn: &BpfInsn, regs: &mut [RegValue; 11]) {
    let dst = insn.dst_reg() as usize;
    let next = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_K) => RegValue::Const(insn.imm as i64 as u64),
        (BPF_MOV, BPF_X) => regs[insn.src_reg() as usize],
        (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => RegValue::Const(0),
        _ => RegValue::Unknown,
    };
    regs[dst] = next;
}

fn advance_alu32_state(insn: &BpfInsn, regs: &mut [RegValue; 11]) {
    let dst = insn.dst_reg() as usize;
    let next = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_K) => RegValue::Const(insn.imm as u32 as u64),
        (BPF_MOV, BPF_X) => match regs[insn.src_reg() as usize] {
            RegValue::Const(value) => RegValue::Const(value as u32 as u64),
            RegValue::Unknown => RegValue::Unknown,
        },
        (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => RegValue::Const(0),
        _ => RegValue::Unknown,
    };
    regs[dst] = next;
}

fn combine_ldimm64(lo: &BpfInsn, hi: &BpfInsn) -> i64 {
    let low = lo.imm as u32 as u64;
    let high = hi.imm as u32 as u64;
    i64::from_le_bytes((low | (high << 32)).to_le_bytes())
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use std::collections::HashMap;

    use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};
    const MEMCPY_BTF_ID: i32 = 4101;
    const MEMSET_BTF_ID: i32 = 4102;

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns)
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ST | size | BPF_MEM,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn width_bytes(size: u8) -> i16 {
        match size {
            BPF_B => 1,
            BPF_H => 2,
            BPF_W => 4,
            BPF_DW => 8,
            other => panic!("unsupported size code {other:#x}"),
        }
    }

    fn width_class(size: u8) -> u64 {
        match size {
            BPF_B => 0,
            BPF_H => 1,
            BPF_W => 2,
            BPF_DW => 3,
            other => panic!("unsupported size code {other:#x}"),
        }
    }

    fn pack_memcpy_payload(
        dst_base: u8,
        src_base: u8,
        dst_off: i16,
        src_off: i16,
        len: u8,
        size: u8,
    ) -> u64 {
        assert!((1..=128).contains(&len));
        (dst_base as u64)
            | ((src_base as u64) << 4)
            | ((dst_off as u16 as u64) << 8)
            | ((src_off as u16 as u64) << 24)
            | (((len - 1) as u64) << 40)
            | (width_class(size) << 48)
    }

    fn pack_memset_payload(
        dst_base: u8,
        val_reg: u8,
        dst_off: i16,
        len: u8,
        size: u8,
        value_from_reg: bool,
        zero_fill: bool,
        fill_imm8: u8,
    ) -> u64 {
        assert!((1..=128).contains(&len));
        (dst_base as u64)
            | ((val_reg as u64) << 4)
            | ((dst_off as u16 as u64) << 8)
            | (((len - 1) as u64) << 24)
            | (width_class(size) << 32)
            | ((value_from_reg as u64) << 34)
            | ((zero_fill as u64) << 35)
            | ((fill_imm8 as u64) << 36)
    }

    fn memcpy_call(
        dst_base: u8,
        dst_off: i16,
        src_base: u8,
        src_off: i16,
        len: u8,
        size: u8,
    ) -> Vec<BpfInsn> {
        emit_packed_kinsn_call_with_off(
            pack_memcpy_payload(dst_base, src_base, dst_off, src_off, len, size),
            MEMCPY_BTF_ID,
            0,
        )
    }

    fn memset_zero_call(dst_base: u8, dst_off: i16, len: u8, size: u8) -> Vec<BpfInsn> {
        emit_packed_kinsn_call_with_off(
            pack_memset_payload(dst_base, 0, dst_off, len, size, false, true, 0),
            MEMSET_BTF_ID,
            0,
        )
    }

    fn make_memcpy_run(
        size: u8,
        tmp_reg: u8,
        src_base: u8,
        src_off: i16,
        dst_base: u8,
        dst_off: i16,
        lanes: usize,
    ) -> Vec<BpfInsn> {
        let stride = width_bytes(size);
        let mut insns = Vec::with_capacity(lanes * 2);
        for lane in 0..lanes {
            let lane_off = stride * lane as i16;
            insns.push(BpfInsn::ldx_mem(
                size,
                tmp_reg,
                src_base,
                src_off + lane_off,
            ));
            insns.push(BpfInsn::stx_mem(
                size,
                dst_base,
                tmp_reg,
                dst_off + lane_off,
            ));
        }
        insns
    }

    fn make_st_mem_zero_run(size: u8, dst_base: u8, dst_off: i16, lanes: usize) -> Vec<BpfInsn> {
        let stride = width_bytes(size);
        let mut insns = Vec::with_capacity(lanes);
        for lane in 0..lanes {
            insns.push(st_mem(size, dst_base, dst_off + stride * lane as i16, 0));
        }
        insns
    }

    fn make_stx_mem_run(
        size: u8,
        src_reg: u8,
        dst_base: u8,
        dst_off: i16,
        lanes: usize,
    ) -> Vec<BpfInsn> {
        let stride = width_bytes(size);
        let mut insns = Vec::with_capacity(lanes);
        for lane in 0..lanes {
            insns.push(BpfInsn::stx_mem(
                size,
                dst_base,
                src_reg,
                dst_off + stride * lane as i16,
            ));
        }
        insns
    }

    fn make_memcpy_program_8_pairs() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8);
        insns.push(exit_insn());
        insns
    }

    fn make_memset_zero_program() -> Vec<BpfInsn> {
        let mut insns = make_st_mem_zero_run(BPF_DW, 10, -64, 8);
        insns.push(exit_insn());
        insns
    }

    fn make_no_consecutive_stores_program() -> Vec<BpfInsn> {
        vec![
            st_mem(BPF_DW, 10, -64, 0),
            BpfInsn::mov64_imm(8, 1),
            st_mem(BPF_DW, 10, -40, 0),
            st_mem(BPF_DW, 10, -8, 0),
            exit_insn(),
        ]
    }

    fn make_below_threshold_program() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -24, 3);
        insns.push(exit_insn());
        insns
    }

    fn make_different_base_regs_program() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 4);
        insns.extend(make_memcpy_run(BPF_DW, 3, 10, -32, 8, 0, 4));
        insns.push(exit_insn());
        insns
    }

    fn make_non_consecutive_offsets_program() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 4);
        insns.extend(make_memcpy_run(BPF_DW, 3, 6, 40, 10, -24, 4));
        insns.push(exit_insn());
        insns
    }

    fn make_mixed_widths_program() -> Vec<BpfInsn> {
        let mut insns = make_st_mem_zero_run(BPF_W, 10, -32, 4);
        insns.extend(make_st_mem_zero_run(BPF_DW, 10, -16, 2));
        insns.push(exit_insn());
        insns
    }

    fn make_memcpy_preserves_surrounding_program() -> Vec<BpfInsn> {
        let mut insns = vec![BpfInsn::mov64_imm(8, 7)];
        insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
        insns.push(BpfInsn::mov64_reg(0, 8));
        insns.push(exit_insn());
        insns
    }

    fn make_branch_fixup_program() -> Vec<BpfInsn> {
        let mut insns = vec![jeq_imm(0, 0, 17)];
        insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns
    }

    fn make_interleaved_non_store_program() -> Vec<BpfInsn> {
        let mut insns = make_st_mem_zero_run(BPF_DW, 10, -64, 4);
        insns.push(BpfInsn::mov64_imm(9, 1));
        insns.extend(make_st_mem_zero_run(BPF_DW, 10, -32, 4));
        insns.push(exit_insn());
        insns
    }

    fn make_same_base_chunked_overlap_program() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 10, -200, 10, -70, 19);
        insns.push(exit_insn());
        insns
    }

    fn make_nonzero_memset_reg_program() -> Vec<BpfInsn> {
        let mut insns = vec![BpfInsn::mov64_imm(8, 0x5a5a5a5a)];
        insns.extend(make_stx_mem_run(BPF_W, 8, 10, -32, 8));
        insns.push(exit_insn());
        insns
    }

    fn make_non_stack_base_memcpy_program() -> Vec<BpfInsn> {
        let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 8, 0, 4);
        insns.push(exit_insn());
        insns
    }

    fn ctx_with_bulk_kfuncs() -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kinsn_registry.memcpy_bulk_btf_id = MEMCPY_BTF_ID;
        ctx.kinsn_registry.memset_bulk_btf_id = MEMSET_BTF_ID;
        ctx.kinsn_registry.target_supported_encodings = HashMap::from([
            (MEMCPY_TARGET.to_string(), BPF_KINSN_ENC_PACKED_CALL),
            (MEMSET_TARGET.to_string(), BPF_KINSN_ENC_PACKED_CALL),
        ]);
        ctx
    }

    fn run_bulk_memory_pass(program: &mut BpfProgram, ctx: &PassContext) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(BulkMemoryPass);
        pm.run(program, ctx).unwrap()
    }

    fn bulk_call_count(insns: &[BpfInsn], btf_id: i32) -> usize {
        insns
            .iter()
            .filter(|insn| {
                insn.is_call() && insn.src_reg() == BPF_PSEUDO_KINSN_CALL && insn.imm == btf_id
            })
            .count()
    }

    #[test]
    fn test_empty_program() {
        let mut program = make_program(vec![]);

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_consecutive_stores() {
        let original = make_no_consecutive_stores_program();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_memcpy_pattern_8_pairs() {
        let mut program = make_program(make_memcpy_program_8_pairs());
        let mut expected = memcpy_call(10, -64, 6, 0, 64, BPF_DW);
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_memset_zero_pattern() {
        let mut program = make_program(make_memset_zero_program());
        let mut expected = memset_zero_call(10, -64, 64, BPF_DW);
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_below_threshold_unchanged() {
        let original = make_below_threshold_program();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_different_base_regs_not_merged() {
        let mut program = make_program(make_different_base_regs_program());
        let mut expected = memcpy_call(10, -64, 6, 0, 32, BPF_DW);
        expected.extend(memcpy_call(8, 0, 10, -32, 32, BPF_DW));
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 2);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_non_stack_base_memcpy_skipped_by_alias_gate() {
        let original = make_non_stack_base_memcpy_program();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("alias not provably safe")));
    }

    #[test]
    fn test_non_consecutive_offsets_split() {
        let mut program = make_program(make_non_consecutive_offsets_program());
        let mut expected = memcpy_call(10, -64, 6, 0, 32, BPF_DW);
        expected.extend(memcpy_call(10, -24, 6, 40, 32, BPF_DW));
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 2);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_mixed_widths_handled() {
        let mut program = make_program(make_mixed_widths_program());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), 1);
        assert_eq!(program.insns.last(), Some(&exit_insn()));
    }

    #[test]
    fn test_memcpy_preserves_surrounding() {
        let mut program = make_program(make_memcpy_preserves_surrounding_program());
        let mut expected = vec![BpfInsn::mov64_imm(8, 7)];
        expected.extend(memcpy_call(10, -64, 6, 0, 64, BPF_DW));
        expected.push(BpfInsn::mov64_reg(0, 8));
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(program.insns, expected);
        assert_eq!(result.pass_results[0].sites_applied, 1);
    }

    #[test]
    fn test_branch_fixup_after_replacement() {
        let mut program = make_program(make_branch_fixup_program());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 1);
        assert_eq!(program.insns[0], jeq_imm(0, 0, 3));
    }

    #[test]
    fn test_interleaved_non_store_splits() {
        let mut program = make_program(make_interleaved_non_store_program());
        let mut expected = memset_zero_call(10, -64, 32, BPF_DW);
        expected.push(BpfInsn::mov64_imm(9, 1));
        expected.extend(memset_zero_call(10, -32, 32, BPF_DW));
        expected.push(exit_insn());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), 2);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_kfunc_not_available_skipped() {
        let original = make_memcpy_program_8_pairs();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &PassContext::test_default());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains(MEMCPY_TARGET)));
    }

    #[test]
    fn test_same_base_chunked_overlap_skipped() {
        let original = make_same_base_chunked_overlap_program();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("overlapping same-base memcpy run")));
    }

    #[test]
    fn test_memset_nonzero_reg_skipped_by_default() {
        let original = make_nonzero_memset_reg_program();
        let mut program = make_program(original.clone());

        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), 0);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }
}
