// SPDX-License-Identifier: MIT
//! Basic-block program representation for bpfopt pass execution.
use crate::analysis::bbprogram_btf::BtfRecordKind;
#[cfg(test)]
use crate::analysis::bbprogram_btf::{remap_btf_records_view, BtfRemapView};
use crate::analysis::bbprogram_lower::remap_btf_records_for_lowering;
use crate::analysis::{DefSite, UseDefGraph};
use crate::insn::{insn_width, BpfInsn, MapPseudo};
use crate::pass::{
    BtfInfoRecords, InsnAnnotation, KinsnRegistry, PrefetchProfile, RegKind, RegSet,
};
use crate::verifier_log::{RegState, StackState, VerifierInsn, VerifierInsnKind};
use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::sync::{Arc, Mutex};
pub(crate) type VerifierOracle = BTreeMap<InsnSite, Arc<[VerifierInsn]>>;
pub(crate) type BtfMetadataMap = BTreeMap<InsnSite, usize>;
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct BlockId(pub(crate) usize);
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct FrameId(pub(crate) usize);
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct InsnSite {
    pub(crate) block: BlockId,
    pub(crate) idx: usize,
}
#[cfg(test)]
impl InsnSite {
    pub(crate) fn for_test(block: BlockId, idx: usize) -> Self {
        Self { block, idx }
    }
}
/// Opaque "instruction slot distance" — the number of machine instruction
/// slots between layout-positioned BPF sites. Layout-aware passes (prefetch,
/// branch_flip) query this when they need physical instruction layout
/// distance for prefetch latency tuning or JA imm16 range checks. The wrapper
/// keeps passes from doing arbitrary `usize` arithmetic on raw slot counts.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord)]
pub struct SlotDistance(usize);
impl SlotDistance {
    pub const ZERO: Self = Self(0);
    /// Construct a layout distance from a slot count (used by callers that
    /// receive a user-supplied window size, e.g. `max_slots`).
    pub fn from_slots(slots: usize) -> Self {
        Self(slots)
    }
    /// Slot count. Only useful for comparison or saturating arithmetic with
    /// another SlotDistance — never for indexing instructions.
    pub fn slots(self) -> usize {
        self.0
    }
    pub fn saturating_sub(self, other: Self) -> Self {
        Self(self.0.saturating_sub(other.0))
    }
    pub fn checked_add(self, other: Self) -> Option<Self> {
        self.0.checked_add(other.0).map(Self)
    }
    /// Absolute slot distance |self - other|.
    pub fn abs_diff(self, other: Self) -> Self {
        Self(self.0.abs_diff(other.0))
    }
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct BBMapBinding {
    pub old_fd: i32,
    pub map_id: u32,
}
#[derive(Debug)]
pub struct BBProgram {
    pub(super) blocks: Vec<Block>,
    pub(crate) entry: BlockId,
    pub(super) use_def: UseDefGraph,
    pub(super) oracle: Option<VerifierOracle>,
    pub(super) pmu_profile: BTreeMap<InsnSite, InsnAnnotation>,
    pub(super) btf: BtfMetadataMap,
    pub(super) kinsn_reg: Arc<KinsnRegistry>,
    pub(crate) map_bindings: Vec<BBMapBinding>,
    pub(crate) func_info: Option<BtfInfoRecords>,
    pub(crate) line_info: Option<BtfInfoRecords>,
    ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>,
    pub(crate) pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>,
    pub(crate) predecessors: Vec<Vec<BlockId>>,
    pub(crate) successors: Vec<Vec<BlockId>>,
    pub(super) prog_type: u32,
    site_liveness_cache: Mutex<Option<Arc<SiteLivenessSets>>>,
    lifted_reg_facts_cache: Mutex<Option<Arc<LiftedRegFacts>>>,
}

impl Clone for BBProgram {
    fn clone(&self) -> Self {
        Self {
            blocks: self.blocks.clone(),
            entry: self.entry,
            use_def: self.use_def.clone(),
            oracle: self.oracle.clone(),
            pmu_profile: self.pmu_profile.clone(),
            btf: self.btf.clone(),
            kinsn_reg: Arc::clone(&self.kinsn_reg),
            map_bindings: self.map_bindings.clone(),
            func_info: self.func_info.clone(),
            line_info: self.line_info.clone(),
            ldimm64_second_slots: self.ldimm64_second_slots.clone(),
            pc_relative_ldimm64_targets: self.pc_relative_ldimm64_targets.clone(),
            predecessors: self.predecessors.clone(),
            successors: self.successors.clone(),
            prog_type: self.prog_type,
            site_liveness_cache: Mutex::new(None),
            lifted_reg_facts_cache: Mutex::new(None),
        }
    }
}
#[derive(Clone, Debug)]
pub struct Block {
    pub id: BlockId,
    pub(super) insns: Vec<BpfInsn>,
    pub(super) terminator: Terminator,
    pub frame: FrameId,
}
#[derive(Debug)]
pub(crate) struct BlockBodyView<'a> {
    pub(crate) block: BlockId,
    pub(crate) sites: Vec<InsnSite>,
    pub(crate) insns: &'a [BpfInsn],
}
#[derive(Debug)]
pub(crate) struct BlockStartWindow<'a> {
    pub(crate) block: BlockId,
    pub(crate) start_idx: usize,
    pub(crate) start_site: InsnSite,
    pub(crate) sites: &'a [InsnSite],
    pub(crate) insns: &'a [BpfInsn],
    pub(crate) lookahead: &'a [BpfInsn],
}
#[derive(Debug)]
pub(crate) struct WindowHit<T> {
    pub(crate) block: BlockId,
    pub(crate) start_idx: usize,
    pub(crate) start: InsnSite,
    pub(crate) old_len: usize,
    pub(crate) value: T,
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
            map_bindings: Vec::new(),
            func_info: None,
            line_info: None,
            ldimm64_second_slots,
            pc_relative_ldimm64_targets,
            predecessors: Vec::new(),
            successors: Vec::new(),
            prog_type: 0,
            site_liveness_cache: Mutex::new(None),
            lifted_reg_facts_cache: Mutex::new(None),
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
    pub fn block_ids(&self) -> impl Iterator<Item = BlockId> + '_ {
        self.blocks.iter().map(|block| block.id)
    }
    pub fn all_sites(&self) -> impl Iterator<Item = InsnSite> + '_ {
        self.blocks.iter().flat_map(logical_sites_for_block)
    }
    pub fn block_frame(&self, block: BlockId) -> anyhow::Result<FrameId> {
        Ok(self.block(block)?.frame)
    }
    pub fn site_block(&self, site: InsnSite) -> BlockId {
        site.block
    }
    pub fn site_frame(&self, site: InsnSite) -> anyhow::Result<FrameId> {
        self.block_frame(site.block)
    }
    pub fn terminator(&self, block: BlockId) -> anyhow::Result<Terminator> {
        Ok(self.block(block)?.terminator)
    }
    pub fn terminator_at_site(&self, site: InsnSite) -> anyhow::Result<Terminator> {
        self.terminator(self.site_block(site))
    }
    pub fn block_single_body_insn(&self, block: BlockId) -> anyhow::Result<Option<&BpfInsn>> {
        let block = self.block(block)?;
        Ok((block.insns.len() == 1).then(|| &block.insns[0]))
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
    #[cfg(test)]
    pub fn live_in(&self, block: BlockId) -> anyhow::Result<RegSet> {
        self.block(block)?;
        compute_liveness(self)
            .live_in
            .remove(&block)
            .ok_or_else(|| anyhow::anyhow!("liveness missing live_in for {:?}", block))
    }
    #[cfg(test)]
    pub fn live_out(&self, block: BlockId) -> anyhow::Result<RegSet> {
        self.block(block)?;
        compute_liveness(self)
            .live_out
            .remove(&block)
            .ok_or_else(|| anyhow::anyhow!("liveness missing live_out for {:?}", block))
    }
    pub fn live_out_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet> {
        self.insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("invalid instruction site {:?}", site))?;
        self.site_liveness()?
            .live_out
            .get(&site)
            .cloned()
            .ok_or_else(|| anyhow::anyhow!("site liveness missing live_out for {:?}", site))
    }
    fn site_liveness(&self) -> anyhow::Result<Arc<SiteLivenessSets>> {
        let mut slot = self
            .site_liveness_cache
            .lock()
            .map_err(|_| anyhow::anyhow!("site liveness cache poisoned"))?;
        if let Some(cached) = slot.as_ref() {
            return Ok(Arc::clone(cached));
        }
        let fresh = Arc::new(compute_site_liveness(self)?);
        *slot = Some(Arc::clone(&fresh));
        Ok(fresh)
    }
    /// Lift-time linear reg-fact for `reg` at the entry of `site`.
    /// Returns `LiftedRegFact::Unknown` if the site is not tracked.
    pub fn reg_fact_at(&self, site: InsnSite, reg: u8) -> anyhow::Result<LiftedRegFact> {
        let facts = self.lifted_reg_facts()?;
        Ok(facts
            .by_site
            .get(&site)
            .map(|state| state[reg as usize])
            .unwrap_or(LiftedRegFact::Unknown))
    }
    /// Set the program type and invalidate any caches that depend on it
    /// (lifted reg facts use prog_type to derive packet ctx layout).
    pub(crate) fn set_prog_type(&mut self, prog_type: u32) -> anyhow::Result<()> {
        if self.prog_type == prog_type {
            return Ok(());
        }
        self.prog_type = prog_type;
        *self
            .lifted_reg_facts_cache
            .lock()
            .map_err(|_| anyhow::anyhow!("lifted reg facts cache poisoned"))? = None;
        Ok(())
    }
    fn lifted_reg_facts(&self) -> anyhow::Result<Arc<LiftedRegFacts>> {
        let mut slot = self
            .lifted_reg_facts_cache
            .lock()
            .map_err(|_| anyhow::anyhow!("lifted reg facts cache poisoned"))?;
        if let Some(cached) = slot.as_ref() {
            return Ok(Arc::clone(cached));
        }
        let fresh = Arc::new(compute_lifted_reg_facts(self)?);
        *slot = Some(Arc::clone(&fresh));
        Ok(fresh)
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
    #[cfg(test)]
    pub(crate) fn oracle(&self) -> Option<&VerifierOracle> {
        self.oracle.as_ref()
    }
    fn verifier_states_at(&self, site: InsnSite) -> Option<&[VerifierInsn]> {
        self.oracle.as_ref()?.get(&site).map(AsRef::as_ref)
    }
    pub fn reg_known_constant(&self, site: InsnSite, reg: u8) -> Option<i64> {
        let mut states = self.verifier_reg_states(site, reg)?;
        let first = reg_exact_value(states.next()?)?;
        for state in states {
            if reg_exact_value(state)? != first {
                return None;
            }
        }
        Some(first as i64)
    }
    pub fn reg_kind(&self, site: InsnSite, reg: u8) -> Option<RegKind> {
        let mut states = self.verifier_reg_states(site, reg)?;
        let first = reg_kind_from_verifier_type(&states.next()?.reg_type);
        for state in states {
            if reg_kind_from_verifier_type(&state.reg_type) != first {
                return None;
            }
        }
        Some(first)
    }
    /// Returns the known constant bytes at the stack region the register
    /// points to, if the verifier proved them. Width is `key_width` bytes.
    pub fn reg_known_stack_bytes(
        &self,
        site: InsnSite,
        reg: u8,
        key_width: usize,
    ) -> Option<Vec<u8>> {
        let states = self.verifier_states_at(site)?;
        if states.is_empty()
            || states
                .iter()
                .any(|state| state.kind == VerifierInsnKind::EdgeFullState)
        {
            return None;
        }
        let mut first = None;
        for state in states {
            let reg_state = state.regs.get(&reg)?;
            let stack_off = fp_stack_offset_from_reg_state(reg_state)?;
            let bytes = known_stack_bytes_from_state(state, stack_off, key_width)?;
            match &first {
                Some(existing) if existing != &bytes => return None,
                Some(_) => {}
                None => first = Some(bytes),
            }
        }
        first
    }
    pub fn site_is_dead_code(&self, site: InsnSite) -> bool {
        self.verifier_states_at(site).is_some_and(|states| {
            !states.is_empty() && states.iter().all(|state| state.speculative)
        })
    }
    fn verifier_reg_states(
        &self,
        site: InsnSite,
        reg: u8,
    ) -> Option<impl Iterator<Item = &RegState>> {
        let states = self.verifier_states_at(site)?;
        if states.is_empty()
            || states
                .iter()
                .any(|state| state.kind == VerifierInsnKind::EdgeFullState)
        {
            return None;
        }
        if states.iter().any(|state| !state.regs.contains_key(&reg)) {
            return None;
        }
        Some(states.iter().filter_map(move |state| state.regs.get(&reg)))
    }
    pub fn branch_taken_rate(&self, site: InsnSite) -> Option<f32> {
        let profile = self.pmu_profile.get(&site)?.branch_profile.as_ref()?;
        let total = profile.taken_count.checked_add(profile.not_taken_count)?;
        (total != 0).then_some(profile.taken_count as f32 / total as f32)
    }
    pub fn branch_miss_rate(&self, site: InsnSite) -> Option<f32> {
        let miss_rate = self
            .pmu_profile
            .get(&site)?
            .branch_profile
            .as_ref()?
            .miss_rate;
        miss_rate.is_finite().then_some(miss_rate as f32)
    }
    pub fn site_hotness(&self, site: InsnSite) -> Option<u64> {
        let record = self.pmu_profile.get(&site)?;
        let branch_count = record
            .branch_profile
            .as_ref()
            .map(|profile| profile.branch_count);
        let execution_count = record
            .prefetch_profile
            .as_ref()
            .map(|profile| profile.execution_count);
        branch_count.into_iter().chain(execution_count).max()
    }
    pub fn prefetch_hint(&self, site: InsnSite) -> Option<&PrefetchProfile> {
        self.pmu_profile.get(&site)?.prefetch_profile.as_ref()
    }
    pub(crate) fn attach_profile_from_annotations(
        &mut self,
        annotations: &[InsnAnnotation],
    ) -> anyhow::Result<()> {
        self.pmu_profile.clear();
        for (pc, annotation) in annotations.iter().enumerate() {
            if annotation.branch_profile.is_none() && annotation.prefetch_profile.is_none() {
                continue;
            }
            let site = self
                .original_pc_to_site(pc)
                .ok_or_else(|| anyhow::anyhow!("profile pc {pc} is not present in BBProgram"))?;
            self.pmu_profile.insert(site, annotation.clone());
        }
        Ok(())
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
    pub fn btf_records(&self) -> anyhow::Result<BtfRemapView> {
        Ok(BtfRemapView {
            func: remap_btf_records_view(self, self.func_info.as_ref(), BtfRecordKind::Func)?,
            line: remap_btf_records_view(self, self.line_info.as_ref(), BtfRecordKind::Line)?,
        })
    }
    pub fn sites_in_block(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
        let len = self.block(block)?.insns.len();
        Ok((0..len).map(move |idx| InsnSite { block, idx }).collect())
    }
    pub fn sites_in_block_with_terminator(&self, block: BlockId) -> anyhow::Result<Vec<InsnSite>> {
        Ok(logical_sites_for_block(self.block(block)?))
    }
    pub(super) fn current_site_pcs(&self) -> anyhow::Result<BTreeMap<InsnSite, usize>> {
        current_site_pcs(self)
    }
    pub(crate) fn original_pc(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.btf
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("site {:?} has no original-PC mapping", site))
    }
    pub(crate) fn original_pc_to_site(&self, pc: usize) -> Option<InsnSite> {
        self.btf
            .iter()
            .find_map(|(&site, &original_pc)| (original_pc == pc).then_some(site))
    }
    pub(crate) fn site_current_pc(&self, site: InsnSite) -> anyhow::Result<usize> {
        self.current_site_pcs()?
            .get(&site)
            .copied()
            .ok_or_else(|| anyhow::anyhow!("site {:?} is not in current program order", site))
    }
    /// LAYOUT QUERY: site's slot offset in the current program layout.
    /// Returns an opaque `SlotDistance` token; passes may only compare/saturate, not arbitrary arithmetic.
    pub fn site_layout_offset(&self, site: InsnSite) -> anyhow::Result<SlotDistance> {
        self.site_current_pc(site).map(SlotDistance)
    }
    /// Convenience for kinsn-class passes: return `(btf_id, kfunc_off)` for a
    /// kinsn target by name. Replaces the two-call sequence of
    /// `kinsn_registry().btf_id_for_target_name(name)` +
    /// `kinsn_registry().call_off_for_target_name(name)`.
    pub fn kinsn_call(&self, target_name: &str) -> anyhow::Result<(i32, i16)> {
        let btf_id = self.kinsn_reg.btf_id_for_target_name(target_name)?;
        let kfunc_off = self.kinsn_reg.call_off_for_target_name(target_name)?;
        Ok((btf_id, kfunc_off))
    }
    /// Live-out RegSet at the last instruction of a kinsn window starting at
    /// `start` and consuming `len` body sites. Used by passes (today: rotate)
    /// that need to know whether a scratch register survives past the window.
    pub fn live_out_after_window(&self, start: InsnSite, len: usize) -> anyhow::Result<RegSet> {
        if len == 0 {
            anyhow::bail!("live_out_after_window len must be > 0 at {:?}", start);
        }
        let block = self.block(start.block)?;
        let end_idx = start
            .idx
            .checked_add(len)
            .and_then(|v| v.checked_sub(1))
            .ok_or_else(|| {
                anyhow::anyhow!(
                    "live_out_after_window window at {:?} len {} overflows",
                    start,
                    len
                )
            })?;
        if end_idx >= block.insns.len() {
            anyhow::bail!(
                "live_out_after_window end idx {end_idx} exceeds block body length {}",
                block.insns.len()
            );
        }
        let end_site = InsnSite {
            block: start.block,
            idx: end_idx,
        };
        self.live_out_site_checked(end_site)
    }
    /// LAYOUT QUERY: total slot count across the contiguous block range
    /// `[first.. =last]` in BlockId order. Used by branch_flip to validate
    /// reflected arm fits within JA imm16 range.
    pub fn block_range_slot_count(
        &self,
        first: BlockId,
        last: BlockId,
    ) -> anyhow::Result<SlotDistance> {
        if first.0 > last.0 {
            anyhow::bail!(
                "block_range_slot_count: range {:?}..={:?} is inverted",
                first,
                last
            );
        }
        let mut len = 0usize;
        for block in first.0..=last.0 {
            for site in self.sites_in_block(BlockId(block))? {
                len = len
                    .checked_add(self.insn_slot_width(site)?)
                    .ok_or_else(|| anyhow::anyhow!("block range slot count overflows"))?;
            }
        }
        Ok(SlotDistance(len))
    }
    pub fn branch_target_entry_sites(&self) -> anyhow::Result<BTreeSet<InsnSite>> {
        let mut targets = BTreeSet::new();
        for block in self.blocks() {
            let target = match self.terminator(block.id)? {
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
        Ok(logical_sites_for_block(self.block(block)?)
            .into_iter()
            .next())
    }
    pub fn terminator_site(&self, block: BlockId) -> anyhow::Result<Option<InsnSite>> {
        let block_ref = self.block(block)?;
        Ok(block_ref.terminator.raw_insn().map(|_| InsnSite {
            block,
            idx: block_ref.insns.len(),
        }))
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
    pub(crate) fn ldimm64_second_slot(&self, site: InsnSite) -> Option<&BpfInsn> {
        self.ldimm64_second_slots.get(&site)
    }
    pub(super) fn remove_ldimm64_second_slot(&mut self, site: InsnSite) {
        self.ldimm64_second_slots.remove(&site);
    }
    pub(super) fn insert_ldimm64_second_slot(&mut self, site: InsnSite, second: BpfInsn) {
        self.ldimm64_second_slots.insert(site, second);
    }
    pub(super) fn shift_ldimm64_second_slots_after_insert(
        &mut self,
        block: BlockId,
        at: usize,
        delta: usize,
    ) {
        Self::shift_metadata_after_insert(&mut self.ldimm64_second_slots, block, at, delta);
    }
    pub(super) fn shift_ldimm64_second_slots_after_delete(
        &mut self,
        block: BlockId,
        at: usize,
        deleted: usize,
    ) {
        Self::shift_metadata_after_delete(&mut self.ldimm64_second_slots, block, at, deleted);
    }
    pub(super) fn remap_ldimm64_second_slots<F>(&mut self, remap: &mut F)
    where
        F: FnMut(InsnSite) -> Option<InsnSite>,
    {
        self.ldimm64_second_slots = std::mem::take(&mut self.ldimm64_second_slots)
            .into_iter()
            .filter_map(|(site, value)| remap(site).map(|site| (site, value)))
            .collect();
    }
    #[cfg(test)]
    fn block_start_pc(&self, block: BlockId) -> anyhow::Result<usize> {
        self.block(block)?;
        Ok(current_block_start_pcs(self)?[block.0])
    }
    fn kinsn_replacement_subprog_skip_reason(
        &self,
        block: BlockId,
        start_slot: usize,
        old_len: usize,
    ) -> anyhow::Result<Option<String>> {
        let block_ref = self.block(block)?;
        let frame = block_ref.frame;
        let frame_start_slot = frame_relative_logical_slot(self, block, start_slot)?;
        let old_end = frame_start_slot
            .checked_add(old_len)
            .ok_or_else(|| anyhow::anyhow!("kinsn replacement old range overflows"))?;
        let mut frame_start_slot_abs = usize::MAX;
        let mut frame_end_slot_abs = 0usize;
        for frame_block in self.blocks().filter(|candidate| candidate.frame == frame) {
            let block_start = frame_relative_logical_slot(self, frame_block.id, 0)?;
            let block_end = block_start + block_logical_slot_len(self, frame_block.id)?;
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
        Ok(None)
    }
    pub(crate) fn remap_block_after_insert(
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
    pub(crate) fn remap_block_after_remove(
        block: BlockId,
        removed: &[BlockId],
    ) -> anyhow::Result<BlockId> {
        if removed.contains(&block) {
            anyhow::bail!("target block {:?} was removed", block);
        }
        let shift = removed.iter().filter(|removed| removed.0 < block.0).count();
        Ok(BlockId(block.0 - shift))
    }
    pub fn is_terminator_site(&self, site: InsnSite) -> anyhow::Result<bool> {
        let block = self.block(site.block)?;
        Ok(site.idx == block.insns.len() && block.terminator.raw_insn().is_some())
    }
    pub(crate) fn insn_slot_width(&self, site: InsnSite) -> anyhow::Result<usize> {
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
    fn rebuild_use_def(&mut self) -> anyhow::Result<()> {
        self.use_def = UseDefGraph::build(self)?;
        Ok(())
    }
    pub(crate) fn attach_side_inputs(
        &mut self,
        insns: &[BpfInsn],
        map_ids: Vec<u32>,
        func_info: Option<BtfInfoRecords>,
        line_info: Option<BtfInfoRecords>,
    ) -> anyhow::Result<()> {
        self.map_bindings = collect_map_bindings(insns, &map_ids)?;
        self.func_info = func_info;
        self.line_info = line_info;
        Ok(())
    }
    pub(crate) fn invalidate_oracle(&mut self) {
        self.oracle = None;
        self.pmu_profile.clear();
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
    pub(crate) fn block_body_view(&self, block: BlockId) -> anyhow::Result<BlockBodyView<'_>> {
        let block_ref = self.block(block)?;
        Ok(BlockBodyView {
            block,
            sites: (0..block_ref.insns.len())
                .map(|idx| InsnSite { block, idx })
                .collect(),
            insns: &block_ref.insns,
        })
    }
    pub(crate) fn scan_block_starts<F, T>(
        &self,
        max_lookahead: usize,
        mut f: F,
    ) -> anyhow::Result<Vec<WindowHit<T>>>
    where
        F: FnMut(BlockStartWindow<'_>) -> anyhow::Result<Option<(usize, usize, T)>>,
    {
        let mut hits = Vec::new();
        for block in self.block_ids() {
            let body = self.block_body_view(block)?;
            for (start_idx, &start_site) in body.sites.iter().enumerate() {
                let lookahead_end = start_idx
                    .checked_add(max_lookahead)
                    .map(|end| end.min(body.insns.len()))
                    .ok_or_else(|| anyhow::anyhow!("lookahead at {start_idx} overflows"))?;
                let window = BlockStartWindow {
                    block: body.block,
                    start_idx,
                    start_site,
                    sites: &body.sites,
                    insns: body.insns,
                    lookahead: &body.insns[start_idx..lookahead_end],
                };
                if window.sites.get(window.start_idx).copied() != Some(window.start_site) {
                    anyhow::bail!("inconsistent start window in {:?}", window.block);
                }
                let Some((local_start_idx, old_len, value)) = f(window)? else {
                    continue;
                };
                if old_len == 0 {
                    anyhow::bail!(
                        "window match in {:?} at index {} has zero old length",
                        body.block,
                        local_start_idx
                    );
                }
                let Some(&start) = body.sites.get(local_start_idx) else {
                    anyhow::bail!(
                        "window match start index {} exceeds {:?} body length {}",
                        local_start_idx,
                        body.block,
                        body.sites.len()
                    );
                };
                let end_idx = local_start_idx.checked_add(old_len).ok_or_else(|| {
                    anyhow::anyhow!(
                        "window match range {} + {} overflows",
                        local_start_idx,
                        old_len
                    )
                })?;
                if end_idx > body.sites.len() {
                    anyhow::bail!(
                        "window match range {}..{} exceeds {:?} body length {}",
                        local_start_idx,
                        end_idx,
                        body.block,
                        body.sites.len()
                    );
                }
                hits.push(WindowHit {
                    block: body.block,
                    start_idx: local_start_idx,
                    start,
                    old_len,
                    value,
                });
            }
        }
        Ok(hits)
    }
}
fn collect_map_bindings(insns: &[BpfInsn], map_ids: &[u32]) -> anyhow::Result<Vec<BBMapBinding>> {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if let Some(kind) = insn.map_pseudo() {
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
fn reg_exact_value(state: &RegState) -> Option<u64> {
    state
        .exact_u64()
        .or_else(|| state.exact_u32().map(u64::from))
}
fn fp_stack_offset_from_reg_state(state: &RegState) -> Option<i32> {
    (state.reg_type == "fp").then(|| state.offset.unwrap_or(0))
}
fn known_stack_bytes_from_state(
    state: &VerifierInsn,
    stack_off: i32,
    width: usize,
) -> Option<Vec<u8>> {
    let mut bytes = Vec::with_capacity(width);
    for idx in 0..width {
        let idx = match i32::try_from(idx) {
            Ok(idx) => idx,
            Err(_) => return None,
        };
        bytes.push(known_stack_byte_from_state(
            state,
            stack_off.checked_add(idx)?,
        )?);
    }
    Some(bytes)
}
fn known_stack_byte_from_state(state: &VerifierInsn, absolute_off: i32) -> Option<u8> {
    let slot_start = verifier_stack_slot_start(absolute_off)?;
    let byte_index = usize::try_from(absolute_off - i32::from(slot_start)).ok()?;
    if byte_index >= 8 {
        return None;
    }
    let stack = state.stack.get(&slot_start)?;
    match verifier_stack_slot_type(stack, byte_index) {
        Some(b'0') => Some(0),
        Some(b'r') | None => verifier_stack_slot_exact_bytes(stack).map(|bytes| bytes[byte_index]),
        Some(_) => None,
    }
}
fn verifier_stack_slot_start(absolute_off: i32) -> Option<i16> {
    if absolute_off >= 0 {
        return None;
    }
    let slot_index = ((-absolute_off - 1) / 8) + 1;
    i16::try_from(-slot_index * 8).ok()
}
fn verifier_stack_slot_type(stack: &StackState, byte_index: usize) -> Option<u8> {
    let slot_types = stack.slot_types.as_ref()?;
    if byte_index >= 8 {
        return None;
    }
    slot_types.as_bytes().get(7 - byte_index).copied()
}
fn verifier_stack_slot_exact_bytes(stack: &StackState) -> Option<[u8; 8]> {
    let value = reg_exact_value(stack.value.as_ref()?)?;
    Some(value.to_le_bytes())
}
fn reg_kind_from_verifier_type(reg_type: &str) -> RegKind {
    match reg_type {
        "scalar" => RegKind::Scalar,
        "fp" => RegKind::FramePointer,
        "ctx" => RegKind::Context,
        "pkt" => RegKind::PacketPointer,
        "pkt_meta" => RegKind::PacketMetaPointer,
        "map_ptr" => RegKind::MapPointer,
        "map_value" => RegKind::MapValue,
        "map_key" => RegKind::MapKey,
        "mem" | "buf" | "ringbuf_mem" | "iter" => RegKind::Memory,
        other if other.starts_with("scalar") => RegKind::Scalar,
        other if other.starts_with("fp") => RegKind::FramePointer,
        "" => RegKind::Unknown,
        other if other.contains("ptr_") || other.contains("_ptr") => RegKind::BtfStructPointer,
        _ => RegKind::OtherPointer,
    }
}
impl Terminator {
    pub(crate) fn raw_insn(&self) -> Option<&BpfInsn> {
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
#[cfg(test)]
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
fn block_logical_slot_len(prog: &BBProgram, block: BlockId) -> anyhow::Result<usize> {
    let block_ref = prog.block(block)?;
    let mut len = 0usize;
    for idx in 0..block_ref.insns.len() {
        len = len
            .checked_add(prog.insn_slot_width(InsnSite { block, idx })?)
            .ok_or_else(|| anyhow::anyhow!("block logical slot length overflows"))?;
    }
    if block_ref.terminator.raw_insn().is_some() {
        len = len
            .checked_add(1)
            .ok_or_else(|| anyhow::anyhow!("block logical slot length overflows"))?;
    }
    Ok(len)
}
fn frame_relative_logical_slot(
    prog: &BBProgram,
    block: BlockId,
    slot: usize,
) -> anyhow::Result<usize> {
    let frame = prog.block(block)?.frame;
    let mut offset = 0usize;
    for candidate in prog.blocks().filter(|candidate| candidate.frame == frame) {
        if candidate.id == block {
            return offset
                .checked_add(slot)
                .ok_or_else(|| anyhow::anyhow!("frame-relative slot {slot} overflows"));
        }
        offset = offset
            .checked_add(block_logical_slot_len(prog, candidate.id)?)
            .ok_or_else(|| anyhow::anyhow!("frame-relative block offset overflows"))?;
    }
    anyhow::bail!("block {:?} is missing from its frame", block)
}
fn site_offset_in_block_slots(prog: &BBProgram, site: InsnSite) -> anyhow::Result<usize> {
    prog.block(site.block)?;
    let mut offset = 0usize;
    for idx in 0..site.idx {
        offset = offset
            .checked_add(prog.insn_slot_width(InsnSite {
                block: site.block,
                idx,
            })?)
            .ok_or_else(|| anyhow::anyhow!("site offset in block overflows"))?;
    }
    Ok(offset)
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
#[cfg(test)]
#[derive(Clone, Debug, Default)]
struct LivenessSets {
    live_in: HashMap<BlockId, RegSet>,
    live_out: HashMap<BlockId, RegSet>,
}
#[derive(Clone, Debug, Default)]
struct SiteLivenessSets {
    live_out: HashMap<InsnSite, RegSet>,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum LiftedRegFact {
    Unknown,
    Ctx,
    Const(i64),
    FpOff(i32),
    /// Direct packet-data pointer. `ptr_def` is the LDX site that loaded it
    /// (or the latest aliased site after MOV-X / ADD-K propagation).
    /// `const_off` is the constant offset accumulated from ADD-K.
    PacketData {
        ptr_def: InsnSite,
        const_off: i32,
    },
    /// Direct packet-end pointer. `ptr_def` is the matching data-load site
    /// when this end-load follows a data-load in the same block; otherwise it
    /// is this end-load's own site.
    PacketEnd {
        ptr_def: InsnSite,
    },
    /// Scalar from a memory load that is not a packet pointer.
    Scalar,
}
impl LiftedRegFact {
    pub fn as_const(self) -> Option<i64> {
        match self {
            Self::Const(value) => Some(value),
            _ => None,
        }
    }
    pub fn as_fp_off(self) -> Option<i32> {
        match self {
            Self::FpOff(off) => Some(off),
            _ => None,
        }
    }
    pub fn as_packet_data(self) -> Option<(InsnSite, i32)> {
        match self {
            Self::PacketData { ptr_def, const_off } => Some((ptr_def, const_off)),
            _ => None,
        }
    }
    pub fn as_packet_end(self) -> Option<InsnSite> {
        match self {
            Self::PacketEnd { ptr_def } => Some(ptr_def),
            _ => None,
        }
    }
}
impl LiftedRegFact {
    fn alu64_imm(self, op: u8, imm: i32) -> Self {
        use crate::insn::{BPF_ADD, BPF_SUB};
        let add_sub = |current: i64| match op {
            BPF_ADD => current.checked_add(i64::from(imm)),
            BPF_SUB => current.checked_sub(i64::from(imm)),
            _ => None,
        };
        match self {
            Self::Const(current) => add_sub(current).map(Self::Const).unwrap_or(Self::Unknown),
            Self::FpOff(current) => add_sub(i64::from(current))
                .and_then(|next| i32::try_from(next).ok())
                .map(Self::FpOff)
                .unwrap_or(Self::Unknown),
            _ => Self::Unknown,
        }
    }
    fn alu32_add_sub(self, imm: i32, is_add: bool) -> Self {
        match self {
            Self::Const(current) => {
                let current = current as u32;
                let imm = imm as u32;
                let next = if is_add {
                    current.wrapping_add(imm)
                } else {
                    current.wrapping_sub(imm)
                };
                Self::Const(next as i64)
            }
            _ => Self::Unknown,
        }
    }
    fn mov32(self) -> Self {
        match self {
            Self::Const(current) => Self::Const(current as u32 as i64),
            _ => Self::Unknown,
        }
    }
}
#[derive(Clone, Debug, Default)]
struct LiftedRegFacts {
    by_site: HashMap<InsnSite, [LiftedRegFact; 11]>,
}
#[cfg(test)]
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
fn compute_lifted_reg_facts(prog: &BBProgram) -> anyhow::Result<LiftedRegFacts> {
    let mut by_site = HashMap::new();
    let layout = crate::insn::packet_ctx_layout(
        prog.prog_type,
        crate::insn::PacketCtxLayoutScope::PacketAccess,
    );
    let mut regs = [LiftedRegFact::Unknown; 11];
    let mut last_data_load: Option<InsnSite> = None;
    for (idx, block) in prog.block_ids().enumerate().collect::<Vec<_>>() {
        if idx == 0 {
            regs = [LiftedRegFact::Unknown; 11];
            regs[1] = LiftedRegFact::Ctx;
            regs[10] = LiftedRegFact::FpOff(0);
            last_data_load = None;
        } else if prog.should_reset_linear_state_at_block(block)? {
            regs = [LiftedRegFact::Unknown; 11];
            regs[10] = LiftedRegFact::FpOff(0);
            last_data_load = None;
        }
        let sites = prog.sites_in_block_with_terminator(block)?;
        for site in sites {
            by_site.insert(site, regs);
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            let ldimm64_hi = if insn.is_ldimm64() {
                Some(prog.ldimm64_second_slot(site).ok_or_else(|| {
                    anyhow::anyhow!("LD_IMM64 at {:?} is missing high half", site)
                })?)
            } else {
                None
            };
            advance_lifted_regs(
                insn,
                ldimm64_hi,
                site,
                layout,
                &mut regs,
                &mut last_data_load,
            )?;
        }
    }
    Ok(LiftedRegFacts { by_site })
}
fn advance_lifted_regs(
    insn: &BpfInsn,
    ldimm64_hi: Option<&BpfInsn>,
    site: InsnSite,
    layout: Option<crate::insn::PacketCtxLayout>,
    regs: &mut [LiftedRegFact; 11],
    last_data_load: &mut Option<InsnSite>,
) -> anyhow::Result<()> {
    use crate::insn::{
        bpf_op, bpf_size, bpf_src, decode_ldimm64_value, BPF_ADD, BPF_ALU, BPF_ALU64, BPF_K,
        BPF_LD, BPF_LDX, BPF_MEM, BPF_MOV, BPF_REG_0, BPF_REG_5, BPF_SUB, BPF_W, BPF_X, BPF_XOR,
    };
    if insn.is_call() {
        // Conservative: blast all packet-typed regs and r0..r5 to Unknown.
        // (Original bounds_check_merge cleared ALL regs on call; we keep r6..r9
        // for non-packet facts but clear packet facts.)
        for reg in BPF_REG_0..=BPF_REG_5 {
            regs[reg as usize] = LiftedRegFact::Unknown;
        }
        for fact in regs.iter_mut() {
            if matches!(
                fact,
                LiftedRegFact::PacketData { .. } | LiftedRegFact::PacketEnd { .. }
            ) {
                *fact = LiftedRegFact::Unknown;
            }
        }
        *last_data_load = None;
        return Ok(());
    }
    if insn.is_ldimm64() {
        let hi =
            ldimm64_hi.ok_or_else(|| anyhow::anyhow!("LD_IMM64 is missing its second slot"))?;
        regs[insn.dst_reg() as usize] = LiftedRegFact::Const(decode_ldimm64_value(insn, hi) as i64);
        return Ok(());
    }
    match insn.class() {
        BPF_ALU64 => {
            let dst = insn.dst_reg() as usize;
            regs[dst] = match (bpf_op(insn.code), bpf_src(insn.code)) {
                (BPF_MOV, BPF_K) => LiftedRegFact::Const(insn.imm as i64),
                (BPF_MOV, BPF_X) => regs[insn.src_reg() as usize],
                (BPF_ADD, BPF_K) => match regs[dst] {
                    LiftedRegFact::PacketData { ptr_def, const_off } => LiftedRegFact::PacketData {
                        ptr_def,
                        const_off: const_off.saturating_add(insn.imm),
                    },
                    _ => regs[dst].alu64_imm(BPF_ADD, insn.imm),
                },
                (BPF_SUB, BPF_K) => regs[dst].alu64_imm(BPF_SUB, insn.imm),
                (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => LiftedRegFact::Unknown,
                _ => LiftedRegFact::Unknown,
            };
        }
        BPF_ALU => {
            let dst = insn.dst_reg() as usize;
            regs[dst] = match (bpf_op(insn.code), bpf_src(insn.code)) {
                (BPF_MOV, BPF_K) => LiftedRegFact::Const(insn.imm as u32 as i64),
                (BPF_MOV, BPF_X) => regs[insn.src_reg() as usize].mov32(),
                (BPF_ADD, BPF_K) => regs[dst].alu32_add_sub(insn.imm, true),
                (BPF_SUB, BPF_K) => regs[dst].alu32_add_sub(insn.imm, false),
                (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => LiftedRegFact::Unknown,
                _ => LiftedRegFact::Unknown,
            };
        }
        BPF_LDX => {
            let dst = insn.dst_reg() as usize;
            let mut fact = LiftedRegFact::Unknown;
            if let Some(layout) = layout {
                if bpf_size(insn.code) == BPF_W
                    && (insn.code & 0xe0) == BPF_MEM
                    && matches!(regs[insn.src_reg() as usize], LiftedRegFact::Ctx)
                {
                    if insn.off == layout.data_off {
                        fact = LiftedRegFact::PacketData {
                            ptr_def: site,
                            const_off: 0,
                        };
                        *last_data_load = Some(site);
                    } else if insn.off == layout.data_end_off {
                        let ptr_def = last_data_load.unwrap_or(site);
                        fact = LiftedRegFact::PacketEnd { ptr_def };
                    }
                }
            }
            regs[dst] = fact;
        }
        BPF_LD => regs[insn.dst_reg() as usize] = LiftedRegFact::Unknown,
        _ => {}
    }
    Ok(())
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
    #[cfg(test)]
    pub(crate) fn rep_site_slot(&self, site: InsnSite) -> anyhow::Result<usize> {
        let offset = site_offset_in_block_slots(self, site)?;
        Ok(self.block_start_pc(site.block)? + offset)
    }

    /// Structural admission check for an in-block replacement. Returns
    /// `Some(reason)` if the replacement crosses subprog boundary. Caller
    /// (try_replace_range) guarantees `old_len > 0 && new_len > 0` before
    /// calling — pure inserts/deletes don't need this check.
    pub(crate) fn admission_skip_reason(
        &self,
        start: InsnSite,
        old_len: usize,
    ) -> anyhow::Result<Option<String>> {
        let start_slot = site_offset_in_block_slots(self, start)?;
        self.kinsn_replacement_subprog_skip_reason(start.block, start_slot, old_len)
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
            .def_sites()
            .find(|d| d.block == BlockId(0) && d.reg == BPF_REG_1)
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
    #[test]
    fn scan_block_starts_skips_empty_body_blocks() {
        let prog = lift_test_program(&[BpfInsn::exit()], &pass_ctx());
        let mut called = false;
        let hits: Vec<WindowHit<()>> = prog
            .scan_block_starts(2, |_| {
                called = true;
                Ok(None)
            })
            .expect("empty-body scan should succeed");
        assert!(hits.is_empty());
        assert!(!called);
    }
    #[test]
    fn scan_block_starts_exposes_truncated_lookahead() {
        let prog = lift_test_program(
            &[BpfInsn::mov64_imm(BPF_REG_0, 7), BpfInsn::exit()],
            &pass_ctx(),
        );
        let hits = prog
            .scan_block_starts(4, |window| {
                assert_eq!(window.block, BlockId(0));
                assert_eq!(window.start_idx, 0);
                assert_eq!(window.start_site, InsnSite::for_test(BlockId(0), 0));
                assert_eq!(window.sites.len(), 1);
                assert_eq!(window.lookahead.len(), 1);
                Ok(Some((window.start_idx, 1, window.lookahead[0].imm)))
            })
            .expect("truncated lookahead scan should succeed");
        assert_eq!(hits.len(), 1);
        assert_eq!(hits[0].start, InsnSite::for_test(BlockId(0), 0));
        assert_eq!(hits[0].old_len, 1);
        assert_eq!(hits[0].value, 7);
    }
    #[test]
    fn scan_block_starts_accepts_replacement_start_before_scan_index() {
        let prog = lift_test_program(
            &[
                BpfInsn::mov64_imm(BPF_REG_0, 1),
                BpfInsn::mov64_imm(BPF_REG_1, 2),
                BpfInsn::mov64_imm(BPF_REG_2, 3),
                BpfInsn::exit(),
            ],
            &pass_ctx(),
        );
        let hits = prog
            .scan_block_starts(2, |window| {
                Ok((window.start_idx == 2).then_some((1, 2, window.start_site)))
            })
            .expect("backward-start scan should succeed");
        assert_eq!(hits.len(), 1);
        assert_eq!(hits[0].start_idx, 1);
        assert_eq!(hits[0].start, InsnSite::for_test(BlockId(0), 1));
        assert_eq!(hits[0].value, InsnSite::for_test(BlockId(0), 2));
    }
    #[test]
    fn scan_block_starts_rejects_out_of_range_local_start() {
        let prog = lift_test_program(
            &[BpfInsn::mov64_imm(BPF_REG_0, 7), BpfInsn::exit()],
            &pass_ctx(),
        );
        let err = prog
            .scan_block_starts(1, |_| Ok(Some((1, 1, ()))))
            .expect_err("out-of-range local start should fail");
        assert!(err.to_string().contains("window match start index 1"));
    }
}
