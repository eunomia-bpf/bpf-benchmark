use super::*;

#[test]
fn parses_real_style_branch_and_insn_states() {
    let log = r#"
from 4 to 6: R0_w=pkt(off=8,r=8) R1=ctx() R2_w=pkt(r=8) R3_w=pkt_end() R10=fp0
6: R0_w=pkt(off=8,r=8) R1=ctx() R2_w=pkt(r=8) R3_w=pkt_end() R10=fp0
6: (71) r3 = *(u8 *)(r2 +0)           ; R2_w=pkt(r=8) R3_w=scalar(umax=255,var_off=(0x0; 0xff))
7: (15) if r3 == 0x0 goto pc+1        ; R3=scalar(smin=umin=smin32=umin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))
10: R1=map_value(map=.data.two_byte_,ks=4,vs=2,off=1) R2=1 R10=fp0 fp-8=0000???? refs=2 cb
"#;

    let insns = parse_verifier_log(log);
    assert_eq!(insns.len(), 5);

    assert_eq!(insns[0].pc, 6);
    assert_eq!(insns[0].from_pc, Some(4));
    assert_eq!(insns[0].kind, VerifierInsnKind::EdgeFullState);
    assert_eq!(insns[0].frame, 0);
    assert_eq!(insns[0].regs.get(&1).unwrap().reg_type, "ctx");
    assert_eq!(insns[0].regs.get(&0).unwrap().reg_type, "pkt");
    assert_eq!(insns[0].regs.get(&0).unwrap().offset, Some(8));
    assert_eq!(insns[0].regs.get(&10).unwrap().reg_type, "fp");
    assert_eq!(insns[0].regs.get(&10).unwrap().offset, Some(0));

    assert_eq!(insns[2].pc, 6);
    let r3_after_load = insns[2].regs.get(&3).unwrap();
    assert_eq!(r3_after_load.reg_type, "scalar");
    assert_eq!(insns[2].kind, VerifierInsnKind::InsnDeltaState);
    assert_eq!(r3_after_load.value_width, VerifierValueWidth::Bits32);
    assert_eq!(r3_after_load.range.umax, Some(255));
    assert_eq!(
        r3_after_load.tnum,
        Some(Tnum {
            value: 0,
            mask: 0xff
        })
    );
    assert_eq!(r3_after_load.exact_value, None);

    assert_eq!(insns[3].pc, 7);
    assert_eq!(insns[3].kind, VerifierInsnKind::BranchDeltaState);
    let r3_before_branch = insns[3].regs.get(&3).unwrap();
    assert_eq!(r3_before_branch.range.umin, Some(0));
    assert_eq!(r3_before_branch.range.umax, Some(255));

    assert_eq!(insns[4].pc, 10);
    let r1 = insns[4].regs.get(&1).unwrap();
    assert_eq!(r1.reg_type, "map_value");
    assert_eq!(r1.offset, Some(1));

    let r2 = insns[4].regs.get(&2).unwrap();
    assert_eq!(r2.reg_type, "scalar");
    assert_eq!(r2.exact_u64(), Some(1));
    assert_eq!(r2.range.umin, Some(1));
    assert_eq!(r2.range.umax, Some(1));

    let fp8 = insns[4].stack.get(&-8).unwrap();
    assert_eq!(fp8.slot_types.as_deref(), Some("0000????"));
    assert!(fp8.value.is_none());
}

#[test]
fn parses_constants_and_repeated_bounds_from_real_messages() {
    let log = r#"
0: R1=ctx() R10=fp0
2: (25) if r0 > 0x1 goto pc+1         ; R0=scalar(smin=smin32=0,smax=umax=smax32=umax32=1,var_off=(0x0; 0x1))
4: (b7) r0 = 0                        ; R0=0
5: (b7) r0 = 1                        ; R0=1
"#;

    let insns = parse_verifier_log(log);
    assert_eq!(insns.len(), 4);

    assert_eq!(insns[0].regs.get(&1).unwrap().reg_type, "ctx");
    assert_eq!(insns[0].regs.get(&10).unwrap().offset, Some(0));

    let range = insns[1].regs.get(&0).unwrap();
    assert_eq!(insns[1].kind, VerifierInsnKind::BranchDeltaState);
    assert_eq!(range.reg_type, "scalar");
    assert_eq!(range.range.smin, Some(0));
    assert_eq!(range.range.umax, Some(1));
    assert_eq!(range.exact_value, None);

    let zero = insns[2].regs.get(&0).unwrap();
    assert_eq!(zero.exact_u64(), Some(0));

    let one = insns[3].regs.get(&0).unwrap();
    assert_eq!(one.exact_u64(), Some(1));
}

