"""Finite paired verifier guest on the existing ARM kernel and root image."""
import fcntl
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import traceback
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');BASE=Path('/workspaces/.agent-state/kprog-ck')
manifest=Path(sys.argv[sys.argv.index('--manifest')+1]) if '--manifest' in sys.argv else LANE/'scalar-run.json'
run=json.loads(manifest.read_text());OUT=Path(run['result']);RAW=Path(run['raw']);pilot='--pilot' in sys.argv;mode='pilot' if pilot else 'all145'
record=dict(pid=os.getpid(),mode=mode,started_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip())
def save():(OUT/(mode+'-stock-controller.json')).write_text(json.dumps(record,indent=2)+'\n')
try:
 save();assert json.loads((OUT/'stock-build.json').read_text())['status']==0
 with (LANE.parent/'locks/timing').open('a') as timing,(LANE.parent/'locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX)
  qroot=ROOT/'.cache/qemu-arm64-root';init=qroot/'qemu-perf-scalar-init';status=RAW/(mode+'-guest-status')
  assert not status.exists(),'do not overwrite completed guest evidence'
  body='''#!/bin/sh
set -eu
mount -t proc proc /proc
mount -t sysfs sysfs /sys
if ! mountpoint -q /dev; then mount -t devtmpfs devtmpfs /dev; fi
mount -t tmpfs tmpfs /run
mount -t tmpfs tmpfs /tmp
mount -t tmpfs tmpfs /var/tmp
mount -t debugfs debugfs /sys/kernel/debug
mount -t bpf bpffs /sys/fs/bpf
mount -t 9p -o trans=virtio,version=9p2000.L,access=any workspace /workspaces
ulimit -l unlimited
export HOME=/root
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
status=0
insmod /workspaces/.agent-state/kprog-ck/verified-module/arm64/bpf_arm64_native_lab.ko || status=$?
if [ "$status" = 0 ]; then
 python3 /workspaces/repository/kprog/results/arm64-scalar-memory-20261127/stock.py RESULT MODE > RAW/guest-STAGE.stdout 2> RAW/guest-STAGE.stderr || status=$?
fi
printf '%s\\n' "$status" > STATUS
sync
echo o > /proc/sysrq-trigger
while :; do sleep 60; done
'''.replace('RESULT',str(OUT)).replace('MODE','--pilot' if pilot else '').replace('RAW',str(RAW)).replace('STAGE',mode).replace('STATUS',str(status))
  init.write_text(body);init.chmod(0o755);(OUT/(mode+'-init-script.txt')).write_text(body)
  kernel=BASE/'build-arm64/arch/arm64/boot/Image';module=BASE/'verified-module/arm64/bpf_arm64_native_lab.ko'
  record['kernel_sha256']=hashlib.sha256(kernel.read_bytes()).hexdigest();record['module_sha256']=hashlib.sha256(module.read_bytes()).hexdigest()
  command=['taskset','-c','16-19','qemu-system-aarch64','-M','virt','-cpu','cortex-a57','-smp','4','-m','8G','-nographic','-no-reboot','-kernel',str(kernel),'-fsdev','local,id=rootfs,path='+str(qroot)+',security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root','-fsdev','local,id=workspace,path=/workspaces,security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=workspace,mount_tag=workspace','-append','console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-perf-scalar-init loglevel=4 panic=30 oops=panic raid=noautodetect']
  record['command']=command;save()
  with (RAW/(mode+'-guest.log')).open('w') as log:r=subprocess.run(command,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT)
  record['qemu_returncode']=r.returncode;record['guest_status']=int(status.read_text());record['controller_status']=int(bool(r.returncode or record['guest_status']))
  record['stock']=json.loads((RAW/('pilot-stock.json' if pilot else 'stock.json')).read_text())
except Exception:record.update(controller_status=1,exception=traceback.format_exc())
finally:
 record['ended_utc']=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();save();print(json.dumps(record),flush=True)
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM scalar-memory '+mode+' paired stock guest ended status '+str(record['controller_status'])+'. Read '+str(OUT/(mode+'-stock-controller.json'))+' and raw verifier logs. Fresh-map acceptance is not live binding/native install or stage2 workload success.\n')
raise SystemExit(record['controller_status'])
