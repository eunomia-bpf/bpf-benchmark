#!/usr/bin/env python3
"""One fixed scalar count per existing domain leaf; no policy-body clones."""
import argparse
import difflib
from pathlib import Path

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--apply', action='store_true')
args = p.parse_args()
root = Path('/workspaces/repository/kprog/x86/native_lab/native_link')
prepared = []


def edit(name, pairs):
    path = root/name
    before = path.read_text()
    after = before
    for old, new, count in pairs:
        assert after.count(old) == count, (name, old, after.count(old), count)
        after = after.replace(old, new)
    prepared.append((path, before, after))


fixed_copy = '''fn copy_fixed(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>, size: u32) -> Result<()> {
    let words=size/8;
    if words>1 {b.push(0xb9);b.extend_from_slice(&words.to_le_bytes());}
    let word_loop=b.len();
    for width in [8u32,4,2,1] {
        let present=if width==8 {words!=0} else {size & width != 0};
        if !present {continue;}
        let load:&[u8]=match width {8=>&[0x48,0x8b,0x06],4=>&[0x8b,0x06],
            2=>&[0x0f,0xb7,0x06],1=>&[0x0f,0xb6,0x06],_=>unreachable!()};
        sites.push(LoadSite{offset:b.len() as u32,insn_len:load.len() as u16,destination:11});
        b.extend_from_slice(load);b.extend_from_slice(&[0x45,0x85,0xdb]);
        faults.push(append_x86_jcc_rel32(b,0x84));
        b.extend_from_slice(match width {8=>&[0x48,0x89,0x07][..],4=>&[0x89,0x07],
            2=>&[0x66,0x89,0x07],1=>&[0x88,0x07],_=>unreachable!()});
        if (width==8 && words>1) || size & (width-1)!=0 {
            b.extend_from_slice(&[0x48,0x83,0xc7,width as u8,0x48,0x83,0xc6,width as u8]);
        }
        if width==8 && words>1 {
            b.extend_from_slice(&[0xff,0xc9]);
            let again=append_x86_jcc_rel32(b,0x85);patch_x86_rel32(b,again,word_loop)?;
        }
    }
    b.extend_from_slice(&[0x31,0xc0]);
    Ok(())
}

'''
count_functions = '''pub(super) fn constant_size(name: &str, facts: Option<&HashMap<Register,u64>>) -> Option<u32> {
    if matches!(name,"bpf_probe_read_kernel"|"bpf_probe_read_user"|"bpf_probe_read_compat"|"bpf_probe_read") {
        facts?.get(&Register::RSI).map(|size| *size as u32)
    } else {None}
}

fn common_size(calls: &[usize], counts: &HashMap<usize,u32>) -> Option<u32> {
    let first=*counts.get(calls.first()?)?;
    calls.iter().all(|site| counts.get(site)==Some(&first)).then_some(first)
}

'''
fixed_execution = '''        for compact in [false,true] {
            let mut fixed_layout=fixture();
            if compact {fixed_layout.user_ptr_max=0x12340000;fixed_layout.boot_cpu_data=0x12350000;}
            for user in [false,true] {
                let anchor=if user {fixed_layout.user_helper} else {fixed_layout.kernel_helper};
                for size in [0u32,1,2,3,4,7,8,9,15,16,17,31,32,33,63,64,65,144,257,512,768,1024] {
                    let (bytes,relocs,sites)=if user {user_leaf(&fixed_layout,anchor,false,Some(size))?}
                        else {kernel_routine(&fixed_layout,anchor,false,Some(size))?};
                    assert!(relocs.is_empty());
                    let stem=format!("{}-fixed-{size}{}",if user {"user"} else {"kernel"},if compact {"-compact"} else {""});
                    let binary=output.join(format!("{stem}.bin"));fs::write(&binary,&bytes)?;
                    let metadata=output.join(format!("{stem}.sites"));
                    let mut text=format!("{}\\n",sites.len());
                    for site in sites {text.push_str(&format!("{} {} {}\\n",site.offset,site.insn_len,site.destination));}
                    fs::write(&metadata,text)?;
                    let run=std::process::Command::new(&driver).arg(binary).arg(metadata)
                        .arg(if user {"9"} else {"8"}).arg(size.to_string()).output()?;
                    fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?;
                    fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
                    assert!(run.status.success(),"{stem}: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
                    println!("{}",String::from_utf8_lossy(&run.stdout));
                }
            }
        }
'''
count_tests = '''    #[test]
    fn fixed_scalar_counts_join_all_callers_and_bound_copy_code() -> Result<()> {
        let registers=HashMap::from([(Register::RSI,0x100000008),(Register::RDX,16)]);
        assert_eq!(constant_size("bpf_probe_read_kernel",Some(&registers)),Some(8));
        assert_eq!(constant_size("bpf_probe_read_user_str",Some(&registers)),None);
        assert_eq!(constant_size("bpf_probe_read_user",None),None);
        let counts=HashMap::from([(0usize,8u32),(5,8),(10,16)]);
        assert_eq!(common_size(&[0,5],&counts),Some(8));
        assert_eq!(common_size(&[0,10],&counts),None);
        assert_eq!(common_size(&[0,15],&counts),None);
        let mut generic=Vec::new();copy_words(&mut generic,&mut Vec::new(),&mut Vec::new(),None)?;
        for size in [0u32,1,2,3,4,7,8,9,15,16,17,144,1024,u32::MAX] {
            let mut bytes=Vec::new();let mut sites=Vec::new();
            copy_words(&mut bytes,&mut sites,&mut Vec::new(),Some(size))?;
            assert!(bytes.len()<generic.len(),"counted body must not unroll a large size");
            assert_eq!(sites.len(),usize::from(size>=8)+(size&7).count_ones() as usize);
        }
        let layout=fixture();
        let helpers=HashMap::from([("bpf_probe_read_user".into(),layout.user_helper),
            ("bpf_probe_read_kernel".into(),layout.kernel_helper),("bpf_probe_read_compat".into(),0x3000)]);
        for (user_size,compat_size,expected) in [(Some(8),Some(8),2),(Some(16),Some(8),5),(Some(8),None,8)] {
            let mut blob=X86_HELPER_CALL_REL32_SLOT.repeat(3);blob[5]=0xe9;blob.push(0xc3);
            let mut relocs=vec![RelocRecord{offset:0,kind:1,target:layout.kernel_helper},
                RelocRecord{offset:5,kind:1,target:0x3000},RelocRecord{offset:10,kind:1,target:layout.user_helper}];
            let mut facts=HashMap::from([(0usize,8u32)]);
            if let Some(size)=user_size {facts.insert(10,size);}
            if let Some(size)=compat_size {facts.insert(5,size);}
            let (ranges,sites)=share(&mut blob,&mut relocs,&layout,&helpers,&facts)?;
            assert_eq!(ranges.len(),3,"reuse one user and one kernel body plus compat dispatcher");
            assert_eq!(sites.len(),expected,"meet direct and compat counts for each domain");
        }
        Ok(())
    }

'''
edit('src/x86_probe_read.rs', [
    ('fn copy_words(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>) -> Result<()> {',
     fixed_copy+'fn copy_words(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>, fixed: Option<u32>) -> Result<()> {\n    if let Some(size)=fixed {return copy_fixed(b,sites,faults,size);}', 1),
    ('fn user_leaf(layout: &RuntimeProbeReadLayout, actual: u64, string: bool)',
     'fn user_leaf(layout: &RuntimeProbeReadLayout, actual: u64, string: bool, fixed: Option<u32>)', 1),
    ('fn kernel_routine(layout: &RuntimeProbeReadLayout, actual: u64, string: bool)',
     'fn kernel_routine(layout: &RuntimeProbeReadLayout, actual: u64, string: bool, fixed: Option<u32>)', 1),
    ('b.extend_from_slice(&[0x4c,0x89,0xc7,0x44,0x89,0xc9]); // rdi=dst, ecx=size',
     'b.extend_from_slice(&[0x4c,0x89,0xc7]); // rdi=dst\n    if string || fixed.is_none() {b.extend_from_slice(&[0x44,0x89,0xc9]);} // ecx=size', 1),
    ('b.extend_from_slice(&[0x48,0x89,0xd6,0x4c,0x89,0xc7,0x44,0x89,0xc9,0x41,0xbb,1,0,0,0]); // rsi=src, rdi=dst, ecx=size, r11d=1',
     'b.extend_from_slice(&[0x48,0x89,0xd6,0x4c,0x89,0xc7]); // rsi=src, rdi=dst\n    if string || fixed.is_none() {b.extend_from_slice(&[0x44,0x89,0xc9]);}\n    b.extend_from_slice(&[0x41,0xbb,1,0,0,0]); // r11d=1', 1),
    ('copy_words(&mut b,&mut sites,&mut faults)?', 'copy_words(&mut b,&mut sites,&mut faults,fixed)?', 1),
    ('copy_words(&mut b, &mut sites, &mut faults)?', 'copy_words(&mut b, &mut sites, &mut faults,fixed)?', 1),
    ('pub(super) fn share(blob:', count_functions+'pub(super) fn share(blob:', 1),
    ('layout: &RuntimeProbeReadLayout, helpers: &HashMap<String,u64>)',
     'layout: &RuntimeProbeReadLayout, helpers: &HashMap<String,u64>, counts: &HashMap<usize,u32>)', 1),
    ('    let mut leaves = [[None,None],[None,None]];',
     '''    let sizes=[false,true].map(|user| {
        let mut calls=Vec::new();
        for name in [if user {"bpf_probe_read_user"} else {"bpf_probe_read_kernel"},"bpf_probe_read_compat"] {
            if let Some(&helper)=helpers.get(name) {calls.extend(calls_to(relocs,helper));}
        }
        common_size(&calls,counts)
    });
    let mut leaves = [[None,None],[None,None]];''', 1),
    ('user_leaf(layout,anchor,string)?', 'user_leaf(layout,anchor,string,if string {None} else {sizes[1]})?', 1),
    ('kernel_routine(layout,anchor,string)?', 'kernel_routine(layout,anchor,string,if string {None} else {sizes[0]})?', 1),
    ('user_leaf(layout,user_anchor,string)?', 'user_leaf(layout,user_anchor,string,if string {None} else {sizes[1]})?', 1),
    ('kernel_routine(layout,kernel_anchor,string)?', 'kernel_routine(layout,kernel_anchor,string,if string {None} else {sizes[0]})?', 1),
    ('user_leaf(&layout,anchor,string)?', 'user_leaf(&layout,anchor,string,None)?', 1),
    ('kernel_routine(&layout,anchor,string)?', 'kernel_routine(&layout,anchor,string,None)?', 1),
    ('share(&mut blob,&mut relocs,&layout,&helpers)?', 'share(&mut blob,&mut relocs,&layout,&helpers,&HashMap::new())?', 2),
    ('share(&mut strings,&mut calls,&layout,&names)?', 'share(&mut strings,&mut calls,&layout,&names,&HashMap::new())?', 1),
    ('        let helpers=HashMap::from([("bpf_probe_read_kernel".into(),layout.kernel_helper),',
     fixed_execution+'        let helpers=HashMap::from([("bpf_probe_read_kernel".into(),layout.kernel_helper),', 1),
    ('    fn fixture() -> RuntimeProbeReadLayout {',count_tests+'    fn fixture() -> RuntimeProbeReadLayout {',1),
])

