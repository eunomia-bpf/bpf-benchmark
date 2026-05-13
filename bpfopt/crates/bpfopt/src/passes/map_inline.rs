// SPDX-License-Identifier: MIT
use crate::analysis::{
    insn_use_def_set, validate_map_inline_hint_specs, InsnSite, ProgramCFG, Terminator,
};
use crate::insn::*;
use crate::pass::*;
use anyhow::{anyhow, bail, Context, Result};
use serde::Deserialize;
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque};
use std::fmt;
use std::fs;
use std::path::{Path, PathBuf};

const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const CONST_STACK_VALUE_LOOKBACK_LIMIT: usize = 256;
const VALUE_PREVIEW_BYTES: usize = 32;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MapInlineHintMode {
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
    pub mode: MapInlineHintMode,
    pub key: Vec<u8>,
}

/// Pre-loaded map info used by snapshot/offline map providers.
///
/// The pass resolves layout/type information from this data. Mutability
/// is derived from bytecode-level writer helpers and map type rules.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInfo {
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

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
enum MapInlineHintAnchor {
    Site(InsnSite),
    MapName(String),
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInlineHint {
    anchor: MapInlineHintAnchor,
    mode: MapInlineHintMode,
    key: Vec<u8>,
}
pub struct MapInlinePass;
#[derive(Debug)]
struct MapInlineSideInput<'a> {
    map_ids: &'a [u32],
    map_info: &'a HashMap<u32, MapInfo>,
    values: &'a HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: &'a HashMap<u32, CompressedMapValues>,
    inner_map_ids: &'a HashMap<(u32, Vec<u8>), u32>,
    maps_skipped_by_size: &'a HashSet<u32>,
    hints: Vec<MapInlineHint>,
}

impl MapInlinePass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        if !args.is_empty() {
            bail!("map_inline CLI side inputs are parsed at the lift boundary");
        }
        Ok(Box::new(MapInlinePass))
    }
}
fn format_hint_anchor(anchor: &MapInlineHintAnchor) -> String {
    match anchor {
        MapInlineHintAnchor::Site(site) => format!("{site:?}"),
        MapInlineHintAnchor::MapName(name) => name.clone(),
    }
}

fn map_inline_side_input<'a>(
    prog: &ProgramCFG,
    ctx: &'a PassContext,
) -> anyhow::Result<MapInlineSideInput<'a>> {
    if !has_map_inline_side_input(ctx) {
        anyhow::bail!("map_inline side input is missing");
    }
    validate_map_inline_hint_specs(&ctx.map_inline_hints)?;
    Ok(MapInlineSideInput {
        map_ids: &ctx.map_ids,
        map_info: &ctx.map_info,
        values: &ctx.map_values,
        compressed_values: &ctx.map_value_overlays,
        inner_map_ids: &ctx.map_inner_map_ids,
        maps_skipped_by_size: &ctx.map_snapshots_skipped_by_size,
        hints: resolve_map_inline_hint_specs(prog, &ctx.map_inline_hints)?,
    })
}

fn has_map_inline_side_input(ctx: &PassContext) -> bool {
    !ctx.map_ids.is_empty()
        || !ctx.map_info.is_empty()
        || !ctx.map_values.is_empty()
        || !ctx.map_value_overlays.is_empty()
        || !ctx.map_inner_map_ids.is_empty()
        || !ctx.map_snapshots_skipped_by_size.is_empty()
        || !ctx.map_inline_hints.is_empty()
}

fn resolve_map_inline_hint_specs(
    prog: &ProgramCFG,
    hints: &[MapInlineHintSpec],
) -> anyhow::Result<Vec<MapInlineHint>> {
    hints
        .iter()
        .map(|hint| {
            Ok(MapInlineHint {
                anchor: resolve_map_inline_hint_anchor(prog, &hint.anchor)?,
                mode: hint.mode,
                key: hint.key.clone(),
            })
        })
        .collect()
}

fn resolve_map_inline_hint_anchor(
    prog: &ProgramCFG,
    anchor: &MapInlineHintAnchorSpec,
) -> anyhow::Result<MapInlineHintAnchor> {
    match anchor {
        MapInlineHintAnchorSpec::Pc(pc) => {
            let site = prog.original_pc_to_site(*pc).ok_or_else(|| {
                anyhow::anyhow!("map_inline hint pc {pc} is not present in the control-flow graph")
            })?;
            Ok(MapInlineHintAnchor::Site(site))
        }
        MapInlineHintAnchorSpec::MapName(name) => Ok(MapInlineHintAnchor::MapName(name.clone())),
    }
}

