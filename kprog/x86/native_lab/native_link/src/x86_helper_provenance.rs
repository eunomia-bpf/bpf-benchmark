//! Helper identities are facts at a CFG point, not a lexical last assignment.
use super::*;
use std::collections::{BTreeSet, VecDeque};

#[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord)]
enum Value { Id(u64), Symbol(String) }
type Values = BTreeSet<Value>;
type State = HashMap<Register, Values>;

#[derive(Clone, Default)]
pub(super) struct Calls {
    pub single: HashMap<u64, String>,
    pub numeric_joins: HashMap<u64, Vec<(u64, String)>>,
    pub tails: HashSet<u64>,
}

fn indirect_register(insn: &Instruction) -> Option<Register> {
    if !matches!(insn.flow_control(), FlowControl::IndirectCall | FlowControl::IndirectBranch)
        || insn.op0_kind() != OpKind::Register { return None; }
    x86_gpr64_family(insn.op0_register())
}

pub(super) fn calls(elf: &object::File, sym: &SymInfo,
    got: &HashMap<LocalSiteKey, String>, helpers: &HashMap<String, u64>) -> Result<Calls> {
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
    let tails: HashSet<_> = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE)
        .into_iter().filter(|i| i.flow_control() == FlowControl::IndirectBranch)
        .map(|i| i.ip()).collect();
    let mut result=Calls::default();
    for (ip, alternatives) in values {
        let mut names=BTreeSet::new();
        let mut numeric=Vec::new();
        for value in &alternatives {
            let name=match value {
                Value::Symbol(name) => name.clone(),
                Value::Id(id) => {
                    let name=bpf_helper_name_from_id(*id).ok_or_else(||
                        anyhow!("unsupported numeric helper id {id} in {} at {ip:#x}", sym.name))?.to_owned();
                    numeric.push((*id,name.clone()));
                    name
                }
            };
            names.insert(name);
        }
        if names.len()==1 {
            result.single.insert(ip-sym.address,names.into_iter().next().unwrap());
        } else if numeric.len()==alternatives.len() {
            result.numeric_joins.insert(ip-sym.address,numeric);
        }
        if tails.contains(&ip) { result.tails.insert(ip-sym.address); }
    }
    Ok(result)
}

