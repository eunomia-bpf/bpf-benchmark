// SPDX-License-Identifier: MIT

use super::ccmp::{encode_ccmp_payload, CcmpFailMode, CcmpPass, CcmpWidth};
use crate::insn::*;
use crate::pass::Arch;
use crate::test_helpers::*;

fn jmp_zero(op: u8, class: u8, reg: u8, off: i16) -> BpfInsn {
    BpfInsn::new(class | op | BPF_K, BpfInsn::make_regs(reg, 0), off, 0)
}

fn ccmp_ctx(arch: Arch) -> crate::pass::PassContext {
    let mut ctx = ctx_with_kinsn("bpf_ccmp64", 77);
    ctx.platform.arch = arch;
    ctx
}

fn three_term_chain() -> Vec<BpfInsn> {
    vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        BpfInsn::exit(),
    ]
}

fn decode_ccmp_payload(encoded: u64) -> anyhow::Result<(u8, CcmpFailMode, CcmpWidth, Vec<u8>)> {
    const MAX_CCMP_TERMS_FOR_TEST: usize = 4;

    if encoded >> 24 != 0 {
        anyhow::bail!("ccmp payload has non-zero reserved bits");
    }
    let dst_reg = (encoded & 0xf) as u8;
    let count_bits = ((encoded >> 4) & 0x3) as usize;
    if count_bits > MAX_CCMP_TERMS_FOR_TEST - 2 {
        anyhow::bail!("ccmp encoded term count exceeds maximum");
    }
    let count = count_bits + 2;
    let fail_mode = match (encoded >> 6) & 0x1 {
        0 => CcmpFailMode::EqZero,
        1 => CcmpFailMode::NeZero,
        bit => anyhow::bail!("invalid ccmp fail mode bit {bit}"),
    };
    let width = match (encoded >> 7) & 0x1 {
        0 => CcmpWidth::Bpf64,
        1 => CcmpWidth::Bpf32,
        bit => anyhow::bail!("invalid ccmp width bit {bit}"),
    };
    let mut regs = Vec::with_capacity(count);
    for idx in 0..MAX_CCMP_TERMS_FOR_TEST {
        let reg = ((encoded >> (8 + idx * 4)) & 0xf) as u8;
        if idx >= count {
            if reg != 0 {
                anyhow::bail!("ccmp unused register slot {idx} is non-zero");
            }
            continue;
        }
        regs.push(reg);
    }
    encode_ccmp_payload(dst_reg, fail_mode, width, &regs)?;
    Ok((dst_reg, fail_mode, width, regs))
}

#[test]
fn ccmp_payload_roundtrips_canonical_encoding() {
    // Restored from HEAD: the CCMP kinsn sidecar payload is an ABI contract,
    // including reserved bits and canonical unused register slots.
    let payload = (
        BPF_REG_0,
        CcmpFailMode::EqZero,
        CcmpWidth::Bpf64,
        vec![BPF_REG_1, BPF_REG_2, BPF_REG_3],
    );

    let encoded = encode_ccmp_payload(payload.0, payload.1, payload.2, &payload.3).unwrap();

    assert_eq!(decode_ccmp_payload(encoded).unwrap(), payload);
}

#[test]
fn ccmp_arch_gate_skips_x86_64() {
    let run = run_pass_on_insns(CcmpPass, three_term_chain(), &ccmp_ctx(Arch::X86_64));

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "aarch64");
}

#[test]
fn ccmp_emits_kinsn_and_final_branch_on_aarch64() {
    let run = run_pass_on_insns(CcmpPass, three_term_chain(), &ccmp_ctx(Arch::Aarch64));

    assert_eq!(run.result.sites_applied, 1);
    assert!(run.lowered[0].is_kinsn_sidecar());
    assert!(run.lowered[1].is_call_kinsn());
    assert_eq!(run.lowered[1].imm, 77);
    assert!(run.lowered[2].is_cond_jmp());
}

#[test]
fn ccmp_rejects_mixed_fail_polarity_chain() {
    let input = vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JNE, BPF_JMP, BPF_REG_2, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CcmpPass, input.clone(), &ccmp_ctx(Arch::Aarch64));

    assert_eq!(run.result.sites_applied, 0);
    assert_eq!(run.lowered, input);
}

#[test]
fn ccmp_skips_overlong_chain_without_partial_rewrite() {
    let input = vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 5),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 4),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_4, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_5, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CcmpPass, input, &ccmp_ctx(Arch::Aarch64));

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "exceeds maximum");
}

#[test]
fn ccmp_skips_site_crossing_subprog_boundary() {
    let input = vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
        BpfInsn::exit(),
        BpfInsn::pseudo_call_to(3, 1),
        BpfInsn::exit(),
    ];

    let run = run_pass_on_insns(CcmpPass, input, &ccmp_ctx(Arch::Aarch64));

    assert_eq!(run.result.sites_applied, 0);
    assert_skip_reason(&run.result, 0, "subprog boundary");
}
