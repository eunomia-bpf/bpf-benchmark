// SPDX-License-Identifier: MIT

use crate::analysis::{BlockId, FrameId};
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn bbprogram_predecessors_are_derived_from_symbolic_successors() {
    let insns = vec![
        BpfInsn::jeq_imm(BPF_REG_1, 0, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    assert_eq!(prog.successors(BlockId(0)), &[BlockId(1), BlockId(2)]);
    assert_eq!(prog.predecessors(BlockId(1)), &[BlockId(0)]);
    assert_eq!(prog.predecessors(BlockId(2)), &[BlockId(0), BlockId(1)]);
    // IMPL: needs BBProgram::dominance() -> Dominance with dominates(a, b).
    let dom = prog.dominance();
    assert!(dom.dominates(BlockId(0), BlockId(1)));
    assert!(dom.dominates(BlockId(0), BlockId(2)));
}

#[test]
fn bbprogram_cfg_edges_use_ja32_imm_target() {
    // P1-G defect 2 coverage at the graph API layer.
    let insns = vec![
        BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    assert_eq!(prog.successors(BlockId(0)), &[BlockId(2)]);
    assert_eq!(prog.predecessors(BlockId(2)), &[BlockId(0)]);
}

#[test]
fn bbprogram_subprog_blocks_cover_callback_body_range() {
    // P1-H strengthened fixture: a real pseudo-call callback must map PCs 3..5
    // to one non-entry frame instead of flattening all blocks into frame 0.
    let insns = vec![
        BpfInsn::pseudo_call_to(0, 3),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(BPF_REG_1, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let prog = lift_test_program(&insns, &pass_ctx());

    // IMPL: needs BBProgram::subprog_blocks(FrameId) -> impl Iterator<Item = BlockId>.
    let callback_blocks = prog.subprog_blocks(FrameId(1)).collect::<Vec<_>>();
    assert_eq!(callback_blocks, vec![BlockId(2)]);
}
