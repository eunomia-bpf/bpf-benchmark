#!/usr/bin/env python3
"""Return directly from ARRAY success and miss paths, retaining generic CALL ABI."""
from pathlib import Path

p = Path('kprog/x86/native_lab/native_link/src/x86.rs')
s = p.read_text()
old = '    body.extend_from_slice(&[0xEB, 0x02]); // jmp over null return'
assert s.count(old) == 1
s = s.replace(old, '    body.push(0xc3); // Successful lookup returns without a shared-return jump.')
old = '''            let code = build_x86_array_lookup_routine(&spec)?;
            let mut map = vec![0u8; 304 + max_entries as usize * 24];'''
new = '''            let code = build_x86_array_lookup_routine(&spec)?;
            let instructions:Vec<_>=Decoder::new(64,&code,DecoderOptions::NONE).into_iter().collect();
            assert!(instructions.iter().all(|i|!i.is_invalid()
                && i.flow_control()!=FlowControl::UnconditionalBranch),"no shared-return jump");
            assert_eq!(instructions.iter().filter(|i|i.mnemonic()==Mnemonic::Ret).count(),2);
            if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                std::fs::write(std::path::Path::new(&out).join(format!("known-array-max{max_entries}.bin")),&code)?;
            }
            let mut map = vec![0u8; 304 + max_entries as usize * 24];'''
assert s.count(old) == 1
s = s.replace(old, new)
p.write_text(s)

p = Path('kprog/x86/native_lab/native_link/src/x86_runtime_array.rs')
s = p.read_text()
old = '''    bytes.extend_from_slice(&[0xeb, 4]); // Skip NULL body to the shared return.
    let null = bytes.len();
    bytes.extend_from_slice(&[0x31, 0xc0, 0xeb, 0]); // NULL, then shared return.
    bytes[generic_branch] = u8::try_from(bytes.len() - generic_branch - 1)? + 1; // Other types skip the shared RET.'''
new = '''    bytes.push(0xc3); // Successful ARRAY lookup returns directly.
    let null = bytes.len();
    bytes.extend_from_slice(&[0x31, 0xc0, 0xc3]); // NULL returns directly too.
    bytes[generic_branch] = u8::try_from(bytes.len() - generic_branch - 1)?;'''
assert s.count(old) == 1
s = s.replace(old, new)
old = '    bytes.push(0xc3); // ARRAY/NULL return; other types branch past this RET.\n'
assert s.count(old) == 1
s = s.replace(old, '')
old = '''            let (mut code, call) = routine(&layout)?;
            let disp = i32::try_from(code.len() as i64 - (call + 5) as i64)?;'''
new = '''            let (mut code, call) = routine(&layout)?;
            let instructions:Vec<_>=Decoder::new(64,&code,DecoderOptions::NONE).into_iter().collect();
            assert!(instructions.iter().all(|i|!i.is_invalid()
                && i.flow_control()!=FlowControl::UnconditionalBranch),"no shared-return jump");
            assert_eq!(instructions.iter().filter(|i|i.mnemonic()==Mnemonic::Ret).count(),3);
            if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                std::fs::write(std::path::Path::new(&out).join("runtime-array.bin"),&code)?;
            }
            let disp = i32::try_from(code.len() as i64 - (call + 5) as i64)?;'''
assert s.count(old) == 1
s = s.replace(old, new)
s = s.replace('assert_eq!(range, (16, 83), "one67-byte routine, not one per call");',
              'assert_eq!(range, (16, 80), "one64-byte routine, not one per call");')
s = s.replace('assert_eq!(external.offset, 16+57);', 'assert_eq!(external.offset, 16+54);')
p.write_text(s)
