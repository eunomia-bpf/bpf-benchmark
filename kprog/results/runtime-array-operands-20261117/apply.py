#!/usr/bin/env python3
"""Reuse field operand encoding without changing ARRAY reads or dispatch."""
from pathlib import Path

p = Path('kprog/x86/native_lab/native_link/src/x86_runtime_array.rs')
s = p.read_text()
old = '''    let mut bytes = vec![0x81, 0xbf]; // cmp dword [rdi+map_type], ARRAY
    bytes.extend_from_slice(&i32::try_from(layout.map_type)?.to_le_bytes());
    bytes.extend_from_slice(&layout.array_type.to_le_bytes());'''
new = '''    let mut bytes = Vec::new();
    let short_type = layout.array_type <= i8::MAX as u32;
    memory::Routine::operand(&mut bytes, &[if short_type {0x83}else{0x81},0xbf],
        i32::try_from(layout.map_type)? as u32); // cmp dword [rdi+map_type], ARRAY
    if short_type {bytes.push(layout.array_type as u8);} else {bytes.extend_from_slice(&layout.array_type.to_le_bytes());}'''
assert s.count(old) == 1
s = s.replace(old, new)
for opcode, field, comment in [('0x3b, 0x87', 'max_entries', 'cmp eax,[rdi+max_entries]'),
                               ('0x23, 0x87', 'index_mask', 'and eax,[rdi+index_mask]'),
                               ('0x8b, 0x97', 'elem_size', 'mov edx,[rdi+elem_size]')]:
    old = f'''    bytes.extend_from_slice(&[{opcode}]); // {comment}
    bytes.extend_from_slice(&i32::try_from(layout.{field})?.to_le_bytes());'''
    new = f'''    memory::Routine::operand(&mut bytes, &[{opcode}], i32::try_from(layout.{field})? as u32); // {comment}'''
    assert s.count(old) == 1
    s = s.replace(old, new)
anchor = '''    #[test]
    fn runtime_array_executes_key_bounds_mask_wide_product_and_other_type_dispatch() -> Result<()> {'''
test = '''    #[test]
    fn runtime_field_encodings_preserve_offsets_full_type_and_branch_targets() -> Result<()> {
        let mut cases=0;
        for offset in [0u32,1,127,128,4096,i32::MAX as u32] {
            for kind in [0u32,2,127,128,256,u32::MAX] {
                let layout=RuntimeArrayLayout{map_type:offset,max_entries:offset,elem_size:offset,
                    index_mask:offset,value:304,array_type:kind};
                let (bytes,call)=routine(&layout)?;
                let instructions:Vec<_>=Decoder::new(64,&bytes,DecoderOptions::NONE).into_iter().collect();
                assert!(instructions.iter().all(|i|!i.is_invalid()));
                let fields:Vec<_>=instructions.iter().filter(|i|i.memory_base()==Register::RDI
                    && i.memory_index()==Register::None).collect();
                assert_eq!(fields.len(),4,"one live read of each bound field");
                for (n,field) in fields.iter().enumerate() {
                    assert_eq!(field.memory_displacement64(),u64::from(offset));
                    let disp=if offset==0 {0}else if offset<=127 {1}else{4};
                    let immediate=if n!=0 {0}else if kind<=127 {1}else{4};
                    assert_eq!(field.len(),2+disp+immediate,"encoded displacement width");
                    assert_eq!(field.memory_size().size(),4,"u32 field reads");
                }
                assert_eq!(fields.iter().map(|i|i.mnemonic()).collect::<Vec<_>>(),
                    [Mnemonic::Cmp,Mnemonic::Cmp,Mnemonic::And,Mnemonic::Mov]);
                let first=fields[0];
                assert_eq!(first.op1_kind(),if kind<=127 {OpKind::Immediate8to32}else{OpKind::Immediate32});
                let actual=if kind<=127 {first.immediate8to32() as u32}else{first.immediate32()};
                assert_eq!(actual,kind,"never sign-extend a positive 128..255 type as imm8");
                for i in &instructions {
                    if i.mnemonic()==Mnemonic::Jne {assert_eq!(i.near_branch_target() as usize,call-4);}
                    if i.mnemonic()==Mnemonic::Jae {
                        let target=i.near_branch_target() as usize;
                        assert_eq!(&bytes[target..target+3],&[0x31,0xc0,0xc3]);
                    }
                }
                assert_eq!(&bytes[call..call+5],X86_HELPER_CALL_REL32_SLOT.as_slice());
                cases+=1;
            }
        }
        println!("runtime ARRAY: {cases} offset/type encodings retain fields and branch targets");
        Ok(())
    }

'''
assert s.count(anchor) == 1
s = s.replace(anchor, test+anchor)
old = 'assert_eq!(range, (16, 80), "one64-byte routine, not one per call");'
assert s.count(old) == 1
s = s.replace(old, 'assert_eq!(range, (16, 65), "one49-byte routine, not one per call");')
old = 'assert_eq!(external.offset, 16+54);'
assert s.count(old) == 1
s = s.replace(old, 'assert_eq!(external.offset, 16+39);')
p.write_text(s)
