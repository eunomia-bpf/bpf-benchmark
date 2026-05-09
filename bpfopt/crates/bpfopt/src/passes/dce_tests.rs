use super::dce::*;
use crate::pass::*;

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
