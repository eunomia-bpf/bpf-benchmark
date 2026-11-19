"""Retain the separate six kernel-context store failures and exact IR sites."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
source = Path('/workspaces/kprog-raw/verified/20261119-checked-cilium/service.tar.gz')
rows = []
with tarfile.open(source) as archive:
    journal = [json.loads(line) for line in archive.extractfile('service/requests/requests.jsonl')]
    for record in journal:
        failure = record.get('simulator_failure', {})
        if 'only read is supported' not in failure.get('stderr', ''):
            continue
        directory = out/str(record['request_id']); directory.mkdir(exist_ok=True)
        name = Path(record['artifact_archive']).name
        with tarfile.open(fileobj=archive.extractfile('service/requests/'+name)) as capsule:
            bc = directory/'bounds-input.bc'
            bc.write_bytes(capsule.extractfile('request/generated/trusted_x86.bpf.bounds-input.bc').read())
        process = subprocess.run(['llvm-dis-18', str(bc), '-o', '-'], text=True, capture_output=True)
        (directory/'disassemble.json').write_text(json.dumps(dict(returncode=process.returncode,
            stderr=process.stderr), indent=2)+'\n')
        process.check_returncode()
        (directory/'frontend.ll').write_text(process.stdout)
        lines = [line.strip() for line in process.stdout.splitlines()
                 if 'asm sideeffect' in line and '*(u16 *)' in line and 'i64 46,' in line]
        row = dict(request=record['request_id'], source_prog_id=record['source_prog_id'],
                   capsule=name, store_ir=lines, frontend=str(bc))
        rows.append(row)
        (directory/'failure.json').write_text(json.dumps(failure, indent=2)+'\n')
(out/'result.json').write_text(json.dumps(dict(source_archive=str(source),requests=rows,
    scope='Actual captured context-store input shapes only; no new compilation, stock acceptance or runtime result.'),indent=2)+'\n')
print(json.dumps(rows), flush=True)
