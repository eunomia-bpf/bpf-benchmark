"""Read retained long-run counters/install receipts; no timing or source changes."""
from pathlib import Path
import collections,hashlib,json,re,subprocess
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
sha=lambda b:hashlib.sha256(b).hexdigest()
def source(p):
 b=p.read_bytes();return dict(path=str(p.relative_to(ROOT)),bytes=len(b),sha256=sha(b))
result=dict(newest_resume='COORDINATOR 2026-11-28T11:20Z',scope='Retained counters and actual install receipts. IDs matched only within each run; no identity pairing by ID, truncated name, load order or fd across runs.',cases={},causal_status='OPEN: counters localize the increment; original installed native bytes/link plans for the11-23 run are not located, so skipped-work or call-target cause is not proven.')
for label,run in [('old','x86_kvm_corpus_20261123_120320_002937'),('current','x86_kvm_corpus_20261128_094333_560478')]:
 base=ROOT/'corpus/results'/run;appfile=base/'details/apps/tetragon__observer.json';log=base/'details/shim-logs/tetragon__observer.post_rejit.log';meta=base/'metadata.json';inputs=[source(p) for p in [appfile,log,meta]];app=json.loads(appfile.read_text());m=json.loads(meta.read_text());assert app['status']=='ok' and m['bpf_stats'] and m['samples']==3 and m['workload_seconds']==180
 last={};lookup={}
 for lineno,line in enumerate(log.read_text().splitlines(),1):
  a=re.search(r'tid=(\d+)\] native-loader jit-info (original|native) fd=(\d+) id=(\d+) type=(\d+) name=(\S+) tag=(\S+) jited_len=(\d+) xlated_len=(\d+)',line)
  if not a:continue
  tid,kind,fd,pid,typ,name,tag,jit,xlat=a.groups();d=dict(id=int(pid),fd=int(fd),type=int(typ),name=name,tag=tag,jited=int(jit),xlated=int(xlat),line=lineno,text=line)
  if kind=='original':last[tid]=d
  elif tid in last and last[tid]['name']==name:
   assert pid not in lookup;lookup[pid]=dict(native=d,original=last[tid],join='Same loader thread adjacent original/native receipt; native ID/name/JIT length validated against per-run record')
 phases={}
 for phase in ['baseline','post_rejit']:
  records=app[phase]['bpf'];retained={k:v for k,v in records.items() if v['run_cnt_delta']>=100};calls=sum(v['run_cnt_delta'] for v in retained.values());elapsed=sum(v['run_time_ns_delta'] for v in retained.values());groups=collections.defaultdict(list);rows=[]
  for pid,v in retained.items():
   row=dict(program_id=pid,**v,ns_per_call=v['run_time_ns_delta']/v['run_cnt_delta'],aggregate_contribution_ns=v['run_time_ns_delta']/calls,call_fraction=v['run_cnt_delta']/calls)
   if phase=='post_rejit':
    receipt=lookup[pid];assert receipt['native']['name']==v['name'] and receipt['native']['jited']==v['bytes_jited'];row['install_receipt']=receipt;key=v['name']+':original_jited='+str(receipt['original']['jited'])
   else:key=v['name']+':jited='+str(v['bytes_jited'])
   row['bucket']=key;groups[key].append(row);rows.append(row)
  buckets={}
  for k,rr in groups.items():
   n=sum(z['run_cnt_delta'] for z in rr);t=sum(z['run_time_ns_delta'] for z in rr);buckets[k]=dict(programs=len(rr),calls=n,run_time_ns=t,call_fraction=n/calls,ns_per_call=t/n,aggregate_contribution_ns=t/calls,installed_bytes=sorted(set(z['bytes_jited'] for z in rr)),original_tags=sorted(set(z['install_receipt']['original']['tag'] for z in rr)) if phase=='post_rejit' else [])
  phases[phase]=dict(calls=calls,run_time_ns=elapsed,ns_per_call=elapsed/calls,programs=len(records),positive_programs=sum(v['run_cnt_delta']>0 for v in records.values()),retained_programs=len(retained),retained_rule='run_cnt_delta>=100 (frozen05-29 parser)',buckets=buckets,records=sorted(rows,key=lambda r:r['run_time_ns_delta'],reverse=True))
 for inp in inputs:assert sha((ROOT/inp['path']).read_bytes())==inp['sha256']
 result['cases'][label]=dict(run=str(base.relative_to(ROOT)),inputs=inputs,phases=phases)
a=result['cases']['old']['phases']['post_rejit'];b=result['cases']['current']['phases']['post_rejit'];assert set(a['buckets'])==set(b['buckets']);deltas=[]
for key in a['buckets']:
 x=a['buckets'][key];y=b['buckets'][key];d=y['aggregate_contribution_ns']-x['aggregate_contribution_ns'];cost=(y['ns_per_call']-x['ns_per_call'])*(x['call_fraction']+y['call_fraction'])/2;mix=(y['call_fraction']-x['call_fraction'])*(x['ns_per_call']+y['ns_per_call'])/2;assert abs(d-cost-mix)<1e-8;deltas.append(dict(bucket=key,contribution_delta_ns=d,symmetric_cost_term_ns=cost,symmetric_mix_term_ns=mix))
result['native_delta_ns']=b['ns_per_call']-a['ns_per_call'];result['bucket_deltas']=sorted(deltas,key=lambda r:r['contribution_delta_ns'],reverse=True);assert abs(sum(x['contribution_delta_ns'] for x in deltas)-result['native_delta_ns'])<1e-8
result['limits']=['Bucket contributions are exact accounting, not cause. Same original BPF tag does not prove same native body, attach target, map values or dynamic work.','Native generic_kprobe 1329->1401 bytes and original tag93c5f592a9cdde6a/JIT1879 are actual receipts, but neither code length nor source-history dates bind native instruction content.','Existing same-image03:56 check archive has canonical generic_kprobe_event blobs/plans; reuse them for current-body analysis. They are not an installed-code capture from either long run.','Do not restore historical short paths or change flags until equal-work and actual branch/helper/map/tail-call targets explain the difference. OTel2689 hold remains.']
(OUT/'comparison.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(delta=result['native_delta_ns'],buckets=result['bucket_deltas']),indent=2))
