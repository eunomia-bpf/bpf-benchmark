// SPDX-License-Identifier: MIT

use super::cond_select::CondSelectPass;
use crate::insn::*;
use crate::pass::Arch;
use crate::test_helpers::*;

fn select_ctx() -> crate::pass::PassContext {
    ctx_with_kinsn("bpf_select64", 5555)
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

fn simulate_param_setup(insns: &[BpfInsn], initial_regs: &[u64; 11]) -> [u64; 11] {
    let sidecar = insns.iter().find(|insn| insn.is_kinsn_sidecar()).unwrap();
    let payload = sidecar.sidecar_payload();
    let a_reg = ((payload >> 4) & 0xf) as usize;
    let b_reg = ((payload >> 8) & 0xf) as usize;
    let cond_reg = ((payload >> 12) & 0xf) as usize;

    let mut regs = [0u64; 11];
    regs[1] = initial_regs[a_reg];
    regs[2] = initial_regs[b_reg];
    regs[3] = initial_regs[cond_reg];
    regs
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
    // Restored from HEAD: parallel parameter setup for bpf_select64 must be
    // alias-safe for every cond/true/false overlap among r1-r3.
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

                let mut initial = [0u64; 11];
                initial[BPF_REG_1 as usize] = 100;
                initial[BPF_REG_2 as usize] = 200;
                initial[BPF_REG_3 as usize] = 300;
                let after = simulate_param_setup(&run.lowered, &initial);

                assert_eq!(
                    after[BPF_REG_1 as usize], initial[true_src as usize],
                    "r1 wrong: cond=r{} true=r{} false=r{}",
                    cond_reg, true_src, false_src
                );
                assert_eq!(
                    after[BPF_REG_2 as usize], initial[false_src as usize],
                    "r2 wrong: cond=r{} true=r{} false=r{}",
                    cond_reg, true_src, false_src
                );
                assert_eq!(
                    after[BPF_REG_3 as usize], initial[cond_reg as usize],
                    "r3 wrong: cond=r{} true=r{} false=r{}",
                    cond_reg, true_src, false_src
                );
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
fn cond_select_skips_when_no_branchless_target_exists() {
    let input = pattern(
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
    );

    let run = run_pass_on_insns(CondSelectPass, input, &pass_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 0, "branchless select");
}

#[test]
fn cond_select_works_on_aarch64_without_cmov_cpu_feature() {
    let mut ctx = select_ctx();
    ctx.platform.arch = Arch::Aarch64;
    let input = pattern(
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
    );

    let run = run_pass_on_insns(CondSelectPass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}
