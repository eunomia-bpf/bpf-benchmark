use super::*;
use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicUsize, Ordering};

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis};
use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
use crate::mock_maps::use_mock_maps;
use crate::pass::{
    Analysis, CompressedMapValues, CompressedMapValuesKind, MapInlineHint, MapInlineHintAnchor,
    MapInlineHintMode, MapInlineRecord, MapMetadata, PassContext, PassManager, RegState,
    StackState, VerifierInsn, VerifierInsnKind,
};
use crate::passes::MapInfoAnalysis;
use crate::passes::{ConstPropPass, DcePass};
use crate::test_helpers::*;

const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY;
const BPF_MAP_TYPE_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_HASH;
const BPF_MAP_TYPE_LRU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_HASH;
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH;
const BPF_MAP_TYPE_LPM_TRIE: u32 = kernel_sys::BPF_MAP_TYPE_LPM_TRIE;
const BPF_MAP_TYPE_ARRAY_OF_MAPS: u32 = kernel_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS;
const BPF_MAP_TYPE_HASH_OF_MAPS: u32 = kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS;
static NEXT_TEMP_DIR: AtomicUsize = AtomicUsize::new(0);

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

fn imprecise_scalar_reg(value: u64) -> RegState {
    let mut reg = scalar_reg(value);
    reg.precise = false;
    reg
}

fn verifier_full_state_with_stack(
    pc: usize,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame: 0,
        from_pc: Some(pc.saturating_sub(1)),
        kind: VerifierInsnKind::EdgeFullState,
        speculative: false,
        regs,
        stack,
    }
}

fn ja(off: i16) -> BpfInsn {
    BpfInsn::ja(off)
}

fn install_map_with_key_size(
    map_id: u32,
    map_type: u32,
    key_size: u32,
    max_entries: u32,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    let info = BpfMapInfo {
        map_type,
        key_size,
        value_size: values.values().next().map(|value| value.len()).unwrap_or(0) as u32,
        max_entries,
    };

    install_mock_map(map_id, MockMapState { info, values });
}

fn install_percpu_array_map(
    map_id: u32,
    value_size: u32,
    max_entries: u32,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    let info = BpfMapInfo {
        map_type: BPF_MAP_TYPE_PERCPU_ARRAY,
        key_size: 4,
        value_size,
        max_entries,
    };

    install_mock_map(map_id, MockMapState { info, values });
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

fn install_array_map_entry(map_id: u32, max_entries: u32, key: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(key.to_le_bytes().to_vec(), value.clone());

    let info = BpfMapInfo {
        map_type: 2,
        key_size: 4,
        value_size: value.len() as u32,
        max_entries,
    };

    install_mock_map(map_id, MockMapState { info, values });
}

fn install_hash_map(map_id: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value);
    install_map(map_id, 1, 8, values);
}

fn install_snapshot_values(
    program: &mut BpfProgram,
    map_id: u32,
    values: &HashMap<Vec<u8>, Vec<u8>>,
) {
    for (key, value) in values {
        program
            .map_values
            .insert((map_id, key.clone()), value.clone());
    }
}

fn pc_inline_hint(pc: usize, mode: MapInlineHintMode, key: Vec<u8>) -> MapInlineHint {
    MapInlineHint {
        anchor: MapInlineHintAnchor::Pc(pc),
        mode,
        key,
    }
}

fn map_name_inline_hint(name: &str, mode: MapInlineHintMode, key: Vec<u8>) -> MapInlineHint {
    MapInlineHint {
        anchor: MapInlineHintAnchor::MapName(name.to_string()),
        mode,
        key,
    }
}

fn install_named_map_metadata(
    program: &mut BpfProgram,
    map_id: u32,
    map_type: u32,
    value_size: u32,
    max_entries: u32,
    name: &str,
) {
    program.map_metadata.insert(
        map_id,
        MapMetadata {
            map_type,
            key_size: 4,
            value_size,
            max_entries,
            map_id,
            name: name.to_string(),
        },
    );
}

fn temp_map_values_dir(name: &str) -> PathBuf {
    let id = NEXT_TEMP_DIR.fetch_add(1, Ordering::Relaxed);
    std::env::temp_dir().join(format!(
        "bpfopt-map-inline-{}-{id}-{name}",
        std::process::id()
    ))
}

fn remove_dir_if_exists(path: &Path) {
    match fs::remove_dir_all(path) {
        Ok(()) => {}
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
        Err(err) => panic!("remove {}: {err}", path.display()),
    }
}

fn write_map_show(dir: &Path, map_id: u32, map_type: &str, value_size: u32) {
    fs::write(
        dir.join(format!("map-{map_id}.show.json")),
        format!(
            r#"{{
              "id": {map_id},
              "type": "{map_type}",
              "name": "test_map",
              "bytes_key": 4,
              "bytes_value": {value_size},
              "max_entries": 8
            }}"#
        ),
    )
    .expect("write map show");
}

fn compressed_overlay_metadata(value_size: u32) -> MapMetadata {
    MapMetadata {
        map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
        key_size: 4,
        value_size,
        max_entries: 8,
        map_id: 9001,
        name: "overlay_map".to_string(),
    }
}

#[test]
fn compressed_overlay_schema_validation_fail_fast() {
    let metadata = compressed_overlay_metadata(4);
    for (label, json, expected) in [
        (
            "unknown compression",
            r#"{"compression":"delta","value_size":4,"value_hex":"01000000"}"#,
            "unsupported compression",
        ),
        (
            "uniform missing value",
            r#"{"compression":"uniform","value_size":4}"#,
            "uniform compression requires value_hex",
        ),
        (
            "sparse missing default",
            r#"{"compression":"sparse","value_size":4,"entries":{"00000001":"02000000"}}"#,
            "sparse compression requires default_hex",
        ),
        (
            "enumerated missing entries",
            r#"{"compression":"enumerated","value_size":4}"#,
            "enumerated compression requires entries",
        ),
        (
            "uniform value length",
            r#"{"compression":"uniform","value_size":4,"value_hex":"0100"}"#,
            "value_hex has 4 hex digit(s), expected 8",
        ),
        (
            "sparse default length",
            r#"{"compression":"sparse","value_size":4,"default_hex":"00","entries":{}}"#,
            "default_hex has 2 hex digit(s), expected 8",
        ),
        (
            "entry value length",
            r#"{"compression":"enumerated","value_size":4,"entries":{"00000001":"02"}}"#,
            "entries value has 2 hex digit(s), expected 8",
        ),
        (
            "raw entries plus compression",
            r#"{"compression":"uniform","value_size":4,"value_hex":"01000000","entries":[{"key":"00000000","value":"01000000"}]}"#,
            "both raw entries and compression overlay",
        ),
    ] {
        let value = serde_json::from_str(json).expect(label);
        let err = parse_compressed_map_values_json(9001, &metadata, value).unwrap_err();
        let message = format!("{err:#}");
        assert!(
            message.contains(expected),
            "{label}: expected {expected:?}, got {message}"
        );
    }
}

