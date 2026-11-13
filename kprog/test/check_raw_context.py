"""Observe flat raw-context loads through both generic simulator read routes."""
import json
from pathlib import Path
import subprocess
import sys

root, output, bpftool = map(Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
rows = []
for phase in ['before-scalar', 'after-scalar']:
    for route in [0, 1]:
        command = [str(bpftool), '-d', 'prog', 'load', str(root / phase / f'route{route}.bpf.o'),
                   f'/sys/fs/bpf/verified_context_{phase}_{route}', 'type', 'kprobe']
        done = subprocess.run(command, capture_output=True, text=True)
        (output / f'{phase}-route{route}.stdout').write_text(done.stdout)
        (output / f'{phase}-route{route}.stderr').write_text(done.stderr)
        rows.append(dict(phase=phase, route=route, command=command, returncode=done.returncode))
(output / 'observations.json').write_text(json.dumps(rows, indent=2) + '\n')
print(json.dumps(rows), flush=True)
if any(row['returncode'] for row in rows if row['phase'] == 'after-scalar'):
    raise SystemExit('raw-context candidate stock verification failed; complete logs retained')
if any(row['returncode'] == 0 for row in rows if row['phase'] == 'before-scalar'):
    raise SystemExit('baseline context observation differs; complete logs retained')
