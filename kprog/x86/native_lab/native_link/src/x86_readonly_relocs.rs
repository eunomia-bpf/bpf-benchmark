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
        for (start, lea) in instructions.iter().enumerate() {
            if lea.mnemonic() != Mnemonic::Lea || !lea.is_ip_rel_memory_operand() ||
                lea.op0_kind() != OpKind::Register ||
                x86_gpr64_family(lea.op0_register()) != Some(lea.op0_register())
            { continue; }
            // The dispatch of this base is emitted after its `lea`, sometimes
            // several switches later, so follow the fact forward over the
            // emitted stream instead of walking the CFG.
            let dispatches = base_dispatches(&instructions, start,
                InstructionInfoFactory::new());
            if dispatches.is_empty() { continue; }
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
                for dispatch in &dispatches {
                    sites.insert(local_site_key(sym, *dispatch - sym.address));
                }
            }
        }
    }
    bases.sort_unstable();
    bases.dedup();
    Ok((bases, sites))
}

// Facts about where a table base and a formed table target live. The compiler
// copies the base before use, overwrites it with the loaded slot, and reuses
// the loaded register as the target, so identity must follow the data, not the
// register names the form happened to use.
#[derive(Clone, PartialEq, Eq)]
struct TableState {
    base: HashSet<Register>,
    loaded: Option<Register>,
    formed: HashSet<Register>,
}


fn table_transfer(insn: &Instruction, state: &mut TableState,
    factory: &mut InstructionInfoFactory) {
    if insn.mnemonic() == Mnemonic::Movsxd && insn.op0_kind() == OpKind::Register &&
        insn.op1_kind() == OpKind::Memory && state.base.contains(&insn.memory_base()) &&
        insn.memory_index() != Register::None && insn.memory_index_scale() == 4 &&
        insn.memory_displacement64() == 0 && insn.segment_prefix() == Register::None
    {
        let dst = insn.op0_register();
        state.base.remove(&dst);
        state.formed.remove(&dst);
        state.loaded = Some(dst);
        return;
    }
    if let Some((dst, src)) = x86_mov_gpr64_to_gpr64(insn) {
        if state.base.contains(&src) { state.base.insert(dst); } else { state.base.remove(&dst); }
        if state.formed.contains(&src) { state.formed.insert(dst); } else { state.formed.remove(&dst); }
        if state.loaded == Some(src) { state.loaded = Some(dst); }
        else if state.loaded == Some(dst) { state.loaded = None; }
        return;
    }
    if insn.mnemonic() == Mnemonic::Add && insn.op0_kind() == OpKind::Register &&
        insn.op1_kind() == OpKind::Register && insn.op0_register().size() == 8 &&
        state.base.contains(&insn.op1_register()) && state.loaded == Some(insn.op0_register())
    {
        let dst = insn.op0_register();
        state.base.remove(&dst);
        state.formed.insert(dst);
        state.loaded = None;
        return;
    }
    for used in factory.info(insn).used_registers() {
        if !matches!(used.access(), OpAccess::Write | OpAccess::CondWrite |
            OpAccess::ReadWrite | OpAccess::ReadCondWrite) { continue; }
        let reg = used.register();
        state.base.remove(&reg);
        state.formed.remove(&reg);
        if state.loaded == Some(reg) { state.loaded = None; }
    }
}

// The indirect branch that dispatches on an address formed from this `lea`.
// The base is emitted once and consumed after the switch bodies it selects, so
// the fact is followed over the emitted stream; it dies when the register that
// holds it is written.
fn base_dispatches(instructions: &[Instruction], start: usize,
    mut factory: InstructionInfoFactory) -> HashSet<u64> {
    let mut dispatches = HashSet::new();
    let mut state = TableState { base: HashSet::from([instructions[start].op0_register()]),
        loaded: None, formed: HashSet::new() };
    for insn in &instructions[start+1..] {
        if insn.flow_control() == FlowControl::IndirectBranch && insn.op0_kind() == OpKind::Register
            && state.formed.contains(&insn.op0_register()) {
            dispatches.insert(insn.ip());
            break;
        }
        table_transfer(insn, &mut state, &mut factory);
        if state.base.is_empty() && state.formed.is_empty() && state.loaded.is_none() { break; }
    }
    dispatches
}

