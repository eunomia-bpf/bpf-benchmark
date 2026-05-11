// SPDX-License-Identifier: MIT
//! Pass framework for BPF program transformations.
//!
//! Core abstractions:
//! - `BBProgram`: basic-block IR used by production pass execution
//! - `BpfPass`: transformation pass that may modify the program

use std::collections::{HashMap, HashSet};
use std::fmt;
use std::sync::Arc;

use crate::analysis::BBProgram;
use crate::insn::BpfInsn;
#[cfg(test)]
pub use crate::test_helpers::{
    build_map_fd_bindings, BpfProgram, MapProvider, SnapshotMapProvider,
};
// MapInlineHint et al. live in passes/map_inline.rs (pass-local metadata) and are
// re-exported here so existing `use crate::pass::*` consumers keep working.
pub use crate::passes::map_inline::{MapInlineHint, MapInlineHintAnchor, MapInlineHintMode};
pub use crate::verifier_log::{
    RegState, ScalarRange, StackState, Tnum, VerifierInsn, VerifierInsnKind, VerifierValueWidth,
};
use serde::ser::SerializeStruct;
use serde::{Serialize, Serializer};

pub type RegSet = HashSet<u8>;

#[derive(Clone, Copy, Debug)]
pub struct KinsnDescriptor {
    pub canonical_name: &'static str,
    pub aliases: &'static [&'static str],
    pub decode_proof: fn(&[u8]) -> ProofRegion,
    pub register_uses: fn(payload: u64) -> RegSet,
}

impl KinsnDescriptor {
    pub fn probe_aliases(self) -> Vec<&'static str> {
        let bpf_aliases = self
            .aliases
            .iter()
            .copied()
            .filter(|alias| alias.starts_with("bpf_"))
            .collect::<Vec<_>>();
        if bpf_aliases.is_empty() {
            vec![self.canonical_name]
        } else {
            bpf_aliases
        }
    }
}

impl Serialize for KinsnDescriptor {
    fn serialize<S>(&self, serializer: S) -> std::result::Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        let mut state = serializer.serialize_struct("KinsnDescriptor", 2)?;
        state.serialize_field("json_name", self.canonical_name)?;
        state.serialize_field("probe_aliases", &self.probe_aliases())?;
        state.end()
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ProofRegion {
    state: ProofRegionState,
}

#[derive(Clone, Debug, PartialEq, Eq)]
enum ProofRegionState {
    Valid { proof_len: usize },
    Invalid { error: String },
}

impl ProofRegion {
    pub fn valid(proof_len: usize) -> Self {
        Self {
            state: ProofRegionState::Valid { proof_len },
        }
    }

    pub fn invalid(error: impl Into<String>) -> Self {
        Self {
            state: ProofRegionState::Invalid {
                error: error.into(),
            },
        }
    }

    pub fn from_result(result: anyhow::Result<usize>) -> Self {
        match result {
            Ok(proof_len) => Self::valid(proof_len),
            Err(err) => Self::invalid(err.to_string()),
        }
    }

