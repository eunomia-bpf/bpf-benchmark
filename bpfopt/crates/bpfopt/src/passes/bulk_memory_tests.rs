// SPDX-License-Identifier: MIT

use super::bulk_memory::BulkMemoryPass;
use crate::insn::*;
use crate::test_helpers::*;

fn bulk_ctx() -> crate::pass::PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_movzbl_mem", 4101, 0)
        .expect("register movzbl kinsn");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_movb_mem_reg", 4102, 0)
        .expect("register movb store kinsn");
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_x86_movb_imm_mem", 4103, 0)
        .expect("register movb imm store kinsn");
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
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 4102));
}

#[test]
fn bulk_memory_rewrites_zero_memset_run() {
    let run = run_pass_on_insns(BulkMemoryPass, memset_zero_run(8), &bulk_ctx());

    assert_eq!(run.result.sites_applied, 1);
    assert!(run
        .lowered
        .iter()
        .any(|i| i.is_call_kinsn() && i.imm == 4103));
}

#[test]
fn test_memset_fill_encoding_matrix() {
    for (label, input, expected_fill, expected_store_count) in [
        (
            "nonzero immediate",
            st_mem_fill_run(BPF_W, 0x7f7f7f7f, 8),
            0x7f,
            32,
        ),
        (
            "byte immediate truncates",
            st_mem_fill_run(BPF_B, 0x12345680, 32),
            0x80,
            32,
        ),
        (
            "negative dw immediate",
            st_mem_fill_run(BPF_DW, -1, 4),
            0xff,
            32,
        ),
        (
            "register fill",
            stx_mem_fill_run(BPF_W, BPF_REG_8, 8),
            0x5a,
            32,
        ),
    ] {
        let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

        assert_eq!(run.result.sites_applied, 1, "{label}");
        let stores = run
            .lowered
            .iter()
            .filter(|i| i.is_call_kinsn() && i.imm == 4103)
            .count();
        assert_eq!(stores, expected_store_count, "{label}");
        assert!(run.lowered.iter().any(|i| {
            i.is_kinsn_sidecar() && BpfInsn::unpack_u8(i.sidecar_payload(), 20) == expected_fill
        }));
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
    let target = (run.lowered[0].off as isize + 1) as usize;
    assert_eq!(target, run.lowered.len() - 1);
}

#[test]
fn bulk_memory_skips_when_proof_temp_live_out() {
    let mut input = memcpy_run(8);
    input.insert(input.len() - 1, BpfInsn::mov64_reg(BPF_REG_0, BPF_REG_3));

    let run = run_pass_on_insns(BulkMemoryPass, input, &bulk_ctx());

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run, 0, "temp");
}
