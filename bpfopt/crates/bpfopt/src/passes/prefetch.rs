// SPDX-License-Identifier: MIT
//! PREFETCH optimization pass.

use std::collections::BTreeMap;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, CFGAnalysis, CFGResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, insn_width,
    remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_target,
};

const HELPER_MAP_LOOKUP_ELEM: i32 = kernel_sys::BPF_FUNC_map_lookup_elem as i32;
const HELPER_XDP_ADJUST_HEAD: i32 = kernel_sys::BPF_FUNC_xdp_adjust_head as i32;
const PREFETCH_TARGET_NAME: &str = "bpf_prefetch";
const TARGET_PREFETCH_DISTANCE: usize = 8;
const MAX_PREFETCH_DISTANCE: usize = 16;
const MAP_VALUE_LOOKAHEAD: usize = 64;

const BPF_PROG_TYPE_SCHED_CLS: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_ACT;
const BPF_PROG_TYPE_XDP: u32 = kernel_sys::BPF_PROG_TYPE_XDP;
const BPF_PROG_TYPE_SK_SKB: u32 = kernel_sys::BPF_PROG_TYPE_SK_SKB;
const BPF_PROG_TYPE_LWT_IN: u32 = kernel_sys::BPF_PROG_TYPE_LWT_IN;
const BPF_PROG_TYPE_LWT_OUT: u32 = kernel_sys::BPF_PROG_TYPE_LWT_OUT;
const BPF_PROG_TYPE_LWT_XMIT: u32 = kernel_sys::BPF_PROG_TYPE_LWT_XMIT;

const XDP_DATA_OFF: i16 = 0;
const XDP_DATA_END_OFF: i16 = 4;
const SKB_DATA_OFF: i16 = 76;
const SKB_DATA_END_OFF: i16 = 80;

/// Packet/map-value prefetch pass.
///
/// The default mode is structural: emit `bpf_prefetch(ptr)` before direct packet
/// accesses and before the first dereference of a value returned by
/// `map_lookup_elem`. If real per-site PMU data is present for a candidate, it is
/// used as an admission filter; missing PMU data does not block structural
/// candidates.
pub struct PrefetchPass;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PrefetchKind {
    MapValue,
    Packet,
}

#[derive(Clone, Copy, Debug)]
struct PrefetchSite {
    anchor_pc: usize,
    target_pc: usize,
    ptr_reg: u8,
    ptr_def_end_pc: usize,
    kind: PrefetchKind,
}

#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target_pc: usize,
    insert_pc: usize,
    ptr_reg: u8,
    score: u64,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum TrackedValue {
    Unknown,
    Ctx,
    PacketData { def_end_pc: usize },
    PacketEnd,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegWriteKind {
    Explicit,
    CallClobber,
}

fn prefetch_payload(ptr_reg: u8) -> anyhow::Result<u64> {
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(u64::from(ptr_reg))
}

#[cfg(test)]
fn decode_prefetch_payload(payload: u64) -> anyhow::Result<u8> {
    let ptr_reg = (payload & 0xf) as u8;
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    if ((payload >> 4) & 0xf) != 0 {
        anyhow::bail!("prefetch payload has unsupported hint kind");
    }
    if payload >> 8 != 0 {
        anyhow::bail!("prefetch payload has non-zero reserved bits");
    }
    Ok(ptr_reg)
}

impl BpfPass for PrefetchPass {
    fn name(&self) -> &str {
        "prefetch"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if ctx.kinsn_registry.prefetch_btf_id < 0 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_prefetch kfunc not available".into(),
                },
            ));
        }

        if !ctx
            .kinsn_registry
            .packed_supported_for_target_name(PREFETCH_TARGET_NAME)
        {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_prefetch packed ABI not available".into(),
                },
            ));
        }

        let cfg_analysis = CFGAnalysis;
        let cfg = analyses.get(&cfg_analysis, program);
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let mut candidates = Vec::new();
        let mut skipped = Vec::new();

        for site in scan_prefetch_sites(&program.insns, &cfg, &bt, ctx.prog_type) {
            let score = match prefetch_profile_for_site(program, site) {
                Some(profile) => {
                    if let Some(reason) = prefetch_profile_skip_reason(site.target_pc, profile)? {
                        skipped.push(SkipReason {
                            pc: site.target_pc,
                            reason,
                        });
                        continue;
                    }
                    profile.execution_count
                }
                None => default_site_score(site),
            };

            let insert_pc = match choose_prefetch_insert_pc(program, &cfg, site) {
                Ok(insert_pc) => insert_pc,
                Err(reason) => {
                    skipped.push(SkipReason {
                        pc: site.target_pc,
                        reason,
                    });
                    continue;
                }
            };

            candidates.push(PrefetchCandidate {
                target_pc: site.target_pc,
                insert_pc,
                ptr_reg: site.ptr_reg,
                score,
            });
        }

        let candidates = dedup_candidates(candidates);
        if candidates.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let btf_id = ctx.kinsn_registry.prefetch_btf_id;
        let kfunc_off = resolve_kinsn_call_off_for_target(ctx, PREFETCH_TARGET_NAME)?;
        let insertions = group_candidates_by_insert_pc(&candidates);

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len + candidates.len() * 2);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            let new_pc = new_insns.len();
            if let Some(prefetches) = insertions.get(&pc) {
                addr_map[pc] = new_pc;
                for candidate in prefetches {
                    let payload = prefetch_payload(candidate.ptr_reg)?;
                    let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                    new_insns.extend_from_slice(&replacement);
                }
            } else {
                addr_map[pc] = new_pc;
            }

            new_insns.push(program.insns[pc]);
            if program.insns[pc].is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: candidates.len(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: candidates.len(),
            sites_skipped: skipped,
            ..Default::default()
        })
    }
}

