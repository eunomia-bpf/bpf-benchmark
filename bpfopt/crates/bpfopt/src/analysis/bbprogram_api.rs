// SPDX-License-Identifier: MIT
//! Mutation API for BBProgram.

use std::collections::{BTreeMap, BTreeSet};
use std::ops::Range;

use crate::analysis::bbprogram::range_len;
use crate::analysis::{BBProgram, Block, BlockId, DefSite, InsnSite, Terminator};
use crate::insn::{insn_width, BpfInsn};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct DiamondPattern {
    pub predecessor: BlockId,
    pub true_branch: BlockId,
    pub false_branch: BlockId,
    pub join: Option<BlockId>,
}

impl BBProgram {
    pub fn delete_insn(&mut self, site: DefSite) -> anyhow::Result<usize> {
        let site = site.site();
        let removed_slots = self.insn_slot_width(site)?;
        {
            let block = self.block_mut(site.block)?;
            if site.idx >= block.insns.len() {
                anyhow::bail!("delete_insn cannot delete terminator at {:?}", site);
            }
            block.insns.remove(site.idx);
        }
        Self::shift_metadata_after_delete(&mut self.btf, site.block, site.idx, 1);
        Self::shift_metadata_after_delete(&mut self.ldimm64_second_slots, site.block, site.idx, 1);
        Self::shift_metadata_after_delete(
            &mut self.pc_relative_ldimm64_targets,
            site.block,
            site.idx,
            1,
        );
        self.rebuild_use_def_after_mutation()?;
        Ok(removed_slots)
    }

    pub fn replace_range(
        &mut self,
        block: BlockId,
        range: Range<usize>,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        let mut next = self.clone();
        next.replace_range_in_place(block, range, replacement)?;
        *self = next;
        Ok(())
    }

    fn replace_range_in_place(
        &mut self,
        block: BlockId,
        range: Range<usize>,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        let old_len = range_len(&range)?;
        let (new_insns, new_second_slots) = logical_replacement(replacement)?;
        {
            let block_ref = self.block(block)?;
            if range.end > block_ref.insns.len() {
                anyhow::bail!(
                    "replace_range {:?} exceeds block {:?} body length {}",
                    range,
                    block,
                    block_ref.insns.len()
                );
            }
        }

        {
            let block_ref = self.block_mut(block)?;
            block_ref.insns.splice(range.clone(), new_insns.clone());
        }

        Self::shift_metadata_after_delete(&mut self.btf, block, range.start, old_len);
        Self::shift_metadata_after_delete(
            &mut self.ldimm64_second_slots,
            block,
            range.start,
            old_len,
        );
        Self::shift_metadata_after_delete(
            &mut self.pc_relative_ldimm64_targets,
            block,
            range.start,
            old_len,
        );
        if !new_insns.is_empty() {
            Self::shift_metadata_after_insert(&mut self.btf, block, range.start, new_insns.len());
            Self::shift_metadata_after_insert(
                &mut self.ldimm64_second_slots,
                block,
                range.start,
                new_insns.len(),
            );
            Self::shift_metadata_after_insert(
                &mut self.pc_relative_ldimm64_targets,
                block,
                range.start,
                new_insns.len(),
            );
        }
        for (idx, second) in new_second_slots {
            self.ldimm64_second_slots.insert(
                InsnSite {
                    block,
                    idx: range.start + idx,
                },
                second,
            );
        }

        self.rebuild_use_def_after_mutation()
    }

    pub fn delete_cond_branch(&mut self, block: BlockId) -> anyhow::Result<()> {
        let fallthrough = match self.block(block)?.terminator {
            Terminator::CondBranch { fallthrough, .. } => fallthrough,
            ref term => anyhow::bail!(
                "block {:?} terminator {:?} is not a conditional branch",
                block,
                term
            ),
        };
        let site = InsnSite {
            block,
            idx: self.block(block)?.insns.len(),
        };
        self.btf.remove(&site);
        self.ldimm64_second_slots.remove(&site);
        self.pc_relative_ldimm64_targets.remove(&site);
        self.block_mut(block)?.terminator = Terminator::Fallthrough { next: fallthrough };
        self.rebuild_cfg_edges();
        self.rebuild_use_def_after_mutation()
    }

    pub fn replace_terminator(
        &mut self,
        block: BlockId,
        terminator: Terminator,
    ) -> anyhow::Result<()> {
        let site = InsnSite {
            block,
            idx: self.block(block)?.insns.len(),
        };
        self.btf.remove(&site);
        self.ldimm64_second_slots.remove(&site);
        self.pc_relative_ldimm64_targets.remove(&site);
        self.block_mut(block)?.terminator = terminator;
        self.rebuild_cfg_edges();
        self.rebuild_use_def_after_mutation()
    }

