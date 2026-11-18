#!/usr/bin/env python3
"""Attribute recovery metadata changes to the shorter live flag instruction."""
import argparse
import json
from pathlib import Path

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('comparison',type=Path)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args()
rows=[]
def sites(folder):
    lines=(folder/'image.abi').read_text().replace('\\n','\n').replace('\\t','\t').splitlines()
    return [tuple(map(int,line.split('\t')[1].split(','))) for line in lines if line.startswith('load_site\t')]
for request in json.loads(a.comparison.read_text())['requests']:
    row=dict(app=request['app'],symbol=request['symbol'],capture=request['capture'])
    if request['returncode']:
        row['returncode']=request['returncode'];rows.append(row);continue
    before,after=Path(request['before_output']),Path(request['after_output'])
    old,new=sites(before),sites(after)
    ob,nb=(before/'image.blob').read_bytes(),(after/'image.blob').read_bytes()
    changed=[(o,n) for o,n in zip(old,new) if o[1:]!=n[1:]]
    changes=[]
    for o,n in changed:
        changes.append(dict(before=o,after=n,before_bytes=ob[o[0]:o[0]+o[1]].hex(),
                            after_bytes=nb[n[0]:n[0]+n[1]].hex(),
                            matches_flag=(o[1:]==(7,65535) and n[1:]==(4,65535)
                              and ob[o[0]:o[0]+7]==bytes.fromhex('f7421401000000')
                              and nb[n[0]:n[0]+4]==bytes.fromhex('f6421401'))))
    mapped=[(offset-sum(3 for o,_ in changed if o[0]<offset),
             length-(3 if any(o[0]==offset for o,_ in changed) else 0),destination)
            for offset,length,destination in old]
    row.update(before_sites=len(old),after_sites=len(new),changed_flags=changes,
               expected_flag_count=len(request['after_ranges']),
               flag_count_matches=len(changes)==len(request['after_ranges']),
               offsets_lengths_destinations_match=mapped==new)
    rows.append(row)
result=dict(scope='Actual captured kernel layout flag offset20; ordered site alignment and exact flag bytes. '
                  'Other instruction recovery lengths/destinations stay, offsets follow the3B deletion.',
            comparison=str(a.comparison),requests=rows)
a.output.write_text(json.dumps(result,indent=2)+'\n')
print('requests',len(rows),'changed flags',sum(len(r.get('changed_flags',[])) for r in rows),
      'attribution mismatches',sum(not r.get('flag_count_matches',False) or
          not r.get('offsets_lengths_destinations_match',False) or
          not all(c['matches_flag'] for c in r.get('changed_flags',[])) for r in rows))
