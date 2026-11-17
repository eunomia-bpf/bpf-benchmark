#!/usr/bin/env python3
"""Reuse routine-local sizing for LPM and clock with real helper relocations."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/x86_probe_read.rs');s=p.read_text()
old='fn compact(routine: (Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>))'
assert s.count(old)==1;s=s.replace(old,'pub(super) '+old);p.write_text(s)
p=Path('kprog/x86/native_lab/native_link/src/x86_ktime.rs');s=p.read_text()
old='''    Ok((b, relocs))
}'''
new='''    let (bytes, relocs, _) = probe_read::compact((b, relocs, Vec::new()))?;
    Ok((bytes, relocs))
}'''
assert s.count(old)==1;s=s.replace(old,new)
old='''        assert_eq!(relocs.len(), 3);
        let mut text'''
new='''        assert_eq!(relocs.len(), 3);
        assert_eq!(relocs.iter().map(|r|r.target).collect::<Vec<_>>(),[0x4000,0x4000,0x5000]);
        for r in &relocs {
            assert_eq!(&bytes[r.offset as usize..r.offset as usize+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),
                "sizing must preserve each external E8+zero patch slot");
        }
        let mut text'''
assert s.count(old)==1;s=s.replace(old,new)
old='''        assert_eq!(calls.len(), 4, "the other call stays and the leaf brings its three calls");'''
new='''        for r in calls.iter().filter(|r|r.target!=0x9999) {
            assert_eq!(&blob[r.offset as usize..r.offset as usize+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),
                "shared helper relocation must include the final leaf offset exactly once");
        }
        assert_eq!(calls.len(), 4, "the other call stays and the leaf brings its three calls");'''
assert s.count(old)==1;s=s.replace(old,new);p.write_text(s)
p=Path('kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs');s=p.read_text()
old='pub(super) fn routine(l:&RuntimeLpmLayout)->Result<(Vec<u8>,usize)> {'
new='pub(super) fn routine(l:&RuntimeLpmLayout,helper:u64)->Result<(Vec<u8>,Vec<RelocRecord>)> {'
assert s.count(old)==1;s=s.replace(old,new)
old='''    b.extend_from_slice(&[0x48,0x83,0xc4,8,0xc3]);Ok((b,call))'''
new='''    b.extend_from_slice(&[0x48,0x83,0xc4,8,0xc3]);
    let nested=vec![RelocRecord{offset:call as u32,kind:1,target:helper}];
    let (bytes,relocs,_)=probe_read::compact((b,nested,Vec::new()))?;
    Ok((bytes,relocs))'''
assert s.count(old)==1;s=s.replace(old,new)
old='''    let start=blob.len();let (bytes,call)=routine(layout)?;
    probe_read::redirect(blob,&calls,start)?;
    relocs.retain(|r|!(r.kind==1&&r.target==helper));blob.extend_from_slice(&bytes);
    relocs.push(RelocRecord{offset:u32::try_from(start+call)?,kind:1,target:helper});Ok(Some((start,blob.len())))'''
new='''    let start=blob.len();let (bytes,nested)=routine(layout,helper)?;
    probe_read::redirect(blob,&calls,start)?;
    relocs.retain(|r|!(r.kind==1&&r.target==helper));blob.extend_from_slice(&bytes);
    for mut r in nested {r.offset=u32::try_from(start+r.offset as usize)?;relocs.push(r);}
    Ok(Some((start,blob.len())))'''
assert s.count(old)==1;s=s.replace(old,new)
s=s.replace('let (code,_)=routine(&l)?;','let (code,_)=routine(&l,0x1234)?;')
old='''        let (bytes,call)=routine(&layout)?;let binary=out.join("lpm.bin");fs::write(&binary,&bytes)?;
        let run=std::process::Command::new(driver).arg(binary).arg(call.to_string()).output()?;'''
new='''        let (bytes,nested)=routine(&layout,0x1234)?;
        assert_eq!(nested.len(),1);assert_eq!((nested[0].kind,nested[0].target),(1,0x1234));
        let call=nested[0].offset as usize;
        assert_eq!(&bytes[call..call+5],X86_HELPER_CALL_REL32_SLOT.as_slice());
        let binary=out.join("lpm.bin");fs::write(&binary,&bytes)?;
        let run=std::process::Command::new(driver).arg(binary).arg(call.to_string()).output()?;'''
assert s.count(old)==1;s=s.replace(old,new)
old='''        assert_eq!(relocs.len(),1,"only the existing generic kernel call remains");'''
new='''        assert_eq!(relocs.len(),1,"only the existing generic kernel call remains");
        assert_eq!((relocs[0].offset as usize,relocs[0].target),(range.0+call,0x1234),
            "sized helper slot must receive the shared leaf shift exactly once");'''
assert s.count(old)==1;s=s.replace(old,new);p.write_text(s)
