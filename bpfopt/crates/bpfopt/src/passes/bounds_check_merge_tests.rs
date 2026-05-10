use super::bounds_check_merge::*;
use crate::insn::*;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};

const BPF_PROG_TYPE_SOCKET_FILTER: u32 = libbpf_sys::BPF_PROG_TYPE_SOCKET_FILTER;
const BPF_PROG_TYPE_SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_ACT;
const BPF_PROG_TYPE_XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;

fn load_packet_root() -> Vec<BpfInsn> {
    load_packet_root_with_offsets(XDP_DATA_OFF, XDP_DATA_END_OFF)
}

fn load_packet_root_with_offsets(data_off: i16, data_end_off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, data_off),
        BpfInsn::ldx_mem(BPF_W, 3, 1, data_end_off),
    ]
}

fn guard(cursor_reg: u8, root_reg: u8, data_end_reg: u8, window_end: i32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_reg(cursor_reg, root_reg),
        BpfInsn::add64_imm(cursor_reg, window_end),
        BpfInsn::jgt_reg(cursor_reg, data_end_reg, 0),
    ]
}

fn compare_pcs(insns: &[BpfInsn]) -> Vec<usize> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            (matches!(
                insn.code,
                code if code == (BPF_JMP | BPF_JGT | BPF_X)
                    || code == (BPF_JMP | BPF_JGE | BPF_X)
                    || code == (BPF_JMP | BPF_JLT | BPF_X)
                    || code == (BPF_JMP | BPF_JLE | BPF_X)
            ))
            .then_some(pc)
        })
        .collect()
}

fn shared_error_program(mut body: Vec<BpfInsn>) -> Vec<BpfInsn> {
    body.push(BpfInsn::mov64_imm(0, 1));
    body.push(BpfInsn::exit());
    let error_pc = body.len();
    body.push(BpfInsn::mov64_imm(0, 0));
    body.push(BpfInsn::exit());

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

fn make_two_adjacent_tc_checks_program() -> Vec<BpfInsn> {
    let mut insns = load_packet_root_with_offsets(SKB_DATA_OFF, SKB_DATA_END_OFF);
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
    insns.push(BpfInsn::jgt_reg(4, 3, 0));
    insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
    insns.extend(guard(5, 2, 3, 34));
    insns.push(BpfInsn::ldx_mem(BPF_W, 7, 2, 30));
    shared_error_program(insns)
}

fn make_mixed_cmp_kind_program() -> Vec<BpfInsn> {
    let mut insns = load_packet_root();
    insns.extend(guard(4, 2, 3, 14));
    insns.push(BpfInsn::ldx_mem(BPF_H, 6, 2, 12));
    insns.push(BpfInsn::mov64_reg(5, 2));
    insns.push(BpfInsn::add64_imm(5, 34));
    insns.push(BpfInsn::jump_reg(BPF_JGE, 5, 3, 0));
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
    insns.push(BpfInsn::add64_imm(8, 2));
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
    insns.push(BpfInsn::exit());

    let err_a_pc = insns.len();
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(BpfInsn::exit());

    let err_b_pc = insns.len();
    insns.push(BpfInsn::mov64_imm(0, 2));
    insns.push(BpfInsn::exit());

    insns[4].off = (err_a_pc as isize - 4 - 1) as i16;
    insns[8].off = (err_b_pc as isize - 8 - 1) as i16;
    insns
}

fn make_no_bounds_check_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        BpfInsn::ldx_mem(BPF_W, 3, 1, 4),
        BpfInsn::mov64_imm(4, 42),
        BpfInsn::add64_imm(4, 8),
        BpfInsn::ldx_mem(BPF_W, 5, 2, 0),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]
}

fn run_bounds_check_merge_pass(program: &mut BpfProgram, prog_type: u32) -> PipelineResult {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.add_pass(BoundsCheckMergePass);

    let mut ctx = PassContext::baseline();
    ctx.prog_type = prog_type;
    pm.run(program, &ctx).unwrap()
}

#[test]
fn test_single_bounds_check_unchanged() {
    let original = make_single_check_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
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
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns.len(), 11);
    assert_eq!(compare_pcs(&program.insns), vec![4]);
    assert_eq!(program.insns[3], BpfInsn::add64_imm(4, 34));
}

