// SPDX-License-Identifier: MIT
// Scan helpers for dynamic map inlining.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fmt::Write as _;
use std::sync::OnceLock;

use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
use crate::insn::*;
use crate::pass::*;

const BPF_MAP_TYPE_HASH: u32 = kernel_sys::BPF_MAP_TYPE_HASH;
const BPF_MAP_TYPE_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_HASH;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY;
const BPF_MAP_TYPE_LRU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_HASH;
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
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
    pub materialization_pcs: Vec<usize>,
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
    #[cfg(test)]
    pub fn all_fixed_loads(&self) -> bool {
        self.other_uses.is_empty()
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantRegValue {
    value: u64,
    source_pc: Option<usize>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantStackBytes {
    bytes: Vec<u8>,
    latest_store_pc: usize,
    latest_source_imm_pc: Option<usize>,
    materialization_pcs: Vec<usize>,
}

#[derive(Clone, Debug)]
struct FrozenMapValue {
    map_id: u32,
    value: Vec<u8>,
}

type DirectMapValueLoadRewrites = (BTreeMap<usize, Vec<BpfInsn>>, usize, Vec<String>);

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
#[cfg(test)]
pub fn extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Option<ConstantKey> {
    let Ok(key) = try_extract_constant_key(insns, call_pc) else {
        return None;
    };
    Some(key)
}

#[cfg(test)]
pub fn try_extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Result<ConstantKey, String> {
    let bounds = subprog_bounds(insns, call_pc);
    let stack_off = resolve_stack_pointer_to_stack(insns, call_pc, 2, bounds)?;
    let mut last_err = None;
    let mut extracted = None;
    for width in [8u8, 4, 2, 1] {
        match find_constant_stack_bytes(insns, call_pc, bounds, stack_off, width) {
            Ok(stack_bytes) => {
                extracted = Some((width, stack_bytes));
                break;
            }
            Err(err) => last_err = Some(err),
        }
    }
    let (width, stack_bytes) = extracted.ok_or_else(|| {
        last_err.unwrap_or_else(|| format!("no stack store found for fp{}", stack_off))
    })?;
    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width,
        value: constant_key_value(&stack_bytes.bytes),
        bytes: stack_bytes.bytes,
        store_pc: stack_bytes.latest_store_pc,
        source_imm_pc: stack_bytes.latest_source_imm_pc,
        materialization_pcs: stack_bytes.materialization_pcs,
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
    let stack_bytes = find_constant_stack_bytes(insns, call_pc, bounds, stack_off, key_width)?;

    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width: key_width,
        value: constant_key_value(&stack_bytes.bytes),
        bytes: stack_bytes.bytes,
        store_pc: stack_bytes.latest_store_pc,
        source_imm_pc: stack_bytes.latest_source_imm_pc,
        materialization_pcs: stack_bytes.materialization_pcs,
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
    let source_info = program
        .map_info_provider
        .map_info(program, source_map_id)?
        .ok_or_else(|| {
            format!(
                "failed to resolve pseudo-map-value source map {}",
                source_map_id
            )
        })?;
    if !source_info.frozen {
        return Err(format!(
            "pseudo-map-value source map {} is mutable",
            source_map_id
        ));
    }

    let source_key = vec![0u8; source_info.key_size as usize];
    let source_value_size = program
        .map_value_provider
        .lookup_value_size(program, &source_info)
        .map_err(|err| {
            format!(
                "failed to determine pseudo-map-value source map {} lookup size: {err}",
                source_map_id
            )
        })?;
    let source_value = program
        .map_value_provider
        .lookup_elem(program, source_map_id, &source_key, source_value_size)
        .map_err(|err| {
            format!(
                "failed to read pseudo-map-value source map {}: {err}",
                source_map_id
            )
        })?;
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
        materialization_pcs: vec![ldimm_pc, ldimm_pc + 1],
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
            && key.materialization_pcs == first.materialization_pcs
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
    let bounds = subprog_bounds(insns, call_pc);

    let (store_pc, source_imm_pc, value) = find_verifier_guided_stack_store(
        insns,
        verifier_states,
        occurrence_idx,
        frame,
        key_off,
        key_width,
        bounds,
    )
    .ok_or_else(|| {
        format!(
            "verifier log did not expose a constant stack store covering fp{} width {} before pc {}",
            key_off, key_width, call_pc
        )
    })?;

    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == key_off);

    Ok(ConstantKey {
        stack_off: key_off,
        width: key_width,
        value,
        bytes: value.to_le_bytes()[..key_width as usize].to_vec(),
        store_pc,
        source_imm_pc,
        materialization_pcs: materialization_pcs_for_store(insns, store_pc, source_imm_pc),
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
) -> Result<ConstantStackBytes, String> {
    find_constant_stack_bytes_with_limit(insns, before_pc, bounds, stack_off, key_width, None)
}

fn find_constant_stack_bytes_with_limit(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: u8,
    mut lookback_limit: Option<usize>,
) -> Result<ConstantStackBytes, String> {
    let key_width_usize = usize::from(key_width);
    let target_start = i32::from(stack_off);
    let target_end = target_start + i32::from(key_width);
    let mut raw = vec![None; key_width_usize];
    let mut latest_store_pc = None;
    let mut latest_source_imm_pc = None;
    let mut materialization_pcs = HashSet::new();
    let mut cursor = before_pc;

    while let Some(pc) = prev_real_pc_bounded(insns, cursor, bounds.0) {
        if let Some(remaining) = lookback_limit.as_mut() {
            if *remaining == 0 {
                break;
            }
            *remaining -= 1;
        }

        let insn = &insns[pc];
        let Some((store_off, width)) = resolve_stack_store_slot(insns, pc, insn, bounds) else {
            cursor = pc;
            continue;
        };
        let store_start = i32::from(store_off);
        let store_end = store_start + i32::from(width);
        let overlap_start = target_start.max(store_start);
        let overlap_end = target_end.min(store_end);
        if overlap_start >= overlap_end {
            cursor = pc;
            continue;
        }

        let bytes = constant_stack_store_bytes(insns, pc, bounds)?;
        let source_imm_pc = constant_stack_store_source_pc(insns, pc, bounds)?;
        let mut covered_new_byte = false;
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
            covered_new_byte = true;
        }

        if covered_new_byte {
            latest_store_pc.get_or_insert(pc);
            if latest_source_imm_pc.is_none() {
                latest_source_imm_pc = source_imm_pc;
            }
            insert_materialization_pc(&mut materialization_pcs, insns, pc);
            if let Some(source_imm_pc) = source_imm_pc {
                insert_materialization_pc(&mut materialization_pcs, insns, source_imm_pc);
            }
        }

        if raw.iter().all(Option::is_some) {
            let bytes = raw
                .into_iter()
                .map(|byte| byte.unwrap_or(0))
                .collect::<Vec<_>>();
            let mut materialization_pcs = materialization_pcs.into_iter().collect::<Vec<_>>();
            materialization_pcs.sort_unstable();
            return Ok(ConstantStackBytes {
                bytes,
                latest_store_pc: latest_store_pc.unwrap_or(pc),
                latest_source_imm_pc,
                materialization_pcs,
            });
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
        return Err(format!(
            "instruction at pc {} is not a stack store",
            store_pc
        ));
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
        return Err(format!(
            "instruction at pc {} is not a stack store",
            store_pc
        ));
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
    bounds: (usize, usize),
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
            verifier_guided_stack_store_value(insns, pc, insn, state, key_off, key_width, bounds)
        else {
            continue;
        };
        return Some((store_pc, source_imm_pc, value));
    }
    None
}

fn verifier_guided_stack_store_value(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    state: &VerifierInsn,
    key_off: i16,
    key_width: u8,
    bounds: (usize, usize),
) -> Option<(usize, Option<usize>, u64)> {
    let (store_off, store_width) = resolve_stack_store_slot(insns, pc, insn, bounds)?;
    let store_start = i32::from(store_off);
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
    let subrange_start = match usize::try_from(key_start - store_start) {
        Ok(start) => start,
        Err(_) => return None,
    };
    let subrange_end = subrange_start + key_width as usize;
    let mut key_bytes = [0u8; 8];
    key_bytes[..key_width as usize].copy_from_slice(&full_bytes[subrange_start..subrange_end]);

    let source_imm_pc = constant_stack_store_source_pc(insns, pc, bounds)
        .map_or_else(|_| None, std::convert::identity);

    Some((state.pc, source_imm_pc, u64::from_le_bytes(key_bytes)))
}

fn verifier_known_scalar_value(reg: &crate::pass::RegState) -> Option<u64> {
    if reg.reg_type != "scalar" {
        return None;
    }

    reg.exact_u64().or_else(|| reg.exact_u32().map(u64::from))
}

/// Classify all uses of the lookup result until its value-pointer aliases die out.
#[cfg(test)]
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
    let map_info = analyses
        .get(&MapInfoAnalysis, program)
        .map_err(anyhow::Error::msg)?;
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    let (direct_replacements, direct_sites_applied, direct_diagnostics) =
        build_direct_map_value_load_rewrites(program)?;
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
                if is_concrete_map_value_snapshot_error(&detail) {
                    return Err(anyhow::anyhow!(
                        "map_inline requires a concrete snapshot value while extracting lookup key at pc {}: {}",
                        site.call_pc,
                        detail
                    ));
                }
                record_skip(
                    &mut skipped,
                    &mut diagnostics,
                    site.call_pc,
                    "lookup key is not a constant stack or pseudo-map-value materialization".into(),
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
        if !info.frozen && !uses.other_uses.is_empty() {
            let reason = "mutable lookup result has non-load uses".to_string();
            record_skip(
                &mut skipped,
                &mut diagnostics,
                site.call_pc,
                reason,
                Some(format!(
                    "site at PC={}: mutable map lookup value escapes beyond fixed loads at pcs {:?}",
                    site.call_pc, uses.other_uses
                )),
            );
            continue;
        }
        let mut rewrite = match build_site_rewrite(program, &site, &key, &uses, info, null_check_pc)
        {
            Ok(Some(rewrite)) => rewrite,
            Ok(None) => {
                let reason = "failed to materialize replacement constants".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            Err(err) => {
                let message = format!("{err:#}");
                if is_concrete_map_value_snapshot_error(&message) {
                    return Err(err.context(format!(
                        "map_inline requires a concrete snapshot value for map {} key {} at lookup pc {}",
                        info.map_id,
                        format_bytes_preview(&key.bytes),
                        site.call_pc
                    )));
                }
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
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: keeping lookup pattern because removal would cross a branch target",
                    site.call_pc
                ),
            );
            rewrite.skipped_pcs.clear();
            rewrite.removed_null_check = false;
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
            sites_skipped: skipped,
            diagnostics,
            ..PassResult::unchanged("map_inline")
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
            sites_skipped: skipped,
            diagnostics,
            map_inline_records,
            ..PassResult::unchanged("map_inline")
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
    super::utils::remap_btf_metadata(program, &final_addr_map)?;
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
                    Err(scan_err) => {
                        match try_extract_constant_key_from_map_value(program, call_pc, info) {
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
                        }
                    }
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
    let remove_lookup_pattern =
        site_can_attempt_lookup_pattern_removal(program, uses, info, null_check_pc);
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let lookup_value_size = program
        .map_value_provider
        .lookup_value_size(program, info)
        .map_err(anyhow::Error::msg)?;
    log_map_inline_debug(&format!(
        "site pc={} reading map_id={} key={:?} lookup_value_size={}",
        site.call_pc, info.map_id, encoded_key, lookup_value_size
    ));
    if program.has_null_map_value_snapshot(info.map_id, &encoded_key) {
        if is_hash_like_map_type(info.map_type) {
            return Err(site_level_inline_veto(format!(
                "hash-like map {} has no live entry for key {}",
                info.map_id,
                format_bytes_preview(&encoded_key)
            )));
        }
        return Err(anyhow::anyhow!(null_map_value_snapshot_message(
            info.map_id,
            &encoded_key
        )));
    }
    let value = match program.map_value_provider.lookup_elem(
        program,
        info.map_id,
        &encoded_key,
        lookup_value_size,
    ) {
        Ok(value) => {
            log_map_inline_debug(&format!(
                "site pc={} INLINE value={:?}",
                site.call_pc, value
            ));
            value
        }
        Err(err) => {
            log_map_inline_debug(&format!(
                "site at PC={}: map lookup(map_id={}, key={}) failed: {}",
                site.call_pc,
                info.map_id,
                format_bytes_preview(&encoded_key),
                err
            ));
            return Err(anyhow::Error::msg(err));
        }
    };
    let inline_value = prepare_inline_value(info, &value).map_err(site_level_inline_veto)?;

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
        lookup_pattern_pcs.extend(key.materialization_pcs.iter().copied());
        if let Some(r2_mov_pc) = key.r2_mov_pc {
            lookup_pattern_pcs.insert(r2_mov_pc);
        }
        if let Some(r2_add_pc) = key.r2_add_pc {
            lookup_pattern_pcs.insert(r2_add_pc);
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
            uses,
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
        && lookup_pattern_removal_is_safe(program, site.call_pc, &lookup_pattern_pcs);
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

fn site_can_attempt_lookup_pattern_removal(
    program: &BpfProgram,
    uses: &R0UseClassification,
    info: &crate::analysis::MapInfo,
    null_check_pc: Option<usize>,
) -> bool {
    if info.can_remove_lookup_pattern_v1() {
        return true;
    }

    info.is_speculative_v1()
        && uses.other_uses.is_empty()
        && null_check_pc.is_some_and(|pc| null_check_is_fallthrough_non_null(&program.insns[pc]))
}

fn build_direct_map_value_load_rewrites(
    program: &BpfProgram,
) -> anyhow::Result<DirectMapValueLoadRewrites> {
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

        let map_value =
            match resolve_frozen_map_value(program, old_fd, &mut map_cache, &mut diagnostics)? {
                Some(map_value) => map_value,
                None => {
                    pc += insn_width(insn);
                    continue;
                }
            };

        let offset = total_off as usize;
        let Some(scalar) = read_scalar_from_value_at(&map_value.value, offset, bpf_size(insn.code))
        else {
            let size = match size_in_bytes(bpf_size(insn.code)) {
                Some(size) => size.to_string(),
                None => "invalid".to_string(),
            };
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                    pc,
                    map_value.map_id,
                    offset,
                    size
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

    Ok((replacements, sites_applied, diagnostics))
}

fn resolve_frozen_map_value(
    program: &BpfProgram,
    old_fd: i32,
    cache: &mut HashMap<i32, Option<FrozenMapValue>>,
    diagnostics: &mut Vec<String>,
) -> anyhow::Result<Option<FrozenMapValue>> {
    if let Some(cached) = cache.get(&old_fd) {
        return Ok(cached.clone());
    }

    let resolved = (|| -> anyhow::Result<Option<FrozenMapValue>> {
        let Some(&map_id) = program.map_fd_bindings.get(&old_fd) else {
            return Ok(None);
        };
        let Some(info) = program
            .map_info_provider
            .map_info(program, map_id)
            .map_err(anyhow::Error::msg)?
        else {
            return Ok(None);
        };
        if !info.frozen {
            return Ok(None);
        }

        let key = vec![0u8; info.key_size as usize];
        let value_size = program
            .map_value_provider
            .lookup_value_size(program, &info)
            .map_err(anyhow::Error::msg)?;
        let value = match program
            .map_value_provider
            .lookup_elem(program, map_id, &key, value_size)
        {
            Ok(value) => value,
            Err(err)
                if is_null_map_value_snapshot_error(&err)
                    && is_hash_like_map_type(info.map_type) =>
            {
                return Ok(None);
            }
            Err(err) => return Err(anyhow::Error::msg(err)),
        };
        Ok(Some(FrozenMapValue { map_id, value }))
    })();

    let cached = match resolved {
        Ok(value) => value,
        Err(err) => {
            if is_concrete_map_value_snapshot_error(&format!("{err:#}")) {
                return Err(err);
            }
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
    Ok(cached)
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
    if raw_value.len() < stride || !raw_value.len().is_multiple_of(stride) {
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
    if size == BPF_DW {
        let signed_value = value as i64;
        if signed_value >= i32::MIN as i64 && signed_value <= i32::MAX as i64 {
            return vec![BpfInsn::mov64_imm(dst_reg, signed_value as i32)];
        }

        return emit_ldimm64(dst_reg, value);
    }

    debug_assert!(value <= u32::MAX as u64);
    vec![BpfInsn::mov32_imm(dst_reg, value as u32 as i32)]
}

fn emit_ldimm64(dst_reg: u8, value: u64) -> Vec<BpfInsn> {
    vec![
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst_reg, 0),
            0,
            value as u32 as i32,
        ),
        BpfInsn::new(0, 0, 0, (value >> 32) as u32 as i32),
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

fn is_concrete_map_value_snapshot_error(message: &str) -> bool {
    is_missing_map_value_snapshot_error(message) || is_null_map_value_snapshot_error(message)
}

fn is_hash_like_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        BPF_MAP_TYPE_HASH
            | BPF_MAP_TYPE_PERCPU_HASH
            | BPF_MAP_TYPE_LRU_HASH
            | BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}

fn lookup_pattern_removal_is_safe(
    program: &BpfProgram,
    lookup_call_pc: usize,
    skipped_pcs: &HashSet<usize>,
) -> bool {
    if skipped_pcs.is_empty() || skipped_pcs.iter().any(|&pc| pc >= program.insns.len()) {
        return false;
    }

    let min_removed_pc = skipped_pcs.iter().min().copied().unwrap_or(0);
    let end_pc = lookup_call_pc + insn_width(&program.insns[lookup_call_pc]);
    let mut pc = min_removed_pc;
    while pc < end_pc {
        let insn = &program.insns[pc];
        let width = insn_width(insn);
        let insn_pcs = pc..pc + width;

        let fully_skipped = insn_pcs.clone().all(|slot| skipped_pcs.contains(&slot));
        if fully_skipped {
            pc += width;
            continue;
        }
        if insn_pcs.clone().any(|slot| skipped_pcs.contains(&slot)) {
            return false;
        }
        if !lookup_pattern_gap_insn_is_safe(insn) {
            return false;
        }
        if [1u8, 2]
            .into_iter()
            .any(|reg| insn_uses_reg(insn, reg) || insn_defines_reg(insn, reg))
        {
            return false;
        }

        pc += width;
    }

    true
}

fn materialization_pcs_for_store(
    insns: &[BpfInsn],
    store_pc: usize,
    source_imm_pc: Option<usize>,
) -> Vec<usize> {
    let mut pcs = HashSet::new();
    insert_materialization_pc(&mut pcs, insns, store_pc);
    if let Some(source_imm_pc) = source_imm_pc {
        insert_materialization_pc(&mut pcs, insns, source_imm_pc);
    }
    let mut pcs = pcs.into_iter().collect::<Vec<_>>();
    pcs.sort_unstable();
    pcs
}

fn insert_materialization_pc(
    materialization_pcs: &mut HashSet<usize>,
    insns: &[BpfInsn],
    pc: usize,
) {
    materialization_pcs.insert(pc);
    if insns.get(pc).is_some_and(BpfInsn::is_ldimm64) && pc + 1 < insns.len() {
        materialization_pcs.insert(pc + 1);
    }
}

fn lookup_pattern_gap_insn_is_safe(insn: &BpfInsn) -> bool {
    !insn.is_jmp_class() && !matches!(insn.class(), BPF_ST | BPF_STX)
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
                let stack_bytes = find_constant_stack_bytes_with_limit(
                    insns,
                    pc,
                    bounds,
                    stack_off,
                    width,
                    Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
                )?;
                return Ok(ConstantRegValue {
                    value: constant_key_value(&stack_bytes.bytes),
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
        write!(out, "{:02x}", byte).expect("writing to String cannot fail");
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
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let bounds = subprog_bounds(insns, start_pc);
    let mut pc = start_pc + 1;

    while pc < insns.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
        let insn = &insns[pc];
        let alias_copy = alias_copy(insn, &alias_regs);
        let allow_null_check =
            classification.fixed_loads.is_empty() && classification.other_uses.is_empty();

        if let Some((dst_reg, alias_off)) = alias_copy {
            classification.alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            pc += insn_width(insn);
            continue;
        }

        if let Some(alias_off) = alias_adjustment(insns, pc, insn, &alias_regs, bounds) {
            classification.alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(insn.dst_reg(), alias_off);
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
                && alias_regs.contains_key(&insn.src_reg())
            {
                classification.alias_copy_pcs.push(pc);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                pc += insn_width(insn);
                continue;
            }
        }

        if let Some(stack_off) = resolve_stack_load_slot(insns, pc, insn, bounds) {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                classification.alias_copy_pcs.push(pc);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                pc += insn_width(insn);
                continue;
            }
        }

        if insn.is_call() {
            if insn_uses_any_alias(insn, &alias_regs) {
                classification.other_uses.push(pc);
                break;
            }

            let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
            let can_follow_helper = allow_unrelated_helper_calls
                || (allow_readonly_helper_calls && helper_call_is_readonly_for_lookup_value(insn));
            if can_follow_helper && (!surviving_aliases.is_empty() || !alias_stack_slots.is_empty())
            {
                alias_regs = surviving_aliases;
                pc += insn_width(insn);
                continue;
            }

            let has_unfollowed_aliases = !surviving_aliases.is_empty();
            alias_regs.clear();
            if !alias_stack_slots.is_empty() {
                pc += insn_width(insn);
                continue;
            }
            if has_unfollowed_aliases {
                classification.other_uses.push(pc);
                break;
            }
            break;
        }

        if insn.is_ldx_mem() && alias_regs.contains_key(&insn.src_reg()) {
            let total_off = i32::from(alias_regs[&insn.src_reg()]) + i32::from(insn.off);
            let Ok(total_off) = i16::try_from(total_off) else {
                classification.other_uses.push(pc);
                kill_defined_alias_regs(&mut alias_regs, insn);
                pc += insn_width(insn);
                continue;
            };
            classification.fixed_loads.push(FixedLoadUse {
                pc,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: total_off,
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
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        insns,
        pc,
        insn.dst_reg(),
        bounds,
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

fn resolve_stack_load_slot(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    bounds: (usize, usize),
) -> Option<i16> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        insns,
        pc,
        insn.src_reg(),
        bounds,
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

fn ends_current_use_region(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    (insn.is_jmp_class()
        && !insn.is_call()
        && !insn.is_exit()
        && !insn_uses_any_alias(insn, alias_regs))
        || starts_next_lookup_setup(insn)
}

fn starts_next_lookup_setup(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_MAP_FD
}

fn alias_copy(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> Option<(u8, i16)> {
    (insn.code == (BPF_ALU64 | BPF_MOV | BPF_X))
        .then(|| {
            alias_regs
                .get(&insn.src_reg())
                .copied()
                .map(|off| (insn.dst_reg(), off))
        })
        .flatten()
}

fn alias_adjustment(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    alias_regs: &HashMap<u8, i16>,
    bounds: (usize, usize),
) -> Option<i16> {
    if insn.class() != BPF_ALU64 {
        return None;
    }

    let base_off = i32::from(*alias_regs.get(&insn.dst_reg())?);
    let delta = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_ADD, BPF_K) => insn.imm as i64,
        (BPF_SUB, BPF_K) => -(insn.imm as i64),
        (BPF_ADD, BPF_X) => match resolve_constant_reg_value_inner(
            insns,
            pc,
            insn.src_reg(),
            bounds,
            REG_RESOLUTION_LIMIT,
        ) {
            Ok(value) => value.value as i64,
            Err(_) => return None,
        },
        (BPF_SUB, BPF_X) => match resolve_constant_reg_value_inner(
            insns,
            pc,
            insn.src_reg(),
            bounds,
            REG_RESOLUTION_LIMIT,
        ) {
            Ok(value) => -(value.value as i64),
            Err(_) => return None,
        },
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

fn null_check_removal_window_is_trivial(
    program: &BpfProgram,
    uses: &R0UseClassification,
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
    let Some(mut pc) = advance_to_non_null_path(
        null_check_pc,
        &program.insns[null_check_pc],
        program.insns.len(),
    ) else {
        return false;
    };
    let load_dst_regs = uses
        .fixed_loads
        .iter()
        .map(|load| (load.pc, load.dst_reg))
        .collect::<HashMap<_, _>>();
    let mut safe_scalar_regs = HashSet::new();
    let mut killed_arg_regs = HashSet::new();

    while pc < null_target_pc {
        let insn = &program.insns[pc];
        let width = insn_width(insn);
        let insn_pcs = pc..pc + width;

        if insn_pcs.clone().all(|slot| skipped_pcs.contains(&slot)) {
            for reg in 1..=5 {
                if insn_defines_reg(insn, reg) {
                    killed_arg_regs.insert(reg);
                    safe_scalar_regs.remove(&reg);
                }
            }
            pc += width;
            continue;
        }
        if insn_pcs.clone().any(|slot| skipped_pcs.contains(&slot)) {
            return false;
        }
        if replacement_pcs.contains(&pc) {
            let Some(&dst_reg) = load_dst_regs.get(&pc) else {
                return false;
            };
            mark_safe_scalar_reg(&mut safe_scalar_regs, &mut killed_arg_regs, dst_reg);
            pc += width;
            continue;
        }

        if !is_trivially_safe_null_check_guarded_insn(
            insn,
            &mut safe_scalar_regs,
            &mut killed_arg_regs,
        ) {
            return false;
        }
        pc += width;
    }

    true
}

fn is_trivially_safe_null_check_guarded_insn(
    insn: &BpfInsn,
    safe_scalar_regs: &mut HashSet<u8>,
    killed_arg_regs: &mut HashSet<u8>,
) -> bool {
    if insn.is_exit() || insn.is_ja() {
        return true;
    }

    if insn.is_ldimm64() {
        if insn.src_reg() != 0 {
            return false;
        }
        mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
        return true;
    }

    match insn.class() {
        BPF_ALU64 | BPF_ALU => match (bpf_op(insn.code), bpf_src(insn.code)) {
            (BPF_MOV, BPF_K) => {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_MOV, BPF_X) if safe_scalar_regs.contains(&insn.src_reg()) => {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_ADD | BPF_SUB | BPF_MUL | BPF_AND | BPF_OR | BPF_LSH | BPF_RSH, BPF_K)
                if safe_scalar_regs.contains(&insn.dst_reg()) =>
            {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_ADD | BPF_SUB | BPF_MUL | BPF_AND | BPF_OR | BPF_LSH | BPF_RSH, BPF_X)
                if safe_scalar_regs.contains(&insn.dst_reg())
                    && safe_scalar_regs.contains(&insn.src_reg()) =>
            {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            _ => false,
        },
        BPF_JMP | BPF_JMP32 if insn.is_call() => {
            if (1..=5).any(|reg| killed_arg_regs.contains(&reg)) {
                return false;
            }
            for reg in 0..=5 {
                safe_scalar_regs.remove(&reg);
            }
            killed_arg_regs.extend(1..=5);
            true
        }
        _ => false,
    }
}

fn mark_safe_scalar_reg(
    safe_scalar_regs: &mut HashSet<u8>,
    killed_arg_regs: &mut HashSet<u8>,
    reg: u8,
) {
    safe_scalar_regs.insert(reg);
    killed_arg_regs.remove(&reg);
}

fn insn_uses_any_alias(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    alias_regs
        .keys()
        .copied()
        .any(|reg| insn_uses_reg(insn, reg))
}

fn kill_defined_alias_regs(alias_regs: &mut HashMap<u8, i16>, insn: &BpfInsn) {
    alias_regs.retain(|&reg, _| !insn_defines_reg(insn, reg));
}

fn insn_uses_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            if bpf_op(insn.code) == BPF_MOV {
                bpf_src(insn.code) == BPF_X && insn.src_reg() == reg
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
#[path = "map_inline_tests.rs"]
mod tests;
