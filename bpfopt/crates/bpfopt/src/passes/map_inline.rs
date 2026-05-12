// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, BBProgram, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
use anyhow::{anyhow, bail, Context, Result};
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque};
use std::sync::OnceLock;
mod map_info;
use map_info::analyze_map_info;
pub use map_info::{MapInfo, MapInfoAnalysis, MapInfoResult, MapReference};
const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const CONST_STACK_VALUE_LOOKBACK_LIMIT: usize = 256;
const VALUE_PREVIEW_BYTES: usize = 32;
#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub enum MapInlineHintAnchor {
    Site(InsnSite),
    MapName(String),
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MapInlineHintMode {
    Soft,
    Hard,
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInlineHint {
    pub anchor: MapInlineHintAnchor,
    pub mode: MapInlineHintMode,
    pub key: Vec<u8>,
}
pub struct MapInlinePass;
#[derive(Clone, Debug)]
pub struct MapInlineSideInput {
    pub map_ids: Vec<u32>,
    pub metadata: HashMap<u32, MapMetadata>,
    pub values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    pub compressed_values: HashMap<u32, CompressedMapValues>,
    pub inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    pub maps_skipped_by_size: HashSet<u32>,
    pub hints: Vec<MapInlineHint>,
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

fn map_inline_side_input(prog: &BBProgram) -> anyhow::Result<&MapInlineSideInput> {
    prog.map_inline_side_input()
        .ok_or_else(|| anyhow::anyhow!("map_inline side input is missing from BBProgram"))
}

fn snapshot_map_info(
    prog: &BBProgram,
    map_id: u32,
) -> std::result::Result<Option<MapInfo>, String> {
    let side_input = map_inline_side_input(prog).map_err(|err| err.to_string())?;
    let Some(metadata) = side_input.metadata.get(&map_id) else {
        return Err(format!(
            "map_values snapshot has no metadata for map {}",
            map_id
        ));
    };
    Ok(Some(MapInfo {
        map_type: metadata.map_type,
        key_size: metadata.key_size,
        value_size: metadata.value_size,
        max_entries: metadata.max_entries,
        map_id: metadata.map_id,
    }))
}
fn lookup_value_size(prog: &BBProgram, info: &MapInfo) -> std::result::Result<usize, String> {
    let side_input = map_inline_side_input(prog).map_err(|err| err.to_string())?;
    if let Some(overlay) = side_input.compressed_values.get(&info.map_id) {
        return Ok(overlay.value_size);
    }
    if let Some(value_size) = side_input
        .values
        .iter()
        .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
    {
        return Ok(value_size);
    }
    Ok(info.value_size as usize)
}
fn lookup_elem(
    prog: &BBProgram,
    map_id: u32,
    key: &[u8],
    value_size: usize,
) -> std::result::Result<Vec<u8>, MapLookupError> {
    let side_input =
        map_inline_side_input(prog).map_err(|err| MapLookupError::Failed(err.to_string()))?;
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
    if !side_input.metadata.contains_key(&map_id) {
        return Err(MapLookupError::Failed(format!(
            "map_values snapshot has no metadata for map {}",
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

fn sites_after_site_in_frame(prog: &BBProgram, start: InsnSite) -> anyhow::Result<Vec<InsnSite>> {
    let frame = prog.site_frame(start)?;
    let mut seen_start = false;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            if seen_start {
                sites.push(site);
            } else if site == start {
                seen_start = true;
            }
        }
    }
    if !seen_start {
        anyhow::bail!("site {:?} is missing from frame {:?}", start, frame);
    }
    Ok(sites)
}

fn sites_before_site_in_frame_rev(
    prog: &BBProgram,
    end: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    let frame = prog.site_frame(end)?;
    let mut seen_end = false;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            if site == end {
                seen_end = true;
                break;
            }
            sites.push(site);
        }
        if seen_end {
            break;
        }
    }
    if !seen_end {
        anyhow::bail!("site {:?} is missing from frame {:?}", end, frame);
    }
    sites.reverse();
    Ok(sites)
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
fn find_map_lookup_sites(prog: &BBProgram) -> anyhow::Result<Vec<MapLookupSite>> {
    let mut sites = Vec::new();
    for block in prog.blocks() {
        for site in prog.sites_in_block(block.id)? {
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            if !is_map_lookup_elem_call(insn) {
                continue;
            }
            if let Some(map_load_site) = find_map_load_for_call(prog, site)? {
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
    prog: &BBProgram,
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
    prog: &BBProgram,
    outer_site: &MapLookupSite,
) -> anyhow::Result<Option<MapInMapChain>> {
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut null_check = None;
    let mut scan_sites = VecDeque::from(sites_after_site_in_frame(prog, outer_site.call_site)?);
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
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn) {
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
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn) {
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
    prog: &BBProgram,
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
    prog: &BBProgram,
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
    prog: &BBProgram,
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
    for (scanned, site) in sites_before_site_in_frame_rev(prog, call_site)?
        .into_iter()
        .enumerate()
    {
        if scanned == CONST_STACK_VALUE_LOOKBACK_LIMIT {
            break;
        }
        let insn = prog.insn(site)?;
        let Some((store_off, width)) = resolve_stack_store_slot(prog, site, insn) else {
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
    prog: &BBProgram,
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
pub struct ResolvedMapInlineHint {
    pub site: InsnSite,
    pub map_id: u32,
    pub key_bytes: Vec<u8>,
    pub value_bytes: Option<Vec<u8>>,
    pub mode: MapInlineHintMode,
    pub map_in_map_inner: Option<(u32, u32)>,
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
fn lookup_call_sites(prog: &BBProgram) -> anyhow::Result<Vec<InsnSite>> {
    let mut sites = Vec::new();
    for site in prog.all_sites() {
        if prog.insn_at(site).is_some_and(is_map_lookup_elem_call) {
            sites.push(site);
        }
    }
    Ok(sites)
}

fn collect_kernel_mutable_maps(
    prog: &BBProgram,
    map_info: &MapInfoResult,
) -> anyhow::Result<KernelMutableMaps> {
    let side_input = map_inline_side_input(prog)?;
    let mut ids = HashSet::new();
    let mut reasons = HashMap::new();
    for metadata in side_input.metadata.values() {
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
    for info in &map_info.unique_maps {
        if ids.contains(&info.map_id) || !lru_lookup_mutates_map(info.map_type) {
            continue;
        }
        ids.insert(info.map_id);
        reasons.insert(
            info.map_id,
            format!(
                "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
                info.map_id
            ),
        );
    }
    for site in prog.all_sites() {
        let insn = prog.insn(site)?;
        if is_map_writer_helper_call(insn) {
            let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, site, 1)?
            else {
                continue;
            };
            let helper_name = map_writer_helper_name(insn.imm);
            let map_ref = map_info.reference_at_site(map_load_site).ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map reference at {:?} for {helper_name} helper at {:?}",
                    map_load_site,
                    site
                )
            })?;
            let map_id = map_ref.map_id.ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map_id at {:?} for {helper_name} helper at {:?}",
                    map_load_site,
                    site
                )
            })?;
            ids.insert(map_id);
            reasons.insert(
                map_id,
                format!(
                    "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={map_id}"
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
fn map_writer_helper_name(helper_id: i32) -> &'static str {
    if helper_id == libbpf_sys::BPF_FUNC_map_update_elem as i32 {
        "BPF_FUNC_map_update_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_delete_elem as i32 {
        "BPF_FUNC_map_delete_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_push_elem as i32 {
        "BPF_FUNC_map_push_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_pop_elem as i32 {
        "BPF_FUNC_map_pop_elem"
    } else {
        "BPF_FUNC_<non-writer>"
    }
}
fn lru_lookup_mutates_map(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_LRU_HASH | libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}
fn map_type_is_map_in_map(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}
fn kernel_mutable_writer_reason(prog: &BBProgram) -> anyhow::Result<String> {
    let side_input = map_inline_side_input(prog)?;
    let Some(map_id) = side_input
        .map_ids
        .first()
        .copied()
        .or_else(|| side_input.metadata.keys().next().copied())
    else {
        return Ok("map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on unknown map".to_string());
    };
    Ok(format!("map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={map_id}"))
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
    prog: &BBProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    hints: &[MapInlineHint],
) -> anyhow::Result<ResolvedHintMap> {
    let sites = find_map_lookup_sites(prog)?;
    let mut resolved = ResolvedHintMap::new();
    let mut deferred = Vec::new();
    for hint in hints {
        if !resolve_direct_inline_hint(
            prog,
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
    prog: &BBProgram,
    map_info: &MapInfoResult,
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
                prog,
                kernel_mutable_maps,
                hint,
                site.call_site,
                info,
                resolved,
            )?;
            Ok(true)
        }
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = direct_map_ids_for_name(prog, map_info, name)?;
            if map_ids.is_empty() {
                return Ok(false);
            }
            let mut matched = 0usize;
            for site in sites {
                let info = lookup_site_map_info(map_info, site)?;
                if map_ids.contains(&info.map_id) {
                    matched += 1;
                    insert_resolved_hint(
                        prog,
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
    prog: &BBProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    deferred: &[MapInlineHint],
    resolved: &mut ResolvedHintMap,
) -> anyhow::Result<()> {
    if deferred.is_empty() {
        return Ok(());
    }
    let routes = resolve_hinted_map_in_map_routes(prog, map_info, sites, resolved)?;
    if routes.is_empty() {
        let has_map_in_map_outer_hint =
            has_resolved_map_in_map_outer_hint(map_info, sites, resolved)?;
        let has_known_inner_hint = deferred.iter().try_fold(false, |found, hint| {
            deferred_hint_targets_known_map_in_map_inner(prog, sites, hint)
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
    for route @ (inner_call_site, inner_info) in &routes {
        for (idx, hint) in deferred.iter().enumerate() {
            if !inner_hint_matches_route(prog, hint, route)? {
                continue;
            }
            insert_resolved_hint(
                prog,
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
        if !matched[idx] && deferred_hint_targets_known_map_in_map_inner(prog, sites, hint)? {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&hint.anchor)
            );
        }
    }
    Ok(())
}
fn resolve_hinted_map_in_map_routes(
    prog: &BBProgram,
    map_info: &MapInfoResult,
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
            let inner_info = snapshot_map_info(prog, inner_map_id)
                .map_err(anyhow::Error::msg)?
                .ok_or_else(|| {
                    anyhow::anyhow!(
                        "map_values snapshot has no metadata for inner map {} from outer map {} key {}",
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
fn has_resolved_map_in_map_outer_hint(
    map_info: &MapInfoResult,
    sites: &[MapLookupSite],
    resolved: &ResolvedHintMap,
) -> anyhow::Result<bool> {
    for site in sites {
        if hints_for_call_site(resolved, site.call_site).is_none() {
            continue;
        }
        if lookup_site_map_info(map_info, site)?.is_map_in_map() {
            return Ok(true);
        }
    }
    Ok(false)
}
fn deferred_hint_targets_known_map_in_map_inner(
    prog: &BBProgram,
    sites: &[MapLookupSite],
    hint: &MapInlineHint,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Site(call_site) => Ok(find_map_in_map_chains(prog, sites)?
            .iter()
            .any(|chain| chain.inner_call_site == *call_site)),
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(prog, name)?;
            map_ids.iter().try_fold(false, |found, map_id| {
                map_id_is_known_inner_map(prog, *map_id).map(|matches| found || matches)
            })
        }
    }
}
fn map_id_is_known_inner_map(prog: &BBProgram, map_id: u32) -> anyhow::Result<bool> {
    Ok(map_inline_side_input(prog)?
        .inner_map_ids
        .values()
        .any(|inner_map_id| *inner_map_id == map_id))
}
fn inner_hint_matches_route(
    prog: &BBProgram,
    hint: &MapInlineHint,
    route: &(InsnSite, MapInfo),
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Site(call_site) => Ok(*call_site == route.0),
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(prog, name)?;
            Ok(map_ids.contains(&route.1.map_id))
        }
    }
}
fn metadata_map_ids_for_name(prog: &BBProgram, name: &str) -> anyhow::Result<HashSet<u32>> {
    let side_input = map_inline_side_input(prog)?;
    let matched = side_input
        .metadata
        .values()
        .filter(|metadata| metadata.name == name)
        .map(|metadata| metadata.map_id)
        .collect::<HashSet<_>>();
    if matched.is_empty() {
        if !side_input.inner_map_ids.is_empty() {
            bail!("inner inline hint anchor map_name:{name} has no matching map-in-map outer hint");
        }
        bail!("inline hint map_name anchor {name:?} is not present in map_values metadata");
    }
    Ok(matched)
}
fn lookup_site_map_info<'a>(
    map_info: &'a MapInfoResult,
    site: &MapLookupSite,
) -> anyhow::Result<&'a MapInfo> {
    let map_ref = map_info
        .reference_at_site(site.map_load_site)
        .ok_or_else(|| {
            anyhow::anyhow!(
                "map reference metadata unavailable for lookup site {:?}",
                site.call_site
            )
        })?;
    map_ref
        .info
        .as_ref()
        .ok_or_else(|| anyhow::anyhow!("map info unavailable for lookup site {:?}", site.call_site))
}
fn direct_map_ids_for_name(
    prog: &BBProgram,
    map_info: &MapInfoResult,
    name: &str,
) -> anyhow::Result<HashSet<u32>> {
    let side_input = map_inline_side_input(prog)?;
    let mut matched = HashSet::new();
    for info in &map_info.unique_maps {
        let metadata = side_input.metadata.get(&info.map_id).ok_or_else(|| {
            anyhow::anyhow!(
                "map_values snapshot has no metadata for used map {} while resolving inline hint map_name anchor {name:?}",
                info.map_id
            )
        })?;
        if metadata.name == name {
            matched.insert(info.map_id);
        }
    }
    Ok(matched)
}
fn insert_resolved_hint(
    prog: &BBProgram,
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
        let inner_map_id = match resolve_inner_map_id_for_outer_key(prog, info, &encoded_key)? {
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
        read_hard_hint_value(prog, info, &hint.key).with_context(|| {
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
            site: call_site,
            map_id: info.map_id,
            key_bytes: hint.key.clone(),
            value_bytes,
            mode: hint.mode,
            map_in_map_inner,
            source_anchor: hint.anchor.clone(),
        });
    Ok(())
}
fn read_hard_hint_value(
    prog: &BBProgram,
    info: &MapInfo,
    key: &[u8],
) -> anyhow::Result<Option<Vec<u8>>> {
    let value_size = lookup_value_size(prog, info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(prog, info.map_id, key, value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) => {
            if enumerated_overlay_missing_key(prog, info.map_id, key)? {
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
fn enumerated_overlay_missing_key(
    prog: &BBProgram,
    map_id: u32,
    key: &[u8],
) -> anyhow::Result<bool> {
    Ok(matches!(
        map_inline_side_input(prog)?
            .compressed_values
            .get(&map_id)
            .map(|overlay| &overlay.kind),
        Some(CompressedMapValuesKind::Enumerated { entries }) if !entries.contains_key(key)
    ))
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
    fn name(&self) -> &str {
        "map_inline"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let side_input = map_inline_side_input(prog)?;
    if !ctx.map_inner_map_ids.is_empty() && ctx.map_inner_map_ids != side_input.inner_map_ids {
        anyhow::bail!("map_inline PassContext inner map IDs differ from BBProgram side input");
    }
    let initial_map_info = analyze_map_info(prog).map_err(anyhow::Error::msg)?;
    let initial_kernel_mutable_maps = collect_kernel_mutable_maps(prog, &initial_map_info)?;
    if prog
        .all_sites()
        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call))
        && !side_input.hints.is_empty()
        && !side_input.inner_map_ids.is_empty()
        && side_input
            .metadata
            .values()
            .any(|metadata| map_type_is_map_in_map(metadata.map_type))
    {
        anyhow::bail!("kernel-mutable inner map");
    }
    let initial_inline_hints = resolve_inline_hints(
        prog,
        &initial_map_info,
        &initial_kernel_mutable_maps,
        &side_input.hints,
    )?;
    let mut inline_hints_consumed = HashSet::<MapInlineHintAnchor>::new();
    let mut result = run_map_inline_round(
        prog,
        true,
        &initial_inline_hints,
        &mut inline_hints_consumed,
    )?;
    let side_input = map_inline_side_input(prog)?;
    if !side_input.hints.is_empty() {
        if side_input.hints.iter().any(|hint| {
            hint.mode == MapInlineHintMode::Soft && !inline_hints_consumed.contains(&hint.anchor)
        }) {
            record_diagnostic(
                &mut result.diagnostics,
                "missing immediate null check".to_string(),
            );
        }
        record_diagnostic(
            &mut result.diagnostics,
            format!("inline_hints_consumed={}", inline_hints_consumed.len()),
        );
    }
    Ok(result)
}
fn run_map_inline_round(
    prog: &mut BBProgram,
    use_verifier_guided_keys: bool,
    inline_hints: &ResolvedHintMap,
    inline_hints_consumed: &mut HashSet<MapInlineHintAnchor>,
) -> anyhow::Result<PassResult> {
    let old_len = prog.all_sites().count();
    let branch_target_sites = prog.branch_target_entry_sites()?;
    let map_info = analyze_map_info(prog).map_err(anyhow::Error::msg)?;
    let kernel_mutable_maps = collect_kernel_mutable_maps(prog, &map_info)?;
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    let mut site_diagnostics = Vec::new();
    if use_verifier_guided_keys {
        record_maps_skipped_by_size_counter(prog, &mut diagnostics)?;
    }
    let DirectMapValueLoadRewriteResult {
        replacements: direct_replacements,
        sites_applied: direct_sites_applied,
        site_diagnostics: direct_site_diagnostics,
        records: direct_records,
    } = build_direct_map_value_load_rewrites(prog, &kernel_mutable_maps)?;
    site_diagnostics.extend(direct_site_diagnostics);
    let sites = find_map_lookup_sites(prog)?;
    let has_writer = prog
        .all_sites()
        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call));
    if sites.is_empty() && has_writer {
        for site in lookup_call_sites(prog)? {
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site,
                kernel_mutable_writer_reason(prog)?,
                None,
            );
        }
    }
    for site in sites {
        let Some(map_ref) = map_info.reference_at_site(site.map_load_site) else {
            skip_lookup!(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                "map reference metadata unavailable".to_string()
            );
        };
        let Some(info) = map_ref.info.as_ref() else {
            skip_lookup!(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                "map info unavailable".to_string()
            );
        };
        if let Some(reason) = kernel_mutable_reason_for_map(&kernel_mutable_maps, info) {
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        if map_snapshot_skipped_by_size(prog, info.map_id)? {
            if !map_inline_side_input(prog)?
                .compressed_values
                .contains_key(&info.map_id)
            {
                return Err(anyhow::anyhow!("snapshot skipped map {}", info.map_id));
            }
            let reason = map_snapshot_skipped_by_size_site_reason(prog, info.map_id)?;
            skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
        }
        let site_inline_hints = hints_for_call_site(inline_hints, site.call_site);
        if info.is_map_in_map() {
            match build_map_in_map_chain_rewrite(prog, &site)? {
                Ok(Some(rewrite)) => rewrites.push(rewrite),
                Ok(None) => {
                    if site_inline_hints.is_some() {
                        if map_inline_side_input(prog)?
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
                }
                Err(reason) => {
                    skip_lookup!(&mut skipped, &mut site_diagnostics, site.call_site, reason);
                }
            }
            continue;
        }
        if hard_null_hint(site_inline_hints).is_some() {
            let key = match extract_site_constant_key(
                prog,
                site.call_site,
                info,
                use_verifier_guided_keys,
                site_inline_hints,
            )? {
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
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site.call_site,
                    "keeping lookup setup because removal would cross a branch target".to_string(),
                );
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
            match build_soft_hint_site_rewrite(prog, &site, info, site_inline_hints)? {
                Ok(Some(rewrite)) => {
                    for hint in site_inline_hints {
                        inline_hints_consumed.insert(hint.source_anchor.clone());
                    }
                    if rewrite
                        .skipped_sites
                        .iter()
                        .any(|site| branch_target_sites.contains(site))
                    {
                        skip_lookup!(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            "soft fold removal would cross a branch target".to_string()
                        );
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
                Ok(None) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        "soft inline hint emitted no replacement bytecode".to_string(),
                        None,
                    );
                }
                Err(reason) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                }
            }
            continue;
        }
        let key = match extract_site_constant_key(
            prog,
            site.call_site,
            info,
            use_verifier_guided_keys,
            site_inline_hints,
        )? {
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
        let mut rewrite = match build_site_rewrite(prog, &site, &key, &uses, info, null_check)? {
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
            record_site_diagnostic(
                &mut site_diagnostics,
                site.call_site,
                "keeping lookup pattern because removal would cross a branch target".to_string(),
            );
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
            ..PassResult::unchanged()
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
        record_site_diagnostic(
            &mut site_diagnostics,
            rewrite.call_site,
            format!("inlined successfully, value={}", rewrite.diagnostic_value),
        );
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
            ..PassResult::unchanged()
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
    result.site_skipped = skipped;
    result.diagnostics = diagnostics;
    result.site_diagnostics = site_diagnostics;
    result.map_inline_records = map_inline_records;
    Ok(result)
}
fn apply_map_inline_edit(
    prog: &mut BBProgram,
    old_len: usize,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
    cleanup_unreachable: bool,
    sites_applied: usize,
) -> anyhow::Result<PassResult> {
    let mut next = prog.clone();
    apply_replacements_and_deletions(&mut next, replacements, skip_sites)?;
    if cleanup_unreachable {
        cleanup_map_inline_bbprogram(&mut next)?;
    }
    let new_len = next.all_sites().count();
    *prog = next;
    Ok(PassResult {
        sites_applied,
        insns_before: old_len,
        insns_after: new_len,
        ..Default::default()
    })
}
fn apply_replacements_and_deletions(
    prog: &mut BBProgram,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
) -> anyhow::Result<()> {
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
            replace_site(prog, replacement)?;
        } else {
            delete_site(prog, site)?;
        }
    }
    Ok(())
}
fn replace_site(prog: &mut BBProgram, replacement: SiteReplacement) -> anyhow::Result<()> {
    if replacement.replacement.is_empty() {
        anyhow::bail!("map_inline replacement at {:?} is empty", replacement.site);
    }
    if prog.is_terminator_site(replacement.site)? {
        let terminator =
            terminator_for_site_replacement(prog, replacement.site, &replacement.replacement)?;
        return prog.replace_terminator_at_site(replacement.site, terminator);
    }
    prog.replace_range_at(replacement.site, 1, replacement.replacement)
}
fn delete_site(prog: &mut BBProgram, site: InsnSite) -> anyhow::Result<()> {
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
        return prog.replace_terminator_at_site(site, terminator);
    }
    prog.replace_range_at(site, 1, Vec::new())
}
fn terminator_for_site_replacement(
    prog: &BBProgram,
    site: InsnSite,
    replacement: &[BpfInsn],
) -> anyhow::Result<Terminator> {
    if replacement.len() != 1 {
        anyhow::bail!(
            "map_inline cannot replace terminator at {:?} with multiple insns",
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
    anyhow::bail!(
        "map_inline unsupported terminator replacement at {:?}",
        site
    )
}
fn cleanup_map_inline_bbprogram(prog: &mut BBProgram) -> anyhow::Result<()> {
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
    prog: &BBProgram,
    call_site: InsnSite,
    info: &MapInfo,
    use_verifier_guided_keys: bool,
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
    if use_verifier_guided_keys {
        return match try_extract_lookup_key_verifier_guided(prog, call_site, info.key_size)? {
            Ok(key) => Ok(Ok(key)),
            Err(verifier_err) => Ok(Err(format!(
                "verifier-guided key extraction failed: {}",
                verifier_err
            ))),
        };
    }
    let detail = "verifier-guided key extraction is unavailable after a prior map_inline rewrite"
        .to_string();
    Ok(Err(detail))
}
fn build_site_rewrite(
    prog: &BBProgram,
    site: &MapLookupSite,
    key: &LookupKey,
    uses: &LookupResultUses,
    info: &MapInfo,
    null_check: Option<InsnSite>,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let remove_lookup_pattern =
        site_can_attempt_lookup_pattern_removal(prog, uses, info, null_check);
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let lookup_value_size = lookup_value_size(prog, info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(prog, info.map_id, &encoded_key, lookup_value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) if is_hash_like_map_type(info.map_type) => {
            return site_level_inline_veto(format!(
                "hash-like map {} has no live entry for key {}",
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
    let removable_null_check = null_check.filter(|site| {
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
fn hard_null_hint(hints: Option<&[ResolvedMapInlineHint]>) -> Option<&ResolvedMapInlineHint> {
    hints?.iter().find(|hint| {
        hint.mode == MapInlineHintMode::Hard
            && hint.value_bytes.is_none()
            && hint.map_in_map_inner.is_none()
    })
}
fn build_hard_null_site_rewrite(
    prog: &BBProgram,
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
fn build_soft_hint_site_rewrite(
    prog: &BBProgram,
    site: &MapLookupSite,
    info: &MapInfo,
    hints: &[ResolvedMapInlineHint],
) -> SiteRewriteResult<Option<SiteRewrite>> {
    if hints.is_empty() {
        return Ok(Ok(None));
    }
    if hints
        .iter()
        .any(|hint| hint.mode != MapInlineHintMode::Soft)
    {
        return site_level_inline_veto("soft hint rewrite received a non-soft hint");
    }
    if info.is_map_in_map() {
        return site_level_inline_veto(
            "soft inline hints are not supported for map-in-map outer lookups",
        );
    }
    if find_soft_fold_null_handler(prog, site.call_site)?.is_none() {
        return site_level_inline_veto("soft fold not applicable: missing null handler");
    }
    site_level_inline_veto("soft fold requires BBProgram CFG insertion")
}
fn find_soft_fold_null_handler(
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<InsnSite>> {
    let sites = sites_after_site_in_frame(prog, call_site)?;
    let Some(null_check) = sites.first().copied() else {
        return Ok(None);
    };
    if !prog.same_block(null_check, call_site) {
        return Ok(None);
    }
    let insn = prog.insn(null_check)?;
    if !is_direct_r0_null_jeq(insn) {
        return Ok(None);
    }
    if non_null_successor_site(prog, null_check, insn)?.is_none() {
        return Ok(None);
    }
    Ok(Some(null_check))
}
fn is_direct_r0_null_jeq(insn: &BpfInsn) -> bool {
    insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && bpf_src(insn.code) == BPF_K
        && insn.dst_reg() == 0
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
}
fn resolve_inner_map_id_for_outer_key(
    prog: &BBProgram,
    outer_info: &MapInfo,
    encoded_outer_key: &[u8],
) -> SiteRewriteResult<u32> {
    let side_input = map_inline_side_input(prog)?;
    if let Some(inner_map_id) = side_input
        .inner_map_ids
        .get(&(outer_info.map_id, encoded_outer_key.to_vec()))
        .copied()
    {
        return Ok(Ok(inner_map_id));
    }
    let value_size = lookup_value_size(prog, outer_info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(prog, outer_info.map_id, encoded_outer_key, value_size) {
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
fn build_map_in_map_chain_rewrite(
    prog: &BBProgram,
    outer_site: &MapLookupSite,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    if find_map_in_map_chains(prog, std::slice::from_ref(outer_site))?
        .into_iter()
        .next()
        .is_none()
    {
        return Ok(Ok(None));
    }
    site_level_inline_veto("map-in-map chain is not inlineable")
}
fn site_can_attempt_lookup_pattern_removal(
    prog: &BBProgram,
    uses: &LookupResultUses,
    info: &MapInfo,
    null_check: Option<InsnSite>,
) -> bool {
    if info.has_removable_lookup_pattern() {
        return true;
    }
    info.requires_entry_presence_check()
        && uses.other_uses.is_empty()
        && null_check.is_some_and(|site| {
            prog.insn_at(site)
                .is_some_and(null_check_is_fallthrough_non_null)
        })
}
fn build_direct_map_value_load_rewrites(
    prog: &BBProgram,
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
            let origin = match resolve_map_value_pointer(prog, site, insn.src_reg()) {
                Ok(origin) => origin,
                Err(err) => return Err(anyhow!(err)),
            };
            let Some((map_ref, value_off)) = origin else {
                continue;
            };
            let Some(total_off) = value_off.checked_add(insn.off as i32) else {
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!(
                        "pseudo-map-value offset overflow (base {} + load off {})",
                        value_off, insn.off
                    ),
                );
                continue;
            };
            if total_off < 0 {
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!("pseudo-map-value load offset {} is negative", total_off),
                );
                continue;
            }
            let map_value = match resolve_snapshot_map_value(
                prog,
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
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!(
                        "pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                        map_value.map_id, offset, size
                    ),
                );
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
            record_site_diagnostic(
                &mut site_diagnostics,
                site,
                format!(
                    "constantized pseudo-map-value load from map_id={} off={} value=0x{:x}",
                    map_value.map_id, offset, scalar
                ),
            );
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
    prog: &BBProgram,
    map_ref: MapRefKey,
    kernel_mutable_maps: &KernelMutableMaps,
    cache: &mut HashMap<MapRefKey, Option<SnapshotMapValue>>,
) -> anyhow::Result<Option<SnapshotMapValue>> {
    if let Some(cached) = cache.get(&map_ref) {
        return Ok(cached.clone());
    }
    let resolved = (|| -> anyhow::Result<Option<SnapshotMapValue>> {
        let Some(map_id) = map_id_for_ref(prog, map_ref)? else {
            return Ok(None);
        };
        if map_snapshot_skipped_by_size(prog, map_id)? {
            return Ok(None);
        }
        let Some(info) = snapshot_map_info(prog, map_id).map_err(anyhow::Error::msg)? else {
            return Ok(None);
        };
        if kernel_mutable_reason_for_map(kernel_mutable_maps, &info).is_some() {
            return Ok(None);
        }
        let key = vec![0u8; info.key_size as usize];
        let value_size = lookup_value_size(prog, &info).map_err(anyhow::Error::msg)?;
        let value = match lookup_elem(prog, map_id, &key, value_size) {
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
fn map_id_for_ref(prog: &BBProgram, map_ref: MapRefKey) -> anyhow::Result<Option<u32>> {
    let side_input = map_inline_side_input(prog)?;
    match MapPseudo::from_src_reg(map_ref.src_reg) {
        Some(kind) if kind.uses_fd() => Ok(prog.map_fd_bindings().get(&map_ref.imm).copied()),
        Some(kind) if kind.uses_index() => {
            let index = usize::try_from(map_ref.imm).map_err(|_| {
                anyhow::anyhow!("negative canonical pseudo-map index {}", map_ref.imm)
            })?;
            let Some(&map_id) = side_input.map_ids.get(index) else {
                anyhow::bail!(
                    "canonical pseudo-map index {} out of range for {} map ids",
                    index,
                    side_input.map_ids.len()
                );
            };
            Ok(Some(map_id))
        }
        _ => Ok(None),
    }
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
    let stride = round_up_8(value_size);
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
fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}
fn find_map_load_for_call(
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<InsnSite>> {
    find_direct_map_load_for_reg_before_site(prog, call_site, 1)
}
fn find_direct_map_load_for_reg_before_site(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
) -> anyhow::Result<Option<InsnSite>> {
    find_direct_map_load_for_reg_before_site_inner(prog, site, reg, REG_RESOLUTION_LIMIT)
}
fn find_direct_map_load_for_reg_before_site_inner(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    let previous_sites = sites_before_site_in_frame_rev(prog, site)?;
    for prev_site in previous_sites {
        let insn = prog.insn(prev_site)?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            if insn.dst_reg() == reg
                && matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx))
            {
                return Ok(Some(prev_site));
            }
            if insn.is_mov64_reg() && insn.dst_reg() == reg {
                return find_direct_map_load_for_reg_before_site_inner(
                    prog,
                    prev_site,
                    insn.src_reg(),
                    budget - 1,
                );
            }
            if is_stack_dw_load_to_reg(insn, reg) {
                return find_direct_map_load_for_stack_slot_before_site(
                    prog,
                    prev_site,
                    insn.off,
                    budget - 1,
                );
            }
            return Ok(None);
        }
    }
    Ok(None)
}
fn find_direct_map_load_for_stack_slot_before_site(
    prog: &BBProgram,
    site: InsnSite,
    stack_off: i16,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    let previous_sites = sites_before_site_in_frame_rev(prog, site)?;
    for prev_site in previous_sites {
        let insn = prog.insn(prev_site)?;
        if is_stack_dw_store(insn, stack_off) {
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
fn is_stack_dw_load_to_reg(insn: &BpfInsn, reg: u8) -> bool {
    insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && insn.dst_reg() == reg
        && insn.src_reg() == 10
}
fn is_stack_dw_store(insn: &BpfInsn, stack_off: i16) -> bool {
    bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && matches!(insn.class(), BPF_ST | BPF_STX)
        && insn.dst_reg() == 10
        && insn.off == stack_off
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
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<(InsnSite, InsnSite, i16)>> {
    let (r2_add_site, scanned) =
        match find_prev_reg_def_within(prog, call_site, 2, R2_SETUP_LOOKBACK_LIMIT) {
            Ok(Some(found)) => found,
            Ok(None) => return Ok(None),
            Err(err) => return Err(err),
        };
    let add = prog
        .insn_at(r2_add_site)
        .ok_or_else(|| anyhow::anyhow!("missing r2 add instruction at {:?}", r2_add_site))?;
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return Ok(None);
    }
    let remaining = R2_SETUP_LOOKBACK_LIMIT.saturating_sub(scanned);
    let (r2_mov_site, _) = match find_prev_reg_def_within(prog, r2_add_site, 2, remaining) {
        Ok(Some(found)) => found,
        Ok(None) => return Ok(None),
        Err(err) => return Err(err),
    };
    let mov = prog
        .insn_at(r2_mov_site)
        .ok_or_else(|| anyhow::anyhow!("missing r2 mov instruction at {:?}", r2_mov_site))?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return Ok(None);
    }
    let stack_off = i16::try_from(add.imm)
        .map_err(|_| anyhow::anyhow!("r2 stack add immediate {} does not fit i16", add.imm))?;
    Ok(Some((r2_mov_site, r2_add_site, stack_off)))
}
fn find_prev_reg_def_within(
    prog: &BBProgram,
    start_site: InsnSite,
    reg: u8,
    limit: usize,
) -> anyhow::Result<Option<(InsnSite, usize)>> {
    let mut scanned = 0usize;
    for site in sites_before_site_in_frame_rev(prog, start_site)? {
        scanned += 1;
        if scanned > limit {
            break;
        }
        if insn_use_def_set(prog.insn(site)?).defs.contains(&reg) {
            return Ok(Some((site, scanned)));
        }
    }
    Ok(None)
}
fn size_in_bytes(size: u8) -> Option<u8> {
    match size {
        BPF_B => Some(1),
        BPF_H => Some(2),
        BPF_W => Some(4),
        BPF_DW => Some(8),
        _ => None,
    }
}
fn find_prev_reg_def(
    prog: &BBProgram,
    start_site: InsnSite,
    reg: u8,
) -> Result<Option<InsnSite>, String> {
    for site in sites_before_site_in_frame_rev(prog, start_site).map_err(|err| err.to_string())? {
        let insn = prog.insn(site).map_err(|err| err.to_string())?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            return Ok(Some(site));
        }
    }
    Ok(None)
}
fn resolve_map_value_pointer(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
) -> Result<Option<(MapRefKey, i32)>, String> {
    resolve_map_value_pointer_inner(prog, before_site, reg, REG_RESOLUTION_LIMIT)
}
fn resolve_map_value_pointer_inner(
    prog: &BBProgram,
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
    let Some(site) = find_prev_reg_def(prog, before_site, reg)? else {
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
fn resolve_stack_pointer_to_stack_inner(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
    budget: usize,
) -> Result<i16, String> {
    if budget == 0 {
        return Err(format!(
            "stack pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    if reg == 10 {
        return Ok(0);
    }
    let Some(site) = find_prev_reg_def(prog, before_site, reg)? else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = *prog.insn(site).map_err(|err| err.to_string())?;
    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);
        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_stack_pointer_to_stack_inner(prog, site, insn.src_reg(), budget - 1);
        }
        if matches!(op, BPF_ADD | BPF_SUB) && src_mode == BPF_K {
            let base = resolve_stack_pointer_to_stack_inner(prog, site, reg, budget - 1)?;
            let delta = insn.imm as i64;
            let signed_delta = if op == BPF_SUB { -delta } else { delta };
            let stack_off = base as i64 + signed_delta;
            return i16::try_from(stack_off).map_err(|_| {
                format!(
                    "resolved stack offset {} from r{} does not fit in i16",
                    stack_off, reg
                )
            });
        }
    }
    Err(format!(
        "register r{} definition at {:?} does not resolve to fp-relative stack memory",
        reg, site
    ))
}
fn log_map_inline_debug(message: &str) {
    static ENABLED: OnceLock<bool> = OnceLock::new();
    if *ENABLED.get_or_init(|| std::env::var_os("BPFREJIT_MAP_INLINE_DEBUG").is_some()) {
        eprintln!("map_inline: {}", message);
    }
}
fn record_diagnostic(diagnostics: &mut Vec<String>, message: String) {
    log_map_inline_debug(&message);
    diagnostics.push(message);
}
fn record_site_diagnostic(diagnostics: &mut Vec<SiteDiagnostic>, site: InsnSite, message: String) {
    log_map_inline_debug(&format!("site {:?}: {}", site, message));
    diagnostics.push(SiteDiagnostic { site, message });
}
fn record_maps_skipped_by_size_counter(
    prog: &BBProgram,
    diagnostics: &mut Vec<String>,
) -> anyhow::Result<()> {
    let side_input = map_inline_side_input(prog)?;
    let count = side_input
        .maps_skipped_by_size
        .iter()
        .filter(|map_id| !side_input.compressed_values.contains_key(map_id))
        .count();
    if count > 0 {
        record_diagnostic(diagnostics, format!("maps_skipped_by_size={count}"));
    }
    Ok(())
}
fn map_snapshot_skipped_by_size(prog: &BBProgram, map_id: u32) -> anyhow::Result<bool> {
    let side_input = map_inline_side_input(prog)?;
    Ok(side_input.maps_skipped_by_size.contains(&map_id)
        && !side_input.compressed_values.contains_key(&map_id))
}
fn map_snapshot_skipped_by_size_reason(map_id: u32) -> String {
    format!("map {map_id} snapshot skipped by size and no overlay provided")
}
fn map_snapshot_skipped_by_size_site_reason(
    prog: &BBProgram,
    map_id: u32,
) -> anyhow::Result<String> {
    Ok(format!(
        "map snapshot skipped by size and no overlay provided (map_name={}, map_id={})",
        map_name_for_id(prog, map_id)?,
        map_id
    ))
}
fn map_name_for_id(prog: &BBProgram, map_id: u32) -> anyhow::Result<String> {
    Ok(match map_inline_side_input(prog)?.metadata.get(&map_id) {
        Some(metadata) if !metadata.name.is_empty() => metadata.name.clone(),
        Some(_) => "<unnamed>".to_string(),
        None => "<unknown>".to_string(),
    })
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
    record_site_diagnostic(diagnostics, site, format!("skip reason: {}", reason));
    if let Some(detail) = detail {
        record_site_diagnostic(diagnostics, site, detail);
    }
}
fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = String::with_capacity(preview_len.saturating_mul(2) + 6);
    out.push_str("0x");
    for byte in &bytes[..preview_len] {
        out.push_str(&format!("{byte:02x}"));
    }
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
    prog: &BBProgram,
    start_site: InsnSite,
    allow_unrelated_helper_calls: bool,
    allow_readonly_helper_calls: bool,
) -> anyhow::Result<LookupResultUses> {
    let mut classification = LookupResultUses::default();
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut scan_sites = VecDeque::from(sites_after_site_in_frame(prog, start_site)?);
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
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn) {
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
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn) {
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
            let can_follow_helper = allow_unrelated_helper_calls
                || (allow_readonly_helper_calls && helper_call_is_readonly_for_lookup_value(insn));
            if can_follow_helper && (!surviving_aliases.is_empty() || !alias_stack_slots.is_empty())
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
fn resolve_stack_store_slot(prog: &BBProgram, site: InsnSite, insn: &BpfInsn) -> Option<(i16, u8)> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    let width = size_in_bytes(bpf_size(insn.code))?;
    if !(insn.class() == BPF_ST || insn.class() == BPF_STX) {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        prog,
        site,
        insn.dst_reg(),
        REG_RESOLUTION_LIMIT,
    ) {
        Ok(base_stack_off) => base_stack_off,
        Err(_) => return None,
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let stack_off = match i16::try_from(stack_off) {
        Ok(stack_off) => stack_off,
        Err(_) => return None,
    };
    Some((stack_off, width))
}
fn resolve_stack_load_slot(prog: &BBProgram, site: InsnSite, insn: &BpfInsn) -> Option<i16> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        prog,
        site,
        insn.src_reg(),
        REG_RESOLUTION_LIMIT,
    ) {
        Ok(base_stack_off) => base_stack_off,
        Err(_) => return None,
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let Ok(stack_off) = i16::try_from(stack_off) else {
        return None;
    };
    Some(stack_off)
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
fn helper_call_is_readonly_for_lookup_value(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == libbpf_sys::BPF_FUNC_ktime_get_ns as i32
}
fn non_null_successor_site(
    prog: &BBProgram,
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
        || starts_next_lookup_setup(insn)
}
fn starts_next_lookup_setup(insn: &BpfInsn) -> bool {
    matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx))
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
