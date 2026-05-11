use super::*;

#[test]
fn bpf_insn_abi_offsets_and_raw_bytes_match_uapi() {
    assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, code), 0);
    assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, off), 2);
    assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, imm), 4);

    let insn = BpfInsn::new(0xbf, BpfInsn::make_regs(3, 5), -2, 0x1234_5678);
    assert_eq!(
        &insn as *const BpfInsn as usize,
        insn.as_kernel() as *const libbpf_sys::bpf_insn as usize
    );
    assert_eq!(
        insn.raw_bytes(),
        [0xbf, 0x53, 0xfe, 0xff, 0x78, 0x56, 0x34, 0x12]
    );
    assert_eq!(BpfInsn::from_raw_bytes(insn.raw_bytes()), insn);
}

#[test]
fn test_cond_jmp_classification() {
    // JEQ_IMM
    let insn = BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(1, 0), 5, 42);
    assert!(insn.is_cond_jmp());
    assert!(insn.is_jmp_class());
    assert!(!insn.is_ja());
    assert!(!insn.is_call());

    // JMP32 JNE_REG
    let insn = BpfInsn::new(BPF_JMP32 | BPF_JNE | BPF_X, BpfInsn::make_regs(2, 3), 3, 0);
    assert!(insn.is_cond_jmp());
    assert!(insn.is_jmp_class());
}

#[test]
fn test_emit_packed_kinsn_call_with_module_off() {
    let payload = 0x12345;
    let insns = emit_packed_kinsn_call_with_off(payload, 1234, 2);

    assert_eq!(insns.len(), 2);
    assert!(insns[0].is_kinsn_sidecar());
    assert_eq!(insns[0].dst_reg(), 0x5);
    assert_eq!(insns[0].off, 0x1234);
    assert_eq!(insns[0].imm, 0);
    assert!(insns[1].is_call());
    assert_eq!(insns[1].imm, 1234);
    assert_eq!(insns[1].off, 2);
}

#[test]
fn test_emit_packed_kinsn_call_wide_payload() {
    let payload = 0xabcde12345;
    let insns = emit_packed_kinsn_call_with_off(payload, 5555, 0);

    assert_eq!(insns.len(), 2);
    assert!(insns[0].is_kinsn_sidecar());
    assert_eq!(insns[0].dst_reg(), 0x5);
    assert_eq!(insns[0].off, 0x1234);
    assert_eq!(insns[0].imm, 0xabcde);
    assert!(insns[1].is_call());
    assert_eq!(insns[1].imm, 5555);
}
