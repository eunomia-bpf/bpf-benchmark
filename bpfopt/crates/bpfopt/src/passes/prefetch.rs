// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, BlockId, InsnSite, ProgramCFG, SlotDistance};
use crate::insn::*;
use crate::pass::*;
use anyhow::{Context, Result};
use serde::Deserialize;
use std::collections::{BTreeMap, BTreeSet};
use std::fs;
use std::path::{Path, PathBuf};
pub(super) const HELPER_MAP_LOOKUP_ELEM: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const HELPER_XDP_ADJUST_HEAD: i32 = libbpf_sys::BPF_FUNC_xdp_adjust_head as i32;
const X86_PREFETCH_NTA_TARGET_NAME: &str = "bpf_x86_prefetchnta";
const X86_PREFETCH_TARGET_NAME: &str = "bpf_x86_prefetcht0";
const X86_PREFETCH_T1_TARGET_NAME: &str = "bpf_x86_prefetcht1";
const X86_PREFETCH_T2_TARGET_NAME: &str = "bpf_x86_prefetcht2";
const ARM64_PREFETCH_TARGET_NAME: &str = "bpf_arm64_prfm_pldl1keep";
const ARM64_PREFETCH_L1STRM_TARGET_NAME: &str = "bpf_arm64_prfm_pldl1strm";
const ARM64_PREFETCH_L2KEEP_TARGET_NAME: &str = "bpf_arm64_prfm_pldl2keep";
const ARM64_PREFETCH_L2STRM_TARGET_NAME: &str = "bpf_arm64_prfm_pldl2strm";
const TARGET_PREFETCH_DISTANCE: usize = 8;
const MAX_PREFETCH_DISTANCE: usize = 16;
const POINTER_INDEX_USE_LOOKAHEAD: usize = 64;
const MAX_PREFETCH_SITES_PER_PROGRAM: usize = 1;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: X86_PREFETCH_NTA_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: X86_PREFETCH_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: X86_PREFETCH_T1_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: X86_PREFETCH_T2_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: ARM64_PREFETCH_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: ARM64_PREFETCH_L1STRM_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: ARM64_PREFETCH_L2KEEP_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: ARM64_PREFETCH_L2STRM_TARGET_NAME,
        register_uses: prefetch_register_uses,
        register_defs: no_regs,
    },
];
fn prefetch_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
#[derive(Clone, Debug)]
pub struct PrefetchPass {
    profile: PrefetchProfileGate,
    hint: PrefetchHint,
    max_sites_per_program: usize,
    emit_candidate_diagnostics: bool,
}

impl PrefetchPass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        let args = PrefetchCliArgs::parse(args)?;
        Ok(Box::new(Self {
            profile: args.profile,
            hint: args.hint,
            max_sites_per_program: args.max_sites_per_program,
            emit_candidate_diagnostics: args.emit_candidate_diagnostics,
        }))
    }

    #[cfg(test)]
    pub(super) fn with_map_value_profile_pcs(pcs: impl IntoIterator<Item = u64>) -> Self {
        Self {
            profile: PrefetchProfileGate {
                map_value_pcs: pcs.into_iter().collect(),
                map_value_prefetch_points: BTreeMap::new(),
                map_value_skip_pcs: BTreeSet::new(),
                map_value_skipped_prefetch_points: BTreeMap::new(),
            },
            hint: PrefetchHint::default(),
            max_sites_per_program: MAX_PREFETCH_SITES_PER_PROGRAM,
            emit_candidate_diagnostics: false,
        }
    }

    #[cfg(test)]
    pub(super) fn from_profile_json_for_test(input: &str) -> Result<Self> {
        let json: PrefetchProfileJson = serde_json::from_str(input)?;
        Ok(Self {
            profile: json.into_gate()?,
            hint: PrefetchHint::default(),
            max_sites_per_program: MAX_PREFETCH_SITES_PER_PROGRAM,
            emit_candidate_diagnostics: false,
        })
    }

    #[cfg(test)]
    pub(super) fn from_profile_json_with_options_for_test(
        input: &str,
        hint: &str,
        max_sites_per_program: usize,
    ) -> Result<Self> {
        let json: PrefetchProfileJson = serde_json::from_str(input)?;
        if max_sites_per_program == 0 {
            anyhow::bail!("test max_sites_per_program must be greater than zero");
        }
        Ok(Self {
            profile: json.into_gate()?,
            hint: PrefetchHint::parse(hint)?,
            max_sites_per_program,
            emit_candidate_diagnostics: false,
        })
    }

    #[cfg(test)]
    pub(super) fn with_candidate_diagnostics_for_test(mut self) -> Self {
        self.emit_candidate_diagnostics = true;
        self
    }
}

impl Default for PrefetchPass {
    fn default() -> Self {
        Self {
            profile: PrefetchProfileGate::default(),
            hint: PrefetchHint::default(),
            max_sites_per_program: MAX_PREFETCH_SITES_PER_PROGRAM,
            emit_candidate_diagnostics: false,
        }
    }
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
enum PrefetchHint {
    #[default]
    L1Keep,
    L1Stream,
    L2Keep,
    L2Stream,
    X86Nta,
}

impl PrefetchHint {
    fn parse(input: &str) -> Result<Self> {
        match input {
            "default" | "l1keep" | "t0" | "pldl1keep" => Ok(Self::L1Keep),
            "l1strm" | "l1stream" | "pldl1strm" => Ok(Self::L1Stream),
            "l2keep" | "t1" | "pldl2keep" => Ok(Self::L2Keep),
            "l2strm" | "t2" | "l2stream" | "pldl2strm" => Ok(Self::L2Stream),
            "nta" | "non-temporal" | "prefetchnta" => Ok(Self::X86Nta),
            other => anyhow::bail!("prefetch unknown hint: {other}"),
        }
    }

    fn target_name(self, arch: Arch) -> &'static str {
        match (arch, self) {
            (Arch::X86_64, Self::L1Keep) => X86_PREFETCH_TARGET_NAME,
            (Arch::X86_64, Self::L1Stream) => X86_PREFETCH_T2_TARGET_NAME,
            (Arch::X86_64, Self::L2Keep) => X86_PREFETCH_T1_TARGET_NAME,
            (Arch::X86_64, Self::L2Stream) => X86_PREFETCH_T2_TARGET_NAME,
            (Arch::X86_64, Self::X86Nta) => X86_PREFETCH_NTA_TARGET_NAME,
            (Arch::Aarch64, Self::L1Keep | Self::X86Nta) => ARM64_PREFETCH_TARGET_NAME,
            (Arch::Aarch64, Self::L1Stream) => ARM64_PREFETCH_L1STRM_TARGET_NAME,
            (Arch::Aarch64, Self::L2Keep) => ARM64_PREFETCH_L2KEEP_TARGET_NAME,
            (Arch::Aarch64, Self::L2Stream) => ARM64_PREFETCH_L2STRM_TARGET_NAME,
        }
    }

