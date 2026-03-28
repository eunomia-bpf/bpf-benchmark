use super::*;
use std::collections::HashMap;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, MapInfoAnalysis};
use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
use crate::pass::{MapInlineRecord, PassContext, PassManager};
use crate::passes::{ConstPropPass, DcePass};
use crate::verifier_log::parse_verifier_log;

fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
    [
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst, src),
            off: 0,
            imm,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        },
    ]
}

fn ld_imm64_parts(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
    [
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst, src),
            off: 0,
            imm: imm_lo,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: imm_hi,
        },
    ]
}

fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn {
        code: BPF_ST | size | BPF_MEM,
        regs: BpfInsn::make_regs(dst, 0),
        off,
        imm,
    }
}

fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
    BpfInsn {
        code: BPF_ALU64 | BPF_ADD | BPF_K,
        regs: BpfInsn::make_regs(dst, 0),
        off: 0,
        imm,
    }
}

fn call_helper(imm: i32) -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_CALL,
        regs: BpfInsn::make_regs(0, 0),
        off: 0,
        imm,
    }
}

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_JEQ | BPF_K,
        regs: BpfInsn::make_regs(dst, 0),
        off,
        imm,
    }
}

fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_JNE | BPF_K,
        regs: BpfInsn::make_regs(dst, 0),
        off,
        imm,
    }
}

fn exit_insn() -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_EXIT,
        regs: 0,
        off: 0,
        imm: 0,
    }
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
    let mut info = BpfMapInfo::default();
    info.map_type = map_type;
    info.id = map_id;
    info.key_size = key_size;
    info.value_size = values.values().next().map(|value| value.len()).unwrap_or(0) as u32;
    info.max_entries = max_entries;

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values,
        },
    );
}

fn install_empty_map(
    map_id: u32,
    map_type: u32,
    value_size: u32,
    max_entries: u32,
    frozen: bool,
) {
    let mut info = BpfMapInfo::default();
    info.map_type = map_type;
    info.id = map_id;
    info.key_size = 4;
    info.value_size = value_size;
    info.max_entries = max_entries;

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
    let mut info = BpfMapInfo::default();
    info.map_type = BPF_MAP_TYPE_PERCPU_ARRAY;
    info.id = map_id;
    info.key_size = 4;
    info.value_size = value_size;
    info.max_entries = max_entries;

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

fn install_array_map_entry(
    map_id: u32,
    max_entries: u32,
    key: u32,
    value: Vec<u8>,
    frozen: bool,
) {
    let mut values = HashMap::new();
    values.insert(key.to_le_bytes().to_vec(), value.clone());

    let mut info = BpfMapInfo::default();
    info.map_type = 2;
    info.id = map_id;
    info.key_size = 4;
    info.value_size = value.len() as u32;
    info.max_entries = max_entries;

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen,
            values,
        },
    );
}

fn install_empty_array_map(map_id: u32, value_size: u32, max_entries: u32) {
    let mut info = BpfMapInfo::default();
    info.map_type = 2;
    info.id = map_id;
    info.key_size = 4;
    info.value_size = value_size;
    info.max_entries = max_entries;

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen: true,
            values: HashMap::new(),
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
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(MapInfoAnalysis);
    pm.add_pass(MapInlinePass);
    pm.run(program, &PassContext::test_default()).unwrap()
}

