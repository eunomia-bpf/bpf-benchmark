"""Diagnose uninterrupted normal-O1 B emission from preserved bounds IR.

This bypasses only the MIR serialization/packing boundary in a result-local
control. Production policy, frontend input, native P and LTO are unchanged.
"""
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker

ident, records = int(sys.argv[1]), Path(sys.argv[2])
records.mkdir(parents=True, exist_ok=True)
case = HERE / ('request-' + str(ident))
obj = case / 'trusted_x86.bpf.o'
status, object_bytes = 1, None
command = list(map(str, [ROOT / 'kprog/stock-path/bin/clang', *worker.COMPILE_FLAGS,
    '-c', case / 'trusted_x86.bpf.bounds.bc', '-o', obj]))
try:
    process = subprocess.run(command, text=True, capture_output=True)
    (records / 'compile-commands.jsonl').write_text(json.dumps(dict(command=command,
        returncode=process.returncode, stdout=process.stdout, stderr=process.stderr)) + '\n')
    print(command[0], 'exit', process.returncode, flush=True)
    process.check_returncode()
    object_bytes, status = obj.stat().st_size, 0
finally:
    (records / 'compile-status.json').write_text(json.dumps(dict(returncode=status,
        request_id=ident, object_bytes=object_bytes, ir_level=1, backend_level=1,
        input='trusted_x86.bpf.bounds.bc', generated_artifacts=['trusted_x86.bpf.o'],
        untouched_intermediates='Existing backend-input.ll and MIR files are archived for provenance, not produced by this control.',
        scope=__doc__), indent=2) + '\n')
