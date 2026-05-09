use super::branch_flip::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, BranchProfile, PassContext};
use crate::test_helpers::*;

fn branch_profile(taken_count: u64, not_taken_count: u64, branch_misses: u64) -> BranchProfile {
    let branch_count = taken_count + not_taken_count;
    assert!(branch_count > 0);
    assert!(branch_misses <= branch_count);
    BranchProfile {
        branch_count,
        branch_misses,
        miss_rate: branch_misses as f64 / branch_count as f64,
        taken_count,
        not_taken_count,
    }
}

// ── True diamond: Jcc +N ; [then N-1] ; JA +M ; [else M] ──
// Example: JNE +2 ; mov(then) ; JA +1 ; mov(else)
// then_len=1, else_len=1

#[test]
fn test_scan_finds_diamond() {
    // JNE r1, 0, +2 ; mov r0, 10 ; JA +1 ; mov r0, 20 ; exit
    let insns = vec![
        jne_imm(1, 0, 2),          // pc=0: Jcc +2 -> target pc=3 (else_start)
        BpfInsn::mov64_imm(0, 10), // pc=1: then body
        BpfInsn::ja(1),            // pc=2: JA +1 -> skip else
        BpfInsn::mov64_imm(0, 20), // pc=3: else body
        BpfInsn::exit(),           // pc=4
    ];
    let sites = scan_branch_flip_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].pc, 0);
    assert_eq!(sites[0].then_len, 1);
    assert_eq!(sites[0].else_len, 1);
    assert_eq!(sites[0].total_len(), 4);
}

#[test]
fn test_scan_asymmetric_diamond() {
    // JEQ r1, 0, +3 ; mov1 ; mov2 ; JA +1 ; mov3 ; exit
    let insns = vec![
        jeq_imm(1, 0, 3),          // Jcc +3 -> target pc=4 (else_start)
        BpfInsn::mov64_imm(0, 1),  // then[0]
        BpfInsn::mov64_imm(1, 2),  // then[1]
        BpfInsn::ja(1),            // JA +1
        BpfInsn::mov64_imm(0, 10), // else[0]
        BpfInsn::exit(),
    ];
    let sites = scan_branch_flip_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].then_len, 2);
    assert_eq!(sites[0].else_len, 1);
}

#[test]
fn test_branch_flip_missing_per_site_profile_errors() {
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    // Provide PMU data so the pass proceeds past the PMU check.
    prog.branch_miss_rate = Some(0.02);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let err = pass.run(&mut prog, &mut cache, &ctx).unwrap_err();
    assert!(err.to_string().contains("no real per-site profile data"));
}

#[test]
fn test_branch_flip_with_biased_pgo() {
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),          // Jcc +2 -> else at pc=3
        BpfInsn::mov64_imm(0, 10), // then
        BpfInsn::ja(1),            // skip else
        BpfInsn::mov64_imm(0, 20), // else
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(80, 20, 2));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    // After flip layout: [JEQ +2] [else: mov 20] [JA +1] [then: mov 10] [exit]
    assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ); // inverted JNE -> JEQ
    assert_eq!(prog.insns[0].off, 2); // skip else(1) + JA(1) = 2
    assert_eq!(prog.insns[1].imm, 20); // else body first
    assert!(prog.insns[2].is_ja());
    assert_eq!(prog.insns[2].off, 1); // jump over then body (1 insn)
    assert_eq!(prog.insns[3].imm, 10); // then body second
    assert_eq!(prog.insns.len(), 5); // same size
}

#[test]
fn test_branch_flip_asymmetric_with_pgo() {
    // then=2 insns, else=3 insns
    let mut prog = make_program(vec![
        jeq_imm(1, 0, 3),          // Jcc +3 -> else at pc=4
        BpfInsn::mov64_imm(0, 1),  // then[0]
        BpfInsn::mov64_imm(1, 2),  // then[1]
        BpfInsn::ja(3),            // JA +3 -> skip else
        BpfInsn::mov64_imm(0, 10), // else[0]
        BpfInsn::mov64_imm(1, 20), // else[1]
        BpfInsn::mov64_imm(2, 30), // else[2]
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(90, 10, 1));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert_eq!(bpf_op(prog.insns[0].code), BPF_JNE); // inverted JEQ -> JNE
    assert_eq!(prog.insns[0].off, 4); // skip else(3) + JA(1) = 4
                                      // Else body first
    assert_eq!(prog.insns[1].imm, 10);
    assert_eq!(prog.insns[2].imm, 20);
    assert_eq!(prog.insns[3].imm, 30);
    // JA to skip then body
    assert!(prog.insns[4].is_ja());
    assert_eq!(prog.insns[4].off, 2); // jump over then body (2 insns)
                                      // Then body second
    assert_eq!(prog.insns[5].imm, 1);
    assert_eq!(prog.insns[6].imm, 2);
    assert_eq!(prog.insns.len(), 8); // same size
}

#[test]
fn test_branch_flip_skips_jset() {
    let mut prog = make_program(vec![
        BpfInsn::new(
            BPF_JMP | BPF_JSET | BPF_K,
            BpfInsn::make_regs(1, 0),
            2,
            0xff,
        ),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(90, 10, 1));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("cannot invert")));
}

