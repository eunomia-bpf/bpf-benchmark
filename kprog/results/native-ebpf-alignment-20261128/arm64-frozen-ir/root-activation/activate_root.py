"""Activate the sole ARM exported runtime root from its verified image, no guest."""
from pathlib import Path
import fcntl,hashlib,json,os,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');K=Path('/workspaces/.agent-state/kprog-ck/build-arm64');BASE=ROOT/'.cache/qemu-arm64-root';TAR=ROOT/'.cache/container-images/arm64-runner-runtime.image.tar';TAG='bpf-benchmark/runner-runtime:arm64'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def git(*args):return subprocess.check_output(['git',*args],cwd=ROOT)
def image(tag):return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}',tag],text=True).strip()
def check_archive(path,files):
 assert git('show','HEAD:'+str(path.relative_to(ROOT)))==path.read_bytes()
 with tarfile.open(path,'r:gz') as t:got={m.name:dict(bytes=m.size,sha256=hashlib.sha256(t.extractfile(m).read()).hexdigest()) for m in t.getmembers() if m.isfile()}
 assert got=={n:{k:v[k] for k in ['bytes','sha256']} for n,v in files.items()}
def protected():
 paths=[p for p in (ROOT/'vendor/build/native-bpf/arm64/stage').rglob('*') if p.is_file()]+[K/'arch/arm64/boot/Image',K/'arch/arm64/boot/vmlinuz.efi',K/'vmlinux',Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage')]
 return {str(p):sha(p) for p in paths}
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='preflight',scope='Existing ARM root activation only; no components/P/kernel/image rebuild, no guest/work/timing.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 os.sched_setaffinity(0,{16,18});save()
 with (LANE.parent/'locks/timing').open('a') as t,(LANE.parent/'locks/image').open('a') as i:
  fcntl.flock(t,fcntl.LOCK_SH);fcntl.flock(i,fcntl.LOCK_EX)
  assert BASE.resolve()==ROOT/'.cache/qemu-arm64-root' and not BASE.is_symlink()
  tmp=Path(str(BASE)+'.tmp');assert tmp.resolve()==ROOT/'.cache/qemu-arm64-root.tmp' and not tmp.exists() and not tmp.is_symlink()
  for p in Path('/proc').iterdir():
   if p.name.isdigit():
    try:exe=(p/'exe').readlink()
    except OSError:continue
    assert 'qemu-system-aarch64' not in exe.name,('active ARM guest',p.name)
  pre=json.loads((OUT/'preflight.json').read_text());old=json.loads((OUT.parent/'runtime-refresh/old-root-results-inventory.json').read_text());check_archive(ROOT/old['archive']['path'],old['files']);check_archive(ROOT/pre['additional_archive']['path'],pre['additional_files'])
  retained=dict(old['files']);retained.update(pre['additional_files']);checked=0
  for row in pre['checked_user_runtime_locations']:
   for d,ds,fs in os.walk(BASE/row['path'],followlinks=False):
    for n in fs:
     p=Path(d)/n
     if p.is_symlink() or not p.is_file():continue
     key=str(p.relative_to(BASE));h=sha(p)
     if key in retained:assert h==retained[key]['sha256'] and p.stat().st_size==retained[key]['bytes'],key
     else:assert key.startswith('workspaces/') and sha(Path('/'+key))==h,key
     checked+=1
  for key,v in retained.items():assert sha(BASE/key)==v['sha256'],key
  source=json.loads((OUT.parent/'runtime-refresh/controller.json').read_text());r.update(preflight_regular_files_rechecked=checked,preserved_files_rechecked=len(retained),protected_before=protected(),arm_image_before=image(TAG),x86_image_before=image('bpf-benchmark/kprog:current'),image_tar_sha256=sha(TAR),phase='root-export')
  assert r['arm_image_before']==source['new_arm_image'];save()
  command=['make','-C',str(ROOT),'arm64-qemu-root','PLATFORM=qemu','ARCH=arm64','HOST_KERNEL_BUILD_DIR_ARM64='+str(K),'NATIVE_BPF_ARTIFACTS_ARM64='+str(ROOT/'vendor/build/native-bpf/arm64/stage'),'JOBS=2','-W',str(TAR),'-o',str(TAR)];r['command']=command;save()
  with (OUT/'root-export.log').open('wb') as log:r['make_returncode']=subprocess.run(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
  assert r['make_returncode']==0;r['activated_payloads']=[]
  for row in source['image_payload_verified']:
   p=BASE/row['image_path'].lstrip('/');got=dict(path=row['image_path'],bytes=p.stat().st_size,sha256=sha(p),elf_machine=int.from_bytes(p.read_bytes()[18:20],'little'));assert got['bytes']==row['bytes'] and got['sha256']==row['sha256'] and got['elf_machine']==183;r['activated_payloads'].append(got)
  assert sha(BASE/'qemu-init')==sha(ROOT/'runner/scripts/qemu-arm64-init')
  r.update(protected_after=protected(),arm_image_after=image(TAG),x86_image_after=image('bpf-benchmark/kprog:current'))
  assert r['protected_before']==r['protected_after'] and r['arm_image_before']==r['arm_image_after'] and r['x86_image_before']==r['x86_image_after'] and sha(TAR)==r['image_tar_sha256']
  r.update(controller_status=0,phase='finished-guest-check-pending')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','make_returncode','exception']}),flush=True)
raise SystemExit(r['controller_status'])
