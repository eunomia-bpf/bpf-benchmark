// SPDX-License-Identifier: MIT

use super::prefetch::PrefetchPass;
use crate::insn::*;
use crate::pass::Arch;
use crate::test_helpers::*;

fn prefetch_ctx() -> crate::pass::PassContext {
    ctx_with_kinsn("bpf_x86_prefetcht0", 7777)
}

fn prefetch_ctx_with_targets(targets: &[(&str, i32)], arch: Arch) -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.arch = arch;
    for &(target, btf_id) in targets {
        ctx.kinsn_registry
            .set_kinsn_call_for_target_name(target, btf_id, 0)
            .expect("test kinsn target should register");
    }
    ctx
}

fn map_lookup_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ]
}

#[test]
fn prefetch_skips_map_value_without_profile_gate() {
    let run = run_pass_on_insns(
        PrefetchPass::default(),
        map_lookup_program(),
        &prefetch_ctx(),
    );

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 2, "map value prefetch requires profile");
}

#[test]
fn prefetch_reports_candidate_census_for_skipped_map_value() {
    let run = run_pass_on_insns(
        PrefetchPass::default().with_candidate_diagnostics_for_test(),
        map_lookup_program(),
        &prefetch_ctx(),
    );

    assert_eq!(run.result.sites_applied, 0);
    let diagnostic = run
        .result
        .site_diagnostics
        .iter()
        .find(|diagnostic| diagnostic.message.contains("prefetch_candidate"))
        .expect("prefetch should report skipped candidate metadata");
    assert_eq!(run.report_prog.rep_site_slot(diagnostic.site).unwrap(), 2);
    assert!(diagnostic.message.contains("source=map-value"));
    assert!(diagnostic.message.contains("ptr_reg=r0"));
    assert!(diagnostic.message.contains("ptr_root_pc=0"));
    assert!(diagnostic.message.contains("ptr_def_pc=0"));
    assert!(diagnostic.message.contains("mem_off=0"));
    assert!(diagnostic.message.contains("dependent_load_depth=0"));
}

#[test]
fn prefetch_suppresses_candidate_census_by_default() {
    let run = run_pass_on_insns(
        PrefetchPass::default(),
        map_lookup_program(),
        &prefetch_ctx(),
    );

    assert_eq!(run.result.sites_applied, 0);
    assert!(run.result.site_diagnostics.is_empty());
    assert_skip_reason(&run, 2, "map value prefetch requires profile");
}

#[test]
fn prefetch_allows_map_value_with_profile_gate() {
    let pass = PrefetchPass::with_map_value_profile_pcs([2]);
    let run = run_pass_on_insns(pass, map_lookup_program(), &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn prefetch_allows_map_value_with_pmu_profile_metrics() {
    let pass = PrefetchPass::from_profile_json_for_test(
        r#"{
            "min_load_misses": 10,
            "min_miss_rate": 0.10,
            "map_value_sites": [
                { "pc": 2, "load_misses": 12, "miss_rate": 0.25 }
            ]
        }"#,
    )
    .unwrap();
    let run = run_pass_on_insns(pass, map_lookup_program(), &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn prefetch_allows_explicit_map_value_prefetch_point() {
    let pass = PrefetchPass::from_profile_json_for_test(
        r#"{
            "map_value_prefetch_points": [
                { "pc": 4, "reg": 6 }
            ]
        }"#,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let run = run_pass_on_insns(pass, input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[4].is_kinsn_sidecar());
    assert!(run.lowered[5].is_call_kinsn());
}

#[test]
fn prefetch_allows_map_value_policy_point_prefetch_action() {
    let pass = PrefetchPass::from_profile_json_for_test(
        r#"{
            "map_value_policy_points": [
                { "pc": 4, "reg": 6, "action": "prefetch" }
            ]
        }"#,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let run = run_pass_on_insns(pass, input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[4].is_kinsn_sidecar());
    assert!(run.lowered[5].is_call_kinsn());
}

#[test]
fn prefetch_policy_point_skip_action_overrides_prefetch_action() {
    let pass = PrefetchPass::from_profile_json_for_test(
        r#"{
            "map_value_policy_points": [
                { "pc": 4, "reg": 6, "action": "prefetch" },
                { "pc": 4, "reg": 6, "action": "skip" }
            ]
        }"#,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let run = run_pass_on_insns(pass, input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert!(!run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn prefetch_policy_point_skip_pc_overrides_map_value_site() {
    let pass = PrefetchPass::from_profile_json_for_test(
        r#"{
            "map_value_pcs": [2],
            "map_value_policy_points": [
                { "pc": 2, "action": "skip" }
            ]
        }"#,
    )
    .unwrap();
    let run = run_pass_on_insns(pass, map_lookup_program(), &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 2, "map value prefetch requires profile");
}

#[test]
fn prefetch_hint_selects_x86_variant_target() {
    let pass = PrefetchPass::from_profile_json_with_options_for_test(
        r#"{
            "map_value_prefetch_points": [
                { "pc": 4, "reg": 6 }
            ]
        }"#,
        "t1",
        1,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let ctx = prefetch_ctx_with_targets(&[("bpf_x86_prefetcht1", 8101)], Arch::X86_64);
    let run = run_pass_on_insns(pass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|insn| insn.is_call_kinsn() && insn.imm == 8101));
}

#[test]
fn prefetch_hint_selects_arm64_variant_target() {
    let pass = PrefetchPass::from_profile_json_with_options_for_test(
        r#"{
            "map_value_prefetch_points": [
                { "pc": 4, "reg": 6 }
            ]
        }"#,
        "pldl2strm",
        1,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let ctx = prefetch_ctx_with_targets(&[("bpf_arm64_prfm_pldl2strm", 8203)], Arch::Aarch64);
    let run = run_pass_on_insns(pass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|insn| insn.is_call_kinsn() && insn.imm == 8203));
}