fn lookup_value_size(
    side_input: &MapInlineSideInput<'_>,
    info: &MapInfo,
) -> std::result::Result<usize, String> {
    Ok(side_input
        .compressed_values
        .get(&info.map_id)
        .map(|overlay| overlay.value_size)
        .or_else(|| {
            side_input
                .values
                .iter()
                .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
        })
        .unwrap_or(info.value_size as usize))
}
fn lookup_elem(
    side_input: &MapInlineSideInput<'_>,
    map_id: u32,
    key: &[u8],
    value_size: usize,
) -> std::result::Result<Vec<u8>, MapLookupError> {
    if let Some(overlay) = side_input.compressed_values.get(&map_id) {
        return match overlay.lookup(key) {
            Some(value) => {
                if value.len() != value_size {
                    Err(MapLookupError::Failed(format!(
                        "compressed map {} returned value size {}, expected {}",
                        map_id,
                        value.len(),
                        value_size
                    )))
                } else {
                    Ok(value)
                }
            }
            None => Err(MapLookupError::MissingKey {
                map_id,
                key: key.to_vec(),
            }),
        };
    }
    if side_input.maps_skipped_by_size.contains(&map_id) {
        return Err(MapLookupError::SkippedBySize { map_id });
    }
    if let Some(value) = side_input.values.get(&(map_id, key.to_vec())) {
        if value.len() != value_size {
            return Err(MapLookupError::Failed(format!(
                "snapshot map {} returned value size {}, expected {}",
                map_id,
                value.len(),
                value_size
            )));
        }
        return Ok(value.clone());
    }
    if !side_input.map_info.contains_key(&map_id) {
        return Err(MapLookupError::Failed(format!(
            "map_values snapshot has no map info for map {}",
            map_id
        )));
    }
    Err(MapLookupError::MissingKey {
        map_id,
        key: key.to_vec(),
    })
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapLookupSite {
    call_site: InsnSite,
    map_load_site: InsnSite,
}

fn advance_site_queue_to(scan_sites: &mut VecDeque<InsnSite>, target: InsnSite) -> bool {
    while let Some(site) = scan_sites.front().copied() {
        if site == target {
            return true;
        }
        scan_sites.pop_front();
    }
    false
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInMapChain {
    inner_call_site: InsnSite,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct LookupKey {
    bytes: Vec<u8>,
    setup_sites: BTreeSet<InsnSite>,
    used_hint: Option<MapInlineHintAnchor>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct LookupValueLoad {
    site: InsnSite,
    dst_reg: u8,
    size: u8,
    offset: i16,
}
#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct LookupResultUses {
    loads: Vec<LookupValueLoad>,
    other_uses: Vec<InsnSite>,
    alias_copies: Vec<InsnSite>,
    null_check: Option<InsnSite>,
}
#[derive(Clone, Debug)]
struct SnapshotMapValue {
    map_id: u32,
    key: Vec<u8>,
    value: Vec<u8>,
}
#[derive(Clone, Debug)]
struct SiteReplacement {
    site: InsnSite,
    replacement: Vec<BpfInsn>,
}
#[derive(Clone, Debug)]
struct DirectMapValueLoadRewriteResult {
    replacements: Vec<SiteReplacement>,
    sites_applied: usize,
    site_diagnostics: Vec<SiteDiagnostic>,
    records: Vec<MapInlineRecord>,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
struct MapRefKey {
    src_reg: u8,
    imm: i32,
}
fn find_map_lookup_sites(prog: &ProgramCFG) -> anyhow::Result<Vec<MapLookupSite>> {
    let mut sites = Vec::new();
    for block in prog.blocks() {
        for site in prog.sites_in_block(block.id)? {
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            if !is_map_lookup_elem_call(insn) {
                continue;
            }
            if let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, site, 1)? {
                sites.push(MapLookupSite {
                    call_site: site,
                    map_load_site,
                });
            }
        }
    }
    Ok(sites)
}
fn find_map_in_map_chains(
    prog: &ProgramCFG,
    outer_sites: &[MapLookupSite],
) -> anyhow::Result<Vec<MapInMapChain>> {
    outer_sites
        .iter()
        .map(|outer_site| find_map_in_map_chain_for_outer(prog, outer_site))
        .filter_map(|result| match result {
            Ok(Some(chain)) => Some(Ok(chain)),
            Ok(None) => None,
            Err(err) => Some(Err(err)),
        })
        .collect()
}
fn find_map_in_map_chain_for_outer(
    prog: &ProgramCFG,
    outer_site: &MapLookupSite,
) -> anyhow::Result<Option<MapInMapChain>> {
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut null_check = None;
    let mut scan_sites = VecDeque::from(sites_after_in_frame(prog, outer_site.call_site)?);
    while let Some(site) = scan_sites.pop_front() {
        if alias_regs.is_empty() && alias_stack_slots.is_empty() {
            break;
        }
        let insn = prog.insn(site)?;
        let allow_null_check = null_check.is_none();
        if allow_null_check && is_null_check_on_alias(insn, &alias_regs) {
            null_check = Some(site);
            let Some(next_site) = non_null_successor_site(prog, site, insn)? else {
                break;
            };
            if !advance_site_queue_to(&mut scan_sites, next_site) {
                break;
            };
            continue;
        }
        if insn.is_call()
            && insn.src_reg() == 0
            && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
        {
            if alias_regs.get(&1).copied() == Some(0) {
                return Ok(Some(MapInMapChain {
                    inner_call_site: site,
                }));
            }
            break;
        }
        if let Some((dst_reg, alias_off)) = alias_copy(insn, &alias_regs) {
            if alias_off != 0 {
                break;
            }
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            continue;
        }
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn)? {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                continue;
            }
        }
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn)? {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                continue;
            }
        }
        if insn_uses_any_alias(insn, &alias_regs) {
            break;
        }
        kill_defined_alias_regs(&mut alias_regs, insn);
    }
    Ok(None)
}
fn try_extract_lookup_key_verifier_guided(
    prog: &ProgramCFG,
    call_site: InsnSite,
    key_size: u32,
) -> anyhow::Result<std::result::Result<LookupKey, String>> {
    if key_size == 0 {
        return Ok(Err("map key size is zero".to_string()));
    }
    let key_width: usize = key_size
        .try_into()
        .map_err(|_| anyhow::anyhow!("map key size {} does not fit in usize", key_size))?;
    if prog.site_is_dead_code(call_site) {
        return Ok(Err(format!("lookup call at {:?} is dead code", call_site)));
    }
    let Some(bytes) = prog.reg_known_stack_bytes(call_site, BPF_REG_2, key_width) else {
        return Ok(Err(match prog.reg_kind(call_site, BPF_REG_2) {
            Some(RegKind::FramePointer) => format!(
                "lookup call at {:?} has no verifier-proven stack bytes for r2 width {}",
                call_site, key_width
            ),
            Some(kind) => format!(
                "lookup call at {:?} has r2 verifier kind {:?}, expected stack pointer",
                call_site, kind
            ),
            None => format!(
                "lookup call at {:?} has no verifier state for r2",
                call_site
            ),
        }));
    };
    Ok(Ok(LookupKey {
        setup_sites: lookup_key_setup_sites(prog, call_site, key_width)?,
        bytes,
        used_hint: None,
    }))
}
fn constant_key_value(bytes: &[u8]) -> u64 {
    let mut buf = [0u8; 8];
    let copy_len = bytes.len().min(buf.len());
    buf[..copy_len].copy_from_slice(&bytes[..copy_len]);
    u64::from_le_bytes(buf)
}
fn lookup_key_setup_sites(
    prog: &ProgramCFG,
    call_site: InsnSite,
    key_width: usize,
) -> anyhow::Result<BTreeSet<InsnSite>> {
    let mut sites = BTreeSet::new();
    let Some((r2_mov_site, r2_add_site, stack_off)) =
        find_r2_stack_pointer_setup_simple(prog, call_site)?
    else {
        return Ok(sites);
    };
    sites.insert(r2_mov_site);
    sites.insert(r2_add_site);
    collect_lookup_key_stack_store_sites(prog, call_site, stack_off, key_width, &mut sites)?;
    Ok(sites)
}
fn collect_lookup_key_stack_store_sites(
    prog: &ProgramCFG,
    call_site: InsnSite,
    stack_off: i16,
    key_width: usize,
    sites: &mut BTreeSet<InsnSite>,
) -> anyhow::Result<()> {
    let key_width_i32 = i32::try_from(key_width)
        .map_err(|_| anyhow::anyhow!("map key width {} does not fit in i32", key_width))?;
    let target_start = i32::from(stack_off);
    let target_end = target_start
        .checked_add(key_width_i32)
        .ok_or_else(|| anyhow::anyhow!("map key stack range overflows"))?;
    let mut covered = vec![false; key_width];
    for (scanned, site) in sites_before_in_frame_rev(prog, call_site)?
        .into_iter()
        .enumerate()
    {
        if scanned == CONST_STACK_VALUE_LOOKBACK_LIMIT {
            break;
        }
        let insn = prog.insn(site)?;
        let Some((store_off, width)) = resolve_stack_store_slot(prog, site, insn)? else {
            continue;
        };
        let store_start = i32::from(store_off);
        let store_end = store_start + i32::from(width);
        let overlap_start = target_start.max(store_start);
        let overlap_end = target_end.min(store_end);
        if overlap_start >= overlap_end {
            continue;
        }
        for absolute_off in overlap_start..overlap_end {
            let key_idx = usize::try_from(absolute_off - target_start).map_err(|_| {
                anyhow::anyhow!("negative key byte index at stack offset {absolute_off}")
            })?;
            if key_idx < covered.len() {
                covered[key_idx] = true;
            }
        }
        sites.insert(site);
        if covered.iter().all(|covered| *covered) {
            break;
        }
    }
    Ok(())
}
#[derive(Clone, Debug)]
struct SiteRewrite {
    call_site: InsnSite,
    diagnostic_value: String,
    removed_null_check: bool,
    map_inline_records: Vec<MapInlineRecord>,
    skipped_sites: BTreeSet<InsnSite>,
    replacements: Vec<SiteReplacement>,
}
type SiteRewriteResult<T> = anyhow::Result<std::result::Result<T, String>>;
fn site_replacement(
    prog: &ProgramCFG,
    site: InsnSite,
    replacement: Vec<BpfInsn>,
) -> anyhow::Result<SiteReplacement> {
    prog.insn(site)?;
    Ok(SiteReplacement { site, replacement })
}
#[derive(Clone, Debug)]
struct KernelMutableMaps {
    ids: HashSet<u32>,
    reasons: HashMap<u32, String>,
}
#[derive(Clone, Debug)]
struct ResolvedMapInlineHint {
    key_bytes: Vec<u8>,
    value_bytes: Option<Vec<u8>>,
    mode: MapInlineHintMode,
    map_in_map_inner: Option<(u32, u32)>,
    source_anchor: MapInlineHintAnchor,
}
type ResolvedHintMap = HashMap<InsnSite, Vec<ResolvedMapInlineHint>>;
fn hints_for_call_site(
    hints: &ResolvedHintMap,
    call_site: InsnSite,
) -> Option<&[ResolvedMapInlineHint]> {
    hints.get(&call_site).map(Vec::as_slice)
}
fn is_map_lookup_elem_call(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
}
fn collect_kernel_mutable_maps(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
) -> anyhow::Result<KernelMutableMaps> {
    let mut ids = HashSet::new();
    let mut reasons = HashMap::new();
    for metadata in side_input.map_info.values() {
        if lru_lookup_mutates_map(metadata.map_type) {
            ids.insert(metadata.map_id);
            reasons.insert(
                metadata.map_id,
                format!(
                    "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
                    metadata.map_id
                ),
            );
        }
    }
    for site in prog.all_sites() {
        let insn = prog.insn(site)?;
        if is_map_writer_helper_call(insn) {
            let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, site, 1)?
            else {
                continue;
            };
            let helper_name = if insn.imm == libbpf_sys::BPF_FUNC_map_update_elem as i32 {
                "BPF_FUNC_map_update_elem"
            } else if insn.imm == libbpf_sys::BPF_FUNC_map_delete_elem as i32 {
                "BPF_FUNC_map_delete_elem"
            } else if insn.imm == libbpf_sys::BPF_FUNC_map_push_elem as i32 {
                "BPF_FUNC_map_push_elem"
            } else if insn.imm == libbpf_sys::BPF_FUNC_map_pop_elem as i32 {
                "BPF_FUNC_map_pop_elem"
            } else {
                "BPF_FUNC_<non-writer>"
            };
            let info = map_info.get(&map_load_site).ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map reference at {:?} for {helper_name} helper at {:?}",
                    map_load_site,
                    site
                )
            })?;
            ids.insert(info.map_id);
            reasons.insert(
                info.map_id,
                format!(
                    "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={}",
                    info.map_id
                ),
            );
        }
    }
    Ok(KernelMutableMaps { ids, reasons })
}
fn is_map_writer_helper_call(insn: &BpfInsn) -> bool {
    insn.is_call()
        && insn.src_reg() == 0
        && (insn.imm == libbpf_sys::BPF_FUNC_map_update_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_delete_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_push_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_pop_elem as i32)
}
fn lru_lookup_mutates_map(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_LRU_HASH | libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}
fn kernel_mutable_reason_for_map(
    kernel_mutable_maps: &KernelMutableMaps,
    info: &MapInfo,
) -> Option<String> {
    if let Some(reason) = kernel_mutable_maps.reasons.get(&info.map_id) {
        return Some(reason.clone());
    }
    if kernel_mutable_maps.ids.contains(&info.map_id) {
        return Some(format!(
            "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={}",
            info.map_id
        ));
    }
    lru_lookup_mutates_map(info.map_type).then(|| {
        format!(
            "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
            info.map_id
        )
    })
}
fn resolve_inline_hints(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    kernel_mutable_maps: &KernelMutableMaps,
    hints: &[MapInlineHint],
) -> anyhow::Result<ResolvedHintMap> {
    let sites = find_map_lookup_sites(prog)?;
    let mut resolved = ResolvedHintMap::new();
    let mut deferred = Vec::new();
    for hint in hints {
        if !resolve_direct_inline_hint(
            prog,
            side_input,
            map_info,
            kernel_mutable_maps,
            &sites,
            hint,
            &mut resolved,
        )? {
            deferred.push(hint.clone());
        }
    }
    resolve_deferred_inner_hints(
        prog,
        side_input,
        map_info,
        kernel_mutable_maps,
        &sites,
        &deferred,
        &mut resolved,
    )?;
    validate_resolved_site_hint_modes(&resolved)?;
    Ok(resolved)
}
fn resolve_direct_inline_hint(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    hint: &MapInlineHint,
    resolved: &mut ResolvedHintMap,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Site(call_site) => {
            let insn = prog.insn(*call_site)?;
            if !is_map_lookup_elem_call(insn) {
                bail!(
                    "inline hint at site {:?} points at a non-lookup call",
                    call_site
                );
            }
            let Some(site) = sites.iter().find(|site| site.call_site == *call_site) else {
                return Ok(false);
            };
            let info = lookup_site_map_info(map_info, site)?;
            insert_resolved_hint(
                side_input,
                kernel_mutable_maps,
                hint,
                site.call_site,
                info,
                resolved,
            )?;
            Ok(true)
        }
        MapInlineHintAnchor::MapName(name) => {
            let mut map_ids = HashSet::new();
            for info in unique_maps(map_info) {
                let metadata = side_input.map_info.get(&info.map_id).ok_or_else(|| {
                    anyhow::anyhow!(
                        "map_values snapshot has no map info for used map {} while resolving inline hint map_name anchor {name:?}",
                        info.map_id
                    )
                })?;
                if metadata.name == *name {
                    map_ids.insert(info.map_id);
                }
            }
            if map_ids.is_empty() {
                return Ok(false);
            }
            let mut matched = 0usize;
            for site in sites {
                let info = lookup_site_map_info(map_info, site)?;
                if map_ids.contains(&info.map_id) {
                    matched += 1;
                    insert_resolved_hint(
                        side_input,
                        kernel_mutable_maps,
                        hint,
                        site.call_site,
                        info,
                        resolved,
                    )?;
                }
            }
            if matched == 0 {
                bail!(
                    "inline hint map_name anchor {name:?} is present in used_maps but matches no map_lookup_elem site"
                );
            }
            Ok(true)
        }
    }
}
fn resolve_deferred_inner_hints(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    deferred: &[MapInlineHint],
    resolved: &mut ResolvedHintMap,
) -> anyhow::Result<()> {
    if deferred.is_empty() {
        return Ok(());
    }
    let routes = resolve_hinted_map_in_map_routes(prog, side_input, map_info, sites, resolved)?;
    if routes.is_empty() {
        let mut has_map_in_map_outer_hint = false;
        for site in sites {
            if hints_for_call_site(resolved, site.call_site).is_none() {
                continue;
            }
            if lookup_site_map_info(map_info, site)?.is_map_in_map() {
                has_map_in_map_outer_hint = true;
                break;
            }
        }
        let has_known_inner_hint = deferred.iter().try_fold(false, |found, hint| {
            deferred_hint_targets_known_map_in_map_inner(prog, side_input, sites, hint)
                .map(|matches| found || matches)
        })?;
        if has_map_in_map_outer_hint || has_known_inner_hint {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&deferred[0].anchor)
            );
        }
        return Ok(());
    }
    let mut matched = vec![false; deferred.len()];
    for (inner_call_site, inner_info) in &routes {
        for (idx, hint) in deferred.iter().enumerate() {
            let matches_route = match &hint.anchor {
                MapInlineHintAnchor::Site(call_site) => *call_site == *inner_call_site,
                MapInlineHintAnchor::MapName(name) => {
                    map_ids_for_name(side_input, name)?.contains(&inner_info.map_id)
                }
            };
            if !matches_route {
                continue;
            }
            insert_resolved_hint(
                side_input,
                kernel_mutable_maps,
                hint,
                *inner_call_site,
                inner_info,
                resolved,
            )?;
            matched[idx] = true;
        }
    }
    for (idx, hint) in deferred.iter().enumerate() {
        if !matched[idx]
            && deferred_hint_targets_known_map_in_map_inner(prog, side_input, sites, hint)?
        {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&hint.anchor)
            );
        }
    }
    Ok(())
}
fn resolve_hinted_map_in_map_routes(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    sites: &[MapLookupSite],
    resolved: &ResolvedHintMap,
) -> anyhow::Result<Vec<(InsnSite, MapInfo)>> {
    let mut routes = Vec::new();
    for outer_site in sites {
        let outer_info = lookup_site_map_info(map_info, outer_site)?;
        if !outer_info.is_map_in_map() {
            continue;
        }
        let Some(outer_hints) = hints_for_call_site(resolved, outer_site.call_site) else {
            continue;
        };
        for outer_hint in outer_hints {
            let Some((_, inner_map_id)) = outer_hint.map_in_map_inner else {
                continue;
            };
            let encoded_outer_key =
                encode_key_bytes(&outer_hint.key_bytes, outer_info.key_size as usize);
            let inner_info = side_input
                .map_info
                .get(&inner_map_id)
                .cloned()
                .ok_or_else(|| {
                    anyhow::anyhow!(
                        "map_values snapshot has no map info for inner map {} from outer map {} key {}",
                        inner_map_id,
                        outer_info.map_id,
                        format_bytes_preview(&encoded_outer_key)
                    )
                })?;
            let Some(chain) = find_map_in_map_chains(prog, std::slice::from_ref(outer_site))?
                .into_iter()
                .next()
            else {
                continue;
            };
            routes.push((chain.inner_call_site, inner_info));
        }
    }
    Ok(routes)
}
fn deferred_hint_targets_known_map_in_map_inner(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    sites: &[MapLookupSite],
    hint: &MapInlineHint,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Site(call_site) => Ok(find_map_in_map_chains(prog, sites)?
            .iter()
            .any(|chain| chain.inner_call_site == *call_site)),
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = map_ids_for_name(side_input, name)?;
            Ok(map_ids.iter().any(|map_id| {
                side_input
                    .inner_map_ids
                    .values()
                    .any(|inner_map_id| inner_map_id == map_id)
            }))
        }
    }
}
fn map_ids_for_name(
    side_input: &MapInlineSideInput<'_>,
    name: &str,
) -> anyhow::Result<HashSet<u32>> {
    let matched = side_input
        .map_info
        .values()
        .filter(|metadata| metadata.name == name)
        .map(|metadata| metadata.map_id)
        .collect::<HashSet<_>>();
    if matched.is_empty() {
        if !side_input.inner_map_ids.is_empty() {
            bail!("inner inline hint anchor map_name:{name} has no matching map-in-map outer hint");
        }
        bail!("inline hint map_name anchor {name:?} is not present in map_values map info");
    }
    Ok(matched)
}
fn lookup_site_map_info<'a>(
    map_info: &'a MapInfoBySite,
    site: &MapLookupSite,
) -> anyhow::Result<&'a MapInfo> {
    map_info.get(&site.map_load_site).ok_or_else(|| {
        anyhow::anyhow!(
            "map reference info unavailable for lookup site {:?}",
            site.call_site
        )
    })
}
fn insert_resolved_hint(
    side_input: &MapInlineSideInput<'_>,
    kernel_mutable_maps: &KernelMutableMaps,
    hint: &MapInlineHint,
    call_site: InsnSite,
    info: &MapInfo,
    resolved: &mut ResolvedHintMap,
) -> anyhow::Result<()> {
    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, info) {
        bail!(
            "inline hint anchor {} targets kernel-mutable map_id={}: {}",
            format_hint_anchor(&hint.anchor),
            info.map_id,
            reason
        );
    }
    if hint.key.len() != info.key_size as usize {
        bail!(
            "inline hint anchor {} has wrong key size: {} byte(s) for map_id={}, expected {}",
            format_hint_anchor(&hint.anchor),
            hint.key.len(),
            info.map_id,
            info.key_size
        );
    }
    let map_in_map_inner = if info.is_map_in_map() {
        if hint.mode != MapInlineHintMode::Hard {
            bail!(
                "map-in-map outer inline hint anchor {} must use hard fold",
                format_hint_anchor(&hint.anchor)
            );
        }
        let encoded_key = encode_key_bytes(&hint.key, info.key_size as usize);
        let inner_map_id = match resolve_inner_map_id_for_outer_key(side_input, info, &encoded_key)?
        {
            Ok(inner_map_id) => inner_map_id,
            Err(reason) => bail!(
                "inline hint anchor {} key {} for map-in-map outer map_id={}: {}",
                format_hint_anchor(&hint.anchor),
                format_bytes_preview(&hint.key),
                info.map_id,
                reason
            ),
        };
        Some((constant_key_value(&hint.key) as u32, inner_map_id))
    } else {
        None
    };
    let value_bytes = if info.is_map_in_map() || hint.mode == MapInlineHintMode::Soft {
        None
    } else {
        read_hard_hint_value(side_input, info, &hint.key).with_context(|| {
            format!(
                "inline hint anchor {} key {} for map_id={}",
                format_hint_anchor(&hint.anchor),
                format_bytes_preview(&hint.key),
                info.map_id
            )
        })?
    };
    resolved
        .entry(call_site)
        .or_default()
        .push(ResolvedMapInlineHint {
            key_bytes: hint.key.clone(),
            value_bytes,
            mode: hint.mode,
            map_in_map_inner,
            source_anchor: hint.anchor.clone(),
        });
    Ok(())
}
fn read_hard_hint_value(
    side_input: &MapInlineSideInput<'_>,
    info: &MapInfo,
    key: &[u8],
) -> anyhow::Result<Option<Vec<u8>>> {
    let value_size = lookup_value_size(side_input, info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(side_input, info.map_id, key, value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) => {
            if matches!(
                side_input
                    .compressed_values
                    .get(&info.map_id)
                    .map(|overlay| &overlay.kind),
                Some(CompressedMapValuesKind::Enumerated { entries }) if !entries.contains_key(key)
            ) {
                return Ok(None);
            }
            return Err(anyhow::anyhow!(
                "hint key is not present in map dump: map_values snapshot missing map {} key {}",
                info.map_id,
                format_bytes_preview(key)
            ));
        }
        Err(err) => {
            return Err(anyhow::anyhow!(
                "hint key is not present in map dump: {err}"
            ))
        }
    };
    prepare_inline_value(info, &value)
        .map(Some)
        .map_err(anyhow::Error::msg)
}
fn validate_resolved_site_hint_modes(resolved: &ResolvedHintMap) -> anyhow::Result<()> {
    for (call_site, hints) in resolved {
        let hard_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Hard)
            .count();
        let soft_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Soft)
            .count();
        if hard_count > 1 {
            bail!("lookup site {:?} has multiple hard inline hints", call_site);
        }
        if hard_count > 0 && soft_count > 0 {
            bail!(
                "lookup site {:?} mixes soft and hard inline hints",
                call_site
            );
        }
        if soft_count > 1 {
            bail!("lookup site {:?} has multiple soft inline hints", call_site);
        }
    }
    Ok(())
}
macro_rules! skip_lookup {
    ($skipped:expr, $diagnostics:expr, $site:expr, $reason:expr) => {{
        record_skip($skipped, $diagnostics, $site, $reason, None);
        continue;
    }};
    ($skipped:expr, $diagnostics:expr, $site:expr, $reason:expr, $detail:expr) => {{
        record_skip($skipped, $diagnostics, $site, $reason, Some($detail));
        continue;
    }};
}
impl BpfPass for MapInlinePass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let side_input = map_inline_side_input(prog, ctx)?;
        let initial_map_info = analyze_map_info(prog, &side_input)?;
        let initial_kernel_mutable_maps =
            collect_kernel_mutable_maps(prog, &side_input, &initial_map_info)?;
        if prog
            .all_sites()
            .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call))
            && !side_input.hints.is_empty()
            && !side_input.inner_map_ids.is_empty()
            && side_input.map_info.values().any(MapInfo::is_map_in_map)
        {
            anyhow::bail!("kernel-mutable inner map");
        }
        let initial_inline_hints = resolve_inline_hints(
            prog,
            &side_input,
            &initial_map_info,
            &initial_kernel_mutable_maps,
            &side_input.hints,
        )?;
        let mut inline_hints_consumed = HashSet::<MapInlineHintAnchor>::new();
        let mut result = run_map_inline_round(
            prog,
            &side_input,
            &initial_inline_hints,
            &mut inline_hints_consumed,
        )?;
        if !side_input.hints.is_empty() {
            result.diagnostics.push(format!(
                "inline_hints_consumed={}",
                inline_hints_consumed.len()
            ));
        }
        Ok(result)
    }
}