fn scan_prefetch_sites(
    insns: &[BpfInsn],
    cfg: &CFGResult,
    bt: &BranchTargetResult,
    prog_type: u32,
) -> Vec<PrefetchSite> {
    let mut sites = scan_map_value_prefetch_sites(insns, cfg);
    if let Some(layout) = packet_ctx_layout(prog_type) {
        sites.extend(scan_packet_prefetch_sites(insns, bt, layout));
    }
    sites
}

fn prefetch_profile_for_site<'a>(
    program: &'a BpfProgram,
    site: PrefetchSite,
) -> Option<&'a PrefetchProfile> {
    program
        .annotations
        .get(site.target_pc)
        .and_then(|ann| ann.prefetch_profile.as_ref())
        .or_else(|| {
            program
                .annotations
                .get(site.anchor_pc)
                .and_then(|ann| ann.prefetch_profile.as_ref())
        })
}

fn default_site_score(site: PrefetchSite) -> u64 {
    match site.kind {
        PrefetchKind::MapValue => 2,
        PrefetchKind::Packet => 1,
    }
}

fn prefetch_profile_skip_reason(
    pc: usize,
    profile: &PrefetchProfile,
) -> anyhow::Result<Option<String>> {
    if profile.execution_count == 0 {
        return Ok(Some("prefetch site execution_count is zero".into()));
    }
    if profile.cache_misses > profile.cache_references {
        anyhow::bail!(
            "prefetch candidate at pc {pc} has cache_misses {} exceeding cache_references {}",
            profile.cache_misses,
            profile.cache_references
        );
    }
    if !profile.miss_rate.is_finite() || !(0.0..=1.0).contains(&profile.miss_rate) {
        anyhow::bail!(
            "prefetch candidate at pc {pc} has invalid cache miss_rate {}",
            profile.miss_rate
        );
    }
    if profile.cache_references == 0 {
        return Ok(Some("prefetch site has zero cache_references".into()));
    }
    if profile.cache_misses == 0 || profile.miss_rate == 0.0 {
        return Ok(Some("prefetch site has no observed cache misses".into()));
    }
    Ok(None)
}

fn scan_map_value_prefetch_sites(insns: &[BpfInsn], cfg: &CFGResult) -> Vec<PrefetchSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
            if let Some(site) = first_map_value_deref_after_lookup(insns, cfg, pc) {
                sites.push(site);
            }
        }
        pc += insn_width(insn);
    }

    sites
}

fn first_map_value_deref_after_lookup(
    insns: &[BpfInsn],
    cfg: &CFGResult,
    call_pc: usize,
) -> Option<PrefetchSite> {
    let (_, subprog_end) = subprog_bounds(cfg, insns.len(), call_pc)?;
    let scan_end = subprog_end.min(call_pc.saturating_add(MAP_VALUE_LOOKAHEAD));
    let mut aliases = [None::<usize>; 11];
    aliases[BPF_REG_0 as usize] = Some(call_pc + 1);
    let mut pc = call_pc + 1;

    while pc < scan_end {
        let insn = &insns[pc];
        let width = insn_width(insn);

        if let Some(base_reg) = memory_base_reg(insn) {
            if let Some(def_end_pc) = aliases[base_reg as usize] {
                return Some(PrefetchSite {
                    anchor_pc: call_pc,
                    target_pc: pc,
                    ptr_reg: base_reg,
                    ptr_def_end_pc: def_end_pc,
                    kind: PrefetchKind::MapValue,
                });
            }
        }

        if stops_map_value_scan(insn) {
            break;
        }
        apply_map_value_alias_transfer(insn, pc, width, &mut aliases);
        pc += width;
    }

    None
}

