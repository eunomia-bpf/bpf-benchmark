#!/usr/bin/env python3
"""Read-only program/map/attachment capture around Make's corpus phases."""
import json
from pathlib import Path
import shlex
import subprocess
import sys
import time

root = Path(sys.argv[1])
root.mkdir(parents=True, exist_ok=True)
docker = ('docker run --cpuset-cpus=2,3 --rm --privileged --pid=host --network=host '
          '--ipc=host --cgroupns=host -e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 -e HOME=/root '
          '$(RUNTIME_ENV) -w "$(ROOT_DIR)" $(RUNTIME_MOUNTS)')
audit_root = Path(__file__).parent
docker += (' -v '+shlex.quote(str(audit_root)+':/audit')+' -e '+shlex.quote('CILIUM_AUDIT_RUN=/audit/'+str(root.relative_to(audit_root)))+' -e '+shlex.quote('PYTHONPATH=/audit:'+str(Path.cwd())))
command = (root/'make-input.txt').read_text().strip() + ' ' + shlex.quote('RUNTIME_DOCKER=' + docker)
(root/'guest-command.txt').write_text(command+'\n')
(root/'guest-host.txt').write_text(subprocess.check_output(
    ['sh','-c','date -u; uname -a; cat /proc/sys/kernel/random/boot_id; cat /proc/cpuinfo'], text=True))
proc = subprocess.Popen(['sh','-c',command], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, bufsize=1)
with (root/'guest.log').open('w') as log:
    for line in proc.stdout:
        log.write(line); log.flush(); print(line, end='', flush=True)
code = proc.wait()
(root/'guest-exit.json').write_text(json.dumps({'corpus_exit':code})+'\n')
sys.exit(code)
