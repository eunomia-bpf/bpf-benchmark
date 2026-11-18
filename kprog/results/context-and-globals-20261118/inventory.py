#!/usr/bin/env python3
"""Read actual BCC executable relocations to loaded map/data symbols."""
import argparse
from collections import Counter
import json
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--replay',type=Path,required=True)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args();report=json.loads(a.replay.read_text());rows=[];names=Counter()
for request in report['requests']:
    if request['app']!='bcc/set':continue
    plan=json.loads(Path(request['plan']).read_text())
    bindings={r['name'] for r in plan['maps']}
    row=dict(symbol=request['symbol'],capture=request['capture'],proof=request['proof'],
             plan=request['plan'],returncode=request['returncode'],references=[])
    if request['returncode']:
        row['error_tail']=request['error_tail'];rows.append(row);continue
    with Path(request['proof']).open('rb') as f:
        elf=ELFFile(f)
        for section in elf.iter_sections():
            if not isinstance(section,RelocationSection):continue
            code=elf.get_section(section['sh_info'])
            if not code['sh_flags'] & 4:continue
            symbols=elf.get_section(section['sh_link'])
            for reloc in section.iter_relocations():
                symbol=symbols.get_symbol(reloc['r_info_sym'])
                if symbol.name not in bindings:continue
                definition=symbol['st_shndx']
                row['references'].append(dict(section=code.name,offset=reloc['r_offset'],
                    relocation_type=reloc['r_info_type'],symbol=symbol.name,
                    symbol_type=symbol['st_info']['type'],symbol_size=symbol['st_size'],
                    definition=elf.get_section(definition).name if isinstance(definition,int) else definition))
                names[symbol.name]+=1
    rows.append(row)
result=dict(scope='Executable-section relocations in 25 actual BCC selected-entry proof inputs, '
            'matched to names bound in their actual kernel plans. Debug/BTF references stay '
            'outside this code-reference inventory. Presence describes remaining map/data '
            'accesses; absence alone proves neither a frozen value nor complete load-time folding.',
            replay=str(a.replay),requests=rows,bound_symbol_relocations=dict(sorted(names.items())))
a.output.mkdir(parents=True,exist_ok=True)
(a.output/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
lines=[r['symbol']+': '+', '.join(f'{k}={v}' for k,v in sorted(Counter(
       s['symbol'] for s in r['references']).items())) for r in rows]
(a.output/'summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
