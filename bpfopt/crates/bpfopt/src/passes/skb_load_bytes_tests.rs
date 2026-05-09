use super::skb_load_bytes::*;
use crate::insn::*;

use crate::analysis::BranchTargetAnalysis;
use crate::pass::{BpfProgram, PassContext, PassManager};
use crate::test_helpers::*;

const BPF_FUNC_SKB_LOAD_BYTES: i32 = kernel_sys::BPF_FUNC_skb_load_bytes as i32;
const BPF_FUNC_DUMMY_HELPER: i32 = kernel_sys::BPF_FUNC_map_lookup_elem as i32;

const BPF_PROG_TYPE_SOCKET_FILTER: u32 = kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER;
const BPF_PROG_TYPE_SCHED_CLS: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_ACT;

const SKB_DATA_OFF: i16 = 76;
const SKB_DATA_END_OFF: i16 = 80;

fn helper_call(helper_id: i32) -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, helper_id)
}

fn make_skb_load_bytes_setup(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_imm(2, offset),
        BpfInsn::mov64_reg(3, 10),
        BpfInsn::alu64_imm(BPF_ADD, 3, stack_off),
        BpfInsn::mov64_imm(4, len),
    ]
}

fn make_skb_load_bytes_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
    let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
    insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
    insns.push(jne_imm(0, 0, 2));
    insns.push(BpfInsn::mov64_imm(0, 1));
    insns.push(exit_insn());
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(exit_insn());
    insns
}

fn make_non_skb_helper_program() -> Vec<BpfInsn> {
    let mut insns = make_skb_load_bytes_setup(14, -8, 1);
    insns.push(helper_call(BPF_FUNC_DUMMY_HELPER));
    insns.push(jne_imm(0, 0, 2));
    insns.push(BpfInsn::mov64_imm(0, 1));
    insns.push(exit_insn());
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(exit_insn());
    insns
}

fn make_no_helper_calls_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -8),
        exit_insn(),
    ]
}

fn make_variable_offset_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_reg(2, 6),
        BpfInsn::mov64_reg(3, 10),
        BpfInsn::alu64_imm(BPF_ADD, 3, -8),
        BpfInsn::mov64_imm(4, 1),
        helper_call(BPF_FUNC_SKB_LOAD_BYTES),
        jne_imm(0, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]
}

fn make_variable_len_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_imm(2, 14),
        BpfInsn::mov64_reg(3, 10),
        BpfInsn::alu64_imm(BPF_ADD, 3, -8),
        BpfInsn::mov64_reg(4, 7),
        helper_call(BPF_FUNC_SKB_LOAD_BYTES),
        jne_imm(0, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]
}

fn make_two_call_program() -> Vec<BpfInsn> {
    let mut insns = vec![BpfInsn::mov64_reg(6, 1)];
    insns.extend(make_skb_load_bytes_setup(14, -8, 1));
    insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
    insns.push(jne_imm(0, 0, 9));
    insns.push(BpfInsn::mov64_reg(1, 6));
    insns.extend(make_skb_load_bytes_setup(18, -16, 1));
    insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
    insns.push(jne_imm(0, 0, 2));
    insns.push(BpfInsn::mov64_imm(0, 1));
    insns.push(exit_insn());
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(exit_insn());
    insns
}

fn make_prior_helper_without_ctx_reload_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_reg(6, 1),
        helper_call(BPF_FUNC_DUMMY_HELPER),
        BpfInsn::mov64_imm(2, 14),
        BpfInsn::mov64_reg(3, 10),
        BpfInsn::alu64_imm(BPF_ADD, 3, -8),
        BpfInsn::mov64_imm(4, 1),
        helper_call(BPF_FUNC_SKB_LOAD_BYTES),
        jne_imm(0, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]
}

fn make_prior_helper_with_ctx_reload_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_reg(6, 1),
        helper_call(BPF_FUNC_DUMMY_HELPER),
        BpfInsn::mov64_reg(1, 6),
        BpfInsn::mov64_imm(2, 14),
        BpfInsn::mov64_reg(3, 10),
        BpfInsn::alu64_imm(BPF_ADD, 3, -8),
        BpfInsn::mov64_imm(4, 1),
        helper_call(BPF_FUNC_SKB_LOAD_BYTES),
        jne_imm(0, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]
}

fn make_branch_around_program() -> Vec<BpfInsn> {
    let mut insns = vec![jeq_imm(0, 0, 6)];
    insns.extend(make_skb_load_bytes_program(14, -8, 1));
    insns
}

fn expected_call_replacement(offset: i32, len: i32) -> Vec<BpfInsn> {
    let mut insns = vec![
        BpfInsn::ldx_mem(BPF_W, 5, 1, SKB_DATA_OFF),
        BpfInsn::ldx_mem(BPF_W, 0, 1, SKB_DATA_END_OFF),
        BpfInsn::mov64_reg(2, 5),
        BpfInsn::alu64_imm(BPF_ADD, 2, offset + len),
        jgt_reg(2, 0, (3 + 2 * len) as i16),
        BpfInsn::alu64_imm(BPF_ADD, 5, offset),
    ];

    for i in 0..len {
        insns.push(BpfInsn::ldx_mem(BPF_B, 4, 5, i as i16));
        insns.push(BpfInsn::stx_mem(BPF_B, 3, 4, i as i16));
    }

    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(BpfInsn::ja(3));
    insns.push(BpfInsn::mov64_imm(2, offset));
    insns.push(BpfInsn::mov64_imm(4, len));
    insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
    insns
}

