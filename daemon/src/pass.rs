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

use serde::Serialize;

use crate::insn::{dump_bytecode, BpfBytecodeDump, BpfInsn, BPF_KINSN_ENC_PACKED_CALL};

// ── Program metadata ────────────────────────────────────────────────

/// Program provenance metadata, obtained from BPF_OBJ_GET_INFO_BY_FD.
///
/// Fields are populated from kernel info and consumed by passes/profiler.
/// The compiler flags them as "never read" because the binary writes but
/// does not read them directly -- they flow through the pipeline.
#[derive(Clone, Debug, Default)]
#[allow(dead_code)]
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
    /// PGO: branch taken/not-taken counts at this instruction.
    /// Used by BranchFlipPass to decide whether to flip.
    pub branch_profile: Option<BranchProfile>,
}

/// PGO branch statistics.
#[derive(Clone, Debug)]
pub struct BranchProfile {
    pub taken_count: u64,
    pub not_taken_count: u64,
}

/// Profiling data that can be injected into the pass pipeline.
///
/// Maps instruction PCs to branch profiles. Consumed by PGO-guided passes
/// like BranchFlipPass. When provided to `PassManager::run_with_profiling`,
/// the data is injected into the program's annotations before pass execution.
///
/// `program_hotness` provides program-level activity metrics from the profiler.
/// `branch_profiles` provides per-PC branch taken/not-taken counts (when available).
#[derive(Clone, Debug, Default)]
pub struct ProfilingData {
    /// Per-PC branch profiles.
    pub branch_profiles: HashMap<usize, BranchProfile>,
    /// Program-level hotness from the profiler (run_cnt/run_time_ns deltas).
    /// Future passes can use this to gate optimization on hot programs.
    #[allow(dead_code)]
    pub program_hotness: Option<crate::profiler::PgoAnalysis>,
    /// Program-level branch miss rate from PMU hardware counters.
    /// Computed as branch_misses / branch_instructions during the observation window.
    /// None if PMU counters are unavailable (e.g., no hardware PMU in VM).
    pub branch_miss_rate: Option<f64>,
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
    /// Program metadata (populated from kernel, read by passes/profiler).
    #[allow(dead_code)]
    pub meta: ProgMeta,
    /// Transform log: records what each pass did.
    pub transform_log: Vec<TransformEntry>,
    /// Module FDs required by kfunc calls introduced during rewrite.
    /// Used by cmd_apply to construct fd_array for BPF_PROG_REJIT.
    pub required_module_fds: Vec<i32>,
    /// Program-level branch miss rate from PMU hardware counters.
    /// Set by `inject_profiling` when PMU data is available.
    /// Consumed by BranchFlipPass to gate optimization.
    pub branch_miss_rate: Option<f64>,
}

/// Transform log entry. Fields are written by passes and consumed by
/// `has_transforms()` and diagnostic output. The compiler flags them
/// as unread because only `sites_applied` is read in the binary itself.
#[derive(Clone, Debug)]
#[allow(dead_code)]
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
            required_module_fds: Vec::new(),
            branch_miss_rate: None,
        }
    }

    /// Resynchronize annotations length after instruction stream changes.
    /// Transform passes must call this after modifying insns.
    pub fn sync_annotations(&mut self) {
        self.annotations
            .resize_with(self.insns.len(), InsnAnnotation::default);
    }

    /// Remap annotations using an address map (old_pc -> new_pc).
    ///
    /// After a transform pass changes instruction count, annotations from the
    /// old program need to be remapped to their new positions. The addr_map
    /// must have length >= old_annotations_len, where addr_map[old_pc] gives
    /// the new_pc for that instruction. Annotations for old PCs that map to
    /// valid new PCs are placed at the new location; all other positions get
    /// default annotations.
    pub fn remap_annotations(&mut self, addr_map: &[usize]) {
        let new_len = self.insns.len();
        let old_annotations = std::mem::take(&mut self.annotations);
        let mut new_annotations = vec![InsnAnnotation::default(); new_len];

        for (old_pc, ann) in old_annotations.into_iter().enumerate() {
            // Skip default annotations (nothing to remap).
            if ann.branch_profile.is_none() {
                continue;
            }
            if old_pc < addr_map.len() {
                let new_pc = addr_map[old_pc];
                if new_pc < new_len {
                    new_annotations[new_pc] = ann;
                }
            }
        }

        self.annotations = new_annotations;
    }

    /// Inject profiling data into annotations.
    ///
    /// For each PC in the profiling data that is within bounds, sets the
    /// corresponding annotation's branch_profile.
    pub fn inject_profiling(&mut self, data: &ProfilingData) {
        for (&pc, profile) in &data.branch_profiles {
            if pc < self.annotations.len() {
                self.annotations[pc].branch_profile = Some(profile.clone());
            }
        }
        // Propagate program-level PMU branch miss rate.
        if data.branch_miss_rate.is_some() {
            self.branch_miss_rate = data.branch_miss_rate;
        }
    }

    /// Record a transform operation.
    pub fn log_transform(&mut self, entry: TransformEntry) {
        self.transform_log.push(entry);
    }

    /// Whether any transforms have been applied (used by tests and diagnostic tools).
    #[allow(dead_code)]
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
#[derive(Clone, Debug, Default)]
pub struct PassResult {
    /// Pass name.
    pub pass_name: String,
    /// Whether the program was modified (triggers analysis invalidation).
    pub changed: bool,
    /// Number of sites applied.
    pub sites_applied: usize,
    /// Sites that were skipped (with reasons).
    pub sites_skipped: Vec<SkipReason>,
    /// Diagnostic messages (read by tests and debug output).
    #[allow(dead_code)]
    pub diagnostics: Vec<String>,
    /// Instruction count before this pass ran.
    pub insns_before: usize,
    /// Instruction count after this pass ran.
    pub insns_after: usize,
}

