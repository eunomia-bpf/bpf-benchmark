// SPDX-License-Identifier: MIT
//! Lift linear BPF bytecode into BBProgram.

use std::collections::{BTreeMap, BTreeSet};
use std::sync::Arc;

use crate::analysis::{
    BBProgram, Block, BlockId, BtfMetadataMap, FrameId, InsnSite, Terminator, VerifierOracle,
};
use crate::insn::*;
use crate::pass::{
    BtfInfoRecords, InsnAnnotation, KinsnRegistry, MapInlineHintAnchorSpec, MapInlineHintModeSpec,
    MapInlineHintSpec, PassContext, VerifierInsn, VerifierInsnKind,
};
use crate::passes::map_inline::{
    MapInlineHint, MapInlineHintAnchor, MapInlineHintMode, MapInlineSideInput,
};

#[cfg(test)]
pub(crate) fn lift(
    insns: &[BpfInsn],
    oracle: Option<Arc<[VerifierInsn]>>,
) -> anyhow::Result<BBProgram> {
    lift_with_kinsn_registry(insns, oracle, Arc::new(KinsnRegistry::unavailable()?))
}

pub(crate) fn lift_with_kinsn_registry(
    insns: &[BpfInsn],
    oracle: Option<Arc<[VerifierInsn]>>,
    kinsn_reg: Arc<KinsnRegistry>,
) -> anyhow::Result<BBProgram> {
    if insns.is_empty() {
        return BBProgram::new(
            Vec::new(),
            BlockId(0),
            lift_oracle(oracle, &BTreeMap::new())?,
            BTreeMap::new(),
            kinsn_reg,
            BTreeMap::new(),
            BTreeMap::new(),
        );
    }

    let boundaries = instruction_boundaries(insns)?;
    let mut block_starts = collect_block_starts(insns, &boundaries)?;
    block_starts.insert(0);
    let block_starts = block_starts.into_iter().collect::<Vec<_>>();
    let pc_to_block = pc_to_block_map(insns.len(), &block_starts);
    let subprog_starts = collect_subprog_starts(insns, &boundaries)?;
    let frame_by_pc = frame_by_pc_map(insns.len(), &subprog_starts);

    let mut blocks = Vec::with_capacity(block_starts.len());
    let mut btf = BtfMetadataMap::new();
    let mut ldimm64_second_slots = BTreeMap::new();
    let mut pc_relative_ldimm64_targets = BTreeMap::new();

    for (block_idx, &start_pc) in block_starts.iter().enumerate() {
        let end_pc = match block_starts.get(block_idx + 1).copied() {
            Some(end_pc) => end_pc,
            None => insns.len(),
        };
        let id = BlockId(block_idx);
        let mut frame = 0usize;
        if let Some(current_frame) = frame_by_pc.get(start_pc).copied() {
            frame = current_frame;
        }
        let frame = FrameId(frame);
        let mut block = Block {
            id,
            insns: Vec::new(),
            terminator: Terminator::End,
            frame,
        };

        let mut pc = start_pc;
        while pc < end_pc {
            let insn = insns[pc];
            if is_block_terminator(&insn) {
                block.terminator = lift_terminator(insns, pc, end_pc, &pc_to_block)?;
                let site = InsnSite {
                    block: id,
                    idx: block.insns.len(),
                };
                btf.insert(site, pc);
                pc += 1;
                if pc != end_pc {
                    anyhow::bail!("terminator at pc {pc} did not end block {:?}", id);
                }
                break;
            }

            let site = InsnSite {
                block: id,
                idx: block.insns.len(),
            };
            btf.insert(site, pc);
            block.insns.push(insn);
            if insn.is_ldimm64() {
                let second_pc = pc + 1;
                let second = *insns
                    .get(second_pc)
                    .ok_or_else(|| anyhow::anyhow!("LD_IMM64 at pc {pc} is missing second slot"))?;
                ldimm64_second_slots.insert(site, second);
                if insn.is_ldimm64_pseudo_func() {
                    let target = target_block_for_pc_relative_imm(
                        pc,
                        i64::from(insn.imm),
                        &pc_to_block,
                        insns.len(),
                    )?;
                    pc_relative_ldimm64_targets.insert(site, target);
                }
                pc += 2;
            } else {
                pc += 1;
            }
        }

        if matches!(block.terminator, Terminator::End) && end_pc < insns.len() {
            block.terminator = Terminator::Fallthrough {
                next: pc_to_block[end_pc],
            };
        }
        blocks.push(block);
    }

    let oracle = lift_oracle(oracle, &btf)?;

    BBProgram::new(
        blocks,
        BlockId(0),
        oracle,
        btf,
        kinsn_reg,
        ldimm64_second_slots,
        pc_relative_ldimm64_targets,
    )
}

