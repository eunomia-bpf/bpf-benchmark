// SPDX-License-Identifier: MIT

use super::extract::ExtractPass;
use crate::insn::*;
use crate::test_helpers::*;

fn extract_ctx(btf_id: i32) -> crate::pass::PassContext {
    let mut ctx = ctx_with_kinsn("bpf_extract64", btf_id);
    ctx.platform.has_bmi1 = true;
    ctx
}

#[test]
fn extract_rewrites_shift_and_mask_to_kinsn() {
    let input = vec![
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 7777));
}

#[test]
fn extract_rewrites_sign_extended_all_ones_mask() {
    let input = vec![
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_3, 0),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_3, -1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 1);
}

#[test]
fn extract_rejects_non_contiguous_mask() {
    let input = vec![
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0x5),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input.clone(), &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn extract_rejects_different_registers() {
    let input = vec![
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_3, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input.clone(), &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn extract_skips_site_with_interior_branch_target() {
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_5, 0, 1),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 1, "interior branch target");
}

#[test]
fn test_extract_pass_branch_fixup() {
    // Restored from HEAD: expanding shift+mask into a kinsn call must retarget
    // branches that skip over the original two-instruction extract site.
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_5, 0, 2),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 1);
    let last_pc = run.lowered.len() - 1;
    assert!(run.lowered[last_pc].is_exit());
    let branch_target = (1 + run.lowered[0].off as i64) as usize;
    assert_eq!(branch_target, last_pc);
}

#[test]
fn extract_preserves_module_call_offset() {
    let mut ctx = pass_ctx();
    ctx.platform.has_bmi1 = true;
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_extract64", 7777, 3)
        .expect("register module kinsn");
    let input = vec![
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &ctx);
    let call = run.lowered.iter().find(|i| i.is_call_kinsn()).unwrap();

    assert_eq!(call.imm, 7777);
    assert_eq!(call.off, 3);
}

#[test]
fn extract_applies_inside_subprogram_frame() {
    let input = vec![
        BpfInsn::pseudo_call_to(0, 4),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_2, 8),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 0xff),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(ExtractPass, input, &extract_ctx(7777));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}
