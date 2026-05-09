// SPDX-License-Identifier: MIT
// Constant propagation and ALU materialization.

use std::collections::{BTreeMap, BTreeSet};

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_ldimm64, fixup_all_branches, insn_width};

const REG_COUNT: usize = 11;
const VERIFIER_POST_STATE_NOT_SCALAR_EXACT: &str = "verifier post-state is not scalar-exact";

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
    facts: BTreeMap<(usize, usize, u8), RegConstFact>,
    scalar_post_states: BTreeMap<(usize, usize, u8), VerifierScalarExactPostState>,
    frames_by_pc: BTreeMap<usize, BTreeSet<usize>>,
}

#[derive(Clone, Copy, Debug, Default)]
struct OracleExactAccumulator {
    saw_observation: bool,
    exact64: Consensus<u64>,
    exact32: Consensus<u32>,
    scalar_post_state: Consensus<VerifierScalarExactPostState>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct VerifierScalarExactPostState {
    value: u64,
    width: VerifierValueWidth,
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
            self.scalar_post_state.invalidate();
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

        match scalar_exact_post_state(reg) {
            Some(state) => self.scalar_post_state.observe(state),
            None => self.scalar_post_state.invalidate(),
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

    fn into_scalar_post_state(self) -> Option<VerifierScalarExactPostState> {
        if !self.saw_observation {
            return None;
        }

        self.scalar_post_state.into_option()
    }
}

impl VerifierExactConstOracle {
    fn from_states(states: &[VerifierInsn]) -> Self {
        let mut frames_by_pc: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();
        let mut visit_counts: BTreeMap<(usize, usize), usize> = BTreeMap::new();
        let mut observed_counts: BTreeMap<(usize, usize, u8), usize> = BTreeMap::new();
        let mut accumulators: BTreeMap<(usize, usize, u8), OracleExactAccumulator> =
            BTreeMap::new();

        for state in states {
            if state.kind == VerifierInsnKind::BranchDeltaState {
                continue;
            }

            frames_by_pc
                .entry(state.pc)
                .or_default()
                .insert(state.frame);
            *visit_counts.entry((state.pc, state.frame)).or_default() += 1;

            for (&regno, reg_state) in &state.regs {
                let key = (state.pc, state.frame, regno);
                *observed_counts.entry(key).or_default() += 1;
                accumulators.entry(key).or_default().observe(reg_state);
            }
        }

        let mut facts = BTreeMap::new();
        let mut scalar_post_states = BTreeMap::new();
        for (key, acc) in accumulators {
            let (pc, frame, _) = key;
            let visits = visit_counts.get(&(pc, frame)).copied().unwrap_or(0);
            let observations = observed_counts.get(&key).copied().unwrap_or(0);
            if observations != visits {
                continue;
            }
            if let Some(fact) = acc.into_fact() {
                facts.insert(key, fact);
            }
            if let Some(state) = acc.into_scalar_post_state() {
                scalar_post_states.insert(key, state);
            }
        }

        Self {
            facts,
            scalar_post_states,
            frames_by_pc,
        }
    }

    fn fact(&self, pc: usize, frame: Option<usize>, reg: u8) -> Option<RegConstFact> {
        match frame {
            Some(frame) => self.facts.get(&(pc, frame, reg)).copied(),
            None => self.frame_invariant_fact(pc, reg),
        }
    }

    fn frame_invariant_fact(&self, pc: usize, reg: u8) -> Option<RegConstFact> {
        let frames = self.frames_by_pc.get(&pc)?;
        let mut exact64 = Consensus::Unseen;
        let mut exact32 = Consensus::Unseen;
        let mut saw_frame = false;

        for &frame in frames {
            let fact = self.facts.get(&(pc, frame, reg)).copied()?;
            saw_frame = true;
            observe_optional(&mut exact64, fact.exact64);
            observe_optional(&mut exact32, fact.exact32);
        }

        let fact = RegConstFact {
            exact64: exact64.into_option(),
            exact32: exact32.into_option(),
        };
        (saw_frame && (fact.exact64.is_some() || fact.exact32.is_some())).then_some(fact)
    }

    fn exact_for_instruction(
        &self,
        pc: usize,
        frame: Option<usize>,
        reg: u8,
        is_32: bool,
    ) -> Option<u64> {
        let fact = self.fact(pc, frame, reg)?;
        if is_32 {
            fact.exact32.map(u64::from)
        } else {
            fact.exact64
        }
    }

    fn post_state_proves_scalar_exact(
        &self,
        pc: usize,
        frame: usize,
        dst: u8,
        value: i64,
        width: VerifierValueWidth,
    ) -> bool {
        self.scalar_post_states
            .get(&(pc, frame, dst))
            .is_some_and(|state| state.matches(value, width))
    }

    fn post_state_proves_scalar_exact_in_context(
        &self,
        pc: usize,
        frame: Option<usize>,
        dst: u8,
        value: i64,
        width: VerifierValueWidth,
    ) -> bool {
        match frame {
            Some(frame) => self.post_state_proves_scalar_exact(pc, frame, dst, value, width),
            None => self
                .frames_by_pc
                .get(&pc)
                .filter(|frames| !frames.is_empty())
                .is_some_and(|frames| {
                    frames.iter().all(|&frame| {
                        self.post_state_proves_scalar_exact(pc, frame, dst, value, width)
                    })
                }),
        }
    }

    fn apply_post_state(&self, pc: usize, frame: Option<usize>, state: &mut RegConstState) {
        for reg in 0..REG_COUNT {
            if let Some(fact) = self.fact(pc, frame, reg as u8) {
                set_reg_fact(state, reg as u8, fact);
            }
        }
    }
}

impl VerifierScalarExactPostState {
    fn matches(self, value: i64, width: VerifierValueWidth) -> bool {
        let expected = match width {
            VerifierValueWidth::Bits32 => value as u32 as u64,
            VerifierValueWidth::Bits64 => value as u64,
            VerifierValueWidth::Unknown => return false,
        };

        self.value == expected && verifier_width_matches(self.width, width)
    }
}

fn scalar_exact_post_state(reg: &crate::pass::RegState) -> Option<VerifierScalarExactPostState> {
    if reg.reg_type != "scalar" {
        return None;
    }

    let (value, width) = match reg.value_width {
        VerifierValueWidth::Bits32 => (u64::from(reg.exact_u32()?), VerifierValueWidth::Bits32),
        VerifierValueWidth::Bits64 => (reg.exact_u64()?, VerifierValueWidth::Bits64),
        VerifierValueWidth::Unknown => {
            let value = reg.exact_u64().or_else(|| reg.exact_u32().map(u64::from))?;
            (value, VerifierValueWidth::Unknown)
        }
    };

    Some(VerifierScalarExactPostState { value, width })
}

fn verifier_width_matches(observed: VerifierValueWidth, required: VerifierValueWidth) -> bool {
    observed == required || observed == VerifierValueWidth::Unknown
}

fn observe_optional<T: Copy + Eq>(consensus: &mut Consensus<T>, value: Option<T>) {
    match value {
        Some(value) => consensus.observe(value),
        None => consensus.invalidate(),
    }
}

#[derive(Default)]
struct ConstPropRewritePlan {
    replacements: BTreeMap<usize, Vec<BpfInsn>>,
    sites_skipped: Vec<SkipReason>,
}

enum AluFoldDecision {
    Replace(Vec<BpfInsn>),
    Skip(SkipReason),
    None,
}

/// Fold exact register constants into MOV32/MOV64/LD_IMM64.
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
        let mut rewrite_plan = ConstPropRewritePlan::default();

        for (block_idx, block) in cfg.blocks.iter().enumerate() {
            simulate_block(
                &program.insns,
                block.start,
                block.end,
                block_in[block_idx],
                &oracle,
                Some(&mut rewrite_plan),
            );
        }

        if rewrite_plan.replacements.is_empty() {
            if rewrite_plan.sites_skipped.is_empty() {
                return Ok(PassResult::unchanged(self.name()));
            }

            return Ok(PassResult {
                pass_name: self.name().into(),
                sites_skipped: rewrite_plan.sites_skipped,
                diagnostics: vec!["const_prop_alu_materialized=0".to_string()],
                ..Default::default()
            });
        }

        let mut alu_materialized = 0usize;
        for &pc in rewrite_plan.replacements.keys() {
            let insn = &program.insns[pc];
            if matches!(insn.class(), BPF_ALU | BPF_ALU64) {
                alu_materialized += 1;
            }
        }

        let sites_applied = rewrite_plan.replacements.len();
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len + sites_applied);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            addr_map[pc] = new_insns.len();
            let width = insn_width(&program.insns[pc]);

