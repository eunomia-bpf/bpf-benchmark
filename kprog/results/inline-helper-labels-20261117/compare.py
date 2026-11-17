#!/usr/bin/env python3
"""Compare completed paired host emissions and identify actual incoming helper branches."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import re
import subprocess
import sys

out=Path('kprog/results/inline-helper-labels-20261117')
raw=Path(sys.argv[1])
before=json.loads(Path('kprog/results/current-link-capture-20261117/replay.json').read_text())
after=json.loads((raw/'replay/replay.json').read_text())
previous={r['capture']:r for r in before['requests']}
summary=defaultdict(Counter)
rows=[]
for row in after['requests']:
    old=previous[row['capture']]
    a,b=Path(old['output']),Path(row['output'])
    same={name:(a/name).read_bytes()==(b/name).read_bytes() for name in
          ('image.blob','image.relocs','image.maps','image.abi')}
    counts=summary[row['app']]
    counts.update(requests=1,changed_payloads=int(not same['image.blob']),
                  before_bytes=old['payload_bytes'],after_bytes=row['payload_bytes'])
    witnesses=[]
    if not same['image.blob']:
        sites=[]
        for line in (b/'stderr').read_text().splitlines():
            if line.startswith('native-link-helper-site '):
                record=json.loads(line.split(' ',1)[1])
                if record['helper'] in ('bpf_get_current_task','bpf_get_current_task_btf',
                                        'bpf_get_smp_processor_id','bpf_jiffies64','bpf_tail_call'):
                    sites.append(record)
        text=subprocess.run(['objdump','-dr',row['proof']],capture_output=True,text=True,check=True).stdout
        (b/'source-branch-disassembly.txt').write_text(text)
        instructions=defaultdict(list)
        function=None
        for line in text.splitlines():
            label=re.match(r'^[0-9a-f]+ <([^>]+)>:',line)
            if label: function=label[1]
            insn=re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+([a-z][a-z0-9]*)\s*(.*)$',line)
            if insn: instructions[function].append((int(insn[1],16),insn[2],insn[3]))
        for site in sites:
            body=instructions[site['symbol']]
            positions=[i for i,v in enumerate(body) if v[0]==site['input_offset']]
            if not positions: continue
            index=positions[0]
            labels={body[index][0]}
            while index and body[index-1][1].startswith('nop'):
                index-=1;labels.add(body[index][0])
            for address,mnemonic,operand in body:
                target=re.match(r'([0-9a-f]+)\s+<',operand)
                if mnemonic.startswith('j') and target and int(target[1],16) in labels:
                    witnesses.append(dict(function=site['symbol'],helper=site['helper'],
                        input_helper_offset=site['input_offset'],branch_offset=address,
                        target=int(target[1],16),mnemonic=mnemonic,operand=operand))
    counts.update(incoming_branch_witnesses=len(witnesses))
    rows.append(dict(app=row['app'],symbol=row['symbol'],capture=row['capture'],
        before_output=str(a),after_output=str(b),before_bytes=old['payload_bytes'],
        after_bytes=row['payload_bytes'],same=same,incoming_branch_witnesses=witnesses))
result=dict(scope='Completed host-neutral emissions using the same actual paired inputs. Branch witnesses '
                  'are static source edges, not branch execution frequencies or installed-size/per-call results.',
            summary={k:dict(v) for k,v in sorted(summary.items())},requests=rows)
(out/'comparison.json').write_text(json.dumps(result,indent=2)+'\n')
lines=['app requests changed_payloads before_bytes after_bytes incoming_branch_witnesses']
for app,c in sorted(summary.items()):
    lines.append(' '.join([app,*[str(c[k]) for k in
                 ('requests','changed_payloads','before_bytes','after_bytes','incoming_branch_witnesses')]]))
(out/'comparison-summary.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
