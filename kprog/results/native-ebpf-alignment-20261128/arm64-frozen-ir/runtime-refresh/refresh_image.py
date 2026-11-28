"""Rebuild stale ARM loader and refresh only its existing image; preserve kernels/P/root/x86."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;L=Path('/workspaces/.agent-state/kprog-lanes');K=Path('/workspaces/.agent-state/kprog-ck/build-arm64');TAG='bpf-benchmark/runner-runtime:arm64';SO=ROOT/'runner/build-arm64-llvmbpf/native_loader/libnative_loader.so';QROOT=ROOT/'.cache/qemu-arm64-root'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def image(tag):return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip()
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
def protected():
 paths=[p for p in (ROOT/'vendor/build/native-bpf/arm64/stage').rglob('*') if p.is_file()]+[K/'arch/arm64/boot/Image',K/'arch/arm64/boot/vmlinuz.efi',K/'vmlinux',Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage'),QROOT/'qemu-init',QROOT/'usr/lib/llvm-18/lib/libLLVM.so.1']
 return {str(p):sha(p) for p in paths}
r=dict(pid=os.getpid(),started_utc=now(),phase='loader-build',controller_status=None,scope='Current committed ARM loader headers/sharedSO only, then existing ARM image tag/tar.48GiB/max2/16,18/timingSH-imageEX. No P/kernel/root/x86/benchmark/guest changes.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 launch=json.loads((OUT/'launch.json').read_text());r['source_revision']=launch['source_revision'];r['source_sha256']=launch['source_sha256']
 for p,s in r['source_sha256'].items():assert sha(ROOT/p)==s,p
 save()
 with (L/'locks/timing').open('a') as t,(L/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX);r['protected_before']=protected();r['x86_image_before']=image('bpf-benchmark/kprog:current');r['old_arm_image']=image(TAG);r['loader_before']=dict(bytes=SO.stat().st_size,sha256=sha(SO));save()
  with tarfile.open(OUT/'loader-before.tar.gz','w:gz') as archive:archive.add(SO,arcname='libnative_loader.so')
  with tarfile.open(OUT/'loader-before.tar.gz','r:gz') as archive:assert hashlib.sha256(archive.extractfile('libnative_loader.so').read()).hexdigest()==r['loader_before']['sha256']
  with (OUT/'loader-build.log').open('wb') as log:r['loader_build_returncode']=subprocess.run(['bash',str(OUT/'loader-build.sh')],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['loader_build_returncode']==0 and int.from_bytes(SO.read_bytes()[18:20],'little')==183;r['loader_after']=dict(bytes=SO.stat().st_size,sha256=sha(SO));r['phase']='image-build';save()
  prerequisites=['host-kernel-arm64','host-kinsn-arm64','host-rust-arm64','host-shim-arm64','host-source-apps-arm64','host-runner-arm64','host-micro-programs-arm64','host-stage2-programs-arm64','host-arm64-sim-proofs','host-bpfopt-llvm-arm64','host-native-bpf-arm64']
  command=['make','-C',str(ROOT)]
  for target in [str(K/'arch/arm64/boot/Image'),str(K/'arch/arm64/boot/vmlinuz.efi'),*prerequisites]:command+=['-o',target]
  command+=['arm64-runner-runtime-image-tar','HOST_KERNEL_BUILD_DIR_ARM64='+str(K),'NATIVE_BPF_ARTIFACTS_ARM64='+str(ROOT/'vendor/build/native-bpf/arm64/stage'),'ARM64_RUNNER_RUNTIME_IMAGE='+TAG,'JOBS=2','IMAGE_BUILD_JOBS=2'];r['image_command']=command;save()
  with (OUT/'image-build.log').open('wb') as log:r['image_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,preexec_fn=child).returncode
  assert r['image_returncode']==0;r['new_arm_image']=image(TAG);r['protected_after']=protected();r['x86_image_after']=image('bpf-benchmark/kprog:current');assert r['protected_before']==r['protected_after'] and r['x86_image_before']==r['x86_image_after']
  if r['old_arm_image']!=r['new_arm_image']:
   found=subprocess.run(['docker','image','inspect',r['old_arm_image']],stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL).returncode==0
   if found:
    result=subprocess.run(['docker','image','rm',r['old_arm_image']],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);r['retirement']=dict(returncode=result.returncode,output=result.stdout)
   else:r['retirement']=dict(returncode=0,output='Old image already absent after successful refresh')
  else:r['retirement']=dict(returncode=0,output='Image content unchanged')
  r.update(controller_status=0,phase='finished-root-activation-pending')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','loader_build_returncode','image_returncode','new_arm_image','exception']}),flush=True)
raise SystemExit(r['controller_status'])
