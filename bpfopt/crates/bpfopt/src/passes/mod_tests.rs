use super::*;
use std::collections::HashMap;

use crate::bpf::{install_mock_map, use_mock_maps, BpfMapInfo, MockMapState};
use crate::insn::*;
use crate::pass::{
    BpfProgram, PassContext, PassManager, PipelineResult, RegState, ScalarRange, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};

const BPF_MAP_TYPE_HASH: u32 = kernel_sys::BPF_MAP_TYPE_HASH;
const BPF_MAP_TYPE_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_ARRAY;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn ld_imm64(dst: u8, src: u8, imm_lo: i32) -> [BpfInsn; 2] {
    [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst, src),
            0,
            imm_lo,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ]
}

fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ST | size | BPF_MEM,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn call_helper(imm: i32) -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, imm)
}

fn install_map(map_id: u32, map_type: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value.clone());

    let info = BpfMapInfo {
        map_type,
        key_size: 4,
        value_size: value.len() as u32,
        max_entries: 8,
    };

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen: true,
            values,
        },
    );
}

fn install_array_map(map_id: u32, value: Vec<u8>) {
    install_map(map_id, BPF_MAP_TYPE_ARRAY, value);
}

fn install_hash_map(map_id: u32, value: Vec<u8>) {
    install_map(map_id, BPF_MAP_TYPE_HASH, value);
}

fn fp_reg(offset: i32) -> RegState {
    RegState {
        reg_type: "fp".to_string(),
        value_width: VerifierValueWidth::Bits64,
        precise: false,
        exact_value: None,
        tnum: None,
        range: ScalarRange::default(),
        offset: Some(offset),
        id: None,
    }
}

fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame: 0,
        from_pc: None,
        kind: VerifierInsnKind::InsnDeltaState,
        speculative: false,
        regs,
        stack: HashMap::new(),
    }
}

fn install_single_lookup_verifier_states(program: &mut BpfProgram) {
    program.set_verifier_states(vec![
        verifier_delta_state(2, HashMap::new()),
        verifier_delta_state(4, HashMap::from([(2, fp_reg(-4))])),
        verifier_delta_state(5, HashMap::new()),
    ]);
}

fn run_pipeline_with_passes(program: &mut BpfProgram, pass_names: &[&str]) -> PipelineResult {
    use_mock_maps(program);
    let pass_names = pass_names
        .iter()
        .map(|name| (*name).to_string())
        .collect::<Vec<_>>();
    let pm = build_custom_pipeline(&pass_names).unwrap();
    let mut ctx = PassContext::test_default();
    ctx.policy.enabled_passes = pass_names;
    pm.run(program, &ctx).unwrap()
}

fn default_test_pipeline() -> PassManager {
    let pass_names = PASS_REGISTRY
        .iter()
        .filter(|entry| entry.name != "branch_flip" && entry.name != "prefetch")
        .map(|entry| entry.name.to_string())
        .collect::<Vec<_>>();
    build_custom_pipeline(&pass_names).unwrap()
}

fn make_wide_mem_4byte_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 1),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 2),
        BpfInsn::alu64_imm(BPF_LSH, 3, 16),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 3),
        BpfInsn::alu64_imm(BPF_LSH, 3, 24),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]
}

#[test]
fn test_cfg_analysis_with_subprogs() {
    use crate::analysis::CFGAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 1), 0, 2),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);

    let cfg = CFGAnalysis;
    let result = cfg.run(&prog);

    assert!(result.subprogs.len() >= 2);
    assert_eq!(result.subprogs[1].start, 3);
}

#[test]
fn test_cfg_analysis_with_callback_subprog_refs() {
    use crate::analysis::CFGAnalysis;
    use crate::pass::Analysis;

    let callback = ld_imm64(2, BPF_PSEUDO_FUNC, 4);
    let prog = make_program(vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_reg(0, 1),
        exit_insn(),
    ]);

    let cfg = CFGAnalysis;
    let result = cfg.run(&prog);

    assert!(result.subprogs.len() >= 2);
    assert_eq!(result.subprogs[1].start, 5);
}

