//! Exact GPR read/must-write effects for specialization of private temporaries.
//! Conditional writes and unclassified flag writes never kill a live value.
use super::*;

fn lane(register: Register, write: bool) -> Option<(String, u64)> {
    let family = x86_gpr64_family(register)?;
    let size = register.size();
    let shift = if matches!(register, Register::AH | Register::BH | Register::CH | Register::DH) { 8 } else { 0 };
    let mask = if size >= 8 || (write && size == 4) { u64::MAX }
        else { ((1u64 << (size * 8)) - 1) << shift };
    Some((format!("X86_{family:?}"), mask))
}

pub(super) fn describe(bytes: &[u8]) -> Result<serde_json::Value> {
    let mut factory = InstructionInfoFactory::new();
    let mut rows = Vec::new();
    for instruction in Decoder::new(64, bytes, DecoderOptions::NONE) {
        if instruction.is_invalid() { bail!("invalid instruction in proof effect metadata"); }
        let mut reads = BTreeMap::<String, u64>::new();
        let mut writes = BTreeMap::<String, u64>::new();
        for used in factory.info(&instruction).used_registers() {
            if matches!(used.access(), OpAccess::Read | OpAccess::CondRead | OpAccess::ReadWrite | OpAccess::ReadCondWrite) {
                if let Some((name, mask)) = lane(used.register(), false) { *reads.entry(name).or_default() |= mask; }
            }
            if matches!(used.access(), OpAccess::Write | OpAccess::ReadWrite) {
                if let Some((name, mask)) = lane(used.register(), true) { *writes.entry(name).or_default() |= mask; }
            }
        }
        if matches!(instruction.mnemonic(), Mnemonic::Xor | Mnemonic::Sub) &&
            instruction.op0_kind() == OpKind::Register && instruction.op1_kind() == OpKind::Register &&
            instruction.op0_register() == instruction.op1_register()
        {
            if let Some((name, _)) = lane(instruction.op0_register(), false) { reads.remove(&name); }
        }
        let unconditional_flags = matches!(instruction.mnemonic(),
            Mnemonic::Add | Mnemonic::Sub | Mnemonic::Adc | Mnemonic::Sbb |
            Mnemonic::And | Mnemonic::Or | Mnemonic::Xor | Mnemonic::Cmp | Mnemonic::Test |
            Mnemonic::Inc | Mnemonic::Dec | Mnemonic::Neg | Mnemonic::Mul | Mnemonic::Imul |
            Mnemonic::Bt | Mnemonic::Bts | Mnemonic::Btr | Mnemonic::Btc |
            Mnemonic::Popcnt | Mnemonic::Tzcnt | Mnemonic::Lzcnt |
            Mnemonic::Clc | Mnemonic::Stc | Mnemonic::Cmc | Mnemonic::Sahf);
        let offset = instruction.ip() as usize;
        rows.push(serde_json::json!({
            "offset": offset,
            "bytes": &bytes[offset..offset + instruction.len()],
            "reads": reads, "writes": writes,
            "flags_read": instruction.rflags_read(),
            "flags_written": if unconditional_flags { instruction.rflags_modified() } else { 0 },
        }));
    }
    Ok(serde_json::json!({"version": 1, "instructions": rows}))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn effect_masks_preserve_partial_and_conditional_writes_and_flag_dependencies() -> Result<()> {
        // MOV EAX,1; MOV AL,1; CMOVE RAX,RCX; XOR EAX,EAX; SHL RAX,CL; ADC RAX,0.
        let effects = describe(&[0xb8,1,0,0,0, 0xb0,1, 0x48,0x0f,0x44,0xc1,
            0x31,0xc0, 0x48,0xd3,0xe0, 0x48,0x83,0xd0,0])?;
        let rows = effects["instructions"].as_array().unwrap();
        assert_eq!(rows[0]["writes"]["X86_RAX"], u64::MAX);
        assert_eq!(rows[1]["writes"]["X86_RAX"], 255u64);
        assert!(rows[2]["writes"].get("X86_RAX").is_none());
        assert!(rows[2]["flags_read"].as_u64().unwrap() != 0);
        assert!(rows[3]["reads"].get("X86_RAX").is_none());
        assert_eq!(rows[4]["flags_written"], 0);
        assert!(rows[5]["flags_read"].as_u64().unwrap() != 0);
        Ok(())
    }
}
