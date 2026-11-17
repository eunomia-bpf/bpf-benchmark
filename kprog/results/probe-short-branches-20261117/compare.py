#!/usr/bin/env python3
"""Check the moved source loads against their pre-sizing bytes and record sizes."""
from pathlib import Path
import argparse,json
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--before',type=Path,required=True)
p.add_argument('--after',type=Path,required=True)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args()
rows=[]
for old_metadata in sorted(a.before.glob('*.sites')):
    name=old_metadata.name
    before=[tuple(map(int,line.split())) for line in old_metadata.read_text().splitlines()[1:]]
    after=[tuple(map(int,line.split())) for line in (a.after/name).read_text().splitlines()[1:]]
    assert len(before)==len(after),name
    old=(a.before/old_metadata.with_suffix('.bin').name).read_bytes()
    new=(a.after/old_metadata.with_suffix('.bin').name).read_bytes()
    for (x,length,destination),(y,new_length,new_destination) in zip(before,after):
        assert (length,destination)==(new_length,new_destination),name
        assert old[x:x+length]==new[y:y+length],(name,x,y)
    rows.append(dict(name=old_metadata.stem,before_bytes=len(old),after_bytes=len(new),
        bytes_saved=len(old)-len(new),loads=len(before),
        load_offsets_before=[r[0] for r in before],load_offsets_after=[r[0] for r in after]))
a.output.mkdir(parents=True,exist_ok=True)
(a.output/'sizes-and-loads.json').write_text(json.dumps(rows,indent=2)+'\n')
lines=['name before_bytes after_bytes saved source_load_sites']
lines += [f"{r['name']} {r['before_bytes']} {r['after_bytes']} {r['bytes_saved']} {r['loads']}" for r in rows]
(a.output/'sizes.txt').write_text('\n'.join(lines)+'\n')
print(f'{len(rows)} probe forms retain protected-load bytes, lengths and R11 destinations after mapping')