edit('fixtures/probe_read_driver.c', [
    ('assert(argc == 4);','assert(argc == 4 || argc == 5);',1),
    ('int user = mode == 1 || mode == 7;','int user = mode == 1 || mode == 7 || mode == 9;',1),
    ('site_count > 0 && site_count <= 8','site_count <= 8',1),
    ('    if (mode == 5) { /* bpf_probe_read (compat):',
     '''    if (mode == 8 || mode == 9) {
        assert(argc == 5); unsigned n=strtoul(argv[4],NULL,0); assert(n<=1024);
        for (unsigned offset=0;offset<8;++offset) {check(dest+1,src+offset,n,0);++vectors;}
        check(dest+1,src+4096-n,n,0);++vectors;
        if (n) {
            const unsigned remains[]={0,n/2,n-1};
            for (unsigned i=0;i<3;++i) {check(dest+1,src+4096-remains[i],n,-14);++vectors;}
        }
        if (user) {
            percpu.loaded_mm=task.mm+0x1000;check(dest+1,src,n,-14);++vectors;percpu.loaded_mm=task.mm;
            user_max=(uintptr_t)src-1;check(dest+1,src,n,-14);++vectors;user_max=UINTPTR_MAX;
            cpu[9]=1u<<20;check(dest+1,src,n,0);++vectors;
            if (n) {check(dest+1,src+4096-(n-1),n,-14);++vectors;}
            assert(smap_enters==smap_leaves && !smap_depth);
        } else {
            virt_bits(40);check(dest+1,src,n,-34);++vectors;virt_bits(48);
        }
        assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,old_gs));
        printf("fixed scalar user=%d size=%u: %u vectors, %u exact-site faults PASS\\n",user,n,vectors,faults);
        return 0;
    }
    if (mode == 5) { /* bpf_probe_read (compat):''', 1),
])

