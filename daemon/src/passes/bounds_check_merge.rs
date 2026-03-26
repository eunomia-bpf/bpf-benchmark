// SPDX-License-Identifier: MIT
//! Bounds-check merge optimization pass.

use std::collections::{BTreeMap, HashSet};

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    compose_addr_maps, eliminate_nops, eliminate_unreachable_blocks, fixup_all_branches,
};

const BPF_ADD: u8 = 0x00;

/// BPF_PROG_TYPE_SCHED_CLS (TC classifier).
const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
/// BPF_PROG_TYPE_SCHED_ACT (TC action).
const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;
/// BPF_PROG_TYPE_XDP.
const BPF_PROG_TYPE_XDP: u32 = 6;
/// BPF_PROG_TYPE_SK_SKB.
const BPF_PROG_TYPE_SK_SKB: u32 = 14;
/// BPF_PROG_TYPE_LWT_IN.
const BPF_PROG_TYPE_LWT_IN: u32 = 18;
/// BPF_PROG_TYPE_LWT_OUT.
const BPF_PROG_TYPE_LWT_OUT: u32 = 19;
/// BPF_PROG_TYPE_LWT_XMIT.
const BPF_PROG_TYPE_LWT_XMIT: u32 = 20;

/// Phase-1 heuristic: treat larger jumps as gapped windows and fail closed.
const MAX_LADDER_WINDOW_GROWTH: i32 = 24;

