// SPDX-License-Identifier: MIT
// Dead register definition elimination after constant propagation.

use crate::pass::*;

use super::utils::{eliminate_dead_register_defs, remap_btf_metadata};

/// Dead code elimination pass.
///
/// Scope:
/// - remove side-effect-free register definitions whose results are dead
pub struct DcePass;

impl BpfPass for DcePass {
    fn name(&self) -> &str {
        "dce"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec![]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let Some((final_insns, final_addr_map)) = eliminate_dead_register_defs(&program.insns)
        else {
            return Ok(PassResult::unchanged(self.name()));
        };

        let sites_applied = program.insns.len() - final_insns.len();
        let mut diagnostics = Vec::new();
        if sites_applied > 0 {
            diagnostics.push(format!("removed {} dead-def insns", sites_applied));
        }

        program.insns = final_insns;
        remap_btf_metadata(program, &final_addr_map)?;
        program.remap_annotations(&final_addr_map);
        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied,
            sites_skipped: vec![],
            diagnostics,
            ..Default::default()
        })
    }
}
