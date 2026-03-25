// SPDX-License-Identifier: MIT
//! Dead code elimination after constant propagation.

use crate::analysis::CFGAnalysis;
use crate::pass::*;

use super::utils::{compose_addr_maps, eliminate_nops, eliminate_unreachable_blocks_with_cfg};

/// Dead code elimination pass.
///
/// v1 scope:
/// - remove CFG-unreachable basic blocks
/// - remove `ja +0` NOPs to a fixed point after branch fixups
///
/// Dead register definition elimination is intentionally left for a later pass.
pub struct DcePass;

impl BpfPass for DcePass {
    fn name(&self) -> &str {
        "dce"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let cfg = analyses.get(&CFGAnalysis, program);
        let mut final_insns = program.insns.clone();
        let mut final_addr_map: Option<Vec<usize>> = None;
        let mut unreachable_removed = 0usize;
        let mut nop_removed = 0usize;

        if let Some((cleaned_insns, cleanup_map)) =
            eliminate_unreachable_blocks_with_cfg(&final_insns, &cfg)
        {
            unreachable_removed = final_insns.len() - cleaned_insns.len();
            final_addr_map = Some(cleanup_map);
            final_insns = cleaned_insns;
        }

        while let Some((cleaned_insns, cleanup_map)) = eliminate_nops(&final_insns) {
            nop_removed += final_insns.len() - cleaned_insns.len();
            final_addr_map = Some(match final_addr_map.take() {
                Some(existing) => compose_addr_maps(&existing, &cleanup_map),
                None => cleanup_map,
            });
            final_insns = cleaned_insns;
        }

        let Some(final_addr_map) = final_addr_map else {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![],
                diagnostics: vec![],
                ..Default::default()
            });
        };

        let sites_applied = unreachable_removed + nop_removed;
        let mut diagnostics = Vec::new();
        if unreachable_removed > 0 {
            diagnostics.push(format!("removed {} unreachable insns", unreachable_removed));
        }
        if nop_removed > 0 {
            diagnostics.push(format!("removed {} nop insns", nop_removed));
        }

        program.insns = final_insns;
        program.remap_annotations(&final_addr_map);
        program.log_transform(TransformEntry { sites_applied });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied,
            sites_skipped: vec![],
            diagnostics,
            ..Default::default()
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::insn::*;
    use crate::passes::ConstPropPass;

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn pseudo_call(off: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
            off: 0,
            imm: off,
        }
    }

    fn run_dce_pass(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(DcePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    fn run_const_prop_then_dce(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(ConstPropPass);
        pm.add_pass(DcePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    #[test]
    fn dce_removes_dead_branch_after_const_prop() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7),
            jeq_imm(1, 7, 1),
            BpfInsn::mov64_imm(2, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let result = run_const_prop_then_dce(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[1].pass_name, "dce");
        assert_eq!(result.pass_results[1].sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 7),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn dce_removes_nops_to_fixed_point() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::ja(2),
            BpfInsn::nop(),
            BpfInsn::nop(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let result = run_dce_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 3);
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
    }

    #[test]
    fn dce_preserves_subprog_entries() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 0),
            pseudo_call(2),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
            BpfInsn::mov64_imm(0, 3),
            exit_insn(),
        ]);

        let result = run_dce_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(
            program.insns,
            vec![
                pseudo_call(2),
                BpfInsn::mov64_imm(0, 2),
                exit_insn(),
                BpfInsn::mov64_imm(0, 3),
                exit_insn(),
            ]
        );
    }
}
