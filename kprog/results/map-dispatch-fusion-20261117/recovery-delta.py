#!/usr/bin/env python3
"""Classify real recovery metadata changes after removing the ARRAY fallback frame."""
from collections import Counter
import json
from pathlib import Path
import sys
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
comparison=json.loads(Path('kprog/results/map-dispatch-fusion-20261117/comparison.json').read_text())
def loads(folder):
    text=(Path(folder)/'image.abi').read_text().replace('\\n','\n').replace('\\t','\t')
    return [tuple(int(v) for v in line.split('\t',1)[1].split(',')) for line in text.splitlines() if line.startswith('load_site\t')]
rows=[];summary=Counter()
for row in comparison['requests']:
    if row['returncode']:rows.append(dict(capture=row['capture'],returncode=row['returncode']));continue
    before,after=loads(row['before_output']),loads(row['after_output'])
    a,b=Counter((length,dest) for _,length,dest in before),Counter((length,dest) for _,length,dest in after)
    removed,added=a-b,b-a
    array=next((r for r in row['previous_ranges'] if r['piece']=='runtime_array'),None)
    fused=bool(row['fused_ranges'])
    old_return=None
    if fused and array:
        offset=array['end']-1
        data=(Path(row['before_output'])/'image.blob').read_bytes()
        old_return=dict(offset=offset,opcode=data[offset],registered=(offset,1,65535) in before)
    explained=(removed==Counter({(1,65535):1}) and not added
        and old_return is not None and old_return['opcode']==0xc3 and old_return['registered']) if fused else a==b
    prefix_equal=lpm_equal=None
    if fused:
        lpm=next(r for r in row['previous_ranges'] if r['piece']=='lpm_lookup')
        current=row['fused_ranges'][0]
        previous=(Path(row['before_output'])/'image.blob').read_bytes()
        emitted=(Path(row['after_output'])/'image.blob').read_bytes()[current['start']:current['end']]
        prefix=previous[array['start']:array['end']-14]
        prefix_equal=emitted[:len(prefix)]==prefix
        lpm_equal=emitted[len(prefix):]==previous[lpm['start']:lpm['end']]
    rows.append(dict(app=row['app'],symbol=row['symbol'],capture=row['capture'],fused=fused,
        array_prefix_byte_identical=prefix_equal,lpm_body_byte_identical=lpm_equal,
        removed_shapes=[dict(length=k[0],destination=k[1],count=v) for k,v in removed.items()],
        added_shapes=[dict(length=k[0],destination=k[1],count=v) for k,v in added.items()],
        old_array_fallback_return=old_return,explained_by_removed_return=explained))
    summary.update(requests=1,fused=int(fused),explained=int(explained),other_differences=int(not explained),
        identical_array_prefixes=int(prefix_equal is True),identical_lpm_bodies=int(lpm_equal is True))
j=dict(scope='Actual ABI sidecar observations. Removed ARRAY fallback RET has an implicit stack read '
    'with destination65535. Classifies its removal; no full recovery semantics, stock or timing claim.',
    summary=dict(summary),requests=rows)
(out/'recovery-delta.json').write_text(json.dumps(j,indent=2)+'\n')
(out/'recovery-delta-summary.txt').write_text(json.dumps(dict(summary))+'\n')
print(json.dumps(dict(summary)))
