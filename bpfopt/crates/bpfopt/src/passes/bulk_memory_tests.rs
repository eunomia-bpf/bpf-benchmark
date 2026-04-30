use super::*;

use std::collections::HashMap;

use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};
const MEMCPY_BTF_ID: i32 = 4101;
const MEMSET_BTF_ID: i32 = 4102;

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

fn pseudo_call_to(call_pc: usize, target_pc: usize) -> BpfInsn {
    let imm = target_pc as i64 - (call_pc as i64 + 1);
    BpfInsn::new(
        BPF_JMP | BPF_CALL,
        BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
        0,
        imm as i32,
    )
}

fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ST | size | BPF_MEM,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
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
    temp_reg: u8,
) -> u64 {
    assert!((1..=128).contains(&len));
    (dst_base as u64)
        | ((src_base as u64) << 4)
        | ((dst_off as u16 as u64) << 8)
        | ((src_off as u16 as u64) << 24)
        | (((len - 1) as u64) << 40)
        | ((temp_reg as u64) << 48)
}

// Mirrors the kernel sidecar field layout, so each encoded field stays explicit.
#[allow(clippy::too_many_arguments)]
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
    temp_reg: u8,
) -> Vec<BpfInsn> {
    emit_packed_kinsn_call_with_off(
        pack_memcpy_payload(dst_base, src_base, dst_off, src_off, len, temp_reg),
        MEMCPY_BTF_ID,
        0,
    )
}

fn memset_zero_call(dst_base: u8, dst_off: i16, len: u8, size: u8) -> Vec<BpfInsn> {
    memset_call(dst_base, dst_off, len, size, 0)
}

fn memset_call(dst_base: u8, dst_off: i16, len: u8, size: u8, fill_imm8: u8) -> Vec<BpfInsn> {
    emit_packed_kinsn_call_with_off(
        pack_memset_payload(
            dst_base,
            0,
            dst_off,
            len,
            size,
            false,
            fill_imm8 == 0,
            fill_imm8,
        ),
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

fn make_memset_nonzero_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(9);
    for lane in 0..8 {
        insns.push(st_mem(BPF_W, 10, -32 + 4 * lane as i16, 0x7f7f7f7f));
    }
    insns.push(exit_insn());
    insns
}

fn make_memset_truncated_byte_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(33);
    for lane in 0..32 {
        insns.push(st_mem(BPF_B, 10, -32 + lane as i16, 0x12345680));
    }
    insns.push(exit_insn());
    insns
}

fn make_memset_negative_dw_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(5);
    for lane in 0..4 {
        insns.push(st_mem(BPF_DW, 10, -32 + 8 * lane as i16, -1));
    }
    insns.push(exit_insn());
    insns
}

fn make_memset_non_repeated_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(9);
    for lane in 0..8 {
        insns.push(st_mem(BPF_W, 10, -32 + 4 * lane as i16, 0x11223344));
    }
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
    let mut expected = memcpy_call(10, -64, 6, 0, 64, 3);
    expected.push(exit_insn());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_memcpy_pattern_inside_multi_subprog_program() {
    let mut insns = vec![pseudo_call_to(0, 2), exit_insn()];
    insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
    insns.push(exit_insn());
    let mut program = make_program(insns);

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 1);
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
fn test_memset_nonzero_immediate_pattern() {
    let mut program = make_program(make_memset_nonzero_imm_program());
    let mut expected = memset_call(10, -32, 32, BPF_W, 0x7f);
    expected.push(exit_insn());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_memset_byte_immediate_truncates_to_imm8() {
    let mut program = make_program(make_memset_truncated_byte_imm_program());
    let mut expected = memset_call(10, -32, 32, BPF_B, 0x80);
    expected.push(exit_insn());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_memset_negative_dw_immediate_uses_ff_fill() {
    let mut program = make_program(make_memset_negative_dw_imm_program());
    let mut expected = memset_call(10, -32, 32, BPF_DW, 0xff);
    expected.push(exit_insn());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_memset_non_repeated_immediate_unchanged() {
    let original = make_memset_non_repeated_imm_program();
    let mut program = make_program(original.clone());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert_eq!(result.pass_results[0].sites_applied, 0);
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
    let mut expected = memcpy_call(10, -64, 6, 0, 32, 3);
    expected.extend(memcpy_call(8, 0, 10, -32, 32, 3));
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
    let mut expected = memcpy_call(10, -64, 6, 0, 32, 3);
    expected.extend(memcpy_call(10, -24, 6, 40, 32, 3));
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
    expected.extend(memcpy_call(10, -64, 6, 0, 64, 3));
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
fn test_memset_nonzero_reg_pattern() {
    let mut program = make_program(make_nonzero_memset_reg_program());
    let mut expected = vec![BpfInsn::mov64_imm(8, 0x5a5a5a5a)];
    expected.extend(memset_call(10, -32, 32, BPF_W, 0x5a));
    expected.push(exit_insn());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(result.program_changed);
    assert_eq!(program.insns, expected);
    assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), 1);
    assert_eq!(result.pass_results[0].sites_applied, 1);
}

#[test]
fn test_memcpy_proof_tmp_live_out_skipped() {
    let mut original = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8);
    original.push(BpfInsn::mov64_reg(8, 3));
    original.push(exit_insn());
    let mut program = make_program(original.clone());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("tmp_reg r3 is live after site")));
}
