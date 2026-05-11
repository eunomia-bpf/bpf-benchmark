// SPDX-License-Identifier: MIT

use super::map_inline::{MapInlineHint, MapInlineHintAnchor, MapInlineHintMode, MapInlinePass};
use super::{ConstPropPass, DcePass};
use crate::insn::*;
use crate::pass::{CompressedMapValues, CompressedMapValuesKind, MapMetadata, PassContext};
use crate::test_helpers::*;
use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};

const LOOKUP: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const UPDATE: i32 = libbpf_sys::BPF_FUNC_map_update_elem as i32;

fn lookup_program(old_fd: i32) -> Vec<BpfInsn> {
    let map = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, i64::from(old_fd));
    vec![
        map[0],
        map[1],
        BpfInsn::st_mem(BPF_W, BPF_REG_10, -4, 1),
        BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_2, -4),
        BpfInsn::helper_call(LOOKUP),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_0, 0),
        BpfInsn::exit(),
    ]
}

fn ctx_for_array_lookup(map_id: u32, value: Vec<u8>) -> PassContext {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![map_id]);
    ctx.map_metadata.insert(
        map_id,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id,
            name: format!("array_{map_id}"),
        },
    );
    ctx.map_values
        .insert((map_id, 1u32.to_le_bytes().to_vec()), value);
    ctx
}

fn temp_map_values_dir(name: &str) -> PathBuf {
    std::env::temp_dir().join(format!("bpfopt-map-inline-{name}-{}", std::process::id()))
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
            r#"{{"id":{map_id},"name":"map_{map_id}","type":"{map_type}","bytes_key":4,"bytes_value":{value_size},"max_entries":8}}"#
        ),
    )
    .expect("write map show");
}

fn map_inline_cli_error(dir: &Path, map_id: u32) -> String {
    let args = vec![
        "--map-values".to_string(),
        dir.display().to_string(),
        "--map-ids".to_string(),
        map_id.to_string(),
    ];
    match MapInlinePass::from_cli_args(&args) {
        Ok(_) => panic!("invalid map_values fixture should fail"),
        Err(err) => err.to_string(),
    }
}

fn make_percpu_blob(slot_value: &[u8], slots: usize) -> Vec<u8> {
    let stride = (slot_value.len() + 7) & !7;
    let mut blob = vec![0u8; stride * slots];
    for slot in 0..slots {
        let offset = slot * stride;
        blob[offset..offset + slot_value.len()].copy_from_slice(slot_value);
    }
    blob
}

#[test]
fn compressed_overlay_schema_validation_fail_fast() {
    // Restored from HEAD: malformed compressed map overlays must fail before
    // any benchmark run can silently proceed with missing or ambiguous values.
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
        let dir = temp_map_values_dir(label.replace(' ', "-").as_str());
        remove_dir_if_exists(&dir);
        fs::create_dir(&dir).expect("create map values dir");
        write_map_show(&dir, 9001, "array", 4);
        fs::write(dir.join("map-9001.dump.json"), "[]").expect("write empty raw dump");
        fs::write(dir.join("overlays.json"), format!(r#"{{"9001":{json}}}"#))
            .expect("write overlay");

        let message = map_inline_cli_error(&dir, 9001);

        remove_dir_if_exists(&dir);
        assert!(
            message.contains(expected),
            "{label}: expected {expected:?}, got {message}"
        );
    }
}

#[test]
fn map_values_overlay_rejects_raw_entries_and_compression_for_same_map() {
    // Restored from HEAD: a map may not provide both raw dump entries and a
    // compressed overlay, because that makes the snapshot source ambiguous.
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

    let message = map_inline_cli_error(&dir, 9101);

    remove_dir_if_exists(&dir);
    assert!(
        message.contains("map 9101 has both raw entries and compression overlay"),
        "{message}"
    );
}

#[test]
fn map_inline_consumes_hint_when_verifier_state_unavailable() {
    // P1-H: operator hard hints are real side inputs, not fallback heuristics.
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::Pc(5),
            mode: MapInlineHintMode::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        }],
    );

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 7)));
}

#[test]
fn map_inline_rejects_hint_with_wrong_key_size() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::Pc(5),
            mode: MapInlineHintMode::Hard,
            key: vec![1, 2],
        }],
    );

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("wrong key size"));
}

#[test]
fn map_inline_rejects_hint_pointing_at_non_lookup_call() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::Pc(6),
            mode: MapInlineHintMode::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        }],
    );

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("non-lookup call"));
}

#[test]
fn map_inline_pass_does_not_use_non_verifier_fixpoint_fallback() {
    // P1-H: after a rewrite invalidates verifier state, a later lookup must not
    // be folded through non-verifier fixed-point key guessing.
    let mut input = lookup_program(42);
    let second = lookup_program(42);
    input.extend_from_slice(&second[..second.len() - 1]);
    input.push(BpfInsn::exit());
    let ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());

    let run = run_pass_on_insns(MapInlinePass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(
        run.lowered
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == LOOKUP)
            .count(),
        1
    );
}

