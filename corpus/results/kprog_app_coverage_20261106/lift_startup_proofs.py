"""Lift exact captured context-free startup bytecode through the normal native proof path."""
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=HERE/'startup-lift';OUT.mkdir(exist_ok=True)
sys.path.insert(0,str(ROOT/'kprog'))
from helper_abi import helper_idents
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen

def run(args):
    args=list(map(str,args));result=subprocess.run(args,capture_output=True,text=True,timeout=120)
    with (OUT/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(command=args,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))+'\n')
    if result.returncode:raise RuntimeError(result.stderr)
    return result

name,raw,section=sys.argv[1:]
if re.fullmatch(r'[A-Za-z_]\w*',name) is None:raise ValueError('name must be a C identifier')
case=OUT/name;case.mkdir()
raw_copy=case/'source.bpf.bin';shutil.copy2(raw,raw_copy)
ir=case/'native.ll';optimized=case/'native.opt.ll'
run([HERE/'lift-bpf-ir',raw_copy,ir])
identities=helper_idents()
def canonical(match):
    number=int(match[1])
    if number not in identities:raise ValueError(f'no public Linux helper declaration for {number}')
    return identities[number]
ir.write_text(re.sub(r'_bpf_helper_ext_([0-9]+)',canonical,ir.read_text()))
run(['opt-18','-O3','-S',ir,'-o',optimized])
native=case/'entry.native.o'
run(['llc-18','-mtriple=x86_64-pc-linux-gnu','-mcpu=x86-64','-filetype=obj','-O=3','-disable-tail-calls','-relocation-model=pic',optimized,'-o',native])
proof=case/'bpf_main.proof.o'
run([ROOT/'kprog/x86/native_lab/native_link/target-c-readonly/release/native-link',
     '--input',native,'--symbol','bpf_main','--mode','proof','--preserve-entry-abi','--output',proof])
insns,subs,end,rodata=gen.parse_proof_object_program('bpf_main',case)
text=gen.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section=section)
source=case/'entry.bpf.c'
source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
obj=case/'entry.bpf.o'
run(['clang','-g','-O2','-Wno-c23-extensions','-target','bpf',
     '-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),
     '-I/usr/include/x86_64-linux-gnu','-c',source,'-o',obj])
(case/'manifest-entry.json').write_text(json.dumps(dict(program='',source_bytecode_hex=raw_copy.read_bytes().hex(),
    native_object=str(native),symbol='bpf_main',simulator_object=str(obj),
    simulator_program=name+'_x86_sim_xdp'),indent=2)+'\n')
print(name,'exact captured bytes → LLVM → native ELF → canonical proof → simulator BPF PASS',flush=True)
