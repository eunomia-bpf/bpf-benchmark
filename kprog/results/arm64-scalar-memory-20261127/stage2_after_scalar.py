"""Continue the authorized scalar repair with the existing stage-2 app recipe."""
import hashlib
import json
import os
from pathlib import Path
import select
import subprocess
import traceback
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());OUT=Path(run['result']);launch=json.loads((OUT/'stage2-queued.json').read_text())
record=dict(pid=os.getpid(),started_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),app='tetragon/observer',dependency_pid=launch['dependency_pid'],phase='waiting-for-existing-scalar-pipeline',scope='Run existing finite ARM checked corpus only after all145 compilations and paired stock loads complete. Verifier refusals are expected outcomes, not execution failures. Same kernel/root/framework/common flags; native/stage2 success comes from actual child receipts.')
def save():(OUT/'stage2-queue-controller.json').write_text(json.dumps(record,indent=2)+'\n')
try:
 save();pid=record['dependency_pid']
 try:fd=os.pidfd_open(pid)
 except ProcessLookupError:fd=None
 if fd is not None:
  try:
   stat=Path('/proc/'+str(pid)+'/stat').read_text();assert stat.rsplit(')',1)[1].split()[19]==launch['dependency_start_ticks'],'dependency PID was reused'
   poll=select.poll();poll.register(fd,select.POLLIN);poll.poll()
  finally:os.close(fd)
 compiled=json.loads((OUT/'compile-controller.json').read_text());stock=json.loads((OUT/'all145-stock-controller.json').read_text())
 assert compiled['controller_status']==0 and len(compiled['cases'])==145
 assert stock['controller_status']==0 and len(stock['stock']['cases'])==145
 assert all(set(row['loads'])=={'before','after'} and all(x['returncode'] in [0,2] for x in row['loads'].values()) for row in stock['stock']['cases'])
 record['dependency_ended_utc']=stock['ended_utc'];record['phase']='running-existing-stage2';record['source_revision']=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()
 record['header_sha256']=hashlib.sha256((ROOT/'kprog/arm64/arm64_sim_local_bpf.h').read_bytes()).hexdigest();record['source_drift_since_compilation']=[p for p,h in compiled['source_sha256'].items() if hashlib.sha256(Path(p).read_bytes()).hexdigest()!=h]
 command=['taskset','-c','19','python3',str(ROOT/'kprog/results/arm64-checked-corpus-20261127/guest_controller.py'),record['app']];record['command']=command
 with (LANE/'scalar-stage2-child.log').open('wb') as log:
  child=subprocess.Popen(command,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT);record['child_pid']=child.pid;save();record['child_returncode']=child.wait()
 record['child_controllers']=[]
 for p in (ROOT/'kprog/results/arm64-checked-corpus-20261127').glob('guest-*/controller.json'):
  r=json.loads(p.read_text())
  if r.get('pid')==child.pid:record['child_controllers'].append(str(p))
 record['controller_status']=int(record['child_returncode']!=0);record['phase']='finished'
except Exception:record.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 record['ended_utc']=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();save();print(json.dumps(record),flush=True)
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM scalar-repair queued Tetragon stage2 ended status '+str(record['controller_status'])+'. Read '+str(OUT/'stage2-queue-controller.json')+' and actual child corpus/service/verifier receipts; distinguish dependency, guest, app, publication and observed workload outcomes.\n')
raise SystemExit(record['controller_status'])
