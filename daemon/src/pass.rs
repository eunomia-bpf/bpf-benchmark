// SPDX-License-Identifier: MIT
//! Pass framework — LLVM-style PassManager for BPF program transformations.
//!
//! Core abstractions:
//! - `BpfProgram`: linear instruction stream + per-insn annotations + metadata
//! - `Analysis`: read-only analysis producing typed, cached results
//! - `BpfPass`: transformation pass that may modify the program
//! - `PassManager`: orchestrates pass execution and analysis cache invalidation

use std::any::{Any, TypeId};
use std::collections::HashMap;

use crate::insn::BpfInsn;

// ── Program metadata ────────────────────────────────────────────────

/// Program provenance metadata, obtained from BPF_OBJ_GET_INFO_BY_FD.
#[derive(Clone, Debug, Default)]
pub struct ProgMeta {
    pub prog_id: u32,
    pub prog_type: u32,
    pub prog_name: String,
    pub map_ids: Vec<u32>,
    pub btf_id: u32,
    pub run_cnt: u64,
    pub run_time_ns: u64,
}

/// Per-instruction annotation — populated by analysis passes, read by transform passes.
#[derive(Clone, Debug, Default)]
pub struct InsnAnnotation {
    /// Whether this is a branch/call target.
    pub is_branch_target: bool,
    /// Whether this is a subprogram entry.
    pub is_subprog_entry: bool,
    /// Whether this is the second slot of LD_IMM64.
    pub is_ldimm64_hi: bool,
    /// Subprogram ID (-1 = main).
    pub subprog_id: i32,
    /// Verifier-provided register type information (optional).
    pub verifier_state: Option<VerifierRegState>,
    /// PGO: branch taken/not-taken counts at this instruction.
    pub branch_profile: Option<BranchProfile>,
    /// Free-form key-value metadata.
    pub metadata: HashMap<String, i64>,
}

/// Verifier-exported register state (per-insn).
#[derive(Clone, Debug)]
pub struct VerifierRegState {
    pub regs: [RegInfo; 11], // r0-r10
}

#[derive(Clone, Debug, Default)]
pub struct RegInfo {
    pub reg_type: u32,
    pub known_value: Option<i64>,
    pub min_value: i64,
    pub max_value: i64,
    pub is_const: bool,
}

/// PGO branch statistics.
#[derive(Clone, Debug)]
pub struct BranchProfile {
    pub taken_count: u64,
    pub not_taken_count: u64,
}

// ── Program IR ──────────────────────────────────────────────────────

/// BPF program IR — linear instruction stream + per-insn annotations + metadata.
///
/// This is the core data structure operated on by all passes. Transform passes
/// modify `insns`; analysis passes populate `annotations` and the analysis cache.
#[derive(Clone)]
pub struct BpfProgram {
    /// Instruction stream (mutable — transform passes modify this).
    pub insns: Vec<BpfInsn>,
    /// Per-insn annotations (length synchronized with insns).
    pub annotations: Vec<InsnAnnotation>,
    /// Program metadata.
    pub meta: ProgMeta,
    /// Transform log: records what each pass did.
    pub transform_log: Vec<TransformEntry>,
}

#[derive(Clone, Debug)]
pub struct TransformEntry {
    pub pass_name: String,
    pub sites_applied: usize,
    pub insns_before: usize,
    pub insns_after: usize,
    pub details: Vec<String>,
}

impl BpfProgram {
    /// Create from raw instructions and metadata. Annotations are default-initialized.
    pub fn new(insns: Vec<BpfInsn>, meta: ProgMeta) -> Self {
        let len = insns.len();
        Self {
            insns,
            annotations: vec![InsnAnnotation::default(); len],
            meta,
            transform_log: Vec::new(),
        }
    }

    /// Resynchronize annotations length after instruction stream changes.
    /// Transform passes must call this after modifying insns.
    pub fn sync_annotations(&mut self) {
        self.annotations
            .resize_with(self.insns.len(), InsnAnnotation::default);
    }

    /// Record a transform operation.
    pub fn log_transform(&mut self, entry: TransformEntry) {
        self.transform_log.push(entry);
    }

    /// Whether any transforms have been applied.
    pub fn has_transforms(&self) -> bool {
        self.transform_log.iter().any(|e| e.sites_applied > 0)
    }
}

// ── Analysis trait ──────────────────────────────────────────────────

