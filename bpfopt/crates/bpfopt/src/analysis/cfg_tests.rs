// SPDX-License-Identifier: MIT

use super::cfg::CFGAnalysis;
use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

#[test]
fn cfg_records_subprog_end_boundaries() {
    let program = BpfProgram::new(vec![
        BpfInsn::pseudo_call_to(0, 3),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]);

    let cfg = CFGAnalysis::run(&program);

    assert_eq!(cfg.subprogs.len(), 2);
    assert_eq!(cfg.subprogs[0].start, 0);
    assert_eq!(cfg.subprogs[0].end, 3);
    assert_eq!(cfg.subprogs[1].start, 3);
    assert_eq!(cfg.subprogs[1].end, 5);
}

#[test]
fn cfg_subprog_bounds_maps_pc_to_range() {
    let callback = BpfInsn::ld_imm64(2, BPF_PSEUDO_FUNC, 4);
    let program = BpfProgram::new(vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_reg(0, 1),
        BpfInsn::exit(),
    ]);

    let cfg = CFGAnalysis::run(&program);

    assert_eq!(cfg.subprog_bounds(1), Some(0..5));
    assert_eq!(cfg.subprog_bounds(5), Some(5..6));
    assert_eq!(cfg.subprog_bounds(6), None);
}

#[test]
fn cfg_edges_use_ja32_imm_target() {
    let program = BpfProgram::new(vec![
        BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(1, 1),
        BpfInsn::exit(),
    ]);

    let cfg = CFGAnalysis::run(&program);
    let entry = cfg.insn_to_block[0];
    let target = cfg.insn_to_block[3];

    assert_eq!(cfg.blocks[entry].succs, vec![target]);
}
