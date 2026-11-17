#!/usr/bin/env python3
"""Reuse the field operand encoder for clock ModRM fields, not GS or immediates."""
from pathlib import Path
import re

p = Path('kprog/x86/native_lab/native_link/src/x86_ktime.rs')
s = p.read_text()
old = '''fn disp(value: u32) -> Result<[u8; 4]> {
    Ok(i32::try_from(value)?.to_le_bytes())
}'''
new = '''fn field(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) -> Result<()> {
    memory::Routine::operand(bytes, opcode, i32::try_from(offset)? as u32);
    Ok(())
}'''
assert s.count(old) == 1
s = s.replace(old, new)
old = 'b.extend_from_slice(&disp(l.tkr_size)?);'
assert s.count(old) == 1
s = s.replace(old, 'b.extend_from_slice(&i32::try_from(l.tkr_size)?.to_le_bytes());')
pattern = r'    b\.extend_from_slice\(&(\[0x[^\]]+\])\); b\.extend_from_slice\(&disp\(([^()]+)\)\?\);'
s, count = re.subn(pattern, lambda m: f'    field(&mut b, &{m[1]}, {m[2]})?;', s)
assert count == 18, count
assert 'disp(' not in s
anchor = '''    #[test]
    fn ktime_leaf_follows_the_kernel_formula_and_calls_the_kernel() -> Result<()> {'''
test = '''    #[test]
    fn clock_fields_preserve_rex_registers_widths_and_displacement_boundaries() -> Result<()> {
        let mut cases=0;
        for (opcode,mnemonic,register,base,width) in [
            (&[0x41,0x8b,0xbb][..],Mnemonic::Mov,Register::EDI,Register::R11,4),
            (&[0x4d,0x8d,0x93],Mnemonic::Lea,Register::R10,Register::R11,0),
            (&[0x4d,0x8b,0x82],Mnemonic::Mov,Register::R8,Register::R10,8),
            (&[0x41,0x8b,0xb1],Mnemonic::Mov,Register::ESI,Register::R9,4),
            (&[0x49,0x2b,0x81],Mnemonic::Sub,Register::RAX,Register::R9,8),
            (&[0x41,0x0f,0xbe,0x89],Mnemonic::Movsx,Register::ECX,Register::R9,1),
            (&[0x41,0x8b,0x91],Mnemonic::Mov,Register::EDX,Register::R9,4),
            (&[0x49,0x03,0x81],Mnemonic::Add,Register::RAX,Register::R9,8),
            (&[0x41,0x0f,0xb6,0x91],Mnemonic::Movzx,Register::EDX,Register::R9,1),
            (&[0x41,0x3b,0xb1],Mnemonic::Cmp,Register::ESI,Register::R9,4),
            (&[0x49,0x2b,0x82],Mnemonic::Sub,Register::RAX,Register::R10,8),
            (&[0x49,0x23,0x82],Mnemonic::And,Register::RAX,Register::R10,8),
            (&[0x49,0x3b,0x80],Mnemonic::Cmp,Register::RAX,Register::R8,8),
            (&[0x41,0x8b,0x92],Mnemonic::Mov,Register::EDX,Register::R10,4),
            (&[0x49,0x03,0x82],Mnemonic::Add,Register::RAX,Register::R10,8),
            (&[0x41,0x8b,0x8a],Mnemonic::Mov,Register::ECX,Register::R10,4),
            (&[0x41,0x3b,0xbb],Mnemonic::Cmp,Register::EDI,Register::R11,4)] {
            for offset in [0u32,1,127,128,4096,i32::MAX as u32] {
                let mut bytes=Vec::new();field(&mut bytes,opcode,offset)?;
                let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);
                let i=decoder.decode();assert!(!i.is_invalid() && !decoder.can_decode());
                assert_eq!((i.mnemonic(),i.op0_register(),i.memory_base()),(mnemonic,register,base));
                assert_eq!(i.memory_index(),Register::None);
                assert_eq!(i.memory_displacement64(),u64::from(offset));
                assert_eq!(i.len(),opcode.len()+if offset==0 {0}else if offset<=127 {1}else{4});
                if width!=0 {assert_eq!(i.memory_size().size(),width);}
                cases+=1;
            }
        }
        println!("clock fields: {cases} REX/register/width/offset encodings PASS");
        Ok(())
    }

'''
assert s.count(anchor) == 1
s = s.replace(anchor, test+anchor)
p.write_text(s)
