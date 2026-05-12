// SPDX-License-Identifier: MIT

use super::prefetch::PrefetchPass;
use crate::insn::*;
use crate::pass::InsnAnnotation;
use crate::test_helpers::*;

fn prefetch_ctx() -> crate::pass::PassContext {
    ctx_with_kinsn("bpf_prefetch", 7777)
}

fn map_lookup_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::helper_call(libbpf_sys::BPF_FUNC_map_lookup_elem as i32),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ]
}

#[test]
fn prefetch_emits_map_value_prefetch() {
    let run = run_pass_on_insns(PrefetchPass, map_lookup_program(), &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 7777));
}

#[test]
fn prefetch_uses_alias_register_for_map_value_deref() {
    let input = vec![
        BpfInsn::helper_call(libbpf_sys::BPF_FUNC_map_lookup_elem as i32),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::jeq_imm(BPF_REG_6, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(PrefetchPass, input, &prefetch_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_kinsn_sidecar()));
}

#[test]
fn prefetch_profile_filters_cold_map_value_site() {
    let mut annotations = vec![InsnAnnotation::default(); 4];
    annotations[2].prefetch_profile = Some(prefetch_profile(100, 0.0));
    let mut ctx = pass_ctx();
    ctx.annotations = annotations;

    let run = run_pass_on_insns(PrefetchPass, map_lookup_program(), &ctx);

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 2, "no observed cache misses");
}

#[test]
fn prefetch_emits_packet_prefetch_in_xdp_program() {
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

    let run = run_pass_on_insns(PrefetchPass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| i.is_call_kinsn()));
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
    input.extend_from_slice(&wide);
    input.extend((0..8).map(|idx| BpfInsn::mov64_imm(BPF_REG_4, idx)));
    input.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
    input.push(BpfInsn::exit());
    let mut ctx = prefetch_ctx();
    ctx.prog_type = libbpf_sys::BPF_PROG_TYPE_XDP;

    let run = run_pass_on_insns(PrefetchPass, input, &ctx);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[1].is_ldimm64());
    assert_eq!(run.lowered[2].code, 0);
    assert!(run.lowered[3].is_kinsn_sidecar());
}
