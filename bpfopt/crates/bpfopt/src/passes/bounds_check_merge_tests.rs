// SPDX-License-Identifier: MIT

use super::bounds_check_merge::BoundsCheckMergePass;
use crate::insn::*;
use crate::pass::BtfInfoRecords;
use crate::test_helpers::*;

const XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;
const SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
const SOCKET_FILTER: u32 = libbpf_sys::BPF_PROG_TYPE_SOCKET_FILTER;

fn load_packet_root(data_off: i16, end_off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_1, data_off),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_3, BPF_REG_1, end_off),
    ]
}

fn guard(cursor: u8, root: u8, data_end: u8, window_end: i32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_reg(cursor, root),
        BpfInsn::add64_imm(cursor, window_end),
        BpfInsn::jump_reg(BPF_JGT, cursor, data_end, 0),
    ]
}

fn shared_error_program(mut body: Vec<BpfInsn>) -> Vec<BpfInsn> {
    body.push(BpfInsn::mov64_imm(BPF_REG_0, 1));
    body.push(BpfInsn::exit());
    let error_target = body.len();
    body.push(BpfInsn::mov64_imm(BPF_REG_0, 0));
    body.push(BpfInsn::exit());
    for compare_idx in compare_pcs(&body) {
        if body[compare_idx].off == 0 {
            body[compare_idx].off = (error_target as isize - compare_idx as isize - 1) as i16;
        }
    }
    body
}

fn two_adjacent_checks(data_off: i16, end_off: i16) -> Vec<BpfInsn> {
    let mut insns = load_packet_root(data_off, end_off);
    insns.extend(guard(BPF_REG_4, BPF_REG_2, BPF_REG_3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.extend(guard(BPF_REG_5, BPF_REG_2, BPF_REG_3, 34));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_2, 30));
    shared_error_program(insns)
}

fn compare_pcs(insns: &[BpfInsn]) -> Vec<usize> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            matches!(
                insn.code,
                code if code == (BPF_JMP | BPF_JGT | BPF_X)
                    || code == (BPF_JMP | BPF_JGE | BPF_X)
                    || code == (BPF_JMP | BPF_JLT | BPF_X)
                    || code == (BPF_JMP | BPF_JLE | BPF_X)
            )
            .then_some(pc)
        })
        .collect()
}

fn run_bounds(input: Vec<BpfInsn>, prog_type: u32) -> PassRun {
    let mut ctx = pass_ctx();
    ctx.prog_type = prog_type;
    run_pass_on_insns(BoundsCheckMergePass, input, &ctx)
}

fn btf_records(offsets: &[u32]) -> BtfInfoRecords {
    let mut bytes = Vec::new();
    for (idx, offset) in offsets.iter().enumerate() {
        bytes.extend_from_slice(&offset.to_le_bytes());
        bytes.extend_from_slice(&(idx as u32).to_le_bytes());
    }
    BtfInfoRecords { rec_size: 8, bytes }
}

#[test]
fn bounds_check_merge_merges_adjacent_xdp_guards() {
    let run = run_bounds(
        two_adjacent_checks(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET),
        XDP,
    );

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(run.lowered.len(), 11);
    assert_eq!(compare_pcs(&run.lowered), vec![4]);
    assert_eq!(run.lowered[3], BpfInsn::add64_imm(BPF_REG_4, 34));
}

#[test]
fn bounds_check_merge_fixes_branch_offsets_after_deletion() {
    // P1-H: branch fixup must be exercised through the real pass path.
    let run = run_bounds(
        two_adjacent_checks(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET),
        XDP,
    );

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(compare_pcs(&run.lowered), vec![4]);
    assert_eq!(run.lowered[4].off, 4);
}

