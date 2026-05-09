// SPDX-License-Identifier: MIT

use super::branch_target::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::Analysis;
use crate::test_helpers::*;

fn pseudo_func_ref(dst: u8, pc: usize, target_pc: usize) -> [BpfInsn; 2] {
    let imm = target_pc as i64 - (pc as i64 + 1);
    ld_imm64(dst, BPF_PSEUDO_FUNC, imm)
}

#[test]
fn branch_target_simple_ja() {
    let insns = vec![
        BpfInsn::ja(2),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(1, 1),
        BpfInsn::exit(),
    ];
    let prog = make_program(insns);
    let result = BranchTargetAnalysis.run(&prog);
    assert!(!result.is_target[0]);
    assert!(!result.is_target[1]);
    assert!(!result.is_target[2]);
    assert!(result.is_target[3]);
}

#[test]
fn branch_target_cond_jmp() {
    let insns = vec![jeq_imm(1, 0, 1), BpfInsn::nop(), BpfInsn::exit()];
    let prog = make_program(insns);
    let result = BranchTargetAnalysis.run(&prog);
    assert!(result.is_target[2]);
}

#[test]
fn branch_target_pseudo_func_callback() {
    let callback = pseudo_func_ref(2, 0, 4);
    let prog = make_program(vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_reg(0, 1),
        BpfInsn::exit(),
    ]);
    let result = BranchTargetAnalysis.run(&prog);

    assert!(result.is_target[4]);
}

#[test]
fn branch_target_no_branches() {
    let insns = vec![BpfInsn::mov64_imm(0, 42), BpfInsn::exit()];
    let prog = make_program(insns);
    let result = BranchTargetAnalysis.run(&prog);
    assert!(!result.is_target[0]);
    assert!(!result.is_target[1]);
}
