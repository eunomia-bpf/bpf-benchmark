// SPDX-License-Identifier: MIT
// Scan helpers for dynamic map inlining.

use std::collections::{BTreeMap, HashSet};
use std::fmt::Write as _;

use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
use crate::bpf;
use crate::insn::*;
use crate::pass::*;

const BPF_ADD: u8 = 0x00;
const BPF_SUB: u8 = 0x10;
const BPF_MUL: u8 = 0x20;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = 6;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;
const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const SITE_LEVEL_INLINE_VETO_PREFIX: &str = "site-level inline veto: ";
const VALUE_PREVIEW_BYTES: usize = 32;

/// Dynamic map inlining optimization pass.
pub struct MapInlinePass;

/// A `bpf_map_lookup_elem()` helper call and its map argument load.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapLookupSite {
    pub call_pc: usize,
    pub map_load_pc: usize,
}

/// Constant key materialized on the stack for a map lookup.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ConstantKey {
    pub stack_off: i16,
    pub width: u8,
    pub value: u64,
    pub store_pc: usize,
    pub source_imm_pc: Option<usize>,
    pub r2_mov_pc: Option<usize>,
    pub r2_add_pc: Option<usize>,
}

/// A fixed-offset scalar load from the map value pointer returned in `r0`.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct FixedLoadUse {
    pub pc: usize,
    pub dst_reg: u8,
    pub size: u8,
    pub offset: i16,
}

/// Classification of all uses that consume the lookup result in `r0`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct R0UseClassification {
    pub fixed_loads: Vec<FixedLoadUse>,
    pub other_uses: Vec<usize>,
    pub alias_copy_pcs: Vec<usize>,
    pub null_check_pc: Option<usize>,
}

impl R0UseClassification {
    /// Returns whether every `r0` use is a fixed-offset scalar load.
    pub fn all_fixed_loads(&self) -> bool {
        self.other_uses.is_empty()
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantRegValue {
    value: u64,
    source_pc: Option<usize>,
}

/// Find all `bpf_map_lookup_elem()` call sites in the instruction stream.
pub fn find_map_lookup_sites(insns: &[BpfInsn]) -> Vec<MapLookupSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
            if let Some(map_load_pc) = find_map_load_for_call(insns, pc) {
                sites.push(MapLookupSite {
                    call_pc: pc,
                    map_load_pc,
                });
            }
        }

        pc += insn_width(insn);
    }

    sites
}

/// Recover a stack-materialized constant key for a lookup helper call.
pub fn extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Option<ConstantKey> {
    try_extract_constant_key(insns, call_pc).ok()
}