    fn profile_name(self) -> &'static str {
        match self {
            Self::L1Keep => "l1keep",
            Self::L1Stream => "l1strm",
            Self::L2Keep => "l2keep",
            Self::L2Stream => "l2strm",
            Self::X86Nta => "nta",
        }
    }
}

#[derive(Clone, Debug, Default)]
struct PrefetchProfileGate {
    map_value_pcs: BTreeSet<u64>,
    map_value_prefetch_points: BTreeMap<u64, BTreeMap<u8, PrefetchPointPolicy>>,
    map_value_skip_pcs: BTreeSet<u64>,
    map_value_skipped_prefetch_points: BTreeMap<u64, BTreeSet<u8>>,
}

#[derive(Clone, Copy, Debug, Default)]
struct PrefetchPointPolicy {
    hint: Option<PrefetchHint>,
}

impl PrefetchProfileGate {
    fn from_path(path: &Path) -> Result<Self> {
        let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
        let json: PrefetchProfileJson = serde_json::from_slice(&data)
            .with_context(|| format!("failed to parse prefetch profile from {}", path.display()))?;
        json.into_gate()
    }

    fn allows_map_value_pc(&self, pc: u64) -> bool {
        self.map_value_pcs.contains(&pc) && !self.map_value_skip_pcs.contains(&pc)
    }

    fn map_value_prefetch_points(&self, pc: u64) -> Option<&BTreeMap<u8, PrefetchPointPolicy>> {
        if self.map_value_skip_pcs.contains(&pc) {
            return None;
        }
        self.map_value_prefetch_points.get(&pc)
    }

    fn skips_map_value_prefetch_point(&self, pc: u64, reg: u8) -> bool {
        self.map_value_skipped_prefetch_points
            .get(&pc)
            .is_some_and(|regs| regs.contains(&reg))
    }
}

struct PrefetchCliArgs {
    profile: PrefetchProfileGate,
    hint: PrefetchHint,
    max_sites_per_program: usize,
    emit_candidate_diagnostics: bool,
}

impl PrefetchCliArgs {
    fn parse(args: &[String]) -> Result<Self> {
        let mut profile_path = None;
        let mut hint = PrefetchHint::default();
        let mut max_sites_per_program = MAX_PREFETCH_SITES_PER_PROGRAM;
        let mut emit_candidate_diagnostics = false;
        let mut iter = args.iter();
        while let Some(arg) = iter.next() {
            if let Some(value) = arg.strip_prefix("--profile=") {
                profile_path = Some(PathBuf::from(value));
                continue;
            }
            if let Some(value) = arg.strip_prefix("--hint=") {
                hint = PrefetchHint::parse(value)?;
                continue;
            }
            if let Some(value) = arg.strip_prefix("--max-sites=") {
                max_sites_per_program = parse_prefetch_max_sites(value)?;
                continue;
            }
            match arg.as_str() {
                "--emit-candidates" => {
                    emit_candidate_diagnostics = true;
                }
                "--candidate-diagnostics" => {
                    emit_candidate_diagnostics = true;
                }
                "--profile" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("prefetch --profile requires FILE"))?;
                    profile_path = Some(PathBuf::from(value));
                }
                "--hint" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("prefetch --hint requires VALUE"))?;
                    hint = PrefetchHint::parse(value)?;
                }
                "--max-sites" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("prefetch --max-sites requires N"))?;
                    max_sites_per_program = parse_prefetch_max_sites(value)?;
                }
                other => anyhow::bail!("prefetch unknown pass-local arg: {other}"),
            }
        }
        let profile = match profile_path {
            Some(path) => PrefetchProfileGate::from_path(&path)?,
            None => PrefetchProfileGate::default(),
        };
        Ok(Self {
            profile,
            hint,
            max_sites_per_program,
            emit_candidate_diagnostics,
        })
    }
}

fn parse_prefetch_max_sites(input: &str) -> Result<usize> {
    let value = input
        .parse::<usize>()
        .with_context(|| format!("prefetch --max-sites expects a positive integer, got {input}"))?;
    if value == 0 {
        anyhow::bail!("prefetch --max-sites must be greater than zero");
    }
    Ok(value)
}

#[derive(Debug, Deserialize)]
struct PrefetchProfileJson {
    #[serde(default)]
    map_value_pcs: Vec<u64>,
    #[serde(default)]
    map_value_sites: Vec<PrefetchProfileSiteJson>,
    #[serde(default)]
    map_value_prefetch_points: Vec<PrefetchProfilePointJson>,
    #[serde(default)]
    map_value_policy_points: Vec<PrefetchProfilePolicyPointJson>,
    #[serde(default = "default_min_load_misses")]
    min_load_misses: u64,
    #[serde(default)]
    min_miss_rate: f64,
}

#[derive(Debug, Deserialize)]
struct PrefetchProfileSiteJson {
    pc: u64,
    #[serde(default)]
    allow: bool,
    #[serde(default)]
    load_misses: Option<u64>,
    #[serde(default)]
    miss_rate: Option<f64>,
}

#[derive(Debug, Deserialize)]
struct PrefetchProfilePointJson {
    pc: u64,
    reg: u8,
}

#[derive(Debug, Deserialize)]
struct PrefetchProfilePolicyPointJson {
    pc: u64,
    #[serde(default)]
    reg: Option<u8>,
    action: PrefetchProfilePolicyAction,
    #[serde(default)]
    policy: Option<String>,
    #[serde(default)]
    horizon: Option<u32>,
    #[serde(default)]
    degree: Option<u32>,
    #[serde(default)]
    hint: Option<String>,
    #[serde(default)]
    reason: Option<String>,
}

#[derive(Debug, Deserialize)]
#[serde(rename_all = "kebab-case")]
enum PrefetchProfilePolicyAction {
    Prefetch,
    Skip,
}

fn default_min_load_misses() -> u64 {
    1
}

