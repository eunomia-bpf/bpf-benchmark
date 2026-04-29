// SPDX-License-Identifier: MIT
// Dead code elimination after constant propagation.

use crate::analysis::CFGAnalysis;
use crate::pass::*;

use super::utils::{
    compose_addr_maps, eliminate_dead_register_defs, eliminate_dead_register_defs_tail_safe,
    eliminate_nops, eliminate_unreachable_blocks_with_cfg, tail_call_protected_prefix_end,
};

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
        let protected_prefix_end = tail_call_protected_prefix_end(&final_insns);
        let mut final_addr_map: Option<Vec<usize>> = None;
        let mut unreachable_removed = 0usize;
        let mut dead_defs_removed = 0usize;
        let mut dead_defs_neutralized = 0usize;
        let mut nop_removed = 0usize;

        if protected_prefix_end.is_none() {
            if let Some((cleaned_insns, cleanup_map)) =
                eliminate_unreachable_blocks_with_cfg(&final_insns, &cfg)
            {
                unreachable_removed = final_insns.len() - cleaned_insns.len();
                final_addr_map = Some(cleanup_map);
                final_insns = cleaned_insns;
            }
        }

        if let Some(prefix_end) = protected_prefix_end {
            if let Some((cleaned_insns, cleanup_map, neutralized, deleted)) =
                eliminate_dead_register_defs_tail_safe(&final_insns, prefix_end)
            {
                dead_defs_neutralized = neutralized;
                dead_defs_removed = deleted;
                final_addr_map = Some(match final_addr_map.take() {
                    Some(existing) => compose_addr_maps(&existing, &cleanup_map),
                    None => cleanup_map,
                });
                final_insns = cleaned_insns;
            }
        } else if let Some((cleaned_insns, cleanup_map)) =
            eliminate_dead_register_defs(&final_insns)
        {
            dead_defs_removed = final_insns.len() - cleaned_insns.len();
            final_addr_map = Some(match final_addr_map.take() {
                Some(existing) => compose_addr_maps(&existing, &cleanup_map),
                None => cleanup_map,
            });
            final_insns = cleaned_insns;
        }

        if protected_prefix_end.is_none() {
            while let Some((cleaned_insns, cleanup_map)) = eliminate_nops(&final_insns) {
                nop_removed += final_insns.len() - cleaned_insns.len();
                final_addr_map = Some(match final_addr_map.take() {
                    Some(existing) => compose_addr_maps(&existing, &cleanup_map),
                    None => cleanup_map,
                });
                final_insns = cleaned_insns;
            }
        }

        let Some(final_addr_map) = final_addr_map else {
            return Ok(PassResult::unchanged(self.name()));
        };

        let sites_applied =
            unreachable_removed + dead_defs_neutralized + dead_defs_removed + nop_removed;
        let mut diagnostics = Vec::new();
        if unreachable_removed > 0 {
            diagnostics.push(format!("removed {} unreachable insns", unreachable_removed));
        }
        if dead_defs_neutralized > 0 {
            diagnostics.push(format!(
                "neutralized {} dead-def insns to preserve tail-call poke indices",
                dead_defs_neutralized
            ));
        }
        if dead_defs_removed > 0 {
            diagnostics.push(format!("removed {} dead-def insns", dead_defs_removed));
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

    fn call_helper(imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm,
        }
    }

    fn pseudo_func_ref(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_DW | BPF_IMM,
                regs: BpfInsn::make_regs(dst, BPF_PSEUDO_FUNC),
                off: 0,
                imm,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ]
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
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
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
    fn dce_removes_dead_defs_exposed_by_const_prop() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov32_imm(1, 20),
            BpfInsn::alu64_imm(BPF_LSH, 1, 32),
            BpfInsn::alu64_imm(BPF_RSH, 1, 32),
            jeq_imm(1, 20, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let result = run_const_prop_then_dce(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[1].pass_name, "dce");
        assert!(result.pass_results[1]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("dead-def")));
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
    }

    #[test]
    fn dce_neutralizes_dead_defs_before_tail_call() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(8, 1),
            BpfInsn::mov64_imm(8, 2),
            call_helper(12),
            exit_insn(),
        ]);

        let result = run_dce_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_reg(8, 8),
                BpfInsn::mov64_reg(8, 8),
                call_helper(12),
                exit_insn(),
            ]
        );
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

    #[test]
    fn dce_preserves_callback_only_subprog_and_rewrites_func_ref() {
        let callback = pseudo_func_ref(2, 4);
        let mut program = BpfProgram::new(vec![
            BpfInsn::ja(1),           // 0
            BpfInsn::mov64_imm(0, 9), // 1: dead
            callback[0],              // 2
            callback[1],              // 3
            BpfInsn::mov64_imm(0, 0), // 4
            exit_insn(),              // 5
            BpfInsn::mov64_imm(0, 8), // 6: dead
            BpfInsn::mov64_reg(0, 1), // 7: callback subprog entry
            exit_insn(),              // 8
        ]);

        let result = run_dce_pass(&mut program);

        assert!(result.program_changed);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn {
                    code: BPF_LD | BPF_DW | BPF_IMM,
                    regs: BpfInsn::make_regs(2, BPF_PSEUDO_FUNC),
                    off: 0,
                    imm: 3,
                },
                callback[1],
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
                BpfInsn::mov64_reg(0, 1),
                exit_insn(),
            ]
        );
        assert!(program.insns[0].is_ldimm64_pseudo_func());
        assert_eq!(program.insns[0].imm, 3);
        assert_eq!(0usize + 1 + program.insns[0].imm as usize, 4);
    }

    /// After const_prop folds a conditional branch, the dead block that
    /// contained the only pseudo-call to a subprog should be removed, AND the
    /// now-orphaned subprog should also be removed. Otherwise the verifier
    /// would report "unreachable insn N" for the orphaned subprog.
    #[test]
    fn dce_removes_orphaned_subprog_after_const_prop() {
        // Program:
        //   0: mov r1, 7
        //   1: jeq r1, 7, +2  (always taken -> jump to pc 4)
        //   2: call sub (pc 6) -- dead after const_prop folds the branch
        //   3: exit             -- dead
        //   4: mov r0, 0
        //   5: exit
        //   6: mov r0, 3   -- subprog entry (orphaned after DCE removes pc 2)
        //   7: exit
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7), // 0
            jeq_imm(1, 7, 2),         // 1: always taken
            pseudo_call(3),           // 2: dead block
            exit_insn(),              // 3: dead block
            BpfInsn::mov64_imm(0, 0), // 4: branch target (live)
            exit_insn(),              // 5
            BpfInsn::mov64_imm(0, 3), // 6: subprog entry (orphaned)
            exit_insn(),              // 7
        ]);

        let result = run_const_prop_then_dce(&mut program);

        assert!(result.program_changed);
        // The orphaned subprog should be removed entirely.
        // After const_prop: jeq becomes JA +2, dead block (call+exit) becomes
        // unreachable, subprog has no remaining callers.
        assert_eq!(
            program.insns,
            vec![BpfInsn::mov64_imm(0, 0), exit_insn(),],
            "orphaned subprog should be removed; got {:?}",
            program.insns
        );
    }

    /// When const_prop folds a branch and one path (with a subprog call) dies,
    /// but there's another live call to the same subprog, the subprog must be
    /// preserved.
    #[test]
    fn dce_preserves_subprog_with_remaining_live_caller() {
        // Program:
        //   0: call sub (pc 5) -- live call
        //   1: mov r1, 7
        //   2: jeq r1, 7, +1  (always taken -> jump to pc 4)
        //   3: call sub (pc 1) -- dead call (different imm, still targets sub)
        //   4: mov r0, 0
        //   5: exit
        //   6: mov r0, 3   -- subprog entry (still has live caller at pc 0)
        //   7: exit
        let mut program = BpfProgram::new(vec![
            pseudo_call(5),           // 0: live call to subprog at pc 6
            BpfInsn::mov64_imm(1, 7), // 1
            jeq_imm(1, 7, 1),         // 2: always taken
            pseudo_call(2),           // 3: dead call to subprog at pc 6
            BpfInsn::mov64_imm(0, 0), // 4
            exit_insn(),              // 5
            BpfInsn::mov64_imm(0, 3), // 6: subprog entry
            exit_insn(),              // 7
        ]);

        let result = run_const_prop_then_dce(&mut program);

        assert!(result.program_changed);
        // Subprog must be preserved because pc 0 still calls it.
        let has_subprog = program.insns.iter().any(|i| *i == BpfInsn::mov64_imm(0, 3));
        assert!(
            has_subprog,
            "subprog with live caller should be preserved; got {:?}",
            program.insns
        );
    }
}
