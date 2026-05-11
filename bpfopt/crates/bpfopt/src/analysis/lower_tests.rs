// SPDX-License-Identifier: MIT

use crate::insn::*;

#[test]
fn fixup_all_branches_rewrites_ja32_imm_after_growth() {
    let mut insn = BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 1);

    insn.set_branch_target_delta(42).unwrap();

    assert_eq!(insn.off, 0);
    assert_eq!(insn.imm, 42);
}

#[test]
fn fixup_all_branches_rejects_i16_overflow() {
    let mut insn = BpfInsn::ja(0);

    let err = insn
        .set_branch_target_delta(i64::from(i16::MAX) + 1)
        .unwrap_err();

    assert!(err.to_string().contains("exceeds i16"));
}

#[test]
fn fixup_all_branches_rejects_ja32_i32_overflow() {
    let mut insn = BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 0);

    let err = insn
        .set_branch_target_delta(i64::from(i32::MAX) + 1)
        .unwrap_err();

    assert!(err.to_string().contains("exceeds i32"));
}