impl PrefetchProfileJson {
    fn into_gate(self) -> Result<PrefetchProfileGate> {
        if !self.min_miss_rate.is_finite() || self.min_miss_rate < 0.0 {
            anyhow::bail!(
                "prefetch profile min_miss_rate must be finite and non-negative, got {}",
                self.min_miss_rate
            );
        }
        let mut map_value_pcs = self.map_value_pcs.into_iter().collect::<BTreeSet<_>>();
        for site in self.map_value_sites {
            let allowed_by_misses = site
                .load_misses
                .is_some_and(|misses| misses >= self.min_load_misses);
            let allowed_by_rate = site
                .miss_rate
                .is_some_and(|rate| rate.is_finite() && rate >= self.min_miss_rate);
            if site.allow || allowed_by_misses || allowed_by_rate {
                map_value_pcs.insert(site.pc);
            }
        }
        let mut map_value_prefetch_points =
            BTreeMap::<u64, BTreeMap<u8, PrefetchPointPolicy>>::new();
        let mut map_value_skip_pcs = BTreeSet::<u64>::new();
        let mut map_value_skipped_prefetch_points = BTreeMap::<u64, BTreeSet<u8>>::new();
        for point in self.map_value_prefetch_points {
            validate_prefetch_profile_reg("map_value_prefetch_points", point.reg)?;
            map_value_prefetch_points
                .entry(point.pc)
                .or_default()
                .insert(point.reg, PrefetchPointPolicy::default());
        }
        for point in self.map_value_policy_points {
            let hint = validate_prefetch_policy_point_metadata(&point)?;
            match point.action {
                PrefetchProfilePolicyAction::Prefetch => {
                    let reg = point.reg.ok_or_else(|| {
                        anyhow::anyhow!(
                            "prefetch profile map_value_policy_points action=prefetch requires reg"
                        )
                    })?;
                    validate_prefetch_profile_reg("map_value_policy_points", reg)?;
                    map_value_prefetch_points
                        .entry(point.pc)
                        .or_default()
                        .insert(reg, PrefetchPointPolicy { hint });
                }
                PrefetchProfilePolicyAction::Skip => {
                    if let Some(reg) = point.reg {
                        validate_prefetch_profile_reg("map_value_policy_points", reg)?;
                        map_value_skipped_prefetch_points
                            .entry(point.pc)
                            .or_default()
                            .insert(reg);
                    } else {
                        map_value_skip_pcs.insert(point.pc);
                    }
                }
            }
        }
        Ok(PrefetchProfileGate {
            map_value_pcs,
            map_value_prefetch_points,
            map_value_skip_pcs,
            map_value_skipped_prefetch_points,
        })
    }
}

fn validate_prefetch_profile_reg(field: &str, reg: u8) -> Result<()> {
    if reg > BPF_REG_10 {
        anyhow::bail!("prefetch profile {field} reg must be 0..10, got {reg}");
    }
    Ok(())
}

fn validate_prefetch_policy_point_metadata(
    point: &PrefetchProfilePolicyPointJson,
) -> Result<Option<PrefetchHint>> {
    if let Some(policy) = point.policy.as_deref() {
        validate_non_empty_profile_text("policy", policy)?;
    }
    if let Some(reason) = point.reason.as_deref() {
        validate_non_empty_profile_text("reason", reason)?;
    }
    if point.horizon.is_some_and(|value| value == 0) {
        anyhow::bail!("prefetch profile map_value_policy_points horizon must be positive");
    }
    if point.degree.is_some_and(|value| value == 0) {
        anyhow::bail!("prefetch profile map_value_policy_points degree must be positive");
    }
    point.hint.as_deref().map(PrefetchHint::parse).transpose()
}

fn validate_non_empty_profile_text(field: &str, value: &str) -> Result<()> {
    if value.trim().is_empty() {
        anyhow::bail!("prefetch profile map_value_policy_points {field} must be non-empty");
    }
    Ok(())
}
#[derive(Clone, Copy, Debug)]
struct PrefetchSite {
    target: InsnSite,
    ptr_reg: u8,
    ptr_root: InsnSite,
    ptr_def: InsnSite,
    mem_off: i16,
    source: PrefetchSource,
    dependent_load_depth: u8,
    hint_override: Option<PrefetchHint>,
}
#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target: InsnSite,
    insert: InsnSite,
    ptr_reg: u8,
    ptr_def: InsnSite,
    mem_off: i16,
    source: PrefetchSource,
    dependent_load_depth: u8,
    hint_override: Option<PrefetchHint>,
}

struct PrefetchLayout {
    pcs: BTreeMap<InsnSite, u64>,
}

impl PrefetchLayout {
    fn from_program(prog: &ProgramCFG) -> anyhow::Result<Self> {
        Ok(Self {
            pcs: report_site_pcs(prog)?,
        })
    }

