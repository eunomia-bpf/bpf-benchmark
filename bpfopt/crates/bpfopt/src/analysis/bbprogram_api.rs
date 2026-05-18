// SPDX-License-Identifier: MIT
//! Mutation API for ProgramCFG.

use std::collections::{BTreeMap, BTreeSet};
use std::ops::Range;
use std::sync::atomic::Ordering;
use std::time::Instant;

use crate::analysis::bbprogram::{N_TRY_REPLACE, T_SPLICE_NS, T_TRY_REPLACE_NS};
use crate::analysis::{BasicBlock, BlockId, DefSite, InsnNode, InsnSite, ProgramCFG, Terminator};
use crate::insn::{insn_width, BpfInsn};
use crate::pass::SiteSkipReason;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct DiamondPattern {
    pub predecessor: BlockId,
    pub true_branch: BlockId,
    pub false_branch: BlockId,
    pub join: Option<BlockId>,
}

impl ProgramCFG {
    /// Transactional rollback wrapper for mutations: clones self, applies `f` to
    /// the clone, swaps on success. On error, self is left untouched.
    fn try_mutate<R>(
        &mut self,
        f: impl FnOnce(&mut Self) -> anyhow::Result<R>,
    ) -> anyhow::Result<R> {
        let mut next = self.clone();
        let r = f(&mut next)?;
        *self = next;
        Ok(r)
    }

    pub fn delete_insn(&mut self, site: DefSite) -> anyhow::Result<usize> {
        self.try_mutate(|p| p.delete_insn_in_place(site))
    }

    fn delete_insn_in_place(&mut self, site: DefSite) -> anyhow::Result<usize> {
        let site = InsnSite {
            block: site.block,
            idx: site.idx,
        };
        let removed_slots = self.insn_slot_width(site)?;
        {
            let block = self.block_mut(site.block)?;
            if site.idx >= block.insns.len() {
                anyhow::bail!("delete_insn cannot delete terminator at {:?}", site);
            }
            block.insns.remove(site.idx);
        }
        self.rebuild_use_def_after_mutation()?;
        Ok(removed_slots)
    }

    /// Universal in-block instruction replacement core.
    ///
    /// All in-block body replacements must go through this API.
    ///
    /// 1. Basic bounds check on `(start, old_len)`.
    /// 2. Structural admission (subprog boundary) on `(old_len, new_len)`.
    ///    Skipped for pure inserts (`old_len == 0`) and pure deletes
    ///    (`new_len == 0`) since those cannot cross subprog boundaries.
    /// 3. On admission failure, records `SiteSkipReason` and returns `Ok(false)`.
    /// 4. On admission success, commits the replacement. `replacement.len()`
    ///    must equal `new_len`.
    pub fn try_replace_range(
        &mut self,
        start: InsnSite,
        old_len: usize,
        replacement: Vec<BpfInsn>,
        skipped: &mut Vec<SiteSkipReason>,
    ) -> anyhow::Result<bool> {
        let t_outer = Instant::now();
        let new_len = replacement.len();
        let block_ref = self.block(start.block)?;
        if start.idx > block_ref.insns.len() {
            anyhow::bail!(
                "try_replace_range starts at {:?}, beyond block body length {}",
                start,
                block_ref.insns.len()
            );
        }
        let end = start
            .idx
            .checked_add(old_len)
            .ok_or_else(|| anyhow::anyhow!("try_replace_range at {:?} overflows", start))?;
        if end > block_ref.insns.len() {
            anyhow::bail!(
                "try_replace_range {:?} length {} exceeds block body length {}",
                start,
                old_len,
                block_ref.insns.len()
            );
        }

        if old_len > 0 && new_len > 0 {
            if let Some(reason) = self.admission_skip_reason(start, old_len)? {
                skipped.push(SiteSkipReason {
                    site: start,
                    reason,
                });
                return Ok(false);
            }
        }

        self.replace_range_in_place(start.block, start.idx..end, replacement)?;
        T_TRY_REPLACE_NS.fetch_add(t_outer.elapsed().as_nanos() as u64, Ordering::Relaxed);
        N_TRY_REPLACE.fetch_add(1, Ordering::Relaxed);
        Ok(true)
    }

