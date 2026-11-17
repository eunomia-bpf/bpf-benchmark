#!/usr/bin/env python3
"""One-shot structural zero-tail source/test stages; retain completed stages."""
from pathlib import Path
import sys

p = Path('kprog/x86/native_lab/native_link/src/x86_probe_read.rs')
s = p.read_text()
if sys.argv[1] == 'test':
    anchor = '    fn fixture() -> RuntimeProbeReadLayout {'
    test = '''    #[test]
    fn identical_zero_tails_share_after_domain_cleanup() -> Result<()> {
        let layout=fixture();
        for string in [false,true] {
            let user=user_leaf(&layout,layout.user_helper,string,None)?.0.len();
            let kernel=kernel_routine(&layout,layout.kernel_helper,string,None)?.0.len();
            let mut blob=X86_HELPER_CALL_REL32_SLOT.repeat(2);blob.push(0xc3);
            let mut relocs=vec![RelocRecord{offset:0,kind:1,target:0x5000},
                                RelocRecord{offset:5,kind:1,target:0x6000}];
            let helpers=HashMap::from([("bpf_probe_read_user".into(),layout.user_helper),
                ("bpf_probe_read_kernel".into(),layout.kernel_helper),
                ((if string {"bpf_probe_read_user_str"}else{"bpf_probe_read_user"}).into(),0x5000),
                ((if string {"bpf_probe_read_kernel_str"}else{"bpf_probe_read_kernel"}).into(),0x6000)]);
            // Keep relocation and layout anchors identical in the scalar case.
            let mut bound=layout.clone();
            if !string {bound.user_helper=0x5000;bound.kernel_helper=0x6000;}
            let (ranges,loads)=share(&mut blob,&mut relocs,&bound,&helpers,&HashMap::new())?;
            assert_eq!(ranges.len(),2);assert!(relocs.is_empty());
            assert!(blob.len()<=11+user+kernel-36,"duplicate zero block remains");
            assert!(loads.iter().all(|site|site.destination==11));
        }
        Ok(())
    }

'''
    assert anchor in s
    s = s.replace(anchor, test + anchor, 1)