    fn pc(&self, site: InsnSite) -> anyhow::Result<u64> {
        self.pcs
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))
    }

    fn offset(&self, site: InsnSite) -> anyhow::Result<SlotDistance> {
        let pc = usize::try_from(self.pc(site)?)
            .map_err(|_| anyhow::anyhow!("report PC for {site:?} does not fit usize"))?;
        Ok(SlotDistance::from_slots(pc))
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PrefetchSource {
    MapValue,
    MapValueProfilePoint,
    Packet,
}

impl PrefetchSource {
    fn report_name(self) -> &'static str {
        match self {
            Self::MapValue => "map-value",
            Self::MapValueProfilePoint => "map-value-profile-point",
            Self::Packet => "packet",
        }
    }
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum TrackedValue {
    Unknown,
    Ctx,
    PacketData {
        root_def: InsnSite,
        ptr_def: InsnSite,
        dependent_load_depth: u8,
    },
    PacketScalar {
        load_depth: u8,
    },
    PacketEnd,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapValueState {
    regs: [Option<InsnSite>; 11],
    stack_aliases: BTreeMap<i16, InsnSite>,
}

impl MapValueState {
    fn unknown() -> Self {
        Self {
            regs: [None; 11],
            stack_aliases: BTreeMap::new(),
        }
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct PacketState {
    regs: [TrackedValue; 11],
    stack_regs: BTreeMap<i16, TrackedValue>,
}

impl PacketState {
    fn unknown() -> Self {
        Self {
            regs: [TrackedValue::Unknown; 11],
            stack_regs: BTreeMap::new(),
        }
    }

    fn entry() -> Self {
        let mut state = Self::unknown();
        state.regs[BPF_REG_1 as usize] = TrackedValue::Ctx;
        state
    }
}
pub(super) fn prefetch_payload(ptr_reg: u8) -> anyhow::Result<u64> {
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(BpfInsn::pack_u4(ptr_reg, 0))
}
impl BpfPass for PrefetchPass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        if prog.all_sites().next().is_none() {
            return Ok(PassResult::default());
        }
        let mut candidates = Vec::new();
        let mut skipped = Vec::new();
        let mut site_diagnostics = Vec::new();
        let layout = PrefetchLayout::from_program(prog)?;
        for site in scan_prefetch_sites(prog, ctx.prog_type, &self.profile, &layout)? {
            if self.emit_candidate_diagnostics {
                site_diagnostics.push(prefetch_site_diagnostic(site, &layout)?);
            }
            if let Some(reason) = reject_unprofitable_site(prog, site, &self.profile, &layout)? {
                skipped.push(checked_site_skip(prog, site.target, reason)?);
                continue;
            }
            let insert_site = match choose_prefetch_insert_site(prog, site, &layout)? {
                Ok(insert) => insert,
                Err(reason) => {
                    skipped.push(checked_site_skip(prog, site.target, reason)?);
                    continue;
                }
            };
            candidates.push(PrefetchCandidate {
                target: site.target,
                insert: insert_site,
                ptr_reg: site.ptr_reg,
                ptr_def: site.ptr_def,
                mem_off: site.mem_off,
                source: site.source,
                dependent_load_depth: site.dependent_load_depth,
                hint_override: site.hint_override,
            });
        }
        let candidates = apply_prefetch_site_budget(
            dedup_candidates(candidates),
            self.max_sites_per_program,
            &mut skipped,
        )?;
        if candidates.is_empty() {
            return Ok(PassResult {
                site_skipped: skipped,
                site_diagnostics,
                ..Default::default()
            });
        }
        let pairs: Vec<(InsnSite, PrefetchCandidate)> =
            candidates.into_iter().map(|c| (c.insert, c)).collect();
        let applied =
            apply_candidates_reverse(prog, &pairs, &mut skipped, |prog, _, candidate| {
                let payload = prefetch_payload(candidate.ptr_reg)?;
                let hint = candidate.hint_override.unwrap_or(self.hint);
                Ok((0, prog.kinsn_emit(hint.target_name(ctx.arch), payload)?))
            })?;
        Ok(PassResult {
            sites_applied: applied,
            site_skipped: skipped,
            site_diagnostics,
            ..Default::default()
        })
    }
}

fn prefetch_site_diagnostic(
    site: PrefetchSite,
    layout: &PrefetchLayout,
) -> anyhow::Result<SiteDiagnostic> {
    let ptr_root_pc = layout.pc(site.ptr_root)?;
    let ptr_def_pc = layout.pc(site.ptr_def)?;
    let hint = site
        .hint_override
        .map(PrefetchHint::profile_name)
        .unwrap_or("default");
    Ok(SiteDiagnostic {
        site: site.target,
        message: format!(
            "prefetch_candidate source={} ptr_reg=r{} ptr_root_pc={} ptr_def_pc={} mem_off={} dependent_load_depth={} hint={}",
            site.source.report_name(),
            site.ptr_reg,
            ptr_root_pc,
            ptr_def_pc,
            site.mem_off,
            site.dependent_load_depth,
            hint,
        ),
    })
}

fn scan_prefetch_sites(
    prog: &ProgramCFG,
    prog_type: u32,
    profile: &PrefetchProfileGate,
    layout: &PrefetchLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = scan_map_value_prefetch_sites(prog, profile, layout)?;
    if let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) {
        sites.extend(scan_packet_prefetch_sites(prog, layout)?);
    }
    Ok(sites)
}
fn scan_map_value_prefetch_sites(
    prog: &ProgramCFG,
    profile: &PrefetchProfileGate,
    layout: &PrefetchLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    let blocks = prog.block_ids().collect::<Vec<_>>();
    let entry_states = map_value_block_entry_states(prog, layout)?;
    for block in blocks {
        let state = entry_states[block.0].clone();
        process_map_value_block(prog, block, state, profile, layout, Some(&mut sites))?;
    }
    Ok(sites)
}

fn map_value_block_entry_states(
    prog: &ProgramCFG,
    layout: &PrefetchLayout,
) -> anyhow::Result<Vec<MapValueState>> {
    let blocks = prog.block_ids().collect::<Vec<_>>();
    let block_count = blocks.len();
    let mut entry_states = vec![MapValueState::unknown(); block_count];
    let mut exit_states = vec![None::<MapValueState>; block_count];
    for _ in 0..block_count.saturating_mul(4).max(1) {
        let mut changed = false;
        for &block in &blocks {
            let entry = merge_map_value_predecessor_states(prog, block, &exit_states);
            if entry_states[block.0] != entry {
                entry_states[block.0] = entry.clone();
                changed = true;
            }
            let exit = process_map_value_block(
                prog,
                block,
                entry,
                &PrefetchProfileGate::default(),
                layout,
                None,
            )?;
            if exit_states[block.0].as_ref() != Some(&exit) {
                exit_states[block.0] = Some(exit);
                changed = true;
            }
        }
        if !changed {
            break;
        }
    }
    Ok(entry_states)
}

fn merge_map_value_predecessor_states(
    prog: &ProgramCFG,
    block: BlockId,
    exit_states: &[Option<MapValueState>],
) -> MapValueState {
    let preds = prog.predecessors(block);
    let mut states = preds.iter().filter_map(|pred| exit_states[pred.0].as_ref());
    let Some(first) = states.next() else {
        return MapValueState::unknown();
    };
    let mut merged = first.clone();
    for state in states {
        for (dst, value) in merged.regs.iter_mut().enumerate() {
            *value = merge_optional_map_alias(*value, state.regs[dst]);
        }
        let mut offsets = merged
            .stack_aliases
            .keys()
            .chain(state.stack_aliases.keys())
            .copied()
            .collect::<BTreeSet<_>>();
        for off in std::mem::take(&mut offsets) {
            let merged_value = merge_optional_map_alias(
                merged.stack_aliases.get(&off).copied(),
                state.stack_aliases.get(&off).copied(),
            );
            match merged_value {
                Some(site) => {
                    merged.stack_aliases.insert(off, site);
                }
                None => {
                    merged.stack_aliases.remove(&off);
                }
            }
        }
    }
    merged
}

fn merge_optional_map_alias(a: Option<InsnSite>, b: Option<InsnSite>) -> Option<InsnSite> {
    match (a, b) {
        (Some(left), Some(right)) if left == right => Some(left),
        (Some(left), None) => Some(left),
        (None, Some(right)) => Some(right),
        _ => None,
    }
}

fn process_map_value_block(
    prog: &ProgramCFG,
    block: BlockId,
    mut state: MapValueState,
    profile: &PrefetchProfileGate,
    layout: &PrefetchLayout,
    mut sites: Option<&mut Vec<PrefetchSite>>,
) -> anyhow::Result<MapValueState> {
    for site in prog.sites_in_block_with_terminator(block)? {
        let insn = prog.insn(site)?;
        if let Some(sites) = sites.as_deref_mut() {
            push_profiled_map_value_prefetch_points(site, profile, &state, layout, sites)?;
        }
        if let Some(base_reg) = load_base_reg(insn) {
            if let Some(ptr_def) = state.regs[base_reg as usize] {
                if let Some(sites) = sites.as_deref_mut() {
                    sites.push(PrefetchSite {
                        target: site,
                        ptr_reg: base_reg,
                        ptr_root: ptr_def,
                        ptr_def,
                        mem_off: insn.off,
                        source: PrefetchSource::MapValue,
                        dependent_load_depth: 0,
                        hint_override: None,
                    });
                }
            }
        }
        if insn.is_call() {
            for reg in state.regs.iter_mut().take(6) {
                *reg = None;
            }
            if insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
                state.regs[BPF_REG_0 as usize] = Some(site);
            }
            continue;
        }
        apply_map_value_alias_transfer(insn, site, &mut state.regs, &mut state.stack_aliases);
    }
    Ok(state)
}

