#!/usr/bin/env python3
"""Catch lost R2-R5, pointer/stack/branch semantics and dropped side effects."""
import argparse
import json
from pathlib import Path
import struct
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
for name in ['build', 'compiler', 'kernel', 'linker', 'output']:
    parser.add_argument('--' + name, type=Path, required=True)
args = parser.parse_args()

def insn(op, dst=0, src=0, off=0, imm=0):
    return struct.pack('<BBhi', op, dst | src << 4, off, imm)

exit = insn(0x95)
functions = {
    'supplied5': insn(0xbf,0,1) + b''.join(insn(0x0f,0,r) for r in range(2,6)) + exit,
    'supplied_load': insn(0x79,0,1) + insn(0x0f,0,2) + exit,
    'supplied_stack': insn(0x7b,10,2,-8) + insn(0x79,0,10,-8) + insn(0x0f,0,1) + exit,
    'supplied_bytes': insn(0xb7) + insn(0x15,2,off=5) + insn(0x71,3,1) + insn(0x0f,0,3) +
                      insn(0x07,1,imm=1) + insn(0x17,2,imm=1) + insn(0x55,2,off=-5) + exit,
    'supplied_branch': insn(0xbf,0,2) + insn(0x65,1,off=1) + insn(0x87) + exit,
    'supplied_narrow': insn(0xbc,0,2) + insn(0x04,0,imm=-1) + exit,
    'supplied_store': insn(0x7b,1,2) + insn(0xb7) + exit,
}
facts = args.output / 'callee-facts.json'
facts.write_text(json.dumps({'functions':{k:v.hex() for k,v in functions.items()}},indent=2)+'\n')
commands = [
    [args.compiler,args.build/'callee-abi-input.o','--symbol','main','--prog-type','1',
     '--kernel-btf',args.kernel,'--bpf-function-bodies',facts,'-o',args.build/'callee-abi-native.o'],
    ['clang-18',args.build/'callee-abi-native.o','-o',args.build/'callee-abi'],
    [args.build/'callee-abi'],
]
for name in functions:
    commands.append([args.linker,'--input',args.build/'callee-abi-native.o','--symbol',name,
                     '--mode','proof','--preserve-entry-abi','--output',args.output/(name+'.proof.o')])
for i, command in enumerate(commands):
    with (args.output/('command-%d.log'%i)).open('w') as log:
        subprocess.run(list(map(str,command)),stdout=log,stderr=subprocess.STDOUT,check=True)
(args.output/'callee-abi-report.json').write_text(json.dumps({
    'functions':list(functions),'vectors_per_function':256,'native_execution_pass':True,
    'proof_entries_pass':len(functions),'commands':[[str(a) for a in c] for c in commands],
    'scope':'Constructed compiler ABI/semantic vectors, not app capture or stock acceptance.'},indent=2)+'\n')
print('Seven nonconstant functions x 256 native ABI/semantic vectors; seven native proof entries PASS')
