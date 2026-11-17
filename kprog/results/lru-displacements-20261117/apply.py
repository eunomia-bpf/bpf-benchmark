#!/usr/bin/env python3
"""Compact the two LRU reference-byte operands without changing map work."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/x86.rs');s=p.read_text()
old='''fn append_x86_cmp_byte_rax_disp32_imm(bytes: &mut Vec<u8>, disp: u32, imm: u8) {
    bytes.extend_from_slice(&[0x80, 0xB8]); // cmp byte ptr [rax+disp32], imm8
    bytes.extend_from_slice(&disp.to_le_bytes());
    bytes.push(imm);
}

fn append_x86_mov_byte_rax_disp32_imm(bytes: &mut Vec<u8>, disp: u32, imm: u8) {
    bytes.extend_from_slice(&[0xC6, 0x80]); // mov byte ptr [rax+disp32], imm8
    bytes.extend_from_slice(&disp.to_le_bytes());
    bytes.push(imm);
}'''
new='''fn append_x86_byte_rax_imm(bytes: &mut Vec<u8>, opcode: u8, reg_bits: u8, disp: u32, imm: u8) {
    bytes.push(opcode);
    if disp == 0 {
        bytes.push(reg_bits);
    } else if let Ok(short) = i8::try_from(disp as i32) {
        bytes.extend_from_slice(&[0x40 | reg_bits, short as u8]);
    } else {
        bytes.push(0x80 | reg_bits);
        bytes.extend_from_slice(&disp.to_le_bytes());
    }
    bytes.push(imm);
}'''
assert s.count(old)==1;s=s.replace(old,new)
s=s.replace('append_x86_cmp_byte_rax_disp32_imm(&mut body, spec.value_offset, 0);',
            'append_x86_byte_rax_imm(&mut body, 0x80, 0x38, spec.value_offset, 0); // cmp ref,0')
s=s.replace('append_x86_mov_byte_rax_disp32_imm(&mut body, spec.value_offset, 1);',
            'append_x86_byte_rax_imm(&mut body, 0xc6, 0, spec.value_offset, 1); // mov ref,1')
anchor='''    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn typed_hash_postprocess_preserves_null_value_pointer_and_lru_reference()'''
test='''    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn compact_lru_operands_preserve_signed_offsets_flags_and_live_reference() -> Result<()> {
        // Compare actual addressing/flag semantics with the original disp32 form.
        for disp in [0u32,1,35,127,128,0x7fff_ffff,0x8000_0000,
                     0xffff_ff7f,0xffff_ff80,u32::MAX] {
            for (opcode,reg_bits) in [(0x80,0x38),(0xc6,0)] {
                for imm in [0u8,1,0xff] {
                    let mut wide=vec![opcode,0x80|reg_bits];
                    wide.extend_from_slice(&disp.to_le_bytes());wide.push(imm);
                    let mut compact=Vec::new();
                    append_x86_byte_rax_imm(&mut compact,opcode,reg_bits,disp,imm);
                    let mut a=Decoder::new(64,&wide,DecoderOptions::NONE);
                    let mut b=Decoder::new(64,&compact,DecoderOptions::NONE);
                    let before=a.decode();let after=b.decode();
                    assert!(!after.is_invalid());
                    assert_eq!((before.code(),before.memory_base(),before.memory_displacement64(),before.immediate8()),
                               (after.code(),after.memory_base(),after.memory_displacement64(),after.immediate8()));
                    assert_eq!((before.rflags_read(),before.rflags_written(),before.rflags_undefined()),
                               (after.rflags_read(),after.rflags_written(),after.rflags_undefined()));
                    let expected=if disp==0 {3}else if i8::try_from(disp as i32).is_ok() {4}else{7};
                    assert_eq!(compact.len(),expected);assert_eq!(after.len(),compact.len());
                }
            }
        }
        for offset in [-128i32,-1,0,1,35,127,128,255] {
            let spec=LookupSiteSpec{kind:LookupKind::LruHash,target_addr:0x5678,key_offset:24,
                max_entries:0,elem_size:0,index_mask:0,value_offset:offset as u32,percpu_base_addr:0};
            let instructions=build_x86_lookup_call_postprocess(&spec)?;
            let post=BlockEncoder::encode(64,InstructionBlock::new(&instructions,0),BlockEncoderOptions::NONE)?.code_buffer;
            if offset==35 {assert_eq!(post.len(),19,"prior same-shape postprocess was25B");}
            if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                fs::write(std::path::Path::new(&out).join(format!("lru-ref{offset}.post.bin")),&post)?;
            }
            let mut code=vec![0x48,0x89,0xf8];code.extend_from_slice(&post);code.push(0xc3);
            for reference in [0u8,1,2,0xff] {
                assert!(memory::call_blob(&code,std::ptr::null_mut(),0,0).is_null());
                let mut node=vec![0xa5u8;768];let index=(256+offset) as usize;
                node[index]=reference;
                let mut expected=node.clone();expected[index]=if reference==0 {1}else{reference};
                let ptr=node.as_mut_ptr().wrapping_add(256);
                assert_eq!(memory::call_blob(&code,ptr,0,0),ptr.wrapping_add(24));
                assert_eq!(node,expected,"offset={offset} initial ref={reference}");
                assert_eq!(memory::call_blob(&code,ptr,0,0),ptr.wrapping_add(24));
                assert_eq!(node,expected,"existing ref must stay unchanged");
            }
        }
        println!("LRU ref:60 operand decodes and32 null/state/idempotence cases PASS");
        Ok(())
    }

'''
assert s.count(anchor)==1;s=s.replace(anchor,test+anchor)
old='''                assert_eq!(node, expected_node, "existing LRU ref stays set");
                assert_eq!(munmap(memory, 4096), 0);'''
new='''                assert_eq!(node, expected_node, "existing LRU ref stays set");
                if kind == LookupKind::LruHash {
                    // A nonzero ref requires no store, even of the same value.
                    let readonly = mmap(std::ptr::null_mut(),4096,3,0x22,-1,0);
                    assert_ne!(readonly as isize,-1);
                    std::ptr::copy_nonoverlapping(expected_node.as_ptr(),readonly.cast(),expected_node.len());
                    assert_eq!(mprotect(readonly,4096,1),0);
                    assert_eq!(postprocess(readonly.cast()),readonly as u64+24);
                    assert_eq!(munmap(readonly,4096),0);
                }
                assert_eq!(munmap(memory, 4096), 0);'''
assert s.count(old)==1;s=s.replace(old,new)
p.write_text(s)