pub fn try_extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Result<ConstantKey, String> {
    let bounds = subprog_bounds(insns, call_pc);
    let stack_off = resolve_stack_pointer_to_stack(insns, call_pc, 2, bounds)?;
    let (store_pc, source_imm_pc, width, value) =
        find_constant_stack_store(insns, call_pc, bounds, stack_off)?;
    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width,
        value,
        store_pc,
        source_imm_pc,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

/// Classify all uses of the lookup result until its value-pointer aliases die out.
pub fn classify_r0_uses(insns: &[BpfInsn], call_pc: usize) -> R0UseClassification {
    classify_r0_uses_with_options(insns, call_pc, false)
}

#[derive(Clone, Debug)]
struct SiteRewrite {
    call_pc: usize,
    diagnostic_value: String,
    removed_null_check: bool,
    speculative: bool,
    map_inline_record: MapInlineRecord,
    skipped_pcs: HashSet<usize>,
    replacements: BTreeMap<usize, Vec<BpfInsn>>,
}

impl BpfPass for MapInlinePass {
    fn name(&self) -> &str {
        "map_inline"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "map_info"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt = analyses.get(&BranchTargetAnalysis, program);
        let map_info = analyses.get(&MapInfoAnalysis, program);
        let mut skipped = Vec::new();
        let mut rewrites = Vec::new();
        let mut diagnostics = Vec::new();
        let sites = find_map_lookup_sites(&program.insns);

        log_map_inline_debug(&format!("found {} lookup sites", sites.len()));

        for site in sites {
            log_map_inline_debug(&format!(
                "evaluating site at PC={} (map_load_pc={})",
                site.call_pc, site.map_load_pc
            ));
            let Some(map_ref) = map_info.reference_at_pc(site.map_load_pc) else {
                log_map_inline_debug(&format!(
                    "site pc={} skip: map reference unavailable",
                    site.call_pc
                ));
                let reason = "map reference metadata unavailable".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            };
            log_map_inline_debug(&format!(
                "site at PC={}: map_ref old_fd={} map_index={} map_id={:?}",
                site.call_pc, map_ref.old_fd, map_ref.map_index, map_ref.map_id
            ));
            let Some(info) = map_ref.info.as_ref() else {
                let reason = "map info unavailable".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            };
            log_map_inline_debug(&format!(
                "site at PC={}: resolved map_id={} map_type={} key_size={} value_size={} max_entries={} frozen={}",
                site.call_pc,
                info.map_id,
                info.map_type,
                info.key_size,
                info.value_size,
                info.max_entries,
                info.frozen
            ));
            if !info.is_inlineable_v1() {
                log_map_inline_debug(&format!(
                    "site pc={} skip: map type {} not inlineable",
                    site.call_pc, info.map_type
                ));
                let reason = format!("map type {} not inlineable in v1", info.map_type);
                record_skip(
                    &mut skipped,
                    &mut diagnostics,
                    site.call_pc,
                    reason,
                    Some(format!(
                        "site at PC={}: map_type={}, skip reason: unsupported map type",
                        site.call_pc, info.map_type
                    )),
                );
                continue;
            }

            let key = match try_extract_constant_key(&program.insns, site.call_pc) {
                Ok(key) => {
                    log_map_inline_debug(&format!(
                        "site at PC={}: extracted key value={} width={} stack_off={} store_pc={} source_imm_pc={:?} r2_mov_pc={:?} r2_add_pc={:?}",
                        site.call_pc,
                        key.value,
                        key.width,
                        key.stack_off,
                        key.store_pc,
                        key.source_imm_pc,
                        key.r2_mov_pc,
                        key.r2_add_pc
                    ));
                    key
                }
                Err(err) => {
                    log_map_inline_debug(&format!("site pc={} skip: {}", site.call_pc, err));
                    record_skip(
                        &mut skipped,
                        &mut diagnostics,
                        site.call_pc,
                        "lookup key is not a constant stack materialization".into(),
                        Some(format!(
                            "site at PC={}: key extraction failed: {}",
                            site.call_pc, err
                        )),
                    );
                    continue;
                }
            };
            if (key.width as u32) < info.key_size {
                let reason = format!(
                    "key width {} is smaller than map key size {}",
                    key.width, info.key_size
                );
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            if info.can_remove_lookup_pattern_v1() && key.value >= info.max_entries as u64 {
                let reason = format!(
                    "constant key {} out of range for max_entries {}",
                    key.value, info.max_entries
                );
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }

            let uses = classify_r0_uses_with_options(
                &program.insns,
                site.call_pc,
                info.frozen && info.can_remove_lookup_pattern_v1(),
            );
            let null_check_pc = uses.null_check_pc;
            if info.is_speculative_v1() && null_check_pc.is_none() {
                let reason = "speculative map inline requires an immediate null check".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            log_map_inline_debug(&format!(
                "site at PC={}: null_check_pc={:?} alias_copies={} fixed_loads={} other_uses={}",
                site.call_pc,
                null_check_pc,
                uses.alias_copy_pcs.len(),
                uses.fixed_loads.len(),
                uses.other_uses.len()
            ));
            if uses.fixed_loads.is_empty() {
                let reason =
                    "lookup result is not consumed by fixed-offset scalar loads".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            if !uses.all_fixed_loads() {
                let reason = "lookup result has non-load uses".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }

            let rewrite = match build_site_rewrite(program, &site, &key, &uses, info, null_check_pc)
            {
                Ok(Some(rewrite)) => rewrite,
                Ok(None) => {
                    let reason = "failed to materialize replacement constants".to_string();
                    record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                    continue;
                }
                Err(err) => {
                    if let Some(reason) = site_level_inline_veto_reason(&err) {
                        record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                        continue;
                    }
                    let reason = format!("map lookup failed: {err:#}");
                    record_skip(
                        &mut skipped,
                        &mut diagnostics,
                        site.call_pc,
                        reason,
                        Some(format!(
                            "site at PC={}: value read failed: {:#}",
                            site.call_pc, err
                        )),
                    );
                    continue;
                }
            };

            if rewrite
                .skipped_pcs
                .iter()
                .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
            {
                let reason = "lookup pattern contains a branch target".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }

            if rewrite
                .replacements
                .keys()
                .any(|pc| rewrite.skipped_pcs.contains(pc))
            {
                let reason = "internal rewrite overlap".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }

            log_map_inline_debug(&format!(
                "site at PC={}: rewrite prepared with {} replacement load(s), removed_null_check={}, speculative={}",
                site.call_pc,
                rewrite.replacements.len(),
                rewrite.removed_null_check,
                rewrite.speculative
            ));
            rewrites.push(rewrite);
        }

        if rewrites.is_empty() {
            log_map_inline_debug("no map_inline rewrites prepared");
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics,
                ..Default::default()
            });
        }

        let mut skip_pcs = HashSet::new();
        let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = BTreeMap::new();
        let mut map_inline_records = Vec::new();
        let mut applied = 0usize;
        let mut removed_any_null_check = false;
        let mut speculative_sites = 0usize;

        for rewrite in rewrites {
            let conflict = rewrite
                .skipped_pcs
                .iter()
                .any(|pc| replacements.contains_key(pc))
                || rewrite.replacements.keys().any(|pc| skip_pcs.contains(pc))
                || rewrite
                    .replacements
                    .keys()
                    .any(|pc| replacements.contains_key(pc))
                || rewrite.skipped_pcs.iter().any(|pc| skip_pcs.contains(pc));
            if conflict {
                let reason = "overlapping map inline rewrite".to_string();
                record_skip(
                    &mut skipped,
                    &mut diagnostics,
                    rewrite.call_pc,
                    reason,
                    None,
                );
                continue;
            }

            removed_any_null_check |= rewrite.removed_null_check;
            speculative_sites += usize::from(rewrite.speculative);
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: inlined successfully, value={}",
                    rewrite.call_pc, rewrite.diagnostic_value
                ),
            );
            map_inline_records.push(rewrite.map_inline_record);
            skip_pcs.extend(rewrite.skipped_pcs);
            replacements.extend(rewrite.replacements);
            applied += 1;
        }

        if applied == 0 {
            log_map_inline_debug("all prepared rewrites were discarded");
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics,
                map_inline_records,
                ..Default::default()
            });
        }

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            addr_map[pc] = new_insns.len();

            if let Some(replacement) = replacements.get(&pc) {
                new_insns.extend_from_slice(replacement);
                pc += 1;
                continue;
            }

            if skip_pcs.contains(&pc) {
                pc += 1;
                continue;
            }

            let insn = program.insns[pc];
            new_insns.push(insn);
            if insn.is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        let mut final_insns = new_insns;
        let mut final_addr_map = addr_map;
        if removed_any_null_check {
            if let Some((cleaned_insns, cleanup_map)) =
                super::utils::eliminate_unreachable_blocks(&final_insns)
            {
                final_addr_map = super::utils::compose_addr_maps(&final_addr_map, &cleanup_map);
                final_insns = cleaned_insns;
            }
            if let Some((cleaned_insns, cleanup_map)) = super::utils::eliminate_nops(&final_insns) {
                final_addr_map = super::utils::compose_addr_maps(&final_addr_map, &cleanup_map);
                final_insns = cleaned_insns;
            }
        }

        program.insns = final_insns;
        program.remap_annotations(&final_addr_map);
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        if speculative_sites > 0 {
            record_diagnostic(
                &mut diagnostics,
                format!("speculative map-inline sites: {}", speculative_sites),
            );
        }

        log_map_inline_debug(&format!(
            "applied {} map_inline rewrite(s), skipped {} site(s)",
            applied,
            skipped.len()
        ));

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics,
            map_inline_records,
            ..Default::default()
        })
    }
}