edit('src/x86.rs', [
    ('HelperBranchRel32 { target_addr: u64, opcode: u8 }',
     'HelperBranchRel32 { target_addr: u64, opcode: u8, probe_size: Option<u32> }', 1),
    ('alternatives, helper_addrs, true, proof_mode, &mut tail_calls)?;',
     'alternatives, helper_addrs, memory_constants.get(&local_ip), true, proof_mode, &mut tail_calls)?;',1),
    ('false, false, &mut tail_calls)?;',
     'memory_constants.get(&local_ip), false, false, &mut tail_calls)?;',1),
    ('Some(PatchKind::HelperBranchRel32 { target_addr, opcode: 0xe9 })',
     'Some(PatchKind::HelperBranchRel32 { target_addr, opcode: 0xe9,\n                        probe_size: probe_read::constant_size(&tail.symbol,memory_constants.get(&local_ip)) })',1),
    ('                                    helper_addr,\n                                )?;',
     '                                    helper_addr, None,\n                                )?;',1),
    ('&mut insn_local_ip, local_ip, target)?;', '&mut insn_local_ip, local_ip, target, None)?;',1),
    ('                        helper_addr,\n                    )?;',
     '                        helper_addr, probe_read::constant_size(&name,memory_constants.get(&local_ip)),\n                    )?;',1),
    ('    let mut map_patches = Vec::new();\n    let mut relocs = Vec::new();',
     '    let mut map_patches = Vec::new();\n    let mut relocs = Vec::new();\n    let mut probe_sizes=HashMap::new();',1),
    ('PatchKind::HelperBranchRel32 { target_addr, opcode } => {',
     'PatchKind::HelperBranchRel32 { target_addr, opcode, probe_size } => {\n                if let Some(size)=probe_size {probe_sizes.insert(p.global_offset,*size);}',1),
    ('probe_read::share(&mut blob, &mut relocs, layout, helper_addrs)?',
     'probe_read::share(&mut blob, &mut relocs, layout, helper_addrs,&probe_sizes)?',1),
    ('    helper_addr: u64,\n) -> Result<()> {',
     '    helper_addr: u64,\n    probe_size: Option<u32>,\n) -> Result<()> {',1),
    ('            target_addr: helper_addr,\n            opcode: 0xe8,',
     '            target_addr: helper_addr,\n            opcode: 0xe8, probe_size,',1),
    ('    helpers: &HashMap<String,u64>,\n    tail: bool, proof: bool,',
     '    helpers: &HashMap<String,u64>, constants: Option<&HashMap<Register,u64>>,\n    tail: bool, proof: bool,',1),
    ('calls.get(&offset).filter(|_| !proof).map(|(_,target)| PatchKind::HelperBranchRel32 {\n            target_addr:*target,opcode:if tail {0xe9} else {0xe8} });',
     'calls.get(&offset).filter(|_| !proof).map(|(name,target)| PatchKind::HelperBranchRel32 {\n            target_addr:*target,opcode:if tail {0xe9} else {0xe8},probe_size:probe_read::constant_size(name,constants) });',1),
    ('        let memory_constants = memory::constants(&bytes, sym.address, &helper_calls.branch_targets)?;',
     '''        let helper_tails=helper_calls.tails.iter().map(|ip| sym.address+ip).collect();
        let memory_constants = memory::constants(&bytes, sym.address, &helper_calls.branch_targets,&helper_tails)?;''',1),
    ('    #[test]\n    fn clock_calls_bind_fast_target_without_changing_observed_helper_identity()',
     '''    #[test]
    fn scalar_count_facts_survive_call_layout_conditional_tails_and_numeric_joins() -> Result<()> {
        let layout=RuntimeProbeReadLayout{user_helper:0x1000,kernel_helper:0x2000,current_task:0,
            jiffies:None,user_ptr_max:0x1111222233334444,boot_cpu_data:0x5555666677778888,
            pagefault_disabled:4,x86_capability:0,task_flags:0,task_personality:16,ktime:None,cred:None,
            cpu_tlbstate:8,tlb_loaded_mm:0,task_mm:8,x86_virt_bits:40};
        let helpers=HashMap::from([("bpf_probe_read_user".into(),0x1000),("bpf_probe_read_kernel".into(),0x2000)]);
        for (form,expected) in [(0,1),(1,1),(2,2),(3,4),(4,8),(5,0),(6,2)] {
            let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
            let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
            let normal=vec![0xbe,8,0,0,0,0xb8,113,0,0,0,0xff,0xd0,0xc3];
            let finite=vec![0xbe,8,0,0,0,0x85,0xff,0x74,7,0xb8,112,0,0,0,0xeb,5,
                            0xb8,113,0,0,0,0xff,0xd0,0xc3];
            let bytes=match form {
                0=>normal,
                1=>vec![0xbe,8,0,0,0,0x85,0xff,0x0f,0x84,0,0,0,0,0xc3],
                2=>finite,
                3=>normal[5..].to_vec(),
                4=>finite[5..].to_vec(),
                5=>{let mut b=normal;b[1]=0;b},
                6=>{let mut b=finite;b[22]=0xe0;b.pop();b},
                _=>unreachable!(),
            };
            object.append_section_data(text,&bytes,1);
            object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:0,size:bytes.len() as u64,
                kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
            if form==1 {
                let helper=object.add_symbol(WriteSymbol{name:b"bpf_probe_read_kernel".to_vec(),value:0,size:0,
                    kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                    section:WriteSymbolSection::Undefined,flags:SymbolFlags::None});
                object.add_relocation(text,WriteRelocation{offset:9,symbol:helper,addend:-4,
                    flags:RelocationFlags::Elf{r_type:4}})?;
            }
            let encoded=object.write()?;let elf=object::File::parse(encoded.as_slice())?;
            let entry=find_symbol_by_name(&elf,"entry")?;
            let result=rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),&HashMap::new(),
                &[],false,false,None,Some(&layout),None,false)?;
            assert_eq!(result.load_sites.iter().filter(|site| site.destination==11).count(),expected,
                       "count fact lost or invented in helper form {form}");
        }
        Ok(())
    }

    #[test]
    fn clock_calls_bind_fast_target_without_changing_observed_helper_identity()''',1),
])

