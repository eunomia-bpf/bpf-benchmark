"""Retain all reported stressor counters for the BCC behavior comparison."""
import csv
import hashlib
import json
from pathlib import Path
import re
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
SHORT=ROOT/'corpus/results/kprog_app_coverage_20261106/bcc-complete-18/workload-counters.json'
RUNS=['x86_kvm_corpus_20261107_060516_326524',
      'x86_kvm_corpus_20261107_051705_921756',
      'x86_kvm_corpus_20261107_054048_802782']
pattern=re.compile(r'metrc:.*?\]\s+(syscall|cap|set|sockfd)\s+(\d+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s')
rows=[];inputs=[];source_runs=[]
def identity(path):
    inputs.append(dict(path=str(path.relative_to(ROOT)),sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
identity(SHORT)
for work in json.loads(SHORT.read_text()):
    for counter in work['counters']:
        rows.append(dict(run='C-short-verified',phase=work['arm'],sample=work['sample'],
            mode='JIT' if work['arm']=='baseline' else 'historical_verified_native_loader',
            workload_seconds=work['duration_s'],returncode=work['returncode'],**counter))
for run in RUNS:
    app_path=ROOT/'corpus/results'/run/'details/apps/bcc__set.json'
    meta_path=ROOT/'corpus/results'/run/'metadata.json'
    identity(app_path);identity(meta_path)
    app=json.loads(app_path.read_text());meta=json.loads(meta_path.read_text())
    source_runs.append(dict(run=run,status=app['status'],error=app['error'],workload_only=meta.get('workload_only',False),post_rejit_present=app['post_rejit'] is not None))
    for phase in ['baseline','post_rejit']:
        if app[phase] is None:continue
        for sample,work in enumerate(app[phase]['workloads']):
            matches=pattern.findall(work['stdout'])
            if len(matches)!=4:raise ValueError('expected the four unfiltered reported stressors')
            mode='no_application_bpf' if meta.get('workload_only') else ('JIT' if phase=='baseline' else app['rejit_result']['mode'])
            if mode=='no_application_bpf':
                if app['rejit_result']['mode']!='workload_only' or app[phase]['bpf']:
                    raise ValueError('workload-only source metadata conflicts with app records')
            for stressor,n,real,user,system in matches:
                rows.append(dict(run=run,phase=phase,sample=sample,mode=mode,
                    workload_seconds=work['duration_s'],returncode=work['returncode'],
                    stressor=stressor,bogo_ops=int(n),real_seconds=float(real),
                    user_seconds=float(user),system_seconds=float(system)))
fields=['run','phase','sample','mode','workload_seconds','returncode','stressor','bogo_ops','real_seconds','user_seconds','system_seconds']
with (HERE/'counters.csv').open('w',newline='') as output:
    writer=csv.DictWriter(output,fieldnames=fields,lineterminator=chr(10));writer.writeheader();writer.writerows(rows)
summary=dict(input_records=len(rows),inputs=inputs,source_runs=source_runs,
    short_syscall=[r for r in rows if r['run']=='C-short-verified' and r['stressor']=='syscall'],
    no_bpf_syscall=[r for r in rows if r['mode']=='no_application_bpf' and r['stressor']=='syscall'],
    conclusion='Both 8434 and 514 occur in the same workload-only no-app-BPF run. Their short-arm difference alone does not establish a native-induced behavior regression. Same-work and the blocking/calibration mechanism remain to be measured on the new trusted application path.')
(HERE/'summary.json').write_text(json.dumps(summary,indent=2)+chr(10))
print('retained',len(rows),'reported stressor rows')