fn push_profiled_map_value_prefetch_points(
    site: InsnSite,
    profile: &PrefetchProfileGate,
    state: &MapValueState,
    layout: &PrefetchLayout,
    sites: &mut Vec<PrefetchSite>,
) -> anyhow::Result<()> {
    let pc = layout.pc(site)?;
    let Some(points) = profile.map_value_prefetch_points(pc) else {
        return Ok(());
    };
    for (&ptr_reg, point_policy) in points {
        if profile.skips_map_value_prefetch_point(pc, ptr_reg) {
            continue;
        }
        let ptr_def = state.regs[ptr_reg as usize].unwrap_or(site);
        sites.push(PrefetchSite {
            target: site,
            ptr_reg,
            ptr_root: ptr_def,
            ptr_def,
            mem_off: 0,
            source: PrefetchSource::MapValueProfilePoint,
            dependent_load_depth: 0,
            hint_override: point_policy.hint,
        });
    }
    Ok(())
}
fn apply_map_value_alias_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    aliases: &mut [Option<InsnSite>; 11],
    stack_aliases: &mut BTreeMap<i16, InsnSite>,
) {
    if insn.is_ldimm64() {
        aliases[insn.dst_reg() as usize] = None;
        return;
    }
    update_stack_aliases(
        insn,
        site,
        |reg| aliases[reg as usize].is_some(),
        stack_aliases,
    );
    match insn.class() {
        BPF_ALU64 => apply_map_value_alu64_transfer(insn, site, aliases),
        BPF_LDX => {
            aliases[insn.dst_reg() as usize] = load_stack_alias(insn, stack_aliases).map(|_| site);
        }
        BPF_ALU | BPF_LD => aliases[insn.dst_reg() as usize] = None,
        _ => {}
    }
}
fn apply_map_value_alu64_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    aliases: &mut [Option<InsnSite>; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            aliases[dst] = aliases[insn.src_reg() as usize].map(|_| site);
        }
        (BPF_ADD | BPF_SUB, BPF_K | BPF_X) if aliases[dst].is_some() => {
            aliases[dst] = Some(site);
        }
        _ => aliases[dst] = None,
    }
}
fn scan_packet_prefetch_sites(
    prog: &ProgramCFG,
    layout: PacketCtxLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    let blocks = prog.block_ids().collect::<Vec<_>>();
    let entry_states = packet_block_entry_states(prog, layout)?;
    for block in blocks {
        let state = entry_states[block.0].clone();
        process_packet_block(prog, block, layout, state, Some(&mut sites))?;
    }
    Ok(sites)
}

fn packet_block_entry_states(
    prog: &ProgramCFG,
    layout: PacketCtxLayout,
) -> anyhow::Result<Vec<PacketState>> {
    let blocks = prog.block_ids().collect::<Vec<_>>();
    let block_count = blocks.len();
    let mut entry_states = vec![PacketState::unknown(); block_count];
    let mut exit_states = vec![None::<PacketState>; block_count];
    for _ in 0..block_count.saturating_mul(4).max(1) {
        let mut changed = false;
        for &block in &blocks {
            let entry = if block.0 == 0 {
                PacketState::entry()
            } else {
                merge_packet_predecessor_states(prog, block, &exit_states)
            };
            if entry_states[block.0] != entry {
                entry_states[block.0] = entry.clone();
                changed = true;
            }
            let exit = process_packet_block(prog, block, layout, entry, None)?;
            if exit_states[block.0].as_ref() != Some(&exit) {
                exit_states[block.0] = Some(exit);
                changed = true;
            }
        }
        if !changed {
            break;
        }
    }
    Ok(entry_states)
}

fn merge_packet_predecessor_states(
    prog: &ProgramCFG,
    block: BlockId,
    exit_states: &[Option<PacketState>],
) -> PacketState {
    let preds = prog.predecessors(block);
    let mut states = preds.iter().filter_map(|pred| exit_states[pred.0].as_ref());
    let Some(first) = states.next() else {
        return PacketState::unknown();
    };
    let mut merged = first.clone();
    for state in states {
        for (dst, value) in merged.regs.iter_mut().enumerate() {
            if *value != state.regs[dst] {
                *value = TrackedValue::Unknown;
            }
        }
        merged
            .stack_regs
            .retain(|off, value| state.stack_regs.get(off) == Some(value));
    }
    merged
}

