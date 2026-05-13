// SPDX-License-Identifier: MIT

use super::branch_flip::BranchFlipPass;
use crate::insn::*;
use crate::pass::BranchProfile;
use crate::test_helpers::*;

fn diamond() -> Vec<BpfInsn> {
    vec![
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(BPF_REG_0, 20),
        BpfInsn::exit(),
    ]
}

fn pass() -> BranchFlipPass {
    BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    }
}

fn ctx_with_branch_profile(taken: u64, not_taken: u64, miss_rate: f64) -> crate::pass::PassContext {
    let mut annotations = vec![None::<BranchProfile>; 5];
    annotations[0] = Some(branch_profile(taken, not_taken, miss_rate));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;
    ctx.branch_miss_rate = Some(0.02);
    ctx
}

#[test]
fn branch_flip_requires_program_level_pmu_data() {
    // BranchFlip must fail fast without real PMU program data.
    let annotations = {
        let mut anns = vec![None::<BranchProfile>; 5];
        anns[0] = Some(branch_profile(80, 20, 0.02));
        anns
    };
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;

    let err = pass_error_on_insns(pass(), diamond(), &ctx);

    assert!(err.contains("real program-level branch_miss_rate data"));
}

#[test]
fn branch_flip_requires_per_site_pgo_data() {
    // BranchFlip must not invent heuristic per-site PMU fields.
    let mut ctx = pass_ctx();
    ctx.branch_miss_rate = Some(0.02);

    let err = pass_error_on_insns(pass(), diamond(), &ctx);

    assert!(err.contains("no real per-site branch count"));
}

#[test]
fn branch_flip_flips_biased_diamond_with_low_miss_rate() {
    let ctx = ctx_with_branch_profile(80, 20, 0.02);

    let run = run_pass_on_insns(pass(), diamond(), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(bpf_op(run.lowered[0].code), BPF_JEQ);
    assert_eq!(run.lowered[0].off, 2);
    assert_eq!(run.lowered[1].imm, 20);
    assert!(run.lowered[2].is_ja());
    assert_eq!(run.lowered[2].off, 1);
    assert_eq!(run.lowered[3].imm, 10);
}

#[test]
fn test_branch_flip_asymmetric_with_pgo() {
    // Restored from HEAD: asymmetric then/else lengths stress branch inversion
    // and offset recomputation differently from the symmetric diamond.
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_1, 0, 3),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 2),
        BpfInsn::ja(3),
        BpfInsn::mov64_imm(BPF_REG_0, 10),
        BpfInsn::mov64_imm(BPF_REG_1, 20),
        BpfInsn::mov64_imm(BPF_REG_2, 30),
        BpfInsn::exit(),
    ];
    let mut annotations = vec![None::<BranchProfile>; input.len()];
    annotations[0] = Some(branch_profile(90, 10, 0.01));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;
    ctx.branch_miss_rate = Some(0.02);

    let run = run_pass_on_insns(pass(), input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(bpf_op(run.lowered[0].code), BPF_JNE);
    assert_eq!(run.lowered[0].off, 4);
    assert_eq!(run.lowered[1].imm, 10);
    assert_eq!(run.lowered[2].imm, 20);
    assert_eq!(run.lowered[3].imm, 30);
    assert!(run.lowered[4].is_ja());
    assert_eq!(run.lowered[4].off, 2);
    assert_eq!(run.lowered[5].imm, 1);
    assert_eq!(run.lowered[6].imm, 2);
    assert_eq!(run.lowered.len(), 8);
}

#[test]
fn test_branch_flip_skips_jset() {
    // Restored from HEAD: JSET has no safe inversion in this pass and must not
    // be rewritten even when PMU data is strongly biased.
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_JSET | BPF_K,
            BpfInsn::make_regs(BPF_REG_1, 0),
            2,
            0xff,
        ),
        BpfInsn::mov64_imm(BPF_REG_0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(BPF_REG_0, 20),
        BpfInsn::exit(),
    ];
    let mut annotations = vec![None::<BranchProfile>; input.len()];
    annotations[0] = Some(branch_profile(90, 10, 0.01));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;
    ctx.branch_miss_rate = Some(0.02);

    let run = run_pass_on_insns(pass(), input.clone(), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
    assert_skip_reason(&run.result, 0, "cannot invert");
}

#[test]
fn branch_flip_skips_insufficient_bias() {
    let ctx = ctx_with_branch_profile(60, 40, 0.02);

    let run = run_pass_on_insns(pass(), diamond(), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "not biased enough");
}

#[test]
fn branch_flip_skips_high_program_miss_rate() {
    let mut ctx = ctx_with_branch_profile(80, 20, 0.02);
    ctx.branch_miss_rate = Some(0.10);

    let run = run_pass_on_insns(pass(), diamond(), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "branch_miss_rate");
}

#[test]
fn branch_flip_skips_high_site_miss_rate() {
    let ctx = ctx_with_branch_profile(90, 10, 0.10);

    let run = run_pass_on_insns(pass(), diamond(), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "site branch_miss_rate");
}

#[test]
fn branch_flip_rejects_oversized_else_delta_through_pass_path() {
    // P1-H: exercise the actual pass and ProgramCFG lower path, not only a helper.
    let mut insns = vec![
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 10),
        BpfInsn::ja(i16::MAX),
    ];
    for _ in 0..i16::MAX as usize {
        insns.push(BpfInsn::mov64_imm(BPF_REG_0, 20));
    }
    insns.push(BpfInsn::exit());
    let mut annotations = vec![None::<BranchProfile>; insns.len()];
    annotations[0] = Some(branch_profile(90, 10, 0.01));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;
    ctx.branch_miss_rate = Some(0.02);

    let err = pass_error_on_insns(pass(), insns, &ctx);

    assert!(err.contains("exceeds i16"));
}

#[test]
fn branch_flip_handles_multiple_sites_without_length_change() {
    let input = vec![
        BpfInsn::jump_imm(BPF_JNE, BPF_REG_1, 0, 3),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_2, 2),
        BpfInsn::ja(2),
        BpfInsn::mov64_imm(BPF_REG_0, 10),
        BpfInsn::mov64_imm(BPF_REG_2, 20),
        BpfInsn::jeq_imm(BPF_REG_3, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 100),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(BPF_REG_0, 200),
        BpfInsn::exit(),
    ];
    let mut annotations = vec![None::<BranchProfile>; input.len()];
    annotations[0] = Some(branch_profile(80, 20, 0.02));
    annotations[6] = Some(branch_profile(85, 15, 0.02));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;
    ctx.branch_miss_rate = Some(0.02);

    let run = run_pass_on_insns(pass(), input.clone(), &ctx);

    assert_eq!(run.result.sites_applied, 2);
    assert_eq!(run.lowered.len(), input.len());
    assert!(run.lowered.last().unwrap().is_exit());
}
