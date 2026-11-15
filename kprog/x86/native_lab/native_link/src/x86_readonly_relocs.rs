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

    #[test]
    fn full_pointer_code_table_keeps_rewritten_instruction_identities() -> Result<()> {
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/absolute-code-tables");
        fs::create_dir_all(build)?;
        let native = build.join("absolute.native.o");
        let command = ["clang-18", "-target", "x86_64-linux-gnu", "-O3", "-march=native",
            "-foptimize-sibling-calls", "-fomit-frame-pointer", "-mno-red-zone",
            "-mgeneral-regs-only", "-fno-stack-protector", "-c",
            "/workspaces/repository/kprog/test/native_absolute_code_table.c", "-o",
            native.to_str().ok_or_else(|| anyhow!("absolute fixture path is not UTF-8"))?];
        let output = std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !output.status.success() { bail!("absolute fixture failed: {}", String::from_utf8_lossy(&output.stderr)); }
        fs::write(build.join("compile-command.json"), serde_json::to_vec(&command)?)?;
        let source = fs::read(native)?;
        let original = object::File::parse(source.as_slice())?;
        let entry = find_symbol_by_name(&original, "absolute_table")?;
        assert_eq!(control_targets(&original, &entry)?.values().next().map(Vec::len), Some(8));
        let proof = rewrite_x86(&original, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
            &HashMap::new(), &[], true, true, None, None, None, None, false)?;
        assert_eq!(proof.proof_data_relocs.len(), 8);
        assert!(proof.proof_data_relocs.iter().all(|reloc| reloc.r_type == 1));
        let path = build.join("absolute.proof.o");
        write_proof_object(&path, object::Architecture::X86_64, "absolute_table", &proof.blob,
            &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
        let bytes = fs::read(&path)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "absolute_table")?;
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
            &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false)?;
        assert_eq!(linked.relocs.len(), 8);
        assert!(linked.map_patches.is_empty());
        for record in &linked.relocs {
            assert_eq!(record.kind, NATIVE_LAB_RELOC_IMAGE_POINTER);
            assert!((record.target as usize) < linked.blob.len());
            assert_eq!(&linked.blob[record.offset as usize..record.offset as usize + 8], &[0;8]);
        }
        fs::write(build.join("absolute.bin"), &linked.blob)?;
        fs::write(build.join("rust-result.json"), serde_json::to_vec_pretty(&serde_json::json!({
            "proof_slots":8,"runtime_image_pointers":linked.relocs.iter().map(|r|
                serde_json::json!({"offset":r.offset,"kind":r.kind,"target":r.target})).collect::<Vec<_>>()
        }))?)?;
        let data = elf.section_by_name(".rela.native_link_rodata").ok_or_else(|| anyhow!("missing nested relocations"))?;
        let (start, _) = data.file_range().ok_or_else(|| anyhow!("missing nested relocation bytes"))?;
        let mut malformed = bytes;
        let at = start as usize + 16;
        let addend = i64::from_le_bytes(malformed[at..at+8].try_into()?);
        malformed[at..at+8].copy_from_slice(&(addend+1).to_le_bytes());
        let elf = object::File::parse(malformed.as_slice())?;
        let entry = find_symbol_by_name(&elf, "absolute_table")?;
        let error = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
            &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
            Some(&layout.hash), Some(&layout.lpm), false).err().ok_or_else(|| anyhow!("interior target accepted"))?;
        assert!(format!("{error:#}").contains("interior"));
        Ok(())
    }

    #[test]
    fn anonymous_section_data_reference_excludes_unrelated_code_tables() -> Result<()> {
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/scalar-rodata");
        fs::create_dir_all(build)?;
        let native = build.join("scalar.native.o");
        let command = ["clang-18", "-c", "/workspaces/repository/kprog/test/native_scalar_rodata.S",
            "-o", native.to_str().ok_or_else(|| anyhow!("scalar fixture path is not UTF-8"))?];
        let output = std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !output.status.success() { bail!("scalar fixture failed: {}", String::from_utf8_lossy(&output.stderr)); }
        fs::write(build.join("compile-command.json"), serde_json::to_vec(&command)?)?;
        let source = fs::read(native)?;
        let original = object::File::parse(source.as_slice())?;
        let data = original.section_by_name(".rodata").ok_or_else(|| anyhow!("fixture has no rodata"))?;
        assert_eq!(data.relocations().count(), 4);
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let mut rows = Vec::new();
        for (name, mask, bias) in [("scalar_lookup", 15u64, 0u32), ("scalar_interior_lookup", 7, 1)] {
            let entry = find_symbol_by_name(&original, name)?;
            let section = original.section_by_index(entry.section_index)?;
            let references: Vec<_> = section.relocations().filter(|(at, _)|
                *at >= entry.address && *at < entry.address + entry.size).collect();
            assert_eq!(references.len(), 1);
            let RelocationTarget::Symbol(index) = references[0].1.target() else { bail!("fixture target is not a symbol") };
            assert_eq!(original.symbol_by_index(index)?.kind(), SymbolKind::Section);
            let included = discover_reachable(&original, &entry)?;
            assert_eq!(included.len(), 1);
            let proof = rewrite_x86(&original, &entry, &included, &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], true, true, None, None, None, None, false)?;
            assert!(proof.proof_data_relocs.is_empty(), "scalar root copied another root's code entries");
            let values: Vec<_> = proof.proof_relocs.iter().filter_map(|r| r.data.as_ref()).collect();
            assert_eq!(values.len(), 1);
            assert_eq!(values[0].len(), 64, "did not retain the containing object extent");
            let path = build.join("scalar.proof.o");
            write_proof_object(&path, object::Architecture::X86_64, name, &proof.blob,
                &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
            let bytes = fs::read(path)?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, name)?;
            let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
                Some(&layout.hash), Some(&layout.lpm), false)?;
            assert!(linked.relocs.is_empty() && linked.map_patches.is_empty());
            let mut code = linked.blob; code.push(0xc3);
            for index in (0..32u64).chain((0..32).map(|i| i + (1u64 << 63))) {
                let mut context = [index];
                let actual = memory::call_blob(&code, context.as_mut_ptr().cast(), 0, 0) as usize as u32;
                assert_eq!(actual, 0x12340000 + (((index & mask) as u32) + bias) * 0x101);
            }
            rows.push(serde_json::json!({"symbol":name,"data_bytes":64,"proof_code_slots":0,"native_host_cases":64}));
        }
        fs::write(build.join("rust-result.json"), serde_json::to_vec_pretty(&rows)?)?;
        Ok(())
    }

    #[test]
    fn scheduled_code_identity_survives_index_overwrite_before_jump() -> Result<()> {
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/scheduled-table");
        fs::create_dir_all(build)?;
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let mut rows = Vec::new();
        for (name, selection) in [("clobber", "-DSCHEDULE_WRITE_TARGET"),
            ("flags", "-DSCHEDULE_READ_FLAGS"), ("scheduled", "-DSCHEDULE_NORMAL")] {
            let native = build.join("scheduled.native.o");
            let command = ["clang-18", "-target", "x86_64-linux-gnu", "-c", selection,
                "/workspaces/repository/kprog/test/native_scheduled_code_table.S",
                "-o", native.to_str().ok_or_else(|| anyhow!("scheduled fixture path is not UTF-8"))?];
            let compiled = std::process::Command::new(command[0]).args(&command[1..]).output()?;
            if !compiled.status.success() { bail!("scheduled fixture failed: {}", String::from_utf8_lossy(&compiled.stderr)); }
            let bytes = fs::read(&native)?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, "scheduled_table")?;
            let targets = control_targets(&elf, &entry)?;
            if name == "clobber" {
                assert!(targets.is_empty(), "overwritten destination retained a table identity");
                rows.push(serde_json::json!({"variant":name,"table_identity":false}));
                continue;
            }
            assert_eq!(targets.len(), 1);
            assert_eq!(targets.values().next().unwrap().len(), 4);
            let proof = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], true, true, None, None, None, None, false)?;
            assert_eq!(proof.proof_data_relocs.len(), 4);
            let path = build.join(format!("{name}.proof.o"));
            write_proof_object(&path, object::Architecture::X86_64, "scheduled_table", &proof.blob,
                &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
            let bytes = fs::read(path)?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, "scheduled_table")?;
            let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
                Some(&layout.hash), Some(&layout.lpm), false)?;
            let mut code = linked.blob; code.push(0xc3);
            if name == "scheduled" {
                for index in 0..64u64 {
                    let mut context = [index];
                    let actual = memory::call_blob(&code, context.as_mut_ptr().cast(), 0, 0) as usize as u32;
                    let selected = index & 7;
                    assert_eq!(actual, if selected < 4 { (selected as u32 + 1)*10 + 10 } else { 0 });
                }
            }
            rows.push(serde_json::json!({"variant":name,"table_identity":true,
                "proof_slots":4,"native_host_cases":if name=="scheduled" {64} else {0}}));
        }
        fs::write(build.join("rust-result.json"), serde_json::to_vec_pretty(&rows)?)?;
        Ok(())
    }

    #[test]
    fn current_otel_scheduled_tables_restore_helper_cfg_predecessors() -> Result<()> {
        let release = fs::read_to_string("/workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release")?;
        let path = format!("/workspaces/repository/vendor/build/native-bpf/x86/{}/native/otel/otelcol-ebpf-profiler.native.o", release.trim());
        let bytes = fs::read(&path)?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "kprobe_unwind_hotspot")?;
        let targets = control_targets(&elf, &entry)?;
        assert_eq!(targets.len(), 4);
        let included = discover_reachable(&elf, &entry)?;
        let got = scan_x86_got_relocations(&elf, &included)?;
        let calls = helper_provenance::calls(&elf, &entry, &got, &HashMap::new())?;
        assert_eq!(calls.get(&0x211).map(String::as_str), Some("bpf_probe_read_user"));
        let proof = rewrite_x86(&elf, &entry, &included, &HashMap::new(), &HashMap::new(),
            &HashMap::new(), &[], true, true, None, None, None, None, false)?;
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/scheduled-table");
        fs::create_dir_all(build)?;
        write_proof_object(&build.join("otel.proof.o"), object::Architecture::X86_64,
            "kprobe_unwind_hotspot", &proof.blob, &proof.proof_symbols, &proof.proof_relocs,
            &proof.proof_data_relocs, proof.callee_saved_mask)?;
        fs::write(build.join("otel-cfg.json"), serde_json::to_vec_pretty(&serde_json::json!({
            "object":path,"symbol":entry.name,"table_targets":targets,"helper_calls":calls,
            "proof_blob_bytes":proof.blob.len(),"proof_data_relocations":proof.proof_data_relocs.len(),
            "scope":"Current object helper CFG and production proof; no B verification or application execution"
        }))?)?;
        Ok(())
    }

    #[test]
    fn separate_roots_copy_only_their_anonymous_code_table_slots() -> Result<()> {
        let build = std::path::Path::new("/var/tmp/kprog-tmp/perf/helper-cfg");
        fs::create_dir_all(build)?;
        let native = build.join("shared.native.o");
        let command = ["clang-18", "-target", "x86_64-linux-gnu", "-O3", "-march=native",
            "-foptimize-sibling-calls", "-fomit-frame-pointer", "-mno-red-zone", "-mgeneral-regs-only",
            "-fno-stack-protector", "-I/workspaces/repository/vendor/libbpf/src", "-c", "/workspaces/repository/kprog/test/native_shared_code_tables.c",
            "-o", native.to_str().ok_or_else(|| anyhow!("shared fixture path is not UTF-8"))?];
        let compiled = std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !compiled.status.success() { bail!("shared-table clang failed: {}", String::from_utf8_lossy(&compiled.stderr)); }
        fs::write(build.join("shared-compile-command.json"), serde_json::to_vec(&command)?)?;
        let source = fs::read(native)?;
        let original = object::File::parse(source.as_slice())?;
        assert_eq!(original.section_by_name(".rodata").ok_or_else(|| anyhow!("fixture has no tables"))?.relocations().count(), 16);
        let layout: KernelLayout = serde_json::from_slice(&fs::read(
            "/var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json")?)?;
        let mut rows = Vec::new();
        for (name, bias) in [("first_table", 17u64), ("second_table", 29)] {
            let entry = find_symbol_by_name(&original, name)?;
            let included = discover_reachable(&original, &entry)?;
            assert_eq!(included.len(), 1);
            let proof = rewrite_x86(&original, &entry, &included, &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], true, true, None, None, None, None, false)?;
            assert_eq!(proof.proof_data_relocs.len(), 8);
            let path = build.join("shared.proof.o");
            write_proof_object(&path, object::Architecture::X86_64, name, &proof.blob,
                &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
            let bytes = fs::read(path)?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, name)?;
            let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(), &HashMap::new(),
                &HashMap::new(), &[], false, true, Some(&layout.array), Some(&layout.probe_read),
                Some(&layout.hash), Some(&layout.lpm), false)?;
            assert!(linked.relocs.is_empty() && linked.map_patches.is_empty());
            let mut code = linked.blob; code.push(0xc3);
            #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
            for seed in 0..4u64 {
                let mut context = [0u64; 9];
                for (i, item) in context.iter_mut().enumerate() { *item = seed*0x9e3779b9+i as u64*71; }
                let expected = [context[1]+bias, context[2]*3, context[3]^(bias+0x1234), context[4].wrapping_sub(bias),
                    context[5]|0x8000, context[6]&0x7fff, context[7]+bias*7, context[8]*5];
                for index in 0..16 {
                    context[0] = index;
                    let actual = memory::call_blob(&code, context.as_mut_ptr().cast(), 0, 0) as usize as u32;
                    assert_eq!(actual, if index < 8 { expected[index as usize] as u32 } else { 0 });
                }
            }
            rows.push(serde_json::json!({"entry":name,"proof_slots":8,"included_functions":1,"native_host_cases":64}));
        }
        fs::write(build.join("shared-tables.json"), serde_json::to_vec_pretty(&rows)?)?;
        Ok(())
    }

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
