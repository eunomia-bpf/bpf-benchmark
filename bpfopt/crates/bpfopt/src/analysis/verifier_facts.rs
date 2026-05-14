// SPDX-License-Identifier: MIT
//! Verifier-log facts consumed by bpfopt analyses.
//!
//! TODO: migrate the verifier-derived facts and local CFG/dataflow facts into
//! one lifecycle-aligned fact bundle. This file is the landing point for that
//! work; for now it only houses the existing verifier-state queries without
//! changing their algorithms or callers.

use crate::analysis::InsnSite;
use crate::pass::RegKind;
use crate::verifier_log::{RegState, StackState, VerifierInsn, VerifierInsnKind};
use std::collections::BTreeMap;
use std::sync::Arc;

pub(crate) type VerifierStatesBySite = BTreeMap<InsnSite, Arc<[VerifierInsn]>>;

pub(crate) fn states_at(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
) -> Option<&[VerifierInsn]> {
    states_by_site?.get(&site).map(AsRef::as_ref)
}

pub(crate) fn reg_known_constant(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
    reg: u8,
    is_32: bool,
) -> Option<i64> {
    let mut states = verifier_post_insn_reg_states(states_by_site, site, reg)?;
    let first = reg_exact_value_for_width(states.next()?, is_32)?;
    for state in states {
        if reg_exact_value_for_width(state, is_32)? != first {
            return None;
        }
    }
    Some(first as i64)
}

pub(crate) fn reg_kind(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
    reg: u8,
) -> Option<RegKind> {
    let mut states = verifier_reg_states(states_by_site, site, reg)?;
    let first = reg_kind_from_verifier_type(&states.next()?.reg_type);
    for state in states {
        if reg_kind_from_verifier_type(&state.reg_type) != first {
            return None;
        }
    }
    Some(first)
}

pub(crate) fn reg_known_stack_bytes(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
    reg: u8,
    key_width: usize,
) -> Option<Vec<u8>> {
    let states = states_at(states_by_site, site)?;
    if states.is_empty()
        || states
            .iter()
            .any(|state| state.kind == VerifierInsnKind::EdgeFullState)
    {
        return None;
    }
    let mut first = None;
    for state in states {
        let reg_state = state.regs.get(&reg)?;
        let stack_off = fp_stack_offset_from_reg_state(reg_state)?;
        let bytes = known_stack_bytes_from_state(state, stack_off, key_width)?;
        match &first {
            Some(existing) if existing != &bytes => return None,
            Some(_) => {}
            None => first = Some(bytes),
        }
    }
    first
}

pub(crate) fn site_is_dead_code(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
) -> bool {
    states_at(states_by_site, site)
        .is_some_and(|states| !states.is_empty() && states.iter().all(|state| state.speculative))
}

fn verifier_reg_states(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
    reg: u8,
) -> Option<impl Iterator<Item = &RegState>> {
    let states = states_at(states_by_site, site)?;
    if states.is_empty()
        || states
            .iter()
            .any(|state| state.kind == VerifierInsnKind::EdgeFullState)
    {
        return None;
    }
    if states.iter().any(|state| !state.regs.contains_key(&reg)) {
        return None;
    }
    Some(states.iter().filter_map(move |state| state.regs.get(&reg)))
}

fn verifier_post_insn_reg_states(
    states_by_site: Option<&VerifierStatesBySite>,
    site: InsnSite,
    reg: u8,
) -> Option<impl Iterator<Item = &RegState>> {
    let states = states_at(states_by_site, site)?;
    let post_states = states
        .iter()
        .filter(|state| state.kind == VerifierInsnKind::InsnDeltaState)
        .collect::<Vec<_>>();
    if post_states.is_empty()
        || post_states
            .iter()
            .any(|state| !state.regs.contains_key(&reg))
    {
        return None;
    }
    Some(
        post_states
            .into_iter()
            .filter_map(move |state| state.regs.get(&reg)),
    )
}

fn reg_exact_value(state: &RegState) -> Option<u64> {
    state
        .exact_u64()
        .or_else(|| state.exact_u32().map(u64::from))
}

fn reg_exact_value_for_width(state: &RegState, is_32: bool) -> Option<u64> {
    if is_32 {
        state.exact_u32().map(u64::from)
    } else {
        state.exact_u64()
    }
}

fn fp_stack_offset_from_reg_state(state: &RegState) -> Option<i32> {
    (state.reg_type == "fp").then(|| state.offset.unwrap_or(0))
}

fn known_stack_bytes_from_state(
    state: &VerifierInsn,
    stack_off: i32,
    width: usize,
) -> Option<Vec<u8>> {
    let mut bytes = Vec::with_capacity(width);
    for idx in 0..width {
        let idx = match i32::try_from(idx) {
            Ok(idx) => idx,
            Err(_) => return None,
        };
        bytes.push(known_stack_byte_from_state(
            state,
            stack_off.checked_add(idx)?,
        )?);
    }
    Some(bytes)
}

fn known_stack_byte_from_state(state: &VerifierInsn, absolute_off: i32) -> Option<u8> {
    let slot_start = verifier_stack_slot_start(absolute_off)?;
    let byte_index = usize::try_from(absolute_off - i32::from(slot_start)).ok()?;
    if byte_index >= 8 {
        return None;
    }
    let stack = state.stack.get(&slot_start)?;
    match verifier_stack_slot_type(stack, byte_index) {
        Some(b'0') => Some(0),
        Some(b'r') | None => verifier_stack_slot_exact_bytes(stack).map(|bytes| bytes[byte_index]),
        Some(_) => None,
    }
}

fn verifier_stack_slot_start(absolute_off: i32) -> Option<i16> {
    if absolute_off >= 0 {
        return None;
    }
    let slot_index = ((-absolute_off - 1) / 8) + 1;
    i16::try_from(-slot_index * 8).ok()
}

fn verifier_stack_slot_type(stack: &StackState, byte_index: usize) -> Option<u8> {
    let slot_types = stack.slot_types.as_ref()?;
    if byte_index >= 8 {
        return None;
    }
    slot_types.as_bytes().get(7 - byte_index).copied()
}

fn verifier_stack_slot_exact_bytes(stack: &StackState) -> Option<[u8; 8]> {
    let value = reg_exact_value(stack.value.as_ref()?)?;
    Some(value.to_le_bytes())
}

fn reg_kind_from_verifier_type(reg_type: &str) -> RegKind {
    match reg_type {
        "scalar" => RegKind::Scalar,
        "fp" => RegKind::FramePointer,
        "ctx" => RegKind::Context,
        "pkt" => RegKind::PacketPointer,
        "pkt_meta" => RegKind::PacketMetaPointer,
        "map_ptr" => RegKind::MapPointer,
        "map_value" => RegKind::MapValue,
        "map_key" => RegKind::MapKey,
        "mem" | "buf" | "ringbuf_mem" | "iter" => RegKind::Memory,
        other if other.starts_with("scalar") => RegKind::Scalar,
        other if other.starts_with("fp") => RegKind::FramePointer,
        "" => RegKind::Unknown,
        other if other.contains("ptr_") || other.contains("_ptr") => RegKind::BtfStructPointer,
        _ => RegKind::OtherPointer,
    }
}
