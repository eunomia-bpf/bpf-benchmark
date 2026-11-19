"""Replay the failing Tetragon B from its completed O1 frontend."""
import json
from pathlib import Path
import subprocess
import sys
import time

root = Path('/workspaces/repository')
sys.path.insert(0, str(root/'kprog/x86'))
import trusted_specializer as worker

out = Path(sys.argv[1])
frontend = Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063707Z-211523/tetragon6/trusted_x86.bpf.bounds-input.bc')
bounds = Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds')
commands = []
def run(arguments):
    arguments = list(map(str, arguments))
    if arguments[0] == str(bounds):
        arguments = ['flock', '-s', '/workspaces/.agent-state/kprog-lanes/locks/image', *arguments]
    start = time.monotonic()
    result = subprocess.run(arguments, text=True, capture_output=True)
    commands.append(dict(command=arguments, returncode=result.returncode,
                         seconds=time.monotonic()-start, stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    print('stage', len(commands), 'exit', result.returncode, 'seconds', commands[-1]['seconds'], flush=True)
    result.check_returncode()

worker.compile_simulator_from_frontend(str(root/'kprog/stock-path/bin/clang'),
    out/'replay.bpf.c', out/'B.o', run, frontend=frontend, bounds_compiler=bounds)
(out/'result.json').write_text(json.dumps(dict(emitted=True, frontend=str(frontend),
    stages=len(commands), scope='Retained O1 frontend replay; no fresh shared-I generation, stock load or runtime result.'), indent=2)+'\n')
