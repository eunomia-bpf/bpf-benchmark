"""Rebuild the one ARM checked loader after the common kernel-symbol fix."""
import fcntl,hashlib,json,os,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');HERE=Path(__file__).resolve().parent
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
stamp=now();out=HERE/('kernel-catalogue-'+stamp.replace('-','').replace(':',''));out.mkdir()
record=dict(pid=os.getpid(),started_utc=stamp,source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),source_sha256=hashlib.sha256((ROOT/'kprog/libnativeloader/src/native_loader_trusted.cpp').read_bytes()).hexdigest(),scope='Build existing ARM checked loader in place; 48GiBAS/atmost2compilerjobs/CPU16,18. Build completion does not establish live kernel symbol/native binding or workload acceptance.',phase='building',controller_status=None)
def save():(out/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
(LANE/'kernel-catalogue-build.json').write_text(json.dumps(dict(result=str(out),pid=os.getpid()))+'\n')
try:
 save()
 with (LANE.parent/'locks/timing').open('a') as timing,(LANE.parent/'locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX)
  command=['prlimit','--as=51539607552','taskset','-c','16,18','cmake','--build',str(ROOT/'runner/build-arm64-llvmbpf'),'--target','trusted-native-loader','--','-j2'];record['command']=command;save()
  with (out/'build.log').open('wb') as log:record['build_returncode']=subprocess.run(command,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT).returncode
  record['controller_status']=int(record['build_returncode']!=0)
  binary=ROOT/'runner/build-arm64-llvmbpf/native_loader/trusted-native-loader'
  if not record['controller_status']:record['loader']=dict(path=str(binary),bytes=binary.stat().st_size,sha256=hashlib.sha256(binary.read_bytes()).hexdigest())
 record['phase']='finished'
except Exception:record.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM kernel-symbol catalogue loader build ended status '+str(record['controller_status'])+'. Read '+str(out/'controller.json')+' and build.log; actual ARM kernel-symbol/native-link validation remains required before claiming request12 repair.\n')
 print(json.dumps(record),flush=True)
raise SystemExit(record['controller_status'])
