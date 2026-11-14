#!/usr/bin/env python3
"""Replay captured B compilation with the generated-C warning fix.

This compiles B through frontend, bounds and BPF backend only. It does not
submit B to the stock verifier, compile native code, or accept an application.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('command', type=Path)
p.add_argument('output', type=Path)
p.add_argument('--cpus', default='16-19')
p.add_argument('--bounds', type=Path, required=True)
a = p.parse_args()
a.output.mkdir(parents=True, exist_ok=True)
def stamp():
    return datetime.now(timezone.utc).isoformat()
base = json.loads(a.command.read_text())
base[base.index('taskset') + 2] = a.cpus
if '-w' not in base:
    base.insert(base.index('-g'), '-w')
compile_input = len(base) - 1 - base[::-1].index('-c') + 1
source = Path(base[compile_input])
h = hashlib.sha256()
with source.open('rb') as f:
    for block in iter(lambda: f.read(1 << 20), b''):
        h.update(block)
(a.output / 'input.json').write_text(json.dumps(dict(path=str(source), bytes=source.stat().st_size,
    sha256=h.hexdigest(), command_source=str(a.command)), indent=2) + '\n')
base[-1] = str(a.output / 'trusted_x86.bpf.bounds-input.bc')
bounds = base[:base.index('--') + 1] + [str(a.bounds), base[-1], '-o', str(a.output / 'trusted_x86.bpf.bounds.bc')]
backend = list(base)
backend.remove('-emit-llvm')
backend[compile_input] = bounds[-1]
backend[-1] = str(a.output / 'trusted_x86.bpf.o')
commands = [('frontend', base), ('bounds', bounds), ('bpf-backend', backend)]
(a.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
results = []
for stage, command in commands:
    (a.output / 'current-stage.json').write_text(json.dumps(dict(stage=stage, started=stamp(), command=command)) + '\n')
    start = time.monotonic()
    with (a.output / (stage + '.log')).open('wb') as log:
        child = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
        pid, status, usage = os.wait4(child.pid, 0)
        child.returncode = os.waitstatus_to_exitcode(status)
    row = dict(stage=stage, child_pid=pid, returncode=child.returncode,
        wall_seconds=time.monotonic()-start, user_seconds=usage.ru_utime,
        system_seconds=usage.ru_stime, max_rss_kib=usage.ru_maxrss)
    results.append(row)
    (a.output / 'resource.json').write_text(json.dumps(results, indent=2) + '\n')
    print(json.dumps(row), flush=True)
    if child.returncode:
        break
(a.output / 'finished').write_text(stamp() + '\n')
raise SystemExit(results[-1]['returncode'])