pub fn lift_with_pass_context(insns: &[BpfInsn], ctx: &PassContext) -> anyhow::Result<BBProgram> {
    lift_with_side_inputs(
        insns,
        ctx.has_verifier_states()
            .then(|| Arc::clone(&ctx.verifier_states)),
        Arc::new(ctx.kinsn_registry.clone()),
        ctx.map_ids.clone(),
        ctx.func_info.clone(),
        ctx.line_info.clone(),
        &ctx.annotations,
        Some(ctx),
    )
}

#[allow(clippy::too_many_arguments)]
fn lift_with_side_inputs(
    insns: &[BpfInsn],
    oracle: Option<Arc<[VerifierInsn]>>,
    kinsn_reg: Arc<KinsnRegistry>,
    map_ids: Vec<u32>,
    func_info: Option<BtfInfoRecords>,
    line_info: Option<BtfInfoRecords>,
    annotations: &[InsnAnnotation],
    map_inline_ctx: Option<&PassContext>,
) -> anyhow::Result<BBProgram> {
    let mut prog = lift_with_kinsn_registry(insns, oracle, kinsn_reg)?;
    prog.attach_side_inputs(insns, map_ids, func_info, line_info)?;
    prog.attach_profile_from_annotations(annotations)?;
    if let Some(ctx) = map_inline_ctx {
        if has_map_inline_side_input(ctx) {
            let side_input = resolve_map_inline_side_input(&prog, ctx)?;
            prog.attach_map_inline_side_input(side_input);
        }
    }
    Ok(prog)
}

fn has_map_inline_side_input(ctx: &PassContext) -> bool {
    !ctx.map_ids.is_empty()
        || !ctx.map_metadata.is_empty()
        || !ctx.map_values.is_empty()
        || !ctx.map_value_overlays.is_empty()
        || !ctx.map_inner_map_ids.is_empty()
        || !ctx.map_snapshots_skipped_by_size.is_empty()
        || !ctx.map_inline_hints.is_empty()
}

fn resolve_map_inline_side_input(
    prog: &BBProgram,
    ctx: &PassContext,
) -> anyhow::Result<MapInlineSideInput> {
    validate_map_inline_hint_specs(&ctx.map_inline_hints)?;
    Ok(MapInlineSideInput {
        map_ids: ctx.map_ids.clone(),
        metadata: ctx.map_metadata.clone(),
        values: ctx.map_values.clone(),
        compressed_values: ctx.map_value_overlays.clone(),
        inner_map_ids: ctx.map_inner_map_ids.clone(),
        maps_skipped_by_size: ctx.map_snapshots_skipped_by_size.clone(),
        hints: resolve_map_inline_hints(prog, &ctx.map_inline_hints)?,
    })
}

fn validate_map_inline_hint_specs(hints: &[MapInlineHintSpec]) -> anyhow::Result<()> {
    let mut anchors = BTreeMap::<MapInlineHintAnchorSpec, (MapInlineHintModeSpec, usize)>::new();
    for hint in hints {
        match anchors.get_mut(&hint.anchor) {
            Some((mode, count)) => {
                if *mode != hint.mode {
                    anyhow::bail!(
                        "inline hint anchor {} mixes soft and hard folds",
                        format_hint_anchor_spec(&hint.anchor)
                    );
                }
                if hint.mode == MapInlineHintModeSpec::Hard {
                    anyhow::bail!(
                        "inline hint anchor {} has multiple hard folds",
                        format_hint_anchor_spec(&hint.anchor)
                    );
                }
                *count += 1;
            }
            None => {
                anchors.insert(hint.anchor.clone(), (hint.mode, 1));
            }
        }
    }
    Ok(())
}

fn resolve_map_inline_hints(
    prog: &BBProgram,
    hints: &[MapInlineHintSpec],
) -> anyhow::Result<Vec<MapInlineHint>> {
    hints
        .iter()
        .map(|hint| {
            Ok(MapInlineHint {
                anchor: resolve_map_inline_hint_anchor(prog, &hint.anchor)?,
                mode: map_inline_hint_mode(hint.mode),
                key: hint.key.clone(),
            })
        })
        .collect()
}

fn resolve_map_inline_hint_anchor(
    prog: &BBProgram,
    anchor: &MapInlineHintAnchorSpec,
) -> anyhow::Result<MapInlineHintAnchor> {
    match anchor {
        MapInlineHintAnchorSpec::Pc(pc) => {
            let site = prog.original_pc_to_site(*pc).ok_or_else(|| {
                anyhow::anyhow!("map_inline hint pc {pc} is not present in BBProgram")
            })?;
            Ok(MapInlineHintAnchor::Site(site))
        }
        MapInlineHintAnchorSpec::MapName(name) => Ok(MapInlineHintAnchor::MapName(name.clone())),
    }
}

