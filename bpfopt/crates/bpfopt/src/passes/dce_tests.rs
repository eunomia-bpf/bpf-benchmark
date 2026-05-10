use super::dce::*;
use crate::pass::*;

use crate::insn::*;
use crate::passes::ConstPropPass;
use crate::test_helpers::*;
use std::collections::HashMap;

fn run_const_prop_then_dce(program: &mut BpfProgram) -> PipelineResult {
    let mut pm = PassManager::new();
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
        BpfInsn::jeq_imm(1, 20, 1),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(1, scalar_reg(20u64 << 32))])),
        verifier_delta_state(2, HashMap::from([(1, scalar_reg(20))])),
    ]);

    let result = run_const_prop_then_dce(&mut program);
    assert_eq!(result.pass_names[1], "dce");
    assert_eq!(result.pass_results[1].sites_applied, 4);
    assert!(result.pass_results[1]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("dead-def")));
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(1, 20),
            BpfInsn::jeq_imm(1, 20, 0),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn dce_preserves_kinsn_implicit_register_uses() {
    let btf_id = 0x1234;
    let payload = BpfInsn::pack_u4(BPF_REG_6, 0)
        | BpfInsn::pack_u4(BPF_REG_6, 4)
        | BpfInsn::pack_u4(BPF_REG_0, 8)
        | BpfInsn::pack_u4(BPF_REG_1, 12);
    assert_eq!(payload, 0x1066);

    let mut ctx = PassContext::baseline();
    ctx.kinsn_registry = KinsnRegistry::default();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_select64", btf_id, 0)
        .expect("test kinsn target should register");

    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(BPF_REG_6, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(btf_id, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ]);

    DcePass
        .run(&mut program, &mut AnalysisCache::new(), &ctx)
        .expect("DCE should preserve kinsn operand materialization");

    assert_eq!(
        &program.insns[..5],
        &[
            BpfInsn::mov64_imm(BPF_REG_6, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::mov64_imm(BPF_REG_1, 7),
            BpfInsn::kinsn_sidecar(payload),
            BpfInsn::call_kinsn_with_off(btf_id, 0),
        ]
    );
}
