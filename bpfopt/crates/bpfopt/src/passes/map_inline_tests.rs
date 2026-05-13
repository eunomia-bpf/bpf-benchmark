// SPDX-License-Identifier: MIT

use super::map_inline::MapInlinePass;
use crate::insn::*;
use crate::pass::{CompressedMapValues, CompressedMapValuesKind, MapInfo, PassContext};
use crate::pass::{MapInlineHintAnchorSpec, MapInlineHintModeSpec, MapInlineHintSpec};
use crate::test_helpers::*;
use std::collections::HashMap;

const LOOKUP: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const UPDATE: i32 = libbpf_sys::BPF_FUNC_map_update_elem as i32;

fn lookup_program(old_fd: i32) -> Vec<BpfInsn> {
    let map = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, i64::from(old_fd));
    vec![
        map[0],
        map[1],
        BpfInsn::new(
            BPF_ST | BPF_W | BPF_MEM,
            BpfInsn::make_regs(BPF_REG_10, 0),
            -4,
            1,
        ),
        BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_2, -4),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, LOOKUP),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_0, 0),
        BpfInsn::exit(),
    ]
}

fn nullable_lookup_program(old_fd: i32) -> Vec<BpfInsn> {
    let map = BpfInsn::ld_imm64(BPF_REG_1, BPF_PSEUDO_MAP_FD, i64::from(old_fd));
    vec![
        map[0],
        map[1],
        BpfInsn::new(
            BPF_ST | BPF_W | BPF_MEM,
            BpfInsn::make_regs(BPF_REG_10, 0),
            -4,
            1,
        ),
        BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_2, -4),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, LOOKUP),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 2),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_0, 0),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(BPF_REG_6, 0),
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
    ctx.map_info.insert(
        map_id,
        MapInfo {
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

fn make_percpu_blob(slot_value: &[u8], slots: usize) -> Vec<u8> {
    let stride = (slot_value.len() + 7) & !7;
    let mut blob = vec![0u8; stride * slots];
    for slot in 0..slots {
        let offset = slot * stride;
        blob[offset..offset + slot_value.len()].copy_from_slice(slot_value);
    }
    blob
}

// (compressed overlay schema validation + raw+compression conflict are now
// enforced at the CLI/lift boundary in main.rs; tests covering those checks
// live alongside the boundary parser.)

#[test]
fn map_inline_consumes_hint_when_verifier_state_unavailable() {
    // P1-H: operator hard hints are real side inputs, not fallback heuristics.
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 7)));
}

#[test]
fn map_inline_rejects_hint_with_wrong_key_size() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Hard,
        key: vec![1, 2],
    }];

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("wrong key size"));
}

#[test]
fn map_inline_rejects_hint_pointing_at_non_lookup_call() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(6),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("non-lookup call"));
}

#[test]
fn map_inline_soft_hint_inlines_load_but_keeps_lookup_and_null_check() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
            map_type: libbpf_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("hash_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Soft,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let run = run_pass_on_insns(MapInlinePass, nullable_lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 7)));
    assert_eq!(
        run.lowered
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == LOOKUP)
            .count(),
        1
    );
    assert!(run.lowered.iter().any(|insn| insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && insn.dst_reg() == BPF_REG_0));
}

#[test]
fn map_inline_hard_hash_hint_keeps_lookup_and_null_check() {
    let value = 7u32.to_le_bytes().to_vec();
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
            map_type: libbpf_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: value.len() as u32,
            max_entries: 8,
            map_id: 111,
            name: format!("hash_{}", 111),
        },
    );
    ctx.map_values
        .insert((111, 1u32.to_le_bytes().to_vec()), value);
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let run = run_pass_on_insns(MapInlinePass, nullable_lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.contains(&BpfInsn::mov32_imm(BPF_REG_6, 7)));
    assert_eq!(
        run.lowered
            .iter()
            .filter(|insn| insn.is_call() && insn.imm == LOOKUP)
            .count(),
        1
    );
    assert!(run.lowered.iter().any(|insn| insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && insn.dst_reg() == BPF_REG_0));
}

#[test]
fn map_inline_soft_hint_skips_when_snapshot_key_is_absent() {
    let mut ctx = PassContext::baseline();
    ctx.map_ids = vec![111];
    ctx.map_info.insert(
        111,
        MapInfo {
            map_type: libbpf_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("hash_{}", 111),
        },
    );
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Soft,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let run = run_pass_on_insns(MapInlinePass, nullable_lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 5, "no live entry");
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
fn map_inline_missing_snapshot_key_errors_for_array_hard_requirement() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_info.insert(
        111,
        MapInfo {
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
fn map_inline_skipped_snapshot_records_site_skip_for_array_lookup() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_info.insert(
        111,
        MapInfo {
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 111,
            name: format!("array_{}", 111),
        },
    );
    ctx.map_snapshots_skipped_by_size.insert(111);

    let run = run_pass_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 5, "snapshot skipped by size");
}

#[test]
fn map_inline_uses_compressed_uniform_overlay() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state_with_stack(
        5,
        HashMap::from([(BPF_REG_2, fp_reg(-4))]),
        stack_snapshot_from_key(-4, &1u32.to_le_bytes()),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_info.insert(
        112,
        MapInfo {
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
    input.insert(
        5,
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, UPDATE),
    );
    let ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());

    let run = run_pass_on_insns(MapInlinePass, input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 6, "kernel-mutable");
}

#[test]
fn map_inline_route_a_rejects_missing_outer_entry_for_hint() {
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(5),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];
    ctx.map_info.insert(
        111,
        crate::test_helpers::map_info(111, libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4),
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
    ctx.map_info.insert(
        111,
        MapInfo {
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
    ctx.map_inline_hints = vec![
        MapInlineHintSpec {
            anchor: MapInlineHintAnchorSpec::Pc(5),
            mode: MapInlineHintModeSpec::Hard,
            key: 1u32.to_le_bytes().to_vec(),
        },
        MapInlineHintSpec {
            anchor: MapInlineHintAnchorSpec::Pc(13),
            mode: MapInlineHintModeSpec::Soft,
            key: 1u32.to_le_bytes().to_vec(),
        },
    ];

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
}

#[test]
fn map_inline_route_a_rejects_kernel_mutable_inner_hint() {
    let mut input = lookup_program(42);
    input.insert(
        5,
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, UPDATE),
    );
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    ctx.map_info.insert(
        111,
        crate::test_helpers::map_info(111, libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4),
    );
    ctx.map_info.insert(
        222,
        MapInfo {
            map_type: libbpf_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
            map_id: 222,
            name: format!("hash_{}", 222),
        },
    );
    ctx.map_inner_map_ids
        .insert((111, 1u32.to_le_bytes().to_vec()), 222);
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::Pc(6),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let err = pass_error_on_insns(MapInlinePass, input, &ctx);

    assert!(err.contains("kernel-mutable inner map"));
}

#[test]
fn map_inline_route_a_rejects_orphan_inner_hint() {
    let mut ctx = ctx_for_array_lookup(111, 7u32.to_le_bytes().to_vec());
    ctx.map_inner_map_ids
        .insert((222, 1u32.to_le_bytes().to_vec()), 333);
    ctx.map_inline_hints = vec![MapInlineHintSpec {
        anchor: MapInlineHintAnchorSpec::MapName("inner".to_string()),
        mode: MapInlineHintModeSpec::Hard,
        key: 1u32.to_le_bytes().to_vec(),
    }];

    let err = pass_error_on_insns(MapInlinePass, lookup_program(42), &ctx);

    assert!(err.contains("no matching map-in-map outer hint"));
}
