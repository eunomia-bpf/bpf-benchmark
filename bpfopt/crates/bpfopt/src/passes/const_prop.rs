// SPDX-License-Identifier: MIT
// Constant propagation and ALU materialization.

use std::collections::BTreeMap;

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_ldimm64, fixup_all_branches, insn_width};

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
        let mut replacements = BTreeMap::new();

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

        if replacements.is_empty() {
            return Ok(PassResult::unchanged(self.name()));
        }

        let mut alu_materialized = 0usize;
        for &pc in replacements.keys() {
            let insn = &program.insns[pc];
            if matches!(insn.class(), BPF_ALU | BPF_ALU64) {
                alu_materialized += 1;
            }
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

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        super::utils::remap_btf_metadata(program, &addr_map)?;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: replacements.len(),
            sites_skipped: vec![],
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
            }
            None
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
    fn eval_binary_alu_rejects_zero_divisor_without_panicking() {
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, false), None);
        assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, true), None);
        assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, true), None);
    }
}
