// SPDX-License-Identifier: MIT

use crate::analysis::{BlockId, InsnSite};
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn bbprogram_live_in_marks_register_used_before_local_def() {
    let insns = vec![
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_2, BPF_REG_1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &pass_ctx());

    assert!(prog.live_in(BlockId(0)).unwrap().contains(&BPF_REG_1));
    assert!(prog.live_in(BlockId(0)).unwrap().contains(&BPF_REG_2));
}

#[test]
fn bbprogram_live_out_propagates_across_branch_successors() {
    let insns = vec![
        BpfInsn::jeq_imm(BPF_REG_1, 0, 1),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_2, BPF_REG_3),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_4, BPF_REG_2),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &pass_ctx());

    assert!(prog.live_out(BlockId(0)).unwrap().contains(&BPF_REG_2));
    assert!(prog.live_in(BlockId(1)).unwrap().contains(&BPF_REG_3));
}

#[test]
fn bbprogram_liveness_models_helper_call_clobbers() {
    let insns = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_6, BPF_REG_1),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &pass_ctx());

    assert!(!prog.live_out(BlockId(0)).unwrap().contains(&BPF_REG_1));
    assert!(prog.live_in(BlockId(0)).unwrap().contains(&BPF_REG_6));
}

#[test]
fn bbprogram_liveness_includes_kinsn_implicit_register_uses() {
    // P1-F support: kinsn call operands are encoded in the sidecar, not in the
    // raw call register fields, and must be visible to DCE/liveness.
    let btf_id = 0x1234;
    let payload = BpfInsn::pack_u4(BPF_REG_6, 0)
        | BpfInsn::pack_u4(BPF_REG_0, 4)
        | BpfInsn::pack_u4(BPF_REG_1, 8);
    let ctx = ctx_with_kinsn("bpf_x86_cmovneq", btf_id);
    let insns = vec![
        BpfInsn::mov64_imm(BPF_REG_6, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(btf_id, 0),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &ctx);

    let kinsn_site = InsnSite {
        block: BlockId(0),
        idx: 4,
    };
    let live_in = prog.live_in_site_checked(kinsn_site).unwrap();
    assert!(live_in.contains(&BPF_REG_6));
    assert!(live_in.contains(&BPF_REG_0));
    assert!(live_in.contains(&BPF_REG_1));
}

#[test]
fn bbprogram_liveness_models_kinsn_implicit_register_defs() {
    let btf_id = 0x1234;
    let payload = BpfInsn::pack_u4(BPF_REG_3, 0) | BpfInsn::pack_u4(BPF_REG_1, 4) | (1 << 15);
    let ctx = ctx_with_kinsn("bpf_x86_leaq", btf_id);
    let insns = vec![
        BpfInsn::mov64_imm(BPF_REG_3, 99),
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(btf_id, 0),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_2, BPF_REG_3),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &ctx);

    let kinsn_site = InsnSite {
        block: BlockId(0),
        idx: 3,
    };
    let live_in = prog.live_in_site_checked(kinsn_site).unwrap();
    assert!(live_in.contains(&BPF_REG_1));
    assert!(!live_in.contains(&BPF_REG_3));
}

#[test]
fn bbprogram_liveness_recomputes_after_delete_insn() {
    let insns = vec![
        BpfInsn::mov64_imm(BPF_REG_2, 1),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_3, BPF_REG_2),
        BpfInsn::exit(),
    ];
    let mut prog = lift_test_program(&insns, &pass_ctx());
    let def = prog
        .def_sites()
        .expect("def_sites")
        .into_iter()
        .find(|d| d.block == BlockId(0) && d.reg == BPF_REG_2)
        .expect("r2 def should exist");

    prog.delete_insn(def).expect("delete should update use-def");

    assert!(prog.live_in(BlockId(0)).unwrap().contains(&BPF_REG_2));
}
