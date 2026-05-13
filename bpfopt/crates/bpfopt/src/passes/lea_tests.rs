// SPDX-License-Identifier: MIT

use super::lea::LeaPass;
use crate::insn::*;
use crate::test_helpers::*;

fn lea_ctx() -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_lea64", 6464, 0)
        .expect("register lea64");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_lea32", 3232, 0)
        .expect("register lea32");
    ctx
}

fn sidecar_payload(run: &PassRun) -> u64 {
    run.lowered
        .iter()
        .find(|insn| insn.is_kinsn_sidecar())
        .expect("lea rewrite should emit sidecar")
        .sidecar_payload()
}

#[test]
fn lea_rewrites_mov_add_imm64() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_10),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_3, -32),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &lea_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 6464));
    let payload = sidecar_payload(&run);
    assert_eq!(BpfInsn::unpack_u4(payload, 0), BPF_REG_3);
    assert_eq!(BpfInsn::unpack_u4(payload, 4), BPF_REG_10);
    assert_eq!(BpfInsn::unpack_u4(payload, 8), 0);
    assert_eq!((payload >> 14) & 1, 0);
    assert_eq!((payload >> 15) & 1, 1);
    assert_eq!(BpfInsn::unpack_u32(payload, 16) as i32, -32);
}

#[test]
fn lea_rewrites_mov_add_reg64() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_4, BPF_REG_7),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_4, BPF_REG_5),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &lea_ctx());

    assert_eq!(run.result.sites_applied, 1);
    let payload = sidecar_payload(&run);
    assert_eq!(BpfInsn::unpack_u4(payload, 0), BPF_REG_4);
    assert_eq!(BpfInsn::unpack_u4(payload, 4), BPF_REG_7);
    assert_eq!(BpfInsn::unpack_u4(payload, 8), BPF_REG_5);
    assert_eq!((payload >> 14) & 1, 1);
}

#[test]
fn lea_rewrites_alu32_forms_to_lea32() {
    let input = vec![
        BpfInsn::mov32_reg(BPF_REG_1, BPF_REG_2),
        BpfInsn::alu32_reg(BPF_ADD, BPF_REG_1, BPF_REG_6),
        BpfInsn::mov32_reg(BPF_REG_3, BPF_REG_4),
        BpfInsn::alu32_imm(BPF_ADD, BPF_REG_3, 12),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &lea_ctx());

    assert_eq!(run.result.sites_applied, 2);
    assert_eq!(
        run.lowered
            .iter()
            .filter(|i| i.is_call_kinsn() && i.imm == 3232)
            .count(),
        2
    );
}

#[test]
fn lea_rejects_zero_imm() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_7),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_3, 0),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input.clone(), &lea_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn lea_rewrites_add_dst_dst_as_base_doubling() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_4, BPF_REG_8),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_4, BPF_REG_4),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &lea_ctx());

    assert_eq!(run.result.sites_applied, 1);
    let payload = sidecar_payload(&run);
    assert_eq!(BpfInsn::unpack_u4(payload, 0), BPF_REG_4);
    assert_eq!(BpfInsn::unpack_u4(payload, 4), BPF_REG_8);
    assert_eq!(BpfInsn::unpack_u4(payload, 8), BPF_REG_8);
    assert_eq!((payload >> 14) & 1, 1);
}

#[test]
fn lea_skips_site_with_interior_branch_target() {
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_5, 0, 1),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_7),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_3, 8),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &lea_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 1, "interior branch target");
}

#[test]
fn lea_preserves_module_call_offset() {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_lea64", 6464, 4)
        .expect("register lea64 module call");
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_7),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_3, 8),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(LeaPass, input, &ctx);
    let call = run.lowered.iter().find(|i| i.is_call_kinsn()).unwrap();

    assert_eq!(call.imm, 6464);
    assert_eq!(call.off, 4);
}