    pub fn proof_len(&self) -> anyhow::Result<usize> {
        match &self.state {
            ProofRegionState::Valid { proof_len } => Ok(*proof_len),
            ProofRegionState::Invalid { error } => anyhow::bail!("{error}"),
        }
    }
}

pub(crate) fn decode_packed_kinsn_payload(payload: &[u8]) -> anyhow::Result<u64> {
    let bytes: [u8; 8] = payload.try_into().map_err(|_| {
        anyhow::anyhow!(
            "kinsn proof payload has length {}, expected 8 bytes",
            payload.len()
        )
    })?;
    Ok(u64::from_le_bytes(bytes))
}

pub(crate) fn kinsn_payload_reg(payload: u64, shift: u8) -> u8 {
    BpfInsn::unpack_u4(payload, shift)
}

pub(crate) fn kinsn_payload_u8(payload: u64, shift: u8) -> u8 {
    BpfInsn::unpack_u8(payload, shift)
}

pub(crate) fn kinsn_payload_s16(payload: u64, shift: u8) -> i16 {
    BpfInsn::unpack_u16(payload, shift) as i16
}

pub(crate) fn validate_bpf_reg(label: &str, reg: u8) -> anyhow::Result<()> {
    if reg > 10 {
        anyhow::bail!("{label} register {reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(())
}

// ── Per-instruction annotation — populated by analysis passes, read by transform passes.
#[derive(Clone, Debug, Default)]
pub struct InsnAnnotation {
    /// PGO: branch taken/not-taken counts at this instruction.
    /// Used by BranchFlipPass to decide whether to flip.
    pub branch_profile: Option<BranchProfile>,
    /// Optional PMU data for prefetch admission.
    /// Used by PrefetchPass to suppress structurally valid but cold sites.
    pub prefetch_profile: Option<PrefetchProfile>,
}

/// Real per-site PMU branch statistics.
#[derive(Clone, Debug)]
pub struct BranchProfile {
    pub branch_count: u64,
    pub branch_misses: u64,
    pub miss_rate: f64,
    pub taken_count: u64,
    pub not_taken_count: u64,
}

/// Real per-site PMU memory statistics for optional prefetch admission.
#[derive(Clone, Debug)]
pub struct PrefetchProfile {
    pub execution_count: u64,
    pub cache_references: u64,
    pub cache_misses: u64,
    pub miss_rate: f64,
}

#[derive(Clone, Debug, Default)]
pub struct ProfilingData {
    pub branch_profiles: HashMap<usize, BranchProfile>,
    pub branch_miss_rate: Option<f64>,
    pub prefetch_profiles: HashMap<usize, PrefetchProfile>,
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

/// Pre-loaded map metadata used by snapshot/offline map providers.
///
/// The pass resolves layout/type information from this metadata. Mutability
/// is derived from bytecode-level writer helpers and map type rules.
#[derive(Clone, Debug)]
pub struct MapMetadata {
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub map_id: u32,
    pub name: String,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct CompressedMapValues {
    pub value_size: usize,
    pub kind: CompressedMapValuesKind,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub enum CompressedMapValuesKind {
    Uniform(Vec<u8>),
    Sparse {
        default: Vec<u8>,
        entries: HashMap<Vec<u8>, Vec<u8>>,
    },
    Enumerated {
        entries: HashMap<Vec<u8>, Vec<u8>>,
    },
}

impl CompressedMapValues {
    pub fn lookup(&self, key: &[u8]) -> Option<Vec<u8>> {
        match &self.kind {
            CompressedMapValuesKind::Uniform(value) => Some(value.clone()),
            CompressedMapValuesKind::Sparse { default, entries } => {
                entries.get(key).cloned().or_else(|| Some(default.clone()))
            }
            CompressedMapValuesKind::Enumerated { entries } => entries.get(key).cloned(),
        }
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub enum MapLookupError {
    MissingKey { map_id: u32, key: Vec<u8> },
    SkippedBySize { map_id: u32 },
    Failed(String),
}

impl fmt::Display for MapLookupError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            MapLookupError::MissingKey { map_id, key } => {
                write!(
                    f,
                    "map_values snapshot missing map {} key {}",
                    map_id,
                    hex_bytes(key)
                )
            }
            MapLookupError::SkippedBySize { map_id } => {
                write!(f, "map_values snapshot skipped map {} by size", map_id)
            }
            MapLookupError::Failed(message) => f.write_str(message),
        }
    }
}

impl std::error::Error for MapLookupError {}

fn hex_bytes(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push(HEX[(byte >> 4) as usize] as char);
        out.push(HEX[(byte & 0x0f) as usize] as char);
    }
    out
}

// ── BpfPass trait ───────────────────────────────────────────────────

/// Pass execution result.
#[derive(Clone, Debug, Default)]
pub struct PassResult {
    /// Number of sites applied.
    pub sites_applied: usize,
    /// Sites that were skipped (with reasons).
    pub sites_skipped: Vec<SkipReason>,
    /// Diagnostic messages (read by tests and debug output).
    pub diagnostics: Vec<String>,
    /// Map-inline sites produced by this pass.
    pub map_inline_records: Vec<MapInlineRecord>,
    /// Instruction count before this pass ran.
    pub insns_before: usize,
    /// Instruction count after this pass ran.
    pub insns_after: usize,
}

impl PassResult {
    pub fn unchanged() -> Self {
        Self {
            sites_applied: 0,
            diagnostics: Vec::new(),
            ..Default::default()
        }
    }

    pub fn skipped(reason: SkipReason) -> Self {
        Self {
            sites_skipped: vec![reason],
            ..Self::unchanged()
        }
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
    pub value: Vec<u8>,
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
pub trait BpfPass: Send + Sync {
    /// Pass name.
    fn name(&self) -> &str;

    /// High-level classification for this pass.
    #[cfg(test)]
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    /// Execute the pass.
    ///
    /// - `program`: mutable reference — pass may modify the instruction stream
    /// - `ctx`: platform context (kfunc availability, CPU features, etc.)
    ///
    /// Returns PassResult describing what was done.
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult>;
}

/// Pass execution context — contains platform info and external configuration.
///
/// These values are invariant for the duration of a pipeline execution.
#[derive(Clone, Debug)]
pub struct PassContext {
    /// Available kinsn targets and static metadata.
    pub kinsn_registry: KinsnRegistry,
    /// CPU capabilities (detected at startup, checked by kinsn passes).
    pub platform: PlatformCapabilities,
    /// Policy configuration (which passes are enabled, parameters, etc.).
    pub policy: PolicyConfig,
    /// BPF program type (from `bpf_prog_info.type`).
    /// Used by passes to apply program-type-specific safety filters.
    /// 0 = unspecified (conservative behavior applies).
    pub prog_type: u32,
    /// Parsed verifier state snapshots consumed at the BBProgram lift boundary.
    pub verifier_states: Arc<[VerifierInsn]>,
    /// Per-original-PC annotations used by profile-guided passes.
    pub annotations: Vec<InsnAnnotation>,
    /// Program-level branch miss rate from real PMU data.
    pub branch_miss_rate: Option<f64>,
    /// Program map IDs in kernel `used_maps` order.
    pub map_ids: Vec<u32>,
    /// Pre-loaded map metadata side inputs.
    pub map_metadata: HashMap<u32, MapMetadata>,
    /// Pre-loaded map value snapshots.
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    /// Compressed map value overlays.
    pub map_value_overlays: HashMap<u32, CompressedMapValues>,
    /// Map-in-map outer entries: (outer map id, key bytes) -> inner map id.
    pub map_inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    /// Map snapshots intentionally skipped by size.
    pub map_snapshots_skipped_by_size: HashSet<u32>,
    /// Explicit map_inline key hints.
    pub map_inline_hints: Vec<MapInlineHint>,
    /// Raw func_info records for BBProgram/lower remapping.
    pub func_info: Option<BtfInfoRecords>,
    /// Raw line_info records for BBProgram/lower remapping.
    pub line_info: Option<BtfInfoRecords>,
}

/// Available kinsn targets resolved at runtime.
#[derive(Clone, Debug)]
pub struct KinsnRegistry {
    by_name: HashMap<&'static str, RegistryEntry>,
    by_call: HashMap<KinsnCallKey, &'static KinsnDescriptor>,
}

#[derive(Clone, Copy, Debug)]
struct RegistryEntry {
    btf_id: Option<i32>,
    call_off: i16,
    descriptor: &'static KinsnDescriptor,
}

#[derive(Clone, Copy, Debug, Hash, PartialEq, Eq)]
struct KinsnCallKey {
    btf_id: i32,
    call_off: i16,
}

#[cfg(test)]
impl Default for KinsnRegistry {
    fn default() -> Self {
        Self::new().expect("built-in kinsn registry should not contain duplicate target names")
    }
}

impl KinsnRegistry {
    pub fn new() -> anyhow::Result<Self> {
        let mut registry = Self {
            by_name: HashMap::new(),
            by_call: HashMap::new(),
        };
        for pass in crate::passes::PASS_REGISTRY {
            for descriptor in pass.metadata.kinsn_targets {
                registry.register_descriptor(descriptor)?;
            }
        }
        Ok(registry)
    }

    pub fn unavailable() -> anyhow::Result<Self> {
        Self::new()
    }

    pub fn canonical_name_for_target_name(&self, target_name: &str) -> Option<&'static str> {
        self.by_name
            .get(target_name)
            .map(|entry| entry.descriptor.canonical_name)
    }

    pub fn lookup_by_kinsn_call(
        &self,
        btf_id: i32,
        call_off: i16,
    ) -> anyhow::Result<&'static KinsnDescriptor> {
        self.by_call
            .get(&KinsnCallKey { btf_id, call_off })
            .copied()
            .ok_or_else(|| {
                anyhow::anyhow!(
                    "kinsn call btf_id {btf_id} call_off {call_off} is not present in the kinsn registry"
                )
            })
    }

    pub fn set_kinsn_call_for_target_name(
        &mut self,
        target_name: &str,
        btf_id: i32,
        call_off: i16,
    ) -> anyhow::Result<()> {
        let descriptor = self.descriptor_for_target_name(target_name)?;
        self.set_kinsn_call_for_descriptor(descriptor, btf_id, call_off)
    }

    pub fn btf_id_for_target_name(&self, target_name: &str) -> anyhow::Result<i32> {
        let entry = self
            .by_name
            .get(target_name)
            .ok_or_else(|| anyhow::anyhow!("kinsn target {target_name} not registered"))?;
        entry
            .btf_id
            .ok_or_else(|| anyhow::anyhow!("kinsn target {target_name} not registered"))
    }

    pub fn call_off_for_target_name(&self, target_name: &str) -> anyhow::Result<i16> {
        self.by_name
            .get(target_name)
            .map(|entry| entry.call_off)
            .ok_or_else(|| anyhow::anyhow!("unknown kinsn target: {target_name}"))
    }

    pub fn is_target_available(&self, target_name: &str) -> bool {
        self.by_name
            .get(target_name)
            .is_some_and(|entry| entry.btf_id.is_some())
    }

    fn register_descriptor(&mut self, descriptor: &'static KinsnDescriptor) -> anyhow::Result<()> {
        self.register_descriptor_name(descriptor.canonical_name, descriptor)?;
        for alias in descriptor.aliases {
            self.register_descriptor_name(alias, descriptor)?;
        }
        Ok(())
    }

    fn register_descriptor_name(
        &mut self,
        name: &'static str,
        descriptor: &'static KinsnDescriptor,
    ) -> anyhow::Result<()> {
        let previous = self.by_name.insert(
            name,
            RegistryEntry {
                btf_id: None,
                call_off: 0,
                descriptor,
            },
        );
        if previous.is_some() {
            anyhow::bail!("duplicate kinsn target name {name}");
        }
        Ok(())
    }

    fn descriptor_for_target_name(
        &self,
        target_name: &str,
    ) -> anyhow::Result<&'static KinsnDescriptor> {
        self.by_name
            .get(target_name)
            .map(|entry| entry.descriptor)
            .ok_or_else(|| anyhow::anyhow!("unknown kinsn target: {target_name}"))
    }

    fn set_kinsn_call_for_descriptor(
        &mut self,
        descriptor: &'static KinsnDescriptor,
        btf_id: i32,
        call_off: i16,
    ) -> anyhow::Result<()> {
        if btf_id < 0 {
            anyhow::bail!(
                "kinsn target {} cannot be registered with negative btf_id {btf_id}",
                descriptor.canonical_name
            );
        }
        let (old_btf_id, old_call_off) = self
            .by_name
            .get(descriptor.canonical_name)
            .map(|entry| (entry.btf_id, entry.call_off))
            .ok_or_else(|| {
                anyhow::anyhow!("unknown kinsn target: {}", descriptor.canonical_name)
            })?;

        let key = KinsnCallKey { btf_id, call_off };
        if let Some(existing) = self.by_call.get(&key) {
            if existing.canonical_name != descriptor.canonical_name {
                anyhow::bail!(
                    "kinsn btf_id {btf_id} call_off {call_off} is already registered for {}",
                    existing.canonical_name
                );
            }
        }
        if let Some(btf_id) = old_btf_id {
            self.by_call.remove(&KinsnCallKey {
                btf_id,
                call_off: old_call_off,
            });
        }
        self.by_call.insert(key, descriptor);
        for entry in self.entries_for_descriptor_mut(descriptor) {
            entry.btf_id = Some(btf_id);
            entry.call_off = call_off;
        }
        Ok(())
    }

    fn entries_for_descriptor_mut(
        &mut self,
        descriptor: &'static KinsnDescriptor,
    ) -> impl Iterator<Item = &mut RegistryEntry> {
        self.by_name
            .values_mut()
            .filter(move |entry| entry.descriptor.canonical_name == descriptor.canonical_name)
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

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum Arch {
    #[default]
    X86_64,
    Aarch64,
}

/// Optimization policy configuration.
#[derive(Clone, Debug, Default)]
pub struct PolicyConfig {
    /// Enabled pass name list. Empty means "allow all registered passes"; the
    /// bpfopt CLI supplies exactly one name for single-pass execution.
    pub enabled_passes: Vec<String>,
}

pub fn run_pass_once(
    pass: &dyn BpfPass,
    program: &mut BBProgram,
    ctx: &PassContext,
) -> anyhow::Result<PassResult> {
    if let Some(skip) = required_kinsn_skip(pass.name(), ctx) {
        return Ok(PassResult::skipped(skip));
    }

    let insns_before = program.program_slot_len()?;
    let mut result = pass.run(program, ctx)?;
    let insns_after = program.program_slot_len()?;
    result.insns_before = insns_before;
    result.insns_after = insns_after;

    if insns_after != insns_before {
        program.invalidate_oracle();
    }

    Ok(result)
}

fn required_kinsn_skip(pass_name: &str, ctx: &PassContext) -> Option<SkipReason> {
    if pass_name == "ccmp" && ctx.platform.arch != Arch::Aarch64 {
        return None;
    }
    let entry = crate::passes::PASS_REGISTRY
        .iter()
        .find(|entry| entry.name == pass_name)?;
    let missing = entry
        .metadata
        .required_kinsns
        .iter()
        .copied()
        .filter(|target| !ctx.kinsn_registry.is_target_available(target))
        .collect::<Vec<_>>();
    (!missing.is_empty()).then(|| SkipReason {
        pc: 0,
        reason: format!("missing required kinsn target(s): {}", missing.join(", ")),
    })
}

// ── Helper: default PassContext for testing ──────────────────────────

impl PassContext {
    pub fn try_baseline() -> anyhow::Result<Self> {
        Ok(Self {
            kinsn_registry: KinsnRegistry::unavailable()?,
            platform: PlatformCapabilities::default(),
            policy: PolicyConfig::default(),
            prog_type: 0,
            verifier_states: Arc::from([]),
            annotations: Vec::new(),
            branch_miss_rate: None,
            map_ids: Vec::new(),
            map_metadata: HashMap::new(),
            map_values: HashMap::new(),
            map_value_overlays: HashMap::new(),
            map_inner_map_ids: HashMap::new(),
            map_snapshots_skipped_by_size: HashSet::new(),
            map_inline_hints: Vec::new(),
            func_info: None,
            line_info: None,
        })
    }

    /// Create a minimal PassContext suitable for testing.
    /// All kinsn targets unavailable, no special CPU features.
    #[cfg(test)]
    pub fn baseline() -> Self {
        Self::try_baseline().expect("baseline pass context should build")
    }

    /// Whether cond_select can lower to a target branchless-select kinsn.
    pub fn has_branchless_select(&self) -> bool {
        self.platform.has_cmov || self.kinsn_registry.is_target_available("bpf_select64")
    }
}
