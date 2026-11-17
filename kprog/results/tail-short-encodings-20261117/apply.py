#!/usr/bin/env python3
"""One-shot tail-encoding test/fix using the existing routine compactor."""
from pathlib import Path
import sys
p=Path('kprog/x86/native_lab/native_link/src/x86.rs');s=p.read_text()
if sys.argv[1]=='test':
    begin=s.index('    #[test]\n    fn tail_count_patch_preserves_target_entry() -> Result<()> {')
    end=s.index('\n    #[test]',begin+12)
    test='''    #[test]
    fn tail_count_patch_preserves_target_entry() -> Result<()> {
        let mut cases=0;
        for (bound,function,entry_offset) in [(68u64,72u64,12u64),(4096,4096,4096),(0,0,0)] {
            let helpers = HashMap::from([
                (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_owned(), bound),
                (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_owned(), 304),
                (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_owned(), function),
                (X86_TAIL_CALL_OFFSET_KEY.to_owned(), entry_offset),
            ]);
            for (saved_frame,live_rbp) in [(Some(64),false),(None,true)] {
                for cleanup in [Vec::new(),vec![0x90;192]] {for mask in [0,15] {
                    let (stub,field)=build_x86_tail_call_inline(&helpers,mask,&cleanup,saved_frame,live_rbp)?;
                    let mut bytes=BlockEncoder::encode(64,InstructionBlock::new(&stub,0),BlockEncoderOptions::NONE)?.code_buffer;
                    assert_eq!(&bytes[field..field+4],&(-16i32).to_le_bytes(),"counter slot before kernel patch");
                    bytes[field..field+4].copy_from_slice(&(-32i32).to_le_bytes());
                    let decoded=decode_x86(&bytes)?;
                    let branches:Vec<_>=decoded.iter().filter(|i|i.is_jcc_short_or_near()).collect();
                    assert_eq!(branches.len(),3,"all live bounds/count/null tests retained");
                    assert!(branches.iter().all(|i|i.near_branch_target()==bytes.len() as u64),"common miss target");
                    if cleanup.is_empty() {assert!(branches.iter().all(|i|i.len()==2),"opaque tail branches should fit rel8");}
                    else {assert!(branches.iter().any(|i|i.len()==6),"long cleanup must keep a near branch");}
                    let entry=decoded.iter().find(|i|i.mnemonic()==Mnemonic::Add && i.op0_register()==Register::RCX).expect("tail entry add");
                    let value=if entry.op1_kind()==OpKind::Immediate8to64 {entry.immediate8to64()}else{entry.immediate32to64()};
                    assert_eq!(value,entry_offset as i64,"counter patch must not redirect the tail jump");
                    let load=decoded.iter().find(|i|i.mnemonic()==Mnemonic::Mov && i.op0_register()==Register::RAX
                        && i.memory_base()==if live_rbp {Register::RBP}else{Register::RAX}).expect("counter pointer load");
                    assert_eq!(load.memory_displacement64() as i64,-32);
                    let mut decoder=Decoder::new(64,&bytes[load.ip() as usize..],DecoderOptions::NONE);
                    let instruction=decoder.decode();
                    let offsets=decoder.get_constant_offsets(&instruction);
                    assert_eq!(offsets.displacement_size(),4,"kind10 always patches four bytes");
                    assert_eq!(load.ip() as usize+offsets.displacement_offset(),field,"counter offset follows branch sizing");
                    cases+=1;
                }}
            }
        }
        println!("tail encodings: {cases} narrow/wide/zero layouts, saved/live frames, masks and short/long cleanup cases PASS");
        Ok(())
    }
'''
    s=s[:begin]+test+s[end:]
    old='&& i.op0_register() == Register::RCX && i.immediate32to64() == 12));'
    new='&& i.op0_register() == Register::RCX\n                && (if i.op1_kind()==OpKind::Immediate8to64 {i.immediate8to64()}else{i.immediate32to64()}) == 12));'
    assert s.count(old)==1;s=s.replace(old,new)
elif sys.argv[1]=='fix':
    old='''    bytes.extend_from_slice(&[0x39, 0x96]); // cmp dword ptr [rsi + disp32], edx
    bytes.extend_from_slice(&map_max_entries.to_le_bytes());'''
    new='''    memory::Routine::operand(&mut bytes, &[0x39, 0x96], map_max_entries); // cmp [rsi+bound], edx'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='''    bytes.extend_from_slice(&[0x48, 0x8B, 0x89]); // mov rcx, [rcx + disp32]
    bytes.extend_from_slice(&prog_bpf_func.to_le_bytes());
    bytes.extend_from_slice(&[0x48, 0x81, 0xC1]); // add rcx, imm32
    bytes.extend_from_slice(&tail_call_offset.to_le_bytes());'''
    new='''    memory::Routine::operand(&mut bytes, &[0x48, 0x8b, 0x89], prog_bpf_func); // rcx=prog->bpf_func
    if let Ok(offset)=i8::try_from(tail_call_offset as i32) {
        bytes.extend_from_slice(&[0x48,0x83,0xc1,offset as u8]);
    } else {
        bytes.extend_from_slice(&[0x48,0x81,0xc1]);
        bytes.extend_from_slice(&tail_call_offset.to_le_bytes());
    }'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='''    // Report the counter-pointer load's disp32, not the target-entry immediate.
    Ok((declared_byte_chunks(&bytes)?, tail_count_field))'''
    new='''    // Make the common miss label an instruction for the existing branch compactor.
    // The raw counter load keeps disp32: kind10 is a four-byte kernel patch.
    bytes.push(0x90);
    let marker=RelocRecord {offset:u32::try_from(tail_count_field-3)?,
        kind:NATIVE_LAB_RELOC_X86_TAIL_COUNT,target:0};
    let (mut bytes,markers,_)=probe_read::compact((bytes,vec![marker],Vec::new()))?;
    bytes.truncate(bytes.len()-1); // The label remains the byte immediately after the stub.
    let field=markers[0].offset as usize+3;
    Ok((declared_byte_chunks(&bytes)?, field))'''
    assert s.count(old)==1;s=s.replace(old,new)
else:raise ValueError('Use test or fix')
p.write_text(s)