#[test]
fn map_values_overlay_rejects_raw_entries_and_compression_for_same_map() {
    let dir = temp_map_values_dir("raw-plus-compression");
    remove_dir_if_exists(&dir);
    fs::create_dir(&dir).expect("create map values dir");
    write_map_show(&dir, 9101, "array", 4);
    fs::write(
        dir.join("map-9101.dump.json"),
        r#"[{"key":["0x01","0x00","0x00","0x00"],"value":["0x07","0x00","0x00","0x00"]}]"#,
    )
    .expect("write raw dump");
    fs::write(
        dir.join("overlays.json"),
        r#"{"9101":{"compression":"uniform","value_size":4,"value_hex":"01000000"}}"#,
    )
    .expect("write overlay");

    let err = match read_map_values(&dir, &[9101]) {
        Ok(_) => panic!("raw entries plus compression overlay should fail"),
        Err(err) => err,
    };
    let message = format!("{err:#}");
    remove_dir_if_exists(&dir);
    assert!(
        message.contains("map 9101 has both raw entries and compression overlay"),
        "{message}"
    );
}

#[test]
fn map_values_reads_inner_map_id_supplement() {
    let dir = temp_map_values_dir("inner-map-id-supplement");
    remove_dir_if_exists(&dir);
    fs::create_dir(&dir).expect("create map values dir");
    write_map_show(&dir, 9102, "array_of_maps", 4);
    fs::write(
        dir.join("map-9102.dump.json"),
        r#"[{"key":["0x00","0x00","0x00","0x00"],"value":["0x00","0x00","0x00","0x00"]}]"#,
    )
    .expect("write raw dump");
    fs::write(
        dir.join("map-9102.inner_map_ids.json"),
        r#"{"9102":{"00000000":"9202"}}"#,
    )
    .expect("write inner map id supplement");

    let snapshot = read_map_values(&dir, &[9102]).expect("read map values");
    remove_dir_if_exists(&dir);

    assert_eq!(
        snapshot
            .inner_map_ids
            .get(&(9102, 0u32.to_le_bytes().to_vec()))
            .copied(),
        Some(9202)
    );
}

#[test]
fn map_values_treats_empty_lpm_trie_dump_as_enumerated_empty() {
    let dir = temp_map_values_dir("empty-lpm-trie");
    remove_dir_if_exists(&dir);
    fs::create_dir(&dir).expect("create map values dir");
    write_map_show(&dir, 9103, "lpm_trie", 4);
    fs::write(dir.join("map-9103.dump.json"), "[]").expect("write raw dump");

    let snapshot = read_map_values(&dir, &[9103]).expect("read map values");
    remove_dir_if_exists(&dir);

    let overlay = snapshot
        .compressed_values
        .get(&9103)
        .expect("empty LPM_TRIE overlay");
    assert_eq!(overlay.value_size, 4);
    match &overlay.kind {
        CompressedMapValuesKind::Enumerated { entries } => assert!(entries.is_empty()),
        other => panic!("expected enumerated overlay, got {other:?}"),
    }
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

fn try_run_map_inline_pass_without_synthetic_verifier_states(
    program: &mut BpfProgram,
) -> anyhow::Result<PipelineResult> {
    use_mock_maps(program);
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
                    let stack = stack_snapshot_from_key(stack_off, &stack_bytes.bytes);
                    states.push(verifier_delta_state_with_stack(
                        site.call_pc,
                        HashMap::from([(2, fp_reg(i32::from(stack_off)))]),
                        stack,
                    ));
                    continue;
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

fn cfg_unreachable_pcs(insns: &[BpfInsn]) -> Vec<usize> {
    let cfg = CFGAnalysis.run(&BpfProgram::new(insns.to_vec()));
    if cfg.blocks.is_empty() || insns.is_empty() {
        return Vec::new();
    }

    let mut reachable_blocks = vec![false; cfg.blocks.len()];
    let mut worklist = vec![cfg.insn_to_block[0]];
    while let Some(block_idx) = worklist.pop() {
        if reachable_blocks[block_idx] {
            continue;
        }
        reachable_blocks[block_idx] = true;
        for &succ in &cfg.blocks[block_idx].succs {
            worklist.push(succ);
        }
    }

    (0..insns.len())
        .filter(|&pc| !reachable_blocks[cfg.insn_to_block[pc]])
        .collect()
}

#[test]
fn map_inline_consumes_hint_when_verifier_state_unavailable() {
    // Bug caught: an explicit operator hint was ignored when verifier stack state was absent.
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    install_array_map_entry(301, 8, 0, vec![42, 0, 0, 0]);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![301]);
    program.map_inline_hints.push(pc_inline_hint(
        4,
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 42)));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag == "inline_hints_consumed=1"));
}

#[test]
fn map_inline_rejects_hint_with_wrong_key_size() {
    // Bug caught: stale or malformed hint bytes were downgraded to a normal key-extraction skip.
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    install_array_map_entry(302, 8, 0, vec![42, 0, 0, 0]);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![302]);
    program
        .map_inline_hints
        .push(pc_inline_hint(4, MapInlineHintMode::Hard, vec![0, 0]));

    let err = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap_err();

    assert!(err
        .to_string()
        .contains("inline hint anchor 4 has 2 key byte(s) for map_id=302, expected 4"));
}

