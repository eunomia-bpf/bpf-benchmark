//! Preserve relative code-table relocations when proof rodata is copied.
//! ELF addends refer to the source instruction layout, not the rewritten one.
use super::*;

fn relative_table_bases(
    elf: &object::File, symbols: &[&SymInfo], data_section: object::SectionIndex,
) -> Result<(Vec<u64>, HashSet<LocalSiteKey>)> {
    let mut bases = Vec::new();
    let mut sites = HashSet::new();
    let data = elf.section_by_index(data_section)?;
    for sym in symbols {
        let section = elf.section_by_index(sym.section_index)?;
        let bytes = read_symbol_bytes(elf, sym)?;
        let instructions: Vec<_> = Decoder::with_ip(64, &bytes, sym.address,
            DecoderOptions::NONE).into_iter().collect();
        for window in instructions.windows(4) {
            let [lea, load, add, jump] = window else { unreachable!() };
            if lea.mnemonic() != Mnemonic::Lea || !lea.is_ip_rel_memory_operand() ||
                lea.op0_kind() != OpKind::Register ||
                x86_gpr64_family(lea.op0_register()) != Some(lea.op0_register()) ||
                load.mnemonic() != Mnemonic::Movsxd || load.op0_kind() != OpKind::Register ||
                load.op1_kind() != OpKind::Memory || load.memory_base() != lea.op0_register() ||
                load.memory_index() == Register::None || load.memory_index_scale() != 4 ||
                load.memory_displacement64() != 0 || load.segment_prefix() != Register::None ||
                load.op0_register() == lea.op0_register() ||
                add.mnemonic() != Mnemonic::Add || add.op0_kind() != OpKind::Register ||
                add.op1_kind() != OpKind::Register || add.op0_register() != load.op0_register() ||
                add.op1_register() != lea.op0_register() || jump.flow_control() != FlowControl::IndirectBranch ||
                jump.op0_kind() != OpKind::Register || jump.op0_register() != load.op0_register()
            { continue; }
            for (at, relocation) in section.relocations().filter(|(at, _)|
                *at >= lea.ip() && *at < lea.next_ip())
            {
                if !matches!(relocation.flags(), RelocationFlags::Elf { r_type: 2 }) { continue; }
                let RelocationTarget::Symbol(index) = relocation.target() else { continue; };
                let target = elf.symbol_by_index(index)?;
                if target.section_index() != Some(data_section) { continue; }
                let mut decoder = Decoder::with_ip(64, &bytes[(lea.ip()-sym.address) as usize..],
                    lea.ip(), DecoderOptions::NONE);
                let decoded = decoder.decode();
                let offsets = decoder.get_constant_offsets(&decoded);
                if offsets.displacement_size() != 4 ||
                    at != lea.ip() + offsets.displacement_offset() as u64 || relocation.has_implicit_addend()
                { bail!("relative table base lacks an explicit PC32 displacement"); }
                let address = i128::from(target.address()) + i128::from(relocation.addend()) +
                    i128::from(lea.next_ip() - at) - i128::from(data.address());
                let base = u64::try_from(address).map_err(|_| anyhow!("relative table base out of range"))?;
                if base >= data.size() { bail!("relative table base exceeds data section"); }
                let mut code_entry = false;
                for (_, entry) in data.relocations().filter(|(at, _)| *at == base) {
                    if !matches!(entry.flags(), RelocationFlags::Elf { r_type: 2 }) { continue; }
                    let RelocationTarget::Symbol(index) = entry.target() else { continue; };
                    if let Some(section) = elf.symbol_by_index(index)?.section_index() {
                        code_entry |= elf.section_by_index(section)?.kind() == SectionKind::Text;
                    }
                }
                if !code_entry { bail!("relative jump-table base has no PC32 code entry"); }
                bases.push(base);
                sites.insert(local_site_key(sym, jump.ip() - sym.address));
            }
        }
    }
    bases.sort_unstable();
    bases.dedup();
    Ok((bases, sites))
}

pub(super) fn indirect_sites(elf: &object::File, included: &[SymInfo])
    -> Result<HashSet<LocalSiteKey>> {
    let symbols: Vec<_> = included.iter().collect();
    let mut sites = HashSet::new();
    for section in elf.sections().filter(|section|
        section.kind() == SectionKind::ReadOnlyData && section.relocations().next().is_some())
    {
        sites.extend(relative_table_bases(elf, &symbols, section.index())?.1);
    }
    Ok(sites)
}

pub(super) struct CodeReloc {
    pub proof: ProofDataReloc,
    pub target_offset: u64,
    pub table_offset: u64,
}

