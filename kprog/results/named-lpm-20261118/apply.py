#!/usr/bin/env python3
"""Apply named-LPM tests/source once, after preserving all prior stages."""
from pathlib import Path
import sys

x = Path('kprog/x86/native_lab/native_link/src/x86.rs')
m = Path('kprog/x86/native_lab/native_link/src/main.rs')
h = Path('kprog/libnativeloader/src/native_loader_link_schema.hpp')
if sys.argv[1] == 'test':
    s = x.read_text()
    anchor = '    #[test]\n    fn runtime_known_maps_use_only_exact_named_map_facts()'
    test = '''    #[test]
    fn named_lpm_shape_reaches_existing_native_dispatch() -> Result<()> {
        let kind=parse_lookup_kind("lpm12")?;
        let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
        let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
        let bytes=[0x48,0x8b,0x3d,0,0,0,0,0xb8,1,0,0,0,0xff,0xd0,0xc3];
        object.append_section_data(text,&bytes,1);
        object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:0,size:bytes.len() as u64,
            kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
            section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
        let map=object.add_symbol(WriteSymbol{name:b"map".to_vec(),value:0,size:0,
            kind:SymbolKind::Data,scope:SymbolScope::Linkage,weak:false,
            section:WriteSymbolSection::Undefined,flags:SymbolFlags::None});
        object.add_relocation(text,WriteRelocation{offset:3,symbol:map,addend:-4,
            flags:RelocationFlags::Elf{r_type:9}})?;
        let data=object.write()?;let elf=object::File::parse(data.as_slice())?;
        let entry=find_symbol_by_name(&elf,"entry")?;
        let spec=LookupSiteSpec{kind,target_addr:0x5678,key_offset:0,max_entries:0,
            elem_size:0,index_mask:0,value_offset:0,percpu_base_addr:0};
        let layout=RuntimeLpmLayout{map_type:12,lpm_type:11,root:40,max_prefixlen:48,data_size:56,
            child:0,child_stride:8,node_prefixlen:16,node_flags:20,node_data:24,key_prefixlen:0,key_data:4};
        for exact in [false,true] {for available in [false,true] {for typed in [false,true] {
            let mut fact=spec.clone();if !typed {fact.kind=LookupKind::Call;}
            let facts=HashMap::from([((if exact {"map"}else{"other"}).into(),fact)]);
            let result=rewrite_x86(&elf,&entry,&[entry.clone()],
                &HashMap::from([("bpf_map_lookup_elem".into(),0x1234)]),
                &HashMap::from([("map".into(),0)]),&facts,&[],false,false,None,None,
                if available {Some(&layout)}else{None},false)?;
            let targets:Vec<_>=result.relocs.iter().filter(|r|r.kind==1).map(|r|r.target).collect();
            let raw=exact && (!available || !typed);
            assert_eq!(targets,vec![if raw {0x5678}else{0x1234}],
                "exact={exact} available={available} typed={typed}");
            let has_native=!raw && available;
            assert_eq!(result.blob.len()>bytes.len()+100,has_native,"one native routine when eligible");
        }}}
        Ok(())
    }

'''
    assert anchor in s
    x.write_text(s.replace(anchor,test+anchor,1))
elif sys.argv[1] == 'fix':
    s = m.read_text().replace('enum LookupKind {\n    Call,','enum LookupKind {\n    Call,\n    Lpm12,',1)
    s = s.replace('"call" => Ok(LookupKind::Call),','"call" => Ok(LookupKind::Call),\n        "lpm12" => Ok(LookupKind::Lpm12),',1)
    s = s.replace('LookupKind::Call => require_call_target', 'LookupKind::Call | LookupKind::Lpm12 => require_call_target')
    s = s.replace('LookupKind::Call | LookupKind::Array', 'LookupKind::Call | LookupKind::Lpm12 | LookupKind::Array')
    s = s.replace('LookupKind::Call\n                                | LookupKind::Hash', 'LookupKind::Call\n                                | LookupKind::Lpm12\n                                | LookupKind::Hash')
    m.write_text(s)
    s = x.read_text().replace('LookupKind::Call | LookupKind::Array','LookupKind::Call | LookupKind::Lpm12 | LookupKind::Array')
    s = s.replace('''                            LookupKind::Call
                            | LookupKind::Hash''','''                            LookupKind::Call
                            | LookupKind::Lpm12
                            | LookupKind::Hash''',1)
    marker = '''                                let helper_addr = resolve_lookup_site_target(
                                    &spec,
                                    &format!("x86 lookup-site {site_label} ({:?})", spec.kind),
                                )?;'''
    assert marker in s
    s = s.replace(marker,'''                                // The loaded LPM key has the existing native routine's 12 data bytes.
                                // Reuse its shared dispatch/body; other shapes keep the kernel target.
                                let helper_addr = if spec.kind==LookupKind::Lpm12 && !proof_mode
                                    && runtime_lpm_layout.is_some() && map_lookup_helper_addr!=0 {
                                    map_lookup_helper_addr
                                } else { resolve_lookup_site_target(&spec,
                                    &format!("x86 lookup-site {site_label} ({:?})",spec.kind))? };''',1)
    x.write_text(s)
    s = h.read_text().replace('''    const CompanionLoad::LookupSite &site)
{
    return NativeLinkArgs::LookupSite{
        lookup_kind_name(site.kind),''','''    const CompanionLoad::LookupSite &site, const MapMeta *meta = nullptr)
{
    return NativeLinkArgs::LookupSite{
        meta && meta->type == BPF_MAP_TYPE_LPM_TRIE && meta->key_size == 16
            ? "lpm12" : lookup_kind_name(site.kind),''',1)
    s = s.replace('''            make_link_lookup_site(site),''','''            make_link_lookup_site(site, meta),''',1)
    h.write_text(s)
else:
    raise ValueError('stage must be test or fix')
