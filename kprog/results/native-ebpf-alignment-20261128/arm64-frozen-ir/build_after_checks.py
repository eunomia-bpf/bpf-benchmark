"""Finish the finite current-image checks before the sole staged component build."""
from pathlib import Path
import fcntl,hashlib,json,os,select,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;L=Path('/workspaces/.agent-state/kprog-lanes')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='current-check-dependency')
def save():(OUT/'build-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 launch=json.loads((OUT/'build-launch.json').read_text());r['dependency']=launch['dependency'];r['source_sha256']=launch['source_sha256'];save()
 try:fd=os.pidfd_open(launch['dependency']['pid'])
 except ProcessLookupError:fd=None
 if fd is not None:select.select([fd],[],[]);os.close(fd)
 dep=json.loads((Path(launch['dependency']['result'])/'controller.json').read_text());assert dep['phase'] in ['finished','failed'];r['dependency_controller_status']=dep['controller_status'];r['phase']='component-build';save()
 for p,s in launch['source_sha256'].items():assert hashlib.sha256((ROOT/p).read_bytes()).hexdigest()==s,p
 with (L/'locks/timing').open('a') as t,(L/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX)
  with (OUT/'build.log').open('wb') as log:r['build_returncode']=subprocess.run(['taskset','-c','16,18','bash',str(OUT/'build.sh')],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
 r['controller_status']=r['build_returncode'];r['phase']='finished';r['products']={str(p.relative_to(ROOT)):dict(bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in [ROOT/'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto',ROOT/'kprog/x86/native_lab/native_link/target/release/native-link']}
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