#[test]
fn prefetch_policy_point_metadata_selects_point_hint() {
    let pass = PrefetchPass::from_profile_json_with_options_for_test(
        r#"{
            "map_value_policy_points": [
                {
                    "pc": 4,
                    "reg": 6,
                    "action": "prefetch",
                    "policy": "horizon",
                    "horizon": 2,
                    "degree": 1,
                    "hint": "pldl2keep",
                    "reason": "synthetic future pointer"
                }
            ]
        }"#,
        "pldl1keep",
        1,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 4),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let ctx = prefetch_ctx_with_targets(&[("bpf_arm64_prfm_pldl2keep", 8202)], Arch::Aarch64);
    let run = run_pass_on_insns(pass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|insn| insn.is_call_kinsn() && insn.imm == 8202));
}

#[test]
fn prefetch_policy_point_rejects_invalid_metadata() {
    let err = PrefetchPass::from_profile_json_for_test(
        r#"{
            "map_value_policy_points": [
                {
                    "pc": 4,
                    "reg": 6,
                    "action": "prefetch",
                    "policy": "horizon",
                    "horizon": 0,
                    "degree": 1,
                    "hint": "pldl1keep",
                    "reason": "bad horizon"
                }
            ]
        }"#,
    )
    .unwrap_err();

    assert!(err.to_string().contains("horizon must be positive"));
}

#[test]
fn prefetch_profile_points_respect_max_sites_degree() {
    let pass = PrefetchPass::from_profile_json_with_options_for_test(
        r#"{
            "map_value_prefetch_points": [
                { "pc": 6, "reg": 6 },
                { "pc": 6, "reg": 7 }
            ]
        }"#,
        "t0",
        2,
    )
    .unwrap();
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 6),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_6, 64),
        BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_0),
        BpfInsn::alu64_imm(BPF_ADD, BPF_REG_7, 128),
        BpfInsn::mov64_imm(BPF_REG_4, 123),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    let run = run_pass_on_insns(pass, input, &prefetch_ctx());
    let prefetch_call_count = run
        .lowered
        .iter()
        .filter(|insn| insn.is_call_kinsn() && insn.imm == 7777)
        .count();

    assert_eq!(run.result.sites_applied, 2);
    assert_eq!(prefetch_call_count, 2);
}

#[test]
fn prefetch_skips_alias_register_for_map_value_without_profile_gate() {
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::jeq_imm(BPF_REG_6, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(PrefetchPass::default(), input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 3, "map value prefetch requires profile");
}

#[test]
fn prefetch_tracks_then_skips_map_value_stack_spill_without_profile_gate() {
    let input = vec![
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            libbpf_sys::BPF_FUNC_map_lookup_elem as i32,
        ),
        BpfInsn::stx_mem(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
        BpfInsn::mov64_imm(BPF_REG_2, 64),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_6, BPF_REG_10, -8),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_6, BPF_REG_2),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_6, 0),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(PrefetchPass::default(), input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 5, "map value prefetch requires profile");
}

