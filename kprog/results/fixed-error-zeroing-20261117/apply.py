#!/usr/bin/env python3
"""Carry the existing scalar count through error zeroing without another leaf."""
from pathlib import Path

p = Path('kprog/x86/native_lab/native_link/src/x86_probe_read.rs')
s = p.read_text()
old = '''/// Zero the whole destination from the saved dst and size that `saved` moves into RDI and ECX;
/// returns the branch that leaves after a zero-length destination.
fn zero_fill(b: &mut Vec<u8>, saved: &[u8]) -> Result<usize> {
    b.extend_from_slice(saved);'''
new = '''/// Zero the full original destination, preserving RAX's error. A known scalar count
/// uses a counted word loop and fixed remainder; only dynamic counts need an exit patch.
fn zero_fill(b: &mut Vec<u8>, fixed: Option<u32>) -> Result<Option<usize>> {
    if let Some(size)=fixed {
        if size==0 {return Ok(None);}
        b.extend_from_slice(&[0x4c,0x89,0xc7,0x31,0xd2]); // original dst, zero RDX
        let words=size/8;
        if words>1 {b.push(0xb9);b.extend_from_slice(&words.to_le_bytes());}
        let word=b.len();
        if words!=0 {b.extend_from_slice(&[0x48,0x89,0x17]);}
        if words>1 {
            b.extend_from_slice(&[0x48,0x83,0xc7,8,0xff,0xc9]);
            let again=append_x86_jcc_rel32(b,0x85);patch_x86_rel32(b,again,word)?;
        }
        let mut offset=if words==1 {8}else{0};
        for (width,opcode) in [(4,&[0x89,0x97][..]),(2,&[0x66,0x89,0x97]),(1,&[0x88,0x97])] {
            if size & width != 0 {
                memory::Routine::operand(b,opcode,offset);
                offset+=width;
            }
        }
        return Ok(None);
    }
    b.extend_from_slice(&[0x4c,0x89,0xc7,0x44,0x89,0xc9]); // original dst and size'''
assert s.count(old) == 1
s = s.replace(old, new)
old = '''    Ok(zero_done)
}'''
assert s.count(old) == 1
s = s.replace(old, old.replace('Ok(zero_done)', 'Ok(Some(zero_done))'))
old = '''    let zero_done = zero_fill(&mut b, &[0x4c,0x89,0xc7,0x44,0x89,0xc9])?; // rdi=r8, ecx=r9d
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?; patch_x86_rel32(&mut b, zero_done, end)?;'''
new = '''    let zero_done = zero_fill(&mut b, if string {None}else{fixed})?;
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?;
    if let Some(branch)=zero_done {patch_x86_rel32(&mut b,branch,end)?;}'''
assert s.count(old) == 2
s = s.replace(old, new)
old = '''        let mut generic=Vec::new();copy_words(&mut generic,&mut Vec::new(),&mut Vec::new(),None)?;
        for size in [0u32,1,2,3,4,7,8,9,15,16,17,144,1024,u32::MAX] {'''
new = '''        let mut generic=Vec::new();copy_words(&mut generic,&mut Vec::new(),&mut Vec::new(),None)?;
        let mut generic_zero=Vec::new();assert!(zero_fill(&mut generic_zero,None)?.is_some());
        for size in [0u32,1,2,3,4,7,8,9,15,16,17,144,1024,u32::MAX] {'''
assert s.count(old) == 1
s = s.replace(old, new)
old = '''            assert_eq!(sites.len(),usize::from(size>=8)+(size&7).count_ones() as usize);
        }'''
new = '''            assert_eq!(sites.len(),usize::from(size>=8)+(size&7).count_ones() as usize);
            let mut zero=Vec::new();assert_eq!(zero_fill(&mut zero,Some(size))?,None);
            assert!(zero.len()<generic_zero.len(),"zeroing must not unroll a large count");
            assert_eq!(zero.is_empty(),size==0,"zero count must not access the destination");
            let instructions:Vec<_>=Decoder::new(64,&zero,DecoderOptions::NONE).into_iter().collect();
            for i in &instructions {
                assert!(!i.is_invalid());
                assert_ne!(i.op0_register().full_register(),Register::RAX,"preserve the error");
            }
            let counts:Vec<_>=instructions.iter().filter(|i|i.op0_register()==Register::ECX
                && i.mnemonic()==Mnemonic::Mov).map(|i|i.immediate32()).collect();
            assert_eq!(counts,if size>=16 {vec![size/8]}else{vec![]},"full-u32 word count");
            if size==u32::MAX {
                let widths:Vec<_>=instructions.iter().filter(|i|i.op0_kind()==OpKind::Memory)
                    .map(|i|i.memory_size().size()).collect();
                assert_eq!(widths,[8,4,2,1],"maximum count keeps its full seven-byte tail");
            }
        }'''
assert s.count(old) == 1
s = s.replace(old, new)
p.write_text(s)
