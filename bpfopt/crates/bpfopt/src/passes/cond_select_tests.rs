// SPDX-License-Identifier: MIT

use super::cond_select::CondSelectPass;
use crate::insn::*;
use crate::test_helpers::*;

fn select_ctx() -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_testq_rr", 5555, 0)
        .expect("register testq kinsn");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_cmovneq_rr", 5556, 0)
        .expect("register cmovneq kinsn");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_cmoveq_rr", 5557, 0)
        .expect("register cmoveq kinsn");
    ctx
}

fn pattern(false_mov: BpfInsn, true_mov: BpfInsn) -> Vec<BpfInsn> {
    vec![
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 2),
        false_mov,
        BpfInsn::ja(1),
        true_mov,
        BpfInsn::exit(),
    ]
}

#[test]
fn cond_select_rewrites_imm_true_reg_false_diamond() {
    let input = pattern(
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_6),
        BpfInsn::mov32_imm(BPF_REG_0, 1),
    );

    let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 5555));
}

#[test]
fn cond_select_rewrites_reg_true_imm_false_diamond() {
    let input = pattern(
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_7),
    );

    let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_kinsn_sidecar()));
}

#[test]
fn test_cond_select_alias_all_overlap_combinations() {
    // Register overlaps among predicate/true/false operands must not block
    // lowering into adjacent test+cmov machine-instruction kinsns.
    let regs = [BPF_REG_1, BPF_REG_2, BPF_REG_3];
    for &cond_reg in &regs {
        for &true_src in &regs {
            for &false_src in &regs {
                let input = vec![
                    BpfInsn::jump_imm(BPF_JNE, cond_reg, 0, 2),
                    BpfInsn::mov64_reg(BPF_REG_0, false_src),
                    BpfInsn::ja(1),
                    BpfInsn::mov64_reg(BPF_REG_0, true_src),
                    BpfInsn::exit(),
                ];

                let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

                assert_eq!(run.result.sites_applied, 1);
                if true_src != false_src {
                    assert!(run.lowered.iter().any(|insn| insn.is_call_kinsn()));
                }
            }
        }
    }
}

#[test]
fn cond_select_materializes_non_zero_compare_predicate() {
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_1, 5, 2),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_6),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_7),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .contains(&BpfInsn::alu64_imm(BPF_XOR, BPF_REG_0, 5)));
}

#[test]
fn cond_select_rewrites_jmp32_predicate() {
    let input = vec![
        BpfInsn::new(
            BPF_JMP32 | BPF_JNE | BPF_K,
            BpfInsn::make_regs(BPF_REG_1, 0),
            2,
            0,
        ),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_6),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_7),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn cond_select_rewrites_diamond_join_with_external_predecessor() {
    // Outer JEQ at pc=0 has an external edge to the shared join (pc=5 exit).
    // The inner JNE at pc=1 forms a valid cond_select diamond whose join is
    // that same exit. The rewrite must succeed: predecessor body is replaced
    // with the select sequence and retargeted to the still-live join.
    let input = vec![
        BpfInsn::jump_imm(BPF_JEQ, BPF_REG_9, 0, 4),
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CondSelectPass, input, &select_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn test_cond_select_short_pattern_c_no_match_cond_clobbered() {
    // Restored from HEAD: short pattern C must not match when the pre-branch
    // MOV overwrites the register that the following Jcc reads.
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 42),
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 0),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CondSelectPass, input.clone(), &select_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn cond_select_errors_when_no_branchless_target_exists() {
    let input = pattern(
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
    );

    let err = pass_error_on_insns(CondSelectPass, input, &pass_ctx());

    assert!(err.contains("bpf_x86_testq_rr"), "unexpected error: {err}");
}
