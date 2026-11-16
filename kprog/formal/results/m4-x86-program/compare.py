#!/usr/bin/env python3
"""Compare the real rendered program and replay defined control/ABI negatives."""
import argparse
import json
from pathlib import Path
import re
import subprocess

ROOT=Path(__file__).resolve().parents[4]
FORMAL=ROOT/'kprog/formal'
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output',type=Path,required=True)
a=parser.parse_args();a.output.mkdir(parents=True,exist_ok=False)
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
       '-I../../vendor/libbpf/include/uapi','-I../../vendor/libbpf/src']
environment=['-include','oracles/compcert_memory_host.h','-include','oracles/x86_program_environment_host.h']
bound=['-D__COMPCERT__','-DKPROG_X86_PROGRAM_EXPORT=1']
program=FORMAL/'build/x86_program_profile.bpf.c'
obj='build/x86_program_profile_host.o';binary='build/test_x86_program_profile_host'
observer='oracles/test_x86_program_profile_host.c'
results={}
for mode in ['native','bound']:
    run(mode+'-compile',flags+(bound if mode=='bound' else [])+environment+['-c',str(program),'-o',obj])
    run(mode+'-link',flags+[observer,obj,'-o',binary])
    path=a.output/(mode+'.bin')
    run(mode,['./'+binary,'--capture'],capture=path)
    results[mode]=dict(bytes=path.stat().st_size,summary=(a.output/(mode+'.log')).read_text().strip())
if (a.output/'native.bin').read_bytes()!=(a.output/'bound.bin').read_bytes():
    raise SystemExit('actual producer return/input/callee prefixes differ')

inline=ROOT/'kprog/x86/x86_sim_inline.h'
callees=FORMAL/'c/X86ProgramCallees.h';calls=FORMAL/'c/X86HelperCalls.h'
abi=FORMAL/'oracles/test_x86_program_callee_abi.c'
expanded={program,inline,callees,calls,abi}
def source(path,mutation):
    body=path.read_text()
    if path==mutation[0]:
        expected_count = 2 if mutation[1] == "X86_SIM_HELPER_bpf_ktime_get_ns" else 1
        assert body.count(mutation[1])==expected_count,(path,mutation[1],body.count(mutation[1]))
        body=body.replace(mutation[1],mutation[2])
    def include(m):
        child=(path.parent/m[1]).resolve()
        return source(child,mutation) if child in expanded else '#include "'+str(child)+'"'
    return '#line 1 "'+str(path)+'"\n'+re.sub(r'^\s*#include "([^"]+)"',include,body,flags=re.M)
mutants={
    'missing-tail-helper':((program,
        'x86_l_3a:\n\tX86_SIM_RUN_OP(X86_OP_CALL_HELPER, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, X86_SIM_HELPER_bpf_ktime_get_ns);',
        'x86_l_3a:'), 'x86 producer program mismatch'),
    'unknown-return-case':((program,'case 0xfULL: goto x86_l_f;','case 0x10ULL: goto x86_l_f;'),
                           'unexpected x86 return continuation'),
    'wrong-helper-id':((program,'X86_SIM_HELPER_bpf_ktime_get_ns','X86_SIM_HELPER_bpf_get_prandom_u32'),
                        'unexpected x86 helper identity'),
    'stack-base-low32':((inline,'#define __x86_native_stack_base (*__x86_bind->native_stack_base)',
                         '#define __x86_native_stack_base ((__u32)*__x86_bind->native_stack_base)'),
                         'x86 producer program mismatch'),
    'missing-ret-release':((inline,'X86_SIM_L_STACK_RELEASE((__s64)(long)__x86_rsp.ptr - 8);','((void)0);'),
                            'x86 producer program mismatch')}
for name,(mutation,diagnostic) in mutants.items():
    run(name+'-compile',flags+bound+environment+['-x','c','-c','-','-o',obj],source(program,mutation))
    run(name+'-link',flags+[observer,obj,'-o',binary])
    run(name,['./'+binary],expected=1)
    if diagnostic not in (a.output/(name+'.log')).read_text():raise SystemExit(name+': missing intended diagnostic')
bad=(calls,'KPROG_X86_HELPER(5, bpf_ktime_get_ns, __u64,','KPROG_X86_HELPER(5, bpf_ktime_get_ns, __u32,')
run('callee-abi-negative',flags+['-x','c','-c','-','-o','build/test_x86_program_callee_abi.o'],source(abi,bad),expected=1)
if 'x86 program callee ABI' not in (a.output/'callee-abi-negative.log').read_text():
    raise SystemExit('callee ABI negative: missing intended diagnostic')
run('restore-abi',flags+['-c',str(abi),'-o','build/test_x86_program_callee_abi.o'])
run('restore-program',flags+bound+environment+['-c',str(program),'-o',obj])
run('restore-link',flags+[observer,obj,'-o',binary])
run('restore',['./'+binary,'--capture'],capture=a.output/'restored.bin')
if (a.output/'restored.bin').read_bytes()!=(a.output/'bound.bin').read_bytes():
    raise SystemExit('restored actual program capture differs')
results['negatives']=[*mutants,'callee-abi-negative']
results['comparison']='all return/callee/input/prefix bytes equal; no masks; normal products restored'
(a.output/'results.json').write_text(json.dumps(results,indent=2)+'\n');print(json.dumps(results,indent=2))
