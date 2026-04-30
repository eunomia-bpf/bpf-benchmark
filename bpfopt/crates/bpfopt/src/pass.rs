// SPDX-License-Identifier: MIT
//! Pass framework — LLVM-style PassManager for BPF program transformations.
//!
//! Core abstractions:
//! - `BpfProgram`: linear instruction stream + metadata
//! - `Analysis`: read-only analysis producing typed, cached results
//! - `BpfPass`: transformation pass that may modify the program
//! - `PassManager`: orchestrates pass execution and analysis cache invalidation

use std::any::{Any, TypeId};
use std::collections::{HashMap, HashSet};
use std::sync::Arc;

use serde::Serialize;

use crate::insn::{dump_bytecode_compact, BpfBytecodeDump, BpfInsn, BPF_KINSN_ENC_PACKED_CALL};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum VerifierInsnKind {
    EdgeFullState,
    PcFullState,
    InsnDeltaState,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum VerifierValueWidth {
    Unknown,
    Bits32,
    Bits64,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct Tnum {
    pub value: u64,
    pub mask: u64,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct ScalarRange {
    pub smin: Option<i64>,
    pub smax: Option<i64>,
    pub umin: Option<u64>,
    pub umax: Option<u64>,
    pub smin32: Option<i32>,
    pub smax32: Option<i32>,
    pub umin32: Option<u32>,
    pub umax32: Option<u32>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct VerifierInsn {
    pub pc: usize,
    pub frame: usize,
    pub from_pc: Option<usize>,
    pub kind: VerifierInsnKind,
    pub speculative: bool,
    pub regs: HashMap<u8, RegState>,
    pub stack: HashMap<i16, StackState>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct RegState {
    pub reg_type: String,
    pub value_width: VerifierValueWidth,
    pub precise: bool,
    pub exact_value: Option<u64>,
    pub tnum: Option<Tnum>,
    pub range: ScalarRange,
    pub offset: Option<i32>,
    pub id: Option<u32>,
}

impl RegState {
    pub fn exact_u64(&self) -> Option<u64> {
        if self.reg_type != "scalar" {
            return None;
        }

        match self.value_width {
            VerifierValueWidth::Bits32 => None,
            VerifierValueWidth::Bits64 | VerifierValueWidth::Unknown => self.exact_value,
        }
    }

    pub fn exact_u32(&self) -> Option<u32> {
        if self.reg_type != "scalar" {
            return None;
        }

        self.exact_value.map(|value| value as u32)
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct StackState {
    pub slot_types: Option<String>,
    pub value: Option<RegState>,
}

/// Raw BTF func_info or line_info records whose first u32 is `insn_off`.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct BtfInfoRecords {
    pub rec_size: u32,
    pub bytes: Vec<u8>,
}

impl BtfInfoRecords {
    pub fn new(label: &str, rec_size: u32, bytes: Vec<u8>) -> anyhow::Result<Self> {
        if rec_size < std::mem::size_of::<u32>() as u32 {
            anyhow::bail!("{label} rec_size {rec_size} is too small to hold insn_off");
        }
        if !bytes.len().is_multiple_of(rec_size as usize) {
            anyhow::bail!(
                "{label} byte length {} is not a multiple of rec_size {rec_size}",
                bytes.len()
            );
        }
        Ok(Self { rec_size, bytes })
    }
}

// ── Program IR ──────────────────────────────────────────────────────

/// BPF program IR — linear instruction stream + metadata.
///
/// This is the core data structure operated on by all passes. Transform passes
/// modify `insns`; analysis passes populate the analysis cache.
#[derive(Clone)]
pub struct BpfProgram {
    /// Instruction stream (mutable — transform passes modify this).
    pub insns: Vec<BpfInsn>,
    /// Transform log: records what each pass did.
    pub transform_log: Vec<TransformEntry>,
    /// Map IDs referenced by this program, in the kernel's `used_maps` order.
    /// This metadata lets analyses resolve `BPF_PSEUDO_MAP_FD` references
    /// found in the original bytecode back to live kernel map objects.
    pub map_ids: Vec<u32>,
    /// Stable `old_fd -> map_id` bindings captured from the original program
    /// before any transform removes or reorders pseudo-map loads.
    pub map_fd_bindings: HashMap<i32, u32>,
    /// Parsed `log_level=2` verifier state snapshots for the original program.
    pub verifier_states: Arc<[VerifierInsn]>,
    /// Raw func_info records replayed by bpfverify after bytecode transforms.
    pub func_info: Option<BtfInfoRecords>,
    /// Raw line_info records replayed by bpfverify after bytecode transforms.
    pub line_info: Option<BtfInfoRecords>,
    /// Pre-loaded map value snapshot: (map_id, key_bytes) -> value_bytes.
    /// Used by offline snapshot callers and unit tests.
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    /// Explicit lookup misses from map-values.json: (map_id, key_bytes).
    pub map_value_nulls: HashSet<(u32, Vec<u8>)>,
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

/// Snapshot-backed map provider used by offline snapshots.
#[derive(Clone, Debug, Default)]
pub struct SnapshotMapProvider;

impl MapInfoProvider for SnapshotMapProvider {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<crate::analysis::MapInfo>, String> {
        let Some(metadata) = program.map_metadata.get(&map_id) else {
            return Err(format!(
                "map_values snapshot has no metadata for map {}",
                map_id
            ));
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
        if let Some(value_size) = program
            .map_values
            .iter()
            .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
        {
            return Ok(value_size);
        }

        Ok(info.value_size as usize)
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
        if program.map_value_nulls.contains(&(map_id, key.to_vec())) {
            return Err(null_map_value_snapshot_message(map_id, key));
        }

        if !program.map_metadata.contains_key(&map_id) {
            return Err(format!(
                "map_values snapshot has no metadata for map {}",
                map_id
            ));
        }
        Err(missing_map_value_snapshot_message(map_id, key))
    }
}

pub fn missing_map_value_snapshot_message(map_id: u32, key: &[u8]) -> String {
    format!(
        "map_values snapshot missing map {} key {}",
        map_id,
        hex_bytes(key)
    )
}

pub fn null_map_value_snapshot_message(map_id: u32, key: &[u8]) -> String {
    format!(
        "map_values snapshot has explicit null for map {} key {}",
        map_id,
        hex_bytes(key)
    )
}

pub fn is_missing_map_value_snapshot_error(message: &str) -> bool {
    message.contains("map_values snapshot missing map ")
}

pub fn is_null_map_value_snapshot_error(message: &str) -> bool {
    message.contains("map_values snapshot has explicit null for map ")
}

fn hex_bytes(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push(HEX[(byte >> 4) as usize] as char);
        out.push(HEX[(byte & 0x0f) as usize] as char);
    }
    out
}

/// Transform log entry — records sites applied by each pass.
#[derive(Clone, Debug)]
pub struct TransformEntry {
    pub sites_applied: usize,
}

impl BpfProgram {
    /// Create from raw instructions.
    pub fn new(insns: Vec<BpfInsn>) -> Self {
        Self {
            insns,
            transform_log: Vec::new(),
            map_ids: Vec::new(),
            map_fd_bindings: HashMap::new(),
            verifier_states: Arc::from([]),
            func_info: None,
            line_info: None,
            map_values: HashMap::new(),
            map_value_nulls: HashSet::new(),
            map_metadata: HashMap::new(),
            map_info_provider: Arc::new(SnapshotMapProvider),
            map_value_provider: Arc::new(SnapshotMapProvider),
        }
    }

    pub fn has_null_map_value_snapshot(&self, map_id: u32, key: &[u8]) -> bool {
        self.map_value_nulls.contains(&(map_id, key.to_vec()))
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

    /// Attach parsed verifier states to this program.
    pub fn set_verifier_states(&mut self, states: Vec<VerifierInsn>) {
        self.verifier_states = Arc::from(states);
    }

    /// Record a transform operation.
    pub fn log_transform(&mut self, entry: TransformEntry) {
        self.transform_log.push(entry);
    }

    /// Whether any transforms have been applied.
    #[cfg(test)]
    pub fn has_transforms(&self) -> bool {
        self.transform_log.iter().any(|e| e.sites_applied > 0)
    }
}

const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;

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

impl Default for AnalysisCache {
    fn default() -> Self {
        Self::new()
    }
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
    #[cfg(test)]
    pub fn invalidate<R: Any>(&mut self) {
        self.cache.remove(&TypeId::of::<R>());
    }

    /// Check whether a specific analysis result is currently cached.
    #[cfg(test)]
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

    pub(crate) fn supported_encodings_for_pass(&self, pass_name: &str) -> u32 {
        Self::target_name_for_pass(pass_name)
            .map(|name| self.supported_encodings_for_target_name(name))
            .unwrap_or(0)
    }

    pub(crate) fn packed_supported_for_pass(&self, pass_name: &str) -> bool {
        (self.supported_encodings_for_pass(pass_name) & BPF_KINSN_ENC_PACKED_CALL) != 0
    }

    pub(crate) fn packed_supported_for_target_name(&self, target_name: &str) -> bool {
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
    /// Deterministic platform capability set for tests.
    pub fn test_default() -> Self {
        Self {
            #[cfg(target_arch = "aarch64")]
            arch: Arch::Aarch64,
            #[cfg(not(target_arch = "aarch64"))]
            arch: Arch::X86_64,
            ..Default::default()
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
pub struct PolicyConfig {
    /// Enabled pass name list.
    pub enabled_passes: Vec<String>,
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

impl Default for AnalysisRegistry {
    fn default() -> Self {
        Self::new()
    }
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

impl Default for PassManager {
    fn default() -> Self {
        Self::new()
    }
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
    #[cfg(test)]
    pub fn add_pass<P: BpfPass + 'static>(&mut self, pass: P) {
        self.passes.push(Box::new(pass));
    }

    /// Add a pre-boxed pass to the end of the pipeline.
    pub fn add_pass_boxed(&mut self, pass: Box<dyn BpfPass>) {
        self.passes.push(pass);
    }

    /// Return the names of all registered passes in pipeline order.
    #[cfg(test)]
    pub fn pass_names(&self) -> Vec<&str> {
        self.passes.iter().map(|p| p.name()).collect()
    }

    /// Return whether a pass is enabled by the current policy.
    fn pass_allowed(&self, pass: &dyn BpfPass, ctx: &PassContext) -> anyhow::Result<bool> {
        let available_passes = self.available_pass_names();
        validate_policy_pass_names(
            "enabled_passes",
            &ctx.policy.enabled_passes,
            &available_passes,
        )?;

        Ok(ctx
            .policy
            .enabled_passes
            .iter()
            .any(|name| name == pass.name()))
    }

    /// Precompute analyses declared by a pass.
    fn run_required_analyses(
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
        for pass in &self.passes {
            let pass = pass.as_ref();
            if !self.pass_allowed(pass, ctx)? {
                continue;
            }

            let result = self.run_single_pass(pass, program, &mut cache, ctx, &mut debug_traces)?;
            if result.changed {
                total_sites += result.sites_applied;
            }
            any_changed |= result.changed;
            pass_results.push(result);
        }

        Ok(PipelineResult {
            pass_results,
            total_sites_applied: total_sites,
            program_changed: any_changed,
            debug_traces,
        })
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
            program.verifier_states = Arc::from([]);
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
            },
            prog_type: 0,
        }
    }
}

impl PassContext {
    /// Create a minimal PassContext suitable for testing.
    /// All kinsn targets unavailable (btf_id = -1), no special CPU features.
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
            },
            prog_type: 0,
        }
    }
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
#[path = "pass_tests.rs"]
mod tests;
