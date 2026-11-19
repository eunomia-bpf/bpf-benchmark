"""Compile and run actual shared-I atomics against hardware and concurrency."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
out, build = map(Path, sys.argv[1:])
out.mkdir(parents=True, exist_ok=True)
build.mkdir(parents=True, exist_ok=True)
commands = []
for args in [
    ['clang-18', '-O3', '-mno-red-zone', '-pthread',
     '-I' + str(root / 'vendor/libbpf/src'),
     '-I' + str(root / 'vendor/libbpf/include/uapi'),
     str(root / 'kprog/results/lock-prefix-review-20261119/shared.c'),
     '-o', str(build / 'shared')],
    [str(build / 'shared')],
]:
    result = subprocess.run(args, text=True, capture_output=True)
    commands.append(dict(command=args, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out / 'shared-commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    print(result.stdout, end='', flush=True)
    if result.returncode:
        print(result.stderr, end='', flush=True)
    result.check_returncode()
