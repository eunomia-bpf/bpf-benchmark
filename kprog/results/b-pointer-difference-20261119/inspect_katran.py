"""Map the coordinator's actual Katran rejection without replaying its frontend."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
source = Path('/workspaces/kprog-raw/coordinator/lto-katran-20261119T185858Z/timing/service.tar.gz')
names = ['trusted_x86.bpf.bounds-input.bc', 'trusted_x86.bpf.bounds.bc',
         'trusted_x86.bpf.o', 'trusted_x86.bpf.c']
with tarfile.open(source) as outer:
    with tarfile.open(fileobj=outer.extractfile('service/requests/1.success.tar.gz')) as capsule:
        for name in names:
            (out/name).write_bytes(capsule.extractfile('request/generated/'+name).read())
        failure = json.load(capsule.extractfile('request/simulator-failure.json'))
        (out/'failure.json').write_text(json.dumps(failure, indent=2)+'\n')
        (out/'verifier.log').write_text(failure['stderr'])
        (out/'original-commands.jsonl').write_bytes(capsule.extractfile('request/generated/commands.jsonl').read())

commands = []
def run(command, path):
    command = list(map(str, command))
    p = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=p.returncode, stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    p.check_returncode()
    path.write_text(p.stdout)
for name in names[:2]:
    run(['llvm-dis-18', out/name, '-o', '-'], out/(name+'.ll'))
run(['llvm-objdump-18', '-dl', out/'trusted_x86.bpf.o'], out/'b-disassembly.txt')
lines = (out/'b-disassembly.txt').read_text().splitlines()
index = next(i for i, line in enumerate(lines) if line.lstrip().startswith('4145:'))
(out/'failure-excerpt.txt').write_text('\n'.join(lines[max(0,index-55):index+20])+'\n')
print((out/'failure-excerpt.txt').read_text(), flush=True)