fn run_map_inline_const_prop_dce(program: &mut BpfProgram) -> PipelineResult {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(MapInfoAnalysis);
    pm.add_pass(MapInlinePass);
    pm.add_pass(ConstPropPass);
    pm.add_pass(DcePass);
    pm.run(program, &PassContext::test_default()).unwrap()
}
fn has_non_constant_key_skip(result: &PipelineResult) -> bool {
    result.pass_results[0].sites_skipped.iter().any(|skip| {
        skip.reason
            .contains("lookup key is not a constant stack or pseudo-map-value materialization")
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
    assert_eq!(program.insns[2], BpfInsn::mov64_imm(2, 42));
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

    let states = parse_verifier_log(
        r#"
0: R1=ctx() R10=fp0
0: (b7) r3 = 0                        ; R3=0
1: (7b) *(u64 *)(r10 -8) = r3         ; R3=0 R10=fp0 fp-8=0
2: (bf) r2 = r10                      ; R2=fp0 R10=fp0
3: (07) r2 += -4                      ; R2=fp-4
4: (18) r1 = 0xffff8f09c3e45000       ; R1=map_ptr(map=test_array,ks=4,vs=4)
6: (85) call bpf_map_lookup_elem#1    ; R0=map_value_or_null(id=1,map=test_array,ks=4,vs=4)
"#,
    );

    let key = try_extract_constant_key_verifier_guided(&insns, &states, 6, 4).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.width, 4);
    assert_eq!(key.value, 0);
    assert_eq!(key.store_pc, 1);
}

#[test]
fn extract_constant_key_from_r2_add_reg_constant() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        st_mem(BPF_W, 10, -4, 7),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::mov64_imm(3, -4),
        BpfInsn::alu64_reg(BPF_ADD, 2, 3),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];

    let key = extract_constant_key(&insns, 6).unwrap();
    assert_eq!(key.stack_off, -4);
    assert_eq!(key.value, 7);
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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(7, 0xaa),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_loads_from_alias_register() {
    install_array_map(120, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        jeq_imm(6, 0, 1),
        BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![120]);

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
            BpfInsn::mov64_imm(7, 7),
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
    assert_eq!(program.insns[0], BpfInsn::mov64_imm(6, 0x1234_5678i32));
    assert!(program.insns[1].is_ldimm64());
    assert_eq!(program.insns[1].dst_reg(), 7);
    assert_eq!(program.insns[1].imm as u32 as u64, 0x89ab_cdef);
    assert_eq!(program.insns[2].imm as u32 as u64, 0x0123_4567);
    assert_eq!(program.insns[3], BpfInsn::mov64_imm(0, 0));
    assert_eq!(program.insns[4], exit_insn());
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
            BpfInsn::mov64_imm(6, 7),
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
    assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 7)));
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
fn map_inline_pass_emits_mov64_imm_for_dw_constants_that_fit_i32() {
    install_array_map(1513, 42u64.to_le_bytes().to_vec());

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
    program.set_map_ids(vec![1513]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(6, 42),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
    assert!(!program.insns[0].is_ldimm64());
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
fn test_map_inline_real_clang_order() {
    install_array_map(117, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![117]);

    let key = extract_constant_key(&program.insns, 5).unwrap();
    assert_eq!(key.value, 1);
    assert_eq!(key.stack_off, -4);

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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn test_map_inline_interleaved_arg_setup() {
    install_array_map(118, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        BpfInsn::mov64_imm(3, 9),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![118]);

    let key = extract_constant_key(&program.insns, 6).unwrap();
    assert_eq!(key.value, 1);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(program.insns[7], BpfInsn::mov64_imm(6, 7));
    assert_eq!(program.insns.last().copied(), Some(exit_insn()));
}

#[test]
fn test_map_inline_r2_clobbered_between() {
    install_array_map(119, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        BpfInsn::mov64_imm(2, 0),
        map[0],
        map[1],
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![119]);

    assert!(extract_constant_key(&program.insns, 6).is_none());

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(has_non_constant_key_skip(&result));
}

#[test]
fn map_inline_pass_rewrites_array_lookup_with_pseudo_map_value_zero_key() {
    install_array_map_entry(9120, 8, 0, vec![7, 0, 0, 0], true);
    install_array_map_entry(9121, 1, 0, vec![0, 0, 0, 0], true);

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
    program.set_map_ids(vec![9120, 9121]);

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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_hash_lookup_with_pseudo_map_value_20_byte_key() {
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

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 42)));
    assert_eq!(result.pass_results[0].map_inline_records.len(), 1);
    assert_eq!(result.pass_results[0].map_inline_records[0].key, key_bytes);
    assert_eq!(
        result.pass_results[0].map_inline_records[0].expected_value,
        42u32.to_le_bytes().to_vec()
    );
}

#[test]
fn map_inline_pass_rewrites_lookup_with_split_halfword_key_materialization() {
    install_array_map_entry(9301, 16, 7, 42u32.to_le_bytes().to_vec(), true);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_H, 10, -4, 7),
        st_mem(BPF_H, 10, -2, 0),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9301]);

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
            st_mem(BPF_H, 10, -4, 7),
            st_mem(BPF_H, 10, -2, 0),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_imm(6, 42),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
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
    program.set_verifier_log(
        r#"
0: R1=ctx() R10=fp0
0: (b7) r3 = 0                        ; R3=0
1: (7b) *(u64 *)(r10 -8) = r3         ; R3=0 R10=fp0 fp-8=0
2: (bf) r2 = r10                      ; R2=fp0 R10=fp0
3: (07) r2 += -4                      ; R2=fp-4
4: (18) r1 = 0xffff8f09c3e45000       ; R1=map_ptr(map=test_array,ks=4,vs=4)
6: (85) call bpf_map_lookup_elem#1    ; R0=map_value_or_null(id=1,map=test_array,ks=4,vs=4)
7: (15) if r0 == 0x0 goto pc+2        ; R0=map_value(map=test_array,ks=4,vs=4)
8: (61) r6 = *(u32 *)(r0 +0)          ; R0=map_value(map=test_array,ks=4,vs=4) R6=42
"#,
    );

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov64_imm(6, 42)));
    assert!(program
        .insns
        .iter()
        .all(|insn| !(insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)));
}

