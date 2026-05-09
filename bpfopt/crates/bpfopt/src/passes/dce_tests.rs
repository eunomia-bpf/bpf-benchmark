use super::dce::*;
use crate::pass::*;

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::passes::ConstPropPass;
use crate::test_helpers::*;
use std::collections::HashMap;

fn run_const_prop_then_dce(program: &mut BpfProgram) -> PipelineResult {
    let mut pm = PassManager::new();
    pm.register_analysis(CFGAnalysis);
    pm.add_pass(ConstPropPass);
    pm.add_pass(DcePass);
    pm.run(program, &PassContext::baseline()).unwrap()
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
        BpfInsn::exit(),
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
            BpfInsn::exit(),
        ]
    );
}