    fn replace_range_in_place(
        &mut self,
        block: BlockId,
        range: Range<usize>,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        // Reject a descending range; the value itself is unused, the
        // checked_sub here is purely validation.
        range
            .end
            .checked_sub(range.start)
            .ok_or_else(|| anyhow::anyhow!("invalid descending range {:?}", range))?;
        let (new_insns, new_second_slots) = logical_replacement(replacement)?;
        {
            let block_ref = self.block(block)?;
            if range.end > block_ref.insns.len() {
                anyhow::bail!(
                    "replace_range_at {:?} exceeds block {:?} body length {}",
                    range,
                    block,
                    block_ref.insns.len()
                );
            }
        }

        let t_splice = Instant::now();
        {
            let block_ref = self.block_mut(block)?;
            block_ref
                .insns
                .splice(range.clone(), new_insns.iter().cloned().map(InsnNode::from));
        }

        for (idx, second) in new_second_slots {
            self.insert_ldimm64_second_slot(
                InsnSite {
                    block,
                    idx: range.start + idx,
                },
                second,
            )?;
        }
        T_SPLICE_NS.fetch_add(t_splice.elapsed().as_nanos() as u64, Ordering::Relaxed);

        self.rebuild_use_def_after_mutation()
    }

    pub fn delete_cond_branch(&mut self, block: BlockId) -> anyhow::Result<()> {
        self.try_mutate(|p| p.delete_cond_branch_in_place(block))
    }

    fn delete_cond_branch_in_place(&mut self, block: BlockId) -> anyhow::Result<()> {
        let fallthrough = match self.block(block)?.terminator {
            Terminator::CondBranch { fallthrough, .. } => fallthrough,
            ref term => anyhow::bail!(
                "block {:?} terminator {:?} is not a conditional branch",
                block,
                term
            ),
        };
        {
            let b = self.block_mut(block)?;
            b.terminator = Terminator::Fallthrough { next: fallthrough };
            b.terminator_btf_pc = None;
        }
        self.rebuild_cfg_edges()?;
        self.rebuild_use_def_after_mutation()
    }

    pub fn replace_terminator(
        &mut self,
        block: BlockId,
        terminator: Terminator,
    ) -> anyhow::Result<()> {
        self.try_mutate(|p| p.replace_terminator_in_place(block, terminator))
    }

    fn replace_terminator_in_place(
        &mut self,
        block: BlockId,
        terminator: Terminator,
    ) -> anyhow::Result<()> {
        {
            let b = self.block_mut(block)?;
            b.terminator = terminator;
            b.terminator_btf_pc = None;
        }
        self.rebuild_cfg_edges()?;
        self.rebuild_use_def_after_mutation()
    }

    pub fn permute_blocks(&mut self, new_order: &[BlockId]) -> anyhow::Result<()> {
        self.try_mutate(|p| p.permute_blocks_in_place(new_order))
    }

    fn permute_blocks_in_place(&mut self, new_order: &[BlockId]) -> anyhow::Result<()> {
        if new_order.len() != self.blocks.len() {
            anyhow::bail!(
                "permute_blocks got {} blocks, expected {}",
                new_order.len(),
                self.blocks.len()
            );
        }
        validate_unique_blocks(new_order)?;
        for &block in new_order {
            self.block(block)?;
        }

        let mut old_to_new = vec![None; self.blocks.len()];
        for (new_idx, &old_id) in new_order.iter().enumerate() {
            old_to_new[old_id.0] = Some(BlockId(new_idx));
        }

        let mut blocks = Vec::with_capacity(self.blocks.len());
        for (new_idx, &old_id) in new_order.iter().enumerate() {
            let mut block = self.block(old_id)?.clone();
            block.id = BlockId(new_idx);
            block.terminator = remap_terminator_after_remove(block.terminator, &old_to_new)?;
            blocks.push(block);
        }
        self.blocks = blocks;
        self.entry = remap_block_id(self.entry, &old_to_new)?;
        self.remap_pc_relative_targets_after_remove(&old_to_new)?;
        self.rebuild_cfg_edges()?;
        self.rebuild_use_def_after_mutation()
    }

    pub fn merge_linear_chain(&mut self, chain: &[BlockId]) -> anyhow::Result<BlockId> {
        self.try_mutate(|p| p.merge_linear_chain_in_place(chain))
    }