fn run_map_inline_round(
    prog: &mut ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    inline_hints: &ResolvedHintMap,
    inline_hints_consumed: &mut HashSet<MapInlineHintAnchor>,
) -> anyhow::Result<PassResult> {
    let old_len = prog.all_sites().count();
    let branch_target_sites = prog.branch_target_entry_sites()?;
    let map_info = analyze_map_info(prog, side_input)?;
    let kernel_mutable_maps = collect_kernel_mutable_maps(prog, side_input, &map_info)?;
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    let mut site_diagnostics = Vec::new();
    let count = side_input
        .maps_skipped_by_size
        .iter()
        .filter(|map_id| !side_input.compressed_values.contains_key(map_id))
        .count();
    if count > 0 {
        diagnostics.push(format!("maps_skipped_by_size={count}"));
    }
    let DirectMapValueLoadRewriteResult {
        replacements: direct_replacements,
        sites_applied: direct_sites_applied,
        site_diagnostics: direct_site_diagnostics,
        records: direct_records,
    } = build_direct_map_value_load_rewrites(prog, side_input, &kernel_mutable_maps)?;
    site_diagnostics.extend(direct_site_diagnostics);
    let sites = find_map_lookup_sites(prog)?;
    let has_writer = prog
        .all_sites()
        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call));
    if sites.is_empty() && has_writer {
        let writer_reason = side_input
            .map_ids
            .first()
            .copied()
            .or_else(|| side_input.map_info.keys().next().copied())
            .map_or_else(
                || "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on unknown map".to_string(),
                |map_id| format!("map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={map_id}"),
            );
        for site in prog.all_sites() {
            if !prog.insn_at(site).is_some_and(is_map_lookup_elem_call) {
                continue;
            }
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site,
                writer_reason.clone(),
                None,
            );
        }
    }
    for site in sites {
        let Some(info) = map_info.get(&site.map_load_site) else {
            skip_lookup!(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                "map reference info unavailable".to_string()
            );
        };
        if let Some(reason) = kernel_mutable_reason_for_map(&kernel_mutable_maps, info) {
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        let site_inline_hints = hints_for_call_site(inline_hints, site.call_site);
        if map_snapshot_skipped_by_size(side_input, info.map_id)? && site_inline_hints.is_none() {
            let reason = map_snapshot_skipped_by_size_reason(info.map_id);
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        if info.is_map_in_map() {
            if find_map_in_map_chains(prog, std::slice::from_ref(&site))?
                .into_iter()
                .next()
                .is_some()
            {
                skip_lookup!(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "map-in-map chain is not inlineable".to_string()
                );
            }
            if site_inline_hints.is_some() {
                if side_input
                    .inner_map_ids
                    .keys()
                    .any(|(outer_map_id, _)| *outer_map_id == info.map_id)
                    && has_writer
                {
                    anyhow::bail!("kernel-mutable inner map");
                }
                anyhow::bail!(
                    "map-in-map outer map_id={} has no live inner map",
                    info.map_id
                );
            }
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                "map-in-map chain is not inlineable".to_string(),
                None,
            );
            continue;
        }
        let has_hard_null_hint = site_inline_hints
            .and_then(|hints| {
                hints.iter().find(|hint| {
                    hint.mode == MapInlineHintMode::Hard
                        && hint.value_bytes.is_none()
                        && hint.map_in_map_inner.is_none()
                })
            })
            .is_some();
        if has_hard_null_hint {
            let key =
                match extract_site_constant_key(prog, site.call_site, info, site_inline_hints)? {
                    Ok(key) => key,
                    Err(detail) => {
                        skip_lookup!(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            "lookup key is not available from inline hint".into(),
                            detail
                        );
                    }
                };
            if let Some(anchor) = key.used_hint.clone() {
                inline_hints_consumed.insert(anchor);
            }
            if key.bytes.len() < info.key_size as usize {
                let reason = format!(
                    "key width {} is smaller than map key size {}",
                    key.bytes.len(),
                    info.key_size
                );
                skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
            }
            let mut rewrite = match build_hard_null_site_rewrite(prog, &site, &key, info)? {
                Ok(rewrite) => rewrite,
                Err(reason) => {
                    skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
                }
            };
            if rewrite
                .skipped_sites
                .iter()
                .any(|site| branch_target_sites.contains(site))
            {
                site_diagnostics.push(SiteDiagnostic {
                    site: site.call_site,
                    message: "keeping lookup setup because removal would cross a branch target"
                        .to_string(),
                });
                rewrite.skipped_sites.clear();
            }
            rewrites.push(rewrite);
            continue;
        }
        if !info.supports_direct_value_access() {
            skip_lookup!(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                format!("map type {} not inlineable", info.map_type),
                format!(
                    "map_type={}, skip reason: unsupported map type",
                    info.map_type
                )
            );
        }
        let has_soft_hint = match site_inline_hints {
            Some(hints) => hints
                .iter()
                .any(|hint| hint.mode == MapInlineHintMode::Soft),
            None => false,
        };
        if has_soft_hint {
            let Some(site_inline_hints) = site_inline_hints else {
                anyhow::bail!(
                    "soft inline hint disappeared for map lookup {:?}",
                    site.call_site
                );
            };
            if site_inline_hints.is_empty() {
                record_skip(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "soft inline hint emitted no replacement bytecode".to_string(),
                    None,
                );
                continue;
            }
            if site_inline_hints
                .iter()
                .any(|hint| hint.mode != MapInlineHintMode::Soft)
            {
                skip_lookup!(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "soft hint rewrite received a non-soft hint".to_string()
                );
            }
            if info.is_map_in_map() {
                skip_lookup!(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "soft inline hints are not supported for map-in-map outer lookups".to_string()
                );
            }
            if find_soft_fold_null_handler(prog, site.call_site)?.is_none() {
                diagnostics.push("missing immediate null check".to_string());
                skip_lookup!(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "soft fold not applicable: missing null handler".to_string()
                );
            }
            let hint = site_inline_hints
                .iter()
                .find(|hint| hint.mode == MapInlineHintMode::Soft)
                .ok_or_else(|| {
                    anyhow::anyhow!("soft inline hint disappeared for {:?}", site.call_site)
                })?;
            let key = LookupKey {
                bytes: hint.key_bytes.clone(),
                setup_sites: BTreeSet::new(),
                used_hint: Some(hint.source_anchor.clone()),
            };
            if key.bytes.len() < info.key_size as usize {
                let reason = format!(
                    "key width {} is smaller than map key size {}",
                    key.bytes.len(),
                    info.key_size
                );
                skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
            }
            let uses = classify_r0_uses_with_options(prog, site.call_site, false)?;
            if uses.loads.is_empty() {
                let reason =
                    "lookup result is not consumed by fixed-offset scalar loads".to_string();
                skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
            }
            let rewrite =
                match build_site_rewrite(prog, side_input, &site, &key, &uses, info, true)? {
                    Ok(Some(rewrite)) => rewrite,
                    Ok(None) => {
                        skip_lookup!(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            "failed to materialize replacement constants".to_string()
                        );
                    }
                    Err(reason) => {
                        skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
                    }
                };
            if let Some(anchor) = key.used_hint.clone() {
                inline_hints_consumed.insert(anchor);
            }
            rewrites.push(rewrite);
            continue;
        }
        let key = match extract_site_constant_key(prog, site.call_site, info, site_inline_hints)? {
            Ok(key) => key,
            Err(detail) => {
                skip_lookup!(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "lookup key is not available from verifier-guided state".into(),
                    detail
                );
            }
        };
        if let Some(anchor) = key.used_hint.clone() {
            inline_hints_consumed.insert(anchor);
        }
        if key.bytes.len() < info.key_size as usize {
            let reason = format!(
                "key width {} is smaller than map key size {}",
                key.bytes.len(),
                info.key_size
            );
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        if info.has_removable_lookup_pattern()
            && key.bytes.len() <= 8
            && constant_key_value(&key.bytes) >= info.max_entries as u64
        {
            let key_value = constant_key_value(&key.bytes);
            let reason = format!(
                "constant key {} out of range for max_entries {}",
                key_value, info.max_entries
            );
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        let uses = classify_r0_uses_with_options(
            prog,
            site.call_site,
            info.has_removable_lookup_pattern(),
        )?;
        let null_check = uses.null_check;
        if info.requires_entry_presence_check() && null_check.is_none() {
            let reason = "hash map inline requires an immediate null check".to_string();
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        if uses.loads.is_empty() {
            let reason = "lookup result is not consumed by fixed-offset scalar loads".to_string();
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        let mut rewrite =
            match build_site_rewrite(prog, side_input, &site, &key, &uses, info, false)? {
                Ok(Some(rewrite)) => rewrite,
                Ok(None) => {
                    skip_lookup!(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        "failed to materialize replacement constants".to_string()
                    );
                }
                Err(reason) => {
                    skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
                }
            };
        if rewrite
            .skipped_sites
            .iter()
            .any(|site| branch_target_sites.contains(site))
        {
            site_diagnostics.push(SiteDiagnostic {
                site: site.call_site,
                message: "keeping lookup pattern because removal would cross a branch target"
                    .to_string(),
            });
            rewrite.skipped_sites.clear();
            rewrite.removed_null_check = false;
        }
        if rewrite
            .replacements
            .iter()
            .any(|replacement| rewrite.skipped_sites.contains(&replacement.site))
        {
            skip_lookup!(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                "internal rewrite overlap".to_string()
            );
        }
        rewrites.push(rewrite);
    }
    if rewrites.is_empty() && direct_replacements.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            diagnostics,
            site_diagnostics,
            ..PassResult::default()
        });
    }
    let mut skip_sites = BTreeSet::new();
    let mut replacements = direct_replacements;
    let mut replacement_sites = replacements
        .iter()
        .map(|replacement| replacement.site)
        .collect::<BTreeSet<_>>();
    let mut map_inline_records = direct_records;
    let mut applied = direct_sites_applied;
    let mut removed_any_null_check = false;
    for rewrite in rewrites {
        let conflict = rewrite
            .skipped_sites
            .iter()
            .any(|site| replacement_sites.contains(site) || skip_sites.contains(site))
            || rewrite.replacements.iter().any(|replacement| {
                replacement_sites.contains(&replacement.site)
                    || skip_sites.contains(&replacement.site)
            });
        if conflict {
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                rewrite.call_site,
                "overlapping map inline rewrite".to_string(),
                None,
            );
            continue;
        }
        removed_any_null_check |= rewrite.removed_null_check;
        site_diagnostics.push(SiteDiagnostic {
            site: rewrite.call_site,
            message: format!("inlined successfully, value={}", rewrite.diagnostic_value),
        });
        map_inline_records.extend(rewrite.map_inline_records);
        skip_sites.extend(rewrite.skipped_sites);
        replacement_sites.extend(
            rewrite
                .replacements
                .iter()
                .map(|replacement| replacement.site),
        );
        replacements.extend(rewrite.replacements);
        applied += 1;
    }
    if applied == 0 {
        return Ok(PassResult {
            site_skipped: skipped,
            diagnostics,
            site_diagnostics,
            map_inline_records,
            ..PassResult::default()
        });
    }
    let mut result = apply_map_inline_edit(
        prog,
        old_len,
        replacements,
        skip_sites,
        removed_any_null_check,
        applied,
    )?;
    skipped.append(&mut result.site_skipped);
    result.site_skipped = skipped;
    result.diagnostics = diagnostics;
    result.site_diagnostics = site_diagnostics;
    result.map_inline_records = map_inline_records;
    Ok(result)
}
fn apply_map_inline_edit(
    prog: &mut ProgramCFG,
    old_len: usize,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
    cleanup_unreachable: bool,
    sites_applied: usize,
) -> anyhow::Result<PassResult> {
    let mut next = prog.clone();
    let mut skipped = Vec::new();
    if !apply_replacements_and_deletions(&mut next, replacements, skip_sites, &mut skipped)? {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::default()
        });
    }
    if cleanup_unreachable {
        cleanup_map_inline_bbprogram(&mut next)?;
    }
    let new_len = next.all_sites().count();
    *prog = next;
    Ok(PassResult {
        sites_applied,
        site_skipped: skipped,
        insns_before: old_len,
        insns_after: new_len,
        ..Default::default()
    })
}
fn apply_replacements_and_deletions(
    prog: &mut ProgramCFG,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<bool> {
    let mut replacement_by_site = BTreeMap::new();
    for replacement in replacements {
        if skip_sites.contains(&replacement.site) {
            anyhow::bail!(
                "map_inline replacement at {:?} overlaps deletion",
                replacement.site
            );
        }
        let site = replacement.site;
        if replacement_by_site.insert(site, replacement).is_some() {
            anyhow::bail!("map_inline has duplicate replacement for {:?}", site);
        }
    }
    let mut edit_sites = replacement_by_site.keys().copied().collect::<BTreeSet<_>>();
    edit_sites.extend(skip_sites.iter().copied());
    for site in edit_sites.into_iter().rev() {
        if let Some(replacement) = replacement_by_site.remove(&site) {
            if !replace_site(prog, replacement, skipped)? {
                return Ok(false);
            }
        } else if !delete_site(prog, site, skipped)? {
            return Ok(false);
        }
    }
    Ok(true)
}
fn replace_site(
    prog: &mut ProgramCFG,
    replacement: SiteReplacement,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<bool> {
    if replacement.replacement.is_empty() {
        anyhow::bail!("map_inline replacement at {:?} is empty", replacement.site);
    }
    if prog.is_terminator_site(replacement.site)? {
        let terminator =
            terminator_for_site_replacement(prog, replacement.site, &replacement.replacement)?;
        prog.replace_terminator(prog.site_block(replacement.site), terminator)?;
        return Ok(true);
    }
    let site = replacement.site;
    prog.try_replace_range(site, 1, replacement.replacement, skipped)
}
fn delete_site(
    prog: &mut ProgramCFG,
    site: InsnSite,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<bool> {
    if prog.is_terminator_site(site)? {
        let terminator = match prog.terminator_at_site(site)? {
            Terminator::CondBranch { fallthrough, .. } => {
                Terminator::Fallthrough { next: fallthrough }
            }
            Terminator::Jump { target, .. } => Terminator::Fallthrough { next: target },
            Terminator::Fallthrough { next } => Terminator::Fallthrough { next },
            Terminator::Call { .. } | Terminator::Exit { .. } | Terminator::End => {
                anyhow::bail!("map_inline cannot delete terminator at {:?}", site)
            }
        };
        prog.replace_terminator(prog.site_block(site), terminator)?;
        return Ok(true);
    }
    prog.try_replace_range(site, 1, Vec::new(), skipped)
}
fn terminator_for_site_replacement(
    prog: &ProgramCFG,
    site: InsnSite,
    replacement: &[BpfInsn],
) -> anyhow::Result<Terminator> {
    if replacement.len() != 1 {
        anyhow::bail!(
            "map_inline cannot replace exit at {:?} with multiple insns",
            site
        );
    }
    let insn = replacement[0];
    let old = prog.terminator_at_site(site)?;
    if insn.is_ja() {
        let target = match old {
            Terminator::Jump { target, .. } => target,
            Terminator::CondBranch { taken, .. } => taken,
            Terminator::Fallthrough { next } => next,
            _ => anyhow::bail!("map_inline cannot infer JA target for {:?}", site),
        };
        return Ok(Terminator::Jump { insn, target });
    }
    if insn.is_cond_jmp() {
        let Terminator::CondBranch {
            taken, fallthrough, ..
        } = old
        else {
            anyhow::bail!("map_inline cannot infer conditional targets for {:?}", site);
        };
        return Ok(Terminator::CondBranch {
            cond: insn,
            taken,
            fallthrough,
        });
    }
    if insn.is_exit() {
        return Ok(Terminator::Exit { insn });
    }
    anyhow::bail!("map_inline unsupported exit replacement at {:?}", site)
}
fn cleanup_map_inline_bbprogram(prog: &mut ProgramCFG) -> anyhow::Result<()> {
    loop {
        let removed = prog.delete_unreachable_blocks()?;
        if removed == 0 {
            break;
        }
    }
    let ordered_blocks = prog.block_ids().collect::<Vec<_>>();
    let mut nops = Vec::new();
    for block in prog.blocks() {
        if let Terminator::Jump { insn, target } = prog.terminator(block.id)? {
            let linear_target = ordered_blocks
                .windows(2)
                .any(|window| window[0] == block.id && window[1] == target);
            if insn == BpfInsn::nop() || linear_target {
                nops.push((block.id, target));
            }
        }
    }
    for (block, target) in nops {
        prog.replace_terminator(block, Terminator::Fallthrough { next: target })?;
    }
    Ok(())
}
fn extract_site_constant_key(
    prog: &ProgramCFG,
    call_site: InsnSite,
    info: &MapInfo,
    site_inline_hints: Option<&[ResolvedMapInlineHint]>,
) -> anyhow::Result<std::result::Result<LookupKey, String>> {
    if let Some(hint) = site_inline_hints.and_then(|hints| {
        hints
            .iter()
            .find(|hint| hint.mode == MapInlineHintMode::Hard)
    }) {
        let key = LookupKey {
            bytes: hint.key_bytes.clone(),
            setup_sites: lookup_key_setup_sites(prog, call_site, hint.key_bytes.len())?,
            used_hint: Some(hint.source_anchor.clone()),
        };
        return Ok(Ok(key));
    }
    match try_extract_lookup_key_verifier_guided(prog, call_site, info.key_size)? {
        Ok(key) => Ok(Ok(key)),
        Err(verifier_err) => Ok(Err(format!(
            "verifier-guided key extraction failed: {}",
            verifier_err
        ))),
    }
}
fn build_site_rewrite(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    site: &MapLookupSite,
    key: &LookupKey,
    uses: &LookupResultUses,
    info: &MapInfo,
    soft_hint: bool,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let remove_lookup_pattern = !soft_hint && info.has_removable_lookup_pattern();
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let lookup_value_size = lookup_value_size(side_input, info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(side_input, info.map_id, &encoded_key, lookup_value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. })
            if soft_hint || is_hash_like_map_type(info.map_type) =>
        {
            return site_level_inline_veto(format!(
                "map {} has no live entry for key {}",
                info.map_id,
                format_bytes_preview(&encoded_key)
            ));
        }
        Err(MapLookupError::SkippedBySize { map_id }) => {
            return site_level_inline_veto(map_snapshot_skipped_by_size_reason(map_id));
        }
        Err(err) => {
            let detail = err.to_string();
            return Err(anyhow::Error::msg(detail.clone()).context(format!(
                "map_inline requires a concrete snapshot value for map {} key {} at lookup {:?}: {}",
                info.map_id,
                format_bytes_preview(&key.bytes),
                site.call_site,
                detail
            )));
        }
    };
    let inline_value = match prepare_inline_value(info, &value) {
        Ok(value) => value,
        Err(reason) => return site_level_inline_veto(reason),
    };
    let removable_null_check = uses.null_check.filter(|site| {
        prog.insn_at(*site)
            .is_some_and(null_check_is_fallthrough_non_null)
    });
    let mut lookup_pattern_sites = BTreeSet::new();
    if remove_lookup_pattern {
        lookup_pattern_sites.insert(site.call_site);
        lookup_pattern_sites.insert(site.map_load_site);
        lookup_pattern_sites.extend(key.setup_sites.iter().copied());
        if let Some(null_check) = removable_null_check {
            lookup_pattern_sites.insert(null_check);
        }
    }
    if remove_lookup_pattern {
        lookup_pattern_sites.extend(uses.alias_copies.iter().copied());
    }
    let can_remove_lookup_pattern =
        remove_lookup_pattern && uses.other_uses.is_empty() && !lookup_pattern_sites.is_empty();
    let skipped_sites = if can_remove_lookup_pattern {
        lookup_pattern_sites
    } else {
        BTreeSet::new()
    };
    let mut replacements = Vec::new();
    for load in &uses.loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
                anyhow::anyhow!(
                    "map value read out of bounds for load {:?} (offset {}, size {})",
                    load.site,
                    load.offset,
                    load.size
                )
            })?;
        replacements.push(site_replacement(
            prog,
            load.site,
            emit_scalar_const_load(load.dst_reg, scalar, load.size != BPF_DW),
        )?);
    }
    if replacements.is_empty() {
        return Ok(Ok(None));
    }
    Ok(Ok(Some(SiteRewrite {
        call_site: site.call_site,
        diagnostic_value: format_inlined_value_diagnostic(&inline_value, &uses.loads),
        removed_null_check: can_remove_lookup_pattern && removable_null_check.is_some(),
        map_inline_records: vec![MapInlineRecord {
            map_id: info.map_id,
            key: encoded_key,
            value: inline_value,
        }],
        skipped_sites,
        replacements,
    })))
}
fn build_hard_null_site_rewrite(
    prog: &ProgramCFG,
    site: &MapLookupSite,
    key: &LookupKey,
    info: &MapInfo,
) -> SiteRewriteResult<SiteRewrite> {
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let mut skipped_sites = BTreeSet::new();
    skipped_sites.insert(site.map_load_site);
    skipped_sites.extend(key.setup_sites.iter().copied());
    let mut replacements = Vec::new();
    replacements.push(site_replacement(
        prog,
        site.call_site,
        vec![BpfInsn::mov64_imm(0, 0)],
    )?);
    let removed_null_check =
        if let Some(null_check) = find_soft_fold_null_handler(prog, site.call_site)? {
            replacements.push(site_replacement(prog, null_check, vec![BpfInsn::ja(0)])?);
            true
        } else {
            false
        };
    Ok(Ok(SiteRewrite {
        call_site: site.call_site,
        diagnostic_value: format!(
            "NULL map_id={} key={}",
            info.map_id,
            format_bytes_preview(&encoded_key)
        ),
        removed_null_check,
        map_inline_records: Vec::new(),
        skipped_sites,
        replacements,
    }))
}
fn find_soft_fold_null_handler(
    prog: &ProgramCFG,
    call_site: InsnSite,
) -> anyhow::Result<Option<InsnSite>> {
    let sites = sites_after_in_frame(prog, call_site)?;
    let Some(null_check) = sites.first().copied() else {
        return Ok(None);
    };
    if null_check.block != call_site.block {
        return Ok(None);
    }
    let insn = prog.insn(null_check)?;
    if !(null_check_is_fallthrough_non_null(insn) && insn.dst_reg() == 0) {
        return Ok(None);
    }
    if non_null_successor_site(prog, null_check, insn)?.is_none() {
        return Ok(None);
    }
    Ok(Some(null_check))
}
fn resolve_inner_map_id_for_outer_key(
    side_input: &MapInlineSideInput<'_>,
    outer_info: &MapInfo,
    encoded_outer_key: &[u8],
) -> SiteRewriteResult<u32> {
    if let Some(inner_map_id) = side_input
        .inner_map_ids
        .get(&(outer_info.map_id, encoded_outer_key.to_vec()))
        .copied()
    {
        return Ok(Ok(inner_map_id));
    }
    let value_size = lookup_value_size(side_input, outer_info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(side_input, outer_info.map_id, encoded_outer_key, value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) => {
            return site_level_inline_veto(format!(
                "map-in-map outer map {} has no live inner map for key {}",
                outer_info.map_id,
                format_bytes_preview(encoded_outer_key)
            ));
        }
        Err(MapLookupError::SkippedBySize { map_id }) => {
            return site_level_inline_veto(map_snapshot_skipped_by_size_reason(map_id));
        }
        Err(err) => return Err(anyhow::Error::msg(err.to_string())),
    };
    if value.len() < 4 {
        return site_level_inline_veto(format!(
            "map-in-map outer map {} value for key {} is too small to hold inner map id",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key)
        ));
    }
    let bytes = &value[..4];
    let inner_map_id = u32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]]);
    if inner_map_id == 0 {
        return site_level_inline_veto(format!(
            "map-in-map outer map {} has no live inner map for key {}",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key)
        ));
    }
    Ok(Ok(inner_map_id))
}
fn build_direct_map_value_load_rewrites(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    kernel_mutable_maps: &KernelMutableMaps,
) -> anyhow::Result<DirectMapValueLoadRewriteResult> {
    let mut replacements = Vec::new();
    let mut sites_applied = 0usize;
    let mut site_diagnostics = Vec::new();
    let mut map_inline_records = Vec::new();
    let mut map_cache: HashMap<MapRefKey, Option<SnapshotMapValue>> = HashMap::new();
    for block in prog.blocks() {
        for site in prog.sites_in_block(block.id)? {
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            if !insn.is_ldx_mem() {
                continue;
            }
            let origin = match resolve_map_value_pointer_inner(
                prog,
                site,
                insn.src_reg(),
                REG_RESOLUTION_LIMIT,
            ) {
                Ok(origin) => origin,
                Err(err) => return Err(anyhow!(err)),
            };
            let Some((map_ref, value_off)) = origin else {
                continue;
            };
            let Some(total_off) = value_off.checked_add(insn.off as i32) else {
                site_diagnostics.push(SiteDiagnostic {
                    site,
                    message: format!(
                        "pseudo-map-value offset overflow (base {} + load off {})",
                        value_off, insn.off
                    ),
                });
                continue;
            };
            if total_off < 0 {
                site_diagnostics.push(SiteDiagnostic {
                    site,
                    message: format!("pseudo-map-value load offset {} is negative", total_off),
                });
                continue;
            }
            let map_value = match resolve_snapshot_map_value(
                prog,
                side_input,
                map_ref,
                kernel_mutable_maps,
                &mut map_cache,
            )? {
                Some(map_value) => map_value,
                None => continue,
            };
            let offset = total_off as usize;
            let Some(scalar) =
                read_scalar_from_value_at(&map_value.value, offset, bpf_size(insn.code))
            else {
                let size = match size_in_bytes(bpf_size(insn.code)) {
                    Some(size) => size.to_string(),
                    None => "invalid".to_string(),
                };
                site_diagnostics.push(SiteDiagnostic {
                    site,
                    message: format!(
                        "pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                        map_value.map_id, offset, size
                    ),
                });
                continue;
            };
            replacements.push(SiteReplacement {
                site,
                replacement: emit_scalar_const_load(
                    insn.dst_reg(),
                    scalar,
                    bpf_size(insn.code) != BPF_DW,
                ),
            });
            sites_applied += 1;
            map_inline_records.push(MapInlineRecord {
                map_id: map_value.map_id,
                key: map_value.key.clone(),
                value: map_value.value.clone(),
            });
            site_diagnostics.push(SiteDiagnostic {
                site,
                message: format!(
                    "constantized pseudo-map-value load from map_id={} off={} value=0x{:x}",
                    map_value.map_id, offset, scalar
                ),
            });
        }
    }
    Ok(DirectMapValueLoadRewriteResult {
        replacements,
        sites_applied,
        site_diagnostics,
        records: map_inline_records,
    })
}
fn resolve_snapshot_map_value(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_ref: MapRefKey,
    kernel_mutable_maps: &KernelMutableMaps,
    cache: &mut HashMap<MapRefKey, Option<SnapshotMapValue>>,
) -> anyhow::Result<Option<SnapshotMapValue>> {
    if let Some(cached) = cache.get(&map_ref) {
        return Ok(cached.clone());
    }
    let resolved = (|| -> anyhow::Result<Option<SnapshotMapValue>> {
        let Some(map_id) = prog.map_id_for_imm(map_ref.imm) else {
            return Ok(None);
        };
        if map_snapshot_skipped_by_size(side_input, map_id)? {
            return Ok(None);
        }
        let Some(info) = side_input.map_info.get(&map_id).cloned() else {
            return Ok(None);
        };
        if kernel_mutable_reason_for_map(kernel_mutable_maps, &info).is_some() {
            return Ok(None);
        }
        let key = vec![0u8; info.key_size as usize];
        let value_size = lookup_value_size(side_input, &info).map_err(anyhow::Error::msg)?;
        let value = match lookup_elem(side_input, map_id, &key, value_size) {
            Ok(value) => value,
            Err(MapLookupError::MissingKey { .. }) if is_hash_like_map_type(info.map_type) => {
                return Ok(None);
            }
            Err(MapLookupError::SkippedBySize { .. }) => return Ok(None),
            Err(err) => return Err(anyhow::Error::msg(err.to_string())),
        };
        Ok(Some(SnapshotMapValue { map_id, key, value }))
    })();
    let cached = resolved?;
    cache.insert(map_ref, cached.clone());
    Ok(cached)
}
fn encode_key_bytes(bytes: &[u8], key_size: usize) -> Vec<u8> {
    bytes[..key_size].to_vec()
}
fn prepare_inline_value(info: &MapInfo, raw_value: &[u8]) -> Result<Vec<u8>, String> {
    if info.map_type != libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY {
        return Ok(raw_value.to_vec());
    }
    collapse_uniform_percpu_array_value(info.value_size as usize, raw_value)
}
fn collapse_uniform_percpu_array_value(
    value_size: usize,
    raw_value: &[u8],
) -> Result<Vec<u8>, String> {
    if value_size == 0 {
        return Err("per-cpu array has zero value_size".to_string());
    }
    let stride = (value_size + 7) & !7;
    if raw_value.len() < stride || !raw_value.len().is_multiple_of(stride) {
        return Err(format!(
            "per-cpu array lookup blob length {} is inconsistent with slot stride {}",
            raw_value.len(),
            stride
        ));
    }
    let slot_count = raw_value.len() / stride;
    let first_value = raw_value[..value_size].to_vec();
    for slot in 1..slot_count {
        let offset = slot * stride;
        if raw_value[offset..offset + value_size] != first_value[..] {
            return Err(format!(
                "per-cpu array value differs across CPUs for {} slot(s)",
                slot_count
            ));
        }
    }
    Ok(first_value)
}
fn read_scalar_from_value(value: &[u8], offset: i16, size: u8) -> Option<u64> {
    if offset < 0 {
        return None;
    }
    read_scalar_from_value_at(value, offset as usize, size)
}
fn read_scalar_from_value_at(value: &[u8], offset: usize, size: u8) -> Option<u64> {
    let width = size_in_bytes(size)? as usize;
    if offset + width > value.len() {
        return None;
    }
    let mut buf = [0u8; 8];
    buf[..width].copy_from_slice(&value[offset..offset + width]);
    Some(u64::from_le_bytes(buf))
}
fn find_direct_map_load_for_reg_before_site(
    prog: &ProgramCFG,
    site: InsnSite,
    reg: u8,
) -> anyhow::Result<Option<InsnSite>> {
    find_direct_map_load_for_reg_before_site_inner(prog, site, reg, REG_RESOLUTION_LIMIT)
}
fn find_direct_map_load_for_reg_before_site_inner(
    prog: &ProgramCFG,
    site: InsnSite,
    reg: u8,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    let Some(prev) = prog.prev_def_in_frame(site, reg)? else {
        return Ok(None);
    };
    let insn = *prog.insn(prev)?;
    if matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx)) {
        return Ok(Some(prev));
    }
    if insn.is_mov64_reg() {
        return find_direct_map_load_for_reg_before_site_inner(
            prog,
            prev,
            insn.src_reg(),
            budget - 1,
        );
    }
    if insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && insn.src_reg() == 10
    {
        return find_direct_map_load_for_stack_slot_before_site(prog, prev, insn.off, budget - 1);
    }
    Ok(None)
}
fn find_direct_map_load_for_stack_slot_before_site(
    prog: &ProgramCFG,
    site: InsnSite,
    stack_off: i16,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    for prev_site in sites_before_in_frame_rev(prog, site)? {
        let insn = prog.insn(prev_site)?;
        if bpf_mode(insn.code) == BPF_MEM
            && bpf_size(insn.code) == BPF_DW
            && matches!(insn.class(), BPF_ST | BPF_STX)
            && insn.dst_reg() == 10
            && insn.off == stack_off
        {
            if insn.class() != BPF_STX {
                return Ok(None);
            }
            return find_direct_map_load_for_reg_before_site_inner(
                prog,
                prev_site,
                insn.src_reg(),
                budget - 1,
            );
        }
    }
    Ok(None)
}
fn site_level_inline_veto<T>(reason: impl Into<String>) -> SiteRewriteResult<T> {
    Ok(Err(reason.into()))
}
fn is_hash_like_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}
fn find_r2_stack_pointer_setup_simple(
    prog: &ProgramCFG,
    call_site: InsnSite,
) -> anyhow::Result<Option<(InsnSite, InsnSite, i16)>> {
    let Some((r2_add_site, scanned)) =
        find_prev_def_within(prog, call_site, 2, R2_SETUP_LOOKBACK_LIMIT)?
    else {
        return Ok(None);
    };
    let add = prog.insn(r2_add_site)?;
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return Ok(None);
    }
    let remaining = R2_SETUP_LOOKBACK_LIMIT.saturating_sub(scanned);
    let Some((r2_mov_site, _)) = find_prev_def_within(prog, r2_add_site, 2, remaining)? else {
        return Ok(None);
    };
    let mov = prog.insn(r2_mov_site)?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return Ok(None);
    }
    let stack_off = i16::try_from(add.imm)
        .map_err(|_| anyhow::anyhow!("r2 stack add immediate {} does not fit i16", add.imm))?;
    Ok(Some((r2_mov_site, r2_add_site, stack_off)))
}
fn find_prev_def_within(
    prog: &ProgramCFG,
    start: InsnSite,
    reg: u8,
    limit: usize,
) -> anyhow::Result<Option<(InsnSite, usize)>> {
    for (scanned, site) in sites_before_in_frame_rev(prog, start)?
        .into_iter()
        .enumerate()
    {
        if scanned >= limit {
            break;
        }
        if insn_use_def_set(prog.insn(site)?).defs.contains(&reg) {
            return Ok(Some((site, scanned + 1)));
        }
    }
    Ok(None)
}
fn size_in_bytes(size: u8) -> Option<u8> {
    BpfMemWidth::from_size_opcode(size).map(|w| w.bytes() as u8)
}
fn resolve_map_value_pointer_inner(
    prog: &ProgramCFG,
    before_site: InsnSite,
    reg: u8,
    budget: usize,
) -> Result<Option<(MapRefKey, i32)>, String> {
    if budget == 0 {
        return Err(format!(
            "map-value pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    let Some(site) = prog
        .prev_def_in_frame(before_site, reg)
        .map_err(|err| err.to_string())?
    else {
        return Ok(None);
    };
    let insn = *prog.insn(site).map_err(|err| err.to_string())?;
    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if matches!(
            insn.map_pseudo(),
            Some(MapPseudo::FdValue | MapPseudo::IdxValue)
        ) {
            let value_off = prog
                .ldimm64_second_slot(site)
                .ok_or_else(|| format!("pseudo-map-value load at {:?} is truncated", site))?
                .imm;
            return Ok(Some((
                MapRefKey {
                    src_reg: insn.src_reg(),
                    imm: insn.imm,
                },
                value_off,
            )));
        }
        return Ok(None);
    }
    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);
        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_map_value_pointer_inner(prog, site, insn.src_reg(), budget - 1);
        }
        if matches!(op, BPF_ADD | BPF_SUB) && src_mode == BPF_K {
            let Some((map_ref, value_off)) =
                resolve_map_value_pointer_inner(prog, site, reg, budget - 1)?
            else {
                return Ok(None);
            };
            let delta = insn.imm as i64;
            let signed_delta = if op == BPF_SUB { -delta } else { delta };
            let value_off = value_off as i64 + signed_delta;
            let value_off = i32::try_from(value_off).map_err(|_| {
                format!(
                    "resolved pseudo-map-value offset {} from r{} does not fit in i32",
                    value_off, reg
                )
            })?;
            return Ok(Some((map_ref, value_off)));
        }
    }
    Ok(None)
}