fn build_site_rewrite(
    program: &BpfProgram,
    site: &MapLookupSite,
    key: &ConstantKey,
    uses: &R0UseClassification,
    info: &crate::analysis::MapInfo,
    null_check_pc: Option<usize>,
) -> anyhow::Result<Option<SiteRewrite>> {
    let remove_lookup_pattern = info.can_remove_lookup_pattern_v1();
    let encoded_key = encode_key_bytes(key.value, info.key_size as usize);
    let lookup_value_size = bpf::bpf_map_lookup_value_size_by_id(info.map_id)?;
    log_map_inline_debug(&format!(
        "site pc={} reading map_id={} key={:?} lookup_value_size={}",
        site.call_pc, info.map_id, encoded_key, lookup_value_size
    ));
    let value = match bpf::bpf_map_lookup_elem_by_id(info.map_id, &encoded_key, lookup_value_size) {
            Ok(value) => {
                log_map_inline_debug(&format!(
                    "site pc={} INLINE value={:?}",
                    site.call_pc, value
                ));
                value
            }
            Err(err) => {
                log_map_inline_debug(&format!(
                    "site at PC={}: bpf_map_lookup_elem_by_id(map_id={}, key={}) failed: {:#}",
                    site.call_pc,
                    info.map_id,
                    format_bytes_preview(&encoded_key),
                    err
                ));
                return Err(err);
            }
        };
    let inline_value = prepare_inline_value(info, &value)
        .map_err(|reason| site_level_inline_veto(reason))?;

    let removable_null_check_pc =
        null_check_pc.filter(|&pc| null_check_is_fallthrough_non_null(&program.insns[pc]));
    let mut lookup_pattern_pcs = HashSet::new();
    if remove_lookup_pattern {
        lookup_pattern_pcs.insert(site.call_pc);
        lookup_pattern_pcs.insert(site.map_load_pc);
        lookup_pattern_pcs.insert(site.map_load_pc + 1);
        lookup_pattern_pcs.insert(key.store_pc);
        if let Some(r2_mov_pc) = key.r2_mov_pc {
            lookup_pattern_pcs.insert(r2_mov_pc);
        }
        if let Some(r2_add_pc) = key.r2_add_pc {
            lookup_pattern_pcs.insert(r2_add_pc);
        }
        if let Some(source_imm_pc) = key.source_imm_pc {
            lookup_pattern_pcs.insert(source_imm_pc);
        }
        if let Some(null_check_pc) = removable_null_check_pc {
            lookup_pattern_pcs.insert(null_check_pc);
        }
    }
    if remove_lookup_pattern {
        lookup_pattern_pcs.extend(uses.alias_copy_pcs.iter().copied());
    }
    let null_check_blocks_lookup_removal =
        null_check_pc.is_some() && removable_null_check_pc.is_none();
    let can_remove_lookup_pattern = remove_lookup_pattern
        && !null_check_blocks_lookup_removal
        && lookup_pattern_removal_is_safe(program, uses, &lookup_pattern_pcs);
    let skipped_pcs = if can_remove_lookup_pattern {
        lookup_pattern_pcs
    } else {
        HashSet::new()
    };

    let mut replacements = BTreeMap::new();
    for load in &uses.fixed_loads {
        let scalar = read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
            anyhow::anyhow!(
                "map value read out of bounds for load pc {} (offset {}, size {})",
                load.pc,
                load.offset,
                load.size
            )
        })?;
        replacements.insert(load.pc, emit_constant_load(load.dst_reg, scalar, load.size));
    }

    if replacements.is_empty() {
        return Ok(None);
    }

    Ok(Some(SiteRewrite {
        call_pc: site.call_pc,
        diagnostic_value: format_inlined_value_diagnostic(&inline_value, &uses.fixed_loads),
        removed_null_check: can_remove_lookup_pattern && removable_null_check_pc.is_some(),
        speculative: info.is_speculative_v1(),
        map_inline_record: MapInlineRecord {
            map_id: info.map_id,
            key: encoded_key,
            expected_value: value,
        },
        skipped_pcs,
        replacements,
    }))
}

fn encode_key_bytes(value: u64, key_size: usize) -> Vec<u8> {
    value.to_le_bytes()[..key_size].to_vec()
}

fn prepare_inline_value(info: &crate::analysis::MapInfo, raw_value: &[u8]) -> Result<Vec<u8>, String> {
    if info.map_type != BPF_MAP_TYPE_PERCPU_ARRAY {
        return Ok(raw_value.to_vec());
    }

    collapse_uniform_percpu_array_value(info.value_size as usize, raw_value)
}

fn collapse_uniform_percpu_array_value(value_size: usize, raw_value: &[u8]) -> Result<Vec<u8>, String> {
    if value_size == 0 {
        return Err("PERCPU_ARRAY has zero value_size".to_string());
    }

    let stride = round_up_8(value_size);
    if raw_value.len() < stride || raw_value.len() % stride != 0 {
        return Err(format!(
            "PERCPU_ARRAY lookup blob length {} is inconsistent with slot stride {}",
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
                "PERCPU_ARRAY value differs across CPUs for {} slot(s)",
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
    let width = size_in_bytes(size)? as usize;
    let offset = offset as usize;
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

fn emit_constant_load(dst_reg: u8, value: u64, size: u8) -> Vec<BpfInsn> {
    let signed_value = value as i64;
    if size == BPF_DW && signed_value >= i32::MIN as i64 && signed_value <= i32::MAX as i64 {
        return vec![BpfInsn::mov64_imm(dst_reg, signed_value as i32)];
    }

    if size != BPF_DW && value <= i32::MAX as u64 {
        return vec![BpfInsn::mov64_imm(dst_reg, value as i32)];
    }

    emit_ldimm64(dst_reg, value)
}

fn emit_ldimm64(dst_reg: u8, value: u64) -> Vec<BpfInsn> {
    vec![
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst_reg, 0),
            off: 0,
            imm: value as u32 as i32,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: (value >> 32) as u32 as i32,
        },
    ]
}

fn find_map_load_for_call(insns: &[BpfInsn], call_pc: usize) -> Option<usize> {
    let (subprog_start, _) = subprog_bounds(insns, call_pc);
    let mut cursor = call_pc;
    while let Some(pc) = prev_real_pc_bounded(insns, cursor, subprog_start) {
        let insn = &insns[pc];
        if insn_defines_reg(insn, 1) {
            return (insn.is_ldimm64()
                && insn.dst_reg() == 1
                && insn.src_reg() == BPF_PSEUDO_MAP_FD)
                .then_some(pc);
        }
        cursor = pc;
    }
    None
}

fn site_level_inline_veto(reason: impl Into<String>) -> anyhow::Error {
    anyhow::anyhow!("{}{}", SITE_LEVEL_INLINE_VETO_PREFIX, reason.into())
}

fn site_level_inline_veto_reason(err: &anyhow::Error) -> Option<String> {
    err.to_string()
        .strip_prefix(SITE_LEVEL_INLINE_VETO_PREFIX)
        .map(str::to_string)
}

fn lookup_pattern_removal_is_safe(
    program: &BpfProgram,
    uses: &R0UseClassification,
    skipped_pcs: &HashSet<usize>,
) -> bool {
    if skipped_pcs.is_empty() || skipped_pcs.iter().any(|&pc| pc >= program.insns.len()) {
        return false;
    }

    let min_removed_pc = skipped_pcs.iter().min().copied().unwrap_or(0);
    let max_removed_pc = skipped_pcs.iter().max().copied().unwrap_or(0);
    let first_load_pc = uses
        .fixed_loads
        .iter()
        .map(|load| load.pc)
        .min()
        .unwrap_or(program.insns.len());

    // Only remove the lookup pattern itself when it is a tight contiguous block.
    // If clang interleaves unrelated setup, keep the lookup instructions and only
    // rewrite the fixed loads that consume the helper result.
    skipped_pcs.len() == max_removed_pc - min_removed_pc + 1 && max_removed_pc < first_load_pc
}

fn find_r2_stack_pointer_setup_simple(
    insns: &[BpfInsn],
    call_pc: usize,
    bounds: (usize, usize),
) -> Option<(usize, usize, i16)> {
    let (r2_add_pc, scanned) =
        find_prev_reg_def_within(insns, call_pc, 2, R2_SETUP_LOOKBACK_LIMIT, bounds.0)?;
    let add = &insns[r2_add_pc];

    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return None;
    }

    let remaining = R2_SETUP_LOOKBACK_LIMIT.saturating_sub(scanned);
    let (r2_mov_pc, _) = find_prev_reg_def_within(insns, r2_add_pc, 2, remaining, bounds.0)?;
    let mov = &insns[r2_mov_pc];
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return None;
    }

    Some((r2_mov_pc, r2_add_pc, add.imm as i16))
}

