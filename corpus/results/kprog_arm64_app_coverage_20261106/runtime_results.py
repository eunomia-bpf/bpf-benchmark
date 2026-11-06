"""Preserve every real startup load and each app's raw phase counters/errors."""
from collections import Counter
import csv
import json
from pathlib import Path
import re
import shutil
import tarfile

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
out=HERE/'runtime-context-v2';out.mkdir(exist_ok=True)
runs=['arm64_qemu_corpus_19700101_000006_311551','arm64_qemu_corpus_19700101_000010_879201']
loads=[];apps=[]
for name in runs:
    run=ROOT/'corpus/results'/name
    for log in sorted((run/'details/shim-logs').glob('*.log')):
        pending={}
        for line in log.read_text().splitlines():
            prefix=re.match(r'\[([^ ]+) pid=(\d+) tid=(\d+)\] (.*)',line)
            if not prefix:continue
            timestamp,pid,tid,text=prefix.groups();key=pid,tid
            start=re.match(r'BPF_PROG_LOAD type=(\d+) \(([^)]+)\) name=(.*?) insn_cnt=(\d+) ',text)
            if start:
                if key in pending:raise RuntimeError(f'nested load in {log}: {key}')
                typ,kind,program,count=start.groups()
                pending[key]=dict(run=name,log=log.name,pid=int(pid),tid=int(tid),timestamp=timestamp,
                    program=program,type=int(typ),type_name=kind,insn_count=int(count),request=text)
            done=re.fullmatch(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)',text)
            if done:
                if key not in pending:raise RuntimeError(f'load result without request in {log}: {key}')
                row=pending.pop(key);fd,error,program_id=map(int,done.groups())
                row.update(fd=fd,errno=error,id=program_id,status='loaded' if fd>=0 else 'failed')
                loads.append(row)
        loads.extend(dict(row,status='unfinished') for row in pending.values())
    for source in sorted((run/'details/apps').glob('*.json')):
        app=json.loads(source.read_text());baseline=app.get('baseline') or {};post=app.get('post_rejit') or {}
        apps.append(dict(app=app['app'],run=name,status=app['status'],baseline_counter_rows=len(baseline.get('bpf',{})),
            post_counter_rows=len(post.get('bpf',{})),error=app.get('error','')))
        shutil.copy2(source,out/source.name)
    with tarfile.open(out/(name+'.tar.gz'),'w:gz') as archive:archive.add(run,arcname=name)
(out/'all-startup-loads.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in loads))
with (out/'app-outcomes.csv').open('w') as target:
    writer=csv.DictWriter(target,fieldnames=list(apps[0]),lineterminator='\n');writer.writeheader();writer.writerows(apps)
table=['| Application | Baseline counter rows | Native counter rows | App status |', '| --- | ---: | ---: | --- |']
for app in sorted(apps,key=lambda row:row['app']):
    table.append(f'| {app["app"]} | {app["baseline_counter_rows"]} | {app["post_counter_rows"]} | {app["status"]} |')
(out/'table.md').write_text('\n'.join(table)+'\n')
for name in ['qemu-five-baselines','qemu-bcc-context-v2','qemu-context-v2-root','pin-runtime-v2','tetragon-alignchecker','tetragon-alignchecker-v2']:
    shutil.copy2(Path('/workspaces/.agent-state/kprog-lanes/A')/(name+'.log'),out/(name+'.log'))
shutil.copy2(ROOT/'kprog/arm64/build/app-verified-stage/bcc/manifest.json',out/'bcc-manifest.json')
print(f'All{len(loads)} startup load attempts retained: {dict(Counter(row["status"] for row in loads))}')
print('\n'.join(table))