/// Analysis pass trait. Each analysis produces a typed Result.
///
/// Analysis passes do not modify the instruction stream — they only read
/// the program and produce analysis results. Results are stored in
/// AnalysisCache and may be shared by multiple transform passes.
pub trait Analysis: Send + Sync {
    /// The concrete result type of this analysis.
    type Result: Any + Clone + Send + Sync;

    /// Analysis name (for debug/logging).
    fn name(&self) -> &str;

    /// Run the analysis and return the result.
    /// Receives an immutable reference to BpfProgram.
    fn run(&self, program: &BpfProgram) -> Self::Result;
}

/// Analysis result cache — indexed by TypeId, supports invalidation.
///
/// When a transform pass modifies the program, the PassManager calls
/// `invalidate_all()` to clear the cache. The next pass that needs an
/// analysis result triggers recomputation.
pub struct AnalysisCache {
    cache: HashMap<TypeId, Box<dyn Any + Send + Sync>>,
}

impl AnalysisCache {
    pub fn new() -> Self {
        Self {
            cache: HashMap::new(),
        }
    }

    /// Get analysis result. If not cached, run the analysis and cache it.
    pub fn get<A: Analysis + 'static>(&mut self, analysis: &A, program: &BpfProgram) -> A::Result {
        let type_id = TypeId::of::<A::Result>();
        if let Some(cached) = self.cache.get(&type_id) {
            if let Some(result) = cached.downcast_ref::<A::Result>() {
                return result.clone();
            }
        }
        let result = analysis.run(program);
        self.cache.insert(type_id, Box::new(result.clone()));
        result
    }

    /// Invalidate all cached results (called after a transform pass modifies the program).
    pub fn invalidate_all(&mut self) {
        self.cache.clear();
    }

    /// Invalidate a specific analysis result.
    pub fn invalidate<R: Any>(&mut self) {
        self.cache.remove(&TypeId::of::<R>());
    }

    /// Check whether a specific analysis result is currently cached.
    pub fn is_cached<R: Any>(&self) -> bool {
        self.cache.contains_key(&TypeId::of::<R>())
    }
}

// ── BpfPass trait ───────────────────────────────────────────────────

/// Pass execution result.
#[derive(Clone, Debug)]
pub struct PassResult {
    /// Pass name.
    pub pass_name: String,
    /// Whether the program was modified (triggers analysis invalidation).
    pub changed: bool,
    /// Number of sites applied.
    pub sites_applied: usize,
    /// Sites that were skipped (with reasons).
    pub sites_skipped: Vec<SkipReason>,
    /// Diagnostic messages.
    pub diagnostics: Vec<String>,
}

#[derive(Clone, Debug)]
pub struct SkipReason {
    pub pc: usize,
    pub reason: String,
}

/// Pass category.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PassCategory {
    /// Performance optimization.
    Optimization,
    /// Security hardening.
    Security,
    /// Observability enhancement.
    Observability,
}

/// Transform pass trait.
///
/// Each optimization is a pass: scan the program, find rewrite sites, apply transforms.
/// Passes can read analysis results through AnalysisCache.
pub trait BpfPass: Send + Sync {
    /// Pass name.
    fn name(&self) -> &str;

    /// Pass category.
    fn category(&self) -> PassCategory;

    /// Declare analyses this pass depends on (for PassManager ordering and precomputation).
    fn required_analyses(&self) -> Vec<&str> {
        vec![]
    }

    /// Execute the pass.
    ///
    /// - `program`: mutable reference — pass may modify the instruction stream
    /// - `analyses`: analysis cache — pass may obtain analysis results
    /// - `ctx`: platform context (kfunc availability, CPU features, etc.)
    ///
    /// Returns PassResult describing what was done.
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult>;
}

/// Pass execution context — contains platform info and external configuration.
///
/// These values are invariant for the duration of a pipeline execution.
#[derive(Clone, Debug)]
pub struct PassContext {
    /// Available kinsn kfuncs and their BTF IDs.
    pub kfunc_registry: KfuncRegistry,
    /// CPU capabilities.
    pub platform: PlatformCapabilities,
    /// Policy configuration (which passes are enabled, parameters, etc.).
    pub policy: PolicyConfig,
}

