"""One paired run, captured with host guest-only PMU sampling."""
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys
import time

out, app = Path(sys.argv[1]).resolve(), sys.argv[2]
root = Path('/workspaces/repository')
base = Path('/workspaces/.agent-state/kprog-ck')
here = root/'kprog/results/runtime-profile-20261120'
state = Path('/var/tmp/kprog-tmp/perf/runtime-profile')
out.mkdir(parents=True, exist_ok=True)
state.mkdir(parents=True, exist_ok=True)
for name, target in [('runtime.image.tar', root/'.cache/container-images/x86_64-runner-runtime.image.tar'),
                     ('bpf_x86_native_lab.ko', root/'kinsn/module/x86/build/bpf_x86_native_lab.ko')]:
    link = state/name
    if not link.is_symlink():
        link.symlink_to(target)
command = [str(base/'perf/perf'), 'record', '-a', '-g', '-C', '20-23',
    '-e', 'cycles:G', '-F', '199', '--clockid', 'monotonic', '-o', str(out/'host.data'), '--',
    'taskset', '-c', '20-23', 'vng', '--run', str(base/'build-x86/arch/x86/boot/bzImage'),
    '--cwd', str(root), '--rwdir', str(root), '--rwdir', str(out),
    '--rwdir', '/var/tmp='+str(state), '--overlay-rwdir', '/tmp',
    '--overlay-rwdir', '/run', '--overlay-rwdir', '/usr/local', '--disable-monitor',
    '--cpus', '4', '--memory', '32G', '--append', 'loglevel=4 panic=30 oops=panic',
    '--exec', f'python3 {here}/guest.py {out} {app}']
record = dict(command=command, app=app, source_commit=subprocess.check_output(
    ['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
    pid=os.getpid(), scope='Paired 60-second profiling diagnostic, not official timing.')
(out/'command.json').write_text(json.dumps(record, indent=2)+'\n')
with open('/workspaces/.agent-state/kprog-lanes/locks/image', 'a') as image:
    fcntl.flock(image, fcntl.LOCK_SH)
    (out/'host.start.clock.json').write_text(json.dumps(dict(
        wall_ns=time.time_ns(), monotonic_ns=time.monotonic_ns()))+'\n')
    with (out/'host.log').open('w') as log:
        code = subprocess.run(command, cwd=root, stdout=log, stderr=subprocess.STDOUT).returncode
    (out/'host.end.clock.json').write_text(json.dumps(dict(
        wall_ns=time.time_ns(), monotonic_ns=time.monotonic_ns()))+'\n')
(out/'exit-code').write_text(str(code)+'\n')
disk = state/'bpf-benchmark-docker.img'
if disk.exists():
    disk.unlink()
    with (root/'kprog/docs/cleanup-log.md').open('a') as log:
        log.write(time.strftime('- %Y-%m-%dT%H:%M:%SZ PERF runtime profile: ', time.gmtime())+
                  f'removed completed guest container-store build {disk}; raw data kept at {out}.\n')
sys.exit(code)
