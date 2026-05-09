use super::*;
use std::collections::{BTreeSet, HashMap};

use crate::bpf::{install_mock_map, use_mock_maps, BpfMapInfo, MockMapState};
use crate::insn::*;
use crate::pass::{
    BpfProgram, PassContext, PipelineResult, RegState, ScalarRange, StackState, Tnum, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};
use crate::passes::test_helpers::{call_helper, exit_insn};

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

fn install_map(map_id: u32, map_type: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value.clone());

    let info = BpfMapInfo {
        map_type,
        key_size: 4,
        value_size: value.len() as u32,
        max_entries: 8,
    };

    install_mock_map(map_id, MockMapState { info, values });
}

fn install_array_map(map_id: u32, value: Vec<u8>) {
    install_map(map_id, BPF_MAP_TYPE_ARRAY, value);
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

fn scalar_reg(value: u64) -> RegState {
    RegState {
        reg_type: "scalar".to_string(),
        value_width: VerifierValueWidth::Bits64,
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

fn install_single_lookup_verifier_states(program: &mut BpfProgram) {
    program.set_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
}

fn install_const_prop_scalar_verifier_state(
    program: &mut BpfProgram,
    pc: usize,
    reg: u8,
    value: u64,
) {
    program.set_verifier_states(vec![verifier_delta_state(
        pc,
        HashMap::from([(reg, scalar_reg(value))]),
    )]);
}

fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_delta_state_with_stack(pc, regs, HashMap::new())
}

fn verifier_delta_state_with_stack(
    pc: usize,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame: 0,
        from_pc: None,
        kind: VerifierInsnKind::InsnDeltaState,
        speculative: false,
        regs,
        stack,
    }
}

fn stack_snapshot_from_key(stack_off: i16, key: &[u8]) -> HashMap<i16, StackState> {
    let mut slots = HashMap::<i16, ([u8; 8], [u8; 8])>::new();
    for (idx, byte) in key.iter().enumerate() {
        let absolute_off = i32::from(stack_off) + idx as i32;
        let slot_index = ((-absolute_off - 1) / 8) + 1;
        let slot_start_i32 = -slot_index * 8;
        let slot_start = i16::try_from(slot_start_i32).unwrap();
        let byte_index = usize::try_from(absolute_off - slot_start_i32).unwrap();
        let type_index = 7 - byte_index;
        let entry = slots.entry(slot_start).or_insert(([0u8; 8], [b'?'; 8]));
        entry.0[byte_index] = *byte;
        entry.1[type_index] = b'r';
    }

    slots
        .into_iter()
        .map(|(off, (bytes, types))| {
            let value = u64::from_le_bytes(bytes);
            (
                off,
                StackState {
                    slot_types: Some(String::from_utf8(types.to_vec()).unwrap()),
                    value: Some(RegState {
                        reg_type: "scalar".to_string(),
                        value_width: VerifierValueWidth::Bits64,
                        precise: true,
                        exact_value: Some(value),
                        tnum: None,
                        range: ScalarRange::default(),
                        offset: None,
                        id: None,
                    }),
                },
            )
        })
        .collect()
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

#[test]
#[rustfmt::skip] fn pass_registry_declares_all_emitted_kinsn_probe_names() {
    let declared = PASS_REGISTRY.iter().flat_map(|entry| entry.metadata.kinsns_used).flat_map(|kinsn| kinsn.probe_aliases.iter().copied()).collect::<BTreeSet<_>>();
    assert_eq!(declared, BTreeSet::from(["bpf_rotate64", "bpf_rotate32", "bpf_select64", "bpf_ccmp64", "bpf_extract64", "bpf_endian_load16", "bpf_endian_load32", "bpf_endian_load64", "bpf_memcpy_bulk", "bpf_memset_bulk", "bpf_prefetch"]));
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

    let map_inline_result = run_pipeline_with_passes(&mut program, &["map_inline"]);
    install_const_prop_scalar_verifier_state(&mut program, 2, 1, 52);
    let const_prop_result = run_pipeline_with_passes(&mut program, &["const_prop"]);
    assert_eq!(map_inline_result.pass_results[0].pass_name, "map_inline");
    assert_eq!(const_prop_result.pass_results[0].pass_name, "const_prop");
    assert_eq!(const_prop_result.pass_results[0].sites_applied, 1);
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
fn cascade_full_pipeline_materializes_alu_and_leaves_branch_cleanup_to_kernel() {
    for (label, map_id, map_type, mut program, expected) in {
        let array_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let hash_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        [
            (
                "array full pipeline",
                304,
                BPF_MAP_TYPE_ARRAY,
                make_program(vec![
                    array_map[0],
                    array_map[1],
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
                ]),
                vec![
                    BpfInsn::mov32_imm(6, 42),
                    jeq_imm(6, 0, 2),
                    BpfInsn::mov64_imm(0, 1),
                    exit_insn(),
                    BpfInsn::mov64_imm(0, 0),
                    exit_insn(),
                ],
            ),
            (
                "hash null path",
                305,
                BPF_MAP_TYPE_HASH,
                make_program(vec![
                    hash_map[0],
                    hash_map[1],
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
                ]),
                vec![BpfInsn::mov64_imm(0, 1), exit_insn()],
            ),
        ]
    } {
        install_map(map_id, map_type, 42u32.to_le_bytes().to_vec());
        program.set_map_ids(vec![map_id]);
        install_single_lookup_verifier_states(&mut program);
        let original_len = program.insns.len();

        let result = run_pipeline_with_passes(&mut program, &["map_inline"]);
        let const_prop_pc = if map_type == BPF_MAP_TYPE_HASH { 2 } else { 3 };
        install_const_prop_scalar_verifier_state(&mut program, const_prop_pc, 1, 52);
        let const_prop_result = run_pipeline_with_passes(&mut program, &["const_prop", "dce"]);
        let mut pass_results = result.pass_results;
        pass_results.extend(const_prop_result.pass_results);
        let pipeline_result = PipelineResult { pass_results };

        assert!(program.insns.len() < original_len, "{label}");
        assert_eq!(
            pipeline_result
                .pass_results
                .iter()
                .find(|pr| pr.pass_name == "map_inline")
                .map(|pr| pr.sites_applied),
            Some(1),
            "{label}"
        );
        assert_eq!(
            pipeline_result
                .pass_results
                .iter()
                .find(|pr| pr.pass_name == "const_prop")
                .map(|pr| pr.sites_applied),
            Some(1),
            "{label}"
        );
        assert!(pipeline_result
            .pass_results
            .iter()
            .find(|pr| pr.pass_name == "dce")
            .map(|pr| pr.sites_applied > 0)
            .unwrap_or(false));
        assert_eq!(program.insns, expected, "{label}");
    }
}
