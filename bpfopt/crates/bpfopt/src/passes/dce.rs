// SPDX-License-Identifier: MIT
// Dead register definition elimination on BBProgram.

use crate::analysis::{BBProgram, DefSite};
use crate::insn::*;
use crate::pass::{BpfPass, PassContext, PassResult};
use std::collections::BTreeSet;

/// Dead code elimination pass.
///
/// Scope:
/// - remove side-effect-free register definitions whose results are dead
pub struct DcePass;

impl BpfPass for DcePass {
    fn name(&self) -> &str {
        "dce"
    }

    fn run(&self, program: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram) -> anyhow::Result<PassResult> {
    let mut sites_applied = 0usize;

    loop {
        let mut dead_defs = BTreeSet::new();
        for &def in prog.use_def.defs.keys() {
            if prog.use_def.uses_for(def).is_empty() && is_removable_dead_def(prog, def)? {
                dead_defs.insert(def);
            }
        }
        if dead_defs.is_empty() {
            break;
        }
        if would_empty_all_bodies(prog, &dead_defs) {
            break;
        }
        for def in dead_defs.into_iter().rev() {
            sites_applied += prog.delete_insn(def)?;
        }
    }

    let diagnostics = if sites_applied > 0 {
        vec![format!("removed {} dead-def insns", sites_applied)]
    } else {
        Vec::new()
    };
    Ok(PassResult {
        sites_applied,
        diagnostics,
        ..PassResult::unchanged()
    })
}

fn would_empty_all_bodies(prog: &BBProgram, dead_defs: &BTreeSet<DefSite>) -> bool {
    let removable_sites = dead_defs
        .iter()
        .map(|def| def.site())
        .collect::<BTreeSet<_>>();
    prog.blocks().all(|block| {
        block.insns.iter().enumerate().all(|(idx, _)| {
            removable_sites.contains(&crate::analysis::InsnSite {
                block: block.id,
                idx,
            })
        })
    })
}

fn is_removable_dead_def(prog: &BBProgram, def: DefSite) -> anyhow::Result<bool> {
    let Some(insn) = prog.insn_at(def.site()) else {
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