#[test]
fn map_inline_rejects_hint_pointing_at_non_lookup_call() {
    // Bug caught: a typo in call_pc could silently leave an operator hint unused.
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    install_array_map_entry(303, 8, 0, vec![42, 0, 0, 0]);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![303]);
    program.map_inline_hints.push(pc_inline_hint(
        2,
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));

    let err = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap_err();

    assert!(err
        .to_string()
        .contains("inline hint at pc 2 does not point to a map_lookup_elem helper call"));
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
fn find_map_in_map_chains_detects_r0_to_r1_alias() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 7),
        BpfInsn::mov64_reg(1, 0),
        st_mem(BPF_W, 10, -8, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ];
    let outer_sites = find_map_lookup_sites(&insns);

    let chains = find_map_in_map_chains(&insns, &outer_sites);
    assert_eq!(chains.len(), 1);
    assert_eq!(chains[0].outer_site.call_pc, 5);
    assert_eq!(chains[0].inner_call_pc, 11);
    assert_eq!(chains[0].outer_alias_copy_pcs, vec![7]);
    assert_eq!(chains[0].outer_null_check_pc, Some(6));
}

#[test]
fn find_map_in_map_chains_detects_stack_spilled_r0_to_r1_alias() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let insns = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 8),
        BpfInsn::stx_mem(BPF_DW, 10, 0, -16),
        BpfInsn::ldx_mem(BPF_DW, 1, 10, -16),
        st_mem(BPF_W, 10, -8, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ];
    let outer_sites = find_map_lookup_sites(&insns);

    let chains = find_map_in_map_chains(&insns, &outer_sites);
    assert_eq!(chains.len(), 1);
    assert_eq!(chains[0].outer_site.call_pc, 5);
    assert_eq!(chains[0].inner_call_pc, 12);
    assert_eq!(chains[0].outer_alias_copy_pcs, vec![7, 8]);
    assert_eq!(chains[0].outer_null_check_pc, Some(6));
}

#[test]
fn find_map_in_map_chains_ignores_absent_alias() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let inner = ld_imm64(1, BPF_PSEUDO_MAP_FD, 43);
    let insns = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        inner[0],
        inner[1],
        st_mem(BPF_W, 10, -8, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
    ];
    let outer_sites = find_map_lookup_sites(&insns);

    assert!(find_map_in_map_chains(&insns, &outer_sites).is_empty());
}

#[test]
fn map_inline_constantizes_snapshot_pseudo_map_value_sources() {
    for (label, map_id, pseudo_src, imm_lo, expected) in [
        ("pseudo map value", 901, BPF_PSEUDO_MAP_VALUE, 77, 42),
        (
            "pseudo map idx value",
            1901,
            BPF_PSEUDO_MAP_IDX_VALUE,
            0,
            99,
        ),
    ] {
        let value = vec![0, 0, 0, 0, expected, 0, 0, 0];
        let mut values = HashMap::new();
        values.insert(0u32.to_le_bytes().to_vec(), value.clone());
        install_map(map_id, 2, 1, values);

        let map_value = ld_imm64_parts(1, pseudo_src, imm_lo, 4);
        let mut program = BpfProgram::new(vec![
            map_value[0],
            map_value[1],
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![map_id]);

        let result = run_map_inline_pass(&mut program);
        assert_eq!(
            program.insns[2],
            BpfInsn::mov32_imm(2, i32::from(expected)),
            "{label}"
        );
        assert_eq!(
            result.pass_results[0].map_inline_records,
            vec![MapInlineRecord {
                map_id,
                key: 0u32.to_le_bytes().to_vec(),
                value,
            }],
            "{label}"
        );
    }
}

#[test]
fn map_inline_pseudo_map_value_feeds_const_prop_and_dce_without_branch_cleanup() {
    let mut values = HashMap::new();
    values.insert(0u32.to_le_bytes().to_vec(), vec![1, 0, 0, 0]);
    install_map(903, 2, 1, values);

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
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(2, 1),
            jeq_imm(2, 1, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
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
fn verifier_guided_key_extraction_matrix() {
    let wide_zero_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let fp_alias_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    for (label, insns, call_pc, stack_off, key_bytes, value, store_pc, check_plain) in [
        (
            "wide zero subrange",
            vec![
                BpfInsn::mov64_imm(3, 0),
                BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                wide_zero_map[0],
                wide_zero_map[1],
                call_helper(HELPER_MAP_LOOKUP_ELEM),
            ],
            6,
            -4,
            0u32.to_le_bytes().to_vec(),
            0,
            1,
            true,
        ),
        (
            "fp alias store base",
            vec![
                BpfInsn::mov64_reg(6, 10),
                add64_imm(6, -8),
                st_mem(BPF_W, 6, 4, 7),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                fp_alias_map[0],
                fp_alias_map[1],
                call_helper(HELPER_MAP_LOOKUP_ELEM),
            ],
            7,
            -4,
            7u32.to_le_bytes().to_vec(),
            7,
            2,
            false,
        ),
    ] {
        if check_plain {
            let plain = try_extract_constant_key(&insns, call_pc).unwrap();
            assert_eq!(plain.stack_off, stack_off, "{label}");
            assert_eq!(plain.width, 4, "{label}");
            assert_eq!(plain.value, value, "{label}");
            assert_eq!(plain.store_pc, store_pc, "{label}");
        }

        let states = vec![verifier_delta_state_with_stack(
            call_pc,
            HashMap::from([(2, fp_reg(i32::from(stack_off)))]),
            stack_snapshot_from_key(stack_off, &key_bytes),
        )];
        let key = try_extract_constant_key_verifier_guided(&insns, &states, call_pc, 4).unwrap();
        assert_eq!(key.stack_off, stack_off, "{label}");
        assert_eq!(key.width, 4, "{label}");
        assert_eq!(key.value, value, "{label}");
        assert_eq!(key.store_pc, store_pc, "{label}");
    }
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
fn map_inline_pass_lookup_rewrite_matrix() {
    let canonical_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let fp_alias_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    for (label, map_id, max_entries, key, value, mut program, expected) in [
        (
            "canonical scalar loads",
            101,
            8,
            1,
            vec![7, 0, 0, 0, 0xaa, 0, 0, 0],
            BpfProgram::new(vec![
                canonical_map[0],
                canonical_map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                BpfInsn::ldx_mem(BPF_B, 7, 0, 4),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]),
            vec![
                BpfInsn::mov32_imm(6, 7),
                BpfInsn::mov32_imm(7, 0xaa),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ],
        ),
        (
            "fp alias key and offset load",
            9251,
            16,
            7,
            vec![0, 0, 0, 0, 42, 0, 0, 0],
            BpfProgram::new(vec![
                BpfInsn::mov64_reg(6, 10),
                add64_imm(6, -8),
                st_mem(BPF_W, 6, 4, 7),
                fp_alias_map[0],
                fp_alias_map[1],
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::mov64_reg(6, 0),
                add64_imm(6, 4),
                BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]),
            vec![
                BpfInsn::mov64_reg(6, 10),
                add64_imm(6, -8),
                BpfInsn::mov32_imm(7, 42),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ],
        ),
    ] {
        install_array_map_entry(map_id, max_entries, key, value);
        program.set_map_ids(vec![map_id]);
        let _result = run_map_inline_pass(&mut program);
        assert_eq!(program.insns, expected, "{label}");
    }
}

#[test]
fn map_inline_pass_struct_value_wide_constant_emission_matrix() {
    let mut struct_value = vec![0u8; 16];
    struct_value[0..4].copy_from_slice(&0x1234_5678u32.to_le_bytes());
    struct_value[8..16].copy_from_slice(&0x0123_4567_89ab_cdefu64.to_le_bytes());
    let struct_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let wide_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    for (
        label,
        map_id,
        value,
        mut program,
        expected_len,
        leading_mov,
        ldimm64_pc,
        dst_reg,
        imm_lo,
        imm_hi,
    ) in [
        (
            "struct fields",
            110,
            struct_value,
            BpfProgram::new(vec![
                struct_map[0],
                struct_map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                BpfInsn::ldx_mem(BPF_DW, 7, 0, 8),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]),
            5,
            Some(BpfInsn::mov32_imm(6, 0x1234_5678i32)),
            1,
            7,
            0x89ab_cdef,
            0x0123_4567,
        ),
        (
            "wide constant",
            103,
            0x1_0000_0000u64.to_le_bytes().to_vec(),
            BpfProgram::new(vec![
                wide_map[0],
                wide_map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]),
            4,
            None,
            0,
            6,
            0,
            1,
        ),
    ] {
        install_array_map(map_id, value);
        program.set_map_ids(vec![map_id]);

        let _result = run_map_inline_pass(&mut program);
        assert_eq!(program.insns.len(), expected_len, "{label}");
        if let Some(leading_mov) = leading_mov {
            assert_eq!(program.insns[0], leading_mov, "{label}");
        }
        assert!(program.insns[ldimm64_pc].is_ldimm64(), "{label}");
        assert_eq!(program.insns[ldimm64_pc].dst_reg(), dst_reg, "{label}");
        assert_eq!(
            program.insns[ldimm64_pc].imm as u32 as u64, imm_lo,
            "{label}"
        );
        assert_eq!(
            program.insns[ldimm64_pc + 1].imm as u32 as u64,
            imm_hi,
            "{label}"
        );
    }
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

    let _result = run_map_inline_pass(&mut program);
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
    for (label, map_id, is_hash) in [("array", 102, false), ("hash", 105, true)] {
        if is_hash {
            install_hash_map(map_id, vec![7, 0, 0, 0]);
        } else {
            install_array_map(map_id, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);
        }

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
        program.set_map_ids(vec![map_id]);

        let result = run_map_inline_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 1, "{label}");
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov32_imm(6, 7),
                BpfInsn::mov64_imm(0, 0),
                exit_insn()
            ],
            "{label}"
        );
    }
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

    let _result = run_map_inline_pass(&mut program);
    assert!(program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(program.insns.contains(&jeq_imm(0, 0, 5)));
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
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
    assert_eq!(program.insns, original);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("key extraction failed")));
}

