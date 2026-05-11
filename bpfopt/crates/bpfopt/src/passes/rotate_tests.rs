// SPDX-License-Identifier: MIT

use super::rotate::RotatePass;
use crate::insn::*;
use crate::test_helpers::*;

fn rotate64_ctx(btf_id: i32) -> crate::pass::PassContext {
    let mut ctx = ctx_with_kinsn("bpf_rotate64", btf_id);
    ctx.platform.has_rorx = true;
    ctx
}

fn rotate32_ctx(btf_id: i32) -> crate::pass::PassContext {
    let mut ctx = ctx_with_kinsn("bpf_rotate32", btf_id);
    ctx.platform.has_rorx = true;
    ctx
}

#[test]
fn rotate_rewrites_provenance_mov_ror64_pattern() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_2),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_3, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input, &rotate64_ctx(9999));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 9999));
}

#[test]
fn rotate_rewrites_rol64_variant_with_reversed_or_order() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_2),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_3, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_2, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input, &rotate64_ctx(9999));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn rotate_rewrites_cilium_split_copy_shape() {
    let input = vec![
        BpfInsn::mov32_reg(BPF_REG_1, BPF_REG_6),
        BpfInsn::alu32_imm(BPF_RSH, BPF_REG_1, 28),
        BpfInsn::mov32_reg(BPF_REG_2, BPF_REG_6),
        BpfInsn::alu32_imm(BPF_LSH, BPF_REG_2, 4),
        BpfInsn::alu32_reg(BPF_OR, BPF_REG_2, BPF_REG_1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input, &rotate32_ctx(8888));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 8888));
}

#[test]
fn rotate_rejects_missing_adjacent_provenance_mov() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_2),
        BpfInsn::mov64_reg(BPF_REG_8, BPF_REG_8),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_3, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input.clone(), &rotate64_ctx(9999));

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn rotate_rejects_wrong_provenance_source() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_4),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_3, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input.clone(), &rotate64_ctx(9999));

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn rotate_rejects_tmp_live_out_conflict() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_2),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_6, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_6),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_6),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input, &rotate64_ctx(9999));

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "tmp_reg");
}

#[test]
fn rotate_applies_inside_subprogram_frame() {
    let input = vec![
        BpfInsn::pseudo_call_to(0, 2),
        BpfInsn::exit(),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_2),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 56),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_3, 8),
        BpfInsn::alu64_reg(BPF_OR, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(RotatePass, input, &rotate64_ctx(1234));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 1234));
}
