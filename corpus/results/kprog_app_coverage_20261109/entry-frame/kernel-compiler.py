#!/usr/bin/env python3
"""Feed the master-owned entry patch to one GCC frontend through stdin."""
from pathlib import Path
import hashlib
import json
import os
import subprocess
import sys

ROOT = Path('/workspaces/repository')
STATE = Path('/var/tmp/kprog-tmp/C/stock-entry')
SOURCE = Path('/var/tmp/kprog-tmp/CK/linux/arch/x86/net/bpf_jit_comp.c')
PATCH = ROOT / 'kprog/stock-path/x86-entry-frame.patch'


def main():
    command = sys.argv[1:]
    if Path(command[0]).name != 'cc1':
        os.execvp(command[0], command)
    index = command.index(str(SOURCE))
    patched = subprocess.run(
        ['patch', '--silent', '--forward', '--no-backup-if-mismatch',
         '--reject-file=' + str(STATE / 'entry-reject.txt'), '--output=-',
         str(SOURCE), str(PATCH)], capture_output=True)
    sys.stderr.buffer.write(patched.stderr)
    patched.check_returncode()
    data = b'#line 1 ' + json.dumps(str(SOURCE)).encode() + b'\n' + patched.stdout
    command[index] = '-'
    command[1:1] = ['-iquote', str(SOURCE.parent)]
    completed = subprocess.run(command, input=data)
    record = dict(command=command, returncode=completed.returncode,
                  source_sha256=hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
                  patch_sha256=hashlib.sha256(PATCH.read_bytes()).hexdigest(),
                  compiler_input_sha256=hashlib.sha256(data).hexdigest())
    with (STATE / 'entry-compiler.jsonl').open('a') as output:
        output.write(json.dumps(record) + '\n')
    completed.check_returncode()
    # Kbuild fixdep consumes the frontend's dependency file after GCC returns.
    # Record the original source and its canonical patch/wrapper as inputs.
    flag = next(name for name in ['-MF', '-MMD', '-MD'] if name in command)
    dependency = Path(command[command.index(flag) + 1])
    content = dependency.read_text()
    inputs = ' '.join(str(p) for p in [SOURCE, PATCH, Path(__file__).resolve()])
    dependency.write_text(content.replace(':', ': ' + inputs, 1))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