fn map_snapshot_skipped_by_size(
    side_input: &MapInlineSideInput<'_>,
    map_id: u32,
) -> anyhow::Result<bool> {
    Ok(side_input.maps_skipped_by_size.contains(&map_id)
        && !side_input.compressed_values.contains_key(&map_id))
}
fn map_snapshot_skipped_by_size_reason(map_id: u32) -> String {
    format!("map {map_id} snapshot skipped by size and no overlay provided")
}
fn record_skip(
    skipped: &mut Vec<SiteSkipReason>,
    diagnostics: &mut Vec<SiteDiagnostic>,
    site: InsnSite,
    reason: String,
    detail: Option<String>,
) {
    skipped.push(SiteSkipReason {
        site,
        reason: reason.clone(),
    });
    diagnostics.push(SiteDiagnostic {
        site,
        message: format!("skip reason: {reason}"),
    });
    if let Some(detail) = detail {
        diagnostics.push(SiteDiagnostic {
            site,
            message: detail,
        });
    }
}
fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = format!("0x{}", hex_bytes(&bytes[..preview_len]));
    if bytes.len() > preview_len {
        out.push_str("...");
    }
    out
}
fn format_inlined_value_diagnostic(value: &[u8], loads: &[LookupValueLoad]) -> String {
    if loads.len() == 1 {
        let load = &loads[0];
        if let Some(scalar) = read_scalar_from_value(value, load.offset, load.size) {
            return format!("0x{scalar:x}");
        }
    }
    format_bytes_preview(value)
}
fn classify_r0_uses_with_options(
    prog: &ProgramCFG,
    start_site: InsnSite,
    allow_helper_calls: bool,
) -> anyhow::Result<LookupResultUses> {
    let mut classification = LookupResultUses::default();
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut scan_sites = VecDeque::from(sites_after_in_frame(prog, start_site)?);
    while let Some(site) = scan_sites.pop_front() {
        if alias_regs.is_empty() && alias_stack_slots.is_empty() {
            break;
        }
        let insn = prog.insn(site)?;
        let alias_copy = alias_copy(insn, &alias_regs);
        let allow_null_check =
            classification.loads.is_empty() && classification.other_uses.is_empty();
        if let Some((dst_reg, alias_off)) = alias_copy {
            classification.alias_copies.push(site);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            continue;
        }
        if let Some(alias_off) = alias_adjustment(insn, &alias_regs) {
            classification.alias_copies.push(site);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(insn.dst_reg(), alias_off);
            continue;
        }
        if allow_null_check
            && classification.null_check.is_none()
            && is_null_check_on_alias(insn, &alias_regs)
        {
            classification.null_check = Some(site);
            let Some(next_site) = non_null_successor_site(prog, site, insn)? else {
                break;
            };
            if !advance_site_queue_to(&mut scan_sites, next_site) {
                break;
            };
            continue;
        }
        if !classification.loads.is_empty()
            && alias_stack_slots.is_empty()
            && ends_current_use_region(insn, &alias_regs)
        {
            break;
        }
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn)? {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                classification.alias_copies.push(site);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                continue;
            }
        }
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn)? {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                classification.alias_copies.push(site);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                continue;
            }
        }
        if insn.is_call() {
            if insn_uses_any_alias(insn, &alias_regs) {
                classification.other_uses.push(site);
                break;
            }
            let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
            if allow_helper_calls
                && (!surviving_aliases.is_empty() || !alias_stack_slots.is_empty())
            {
                alias_regs = surviving_aliases;
                continue;
            }
            let has_unfollowed_aliases = !surviving_aliases.is_empty();
            alias_regs.clear();
            if !alias_stack_slots.is_empty() {
                continue;
            }
            if has_unfollowed_aliases {
                classification.other_uses.push(site);
                break;
            }
            break;
        }
        if insn.is_exit() {
            break;
        }
        if insn.is_ldx_mem() && alias_regs.contains_key(&insn.src_reg()) {
            let total_off = i32::from(alias_regs[&insn.src_reg()]) + i32::from(insn.off);
            let Ok(total_off) = i16::try_from(total_off) else {
                classification.other_uses.push(site);
                kill_defined_alias_regs(&mut alias_regs, insn);
                continue;
            };
            classification.loads.push(LookupValueLoad {
                site,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: total_off,
            });
        } else if insn_uses_any_alias(insn, &alias_regs) {
            classification.other_uses.push(site);
        }
        kill_defined_alias_regs(&mut alias_regs, insn);
    }
    Ok(classification)
}
fn resolve_stack_store_slot(
    prog: &ProgramCFG,
    site: InsnSite,
    insn: &BpfInsn,
) -> anyhow::Result<Option<(i16, u8)>> {
    if bpf_mode(insn.code) != BPF_MEM {
        return Ok(None);
    }
    let Some(width) = size_in_bytes(bpf_size(insn.code)) else {
        return Ok(None);
    };
    if !(insn.class() == BPF_ST || insn.class() == BPF_STX) {
        return Ok(None);
    }
    let base_stack_off = match prog.reg_fact_at(site, insn.dst_reg())?.as_fp_off() {
        Some(off) => match i16::try_from(off) {
            Ok(off) => off,
            Err(_) => return Ok(None),
        },
        None => return Ok(None),
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let stack_off = match i16::try_from(stack_off) {
        Ok(stack_off) => stack_off,
        Err(_) => return Ok(None),
    };
    Ok(Some((stack_off, width)))
}
fn resolve_stack_load_slot(
    prog: &ProgramCFG,
    site: InsnSite,
    insn: &BpfInsn,
) -> anyhow::Result<Option<i16>> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return Ok(None);
    }
    let base_stack_off = match prog.reg_fact_at(site, insn.src_reg())?.as_fp_off() {
        Some(off) => match i16::try_from(off) {
            Ok(off) => off,
            Err(_) => return Ok(None),
        },
        None => return Ok(None),
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let Ok(stack_off) = i16::try_from(stack_off) else {
        return Ok(None);
    };
    Ok(Some(stack_off))
}
fn kill_overlapping_alias_stack_slots(
    alias_stack_slots: &mut HashMap<i16, i16>,
    stack_off: i16,
    width: u8,
) {
    let store_start = i32::from(stack_off);
    let store_end = store_start + i32::from(width);
    alias_stack_slots.retain(|slot, _| {
        let alias_start = i32::from(*slot);
        let alias_end = alias_start + 8;
        store_end <= alias_start || store_start >= alias_end
    });
}
fn surviving_alias_regs_after_helper_call(alias_regs: &HashMap<u8, i16>) -> HashMap<u8, i16> {
    alias_regs
        .iter()
        .filter(|(reg, _)| (6u8..=9u8).contains(reg))
        .map(|(&reg, &off)| (reg, off))
        .collect()
}
fn non_null_successor_site(
    prog: &ProgramCFG,
    null_check: InsnSite,
    insn: &BpfInsn,
) -> anyhow::Result<Option<InsnSite>> {
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator_at_site(null_check)?
    else {
        return Ok(None);
    };
    let non_null_block = match bpf_op(insn.code) {
        BPF_JEQ => fallthrough,
        BPF_JNE => taken,
        _ => return Ok(None),
    };
    prog.first_site_in_block(non_null_block)
}
fn ends_current_use_region(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    (insn.is_jmp_class()
        && !insn.is_call()
        && !insn.is_exit()
        && !insn_uses_any_alias(insn, alias_regs))
        || matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx))
}
fn alias_copy(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> Option<(u8, i16)> {
    insn.is_mov64_reg()
        .then(|| {
            alias_regs
                .get(&insn.src_reg())
                .copied()
                .map(|off| (insn.dst_reg(), off))
        })
        .flatten()
}
fn alias_adjustment(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> Option<i16> {
    if insn.class() != BPF_ALU64 {
        return None;
    }
    let base_off = i32::from(*alias_regs.get(&insn.dst_reg())?);
    let delta = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_ADD, BPF_K) => insn.imm as i64,
        (BPF_SUB, BPF_K) => -(insn.imm as i64),
        _ => return None,
    };
    let Ok(adjusted) = i16::try_from(base_off as i64 + delta) else {
        return None;
    };
    Some(adjusted)
}
fn is_null_check_on_alias(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    let op = bpf_op(insn.code);
    insn.class() == BPF_JMP
        && matches!(op, BPF_JEQ | BPF_JNE)
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && (op == BPF_JEQ || insn.off >= 0)
        && alias_regs.get(&insn.dst_reg()).copied() == Some(0)
}
fn null_check_is_fallthrough_non_null(insn: &BpfInsn) -> bool {
    insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
}
fn insn_uses_any_alias(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    let use_def = insn_use_def_set(insn);
    alias_regs
        .keys()
        .copied()
        .any(|reg| use_def.uses.contains(&reg))
}
fn kill_defined_alias_regs(alias_regs: &mut HashMap<u8, i16>, insn: &BpfInsn) {
    let use_def = insn_use_def_set(insn);
    alias_regs.retain(|reg, _| !use_def.defs.contains(reg));
}