    pub fn permute_blocks(&mut self, new_order: &[BlockId]) -> anyhow::Result<()> {
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
        self.remap_metadata_sites(|site| {
            old_to_new[site.block.0].map(|block| InsnSite {
                block,
                idx: site.idx,
            })
        });
        self.remap_pc_relative_targets_after_remove(&old_to_new)?;
        self.rebuild_cfg_edges();
        self.rebuild_use_def_after_mutation()
    }

    pub fn merge_linear_chain(&mut self, chain: &[BlockId]) -> anyhow::Result<BlockId> {
        let mut next = self.clone();
        let merged = next.merge_linear_chain_in_place(chain)?;
        *self = next;
        Ok(merged)
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
            if chain_set.contains(succ) {
                anyhow::bail!("last chain block {:?} branches back into the chain", last);
            }
        }
        ensure_no_pc_relative_targets(self, &chain_set, first)?;

        if chain.len() == 1 {
            return Ok(first);
        }

        let original_first_len = self.block(first)?.insns.len();
        let mut merged_insns = self.block(first)?.insns.clone();
        let mut offsets = BTreeMap::new();
        let mut block_lens = BTreeMap::new();
        for &block in chain {
            block_lens.insert(block, self.block(block)?.insns.len());
        }
        offsets.insert(first, 0usize);
        for &block in &chain[1..] {
            offsets.insert(block, merged_insns.len());
            merged_insns.extend_from_slice(&self.block(block)?.insns);
        }
        let merged_body_len = merged_insns.len();
        let last_terminator = self.block(last)?.terminator;