fn analyze(bytes: &[u8], base: u64, tables: &HashMap<u64, Vec<u64>>,
    symbolic: impl Fn(&Instruction) -> Option<Value>) -> Result<HashMap<u64, Values>> {
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
        let mut assigned = symbolic(insn).map(|value| (insn.op0_register(), Values::from([value])));
        if insn.mnemonic() == Mnemonic::Mov && insn.op_count() == 2 && insn.op0_kind() == OpKind::Register {
            let width = insn.op0_register().size();
            if width == 4 || width == 8 {
                let reg = x86_gpr64_family(insn.op0_register());
                if let Some((reg, value)) = x86_mov_imm_to_gpr64(insn).filter(|(_, id)| *id <= 255) {
                    assigned = Some((reg, Values::from([Value::Id(value)])));
                } else if insn.op1_kind() == OpKind::Register && insn.op1_register().size() == width {
                    if let Some(value) = x86_gpr64_family(insn.op1_register()).and_then(|r| state.get(&r)) {
                        if width == 8 || value.iter().all(|v| matches!(v, Value::Id(_))) {
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
                else if !indirect_register(insn).is_some_and(|reg| state.contains_key(&reg)) {
                    successors.extend(insns.iter().map(Instruction::ip));
                }
            }
            _ => {}
        }
        for target in successors {
            let Some(&j) = indices.get(&target) else {
                if target >= base && target < base+bytes.len() as u64 { bail!("helper CFG branch to {:#x} from {:#x} targets an interior byte", target, insn.ip()); }
                continue;
            };
            let changed = if let Some(previous) = &mut states[j] {
                let old = previous.clone();
                previous.retain(|reg, values| {
                    if let Some(incoming)=state.get(reg) {
                        values.extend(incoming.iter().cloned());true
                    } else { false }
                });
                *previous != old
            } else { states[j] = Some(state.clone()); true };
            if changed { queue.push_back(j); }
        }
    }
    Ok(insns.iter().enumerate().filter_map(|(i, insn)| {
        if tables.contains_key(&insn.ip()) { return None; }
        let reg = indirect_register(insn)?;
        states[i].as_ref()?.get(&reg).cloned().map(|value| (insn.ip(), value))
    }).collect())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn compiler_emitted_kprobe_helper_tails_produce_symbolic_proof() -> Result<()> {
        let build=std::path::Path::new("/var/tmp/kprog-tmp/perf/helper-cfg");
        fs::create_dir_all(build)?;
        let native=build.join("numeric-tail.native.o");
        let command=["clang-18","-O3","-g","-fPIC","-fomit-frame-pointer","-march=native",
            "-mno-red-zone","-mgeneral-regs-only","-fno-stack-protector","-fno-asynchronous-unwind-tables",
            "-fno-unwind-tables","-c","/workspaces/repository/kprog/test/native_numeric_helper_tail.c",
            "-o",native.to_str().unwrap()];
        let output=std::process::Command::new(command[0]).args(&command[1..]).output()?;
        if !output.status.success() { bail!("helper-tail fixture: {}",String::from_utf8_lossy(&output.stderr)); }
        let source=fs::read(native)?;
        let elf=object::File::parse(source.as_slice())?;
        let entry=find_symbol_by_name(&elf,"numeric_tail")?;
        let included=discover_reachable(&elf,&entry)?;
        let facts=calls(&elf,&entry,&HashMap::new(),&HashMap::new())?;
        assert!(!facts.tails.is_empty(),"compiler fixture no longer exercises numeric tail exits");
        let proof=rewrite_x86(&elf,&entry,&included,&HashMap::new(),&HashMap::new(),&HashMap::new(),&[],
            true,true,None,None,None,false)?;
        write_proof_object(&build.join("numeric-tail.proof.o"),object::Architecture::X86_64,"numeric_tail",
            &proof.blob,&proof.proof_symbols,&proof.proof_relocs,&proof.proof_data_relocs,proof.callee_saved_mask)?;
        assert!(proof.proof_relocs.iter().any(|r|r.symbol=="bpf_get_prandom_u32"));
        assert!(proof.proof_relocs.iter().any(|r|r.symbol=="bpf_get_smp_processor_id"));
        Ok(())
    }

    #[test]
    fn numeric_helper_tails_keep_arguments_and_return_through_entry_and_caller() -> Result<()> {
        use object::write::{Object, Symbol, SymbolSection};
        let build=std::path::Path::new("/var/tmp/kprog-tmp/perf/helper-cfg");
        fs::create_dir_all(build)?;
        let helpers=HashMap::from([("bpf_redirect".into(),0x1234), ("bpf_redirect_peer".into(),0x5678)]);
        let singleton=vec![0xb8,23,0,0,0,0xff,0xe0];
        let joined=vec![0x85,0xff,0x74,7,0xb8,23,0,0,0,0xeb,5,0xb8,155,0,0,0,0xff,0xe0];
        let mut cases=0;
        for (name,body) in [("singleton",singleton),("joined",joined)] {
            for caller in [false,true] {
                let mut object=Object::new(object::BinaryFormat::Elf,object::Architecture::X86_64,object::Endianness::Little);
                let section=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
                // The caller aligns its stack, calls the tail-exiting subprogram,
                // then observes the helper result after the subprogram returns.
                let prefix=if caller {vec![0x48,0x83,0xec,8,0xe8,9,0,0,0,
                    0x48,0x83,0xc4,8,0x48,0x83,0xc0,7,0xc3]} else {Vec::new()};
                let mut code=prefix.clone();code.extend_from_slice(&body);
                object.append_section_data(section,&code,1);
                for (symbol,offset,size) in if caller {
                    vec![("entry",0,prefix.len()),("callee",prefix.len(),body.len())]
                } else {vec![("entry",0,body.len())]} {
                    object.add_symbol(Symbol {name:symbol.as_bytes().to_vec(),value:offset as u64,size:size as u64,
                        kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                        section:SymbolSection::Section(section),flags:SymbolFlags::None});
                }
                let bytes=object.write()?;
                let elf=object::File::parse(bytes.as_slice())?;
                let entry=find_symbol_by_name(&elf,"entry")?;
                let included=discover_reachable(&elf,&entry)?;
                let proof=rewrite_x86(&elf,&entry,&included,&helpers,&HashMap::new(),&HashMap::new(),&[],
                    true,true,None,None,None,false)?;
                assert_eq!(proof.proof_relocs.iter().filter(|r| r.symbol.starts_with("bpf_")).count(),
                    if name=="joined" {2}else {1});
                let path=build.join(format!("{name}-{caller}.tail.proof.o"));
                write_proof_object(&path,object::Architecture::X86_64,"entry",&proof.blob,
                    &proof.proof_symbols,&proof.proof_relocs,&proof.proof_data_relocs,proof.callee_saved_mask)?;
                let roundtrip=fs::read(path)?;
                let linked_elf=object::File::parse(roundtrip.as_slice())?;
                let linked_entry=find_symbol_by_name(&linked_elf,"entry")?;
                let linked_symbols=discover_reachable(&linked_elf,&linked_entry)?;
                // Old proofs could retain an unwrapped numeric helper JMP.
                // Include that exact form rather than accepting a skipped JIT exit.
                let path=build.join(format!("{name}-{caller}.legacy-tail.proof.o"));
                let symbols:Vec<_>=included.iter().map(|s| ProofSymbol {name:s.name.clone(),
                    offset:s.address,size:s.size}).collect();
                write_proof_object(&path,object::Architecture::X86_64,"entry",&code,&symbols,&[],&[],0)?;
                let legacy=fs::read(path)?;
                let legacy_elf=object::File::parse(legacy.as_slice())?;
                let legacy_entry=find_symbol_by_name(&legacy_elf,"entry")?;
                let legacy_symbols=discover_reachable(&legacy_elf,&legacy_entry)?;
                for (elf,entry,included) in [(&elf,&entry,&included),(&linked_elf,&linked_entry,&linked_symbols),
                    (&legacy_elf,&legacy_entry,&legacy_symbols)] {
                    let linked=rewrite_x86(elf,entry,included,&helpers,&HashMap::new(),&HashMap::new(),&[],
                        false,true,None,None,None,false)?;
                    // An observable epilogue distinguishes returning through
                    // the JIT exit from incorrectly returning straight to C.
                    let mut image=linked.blob;image.extend_from_slice(&[0x48,0x05,0,1,0,0,0xc3]);
                    let mut stubs=HashMap::new();
                    for (target,value) in [(0x1234,0x1000u32),(0x5678,0x2000)] {
                        stubs.insert(target,image.len());
                        // A real SysV callee enters with RSP mod 16 == 8.
                        // Return zero on a misaligned call instead of hiding it.
                        image.extend_from_slice(&[0x48,0x89,0xe0,0x83,0xe0,15,0x83,0xf8,8,
                            0x74,3,0x31,0xc0,0xc3]);
                        image.extend_from_slice(&[0x48,0x8d,0x84,0x37]);
                        image.extend_from_slice(&value.to_le_bytes());image.push(0xc3);
                    }
                    for relocation in linked.relocs {
                        let at=relocation.offset as usize;
                        let displacement=i32::try_from(stubs[&relocation.target] as i64-(at+5) as i64)?;
                        image[at+1..at+5].copy_from_slice(&displacement.to_le_bytes());
                    }
                    for selector in [0usize,1,7,128] {
                        let expected=if name=="joined" && selector==0 {0x2000}else {0x1000};
                        assert_eq!(memory::call_blob(&image,selector as *mut u8,19,0) as usize,
                            expected+selector+19+256+if caller {7}else {0});
                        cases+=1;
                    }
                }
            }
        }
        assert_eq!(cases,48);
        // Unknown and partial writes must not become a helper tail fact.
        assert!(analyze(&[0xff,0xe0],0,&HashMap::new(),|_|None)?.is_empty());
        assert!(analyze(&[0xb8,23,0,0,0,0xb0,155,0xff,0xe0],0,&HashMap::new(),|_|None)?.is_empty());
        Ok(())
    }
    fn ids(bytes: &[u8]) -> Result<HashMap<u64, Value>> {
        Ok(analyze(bytes, 0, &HashMap::new(), |_| None)?.into_iter()
            .filter_map(|(ip,values)| (values.len()==1).then(|| (ip,values.into_iter().next().unwrap())))
            .collect())
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
            &HashMap::new(), &[], false, false, None, None, None, false)?;
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
    fn finite_numeric_join_dispatches_both_helpers_and_preserves_ids() -> Result<()> {
        use object::write::{Object, Symbol, SymbolSection};
        // The compiler merges redirect(23) and redirect_peer(155) calls.
        // R13's ID remains observable after the helper; RSI is a zero argument.
        let code=[0x41,0x55,0x48,0x85,0xff,0x74,8,
            0x41,0xbd,23,0,0,0,0xeb,6,0x41,0xbd,155,0,0,0,
            0x31,0xf6,0x41,0xff,0xd5,0x4c,0x01,0xe8,0x41,0x5d,0xc3];
        let mut object=Object::new(object::BinaryFormat::Elf,object::Architecture::X86_64,object::Endianness::Little);
        let section=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
        object.append_section_data(section,&code,1);
        object.add_symbol(Symbol {name:b"entry".to_vec(),value:0,size:code.len() as u64,
            kind:object::SymbolKind::Text,scope:object::SymbolScope::Linkage,weak:false,
            section:SymbolSection::Section(section),flags:object::SymbolFlags::None});
        let bytes=object.write()?;
        let elf=object::File::parse(bytes.as_slice())?;
        let entry=find_symbol_by_name(&elf,"entry")?;
        let facts=calls(&elf,&entry,&HashMap::new(),&HashMap::new())?;
        assert_eq!(facts.numeric_joins[&23],vec![(23,"bpf_redirect".into()),(155,"bpf_redirect_peer".into())]);
        let helpers=HashMap::from([("bpf_redirect".into(),0x1234),("bpf_redirect_peer".into(),0x5678)]);
        let proof=rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),
            &HashMap::new(),&[],true,true,None,None,None,false)?;
        assert!(!proof.blob.is_empty());
        let linked=rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),
            &HashMap::new(),&[],false,true,None,None,None,false)?;
        assert_eq!(linked.relocs.len(),2);
        let mut image=linked.blob;
        image.push(0xc3); // The installed JIT epilogue follows the entry blob.
        let mut stubs=HashMap::new();
        for (target,constant) in [(0x1234,0x1000u32),(0x5678,0x2000)] {
            stubs.insert(target,image.len());
            // LEA RAX,[RDI+RSI+constant]; RET -- actual argument/result path.
            image.extend_from_slice(&[0x48,0x8d,0x84,0x37]);
            image.extend_from_slice(&constant.to_le_bytes());image.push(0xc3);
        }
        for relocation in linked.relocs {
            let offset=relocation.offset as usize;
            let displacement=i32::try_from(stubs[&relocation.target] as i64-(offset+5) as i64)?;
            image[offset+1..offset+5].copy_from_slice(&displacement.to_le_bytes());
        }
        #[cfg(all(target_arch="x86_64",target_os="linux"))]
        for selector in [0usize,1,7,128] {
            let expected=if selector==0 {0x2000+155} else {0x1000+selector+23};
            assert_eq!(memory::call_blob(&image,selector as *mut u8,0,0) as usize,expected);
        }
        // An unknown incoming path still prevents a finite dispatch fact.
        let unknown=[0x85,0xff,0x74,5,0xb8,23,0,0,0,0xff,0xd0,0xc3];
        assert!(analyze(&unknown,0,&HashMap::new(),|_|None)?.is_empty());
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
        let names = calls(&elf,&entry,&HashMap::new(),&HashMap::new())?.single;
        assert_eq!(names.get(&16).map(String::as_str),Some("bpf_probe_read_compat"));
        assert_eq!(names.get(&25).map(String::as_str),Some("bpf_probe_read_kernel"));
        let helpers = HashMap::from([("bpf_probe_read_compat".into(),0x1234),
            ("bpf_probe_read_kernel".into(),0x5678)]);
        let linked = rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),
            &HashMap::new(),&[],false,true,None,None,None,false)?;
        assert_eq!(linked.relocs.iter().map(|r|r.target).collect::<Vec<_>>(),vec![0x1234,0x5678]);
        Ok(())
    }
}