    fn merge_linear_chain_in_place(&mut self, chain: &[BlockId]) -> anyhow::Result<BlockId> {
        if chain.is_empty() {
            anyhow::bail!("merge_linear_chain requires at least one block");
        }
        validate_unique_blocks(chain)?;
        for &block in chain {
            self.block(block)?;
        }
        for pair in chain.windows(2) {
            let current = pair[0];
            let next = pair[1];
            if current.0 + 1 != next.0 {
                anyhow::bail!(
                    "merge_linear_chain requires physically adjacent blocks, got {:?} then {:?}",
                    current,
                    next
                );
            }
            if self.successors(current) != [next] {
                anyhow::bail!(
                    "block {:?} does not have {:?} as its only chain successor: {:?}",
                    current,
                    next,
                    self.successors(current)
                );
            }
            if self.predecessors(next) != [current] {
                anyhow::bail!(
                    "block {:?} does not have {:?} as its only predecessor: {:?}",
                    next,
                    current,
                    self.predecessors(next)
                );
            }
        }
        let chain_set = chain.iter().copied().collect::<BTreeSet<_>>();
        let first = chain[0];
        let last = chain[chain.len() - 1];
        for succ in self.successors(last) {
            if chain_set.contains(&succ) {
                anyhow::bail!("last chain block {:?} branches back into the chain", last);
            }
        }
        ensure_no_pc_relative_targets(self, &chain_set, first)?;

        if chain.len() == 1 {
            return Ok(first);
        }

        let mut merged_insns = self.block(first)?.insns.clone();
        for &block in &chain[1..] {
            merged_insns.extend_from_slice(&self.block(block)?.insns);
        }
        let last_terminator = self.block(last)?.terminator;

        {
            let first_block = self.block_mut(first)?;
            first_block.insns = merged_insns;
            first_block.terminator = last_terminator;
        }

        let remove = chain[1..].iter().copied().collect::<BTreeSet<_>>();
        self.remove_blocks_in_place(&remove)?;
        Ok(first)
    }

    pub fn delete_unreachable_blocks(&mut self) -> anyhow::Result<usize> {
        if self.blocks.is_empty() {
            return Ok(0);
        }
        let mut reachable = BTreeSet::new();
        let mut stack = vec![self.entry];
        while let Some(block) = stack.pop() {
            if !reachable.insert(block) {
                continue;
            }
            stack.extend(self.successors(block).iter().copied());
        }
        let remove = self
            .blocks
            .iter()
            .map(|block| block.id)
            .filter(|block| !reachable.contains(block))
            .collect::<BTreeSet<_>>();
        let removed = remove.len();
        if removed > 0 {
            let mut next = self.clone();
            next.remove_blocks_in_place(&remove)?;
            *self = next;
        }
        Ok(removed)
    }

    pub fn split_block(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
        self.try_mutate(|p| p.split_block_in_place(at))
    }

    fn split_block_in_place(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
        let old_len = self.block(at.block)?.insns.len();
        if at.idx > old_len {
            anyhow::bail!(
                "split_block index {} exceeds block {:?} body length {}",
                at.idx,
                at.block,
                old_len
            );
        }
        let head = at.block;
        let tail = BlockId(head.0 + 1);
        self.remap_pc_relative_targets_after_insert(tail);

        let (tail_insns, tail_terminator, frame) = {
            let head_block = self.block_mut(head)?;
            let tail_insns = head_block.insns.split_off(at.idx);
            let tail_terminator = head_block.terminator;
            let frame = head_block.frame;
            head_block.terminator = Terminator::Fallthrough { next: tail };
            (tail_insns, tail_terminator, frame)
        };

        self.blocks.insert(
            tail.0,
            BasicBlock {
                id: tail,
                insns: tail_insns,
                terminator: tail_terminator,
                terminator_branch_profile: None,
                terminator_btf_pc: None,
                terminator_verifier_states: None,
                terminator_uses: Default::default(),
                terminator_defs: Default::default(),
                terminator_live_in: None,
                terminator_live_out: None,
                terminator_local_reg_state: None,
                frame,
                predecessors: Vec::new(),
            },
        );
        for (idx, block) in self.blocks.iter_mut().enumerate() {
            block.id = BlockId(idx);
        }
        for block in &mut self.blocks {
            if block.id != head {
                block.terminator = remap_terminator(block.terminator, |mut b| {
                    if b.0 >= tail.0 {
                        b.0 += 1;
                    }
                    Ok(b)
                })
                .expect("block-shift closure never fails");
            }
        }
        if self.entry.0 >= tail.0 {
            self.entry.0 += 1;
        }
        self.rebuild_cfg_edges()?;
        self.rebuild_use_def_after_mutation()?;
        Ok((head, tail))
    }

    pub fn replace_diamond_with_insns(
        &mut self,
        pattern: DiamondPattern,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        self.try_mutate(|p| p.replace_diamond_with_insns_in_place(pattern, replacement))
    }

