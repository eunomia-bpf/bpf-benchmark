use super::ccmp::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};
use crate::test_helpers::*;

fn jmp_zero(op: u8, class: u8, reg: u8, off: i16) -> BpfInsn {
    BpfInsn::new(class | op | BPF_K, BpfInsn::make_regs(reg, 0), off, 0)
}

fn ccmp_ctx(arch: Arch) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.platform.arch = arch;
    ctx.kinsn_registry.ccmp64_btf_id = 77;
    ctx
}

fn decode_ccmp_payload(encoded: u64) -> anyhow::Result<CcmpPayload> {
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
    let payload = CcmpPayload {
        dst_reg,
        fail_mode,
        width,
        regs,
    };
    encode_ccmp_payload(&payload)?;
    Ok(payload)
}

#[test]
fn ccmp_payload_roundtrips_canonical_encoding() {
    let payload = CcmpPayload {
        dst_reg: BPF_REG_0,
        fail_mode: CcmpFailMode::EqZero,
        width: CcmpWidth::Bpf64,
        regs: vec![BPF_REG_1, BPF_REG_2, BPF_REG_3],
    };

    let encoded = encode_ccmp_payload(&payload).unwrap();
    assert_eq!(decode_ccmp_payload(encoded).unwrap(), payload);
}

#[test]
fn ccmp_payload_rejects_dst_alias() {
    let err = encode_ccmp_payload(&CcmpPayload {
        dst_reg: BPF_REG_1,
        fail_mode: CcmpFailMode::EqZero,
        width: CcmpWidth::Bpf64,
        regs: vec![BPF_REG_1, BPF_REG_2],
    })
    .unwrap_err();

    assert!(err.to_string().contains("aliases"));
}

#[test]
fn scan_ccmp_chain_detects_three_term_nez_guard() {
    let insns = vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        exit_insn(),
    ];

    let sites = scan_ccmp_sites(&insns);

    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].old_len, 3);
    assert_eq!(sites[0].target_pc, 4);
    assert_eq!(sites[0].fail_mode, CcmpFailMode::EqZero);
    assert_eq!(sites[0].regs, vec![BPF_REG_1, BPF_REG_2, BPF_REG_3]);
}

#[test]
fn scan_ccmp_chain_rejects_mixed_fail_polarity_boundary() {
    let insns = vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JNE, BPF_JMP, BPF_REG_2, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        exit_insn(),
    ];

    assert!(scan_ccmp_sites(&insns).is_empty());
}

#[test]
fn ccmp_pass_arch_gate_skips_x86_64() {
    let mut program = BpfProgram::new(vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        exit_insn(),
    ]);
    let pass = CcmpPass;
    let result = pass
        .run(
            &mut program,
            &mut AnalysisCache::new(),
            &ccmp_ctx(Arch::X86_64),
        )
        .unwrap();
    assert!(result.sites_skipped[0].reason.contains("aarch64"));
}

#[test]
fn ccmp_pass_emits_kinsn_and_final_branch_on_aarch64() {
    let mut program = BpfProgram::new(vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 0),
        exit_insn(),
    ]);
    let pass = CcmpPass;
    let result = pass
        .run(
            &mut program,
            &mut AnalysisCache::new(),
            &ccmp_ctx(Arch::Aarch64),
        )
        .unwrap();
    assert_eq!(result.sites_applied, 1);
    assert!(program.insns[0].is_kinsn_sidecar());
    assert_eq!(program.insns[1].src_reg(), BPF_PSEUDO_KINSN_CALL);
    assert_eq!(program.insns[1].imm, 77);
    assert_eq!(program.insns[2].code, BPF_JMP | BPF_JEQ | BPF_K);
    assert_eq!(program.insns[2].dst_reg(), BPF_REG_0);
    assert_eq!(program.insns[2].off, 1);

    let decoded = decode_ccmp_payload(sidecar_payload(&program.insns[0])).unwrap();
    assert_eq!(decoded.regs, vec![BPF_REG_1, BPF_REG_2, BPF_REG_3]);
    assert_eq!(decoded.fail_mode, CcmpFailMode::EqZero);
}

#[test]
fn ccmp_pass_skips_overlong_chain_without_partial_rewrite() {
    let mut program = BpfProgram::new(vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 5),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 4),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_4, 2),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_5, 1),
        BpfInsn::mov64_imm(BPF_REG_0, 1),
        exit_insn(),
    ]);
    let pass = CcmpPass;
    let result = pass
        .run(
            &mut program,
            &mut AnalysisCache::new(),
            &ccmp_ctx(Arch::Aarch64),
        )
        .unwrap();
    assert!(result.sites_skipped[0].reason.contains("exceeds maximum"));
    assert_eq!(program.insns[0].code, BPF_JMP | BPF_JEQ | BPF_K);
}

#[test]
fn ccmp_pass_skips_site_crossing_subprog_boundary() {
    let mut program = BpfProgram::new(vec![
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
        jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
        exit_insn(),
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
            0,
            -2,
        ),
        exit_insn(),
    ]);
    let pass = CcmpPass;
    let result = pass
        .run(
            &mut program,
            &mut AnalysisCache::new(),
            &ccmp_ctx(Arch::Aarch64),
        )
        .unwrap();
    assert!(result.sites_skipped[0].reason.contains("subprog boundary"));
}
