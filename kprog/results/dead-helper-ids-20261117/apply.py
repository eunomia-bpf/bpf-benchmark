#!/usr/bin/env python3
"""Remove only adjacent nonlabel RAX ID definitions after a helper is resolved."""
from pathlib import Path
import sys
p=Path('kprog/x86/native_lab/native_link/src/x86.rs');s=p.read_text()
if sys.argv[1]=='test':
    anchor='    #[test]\n    fn kernel_tail_calls_always_relocate_the_counter_frame() -> Result<()> {'
    test='''    #[test]
    #[cfg(all(target_arch="x86_64",target_os="linux"))]
    fn bound_helpers_drop_only_dead_adjacent_rax_ids_and_keep_proof_and_tail_state() -> Result<()> {
        let helpers=HashMap::from([("bpf_get_current_pid_tgid".into(),0x1234),
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.into(),68),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.into(),304),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.into(),72),(X86_TAIL_CALL_OFFSET_KEY.into(),12)]);
        let link=|code:&[u8],proof:bool| -> Result<RewriteResult> {
            let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
            let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
            object.append_section_data(text,code,1);
            object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:0,size:code.len() as u64,
                kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
            let bytes=object.write()?;let elf=object::File::parse(bytes.as_slice())?;
            let entry=find_symbol_by_name(&elf,"entry")?;
            rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),&HashMap::new(),
                &[],proof,false,None,None,None,false)
        };
        let definitions=|bytes:&[u8],id:u64| -> Result<usize> {Ok(decode_x86(bytes)?.iter()
            .filter(|i|x86_mov_imm_to_gpr64(i).is_some_and(|(_,value)|value==id)).count())};
        let forms:Vec<(Vec<u8>,usize)>=vec![
            (vec![0xb8,14,0,0,0,0xff,0xd0,0xc3],0),
            (vec![0x85,0xff,0x74,1,0x90,0xb8,14,0,0,0,0xff,0xd0,0xc3],1),
            (vec![0xb8,14,0,0,0,0x85,0xff,0x74,5,0xb8,14,0,0,0,0xff,0xd0,0xc3],1),
            (vec![0xb8,14,0,0,0,0x85,0xff,0xff,0xd0,0xc3],1),
            (vec![0x41,0xbb,14,0,0,0,0x41,0xff,0xd3,0xc3],1),
            (vec![0x48,0xb8,14,0,0,0,0,0,0,0,0xff,0xd0,0xc3],0),
            (vec![0x48,0xc7,0xc0,14,0,0,0,0xff,0xd0,0xc3],0)];
        let mut cases=0;
        for (index,(bytes,expected)) in forms.iter().enumerate() {
            let proof=link(bytes,true)?;
            assert_eq!(definitions(&proof.blob,14)?,definitions(bytes,14)?,"proof retains IDs form{index}");
            let linked=link(bytes,false)?;
            assert_eq!(definitions(&linked.blob,14)?,*expected,"dead ID form{index}");
            assert_eq!(linked.relocs.len(),1);assert_eq!(linked.relocs[0].target,0x1234);
            let relocation=linked.relocs[0];
            assert_eq!(relocation.kind,NATIVE_LAB_RELOC_HELPER_CALL_REL32);
            let mut blob=linked.blob;blob.push(0xc3);let target=blob.len();
            // Count the helper and return RDI XOR RDX without changing callee-saved registers.
            blob.extend_from_slice(&[0x48,0xff,0x06,0x48,0x89,0xf8,0x48,0x31,0xd0,0xc3]);
            let offset=relocation.offset as usize;
            blob[offset+1..offset+5].copy_from_slice(&i32::try_from(target as i64-offset as i64-5)?.to_le_bytes());
            let mut calls=0u64;
            for argument in [0usize,7,65537,usize::MAX] {for selector in [0usize,1] {
                let result=memory::call_blob(&blob,selector as *mut u8,&mut calls as *mut u64 as usize,argument) as usize;
                assert_eq!(result,selector^argument,"args/return form{index}");cases+=1;
            }}
            assert_eq!(unsafe{std::ptr::read_volatile(&calls)},8,"one helper per invocation");
        }
        let tail=link(&[0xb8,12,0,0,0,0xff,0xd0,0xc3],false)?;
        assert_eq!(definitions(&tail.blob,12)?,1,"tail miss state stays untouched");
        let mut tail=tail.blob;tail.push(0xc3);let mut map=[0u8;72];
        assert_eq!(memory::call_blob(&tail,std::ptr::null_mut(),map.as_mut_ptr() as usize,1) as usize,12);
        println!("dead helper IDs: {cases} argument/return/call executions, seven proof shapes and tail miss PASS");
        Ok(())
    }

'''
    assert s.count(anchor)==1;s=s.replace(anchor,test+anchor)
elif sys.argv[1]=='fix':
    anchor='''        let proven_helpers = &helper_calls.single;'''
    prefix='''        // Keep code-entry labels, including resolved table targets, intact.
        let incoming_labels:HashSet<_>=Decoder::with_ip(64,&bytes,sym.address,DecoderOptions::NONE)
            .into_iter().filter(|i|matches!(i.flow_control(),
                FlowControl::ConditionalBranch|FlowControl::UnconditionalBranch))
            .map(|i|i.near_branch_target())
            .chain(helper_calls.branch_targets.values().flatten().copied())
            .filter_map(|ip|ip.checked_sub(sym.address)).collect();
'''
    assert s.count(anchor)==1;s=s.replace(anchor,prefix+anchor)
    anchor='''                    if let Some(inline)=probe_read::direct_load(runtime_probe_read_layout,helper_addrs,&name)? {'''
    prefix='''                    // The resolved call defines RAX; its adjacent target ID is dead.
                    // Proof, finite dispatch and tail-call state are handled above.
                    if call_reg==Some(Register::RAX) && matches!(kinds.last(),Some(None))
                        && local.last().is_some_and(|previous|
                            matches!(previous.op0_register(),Register::EAX|Register::RAX)
                            && previous.next_ip()==local_ip && !incoming_labels.contains(&previous.ip())
                            && x86_mov_imm_to_gpr64(previous).is_some_and(|(_,id)|
                                bpf_helper_name_from_id(id)==Some(name.as_str()))) {
                        let keep=local.len()-1;
                        local.truncate(keep);kinds.truncate(keep);insn_local_ip.truncate(keep);
                    }
'''
    assert s.count(anchor)==1;s=s.replace(anchor,prefix+anchor)
else:raise ValueError('Use test or fix')
p.write_text(s)
