"""Derived per-run observations; original counters remain in the raw archives."""
import bisect,collections,csv,json
from pathlib import Path
H=Path(__file__).resolve().parent
RUNS=['run-baseline-20261107T055424Z','run-tables-20261107T055854Z']
rows=[];cache=[];profiles=[]
for run in RUNS:
 data=json.loads((H/run/'summary.json').read_text())
 for w in data['windows']:
  p=Path(w['directory']);primary=max(w['bpf'],key=lambda b:b['run_count'])
  if w['kind']=='stat':
   r=dict(run=run,app=w['app'],arm=w['arm'],scenario=w['scenario'],inputs=w['count'],primary_id=primary['id'],primary_run_count=primary['run_count'],primary_ns_per_run=primary['ns_per_run'])
   r.update(w['guest_roi_events_per_input']);rows.append(r)
   if w['app']=='katran':
    snapshots=[]
    for side in ['before','after']:
     x=json.loads((p/('map-stats-'+side+'.json')).read_text());mid=str(next(m['id'] for m in x['maps'] if m['name']=='stats'))
     snapshots.append({v['formatted']['key']:{z['cpu']:z['value'] for z in v['formatted']['values']} for v in x['values'][mid]})
    for key in [0,512,513,515]:
     for cpu,value in snapshots[0][key].items():
      cache.append(dict(run=run,arm=w['arm'],scenario=w['scenario'],key=key,cpu=cpu,v1_delta=snapshots[1][key][cpu]['v1']-value['v1'],v2_delta=snapshots[1][key][cpu]['v2']-value['v2']))
  else:
   info=json.loads(json.loads((p/(str(primary['id'])+'.jit-dump.json')).read_text())['stdout']);base=int(info['jited_addr'],16);size=info['first_jited_func_len']
   symbols=[]
   for line in (p/'kallsyms.txt').read_text().splitlines():
    f=line.split()
    if len(f)>=3 and int(f[0],16):symbols.append((int(f[0],16),f[2]))
   symbols.sort();addresses=[a for a,n in symbols];hist=collections.Counter();spans=collections.Counter()
   for line in (p/'samples.txt').read_text().splitlines():
    f=line.split()
    if not f:continue
    try:ip=int(f[0],16)
    except ValueError:continue
    if base<=ip<base+size:spans['primary loaded code']+=1
    idx=bisect.bisect_right(addresses,ip)-1
    name=symbols[idx][1] if idx>=0 and ip-addresses[idx]<(1<<24) else '[guest-user-or-unknown]';hist[name]+=1
   profiles.append(dict(run=run,app=w['app'],arm=w['arm'],scenario=w['scenario'],primary=primary,primary_jit=info,span_samples=dict(spans),sample_count=sum(hist.values()),symbols=hist.most_common()))
for file,data in [('ready2m-counters.csv',rows),('ready2m-cache-work.csv',cache)]:
 with (H/file).open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(data[0]),lineterminator=chr(10));w.writeheader();w.writerows(data)
(H/'ready2m-profiles.json').write_text(json.dumps(profiles,indent=2)+chr(10))
