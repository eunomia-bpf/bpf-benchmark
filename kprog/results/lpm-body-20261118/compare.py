#!/usr/bin/env python3
"""Report every actual emission and metadata observation after child scaling."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('raw',type=Path)
p.add_argument('--output',type=Path,required=True)
p.add_argument('--before',type=Path,default=Path('kprog/results/named-lpm-20261118/replay.json'))
a=p.parse_args()
baseline=a.before
old={r['capture']:r for r in json.loads(baseline.read_text())['requests']}
after=json.loads((a.raw/'replay/replay.json').read_text())
counts=defaultdict(Counter); rows=[]
def text(path):
    return [r.split('\t') for r in path.read_text().replace('\\n','\n').replace('\\t','\t').splitlines()]
for request in after['requests']:
    before=old[request['capture']]; c=counts[request['app']]
    row=dict(app=request['app'],symbol=request['symbol'],capture=request['capture'],
             before_output=before['output'],after_output=request['output'],returncode=request['returncode'])
    c.update(requests=1,passed=int(request['returncode']==0),failed=int(request['returncode']!=0))
    if before['returncode'] or request['returncode']:
        row.update(before_error=before.get('error_tail'),after_error=request.get('error_tail'))
    else:
        left,right=Path(before['output']),Path(request['output'])
        b,n=(left/'image.blob').read_bytes(),(right/'image.blob').read_bytes()
        br=list(struct.iter_unpack('<IIQ',(left/'image.relocs').read_bytes()))
        nr=list(struct.iter_unpack('<IIQ',(right/'image.relocs').read_bytes()))
        ba,na=text(left/'image.abi'),text(right/'image.abi')
        equal=dict(helper_targets=Counter(t for _,k,t in br if k==1)==Counter(t for _,k,t in nr if k==1),
                   relocation_kinds=Counter(k for _,k,_ in br)==Counter(k for _,k,_ in nr),
                   map_names=Counter(r[0] for r in text(left/'image.maps'))==Counter(r[0] for r in text(right/'image.maps')),
                   callee_mask=[r for r in ba if r[0]=='callee_saved_mask']==[r for r in na if r[0]=='callee_saved_mask'],
                   recovery_shapes=Counter(tuple(r[1].split(',')[1:]) for r in ba if r[0]=='load_site')==
                                   Counter(tuple(r[1].split(',')[1:]) for r in na if r[0]=='load_site'))
        ranges=lambda r:[x for x in r['lto_ranges'] if x['piece'] in ['runtime_array_lpm','lpm_lookup']]
        old_ranges,new_ranges=ranges(before),ranges(request)
        row.update(before_bytes=len(b),after_bytes=len(n),equal=equal,
                   before_ranges=old_ranges,after_ranges=new_ranges)
        c.update(before_bytes=len(b),after_bytes=len(n),changed=int(b!=n),
                 routines=len(new_ranges),growth=int(len(n)>len(b)))
        for name,same in equal.items(): c[name+'_differences']+=int(not same)
    rows.append(row)
result=dict(raw=str(a.raw),baseline=str(baseline),index_errors=after['index_errors'],
            summary={k:dict(v) for k,v in sorted(counts.items())},requests=rows,
            scope='Paired host-neutral artifacts and metadata observations. Installed app bytes and per-call effects remain batch measurements.')
a.output.write_text(json.dumps(result,indent=2)+'\n')
for app,c in result['summary'].items():
    print(app,json.dumps(c,sort_keys=True))
