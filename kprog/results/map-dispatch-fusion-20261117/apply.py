#!/usr/bin/env python3
"""One-shot test/fix recipe: reuse ARRAY prefix and LPM body with one helper frame."""
from pathlib import Path
import sys
root=Path('kprog/x86/native_lab/native_link/src')
x=root/'x86.rs'
if sys.argv[1]=='test':
    s=x.read_text()
    anchor='    #[test]\n    fn kernel_tail_calls_always_relocate_the_counter_frame() -> Result<()> {'
    test='''    #[test]
    #[cfg(all(target_arch="x86_64",target_os="linux"))]
    fn map_dispatch_fusion_keeps_one_helper_frame_and_original_lookup_results() -> Result<()> {
        let array=RuntimeArrayLayout{map_type:12,max_entries:24,elem_size:32,
            index_mask:36,value:64,array_type:2};
        let lpm=RuntimeLpmLayout{map_type:12,lpm_type:11,root:40,max_prefixlen:56,data_size:64,
            child:8,child_stride:8,node_prefixlen:32,node_flags:36,node_data:48,key_prefixlen:0,key_data:4};
        let mut cases=0;
        for tail in [false,true] {for (a,l) in [(None,None),(Some(&array),None),(None,Some(&lpm)),(Some(&array),Some(&lpm))] {
            let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
            let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
            let code=if tail {vec![0xb8,1,0,0,0,0xff,0xe0]}else{vec![0x48,0x83,0xec,8,0xb8,1,0,0,0,0xff,0xd0,0x48,0x83,0xc4,8,0xc3]};
            object.append_section_data(text,&code,1);
            object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:0,size:code.len() as u64,
                kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
            let bytes=object.write()?;let elf=object::File::parse(bytes.as_slice())?;
            let entry=find_symbol_by_name(&elf,"entry")?;
            let linked=rewrite_x86(&elf,&entry,&[entry.clone()],
                &HashMap::from([("bpf_map_lookup_elem".into(),0x1234)]),&HashMap::new(),&HashMap::new(),
                &[],false,false,a,None,l,false)?;
            assert_eq!(linked.relocs.len(),1,"one final generic helper relocation");
            let relocation=linked.relocs[0];
            assert_eq!((relocation.kind,relocation.target),(NATIVE_LAB_RELOC_HELPER_CALL_REL32,0x1234));
            let site=relocation.offset as usize;
            assert_eq!(&linked.blob[site..site+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),"external ABI stays E8");
            if a.is_some() && l.is_some() {
                let calls=decode_x86(&linked.blob)?.iter().filter(|i|i.mnemonic()==Mnemonic::Call).count();
                assert_eq!(calls,2,"ARRAY must enter LPM without another call frame");
                if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                    fs::write(PathBuf::from(out).join(format!("map-dispatch-fused-{tail}.bin")),&linked.blob)?;
                }
            }
            let mut blob=linked.blob;blob.push(0xc3);let target=blob.len();
            // Count generic calls, check SysV alignment, return original map XOR key.
            blob.extend_from_slice(&[0x48,0xff,0x02,0x48,0x89,0xe0,0x83,0xe0,15,0x83,0xf8,8,
                0x74,6,0xb8,0xfe,0xca,0xad,0xde,0xc3,0x48,0x89,0xf8,0x48,0x31,0xf0,0xc3]);
            blob[site+1..site+5].copy_from_slice(&i32::try_from(target as i64-site as i64-5)?.to_le_bytes());
            let mut map=[0u8;128];let mut node=[0u8;128];let mut key=[0u8;16];
            let put32=|b:&mut [u8],o:usize,v:u32|b[o..o+4].copy_from_slice(&v.to_le_bytes());
            let put64=|b:&mut [u8],o:usize,v:u64|b[o..o+8].copy_from_slice(&v.to_le_bytes());
            let mp=map.as_mut_ptr();let kp=key.as_ptr() as usize;let mut callbacks=0u64;
            for kind in [2u32,11,1] {for index in [0u32,1,4,5,u32::MAX] {
                map.fill(0);key.fill(0);node.fill(0);
                put32(&mut map,12,kind);put32(&mut map,24,5);put32(&mut map,32,24);put32(&mut map,36,7);
                put32(&mut key,0,if kind==11 {96}else{index});
                put64(&mut map,40,node.as_ptr() as u64);put64(&mut map,56,96);put64(&mut map,64,12);
                put32(&mut node,32,96);
                let expected=if kind==2 && a.is_some() {if index<5 {mp as usize+64+index as usize*24}else{0}}
                    else if kind==11 && l.is_some() {node.as_ptr() as usize+60}else{mp as usize^kp};
                let generic=!(kind==2&&a.is_some() || kind==11&&l.is_some());
                callbacks=0;
                let result=memory::call_blob(&blob,mp,kp,&mut callbacks as *mut u64 as usize) as usize;
                assert_eq!(result,expected,"tail={tail} ARRAY={} LPM={} kind={kind} index={index}",a.is_some(),l.is_some());
                assert_eq!(unsafe{std::ptr::read_volatile(&callbacks)},u64::from(generic));cases+=1;
            }}
        }}
        println!("map dispatch fusion: {cases} actual rewrite CALL/JMP, facts-present/absent, ARRAY/LPM/generic results and helper ABI cases PASS");
        Ok(())
    }

'''
    assert s.count(anchor)==1
    x.write_text(s.replace(anchor,test+anchor))