impl PassResult {
    /// Construct a PassResult with insns_before/insns_after defaulting to 0.
    ///
    /// The PassManager overwrites insns_before/insns_after after each pass runs,
    /// so passes themselves don't need to track those values.
    pub fn new(
        pass_name: String,
        changed: bool,
        sites_applied: usize,
        sites_skipped: Vec<SkipReason>,
        diagnostics: Vec<String>,
    ) -> Self {
        Self {
            pass_name,
            changed,
            sites_applied,
            sites_skipped,
            diagnostics,
            insns_before: 0,
            insns_after: 0,
        }
    }

    /// Aggregate skip reasons into a reason -> count map.
    pub fn skip_reason_counts(&self) -> HashMap<String, usize> {
        let mut counts: HashMap<String, usize> = HashMap::new();
        for skip in &self.sites_skipped {
            *counts.entry(skip.reason.clone()).or_insert(0) += 1;
        }
        counts
    }
}

#[derive(Clone, Debug)]
pub struct SkipReason {
    pub pc: usize,
    pub reason: String,
}

/// Pass category — used by the BpfPass trait and read by tests.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
#[allow(dead_code)]
pub enum PassCategory {
    /// Performance optimization.
    Optimization,
    /// Security hardening.
    Security,
    /// Observability enhancement.
    Observability,
    /// Placeholder / experimental pass (not production-ready).
    Placeholder,
}

/// Transform pass trait.
///
/// Each optimization is a pass: scan the program, find rewrite sites, apply transforms.
/// Passes can read analysis results through AnalysisCache.
pub trait BpfPass: Send + Sync {
    /// Pass name.
    fn name(&self) -> &str;

    /// Pass category.
    #[allow(dead_code)]
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
    /// CPU capabilities (detected at startup, checked by kinsn passes).
    pub platform: PlatformCapabilities,
    /// Policy configuration (which passes are enabled, parameters, etc.).
    pub policy: PolicyConfig,
    /// Debug logging configuration.
    pub debug: DebugConfig,
}

#[derive(Clone, Debug, Default)]
pub struct DebugConfig {
    pub enabled: bool,
}

/// Available kfuncs and their BTF IDs.
/// BTF ID = -1 means the kfunc is not available.
#[derive(Clone, Debug, Default)]
#[allow(dead_code)]
pub struct KfuncRegistry {
    pub rotate64_btf_id: i32,
    pub select64_btf_id: i32,
    pub extract64_btf_id: i32,
    pub lea64_btf_id: i32,
    pub movbe64_btf_id: i32,
    pub endian_load16_btf_id: i32,
    pub endian_load32_btf_id: i32,
    pub endian_load64_btf_id: i32,
    pub speculation_barrier_btf_id: i32,
    /// Legacy single module FD (kept for backward compat; prefer per-kfunc FDs).
    pub module_fd: Option<i32>,
    /// Per-kfunc module FDs: maps kfunc name (e.g., "bpf_rotate64") to its
    /// owning module's BTF FD. This allows different kfuncs from different
    /// modules to each contribute their correct FD to the REJIT fd_array.
    pub kfunc_module_fds: HashMap<String, i32>,
    /// Per-kfunc supported kinsn encodings.
    /// Tests that only seed BTF IDs rely on the packed-only fallback below.
    pub kfunc_supported_encodings: HashMap<String, u32>,
}

