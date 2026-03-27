// SPDX-License-Identifier: MIT
// Scan helpers for dynamic map inlining.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fmt::Write as _;
use std::sync::OnceLock;

use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
use crate::bpf;
use crate::insn::*;
use crate::pass::*;
use crate::verifier_log::VerifierInsn;

const BPF_ADD: u8 = 0x00;
const BPF_SUB: u8 = 0x10;
const BPF_MUL: u8 = 0x20;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = 6;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;
const HELPER_KTIME_GET_NS: i32 = 5;
const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const CONST_STACK_VALUE_LOOKBACK_LIMIT: usize = 256;
const MAP_INLINE_FIXED_POINT_MAX_ITERS: usize = 8;
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
    pub bytes: Vec<u8>,
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

#[derive(Clone, Debug)]
struct FrozenMapValue {
    map_id: u32,
    value: Vec<u8>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
enum KeyPointerOrigin {
    Stack(i16),
    MapValue {
        old_fd: i32,
        value_off: i32,
        ldimm_pc: usize,
    },
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
    let mut last_err = None;
    let mut extracted = None;
    for width in [8u8, 4, 2, 1] {
        match find_constant_stack_bytes(insns, call_pc, bounds, stack_off, width) {
            Ok((store_pc, source_imm_pc, bytes)) => {
                extracted = Some((store_pc, source_imm_pc, width, bytes));
                break;
            }
            Err(err) => last_err = Some(err),
        }
    }
    let (store_pc, source_imm_pc, width, bytes) = extracted.ok_or_else(|| {
        last_err.unwrap_or_else(|| format!("no stack store found for fp{}", stack_off))
    })?;
    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width,
        value: constant_key_value(&bytes),
        bytes,
        store_pc,
        source_imm_pc,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

fn try_extract_constant_key_sized(
    insns: &[BpfInsn],
    call_pc: usize,
    key_size: u32,
) -> Result<ConstantKey, String> {
    if key_size == 0 {
        return Err("map key size is zero".to_string());
    }

    let bounds = subprog_bounds(insns, call_pc);
    let stack_off = resolve_stack_pointer_to_stack(insns, call_pc, 2, bounds)?;
    let key_width = u8::try_from(key_size)
        .map_err(|_| format!("map key size {} does not fit in u8", key_size))?;
    let (store_pc, source_imm_pc, bytes) =
        find_constant_stack_bytes(insns, call_pc, bounds, stack_off, key_width)?;

    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width: key_width,
        value: constant_key_value(&bytes),
        bytes,
        store_pc,
        source_imm_pc,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

fn try_extract_constant_key_from_map_value(
    program: &BpfProgram,
    call_pc: usize,
    info: &crate::analysis::MapInfo,
) -> Result<ConstantKey, String> {
    let key_width = u8::try_from(info.key_size)
        .map_err(|_| format!("map key size {} does not fit in u8", info.key_size))?;
    if key_width == 0 {
        return Err("map key size is zero".to_string());
    }

    let bounds = subprog_bounds(&program.insns, call_pc);
    let origin = resolve_key_pointer_origin(&program.insns, call_pc, 2, bounds)?;
    let KeyPointerOrigin::MapValue {
        old_fd,
        value_off,
        ldimm_pc,
    } = origin
    else {
        return Err("key pointer does not resolve to a pseudo-map-value constant".to_string());
    };

    if value_off < 0 {
        return Err(format!(
            "pseudo-map-value key offset {} is negative",
            value_off
        ));
    }

    let source_map_id = program
        .map_fd_bindings
        .get(&old_fd)
        .copied()
        .ok_or_else(|| format!("no map_id binding for pseudo-map-value old_fd {}", old_fd))?;
    let (source_info, source_frozen) =
        bpf::bpf_map_get_info_by_id(source_map_id).map_err(|err| {
            format!(
                "failed to resolve pseudo-map-value source map {}: {err:#}",
                source_map_id
            )
        })?;
    if !source_frozen {
        return Err(format!(
            "pseudo-map-value source map {} is mutable",
            source_map_id
        ));
    }

    let source_key = vec![0u8; source_info.key_size as usize];
    let source_value_size = bpf::bpf_map_lookup_value_size(&source_info);
    let source_value =
        bpf::bpf_map_lookup_elem_by_id(source_map_id, &source_key, source_value_size).map_err(
            |err| {
                format!(
                    "failed to read pseudo-map-value source map {}: {err:#}",
                    source_map_id
                )
            },
        )?;
    let value_off = value_off as usize;
    let key_end = value_off
        .checked_add(info.key_size as usize)
        .ok_or_else(|| "pseudo-map-value key offset overflows".to_string())?;
    if key_end > source_value.len() {
        return Err(format!(
            "pseudo-map-value key range [{}..{}) exceeds source map value length {}",
            value_off,
            key_end,
            source_value.len()
        ));
    }

    let bytes = source_value[value_off..key_end].to_vec();
    Ok(ConstantKey {
        stack_off: 0,
        width: key_width,
        value: constant_key_value(&bytes),
        bytes,
        // Reuse the removable-pc slots so a contiguous `ldimm64 r2 =
        // pseudo_map_value` setup can be dropped alongside the lookup.
        store_pc: ldimm_pc,
        source_imm_pc: Some(ldimm_pc + 1),
        r2_mov_pc: None,
        r2_add_pc: None,
    })
}

fn try_extract_constant_key_verifier_guided(
    insns: &[BpfInsn],
    verifier_states: &[VerifierInsn],
    call_pc: usize,
    key_size: u32,
) -> Result<ConstantKey, String> {
    if verifier_states.is_empty() {
        return Err("no verifier states available".to_string());
    }
    if key_size == 0 {
        return Err("map key size is zero".to_string());
    }
    if key_size > 8 {
        return Err(format!(
            "verifier-guided constant-key extraction currently supports up to 8-byte keys (got {})",
            key_size
        ));
    }
    let key_width: u8 = key_size
        .try_into()
        .map_err(|_| format!("map key size {} does not fit in u8", key_size))?;

    let occurrences = verifier_states
        .iter()
        .enumerate()
        .filter(|(_, state)| state.pc == call_pc)
        .collect::<Vec<_>>();
    if occurrences.is_empty() {
        return Err(format!(
            "verifier log has no state snapshot at call pc {}",
            call_pc
        ));
    }

    let mut extracted = Vec::new();
    for (occ_idx, state) in occurrences {
        extracted.push(try_extract_constant_key_for_occurrence(
            insns,
            verifier_states,
            call_pc,
            key_width,
            occ_idx,
            state.frame,
        )?);
    }

    let first = extracted
        .first()
        .cloned()
        .ok_or_else(|| format!("no verifier-guided key candidates at pc {}", call_pc))?;
    let all_same = extracted.iter().all(|key| {
        key.stack_off == first.stack_off
            && key.width == first.width
            && key.bytes == first.bytes
            && key.store_pc == first.store_pc
    });
    if !all_same {
        return Err(format!(
            "verifier-derived key candidates disagree across {} state(s)",
            extracted.len()
        ));
    }

    Ok(first)
}

fn try_extract_constant_key_for_occurrence(
    insns: &[BpfInsn],
    verifier_states: &[VerifierInsn],
    call_pc: usize,
    key_width: u8,
    occurrence_idx: usize,
    frame: usize,
) -> Result<ConstantKey, String> {
    let key_off =
        find_latest_r2_stack_offset(verifier_states, occurrence_idx, frame).ok_or_else(|| {
            format!(
                "verifier log did not expose r2 stack pointer before pc {}",
                call_pc
            )
        })?;

    let (store_pc, source_imm_pc, value) =
        find_verifier_guided_stack_store(insns, verifier_states, occurrence_idx, frame, key_off, key_width)
            .ok_or_else(|| {
                format!(
                    "verifier log did not expose a constant stack store covering fp{} width {} before pc {}",
                    key_off, key_width, call_pc
                )
            })?;

    let bounds = subprog_bounds(insns, call_pc);
    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == key_off);

    Ok(ConstantKey {
        stack_off: key_off,
        width: key_width,
        value,
        bytes: value.to_le_bytes()[..key_width as usize].to_vec(),
        store_pc,
        source_imm_pc,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

fn find_latest_r2_stack_offset(
    verifier_states: &[VerifierInsn],
    before_idx: usize,
    frame: usize,
) -> Option<i16> {
    for idx in (0..before_idx).rev() {
        let state = &verifier_states[idx];
        if state.frame != frame {
            continue;
        }
        let Some(reg) = state.regs.get(&2) else {
            continue;
        };
        if reg.reg_type != "fp" {
            return None;
        }
        return reg.offset.map(|off| off as i16);
    }
    None
}

fn constant_key_value(bytes: &[u8]) -> u64 {
    let mut buf = [0u8; 8];
    let copy_len = bytes.len().min(buf.len());
    buf[..copy_len].copy_from_slice(&bytes[..copy_len]);
    u64::from_le_bytes(buf)
}

fn format_constant_key(key: &ConstantKey) -> String {
    if key.bytes.len() <= 8 {
        format!("0x{:x}", key.value)
    } else {
        format_bytes_preview(&key.bytes)
    }
}

fn find_constant_stack_bytes(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: u8,
) -> Result<(usize, Option<usize>, Vec<u8>), String> {
    find_constant_stack_bytes_with_limit(insns, before_pc, bounds, stack_off, key_width, None)
}

fn find_constant_stack_bytes_with_limit(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: u8,
    mut lookback_limit: Option<usize>,
) -> Result<(usize, Option<usize>, Vec<u8>), String> {
    let key_width_usize = usize::from(key_width);
    let target_start = i32::from(stack_off);
    let target_end = target_start + i32::from(key_width);
    let mut raw = vec![None; key_width_usize];
    let mut latest_store_pc = None;
    let mut latest_source_imm_pc = None;
    let mut cursor = before_pc;

    while let Some(pc) = prev_real_pc_bounded(insns, cursor, bounds.0) {
        if let Some(remaining) = lookback_limit.as_mut() {
            if *remaining == 0 {
                break;
            }
            *remaining -= 1;
        }

        let insn = &insns[pc];
        if !matches!(bpf_class(insn.code), BPF_ST | BPF_STX)
            || bpf_mode(insn.code) != BPF_MEM
            || insn.dst_reg() != 10
        {
            cursor = pc;
            continue;
        }

        let width = size_in_bytes(bpf_size(insn.code)).ok_or_else(|| {
            format!(
                "stack store at pc {} uses unsupported width opcode {:#x}",
                pc, insn.code
            )
        })?;
        let store_start = i32::from(insn.off);
        let store_end = store_start + i32::from(width);
        let overlap_start = target_start.max(store_start);
        let overlap_end = target_end.min(store_end);
        if overlap_start >= overlap_end {
            cursor = pc;
            continue;
        }

        let bytes = constant_stack_store_bytes(insns, pc, bounds)?;
        let source_imm_pc = constant_stack_store_source_pc(insns, pc, bounds)?;
        for absolute_off in overlap_start..overlap_end {
            let key_idx = usize::try_from(absolute_off - target_start).unwrap_or(usize::MAX);
            if key_idx >= key_width_usize || raw[key_idx].is_some() {
                continue;
            }
            let store_idx = usize::try_from(absolute_off - store_start).unwrap_or(usize::MAX);
            if store_idx >= bytes.len() {
                return Err(format!(
                    "stack store at pc {} does not cover expected byte offset {}",
                    pc, absolute_off
                ));
            }
            raw[key_idx] = Some(bytes[store_idx]);
            latest_store_pc.get_or_insert(pc);
            if latest_source_imm_pc.is_none() {
                latest_source_imm_pc = source_imm_pc;
            }
        }

        if raw.iter().all(Option::is_some) {
            let bytes = raw
                .into_iter()
                .map(|byte| byte.unwrap_or(0))
                .collect::<Vec<_>>();
            return Ok((
                latest_store_pc.unwrap_or(pc),
                latest_source_imm_pc,
                bytes,
            ));
        }

        cursor = pc;
    }

    Err(format!(
        "no constant stack store sequence found for fp{} width {}",
        stack_off, key_width
    ))
}

fn constant_stack_store_bytes(
    insns: &[BpfInsn],
    store_pc: usize,
    bounds: (usize, usize),
) -> Result<Vec<u8>, String> {
    let insn = &insns[store_pc];
    let width = size_in_bytes(bpf_size(insn.code)).ok_or_else(|| {
        format!(
            "stack store at pc {} uses unsupported width opcode {:#x}",
            store_pc, insn.code
        )
    })?;

    let value = if bpf_class(insn.code) == BPF_ST {
        truncate_imm(insn.imm, width)
    } else if bpf_class(insn.code) == BPF_STX {
        let resolved = resolve_constant_reg_value(insns, store_pc, insn.src_reg(), bounds)?;
        truncate_value(resolved.value, width)
    } else {
        return Err(format!("instruction at pc {} is not a stack store", store_pc));
    };

    Ok(value.to_le_bytes()[..usize::from(width)].to_vec())
}

fn constant_stack_store_source_pc(
    insns: &[BpfInsn],
    store_pc: usize,
    bounds: (usize, usize),
) -> Result<Option<usize>, String> {
    let insn = &insns[store_pc];
    if bpf_class(insn.code) == BPF_ST {
        return Ok(None);
    }
    if bpf_class(insn.code) != BPF_STX {
        return Err(format!("instruction at pc {} is not a stack store", store_pc));
    }
    Ok(resolve_constant_reg_value(insns, store_pc, insn.src_reg(), bounds)?.source_pc)
}

fn find_verifier_guided_stack_store(
    insns: &[BpfInsn],
    verifier_states: &[VerifierInsn],
    before_idx: usize,
    frame: usize,
    key_off: i16,
    key_width: u8,
) -> Option<(usize, Option<usize>, u64)> {
    for idx in (0..before_idx).rev() {
        let state = &verifier_states[idx];
        if state.frame != frame {
            continue;
        }
        let pc = state.pc;
        let Some(insn) = insns.get(pc) else {
            continue;
        };
        let Some((store_pc, source_imm_pc, value)) =
            verifier_guided_stack_store_value(insn, state, key_off, key_width)
        else {
            continue;
        };
        return Some((store_pc, source_imm_pc, value));
    }
    None
}

fn verifier_guided_stack_store_value(
    insn: &BpfInsn,
    state: &VerifierInsn,
    key_off: i16,
    key_width: u8,
) -> Option<(usize, Option<usize>, u64)> {
    if !matches!(bpf_class(insn.code), BPF_ST | BPF_STX)
        || bpf_mode(insn.code) != BPF_MEM
        || insn.dst_reg() != 10
    {
        return None;
    }

    let store_width = size_in_bytes(bpf_size(insn.code))?;
    let store_start = i32::from(insn.off);
    let store_end = store_start + i32::from(store_width);
    let key_start = i32::from(key_off);
    let key_end = key_start + i32::from(key_width);
    if store_start > key_start || store_end < key_end {
        return None;
    }

    let raw_value = match bpf_class(insn.code) {
        BPF_ST => truncate_imm(insn.imm, store_width),
        BPF_STX => truncate_value(
            verifier_known_scalar_value(state.regs.get(&insn.src_reg())?)?,
            store_width,
        ),
        _ => return None,
    };

    let full_bytes = raw_value.to_le_bytes();
    let subrange_start = usize::try_from(key_start - store_start).ok()?;
    let subrange_end = subrange_start + key_width as usize;
    let mut key_bytes = [0u8; 8];
    key_bytes[..key_width as usize].copy_from_slice(&full_bytes[subrange_start..subrange_end]);

    Some((state.pc, None, u64::from_le_bytes(key_bytes)))
}

fn verifier_known_scalar_value(reg: &crate::verifier_log::RegState) -> Option<u64> {
    if reg.reg_type != "scalar" {
        return None;
    }
    reg.known_value.map(|value| value as u64)
}

/// Classify all uses of the lookup result until its value-pointer aliases die out.
pub fn classify_r0_uses(insns: &[BpfInsn], call_pc: usize) -> R0UseClassification {
    classify_r0_uses_with_options(insns, call_pc, false, false)
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
        let mut total_applied = 0usize;
        let mut total_changed = false;
        let mut final_skipped = Vec::new();
        let mut diagnostics = Vec::new();
        let mut map_inline_records = Vec::new();
        let mut hit_iteration_cap = false;

        for iter in 0..MAP_INLINE_FIXED_POINT_MAX_ITERS {
            let round = run_map_inline_round(program, analyses, iter == 0)?;
            let round_changed = round.changed;

            final_skipped = round.sites_skipped;
            total_applied += round.sites_applied;
            total_changed |= round_changed;
            map_inline_records.extend(round.map_inline_records);
            if iter == 0 {
                diagnostics.extend(round.diagnostics);
            } else {
                diagnostics.extend(
                    round
                        .diagnostics
                        .into_iter()
                        .map(|diag| format!("round {}: {}", iter + 1, diag)),
                );
            }

            if !round_changed {
                break;
            }

            analyses.invalidate_all();
            hit_iteration_cap = iter + 1 == MAP_INLINE_FIXED_POINT_MAX_ITERS;
        }

        if hit_iteration_cap {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "stopped after {} map_inline fixpoint rounds",
                    MAP_INLINE_FIXED_POINT_MAX_ITERS
                ),
            );
        }

        if total_changed {
            program.log_transform(TransformEntry {
                sites_applied: total_applied,
            });
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: total_changed,
            sites_applied: total_applied,
            sites_skipped: final_skipped,
            diagnostics,
            map_inline_records,
            ..Default::default()
        })
    }
}

fn run_map_inline_round(
    program: &mut BpfProgram,
    analyses: &mut AnalysisCache,
    use_verifier_guided_keys: bool,
) -> anyhow::Result<PassResult> {
    let bt = analyses.get(&BranchTargetAnalysis, program);
    let map_info = analyses.get(&MapInfoAnalysis, program);
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    let (direct_replacements, direct_sites_applied, direct_diagnostics) =
        build_direct_map_value_load_rewrites(program);
    diagnostics.extend(direct_diagnostics);
    let sites = find_map_lookup_sites(&program.insns);

    log_map_inline_debug(&format!(
        "found {} lookup sites (verifier_guided_keys={})",
        sites.len(),
        use_verifier_guided_keys
    ));

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

        let key = match extract_site_constant_key(
            program,
            site.call_pc,
            info,
            use_verifier_guided_keys,
        ) {
            Ok(key) => key,
            Err(detail) => {
                record_skip(
                    &mut skipped,
                    &mut diagnostics,
                    site.call_pc,
                    "lookup key is not a constant stack or pseudo-map-value materialization"
                        .into(),
                    Some(format!("site at PC={}: {}", site.call_pc, detail)),
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
        if info.can_remove_lookup_pattern_v1()
            && key.bytes.len() <= 8
            && key.value >= info.max_entries as u64
        {
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
            info.can_remove_lookup_pattern_v1(),
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
            let reason = "lookup result is not consumed by fixed-offset scalar loads".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        let rewrite = match build_site_rewrite(program, &site, &key, &uses, info, null_check_pc) {
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

    if rewrites.is_empty() && direct_replacements.is_empty() {
        log_map_inline_debug("no map_inline rewrites prepared");
        return Ok(PassResult {
            pass_name: "map_inline".into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: skipped,
            diagnostics,
            ..Default::default()
        });
    }

    let mut skip_pcs = HashSet::new();
    let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = direct_replacements;
    let mut map_inline_records = Vec::new();
    let mut applied = direct_sites_applied;
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
            pass_name: "map_inline".into(),
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
        pass_name: "map_inline".into(),
        changed: true,
        sites_applied: applied,
        sites_skipped: skipped,
        diagnostics,
        map_inline_records,
        ..Default::default()
    })
}

fn extract_site_constant_key(
    program: &BpfProgram,
    call_pc: usize,
    info: &crate::analysis::MapInfo,
    use_verifier_guided_keys: bool,
) -> Result<ConstantKey, String> {
    if use_verifier_guided_keys {
        match try_extract_constant_key_verifier_guided(
            &program.insns,
            program.verifier_states.as_ref(),
            call_pc,
            info.key_size,
        ) {
            Ok(key) => {
                log_map_inline_debug(&format!(
                    "site at PC={}: verifier-guided key={} width={} stack_off={} store_pc={} source_imm_pc={:?} r2_mov_pc={:?} r2_add_pc={:?}",
                    call_pc,
                    format_constant_key(&key),
                    key.width,
                    key.stack_off,
                    key.store_pc,
                    key.source_imm_pc,
                    key.r2_mov_pc,
                    key.r2_add_pc
                ));
                return Ok(key);
            }
            Err(verifier_err) => {
                match try_extract_constant_key_sized(&program.insns, call_pc, info.key_size) {
                    Ok(key) => {
                        log_map_inline_debug(&format!(
                            "site at PC={}: fallback backward-scan key after verifier-guided miss: {}",
                            call_pc, verifier_err
                        ));
                        log_map_inline_debug(&format!(
                            "site at PC={}: extracted key={} width={} stack_off={} store_pc={} source_imm_pc={:?} r2_mov_pc={:?} r2_add_pc={:?}",
                            call_pc,
                            format_constant_key(&key),
                            key.width,
                            key.stack_off,
                            key.store_pc,
                            key.source_imm_pc,
                            key.r2_mov_pc,
                            key.r2_add_pc
                        ));
                        return Ok(key);
                    }
                    Err(scan_err) => match try_extract_constant_key_from_map_value(program, call_pc, info)
                    {
                        Ok(key) => {
                            log_map_inline_debug(&format!(
                                "site at PC={}: pseudo-map-value key after verifier-guided miss={} and backward-scan miss={}",
                                call_pc, verifier_err, scan_err
                            ));
                            log_map_inline_debug(&format!(
                                "site at PC={}: extracted pseudo-map-value key={} width={} store_pc={} source_imm_pc={:?}",
                                call_pc,
                                format_constant_key(&key),
                                key.width,
                                key.store_pc,
                                key.source_imm_pc
                            ));
                            return Ok(key);
                        }
                        Err(map_value_err) => {
                            log_map_inline_debug(&format!(
                                "site pc={} skip: verifier-guided={} fallback={} pseudo-map-value={}",
                                call_pc, verifier_err, scan_err, map_value_err
                            ));
                            return Err(format!(
                                "verifier-guided key extraction failed: {}; fallback scan failed: {}; pseudo-map-value fallback failed: {}",
                                verifier_err, scan_err, map_value_err
                            ));
                        }
                    },
                }
            }
        }
    }

    match try_extract_constant_key_sized(&program.insns, call_pc, info.key_size) {
        Ok(key) => {
            log_map_inline_debug(&format!(
                "site at PC={}: extracted key={} width={} stack_off={} store_pc={} source_imm_pc={:?} r2_mov_pc={:?} r2_add_pc={:?}",
                call_pc,
                format_constant_key(&key),
                key.width,
                key.stack_off,
                key.store_pc,
                key.source_imm_pc,
                key.r2_mov_pc,
                key.r2_add_pc
            ));
            Ok(key)
        }
        Err(scan_err) => match try_extract_constant_key_from_map_value(program, call_pc, info) {
            Ok(key) => {
                log_map_inline_debug(&format!(
                    "site at PC={}: pseudo-map-value key after backward-scan miss={}",
                    call_pc, scan_err
                ));
                log_map_inline_debug(&format!(
                    "site at PC={}: extracted pseudo-map-value key={} width={} store_pc={} source_imm_pc={:?}",
                    call_pc,
                    format_constant_key(&key),
                    key.width,
                    key.store_pc,
                    key.source_imm_pc
                ));
                Ok(key)
            }
            Err(map_value_err) => {
                log_map_inline_debug(&format!(
                    "site pc={} skip: fallback={} pseudo-map-value={}",
                    call_pc, scan_err, map_value_err
                ));
                Err(format!(
                    "fallback scan failed: {}; pseudo-map-value fallback failed: {}",
                    scan_err, map_value_err
                ))
            }
        },
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
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
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
    let inline_value =
        prepare_inline_value(info, &value).map_err(|reason| site_level_inline_veto(reason))?;

    let removable_null_check_pc =
        null_check_pc.filter(|&pc| null_check_is_fallthrough_non_null(&program.insns[pc]));
    let replacement_pcs = uses
        .fixed_loads
        .iter()
        .map(|load| load.pc)
        .collect::<HashSet<_>>();
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
    let null_check_blocks_lookup_removal = if let Some(null_check_pc) = removable_null_check_pc {
        !null_check_removal_window_is_trivial(
            program,
            null_check_pc,
            &lookup_pattern_pcs,
            &replacement_pcs,
        )
    } else {
        null_check_pc.is_some()
    };
    let can_remove_lookup_pattern = remove_lookup_pattern
        && uses.other_uses.is_empty()
        && !null_check_blocks_lookup_removal
        && lookup_pattern_removal_is_safe(program, uses, &lookup_pattern_pcs);
    let skipped_pcs = if can_remove_lookup_pattern {
        lookup_pattern_pcs
    } else {
        HashSet::new()
    };

    let mut replacements = BTreeMap::new();
    for load in &uses.fixed_loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
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

fn build_direct_map_value_load_rewrites(
    program: &BpfProgram,
) -> (BTreeMap<usize, Vec<BpfInsn>>, usize, Vec<String>) {
    let mut replacements = BTreeMap::new();
    let mut sites_applied = 0usize;
    let mut diagnostics = Vec::new();
    let mut map_cache: HashMap<i32, Option<FrozenMapValue>> = HashMap::new();
    let mut pc = 0usize;

    while pc < program.insns.len() {
        let insn = &program.insns[pc];
        if !insn.is_ldx_mem() {
            pc += insn_width(insn);
            continue;
        }

        let bounds = subprog_bounds(&program.insns, pc);
        let origin = match resolve_key_pointer_origin(&program.insns, pc, insn.src_reg(), bounds) {
            Ok(KeyPointerOrigin::MapValue {
                old_fd, value_off, ..
            }) => Some((old_fd, value_off)),
            _ => None,
        };
        let Some((old_fd, value_off)) = origin else {
            pc += insn_width(insn);
            continue;
        };

        let Some(total_off) = value_off.checked_add(insn.off as i32) else {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value offset overflow (base {} + load off {})",
                    pc, value_off, insn.off
                ),
            );
            pc += insn_width(insn);
            continue;
        };
        if total_off < 0 {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value load offset {} is negative",
                    pc, total_off
                ),
            );
            pc += insn_width(insn);
            continue;
        }

        let Some(map_value) =
            resolve_frozen_map_value(program, old_fd, &mut map_cache, &mut diagnostics)
        else {
            pc += insn_width(insn);
            continue;
        };

        let offset = total_off as usize;
        let Some(scalar) = read_scalar_from_value_at(&map_value.value, offset, bpf_size(insn.code))
        else {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                    pc,
                    map_value.map_id,
                    offset,
                    size_in_bytes(bpf_size(insn.code)).unwrap_or_default()
                ),
            );
            pc += insn_width(insn);
            continue;
        };

        replacements.insert(
            pc,
            emit_constant_load(insn.dst_reg(), scalar, bpf_size(insn.code)),
        );
        sites_applied += 1;
        record_diagnostic(
            &mut diagnostics,
            format!(
                "site at PC={}: constantized pseudo-map-value load from map_id={} off={} value=0x{:x}",
                pc, map_value.map_id, offset, scalar
            ),
        );

        pc += insn_width(insn);
    }

