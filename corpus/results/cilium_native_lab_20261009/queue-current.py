#!/usr/bin/env python3
"""Start current only after all historical invocations and the guest lock close."""
import fcntl
import json
from pathlib import Path
import subprocess
import sys
import time

root=Path(__file__).resolve().parent
last=root/'paper/pair-05-stats-0-control/exit.json'
while not last.exists():
    if (root/'reboot-state.json').exists() and len(json.loads((root/'reboot-state.json').read_text())['reboots'])>=2:
        raise SystemExit('second host restart: current queue stopped')
    time.sleep(5)
with open('/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/guest-execution.lock')as lock:
    fcntl.flock(lock,fcntl.LOCK_EX)
    fcntl.flock(lock,fcntl.LOCK_UN)
for path in (root/'paper').glob('*/exit.json'):
    data=json.loads(path.read_text())
    if data['exit_code'] or data['app_errors']:
        raise SystemExit('historical invocation failed: '+str(path))
with (root/'current-series.log').open('w') as log:
    result=subprocess.run(['python3',str(root/'run-series.py'),'current','/workspaces/repository'],stdout=log,stderr=subprocess.STDOUT)
(root/'current-series-exit.json').write_text(json.dumps({'exit_code':result.returncode,'finished':time.time()})+'\n')
sys.exit(result.returncode)