fn absolute_table_bases(
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
        for window in instructions.windows(2) {
            let [lea, jump] = window else { unreachable!() };
            if lea.mnemonic() != Mnemonic::Lea || !lea.is_ip_rel_memory_operand() ||
                lea.op0_kind() != OpKind::Register ||
                x86_gpr64_family(lea.op0_register()) != Some(lea.op0_register()) ||
                jump.flow_control() != FlowControl::IndirectBranch ||
                jump.op0_kind() != OpKind::Memory || jump.memory_base() != lea.op0_register() ||
                jump.memory_index() == Register::None || jump.memory_index_scale() != 8 ||
                jump.memory_displacement64() != 0 || jump.segment_prefix() != Register::None
            { continue; }
            for (at, relocation) in section.relocations().filter(|(at, _)|
                *at >= lea.ip() && *at < lea.next_ip()) {
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
                { bail!("absolute table base lacks an explicit PC32 displacement"); }
                let base = i128::from(target.address()) + i128::from(relocation.addend()) +
                    i128::from(lea.next_ip()-at) - i128::from(data.address());
                let base = u64::try_from(base).map_err(|_| anyhow!("absolute table base out of range"))?;
                let mut code_entry = false;
                for (_, entry) in data.relocations().filter(|(at, _)| *at == base) {
                    if !matches!(entry.flags(), RelocationFlags::Elf { r_type: 1 }) { continue; }
                    let RelocationTarget::Symbol(index) = entry.target() else { continue; };
                    if let Some(section) = elf.symbol_by_index(index)?.section_index() {
                        code_entry |= elf.section_by_index(section)?.kind() == SectionKind::Text;
                    }
                }
                if !code_entry { bail!("absolute jump-table base has no full-pointer code entry"); }
                bases.push(base);
                sites.insert(local_site_key(sym, jump.ip()-sym.address));
            }
        }
    }
    bases.sort_unstable(); bases.dedup();
    Ok((bases, sites))
}

fn code_table_bases(elf: &object::File, symbols: &[&SymInfo], section: object::SectionIndex)
    -> Result<(Vec<(u64, u32)>, HashSet<LocalSiteKey>)> {
    let (relative, mut sites) = relative_table_bases(elf, symbols, section)?;
    let (absolute, absolute_sites) = absolute_table_bases(elf, symbols, section)?;
    sites.extend(absolute_sites);
    let mut bases: Vec<_> = relative.into_iter().map(|base| (base, 2))
        .chain(absolute.into_iter().map(|base| (base, 1))).collect();
    bases.sort_unstable(); bases.dedup();
    Ok((bases, sites))
}

pub(super) fn indirect_sites(elf: &object::File, included: &[SymInfo])
    -> Result<HashSet<LocalSiteKey>> {
    let symbols: Vec<_> = included.iter().collect();
    let mut sites = HashSet::new();
    for section in elf.sections() {
        if !immutable_section(section.kind(), section.name()?) || section.relocations().next().is_none() { continue; }
        sites.extend(code_table_bases(elf, &symbols, section.index())?.1);
    }
    Ok(sites)
}

// Every code table in the object, keyed by its base, so one function's table
// ends where the next function's table begins.
fn text_table_bases(elf: &object::File, section: object::SectionIndex)
    -> Result<Vec<(u64, u32)>> {
    let mut symbols = Vec::new();
    for symbol in elf.symbols().filter(|symbol|
        symbol.kind() == object::SymbolKind::Text && !symbol.is_undefined() && symbol.size() > 0) {
        if let Some(index) = symbol.section_index() {
            symbols.push(SymInfo { name: symbol.name()?.to_owned(), section_index: index,
                address: symbol.address(), size: symbol.size() });
        }
    }
    let symbols: Vec<_> = symbols.iter().collect();
    Ok(code_table_bases(elf, &symbols, section)?.0)
}

// Conservative union of the actual relative-table destinations of this
// function. A shared successor set may lose precision, never add a helper fact.
pub(super) fn control_targets(elf: &object::File, sym: &SymInfo)
    -> Result<HashMap<u64, Vec<u64>>> {
    let mut result = HashMap::new();
    for section in elf.sections() {
        if !immutable_section(section.kind(), section.name()?) || section.relocations().next().is_none() { continue; }
        let (bases, sites) = code_table_bases(elf, &[sym], section.index())?;
        if sites.is_empty() { continue; }
        // Slots of one table are contiguous from its base to the next table in
        // the object. Reading the whole section under this symbol's bases would
        // reinterpret a neighbouring table's addends against the wrong base and
        // invent targets inside this function.
        let limits = text_table_bases(elf, section.index())?;
        let relocations: BTreeMap<_, _> = section.relocations().collect();
        let mut targets = Vec::new();
        for (base, kind) in &bases {
            let width = if *kind == 1 { 8 } else { 4 };
            let limit = limits.iter().map(|(at, _)| *at).filter(|at| at > base)
                .min().unwrap_or(section.size());
            let mut at = *base;
            while at.checked_add(width).is_some_and(|end| end <= limit) {
                let Some(relocation) = relocations.get(&at) else { break; };
                if !matches!(relocation.flags(), RelocationFlags::Elf { r_type } if r_type == *kind) ||
                    relocation.has_implicit_addend() { break; }
                let RelocationTarget::Symbol(index) = relocation.target() else { break; };
                let target = elf.symbol_by_index(index)?;
                if target.section_index() != Some(sym.section_index) { break; }
                let address = i128::from(target.address()) + i128::from(relocation.addend()) -
                    if *kind == 2 { i128::from(at-base) } else { 0 };
                if address >= i128::from(sym.address) && address < i128::from(sym.address+sym.size) {
                    targets.push(u64::try_from(address)?);
                }
                at += width;
            }
        }
        targets.sort_unstable(); targets.dedup();
        for (_, _, site) in sites { result.insert(sym.address+site, targets.clone()); }
    }
    Ok(result)
}

