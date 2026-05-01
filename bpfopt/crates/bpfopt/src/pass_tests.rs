use super::*;
use crate::insn::*;

// ── Test helpers ────────────────────────────────────────────────

/// Construct a minimal BPF program from instructions.
fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

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

fn ctx_for_pass_manager(pm: &PassManager) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.policy.enabled_passes = pm.pass_names().into_iter().map(str::to_string).collect();
    ctx
}

/// A no-op pass that does not change the program.
struct NoOpPass;

impl BpfPass for NoOpPass {
    fn name(&self) -> &str {
        "noop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        _program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that unconditionally appends a NOP instruction.
struct AppendNopPass;

impl BpfPass for AppendNopPass {
    fn name(&self) -> &str {
        "append_nop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        program.insns.push(BpfInsn::nop());
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: 1,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that inserts a NOP at the beginning of the program.
struct PrependNopPass;

impl BpfPass for PrependNopPass {
    fn name(&self) -> &str {
        "prepend_nop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let old_len = program.insns.len();
        program.insns.insert(0, BpfInsn::nop());
        let addr_map = (0..=old_len).map(|pc| pc + 1).collect::<Vec<_>>();
        program.remap_annotations(&addr_map);
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: 1,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that replaces all MOV64_IMM with a different immediate value.
struct RewriteMovImmPass {
    new_imm: i32,
}

impl BpfPass for RewriteMovImmPass {
    fn name(&self) -> &str {
        "rewrite_mov_imm"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let mut applied = 0;
        for insn in &mut program.insns {
            if insn.code == (BPF_ALU64 | BPF_MOV | BPF_K) {
                insn.imm = self.new_imm;
                applied += 1;
            }
        }
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

#[test]
fn test_prepend_nop_pass_shifts_annotations_forward() {
    let mut pm = PassManager::new();
    pm.add_pass(PrependNopPass);

    let mut program = make_program(vec![BpfInsn::mov64_imm(0, 1), exit_insn()]);
    program.annotations[1].branch_profile = Some(branch_profile(7, 3, 1));

    let ctx = ctx_for_pass_manager(&pm);
    let result = pm.run(&mut program, &ctx).unwrap();

    assert!(result.program_changed);
    assert_eq!(program.insns.len(), 3);
    assert!(program.annotations[0].branch_profile.is_none());
    assert!(program.annotations[1].branch_profile.is_none());
    assert_eq!(
        program.annotations[2]
            .branch_profile
            .as_ref()
            .expect("prepended program should remap existing annotation")
            .taken_count,
        7
    );
}

/// A trivial analysis that counts the number of instructions.
struct InsnCountAnalysis;

impl Analysis for InsnCountAnalysis {
    type Result = usize;
    fn name(&self) -> &str {
        "insn_count"
    }
    fn run(&self, program: &BpfProgram) -> usize {
        program.insns.len()
    }
}

/// A pass that reads the InsnCountAnalysis result and stores it in diagnostics.
struct CountReportingPass;

impl BpfPass for CountReportingPass {
    fn name(&self) -> &str {
        "count_reporter"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Observability
    }
    fn required_analyses(&self) -> Vec<&str> {
        vec!["insn_count"]
    }
    fn run(
        &self,
        _program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let analysis = InsnCountAnalysis;
        let count = analyses.get(&analysis, _program);
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec![format!("insn_count={}", count)],
            ..Default::default()
        })
    }
}

struct MissingAnalysisPass;

impl BpfPass for MissingAnalysisPass {
    fn name(&self) -> &str {
        "missing_analysis"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["not_registered"]
    }

    fn run(
        &self,
        _program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        Ok(PassResult::unchanged(self.name()))
    }
}

struct VerifierStateCountPass;

impl BpfPass for VerifierStateCountPass {
    fn name(&self) -> &str {
        "verifier_state_count"
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            diagnostics: vec![format!("verifier_states={}", program.verifier_states.len())],
            ..Default::default()
        })
    }
}

fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

// ── BpfProgram tests ────────────────────────────────────────────

#[test]
fn test_bpf_program_sync_annotations_grow() {
    let mut prog = make_program(vec![exit_insn()]);
    assert_eq!(prog.annotations.len(), 1);
    prog.insns.push(BpfInsn::nop());
    prog.insns.push(BpfInsn::nop());
    prog.sync_annotations();
    assert_eq!(prog.annotations.len(), 3);
}

#[test]
fn test_bpf_program_sync_annotations_shrink() {
    let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), exit_insn()]);
    assert_eq!(prog.annotations.len(), 3);
    prog.insns.truncate(1);
    prog.sync_annotations();
    assert_eq!(prog.annotations.len(), 1);
}

// ── AnalysisCache tests ─────────────────────────────────────────

#[test]
fn test_analysis_cache_basic() {
    let mut cache = AnalysisCache::new();
    let prog = make_program(vec![BpfInsn::nop(), exit_insn()]);
    let analysis = InsnCountAnalysis;

    assert!(!cache.is_cached::<usize>());
    let count = cache.get(&analysis, &prog);
    assert_eq!(count, 2);
    assert!(cache.is_cached::<usize>());
}

#[test]
fn test_analysis_cache_targeted_invalidation_for_known_types() {
    use crate::analysis::{
        BranchTargetAnalysis, BranchTargetResult, CFGAnalysis, CFGResult, LivenessAnalysis,
        LivenessResult,
    };

    let mut cache = AnalysisCache::new();
    let prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);