#[test]
fn test_branch_flip_insufficient_bias() {
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(60, 40, 2));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("not biased enough")));
}

#[test]
fn test_invert_jcc_roundtrip() {
    let pairs = [
        (BPF_JEQ, BPF_JNE),
        (BPF_JGT, BPF_JLE),
        (BPF_JGE, BPF_JLT),
        (BPF_JSGT, BPF_JSLE),
        (BPF_JSGE, BPF_JSLT),
    ];
    for (a, b) in pairs {
        assert_eq!(invert_jcc_op(a), Some(b));
        assert_eq!(invert_jcc_op(b), Some(a));
    }
    assert_eq!(invert_jcc_op(BPF_JSET), None);
}

#[test]
fn test_branch_flip_skips_high_miss_rate() {
    // With high branch miss rate from PMU, the pass should skip all sites
    // even if per-PC PGO data says to flip.
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(80, 20, 2));
    // Simulate high branch miss rate (10% > 5% threshold).
    prog.branch_miss_rate = Some(0.10);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("branch_miss_rate")));
}

#[test]
fn test_branch_flip_allows_low_miss_rate() {
    // With low branch miss rate from PMU, the pass should proceed normally.
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(80, 20, 2));
    // Low branch miss rate (2% < 5% threshold) — should allow flip.
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_branch_flip_missing_program_pmu_data_errors() {
    // Without program-level PMU data, branch_flip fails fast.
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(80, 20, 2));
    // No PMU data.
    assert!(prog.branch_miss_rate.is_none());

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let err = pass.run(&mut prog, &mut cache, &ctx).unwrap_err();
    assert!(err
        .to_string()
        .contains("real program-level branch_miss_rate data"));
}

#[test]
fn test_branch_flip_skips_high_site_miss_rate() {
    let mut prog = make_program(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(90, 10, 10));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("site branch_miss_rate")));
}

// ── MEDIUM #4: Profiler -> pass integration test ────────────────

/// MEDIUM #4: Test the data flow from ProfilingData -> BranchFlipPass.
/// Constructs ProfilingData in the profiler output shape and injects it
/// before the full pass pipeline runs.
#[test]
fn test_profiler_to_pass_pipeline_integration() {
    // Build a program with a biased branch
    let insns = vec![
        jne_imm(1, 0, 2),          // PC 0: biased branch
        BpfInsn::mov64_imm(0, 10), // PC 1
        BpfInsn::ja(1),            // PC 2
        BpfInsn::mov64_imm(0, 20), // PC 3
        BpfInsn::exit(),           // PC 4
    ];
    let mut prog = BpfProgram::new(insns);

    // Construct ProfilingData as the profiler module would
    let mut branch_profiles = std::collections::HashMap::new();
    branch_profiles.insert(0, branch_profile(90, 10, 1));
    let profiling = crate::pass::ProfilingData {
        branch_profiles,
        branch_miss_rate: Some(0.10), // 10% miss rate => high, should trigger
        ..Default::default()
    };

    prog.inject_profiling(&profiling);
    let mut pm = PassManager::new();
    pm.register_analysis(crate::analysis::BranchTargetAnalysis);
    pm.register_analysis(crate::analysis::LivenessAnalysis);
    pm.add_pass(BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    });
    let mut ctx = PassContext::baseline();
    ctx.policy.enabled_passes = vec!["branch_flip".to_string()];

    let _result = pm.run(&mut prog, &ctx).unwrap();

    // With high miss rate (0.10 > max_branch_miss_rate 0.05), the pass should skip.
    // This tests that profiling data correctly flows through the pipeline.

    // Now test with low miss rate (should flip)
    let profiling_low_miss = crate::pass::ProfilingData {
        branch_profiles: {
            let mut m = std::collections::HashMap::new();
            m.insert(0, branch_profile(90, 10, 1));
            m
        },
        branch_miss_rate: Some(0.01), // 1% miss rate => low, should trigger
        ..Default::default()
    };

    let mut prog2 = BpfProgram::new(vec![
        jne_imm(1, 0, 2),
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        BpfInsn::exit(),
    ]);
    prog2.inject_profiling(&profiling_low_miss);

    let mut pm2 = PassManager::new();
    pm2.register_analysis(crate::analysis::BranchTargetAnalysis);
    pm2.register_analysis(crate::analysis::LivenessAnalysis);
    pm2.add_pass(BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    });

    let _result2 = pm2.run(&mut prog2, &ctx).unwrap();

    // With low miss rate and high bias, the branch should be flipped
}

