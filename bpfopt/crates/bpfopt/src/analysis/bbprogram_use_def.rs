// SPDX-License-Identifier: MIT
//! Use-def graph construction for ProgramCFG.

use std::collections::{BTreeMap, BTreeSet, HashSet};

use crate::analysis::{BlockId, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::RegSet;

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct DefSite {
    pub block: BlockId,
    pub idx: usize,
    pub reg: u8,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct UseSite {
    pub block: BlockId,
    pub idx: usize,
    pub reg: u8,
}

/// Reverse index from def-site to its use-sites. The per-site `uses`/`defs`
/// register sets live inline on `InsnNode` / `BasicBlock`; this struct is the
/// single derived def→uses lookup table allowed by the design.
#[derive(Clone, Debug, Default)]
pub(crate) struct UseDefGraph {
    pub(super) defs: BTreeMap<DefSite, Vec<UseSite>>,
}

type ReachingState = BTreeMap<u8, BTreeSet<DefSite>>;

impl UseDefGraph {
    /// Populate per-site `uses`/`defs` on each InsnNode + BasicBlock terminator,
    /// then build the reverse def→uses index. Must be called from within
    /// `ProgramCFG::rebuild_use_def` so the program is mutable.
    pub fn build(prog: &mut ProgramCFG) -> anyhow::Result<Self> {
        populate_site_use_def(prog)?;

        let mut in_states = vec![ReachingState::new(); prog.blocks.len()];
        let mut changed = true;
        while changed {
            changed = false;
            let mut next_in_states = in_states.clone();
            for block_id in prog.block_ids().collect::<Vec<_>>() {
                let out_state = process_block_state(prog, block_id, &in_states[block_id.0], None)?;
                for succ in prog.dataflow_successors(block_id)? {
                    let Some(succ_state) = next_in_states.get_mut(succ.0) else {
                        anyhow::bail!("block {:?} has invalid successor {:?}", block_id, succ);
                    };
                    if merge_state(succ_state, &out_state) {
                        changed = true;
                    }
                }
            }
            in_states = next_in_states;
        }

        let mut graph = Self::default();
        for block_id in prog.block_ids().collect::<Vec<_>>() {
            process_block_state(prog, block_id, &in_states[block_id.0], Some(&mut graph))?;
        }
        Ok(graph)
    }

    pub fn uses_for(&self, def: DefSite) -> &[UseSite] {
        match self.defs.get(&def) {
            Some(uses) => uses.as_slice(),
            None => &[],
        }
    }

    pub fn defs(&self) -> impl Iterator<Item = &DefSite> {
        self.defs.keys()
    }
}

fn site_uses_defs<'a>(prog: &'a ProgramCFG, site: InsnSite) -> Option<(&'a RegSet, &'a RegSet)> {
    let block = prog.block_ref(site.block)?;
    if site.idx < block.insns.len() {
        let node = &block.insns[site.idx];
        Some((&node.uses, &node.defs))
    } else if site.idx == block.insns.len() {
        Some((&block.terminator_uses, &block.terminator_defs))
    } else {
        None
    }
}

fn process_block_state(
    prog: &ProgramCFG,
    block: BlockId,
    input: &ReachingState,
    graph: Option<&mut UseDefGraph>,
) -> anyhow::Result<ReachingState> {
    let mut graph = graph;
    let mut state = input.clone();
    for site in prog.sites_in_block_with_terminator(block)? {
        let (uses, defs) = site_uses_defs(prog, site)
            .ok_or_else(|| anyhow::anyhow!("missing use-def facts for site {:?}", site))?;
        if let Some(graph) = graph.as_deref_mut() {
            record_uses(graph, site, uses, &state);
        }
        for &reg in defs {
            let def = DefSite {
                block: site.block,
                idx: site.idx,
                reg,
            };
            state.insert(reg, BTreeSet::from([def]));
            if let Some(graph) = graph.as_deref_mut() {
                graph.defs.entry(def).or_default();
            }
        }
    }
    Ok(state)
}

fn record_uses(graph: &mut UseDefGraph, site: InsnSite, uses: &RegSet, state: &ReachingState) {
    for &reg in uses {
        let use_site = UseSite {
            block: site.block,
            idx: site.idx,
            reg,
        };
        if let Some(defs) = state.get(&reg) {
            for def in defs {
                graph.defs.entry(*def).or_default().push(use_site);
            }
        }
    }
}

fn merge_state(dst: &mut ReachingState, src: &ReachingState) -> bool {
    let mut changed = false;
    for (&reg, defs) in src {
        let entry = dst.entry(reg).or_default();
        let old_len = entry.len();
        entry.extend(defs.iter().copied());
        changed |= entry.len() != old_len;
    }
    changed
}

fn populate_site_use_def(prog: &mut ProgramCFG) -> anyhow::Result<()> {
    // Pass 1: every body insn and terminator gets its insn-derived uses/defs.
    for block_id in prog.block_ids().collect::<Vec<_>>() {
        let body_len = prog.block_ref(block_id).expect("block").insns.len();
        for idx in 0..body_len {
            let insn = prog.block_ref(block_id).expect("block").insns[idx].insn;
            let (uses, defs) = insn_use_def_pair(&insn);
            let node = &mut prog.block_mut_for_use_def(block_id)?.insns[idx];
            node.uses = uses;
            node.defs = defs;
        }
        if let Some(term_insn) = prog
            .block_ref(block_id)
            .expect("block")
            .terminator
            .raw_insn()
        {
            let (uses, defs) = insn_use_def_pair(&term_insn);
            let block = prog.block_mut_for_use_def(block_id)?;
            block.terminator_uses = uses;
            block.terminator_defs = defs;
        } else {
            let block = prog.block_mut_for_use_def(block_id)?;
            block.terminator_uses = Default::default();
            block.terminator_defs = Default::default();
        }
    }

    // Pass 2: kinsn-aware overrides. A `call <kinsn>` consumes registers per
    // its descriptor; its preceding `BPF_LD` sidecar contributes none.
    for block_id in prog.block_ids().collect::<Vec<_>>() {
        let sites: Vec<InsnSite> = prog
            .sites_in_block_with_terminator(block_id)?
            .into_iter()
            .collect();
        for window_idx in 0..sites.len() {
            let site = sites[window_idx];
            let call = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            if !call.is_call_kinsn() {
                continue;
            }
            let Some(&sidecar_site) = window_idx.checked_sub(1).and_then(|i| sites.get(i)) else {
                anyhow::bail!("kinsn call at {:?} is missing its packed sidecar", site);
            };
            let sidecar = prog
                .insn_at(sidecar_site)
                .ok_or_else(|| anyhow::anyhow!("missing kinsn sidecar at {:?}", sidecar_site))?;
            if !sidecar.is_kinsn_sidecar() {
                anyhow::bail!("kinsn call at {:?} is missing its packed sidecar", site);
            }
            let descriptor = prog.kinsn_reg.lookup_by_kinsn_call(call.imm, call.off)?;
            let payload = sidecar.sidecar_payload();
            let uses = (descriptor.register_uses)(payload);
            let defs = (descriptor.register_defs)(payload);
            validate_registers(descriptor.name, site, "uses", &uses)?;
            validate_registers(descriptor.name, site, "defs", &defs)?;

            let block = prog.block_mut_for_use_def(block_id)?;
            // Sidecar contributes neither uses nor defs.
            if sidecar_site.idx < block.insns.len() {
                block.insns[sidecar_site.idx].uses = Default::default();
                block.insns[sidecar_site.idx].defs = Default::default();
            }
            if site.idx < block.insns.len() {
                block.insns[site.idx].uses = uses;
                block.insns[site.idx].defs = defs;
            } else {
                block.terminator_uses = uses;
                block.terminator_defs = defs;
            }
        }
    }
    Ok(())
}

fn validate_registers(
    name: &str,
    site: InsnSite,
    label: &str,
    regs: &RegSet,
) -> anyhow::Result<()> {
    for &reg in regs {
        if reg > BPF_REG_10 {
            anyhow::bail!(
                "{name} kinsn call at {:?} {label} invalid register r{reg}",
                site
            );
        }
    }
    Ok(())
}

fn insn_use_def_pair(insn: &BpfInsn) -> (RegSet, RegSet) {
    let mut uses = HashSet::new();
    let mut defs = HashSet::new();

    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            if op == BPF_MOV {
                defs.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            } else {
                defs.insert(insn.dst_reg());
                uses.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            }
        }
        BPF_LDX => {
            defs.insert(insn.dst_reg());
            uses.insert(insn.src_reg());
        }
        BPF_ST | BPF_STX => {
            uses.insert(insn.dst_reg());
            if insn.class() == BPF_STX {
                uses.insert(insn.src_reg());
            }
        }
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                for reg in 1..=5 {
                    uses.insert(reg);
                }
                for reg in 0..=5 {
                    defs.insert(reg);
                }
            } else if insn.is_exit() {
                uses.insert(0);
            } else {
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
                if !insn.is_ja() {
                    uses.insert(insn.dst_reg());
                }
            }
        }
        BPF_LD => {
            defs.insert(insn.dst_reg());
        }
        _ => {}
    }

    (uses, defs)
}

/// Public API result struct preserved so passes can access `.uses` / `.defs`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub(crate) struct RegUseDefSet {
    pub uses: RegSet,
    pub defs: RegSet,
}

pub(crate) fn insn_use_def_set(insn: &BpfInsn) -> RegUseDefSet {
    let (uses, defs) = insn_use_def_pair(insn);
    RegUseDefSet { uses, defs }
}
