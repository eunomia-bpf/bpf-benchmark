// SPDX-License-Identifier: MIT
//! Use-def graph construction for BBProgram.

use std::collections::{BTreeMap, BTreeSet, HashSet};

use crate::analysis::{BBProgram, BlockId, InsnSite};
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

#[derive(Clone, Debug, Default)]
pub struct UseDefGraph {
    pub(super) defs: BTreeMap<DefSite, Vec<UseSite>>,
    pub(super) uses: BTreeMap<UseSite, Vec<DefSite>>,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct RegUseDefSet {
    pub uses: HashSet<u8>,
    pub defs: HashSet<u8>,
}

type ReachingState = BTreeMap<u8, BTreeSet<DefSite>>;

impl UseDefGraph {
    pub fn build(prog: &BBProgram) -> anyhow::Result<Self> {
        let site_facts = kinsn_aware_site_facts(prog)?;
        let mut in_states = vec![ReachingState::new(); prog.blocks.len()];
        let mut changed = true;

        while changed {
            changed = false;
            let mut next_in_states = in_states.clone();
            for block in prog.blocks() {
                let out_state =
                    process_block_state(prog, block.id, &site_facts, &in_states[block.id.0], None)?;
                for succ in prog.dataflow_successors(block.id)? {
                    let Some(succ_state) = next_in_states.get_mut(succ.0) else {
                        anyhow::bail!("block {:?} has invalid successor {:?}", block.id, succ);
                    };
                    if merge_state(succ_state, &out_state) {
                        changed = true;
                    }
                }
            }
            in_states = next_in_states;
        }

        let mut graph = Self::default();
        for block in prog.blocks() {
            process_block_state(
                prog,
                block.id,
                &site_facts,
                &in_states[block.id.0],
                Some(&mut graph),
            )?;
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

fn process_block_state(
    prog: &BBProgram,
    block: BlockId,
    site_facts: &BTreeMap<InsnSite, RegUseDefSet>,
    input: &ReachingState,
    graph: Option<&mut UseDefGraph>,
) -> anyhow::Result<ReachingState> {
    let mut graph = graph;
    let mut state = input.clone();
    for site in prog.sites_in_block_with_terminator(block)? {
        let Some(facts) = site_facts.get(&site) else {
            anyhow::bail!("missing use-def facts for site {:?}", site);
        };
        if let Some(graph) = graph.as_deref_mut() {
            record_uses(graph, site, facts, &state);
        }
        for &reg in &facts.defs {
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

fn record_uses(
    graph: &mut UseDefGraph,
    site: InsnSite,
    facts: &RegUseDefSet,
    state: &ReachingState,
) {
    for &reg in &facts.uses {
        let use_site = UseSite {
            block: site.block,
            idx: site.idx,
            reg,
        };
        let defs = if let Some(defs) = state.get(&reg) {
            defs.iter().copied().collect::<Vec<_>>()
        } else {
            Vec::new()
        };
        for def in &defs {
            graph.defs.entry(*def).or_default().push(use_site);
        }
        graph.uses.insert(use_site, defs);
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

fn kinsn_aware_site_facts(prog: &BBProgram) -> anyhow::Result<BTreeMap<InsnSite, RegUseDefSet>> {
    let mut facts = BTreeMap::new();
    let mut sites = Vec::new();

    for block in prog.blocks() {
        for site in prog.sites_in_block_with_terminator(block.id)? {
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            facts.insert(site, insn_use_def_set(insn));
            sites.push(site);
        }
    }

    for index in 0..sites.len() {
        let site = sites[index];
        let call = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if !call.is_call_kinsn() {
            continue;
        }
        let Some(&sidecar_site) = index.checked_sub(1).and_then(|i| sites.get(i)) else {
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
        validate_register_uses(descriptor.name, site, &uses)?;
        facts.insert(sidecar_site, RegUseDefSet::default());
        facts.insert(
            site,
            RegUseDefSet {
                uses,
                defs: HashSet::new(),
            },
        );
    }

    Ok(facts)
}

fn validate_register_uses(name: &str, site: InsnSite, uses: &RegSet) -> anyhow::Result<()> {
    for &reg in uses {
        if reg > BPF_REG_10 {
            anyhow::bail!(
                "{name} kinsn call at {:?} uses invalid register r{reg}",
                site
            );
        }
    }
    Ok(())
}

pub fn insn_use_def_set(insn: &BpfInsn) -> RegUseDefSet {
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

    RegUseDefSet { uses, defs }
}
