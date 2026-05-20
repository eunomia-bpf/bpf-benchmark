// SPDX-License-Identifier: MIT

use std::collections::HashMap;

use crate::analysis::{lift_with_pass_context, lower, ProgramCFG};
use crate::insn::BpfInsn;
use crate::pass::{
    BpfPass, PassContext, PassResult, RegState, ScalarRange, StackState, Tnum, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};
use crate::passes::map_inline::MapInfo;

pub struct PassRun {
    pub result: PassResult,
    pub lowered: Vec<BpfInsn>,
    pub prog: ProgramCFG,
    /// Snapshot of the lifted program before the pass mutated it. Tests use
    /// this to resolve `site_skipped` entries to pre-mutation report PCs.
    pub report_prog: ProgramCFG,
}

pub fn lift_test_program(insns: &[BpfInsn], ctx: &PassContext) -> ProgramCFG {
    lift_with_pass_context(insns, ctx)
        .expect("test bytecode and side inputs should lift into ProgramCFG")
}

pub fn lower_test_program(prog: &ProgramCFG) -> Vec<BpfInsn> {
    lower(prog).expect("test ProgramCFG should lower")
}

pub fn run_pass_on_insns<P: BpfPass>(pass: P, insns: Vec<BpfInsn>, ctx: &PassContext) -> PassRun {
    let mut prog = lift_test_program(&insns, ctx);
    let report_prog = prog.clone();
    // Test helpers run passes through the production ProgramCFG API.
    let result = pass
        .run(&mut prog, ctx)
        .expect("future ProgramCFG-native pass should run");
    let lowered = lower_test_program(&prog);
    PassRun {
        result,
        lowered,
        prog,
        report_prog,
    }
}

pub fn pass_error_on_insns<P: BpfPass>(pass: P, insns: Vec<BpfInsn>, ctx: &PassContext) -> String {
    let mut prog = lift_test_program(&insns, ctx);
    // Test helpers run passes through the production ProgramCFG API.
    pass.run(&mut prog, ctx)
        .expect_err("future ProgramCFG-native pass should reject this fixture")
        .to_string()
}

pub fn pass_ctx() -> PassContext {
    PassContext::default()
}

pub fn ctx_with_kinsn(target: &str, btf_id: i32) -> PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name(target, btf_id, 0)
        .expect("test kinsn target should register");
    ctx
}

pub fn ctx_with_verifier_states(states: Vec<VerifierInsn>) -> PassContext {
    let mut ctx = pass_ctx();
    // Raw verifier states stay on PassContext and are consumed once at lift.
    ctx.set_verifier_states_test(states);
    ctx
}

pub fn set_map_ids(ctx: &mut PassContext, map_ids: Vec<u32>) {
    // Canonical map-id binding side input lives on PassContext.
    ctx.map_ids = map_ids;
}

pub fn scalar_reg(value: u64) -> RegState {
    scalar_reg_with_width(value, VerifierValueWidth::Bits64)
}

pub fn scalar32_reg(value: u64) -> RegState {
    scalar_reg_with_width(value, VerifierValueWidth::Bits32)
}

pub fn scalar_reg_with_width(value: u64, value_width: VerifierValueWidth) -> RegState {
    let mut reg = RegState::new("scalar", value_width);
    reg.precise = true;
    reg.exact_value = Some(value);
    reg.tnum = Some(Tnum { value, mask: 0 });
    reg.range = ScalarRange {
        smin: Some(value as i64),
        smax: Some(value as i64),
        umin: Some(value),
        umax: Some(value),
        smin32: Some(value as u32 as i32),
        smax32: Some(value as u32 as i32),
        umin32: Some(value as u32),
        umax32: Some(value as u32),
    };
    reg
}

pub fn fp_reg(offset: i32) -> RegState {
    let mut reg = RegState::new("fp", VerifierValueWidth::Bits64);
    reg.offset = Some(offset);
    reg
}

pub fn pkt_reg() -> RegState {
    RegState::new("pkt", VerifierValueWidth::Bits64)
}

pub fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_delta_state_with_stack(pc, regs, HashMap::new())
}

pub fn verifier_delta_state_with_stack(
    pc: usize,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::InsnDeltaState, regs, stack)
}

pub fn verifier_delta_state_in_frame(
    pc: usize,
    frame: usize,
    regs: HashMap<u8, RegState>,
) -> VerifierInsn {
    verifier_state(
        pc,
        frame,
        VerifierInsnKind::InsnDeltaState,
        regs,
        HashMap::new(),
    )
}

pub fn verifier_full_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::PcFullState, regs, HashMap::new())
}

pub fn verifier_edge_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::EdgeFullState, regs, HashMap::new())
}

pub fn verifier_state(
    pc: usize,
    frame: usize,
    kind: VerifierInsnKind,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame,
        from_pc: None,
        kind,
        speculative: false,
        regs,
        stack,
    }
}

pub fn stack_snapshot_from_key(stack_off: i16, key: &[u8]) -> HashMap<i16, StackState> {
    let mut slots = HashMap::<i16, ([u8; 8], [u8; 8])>::new();
    for (idx, byte) in key.iter().enumerate() {
        let absolute_off = i32::from(stack_off) + idx as i32;
        let slot_index = ((-absolute_off - 1) / 8) + 1;
        let slot_start_i32 = -slot_index * 8;
        let slot_start = i16::try_from(slot_start_i32).expect("stack slot start fits i16");
        let byte_index =
            usize::try_from(absolute_off - slot_start_i32).expect("byte index fits usize");
        let type_index = 7 - byte_index;
        let entry = slots.entry(slot_start).or_insert(([0u8; 8], [b'?'; 8]));
        entry.0[byte_index] = *byte;
        entry.1[type_index] = b'r';
    }

    slots
        .into_iter()
        .map(|(off, (bytes, types))| {
            (
                off,
                StackState {
                    slot_types: Some(String::from_utf8(types.to_vec()).expect("slot types utf8")),
                    value: Some(scalar_reg(u64::from_le_bytes(bytes))),
                },
            )
        })
        .collect()
}

pub fn map_info(map_id: u32, map_type: u32, key_size: u32, value_size: u32) -> MapInfo {
    MapInfo {
        map_type,
        key_size,
        value_size,
        max_entries: 8,
        map_id,
        name: format!("map_{map_id}"),
    }
}

pub fn branch_profile(taken: u64, not_taken: u64, miss_rate: f64) -> crate::pass::BranchProfile {
    crate::pass::BranchProfile {
        branch_count: taken + not_taken,
        branch_misses: ((taken + not_taken) as f64 * miss_rate) as u64,
        miss_rate,
        taken_count: taken,
        not_taken_count: not_taken,
    }
}

pub fn assert_skip_reason(run: &PassRun, pc: usize, reason: &str) {
    let matched = run.result.site_skipped.iter().any(|skip| {
        run.report_prog.rep_site_slot(skip.site).ok() == Some(pc) && skip.reason.contains(reason)
    });
    assert!(
        matched,
        "missing skip pc={pc} reason containing {reason:?}; got {:?}",
        run.result.site_skipped
    );
}

pub fn assert_diagnostic(result: &PassResult, needle: &str) {
    assert!(
        result.diagnostics.iter().any(|diag| diag.contains(needle)),
        "missing diagnostic containing {needle:?}; got {:?}",
        result.diagnostics
    );
}