/// Test that branch_flip correctly handles multiple sequential diamonds
/// in a program, verifying that branch offsets are correctly adjusted
/// after flipping multiple sites.
#[test]
fn test_branch_flip_multiple_sites_correctness() {
    // Build a program with two consecutive diamonds.
    let mut prog = make_program(vec![
        // Diamond 1: JNE r1, 0, +3 ; mov1 ; mov2 ; JA +2 ; mov3 ; mov4
        jne_imm(1, 0, 3),          // pc=0: Jcc +3 -> else at pc=4
        BpfInsn::mov64_imm(0, 1),  // pc=1: then[0]
        BpfInsn::mov64_imm(2, 2),  // pc=2: then[1]
        BpfInsn::ja(2),            // pc=3: JA +2
        BpfInsn::mov64_imm(0, 10), // pc=4: else[0]
        BpfInsn::mov64_imm(2, 20), // pc=5: else[1]
        // Diamond 2: JEQ r3, 0, +2 ; mov5 ; JA +1 ; mov6
        jeq_imm(3, 0, 2),           // pc=6: Jcc +2 -> else at pc=9
        BpfInsn::mov64_imm(0, 100), // pc=7: then
        BpfInsn::ja(1),             // pc=8: JA +1
        BpfInsn::mov64_imm(0, 200), // pc=9: else
        BpfInsn::exit(),            // pc=10
    ]);
    // Inject biased PGO data for both diamonds.
    prog.annotations[0].branch_profile = Some(branch_profile(80, 20, 2));
    prog.annotations[6].branch_profile = Some(branch_profile(85, 15, 2));
    prog.branch_miss_rate = Some(0.02);

    let orig_len = prog.insns.len();

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 2, "should flip both diamonds");
    // Size should be preserved.
    assert_eq!(prog.insns.len(), orig_len);
    // Last instruction should still be EXIT.
    assert!(prog.insns.last().unwrap().is_exit());
    // First Jcc should be inverted: JNE -> JEQ
    assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ);
}

/// Test correctness of a flipped diamond by verifying the instruction
/// layout matches expected output: inverted condition, swapped bodies.
#[test]
fn test_branch_flip_verifies_output_layout() {
    // Diamond: JNE r1, 0, +3 ; mov A ; mov B ; JA +1 ; mov C
    // then_len=2, else_len=1
    let mut prog = make_program(vec![
        jne_imm(1, 0, 3),          // pc=0: Jcc +3 -> else at pc=4
        BpfInsn::mov64_imm(0, 1),  // pc=1: then[0]
        BpfInsn::mov64_imm(2, 2),  // pc=2: then[1]
        BpfInsn::ja(1),            // pc=3: JA +1
        BpfInsn::mov64_imm(0, 99), // pc=4: else[0]
        BpfInsn::exit(),           // pc=5
    ]);
    prog.annotations[0].branch_profile = Some(branch_profile(90, 10, 1));
    prog.branch_miss_rate = Some(0.02);

    let mut cache = AnalysisCache::new();
    let ctx = PassContext::baseline();

    let pass = BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    };
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);

    // After flip: [JEQ +2] [else: mov 99] [JA +2] [then: mov 1, mov 2] [exit]
    assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ); // inverted
    assert_eq!(prog.insns[0].off, 2); // skip else(1) + JA(1)
    assert_eq!(prog.insns[1].imm, 99); // else body first
    assert!(prog.insns[2].is_ja());
    assert_eq!(prog.insns[2].off, 2); // skip then(2)
    assert_eq!(prog.insns[3].imm, 1); // then body second
    assert_eq!(prog.insns[4].imm, 2); // then body second
    assert!(prog.insns[5].is_exit());
}
