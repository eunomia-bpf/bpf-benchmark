"""Lift exact captured context-free startup bytecode through the normal native proof path."""
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import struct
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
# Bind source LDDW identities before optimization; no inferred map name/size.
code=raw_copy.read_bytes()
bindings=[]
by_symbol={}
by_identity={}
fd_sites=[]
for pc in range(len(code)//8):
    opcode,regs,off,imm=struct.unpack_from("<BBhi",code,pc*8)
    if opcode!=0x18 or regs>>4 not in {1,2}:continue
    if pc+1>=len(code)//8:raise ValueError("source map LDDW lacks its continuation")
    next_op,next_regs,next_off,upper=struct.unpack_from("<BBhi",code,(pc+1)*8)
    if next_op or next_regs or next_off or (regs>>4==1 and upper):
        raise ValueError("source map LDDW continuation is malformed")
    kind=regs>>4;value_offset=upper & 0xffffffff if kind==2 else 0
    if imm<=0:raise ValueError("source map FD must be positive")
    upstream=(f"__llvmbpf_pseudo_map_fd_{imm:08x}" if kind==1 else
              f"__llvmbpf_pseudo_map_value_fd_{imm:08x}_off_{value_offset:08x}")
    fd_sites.append(pc)
    if upstream in by_symbol:continue
    key=(kind,imm)
    if key not in by_identity:
        binding=dict(native_symbol=f"__native_source_map_{pc}",source_insn=pc,
                     proof_symbol=f"__source_map_base_{pc}",kind=kind,value_offset=value_offset)
        bindings.append(binding);by_identity[key]=binding
    binding=by_identity[key]
    by_symbol[upstream]=(binding,value_offset-binding['value_offset'])
if len({struct.unpack_from("<i",code,b["source_insn"]*8+4)[0] for b in bindings})>1:
    raise ValueError("multiple source map FDs require actual map-identity alias context")
text=ir.read_text()
for upstream,(binding,delta) in by_symbol.items():
    declaration="@"+upstream+" = external global i8"
    if text.count(declaration)!=1:raise ValueError("source-map LLVM declaration must be external and unique")
    text=text.replace(declaration+"\n","")
    expression="@"+binding['native_symbol']
    if delta:expression=f"getelementptr (i8, ptr {expression}, i64 {delta})"
    text=re.sub("@"+re.escape(upstream)+r"\b",lambda match:expression,text)
for binding in bindings:
    # One incomplete object per source identity, preserving overlapping offsets.
    text+="\n@"+binding['native_symbol']+" = external global [0 x i8]\n"
ir.write_text(text)
(case/'source-map-bindings.json').write_text(json.dumps(bindings,indent=2)+'\n')
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
run([ROOT/'kprog/x86/native_lab/native_link/target-c-tail/release/native-link',
     '--input',native,'--symbol','bpf_main','--mode','proof','--preserve-entry-abi','--output',proof])
insns,subs,end,rodata=gen.parse_proof_object_program('bpf_main',case)
text=gen.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=rodata,program_section=section,source_map_bindings=bindings)
source=case/'entry.bpf.c'
source.write_text(text.replace('#include "../x86_sim_local_bpf.h"',f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
obj=case/'entry.bpf.o'
run(['clang','-g','-O2','-Wno-c23-extensions','-target','bpf',
     '-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),
     '-I/usr/include/x86_64-linux-gnu','-c',source,'-o',obj])
template=bytearray(code)
# Multi-site proofs keep exact FD bytes until runtime alias-class binding is supplied.
normalized_sites=fd_sites if len(fd_sites)==1 else []
for pc in normalized_sites:struct.pack_into('<i',template,pc*8+4,0)
entry=dict(program='',source_bytecode_hex=template.hex(),native_object=str(native),symbol='bpf_main',
           simulator_object=str(obj),simulator_program=name+'_x86_sim_xdp')
if bindings:
    if normalized_sites:entry['source_map_fd_sites']=normalized_sites
    entry['source_map_bindings']=[{key:b[key] for key in ('native_symbol','source_insn')} for b in bindings]
(case/'manifest-entry.json').write_text(json.dumps(entry,indent=2)+'\n')
print(name,'exact captured bytes → LLVM → native ELF → canonical proof → simulator BPF PASS',flush=True)
