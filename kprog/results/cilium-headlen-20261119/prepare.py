"""Retain packet-rejected inputs from success and hard-failure capsules."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

root = Path('/workspaces/repository')
out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
source = Path('/workspaces/kprog-raw/verified/20261119-checked-cilium/service.tar.gz')
previous = json.loads(Path(sys.argv[2]).read_text()) if len(sys.argv) == 3 else None
reused = {row['request']: row for row in previous['requests']} if previous else {}
if previous and previous['source_archive'] != str(source):
    raise ValueError('retained inputs belong to a different service archive')
results = []
with tarfile.open(source) as archive:
    rows = [json.loads(line) for line in archive.extractfile('service/requests/requests.jsonl')]
    for row in rows:
        request = row['request_id']
        name = Path(row['artifact_archive'] if 'artifact_archive' in row else row['failure_archive']).name
        with tarfile.open(fileobj=archive.extractfile('service/requests/'+name)) as capsule:
            if 'request/simulator-failure.json' not in capsule.getnames():
                continue
            failure = json.load(capsule.extractfile('request/simulator-failure.json'))
            if 'invalid access to packet' not in failure.get('stderr', ''):
                continue
            directory = Path(reused[request]['frontend']).parent if request in reused else out/str(request)
            if request not in reused:
                directory.mkdir(exist_ok=True)
                for artifact in ['trusted_x86.bpf.bounds-input.bc', 'trusted_x86.bpf.o']:
                    (directory/artifact).write_bytes(capsule.extractfile('request/generated/'+artifact).read())
                (directory/'failure.json').write_text(json.dumps(failure, indent=2)+'\n')
                if 'request/load-direct.stderr' in capsule.getnames():
                    (directory/'load-direct.stderr').write_bytes(capsule.extractfile('request/load-direct.stderr').read())
        if request in (3, 7, 64) and request not in reused:
            command = ['llvm-dis-18', str(directory/'trusted_x86.bpf.bounds-input.bc'), '-o', '-']
            p = subprocess.run(command, text=True, capture_output=True)
            (directory/'disassemble-command.json').write_text(json.dumps(dict(
                command=command, returncode=p.returncode, stderr=p.stderr), indent=2)+'\n')
            p.check_returncode()
            (directory/'frontend.ll').write_text(p.stdout)
        results.append(dict(request=request, source_prog_id=row['source_prog_id'],
            capsule=name, journal_status=row['status'], error=failure['error'],
            frontend=str(directory/'trusted_x86.bpf.bounds-input.bc')))
(out/'inputs.json').write_text(json.dumps(dict(source_archive=str(source), requests=results,
    scope='Actual archived inputs and original errors, no compilation or stock/current-app pass.'), indent=2)+'\n')
print(f'Retained {len(results)} actual packet-class frontend inputs.', flush=True)
