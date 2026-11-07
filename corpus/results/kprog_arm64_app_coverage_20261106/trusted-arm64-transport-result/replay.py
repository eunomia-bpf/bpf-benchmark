from pathlib import Path
import subprocess,os,json,hashlib,argparse
parser=argparse.ArgumentParser()
parser.add_argument('--rootfs',required=True)
args=parser.parse_args()
root=Path(__file__).resolve().parents[4];out=root/'kprog/arm64/build/trusted-transport';state=out
if not args.rootfs or not Path(args.rootfs).is_dir():raise ValueError('the existing ARM runtime root is required')
status=out/'guest-status'
if status.exists():raise RuntimeError('uncollected transport status already exists')
command=['taskset','-c','20-23','qemu-system-aarch64','-M','virt','-cpu','max','-smp','2','-m','2048','-nographic','-no-reboot',
 '-kernel',str(root/'vendor/build/arm64/linux/arch/arm64/boot/Image'),
 '-fsdev','local,id=rootfs,path='+str(Path(args.rootfs).resolve())+',security_model=none,readonly=on',
 '-device','virtio-9p-device,fsdev=rootfs,mount_tag=rootfs',
 '-fsdev','local,id=repo,path='+str(root)+',security_model=none',
 '-device','virtio-9p-device,fsdev=repo,mount_tag=repo',
 '-append','console=ttyAMA0 root=rootfs rootfstype=9p rootflags=trans=virtio,version=9p2000.L ro init=/bin/sh loglevel=4 panic=-1 oops=panic']
paths=['vendor/build/arm64/linux/arch/arm64/boot/Image','kinsn/module/arm64/build/bpf_arm64_native_lab.ko','kprog/arm64/build/trusted-transport/test-trusted-transport','kprog/tv/test_trusted_transport.c','kinsn/module/include/native_lab_trusted_wire.h']
(out/'inputs.json').write_text(json.dumps(dict(command=command,hashes={p:hashlib.sha256((root/p).read_bytes()).hexdigest() for p in paths}),indent=2)+'\n')
script='mount -t proc proc /proc && mount -t sysfs sysfs /sys && mount -t 9p -o trans=virtio repo /mnt && mount -t debugfs debugfs /sys/kernel/debug && insmod /mnt/kinsn/module/arm64/build/bpf_arm64_native_lab.ko && /mnt/kprog/arm64/build/trusted-transport/test-trusted-transport /sys/kernel/debug/bpf_arm64_native_lab\nrc=$?\necho "$rc" >/mnt/kprog/arm64/build/trusted-transport/guest-status\nsync\necho 1 >/proc/sys/kernel/sysrq\necho o >/proc/sysrq-trigger\n/sbin/poweroff -f\n'
p=subprocess.Popen(command,stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
(out/'qemu.pid').write_text(str(p.pid)+'\n');sent=False;tail=b''
with (state/'console.log').open('wb') as log:
 while True:
  chunk=os.read(p.stdout.fileno(),8192)
  if not chunk:break
  log.write(chunk);log.flush();tail=(tail+chunk)[-4096:]
  if not sent and tail.endswith(b'# '):
   p.stdin.write(script.encode());p.stdin.flush();sent=True
 rc=p.wait()
result=dict(qemu_exit=rc,commands_sent=sent,guest_status=int(status.read_text()) if status.exists() else None)
(out/'result.json').write_text(json.dumps(result,indent=2)+'\n');(state/'exit').write_text(str(0 if result['guest_status']==0 else 1)+'\n')
print(json.dumps(result),flush=True)

raise SystemExit(0 if result['guest_status']==0 and result['qemu_exit']==0 else 1)