#[derive(Clone, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Scalar,
    PacketData { root_id: u32, const_off: i32 },
    PacketEnd { root_id: u32 },
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

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if program.insns.is_empty() || !is_packet_prog_type(ctx.prog_type) {
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

        let mut scan = scan_guard_sites(&program.insns, &bt, &liveness);
        if scan.guards.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: scan.skips,
                diagnostics: vec![],
                ..Default::default()
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
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: scan.skips,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let mut replacements = BTreeMap::new();
        let mut skip_pcs = HashSet::new();
        for rewrite in &rewrites {
            let mut widened = program.insns[rewrite.dominant_add_pc];
            widened.imm = rewrite.merged_end;
            replacements.insert(rewrite.dominant_add_pc, vec![widened]);
            skip_pcs.extend(rewrite.skip_pcs.iter().copied());
        }

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            addr_map[pc] = new_insns.len();

            if let Some(replacement) = replacements.get(&pc) {
                new_insns.extend_from_slice(replacement);
                let width = insn_width(&program.insns[pc]);
                for j in 1..width {
                    addr_map[pc + j] = new_insns.len();
                }
                pc += width;
                continue;
            }

            if skip_pcs.contains(&pc) {
                let width = insn_width(&program.insns[pc]);
                for j in 0..width {
                    addr_map[pc + j] = new_insns.len();
                }
                pc += width;
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

        let mut final_insns = new_insns;
        let mut final_addr_map = addr_map;
        if let Some((cleaned_insns, cleanup_map)) = eliminate_unreachable_blocks(&final_insns) {
            final_addr_map = compose_addr_maps(&final_addr_map, &cleanup_map);
            final_insns = cleaned_insns;
        }
        while let Some((cleaned_insns, cleanup_map)) = eliminate_nops(&final_insns) {
            final_addr_map = compose_addr_maps(&final_addr_map, &cleanup_map);
            final_insns = cleaned_insns;
        }

        program.insns = final_insns;
        program.remap_annotations(&final_addr_map);
        program.log_transform(TransformEntry {
            sites_applied: rewrites.len(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: rewrites.len(),
            sites_skipped: scan.skips,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn is_packet_prog_type(prog_type: u32) -> bool {
    matches!(
        prog_type,
        BPF_PROG_TYPE_SCHED_CLS
            | BPF_PROG_TYPE_SCHED_ACT
            | BPF_PROG_TYPE_XDP
            | BPF_PROG_TYPE_SK_SKB
            | BPF_PROG_TYPE_LWT_IN
            | BPF_PROG_TYPE_LWT_OUT
            | BPF_PROG_TYPE_LWT_XMIT
    )
}

fn scan_guard_sites(
    insns: &[BpfInsn],
    bt: &crate::analysis::BranchTargetResult,
    liveness: &crate::analysis::LivenessResult,
) -> ScanResult {
    let mut states = vec![RegValue::Unknown; 11];
    let mut next_root_id = 1u32;
    let mut last_data_root = None;
    let mut result = ScanResult::default();
    let mut pc = 0usize;

    while pc < insns.len() {
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
        );
        pc += insn_width(&insns[pc]);
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
    let (cursor_reg, data_end_reg) = normalize_slow_guard(insn)?;
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
        slow_target_pc,
        can_widen_in_place,
        can_remove_setup,
    })
}

fn detect_variable_guard(pc: usize, insns: &[BpfInsn], states: &[RegValue]) -> Option<SkipReason> {
    let insn = insns.get(pc)?;
    let (cursor_reg, data_end_reg) = normalize_slow_guard(insn)?;
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

fn normalize_slow_guard(insn: &BpfInsn) -> Option<(u8, u8)> {
    if insn.class() != BPF_JMP || bpf_src(insn.code) != BPF_X {
        return None;
    }

    match bpf_op(insn.code) {
        BPF_JGT | BPF_JGE => Some((insn.dst_reg(), insn.src_reg())),
        BPF_JLT | BPF_JLE => Some((insn.src_reg(), insn.dst_reg())),
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
) {
    let dst = insn.dst_reg() as usize;
    let src = insn.src_reg() as usize;

    match insn.class() {
        BPF_LDX => {
            if is_ctx_data_load(&insn) {
                let root_id = *next_root_id;
                *next_root_id += 1;
                states[dst] = RegValue::PacketData {
                    root_id,
                    const_off: 0,
                };
                *last_data_root = Some(root_id);
            } else if is_ctx_data_end_load(&insn) {
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

fn is_ctx_data_load(insn: &BpfInsn) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == 0
}

fn is_ctx_data_end_load(insn: &BpfInsn) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == 4
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

    use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
    use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};

    const BPF_ADD: u8 = 0x00;

    const BPF_PROG_TYPE_SOCKET_FILTER: u32 = 1;
    const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
    const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;
    const BPF_PROG_TYPE_XDP: u32 = 6;

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JGT | BPF_X,
            regs: BpfInsn::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    fn load_packet_root() -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 3, 1, 4),
        ]
    }

    fn guard(cursor_reg: u8, root_reg: u8, data_end_reg: u8, window_end: i32) -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(cursor_reg, root_reg),
            BpfInsn::alu64_imm(BPF_ADD, cursor_reg, window_end),
            jgt_reg(cursor_reg, data_end_reg, 0),
        ]
    }

    fn compare_pcs(insns: &[BpfInsn]) -> Vec<usize> {
        insns
            .iter()
            .enumerate()
            .filter_map(|(pc, insn)| (insn.code == (BPF_JMP | BPF_JGT | BPF_X)).then_some(pc))
            .collect()
    }

    fn shared_error_program(mut body: Vec<BpfInsn>) -> Vec<BpfInsn> {
        body.push(BpfInsn::mov64_imm(0, 1));
        body.push(exit_insn());
        let error_pc = body.len();
        body.push(BpfInsn::mov64_imm(0, 0));
        body.push(exit_insn());

        for pc in compare_pcs(&body) {
            if body[pc].off == 0 {
                body[pc].off = (error_pc as isize - pc as isize - 1) as i16;
            }
        }

        body
    }

    fn make_single_check_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        shared_error_program(insns)
    }

    fn make_two_adjacent_checks_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.extend(guard(5, 2, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
        shared_error_program(insns)
    }

    fn make_three_ladder_checks_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.extend(guard(5, 2, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
        insns.extend(guard(6, 2, 3, 54));
        insns.push(BpfInsn::ldx_mem(BPF_W, 8, 2, 50));
        shared_error_program(insns)
    }

    fn make_non_adjacent_checks_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.extend(guard(5, 2, 3, 40));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 36));
        shared_error_program(insns)
    }

    fn make_variable_offset_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.push(BpfInsn::mov64_imm(8, 20));
        insns.push(BpfInsn::mov64_reg(4, 2));
        insns.push(BpfInsn::alu64_reg(BPF_ADD, 4, 8));
        insns.push(jgt_reg(4, 3, 0));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.extend(guard(5, 2, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
        shared_error_program(insns)
    }

    fn make_different_base_regs_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.push(BpfInsn::ldx_mem(BPF_W, 8, 1, 0));
        insns.extend(guard(5, 8, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 8, 30));
        shared_error_program(insns)
    }

    fn make_interleaved_checks_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.push(BpfInsn::mov64_imm(8, 1));
        insns.push(BpfInsn::alu64_imm(BPF_ADD, 8, 2));
        insns.extend(guard(5, 2, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
        shared_error_program(insns)
    }

    fn make_different_error_targets_program() -> Vec<BpfInsn> {
        let mut insns = load_packet_root();
        insns.extend(guard(4, 2, 3, 14));
        insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
        insns.extend(guard(5, 2, 3, 34));
        insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());

        let err_a_pc = insns.len();
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());

        let err_b_pc = insns.len();
        insns.push(BpfInsn::mov64_imm(0, 2));
        insns.push(exit_insn());

        insns[4].off = (err_a_pc as isize - 4 - 1) as i16;
        insns[8].off = (err_b_pc as isize - 8 - 1) as i16;
        insns
    }

    fn make_no_bounds_check_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 3, 1, 4),
            BpfInsn::mov64_imm(4, 42),
            BpfInsn::alu64_imm(BPF_ADD, 4, 8),
            BpfInsn::ldx_mem(BPF_W, 5, 2, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn run_bounds_check_merge_pass(program: &mut BpfProgram, prog_type: u32) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(CFGAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(BoundsCheckMergePass);

        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        pm.run(program, &ctx).unwrap()
    }

    #[test]
    fn test_single_bounds_check_unchanged() {
        let original = make_single_check_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(
            !result.pass_results[0].sites_skipped.is_empty(),
            "single recognized guard should be reported as non-mergeable",
        );
    }

    #[test]
    fn test_two_adjacent_checks_merged() {
        let mut program = BpfProgram::new(make_two_adjacent_checks_program());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns.len(), 11);
        assert_eq!(compare_pcs(&program.insns), vec![4]);
        assert_eq!(program.insns[3], BpfInsn::alu64_imm(BPF_ADD, 4, 34));
    }

    #[test]
    fn test_three_ladder_checks_merged() {
        let mut program = BpfProgram::new(make_three_ladder_checks_program());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns.len(), 12);
        assert_eq!(compare_pcs(&program.insns), vec![4]);
        assert_eq!(program.insns[3], BpfInsn::alu64_imm(BPF_ADD, 4, 54));
    }

    #[test]
    fn test_non_adjacent_checks_not_merged() {
        let original = make_non_adjacent_checks_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(compare_pcs(&program.insns), vec![4, 8]);
        assert!(
            !result.pass_results[0].sites_skipped.is_empty(),
            "gapped windows should be recognized and rejected",
        );
    }

    #[test]
    fn test_variable_offset_skipped() {
        let original = make_variable_offset_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(compare_pcs(&program.insns), vec![5, 9]);
        assert!(
            !result.pass_results[0].sites_skipped.is_empty(),
            "variable-offset guards should be recognized and skipped",
        );
    }

    #[test]
    fn test_different_base_regs_not_merged() {
        let original = make_different_base_regs_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(compare_pcs(&program.insns), vec![4, 9]);
        assert!(
            !result.pass_results[0].sites_skipped.is_empty(),
            "different packet roots should block merging",
        );
    }

    #[test]
    fn test_interleaved_instructions_handled() {
        let mut program = BpfProgram::new(make_interleaved_checks_program());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns.len(), 13);
        assert_eq!(compare_pcs(&program.insns), vec![4]);
        assert_eq!(program.insns[3], BpfInsn::alu64_imm(BPF_ADD, 4, 34));
    }

    #[test]
    fn test_different_error_targets_not_merged() {
        let original = make_different_error_targets_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(compare_pcs(&program.insns), vec![4, 8]);
        assert!(
            !result.pass_results[0].sites_skipped.is_empty(),
            "guards with different slow sinks should be rejected",
        );
    }

    #[test]
    fn test_xdp_program_only() {
        let mut xdp_program = BpfProgram::new(make_two_adjacent_checks_program());
        let xdp_result = run_bounds_check_merge_pass(&mut xdp_program, BPF_PROG_TYPE_XDP);
        assert!(xdp_result.program_changed);
        assert_eq!(xdp_program.insns.len(), 11);

        let mut tc_program = BpfProgram::new(make_two_adjacent_checks_program());
        let tc_result = run_bounds_check_merge_pass(&mut tc_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(tc_result.program_changed);
        assert_eq!(tc_program.insns.len(), 11);

        let mut tc_action_program = BpfProgram::new(make_two_adjacent_checks_program());
        let tc_action_result =
            run_bounds_check_merge_pass(&mut tc_action_program, BPF_PROG_TYPE_SCHED_ACT);
        assert!(tc_action_result.program_changed);
        assert_eq!(tc_action_program.insns.len(), 11);

        let original = make_two_adjacent_checks_program();
        let mut non_packet_program = BpfProgram::new(original.clone());
        let non_packet_result =
            run_bounds_check_merge_pass(&mut non_packet_program, BPF_PROG_TYPE_SOCKET_FILTER);
        assert!(!non_packet_result.program_changed);
        assert_eq!(non_packet_program.insns, original);
    }

    #[test]
    fn test_empty_program() {
        let mut program = BpfProgram::new(vec![]);

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_bounds_checks() {
        let original = make_no_bounds_check_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(compare_pcs(&program.insns).is_empty());
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_merge_preserves_largest_check() {
        let mut program = BpfProgram::new(make_three_ladder_checks_program());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(program.insns[3], BpfInsn::alu64_imm(BPF_ADD, 4, 54));
        assert_eq!(program.insns[4].code, BPF_JMP | BPF_JGT | BPF_X);
        assert_eq!(compare_pcs(&program.insns), vec![4]);
    }

    #[test]
    fn test_branch_fixup_after_merge() {
        let mut program = BpfProgram::new(make_two_adjacent_checks_program());

        let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(program.insns.len(), 11);
        assert_eq!(compare_pcs(&program.insns), vec![4]);
        assert_eq!(program.insns[4].off, 4);
    }
}