fn find_prev_reg_def_within(
    insns: &[BpfInsn],
    start_pc: usize,
    reg: u8,
    limit: usize,
    lower_bound: usize,
) -> Option<(usize, usize)> {
    let mut cursor = start_pc;
    let mut scanned = 0usize;

    while scanned < limit {
        let pc = prev_real_pc_bounded(insns, cursor, lower_bound)?;
        scanned += 1;
        if insn_defines_reg(&insns[pc], reg) {
            return Some((pc, scanned));
        }
        cursor = pc;
    }

    None
}

fn find_constant_stack_store(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
) -> Result<(usize, Option<usize>, u8, u64), String> {
    let mut cursor = before_pc;
    while let Some(pc) = prev_real_pc_bounded(insns, cursor, bounds.0) {
        let insn = &insns[pc];
        if !is_stack_store_at(insn, stack_off) {
            cursor = pc;
            continue;
        }

        let width = size_in_bytes(bpf_size(insn.code)).ok_or_else(|| {
            format!(
                "stack store at pc {} uses unsupported width opcode {:#x}",
                pc, insn.code
            )
        })?;
        if bpf_class(insn.code) == BPF_ST {
            return Ok((pc, None, width, truncate_imm(insn.imm, width)));
        }

        if bpf_class(insn.code) == BPF_STX {
            let resolved = resolve_constant_reg_value(insns, pc, insn.src_reg(), bounds)?;
            return Ok((
                pc,
                resolved.source_pc,
                width,
                truncate_value(resolved.value, width),
            ));
        }
        cursor = pc;
    }
    Err(format!("no stack store found for fp{}", stack_off))
}

fn resolve_constant_reg_value(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<ConstantRegValue, String> {
    resolve_constant_reg_value_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_constant_reg_value_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
    budget: usize,
) -> Result<ConstantRegValue, String> {
    if budget == 0 {
        return Err(format!(
            "constant register resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("source register r{} is a function argument", reg));
        }
        return Err(format!("no definition for source register r{}", reg));
    };
    let insn = &insns[pc];

    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if insn.src_reg() != 0 {
            return Err(format!(
                "register r{} at pc {} is loaded from pseudo source {}",
                reg,
                pc,
                insn.src_reg()
            ));
        }
        return Ok(ConstantRegValue {
            value: decode_ldimm64(insns, pc)?,
            source_pc: Some(pc),
        });
    }

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let is_32bit = insn.class() == BPF_ALU;
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_K {
            return Ok(ConstantRegValue {
                value: apply_alu_width(insn.imm as i64 as u64, is_32bit),
                source_pc: Some(pc),
            });
        }

        if op == BPF_MOV && src_mode == BPF_X {
            let resolved =
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?;
            return Ok(ConstantRegValue {
                value: apply_alu_width(resolved.value, is_32bit),
                source_pc: resolved.source_pc,
            });
        }

        let lhs = resolve_constant_reg_value_inner(insns, pc, reg, bounds, budget - 1)?;
        let rhs = if src_mode == BPF_K {
            insn.imm as i64 as u64
        } else {
            resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?.value
        };
        let value = apply_constant_alu(op, lhs.value, rhs, is_32bit).ok_or_else(|| {
            format!(
                "register r{} definition at pc {} uses unsupported constant op {:#x}",
                reg, pc, insn.code
            )
        })?;
        return Ok(ConstantRegValue {
            value,
            source_pc: None,
        });
    }

    Err(format!(
        "register r{} definition at pc {} is not a supported constant materialization",
        reg, pc
    ))
}

fn is_stack_store_at(insn: &BpfInsn, stack_off: i16) -> bool {
    matches!(bpf_class(insn.code), BPF_ST | BPF_STX)
        && bpf_mode(insn.code) == BPF_MEM
        && insn.dst_reg() == 10
        && insn.off == stack_off
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

fn truncate_imm(imm: i32, width: u8) -> u64 {
    truncate_value(imm as i64 as u64, width)
}

fn truncate_value(value: u64, width: u8) -> u64 {
    match width {
        1 => value & 0xff,
        2 => value & 0xffff,
        4 => value & 0xffff_ffff,
        8 => value,
        _ => value,
    }
}

fn prev_real_pc_bounded(insns: &[BpfInsn], pc: usize, lower_bound: usize) -> Option<usize> {
    if pc <= lower_bound {
        return None;
    }

    let mut cursor = lower_bound;
    let mut prev = None;
    while cursor < pc {
        prev = Some(cursor);
        cursor += insn_width(&insns[cursor]);
    }
    (cursor == pc)
        .then_some(prev?)
        .filter(|prev_pc| *prev_pc >= lower_bound)
}

fn find_prev_reg_def(
    insns: &[BpfInsn],
    start_pc: usize,
    reg: u8,
    lower_bound: usize,
) -> Option<usize> {
    let mut cursor = start_pc;
    while let Some(pc) = prev_real_pc_bounded(insns, cursor, lower_bound) {
        if insn_defines_reg(&insns[pc], reg) {
            return Some(pc);
        }
        cursor = pc;
    }
    None
}

fn resolve_stack_pointer_to_stack(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<i16, String> {
    resolve_stack_pointer_to_stack_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_stack_pointer_to_stack_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
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

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = &insns[pc];

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_stack_pointer_to_stack_inner(
                insns,
                pc,
                insn.src_reg(),
                bounds,
                budget - 1,
            );
        }

        if op == BPF_ADD || op == BPF_SUB {
            let base = resolve_stack_pointer_to_stack_inner(insns, pc, reg, bounds, budget - 1)?;
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?
                    .value as i64
            };
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
        "register r{} definition at pc {} does not resolve to fp-relative stack memory",
        reg, pc
    ))
}