pub fn attach_cli_side_input(ctx: &mut PassContext, pass_args: &[String]) -> Result<()> {
    let cli = MapInlineCliArgs::parse(pass_args)?;
    let map_ids = cli.map_ids()?;
    let snapshot = read_map_values(&cli.map_values, &map_ids)?;
    ctx.map_ids = map_ids;
    ctx.map_info = snapshot.map_info;
    ctx.map_values = snapshot.values;
    ctx.map_value_overlays = snapshot.compressed_values;
    ctx.map_inner_map_ids = snapshot.inner_map_ids;
    ctx.map_snapshots_skipped_by_size = snapshot.maps_skipped_by_size;
    ctx.map_inline_hints = cli.inline_hints;
    Ok(())
}

struct MapInlineCliArgs {
    map_values: PathBuf,
    map_ids: Option<String>,
    inline_hints: Vec<MapInlineHintSpec>,
}

impl MapInlineCliArgs {
    fn parse(args: &[String]) -> Result<Self> {
        let mut map_values = None;
        let mut map_ids = None;
        let mut inline_hints = Vec::new();
        let mut iter = args.iter();
        while let Some(arg) = iter.next() {
            if let Some(value) = arg.strip_prefix("--inline-hint=") {
                inline_hints.push(parse_inline_hint(value)?);
                continue;
            }
            match arg.as_str() {
                "--map-values" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow!("--map-values requires DIR"))?;
                    map_values = Some(PathBuf::from(value));
                }
                "--map-ids" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow!("--map-ids requires LIST"))?;
                    map_ids = Some(value.clone());
                }
                "--inline-hint" => {
                    let value = iter.next().ok_or_else(|| {
                        anyhow!("--inline-hint requires <anchor>:[!]<hex_key_bytes>")
                    })?;
                    inline_hints.push(parse_inline_hint(value)?);
                }
                other => bail!("map_inline unknown pass-local arg: {other}"),
            }
        }
        validate_map_inline_hint_specs(&inline_hints)?;
        Ok(Self {
            map_values: map_values.ok_or_else(|| anyhow!("map_inline requires --map-values"))?,
            map_ids,
            inline_hints,
        })
    }

    fn map_ids(&self) -> Result<Vec<u32>> {
        self.map_ids
            .as_deref()
            .ok_or_else(|| anyhow!("map_inline requires --map-ids"))
            .and_then(parse_map_ids_arg)
    }
}