impl KfuncRegistry {
    fn kfunc_name_for_pass(pass_name: &str) -> Option<&'static str> {
        match pass_name {
            "rotate" => Some("bpf_rotate64"),
            "cond_select" => Some("bpf_select64"),
            "extract" => Some("bpf_extract64"),
            "endian_fusion" => Some("bpf_endian_load32"),
            "speculation_barrier" => Some("bpf_speculation_barrier"),
            _ => None,
        }
    }

    fn btf_id_for_kfunc_name(&self, kfunc_name: &str) -> i32 {
        match kfunc_name {
            "bpf_rotate64" => self.rotate64_btf_id,
            "bpf_select64" => self.select64_btf_id,
            "bpf_extract64" => self.extract64_btf_id,
            "bpf_endian_load16" => self.endian_load16_btf_id,
            "bpf_endian_load32" => self.endian_load32_btf_id,
            "bpf_endian_load64" => self.endian_load64_btf_id,
            "bpf_speculation_barrier" => self.speculation_barrier_btf_id,
            _ => -1,
        }
    }

    /// Return the module FD for a given pass name. Looks up the per-kfunc
    /// module FD first; falls back to the legacy single module_fd.
    pub fn module_fd_for_pass(&self, pass_name: &str) -> Option<i32> {
        let kfunc_name = match Self::kfunc_name_for_pass(pass_name) {
            Some(name) => name,
            None => return self.module_fd,
        };
        self.kfunc_module_fds
            .get(kfunc_name)
            .copied()
            .or(self.module_fd)
    }

    pub fn supported_encodings_for_kfunc_name(&self, kfunc_name: &str) -> u32 {
        self.kfunc_supported_encodings
            .get(kfunc_name)
            .copied()
            .or_else(|| {
                if self.btf_id_for_kfunc_name(kfunc_name) >= 0 {
                    Some(BPF_KINSN_ENC_PACKED_CALL)
                } else {
                    None
                }
            })
            .unwrap_or(0)
    }

    pub fn supported_encodings_for_pass(&self, pass_name: &str) -> u32 {
        Self::kfunc_name_for_pass(pass_name)
            .map(|name| self.supported_encodings_for_kfunc_name(name))
            .unwrap_or(0)
    }

    pub fn packed_supported_for_pass(&self, pass_name: &str) -> bool {
        (self.supported_encodings_for_pass(pass_name) & BPF_KINSN_ENC_PACKED_CALL) != 0
    }

    pub fn packed_supported_for_kfunc_name(&self, kfunc_name: &str) -> bool {
        (self.supported_encodings_for_kfunc_name(kfunc_name) & BPF_KINSN_ENC_PACKED_CALL) != 0
    }

    /// Return all unique module FDs in the registry.
    /// Used by cmd_apply to validate that required_module_fds are a subset.
    pub fn all_module_fds(&self) -> Vec<i32> {
        let mut fds: Vec<i32> = self.kfunc_module_fds.values().copied().collect();
        if let Some(fd) = self.module_fd {
            if !fds.contains(&fd) {
                fds.push(fd);
            }
        }
        fds.sort();
        fds.dedup();
        fds
    }
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

impl PlatformCapabilities {
    /// Detect CPU capabilities for the current platform.
    ///
    /// On x86_64, parses `/proc/cpuinfo` flags to detect BMI1, BMI2, CMOV,
    /// MOVBE, and BMI2 (for RORX). On aarch64, sets arch and basic capabilities.
    pub fn detect() -> Self {
        #[cfg(target_arch = "x86_64")]
        {
            Self::detect_x86_64()
        }
        #[cfg(target_arch = "aarch64")]
        {
            Self {
                // ARM64 always has conditional select (CSEL).
                has_cmov: true,
                arch: Arch::Aarch64,
                ..Default::default()
            }
        }
        #[cfg(not(any(target_arch = "x86_64", target_arch = "aarch64")))]
        {
            Self::default()
        }
    }

