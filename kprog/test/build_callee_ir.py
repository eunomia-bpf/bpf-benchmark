#!/usr/bin/env python3
"""Link the IR bridge against the sole canonical runner compiler objects."""
import argparse
from pathlib import Path
import shlex
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--root', type=Path, required=True)
parser.add_argument('--build', type=Path, required=True)
args = parser.parse_args()
canonical = args.root / 'runner/build-llvmbpf'
link = shlex.split((canonical / 'CMakeFiles/micro_exec.dir/link.txt').read_text())
flags = {}
for line in (canonical / 'CMakeFiles/micro_exec.dir/flags.make').read_text().splitlines():
    if line.startswith(('CXX_DEFINES = ', 'CXX_INCLUDES = ', 'CXX_FLAGS = ')):
        key, value = line.split(' = ', 1)
        flags[key] = shlex.split(value)
first_object = next(i for i, value in enumerate(link) if value.endswith('.o'))
output_index = link.index('-o')
objects = [value for value in link[first_object:output_index] if '/vendor/llvmbpf/src/' in value]
obj = args.build / 'bpf-callee-ir.o'
commands = [
    [link[0], *flags['CXX_DEFINES'], *flags['CXX_INCLUDES'], *flags['CXX_FLAGS'],
     '-MMD', '-MF', str(args.build / 'bpf-callee-ir.compile.d'), '-MT', str(args.build / 'kprog-bpf-callee-ir'),
     '-c', str(args.root / 'kprog/x86/bpf_callee_ir.cpp'), '-o', str(obj)],
    [*link[:first_object], str(obj), *objects, '-o', str(args.build / 'kprog-bpf-callee-ir'),
     *link[output_index + 2:]],
]
for command in commands:
    print(shlex.join(command), flush=True)
    subprocess.run(command, cwd=canonical, check=True)

# Normal Make dependencies keep the bridge tied to the canonical compiler,
# without building or retaining another library.
dependencies = [canonical / value for value in objects]
dependencies += [canonical / 'CMakeFiles/micro_exec.dir/flags.make',
                 canonical / 'CMakeFiles/micro_exec.dir/link.txt']
(args.build / 'bpf-callee-ir.link.d').write_text(
    str(args.build / 'kprog-bpf-callee-ir') + ': ' + ' '.join(map(str, dependencies)) + '\n')
