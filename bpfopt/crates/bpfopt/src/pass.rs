// SPDX-License-Identifier: MIT
//! Pass framework for BPF program transformations.
//!
//! Core abstractions:
//! - `ProgramCFG`: basic-block IR used by production pass execution
//! - `BpfPass`: transformation pass that may modify the program

use std::collections::{BTreeMap, HashMap, HashSet};
use std::path::PathBuf;
use std::sync::Arc;

use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::{
    BpfInsn, BPF_JEQ, BPF_JGE, BPF_JGT, BPF_JLE, BPF_JLT, BPF_JNE, BPF_JSGE, BPF_JSGT, BPF_JSLE,
    BPF_JSLT,
};
use crate::passes::map_inline::{CompressedMapValues, MapInfo, MapInlineHintSpec};
#[cfg(test)]
pub(crate) use crate::verifier_log::{RegState, ScalarRange, StackState, Tnum, VerifierValueWidth};
pub(crate) use crate::verifier_log::{VerifierInsn, VerifierInsnKind};
use clap::Args;
use serde::{Deserialize, Serialize};

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
    pub register_defs: fn(payload: u64) -> RegSet,
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

pub(crate) fn no_regs(_payload: u64) -> RegSet {
    RegSet::new()
}

/// Real per-site PMU branch statistics. Optional per-PC PGO input; the lift
/// step attaches present entries onto ProgramCFG keyed by site.
#[derive(Clone, Debug)]
pub struct BranchProfile {
    pub branch_count: u64,
    pub branch_misses: u64,
    pub miss_rate: f64,
    pub taken_count: u64,
    pub not_taken_count: u64,
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

/// CLI args shared by normal `--pass` invocations.
///
/// IMPORTANT: only put a flag here when *every* bpfopt run conceivably
/// needs it (input/output/report paths, target arch, prog type, kinsn
/// capability metadata, verifier log, BTF remapping inputs).
/// Per-pass tuning (e.g. map_inline's `--inline-hint`, branch_flip's
/// `--profile`, prefetch's `--profile`) goes in the pass's own
/// `<Pass>CliArgs` struct and is parsed AFTER `--`. Adding a pass-specific
/// flag here pollutes the pass invocation namespace.
#[derive(Args, Clone, Debug, Default)]
pub struct CommonArgs {
    /// Input bytecode file. Defaults to stdin.
    #[arg(long, value_name = "FILE")]
    pub input: Option<PathBuf>,
    /// Output bytecode or JSON file. Defaults to stdout.
    #[arg(long, value_name = "FILE")]
    pub output: Option<PathBuf>,
    /// Pass report JSON output file.
    #[arg(long, value_name = "FILE")]
    pub report: Option<PathBuf>,
    /// BPF program type, such as xdp, sched_cls, tracing, or a numeric type.
    #[arg(long, value_name = "TYPE")]
    pub prog_type: Option<String>,
    /// Kinsn capability JSON file.
    #[arg(long, value_name = "FILE")]
    pub target: Option<PathBuf>,
    /// Verifier states JSON file.
    #[arg(long, value_name = "FILE")]
    pub verifier_states: Option<PathBuf>,
    /// Raw func_info records to remap in place when instruction offsets change.
    #[arg(long, value_name = "FILE")]
    pub func_info: Option<PathBuf>,
    /// Byte size of one func_info record.
    #[arg(long, value_name = "BYTES")]
    pub func_info_rec_size: Option<u32>,
    /// Raw line_info records to remap in place when instruction offsets change.
    #[arg(long, value_name = "FILE")]
    pub line_info: Option<PathBuf>,
    /// Byte size of one line_info record.
    #[arg(long, value_name = "BYTES")]
    pub line_info_rec_size: Option<u32>,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct TargetJson {
    /// Target architecture (e.g. "x86_64", "aarch64"). Consumed by passes
    /// for emit-time optimization choices; never used for admission/gating.
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub arch: Option<String>,
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
    /// Sites that were skipped by ProgramCFG-native passes before report PC
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
}

impl PassResult {
    /// Whole-pass skip anchored at the program's first report site.
    pub fn skipped_pass(program: &ProgramCFG, reason: impl Into<String>) -> anyhow::Result<Self> {
        let site_skipped = vec![SiteSkipReason::new(first_report_site(program)?, reason)];
        Ok(Self {
            site_skipped,
            ..Default::default()
        })
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
    /// Execute the pass. `program` may be mutated; `ctx` carries platform and
    /// side-input state. Returns a `PassResult` describing what changed.
    fn run(&self, program: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult>;
}

/// Pass execution context — contains platform info and external configuration.
///
/// These values are invariant for the duration of a single pass invocation.
#[derive(Clone, Debug, Default)]
pub struct PassContext {
    /// Available kinsn targets and static descriptors.
    pub kinsn_registry: KinsnRegistry,
    /// Target architecture for emission-time optimization choices (e.g.
    /// endian_fusion's directly-encodable offset rules). Sourced from
    /// `target.json`, never auto-detected from the host. Has no bearing on
    /// pass admission — invalid bytecode is rejected by the kernel verifier.
    pub arch: Arch,
    /// BPF program type (from `bpf_prog_info.type`).
    /// Used by passes to apply program-type-specific safety filters.
    /// 0 = unspecified (conservative behavior applies).
    pub prog_type: u32,
    /// Parsed verifier state snapshots consumed at the ProgramCFG lift boundary.
    /// Private; lift accesses via `verifier_states_arc()`, tests via `set_verifier_states_test`.
    verifier_states: Arc<[VerifierInsn]>,
    /// Per-original-PC branch profiles used by profile-guided passes.
    pub annotations: Vec<Option<BranchProfile>>,
    /// Program-level branch miss rate from real PMU data.
    pub branch_miss_rate: Option<f64>,
    /// Program map IDs in kernel `used_maps` order.
    pub map_ids: Vec<u32>,
    /// Pre-loaded map info side inputs.
    pub map_info: HashMap<u32, MapInfo>,
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
    /// Raw func_info records for ProgramCFG/lower remapping.
    pub func_info: Option<BtfInfoRecords>,
    /// Raw line_info records for ProgramCFG/lower remapping.
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
        for descriptor in crate::passes::COMMON_KINSN_TARGETS {
            registry.insert_builtin_descriptor(descriptor)?;
        }
        for pass in crate::passes::PASS_REGISTRY {
            for descriptor in pass.kinsn_targets {
                registry.insert_builtin_descriptor(descriptor)?;
            }
        }
        Ok(registry)
    }

    fn insert_builtin_descriptor(
        &mut self,
        descriptor: &'static KinsnDescriptor,
    ) -> anyhow::Result<()> {
        let previous = self.by_name.insert(
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
        Ok(())
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
}

/// CPU platform capabilities. Currently only `arch` matters at runtime —
/// pass admission gates on kinsn availability instead of CPU feature bits.
/// Target architecture, sourced from `target.json`. Used by emit-time
/// optimization choices in passes (e.g. endian_fusion offset encoding).
/// Default is `X86_64` so that programs targeting the most common arch
/// stay optimized when `target.json` omits the `arch` field.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum Arch {
    #[default]
    X86_64,
    Aarch64,
}

impl Arch {
    pub fn from_str(s: &str) -> anyhow::Result<Self> {
        match s {
            "x86_64" | "amd64" => Ok(Self::X86_64),
            "aarch64" | "arm64" => Ok(Self::Aarch64),
            _ => anyhow::bail!("unsupported target arch: {s}"),
        }
    }
}

pub fn run_pass_once(
    pass: &dyn BpfPass,
    program: &mut ProgramCFG,
    ctx: &PassContext,
) -> anyhow::Result<PassResult> {
    let insns_before = program_instruction_slots(program)?;
    let mut result = pass.run(program, ctx)?;
    let insns_after = program_instruction_slots(program)?;
    result.insns_before = insns_before;
    result.insns_after = insns_after;

    if insns_after != insns_before {
        program.invalidate_verifier_states();
    }

    Ok(result)
}

pub fn report_site_pc(program: &ProgramCFG, site: InsnSite) -> anyhow::Result<u64> {
    let pc = program.site_current_pc(site)?;
    u64::try_from(pc).map_err(|_| anyhow::anyhow!("report PC {pc} for {site:?} does not fit u64"))
}

fn program_instruction_slots(program: &ProgramCFG) -> anyhow::Result<usize> {
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
    prog: &mut ProgramCFG,
    candidates: &[(InsnSite, S)],
    skipped: &mut Vec<SiteSkipReason>,
    mut emit: F,
) -> anyhow::Result<usize>
where
    F: FnMut(&ProgramCFG, InsnSite, &S) -> anyhow::Result<(usize, Vec<BpfInsn>)>,
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

/// Walk every block boundary and record a "pattern straddles block split"
/// skip whenever the last body insn of one block and the first body insn of
/// its fallthrough successor satisfy `matches_pair`.
///
/// Used by 2-insn pair passes (extract, endian) to surface the same
/// interior-branch-target signal scan_block_starts misses.
pub fn collect_cross_block_pair_skips<F>(
    prog: &ProgramCFG,
    mut matches_pair: F,
    reason: &str,
) -> anyhow::Result<Vec<SiteSkipReason>>
where
    F: FnMut(&BpfInsn, &BpfInsn) -> bool,
{
    use crate::analysis::Terminator;
    let mut skipped = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        let body = prog.block_body_view(block)?;
        let Some(&start) = body.sites.last() else {
            continue;
        };
        let next_block = match prog.terminator(block)? {
            Terminator::Fallthrough { next } => next,
            _ => continue,
        };
        let successors = prog.successors(block);
        if successors.len() != 1 || successors[0] != next_block {
            anyhow::bail!("fallthrough block {:?} has inconsistent successors", block);
        }
        let Some(next) = prog.sites_in_block(next_block)?.first().copied() else {
            continue;
        };
        if matches_pair(prog.insn(start)?, prog.insn(next)?) {
            skipped.push(SiteSkipReason::new(start, reason));
        }
    }
    Ok(skipped)
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
    prog: &ProgramCFG,
    site: InsnSite,
    reason: impl Into<String>,
) -> anyhow::Result<SiteSkipReason> {
    prog.insn(site)?;
    Ok(SiteSkipReason::new(site, reason))
}

pub(crate) fn delete_body_sites_reverse<I>(
    prog: &mut ProgramCFG,
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
    prog: &ProgramCFG,
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
    prog: &ProgramCFG,
    start: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    frame_sites_around(prog, start, true)
}

pub(crate) fn sites_before_in_frame_rev(
    prog: &ProgramCFG,
    end: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    frame_sites_around(prog, end, false)
}

pub fn first_report_site(program: &ProgramCFG) -> anyhow::Result<InsnSite> {
    for block in program.block_ids() {
        if let Some(site) = program.first_site_in_block(block)? {
            return Ok(site);
        }
    }
    anyhow::bail!("cannot report a pass site for an empty program")
}

// ── Helper: default PassContext for testing ──────────────────────────

impl PassContext {
    pub fn set_verifier_states_from_log(&mut self, log: &str) -> anyhow::Result<()> {
        // An empty state set is legitimate when the previous ReJIT step ran at
        // log_level=1 — the kernel only emits the final pass/fail line, no
        // per-PC deltas. Passes that consume verifier states fall back to
        // unknown reg classification (which their is_some_and gates handle).
        self.verifier_states = Arc::from(crate::verifier_log::verifier_states_from_log(log)?);
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
    /// to seed the ProgramCFG verifier-state map. After lift, passes consume typed
    /// `ProgramCFG::reg_*` queries instead of touching raw verifier data.
    pub(crate) fn verifier_states_arc(&self) -> Arc<[VerifierInsn]> {
        Arc::clone(&self.verifier_states)
    }
}
