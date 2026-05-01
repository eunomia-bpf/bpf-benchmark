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

use std::collections::HashMap;

use crate::{
    RegState, ScalarRange, StackState, Tnum, VerifierInsn, VerifierInsnKind, VerifierValueWidth,
};

pub fn parse_verifier_log(log: &str) -> Vec<VerifierInsn> {
    log.lines().filter_map(parse_state_line).collect()
}

/// Extract the PC of the verifier failure from a REJIT error message.
///
/// Heuristics (in priority order):
/// 1. Look for error lines like `R2 type=scalar expected=packet_ptr` at the end
///    — they follow a state snapshot whose PC is the failure point.
/// 2. Look for lines with `invalid` or `type=` that aren't state lines — extract
///    the PC from the preceding state line.
/// 3. Fall back to the last PC seen in any state snapshot (the verifier typically
///    reports the state just before the error).
///
/// Returns `None` if no meaningful PC can be extracted.
#[cfg(test)]
pub fn extract_failure_pc(verifier_log: &str) -> Option<usize> {
    let lines: Vec<&str> = verifier_log.lines().collect();
    if lines.is_empty() {
        return None;
    }

    // Strategy 1: Look for common verifier error patterns and take the PC from
    // the preceding state line.
    let error_patterns = [
        "invalid",
        "type=",
        "expected",
        "not allowed",
        "permission denied",
        "R0 !read_ok",
        "unreachable",
        "back-edge",
        "loop detected",
        "BPF_EXIT without",
        "jump out of range",
        "misaligned",
    ];

    let mut last_state_pc: Option<usize> = None;
    for line in &lines {
        let trimmed = line.trim();
        // Try to parse as a state line to track the latest PC.
        if let Some(vi) = parse_state_line(trimmed) {
            last_state_pc = Some(vi.pc);
            continue;
        }
        // Check if this is an error line.
        let lower = trimmed.to_lowercase();
        if error_patterns.iter().any(|pat| lower.contains(pat)) {
            // If we have a preceding state PC, that's our failure point.
            if let Some(pc) = last_state_pc {
                return Some(pc);
            }
        }
    }

    // Strategy 2: Return the last state PC seen (the verifier typically emits
    // the failing state last before the error summary).
    last_state_pc
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
    let from_pc = parse_optional(from_text.trim())?;

    let digits_len = rest.chars().take_while(|ch| ch.is_ascii_digit()).count();
    if digits_len == 0 {
        return None;
    }

    let pc = parse_optional(&rest[..digits_len])?;
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
    let pc = parse_optional(line[..colon].trim())?;
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
    let kind = if is_conditional_branch_text(insn_text) {
        VerifierInsnKind::BranchDeltaState
    } else {
        VerifierInsnKind::InsnDeltaState
    };
    is_state_text(state_text).then_some((pc, None, kind, false, state_text))
}

fn is_state_text(text: &str) -> bool {
    text.starts_with('R') || text.starts_with("frame")
}

fn is_conditional_branch_text(text: &str) -> bool {
    text.contains(" if ") && text.contains(" goto ")
}

fn strip_frame_prefix(text: &str) -> (usize, &str) {
    let Some(rest) = text.strip_prefix("frame") else {
        return (0, text);
    };

    let digits_len = rest.chars().take_while(|ch| ch.is_ascii_digit()).count();
    if digits_len == 0 {
        return (0, text);
    }

    let frame = parse_optional(&rest[..digits_len]);
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
    let off = parse_stack_name(lhs)?;
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
    Some((parse_optional(name)?, value_width))
}

fn parse_stack_name(name: &str) -> Option<i16> {
    let name = name.strip_prefix("fp")?;
    result_to_option(parse_i32(name)?.try_into())
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
        let close = value.rfind(')').unwrap_or(value.len());
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
                "smin32" | "smin32_value" => state.range.smin32 = parse_signed_i32(value),
                "smax32" | "smax32_value" => state.range.smax32 = parse_signed_i32(value),
                "umin32" | "umin32_value" => state.range.umin32 = parse_unsigned_u32(value),
                "umax32" | "umax32_value" => state.range.umax32 = parse_unsigned_u32(value),
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
    result_to_option(parse_signed_value(text)?.try_into())
}

fn parse_u32(text: &str) -> Option<u32> {
    result_to_option(parse_unsigned_u64(text)?.try_into())
}

fn parse_signed_i32(text: &str) -> Option<i32> {
    result_to_option(parse_signed_value(text)?.try_into())
}

