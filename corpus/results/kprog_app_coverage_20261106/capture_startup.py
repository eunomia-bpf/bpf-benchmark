"""Retain each actual x86 application load, including probes and failed attempts."""
import collections
import csv
import json
from pathlib import Path
import re
import shutil
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=Path(sys.argv[1]).resolve();OUT.mkdir()
run=ROOT/'corpus/results/x86_kvm_corpus_20261106_114826_062263/details'
katran=ROOT/'corpus/results/x86_kvm_corpus_20261106_113727_795524/details'
inputs=[('bcc',run,'bcc__set','bcc_set'),
        ('otelcol-ebpf-profiler',run,'otelcol-ebpf-profiler__profiling','otelcol-ebpf-profiler_profiling'),
        ('cilium',run,'cilium__agent','cilium_agent'),
        ('tetragon',run,'tetragon__observer','tetragon_observer'),
        ('tracee',run,'tracee__monitor','tracee_monitor'),
        ('katran',katran,'katran','katran')]
all_rows=[];summary=[]
for app,directory,log_stem,evidence_stem in inputs:
    target=OUT/app;target.mkdir()
    log=directory/'shim-logs'/(log_stem+'.baseline.log')
    inventory=directory/'bpf-evidence'/evidence_stem/'baseline/program-inventory.json'
    shutil.copy2(log,target/'startup.log')
    shutil.copy2(inventory,target/'program-inventory.json')
    current={p['id']:p for p in json.loads(inventory.read_text())}
    pending={};rows=[];processes={}
    for line in log.read_text().splitlines():
        match=re.match(r'\[([^ ]+) pid=(\d+) tid=(\d+)\] (.*)',line)
        if not match:continue
        timestamp,pid,tid,message=match.groups();key=pid,tid
        if message.startswith('shim_init '):processes[pid]=message
        load=re.fullmatch(r'BPF_PROG_LOAD type=(\d+) \(([^)]+)\) name=(.*?) insn_cnt=(\d+) .*license=(.*?) expected_attach=(\d+) attach_btf_id=(\d+) prog_btf_fd=(\d+) attach_btf_obj_fd=(\d+) attach_prog_fd=(\d+)',message)
        if load:
            if key in pending:raise ValueError(f'nested unpaired load {app} {key}')
            typ,typename,name,count,license,attach,btfid,btffd,objfd,progfd=load.groups()
            pending[key]=dict(app=app,pid=int(pid),tid=int(tid),name=name,type=int(typ),type_name=typename,
                insn_count=int(count),license=license,expected_attach_type=int(attach),attach_btf_id=int(btfid),
                prog_btf_fd=int(btffd),attach_btf_obj_fd=int(objfd),attach_prog_fd=int(progfd),start=timestamp)
        done=re.fullmatch(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)',message)
        if done:
            if key not in pending:raise ValueError(f'load result without input {app} {key}')
            row=pending.pop(key);fd,error,program=map(int,done.groups())
            row.update(fd=fd,errno=error,id=program,end=timestamp,
                executable=processes.get(pid,''),resident=program in current,
                full_name=current.get(program,{}).get('name',row['name']))
            rows.append(row)
    (target/'loads.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
    (target/'unfinished.json').write_text(json.dumps(list(pending.values()),indent=2)+'\n')
    resident={r['id'] for r in rows if r['resident']}
    summary.append(dict(app=app,attempts=len(rows),loaded=sum(r['fd']>=0 for r in rows),
        failed=sum(r['fd']<0 for r in rows),unfinished=len(pending),resident_programs=len(resident),
        source=str(directory)))
    all_rows.extend(rows)
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
with (OUT/'loads.csv').open('w') as stream:
    fields=['app','pid','tid','name','full_name','type','insn_count','id','fd','errno','resident','expected_attach_type','attach_btf_id','executable']
    writer=csv.DictWriter(stream,fieldnames=fields,extrasaction='ignore',lineterminator='\n');writer.writeheader();writer.writerows(all_rows)
for row in summary:print(row)
print('All startup attempts retained; resident counts are matched to this app\'s actual load IDs, not the global inventory.')
