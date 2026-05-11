// SPDX-License-Identifier: MIT

use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn bbprogram_map_bindings_preserve_loader_fd_order() {
    let a = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, 11);
    let b = BpfInsn::ld_imm64(BPF_REG_2, BPF_PSEUDO_MAP_FD, 22);
    let mut ctx = pass_ctx();
    set_map_ids(&mut ctx, vec![101, 202]);
    let prog = lift_test_program(&[a[0], a[1], b[0], b[1], BpfInsn::exit()], &ctx);

    // IMPL: needs BBProgram::map_bindings() -> &[MapBinding] based on PassContext map_ids.
    let bindings = prog.map_bindings();
    assert_eq!(bindings[0].old_fd, 11);
    assert_eq!(bindings[0].map_id, 101);
    assert_eq!(bindings[1].old_fd, 22);
    assert_eq!(bindings[1].map_id, 202);
}

#[test]
fn bbprogram_map_bindings_survive_dead_pseudo_load_deletion() {
    let a = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, 11);
    let b = BpfInsn::ld_imm64(BPF_REG_2, BPF_PSEUDO_MAP_FD, 22);
    let mut ctx = pass_ctx();
    set_map_ids(&mut ctx, vec![101, 202]);
    let mut prog = lift_test_program(&[a[0], a[1], b[0], b[1], BpfInsn::exit()], &ctx);
    let def = prog
        .reaching_defs(crate::analysis::BlockId(0))
        .defs_for(BPF_REG_1)
        .next()
        .expect("map fd r1 def should exist");

    prog.delete_insn(def)
        .expect("delete should keep stable binding");

    let bindings = prog.map_bindings();
    assert_eq!(bindings[0].old_fd, 11);
    assert_eq!(bindings[0].map_id, 101);
    assert_eq!(bindings[1].old_fd, 22);
    assert_eq!(bindings[1].map_id, 202);
}
