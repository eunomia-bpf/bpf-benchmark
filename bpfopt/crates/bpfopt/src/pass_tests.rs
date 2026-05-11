// SPDX-License-Identifier: MIT

use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::Arc;

use crate::analysis::{BBProgram, BlockId, DefSite};
use crate::insn::*;
use crate::pass::*;
use crate::passes::{ConstPropPass, DcePass};
use crate::test_helpers::*;

struct CountingPass {
    name: &'static str,
    calls: Arc<AtomicUsize>,
}

impl BpfPass for CountingPass {
    fn name(&self) -> &str {
        self.name
    }

    // IMPL: needs BpfPass::run(&mut BBProgram, &PassContext) -> Result<PassResult>.
    fn run(&self, prog: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        self.calls.fetch_add(1, Ordering::SeqCst);
        assert!(!prog.blocks().collect::<Vec<_>>().is_empty());
        Ok(PassResult::unchanged())
    }
}

struct DeleteFirstMovPass;

impl BpfPass for DeleteFirstMovPass {
    fn name(&self) -> &str {
        "delete_first_mov"
    }

    // IMPL: needs BpfPass::run(&mut BBProgram, &PassContext) -> Result<PassResult>.
    fn run(&self, prog: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        prog.delete_insn(DefSite {
            block: BlockId(0),
            idx: 0,
            reg: BPF_REG_1,
        })?;
        Ok(PassResult {
            sites_applied: 1,
            ..PassResult::default()
        })
    }
}

#[test]
fn pipeline_lifts_once_runs_multiple_passes_on_same_bbprogram() {
    let first_calls = Arc::new(AtomicUsize::new(0));
    let second_calls = Arc::new(AtomicUsize::new(0));
    let input = vec![BpfInsn::mov64_imm(BPF_REG_0, 0), BpfInsn::exit()];

    let (results, lowered, _) = run_pipeline_on_insns(
        vec![
            Box::new(CountingPass {
                name: "first",
                calls: first_calls.clone(),
            }),
            Box::new(CountingPass {
                name: "second",
                calls: second_calls.clone(),
            }),
        ],
        input.clone(),
        &pass_ctx(),
    );

    assert_eq!(results.len(), 2);
    assert_eq!(first_calls.load(Ordering::SeqCst), 1);
    assert_eq!(second_calls.load(Ordering::SeqCst), 1);
    assert_eq!(lowered, input);
}

#[test]
fn pipeline_lowers_once_after_all_bbprogram_mutations() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_1, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ];

    let (results, lowered, _) =
        run_pipeline_on_insns(vec![Box::new(DeleteFirstMovPass)], input, &pass_ctx());

    assert_eq!(results[0].sites_applied, 1);
    assert_eq!(
        lowered,
        vec![BpfInsn::mov64_imm(BPF_REG_0, 0), BpfInsn::exit()]
    );
}

#[test]
fn test_pass_manager_invalidates_verifier_states_after_transform() {
    // Restored from HEAD: verifier/oracle facts must not survive a bytecode
    // mutation, or later passes can apply stale per-PC verifier evidence.
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

    assert_eq!(prog.oracle().expect("oracle should be lifted").len(), 1);

    prog.delete_insn(DefSite {
        block: BlockId(0),
        idx: 0,
        reg: BPF_REG_1,
    })
    .expect("delete should invalidate oracle");

    assert!(
        prog.oracle().is_none_or(|states| states.is_empty()),
        "BBProgram mutation must clear stale verifier/oracle facts"
    );
}

#[test]
fn pipeline_pass_context_carries_verifier_states_between_passes() {
    let input = vec![
        BpfInsn::mov32_imm(BPF_REG_1, 20),
        BpfInsn::alu64_imm(BPF_LSH, BPF_REG_1, 32),
        BpfInsn::alu64_imm(BPF_RSH, BPF_REG_1, 32),
        BpfInsn::exit(),
    ];
    let ctx = ctx_with_verifier_states(vec![
        verifier_delta_state(
            1,
            std::collections::HashMap::from([(BPF_REG_1, scalar_reg(20u64 << 32))]),
        ),
        verifier_delta_state(
            2,
            std::collections::HashMap::from([(BPF_REG_1, scalar_reg(20))]),
        ),
    ]);

    let (results, lowered, prog) = run_pipeline_on_insns(
        vec![Box::new(ConstPropPass), Box::new(DcePass)],
        input,
        &ctx,
    );

    assert_eq!(results.len(), 2);
    assert!(
        prog.oracle().is_none(),
        "mutating passes must invalidate consumed verifier states"
    );
    assert!(lowered.contains(&BpfInsn::mov64_imm(BPF_REG_1, 20)));
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
    set_btf_records(
        &mut ctx,
        Some(crate::pass::BtfInfoRecords {
            rec_size: 8,
            bytes: [0u32.to_le_bytes(), 10u32.to_le_bytes()].concat(),
        }),
        Some(crate::pass::BtfInfoRecords {
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
        }),
    );
    let mut prog = lift_test_program(&input, &ctx);

    prog.delete_insn(DefSite {
        block: BlockId(0),
        idx: 1,
        reg: BPF_REG_9,
    })
    .expect("delete should remap BTF metadata");

    // IMPL: needs BBProgram::btf_records() with offsets and type-id views.
    assert_eq!(prog.btf_records().func_offsets(), vec![0]);
    assert_eq!(prog.btf_records().line_offsets(), vec![0, 1, 2]);
    assert_eq!(prog.btf_records().line_type_ids(), vec![100, 102, 103]);
}

#[test]
fn kinsn_registry_resolves_aliases_to_canonical_target() {
    let mut registry = KinsnRegistry::default();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 1234, 2)
        .expect("register rotate");

    assert_eq!(
        registry.canonical_name_for_target_name("bpf_rotate64"),
        Some("bpf_rotate64")
    );
    assert_eq!(
        registry.btf_id_for_target_name("bpf_rotate64").unwrap(),
        1234
    );
    assert_eq!(
        registry.call_off_for_target_name("bpf_rotate64").unwrap(),
        2
    );
    assert_eq!(
        registry
            .lookup_by_kinsn_call(1234, 2)
            .unwrap()
            .canonical_name,
        "bpf_rotate64"
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
        registry
            .lookup_by_kinsn_call(5678, 3)
            .unwrap()
            .canonical_name,
        "bpf_rotate64"
    );
}

#[test]
fn pass_context_owns_side_input_fields_for_bbprogram_passes() {
    let mut ctx = ctx_with_verifier_states(vec![verifier_delta_state(
        0,
        std::collections::HashMap::from([(BPF_REG_1, scalar_reg(7))]),
    )]);
    set_map_ids(&mut ctx, vec![111]);
    set_branch_miss_rate(&mut ctx, 0.02);

    // IMPL: these side inputs move off BpfProgram and onto PassContext.
    assert_eq!(ctx.verifier_states.len(), 1);
    assert_eq!(ctx.map_ids, vec![111]);
    assert_eq!(ctx.branch_miss_rate, Some(0.02));
}