#[test]
fn prefetch_skips_static_packet_load_without_data_dependency() {
    let mut input = vec![BpfInsn::ldx_mem(
        BPF_W,
        BPF_REG_6,
        BPF_REG_1,
        XDP_PACKET_DATA_OFFSET,
    )];
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_3, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 9, "requires a data-dependent dereference");
}

#[test]
fn prefetch_tracks_then_skips_static_packet_stack_spill() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::stx_mem(BPF_DW, BPF_REG_10, BPF_REG_6, -8),
        BpfInsn::mov64_imm(BPF_REG_2, 32),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_7, BPF_REG_10, -8),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_7, BPF_REG_2),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 0),
        BpfInsn::exit(),
    ];
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 5, "requires a data-dependent dereference");
}

#[test]
fn prefetch_deduplicates_same_cacheline_packet_first_deref_loads() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_6, 40),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 63),
        BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_6),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_7, BPF_REG_2),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 0),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 1),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 63),
        BpfInsn::exit(),
    ];
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_skip_reason(&run, 1, "address source");
}

#[test]
fn prefetch_ignores_packet_stores() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::stx_mem(BPF_B, BPF_REG_6, BPF_REG_2, 64),
        BpfInsn::exit(),
    ];
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
}

#[test]
fn prefetch_inserts_only_at_ldimm64_instruction_boundary() {
    let wide = BpfInsn::ld_imm64(BPF_REG_3, 0, 123);
    let mut input = vec![BpfInsn::ldx_mem(
        BPF_W,
        BPF_REG_6,
        BPF_REG_1,
        XDP_PACKET_DATA_OFFSET,
    )];
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_6, 40));
    input.push(BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 63));
    input.push(BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_6));
    input.push(BpfInsn::alu64_reg(BPF_ADD, BPF_REG_7, BPF_REG_2));
    input.extend_from_slice(&wide);
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_4, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    let ldimm = run.lowered.iter().position(|i| i.is_ldimm64()).unwrap();
    assert_eq!(run.lowered[ldimm + 1].code, 0);
    assert!(!run.lowered[ldimm + 1].is_kinsn_sidecar());
    assert!(run.lowered.iter().any(|i| i.is_kinsn_sidecar()));
}

#[test]
fn prefetch_emits_packet_first_deref() {
    let mut input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_6, 40),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 63),
        BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_6),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_7, BPF_REG_2),
    ];
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_4, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_7, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_skip_reason(&run, 1, "address source");
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn prefetch_emits_packet_first_deref_through_alu32_index_math() {
    let mut input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_6, 40),
        BpfInsn::alu32_reg(BPF_MOV, BPF_REG_3, BPF_REG_2),
        BpfInsn::alu32_imm(BPF_AND, BPF_REG_3, 63),
        BpfInsn::alu32_reg(BPF_MOV, BPF_REG_7, BPF_REG_3),
        BpfInsn::alu32_imm(BPF_LSH, BPF_REG_7, 3),
        BpfInsn::mov64_reg(BPF_REG_8, BPF_REG_6),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_8, BPF_REG_7),
    ];
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_4, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_8, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert_skip_reason(&run, 1, "address source");
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
}

#[test]
fn prefetch_skips_two_stage_dependent_packet_chain() {
    let mut input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_PACKET_DATA_OFFSET),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_2, BPF_REG_6, 40),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_2, 63),
        BpfInsn::mov64_reg(BPF_REG_7, BPF_REG_6),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_7, BPF_REG_2),
        BpfInsn::ldx_mem(BPF_B, BPF_REG_3, BPF_REG_7, 0),
        BpfInsn::alu64_imm(BPF_AND, BPF_REG_3, 63),
        BpfInsn::mov64_reg(BPF_REG_8, BPF_REG_6),
        BpfInsn::alu64_reg(BPF_ADD, BPF_REG_8, BPF_REG_3),
    ];
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_4, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_8, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass::default(), input, &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 1, "address source");
    assert_skip_reason(&run, 5, "address source");
    assert_skip_reason(&run, 17, "chain is too deep");
}
