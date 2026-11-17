#!/usr/bin/env python3
"""Size local probe branches before the builders publish recovery metadata."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/x86_probe_read.rs');s=p.read_text()
anchor='''fn append(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, ranges: &mut Vec<(usize,usize)>,'''
code='''fn compact(routine: (Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>))
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let (bytes, mut relocs, mut sites) = routine;
    let mut decoder = Decoder::new(64, &bytes, DecoderOptions::NONE);
    let instructions: Vec<_> = decoder.iter().collect();
    let indices: HashMap<_,_> = instructions.iter().enumerate()
        .map(|(i,insn)| (insn.ip() as u32,i)).collect();
    let encoded = BlockEncoder::encode(64, InstructionBlock::new(&instructions,0),
        BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS)?;
    for reloc in &mut relocs {reloc.offset=encoded.new_instruction_offsets[indices[&reloc.offset]];}
    for site in &mut sites {site.offset=encoded.new_instruction_offsets[indices[&site.offset]];}
    Ok((encoded.code_buffer,relocs,sites))
}

'''
assert s.count(anchor)==1;s=s.replace(anchor,code+anchor)
old='    Ok((b, Vec::new(), sites))'
assert s.count(old)==2
s=s.replace(old,'    compact((b, Vec::new(), sites))')
anchor='''    // A helper tail jump must stay a jump: adding a CALL adds a return frame.'''
test='''    #[test]
    fn local_branch_sizing_preserves_helper_slots_load_sites_and_global_append() -> Result<()> {
        // Both sides of the short-branch boundary, forward/backward edges,
        // and a relocated kernel-call slot before a recovered source load.
        let mut cases=0;
        for padding in [0,1,115,116,117,118,120,124,127,128,129,200] {
            let mut bytes=vec![0x48,0x89,0xf8,0x48,0x85,0xff]; // rax=rdi; test rdi
            let null=append_x86_jcc_rel32(&mut bytes,0x84);
            let forward=jump(&mut bytes);bytes.resize(bytes.len()+padding,0x90);
            let worker=bytes.len();patch_x86_rel32(&mut bytes,forward,worker)?;
            let call=bytes.len();bytes.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
            let load=bytes.len();bytes.extend_from_slice(&[0x48,0x8b,0x07,0xff,0xce]); // load; dec esi
            let again=append_x86_jcc_rel32(&mut bytes,0x85);patch_x86_rel32(&mut bytes,again,worker)?;
            let end=bytes.len();patch_x86_rel32(&mut bytes,null,end)?;bytes.push(0xc3);
            let routine=(bytes.clone(),vec![RelocRecord{offset:call as u32,kind:1,target:0x1234}],
                vec![LoadSite{offset:load as u32,insn_len:3,destination:11}]);
            let (sized,relocs,sites)=compact(routine)?;
            assert!(sized.len()<bytes.len());
            assert_eq!(&sized[relocs[0].offset as usize..relocs[0].offset as usize+5],
                X86_HELPER_CALL_REL32_SLOT.as_slice());
            assert_eq!((relocs[0].kind,relocs[0].target),(1,0x1234));
            assert_eq!((sites[0].insn_len,sites[0].destination),(3,11));
            assert_eq!(&sized[sites[0].offset as usize..sites[0].offset as usize+3],&bytes[load..load+3]);
            let mut a=Decoder::new(64,&bytes,DecoderOptions::NONE);
            let mut b=Decoder::new(64,&sized,DecoderOptions::NONE);
            let old:Vec<_>=a.iter().collect();let new:Vec<_>=b.iter().collect();
            assert_eq!(old.len(),new.len());
            let mapped:HashMap<_,_>=old.iter().zip(&new).map(|(a,b)|(a.ip(),b.ip())).collect();
            for (a,b) in old.iter().zip(&new) {
                assert_eq!((a.mnemonic(),a.condition_code()),(b.mnemonic(),b.condition_code()));
                if matches!(a.flow_control(),FlowControl::ConditionalBranch|FlowControl::UnconditionalBranch|FlowControl::Call) {
                    assert_eq!(b.near_branch64(),mapped[&a.near_branch64()]);
                }
            }
            let (twice,twice_relocs,twice_sites)=compact((sized.clone(),relocs.clone(),sites.clone()))?;
            assert_eq!(twice,sized);assert_eq!(twice_relocs[0].offset,relocs[0].offset);
            assert_eq!(twice_sites[0].offset,sites[0].offset);
            for prefix in [0,11] {
                let mut blob=vec![0x90;prefix];let mut global_relocs=Vec::new();
                let mut ranges=Vec::new();let mut global_sites=Vec::new();
                let start=append(&mut blob,&mut global_relocs,&mut ranges,&mut global_sites,
                    (sized.clone(),relocs.clone(),sites.clone()))?;
                assert_eq!(start,prefix);assert_eq!(ranges,vec![(prefix,prefix+sized.len())]);
                assert_eq!(global_sites[0].offset as usize,prefix+sites[0].offset as usize);
                let helper=blob.len();blob.extend_from_slice(&[0xfe,0x02,0xc3]); // inc byte [rdx]; ret
                patch_x86_rel32(&mut blob,global_relocs[0].offset as usize+1,helper)?;
                let source=0x123456789abcdef0u64;let mut hits=0u8;
                assert!(memory::call_blob(&blob,std::ptr::null_mut(),3,&mut hits as *mut _ as usize).is_null());
                assert_eq!(hits,0);
                for count in [1usize,3] {
                    hits=0;
                    let result=memory::call_blob(&blob,&source as *const _ as *mut u8,count,&mut hits as *mut _ as usize);
                    assert_eq!(result as u64,source);assert_eq!(hits as usize,count);
                }
                cases+=1;
            }
        }
        println!("Probe branch layout:24 mixed-edge/relocation/recovery/append cases PASS");
        Ok(())
    }

'''
assert s.count(anchor)==1;s=s.replace(anchor,test+anchor)
p.write_text(s)
