"""Run the configured-map regression against the actual collector dependency graph."""
from pathlib import Path
import fcntl,hashlib,io,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BASE=ROOT/'.cache/qemu-arm64-root';LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');APP=ROOT/'vendor/repos/opentelemetry-ebpf-profiler';MOD=ROOT/'vendor/build/otelcol-ebpf-profiler-build-arm64';K=Path('/workspaces/.agent-state/kprog-ck/build-arm64')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def image(tag):return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip()
def compile_child():
 resource.setrlimit(resource.RLIMIT_AS,(51539607552,51539607552));os.sched_setaffinity(0,{16,18})
def guest_child():os.sched_setaffinity(0,{16,18,19})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='preflight',scope='Actual collector graph test compilation and real ARM kernel-map regression; existing images, current kernel and native artifacts.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
lock=None;original={}
try:
 os.sched_setaffinity(0,{19});old=json.loads((OUT.parent/'controller.json').read_text());assert old['controller_status']==0
 for n,h in old['source_sha256'].items():assert sha(APP/n)==h,n
 r['app_source_commit']=subprocess.check_output(['git','rev-parse','HEAD'],cwd=APP,text=True).strip();assert r['app_source_commit']=='6cfd48e9705c263a89839d5e7b34c716d1cdfc27'
 paths=[Path(n) for n in old['protected_after']]+[Path(old['app_compile_product']['path']),MOD/'go.mod',MOD/'go.sum']
 r['protected_before']={str(p):sha(p) for p in paths};r['image_ids_before']={tag:image(tag) for tag in old['image_ids_after']};r['test_product_before']=old['integration_compile_product'];assert sha(Path(r['test_product_before']['path']))==r['test_product_before']['sha256']
 r['phase']='actual_graph_test_compile';save()
 with (OUT/'compile.log').open('wb') as f:r['compile_returncode']=subprocess.run(['bash',str(OUT/'build-actual-regression.sh')],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=compile_child).returncode
 assert r['compile_returncode']==0
 product=APP/'support/tracer.test';r['test_product']=dict(path=str(product),bytes=product.stat().st_size,sha256=sha(product),elf_machine=int.from_bytes(product.read_bytes()[18:20],'little'));assert r['test_product']['elf_machine']==183
 lock=(LANE.parent/'locks/image').open('a');r['phase']='image_shared_resource';save();fcntl.flock(lock,fcntl.LOCK_SH|fcntl.LOCK_NB)
 for proc in Path('/proc').iterdir():
  if proc.name.isdigit():
   try:exe=(proc/'exe').readlink()
   except OSError:continue
   assert 'qemu-system-aarch64' not in exe.name,('active ARM guest',proc.name)
 assert sha(BASE/'qemu-init')==sha(ROOT/'runner/scripts/qemu-arm64-init')
 r['original_init_sha256']=sha(BASE/'qemu-init');r['root_old_app_sha256']=sha(BASE/'usr/local/bin/otelcol-ebpf-profiler')
 original={n:(BASE/n).read_bytes() for n in ['qemu-run.sh','qemu-status']};r['guest_state_before']={n:dict(bytes=len(b),sha256=hashlib.sha256(b).hexdigest()) for n,b in original.items()}
 with tarfile.open(OUT/'guest-state-before.tar.gz','w:gz') as t:
  for n,b in original.items():
   m=tarfile.TarInfo(n);m.size=len(b);m.mode=0o755 if n.endswith('.sh') else 0o644;t.addfile(m,io.BytesIO(b))
 (BASE/'qemu-run.sh').write_bytes((OUT/'guest-run.sh').read_bytes());(BASE/'qemu-run.sh').chmod(0o755);(BASE/'qemu-status').write_text('')
 command=['qemu-system-aarch64','-M','virt','-cpu','cortex-a57','-smp','4','-m','8G','-nographic','-no-reboot','-kernel',str(K/'arch/arm64/boot/Image'),'-fsdev',f'local,id=rootfs,path={BASE},security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root','-fsdev',f'local,id=perfsource,path={ROOT},security_model=none,readonly=on,multidevs=remap','-device','virtio-9p-device,fsdev=perfsource,mount_tag=perf-source','-append','console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=4 panic=30 oops=panic raid=noautodetect']
 r['command']=command;r['phase']='guest';save()
 with (OUT/'guest.log').open('wb') as f:r['qemu_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=guest_child).returncode
 r['guest_status']=(BASE/'qemu-status').read_text().strip();(OUT/'guest-status.txt').write_text(r['guest_status']+'\n');text=(OUT/'guest.log').read_text(errors='replace');r['test_pass_observed']='--- PASS: TestLoadAllMapsInitializesConfiguredVariables' in text;r['test_skip_observed']='--- SKIP:' in text
 assert r['qemu_returncode']==0 and r['guest_status']=='0' and r['test_pass_observed'] and not r['test_skip_observed']
 r['protected_after']={str(p):sha(p) for p in paths};r['image_ids_after']={tag:image(tag) for tag in r['image_ids_before']};assert r['protected_before']==r['protected_after'] and r['image_ids_before']==r['image_ids_after']
 assert sha(BASE/'qemu-init')==r['original_init_sha256'];r.update(controller_status=0,phase='finished-kernel-map-regression-full-app-work-pending')
except Exception:r.update(controller_status=1,phase='failed-receipts-retained',exception=traceback.format_exc())
finally:
 for n,b in original.items():(BASE/n).write_bytes(b)
 if original:r['guest_state_restored']=all((BASE/n).read_bytes()==b for n,b in original.items())
 if lock is not None:fcntl.flock(lock,fcntl.LOCK_UN);lock.close()
 r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','compile_returncode','qemu_returncode','guest_status','test_pass_observed','exception']}),flush=True)
raise SystemExit(r['controller_status'])
