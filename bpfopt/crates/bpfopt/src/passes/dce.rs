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

#[cfg(test)]
mod tests {
    use super::*;

    use crate::analysis::CFGAnalysis;
    use crate::insn::*;
    use crate::passes::ConstPropPass;
    use std::collections::HashMap;

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn run_const_prop_then_dce(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(ConstPropPass);
        pm.add_pass(DcePass);
        pm.run(program, &PassContext::test_default()).unwrap()
    }

    fn scalar_reg(value: u64) -> RegState {
        RegState {
            reg_type: "scalar".to_string(),
            value_width: VerifierValueWidth::Bits64,
            precise: true,
            exact_value: Some(value),
            tnum: Some(Tnum { value, mask: 0 }),
            range: ScalarRange {
                smin: Some(value as i64),
                smax: Some(value as i64),
                umin: Some(value),
                umax: Some(value),
                smin32: Some(value as u32 as i32),
                smax32: Some(value as u32 as i32),
                umin32: Some(value as u32),
                umax32: Some(value as u32),
            },
            offset: None,
            id: None,
        }
    }

    fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
        VerifierInsn {
            pc,
            frame: 0,
            from_pc: None,
            kind: VerifierInsnKind::InsnDeltaState,
            speculative: false,
            regs,
            stack: HashMap::new(),
        }
    }

    #[test]
    fn dce_removes_dead_defs_exposed_by_const_prop_without_branch_cleanup() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov32_imm(1, 20),
            BpfInsn::alu64_imm(BPF_LSH, 1, 32),
            BpfInsn::alu64_imm(BPF_RSH, 1, 32),
            jeq_imm(1, 20, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.set_verifier_states(vec![
            verifier_delta_state(1, HashMap::from([(1, scalar_reg(20u64 << 32))])),
            verifier_delta_state(2, HashMap::from([(1, scalar_reg(20))])),
        ]);

        let result = run_const_prop_then_dce(&mut program);
        assert_eq!(result.pass_results[1].pass_name, "dce");
        assert_eq!(result.pass_results[1].sites_applied, 4);
        assert!(result.pass_results[1]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("dead-def")));
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 20),
                jeq_imm(1, 20, 0),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }
}
