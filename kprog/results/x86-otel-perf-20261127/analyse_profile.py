"""Resolve phase-specific PMU samples, periods, and actual entry counters."""
import bisect,collections,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
out=Path(sys.argv[1]) if len(sys.argv)>1 else Path(json.loads((LANE/'otel-performance-profile.json').read_text())['result'])
controller=json.loads((out/'controller.json').read_text());assert controller['controller_status']==0
raw=Path(controller['raw']);run=Path(controller['run_dir']);app=json.loads((run/'details/apps/otelcol-ebpf-profiler__profiling.json').read_text());assert app['status']=='ok'
grt,gup=map(float,(raw/'clock.txt').read_text().split());hoff=float((raw/'host-rt-minus-uptime.txt').read_text())
boot={}
for line in (raw/'kallsyms.txt').read_text().splitlines():
 a,t,n,*_=line.split()
 if t in 'tTwW':boot[int(a,16)]=n
windows={};tables={};counters={}
for ph in ['baseline','post_rejit']:
 log=(run/('details/shim-logs/otelcol-ebpf-profiler__profiling.'+ph+'.log')).read_text()
 start=float(re.search(r'^\[([\d.]+) .*cmd=measure_start',log,re.M)[1]);end=float(re.search(r'^\[([\d.]+) .*cmd=measure_finish',log,re.M)[1]);windows[ph]=(start,end)
 snaps=[(float(p.name[len('kallsyms-bpf-'):-4]),p) for p in raw.glob('kallsyms-bpf-*.txt')];inside=[x for x in snaps if start<=x[0]<end];assert inside
 _,snapshot=min(inside,key=lambda x:abs(x[0]-(start+end)/2));syms=dict(boot)
 for line in snapshot.read_text().splitlines():
  a,t,n,*_=line.split();syms[int(a,16)]=n
 tables[ph]=(syms,sorted(syms),str(snapshot.relative_to(raw)))
 entries=[(k,v) for k,v in app[ph]['bpf'].items() if v.get('name')=='native_tracer_e'];assert len(entries)==1
 k,v=entries[0];counters[ph]=dict(prog_id=k,calls=v['run_cnt_delta'],runtime_ns=v['run_time_ns_delta'],ns_per_call=v['run_time_ns_delta']/v['run_cnt_delta'])
def resolve(ph,ip):
 syms,keys,_=tables[ph];at=bisect.bisect_right(keys,ip)-1
 if ip<0xffff800000000000:return '[guest-user]',0
 return (syms[keys[at]],ip-keys[at]) if at>=0 else ('[unknown]',0)
pattern=re.compile(r'^\d+ (\d+) \S+ \[\S+\]: PERF_RECORD_SAMPLE\(IP, 0x([45])\): (\d+)/(\d+): 0x([0-9a-f]+) period: (\d+)')
samples=collections.defaultdict(collections.Counter);periods=collections.defaultdict(collections.Counter);own=collections.Counter();hot=collections.defaultdict(collections.Counter);total=0
p=subprocess.Popen(['/workspaces/.agent-state/kprog-ck/perf-tool/perf','report','-D','-i',str(raw/'host-perf.data')],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
for line in p.stdout:
 m=pattern.match(line)
 if not m:continue
 total+=1;t=int(m[1])/1e9+hoff-grt+gup;pid=int(m[3]);ip=int(m[5],16);period=int(m[6])
 for ph,(a,b) in windows.items():
  if not a<=t<b:continue
  name,offset=resolve(ph,ip);samples[ph,pid][name]+=1;periods[ph,pid][name]+=period
  if name in ['trie_lookup_elem','copy_from_user_nofault','array_map_lookup_elem']:own[ph,pid]+=1;hot[ph,pid,name][offset]+=period
assert p.wait()==0
pids={ph:max((pid for key,pid in own if key==ph),key=lambda pid:own[ph,pid]) for ph in windows};assert len(set(pids.values()))==1,pids
result=dict(scope='Actual completed10s diagnostic, phase-specific nearest in-phase symbols, own QEMU selected by boot-kernel helper samples. Sample period sums are PMU cycle estimates with skid/multiplexing limits; no exact per-call kernel time or workload identity claim.',controller_status=0,total_guest_samples=total,own_qemu_pid=pids['baseline'],image=controller['profile-image.txt'],source=controller['profile-source.txt'],windows=windows,entry_counters=counters,entry_per_call_speedup=counters['baseline']['ns_per_call']/counters['post_rejit']['ns_per_call'],phases={})
for ph,(a,b) in windows.items():
 pid=pids[ph];cs=samples[ph,pid];ps=periods[ph,pid]
 result['phases'][ph]=dict(snapshot=tables[ph][2],duration=b-a,pid_samples={str(k[1]):sum(v.values()) for k,v in samples.items() if k[0]==ph},sample_count=sum(cs.values()),period_sum=sum(ps.values()),symbols={n:dict(samples=cs[n],samples_per_second=cs[n]/(b-a),period_sum=ps[n],period_per_entry_call=ps[n]/counters[ph]['calls']) for n in cs},hot_offsets={n:dict(hot[ph,pid,n].most_common(30)) for n in ['trie_lookup_elem','copy_from_user_nofault','array_map_lookup_elem']})
(out/'pmu-analysis.json').write_text(json.dumps(result,indent=2)+'\n')
names=set(result['phases']['baseline']['symbols'])|set(result['phases']['post_rejit']['symbols'])
def metric(ph,n):return result['phases'][ph]['symbols'].get(n,{}).get('period_per_entry_call',0)
rows=sorted(names,key=lambda n:metric('post_rejit',n)-metric('baseline',n),reverse=True)
with (out/'pmu-symbol-deltas.tsv').open('w') as f:
 f.write('symbol\tbaseline_samples\tnative_samples\tbaseline_period_per_entry_call\tnative_period_per_entry_call\tdelta\n')
 for n in rows:
  e=result['phases']['baseline']['symbols'].get(n,{});v=result['phases']['post_rejit']['symbols'].get(n,{})
  f.write('\t'.join(map(str,[n,e.get('samples',0),v.get('samples',0),metric('baseline',n),metric('post_rejit',n),metric('post_rejit',n)-metric('baseline',n)]))+'\n')
print(json.dumps(dict(own_pid=pids,speedup=result['entry_per_call_speedup'],entry_counters=counters,largest_positive=[(n,metric('baseline',n),metric('post_rejit',n)) for n in rows[:12]])),flush=True)