elif sys.argv[1]=='fix':
    p=root/'x86_runtime_array.rs';s=p.read_text()
    old='''                    layout: &RuntimeArrayLayout, helper: u64) -> Result<Option<(usize, usize)>> {'''
    new='''                    layout: &RuntimeArrayLayout, helper: u64,
                    lpm: Option<&RuntimeLpmLayout>) -> Result<Option<(usize, usize)>> {'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='''    let (bytes, call) = routine(layout)?;
    probe_read::redirect(blob, &sites, start)?;'''
    new='''    // Non-ARRAY dispatch enters the existing LPM body in the same frame.
    // Its final generic call retains the external E8 slot required by loaders.
    let (bytes, nested) = if let Some(lpm) = lpm {
        let mut bytes = build_prefix(layout)?;
        let prefix = bytes.len();
        let (body, mut nested) = lpm_lookup::routine(lpm, helper)?;
        bytes.extend_from_slice(&body);
        for r in &mut nested { r.offset = u32::try_from(prefix + r.offset as usize)?; }
        (bytes, nested)
    } else {
        let (bytes, call) = routine(layout)?;
        (bytes, vec![RelocRecord { offset: u32::try_from(call)?,
            kind: NATIVE_LAB_RELOC_HELPER_CALL_REL32, target: helper }])
    };
    probe_read::redirect(blob, &sites, start)?;'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='''    relocs.push(RelocRecord { offset: u32::try_from(start + call)?,
        kind: NATIVE_LAB_RELOC_HELPER_CALL_REL32, target: helper });'''
    new='''    for mut r in nested { r.offset = u32::try_from(start + r.offset as usize)?; relocs.push(r); }'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='share(&mut blob, &mut relocs, &layout, 0x1234)?';assert s.count(old)==1
    s=s.replace(old,'share(&mut blob, &mut relocs, &layout, 0x1234, None)?');p.write_text(s)
    s=x.read_text()
    old='runtime_array::share(&mut blob, &mut relocs, layout, map_lookup_helper_addr)?'
    assert s.count(old)==1;s=s.replace(old,'runtime_array::share(&mut blob, &mut relocs, layout, map_lookup_helper_addr, runtime_lpm_layout)?')
    old='show_lto_range(show, "runtime_array", range);';assert s.count(old)==1
    s=s.replace(old,'show_lto_range(show, if runtime_lpm_layout.is_some() {"runtime_array_lpm"} else {"runtime_array"}, range);')
    old='runtime_lpm_layout.filter(|_| !proof_mode)';assert s.count(old)==1
    s=s.replace(old,'runtime_lpm_layout.filter(|_| !proof_mode && runtime_array_layout.is_none())');x.write_text(s)
else:
    raise ValueError('Use test or fix')
