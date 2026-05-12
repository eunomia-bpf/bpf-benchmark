// SPDX-License-Identifier: MIT

use super::endian::EndianFusionPass;
use crate::insn::*;
use crate::test_helpers::*;

fn endian_ctx() -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.platform.has_movbe = true;
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_endian_load16", 1616, 0)
        .expect("register endian16");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_endian_load32", 3232, 0)
        .expect("register endian32");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_endian_load64", 6464, 0)
        .expect("register endian64");
    ctx
}

#[test]
fn endian_rewrites_32bit_load_swap() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_6, 8),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_2, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &endian_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 3232));
}

#[test]
fn endian_rewrites_16bit_load_swap() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_H, BPF_REG_3, BPF_REG_6, 10),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_3, 0),
            0,
            16,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &endian_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 1616));
}

#[test]
fn endian_rewrites_64bit_load_swap() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_0, BPF_REG_7, 0),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_0, 0),
            0,
            64,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &endian_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 6464));
}

#[test]
fn endian_rejects_register_mismatch() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_1, 0),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_3, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input.clone(), &endian_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn endian_rejects_size_mismatch() {
    let input = vec![
        BpfInsn::ldx_mem(BPF_H, BPF_REG_2, BPF_REG_1, 0),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_2, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input.clone(), &endian_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn endian_skips_interior_branch_target() {
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_5, 0, 1),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_1, 0),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_2, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &endian_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 1, "interior branch target");
}

#[test]
fn test_endian_fusion_pass_branch_fixup() {
    // Restored from HEAD: expanding a load+bswap site into a kinsn call must
    // retarget branches that skip over the original two-instruction site.
    let input = vec![
        BpfInsn::jeq_imm(BPF_REG_5, 0, 2),
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_6, 4),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_2, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &endian_ctx());

    assert_eq!(run.result.sites_applied, 1);
    let last_pc = run.lowered.len() - 1;
    assert!(run.lowered[last_pc].is_exit());
    let branch_target = (1 + run.lowered[0].off as i64) as usize;
    assert_eq!(branch_target, last_pc);
}

#[test]
fn endian_preserves_module_call_offset() {
    let mut ctx = pass_ctx();
    ctx.platform.has_movbe = true;
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_endian_load32", 3232, 2)
        .expect("register endian32 module call");
    let input = vec![
        BpfInsn::ldx_mem(BPF_W, BPF_REG_2, BPF_REG_6, 8),
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(BPF_REG_2, 0),
            0,
            32,
        ),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(EndianFusionPass, input, &ctx);
    let call = run.lowered.iter().find(|i| i.is_call_kinsn()).unwrap();

    assert_eq!(call.imm, 3232);
    assert_eq!(call.off, 2);
}
