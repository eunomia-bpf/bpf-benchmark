"""Package selected real-section proof diagnostics; never replace app startup."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
phase=Path(sys.argv[1]).resolve()
base=Path(sys.argv[2]).resolve()
build=ROOT/'kprog/arm64/build/app-coverage'/phase.name
root=build/'root'
root.mkdir(parents=True)
with base.open('rb') as source:
    unpack=subprocess.run(['gzip','-dc'],stdin=source,capture_output=True,check=True)
subprocess.run(['cpio','-id','--quiet','--no-absolute-filenames','bin/busybox','dev/console'],
               cwd=root,input=unpack.stdout,check=True)
for name in ['proc','sys','results','objects','tmp']: (root/name).mkdir()
(root/'bin/sh').symlink_to('busybox')
shutil.copy2(HERE/'verify-proof',root/'verify-proof')
script=['#!/bin/sh','export PATH=/bin','busybox mount -t proc proc /proc || exit 1',
        'busybox mount -t sysfs sysfs /sys || exit 1',
        'busybox mount -t 9p -o trans=virtio results /results || exit 1',
        'ulimit -l unlimited || exit 1','status=0']
for row in coverage.records(phase):
    name=row['name']
    compiled=json.loads((phase/'compile'/(name+'.json')).read_text())
    if compiled['returncode']: raise RuntimeError(f'uncompiled proof: {name}')
    shutil.copy2(phase/'objects'/(name+'.bpf.o'),root/'objects')
    script += [f'echo load {name}',
       f'busybox timeout 600 /verify-proof /objects/{name}.bpf.o {name}_arm64_sim_xdp /results/{name}.verifier.log >/results/{name}.stdout 2>/results/{name}.stderr',
       'rc=$?',f'echo "$rc" >/results/{name}.rc','if [ "$rc" != 0 ]; then status=1; fi']
script += ['echo "$status" >/results/guest-status','busybox sync','busybox poweroff -f']
(root/'init').write_text('\n'.join(script)+'\n');(root/'init').chmod(0o755)
files='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
archive=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=files.encode(),capture_output=True,check=True)
with (build/'initramfs.cpio.gz').open('wb') as out:
    subprocess.run(['gzip','-c'],input=archive.stdout,stdout=out,check=True)
print('all23 real BCC proof sections/maps packaged for default-map load-only diagnostics')
