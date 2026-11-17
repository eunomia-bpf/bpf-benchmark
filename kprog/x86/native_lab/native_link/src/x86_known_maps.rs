//! Named map-pointer provenance. Every reachable predecessor must agree at a join.
//! Arithmetic, partial writes, memory reloads and caller-clobbered registers lose identity.
use super::*;

pub(super) fn arguments(
    bytes: &[u8], sym: &SymInfo, got: &HashMap<LocalSiteKey, String>,
    absolute: &HashMap<LocalSiteKey, non_pic::Reference>,
    maps: &HashMap<String, u64>,
    branch_targets: &HashMap<u64, Vec<u64>>,
) -> Result<HashMap<u64, String>> {
    let mut decoder = Decoder::with_ip(64, bytes, sym.address, DecoderOptions::NONE);
    let mut instructions = Vec::new();
    while decoder.can_decode() {
        let insn = decoder.decode();
        if insn.is_invalid() { bail!("invalid x86 map-provenance instruction in {}", sym.name); }
        instructions.push(insn);
    }
    // Reuse the helper analysis's resolved code-table destinations. Only an
    // unresolved indirect branch may enter an arbitrary instruction.
    if instructions.iter().any(|i| i.flow_control() == FlowControl::IndirectBranch
        && !branch_targets.get(&i.ip()).is_some_and(|targets| !targets.is_empty())) {
        return Ok(HashMap::new());
    }
    let indices:HashMap<_,_>=instructions.iter().enumerate().map(|(n,i)|(i.ip(),n)).collect();
    let mut states:Vec<Option<HashMap<Register,String>>>=vec![None;instructions.len()];
    if states.is_empty() {return Ok(HashMap::new());}
    states[0]=Some(HashMap::new());
    let mut queue=std::collections::VecDeque::from([0]);
    let mut result=HashMap::new();
    let mut factory=InstructionInfoFactory::new();
    while let Some(index)=queue.pop_front() {
        let insn=&instructions[index];
        let mut registers=states[index].as_ref().expect("queued map state").clone();
        let local_ip = insn.ip() - sym.address;
        let call = matches!(insn.flow_control(), FlowControl::Call | FlowControl::IndirectCall);
        let transfer = call || insn.flow_control() == FlowControl::UnconditionalBranch;
        if transfer {
            if let Some(name) = registers.get(&Register::RDI) {
                result.insert(local_ip, name.clone());
            } else { result.remove(&local_ip); }
        }
        let mut assigned = None;
        if let Some(reference) = absolute.get(&local_site_key(sym, local_ip)) {
            assigned = Some((reference.register, reference.name.clone()));
        }
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
        let mut successors=Vec::new();
        if insn.flow_control()==FlowControl::IndirectBranch {
            for target in &branch_targets[&insn.ip()] {
                if let Some(&n)=indices.get(target) {successors.push(n);}
            }
        }
        if matches!(insn.flow_control(),FlowControl::UnconditionalBranch|FlowControl::ConditionalBranch) {
            if let Some(&n)=indices.get(&insn.near_branch_target()) {successors.push(n);}
        }
        if matches!(insn.flow_control(),FlowControl::Next|FlowControl::Call|
            FlowControl::IndirectCall|FlowControl::ConditionalBranch) && index+1<instructions.len() {
            successors.push(index+1);
        }
        for n in successors {
            let merged=match &states[n] {
                None=>registers.clone(),
                Some(old)=>old.iter().filter(|(r,name)|registers.get(*r)==Some(*name))
                    .map(|(&r,name)|(r,name.clone())).collect(),
            };
            if states[n].as_ref()!=Some(&merged) {states[n]=Some(merged);queue.push_back(n);}
        }
    }
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn track(bytes: &[u8]) -> Result<HashMap<u64, String>> {
        let sym = SymInfo { name: "entry".into(), section_index: object::SectionIndex(1),
                            address: 0, size: bytes.len() as u64 };
        arguments(bytes, &sym, &HashMap::from([((sym.section_index, 0, 3), "map".into())]), &HashMap::new(),
                  &HashMap::from([("map".into(), 0x1000)]), &HashMap::new())
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
    fn map_bindings_meet_across_branches_and_loops() -> Result<()> {
        // Both edges retain the same preceding identity, even at a zero-length join.
        let names=track(&[0x48,0x8b,0x3d,0,0,0,0,0x74,0,0xe8,0,0,0,0,0xc3])?;
        assert_eq!(names.get(&9).map(String::as_str),Some("map"));
        // Either arm establishes its own map. Only equal named identities meet.
        let bytes=[0x85,0xff,0x74,9,0x48,0x8b,0x3d,0,0,0,0,0xeb,7,
                   0x48,0x8b,0x3d,0,0,0,0,0xe8,0,0,0,0,0xc3];
        let sym=SymInfo{name:"entry".into(),section_index:object::SectionIndex(1),address:0,size:bytes.len() as u64};
        for same in [true,false] {
            let got=HashMap::from([(local_site_key(&sym,7),"map".into()),
                (local_site_key(&sym,16),if same {"map".into()}else{"other".into()})]);
            let names=arguments(&bytes,&sym,&got,&HashMap::new(),
                &HashMap::from([("map".into(),0x1000),("other".into(),0x2000)]),&HashMap::new())?;
            assert_eq!(names.get(&20).map(String::as_str),if same {Some("map")}else{None});
        }
        // A callee-saved map survives a loop only if no backedge destroys it.
        for kill in [false,true] {
            let mut bytes=vec![0x4c,0x8b,0x25,0,0,0,0,0x4c,0x89,0xe7,0xe8,0,0,0,0];
            if kill {bytes.extend_from_slice(&[0x45,0x31,0xe4]);}
            bytes.extend_from_slice(&[0x85,0xc0,0x75,if kill {0xf1}else{0xf4},0xc3]);
            let names=track(&bytes)?;
            assert_eq!(names.get(&10).map(String::as_str),if kill {None}else{Some("map")});
        }
        // A first-iteration fact is not a fixed-point fact for caller-saved RDI.
        let names=track(&[0x48,0x8b,0x3d,0,0,0,0,0xe8,0,0,0,0,0x85,0xc0,0x75,0xf7,0xc3])?;
        assert!(!names.contains_key(&7));
        println!("named map CFG: agreeing/disagreeing joins, callee/caller loop clobbers PASS");
        Ok(())
    }

    #[test]
    fn joins_partial_writes_and_arithmetic_erase_provenance() -> Result<()> {
        let load = [0x48,0x8b,0x3d,0,0,0,0]; // named map -> RDI
        for suffix in [
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
        assert!(arguments(&bytes, &sym, &HashMap::from([((sym.section_index,0,5),"map".into())]), &HashMap::new(),
                          &HashMap::from([("map".into(),0x1000)]), &HashMap::new())?.is_empty());
        // Unknown jump-table successors cannot reuse any linear-flow fact.
        assert!(track(&[load.as_slice(), &[0xe8,0,0,0,0, 0xff,0xe0]].concat())?.is_empty());
        Ok(())
    }

    #[test]
    fn resolved_jump_tables_keep_local_loads_but_erase_joined_map_facts() -> Result<()> {
        // Two blocks each load a named map then call. The first ends in an
        // indirect jump; a table edge may bypass either map load entirely.
        let bytes = [0x48,0x8b,0x3d,0,0,0,0, 0xe8,0,0,0,0, 0xff,0xe0,
                     0x48,0x8b,0x3d,0,0,0,0, 0xe8,0,0,0,0, 0xc3];
        let sym = SymInfo { name: "entry".into(), section_index: object::SectionIndex(1),
                            address: 0x1000, size: bytes.len() as u64 };
        let got = HashMap::from([(local_site_key(&sym,3),"map".into()),
                                 (local_site_key(&sym,17),"map".into())]);
        let maps = HashMap::from([("map".into(),0x2000)]);
        for (targets, expected) in [
            (vec![sym.address+14], vec![7,21]),
            (vec![sym.address+7,sym.address+14], vec![21]),
            (vec![sym.address+7,sym.address+21], vec![]),
        ] {
            let sites = arguments(&bytes, &sym, &got, &HashMap::new(), &maps,
                &HashMap::from([(sym.address+12,targets)]))?;
            let mut actual: Vec<_> = sites.into_keys().collect();
            actual.sort_unstable();
            assert_eq!(actual, expected);
        }
        assert!(arguments(&bytes, &sym, &got, &HashMap::new(), &maps,
                          &HashMap::new())?.is_empty());
        Ok(())
    }
}
