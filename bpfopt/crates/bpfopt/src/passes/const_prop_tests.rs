// SPDX-License-Identifier: MIT

use super::const_prop::*;
use crate::insn::*;
use crate::test_helpers::*;
use std::collections::HashMap;

fn run_const_prop(input: Vec<BpfInsn>, states: Vec<crate::pass::VerifierInsn>) -> PassRun {
    let ctx = ctx_with_verifier_states(states);
    run_pass_on_insns(ConstPropPass, input, &ctx)
}

#[test]
fn const_prop_folds_alu_chain_to_constant_mov() {
    let run = run_const_prop(
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, 4),
            BpfInsn::mov64_imm(BPF_REG_2, 8),
            BpfInsn::alu64_reg(BPF_ADD, BPF_REG_1, BPF_REG_2),
            BpfInsn::exit(),
        ],
        vec![verifier_delta_state(
            2,
            HashMap::from([(BPF_REG_1, scalar_reg(12))]),
        )],
    );

    assert_diagnostic(&run.result, "const_prop_alu_materialized=1");
    assert_eq!(
        run.lowered,
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, 4),
            BpfInsn::mov64_imm(BPF_REG_2, 8),
            BpfInsn::mov64_imm(BPF_REG_1, 12),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_folds_alu32_chain_to_mov32_imm() {
    let run = run_const_prop(
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, -1),
            BpfInsn::alu32_imm(BPF_ADD, BPF_REG_1, 1),
            BpfInsn::exit(),
        ],
        vec![verifier_delta_state(
            1,
            HashMap::from([(BPF_REG_1, scalar32_reg(0))]),
        )],
    );

    assert_eq!(
        run.lowered,
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, -1),
            BpfInsn::mov32_imm(BPF_REG_1, 0),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_tracks_ldimm64_constants() {
    let wide = BpfInsn::ld_imm64(BPF_REG_1, 0, 1_i64 << 32);
    let run = run_const_prop(
        vec![
            wide[0],
            wide[1],
            BpfInsn::add64_imm(BPF_REG_1, 1),
            BpfInsn::exit(),
        ],
        vec![verifier_delta_state(
            2,
            HashMap::from([(BPF_REG_1, scalar_reg(0x1_0000_0001))]),
        )],
    );

    assert!(run.lowered[2].is_ldimm64());
    assert_eq!(run.lowered[2].dst_reg(), BPF_REG_1);
    assert_eq!(run.lowered[2].imm as u32 as u64, 1);
    assert_eq!(run.lowered[3].imm as u32 as u64, 1);
}

#[test]
fn const_prop_does_not_fold_typed_ldimm64_map_value() {
    let typed = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_VALUE, (0x1a8_i64 << 32) | 0x11);
    let input = vec![
        typed[0],
        typed[1],
        BpfInsn::add64_imm(BPF_REG_1, 16),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(input.clone(), Vec::new());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_uses_verifier_exact_constants_for_alu_after_helper_calls() {
    let run = run_const_prop(
        vec![
            BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
            BpfInsn::add64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ],
        vec![verifier_delta_state(
            1,
            HashMap::from([(BPF_REG_0, scalar_reg(42))]),
        )],
    );

    assert_eq!(
        run.lowered,
        vec![
            BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
            BpfInsn::mov64_imm(BPF_REG_0, 42),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_does_not_seed_caller_saved_regs_from_call_post_state() {
    // P1-K: call-pc post-state for R0-R5 must not repopulate caller-saved facts.
    let input = vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
        BpfInsn::add64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![verifier_delta_state(
            0,
            HashMap::from([(BPF_REG_0, scalar_reg(41))]),
        )],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_post_state_guard_rejects_packet_pointer_copy_materialization() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 62),
        BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_1),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_7, 0),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![verifier_delta_state(
            1,
            HashMap::from([(BPF_REG_7, pkt_reg())]),
        )],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 1, VERIFIER_POST_STATE_POINTER_TYPE);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_post_state_guard_allows_scalar_exact_register_copy() {
    let run = run_const_prop(
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, 62),
            BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_1),
            BpfInsn::exit(),
        ],
        vec![verifier_delta_state(
            1,
            HashMap::from([(BPF_REG_7, scalar_reg(62))]),
        )],
    );

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(
        run.lowered,
        vec![
            BpfInsn::mov64_imm(BPF_REG_1, 62),
            BpfInsn::mov64_imm(BPF_REG_7, 62),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_rejects_edge_state_only_pointer_arithmetic_materialization() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_7, 0),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_7),
        BpfInsn::add64_imm(BPF_REG_3, 34),
        BpfInsn::ldx_mem(BPF_H, BPF_REG_2, BPF_REG_3, 2),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![
            verifier_delta_state(1, HashMap::from([(BPF_REG_3, pkt_reg())])),
            verifier_edge_state(2, HashMap::from([(BPF_REG_3, scalar_reg(34))])),
        ],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_rejects_replacement_when_observation_missing_at_some_visit() {
    let input = vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
        BpfInsn::nop(),
        BpfInsn::add64_imm(BPF_REG_3, 1),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![
            verifier_delta_state(3, HashMap::from([(BPF_REG_3, scalar_reg(99))])),
            verifier_delta_state(3, HashMap::new()),
        ],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_rejects_replacement_when_full_state_visit_omits_reg() {
    let input = vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
        BpfInsn::add64_imm(BPF_REG_3, 1),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![
            verifier_delta_state(1, HashMap::from([(BPF_REG_3, scalar_reg(42))])),
            verifier_full_state(1, HashMap::new()),
        ],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_rejects_replacement_across_disagreeing_frames() {
    let input = vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
        BpfInsn::add64_imm(BPF_REG_3, 1),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(
        input.clone(),
        vec![
            verifier_delta_state_in_frame(1, 0, HashMap::from([(BPF_REG_3, scalar_reg(42))])),
            verifier_delta_state_in_frame(1, 1, HashMap::from([(BPF_REG_3, scalar_reg(43))])),
        ],
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn const_prop_accepts_when_every_visit_agrees() {
    let run = run_const_prop(
        vec![
            BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
            BpfInsn::add64_imm(BPF_REG_3, 1),
            BpfInsn::exit(),
        ],
        vec![
            verifier_delta_state(1, HashMap::from([(BPF_REG_3, scalar_reg(42))])),
            verifier_delta_state(1, HashMap::from([(BPF_REG_3, scalar_reg(42))])),
        ],
    );

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(
        run.lowered,
        vec![
            BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 7),
            BpfInsn::mov64_imm(BPF_REG_3, 42),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_rejects_zero_divisor_without_panicking() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 9),
        BpfInsn::alu64_imm(BPF_DIV, BPF_REG_1, 0),
        BpfInsn::alu64_imm(BPF_MOD, BPF_REG_1, 0),
        BpfInsn::exit(),
    ];

    let run = run_const_prop(input.clone(), Vec::new());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}