fn decode_ldimm64(insns: &[BpfInsn], pc: usize) -> Result<u64, String> {
    let lo = insns
        .get(pc)
        .ok_or_else(|| format!("ldimm64 at pc {} is out of bounds", pc))?;
    let hi = insns
        .get(pc + 1)
        .ok_or_else(|| format!("ldimm64 at pc {} is missing high half", pc))?;
    Ok((lo.imm as u32 as u64) | ((hi.imm as u32 as u64) << 32))
}

fn apply_alu_width(value: u64, is_32bit: bool) -> u64 {
    if is_32bit {
        value as u32 as u64
    } else {
        value
    }
}

fn apply_constant_alu(op: u8, lhs: u64, rhs: u64, is_32bit: bool) -> Option<u64> {
    let value = if is_32bit {
        let lhs = lhs as u32;
        let rhs = rhs as u32;
        match op {
            BPF_ADD => lhs.wrapping_add(rhs) as u64,
            BPF_SUB => lhs.wrapping_sub(rhs) as u64,
            BPF_MUL => lhs.wrapping_mul(rhs) as u64,
            BPF_AND => (lhs & rhs) as u64,
            BPF_OR => (lhs | rhs) as u64,
            BPF_LSH => {
                if rhs >= 32 {
                    return None;
                }
                lhs.wrapping_shl(rhs) as u64
            }
            BPF_RSH => {
                if rhs >= 32 {
                    return None;
                }
                lhs.wrapping_shr(rhs) as u64
            }
            _ => return None,
        }
    } else {
        match op {
            BPF_ADD => lhs.wrapping_add(rhs),
            BPF_SUB => lhs.wrapping_sub(rhs),
            BPF_MUL => lhs.wrapping_mul(rhs),
            BPF_AND => lhs & rhs,
            BPF_OR => lhs | rhs,
            BPF_LSH => {
                if rhs >= 64 {
                    return None;
                }
                lhs.wrapping_shl(rhs as u32)
            }
            BPF_RSH => {
                if rhs >= 64 {
                    return None;
                }
                lhs.wrapping_shr(rhs as u32)
            }
            _ => return None,
        }
    };
    Some(apply_alu_width(value, is_32bit))
}

fn subprog_bounds(insns: &[BpfInsn], pc: usize) -> (usize, usize) {
    let mut starts = vec![0usize];
    let mut cursor = 0usize;
    while cursor < insns.len() {
        let insn = &insns[cursor];
        if insn.is_call() && insn.src_reg() == BPF_PSEUDO_CALL {
            let target = (cursor as i64 + 1 + insn.imm as i64) as usize;
            if target < insns.len() {
                starts.push(target);
            }
        }
        cursor += insn_width(insn);
    }

    starts.sort_unstable();
    starts.dedup();

    let mut start = 0usize;
    let mut end = insns.len();
    for (idx, subprog_start) in starts.iter().copied().enumerate() {
        if subprog_start > pc {
            break;
        }
        start = subprog_start;
        end = starts.get(idx + 1).copied().unwrap_or(insns.len());
    }
    (start, end)
}

fn site_skip_diagnostic(pc: usize, reason: &str) -> String {
    format!("site at PC={}: skip reason: {}", pc, reason)
}

fn log_map_inline_debug(message: &str) {
    eprintln!("map_inline: {}", message);
}

fn record_diagnostic(diagnostics: &mut Vec<String>, message: String) {
    log_map_inline_debug(&message);
    diagnostics.push(message);
}

fn record_skip(
    skipped: &mut Vec<SkipReason>,
    diagnostics: &mut Vec<String>,
    pc: usize,
    reason: String,
    detail: Option<String>,
) {
    skipped.push(SkipReason {
        pc,
        reason: reason.clone(),
    });
    record_diagnostic(diagnostics, site_skip_diagnostic(pc, &reason));
    if let Some(detail) = detail {
        record_diagnostic(diagnostics, detail);
    }
}

fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = String::with_capacity(preview_len.saturating_mul(2) + 6);
    out.push_str("0x");
    for byte in &bytes[..preview_len] {
        let _ = write!(out, "{:02x}", byte);
    }
    if bytes.len() > preview_len {
        out.push_str("...");
    }
    out
}

fn format_inlined_value_diagnostic(value: &[u8], loads: &[FixedLoadUse]) -> String {
    if loads.len() == 1 {
        let load = &loads[0];
        if let Some(scalar) = read_scalar_from_value(value, load.offset, load.size) {
            return format!("0x{scalar:x}");
        }
    }
    format_bytes_preview(value)
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

fn classify_r0_uses_with_options(
    insns: &[BpfInsn],
    start_pc: usize,
    allow_unrelated_helper_calls: bool,
) -> R0UseClassification {
    let mut classification = R0UseClassification::default();
    let mut alias_regs = HashSet::from([0u8]);
    let mut pc = start_pc + 1;

    while pc < insns.len() && !alias_regs.is_empty() {
        let insn = &insns[pc];
        let alias_copy_dst = alias_copy_dst(insn, &alias_regs);
        let allow_null_check =
            classification.fixed_loads.is_empty() && classification.other_uses.is_empty();

        if let Some(dst_reg) = alias_copy_dst {
            classification.alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg);
            pc += insn_width(insn);
            continue;
        }

        if allow_null_check
            && classification.null_check_pc.is_none()
            && is_null_check_on_alias(insn, &alias_regs)
        {
            classification.null_check_pc = Some(pc);
            let Some(next_pc) = advance_to_non_null_path(pc, insn, insns.len()) else {
                break;
            };
            pc = next_pc;
            continue;
        }

        if !classification.fixed_loads.is_empty() && ends_current_use_region(insn, &alias_regs) {
            break;
        }

        if insn.is_call() {
            if allow_unrelated_helper_calls {
                let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
                if !surviving_aliases.is_empty() {
                    alias_regs = surviving_aliases;
                    pc += insn_width(insn);
                    continue;
                }
            }
            classification.other_uses.push(pc);
            break;
        }

        if insn.is_ldx_mem() && alias_regs.contains(&insn.src_reg()) {
            classification.fixed_loads.push(FixedLoadUse {
                pc,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: insn.off,
            });
        } else if insn_uses_any_alias(insn, &alias_regs) {
            classification.other_uses.push(pc);
        }

        kill_defined_alias_regs(&mut alias_regs, insn);

        pc += insn_width(insn);
    }

    classification
}

