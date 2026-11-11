#!/usr/bin/env python3
"""Census follow-up 3: B sources beyond Clang's source-location space.

Recompiles archived census B sources through the x86 trusted specializer's
compile_simulator (the service's own B compile) with the in-tree model, and
compares the result with the census object.

  source-locations.py extract <requests.tar.gz> <work>
      unpack every B source of the census request archive (concatenated
      requests.tar.gz.partNNN of the master-grouped census) under <work>/x
  source-locations.py compile <cpus> <work> <worker-id>...
      compile the named workers' B sources into <work>/out/<worker-id>; when the
      census archived an object, compare its code and relocations
      (llvm-objdump -d -r) with the new object; append one row per worker to
      <work>/rows.jsonl
"""
import json
import re
import resource
import shutil
import subprocess
import sys
import tarfile
import time
from pathlib import Path

ROOT = Path('/workspaces/repository')
sys.path.insert(0, str(ROOT / 'kprog/x86'))
CLANG = ROOT / 'kprog/stock-path/bin/clang'
OBJDUMP = '/usr/lib/llvm-18/bin/llvm-objdump'


def extract(archive, work):
    with tarfile.open(archive) as tar:
        members = [m for m in tar.getmembers()
                   if m.name.endswith(('/generated/trusted_x86.bpf.c', '/generated/trusted_x86.bpf.o'))]
        tar.extractall(Path(work) / 'x', members=members)
    print(len(members), 'members')


def disassembly(obj):
    text = subprocess.run([OBJDUMP, '-d', '-r', str(obj)], check=True, text=True,
                          capture_output=True).stdout
    return text.split('\n', 2)[2]


def compile_one(work, worker):
    import trusted_specializer
    generated = sorted((work / 'x').glob(f'workers*/{worker}/stock-state/*/request/generated'))[0]
    out = work / 'out' / worker
    shutil.rmtree(out, ignore_errors=True)
    out.mkdir(parents=True)
    source = out / 'trusted_x86.bpf.c'
    shutil.copy(generated / 'trusted_x86.bpf.c', source)
    commands = []

    def run(command):
        command = [str(x) for x in command]
        start = time.time()
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             seconds=round(time.time() - start, 1),
                             children_max_rss_kib=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss,
                             stderr_tail=result.stderr[-4000:]))
        result.check_returncode()

    start = time.time()
    row = dict(worker=worker, census_archive=str(generated.parent.parent.relative_to(work / 'x')),
               source_bytes=source.stat().st_size)
    try:
        trusted_specializer.compile_simulator(CLANG, source, out / 'trusted_x86.bpf.o', run)
        row['compiled'] = True
    except subprocess.CalledProcessError:
        row['compiled'] = False
    row.update(seconds=round(time.time() - start, 1), pieces=len(list(out.glob('*.piece*.c'))),
               max_rss_mib=max(c['children_max_rss_kib'] for c in commands) // 1024)
    census_object = generated / 'trusted_x86.bpf.o'
    if row['compiled'] and census_object.exists():
        row['equal_to_census_object'] = disassembly(census_object) == disassembly(out / 'trusted_x86.bpf.o')
    if row['compiled']:
        row['bpf_instructions'] = len(re.findall(r'(?m)^ +[0-9]+:', disassembly(out / 'trusted_x86.bpf.o')))
    (out / 'commands.json').write_text(json.dumps(commands, indent=1) + '\n')
    for item in out.glob('*.piece*'):
        item.unlink()
    (out / 'trusted_x86.bpf.i').unlink(missing_ok=True)
    with (work / 'rows.jsonl').open('a') as rows:
        rows.write(json.dumps(row) + '\n')
    print(json.dumps(row))


def main():
    mode = sys.argv[1]
    if mode == 'extract':
        extract(sys.argv[2], sys.argv[3])
    elif mode == 'compile':
        import os
        os.sched_setaffinity(0, {int(c) for part in sys.argv[2].split(',')
                                 for c in (range(int(part.split('-')[0]), int(part.split('-')[-1]) + 1))})
        for worker in sys.argv[4:]:
            compile_one(Path(sys.argv[3]), worker)
    else:
        raise SystemExit(__doc__)


if __name__ == '__main__':
    main()