/// Available kfuncs and their BTF IDs.
/// BTF ID = -1 means the kfunc is not available.
#[derive(Clone, Debug, Default)]
pub struct KfuncRegistry {
    pub rotate64_btf_id: i32,
    pub select64_btf_id: i32,
    pub extract64_btf_id: i32,
    pub lea64_btf_id: i32,
    pub movbe64_btf_id: i32,
    /// Module FD (when using module kfuncs, REJIT's fd_array needs it).
    pub module_fd: Option<i32>,
}

/// CPU platform capabilities.
#[derive(Clone, Debug, Default)]
pub struct PlatformCapabilities {
    pub has_bmi1: bool,
    pub has_bmi2: bool,
    pub has_cmov: bool,
    pub has_movbe: bool,
    pub has_rorx: bool,
    pub arch: Arch,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum Arch {
    #[default]
    X86_64,
    Aarch64,
}

/// Optimization policy configuration.
#[derive(Clone, Debug, Default)]
pub struct PolicyConfig {
    /// Enabled pass name list (empty = all enabled).
    pub enabled_passes: Vec<String>,
    /// Disabled pass name list.
    pub disabled_passes: Vec<String>,
    /// Global parameters.
    pub params: HashMap<String, String>,
}

// ── Type-erased analysis wrapper ────────────────────────────────────

/// Type-erased Analysis trait object wrapper.
pub trait AnyAnalysis: Send + Sync {
    fn name(&self) -> &str;
    fn run_and_cache(&self, program: &BpfProgram, cache: &mut AnalysisCache);
}

/// Blanket impl of AnyAnalysis for all Analysis types.
impl<A: Analysis + 'static> AnyAnalysis for A
where
    A::Result: 'static,
{
    fn name(&self) -> &str {
        Analysis::name(self)
    }

    fn run_and_cache(&self, program: &BpfProgram, cache: &mut AnalysisCache) {
        cache.get(self, program);
    }
}

// ── Analysis registry ───────────────────────────────────────────────

/// Analysis registry — stores all available analysis instances.
pub struct AnalysisRegistry {
    registry: HashMap<String, Box<dyn AnyAnalysis>>,
}

impl AnalysisRegistry {
    pub fn new() -> Self {
        Self {
            registry: HashMap::new(),
        }
    }
}

// ── PassManager ─────────────────────────────────────────────────────

/// Pipeline execution result.
#[derive(Clone, Debug)]
pub struct PipelineResult {
    pub pass_results: Vec<PassResult>,
    pub total_sites_applied: usize,
    pub program_changed: bool,
}

/// PassManager — manages and executes the pass pipeline.
///
/// Similar to LLVM's FunctionPassManager: executes passes in order,
/// manages analysis cache invalidation, and collects statistics.
pub struct PassManager {
    passes: Vec<Box<dyn BpfPass>>,
    analyses: AnalysisRegistry,
}

impl PassManager {
    pub fn new() -> Self {
        Self {
            passes: Vec::new(),
            analyses: AnalysisRegistry::new(),
        }
    }

    /// Register an analysis.
    pub fn register_analysis<A: Analysis + 'static>(&mut self, analysis: A)
    where
        A::Result: 'static,
    {
        let name = analysis.name().to_string();
        self.analyses.registry.insert(name, Box::new(analysis));
    }

    /// Add a pass to the end of the pipeline.
    pub fn add_pass<P: BpfPass + 'static>(&mut self, pass: P) {
        self.passes.push(Box::new(pass));
    }

    /// Return the number of registered passes.
    pub fn pass_count(&self) -> usize {
        self.passes.len()
    }

    /// Execute the entire pipeline.
    ///
    /// For each pass:
    /// 1. Ensure required analyses are computed
    /// 2. Run the pass
    /// 3. If the pass modified the program, invalidate the analysis cache
    pub fn run(
        &self,
        program: &mut BpfProgram,
        ctx: &PassContext,
    ) -> anyhow::Result<PipelineResult> {
        let mut cache = AnalysisCache::new();
        let mut pass_results = Vec::new();
        let mut total_sites = 0usize;
        let mut any_changed = false;

        for pass in &self.passes {
            // Check whether policy allows this pass.
            if !ctx.policy.disabled_passes.is_empty()
                && ctx
                    .policy
                    .disabled_passes
                    .contains(&pass.name().to_string())
            {
                continue;
            }
            if !ctx.policy.enabled_passes.is_empty()
                && !ctx
                    .policy
                    .enabled_passes
                    .contains(&pass.name().to_string())
            {
                continue;
            }

            // Ensure required analyses are computed.
            for analysis_name in pass.required_analyses() {
                if let Some(analysis) = self.analyses.registry.get(analysis_name) {
                    analysis.run_and_cache(program, &mut cache);
                }
            }

            // Run the pass.
            let result = pass.run(program, &mut cache, ctx)?;

            if result.changed {
                // Transform modified the program — invalidate all analysis caches.
                cache.invalidate_all();
                // Synchronize annotations.
                program.sync_annotations();
                any_changed = true;
            }

            total_sites += result.sites_applied;
            pass_results.push(result);
        }

        Ok(PipelineResult {
            pass_results,
            total_sites_applied: total_sites,
            program_changed: any_changed,
        })
    }
}