fn parse_inline_hint(input: &str) -> Result<MapInlineHintSpec> {
    let (anchor_str, key_str) = input.split_once(':').ok_or_else(|| {
        anyhow!("invalid --inline-hint '{input}': expected <anchor>:[!]<hex_key_bytes>")
    })?;
    let anchor = parse_inline_hint_anchor(anchor_str)
        .with_context(|| format!("invalid --inline-hint anchor in '{input}'"))?;
    let (mode, hex_str) = if let Some(hex) = key_str.strip_prefix('!') {
        (MapInlineHintMode::Hard, hex)
    } else {
        (MapInlineHintMode::Soft, key_str)
    };
    let key = parse_inline_hint_hex(hex_str)
        .with_context(|| format!("invalid --inline-hint key bytes in '{input}'"))?;
    Ok(MapInlineHintSpec { anchor, mode, key })
}

fn parse_inline_hint_anchor(input: &str) -> Result<MapInlineHintAnchorSpec> {
    if input.is_empty() {
        bail!("anchor is empty");
    }
    if input.bytes().all(|byte| byte.is_ascii_digit()) {
        let pc = input
            .parse::<usize>()
            .with_context(|| format!("invalid call_pc anchor {input:?}"))?;
        return Ok(MapInlineHintAnchorSpec::Pc(pc));
    }
    let first = input.as_bytes()[0];
    if !(first.is_ascii_alphabetic() || first == b'_') {
        bail!("map-name anchor must start with a letter or underscore");
    }
    if !input
        .bytes()
        .skip(1)
        .all(|byte| byte.is_ascii_alphanumeric() || byte == b'_')
    {
        bail!("map-name anchor must contain only ASCII letters, digits, and underscores");
    }
    Ok(MapInlineHintAnchorSpec::MapName(input.to_string()))
}

