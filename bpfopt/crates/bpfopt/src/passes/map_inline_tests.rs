use super::*;
use std::collections::HashMap;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis};
use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
use crate::mock_maps::use_mock_maps;
use crate::pass::{
    MapInlineRecord, PassContext, PassManager, RegState, ScalarRange, Tnum, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};
use crate::passes::test_helpers::{call_helper, exit_insn};
use crate::passes::MapInfoAnalysis;
use crate::passes::{ConstPropPass, DcePass};

fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
    [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst, src),
            0,
            imm,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ]
}

fn ld_imm64_parts(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
    [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst, src),
            0,
            imm_lo,
        ),
        BpfInsn::new(0, 0, 0, imm_hi),
    ]
}

fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ST | size | BPF_MEM,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU64 | BPF_ADD | BPF_K,
        BpfInsn::make_regs(dst, 0),
        0,
        imm,
    )
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

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JNE | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn ja(off: i16) -> BpfInsn {
    BpfInsn::ja(off)
}

fn install_map(
    map_id: u32,
    map_type: u32,
    max_entries: u32,
    frozen: bool,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    install_map_with_key_size(map_id, map_type, 4, max_entries, frozen, values);
}

fn install_map_with_key_size(
    map_id: u32,
    map_type: u32,
    key_size: u32,
    max_entries: u32,
    frozen: bool,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    let info = BpfMapInfo {
        map_type,
        key_size,
        value_size: values.values().next().map(|value| value.len()).unwrap_or(0) as u32,
        max_entries,
    };

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values,
        },
    );
}

fn install_empty_map(map_id: u32, map_type: u32, value_size: u32, max_entries: u32, frozen: bool) {
    let info = BpfMapInfo {
        map_type,
        key_size: 4,
        value_size,
        max_entries,
    };

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values: HashMap::new(),
        },
    );
}

fn install_percpu_array_map(
    map_id: u32,
    value_size: u32,
    max_entries: u32,
    frozen: bool,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    let info = BpfMapInfo {
        map_type: BPF_MAP_TYPE_PERCPU_ARRAY,
        key_size: 4,
        value_size,
        max_entries,
    };

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values,
        },
    );
}

fn make_percpu_blob(slot_value: &[u8], slots: usize) -> Vec<u8> {
    let stride = round_up_8(slot_value.len());
    let mut blob = vec![0u8; stride * slots];
    for slot in 0..slots {
        let offset = slot * stride;
        blob[offset..offset + slot_value.len()].copy_from_slice(slot_value);
    }
    blob
}

fn install_array_map(map_id: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value);
    install_map(map_id, 2, 8, true, values);
}

fn install_array_map_entry(map_id: u32, max_entries: u32, key: u32, value: Vec<u8>, frozen: bool) {
    let mut values = HashMap::new();
    values.insert(key.to_le_bytes().to_vec(), value.clone());

    let info = BpfMapInfo {
        map_type: 2,
        key_size: 4,
        value_size: value.len() as u32,
        max_entries,
    };

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values,
        },
    );
}

fn install_hash_map(map_id: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value);
    install_map(map_id, 1, 8, true, values);
}

fn install_mutable_array_map(map_id: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value);
    install_map(map_id, 2, 8, false, values);
}

fn run_map_inline_pass(program: &mut BpfProgram) -> PipelineResult {
    try_run_map_inline_pass(program).unwrap()
}

fn try_run_map_inline_pass(program: &mut BpfProgram) -> anyhow::Result<PipelineResult> {
    use_mock_maps(program);
    install_synthetic_verifier_states_for_map_inline_tests(program);
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(MapInfoAnalysis);
    pm.add_pass(MapInlinePass);
    pm.run(program, &PassContext::test_default())
}

fn run_map_inline_const_prop_dce(program: &mut BpfProgram) -> PipelineResult {
    use_mock_maps(program);
    install_synthetic_verifier_states_for_map_inline_tests(program);
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(MapInfoAnalysis);
    pm.add_pass(MapInlinePass);
    pm.add_pass(ConstPropPass);
    pm.add_pass(DcePass);
    pm.run(program, &PassContext::test_default()).unwrap()
}

