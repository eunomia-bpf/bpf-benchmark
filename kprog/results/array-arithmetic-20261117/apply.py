#!/usr/bin/env python3
"""Apply the small known-ARRAY arithmetic change in the sole checkout."""
from pathlib import Path
p = Path('kprog/x86/native_lab/native_link/src/x86.rs')
s = p.read_text()
old = '''        bytes.extend_from_slice(&[0x48, 0x69, 0xC0]); // imul rax, rax, imm32
        bytes.extend_from_slice(&imm.to_le_bytes());'''
new = '''        if let Ok(short) = i8::try_from(imm) {
            bytes.extend_from_slice(&[0x48, 0x6B, 0xC0, short as u8]); // imul rax, rax, imm8
        } else {
            bytes.extend_from_slice(&[0x48, 0x69, 0xC0]); // imul rax, rax, imm32
            bytes.extend_from_slice(&imm.to_le_bytes());
        }'''
assert s.count(old) == 1
s = s.replace(old, new)
old = '''    bytes.extend_from_slice(&[0x48, 0x01, 0xF8]); // add rax, rdi
    if value_offset != 0 {
        append_x86_add_rax_imm(bytes, value_offset);
    }
    Ok(())
}

fn build_x86_array_lookup_routine'''
new = '''    if value_offset == 0 {
        bytes.extend_from_slice(&[0x48, 0x01, 0xF8]); // add rax, rdi
    } else if let Ok(short) = i8::try_from(value_offset as i32) {
        bytes.extend_from_slice(&[0x48, 0x8D, 0x44, 0x07, short as u8]);
    } else {
        bytes.extend_from_slice(&[0x48, 0x8D, 0x84, 0x07]); // lea rax, [rdi + rax + disp32]
        bytes.extend_from_slice(&value_offset.to_le_bytes());
    }
    Ok(())
}

fn build_x86_array_lookup_routine'''
assert s.count(old) == 1
s = s.replace(old, new)
anchor = '''    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn shared_known_arrays_preserve_shapes_keys_bounds_and_call_returns()'''
test = '''    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn known_array_arithmetic_preserves_wide_products_and_displacement_signs() -> Result<()> {
        // Catch an accidental EAX multiply, sign-extended imm8 at stride 128,
        // or a changed displacement when ADDs become one LEA.
        for stride in [1, 2, 4, 8, 16, 24, 63, 127, 128, 129, 255, 256,
                       4096, 0x7fff_ffff, 0x4000_0000] {
            for offset in [0, 1, 127, 128, 304, 0x7fff_ffff, 0x8000_0000, u32::MAX] {
                let mut code = vec![0x48, 0x89, 0xf0]; // mov rax, rsi
                append_x86_array_value_ptr(&mut code, stride, offset)?;
                code.push(0xc3);
                for index in [0u32, 1, 3, 0x7fff_ffff, u32::MAX] {
                    let base = 0x1234_5678_9000usize;
                    let expected = (base as u64)
                        .wrapping_add(u64::from(index) * u64::from(stride))
                        .wrapping_add(offset as i32 as i64 as u64);
                    assert_eq!(memory::call_blob(&code, base as *mut u8, index as usize, 0) as u64,
                        expected, "stride={stride} offset={offset} index={index}");
                }
            }
        }
        for (stride, offset, expected_len) in [(24, 304, 12), (24, 127, 9),
                (24, 0, 7), (127, 304, 12), (129, 304, 15), (16, 304, 12)] {
            let mut code = Vec::new();
            append_x86_array_value_ptr(&mut code, stride, offset)?;
            assert_eq!(code.len(), expected_len, "stride={stride} offset={offset}");
            let mut decoder = Decoder::new(64, &code, DecoderOptions::NONE);
            let mut instructions = Vec::new();
            while decoder.can_decode() {
                let insn = decoder.decode();
                assert!(!insn.is_invalid());
                assert_eq!(insn.op0_register(), Register::RAX);
                instructions.push(insn);
            }
            assert_eq!(instructions.len(), 2);
            if stride == 24 && offset == 304 {
                assert_eq!(code, [0x48, 0x6b, 0xc0, 24, 0x48, 0x8d, 0x84, 0x07, 0x30, 1, 0, 0]);
                if let Some(out) = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                    fs::write(std::path::Path::new(&out).join("array-stride24-offset304.bin"), &code)?;
                }
            }
        }
        // Exercise the complete lookup around its existing unsigned bounds.
        for max_entries in [3, 4096] {
            let spec = LookupSiteSpec { kind: LookupKind::Array, target_addr: 0,
                key_offset: 0, max_entries, elem_size: 24, index_mask: max_entries.next_power_of_two()-1,
                value_offset: 304, percpu_base_addr: 0 };
            let code = build_x86_array_lookup_routine(&spec)?;
            let mut map = vec![0u8; 304 + max_entries as usize * 24];
            for key in [0, 1, max_entries-1, max_entries, u32::MAX] {
                let actual = memory::call_blob(&code, map.as_mut_ptr(), &key as *const _ as usize, 0);
                let expected = if key < max_entries { map.as_mut_ptr().wrapping_add(304 + key as usize*24) }
                    else { std::ptr::null_mut() };
                assert_eq!(actual, expected, "stride24 bounds max={max_entries} key={key}");
            }
        }
        Ok(())
    }

'''
assert s.count(anchor) == 1
s = s.replace(anchor, test + anchor)
p.write_text(s)
