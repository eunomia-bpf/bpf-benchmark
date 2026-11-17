#!/usr/bin/env python3
"""Prepare item 1c without editing the pending batch's build inputs.

Default: print the proposed diff. --apply: edit the sole checkout, after the
batch-2 image snapshot. No candidate source tree or second build is created.
"""
import argparse
import difflib
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--apply', action='store_true')
args = parser.parse_args()
path = Path('/workspaces/repository/kprog/x86/native_lab/native_link/src/x86_probe_read.rs')
original = path.read_text()
text = original


def replace(old, new, count=1):
    global text
    assert text.count(old) == count, (old, text.count(old), count)
    text = text.replace(old, new)


replace('fn jump(bytes: &mut Vec<u8>) -> usize {', '''// Use a 64-bit-address-size absolute SIB operand; disp32 is sign extended.
// Values remain live. Other addresses use the same R11 scratch as before.
fn live_global(bytes: &mut Vec<u8>, compact: &[u8], wide: &[u8], address: u64) {
    if address as u32 as i32 as i64 as u64 == address {
        bytes.extend_from_slice(compact);
        bytes.extend_from_slice(&(address as u32).to_le_bytes());
    } else {
        absolute(bytes, &[0x49,0xbb], address);
        bytes.extend_from_slice(wide);
    }
}

fn jump(bytes: &mut Vec<u8>) -> usize {''')
replace('    absolute(&mut b, &[0x49,0xbb], target(layout.user_ptr_max)?);',
        '    live_global(&mut b, &[0x48,0x8b,0x04,0x25], &[0x49,0x8b,0x03], target(layout.user_ptr_max)?);', 3)
replace('[0x49,0x8b,0x03,0x48,0x39,0xc2,0x48,0x0f,0x47,0xd0]',
        '[0x48,0x39,0xc2,0x48,0x0f,0x47,0xd0]')
replace('[0x49,0x8b,0x03,0x4c,0x29,0xc8,0x48,0x39,0xc2]',
        '[0x4c,0x29,0xc8,0x48,0x39,0xc2]')
replace('    b.extend_from_slice(&[0x49,0x8b,0x03,0x48,0x05,0,0x10,0,0,0x48,0x39,0xc2]); // rax=[r11]+4096; cmp rdx,rax',
        '    b.extend_from_slice(&[0x48,0x05,0,0x10,0,0,0x48,0x39,0xc2]); // rax=TASK_SIZE_MAX+4096; cmp rdx,rax')
replace('    b.extend_from_slice(&[0x49,0x8b,0x03]); // rax=TASK_SIZE_MAX\n', '')
replace('''    absolute(&mut b, &[0x49,0xbb], target(layout.boot_cpu_data)?);
    b.extend_from_slice(&[0x41,0xf7,0x83]); // test boot_cpu_data.x86_capability[9],SMAP
    b.extend_from_slice(&i32::try_from(layout.x86_capability+9*4)?.to_le_bytes());''',
        '''    live_global(&mut b, &[0xf7,0x04,0x25], &[0x41,0xf7,0x03],
        target(layout.boot_cpu_data)?.wrapping_add(u64::from(layout.x86_capability)+9*4)); // test capability[9],SMAP''')
replace('''    absolute(&mut b, &[0x49,0xbb], target(layout.boot_cpu_data)?);
    b.extend_from_slice(&[0x41,0x0f,0xb6,0x8b]); // movzx ecx,byte[r11+x86_virt_bits]
    b.extend_from_slice(&i32::try_from(layout.x86_virt_bits)?.to_le_bytes());''',
        '''    live_global(&mut b, &[0x0f,0xb6,0x0c,0x25], &[0x41,0x0f,0xb6,0x0b],
        target(layout.boot_cpu_data)?.wrapping_add(u64::from(layout.x86_virt_bits))); // movzx ecx,byte[virt_bits]''')
replace('    fn fixture() -> RuntimeProbeReadLayout {', '''    // Catch accidental 0x67 zero-extension and signed-disp32 boundary errors.
    #[test]
    fn compact_global_operands_preserve_full_effective_addresses() {
        for address in [0u64, 0x7fffffff, 0xffffffff80000000, u64::MAX,
                        0x80000000, 0xffffffff7fffffff, 0x1111222233334444] {
            let compact_address=address as u32 as i32 as i64 as u64==address;
            for (compact,wide,test) in [
                (&[0x48,0x8b,0x04,0x25][..],&[0x49,0x8b,0x03][..],false),
                (&[0x0f,0xb6,0x0c,0x25][..],&[0x41,0x0f,0xb6,0x0b][..],false),
                (&[0xf7,0x04,0x25][..],&[0x41,0xf7,0x03][..],true)] {
                let mut bytes=Vec::new();live_global(&mut bytes,compact,wide,address);
                if test {bytes.extend_from_slice(&(1u32<<20).to_le_bytes());}
                let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);
                if !compact_address {
                    let load=decoder.decode();
                    assert_eq!(load.op0_register(),Register::R11);
                    assert_eq!(load.immediate64(),address);
                }
                let operand=decoder.decode();assert!(!operand.is_invalid());
                assert_eq!(operand.memory_index(),Register::None);
                if compact_address {
                    assert_eq!(operand.memory_base(),Register::None);
                    assert_eq!(operand.memory_displacement64(),address);
                    assert_eq!(bytes.len(),compact.len()+4+if test {4} else {0});
                } else {
                    assert_eq!(operand.memory_base(),Register::R11);
                    assert_eq!(operand.memory_displacement64(),0);
                }
                assert!(!decoder.can_decode());
            }
        }
    }

    fn fixture() -> RuntimeProbeReadLayout {''')

if args.apply:
    path.write_text(text)
else:
    print(''.join(difflib.unified_diff(original.splitlines(True), text.splitlines(True),
                                    fromfile=str(path), tofile=str(path))), end='')