fn stops_map_value_scan(insn: &BpfInsn) -> bool {
    insn.is_call()
        || insn.is_exit()
        || insn.is_ldimm64_pseudo_func()
        || (insn.is_ja() && insn.off != 0)
}

fn apply_map_value_alias_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    aliases: &mut [Option<usize>; 11],
) {
    if insn.is_ldimm64() {
        aliases[insn.dst_reg() as usize] = None;
        return;
    }

    match insn.class() {
        BPF_ALU64 => apply_map_value_alu64_transfer(insn, pc, width, aliases),
        BPF_ALU | BPF_LD | BPF_LDX => aliases[insn.dst_reg() as usize] = None,
        _ => {}
    }
}

fn apply_map_value_alu64_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    aliases: &mut [Option<usize>; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            aliases[dst] = aliases[insn.src_reg() as usize].map(|_| pc + width);
        }
        (BPF_ADD | BPF_SUB, BPF_K) if aliases[dst].is_some() => {
            aliases[dst] = Some(pc + width);
        }
        _ => aliases[dst] = None,
    }
}

fn scan_packet_prefetch_sites(
    insns: &[BpfInsn],
    bt: &BranchTargetResult,
    layout: PacketCtxLayout,
) -> Vec<PrefetchSite> {
    let mut sites = Vec::new();
    let mut regs = initial_packet_regs();
    let mut pc = 0usize;

    while pc < insns.len() {
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            regs = [TrackedValue::Unknown; 11];
        }

        let insn = &insns[pc];
        let width = insn_width(insn);
        if let Some(base_reg) = memory_base_reg(insn) {
            if let TrackedValue::PacketData { def_end_pc } = regs[base_reg as usize] {
                sites.push(PrefetchSite {
                    anchor_pc: pc,
                    target_pc: pc,
                    ptr_reg: base_reg,
                    ptr_def_end_pc: def_end_pc,
                    kind: PrefetchKind::Packet,
                });
            }
        }

        apply_packet_transfer(insn, pc, width, layout, &mut regs);
        pc += width;
    }

    sites
}

fn packet_ctx_layout(prog_type: u32) -> Option<PacketCtxLayout> {
    match prog_type {
        BPF_PROG_TYPE_XDP => Some(PacketCtxLayout {
            data_off: XDP_DATA_OFF,
            data_end_off: XDP_DATA_END_OFF,
        }),
        BPF_PROG_TYPE_SCHED_CLS
        | BPF_PROG_TYPE_SCHED_ACT
        | BPF_PROG_TYPE_SK_SKB
        | BPF_PROG_TYPE_LWT_IN
        | BPF_PROG_TYPE_LWT_OUT
        | BPF_PROG_TYPE_LWT_XMIT => Some(PacketCtxLayout {
            data_off: SKB_DATA_OFF,
            data_end_off: SKB_DATA_END_OFF,
        }),
        _ => None,
    }
}

fn initial_packet_regs() -> [TrackedValue; 11] {
    let mut regs = [TrackedValue::Unknown; 11];
    regs[BPF_REG_1 as usize] = TrackedValue::Ctx;
    regs
}

fn apply_packet_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
) {
    if insn.is_call() {
        if insn.src_reg() == 0 && insn.imm == HELPER_XDP_ADJUST_HEAD {
            for reg in regs.iter_mut() {
                *reg = TrackedValue::Unknown;
            }
        } else {
            for reg in regs.iter_mut().take(6) {
                *reg = TrackedValue::Unknown;
            }
        }
        return;
    }

    if insn.is_ldimm64() {
        regs[insn.dst_reg() as usize] = TrackedValue::Unknown;
        return;
    }

    match insn.class() {
        BPF_LDX if bpf_mode(insn.code) == BPF_MEM => {
            apply_packet_ldx_transfer(insn, pc, width, layout, regs);
        }
        BPF_ALU64 => apply_packet_alu64_transfer(insn, pc, width, regs),
        BPF_ALU | BPF_LD => regs[insn.dst_reg() as usize] = TrackedValue::Unknown,
        _ => {}
    }
}

