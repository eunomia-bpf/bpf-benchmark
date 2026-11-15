#!/usr/bin/env python3
"""Replay historical headers in RAM; compare complete ARM dispatcher frames.

No source tree or extra compiled product is created. Logs and complete captures
are raw evidence. Products are replaced in the ordinary formal build directory.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess

ROOT=Path(__file__).resolve().parents[4]
FORMAL=ROOT/'kprog/formal'
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output',type=Path,required=True)
parser.add_argument('--before',default='4a2b31f48')
parser.add_argument('--mutations-only',action='store_true')
a=parser.parse_args()
a.output.mkdir(parents=True,exist_ok=False)
revision=subprocess.check_output(['git','rev-parse',a.before],cwd=ROOT,text=True).strip()
changed=['arm64_alu_operand','arm64_alu_operand_select','arm64_cond','arm64_csel_ptr','arm64_flag_operand','arm64_mov','arm64_movk','arm64_orn','arm64_reduction']
local=ROOT/'kprog/arm64/arm64_sim_local_bpf.h'
headers=[local,local.with_name('arm64_sim.h')]+[FORMAL/f'generated/{h}.h' for h in changed]
past={p:subprocess.check_output(['git','show',f'{revision}:{p.relative_to(ROOT)}'],cwd=ROOT,text=True) for p in headers}
inline={FORMAL/'c/Arm64Addressing.h',FORMAL/'c/Arm64Address.h',*headers}
shims='\n'.join('#define '+out+'(OUTPUT, '+params+') do { (OUTPUT)='+old+'('+args+'); } while (0)' for out,params,old,args in [
 ('KPROG_ARM64_MOV_PTR_TAG_PATH_INTO','OP, WIDTH, UNSUPPORTED','KPROG_ARM64_MOV_PTR_TAG_PATH','OP, WIDTH, UNSUPPORTED'),
 ('KPROG_ARM64_CSEL_PTR_TAG_PATH_INTO','OP, WIDTH, UNSUPPORTED','KPROG_ARM64_CSEL_PTR_TAG_PATH','OP, WIDTH, UNSUPPORTED'),
 ('KPROG_ARM64_ALU_OPERAND_SELECT_INTO','OP','KPROG_ARM64_ALU_OPERAND_SELECT','OP'),
 ('KPROG_ARM64_FLAG_RHS_INTO','OP, IMM, REG','KPROG_ARM64_FLAG_RHS','OP, IMM, REG'),
 ('KPROG_ARM64_MOVK_INSERT_INTO','DST, IMM, SHIFT, UNSUPPORTED','KPROG_ARM64_MOVK_INSERT','DST, IMM, SHIFT, UNSUPPORTED'),
 ('KPROG_ARM64_REDUCTION_VALUE_INTO','OP, VALUE, UNSUPPORTED','KPROG_ARM64_REDUCTION_VALUE','OP, VALUE, UNSUPPORTED')])+'\n'
commands=[]
def run(name,argv,stdin=None,capture=None):
    with (a.output/(name+'.log')).open('w') as log:
        if capture:
            with capture.open('wb') as binary:r=subprocess.run(argv,cwd=FORMAL,input=stdin,text=True,stdout=binary,stderr=log)
        else:r=subprocess.run(argv,cwd=FORMAL,input=stdin,text=True,stdout=log,stderr=log)
    commands.append({'name':name,'argv':argv,'exit':r.returncode})
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if r.returncode:raise SystemExit(f'{name} failed {r.returncode}')

def source(path,historical=False,mutant=None):
    def expand(p):
        body=past[p] if historical and p in past else p.read_text()
        if mutant and p==mutant[0]:
            assert body.count(mutant[1])==1,(p,mutant[1],body.count(mutant[1]))
            body=body.replace(mutant[1],mutant[2])
        def replace(m):
            child=(p.parent/m[1]).resolve()
            return ('\n#line 1 "'+str(child)+'"\n'+expand(child)+'\n#line 1 "'+str(p)+'"\n') if child in inline else '#include "'+str(child)+'"'
        body=re.sub(r'^\s*#include "([^"]+)"',replace,body,flags=re.M)
        return body+('\n'+shims if historical and p==local else '')
    return '#line 1 "'+str(path)+'"\n'+expand(path)

flags=['cc','-Wall','-Wextra','-O2','-fsanitize=undefined','-fno-sanitize-recover=undefined','-I../../vendor/libbpf/include/uapi','-I../../vendor/libbpf/src']
objects=['build/arm64_addressing_binding.o','build/arm64_address_binding.o','build/arm64_numeric_binding.o']
if not a.mutations_only:
    # The address primitive is unchanged in this step. Keep one native object until
    # the adapter phase, where its actual CompCert branch is compiled in place.
    run('address-native',flags+['-c','c/Arm64Address.c','-o',objects[1]])
    results={}
    for phase in ['historical','native','adapter']:
        extra=['-D__COMPCERT__','-include','oracles/compcert_memory_host.h'] if phase=='adapter' else []
        if phase=='adapter':run('address-adapter',flags+extra+['-c','c/Arm64Address.c','-o',objects[1]])
        for filename,index in [('Arm64Numeric',2),('Arm64Addressing',0)]:
            run(phase+'-'+filename,flags+extra+['-x','c','-c','-','-o',objects[index]],source(FORMAL/f'c/{filename}.c',phase=='historical'))
        run(phase+'-oracle',flags+['oracles/test_arm64_execute_host.c']+objects+['-o','build/test_arm64_execute_host'])
        capture=a.output/(phase+'.bin')
        run(phase+'-frames',['./build/test_arm64_execute_host','--capture'],capture=capture)
        results[phase]={'capture_bytes':capture.stat().st_size,'summary':(a.output/(phase+'-frames.log')).read_text().strip()}
    reference=(a.output/'historical.bin').read_bytes()
    for phase in ['native','adapter']:
        got=(a.output/(phase+'.bin')).read_bytes()
        if got!=reference:
            first=next((i for i,(x,y) in enumerate(zip(reference,got)) if x!=y),min(len(got),len(reference)))
            raise SystemExit(f'{phase} frame mismatch at byte {first}')
    results['comparison']='all capture bytes identical; no masks'
    results['before']=revision
    (a.output/'results.json').write_text(json.dumps(results,indent=2)+'\n')
    print(json.dumps(results,indent=2))


# Each mutation has an independent expected-value, callback-order or lane check.
# Recompile only the affected numeric root and the real oracle, in place.
mutants=[
 ('mov-width-truncation','arm64_mov','__u64 __kprog_a64_mov_width = (WIDTH);','__u64 __kprog_a64_mov_width = (__u8)(WIDTH);'),
 ('flag-register-not-observed','arm64_flag_operand','__u64 NAME = (REG);','__u64 NAME = 0;'),
 ('condition-raw-flag-booleanized','arm64_cond','ARM64_COND_EQ) NAME=(Z);','ARM64_COND_EQ) NAME=!!(Z);'),
 ('movk-wrong-column','arm64_movk','__kprog_a64_movk_mask = 0xffffULL << 16U;','__kprog_a64_movk_mask = 0xffffULL << 0U;'),
 ('cnt-high-byte-lost','arm64_reduction','KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 56) & 0xffULL)','KPROG_ARM64_POPCOUNT_BYTE(0)')]
# Check the exact spelling before any compile; a missing mutant is an error.
mutation_results=[]
for label,header,before,after in mutants:
    mutation=(FORMAL/f'generated/{header}.h',before,after)
    run(label+'-numeric',flags+['-D__COMPCERT__','-include','oracles/compcert_memory_host.h','-x','c','-c','-','-o',objects[2]],source(FORMAL/'c/Arm64Numeric.c',mutant=mutation))
    run(label+'-oracle',flags+['-x','c','-','-x','none']+objects+['-o','build/test_arm64_execute_host'],source(FORMAL/'oracles/test_arm64_execute_host.c',mutant=mutation))
    with (a.output/(label+'-run.log')).open('w') as log:
        r=subprocess.run(['./build/test_arm64_execute_host'],cwd=FORMAL,stdout=log,stderr=log)
    if r.returncode!=1:raise SystemExit(f'{label}: expected assertion exit1, got {r.returncode}')
    mutation_results.append({'mutation':label,'exit':r.returncode,'assertion':(a.output/(label+'-run.log')).read_text().strip()})
run('restore-numeric',flags+['-D__COMPCERT__','-include','oracles/compcert_memory_host.h','-c','c/Arm64Numeric.c','-o',objects[2]])
run('restore-oracle',flags+['oracles/test_arm64_execute_host.c']+objects+['-o','build/test_arm64_execute_host'])
run('restored-baseline',['./build/test_arm64_execute_host'])
(a.output/'mutations.json').write_text(json.dumps(mutation_results,indent=2)+'\n')
print(json.dumps(mutation_results,indent=2))
