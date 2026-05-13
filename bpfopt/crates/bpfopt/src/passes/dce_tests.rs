// SPDX-License-Identifier: MIT

use super::dce::DcePass;
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn dce_preserves_kinsn_implicit_register_uses() {
    // P1-F: DCE must not delete values consumed only through a kinsn sidecar.
    let btf_id = 0x1234;
    let payload = BpfInsn::pack_u4(BPF_REG_6, 0)
        | BpfInsn::pack_u4(BPF_REG_6, 4)
        | BpfInsn::pack_u4(BPF_REG_0, 8)
        | BpfInsn::pack_u4(BPF_REG_1, 12);
    let ctx = ctx_with_kinsn("bpf_select64", btf_id);
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_6, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(btf_id, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(DcePass, input, &ctx);

    assert_eq!(
        &run.lowered[..5],
        &[
            BpfInsn::mov64_imm(BPF_REG_6, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::mov64_imm(BPF_REG_1, 7),
            BpfInsn::kinsn_sidecar(payload),
            BpfInsn::call_kinsn_with_off(btf_id, 0),
        ]
    );
}

#[test]
fn dce_sees_kinsn_implicit_register_defs() {
    // The old r6 value is dead because bpf_select64 defines r6 via payload[0].
    let btf_id = 0x1234;
    let payload = BpfInsn::pack_u4(BPF_REG_6, 0)
        | BpfInsn::pack_u4(BPF_REG_0, 4)
        | BpfInsn::pack_u4(BPF_REG_1, 8)
        | BpfInsn::pack_u4(BPF_REG_2, 12);
    let ctx = ctx_with_kinsn("bpf_select64", btf_id);
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_6, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_1, 7),
        BpfInsn::mov64_imm(BPF_REG_2, 1),
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(btf_id, 0),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_6),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(DcePass, input, &ctx);

    assert!(!run.lowered.contains(&BpfInsn::mov64_imm(BPF_REG_6, 0)));
    assert!(run
        .lowered
        .contains(&BpfInsn::call_kinsn_with_off(btf_id, 0)));
}
