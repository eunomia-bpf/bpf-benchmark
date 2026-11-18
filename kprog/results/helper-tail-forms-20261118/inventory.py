#!/usr/bin/env python3
"""Inventory actual helper tails and their existing map facts in every capture."""
import argparse
from collections import Counter,defaultdict
import json
from pathlib import Path
import struct
from elftools.elf.elffile import ELFFile

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--replay',type=Path,required=True)
p.add_argument('--system-map',type=Path,required=True)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
symbols={fields[2]:int(fields[0],16) for line in a.system_map.read_text().splitlines()
         if len(fields:=line.split())==3}
replay=json.loads(a.replay.read_text());counts=defaultdict(Counter);rows=[]
for request in replay['requests']:
    c=counts[request['app']];c['requests']+=1
    row=dict(app=request['app'],symbol=request['symbol'],capture=request['capture'],
             proof=request['proof'],plan=request['plan'],output=request['output'],returncode=request['returncode'])
    if request['returncode']:
        row['error_tail']=request['error_tail'];c['errors']+=1;rows.append(row);continue
    c['emitted']+=1;folder=Path(request['output']);plan=json.loads(Path(request['plan']).read_text())
    helpers={h['name']:h['addr'] for h in plan['helpers']}
    slide=helpers['bpf_map_lookup_elem']-symbols['bpf_map_lookup_elem'];trie=symbols['trie_lookup_elem']+slide
    maps={s['name']:s for s in plan['lookup_maps']};tails=[];ordinary=[]
    for line in (folder/'stderr').read_text().splitlines():
        if line.startswith('native-link-helper-tail-site '):tails.append(json.loads(line.split(' ',1)[1]))
        elif line.startswith('native-link-helper-site '):ordinary.append(json.loads(line.split(' ',1)[1]))
    if tails:
        with Path(request['proof']).open('rb') as f:
            elf=ELFFile(f);table=elf.get_section_by_name('.symtab')
            for site in tails:
                candidates=[s for s in table.get_symbol_by_name(site['symbol']) or []
                            if isinstance(s['st_shndx'],int) and s['st_value']<=site['input_offset']<s['st_value']+s['st_size']]
                site['source_candidates']=len(candidates)
                if len(candidates)==1:
                    sym=candidates[0];section=elf.get_section(sym['st_shndx']);offset=site['input_offset']-section['sh_addr']
                    site['proof_bytes_at_site']=section.data()[offset:offset+8].hex()
                site['lookup_fact']=maps.get(site['map'])
                fact=site['lookup_fact']
                site['named_trie_operation']=bool(fact and fact['target_addr']==trie)
                c['tail_sites']+=1;c['tail_'+site['form']]+=1
                for helper in site['helpers']:c['tail_helper_'+helper]+=1
                if 'bpf_map_lookup_elem' in site['helpers']:
                    c['lookup_tail_sites']+=1;c['lookup_tail_named']+=int(site['map'] is not None)
                    c['lookup_tail_trie_operation']+=int(site['named_trie_operation'])
    blob=(folder/'image.blob').read_bytes();relocs=list(struct.iter_unpack('<IIQ',(folder/'image.relocs').read_bytes()))
    calls=[dict(offset=o,target=t,opcode=hex(blob[o])) for o,k,t in relocs
           if k==1 and t in [trie,helpers['bpf_map_lookup_elem']]]
    for call in calls:c[('trie_' if call['target']==trie else 'generic_')+call['opcode']]+=1
    row.update(tails=tails,ordinary_lookup_sites=[s for s in ordinary if s['helper']=='bpf_map_lookup_elem'],
               map_lookup_relocations=calls,trie_target=trie)
    rows.append(row)
result=dict(replay=str(a.replay),system_map=str(a.system_map),index_errors=replay['index_errors'],
            summary={k:dict(v) for k,v in sorted(counts.items())},requests=rows,
            scope='Static actual source-tail records from existing helper/map provenance, with retained proof bytes '
                  'and emitted relocation opcodes. A trie operation establishes map kind; LPM key shape, '
                  'frequency, installed size and per-call effect remain loaded/runtime measurements.')
(a.output/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
lines=[app+' '+json.dumps(c,sort_keys=True) for app,c in result['summary'].items()]
(a.output/'summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
