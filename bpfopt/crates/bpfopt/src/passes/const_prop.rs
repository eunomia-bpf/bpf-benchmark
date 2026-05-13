// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;

pub(super) const VERIFIER_POST_STATE_POINTER_TYPE: &str =
    "register has pointer type, cannot materialize";

pub struct ConstPropPass;

impl BpfPass for ConstPropPass {
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        if prog.is_empty() {
            return Ok(PassResult::default());
        }
        let mut candidates = Vec::<(InsnSite, Vec<BpfInsn>)>::new();
        let mut sites_skipped = Vec::new();
        for block in prog.block_ids().collect::<Vec<_>>() {
            for site in prog.sites_in_block(block)? {
                if prog.site_is_dead_code(site) {
                    continue;
                }
                let insn = *prog.insn(site)?;
                if !matches!(insn.class(), BPF_ALU | BPF_ALU64) {
                    continue;
                }
                // MOV r, K is already a constant load — nothing to fold.
                if bpf_op(insn.code) == BPF_MOV && bpf_src(insn.code) == BPF_K {
                    continue;
                }
                let dst_reg = insn.dst_reg();
                if reg_kind_is_pointer(prog.reg_kind(site, dst_reg)) {
                    sites_skipped.push(SiteSkipReason::new(site, VERIFIER_POST_STATE_POINTER_TYPE));
                    continue;
                }
                let Some(value) = prog.reg_known_constant(site, dst_reg) else {
                    continue;
                };
                let is_32 = insn.class() == BPF_ALU;
                let replacement = emit_scalar_const_load(dst_reg, value as u64, is_32);
                if replacement.len() == 1 && replacement[0] == insn {
                    continue;
                }
                candidates.push((site, replacement));
            }
        }
        if candidates.is_empty() {
            if sites_skipped.is_empty() {
                return Ok(PassResult::default());
            }
            return Ok(PassResult {
                site_skipped: sites_skipped,
                diagnostics: vec!["const_prop_alu_materialized=0".to_string()],
                ..Default::default()
            });
        }
        let alu_materialized = candidates.len();
        candidates.sort_by_key(|(site, _)| *site);
        let applied =
            apply_candidates_reverse(prog, &candidates, &mut sites_skipped, |_, _, repl| {
                Ok((1, repl.clone()))
            })?;
        Ok(PassResult {
            sites_applied: applied,
            site_skipped: sites_skipped,
            diagnostics: vec![format!("const_prop_alu_materialized={alu_materialized}")],
            ..Default::default()
        })
    }
}

fn reg_kind_is_pointer(kind: Option<RegKind>) -> bool {
    matches!(
        kind,
        Some(
            RegKind::FramePointer
                | RegKind::Context
                | RegKind::PacketPointer
                | RegKind::PacketMetaPointer
                | RegKind::MapPointer
                | RegKind::MapValue
                | RegKind::MapKey
                | RegKind::Memory
                | RegKind::BtfStructPointer
                | RegKind::OtherPointer
        )
    )
}