    (replacements, sites_applied, diagnostics)
}

fn resolve_frozen_map_value(
    program: &BpfProgram,
    old_fd: i32,
    cache: &mut HashMap<i32, Option<FrozenMapValue>>,
    diagnostics: &mut Vec<String>,
) -> Option<FrozenMapValue> {
    if let Some(cached) = cache.get(&old_fd) {
        return cached.clone();
    }

    let resolved = (|| -> anyhow::Result<Option<FrozenMapValue>> {
        let Some(&map_id) = program.map_fd_bindings.get(&old_fd) else {
            return Ok(None);
        };
        let (info, frozen) = bpf::bpf_map_get_info_by_id(map_id)?;
        if !frozen {
            return Ok(None);
        }

        let key = vec![0u8; info.key_size as usize];
        let value_size = bpf::bpf_map_lookup_value_size(&info);
        let value = bpf::bpf_map_lookup_elem_by_id(map_id, &key, value_size)?;
        Ok(Some(FrozenMapValue { map_id, value }))
    })();

    let cached = match resolved {
        Ok(value) => value,
        Err(err) => {
            record_diagnostic(
                diagnostics,
                format!(
                    "pseudo-map-value old_fd {} could not be resolved to a frozen value: {err:#}",
                    old_fd
                ),
            );
            None
        }
    };
    cache.insert(old_fd, cached.clone());
    cached
}

