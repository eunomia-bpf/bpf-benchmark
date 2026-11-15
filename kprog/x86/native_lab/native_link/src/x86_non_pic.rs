//! Non-PIC map addresses use full kernel pointers, including when the compiler
//! chose a zero/sign-extended 32-bit immediate for the relocatable address.
//! Proof objects normalize these to the existing symbolic GOT-load ABI; kernel
//! objects use the same MOVABS/map-patch contract as PIC map references.
use super::*;

pub(super) struct Reference {
    pub name: String,
    pub register: Register,
    pub relocation_offset: u64,
}

pub(super) fn references(
    elf: &object::File, included: &[SymInfo], maps: &HashMap<String, u64>,
) -> Result<HashMap<LocalSiteKey, Reference>> {
    let mut result = HashMap::new();
    for sym in included {
        let section = elf.section_by_index(sym.section_index)?;
        let bytes = read_symbol_bytes(elf, sym)?;
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
        let mut decoded = Vec::new();
        while decoder.can_decode() {
            let instruction = decoder.decode();
            if instruction.is_invalid() { bail!("invalid non-PIC instruction in {}", sym.name); }
            let offsets = decoder.get_constant_offsets(&instruction);
            decoded.push((instruction, offsets));
        }
        for (at, reloc) in section.relocations().filter(|(at, _)|
            *at >= sym.address && *at < sym.address + sym.size)
        {
            let RelocationFlags::Elf { r_type: kind @ (1 | 2 | 10 | 11) } = reloc.flags() else { continue; };
            let RelocationTarget::Symbol(index) = reloc.target() else { continue; };
            let target = elf.symbol_by_index(index)?;
            let name = target.name()?;
            let declared_map = target.section_index()
                .map(|i| elf.section_by_index(i)).transpose()?
                .map(|s| s.name().map(|n| n == ".maps" || n == "maps"))
                .transpose()?.unwrap_or(false);
            if !declared_map && !maps.contains_key(name) { continue; }
            let (insn, offsets) = decoded.iter().find(|(i, _)| i.ip() <= at && at < i.next_ip())
                .ok_or_else(|| anyhow!("non-PIC map relocation outside {}", sym.name))?;
            // PC-relative data reads/writes keep their existing DATASEC path.
            if kind == 2 && insn.mnemonic() != Mnemonic::Lea { continue; }
            let addend = i128::from(reloc.addend()) + if kind == 2 {
                i128::from(insn.next_ip() - at)
            } else { 0 };
            // The loader's address namespace also contains DATASEC variables.
            // Their indexed PC32 addresses already have a live-value lowering;
            // do not mistake such a member address for an interior map handle.
            if kind == 2 && addend != 0 && !declared_map { continue; }
            if addend != 0 || reloc.has_implicit_addend() {
                bail!("non-PIC map address {name} requires an explicit zero address addend");
            }
            let register = x86_gpr64_family(insn.op0_register())
                .ok_or_else(|| anyhow!("non-PIC map address {name} requires a GPR destination"))?;
            let expected = if kind == 1 { 8 } else { 4 };
            let valid = if kind == 2 {
                insn.mnemonic() == Mnemonic::Lea && insn.is_ip_rel_memory_operand() &&
                insn.op0_register() == register && offsets.displacement_size() == 4 &&
                at == insn.ip() + offsets.displacement_offset() as u64
            } else {
                insn.mnemonic() == Mnemonic::Mov &&
                matches!(insn.op1_kind(), OpKind::Immediate32 | OpKind::Immediate32to64 | OpKind::Immediate64) &&
                at == insn.ip() + offsets.immediate_offset() as u64 &&
                offsets.immediate_size() == expected &&
                (kind != 1 || insn.op1_kind() == OpKind::Immediate64) &&
                (kind != 10 || insn.op1_kind() == OpKind::Immediate32) &&
                (kind != 11 || insn.op1_kind() == OpKind::Immediate32to64)
            };
            if !valid || insn.op_count() != 2 || insn.op0_kind() != OpKind::Register
            {
                bail!("unsupported non-PIC map address {name}: relocation {kind} at {at:#x} in {}", sym.name);
            }
            if result.insert(local_site_key(sym, insn.ip() - sym.address), Reference {
                name: name.to_owned(), register, relocation_offset: at - sym.address,
            }).is_some() { bail!("multiple non-PIC map relocations in one instruction"); }
        }
    }
    Ok(result)
}

