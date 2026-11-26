"""Separate stock admission, native emission and the existing guest oracle."""
import gzip
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile

HERE = Path(__file__).resolve().parent
controller = Path(sys.argv[1])
raw = Path(json.loads(controller.read_text())['raw'])
rows = []
for case in json.loads((raw / 'cases.json').read_text()):
    directory = raw / case['name']
    requests, commands, cleanup = [], [], []
    with tarfile.open(directory / 'service.tar.gz') as service:
        for name in service.getnames():
            if name.endswith('requests.jsonl'):
                requests = [json.loads(line) for line in service.extractfile(name).read().decode().splitlines()]
            if not name.endswith('.success.tar.gz'):
                continue
            with tarfile.open(fileobj=io.BytesIO(service.extractfile(name).read())) as request:
                names = set(request.getnames())
                for line in request.extractfile('request/generated/commands.jsonl').read().decode().splitlines():
                    row = json.loads(line); argv = row['command']
                    if '-E' in argv:
                        paths = [argv[argv.index('-E')+1], argv[argv.index('-o')+1]]
                        cleanup.append(dict(command=argv, returncode=row['returncode'],
                            pieces_absent_from_complete_archive=all('request/generated/' + Path(p).name not in names for p in paths),
                            joined_source_retained='request/generated/trusted_x86.bpf.i' in names))
                for line in request.extractfile('request/generated/native-commands.jsonl').read().decode().splitlines():
                    row = json.loads(line); argv = row['command']
                    if '-target' in argv and 'x86_64-linux-gnu' in argv and '-c' in argv and '-emit-llvm' not in argv:
                        commands.append(dict(command=argv, returncode=row['returncode'],
                                             common_branch_option='-x86-cmov-converter-force-all' in argv))
                if case['returncode']:
                    payload = request.extractfile('request/generated/request.native.o').read()
                    fd = os.memfd_create('initial-P')
                    try:
                        os.write(fd, payload)
                        assembly = subprocess.check_output(['llvm-objdump-18', '-dr', f'/proc/{os.getpid()}/fd/{fd}'], text=True)
                    finally:
                        os.close(fd)
                    (HERE / (case['name'] + '-initial-P.dis')).write_text(assembly)
                    source = request.extractfile('request/generated/trusted_x86.bpf.c').read()
                    (HERE / (case['name'] + '-generated.c.gz')).write_bytes(gzip.compress(source, mtime=0))
    outputs = [json.loads(line) for line in (directory / 'stdout').read_text().splitlines() if line.startswith('{')]
    rows.append(dict(name=case['name'], returncode=case['returncode'], requests=requests,
                     native_emissions=commands, preprocessing_cleanup=cleanup,
                     observed_retvals=[o['retval'] for o in outputs if 'retval' in o]))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              controller=str(controller), cases=rows,
              scope='All attempted cases retained. Existing oracle expects older helper EFAULT semantics; initial current P in three failures ends with constant3. The client combines syscall/retval errors and does not print failed retval, so3 is a static code finding, not a recorded failed TEST_RUN counter. Stock B admission, checked installation and self-check outcomes are separate. No app or performance conclusion.')
(HERE / 'guest-outcome.json').write_text(json.dumps(record, indent=2) + '\n')
for row in rows:
    print(row['name'], row['returncode'], row['observed_retvals'],
          [(r.get('b_stock_passed'), r.get('execution_path')) for r in row['requests']])
