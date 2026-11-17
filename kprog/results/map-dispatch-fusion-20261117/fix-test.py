#!/usr/bin/env python3
"""Keep the legacy unshared JMP assertion separate from fused external E8 ABI."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/x86.rs');s=p.read_text()
old='''            assert_eq!(&linked.blob[site..site+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),"external ABI stays E8");'''
new='''            // With no runtime wrapper, preserve the pre-existing numeric tail JMP.
            // Every shared ARRAY/LPM wrapper must still call its external helper via E8.
            let opcode=if tail && a.is_none() && l.is_none() {0xe9}else{0xe8};
            assert_eq!(linked.blob[site],opcode,"existing transfer or shared external ABI");
            assert_eq!(&linked.blob[site+1..site+5],&[0;4]);'''
assert s.count(old)==1;s=s.replace(old,new)
old='let mp=map.as_mut_ptr();let kp=key.as_ptr() as usize;let mut callbacks=0u64;'
new='let mp=map.as_mut_ptr();let kp=key.as_ptr() as usize;'
assert s.count(old)==1;s=s.replace(old,new)
old='''                callbacks=0;
                let result=memory::call_blob(&blob,mp,kp,&mut callbacks as *mut u64 as usize)'''
new='''                let mut callbacks=0u64;
                let result=memory::call_blob(&blob,mp,kp,&mut callbacks as *mut u64 as usize)'''
assert s.count(old)==1;s=s.replace(old,new);p.write_text(s)