#[test]
fn map_inline_soft_map_name_hint_emits_key_check_scalar_fold_without_fallback() {
    let map_id = 9601;
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(map_id, 1, 8, values.clone());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::stx_mem(BPF_W, 10, 3, -4),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![map_id]);
    program.map_metadata.insert(
        map_id,
        MapMetadata {
            map_type: kernel_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id,
            name: "vip_map".to_string(),
        },
    );
    install_snapshot_values(&mut program, map_id, &values);
    program.map_inline_hints.push(map_name_inline_hint(
        "vip_map",
        MapInlineHintMode::Soft,
        1u32.to_le_bytes().to_vec(),
    ));

    let result = run_map_inline_pass(&mut program);

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(result.pass_results[0].map_inline_records.len(), 1);
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(!program.insns.contains(&BpfInsn::mov64_reg(0, 10)));
    assert!(!program.insns.contains(&map[0]));
    assert!(program.insns.contains(&BpfInsn::ldx_mem(BPF_W, 3, 2, 0)));
    assert!(program.insns.contains(&BpfInsn::mov32_imm(4, 1)));
    assert!(program.insns.iter().any(|insn| {
        insn.class() == BPF_JMP
            && bpf_op(insn.code) == BPF_JNE
            && bpf_src(insn.code) == BPF_X
            && insn.dst_reg() == 3
            && insn.src_reg() == 4
    }));
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
    assert!(program
        .insns
        .windows(2)
        .any(|window| window[0] == BpfInsn::mov64_imm(0, 0) && window[1].is_ja()));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("soft-fold hints=1")));
}

#[test]
fn map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists() {
    let hard_map_id = 9611;
    let soft_map_id = 9612;

    let mut hard_values = HashMap::new();
    hard_values.insert(0u32.to_le_bytes().to_vec(), 42u32.to_le_bytes().to_vec());
    install_map(
        hard_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        8,
        hard_values.clone(),
    );

    let mut soft_values = HashMap::new();
    soft_values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(
        soft_map_id,
        kernel_sys::BPF_MAP_TYPE_HASH,
        8,
        soft_values.clone(),
    );

    let hard_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let soft_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 43);
    let mut program = BpfProgram::new(vec![
        hard_map[0],
        hard_map[1],
        st_mem(BPF_W, 10, -4, 0),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        soft_map[0],
        soft_map[1],
        st_mem(BPF_W, 10, -8, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_imm(8, 2),
        BpfInsn::mov64_imm(1, 7),
        jeq_imm(0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, 7, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![hard_map_id, soft_map_id]);
    install_named_map_metadata(
        &mut program,
        hard_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        4,
        8,
        "hard_map",
    );
    install_named_map_metadata(
        &mut program,
        soft_map_id,
        kernel_sys::BPF_MAP_TYPE_HASH,
        4,
        8,
        "soft_map",
    );
    install_snapshot_values(&mut program, hard_map_id, &hard_values);
    install_snapshot_values(&mut program, soft_map_id, &soft_values);
    program.map_inline_hints.push(map_name_inline_hint(
        "hard_map",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "soft_map",
        MapInlineHintMode::Soft,
        1u32.to_le_bytes().to_vec(),
    ));

    let result = run_map_inline_pass(&mut program);

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 42)));
    assert!(program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("soft fold not applicable: missing null handler")));
    let unreachable = cfg_unreachable_pcs(&program.insns);
    assert!(
        unreachable.is_empty(),
        "map_inline emitted CFG-unreachable instruction(s): {unreachable:?}"
    );
}