edit('src/x86_memory.rs', [
    ('    branch_targets: &HashMap<u64, Vec<u64>>,\n) -> Result<HashMap<u64, HashMap<Register, u64>>> {',
     '    branch_targets: &HashMap<u64, Vec<u64>>,\n    helper_tails: &HashSet<u64>,\n) -> Result<HashMap<u64, HashMap<Register, u64>>> {',1),
    ('(i.flow_control() == FlowControl::IndirectBranch\n            && !branch_targets',
     '(i.flow_control() == FlowControl::IndirectBranch\n            && !helper_tails.contains(&i.ip())\n            && !branch_targets',1),
    ('if i.flow_control() == FlowControl::IndirectBranch {\n            for target',
     'if i.flow_control() == FlowControl::IndirectBranch && !helper_tails.contains(&i.ip()) {\n            for target',1),
    *[(f'constants(&{name}, 0, &HashMap::new())?',f'constants(&{name}, 0, &HashMap::new(), &HashSet::new())?',1)
      for name in ['branch','equal','partial','looped','indirect','local_call']],
    ('constants(&bytes,base,&edges)?','constants(&bytes,base,&edges,&HashSet::new())?',2),
    ('constants(&bytes,base,&HashMap::new())?','constants(&bytes,base,&HashMap::new(),&HashSet::new())?',1),
    ('constants(&bytes,base,&invalid)?','constants(&bytes,base,&invalid,&HashSet::new())?',1),
    ('        let invalid=HashMap::from([(base+5,vec![base+7,base+15])]);',
     '''        let terminal=[0xbe,8,0,0,0,0xff,0xe0];
        let tails=HashSet::from([base+5]);
        assert_eq!(constants(&terminal,base,&HashMap::new(),&tails)?[&5].get(&Register::RSI),Some(&8));
        let invalid=HashMap::from([(base+5,vec![base+7,base+15])]);''',1),
])

for path, before, after in prepared:
    if args.apply:
        path.write_text(after)
    else:
        print(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),
                                        fromfile=str(path),tofile=str(path))),end='')
