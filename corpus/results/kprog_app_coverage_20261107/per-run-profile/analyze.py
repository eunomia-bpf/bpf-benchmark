"""Report inclusive guest-only counters separately from actual BPF runtime stats."""
import bisect,collections,json,re,sys
from pathlib import Path
out=Path(sys.argv[1]);summary=[];checks=[]
for ready in sorted(out.glob('ready-*.json')):
 meta=json.loads(ready.read_text());p=Path(meta['prefix']);done=out/f"done-{meta['index']:03d}.json"
 if not done.exists():raise RuntimeError('unfinished window '+str(p))
 result=json.loads(done.read_text());work=result.get('result',{});deltas=json.loads((p/'program-deltas.json').read_text())
 row={k:meta[k] for k in ['app','arm','scenario','kind','count']};row['directory']=str(p);row['work']=work
 row['bpf']=[dict(id=x['before']['id'],source_btf_symbol=x['before'].get('source_btf_symbol'),run_count=x['run_count'],ns_per_run=x['run_time_ns']/x['run_count'] if x['run_count'] else None) for x in deltas]
 if meta['app']=='tetragon' and sum(x['run_count'] for x in deltas)<=0:raise RuntimeError('fixed work did not invoke generic_kprobe_event')
 if not result['ok']:raise RuntimeError(result)
 if work.get('count')!=meta['count']:raise RuntimeError('work count mismatch')
 if meta['app']=='katran' and work.get('retval')!=3:raise RuntimeError('not the intended VIP-hit XDP_TX path')
 if meta['kind']=='stat':
  values={};unsupported=[]
  for line in (p/'perf-stat.csv').read_text().splitlines():
   if line.startswith('#') or not line.strip():continue
   f=line.split(';')
   if len(f)<3:continue
   if f[0].strip().startswith('<'):unsupported.append(line);continue
   try:values[f[2]]=float(f[0].replace(',',''))/meta['count']
   except ValueError:continue
  row['guest_roi_events_per_input']=values;row['unsupported_events']=unsupported
  if unsupported or len(values)!=5 or not all(v>0 for k,v in values.items() if 'cycles' in k or 'instructions' in k):raise RuntimeError('hardware count validation failed '+str(p))
 else:
  symbols=[]
  for line in (p/'kallsyms.txt').read_text().splitlines():
   f=line.split()
   if len(f)>=3:
    try:a=int(f[0],16)
    except ValueError:continue
    if a:symbols.append((a,f[2]))
  symbols.sort();addresses=[a for a,n in symbols];hist=collections.Counter();regions=collections.Counter();sample_ips=collections.Counter()
  for line in (p/'samples.txt').read_text().splitlines():
   f=line.strip().split()
   if not f:continue
   try:ip=int(f[0],16)
   except ValueError:continue
   if not ip:continue
   sample_ips[ip]+=1;idx=bisect.bisect_right(addresses,ip)-1
   name=symbols[idx][1] if idx>=0 and ip-addresses[idx]<1<<24 else '[guest-user-or-unknown]';hist[name]+=1
   if name.startswith('bpf_prog_'):region='BPF/JIT code'
   elif 'lookup' in name or 'htab' in name or 'lru' in name:region='map/hash/LRU kernel code'
   elif 'tail_call' in name:region='tail-call kernel code'
   elif 'bpf_test' in name or 'bpf_prog_run' in name:region='test-run/dispatch kernel code'
   else:region='other kernel/user/measurement code'
   regions[region]+=1
  row['samples']=sum(hist.values());row['sample_regions']=dict(regions);row['top_symbols']=hist.most_common(25);row['top_ips']=[dict(ip=hex(ip),samples=n) for ip,n in sample_ips.most_common(30)]
  if not row['samples']:raise RuntimeError('no actual guest samples '+str(p))
 summary.append(row)
# Byte-identical transformed packet/action is required across arms for each scenario.
for scenario in {r['scenario'] for r in summary if r['app']=='katran'}:
 vals={(r['work']['retval'],r['work']['output_size'],r['work']['output_fnv64']) for r in summary if r['app']=='katran' and r['scenario']==scenario}
 if len(vals)!=1:raise RuntimeError('JIT/native packet or action mismatch '+scenario)
 checks.append(scenario+': exact action/packet hash agree')
(out/'summary.json').write_text(json.dumps(dict(checks=checks,windows=summary),indent=2)+'\n')
print(json.dumps(dict(checks=checks,windows=len(summary)),indent=2))
