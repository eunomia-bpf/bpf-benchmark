// SPDX-License-Identifier: MIT
//! Basic-block program representation for bpfopt pass execution.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ops::Range;
use std::sync::Arc;

use crate::analysis::bbprogram_btf::{remap_btf_records_view, BtfRecordKind, BtfRecordsView};
use crate::analysis::bbprogram_lower::remap_btf_records_for_lowering;
use crate::analysis::{DefSite, UseDefGraph};
use crate::insn::{insn_width, BpfInsn, MapPseudo};
use crate::pass::{BtfInfoRecords, KinsnRegistry, RegSet, VerifierInsn};

pub type VerifierOracle = Arc<[VerifierInsn]>;
pub type BtfMetadataMap = BTreeMap<InsnSite, usize>;

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct BlockId(pub usize);

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct FrameId(pub usize);

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct InsnSite {
    pub block: BlockId,
    pub idx: usize,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct BBMapBinding {
    pub old_fd: i32,
    pub map_id: u32,
}

#[derive(Clone, Debug)]
pub struct BBProgram {
    pub(super) blocks: Vec<Block>,
    pub entry: BlockId,
    pub(super) use_def: UseDefGraph,
    pub(super) oracle: Option<VerifierOracle>,
    pub(super) btf: BtfMetadataMap,
    pub(super) kinsn_reg: Arc<KinsnRegistry>,
    pub(crate) map_ids: Vec<u32>,
    pub(crate) map_bindings: Vec<BBMapBinding>,
    pub(crate) func_info: Option<BtfInfoRecords>,
    pub(crate) line_info: Option<BtfInfoRecords>,
    pub(crate) ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>,
    pub(crate) pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>,
    pub(crate) predecessors: Vec<Vec<BlockId>>,
    pub(crate) successors: Vec<Vec<BlockId>>,
}

#[derive(Clone, Debug)]
pub struct Block {
    pub id: BlockId,
    pub(super) insns: Vec<BpfInsn>,
    pub(super) terminator: Terminator,
    pub frame: FrameId,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Terminator {
    Fallthrough {
        next: BlockId,
    },
    Jump {
        insn: BpfInsn,
        target: BlockId,
    },
    CondBranch {
        cond: BpfInsn,
        taken: BlockId,
        fallthrough: BlockId,
    },
    Call {
        call: BpfInsn,
        callee: BlockId,
        return_to: BlockId,
    },
    Exit {
        insn: BpfInsn,
    },
    End,
}

impl BBProgram {
    pub(crate) fn new(
        blocks: Vec<Block>,
        entry: BlockId,
        oracle: Option<VerifierOracle>,
        btf: BtfMetadataMap,
        kinsn_reg: Arc<KinsnRegistry>,
        ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>,
        pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>,
    ) -> anyhow::Result<Self> {
        let mut prog = Self {
            blocks,
            entry,
            use_def: UseDefGraph::default(),
            oracle,
            btf,
            kinsn_reg,
            map_ids: Vec::new(),
            map_bindings: Vec::new(),
            func_info: None,
            line_info: None,
            ldimm64_second_slots,
            pc_relative_ldimm64_targets,
            predecessors: Vec::new(),
            successors: Vec::new(),
        };
        prog.rebuild_cfg_edges()?;
        prog.rebuild_use_def()?;
        Ok(prog)
    }

    pub fn blocks(&self) -> impl Iterator<Item = &Block> {
        self.blocks.iter()
    }

    pub fn is_empty(&self) -> bool {
        self.blocks.is_empty()
    }

    pub fn block_count(&self) -> usize {
        self.blocks.len()
    }

    pub fn block_ids(&self) -> impl Iterator<Item = BlockId> + '_ {
        self.blocks.iter().map(|block| block.id)
    }

    pub fn block_body_len(&self, block: BlockId) -> anyhow::Result<usize> {
        Ok(self.block(block)?.insns.len())
    }

    pub fn block_is_body_empty(&self, block: BlockId) -> anyhow::Result<bool> {
        Ok(self.block(block)?.insns.is_empty())
    }

    pub fn block_frame(&self, block: BlockId) -> anyhow::Result<FrameId> {
        Ok(self.block(block)?.frame)
    }

    pub fn terminator(&self, block: BlockId) -> anyhow::Result<Terminator> {
        Ok(self.block(block)?.terminator)
    }

    pub fn block_single_body_insn(&self, block: BlockId) -> anyhow::Result<Option<&BpfInsn>> {
        let block = self.block(block)?;
        Ok((block.insns.len() == 1).then(|| &block.insns[0]))
    }

    pub fn block_body_insns(&self, block: BlockId) -> anyhow::Result<impl Iterator<Item = (InsnSite, &BpfInsn)> + '_> {
        self.block(block)?;
        Ok(self.blocks[block.0]
            .insns
            .iter()
            .enumerate()
            .map(move |(idx, insn)| (InsnSite { block, idx }, insn)))
    }

    pub fn copied_body_insns(&self, block: BlockId) -> anyhow::Result<Vec<BpfInsn>> {
        Ok(self.block(block)?.insns.clone())
    }

    pub fn body_insn_window(
        &self,
        block: BlockId,
        start: usize,
        len: usize,
    ) -> anyhow::Result<Vec<BpfInsn>> {
        let block_ref = self.block(block)?;
        let end = start
            .checked_add(len)
            .ok_or_else(|| anyhow::anyhow!("instruction window at {start} overflows"))?;
        Ok(block_ref
            .insns
            .get(start..end)
            .ok_or_else(|| {
                anyhow::anyhow!(
                    "instruction window {}..{} exceeds block {:?} body length {}",
                    start,
                    end,
                    block,
                    block_ref.insns.len()
                )
            })?
            .to_vec())
    }

    pub fn predecessors(&self, block: BlockId) -> &[BlockId] {
        &self.predecessors[block.0]
    }

    pub fn successors(&self, block: BlockId) -> &[BlockId] {
        &self.successors[block.0]
    }

    pub fn should_reset_linear_state_at_block(&self, block: BlockId) -> anyhow::Result<bool> {
        self.block(block)?;
        if block.0 == 0 {
            return Ok(false);
        }
        let preds = self.predecessors(block);
        if preds.len() != 1 {
            return Ok(true);
        }
        let pred = preds[0];
        if pred.0 + 1 != block.0 {
            return Ok(true);
        }
        let term = self.block(pred)?.terminator;
        Ok(
            !matches!(term, Terminator::Fallthrough { next } if next == block)
                && !matches!(term, Terminator::CondBranch { fallthrough, .. } if fallthrough == block),
        )
    }

    pub fn dominance(&self) -> Dominance {
        Dominance::compute(self)
    }

    #[cfg(test)]
    pub fn live_in(&self, block: BlockId) -> RegSet {
        self.live_in_checked(block)
            .unwrap_or_else(|err| panic!("invalid live_in query for {:?}: {err}", block))
    }

    pub fn live_in_checked(&self, block: BlockId) -> anyhow::Result<RegSet> {
        self.block(block)?;
        compute_liveness(self)
            .live_in
            .remove(&block)
            .ok_or_else(|| anyhow::anyhow!("liveness missing live_in for {:?}", block))
    }

    #[cfg(test)]
    pub fn live_out(&self, block: BlockId) -> RegSet {
        self.live_out_checked(block)
            .unwrap_or_else(|err| panic!("invalid live_out query for {:?}: {err}", block))
    }

    pub fn live_out_checked(&self, block: BlockId) -> anyhow::Result<RegSet> {
        self.block(block)?;
        compute_liveness(self)
            .live_out
            .remove(&block)
            .ok_or_else(|| anyhow::anyhow!("liveness missing live_out for {:?}", block))
    }

    #[cfg(test)]
    pub fn live_out_site(&self, site: InsnSite) -> RegSet {
        self.live_out_site_checked(site)
            .unwrap_or_else(|err| panic!("invalid live_out_site query for {:?}: {err}", site))
    }

    pub fn live_out_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet> {
        self.insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("invalid instruction site {:?}", site))?;
        compute_site_liveness(self)?
            .live_out
            .remove(&site)
            .ok_or_else(|| anyhow::anyhow!("site liveness missing live_out for {:?}", site))
    }

    pub fn live_out_current_pc(&self, pc: usize) -> anyhow::Result<RegSet> {
        let site_pcs = current_site_pcs(self)?;
        let site = self
            .site_at_current_pc(&site_pcs, pc)?
            .ok_or_else(|| anyhow::anyhow!("current pc {pc} is not present in BBProgram"))?;
        self.live_out_site_checked(site)
    }

    pub fn reaching_defs(&self, block: BlockId) -> ReachingDefs {
        let defs = self
            .use_def
            .defs()
            .copied()
            .filter(|def| def.block == block)
            .fold(BTreeMap::<u8, Vec<DefSite>>::new(), |mut defs, def| {
                defs.entry(def.reg).or_default().push(def);
                defs
            });
        ReachingDefs { defs }
    }

    pub fn map_bindings(&self) -> &[BBMapBinding] {
        &self.map_bindings
    }

    pub fn map_fd_bindings(&self) -> HashMap<i32, u32> {
        self.map_bindings
            .iter()
            .map(|binding| (binding.old_fd, binding.map_id))
            .collect()
    }

    pub fn oracle(&self) -> Option<&[VerifierInsn]> {
        self.oracle.as_deref()
    }

    pub fn kinsn_registry(&self) -> &KinsnRegistry {
        &self.kinsn_reg
    }

    pub fn def_sites(&self) -> impl Iterator<Item = DefSite> + '_ {
        self.use_def.defs().copied()
    }

    pub fn uses_for_def(&self, def: DefSite) -> &[crate::analysis::UseSite] {
        self.use_def.uses_for(def)
    }

    pub fn current_site_position(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.current_sites()?
            .into_iter()
            .position(|candidate| candidate == site)
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))
    }

    pub fn current_sites_after_in_frame(
        &self,
        site: InsnSite,
    ) -> anyhow::Result<Vec<InsnSite>> {
        let frame = self.block_frame(site.block)?;
        let sites = self.current_sites()?;
        let pos = sites
            .iter()
            .position(|candidate| *candidate == site)
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))?;
        sites
            .into_iter()
            .skip(pos + 1)
            .filter_map(|candidate| {
                self.block_frame(candidate.block)
                    .map(|candidate_frame| (candidate_frame == frame).then_some(candidate))
                    .transpose()
            })
            .collect()
    }

    pub fn current_sites_before_in_frame_rev(
        &self,
        site: InsnSite,
    ) -> anyhow::Result<Vec<InsnSite>> {
        let frame = self.block_frame(site.block)?;
        let sites = self.current_sites()?;
        let pos = sites
            .iter()
            .position(|candidate| *candidate == site)
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))?;
        sites
            .into_iter()
            .take(pos)
            .rev()
            .filter_map(|candidate| {
                self.block_frame(candidate.block)
                    .map(|candidate_frame| (candidate_frame == frame).then_some(candidate))
                    .transpose()
            })
            .collect()
    }

    pub fn subprog_blocks(&self, frame: FrameId) -> impl Iterator<Item = BlockId> + '_ {
        self.blocks
            .iter()
            .filter(move |block| block.frame == frame)
            .map(|block| block.id)
    }

    #[cfg(test)]
    pub fn btf_records(&self) -> BtfRecordsView {
        self.btf_records_checked()
            .unwrap_or_else(|err| panic!("BBProgram BTF remap should be valid: {err}"))
    }

    pub fn btf_records_checked(&self) -> anyhow::Result<BtfRecordsView> {
        Ok(BtfRecordsView {
            func: remap_btf_records_view(self, self.func_info.as_ref(), BtfRecordKind::Func)?,
            line: remap_btf_records_view(self, self.line_info.as_ref(), BtfRecordKind::Line)?,
        })
    }

    pub fn unreachable_blocks(&self) -> Vec<BlockId> {
        if self.blocks.is_empty() {
            return Vec::new();
        }
        let mut reachable = BTreeSet::new();
        let mut stack = vec![self.entry];
        while let Some(block) = stack.pop() {
            if !reachable.insert(block) {
                continue;
            }
            stack.extend(self.successors(block).iter().copied());
        }
        self.blocks
            .iter()
            .map(|block| block.id)
            .filter(|block| !reachable.contains(block))
            .filter(|&block| !self.is_lexical_dead_tail(block, &reachable))
            .collect()
    }

    fn is_lexical_dead_tail(&self, block: BlockId, reachable: &BTreeSet<BlockId>) -> bool {
        let mut idx = block.0;
        while idx > 0 {
            let prev = &self.blocks[idx - 1];
            if reachable.contains(&prev.id) {
                return matches!(prev.terminator, Terminator::Exit { .. } | Terminator::End);
            }
            if !matches!(
                prev.terminator,
                Terminator::Exit { .. } | Terminator::End | Terminator::Fallthrough { .. }
            ) {
                return false;
            }
            idx -= 1;
        }
        false
    }

    pub fn sites_in_block(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
        let len = self.block(block)?.insns.len();
        Ok((0..len).map(move |idx| InsnSite { block, idx }).collect())
    }

    pub fn sites_in_block_with_terminator(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
        self.logical_sites_in_block(block)
    }

    pub(super) fn current_site_pcs(&self) -> anyhow::Result<BTreeMap<InsnSite, usize>> {
        current_site_pcs(self)
    }

    pub fn current_sites(&self) -> anyhow::Result<Vec<InsnSite>> {
        let mut sites = self
            .current_site_pcs()?
            .into_iter()
            .map(|(site, pc)| (pc, site))
            .collect::<Vec<_>>();
        sites.sort_by_key(|(pc, _)| *pc);
        Ok(sites.into_iter().map(|(_, site)| site).collect())
    }

    pub fn report_pc(&self, site: InsnSite) -> anyhow::Result<usize> {
        current_site_pcs(self)?
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("current pc missing for {:?}", site))
    }

    pub(super) fn branch_target_pcs(&self) -> anyhow::Result<BTreeSet<usize>> {
        let block_start_pcs = current_block_start_pcs(self)?;
        let mut targets = BTreeSet::new();
        for block in self.blocks() {
            match block.terminator {
                Terminator::Jump { target, .. } => {
                    targets.insert(block_start_pcs[target.0]);
                }
                Terminator::CondBranch { taken, .. } => {
                    targets.insert(block_start_pcs[taken.0]);
                }
                Terminator::Call { callee, .. } => {
                    targets.insert(block_start_pcs[callee.0]);
                }
                Terminator::Fallthrough { .. } | Terminator::Exit { .. } | Terminator::End => {}
            }
        }
        for target in self.pc_relative_ldimm64_targets.values() {
            targets.insert(block_start_pcs[target.0]);
        }
        Ok(targets)
    }

    pub fn branch_target_sites(&self) -> anyhow::Result<BTreeSet<InsnSite>> {
        let mut targets = BTreeSet::new();
        for block in self.blocks() {
            let target = match block.terminator {
                Terminator::Jump { target, .. } => Some(target),
                Terminator::CondBranch { taken, .. } => Some(taken),
                Terminator::Call { callee, .. } => Some(callee),
                Terminator::Fallthrough { .. } | Terminator::Exit { .. } | Terminator::End => None,
            };
            if let Some(target) = target {
                if let Some(site) = self.first_site_in_block(target)? {
                    targets.insert(site);
                }
            }
        }
        for &target in self.pc_relative_ldimm64_targets.values() {
            if let Some(site) = self.first_site_in_block(target)? {
                targets.insert(site);
            }
        }
        Ok(targets)
    }

    pub fn first_site_in_block(&self, block: BlockId) -> anyhow::Result<Option<InsnSite>> {
        Ok(self.logical_sites_in_block(block)?.into_iter().next())
    }

    pub fn next_site_in_linear_order(&self, site: InsnSite) -> anyhow::Result<Option<InsnSite>> {
        let sites = self.current_sites()?;
        let pos = sites
            .iter()
            .position(|candidate| *candidate == site)
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))?;
        Ok(sites.get(pos + 1).copied())
    }

    pub fn sites_in_linear_pc_range(
        &self,
        start_pc: usize,
        end_pc: usize,
    ) -> anyhow::Result<Vec<(usize, InsnSite)>> {
        let site_pcs = current_site_pcs(self)?;
        let mut sites = site_pcs
            .into_iter()
            .filter(|(_, pc)| *pc >= start_pc && *pc < end_pc)
            .map(|(site, pc)| (pc, site))
            .collect::<Vec<_>>();
        sites.sort_by_key(|(pc, _)| *pc);
        Ok(sites)
    }

    pub fn sites_in_block_slot_range(
        &self,
        block: BlockId,
        range: Range<usize>,
    ) -> anyhow::Result<Vec<InsnSite>> {
        self.block(block)?;
        let mut sites = Vec::new();
        for slot in range {
            let site = self.site_for_block_slot(block, slot)?;
            if !sites.contains(&site) {
                sites.push(site);
            }
        }
        Ok(sites)
    }

    pub fn insn_at(&self, site: InsnSite) -> Option<&BpfInsn> {
        let block = self.blocks.get(site.block.0)?;
        if site.idx < block.insns.len() {
            return block.insns.get(site.idx);
        }
        (site.idx == block.insns.len())
            .then(|| block.terminator.raw_insn())
            .flatten()
    }

    pub fn ldimm64_second_slot(&self, site: InsnSite) -> Option<&BpfInsn> {
        self.ldimm64_second_slots.get(&site)
    }

    pub fn block_start_pc(&self, block: BlockId) -> anyhow::Result<usize> {
        self.block(block)?;
        Ok(current_block_start_pcs(self)?[block.0])
    }

    pub fn kinsn_replacement_subprog_skip_reason(
        &self,
        block: BlockId,
        start_slot: usize,
        old_len: usize,
        replacement_len: usize,
    ) -> anyhow::Result<Option<String>> {
        if old_len == 0 {
            anyhow::bail!(
                "kinsn replacement in {:?} at slot {start_slot} has zero old length",
                block
            );
        }
        if replacement_len == 0 {
            anyhow::bail!(
                "kinsn replacement in {:?} at slot {start_slot} has zero replacement length",
                block
            );
        }
        let block_ref = self.block(block)?;
        let frame = block_ref.frame;
        let frame_start_slot = self.frame_relative_slot(block, start_slot)?;
        let old_end = frame_start_slot
            .checked_add(old_len)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement old range overflows"))?;
        let replacement_end = frame_start_slot
            .checked_add(replacement_len)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement new range overflows"))?;

        let mut frame_start_slot_abs = usize::MAX;
        let mut frame_end_slot_abs = 0usize;
        for frame_block in self.blocks().filter(|candidate| candidate.frame == frame) {
            let block_start = self.frame_relative_slot(frame_block.id, 0)?;
            let block_end = block_start + self.block_slot_len(frame_block.id)?;
            frame_start_slot_abs = frame_start_slot_abs.min(block_start);
            frame_end_slot_abs = frame_end_slot_abs.max(block_end);
        }
        if frame_start_slot_abs == usize::MAX {
            anyhow::bail!("frame {:?} for block {:?} has no blocks", frame, block);
        }

        if old_end > frame_end_slot_abs {
            return Ok(Some(format!(
                "kinsn site crosses subprog boundary (site {frame_start_slot}..{old_end}, subprog {frame_start_slot_abs}..{frame_end_slot_abs})"
            )));
        }
        if replacement_end > frame_end_slot_abs {
            return Ok(Some(format!(
                "kinsn replacement crosses subprog boundary (replacement {frame_start_slot}..{replacement_end}, subprog {frame_start_slot_abs}..{frame_end_slot_abs})"
            )));
        }
        Ok(None)
    }

    pub fn block_slot_len(&self, block: BlockId) -> anyhow::Result<usize> {
        let block_ref = self.block(block)?;
        let mut len = 0usize;
        for idx in 0..block_ref.insns.len() {
            len += self.insn_slot_width(InsnSite { block, idx })?;
        }
        if block_ref.terminator.raw_insn().is_some() {
            len += 1;
        }
        Ok(len)
    }

    pub fn block_slot_bounds(&self, block: BlockId) -> anyhow::Result<(usize, usize)> {
        let start = self.block_start_pc(block)?;
        let len = self.block_slot_len(block)?;
        Ok((start, start + len))
    }

    pub fn frame_relative_slot(&self, block: BlockId, slot: usize) -> anyhow::Result<usize> {
        let frame = self.block(block)?.frame;
        let mut offset = 0usize;
        for candidate in self.blocks().filter(|candidate| candidate.frame == frame) {
            if candidate.id == block {
                return offset
                    .checked_add(slot)
                    .ok_or_else(|| anyhow::anyhow!("frame-relative slot {slot} overflows"));
            }
            offset = offset
                .checked_add(self.block_slot_len(candidate.id)?)
                .ok_or_else(|| anyhow::anyhow!("frame-relative block offset overflows"))?;
        }
        anyhow::bail!("block {:?} is missing from its frame", block)
    }

    pub fn remap_block_after_insert(
        block: BlockId,
        split_head: BlockId,
        split_tail: BlockId,
    ) -> BlockId {
        if block == split_head {
            split_tail
        } else if block.0 >= split_tail.0 {
            BlockId(block.0 + 1)
        } else {
            block
        }
    }

    pub fn remap_block_after_remove(
        block: BlockId,
        removed: &[BlockId],
    ) -> anyhow::Result<BlockId> {
        if removed.contains(&block) {
            anyhow::bail!("target block {:?} was removed", block);
        }
        let shift = removed.iter().filter(|removed| removed.0 < block.0).count();
        Ok(BlockId(block.0 - shift))
    }

    pub fn frame_slot_bounds(&self, frame: FrameId) -> anyhow::Result<(usize, usize)> {
        let mut start = usize::MAX;
        let mut end = 0usize;
        for block in self.blocks().filter(|block| block.frame == frame) {
            let (block_start, block_end) = self.block_slot_bounds(block.id)?;
            start = start.min(block_start);
            end = end.max(block_end);
        }
        if start == usize::MAX {
            anyhow::bail!("frame {:?} has no blocks", frame);
        }
        Ok((start, end))
    }

    pub fn program_slot_len(&self) -> anyhow::Result<usize> {
        self.blocks().try_fold(
            0usize,
            |len, block| Ok(len + self.block_slot_len(block.id)?),
        )
    }

    pub fn block_range_for_slots(
        &self,
        block: BlockId,
        start_slot: usize,
        old_len: usize,
    ) -> anyhow::Result<std::ops::Range<usize>> {
        if old_len == 0 {
            anyhow::bail!(
                "block {:?} replacement at slot {} has zero old length",
                block,
                start_slot
            );
        }
        let end_slot = start_slot
            .checked_add(old_len - 1)
            .ok_or_else(|| anyhow::anyhow!("slot range at {start_slot} overflows"))?;
        let start = self.site_for_block_slot(block, start_slot)?;
        let end = self.site_for_block_slot(block, end_slot)?;
        if start.block != block || end.block != block {
            anyhow::bail!(
                "slot range {}..{} does not stay in block {:?}",
                start_slot,
                end_slot + 1,
                block
            );
        }
        Ok(start.idx..end.idx + 1)
    }

    pub fn site_for_block_slot(&self, block: BlockId, slot: usize) -> anyhow::Result<InsnSite> {
        let block_ref = self.block(block)?;
        let mut current = 0usize;
        for idx in 0..block_ref.insns.len() {
            let site = InsnSite { block, idx };
            let width = self.insn_slot_width(site)?;
            if slot >= current && slot < current + width {
                return Ok(site);
            }
            current += width;
        }
        anyhow::bail!(
            "block {:?} has no logical instruction site for body slot {}",
            block,
            slot
        )
    }

    pub fn absolute_pc_for_block_slot(&self, block: BlockId, slot: usize) -> anyhow::Result<usize> {
        self.block_start_pc(block)?
            .checked_add(slot)
            .ok_or_else(|| anyhow::anyhow!("absolute pc for slot {slot} overflows"))
    }

    pub fn is_terminator_site(&self, site: InsnSite) -> anyhow::Result<bool> {
        let block = self.block(site.block)?;
        Ok(site.idx == block.insns.len() && block.terminator.raw_insn().is_some())
    }

    pub fn sites_in_block_pc_range(
        &self,
        site_pcs: &BTreeMap<InsnSite, usize>,
        block: BlockId,
        start_pc: usize,
        end_pc: usize,
    ) -> anyhow::Result<Vec<(usize, InsnSite)>> {
        let mut sites = Vec::new();
        for site in self.sites_in_block_with_terminator(block)? {
            let pc = site_pcs
                .get(&site)
                .copied()
                .ok_or_else(|| anyhow::anyhow!("current pc missing for {:?}", site))?;
            if pc >= start_pc && pc < end_pc {
                sites.push((pc, site));
            }
        }
        sites.sort_by_key(|(pc, _)| *pc);
        Ok(sites)
    }

    pub fn sites_in_frame_pc_range(
        &self,
        site_pcs: &BTreeMap<InsnSite, usize>,
        frame: FrameId,
        start_pc: usize,
        end_pc: usize,
    ) -> anyhow::Result<Vec<(usize, InsnSite)>> {
        let mut sites = Vec::new();
        for block in self.blocks().filter(|block| block.frame == frame) {
            sites.extend(self.sites_in_block_pc_range(site_pcs, block.id, start_pc, end_pc)?);
        }
        sites.sort_by_key(|(pc, _)| *pc);
        Ok(sites)
    }

    pub fn site_at_current_pc(
        &self,
        site_pcs: &BTreeMap<InsnSite, usize>,
        pc: usize,
    ) -> anyhow::Result<Option<InsnSite>> {
        let mut matches = site_pcs
            .iter()
            .filter_map(|(&site, &site_pc)| (site_pc == pc).then_some(site));
        let Some(site) = matches.next() else {
            return Ok(None);
        };
        if matches.next().is_some() {
            anyhow::bail!("current pc {pc} maps to multiple instruction sites");
        }
        Ok(Some(site))
    }

    pub fn site_for_original_pc(&self, pc: usize) -> anyhow::Result<InsnSite> {
        self.btf
            .iter()
            .find_map(|(&site, &orig_pc)| (orig_pc == pc).then_some(site))
            .ok_or_else(|| anyhow::anyhow!("original pc {pc} is not present in BBProgram"))
    }

    pub fn block_for_original_pc(&self, pc: usize) -> anyhow::Result<BlockId> {
        Ok(self.site_for_original_pc(pc)?.block)
    }

    pub fn insn_slot_width(&self, site: InsnSite) -> anyhow::Result<usize> {
        let insn = self
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("invalid instruction site {:?}", site))?;
        if insn.is_ldimm64() {
            if !self.ldimm64_second_slots.contains_key(&site) {
                anyhow::bail!("LD_IMM64 at {:?} is missing its second slot", site);
            }
            Ok(2)
        } else {
            Ok(1)
        }
    }

    pub(crate) fn rebuild_cfg_edges(&mut self) -> anyhow::Result<()> {
        self.successors = vec![Vec::new(); self.blocks.len()];
        self.predecessors = vec![Vec::new(); self.blocks.len()];

        for block in &self.blocks {
            let from = block.id;
            for succ in block.terminator.successors() {
                if succ.0 >= self.blocks.len() {
                    anyhow::bail!(
                        "block {:?} terminator references invalid successor {:?}",
                        from,
                        succ
                    );
                }
                self.successors[from.0].push(succ);
                self.predecessors[succ.0].push(from);
            }
        }

        for edges in &mut self.successors {
            edges.sort_unstable();
            edges.dedup();
        }
        for edges in &mut self.predecessors {
            edges.sort_unstable();
            edges.dedup();
        }
        Ok(())
    }

    pub(crate) fn rebuild_use_def(&mut self) -> anyhow::Result<()> {
        self.use_def = UseDefGraph::build(self)?;
        Ok(())
    }

    pub fn attach_side_inputs(
        &mut self,
        insns: &[BpfInsn],
        map_ids: Vec<u32>,
        func_info: Option<BtfInfoRecords>,
        line_info: Option<BtfInfoRecords>,
    ) -> anyhow::Result<()> {
        self.map_bindings = collect_map_bindings(insns, &map_ids)?;
        self.map_ids = map_ids;
        self.func_info = func_info;
        self.line_info = line_info;
        Ok(())
    }

    pub(crate) fn invalidate_oracle(&mut self) {
        self.oracle = None;
    }

    pub fn reset_btf_to_current_pcs(&mut self) -> anyhow::Result<()> {
        self.btf = current_site_pcs(self)?;
        Ok(())
    }

    pub(crate) fn rebuild_use_def_after_mutation(&mut self) -> anyhow::Result<()> {
        self.rebuild_use_def()?;
        self.invalidate_oracle();
        Ok(())
    }

    pub fn remapped_func_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_for_lowering(self, self.func_info.as_ref(), BtfRecordKind::Func)
    }

    pub fn remapped_line_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_for_lowering(self, self.line_info.as_ref(), BtfRecordKind::Line)
    }

    pub(crate) fn block(&self, block: BlockId) -> anyhow::Result<&Block> {
        self.blocks
            .get(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))
    }

    pub(crate) fn block_mut(&mut self, block: BlockId) -> anyhow::Result<&mut Block> {
        self.blocks
            .get_mut(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))
    }

    pub(crate) fn logical_sites_in_block(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
        Ok(logical_sites_for_block(self.block(block)?))
    }

    pub(crate) fn dataflow_successors(&self, block: BlockId) -> anyhow::Result<Vec<BlockId>> {
        let block_ref = self
            .blocks
            .get(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))?;
        Ok(block_ref.terminator.dataflow_successors())
    }

    pub(crate) fn shift_metadata_after_insert<T>(
        map: &mut BTreeMap<InsnSite, T>,
        block: BlockId,
        at: usize,
        delta: usize,
    ) {
        let old = std::mem::take(map);
        *map = old
            .into_iter()
            .map(|(mut site, value)| {
                if site.block == block && site.idx >= at {
                    site.idx += delta;
                }
                (site, value)
            })
            .collect();
    }

    pub(crate) fn shift_metadata_after_delete<T>(
        map: &mut BTreeMap<InsnSite, T>,
        block: BlockId,
        at: usize,
        deleted: usize,
    ) {
        let old = std::mem::take(map);
        *map = old
            .into_iter()
            .filter_map(|(mut site, value)| {
                if site.block == block {
                    if (at..at + deleted).contains(&site.idx) {
                        return None;
                    }
                    if site.idx >= at + deleted {
                        site.idx -= deleted;
                    }
                }
                Some((site, value))
            })
            .collect();
    }
}