fn map_inline_hint_mode(mode: MapInlineHintModeSpec) -> MapInlineHintMode {
    match mode {
        MapInlineHintModeSpec::Soft => MapInlineHintMode::Soft,
        MapInlineHintModeSpec::Hard => MapInlineHintMode::Hard,
    }
}

fn format_hint_anchor_spec(anchor: &MapInlineHintAnchorSpec) -> String {
    match anchor {
        MapInlineHintAnchorSpec::Pc(pc) => pc.to_string(),
        MapInlineHintAnchorSpec::MapName(name) => name.clone(),
    }
}

fn lift_oracle(
    oracle: Option<Arc<[VerifierInsn]>>,
    btf: &BtfMetadataMap,
) -> anyhow::Result<Option<VerifierOracle>> {
    let Some(oracle) = oracle else {
        return Ok(None);
    };
    let pc_to_site = btf
        .iter()
        .map(|(&site, &pc)| (pc, site))
        .collect::<BTreeMap<_, _>>();
    let mut states_by_site = BTreeMap::<InsnSite, Vec<VerifierInsn>>::new();
    for state in oracle.iter() {
        states_by_site
            .entry(verifier_state_site(state, &pc_to_site)?)
            .or_default()
            .push(state.clone());
    }
    Ok(Some(
        states_by_site
            .into_iter()
            .map(|(site, states)| (site, Arc::from(states)))
            .collect(),
    ))
}

fn verifier_state_site(
    state: &VerifierInsn,
    pc_to_site: &BTreeMap<usize, InsnSite>,
) -> anyhow::Result<InsnSite> {
    if let Some(&site) = pc_to_site.get(&state.pc) {
        return Ok(site);
    }
    if state.kind != VerifierInsnKind::InsnDeltaState {
        anyhow::bail!("verifier state pc {} is not present in BBProgram", state.pc);
    }
    pc_to_site
        .range(state.pc..)
        .next()
        .map(|(_, &site)| site)
        .or_else(|| pc_to_site.iter().next_back().map(|(_, &site)| site))
        .ok_or_else(|| anyhow::anyhow!("verifier state pc {} has no BBProgram site", state.pc))
}

fn instruction_boundaries(insns: &[BpfInsn]) -> anyhow::Result<Vec<bool>> {
    let mut boundaries = vec![false; insns.len() + 1];
    let mut pc = 0usize;
    while pc < insns.len() {
        boundaries[pc] = true;
        let width = insn_width(&insns[pc]);
        if pc + width > insns.len() {
            anyhow::bail!(
                "instruction at pc {pc} exceeds program length {}",
                insns.len()
            );
        }
        pc += width;
    }
    boundaries[insns.len()] = true;
    if pc != insns.len() {
        anyhow::bail!(
            "instruction walk ended at pc {pc}, expected {}",
            insns.len()
        );
    }
    Ok(boundaries)
}

fn collect_block_starts(insns: &[BpfInsn], boundaries: &[bool]) -> anyhow::Result<BTreeSet<usize>> {
    let mut starts = BTreeSet::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        let width = insn_width(&insn);
        let next_pc = pc + width;

        if insn.is_ldimm64_pseudo_func() {
            starts.insert(target_pc_for_pc_relative_imm(
                pc,
                i64::from(insn.imm),
                insns.len(),
            )?);
        } else if is_block_terminator(&insn) {
            if !insn.is_exit() {
                if let Some(target) = branch_or_call_target_pc(&insn, pc)? {
                    starts.insert(target);
                }
            }
            if next_pc < insns.len() {
                starts.insert(next_pc);
            }
        } else if insn.is_cond_jmp() || insn.is_ja() {
            if let Some(target) = branch_or_call_target_pc(&insn, pc)? {
                starts.insert(target);
            }
            if next_pc < insns.len() {
                starts.insert(next_pc);
            }
        }

        pc = next_pc;
    }

    for &start in &starts {
        if start > insns.len() {
            anyhow::bail!(
                "block start pc {start} is outside program length {}",
                insns.len()
            );
        }
        if !boundaries[start] {
            anyhow::bail!("block start pc {start} is not an instruction boundary");
        }
    }
    Ok(starts)
}

fn collect_subprog_starts(insns: &[BpfInsn], boundaries: &[bool]) -> anyhow::Result<Vec<usize>> {
    let mut starts = BTreeSet::from([0usize]);
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_ldimm64_pseudo_func() || is_pseudo_call(&insn) {
            starts.insert(target_pc_for_pc_relative_imm(
                pc,
                i64::from(insn.imm),
                insns.len(),
            )?);
        }
        pc += insn_width(&insn);
    }

    let starts = starts.into_iter().collect::<Vec<_>>();
    for &start in &starts {
        if start >= insns.len() {
            anyhow::bail!(
                "subprogram start pc {start} is outside program length {}",
                insns.len()
            );
        }
        if !boundaries[start] {
            anyhow::bail!("subprogram start pc {start} is not an instruction boundary");
        }
    }
    Ok(starts)
}