pub(super) fn code_relocations(
    elf: &object::File, layouts: &[SymbolLayout], section_index: object::SectionIndex,
    start: u64, size: u64, owner: &str,
) -> Result<Vec<CodeReloc>> {
    let section = elf.section_by_index(section_index)?;
    let end = start.checked_add(size).ok_or_else(|| anyhow!("proof data range overflow"))?;
    let relocations: Vec<_> = section.relocations().filter(|(at, _)| *at >= start && *at < end).collect();
    if relocations.is_empty() { return Ok(Vec::new()); }
    let symbols: Vec<_> = layouts.iter().map(|layout| &layout.sym).collect();
    let bases = relative_table_bases(elf, &symbols, section_index)?.0;
    let mut result = Vec::new();
    for (at, relocation) in relocations {
        if !matches!(relocation.flags(), RelocationFlags::Elf { r_type: 2 }) ||
            relocation.has_implicit_addend() || at.checked_add(4).is_none_or(|limit| limit > end)
        { bail!("unsupported nested read-only relocation in {owner} at {at:#x}"); }
        let RelocationTarget::Symbol(index) = relocation.target() else {
            bail!("nested read-only relocation requires a symbol target");
        };
        let target = elf.symbol_by_index(index)?;
        let base = *bases.iter().rev().find(|base| **base <= at && **base >= start)
            .ok_or_else(|| anyhow!("nested PC32 code relocation in {owner} has no relative jump-table base"))?;
        if (at - base) % 4 != 0 { bail!("misaligned relative jump-table entry in {owner}"); }
        let address = i128::from(target.address()) + i128::from(relocation.addend()) - i128::from(at - base);
        let destination = layouts.iter().find(|layout|
            Some(layout.sym.section_index) == target.section_index() &&
            address >= i128::from(layout.sym.address) && address < i128::from(layout.sym.address + layout.sym.size))
            .ok_or_else(|| anyhow!("relative jump table {owner} targets code outside the included symbols"))?;
        let source_offset = u64::try_from(address - i128::from(destination.sym.address))?;
        let index = destination.insn_local_ip.iter().position(|offset| *offset == source_offset)
            .ok_or_else(|| anyhow!("relative jump table {owner} targets a removed or interior instruction"))?;
        let encoded = destination.new_offset_in_sym[index];
        if encoded == u32::MAX { bail!("relative jump-table target has no rewritten instruction"); }
        result.push(CodeReloc {
            proof: ProofDataReloc { owner: owner.to_owned(), offset: at - start, r_type: 2,
                symbol: destination.sym.name.clone(), addend: i64::try_from(u64::from(encoded) + at - base)? },
            target_offset: u64::try_from(destination.base_in_blob)?.checked_add(u64::from(encoded))
                .ok_or_else(|| anyhow!("relative table code offset overflow"))?,
            table_offset: base - start,
        });
    }
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn fixture(interior: bool, base: u64) -> Result<Vec<u8>> {
        let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
        let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
        let data = object.add_section(Vec::new(), b".rodata".to_vec(), SectionKind::ReadOnlyData);
        let bytes = [0x48,0x8d,0x0d,0,0,0,0, 0x48,0x63,0x04,0x81, 0x48,0x01,0xc8,
            0xff,0xe0, 0xb8,1,0,0,0,0xc3, 0xb8,2,0,0,0,0xc3];
        object.append_section_data(text, &bytes, 1);
        object.append_section_data(data, &vec![0; base as usize + 8], 4);
        let entry = object.add_symbol(WriteSymbol { name: b"entry".to_vec(), value: 0, size: 28,
            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Section(text), flags: SymbolFlags::None });
        let table = object.section_symbol(data);
        object.add_relocation(text, WriteRelocation { offset: 3, symbol: table, addend: base as i64 - 4,
            flags: RelocationFlags::Elf { r_type: 2 } })?;
        for (offset, addend) in [(0, if interior { 17 } else { 16 }), (4, 26)] {
            object.add_relocation(data, WriteRelocation { offset: base + offset, symbol: entry, addend,
                flags: RelocationFlags::Elf { r_type: 2 } })?;
        }
        Ok(object.write()?)
    }

    #[test]
    fn relative_tables_use_rewritten_target_offsets_and_preserve_slot_bias() -> Result<()> {
        for (interior, base) in [(false, 0), (false, 8), (true, 0)] {
            let bytes = fixture(interior, base)?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, "entry")?;
            let layout = SymbolLayout { sym: entry, base_in_blob: 99,
                insn_local_ip: vec![0,7,11,14,16,21,22,27],
                new_offset_in_sym: vec![0,7,11,14,30,35,40,45] };
            let data = elf.section_by_name(".rodata").unwrap();
            let result = code_relocations(&elf, &[layout], data.index(), base, 8, "table");
            if interior { assert!(result.is_err()); continue; }
            let result = result?;
            assert_eq!(result.iter().map(|r| (r.proof.offset, r.proof.symbol.as_str(), r.proof.addend)).collect::<Vec<_>>(),
                vec![(0,"entry",30),(4,"entry",44)]);
            assert_eq!(result.iter().map(|r| (r.target_offset,r.table_offset)).collect::<Vec<_>>(),
                vec![(129,0),(139,0)]);
        }
        Ok(())
    }

    #[test]
    fn table_shape_does_not_authorize_unbound_code_or_another_jump_register() -> Result<()> {
        for wrong_register in [false, true] {
            let mut bytes = fixture(false, 0)?;
            let elf = object::File::parse(bytes.as_slice())?;
            if wrong_register {
                let (offset, _) = elf.section_by_name(".text").unwrap().file_range().unwrap();
                bytes[offset as usize + 15] = 0xe1; // JMP RCX instead of table result RAX.
            } else {
                let (offset, _) = elf.section_by_name(".rela.rodata").unwrap().file_range().unwrap();
                let field = offset as usize + 8;
                let info = u64::from_le_bytes(bytes[field..field + 8].try_into()?);
                bytes[field..field + 8].copy_from_slice(&((info & !0xffff_ffff) | 1).to_le_bytes());
            }
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, "entry")?;
            let sites = indirect_sites(&elf, &[entry.clone()]);
            if !wrong_register { assert!(sites.is_err()); continue; }
            assert!(sites?.is_empty());
            let code = read_symbol_bytes(&elf, &entry)?;
            let jump = Decoder::new(64, &code, DecoderOptions::NONE).into_iter()
                .find(|i| i.flow_control() == FlowControl::IndirectBranch).unwrap();
            assert!(validate_no_external_refs(&jump, &[(0, 28)], |_| false).is_err());
        }
        Ok(())
    }
}