fn collect_map_bindings(insns: &[BpfInsn], map_ids: &[u32]) -> anyhow::Result<Vec<BBMapBinding>> {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if let Some(kind) = insn.map_pseudo_kind() {
            let map_id = resolve_map_id(kind, insn.imm, map_ids, &mut fd_order)?;
            if let Some(map_id) = map_id {
                bindings.push(BBMapBinding {
                    old_fd: insn.imm,
                    map_id,
                });
            }
        }
        pc += insn_width(&insn);
    }

    Ok(bindings)
}

fn resolve_map_id(
    kind: MapPseudo,
    imm: i32,
    map_ids: &[u32],
    fd_order: &mut Vec<i32>,
) -> anyhow::Result<Option<u32>> {
    if kind.uses_index() {
        let index = usize::try_from(imm)
            .map_err(|_| anyhow::anyhow!("negative canonical map index {imm}"))?;
        return Ok(map_ids.get(index).copied());
    }

    if !fd_order.contains(&imm) {
        fd_order.push(imm);
    }
    let index = fd_order
        .iter()
        .position(|fd| *fd == imm)
        .ok_or_else(|| anyhow::anyhow!("failed to resolve map fd order for fd {imm}"))?;
    Ok(map_ids.get(index).copied())
}

impl Terminator {
    pub fn raw_insn(&self) -> Option<&BpfInsn> {
        match self {
            Self::Jump { insn, .. } => Some(insn),
            Self::CondBranch { cond, .. } => Some(cond),
            Self::Call { call, .. } => Some(call),
            Self::Exit { insn } => Some(insn),
            Self::Fallthrough { .. } | Self::End => None,
        }
    }

