use super::*;
use bpfopt::analysis::{
    canonicalize_map_refs_to_idx, lift_with_pass_context,
    shift_target_module_call_offsets_for_map_prefix,
};
use bpfopt::insn::{MapPseudo, BPF_DW, BPF_IMM, BPF_LD};
use bpfopt::pass::KinsnJson;

fn minimal_program_bytes() -> Vec<u8> {
    vec![
        0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00,
    ]
}

#[test]
fn parse_bytecode_rejects_non_instruction_multiple() {
    let err = parse_bytecode(&[0u8; 9]).unwrap_err().to_string();
    assert!(err.contains("multiple of 8"));
}

#[test]
fn parse_bytecode_round_trips_raw_instruction_bytes() {
    let raw = minimal_program_bytes();
    let insns = parse_bytecode(&raw).unwrap();
    let encoded = insns
        .iter()
        .flat_map(|insn| insn.raw_bytes())
        .collect::<Vec<_>>();
    assert_eq!(encoded, raw);
}

fn make_ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
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

fn pseudo_pairs(insns: &[BpfInsn]) -> Vec<(u8, i32, i32)> {
    insns
        .chunks_exact(2)
        .map(|pair| (pair[0].src_reg(), pair[0].imm, pair[1].imm))
        .collect()
}

fn kinsn_target(entries: &[(&str, i32, i16)]) -> TargetJson {
    TargetJson {
        arch: Some("x86_64".to_string()),
        features: Vec::new(),
        kinsns: entries
            .iter()
            .map(|(name, btf_func_id, call_offset)| {
                (
                    (*name).to_string(),
                    KinsnJson {
                        btf_func_id: *btf_func_id,
                        btf_id: *btf_func_id as u32,
                        call_offset: *call_offset,
                    },
                )
            })
            .collect(),
    }
}

#[test]
fn canonicalize_map_refs_rewrites_fd_pseudos_in_first_seen_order() {
    let mut insns = Vec::new();
    insns.extend(make_ld_imm64(1, MapPseudo::Fd.src_reg(), 489));
    insns.extend(make_ld_imm64(1, MapPseudo::FdValue.src_reg(), 466));
    insns.extend(make_ld_imm64(1, MapPseudo::Fd.src_reg(), 489));

    canonicalize_map_refs_to_idx(&mut insns, None, &[101, 102]).unwrap();

    assert_eq!(
        pseudo_pairs(&insns),
        vec![
            (MapPseudo::Idx.src_reg(), 0, 0),
            (MapPseudo::IdxValue.src_reg(), 1, 0),
            (MapPseudo::Idx.src_reg(), 0, 0),
        ]
    );
}

#[test]
fn canonicalize_map_refs_checks_idx_range_without_fd_array() {
    let mut insns = Vec::new();
    insns.extend(make_ld_imm64(1, MapPseudo::Idx.src_reg(), 2));

    let err = canonicalize_map_refs_to_idx(&mut insns, None, &[42]).unwrap_err();

    assert!(err.to_string().contains("out of range"), "err={err:#}");
}

#[test]
fn canonical_pass_names_accept_v3_cli_names() {
    assert_eq!(canonicalize_pass_name("wide-mem").unwrap(), "wide_mem");
    assert_eq!(canonicalize_pass_name("ccmp").unwrap(), "ccmp");
    assert_eq!(
        canonicalize_pass_name("skb-load-bytes").unwrap(),
        "skb_load_bytes_spec"
    );
    assert_eq!(canonicalize_pass_name("prefetch").unwrap(), "prefetch");
    assert!(canonicalize_pass_name("wide_mem2").is_err());
}

#[test]
fn canonical_kinsn_names_accept_all_v3_aliases() {
    for (input, expected) in [
        ("bpf_rotate64", "bpf_rotate64"),
        ("rotate64", "bpf_rotate64"),
        ("bpf_rotate32", "bpf_rotate32"),
        ("rotate32", "bpf_rotate32"),
        ("bpf_select64", "bpf_select64"),
        ("select64", "bpf_select64"),
        ("bpf_ccmp64", "bpf_ccmp64"),
        ("ccmp64", "bpf_ccmp64"),
        ("bpf_extract64", "bpf_extract64"),
        ("extract64", "bpf_extract64"),
        ("bpf_endian_load16", "bpf_endian_load16"),
        ("endian_load16", "bpf_endian_load16"),
        ("bpf_endian_load32", "bpf_endian_load32"),
        ("endian_load32", "bpf_endian_load32"),
        ("bpf_endian_load64", "bpf_endian_load64"),
        ("endian_load64", "bpf_endian_load64"),
        ("bpf_bulk_memcpy", "bpf_bulk_memcpy"),
        ("bulk_memcpy", "bpf_bulk_memcpy"),
        ("bpf_memcpy_bulk", "bpf_bulk_memcpy"),
        ("memcpy_bulk", "bpf_bulk_memcpy"),
        ("bpf_bulk_memset", "bpf_bulk_memset"),
        ("bulk_memset", "bpf_bulk_memset"),
        ("bpf_memset_bulk", "bpf_bulk_memset"),
        ("memset_bulk", "bpf_bulk_memset"),
        ("bpf_prefetch", "bpf_prefetch"),
        ("prefetch", "bpf_prefetch"),
    ] {
        assert_eq!(canonicalize_kinsn_name(input).unwrap(), expected);
    }
}

