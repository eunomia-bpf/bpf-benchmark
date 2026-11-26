"""Compile the newly generated source through the normal installed B pipeline."""
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker

case = HERE / 'request-39'
source, obj = case / 'trusted_x86.bpf.c', case / 'trusted_x86.bpf.o'
status = 1
object_bytes = None
def run(command):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    with (HERE / 'compile-commands.jsonl').open('a') as log:
        log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                  stdout=result.stdout, stderr=result.stderr)) + '\n')
    print(command[0], 'exit', result.returncode, flush=True)
    result.check_returncode()

try:
    worker.compile_simulator(ROOT / 'kprog/stock-path/bin/clang', source, obj, run,
        bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
    object_bytes = obj.stat().st_size
    status = 0
finally:
    record = dict(returncode=status, request_id=39,
        source_equal_to_request62=source.read_text() == (HERE / 'request-62/trusted_x86.bpf.c').read_text(),
        object_bytes=object_bytes,
        scope='Normal B compilation only; stock-verifier and app acceptance remain separate.')
    (HERE / 'compile-status.json').write_text(json.dumps(record, indent=2) + '\n')
    lane = Path('/workspaces/.agent-state/kprog-lanes/perf')
    with (lane / 'resume-msg.md').open('a') as message:
        message.write(f'\nTetragon table B compilation ended status {status}. Read {HERE}/compile-status.json, '
            'compile-commands.jsonl and compile.log; record the actual result, continue the phase1 pipeline '
            'within design, retain all raw evidence and leave full timing frozen.\n')
    stop = lane / 'STOP'
    if stop.exists() and stop.read_text().startswith('PERF table compilation:'):
        stop.unlink()