    pub fn successors(&self) -> Vec<BlockId> {
        match *self {
            Self::Fallthrough { next } | Self::Jump { target: next, .. } => vec![next],
            Self::CondBranch {
                taken, fallthrough, ..
            } => {
                if taken == fallthrough {
                    vec![taken]
                } else {
                    vec![taken, fallthrough]
                }
            }
            Self::Call {
                callee, return_to, ..
            } => {
                if callee == return_to {
                    vec![callee]
                } else {
                    vec![callee, return_to]
                }
            }
            Self::Exit { .. } | Self::End => Vec::new(),
        }
    }

    pub(crate) fn dataflow_successors(&self) -> Vec<BlockId> {
        match *self {
            Self::Fallthrough { next } | Self::Jump { target: next, .. } => vec![next],
            Self::CondBranch {
                taken, fallthrough, ..
            } => {
                if taken == fallthrough {
                    vec![taken]
                } else {
                    vec![taken, fallthrough]
                }
            }
            Self::Call { return_to, .. } => vec![return_to],
            Self::Exit { .. } | Self::End => Vec::new(),
        }
    }
}

pub(crate) fn range_len(range: &Range<usize>) -> anyhow::Result<usize> {
    range
        .end
        .checked_sub(range.start)
        .ok_or_else(|| anyhow::anyhow!("invalid descending range {:?}", range))
}