fn apply_packet_ldx_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
) {
    let dst = insn.dst_reg() as usize;
    regs[dst] = match regs[insn.src_reg() as usize] {
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_off => {
            TrackedValue::PacketData {
                def_end_pc: pc + width,
            }
        }
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_end_off => {
            TrackedValue::PacketEnd
        }
        _ => TrackedValue::Unknown,
    };
}

fn apply_packet_alu64_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    regs: &mut [TrackedValue; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            regs[dst] = match regs[insn.src_reg() as usize] {
                TrackedValue::PacketData { .. } => TrackedValue::PacketData {
                    def_end_pc: pc + width,
                },
                value => value,
            };
        }
        (BPF_ADD | BPF_SUB, BPF_K) => {
            if let TrackedValue::PacketData { .. } = regs[dst] {
                regs[dst] = TrackedValue::PacketData {
                    def_end_pc: pc + width,
                };
            } else {
                regs[dst] = TrackedValue::Unknown;
            }
        }
        _ => regs[dst] = TrackedValue::Unknown,
    }
}

fn memory_base_reg(insn: &BpfInsn) -> Option<u8> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    match insn.class() {
        BPF_LDX => Some(insn.src_reg()),
        BPF_ST | BPF_STX => Some(insn.dst_reg()),
        _ => None,
    }
}

fn choose_prefetch_insert_pc(
    program: &BpfProgram,
    cfg: &CFGResult,
    site: PrefetchSite,
) -> Result<usize, String> {
    let target_pc = site.target_pc;
    if target_pc >= program.insns.len() || target_pc >= cfg.insn_to_block.len() {
        return Err("prefetch target pc is outside the instruction stream".into());
    }

    let (subprog_start, subprog_end) = subprog_bounds(cfg, program.insns.len(), target_pc)
        .ok_or_else(|| "prefetch target pc is outside all subprograms".to_string())?;
    let block = &cfg.blocks[cfg.insn_to_block[target_pc]];
    if block.start < subprog_start || block.end > subprog_end {
        return Err(format!(
            "prefetch basic block crosses subprog boundary (block {}..{}, subprog {}..{})",
            block.start, block.end, subprog_start, subprog_end
        ));
    }

    let valid_start = block
        .start
        .max(subprog_start)
        .max(target_pc.saturating_sub(MAX_PREFETCH_DISTANCE))
        .max(site.ptr_def_end_pc);
    if valid_start > target_pc {
        return Err("no valid prefetch insertion window".into());
    }

    reject_control_flow_between(&program.insns, valid_start, target_pc)?;
    reject_reg_write_between(&program.insns, site.ptr_reg, valid_start, target_pc)?;

    let ideal = target_pc.saturating_sub(TARGET_PREFETCH_DISTANCE);
    let Some(insert_pc) = nearest_instruction_boundary(
        &program.insns,
        block.start,
        target_pc + 1,
        valid_start,
        target_pc,
        ideal,
    ) else {
        return Err("prefetch insertion window has no instruction boundary".into());
    };
    Ok(insert_pc)
}

fn subprog_bounds(
    cfg: &crate::analysis::CFGResult,
    program_len: usize,
    pc: usize,
) -> Option<(usize, usize)> {
    let idx = cfg
        .subprogs
        .iter()
        .rposition(|subprog| subprog.start <= pc)?;
    let start = cfg.subprogs[idx].start;
    let end = cfg
        .subprogs
        .get(idx + 1)
        .map(|subprog| subprog.start)
        .unwrap_or(program_len);
    (pc < end).then_some((start, end))
}

fn reject_control_flow_between(
    insns: &[BpfInsn],
    start_pc: usize,
    end_pc: usize,
) -> Result<(), String> {
    let mut pc = start_pc;
    while pc < end_pc {
        let insn = &insns[pc];
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Err(format!(
                "prefetch window contains control-flow instruction at pc {pc}"
            ));
        }
        pc += insn_width(insn);
    }
    Ok(())
}

fn reject_reg_write_between(
    insns: &[BpfInsn],
    reg: u8,
    start_pc: usize,
    end_pc: usize,
) -> Result<(), String> {
    let mut pc = start_pc;
    while pc < end_pc {
        let insn = &insns[pc];
        if reg_write_kind(insn, reg).is_some() {
            return Err(format!(
                "r{reg} is redefined inside the prefetch window at pc {pc}"
            ));
        }
        pc += insn_width(insn);
    }
    Ok(())
}

