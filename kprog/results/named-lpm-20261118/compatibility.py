#!/usr/bin/env python3
"""Compare all legacy emissions, keeping activation separate from compatibility."""
import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--before',type=Path,required=True)
p.add_argument('--after',type=Path,required=True)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args()
b=json.loads(a.before.read_text());n=json.loads(a.after.read_text())
old={r['capture']:r for r in b['requests']};new={r['capture']:r for r in n['requests']}
summary=defaultdict(Counter);rows=[]
for capture in sorted(old.keys()|new.keys()):
    before,after=old.get(capture),new.get(capture)
    c=summary[(after or before)['app']];c['requests']+=1
    row=dict(capture=capture,before=before,after=after)
    if before is None or after is None:c['unpaired']+=1
    elif before['returncode'] or after['returncode']:c['errors']+=1
    else:
        row['artifact_equal']={name:(Path(before['output'])/name).read_bytes()==
                              (Path(after['output'])/name).read_bytes()
                              for name in ['image.blob','image.relocs','image.maps','image.abi']}
        c.update(emitted=1,identical=int(all(row['artifact_equal'].values())),
                 changed=int(not all(row['artifact_equal'].values())))
    rows.append(row)
result=dict(scope='Unchanged captured plans retain original call kinds. Equal artifacts measure '
            'compatibility only; candidate activation is covered by shape/binding/execution '
            'fixtures and requires actual loaded selection in the next image.',
            before=str(a.before),after=str(a.after),before_index_errors=b['index_errors'],
            after_index_errors=n['index_errors'],summary={k:dict(v) for k,v in sorted(summary.items())},requests=rows)
a.output.mkdir(parents=True,exist_ok=True)
(a.output/'compatibility.json').write_text(json.dumps(result,indent=2)+'\n')
lines=[f"{app}: {s.get('emitted',0)}/{s['requests']} emit, {s.get('identical',0)} identical, "
       f"{s.get('changed',0)} changed artifact sets" for app,s in result['summary'].items()]
(a.output/'compatibility-summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