#[derive(Clone, Debug)]
pub struct Dominance {
    dominators: Vec<BTreeSet<BlockId>>,
}

impl Dominance {
    fn compute(prog: &BBProgram) -> Self {
        let all = prog
            .blocks
            .iter()
            .map(|block| block.id)
            .collect::<BTreeSet<_>>();
        let mut dominators = vec![all.clone(); prog.blocks.len()];
        if prog.entry.0 < dominators.len() {
            dominators[prog.entry.0] = BTreeSet::from([prog.entry]);
        }

        let mut changed = true;
        while changed {
            changed = false;
            for block in prog.blocks() {
                if block.id == prog.entry {
                    continue;
                }
                let preds = prog.predecessors(block.id);
                let mut next = if let Some((&first, rest)) = preds.split_first() {
                    let mut acc = dominators[first.0].clone();
                    for pred in rest {
                        acc = acc
                            .intersection(&dominators[pred.0])
                            .copied()
                            .collect::<BTreeSet<_>>();
                    }
                    acc
                } else {
                    BTreeSet::new()
                };
                next.insert(block.id);
                if next != dominators[block.id.0] {
                    dominators[block.id.0] = next;
                    changed = true;
                }
            }
        }

        Self { dominators }
    }

    pub fn dominates(&self, dominator: BlockId, block: BlockId) -> bool {
        self.dominators
            .get(block.0)
            .is_some_and(|set| set.contains(&dominator))
    }
}

