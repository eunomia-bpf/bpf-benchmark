// SPDX-License-Identifier: MIT
//! Basic-block program representation for staged bpfopt pass migration.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ops::Range;
use std::sync::Arc;

use crate::analysis::bbprogram_btf::{
    remap_btf_records_bytes, remap_btf_records_view, BtfRecordKind, BtfRecordsView,
};
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
pub struct BlockBodyLinearView {
    pub block: BlockId,
    pub start_pc: usize,
    pub insns: Vec<BpfInsn>,
    slot_to_site: BTreeMap<usize, InsnSite>,
}

impl BlockBodyLinearView {
    pub fn site_for_slot(&self, slot: usize) -> anyhow::Result<InsnSite> {
        self.slot_to_site.get(&slot).copied().ok_or_else(|| {
            anyhow::anyhow!(
                "block {:?} has no logical instruction site for body slot {}",
                self.block,
                slot
            )
        })
    }

    pub fn range_for_slots(
        &self,
        start_slot: usize,
        old_len: usize,
    ) -> anyhow::Result<Range<usize>> {
        if old_len == 0 {
            anyhow::bail!(
                "block {:?} replacement at slot {} has zero old length",
                self.block,
                start_slot
            );
        }
        let end_slot = start_slot
            .checked_add(old_len - 1)
            .ok_or_else(|| anyhow::anyhow!("slot range at {start_slot} overflows"))?;
        let start = self.site_for_slot(start_slot)?;
        let end = self.site_for_slot(end_slot)?;
        if start.block != self.block || end.block != self.block {
            anyhow::bail!(
                "slot range {}..{} does not stay in block {:?}",
                start_slot,
                end_slot + 1,
                self.block
            );
        }
        Ok(start.idx..end.idx + 1)
    }

    pub fn absolute_pc(&self, slot: usize) -> anyhow::Result<usize> {
        self.start_pc
            .checked_add(slot)
            .ok_or_else(|| anyhow::anyhow!("absolute pc for slot {slot} overflows"))
    }
}

#[derive(Clone, Debug)]
pub struct ProgramLinearView {
    pub insns: Vec<BpfInsn>,
    slot_to_site: BTreeMap<usize, InsnSite>,
}

impl ProgramLinearView {
    pub fn site_for_slot(&self, slot: usize) -> anyhow::Result<InsnSite> {
        self.slot_to_site
            .get(&slot)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("no logical instruction site for program slot {slot}"))
    }

    pub fn range_for_slots(
        &self,
        start_slot: usize,
        old_len: usize,
    ) -> anyhow::Result<(BlockId, Range<usize>)> {
        if old_len == 0 {
            anyhow::bail!("program replacement at slot {start_slot} has zero old length");
        }
        let end_slot = start_slot
            .checked_add(old_len - 1)
            .ok_or_else(|| anyhow::anyhow!("slot range at {start_slot} overflows"))?;
        let start = self.site_for_slot(start_slot)?;
        let end = self.site_for_slot(end_slot)?;
        if start.block != end.block {
            anyhow::bail!(
                "program slot range {}..{} crosses block boundary {:?}->{:?}",
                start_slot,
                end_slot + 1,
                start.block,
                end.block
            );
        }
        Ok((start.block, start.idx..end.idx + 1))
    }
}

