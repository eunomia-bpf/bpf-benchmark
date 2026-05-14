// SPDX-License-Identifier: MIT
//! Basic-block program representation for bpfopt pass execution.
use crate::analysis::bbprogram_btf::BtfRecordKind;
#[cfg(test)]
use crate::analysis::bbprogram_btf::{remap_btf_records_view, BtfRemapView};
use crate::analysis::bbprogram_lower::remap_btf_records_for_lowering;
use crate::analysis::verifier_facts;
use crate::analysis::VerifierStatesBySite;
use crate::analysis::{DefSite, UseDefGraph};
use crate::insn::{
    bpf_class, insn_width, BpfInsn, MapPseudo, BPF_LDX, BPF_REG_10, BPF_ST, BPF_STX,
};
use crate::pass::{BranchProfile, BtfInfoRecords, KinsnRegistry, RegKind, RegSet};
use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::sync::{Arc, Mutex};
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
pub struct MapBinding {
    pub old_fd: i32,
    pub map_id: u32,
}
#[derive(Debug)]
pub struct ProgramCFG {
    pub(super) blocks: Vec<BasicBlock>,
    pub(crate) entry: BlockId,
    pub(super) use_def: UseDefGraph,
    pub(super) verifier_states: Option<VerifierStatesBySite>,
    pub(super) branch_profile_by_site: BTreeMap<InsnSite, BranchProfile>,
    pub(super) btf: BtfMetadataMap,
    pub(super) kinsn_reg: Arc<KinsnRegistry>,
    pub(crate) map_bindings: Vec<MapBinding>,
    pub(crate) func_info: Option<BtfInfoRecords>,
    pub(crate) line_info: Option<BtfInfoRecords>,
    ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>,
    pub(crate) pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>,
    pub(super) prog_type: u32,
    site_liveness_cache: Mutex<Option<Arc<SiteLivenessSets>>>,
    lifted_reg_facts_cache: Mutex<Option<Arc<LiftedRegFacts>>>,
}