fn surviving_alias_regs_after_helper_call(alias_regs: &HashSet<u8>) -> HashSet<u8> {
    alias_regs
        .iter()
        .copied()
        .filter(|reg| (6..=9).contains(reg))
        .collect()
}

fn advance_to_non_null_path(pc: usize, insn: &BpfInsn, insn_count: usize) -> Option<usize> {
    let fallthrough_pc = pc + insn_width(insn);
    match bpf_op(insn.code) {
        BPF_JEQ => (fallthrough_pc < insn_count).then_some(fallthrough_pc),
        BPF_JNE => jump_target_pc(pc, insn, insn_count),
        _ => None,
    }
}

fn jump_target_pc(pc: usize, insn: &BpfInsn, insn_count: usize) -> Option<usize> {
    let target = pc as isize + 1 + insn.off as isize;
    (0..insn_count as isize)
        .contains(&target)
        .then_some(target as usize)
}

fn ends_current_use_region(insn: &BpfInsn, alias_regs: &HashSet<u8>) -> bool {
    (insn.is_jmp_class()
        && !insn.is_call()
        && !insn.is_exit()
        && !insn_uses_any_alias(insn, alias_regs))
        || starts_next_lookup_setup(insn)
}

fn starts_next_lookup_setup(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_MAP_FD
}

fn alias_copy_dst(insn: &BpfInsn, alias_regs: &HashSet<u8>) -> Option<u8> {
    (insn.code == (BPF_ALU64 | BPF_MOV | BPF_X) && alias_regs.contains(&insn.src_reg()))
        .then_some(insn.dst_reg())
}

fn is_null_check_on_alias(insn: &BpfInsn, alias_regs: &HashSet<u8>) -> bool {
    insn.class() == BPF_JMP
        && matches!(bpf_op(insn.code), BPF_JEQ | BPF_JNE)
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
        && alias_regs.contains(&insn.dst_reg())
}

fn null_check_is_fallthrough_non_null(insn: &BpfInsn) -> bool {
    insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
}

fn insn_uses_any_alias(insn: &BpfInsn, alias_regs: &HashSet<u8>) -> bool {
    alias_regs
        .iter()
        .copied()
        .any(|reg| insn_uses_reg(insn, reg))
}

fn kill_defined_alias_regs(alias_regs: &mut HashSet<u8>, insn: &BpfInsn) {
    for reg in 0..=10 {
        if insn_defines_reg(insn, reg) {
            alias_regs.remove(&reg);
        }
    }
}

fn insn_uses_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            if bpf_op(insn.code) == BPF_MOV {
                (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
                    || (bpf_src(insn.code) != BPF_X && false)
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        BPF_LDX => insn.src_reg() == reg,
        BPF_ST => insn.dst_reg() == reg,
        BPF_STX => insn.dst_reg() == reg || insn.src_reg() == reg,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                (1..=5).contains(&reg)
            } else if insn.is_exit() {
                reg == 0
            } else if insn.is_ja() {
                false
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        _ => false,
    }
}

