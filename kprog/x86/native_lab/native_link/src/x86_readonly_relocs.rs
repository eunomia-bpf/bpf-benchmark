//! Preserve code and live-map identities in immutable compiler tables.
//! Relative code addends refer to source instructions, not the rewritten layout.
use super::*;

pub(super) fn immutable_section(kind: SectionKind, name: &str) -> bool {
    kind == SectionKind::ReadOnlyData || name == ".data.rel.ro" || name.starts_with(".data.rel.ro.")
}

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

pub(super) enum DataReloc {
    RelativeCode { proof: ProofDataReloc, target_offset: u64, table_offset: u64 },
    MapPointer(ProofDataReloc),
}

impl DataReloc {
    pub fn proof(self) -> ProofDataReloc {
        match self { Self::RelativeCode { proof, .. } | Self::MapPointer(proof) => proof }
    }
}

pub(super) fn data_relocations(
    elf: &object::File, layouts: &[SymbolLayout], section_index: object::SectionIndex,
    start: u64, size: u64, owner: &str, maps: &HashMap<String, u64>,
) -> Result<Vec<DataReloc>> {
    let section = elf.section_by_index(section_index)?;
    let end = start.checked_add(size).ok_or_else(|| anyhow!("proof data range overflow"))?;
    let relocations: Vec<_> = section.relocations().filter(|(at, _)| *at >= start && *at < end).collect();
    if relocations.is_empty() { return Ok(Vec::new()); }
    let symbols: Vec<_> = layouts.iter().map(|layout| &layout.sym).collect();
    let bases = relative_table_bases(elf, &symbols, section_index)?.0;
    let mut result = Vec::new();
    for (at, relocation) in relocations {
        if matches!(relocation.flags(), RelocationFlags::Elf { r_type: 1 }) {
            let RelocationTarget::Symbol(index) = relocation.target() else {
                bail!("nested map pointer requires a symbol target");
            };
            let target = elf.symbol_by_index(index)?;
            let name = target.name()?;
            let declared_data = match target.section_index() {
                Some(index) => {
                    let target_section = elf.section_by_index(index)?;
                    matches!(target_section.kind(), SectionKind::Data | SectionKind::UninitializedData) &&
                        !immutable_section(target_section.kind(), target_section.name()?) &&
                        target.kind() == SymbolKind::Data
                }
                None => target.is_undefined() && target.kind() != SymbolKind::Text,
            };
            if name.is_empty() || (!declared_data && !maps.contains_key(name)) {
                bail!("nested absolute read-only relocation {owner} does not name a live map/data capability");
            }
            if relocation.has_implicit_addend() || relocation.addend() != 0 ||
                at.checked_add(8).is_none_or(|limit| limit > end) {
                bail!("nested map address {name} requires an explicit zero address addend and full pointer slot");
            }
            result.push(DataReloc::MapPointer(ProofDataReloc {
                owner: owner.to_owned(), offset: at - start, r_type: 1,
                symbol: name.to_owned(), addend: 0,
            }));
            continue;
        }
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
        result.push(DataReloc::RelativeCode {
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

    #[test]
    fn compiler_relro_lookup_keeps_map_choices_and_helper_in_proof() -> Result<()> {
        // Bug: pointer-table support must also survive a real helper consumer,
        // not merely a pointer-valued component return that BPF cannot accept.
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/map-table-lookup");
        fs::create_dir_all(build)?;
        let native = build.join("lookup.native.o");
        let command = ["clang-18", "-target", "x86_64-linux-gnu", "-O3", "-march=native",
            "-foptimize-sibling-calls", "-fomit-frame-pointer", "-mno-red-zone", "-mgeneral-regs-only",
            "-fno-stack-protector", "-g", "-I/workspaces/repository/vendor/libbpf/src",
            "-c", "/workspaces/repository/kprog/test/native_map_lookup_table.c",
            "-o", native.to_str().ok_or_else(|| anyhow!("lookup fixture path is not UTF-8"))?];
        fs::write(build.join("compile-command.json"), serde_json::to_vec(&command)?)?;
        let compiled = std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !compiled.status.success() { bail!("clang lookup fixture failed: {}", String::from_utf8_lossy(&compiled.stderr)); }
        let bytes = fs::read(&native)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "map_lookup_table")?;
        let maps: HashMap<_, _> = (0..8).map(|index| (format!("map{index}"), 0x100000000u64 + index * 32)).collect();
        let proof = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &maps,
            &HashMap::new(), &[], true, true, None, None, None, None, false)?;
        assert_eq!(proof.proof_data_relocs.len(), 8);
        assert!(proof.proof_data_relocs.iter().all(|item|
            item.r_type == 1 && item.addend == 0 && maps.contains_key(&item.symbol)));
        // Libbpf's numeric helper ABI remains MOV EAX,1; CALL RAX in proof
        // mode. It does not acquire a named ELF helper relocation.
        assert!(proof.blob.windows(7).any(|bytes| bytes == [0xb8, 1, 0, 0, 0, 0xff, 0xd0]));
        let path = build.join("trusted_x86.proof.o");
        write_proof_object(&path, object::Architecture::X86_64,
            "map_lookup_table", &proof.blob, &proof.proof_symbols, &proof.proof_relocs,
            &proof.proof_data_relocs, proof.callee_saved_mask)?;
        let bytes = fs::read(path)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "map_lookup_table")?;
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let helpers = HashMap::from([("bpf_map_lookup_elem".to_owned(), 0x1234)]);
        let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &maps,
            &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false)?;
        assert_eq!(linked.map_patches.len(), 8);
        assert!(linked.relocs.iter().all(|item|
            item.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32 && item.target == 0x1234));
        fs::write(build.join("lookup.kernel.bin"), &linked.blob)?;
        fs::write(build.join("lookup.map-patches.tsv"), linked.map_patches.iter()
            .map(|patch| format!("{}\t{}\n", patch.name, patch.offset)).collect::<String>())?;
        fs::write(build.join("lookup.helper-slots.json"), serde_json::to_vec(
            &linked.relocs.iter().map(|item| item.offset).collect::<Vec<_>>())?)?;
        fs::write(build.join("proof-result.json"), serde_json::to_vec_pretty(&serde_json::json!({
            "map_slots": 8, "helper": "bpf_map_lookup_elem",
            "scope": "Actual clang lookup consumer through production proof writer; not BPF acceptance"
        }))?)?;
        Ok(())
    }

    #[test]
    fn compiler_relro_map_table_keeps_live_pointer_slots_through_proof() -> Result<()> {
        // Bug: treating the anonymous RELRO table as mutable DATASEC either
        // rejects valid clang output or freezes zero placeholders as pointers.
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/map-pointer-tables");
        fs::create_dir_all(build)?;
        let native = build.join("fixture.native.o");
        let command = ["clang-18", "-target", "x86_64-linux-gnu", "-O3", "-march=native",
            "-foptimize-sibling-calls", "-fomit-frame-pointer", "-mno-red-zone", "-mgeneral-regs-only",
            "-fno-stack-protector", "-c", "/workspaces/repository/kprog/test/native_map_pointer_table.c",
            "-o", native.to_str().ok_or_else(|| anyhow!("native fixture path is not UTF-8"))?];
        fs::write(build.join("compile-command.json"), serde_json::to_vec(&command)?)?;
        let compiled = std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !compiled.status.success() { bail!("clang RELRO fixture failed: {}", String::from_utf8_lossy(&compiled.stderr)); }
        let bytes = fs::read(&native)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let table = elf.section_by_name(".data.rel.ro").ok_or_else(|| anyhow!("clang did not emit a RELRO table"))?;
        assert_eq!(table.relocations().count(), 8);
        let entry = find_symbol_by_name(&elf, "map_pointer_table")?;
        let empty = HashMap::new();
        let values = [[0xa5u8; 1]; 8];
        let maps: HashMap<_, _> = values.iter().enumerate()
            .map(|(index, value)| (format!("map{index}"), value.as_ptr() as u64)).collect();
        let proof = rewrite_x86(&elf, &entry, &[entry.clone()], &empty, &maps, &HashMap::new(),
            &[], true, true, None, None, None, None, false)?;
        assert_eq!(proof.proof_data_relocs.len(), 8);
        for relocation in &proof.proof_data_relocs {
            assert_eq!((relocation.r_type, relocation.addend), (1, 0));
            assert!(maps.contains_key(&relocation.symbol));
        }
        let proof_path = build.join("fixture.proof.o");
        write_proof_object(&proof_path, object::Architecture::X86_64, "map_pointer_table", &proof.blob,
            &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
        let bytes = fs::read(&proof_path)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "map_pointer_table")?;
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &empty, &maps, &HashMap::new(),
            &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false)?;
        assert_eq!(linked.map_patches.len(), 8);
        assert!(linked.relocs.is_empty());
        fs::write(build.join("fixture.kernel.bin"), &linked.blob)?;
        fs::write(build.join("fixture.map-patches.tsv"), linked.map_patches.iter()
            .map(|patch| format!("{}\t{}\n", patch.name, patch.offset)).collect::<String>())?;
        let mut missing = maps.clone();
        missing.remove("map3");
        let error = rewrite_x86(&elf, &entry, &[entry.clone()], &empty, &missing, &HashMap::new(),
            &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false).err()
            .ok_or_else(|| anyhow!("missing live map was silently embedded"))?;
        assert!(error.to_string().contains("unknown live map/data capability"));
        // Existing map-pointer ABI binds the exact handle. Do not silently
        // discard an ELF addend and return a different pointer.
        let mut altered = bytes.clone();
        let (relocation_offset, _) = elf.section_by_name(".rela.native_link_rodata")
            .ok_or_else(|| anyhow!("proof lost nested relocations"))?.file_range()
            .ok_or_else(|| anyhow!("nested relocation section has no file range"))?;
        altered[relocation_offset as usize + 16..relocation_offset as usize + 24]
            .copy_from_slice(&8i64.to_le_bytes());
        let invalid = object::File::parse(altered.as_slice())?;
        let invalid_entry = find_symbol_by_name(&invalid, "map_pointer_table")?;
        let error = rewrite_x86(&invalid, &invalid_entry, &[invalid_entry.clone()], &empty, &maps,
            &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false).err()
            .ok_or_else(|| anyhow!("nested map-pointer addend was silently dropped"))?;
        assert!(error.to_string().contains("explicit zero address addend"));
        let mut code = linked.blob;
        for patch in &linked.map_patches {
            code[patch.offset..patch.offset + 8].copy_from_slice(&maps[&patch.name].to_le_bytes());
        }
        code.push(0xc3);
        #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
        for index in [0u32,1,2,3,4,5,6,7,8,u32::MAX] {
            let expected = if index < 8 { values[index as usize].as_ptr() as u64 } else { 0 };
            let actual = memory::call_blob(&code, (&index as *const u32).cast_mut().cast(), 0, 0) as u64;
            assert_eq!(actual, expected);
            if index < 8 { assert!(actual > u32::MAX as u64); }
        }
        fs::write(build.join("result.json"), serde_json::to_vec_pretty(&serde_json::json!({
            "native_relro_slots": 8, "proof_map_relocations": 8, "kernel_map_patches": 8,
            "host_executions": 10, "normal_boot_facts": true,
            "missing_map_rejected": true, "interior_map_handle_rejected": true,
            "scope": "Actual clang output/proof/kernel rewrite and host pointer identity only; no B or app acceptance"
        }))?)?;
        Ok(())
    }

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
            let result = data_relocations(&elf, &[layout], data.index(), base, 8, "table", &HashMap::new());
            if interior { assert!(result.is_err()); continue; }
            let result = result?;
            assert_eq!(result.iter().map(|r| match r { DataReloc::RelativeCode { proof, .. } =>
                (proof.offset, proof.symbol.as_str(), proof.addend), _ => panic!("expected relative code") }).collect::<Vec<_>>(),
                vec![(0,"entry",30),(4,"entry",44)]);
            assert_eq!(result.iter().map(|r| match r { DataReloc::RelativeCode { target_offset, table_offset, .. } =>
                (*target_offset,*table_offset), _ => panic!("expected relative code") }).collect::<Vec<_>>(),
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
