// SPDX-License-Identifier: MIT
// Constant propagation and branch folding.

use std::collections::{BTreeMap, HashSet};

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::pass::*;

const REG_COUNT: usize = 11;

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
struct RegConstFact {
    exact64: Option<u64>,
    exact32: Option<u32>,
}

impl RegConstFact {
    const fn unknown() -> Self {
        Self {
            exact64: None,
            exact32: None,
        }
    }
}

type RegConstState = [RegConstFact; REG_COUNT];

#[derive(Default)]
struct VerifierExactConstOracle {
    facts: BTreeMap<(usize, u8), RegConstFact>,
}

#[derive(Clone, Copy, Debug, Default)]
struct OracleExactAccumulator {
    saw_observation: bool,
    exact64: Consensus<u64>,
    exact32: Consensus<u32>,
}

#[derive(Clone, Copy, Debug)]
enum Consensus<T> {
    Unseen,
    Exact(T),
    Conflict,
}

impl<T> Default for Consensus<T> {
    fn default() -> Self {
        Self::Unseen
    }
}

impl<T: Copy + Eq> Consensus<T> {
    fn observe(&mut self, value: T) {
        *self = match *self {
            Self::Unseen => Self::Exact(value),
            Self::Exact(current) if current == value => Self::Exact(current),
            Self::Exact(_) | Self::Conflict => Self::Conflict,
        };
    }

    fn invalidate(&mut self) {
        *self = Self::Conflict;
    }

    fn into_option(self) -> Option<T> {
        match self {
            Self::Exact(value) => Some(value),
            Self::Unseen | Self::Conflict => None,
        }
    }
}

impl OracleExactAccumulator {
    fn observe(&mut self, reg: &crate::pass::RegState) {
        self.saw_observation = true;

        if reg.reg_type != "scalar" {
            self.exact64.invalidate();
            self.exact32.invalidate();
            return;
        }

        match (reg.exact_u64(), reg.exact_u32()) {
            (Some(exact64), Some(exact32)) => {
                self.exact64.observe(exact64);
                self.exact32.observe(exact32);
            }
            (Some(_), None) => {
                self.exact64.invalidate();
                self.exact32.invalidate();
            }
            (None, Some(exact32)) => {
                self.exact64.invalidate();
                self.exact32.observe(exact32);
            }
            (None, None) => {
                self.exact64.invalidate();
                self.exact32.invalidate();
            }
        }
    }

    fn into_fact(self) -> Option<RegConstFact> {
        if !self.saw_observation {
            return None;
        }

        let fact = RegConstFact {
            exact64: self.exact64.into_option(),
            exact32: self.exact32.into_option(),
        };
        (fact.exact64.is_some() || fact.exact32.is_some()).then_some(fact)
    }
}

impl VerifierExactConstOracle {
    fn from_states(states: &[VerifierInsn]) -> Self {
        let mut accumulators: BTreeMap<(usize, u8), OracleExactAccumulator> = BTreeMap::new();

        for state in states {
            if state.kind != VerifierInsnKind::InsnDeltaState {
                continue;
            }

            for (&regno, reg_state) in &state.regs {
                accumulators
                    .entry((state.pc, regno))
                    .or_default()
                    .observe(reg_state);
            }
        }

        let facts = accumulators
            .into_iter()
            .filter_map(|(key, acc)| acc.into_fact().map(|fact| (key, fact)))
            .collect();

        Self { facts }
    }

    fn fact(&self, pc: usize, reg: u8) -> Option<RegConstFact> {
        self.facts.get(&(pc, reg)).copied()
    }

    fn exact_for_instruction(&self, pc: usize, reg: u8, is_32: bool) -> Option<u64> {
        let fact = self.fact(pc, reg)?;
        if is_32 {
            fact.exact32.map(u64::from)
        } else {
            fact.exact64
        }
    }

    fn apply_post_state(&self, pc: usize, state: &mut RegConstState) {
        for reg in 0..REG_COUNT {
            if let Some(fact) = self.fact(pc, reg as u8) {
                set_reg_fact(state, reg as u8, fact);
            }
        }
    }
}

/// Fold exact register constants into MOV32/MOV64/LD_IMM64/JA/NOP.
pub struct ConstPropPass;

