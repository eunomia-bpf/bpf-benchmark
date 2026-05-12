// SPDX-License-Identifier: MIT
//! Parser for BPF verifier logs captured with `log_level=2`.
//!
//! The verifier emits state snapshots in a few common forms:
//! - `from <prev> to <pc>: R0=... R1=...`
//! - `<pc>: R0=... R1=...`
//! - `<pc>: (..insn..) ... ; R0=... R1=...`
//!
//! This module extracts per-PC register state summaries that can feed later
//! optimization analyses (constant propagation, range checks, liveness, etc.).
//!
//! Used to turn raw verifier logs into structured verifier-state JSON.
use serde::{Deserialize, Serialize};
use std::collections::{BTreeMap, HashMap};
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
#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierStatesJson {
    #[serde(default)]
    pub insns: Vec<VerifierInsnJson>,
}
#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierInsnJson {
    pub pc: usize,
    #[serde(default, skip_serializing_if = "is_zero_usize")]
    pub frame: usize,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub kind: Option<String>,
    #[serde(default, skip_serializing_if = "BTreeMap::is_empty")]
    pub stack: BTreeMap<String, VerifierStackJson>,
    #[serde(default)]
    pub regs: BTreeMap<String, VerifierRegJson>,
}
#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierStackJson {
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub slot_types: Option<String>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub value: Option<VerifierRegJson>,
}
#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierRegJson {
    #[serde(rename = "type", default = "default_reg_type")]
    pub reg_type: String,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub precise: Option<bool>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub offset: Option<i32>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub const_val: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub min: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub max: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub tnum: Option<String>,
}
fn default_reg_type() -> String {
    "scalar".to_string()
}
fn is_zero_usize(value: &usize) -> bool {
    *value == 0
}
#[cfg(test)]
pub(crate) fn parse_verifier_log(log: &str) -> Vec<VerifierInsn> {
    log.lines().filter_map(parse_state_line).collect()
}
pub fn verifier_states_from_log(log: &str) -> VerifierStatesJson {
    let parsed: Vec<VerifierInsn> = log.lines().filter_map(parse_state_line).collect();
    convert_verifier_states(&parsed)
}
pub(crate) fn verifier_states_from_json(
    states: VerifierStatesJson,
) -> anyhow::Result<Vec<VerifierInsn>> {
    states
        .insns
        .into_iter()
        .map(|insn| {
            let regs = insn
                .regs
                .into_iter()
                .map(|(reg, state)| Ok((json_reg_name(&reg)?, json_reg_state(state)?)))
                .collect::<anyhow::Result<HashMap<_, _>>>()?;
            let stack = insn
                .stack
                .into_iter()
                .map(|(off, state)| Ok((json_stack_name(&off)?, json_stack_state(state)?)))
                .collect::<anyhow::Result<HashMap<_, _>>>()?;
            Ok(VerifierInsn {
                pc: insn.pc,
                frame: insn.frame,
                from_pc: None,
                kind: json_verifier_insn_kind(insn.kind.as_deref())?,
                speculative: false,
                regs,
                stack,
            })
        })
        .collect()
}
fn json_verifier_insn_kind(kind: Option<&str>) -> anyhow::Result<VerifierInsnKind> {
    match kind.unwrap_or("insn_delta_state") {
        "edge_full_state" => Ok(VerifierInsnKind::EdgeFullState),
        "pc_full_state" => Ok(VerifierInsnKind::PcFullState),
        "branch_delta_state" => Ok(VerifierInsnKind::BranchDeltaState),
        "insn_delta_state" => Ok(VerifierInsnKind::InsnDeltaState),
        other => anyhow::bail!("invalid verifier state kind: {other}"),
    }
}
fn json_reg_name(reg: &str) -> anyhow::Result<u8> {
    let stripped = reg
        .strip_prefix('r')
        .or_else(|| reg.strip_prefix('R'))
        .unwrap_or(reg);
    let value = stripped
        .parse::<u8>()
        .map_err(|err| anyhow::anyhow!("invalid register name {stripped}: {err}"))?;
    if value > 10 {
        anyhow::bail!("invalid BPF register r{value}");
    }
    Ok(value)
}
fn json_stack_name(off: &str) -> anyhow::Result<i16> {
    let stripped = off
        .strip_prefix("fp")
        .or_else(|| off.strip_prefix("FP"))
        .unwrap_or(off);
    let value = stripped
        .parse::<i16>()
        .map_err(|err| anyhow::anyhow!("invalid stack slot name {stripped}: {err}"))?;
    if value >= 0 || value % 8 != 0 {
        anyhow::bail!("invalid BPF stack slot fp{value}");
    }
    Ok(value)
}
fn json_stack_state(state: VerifierStackJson) -> anyhow::Result<StackState> {
    if let Some(slot_types) = &state.slot_types {
        if slot_types.is_empty()
            || slot_types.len() > 8
            || !slot_types
                .chars()
                .all(|ch| matches!(ch, '?' | 'r' | 'm' | '0' | 'd' | 'i' | 'f'))
        {
            anyhow::bail!("invalid verifier stack slot type string: {slot_types}");
        }
    }
    Ok(StackState {
        slot_types: state.slot_types,
        value: state.value.map(json_reg_state).transpose()?,
    })
}
fn json_reg_state(state: VerifierRegJson) -> anyhow::Result<RegState> {
    let tnum = state.tnum.as_deref().map(json_tnum).transpose()?;
    Ok(RegState {
        reg_type: state.reg_type,
        value_width: VerifierValueWidth::Unknown,
        precise: state.precise.unwrap_or(false),
        exact_value: state.const_val.map(|value| value as u64),
        tnum,
        range: ScalarRange {
            smin: state.min,
            smax: state.max,
            umin: state.min.and_then(|v| u64::try_from(v).ok()),
            umax: state.max.and_then(|v| u64::try_from(v).ok()),
            ..ScalarRange::default()
        },
        offset: state.offset,
        id: None,
    })
}
fn json_tnum(input: &str) -> anyhow::Result<Tnum> {
    let (value, mask) = input
        .split_once('/')
        .ok_or_else(|| anyhow::anyhow!("invalid tnum {input}: expected value/mask"))?;
    Ok(Tnum {
        value: json_u64_auto_radix(value)?,
        mask: json_u64_auto_radix(mask)?,
    })
}
fn json_u64_auto_radix(input: &str) -> anyhow::Result<u64> {
    let input = input.trim();
    if let Some(hex) = input.strip_prefix("0x") {
        Ok(u64::from_str_radix(hex, 16)?)
    } else {
        Ok(input.parse::<u64>()?)
    }
}
fn convert_verifier_states(states: &[VerifierInsn]) -> VerifierStatesJson {
    let insns = states
        .iter()
        .filter(|state| state.kind != VerifierInsnKind::BranchDeltaState)
        .filter_map(convert_verifier_state)
        .collect();
    VerifierStatesJson { insns }
}
fn convert_verifier_state(state: &VerifierInsn) -> Option<VerifierInsnJson> {
    let regs = state
        .regs
        .iter()
        .filter_map(|(&regno, reg)| convert_reg_state(reg).map(|reg| (format!("r{regno}"), reg)))
        .collect::<BTreeMap<_, _>>();
    let stack = state
        .stack
        .iter()
        .filter_map(|(&off, state)| {
            convert_stack_state(state).map(|state| (format!("fp{off}"), state))
        })
        .collect::<BTreeMap<_, _>>();
    (!regs.is_empty() || !stack.is_empty()).then_some(VerifierInsnJson {
        pc: state.pc,
        frame: state.frame,
        kind: verifier_insn_kind_json(state.kind),
        stack,
        regs,
    })
}
fn verifier_insn_kind_json(kind: VerifierInsnKind) -> Option<String> {
    match kind {
        VerifierInsnKind::InsnDeltaState => None,
        VerifierInsnKind::EdgeFullState => Some("edge_full_state".to_string()),
        VerifierInsnKind::PcFullState => Some("pc_full_state".to_string()),
        VerifierInsnKind::BranchDeltaState => Some("branch_delta_state".to_string()),
    }
}
fn convert_stack_state(state: &StackState) -> Option<VerifierStackJson> {
    let value = state.value.as_ref().and_then(convert_reg_state);
    (state.slot_types.is_some() || value.is_some()).then_some(VerifierStackJson {
        slot_types: state.slot_types.clone(),
        value,
    })
}
fn convert_reg_state(reg: &RegState) -> Option<VerifierRegJson> {
    let const_val = reg
        .exact_u64()
        .or_else(|| reg.exact_u32().map(u64::from))
        .map(|value| value as i64);
    let (min, max) = if let (Some(min), Some(max)) = (reg.range.umin, reg.range.umax) {
        if min <= i64::MAX as u64 && max <= i64::MAX as u64 {
            (Some(min as i64), Some(max as i64))
        } else {
            (reg.range.smin, reg.range.smax)
        }
    } else {
        (reg.range.smin, reg.range.smax)
    };
    let tnum = reg
        .tnum
        .map(|tnum| format!("0x{:x}/0x{:x}", tnum.value, tnum.mask));
    (reg.precise
        || reg.offset.is_some()
        || const_val.is_some()
        || min.is_some()
        || max.is_some()
        || tnum.is_some())
    .then_some(VerifierRegJson {
        reg_type: reg.reg_type.clone(),
        precise: Some(reg.precise),
        offset: reg.offset,
        const_val,
        min,
        max,
        tnum,
    })
}
fn parse_state_line(line: &str) -> Option<VerifierInsn> {
    let trimmed = line.trim();
    if trimmed.is_empty() {
        return None;
    }
    let (pc, from_pc, kind, speculative, state_text) =
        parse_from_state_line(trimmed).or_else(|| parse_pc_state_line(trimmed))?;
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
                state.value = Some(parse_reg_state(
                    tokens[idx + 1],
                    VerifierValueWidth::Unknown,
                ));
                idx += 1;
            }
            stack.insert(off, state);
            idx += 1;
            continue;
        }
        idx += 1;
    }
    if regs.is_empty() && stack.is_empty() {
        return None;
    }
    Some(VerifierInsn {
        pc,
        frame,
        from_pc,
        kind,
        speculative,
        regs,
        stack,
    })
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
    let (regno, value_width) = parse_reg_name(lhs)?;
    let state = parse_reg_state(rhs.trim(), value_width);
    Some((regno, state))
}
fn parse_stack_token(token: &str) -> Option<(i16, StackState)> {
    let (lhs, rhs) = token.split_once('=')?;
    let off = parse_i32(lhs.strip_prefix("fp")?)?.try_into().ok()?;
    let state = parse_stack_state(rhs.trim());
    Some((off, state))
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
fn parse_reg_state(raw: &str, value_width: VerifierValueWidth) -> RegState {
    let (precise, value) = match raw.strip_prefix('P') {
        Some(rest) => (true, rest),
        None => (false, raw),
    };
    if let Some(exact) = parse_scalar_exact_value(value) {
        let mut state = RegState::new("scalar", value_width);
        state.precise = precise;
        state.exact_value = Some(exact);
        apply_exact_value_to_range(&mut state.range, exact, value_width);
        return state;
    }
    if let Some(rest) = value.strip_prefix("fp") {
        let mut state = RegState::new("fp", value_width);
        state.precise = precise;
        if !rest.is_empty() {
            state.offset = parse_i32(rest);
        }
        return state;
    }
    if let Some(open) = value.find('(') {
        let close = match value.rfind(')') {
            Some(close) => close,
            None => value.len(),
        };
        let reg_type = normalize_reg_type(&value[..open]);
        let mut state = RegState::new(reg_type, value_width);
        state.precise = precise;
        parse_reg_attributes(&value[open + 1..close], &mut state);
        infer_exact_value(&mut state);
        return state;
    }
    let mut state = RegState::new(normalize_reg_type(value), value_width);
    state.precise = precise;
    state
}
fn normalize_reg_type(reg_type: &str) -> String {
    match reg_type {
        "inv" => "scalar".to_string(),
        other => other.to_string(),
    }
}
fn parse_stack_state(raw: &str) -> StackState {
    if raw.is_empty() {
        return StackState {
            slot_types: None,
            value: None,
        };
    }
    for split in raw.char_indices().skip(1).map(|(idx, _)| idx) {
        let prefix = &raw[..split];
        let rest = raw[split..].trim();
        if prefix.len() == 8
            && prefix.chars().all(is_stack_slot_type_char)
            && looks_like_reg_state(rest)
        {
            return StackState {
                slot_types: Some(prefix.to_string()),
                value: Some(parse_reg_state(rest, VerifierValueWidth::Unknown)),
            };
        }
    }
    if raw.len() == 8 && raw.chars().all(is_stack_slot_type_char) {
        return StackState {
            slot_types: Some(raw.to_string()),
            value: None,
        };
    }
    if looks_like_reg_state(raw) {
        return StackState {
            slot_types: None,
            value: Some(parse_reg_state(raw, VerifierValueWidth::Unknown)),
        };
    }
    if raw.chars().all(is_stack_slot_type_char) {
        return StackState {
            slot_types: Some(raw.to_string()),
            value: None,
        };
    }
    StackState {
        slot_types: None,
        value: Some(parse_reg_state(raw, VerifierValueWidth::Unknown)),
    }
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
        if parts.len() < 2 {
            continue;
        }
        let value = parts[parts.len() - 1];
        for key in &parts[..parts.len() - 1] {
            match *key {
                "smin" | "smin_value" => state.range.smin = parse_signed_value(value),
                "smax" | "smax_value" => state.range.smax = parse_signed_value(value),
                "umin" | "umin_value" => state.range.umin = parse_unsigned_value(value),
                "umax" | "umax_value" => state.range.umax = parse_unsigned_value(value),
                "smin32" | "smin32_value" => state.range.smin32 = parse_i32(value),
                "smax32" | "smax32_value" => state.range.smax32 = parse_i32(value),
                "umin32" | "umin32_value" => state.range.umin32 = parse_u32(value),
                "umax32" | "umax32_value" => state.range.umax32 = parse_u32(value),
                "off" => state.offset = parse_i32(value),
                "id" => state.id = parse_u32(value),
                "var_off" => state.tnum = parse_tnum(value),
                _ => {}
            }
        }
    }
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
