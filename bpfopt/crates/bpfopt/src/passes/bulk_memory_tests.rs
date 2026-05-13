// SPDX-License-Identifier: MIT

use super::bulk_memory::BulkMemoryPass;
use crate::insn::*;
use crate::test_helpers::*;

fn bulk_ctx() -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_bulk_memcpy", 4101, 0)
        .expect("register memcpy kinsn");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_bulk_memset", 4102, 0)
        .expect("register memset kinsn");
    ctx
}

fn memcpy_run(lanes: usize) -> Vec<BpfInsn> {
    let mut insns = Vec::new();
    for lane in 0..lanes {
        let off = (lane * 8) as i16;
        insns.push(BpfInsn::ldx_mem(BPF_DW, BPF_REG_3, BPF_REG_6, off));
        insns.push(BpfInsn::stx_mem(BPF_DW, BPF_REG_10, BPF_REG_3, -64 + off));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn memset_zero_run(lanes: usize) -> Vec<BpfInsn> {
    let mut insns = Vec::new();
    for lane in 0..lanes {
        insns.push(BpfInsn::new(
            BPF_ST | BPF_DW | BPF_MEM,
            BpfInsn::make_regs(BPF_REG_10, 0),
            -64 + (lane * 8) as i16,
            0,
        ));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn width_class(size: u8) -> u64 {
    match size {
        BPF_B => 0,
        BPF_H => 1,
        BPF_W => 2,
        BPF_DW => 3,
        other => panic!("unsupported size code {other:#x}"),
    }
}

fn pack_memset_payload(dst_base: u8, dst_off: i16, len: u8, size: u8, fill_imm8: u8) -> u64 {
    assert!((1..=128).contains(&len));
    let zero_fill = fill_imm8 == 0;
    (dst_base as u64)
        | ((dst_off as u16 as u64) << 8)
        | (((len - 1) as u64) << 24)
        | (width_class(size) << 32)
        | ((zero_fill as u64) << 35)
        | ((fill_imm8 as u64) << 36)
}

fn memset_call(dst_base: u8, dst_off: i16, len: u8, size: u8, fill_imm8: u8) -> Vec<BpfInsn> {
    emit_packed_kinsn_call_with_off(
        pack_memset_payload(dst_base, dst_off, len, size, fill_imm8),
        4102,
        0,
    )
}

fn st_mem_fill_run(size: u8, imm: i32, lanes: usize) -> Vec<BpfInsn> {
    let stride = match size {
        BPF_B => 1,
        BPF_H => 2,
        BPF_W => 4,
        BPF_DW => 8,
        other => panic!("unsupported size code {other:#x}"),
    };
    let mut insns = Vec::new();
    for lane in 0..lanes {
        insns.push(BpfInsn::new(
            BPF_ST | size | BPF_MEM,
            BpfInsn::make_regs(BPF_REG_10, 0),
            -32 + stride * lane as i16,
            imm,
        ));
    }
    insns.push(BpfInsn::exit());
    insns
}

fn stx_mem_fill_run(size: u8, src_reg: u8, lanes: usize) -> Vec<BpfInsn> {
    let stride = match size {
        BPF_B => 1,
        BPF_H => 2,
        BPF_W => 4,
        BPF_DW => 8,
        other => panic!("unsupported size code {other:#x}"),
    };
    let mut insns = vec![BpfInsn::mov64_imm(src_reg, 0x5a5a5a5a)];
    for lane in 0..lanes {
        insns.push(BpfInsn::stx_mem(
            size,
            BPF_REG_10,
            src_reg,
            -32 + stride * lane as i16,
        ));
    }
    insns.push(BpfInsn::exit());
    insns
}

#[test]
fn bulk_memory_rewrites_large_memcpy_run() {
    let run = run_pass_on_insns(BulkMemoryPass, memcpy_run(8), &bulk_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 4101));
}

#[test]
fn bulk_memory_rewrites_zero_memset_run() {
    let run = run_pass_on_insns(BulkMemoryPass, memset_zero_run(8), &bulk_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 4102));
}

#[test]
fn test_memset_fill_encoding_matrix() {
    // Restored from HEAD: the memset kinsn sidecar payload is ABI-like; each
    // fill mode must encode the width, offset, length, zero flag, and byte fill.
    for (label, input, mut expected) in [
        (
            "nonzero immediate",
            st_mem_fill_run(BPF_W, 0x7f7f7f7f, 8),
            memset_call(BPF_REG_10, -32, 32, BPF_W, 0x7f),
        ),
        (
            "byte immediate truncates",
            st_mem_fill_run(BPF_B, 0x12345680, 32),
            memset_call(BPF_REG_10, -32, 32, BPF_B, 0x80),
        ),
        (
            "negative dw immediate",
            st_mem_fill_run(BPF_DW, -1, 4),
            memset_call(BPF_REG_10, -32, 32, BPF_DW, 0xff),
        ),
        ("register fill", stx_mem_fill_run(BPF_W, BPF_REG_8, 8), {
            let mut out = vec![BpfInsn::mov64_imm(BPF_REG_8, 0x5a5a5a5a)];
            out.extend(memset_call(BPF_REG_10, -32, 32, BPF_W, 0x5a));
            out
        }),
    ] {
        expected.push(BpfInsn::exit());

        let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

        assert_eq!(run.result.sites_applied, 1, "{label}");
        assert_eq!(run.lowered, expected, "{label}");
    }
}

#[test]
fn bulk_memory_rejects_short_memcpy_run() {
    let input = memcpy_run(1);

    let run = run_pass_on_insns(BulkMemoryPass, input.clone(), &bulk_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn bulk_memory_rejects_aliasing_memcpy_ranges() {
    let mut input = Vec::new();
    for lane in 0..8 {
        let off = (lane * 8) as i16;
        input.push(BpfInsn::ldx_mem(BPF_DW, BPF_REG_3, BPF_REG_10, -64 + off));
        input.push(BpfInsn::stx_mem(BPF_DW, BPF_REG_10, BPF_REG_3, -60 + off));
    }
    input.push(BpfInsn::exit());

    let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 0, "alias");
}

#[test]
fn bulk_memory_fixes_branches_after_replacement() {
    let mut input = vec![BpfInsn::ja(16)];
    input.extend(memcpy_run(8));

    let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[0].is_ja());
    assert_eq!(run.lowered[0].off, 2);
}

#[test]
fn bulk_memory_skips_when_proof_temp_live_out() {
    let mut input = memcpy_run(8);
    input.insert(input.len() - 1, BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_3));

    let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 0, "temp");
}
