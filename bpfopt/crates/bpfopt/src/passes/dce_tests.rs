// SPDX-License-Identifier: MIT

use super::const_prop::ConstPropPass;
use super::dce::DcePass;
use crate::insn::*;
use crate::test_helpers::*;
use std::collections::HashMap;

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
fn dce_removes_dead_defs_exposed_by_const_prop_without_branch_cleanup() {
    let input = vec![
        BpfInsn::mov32_imm(BPF_REG_1, 20),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_1, 32),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_1, 32),
        BpfInsn::jeq_imm(BPF_REG_1, 20, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let ctx = ctx_with_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(BPF_REG_1, scalar_reg(20u64 << 32))])),
        verifier_delta_state(2, HashMap::from([(BPF_REG_1, scalar_reg(20))])),
    ]);

    let (results, lowered, _) = run_pipeline_on_insns(
        vec![Box::new(ConstPropPass), Box::new(DcePass)],
        input,
        &ctx,
    );

    assert_eq!(results[1].sites_applied, 4);
    assert_diagnostic(&results[1], "dead-def");
    assert_eq!(
        lowered,
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, 20),
            BpfInsn::jeq_imm(BPF_REG_1, 20, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ]
    );
}