#[derive(Clone, Debug, Default)]
pub struct ReachingDefs {
    defs: BTreeMap<u8, Vec<DefSite>>,
}

impl ReachingDefs {
    pub fn defs_for(&self, reg: u8) -> impl Iterator<Item = DefSite> + '_ {
        self.defs
            .get(&reg)
            .into_iter()
            .flat_map(|defs| defs.iter().copied())
    }
}

fn current_site_pcs(prog: &BBProgram) -> anyhow::Result<BTreeMap<InsnSite, usize>> {
    let mut pcs = BTreeMap::new();
    let mut pc = 0usize;
    for block in prog.blocks() {
        for idx in 0..block.insns.len() {
            let site = InsnSite {
                block: block.id,
                idx,
            };
            pcs.insert(site, pc);
            pc += prog.insn_slot_width(site)?;
        }
        if block.terminator.raw_insn().is_some() {
            pcs.insert(
                InsnSite {
                    block: block.id,
                    idx: block.insns.len(),
                },
                pc,
            );
            pc += 1;
        }
    }
    Ok(pcs)
}

fn current_block_start_pcs(prog: &BBProgram) -> anyhow::Result<Vec<usize>> {
    let mut block_start_pc = vec![0usize; prog.blocks.len()];
    let mut pc = 0usize;
    for block in prog.blocks() {
        block_start_pc[block.id.0] = pc;
        for idx in 0..block.insns.len() {
            pc += prog.insn_slot_width(InsnSite {
                block: block.id,
                idx,
            })?;
        }
        if block.terminator.raw_insn().is_some() {
            pc += 1;
        }
    }
    Ok(block_start_pc)
}

