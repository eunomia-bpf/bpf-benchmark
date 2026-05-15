// SPDX-License-Identifier: MIT
//! Parser for BPF verifier logs captured with `log_level=2`.
//!
//! The verifier emits state snapshots in a few common forms:
//! - `from <prev> to <pc>: R0=... R1=...`
//! - `<pc>: R0=... R1=...`
//! - `<pc>: (..insn..) ... ; R0=... R1=...`
//!
//! This module extracts per-PC register state summaries that feed later
//! optimization analyses (constant propagation, range checks, liveness, etc.).
use std::collections::HashMap;

use anyhow::{anyhow, bail, Context, Result};
#[allow(clippy::enum_variant_names)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum VerifierInsnKind {
    EdgeFullState,
    PcFullState,
    BranchDeltaState,
    InsnDeltaState,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum VerifierValueWidth {
    Unknown,
    Bits32,
    Bits64,
}
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub(crate) struct Tnum {
    pub value: u64,
    pub mask: u64,
}
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub(crate) struct ScalarRange {
    pub smin: Option<i64>,
    pub smax: Option<i64>,
    pub umin: Option<u64>,
    pub umax: Option<u64>,
    pub smin32: Option<i32>,
    pub smax32: Option<i32>,
    pub umin32: Option<u32>,
    pub umax32: Option<u32>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub(crate) struct VerifierInsn {
    pub pc: usize,
    pub frame: usize,
    pub from_pc: Option<usize>,
    pub kind: VerifierInsnKind,
    pub speculative: bool,
    pub regs: HashMap<u8, RegState>,
    pub stack: HashMap<i16, StackState>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub(crate) struct RegState {
    pub reg_type: String,
    pub value_width: VerifierValueWidth,
    pub precise: bool,
    pub exact_value: Option<u64>,
    pub tnum: Option<Tnum>,
    pub range: ScalarRange,
    pub offset: Option<i32>,
    pub id: Option<u32>,
}
impl RegState {
    pub fn new(reg_type: impl Into<String>, value_width: VerifierValueWidth) -> Self {
        Self {
            reg_type: reg_type.into(),
            value_width,
            precise: false,
            exact_value: None,
            tnum: None,
            range: ScalarRange::default(),
            offset: None,
            id: None,
        }
    }
    pub fn exact_u64(&self) -> Option<u64> {
        if self.reg_type != "scalar" {
            return None;
        }
        match self.value_width {
            VerifierValueWidth::Bits32 => None,
            VerifierValueWidth::Bits64 | VerifierValueWidth::Unknown => self.exact_value,
        }
    }
    pub fn exact_u32(&self) -> Option<u32> {
        if self.reg_type != "scalar" {
            return None;
        }
        self.exact_value.map(|value| value as u32)
    }
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub(crate) struct StackState {
    pub slot_types: Option<String>,
    pub value: Option<RegState>,
}
#[cfg(test)]
pub(crate) fn parse_verifier_log(log: &str) -> Vec<VerifierInsn> {
    parse_verifier_log_result(log).expect("test verifier log should parse")
}
#[cfg(test)]
pub(crate) fn parse_verifier_log_result(log: &str) -> Result<Vec<VerifierInsn>> {
    parse_log_states(log, true)
}
pub(crate) fn verifier_states_from_log(log: &str) -> Result<Vec<VerifierInsn>> {
    parse_log_states(log, false)
}
fn parse_log_states(log: &str, include_branch_delta: bool) -> Result<Vec<VerifierInsn>> {
    let mut states = Vec::new();
    for (idx, line) in log.lines().enumerate() {
        let Some(state) = parse_state_line(line).with_context(|| {
            format!(
                "failed to parse verifier state line {}: {:?}",
                idx + 1,
                line
            )
        })?
        else {
            continue;
        };
        if include_branch_delta || state.kind != VerifierInsnKind::BranchDeltaState {
            states.push(state);
        }
    }
    Ok(states)
}
fn parse_state_line(line: &str) -> Result<Option<VerifierInsn>> {
    let trimmed = line.trim();
    if trimmed.is_empty() {
        return Ok(None);
    }
    let Some((pc, from_pc, kind, speculative, state_text)) =
        parse_from_state_line(trimmed).or_else(|| parse_pc_state_line(trimmed))
    else {
        if looks_like_state_line(trimmed) {
            bail!("state-like line did not match a supported verifier state format");
        }
        return Ok(None);
    };
    let (frame, state_text) = strip_frame_prefix(state_text);
    let mut regs = HashMap::new();
    let mut stack = HashMap::new();
    let tokens = split_top_level_tokens(state_text);
    let mut idx = 0usize;
    while idx < tokens.len() {
        let token = tokens[idx];
        if let Some((regno, state)) = parse_reg_token(token) {
            regs.insert(regno, state);
            idx += 1;
            continue;
        }
        if let Some((off, mut state)) = parse_stack_token(token) {
            if state.value.is_none()
                && idx + 1 < tokens.len()
                && parse_reg_token(tokens[idx + 1]).is_none()
                && parse_stack_token(tokens[idx + 1]).is_none()
                && looks_like_reg_state(tokens[idx + 1])
            {
                match parse_reg_state(tokens[idx + 1], VerifierValueWidth::Unknown) {
                    Ok(value) => {
                        state.value = Some(value);
                        idx += 1;
                    }
                    Err(err) => {
                        warn_verifier_log(format!("skipping {:?}: {err:#}", tokens[idx + 1]));
                    }
                }
            }
            stack.insert(off, state);
            idx += 1;
            continue;
        }
        idx += 1;
    }
    if regs.is_empty() && stack.is_empty() {
        bail!("verifier state line contained no register or stack state");
    }
    Ok(Some(VerifierInsn {
        pc,
        frame,
        from_pc,
        kind,
        speculative,
        regs,
        stack,
    }))
}
fn looks_like_state_line(line: &str) -> bool {
    if line.starts_with("from ") {
        return line.contains(':')
            && (line.contains(" R") || line.contains(": R") || line.contains("frame"));
    }
    let Some((pc, tail)) = line.split_once(':') else {
        return false;
    };
    if !pc.trim().chars().all(|ch| ch.is_ascii_digit()) {
        return false;
    }
    let tail = tail.trim();
    if is_state_text(tail) {
        return true;
    }
    // "<pc>: <insn> ; <state>" — only state-like if the post-`;` segment
    // actually contains register/frame state. Lines like
    // "224: (85) call bpf_tail_call#12       ;" have an empty post-`;`
    // because the verifier emits no state for non-returning instructions.
    tail.split_once(';')
        .map(|(_, state)| is_state_text(state.trim()))
        .unwrap_or(false)
}
fn parse_from_state_line(
    line: &str,
) -> Option<(usize, Option<usize>, VerifierInsnKind, bool, &str)> {
    let rest = line.strip_prefix("from ")?;
    let (from_text, rest) = rest.split_once(" to ")?;
    let from_pc = from_text.trim().parse().ok()?;
    let digits_len = rest.chars().take_while(|ch| ch.is_ascii_digit()).count();
    if digits_len == 0 {
        return None;
    }
    let pc = rest[..digits_len].parse().ok()?;
    let mut tail = &rest[digits_len..];
    let speculative = if let Some(stripped) = tail.strip_prefix(" (speculative execution)") {
        tail = stripped;
        true
    } else {
        false
    };
    let state_text = tail.strip_prefix(':')?.trim();
    is_state_text(state_text).then_some((
        pc,
        Some(from_pc),
        VerifierInsnKind::EdgeFullState,
        speculative,
        state_text,
    ))
}
fn parse_pc_state_line(line: &str) -> Option<(usize, Option<usize>, VerifierInsnKind, bool, &str)> {
    let colon = line.find(':')?;
    let pc = line[..colon].trim().parse().ok()?;
    let tail = line[colon + 1..].trim();
    if tail.is_empty() {
        return None;
    }
    if is_state_text(tail) {
        return Some((pc, None, VerifierInsnKind::PcFullState, false, tail));
    }
    let semicolon = find_top_level_char(tail, ';')?;
    let insn_text = tail[..semicolon].trim();
    let state_text = tail[semicolon + 1..].trim();
    let kind = if insn_text.contains(" if ") && insn_text.contains(" goto ") {
        VerifierInsnKind::BranchDeltaState
    } else {
        VerifierInsnKind::InsnDeltaState
    };
    is_state_text(state_text).then_some((pc, None, kind, false, state_text))
}
fn is_state_text(text: &str) -> bool {
    text.starts_with('R') || text.starts_with("frame")
}
fn strip_frame_prefix(text: &str) -> (usize, &str) {
    let Some(rest) = text.strip_prefix("frame") else {
        return (0, text);
    };
    let digits_len = rest.chars().take_while(|ch| ch.is_ascii_digit()).count();
    if digits_len == 0 {
        return (0, text);
    }
    let frame = rest[..digits_len].parse().ok();
    let tail = rest[digits_len..].trim_start();
    match (frame, tail.strip_prefix(':')) {
        (Some(frame), Some(tail)) => (frame, tail.trim_start()),
        _ => (0, text),
    }
}
fn split_top_level_tokens(text: &str) -> Vec<&str> {
    let mut tokens = Vec::new();
    let mut start = None;
    let mut depth = 0i32;
    for (idx, ch) in text.char_indices() {
        match ch {
            '(' => {
                if start.is_none() {
                    start = Some(idx);
                }
                depth += 1;
            }
            ')' => {
                depth -= 1;
            }
            ch if ch.is_whitespace() && depth == 0 => {
                if let Some(token_start) = start.take() {
                    tokens.push(&text[token_start..idx]);
                }
            }
            _ => {
                if start.is_none() {
                    start = Some(idx);
                }
            }
        }
    }
    if let Some(token_start) = start {
        tokens.push(&text[token_start..]);
    }
    tokens
}
fn parse_reg_token(token: &str) -> Option<(u8, RegState)> {
    let (lhs, rhs) = token.split_once('=')?;
    let Some((regno, value_width)) = parse_reg_name(lhs) else {
        if lhs.starts_with('R') {
            warn_verifier_log(format!("invalid register token {token:?}"));
        }
        return None;
    };
    match parse_reg_state(rhs.trim(), value_width) {
        Ok(state) => Some((regno, state)),
        Err(err) => {
            warn_verifier_log(format!("skipping {token:?}: {err:#}"));
            None
        }
    }
}
fn parse_stack_token(token: &str) -> Option<(i16, StackState)> {
    let (lhs, rhs) = token.split_once('=')?;
    let fp_off = lhs.strip_prefix("fp")?;
    let Some(off) = parse_i32(fp_off).and_then(|off| off.try_into().ok()) else {
        warn_verifier_log(format!("invalid stack offset in {token:?}"));
        return None;
    };
    match parse_stack_state(rhs.trim()) {
        Ok(state) => Some((off, state)),
        Err(err) => {
            warn_verifier_log(format!("skipping {token:?}: {err:#}"));
            None
        }
    }
}
fn parse_reg_name(name: &str) -> Option<(u8, VerifierValueWidth)> {
    let name = name.strip_prefix('R')?;
    let (name, value_width) = if let Some(name) = name.strip_suffix("_w") {
        (name, VerifierValueWidth::Bits32)
    } else {
        (name, VerifierValueWidth::Bits64)
    };
    Some((name.parse().ok()?, value_width))
}
fn parse_reg_state(raw: &str, value_width: VerifierValueWidth) -> Result<RegState> {
    let (precise, value) = match raw.strip_prefix('P') {
        Some(rest) => (true, rest),
        None => (false, raw),
    };
    if let Some(exact) = parse_scalar_exact_value(value) {
        let mut state = RegState::new("scalar", value_width);
        state.precise = precise;
        state.exact_value = Some(exact);
        apply_exact_value_to_range(&mut state.range, exact, value_width);
        return Ok(state);
    }
    if let Some(rest) = value.strip_prefix("fp") {
        let mut state = RegState::new("fp", value_width);
        state.precise = precise;
        // Cross-frame form `fp[N]-M`: the kernel verifier annotates the source
        // frame for stack pointers. We don't track frame index per register, so
        // strip the `[N]` and use the offset M.
        let offset_text = match rest.strip_prefix('[').and_then(|r| r.split_once(']')) {
            Some((_, after)) => after,
            None => rest,
        };
        if !offset_text.is_empty() {
            state.offset = Some(
                parse_i32(offset_text)
                    .ok_or_else(|| anyhow!("invalid frame-pointer offset {offset_text:?}"))?,
            );
        }
        return Ok(state);
    }
    if let Some(open) = value.find('(') {
        let close = value
            .rfind(')')
            .ok_or_else(|| anyhow!("missing ')' in verifier register state {value:?}"))?;
        let reg_type = normalize_reg_type(&value[..open]);
        let mut state = RegState::new(reg_type, value_width);
        state.precise = precise;
        parse_reg_attributes(&value[open + 1..close], &mut state);
        infer_exact_value(&mut state);
        return Ok(state);
    }
    let mut state = RegState::new(normalize_reg_type(value), value_width);
    state.precise = precise;
    Ok(state)
}
fn normalize_reg_type(reg_type: &str) -> String {
    match reg_type {
        "inv" => "scalar".to_string(),
        other => other.to_string(),
    }
}
fn parse_stack_state(raw: &str) -> Result<StackState> {
    if raw.is_empty() {
        return Ok(StackState {
            slot_types: None,
            value: None,
        });
    }
    for split in raw.char_indices().skip(1).map(|(idx, _)| idx) {
        let prefix = &raw[..split];
        let rest = raw[split..].trim();
        if prefix.len() == 8
            && prefix.chars().all(is_stack_slot_type_char)
            && looks_like_reg_state(rest)
        {
            return Ok(StackState {
                slot_types: Some(prefix.to_string()),
                value: Some(parse_reg_state(rest, VerifierValueWidth::Unknown)?),
            });
        }
    }
    if raw.len() == 8 && raw.chars().all(is_stack_slot_type_char) {
        return Ok(StackState {
            slot_types: Some(raw.to_string()),
            value: None,
        });
    }
    if looks_like_reg_state(raw) {
        return Ok(StackState {
            slot_types: None,
            value: Some(parse_reg_state(raw, VerifierValueWidth::Unknown)?),
        });
    }
    if raw.chars().all(is_stack_slot_type_char) {
        return Ok(StackState {
            slot_types: Some(raw.to_string()),
            value: None,
        });
    }
    Ok(StackState {
        slot_types: None,
        value: Some(parse_reg_state(raw, VerifierValueWidth::Unknown)?),
    })
}
fn looks_like_reg_state(raw: &str) -> bool {
    if raw.is_empty() {
        return false;
    }
    parse_signed_value(raw).is_some()
        || raw.starts_with("fp")
        || raw.contains('(')
        || raw == "scalar"
        || (!raw.chars().all(is_stack_slot_type_char)
            && raw
                .chars()
                .all(|ch| ch.is_ascii_alphanumeric() || matches!(ch, '_' | '+' | '-')))
}
fn is_stack_slot_type_char(ch: char) -> bool {
    matches!(ch, '?' | 'r' | 'm' | '0' | 'd' | 'i' | 'f')
}
fn parse_reg_attributes(attrs: &str, state: &mut RegState) {
    for segment in split_top_level_segments(attrs, ',') {
        let parts: Vec<_> = segment
            .split('=')
            .map(str::trim)
            .filter(|part| !part.is_empty())
            .collect();
        if parts.len() == 1 {
            match parts[0] {
                "trusted" | "untrusted" | "rdonly_buf" | "rdwr_buf" | "rcu" | "percpu_ptr"
                | "may_be_null" | "alloc" => continue,
                other => {
                    warn_verifier_log(format!("unknown verifier register attribute {other:?}"));
                    continue;
                }
            }
        }
        if parts.len() < 2 {
            warn_verifier_log(format!(
                "malformed verifier register attribute segment {segment:?}"
            ));
            continue;
        }
        let value = parts[parts.len() - 1];
        for key in &parts[..parts.len() - 1] {
            match *key {
                "smin" | "smin_value" => {
                    state.range.smin = parse_attr(key, value, parse_signed_value(value));
                }
                "smax" | "smax_value" => {
                    state.range.smax = parse_attr(key, value, parse_signed_value(value));
                }
                "umin" | "umin_value" => {
                    state.range.umin = parse_attr(key, value, parse_unsigned_value(value));
                }
                "umax" | "umax_value" => {
                    state.range.umax = parse_attr(key, value, parse_unsigned_value(value));
                }
                "smin32" | "smin32_value" => {
                    state.range.smin32 = parse_attr(key, value, parse_i32(value));
                }
                "smax32" | "smax32_value" => {
                    state.range.smax32 = parse_attr(key, value, parse_i32(value));
                }
                "umin32" | "umin32_value" => {
                    state.range.umin32 = parse_attr(key, value, parse_u32(value));
                }
                "umax32" | "umax32_value" => {
                    state.range.umax32 = parse_attr(key, value, parse_u32(value));
                }
                "off" => state.offset = parse_attr(key, value, parse_i32(value)),
                "id" => state.id = parse_attr(key, value, parse_u32(value)),
                "var_off" => {
                    state.tnum = parse_attr(key, value, parse_tnum(value));
                }
                "r" | "map" | "ks" | "vs" | "imm" | "ref_obj_id" | "btf_id" | "mem_size"
                | "alloc_size" | "aux_off" | "name" => {}
                other => {
                    warn_verifier_log(format!("unknown verifier register attribute {other:?}"));
                }
            }
        }
    }
}

fn warn_verifier_log(message: String) {
    eprintln!("warning: verifier log: {message}");
}
fn parse_attr<T>(key: &str, value: &str, parsed: Option<T>) -> Option<T> {
    if parsed.is_none() {
        warn_verifier_log(format!("invalid {key} attribute value {value:?}"));
    }
    parsed
}
fn apply_exact_value_to_range(
    range: &mut ScalarRange,
    exact: u64,
    value_width: VerifierValueWidth,
) {
    let exact32 = exact as u32;
    range.umin32 = Some(exact32);
    range.umax32 = Some(exact32);
    range.smin32 = Some(exact32 as i32);
    range.smax32 = Some(exact32 as i32);
    if value_width != VerifierValueWidth::Bits32 {
        range.umin = Some(exact);
        range.umax = Some(exact);
        range.smin = Some(exact as i64);
        range.smax = Some(exact as i64);
    }
}
fn infer_exact_value(state: &mut RegState) {
    if state.reg_type != "scalar" || state.exact_value.is_some() {
        return;
    }
    if let Some(tnum) = state.tnum {
        if tnum.mask == 0 {
            state.exact_value = Some(tnum.value);
            return;
        }
    }
    if let (Some(umin), Some(umax)) = (state.range.umin, state.range.umax) {
        if umin == umax {
            state.exact_value = Some(umin);
            return;
        }
    }
    if let (Some(umin32), Some(umax32)) = (state.range.umin32, state.range.umax32) {
        if umin32 == umax32 {
            state.exact_value = Some(u64::from(umin32));
            if state.value_width == VerifierValueWidth::Bits64 {
                state.value_width = VerifierValueWidth::Bits32;
            }
        }
    }
}
fn split_top_level_segments(text: &str, separator: char) -> Vec<&str> {
    let mut segments = Vec::new();
    let mut start = 0usize;
    let mut depth = 0i32;
    for (idx, ch) in text.char_indices() {
        match ch {
            '(' => depth += 1,
            ')' => depth -= 1,
            _ if ch == separator && depth == 0 => {
                let segment = text[start..idx].trim();
                if !segment.is_empty() {
                    segments.push(segment);
                }
                start = idx + ch.len_utf8();
            }
            _ => {}
        }
    }
    let segment = text[start..].trim();
    if !segment.is_empty() {
        segments.push(segment);
    }
    segments
}
fn find_top_level_char(text: &str, needle: char) -> Option<usize> {
    let mut depth = 0i32;
    for (idx, ch) in text.char_indices() {
        match ch {
            '(' => depth += 1,
            ')' => depth -= 1,
            _ if ch == needle && depth == 0 => return Some(idx),
            _ => {}
        }
    }
    None
}
fn parse_i32(text: &str) -> Option<i32> {
    parse_signed_value(text)?.try_into().ok()
}
fn parse_u32(text: &str) -> Option<u32> {
    parse_unsigned_u64(text)?.try_into().ok()
}
fn parse_hex_u64(text: &str) -> Option<u64> {
    u64::from_str_radix(text, 16).ok()
}
fn parse_signed_value(text: &str) -> Option<i64> {
    let value = text.trim();
    let (negative, body) = match value.as_bytes().first()? {
        b'-' => (true, &value[1..]),
        b'+' => (false, &value[1..]),
        _ => (false, value),
    };
    if let Some(rest) = body.strip_prefix("0x").or_else(|| body.strip_prefix("0X")) {
        let mag = parse_hex_u64(rest)?;
        if negative {
            return i64::try_from(-(mag as i128)).ok();
        }
        return Some(mag as i64);
    }
    if negative {
        value.parse::<i64>().ok()
    } else {
        body.parse().ok()
    }
}
fn parse_unsigned_value(text: &str) -> Option<u64> {
    let value = text.trim();
    if value.is_empty() || value.starts_with('-') {
        return None;
    }
    if let Some(rest) = value.strip_prefix('+') {
        parse_unsigned_u64(rest)
    } else {
        parse_unsigned_u64(value)
    }
}
fn parse_unsigned_u64(text: &str) -> Option<u64> {
    if let Some(rest) = text.strip_prefix("0x").or_else(|| text.strip_prefix("0X")) {
        return parse_hex_u64(rest);
    }
    text.parse().ok()
}
fn parse_scalar_exact_value(text: &str) -> Option<u64> {
    let value = text.trim();
    if value.is_empty() || value.contains('(') {
        return None;
    }
    if let Some(rest) = value
        .strip_prefix("-0x")
        .or_else(|| value.strip_prefix("-0X"))
    {
        let magnitude = parse_hex_u64(rest)?;
        return Some(0u64.wrapping_sub(magnitude));
    }
    if let Some(rest) = value.strip_prefix('-') {
        let magnitude = rest.parse().ok()?;
        return Some(0u64.wrapping_sub(magnitude));
    }
    if let Some(rest) = value.strip_prefix('+') {
        return parse_unsigned_u64(rest);
    }
    parse_unsigned_u64(value)
}
fn parse_tnum(text: &str) -> Option<Tnum> {
    let value = text.trim();
    let inner = value.strip_prefix('(')?.strip_suffix(')')?;
    let (value, mask) = inner.split_once(';')?;
    Some(Tnum {
        value: parse_unsigned_u64(value.trim())?,
        mask: parse_unsigned_u64(mask.trim())?,
    })
}
#[cfg(test)]
#[path = "verifier_log_tests.rs"]
mod tests;

// ==========================================================================
// Verifier-state interpretation helpers (formerly analysis/verifier_facts.rs).
//
// Public query functions take an already-resolved slice of `VerifierInsn`
// (one site's visits). Storage lives inline on `InsnNode`/`BasicBlock`; the
// site-to-state lookup happens in `ProgramCFG::verifier_states_at`.
// ==========================================================================

use crate::analysis::InsnSite;
use crate::pass::RegKind;
use std::collections::BTreeMap;
use std::sync::Arc;

/// Lift-time mapping from site to verifier states. After lift, per-site
/// states live on `InsnNode`/`BasicBlock`; this alias survives only at the
/// lift boundary.
pub(crate) type VerifierStatesBySite = BTreeMap<InsnSite, Arc<[VerifierInsn]>>;

pub(crate) fn reg_known_constant(
    states: Option<&[VerifierInsn]>,
    reg: u8,
    is_32: bool,
) -> Option<i64> {
    // Use only InsnDeltaState (the per-PC post-state line) — for an ALU op
    // at PC, the verifier post-state captures the *result*, while
    // PcFullState/EdgeFullState capture pre-state on entry. Mixing pre and
    // post would substitute a stale value for the ALU's destination.
    let mut iter = verifier_post_insn_reg_states(states, reg)?;
    let first = reg_exact_value_for_width(iter.next()?, is_32)?;
    for state in iter {
        if reg_exact_value_for_width(state, is_32)? != first {
            return None;
        }
    }
    Some(first as i64)
}

pub(crate) fn reg_kind(states: Option<&[VerifierInsn]>, reg: u8) -> Option<RegKind> {
    let mut iter = verifier_reg_states(states, reg)?;
    let first = reg_kind_from_verifier_type(&iter.next()?.reg_type);
    for state in iter {
        if reg_kind_from_verifier_type(&state.reg_type) != first {
            return None;
        }
    }
    Some(first)
}

pub(crate) fn reg_known_stack_bytes(
    states: Option<&[VerifierInsn]>,
    reg: u8,
    key_width: usize,
) -> Option<Vec<u8>> {
    let states = states?;
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

pub(crate) fn site_is_dead_code(states: Option<&[VerifierInsn]>) -> bool {
    states.is_some_and(|states| !states.is_empty() && states.iter().all(|s| s.speculative))
}

fn verifier_reg_states(
    states: Option<&[VerifierInsn]>,
    reg: u8,
) -> Option<impl Iterator<Item = &RegState>> {
    let states = states?;
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
    states: Option<&[VerifierInsn]>,
    reg: u8,
) -> Option<impl Iterator<Item = &RegState>> {
    let states = states?;
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