fn install_synthetic_verifier_states_for_map_inline_tests(program: &mut BpfProgram) {
    if !program.verifier_states.is_empty() {
        return;
    }

    let mut states = Vec::new();
    for site in find_map_lookup_sites(&program.insns) {
        let Some(map_load) = program.insns.get(site.map_load_pc) else {
            continue;
        };
        let Some(map_id) = program.map_fd_bindings.get(&map_load.imm).copied() else {
            continue;
        };
        let Some(info) = program.map_provider.map_info(program, map_id).unwrap() else {
            continue;
        };
        let bounds = subprog_bounds(&program.insns, site.call_pc);
        let Ok(stack_off) = resolve_stack_pointer_to_stack(&program.insns, site.call_pc, 2, bounds)
        else {
            continue;
        };
        if let Some((mov_pc, add_pc, _)) =
            find_r2_stack_pointer_setup_simple(&program.insns, site.call_pc, bounds)
        {
            if let Ok(key_width) = u8::try_from(info.key_size) {
                if let Ok(stack_bytes) = find_constant_stack_bytes(
                    &program.insns,
                    site.call_pc,
                    bounds,
                    stack_off,
                    key_width,
                ) {
                    let store = program.insns[stack_bytes.latest_store_pc];
                    let mut regs = HashMap::new();
                    if bpf_class(store.code) == BPF_STX {
                        if let Ok(value) = resolve_constant_reg_value(
                            &program.insns,
                            stack_bytes.latest_store_pc,
                            store.src_reg(),
                            bounds,
                        ) {
                            regs.insert(store.src_reg(), scalar_reg(value.value));
                        }
                    }
                    states.push(verifier_delta_state(stack_bytes.latest_store_pc, regs));
                }
            }
            let setup_pc = add_pc.max(mov_pc);
            states.push(verifier_delta_state(
                setup_pc,
                HashMap::from([(2, fp_reg(i32::from(stack_off)))]),
            ));
            states.push(verifier_delta_state(site.call_pc, HashMap::new()));
        }
    }

    program.set_verifier_states(states);
}

fn has_non_constant_key_skip(result: &PipelineResult) -> bool {
    result.pass_results[0].sites_skipped.iter().any(|skip| {
        skip.reason
            .contains("lookup key is not available from verifier-guided state")
    })
}

#[test]
fn find_map_lookup_sites_matches_helper_one_with_map_arg() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 7),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let sites = find_map_lookup_sites(&insns);
    assert_eq!(
        sites,
        vec![MapLookupSite {
            call_pc: 5,
            map_load_pc: 0,
        }]
    );
}

#[test]
fn find_map_lookup_sites_ignores_calls_without_map_load() {
    let insns = vec![
        BpfInsn::mov64_imm(1, 0),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    assert!(find_map_lookup_sites(&insns).is_empty());
}

#[test]
fn map_inline_constantizes_frozen_pseudo_map_value_loads() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), vec![0, 0, 0, 0, 42, 0, 0, 0]);
    install_map(901, 2, 1, true, values);

    let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 77, 4);
    let mut program = BpfProgram::new(vec![
        map_value[0],
        map_value[1],
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![901]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(program.insns[2], BpfInsn::mov32_imm(2, 42));
}

#[test]
fn map_inline_constantizes_frozen_pseudo_map_idx_value_loads() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), vec![0, 0, 0, 0, 99, 0, 0, 0]);
    install_map(1901, 2, 1, true, values);

    let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_IDX_VALUE, 0, 4);
    let mut program = BpfProgram::new(vec![
        map_value[0],
        map_value[1],
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![1901]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(program.insns[2], BpfInsn::mov32_imm(2, 99));
}

#[test]
fn map_inline_skips_mutable_pseudo_map_value_loads() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
    install_map(902, 2, 1, false, values);

    let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 78, 0);
    let original = vec![
        map_value[0],
        map_value[1],
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![902]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
}

