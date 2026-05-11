// SPDX-License-Identifier: MIT

use super::*;
use crate::insn::*;
use crate::test_helpers::*;
use std::collections::BTreeSet;

#[test]
fn pass_registry_declares_every_default_cli_pass() {
    let names = PASS_REGISTRY
        .iter()
        .map(|entry| entry.name)
        .collect::<Vec<_>>();

    assert_eq!(
        names,
        vec![
            "noop",
            "map_inline",
            "const_prop",
            "dce",
            "skb_load_bytes_spec",
            "bounds_check_merge",
            "wide_mem",
            "bulk_memory",
            "rotate",
            "cond_select",
            "ccmp",
            "extract",
            "endian_fusion",
            "branch_flip",
            "prefetch",
        ]
    );
}

#[test]
fn pass_registry_declares_all_emitted_kinsn_probe_names() {
    let mut names = BTreeSet::new();
    for entry in PASS_REGISTRY {
        for target in entry.metadata.kinsn_targets {
            names.insert(target.canonical_name);
            names.extend(target.probe_aliases());
        }
    }

    assert!(names.contains("bpf_rotate64"));
    assert!(names.contains("bpf_rotate32"));
    assert!(names.contains("bpf_select64"));
    assert!(names.contains("bpf_ccmp64"));
    assert!(names.contains("bpf_extract64"));
    assert!(names.contains("bpf_endian_load16"));
    assert!(names.contains("bpf_endian_load32"));
    assert!(names.contains("bpf_endian_load64"));
    assert!(names.contains("bpf_bulk_memcpy"));
    assert!(names.contains("bpf_bulk_memset"));
    assert!(names.contains("bpf_prefetch"));
}

#[test]
fn map_inline_const_prop_dce_cascade_uses_one_bbprogram_pipeline() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 1),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_1, 1),
        BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_1),
        BpfInsn::exit(),
    ];
    let ctx = ctx_with_verifier_states(vec![verifier_delta_state(
        1,
        std::collections::HashMap::from([(BPF_REG_1, scalar_reg(2))]),
    )]);

    let (results, lowered, _) = run_pipeline_on_insns(
        vec![Box::new(ConstPropPass), Box::new(DcePass)],
        input,
        &ctx,
    );

    assert_eq!(results.len(), 2);
    assert!(lowered.contains(&BpfInsn::mov64_imm(BPF_REG_1, 2)));
}

#[test]
fn custom_pipeline_rejects_unknown_pass_names_without_running() {
    let requested = ["const_prop".to_string(), "definitely_missing".to_string()];

    // IMPL: needs BBProgram-native pipeline resolver for custom pass lists.
    let err = build_custom_bbprogram_pipeline(&requested).unwrap_err();

    assert!(err.to_string().contains("unknown pass name"));
}
