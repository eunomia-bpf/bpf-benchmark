// SPDX-License-Identifier: MIT
//! Pass framework — LLVM-style PassManager for BPF program transformations.
//!
//! Core abstractions:
//! - `BpfProgram`: linear instruction stream + per-insn annotations + metadata
//! - `Analysis`: read-only analysis producing typed, cached results
//! - `BpfPass`: transformation pass that may modify the program
//! - `PassManager`: orchestrates pass execution and analysis cache invalidation

use std::any::{Any, TypeId};
use std::collections::{HashMap, HashSet};
use std::sync::Arc;

use serde::Serialize;

use crate::insn::{dump_bytecode_compact, BpfBytecodeDump, BpfInsn, BPF_KINSN_ENC_PACKED_CALL};
use crate::verifier_log::VerifierInsn;

// ── Per-instruction annotation — populated by analysis passes, read by transform passes.
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

#[derive(Clone, Debug, Default)]
pub struct ProfilingData {
    pub branch_profiles: HashMap<usize, BranchProfile>,
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
    /// Transform log: records what each pass did.
    pub transform_log: Vec<TransformEntry>,
    /// Map IDs referenced by this program, in the kernel's `used_maps` order.
    /// This metadata lets analyses resolve `BPF_PSEUDO_MAP_FD` references
    /// found in the original bytecode back to live kernel map objects.
    pub map_ids: Vec<u32>,
    /// Stable `old_fd -> map_id` bindings captured from the original program
    /// before any transform removes or reorders pseudo-map loads.
    pub map_fd_bindings: HashMap<i32, u32>,
    /// Program-level branch miss rate from PMU hardware counters.
    /// Set by `inject_profiling` when PMU data is available.
    /// Consumed by BranchFlipPass to gate optimization.
    pub branch_miss_rate: Option<f64>,
    /// Parsed `log_level=2` verifier state snapshots for the original program.
    pub verifier_states: Arc<[VerifierInsn]>,
    /// Pre-loaded map value snapshot: (map_id, key_bytes) -> value_bytes.
    /// Used by offline snapshot callers and unit tests.
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    /// Pre-loaded map metadata: map_id -> MapMetadata.
    /// Used by offline snapshot callers and unit tests.
    pub map_metadata: HashMap<u32, MapMetadata>,
    /// Map metadata resolver. The daemon installs a live raw-syscall provider;
    /// offline callers use the default snapshot provider.
    pub map_info_provider: Arc<dyn MapInfoProvider>,
    /// Map value resolver. The daemon installs a live raw-syscall provider;
    /// offline callers use the default snapshot provider.
    pub map_value_provider: Arc<dyn MapValueProvider>,
}

/// Pre-loaded map metadata used by snapshot/offline map providers.
#[derive(Clone, Debug)]
pub struct MapMetadata {
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub frozen: bool,
    pub map_id: u32,
}

/// Provider for resolving map metadata from the current execution environment.
pub trait MapInfoProvider: Send + Sync + std::fmt::Debug {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<crate::analysis::MapInfo>, String>;
}

/// Provider for resolving map values from the current execution environment.
pub trait MapValueProvider: Send + Sync + std::fmt::Debug {
    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &crate::analysis::MapInfo,
    ) -> std::result::Result<usize, String>;

    fn lookup_elem(
        &self,
        program: &BpfProgram,
        map_id: u32,
        key: &[u8],
        value_size: usize,
    ) -> std::result::Result<Vec<u8>, String>;
}

/// Snapshot-backed map provider used by offline snapshots and unit tests.
#[derive(Clone, Debug, Default)]
pub struct SnapshotMapProvider;