fn pc_to_block_map(program_len: usize, block_starts: &[usize]) -> Vec<BlockId> {
    let mut pc_to_block = vec![BlockId(0); program_len + 1];
    for (idx, &start) in block_starts.iter().enumerate() {
        let end = match block_starts.get(idx + 1).copied() {
            Some(end) => end,
            None => program_len,
        };
        for slot in pc_to_block.iter_mut().take(end).skip(start) {
            *slot = BlockId(idx);
        }
    }
    pc_to_block[program_len] = match block_starts
        .iter()
        .position(|&start| start == program_len)
        .map(BlockId)
    {
        Some(block) => block,
        None => BlockId(block_starts.len()),
    };
    pc_to_block
}

fn frame_by_pc_map(program_len: usize, subprog_starts: &[usize]) -> Vec<usize> {
    let mut frame_by_pc = vec![0usize; program_len];
    for (frame, &start) in subprog_starts.iter().enumerate() {
        let end = match subprog_starts.get(frame + 1).copied() {
            Some(end) => end,
            None => program_len,
        };
        for slot in &mut frame_by_pc[start..end] {
            *slot = frame;
        }
    }
    frame_by_pc
}

fn lift_terminator(
    insns: &[BpfInsn],
    pc: usize,
    block_end: usize,
    pc_to_block: &[BlockId],
) -> anyhow::Result<Terminator> {
    let insn = insns[pc];
    if insn.is_exit() {
        return Ok(Terminator::Exit { insn });
    }
    if is_pseudo_call(&insn) {
        let callee =
            target_block_for_pc_relative_imm(pc, i64::from(insn.imm), pc_to_block, insns.len())?;
        let return_pc = pc + 1;
        if return_pc >= insns.len() {
            anyhow::bail!("pseudo_call at pc {pc} has no return instruction");
        }
        return Ok(Terminator::Call {
            call: insn,
            callee,
            return_to: pc_to_block[return_pc],
        });
    }
    if insn.is_ja() {
        let target_pc = branch_or_call_target_pc(&insn, pc)?
            .ok_or_else(|| anyhow::anyhow!("JA at pc {pc} has no target"))?;
        return Ok(Terminator::Jump {
            insn,
            target: pc_to_block[target_pc],
        });
    }
    if insn.is_cond_jmp() {
        let target_pc = branch_or_call_target_pc(&insn, pc)?
            .ok_or_else(|| anyhow::anyhow!("conditional branch at pc {pc} has no target"))?;
        let fallthrough_pc = pc + 1;
        if fallthrough_pc >= insns.len() {
            anyhow::bail!("conditional branch at pc {pc} has no fallthrough instruction");
        }
        return Ok(Terminator::CondBranch {
            cond: insn,
            taken: pc_to_block[target_pc],
            fallthrough: pc_to_block[fallthrough_pc],
        });
    }

    if block_end < insns.len() {
        Ok(Terminator::Fallthrough {
            next: pc_to_block[block_end],
        })
    } else {
        Ok(Terminator::End)
    }
}

fn is_block_terminator(insn: &BpfInsn) -> bool {
    insn.is_exit() || insn.is_ja() || insn.is_cond_jmp() || is_pseudo_call(insn)
}

fn is_pseudo_call(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == BPF_PSEUDO_CALL
}

fn branch_or_call_target_pc(insn: &BpfInsn, pc: usize) -> anyhow::Result<Option<usize>> {
    if is_pseudo_call(insn) {
        return Ok(Some(target_pc_for_pc_relative_imm(
            pc,
            i64::from(insn.imm),
            usize::MAX,
        )?));
    }
    Ok(insn.branch_target_pc(pc))
}

fn target_pc_for_pc_relative_imm(
    pc: usize,
    delta: i64,
    program_len: usize,
) -> anyhow::Result<usize> {
    let Some(target) = relative_branch_target_pc(pc, delta) else {
        anyhow::bail!("pc-relative target from pc {pc} with delta {delta} underflows");
    };
    if target >= program_len {
        anyhow::bail!("pc-relative target {target} is outside program length {program_len}");
    }
    Ok(target)
}

fn target_block_for_pc_relative_imm(
    pc: usize,
    delta: i64,
    pc_to_block: &[BlockId],
    program_len: usize,
) -> anyhow::Result<BlockId> {
    let target = target_pc_for_pc_relative_imm(pc, delta, program_len)?;
    pc_to_block
        .get(target)
        .copied()
        .ok_or_else(|| anyhow::anyhow!("target pc {target} has no block"))
}

#[cfg(test)]
#[path = "bbprogram_lift_tests.rs"]
mod tests;