    // Populate all three analyses.
    cache.get(&BranchTargetAnalysis, &prog);
    cache.get(&CFGAnalysis, &prog);
    cache.get(&LivenessAnalysis, &prog);

    assert!(cache.is_cached::<BranchTargetResult>());
    assert!(cache.is_cached::<CFGResult>());
    assert!(cache.is_cached::<LivenessResult>());

    // Targeted invalidation of BranchTargetResult only.
    cache.invalidate::<BranchTargetResult>();
    assert!(!cache.is_cached::<BranchTargetResult>());
    assert!(cache.is_cached::<CFGResult>());
    assert!(cache.is_cached::<LivenessResult>());

    // Invalidate the rest.
    cache.invalidate::<CFGResult>();
    cache.invalidate::<LivenessResult>();
    assert!(!cache.is_cached::<CFGResult>());
    assert!(!cache.is_cached::<LivenessResult>());
}

// ── PassManager tests ───────────────────────────────────────────

#[test]
fn test_pass_manager_empty_pipeline() {
    let pm = PassManager::new();
    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    let ctx = PassContext::test_default();

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 0);
    assert_eq!(result.total_sites_applied, 0);
    assert!(!result.program_changed);
    // Program should be unchanged.
    assert_eq!(prog.insns.len(), 2);
}

#[test]
fn test_pass_manager_multiple_passes_sequential() {
    let mut pm = PassManager::new();
    pm.add_pass(RewriteMovImmPass { new_imm: 99 });
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 2);
    // First pass: rewrite_mov_imm changed the MOV IMM value.
    assert!(result.pass_results[0].changed);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    // Second pass: append_nop added a NOP.
    assert!(result.pass_results[1].changed);
    assert_eq!(result.pass_results[1].sites_applied, 1);

    assert_eq!(result.total_sites_applied, 2);
    assert!(result.program_changed);

    // Check the MOV IMM was rewritten.
    assert_eq!(prog.insns[0].imm, 99);
    // Check the NOP was appended.
    assert_eq!(prog.insns.len(), 3);
    assert!(prog.insns[2].is_ja() && prog.insns[2].off == 0);
}

#[test]
fn test_pass_manager_analysis_cache_invalidation() {
    // After a transform pass, the analysis cache should be invalidated.
    // A subsequent analysis read should see the updated program.
    let mut pm = PassManager::new();
    pm.register_analysis(InsnCountAnalysis);

    // First pass: report count (should see 2 insns)
    pm.add_pass(CountReportingPass);
    // Second pass: append a NOP (modifies program)
    pm.add_pass(AppendNopPass);
    // Third pass: report count again (should see 3 insns after invalidation)
    pm.add_pass(CountReportingPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 3);
    // First count_reporter sees 2 instructions.
    assert_eq!(result.pass_results[0].diagnostics, vec!["insn_count=2"]);
    // append_nop runs.
    assert!(result.pass_results[1].changed);
    // Second count_reporter should see 3 instructions (cache was invalidated).
    assert_eq!(result.pass_results[2].diagnostics, vec!["insn_count=3"]);
}