#[test]
fn target_json_maps_v3_kinsn_aliases_to_registry_fields() {
    let mut target = kinsn_target(&[
        ("rotate32", 10, 1),
        ("bpf_bulk_memcpy", 11, 2),
        ("bpf_endian_load64", 12, 0),
        ("bpf_ccmp64", 13, 0),
        ("bpf_prefetch", 14, 7),
    ]);
    target.features = vec!["cmov".to_string(), "movbe".to_string()];

    let registry = kinsn_registry_from_target(&target).unwrap();
    for (name, btf_id) in [
        ("bpf_rotate32", 10),
        ("bpf_bulk_memcpy", 11),
        ("bpf_endian_load64", 12),
        ("bpf_ccmp64", 13),
        ("bpf_prefetch", 14),
    ] {
        assert_eq!(registry.btf_id_for_target_name(name).unwrap(), btf_id);
    }
    for (name, call_off) in [
        ("bpf_rotate32", 1),
        ("bpf_bulk_memcpy", 2),
        ("bpf_prefetch", 7),
    ] {
        assert_eq!(registry.call_off_for_target_name(name).unwrap(), call_off);
    }
}

#[test]
fn target_json_disambiguates_module_local_btf_ids_by_call_offset() {
    let target = kinsn_target(&[
        ("bpf_endian_load16", 128703, 1),
        ("bpf_rotate64", 128703, 2),
    ]);
    let registry = kinsn_registry_from_target(&target).unwrap();

    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 1)
            .unwrap()
            .canonical_name,
        "bpf_endian_load16"
    );
    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 2)
            .unwrap()
            .canonical_name,
        "bpf_rotate64"
    );
}

#[test]
fn target_json_allows_shared_btf_id_when_zero_call_offset_is_first() {
    let target = kinsn_target(&[
        ("bpf_endian_load16", 128703, 0),
        ("bpf_rotate64", 128703, 2),
    ]);
    let registry = kinsn_registry_from_target(&target).unwrap();

    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 0)
            .unwrap()
            .canonical_name,
        "bpf_endian_load16"
    );
    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 2)
            .unwrap()
            .canonical_name,
        "bpf_rotate64"
    );
}

#[test]
fn target_json_rejects_ambiguous_duplicate_kinsn_call_keys() {
    let target = kinsn_target(&[
        ("bpf_endian_load16", 128703, 1),
        ("bpf_rotate64", 128703, 1),
    ]);

    let err = kinsn_registry_from_target(&target).unwrap_err();

    assert!(
        err.to_string().contains("btf_id 128703 call_off 1"),
        "err={err}"
    );
}

#[test]
fn target_json_requires_call_offset_for_each_kinsn() {
    let err = serde_json::from_str::<TargetJson>(
        r#"{
              "arch": "x86_64",
              "kinsns": {
                "bpf_extract64": { "btf_func_id": 129876 }
              }
            }"#,
    )
    .unwrap_err();

    assert!(err.to_string().contains("call_offset"), "err={err}");
}

#[test]
fn target_call_offsets_shift_after_map_prefix() {
    let mut target = TargetJson {
        arch: Some("x86_64".to_string()),
        features: Vec::new(),
        kinsns: BTreeMap::from([
            (
                "bpf_rotate64".to_string(),
                KinsnJson {
                    btf_func_id: 1,
                    btf_id: 100,
                    call_offset: 1,
                },
            ),
            (
                "bpf_extract64".to_string(),
                KinsnJson {
                    btf_func_id: 2,
                    btf_id: 200,
                    call_offset: 2,
                },
            ),
            (
                "bpf_select64".to_string(),
                KinsnJson {
                    btf_func_id: 3,
                    btf_id: 0,
                    call_offset: 0,
                },
            ),
        ]),
    };

    shift_target_module_call_offsets_for_map_prefix(&mut target, 5).unwrap();

    assert_eq!(target.kinsns["bpf_rotate64"].call_offset, 5);
    assert_eq!(target.kinsns["bpf_extract64"].call_offset, 6);
    assert_eq!(target.kinsns["bpf_select64"].call_offset, 0);
}

#[test]
fn pass_report_serializes_inlined_map_entries_as_hex() {
    let result = PassResult {
        sites_applied: 1,
        map_inline_records: vec![bpfopt::pass::MapInlineRecord {
            map_id: 7,
            key: vec![1, 0, 0, 0],
            value: vec![42, 0, 0, 0],
        }],
        insns_before: 4,
        insns_after: 2,
        ..PassResult::default()
    };

    let insns = parse_bytecode(&minimal_program_bytes()).unwrap();
    let program = lift_with_pass_context(&insns, &PassContext::try_baseline().unwrap()).unwrap();
    let report =
        serde_json::to_value(pass_report("map_inline", &program, &result).unwrap()).unwrap();

    assert_eq!(report["inlined_map_entries"][0]["map_id"], 7);
    assert_eq!(report["inlined_map_entries"][0]["key_hex"], "01000000");
    assert_eq!(report["inlined_map_entries"][0]["value_hex"], "2a000000");
}

// (verifier-log parsing tests live in bpfopt/crates/bpfopt/src/verifier_log_tests.rs,
// which has direct access to crate-internal helpers.)
