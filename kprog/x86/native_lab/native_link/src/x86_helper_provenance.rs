//! Helper identities are facts at a CFG point, not a lexical last assignment.
use super::*;
use std::collections::VecDeque;

#[derive(Clone, Debug, PartialEq, Eq)]
enum Value { Id(u64), Symbol(String) }
type State = HashMap<Register, Value>;

pub(super) fn calls(elf: &object::File, sym: &SymInfo,
    got: &HashMap<LocalSiteKey, String>, helpers: &HashMap<String, u64>) -> Result<HashMap<u64, String>> {
    let bytes = read_symbol_bytes(elf, sym)?;
    let tables = readonly_relocs::control_targets(elf, sym)?;
    let values = analyze(&bytes, sym.address, &tables, |insn| {
        if insn.mnemonic() != Mnemonic::Mov || insn.op0_kind() != OpKind::Register ||
            insn.op0_register().size() != 8 || insn.op1_kind() != OpKind::Memory ||
            !insn.is_ip_rel_memory_operand() { return None; }
        let name = got.get(&local_site_key(sym, insn.next_ip()-sym.address-4))?;
        (name.starts_with("bpf_") || helpers.contains_key(name) || matches!(name.as_str(), "memcpy" | "memset"))
            .then(|| Value::Symbol(name.clone()))
    })?;
    values.into_iter().map(|(ip, value)| {
        let name = match value {
            Value::Symbol(name) => name,
            Value::Id(id) => bpf_helper_name_from_id(id).ok_or_else(||
                anyhow!("unsupported numeric helper id {id} in {} at {ip:#x}", sym.name))?.to_owned(),
        };
        Ok((ip-sym.address, name))
    }).collect()
}

fn analyze(bytes: &[u8], base: u64, tables: &HashMap<u64, Vec<u64>>,
    symbolic: impl Fn(&Instruction) -> Option<Value>) -> Result<HashMap<u64, Value>> {
    let insns: Vec<_> = Decoder::with_ip(64, bytes, base, DecoderOptions::NONE).into_iter().collect();
    if insns.iter().any(Instruction::is_invalid) { bail!("invalid instruction in helper CFG"); }
    let indices: HashMap<_, _> = insns.iter().enumerate().map(|(i, insn)| (insn.ip(), i)).collect();
    if insns.is_empty() { return Ok(HashMap::new()); }
    let mut states: Vec<Option<State>> = vec![None; insns.len()];
    states[0] = Some(HashMap::new());
    let mut queue = VecDeque::from([0]);
    let mut factory = InstructionInfoFactory::new();
    while let Some(i) = queue.pop_front() {
        let insn = &insns[i];
        let mut state = states[i].clone().ok_or_else(|| anyhow!("missing reachable helper state"))?;
        let mut assigned = symbolic(insn).map(|value| (insn.op0_register(), value));
        if insn.mnemonic() == Mnemonic::Mov && insn.op_count() == 2 && insn.op0_kind() == OpKind::Register {
            let width = insn.op0_register().size();
            if width == 4 || width == 8 {
                let reg = x86_gpr64_family(insn.op0_register());
                if let Some((reg, value)) = x86_mov_imm_to_gpr64(insn).filter(|(_, id)| *id <= 255) {
                    assigned = Some((reg, Value::Id(value)));
                } else if insn.op1_kind() == OpKind::Register && insn.op1_register().size() == width {
                    if let Some(value) = x86_gpr64_family(insn.op1_register()).and_then(|r| state.get(&r)) {
                        if width == 8 || matches!(value, Value::Id(_)) {
                            assigned = reg.map(|reg| (reg, value.clone()));
                        }
                    }
                }
            }
        }
        for register in factory.info(insn).used_registers() {
            if matches!(register.access(), OpAccess::Write | OpAccess::CondWrite | OpAccess::ReadWrite | OpAccess::ReadCondWrite) {
                if let Some(reg) = x86_gpr64_family(register.register()) { state.remove(&reg); }
            }
        }
        if matches!(insn.flow_control(), FlowControl::Call | FlowControl::IndirectCall) {
            clear_x86_call_clobbered_registers(&mut state);
        }
        if let Some((reg, value)) = assigned { state.insert(reg, value); }
        let mut successors = Vec::new();
        match insn.flow_control() {
            FlowControl::Next | FlowControl::Call | FlowControl::IndirectCall => successors.push(insn.next_ip()),
            FlowControl::ConditionalBranch => { successors.push(insn.next_ip()); successors.push(insn.near_branch_target()); }
            FlowControl::UnconditionalBranch => successors.push(insn.near_branch_target()),
            FlowControl::IndirectBranch => {
                if let Some(targets) = tables.get(&insn.ip()) { successors.extend(targets); }
                else { successors.extend(insns.iter().map(Instruction::ip)); }
            }
            _ => {}
        }
        for target in successors {
            let Some(&j) = indices.get(&target) else {
                if target >= base && target < base+bytes.len() as u64 { bail!("helper CFG branch targets an interior byte"); }
                continue;
            };
            let changed = if let Some(previous) = &mut states[j] {
                let old = previous.len();
                previous.retain(|reg, value| state.get(reg) == Some(value));
                old != previous.len()
            } else { states[j] = Some(state.clone()); true };
            if changed { queue.push_back(j); }
        }
    }
    Ok(insns.iter().enumerate().filter_map(|(i, insn)| {
        if insn.flow_control() != FlowControl::IndirectCall { return None; }
        let reg = x86_indirect_call_register(insn)?;
        states[i].as_ref()?.get(&reg).cloned().map(|value| (insn.ip(), value))
    }).collect())
}