#[test]
fn test_pass_manager_rejects_unregistered_required_analysis() {
    let mut pm = PassManager::new();
    pm.add_pass(MissingAnalysisPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    let ctx = ctx_for_pass_manager(&pm);

    let err = pm.run(&mut prog, &ctx).unwrap_err();
    assert!(
        err.to_string()
            .contains("requires unknown analysis 'not_registered'"),
        "err={err:#}"
    );
}

#[test]
fn test_pass_manager_invalidates_verifier_states_after_transform() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);
    pm.add_pass(VerifierStateCountPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    prog.set_verifier_states(vec![VerifierInsn {
        pc: 0,
        frame: 0,
        from_pc: None,
        kind: VerifierInsnKind::InsnDeltaState,
        speculative: false,
        regs: HashMap::new(),
        stack: HashMap::new(),
    }]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 2);
    assert!(result.pass_results[0].changed);
    assert_eq!(
        result.pass_results[1].diagnostics,
        vec!["verifier_states=0"]
    );
}

#[test]
fn test_pass_manager_enabled_pass_policy() {
    let mut pm = PassManager::new();
    pm.add_pass(NoOpPass);
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![exit_insn()]);
    let mut ctx = PassContext::test_default();
    // Only enable append_nop — noop should be skipped.
    ctx.policy.enabled_passes = vec!["append_nop".into()];

    let result = pm.run(&mut prog, &ctx).unwrap();

    // Only append_nop should run.
    assert_eq!(result.pass_results.len(), 1);
    assert_eq!(result.pass_results[0].pass_name, "append_nop");
    assert!(result.program_changed);
    assert_eq!(prog.insns.len(), 2);
}

// ── Per-target static call offset tests ────────────────────────

#[test]
fn test_kinsn_registry_per_target_call_offsets() {
    let reg = KinsnRegistry {
        rotate64_btf_id: 10,
        select64_btf_id: 20,
        ccmp64_btf_id: -1,
        extract64_btf_id: 30,
        memcpy_bulk_btf_id: -1,
        memset_bulk_btf_id: -1,
        endian_load16_btf_id: -1,
        endian_load32_btf_id: -1,
        endian_load64_btf_id: -1,
        prefetch_btf_id: -1,
        target_call_offsets: HashMap::from([
            ("bpf_rotate64".to_string(), 100),
            ("bpf_select64".to_string(), 200),
            ("bpf_extract64".to_string(), 300),
        ]),
        target_supported_encodings: HashMap::new(),
    };

    assert_eq!(reg.call_off_for_target_name("bpf_rotate64"), 100);
    assert_eq!(reg.call_off_for_target_name("bpf_select64"), 200);
    assert_eq!(reg.call_off_for_target_name("bpf_extract64"), 300);
}

// ── Issue 5: Annotation remap tests ─────────────────────────

#[test]
fn test_remap_annotations_deleted_instruction() {
    let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), exit_insn()]);
    prog.annotations[0].branch_profile = Some(branch_profile(10, 5, 1));

    // Simulate a transform that removes instruction 0.
    // addr_map: old_pc 0->0 (maps to first new insn), 1->0, 2->1, sentinel 3->2
    // After rewrite, the program has 2 instructions.
    prog.insns = vec![BpfInsn::nop(), exit_insn()];
    // Both old pcs 0 and 1 map to new pc 0 — the annotation from old pc 0
    // ends up at new pc 0.
    let addr_map = vec![0, 0, 1, 2];
    prog.remap_annotations(&addr_map);

    assert!(prog.annotations[0].branch_profile.is_some());
    assert_eq!(prog.annotations.len(), 2);
}

// ── Issue 6: PGO closedloop tests ───────────────────────────

#[test]
fn test_profiling_data_injection() {
    let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), exit_insn()]);
    assert!(prog.annotations[1].branch_profile.is_none());

    let mut pdata = ProfilingData::default();
    pdata.branch_profiles.insert(1, branch_profile(80, 20, 2));
    prog.inject_profiling(&pdata);

    assert!(prog.annotations[0].branch_profile.is_none());
    assert!(prog.annotations[1].branch_profile.is_some());
    let bp = prog.annotations[1].branch_profile.as_ref().unwrap();
    assert_eq!(bp.taken_count, 80);
    assert_eq!(bp.not_taken_count, 20);
}