#[test]
fn map_inline_pseudo_map_value_feeds_const_prop_and_dce() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), vec![1, 0, 0, 0]);
    install_map(903, 2, 1, true, values);

    let map_value = ld_imm64_parts(1, BPF_PSEUDO_MAP_VALUE, 79, 0);
    let mut program = BpfProgram::new(vec![
        map_value[0],
        map_value[1],
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        jeq_imm(2, 1, 1),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![903]);

    let result = run_map_inline_const_prop_dce(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert!(result.pass_results[0].changed);
    assert!(result.pass_results[1].changed);
    assert!(
        !program.insns.iter().any(|insn| insn.is_cond_jmp()),
        "expected const_prop+dce to remove the conditional branch after pseudo-map-value constantization"
    );
    assert!(
        !program
            .insns
            .iter()
            .any(|insn| *insn == BpfInsn::mov64_imm(0, 0)),
        "expected dce to remove the dead false branch after pseudo-map-value constantization"
    );
}

#[test]
fn extract_constant_key_from_direct_stack_store() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 7),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = extract_constant_key(&insns, 5).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.width, 4);
    assert_eq!(key.value, 7);
    assert_eq!(key.store_pc, 2);
    assert_eq!(key.source_imm_pc, None);
}

#[test]
fn extract_constant_key_from_stx_stack_store() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        map[0],
        map[1],
        BpfInsn::mov64_imm(3, 9),
        BpfInsn::stx_mem(BPF_W, 10, 3, -4),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = extract_constant_key(&insns, 6).unwrap();
    assert_eq!(key.value, 9);
    assert_eq!(key.store_pc, 3);
    assert_eq!(key.source_imm_pc, Some(2));
}

#[test]
fn extract_constant_key_from_r2_copy_chain() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        st_mem(BPF_W, 10, -4, 7),
        BpfInsn::mov64_reg(6, 10),
        add64_imm(6, -4),
        BpfInsn::mov64_reg(2, 6),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = extract_constant_key(&insns, 6).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.value, 7);
    assert_eq!(key.r2_mov_pc, None);
    assert_eq!(key.r2_add_pc, None);
}

#[test]
fn verifier_guided_key_extracts_wide_zero_store_subrange() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        BpfInsn::mov64_imm(3, 0),
        BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];
    let plain = try_extract_constant_key(&insns, 6).unwrap();
    assert_eq!(plain.stack_off, -4);
    assert_eq!(plain.width, 4);
    assert_eq!(plain.value, 0);
    assert_eq!(plain.store_pc, 1);

    let states = vec![
        verifier_delta_state(1, HashMap::from([(3, scalar_reg(0))])),
        verifier_delta_state(3, HashMap::from([(2, fp_reg(-4))])),
        verifier_delta_state(6, HashMap::new()),
    ];

    let key = try_extract_constant_key_verifier_guided(&insns, &states, 6, 4).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.width, 4);
    assert_eq!(key.value, 0);
    assert_eq!(key.store_pc, 1);
}

#[test]
fn extract_constant_key_from_fp_alias_store_base() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        BpfInsn::mov64_reg(6, 10),
        add64_imm(6, -8),
        st_mem(BPF_W, 6, 4, 7),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = extract_constant_key(&insns, 7).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.value, 7);
}

#[test]
fn verifier_guided_key_extracts_store_via_fp_alias_base() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        BpfInsn::mov64_reg(6, 10),
        add64_imm(6, -8),
        st_mem(BPF_W, 6, 4, 7),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let states = vec![
        verifier_delta_state(2, HashMap::new()),
        verifier_delta_state(4, HashMap::from([(2, fp_reg(-4))])),
        verifier_delta_state(7, HashMap::new()),
    ];

    let key = try_extract_constant_key_verifier_guided(&insns, &states, 7, 4).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.value, 7);
    assert_eq!(key.store_pc, 2);
}

#[test]
fn extract_constant_key_from_ldimm64_stack_store() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let key_imm = emit_ldimm64(3, 0x1_0000_0001);
    let insns = vec![
        key_imm[0],
        key_imm[1],
        BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = try_extract_constant_key_sized(&insns, 7, 8).unwrap();
    assert_eq!(key.stack_off, -8);
    assert_eq!(key.width, 8);
    assert_eq!(key.value, 0x1_0000_0001);
    assert_eq!(key.source_imm_pc, Some(0));
}

#[test]
fn classify_r0_uses_collects_fixed_loads_until_redefinition() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
        BpfInsn::ldx_mem(BPF_B, 4, 0, 7),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::ldx_mem(BPF_W, 5, 0, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(
        uses.fixed_loads,
        vec![
            FixedLoadUse {
                pc: 1,
                dst_reg: 3,
                size: BPF_W,
                offset: 0,
            },
            FixedLoadUse {
                pc: 2,
                dst_reg: 4,
                size: BPF_B,
                offset: 7,
            },
        ]
    );
    assert!(uses.other_uses.is_empty());
}