fn logical_sites_for_block(block: &Block) -> Vec<InsnSite> {
    let mut sites = (0..block.insns.len())
        .map(|idx| InsnSite {
            block: block.id,
            idx,
        })
        .collect::<Vec<_>>();
    if block.terminator.raw_insn().is_some() {
        sites.push(InsnSite {
            block: block.id,
            idx: block.insns.len(),
        });
    }
    sites
}

#[derive(Clone, Debug, Default)]
struct LivenessSets {
    live_in: HashMap<BlockId, RegSet>,
    live_out: HashMap<BlockId, RegSet>,
}

#[derive(Clone, Debug, Default)]
struct SiteLivenessSets {
    live_out: HashMap<InsnSite, RegSet>,
}

fn compute_liveness(prog: &BBProgram) -> LivenessSets {
    let mut use_sets = HashMap::<BlockId, RegSet>::new();
    let mut def_sets = HashMap::<BlockId, RegSet>::new();
    let mut kinsn_uses = HashMap::<BlockId, RegSet>::new();

    for block in prog.blocks() {
        let mut uses = RegSet::new();
        let mut defs = RegSet::new();
        let mut implicit = RegSet::new();
        for site in logical_sites_for_block(block) {
            let site_uses = prog
                .use_def
                .uses
                .keys()
                .filter(|use_site| use_site.block == site.block && use_site.idx == site.idx)
                .map(|use_site| use_site.reg)
                .collect::<RegSet>();
            for reg in site_uses {
                if !defs.contains(&reg) {
                    uses.insert(reg);
                }
                if prog.insn_at(site).is_some_and(|insn| insn.is_call_kinsn()) {
                    implicit.insert(reg);
                }
            }
            for def in prog
                .use_def
                .defs
                .keys()
                .filter(|def| def.block == site.block && def.idx == site.idx)
            {
                defs.insert(def.reg);
            }
        }
        use_sets.insert(block.id, uses);
        def_sets.insert(block.id, defs);
        kinsn_uses.insert(block.id, implicit);
    }

    let mut live_in = HashMap::<BlockId, RegSet>::new();
    let mut live_out = HashMap::<BlockId, RegSet>::new();
    for block in prog.blocks() {
        live_in.insert(block.id, RegSet::new());
        live_out.insert(block.id, RegSet::new());
    }

    let mut changed = true;
    while changed {
        changed = false;
        for block in prog.blocks().collect::<Vec<_>>().into_iter().rev() {
            let mut out = RegSet::new();
            for succ in prog.successors(block.id) {
                if let Some(succ_in) = live_in.get(succ) {
                    out.extend(succ_in.iter().copied());
                }
            }
            let mut input = out
                .difference(&def_sets[&block.id])
                .copied()
                .collect::<RegSet>();
            input.extend(use_sets[&block.id].iter().copied());
            let mut public_out = out;
            public_out.extend(kinsn_uses[&block.id].iter().copied());
            if live_in.get(&block.id) != Some(&input)
                || live_out.get(&block.id) != Some(&public_out)
            {
                live_in.insert(block.id, input);
                live_out.insert(block.id, public_out);
                changed = true;
            }
        }
    }

    LivenessSets { live_in, live_out }
}