#[test]
fn parses_speculative_full_state_and_stack_spill() {
    let log = r#"
from 12 to 18 (speculative execution): frame1: R2_w=42 R10=fp0 fp-24=0000???? scalar(id=7,var_off=(0x2a; 0x0))
"#;

    let insns = parse_verifier_log(log);
    assert_eq!(insns.len(), 1);

    let insn = &insns[0];
    assert_eq!(insn.kind, VerifierInsnKind::EdgeFullState);
    assert!(insn.speculative);
    assert_eq!(insn.frame, 1);

    let reg = insn.regs.get(&2).unwrap();
    assert_eq!(reg.value_width, VerifierValueWidth::Bits32);
    assert_eq!(reg.exact_u32(), Some(42));
    assert_eq!(reg.exact_u64(), None);

    let spill = insn.stack.get(&-24).unwrap();
    assert_eq!(spill.slot_types.as_deref(), Some("0000????"));
    let spilled_value = spill.value.as_ref().unwrap();
    assert_eq!(spilled_value.reg_type, "scalar");
    assert_eq!(spilled_value.id, Some(7));
    assert_eq!(
        spilled_value.tnum,
        Some(Tnum {
            value: 0x2a,
            mask: 0
        })
    );
    assert_eq!(spilled_value.exact_u64(), Some(42));
}

#[test]
fn distinguishes_exact_64bit_and_32bit_scalars() {
    let log = r#"
0: (b7) r3 = 42                       ; R3=42
1: (b4) w4 = 42                       ; R4_w=42
"#;

    let insns = parse_verifier_log(log);
    assert_eq!(insns.len(), 2);

    let r3 = insns[0].regs.get(&3).unwrap();
    assert_eq!(r3.value_width, VerifierValueWidth::Bits64);
    assert_eq!(r3.exact_u64(), Some(42));
    assert_eq!(r3.exact_u32(), Some(42));

    let r4 = insns[1].regs.get(&4).unwrap();
    assert_eq!(r4.value_width, VerifierValueWidth::Bits32);
    assert_eq!(r4.exact_u64(), None);
    assert_eq!(r4.exact_u32(), Some(42));
}

#[test]
fn truncated_state_line_is_an_error() {
    let log = "\
0: R1=ctx() R10=fp0
1: (b7) r0 = 0                        ; R0=0
2: (07) r0 += 1                       ; R0=scalar(var_off=(0x1;
";

    let err = format!("{:#}", parse_verifier_log_result(log).unwrap_err());
    assert!(err.contains("failed to parse verifier state line 3"));
    assert!(err.contains("no register or stack state"));
}

#[test]
fn ignores_non_state_lines() {
    let log = r#"
0: (b7) r0 = 0
1: safe
from 2 to 7: safe
processed 4 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
"#;

    assert!(parse_verifier_log(log).is_empty());
}

#[test]
fn parses_frame_and_stack_tokens() {
    let log = r#"
3: frame1: R1=ctx() R2=fp-24 R10=fp0 fp-24=scalar(id=1) fp-32=0000???? fp-40=fp-56
"#;

    let insns = parse_verifier_log(log);
    assert_eq!(insns.len(), 1);
    let insn = &insns[0];
    assert_eq!(insn.pc, 3);
    assert_eq!(insn.frame, 1);
    assert_eq!(insn.regs.get(&2).unwrap().reg_type, "fp");
    assert_eq!(insn.regs.get(&2).unwrap().offset, Some(-24));

    let fp24 = insn.stack.get(&-24).unwrap();
    assert_eq!(fp24.slot_types, None);
    assert_eq!(fp24.value.as_ref().unwrap().reg_type, "scalar");

    let fp32 = insn.stack.get(&-32).unwrap();
    assert_eq!(fp32.slot_types.as_deref(), Some("0000????"));
    assert!(fp32.value.is_none());

    let fp40 = insn.stack.get(&-40).unwrap();
    assert_eq!(fp40.value.as_ref().unwrap().reg_type, "fp");
    assert_eq!(fp40.value.as_ref().unwrap().offset, Some(-56));
}