        let remap_site = |site: InsnSite| -> Option<InsnSite> {
            if !chain_set.contains(&site.block) {
                return Some(site);
            }
            if site.block == first {
                return (site.idx < original_first_len).then_some(site);
            }
            let block_len = block_lens[&site.block];
            if site.idx < block_len {
                let offset = offsets[&site.block];
                return Some(InsnSite {
                    block: first,
                    idx: offset + site.idx,
                });
            }
            if site.block == last && site.idx == block_len {
                return Some(InsnSite {
                    block: first,
                    idx: merged_body_len,
                });
            }
            None
        };
        self.remap_metadata_sites(remap_site);

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
        self.remove_blocks(&remove)?;
        Ok(removed)
    }

    pub fn try_split_block(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
        self.split_block(at)
    }

    pub fn split_block(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
        let mut next = self.clone();
        let split = next.split_block_in_place(at)?;
        *self = next;
        Ok(split)
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
        self.remap_metadata_sites_after_split(at, tail);
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
            Block {
                id: tail,
                insns: tail_insns,
                terminator: tail_terminator,
                frame,
            },
        );
        for (idx, block) in self.blocks.iter_mut().enumerate() {
            block.id = BlockId(idx);
        }
        for block in &mut self.blocks {
            if block.id != head {
                block.terminator = remap_terminator_after_insert(block.terminator, tail);
            }
        }
        if self.entry.0 >= tail.0 {
            self.entry.0 += 1;
        }
        self.rebuild_cfg_edges();
        self.rebuild_use_def_after_mutation()?;
        Ok((head, tail))
    }

    pub fn replace_diamond_with_insns(
        &mut self,
        pattern: DiamondPattern,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        let mut next = self.clone();
        next.replace_diamond_with_insns_in_place(pattern, replacement)?;
        *self = next;
        Ok(())
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
        let replacement_len = replacement.len();

        let mut remove = BTreeSet::new();
        for block in [pattern.true_branch, pattern.false_branch] {
            if block != pattern.predecessor {
                remove.insert(block);
            }
        }
        if let Some(join) = pattern.join {
            if join != pattern.predecessor {
                remove.insert(join);
            }
        }

        let replacement_offset = replacement_len;
        if let Some(join) = pattern.join {
            let join_body = self.block(join)?.insns.clone();
            let join_body_len = join_body.len();
            let join_terminator = self.block(join)?.terminator;
            let remap_site = |site: InsnSite| -> Option<InsnSite> {
                if site.block == join {
                    if site.idx < join_body_len {
                        return Some(InsnSite {
                            block: pattern.predecessor,
                            idx: replacement_offset + site.idx,
                        });
                    }
                    if site.idx == join_body_len {
                        return Some(InsnSite {
                            block: pattern.predecessor,
                            idx: replacement_offset + join_body_len,
                        });
                    }
                }
                (!remove.contains(&site.block)).then_some(site)
            };
            self.remap_metadata_sites(remap_site);
            let predecessor = self.block_mut(pattern.predecessor)?;
            predecessor.insns = Vec::with_capacity(replacement_len + join_body_len);
            predecessor.insns.extend_from_slice(&replacement);
            predecessor.insns.extend_from_slice(&join_body);
            predecessor.terminator = join_terminator;
        } else {
            let replacement_terminator = common_branch_terminator(self, pattern)?;
            let remap_site = |site: InsnSite| -> Option<InsnSite> {
                (!remove.contains(&site.block)).then_some(site)
            };
            self.remap_metadata_sites(remap_site);
            let predecessor = self.block_mut(pattern.predecessor)?;
            predecessor.insns = replacement;
            predecessor.terminator = replacement_terminator;
        }
        for (idx, second) in new_second_slots {
            self.ldimm64_second_slots.insert(
                InsnSite {
                    block: pattern.predecessor,
                    idx,
                },
                second,
            );
        }

        self.remove_blocks_in_place(&remove)?;
        Ok(())
    }

    fn remove_blocks(&mut self, remove: &BTreeSet<BlockId>) -> anyhow::Result<()> {
        let mut next = self.clone();
        next.remove_blocks_in_place(remove)?;
        *self = next;
        Ok(())
    }

    fn remove_blocks_in_place(&mut self, remove: &BTreeSet<BlockId>) -> anyhow::Result<()> {
        if remove.is_empty() {
            return Ok(());
        }
        for &block in remove {
            self.block(block)?;
        }
        if remove.contains(&self.entry) {
            anyhow::bail!("cannot remove entry block {:?}", self.entry);
        }

        let mut old_to_new = vec![None; self.blocks.len()];
        let mut next = 0usize;
        for (old, slot) in old_to_new.iter_mut().enumerate() {
            let old_id = BlockId(old);
            if remove.contains(&old_id) {
                continue;
            }
            *slot = Some(BlockId(next));
            next += 1;
        }

        let mut blocks = Vec::with_capacity(next);
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
        self.remap_metadata_sites(|site| {
            old_to_new[site.block.0].map(|block| InsnSite {
                block,
                idx: site.idx,
            })
        });
        self.remap_pc_relative_targets_after_remove(&old_to_new)?;
        self.rebuild_cfg_edges();
        self.rebuild_use_def_after_mutation()
    }

    fn remap_metadata_sites<F>(&mut self, mut remap: F)
    where
        F: FnMut(InsnSite) -> Option<InsnSite>,
    {
        self.btf = remap_site_map(std::mem::take(&mut self.btf), &mut remap);
        self.ldimm64_second_slots =
            remap_site_map(std::mem::take(&mut self.ldimm64_second_slots), &mut remap);
        self.pc_relative_ldimm64_targets = remap_site_map(
            std::mem::take(&mut self.pc_relative_ldimm64_targets),
            &mut remap,
        );
    }

    fn remap_metadata_sites_after_split(&mut self, at: InsnSite, tail: BlockId) {
        self.remap_metadata_sites(|site| {
            if site.block == at.block {
                if site.idx < at.idx {
                    Some(site)
                } else {
                    Some(InsnSite {
                        block: tail,
                        idx: site.idx - at.idx,
                    })
                }
            } else if site.block.0 >= tail.0 {
                Some(InsnSite {
                    block: BlockId(site.block.0 + 1),
                    idx: site.idx,
                })
            } else {
                Some(site)
            }
        });
    }

    fn remap_pc_relative_targets_after_insert(&mut self, inserted: BlockId) {
        for target in self.pc_relative_ldimm64_targets.values_mut() {
            if target.0 >= inserted.0 {
                target.0 += 1;
            }
        }
    }

    fn remap_pc_relative_targets_after_remove(
        &mut self,
        old_to_new: &[Option<BlockId>],
    ) -> anyhow::Result<()> {
        for target in self.pc_relative_ldimm64_targets.values_mut() {
            *target = remap_block_id(*target, old_to_new)?;
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
    prog: &BBProgram,
    removed_chain_blocks: &BTreeSet<BlockId>,
    kept: BlockId,
) -> anyhow::Result<()> {
    for (&site, &target) in &prog.pc_relative_ldimm64_targets {
        if removed_chain_blocks.contains(&target) && target != kept {
            anyhow::bail!(
                "pc-relative LD_IMM64 at {:?} targets merged-away block {:?}",
                site,
                target
            );
        }
    }
    Ok(())
}

fn remap_site_map<T, F>(map: BTreeMap<InsnSite, T>, remap: &mut F) -> BTreeMap<InsnSite, T>
where
    F: FnMut(InsnSite) -> Option<InsnSite>,
{
    map.into_iter()
        .filter_map(|(site, value)| remap(site).map(|site| (site, value)))
        .collect()
}

fn remap_block_id(block: BlockId, old_to_new: &[Option<BlockId>]) -> anyhow::Result<BlockId> {
    old_to_new
        .get(block.0)
        .copied()
        .flatten()
        .ok_or_else(|| anyhow::anyhow!("block {:?} was removed or is invalid", block))
}

fn remap_terminator_after_remove(
    term: Terminator,
    old_to_new: &[Option<BlockId>],
) -> anyhow::Result<Terminator> {
    Ok(match term {
        Terminator::Fallthrough { next } => Terminator::Fallthrough {
            next: remap_block_id(next, old_to_new)?,
        },
        Terminator::Jump { insn, target } => Terminator::Jump {
            insn,
            target: remap_block_id(target, old_to_new)?,
        },
        Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } => Terminator::CondBranch {
            cond,
            taken: remap_block_id(taken, old_to_new)?,
            fallthrough: remap_block_id(fallthrough, old_to_new)?,
        },
        Terminator::Call {
            call,
            callee,
            return_to,
        } => Terminator::Call {
            call,
            callee: remap_block_id(callee, old_to_new)?,
            return_to: remap_block_id(return_to, old_to_new)?,
        },
        Terminator::Exit { insn } => Terminator::Exit { insn },
        Terminator::End => Terminator::End,
    })
}

