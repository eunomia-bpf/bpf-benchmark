#!/usr/bin/env python3
"""Compare completed dead-ID emissions with the actual post-label-fix baseline."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct
import sys

raw=Path(sys.argv[1]);out=Path('kprog/results/dead-helper-ids-20261117')
baseline=Path('/workspaces/kprog-raw/perf/inline-helper-labels-20261117/host-20261117T204206Z-2750151/replay/replay.json')
before={r['capture']:r for r in json.loads(baseline.read_text())['requests']}
after=json.loads((raw/'replay/replay.json').read_text())
counts=defaultdict(Counter);rows=[]
def records(path):return list(struct.iter_unpack('<IIQ',path.read_bytes()))
def text_rows(path):return [r.split('\t') for r in path.read_text().replace('\\n','\n').replace('\\t','\t').splitlines()]
for request in after['requests']:
    old=before[request['capture']];app=request['app'];c=counts[app]
    row=dict(app=app,symbol=request['symbol'],capture=request['capture'],
             before_output=old['output'],after_output=request['output'],returncode=request['returncode'])
    c.update(requests=1,passed=int(request['returncode']==0),failed=int(request['returncode']!=0))
    if request['returncode'] or old['returncode']:
        row['current_error']=request.get('error_tail');row['baseline_error']=old.get('error_tail')
        rows.append(row);continue
    a,b=Path(old['output']),Path(request['output'])
    aa,bb=(a/'image.blob').read_bytes(),(b/'image.blob').read_bytes()
    ar,br=records(a/'image.relocs'),records(b/'image.relocs')
    am,bm=text_rows(a/'image.maps'),text_rows(b/'image.maps')
    ab,ba=text_rows(a/'image.abi'),text_rows(b/'image.abi')
    equal=dict(payload=aa==bb,
        helper_targets=Counter(t for _,k,t in ar if k==1)==Counter(t for _,k,t in br if k==1),
        relocation_kinds=Counter(k for _,k,_ in ar)==Counter(k for _,k,_ in br),
        map_names=Counter(r[0] for r in am)==Counter(r[0] for r in bm),
        callee_mask=[r for r in ab if r[0]=='callee_saved_mask']==[r for r in ba if r[0]=='callee_saved_mask'],
        recovery_shapes=Counter(tuple(r[1].split(',')[1:]) for r in ab if r[0]=='load_site')==
                        Counter(tuple(r[1].split(',')[1:]) for r in ba if r[0]=='load_site'))
    row.update(before_bytes=len(aa),after_bytes=len(bb),equal=equal)
    c.update(before_bytes=len(aa),after_bytes=len(bb),changed=int(aa!=bb))
    for name,same in equal.items():
        if name!='payload':c.update({name+'_differences':int(not same)})
    rows.append(row)
result=dict(scope='Paired actual host-neutral emissions after the label fix. All requests/failures retained. '
    'Helper target multiplicities, map-name counts, callee mask and recovery shape counts are observations, '
    'not a complete semantic proof or installed-size/per-call/throughput result. Code/image-pointer offsets '
    'can move. Original raw sidecars are not normalized or changed.',baseline=str(baseline),raw=str(raw),
    index_errors=after['index_errors'],summary={k:dict(v) for k,v in sorted(counts.items())},requests=rows)
(out/'comparison.json').write_text(json.dumps(result,indent=2)+'\n')
lines=['app requests passed failed changed before_bytes after_bytes helper_target_differences map_name_differences mask_differences recovery_shape_differences']
for app,c in sorted(counts.items()):
    lines.append(' '.join([app,*[str(c[k]) for k in ('requests','passed','failed','changed','before_bytes',
       'after_bytes','helper_targets_differences','map_names_differences','callee_mask_differences','recovery_shapes_differences')]]))
lines.append('index_errors '+str(len(after['index_errors'])))
(out/'comparison-summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