            if let Some(replacement) = rewrite_plan.replacements.get(&pc) {
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

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        super::utils::remap_btf_metadata(program, &addr_map)?;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied,
            sites_skipped: rewrite_plan.sites_skipped,
            diagnostics: vec![format!("const_prop_alu_materialized={alu_materialized}")],
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
    let mut updated = true;

    while updated {
        updated = false;

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
                updated = true;
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
    mut rewrite_plan: Option<&mut ConstPropRewritePlan>,
) -> RegConstState {
    let collect_rewrites = rewrite_plan.is_some();
    let mut pc = start;
    while pc < end {
        let (next_state, decision) =
            analyze_instruction(insns, pc, None, &state, oracle, collect_rewrites);
        if let Some(plan) = rewrite_plan.as_mut() {
            let plan = &mut **plan;
            match decision {
                AluFoldDecision::Replace(replacement) => {
                    plan.replacements.insert(pc, replacement);
                }
                AluFoldDecision::Skip(skip) => plan.sites_skipped.push(skip),
                AluFoldDecision::None => {}
            }
        }
        state = next_state;
        pc += insn_width(&insns[pc]);
    }
    state
}

fn analyze_instruction(
    insns: &[BpfInsn],
    pc: usize,
    frame: Option<usize>,
    state: &RegConstState,
    oracle: &VerifierExactConstOracle,
    collect_rewrites: bool,
) -> (RegConstState, AluFoldDecision) {
    let insn = &insns[pc];
    let mut next = *state;
    let decision = match insn.class() {
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
            AluFoldDecision::None
        }
        BPF_LDX => {
            set_reg_unknown(&mut next, insn.dst_reg());
            AluFoldDecision::None
        }
        BPF_ALU | BPF_ALU64 => {
            let decision = if collect_rewrites {
                fold_alu_instruction(insns, pc, frame, state, oracle)
            } else {
                AluFoldDecision::None
            };
            let result = evaluate_alu_result(insn, state);
            match result {
                Some(value) => set_reg_exact64(&mut next, insn.dst_reg(), value),
                None => set_reg_unknown(&mut next, insn.dst_reg()),
            }
            decision
        }
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                for reg in 0..=5 {
                    set_reg_unknown(&mut next, reg as u8);
                }
            }
            AluFoldDecision::None
        }
        _ => AluFoldDecision::None,
    };

    if can_apply_oracle_post_state(insn) {
        oracle.apply_post_state(pc, frame, &mut next);
    }
    (next, decision)
}

