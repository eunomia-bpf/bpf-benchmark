// SPDX-License-Identifier: MIT
// Constant propagation and ALU materialization.

use std::collections::{BTreeMap, BTreeSet};

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::pass::*;

use crate::rewrite::{BtfRemapPolicy, RewritePlan};

const REG_COUNT: usize = 11;
// ReJIT logs can report post-state PCs slightly ahead of bpfopt's current
// bytecode index after earlier transforms; pointer evidence must still win.
const VERIFIER_POINTER_POST_STATE_LOOKAHEAD: usize = 8;
pub(super) const VERIFIER_POST_STATE_NOT_SCALAR_EXACT: &str =
    "verifier post-state is not scalar-exact";
pub(super) const VERIFIER_POST_STATE_POINTER_TYPE: &str =
    "register has pointer type, cannot materialize";

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
struct RegConstFact {
    exact64: Option<u64>,
    exact32: Option<u32>,
    may_pointer: bool,
}

impl RegConstFact {
    const fn unknown() -> Self {
        Self {
            exact64: None,
            exact32: None,
            may_pointer: false,
        }
    }

    const fn pointer() -> Self {
        Self {
            exact64: None,
            exact32: None,
            may_pointer: true,
        }
    }
}

type RegConstState = [RegConstFact; REG_COUNT];

#[derive(Default)]
struct VerifierExactConstOracle {
    facts: BTreeMap<(usize, usize, u8), RegConstFact>,
    insn_delta_scalar_post_states: BTreeMap<(usize, usize, u8), VerifierScalarExactPostState>,
    insn_delta_pointer_post_states: BTreeSet<(usize, usize, u8)>,
    frames_by_pc: BTreeMap<usize, BTreeSet<usize>>,
    post_state_frames_by_pc: BTreeMap<usize, BTreeSet<usize>>,
}

#[derive(Clone, Copy, Debug, Default)]
struct OracleExactAccumulator {
    saw_observation: bool,
    exact64: Consensus<u64>,
    exact32: Consensus<u32>,
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
            may_pointer: false,
        };
        (fact.exact64.is_some() || fact.exact32.is_some()).then_some(fact)
    }
}

impl VerifierExactConstOracle {
    fn from_states(states: &[VerifierInsn]) -> Self {
        let mut frames_by_pc: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();
        let mut visit_counts: BTreeMap<(usize, usize), usize> = BTreeMap::new();
        let mut observed_counts: BTreeMap<(usize, usize, u8), usize> = BTreeMap::new();
        let mut accumulators: BTreeMap<(usize, usize, u8), OracleExactAccumulator> =
            BTreeMap::new();
        let mut post_state_frames_by_pc: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();
        let mut post_state_visit_counts: BTreeMap<(usize, usize), usize> = BTreeMap::new();
        let mut post_state_observed_counts: BTreeMap<(usize, usize, u8), usize> = BTreeMap::new();
        let mut post_state_accumulators: BTreeMap<
            (usize, usize, u8),
            Consensus<VerifierScalarExactPostState>,
        > = BTreeMap::new();
        let mut insn_delta_pointer_post_states = BTreeSet::new();

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

            if state.kind == VerifierInsnKind::InsnDeltaState {
                post_state_frames_by_pc
                    .entry(state.pc)
                    .or_default()
                    .insert(state.frame);
                *post_state_visit_counts
                    .entry((state.pc, state.frame))
                    .or_default() += 1;
                for (&regno, reg_state) in &state.regs {
                    let key = (state.pc, state.frame, regno);
                    *post_state_observed_counts.entry(key).or_default() += 1;
                    if verifier_type_is_pointer(&reg_state.reg_type) {
                        insn_delta_pointer_post_states.insert(key);
                    }
                    let acc = post_state_accumulators.entry(key).or_default();
                    match scalar_exact_post_state(reg_state) {
                        Some(post_state) => acc.observe(post_state),
                        None => acc.invalidate(),
                    }
                }
            }
        }

