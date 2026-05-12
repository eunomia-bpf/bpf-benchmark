// SPDX-License-Identifier: MIT

use super::*;
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn map_inline_const_prop_dce_cascade_uses_one_bbprogram_pipeline() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 1),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_1, 1),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_1),
        BpfInsn::exit(),
    ];
    let ctx = ctx_with_verifier_states(vec![verifier_delta_state(
        1,
        std::collections::HashMap::from([(BPF_REG_1, scalar_reg(2))]),
    )]);

    let (results, lowered, _) = run_pipeline_on_insns(
        vec![Box::new(ConstPropPass), Box::new(DcePass)],
        input,
        &ctx,
    );

    assert_eq!(results.len(), 2);
    assert!(lowered.contains(&BpfInsn::mov64_imm(BPF_REG_1, 2)));
}