fn encode_key_bytes(bytes: &[u8], key_size: usize) -> Vec<u8> {
    bytes[..key_size].to_vec()
}

fn prepare_inline_value(
    info: &crate::analysis::MapInfo,
    raw_value: &[u8],
) -> Result<Vec<u8>, String> {
    if info.map_type != BPF_MAP_TYPE_PERCPU_ARRAY {
        return Ok(raw_value.to_vec());
    }

    collapse_uniform_percpu_array_value(info.value_size as usize, raw_value)
}

fn collapse_uniform_percpu_array_value(
    value_size: usize,
    raw_value: &[u8],
) -> Result<Vec<u8>, String> {
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

    if insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && insn.dst_reg() == reg
        && budget > 1
    {
        if let Some(width) = size_in_bytes(bpf_size(insn.code)) {
            if let Ok(base_stack_off) =
                resolve_stack_pointer_to_stack_inner(insns, pc, insn.src_reg(), bounds, budget - 1)
            {
                let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
                let stack_off = i16::try_from(stack_off).map_err(|_| {
                    format!(
                        "resolved stack load offset {} from r{} does not fit in i16",
                        stack_off, reg
                    )
                })?;
                let (_, _, bytes) = find_constant_stack_bytes_with_limit(
                    insns,
                    pc,
                    bounds,
                    stack_off,
                    width,
                    Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
                )?;
                return Ok(ConstantRegValue {
                    value: constant_key_value(&bytes),
                    source_pc: None,
                });
            }
        }
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

fn resolve_key_pointer_origin(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<KeyPointerOrigin, String> {
    resolve_key_pointer_origin_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_key_pointer_origin_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
    budget: usize,
) -> Result<KeyPointerOrigin, String> {
    if budget == 0 {
        return Err(format!(
            "key pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    if reg == 10 {
        return Ok(KeyPointerOrigin::Stack(0));
    }

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = &insns[pc];

    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if insn.src_reg() == BPF_PSEUDO_MAP_VALUE {
            let value_off = insns
                .get(pc + 1)
                .ok_or_else(|| format!("pseudo-map-value load at pc {} is truncated", pc))?
                .imm;
            return Ok(KeyPointerOrigin::MapValue {
                old_fd: insn.imm,
                value_off,
                ldimm_pc: pc,
            });
        }
        return Err(format!(
            "register r{} definition at pc {} is not a pseudo-map-value pointer",
            reg, pc
        ));
    }

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_key_pointer_origin_inner(insns, pc, insn.src_reg(), bounds, budget - 1);
        }

        if op == BPF_ADD || op == BPF_SUB {
            let base = resolve_key_pointer_origin_inner(insns, pc, reg, bounds, budget - 1)?;
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?
                    .value as i64
            };
            let signed_delta = if op == BPF_SUB { -delta } else { delta };
            return match base {
                KeyPointerOrigin::Stack(stack_off) => {
                    let stack_off = stack_off as i64 + signed_delta;
                    let stack_off = i16::try_from(stack_off).map_err(|_| {
                        format!(
                            "resolved stack offset {} from r{} does not fit in i16",
                            stack_off, reg
                        )
                    })?;
                    Ok(KeyPointerOrigin::Stack(stack_off))
                }
                KeyPointerOrigin::MapValue {
                    old_fd,
                    value_off,
                    ldimm_pc,
                } => {
                    let value_off = value_off as i64 + signed_delta;
                    let value_off = i32::try_from(value_off).map_err(|_| {
                        format!(
                            "resolved pseudo-map-value offset {} from r{} does not fit in i32",
                            value_off, reg
                        )
                    })?;
                    Ok(KeyPointerOrigin::MapValue {
                        old_fd,
                        value_off,
                        ldimm_pc,
                    })
                }
            };
        }
    }

    Err(format!(
        "register r{} definition at pc {} does not resolve to constant stack or pseudo-map-value memory",
        reg, pc
    ))
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
    static ENABLED: OnceLock<bool> = OnceLock::new();
    if *ENABLED.get_or_init(|| std::env::var_os("BPFREJIT_MAP_INLINE_DEBUG").is_some()) {
        eprintln!("map_inline: {}", message);
    }
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
    allow_readonly_helper_calls: bool,
) -> R0UseClassification {
    let mut classification = R0UseClassification::default();
    let mut alias_regs = HashSet::from([0u8]);
    let mut alias_stack_slots = HashSet::new();
    let bounds = subprog_bounds(insns, start_pc);
    let mut pc = start_pc + 1;

    while pc < insns.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
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

        if !classification.fixed_loads.is_empty()
            && alias_stack_slots.is_empty()
            && ends_current_use_region(insn, &alias_regs)
        {
            break;
        }

        if let Some((stack_off, width)) = resolve_stack_store_slot(insns, pc, insn, bounds) {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains(&insn.src_reg())
            {
                classification.alias_copy_pcs.push(pc);
                alias_stack_slots.insert(stack_off);
                pc += insn_width(insn);
                continue;
            }
        }

        if let Some(stack_off) = resolve_stack_load_slot(insns, pc, insn, bounds) {
            if alias_stack_slots.contains(&stack_off) {
                classification.alias_copy_pcs.push(pc);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg());
                pc += insn_width(insn);
                continue;
            }
        }

        if insn.is_call() {
            if allow_unrelated_helper_calls
                || (allow_readonly_helper_calls && helper_call_is_readonly_for_lookup_value(insn))
            {
                let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
                if !surviving_aliases.is_empty() || !alias_stack_slots.is_empty() {
                    alias_regs = surviving_aliases;
                    pc += insn_width(insn);
                    continue;
                }
            }
            if insn_uses_any_alias(insn, &alias_regs)
                || (alias_stack_slots.is_empty() && !alias_regs.is_empty())
            {
                classification.other_uses.push(pc);
                break;
            }
            alias_regs.clear();
            if !alias_stack_slots.is_empty() {
                pc += insn_width(insn);
                continue;
            }
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

fn resolve_stack_store_slot(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    bounds: (usize, usize),
) -> Option<(i16, u8)> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    let width = size_in_bytes(bpf_size(insn.code))?;
    if !(insn.class() == BPF_ST || insn.class() == BPF_STX) {
        return None;
    }
    let base_stack_off =
        resolve_stack_pointer_to_stack_inner(insns, pc, insn.dst_reg(), bounds, REG_RESOLUTION_LIMIT)
            .ok()?;
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let stack_off = i16::try_from(stack_off).ok()?;
    Some((stack_off, width))
}

fn resolve_stack_load_slot(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    bounds: (usize, usize),
) -> Option<i16> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return None;
    }
    let base_stack_off =
        resolve_stack_pointer_to_stack_inner(insns, pc, insn.src_reg(), bounds, REG_RESOLUTION_LIMIT)
            .ok()?;
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    i16::try_from(stack_off).ok()
}