fn process_packet_block(
    prog: &ProgramCFG,
    block: BlockId,
    layout: PacketCtxLayout,
    mut state: PacketState,
    mut sites: Option<&mut Vec<PrefetchSite>>,
) -> anyhow::Result<PacketState> {
    for site in prog.sites_in_block_with_terminator(block)? {
        let insn = prog.insn(site)?;
        if let Some(base_reg) = load_base_reg(insn) {
            if let TrackedValue::PacketData {
                root_def,
                ptr_def,
                dependent_load_depth,
            } = state.regs[base_reg as usize]
            {
                if let Some(sites) = sites.as_deref_mut() {
                    sites.push(PrefetchSite {
                        target: site,
                        ptr_reg: base_reg,
                        ptr_root: root_def,
                        ptr_def,
                        mem_off: insn.off,
                        source: PrefetchSource::Packet,
                        dependent_load_depth,
                        hint_override: None,
                    });
                }
            }
        }
        apply_packet_transfer(insn, site, layout, &mut state.regs, &mut state.stack_regs);
    }
    Ok(state)
}
fn apply_packet_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
    stack_regs: &mut BTreeMap<i16, TrackedValue>,
) {
    if insn.is_call() {
        if insn.src_reg() == 0 && insn.imm == HELPER_XDP_ADJUST_HEAD {
            for reg in regs.iter_mut() {
                *reg = TrackedValue::Unknown;
            }
            stack_regs.clear();
        } else {
            for reg in regs.iter_mut().take(6) {
                *reg = TrackedValue::Unknown;
            }
        }
        return;
    }
    if insn.is_ldimm64() {
        regs[insn.dst_reg() as usize] = TrackedValue::Unknown;
        return;
    }
    update_packet_stack_aliases(insn, stack_regs, regs);
    match insn.class() {
        BPF_LDX if bpf_mode(insn.code) == BPF_MEM => {
            apply_packet_ldx_transfer(insn, site, layout, regs, stack_regs);
        }
        BPF_ALU64 => apply_packet_alu64_transfer(insn, site, regs),
        BPF_ALU => apply_packet_alu32_transfer(insn, regs),
        BPF_LD => regs[insn.dst_reg() as usize] = TrackedValue::Unknown,
        _ => {}
    }
}
fn apply_packet_ldx_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
    stack_regs: &BTreeMap<i16, TrackedValue>,
) {
    let dst = insn.dst_reg() as usize;
    if let Some(value) = load_stack_value(insn, stack_regs) {
        regs[dst] = match value {
            TrackedValue::PacketData {
                root_def,
                dependent_load_depth,
                ..
            } => TrackedValue::PacketData {
                root_def,
                ptr_def: site,
                dependent_load_depth,
            },
            value => value,
        };
        return;
    }
    if let TrackedValue::PacketData {
        dependent_load_depth,
        ..
    } = regs[insn.src_reg() as usize]
    {
        regs[dst] = TrackedValue::PacketScalar {
            load_depth: dependent_load_depth.saturating_add(1),
        };
        return;
    }
    regs[dst] = match regs[insn.src_reg() as usize] {
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_off => {
            TrackedValue::PacketData {
                root_def: site,
                ptr_def: site,
                dependent_load_depth: 0,
            }
        }
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_end_off => {
            TrackedValue::PacketEnd
        }
        _ => TrackedValue::Unknown,
    };
}
fn apply_packet_alu64_transfer(insn: &BpfInsn, site: InsnSite, regs: &mut [TrackedValue; 11]) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            regs[dst] = match regs[insn.src_reg() as usize] {
                TrackedValue::PacketData {
                    root_def,
                    dependent_load_depth,
                    ..
                } => TrackedValue::PacketData {
                    root_def,
                    ptr_def: site,
                    dependent_load_depth,
                },
                value => value,
            };
        }
        (BPF_ADD | BPF_SUB, BPF_K) => {
            regs[dst] = match regs[dst] {
                TrackedValue::PacketData {
                    root_def,
                    dependent_load_depth,
                    ..
                } => TrackedValue::PacketData {
                    root_def,
                    ptr_def: site,
                    dependent_load_depth,
                },
                TrackedValue::PacketScalar { load_depth } => {
                    TrackedValue::PacketScalar { load_depth }
                }
                _ => TrackedValue::Unknown,
            };
        }
        (BPF_ADD | BPF_SUB, BPF_X) => {
            regs[dst] = match (regs[dst], regs[insn.src_reg() as usize]) {
                (
                    TrackedValue::PacketData {
                        root_def,
                        dependent_load_depth,
                        ..
                    },
                    TrackedValue::PacketScalar { load_depth },
                ) => TrackedValue::PacketData {
                    root_def,
                    ptr_def: site,
                    dependent_load_depth: dependent_load_depth.max(load_depth),
                },
                (
                    TrackedValue::PacketData {
                        root_def,
                        dependent_load_depth,
                        ..
                    },
                    _,
                ) => TrackedValue::PacketData {
                    root_def,
                    ptr_def: site,
                    dependent_load_depth,
                },
                (
                    TrackedValue::PacketScalar { load_depth },
                    TrackedValue::PacketScalar {
                        load_depth: src_depth,
                    },
                ) => TrackedValue::PacketScalar {
                    load_depth: load_depth.max(src_depth),
                },
                (TrackedValue::PacketScalar { load_depth }, _) => {
                    TrackedValue::PacketScalar { load_depth }
                }
                _ => TrackedValue::Unknown,
            };
        }
        _ => {
            if let TrackedValue::PacketScalar { load_depth } = regs[dst] {
                regs[dst] = TrackedValue::PacketScalar { load_depth };
            } else {
                regs[dst] = TrackedValue::Unknown;
            }
        }
    }
}

fn apply_packet_alu32_transfer(insn: &BpfInsn, regs: &mut [TrackedValue; 11]) {
    let dst = insn.dst_reg() as usize;
    regs[dst] = match (
        bpf_op(insn.code),
        bpf_src(insn.code),
        regs[dst],
        regs[insn.src_reg() as usize],
    ) {
        (BPF_MOV, BPF_X, _, TrackedValue::PacketScalar { load_depth }) => {
            TrackedValue::PacketScalar { load_depth }
        }
        (BPF_MOV, BPF_K, _, _) => TrackedValue::Unknown,
        (
            _,
            BPF_X,
            TrackedValue::PacketScalar { load_depth },
            TrackedValue::PacketScalar {
                load_depth: src_depth,
            },
        ) => TrackedValue::PacketScalar {
            load_depth: load_depth.max(src_depth),
        },
        (_, _, TrackedValue::PacketScalar { load_depth }, _) => {
            TrackedValue::PacketScalar { load_depth }
        }
        _ => TrackedValue::Unknown,
    };
}

fn stack_store_src(insn: &BpfInsn) -> Option<Option<u8>> {
    if bpf_mode(insn.code) != BPF_MEM || insn.dst_reg() != BPF_REG_10 {
        return None;
    }
    match insn.class() {
        BPF_STX => Some(Some(insn.src_reg())),
        BPF_ST => Some(None),
        _ => None,
    }
}

fn stack_load_off(insn: &BpfInsn) -> Option<i16> {
    (insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && insn.src_reg() == BPF_REG_10)
        .then_some(insn.off)
}

fn update_stack_aliases<F>(
    insn: &BpfInsn,
    site: InsnSite,
    is_pointer_reg: F,
    stack_aliases: &mut BTreeMap<i16, InsnSite>,
) where
    F: FnOnce(u8) -> bool,
{
    let Some(src_reg) = stack_store_src(insn) else {
        return;
    };
    match src_reg {
        Some(src) if bpf_size(insn.code) == BPF_DW && is_pointer_reg(src) => {
            stack_aliases.insert(insn.off, site);
        }
        _ => {
            stack_aliases.remove(&insn.off);
        }
    }
}

fn load_stack_alias(insn: &BpfInsn, stack_aliases: &BTreeMap<i16, InsnSite>) -> Option<InsnSite> {
    let off = stack_load_off(insn)?;
    stack_aliases.get(&off).copied()
}

