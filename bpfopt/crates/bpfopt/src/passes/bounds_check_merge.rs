// SPDX-License-Identifier: MIT
//! Bounds-check merge optimization pass.

use std::collections::HashSet;

use crate::analysis::{iter_sites, BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::dce::{eliminate_nops, eliminate_unreachable_blocks};
use crate::rewrite::{
    commit_rewrite_output, compose_addr_maps, BtfRemapPolicy, RewriteOutput, RewritePlan,
};

/// BPF_PROG_TYPE_SCHED_CLS (TC classifier).
const BPF_PROG_TYPE_SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
/// BPF_PROG_TYPE_SCHED_ACT (TC action).
const BPF_PROG_TYPE_SCHED_ACT: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_ACT;
/// BPF_PROG_TYPE_XDP.
const BPF_PROG_TYPE_XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;
/// BPF_PROG_TYPE_SK_SKB.
const BPF_PROG_TYPE_SK_SKB: u32 = libbpf_sys::BPF_PROG_TYPE_SK_SKB;
/// BPF_PROG_TYPE_LWT_IN.
const BPF_PROG_TYPE_LWT_IN: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_IN;
/// BPF_PROG_TYPE_LWT_OUT.
const BPF_PROG_TYPE_LWT_OUT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_OUT;
/// BPF_PROG_TYPE_LWT_XMIT.
const BPF_PROG_TYPE_LWT_XMIT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_XMIT;

/// Phase-1 heuristic: treat larger jumps as gapped windows and fail closed.
const MAX_LADDER_WINDOW_GROWTH: i32 = 24;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
}

#[derive(Clone, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Scalar,
    PacketData { root_id: u32, const_off: i32 },
    PacketEnd { root_id: u32 },
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum GuardCmpKind {
    Strict,
    Inclusive,
}

#[derive(Clone, Debug)]
struct GuardSite {
    mov_pc: usize,
    add_pc: usize,
    compare_pc: usize,
    root_reg: u8,
    data_end_reg: u8,
    root_id: u32,
    window_end: i32,
    cmp_kind: GuardCmpKind,
    slow_target_pc: usize,
    can_widen_in_place: bool,
    can_remove_setup: bool,
}

#[derive(Clone, Debug)]
struct LadderRewrite {
    dominant_add_pc: usize,
    merged_end: i32,
    skip_pcs: Vec<usize>,
}

#[derive(Default)]
struct ScanResult {
    guards: Vec<GuardSite>,
    skips: Vec<SkipReason>,
}

/// Merge packet bounds-check ladders into a single dominant guard.
pub struct BoundsCheckMergePass;