fn parse_inline_hint_hex(input: &str) -> Result<Vec<u8>> {
    if !input.len().is_multiple_of(2) {
        bail!("hex string must have an even number of digits");
    }
    input
        .as_bytes()
        .chunks_exact(2)
        .map(|pair| {
            let hi = hex_nibble(pair[0])
                .ok_or_else(|| anyhow!("invalid hex digit '{}'", char::from(pair[0])))?;
            let lo = hex_nibble(pair[1])
                .ok_or_else(|| anyhow!("invalid hex digit '{}'", char::from(pair[1])))?;
            Ok((hi << 4) | lo)
        })
        .collect()
}

fn hex_nibble(byte: u8) -> Option<u8> {
    match byte {
        b'0'..=b'9' => Some(byte - b'0'),
        b'a'..=b'f' => Some(byte - b'a' + 10),
        b'A'..=b'F' => Some(byte - b'A' + 10),
        _ => None,
    }
}

#[derive(Clone)]
struct MapSnapshot {
    map_info: HashMap<u32, MapInfo>,
    values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: HashMap<u32, CompressedMapValues>,
    inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    maps_skipped_by_size: HashSet<u32>,
}

#[derive(Debug, Deserialize)]
struct ProgInfoMapIdsJson {
    #[serde(default)]
    map_ids: Vec<u32>,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapShowJson {
    id: u32,
    #[serde(default)]
    name: String,
    #[serde(rename = "type")]
    map_type: MapTypeJson,
    bytes_key: u32,
    bytes_value: u32,
    max_entries: u32,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapEntryJson {
    key: Vec<String>,
    #[serde(default)]
    value: Option<BpftoolMapValueJson>,
    #[serde(default)]
    values: Vec<BpftoolPerCpuValueJson>,
    #[serde(default)]
    inner_map_id: Option<u32>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum InnerMapIdJson {
    Number(u32),
    String(String),
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct BpftoolMapDumpSkipMarker {
    skipped: bool,
    reason: String,
    size_bytes: u64,
    limit_bytes: u64,
}

enum BpftoolMapDumpSnapshot {
    Entries(Vec<BpftoolMapEntryJson>),
    Compressed(CompressedMapValues),
    SkippedBySize,
}

#[derive(Debug, Deserialize)]
struct BpftoolPerCpuValueJson {
    value: Vec<String>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum BpftoolMapValueJson {
    Bytes(Vec<String>),
    Error { error: String },
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct CompressedMapValuesJson {
    compression: String,
    value_size: usize,
    #[serde(default)]
    value_hex: Option<String>,
    #[serde(default)]
    default_hex: Option<String>,
    #[serde(default)]
    entries: Option<serde_json::Value>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum MapTypeJson {
    Number(u32),
    Name(String),
}

fn read_map_values(path: &Path, map_ids: &[u32]) -> Result<MapSnapshot> {
    if !path.is_dir() {
        bail!(
            "--map-values must point to a bpftool snapshot directory, got {}",
            path.display()
        );
    }
    let mut metadata = HashMap::new();
    let mut values = HashMap::new();
    let mut compressed_values = HashMap::new();
    let mut inner_map_ids = HashMap::new();
    let mut maps_skipped_by_size = HashSet::new();
    let mut empty_lpm_trie_maps = HashSet::new();
    for &map_id in map_ids.iter().filter(|&&map_id| map_id != 0) {
        let show = read_bpftool_map_show(path, map_id)?;
        let map_type = parse_map_type(&show.map_type)?;
        let map_info = MapInfo {
            map_type,
            key_size: show.bytes_key,
            value_size: show.bytes_value,
            max_entries: show.max_entries,
            map_id: show.id,
            name: show.name,
        };
        if needs_bpftool_map_dump(map_type) {
            match read_bpftool_map_dump(path, show.id, &map_info)? {
                BpftoolMapDumpSnapshot::Entries(entries) => {
                    if entries.is_empty() && map_info.map_type == libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
                    {
                        empty_lpm_trie_maps.insert(show.id);
                    }
                    for entry in entries {
                        let key = decode_bpftool_hex_bytes(&entry.key)
                            .with_context(|| format!("invalid key bytes for map {}", show.id))?;
                        let value = decode_bpftool_entry_value(&entry, &map_info)
                            .with_context(|| format!("invalid value bytes for map {}", show.id))?;
                        values.insert((show.id, key.clone()), value);
                        if let Some(inner_map_id) = entry.inner_map_id {
                            inner_map_ids.insert((show.id, key), inner_map_id);
                        }
                    }
                }
                BpftoolMapDumpSnapshot::Compressed(compressed) => {
                    if values.keys().any(|(map_id, _)| *map_id == show.id) {
                        bail!(
                            "map {} has both raw entries and compression overlay",
                            show.id
                        );
                    }
                    compressed_values.insert(show.id, compressed);
                }
                BpftoolMapDumpSnapshot::SkippedBySize => {
                    maps_skipped_by_size.insert(show.id);
                }
            }
            read_inner_map_ids_supplement(
                path,
                show.id,
                map_info.key_size as usize,
                &mut inner_map_ids,
            )?;
        }
        metadata.insert(show.id, map_info);
    }
    read_optional_compressed_overlay_file(path, &metadata, &values, &mut compressed_values)?;
    synthesize_empty_lpm_trie_overlays(&empty_lpm_trie_maps, &metadata, &mut compressed_values)?;
    Ok(MapSnapshot {
        map_info: metadata,
        values,
        compressed_values,
        inner_map_ids,
        maps_skipped_by_size,
    })
}

fn read_bpftool_map_show(path: &Path, map_id: u32) -> Result<BpftoolMapShowJson> {
    let show_path = path.join(format!("map-{map_id}.show.json"));
    let show: BpftoolMapShowJson = read_json_file(&show_path, "bpftool map show JSON")?;
    if show.id != map_id {
        bail!(
            "{} contains map id {}, expected {}",
            show_path.display(),
            show.id,
            map_id
        );
    }
    Ok(show)
}

fn read_bpftool_map_dump(
    path: &Path,
    map_id: u32,
    metadata: &MapInfo,
) -> Result<BpftoolMapDumpSnapshot> {
    let dump_path = path.join(format!("map-{map_id}.dump.json"));
    let data =
        fs::read(&dump_path).with_context(|| format!("failed to read {}", dump_path.display()))?;
    let Some(first) = data
        .iter()
        .copied()
        .find(|byte| !byte.is_ascii_whitespace())
    else {
        bail!("{} is empty", dump_path.display());
    };
    match first {
        b'[' => {
            let entries = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump JSON from {}",
                    dump_path.display()
                )
            })?;
            Ok(BpftoolMapDumpSnapshot::Entries(entries))
        }
        b'{' => {
            let value: serde_json::Value = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump object from {}",
                    dump_path.display()
                )
            })?;
            if value.get("compression").is_some() {
                let compressed = parse_compressed_map_values_json(map_id, metadata, value)
                    .with_context(|| {
                        format!(
                            "failed to parse compressed map overlay {}",
                            dump_path.display()
                        )
                    })?;
                return Ok(BpftoolMapDumpSnapshot::Compressed(compressed));
            }
            let marker: BpftoolMapDumpSkipMarker =
                serde_json::from_value(value).with_context(|| {
                    format!(
                        "failed to parse bpftool map dump skip marker from {}",
                        dump_path.display()
                    )
                })?;
            if !marker.skipped
                || marker.reason != "size_limit"
                || marker.size_bytes <= marker.limit_bytes
            {
                bail!(
                    "unexpected bpftool map dump skip marker in {}",
                    dump_path.display()
                );
            }
            Ok(BpftoolMapDumpSnapshot::SkippedBySize)
        }
        _ => bail!(
            "{} is neither a bpftool map dump array nor a skip marker object",
            dump_path.display()
        ),
    }
}

fn read_inner_map_ids_supplement(
    path: &Path,
    map_id: u32,
    key_size: usize,
    inner_map_ids: &mut HashMap<(u32, Vec<u8>), u32>,
) -> Result<()> {
    let supplement_path = path.join(format!("map-{map_id}.inner_map_ids.json"));
    let data = match fs::read(&supplement_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err)
                .with_context(|| format!("failed to read {}", supplement_path.display()));
        }
    };
    let supplement: HashMap<String, HashMap<String, InnerMapIdJson>> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse inner_map_id supplement from {}",
                supplement_path.display()
            )
        })?;
    let expected_map_id = map_id.to_string();
    for present_map_id in supplement.keys() {
        if present_map_id != &expected_map_id {
            bail!(
                "{} contains inner_map_id table for map {}, expected only {}",
                supplement_path.display(),
                present_map_id,
                expected_map_id
            );
        }
    }
    let entries = supplement.get(&expected_map_id).ok_or_else(|| {
        anyhow!(
            "{} does not contain inner_map_id table for map {}",
            supplement_path.display(),
            map_id
        )
    })?;
    for (key_hex, inner_map_id_json) in entries {
        let key = decode_fixed_hex_bytes(map_id, "inner_map_id supplement key", key_hex, key_size)?;
        let inner_map_id = match inner_map_id_json {
            InnerMapIdJson::Number(number) => *number,
            InnerMapIdJson::String(text) => text.parse::<u32>().with_context(|| {
                format!("map {map_id} inner_map_id supplement entry {key_hex:?} is not a u32 id")
            })?,
        };
        if inner_map_id == 0 {
            bail!(
                "map {map_id} inner_map_id supplement entry {key_hex:?} has id 0; omit NULL entries"
            );
        }
        inner_map_ids.insert((map_id, key), inner_map_id);
    }
    Ok(())
}

