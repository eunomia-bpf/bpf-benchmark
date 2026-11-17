//! Defined image-code addresses through full-width register and private stack copies.
use super::*;

pub(super) fn calls(elf: &object::File, sym: &SymInfo, included: &[SymInfo])
    -> Result<HashSet<u64>> {
    let bytes = read_symbol_bytes(elf, sym)?;
    let section = elf.section_by_index(sym.section_index)?;
    let relocations: HashMap<_, _> = section.relocations().collect();
    let mut seeds = HashSet::new();
    for insn in Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE) {
        if insn.mnemonic() != Mnemonic::Lea || insn.op0_kind() != OpKind::Register
            || insn.op0_register().size() != 8 || !insn.is_ip_rel_memory_operand() { continue; }
        let Some(reloc) = relocations.get(&(insn.next_ip()-4)) else { continue; };
        if !matches!(reloc.flags(), RelocationFlags::Elf { r_type: 2 }) { continue; }
        let Some(target) = resolve_x86_plt32_defined_target_addr(elf, reloc)? else { continue; };
        if included.iter().any(|function| symbol_key(function) == target) {
            seeds.insert(insn.ip());
        }
    }
    Ok(analyze(&bytes, sym.address, &seeds))
}

fn stack_offset(insn: &Instruction) -> Option<i64> {
    (insn.memory_base() == Register::RSP && insn.memory_index() == Register::None
        && insn.segment_prefix() == Register::None)
        .then_some(insn.memory_displacement64() as i64)
}

fn analyze(bytes: &[u8], base: u64, seeds: &HashSet<u64>) -> HashSet<u64> {
    let instructions: Vec<_> = Decoder::with_ip(64, bytes, base, DecoderOptions::NONE).into_iter().collect();
    // Unknown jump-table predecessors cannot contribute a private stack fact.
    if instructions.iter().any(|i| i.flow_control() == FlowControl::IndirectBranch) {
        return HashSet::new();
    }
    let mut boundaries = HashSet::from([base]);
    for insn in &instructions {
        if insn.flow_control() == FlowControl::Call && insn.op0_kind() == OpKind::NearBranch64 {
            boundaries.insert(insn.near_branch_target());
        }
        if !matches!(insn.flow_control(), FlowControl::Next | FlowControl::Call | FlowControl::IndirectCall) {
            boundaries.insert(insn.next_ip());
            if matches!(insn.op0_kind(), OpKind::NearBranch64) {
                boundaries.insert(insn.near_branch_target());
            }
        }
    }
    let mut registers = HashMap::<Register, ()>::new();
    let mut slots = HashSet::<i64>::new();
    let mut sites = HashSet::new();
    let mut factory = InstructionInfoFactory::new();
    for insn in &instructions {
        if boundaries.contains(&insn.ip()) { registers.clear(); slots.clear(); }
        if x86_indirect_call_register(insn).is_some_and(|reg| registers.contains_key(&reg)) {
            sites.insert(insn.ip()-base);
        }
        let register_copy = insn.mnemonic() == Mnemonic::Mov
            && insn.op1_kind() == OpKind::Register && insn.op1_register().size() == 8
            && registers.contains_key(&insn.op1_register());
        let assigned = insn.op0_kind() == OpKind::Register && insn.op0_register().size() == 8
            && (seeds.contains(&insn.ip()) || register_copy ||
                (insn.mnemonic() == Mnemonic::Mov && insn.op1_kind() == OpKind::Memory
                    && insn.memory_size().size() == 8 && stack_offset(insn).is_some_and(|s| slots.contains(&s))));
        let info = factory.info(insn);
        if info.used_memory().iter().any(|m| matches!(m.access(), OpAccess::Write |
            OpAccess::CondWrite | OpAccess::ReadWrite | OpAccess::ReadCondWrite)) {
            if insn.op0_kind() == OpKind::Memory {
                if let Some(offset) = stack_offset(insn).filter(|_| insn.memory_size().size() > 0) {
                    let end = i128::from(offset)+insn.memory_size().size() as i128;
                    slots.retain(|s| i128::from(*s)+8 <= i128::from(offset) || i128::from(*s) >= end);
                    if register_copy && insn.memory_size().size() == 8 { slots.insert(offset); }
                } else { slots.clear(); }
            } else { slots.clear(); }
        }
        for used in info.used_registers() {
            if matches!(used.access(), OpAccess::Write | OpAccess::CondWrite |
                OpAccess::ReadWrite | OpAccess::ReadCondWrite) {
                if let Some(reg) = x86_gpr64_family(used.register()) {
                    registers.remove(&reg);
                    if reg == Register::RSP { slots.clear(); }
                }
            }
        }
        if matches!(insn.flow_control(), FlowControl::Call | FlowControl::IndirectCall) {
            clear_x86_call_clobbered_registers(&mut registers);
            slots.clear(); // A callee may write through an escaped stack pointer.
        }
        if assigned { registers.insert(insn.op0_register(), ()); }
    }
    sites
}