fn insn_defines_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        BPF_JMP | BPF_JMP32 => insn.is_call() && reg <= 5,
        _ => false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;

    use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
    use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
    use crate::pass::{MapInlineRecord, PassContext, PassManager};

    fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_DW | BPF_IMM,
                regs: BpfInsn::make_regs(dst, src),
                off: 0,
                imm,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ]
    }

    fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ST | size | BPF_MEM,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ALU64 | BPF_ADD | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off: 0,
            imm,
        }
    }

    fn call_helper(imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
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

    fn ja(off: i16) -> BpfInsn {
        BpfInsn::ja(off)
    }

    fn install_map(
        map_id: u32,
        map_type: u32,
        max_entries: u32,
        frozen: bool,
        values: HashMap<Vec<u8>, Vec<u8>>,
    ) {
        let mut info = BpfMapInfo::default();
        info.map_type = map_type;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = values.values().next().map(|value| value.len()).unwrap_or(0) as u32;
        info.max_entries = max_entries;

        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen,
                values,
            },
        );
    }

    fn install_percpu_array_map(
        map_id: u32,
        value_size: u32,
        max_entries: u32,
        frozen: bool,
        values: HashMap<Vec<u8>, Vec<u8>>,
    ) {
        let mut info = BpfMapInfo::default();
        info.map_type = BPF_MAP_TYPE_PERCPU_ARRAY;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = value_size;
        info.max_entries = max_entries;

        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen,
                values,
            },
        );
    }

    fn make_percpu_blob(slot_value: &[u8], slots: usize) -> Vec<u8> {
        let stride = round_up_8(slot_value.len());
        let mut blob = vec![0u8; stride * slots];
        for slot in 0..slots {
            let offset = slot * stride;
            blob[offset..offset + slot_value.len()].copy_from_slice(slot_value);
        }
        blob
    }

    fn install_array_map(map_id: u32, value: Vec<u8>) {
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), value);
        install_map(map_id, 2, 8, true, values);
    }

    fn install_hash_map(map_id: u32, value: Vec<u8>) {
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), value);
        install_map(map_id, 1, 8, true, values);
    }

    fn install_mutable_array_map(map_id: u32, value: Vec<u8>) {
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), value);
        install_map(map_id, 2, 8, false, values);
    }

    fn run_map_inline_pass(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(MapInfoAnalysis);
        pm.add_pass(MapInlinePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    #[test]
    fn find_map_lookup_sites_matches_helper_one_with_map_arg() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let sites = find_map_lookup_sites(&insns);
        assert_eq!(
            sites,
            vec![MapLookupSite {
                call_pc: 5,
                map_load_pc: 0,
            }]
        );
    }

    #[test]
    fn find_map_lookup_sites_ignores_calls_without_map_load() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 0),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        assert!(find_map_lookup_sites(&insns).is_empty());
    }

    #[test]
    fn extract_constant_key_from_direct_stack_store() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 5).unwrap();
        assert_eq!(key.stack_off, -4);
        assert_eq!(key.width, 4);
        assert_eq!(key.value, 7);
        assert_eq!(key.store_pc, 2);
        assert_eq!(key.source_imm_pc, None);
    }

    #[test]
    fn extract_constant_key_from_stx_stack_store() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            BpfInsn::mov64_imm(3, 9),
            BpfInsn::stx_mem(BPF_W, 10, 3, -4),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 6).unwrap();
        assert_eq!(key.value, 9);
        assert_eq!(key.store_pc, 3);
        assert_eq!(key.source_imm_pc, Some(2));
    }

    #[test]
    fn extract_constant_key_from_r2_copy_chain() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(6, 10),
            add64_imm(6, -4),
            BpfInsn::mov64_reg(2, 6),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 6).unwrap();
        assert_eq!(key.stack_off, -4);
        assert_eq!(key.value, 7);
        assert_eq!(key.r2_mov_pc, None);
        assert_eq!(key.r2_add_pc, None);
    }

    #[test]
    fn extract_constant_key_from_r2_add_reg_constant() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(2, 10),
            BpfInsn::mov64_imm(3, -4),
            BpfInsn::alu64_reg(BPF_ADD, 2, 3),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 6).unwrap();
        assert_eq!(key.stack_off, -4);
        assert_eq!(key.value, 7);
    }

    #[test]
    fn extract_constant_key_from_ldimm64_stack_store() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let key_imm = emit_ldimm64(3, 0x1_0000_0001);
        let insns = vec![
            key_imm[0],
            key_imm[1],
            BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -8),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 7).unwrap();
        assert_eq!(key.stack_off, -8);
        assert_eq!(key.width, 8);
        assert_eq!(key.value, 0x1_0000_0001);
        assert_eq!(key.source_imm_pc, Some(0));
    }

    #[test]
    fn classify_r0_uses_collects_fixed_loads_until_redefinition() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
            BpfInsn::ldx_mem(BPF_B, 4, 0, 7),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::ldx_mem(BPF_W, 5, 0, 0),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(
            uses.fixed_loads,
            vec![
                FixedLoadUse {
                    pc: 1,
                    dst_reg: 3,
                    size: BPF_W,
                    offset: 0,
                },
                FixedLoadUse {
                    pc: 2,
                    dst_reg: 4,
                    size: BPF_B,
                    offset: 7,
                },
            ]
        );
        assert!(uses.other_uses.is_empty());
    }

    #[test]
    fn classify_r0_uses_tracks_alias_copies_and_guarded_loads() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 1),
            BpfInsn::ldx_mem(BPF_W, 3, 6, 0),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(uses.fixed_loads.len(), 1);
        assert!(uses.other_uses.is_empty());
        assert_eq!(uses.alias_copy_pcs, vec![1]);
        assert_eq!(uses.null_check_pc, Some(2));
        assert!(uses.all_fixed_loads());
    }

    #[test]
    fn classify_r0_uses_can_follow_callee_saved_alias_across_helper_when_enabled() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(9, 0),
            jeq_imm(9, 0, 2),
            call_helper(2),
            BpfInsn::ldx_mem(BPF_W, 3, 9, 4),
        ];

        let strict_uses = classify_r0_uses(&insns, 0);
        assert_eq!(strict_uses.other_uses, vec![3]);
        assert!(strict_uses.fixed_loads.is_empty());

        let relaxed_uses = classify_r0_uses_with_options(&insns, 0, true);
        assert_eq!(relaxed_uses.null_check_pc, Some(2));
        assert_eq!(relaxed_uses.other_uses, Vec::<usize>::new());
        assert_eq!(
            relaxed_uses.fixed_loads,
            vec![FixedLoadUse {
                pc: 4,
                dst_reg: 3,
                size: BPF_W,
                offset: 4,
            }]
        );
    }

    #[test]
    fn classify_r0_uses_marks_pointer_escape_after_null_check_as_other() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::mov64_reg(1, 0),
            call_helper(2),
            BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(uses.null_check_pc, Some(1));
        assert_eq!(uses.other_uses, vec![3]);
        assert!(!uses.all_fixed_loads());
    }

    #[test]
    fn map_inline_pass_rewrites_lookup_and_scalar_loads() {
        install_array_map(101, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::ldx_mem(BPF_B, 7, 0, 4),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![101]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(7, 0xaa),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_rewrites_loads_from_alias_register() {
        install_array_map(120, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 1),
            BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![120]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(7, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_rewrites_struct_value_multiple_fields() {
        let mut value = vec![0u8; 16];
        value[0..4].copy_from_slice(&0x1234_5678u32.to_le_bytes());
        value[8..16].copy_from_slice(&0x0123_4567_89ab_cdefu64.to_le_bytes());
        install_array_map(110, value);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::ldx_mem(BPF_DW, 7, 0, 8),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![110]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(program.insns.len(), 5);
        assert_eq!(program.insns[0], BpfInsn::mov64_imm(6, 0x1234_5678i32));
        assert!(program.insns[1].is_ldimm64());
        assert_eq!(program.insns[1].dst_reg(), 7);
        assert_eq!(program.insns[1].imm as u32 as u64, 0x89ab_cdef);
        assert_eq!(program.insns[2].imm as u32 as u64, 0x0123_4567);
        assert_eq!(program.insns[3], BpfInsn::mov64_imm(0, 0));
        assert_eq!(program.insns[4], exit_insn());
    }

    #[test]
    fn map_inline_pass_removes_null_check_and_dead_cold_block() {
        install_array_map(102, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![102]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_emits_ldimm64_for_wide_constants() {
        install_array_map(103, 0x1_0000_0000u64.to_le_bytes().to_vec());

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![103]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(program.insns.len(), 4);
        assert!(program.insns[0].is_ldimm64());
        assert_eq!(program.insns[0].dst_reg(), 6);
        assert_eq!(program.insns[0].imm as u32 as u64, 0);
        assert_eq!(program.insns[1].imm as u32 as u64, 1);
    }

    #[test]
    fn map_inline_pass_emits_mov64_imm_for_dw_constants_that_fit_i32() {
        install_array_map(1513, 42u64.to_le_bytes().to_vec());

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![1513]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 42),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
        assert!(!program.insns[0].is_ldimm64());
    }

    #[test]
    fn map_inline_pass_skips_non_constant_key() {
        install_array_map(104, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            BpfInsn::stx_mem(BPF_W, 10, 3, -4),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![104]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("constant stack materialization")));
        assert!(result.pass_results[0]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("key extraction failed")));
    }

    #[test]
    fn test_map_inline_real_clang_order() {
        install_array_map(117, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![117]);

        let key = extract_constant_key(&program.insns, 5).unwrap();
        assert_eq!(key.value, 1);
        assert_eq!(key.stack_off, -4);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn test_map_inline_interleaved_arg_setup() {
        install_array_map(118, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            BpfInsn::mov64_imm(3, 9),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![118]);

        let key = extract_constant_key(&program.insns, 6).unwrap();
        assert_eq!(key.value, 1);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(program.insns[7], BpfInsn::mov64_imm(6, 7));
        assert_eq!(program.insns.last().copied(), Some(exit_insn()));
    }

    #[test]
    fn test_map_inline_r2_clobbered_between() {
        install_array_map(119, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            BpfInsn::mov64_imm(2, 0),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![119]);

        assert!(extract_constant_key(&program.insns, 6).is_none());

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("constant stack materialization")));
    }

    #[test]
    fn map_inline_pass_keeps_hash_lookup_and_null_check() {
        install_hash_map(105, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![105]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                map[0],
                map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jeq_imm(0, 0, 3),
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                ja(1),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
        assert_eq!(
            result.pass_results[0]
                .diagnostics
                .iter()
                .any(|diag| diag.contains("site at PC=5: inlined successfully")),
            true
        );
        assert_eq!(
            result.pass_results[0]
                .diagnostics
                .iter()
                .any(|diag| diag.contains("site at PC=5: inlined successfully, value=0x7")),
            true
        );
        assert_eq!(
            result.pass_results[0]
                .diagnostics
                .iter()
                .any(|diag| diag.contains("speculative map-inline sites: 1")),
            true
        );
    }

    #[test]
    fn map_inline_pass_keeps_hash_lookup_and_rewrites_alias_load() {
        install_hash_map(121, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![121]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                map[0],
                map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::mov64_reg(6, 0),
                jeq_imm(6, 0, 3),
                BpfInsn::mov64_imm(7, 7),
                BpfInsn::mov64_imm(0, 0),
                ja(1),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn classify_r0_uses_tracks_jne_null_check() {
        let uses = classify_r0_uses(
            &[
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jne_imm(0, 0, 1),
                ja(2),
                BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ],
            0,
        );

        assert_eq!(uses.null_check_pc, Some(1));
        assert_eq!(
            uses.fixed_loads,
            vec![FixedLoadUse {
                pc: 3,
                dst_reg: 6,
                size: BPF_W,
                offset: 0,
            }]
        );
        assert!(uses.other_uses.is_empty());
    }

    #[test]
    fn map_inline_pass_keeps_hash_lookup_and_rewrites_jne_guarded_load() {
        install_hash_map(122, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jne_imm(0, 0, 1),
            ja(3),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![122]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                map[0],
                map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jne_imm(0, 0, 1),
                ja(3),
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_skips_pointer_escape_to_helper() {
        install_array_map(106, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_reg(1, 0),
            call_helper(2),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![106]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("non-load uses")));
    }

    #[test]
    fn map_inline_pass_skips_lookup_result_write_back() {
        install_array_map(116, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            st_mem(BPF_W, 0, 0, 99),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![116]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("non-load uses")));
    }

    #[test]
    fn map_inline_pass_rewrites_multiple_lookup_sites() {
        install_array_map(107, vec![7, 0, 0, 0]);
        install_array_map(108, vec![9, 0, 0, 0]);

        let map0 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let map1 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 43);
        let mut program = BpfProgram::new(vec![
            map0[0],
            map0[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            map1[0],
            map1[1],
            st_mem(BPF_W, 10, -8, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -8),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![107, 108]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(7, 9),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_rewrites_lookup_inside_subprog() {
        install_array_map(109, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            BpfInsn {
                code: BPF_JMP | BPF_CALL,
                regs: BpfInsn::make_regs(0, 1),
                off: 0,
                imm: 2,
            },
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(9, 0),
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![109]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(program.insns[0].imm, 2);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn {
                    code: BPF_JMP | BPF_CALL,
                    regs: BpfInsn::make_regs(0, 1),
                    off: 0,
                    imm: 2,
                },
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
                BpfInsn::mov64_imm(9, 0),
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_inlines_non_frozen_array_maps() {
        install_mutable_array_map(111, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![111]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_records_inlined_sites_for_tracker() {
        let value = vec![7, 0, 0, 0];
        install_array_map(115, value.clone());

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![115]);

        let result = run_map_inline_pass(&mut program);

        assert_eq!(
            result.pass_results[0].map_inline_records,
            vec![MapInlineRecord {
                map_id: 115,
                key: 1u32.to_le_bytes().to_vec(),
                expected_value: value,
            }]
        );
    }

    #[test]
    fn map_inline_pass_inlines_uniform_percpu_array_maps() {
        let blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), blob.clone());
        install_percpu_array_map(112, 4, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![112]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert!(
            !program
                .insns
                .iter()
                .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)
        );
        assert!(program.insns.iter().any(|insn| insn == &BpfInsn::mov64_imm(6, 7)));
        assert!(
            result.pass_results[0].map_inline_records[0].expected_value == blob,
            "tracker should store the full per-cpu blob: {:?}",
            result.pass_results[0].map_inline_records
        );
    }

    #[test]
    fn map_inline_pass_skips_mixed_percpu_array_maps() {
        let mut blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
        blob[8..12].copy_from_slice(&9u32.to_le_bytes());
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), blob);
        install_percpu_array_map(212, 4, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![212]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(
            result.pass_results[0]
                .sites_skipped
                .iter()
                .any(|skip| skip.reason.contains("PERCPU_ARRAY value differs across CPUs")),
            "mixed PERCPU_ARRAY should be rejected with a precise reason: {:?}",
            result.pass_results[0].sites_skipped
        );
    }

    /// PERCPU_HASH maps must not be inlined either.
    #[test]
    fn map_inline_pass_skips_percpu_hash_maps() {
        // map_type 5 = BPF_MAP_TYPE_PERCPU_HASH
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
        install_map(113, 5, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![113]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(
            result.pass_results[0]
                .sites_skipped
                .iter()
                .any(|skip| skip.reason.contains("not inlineable")),
            "PERCPU_HASH should be rejected: {:?}",
            result.pass_results[0].sites_skipped
        );
    }

    /// LRU_PERCPU_HASH maps must not be inlined either.
    #[test]
    fn map_inline_pass_skips_lru_percpu_hash_maps() {
        // map_type 10 = BPF_MAP_TYPE_LRU_PERCPU_HASH
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
        install_map(114, 10, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![114]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(
            result.pass_results[0]
                .sites_skipped
                .iter()
                .any(|skip| skip.reason.contains("not inlineable")),
            "LRU_PERCPU_HASH should be rejected: {:?}",
            result.pass_results[0].sites_skipped
        );
    }
}