impl Clone for ProgramCFG {
    fn clone(&self) -> Self {
        Self {
            blocks: self.blocks.clone(),
            entry: self.entry,
            use_def: self.use_def.clone(),
            verifier_states: self.verifier_states.clone(),
            branch_profile_by_site: self.branch_profile_by_site.clone(),
            btf: self.btf.clone(),
            kinsn_reg: Arc::clone(&self.kinsn_reg),
            map_bindings: self.map_bindings.clone(),
            func_info: self.func_info.clone(),
            line_info: self.line_info.clone(),
            ldimm64_second_slots: self.ldimm64_second_slots.clone(),
            pc_relative_ldimm64_targets: self.pc_relative_ldimm64_targets.clone(),
            prog_type: self.prog_type,
            site_liveness_cache: Mutex::new(None),
            lifted_reg_facts_cache: Mutex::new(None),
        }
    }
}
#[derive(Clone, Debug)]
pub struct BasicBlock {
    pub id: BlockId,
    pub(super) insns: Vec<BpfInsn>,
    pub(super) terminator: Terminator,
    pub frame: FrameId,
    pub(super) predecessors: Vec<BlockId>,
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
impl ProgramCFG {
    pub(crate) fn new(
        blocks: Vec<BasicBlock>,
        entry: BlockId,
        verifier_states: Option<VerifierStatesBySite>,
        btf: BtfMetadataMap,
        kinsn_reg: Arc<KinsnRegistry>,
        ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>,
        pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>,
    ) -> anyhow::Result<Self> {
        let mut prog = Self {
            blocks,
            entry,
            use_def: UseDefGraph::default(),
            verifier_states,
            branch_profile_by_site: BTreeMap::new(),
            btf,
            kinsn_reg,
            map_bindings: Vec::new(),
            func_info: None,
            line_info: None,
            ldimm64_second_slots,
            pc_relative_ldimm64_targets,
            prog_type: 0,
            site_liveness_cache: Mutex::new(None),
            lifted_reg_facts_cache: Mutex::new(None),
        };
        prog.rebuild_cfg_edges()?;
        prog.rebuild_use_def()?;
        Ok(prog)
    }
    pub fn blocks(&self) -> impl Iterator<Item = &BasicBlock> {
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
        &self.blocks[block.0].predecessors
    }
    pub fn successors(&self, block: BlockId) -> Vec<BlockId> {
        let mut s = self.blocks[block.0].terminator.successors();
        s.sort_unstable();
        s.dedup();
        s
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
        let first = logical_sites_for_block(self.block(block)?)
            .into_iter()
            .next()
            .ok_or_else(|| anyhow::anyhow!("block {:?} has no sites", block))?;
        self.live_in_site_checked(first)
    }
    #[cfg(test)]
    pub fn live_out(&self, block: BlockId) -> anyhow::Result<RegSet> {
        let last = logical_sites_for_block(self.block(block)?)
            .into_iter()
            .next_back()
            .ok_or_else(|| anyhow::anyhow!("block {:?} has no sites", block))?;
        self.live_out_site_checked(last)
    }
    pub fn live_in_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet> {
        self.insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("invalid instruction site {:?}", site))?;
        self.site_liveness()?
            .live_in
            .get(&site)
            .cloned()
            .ok_or_else(|| anyhow::anyhow!("site liveness missing live_in for {:?}", site))
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
    pub fn map_bindings(&self) -> &[MapBinding] {
        &self.map_bindings
    }
    /// Resolve the kernel map id for a pseudo-map ldimm64 immediate.
    /// Returns the map id that was bound at ProgramCFG construction time;
    /// callers must skip the site if `None` (the construction snapshot
    /// is the authoritative source).
    pub fn map_id_for_imm(&self, imm: i32) -> Option<u32> {
        self.map_bindings
            .iter()
            .find(|binding| binding.old_fd == imm)
            .map(|binding| binding.map_id)
    }
    #[cfg(test)]
    pub(crate) fn verifier_states_by_site(&self) -> Option<&VerifierStatesBySite> {
        self.verifier_states.as_ref()
    }
    pub fn reg_known_constant(&self, site: InsnSite, reg: u8, is_32: bool) -> Option<i64> {
        if !self.verifier_post_state_reaches_site_once(site) {
            return None;
        }
        if self
            .verifier_runtime_divergent_regs_after_sites()
            .ok()?
            .get(&site)
            .is_some_and(|regs| regs.contains(&reg))
        {
            return None;
        }
        verifier_facts::reg_known_constant(self.verifier_states.as_ref(), site, reg, is_32)
    }
    pub fn reg_kind(&self, site: InsnSite, reg: u8) -> Option<RegKind> {
        verifier_facts::reg_kind(self.verifier_states.as_ref(), site, reg)
    }
    /// Returns the known constant bytes at the stack region the register
    /// points to, if the verifier proved them. Width is `key_width` bytes.
    pub fn reg_known_stack_bytes(
        &self,
        site: InsnSite,
        reg: u8,
        key_width: usize,
    ) -> Option<Vec<u8>> {
        verifier_facts::reg_known_stack_bytes(self.verifier_states.as_ref(), site, reg, key_width)
    }
    pub fn site_is_dead_code(&self, site: InsnSite) -> bool {
        verifier_facts::site_is_dead_code(self.verifier_states.as_ref(), site)
    }
    fn verifier_post_state_reaches_site_once(&self, site: InsnSite) -> bool {
        if self.insn_at(site).is_none() {
            return false;
        }
        self.block_has_single_reaching_state(site.block, &mut BTreeMap::new(), &mut BTreeSet::new())
    }
    fn block_has_single_reaching_state(
        &self,
        block: BlockId,
        memo: &mut BTreeMap<BlockId, bool>,
        visiting: &mut BTreeSet<BlockId>,
    ) -> bool {
        if let Some(&known) = memo.get(&block) {
            return known;
        }
        if !visiting.insert(block) {
            memo.insert(block, false);
            return false;
        }
        let result = if block == self.entry {
            true
        } else if let Some(block_ref) = self.blocks.get(block.0) {
            match block_ref.predecessors.as_slice() {
                [pred] if *pred != block => {
                    self.block_has_single_reaching_state(*pred, memo, visiting)
                }
                _ => false,
            }
        } else {
            false
        };
        visiting.remove(&block);
        memo.insert(block, result);
        result
    }
    fn verifier_runtime_divergent_regs_after_sites(
        &self,
    ) -> anyhow::Result<HashMap<InsnSite, RegSet>> {
        let site_facts = self.use_def_site_facts()?;
        let mut in_states = vec![(RegSet::new(), false); self.blocks.len()];
        let mut changed = true;

        while changed {
            changed = false;
            let mut next_in_states = in_states.clone();
            for block in self.blocks() {
                let (out_regs, out_stack) = self.process_verifier_runtime_divergence_block(
                    block.id,
                    &site_facts,
                    &in_states[block.id.0].0,
                    in_states[block.id.0].1,
                    None,
                )?;
                for succ in self.dataflow_successors(block.id)? {
                    let Some(succ_state) = next_in_states.get_mut(succ.0) else {
                        anyhow::bail!("block {:?} has invalid successor {:?}", block.id, succ);
                    };
                    let old_len = succ_state.0.len();
                    succ_state.0.extend(out_regs.iter().copied());
                    changed |= succ_state.0.len() != old_len;
                    if out_stack && !succ_state.1 {
                        succ_state.1 = true;
                        changed = true;
                    }
                }
            }
            in_states = next_in_states;
        }

        let mut after_sites = HashMap::new();
        for block in self.blocks() {
            self.process_verifier_runtime_divergence_block(
                block.id,
                &site_facts,
                &in_states[block.id.0].0,
                in_states[block.id.0].1,
                Some(&mut after_sites),
            )?;
        }
        Ok(after_sites)
    }
    fn use_def_site_facts(&self) -> anyhow::Result<HashMap<InsnSite, (RegSet, RegSet)>> {
        let mut facts = HashMap::new();
        for block in self.blocks() {
            for site in logical_sites_for_block(block) {
                facts.insert(site, (RegSet::new(), RegSet::new()));
            }
        }
        for use_site in self.use_def.uses.keys() {
            let site = InsnSite {
                block: use_site.block,
                idx: use_site.idx,
            };
            let Some((uses, _)) = facts.get_mut(&site) else {
                anyhow::bail!("use-def graph references invalid use site {:?}", site);
            };
            uses.insert(use_site.reg);
        }
        for def in self.use_def.defs.keys() {
            let site = InsnSite {
                block: def.block,
                idx: def.idx,
            };
            let Some((_, defs)) = facts.get_mut(&site) else {
                anyhow::bail!("use-def graph references invalid def site {:?}", site);
            };
            defs.insert(def.reg);
        }
        Ok(facts)
    }
    fn process_verifier_runtime_divergence_block(
        &self,
        block: BlockId,
        site_facts: &HashMap<InsnSite, (RegSet, RegSet)>,
        input: &RegSet,
        input_stack: bool,
        mut after_sites: Option<&mut HashMap<InsnSite, RegSet>>,
    ) -> anyhow::Result<(RegSet, bool)> {
        let mut state = input.clone();
        let mut stack_divergent = input_stack;
        for site in self.sites_in_block_with_terminator(block)? {
            let insn = self.insn_at(site);
            let (uses, defs) = site_facts
                .get(&site)
                .ok_or_else(|| anyhow::anyhow!("missing use-def facts for site {:?}", site))?;
            let input_depends_on_kinsn = uses.iter().any(|reg| state.contains(reg));
            let site_is_kinsn_call = insn.is_some_and(|insn| insn.is_call_kinsn());
            let input_depends_on_stack = stack_divergent && insn.is_some_and(insn_loads_from_stack);
            for &reg in defs {
                if site_is_kinsn_call || input_depends_on_kinsn || input_depends_on_stack {
                    state.insert(reg);
                } else {
                    state.remove(&reg);
                }
            }
            if let Some(insn) = insn {
                if input_depends_on_kinsn && insn_stores_to_stack(insn) {
                    stack_divergent = true;
                }
                if insn.is_kinsn_sidecar() {
                    state.insert(insn.dst_reg());
                }
            }
            if let Some(after_sites) = after_sites.as_deref_mut() {
                after_sites.insert(site, state.clone());
            }
        }
        Ok((state, stack_divergent))
    }
    pub fn branch_taken_rate(&self, site: InsnSite) -> Option<f32> {
        let profile = self.branch_profile_by_site.get(&site)?;
        let total = profile.taken_count.checked_add(profile.not_taken_count)?;
        (total != 0).then_some(profile.taken_count as f32 / total as f32)
    }
    pub fn branch_miss_rate(&self, site: InsnSite) -> Option<f32> {
        let miss_rate = self.branch_profile_by_site.get(&site)?.miss_rate;
        miss_rate.is_finite().then_some(miss_rate as f32)
    }
    pub fn site_hotness(&self, site: InsnSite) -> Option<u64> {
        Some(self.branch_profile_by_site.get(&site)?.branch_count)
    }
    pub(crate) fn attach_profile_from_annotations(
        &mut self,
        annotations: &[Option<BranchProfile>],
    ) -> anyhow::Result<()> {
        self.branch_profile_by_site.clear();
        for (pc, profile) in annotations.iter().enumerate() {
            let Some(profile) = profile else { continue };
            let site = self.original_pc_to_site(pc).ok_or_else(|| {
                anyhow::anyhow!("profile pc {pc} is not present in the control-flow graph")
            })?;
            self.branch_profile_by_site.insert(site, profile.clone());
        }
        Ok(())
    }
    pub fn def_sites(&self) -> impl Iterator<Item = DefSite> + '_ {
        self.use_def.defs().copied()
    }
    /// First in-frame predecessor site (in linear layout order, no CFG) that
    /// defines `reg`. Returns `None` if no such site exists within the frame.
    /// Callers that need CFG/dominance reasoning must not use this primitive.
    pub fn prev_def_in_frame(&self, start: InsnSite, reg: u8) -> anyhow::Result<Option<InsnSite>> {
        for site in crate::pass::sites_before_in_frame_rev(self, start)? {
            if crate::analysis::insn_use_def_set(self.insn(site)?)
                .defs
                .contains(&reg)
            {
                return Ok(Some(site));
            }
        }
        Ok(None)
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
            .ok_or_else(|| anyhow::anyhow!("no instruction at site {:?}", site))
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
        for block in &mut self.blocks {
            block.predecessors.clear();
        }
        let blocks_len = self.blocks.len();
        for from in 0..blocks_len {
            let from_id = self.blocks[from].id;
            for succ in self.blocks[from].terminator.successors() {
                if succ.0 >= blocks_len {
                    anyhow::bail!(
                        "block {:?} terminator references invalid successor {:?}",
                        from_id,
                        succ
                    );
                }
                self.blocks[succ.0].predecessors.push(from_id);
            }
        }
        for block in &mut self.blocks {
            block.predecessors.sort_unstable();
            block.predecessors.dedup();
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
    pub(crate) fn invalidate_verifier_states(&mut self) {
        self.verifier_states = None;
        self.branch_profile_by_site.clear();
    }
    pub(crate) fn rebuild_use_def_after_mutation(&mut self) -> anyhow::Result<()> {
        self.rebuild_use_def()?;
        self.invalidate_verifier_states();
        Ok(())
    }
    pub fn remapped_func_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_for_lowering(self, self.func_info.as_ref(), BtfRecordKind::Func)
    }
    pub fn remapped_line_info_records(&self) -> anyhow::Result<Option<BtfInfoRecords>> {
        remap_btf_records_for_lowering(self, self.line_info.as_ref(), BtfRecordKind::Line)
    }
    pub(super) fn block(&self, block: BlockId) -> anyhow::Result<&BasicBlock> {
        self.blocks
            .get(block.0)
            .ok_or_else(|| anyhow::anyhow!("invalid block id {:?}", block))
    }
    pub(super) fn block_mut(&mut self, block: BlockId) -> anyhow::Result<&mut BasicBlock> {
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
            for start_idx in 0..body.sites.len() {
                let lookahead_end = start_idx
                    .checked_add(max_lookahead)
                    .map(|end| end.min(body.insns.len()))
                    .ok_or_else(|| anyhow::anyhow!("lookahead at {start_idx} overflows"))?;
                let window = BlockStartWindow {
                    block,
                    start_idx,
                    insns: body.insns,
                    lookahead: &body.insns[start_idx..lookahead_end],
                };
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
fn collect_map_bindings(insns: &[BpfInsn], map_ids: &[u32]) -> anyhow::Result<Vec<MapBinding>> {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if let Some(kind) = insn.map_pseudo() {
            let map_id = resolve_map_id(kind, insn.imm, map_ids, &mut fd_order)?;
            if let Some(map_id) = map_id {
                bindings.push(MapBinding {
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
fn insn_loads_from_stack(insn: &BpfInsn) -> bool {
    bpf_class(insn.code) == BPF_LDX && insn.src_reg() == BPF_REG_10
}
fn insn_stores_to_stack(insn: &BpfInsn) -> bool {
    matches!(bpf_class(insn.code), BPF_ST | BPF_STX) && insn.dst_reg() == BPF_REG_10
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
fn current_site_pcs(prog: &ProgramCFG) -> anyhow::Result<BTreeMap<InsnSite, usize>> {
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
fn current_block_start_pcs(prog: &ProgramCFG) -> anyhow::Result<Vec<usize>> {
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
fn block_logical_slot_len(prog: &ProgramCFG, block: BlockId) -> anyhow::Result<usize> {
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
    prog: &ProgramCFG,
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
fn site_offset_in_block_slots(prog: &ProgramCFG, site: InsnSite) -> anyhow::Result<usize> {
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
fn logical_sites_for_block(block: &BasicBlock) -> Vec<InsnSite> {
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
struct SiteLivenessSets {
    live_in: HashMap<InsnSite, RegSet>,
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
fn compute_site_liveness(prog: &ProgramCFG) -> anyhow::Result<SiteLivenessSets> {
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
    Ok(SiteLivenessSets { live_in, live_out })
}
fn compute_lifted_reg_facts(prog: &ProgramCFG) -> anyhow::Result<LiftedRegFacts> {
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
        for (block_idx, site) in sites.iter().copied().enumerate() {
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
            let kinsn_call_defs = if insn.is_call_kinsn() {
                let sidecar_site = block_idx
                    .checked_sub(1)
                    .and_then(|i| sites.get(i).copied())
                    .ok_or_else(|| {
                        anyhow::anyhow!("kinsn call at {:?} is missing its packed sidecar", site)
                    })?;
                let sidecar = prog.insn_at(sidecar_site).ok_or_else(|| {
                    anyhow::anyhow!("missing kinsn sidecar instruction at {:?}", sidecar_site)
                })?;
                if !sidecar.is_kinsn_sidecar() {
                    anyhow::bail!("kinsn call at {:?} is missing its packed sidecar", site);
                }
                let descriptor = prog.kinsn_reg.lookup_by_kinsn_call(insn.imm, insn.off)?;
                Some((descriptor.register_defs)(sidecar.sidecar_payload()))
            } else {
                None
            };
            advance_lifted_regs(
                insn,
                ldimm64_hi,
                kinsn_call_defs.as_ref(),
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
    kinsn_call_defs: Option<&RegSet>,
    site: InsnSite,
    layout: Option<crate::insn::PacketCtxLayout>,
    regs: &mut [LiftedRegFact; 11],
    last_data_load: &mut Option<InsnSite>,
) -> anyhow::Result<()> {
    use crate::insn::{
        bpf_op, bpf_size, bpf_src, decode_ldimm64_value, BPF_ADD, BPF_ALU, BPF_ALU64, BPF_K,
        BPF_LD, BPF_LDX, BPF_MEM, BPF_MOV, BPF_REG_0, BPF_REG_5, BPF_SUB, BPF_W, BPF_X, BPF_XOR,
    };
    // kinsn sidecar carries dst/off/imm as packed metadata for the immediately
    // following kinsn call. It is not a real assignment, so it must not update
    // any reg fact — otherwise its dst_reg field (= the upcoming kinsn dst)
    // would be falsely set to Const(payload imm) here.
    if insn.is_kinsn_sidecar() {
        return Ok(());
    }
    if insn.is_call_kinsn() {
        // kinsn calls have explicit register defs declared by KinsnDescriptor.
        // Clear only those regs; preserve all others (packet facts, scratch
        // regs, last_data_load). kinsn modules do not mutate packets.
        let defs = kinsn_call_defs.ok_or_else(|| {
            anyhow::anyhow!("kinsn call at {:?} missing resolved descriptor defs", site)
        })?;
        for &reg in defs {
            regs[reg as usize] = LiftedRegFact::Unknown;
        }
        return Ok(());
    }
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
fn site_successors(prog: &ProgramCFG, site: InsnSite) -> anyhow::Result<Vec<InsnSite>> {
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
    prog: &ProgramCFG,
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
impl ProgramCFG {
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
                assert_eq!(window.start_idx, 0);
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
                Ok((window.start_idx == 2).then_some((1, 2, ())))
            })
            .expect("backward-start scan should succeed");
        assert_eq!(hits.len(), 1);
        assert_eq!(hits[0].start_idx, 1);
        assert_eq!(hits[0].start, InsnSite::for_test(BlockId(0), 1));
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