impl BpfPass for BoundsCheckMergePass {
    fn name(&self) -> &str {
        "bounds_check_merge"
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let Some(layout) = packet_ctx_layout(ctx.prog_type) else {
            return Ok(PassResult::unchanged());
        };
        if program.insns.is_empty() {
            return Ok(PassResult::unchanged());
        }

        let bt = analyses.get::<BranchTargetAnalysis>(program);
        let liveness = analyses.get::<LivenessAnalysis>(program);

        let mut scan = scan_guard_sites(&program.insns, &bt, &liveness, layout);
        if scan.guards.is_empty() {
            return Ok(PassResult {
                sites_skipped: scan.skips,
                ..PassResult::unchanged()
            });
        }

        let mut rewrites = Vec::new();
        let mut consumed = vec![false; scan.guards.len()];
        let mut i = 0usize;
        while i < scan.guards.len() {
            if consumed[i] {
                i += 1;
                continue;
            }

            let mut group = vec![i];
            let mut j = i + 1;
            while j < scan.guards.len() {
                let prev = &scan.guards[*group.last().unwrap()];
                let next = &scan.guards[j];
                if !can_extend_ladder(prev, next, &program.insns, &bt) {
                    break;
                }
                group.push(j);
                j += 1;
            }

            if group.len() >= 2 {
                if let Some(rewrite) = build_ladder_rewrite(&group, &scan.guards, &bt) {
                    for &idx in &group {
                        consumed[idx] = true;
                    }
                    rewrites.push(rewrite);
                    i = group.last().copied().unwrap_or(i) + 1;
                    continue;
                }
            }

            i += 1;
        }

        for (idx, guard) in scan.guards.iter().enumerate() {
            if !consumed[idx] {
                scan.skips.push(SkipReason {
                    pc: guard.compare_pc,
                    reason: "guard not part of a mergeable ladder".into(),
                });
            }
        }

        if rewrites.is_empty() {
            return Ok(PassResult {
                sites_skipped: scan.skips,
                ..PassResult::unchanged()
            });
        }

        let mut plan = RewritePlan::new();
        let mut skip_pcs = HashSet::new();
        for rewrite in &rewrites {
            let mut widened = program.insns[rewrite.dominant_add_pc];
            widened.imm = rewrite.merged_end;
            plan.replace_range(
                rewrite.dominant_add_pc,
                insn_width(&program.insns[rewrite.dominant_add_pc]),
                vec![widened],
            )?;
            skip_pcs.extend(rewrite.skip_pcs.iter().copied());
        }
        for pc in skip_pcs {
            plan.delete_range(pc, insn_width(&program.insns[pc]))?;
        }

        let output = plan.build(&program.insns)?;
        let mut final_insns = output.insns;
        let mut final_addr_map = output.addr_map;

        if let Some((cleaned_insns, cleanup_map)) = eliminate_unreachable_blocks(&final_insns)? {
            final_addr_map = compose_addr_maps(&final_addr_map, &cleanup_map);
            final_insns = cleaned_insns;
        }
        while let Some((cleaned_insns, cleanup_map)) = eliminate_nops(&final_insns)? {
            final_addr_map = compose_addr_maps(&final_addr_map, &cleanup_map);
            final_insns = cleaned_insns;
        }

        let mut result = commit_rewrite_output(
            program,
            RewriteOutput {
                insns: final_insns,
                addr_map: final_addr_map,
                sites_applied: rewrites.len(),
            },
            BtfRemapPolicy::Remap,
        )?;
        result.sites_skipped = scan.skips;
        Ok(result)
    }
}

fn packet_ctx_layout(prog_type: u32) -> Option<PacketCtxLayout> {
    match prog_type {
        BPF_PROG_TYPE_XDP => Some(PacketCtxLayout {
            data_off: XDP_PACKET_DATA_OFFSET,
            data_end_off: XDP_PACKET_DATA_END_OFFSET,
        }),
        BPF_PROG_TYPE_SCHED_CLS
        | BPF_PROG_TYPE_SCHED_ACT
        | BPF_PROG_TYPE_SK_SKB
        | BPF_PROG_TYPE_LWT_IN
        | BPF_PROG_TYPE_LWT_OUT
        | BPF_PROG_TYPE_LWT_XMIT => Some(PacketCtxLayout {
            data_off: SKB_PACKET_DATA_OFFSET,
            data_end_off: SKB_PACKET_DATA_END_OFFSET,
        }),
        _ => None,
    }
}

fn scan_guard_sites(
    insns: &[BpfInsn],
    bt: &crate::analysis::BranchTargetResult,
    liveness: &crate::analysis::LivenessResult,
    layout: PacketCtxLayout,
) -> ScanResult {
    let mut states = vec![RegValue::Unknown; 11];
    let mut next_root_id = 1u32;
    let mut last_data_root = None;
    let mut result = ScanResult::default();

    for site in iter_sites(insns, |insns, pc| Some(insn_width(&insns[pc]))) {
        let pc = site.pc;
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            clear_states(&mut states);
            last_data_root = None;
        }

        if let Some(skip) = detect_variable_guard(pc, insns, &states) {
            result.skips.push(skip);
        } else if let Some(site) = detect_guard_site(pc, insns, bt, liveness, &states) {
            result.guards.push(site);
        }

        apply_transfer(
            insns[pc],
            &mut states,
            &mut next_root_id,
            &mut last_data_root,
            layout,
        );
    }

    result
}