#[test]
fn classify_r0_uses_tracks_alias_copies_and_guarded_loads() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        jeq_imm(6, 0, 1),
        BpfInsn::ldx_mem(BPF_W, 3, 6, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(uses.fixed_loads.len(), 1);
    assert!(uses.other_uses.is_empty());
    assert_eq!(uses.alias_copy_pcs, vec![1]);
    assert_eq!(uses.null_check_pc, Some(2));
    assert!(uses.all_fixed_loads());
}

#[test]
fn classify_r0_uses_tracks_alias_offset_loads() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        add64_imm(6, 4),
        BpfInsn::ldx_mem(BPF_W, 3, 6, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(uses.alias_copy_pcs, vec![1, 2]);
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 3,
            dst_reg: 3,
            size: BPF_W,
            offset: 4,
        }]
    );
    assert!(uses.other_uses.is_empty());
}

#[test]
fn classify_r0_uses_does_not_treat_non_zero_alias_offset_as_null_check() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        add64_imm(6, 4),
        jeq_imm(6, 0, 1),
        BpfInsn::ldx_mem(BPF_W, 3, 6, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(uses.null_check_pc, None);
    assert_eq!(uses.other_uses, vec![3]);
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 4,
            dst_reg: 3,
            size: BPF_W,
            offset: 4,
        }]
    );
}

#[test]
fn classify_r0_uses_can_follow_callee_saved_alias_across_helper_when_enabled() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(9, 0),
        jeq_imm(9, 0, 2),
        call_helper(2),
        BpfInsn::ldx_mem(BPF_W, 3, 9, 4),
    ];

    let strict_uses = classify_r0_uses(&insns, 0);
    assert_eq!(strict_uses.other_uses, vec![3]);
    assert!(strict_uses.fixed_loads.is_empty());

    let relaxed_uses = classify_r0_uses_with_options(&insns, 0, true, true);
    assert_eq!(relaxed_uses.null_check_pc, Some(2));
    assert_eq!(relaxed_uses.other_uses, Vec::<usize>::new());
    assert_eq!(
        relaxed_uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 4,
            dst_reg: 3,
            size: BPF_W,
            offset: 4,
        }]
    );
}

#[test]
fn classify_r0_uses_tracks_stack_spill_and_reload_across_helper() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::stx_mem(BPF_DW, 10, 0, -16),
        call_helper(2),
        BpfInsn::ldx_mem(BPF_DW, 6, 10, -16),
        BpfInsn::ldx_mem(BPF_W, 3, 6, 4),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(uses.other_uses, Vec::<usize>::new());
    assert_eq!(uses.alias_copy_pcs, vec![1, 3]);
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 4,
            dst_reg: 3,
            size: BPF_W,
            offset: 4,
        }]
    );
    assert!(uses.all_fixed_loads());
}

#[test]
fn classify_r0_uses_allows_helper_argument_loaded_from_lookup_value() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 4),
        BpfInsn::mov64_reg(1, 6),
        call_helper(2),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 1,
            dst_reg: 6,
            size: BPF_W,
            offset: 4,
        }]
    );
    assert!(uses.other_uses.is_empty());
    assert!(uses.all_fixed_loads());
}

#[test]
fn classify_r0_uses_marks_pointer_escape_after_null_check_as_other() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 2),
        BpfInsn::mov64_reg(1, 0),
        call_helper(2),
        BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(uses.null_check_pc, Some(1));
    assert_eq!(uses.other_uses, vec![3]);
    assert!(!uses.all_fixed_loads());
}

#[test]
fn classify_r0_uses_marks_store_back_as_other_use() {
    let insns = vec![
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 1, 0, 0),
        add64_imm(1, 1),
        BpfInsn::stx_mem(BPF_W, 0, 1, 0),
    ];

    let uses = classify_r0_uses(&insns, 0);
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 1,
            dst_reg: 1,
            size: BPF_W,
            offset: 0,
        }]
    );
    assert_eq!(uses.other_uses, vec![3]);
    assert!(!uses.all_fixed_loads());
}