fn compute_site_liveness(prog: &BBProgram) -> anyhow::Result<SiteLivenessSets> {
    let mut sites = Vec::new();
    let mut use_sets = HashMap::<InsnSite, RegSet>::new();
    let mut def_sets = HashMap::<InsnSite, RegSet>::new();

    for block in prog.blocks() {
        for site in logical_sites_for_block(block) {
            sites.push(site);
            use_sets.insert(
                site,
                prog.use_def
                    .uses
                    .keys()
                    .filter(|use_site| use_site.block == site.block && use_site.idx == site.idx)
                    .map(|use_site| use_site.reg)
                    .collect(),
            );
            def_sets.insert(
                site,
                prog.use_def
                    .defs
                    .keys()
                    .filter(|def| def.block == site.block && def.idx == site.idx)
                    .map(|def| def.reg)
                    .collect(),
            );
        }
    }

    let mut live_in = sites
        .iter()
        .copied()
        .map(|site| (site, RegSet::new()))
        .collect::<HashMap<_, _>>();
    let mut live_out = live_in.clone();

    let mut changed = true;
    while changed {
        changed = false;
        for &site in sites.iter().rev() {
            let mut out = RegSet::new();
            for succ in site_successors(prog, site)? {
                if let Some(succ_in) = live_in.get(&succ) {
                    out.extend(succ_in.iter().copied());
                }
            }
            let mut input = out
                .difference(&def_sets[&site])
                .copied()
                .collect::<RegSet>();
            input.extend(use_sets[&site].iter().copied());
            if live_in.get(&site) != Some(&input) || live_out.get(&site) != Some(&out) {
                live_in.insert(site, input);
                live_out.insert(site, out);
                changed = true;
            }
        }
    }

    Ok(SiteLivenessSets { live_out })
}

