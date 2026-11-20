"""Observe the frozen guest run without changing its workload or lifecycle."""
import json
from pathlib import Path
import subprocess
import sys
import time

out, app = Path(sys.argv[1]), sys.argv[2]
root = Path('/workspaces/repository')
here = root/'kprog/results/runtime-profile-20261120'
Path('/proc/sys/kernel/kptr_restrict').write_text('0\n')
Path('/proc/sys/net/core/bpf_jit_kallsyms').write_text('1\n')
command = ['make', '-f', 'kprog/perf/one-image/Makefile', 'guest',
           'APPS='+app, 'SAMPLES=1', 'WORKLOAD_DURATION=60',
           'BPFREJIT_CORPUS_BPF_STATS=1', 'NATIVE_LOADER_MODE=post']
with (out/'guest.log').open('w') as log:
    child = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT, cwd=root)
with (out/'guest.log').open() as log:
    while True:
        line = log.readline()
        if not line:
            if child.poll() is not None:
                break
            time.sleep(0.2)
            continue
        if not line.startswith('{'):
            continue
        event = json.loads(line)
        if event.get('event') not in {'measurement_start', 'measurement_done'}:
            continue
        phase = event['phase']
        suffix = 'start' if event['event'] == 'measurement_start' else 'end'
        (out/f'{phase}.{suffix}.clock.json').write_text(json.dumps(dict(
            wall_ns=time.time_ns(), monotonic_ns=time.monotonic_ns()))+'\n')
        (out/f'{phase}.{suffix}.kallsyms').write_text(Path('/proc/kallsyms').read_text())
        if suffix == 'start':
            with (out/f'{phase}.jit.log').open('w') as errors:
                result = subprocess.run([sys.executable, here/'jit.py',
                    out/f'{phase}.jit.json'], stdout=errors, stderr=subprocess.STDOUT)
            (out/f'{phase}.jit.exit-code').write_text(str(result.returncode)+'\n')
code = child.wait()
(out/'guest-exit-code').write_text(str(code)+'\n')
sys.exit(code)