#[test]
fn test_run_with_profiling_enables_branch_flip() {
    use crate::analysis::BranchTargetAnalysis;

    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.add_pass(BranchFlipPass {
        min_bias: 0.7,
        max_branch_miss_rate: 0.05,
    });

    // A simple diamond that would be flipped if PGO says the branch is hot.
    let jne = BpfInsn::new(BPF_JMP | BPF_JNE | BPF_K, BpfInsn::make_regs(1, 0), 2, 0);
    let mut prog = make_program(vec![
        jne,                       // pc=0
        BpfInsn::mov64_imm(0, 10), // then
        BpfInsn::ja(1),            // skip else
        BpfInsn::mov64_imm(0, 20), // else
        exit_insn(),
    ]);
    let ctx = PassContext::test_default();

    // Without profiling: branch_flip fails fast.
    let err = pm.run_with_profiling(&mut prog, &ctx, None).unwrap_err();
    assert!(err
        .to_string()
        .contains("real program-level branch_miss_rate data"));

    // Reset the program.
    let mut prog = make_program(vec![
        jne,
        BpfInsn::mov64_imm(0, 10),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 20),
        exit_insn(),
    ]);

    // With profiling data showing hot branch + PMU data: should flip.
    let mut pdata = ProfilingData::default();
    pdata.branch_profiles.insert(0, branch_profile(90, 10, 1));
    pdata.branch_miss_rate = Some(0.02);
    let result = pm
        .run_with_profiling(&mut prog, &ctx, Some(&pdata))
        .unwrap();
    assert!(
        result.program_changed,
        "should flip with PGO data showing hot branch"
    );
}

// ── BranchFlipPass import for testing ───────────────────────
use crate::passes::BranchFlipPass;

// ── PlatformCapabilities tests ──────────────────────────────

#[test]
fn test_pass_skips_without_platform_capability() {
    // A pass that requires CMOV (cond_select on x86) should skip when the
    // platform capability is unavailable.
    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::passes::CondSelectPass;

    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.add_pass(CondSelectPass);

    // Context has select kinsn available but platform lacks CMOV.
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.select64_btf_id = 1234;
    // has_cmov is false by default in test_default().

    let mut prog = make_program(vec![
        BpfInsn::new(
            crate::insn::BPF_JMP | crate::insn::BPF_JNE | crate::insn::BPF_K,
            BpfInsn::make_regs(1, 0),
            2,
            0,
        ),
        BpfInsn::mov64_reg(2, 4),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(2, 3),
        exit_insn(),
    ]);

    let result = pm.run(&mut prog, &ctx).unwrap();
    // Should not apply anything because platform lacks CMOV.
    assert!(!result.program_changed);
    assert_eq!(result.total_sites_applied, 0);
    // Should have a skip reason about CMOV.
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("CMOV")));
}

#[test]
fn test_invalid_policy_pass_name_is_rejected() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![exit_insn()]);
    let mut ctx = ctx_for_pass_manager(&pm);
    ctx.policy.enabled_passes = vec!["bulk_mem".into()];

    let err = pm
        .run(&mut prog, &ctx)
        .expect_err("legacy aliases should be rejected");

    assert!(err.to_string().contains("invalid enabled_passes"));
    assert!(err.to_string().contains("unknown pass name(s): bulk_mem"));
}

#[test]
fn test_pass_result_skip_reason_counts() {
    let result = PassResult {
        pass_name: "test".into(),
        changed: false,
        sites_applied: 0,
        sites_skipped: vec![
            SkipReason {
                pc: 0,
                reason: "kfunc_unavailable".into(),
            },
            SkipReason {
                pc: 5,
                reason: "subprog_unsupported".into(),
            },
            SkipReason {
                pc: 10,
                reason: "kfunc_unavailable".into(),
            },
            SkipReason {
                pc: 15,
                reason: "kfunc_unavailable".into(),
            },
            SkipReason {
                pc: 20,
                reason: "insufficient_bias".into(),
            },
        ],
        diagnostics: vec![],
        ..Default::default()
    };

    let counts = result.skip_reason_counts();
    assert_eq!(counts["kfunc_unavailable"], 3);
    assert_eq!(counts["subprog_unsupported"], 1);
    assert_eq!(counts["insufficient_bias"], 1);
    assert_eq!(counts.len(), 3);
}

#[test]
fn test_pass_result_insns_before_after_filled_by_pass_manager() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![exit_insn()]);
    let ctx = ctx_for_pass_manager(&pm);
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 1);
    let pr = &result.pass_results[0];
    // Before append_nop: 1 instruction (exit).
    assert_eq!(pr.insns_before, 1);
    // After append_nop: 2 instructions (exit + NOP).
    assert_eq!(pr.insns_after, 2);
}