fn kill_overlapping_alias_stack_slots(alias_stack_slots: &mut HashSet<i16>, stack_off: i16, width: u8) {
    let store_start = i32::from(stack_off);
    let store_end = store_start + i32::from(width);
    alias_stack_slots.retain(|slot| {
        let alias_start = i32::from(*slot);
        let alias_end = alias_start + 8;
        store_end <= alias_start || store_start >= alias_end
    });
}

fn surviving_alias_regs_after_helper_call(alias_regs: &HashSet<u8>) -> HashSet<u8> {
    alias_regs
        .iter()
        .copied()
        .filter(|reg| (6..=9).contains(reg))
        .collect()
}

fn helper_call_is_readonly_for_lookup_value(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_KTIME_GET_NS
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

fn null_check_removal_window_is_trivial(
    program: &BpfProgram,
    null_check_pc: usize,
    skipped_pcs: &HashSet<usize>,
    replacement_pcs: &HashSet<usize>,
) -> bool {
    let Some(null_target_pc) = jump_target_pc(
        null_check_pc,
        &program.insns[null_check_pc],
        program.insns.len(),
    ) else {
        return false;
    };
    let Some(mut pc) =
        advance_to_non_null_path(null_check_pc, &program.insns[null_check_pc], program.insns.len())
    else {
        return false;
    };

    while pc < null_target_pc {
        if skipped_pcs.contains(&pc) || replacement_pcs.contains(&pc) {
            pc += insn_width(&program.insns[pc]);
            continue;
        }

        let insn = &program.insns[pc];
        if !is_trivially_safe_null_check_guarded_insn(insn) {
            return false;
        }
        pc += insn_width(insn);
    }

    true
}

fn is_trivially_safe_null_check_guarded_insn(insn: &BpfInsn) -> bool {
    if insn.is_exit() || insn.is_ja() {
        return true;
    }

    if insn.is_ldimm64() {
        return insn.src_reg() == 0;
    }

    match insn.class() {
        BPF_ALU64 | BPF_ALU => bpf_op(insn.code) == BPF_MOV && bpf_src(insn.code) == BPF_K,
        _ => false,
    }
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

    use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, MapInfoAnalysis};
    use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
    use crate::pass::{MapInlineRecord, PassContext, PassManager};
    use crate::passes::{ConstPropPass, DcePass};
    use crate::verifier_log::parse_verifier_log;

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

    fn ld_imm64_parts(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_DW | BPF_IMM,
                regs: BpfInsn::make_regs(dst, src),
                off: 0,
                imm: imm_lo,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: imm_hi,
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
        install_map_with_key_size(map_id, map_type, 4, max_entries, frozen, values);
    }

    fn install_map_with_key_size(
        map_id: u32,
        map_type: u32,
        key_size: u32,
        max_entries: u32,
        frozen: bool,
        values: HashMap<Vec<u8>, Vec<u8>>,
    ) {
        let mut info = BpfMapInfo::default();
        info.map_type = map_type;
        info.id = map_id;
        info.key_size = key_size;
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

    fn install_empty_map(
        map_id: u32,
        map_type: u32,
        value_size: u32,
        max_entries: u32,
        frozen: bool,
    ) {
        let mut info = BpfMapInfo::default();
        info.map_type = map_type;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = value_size;
        info.max_entries = max_entries;

        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen,
                values: HashMap::new(),
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

    fn install_array_map_entry(
        map_id: u32,
        max_entries: u32,
        key: u32,
        value: Vec<u8>,
        frozen: bool,
    ) {
        let mut values = HashMap::new();
        values.insert(key.to_le_bytes().to_vec(), value.clone());

        let mut info = BpfMapInfo::default();
        info.map_type = 2;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = value.len() as u32;
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

    fn install_empty_array_map(map_id: u32, value_size: u32, max_entries: u32) {
        let mut info = BpfMapInfo::default();
        info.map_type = 2;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = value_size;
        info.max_entries = max_entries;

        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen: true,
                values: HashMap::new(),
            },
        );
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

    fn run_map_inline_const_prop_dce(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(CFGAnalysis);
        pm.register_analysis(MapInfoAnalysis);
        pm.add_pass(MapInlinePass);
        pm.add_pass(ConstPropPass);
        pm.add_pass(DcePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    fn bcc_top20_objects() -> Vec<std::path::PathBuf> {
        let dir = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("corpus/build/bcc/libbpf-tools");
        let mut objects = std::fs::read_dir(dir)
            .unwrap()
            .filter_map(|entry| entry.ok().map(|entry| entry.path()))
            .filter(|path| {
                path.extension().and_then(|ext| ext.to_str()) == Some("o")
                    && path.file_name()
                        .and_then(|name| name.to_str())
                        .map(|name| name.ends_with(".bpf.o") && !name.ends_with(".tmp.o"))
                        .unwrap_or(false)
            })
            .collect::<Vec<_>>();
        objects.sort();
        objects.truncate(20);
        objects
    }

    #[test]
    #[ignore]
    fn dump_bcc_top20_pattern_stats() {
        use crate::elf_parser::parse_bpf_object;

        let mut pseudo_map_value_loads = 0usize;
        let mut rodata_loads = 0usize;
        let mut data_loads = 0usize;
        let mut bss_loads = 0usize;
        let mut kconfig_loads = 0usize;
        let mut lookup_calls = 0usize;
        let mut array_calls = 0usize;
        let mut hash_calls = 0usize;
        let mut percpu_calls = 0usize;
        let mut other_calls = 0usize;
        let mut constant_key_calls = 0usize;
        let mut dynamic_key_calls = 0usize;
        let mut constant_array_fixed_load_only = 0usize;
        let mut constant_array_other_uses = 0usize;

        for object_path in bcc_top20_objects() {
            let object = parse_bpf_object(&object_path).unwrap();
            let mut object_pseudo_map_value_loads = 0usize;
            let mut object_lookup_calls = 0usize;
            let mut object_constant_key_calls = 0usize;
            for program in &object.programs {
                for relocation in &program.map_relocations {
                    if relocation.pseudo_src != BPF_PSEUDO_MAP_VALUE {
                        continue;
                    }
                    if !relocation.map_name.starts_with('.') {
                        continue;
                    }
                    pseudo_map_value_loads += 1;
                    object_pseudo_map_value_loads += 1;
                    match relocation.map_name.as_str() {
                        name if name.starts_with(".rodata") => rodata_loads += 1,
                        name if name.starts_with(".data") => data_loads += 1,
                        name if name.starts_with(".bss") => bss_loads += 1,
                        name if name.starts_with(".kconfig") => kconfig_loads += 1,
                        _ => {}
                    }
                }

                for site in find_map_lookup_sites(&program.insns) {
                    lookup_calls += 1;
                    object_lookup_calls += 1;
                    let relocation = program
                        .map_relocations
                        .iter()
                        .find(|relocation| relocation.pc == site.map_load_pc)
                        .unwrap();
                    let map = &object.maps[relocation.map_index];
                    match map.map_type.unwrap_or_default() {
                        2 => array_calls += 1,
                        1 | 9 => hash_calls += 1,
                        5 | 6 | 10 => percpu_calls += 1,
                        _ => other_calls += 1,
                    }

                    let is_constant_key = extract_constant_key(&program.insns, site.call_pc)
                        .is_some()
                        || object.maps[relocation.map_index].name.starts_with('.');
                    if is_constant_key {
                        constant_key_calls += 1;
                        object_constant_key_calls += 1;
                        if matches!(map.map_type, Some(2 | 6)) {
                            let uses = classify_r0_uses_with_options(
                                &program.insns,
                                site.call_pc,
                                false,
                                false,
                            );
                            if !uses.fixed_loads.is_empty() && uses.all_fixed_loads() {
                                constant_array_fixed_load_only += 1;
                            } else {
                                constant_array_other_uses += 1;
                            }
                        }
                    } else {
                        dynamic_key_calls += 1;
                    }
                }
            }

            println!(
                "object={} pseudo_map_value_loads={} lookup_calls={} constant_key_calls={}",
                object_path.file_name().and_then(|name| name.to_str()).unwrap_or("unknown"),
                object_pseudo_map_value_loads,
                object_lookup_calls,
                object_constant_key_calls
            );
        }

        println!("bcc_top20_objects={}", bcc_top20_objects().len());
        println!("pseudo_map_value_loads={pseudo_map_value_loads}");
        println!("rodata_loads={rodata_loads}");
        println!("data_loads={data_loads}");
        println!("bss_loads={bss_loads}");
        println!("kconfig_loads={kconfig_loads}");
        println!("lookup_calls={lookup_calls}");
        println!("array_calls={array_calls}");
        println!("hash_calls={hash_calls}");
        println!("percpu_calls={percpu_calls}");
        println!("other_calls={other_calls}");
        println!("constant_key_calls={constant_key_calls}");
        println!("dynamic_key_calls={dynamic_key_calls}");
        println!("constant_array_fixed_load_only={constant_array_fixed_load_only}");
        println!("constant_array_other_uses={constant_array_other_uses}");
    }

    fn has_non_constant_key_skip(result: &PipelineResult) -> bool {
        result.pass_results[0].sites_skipped.iter().any(|skip| {
            skip.reason
                .contains("lookup key is not a constant stack or pseudo-map-value materialization")
        })
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
    fn map_inline_constantizes_frozen_pseudo_map_value_loads() {
        let mut values = HashMap::new();
        values.insert(0u32.to_le_bytes().to_vec(), vec![0, 0, 0, 0, 42, 0, 0, 0]);
        install_map(901, 2, 1, true, values);

        let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 77, 4);
        let mut program = BpfProgram::new(vec![
            map_value[0],
            map_value[1],
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![901]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(program.insns[2], BpfInsn::mov64_imm(2, 42));
    }

    #[test]
    fn map_inline_skips_mutable_pseudo_map_value_loads() {
        let mut values = HashMap::new();
        values.insert(0u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
        install_map(902, 2, 1, false, values);

        let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 78, 0);
        let original = vec![
            map_value[0],
            map_value[1],
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![902]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn map_inline_pseudo_map_value_feeds_const_prop_and_dce() {
        let mut values = HashMap::new();
        values.insert(0u32.to_le_bytes().to_vec(), vec![1, 0, 0, 0]);
        install_map(903, 2, 1, true, values);

        let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 79, 0);
        let mut program = BpfProgram::new(vec![
            map_value[0],
            map_value[1],
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            jeq_imm(2, 1, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![903]);

        let result = run_map_inline_const_prop_dce(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].pass_name, "map_inline");
        assert_eq!(result.pass_results[1].pass_name, "const_prop");
        assert_eq!(result.pass_results[2].pass_name, "dce");
        assert!(result.pass_results[0].changed);
        assert!(result.pass_results[1].changed);
        assert!(
            !program.insns.iter().any(|insn| insn.is_cond_jmp()),
            "expected const_prop+dce to remove the conditional branch after pseudo-map-value constantization"
        );
        assert!(
            !program.insns.iter().any(|insn| *insn == BpfInsn::mov64_imm(0, 0)),
            "expected dce to remove the dead false branch after pseudo-map-value constantization"
        );
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
    fn verifier_guided_key_extracts_wide_zero_store_subrange() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            BpfInsn::mov64_imm(3, 0),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];
        let plain = try_extract_constant_key(&insns, 6).unwrap();
        assert_eq!(plain.stack_off, -4);
        assert_eq!(plain.width, 4);
        assert_eq!(plain.value, 0);
        assert_eq!(plain.store_pc, 1);

        let states = parse_verifier_log(
            r#"
0: R1=ctx() R10=fp0
0: (b7) r3 = 0                        ; R3=0
1: (7b) *(u64 *)(r10 -8) = r3         ; R3=0 R10=fp0 fp-8=0
2: (bf) r2 = r10                      ; R2=fp0 R10=fp0
3: (07) r2 += -4                      ; R2=fp-4
4: (18) r1 = 0xffff8f09c3e45000       ; R1=map_ptr(map=test_array,ks=4,vs=4)
6: (85) call bpf_map_lookup_elem#1    ; R0=map_value_or_null(id=1,map=test_array,ks=4,vs=4)
"#,
        );

        let key = try_extract_constant_key_verifier_guided(&insns, &states, 6, 4).unwrap();
        assert_eq!(key.stack_off, -4);
        assert_eq!(key.width, 4);
        assert_eq!(key.value, 0);
        assert_eq!(key.store_pc, 1);
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

        let key = try_extract_constant_key_sized(&insns, 7, 8).unwrap();
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

        let relaxed_uses = classify_r0_uses_with_options(&insns, 0, true, true);
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
    fn classify_r0_uses_tracks_stack_spill_and_reload_across_helper() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::stx_mem(BPF_DW, 10, 0, -16),
            call_helper(2),
            BpfInsn::ldx_mem(BPF_DW, 6, 10, -16),
            BpfInsn::ldx_mem(BPF_W, 3, 6, 4),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(uses.other_uses, Vec::<usize>::new());
        assert_eq!(uses.alias_copy_pcs, vec![1, 3]);
        assert_eq!(
            uses.fixed_loads,
            vec![FixedLoadUse {
                pc: 4,
                dst_reg: 3,
                size: BPF_W,
                offset: 4,
            }]
        );
        assert!(uses.all_fixed_loads());
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
    fn map_inline_pass_keeps_null_check_when_non_null_window_has_side_effects() {
        install_array_map(1602, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 5),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::stx_mem(BPF_W, 10, 6, -8),
            jeq_imm(6, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![1602]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert!(program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
        assert!(program.insns.contains(&jeq_imm(0, 0, 5)));
        assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 7)));
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
        assert!(has_non_constant_key_skip(&result));
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
        assert!(has_non_constant_key_skip(&result));
    }

    #[test]
    fn map_inline_pass_rewrites_array_lookup_with_pseudo_map_value_zero_key() {
        install_array_map_entry(9120, 8, 0, vec![7, 0, 0, 0], true);
        install_array_map_entry(9121, 1, 0, vec![0, 0, 0, 0], true);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let key = ld_imm64_parts(2, BPF_PSEUDO_MAP_VALUE, 43, 0);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            key[0],
            key[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9120, 9121]);

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
    fn map_inline_pass_rewrites_hash_lookup_with_pseudo_map_value_20_byte_key() {
        let key_bytes = (0u8..20).collect::<Vec<_>>();
        install_array_map_entry(9401, 1, 0, key_bytes.clone(), true);

        let mut values = HashMap::new();
        values.insert(key_bytes.clone(), 42u32.to_le_bytes().to_vec());
        install_map_with_key_size(9402, 1, 20, 16, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let key = ld_imm64_parts(2, BPF_PSEUDO_MAP_VALUE, 43, 0);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            key[0],
            key[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9402, 9401]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 42)));
        assert_eq!(result.pass_results[0].map_inline_records.len(), 1);
        assert_eq!(result.pass_results[0].map_inline_records[0].key, key_bytes);
        assert_eq!(
            result.pass_results[0].map_inline_records[0].expected_value,
            42u32.to_le_bytes().to_vec()
        );
    }

    #[test]
    fn map_inline_pass_rewrites_lookup_with_split_halfword_key_materialization() {
        install_array_map_entry(9301, 16, 7, 42u32.to_le_bytes().to_vec(), true);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_H, 10, -4, 7),
            st_mem(BPF_H, 10, -2, 0),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9301]);

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
                st_mem(BPF_H, 10, -4, 7),
                st_mem(BPF_H, 10, -2, 0),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::mov64_imm(6, 42),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_uses_verifier_guided_wide_zero_store_key() {
        let mut values = HashMap::new();
        values.insert(0u32.to_le_bytes().to_vec(), 42u32.to_le_bytes().to_vec());
        install_map(7001, 2, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 123);
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(3, 0),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![7001]);
        program.set_verifier_log(
            r#"
0: R1=ctx() R10=fp0
0: (b7) r3 = 0                        ; R3=0
1: (7b) *(u64 *)(r10 -8) = r3         ; R3=0 R10=fp0 fp-8=0
2: (bf) r2 = r10                      ; R2=fp0 R10=fp0
3: (07) r2 += -4                      ; R2=fp-4
4: (18) r1 = 0xffff8f09c3e45000       ; R1=map_ptr(map=test_array,ks=4,vs=4)
6: (85) call bpf_map_lookup_elem#1    ; R0=map_value_or_null(id=1,map=test_array,ks=4,vs=4)
7: (15) if r0 == 0x0 goto pc+2        ; R0=map_value(map=test_array,ks=4,vs=4)
8: (61) r6 = *(u32 *)(r0 +0)          ; R0=map_value(map=test_array,ks=4,vs=4) R6=42
"#,
        );

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 42)));
        assert!(program
            .insns
            .iter()
            .all(|insn| !(insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)));
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
    fn map_inline_pass_rewrites_hash_lookup_with_20_byte_constant_key() {
        let mut values = HashMap::new();
        let mut key_bytes = vec![0u8; 20];
        key_bytes[16..20].copy_from_slice(&1u32.to_le_bytes());
        values.insert(key_bytes.clone(), 7u32.to_le_bytes().to_vec());
        install_map_with_key_size(9310, 1, 20, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            BpfInsn::mov64_imm(3, 0),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -20),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -12),
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -20),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9310]);

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
                BpfInsn::mov64_imm(3, 0),
                BpfInsn::stx_mem(BPF_DW, 10, 3, -20),
                BpfInsn::stx_mem(BPF_DW, 10, 3, -12),
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -20),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jeq_imm(0, 0, 3),
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                ja(1),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
        assert_eq!(result.pass_results[0].map_inline_records[0].key, key_bytes);
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
    fn map_inline_pass_rewrites_load_before_pointer_escape_to_helper() {
        install_array_map(106, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
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
        ]);
        program.set_map_ids(vec![106]);

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
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_reg(1, 0),
                call_helper(2),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_rewrites_load_before_lookup_result_write_back() {
        install_array_map(116, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
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
        ]);
        program.set_map_ids(vec![116]);

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
                BpfInsn::mov64_imm(6, 7),
                st_mem(BPF_W, 0, 0, 99),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
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
    fn map_inline_pass_reaches_fixpoint_across_cascading_lookup_keys() {
        install_array_map(9201, 2u32.to_le_bytes().to_vec());
        install_array_map_entry(9202, 8, 2, 9u32.to_le_bytes().to_vec(), true);

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
            BpfInsn::stx_mem(BPF_W, 10, 6, -8),
            map1[0],
            map1[1],
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -8),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9201, 9202]);

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
                BpfInsn::mov64_imm(7, 9),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_reaches_fixpoint_through_stack_reloaded_key() {
        install_array_map(9203, 2u32.to_le_bytes().to_vec());
        install_array_map_entry(9204, 8, 2, 11u32.to_le_bytes().to_vec(), true);

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
            BpfInsn::stx_mem(BPF_DW, 10, 6, -16),
            BpfInsn::ldx_mem(BPF_DW, 7, 10, -16),
            BpfInsn::stx_mem(BPF_W, 10, 7, -8),
            map1[0],
            map1[1],
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -8),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 8, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![9203, 9204]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 2);
        assert!(
            !program
                .insns
                .iter()
                .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM),
            "expected both lookup helpers to be eliminated, got: {:?}",
            program.insns
        );
        assert!(
            program
                .insns
                .iter()
                .any(|insn| insn.code == (BPF_ALU64 | BPF_MOV | BPF_K)
                    && insn.dst_reg() == 8
                    && insn.imm == 11),
            "expected final lookup load to become constant, got: {:?}",
            program.insns
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
    fn map_inline_pass_inlines_mutable_array_across_readonly_helper_call() {
        install_mutable_array_map(411, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(9, 0),
            call_helper(HELPER_KTIME_GET_NS),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![411]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                call_helper(HELPER_KTIME_GET_NS),
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_skips_hash_lookup_across_readonly_helper_call() {
        install_hash_map(413, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(9, 0),
            jeq_imm(9, 0, 2),
            call_helper(HELPER_KTIME_GET_NS),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![413]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip
                .reason
                .contains("fixed-offset scalar loads")));
    }

    #[test]
    fn map_inline_pass_skips_mutable_array_across_side_effect_helper_call() {
        install_mutable_array_map(412, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(9, 0),
            call_helper(2),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![412]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip
                .reason
                .contains("fixed-offset scalar loads")));
    }

    #[test]
    fn map_inline_pass_inlines_zero_filled_array_maps() {
        install_empty_map(311, 2, 8, 8, true);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 2),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::ldx_mem(BPF_DW, 7, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![311]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 0),
                BpfInsn::mov64_imm(7, 0),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_inlines_zero_filled_percpu_array_maps() {
        install_empty_map(312, BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, true);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 3),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![312]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 0),
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
    fn map_inline_pass_inlines_zero_filled_array_defaults() {
        install_empty_array_map(915, 4, 8);

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
        program.set_map_ids(vec![915]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert!(!program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
        assert_eq!(
            result.pass_results[0].map_inline_records[0].expected_value,
            vec![0u8; 4]
        );
        assert!(program
            .insns
            .iter()
            .any(|insn| insn == &BpfInsn::mov64_imm(6, 0)));
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
        assert!(!program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
        assert!(program
            .insns
            .iter()
            .any(|insn| insn == &BpfInsn::mov64_imm(6, 7)));
        assert!(
            result.pass_results[0].map_inline_records[0].expected_value == blob,
            "tracker should store the full per-cpu blob: {:?}",
            result.pass_results[0].map_inline_records
        );
    }

    #[test]
    fn map_inline_pass_inlines_zero_filled_percpu_array_defaults() {
        install_percpu_array_map(916, 4, 8, true, HashMap::new());

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
        program.set_map_ids(vec![916]);

        let result = run_map_inline_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert!(!program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
        assert!(
            program
                .insns
                .iter()
                .any(|insn| insn == &BpfInsn::mov64_imm(6, 0)),
            "program should inline a zero constant: {:?}",
            program.insns
        );
        assert!(
            result.pass_results[0].map_inline_records[0]
                .expected_value
                .iter()
                .all(|byte| *byte == 0),
            "tracker should preserve the full zero-filled per-cpu blob: {:?}",
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
            result.pass_results[0].sites_skipped.iter().any(|skip| skip
                .reason
                .contains("PERCPU_ARRAY value differs across CPUs")),
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
