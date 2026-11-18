//! LPM lookup for the real OTel 12-data-byte shape. Generic helper remains for
//! other map types/data sizes. Caller retains the original RCU/lifetime contract.
use super::*;
fn mem(b:&mut Vec<u8>,op:&[u8],modrm:usize,offset:u32)->Result<()> {
    let displacement=i32::try_from(offset)?;
    let start=b.len();b.extend_from_slice(op);
    if let Ok(short)=i8::try_from(displacement) {
        // The caller identifies ModRM explicitly: indexed operands end in SIB.
        b[start+modrm]=(b[start+modrm]&0x3f)|0x40;b.push(short as u8);
    } else {b.extend_from_slice(&displacement.to_le_bytes());}
    Ok(())
}
fn jmp(b:&mut Vec<u8>)->usize {b.push(0xe9);let at=b.len();b.extend_from_slice(&[0;4]);at}
pub(super) fn routine(l:&RuntimeLpmLayout,helper:u64)->Result<(Vec<u8>,Vec<RelocRecord>)> {
    let mut b=Vec::new();
    mem(&mut b,&[0x81,0xbf],1,l.map_type)?;b.extend_from_slice(&l.lpm_type.to_le_bytes());
    let other_type=append_x86_jcc_rel32(&mut b,0x85);
    mem(&mut b,&[0x48,0x83,0xbf],2,l.data_size)?;b.push(12);
    let other_size=append_x86_jcc_rel32(&mut b,0x85);
    mem(&mut b,&[0x44,0x8b,0x96],2,l.key_prefixlen)?; // r10d=query prefix
    mem(&mut b,&[0x4c,0x3b,0x97],2,l.max_prefixlen)?;
    let invalid=append_x86_jcc_rel32(&mut b,0x87);
    b.extend_from_slice(&[0x45,0x31,0xc0]); // r8=best node
    mem(&mut b,&[0x48,0x8b,0x97],2,l.root)?; // rdx=current node
    let walk=b.len();b.extend_from_slice(&[0x48,0x85,0xd2]);
    let empty=append_x86_jcc_rel32(&mut b,0x84);
    mem(&mut b,&[0x44,0x8b,0x9a],2,l.node_prefixlen)?; // r11d=node prefix
    // A query shorter than this node ends the walk; otherwise its limit is node.
    b.extend_from_slice(&[0x45,0x39,0xda]); // cmp query,node
    let short_query=append_x86_jcc_rel32(&mut b,0x82);
    // LPM allocation fixes max_prefixlen=data_size*8, hence96 for this shape.
    // Read the next child early, overlapping its latency with prefix matching.
    // A full-depth node has no key bit at96 and must skip this read.
    b.extend_from_slice(&[0x31,0xff,0x41,0x83,0xfb,96]);
    let no_child=append_x86_jcc_rel32(&mut b,0x83);
    b.extend_from_slice(&[0x44,0x89,0xd9,0xc1,0xe9,3]);
    mem(&mut b,&[0x0f,0xb6,0x84,0x0e],2,l.key_data)?; // key data[node prefix /8]
    b.extend_from_slice(&[0x44,0x89,0xd9,0xf7,0xd1,0x83,0xe1,7,0xd3,0xe8,0x83,0xe0,1]);
    // Fold constant pointer stride into SIB; retain multiplication for other layouts.
    let sib=match l.child_stride {1=>0x02,2=>0x42,4=>0x82,8=>0xc2,_=>{
        b.extend_from_slice(&[0x48,0x69,0xc0]);b.extend_from_slice(&i32::try_from(l.child_stride)?.to_le_bytes());0x02
    }};
    mem(&mut b,&[0x48,0x8b,0xbc,sib],2,l.child)?;
    let child_ready=b.len();patch_x86_rel32(&mut b,no_child,child_ready)?;
    mem(&mut b,&[0x48,0x8b,0x82],2,l.node_data)?;
    mem(&mut b,&[0x48,0x33,0x86],2,l.key_data)?;
    b.extend_from_slice(&[0x48,0x0f,0xc8,0x48,0x85,0xc0]); // big endian XOR
    let first_equal=append_x86_jcc_rel32(&mut b,0x84);
    b.extend_from_slice(&[0x48,0x0f,0xbd,0xc8,0x83,0xf1,63]); // ecx=63-bsr(diff)
    let first_done=jmp(&mut b);
    let second=b.len();patch_x86_rel32(&mut b,first_equal,second)?;
    b.extend_from_slice(&[0x41,0x83,0xfb,64]); // first chunk satisfies node prefix
    let short_prefix=append_x86_jcc_rel32(&mut b,0x86);
    mem(&mut b,&[0x8b,0x82],1,l.node_data+8)?;
    mem(&mut b,&[0x33,0x86],1,l.key_data+8)?;
    b.extend_from_slice(&[0x0f,0xc8,0x85,0xc0]);
    let all_equal=append_x86_jcc_rel32(&mut b,0x84);
    b.extend_from_slice(&[0x0f,0xbd,0xc8,0x83,0xf1,95]); // ecx=64+31-bsr(diff)
    let second_done=jmp(&mut b);
    let exact=b.len();patch_x86_rel32(&mut b,all_equal,exact)?;
    b.push(0xb9);b.extend_from_slice(&96u32.to_le_bytes());
    let exact_done=jmp(&mut b);
    let prefix64=b.len();patch_x86_rel32(&mut b,short_prefix,prefix64)?;
    b.push(0xb9);b.extend_from_slice(&64u32.to_le_bytes());
    let matched=b.len();patch_x86_rel32(&mut b,exact_done,matched)?;patch_x86_rel32(&mut b,first_done,matched)?;patch_x86_rel32(&mut b,second_done,matched)?;
    b.extend_from_slice(&[0x44,0x39,0xd9]);
    let mismatch=append_x86_jcc_rel32(&mut b,0x82);
    b.extend_from_slice(&[0x41,0x83,0xfb,96]);
    let full=append_x86_jcc_rel32(&mut b,0x84);
    mem(&mut b,&[0xf7,0x82],1,l.node_flags)?;b.extend_from_slice(&1u32.to_le_bytes());
    let intermediate=append_x86_jcc_rel32(&mut b,0x85);
    b.extend_from_slice(&[0x49,0x89,0xd0]); // best=current, unless intermediate
    let descend=b.len();patch_x86_rel32(&mut b,intermediate,descend)?;
    b.extend_from_slice(&[0x48,0x89,0xfa]); // current=previously-read child
    let back=jmp(&mut b);patch_x86_rel32(&mut b,back,walk)?;
    let found=b.len();patch_x86_rel32(&mut b,full,found)?;
    b.extend_from_slice(&[0x49,0x89,0xd0]); // exact max-prefix wins even before flags
    let finish=b.len();patch_x86_rel32(&mut b,empty,finish)?;patch_x86_rel32(&mut b,mismatch,finish)?;patch_x86_rel32(&mut b,short_query,finish)?;
    b.extend_from_slice(&[0x4d,0x85,0xc0]);let absent=append_x86_jcc_rel32(&mut b,0x84);
    mem(&mut b,&[0x49,0x8d,0x80],2,l.node_data+12)?;b.push(0xc3);
    let zero=b.len();patch_x86_rel32(&mut b,invalid,zero)?;patch_x86_rel32(&mut b,absent,zero)?;
    b.extend_from_slice(&[0x31,0xc0,0xc3]);
    let fallback=b.len();patch_x86_rel32(&mut b,other_type,fallback)?;patch_x86_rel32(&mut b,other_size,fallback)?;
    b.extend_from_slice(&[0x48,0x83,0xec,8]);let call=b.len();b.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
    b.extend_from_slice(&[0x48,0x83,0xc4,8,0xc3]);
    let nested=vec![RelocRecord{offset:call as u32,kind:1,target:helper}];
    let (bytes,relocs,_)=probe_read::compact((b,nested,Vec::new()))?;
    Ok((bytes,relocs))
}
pub(super) fn share(blob:&mut Vec<u8>,relocs:&mut Vec<RelocRecord>,layout:&RuntimeLpmLayout,
                    helper:u64)->Result<Option<(usize,usize)>> {
    let calls:Vec<_>=relocs.iter().filter(|r|r.kind==1&&r.target==helper).map(|r|r.offset as usize).collect();
    if calls.is_empty(){return Ok(None);}
    let start=blob.len();let (bytes,nested)=routine(layout,helper)?;
    probe_read::redirect(blob,&calls,start)?;
    relocs.retain(|r|!(r.kind==1&&r.target==helper));blob.extend_from_slice(&bytes);
    for mut r in nested {r.offset=u32::try_from(start+r.offset as usize)?;relocs.push(r);}
    Ok(Some((start,blob.len())))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    #[test]
    fn short_displacements_preserve_lpm_registers_sib_and_operand_widths()->Result<()> {
        // Catch editing the SIB byte instead of ModRM, or truncating offset128.
        let forms:&[(&[u8],usize,&[u8])]=&[
            (&[0x81,0xbf],1,&[11,0,0,0]),(&[0x48,0x83,0xbf],2,&[12]),
            (&[0x44,0x8b,0x96],2,&[]),(&[0x4c,0x3b,0x97],2,&[]),
            (&[0x48,0x8b,0x97],2,&[]),(&[0x44,0x8b,0x9a],2,&[]),
            (&[0x0f,0xb6,0x84,0x0e],2,&[]),(&[0x48,0x8b,0xbc,0x02],2,&[]),
            (&[0x48,0x8b,0x82],2,&[]),(&[0x48,0x33,0x86],2,&[]),
            (&[0x8b,0x82],1,&[]),(&[0x33,0x86],1,&[]),
            (&[0xf7,0x82],1,&[1,0,0,0]),(&[0x49,0x8d,0x80],2,&[])];
        for &(op,modrm,tail) in forms {
            for offset in [0,1,127,128,255,256,i32::MAX as u32] {
                let mut wide=op.to_vec();wide.extend_from_slice(&offset.to_le_bytes());wide.extend_from_slice(tail);
                let mut compact=Vec::new();mem(&mut compact,op,modrm,offset)?;compact.extend_from_slice(tail);
                let mut before=Decoder::new(64,&wide,DecoderOptions::NONE);
                let mut after=Decoder::new(64,&compact,DecoderOptions::NONE);
                let a=before.decode();let b=after.decode();
                assert!(!a.is_invalid()&&!b.is_invalid());
                assert_eq!((a.code(),a.op0_register(),a.op1_register()),
                           (b.code(),b.op0_register(),b.op1_register()));
                assert_eq!((a.memory_base(),a.memory_index(),a.memory_index_scale(),a.memory_size(),a.memory_displacement64()),
                           (b.memory_base(),b.memory_index(),b.memory_index_scale(),b.memory_size(),b.memory_displacement64()));
                assert_eq!(after.get_constant_offsets(&b).displacement_size(),if offset<=127 {1}else{4});
                assert_eq!(compact.len(),wide.len()-if offset<=127 {3}else{0});
                assert_eq!(b.len(),compact.len());
            }
        }
        Ok(())
    }

    #[test]
    fn lpm_all_differing_bits_and_prefix_clamps_match_bitwise_reference()->Result<()> {
        // Two layouts exercise actual compact and wide operands in the full walk.
        let mut vectors=0;
        for pad in [0u32,128] {
            let l=RuntimeLpmLayout{map_type:12+pad,lpm_type:11,root:40+pad,
                max_prefixlen:56+pad,data_size:64+pad,child:8+pad,child_stride:8,
                node_prefixlen:32+pad,node_flags:36+pad,node_data:48+pad,
                key_prefixlen:pad,key_data:4+pad};
            let (code,_)=routine(&l,0x1234)?;
            let mut map=[0u8;256];let mut node=[0u8;256];let mut key=[0u8;256];
            let put32=|bytes:&mut [u8],offset:u32,value:u32| bytes[offset as usize..offset as usize+4].copy_from_slice(&value.to_le_bytes());
            let put64=|bytes:&mut [u8],offset:u32,value:u64| bytes[offset as usize..offset as usize+8].copy_from_slice(&value.to_le_bytes());
            put32(&mut map,l.map_type,11);put64(&mut map,l.max_prefixlen,96);
            put64(&mut map,l.data_size,12);put64(&mut map,l.root,node.as_ptr() as u64);
            for differing in 0..=96 {
                key[l.key_data as usize..l.key_data as usize+12].fill(0);
                if differing<96 {key[l.key_data as usize+differing/8]=1<<(7-differing%8);}
                let common=(0..96).take_while(|bit| {
                    let shift=7-bit%8;
                    (node[l.node_data as usize+bit/8]>>shift)&1 == (key[l.key_data as usize+bit/8]>>shift)&1
                }).count() as u32;
                for prefix in [0u32,1,31,32,63,64,65,95,96] {
                    put32(&mut node,l.node_prefixlen,prefix);
                    for query in [0u32,1,31,32,63,64,65,95,96,97] {
                        put32(&mut key,l.key_prefixlen,query);
                        for flags in [0u32,1] {
                            put32(&mut node,l.node_flags,flags);
                            let expected=if query<=96 && query>=prefix && common>=prefix && (flags==0 || prefix==96) {
                                node.as_ptr().wrapping_add(l.node_data as usize+12) as usize
                            } else {0};
                            let actual=memory::call_blob(&code,map.as_mut_ptr(),key.as_ptr() as usize,0) as usize;
                            assert_eq!(actual,expected,"pad={pad} differing={differing} prefix={prefix} query={query} flags={flags}");
                            vectors+=1;
                        }
                    }
                }
            }
        }
        println!("LPM exhaustive: {vectors} compact/wide bitwise prefix/flag vectors PASS");
        Ok(())
    }

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
            .arg(root.join("kprog/build/test-lpm-lookup.c")).arg("-o").arg(&driver).output()?;
        fs::write(out.join("compile.stdout"),&cc.stdout)?;fs::write(out.join("compile.stderr"),&cc.stderr)?;
        if !cc.status.success(){bail!("LPM fixture compile: {}",String::from_utf8_lossy(&cc.stderr));}
        let (bytes,nested)=routine(&layout,0x1234)?;
        assert_eq!(nested.len(),1);assert_eq!((nested[0].kind,nested[0].target),(1,0x1234));
        let call=nested[0].offset as usize;
        assert_eq!(&bytes[call..call+5],X86_HELPER_CALL_REL32_SLOT.as_slice());
        let binary=out.join("lpm.bin");fs::write(&binary,&bytes)?;
        let run=std::process::Command::new(driver).arg(binary).arg(call.to_string()).output()?;
        fs::write(out.join("stdout"),&run.stdout)?;fs::write(out.join("stderr"),&run.stderr)?;
        assert!(run.status.success(),"LPM host: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        println!("{}",String::from_utf8_lossy(&run.stdout));
        let mut blob=vec![0xe8,0,0,0,0,0xe9,0,0,0,0,0xc3];
        let mut relocs=vec![RelocRecord{offset:0,kind:1,target:0x1234},
                            RelocRecord{offset:5,kind:1,target:0x1234}];
        let range=share(&mut blob,&mut relocs,&layout,0x1234)?.expect("shared LPM");
        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));
        for site in [0usize,5] {
            let rel=i32::from_le_bytes(blob[site+1..site+5].try_into()?);
            assert_eq!(site as i64+5+i64::from(rel),range.0 as i64);
        }
        assert_eq!(relocs.len(),1,"only the existing generic kernel call remains");
        assert_eq!((relocs[0].offset as usize,relocs[0].target),(range.0+call,0x1234),
            "sized helper slot must receive the shared leaf shift exactly once");
        assert_eq!(&blob[relocs[0].offset as usize..relocs[0].offset as usize+5],
                   X86_HELPER_CALL_REL32_SLOT.as_slice());
        Ok(())
    }
}
