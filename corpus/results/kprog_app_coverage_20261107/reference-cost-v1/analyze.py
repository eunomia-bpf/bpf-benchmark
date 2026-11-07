"""Localize historical Tetragon cost by observed name/type/code-size families."""
import collections,csv,hashlib,json,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3]
RUNS=['x86_kvm_corpus_20260529_045551_393389','x86_kvm_corpus_20261107_002003_274609']
raw=[];groups=[];inputs=[]
for run in RUNS:
 p=ROOT/'corpus/results'/run/'details/apps/tetragon__observer.json';app=json.loads(p.read_text());inputs.append(dict(path=str(p.relative_to(ROOT)),sha256=hashlib.sha256(p.read_bytes()).hexdigest(),status=app['status'],mode=app['rejit_result']))
 for phase in ['baseline','post_rejit']:
  buckets=collections.defaultdict(lambda:[0,0,0])
  for rec in app[phase]['bpf'].values():
   row=dict(run=run,phase=phase,**rec);n=rec['run_cnt_delta'];t=rec['run_time_ns_delta'];row['ns_per_run']=t/n if n else None;raw.append(row)
   if n>=100:
    key=(rec['name'],rec['type'],rec['bytes_jited'],rec['bytes_xlated']);v=buckets[key];v[0]+=1;v[1]+=n;v[2]+=t
  for key,(count,runs,elapsed) in buckets.items():groups.append(dict(run=run,phase=phase,name=key[0],type=key[1],bytes_jited=key[2],bytes_xlated=key[3],records=count,runs=runs,time_ns=elapsed,ns_per_run=elapsed/runs))
fields=['run','phase','id','name','type','bytes_jited','bytes_xlated','run_cnt_delta','run_time_ns_delta','ns_per_run']
with (HERE/'all-program-records.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=fields,lineterminator=chr(10));w.writeheader();w.writerows(raw)
(HERE/'families.json').write_text(json.dumps(groups,indent=2)+chr(10))
commit=subprocess.check_output(['git','rev-parse','9f3855f6f'],cwd=ROOT,text=True).strip();oldpath='native-sim/x86/native_lab/native_link/src/x86.rs';text=subprocess.check_output(['git','show',commit+':'+oldpath],cwd=ROOT,text=True);a=text.index('fn select_lookup_site(');b=text.index('\npub(',a)
# Historical source stays in Git; keep its identity instead of another active copy.
(HERE/'inputs.json').write_text(json.dumps(dict(inputs=inputs,grouping_rule='Existing archived analysis uses run_cnt_delta>=100 for its summary; raw CSV retains every record.',nearby_source=dict(commit=commit,path=oldpath,sha256=hashlib.sha256(text.encode()).hexdigest(),pinned_to_measured_image=False)),indent=2)+chr(10))
print('raw_records',len(raw),'families',len(groups))
