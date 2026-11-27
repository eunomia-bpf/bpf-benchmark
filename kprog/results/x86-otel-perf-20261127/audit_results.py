"""Inventory available corpus measurements without mixing diagnostic and timing cohorts."""
import collections,hashlib,importlib.util,json,os,statistics,subprocess,sys,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
stamp=now();refresh='--complete-current' in sys.argv;out=Path(json.loads((LANE/'performance-data-audit.json').read_text())['result']) if refresh else HERE/('data-audit-'+stamp.replace('-','').replace(':',''));out.mkdir(exist_ok=refresh)
record=dict(pid=os.getpid(),started_utc=stamp,controller_status=None,scope='All available canonical corpus/result metadata plus retained Spark5-8 raw roots. Inventory, not all historical archives decoded or a causal attribution. Source/image missingness and invalid/error runs remain explicit; full3x180 timing and10s diagnostics stay separate.')
def save():(out/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
(LANE/'performance-data-audit.json').write_text(json.dumps(dict(result=str(out),pid=os.getpid()),indent=2)+'\n')
try:
 save();spec=importlib.util.spec_from_file_location('ratio',ROOT/'kprog/results/flag-tuning-20261117/may29_ratio.py');ratio=importlib.util.module_from_spec(spec);sys.argv=[sys.argv[0]];spec.loader.exec_module(ratio)
 roots=[ROOT/'corpus/results',*[Path('/workspaces/kprog-raw')/('arm64-spark-run'+str(i)) for i in range(5,9)]]
 paths=[];seen=set()
 for base in roots:
  if not base.exists():continue
  candidates=base.glob('*_corpus_*/metadata.json') if base==roots[0] else base.rglob('metadata.json')
  for p in candidates:
   if '_corpus_' not in p.parent.name:continue
   if str(p.resolve()) not in seen:paths.append(p);seen.add(str(p.resolve()))
 record['metadata_paths']=len(paths);record['roots']=[str(p) for p in roots];save();rows=[]
 canonical_missing=[str(p) for p in roots[0].glob('*_corpus_*') if p.is_dir() and not (p/'metadata.json').exists()]
 record['canonical_directories_without_metadata']=len(canonical_missing);save()
 (out/'directories-without-metadata.json').write_text(json.dumps(canonical_missing,indent=2)+'\n')
 for p in sorted(paths):
  base=dict(path=str(p.parent),run=p.parent.name)
  try:
   meta=json.loads(p.read_text());details=p.parent/meta.get('details_dir','details');result_path=details/'result.json';res=json.loads(result_path.read_text()) if result_path.exists() else {}
   base.update(started_at=meta.get('started_at'),samples=meta.get('samples',res.get('samples')),seconds=meta.get('workload_seconds',res.get('workload_seconds')),stats=meta.get('bpf_stats',res.get('bpf_stats')),status=meta.get('status'),result_status=res.get('status'),image=meta.get('image',meta.get('runtime_image')),source_commit=meta.get('git_commit',meta.get('revision')),backend=meta.get('run_type',p.parent.name.split('_corpus_',1)[0]),metadata_sha256=hashlib.sha256(p.read_bytes()).hexdigest())
   base['cohort']='full3x180' if base['samples']==3 and base['seconds']==180 else 'check1x10' if base['samples']==1 and base['seconds']==10 else 'other'
   base['guest_clock_is_epoch']=str(base['started_at']).startswith('1970-')
   for i in range(5,9):
    if '/arm64-spark-run'+str(i)+'/' in str(p):
     base['documented_batch']='Spark run'+str(i);base['batch_readme']='kprog/results/arm64-spark-run'+str(i)+'-'+('20261123' if i==5 else '20261124' if i in [6,7] else '20261126')+'/README.md'
   files=sorted((details/'apps').glob('*.json'));base['app_files']=len(files)
   if not files:rows.append(dict(base,inventory_error='No app JSON remains at this metadata path'));continue
   for f in files:
    row=dict(base,app_file=str(f))
    try:
     app=json.loads(f.read_text());row.update(app=app.get('app',f.stem.replace('__','/')),app_status=app.get('status'),error=app.get('error'),app_sha256=hashlib.sha256(f.read_bytes()).hexdigest())
     row['phases']={ph:None if app.get(ph) is None else dict(programs=len(app[ph]['bpf']),active=sum(v['run_cnt_delta']>0 for v in app[ph]['bpf'].values())) for ph in ['baseline','post_rejit']}
     try:
      a,b=ratio.ne.bpf_aggregate(app,'baseline'),ratio.ne.bpf_aggregate(app,'post_rejit');row.update(ebpf_ns=a[0],native_ns=b[0],per_call_ratio=a[0]/b[0] if a[0] and b[0] else None)
     except Exception as e:row['ns_error']=str(e)
     try:
      es,ns=ratio.ne.phase_samples(app,'baseline'),ratio.ne.phase_samples(app,'post_rejit');e=[v[0] for v in es];n=[v[0] for v in ns]
      value=statistics.median(n)/statistics.median(e);row.update(throughput_ratio=value,ebpf_samples=e,native_samples=n,throughput_sample_ratios=[n[i]/e[i] for i in range(min(len(e),len(n)))],workload_errors=sum(v[2] for v in es+ns))
     except Exception as e:row['throughput_error']=str(e)
     if row.get('image') is None:row['provenance_note']='Inspected top-level image fields are absent; join batch README/launcher/nested provenance. Do not infer image from run date.'
    except Exception:row['inventory_error']=traceback.format_exc()
    rows.append(row)
  except Exception:rows.append(dict(base,inventory_error=traceback.format_exc()))
 summary=dict(metadata_paths=len(paths),directories_without_metadata=len(canonical_missing),rows=len(rows),cohorts=dict(collections.Counter((str(r.get('backend')),r.get('cohort'),str(r.get('stats'))) for r in rows)),inventory_errors=sum('inventory_error' in r for r in rows),missing_image=sum(not r.get('image') for r in rows),missing_commit=sum(not r.get('source_commit') for r in rows))
 # Tuple keys are formatted explicitly for JSON, preserving each cohort.
 summary['cohorts']={str(k):v for k,v in summary['cohorts'].items()}
 (out/'inventory.json').write_text(json.dumps(dict(scope=record['scope'],summary=summary,runs=rows),indent=2)+'\n')
 cols=['run','documented_batch','guest_clock_is_epoch','backend','cohort','stats','app','app_status','ebpf_ns','native_ns','per_call_ratio','throughput_ratio','workload_errors','image','source_commit','path']
 with (out/'inventory.tsv').open('w') as f:
  f.write('\t'.join(cols)+'\n')
  for r in rows:f.write('\t'.join(str(r.get(k,'')) for k in cols)+'\n')
 record.update(controller_status=0,summary=summary)
except Exception:record.update(controller_status=1,exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nPerformance all-available-data inventory ended status '+str(record['controller_status'])+'. Read '+str(out/'controller.json')+'/inventory.json/tsv; join missing image/commit to recorded batch provenance and semantic-validity notes before trend or causal claims.\n')
 print(json.dumps(record),flush=True)
raise SystemExit(record['controller_status'])
