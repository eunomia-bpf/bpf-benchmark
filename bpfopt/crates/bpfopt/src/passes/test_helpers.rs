// SPDX-License-Identifier: MIT
//! Shared test helper functions for pass unit tests.
//!
//! This module is `#[cfg(test)]` only. Import with:
//! `use crate::passes::test_helpers::*;`

use crate::insn::*;

/// Return a BPF EXIT instruction.
pub fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

/// Return a BPF helper-call instruction (src_reg = 0).
pub fn call_helper(imm: i32) -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, imm)
}

/// Return a BPF_PSEUDO_CALL instruction whose offset encodes
/// `target_pc - (call_pc + 1)`.
pub fn pseudo_call_to(call_pc: usize, target_pc: usize) -> BpfInsn {
    let imm = target_pc as i64 - (call_pc as i64 + 1);
    BpfInsn::new(
        BPF_JMP | BPF_CALL,
        BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
        0,
        imm as i32,
    )
}
