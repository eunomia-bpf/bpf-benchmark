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
//! Used by `bpf_prog_rejit()` to parse verifier diagnostics on REJIT failure,
//! providing structured error output in `cmd_apply` and `try_apply_one`.

use std::collections::HashMap;

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct VerifierInsn {
    pub pc: usize,
    pub regs: HashMap<u8, RegState>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct RegState {
    pub reg_type: String,
    pub min_value: Option<i64>,
    pub max_value: Option<i64>,
    pub known_value: Option<i64>,
    pub offset: Option<i32>,
}

impl RegState {
    fn new(reg_type: impl Into<String>) -> Self {
        Self {
            reg_type: reg_type.into(),
            min_value: None,
            max_value: None,
            known_value: None,
            offset: None,
        }
    }
}

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

    let (pc, state_text) =
        parse_from_state_line(trimmed).or_else(|| parse_pc_state_line(trimmed))?;

    let mut regs = HashMap::new();
    for token in split_top_level_tokens(state_text) {
        if let Some((regno, state)) = parse_reg_token(token) {
            regs.insert(regno, state);
        }
    }

    if regs.is_empty() {
        return None;
    }

    Some(VerifierInsn { pc, regs })
}

fn parse_from_state_line(line: &str) -> Option<(usize, &str)> {
    let rest = line.strip_prefix("from ")?;
    let (_, rest) = rest.split_once(" to ")?;

    let digits_len = rest.chars().take_while(|ch| ch.is_ascii_digit()).count();
    if digits_len == 0 {
        return None;
    }

    let pc = rest[..digits_len].parse().ok()?;
    let mut tail = &rest[digits_len..];
    if let Some(stripped) = tail.strip_prefix(" (speculative execution)") {
        tail = stripped;
    }

    let state_text = tail.strip_prefix(':')?.trim();
    is_state_text(state_text).then_some((pc, state_text))
}

fn parse_pc_state_line(line: &str) -> Option<(usize, &str)> {
    let colon = line.find(':')?;
    let pc = line[..colon].trim().parse().ok()?;
    let tail = line[colon + 1..].trim();
    if tail.is_empty() {
        return None;
    }

    if is_state_text(tail) {
        return Some((pc, tail));
    }

    let semicolon = find_top_level_char(tail, ';')?;
    let state_text = tail[semicolon + 1..].trim();
    is_state_text(state_text).then_some((pc, state_text))
}

fn is_state_text(text: &str) -> bool {
    text.starts_with('R') || text.starts_with("frame")
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
    let regno = parse_reg_name(lhs)?;
    let state = parse_reg_state(rhs.trim());
    Some((regno, state))
}

fn parse_reg_name(name: &str) -> Option<u8> {
    let name = name.strip_prefix('R')?;
    let name = name.strip_suffix("_w").unwrap_or(name);
    name.parse().ok()
}

fn parse_reg_state(raw: &str) -> RegState {
    let value = raw.strip_prefix('P').unwrap_or(raw);

    if let Some(known) = parse_signed_value(value) {
        let mut state = RegState::new("scalar");
        state.known_value = Some(known);
        state.min_value = Some(known);
        state.max_value = Some(known);
        return state;
    }

    if let Some(rest) = value.strip_prefix("fp") {
        let mut state = RegState::new("fp");
        if !rest.is_empty() {
            state.offset = parse_i32(rest);
        }
        return state;
    }

    if let Some(open) = value.find('(') {
        let close = value.rfind(')').unwrap_or(value.len());
        let reg_type = normalize_reg_type(&value[..open]);
        let mut state = RegState::new(reg_type);
        parse_reg_attributes(&value[open + 1..close], &mut state);
        if state.known_value.is_none() && state.reg_type == "scalar" {
            if let (Some(min), Some(max)) = (state.min_value, state.max_value) {
                if min == max {
                    state.known_value = Some(min);
                }
            }
        }
        return state;
    }

    RegState::new(normalize_reg_type(value))
}

fn normalize_reg_type(reg_type: &str) -> String {
    match reg_type {
        "inv" => "scalar".to_string(),
        other => other.to_string(),
    }
}

