// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, BlockId, InsnSite};
use crate::insn::*;
use crate::pass::*;
use std::collections::BTreeMap;
const REG_COUNT: usize = 11;
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
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum AluWidth {
    Bits32,
    Bits64,
}
enum AluFoldDecision {
    Replace(Vec<BpfInsn>),
    Skip(SiteSkipReason),
    None,
}
type ConstPropReplacement = (InsnSite, Vec<BpfInsn>);
struct RewriteOutputs<'a> {
    replacements: &'a mut Vec<ConstPropReplacement>,
    sites_skipped: &'a mut Vec<SiteSkipReason>,
}
pub struct ConstPropPass;
impl BpfPass for ConstPropPass {
    fn name(&self) -> &str {
        "const_prop"
    }
    fn run(&self, program: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram) -> anyhow::Result<PassResult> {
    if prog.is_empty() {
        return Ok(PassResult::unchanged());
    }
    let dataflow_preds = dataflow_predecessors(prog)?;
    let block_in = solve_block_entry_states(prog, &dataflow_preds)?;
    let mut replacements = Vec::<(InsnSite, Vec<BpfInsn>)>::new();
    let mut sites_skipped = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        let in_state = *block_in
            .get(&block)
            .ok_or_else(|| anyhow::anyhow!("block {:?} is missing solved input state", block))?;
        simulate_block(
            prog,
            block,
            in_state,
            Some(RewriteOutputs {
                replacements: &mut replacements,
                sites_skipped: &mut sites_skipped,
            }),
        )?;
    }
    if replacements.is_empty() {
        if sites_skipped.is_empty() {
            return Ok(PassResult::unchanged());
        }
        return Ok(PassResult {
            site_skipped: sites_skipped,
            diagnostics: vec!["const_prop_alu_materialized=0".to_string()],
            ..Default::default()
        });
    }
    let alu_materialized = replacements.len();
    let mut applied = 0usize;
    replacements.sort_by_key(|(site, _)| *site);
    for (site, replacement) in replacements.into_iter().rev() {
        prog.replace_range_at(site, 1, replacement)?;
        applied += 1;
    }
    Ok(PassResult {
        sites_applied: applied,
        site_skipped: sites_skipped,
        diagnostics: vec![format!("const_prop_alu_materialized={alu_materialized}")],
        ..Default::default()
    })
}
fn dataflow_predecessors(prog: &BBProgram) -> anyhow::Result<BTreeMap<BlockId, Vec<BlockId>>> {
    let mut preds = prog
        .block_ids()
        .map(|block| (block, Vec::new()))
        .collect::<BTreeMap<_, _>>();
    for block in prog.blocks() {
        for succ in prog.dataflow_successors(block.id)? {
            let Some(slot) = preds.get_mut(&succ) else {
                anyhow::bail!("block {:?} has invalid successor {:?}", block.id, succ);
            };
            slot.push(block.id);
        }
    }
    for slot in preds.values_mut() {
        slot.sort_unstable();
        slot.dedup();
    }
    Ok(preds)
}
fn solve_block_entry_states(
    prog: &BBProgram,
    dataflow_preds: &BTreeMap<BlockId, Vec<BlockId>>,
) -> anyhow::Result<BTreeMap<BlockId, RegConstState>> {
    let mut block_in = prog
        .block_ids()
        .map(|block| (block, unknown_state()))
        .collect::<BTreeMap<_, _>>();
    let mut block_out = block_in.clone();
    let mut updated = true;
    while updated {
        updated = false;
        for block in prog.blocks() {
            let preds = dataflow_preds.get(&block.id).ok_or_else(|| {
                anyhow::anyhow!("block {:?} is missing predecessor state", block.id)
            })?;
            let in_state = merge_predecessor_states(preds, &block_out)?;
            let out_state = simulate_block(prog, block.id, in_state, None)?;
            if block_in.get(&block.id) != Some(&in_state)
                || block_out.get(&block.id) != Some(&out_state)
            {
                block_in.insert(block.id, in_state);
                block_out.insert(block.id, out_state);
                updated = true;
            }
        }
    }
    Ok(block_in)
}
fn merge_predecessor_states(
    preds: &[BlockId],
    block_out: &BTreeMap<BlockId, RegConstState>,
) -> anyhow::Result<RegConstState> {
    let Some((&first, rest)) = preds.split_first() else {
        return Ok(unknown_state());
    };
    let mut merged = *block_out
        .get(&first)
        .ok_or_else(|| anyhow::anyhow!("predecessor {:?} is missing output state", first))?;
    for &pred in rest {
        let pred_state = *block_out
            .get(&pred)
            .ok_or_else(|| anyhow::anyhow!("predecessor {:?} is missing output state", pred))?;
        merged = meet_states(&merged, &pred_state);
    }
    Ok(merged)
}
fn simulate_block(
    prog: &BBProgram,
    block: BlockId,
    mut state: RegConstState,
    mut rewrite_outputs: Option<RewriteOutputs<'_>>,
) -> anyhow::Result<RegConstState> {
    let collect_rewrites = rewrite_outputs.is_some();
    for site in prog.sites_in_block_with_terminator(block)? {
        let insn = *prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        let ldimm64_value = if insn.is_ldimm64() {
            Some(decode_ldimm64_site(prog, site)?)
        } else {
            None
        };
        let (next_state, decision) =
            analyze_instruction(prog, &insn, ldimm64_value, site, &state, collect_rewrites)?;
        if let Some(outputs) = rewrite_outputs.as_mut() {
            match decision {
                AluFoldDecision::Replace(replacement) => {
                    outputs.replacements.push((site, replacement));
                }
                AluFoldDecision::Skip(skip) => outputs.sites_skipped.push(skip),
                AluFoldDecision::None => {}
            }
        }
        state = next_state;
    }
    Ok(state)
}
fn analyze_instruction(
    prog: &BBProgram,
    insn: &BpfInsn,
    ldimm64_value: Option<u64>,
    site: InsnSite,
    state: &RegConstState,
    collect_rewrites: bool,
) -> anyhow::Result<(RegConstState, AluFoldDecision)> {
    let mut next = *state;
    let decision = match insn.class() {
        BPF_LD => {
            if insn.is_ldimm64() {
                if insn.src_reg() == 0 {
                    let value = ldimm64_value
                        .ok_or_else(|| anyhow::anyhow!("missing LD_IMM64 value at {:?}", site))?;
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
            let decision = if collect_rewrites && !prog.site_is_dead_code(site) {
                fold_alu_instruction(prog, insn, site, state)
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
    if can_apply_program_facts(insn) {
        apply_program_facts(prog, site, &mut next);
    }
    Ok((next, decision))
}
fn can_apply_program_facts(insn: &BpfInsn) -> bool {
    !(insn.is_call() || insn.is_mov64_reg() || insn.is_mov32_reg())
}
fn fold_alu_instruction(
    prog: &BBProgram,
    insn: &BpfInsn,
    site: InsnSite,
    state: &RegConstState,
) -> AluFoldDecision {
    if bpf_op(insn.code) == BPF_MOV && bpf_src(insn.code) == BPF_K {
        return AluFoldDecision::None;
    }
    let is_32 = insn.class() == BPF_ALU;
    let result = evaluate_alu_result(insn, state).or_else(|| {
        program_materializes_alu_result(insn)
            .then(|| program_exact_for_instruction(prog, site, insn.dst_reg(), is_32))
            .flatten()
    });
    let Some(result) = result else {
        return AluFoldDecision::None;
    };
    let candidate = emit_scalar_const_load(insn.dst_reg(), result, is_32);
    if replacement_if_changed(insn, &candidate).is_none() {
        return AluFoldDecision::None;
    }
    let width = if is_32 {
        AluWidth::Bits32
    } else {
        AluWidth::Bits64
    };
    if alu_inputs_may_be_pointer(insn, state) {
        return AluFoldDecision::Skip(SiteSkipReason {
            site,
            reason: VERIFIER_POST_STATE_POINTER_TYPE.to_string(),
        });
    }
    if verifier_reg_may_be_pointer(prog, site, insn.dst_reg()) {
        return AluFoldDecision::Skip(SiteSkipReason {
            site,
            reason: VERIFIER_POST_STATE_POINTER_TYPE.to_string(),
        });
    }
    if !program_proves_scalar_exact(prog, site, insn.dst_reg(), result, width) {
        return AluFoldDecision::Skip(SiteSkipReason {
            site,
            reason: VERIFIER_POST_STATE_NOT_SCALAR_EXACT.to_string(),
        });
    }
    AluFoldDecision::Replace(candidate)
}
fn program_materializes_alu_result(insn: &BpfInsn) -> bool {
    !(insn.is_mov64_reg() || insn.is_mov32_reg())
}
fn program_exact_for_instruction(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
    is_32: bool,
) -> Option<u64> {
    let value = prog.reg_known_constant(site, reg)? as u64;
    Some(normalize_alu_result(is_32, value))
}
fn program_proves_scalar_exact(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
    expected: u64,
    width: AluWidth,
) -> bool {
    let Some(value) = prog.reg_known_constant(site, reg) else {
        return false;
    };
    match width {
        AluWidth::Bits32 => value as u32 as u64 == expected as u32 as u64,
        AluWidth::Bits64 => value as u64 == expected,
    }
}
fn apply_program_facts(prog: &BBProgram, site: InsnSite, state: &mut RegConstState) {
    for reg in 0..REG_COUNT {
        let reg = reg as u8;
        let fact = if verifier_reg_may_be_pointer(prog, site, reg) {
            Some(RegConstFact::pointer())
        } else {
            prog.reg_known_constant(site, reg)
                .map(|value| RegConstFact {
                    exact64: Some(value as u64),
                    exact32: Some(value as u32),
                    may_pointer: false,
                })
        };
        if let Some(fact) = fact {
            set_reg_program_fact(state, reg, fact);
        }
    }
}
fn verifier_reg_may_be_pointer(prog: &BBProgram, site: InsnSite, reg: u8) -> bool {
    matches!(
        prog.reg_kind(site, reg),
        Some(
            RegKind::FramePointer
                | RegKind::Context
                | RegKind::PacketPointer
                | RegKind::PacketMetaPointer
                | RegKind::MapPointer
                | RegKind::MapValue
                | RegKind::MapKey
                | RegKind::Memory
                | RegKind::BtfStructPointer
                | RegKind::OtherPointer
        )
    )
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
    eval_binary_alu_const(op, dst, rhs, is_32)
}
fn eval_unary_alu(op: u8, lhs: u64, is_32: bool) -> Option<u64> {
    match (op, is_32) {
        (BPF_NEG, true) => Some((-(lhs as u32 as i32) as u32) as u64),
        (BPF_NEG, false) => Some((-(lhs as i64)) as u64),
        _ => None,
    }
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
fn set_reg_program_fact(state: &mut RegConstState, reg: u8, fact: RegConstFact) {
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
fn decode_ldimm64_site(prog: &BBProgram, site: InsnSite) -> anyhow::Result<u64> {
    let first = prog
        .insn_at(site)
        .ok_or_else(|| anyhow::anyhow!("missing LD_IMM64 first slot at {:?}", site))?;
    let second = prog
        .ldimm64_second_slot(site)
        .ok_or_else(|| anyhow::anyhow!("missing LD_IMM64 second slot at {:?}", site))?;
    Ok(decode_ldimm64_value(first, second))
}
fn replacement_if_changed(insn: &BpfInsn, candidate: &[BpfInsn]) -> Option<Vec<BpfInsn>> {
    if candidate.len() == 1 && candidate[0] == *insn {
        return None;
    }
    Some(candidate.to_vec())
}