#[cfg(test)]
mod tests {
    use super::*;

    fn roundtrip(elf: &object::File, entry: &SymInfo, path: &PathBuf) -> Result<RewriteResult> {
        let included=discover_reachable(elf,entry)?;
        let empty=HashMap::new();
        let proof=rewrite_x86(elf,entry,&included,&empty,&empty,&HashMap::new(),&[],true,true,
                              None,None,None,false)?;
        write_proof_object(path,object::Architecture::X86_64,&entry.name,&proof.blob,&proof.proof_symbols,
            &proof.proof_relocs,&proof.proof_data_relocs,proof.callee_saved_mask)?;
        let bytes=fs::read(path)?;
        let elf=object::File::parse(bytes.as_slice())?;
        let entry=find_symbol_by_name(&elf,&entry.name)?;
        let included=discover_reachable(&elf,&entry)?;
        rewrite_x86(&elf,&entry,&included,&empty,&empty,&HashMap::new(),&[],false,true,
                    None,None,None,false)
    }

    #[test]
    fn stack_code_identity_is_lost_on_aliases_partial_writes_calls_and_joins() {
        let seed = [0x48,0x8d,0x05,0,0,0,0];
        let store = [0x48,0x89,0x44,0x24,8];
        let reload_call = [0x48,0x8b,0x44,0x24,8,0xff,0xd0];
        for (middle, known) in [
            (vec![], true),
            (vec![0xc6,0x44,0x24,16,0], true), // Disjoint stack write.
            (vec![0xc6,0x44,0x24,11,0], false), // Partial overlap.
            (vec![0x48,0x89,0x01], false), // Unknown write may alias the slot.
            (vec![0x48,0x83,0xec,8], false), // RSP has changed.
            (vec![0xe8,0,0,0,0], false), // Callee may mutate escaped stack.
            (vec![0xeb,0], false), // Incoming block has no proven slot fact.
        ] {
            let code = [seed.as_slice(), store.as_slice(), &middle, &reload_call].concat();
            assert_eq!(!analyze(&code,0,&HashSet::from([0])).is_empty(),known,"{middle:x?}");
        }
        for suffix in [vec![0x89,0xc0,0xff,0xd0], vec![0xe8,0,0,0,0,0xff,0xd0]] {
            assert!(analyze(&[seed.as_slice(),&suffix].concat(),0,&HashSet::from([0])).is_empty());
        }
        let copy_call = [0x49,0x89,0xc4,0x41,0xff,0xd4];
        assert_eq!(analyze(&[seed.as_slice(),&copy_call].concat(),0,&HashSet::from([0])),HashSet::from([10]));
    }


    #[test]
    #[ignore = "uses the retained upstream CEL compiler output"]
    fn retained_cel_code_pointer_executes() -> Result<()> {
        let input=std::env::var("NATIVE_LINK_CODE_POINTER_INPUT")?;
        let output=PathBuf::from(std::env::var("NATIVE_LINK_CODE_POINTER_OUTPUT")?);
        let bytes=fs::read(input)?;
        let elf=object::File::parse(bytes.as_slice())?;
        let entry=find_symbol_by_name(&elf,"native_cel_stock")?;
        let result=roundtrip(&elf,&entry,&output.join("cel.proof.o"))?;
        assert!(result.relocs.is_empty());
        #[cfg(all(target_arch="x86_64",target_os="linux"))]
        {
            let mut code=result.blob;code.push(0xc3);
            for value in 0..64u64 {
                let mut context=[value,17,29];
                assert_eq!(memory::call_blob(&code,context.as_mut_ptr().cast(),0,0) as usize,
                           usize::from(value==42),"actual upstream CEL input {value}");
            }
            fs::write(output.join("cel-execution.json"),
                "{\"actual_upstream_cel_vectors\":64,\"proof_kernel_roundtrip\":true,\"stock_checked\":false}\n")?;
        }
        Ok(())
    }
}
