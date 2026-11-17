#!/usr/bin/env python3
"""Count adjacent RAX helper-ID definitions in actual captured proof inputs."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import subprocess
import sys

raw=Path(sys.argv[1]);raw.mkdir(parents=True,exist_ok=True)
report=Path('/workspaces/kprog-raw/perf/inline-helper-labels-20261117/host-20261117T204206Z-2750151/replay/replay.json')
rows=json.loads(report.read_text())['requests']
summary=defaultdict(Counter);candidates=[]
for row in rows:
    output=Path(row['output'])
    sites={}
    for line in (output/'stderr').read_text().splitlines():
        if line.startswith('native-link-helper-site '):
            site=json.loads(line.split(' ',1)[1])
            sites[(site['symbol'],site['input_offset'])]=site['helper']
    text=subprocess.run(['objdump','-dr',row['proof']],capture_output=True,text=True,check=True).stdout
    function=None;previous=None
    for line in text.splitlines():
        label=re.match(r'^[0-9a-f]+ <([^>]+)>:',line)
        if label:function=label[1];previous=None
        insn=re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+([a-z][a-z0-9]*)\s*(.*)$',line)
        if not insn:continue
        address,mnemonic,operand=int(insn[1],16),insn[2],insn[3]
        helper=sites.get((function,address))
        if helper and mnemonic=='call' and operand.strip()=='*%rax' and previous:
            paddr,pmnem,poperand=previous
            immediate=re.fullmatch(r'\$0x([0-9a-f]+),%(eax|rax)',poperand.replace(' ',''))
            if pmnem in ('mov','movabs') and immediate:
                numeric=int(immediate[1],16)
                candidate=dict(app=row['app'],symbol=row['symbol'],function=function,
                    proof=row['proof'],capture=row['capture'],helper=helper,id=numeric,
                    mov_offset=paddr,call_offset=address,immediate_bytes=address-paddr,
                    tail_call=helper=='bpf_tail_call')
                candidates.append(candidate)
                group='tail' if candidate['tail_call'] else 'ordinary'
                summary[row['app']].update({group+'_sites':1,group+'_bytes':address-paddr})
        previous=(address,mnemonic,operand)
result=dict(scope='Static actual proof sites and immediate byte counts. Not executed frequency, '
                  'installed size or gain. Tail calls are recorded separately and kept unchanged.',
            source_report=str(report),summary={k:dict(v) for k,v in sorted(summary.items())},candidates=candidates)
(raw/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
lines=['app ordinary_sites ordinary_bytes tail_sites tail_bytes']
for app,c in sorted(summary.items()):lines.append(' '.join([app,*[str(c[k]) for k in
                                                ('ordinary_sites','ordinary_bytes','tail_sites','tail_bytes')]]))
(raw/'summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
