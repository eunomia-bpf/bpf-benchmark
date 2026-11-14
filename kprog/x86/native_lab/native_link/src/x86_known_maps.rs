//! Conservative map-pointer provenance within native basic blocks.
//!
//! Facts start only at named map GOT loads. Joins, arithmetic, partial writes,
//! memory reloads and caller-clobbered registers cannot inherit a map identity.
use super::*;

pub(super) fn arguments(
    bytes: &[u8], sym: &SymInfo, got: &HashMap<LocalSiteKey, String>,
    maps: &HashMap<String, u64>,
) -> Result<HashMap<u64, String>> {
    let mut decoder = Decoder::with_ip(64, bytes, sym.address, DecoderOptions::NONE);
    let mut instructions = Vec::new();
    while decoder.can_decode() {
        let insn = decoder.decode();
        if insn.is_invalid() { bail!("invalid x86 map-provenance instruction in {}", sym.name); }
        instructions.push(insn);
    }
    // An unresolved jump table may enter any block; keep those lookups generic.
    if instructions.iter().any(|i| i.flow_control() == FlowControl::IndirectBranch) {
        return Ok(HashMap::new());
    }
    let mut boundaries = HashSet::from([sym.address]);
    for insn in &instructions {
        if !matches!(insn.flow_control(), FlowControl::Next | FlowControl::Call | FlowControl::IndirectCall) {
            boundaries.insert(insn.next_ip());
            if matches!(insn.op0_kind(), OpKind::NearBranch16 | OpKind::NearBranch32 | OpKind::NearBranch64) {
                boundaries.insert(insn.near_branch_target());
            }
        }
    }
    let mut registers: HashMap<Register, String> = HashMap::new();
    let mut result = HashMap::new();
    let mut factory = InstructionInfoFactory::new();
    for insn in &instructions {
        if boundaries.contains(&insn.ip()) { registers.clear(); }
        let local_ip = insn.ip() - sym.address;
        let call = matches!(insn.flow_control(), FlowControl::Call | FlowControl::IndirectCall);
        if call {
            if let Some(name) = registers.get(&Register::RDI) {
                result.insert(local_ip, name.clone());
            }
        }
        let mut assigned = None;
        if insn.mnemonic() == Mnemonic::Mov && insn.op0_kind() == OpKind::Register
            && x86_gpr64_family(insn.op0_register()) == Some(insn.op0_register())
        {
            if insn.op1_kind() == OpKind::Register
                && x86_gpr64_family(insn.op1_register()) == Some(insn.op1_register())
            {
                assigned = registers.get(&insn.op1_register()).cloned()
                    .map(|name| (insn.op0_register(), name));
            } else if insn.op1_kind() == OpKind::Memory && insn.is_ip_rel_memory_operand() {
                let key = local_site_key(sym, local_ip + insn.len() as u64 - 4);
                if let Some(name) = got.get(&key).filter(|name| maps.contains_key(*name)) {
                    assigned = Some((insn.op0_register(), name.clone()));
                }
            }
        }
        for reg in factory.info(insn).used_registers() {
            if matches!(reg.access(), OpAccess::Write | OpAccess::CondWrite |
                OpAccess::ReadWrite | OpAccess::ReadCondWrite) {
                if let Some(family) = x86_gpr64_family(reg.register()) { registers.remove(&family); }
            }
        }
        if call { clear_x86_call_clobbered_registers(&mut registers); }
        if let Some((reg, name)) = assigned { registers.insert(reg, name); }
    }
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn track(bytes: &[u8]) -> Result<HashMap<u64, String>> {
        let sym = SymInfo { name: "entry".into(), section_index: object::SectionIndex(1),
                            address: 0, size: bytes.len() as u64 };
        arguments(bytes, &sym, &HashMap::from([((sym.section_index, 0, 3), "map".into())]),
                  &HashMap::from([("map".into(), 0x1000)]))
    }

    #[test]
    fn actual_pointer_moves_survive_but_inner_results_do_not() -> Result<()> {
        // mov map@GOTPCREL(%rip),%r12; mov %r12,%rdi; call; mov %rax,%rdi; call;
        // mov %r12,%rdi; call. The helper's RAX result may be an inner map.
        let names = track(&[0x4c,0x8b,0x25,0,0,0,0, 0x4c,0x89,0xe7, 0xe8,0,0,0,0,
            0x48,0x89,0xc7, 0xe8,0,0,0,0, 0x4c,0x89,0xe7, 0xe8,0,0,0,0])?;
        assert_eq!(names.get(&10).map(String::as_str), Some("map"));
        assert!(!names.contains_key(&18));
        assert_eq!(names.get(&26).map(String::as_str), Some("map"));
        Ok(())
    }

    #[test]
    fn joins_partial_writes_and_arithmetic_erase_provenance() -> Result<()> {
        let load = [0x48,0x8b,0x3d,0,0,0,0]; // named map -> RDI
        for suffix in [
            vec![0x74,0, 0xe8,0,0,0,0], // branch enters call directly
            vec![0x89,0xff, 0xe8,0,0,0,0], // mov edi,edi truncates
            vec![0x48,0x83,0xc7,8, 0xe8,0,0,0,0], // add rdi,8
            vec![0x48,0x0f,0x44,0xf8, 0xe8,0,0,0,0], // cmove rdi,rax
            vec![0x48,0x8b,0x3f, 0xe8,0,0,0,0], // memory value is not map
            vec![0xe8,0,0,0,0, 0xe8,0,0,0,0], // caller-clobbered RDI
        ] {
            let bytes = [load.as_slice(), suffix.as_slice()].concat();
            let names = track(&bytes)?;
            assert!(!names.contains_key(&((bytes.len() - 5) as u64)), "{bytes:x?}");
        }
        // A taken edge bypasses the load, joining immediately at the call.
        let bytes = [0x74,7, 0x48,0x8b,0x3d,0,0,0,0, 0xe8,0,0,0,0];
        let sym = SymInfo { name: "entry".into(), section_index: object::SectionIndex(1),
                            address: 0, size: bytes.len() as u64 };
        assert!(arguments(&bytes, &sym, &HashMap::from([((sym.section_index,0,5),"map".into())]),
                          &HashMap::from([("map".into(),0x1000)]))?.is_empty());
        // Unknown jump-table successors cannot reuse any linear-flow fact.
        assert!(track(&[load.as_slice(), &[0xe8,0,0,0,0, 0xff,0xe0]].concat())?.is_empty());
        Ok(())
    }
}
