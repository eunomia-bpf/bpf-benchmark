//! Key-size-specialized raw htab lookup. Matches hashtab.c lookup_nulls_elem_raw:
//! live seed/buckets, Jenkins32, exact key equality, nulls-marker retry and raw
//! element return. Existing caller supplies map lifetime/RCU and postprocessing.
use super::*;

fn disp(b: &mut Vec<u8>, op: &[u8], offset: u32) -> Result<()> {
    b.extend_from_slice(op);
    b.extend_from_slice(&i32::try_from(offset)?.to_le_bytes());
    Ok(())
}
fn jump(b: &mut Vec<u8>) -> usize {
    b.push(0xe9); let offset=b.len(); b.extend_from_slice(&[0;4]); offset
}
// a,b,c live in r8d,r9d,r10d; all arithmetic wraps at32 bits like jhash2.
fn alu(b: &mut Vec<u8>, op:u8, dst:u8, src:u8) {
    b.extend_from_slice(&[0x45,op,0xc0|(src<<3)|dst]);
}
fn rotate(b:&mut Vec<u8>,src:u8,n:u8) {
    b.extend_from_slice(&[0x44,0x89,0xc0|(src<<3),0xc1,0xc0,n]); // eax=rol(src,n)
}
fn temp(b:&mut Vec<u8>,op:u8,dst:u8) { b.extend_from_slice(&[0x41,op,0xc0|dst]); }
fn hash(b:&mut Vec<u8>,layout:&RuntimeHashLayout,size:u32) -> Result<()> {
    disp(b,&[0x44,0x8b,0x87],layout.hashrnd)?; // a=live seed
    b.extend_from_slice(&[0x41,0x81,0xc0]);
    b.extend_from_slice(&0xdead_beefu32.wrapping_add(size).to_le_bytes());
    b.extend_from_slice(&[0x45,0x89,0xc1,0x45,0x89,0xc2]); // b=c=a
    if size==16 {
        for reg in 0..3 { disp(b,&[0x44,0x03,0x86|(reg<<3)],u32::from(reg)*4)?; }
        for (dst,src,n,add_dst,add_src) in [(0,2,4,2,1),(1,0,6,0,2),(2,1,8,1,0),
            (0,2,16,2,1),(1,0,19,0,2),(2,1,4,1,0)] {
            alu(b,0x29,dst,src);rotate(b,src,n);temp(b,0x31,dst);alu(b,0x01,add_dst,add_src);
        }
        disp(b,&[0x44,0x03,0x86],12)?;
    } else {
        // Match jhash2's final-word switch order c,b,a.
        for reg in (0..(size/4) as u8).rev() { disp(b,&[0x44,0x03,0x86|(reg<<3)],u32::from(reg)*4)?; }
    }
    for (dst,src,n) in [(2,1,14),(0,2,11),(1,0,25),(2,1,16),(0,2,4),(1,0,14),(2,1,24)] {
        alu(b,0x31,dst,src);rotate(b,src,n);temp(b,0x29,dst);
    }
    Ok(())
}