fn parse_unsigned_u32(text: &str) -> Option<u32> {
    result_to_option(parse_unsigned_u64(text)?.try_into())
}

fn parse_optional<T: std::str::FromStr>(text: &str) -> Option<T> {
    let Ok(value) = text.parse() else {
        return None;
    };
    Some(value)
}

fn result_to_option<T, E>(result: Result<T, E>) -> Option<T> {
    let Ok(value) = result else {
        return None;
    };
    Some(value)
}

fn parse_hex_u64(text: &str) -> Option<u64> {
    let Ok(value) = u64::from_str_radix(text, 16) else {
        return None;
    };
    Some(value)
}

fn parse_signed_value(text: &str) -> Option<i64> {
    let value = text.trim();
    if value.is_empty() {
        return None;
    }

    if let Some(rest) = value
        .strip_prefix("-0x")
        .or_else(|| value.strip_prefix("-0X"))
    {
        let magnitude = parse_hex_u64(rest)? as i128;
        return result_to_option(i64::try_from(-magnitude));
    }

    if let Some(rest) = value
        .strip_prefix("+0x")
        .or_else(|| value.strip_prefix("+0X"))
    {
        let magnitude = parse_hex_u64(rest)?;
        return Some(magnitude as i64);
    }

    if let Some(rest) = value
        .strip_prefix("0x")
        .or_else(|| value.strip_prefix("0X"))
    {
        let magnitude = parse_hex_u64(rest)?;
        return Some(magnitude as i64);
    }

    parse_optional(value)
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

    parse_optional(text)
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
        let magnitude = parse_optional(rest)?;
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
mod tests {
    use super::*;

    #[test]
    fn parses_real_style_branch_and_insn_states() {
        let log = r#"
from 4 to 6: R0_w=pkt(off=8,r=8) R1=ctx() R2_w=pkt(r=8) R3_w=pkt_end() R10=fp0
6: R0_w=pkt(off=8,r=8) R1=ctx() R2_w=pkt(r=8) R3_w=pkt_end() R10=fp0
6: (71) r3 = *(u8 *)(r2 +0)           ; R2_w=pkt(r=8) R3_w=scalar(umax=255,var_off=(0x0; 0xff))
7: (15) if r3 == 0x0 goto pc+1        ; R3=scalar(smin=umin=smin32=umin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))
10: R1=map_value(map=.data.two_byte_,ks=4,vs=2,off=1) R2=1 R10=fp0 fp-8=0000???? refs=2 cb
"#;

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 5);

        assert_eq!(insns[0].pc, 6);
        assert_eq!(insns[0].from_pc, Some(4));
        assert_eq!(insns[0].kind, VerifierInsnKind::EdgeFullState);
        assert_eq!(insns[0].frame, 0);
        assert_eq!(insns[0].regs.get(&1).unwrap().reg_type, "ctx");
        assert_eq!(insns[0].regs.get(&0).unwrap().reg_type, "pkt");
        assert_eq!(insns[0].regs.get(&0).unwrap().offset, Some(8));
        assert_eq!(insns[0].regs.get(&10).unwrap().reg_type, "fp");
        assert_eq!(insns[0].regs.get(&10).unwrap().offset, Some(0));

        assert_eq!(insns[2].pc, 6);
        let r3_after_load = insns[2].regs.get(&3).unwrap();
        assert_eq!(r3_after_load.reg_type, "scalar");
        assert_eq!(insns[2].kind, VerifierInsnKind::InsnDeltaState);
        assert_eq!(r3_after_load.value_width, VerifierValueWidth::Bits32);
        assert_eq!(r3_after_load.range.umax, Some(255));
        assert_eq!(
            r3_after_load.tnum,
            Some(Tnum {
                value: 0,
                mask: 0xff
            })
        );
        assert_eq!(r3_after_load.exact_value, None);

        assert_eq!(insns[3].pc, 7);
        assert_eq!(insns[3].kind, VerifierInsnKind::BranchDeltaState);
        let r3_before_branch = insns[3].regs.get(&3).unwrap();
        assert_eq!(r3_before_branch.range.umin, Some(0));
        assert_eq!(r3_before_branch.range.umax, Some(255));

        assert_eq!(insns[4].pc, 10);
        let r1 = insns[4].regs.get(&1).unwrap();
        assert_eq!(r1.reg_type, "map_value");
        assert_eq!(r1.offset, Some(1));

        let r2 = insns[4].regs.get(&2).unwrap();
        assert_eq!(r2.reg_type, "scalar");
        assert_eq!(r2.exact_u64(), Some(1));
        assert_eq!(r2.range.umin, Some(1));
        assert_eq!(r2.range.umax, Some(1));

        let fp8 = insns[4].stack.get(&-8).unwrap();
        assert_eq!(fp8.slot_types.as_deref(), Some("0000????"));
        assert!(fp8.value.is_none());
    }

    #[test]
    fn parses_constants_and_repeated_bounds_from_real_messages() {
        let log = r#"
0: R1=ctx() R10=fp0
2: (25) if r0 > 0x1 goto pc+1         ; R0=scalar(smin=smin32=0,smax=umax=smax32=umax32=1,var_off=(0x0; 0x1))
4: (b7) r0 = 0                        ; R0=0
5: (b7) r0 = 1                        ; R0=1
"#;

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 4);

        assert_eq!(insns[0].regs.get(&1).unwrap().reg_type, "ctx");
        assert_eq!(insns[0].regs.get(&10).unwrap().offset, Some(0));

        let range = insns[1].regs.get(&0).unwrap();
        assert_eq!(insns[1].kind, VerifierInsnKind::BranchDeltaState);
        assert_eq!(range.reg_type, "scalar");
        assert_eq!(range.range.smin, Some(0));
        assert_eq!(range.range.umax, Some(1));
        assert_eq!(range.exact_value, None);

        let zero = insns[2].regs.get(&0).unwrap();
        assert_eq!(zero.exact_u64(), Some(0));

        let one = insns[3].regs.get(&0).unwrap();
        assert_eq!(one.exact_u64(), Some(1));
    }

    #[test]
    fn parses_speculative_full_state_and_stack_spill() {
        let log = r#"
from 12 to 18 (speculative execution): frame1: R2_w=42 R10=fp0 fp-24=0000???? scalar(id=7,var_off=(0x2a; 0x0))
"#;

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 1);

        let insn = &insns[0];
        assert_eq!(insn.kind, VerifierInsnKind::EdgeFullState);
        assert!(insn.speculative);
        assert_eq!(insn.frame, 1);

        let reg = insn.regs.get(&2).unwrap();
        assert_eq!(reg.value_width, VerifierValueWidth::Bits32);
        assert_eq!(reg.exact_u32(), Some(42));
        assert_eq!(reg.exact_u64(), None);

        let spill = insn.stack.get(&-24).unwrap();
        assert_eq!(spill.slot_types.as_deref(), Some("0000????"));
        let spilled_value = spill.value.as_ref().unwrap();
        assert_eq!(spilled_value.reg_type, "scalar");
        assert_eq!(spilled_value.id, Some(7));
        assert_eq!(
            spilled_value.tnum,
            Some(Tnum {
                value: 0x2a,
                mask: 0
            })
        );
        assert_eq!(spilled_value.exact_u64(), Some(42));
    }

    #[test]
    fn distinguishes_exact_64bit_and_32bit_scalars() {
        let log = r#"
0: (b7) r3 = 42                       ; R3=42
1: (b4) w4 = 42                       ; R4_w=42
"#;

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 2);

        let r3 = insns[0].regs.get(&3).unwrap();
        assert_eq!(r3.value_width, VerifierValueWidth::Bits64);
        assert_eq!(r3.exact_u64(), Some(42));
        assert_eq!(r3.exact_u32(), Some(42));

        let r4 = insns[1].regs.get(&4).unwrap();
        assert_eq!(r4.value_width, VerifierValueWidth::Bits32);
        assert_eq!(r4.exact_u64(), None);
        assert_eq!(r4.exact_u32(), Some(42));
    }

    #[test]
    fn truncated_log_tail_does_not_drop_complete_states() {
        let log = "\
0: R1=ctx() R10=fp0
1: (b7) r0 = 0                        ; R0=0
2: (07) r0 += 1                       ; R0=scalar(var_off=(0x1;
";

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 3);
        assert_eq!(insns[0].pc, 0);
        assert_eq!(insns[1].regs.get(&0).unwrap().exact_u64(), Some(0));
        assert_eq!(insns[2].pc, 2);
        assert_eq!(insns[2].regs.get(&0).unwrap().reg_type, "scalar");
        assert_eq!(insns[2].regs.get(&0).unwrap().exact_u64(), None);
    }

    #[test]
    fn ignores_non_state_lines() {
        let log = r#"
0: (b7) r0 = 0
1: safe
from 2 to 7: safe
processed 4 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
"#;

        assert!(parse_verifier_log(log).is_empty());
    }

    /// Simulate parsing a verifier rejection log embedded in a REJIT error.
    /// This tests the integration path: bpf_prog_rejit() captures the log,
    /// and the caller parses it with parse_verifier_log().
    #[test]
    fn parse_verifier_rejection_from_rejit_error() {
        // Simulate an error message like bpf_prog_rejit() would produce.
        let error_msg = "BPF_PROG_REJIT: Permission denied (os error 13)\n\
                         verifier log:\n\
                         0: R1=ctx() R10=fp0\n\
                         0: (b7) r0 = 0                        ; R0=0\n\
                         1: (95) exit\n\
                         processed 2 insns (limit 1000000)";

        // Extract the log portion (same logic as cmd_apply/try_apply_one).
        let log_text = if let Some(log_start) = error_msg.find("verifier log:\n") {
            &error_msg[log_start + "verifier log:\n".len()..]
        } else {
            ""
        };

        let parsed = parse_verifier_log(log_text);
        assert!(
            !parsed.is_empty(),
            "should parse at least one state from rejection log"
        );
        // First state snapshot is at pc=0.
        assert_eq!(parsed[0].pc, 0);
        assert!(parsed[0].regs.contains_key(&1));
        assert_eq!(parsed[0].regs.get(&1).unwrap().reg_type, "ctx");
    }

    #[test]
    fn parses_frame_and_stack_tokens() {
        let log = r#"
3: frame1: R1=ctx() R2=fp-24 R10=fp0 fp-24=scalar(id=1) fp-32=0000???? fp-40=fp-56
"#;

        let insns = parse_verifier_log(log);
        assert_eq!(insns.len(), 1);
        let insn = &insns[0];
        assert_eq!(insn.pc, 3);
        assert_eq!(insn.frame, 1);
        assert_eq!(insn.regs.get(&2).unwrap().reg_type, "fp");
        assert_eq!(insn.regs.get(&2).unwrap().offset, Some(-24));

        let fp24 = insn.stack.get(&-24).unwrap();
        assert_eq!(fp24.slot_types, None);
        assert_eq!(fp24.value.as_ref().unwrap().reg_type, "scalar");

        let fp32 = insn.stack.get(&-32).unwrap();
        assert_eq!(fp32.slot_types.as_deref(), Some("0000????"));
        assert!(fp32.value.is_none());

        let fp40 = insn.stack.get(&-40).unwrap();
        assert_eq!(fp40.value.as_ref().unwrap().reg_type, "fp");
        assert_eq!(fp40.value.as_ref().unwrap().offset, Some(-56));
    }

    // ── extract_failure_pc tests ──────────────────────────────────

    #[test]
    fn extract_failure_pc_from_type_mismatch() {
        // The verifier typically emits the state snapshot, then a separate error line.
        let log = "\
0: R1=ctx() R10=fp0
0: (b7) r0 = 0                        ; R0=0
5: R0=pkt(off=8,r=8) R1=ctx() R2=pkt(r=8)
5: (71) r3 = *(u8 *)(r2 +0)           ; R2=pkt(r=8) R3=scalar(umax=255)
R2 type=scalar expected=pkt_ptr
";
        let pc = extract_failure_pc(log);
        assert_eq!(
            pc,
            Some(5),
            "should return the PC of the last state before the error line"
        );
    }

    #[test]
    fn extract_failure_pc_from_invalid_insn() {
        let log = "\
0: R1=ctx() R10=fp0
3: R0=scalar R1=ctx()
3: (85) call bpf_rotate64#12345 ; R1=scalar
invalid func bpf_rotate64#12345
";
        let pc = extract_failure_pc(log);
        assert_eq!(pc, Some(3));
    }

    #[test]
    fn extract_failure_pc_last_state_fallback() {
        // No error keyword, just state lines — should return the last PC.
        let log = "\
0: R1=ctx() R10=fp0
4: R0=scalar R1=ctx()
10: R0=0 R10=fp0
";
        let pc = extract_failure_pc(log);
        assert_eq!(pc, Some(10));
    }

    #[test]
    fn extract_failure_pc_empty_log() {
        assert_eq!(extract_failure_pc(""), None);
        assert_eq!(extract_failure_pc("processed 2 insns"), None);
    }

    #[test]
    fn extract_failure_pc_jump_out_of_range() {
        let log = "\
0: R1=ctx() R10=fp0
2: R0=scalar
jump out of range from insn 2 to 99
";
        let pc = extract_failure_pc(log);
        assert_eq!(pc, Some(2));
    }
}
