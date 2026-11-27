"""Finite current-root ARM frozen-corpus check through the registered service."""
import fcntl
import json
import os
from pathlib import Path
import subprocess
import shlex
import sys
import time
import traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
BASE=Path('/workspaces/.agent-state/kprog-ck');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
APP=sys.argv[1] if len(sys.argv)>1 else 'bcc/set'
def now():return subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip()
token=subprocess.check_output(['date','-u','+%Y%m%dT%H%M%SZ'],text=True).strip()
OUT=HERE/('guest-'+token);OUT.mkdir()
RAW=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127')/token;RAW.mkdir(parents=True)
record=dict(started_utc=now(),pid=os.getpid(),raw=str(RAW),revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
 app=APP, scope=f'Frozen {APP} corpus workload, baseline and registered checked native post phase; one10second functional sample withstats. Cortex-A57 fourCPUs/eightGiB matches current ARM entry. Diagnostic only, full timing frozen.')
record['run_token']=os.urandom(4).hex()
def save():(OUT/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
status=1;broker=None
try:
 save()
 with Path('/workspaces/.agent-state/kprog-lanes/locks/timing').open('a') as timing,Path('/workspaces/.agent-state/kprog-lanes/locks/image').open('a') as image:
  fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_EX)
  qroot=ROOT/'.cache/qemu-arm64-root'
  init=qroot/'qemu-perf-checked-init'
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
install -d /run/host-python
mount -t 9p -o trans=virtio,version=9p2000.L,access=any hostpython /run/host-python
install -d /run/checked-python
ln -s /run/host-python/elftools /run/checked-python/elftools
ulimit -l unlimited
export HOME=/root
export PATH=/usr/lib/llvm-18/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
export PYTHONPATH=/workspaces/repository:/run/checked-python
export CLANG=/workspaces/repository/kprog/stock-path/bin/clang
export KPROG_ARM64_SYSROOT=/workspaces/repository/.cache/qemu-arm64-root
export KPROG_TRUSTED_COMPILE_STATE=RAW_PATH/broker
export BPFREJIT_INSIDE_RUNTIME_CONTAINER=1
export TARGET=arm64-qemu RUN_TARGET_NAME=arm64-qemu RUN_TARGET_ARCH=arm64 RUN_EXECUTOR=kvm
export RUN_TOKEN=CORPUS_TOKEN RUN_REMOTE_PYTHON_BIN=python3 RUN_RUNTIME_PYTHON_BIN=python3 RUN_BPFTOOL_BIN=bpftool
export RUN_NATIVE_REPOS_CSV=bcc,katran,tracee,tetragon ETCD_UNSUPPORTED_ARCH=arm64
status=0
cd /workspaces/repository
python3 kprog/results/arm64-checked-corpus-20261127/guest.py RAW_PATH APP_ARG || status=$?
printf '%s\\n' "$status" > RAW_PATH/guest-status
sync
echo o > /proc/sysrq-trigger
while :; do sleep 60; done
'''.replace('RAW_PATH',str(RAW)).replace('CORPUS_TOKEN',record['run_token']).replace('APP_ARG',shlex.quote(APP))
  init.write_text(body);init.chmod(0o755)
  (OUT/'init-script.txt').write_text(body)
  state=RAW/'broker';broker_cmd=['prlimit','--as=17179869184','taskset','-c','16','python3',str(ROOT/'kprog/trusted_compile.py'),'serve','--scope',str(RAW),'--state',str(state),'--clang',str(ROOT/'kprog/stock-path/bin/clang'),'--arm64-sysroot',str(ROOT/'.cache/qemu-arm64-root')]
  record['broker_command']=broker_cmd;save()
  env=dict(os.environ,QEMU_LD_PREFIX=str(qroot))
  broker_log=(RAW/'broker.log').open('w')
  broker=subprocess.Popen(broker_cmd,cwd=ROOT,env=env,stdout=broker_log,stderr=subprocess.STDOUT)
  while not (state/'ready.json').exists():
   if broker.poll() is not None:raise RuntimeError('host broker exited before ready')
   time.sleep(0.05)
  command=['taskset','-c','16-19','qemu-system-aarch64','-M','virt','-cpu','cortex-a57','-smp','4','-m','8G','-nographic','-no-reboot',
   '-kernel',str(BASE/'build-arm64/arch/arm64/boot/Image'),
   '-fsdev','local,id=rootfs,path='+str(qroot)+',security_model=none,multidevs=remap',
   '-device','virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root',
   '-fsdev','local,id=workspace,path=/workspaces,security_model=none,multidevs=remap',
   '-device','virtio-9p-device,fsdev=workspace,mount_tag=workspace',
   '-fsdev','local,id=hostpython,path=/usr/lib/python3/dist-packages,security_model=none,multidevs=remap,readonly=on',
   '-device','virtio-9p-device,fsdev=hostpython,mount_tag=hostpython',
   '-append','console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-perf-checked-init loglevel=4 panic=30 oops=panic raid=noautodetect']
  record.update(guest_command=command,guest_started_utc=now());save()
  with (RAW/'guest.log').open('w') as log:r=subprocess.run(command,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
  record['qemu_returncode']=r.returncode
  status=int((RAW/'guest-status').read_text())
  if r.returncode:status=1
  record['cases']=json.loads((RAW/'cases.json').read_text())
except Exception:record['exception']=traceback.format_exc()
finally:
 if broker is not None:
  (RAW/'broker/STOP').write_text('finite guest complete\n')
  try:record['broker_returncode']=broker.wait(timeout=10)
  except subprocess.TimeoutExpired:
   broker.terminate();record['broker_returncode']=broker.wait();record['broker_cleanup']='terminated after STOP timeout';status=1
  broker_log.close()
 record.update(controller_status=status,ended_utc=now());save()
 try:
  with (OUT/'archive.log').open('w') as log:
   commands=[['tar','-C',str(RAW.parent),'-cf','-',RAW.name],['zstd','-T1','-3','-c'],['split','-b','48000000','-',str(OUT/'evidence.tar.zst.part-')]]
   a=subprocess.Popen(commands[0],stdout=subprocess.PIPE,stderr=log);b=subprocess.Popen(commands[1],stdin=a.stdout,stdout=subprocess.PIPE,stderr=log);a.stdout.close();c=subprocess.Popen(commands[2],stdin=b.stdout,stderr=log);b.stdout.close()
   codes=[c.wait(),b.wait(),a.wait()][::-1]
  record.update(archive_commands=commands,archive_returncodes=codes);save()
  if any(codes):raise RuntimeError('raw archive failed')
  with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('a') as lock,(OUT/'publication.log').open('a') as log:
   fcntl.flock(lock,fcntl.LOCK_EX)
   path=str(OUT.relative_to(ROOT))
   for cmd in [['git','add','-f','--',path],['git','commit','--only','-m',f'Record actual ARM checked {APP} corpus check','--',path],['git','push']]:subprocess.run(cmd,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT,check=True)
 except Exception:record['publication_error']=traceback.format_exc();status=1;record['controller_status']=status;save()
 with (LANE/'resume-msg.md').open('a') as f:f.write(f'\nARM checked {APP} corpus check ended status {status}. Read {OUT}/controller.json, publication.log and archived/raw per-case service/verifier/TEST_RUN records; record actual baseline/post workload and per-program stock/checked/direct outcomes, fix real within-design failures. Full timing stays frozen.\n')
 stop=LANE/'STOP'
 if stop.exists() and stop.read_text().startswith('PERF ARM checked corpus:'):stop.unlink()
raise SystemExit(status)
