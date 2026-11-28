"""Read exact frozen BCC stats-off/on long-run metrics and installation receipts."""
from pathlib import Path
import collections,hashlib,importlib.util,json,re,statistics,sys,types
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;sha=lambda b:hashlib.sha256(b).hexdigest();m=types.ModuleType('matplotlib');m.use=lambda *a,**k:None;p=types.ModuleType('matplotlib.pyplot');m.pyplot=p;sys.modules['matplotlib']=m;sys.modules['matplotlib.pyplot']=p;spec=importlib.util.spec_from_file_location('frozen_eval',ROOT/'kprog/docs/archive/native_eval_20260529.py');ne=importlib.util.module_from_spec(spec);sys.modules[spec.name]=ne;spec.loader.exec_module(ne)
def src(p):
 b=p.read_bytes();return dict(path=str(p.relative_to(ROOT)),bytes=len(b),sha256=sha(b))
result=dict(newest_resume='COORDINATOR 2026-11-28T11:20Z',scope='Existing3x180s counters/workloads/load receipts only. Stats0 counter zeros are disabled accounting, not zero BPF work. No new guest or source changes.',parser=src(ROOT/'kprog/docs/archive/native_eval_20260529.py'),cases={})
for mode,run in [('off','x86_kvm_corpus_20261128_061040_622818'),('on','x86_kvm_corpus_20261128_085002_496250')]:
 base=ROOT/'corpus/results'/run;ap=base/'details/apps/bcc__set.json';mp=base/'metadata.json';logs=[base/'details/shim-logs'/('bcc__set.'+s+'.log') for s in ['baseline','post_rejit']];inputs=[src(p) for p in [ap,mp]+logs];app=json.loads(ap.read_text());meta=json.loads(mp.read_text());assert app['status']=='ok' and meta['bpf_stats']==(mode=='on') and meta['samples']==3 and meta['workload_seconds']==180
 phases={}
 for phase in ['baseline','post_rejit']:
  samples=ne.phase_samples(app,phase);assert len(samples)==3 and all(s[2]==0 for s in samples);phases[phase]=dict(samples=[dict(total=s[0],by_stressor=s[1],errors=s[2]) for s in samples],median_total=statistics.median(s[0] for s in samples),by_stressor_medians={k:statistics.median(s[1].get(k,0) for s in samples) for k in sorted({k for s in samples for k in s[1]})},bpf_records=app[phase]['bpf'],workload_commands=[w['command'] for w in app[phase]['workloads']])
 last={};records=[]
 for ln,line in enumerate(logs[1].read_text().splitlines(),1):
  a=re.search(r'tid=(\d+)\] native-loader jit-info (original|native) fd=(\d+) id=(\d+) type=(\d+) name=(\S+) tag=(\S+) jited_len=(\d+) xlated_len=(\d+)',line)
  if not a:continue
  tid,kind,fd,pid,typ,name,tag,jit,xlat=a.groups();d=dict(id=int(pid),name=name,tag=tag,jited=int(jit),xlated=int(xlat),line=ln,text=line)
  if kind=='original':last[tid]=d
  elif tid in last and last[tid]['name']==name:records.append(dict(original=last[tid],native=d))
 for p in inputs:assert sha((ROOT/p['path']).read_bytes())==p['sha256']
 result['cases'][mode]=dict(run=str(base.relative_to(ROOT)),inputs=inputs,phases=phases,native_loads=records,throughput_ratio=phases['post_rejit']['median_total']/phases['baseline']['median_total'])
comparison=[]
for mode,c in result['cases'].items():
 e=c['phases']['baseline'];n=c['phases']['post_rejit'];comparison.append(dict(stats=mode,ratio=c['throughput_ratio'],stressor_ratios={k:n['by_stressor_medians'][k]/e['by_stressor_medians'][k] if e['by_stressor_medians'][k] else None for k in e['by_stressor_medians']},component_medians=dict(ebpf=e['by_stressor_medians'],native=n['by_stressor_medians'])))
def identities(c):return collections.Counter((r['native']['name'],r['original']['tag'],r['original']['jited'],r['native']['jited']) for r in c['native_loads'])
a=identities(result['cases']['off']);b=identities(result['cases']['on']);result['native_load_fingerprint_comparison']=dict(off_loads=sum(a.values()),on_loads=sum(b.values()),equal_multiset=a==b,off_only=[dict(fields=list(k),count=v) for k,v in (a-b).items()],on_only=[dict(fields=list(k),count=v) for k,v in (b-a).items()],scope='name, originalBPFtag/JITlength and nativeJITlength only; not actual native-byte, frozen-global or map-binding equality.')
result['component_comparison']=comparison;(OUT/'retained-runs.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(components=comparison,identity=result['native_load_fingerprint_comparison']),indent=2))