fn lookup(layout:&RuntimeHashLayout,size:u32) -> Result<Vec<u8>> {
    let mut b=Vec::new();hash(&mut b,layout,size)?;
    disp(&mut b,&[0x44,0x8b,0x87],layout.n_buckets)?;
    b.extend_from_slice(&[0x41,0xff,0xc8,0x45,0x21,0xd0]); // r8d=(n-1)&hash
    disp(&mut b,&[0x48,0x8b,0x97],layout.buckets)?; // actual bucket array
    b.extend_from_slice(&[0x44,0x89,0xc1,0x48,0x69,0xc9]);
    b.extend_from_slice(&i32::try_from(layout.bucket_size)?.to_le_bytes());
    disp(&mut b,&[0x48,0x8d,0x94,0x0a],layout.head)?; // rdx=&buckets[index].head
    let again=b.len();disp(&mut b,&[0x48,0x8b,0x82],layout.first)?;
    let walk=b.len();b.extend_from_slice(&[0xa8,1]);
    let null=append_x86_jcc_rel32(&mut b,0x85);
    if layout.node!=0 { b.extend_from_slice(&[0x48,0x2d]);b.extend_from_slice(&i32::try_from(layout.node)?.to_le_bytes()); }
    disp(&mut b,&[0x44,0x39,0x90],layout.hash)?;
    let mut next=vec![append_x86_jcc_rel32(&mut b,0x85)];
    // Kernel generic memcmp first compares ulong chunks. On a differing chunk
    // it rechecks that remaining range bytewise; preserve this access shape.
    let mut byte_fixes=Vec::new();
    let words=size/8;
    for i in 0..words {
        disp(&mut b,&[0x48,0x8b,0x88],layout.key+i*8)?;
        disp(&mut b,&[0x48,0x3b,0x8e],i*8)?;
        byte_fixes.push((append_x86_jcc_rel32(&mut b,0x85),i*8));
    }
    if size%8==0 { b.push(0xc3); } else { byte_fixes.push((jump(&mut b),words*8)); }
    let mut byte_labels=Vec::new();
    for i in 0..size {
        byte_labels.push(b.len());
        disp(&mut b,&[0x0f,0xb6,0x88],layout.key+i)?;
        disp(&mut b,&[0x3a,0x8e],i)?;
        next.push(append_x86_jcc_rel32(&mut b,0x85));
    }
    b.push(0xc3);
    for (fix,offset) in byte_fixes {patch_x86_rel32(&mut b,fix,byte_labels[offset as usize])?;}
    let next_label=b.len();for fix in next {patch_x86_rel32(&mut b,fix,next_label)?;}
    disp(&mut b,&[0x48,0x8b,0x80],layout.node+layout.next)?;
    let back=jump(&mut b);patch_x86_rel32(&mut b,back,walk)?;
    let null_label=b.len();patch_x86_rel32(&mut b,null,null_label)?;
    b.extend_from_slice(&[0x48,0x89,0xc1,0x48,0xd1,0xe9,0x4c,0x39,0xc1]); // marker>>1 ==index
    let retry=append_x86_jcc_rel32(&mut b,0x85);patch_x86_rel32(&mut b,retry,again)?;
    b.extend_from_slice(&[0x31,0xc0,0xc3]);
    Ok(b)
}

pub(super) fn routine(layout:&RuntimeHashLayout) -> Result<(Vec<u8>,usize)> {
    let mut b=Vec::new();disp(&mut b,&[0x8b,0x87],layout.key_size)?;
    let mut entries=Vec::new();
    for size in [4u8,8,12,16] {
        b.extend_from_slice(&[0x83,0xf8,size]);entries.push((append_x86_jcc_rel32(&mut b,0x84),size));
    }
    // Other key sizes retain the original raw helper, with unchanged arguments.
    b.extend_from_slice(&[0x48,0x83,0xec,8]);let call=b.len();
    b.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
    b.extend_from_slice(&[0x48,0x83,0xc4,8,0xc3]);
    for (fix,size) in entries {
        let start=b.len();patch_x86_rel32(&mut b,fix,start)?;
        b.extend_from_slice(&lookup(layout,u32::from(size))?);
    }
    Ok((b,call))
}

