"""Compare stock-verifier outcomes for the generic signed32 clip regression."""
import json
from pathlib import Path
import subprocess
import sys

before, after, output = map(Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
results = []
for label, program in [('before', before), ('after', after)]:
    command = ['bpftool', '-d', 'prog', 'load', str(program),
               '/sys/fs/bpf/verified_signed_' + label, 'type', 'kprobe']
    done = subprocess.run(command, capture_output=True, text=True)
    (output / (label + '.stdout')).write_text(done.stdout)
    (output / (label + '.stderr')).write_text(done.stderr)
    results.append(dict(label=label, command=command, returncode=done.returncode))
(output / 'observations.json').write_text(json.dumps(results, indent=2) + '\n')
print(json.dumps(results), flush=True)
if results[1]['returncode']:
    raise SystemExit('signed32 candidate stock verification failed; complete stderr retained')
if not results[0]['returncode'] or 'unbounded memory access' not in (output / 'before.stderr').read_text():
    raise SystemExit('baseline outcome differs from the expected scalar-range regression; complete stderr retained')
