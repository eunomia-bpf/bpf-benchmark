"""Observe debug-variable and BTF metadata without retaining compiler outputs."""
import argparse
from collections import Counter
import hashlib
import json
import os
import re
import subprocess
import time
from elftools.elf.elffile import ELFFile


def main(a):
    command = ['llvm-dis-18', str(a.bitcode), '-o', '-']
    names = Counter()
    executor_subprograms = debug_intrinsics = longest_run = run = ir_bytes = 0
    a.output.parent.mkdir(parents=True, exist_ok=True)
    start = time.monotonic()
    with a.output.with_suffix('.stderr').open('w') as errors:
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=errors, text=True)
        for line in process.stdout:
            ir_bytes += len(line.encode())
            variable = re.search(r'!DILocalVariable\(name: "([^"]+)"', line)
            if variable:
                names[variable[1]] += 1
            executor_subprograms += '!DISubprogram(name: "x86_sim_inline_execute"' in line
            if re.match(r'\s*(?:tail )?call void @llvm\.dbg\.(?:value|declare|assign)\(', line):
                debug_intrinsics += 1
                run += 1
                longest_run = max(longest_run, run)
            else:
                run = 0
        _, status, usage = os.wait4(process.pid, 0)
        process.returncode = os.waitstatus_to_exitcode(status)
    if process.returncode:
        raise subprocess.CalledProcessError(process.returncode, command)
    sections = {}
    if a.object is not None:
        with a.object.open('rb') as stream:
            sections = {s.name: s.data() for s in ELFFile(stream).iter_sections()
                        if s.name in ('.BTF', '.BTF.ext', 'kprobe')}
    record = dict(command=command, bitcode_sha256=hashlib.sha256(a.bitcode.read_bytes()).hexdigest(),
        object_sha256=hashlib.sha256(a.object.read_bytes()).hexdigest() if a.object is not None else None,
        local_variables=sum(names.values()), names=dict(names),
        debug_variable_intrinsics=debug_intrinsics, longest_debug_variable_run=longest_run,
        ir_text_bytes=ir_bytes, executor_debug_subprograms=executor_subprograms,
        wall_seconds=time.monotonic()-start, user_seconds=usage.ru_utime,
        system_seconds=usage.ru_stime, max_rss_kib=usage.ru_maxrss,
        sections={name:dict(bytes=len(data), sha256=hashlib.sha256(data).hexdigest())
                  for name,data in sections.items()})
    a.output.write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps({k:v for k,v in record.items() if k!='names'}))


if __name__=='__main__':
    from pathlib import Path
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('bitcode','output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--object', type=Path)
    main(parser.parse_args())
