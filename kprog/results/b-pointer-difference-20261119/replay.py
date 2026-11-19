"""Replay the retained Tracee frontend, without rerunning the C frontend."""
import json
from pathlib import Path
import subprocess
import sys

root = Path('/workspaces/repository')
request = int(sys.argv[2]) if len(sys.argv) > 2 else 27
retained = Path('/workspaces/kprog-raw/perf/tracee-live-failures-20261119/'
                f'recovery-20261119T163803Z-17194/source-mapping/{request}/frontend.ll')
out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
sys.path.insert(0, str(root/'kprog/x86'))
import trusted_specializer as adapter

commands = []
def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    result.check_returncode()
    return result.stdout

run(['/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds',
     retained, '-o', out/'bounds.bc'])
(out/'bounds.ll').write_text(run(['llvm-dis-18', out/'bounds.bc', '-o', '-']))
adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang',
    out/'replay.bpf.c', out/'replay.bpf.o', run, compiled_input=out/'bounds.bc')
(out/'b-disassembly.txt').write_text(run(['llvm-objdump-18', '-dl', out/'replay.bpf.o']))
(out/'result.json').write_text(json.dumps(dict(retained_frontend=str(retained),
    b_emitted=True, scope=f'Retained request{request} B compiler replay; '
    'not stock acceptance, new app coverage or timing.'), indent=2)+'\n')
