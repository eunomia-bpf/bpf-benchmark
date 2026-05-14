// SPDX-License-Identifier: MIT

use crate::analysis::{BlockId, DefSite, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
use crate::test_helpers::*;

#[test]
fn verifier_states_invalidated_after_program_mutation() {
    // Verifier states must not survive a bytecode mutation, or later passes
    // can apply stale per-PC verifier evidence.
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 42),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let ctx = ctx_with_verifier_states(vec![verifier_delta_state(
        0,
        std::collections::HashMap::from([(BPF_REG_1, scalar_reg(42))]),
    )]);
    let mut prog = lift_test_program(&input, &ctx);

    let any_states_attached = |prog: &ProgramCFG| {
        prog.block_ids().any(|block| {
            prog.sites_in_block_with_terminator(block)
                .expect("sites")
                .iter()
                .any(|&site| prog.verifier_states_at(site).is_some())
        })
    };
    assert!(
        any_states_attached(&prog),
        "verifier states should be lifted onto at least one site"
    );

    prog.delete_insn(DefSite {
        block: BlockId(0),
        idx: 0,
        reg: BPF_REG_1,
    })
    .expect("delete should invalidate verifier states");

    assert!(
        !any_states_attached(&prog),
        "ProgramCFG mutation must clear stale verifier states"
    );
}

#[test]
fn remap_btf_metadata_drops_deleted_entries_and_shifts_survivors() {
    // Restored from HEAD: BTF records attached to deleted instructions must be
    // dropped, while later survivors shift to their new lowered instruction PCs.
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::mov64_imm(BPF_REG_9, 9),
        BpfInsn::mov64_imm(BPF_REG_1, 1),
        BpfInsn::mov64_imm(BPF_REG_2, 2),
        BpfInsn::exit(),
    ];
    let mut ctx = pass_ctx();
    ctx.func_info = Some(crate::pass::BtfInfoRecords {
        rec_size: 8,
        bytes: [0u32.to_le_bytes(), 10u32.to_le_bytes()].concat(),
    });
    ctx.line_info = Some(crate::pass::BtfInfoRecords {
        rec_size: 16,
        bytes: [
            [
                0u32.to_le_bytes(),
                100u32.to_le_bytes(),
                0u32.to_le_bytes(),
                0u32.to_le_bytes(),
            ]
            .concat(),
            [
                1u32.to_le_bytes(),
                101u32.to_le_bytes(),
                0u32.to_le_bytes(),
                0u32.to_le_bytes(),
            ]
            .concat(),
            [
                2u32.to_le_bytes(),
                102u32.to_le_bytes(),
                0u32.to_le_bytes(),
                0u32.to_le_bytes(),
            ]
            .concat(),
            [
                3u32.to_le_bytes(),
                103u32.to_le_bytes(),
                0u32.to_le_bytes(),
                0u32.to_le_bytes(),
            ]
            .concat(),
        ]
        .concat(),
    });
    let mut prog = lift_test_program(&input, &ctx);

    prog.delete_insn(DefSite {
        block: BlockId(0),
        idx: 1,
        reg: BPF_REG_9,
    })
    .expect("delete should remap BTF metadata");

    // IMPL: needs ProgramCFG::btf_records() with offsets and type-id views.
    assert_eq!(prog.btf_records().unwrap().func_offsets(), vec![0]);
    assert_eq!(prog.btf_records().unwrap().line_offsets(), vec![0, 1, 2]);
    assert_eq!(
        prog.btf_records().unwrap().line_type_ids(),
        vec![100, 102, 103]
    );
}

#[test]
fn kinsn_registry_rejects_duplicate_call_keys_for_different_targets() {
    let mut registry = KinsnRegistry::default();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 1234, 0)
        .unwrap();

    let err = registry
        .set_kinsn_call_for_target_name("bpf_extract64", 1234, 0)
        .unwrap_err();

    assert!(err.to_string().contains("already registered"));
}

#[test]
fn kinsn_registry_rejects_negative_btf_id() {
    let mut registry = KinsnRegistry::default();

    let err = registry
        .set_kinsn_call_for_target_name("bpf_rotate64", -1, 0)
        .unwrap_err();

    assert!(err.to_string().contains("negative btf_id"));
}

#[test]
fn kinsn_registry_replaces_old_call_key_when_target_moves() {
    let mut registry = KinsnRegistry::default();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 1234, 0)
        .unwrap();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 5678, 3)
        .unwrap();

    assert!(registry.lookup_by_kinsn_call(1234, 0).is_err());
    assert_eq!(
        registry.lookup_by_kinsn_call(5678, 3).unwrap().name,
        "bpf_rotate64"
    );
}
