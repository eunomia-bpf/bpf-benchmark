"""Build the actual ARM tool using the canonical base's LLVM18, after host validation."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,select,shlex,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;L=Path('/workspaces/.agent-state/kprog-lanes');BASE=ROOT/'.cache/qemu-arm64-root';STAGE=ROOT/'vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
r=dict(pid=os.getpid(),started_utc=now(),phase='host-component-dependency',controller_status=None)
def save():(OUT/'native-arm-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 dep=json.loads((OUT/'build-controller.json').read_text());r['dependency_pid']=dep['pid'];save()
 if dep['controller_status'] is None:
  try:fd=os.pidfd_open(dep['pid'])
  except ProcessLookupError:fd=None
  if fd is not None:select.select([fd],[],[]);os.close(fd)
 dep=json.loads((OUT/'build-controller.json').read_text());assert dep['controller_status']==0,dep
 for p,s in dep['source_sha256'].items():assert sha(ROOT/p)==s,p
 llvm=BASE/'usr/lib/llvm-18/lib/libLLVM.so.1';bpf=BASE/'usr/lib/aarch64-linux-gnu/libbpf.so.1';libs=BASE/'usr/lib/aarch64-linux-gnu';assert llvm.is_file() and bpf.is_file()
 r.update(phase='native-arm-build',llvm=dict(path=str(llvm),sha256=sha(llvm)),before=dict(bytes=STAGE.stat().st_size,sha256=sha(STAGE)));save()
 with (L/'locks/timing').open('a') as t,(L/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX)
  before=OUT/'arm-tool-before.tar.gz'
  with tarfile.open(before,'w:gz') as tar:tar.add(STAGE,arcname='kprog-perf-context-lto')
  with tarfile.open(before,'r:gz') as tar:assert hashlib.sha256(tar.extractfile('kprog-perf-context-lto').read()).hexdigest()==r['before']['sha256']
  output=STAGE.with_name(STAGE.name+'.arm64.tmp')
  flags=shlex.split(subprocess.check_output(['llvm-config-18','--cxxflags'],text=True))
  command=['aarch64-linux-gnu-g++',*flags,'-std=c++17','-fexceptions','-Wall','-Wextra','-Wno-unused-parameter','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'runner/build-llvmbpf/vendor/libbpf/prefix/include'),str(ROOT/'kprog/x86/perf_context_lto.cpp'),'-o',str(output),str(llvm),str(bpf),'-Wl,-rpath-link,'+str(libs),'-Wl,-rpath-link,'+str(BASE/'lib/aarch64-linux-gnu'),'-lpthread','-ldl','-lz']
  r['command']=command;save()
  with (OUT/'native-arm-build.log').open('wb') as log:r['build_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['build_returncode']==0,r['build_returncode'];r['file']=subprocess.check_output(['file',str(output)],text=True).strip();assert 'ARM aarch64' in r['file']
  # Reuse the exact existing scalar regression's final ARM input, not another fixture.
  cases=sorted((ROOT/'kprog/x86/native_lab/native_link/target').glob('frozen-ir-test-*/input.proof.o'),key=lambda p:p.stat().st_mtime)
  assert cases;fixture=cases[-1];assert int.from_bytes(fixture.read_bytes()[18:20],'little')==183
  facts=OUT/'native-arm-immutable.json';facts.write_text('{"option":"00000000"}\n');native=OUT/'native-arm-scalar.o'
  command=['qemu-aarch64-static','-L',str(BASE),str(output),str(fixture),'--symbol','entry','--kernel-btf','/workspaces/.agent-state/kprog-ck/build-arm64/vmlinux','--prog-type','0','--immutable-globals',str(facts),'-o',str(native)]
  r['execution_command']=command;r['fixture']=dict(path=str(fixture),sha256=sha(fixture));save()
  with (OUT/'native-arm-execution.log').open('wb') as log:r['execution_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['execution_returncode']==0;assert int.from_bytes(native.read_bytes()[18:20],'little')==183
  proof=OUT/'native-arm-scalar.proof.o'
  command=[str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'),'--input',str(native),'--symbol','entry','--mode','proof','--output',str(proof)]
  with (OUT/'native-arm-proof.log').open('wb') as log:subprocess.run(command,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,check=True)
  undefined=subprocess.check_output(['llvm-nm-18','--undefined-only',str(proof)],text=True);(OUT/'native-arm-undefined.txt').write_text(undefined);names={s.split()[-1] for s in undefined.splitlines() if s.split()};assert 'live' in names and 'selected' not in names and 'option' not in names
  r['needed']=subprocess.check_output(['aarch64-linux-gnu-readelf','-d',str(output)],text=True);os.replace(output,STAGE);r['product']=dict(path=str(STAGE),bytes=STAGE.stat().st_size,sha256=sha(STAGE));r['before_archive']=dict(path=str(before),bytes=before.stat().st_size,sha256=sha(before));r.update(controller_status=0,phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
