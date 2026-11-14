//! Mutable PC-relative data is an existing live DATASEC resource, never frozen
//! bytes in executable text or proof rodata. Keep the original variable name so
//! the loader binds its actual BTF offset and map lifetime.
use super::*;

pub(super) struct Reference {
    pub name: String,
    pub addend: i64,
    pub offset: i64,
}

pub(super) fn references(elf: &object::File, included: &[SymInfo])
    -> Result<HashMap<LocalSiteKey,Reference>> {
    let mut result=HashMap::new();
    for sym in included {
        let section=elf.section_by_index(sym.section_index)?;
        let bytes=read_symbol_bytes(elf,sym)?;
        let insns:Vec<_>=Decoder::with_ip(64,&bytes,sym.address,DecoderOptions::NONE).into_iter().collect();
        for (at,r) in section.relocations().filter(|(at,_)| *at>=sym.address && *at<sym.address+sym.size) {
            if !matches!(r.flags(),RelocationFlags::Elf{r_type:2}) {continue;}
            let RelocationTarget::Symbol(index)=r.target() else {continue;};
            let target=elf.symbol_by_index(index)?;
            let name=target.name()?;
            let data=target.section_index().map(|i|elf.section_by_index(i)).transpose()?;
            let writable=data.as_ref().is_some_and(|s| matches!(s.kind(),SectionKind::Data|SectionKind::UninitializedData) && s.name().ok()!=Some(".maps"));
            if !writable && !target.is_undefined() {continue;}
            let insn=insns.iter().find(|i|i.ip()<=at && at<i.next_ip())
                .ok_or_else(||anyhow!("PC32 data relocation outside decoded instruction"))?;
            if !insn.is_ip_rel_memory_operand() {continue;}
            let bias=i64::try_from(insn.next_ip()-at)?;
            let (name,base)=if target.size()>0 || target.is_undefined() {
                (name.to_owned(),target.address())
            } else {
                let address=i128::from(target.address())+i128::from(r.addend())+i128::from(bias);
                let variable=elf.symbols().find(|s|s.section_index()==target.section_index() &&
                    s.kind()==SymbolKind::Data && s.size()>0 &&
                    i128::from(s.address())<=address && address<i128::from(s.address())+i128::from(s.size()))
                    .ok_or_else(||anyhow!("mutable section {} offset {address:#x} lacks its data symbol",data.as_ref().unwrap().name().unwrap_or("?")))?;
                (variable.name()?.to_owned(),variable.address())
            };
            let addend=i64::try_from(i128::from(target.address())+i128::from(r.addend())-i128::from(base))?;
            result.insert(local_site_key(sym,at-sym.address),Reference{name,addend,offset:addend.checked_add(bias).ok_or_else(||anyhow!("mutable data offset overflow"))?});
        }
    }
    Ok(result)
}

pub(super) fn instructions(mut insn:Instruction,reference:&Reference,proof:bool)
    -> Result<Vec<(Instruction,Option<PatchKind>)>> {
    let mut factory=InstructionInfoFactory::new();
    let info=factory.info(&insn);
    let used:HashSet<_>=info.used_registers().iter().filter_map(|r|x86_gpr64_family(r.register())).collect();
    let lea=insn.mnemonic()==Mnemonic::Lea;
    if insn.flow_control()!=FlowControl::Next || (!lea && used.contains(&Register::RSP)) {
        bail!("mutable data reference {} requires an ordinary memory instruction",reference.name);
    }
    let scratch=if lea {x86_gpr64_family(insn.op0_register())} else {
        [Register::R11,Register::R10,Register::RAX,Register::RCX,Register::RDX]
            .into_iter().find(|r|!used.contains(r))
    }.ok_or_else(||anyhow!("mutable data reference has no address register"))?;
    let (low,high)=x86_gpr64_encoding(scratch)?;
    let stack=|op|->Result<Instruction>{
        let mut bytes=Vec::new();if high {bytes.push(0x41);}bytes.push(op+low);declared_bytes(&bytes)
    };
    let mut result=Vec::new();
    if !lea {result.push((stack(0x50)?,None));}
    if proof {
        let mut address=vec![0x48|if high {4} else {0},0x8d,0x05|(low<<3)];
        address.extend_from_slice(&[0;4]);
        result.push((declared_bytes(&address)?,Some(PatchKind::WritableAddress{name:reference.name.clone()})));
    } else {
        result.push((build_x86_movabs_reg(scratch,0)?,Some(PatchKind::MapImmediate{name:reference.name.clone(),imm_offset:2})));
    }
    insn.set_memory_base(scratch);insn.set_memory_index(Register::None);
    insn.set_memory_displacement64(reference.offset as u64);insn.set_memory_displ_size(if reference.offset==0 {0} else {8});
    result.push((insn,None));
    if !lea {result.push((stack(0x58)?,None));}
    Ok(result)
}