#[cfg(test)]
mod tests {
    use super::*;
    fn ids(bytes: &[u8]) -> Result<HashMap<u64, Value>> {
        analyze(bytes, 0, &HashMap::new(), |_| None)
    }

    #[test]
    fn joins_backedges_calls_and_partial_writes_do_not_use_lexical_state() -> Result<()> {
        // R13=4 dominates a branch over an unreachable R13=1 assignment.
        let bytes = [0x41,0xbd,4,0,0,0, 0xeb,6, 0x41,0xbd,1,0,0,0, 0x41,0xff,0xd5, 0xc3];
        assert_eq!(ids(&bytes)?.get(&14), Some(&Value::Id(4)));
        // Two reachable values disagree: no singleton identity may be bound.
        let mut joined = bytes; joined[6] = 0x74;
        assert!(!ids(&joined)?.contains_key(&14));
        // A narrow write changes the register's value; it cannot mean helper 1.
        assert!(ids(&[0x41,0xbd,4,0,0,0, 0x41,0xb5,1, 0x41,0xff,0xd5, 0xc3])?.is_empty());
        // Caller-saved RAX is unknown after a call; callee-saved R13 survives.
        let preserved = ids(&[0x41,0xbd,4,0,0,0, 0xe8,0,0,0,0, 0x41,0xff,0xd5, 0xc3])?;
        assert_eq!(preserved.get(&11), Some(&Value::Id(4)));
        assert!(ids(&[0xb8,4,0,0,0, 0xe8,0,0,0,0, 0xff,0xd0, 0xc3])?.is_empty());
        // A loop's backedge changes 4 to 1 before returning to the call.
        assert!(!ids(&[0x41,0xbd,4,0,0,0, 0x41,0xff,0xd5, 0x41,0xbd,1,0,0,0, 0x75,0xf5, 0xc3])?.contains_key(&6));
        Ok(())
    }