#[test]
fn map_inline_lpm_trie_enumerated_empty_hard_hint_folds_lookup_to_null() {
    let map_id = 9621;
    install_mock_map(
        map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_LPM_TRIE,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 0),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![map_id]);
    install_named_map_metadata(
        &mut program,
        map_id,
        BPF_MAP_TYPE_LPM_TRIE,
        4,
        8,
        "lpm_src_v4",
    );
    program.map_value_overlays.insert(
        map_id,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Enumerated {
                entries: HashMap::new(),
            },
        },
    );
    program.map_inline_hints.push(map_name_inline_hint(
        "lpm_src_v4",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));

    let result = run_map_inline_const_prop_dce(&mut program);

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 0), exit_insn()]);
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("NULL map_id=9621 key=0x00000000")));
}

#[test]
fn map_inline_skips_kernel_mutable_map() {
    let map_id = 9603;
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(map_id, 1, 8, values.clone());

    let map_update = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map_update[0],
        map_update[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        BpfInsn::mov64_reg(3, 10),
        add64_imm(3, -8),
        call_helper(HELPER_MAP_UPDATE_ELEM),
        map[0],
        map[1],
        BpfInsn::stx_mem(BPF_W, 10, 3, -4),
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
    install_snapshot_values(&mut program, map_id, &values);

    let result = run_map_inline_pass(&mut program);

    assert_eq!(program.insns, original);
    assert_eq!(result.pass_results[0].sites_applied, 0);
    assert!(result.pass_results[0].diagnostics.iter().any(|diag| {
        diag.contains(
            "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id=9603",
        )
    }));
}

#[test]
fn map_inline_does_not_abort_on_runtime_map_pointer_writer() {
    let dynamic_map_id = 9702;
    let inline_map_id = 9703;
    install_map(
        dynamic_map_id,
        kernel_sys::BPF_MAP_TYPE_PROG_ARRAY,
        1,
        HashMap::new(),
    );
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(inline_map_id, 1, 8, values.clone());

    let dynamic_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 41);
    let inline_map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        dynamic_map[0],
        dynamic_map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::stx_mem(BPF_DW, 10, 0, -8),
        BpfInsn::ldx_mem(BPF_DW, 1, 10, -8),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        BpfInsn::mov64_reg(3, 10),
        add64_imm(3, -16),
        BpfInsn::mov64_imm(4, 0),
        call_helper(HELPER_MAP_UPDATE_ELEM),
        inline_map[0],
        inline_map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original);
    program.set_map_ids(vec![dynamic_map_id, inline_map_id]);
    install_snapshot_values(&mut program, inline_map_id, &values);

    let result = run_map_inline_pass(&mut program);

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
    assert!(result.pass_results[0].diagnostics.iter().all(|diag| {
        !diag.contains(&format!("map_id={inline_map_id}")) || !diag.contains("map kernel-mutable")
    }));
}

#[test]
fn map_inline_pass_skips_pseudo_map_value_lookup_key_without_verifier_state() {
    let key_bytes = (0u8..20).collect::<Vec<_>>();
    install_array_map_entry(9401, 1, 0, key_bytes.clone());

    let mut values = HashMap::new();
    values.insert(key_bytes.clone(), 42u32.to_le_bytes().to_vec());
    install_map_with_key_size(9402, 1, 20, 16, values);

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
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag.contains("no verifier states available")));
}

#[test]
fn map_inline_pass_uses_stack_snapshot_key_size_matrix() {
    let lo = 0x0706_0504_0302_0100u64;
    let hi = 0x0f0e_0d0c_0b0a_0908u64;
    let mut key16 = lo.to_le_bytes().to_vec();
    key16.extend_from_slice(&hi.to_le_bytes());
    let key256 = (0u8..=255).collect::<Vec<_>>();
    let mut key20 = vec![0u8; 20];
    key20[16..20].copy_from_slice(&1u32.to_le_bytes());

    let map16 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let key_lo = emit_ldimm64(3, lo);
    let key_hi = emit_ldimm64(4, hi);
    let map256 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let map20 = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let map_zero = ld_imm64(1, BPF_PSEUDO_MAP_FD, 123);

    for (
        label,
        map_id,
        map_type,
        key_size,
        max_entries,
        key_bytes,
        value,
        mut program,
        verifier_states,
    ) in [
        (
            "16-byte key",
            9302,
            1,
            16,
            8,
            key16,
            42u32,
            BpfProgram::new(vec![
                map16[0],
                map16[1],
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
            ]),
            vec![],
        ),
        (
            "256-byte key",
            9320,
            2,
            256,
            1,
            key256.clone(),
            99u32,
            BpfProgram::new(vec![
                map256[0],
                map256[1],
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -256),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                exit_insn(),
            ]),
            vec![verifier_delta_state_with_stack(
                4,
                HashMap::from([(2, fp_reg(-256))]),
                stack_snapshot_from_key(-256, &key256),
            )],
        ),
        (
            "20-byte key",
            9310,
            1,
            20,
            8,
            key20,
            7u32,
            BpfProgram::new(vec![
                map20[0],
                map20[1],
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
            ]),
            vec![],
        ),
        (
            "verifier-guided wide zero",
            7001,
            2,
            4,
            8,
            0u32.to_le_bytes().to_vec(),
            42u32,
            BpfProgram::new(vec![
                BpfInsn::mov64_imm(3, 0),
                BpfInsn::stx_mem(BPF_DW, 10, 3, -8),
                BpfInsn::mov64_reg(2, 10),
                add64_imm(2, -4),
                map_zero[0],
                map_zero[1],
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jeq_imm(0, 0, 2),
                BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
                exit_insn(),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]),
            vec![verifier_delta_state_with_stack(
                6,
                HashMap::from([(2, fp_reg(-4))]),
                stack_snapshot_from_key(-4, &0u32.to_le_bytes()),
            )],
        ),
    ] {
        let mut values = HashMap::new();
        values.insert(key_bytes.clone(), value.to_le_bytes().to_vec());
        install_map_with_key_size(map_id, map_type, key_size, max_entries, values);
        program.set_map_ids(vec![map_id]);
        if !verifier_states.is_empty() {
            program.set_verifier_states(verifier_states);
        }

        let result = run_map_inline_pass(&mut program);
        assert_eq!(result.pass_results[0].sites_applied, 1, "{label}");
        assert!(
            program.insns.contains(&BpfInsn::mov32_imm(6, value as i32)),
            "{label}"
        );
        assert_eq!(
            result.pass_results[0].map_inline_records[0].key, key_bytes,
            "{label}"
        );
    }
}

