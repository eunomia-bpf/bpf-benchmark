use super::bulk_memory::*;
use crate::analysis::*;
use crate::insn::*;

use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};
use crate::test_helpers::*;
const MEMCPY_BTF_ID: i32 = 4101;
const MEMSET_BTF_ID: i32 = 4102;

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
        insns.push(BpfInsn::st_mem(
            size,
            dst_base,
            dst_off + stride * lane as i16,
            0,
        ));
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
    insns.push(BpfInsn::exit());
    insns
}

fn make_memset_zero_program() -> Vec<BpfInsn> {
    let mut insns = make_st_mem_zero_run(BPF_DW, 10, -64, 8);
    insns.push(BpfInsn::exit());
    insns
}

fn make_memset_nonzero_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(9);
    for lane in 0..8 {
        insns.push(BpfInsn::st_mem(
            BPF_W,
            10,
            -32 + 4 * lane as i16,
            0x7f7f7f7f,
        ));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn make_memset_truncated_byte_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(33);
    for lane in 0..32 {
        insns.push(BpfInsn::st_mem(BPF_B, 10, -32 + lane as i16, 0x12345680));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn make_memset_negative_dw_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(5);
    for lane in 0..4 {
        insns.push(BpfInsn::st_mem(BPF_DW, 10, -32 + 8 * lane as i16, -1));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn make_memset_non_repeated_imm_program() -> Vec<BpfInsn> {
    let mut insns = Vec::with_capacity(9);
    for lane in 0..8 {
        insns.push(BpfInsn::st_mem(
            BPF_W,
            10,
            -32 + 4 * lane as i16,
            0x11223344,
        ));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn make_no_consecutive_stores_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::st_mem(BPF_DW, 10, -64, 0),
        BpfInsn::mov64_imm(8, 1),
        BpfInsn::st_mem(BPF_DW, 10, -40, 0),
        BpfInsn::st_mem(BPF_DW, 10, -8, 0),
        BpfInsn::exit(),
    ]
}

fn make_below_threshold_program() -> Vec<BpfInsn> {
    let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -24, 3);
    insns.push(BpfInsn::exit());
    insns
}

fn make_different_base_regs_program() -> Vec<BpfInsn> {
    let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 4);
    insns.extend(make_memcpy_run(BPF_DW, 3, 10, -32, 8, 0, 4));
    insns.push(BpfInsn::exit());
    insns
}

fn make_non_consecutive_offsets_program() -> Vec<BpfInsn> {
    let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 4);
    insns.extend(make_memcpy_run(BPF_DW, 3, 6, 40, 10, -24, 4));
    insns.push(BpfInsn::exit());
    insns
}

fn make_mixed_widths_program() -> Vec<BpfInsn> {
    let mut insns = make_st_mem_zero_run(BPF_W, 10, -32, 4);
    insns.extend(make_st_mem_zero_run(BPF_DW, 10, -16, 2));
    insns.push(BpfInsn::exit());
    insns
}

fn make_memcpy_preserves_surrounding_program() -> Vec<BpfInsn> {
    let mut insns = vec![BpfInsn::mov64_imm(8, 7)];
    insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
    insns.push(BpfInsn::mov64_reg(0, 8));
    insns.push(BpfInsn::exit());
    insns
}

fn make_branch_fixup_program() -> Vec<BpfInsn> {
    let mut insns = vec![BpfInsn::jeq_imm(0, 0, 17)];
    insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
    insns.push(BpfInsn::mov64_imm(0, 1));
    insns.push(BpfInsn::exit());
    insns
}

fn make_interleaved_non_store_program() -> Vec<BpfInsn> {
    let mut insns = make_st_mem_zero_run(BPF_DW, 10, -64, 4);
    insns.push(BpfInsn::mov64_imm(9, 1));
    insns.extend(make_st_mem_zero_run(BPF_DW, 10, -32, 4));
    insns.push(BpfInsn::exit());
    insns
}

fn make_same_base_chunked_overlap_program() -> Vec<BpfInsn> {
    let mut insns = make_memcpy_run(BPF_DW, 3, 10, -200, 10, -70, 19);
    insns.push(BpfInsn::exit());
    insns
}

fn make_nonzero_memset_reg_program() -> Vec<BpfInsn> {
    let mut insns = vec![BpfInsn::mov64_imm(8, 0x5a5a5a5a)];
    insns.extend(make_stx_mem_run(BPF_W, 8, 10, -32, 8));
    insns.push(BpfInsn::exit());
    insns
}

fn make_non_stack_base_memcpy_program() -> Vec<BpfInsn> {
    let mut insns = make_memcpy_run(BPF_DW, 3, 6, 0, 8, 0, 4);
    insns.push(BpfInsn::exit());
    insns
}

fn ctx_with_bulk_kfuncs() -> PassContext {
    let mut ctx = PassContext::baseline();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_bulk_memcpy", MEMCPY_BTF_ID, 0)
        .unwrap();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_bulk_memset", MEMSET_BTF_ID, 0)
        .unwrap();
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
fn test_memcpy_pattern_8_pairs() {
    for (label, mut program, expected) in {
        let mut plain_expected = memcpy_call(10, -64, 6, 0, 64, 3);
        plain_expected.push(BpfInsn::exit());
        let mut surrounding_expected = vec![BpfInsn::mov64_imm(8, 7)];
        surrounding_expected.extend(memcpy_call(10, -64, 6, 0, 64, 3));
        surrounding_expected.push(BpfInsn::mov64_reg(0, 8));
        surrounding_expected.push(BpfInsn::exit());
        [
            (
                "canonical",
                make_program(make_memcpy_program_8_pairs()),
                plain_expected,
            ),
            (
                "surrounding",
                make_program(make_memcpy_preserves_surrounding_program()),
                surrounding_expected,
            ),
        ]
    } {
        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
        assert_eq!(result.pass_results[0].sites_applied, 1, "{label}");
        assert_eq!(program.insns, expected, "{label}");
    }
}

#[test]
fn test_memcpy_pattern_inside_multi_subprog_program() {
    let mut insns = vec![BpfInsn::pseudo_call_to(0, 2), BpfInsn::exit()];
    insns.extend(make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8));
    insns.push(BpfInsn::exit());
    let mut program = make_program(insns);

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 1);
}

