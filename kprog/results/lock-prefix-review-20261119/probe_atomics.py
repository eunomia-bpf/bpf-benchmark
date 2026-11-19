"""Record native/BPF lowering of the indivisible old-value boundary."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
out = Path(sys.argv[1])
build = Path(sys.argv[2])
source = root / 'kprog/results/lock-prefix-review-20261119/atomic.c'
out.mkdir(parents=True, exist_ok=True)
build.mkdir(parents=True, exist_ok=True)
cases = []
for target in ['x86_64-unknown-linux-gnu', 'bpfel']:
    for width in [8, 16, 32, 64]:
        for operation in ['fetch-add', 'compare-exchange']:
            name = f'{target}-{width}-{operation}'
            command = ['clang-18', '-target', target, '-O3', '-ffreestanding',
                       '-S', '-DWIDTH=' + str(width), str(source),
                       '-o', str(build / 'atomic.s')]
            if operation == 'fetch-add':
                command.append('-DFETCH_ADD')
            compiled = subprocess.run(command, text=True, capture_output=True)
            (out / (name + '.stdout')).write_text(compiled.stdout)
            (out / (name + '.stderr')).write_text(compiled.stderr)
            assembly = None
            if compiled.returncode == 0:
                assembly = (build / 'atomic.s').read_text()
                (out / (name + '.s')).write_text(assembly)
            cases.append(dict(target=target, width=width, operation=operation,
                              command=command, returncode=compiled.returncode,
                              assembly=assembly))
            (out / 'atomic-lowering.json').write_text(
                json.dumps(dict(cases=cases), indent=2) + '\n')
            print(name, compiled.returncode, flush=True)

# A backend failure at another width is evidence to retain, not a plain-RMW
# replacement. These are the actual BPF atomic widths the implementation needs.
assert all(case['returncode'] == 0 for case in cases
           if case['target'].startswith('x86_64') or case['width'] in [32, 64])
