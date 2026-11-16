#!/usr/bin/env python3
"""Execute upstream CEL bodies through native LTO with their actual argument ABI."""
import argparse
import ctypes
import json
from pathlib import Path
import subprocess
import sys

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build',type=Path,required=True)
parser.add_argument('--output',type=Path,required=True)
parser.add_argument('--compiler',type=Path)
parser.add_argument('--kernel',type=Path)
parser.add_argument('--linker',type=Path)
parser.add_argument('--worker',type=int)
args = parser.parse_args()
cases = json.loads((args.output/'upstream-cel.json').read_text())
if args.worker is not None:
    case = cases[args.worker]
    library = ctypes.CDLL(str(args.build/'tetragon-cel-native.so'))
    entry = library.native_cel_entry
    entry.argtypes = [ctypes.c_void_p,ctypes.c_void_p]
    entry.restype = ctypes.c_int
    offsets = (ctypes.c_uint64*len(case['offsets']))(*case['offsets'])
    values = ctypes.create_string_buffer(bytes.fromhex(case['values']))
    actual = entry(offsets,values)
    if actual != case['expected']:
        raise AssertionError((case['expression'],case['values'],case['expected'],actual))
    print(json.dumps(dict(index=args.worker,expected=case['expected'],actual=actual)))
    raise SystemExit(0)
results = []
for i,case in enumerate(cases):
    facts = args.output/('upstream-cel-%d.json'%i)
    facts.write_text(json.dumps(dict(functions={'cel_expression':case['code']}))+'\n')
    commands = [
        [args.compiler,args.build/'tetragon-cel-input.o','--symbol','native_cel_entry','--prog-type','2',
         '--kernel-btf',args.kernel,'--bpf-function-bodies',facts,'-o',args.build/'tetragon-cel-native.o'],
        ['clang-18','-shared',args.build/'tetragon-cel-native.o','-o',args.build/'tetragon-cel-native.so'],
        [sys.executable,__file__,'--build',args.build,'--output',args.output,'--worker',str(i)],
        [args.linker,'--input',args.build/'tetragon-cel-native.o','--symbol','native_cel_entry',
         '--mode','proof','--preserve-entry-abi','--output',args.output/('upstream-cel-%d.proof.o'%i)],
    ]
    for j,command in enumerate(commands):
        with (args.output/('upstream-cel-%d-%d.log'%(i,j))).open('w') as log:
            subprocess.run(list(map(str,command)),stdout=log,stderr=subprocess.STDOUT,check=True)
    results.append(dict(index=i,expression=case['expression'],instructions=len(case['code'])//16,
                        expected=case['expected'],passed=True))
(args.output/'upstream-cel-report.json').write_text(json.dumps(dict(cases=results,
    scope='Actual unmodified upstream CEL compiler, constructed argument vectors; not app startup or stock acceptance.'),indent=2)+'\n')
print('Upstream CEL native execution/proof cases PASS:',len(results))
