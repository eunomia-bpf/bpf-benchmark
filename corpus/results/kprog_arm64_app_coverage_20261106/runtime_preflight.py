"""Retain every startup load attempt and interrupted QEMU runtime evidence."""
import csv
import json
from pathlib import Path
import re
import shutil
import sys
import tarfile
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
phase=Path(sys.argv[1]).resolve();phase.mkdir()
state=Path('/workspaces/.agent-state/kprog-lanes/A')
logs=['qemu-inventory-root.log','qemu-inventory-root-v2.log','verified-runtime-build.log',
      'verified-runtime-build-v2.log','qemu-verified-root.log','qemu-paired-modules-root.log',
      'qemu-bcc-verified-1.log','qemu-bcc-verified-2.log','qemu-bcc-verified-3.log']
(phase/'host-logs').mkdir()
for name in logs: shutil.copy2(state/name,phase/'host-logs'/name)
guest=ROOT/'kprog/arm64/build/app-qemu-root'
run=guest/'workspaces/repository/corpus/results/arm64_qemu_corpus_19700101_000013_229609'
shutil.copytree(run,phase/'interrupted-run')
for name in ['qemu-init','qemu-run.sh']: shutil.copy2(guest/name,phase/name)
shutil.copy2(ROOT/'Makefile',phase/'host-Makefile')
rows=[];pending={}
manifest=json.loads((HERE/'inventory/bcc.json').read_text())['objects']
for line in (run/'details/shim-logs/bcc__set.baseline.log').read_text().splitlines():
 match=re.match(r'\[([^ ]+) pid=(\d+) tid=(\d+)\] (.*)',line)
 if not match: continue
 timestamp,pid,tid,message=match.groups();key=pid,tid
 load=re.fullmatch(r'BPF_PROG_LOAD type=(\d+) \(([^)]+)\) name=(.*?) insn_cnt=(\d+) .*license=(.*?) expected_attach=(\d+) attach_btf_id=(\d+) prog_btf_fd=(\d+) attach_btf_obj_fd=(\d+) attach_prog_fd=(\d+)',message)
 if load:
  if key in pending: raise RuntimeError(f'unpaired nested load {key}')
  typ,typename,name,count,license,attach,btfid,btffd,objfd,progfd=load.groups()
  pending[key]=dict(pid=pid,tid=tid,guest_monotonic_start=timestamp,name=name,type=int(typ),type_name=typename,
   insn_count=int(count),license=license,expected_attach_type=int(attach),attach_btf_id=int(btfid),
   prog_btf_fd=int(btffd),attach_btf_obj_fd=int(objfd),attach_prog_fd=int(progfd))
 done=re.fullmatch(r'  PROG_LOAD -> fd=(-?\d+) errno=(\d+) kernel_prog_id=(\d+)',message)
 if done:
  if key not in pending: raise RuntimeError(f'load result without input {key}')
  row=pending.pop(key);fd,error,program=map(int,done.groups())
  row.update(fd=fd,errno=error,id=program,guest_monotonic_end=timestamp)
  row['manifest_candidates']=[entry for entry in manifest if row['name'] and
   (entry['program']==row['name'] or entry.get('symbol',entry['program'])[:15]==row['name'])]
  rows.append(row)
(phase/'startup-loads.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows))
(phase/'unfinished-loads.json').write_text(json.dumps(list(pending.values()),indent=2)+'\n')
with (phase/'startup-loads.csv').open('w') as out:
 fields=['id','pid','tid','name','type','type_name','insn_count','fd','errno','expected_attach_type','attach_btf_id','manifest_candidates']
 writer=csv.DictWriter(out,fieldnames=fields,extrasaction='ignore',lineterminator='\n');writer.writeheader();writer.writerows(rows)
with tarfile.open(phase/'runtime-preflight.tar.gz','w:gz') as out:
 for path in sorted(phase.iterdir()):
  if path.name!='runtime-preflight.tar.gz': out.add(path,arcname=path.name)
print(f'{len(rows)} complete startup load attempts, {len(pending)} unfinished; all retained')