        let mut facts = BTreeMap::new();
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
        }
        let mut insn_delta_scalar_post_states = BTreeMap::new();
        for (key, acc) in post_state_accumulators {
            let (pc, frame, _) = key;
            let visits = post_state_visit_counts
                .get(&(pc, frame))
                .copied()
                .unwrap_or(0);
            let observations = post_state_observed_counts.get(&key).copied().unwrap_or(0);
            if observations != visits {
                continue;
            }
            if let Some(state) = acc.into_option() {
                insn_delta_scalar_post_states.insert(key, state);
            }
        }

        Self {
            facts,
            insn_delta_scalar_post_states,
            insn_delta_pointer_post_states,
            frames_by_pc,
            post_state_frames_by_pc,
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
            may_pointer: false,
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

    fn instruction_post_state_proves_scalar_exact(
        &self,
        pc: usize,
        frame: usize,
        dst: u8,
        value: i64,
        width: VerifierValueWidth,
    ) -> bool {
        self.insn_delta_scalar_post_states
            .get(&(pc, frame, dst))
            .is_some_and(|state| state.matches(value, width))
    }

    fn instruction_post_state_proves_scalar_exact_in_context(
        &self,
        pc: usize,
        frame: Option<usize>,
        dst: u8,
        value: i64,
        width: VerifierValueWidth,
    ) -> bool {
        match frame {
            Some(frame) => {
                self.instruction_post_state_proves_scalar_exact(pc, frame, dst, value, width)
            }
            None => self
                .post_state_frames_by_pc
                .get(&pc)
                .filter(|frames| !frames.is_empty())
                .is_some_and(|frames| {
                    frames.iter().all(|&frame| {
                        self.instruction_post_state_proves_scalar_exact(
                            pc, frame, dst, value, width,
                        )
                    })
                }),
        }
    }

    fn instruction_post_state_has_pointer_type_in_context(
        &self,
        pc: usize,
        frame: Option<usize>,
        dst: u8,
    ) -> bool {
        let max_pc = pc.saturating_add(VERIFIER_POINTER_POST_STATE_LOOKAHEAD);
        match frame {
            Some(frame) => {
                self.insn_delta_pointer_post_states
                    .iter()
                    .any(|&(state_pc, state_frame, reg)| {
                        state_pc >= pc && state_pc <= max_pc && state_frame == frame && reg == dst
                    })
            }
            None => self
                .insn_delta_pointer_post_states
                .iter()
                .any(|&(state_pc, _, reg)| state_pc >= pc && state_pc <= max_pc && reg == dst),
        }
    }

    fn apply_exact_facts(&self, pc: usize, frame: Option<usize>, state: &mut RegConstState) {
        for reg in 0..REG_COUNT {
            if let Some(fact) = self.fact(pc, frame, reg as u8) {
                set_reg_oracle_fact(state, reg as u8, fact);
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

fn verifier_type_is_pointer(reg_type: &str) -> bool {
    reg_type != "scalar"
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
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let cfg = analyses.get::<CFGAnalysis>(program);
        if cfg.blocks.is_empty() {
            return Ok(PassResult::unchanged());
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
                return Ok(PassResult::unchanged());
            }

            return Ok(PassResult {
                sites_skipped: rewrite_plan.sites_skipped,
                diagnostics: vec!["const_prop_alu_materialized=0".to_string()],
                ..Default::default()
            });
        }

        let alu_materialized = rewrite_plan
            .replacements
            .keys()
            .filter(|&&pc| matches!(program.insns[pc].class(), BPF_ALU | BPF_ALU64))
            .count();

        let mut plan = RewritePlan::new();
        for (&pc, replacement) in &rewrite_plan.replacements {
            plan.replace_range(pc, insn_width(&program.insns[pc]), replacement.clone())?;
        }

        let mut result = plan.commit(program, BtfRemapPolicy::Remap)?;
        result.sites_applied = rewrite_plan.replacements.len();
        result.sites_skipped = rewrite_plan.sites_skipped;
        result.diagnostics = vec![format!("const_prop_alu_materialized={alu_materialized}")];
        Ok(result)
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
                    set_reg_may_pointer(&mut next, insn.dst_reg());
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
                None if alu_inputs_may_be_pointer(insn, state) => {
                    set_reg_may_pointer(&mut next, insn.dst_reg())
                }
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

    if can_apply_oracle_facts(insn) {
        oracle.apply_exact_facts(pc, frame, &mut next);
    }
    (next, decision)
}

fn can_apply_oracle_facts(insn: &BpfInsn) -> bool {
    !insn.is_call() && !(insn.is_mov64_reg() || insn.is_mov32_reg())
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
    if alu_inputs_may_be_pointer(insn, state) {
        return AluFoldDecision::Skip(SkipReason {
            pc,
            reason: VERIFIER_POST_STATE_POINTER_TYPE.to_string(),
        });
    }
    if oracle.instruction_post_state_has_pointer_type_in_context(pc, frame, insn.dst_reg()) {
        return AluFoldDecision::Skip(SkipReason {
            pc,
            reason: VERIFIER_POST_STATE_POINTER_TYPE.to_string(),
        });
    }
    if !oracle.instruction_post_state_proves_scalar_exact_in_context(
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
    !(insn.is_mov64_reg() || insn.is_mov32_reg())
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

pub(super) fn eval_binary_alu(op: u8, lhs: u64, rhs: u64, is_32: bool) -> Option<u64> {
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

fn alu_inputs_may_be_pointer(insn: &BpfInsn, state: &RegConstState) -> bool {
    reg_may_be_pointer(state, insn.dst_reg())
        || (bpf_src(insn.code) == BPF_X && reg_may_be_pointer(state, insn.src_reg()))
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

fn reg_may_be_pointer(state: &RegConstState, reg: u8) -> bool {
    state.get(reg as usize).is_some_and(|fact| fact.may_pointer)
}

fn set_reg_fact(state: &mut RegConstState, reg: u8, fact: RegConstFact) {
    if let Some(slot) = state.get_mut(reg as usize) {
        *slot = fact;
    }
}

fn set_reg_oracle_fact(state: &mut RegConstState, reg: u8, fact: RegConstFact) {
    if let Some(slot) = state.get_mut(reg as usize) {
        if slot.may_pointer {
            return;
        }
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
            may_pointer: false,
        },
    );
}

fn set_reg_unknown(state: &mut RegConstState, reg: u8) {
    set_reg_fact(state, reg, RegConstFact::unknown());
}

fn set_reg_may_pointer(state: &mut RegConstState, reg: u8) {
    set_reg_fact(state, reg, RegConstFact::pointer());
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
        may_pointer: lhs.may_pointer || rhs.may_pointer,
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
    let mut state = [RegConstFact::unknown(); REG_COUNT];
    state[10] = RegConstFact::pointer();
    state
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
