#!/usr/bin/env python3
"""Observe the retained ARRAY-to-LPM dispatch chain before proposing fusion."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import struct
import sys

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/inline-helper-labels-20261117/host-20261117T204206Z-2750151/replay/replay.json')
summary=defaultdict(Counter);rows=[]
for row in json.loads(source.read_text())['requests']:
    regions={r['piece']:r for r in row.get('lto_ranges',[])}
    array,lpm=regions.get('runtime_array'),regions.get('lpm_lookup')
    record=dict(app=row['app'],symbol=row['symbol'],output=row['output'],
                returncode=row['returncode'],array=array,lpm=lpm)
    c=summary[row['app']];c.update(requests=1,both_ranges=int(bool(array and lpm)))
    if array and lpm:
        data=(Path(row['output'])/'image.blob').read_bytes()
        tail=data[array['end']-14:array['end']]
        shape=len(tail)==14 and tail[:4]==bytes.fromhex('4883ec08') and tail[4]==0xe8 and tail[-5:]==bytes.fromhex('4883c408c3')
        target=array['end']-5+struct.unpack_from('<i',tail,5)[0] if shape else None
        external=data[lpm['end']-14:lpm['end']]
        final_shape=len(external)==14 and external==bytes.fromhex('4883ec08e8000000004883c408c3')
        relocs=list(struct.iter_unpack('<IIQ',(Path(row['output'])/'image.relocs').read_bytes()))
        final_calls=[dict(offset=o,kind=k,target=t) for o,k,t in relocs if k==1 and o==lpm['end']-10]
        record.update(array_fallback_bytes=tail.hex(),array_nested_call=shape,
                      array_call_target=target,array_calls_lpm=target==lpm['start'],
                      lpm_external_fallback=final_shape,lpm_final_relocations=final_calls)
        c.update(array_calls_lpm=int(target==lpm['start']),lpm_external_frames=int(final_shape),
                 array_fallback_bytes=14 if shape else 0)
    rows.append(record)
result=dict(scope='Retained host-neutral dispatch ranges and bytes, all requests retained. '
    'Static chain shapes are not executed frequencies or installed-byte/per-call measurements. '
    'A missing range does not imply an app has no helper/map work.',source=str(source),
    summary={k:dict(v) for k,v in sorted(summary.items())},requests=rows)
(out/'dispatch.json').write_text(json.dumps(result,indent=2)+'\n')
lines=['app requests both_ranges array_calls_lpm lpm_external_frames array_fallback_bytes']
for app,c in sorted(summary.items()):lines.append(' '.join([app,*[str(c[k]) for k in
  ('requests','both_ranges','array_calls_lpm','lpm_external_frames','array_fallback_bytes')]]))
(out/'summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