fn nearest_instruction_boundary(
    insns: &[BpfInsn],
    scan_start: usize,
    scan_end: usize,
    valid_start: usize,
    valid_end: usize,
    ideal: usize,
) -> Option<usize> {
    let mut pc = scan_start;
    let mut best = None;

    while pc < scan_end {
        if pc >= valid_start && pc <= valid_end {
            let distance = pc.abs_diff(ideal);
            let replace = best
                .map(|(best_distance, best_pc)| {
                    distance < best_distance || (distance == best_distance && pc < best_pc)
                })
                .unwrap_or(true);
            if replace {
                best = Some((distance, pc));
            }
        }
        pc += insn_width(&insns[pc]);
    }

    best.map(|(_, pc)| pc)
}

fn reg_write_kind(insn: &BpfInsn, reg: u8) -> Option<RegWriteKind> {
    if insn.is_call() && reg <= BPF_REG_5 {
        return Some(RegWriteKind::CallClobber);
    }
    if insn.is_ldimm64() {
        return (insn.dst_reg() == reg).then_some(RegWriteKind::Explicit);
    }
    match insn.class() {
        BPF_LD | BPF_LDX | BPF_ALU | BPF_ALU64 => {
            (insn.dst_reg() == reg).then_some(RegWriteKind::Explicit)
        }
        _ => None,
    }
}

fn dedup_candidates(mut candidates: Vec<PrefetchCandidate>) -> Vec<PrefetchCandidate> {
    candidates.sort_by(|a, b| {
        b.score
            .cmp(&a.score)
            .then_with(|| a.insert_pc.cmp(&b.insert_pc))
            .then_with(|| a.target_pc.cmp(&b.target_pc))
    });

    let mut kept = Vec::new();
    for candidate in candidates {
        if kept.iter().any(|existing: &PrefetchCandidate| {
            existing.insert_pc == candidate.insert_pc && existing.ptr_reg == candidate.ptr_reg
        }) {
            continue;
        }
        kept.push(candidate);
    }
    kept.sort_by_key(|candidate| candidate.insert_pc);
    kept
}

