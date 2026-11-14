//! LPM lookup for the real OTel 12-data-byte shape. Generic helper remains for
//! other map types/data sizes. Caller retains the original RCU/lifetime contract.
use super::*;
fn mem(b:&mut Vec<u8>,op:&[u8],offset:u32)->Result<()> {
    b.extend_from_slice(op);b.extend_from_slice(&i32::try_from(offset)?.to_le_bytes());Ok(())
}
fn jmp(b:&mut Vec<u8>)->usize {b.push(0xe9);let at=b.len();b.extend_from_slice(&[0;4]);at}
pub(super) fn routine(l:&RuntimeLpmLayout)->Result<(Vec<u8>,usize)> {
    let mut b=Vec::new();
    mem(&mut b,&[0x81,0xbf],l.map_type)?;b.extend_from_slice(&l.lpm_type.to_le_bytes());
    let other_type=append_x86_jcc_rel32(&mut b,0x85);
    mem(&mut b,&[0x48,0x83,0xbf],l.data_size)?;b.push(12);
    let other_size=append_x86_jcc_rel32(&mut b,0x85);
    mem(&mut b,&[0x44,0x8b,0x96],l.key_prefixlen)?; // r10d=query prefix
    mem(&mut b,&[0x4c,0x3b,0x97],l.max_prefixlen)?;
    let invalid=append_x86_jcc_rel32(&mut b,0x87);
    b.extend_from_slice(&[0x45,0x31,0xc0]); // r8=best node
    mem(&mut b,&[0x48,0x8b,0x97],l.root)?; // rdx=current node
    let walk=b.len();b.extend_from_slice(&[0x48,0x85,0xd2]);
    let empty=append_x86_jcc_rel32(&mut b,0x84);
    mem(&mut b,&[0x44,0x8b,0x9a],l.node_prefixlen)?; // r11d=node prefix
    b.extend_from_slice(&[0x45,0x89,0xd9,0x45,0x39,0xd1,0x45,0x0f,0x47,0xca]); // r9d=min(node,query)
    mem(&mut b,&[0x48,0x8b,0x82],l.node_data)?;
    mem(&mut b,&[0x48,0x33,0x86],l.key_data)?;
    b.extend_from_slice(&[0x48,0x0f,0xc8,0x48,0x85,0xc0]); // big endian XOR
    let first_equal=append_x86_jcc_rel32(&mut b,0x84);
    b.extend_from_slice(&[0x48,0x0f,0xbd,0xc8,0xf7,0xd9,0x83,0xc1,63]); // ecx=63-bsr(diff)
    let first_done=jmp(&mut b);
    let second=b.len();patch_x86_rel32(&mut b,first_equal,second)?;
    b.extend_from_slice(&[0x41,0x83,0xf9,64]); // first chunk satisfies short prefix
    let short_prefix=append_x86_jcc_rel32(&mut b,0x86);
    mem(&mut b,&[0x8b,0x82],l.node_data+8)?;
    mem(&mut b,&[0x33,0x86],l.key_data+8)?;
    b.extend_from_slice(&[0x0f,0xc8,0x85,0xc0]);
    let all_equal=append_x86_jcc_rel32(&mut b,0x84);
    b.extend_from_slice(&[0x0f,0xbd,0xc8,0xf7,0xd9,0x83,0xc1,95]); // ecx=64+31-bsr(diff)
    let second_done=jmp(&mut b);
    let exact=b.len();patch_x86_rel32(&mut b,all_equal,exact)?;
    b.push(0xb9);b.extend_from_slice(&96u32.to_le_bytes());
    let exact_done=jmp(&mut b);
    let prefix64=b.len();patch_x86_rel32(&mut b,short_prefix,prefix64)?;
    b.push(0xb9);b.extend_from_slice(&64u32.to_le_bytes());
    let clamp=b.len();patch_x86_rel32(&mut b,exact_done,clamp)?;patch_x86_rel32(&mut b,first_done,clamp)?;patch_x86_rel32(&mut b,second_done,clamp)?;
    b.extend_from_slice(&[0x44,0x39,0xc9,0x41,0x0f,0x47,0xc9]); // min(common prefix,limit)
    mem(&mut b,&[0x48,0x3b,0x8f],l.max_prefixlen)?;
    let full=append_x86_jcc_rel32(&mut b,0x84);
    b.extend_from_slice(&[0x44,0x39,0xd9]);
    let mismatch=append_x86_jcc_rel32(&mut b,0x82);
    mem(&mut b,&[0xf7,0x82],l.node_flags)?;b.extend_from_slice(&1u32.to_le_bytes());
    let intermediate=append_x86_jcc_rel32(&mut b,0x85);
    b.extend_from_slice(&[0x49,0x89,0xd0]); // best=current, unless intermediate
    let descend=b.len();patch_x86_rel32(&mut b,intermediate,descend)?;
    b.extend_from_slice(&[0x44,0x89,0xd9,0xc1,0xe9,3]);
    mem(&mut b,&[0x0f,0xb6,0x84,0x0e],l.key_data)?; // key data[node prefix /8]
    b.extend_from_slice(&[0x44,0x89,0xd9,0x83,0xe1,7,0x83,0xf1,7,0xd3,0xe8,0x83,0xe0,1]);
    b.extend_from_slice(&[0x48,0x69,0xc0]);b.extend_from_slice(&i32::try_from(l.child_stride)?.to_le_bytes());
    mem(&mut b,&[0x48,0x8b,0x94,0x02],l.child)?;
    let back=jmp(&mut b);patch_x86_rel32(&mut b,back,walk)?;
    let found=b.len();patch_x86_rel32(&mut b,full,found)?;
    b.extend_from_slice(&[0x49,0x89,0xd0]); // exact max-prefix wins even before flags
    let finish=b.len();patch_x86_rel32(&mut b,empty,finish)?;patch_x86_rel32(&mut b,mismatch,finish)?;
    b.extend_from_slice(&[0x4d,0x85,0xc0]);let absent=append_x86_jcc_rel32(&mut b,0x84);
    mem(&mut b,&[0x49,0x8d,0x80],l.node_data+12)?;b.push(0xc3);
    let zero=b.len();patch_x86_rel32(&mut b,invalid,zero)?;patch_x86_rel32(&mut b,absent,zero)?;
    b.extend_from_slice(&[0x31,0xc0,0xc3]);
    let fallback=b.len();patch_x86_rel32(&mut b,other_type,fallback)?;patch_x86_rel32(&mut b,other_size,fallback)?;
    b.extend_from_slice(&[0x48,0x83,0xec,8]);let call=b.len();b.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
    b.extend_from_slice(&[0x48,0x83,0xc4,8,0xc3]);Ok((b,call))
}
pub(super) fn share(blob:&mut Vec<u8>,relocs:&mut Vec<RelocRecord>,layout:&RuntimeLpmLayout,
                    helper:u64)->Result<Option<(usize,usize)>> {
    let calls:Vec<_>=relocs.iter().filter(|r|r.kind==1&&r.target==helper).map(|r|r.offset as usize).collect();
    if calls.is_empty(){return Ok(None);}
    let start=blob.len();let (bytes,call)=routine(layout)?;
    for site in calls {
        if blob.get(site..site+5)!=Some(X86_HELPER_CALL_REL32_SLOT.as_slice()){bail!("LPM LTO lost generic-helper E8 slot");}
        patch_x86_rel32(blob,site+1,start)?;
    }
    relocs.retain(|r|!(r.kind==1&&r.target==helper));blob.extend_from_slice(&bytes);
    relocs.push(RelocRecord{offset:u32::try_from(start+call)?,kind:1,target:helper});Ok(Some((start,blob.len())))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    #[test]
    fn emitted_lpm_lookup_matches_bitwise_reference_and_preserves_other_types()->Result<()> {
        let layout=RuntimeLpmLayout{map_type:12,lpm_type:11,root:40,max_prefixlen:56,data_size:64,
            child:8,child_stride:8,node_prefixlen:32,node_flags:36,node_data:48,key_prefixlen:0,key_data:4};
        let out=std::env::var_os("NATIVE_LINK_LPM_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(||std::env::temp_dir().join(format!("lpm-lookup-{}",std::process::id())));
        fs::create_dir_all(&out)?;
        let root=PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../..");
        let driver=out.join("check");
        let cc=std::process::Command::new("cc").args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg(root.join("kprog/perf/native-context/test-lpm-lookup.c")).arg("-o").arg(&driver).output()?;
        fs::write(out.join("compile.stdout"),&cc.stdout)?;fs::write(out.join("compile.stderr"),&cc.stderr)?;
        if !cc.status.success(){bail!("LPM fixture compile: {}",String::from_utf8_lossy(&cc.stderr));}
        let (bytes,call)=routine(&layout)?;let binary=out.join("lpm.bin");fs::write(&binary,&bytes)?;
        let run=std::process::Command::new(driver).arg(binary).arg(call.to_string()).output()?;
        fs::write(out.join("stdout"),&run.stdout)?;fs::write(out.join("stderr"),&run.stderr)?;
        assert!(run.status.success(),"LPM host: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        println!("{}",String::from_utf8_lossy(&run.stdout));Ok(())
    }
}