#[test]
fn map_inline_pass_rewrites_lookup_and_scalar_loads() {
    install_array_map(101, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::ldx_mem(BPF_B, 7, 0, 4),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![101]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov32_imm(7, 0xaa),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_lookup_with_fp_alias_store_key_and_offset_load() {
    install_array_map_entry(9251, 16, 7, vec![0, 0, 0, 0, 42, 0, 0, 0], true);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_reg(6, 10),
        add64_imm(6, -8),
        st_mem(BPF_W, 6, 4, 7),
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        add64_imm(6, 4),
        BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9251]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_reg(6, 10),
            add64_imm(6, -8),
            BpfInsn::mov32_imm(7, 42),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_struct_value_multiple_fields() {
    let mut value = vec![0u8; 16];
    value[0..4].copy_from_slice(&0x1234_5678u32.to_le_bytes());
    value[8..16].copy_from_slice(&0x0123_4567_89ab_cdefu64.to_le_bytes());
    install_array_map(110, value);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::ldx_mem(BPF_DW, 7, 0, 8),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![110]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(program.insns.len(), 5);
    assert_eq!(program.insns[0], BpfInsn::mov32_imm(6, 0x1234_5678i32));
    assert!(program.insns[1].is_ldimm64());
    assert_eq!(program.insns[1].dst_reg(), 7);
    assert_eq!(program.insns[1].imm as u32 as u64, 0x89ab_cdef);
    assert_eq!(program.insns[2].imm as u32 as u64, 0x0123_4567);
    assert_eq!(program.insns[3], BpfInsn::mov64_imm(0, 0));
    assert_eq!(program.insns[4], exit_insn());
}

#[test]
fn map_inline_pass_rewrites_u32_max_with_mov32_imm() {
    install_array_map(111, 0xffff_ffffu32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![111]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov32_imm(6, -1),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_removes_null_check_and_dead_cold_block() {
    install_array_map(102, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 3),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![102]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_keeps_null_check_when_non_null_window_has_side_effects() {
    install_array_map(1602, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 5),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::stx_mem(BPF_W, 10, 6, -8),
        jeq_imm(6, 0, 1),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![1602]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert!(program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(program.insns.contains(&jeq_imm(0, 0, 5)));
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
}

#[test]
fn map_inline_pass_emits_ldimm64_for_wide_constants() {
    install_array_map(103, 0x1_0000_0000u64.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![103]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(program.insns.len(), 4);
    assert!(program.insns[0].is_ldimm64());
    assert_eq!(program.insns[0].dst_reg(), 6);
    assert_eq!(program.insns[0].imm as u32 as u64, 0);
    assert_eq!(program.insns[1].imm as u32 as u64, 1);
}

#[test]
fn map_inline_pass_skips_non_constant_key() {
    install_array_map(104, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        BpfInsn::stx_mem(BPF_W, 10, 3, -4),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![104]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("key extraction failed")));
}

#[test]
fn map_inline_pass_skips_pseudo_map_value_lookup_key_without_verifier_state() {
    let key_bytes = (0u8..20).collect::<Vec<_>>();
    install_array_map_entry(9401, 1, 0, key_bytes.clone(), true);

    let mut values = HashMap::new();
    values.insert(key_bytes.clone(), 42u32.to_le_bytes().to_vec());
    install_map_with_key_size(9402, 1, 20, 16, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let key = ld_imm64_parts(2, BPF_PSEUDO_MAP_VALUE, 43, 0);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        key[0],
        key[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9402, 9401]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(result.total_sites_applied, 0);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("no verifier states available")));
}

#[test]
fn map_inline_pass_skips_16_byte_key_without_verifier_support() {
    let lo = 0x0706_0504_0302_0100u64;
    let hi = 0x0f0e_0d0c_0b0a_0908u64;
    let mut key_bytes = lo.to_le_bytes().to_vec();
    key_bytes.extend_from_slice(&hi.to_le_bytes());

    let mut values = HashMap::new();
    values.insert(key_bytes.clone(), 42u32.to_le_bytes().to_vec());
    install_map_with_key_size(9302, 1, 16, 8, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let key_lo = emit_ldimm64(3, lo);
    let key_hi = emit_ldimm64(4, hi);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        key_lo[0],
        key_lo[1],
        BpfInsn::stx_mem(BPF_DW, 10, 3, -16),
        key_hi[0],
        key_hi[1],
        BpfInsn::stx_mem(BPF_DW, 10, 4, -8),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -16),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 3),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9302]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(result.total_sites_applied, 0);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("supports up to 8-byte keys")));
}

#[test]
fn map_inline_pass_uses_verifier_guided_wide_zero_store_key() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), 42u32.to_le_bytes().to_vec());
    install_map(7001, 2, 8, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 123);
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(3, 0),
        BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        exit_insn(),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![7001]);
    program.set_verifier_states(vec![
        verifier_delta_state(1, HashMap::from([(3, scalar_reg(0))])),
        verifier_delta_state(3, HashMap::from([(2, fp_reg(-4))])),
        verifier_delta_state(6, HashMap::new()),
        verifier_delta_state(8, HashMap::from([(6, scalar_reg(42))])),
    ]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 42)));
    assert!(program
        .insns
        .iter()
        .all(|insn| !(insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)));
}