    /// Detect x86_64 CPU features by parsing /proc/cpuinfo flags.
    #[cfg(target_arch = "x86_64")]
    fn detect_x86_64() -> Self {
        let flags = match std::fs::read_to_string("/proc/cpuinfo") {
            Ok(content) => {
                // Find the first "flags" line.
                content
                    .lines()
                    .find(|l| l.starts_with("flags"))
                    .unwrap_or("")
                    .to_string()
            }
            Err(_) => String::new(),
        };

        Self {
            has_bmi1: flags.contains(" bmi1"),
            has_bmi2: flags.contains(" bmi2"),
            has_cmov: flags.contains(" cmov"),
            has_movbe: flags.contains(" movbe"),
            // RORX is part of BMI2 instruction set.
            has_rorx: flags.contains(" bmi2"),
            arch: Arch::X86_64,
        }
    }
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum Arch {
    #[default]
    X86_64,
    Aarch64,
}

/// Optimization policy configuration.
#[derive(Clone, Debug, Default)]
#[allow(dead_code)]
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
    fn run_and_cache(&self, program: &BpfProgram, cache: &mut AnalysisCache);
}

/// Blanket impl of AnyAnalysis for all Analysis types.
impl<A: Analysis + 'static> AnyAnalysis for A
where
    A::Result: 'static,
{
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

/// Records which pass is responsible for modifications at a given PC range.
///
/// After the pipeline runs, `transform_attribution` maps each modified PC range
/// back to the pass that created it. Used by the rollback mechanism to attribute
/// verifier failures to specific passes.
#[derive(Clone, Debug)]
pub struct TransformAttribution {
    /// PC range (in the *new* instruction stream) that was produced by a pass.
    pub pc_range: std::ops::Range<usize>,
    /// Name of the pass that produced this range.
    pub pass_name: String,
}

#[derive(Clone, Debug, Serialize)]
pub struct PassDebugTrace {
    pub pass_name: String,
    pub changed: bool,
    pub bytecode_before: BpfBytecodeDump,
    pub bytecode_after: BpfBytecodeDump,
}

/// Pipeline execution result.
#[derive(Clone, Debug)]
pub struct PipelineResult {
    pub pass_results: Vec<PassResult>,
    pub total_sites_applied: usize,
    pub program_changed: bool,
    /// Attribution of PC ranges to passes (populated for rollback support).
    pub attribution: Vec<TransformAttribution>,
    /// Full bytecode dumps around each executed pass, only populated when
    /// debug logging is enabled.
    pub debug_traces: Vec<PassDebugTrace>,
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
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn add_pass<P: BpfPass + 'static>(&mut self, pass: P) {
        self.passes.push(Box::new(pass));
    }

    /// Add a pre-boxed pass to the end of the pipeline.
    pub fn add_pass_boxed(&mut self, pass: Box<dyn BpfPass>) {
        self.passes.push(pass);
    }

    /// Return the number of registered passes.
    #[allow(dead_code)]
    pub fn pass_count(&self) -> usize {
        self.passes.len()
    }

    /// Return the names of all registered passes in pipeline order.
    #[allow(dead_code)]
    pub fn pass_names(&self) -> Vec<&str> {
        self.passes.iter().map(|p| p.name()).collect()
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
        let mut debug_traces = Vec::new();

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
                && !ctx.policy.enabled_passes.contains(&pass.name().to_string())
            {
                continue;
            }

            // Ensure required analyses are computed (skip if already cached).
            for analysis_name in pass.required_analyses() {
                if let Some(analysis) = self.analyses.registry.get(analysis_name) {
                    // The analysis cache's get() method handles caching internally,
                    // but run_and_cache is used for type-erased access. It's a no-op
                    // if the result is already cached.
                    analysis.run_and_cache(program, &mut cache);
                }
            }

            // Record insn count before this pass runs.
            let insns_before = program.insns.len();
            let before_dump = ctx.debug.enabled.then(|| dump_bytecode(&program.insns));

            // Run the pass.
            let mut result = pass.run(program, &mut cache, ctx)?;

            // Fill in insns_before/insns_after from the actual program state.
            result.insns_before = insns_before;
            result.insns_after = program.insns.len();
            let after_dump = ctx.debug.enabled.then(|| dump_bytecode(&program.insns));

            if let (Some(bytecode_before), Some(bytecode_after)) = (before_dump, after_dump) {
                debug_traces.push(PassDebugTrace {
                    pass_name: result.pass_name.clone(),
                    changed: result.changed,
                    bytecode_before,
                    bytecode_after,
                });
            }

            if result.changed {
                // Transform modified the program — invalidate cached analyses.
                // Use targeted invalidation for known analysis types, then
                // clear any remaining entries.
                use crate::analysis::{BranchTargetResult, CFGResult, LivenessResult};
                if cache.is_cached::<BranchTargetResult>() {
                    cache.invalidate::<BranchTargetResult>();
                }
                if cache.is_cached::<CFGResult>() {
                    cache.invalidate::<CFGResult>();
                }
                if cache.is_cached::<LivenessResult>() {
                    cache.invalidate::<LivenessResult>();
                }
                // Clear any other cached analyses that might exist.
                cache.invalidate_all();
                // Synchronize annotations.
                program.sync_annotations();
                any_changed = true;
            }

            total_sites += result.sites_applied;
            pass_results.push(result);
        }

        // Build attribution from pass results. Each pass that applied any sites
        // gets a conservative attribution covering the entire final program range.
        // This is sufficient for rollback: when the verifier rejects at some PC,
        // all passes that made changes are candidates for disabling. The last
        // matching pass (most recently applied) is preferred by the attribution
        // lookup in attribute_verifier_failure().
        let mut attribution = Vec::new();
        for pr in &pass_results {
            if pr.sites_applied > 0 {
                attribution.push(TransformAttribution {
                    pc_range: 0..program.insns.len(),
                    pass_name: pr.pass_name.clone(),
                });
            }
        }

        Ok(PipelineResult {
            pass_results,
            total_sites_applied: total_sites,
            program_changed: any_changed,
            attribution,
            debug_traces,
        })
    }

    /// Execute the pipeline with optional profiling data.
    ///
    /// If `profiling` is provided, injects branch profiles into the program's
    /// annotations before running the pipeline. This enables PGO-guided passes
    /// like BranchFlipPass to make data-driven decisions.
    pub fn run_with_profiling(
        &self,
        program: &mut BpfProgram,
        ctx: &PassContext,
        profiling: Option<&ProfilingData>,
    ) -> anyhow::Result<PipelineResult> {
        if let Some(data) = profiling {
            program.inject_profiling(data);
        }
        self.run(program, ctx)
    }
}