#[test]
fn map_inline_pseudo_map_value_feeds_const_prop_and_dce_without_branch_cleanup() {
    // Restored from HEAD: pseudo-map-value constantization must cascade into
    // const_prop and DCE without relying on map_inline's branch cleanup path.
    let map_value = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_VALUE, 79);
    let input = vec![
        map_value[0],
        map_value[1],
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_1, 0),
        BpfInsn::jeq_imm(BPF_REG_2, 1, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];
    let value = vec![1, 0, 0, 0];
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![903];
    ctx.map_metadata.insert(
        903,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 903,
            name: format!("array_{}", 903),
        },
    );
    ctx.map_values
        .insert((903, 0u32.to_le_bytes().to_vec()), value);

    let (results, lowered, _) = run_pipeline_on_insns(
        vec![
            Box::new(MapInlinePass),
            Box::new(ConstPropPass),
            Box::new(DcePass),
        ],
        input,
        &ctx,
    );

    assert_eq!(results.len(), 3);
    assert_eq!(
        lowered,
        vec![
            BpfInsn::mov32_imm(BPF_REG_2, 1),
            BpfInsn::jeq_imm(BPF_REG_2, 1, 0),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn map_inline_missing_snapshot_key_errors_for_array_hard_requirement() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("map_values snapshot missing map 111 key 01000000"));
}

#[test]
fn map_inline_skipped_snapshot_errors_for_hard_array_lookup() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    skip_map_snapshot(&mut ctx, 111);

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("snapshot skipped map 111"));
}

#[test]
fn map_inline_uses_compressed_uniform_overlay() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_value_overlays.insert(
        111,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Uniform(9u32.to_le_bytes().to_vec()),
        },
    );

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 9)));
}

#[test]
fn map_inline_skips_percpu_map_without_scalarizing_value() {
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("percpu_{}", 111),
        },
    );

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 5, "per-cpu");
}

#[test]
fn map_inline_pass_inlines_uniform_percpu_array_maps() {
    // Restored from HEAD: per-CPU array maps are safe to inline when every CPU
    // slot carries the same scalar value.
    let blob = make_percpu_blob(&7u32.to_le_bytes(), 2);
    let mut ctx = ctx_for_array_lookup(112, blob);
    ctx.map_metadata.insert(
        112,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 112,
            name: format!("percpu_{}", 112),
        },
    );

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(!run
        .lowered
        .iter()
        .any(|insn| insn.is_call() && insn.imm == LOOKUP));
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 7)));
    assert_eq!(run.result.map_inline_records[0].map_id, 112);
}

#[test]
fn map_inline_skips_kernel_mutable_map() {
    let mut input = lookup_program(42);
    input.insert(5, BpfInsn::helper_call(UPDATE));
    let ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());

    let run = run_pass_on_insns(MapInlinePass, input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 6, "kernel-mutable");
}

#[test]
fn map_inline_route_a_rejects_missing_outer_entry_for_hint() {
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::Pc(5),
            mode: MapInlineHintMode::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        }],
    );
    ctx.map_metadata.insert(
        111,
        crate::test_helpers::map_metadata(111, libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4),
    );

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("has no live inner map"));
}

#[test]
fn map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists() {
    // P1-H: mixed hard/soft hints must not create unreachable CFG when the soft
    // lookup lacks the required immediate null handler.
    let mut input = lookup_program(42);
    let second = lookup_program(42);
    input.extend_from_slice(&second[..second.len() - 1]);
    input.push(BpfInsn::exit());
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_metadata.insert(
        111,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    set_map_inline_hints(
        &mut ctx,
        vec![
            MapInlineHint {
                anchor: MapInlineHintAnchor::Pc(5),
                mode: MapInlineHintMode::Hard,
                key: 1u32.to_le_bytes().to_vec(),
            },
            MapInlineHint {
                anchor: MapInlineHintAnchor::Pc(13),
                mode: MapInlineHintMode::Soft,
                key: 1u32.to_le_bytes().to_vec(),
            },
        ],
    );

    let run = run_pass_on_insns(MapInlinePass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_eq!(
        run.lowered
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == LOOKUP)
            .count(),
        1
    );
    assert_diagnostic(&run.result, "missing immediate null check");
    // IMPL: BBProgram should expose unreachable block IDs after mutation for CFG sanity checks.
    assert!(run.prog.unreachable_blocks().is_empty());
}

#[test]
fn map_inline_route_a_rejects_kernel_mutable_inner_hint() {
    let mut input = lookup_program(42);
    input.insert(5, BpfInsn::helper_call(UPDATE));
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    ctx.map_metadata.insert(
        111,
        crate::test_helpers::map_metadata(111, libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4),
    );
    ctx.map_metadata.insert(
        222,
        MapMetadata {
            map_type: libbpf_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 222,
            name: format!("hash_{}", 222),
        },
    );
    add_inner_map(&mut ctx, 111, 1u32.to_le_bytes().to_vec(), 222);
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::Pc(6),
            mode: MapInlineHintMode::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        }],
    );

    let err = pass_error_on_insns(MapInlinePass, input, &ctx);

    assert!(err.contains("kernel-mutable inner map"));
}

#[test]
fn map_inline_route_a_rejects_orphan_inner_hint() {
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    add_inner_map(&mut ctx, 222, 1u32.to_le_bytes().to_vec(), 333);
    set_map_inline_hints(
        &mut ctx,
        vec![MapInlineHint {
            anchor: MapInlineHintAnchor::MapName("inner".to_string()),
            mode: MapInlineHintMode::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        }],
    );

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("no matching map-in-map outer hint"));
}