#[test]
fn test_three_ladder_checks_merged() {
    let mut program = BpfProgram::new(make_three_ladder_checks_program());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns.len(), 12);
    assert_eq!(compare_pcs(&program.insns), vec![4]);
    assert_eq!(program.insns[3], BpfInsn::add64_imm(4, 54));
}

#[test]
fn test_non_adjacent_checks_not_merged() {
    let original = make_non_adjacent_checks_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
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
    assert_eq!(program.insns, original);
    assert_eq!(compare_pcs(&program.insns), vec![5, 9]);
    assert!(
        !result.pass_results[0].sites_skipped.is_empty(),
        "variable-offset guards should be recognized and skipped",
    );
}

#[test]
fn test_mixed_cmp_kinds_not_merged() {
    let original = make_mixed_cmp_kind_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(program.insns, original);
    assert_eq!(compare_pcs(&program.insns), vec![4, 8]);
    assert!(
        !result.pass_results[0].sites_skipped.is_empty(),
        "mixed strict/inclusive guards must not be merged",
    );
}

#[test]
fn test_different_base_regs_not_merged() {
    let original = make_different_base_regs_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
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
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns.len(), 13);
    assert_eq!(compare_pcs(&program.insns), vec![4]);
    assert_eq!(program.insns[3], BpfInsn::add64_imm(4, 34));
}

#[test]
fn test_different_error_targets_not_merged() {
    let original = make_different_error_targets_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(program.insns, original);
    assert_eq!(compare_pcs(&program.insns), vec![4, 8]);
    assert!(
        !result.pass_results[0].sites_skipped.is_empty(),
        "guards with different slow sinks should be rejected",
    );
}

#[test]
fn test_packet_program_ctx_layouts() {
    let mut xdp_program = BpfProgram::new(make_two_adjacent_checks_program());
    let _xdp_result = run_bounds_check_merge_pass(&mut xdp_program, BPF_PROG_TYPE_XDP);
    assert_eq!(xdp_program.insns.len(), 11);

    let mut tc_program = BpfProgram::new(make_two_adjacent_tc_checks_program());
    let _tc_result = run_bounds_check_merge_pass(&mut tc_program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(tc_program.insns.len(), 11);

    let mut tc_action_program = BpfProgram::new(make_two_adjacent_tc_checks_program());
    let _tc_action_result =
        run_bounds_check_merge_pass(&mut tc_action_program, BPF_PROG_TYPE_SCHED_ACT);
    assert_eq!(tc_action_program.insns.len(), 11);

    let xdp_layout_in_tc = make_two_adjacent_checks_program();
    let mut xdp_layout_tc_program = BpfProgram::new(xdp_layout_in_tc.clone());
    let _xdp_layout_tc_result =
        run_bounds_check_merge_pass(&mut xdp_layout_tc_program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(xdp_layout_tc_program.insns, xdp_layout_in_tc);

    let original = make_two_adjacent_checks_program();
    let mut non_packet_program = BpfProgram::new(original.clone());
    let _non_packet_result =
        run_bounds_check_merge_pass(&mut non_packet_program, BPF_PROG_TYPE_SOCKET_FILTER);
    assert_eq!(non_packet_program.insns, original);
}

#[test]
fn test_empty_program() {
    let mut program = BpfProgram::new(vec![]);

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert!(program.insns.is_empty());
    assert_eq!(result.pass_results[0].sites_applied, 0);
}

#[test]
fn test_no_bounds_checks() {
    let original = make_no_bounds_check_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(program.insns, original);
    assert!(compare_pcs(&program.insns).is_empty());
    assert_eq!(result.pass_results[0].sites_applied, 0);
}

#[test]
fn test_merge_preserves_largest_check() {
    let mut program = BpfProgram::new(make_three_ladder_checks_program());

    let _result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(program.insns[3], BpfInsn::add64_imm(4, 54));
    assert_eq!(program.insns[4].code, BPF_JMP | BPF_JGT | BPF_X);
    assert_eq!(compare_pcs(&program.insns), vec![4]);
}

#[test]
fn test_branch_fixup_after_merge() {
    let mut program = BpfProgram::new(make_two_adjacent_checks_program());

    let _result = run_bounds_check_merge_pass(&mut program, BPF_PROG_TYPE_XDP);
    assert_eq!(program.insns.len(), 11);
    assert_eq!(compare_pcs(&program.insns), vec![4]);
    assert_eq!(program.insns[4].off, 4);
}