pub(super) fn share(blob:&mut Vec<u8>,relocs:&mut Vec<RelocRecord>,layout:&RuntimeHashLayout,
                    facts:&HashMap<String,LookupSiteSpec>) -> Result<Vec<(usize,usize)>> {
    let targets:HashSet<u64>=facts.values().filter(|s|matches!(s.kind,
        LookupKind::Hash|LookupKind::LruHash|LookupKind::PerCpuHash|LookupKind::HashOfMaps))
        .map(|s|s.target_addr).collect();
    let mut targets:Vec<_>=targets.into_iter().collect();targets.sort_unstable();
    let mut ranges=Vec::new();
    for target in targets {
        let calls:Vec<_>=relocs.iter().filter(|r|r.kind==1 && r.target==target).map(|r|r.offset as usize).collect();
        if calls.is_empty() {continue;}
        let start=blob.len();let (bytes,call)=routine(layout)?;
        for &site in &calls {
            if blob.get(site..site+5)!=Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {bail!("hash LTO lost raw-helper E8 slot");}
            patch_x86_rel32(blob,site+1,start)?;
        }
        relocs.retain(|r|!(r.kind==1 && r.target==target));
        blob.extend_from_slice(&bytes);
        relocs.push(RelocRecord{offset:u32::try_from(start+call)?,kind:1,target});
        ranges.push((start,blob.len()));
    }
    Ok(ranges)
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    fn fixture()->RuntimeHashLayout {
        RuntimeHashLayout{key_size:12,buckets:40,n_buckets:32,hashrnd:20,
            bucket_size:32,head:8,first:0,node:8,next:0,hash:32,key:40}
    }
    #[test]
    fn emitted_hash_lookup_matches_kernel_jhash_and_nulls_semantics()->Result<()> {
        let output=std::env::var_os("NATIVE_LINK_HASH_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(||std::env::temp_dir().join(format!("hash-lookup-{}",std::process::id())));
        fs::create_dir_all(&output)?;
        let root=PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../..");
        let driver=output.join("check");
        let compile=std::process::Command::new("cc").args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg("-isystem").arg(root.join("vendor/linux-framework/tools/include"))
            .arg(root.join("kprog/perf/native-context/test-hash-lookup.c"))
            .args(["-pthread","-o"]).arg(&driver).output()?;
        fs::write(output.join("compile.stdout"),&compile.stdout)?;fs::write(output.join("compile.stderr"),&compile.stderr)?;
        if !compile.status.success(){bail!("hash host fixture compile: {}",String::from_utf8_lossy(&compile.stderr));}
        let (bytes,call)=routine(&fixture())?;let binary=output.join("hash.bin");fs::write(&binary,&bytes)?;
        let run=std::process::Command::new(driver).arg(binary).arg(call.to_string()).output()?;
        fs::write(output.join("stdout"),&run.stdout)?;fs::write(output.join("stderr"),&run.stderr)?;
        assert!(run.status.success(),"hash host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        println!("{}",String::from_utf8_lossy(&run.stdout));
        Ok(())
    }
    #[test]
    fn hash_sharing_uses_only_typed_raw_targets_and_keeps_call_postprocessing()->Result<()> {
        let mut blob=X86_HELPER_CALL_REL32_SLOT.repeat(3);blob.extend_from_slice(&[0x48,0x83,0xc0,56,0xc3]);
        let original=blob.clone();
        let mut relocs=vec![RelocRecord{offset:0,kind:1,target:0x1234},
            RelocRecord{offset:5,kind:1,target:0x1234},RelocRecord{offset:10,kind:1,target:0x5678}];
        let mut facts=HashMap::from([("unknown".into(),LookupSiteSpec{kind:LookupKind::Call,target_addr:0x5678,
            key_offset:0,max_entries:0,elem_size:0,index_mask:0,value_offset:0,percpu_base_addr:0,map_name:Some("unknown".into())})]);
        let unused=share(&mut blob,&mut relocs,&fixture(),&facts)?;
        assert!(unused.is_empty());assert_eq!(blob,original,"generic target must stay generic");
        let mut typed=facts["unknown"].clone();typed.kind=LookupKind::Hash;typed.target_addr=0x1234;facts.insert("known".into(),typed);
        let ranges=share(&mut blob,&mut relocs,&fixture(),&facts)?;assert_eq!(ranges.len(),1);
        for site in [0usize,5]{let disp=i32::from_le_bytes(blob[site+1..site+5].try_into()?);assert_eq!(site as i64+5+i64::from(disp),original.len() as i64);}
        assert_eq!(&blob[10..original.len()],&original[10..],"unrelated call and existing key/value adjustment unchanged");
        assert_eq!(relocs.len(),2);assert!(relocs.iter().any(|r|r.offset==10&&r.target==0x5678));
        let fallback=relocs.iter().find(|r|r.target==0x1234).expect("original helper for other key sizes");
        assert_eq!(&blob[fallback.offset as usize..fallback.offset as usize+5],&X86_HELPER_CALL_REL32_SLOT);
        Ok(())
    }
}