#[test]
fn map_inline_pass_keeps_hash_lookup_and_null_check() {
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
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 3),
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    );
    assert_eq!(
        result.pass_results[0]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("site at PC=5: inlined successfully")),
        true
    );
    assert_eq!(
        result.pass_results[0]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("site at PC=5: inlined successfully, value=0x7")),
        true
    );
    assert_eq!(
        result.pass_results[0]
            .diagnostics
            .iter()
            .any(|diag| diag.contains("speculative map-inline sites: 1")),
        true
    );
}

#[test]
fn map_inline_pass_rewrites_hash_lookup_with_20_byte_constant_key() {
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
            BpfInsn::mov64_imm(3, 0),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -20),
            BpfInsn::stx_mem(BPF_DW, 10, 3, -12),
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -20),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 3),
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    );
    assert_eq!(result.pass_results[0].map_inline_records[0].key, key_bytes);
}

#[test]
fn map_inline_pass_keeps_hash_lookup_and_rewrites_alias_load() {
    install_hash_map(121, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(6, 0),
        jeq_imm(6, 0, 3),
        BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![121]);

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
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 3),
            BpfInsn::mov64_imm(7, 7),
            BpfInsn::mov64_imm(0, 0),
            ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    );
}

#[test]
fn classify_r0_uses_tracks_jne_null_check() {
    let uses = classify_r0_uses(
        &[
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jne_imm(0, 0, 1),
            ja(2),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ],
        0,
    );

    assert_eq!(uses.null_check_pc, Some(1));
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 3,
            dst_reg: 6,
            size: BPF_W,
            offset: 0,
        }]
    );
    assert!(uses.other_uses.is_empty());
}