#[test]
fn test_liveness_across_branch() {
    use crate::analysis::LivenessAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![
        BpfInsn::mov64_imm(1, 10),
        jeq_imm(1, 0, 1),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::mov64_imm(0, 2),
        exit_insn(),
    ]);

    let liveness = LivenessAnalysis;
    let result = liveness.run(&prog);

    assert!(result.live_out[0].contains(&1));
    assert!(!result.live_out[1].contains(&0));
    assert!(result.live_out[3].contains(&0));
}

#[test]
fn test_branch_targets_backward_jump() {
    use crate::analysis::BranchTargetAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![BpfInsn::mov64_imm(0, 0), BpfInsn::ja(-2)]);

    let bt = BranchTargetAnalysis;
    let result = bt.run(&prog);

    assert!(result.is_target[0]);
    assert!(!result.is_target[1]);
}

#[test]
fn test_default_pipeline_wide_mem() {
    let mut prog = make_program(make_wide_mem_4byte_program());
    let ctx = PassContext::test_default();

    let pm = default_test_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();
    assert!(result.program_changed);
    assert!(result.total_sites_applied >= 1);
}

#[test]
fn test_map_inline_only_pipeline_contains_only_map_inline() {
    let pm =
        build_custom_pipeline(&["map_inline".to_string()]).expect("custom pipeline should build");

    assert_eq!(pm.pass_names(), vec!["map_inline"]);
}

#[test]
fn test_build_custom_pipeline_respects_registry_order() {
    let pm = build_custom_pipeline(&[
        "wide_mem".to_string(),
        "const_prop".to_string(),
        "map_inline".to_string(),
    ])
    .expect("custom pipeline should build");

    assert_eq!(
        pm.pass_names(),
        vec!["map_inline", "const_prop", "wide_mem"]
    );
}

#[test]
fn test_build_custom_pipeline_rejects_unknown_pass_name() {
    let err = match build_custom_pipeline(&["wide_mem".to_string(), "nope".to_string()]) {
        Ok(_) => panic!("unknown pass should be rejected"),
        Err(err) => err,
    };

    assert!(err.to_string().contains("unknown pass name(s): nope"));
}

#[test]
fn cascade_map_inline_emits_non_zero_mov_constant() {
    install_array_map(301, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 0, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![301]);
    install_single_lookup_verifier_states(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline"]);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, vec![BpfInsn::mov32_imm(0, 42), exit_insn()]);
}

#[test]
fn cascade_const_prop_folds_non_zero_map_inline_output() {
    install_array_map(302, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 0, 0, 0),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![302]);
    install_single_lookup_verifier_states(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(0, 42),
            BpfInsn::mov64_imm(1, 10),
            BpfInsn::mov64_imm(1, 52),
            exit_insn(),
        ]
    );
}

#[test]
fn cascade_dce_eliminates_dead_branch_after_const_prop() {
    install_array_map(303, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        jeq_imm(6, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![303]);
    install_single_lookup_verifier_states(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert!(result.pass_results[2].changed);
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}

#[test]
fn cascade_full_pipeline_shortens_program_and_preserves_folded_semantics() {
    install_array_map(304, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        jeq_imm(6, 0, 4),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 6),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![304]);
    install_single_lookup_verifier_states(&mut program);
    let original_len = program.insns.len();

    let pm = default_test_pipeline();
    use_mock_maps(&mut program);
    let result = pm.run(&mut program, &PassContext::test_default()).unwrap();

    assert!(result.program_changed);
    assert!(program.insns.len() < original_len);
    assert_eq!(
        result
            .pass_results
            .iter()
            .find(|pr| pr.pass_name == "map_inline")
            .map(|pr| pr.sites_applied),
        Some(1)
    );
    assert_eq!(
        result
            .pass_results
            .iter()
            .find(|pr| pr.pass_name == "const_prop")
            .map(|pr| pr.sites_applied),
        Some(2)
    );
    assert!(result
        .pass_results
        .iter()
        .find(|pr| pr.pass_name == "dce")
        .map(|pr| pr.changed)
        .unwrap_or(false));
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}

#[test]
fn cascade_hash_map_removes_lookup_and_null_path_then_folds_non_null_path() {
    install_hash_map(305, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 5),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 6),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![305]);
    install_single_lookup_verifier_states(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert!(result.pass_results[2].changed);
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}