fn site_successors(prog: &BBProgram, site: InsnSite) -> anyhow::Result<Vec<InsnSite>> {
    let block = prog.block(site.block)?;
    if site.idx < block.insns.len() {
        if site.idx + 1 < block.insns.len() {
            return Ok(vec![InsnSite {
                block: site.block,
                idx: site.idx + 1,
            }]);
        }
        if block.terminator.raw_insn().is_some() {
            return Ok(vec![InsnSite {
                block: site.block,
                idx: block.insns.len(),
            }]);
        }
    }
    let mut successors = Vec::new();
    for succ in block.terminator.dataflow_successors() {
        successors.extend(first_logical_sites(prog, succ, &mut BTreeSet::new())?);
    }
    Ok(successors)
}

fn first_logical_sites(
    prog: &BBProgram,
    block: BlockId,
    visited: &mut BTreeSet<BlockId>,
) -> anyhow::Result<Vec<InsnSite>> {
    if !visited.insert(block) {
        return Ok(Vec::new());
    }
    let block_ref = prog.block(block)?;
    let sites = logical_sites_for_block(block_ref);
    if let Some(site) = sites.first().copied() {
        return Ok(vec![site]);
    }
    let mut successors = Vec::new();
    for succ in block_ref.terminator.dataflow_successors() {
        successors.extend(first_logical_sites(prog, succ, visited)?);
    }
    Ok(successors)
}