impl BpfPass for ConstPropPass {
    fn name(&self) -> &str {
        "const_prop"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let cfg = analyses.get(&CFGAnalysis, program);
        if cfg.blocks.is_empty() {
            return Ok(PassResult::unchanged(self.name()));
        }

        let oracle = VerifierExactConstOracle::from_states(program.verifier_states.as_ref());
        let block_in = solve_block_entry_states(program, &cfg, &oracle);
        let mut replacements = BTreeMap::new();
        let protected_prefix_end = super::utils::tail_call_protected_prefix_end(&program.insns);
        let mut nop_pcs = HashSet::new();

        for (block_idx, block) in cfg.blocks.iter().enumerate() {
            simulate_block(
                &program.insns,
                block.start,
                block.end,
                block_in[block_idx],
                &oracle,
                Some(&mut replacements),
            );
        }

        if let Some(prefix_end) = protected_prefix_end {
            replacements.retain(|&pc, replacement| {
                tail_safe_const_prop_replacement(&program.insns, pc, replacement, prefix_end)
            });
        }

        for (&pc, replacement) in &replacements {
            if replacement.len() == 1 && replacement[0] == BpfInsn::nop() {
                nop_pcs.insert(pc);
            }
        }

        if replacements.is_empty() {
            return Ok(PassResult::unchanged(self.name()));
        }

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len + replacements.len());
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            addr_map[pc] = new_insns.len();
            let width = insn_width(&program.insns[pc]);

            if let Some(replacement) = replacements.get(&pc) {
                new_insns.extend_from_slice(replacement);
                pc += width;
                continue;
            }

