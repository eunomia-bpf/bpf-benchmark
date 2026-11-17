#!/usr/bin/env python3
"""Apply the ordered LPM encoding change in the sole checkout."""
from pathlib import Path
import re
p=Path('kprog/x86/native_lab/native_link/src/x86_lpm_lookup.rs')
s=p.read_text()
old='''fn mem(b:&mut Vec<u8>,op:&[u8],offset:u32)->Result<()> {
    b.extend_from_slice(op);b.extend_from_slice(&i32::try_from(offset)?.to_le_bytes());Ok(())
}'''
new='''fn mem(b:&mut Vec<u8>,op:&[u8],modrm:usize,offset:u32)->Result<()> {
    let displacement=i32::try_from(offset)?;
    let start=b.len();b.extend_from_slice(op);
    if let Ok(short)=i8::try_from(displacement) {
        // The caller identifies ModRM explicitly: indexed operands end in SIB.
        b[start+modrm]=(b[start+modrm]&0x3f)|0x40;b.push(short as u8);
    } else {b.extend_from_slice(&displacement.to_le_bytes());}
    Ok(())
}'''
assert s.count(old)==1
s=s.replace(old,new)
def operand(m):
    op=[int(x,16) for x in m[1].split(',')]
    indexed=op in [[0x0f,0xb6,0x84,0x0e],[0x48,0x8b,0xbc,0x02]]
    return f'mem(&mut b,&[{m[1]}],{len(op)-(2 if indexed else 1)},'
s,n=re.subn(r'mem\(&mut b,&\[([^]]+)\],',operand,s)
assert n==14, n
s=s.replace('[0x48,0x0f,0xbd,0xc8,0xf7,0xd9,0x83,0xc1,63]',
            '[0x48,0x0f,0xbd,0xc8,0x83,0xf1,63]')
s=s.replace('[0x0f,0xbd,0xc8,0xf7,0xd9,0x83,0xc1,95]',
            '[0x0f,0xbd,0xc8,0x83,0xf1,95]')
anchor='''    #[test]
    fn emitted_lpm_lookup_matches_bitwise_reference_and_preserves_other_types()'''
test='''    #[test]
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
            let (code,_)=routine(&l)?;
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

'''
assert s.count(anchor)==1
s=s.replace(anchor,test+anchor)
p.write_text(s)