fn detect_guard_site(
    pc: usize,
    insns: &[BpfInsn],
    bt: &crate::analysis::BranchTargetResult,
    liveness: &crate::analysis::LivenessResult,
    states: &[RegValue],
) -> Option<GuardSite> {
    let insn = insns.get(pc)?;
    let (cursor_reg, data_end_reg, cmp_kind) = normalize_slow_guard(insn)?;
    let mov_pc = pc.checked_sub(2)?;
    let add_pc = pc.checked_sub(1)?;
    let mov = insns.get(mov_pc)?;
    let add = insns.get(add_pc)?;

    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return None;
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != cursor_reg {
        return None;
    }

    let root_reg = mov.src_reg();
    let window_end = add.imm;
    if window_end <= 0 {
        return None;
    }

    let RegValue::PacketData { root_id, const_off } = reg_state(states, cursor_reg)?.clone() else {
        return None;
    };
    let RegValue::PacketData {
        root_id: root_base_id,
        const_off: root_off,
    } = reg_state(states, root_reg)?.clone()
    else {
        return None;
    };
    let RegValue::PacketEnd {
        root_id: end_root_id,
    } = reg_state(states, data_end_reg)?.clone()
    else {
        return None;
    };

    if root_id != root_base_id || root_id != end_root_id || root_off != 0 || const_off != window_end
    {
        return None;
    }

    let slow_target_pc = target_pc(pc, insn.off)?;
    if slow_target_pc >= insns.len() {
        return None;
    }

    let can_widen_in_place = !bt.is_target.get(mov_pc).copied().unwrap_or(false)
        && !bt.is_target.get(add_pc).copied().unwrap_or(false)
        && !bt.is_target.get(pc).copied().unwrap_or(false)
        && !liveness.live_out.get(pc)?.contains(&cursor_reg);
    let can_remove_setup = !bt.is_target.get(mov_pc).copied().unwrap_or(false)
        && !bt.is_target.get(add_pc).copied().unwrap_or(false)
        && !liveness.live_out.get(pc)?.contains(&cursor_reg);

    Some(GuardSite {
        mov_pc,
        add_pc,
        compare_pc: pc,
        root_reg,
        data_end_reg,
        root_id,
        window_end,
        cmp_kind,
        slow_target_pc,
        can_widen_in_place,
        can_remove_setup,
    })
}

fn detect_variable_guard(pc: usize, insns: &[BpfInsn], states: &[RegValue]) -> Option<SkipReason> {
    let insn = insns.get(pc)?;
    let (cursor_reg, data_end_reg, _) = normalize_slow_guard(insn)?;
    let mov_pc = pc.checked_sub(2)?;
    let add_pc = pc.checked_sub(1)?;
    let mov = insns.get(mov_pc)?;
    let add = insns.get(add_pc)?;

    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return None;
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_X) || add.dst_reg() != cursor_reg {
        return None;
    }

    let root_reg = mov.src_reg();
    match (
        reg_state(states, root_reg)?,
        reg_state(states, data_end_reg)?,
    ) {
        (
            RegValue::PacketData {
                root_id: left_root,
                const_off: 0,
            },
            RegValue::PacketEnd {
                root_id: right_root,
            },
        ) if left_root == right_root => Some(SkipReason {
            pc,
            reason: "variable packet window is not mergeable in v1".into(),
        }),
        _ => None,
    }
}

fn normalize_slow_guard(insn: &BpfInsn) -> Option<(u8, u8, GuardCmpKind)> {
    if insn.class() != BPF_JMP || bpf_src(insn.code) != BPF_X {
        return None;
    }

    match bpf_op(insn.code) {
        BPF_JGT => Some((insn.dst_reg(), insn.src_reg(), GuardCmpKind::Strict)),
        BPF_JLT => Some((insn.src_reg(), insn.dst_reg(), GuardCmpKind::Strict)),
        BPF_JGE => Some((insn.dst_reg(), insn.src_reg(), GuardCmpKind::Inclusive)),
        BPF_JLE => Some((insn.src_reg(), insn.dst_reg(), GuardCmpKind::Inclusive)),
        _ => None,
    }
}

fn can_extend_ladder(
    prev: &GuardSite,
    next: &GuardSite,
    insns: &[BpfInsn],
    bt: &crate::analysis::BranchTargetResult,
) -> bool {
    if prev.root_id != next.root_id
        || prev.root_reg != next.root_reg
        || prev.data_end_reg != next.data_end_reg
        || prev.cmp_kind != next.cmp_kind
        || prev.slow_target_pc != next.slow_target_pc
        || next.window_end <= prev.window_end
        || next.window_end - prev.window_end > MAX_LADDER_WINDOW_GROWTH
        || next.mov_pc <= prev.compare_pc
    {
        return false;
    }

    for pc in (prev.compare_pc + 1)..next.mov_pc {
        if !is_merge_safe_interleave(pc, insns, bt) {
            return false;
        }
    }

    !bt.is_target.get(next.compare_pc).copied().unwrap_or(false)
}

