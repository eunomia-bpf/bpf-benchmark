"""Build the actual ARM tool using the canonical base's LLVM18, after host validation."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,select,shlex,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;L=Path('/workspaces/.agent-state/kprog-lanes');BASE=ROOT/'.cache/qemu-arm64-root';STAGE=ROOT/'vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
previous=json.loads((OUT/'attempt2-native-arm-controller.json').read_text());r={k:v for k,v in previous.items() if k not in ['exception','ended_utc']};r.update(pid=os.getpid(),started_utc=now(),phase='arm-execution-only',controller_status=None)
def save():(OUT/'native-arm-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 dep=json.loads((OUT/'build-controller.json').read_text());assert dep['controller_status']==0
 for p,s in dep['source_sha256'].items():assert sha(ROOT/p)==s,p
 output=STAGE.with_name(STAGE.name+'.arm64.tmp');assert int.from_bytes(output.read_bytes()[18:20],'little')==183;r['reused_compiled_tool_sha256']=sha(output);assert sha(STAGE)==r['before']['sha256'];before=OUT/'arm-tool-before.tar.gz';save()
 with (L/'locks/timing').open('a') as t,(L/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX)
  # Reuse the exact existing scalar regression's final ARM input, not another fixture.
  cases=sorted((ROOT/'kprog/x86/native_lab/native_link/target').glob('frozen-ir-test-*/input.proof.o'),key=lambda p:p.stat().st_mtime)
  assert cases;fixture=cases[-1];assert int.from_bytes(fixture.read_bytes()[18:20],'little')==183
  facts=OUT/'native-arm-immutable.json';facts.write_text('{"option":"00000000"}\n');native=OUT/'native-arm-scalar.o'
  command=['qemu-aarch64-static','-L',str(BASE),str(output),str(fixture),'--symbol','entry','--kernel-btf','/workspaces/.agent-state/kprog-ck/build-arm64/vmlinux','--prog-type','0','--immutable-globals',str(facts),'-o',str(native)]
  r['execution_command']=command;r['fixture']=dict(path=str(fixture),sha256=sha(fixture));save()
  with (OUT/'native-arm-execution.log').open('wb') as log:r['execution_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['execution_returncode']==0;assert int.from_bytes(native.read_bytes()[18:20],'little')==183
  undefined=subprocess.check_output(['llvm-nm-18','--undefined-only',str(native)],text=True);(OUT/'native-arm-undefined.txt').write_text(undefined);names={s.split()[-1] for s in undefined.splitlines() if s.split()};assert 'live' in names and 'selected' not in names and 'option' not in names
  r['needed']=subprocess.check_output(['aarch64-linux-gnu-readelf','-d',str(output)],text=True);os.replace(output,STAGE);r['product']=dict(path=str(STAGE),bytes=STAGE.stat().st_size,sha256=sha(STAGE));r['before_archive']=dict(path=str(before),bytes=before.stat().st_size,sha256=sha(before));r.update(controller_status=0,phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