#[derive(Clone, Debug)]
pub struct BBProgram {
    pub blocks: Vec<Block>,
    pub entry: BlockId,
    pub use_def: UseDefGraph,
    pub oracle: Option<VerifierOracle>,
    pub btf: BtfMetadataMap,
    pub kinsn_reg: Arc<KinsnRegistry>,
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
    pub insns: Vec<BpfInsn>,
    pub terminator: Terminator,
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
        prog.rebuild_cfg_edges();
        prog.rebuild_use_def()?;
        Ok(prog)
    }

    pub fn blocks(&self) -> impl Iterator<Item = &Block> {
        self.blocks.iter()
    }

    pub fn predecessors(&self, block: BlockId) -> &[BlockId] {
        &self.predecessors[block.0]
    }

    pub fn successors(&self, block: BlockId) -> &[BlockId] {
        &self.successors[block.0]
    }

    pub fn dominance(&self) -> Dominance {
        Dominance::compute(self)
    }

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
        let sites = self.current_pc_sites()?;
        let site = sites
            .get(&pc)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("current pc {pc} is not present in BBProgram"))?;
        self.live_out_site_checked(site)
    }

    pub fn reaching_defs(&self, block: BlockId) -> ReachingDefs {
        let defs = self
            .use_def
            .defs
            .keys()
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

    pub fn subprog_blocks(&self, frame: FrameId) -> impl Iterator<Item = BlockId> + '_ {
        self.blocks
            .iter()
            .filter(move |block| block.frame == frame)
            .map(|block| block.id)
    }

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

    pub fn sites_in_block(&self, block: BlockId) -> impl Iterator<Item = InsnSite> {
        let len = self
            .blocks
            .get(block.0)
            .map(|block_ref| block_ref.insns.len())
            .unwrap_or(0);
        (0..len).map(move |idx| InsnSite { block, idx })
    }

    pub fn sites_in_block_with_terminator(&self, block: BlockId) -> impl Iterator<Item = InsnSite> {
        self.logical_sites_in_block(block).into_iter()
    }

    pub fn current_site_pcs(&self) -> anyhow::Result<BTreeMap<InsnSite, usize>> {
        current_site_pcs(self)
    }

    pub fn current_pc_sites(&self) -> anyhow::Result<BTreeMap<usize, InsnSite>> {
        Ok(current_site_pcs(self)?
            .into_iter()
            .map(|(site, pc)| (pc, site))
            .collect())
    }

    pub fn branch_target_pcs(&self) -> anyhow::Result<BTreeSet<usize>> {
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

    pub fn insn_at(&self, site: InsnSite) -> Option<&BpfInsn> {
        let block = self.blocks.get(site.block.0)?;
        if site.idx < block.insns.len() {
            return block.insns.get(site.idx);
        }
        (site.idx == block.insns.len())
            .then(|| block.terminator.raw_insn())
            .flatten()
    }

    pub fn block_body_linear_view(&self, block: BlockId) -> anyhow::Result<BlockBodyLinearView> {
        let block_ref = self.block(block)?;
        let block_start_pcs = current_block_start_pcs(self)?;
        let mut insns = Vec::new();
        let mut slot_to_site = BTreeMap::new();
        for (idx, &insn) in block_ref.insns.iter().enumerate() {
            let site = InsnSite { block, idx };
            let slot = insns.len();
            slot_to_site.insert(slot, site);
            insns.push(insn);
            if insn.is_ldimm64() {
                let second = self.ldimm64_second_slots.get(&site).ok_or_else(|| {
                    anyhow::anyhow!("LD_IMM64 at {:?} is missing its second slot", site)
                })?;
                slot_to_site.insert(slot + 1, site);
                insns.push(*second);
            }
        }
        Ok(BlockBodyLinearView {
            block,
            start_pc: block_start_pcs[block.0],
            insns,
            slot_to_site,
        })
    }

    pub fn program_linear_view(&self) -> anyhow::Result<ProgramLinearView> {
        let mut insns = Vec::new();
        let mut slot_to_site = BTreeMap::new();
        for block in self.blocks() {
            for (idx, &insn) in block.insns.iter().enumerate() {
                let site = InsnSite {
                    block: block.id,
                    idx,
                };
                let slot = insns.len();
                slot_to_site.insert(slot, site);
                insns.push(insn);
                if insn.is_ldimm64() {
                    let second = self.ldimm64_second_slots.get(&site).ok_or_else(|| {
                        anyhow::anyhow!("LD_IMM64 at {:?} is missing its second slot", site)
                    })?;
                    slot_to_site.insert(slot + 1, site);
                    insns.push(*second);
                }
            }
            if let Some(&raw) = block.terminator.raw_insn() {
                slot_to_site.insert(
                    insns.len(),
                    InsnSite {
                        block: block.id,
                        idx: block.insns.len(),
                    },
                );
                insns.push(raw);
            }
        }
        Ok(ProgramLinearView {
            insns,
            slot_to_site,
        })
    }

    pub fn current_block_start_pc(&self, block: BlockId) -> anyhow::Result<usize> {
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
        let block_start_pcs = current_block_start_pcs(self)?;
        let start_pc = block_start_pcs[block.0]
            .checked_add(start_slot)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement start pc overflows"))?;
        let old_end = start_pc
            .checked_add(old_len)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement old range overflows"))?;
        let replacement_end = start_pc
            .checked_add(replacement_len)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement new range overflows"))?;

        let mut frame_start = usize::MAX;
        let mut frame_end = 0usize;
        let mut other_frame_starts = BTreeSet::new();
        for frame_block in self.blocks().filter(|candidate| candidate.frame == frame) {
            let block_start = block_start_pcs[frame_block.id.0];
            let block_end = block_start + self.block_slot_len(frame_block.id)?;
            frame_start = frame_start.min(block_start);
            frame_end = frame_end.max(block_end);
        }
        for other in self.blocks().filter(|candidate| candidate.frame != frame) {
            other_frame_starts.insert(block_start_pcs[other.id.0]);
        }
        if frame_start == usize::MAX {
            anyhow::bail!("frame {:?} for block {:?} has no blocks", frame, block);
        }

        if old_end > frame_end {
            return Ok(Some(format!(
                "kinsn site crosses subprog boundary (site {start_pc}..{old_end}, subprog {frame_start}..{frame_end})"
            )));
        }
        if replacement_end > frame_end {
            return Ok(Some(format!(
                "kinsn replacement crosses subprog boundary (replacement {start_pc}..{replacement_end}, subprog {frame_start}..{frame_end})"
            )));
        }
        if other_frame_starts
            .iter()
            .any(|&subprog| subprog > start_pc && subprog < old_end)
        {
            return Ok(Some(format!(
                "kinsn site contains subprog entry inside replacement range {start_pc}..{old_end}"
            )));
        }
        Ok(None)
    }

    fn block_slot_len(&self, block: BlockId) -> anyhow::Result<usize> {
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

    pub(crate) fn rebuild_cfg_edges(&mut self) {
        self.successors = vec![Vec::new(); self.blocks.len()];
        self.predecessors = vec![Vec::new(); self.blocks.len()];

        for block in &self.blocks {
            let from = block.id;
            for succ in block.terminator.successors() {
                if succ.0 >= self.blocks.len() {
                    continue;
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
        self.oracle = Some(Arc::from([]));
    }

    pub(crate) fn rebuild_use_def_after_mutation(&mut self) -> anyhow::Result<()> {
        self.rebuild_use_def()?;
        self.invalidate_oracle();
        Ok(())
    }

    pub fn remapped_func_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_bytes(self, self.func_info.as_ref(), BtfRecordKind::Func)
    }

    pub fn remapped_line_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_bytes(self, self.line_info.as_ref(), BtfRecordKind::Line)
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

    pub(crate) fn logical_sites_in_block(&self, block: BlockId) -> Vec<InsnSite> {
        let Some(block_ref) = self.blocks.get(block.0) else {
            return Vec::new();
        };
        let mut sites = (0..block_ref.insns.len())
            .map(|idx| InsnSite { block, idx })
            .collect::<Vec<_>>();
        if block_ref.terminator.raw_insn().is_some() {
            sites.push(InsnSite {
                block,
                idx: block_ref.insns.len(),
            });
        }
        sites
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
        for site in prog.logical_sites_in_block(block.id) {
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
        for site in prog.logical_sites_in_block(block.id) {
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
    let sites = prog.logical_sites_in_block(block);
    if let Some(site) = sites.first().copied() {
        return Ok(vec![site]);
    }
    let mut successors = Vec::new();
    for succ in block_ref.terminator.dataflow_successors() {
        successors.extend(first_logical_sites(prog, succ, visited)?);
    }
    Ok(successors)
}
