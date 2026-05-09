use super::const_prop::*;
use crate::analysis::*;
use crate::insn::*;
use crate::pass::*;
use crate::test_helpers::*;
use std::collections::HashMap;

fn scalar_reg_with_width(value: u64, value_width: VerifierValueWidth) -> RegState {
    RegState {
        reg_type: "scalar".to_string(),
        value_width,
        precise: true,
        exact_value: Some(value),
        tnum: Some(Tnum { value, mask: 0 }),
        range: ScalarRange {
            smin: Some(value as i64),
            smax: Some(value as i64),
            umin: Some(value),
            umax: Some(value),
            smin32: Some(value as u32 as i32),
            smax32: Some(value as u32 as i32),
            umin32: Some(value as u32),
            umax32: Some(value as u32),
        },
        offset: None,
        id: None,
    }
}

fn pkt_reg() -> RegState {
    RegState::new("pkt", VerifierValueWidth::Bits64)
}

fn verifier_delta_state_in_frame(
    pc: usize,
    frame: usize,
    regs: HashMap<u8, RegState>,
) -> VerifierInsn {
    verifier_state_in_frame(pc, frame, VerifierInsnKind::InsnDeltaState, regs)
}

fn verifier_state_in_frame(
    pc: usize,
    frame: usize,
    kind: VerifierInsnKind,
    regs: HashMap<u8, RegState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame,
        from_pc: None,
        kind,
        speculative: false,
        regs,
        stack: HashMap::new(),
    }
}

fn run_const_prop_pass(program: &mut BpfProgram) -> PipelineResult {
    let mut pm = PassManager::new();
    pm.register_analysis(CFGAnalysis);
    pm.add_pass(ConstPropPass);
    pm.run(program, &PassContext::baseline()).unwrap()
}

fn diagnostic_counter(pass: &PassResult, key: &str) -> usize {
    let prefix = format!("{key}=");
    pass.diagnostics
        .iter()
        .find_map(|diag| diag.strip_prefix(&prefix))
        .unwrap_or_else(|| panic!("missing diagnostic counter {key}"))
        .parse()
        .unwrap_or_else(|err| panic!("invalid diagnostic counter {key}: {err}"))
}