// Anonymous section symbols are containers, not individual compiler tables.
// Copy only the referenced table's contiguous relocation slots, bounded also
// by the next table of any entry point in the source object.
pub(super) fn table_span(elf: &object::File, layouts: &[SymbolLayout],
    section_index: object::SectionIndex, address: i128) -> Result<Option<(u64, u64)>> {
    if let Some(span) = code_table_span(elf, layouts, section_index, address)? {
        return Ok(Some(span));
    }
    let section = elf.section_by_index(section_index)?;
    if !immutable_section(section.kind(), section.name()?) { return Ok(None); }
    let Ok(address) = u64::try_from(address) else { return Ok(None); };
    // A section-symbol relocation can point into a named scalar object. Its
    // ELF extent is the same boundary used for a direct symbol relocation;
    // copying the container would pull in unrelated roots' code tables.
    // Overlapping aliases retain the union of the containing object extents.
    let mut extent: Option<(u64, u64)> = None;
    for symbol in elf.symbols().filter(|symbol| symbol.kind() == SymbolKind::Data &&
        symbol.section_index() == Some(section_index) && symbol.size() > 0) {
        let start = symbol.address().checked_sub(section.address())
            .ok_or_else(|| anyhow!("read-only object is below its section base"))?;
        let end = start.checked_add(symbol.size())
            .ok_or_else(|| anyhow!("read-only object extent overflow"))?;
        if start <= address && address < end {
            extent = Some(match extent {
                Some((first, last)) => (first.min(start), last.max(end)),
                None => (start, end),
            });
        }
    }
    Ok(extent.map(|(start, end)| (start, end - start)))
}

fn code_table_span(elf: &object::File, layouts: &[SymbolLayout],
    section_index: object::SectionIndex, address: i128) -> Result<Option<(u64, u64)>> {
    let Ok(base) = u64::try_from(address) else { return Ok(None); };
    let included: Vec<_> = layouts.iter().map(|layout| &layout.sym).collect();
    let bases = code_table_bases(elf, &included, section_index)?.0;
    let Some((_, kind)) = bases.iter().find(|(at, _)| *at == base) else { return Ok(None); };
    let width = if *kind == 1 { 8 } else { 4 };
    let section = elf.section_by_index(section_index)?;
    let next = text_table_bases(elf, section_index)?.into_iter()
        .map(|(at, _)| at).filter(|at| *at > base).min().unwrap_or(section.size());
    let relocations: BTreeMap<_, _> = section.relocations().collect();
    let mut end = base;
    while end.checked_add(width).is_some_and(|limit| limit <= next) {
        let Some(relocation) = relocations.get(&end) else { break; };
        if !matches!(relocation.flags(), RelocationFlags::Elf { r_type } if r_type == *kind) || relocation.has_implicit_addend() { break; }
        let RelocationTarget::Symbol(index) = relocation.target() else { break; };
        let Some(index) = elf.symbol_by_index(index)?.section_index() else { break; };
        if elf.section_by_index(index)?.kind() != SectionKind::Text { break; }
        end += width;
    }
    if end == base { bail!("referenced code table has no complete relocation slots"); }
    Ok(Some((base, end-base)))
}

pub(super) enum DataReloc {
    RelativeCode { proof: ProofDataReloc, target_offset: u64, table_offset: u64 },
    AbsoluteCode { proof: ProofDataReloc, target_offset: u64 },
    MapPointer(ProofDataReloc),
}

impl DataReloc {
    pub fn proof(self) -> ProofDataReloc {
        match self { Self::RelativeCode { proof, .. } | Self::AbsoluteCode { proof, .. } | Self::MapPointer(proof) => proof }
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
            if let Some(index) = target.section_index() {
                if elf.section_by_index(index)?.kind() == SectionKind::Text {
                    if relocation.has_implicit_addend() || at.checked_add(8).is_none_or(|limit| limit > end) {
                        bail!("absolute code table needs an explicit full-pointer slot");
                    }
                    let address = i128::from(target.address()) + i128::from(relocation.addend());
                    let destination = layouts.iter().find(|layout|
                        layout.sym.section_index == index && address >= i128::from(layout.sym.address) &&
                        address < i128::from(layout.sym.address + layout.sym.size))
                        .ok_or_else(|| anyhow!("absolute code table targets code outside the included symbols"))?;
                    let source_offset = u64::try_from(address-i128::from(destination.sym.address))?;
                    let instruction = destination.insn_local_ip.iter().position(|offset| *offset == source_offset)
                        .ok_or_else(|| anyhow!("absolute code table targets a removed or interior instruction"))?;
                    let encoded = destination.new_offset_in_sym[instruction];
                    if encoded == u32::MAX { bail!("absolute code-table target has no rewritten instruction"); }
                    result.push(DataReloc::AbsoluteCode {
                        proof: ProofDataReloc { owner: owner.to_owned(), offset: at-start, r_type: 1,
                            symbol: destination.sym.name.clone(), addend: i64::from(encoded) },
                        target_offset: u64::try_from(destination.base_in_blob)?.checked_add(u64::from(encoded))
                            .ok_or_else(|| anyhow!("absolute table code offset overflow"))?,
                    });
                    continue;
                }
            }
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