    #[test]
    fn kernel_binding_uses_cfg_identity_and_keeps_observed_numeric_value() -> Result<()> {
        // Old lexical tracking bound the unreachable helper 1; dropping the
        // helper-id MOV also damaged the later scalar observation of R13.
        use object::write::{Object, Symbol, SymbolSection};
        let code = [0x41,0x55, 0x41,0xbd,4,0,0,0, 0xeb,6, 0x41,0xbd,1,0,0,0,
                    0x41,0xff,0xd5, 0x44,0x89,0xe8, 0x41,0x5d, 0xc3];
        let mut object = Object::new(object::BinaryFormat::Elf, object::Architecture::X86_64, object::Endianness::Little);
        let section = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
        object.append_section_data(section, &code, 1);
        object.add_symbol(Symbol { name: b"entry".to_vec(), value: 0, size: code.len() as u64,
            kind: object::SymbolKind::Text, scope: object::SymbolScope::Linkage, weak: false,
            section: SymbolSection::Section(section), flags: object::SymbolFlags::None });
        let bytes = object.write()?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf, "entry")?;
        let helpers = HashMap::from([("bpf_probe_read_compat".to_owned(), 0x1234),
                                    ("bpf_map_lookup_elem".to_owned(), 0x5678)]);
        let linked = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &HashMap::new(),
            &HashMap::new(), &[], false, false, None, None, None, None, false)?;
        assert_eq!(linked.relocs.len(), 1);
        assert_eq!(linked.relocs[0].target, 0x1234);
        let mut code = linked.blob;
        let stub = code.len()+1;
        code.extend_from_slice(&[0xc3, 0x31,0xc0,0xc3]);
        for relocation in linked.relocs {
            assert_eq!(relocation.kind, NATIVE_LAB_RELOC_HELPER_CALL_REL32);
            let at = relocation.offset as usize;
            code[at+1..at+5].copy_from_slice(&i32::try_from(stub as i64-(at+5) as i64)?.to_le_bytes());
        }
        #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
        assert_eq!(memory::call_blob(&code, std::ptr::null_mut(), 0, 0) as usize, 4);
        Ok(())
    }

    #[test]
    fn r13_rebinding_distinguishes_compat_and_kernel_read_targets() -> Result<()> {
        // Preserve the old Tetragon failure class without depending on a
        // moving producer artifact's register allocation or fixed offsets:
        // R13=4, skip an unreachable1, call; then rebind R13=113 and call.
        use object::write::{Object, Symbol, SymbolSection};
        let code = [0x41,0x55,0x41,0xbd,4,0,0,0,0xeb,6,0x41,0xbd,1,0,0,0,
            0x41,0xff,0xd5,0x41,0xbd,113,0,0,0,0x41,0xff,0xd5,0x41,0x5d,0xc3];
        let mut object = Object::new(object::BinaryFormat::Elf,object::Architecture::X86_64,object::Endianness::Little);
        let section = object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
        object.append_section_data(section,&code,1);
        object.add_symbol(Symbol { name:b"entry".to_vec(),value:0,size:code.len() as u64,
            kind:object::SymbolKind::Text,scope:object::SymbolScope::Linkage,weak:false,
            section:SymbolSection::Section(section),flags:object::SymbolFlags::None });
        let bytes = object.write()?;
        let elf = object::File::parse(bytes.as_slice())?;
        let entry = find_symbol_by_name(&elf,"entry")?;
        let names = calls(&elf,&entry,&HashMap::new(),&HashMap::new())?;
        assert_eq!(names.get(&16).map(String::as_str),Some("bpf_probe_read_compat"));
        assert_eq!(names.get(&25).map(String::as_str),Some("bpf_probe_read_kernel"));
        let helpers = HashMap::from([("bpf_probe_read_compat".into(),0x1234),
            ("bpf_probe_read_kernel".into(),0x5678)]);
        let linked = rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),
            &HashMap::new(),&[],false,true,None,None,None,None,false)?;
        assert_eq!(linked.relocs.iter().map(|r|r.target).collect::<Vec<_>>(),vec![0x1234,0x5678]);
        Ok(())
    }
}
