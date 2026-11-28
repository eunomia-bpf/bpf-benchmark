"""Finish the same current-source build with the existing LPM oracle and loader target."""
import hashlib,json,os,select,shutil,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
b=json.loads((LANE/'lpm-type-binding-build.json').read_text());r=dict(pid=os.getpid(),started_utc=now(),phase='build-dependency',controller_status=None,build=b,raw='/workspaces/kprog-raw/perf/lpm-type-binding-20261128')
def save():(OUT/'oracle-loader-controller.json').write_text(json.dumps(r,indent=2)+chr(10))
try:
 save()
 try:fd=os.pidfd_open(b['pid'])
 except ProcessLookupError:fd=None
 if fd is not None:
  poll=select.poll();poll.register(fd,select.POLLIN);poll.poll();os.close(fd)
 r['build_returncode']=int((OUT/'build.exit').read_text());save()
 assert r['build_returncode']==0,'build failed; original log/exit retained'
 assert {p:sha(ROOT/p) for p in b['source_sha256']}==b['source_sha256'],'source changed after build launch'
 r['phase']='oracle-and-loader';save()
 with (OUT/'oracle-and-loader.log').open('wb') as log:
  r['returncode']=subprocess.run(['taskset','-c','16,18','bash',str(OUT/'oracle-and-loader.sh')],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
 assert r['returncode']==0,'oracle/loader command failed; see exact log'
 raw=Path(r['raw']);art=raw/'artifacts';art.mkdir(exist_ok=True);tmp=Path('/var/tmp/kprog-tmp/perf/lpm-c-lto')
 names=['layout','fixture.o']+[n+'-'+s+'.o' for n in ['fixed','dynamic','mixed','unknown'] for s in ['entry','entry_select']]+[n+'-execute' for n in ['fixed','dynamic','mixed','unknown']]
 for name in names:shutil.copyfile(tmp/name,art/name)
 r['oracle_report']=json.loads((raw/'report.json').read_text())
 r['products']={str(p.relative_to(ROOT)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in [ROOT/'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto',ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',ROOT/'runner/build-llvmbpf/native_loader/libnative_loader.so']}
 r.update(phase='finished',controller_status=0)
except Exception:r.update(phase='failed',controller_status=1,exception=traceback.format_exc())
finally:
 r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['pid','phase','controller_status','exception']}),flush=True)
raise SystemExit(r['controller_status'])
