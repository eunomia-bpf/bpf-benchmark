// SPDX-License-Identifier: MIT
//! Basic-block program representation for bpfopt pass execution.
use crate::analysis::bbprogram_btf::BtfRecordKind;
#[cfg(test)]
use crate::analysis::bbprogram_btf::{remap_btf_records_view, BtfRemapView};
use crate::analysis::bbprogram_lower::remap_btf_records_for_lowering;
use crate::analysis::{DefSite, UseDefGraph};
use crate::insn::{insn_width, BpfInsn, MapPseudo};
use crate::pass::{
    BtfInfoRecords, InsnAnnotation, KinsnRegistry, PmuRecord, PrefetchProfile, ProfilingData,
    RegSet, VerifierInsn,
};
use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ops::Range;
use std::sync::Arc;
pub type VerifierOracle = BTreeMap<InsnSite, Arc<[VerifierInsn]>>;
pub type BtfMetadataMap = BTreeMap<InsnSite, usize>;
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct BlockId(pub usize);
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct FrameId(pub usize);
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct InsnSite {
    pub block: BlockId,
    pub(super) idx: usize,
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct BBMapBinding {
    pub old_fd: i32,
    pub map_id: u32,
}
#[derive(Clone, Debug)]
pub struct BBProgram {
    pub(super) blocks: Vec<Block>,
    pub(crate) entry: BlockId,
    pub(super) use_def: UseDefGraph,
    pub(super) oracle: Option<VerifierOracle>,
    pub(super) pmu_profile: BTreeMap<InsnSite, PmuRecord>,
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
            pmu_profile: BTreeMap::new(),
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
    pub fn entry(&self) -> BlockId {
        self.entry
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
    pub fn block_body_insns(
        &self,
        block: BlockId,
    ) -> anyhow::Result<impl Iterator<Item = (InsnSite, &BpfInsn)> + '_> {
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
    pub fn oracle(&self) -> Option<&VerifierOracle> {
        self.oracle.as_ref()
    }
    pub fn oracle_at(&self, site: InsnSite) -> Option<&VerifierInsn> {
        self.oracle.as_ref()?.get(&site)?.first()
    }
    pub(crate) fn verifier_states_at(&self, site: InsnSite) -> Option<&[VerifierInsn]> {
        self.oracle.as_ref()?.get(&site).map(AsRef::as_ref)
    }
    pub fn profile_at(&self, site: InsnSite) -> Option<&PmuRecord> {
        self.pmu_profile.get(&site)
    }
    pub(crate) fn attach_profile_from_annotations(
        &mut self,
        annotations: &[InsnAnnotation],
    ) -> anyhow::Result<()> {
        let profiles = annotations
            .iter()
            .enumerate()
            .filter(|(_, annotation)| {
                annotation.branch_profile.is_some() || annotation.prefetch_profile.is_some()
            })
            .map(|(pc, annotation)| (pc, annotation.clone()))
            .collect::<HashMap<_, _>>();
        self.attach_pmu_records_from_original_pcs(&profiles)
    }
    pub(crate) fn attach_prefetch_profile_from_original_pcs(
        &mut self,
        profiles: &HashMap<usize, PrefetchProfile>,
    ) -> anyhow::Result<()> {
        let records = profiles
            .iter()
            .map(|(&pc, profile)| {
                (
                    pc,
                    PmuRecord {
                        prefetch_profile: Some(profile.clone()),
                        ..Default::default()
                    },
                )
            })
            .collect::<HashMap<_, _>>();
        self.attach_pmu_records_from_original_pcs(&records)
    }
    pub(crate) fn attach_profile_data(&mut self, profile: &ProfilingData) -> anyhow::Result<()> {
        if profile.branch_profiles.is_empty() {
            return self.attach_prefetch_profile_from_original_pcs(&profile.prefetch_profiles);
        }
        let mut records = HashMap::<usize, PmuRecord>::new();
        for (&pc, branch_profile) in &profile.branch_profiles {
            records.entry(pc).or_default().branch_profile = Some(branch_profile.clone());
        }
        for (&pc, prefetch_profile) in &profile.prefetch_profiles {
            records.entry(pc).or_default().prefetch_profile = Some(prefetch_profile.clone());
        }
        self.attach_pmu_records_from_original_pcs(&records)
    }
    fn attach_pmu_records_from_original_pcs(
        &mut self,
        profiles: &HashMap<usize, PmuRecord>,
    ) -> anyhow::Result<()> {
        self.pmu_profile.clear();
        for (&pc, profile) in profiles {
            let site = self
                .original_pc_to_site(pc)
                .ok_or_else(|| anyhow::anyhow!("profile pc {pc} is not present in BBProgram"))?;
            self.pmu_profile.insert(site, profile.clone());
        }
        Ok(())
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
    pub fn subprog_blocks(&self, frame: FrameId) -> impl Iterator<Item = BlockId> + '_ {
        self.blocks
            .iter()
            .filter(move |block| block.frame == frame)
            .map(|block| block.id)
    }
    #[cfg(test)]
    pub fn btf_records(&self) -> BtfRemapView {
        self.btf_records_checked()
            .unwrap_or_else(|err| panic!("BBProgram BTF remap should be valid: {err}"))
    }
    #[cfg(test)]
    pub fn btf_records_checked(&self) -> anyhow::Result<BtfRemapView> {
        Ok(BtfRemapView {
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
    pub fn original_pc(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.btf
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("site {:?} has no original-PC mapping", site))
    }
    pub fn original_pc_to_site(&self, pc: usize) -> Option<InsnSite> {
        self.btf
            .iter()
            .find_map(|(&site, &original_pc)| (original_pc == pc).then_some(site))
    }
    pub fn site_current_pc(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.current_site_pcs()?
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))
    }
    pub fn first_site_in_block(&self, block: BlockId) -> anyhow::Result<Option<InsnSite>> {
        Ok(self.logical_sites_in_block(block)?.into_iter().next())
    }
    pub fn block_entry_site(&self, block: BlockId) -> anyhow::Result<InsnSite> {
        self.first_site_in_block(block)?
            .ok_or_else(|| anyhow::anyhow!("block {:?} has no entry instruction site", block))
    }
    pub fn terminator_site(&self, block: BlockId) -> anyhow::Result<Option<InsnSite>> {
        let block_ref = self.block(block)?;
        Ok(block_ref.terminator.raw_insn().map(|_| InsnSite {
            block,
            idx: block_ref.insns.len(),
        }))
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
    pub fn insn(&self, site: InsnSite) -> anyhow::Result<&BpfInsn> {
        self.insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("no instruction at BBProgram site {:?}", site))
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
    pub fn is_terminator_site(&self, site: InsnSite) -> anyhow::Result<bool> {
        let block = self.block(site.block)?;
        Ok(site.idx == block.insns.len() && block.terminator.raw_insn().is_some())
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
        self.pmu_profile.clear();
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
    pub(super) fn block(&self, block: BlockId) -> anyhow::Result<&Block> {
        self.blocks
            .get(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))
    }
    pub(super) fn block_mut(&mut self, block: BlockId) -> anyhow::Result<&mut Block> {
        self.blocks
            .get_mut(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))
    }
    pub(super) fn logical_sites_in_block(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
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
impl BBProgram {
    pub(crate) fn bf_skip_reason(
        &self,
        site: InsnSite,
        reason: String,
    ) -> anyhow::Result<crate::pass::SiteSkipReason> {
        self.insn(site)?;
        Ok(crate::pass::SiteSkipReason { site, reason })
    }

    pub(crate) fn bf_blocks_are_adjacent(
        &self,
        left: BlockId,
        right: BlockId,
    ) -> anyhow::Result<bool> {
        self.block(left)?;
        self.block(right)?;
        Ok(left.0 + 1 == right.0)
    }

    pub(crate) fn bf_block_range_has_body_site(
        &self,
        first: BlockId,
        last: BlockId,
    ) -> anyhow::Result<bool> {
        if first.0 > last.0 {
            anyhow::bail!(
                "branch_flip block range {:?}..={:?} is inverted",
                first,
                last
            );
        }
        for block in first.0..=last.0 {
            if !self.sites_in_block(BlockId(block))?.is_empty() {
                return Ok(true);
            }
        }
        Ok(false)
    }

    pub(crate) fn bf_validate_flipped_branch_deltas(
        &self,
        report_site: InsnSite,
        then_first: BlockId,
        then_last: BlockId,
        else_first: BlockId,
        else_last: BlockId,
        cond: BpfInsn,
    ) -> anyhow::Result<()> {
        let then_len = self.bf_block_range_body_slot_len(then_first, then_last)?;
        let else_len = self.bf_block_range_body_slot_len(else_first, else_last)?;
        let cond_delta = else_len.checked_add(1).ok_or_else(|| {
            anyhow::anyhow!(
                "branch_flip site {:?} else arm overflows branch delta",
                report_site
            )
        })?;
        let mut inverted = cond;
        inverted.set_branch_target_delta(i64::try_from(cond_delta).map_err(|_| {
            anyhow::anyhow!(
                "branch_flip site {:?} else arm length {} overflows branch delta",
                report_site,
                else_len
            )
        })?)?;
        let mut ja = BpfInsn::ja(0);
        ja.set_branch_target_delta(i64::try_from(then_len).map_err(|_| {
            anyhow::anyhow!(
                "branch_flip site {:?} then arm length {} overflows branch delta",
                report_site,
                then_len
            )
        })?)?;
        Ok(())
    }

    fn bf_block_range_body_slot_len(&self, first: BlockId, last: BlockId) -> anyhow::Result<usize> {
        if first.0 > last.0 {
            anyhow::bail!(
                "branch_flip block range {:?}..={:?} is inverted",
                first,
                last
            );
        }
        let mut len = 0usize;
        for block in first.0..=last.0 {
            for site in self.sites_in_block(BlockId(block))? {
                len = len
                    .checked_add(self.insn_slot_width(site)?)
                    .ok_or_else(|| anyhow::anyhow!("branch_flip arm slot length overflows"))?;
            }
        }
        Ok(len)
    }

    pub(crate) fn pf_attach_prefetch_profiles(
        &mut self,
        profiles: &BTreeMap<InsnSite, PrefetchProfile>,
    ) -> anyhow::Result<()> {
        self.pmu_profile.clear();
        for (&site, profile) in profiles {
            self.insn_at(site).ok_or_else(|| {
                anyhow::anyhow!("prefetch profile site {:?} is not present", site)
            })?;
            self.pmu_profile.insert(
                site,
                PmuRecord {
                    prefetch_profile: Some(profile.clone()),
                    ..Default::default()
                },
            );
        }
        Ok(())
    }

    pub(crate) fn pf_skip_reason(
        &self,
        site: InsnSite,
        reason: String,
    ) -> anyhow::Result<crate::pass::SiteSkipReason> {
        self.insn(site)?;
        Ok(crate::pass::SiteSkipReason { site, reason })
    }

    pub(crate) fn pf_sites_after_in_frame(
        &self,
        anchor: InsnSite,
        max_slots: usize,
    ) -> anyhow::Result<Vec<InsnSite>> {
        self.insn(anchor)?;
        let frame = self.block_frame(anchor.block)?;
        let scan_start = self.pf_site_end_slot(anchor)?;
        let scan_end = scan_start
            .checked_add(max_slots)
            .ok_or_else(|| anyhow::anyhow!("prefetch scan after {:?} overflows", anchor))?;
        let mut sites = Vec::new();
        for block in self.subprog_blocks(frame) {
            for site in self.sites_in_block_with_terminator(block)? {
                let site_start = self.pf_site_start_slot(site)?;
                if site_start < scan_start {
                    continue;
                }
                if site_start >= scan_end {
                    return Ok(sites);
                }
                sites.push(site);
            }
        }
        Ok(sites)
    }

    pub(crate) fn pf_prefetch_window_sites(
        &self,
        ptr_def: InsnSite,
        target: InsnSite,
        max_slots: usize,
    ) -> anyhow::Result<Vec<InsnSite>> {
        self.insn(ptr_def)?;
        self.insn(target)?;
        let frame = self.block_frame(target.block)?;
        if self.block_frame(ptr_def.block)? != frame {
            anyhow::bail!(
                "prefetch pointer definition {:?} and target {:?} are in different frames",
                ptr_def,
                target
            );
        }
        let (block_start, block_end) = self.block_slot_bounds(target.block)?;
        let (frame_start, frame_end) = self.frame_slot_bounds(frame)?;
        if block_start < frame_start || block_end > frame_end {
            anyhow::bail!(
                "prefetch block {:?} crosses frame {:?}: block {}..{}, frame {}..{}",
                target.block,
                frame,
                block_start,
                block_end,
                frame_start,
                frame_end
            );
        }
        let target_start = self.pf_site_start_slot(target)?;
        let ptr_def_end = self.pf_site_end_slot(ptr_def)?;
        let valid_start = block_start
            .max(target_start.saturating_sub(max_slots))
            .max(ptr_def_end);
        if valid_start > target_start {
            return Ok(Vec::new());
        }
        let mut sites = Vec::new();
        for site in self.sites_in_block(target.block)? {
            let site_start = self.pf_site_start_slot(site)?;
            if site_start >= valid_start && site_start <= target_start {
                sites.push(site);
            }
        }
        Ok(sites)
    }

    pub(crate) fn pf_nearest_prefetch_insert_site(
        &self,
        sites: &[InsnSite],
        target: InsnSite,
        ideal_distance: usize,
    ) -> anyhow::Result<Option<InsnSite>> {
        let ideal = self
            .pf_site_start_slot(target)?
            .saturating_sub(ideal_distance);
        let mut best = None;
        for &site in sites {
            let site_start = self.pf_site_start_slot(site)?;
            let distance = site_start.abs_diff(ideal);
            if best.is_none_or(|(best_distance, best_start, _)| {
                distance < best_distance || (distance == best_distance && site_start < best_start)
            }) {
                best = Some((distance, site_start, site));
            }
        }
        Ok(best.map(|(_, _, site)| site))
    }

    fn pf_site_start_slot(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.rep_site_slot(site)
    }

    fn pf_site_end_slot(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.pf_site_start_slot(site)?
            .checked_add(self.insn_slot_width(site)?)
            .ok_or_else(|| anyhow::anyhow!("prefetch site {:?} end slot overflows", site))
    }
}

impl BBProgram {
    pub fn rep_site_slot(&self, site: InsnSite) -> anyhow::Result<usize> {
        let mut offset = 0usize;
        for idx in 0..site.idx {
            offset += self.insn_slot_width(InsnSite {
                block: site.block,
                idx,
            })?;
        }
        Ok(self.block_slot_bounds(site.block)?.0 + offset)
    }

    pub fn rep_admit_kinsn_site_window(
        &self,
        start: InsnSite,
        old_len: usize,
        replacement_len: usize,
        skipped: &mut Vec<crate::pass::SiteSkipReason>,
    ) -> anyhow::Result<Option<(BlockId, Range<usize>)>> {
        let mut start_slot = 0usize;
        for idx in 0..start.idx {
            start_slot += self.insn_slot_width(InsnSite {
                block: start.block,
                idx,
            })?;
        }
        if let Some(reason) = self.kinsn_replacement_subprog_skip_reason(
            start.block,
            start_slot,
            old_len,
            replacement_len,
        )? {
            skipped.push(crate::pass::SiteSkipReason {
                site: start,
                reason,
            });
            return Ok(None);
        }
        Ok(Some((start.block, start.idx..start.idx + old_len)))
    }
}

impl BBProgram {
    pub fn bcm_sites_between(
        &self,
        start: InsnSite,
        end: InsnSite,
    ) -> anyhow::Result<Option<Vec<InsnSite>>> {
        let frame = self.block_frame(start.block)?;
        if self.block_frame(end.block)? != frame || !self.is_terminator_site(start)? {
            return Ok(None);
        }

        let Terminator::CondBranch { fallthrough, .. } = self.terminator(start.block)? else {
            return Ok(None);
        };

        let mut sites = Vec::new();
        let mut cursor = fallthrough;
        let mut visited = BTreeSet::new();
        loop {
            if !visited.insert(cursor) || self.block_frame(cursor)? != frame {
                return Ok(None);
            }

            for site in self.sites_in_block_with_terminator(cursor)? {
                if cursor == end.block && site == end {
                    return Ok(Some(sites));
                }
                sites.push(site);
            }

            let Terminator::Fallthrough { next } = self.terminator(cursor)? else {
                return Ok(None);
            };
            cursor = next;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::test_helpers::*;
    #[test]
    fn bbprogram_ja32_successor_uses_imm_target() {
        let insns = vec![
            BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        assert!(prog.successors(BlockId(0)).contains(&BlockId(2)));
        assert!(matches!(
            prog.blocks().next().unwrap().terminator,
            Terminator::Jump {
                target: BlockId(2),
                ..
            }
        ));
    }
    #[test]
    fn bbprogram_cond_branch_exposes_taken_and_fallthrough_edges() {
        let insns = vec![
            BpfInsn::jeq_imm(BPF_REG_1, 0, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
        assert!(matches!(
            prog.blocks().next().unwrap().terminator,
            Terminator::CondBranch {
                taken: BlockId(2),
                fallthrough: BlockId(1),
                ..
            }
        ));
    }
    #[test]
    fn bbprogram_pseudo_call_records_callee_and_return_blocks() {
        let insns = vec![
            BpfInsn::pseudo_call_to(0, 3),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        assert!(matches!(
            prog.blocks().next().unwrap().terminator,
            Terminator::Call {
                callee: BlockId(2),
                return_to: BlockId(1),
                ..
            }
        ));
        assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
    }
    #[test]
    fn bbprogram_predecessors_are_derived_from_symbolic_successors() {
        let insns = vec![
            BpfInsn::jeq_imm(BPF_REG_1, 0, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
        assert_eq!(prog.predecessors(BlockId(1)), &[BlockId(0)]);
        assert_eq!(prog.predecessors(BlockId(2)), &[BlockId(0), BlockId(1)]);
        let dom = prog.dominance();
        assert!(dom.dominates(BlockId(0), BlockId(1)));
        assert!(dom.dominates(BlockId(0), BlockId(2)));
    }
    #[test]
    fn bbprogram_cfg_edges_use_ja32_imm_target() {
        let insns = vec![
            BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        assert_eq!(prog.successors(BlockId(0)), &[BlockId(2)]);
        assert_eq!(prog.predecessors(BlockId(2)), &[BlockId(0)]);
    }
    #[test]
    fn bbprogram_subprog_blocks_cover_callback_body_range() {
        let insns = vec![
            BpfInsn::pseudo_call_to(0, 3),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_imm(BPF_REG_1, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ];
        let prog = lift_test_program(&insns, &pass_ctx());
        let callback_blocks = prog.subprog_blocks(FrameId(1)).collect::<Vec<_>>();
        assert_eq!(callback_blocks, vec![BlockId(2)]);
    }
    #[test]
    fn bbprogram_map_bindings_preserve_loader_fd_order() {
        let a = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, 11);
        let b = BpfInsn::ld_imm64(BPF_REG_2, BPF_PSEUDO_MAP_FD, 22);
        let mut ctx = pass_ctx();
        set_map_ids(&mut ctx, vec![101, 202]);
        let prog = lift_test_program(&[a[0], a[1], b[0], b[1], BpfInsn::exit()], &ctx);
        let bindings = prog.map_bindings();
        assert_eq!(bindings[0].old_fd, 11);
        assert_eq!(bindings[0].map_id, 101);
        assert_eq!(bindings[1].old_fd, 22);
        assert_eq!(bindings[1].map_id, 202);
    }
    #[test]
    fn bbprogram_map_bindings_survive_dead_pseudo_load_deletion() {
        let a = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, 11);
        let b = BpfInsn::ld_imm64(BPF_REG_2, BPF_PSEUDO_MAP_FD, 22);
        let mut ctx = pass_ctx();
        set_map_ids(&mut ctx, vec![101, 202]);
        let mut prog = lift_test_program(&[a[0], a[1], b[0], b[1], BpfInsn::exit()], &ctx);
        let def = prog
            .reaching_defs(BlockId(0))
            .defs_for(BPF_REG_1)
            .next()
            .expect("map fd r1 def should exist");
        prog.delete_insn(def)
            .expect("delete should keep stable binding");
        let bindings = prog.map_bindings();
        assert_eq!(bindings[0].old_fd, 11);
        assert_eq!(bindings[0].map_id, 101);
        assert_eq!(bindings[1].old_fd, 22);
        assert_eq!(bindings[1].map_id, 202);
    }
    #[test]
    fn bbprogram_sites_in_block_treats_ldimm64_as_one_logical_site() {
        let wide = BpfInsn::ld_imm64(BPF_REG_1, 0, 0x1_0000_0000);
        let prog = lift_test_program(&[wide[0], wide[1], BpfInsn::exit()], &pass_ctx());
        let sites = prog
            .sites_in_block(BlockId(0))
            .expect("valid block should enumerate body sites");
        assert_eq!(
            sites,
            vec![InsnSite {
                block: BlockId(0),
                idx: 0
            }]
        );
    }
    #[test]
    fn bbprogram_sites_in_block_excludes_terminator_from_body_iteration() {
        let prog = lift_test_program(
            &[
                BpfInsn::mov64_imm(BPF_REG_0, 0),
                BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
                BpfInsn::mov64_imm(BPF_REG_0, 1),
                BpfInsn::exit(),
            ],
            &pass_ctx(),
        );
        let sites = prog
            .sites_in_block(BlockId(0))
            .expect("valid block should enumerate body sites");
        assert_eq!(
            sites,
            vec![InsnSite {
                block: BlockId(0),
                idx: 0
            }]
        );
    }
    #[test]
    fn bbprogram_sites_can_include_terminators_when_requested() {
        let prog = lift_test_program(
            &[BpfInsn::jeq_imm(BPF_REG_0, 0, 1), BpfInsn::exit()],
            &pass_ctx(),
        );
        let sites = prog
            .sites_in_block_with_terminator(BlockId(0))
            .expect("valid block should enumerate logical sites");
        assert_eq!(
            sites,
            vec![InsnSite {
                block: BlockId(0),
                idx: 0
            }]
        );
    }
}

impl BBProgram {
    /// Returns the InsnSite at the start of a block's body, or None if empty.
    pub fn block_first_body_site(&self, block: BlockId) -> Option<InsnSite> {
        let block_ref = self.blocks.get(block.0)?;
        (!block_ref.insns.is_empty()).then_some(InsnSite { block, idx: 0 })
    }

    /// Returns the InsnSite immediately following `site` within the same block.
    /// Returns None if `site` is the last body site in its block.
    pub fn next_site_in_block(&self, site: InsnSite) -> Option<InsnSite> {
        let block_ref = self.blocks.get(site.block.0)?;
        let next_idx = site.idx.checked_add(1)?;
        (next_idx < block_ref.insns.len()).then_some(InsnSite {
            block: site.block,
            idx: next_idx,
        })
    }

    /// True iff `a` and `b` are in the same block and `b` immediately follows `a`.
    pub fn is_immediately_followed_by(&self, a: InsnSite, b: InsnSite) -> bool {
        self.next_site_in_block(a) == Some(b)
    }

    /// Iterator over adjacent body-site pairs within `block`.
    pub fn adjacent_pairs_in_block(
        &self,
        block: BlockId,
    ) -> impl Iterator<Item = (InsnSite, InsnSite)> + '_ {
        let pair_count = self
            .blocks
            .get(block.0)
            .map_or(0, |block_ref| block_ref.insns.len().saturating_sub(1));
        (0..pair_count).map(move |idx| {
            (
                InsnSite { block, idx },
                InsnSite {
                    block,
                    idx: idx + 1,
                },
            )
        })
    }

    /// Iterator over fixed-size adjacent body-site windows within `block`.
    /// Empty iterator if block body has fewer than N sites.
    pub fn adjacent_windows_in_block<const N: usize>(
        &self,
        block: BlockId,
    ) -> impl Iterator<Item = [InsnSite; N]> + '_ {
        let body_len = self
            .blocks
            .get(block.0)
            .map_or(0, |block_ref| block_ref.insns.len());
        let window_count = if N == 0 || body_len < N {
            0
        } else {
            body_len - N + 1
        };
        (0..window_count).map(move |start| {
            std::array::from_fn(|offset| InsnSite {
                block,
                idx: start + offset,
            })
        })
    }

    /// Replace-range helper that takes an InsnSite + length, hiding
    /// `idx..idx+len` arithmetic from passes.
    pub fn replace_range_at(
        &mut self,
        site: InsnSite,
        len: usize,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        let block_ref = self.block(site.block)?;
        if site.idx > block_ref.insns.len() {
            anyhow::bail!(
                "replace_range_at starts at {:?}, beyond block body length {}",
                site,
                block_ref.insns.len()
            );
        }
        let end = site
            .idx
            .checked_add(len)
            .ok_or_else(|| anyhow::anyhow!("replace_range_at at {:?} overflows", site))?;
        if end > block_ref.insns.len() {
            anyhow::bail!(
                "replace_range_at {:?} length {} exceeds block body length {}",
                site,
                len,
                block_ref.insns.len()
            );
        }
        self.replace_range(site.block, site.idx..end, replacement)
    }
}