fn can_apply_oracle_post_state(insn: &BpfInsn) -> bool {
    !insn.is_call() && !is_reg_to_reg_mov(insn)
}

fn fold_alu_instruction(
    insns: &[BpfInsn],
    pc: usize,
    frame: Option<usize>,
    state: &RegConstState,
    oracle: &VerifierExactConstOracle,
) -> AluFoldDecision {
    let insn = &insns[pc];
    if bpf_op(insn.code) == BPF_MOV && bpf_src(insn.code) == BPF_K {
        return AluFoldDecision::None;
    }

    let is_32 = insn.class() == BPF_ALU;
    let result = evaluate_alu_result(insn, state).or_else(|| {
        oracle_materializes_alu_result(insn)
            .then(|| oracle.exact_for_instruction(pc, frame, insn.dst_reg(), is_32))
            .flatten()
    });
    let Some(result) = result else {
        return AluFoldDecision::None;
    };

    let candidate = emit_constant_load(insn.dst_reg(), result, is_32);
    if replacement_if_changed(insns, pc, &candidate).is_none() {
        return AluFoldDecision::None;
    }

    let width = if is_32 {
        VerifierValueWidth::Bits32
    } else {
        VerifierValueWidth::Bits64
    };
    if !oracle.post_state_proves_scalar_exact_in_context(
        pc,
        frame,
        insn.dst_reg(),
        result as i64,
        width,
    ) {
        return AluFoldDecision::Skip(SkipReason {
            pc,
            reason: VERIFIER_POST_STATE_NOT_SCALAR_EXACT.to_string(),
        });
    }

    AluFoldDecision::Replace(candidate)
}

