"""Canonical ARCH=arm64 tool build and actual ARM linker proof execution; no guest/image rebuild."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;L=Path('/workspaces/.agent-state/kprog-lanes');BASE=ROOT/'.cache/qemu-arm64-root';TOOL=ROOT/'vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto';LINKER=ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
def image():return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip()
def inputs():
 stage=TOOL.parent;paths=[p for p in stage.rglob('*') if p.is_file() and p!=TOOL]+[Path('/workspaces/.agent-state/kprog-ck/build-arm64/arch/arm64/boot/Image'),Path('/workspaces/.agent-state/kprog-ck/build-arm64/vmlinux'),Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage')]
 return {str(p):sha(p) for p in paths}
r=dict(pid=os.getpid(),started_utc=now(),phase='canonical-components',controller_status=None,scope='48GiB/max2/CPU16,18/timingSH-imageEX. Canonical Makefile ARM compiler + existing cross-Rust native-link; no P/kernel/image/benchmark/timing/PMU.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 launch=json.loads((OUT/'launch.json').read_text());r['source_sha256']=launch['source_sha256']
 for p,s in r['source_sha256'].items():assert sha(ROOT/p)==s,p
 save()
 with (L/'locks/timing').open('a') as t,(L/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX);before=inputs();r['image_before']=image();r['inputs_before']=before;r['compiler_before']=sha(TOOL);save()
  with tarfile.open(OUT/'tools-before.tar.gz','w:gz') as archive:
   for p in [TOOL,LINKER]:
    if p.is_file():archive.add(p,arcname=str(p.relative_to(ROOT)))
  with (OUT/'build.log').open('wb') as log:r['build_returncode']=subprocess.run(['bash',str(OUT/'build.sh')],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['build_returncode']==0;assert int.from_bytes(TOOL.read_bytes()[18:20],'little')==183 and int.from_bytes(LINKER.read_bytes()[18:20],'little')==183
  native=OUT.parent/'native-arm-scalar.o';proof=OUT/'native-arm-linker.proof.o';command=['qemu-aarch64-static','-L',str(BASE),str(LINKER),'--input',str(native),'--symbol','entry','--mode','proof','--output',str(proof)];r['execution_command']=command;save()
  with (OUT/'arm-linker-execution.log').open('wb') as log:r['execution_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['execution_returncode']==0 and int.from_bytes(proof.read_bytes()[18:20],'little')==183
  undefined=subprocess.check_output(['llvm-nm-18','--undefined-only',str(proof)],text=True);(OUT/'undefined.txt').write_text(undefined);names={s.split()[-1] for s in undefined.splitlines() if s.split()};assert 'live' in names and 'selected' not in names and 'option' not in names;assert '.native_link_abi' in subprocess.check_output(['llvm-readelf-18','-S',str(proof)],text=True)
  r['compiler_matches_validated_artifact']=sha(TOOL)==r['compiler_before'];r['proof_matches_host_linker']=sha(proof)==sha(OUT.parent/'native-arm-scalar.proof.o');r['products']={str(p.relative_to(ROOT)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in [TOOL,LINKER,proof]};r['inputs_after']=inputs();r['image_after']=image();assert before==r['inputs_after'] and r['image_before']==r['image_after'];r.update(controller_status=0,phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','build_returncode','execution_returncode','exception']}),flush=True)
raise SystemExit(r['controller_status'])