#[test]
fn const_prop_folds_alu_chain_to_constant_mov() {
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(1, 4),
        BpfInsn::mov64_imm(2, 8),
        BpfInsn::alu64_reg(BPF_ADD, 1, 2),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![verifier_delta_state(
        2,
        HashMap::from([(1, scalar_reg(12))]),
    )]);

    let result = run_const_prop_pass(&mut program);
    let pass = &result.pass_results[0];
    assert_eq!(diagnostic_counter(pass, "const_prop_alu_materialized"), 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(1, 4),
            BpfInsn::mov64_imm(2, 8),
            BpfInsn::mov64_imm(1, 12),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_folds_alu32_chain_to_mov32_imm() {
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(1, -1),
        BpfInsn::new(BPF_ALU | BPF_ADD | BPF_K, BpfInsn::make_regs(1, 0), 0, 1),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![verifier_delta_state(
        1,
        HashMap::from([(1, scalar_reg_with_width(0, VerifierValueWidth::Bits32))]),
    )]);

    let _result = run_const_prop_pass(&mut program);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(1, -1),
            BpfInsn::mov32_imm(1, 0),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_tracks_ldimm64_constants() {
    let wide = ld_imm64(1, 0, 1_i64 << 32);
    let mut program = BpfProgram::new(vec![wide[0], wide[1], add64_imm(1, 1), BpfInsn::exit()]);
    program.set_verifier_states(vec![verifier_delta_state(
        2,
        HashMap::from([(1, scalar_reg(0x1_0000_0001))]),
    )]);

    let _result = run_const_prop_pass(&mut program);
    assert_eq!(program.insns.len(), 5);
    assert!(program.insns[2].is_ldimm64());
    assert_eq!(program.insns[2].dst_reg(), 1);
    assert_eq!(program.insns[2].imm as u32 as u64, 1);
    assert_eq!(program.insns[3].imm as u32 as u64, 1);
    assert_eq!(program.insns[4], BpfInsn::exit());
}

#[test]
fn const_prop_does_not_fold_typed_ldimm64_map_value() {
    let typed = ld_imm64(1, 2, (0x1a8_i64 << 32) | 0x11);
    let original = vec![typed[0], typed[1], add64_imm(1, 16), BpfInsn::exit()];
    let mut program = BpfProgram::new(original.clone());

    let _result = run_const_prop_pass(&mut program);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_uses_verifier_exact_constants_for_alu_after_helper_calls() {
    let mut program = BpfProgram::new(vec![
        BpfInsn::helper_call(7),
        add64_imm(0, 1),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![verifier_delta_state(
        1,
        HashMap::from([(0, scalar_reg(42))]),
    )]);

    let _result = run_const_prop_pass(&mut program);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::helper_call(7),
            BpfInsn::mov64_imm(0, 42),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_does_not_seed_caller_saved_regs_from_call_post_state() {
    // Bug caught: a call-pc verifier post-state for R0-R5 must not repopulate
    // caller-saved regs after call handling cleared them in the abstract model.
    let original = vec![BpfInsn::helper_call(7), add64_imm(0, 1), BpfInsn::exit()];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![verifier_delta_state(
        0,
        HashMap::from([(0, scalar_reg(41))]),
    )]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_does_not_use_oracle_for_register_mov_provenance() {
    // Bug caught: a verifier pre-state exact value for MOV X's destination
    // must not replace a register copy that may transfer pointer provenance.
    let original = vec![BpfInsn::mov64_reg(2, 3), add64_imm(2, 1), BpfInsn::exit()];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![verifier_state_in_frame(
        0,
        0,
        VerifierInsnKind::PcFullState,
        HashMap::from([(2, scalar_reg(16))]),
    )]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_post_state_guard_rejects_packet_pointer_copy_materialization() {
    // Bug caught: local numeric state must not turn a provenance-carrying packet
    // pointer copy into a scalar immediate before a later packet memory access.
    let original = vec![
        BpfInsn::mov64_imm(1, 62),
        BpfInsn::mov64_reg(7, 1),
        BpfInsn::ldx_mem(BPF_B, 2, 7, 0),
        BpfInsn::exit(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![verifier_delta_state(
        1,
        HashMap::from([(7, pkt_reg())]),
    )]);

    let result = run_const_prop_pass(&mut program);
    let pass = &result.pass_results[0];
    assert_eq!(pass.sites_applied, 0);
    assert_eq!(pass.sites_skipped.len(), 1);
    assert_eq!(pass.sites_skipped[0].pc, 1);
    assert_eq!(
        pass.sites_skipped[0].reason,
        VERIFIER_POST_STATE_NOT_SCALAR_EXACT
    );
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_post_state_guard_allows_scalar_exact_register_copy() {
    // Bug caught: the verifier guard should preserve useful scalar MOV X
    // materialization when the post-state proves the destination is scalar exact.
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(1, 62),
        BpfInsn::mov64_reg(7, 1),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![verifier_delta_state(
        1,
        HashMap::from([(7, scalar_reg(62))]),
    )]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(1, 62),
            BpfInsn::mov64_imm(7, 62),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn const_prop_rejects_edge_state_only_pointer_arithmetic_materialization() {
    // Bug caught: edge/full states describe control-flow entry state, not the
    // instruction post-state. They must not prove an ALU replacement that
    // would turn packet pointer arithmetic into a scalar immediate.
    let original = vec![
        BpfInsn::mov64_imm(7, 0),
        BpfInsn::mov64_reg(3, 7),
        add64_imm(3, 34),
        BpfInsn::ldx_mem(BPF_H, 2, 3, 2),
        BpfInsn::exit(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(3, pkt_reg())])),
        verifier_state_in_frame(
            2,
            0,
            VerifierInsnKind::EdgeFullState,
            HashMap::from([(3, scalar_reg(34))]),
        ),
    ]);

    let result = run_const_prop_pass(&mut program);
    let pass = &result.pass_results[0];
    assert_eq!(pass.sites_applied, 0);
    assert!(pass
        .sites_skipped
        .iter()
        .any(|skip| { skip.pc == 2 && skip.reason == VERIFIER_POST_STATE_NOT_SCALAR_EXACT }));
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_rejects_replacement_when_observation_missing_at_some_visit() {
    // Bug caught: a verifier delta from one diamond arm must not prove the join-pc
    // constant when another visit to the same pc omitted that register.
    let original = vec![
        BpfInsn::helper_call(7),
        BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(0, 0), 1, 0),
        BpfInsn::nop(),
        add64_imm(3, 1),
        BpfInsn::exit(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![
        verifier_delta_state(3, HashMap::from([(3, scalar_reg(99))])),
        verifier_delta_state(3, HashMap::new()),
    ]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_rejects_replacement_when_full_state_visit_omits_reg() {
    // Bug caught: full verifier snapshots are visits too; ignoring a full-state
    // omission would let one delta-state exact value masquerade as global proof.
    let original = vec![BpfInsn::helper_call(7), add64_imm(3, 1), BpfInsn::exit()];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
        verifier_state_in_frame(1, 0, VerifierInsnKind::PcFullState, HashMap::new()),
    ]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_rejects_replacement_across_disagreeing_frames() {
    // Bug caught: context-insensitive simulation must not apply a verifier fact
    // from one call frame when the same pc has a different exact value elsewhere.
    let original = vec![BpfInsn::helper_call(7), add64_imm(3, 1), BpfInsn::exit()];
    let mut program = BpfProgram::new(original.clone());
    program.set_verifier_states(vec![
        verifier_delta_state_in_frame(1, 0, HashMap::from([(3, scalar_reg(42))])),
        verifier_delta_state_in_frame(1, 1, HashMap::from([(3, scalar_reg(43))])),
    ]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert_eq!(program.insns, original);
}

#[test]
fn const_prop_accepts_when_every_visit_agrees() {
    // Bug caught: the fail-closed oracle should still allow useful folding when
    // every verifier visit to a pc/frame observes the same exact register value.
    let mut program = BpfProgram::new(vec![
        BpfInsn::helper_call(7),
        add64_imm(3, 1),
        BpfInsn::exit(),
    ]);
    program.set_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
        verifier_delta_state(1, HashMap::from([(3, scalar_reg(42))])),
    ]);

    let result = run_const_prop_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::helper_call(7),
            BpfInsn::mov64_imm(3, 42),
            BpfInsn::exit()
        ]
    );
}

#[test]
fn eval_binary_alu_rejects_zero_divisor_without_panicking() {
    assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, false), None);
    assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, false), None);
    assert_eq!(eval_binary_alu(BPF_DIV, 9, 0, true), None);
    assert_eq!(eval_binary_alu(BPF_MOD, 9, 0, true), None);
}
