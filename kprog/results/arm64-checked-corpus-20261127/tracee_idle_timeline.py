"""Locate Tracee measurement relative to actual raw tracepoint attachment."""
import ast
import gzip
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();token=now.replace('-','').replace(':','');OUT=HERE/('tracee-idle-'+token);OUT.mkdir()
archive=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T140827Z/tracee-monitor/corpus.tar.gz');controller=json.loads((HERE/'guest-20261127T140827Z/controller.json').read_text())
record=dict(utc=now,input_archive=str(archive),input_archive_sha256=hashlib.sha256(archive.read_bytes()).hexdigest(),guest_start_revision=controller['guest_start_revision'],scope='Read-only archived guest timing diagnosis; no new guest, compiler, framework/settings/readiness or production change.',phases={},evidence_files={})
files={}
with tarfile.open(archive) as t:
 for m in t:
  if m.isfile() and m.name.endswith(('details/apps/tracee__monitor.json','details/result.json','tracee__monitor.baseline.log','tracee__monitor.post_rejit.log')):
   data=t.extractfile(m).read();files[Path(m.name).name]=data;packed=gzip.compress(data,mtime=0);dest=OUT/(Path(m.name).name+'.gz');dest.write_bytes(packed);record['evidence_files'][dest.name]=dict(original_member=m.name,original_bytes=len(data),original_sha256=hashlib.sha256(data).hexdigest(),gzip_sha256=hashlib.sha256(packed).hexdigest())
app=json.loads(files['tracee__monitor.json']);result=json.loads(files['result.json']);record['frozen_sample']=dict(samples=result['samples'],warmups=result['warmups'],workload_seconds=result['workload_seconds'],bpf_stats=result['bpf_stats'],app_status=app['status'])
timeline=[]
for phase in ['baseline','post_rejit']:
 lines=files['tracee__monitor.'+phase+'.log'].decode().splitlines();events=[]
 for number,line in enumerate(lines,1):
  m=re.match(r'\[([0-9.]+) pid=(\d+) tid=(\d+)\] (.*)',line)
  if not m:continue
  seconds=float(m[1]);text=m[4]
  if any(k in text for k in ['cmd=measure_','cmd=list_progs','cmd=has_programs','BPF_RAW_TRACEPOINT_OPEN name=']):
   event=dict(phase=phase,guest_seconds=seconds,line=number,pid=int(m[2]),tid=int(m[3]),text=text);events.append(event);timeline.append(event)
 measured=app[phase]['bpf'];starts=[x for x in events if 'cmd=measure_start' in x['text']];finishes=[x for x in events if 'cmd=measure_finish' in x['text']];raw=[x for x in events if 'BPF_RAW_TRACEPOINT_OPEN name=' in x['text']]
 assert len(starts)==len(finishes)==1
 row=dict(measurement_start_request=starts[0],measurement_finish_request=finishes[0],socket_command_interval_seconds=finishes[0]['guest_seconds']-starts[0]['guest_seconds'],last_startup_program_query=next(x for x in reversed(events) if 'cmd=list_progs' in x['text'] and x['guest_seconds']<starts[0]['guest_seconds']),raw_tracepoint_open_count=len(raw),first_raw_tracepoint_open=raw[0] if raw else None,syscall_raw_opens=[x for x in raw if re.search(r'name=sys_(enter|exit)\b',x['text'])],observed_programs=len(measured),active_programs=sum(int(p['run_cnt_delta'])>0 for p in measured.values()),total_observed_calls=sum(int(p['run_cnt_delta']) for p in measured.values()),workloads=[{k:w[k] for k in ['workload_name','command','duration_s','returncode']} for w in app[phase]['workloads']])
 row['all_raw_attachments_after_measurement_finish']=all(x['guest_seconds']>finishes[0]['guest_seconds'] for x in raw) if raw else None;record['phases'][phase]=row
assert record['phases']['baseline']['all_raw_attachments_after_measurement_finish'] and record['phases']['post_rejit']['raw_tracepoint_open_count']==0
source_paths={'runner/libs/app_runners/tracee.py':{'__enter__','start','_tracee_collector_has_activity'},'runner/libs/rejit.py':{'app_shim_has_programs','wait_for_app_shim_programs','measure_app_phase'}}
snippets=[];record['framework_source']={}
for path,names in source_paths.items():
 data=subprocess.check_output(['git','show',record['guest_start_revision']+':'+path],cwd=ROOT);working=(ROOT/path).read_bytes();assert data==working,'Frozen framework source drift'
 text=data.decode();lines=text.splitlines();nodes=[n for n in ast.walk(ast.parse(text)) if isinstance(n,(ast.FunctionDef,ast.AsyncFunctionDef)) and n.name in names];record['framework_source'][path]=dict(sha256=hashlib.sha256(data).hexdigest(),matches_current_working=True,functions=[dict(name=n.name,line=n.lineno,end_line=n.end_lineno) for n in nodes])
 for n in sorted(nodes,key=lambda n:n.lineno):snippets.append(path+':'+str(n.lineno)+'\n'+'\n'.join(lines[n.lineno-1:n.end_lineno]))
(OUT/'framework-source.txt').write_text('\n\n'.join(snippets)+'\n')
record['diagnosis']='Baseline measured before all raw-tracepoint attachment, not merely a quiet attached filter. Startup readiness accepts healthz OR any output plus tracked programs; it then accepts a stable program-list gap and sleeps the unchanged5seconds. On slow guest init this precedes actual syscall attachment. Post phase also measured during loading and records no raw-tracepoint attachment before its later native failure. A successful stressor return does not establish exercised Tracee programs.'
record['limits']='Socket timestamps mark command entry, not an independently instrumented internal stats boundary. Full logs and successful raw-open returns are preserved. Only startup ordering is established; exact healthz/output OR branch is not logged. No Spark-host startup-order equivalence or repair validated. Frozen framework/readiness/settle/workload/900s remain unchanged.'
record['controller_status']=0;(OUT/'diagnosis.json').write_text(json.dumps(record,indent=2)+'\n')
with (OUT/'timeline.tsv').open('w') as f:
 f.write('phase\tguest_seconds\tline\tpid\ttid\tevent\n')
 for row in timeline:f.write('\t'.join(str(row[k]) for k in ['phase','guest_seconds','line','pid','tid','text'])+'\n')
(LANE/'tracee-idle-diagnosis.json').write_text(json.dumps(dict(result=str(OUT)),indent=2)+'\n');print(json.dumps(dict(result=str(OUT),baseline_start=record['phases']['baseline']['measurement_start_request']['guest_seconds'],baseline_finish=record['phases']['baseline']['measurement_finish_request']['guest_seconds'],first_raw_attach=record['phases']['baseline']['first_raw_tracepoint_open']['guest_seconds'],post_raw_opens=record['phases']['post_rejit']['raw_tracepoint_open_count'],evidence_files=len(record['evidence_files']))),flush=True)
