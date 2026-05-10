use super::*;
use std::collections::{BTreeSet, HashMap};

use crate::bpf::use_mock_maps;
use crate::insn::*;
use crate::pass::{BpfProgram, PassContext, PipelineResult};
use crate::test_helpers::*;

const BPF_MAP_TYPE_HASH: u32 = libbpf_sys::BPF_MAP_TYPE_HASH;
const BPF_MAP_TYPE_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_ARRAY;
const BPF_PSEUDO_MAP_FD: u8 = libbpf_sys::BPF_PSEUDO_MAP_FD as u8;

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

fn run_pipeline_with_passes(program: &mut BpfProgram, pass_names: &[&str]) -> PipelineResult {
    use_mock_maps(program);
    let pass_names = pass_names
        .iter()
        .map(|name| (*name).to_string())
        .collect::<Vec<_>>();
    let pm = build_custom_pipeline(&pass_names).unwrap();
    let mut ctx = PassContext::baseline();
    ctx.policy.enabled_passes = pass_names;
    pm.run(program, &ctx).unwrap()
}

#[test]
#[rustfmt::skip] fn pass_registry_declares_all_emitted_kinsn_probe_names() {
    let declared = PASS_REGISTRY.iter().flat_map(|entry| entry.metadata.kinsn_targets).flat_map(|kinsn| kinsn.probe_aliases()).collect::<BTreeSet<_>>();
    assert_eq!(declared, BTreeSet::from(["bpf_rotate64", "bpf_rotate32", "bpf_select64", "bpf_ccmp64", "bpf_extract64", "bpf_endian_load16", "bpf_endian_load32", "bpf_endian_load64", "bpf_memcpy_bulk", "bpf_memset_bulk", "bpf_prefetch"]));
}

#[test]
fn test_cfg_analysis_with_subprogs() {
    use crate::analysis::CFGAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 1), 0, 2),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
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

    let callback = BpfInsn::ld_imm64(2, BPF_PSEUDO_FUNC, 4);
    let prog = make_program(vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_reg(0, 1),
        BpfInsn::exit(),
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
        BpfInsn::jeq_imm(1, 0, 1),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::mov64_imm(0, 2),
        BpfInsn::exit(),
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

    let map = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        BpfInsn::st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::add64_imm(2, -4),
        BpfInsn::helper_call(libbpf_sys::BPF_FUNC_map_lookup_elem as i32),
        BpfInsn::ldx_mem(BPF_W, 0, 0, 0),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 0),
        BpfInsn::exit(),
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
            BpfInsn::exit(),
        ]
    );
}

#[test]
fn cascade_full_pipeline_materializes_alu_and_leaves_branch_cleanup_to_kernel() {
    for (label, map_id, map_type, mut program, expected) in {
        let array_map = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let hash_map = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        [
            (
                "array full pipeline",
                304,
                BPF_MAP_TYPE_ARRAY,
                make_program(vec![
                    array_map[0],
                    array_map[1],
                    BpfInsn::st_mem(BPF_W, 10, -4, 1),
                    BpfInsn::mov64_reg(2, 10),
                    BpfInsn::add64_imm(2, -4),
                    BpfInsn::helper_call(libbpf_sys::BPF_FUNC_map_lookup_elem as i32),
                    BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                    BpfInsn::jeq_imm(6, 0, 4),
                    BpfInsn::mov64_imm(1, 10),
                    BpfInsn::alu64_reg(BPF_ADD, 1, 6),
                    BpfInsn::mov64_imm(0, 1),
                    BpfInsn::exit(),
                    BpfInsn::mov64_imm(0, 0),
                    BpfInsn::exit(),
                ]),
                vec![
                    BpfInsn::mov32_imm(6, 42),
                    BpfInsn::jeq_imm(6, 0, 2),
                    BpfInsn::mov64_imm(0, 1),
                    BpfInsn::exit(),
                    BpfInsn::mov64_imm(0, 0),
                    BpfInsn::exit(),
                ],
            ),
            (
                "hash null path",
                305,
                BPF_MAP_TYPE_HASH,
                make_program(vec![
                    hash_map[0],
                    hash_map[1],
                    BpfInsn::st_mem(BPF_W, 10, -4, 1),
                    BpfInsn::mov64_reg(2, 10),
                    BpfInsn::add64_imm(2, -4),
                    BpfInsn::helper_call(libbpf_sys::BPF_FUNC_map_lookup_elem as i32),
                    BpfInsn::jeq_imm(0, 0, 5),
                    BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
                    BpfInsn::mov64_imm(1, 10),
                    BpfInsn::alu64_reg(BPF_ADD, 1, 6),
                    BpfInsn::mov64_imm(0, 1),
                    BpfInsn::exit(),
                    BpfInsn::mov64_imm(0, 0),
                    BpfInsn::exit(),
                ]),
                vec![BpfInsn::mov64_imm(0, 1), BpfInsn::exit()],
            ),
        ]
    } {
        install_map(
            map_id,
            map_type,
            8,
            HashMap::from([(1u32.to_le_bytes().to_vec(), 42u32.to_le_bytes().to_vec())]),
        );
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