fn expected_rewritten_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
    let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
    insns.extend(expected_call_replacement(offset, len));
    insns.push(jne_imm(0, 0, 2));
    insns.push(BpfInsn::mov64_imm(0, 1));
    insns.push(exit_insn());
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(exit_insn());
    insns
}

fn run_skb_load_bytes_pass(
    program: &mut BpfProgram,
    prog_type: u32,
) -> crate::pass::PipelineResult {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.add_pass(SkbLoadBytesSpecPass);

    let mut ctx = PassContext::test_default();
    ctx.prog_type = prog_type;
    pm.run(program, &ctx).unwrap()
}

fn count_ctx_access(insns: &[BpfInsn], off: i16) -> usize {
    insns
        .iter()
        .filter(|insn| {
            insn.is_ldx_mem()
                && bpf_size(insn.code) == BPF_W
                && insn.src_reg() == 1
                && insn.off == off
        })
        .count()
}

#[test]
fn test_empty_program() {
    let mut program = BpfProgram::new(vec![]);

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert!(program.insns.is_empty());
    assert_eq!(result.pass_results[0].sites_applied, 0);
}

#[test]
fn test_no_helper_calls() {
    let original = make_no_helper_calls_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns, original);
    assert_eq!(result.pass_results[0].sites_applied, 0);
}

#[test]
fn test_non_skb_helper_unchanged() {
    let original = make_non_skb_helper_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns, original);
    assert_eq!(result.pass_results[0].sites_applied, 0);
}

#[test]
fn test_single_skb_load_bytes_replaced() {
    let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected_rewritten_program(14, -8, 1));
}

#[test]
fn test_constant_offset_and_len_required() {
    let variable_offset = make_variable_offset_program();
    let mut offset_program = BpfProgram::new(variable_offset.clone());
    let _offset_result = run_skb_load_bytes_pass(&mut offset_program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(offset_program.insns, variable_offset);

    let variable_len = make_variable_len_program();
    let mut len_program = BpfProgram::new(variable_len.clone());
    let _len_result = run_skb_load_bytes_pass(&mut len_program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(len_program.insns, variable_len);
}

#[test]
fn test_ctx_arg_must_be_reloaded_after_prior_helper_call() {
    let original = make_prior_helper_without_ctx_reload_program();
    let mut program = BpfProgram::new(original.clone());

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason == "arg1 is not ctx"));
}

#[test]
fn test_ctx_reload_from_callee_saved_reg_is_accepted() {
    let mut expected = make_prior_helper_with_ctx_reload_program();
    let call_pc = 7usize;
    expected.splice(call_pc..=call_pc, expected_call_replacement(14, 1));

    let mut program = BpfProgram::new(make_prior_helper_with_ctx_reload_program());

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_only_small_constant_lengths_are_specialized() {
    let original = make_skb_load_bytes_program(14, -16, 9);
    let mut program = BpfProgram::new(original.clone());

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason == "len > 8"));
}

#[test]
fn test_only_tc_programs() {
    let expected = expected_rewritten_program(14, -8, 1);

    let mut cls_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
    let cls_result = run_skb_load_bytes_pass(&mut cls_program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(cls_result.pass_results[0].sites_applied, 1);
    assert_eq!(cls_program.insns, expected);

    let mut act_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
    let act_result = run_skb_load_bytes_pass(&mut act_program, BPF_PROG_TYPE_SCHED_ACT);
    assert_eq!(act_result.pass_results[0].sites_applied, 1);
    assert_eq!(act_program.insns, expected_rewritten_program(14, -8, 1));

    let original = make_skb_load_bytes_program(14, -8, 1);
    let mut socket_filter_program = BpfProgram::new(original.clone());
    let _socket_filter_result =
        run_skb_load_bytes_pass(&mut socket_filter_program, BPF_PROG_TYPE_SOCKET_FILTER);
    assert_eq!(socket_filter_program.insns, original);
}

#[test]
fn test_supported_wide_lengths_stay_bytewise() {
    for len in [2, 4, 8] {
        let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -16, len));

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
        assert_eq!(result.pass_results[0].sites_applied, 1, "len={len}");
        assert_eq!(program.insns, expected_rewritten_program(14, -16, len));
    }
}

#[test]
fn test_error_check_preserved() {
    let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

    let _result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns[8], jgt_reg(2, 0, 5));
    assert_eq!(program.insns[17], jne_imm(0, 0, 2));
}

#[test]
fn test_multiple_calls_in_sequence() {
    let original = make_two_call_program();
    let original_len = original.len();
    let mut program = BpfProgram::new(original);

    let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_ACT);
    assert_eq!(result.pass_results[0].sites_applied, 2);
    assert_eq!(count_ctx_access(&program.insns, SKB_DATA_OFF), 2);
    assert_eq!(count_ctx_access(&program.insns, SKB_DATA_END_OFF), 2);
    assert_eq!(program.insns.len(), original_len + 24);
}

#[test]
fn test_branch_fixup_correct() {
    let mut program = BpfProgram::new(make_branch_around_program());

    let _result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);
    assert_eq!(program.insns[0], jeq_imm(0, 0, 18));
}