pub(super) fn address(
    reference: &Reference, proof: bool,
) -> Result<(Instruction, PatchKind)> {
    if !proof {
        return Ok((build_x86_movabs_reg(reference.register, 0)?,
            PatchKind::MapImmediate { name: reference.name.clone(), imm_offset: 2 }));
    }
    let (low, high) = x86_gpr64_encoding(reference.register)?;
    let bytes = [0x48 | if high { 4 } else { 0 }, 0x8b, 0x05 | (low << 3), 0, 0, 0, 0];
    Ok((declared_bytes(&bytes)?, PatchKind::ProofMapAddress { name: reference.name.clone() }))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn fixture(kind: u32, bytes: &[u8], offset: u64, addend: i64) -> Result<Vec<u8>> {
        let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
        let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
        let maps = object.add_section(Vec::new(), b".maps".to_vec(), SectionKind::Data);
        object.append_section_data(text, bytes, 1);
        object.append_section_data(maps, &[0; 32], 8);
        object.add_symbol(WriteSymbol { name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Section(text), flags: SymbolFlags::None });
        let map = object.add_symbol(WriteSymbol { name: b"map".to_vec(), value: 0, size: 32,
            kind: SymbolKind::Data, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Section(maps), flags: SymbolFlags::None });
        object.add_relocation(text, WriteRelocation { offset, symbol: map, addend,
            flags: RelocationFlags::Elf { r_type: kind } })?;
        Ok(object.write()?)
    }

    fn link(data: &[u8], proof: bool, maps: &HashMap<String, u64>) -> Result<RewriteResult> {
        let elf = object::File::parse(data)?;
        let entry = find_symbol_by_name(&elf, "entry")?;
        rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), maps, &HashMap::new(), &[], proof, false, None,
            false, None, None, None, false, false, false)
    }

    #[test]
    fn non_pic_maps_preserve_high_pointer_bits_and_existing_proof_abi() -> Result<()> {
        // Bug: applying an ELF32 immediate literally truncates a live kernel map
        // pointer. Cover zero-extension, sign-extension and large-code-model MOV.
        for (kind, bytes, offset, addend) in [
            (10, vec![0xb8, 0, 0, 0, 0, 0xc3], 1, 0),
            (11, vec![0x48, 0xc7, 0xc0, 0, 0, 0, 0, 0xc3], 3, 0),
            (1, vec![0x48, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0xc3], 2, 0),
            (2, vec![0x48, 0x8d, 0x05, 0, 0, 0, 0, 0xc3], 3, -4),
        ] {
            let data = fixture(kind, &bytes, offset, addend)?;
            let maps = HashMap::from([("map".to_owned(), 0xffff_8880_1234_5678)]);
            let kernel = link(&data, false, &maps)?;
            assert_eq!(kernel.map_patches.len(), 1);
            let patch = &kernel.map_patches[0];
            assert_eq!((&patch.name, patch.offset), (&"map".to_owned(), 2));
            assert_eq!(&kernel.blob[..2], &[0x48, 0xb8]);
            assert!(kernel.relocs.is_empty());
            let proof = link(&data, true, &HashMap::new())?;
            assert_eq!(&proof.blob[..3], &[0x48, 0x8b, 0x05]);
            assert_eq!(proof.proof_relocs.len(), 1);
            let reloc = &proof.proof_relocs[0];
            assert_eq!((reloc.offset, reloc.r_type, reloc.symbol.as_str(), reloc.addend), (3, 9, "map", -4));
            #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
            {
                // Execute the emitted MOVABS after the same eight-byte patch
                // the loader applies; use a real pointer above the 32-bit range.
                let value = [0xabu8; 1];
                let address = value.as_ptr() as u64;
                assert!(address > u32::MAX as u64);
                let mut code = kernel.blob;
                code[patch.offset..patch.offset + 8].copy_from_slice(&address.to_le_bytes());
                code.push(0xc3);
                assert_eq!(memory::call_blob(&code, std::ptr::null_mut(), 0, 0) as u64, address);
            }
        }
        Ok(())
    }

    #[test]
    fn non_pic_maps_reject_interior_addresses_and_mismatched_relocation_fields() -> Result<()> {
        let maps = HashMap::from([("map".to_owned(), 0xffff_8880_0000_0000)]);
        for (bytes, offset, addend) in [
            (vec![0xb8, 0, 0, 0, 0, 0xc3], 1, 8),
            (vec![0xb8, 0, 0, 0, 0, 0xc3], 0, 0),
            (vec![0x48, 0x8b, 0x04, 0x25, 0, 0, 0, 0, 0xc3], 4, 0),
        ] {
            let data = fixture(10, &bytes, offset, addend)?;
            assert!(link(&data, false, &maps).is_err());
        }
        Ok(())
    }

    #[test]
    fn pc32_datasec_member_keeps_existing_live_value_lowering() -> Result<()> {
        let mut data = fixture(2, &[0x48, 0x8d, 0x05, 0, 0, 0, 0, 0xc3], 3, 4)?;
        let name = data.windows(6).position(|bytes| bytes == b".maps\0")
            .ok_or_else(|| anyhow!("fixture lacks map section name"))?;
        data[name..name + 5].copy_from_slice(b".data");
        let elf = object::File::parse(data.as_slice())?;
        let entry = find_symbol_by_name(&elf, "entry")?;
        let maps = HashMap::from([("map".to_owned(), 0xffff_8880_0000_0000)]);
        assert!(references(&elf, &[entry.clone()], &maps)?.is_empty());
        let writable = writable_data::references(&elf, &[entry.clone()])?;
        let value = writable.get(&local_site_key(&entry, 3))
            .ok_or_else(|| anyhow!("live DATASEC member lost its binding"))?;
        assert_eq!((value.name.as_str(), value.offset), ("map", 8));
        Ok(())
    }
}