#[test]
fn map_inline_pass_uses_full_state_stack_snapshot_for_key() {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 42u32.to_le_bytes().to_vec());
    install_map(9323, 2, 8, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![9323]);
    program.set_verifier_states(vec![
        verifier_delta_state(0, HashMap::from([(0, scalar_reg(0))])),
        verifier_full_state_with_stack(
            4,
            HashMap::from([(2, fp_reg(-4))]),
            stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
        ),
    ]);

    let result = run_map_inline_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 42)));
    assert_eq!(
        result.pass_results[0].map_inline_records[0].key,
        1u32.to_le_bytes().to_vec()
    );
}

#[test]
fn map_inline_pass_reports_unavailable_when_call_stack_snapshot_is_absent() {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(9321, 2, 8, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![9321]);
    program.set_verifier_states(vec![verifier_delta_state(
        4,
        HashMap::from([(2, fp_reg(-4))]),
    )]);

    let result = run_map_inline_pass(&mut program);
    assert_eq!(program.insns, original);
    assert!(has_non_constant_key_skip(&result));
    assert!(result.pass_results[0].diagnostics.iter().any(|diag| {
        diag.contains("did not expose constant stack bytes covering fp-4 width 4")
    }));
}

#[test]
fn map_inline_pass_requires_explicit_precise_stack_scalar() {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(9322, 2, 8, values);

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ];
    let mut stack = HashMap::new();
    stack.insert(
        -8,
        StackState {
            slot_types: Some("rrrrrrrr".to_string()),
            value: Some(imprecise_scalar_reg(u64::from_le_bytes([
                0, 0, 0, 0, 1, 0, 0, 0,
            ]))),
        },
    );
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![9322]);
    program.set_verifier_states(vec![verifier_delta_state_with_stack(
        4,
        HashMap::from([(2, fp_reg(-4))]),
        stack,
    )]);

    let result = run_map_inline_pass(&mut program);
    assert_eq!(program.insns, original);
    assert!(has_non_constant_key_skip(&result));
}

#[test]
fn map_inline_pass_rewrites_map_in_map_chain_loads() {
    let outer_map_id = 9501;
    let inner_map_id = 9502;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_HASH_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_array_map_entry(inner_map_id, 8, 2, 77u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 8),
        BpfInsn::mov64_reg(1, 0),
        st_mem(BPF_W, 10, -8, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![outer_map_id]);
    program
        .map_inner_map_ids
        .insert((outer_map_id, 1u32.to_le_bytes().to_vec()), inner_map_id);
    program.set_verifier_states(vec![
        verifier_delta_state_with_stack(
            5,
            HashMap::from([(2, fp_reg(-4))]),
            stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
        ),
        verifier_delta_state_with_stack(
            11,
            HashMap::from([(2, fp_reg(-8))]),
            stack_snapshot_from_key(-8, &2u32.to_le_bytes()),
        ),
    ]);

    let result = run_map_inline_pass(&mut program);
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 77)));
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert_eq!(
        result.pass_results[0].map_inline_records[0].map_id,
        inner_map_id
    );
    assert_eq!(
        result.pass_results[0].map_inline_records[0].key,
        2u32.to_le_bytes().to_vec()
    );
}

fn map_in_map_route_program(outer_map_id: u32, outer_key: u32, inner_key: u32) -> BpfProgram {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, outer_key as i32),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 8),
        BpfInsn::mov64_reg(1, 0),
        st_mem(BPF_W, 10, -8, inner_key as i32),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![outer_map_id]);
    program
}

fn has_map_ptr_load_to_r0(insns: &[BpfInsn], map_id: u32) -> bool {
    insns.windows(2).any(|window| {
        window[0].is_ldimm64()
            && window[0].dst_reg() == 0
            && window[0].src_reg() == BPF_PSEUDO_MAP_FD
            && window[0].imm == 0
            && window[1].imm == map_id as i32
    })
}

#[test]
fn map_inline_outer_only_array_of_maps_hard_hint_replaces_outer_lookup_only() {
    let outer_map_id = 9571;
    let inner_map_id = 9572;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_ARRAY_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_map(inner_map_id, BPF_MAP_TYPE_LRU_HASH, 8, HashMap::new());

    let mut program = map_in_map_route_program(outer_map_id, 0, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        4,
        8,
        "outer_array_only",
    );
    program
        .map_inner_map_ids
        .insert((outer_map_id, 0u32.to_le_bytes().to_vec()), inner_map_id);
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_array_only",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(has_map_ptr_load_to_r0(&program.insns, inner_map_id));
    assert_eq!(
        program
            .insns
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)
            .count(),
        1
    );
    assert!(
        program.insns.iter().any(|insn| is_direct_r0_null_jeq(insn)),
        "outer NULL check must stay in bytecode for verifier-visible control flow"
    );
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag == "inline_hints_consumed=1"));
}

