// SPDX-License-Identifier: MIT

use super::liveness::{insn_use_def, LivenessAnalysis};
use crate::insn::*;
use crate::pass::Analysis;
use crate::test_helpers::*;

#[test]
fn liveness_simple_def_use() {
    let insns = vec![BpfInsn::mov64_imm(0, 42), exit_insn()];
    let prog = make_program(insns);
    let liveness = LivenessAnalysis.run(&prog);
    assert!(liveness.live_out[0].contains(&0));
    assert!(!liveness.live_out[1].contains(&0));
}

#[test]
fn liveness_register_killed() {
    let insns = vec![
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::mov64_reg(0, 1),
        exit_insn(),
    ];
    let prog = make_program(insns);
    let liveness = LivenessAnalysis.run(&prog);
    assert!(liveness.live_out[0].contains(&1));
    assert!(!liveness.live_out[1].contains(&1));
    assert!(liveness.live_out[1].contains(&0));
}

#[test]
fn liveness_branch_merges() {
    let insns = vec![
        jeq_imm(1, 0, 1),
        BpfInsn::mov64_imm(2, 5),
        BpfInsn::mov64_reg(0, 2),
        exit_insn(),
    ];
    let prog = make_program(insns);
    let liveness = LivenessAnalysis.run(&prog);
    assert!(liveness.live_out[1].contains(&2));
}

#[test]
fn use_def_alu_imm() {
    let insn = BpfInsn::alu64_imm(BPF_LSH, 1, 8);
    let (uses, defs) = insn_use_def(&insn);
    assert!(uses.contains(&1));
    assert!(defs.contains(&1));
}

#[test]
fn use_def_mov_reg() {
    let insn = BpfInsn::mov64_reg(0, 1);
    let (uses, defs) = insn_use_def(&insn);
    assert!(uses.contains(&1));
    assert!(!uses.contains(&0));
    assert!(defs.contains(&0));
}

#[test]
fn use_def_call() {
    let insn = BpfInsn::call_kfunc(42);
    let (uses, defs) = insn_use_def(&insn);
    for r in 1..=5 {
        assert!(uses.contains(&r));
    }
    // BPF calling convention: r0 = return value, r1-r5 = clobbered
    for r in 0..=5 {
        assert!(defs.contains(&r), "r{} should be in defs for call", r);
    }
}

#[test]
fn liveness_call_clobbers_caller_saved() {
    // After a call, r1-r5 are dead (clobbered).
    // r6 is callee-saved, so it should remain live across the call.
    let insns = vec![
        BpfInsn::mov64_imm(6, 42), // r6 = 42
        BpfInsn::mov64_imm(1, 1),  // r1 = 1 (arg)
        BpfInsn::call_kfunc(99),   // call; clobbers r0-r5
        BpfInsn::mov64_reg(0, 6),  // r0 = r6 (use callee-saved)
        exit_insn(),
    ];
    let prog = make_program(insns);
    let liveness = LivenessAnalysis.run(&prog);
    // r6 should be live across the call (live_out[2] should contain r6)
    assert!(liveness.live_out[2].contains(&6));
    // r1 should NOT be live after the call (it's clobbered)
    assert!(!liveness.live_out[2].contains(&1));
}

#[test]
fn use_def_exit() {
    let (uses, defs) = insn_use_def(&exit_insn());
    assert!(uses.contains(&0));
    assert!(defs.is_empty());
}

#[test]
fn use_def_ldx() {
    let insn = BpfInsn::ldx_mem(BPF_W, 0, 6, 4);
    let (uses, defs) = insn_use_def(&insn);
    assert!(uses.contains(&6));
    assert!(defs.contains(&0));
}

#[test]
fn use_def_stx() {
    let insn = BpfInsn::stx_mem(BPF_DW, 10, 1, -8);
    let (uses, _defs) = insn_use_def(&insn);
    assert!(uses.contains(&10));
    assert!(uses.contains(&1));
}
