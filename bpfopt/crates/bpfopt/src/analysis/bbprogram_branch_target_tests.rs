// SPDX-License-Identifier: MIT

use crate::analysis::{BlockId, Terminator};
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn bbprogram_ja32_successor_uses_imm_target() {
    // P1-G defect 2: JA32 stores its PC-relative target in imm, not off.
    let insns = vec![
        BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    assert!(prog.successors(BlockId(0)).contains(&BlockId(2)));
    assert!(matches!(
        prog.blocks().next().unwrap().terminator,
        Terminator::Jump {
            target: BlockId(2),
            ..
        }
    ));
}

#[test]
fn bbprogram_cond_branch_exposes_taken_and_fallthrough_edges() {
    let insns = vec![
        BpfInsn::jeq_imm(BPF_REG_1, 0, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
    assert!(matches!(
        prog.blocks().next().unwrap().terminator,
        Terminator::CondBranch {
            taken: BlockId(2),
            fallthrough: BlockId(1),
            ..
        }
    ));
}

#[test]
fn bbprogram_pseudo_call_records_callee_and_return_blocks() {
    let insns = vec![
        BpfInsn::pseudo_call_to(0, 3),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    assert!(matches!(
        prog.blocks().next().unwrap().terminator,
        Terminator::Call {
            callee: BlockId(2),
            return_to: BlockId(1),
            ..
        }
    ));
    assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
}