#[test]
fn map_inline_outer_only_hash_of_maps_hard_hint_uses_outer_overlay() {
    let outer_map_id = 9573;
    let inner_map_id = 9574;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_HASH_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_map(inner_map_id, BPF_MAP_TYPE_LRU_HASH, 8, HashMap::new());

    let mut program = map_in_map_route_program(outer_map_id, 3, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_HASH_OF_MAPS,
        4,
        8,
        "outer_hash_only",
    );
    program.map_value_overlays.insert(
        outer_map_id,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Enumerated {
                entries: HashMap::from([(
                    3u32.to_le_bytes().to_vec(),
                    inner_map_id.to_le_bytes().to_vec(),
                )]),
            },
        },
    );
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_hash_only",
        MapInlineHintMode::Hard,
        3u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(has_map_ptr_load_to_r0(&program.insns, inner_map_id));
    assert_eq!(
        program
            .insns
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM)
            .count(),
        1
    );
    assert!(!program.insns.contains(&BpfInsn::mov32_imm(6, 0)));
}

#[test]
fn map_inline_route_a_array_of_maps_hard_hints_fold_outer_and_inner() {
    let outer_map_id = 9521;
    let inner_map_id = 9522;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_ARRAY_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_array_map_entry(inner_map_id, 8, 1, 123u32.to_le_bytes().to_vec());

    let mut program = map_in_map_route_program(outer_map_id, 0, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        4,
        8,
        "outer_array",
    );
    install_named_map_metadata(
        &mut program,
        inner_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        4,
        8,
        "inner_array",
    );
    program
        .map_inner_map_ids
        .insert((outer_map_id, 0u32.to_le_bytes().to_vec()), inner_map_id);
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_array",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "inner_array",
        MapInlineHintMode::Hard,
        1u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 123)));
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag == "inline_hints_consumed=2"));
}

#[test]
fn map_inline_route_a_hash_of_maps_uses_outer_overlay_and_inner_hard_hint() {
    let outer_map_id = 9531;
    let inner_map_id = 9532;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_HASH_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_array_map_entry(inner_map_id, 8, 2, 77u32.to_le_bytes().to_vec());

    let mut program = map_in_map_route_program(outer_map_id, 3, 2);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_HASH_OF_MAPS,
        4,
        8,
        "outer_hash",
    );
    install_named_map_metadata(
        &mut program,
        inner_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        4,
        8,
        "inner_array_overlay",
    );
    program.map_value_overlays.insert(
        outer_map_id,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Enumerated {
                entries: HashMap::from([(
                    3u32.to_le_bytes().to_vec(),
                    inner_map_id.to_le_bytes().to_vec(),
                )]),
            },
        },
    );
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_hash",
        MapInlineHintMode::Hard,
        3u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "inner_array_overlay",
        MapInlineHintMode::Hard,
        2u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 77)));
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
}

#[test]
fn map_inline_hash_hard_hint_without_inner_hint_uses_normal_fold() {
    let hash_map_id = 9541;
    let metadata_only_map_id = 9542;
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), 7u32.to_le_bytes().to_vec());
    install_map(
        hash_map_id,
        kernel_sys::BPF_MAP_TYPE_HASH,
        8,
        values.clone(),
    );

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 1),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![hash_map_id]);
    install_named_map_metadata(
        &mut program,
        hash_map_id,
        kernel_sys::BPF_MAP_TYPE_HASH,
        4,
        8,
        "vip_map",
    );
    install_named_map_metadata(
        &mut program,
        metadata_only_map_id,
        BPF_MAP_TYPE_LPM_TRIE,
        4,
        8,
        "lpm_src_v4",
    );
    install_snapshot_values(&mut program, hash_map_id, &values);
    program.map_inline_hints.push(map_name_inline_hint(
        "vip_map",
        MapInlineHintMode::Hard,
        1u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "lpm_src_v4",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));

    let result = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap();

    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag == "inline_hints_consumed=1"));
}

#[test]
fn map_inline_route_a_rejects_missing_outer_entry_for_hint() {
    let outer_map_id = 9545;
    let inner_map_id = 9546;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_ARRAY_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_array_map_entry(inner_map_id, 8, 1, 9u32.to_le_bytes().to_vec());

    let mut program = map_in_map_route_program(outer_map_id, 0, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        4,
        8,
        "outer_missing",
    );
    install_named_map_metadata(
        &mut program,
        inner_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        4,
        8,
        "inner_after_missing",
    );
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_missing",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "inner_after_missing",
        MapInlineHintMode::Hard,
        1u32.to_le_bytes().to_vec(),
    ));

    let err = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap_err();

    assert!(err.to_string().contains("has no live inner map"));
}

#[test]
fn map_inline_route_a_rejects_kernel_mutable_inner_hint() {
    let outer_map_id = 9551;
    let inner_map_id = 9552;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_ARRAY_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_map(inner_map_id, BPF_MAP_TYPE_LRU_HASH, 8, HashMap::new());

    let mut program = map_in_map_route_program(outer_map_id, 0, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        4,
        8,
        "outer_array_lru",
    );
    install_named_map_metadata(
        &mut program,
        inner_map_id,
        BPF_MAP_TYPE_LRU_HASH,
        4,
        8,
        "inner_lru",
    );
    program
        .map_inner_map_ids
        .insert((outer_map_id, 0u32.to_le_bytes().to_vec()), inner_map_id);
    program.map_inline_hints.push(map_name_inline_hint(
        "outer_array_lru",
        MapInlineHintMode::Hard,
        0u32.to_le_bytes().to_vec(),
    ));
    program.map_inline_hints.push(map_name_inline_hint(
        "inner_lru",
        MapInlineHintMode::Hard,
        1u32.to_le_bytes().to_vec(),
    ));

    let err = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap_err();

    assert!(err.to_string().contains("kernel-mutable"));
}

#[test]
fn map_inline_route_a_rejects_orphan_inner_hint() {
    let outer_map_id = 9561;
    let inner_map_id = 9562;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_ARRAY_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );
    install_array_map_entry(inner_map_id, 8, 1, 9u32.to_le_bytes().to_vec());

    let mut program = map_in_map_route_program(outer_map_id, 0, 1);
    install_named_map_metadata(
        &mut program,
        outer_map_id,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        4,
        8,
        "outer_without_hint",
    );
    install_named_map_metadata(
        &mut program,
        inner_map_id,
        kernel_sys::BPF_MAP_TYPE_ARRAY,
        4,
        8,
        "orphan_inner",
    );
    program
        .map_inner_map_ids
        .insert((outer_map_id, 0u32.to_le_bytes().to_vec()), inner_map_id);
    program.map_inline_hints.push(map_name_inline_hint(
        "orphan_inner",
        MapInlineHintMode::Hard,
        1u32.to_le_bytes().to_vec(),
    ));

    let err = try_run_map_inline_pass_without_synthetic_verifier_states(&mut program).unwrap_err();

    assert!(err
        .to_string()
        .contains("has no matching map-in-map outer hint"));
}

