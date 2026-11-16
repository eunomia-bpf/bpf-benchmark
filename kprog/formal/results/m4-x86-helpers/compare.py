#!/usr/bin/env python3
"""Replay actual helper bindings, then mutate one boundary at a time in RAM."""
import argparse
import json
from pathlib import Path
import re
import subprocess

ROOT=Path(__file__).resolve().parents[4]
FORMAL=ROOT/'kprog/formal'
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output',type=Path,required=True)
a=parser.parse_args()
a.output.mkdir(parents=True,exist_ok=False)
commands=[]
def run(name,argv,source=None,capture=None,expected=0):
    with (a.output/(name+'.log')).open('w') as log:
        if capture:
            with capture.open('wb') as output:
                p=subprocess.run(argv,cwd=FORMAL,input=source,text=True,stdout=output,stderr=log)
        else:p=subprocess.run(argv,cwd=FORMAL,input=source,text=True,stdout=log,stderr=log)
    commands.append(dict(name=name,argv=argv,exit=p.returncode))
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if p.returncode!=expected:raise SystemExit(f'{name}: exit {p.returncode}, expected {expected}')

flags=['cc','-std=c11','-Wall','-Wextra','-O1','-fsanitize=undefined','-fno-sanitize-recover=undefined',
       '-include','oracles/compcert_memory_host.h','-I../../vendor/libbpf/include/uapi','-I../../vendor/libbpf/src']
objects=['build/x86_helpers_binding.o','build/x86_pointer_binding.o']
binary='build/test_x86_helpers_binding_host'
results={}
for mode in ['native','adapter']:
    extra=['-D__COMPCERT__'] if mode=='adapter' else []
    for filename,obj in zip(['X86Helpers','X86Pointer'],objects):
        run(mode+'-'+filename,flags+extra+['-c','c/'+filename+'.c','-o',obj])
    run(mode+'-oracle',flags+['oracles/test_x86_helpers_binding_host.c',*objects,'-o',binary])
    path=a.output/(mode+'.bin')
    run(mode,['./'+binary,'--capture'],capture=path)
    results[mode]=dict(bytes=path.stat().st_size,summary=(a.output/(mode+'.log')).read_text().strip())
# Each process compares native/reference and bound observations at identical
# addresses. Captures retain raw pointer bits; ASLR is not masked or normalized.

helper=FORMAL/'c/X86Helpers.c'
local=ROOT/'kprog/x86/x86_sim_local_bpf.h'
calls=FORMAL/'c/X86HelperCalls.h'
expanded={helper,FORMAL/'c/X86Helpers.h',FORMAL/'c/X86Pointer.h',local,calls}
def source(path,mutation):
    body=path.read_text()
    if path==mutation[0]:
        assert body.count(mutation[1])==1,(path,mutation[1],body.count(mutation[1]))
        body=body.replace(mutation[1],mutation[2])
    def include(m):
        child=(path.parent/m[1]).resolve()
        return source(child,mutation) if child in expanded else '#include "'+str(child)+'"'
    return '#line 1 "'+str(path)+'"\n'+re.sub(r'^\s*#include "([^"]+)"',include,body,flags=re.M)

mutants={
    'capacity-frozen64':(helper,'kprog_x86_read_reg(state, arena, capacity,','kprog_x86_read_reg(state, arena, 64,'),
    'fact-pointer-slot0':(helper,'#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)',
                         '#define X86_SIM_L_SV_PTR(I) (*facts[0].pointer)'),
    'output-length-low8':(local,'__x86_hw_size=(__u32)X86_SIM_L_READ_REG(SIZE)',
                         '__x86_hw_size=(__u8)X86_SIM_L_READ_REG(SIZE)'),
    'void-result-one':(local,'(EXPR); X86_SIM_L_HELPER_SCALAR_RESULT(0ULL)',
                       '(EXPR); X86_SIM_L_HELPER_SCALAR_RESULT(1ULL)'),
    'clobber-xmm-high':(local,'        __x86_xmm0_hi = X86_SIM_L_UNSPECIFIED();',
                        '        __x86_xmm0_hi = 0;'),
    'map-update-arguments':(local,
        'bpf_map_update_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX),',
        'bpf_map_update_elem((void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDI), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RDX), (const void *)X86_SIM_L_HELPER_ARG_PTR(X86_RSI),')}
for name,mutation in mutants.items():
    run(name+'-compile',flags+['-D__COMPCERT__','-x','c','-c','-','-o',objects[0]],source(helper,mutation))
    run(name+'-link',flags+['oracles/test_x86_helpers_binding_host.c',*objects,'-o',binary])
    run(name,['./'+binary],expected=1)
    if 'x86 helper binding mismatch' not in (a.output/(name+'.log')).read_text():
        raise SystemExit(name+': missing intended diagnostic')
abi=FORMAL/'oracles/test_x86_helper_abi.c'
bad=(calls,'KPROG_X86_HELPER(5, bpf_ktime_get_ns, __u64,','KPROG_X86_HELPER(5, bpf_ktime_get_ns, __u32,')
run('callee-abi-negative',flags+['-x','c','-c','-','-o','build/test_x86_helper_abi.o'],source(abi,bad),expected=1)
if 'x86 helper callee ABI' not in (a.output/'callee-abi-negative.log').read_text():
    raise SystemExit('callee ABI negative: missing intended diagnostic')
run('restore-abi',flags+['-c',str(abi),'-o','build/test_x86_helper_abi.o'])
run('restore-helper',flags+['-D__COMPCERT__','-c','c/X86Helpers.c','-o',objects[0]])
run('restore-oracle',flags+['oracles/test_x86_helpers_binding_host.c',*objects,'-o',binary])
run('restore',['./'+binary])
results['negatives']=[*mutants,'callee-abi-negative']
results['comparison']='paired registry and alias/refusal checks within each process; raw captures retain pointer bits; normal products restored'
(a.output/'results.json').write_text(json.dumps(results,indent=2)+'\n')
print(json.dumps(results,indent=2))
