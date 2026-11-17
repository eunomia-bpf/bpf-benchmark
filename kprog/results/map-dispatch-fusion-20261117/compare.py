#!/usr/bin/env python3
"""Compare actual fused emissions with the immediately preceding dead-ID replay."""
from collections import Counter,defaultdict
import json
from pathlib import Path
import struct
import sys
raw=Path(sys.argv[1]);out=Path('kprog/results/map-dispatch-fusion-20261117')
baseline=Path('/workspaces/kprog-raw/perf/link-entry-replay-20261117/host-20261117T223029Z-2788020/replay/replay.json')
before={r['capture']:r for r in json.loads(baseline.read_text())['requests']}
after=json.loads((raw/'replay/replay.json').read_text())
counts=defaultdict(Counter);rows=[]
def relocations(p):return list(struct.iter_unpack('<IIQ',(p/'image.relocs').read_bytes()))
def text_rows(p):return [r.split('\t') for r in p.read_text().replace('\\n','\n').replace('\\t','\t').splitlines()]
for request in after['requests']:
    old=before[request['capture']];c=counts[request['app']]
    row=dict(app=request['app'],symbol=request['symbol'],capture=request['capture'],
        before_output=old['output'],after_output=request['output'],returncode=request['returncode'])
    c.update(requests=1,passed=int(request['returncode']==0),failed=int(request['returncode']!=0))
    if request['returncode'] or old['returncode']:
        row.update(current_error=request.get('error_tail'),baseline_error=old.get('error_tail'))
        rows.append(row);continue
    a,b=Path(old['output']),Path(request['output'])
    aa,bb=(a/'image.blob').read_bytes(),(b/'image.blob').read_bytes()
    ar,br=relocations(a),relocations(b)
    abi_a,abi_b=text_rows(a/'image.abi'),text_rows(b/'image.abi')
    equal=dict(payload=aa==bb,
        helper_targets=Counter(t for _,k,t in ar if k==1)==Counter(t for _,k,t in br if k==1),
        relocation_kinds=Counter(k for _,k,_ in ar)==Counter(k for _,k,_ in br),
        map_names=Counter(r[0] for r in text_rows(a/'image.maps'))==Counter(r[0] for r in text_rows(b/'image.maps')),
        callee_mask=[r for r in abi_a if r[0]=='callee_saved_mask']==[r for r in abi_b if r[0]=='callee_saved_mask'],
        recovery_shapes=Counter(tuple(r[1].split(',')[1:]) for r in abi_a if r[0]=='load_site')==
            Counter(tuple(r[1].split(',')[1:]) for r in abi_b if r[0]=='load_site'))
    old_ranges=old.get('lto_ranges',[]);new_ranges=request.get('lto_ranges',[])
    fused=[r for r in new_ranges if r['piece']=='runtime_array_lpm']
    previous=[r for r in old_ranges if r['piece'] in ('runtime_array','lpm_lookup')]
    row.update(before_bytes=len(aa),after_bytes=len(bb),equal=equal,
        previous_ranges=previous,fused_ranges=fused,
        previous_dispatch_bytes=sum(r['end']-r['start'] for r in previous),
        fused_dispatch_bytes=sum(r['end']-r['start'] for r in fused))
    c.update(before_bytes=len(aa),after_bytes=len(bb),changed=int(aa!=bb),fused_images=int(bool(fused)))
    for name,same in equal.items():
        if name!='payload':c.update({name+'_differences':int(not same)})
    rows.append(row)
result=dict(scope='Actual paired host-neutral emissions after dead-ID source; all requests/errors retained. '
    'Ranges/helper target multiplicities/map names/masks/recovery shape counts are observations, not a '
    'complete semantic proof, installed-code measurement or timing. Original sidecars remain unchanged.',
    baseline=str(baseline),raw=str(raw),index_errors=after['index_errors'],
    summary={k:dict(v) for k,v in sorted(counts.items())},requests=rows)
(out/'comparison.json').write_text(json.dumps(result,indent=2)+'\n')
keys=('requests','passed','failed','changed','fused_images','before_bytes','after_bytes',
    'helper_targets_differences','map_names_differences','callee_mask_differences','recovery_shapes_differences')
lines=['app '+' '.join(keys)]+[app+' '+' '.join(str(c[k]) for k in keys) for app,c in sorted(counts.items())]
lines.append('index_errors '+str(len(after['index_errors'])))
(out/'comparison-summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