    fn replace_diamond_with_insns_in_place(
        &mut self,
        pattern: DiamondPattern,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        self.block(pattern.predecessor)?;
        self.block(pattern.true_branch)?;
        self.block(pattern.false_branch)?;
        if let Some(join) = pattern.join {
            self.block(join)?;
        }
        validate_diamond(self, pattern)?;
        let (replacement, new_second_slots) = logical_replacement(replacement)?;
        if replacement.is_empty() {
            anyhow::bail!("replace_diamond_with_insns requires a non-empty replacement");
        }
        // A branch block is "shared" if any incoming edge enters it from outside
        // the diamond. Shared branches can't be removed (their external edges
        // would dangle); the diamond path bypasses them via Jump->join from the
        // predecessor. The join is always preserved when present, so unrelated
        // external predecessors of the join remain valid after the branch arms
        // are removed.
        let branch_shared = |branch: BlockId| {
            branch != pattern.predecessor
                && self
                    .predecessors(branch)
                    .iter()
                    .any(|pred| *pred != pattern.predecessor)
        };

        let mut remove = BTreeSet::new();
        for block in [pattern.true_branch, pattern.false_branch] {
            if block != pattern.predecessor && !branch_shared(block) {
                remove.insert(block);
            }
        }

        if let Some(join) = pattern.join {
            let predecessor = self.block_mut(pattern.predecessor)?;
            predecessor.insns = replacement.iter().cloned().map(InsnNode::from).collect();
            predecessor.terminator = Terminator::Jump {
                insn: BpfInsn::ja(0),
                target: join,
            };
        } else {
            let true_term = self.block(pattern.true_branch)?.terminator;
            let false_term = self.block(pattern.false_branch)?.terminator;
            if true_term != false_term {
                anyhow::bail!("CFG diamond branches do not share a terminator");
            }
            let predecessor = self.block_mut(pattern.predecessor)?;
            predecessor.insns = replacement.iter().cloned().map(InsnNode::from).collect();
            predecessor.terminator = true_term;
        }
        for (idx, second) in new_second_slots {
            self.insert_ldimm64_second_slot(
                InsnSite {
                    block: pattern.predecessor,
                    idx,
                },
                second,
            )?;
        }

        self.remove_blocks_in_place(&remove)?;
        Ok(())
    }

    fn remove_blocks_in_place(&mut self, remove: &BTreeSet<BlockId>) -> anyhow::Result<()> {
        for &block in remove {
            self.block(block)?;
        }
        if remove.contains(&self.entry) {
            anyhow::bail!("cannot remove entry block {:?}", self.entry);
        }

        let removed = remove.iter().copied().collect::<Vec<_>>();
        let mut old_to_new = vec![None; self.blocks.len()];
        for (old, slot) in old_to_new.iter_mut().enumerate() {
            let old_id = BlockId(old);
            if remove.contains(&old_id) {
                continue;
            }
            *slot = Some(Self::remap_block_after_remove(old_id, &removed)?);
        }

        let mut blocks = Vec::with_capacity(self.blocks.len() - remove.len());
        for block in self
            .blocks
            .iter()
            .filter(|block| !remove.contains(&block.id))
        {
            let mut block = block.clone();
            block.id = remap_block_id(block.id, &old_to_new)?;
            block.terminator = remap_terminator_after_remove(block.terminator, &old_to_new)?;
            blocks.push(block);
        }
        self.blocks = blocks;
        self.entry = remap_block_id(self.entry, &old_to_new)?;
        self.remap_pc_relative_targets_after_remove(&old_to_new)?;
        self.rebuild_cfg_edges()?;
        self.rebuild_use_def_after_mutation()
    }

    // remap_metadata_sites / remap_metadata_sites_after_split were the
    // sidecar-shifting helpers for the deleted btf BTreeMap. With all per-insn
    // metadata now living inline on `InsnNode`, Vec splice/move carries the
    // fields with the instruction and no remap is needed.

    fn remap_pc_relative_targets_after_insert(&mut self, inserted: BlockId) {
        for block in &mut self.blocks {
            for node in &mut block.insns {
                if let Some(target) = node.pc_relative_ldimm64_target.as_mut() {
                    if target.0 >= inserted.0 {
                        target.0 += 1;
                    }
                }
            }
        }
    }

    fn remap_pc_relative_targets_after_remove(
        &mut self,
        old_to_new: &[Option<BlockId>],
    ) -> anyhow::Result<()> {
        for block in &mut self.blocks {
            for node in &mut block.insns {
                if let Some(target) = node.pc_relative_ldimm64_target.as_mut() {
                    *target = remap_block_id(*target, old_to_new)?;
                }
            }
        }
        Ok(())
    }
}