fn update_packet_stack_aliases(
    insn: &BpfInsn,
    stack_regs: &mut BTreeMap<i16, TrackedValue>,
    regs: &[TrackedValue; 11],
) {
    let Some(src_reg) = stack_store_src(insn) else {
        return;
    };
    match src_reg {
        Some(src) if bpf_size(insn.code) == BPF_DW => match regs[src as usize] {
            TrackedValue::Unknown => {
                stack_regs.remove(&insn.off);
            }
            value => {
                stack_regs.insert(insn.off, value);
            }
        },
        _ => {
            stack_regs.remove(&insn.off);
        }
    }
}

fn load_stack_value(
    insn: &BpfInsn,
    stack_regs: &BTreeMap<i16, TrackedValue>,
) -> Option<TrackedValue> {
    let off = stack_load_off(insn)?;
    stack_regs.get(&off).copied()
}
fn load_base_reg(insn: &BpfInsn) -> Option<u8> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    match insn.class() {
        BPF_LDX => Some(insn.src_reg()),
        _ => None,
    }
}

fn reject_unprofitable_site(
    prog: &ProgramCFG,
    site: PrefetchSite,
    profile: &PrefetchProfileGate,
    layout: &PrefetchLayout,
) -> anyhow::Result<Option<String>> {
    match site.source {
        PrefetchSource::MapValueProfilePoint => Ok(None),
        PrefetchSource::MapValue => {
            let pc = layout.pc(site.target)?;
            if profile.allows_map_value_pc(pc) {
                Ok(None)
            } else {
                Ok(Some(format!(
                    "map value prefetch requires profile or PMU evidence for pc {pc}"
                )))
            }
        }
        PrefetchSource::Packet => reject_unprofitable_packet_site(prog, site, layout),
    }
}

fn reject_unprofitable_packet_site(
    prog: &ProgramCFG,
    site: PrefetchSite,
    layout: &PrefetchLayout,
) -> anyhow::Result<Option<String>> {
    if packet_load_feeds_later_packet_pointer(prog, site, layout)? {
        return Ok(Some(
            "packet load is an address source for a later dereference".into(),
        ));
    }
    if site.dependent_load_depth == 0 {
        return Ok(Some(
            "packet prefetch requires a data-dependent dereference".into(),
        ));
    }
    if site.dependent_load_depth > 1 {
        return Ok(Some(
            "dependent packet pointer chain is too deep for prefetch".into(),
        ));
    }
    Ok(None)
}

fn packet_load_feeds_later_packet_pointer(
    prog: &ProgramCFG,
    site: PrefetchSite,
    layout: &PrefetchLayout,
) -> anyhow::Result<bool> {
    let target = prog.insn(site.target)?;
    let loaded_reg = target.dst_reg();
    let mut scalar_aliases = RegSet::default();
    let mut packet_ptr_aliases = RegSet::default();
    scalar_aliases.insert(loaded_reg);
    packet_ptr_aliases.insert(site.ptr_reg);
    packet_ptr_aliases.insert(prog.insn(site.ptr_root)?.dst_reg());
    for scan_site in
        pf_sites_after_in_frame(prog, site.target, POINTER_INDEX_USE_LOOKAHEAD, layout)?
    {
        if scan_site == site.target {
            continue;
        }
        let insn = prog.insn(scan_site)?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            break;
        }
        if packet_ptr_aliases.contains(&insn.dst_reg())
            && scalar_aliases.contains(&insn.src_reg())
            && insn.class() == BPF_ALU64
            && bpf_src(insn.code) == BPF_X
            && matches!(bpf_op(insn.code), BPF_ADD | BPF_SUB)
        {
            return Ok(true);
        }
        update_pointer_index_scan_aliases(insn, &mut scalar_aliases, &mut packet_ptr_aliases);
    }
    Ok(false)
}

fn update_pointer_index_scan_aliases(
    insn: &BpfInsn,
    scalar_aliases: &mut RegSet,
    packet_ptr_aliases: &mut RegSet,
) {
    let dst = insn.dst_reg();
    if insn.class() == BPF_LDX || insn.class() == BPF_LD || insn.is_ldimm64() {
        scalar_aliases.remove(&dst);
        packet_ptr_aliases.remove(&dst);
        return;
    }
    if matches!(insn.class(), BPF_ALU | BPF_ALU64)
        && bpf_op(insn.code) == BPF_MOV
        && bpf_src(insn.code) == BPF_X
    {
        if scalar_aliases.contains(&insn.src_reg()) {
            scalar_aliases.insert(dst);
        } else {
            scalar_aliases.remove(&dst);
        }
        if insn.class() == BPF_ALU64 && packet_ptr_aliases.contains(&insn.src_reg()) {
            packet_ptr_aliases.insert(dst);
        } else {
            packet_ptr_aliases.remove(&dst);
        }
        return;
    }
    if insn.class() == BPF_ALU64
        && packet_ptr_aliases.contains(&dst)
        && matches!(bpf_op(insn.code), BPF_ADD | BPF_SUB)
    {
        return;
    }
    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && scalar_aliases.contains(&dst) {
        return;
    }
    if insn_use_def_set(insn).defs.contains(&dst) {
        scalar_aliases.remove(&dst);
        packet_ptr_aliases.remove(&dst);
    }
}

fn choose_prefetch_insert_site(
    prog: &ProgramCFG,
    site: PrefetchSite,
    layout: &PrefetchLayout,
) -> anyhow::Result<std::result::Result<InsnSite, String>> {
    if site.source == PrefetchSource::MapValueProfilePoint {
        let insn = prog.insn(site.target)?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Ok(Err(
                "profile prefetch point cannot be control-flow or pseudo func".into(),
            ));
        }
        return Ok(Ok(site.target));
    }
    let window = pf_prefetch_window_sites(
        prog,
        site.ptr_def,
        site.target,
        MAX_PREFETCH_DISTANCE,
        layout,
    )?;
    if window.is_empty() {
        return Ok(Err("no valid prefetch insertion window".into()));
    }
    if let Some(reason) = reject_control_flow_between(prog, &window)? {
        return Ok(Err(reason));
    }
    if let Some(reason) = reject_reg_write_between(prog, &window, site.ptr_reg)? {
        return Ok(Err(reason));
    }
    let Some(insert_site) =
        pf_nearest_prefetch_insert_site(&window, site.target, TARGET_PREFETCH_DISTANCE, layout)?
    else {
        return Ok(Err(
            "prefetch insertion window has no instruction boundary".into()
        ));
    };
    Ok(Ok(insert_site))
}

