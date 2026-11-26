"""Finite existing sole-kernel stock check of the ARM B producer change."""
import fcntl
import io
import json
import os
from pathlib import Path
import subprocess
import tarfile
import traceback
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
token=subprocess.check_output(['date','-u','+%Y%m%dT%H%M%SZ'],text=True).strip()
OUT=HERE/('frontend-stock-'+token)
OUT.mkdir()
record=dict(started_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),pid=os.getpid(),
 scope='Existing sole-x86-kernel stock B loads for synthetic ARM P frontend before/direct-after/broker-after cases. ISA-neutral B only; no ARM native kernel execution, app or timing result.')
def save():(OUT/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
status=1
try:
 save()
 requests=[]
 for i,phase in enumerate(['before','after','broker']):
  case=OUT/str(i);case.mkdir();replay=OUT/'replay'/str(i);replay.mkdir(parents=True)
  with tarfile.open(HERE/f'frontend-{phase}-evidence.tar.gz') as archive:
   (replay/'replay.bpf.o').write_bytes(archive.extractfile('frontend/generated/trusted_arm64.bpf.o').read())
  (case/'generation.metadata.json').write_text(json.dumps(dict(version=1,prog_type=2,section='kprobe/trusted',maps=[]))+'\n')
  (case/'kernel.facts.json').write_text(json.dumps(dict(prog_type=2,expected_attach_type=0,prog_flags=0,prog_ifindex=0,
      attach_btf_id=0,attach_btf_obj_id=0,attach_prog_id=0,gpl_compatible=1))+'\n')
  requests.append(dict(request=i,phase=phase))
 (OUT/'index.json').write_text(json.dumps(dict(source_archive='synthetic ARM frontend diagnostic archives',requests=requests))+'\n')
 command=['make','-f','kprog/results/cilium-headlen-20261119/Makefile','archive-stock',
          'OUT='+str(OUT),'INPUTS='+str(OUT/'index.json'),'REPLAY='+str(OUT/'replay')]
 record['command']=command;save()
 with Path('/workspaces/.agent-state/kprog-lanes/locks/timing').open('a') as timing,Path('/workspaces/.agent-state/kprog-lanes/locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_SH)
  with (OUT/'guest.log').open('w') as log:r=subprocess.run(command,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
 record['returncode']=r.returncode
 record['results']=json.loads((OUT/'result.json').read_text())
 rows=record['results']['requests']
 status=0 if r.returncode==0 and len(rows)==3 and all(row['returncode']==0 for row in rows) else 1
except Exception:
 record['exception']=traceback.format_exc()
finally:
 record['controller_status']=status
 record['ended_utc']=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip();save()
 try:
  with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('a') as lock,(OUT/'publication.log').open('a') as log:
   fcntl.flock(lock,fcntl.LOCK_EX)
   path=str(OUT.relative_to(ROOT))
   for command in [['git','add','-f','--',path],['git','commit','--only','-m','Record ARM frontend B stock subset','--',path],['git','push']]:
    subprocess.run(command,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT,check=True)
 except Exception:
  record['publication_error']=traceback.format_exc();status=1;record['controller_status']=status;save()
 with (LANE/'resume-msg.md').open('a') as message:
  message.write(f'\nARM frontend stock subset ended status {status}. Read {OUT}/controller.json, publication.log, result.json and per-case verifier logs; record actual before/direct/broker B acceptance, fix actual within-design regressions, keep full timing frozen.\n')
 stop=LANE/'STOP'
 if stop.exists() and stop.read_text().startswith('PERF ARM frontend stock:'):stop.unlink()
raise SystemExit(status)
