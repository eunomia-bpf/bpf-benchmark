// SPDX-License-Identifier: MIT
//! Pass framework for BPF program transformations.
//!
//! Core abstractions:
//! - `BBProgram`: basic-block IR used by production pass execution
//! - `BpfPass`: transformation pass that may modify the program

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fmt;
use std::path::PathBuf;
use std::sync::Arc;

use crate::analysis::{BBProgram, InsnSite};
use crate::insn::{
    BpfInsn, BPF_JEQ, BPF_JGE, BPF_JGT, BPF_JLE, BPF_JLT, BPF_JNE, BPF_JSGE, BPF_JSGT, BPF_JSLE,
    BPF_JSLT,
};
#[cfg(test)]
pub(crate) use crate::verifier_log::{RegState, ScalarRange, StackState, Tnum, VerifierValueWidth};
pub(crate) use crate::verifier_log::{VerifierInsn, VerifierInsnKind};
use clap::Args;
use serde::ser::SerializeStruct;
use serde::{Deserialize, Serialize, Serializer};

pub type RegSet = HashSet<u8>;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum RegKind {
    Scalar,
    FramePointer,
    Context,
    PacketPointer,
    PacketMetaPointer,
    MapPointer,
    MapValue,
    MapKey,
    Memory,
    BtfStructPointer,
    OtherPointer,
    Unknown,
}

#[derive(Clone, Copy, Debug)]
pub struct KinsnDescriptor {
    pub name: &'static str,
    pub register_uses: fn(payload: u64) -> RegSet,
}

impl Serialize for KinsnDescriptor {
    fn serialize<S>(&self, serializer: S) -> std::result::Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        let mut state = serializer.serialize_struct("KinsnDescriptor", 1)?;
        state.serialize_field("name", self.name)?;
        state.end()
    }
}

pub(crate) fn kinsn_payload_reg(payload: u64, shift: u8) -> u8 {
    BpfInsn::unpack_u4(payload, shift)
}

/// Build a RegSet from a fixed list of payload reg offsets. Use for kinsn
/// descriptors whose register operands are at known bit offsets.
pub(crate) fn regs_from_offsets(payload: u64, offsets: &[u8]) -> RegSet {
    offsets
        .iter()
        .copied()
        .map(|shift| kinsn_payload_reg(payload, shift))
        .collect()
}