#[test]
fn map_inline_pass_skips_missing_outer_map_in_map_entry() {
    let outer_map_id = 9511;
    install_mock_map(
        outer_map_id,
        MockMapState {
            info: BpfMapInfo {
                map_type: BPF_MAP_TYPE_HASH_OF_MAPS,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            values: HashMap::new(),
        },
    );

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 7),
        BpfInsn::mov64_reg(1, 0),
        st_mem(BPF_W, 10, -8, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -8),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![outer_map_id]);

    let result = run_map_inline_pass(&mut program);
    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .sites_skipped
        .iter()
        .any(|skip| { skip.reason.contains("has no live inner map") }));
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

    let _result = run_map_inline_pass(&mut program);
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
        call_helper(HELPER_KTIME_GET_NS),
        BpfInsn::mov64_imm(0, 0),
        ja(1),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);
    program.set_map_ids(vec![1061]);

    let _result = run_map_inline_pass(&mut program);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(6, 7),
            BpfInsn::mov64_reg(1, 6),
            call_helper(HELPER_KTIME_GET_NS),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    );
}

#[test]
fn map_inline_pass_does_not_use_non_verifier_fixpoint_fallback() {
    install_array_map(9203, 2u32.to_le_bytes().to_vec());
    install_array_map_entry(9204, 8, 2, 11u32.to_le_bytes().to_vec());

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

    let _result = run_map_inline_pass(&mut program);
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

    let _result = run_map_inline_pass(&mut program);
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
fn map_inline_pass_inlines_mutable_array_across_readonly_helper_call() {
    install_array_map(411, vec![7, 0, 0, 0]);

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

    let _result = run_map_inline_pass(&mut program);
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
fn map_inline_pass_skips_size_skipped_array_map() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let original = vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ];
    let mut program = BpfProgram::new(original.clone());
    program.set_map_ids(vec![312]);
    program.map_metadata.insert(
        312,
        MapMetadata {
            map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 8,
            max_entries: 8,
            map_id: 312,
            name: "oversized".to_string(),
        },
    );
    program.map_snapshots_skipped_by_size.insert(312);

    let result = try_run_map_inline_pass(&mut program).unwrap();

    assert_eq!(program.insns, original);
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .any(|diag| diag == "maps_skipped_by_size=1"));
    assert!(result.pass_results[0].sites_skipped.iter().any(|skip| {
        skip.pc == 5
            && skip.reason
                == "map snapshot skipped by size and no overlay provided (map_name=oversized, map_id=312)"
    }));
    assert!(result.pass_results[0].diagnostics.iter().any(|diag| {
        diag == "site at PC=5: skip reason: map snapshot skipped by size and no overlay provided (map_name=oversized, map_id=312)"
    }));
}

#[test]
fn map_inline_pass_uses_overlay_for_size_skipped_array_map() {
    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = BpfProgram::new(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 2),
        BpfInsn::mov64_reg(2, 10),
        add64_imm(2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![313]);
    program.map_metadata.insert(
        313,
        MapMetadata {
            map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 8,
            max_entries: 8,
            map_id: 313,
            name: "oversized_with_overlay".to_string(),
        },
    );
    program.map_snapshots_skipped_by_size.insert(313);
    program.map_value_overlays.insert(
        313,
        CompressedMapValues {
            value_size: 8,
            kind: CompressedMapValuesKind::Uniform(vec![7, 0, 0, 0, 0, 0, 0, 0]),
        },
    );

    let result = try_run_map_inline_pass(&mut program).unwrap();

    assert!(program.insns.contains(&BpfInsn::mov32_imm(6, 7)));
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert!(result.pass_results[0]
        .diagnostics
        .iter()
        .all(|diag| { !diag.contains("map snapshot skipped by size and no overlay provided") }));
}

#[test]
fn map_inline_pass_inlines_uniform_percpu_array_maps() {
    let blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), blob.clone());
    install_percpu_array_map(112, 4, 8, values);

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
    assert!(!program
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == HELPER_MAP_LOOKUP_ELEM));
    assert!(program
        .insns
        .iter()
        .any(|insn| insn == &BpfInsn::mov32_imm(6, 7)));
    assert_eq!(result.pass_results[0].map_inline_records[0].map_id, 112);
}

#[test]
fn map_inline_pass_snapshot_missing_error_matrix() {
    for (label, map_id, key_hex) in [("percpu array default", 916, "01000000")] {
        install_percpu_array_map(map_id, 4, 8, HashMap::new());

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
        program.set_map_ids(vec![map_id]);

        let err = try_run_map_inline_pass(&mut program).unwrap_err();
        let message = format!("{err:#}");
        assert!(
            message.contains("map_inline requires a concrete snapshot value"),
            "{label}"
        );
        assert!(
            message.contains(&format!(
                "map_values snapshot missing map {map_id} key {key_hex}"
            )),
            "{label}: {message}"
        );
    }
}

#[test]
fn map_inline_pass_skips_mixed_percpu_array_maps() {
    let mut blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
    blob[8..12].copy_from_slice(&9u32.to_le_bytes());
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), blob);
    install_percpu_array_map(212, 4, 8, values);

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
        install_map(map_id, map_type, 8, values);

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
        assert_eq!(program.insns, original);
        let expected_reason = if map_type == BPF_MAP_TYPE_LRU_PERCPU_HASH {
            "LRU map lookup mutates access order"
        } else {
            "not inlineable"
        };
        assert!(
            result.pass_results[0]
                .sites_skipped
                .iter()
                .any(|skip| skip.reason.contains(expected_reason)),
            "map type {map_type} should be rejected with {expected_reason}: {:?}",
            result.pass_results[0].sites_skipped
        );
    }
}
