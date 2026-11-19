"""Compare equivalent shared-I memory accesses before altering their code."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
out, build = map(Path, sys.argv[1:])
out.mkdir(parents=True, exist_ok=True)
build.mkdir(parents=True, exist_ok=True)
commands = []


def run(command):
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
    return result.stdout


run(['clang-18', '-O3', '-mno-red-zone',
     '-I' + str(root / 'vendor/libbpf/src'),
     '-I' + str(root / 'vendor/libbpf/include/uapi'),
     str(root / 'kprog/results/released-alias-20261119/reproduce.c'),
     '-o', str(build / 'reproduce')])
observations = json.loads(run([str(build / 'reproduce')]))
groups = {}
for case in observations['cases']:
    groups.setdefault((case['family'], case['released'], case['width']), []).append(case)
differences = []
for key, cases in groups.items():
    expected = next(case for case in cases if case['address_mode'] == 0)
    if any((case['value'], case['input_visits']) !=
           (expected['value'], expected['input_visits']) for case in cases):
        differences.append(dict(family=key[0], released=key[1], width=key[2], cases=cases))
summary = dict(**observations, differences=differences,
               scope='Shared C value/input-visit regression. No stock, app or runtime claim.')
(out / 'result.json').write_text(json.dumps(summary, indent=2) + '\n')
print(f"{len(observations['cases'])} observations; {len(differences)} unequal address-form groups", flush=True)
print(f"{len(observations['nonstack'])} ordinary reads and {len(observations['faults'])} physical-fault ordering cases passed", flush=True)
assert not differences, 'Equivalent released-stack address forms differ in value or input observations'