fn read_optional_compressed_overlay_file(
    path: &Path,
    metadata: &HashMap<u32, MapInfo>,
    raw_values: &HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    let overlay_path = path.join("overlays.json");
    let data = match fs::read(&overlay_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err).with_context(|| format!("failed to read {}", overlay_path.display()));
        }
    };
    let overlays: HashMap<String, serde_json::Value> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse compressed map overlays from {}",
                overlay_path.display()
            )
        })?;
    for (map_id_text, overlay) in overlays {
        let map_id = map_id_text
            .parse::<u32>()
            .with_context(|| format!("invalid compressed overlay map id {map_id_text:?}"))?;
        let map_info = metadata.get(&map_id).ok_or_else(|| {
            anyhow!(
                "compressed overlay references map {} not present in --map-ids map info",
                map_id
            )
        })?;
        if raw_values
            .keys()
            .any(|(raw_map_id, _)| *raw_map_id == map_id)
        {
            bail!("map {map_id} has both raw entries and compression overlay");
        }
        let compressed = parse_compressed_map_values_json(map_id, map_info, overlay)
            .map_err(|err| anyhow!("invalid compressed overlay for map {map_id}: {err}"))?;
        if compressed_values.insert(map_id, compressed).is_some() {
            bail!("map {map_id} has duplicate compression overlays");
        }
    }
    Ok(())
}

fn synthesize_empty_lpm_trie_overlays(
    empty_lpm_trie_maps: &HashSet<u32>,
    metadata: &HashMap<u32, MapInfo>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    for map_id in empty_lpm_trie_maps {
        if compressed_values.contains_key(map_id) {
            continue;
        }
        let map_info = metadata
            .get(map_id)
            .ok_or_else(|| anyhow!("empty LPM_TRIE map {} missing map_values map info", map_id))?;
        compressed_values.insert(
            *map_id,
            CompressedMapValues {
                value_size: map_info.value_size as usize,
                kind: CompressedMapValuesKind::Enumerated {
                    entries: HashMap::new(),
                },
            },
        );
    }
    Ok(())
}

fn parse_compressed_map_values_json(
    map_id: u32,
    metadata: &MapInfo,
    value: serde_json::Value,
) -> Result<CompressedMapValues> {
    let overlay: CompressedMapValuesJson = serde_json::from_value(value)
        .with_context(|| format!("invalid compressed map overlay schema for map {map_id}"))?;
    if overlay.value_size != metadata.value_size as usize {
        bail!(
            "map {map_id} compressed overlay value_size {} does not match map bytes_value {}",
            overlay.value_size,
            metadata.value_size
        );
    }
    let kind = match overlay.compression.as_str() {
        "uniform" => {
            if let Some(entries) = overlay.entries {
                if entries.is_array() {
                    bail!("map {map_id} has both raw entries and compression overlay");
                }
                bail!("map {map_id} uniform compression must not include entries");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} uniform compression must not include default_hex");
            }
            let value_hex = overlay
                .value_hex
                .ok_or_else(|| anyhow!("map {map_id} uniform compression requires value_hex"))?;
            let value =
                decode_compressed_value_hex(map_id, "value_hex", &value_hex, overlay.value_size)?;
            CompressedMapValuesKind::Uniform(value)
        }
        "sparse" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} sparse compression must not include value_hex");
            }
            let default_hex = overlay
                .default_hex
                .ok_or_else(|| anyhow!("map {map_id} sparse compression requires default_hex"))?;
            let default = decode_compressed_value_hex(
                map_id,
                "default_hex",
                &default_hex,
                overlay.value_size,
            )?;
            let entries = overlay
                .entries
                .ok_or_else(|| anyhow!("map {map_id} sparse compression requires entries"))?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Sparse { default, entries }
        }
        "enumerated" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include value_hex");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include default_hex");
            }
            let entries = overlay
                .entries
                .ok_or_else(|| anyhow!("map {map_id} enumerated compression requires entries"))?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Enumerated { entries }
        }
        other => bail!("map {map_id} unsupported compression {other:?}"),
    };
    Ok(CompressedMapValues {
        value_size: overlay.value_size,
        kind,
    })
}

fn decode_compressed_entries(
    map_id: u32,
    key_size: usize,
    value_size: usize,
    entries: serde_json::Value,
) -> Result<HashMap<Vec<u8>, Vec<u8>>> {
    let object = entries
        .as_object()
        .ok_or_else(|| anyhow!("map {map_id} compressed entries must be a JSON object"))?;
    let mut decoded = HashMap::new();
    for (key_hex, value_json) in object {
        let value_hex = value_json.as_str().ok_or_else(|| {
            anyhow!("map {map_id} compressed entry {key_hex:?} value must be a hex string")
        })?;
        let key = decode_fixed_hex_bytes(map_id, "compressed entry key", key_hex, key_size)?;
        let value = decode_compressed_value_hex(map_id, "entries value", value_hex, value_size)?;
        decoded.insert(key, value);
    }
    Ok(decoded)
}

fn decode_compressed_value_hex(
    map_id: u32,
    field: &str,
    hex: &str,
    value_size: usize,
) -> Result<Vec<u8>> {
    decode_fixed_hex_bytes(map_id, &format!("compressed {field}"), hex, value_size)
}

fn decode_fixed_hex_bytes(map_id: u32, label: &str, hex: &str, byte_len: usize) -> Result<Vec<u8>> {
    let expected = byte_len
        .checked_mul(2)
        .ok_or_else(|| anyhow!("map {map_id} {label} byte_len {byte_len} overflows hex length"))?;
    if hex.len() != expected {
        bail!(
            "map {map_id} {label} has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex).with_context(|| format!("map {map_id} {label} has invalid hex"))
}

fn decode_bpftool_entry_value(entry: &BpftoolMapEntryJson, metadata: &MapInfo) -> Result<Vec<u8>> {
    if !entry.values.is_empty() {
        return decode_bpftool_percpu_values(&entry.values, metadata.value_size as usize);
    }
    let Some(value) = &entry.value else {
        bail!("bpftool entry has neither value nor per-CPU values");
    };
    match value {
        BpftoolMapValueJson::Bytes(bytes) => decode_bpftool_hex_bytes(bytes),
        BpftoolMapValueJson::Error { error } => {
            bail!("bpftool map dump returned lookup error: {error}")
        }
    }
}

fn decode_bpftool_percpu_values(
    values: &[BpftoolPerCpuValueJson],
    value_size: usize,
) -> Result<Vec<u8>> {
    let stride = (value_size + 7) & !7;
    let mut out = Vec::with_capacity(values.len().saturating_mul(stride));
    for value in values {
        let bytes = decode_bpftool_hex_bytes(&value.value)?;
        if bytes.len() != value_size {
            bail!(
                "per-CPU value has {} byte(s), expected {}",
                bytes.len(),
                value_size
            );
        }
        out.extend_from_slice(&bytes);
        out.resize(out.len() + (stride - value_size), 0);
    }
    Ok(out)
}

fn decode_bpftool_hex_bytes(input: &[String]) -> Result<Vec<u8>> {
    input
        .iter()
        .map(|byte| {
            let byte = byte.trim();
            let hex = match byte.strip_prefix("0x") {
                Some(hex) => hex,
                None => byte,
            };
            u8::from_str_radix(hex, 16).with_context(|| format!("invalid bpftool byte {byte:?}"))
        })
        .collect()
}

fn needs_bpftool_map_dump(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
            | libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
            | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}

fn parse_map_type(map_type: &MapTypeJson) -> Result<u32> {
    match map_type {
        MapTypeJson::Number(number) => Ok(*number),
        MapTypeJson::Name(name) => {
            let normalized = name
                .trim()
                .trim_start_matches("BPF_MAP_TYPE_")
                .trim_start_matches("bpf_map_type_")
                .replace(['-', ' '], "_")
                .to_ascii_lowercase();
            match normalized.as_str() {
                "hash" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH),
                "array" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY),
                "prog_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PROG_ARRAY),
                "perf_event_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY),
                "percpu_hash" | "per_cpu_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH),
                "percpu_array" | "per_cpu_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY),
                "stack_trace" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK_TRACE),
                "cgroup_array" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_ARRAY),
                "lru_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_LRU_HASH),
                "lru_percpu_hash" | "lru_per_cpu_hash" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH)
                }
                "lpm_trie" => Ok(libbpf_sys::BPF_MAP_TYPE_LPM_TRIE),
                "array_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS),
                "hash_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS),
                "devmap" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP),
                "devmap_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP_HASH),
                "sockmap" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKMAP),
                "cpumap" => Ok(libbpf_sys::BPF_MAP_TYPE_CPUMAP),
                "xskmap" => Ok(libbpf_sys::BPF_MAP_TYPE_XSKMAP),
                "sockhash" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKHASH),
                "cgroup_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_STORAGE),
                "reuseport_sockarray" => Ok(libbpf_sys::BPF_MAP_TYPE_REUSEPORT_SOCKARRAY),
                "percpu_cgroup_storage" | "per_cpu_cgroup_storage" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE)
                }
                "queue" => Ok(libbpf_sys::BPF_MAP_TYPE_QUEUE),
                "stack" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK),
                "sk_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_SK_STORAGE),
                "struct_ops" => Ok(libbpf_sys::BPF_MAP_TYPE_STRUCT_OPS),
                "ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_RINGBUF),
                "inode_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_INODE_STORAGE),
                "task_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_TASK_STORAGE),
                "bloom_filter" => Ok(libbpf_sys::BPF_MAP_TYPE_BLOOM_FILTER),
                "user_ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_USER_RINGBUF),
                "cgrp_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGRP_STORAGE),
                "arena" => Ok(libbpf_sys::BPF_MAP_TYPE_ARENA),
                "insn_array" => Ok(libbpf_sys::BPF_MAP_TYPE_INSN_ARRAY),
                _ => bail!("unsupported map_type: {name}"),
            }
        }
    }
}

fn parse_map_ids_arg(value: &str) -> Result<Vec<u32>> {
    if value.contains('/') || value.ends_with(".json") {
        let prog_info: ProgInfoMapIdsJson = read_json_file(Path::new(value), "prog_info JSON")?;
        return Ok(prog_info.map_ids);
    }
    value
        .split(',')
        .map(|entry| {
            entry
                .trim()
                .parse::<u32>()
                .with_context(|| format!("invalid --map-ids value: {entry}"))
        })
        .collect()
}

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

impl MapInfo {
    pub fn supports_direct_value_access(&self) -> bool {
        matches!(
            self.map_type,
            libbpf_sys::BPF_MAP_TYPE_HASH
                | libbpf_sys::BPF_MAP_TYPE_ARRAY
                | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
                | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
        )
    }

    pub fn is_map_in_map(&self) -> bool {
        matches!(
            self.map_type,
            libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
        )
    }

    pub fn has_removable_lookup_pattern(&self) -> bool {
        matches!(
            self.map_type,
            libbpf_sys::BPF_MAP_TYPE_ARRAY | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
        )
    }

    pub fn requires_entry_presence_check(&self) -> bool {
        matches!(
            self.map_type,
            libbpf_sys::BPF_MAP_TYPE_HASH | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
        )
    }
}

type MapInfoBySite = HashMap<InsnSite, MapInfo>;

fn analyze_map_info(
    program: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
) -> Result<MapInfoBySite> {
    let mut by_site = HashMap::new();
    for site in program.all_sites() {
        let Some(insn) = program.insn_at(site) else {
            continue;
        };
        if !matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx)) {
            continue;
        }
        let Some(map_id) = program.map_id_for_imm(insn.imm) else {
            continue;
        };
        let info = side_input
            .map_info
            .get(&map_id)
            .ok_or_else(|| anyhow!("map_values snapshot has no map info for map {}", map_id))?
            .clone();
        by_site.insert(site, info);
    }
    Ok(by_site)
}

fn unique_maps(map_info: &MapInfoBySite) -> Vec<MapInfo> {
    let mut seen = HashMap::new();
    for info in map_info.values() {
        seen.entry(info.map_id).or_insert_with(|| info.clone());
    }
    let mut ordered = seen.into_values().collect::<Vec<_>>();
    ordered.sort_by_key(|info| info.map_id);
    ordered
}