// ── Helper: default PassContext for testing ──────────────────────────

impl PassContext {
    /// Create a minimal PassContext suitable for testing.
    /// All kfuncs unavailable (btf_id = -1), no special CPU features.
    #[allow(dead_code)]
    pub fn test_default() -> Self {
        Self {
            kfunc_registry: KfuncRegistry {
                rotate64_btf_id: -1,
                select64_btf_id: -1,
                extract64_btf_id: -1,
                lea64_btf_id: -1,
                movbe64_btf_id: -1,
                endian_load16_btf_id: -1,
                endian_load32_btf_id: -1,
                endian_load64_btf_id: -1,
                speculation_barrier_btf_id: -1,
                module_fd: None,
                kfunc_module_fds: HashMap::new(),
                kfunc_supported_encodings: HashMap::new(),
            },
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig::default(),
            debug: DebugConfig::default(),
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
            ..Default::default()
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
                    ..Default::default()
                },
                PassResult {
                    pass_name: "b".into(),
                    changed: false,
                    sites_applied: 0,
                    sites_skipped: vec![],
                    diagnostics: vec![],
                    ..Default::default()
                },
            ],
            total_sites_applied: 2,
            program_changed: true,
            attribution: vec![],
            debug_traces: vec![],
        };

        assert!(pr.program_changed);
        assert_eq!(pr.total_sites_applied, 2);
        assert_eq!(pr.pass_results.len(), 2);
    }

    #[test]
    fn test_pass_manager_collects_debug_traces_when_enabled() {
        let mut pm = PassManager::new();
        pm.add_pass(AppendNopPass);

        let mut ctx = PassContext::test_default();
        ctx.debug.enabled = true;

        let mut prog = make_program(vec![exit_insn()]);
        let result = pm
            .run(&mut prog, &ctx)
            .expect("pass manager should succeed");

        assert_eq!(result.debug_traces.len(), 1);
        assert_eq!(result.debug_traces[0].pass_name, "append_nop");
        assert_eq!(result.debug_traces[0].bytecode_before.insn_count, 1);
        assert_eq!(result.debug_traces[0].bytecode_after.insn_count, 2);
    }

    #[test]
    fn test_pass_context_test_default() {
        let ctx = PassContext::test_default();
        assert_eq!(ctx.kfunc_registry.rotate64_btf_id, -1);
        assert_eq!(ctx.kfunc_registry.select64_btf_id, -1);
        assert!(!ctx.platform.has_bmi1);
        assert!(ctx.policy.enabled_passes.is_empty());
        assert!(ctx.policy.disabled_passes.is_empty());
        assert!(!ctx.debug.enabled);
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
                endian_load16_btf_id: -1,
                endian_load32_btf_id: -1,
                endian_load64_btf_id: -1,
                speculation_barrier_btf_id: -1,
                module_fd: Some(42),
                kfunc_module_fds: HashMap::new(),
                kfunc_supported_encodings: HashMap::new(),
            },
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig::default(),
            debug: DebugConfig::default(),
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

    // ── Issue 3: Per-kfunc module FD tests ──────────────────────

    #[test]
    fn test_kfunc_registry_per_kfunc_module_fd() {
        let mut reg = KfuncRegistry {
            rotate64_btf_id: 10,
            select64_btf_id: 20,
            extract64_btf_id: 30,
            lea64_btf_id: -1,
            movbe64_btf_id: -1,
            endian_load16_btf_id: -1,
            endian_load32_btf_id: -1,
            endian_load64_btf_id: -1,
            speculation_barrier_btf_id: -1,
            module_fd: None,
            kfunc_module_fds: HashMap::new(),
            kfunc_supported_encodings: HashMap::new(),
        };
        // Set different FDs for different kfuncs.
        reg.kfunc_module_fds.insert("bpf_rotate64".to_string(), 100);
        reg.kfunc_module_fds.insert("bpf_select64".to_string(), 200);
        reg.kfunc_module_fds
            .insert("bpf_extract64".to_string(), 300);

        // Each pass should get its own module FD.
        assert_eq!(reg.module_fd_for_pass("rotate"), Some(100));
        assert_eq!(reg.module_fd_for_pass("cond_select"), Some(200));
        assert_eq!(reg.module_fd_for_pass("extract"), Some(300));
    }

    #[test]
    fn test_kfunc_registry_per_kfunc_fallback_to_legacy() {
        let mut reg = KfuncRegistry {
            rotate64_btf_id: 10,
            select64_btf_id: -1,
            extract64_btf_id: -1,
            lea64_btf_id: -1,
            movbe64_btf_id: -1,
            endian_load16_btf_id: -1,
            endian_load32_btf_id: -1,
            endian_load64_btf_id: -1,
            speculation_barrier_btf_id: -1,
            module_fd: Some(42), // legacy
            kfunc_module_fds: HashMap::new(),
            kfunc_supported_encodings: HashMap::new(),
        };
        // Only rotate has a per-kfunc FD.
        reg.kfunc_module_fds.insert("bpf_rotate64".to_string(), 100);

        assert_eq!(reg.module_fd_for_pass("rotate"), Some(100));
        // cond_select has no per-kfunc FD, falls back to legacy.
        assert_eq!(reg.module_fd_for_pass("cond_select"), Some(42));
        // Unknown pass falls back to legacy.
        assert_eq!(reg.module_fd_for_pass("unknown"), Some(42));
    }

    #[test]
    fn test_kfunc_registry_all_module_fds() {
        let mut reg = KfuncRegistry {
            rotate64_btf_id: 10,
            select64_btf_id: 20,
            extract64_btf_id: -1,
            lea64_btf_id: -1,
            movbe64_btf_id: -1,
            endian_load16_btf_id: -1,
            endian_load32_btf_id: -1,
            endian_load64_btf_id: -1,
            speculation_barrier_btf_id: -1,
            module_fd: Some(100),
            kfunc_module_fds: HashMap::new(),
            kfunc_supported_encodings: HashMap::new(),
        };
        reg.kfunc_module_fds.insert("bpf_rotate64".to_string(), 100);
        reg.kfunc_module_fds.insert("bpf_select64".to_string(), 200);

        let fds = reg.all_module_fds();
        assert!(fds.contains(&100));
        assert!(fds.contains(&200));
        // 100 appears in both legacy and per-kfunc, but should be deduped.
        assert_eq!(fds.len(), 2);
    }

    #[test]
    fn test_required_module_fds_subset_of_all_module_fds() {
        // Simulate what cmd_apply does: after running passes, required_module_fds
        // should be a subset of registry.all_module_fds().
        let mut reg = KfuncRegistry {
            rotate64_btf_id: 10,
            select64_btf_id: 20,
            extract64_btf_id: -1,
            lea64_btf_id: -1,
            movbe64_btf_id: -1,
            endian_load16_btf_id: -1,
            endian_load32_btf_id: -1,
            endian_load64_btf_id: -1,
            speculation_barrier_btf_id: -1,
            module_fd: None,
            kfunc_module_fds: HashMap::new(),
            kfunc_supported_encodings: HashMap::new(),
        };
        reg.kfunc_module_fds.insert("bpf_rotate64".to_string(), 100);
        reg.kfunc_module_fds.insert("bpf_select64".to_string(), 200);

        let all_fds = reg.all_module_fds();

        // Simulate a program that used rotate and select passes.
        let required: Vec<i32> = vec![100, 200];
        for fd in &required {
            assert!(
                all_fds.contains(fd),
                "required fd {} not in all_module_fds {:?}",
                fd,
                all_fds
            );
        }

        // An unknown FD should fail the subset check.
        assert!(!all_fds.contains(&999));
    }

    // ── Issue 5: Annotation remap tests ─────────────────────────

    #[test]
    fn test_remap_annotations_basic() {
        let mut prog = make_program(vec![
            BpfInsn::nop(),
            BpfInsn::nop(),
            BpfInsn::nop(),
            exit_insn(),
        ]);
        // Set a branch profile on instruction 1.
        prog.annotations[1].branch_profile = Some(BranchProfile {
            taken_count: 100,
            not_taken_count: 50,
        });

        // Simulate a transform that inserts an instruction before pc=1.
        // addr_map: old_pc 0->0, 1->2, 2->3, 3->4, sentinel 4->5
        let new_insns = vec![
            BpfInsn::nop(),
            BpfInsn::nop(), // inserted
            BpfInsn::nop(),
            BpfInsn::nop(),
            exit_insn(),
        ];
        let addr_map = vec![0, 2, 3, 4, 5];
        prog.insns = new_insns;
        prog.remap_annotations(&addr_map);

        // The profile should now be at new_pc=2 (remapped from old_pc=1).
        assert!(prog.annotations[0].branch_profile.is_none());
        assert!(prog.annotations[1].branch_profile.is_none());
        assert!(prog.annotations[2].branch_profile.is_some());
        assert_eq!(
            prog.annotations[2]
                .branch_profile
                .as_ref()
                .unwrap()
                .taken_count,
            100
        );
        assert!(prog.annotations[3].branch_profile.is_none());
        assert!(prog.annotations[4].branch_profile.is_none());
    }

    #[test]
    fn test_remap_annotations_deleted_instruction() {
        let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), exit_insn()]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 10,
            not_taken_count: 5,
        });

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
        pdata.branch_profiles.insert(
            1,
            BranchProfile {
                taken_count: 80,
                not_taken_count: 20,
            },
        );
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
        let jne = BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 2,
            imm: 0,
        };
        let mut prog = make_program(vec![
            jne,                       // pc=0
            BpfInsn::mov64_imm(0, 10), // then
            BpfInsn::ja(1),            // skip else
            BpfInsn::mov64_imm(0, 20), // else
            exit_insn(),
        ]);
        let ctx = PassContext::test_default();

        // Without profiling: no flip.
        let result = pm.run_with_profiling(&mut prog, &ctx, None).unwrap();
        assert!(!result.program_changed, "should not flip without PGO data");

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
        pdata.branch_profiles.insert(
            0,
            BranchProfile {
                taken_count: 90,
                not_taken_count: 10,
            },
        );
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
    fn test_platform_detect_returns_valid_result() {
        let caps = PlatformCapabilities::detect();
        // On any Linux machine, detection should complete without panic.
        // On x86_64, at least some capabilities should be detected.
        #[cfg(target_arch = "x86_64")]
        {
            assert_eq!(caps.arch, Arch::X86_64);
            // Most x86_64 CPUs have CMOV (Pentium Pro+).
            // We don't assert true because of CI variety, but we assert it runs.
        }
        #[cfg(target_arch = "aarch64")]
        {
            assert_eq!(caps.arch, Arch::Aarch64);
            assert!(caps.has_cmov, "ARM64 always has CSEL");
        }
        // Just verify the struct is valid regardless of platform.
        let _ = format!("{:?}", caps);
    }

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

        // Context has select kfunc available but platform lacks CMOV.
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.select64_btf_id = 1234;
        // has_cmov is false by default in test_default().

        let mut prog = make_program(vec![
            BpfInsn {
                code: crate::insn::BPF_JMP | crate::insn::BPF_JNE | crate::insn::BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 2,
                imm: 0,
            },
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

    // ── TransformAttribution tests ──────────────────────────────

    #[test]
    fn test_attribution_populated_after_transform() {
        let mut pm = PassManager::new();
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![exit_insn()]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert!(
            !result.attribution.is_empty(),
            "attribution should be populated after transform"
        );
        assert_eq!(result.attribution[0].pass_name, "append_nop");
    }

    #[test]
    fn test_attribution_empty_when_no_change() {
        let mut pm = PassManager::new();
        pm.add_pass(NoOpPass);

        let mut prog = make_program(vec![exit_insn()]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(!result.program_changed);
        assert!(
            result.attribution.is_empty(),
            "attribution should be empty when no changes"
        );
    }

    #[test]
    fn test_attribution_multiple_passes() {
        let mut pm = PassManager::new();
        pm.add_pass(RewriteMovImmPass { new_imm: 99 });
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.attribution.len(), 2);
        let names: Vec<&str> = result
            .attribution
            .iter()
            .map(|a| a.pass_name.as_str())
            .collect();
        assert!(names.contains(&"rewrite_mov_imm"));
        assert!(names.contains(&"append_nop"));
    }

    #[test]
    fn test_disabled_pass_not_in_attribution() {
        let mut pm = PassManager::new();
        pm.add_pass(RewriteMovImmPass { new_imm: 99 });
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let mut ctx = PassContext::test_default();
        ctx.policy.disabled_passes = vec!["rewrite_mov_imm".into()];

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        // Only append_nop should appear in attribution.
        assert_eq!(result.attribution.len(), 1);
        assert_eq!(result.attribution[0].pass_name, "append_nop");
    }

    #[test]
    fn test_pass_names_method() {
        let mut pm = PassManager::new();
        pm.add_pass(NoOpPass);
        pm.add_pass(AppendNopPass);

        let names = pm.pass_names();
        assert_eq!(names, vec!["noop", "append_nop"]);
    }

    #[test]
    fn test_rollback_via_disabled_passes_policy() {
        // Simulate the rollback mechanism: run with all passes, then disable one
        // and verify the disabled pass is skipped on the second run.
        let mut pm = PassManager::new();
        pm.add_pass(RewriteMovImmPass { new_imm: 99 });
        pm.add_pass(AppendNopPass);

        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let ctx = PassContext::test_default();

        // First run: both passes fire.
        let result1 = pm.run(&mut prog, &ctx).unwrap();
        assert_eq!(result1.attribution.len(), 2);
        assert_eq!(prog.insns[0].imm, 99);
        assert_eq!(prog.insns.len(), 3); // 2 original + 1 NOP

        // Second run: disable rewrite_mov_imm (simulating rollback).
        let mut prog2 = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let mut ctx2 = PassContext::test_default();
        ctx2.policy.disabled_passes = vec!["rewrite_mov_imm".into()];

        let result2 = pm.run(&mut prog2, &ctx2).unwrap();
        assert_eq!(result2.attribution.len(), 1);
        assert_eq!(result2.attribution[0].pass_name, "append_nop");
        // The MOV immediate should NOT be rewritten.
        assert_eq!(prog2.insns[0].imm, 42);
        // But NOP should still be appended.
        assert_eq!(prog2.insns.len(), 3);
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
        let ctx = PassContext::test_default();
        let result = pm.run(&mut prog, &ctx).unwrap();

        assert_eq!(result.pass_results.len(), 1);
        let pr = &result.pass_results[0];
        // Before append_nop: 1 instruction (exit).
        assert_eq!(pr.insns_before, 1);
        // After append_nop: 2 instructions (exit + NOP).
        assert_eq!(pr.insns_after, 2);
    }
}
