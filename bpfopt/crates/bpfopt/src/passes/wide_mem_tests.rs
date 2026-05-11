// SPDX-License-Identifier: MIT

use super::wide_mem::WideMemPass;
use crate::insn::*;
use crate::test_helpers::*;

fn wide_mem_2(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, dst, base, off),
        BpfInsn::ldx_mem(BPF_B, tmp, base, off + 1),
        BpfInsn::alu64_imm(BPF_LSH, tmp, 8),
        BpfInsn::alu64_reg(BPF_OR, dst, tmp),
    ]
}

fn wide_mem_4(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, dst, base, off),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, base, off + 1),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_2, 8),
        BpfInsn::alu64_reg(BPF_OR, dst, BPF_REG_2),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_3, base, off + 2),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_3, 16),
        BpfInsn::alu64_reg(BPF_OR, dst, BPF_REG_3),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_4, base, off + 3),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_4, 24),
        BpfInsn::alu64_reg(BPF_OR, dst, BPF_REG_4),
    ]
}

fn with_exit(mut insns: Vec<BpfInsn>) -> Vec<BpfInsn> {
    insns.push(BpfInsn::exit());
    insns
}

#[test]
fn wide_mem_collapses_halfword_byte_ladder() {
    let run = run_pass_on_insns(
        WideMemPass,
        with_exit(wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 10)),
        &pass_ctx(),
    );

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(run.lowered.len(), 2);
    assert_eq!(run.lowered[0].code, BPF_LDX | BPF_H | BPF_MEM);
    assert_eq!(run.lowered[0].off, 10);
}

#[test]
fn wide_mem_collapses_multiple_sites() {
    let mut input = wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 0);
    input.extend(wide_mem_2(BPF_REG_3, BPF_REG_4, BPF_REG_7, 4));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 2);
    assert_eq!(run.lowered.len(), 3);
    assert_eq!(run.lowered[0].code, BPF_LDX | BPF_H | BPF_MEM);
    assert_eq!(run.lowered[1].code, BPF_LDX | BPF_H | BPF_MEM);
}

#[test]
fn wide_mem_skips_misaligned_halfword_site() {
    let run = run_pass_on_insns(
        WideMemPass,
        with_exit(wide_mem_2(BPF_REG_1, BPF_REG_2, BPF_REG_10, -95)),
        &pass_ctx(),
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "not naturally aligned");
}

#[test]
fn wide_mem_skips_site_with_interior_branch_target() {
    let mut input = vec![BpfInsn::jeq_imm(BPF_REG_5, 0, 2)];
    input.extend(wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 0));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 1, "interior branch target");
}

#[test]
fn wide_mem_skips_site_with_live_scratch_reg() {
    let mut input = wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 0);
    input.push(BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_1));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "scratch register live");
}

#[test]
fn wide_mem_updates_forward_branch_after_shrinking_site() {
    let mut input = vec![BpfInsn::ja(10)];
    input.extend(wide_mem_4(BPF_REG_0, BPF_REG_6, 0));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[0].is_ja());
    assert_eq!(run.lowered[0].off, 1);
}

#[test]
fn wide_mem_updates_backward_branch_after_shrinking_site() {
    let mut input = vec![BpfInsn::mov64_imm(BPF_REG_0, 0)];
    input.extend(wide_mem_4(BPF_REG_0, BPF_REG_6, 0));
    input.push(BpfInsn::ja(-12));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[2].is_ja());
    assert_eq!(run.lowered[2].off, -3);
}

#[test]
fn wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside() {
    // P1-H: kinsn/pass replacement must not cross pseudo-func subprogram boundary.
    let map_ref = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, 42);
    let callback = BpfInsn::ld_imm64(BPF_REG_2, BPF_PSEUDO_FUNC, 2);
    let mut input = vec![map_ref[0], map_ref[1], callback[0], callback[1]];
    input.extend(wide_mem_2(BPF_REG_6, BPF_REG_8, BPF_REG_10, -8));
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(WideMemPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 4, "interior branch target");
    assert!(run.lowered[2].is_ldimm64_pseudo_func());
}

#[test]
fn wide_mem_skips_btf_struct_pointer_field_loads() {
    // P1-H: BTF struct pointers are not ordinary byte ladders.
    let ctx = ctx_with_verifier_states(vec![verifier_full_state(
        0,
        std::collections::HashMap::from([(
            BPF_REG_6,
            crate::pass::RegState::new(
                "trusted_ptr_bpf_prog",
                crate::pass::VerifierValueWidth::Unknown,
            ),
        )]),
    )]);

    let run = run_pass_on_insns(
        WideMemPass,
        with_exit(wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 0)),
        &ctx,
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "BTF struct pointer");
}

#[test]
fn wide_mem_xdp_skips_non_stack_packet_pointer_candidates() {
    let mut ctx = pass_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(
        WideMemPass,
        with_exit(wide_mem_2(BPF_REG_0, BPF_REG_1, BPF_REG_6, 0)),
        &ctx,
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "packet pointer");
}