#[test]
fn map_inline_pass_removes_hash_lookup_and_null_path_when_entry_present() {
    install_hash_map(105, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 3),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![105]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("site at PC=5: inlined successfully")));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("site at PC=5: inlined successfully, value=0x7")));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("speculative map-inline sites: 1")));
}

#[test]
fn map_inline_pass_skips_20_byte_constant_key_without_verifier_support() {
    let mut values = HashMap::new();
    let mut key_bytes = vec![0u8; 20];
    key_bytes[16..20].copy_from_slice(&1u32.to_le_bytes());
    values.insert(key_bytes.clone(), 7u32.to_le_bytes().to_vec());
    install_map_with_key_size(9310, 1, 20, 8, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_imm(3, 0),
        BpfInsn::stx_mem(BPF_DW, 10, 3, -20),
        BpfInsn::stx_mem(BPF_DW, 10, 3, -12),
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -20),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 3),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9310]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(result.total_sites_applied, 0);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("supports up to 8-byte keys")));
}

#[test]
fn map_inline_pass_keeps_hash_lookup_and_rewrites_jne_guarded_load() {
    install_hash_map(122, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jne_imm(0, 0, 1),
        ja(3),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![122]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jne_imm(0, 0, 1),
            ja(3),
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_keeps_lookup_and_rewrites_load_when_setup_has_branch_target() {
    install_hash_map(123, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(3, 1),
        jne_imm(3, 0, 2),
        BpfInsn::mov64_imm(4, 0),
        BpfInsn::mov64_imm(4, 0),
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 1),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![123]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(3, 1),
            jne_imm(3, 0, 2),
            BpfInsn::mov64_imm(4, 0),
            BpfInsn::mov64_imm(4, 0),
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            map[0],
            map[1],
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 1),
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
    assert!(
        !result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason == "lookup pattern contains a branch target"),
        "site should keep lookup while still rewriting the load: {:?}",
        result.pass_results[0].sites_skipped
    );
}

#[test]
fn map_inline_pass_removes_hash_lookup_before_helper_using_loaded_scalar() {
    install_hash_map(1061, vec![0, 0, 0, 0, 7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 5),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 4),
        BpfInsn::mov64_reg(1, 6),
        call_helper(2),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![1061]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_reg(1, 6),
            call_helper(2),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_does_not_use_non_verifier_fixpoint_fallback() {
    install_array_map(9203, 2u32.to_le_bytes().to_vec());
    install_array_map_entry(9204, 8, 2, 11u32.to_le_bytes().to_vec(), true);

    let map0 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let map1 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 43);
    let mut program = BpfProgram::new(vec![
        map0[0],
        map0[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::stx_mem(BPF_DW, 10, 6, -16),
        BpfInsn::ldx_mem(BPF_DW, 7, 10, -16),
        BpfInsn::stx_mem(BPF_W, 10, 7, -8),
        map1[0],
        map1[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 8, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9203, 9204]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert!(
        program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM),
        "expected later lookup helper to remain without refreshed verifier state, got: {:?}",
        program.insns
    );
    assert!(
        !program
            .insns
            .iter()
            .any(|insn| insn.code == (BPF_ALU | BPF_MOV | BPF_K)
                && insn.dst_reg() == 8
                && insn.imm == 11),
        "did not expect non-verifier fallback to constantize final lookup, got: {:?}",
        program.insns
    );
}

#[test]
fn map_inline_pass_rewrites_lookup_inside_subprog() {
    install_array_map(109, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 1), 0, 2),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_imm(9, 0),
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![109]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(program.insns[0].imm, 2);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 1), 0, 2),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(9, 0),
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_skips_mutable_array_lookup_with_store_back() {
    install_mutable_array_map(415, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        add64_imm(6, 1),
        BpfInsn::stx_mem(BPF_W, 0, 6, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![415]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0].sites_skipped.iter().any(|skip| skip
        .reason
        .contains("mutable lookup result has non-load uses")));
}