#[test]
fn bounds_check_merge_keeps_non_adjacent_windows_separate() {
    let mut insns = load_packet_root(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    insns.extend(guard(BPF_REG_4, BPF_REG_2, BPF_REG_3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.extend(guard(BPF_REG_5, BPF_REG_2, BPF_REG_3, 40));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_2, 36));
    let input = shared_error_program(insns);

    let run = run_bounds(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
    assert_eq!(compare_pcs(&run.lowered), vec![4, 8]);
}

#[test]
fn bounds_check_merge_rejects_variable_offset_guard() {
    let mut insns = load_packet_root(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    insns.push(BpfInsn::mov64_imm(BPF_REG_8, 20));
    insns.push(BpfInsn::mov64_reg(BPF_REG_4, BPF_REG_2));
    insns.push(BpfInsn::alu64_reg(BPF_ADD, BPF_REG_4, BPF_REG_8));
    insns.push(BpfInsn::jump_reg(BPF_JGT, BPF_REG_4, BPF_REG_3, 0));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.extend(guard(BPF_REG_5, BPF_REG_2, BPF_REG_3, 34));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_2, 30));
    let input = shared_error_program(insns);

    let run = run_bounds(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn bounds_check_merge_rejects_mixed_compare_kinds() {
    let mut insns = load_packet_root(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    insns.extend(guard(BPF_REG_4, BPF_REG_2, BPF_REG_3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.push(BpfInsn::mov64_reg(BPF_REG_5, BPF_REG_2));
    insns.push(BpfInsn::add64_imm(BPF_REG_5, 34));
    insns.push(BpfInsn::jump_reg(BPF_JGE, BPF_REG_5, BPF_REG_3, 0));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_2, 30));
    let input = shared_error_program(insns);

    let run = run_bounds(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn test_different_base_regs_not_merged() {
    // Restored from HEAD: guards rooted at different packet pointers must not
    // be merged into one dominant check.
    let mut insns = load_packet_root(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    insns.extend(guard(BPF_REG_4, BPF_REG_2, BPF_REG_3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_8, BPF_REG_1, 0));
    insns.extend(guard(BPF_REG_5, BPF_REG_8, BPF_REG_3, 34));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_8, 30));
    let input = shared_error_program(insns);

    let run = run_bounds(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
    assert_eq!(compare_pcs(&run.lowered), vec![4, 9]);
    assert!(
        !run.result.sites_skipped.is_empty(),
        "different packet roots should block merging"
    );
}

#[test]
fn test_different_error_targets_not_merged() {
    // Restored from HEAD: merging guards with different slow-path targets would
    // change failure semantics.
    let mut insns = load_packet_root(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    insns.extend(guard(BPF_REG_4, BPF_REG_2, BPF_REG_3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, BPF_REG_6, BPF_REG_2, 12));
    insns.extend(guard(BPF_REG_5, BPF_REG_2, BPF_REG_3, 34));
    insns.push(BpfInsn::ldx_mem(BPF_W, BPF_REG_7, BPF_REG_2, 30));
    insns.push(BpfInsn::mov64_imm(BPF_REG_0, 1));
    insns.push(BpfInsn::exit());

    let err_a_target = insns.len();
    insns.push(BpfInsn::mov64_imm(BPF_REG_0, 0));
    insns.push(BpfInsn::exit());

    let err_b_target = insns.len();
    insns.push(BpfInsn::mov64_imm(BPF_REG_0, 2));
    insns.push(BpfInsn::exit());

    insns[4].off = (err_a_target as isize - 4 - 1) as i16;
    insns[8].off = (err_b_target as isize - 8 - 1) as i16;
    let input = insns;

    let run = run_bounds(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
    assert_eq!(compare_pcs(&run.lowered), vec![4, 8]);
    assert!(
        !run.result.sites_skipped.is_empty(),
        "guards with different slow sinks should be rejected"
    );
}

#[test]
fn bounds_check_merge_accepts_tc_layout_and_rejects_wrong_prog_type() {
    let tc = run_bounds(
        two_adjacent_checks(SKB_PACKET_DATA_OFFSET, SKB_PACKET_DATA_END_OFFSET),
        SCHED_CLS,
    );
    assert_eq!(tc.result.sites_applied, 1);

    let input = two_adjacent_checks(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    let non_packet = run_bounds(input.clone(), SOCKET_FILTER);
    assert_eq!(non_packet.result.sites_applied, 0);
    assert_eq!(non_packet.lowered, input);
}

#[test]
fn bounds_check_merge_remaps_btf_metadata_on_bbprogram() {
    // P1-H: BTF metadata must be remapped by the ProgramCFG mutation/lower path.
    let input = two_adjacent_checks(XDP_PACKET_DATA_OFFSET, XDP_PACKET_DATA_END_OFFSET);
    let mut ctx = pass_ctx();
    ctx.prog_type = XDP;
    ctx.func_info = Some(btf_records(&[0, 12]));
    ctx.line_info = Some(btf_records(&[5, 9, 12]));

    let run = run_pass_on_insns(BoundsCheckMergePass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    // IMPL: needs ProgramCFG::btf_records() or equivalent lowered metadata view.
    assert_eq!(run.prog.btf_records().unwrap().func_offsets(), vec![0, 9]);
    assert_eq!(
        run.prog.btf_records().unwrap().line_offsets(),
        vec![5, 6, 9]
    );
}