fn is_merge_safe_interleave(
    pc: usize,
    insns: &[BpfInsn],
    bt: &crate::analysis::BranchTargetResult,
) -> bool {
    if bt.is_target.get(pc).copied().unwrap_or(false) {
        return false;
    }

    let insn = &insns[pc];
    match insn.class() {
        BPF_JMP | BPF_JMP32 => false,
        BPF_ST | BPF_STX => insn.dst_reg() == 10,
        _ => true,
    }
}

fn build_ladder_rewrite(
    group: &[usize],
    guards: &[GuardSite],
    bt: &crate::analysis::BranchTargetResult,
) -> Option<LadderRewrite> {
    let dominant = guards.get(*group.first()?)?;
    if !dominant.can_widen_in_place {
        return None;
    }

    let mut merged_end = dominant.window_end;
    let mut skip_pcs = Vec::new();

    for &idx in group.iter().skip(1) {
        let site = guards.get(idx)?;
        merged_end = merged_end.max(site.window_end);
        if bt.is_target.get(site.compare_pc).copied().unwrap_or(false) {
            return None;
        }

        if site.can_remove_setup {
            skip_pcs.extend([site.mov_pc, site.add_pc, site.compare_pc]);
        } else {
            skip_pcs.push(site.compare_pc);
        }
    }

    Some(LadderRewrite {
        dominant_add_pc: dominant.add_pc,
        merged_end,
        skip_pcs,
    })
}

fn apply_transfer(
    insn: BpfInsn,
    states: &mut [RegValue],
    next_root_id: &mut u32,
    last_data_root: &mut Option<u32>,
    layout: PacketCtxLayout,
) {
    let dst = insn.dst_reg() as usize;
    let src = insn.src_reg() as usize;

    match insn.class() {
        BPF_LDX => {
            if is_ctx_data_load(&insn, layout) {
                let root_id = *next_root_id;
                *next_root_id += 1;
                states[dst] = RegValue::PacketData {
                    root_id,
                    const_off: 0,
                };
                *last_data_root = Some(root_id);
            } else if is_ctx_data_end_load(&insn, layout) {
                let root_id = last_data_root.unwrap_or_else(|| {
                    let root_id = *next_root_id;
                    *next_root_id += 1;
                    root_id
                });
                states[dst] = RegValue::PacketEnd { root_id };
            } else {
                states[dst] = RegValue::Scalar;
            }
        }
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            match (op, bpf_src(insn.code)) {
                (BPF_MOV, BPF_X) => {
                    states[dst] = states.get(src).cloned().unwrap_or(RegValue::Unknown)
                }
                (BPF_MOV, _) => states[dst] = RegValue::Scalar,
                (BPF_ADD, BPF_K) => {
                    states[dst] = match states.get(dst).cloned().unwrap_or(RegValue::Unknown) {
                        RegValue::PacketData { root_id, const_off } => RegValue::PacketData {
                            root_id,
                            const_off: const_off + insn.imm,
                        },
                        _ => RegValue::Scalar,
                    };
                }
                _ => states[dst] = RegValue::Unknown,
            }
        }
        BPF_LD => states[dst] = RegValue::Scalar,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                clear_states(states);
                *last_data_root = None;
            }
        }
        _ => {}
    }
}

fn is_ctx_data_load(insn: &BpfInsn, layout: PacketCtxLayout) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_off
}

fn is_ctx_data_end_load(insn: &BpfInsn, layout: PacketCtxLayout) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_end_off
}

fn reg_state(states: &[RegValue], reg: u8) -> Option<&RegValue> {
    states.get(reg as usize)
}

fn clear_states(states: &mut [RegValue]) {
    for state in states {
        *state = RegValue::Unknown;
    }
}

fn target_pc(pc: usize, off: i16) -> Option<usize> {
    let pc = pc as i64;
    let target = pc + 1 + off as i64;
    (target >= 0).then_some(target as usize)
}