// ── Per-instruction annotation — populated by analysis passes, read by transform passes.
#[derive(Clone, Debug, Default)]
pub struct InsnAnnotation {
    /// PGO: branch taken/not-taken counts at this instruction.
    /// Used by BranchFlipPass to decide whether to flip.
    pub branch_profile: Option<BranchProfile>,
    /// Optional PMU data for prefetch admission.
    /// Used by PrefetchPass to suppress structurally valid but cold sites.
    pub(crate) prefetch_profile: Option<PrefetchProfile>,
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
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MapInlineHintModeSpec {
    Soft,
    Hard,
}

#[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum MapInlineHintAnchorSpec {
    Pc(usize),
    MapName(String),
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInlineHintSpec {
    pub anchor: MapInlineHintAnchorSpec,
    pub mode: MapInlineHintModeSpec,
    pub key: Vec<u8>,
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

/// Framework-global CLI args shared by every pass invocation.
///
/// IMPORTANT: only put a flag here when *every* bpfopt run conceivably
/// needs it (input/output/report paths, target arch, prog type, BTF
/// remapping inputs, kinsn target metadata, verifier-states JSON).
/// Per-pass tuning (e.g. map_inline's `--inline-hint`, branch_flip's
/// `--profile`, prefetch's `--profile`) goes in the pass's own
/// `<Pass>CliArgs` struct and is parsed AFTER `--`. Adding a pass-specific
/// flag here pollutes the global namespace and breaks the pass-local
/// args trait.
#[derive(Args, Clone, Debug, Default)]
pub struct CommonArgs {
    /// Input bytecode file. Defaults to stdin.
    #[arg(long, global = true, value_name = "FILE")]
    pub input: Option<PathBuf>,
    /// Output bytecode or JSON file. Defaults to stdout.
    #[arg(long, global = true, value_name = "FILE")]
    pub output: Option<PathBuf>,
    /// Canonicalize map references from loader FD form to stable map-index form.
    #[arg(long, global = true)]
    pub canonicalize_map_refs: bool,
    /// Program map IDs in kernel used_maps order, comma-separated.
    #[arg(long, global = true, value_name = "IDS", value_delimiter = ',')]
    pub map_ids: Vec<u32>,
    /// Pass report JSON output file.
    #[arg(long, global = true, value_name = "FILE")]
    pub report: Option<PathBuf>,
    /// Target architecture: x86_64 or aarch64.
    #[arg(long, global = true, value_name = "ARCH")]
    pub platform: Option<String>,
    /// BPF program type, such as xdp, sched_cls, tracing, or a numeric type.
    #[arg(long, global = true, value_name = "TYPE")]
    pub prog_type: Option<String>,
    /// Available kinsns, comma-separated. Entries may be name or name:btf_id.
    #[arg(long, global = true, value_name = "LIST", value_delimiter = ',')]
    pub kinsns: Vec<String>,
    /// Target platform JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    pub target: Option<PathBuf>,
    /// Output target platform JSON file after canonicalization-time rewrites.
    #[arg(long, global = true, value_name = "FILE")]
    pub target_output: Option<PathBuf>,
    /// Verifier states JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    pub verifier_states: Option<PathBuf>,
    /// Raw func_info records to remap in place when instruction offsets change.
    #[arg(long, global = true, value_name = "FILE")]
    pub func_info: Option<PathBuf>,
    /// Byte size of one func_info record.
    #[arg(long, global = true, value_name = "BYTES")]
    pub func_info_rec_size: Option<u32>,
    /// Raw line_info records to remap in place when instruction offsets change.
    #[arg(long, global = true, value_name = "FILE")]
    pub line_info: Option<PathBuf>,
    /// Byte size of one line_info record.
    #[arg(long, global = true, value_name = "BYTES")]
    pub line_info_rec_size: Option<u32>,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct TargetJson {
    #[serde(skip_serializing_if = "Option::is_none")]
    pub arch: Option<String>,
    #[serde(default)]
    pub features: Vec<String>,
    #[serde(default)]
    pub kinsns: BTreeMap<String, KinsnJson>,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct KinsnJson {
    pub btf_func_id: i32,
    #[serde(default)]
    pub btf_id: u32,
    pub call_offset: i16,
}

// ── Program IR ──────────────────────────────────────────────────────

/// Pre-loaded map metadata used by snapshot/offline map providers.
///
/// The pass resolves layout/type information from this metadata. Mutability
/// is derived from bytecode-level writer helpers and map type rules.
#[derive(Clone, Debug, PartialEq, Eq)]
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

pub fn hex_bytes(bytes: &[u8]) -> String {
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
    /// Sites that were skipped by BBProgram-native passes before report PC
    /// materialization.
    pub site_skipped: Vec<SiteSkipReason>,
    /// Diagnostic messages (read by tests and debug output).
    pub diagnostics: Vec<String>,
    /// Site-keyed diagnostic messages materialized to report PCs by the CLI
    /// report sink.
    pub site_diagnostics: Vec<SiteDiagnostic>,
    /// Map-inline sites produced by this pass.
    pub map_inline_records: Vec<MapInlineRecord>,
    /// Instruction count before this pass ran.
    pub insns_before: usize,
    /// Instruction count after this pass ran.
    pub insns_after: usize,
    /// Test-only PC-keyed skip mirror, materialized by test helpers before
    /// the BBProgram is mutated. Production code uses `site_skipped`.
    #[cfg(test)]
    pub sites_skipped: Vec<SkipReason>,
}

/// Test-only PC-keyed skip record used by test assertions. Not in production.
#[cfg(test)]
#[derive(Clone, Debug)]
pub struct SkipReason {
    pub pc: usize,
    pub reason: String,
}

impl PassResult {
    pub fn unchanged() -> Self {
        Self {
            sites_applied: 0,
            diagnostics: Vec::new(),
            ..Default::default()
        }
    }

    pub fn skipped_site(reason: SiteSkipReason) -> Self {
        Self {
            site_skipped: vec![reason],
            ..Self::unchanged()
        }
    }

    /// Whole-pass skip anchored at the program's first report site.
    pub fn skipped_pass(program: &BBProgram, reason: impl Into<String>) -> anyhow::Result<Self> {
        Ok(Self::skipped_site(SiteSkipReason::new(
            first_report_site(program)?,
            reason,
        )))
    }

    pub fn with_sites(sites_applied: usize, site_skipped: Vec<SiteSkipReason>) -> Self {
        Self {
            sites_applied,
            site_skipped,
            ..Default::default()
        }
    }
}

#[derive(Clone, Debug)]
pub struct SiteSkipReason {
    pub site: InsnSite,
    pub reason: String,
}

impl SiteSkipReason {
    pub fn new(site: InsnSite, reason: impl Into<String>) -> Self {
        Self {
            site,
            reason: reason.into(),
        }
    }
}

#[derive(Clone, Debug)]
pub struct SiteDiagnostic {
    pub site: InsnSite,
    pub message: String,
}

/// One specialized map value snapshot emitted by `MapInlinePass`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct MapInlineRecord {
    pub map_id: u32,
    pub key: Vec<u8>,
    pub value: Vec<u8>,
}

/// Transform pass trait.
///
/// Each optimization is a pass: scan the program, find rewrite sites, apply transforms.
pub trait BpfPass: Send + Sync {
    /// Pass name.
    fn name(&self) -> &str;

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
    /// BPF program type (from `bpf_prog_info.type`).
    /// Used by passes to apply program-type-specific safety filters.
    /// 0 = unspecified (conservative behavior applies).
    pub prog_type: u32,
    /// Parsed verifier state snapshots consumed at the BBProgram lift boundary.
    /// Private; lift accesses via `verifier_states_arc()`, tests via `set_verifier_states_test`.
    verifier_states: Arc<[VerifierInsn]>,
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
    /// Explicit map_inline key hints keyed by original CLI anchors.
    pub map_inline_hints: Vec<MapInlineHintSpec>,
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
                let previous = registry.by_name.insert(
                    descriptor.name,
                    RegistryEntry {
                        btf_id: None,
                        call_off: 0,
                        descriptor,
                    },
                );
                if previous.is_some() {
                    anyhow::bail!("duplicate kinsn target name {}", descriptor.name);
                }
            }
        }
        Ok(registry)
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
        if btf_id < 0 {
            anyhow::bail!(
                "kinsn target {target_name} cannot be registered with negative btf_id {btf_id}"
            );
        }
        let entry = self
            .by_name
            .get_mut(target_name)
            .ok_or_else(|| anyhow::anyhow!("unknown kinsn target: {target_name}"))?;
        let descriptor = entry.descriptor;
        let old_btf_id = entry.btf_id;
        let old_call_off = entry.call_off;

        let key = KinsnCallKey { btf_id, call_off };
        if let Some(existing) = self.by_call.get(&key) {
            if existing.name != descriptor.name {
                anyhow::bail!(
                    "kinsn btf_id {btf_id} call_off {call_off} is already registered for {}",
                    existing.name
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
        let entry = self
            .by_name
            .get_mut(target_name)
            .expect("entry just looked up");
        entry.btf_id = Some(btf_id);
        entry.call_off = call_off;
        Ok(())
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

pub fn run_pass_once(
    pass: &dyn BpfPass,
    program: &mut BBProgram,
    ctx: &PassContext,
) -> anyhow::Result<PassResult> {
    let insns_before = program_instruction_slots(program)?;
    let mut result = pass.run(program, ctx)?;
    let insns_after = program_instruction_slots(program)?;
    result.insns_before = insns_before;
    result.insns_after = insns_after;

    if insns_after != insns_before {
        program.invalidate_oracle();
    }

    Ok(result)
}

pub fn report_site_pc(program: &BBProgram, site: InsnSite) -> anyhow::Result<u64> {
    let pc = program.site_current_pc(site)?;
    u64::try_from(pc).map_err(|_| anyhow::anyhow!("report PC {pc} for {site:?} does not fit u64"))
}

fn program_instruction_slots(program: &BBProgram) -> anyhow::Result<usize> {
    let mut len = 0usize;
    for site in program.all_sites() {
        len = len
            .checked_add(program.insn_slot_width(site)?)
            .ok_or_else(|| anyhow::anyhow!("program instruction slot count overflows"))?;
    }
    Ok(len)
}

/// Apply matched candidates in reverse site order, calling `emit` for each.
///
/// `emit` receives `(prog, start_site, &site_data)` and returns
/// `(old_len, replacement_insns)`. Returns the number of sites that committed
/// (i.e. `try_replace_range` returned `Ok(true)`).
pub fn apply_candidates_reverse<S, F>(
    prog: &mut BBProgram,
    candidates: &[(InsnSite, S)],
    skipped: &mut Vec<SiteSkipReason>,
    mut emit: F,
) -> anyhow::Result<usize>
where
    F: FnMut(&BBProgram, InsnSite, &S) -> anyhow::Result<(usize, Vec<BpfInsn>)>,
{
    let mut applied = 0usize;
    for (start, site) in candidates.iter().rev() {
        let (old_len, replacement) = emit(prog, *start, site)?;
        if prog.try_replace_range(*start, old_len, replacement, skipped)? {
            applied += 1;
        }
    }
    Ok(applied)
}

/// Detect a 2-insn pattern that crosses a single fallthrough block boundary.
///
/// `start` must point to the candidate first insn. If `start` is the last site
/// in its block and the block falls through into a successor whose first site
/// makes `matches_pair(start_insn, next_insn)` true, returns
/// `Some(SiteSkipReason { site: start, reason })`. Otherwise `None`.
///
/// Used by passes whose matchers operate on adjacent insn pairs and need to
/// surface a clear "skipped: interior branch target" signal when the pattern
/// straddles a block split (e.g. extract, endian, wide_mem).
pub fn check_cross_block_pair_pattern<F>(
    prog: &BBProgram,
    start: InsnSite,
    matches_pair: F,
    reason: &str,
) -> anyhow::Result<Option<SiteSkipReason>>
where
    F: FnOnce(&BpfInsn, &BpfInsn) -> bool,
{
    use crate::analysis::Terminator;
    let i0 = prog.insn(start)?;
    let start_block = prog.site_block(start);
    let body = prog.block_body_view(start_block)?;
    if start.idx + 1 < body.sites.len() {
        return Ok(None);
    }
    let next_block = match prog.terminator_at_site(start)? {
        Terminator::Fallthrough { next } => next,
        _ => return Ok(None),
    };
    let successors = prog.successors(start_block);
    if successors.len() != 1 || successors[0] != next_block {
        anyhow::bail!(
            "fallthrough block {:?} has inconsistent successors",
            start_block
        );
    }
    let Some(next) = prog.sites_in_block(next_block)?.first().copied() else {
        return Ok(None);
    };
    let i1 = prog.insn(next)?;
    Ok(matches_pair(i0, i1).then(|| SiteSkipReason::new(start, reason)))
}

pub(crate) fn invert_cond_jmp_op(op: u8) -> Option<u8> {
    match op {
        BPF_JEQ => Some(BPF_JNE),
        BPF_JNE => Some(BPF_JEQ),
        BPF_JGT => Some(BPF_JLE),
        BPF_JGE => Some(BPF_JLT),
        BPF_JLT => Some(BPF_JGE),
        BPF_JLE => Some(BPF_JGT),
        BPF_JSGT => Some(BPF_JSLE),
        BPF_JSGE => Some(BPF_JSLT),
        BPF_JSLT => Some(BPF_JSGE),
        BPF_JSLE => Some(BPF_JSGT),
        _ => None,
    }
}

pub(crate) fn checked_site_skip(
    prog: &BBProgram,
    site: InsnSite,
    reason: impl Into<String>,
) -> anyhow::Result<SiteSkipReason> {
    prog.insn(site)?;
    Ok(SiteSkipReason::new(site, reason))
}

pub(crate) fn delete_body_sites_reverse<I>(
    prog: &mut BBProgram,
    sites: I,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<usize>
where
    I: IntoIterator<Item = InsnSite>,
{
    let mut sites = sites.into_iter().collect::<Vec<_>>();
    sites.sort_unstable_by(|a, b| b.cmp(a));
    let mut deleted = 0usize;
    for site in sites {
        if prog.is_terminator_site(site)? {
            anyhow::bail!(
                "delete_body_sites_reverse cannot delete terminator at {:?}",
                site
            );
        }
        if prog.try_replace_range(site, 1, Vec::new(), skipped)? {
            deleted += 1;
        }
    }
    Ok(deleted)
}

/// Collect all sites in `anchor`'s frame, returning either the sites strictly
/// after `anchor` (in forward order) or the sites strictly before `anchor`
/// (in reverse order, nearest first).
fn frame_sites_around(
    prog: &BBProgram,
    anchor: InsnSite,
    after: bool,
) -> anyhow::Result<Vec<InsnSite>> {
    let frame = prog.site_frame(anchor)?;
    let mut sites = Vec::new();
    let mut seen = false;
    'outer: for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            if site == anchor {
                seen = true;
                if !after {
                    break 'outer;
                }
            } else if after == seen {
                sites.push(site);
            }
        }
    }
    if !seen {
        anyhow::bail!("site {:?} is missing from frame {:?}", anchor, frame);
    }
    if !after {
        sites.reverse();
    }
    Ok(sites)
}

pub(crate) fn sites_after_in_frame(
    prog: &BBProgram,
    start: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    frame_sites_around(prog, start, true)
}

pub(crate) fn sites_before_in_frame_rev(
    prog: &BBProgram,
    end: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    frame_sites_around(prog, end, false)
}

pub fn first_report_site(program: &BBProgram) -> anyhow::Result<InsnSite> {
    for block in program.block_ids() {
        if let Some(site) = program.first_site_in_block(block)? {
            return Ok(site);
        }
    }
    anyhow::bail!("cannot report a pass site for an empty BBProgram")
}

// ── Helper: default PassContext for testing ──────────────────────────

impl PassContext {
    pub fn set_verifier_states_from_log(&mut self, log: &str) -> anyhow::Result<()> {
        let states = crate::verifier_log::verifier_states_from_log(log);
        if states.is_empty() {
            anyhow::bail!("verifier log did not contain parseable state snapshots");
        }
        self.verifier_states = Arc::from(states);
        Ok(())
    }

    #[cfg(test)]
    pub(crate) fn set_verifier_states_test(&mut self, states: Vec<VerifierInsn>) {
        self.verifier_states = Arc::from(states);
    }

    pub fn has_verifier_states(&self) -> bool {
        !self.verifier_states.is_empty()
    }

    /// Lift-time accessor: only `bbprogram_lift` reads raw verifier states here
    /// to seed the BBProgram oracle. After lift, passes consume typed
    /// `BBProgram::reg_*` queries instead of touching raw verifier data.
    pub(crate) fn verifier_states_arc(&self) -> Arc<[VerifierInsn]> {
        Arc::clone(&self.verifier_states)
    }

    pub fn try_baseline() -> anyhow::Result<Self> {
        Ok(Self {
            kinsn_registry: KinsnRegistry::new()?,
            platform: PlatformCapabilities::default(),
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

    /// Whether cond_select can lower to the branchless-select kinsn.
    pub fn has_branchless_select(&self) -> bool {
        self.kinsn_registry.is_target_available("bpf_select64")
    }
}
