// SPDX-License-Identifier: MIT
//! Bulk-memory optimization pass.

use std::collections::HashSet;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, LivenessAnalysis, LivenessResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, insn_width,
    kinsn_replacement_subprog_skip_reason, map_replacement_range, remap_kinsn_btf_metadata,
    resolve_kinsn_call_off_for_target,
};

const MEMCPY_TARGET: &str = "bpf_memcpy_bulk";
const MEMSET_TARGET: &str = "bpf_memset_bulk";
const MIN_BULK_BYTES: usize = 32;
const CHUNK_MAX_BYTES: usize = 128;
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
        temp_reg: u8,
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

    fn replacement_len(&self) -> usize {
        match &self.kind {
            BulkSiteKind::Memcpy { chunk_sizes, .. } | BulkSiteKind::Memset { chunk_sizes, .. } => {
                chunk_sizes.len() * 2
            }
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
            return Ok(PassResult::unchanged(self.name()));
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

            if let Some(reason) = kinsn_replacement_subprog_skip_reason(
                &program.insns,
                site.start_pc,
                site.old_len,
                site.replacement_len(),
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let memcpy_off = if memcpy_btf_id >= 0 {
            resolve_kinsn_call_off_for_target(ctx, MEMCPY_TARGET)?
        } else {
            0
        };
        let memset_off = if memset_btf_id >= 0 {
            resolve_kinsn_call_off_for_target(ctx, MEMSET_TARGET)?
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
                map_replacement_range(&mut addr_map, pc, site.old_len, new_pc, replacement.len());
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
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
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
            temp_reg: first.tmp_reg,
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
            temp_reg,
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
                        *temp_reg,
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
    temp_reg: u8,
) -> u64 {
    (dst_base as u64)
        | ((src_base as u64) << 4)
        | ((dst_off as u16 as u64) << 8)
        | ((src_off as u16 as u64) << 24)
        | (((len - 1) as u64) << 40)
        | ((temp_reg as u64) << 48)
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
        for reg in regs.iter_mut().take(6) {
            *reg = RegValue::Unknown;
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

#[cfg(test)]
#[path = "bulk_memory_tests.rs"]
mod tests;