#[test]
fn map_inline_pass_inlines_mutable_array_across_readonly_helper_call() {
    install_mutable_array_map(411, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(9, 0),
        call_helper(HELPER_KTIME_GET_NS),
        BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![411]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            call_helper(HELPER_KTIME_GET_NS),
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_skips_mutable_array_across_side_effect_helper_call() {
    install_mutable_array_map(412, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(9, 0),
        call_helper(2),
        BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![412]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("fixed-offset scalar loads")));
}

#[test]
fn map_inline_pass_errors_when_array_snapshot_key_is_absent() {
    install_empty_map(311, 2, 8, 8, true);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::ldx_mem(BPF_DW, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![311]);

    let err = try_run_map_inline_pass(&mut program).unwrap_err();
    let message = format!("{err:#}");
    assert!(message.contains("map_inline requires a concrete snapshot value"));
    assert!(message.contains("map_values snapshot missing map 311 key 02000000"));
}

#[test]
fn map_inline_pass_records_inlined_sites_for_tracker() {
    let value = vec![7, 0, 0, 0];
    install_array_map(115, value.clone());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![115]);

    let result = run_map_inline_pass(&mut program);

    assert_eq!(
        result.pass_results[0].map_inline_records,
        vec![MapInlineRecord {
            map_id: 115,
            key: 1u32.to_le_bytes().to_vec(),
            expected_value: value,
        }]
    );
}

#[test]
fn map_inline_pass_inlines_uniform_percpu_array_maps() {
    let blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), blob.clone());
    install_percpu_array_map(112, 4, 8, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![112]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(program
        .insns
        .iter()
        .any(|insn| insn == &BpfInsn::mov32_imm(6, 7)));
    assert!(
        result.pass_results[0].map_inline_records[0].expected_value == blob,
        "tracker should store the full per-cpu blob: {:?}",
        result.pass_results[0].map_inline_records
    );
}

#[test]
fn map_inline_pass_errors_when_percpu_array_default_snapshot_is_absent() {
    install_percpu_array_map(916, 4, 8, true, HashMap::new());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![916]);

    let err = try_run_map_inline_pass(&mut program).unwrap_err();
    let message = format!("{err:#}");
    assert!(message.contains("map_inline requires a concrete snapshot value"));
    assert!(message.contains("map_values snapshot missing map 916 key 01000000"));
}

#[test]
fn map_inline_pass_skips_mixed_percpu_array_maps() {
    let mut blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
    blob[8..12].copy_from_slice(&9u32.to_le_bytes());
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), blob);
    install_percpu_array_map(212, 4, 8, true, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![212]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(
        result.pass_results[0].sites_skipped.iter().any(|skip| skip
            .reason
            .contains("PERCPU_ARRAY value differs across CPUs")),
        "mixed PERCPU_ARRAY should be rejected with a precise reason: {:?}",
        result.pass_results[0].sites_skipped
    );
}

#[test]
fn map_inline_pass_skips_percpu_hash_family_maps() {
    for (map_id, map_type) in [
        (113, BPF_MAP_TYPE_PERCPU_HASH),
        (114, BPF_MAP_TYPE_LRU_PERCPU_HASH),
    ] {
        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
        install_map(map_id, map_type, 8, true, values);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![map_id]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(
            result.pass_results[0]
                .sites_skipped
                .iter()
                .any(|skip| skip.reason.contains("not inlineable")),
            "map type {map_type} should be rejected: {:?}",
            result.pass_results[0].sites_skipped
        );
    }
}