fn remap_terminator_after_insert(term: Terminator, inserted: BlockId) -> Terminator {
    let remap = |mut block: BlockId| {
        if block.0 >= inserted.0 {
            block.0 += 1;
        }
        block
    };
    match term {
        Terminator::Fallthrough { next } => Terminator::Fallthrough { next: remap(next) },
        Terminator::Jump { insn, target } => Terminator::Jump {
            insn,
            target: remap(target),
        },
        Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } => Terminator::CondBranch {
            cond,
            taken: remap(taken),
            fallthrough: remap(fallthrough),
        },
        Terminator::Call {
            call,
            callee,
            return_to,
        } => Terminator::Call {
            call,
            callee: remap(callee),
            return_to: remap(return_to),
        },
        Terminator::Exit { insn } => Terminator::Exit { insn },
        Terminator::End => Terminator::End,
    }
}

fn validate_diamond(prog: &BBProgram, pattern: DiamondPattern) -> anyhow::Result<()> {
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.block(pattern.predecessor)?.terminator
    else {
        anyhow::bail!(
            "diamond predecessor {:?} is not a conditional branch",
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
            anyhow::bail!("blocks {:?} do not form a supported diamond", pattern);
        }
        for branch in [pattern.true_branch, pattern.false_branch] {
            if branch == pattern.predecessor || branch == join {
                continue;
            }
            let preds = prog.predecessors(branch);
            if preds != [pattern.predecessor] {
                anyhow::bail!(
                    "diamond branch {:?} has unexpected predecessors {:?}",
                    branch,
                    preds
                );
            }
        }
        let allowed_preds = [
            pattern.predecessor,
            pattern.true_branch,
            pattern.false_branch,
        ];
        for pred in prog.predecessors(join) {
            if !allowed_preds.contains(pred) {
                anyhow::bail!(
                    "diamond join {:?} has external predecessor {:?}",
                    join,
                    pred
                );
            }
        }
    } else {
        if taken != pattern.true_branch || fallthrough != pattern.false_branch {
            anyhow::bail!("diamond without join must branch to true/false blocks directly");
        }
        let true_term = prog.block(pattern.true_branch)?.terminator;
        let false_term = prog.block(pattern.false_branch)?.terminator;
        if true_term != false_term {
            anyhow::bail!("diamond without join has different branch terminators");
        }
    }
    Ok(())
}

fn branch_reaches_join(prog: &BBProgram, branch: BlockId, join: BlockId) -> bool {
    branch == join || prog.successors(branch) == [join]
}

fn common_branch_terminator(
    prog: &BBProgram,
    pattern: DiamondPattern,
) -> anyhow::Result<Terminator> {
    let true_term = prog.block(pattern.true_branch)?.terminator;
    let false_term = prog.block(pattern.false_branch)?.terminator;
    if true_term != false_term {
        anyhow::bail!("diamond branches do not share a terminator");
    }
    Ok(true_term)
}