fn parse_reg_attributes(attrs: &str, state: &mut RegState) {
    let mut smin = None;
    let mut smax = None;
    let mut umin = None;
    let mut umax = None;
    let mut smin32 = None;
    let mut smax32 = None;
    let mut umin32 = None;
    let mut umax32 = None;

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
                "smin" | "smin_value" => smin = parse_signed_value(value),
                "smax" | "smax_value" => smax = parse_signed_value(value),
                "umin" | "umin_value" => umin = parse_unsigned_value(value),
                "umax" | "umax_value" => umax = parse_unsigned_value(value),
                "smin32" | "smin32_value" => smin32 = parse_signed_value(value),
                "smax32" | "smax32_value" => smax32 = parse_signed_value(value),
                "umin32" | "umin32_value" => umin32 = parse_unsigned_value(value),
                "umax32" | "umax32_value" => umax32 = parse_unsigned_value(value),
                "off" => state.offset = parse_i32(value),
                _ => {}
            }
        }
    }

    state.min_value = smin.or(umin).or(smin32).or(umin32);
    state.max_value = smax.or(umax).or(smax32).or(umax32);
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

fn parse_signed_value(text: &str) -> Option<i64> {
    let value = text.trim();
    if value.is_empty() {
        return None;
    }

    if let Some(rest) = value
        .strip_prefix("-0x")
        .or_else(|| value.strip_prefix("-0X"))
    {
        let magnitude = u64::from_str_radix(rest, 16).ok()? as i128;
        return i64::try_from(-magnitude).ok();
    }

    if let Some(rest) = value
        .strip_prefix("+0x")
        .or_else(|| value.strip_prefix("+0X"))
    {
        let magnitude = u64::from_str_radix(rest, 16).ok()?;
        return Some(magnitude as i64);
    }

    if let Some(rest) = value
        .strip_prefix("0x")
        .or_else(|| value.strip_prefix("0X"))
    {
        let magnitude = u64::from_str_radix(rest, 16).ok()?;
        return Some(magnitude as i64);
    }

    value.parse().ok()
}

fn parse_unsigned_value(text: &str) -> Option<i64> {
    let value = text.trim();
    if value.is_empty() || value.starts_with('-') {
        return None;
    }

    let unsigned = if let Some(rest) = value.strip_prefix('+') {
        parse_unsigned_u64(rest)?
    } else {
        parse_unsigned_u64(value)?
    };

    i64::try_from(unsigned).ok()
}

fn parse_unsigned_u64(text: &str) -> Option<u64> {
    if let Some(rest) = text.strip_prefix("0x").or_else(|| text.strip_prefix("0X")) {
        return u64::from_str_radix(rest, 16).ok();
    }

    text.parse().ok()
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
        assert_eq!(insns[0].regs.get(&1).unwrap().reg_type, "ctx");
        assert_eq!(insns[0].regs.get(&0).unwrap().reg_type, "pkt");
        assert_eq!(insns[0].regs.get(&0).unwrap().offset, Some(8));
        assert_eq!(insns[0].regs.get(&10).unwrap().reg_type, "fp");
        assert_eq!(insns[0].regs.get(&10).unwrap().offset, Some(0));

        assert_eq!(insns[2].pc, 6);
        let r3_after_load = insns[2].regs.get(&3).unwrap();
        assert_eq!(r3_after_load.reg_type, "scalar");
        assert_eq!(r3_after_load.min_value, None);
        assert_eq!(r3_after_load.max_value, Some(255));
        assert_eq!(r3_after_load.known_value, None);

        assert_eq!(insns[3].pc, 7);
        let r3_before_branch = insns[3].regs.get(&3).unwrap();
        assert_eq!(r3_before_branch.min_value, Some(0));
        assert_eq!(r3_before_branch.max_value, Some(255));

        assert_eq!(insns[4].pc, 10);
        let r1 = insns[4].regs.get(&1).unwrap();
        assert_eq!(r1.reg_type, "map_value");
        assert_eq!(r1.offset, Some(1));

        let r2 = insns[4].regs.get(&2).unwrap();
        assert_eq!(r2.reg_type, "scalar");
        assert_eq!(r2.known_value, Some(1));
        assert_eq!(r2.min_value, Some(1));
        assert_eq!(r2.max_value, Some(1));
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
        assert_eq!(range.reg_type, "scalar");
        assert_eq!(range.min_value, Some(0));
        assert_eq!(range.max_value, Some(1));
        assert_eq!(range.known_value, None);

        let zero = insns[2].regs.get(&0).unwrap();
        assert_eq!(zero.known_value, Some(0));

        let one = insns[3].regs.get(&0).unwrap();
        assert_eq!(one.known_value, Some(1));
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
