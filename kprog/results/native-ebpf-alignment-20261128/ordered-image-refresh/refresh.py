"""Coordinator11:20 sole-image refresh; frozen kernel/P/app stay, six-app check is subsequent."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,traceback,re
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');LOCKS=LANE.parent/'locks';os.sched_setaffinity(0,{19});now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def git(*args):return subprocess.check_output(['git',*args],cwd=ROOT,text=True).strip()
def image_id():return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip()
def app_hold():
 assert git('branch','--show-current')=='master' and (LANE/'STOP').exists()
 assert git('-C','vendor/repos/opentelemetry-ebpf-profiler','rev-parse','HEAD').startswith('2689a430') and '2689a430' in git('ls-tree','HEAD','vendor/repos/opentelemetry-ebpf-profiler')
 subprocess.run(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','diff','--quiet'],cwd=ROOT,check=True)
def build_limits():resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16,18})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='waiting-locks',scope='COORDINATOR2026-11-28T11:20Z orderedcurrentx86 refresh with ee7f45f55 and6c8fdc70f; BCChostwait confound documented, no speculativecodefix. Rebuild commonlinker/loader/contextcompiler only, preservekernel/nativeP/manifest/benchmark/app2689. No guest/fulltiming in this controller. Six-app10s next after actualimage verification.',commands=[])
def save():(HERE/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
assert not (HERE/'controller.json').exists()
(LANE/'ordered-image-refresh.json').write_text(json.dumps(dict(pid=os.getpid(),result=str(HERE/'controller.json'),log=str(HERE/'job.log')),indent=2)+'\n')
try:
 save();newest=re.findall(r'^COORDINATOR (\S+):',(LANE/'resume-msg.md').read_text(),re.M)[-1];assert newest=='2026-11-28T11:20Z',newest;app_hold()
 for rev in ['ee7f45f55','6c8fdc70f']:subprocess.run(['git','merge-base','--is-ancestor',rev,'HEAD'],cwd=ROOT,check=True)
 with (LOCKS/'timing').open('a') as timing,(LOCKS/'image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX);app_hold();r['phase']='build-common-products';r['source_revision']=git('rev-parse','HEAD');r['old_image']=image_id();assert r['old_image']=='sha256:6b88c0ba4c2253a3eadc999048dc39789185f7516b86a70ec14d098418610e11'
  kernel=Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage');stage=ROOT/'vendor/build/native-bpf/x86/stage';r['kernel_sha256']=sha(kernel)
  def p_inputs():return {str(p.relative_to(stage)):sha(p) for p in sorted(stage.rglob('*')) if p.is_file() and p.name!='kprog-perf-context-lto'}
  r['native_P_inputs']=p_inputs();paths=git('ls-files','kprog/libnativeloader','kprog/x86/native_lab/native_link','kprog/x86/perf_context_lto.cpp','vendor/bpf/Makefile','kprog/perf/one-image/Makefile','corpus','runner/mk','runner/containers','runner/CMakeLists.txt','Makefile').splitlines();paths=[p for p in paths if '/results/' not in p and Path(p).is_file() and Path(p).suffix in ['.rs','.cpp','.hpp','.h','.c','.py','.sh','.mk','.txt','.json','.toml','.lock','.Dockerfile','']];r['source_sha256']={p:sha(ROOT/p) for p in paths};save()
  env=dict(os.environ,CARGO_BUILD_JOBS='2',CMAKE_BUILD_PARALLEL_LEVEL='2')
  def run(cmd,name):
   row=dict(command=cmd,log=name,started_utc=now());r['commands'].append(row);save()
   with (HERE/name).open('wb') as f:row['returncode']=subprocess.run(cmd,cwd=ROOT,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=build_limits).returncode
   row['ended_utc']=now();save();assert row['returncode']==0,row
  run(['cargo','build','--locked','--release','-j2','--manifest-path',str(ROOT/'kprog/x86/native_lab/native_link/Cargo.toml')],'linker-build.log')
  run(['cmake','--build',str(ROOT/'runner/build-llvmbpf'),'--target','native_loader_shared','-j2'],'loader-build.log')
  run(['make','-C',str(ROOT/'vendor/bpf'),'ARCH=x86',str(stage/'kprog-perf-context-lto'),'JOBS=2'],'context-build.log')
  products={'/usr/local/bin/native-link':ROOT/'kprog/x86/native_lab/native_link/target/release/native-link','/usr/local/lib/bpfrejit/libnative_loader.so':ROOT/'runner/build-llvmbpf/native_loader/libnative_loader.so','/opt/bpf-benchmark/native-bpf/x86_64/kprog-perf-context-lto':stage/'kprog-perf-context-lto'};r['products']={n:dict(host_path=str(p),sha256=sha(p)) for n,p in products.items()};r['phase']='build-runtime-image';save()
  skip=['host-kinsn-x86','host-rust-x86','host-shim-x86','host-source-apps-x86','host-runner-x86','host-micro-programs-x86','host-stage2-programs-x86','host-x86-sim-proofs','host-bpfopt-llvm-x86','host-native-bpf-x86','host-kernel-x86'];cmd=['make','-C',str(ROOT),'-o',str(kernel)]
  for target in skip:cmd+=['-o',target]
  cmd+=['x86-runner-runtime-image-tar','HOST_KERNEL_BUILD_DIR_X86=/workspaces/.agent-state/kprog-ck/build-x86','X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/kprog:current','X86_RUNTIME_KERNEL_IMAGE='+str(kernel),'JOBS=2','IMAGE_BUILD_JOBS=2'];run(cmd,'image-build.log');r['new_image']=image_id();app_hold();assert sha(kernel)==r['kernel_sha256'] and p_inputs()==r['native_P_inputs'];assert all(sha(ROOT/p)==h for p,h in r['source_sha256'].items())
  expected={**{n:d['sha256'] for n,d in r['products'].items()},**{'/opt/bpf-benchmark/native-bpf/x86_64/'+n:h for n,h in r['native_P_inputs'].items()}}
  code="import sys,json,hashlib;d=json.load(sys.stdin);bad=[p for p,h in d.items() if hashlib.sha256(open(p,'rb').read()).hexdigest()!=h];print(json.dumps(dict(files=len(d),bad=bad)));sys.exit(bool(bad))"
  proc=subprocess.run(['docker','run','--rm','-i','--network','none','--entrypoint','python3',r['new_image'],'-c',code],input=json.dumps(expected),text=True,capture_output=True);r['image_payload_verification']=dict(returncode=proc.returncode,stdout=proc.stdout,stderr=proc.stderr);save();assert proc.returncode==0
  tar=ROOT/'.cache/container-images/x86_64-runner-runtime.image.tar';r['runtime_tar']=dict(path=str(tar),bytes=tar.stat().st_size,sha256=sha(tar));r['kernel_P_source_app_unchanged']=True;save()
  if r['old_image']!=r['new_image']:
   p=subprocess.run(['docker','image','rm',r['old_image']],stdin=subprocess.DEVNULL,text=True,capture_output=True);r['old_image_retirement']=dict(returncode=p.returncode,stdout=p.stdout,stderr=p.stderr);save();assert p.returncode==0
 r.update(controller_status=0,phase='finished',next='Collect same build, verify actualproducts/image/tar/sourceguards; run ordered six-app10s alignment check. Build0 is NOT app/installedcode/equalwork acceptance.')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k not in ['native_P_inputs','source_sha256']}),flush=True)
raise SystemExit(r['controller_status'])
