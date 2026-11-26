"""Test one common O2 machine backend using the existing post-IR module.

This control changes no production policy and does not rerun frontend/GVN.
Canonical case products are replaced in place; their baseline is archived.
"""
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
ident, records = int(sys.argv[1]), Path(sys.argv[2])
records.mkdir(parents=True, exist_ok=True)
case = HERE / ('request-' + str(ident))
before, packed = case / 'trusted_x86.bpf.before.mir', case / 'trusted_x86.bpf.packed.mir'
ir, obj = case / 'trusted_x86.bpf.backend-input.ll', case / 'trusted_x86.bpf.o'
status, object_bytes = 1, None

def run(command):
    command = list(map(str, command))
    process = subprocess.run(command, text=True, capture_output=True)
    with (records / 'compile-commands.jsonl').open('a') as out:
        out.write(json.dumps(dict(command=command, returncode=process.returncode,
                                 stdout=process.stdout, stderr=process.stderr)) + '\n')
    print(command[0], 'exit', process.returncode, flush=True)
    process.check_returncode()

try:
    # Decode the MIR's literal LLVM-module document, without changing IR.
    with before.open() as source, ir.open('w') as destination:
        if next(source) != '--- |\n':
            raise ValueError('baseline MIR has no literal LLVM module')
        for line in source:
            if line == '...\n':
                break
            if line == '\n':
                destination.write(line)
                continue
            if not line.startswith('  '):
                raise ValueError('invalid indentation in baseline LLVM module')
            destination.write(line[2:])
        else:
            raise ValueError('baseline LLVM module is not terminated')
    flags = ['llc-18', '-O2', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096']
    run([*flags, '-stop-before=prologepilog', ir, '-o', before])
    run([sys.executable, ROOT / 'kprog/x86/whole_word_spills.py', before, packed])
    run([*flags, '-start-before=prologepilog', '-filetype=obj', packed, '-o', obj])
    object_bytes, status = obj.stat().st_size, 0
finally:
    (records / 'compile-status.json').write_text(json.dumps(dict(returncode=status,
        request_id=ident, object_bytes=object_bytes, backend_level=2,
        scope=__doc__), indent=2) + '\n')