// ── Helper: default PassContext for testing ──────────────────────────

impl PassContext {
    /// Create a minimal PassContext suitable for testing.
    /// All kfuncs unavailable (btf_id = -1), no special CPU features.
    pub fn test_default() -> Self {
        Self {
            kfunc_registry: KfuncRegistry {
                rotate64_btf_id: -1,
                select64_btf_id: -1,
                extract64_btf_id: -1,
                lea64_btf_id: -1,
                movbe64_btf_id: -1,
                module_fd: None,
            },
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig::default(),
        }
    }
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;

    // ── Test helpers ────────────────────────────────────────────────

    /// Construct a minimal BPF program from instructions.
    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
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
            })
        }
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
            })
        }
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    // ── BpfProgram tests ────────────────────────────────────────────

    #[test]
    fn test_bpf_program_new() {
        let prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        assert_eq!(prog.insns.len(), 2);
        assert_eq!(prog.annotations.len(), 2);
        assert!(!prog.has_transforms());
    }

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

    #[test]
    fn test_bpf_program_log_transform() {
        let mut prog = make_program(vec![exit_insn()]);
        assert!(!prog.has_transforms());
        prog.log_transform(TransformEntry {
            pass_name: "test".into(),
            sites_applied: 0,
            insns_before: 1,
            insns_after: 1,
            details: vec![],
        });
        // sites_applied == 0, so has_transforms should be false
        assert!(!prog.has_transforms());

        prog.log_transform(TransformEntry {
            pass_name: "test2".into(),
            sites_applied: 1,
            insns_before: 1,
            insns_after: 2,
            details: vec!["added nop".into()],
        });
        assert!(prog.has_transforms());
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
    fn test_analysis_cache_returns_cached_value() {
        let mut cache = AnalysisCache::new();
        let prog = make_program(vec![BpfInsn::nop(), exit_insn()]);
        let analysis = InsnCountAnalysis;

        let count1 = cache.get(&analysis, &prog);
        // Even if we could change the program, the cached value should be returned
        let count2 = cache.get(&analysis, &prog);
        assert_eq!(count1, count2);
        assert_eq!(count1, 2);
    }

    #[test]
    fn test_analysis_cache_invalidate_all() {
        let mut cache = AnalysisCache::new();
        let prog = make_program(vec![exit_insn()]);
        let analysis = InsnCountAnalysis;

        cache.get(&analysis, &prog);
        assert!(cache.is_cached::<usize>());

        cache.invalidate_all();
        assert!(!cache.is_cached::<usize>());
    }

    #[test]
    fn test_analysis_cache_invalidate_specific() {
        let mut cache = AnalysisCache::new();
        let prog = make_program(vec![exit_insn()]);
        let analysis = InsnCountAnalysis;

        cache.get(&analysis, &prog);
        assert!(cache.is_cached::<usize>());

        cache.invalidate::<usize>();
        assert!(!cache.is_cached::<usize>());
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
    fn test_pass_manager_single_pass_no_change() {
        let mut pm = PassManager::new();
        pm.add_pass(NoOpPass);
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert_eq!(result.pass_results.len(), 1);
        assert_eq!(result.pass_results[0].pass_name, "noop");
        assert!(!result.pass_results[0].changed);
        assert_eq!(result.total_sites_applied, 0);
        assert!(!result.program_changed);
        assert_eq!(prog.insns.len(), 2);
    }

    #[test]
    fn test_pass_manager_single_pass_with_change() {
        let mut pm = PassManager::new();
        pm.add_pass(AppendNopPass);
        let mut prog = make_program(vec![exit_insn()]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert_eq!(result.pass_results.len(), 1);
        assert!(result.pass_results[0].changed);
        assert_eq!(result.total_sites_applied, 1);
        assert!(result.program_changed);
        // Original 1 insn + 1 appended NOP
        assert_eq!(prog.insns.len(), 2);
        // Annotations should be synced
        assert_eq!(prog.annotations.len(), 2);
    }

    #[test]
    fn test_pass_manager_multiple_passes_sequential() {
        let mut pm = PassManager::new();
        pm.add_pass(RewriteMovImmPass { new_imm: 99 });
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let ctx = PassContext::test_default();

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
        let ctx = PassContext::test_default();

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
    fn test_pass_result_reporting() {
        let result = PassResult {
            pass_name: "test_pass".into(),
            changed: true,
            sites_applied: 3,
            sites_skipped: vec![
                SkipReason {
                    pc: 5,
                    reason: "interior branch".into(),
                },
                SkipReason {
                    pc: 15,
                    reason: "caller-saved conflict".into(),
                },
            ],
            diagnostics: vec!["applied 3 sites".into()],
        };

        assert_eq!(result.pass_name, "test_pass");
        assert!(result.changed);
        assert_eq!(result.sites_applied, 3);
        assert_eq!(result.sites_skipped.len(), 2);
        assert_eq!(result.sites_skipped[0].pc, 5);
        assert_eq!(result.sites_skipped[1].reason, "caller-saved conflict");
        assert_eq!(result.diagnostics.len(), 1);
    }

    #[test]
    fn test_pass_manager_disabled_pass_policy() {
        let mut pm = PassManager::new();
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![exit_insn()]);
        let mut ctx = PassContext::test_default();
        ctx.policy.disabled_passes = vec!["append_nop".into()];

        let result = pm.run(&mut prog, &ctx).unwrap();

        // The pass should be skipped.
        assert_eq!(result.pass_results.len(), 0);
        assert!(!result.program_changed);
        assert_eq!(prog.insns.len(), 1);
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

    #[test]
    fn test_pass_category() {
        let noop = NoOpPass;
        assert_eq!(noop.category(), PassCategory::Optimization);

        let reporter = CountReportingPass;
        assert_eq!(reporter.category(), PassCategory::Observability);
    }

    #[test]
    fn test_pipeline_result_aggregate() {
        let pr = PipelineResult {
            pass_results: vec![
                PassResult {
                    pass_name: "a".into(),
                    changed: true,
                    sites_applied: 2,
                    sites_skipped: vec![],
                    diagnostics: vec![],
                },
                PassResult {
                    pass_name: "b".into(),
                    changed: false,
                    sites_applied: 0,
                    sites_skipped: vec![],
                    diagnostics: vec![],
                },
            ],
            total_sites_applied: 2,
            program_changed: true,
        };

        assert!(pr.program_changed);
        assert_eq!(pr.total_sites_applied, 2);
        assert_eq!(pr.pass_results.len(), 2);
    }

    #[test]
    fn test_pass_context_test_default() {
        let ctx = PassContext::test_default();
        assert_eq!(ctx.kfunc_registry.rotate64_btf_id, -1);
        assert_eq!(ctx.kfunc_registry.select64_btf_id, -1);
        assert!(!ctx.platform.has_bmi1);
        assert!(ctx.policy.enabled_passes.is_empty());
        assert!(ctx.policy.disabled_passes.is_empty());
    }

    #[test]
    fn test_kfunc_registry_with_available_kfuncs() {
        let ctx = PassContext {
            kfunc_registry: KfuncRegistry {
                rotate64_btf_id: 1234,
                select64_btf_id: -1,
                extract64_btf_id: -1,
                lea64_btf_id: -1,
                movbe64_btf_id: -1,
                module_fd: Some(42),
            },
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig::default(),
        };
        assert!(ctx.kfunc_registry.rotate64_btf_id > 0);
        assert!(ctx.kfunc_registry.select64_btf_id < 0);
        assert_eq!(ctx.kfunc_registry.module_fd, Some(42));
    }

    #[test]
    fn test_pass_manager_pass_count() {
        let mut pm = PassManager::new();
        assert_eq!(pm.pass_count(), 0);
        pm.add_pass(NoOpPass);
        assert_eq!(pm.pass_count(), 1);
        pm.add_pass(AppendNopPass);
        assert_eq!(pm.pass_count(), 2);
    }
}