            let insn = program.insns[pc];
            new_insns.push(insn);
            if width == 2 && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map);
        fixup_folded_jumps(&mut new_insns, &program.insns, &addr_map, &replacements);
        for old_pc in nop_pcs {
            let new_pc = addr_map[old_pc];
            if new_pc < new_insns.len() {
                new_insns[new_pc] = BpfInsn::nop();
            }
        }

        let mut final_insns = new_insns;
        let mut final_addr_map = addr_map;
        let cleanup_cfg = CFGAnalysis.run(&BpfProgram::new(final_insns.clone()));
        if let Some((cleaned_insns, cleanup_map)) =
            super::utils::eliminate_unreachable_blocks_with_cfg(&final_insns, &cleanup_cfg)
        {
            final_addr_map = super::utils::compose_addr_maps(&final_addr_map, &cleanup_map);
            final_insns = cleaned_insns;
        }

        program.insns = final_insns;
        super::utils::remap_btf_metadata(program, &final_addr_map)?;
        program.remap_annotations(&final_addr_map);
        program.log_transform(TransformEntry {
            sites_applied: replacements.len(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: replacements.len(),
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn solve_block_entry_states(
    program: &BpfProgram,
    cfg: &crate::analysis::CFGResult,
    oracle: &VerifierExactConstOracle,
) -> Vec<RegConstState> {
    let mut block_in = vec![unknown_state(); cfg.blocks.len()];
    let mut block_out = vec![unknown_state(); cfg.blocks.len()];
    let mut changed = true;

    while changed {
        changed = false;

        for (block_idx, block) in cfg.blocks.iter().enumerate() {
            let in_state = merge_predecessor_states(&block.preds, &block_out);
            let out_state = simulate_block(
                &program.insns,
                block.start,
                block.end,
                in_state,
                oracle,
                None,
            );

            if block_in[block_idx] != in_state || block_out[block_idx] != out_state {
                block_in[block_idx] = in_state;
                block_out[block_idx] = out_state;
                changed = true;
            }
        }
    }

    block_in
}

fn merge_predecessor_states(preds: &[usize], block_out: &[RegConstState]) -> RegConstState {
    let Some((&first, rest)) = preds.split_first() else {
        return unknown_state();
    };

    let mut merged = block_out[first];
    for &pred in rest {
        merged = meet_states(&merged, &block_out[pred]);
    }
    merged
}

fn simulate_block(
    insns: &[BpfInsn],
    start: usize,
    end: usize,
    mut state: RegConstState,
    oracle: &VerifierExactConstOracle,
    mut replacements: Option<&mut BTreeMap<usize, Vec<BpfInsn>>>,
) -> RegConstState {
    let mut pc = start;
    while pc < end {
        let (next_state, replacement) = analyze_instruction(insns, pc, &state, oracle);
        if let (Some(map), Some(replacement)) = (replacements.as_deref_mut(), replacement) {
            map.insert(pc, replacement);
        }
        state = next_state;
        pc += insn_width(&insns[pc]);
    }
    state
}

fn analyze_instruction(
    insns: &[BpfInsn],
    pc: usize,
    state: &RegConstState,
    oracle: &VerifierExactConstOracle,
) -> (RegConstState, Option<Vec<BpfInsn>>) {
    let insn = &insns[pc];
    let mut next = *state;
    let replacement = match insn.class() {
        BPF_LD => {
            if insn.is_ldimm64() {
                if insn.src_reg() == 0 {
                    let value = decode_ldimm64(insns, pc);
                    set_reg_exact64(&mut next, insn.dst_reg(), value);
                } else {
                    /* Pseudo-imm forms like MAP_FD/MAP_VALUE carry verifier-visible
                     * type via src_reg. Treat them as non-foldable so const_prop
                     * never re-emits them as plain scalar LD_IMM64.
                     */
                    set_reg_unknown(&mut next, insn.dst_reg());
                }
            } else {
                set_reg_unknown(&mut next, insn.dst_reg());
            }
            None
        }
        BPF_LDX => {
            set_reg_unknown(&mut next, insn.dst_reg());
            None
        }
        BPF_ALU | BPF_ALU64 => {
            let replacement = fold_alu_instruction(insns, pc, state, oracle);
            let result = evaluate_alu_result(insn, state);
            match result {
                Some(value) => set_reg_exact64(&mut next, insn.dst_reg(), value),
                None => set_reg_unknown(&mut next, insn.dst_reg()),
            }
            replacement
        }
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                for reg in 0..=5 {
                    set_reg_unknown(&mut next, reg as u8);
                }
                None
            } else if insn.is_cond_jmp() {
                fold_jump_instruction(insns, pc, state)
            } else {
                None
            }
        }
        _ => None,
    };

    oracle.apply_post_state(pc, &mut next);
    (next, replacement)
}

fn fold_alu_instruction(
    insns: &[BpfInsn],
    pc: usize,
    state: &RegConstState,
    oracle: &VerifierExactConstOracle,
) -> Option<Vec<BpfInsn>> {
    let insn = &insns[pc];
    let result = oracle
        .exact_for_instruction(pc, insn.dst_reg(), insn.class() == BPF_ALU)
        .or_else(|| evaluate_alu_result(insn, state))?;

    let op = bpf_op(insn.code);
    let candidate = match op {
        BPF_MOV if bpf_src(insn.code) == BPF_K => return None,
        _ => emit_constant_load(insn.dst_reg(), result, insn.class() == BPF_ALU),
    };

    replacement_if_changed(insns, pc, &candidate)
}

fn fold_jump_instruction(
    insns: &[BpfInsn],
    pc: usize,
    state: &RegConstState,
) -> Option<Vec<BpfInsn>> {
    let insn = &insns[pc];
    let taken = evaluate_jump_condition(insn, state)?;
    let candidate = if taken {
        vec![BpfInsn::ja(insn.off)]
    } else {
        vec![BpfInsn::nop()]
    };
    replacement_if_changed(insns, pc, &candidate)
}

fn evaluate_alu_result(insn: &BpfInsn, state: &RegConstState) -> Option<u64> {
    let is_32 = insn.class() == BPF_ALU;
    let op = bpf_op(insn.code);

    if op == BPF_MOV {
        return if bpf_src(insn.code) == BPF_X {
            reg_const(state, insn.src_reg(), is_32).map(|value| normalize_alu_result(is_32, value))
        } else {
            Some(alu_imm_operand(insn))
        };
    }

    let dst = reg_const(state, insn.dst_reg(), is_32)?;

    if op == BPF_NEG {
        return eval_unary_alu(op, dst, is_32);
    }

    let rhs = if bpf_src(insn.code) == BPF_X {
        reg_const(state, insn.src_reg(), is_32)?
    } else {
        alu_imm_operand(insn)
    };

    eval_binary_alu(op, dst, rhs, is_32)
}

fn evaluate_jump_condition(insn: &BpfInsn, state: &RegConstState) -> Option<bool> {
    let is_32 = insn.class() == BPF_JMP32;
    let lhs = reg_const(state, insn.dst_reg(), is_32)?;
    let rhs = if bpf_src(insn.code) == BPF_X {
        reg_const(state, insn.src_reg(), is_32)?
    } else {
        jump_imm_operand(insn)
    };

    let lhs_u = normalize_jump_operand(lhs, is_32);
    let rhs_u = normalize_jump_operand(rhs, is_32);
    let lhs_s = normalize_signed_jump_operand(lhs, is_32);
    let rhs_s = normalize_signed_jump_operand(rhs, is_32);

    Some(match bpf_op(insn.code) {
        BPF_JEQ => lhs_u == rhs_u,
        BPF_JNE => lhs_u != rhs_u,
        BPF_JGT => lhs_u > rhs_u,
        BPF_JGE => lhs_u >= rhs_u,
        BPF_JLT => lhs_u < rhs_u,
        BPF_JLE => lhs_u <= rhs_u,
        BPF_JSGT => lhs_s > rhs_s,
        BPF_JSGE => lhs_s >= rhs_s,
        BPF_JSLT => lhs_s < rhs_s,
        BPF_JSLE => lhs_s <= rhs_s,
        BPF_JSET => (lhs_u & rhs_u) != 0,
        _ => return None,
    })
}

fn eval_unary_alu(op: u8, lhs: u64, is_32: bool) -> Option<u64> {
    match (op, is_32) {
        (BPF_NEG, true) => Some((-(lhs as u32 as i32) as u32) as u64),
        (BPF_NEG, false) => Some((-(lhs as i64)) as u64),
        _ => None,
    }
}

fn eval_binary_alu(op: u8, lhs: u64, rhs: u64, is_32: bool) -> Option<u64> {
    if is_32 {
        let lhs = lhs as u32;
        let rhs = rhs as u32;
        let result = match op {
            BPF_ADD => lhs.wrapping_add(rhs),
            BPF_SUB => lhs.wrapping_sub(rhs),
            BPF_MUL => lhs.wrapping_mul(rhs),
            BPF_DIV => {
                if rhs == 0 {
                    return None;
                }
                lhs / rhs
            }
            BPF_MOD => {
                if rhs == 0 {
                    return None;
                }
                lhs % rhs
            }
            BPF_OR => lhs | rhs,
            BPF_AND => lhs & rhs,
            BPF_XOR => lhs ^ rhs,
            BPF_LSH => (rhs < 32).then_some(lhs.wrapping_shl(rhs))?,
            BPF_RSH => (rhs < 32).then_some(lhs.wrapping_shr(rhs))?,
            BPF_ARSH => {
                let lhs = lhs as i32;
                (rhs < 32).then_some((lhs >> rhs) as u32)?
            }
            _ => return None,
        };
        return Some(result as u64);
    }

    let result = match op {
        BPF_ADD => lhs.wrapping_add(rhs),
        BPF_SUB => lhs.wrapping_sub(rhs),
        BPF_MUL => lhs.wrapping_mul(rhs),
        BPF_DIV => {
            if rhs == 0 {
                return None;
            }
            lhs / rhs
        }
        BPF_MOD => {
            if rhs == 0 {
                return None;
            }
            lhs % rhs
        }
        BPF_OR => lhs | rhs,
        BPF_AND => lhs & rhs,
        BPF_XOR => lhs ^ rhs,
        BPF_LSH => (rhs < 64).then_some(lhs.wrapping_shl(rhs as u32))?,
        BPF_RSH => (rhs < 64).then_some(lhs.wrapping_shr(rhs as u32))?,
        BPF_ARSH => {
            let lhs = lhs as i64;
            (rhs < 64).then_some((lhs >> rhs) as u64)?
        }
        _ => return None,
    };
    Some(result)
}

fn normalize_alu_result(is_32: bool, value: u64) -> u64 {
    if is_32 {
        value as u32 as u64
    } else {
        value
    }
}

fn normalize_jump_operand(value: u64, is_32: bool) -> u64 {
    if is_32 {
        value as u32 as u64
    } else {
        value
    }
}

fn normalize_signed_jump_operand(value: u64, is_32: bool) -> i64 {
    if is_32 {
        (value as u32 as i32) as i64
    } else {
        value as i64
    }
}

fn alu_imm_operand(insn: &BpfInsn) -> u64 {
    if insn.class() == BPF_ALU {
        insn.imm as u32 as u64
    } else {
        insn.imm as i64 as u64
    }
}

fn jump_imm_operand(insn: &BpfInsn) -> u64 {
    if insn.class() == BPF_JMP32 {
        insn.imm as u32 as u64
    } else {
        insn.imm as i64 as u64
    }
}

fn reg_const(state: &RegConstState, reg: u8, is_32: bool) -> Option<u64> {
    let fact = *state.get(reg as usize)?;
    if is_32 {
        fact.exact32.map(u64::from)
    } else {
        fact.exact64
    }
}

fn set_reg_fact(state: &mut RegConstState, reg: u8, fact: RegConstFact) {
    if let Some(slot) = state.get_mut(reg as usize) {
        *slot = fact;
    }
}

fn set_reg_exact64(state: &mut RegConstState, reg: u8, value: u64) {
    set_reg_fact(
        state,
        reg,
        RegConstFact {
            exact64: Some(value),
            exact32: Some(value as u32),
        },
    );
}

fn set_reg_unknown(state: &mut RegConstState, reg: u8) {
    set_reg_fact(state, reg, RegConstFact::unknown());
}

fn merge_reg_fact(lhs: RegConstFact, rhs: RegConstFact) -> RegConstFact {
    RegConstFact {
        exact64: match (lhs.exact64, rhs.exact64) {
            (Some(left), Some(right)) if left == right => Some(left),
            _ => None,
        },
        exact32: match (lhs.exact32, rhs.exact32) {
            (Some(left), Some(right)) if left == right => Some(left),
            _ => None,
        },
    }
}

fn meet_states(lhs: &RegConstState, rhs: &RegConstState) -> RegConstState {
    let mut merged = unknown_state();
    for reg in 0..REG_COUNT {
        merged[reg] = merge_reg_fact(lhs[reg], rhs[reg]);
    }
    merged
}

fn unknown_state() -> RegConstState {
    [RegConstFact::unknown(); REG_COUNT]
}

fn emit_constant_load(dst_reg: u8, value: u64, is_32: bool) -> Vec<BpfInsn> {
    if is_32 {
        return vec![BpfInsn::mov32_imm(dst_reg, value as u32 as i32)];
    }

    if let Some(imm) = as_mov64_imm(value) {
        vec![BpfInsn::mov64_imm(dst_reg, imm)]
    } else {
        emit_ldimm64(dst_reg, value)
    }
}

fn as_mov64_imm(value: u64) -> Option<i32> {
    let imm = value as i64 as i32;
    ((imm as i64) as u64 == value).then_some(imm)
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

fn decode_ldimm64(insns: &[BpfInsn], pc: usize) -> u64 {
    let lo = insns[pc].imm as u32 as u64;
    let hi = insns
        .get(pc + 1)
        .map(|insn| insn.imm as u32 as u64)
        .unwrap_or(0);
    lo | (hi << 32)
}

fn replacement_if_changed(
    insns: &[BpfInsn],
    pc: usize,
    candidate: &[BpfInsn],
) -> Option<Vec<BpfInsn>> {
    let width = insn_width(&insns[pc]);
    let original = &insns[pc..pc + width];
    (original != candidate).then(|| candidate.to_vec())
}

fn tail_safe_const_prop_replacement(
    insns: &[BpfInsn],
    pc: usize,
    replacement: &[BpfInsn],
    protected_prefix_end: usize,
) -> bool {
    let old_insn = &insns[pc];
    if old_insn.is_cond_jmp() {
        return false;
    }
    if pc >= protected_prefix_end {
        return true;
    }

    replacement.len() == insn_width(old_insn)
        && !replacement.iter().any(|insn| insn.is_ja() && insn.off == 0)
}

fn fixup_folded_jumps(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
    replacements: &BTreeMap<usize, Vec<BpfInsn>>,
) {
    for (&old_pc, replacement) in replacements {
        let old_insn = &old_insns[old_pc];
        if !old_insn.is_cond_jmp() {
            continue;
        }

        let Some(new_branch) = replacement.first() else {
            continue;
        };
        if !new_branch.is_ja() || new_branch.off == 0 {
            continue;
        }

        let old_target = old_pc as i64 + 1 + old_insn.off as i64;
        if !(0..=old_insns.len() as i64).contains(&old_target) {
            continue;
        }

        let new_pc = addr_map[old_pc];
        if new_pc >= new_insns.len() || !new_insns[new_pc].is_ja() {
            continue;
        }

        let new_target = addr_map[old_target as usize];
        let new_off = new_target as i64 - (new_pc as i64 + 1);
        if let Ok(new_off) = i16::try_from(new_off) {
            new_insns[new_pc].off = new_off;
        }
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;

    use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
    use crate::bpf::{install_mock_map, use_mock_maps, BpfMapInfo, MockMapState};
    use crate::passes::{DcePass, MapInlinePass};

    const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn jeq32_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP32 | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_JNE | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn ld_imm64(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, src),
                0,
                imm_lo,
            ),
            BpfInsn::new(0, 0, 0, imm_hi),
        ]
    }

    fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
        BpfInsn::new(
            BPF_ST | size | BPF_MEM,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
        BpfInsn::new(
            BPF_ALU64 | BPF_ADD | BPF_K,
            BpfInsn::make_regs(dst, 0),
            0,
            imm,
        )
    }

    fn call_helper(imm: i32) -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, imm)
    }

    fn scalar_reg(value: u64) -> RegState {
        RegState {
            reg_type: "scalar".to_string(),
            value_width: VerifierValueWidth::Bits64,
            precise: true,
            exact_value: Some(value),
            tnum: Some(Tnum { value, mask: 0 }),
            range: ScalarRange {
                smin: Some(value as i64),
                smax: Some(value as i64),
                umin: Some(value),
                umax: Some(value),
                smin32: Some(value as u32 as i32),
                smax32: Some(value as u32 as i32),
                umin32: Some(value as u32),
                umax32: Some(value as u32),
            },
            offset: None,
            id: None,
        }
    }

    fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
        VerifierInsn {
            pc,
            frame: 0,
            from_pc: None,
            kind: VerifierInsnKind::InsnDeltaState,
            speculative: false,
            regs,
            stack: HashMap::new(),
        }
    }

    fn install_array_map(map_id: u32, value: Vec<u8>) {
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), value.clone());

        let info = BpfMapInfo {
            map_type: 2,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
        };

        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen: true,
                values,
            },
        );
    }

    fn run_const_prop_pass(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(ConstPropPass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    fn run_const_prop_then_dce(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(ConstPropPass);
        pm.add_pass(DcePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    #[test]
    fn const_prop_folds_alu_chain_to_constant_mov() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 4),
            BpfInsn::mov64_imm(2, 8),
            BpfInsn::alu64_reg(BPF_ADD, 1, 2),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 4),
                BpfInsn::mov64_imm(2, 8),
                BpfInsn::mov64_imm(1, 12),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_folds_alu32_chain_to_mov32_imm() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, -1),
            BpfInsn::new(BPF_ALU | BPF_ADD | BPF_K, BpfInsn::make_regs(1, 0), 0, 1),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, -1),
                BpfInsn::mov32_imm(1, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_tracks_ldimm64_constants() {
        let wide = ld_imm64(1, 0, 0, 1);
        let mut program = BpfProgram::new(vec![wide[0], wide[1], add64_imm(1, 1), exit_insn()]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(program.insns.len(), 5);
        assert!(program.insns[2].is_ldimm64());
        assert_eq!(program.insns[2].dst_reg(), 1);
        assert_eq!(program.insns[2].imm as u32 as u64, 1);
        assert_eq!(program.insns[3].imm as u32 as u64, 1);
        assert_eq!(program.insns[4], exit_insn());
    }

    #[test]
    fn const_prop_does_not_fold_typed_ldimm64_map_value() {
        let typed = ld_imm64(1, 2, 0x11, 0x1a8);
        let original = vec![typed[0], typed[1], add64_imm(1, 16), exit_insn()];
        let mut program = BpfProgram::new(original.clone());

        let result = run_const_prop_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(result.total_sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_folds_constant_branches_to_ja_and_nop() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7),
            jeq_imm(1, 7, 1),
            BpfInsn::mov64_imm(2, 0),
            BpfInsn::mov64_imm(3, 9),
            jeq_imm(3, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 7),
                BpfInsn::ja(0),
                BpfInsn::mov64_imm(3, 9),
                BpfInsn::nop(),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_uses_verifier_exact_constants_after_helper_calls() {
        let mut program = BpfProgram::new(vec![
            call_helper(7),
            jeq_imm(0, 1, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_verifier_states(vec![
            verifier_delta_state(0, HashMap::from([(0, scalar_reg(1))])),
            verifier_delta_state(1, HashMap::from([(0, scalar_reg(1))])),
            verifier_delta_state(2, HashMap::from([(0, scalar_reg(0))])),
            verifier_delta_state(3, HashMap::from([(0, scalar_reg(1))])),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                call_helper(7),
                BpfInsn::ja(0),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_folds_branch_after_map_inline() {
        install_array_map(201, vec![7, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42, 0);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(1),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            jeq_imm(6, 7, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_map_ids(vec![201]);

        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(CFGAnalysis);
        pm.register_analysis(MapInfoAnalysis);
        pm.add_pass(MapInlinePass);
        pm.add_pass(ConstPropPass);

        use_mock_maps(&mut program);
        let result = pm.run(&mut program, &PassContext::test_default()).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].pass_name, "map_inline");
        assert_eq!(result.pass_results[1].pass_name, "const_prop");
        assert_eq!(result.pass_results[1].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov32_imm(6, 7),
                BpfInsn::ja(0),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_removes_dead_target_after_false_branch_fold() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 1),
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 1),
                BpfInsn::nop(),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_skips_tail_sensitive_branch_folding_but_keeps_safe_alu_fold() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7),
            jeq_imm(1, 7, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(2, 5),
            add64_imm(2, 2),
            call_helper(12),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 7),
                jeq_imm(1, 7, 1),
                BpfInsn::mov64_imm(0, 0),
                BpfInsn::mov64_imm(2, 5),
                BpfInsn::mov64_imm(2, 7),
                call_helper(12),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_fixups_folded_jump_after_ldimm64_growth() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(2, 7),
            jeq_imm(2, 7, 2),
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 40),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![BpfInsn::mov64_imm(2, 7), BpfInsn::ja(0), exit_insn(),]
        );
    }

    #[test]
    fn fixup_folded_jumps_remaps_backward_jump_after_growth() {
        let old_insns = vec![BpfInsn::mov64_imm(2, 1), jne_imm(1, 0, -2), exit_insn()];
        let wide = ld_imm64(2, 0, 1, 1);
        let mut new_insns = vec![wide[0], wide[1], BpfInsn::ja(-2), exit_insn()];
        let addr_map = vec![0, 2, 3, 4];
        let replacements = BTreeMap::from([(1usize, vec![BpfInsn::ja(-2)])]);

        fixup_folded_jumps(&mut new_insns, &old_insns, &addr_map, &replacements);

        assert_eq!(new_insns[2], BpfInsn::ja(-3));
        assert_eq!(2isize + 1 + new_insns[2].off as isize, 0);
    }

    #[test]
    fn const_prop_folds_jmp32_branch_and_fixups_target_after_growth() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, -1),
            jeq32_imm(1, -1, 2),
            BpfInsn::mov64_imm(2, 1),
            BpfInsn::alu64_imm(BPF_LSH, 2, 40),
            exit_insn(),
        ]);

        let result = run_const_prop_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![BpfInsn::mov64_imm(1, -1), BpfInsn::ja(0), exit_insn(),]
        );
    }

    #[test]
    fn fixup_folded_jumps_remaps_jump_to_end_sentinel() {
        let old_insns = vec![jeq_imm(1, 7, 2), BpfInsn::mov64_imm(2, 1), exit_insn()];
        let wide = ld_imm64(2, 0, 1, 1);
        let mut new_insns = vec![BpfInsn::ja(2), wide[0], wide[1], exit_insn()];
        let addr_map = vec![0, 1, 3, 4];
        let replacements = BTreeMap::from([(0usize, vec![BpfInsn::ja(2)])]);

        fixup_folded_jumps(&mut new_insns, &old_insns, &addr_map, &replacements);

        assert_eq!(new_insns[0], BpfInsn::ja(3));
        assert_eq!(1 + new_insns[0].off as usize, 4);
    }

    #[test]
    fn const_prop_then_dce_handles_folded_jump_after_dead_block_growth() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7),
            jeq_imm(1, 7, 2),
            BpfInsn::mov64_imm(2, 1),
            BpfInsn::alu64_imm(BPF_LSH, 2, 40),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let result = run_const_prop_then_dce(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].pass_name, "const_prop");
        assert_eq!(result.pass_results[1].pass_name, "dce");
        assert!(result.pass_results[0].changed);
        assert!(result.pass_results[1].changed);
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
    }

    #[test]
    fn eval_binary_alu_rejects_zero_divisor_without_panicking() {
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, true), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, true), None);
    }
}