fn group_candidates_by_insert_pc(
    candidates: &[PrefetchCandidate],
) -> BTreeMap<usize, Vec<PrefetchCandidate>> {
    let mut grouped = BTreeMap::<usize, Vec<PrefetchCandidate>>::new();
    for candidate in candidates {
        grouped
            .entry(candidate.insert_pc)
            .or_default()
            .push(candidate.clone());
    }
    grouped
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::{BranchTargetAnalysis, CFGAnalysis};
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn map_lookup_call() -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            HELPER_MAP_LOOKUP_ELEM,
        )
    }

    fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, src),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn filler(dst: u8, count: usize) -> Vec<BpfInsn> {
        (0..count)
            .map(|idx| BpfInsn::mov64_imm(dst, idx as i32))
            .collect()
    }

    fn ctx_with_prefetch_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kinsn_registry.prefetch_btf_id = btf_id;
        ctx
    }

    fn hot_prefetch_profile(execution_count: u64) -> PrefetchProfile {
        PrefetchProfile {
            execution_count,
            cache_references: execution_count * 2,
            cache_misses: execution_count,
            miss_rate: 0.5,
        }
    }

    fn cold_prefetch_profile(execution_count: u64) -> PrefetchProfile {
        PrefetchProfile {
            execution_count,
            cache_references: execution_count,
            cache_misses: 0,
            miss_rate: 0.0,
        }
    }

    fn sidecar_payload(insn: &BpfInsn) -> u64 {
        (u64::from(insn.dst_reg()) & 0xf)
            | (u64::from(insn.off as u16) << 4)
            | (u64::from(insn.imm as u32) << 20)
    }

    fn lookup_value_program() -> (BpfProgram, usize, usize) {
        let insns = vec![
            map_lookup_call(),
            jeq_imm(BPF_REG_0, 0, 1),
            BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
            exit_insn(),
        ];
        (BpfProgram::new(insns), 0, 2)
    }

    fn lookup_value_alias_program() -> (BpfProgram, usize, usize) {
        let insns = vec![
            map_lookup_call(),
            BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
            jeq_imm(BPF_REG_6, 0, 1),
            BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
            exit_insn(),
        ];
        (BpfProgram::new(insns), 0, 3)
    }

    fn packet_program_with_filler(filler_count: usize) -> (BpfProgram, usize) {
        let mut insns = vec![BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_DATA_OFF)];
        insns.extend(filler(BPF_REG_3, filler_count));
        let load_pc = insns.len();
        insns.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
        insns.push(exit_insn());
        (BpfProgram::new(insns), load_pc)
    }

    fn run_prefetch_pass(program: &mut BpfProgram, ctx: &PassContext) -> PassResult {
        let mut cache = AnalysisCache::new();
        PrefetchPass.run(program, &mut cache, ctx).unwrap()
    }

    #[test]
    fn prefetch_payload_round_trips_register_and_rejects_reserved_bits() {
        let payload = prefetch_payload(BPF_REG_2).unwrap();

        assert_eq!(decode_prefetch_payload(payload).unwrap(), BPF_REG_2);
        assert!(decode_prefetch_payload(payload | (1 << 4)).is_err());
        assert!(decode_prefetch_payload(payload | (1 << 8)).is_err());
        assert!(prefetch_payload(11).is_err());
    }

    #[test]
    fn prefetch_pass_emits_map_value_prefetch_without_profile() {
        let (mut program, _call_pc, _load_pc) = lookup_value_program();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = run_prefetch_pass(&mut program, &ctx);

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert!(program.insns[2].is_kinsn_sidecar());
        assert_eq!(
            decode_prefetch_payload(sidecar_payload(&program.insns[2])).unwrap(),
            BPF_REG_0
        );
        assert!(program.insns[3].is_call());
        assert_eq!(program.insns[3].src_reg(), BPF_PSEUDO_KINSN_CALL);
        assert_eq!(program.insns[3].imm, 7777);
        assert!(program.insns.last().unwrap().is_exit());
    }

    #[test]
    fn prefetch_pass_uses_alias_register_for_map_value_deref() {
        let (mut program, _call_pc, _load_pc) = lookup_value_alias_program();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = run_prefetch_pass(&mut program, &ctx);

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert!(program.insns[3].is_kinsn_sidecar());
        assert_eq!(
            decode_prefetch_payload(sidecar_payload(&program.insns[3])).unwrap(),
            BPF_REG_6
        );
    }

    #[test]
    fn prefetch_pass_profile_can_filter_cold_map_value_site() {
        let (mut program, _call_pc, load_pc) = lookup_value_program();
        program.annotations[load_pc].prefetch_profile = Some(cold_prefetch_profile(100));
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = run_prefetch_pass(&mut program, &ctx);

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("no observed cache misses")));
    }

    #[test]
    fn prefetch_pass_emits_packet_prefetch_without_profile() {
        let (mut program, _load_pc) = packet_program_with_filler(8);
        let mut ctx = ctx_with_prefetch_kfunc(7777);
        ctx.prog_type = BPF_PROG_TYPE_XDP;

        let result = run_prefetch_pass(&mut program, &ctx);

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert!(program.insns[1].is_kinsn_sidecar());
        assert_eq!(
            decode_prefetch_payload(sidecar_payload(&program.insns[1])).unwrap(),
            BPF_REG_6
        );
    }

    #[test]
    fn prefetch_pass_inserts_only_at_instruction_boundaries() {
        let wide = ld_imm64(BPF_REG_3, 0, 123);
        let mut insns = vec![BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_DATA_OFF)];
        insns.extend_from_slice(&wide);
        insns.extend(filler(BPF_REG_4, 8));
        insns.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
        insns.push(exit_insn());
        let mut program = BpfProgram::new(insns);
        let mut ctx = ctx_with_prefetch_kfunc(7777);
        ctx.prog_type = BPF_PROG_TYPE_XDP;

        let result = run_prefetch_pass(&mut program, &ctx);

        assert!(result.changed);
        assert!(program.insns[1].is_ldimm64());
        assert_eq!(program.insns[2].code, 0);
        assert!(program.insns[3].is_kinsn_sidecar());
    }

    #[test]
    fn prefetch_pass_integration_with_pass_manager() {
        let (mut program, call_pc, _load_pc) = lookup_value_program();
        let mut profile = ProfilingData::default();
        profile
            .prefetch_profiles
            .insert(call_pc, hot_prefetch_profile(100));
        profile.cache_miss_rate = Some(0.5);

        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(PrefetchPass);
        let ctx = ctx_with_prefetch_kfunc(1234);

        let result = pm
            .run_with_profiling(&mut program, &ctx, Some(&profile))
            .unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }
}