elif sys.argv[1] == 'fix':
    # Only the two leaf builders acquire structural zero offsets. Other public
    # compact callers keep the same tuple and behavior.
    for name in ['user_leaf', 'kernel_routine']:
        start = s.index('fn ' + name + '(')
        end = s.index('\n}\n', start) + 3
        body = s[start:end]
        body = body.replace('Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)>',
                            'Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>, usize)>')
        body = body.replace('let zero = b.len();', 'let mut zero = b.len();')
        body = body.replace('    compact((b, Vec::new(), sites))',
            '''    let (bytes,relocs,sites)=compact_at((b,Vec::new(),sites),std::slice::from_mut(&mut zero))?;
    Ok((bytes,relocs,sites,zero))''')
        s = s[:start] + body + s[end:]
    marker = '''    let (bytes, mut relocs, mut sites) = routine;'''
    start = s.index('pub(super) fn compact(')
    pos = s.index(marker, start)
    s = s[:pos] + '''    compact_at(routine,&mut [])
}

fn compact_at(routine: (Vec<u8>,Vec<RelocRecord>,Vec<LoadSite>), marks: &mut [usize])
    -> Result<(Vec<u8>,Vec<RelocRecord>,Vec<LoadSite>)> {
''' + s[pos:]
    marker = '    for reloc in &mut relocs {reloc.offset=encoded.new_instruction_offsets[indices[&reloc.offset]];}'
    assert marker in s
    s = s.replace(marker, '    for mark in marks {*mark=encoded.new_instruction_offsets[indices[&(*mark as u32)]] as usize;}\n'+marker, 1)
    marker = 'pub(super) fn constant_size('
    helper = '''// Reuse a structurally identified zero suffix after each leaf's own cleanup.
// Prefix success branches keep their original RET label and fault loads retain
// their original instruction index through the existing block encoder.
fn append_read(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, ranges: &mut Vec<(usize,usize)>,
               loads: &mut Vec<LoadSite>, tails: &mut HashMap<Vec<u8>,usize>,
               routine: (Vec<u8>,Vec<RelocRecord>,Vec<LoadSite>,usize)) -> Result<usize> {
    let (mut bytes,mut nested,mut sites,zero)=routine;
    let start=blob.len();
    if bytes.len()-zero>6 {
        if let Some(&target)=tails.get(&bytes[zero..]) {
            let original:Vec<_>=Decoder::with_ip(64,&bytes,start as u64,DecoderOptions::NONE).collect();
            let mut kept:Vec<_>=original.iter().copied().take_while(|i|i.ip()<(start+zero) as u64).collect();
            let indices:HashMap<_,_>=kept.iter().enumerate().map(|(n,i)|((i.ip() as usize-start) as u32,n)).collect();
            let mut branch=Instruction::with_branch(Code::Jmp_rel32_64,target as u64)?;
            branch.set_ip((start+zero) as u64);kept.push(branch);
            kept.push(*original.last().expect("read leaf return"));
            let encoded=BlockEncoder::encode(64,InstructionBlock::new(&kept,start as u64),
                BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS)?;
            for site in &mut sites {site.offset=encoded.new_instruction_offsets[indices[&site.offset]];}
            for reloc in &mut nested {reloc.offset=encoded.new_instruction_offsets[indices[&reloc.offset]];}
            bytes=encoded.code_buffer;
        } else {tails.insert(bytes[zero..].to_vec(),start+zero);}
    }
    append(blob,relocs,ranges,loads,(bytes,nested,sites))
}

'''
    assert marker in s
    s = s.replace(marker, helper + marker, 1)
    start = s.index('pub(super) fn share(')
    end = s.index('\npub(super) fn direct_load(', start)
    body = s[start:end].replace('    let mut loads = Vec::new();',
                                '    let mut loads = Vec::new();\n    let mut tails=HashMap::new();')
    body = body.replace('append(blob, relocs, &mut ranges, &mut loads, built)',
                         'append_read(blob, relocs, &mut ranges, &mut loads, &mut tails, built)')
    body = body.replace('append(blob,relocs,&mut ranges,&mut loads,built)',
                         'append_read(blob,relocs,&mut ranges,&mut loads,&mut tails,built)')
    s = s[:start] + body + s[end:]
    # Existing complete execution matrices also exercise a second leaf with a
    # shared error suffix, using the same driver and original test arguments.
    s = s.replace('let (bytes,relocs,sites) = if user {user_leaf',
                  'let (bytes,relocs,sites,zero) = if user {user_leaf')
    s = s.replace('let (bytes,relocs,sites)=if user {user_leaf',
                  'let (bytes,relocs,sites,zero)=if user {user_leaf')
    anchor = '            let binary = output.join(format!("{stem}.bin"));'
    assert anchor in s
    s = s.replace(anchor, '''            execute_shared(&driver,&output,&stem,if mode==3 {7}else{mode},None,
                (bytes.clone(),relocs.clone(),sites.clone(),zero))?;
''' + anchor, 1)
    anchor = '                    let binary=output.join(format!("{stem}.bin"));fs::write(&binary,&bytes)?;'
    assert anchor in s
    s = s.replace(anchor, '''                    execute_shared(&driver,&output,&stem,if user {11}else{10},Some(size),
                        (bytes.clone(),relocs.clone(),sites.clone(),zero))?;
''' + anchor, 1)
    anchor = '    #[test]\n    fn emitted_probe_reads_execute_success_fault_partial_zero_policy_and_nesting()'
    helper = '''    fn execute_shared(driver: &Path, output: &Path, stem: &str, mode: usize, size: Option<u32>,
        routine: (Vec<u8>,Vec<RelocRecord>,Vec<LoadSite>,usize)) -> Result<()> {
        let mut blob=vec![0xe9,0,0,0,0];let mut relocs=Vec::new();let mut ranges=Vec::new();
        let mut loads=Vec::new();let mut tails=HashMap::new();
        append_read(&mut blob,&mut relocs,&mut ranges,&mut loads,&mut tails,routine.clone())?;
        let target=append_read(&mut blob,&mut relocs,&mut ranges,&mut loads,&mut tails,routine)?;
        patch_x86_rel32(&mut blob,1,target)?;
        let binary=output.join(format!("{stem}-shared.bin"));fs::write(&binary,&blob)?;
        let metadata=output.join(format!("{stem}-shared.sites"));
        let mut text=format!("{}\\n",loads.len());
        for site in loads {text.push_str(&format!("{} {} {}\\n",site.offset,site.insn_len,site.destination));}
        fs::write(&metadata,text)?;
        let mut command=std::process::Command::new(driver);command.arg(binary).arg(metadata).arg(mode.to_string());
        if let Some(size)=size {command.arg(size.to_string());}
        let run=command.output()?;
        fs::write(output.join(format!("{stem}-shared.stdout")),&run.stdout)?;
        fs::write(output.join(format!("{stem}-shared.stderr")),&run.stderr)?;
        assert!(run.status.success(),"{stem} shared: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        Ok(())
    }

'''
    assert anchor in s
    s = s.replace(anchor, helper + anchor, 1)
else:
    raise ValueError('stage must be test or fix')
p.write_text(s)
