"""Retain real frontend inputs for the forty reported packet-bound failures."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

root = Path('/workspaces/repository')
out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
source = Path('/workspaces/kprog-raw/verified/20261119-checked-cilium/service.tar.gz')
rows = json.loads((root/'kprog/results/cilium-packet-bounds-20261119/requests.json').read_text())
results = []
with tarfile.open(source) as archive:
    for row in rows:
        if row['class'] != 'packet':
            continue
        request = row['request_id']
        directory = out/str(request); directory.mkdir(exist_ok=True)
        with tarfile.open(fileobj=archive.extractfile(f'service/requests/{request}.success.tar.gz')) as capsule:
            for name in ['trusted_x86.bpf.bounds-input.bc', 'trusted_x86.bpf.o']:
                (directory/name).write_bytes(capsule.extractfile('request/generated/'+name).read())
            failure = json.load(capsule.extractfile('request/simulator-failure.json'))
            (directory/'failure.json').write_text(json.dumps(failure, indent=2)+'\n')
            assert 'invalid access to packet' in failure['stderr'], (request, failure['error'])
        if request in (3, 7):
            command = ['llvm-dis-18', str(directory/'trusted_x86.bpf.bounds-input.bc'), '-o', '-']
            p = subprocess.run(command, text=True, capture_output=True)
            (directory/'disassemble-command.json').write_text(json.dumps(dict(
                command=command, returncode=p.returncode, stderr=p.stderr), indent=2)+'\n')
            p.check_returncode()
            (directory/'frontend.ll').write_text(p.stdout)
        results.append(dict(request=request, error=failure['error'], frontend=str(directory/'trusted_x86.bpf.bounds-input.bc')))
(out/'inputs.json').write_text(json.dumps(dict(source_archive=str(source), requests=results,
    scope='Actual archived inputs and original errors, no compilation or stock/current-app pass.'), indent=2)+'\n')
assert len(results) == 40, len(results)
print(f'Retained {len(results)} actual packet-class frontend inputs.', flush=True)
