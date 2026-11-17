#!/usr/bin/env python3
"""Reproduce and fix source-label loss at inline helper entry chunks."""
from pathlib import Path
import sys
p=Path('kprog/x86/native_lab/native_link/src/x86.rs')
s=p.read_text()
if sys.argv[1]=='test':
    anchor='    #[test]\n    fn kernel_tail_calls_always_relocate_the_counter_frame() -> Result<()> {'
    test='''    #[test]
    #[cfg(all(target_arch="x86_64",target_os="linux"))]
    fn branches_enter_direct_loads_and_tail_stubs_at_the_original_call_label() -> Result<()> {
        let mut ticks=0u64;
        let layout=RuntimeProbeReadLayout{user_helper:0x1000,kernel_helper:0x2000,current_task:0,
            jiffies:Some(&mut ticks as *mut u64 as u64),user_ptr_max:0,boot_cpu_data:0,
            pagefault_disabled:0,x86_capability:0,task_flags:0,task_personality:0,ktime:None,cred:None,
            cpu_tlbstate:0,tlb_loaded_mm:0,task_mm:0,x86_virt_bits:0};
        let helpers=HashMap::from([("bpf_probe_read_kernel".into(),0x2000),
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.into(),68),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.into(),304),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.into(),72),
            (X86_TAIL_CALL_OFFSET_KEY.into(),12)]);
        let mut cases=0;
        for (name,id,tail) in [("bpf_jiffies64",118,false),("bpf_tail_call",12,true)] {
            for named in [false,true] { for base in [0usize,32] { for skip_nop in [0u8,1] {
                let mut bytes=if named {vec![]} else {vec![0xb8,id,0,0,0]};
                bytes.extend_from_slice(&[0x85,0xff,0x74,skip_nop,0x90]);
                let call=bytes.len();
                bytes.extend_from_slice(if named {&[0xe8,0,0,0,0][..]} else {&[0xff,0xd0][..]});
                if tail {bytes.extend_from_slice(&[0x48,0x89,0xd0]);}
                bytes.push(0xc3);
                let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
                let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
                object.append_section_data(text,&vec![0x90;base],1);
                object.append_section_data(text,&bytes,1);
                object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:base as u64,size:bytes.len() as u64,
                    kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                    section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
                if named {
                    let helper=object.add_symbol(WriteSymbol{name:name.as_bytes().to_vec(),value:0,size:0,
                        kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                        section:WriteSymbolSection::Undefined,flags:SymbolFlags::None});
                    object.add_relocation(text,WriteRelocation{offset:(base+call+1) as u64,symbol:helper,addend:-4,
                        flags:RelocationFlags::Elf{r_type:4}})?;
                }
                let encoded=object.write()?;let elf=object::File::parse(encoded.as_slice())?;
                let entry=find_symbol_by_name(&elf,"entry")?;
                let output=rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),&HashMap::new(),
                    &[],false,false,None,Some(&layout),None,false)?;
                let branch=decode_x86(&output.blob)?.into_iter().find(|i|i.is_jcc_short_or_near()).unwrap();
                let target=branch.near_branch_target() as usize;
                let marker=if tail {&[0x89,0xd2][..]} else {&[0x48,0xa1][..]};
                assert_eq!(output.blob.get(target..target+marker.len()),Some(marker),
                    "branch skipped {name}: named={named} base={base} nop={skip_nop}");
                assert_eq!(output.relocs.len(),usize::from(tail));
                if tail {assert_eq!(output.relocs[0].kind,NATIVE_LAB_RELOC_X86_TAIL_COUNT);}
                let mut blob=output.blob;blob.push(0xc3);
                let mut map=[0u8;72];
                for value in [0u64,0x1122334455667788,u64::MAX] {
                    unsafe{std::ptr::write_volatile(&mut ticks,value);}
                    for selector in [0usize,1] {
                        let actual=memory::call_blob(&blob,selector as *mut u8,map.as_mut_ptr() as usize,
                            0x100000001) as u64;
                        assert_eq!(actual,if tail {1}else{value},"{name} selector={selector}");
                        cases+=1;
                    }
                }
            } } }
        }
        println!("inline helper labels: {cases} branch/fallthrough/live-load/tail-miss executions PASS");
        Ok(())
    }

'''
    assert s.count(anchor)==1
    s=s.replace(anchor,test+anchor)
elif sys.argv[1]=='fix':
    old='''                            push_x86_synthetic(
                                &mut local,
                                &mut kinds,
                                &mut insn_local_ip,
                                &mut next_synthetic_ip,
                                ib,
                            )?;
                            if chunk_index == field_chunk {'''
    new='''                            if chunk_index == 0 {
                                push_x86_replacement(&mut local,&mut kinds,&mut insn_local_ip,local_ip,ib,None);
                            } else {
                                push_x86_synthetic(&mut local,&mut kinds,&mut insn_local_ip,&mut next_synthetic_ip,ib)?;
                            }
                            if chunk_index == field_chunk {'''
    assert s.count(old)==1
    s=s.replace(old,new)
    old='''                        for ib in inline {
                            push_x86_synthetic(&mut local,&mut kinds,&mut insn_local_ip,&mut next_synthetic_ip,ib)?;
                        }'''
    new='''                        for (index,ib) in inline.into_iter().enumerate() {
                            if index == 0 {
                                push_x86_replacement(&mut local,&mut kinds,&mut insn_local_ip,local_ip,ib,None);
                            } else {
                                push_x86_synthetic(&mut local,&mut kinds,&mut insn_local_ip,&mut next_synthetic_ip,ib)?;
                            }
                        }'''
    assert s.count(old)==1
    s=s.replace(old,new)
else:
    raise ValueError('Use test or fix')
p.write_text(s)