fn logical_replacement(
    replacement: Vec<BpfInsn>,
) -> anyhow::Result<(Vec<BpfInsn>, BTreeMap<usize, BpfInsn>)> {
    let mut logical = Vec::new();
    let mut second_slots = BTreeMap::new();
    let mut pc = 0usize;
    while pc < replacement.len() {
        let insn = replacement[pc];
        let width = insn_width(&insn);
        if pc + width > replacement.len() {
            anyhow::bail!("replacement LD_IMM64 at pc {pc} is missing its second slot");
        }
        let idx = logical.len();
        logical.push(insn);
        if width == 2 {
            second_slots.insert(idx, replacement[pc + 1]);
        }
        pc += width;
    }
    Ok((logical, second_slots))
}

fn validate_unique_blocks(blocks: &[BlockId]) -> anyhow::Result<()> {
    let mut seen = BTreeSet::new();
    for &block in blocks {
        if !seen.insert(block) {
            anyhow::bail!("duplicate block {:?} in block list", block);
        }
    }
    Ok(())
}

fn ensure_no_pc_relative_targets(
    prog: &ProgramCFG,
    removed_chain_blocks: &BTreeSet<BlockId>,
    kept: BlockId,
) -> anyhow::Result<()> {
    for block in prog.blocks() {
        for (idx, node) in block.insns.iter().enumerate() {
            if let Some(target) = node.pc_relative_ldimm64_target {
                if removed_chain_blocks.contains(&target) && target != kept {
                    let site = InsnSite {
                        block: block.id,
                        idx,
                    };
                    anyhow::bail!(
                        "pc-relative LD_IMM64 at {:?} targets merged-away block {:?}",
                        site,
                        target
                    );
                }
            }
        }
    }
    Ok(())
}

fn remap_block_id(block: BlockId, old_to_new: &[Option<BlockId>]) -> anyhow::Result<BlockId> {
    old_to_new
        .get(block.0)
        .copied()
        .flatten()
        .ok_or_else(|| anyhow::anyhow!("block {:?} was removed or is invalid", block))
}

fn remap_terminator<F>(term: Terminator, mut remap: F) -> anyhow::Result<Terminator>
where
    F: FnMut(BlockId) -> anyhow::Result<BlockId>,
{
    Ok(match term {
        Terminator::Fallthrough { next } => Terminator::Fallthrough { next: remap(next)? },
        Terminator::Jump { insn, target } => Terminator::Jump {
            insn,
            target: remap(target)?,
        },
        Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } => Terminator::CondBranch {
            cond,
            taken: remap(taken)?,
            fallthrough: remap(fallthrough)?,
        },
        Terminator::Call {
            call,
            callee,
            return_to,
        } => Terminator::Call {
            call,
            callee: remap(callee)?,
            return_to: remap(return_to)?,
        },
        Terminator::Exit { insn } => Terminator::Exit { insn },
        Terminator::End => Terminator::End,
    })
}

fn remap_terminator_after_remove(
    term: Terminator,
    old_to_new: &[Option<BlockId>],
) -> anyhow::Result<Terminator> {
    remap_terminator(term, |b| remap_block_id(b, old_to_new))
}

fn validate_diamond(prog: &ProgramCFG, pattern: DiamondPattern) -> anyhow::Result<()> {
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.block(pattern.predecessor)?.terminator
    else {
        anyhow::bail!(
            "CFG diamond predecessor {:?} is not a conditional branch",
            pattern.predecessor
        );
    };

    if let Some(join) = pattern.join {
        let pattern_a = taken == pattern.true_branch
            && fallthrough == pattern.false_branch
            && branch_reaches_join(prog, pattern.true_branch, join)
            && branch_reaches_join(prog, pattern.false_branch, join);
        let pattern_c = pattern.true_branch == pattern.predecessor
            && taken == join
            && fallthrough == pattern.false_branch
            && branch_reaches_join(prog, pattern.false_branch, join);
        if !pattern_a && !pattern_c {
            anyhow::bail!("blocks {:?} do not form a supported CFG diamond", pattern);
        }
    } else {
        if taken != pattern.true_branch || fallthrough != pattern.false_branch {
            anyhow::bail!("CFG diamond without join must branch to true/false blocks directly");
        }
        let true_term = prog.block(pattern.true_branch)?.terminator;
        let false_term = prog.block(pattern.false_branch)?.terminator;
        if true_term != false_term {
            anyhow::bail!("CFG diamond without join has different branch terminators");
        }
    }
    Ok(())
}

fn branch_reaches_join(prog: &ProgramCFG, branch: BlockId, join: BlockId) -> bool {
    branch == join || prog.successors(branch) == [join]
}
