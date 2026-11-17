#!/usr/bin/env python3
"""Capture old memory bodies, then keep large known counts in the emitter."""
from pathlib import Path
import sys
p=Path('kprog/x86/native_lab/native_link/src/x86_memory.rs')
s=p.read_text()
if sys.argv[1]=='--capture':
    old='''                            let bytes = routine.bytes()?;
                            let code = Mapping::code(&bytes);'''
    new='''                            let bytes = routine.bytes()?;
                            if let Some(out) = std::env::var_os("NATIVE_LINK_MEMORY_TEST_OUTPUT") {
                                fs::write(std::path::Path::new(&out).join(format!("{}.bin",routine.name())),&bytes)?;
                            }
                            let code = Mapping::code(&bytes);'''
    assert s.count(old)==1
    s=s.replace(old,new)
elif sys.argv[1]=='--change':
    assert s.count('length: Option<u16>')==1
    s=s.replace('length: Option<u16>','length: Option<u64>')
    old='''            .copied()
            .filter(|&n| n <= 512)
            .map(|n| n as u16);'''
    assert s.count(old)==1
    s=s.replace(old,'            .copied();')
    old='''        if let Some(length) = self.length {
            let mut offset = 0;
            for width in [8, 4, 2, 1] {
                while u32::from(length) - offset >= u32::from(width) {'''
    new='''        if let Some(length) = self.length {
            // The existing unroll cutoff selects layout, not whether a count is known.
            let remainder = if length > 512 {
                let blocks = length / 32;
                if let Ok(short) = u32::try_from(blocks) {
                    b.push(0xb9); b.extend_from_slice(&short.to_le_bytes()); // mov ecx,blocks
                } else {
                    b.extend_from_slice(&[0x48,0xb9]); b.extend_from_slice(&blocks.to_le_bytes());
                }
                let loop32 = b.len();
                for offset in [0,8,16,24] { self.word(&mut b,offset,8); }
                self.advance(&mut b,32);
                b.extend_from_slice(&[0x48,0xff,0xc9]); // dec rcx (positive known block count)
                let again = append_x86_jcc_rel32(&mut b,0x85);
                patch_x86_rel32(&mut b,again,loop32)?;
                (length % 32) as u32
            } else { length as u32 };
            let mut offset = 0;
            for width in [8, 4, 2, 1] {
                while remainder - offset >= u32::from(width) {'''
    assert s.count(old)==1
    s=s.replace(old,new)
    assert s.count('(specialized && length <= 512).then_some(length as u16)')==2
    s=s.replace('(specialized && length <= 512).then_some(length as u16)',
                'specialized.then_some(length as u64)')
    s=s.replace('Some(length as u16)','Some(length as u64)')
    s=s.replace('.chain([127, 128, 129, 367, 368, 369, 511, 512, 513, 4096, 17111])',
                '.chain(513..=575)\n                .chain([127, 128, 129, 367, 368, 369, 511, 512, 668, 4096, 17111])')
    s=s.replace('for length in (0..=65).chain([127, 128, 129, 367, 368, 369, 511, 512, 513, 4096]) {',
                'for length in (0..=65).chain(513..=575).chain([127, 128, 129, 367, 368, 369, 511, 512, 668, 4095, 4096]) {')
    anchor='''        #[test]
        #[ignore = "opt-in host timing evidence, not a correctness or workload gate"]
        fn memory_host_microbenchmark()'''
    test='''        #[test]
        fn known_large_counts_keep_full_width_without_dynamic_dispatch() -> Result<()> {
            // Catch loss of counts above512, sign extension at2^31 blocks,
            // or truncation at2^32 blocks, without allocating huge buffers.
            let mut sizes=String::from("copy zero count known_bytes dynamic_bytes\\n");
            for length in [513u64,543,544,545,668,4096,17111,u32::MAX as u64,
                (1u64<<31)*32,(1u64<<32)*32-1,(1u64<<32)*32,u64::MAX] {
                for (copy,zero) in [(false,false),(false,true),(true,false)] {
                    let facts=HashMap::from([(Register::RDX,length),
                        (Register::RSI,if zero {0x100}else{0x1234})]);
                    let routine=Routine::at_call(if copy {"memcpy"}else{"memset"},Some(&facts)).unwrap();
                    assert_eq!(routine.length,Some(length));assert_eq!(routine.zero,zero);
                    let bytes=routine.bytes()?;
                    let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);
                    let mut info=InstructionInfoFactory::new();
                    let mut count=None;let mut conditional=0;
                    while decoder.can_decode() {
                        let insn=decoder.decode();assert!(!insn.is_invalid());
                        if insn.mnemonic()==Mnemonic::Mov {
                            if insn.op0_register()==Register::ECX {count=Some(insn.immediate32() as u64);}
                            if insn.op0_register()==Register::RCX {count=Some(insn.immediate64());}
                        }
                        conditional+=usize::from(insn.flow_control()==FlowControl::ConditionalBranch);
                        assert!(!info.info(&insn).used_registers().iter().any(|r|
                            x86_gpr64_family(r.register())==Some(Register::RDX)),
                            "known count must not redispatch through runtime RDX");
                    }
                    assert_eq!(count,Some(length/32));assert_eq!(conditional,1);
                    let dynamic=Routine{copy,length:None,zero}.bytes()?;
                    assert!(bytes.len()<dynamic.len(),"{routine:?} must stay a compact loop");
                    sizes.push_str(&format!("{copy} {zero} {length} {} {}\\n",bytes.len(),dynamic.len()));
                }
            }
            for name in ["memcpy","memset"] {
                assert_eq!(Routine::at_call(name,None).unwrap().length,None);
            }
            if let Some(out)=std::env::var_os("NATIVE_LINK_MEMORY_TEST_OUTPUT") {
                fs::write(std::path::Path::new(&out).join("sizes.txt"),&sizes)?;
            }
            println!("Known large memory:36 full-width count/dispatch cases PASS");
            Ok(())
        }

'''
    assert s.count(anchor)==1
    s=s.replace(anchor,test+anchor)
else:
    raise ValueError('use --capture or --change')
p.write_text(s)
