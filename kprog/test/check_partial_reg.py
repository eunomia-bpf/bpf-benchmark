"""Collect stock-verifier outcomes for all partial-register lane regressions."""
import json
from pathlib import Path
import subprocess
import sys

root, output = map(Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
rows = []
for phase, directory in [('before', 'before-retry1'), ('after', 'after')]:
    for lane in [0, 8, 16]:
        command = ['bpftool', '-d', 'prog', 'load', str(root / directory / f'lane{lane}.bpf.o'),
                   f'/sys/fs/bpf/verified_partial_{phase}_{lane}', 'type', 'kprobe']
        done = subprocess.run(command, capture_output=True, text=True)
        (output / f'{phase}-lane{lane}.stdout').write_text(done.stdout)
        (output / f'{phase}-lane{lane}.stderr').write_text(done.stderr)
        rows.append(dict(phase=phase, lane=lane, command=command, returncode=done.returncode))
(output / 'observations.json').write_text(json.dumps(rows, indent=2) + '\n')
print(json.dumps(rows), flush=True)
if any(row['returncode'] for row in rows if row['phase'] == 'after'):
    raise SystemExit('partial-register candidate stock verification failed; complete logs retained')
if any(row['returncode'] == 0 for row in rows if row['phase'] == 'before'):
    raise SystemExit('baseline scalar-range observation differs; complete logs retained')
