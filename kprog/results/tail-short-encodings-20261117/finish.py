#!/usr/bin/env python3
"""Publish actual tail-encoding results against the immediately preceding fusion replay."""
from collections import Counter,defaultdict
import json
import os
from pathlib import Path
import struct
import sys
raw=Path(sys.argv[1]);out=Path('kprog/results/tail-short-encodings-20261117')
baseline=Path('/workspaces/kprog-raw/perf/map-dispatch-fusion-20261117/current-raw.txt').read_text().strip()
baseline=Path(baseline)/'replay/replay.json'
before={r['capture']:r for r in json.loads(baseline.read_text())['requests']}
after=json.loads((raw/'replay/replay.json').read_text())
summary=defaultdict(Counter);rows=[]
def facts(folder):
    folder=Path(folder);data=(folder/'image.blob').read_bytes()
    records=list(struct.iter_unpack('<IIQ',(folder/'image.relocs').read_bytes()))
    return data,Counter(t for _,k,t in records if k==1),Counter((t,data[o:o+4].hex()) for o,k,t in records if k==10)
for request in after['requests']:
    old=before[request['capture']];c=summary[request['app']]
    row=dict(app=request['app'],symbol=request['symbol'],capture=request['capture'],returncode=request['returncode'],
        before_output=old['output'],after_output=request['output'])
    c.update(requests=1,passed=int(request['returncode']==0),failed=int(request['returncode']!=0))
    if request['returncode'] or old['returncode']:
        row.update(current_error=request.get('error_tail'),baseline_error=old.get('error_tail'))
    else:
        a,ah,ac=facts(old['output']);b,bh,bc=facts(request['output'])
        row.update(before_bytes=len(a),after_bytes=len(b),unchanged=a==b,
            helper_target_multisets_equal=ah==bh,counter_slot_multisets_equal=ac==bc,
            counter_slots=sum(bc.values()))
        c.update(before_bytes=len(a),after_bytes=len(b),changed=int(a!=b),
            helper_target_differences=int(ah!=bh),counter_slot_differences=int(ac!=bc),counter_slots=sum(bc.values()))
    rows.append(row)
j=dict(scope='Actual paired host-neutral emissions after ARRAY/LPM fusion. All requests/errors retained; helper-target '
    'and four-byte counter-slot observations are not a full semantic proof or installed/time measurement.',
    baseline=str(baseline),raw=str(raw),index_errors=after['index_errors'],
    summary={k:dict(v) for k,v in sorted(summary.items())},requests=rows)
(out/'comparison.json').write_text(json.dumps(j,indent=2)+'\n')
parts=[f"{app}: {s['passed']}/{s['requests']} emit, {s.get('before_bytes',0)} -> {s.get('after_bytes',0)} neutral B, {s.get('counter_slots',0)} tail slots, {s.get('counter_slot_differences',0)} counter-slot multiset differences" for app,s in j['summary'].items()]
stamp=os.environ['STAMP'];text=f"\n{stamp} — Tail encoding actual host comparison: "+'; '.join(parts)+". Requests/errors and helper-target observations retained in comparison.json. No installed/per-call/body/helper/map/throughput gain claimed; Omp owns image/check/affected-app timing with all LTO on.\n"
for file in [out/'README.md',Path('kprog/docs/optimizations.md')]:file.write_text(file.read_text()+text)
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a') as f:f.write(f"\n- LANE PERF {stamp}: Tail encoding host replay report completed. "+'; '.join(parts)+". All actual statuses retained; own-path publication follows. Installed/time metrics remain pending, all LTO on.\n")
(out/'comparison-summary.txt').write_text('\n'.join(parts)+'\n');print('\n'.join(parts))
