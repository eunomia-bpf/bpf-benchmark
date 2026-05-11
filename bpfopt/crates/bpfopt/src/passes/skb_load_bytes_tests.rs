// SPDX-License-Identifier: MIT

use super::skb_load_bytes::SkbLoadBytesSpecPass;
use crate::insn::*;
use crate::test_helpers::*;

const SKB_LOAD_BYTES: i32 = libbpf_sys::BPF_FUNC_skb_load_bytes as i32;
const MAP_LOOKUP: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
const XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;

fn setup(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::mov64_imm(BPF_REG_2, offset),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_3, stack_off),
        BpfInsn::mov64_imm(BPF_REG_4, len),
    ]
}

fn skb_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
    let mut insns = setup(offset, stack_off, len);
    insns.push(BpfInsn::helper_call(SKB_LOAD_BYTES));
    insns.push(BpfInsn::jne_imm(BPF_REG_0, 0, 2));
    insns.push(BpfInsn::mov64_imm(BPF_REG_0, 1));
    insns.push(BpfInsn::exit());
    insns.push(BpfInsn::mov64_imm(BPF_REG_0, 0));
    insns.push(BpfInsn::exit());
    insns
}

fn run_skb(input: Vec<BpfInsn>, prog_type: u32) -> PassRun {
    let mut ctx = pass_ctx();
    ctx.prog_type = prog_type;
    run_pass_on_insns(SkbLoadBytesSpecPass, input, &ctx)
}

#[test]
fn skb_load_bytes_rewrites_constant_offset_and_length() {
    let run = run_skb(skb_program(14, -8, 1), SCHED_CLS);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered.iter().any(|i| {
        i.is_ldx_mem() && i.src_reg() == BPF_REG_1 && i.off == SKB_PACKET_DATA_OFFSET
    }));
    assert!(run.lowered.iter().any(|i| {
        i.is_ldx_mem() && i.src_reg() == BPF_REG_1 && i.off == SKB_PACKET_DATA_END_OFFSET
    }));
}

#[test]
fn skb_load_bytes_ignores_non_skb_helper() {
    let mut input = setup(14, -8, 1);
    input.push(BpfInsn::helper_call(MAP_LOOKUP));
    input.push(BpfInsn::exit());

    let run = run_skb(input.clone(), SCHED_CLS);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn skb_load_bytes_rejects_variable_offset() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_6),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_3, -8),
        BpfInsn::mov64_imm(BPF_REG_4, 1),
        BpfInsn::helper_call(SKB_LOAD_BYTES),
        BpfInsn::exit(),
    ];

    let run = run_skb(input.clone(), SCHED_CLS);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn skb_load_bytes_rejects_variable_length() {
    let input = vec![
        BpfInsn::mov64_imm(BPF_REG_2, 14),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_3, -8),
        BpfInsn::mov64_reg(BPF_REG_4, BPF_REG_7),
        BpfInsn::helper_call(SKB_LOAD_BYTES),
        BpfInsn::exit(),
    ];

    let run = run_skb(input.clone(), SCHED_CLS);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn skb_load_bytes_requires_tc_program_type() {
    let input = skb_program(14, -8, 1);

    let run = run_skb(input.clone(), XDP);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn skb_load_bytes_requires_ctx_reload_after_prior_helper() {
    let input = vec![
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_1),
        BpfInsn::helper_call(MAP_LOOKUP),
        BpfInsn::mov64_imm(BPF_REG_2, 14),
        BpfInsn::mov64_reg(BPF_REG_3, BPF_REG_10),
        BpfInsn::add64_imm(BPF_REG_3, -8),
        BpfInsn::mov64_imm(BPF_REG_4, 1),
        BpfInsn::helper_call(SKB_LOAD_BYTES),
        BpfInsn::exit(),
    ];

    let run = run_skb(input.clone(), SCHED_CLS);

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn skb_load_bytes_fixes_branch_around_rewritten_site() {
    let mut input = vec![BpfInsn::jeq_imm(BPF_REG_0, 0, 6)];
    input.extend(skb_program(14, -8, 1));

    let run = run_skb(input, SCHED_CLS);

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[0].is_cond_jmp());
    assert!(run.lowered[0].off > 6);
}
