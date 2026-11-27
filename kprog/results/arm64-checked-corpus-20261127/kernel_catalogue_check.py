"""Finite real-ARM production symbol/parser binding check; no native install claim."""
import fcntl,hashlib,json,os,shlex,subprocess,tarfile,time,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');BASE=Path('/workspaces/.agent-state/kprog-ck')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
stamp=now();token=stamp.replace('-','').replace(':','');out=HERE/('kernel-catalogue-check-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/arm64-kernel-catalogue-20261127')/token;raw.mkdir(parents=True)
record=dict(pid=os.getpid(),started_utc=stamp,raw=str(raw),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),phase='compile',controller_status=None,commands=[],scope='Production CPP parser and build_native_link_args, crosscompiled with existing ARM loader flags, checked against the actual one boot kernel. No test mocks, kernel/helper modifications, app workload or native installation acceptance.')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save():(out/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
def command(args,name,cpu='16',cwd=ROOT):
 cmd=['prlimit','--as=51539607552','taskset','-c',cpu,*map(str,args)];begin=time.monotonic()
 with (raw/(name+'.stdout')).open('wb') as a,(raw/(name+'.stderr')).open('wb') as b:r=subprocess.run(cmd,cwd=cwd,stdin=subprocess.DEVNULL,stdout=a,stderr=b)
 record['commands'].append(dict(command=cmd,returncode=r.returncode,wall_seconds=time.monotonic()-begin));save();assert r.returncode==0,name
(LANE/'kernel-catalogue-check.json').write_text(json.dumps(dict(result=str(out),pid=os.getpid()))+'\n')
try:
 save()
 with (LANE.parent/'locks/timing').open('a') as timing,(LANE.parent/'locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX)
  source=HERE/'kernel_catalogue_check.cpp';build=ROOT/'runner/build-arm64-llvmbpf/native_loader'
  flags={}
  for line in (build/'CMakeFiles/native_loader.dir/flags.make').read_text().splitlines():
   if ' = ' in line:
    k,v=line.split(' = ',1);flags[k]=shlex.split(v)
  record['source_sha256']={str(p.relative_to(ROOT)):sha(p) for p in [source,Path(__file__),ROOT/'kprog/libnativeloader/src/native_loader_trusted.cpp',ROOT/'kprog/libnativeloader/src/native_loader_lto.hpp',ROOT/'kprog/libnativeloader/src/native_loader_trusted_link_schema.hpp']}
  command(['/usr/bin/aarch64-linux-gnu-g++',*flags['CXX_DEFINES'],*flags['CXX_INCLUDES'],*flags['CXX_FLAGS'],'-ffunction-sections','-fdata-sections','-c',source,'-o',raw/'check.o'],'compile')
  link=shlex.split((build/'CMakeFiles/trusted-native-loader.dir/link.txt').read_text());oi=link.index('-o');link[oi-1]=str(raw/'check.o');link[oi+1]=str(raw/'check');link.insert(1,'-Wl,--gc-sections')
  command(link,'link',cwd=build);record['test_binary_sha256']=sha(raw/'check')
  record['phase']='guest';save();qroot=ROOT/'.cache/qemu-arm64-root';init=qroot/'qemu-perf-catalogue-init'
  body='''#!/bin/sh
set -eu
mount -t proc proc /proc
mount -t sysfs sysfs /sys
if ! mountpoint -q /dev; then mount -t devtmpfs devtmpfs /dev; fi
mount -t 9p -o trans=virtio,version=9p2000.L,access=any workspace /workspaces
status=0
RAW/check > RAW/check.stdout 2> RAW/check.stderr || status=$?
grep -E ' (ktime_get_mono_fast_ns|jiffies_64|copy_from_user_nofault|copy_from_kernel_nofault)$' /proc/kallsyms > RAW/boot-symbols.txt
printf '%s\\n' "$status" > RAW/guest-status
sync
echo o > /proc/sysrq-trigger
while :; do sleep 60; done
'''.replace('RAW',str(raw))
  init.write_text(body);init.chmod(0o755);(out/'init-script.txt').write_text(body)
  kernel=BASE/'build-arm64/arch/arm64/boot/Image';record['kernel_sha256']=sha(kernel);save()
  args=['taskset','-c','16-19','qemu-system-aarch64','-M','virt','-cpu','cortex-a57','-smp','4','-m','8G','-nographic','-no-reboot','-kernel',str(kernel),'-fsdev','local,id=rootfs,path='+str(qroot)+',security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root','-fsdev','local,id=workspace,path=/workspaces,security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=workspace,mount_tag=workspace','-append','console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-perf-catalogue-init loglevel=4 panic=30 oops=panic raid=noautodetect']
  record['guest_command']=args;save()
  with (raw/'guest.log').open('wb') as log:record['qemu_returncode']=subprocess.run(args,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT).returncode
  assert record['qemu_returncode']==0
  record['guest_status']=int((raw/'guest-status').read_text());assert record['guest_status']==0
  result=json.loads((raw/'check.stdout').read_text());boot={line.split()[2]:int(line.split()[0],16) for line in (raw/'boot-symbols.txt').read_text().splitlines()}
  assert result['status']==0 and result['symbols']==boot and len(boot)==4
  record['result']=result;record['boot_symbols']=boot
 record.update(controller_status=0,phase='finished')
except Exception:record.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM production kernel-symbol catalogue check ended status '+str(record['controller_status'])+'. Read '+str(out/'controller.json')+' and raw logs. Binding validation is separate from original Tetragon native installation/startup.\n')
 print(json.dumps(record),flush=True)
raise SystemExit(record['controller_status'])