fn oracle_materializes_alu_result(insn: &BpfInsn) -> bool {
    !is_reg_to_reg_mov(insn)
}

fn is_reg_to_reg_mov(insn: &BpfInsn) -> bool {
    matches!(insn.class(), BPF_ALU | BPF_ALU64)
        && bpf_op(insn.code) == BPF_MOV
        && bpf_src(insn.code) == BPF_X
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

fn alu_imm_operand(insn: &BpfInsn) -> u64 {
    if insn.class() == BPF_ALU {
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

fn decode_ldimm64(insns: &[BpfInsn], pc: usize) -> u64 {
    let lo = insns[pc].imm as u32 as u64;
    let hi = insns[pc + 1].imm as u32 as u64;
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

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
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
        scalar_reg_with_width(value, VerifierValueWidth::Bits64)
    }

    fn scalar_reg_with_width(value: u64, value_width: VerifierValueWidth) -> RegState {
        RegState {
            reg_type: "scalar".to_string(),
            value_width,
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

    fn pkt_reg() -> RegState {
        RegState::new("pkt", VerifierValueWidth::Bits64)
    }

    fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
        verifier_delta_state_in_frame(pc, 0, regs)
    }

    fn verifier_delta_state_in_frame(
        pc: usize,
        frame: usize,
        regs: HashMap<u8, RegState>,
    ) -> VerifierInsn {
        verifier_state_in_frame(pc, frame, VerifierInsnKind::InsnDeltaState, regs)
    }

    fn verifier_state_in_frame(
        pc: usize,
        frame: usize,
        kind: VerifierInsnKind,
        regs: HashMap<u8, RegState>,
    ) -> VerifierInsn {
        VerifierInsn {
            pc,
            frame,
            from_pc: None,
            kind,
            speculative: false,
            regs,
            stack: HashMap::new(),
        }
    }

    fn run_const_prop_pass(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(ConstPropPass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    fn diagnostic_counter(pass: &PassResult, key: &str) -> usize {
        let prefix = format!("{key}=");
        pass.diagnostics
            .iter()
            .find_map(|diag| diag.strip_prefix(&prefix))
            .unwrap_or_else(|| panic!("missing diagnostic counter {key}"))
            .parse()
            .unwrap_or_else(|err| panic!("invalid diagnostic counter {key}: {err}"))
    }

    #[test]
    fn const_prop_folds_alu_chain_to_constant_mov() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 4),
            BpfInsn::mov64_imm(2, 8),
            BpfInsn::alu64_reg(BPF_ADD, 1, 2),
            exit_insn(),
        ]);
        program.set_verifier_states(vec![verifier_delta_state(
            2,
            HashMap::from([(1, scalar_reg(12))]),
        )]);

        let result = run_const_prop_pass(&mut program);
        let pass = &result.pass_results[0];
        assert_eq!(diagnostic_counter(pass, "const_prop_alu_materialized"), 1);
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
        program.set_verifier_states(vec![verifier_delta_state(
            1,
            HashMap::from([(1, scalar_reg_with_width(0, VerifierValueWidth::Bits32))]),
        )]);

        let _result = run_const_prop_pass(&mut program);
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
        program.set_verifier_states(vec![verifier_delta_state(
            2,
            HashMap::from([(1, scalar_reg(0x1_0000_0001))]),
        )]);

        let _result = run_const_prop_pass(&mut program);
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

        let _result = run_const_prop_pass(&mut program);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_uses_verifier_exact_constants_for_alu_after_helper_calls() {
        let mut program = BpfProgram::new(vec![call_helper(7), add64_imm(0, 1), exit_insn()]);
        program.set_verifier_states(vec![verifier_delta_state(
            1,
            HashMap::from([(0, scalar_reg(42))]),
        )]);

        let _result = run_const_prop_pass(&mut program);
        assert_eq!(
            program.insns,
            vec![call_helper(7), BpfInsn::mov64_imm(0, 42), exit_insn(),]
        );
    }

    #[test]
    fn const_prop_does_not_seed_caller_saved_regs_from_call_post_state() {
        // Bug caught: a call-pc verifier post-state for R0-R5 must not repopulate
        // caller-saved regs after call handling cleared them in the abstract model.
        let original = vec![call_helper(7), add64_imm(0, 1), exit_insn()];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![verifier_delta_state(
            0,
            HashMap::from([(0, scalar_reg(41))]),
        )]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_does_not_use_oracle_for_register_mov_provenance() {
        // Bug caught: a verifier pre-state exact value for MOV X's destination
        // must not replace a register copy that may transfer pointer provenance.
        let original = vec![BpfInsn::mov64_reg(2, 3), add64_imm(2, 1), exit_insn()];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![verifier_state_in_frame(
            0,
            0,
            VerifierInsnKind::PcFullState,
            HashMap::from([(2, scalar_reg(16))]),
        )]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_post_state_guard_rejects_packet_pointer_copy_materialization() {
        // Bug caught: local numeric state must not turn a provenance-carrying packet
        // pointer copy into a scalar immediate before a later packet memory access.
        let original = vec![
            BpfInsn::mov64_imm(1, 62),
            BpfInsn::mov64_reg(7, 1),
            BpfInsn::ldx_mem(BPF_B, 2, 7, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![verifier_delta_state(
            1,
            HashMap::from([(7, pkt_reg())]),
        )]);

        let result = run_const_prop_pass(&mut program);
        let pass = &result.pass_results[0];
        assert_eq!(pass.sites_applied, 0);
        assert_eq!(pass.sites_skipped.len(), 1);
        assert_eq!(pass.sites_skipped[0].pc, 1);
        assert_eq!(
            pass.sites_skipped[0].reason,
            VERIFIER_POST_STATE_NOT_SCALAR_EXACT
        );
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_post_state_guard_allows_scalar_exact_register_copy() {
        // Bug caught: the verifier guard should preserve useful scalar MOV X
        // materialization when the post-state proves the destination is scalar exact.
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 62),
            BpfInsn::mov64_reg(7, 1),
            exit_insn(),
        ]);
        program.set_verifier_states(vec![verifier_delta_state(
            1,
            HashMap::from([(7, scalar_reg(62))]),
        )]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 62),
                BpfInsn::mov64_imm(7, 62),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn const_prop_rejects_replacement_when_observation_missing_at_some_visit() {
        // Bug caught: a verifier delta from one diamond arm must not prove the join-pc
        // constant when another visit to the same pc omitted that register.
        let original = vec![
            call_helper(7),
            BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(0, 0), 1, 0),
            BpfInsn::nop(),
            add64_imm(3, 1),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![
            verifier_delta_state(3, HashMap::from([(3, scalar_reg(99))])),
            verifier_delta_state(3, HashMap::new()),
        ]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_rejects_replacement_when_full_state_visit_omits_reg() {
        // Bug caught: full verifier snapshots are visits too; ignoring a full-state
        // omission would let one delta-state exact value masquerade as global proof.
        let original = vec![call_helper(7), add64_imm(3, 1), exit_insn()];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![
            verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
            verifier_state_in_frame(1, 0, VerifierInsnKind::PcFullState, HashMap::new()),
        ]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_rejects_replacement_across_disagreeing_frames() {
        // Bug caught: context-insensitive simulation must not apply a verifier fact
        // from one call frame when the same pc has a different exact value elsewhere.
        let original = vec![call_helper(7), add64_imm(3, 1), exit_insn()];
        let mut program = BpfProgram::new(original.clone());
        program.set_verifier_states(vec![
            verifier_delta_state_in_frame(1, 0, HashMap::from([(3, scalar_reg(42))])),
            verifier_delta_state_in_frame(1, 1, HashMap::from([(3, scalar_reg(43))])),
        ]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert_eq!(program.insns, original);
    }

    #[test]
    fn const_prop_accepts_when_every_visit_agrees() {
        // Bug caught: the fail-closed oracle should still allow useful folding when
        // every verifier visit to a pc/frame observes the same exact register value.
        let mut program = BpfProgram::new(vec![call_helper(7), add64_imm(3, 1), exit_insn()]);
        program.set_verifier_states(vec![
            verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
            verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
        ]);

        let result = run_const_prop_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![call_helper(7), BpfInsn::mov64_imm(3, 42), exit_insn()]
        );
    }

    #[test]
    fn eval_binary_alu_rejects_zero_divisor_without_panicking() {
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, true), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, true), None);
    }
}