#[test]
fn test_memset_zero_pattern() {
    let mut program = make_program(make_memset_zero_program());
    let mut expected = memset_zero_call(10, -64, 64, BPF_DW);
    expected.push(BpfInsn::exit());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, expected);
}

#[test]
fn test_memset_fill_encoding_matrix() {
    for (label, mut program, expected) in {
        let mut nonzero_imm = memset_call(10, -32, 32, BPF_W, 0x7f);
        nonzero_imm.push(BpfInsn::exit());
        let mut truncated_byte = memset_call(10, -32, 32, BPF_B, 0x80);
        truncated_byte.push(BpfInsn::exit());
        let mut negative_dw = memset_call(10, -32, 32, BPF_DW, 0xff);
        negative_dw.push(BpfInsn::exit());
        let mut reg_fill = vec![BpfInsn::mov64_imm(8, 0x5a5a5a5a)];
        reg_fill.extend(memset_call(10, -32, 32, BPF_W, 0x5a));
        reg_fill.push(BpfInsn::exit());
        [
            (
                "nonzero immediate",
                make_program(make_memset_nonzero_imm_program()),
                nonzero_imm,
            ),
            (
                "byte immediate truncates",
                make_program(make_memset_truncated_byte_imm_program()),
                truncated_byte,
            ),
            (
                "negative dw immediate",
                make_program(make_memset_negative_dw_imm_program()),
                negative_dw,
            ),
            (
                "register fill",
                make_program(make_nonzero_memset_reg_program()),
                reg_fill,
            ),
        ]
    } {
        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
        assert_eq!(result.pass_results[0].sites_applied, 1, "{label}");
        assert_eq!(program.insns, expected, "{label}");
    }
}

#[test]
fn test_bulk_memory_negative_pattern_matrix() {
    for (label, original) in [
        (
            "no consecutive stores",
            make_no_consecutive_stores_program(),
        ),
        (
            "non-repeated immediate",
            make_memset_non_repeated_imm_program(),
        ),
        ("below threshold", make_below_threshold_program()),
    ] {
        let mut program = make_program(original.clone());
        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
        assert_eq!(program.insns, original, "{label}");
        assert_eq!(result.pass_results[0].sites_applied, 0, "{label}");
    }
}

#[test]
fn test_bulk_memory_segmentation_matrix() {
    for (label, mut program, expected, memcpy_calls, memset_calls) in {
        let mut different_base = memcpy_call(10, -64, 6, 0, 32, 3);
        different_base.extend(memcpy_call(8, 0, 10, -32, 32, 3));
        different_base.push(BpfInsn::exit());
        let mut non_consecutive = memcpy_call(10, -64, 6, 0, 32, 3);
        non_consecutive.extend(memcpy_call(10, -24, 6, 40, 32, 3));
        non_consecutive.push(BpfInsn::exit());
        let mut interleaved = memset_zero_call(10, -64, 32, BPF_DW);
        interleaved.push(BpfInsn::mov64_imm(9, 1));
        interleaved.extend(memset_zero_call(10, -32, 32, BPF_DW));
        interleaved.push(BpfInsn::exit());
        [
            (
                "different base regs",
                make_program(make_different_base_regs_program()),
                different_base,
                2,
                0,
            ),
            (
                "non-consecutive offsets",
                make_program(make_non_consecutive_offsets_program()),
                non_consecutive,
                2,
                0,
            ),
            (
                "interleaved non-store",
                make_program(make_interleaved_non_store_program()),
                interleaved,
                0,
                2,
            ),
        ]
    } {
        let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
        assert_eq!(result.pass_results[0].sites_applied, 2, "{label}");
        assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), memcpy_calls);
        assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), memset_calls);
        assert_eq!(program.insns, expected, "{label}");
    }
}

#[test]
fn test_non_stack_base_memcpy_skipped_by_alias_gate() {
    let original = make_non_stack_base_memcpy_program();
    let mut program = make_program(original.clone());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("alias not provably safe")));
}

#[test]
fn test_mixed_widths_handled() {
    let mut program = make_program(make_mixed_widths_program());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(bulk_call_count(&program.insns, MEMSET_BTF_ID), 1);
    assert_eq!(program.insns.last(), Some(&BpfInsn::exit()));
}

#[test]
fn test_branch_fixup_after_replacement() {
    let mut program = make_program(make_branch_fixup_program());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(bulk_call_count(&program.insns, MEMCPY_BTF_ID), 1);
    assert_eq!(program.insns[0], BpfInsn::jeq_imm(0, 0, 3));
}

#[test]
fn test_same_base_chunked_overlap_skipped() {
    let original = make_same_base_chunked_overlap_program();
    let mut program = make_program(original.clone());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("overlapping same-base memcpy run")));
}

#[test]
fn test_memcpy_proof_tmp_live_out_skipped() {
    let mut original = make_memcpy_run(BPF_DW, 3, 6, 0, 10, -64, 8);
    original.push(BpfInsn::mov64_reg(8, 3));
    original.push(BpfInsn::exit());
    let mut program = make_program(original.clone());

    let result = run_bulk_memory_pass(&mut program, &ctx_with_bulk_kfuncs());
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("tmp_reg r3 is live after site")));
}