#[test]
fn classify_r0_uses_tracks_backward_jeq_null_check() {
    let uses = classify_r0_uses(
        &[
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn {
                code: BPF_JMP | BPF_JEQ | BPF_K,
                regs: BpfInsn::make_regs(0, 0),
                off: -1,
                imm: 0,
            },
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ],
        0,
    );

    assert_eq!(uses.null_check_pc, Some(1));
    assert_eq!(
        uses.fixed_loads,
        vec![FixedLoadUse {
            pc: 2,
            dst_reg: 6,
            size: BPF_W,
            offset: 0,
        }]
    );
    assert!(uses.other_uses.is_empty());
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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_load_before_pointer_escape_to_helper() {
    install_array_map(106, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_reg(1, 0),
        call_helper(2),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![106]);

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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_reg(1, 0),
            call_helper(2),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_load_before_lookup_result_write_back() {
    install_array_map(116, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        st_mem(BPF_W, 0, 0, 99),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![116]);

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
            BpfInsn::mov64_imm(6, 7),
            st_mem(BPF_W, 0, 0, 99),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_rewrites_multiple_lookup_sites() {
    install_array_map(107, vec![7, 0, 0, 0]);
    install_array_map(108, vec![9, 0, 0, 0]);

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
        map1[0],
        map1[1],
        st_mem(BPF_W, 10, -8, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![107, 108]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 2);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(7, 9),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_reaches_fixpoint_across_cascading_lookup_keys() {
    install_array_map(9201, 2u32.to_le_bytes().to_vec());
    install_array_map_entry(9202, 8, 2, 9u32.to_le_bytes().to_vec(), true);

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
        BpfInsn::stx_mem(BPF_W, 10, 6, -8),
        map1[0],
        map1[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9201, 9202]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.total_sites_applied, 2);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(7, 9),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_reaches_fixpoint_through_stack_reloaded_key() {
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
    assert_eq!(result.total_sites_applied, 2);
    assert!(
        !program
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM),
        "expected both lookup helpers to be eliminated, got: {:?}",
        program.insns
    );
    assert!(
        program
            .insns
            .iter()
            .any(|insn| insn.code == (BPF_ALU64 | BPF_MOV | BPF_K)
                && insn.dst_reg() == 8
                && insn.imm == 11),
        "expected final lookup load to become constant, got: {:?}",
        program.insns
    );
}

#[test]
fn map_inline_pass_rewrites_lookup_inside_subprog() {
    install_array_map(109, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 1),
            off: 0,
            imm: 2,
        },
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
            BpfInsn {
                code: BPF_JMP | BPF_CALL,
                regs: BpfInsn::make_regs(0, 1),
                off: 0,
                imm: 2,
            },
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(9, 0),
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_inlines_non_frozen_array_maps() {
    install_mutable_array_map(111, vec![7, 0, 0, 0]);

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
    program.set_map_ids(vec![111]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(6, 7),
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
fn map_inline_pass_inlines_read_only_site_after_same_map_writeback_elsewhere() {
    install_mutable_array_map(416, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        add64_imm(6, 1),
        BpfInsn::stx_mem(BPF_W, 0, 6, 0),
        map[0],
        map[1],
        st_mem(BPF_W, 10, -8, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![416]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
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
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            add64_imm(6, 1),
            BpfInsn::stx_mem(BPF_W, 0, 6, 0),
            BpfInsn::mov64_imm(7, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
    assert!(result.pass_results[0].sites_skipped.iter().any(|skip| skip
        .reason
        .contains("mutable lookup result has non-load uses")));
    assert!(!result.pass_results[0].sites_skipped.iter().any(|skip| skip
        .reason
        .contains("mutable map value is written elsewhere in program")));
}

#[test]
fn map_inline_pass_keeps_other_mutable_read_only_maps_inlineable() {
    install_mutable_array_map(417, vec![7, 0, 0, 0]);
    install_mutable_array_map(418, vec![11, 0, 0, 0]);

    let map1 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let map2 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 43);
    let mut program = BpfProgram::new(vec![
        map1[0],
        map1[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        add64_imm(6, 1),
        BpfInsn::stx_mem(BPF_W, 0, 6, 0),
        map2[0],
        map2[1],
        st_mem(BPF_W, 10, -8, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![417, 418]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(
        program
            .insns
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)
            .count(),
        1
    );
    assert!(program
        .insns
        .iter()
        .any(|insn| insn == &BpfInsn::mov64_imm(7, 11)));
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
            BpfInsn::mov64_imm(6, 7),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_skips_hash_lookup_across_readonly_helper_call() {
    install_hash_map(413, vec![7, 0, 0, 0]);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(9, 0),
        jeq_imm(9, 0, 2),
        call_helper(HELPER_KTIME_GET_NS),
        BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![413]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("fixed-offset scalar loads")));
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
fn map_inline_pass_inlines_zero_filled_array_maps() {
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

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(6, 0),
            BpfInsn::mov64_imm(7, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_inlines_zero_filled_percpu_array_maps() {
    install_empty_map(312, BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, true);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 3),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![312]);

    let result = run_map_inline_pass(&mut program);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov64_imm(6, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
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
fn map_inline_pass_inlines_zero_filled_array_defaults() {
    install_empty_array_map(915, 4, 8);

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
    program.set_map_ids(vec![915]);

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert_eq!(
        result.pass_results[0].map_inline_records[0].expected_value,
        vec![0u8; 4]
    );
    assert!(program
        .insns
        .iter()
        .any(|insn| insn == &BpfInsn::mov64_imm(6, 0)));
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
        .any(|insn| insn == &BpfInsn::mov64_imm(6, 7)));
    assert!(
        result.pass_results[0].map_inline_records[0].expected_value == blob,
        "tracker should store the full per-cpu blob: {:?}",
        result.pass_results[0].map_inline_records
    );
}

#[test]
fn map_inline_pass_inlines_zero_filled_percpu_array_defaults() {
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

    let result = run_map_inline_pass(&mut program);

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(
        program
            .insns
            .iter()
            .any(|insn| insn == &BpfInsn::mov64_imm(6, 0)),
        "program should inline a zero constant: {:?}",
        program.insns
    );
    assert!(
        result.pass_results[0].map_inline_records[0]
            .expected_value
            .iter()
            .all(|byte| *byte == 0),
        "tracker should preserve the full zero-filled per-cpu blob: {:?}",
        result.pass_results[0].map_inline_records
    );
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

/// PERCPU_HASH maps must not be inlined either.
#[test]
fn map_inline_pass_skips_percpu_hash_maps() {
    // map_type 5 = BPF_MAP_TYPE_PERCPU_HASH
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
    install_map(113, 5, 8, true, values);

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
    program.set_map_ids(vec![113]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(
        result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("not inlineable")),
        "PERCPU_HASH should be rejected: {:?}",
        result.pass_results[0].sites_skipped
    );
}

/// LRU_PERCPU_HASH maps must not be inlined either.
#[test]
fn map_inline_pass_skips_lru_percpu_hash_maps() {
    // map_type 10 = BPF_MAP_TYPE_LRU_PERCPU_HASH
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), vec![7, 0, 0, 0]);
    install_map(114, 10, 8, true, values);

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
    program.set_map_ids(vec![114]);

    let result = run_map_inline_pass(&mut program);

    assert!(!result.program_changed);
    assert_eq!(program.insns, original);
    assert!(
        result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("not inlineable")),
        "LRU_PERCPU_HASH should be rejected: {:?}",
        result.pass_results[0].sites_skipped
    );
}
