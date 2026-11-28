"""Activate the already built fixed ARM collector through the canonical image/root rules."""
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');BASE=ROOT/'.cache/qemu-arm64-root';K=Path('/workspaces/.agent-state/kprog-ck/build-arm64');TAG='bpf-benchmark/runner-runtime:arm64';TAR=ROOT/'.cache/container-images/arm64-runner-runtime.image.tar'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def image(tag):return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip()
def child():resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='image-resource',scope='Already-built ARM collector app activation only, canonical image tag/root, imageEX immediate status, CPUs16,18; kernels/P/compiler/loader/x86 image preserved.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
lock=None
try:
 os.sched_setaffinity(0,{19});save();lock=(LANE.parent/'locks/image').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 for p in Path('/proc').iterdir():
  if p.name.isdigit():
   try:exe=(p/'exe').readlink()
   except OSError:continue
   assert 'qemu-system-aarch64' not in exe.name,p.name
 assert BASE.resolve()==ROOT/'.cache/qemu-arm64-root' and not BASE.is_symlink();assert not Path(str(BASE)+'.tmp').exists() and not Path(str(BASE)+'.tmp').is_symlink()
 prior=json.loads((OUT.parent/'kernel-regression/controller.json').read_text());assert prior['controller_status']==0
 paths=[Path(n) for n in prior['protected_after'] if n!=str(BASE/'usr/local/bin/otelcol-ebpf-profiler')];r['protected_before']={str(p):sha(p) for p in paths};assert all(r['protected_before'][str(p)]==prior['protected_after'][str(p)] for p in paths)
 pre=json.loads((OUT/'root-preflight.json').read_text());archive=ROOT/pre['archive']['path'];assert sha(archive)==pre['archive']['sha256'];assert subprocess.check_output(['git','show','HEAD:'+str(archive.relative_to(ROOT))])==archive.read_bytes()
 with tarfile.open(archive,'r:gz') as t:got={m.name:dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest()) for m in t.getmembers() if m.isfile()}
 assert got==pre['archived_files']
 for n,row in {**pre['archived_files'],**pre['host_matching_files']}.items():
  p=BASE/n;assert sha(p)==row['sha256'] and p.stat().st_size==row['bytes'],n
  if n in pre['host_matching_files']:assert sha(Path('/'+n))==row['sha256'],n
 r['old_arm_image']=image(TAG);r['x86_image_before']=image('bpf-benchmark/kprog:current');r['phase']='image-build'
 prereqs=['host-kernel-arm64','host-kinsn-arm64','host-rust-arm64','host-shim-arm64','host-source-apps-arm64','host-runner-arm64','host-micro-programs-arm64','host-stage2-programs-arm64','host-arm64-sim-proofs','host-bpfopt-llvm-arm64','host-native-bpf-arm64']
 command=['make','-C',str(ROOT)]
 for target in [str(K/'arch/arm64/boot/Image'),str(K/'arch/arm64/boot/vmlinuz.efi'),*prereqs]:command+=['-o',target]
 command+=['arm64-runner-runtime-image-tar','HOST_KERNEL_BUILD_DIR_ARM64='+str(K),'NATIVE_BPF_ARTIFACTS_ARM64='+str(ROOT/'vendor/build/native-bpf/arm64/stage'),'ARM64_RUNNER_RUNTIME_IMAGE='+TAG,'JOBS=2','IMAGE_BUILD_JOBS=2'];r['image_command']=command;save()
 with (OUT/'image-build.log').open('wb') as f:r['image_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=child).returncode
 assert r['image_returncode']==0;r['new_arm_image']=image(TAG)
 expected=json.loads((OUT.parents[2]/'root-activation/controller.json').read_text())['activated_payloads'];app=json.loads((OUT.parent/'controller.json').read_text())['app_compile_product'];expected.append(dict(path='/usr/local/bin/otelcol-ebpf-profiler',bytes=app['bytes'],sha256=app['sha256']))
 cid=subprocess.check_output(['docker','create',TAG],text=True).strip();r['image_payload_verified']=[]
 try:
  for row in expected:
   cmd=subprocess.Popen(['docker','cp','-L',cid+':'+row['path'],'-'],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
   with tarfile.open(fileobj=cmd.stdout,mode='r|*') as t:
    m=next(m for m in t if m.isfile());f=t.extractfile(m);h=hashlib.sha256();head=f.read(20);h.update(head)
    for b in iter(lambda:f.read(1048576),b''):h.update(b)
   for rest in iter(lambda:cmd.stdout.read(1048576),b''):pass
   cmd.stdout.close();error=cmd.stderr.read();assert cmd.wait()==0,error;assert m.size==row['bytes'] and h.hexdigest()==row['sha256'] and int.from_bytes(head[18:20],'little')==183,row
   r['image_payload_verified'].append(dict(row,elf_machine=183))
 finally:subprocess.run(['docker','rm',cid],check=True,stdout=subprocess.DEVNULL)
 r['phase']='root-export';command=['make','-C',str(ROOT),'arm64-qemu-root','PLATFORM=qemu','ARCH=arm64','HOST_KERNEL_BUILD_DIR_ARM64='+str(K),'NATIVE_BPF_ARTIFACTS_ARM64='+str(ROOT/'vendor/build/native-bpf/arm64/stage'),'JOBS=2','-W',str(TAR),'-o',str(TAR)];r['root_command']=command;save()
 with (OUT/'root-export.log').open('wb') as f:r['root_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=child).returncode
 assert r['root_returncode']==0
 for row in expected:assert (BASE/row['path'].lstrip('/')).stat().st_size==row['bytes'] and sha(BASE/row['path'].lstrip('/'))==row['sha256'],row
 assert sha(BASE/'qemu-init')==sha(ROOT/'runner/scripts/qemu-arm64-init')
 r['protected_after']={str(p):sha(p) for p in paths};r['x86_image_after']=image('bpf-benchmark/kprog:current');assert r['protected_after']==r['protected_before'] and r['x86_image_after']==r['x86_image_before']
 if r['old_arm_image']!=r['new_arm_image']:
  retired=subprocess.run(['docker','image','rm',r['old_arm_image']],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);r['retirement']=dict(returncode=retired.returncode,output=retired.stdout)
  assert retired.returncode==0,retired.stdout
  with (ROOT/'kprog/docs/cleanup-log.md').open('a') as f:f.write('\n- '+now()+': PERF retired rebuildable ARM image '+r['old_arm_image']+' after canonical fixed-app image '+r['new_arm_image']+' and all five image/root payload hashes were verified. Existing user/root data remains archived at '+str(OUT.relative_to(ROOT)/'root-data-before.tar.gz')+'.\n')
 r.update(controller_status=0,phase='finished-fixed-app-work-check-pending')
except BlockingIOError:r.update(controller_status=75,phase='image-owner-active-resume-when-free')
except Exception:r.update(controller_status=1,phase='failed-receipts-retained',exception=traceback.format_exc())
finally:
 if lock is not None:fcntl.flock(lock,fcntl.LOCK_UN);lock.close()
 r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','image_returncode','root_returncode','exception']}),flush=True)
raise SystemExit(r['controller_status'])