impl MapInfoProvider for SnapshotMapProvider {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<crate::analysis::MapInfo>, String> {
        let Some(metadata) = program.map_metadata.get(&map_id) else {
            #[cfg(test)]
            {
                return Ok(crate::mock_maps::mock_map_metadata(map_id).map(|metadata| {
                    crate::analysis::MapInfo {
                        map_type: metadata.map_type,
                        key_size: metadata.key_size,
                        value_size: metadata.value_size,
                        max_entries: metadata.max_entries,
                        frozen: metadata.frozen,
                        map_id: metadata.map_id,
                    }
                }));
            }
            #[cfg(not(test))]
            return Ok(None);
        };
        Ok(Some(crate::analysis::MapInfo {
            map_type: metadata.map_type,
            key_size: metadata.key_size,
            value_size: metadata.value_size,
            max_entries: metadata.max_entries,
            frozen: metadata.frozen,
            map_id: metadata.map_id,
        }))
    }
}

impl MapValueProvider for SnapshotMapProvider {
    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &crate::analysis::MapInfo,
    ) -> std::result::Result<usize, String> {
        program
            .map_values
            .iter()
            .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
            .or_else(|| {
                #[cfg(test)]
                {
                    crate::mock_maps::mock_lookup_value_size(info.map_id)
                }
                #[cfg(not(test))]
                {
                    None
                }
            })
            .or(Some(info.value_size as usize))
            .ok_or_else(|| format!("map {} has no value size", info.map_id))
    }

    fn lookup_elem(
        &self,
        program: &BpfProgram,
        map_id: u32,
        key: &[u8],
        value_size: usize,
    ) -> std::result::Result<Vec<u8>, String> {
        if let Some(value) = program.map_values.get(&(map_id, key.to_vec())) {
            if value.len() != value_size {
                return Err(format!(
                    "snapshot map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                ));
            }
            return Ok(value.clone());
        }

        #[cfg(test)]
        if let Some(result) = crate::mock_maps::mock_lookup_elem(map_id, key, value_size) {
            return result;
        }

        let Some(metadata) = program.map_metadata.get(&map_id) else {
            return Err(format!(
                "map_values snapshot has no metadata for map {}",
                map_id
            ));
        };
        zero_filled_snapshot_lookup(metadata, key, value_size)
            .ok_or_else(|| format!("map_values snapshot missing map {} key {:?}", map_id, key))
    }
}

fn zero_filled_snapshot_lookup(
    metadata: &MapMetadata,
    key: &[u8],
    value_size: usize,
) -> Option<Vec<u8>> {
    const BPF_MAP_TYPE_ARRAY: u32 = 2;
    const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = 6;

    if !matches!(
        metadata.map_type,
        BPF_MAP_TYPE_ARRAY | BPF_MAP_TYPE_PERCPU_ARRAY
    ) {
        return None;
    }
    if metadata.key_size as usize != key.len() || key.len() > 8 {
        return None;
    }
    if value_size < metadata.value_size as usize {
        return None;
    }

    let mut raw = [0u8; 8];
    raw[..key.len()].copy_from_slice(key);
    let index = u64::from_le_bytes(raw);
    (index < metadata.max_entries as u64).then_some(vec![0u8; value_size])
}

/// Transform log entry — records sites applied by each pass.
#[derive(Clone, Debug)]
pub struct TransformEntry {
    pub sites_applied: usize,
}

impl BpfProgram {
    /// Create from raw instructions. Annotations are default-initialized.
    pub fn new(insns: Vec<BpfInsn>) -> Self {
        let len = insns.len();
        Self {
            insns,
            annotations: vec![InsnAnnotation::default(); len],
            transform_log: Vec::new(),
            map_ids: Vec::new(),
            map_fd_bindings: HashMap::new(),
            branch_miss_rate: None,
            verifier_states: Arc::from([]),
            map_values: HashMap::new(),
            map_metadata: HashMap::new(),
            map_info_provider: Arc::new(SnapshotMapProvider),
            map_value_provider: Arc::new(SnapshotMapProvider),
        }
    }

    /// Install map providers for live runtime or specialized test execution.
    pub fn set_map_providers(
        &mut self,
        map_info_provider: Arc<dyn MapInfoProvider>,
        map_value_provider: Arc<dyn MapValueProvider>,
    ) {
        self.map_info_provider = map_info_provider;
        self.map_value_provider = map_value_provider;
    }

    /// Attach live-kernel map IDs to this program.
    pub fn set_map_ids(&mut self, map_ids: Vec<u32>) {
        self.map_fd_bindings = build_map_fd_bindings(&self.insns, &map_ids);
        self.map_ids = map_ids;
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

    /// Attach parsed verifier states to this program.
    pub fn set_verifier_states(&mut self, states: Vec<VerifierInsn>) {
        self.verifier_states = Arc::from(states);
    }

    /// Parse and attach a raw verifier log to this program.
    #[cfg(test)]
    pub fn set_verifier_log(&mut self, log: &str) {
        self.set_verifier_states(crate::verifier_log::parse_verifier_log(log));
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

const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;

pub fn build_map_fd_bindings(insns: &[BpfInsn], map_ids: &[u32]) -> HashMap<i32, u32> {
    let mut old_fd_to_map_id = HashMap::new();
    let mut unique_old_fds = Vec::new();

    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_ldimm64() {
            if matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE)
                && !unique_old_fds.contains(&insn.imm)
            {
                unique_old_fds.push(insn.imm);
            }
            pc += 2;
            continue;
        }
        pc += 1;
    }

    for (index, old_fd) in unique_old_fds.into_iter().enumerate() {
        if let Some(&map_id) = map_ids.get(index) {
            old_fd_to_map_id.insert(old_fd, map_id);
        }
    }

    old_fd_to_map_id
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
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn invalidate<R: Any>(&mut self) {
        self.cache.remove(&TypeId::of::<R>());
    }

    /// Check whether a specific analysis result is currently cached.
    #[cfg_attr(not(test), allow(dead_code))]
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
    #[cfg_attr(not(test), allow(dead_code))]
    pub diagnostics: Vec<String>,
    /// Map-inline dependencies produced by this pass.
    pub map_inline_records: Vec<MapInlineRecord>,
    /// Instruction count before this pass ran.
    pub insns_before: usize,
    /// Instruction count after this pass ran.
    pub insns_after: usize,
}

impl PassResult {
    pub fn unchanged(pass_name: impl Into<String>) -> Self {
        Self {
            pass_name: pass_name.into(),
            changed: false,
            sites_applied: 0,
            diagnostics: Vec::new(),
            ..Default::default()
        }
    }

    pub fn skipped(pass_name: impl Into<String>, reason: SkipReason) -> Self {
        Self {
            sites_skipped: vec![reason],
            ..Self::unchanged(pass_name)
        }
    }

    pub fn skipped_with_diagnostics(
        pass_name: impl Into<String>,
        reason: SkipReason,
        diagnostics: Vec<String>,
    ) -> Self {
        Self {
            diagnostics,
            ..Self::skipped(pass_name, reason)
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

/// One specialized map value snapshot emitted by `MapInlinePass`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct MapInlineRecord {
    pub map_id: u32,
    pub key: Vec<u8>,
    pub expected_value: Vec<u8>,
}

/// High-level pass classification used by diagnostics and tests.
#[cfg(test)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PassCategory {
    Optimization,
    Observability,
}

/// Transform pass trait.
///
/// Each optimization is a pass: scan the program, find rewrite sites, apply transforms.
/// Passes can read analysis results through AnalysisCache.
pub trait BpfPass: Send + Sync {
    /// Pass name.
    fn name(&self) -> &str;

    /// High-level classification for this pass.
    #[cfg(test)]
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

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
    /// Available kinsn targets and static metadata.
    pub kinsn_registry: KinsnRegistry,
    /// Resolves CALL.off for kinsn calls introduced by passes.
    pub kinsn_call_resolver: Arc<dyn KinsnCallResolver>,
    /// CPU capabilities (detected at startup, checked by kinsn passes).
    pub platform: PlatformCapabilities,
    /// Policy configuration (which passes are enabled, parameters, etc.).
    pub policy: PolicyConfig,
    /// BPF program type (from `bpf_prog_info.type`).
    /// Used by passes to apply program-type-specific safety filters.
    /// 0 = unspecified (conservative behavior applies).
    pub prog_type: u32,
}

/// Available kinsn targets and static metadata.
/// BTF ID = -1 means the target is not available.
#[derive(Clone, Debug, Default)]
pub struct KinsnRegistry {
    pub rotate64_btf_id: i32,
    pub select64_btf_id: i32,
    pub extract64_btf_id: i32,
    pub memcpy_bulk_btf_id: i32,
    pub memset_bulk_btf_id: i32,
    pub endian_load16_btf_id: i32,
    pub endian_load32_btf_id: i32,
    pub endian_load64_btf_id: i32,
    /// Per-target static call offsets used by offline callers.
    pub target_call_offsets: HashMap<String, i16>,
    /// Per-target supported kinsn encodings.
    /// Tests that only seed BTF IDs rely on the packed-only fallback below.
    pub target_supported_encodings: HashMap<String, u32>,
}

impl KinsnRegistry {
    pub fn target_name_for_pass(pass_name: &str) -> Option<&'static str> {
        match pass_name {
            "rotate" => Some("bpf_rotate64"),
            "cond_select" => Some("bpf_select64"),
            "extract" => Some("bpf_extract64"),
            "endian_fusion" => Some("bpf_endian_load32"),
            _ => None,
        }
    }

    pub fn btf_id_for_target_name(&self, target_name: &str) -> i32 {
        match target_name {
            "bpf_rotate64" => self.rotate64_btf_id,
            "bpf_select64" => self.select64_btf_id,
            "bpf_extract64" => self.extract64_btf_id,
            "bpf_memcpy_bulk" => self.memcpy_bulk_btf_id,
            "bpf_memset_bulk" => self.memset_bulk_btf_id,
            "bpf_endian_load16" => self.endian_load16_btf_id,
            "bpf_endian_load32" => self.endian_load32_btf_id,
            "bpf_endian_load64" => self.endian_load64_btf_id,
            _ => -1,
        }
    }

    pub fn call_off_for_target_name(&self, target_name: &str) -> i16 {
        self.target_call_offsets
            .get(target_name)
            .copied()
            .unwrap_or(0)
    }

    /// Return the encoded call offset for a given pass's kinsn target.
    pub fn call_off_for_pass(&self, pass_name: &str) -> i16 {
        Self::target_name_for_pass(pass_name)
            .map(|target_name| self.call_off_for_target_name(target_name))
            .unwrap_or(0)
    }

    pub fn supported_encodings_for_target_name(&self, target_name: &str) -> u32 {
        self.target_supported_encodings
            .get(target_name)
            .copied()
            .or_else(|| {
                if self.btf_id_for_target_name(target_name) >= 0 {
                    Some(BPF_KINSN_ENC_PACKED_CALL)
                } else {
                    None
                }
            })
            .unwrap_or(0)
    }

    pub fn supported_encodings_for_pass(&self, pass_name: &str) -> u32 {
        Self::target_name_for_pass(pass_name)
            .map(|name| self.supported_encodings_for_target_name(name))
            .unwrap_or(0)
    }

    pub fn packed_supported_for_pass(&self, pass_name: &str) -> bool {
        (self.supported_encodings_for_pass(pass_name) & BPF_KINSN_ENC_PACKED_CALL) != 0
    }

    pub fn packed_supported_for_target_name(&self, target_name: &str) -> bool {
        (self.supported_encodings_for_target_name(target_name) & BPF_KINSN_ENC_PACKED_CALL) != 0
    }
}

/// Adapter for encoding kinsn CALL.off in different execution modes.
pub trait KinsnCallResolver: Send + Sync + std::fmt::Debug {
    fn call_off_for_target_name(
        &self,
        registry: &KinsnRegistry,
        target_name: &str,
    ) -> anyhow::Result<i16>;

    fn call_off_for_pass(&self, registry: &KinsnRegistry, pass_name: &str) -> anyhow::Result<i16> {
        match KinsnRegistry::target_name_for_pass(pass_name) {
            Some(target_name) => self.call_off_for_target_name(registry, target_name),
            None => Ok(0),
        }
    }
}

/// Offline resolver: CALL.off comes from precomputed target metadata.
#[derive(Clone, Debug, Default)]
pub struct StaticKinsnCallResolver;

impl KinsnCallResolver for StaticKinsnCallResolver {
    fn call_off_for_target_name(
        &self,
        registry: &KinsnRegistry,
        target_name: &str,
    ) -> anyhow::Result<i16> {
        Ok(registry.call_off_for_target_name(target_name))
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
    #[cfg_attr(not(target_arch = "aarch64"), allow(dead_code))]
    Aarch64,
}

/// Optimization policy configuration.
#[derive(Clone, Debug, Default)]
pub struct PolicyConfig {
    /// Enabled pass name list.
    pub enabled_passes: Vec<String>,
    /// Disabled pass name list.
    pub disabled_passes: Vec<String>,
}

pub fn default_enabled_passes() -> Vec<String> {
    crate::passes::PASS_REGISTRY
        .iter()
        .map(|entry| entry.name.to_string())
        .collect()
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

#[derive(Clone, Debug, Serialize)]
pub struct PassDebugTrace {
    pub pass_name: String,
    pub changed: bool,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub bytecode_before: Option<BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub bytecode_after: Option<BpfBytecodeDump>,
}

/// Pipeline execution result.
#[derive(Clone, Debug)]
pub struct PipelineResult {
    pub pass_results: Vec<PassResult>,
    pub total_sites_applied: usize,
    pub program_changed: bool,
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

pub const CONST_PROP_DCE_FIXED_POINT_MAX_ITERS: usize = 5;

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

    /// Return a pass by pipeline index.
    pub fn pass_at(&self, index: usize) -> Option<&dyn BpfPass> {
        self.passes.get(index).map(|pass| pass.as_ref())
    }

    /// Return whether a pass is enabled by the current policy.
    pub fn pass_allowed(&self, pass: &dyn BpfPass, ctx: &PassContext) -> anyhow::Result<bool> {
        let available_passes = self.available_pass_names();
        pass_allowed(pass, ctx, &available_passes)
    }

    /// Precompute analyses declared by a pass.
    pub fn run_required_analyses(
        &self,
        pass: &dyn BpfPass,
        program: &BpfProgram,
        cache: &mut AnalysisCache,
    ) {
        for analysis_name in pass.required_analyses() {
            if let Some(analysis) = self.analyses.registry.get(analysis_name) {
                analysis.run_and_cache(program, cache);
            }
        }
    }

    fn available_pass_names(&self) -> HashSet<&str> {
        self.passes
            .iter()
            .map(|pass| pass.name())
            .chain(crate::passes::PASS_REGISTRY.iter().map(|entry| entry.name))
            .collect::<HashSet<_>>()
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
        let mut pass_idx = 0usize;

        while pass_idx < self.passes.len() {
            let pass = self.passes[pass_idx].as_ref();
            if !self.pass_allowed(pass, ctx)? {
                pass_idx += 1;
                continue;
            }

            let has_fixed_point_pair = pass.name() == "const_prop"
                && pass_idx + 1 < self.passes.len()
                && self.passes[pass_idx + 1].name() == "dce"
                && self.pass_allowed(self.passes[pass_idx + 1].as_ref(), ctx)?;

            if has_fixed_point_pair {
                for _ in 0..CONST_PROP_DCE_FIXED_POINT_MAX_ITERS {
                    let const_result =
                        self.run_single_pass(pass, program, &mut cache, ctx, &mut debug_traces)?;
                    if const_result.changed {
                        total_sites += const_result.sites_applied;
                    }
                    any_changed |= const_result.changed;

                    let dce_result = self.run_single_pass(
                        self.passes[pass_idx + 1].as_ref(),
                        program,
                        &mut cache,
                        ctx,
                        &mut debug_traces,
                    )?;
                    if dce_result.changed {
                        total_sites += dce_result.sites_applied;
                    }
                    any_changed |= dce_result.changed;

                    let pair_changed = const_result.changed || dce_result.changed;
                    pass_results.push(const_result);
                    pass_results.push(dce_result);

                    if !pair_changed {
                        break;
                    }
                }

                pass_idx += 2;
                continue;
            }

            let result = self.run_single_pass(pass, program, &mut cache, ctx, &mut debug_traces)?;
            if result.changed {
                total_sites += result.sites_applied;
            }
            any_changed |= result.changed;
            pass_results.push(result);
            pass_idx += 1;
        }

        Ok(PipelineResult {
            pass_results,
            total_sites_applied: total_sites,
            program_changed: any_changed,
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

    fn run_single_pass(
        &self,
        pass: &dyn BpfPass,
        program: &mut BpfProgram,
        cache: &mut AnalysisCache,
        ctx: &PassContext,
        debug_traces: &mut Vec<PassDebugTrace>,
    ) -> anyhow::Result<PassResult> {
        self.run_required_analyses(pass, program, cache);
        let before_insns = program.insns.clone();
        let insns_before = before_insns.len();
        let mut result = pass.run(program, cache, ctx)?;
        result.insns_before = insns_before;
        result.insns_after = program.insns.len();

        if result.changed {
            debug_traces.push(PassDebugTrace {
                pass_name: result.pass_name.clone(),
                changed: true,
                bytecode_before: Some(dump_bytecode_compact(&before_insns)),
                bytecode_after: Some(dump_bytecode_compact(&program.insns)),
            });
            cache.invalidate_all();
            program.sync_annotations();
        } else {
            debug_traces.push(PassDebugTrace {
                pass_name: result.pass_name.clone(),
                changed: false,
                bytecode_before: None,
                bytecode_after: None,
            });
        }

        Ok(result)
    }
}

fn pass_allowed(
    pass: &dyn BpfPass,
    ctx: &PassContext,
    available_passes: &HashSet<&str>,
) -> anyhow::Result<bool> {
    validate_policy_pass_names(
        "enabled_passes",
        &ctx.policy.enabled_passes,
        available_passes,
    )?;
    validate_policy_pass_names(
        "disabled_passes",
        &ctx.policy.disabled_passes,
        available_passes,
    )?;

    if !ctx.policy.disabled_passes.is_empty()
        && ctx
            .policy
            .disabled_passes
            .contains(&pass.name().to_string())
    {
        return Ok(false);
    }

    Ok(ctx
        .policy
        .enabled_passes
        .iter()
        .any(|name| name == pass.name()))
}

fn validate_policy_pass_names(
    field: &str,
    configured: &[String],
    available_passes: &HashSet<&str>,
) -> anyhow::Result<()> {
    let mut unknown = configured
        .iter()
        .filter(|name| !available_passes.contains(name.as_str()))
        .cloned()
        .collect::<Vec<_>>();
    unknown.sort();
    unknown.dedup();
    if unknown.is_empty() {
        return Ok(());
    }
    anyhow::bail!(
        "invalid {field}: unknown pass name(s): {}",
        unknown.join(", ")
    );
}

// ── Helper: default PassContext for testing ──────────────────────────

impl Default for PassContext {
    fn default() -> Self {
        Self {
            kinsn_registry: KinsnRegistry::default(),
            kinsn_call_resolver: Arc::new(StaticKinsnCallResolver),
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig {
                enabled_passes: default_enabled_passes(),
                ..PolicyConfig::default()
            },
            prog_type: 0,
        }
    }
}

impl PassContext {
    /// Create a minimal PassContext suitable for testing.
    /// All kinsn targets unavailable (btf_id = -1), no special CPU features.
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn test_default() -> Self {
        Self {
            kinsn_registry: KinsnRegistry {
                rotate64_btf_id: -1,
                select64_btf_id: -1,
                extract64_btf_id: -1,
                memcpy_bulk_btf_id: -1,
                memset_bulk_btf_id: -1,
                endian_load16_btf_id: -1,
                endian_load32_btf_id: -1,
                endian_load64_btf_id: -1,
                target_call_offsets: HashMap::new(),
                target_supported_encodings: HashMap::new(),
            },
            kinsn_call_resolver: Arc::new(StaticKinsnCallResolver),
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig {
                enabled_passes: default_enabled_passes(),
                ..PolicyConfig::default()
            },
            prog_type: 0,
        }
    }
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
#[path = "pass_tests.rs"]
mod tests;
