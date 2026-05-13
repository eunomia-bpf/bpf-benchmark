// SPDX-License-Identifier: MIT
//! Lift linear BPF bytecode into ProgramCFG.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::sync::Arc;

use anyhow::{Context, Result};

use crate::analysis::{
    BasicBlock, BlockId, BtfMetadataMap, FrameId, InsnSite, ProgramCFG, Terminator,
    VerifierStatesBySite,
};
use crate::insn::*;
use crate::pass::{KinsnRegistry, PassContext, TargetJson, VerifierInsn, VerifierInsnKind};
use crate::passes::map_inline::{MapInlineHintAnchorSpec, MapInlineHintMode, MapInlineHintSpec};

#[cfg(test)]
pub(crate) fn lift(
    insns: &[BpfInsn],
    verifier_states: Option<Arc<[VerifierInsn]>>,
) -> anyhow::Result<ProgramCFG> {
    lift_with_kinsn_registry(insns, verifier_states, Arc::new(KinsnRegistry::new()?))
}

pub(crate) fn lift_with_kinsn_registry(
    insns: &[BpfInsn],
    verifier_states: Option<Arc<[VerifierInsn]>>,
    kinsn_reg: Arc<KinsnRegistry>,
) -> anyhow::Result<ProgramCFG> {
    if insns.is_empty() {
        return ProgramCFG::new(
            Vec::new(),
            BlockId(0),
            lift_verifier_states_by_site(verifier_states, &BTreeMap::new())?,
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
        let mut block = BasicBlock {
            id,
            insns: Vec::new(),
            terminator: Terminator::End,
            frame,
            predecessors: Vec::new(),
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
                    anyhow::bail!("exit at pc {pc} did not end block {:?}", id);
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

    let verifier_states = lift_verifier_states_by_site(verifier_states, &btf)?;

    ProgramCFG::new(
        blocks,
        BlockId(0),
        verifier_states,
        btf,
        kinsn_reg,
        ldimm64_second_slots,
        pc_relative_ldimm64_targets,
    )
}

pub fn lift_with_pass_context(insns: &[BpfInsn], ctx: &PassContext) -> anyhow::Result<ProgramCFG> {
    let mut prog = lift_with_kinsn_registry(
        insns,
        ctx.has_verifier_states().then(|| ctx.verifier_states_arc()),
        Arc::new(ctx.kinsn_registry.clone()),
    )?;
    prog.attach_side_inputs(
        insns,
        ctx.map_ids.clone(),
        ctx.func_info.clone(),
        ctx.line_info.clone(),
    )?;
    prog.attach_profile_from_annotations(&ctx.annotations)?;
    prog.set_prog_type(ctx.prog_type)?;
    Ok(prog)
}

// Snapshot initialization canonicalizes loader-owned map references before the
// daemon lifts bytecode into ProgramCFG. This is intentionally a raw Vec mutation
// path for lift-time normalization; optimization passes operate through ProgramCFG.
pub fn canonicalize_map_refs_to_idx(
    insns: &mut [BpfInsn],
    original_loader_fd_array: Option<&[i32]>,
    map_ids: &[u32],
) -> Result<()> {
    let fd_to_map_index = collect_fd_form_map_refs(insns)?;
    if fd_to_map_index.is_empty() && !contains_idx_form_map_ref(insns)? {
        return Ok(());
    }

    if fd_to_map_index.len() > map_ids.len() {
        anyhow::bail!(
            "canonicalize_map_refs_to_idx: bytecode references {} unique loader map fds but prog_info has {} map ids",
            fd_to_map_index.len(),
            map_ids.len()
        );
    }

    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            let map_pseudo = insns[i].map_pseudo();
            if map_pseudo.is_some() && i + 1 >= insns.len() {
                anyhow::bail!(
                    "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                );
            }
            if matches!(map_pseudo, Some(MapPseudo::Fd | MapPseudo::FdValue)) {
                let old_fd = insns[i].imm;
                let Some(&map_index) = fd_to_map_index.get(&old_fd) else {
                    anyhow::bail!(
                        "canonicalize_map_refs_to_idx: loader map fd {} was not present in first-seen bindings",
                        old_fd
                    );
                };
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
                insns[i].set_src_reg(if map_pseudo == Some(MapPseudo::Fd) {
                    MapPseudo::Idx.src_reg()
                } else {
                    MapPseudo::IdxValue.src_reg()
                });
            } else if matches!(map_pseudo, Some(MapPseudo::Idx | MapPseudo::IdxValue)) {
                let map_index = canonical_idx_map_index(
                    insns[i].imm,
                    original_loader_fd_array,
                    &fd_to_map_index,
                    map_ids.len(),
                )?;
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    Ok(())
}

fn collect_fd_form_map_refs(insns: &[BpfInsn]) -> Result<HashMap<i32, usize>> {
    let mut fd_to_map_index = HashMap::new();
    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            if matches!(
                insns[i].map_pseudo(),
                Some(MapPseudo::Fd | MapPseudo::FdValue)
            ) {
                if i + 1 >= insns.len() {
                    anyhow::bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                let next_index = fd_to_map_index.len();
                fd_to_map_index.entry(insns[i].imm).or_insert(next_index);
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(fd_to_map_index)
}

fn contains_idx_form_map_ref(insns: &[BpfInsn]) -> Result<bool> {
    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            if matches!(
                insns[i].map_pseudo(),
                Some(MapPseudo::Idx | MapPseudo::IdxValue)
            ) {
                if i + 1 >= insns.len() {
                    anyhow::bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                return Ok(true);
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(false)
}

fn canonical_idx_map_index(
    old_index: i32,
    original_loader_fd_array: Option<&[i32]>,
    fd_to_map_index: &HashMap<i32, usize>,
    map_count: usize,
) -> Result<usize> {
    let old_index = usize::try_from(old_index).with_context(|| {
        format!("canonicalize_map_refs_to_idx: negative map fd_array index {old_index}")
    })?;
    let Some(loader_fd_array) = original_loader_fd_array else {
        if old_index >= map_count {
            anyhow::bail!(
                "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
                old_index,
                map_count
            );
        }
        return Ok(old_index);
    };
    let Some(&loader_fd) = loader_fd_array.get(old_index) else {
        anyhow::bail!(
            "canonicalize_map_refs_to_idx: loader fd_array index {} out of range for {} fds",
            old_index,
            loader_fd_array.len()
        );
    };
    if let Some(&map_index) = fd_to_map_index.get(&loader_fd) {
        return Ok(map_index);
    }
    if loader_fd_array.len() != map_count {
        anyhow::bail!(
            "canonicalize_map_refs_to_idx: cannot map loader fd_array index {} without fd-form binding; loader fd_array has {} entries but prog_info has {} map ids",
            old_index,
            loader_fd_array.len(),
            map_count
        );
    }
    if old_index >= map_count {
        anyhow::bail!(
            "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
            old_index,
            map_count
        );
    }
    Ok(old_index)
}

pub fn shift_target_module_call_offsets_for_map_prefix(
    target: &mut TargetJson,
    map_count: usize,
) -> Result<()> {
    let module_base = module_fd_array_base(map_count)?;
    for (name, kinsn) in &mut target.kinsns {
        if kinsn.call_offset == 0 {
            continue;
        }
        if kinsn.call_offset < 0 {
            anyhow::bail!(
                "target kinsn {name} has negative call_offset {}",
                kinsn.call_offset
            );
        }
        if kinsn.btf_id == 0 {
            anyhow::bail!(
                "target kinsn {name} has call_offset {} but no BTF object id",
                kinsn.call_offset
            );
        }
        let shifted = module_base
            .checked_add(i32::from(kinsn.call_offset) - 1)
            .with_context(|| format!("target kinsn {name} call_offset overflow"))?;
        if shifted > i32::from(i16::MAX) {
            anyhow::bail!(
                "target kinsn {name} shifted call_offset {shifted} exceeds BPF instruction off field"
            );
        }
        kinsn.call_offset =
            i16::try_from(shifted).context("shifted call_offset exceeds i16 range")?;
    }
    Ok(())
}

fn module_fd_array_base(map_count: usize) -> Result<i32> {
    let map_count = i32::try_from(map_count).context("map count exceeds i32")?;
    Ok(map_count.max(1))
}

pub fn validate_map_inline_hint_specs(hints: &[MapInlineHintSpec]) -> anyhow::Result<()> {
    let mut anchors = BTreeMap::<MapInlineHintAnchorSpec, (MapInlineHintMode, usize)>::new();
    for hint in hints {
        match anchors.get_mut(&hint.anchor) {
            Some((mode, count)) => {
                if *mode != hint.mode {
                    anyhow::bail!(
                        "inline hint anchor {} mixes soft and hard folds",
                        format_hint_anchor_spec(&hint.anchor)
                    );
                }
                if hint.mode == MapInlineHintMode::Hard {
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

fn format_hint_anchor_spec(anchor: &MapInlineHintAnchorSpec) -> String {
    match anchor {
        MapInlineHintAnchorSpec::Pc(pc) => pc.to_string(),
        MapInlineHintAnchorSpec::MapName(name) => name.clone(),
    }
}

fn lift_verifier_states_by_site(
    verifier_states: Option<Arc<[VerifierInsn]>>,
    btf: &BtfMetadataMap,
) -> anyhow::Result<Option<VerifierStatesBySite>> {
    let Some(verifier_states) = verifier_states else {
        return Ok(None);
    };
    let pc_to_site = btf
        .iter()
        .map(|(&site, &pc)| (pc, site))
        .collect::<BTreeMap<_, _>>();
    let mut states_by_site = BTreeMap::<InsnSite, Vec<VerifierInsn>>::new();
    for state in verifier_states.iter() {
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
        anyhow::bail!(
            "verifier state pc {} is not present in the control-flow graph",
            state.pc
        );
    }
    pc_to_site
        .range(state.pc..)
        .next()
        .map(|(_, &site)| site)
        .or_else(|| pc_to_site.iter().next_back().map(|(_, &site)| site))
        .ok_or_else(|| anyhow::anyhow!("verifier state pc {} has no instruction site", state.pc))
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