fn pf_sites_after_in_frame(
    prog: &ProgramCFG,
    anchor: InsnSite,
    max_slots: usize,
    layout: &PrefetchLayout,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(anchor)?;
    let frame = prog.site_frame(anchor)?;
    let scan_start = pf_site_end_offset(prog, anchor, layout)?;
    let scan_end = scan_start
        .checked_add(SlotDistance::from_slots(max_slots))
        .ok_or_else(|| anyhow::anyhow!("prefetch scan after {:?} overflows", anchor))?;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            let site_start = layout.offset(site)?;
            if site_start < scan_start {
                continue;
            }
            if site_start >= scan_end {
                return Ok(sites);
            }
            sites.push(site);
        }
    }
    Ok(sites)
}

fn pf_prefetch_window_sites(
    prog: &ProgramCFG,
    ptr_def: InsnSite,
    target: InsnSite,
    max_slots: usize,
    layout: &PrefetchLayout,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(ptr_def)?;
    prog.insn(target)?;
    let target_block = prog.site_block(target);
    let frame = prog.site_frame(target)?;
    if prog.site_frame(ptr_def)? != frame {
        anyhow::bail!(
            "prefetch pointer definition {:?} and target {:?} are in different frames",
            ptr_def,
            target
        );
    }
    let ptr_def_block = prog.site_block(ptr_def);
    let block_start = first_block_layout_offset(prog, target_block, layout)?;
    let target_start = layout.offset(target)?;
    let ptr_def_end = pf_site_end_offset(prog, ptr_def, layout)?;
    if ptr_def_block == target_block && ptr_def_end > target_start {
        return Ok(Vec::new());
    }
    let pointer_available_start = if ptr_def_end <= target_start {
        ptr_def_end
    } else {
        block_start
    };
    let valid_start = block_start
        .max(target_start.saturating_sub(SlotDistance::from_slots(max_slots)))
        .max(pointer_available_start);
    if valid_start > target_start {
        return Ok(Vec::new());
    }
    let mut sites = Vec::new();
    for site in prog.sites_in_block(target_block)? {
        let site_start = layout.offset(site)?;
        if site_start >= valid_start && site_start <= target_start {
            sites.push(site);
        }
    }
    Ok(sites)
}

fn pf_nearest_prefetch_insert_site(
    sites: &[InsnSite],
    target: InsnSite,
    ideal_distance: usize,
    layout: &PrefetchLayout,
) -> anyhow::Result<Option<InsnSite>> {
    let ideal = layout
        .offset(target)?
        .saturating_sub(SlotDistance::from_slots(ideal_distance));
    let mut best: Option<(SlotDistance, SlotDistance, InsnSite)> = None;
    for &site in sites {
        let site_start = layout.offset(site)?;
        let distance = site_start.abs_diff(ideal);
        if best.is_none_or(|(best_distance, best_start, _)| {
            distance < best_distance || (distance == best_distance && site_start < best_start)
        }) {
            best = Some((distance, site_start, site));
        }
    }
    Ok(best.map(|(_, _, site)| site))
}

fn pf_site_end_offset(
    prog: &ProgramCFG,
    site: InsnSite,
    layout: &PrefetchLayout,
) -> anyhow::Result<SlotDistance> {
    layout
        .offset(site)?
        .checked_add(SlotDistance::from_slots(prog.insn_slot_width(site)?))
        .ok_or_else(|| anyhow::anyhow!("prefetch site {:?} end offset overflows", site))
}

fn first_block_layout_offset(
    prog: &ProgramCFG,
    block: BlockId,
    layout: &PrefetchLayout,
) -> anyhow::Result<SlotDistance> {
    match prog.sites_in_block_with_terminator(block)?.first() {
        Some(&first) => layout.offset(first),
        None => Ok(SlotDistance::ZERO),
    }
}

fn reject_control_flow_between(
    prog: &ProgramCFG,
    window: &[InsnSite],
) -> anyhow::Result<Option<String>> {
    for &site in window {
        let insn = prog.insn(site)?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Ok(Some(format!(
                "prefetch window contains control-flow instruction at {:?}",
                site
            )));
        }
    }
    Ok(None)
}
fn reject_reg_write_between(
    prog: &ProgramCFG,
    window: &[InsnSite],
    reg: u8,
) -> anyhow::Result<Option<String>> {
    for &site in window {
        let insn = prog.insn(site)?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            return Ok(Some(format!(
                "r{reg} is redefined inside the prefetch window at {:?}",
                site
            )));
        }
    }
    Ok(None)
}
fn dedup_candidates(mut candidates: Vec<PrefetchCandidate>) -> Vec<PrefetchCandidate> {
    candidates.sort_by(|a, b| {
        a.insert
            .cmp(&b.insert)
            .then_with(|| a.ptr_def.cmp(&b.ptr_def))
            .then_with(|| a.target.cmp(&b.target))
    });
    let mut kept: Vec<PrefetchCandidate> = Vec::new();
    for candidate in candidates {
        if kept.iter().any(|existing| {
            existing.ptr_reg == candidate.ptr_reg
                && existing.ptr_def == candidate.ptr_def
                && same_prefetch_cacheline(existing.mem_off, candidate.mem_off)
        }) {
            continue;
        }
        kept.push(candidate);
    }
    kept
}

fn same_prefetch_cacheline(a: i16, b: i16) -> bool {
    i32::from(a).div_euclid(64) == i32::from(b).div_euclid(64)
}

fn apply_prefetch_site_budget(
    mut candidates: Vec<PrefetchCandidate>,
    max_sites_per_program: usize,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<Vec<PrefetchCandidate>> {
    if candidates.len() <= max_sites_per_program {
        return Ok(candidates);
    }
    candidates.sort_by(|a, b| {
        prefetch_candidate_rank(a)
            .cmp(&prefetch_candidate_rank(b))
            .then_with(|| a.insert.cmp(&b.insert))
            .then_with(|| a.target.cmp(&b.target))
    });
    let mut kept = Vec::new();
    for candidate in candidates {
        if kept.len() < max_sites_per_program {
            kept.push(candidate);
        } else {
            skipped.push(SiteSkipReason::new(
                candidate.target,
                "prefetch site budget exceeded",
            ));
        }
    }
    Ok(kept)
}

fn prefetch_candidate_rank(candidate: &PrefetchCandidate) -> (u8, u8) {
    let source_rank = match candidate.source {
        PrefetchSource::MapValueProfilePoint => 0,
        PrefetchSource::Packet => 1,
        PrefetchSource::MapValue => 2,
    };
    (source_rank, candidate.dependent_load_depth)
}
