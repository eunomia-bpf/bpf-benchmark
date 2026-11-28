"""Canonical build/tests and the same executable witness for the four-line fix."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
os.sched_setaffinity(0,{19});source=ROOT/'kprog/x86/native_lab/native_link/src/main.rs'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,stages=[])
def save():(OUT/'fix-controller.json').write_text(json.dumps(r,indent=2)+'\n')
def run(name,args,env=None):
 p=OUT/(name+'.log');started=now()
 with p.open('xb') as f:c=subprocess.run(args,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env,preexec_fn=limits)
 row=dict(name=name,args=args,started_utc=started,ended_utc=now(),returncode=c.returncode,log=dict(path=str(p.relative_to(ROOT)),bytes=p.stat().st_size,sha256=sha(p)),cpu=16,address_space_bytes=48*1024**3);r['stages'].append(row);save();return c.returncode
try:
 prep=json.loads((OUT/'fix-preparation.json').read_text());assert sha(source)==prep['after_sha256'];r['source_sha256']=sha(source);save()
 target=['make','-C','kprog/results/arm64-common-flags-20261126'];host=run('host-build',target+['native-link-build'])
 if host==0:
  env=dict(os.environ,RUST_TEST_THREADS='1');run('existing-linker-tests',target+['native-link-tests'],env=env)
  run('same-witness-after',['make','-C',str(OUT.relative_to(ROOT)),'after'])
 # Cross-build is independent of test/witness outcomes; preserve each stage.
 run('arm-build',target+['native-link-arm-build'])
 r['products']={}
 for arch,path in [('x86','kprog/x86/native_lab/native_link/target/release/native-link'),('arm64','kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link')]:
  p=ROOT/path;r['products'][arch]=dict(path=path,bytes=p.stat().st_size,sha256=sha(p))
 after=OUT/'after/controller.json'
 if after.exists():
  a=json.loads(after.read_text());r['after_cases']=a['cases'];r['witness_regression_passed']=a.get('regression_passed',False)
 assert sha(source)==r['source_sha256'],'source changed during validation'
 r['controller_status']=0 if all(x['returncode']==0 for x in r['stages']) and r.get('witness_regression_passed',False) else 1
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:r['ended_utc']=now();save()
raise SystemExit(r['controller_status'])
