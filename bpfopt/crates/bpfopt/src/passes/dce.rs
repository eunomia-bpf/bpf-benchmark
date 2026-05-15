// SPDX-License-Identifier: MIT

use crate::analysis::{DefSite, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::{BpfPass, PassContext, PassResult};
use std::collections::BTreeSet;

pub struct DcePass;

impl BpfPass for DcePass {
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut sites_applied = 0usize;

        loop {
            let mut dead_defs = BTreeSet::new();
            for def in prog.def_sites()? {
                if prog.uses_for_def(def)?.is_empty() && is_removable_dead_def(prog, def)? {
                    dead_defs.insert(def);
                }
            }
            if dead_defs.is_empty() {
                break;
            }
            if would_empty_all_bodies(prog, &dead_defs)? {
                break;
            }
            for def in dead_defs.into_iter().rev() {
                prog.delete_insn(def)?;
                sites_applied += 1;
            }
        }

        let diagnostics = (sites_applied > 0)
            .then(|| format!("removed {} dead defs", sites_applied))
            .into_iter()
            .collect();
        Ok(PassResult {
            sites_applied,
            diagnostics,
            ..PassResult::default()
        })
    }
}

fn would_empty_all_bodies(
    prog: &ProgramCFG,
    dead_defs: &BTreeSet<DefSite>,
) -> anyhow::Result<bool> {
    let removable_sites = dead_defs
        .iter()
        .map(|def| InsnSite {
            block: def.block,
            idx: def.idx,
        })
        .collect::<BTreeSet<_>>();
    for block in prog.block_ids() {
        if !prog
            .sites_in_block(block)?
            .into_iter()
            .all(|site| removable_sites.contains(&site))
        {
            return Ok(false);
        }
    }
    Ok(true)
}

fn is_removable_dead_def(prog: &ProgramCFG, def: DefSite) -> anyhow::Result<bool> {
    let site = InsnSite {
        block: def.block,
        idx: def.idx,
    };
    let Some(insn) = prog.insn_at(site) else {
        anyhow::bail!("dead-def candidate {:?} has no instruction", def);
    };
    let is_self_move = matches!(insn.class(), BPF_ALU | BPF_ALU64)
        && bpf_op(insn.code) == BPF_MOV
        && bpf_src(insn.code) == BPF_X
        && insn.dst_reg() == insn.src_reg();
    if is_self_move {
        return Ok(false);
    }

    Ok(match insn.class() {
        BPF_ALU | BPF_ALU64 | BPF_LDX => def.reg == insn.dst_reg(),
        BPF_LD if insn.is_ldimm64() && !insn.is_ldimm64_pseudo_func() => def.reg == insn.dst_reg(),
        _ => false,
    })
}
