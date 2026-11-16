#!/usr/bin/env python3
"""Check real producer context entries and reject pointer/context mutations."""
import argparse
import json
from pathlib import Path
import subprocess

FORMAL=Path(__file__).resolve().parents[2]
ROOT=FORMAL.parents[1]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args();a.output=a.output.resolve();a.output.mkdir(parents=True,exist_ok=False)
commands=[];results={}
flags=['cc','-std=c11','-O1','-fsanitize=undefined','-fno-sanitize-recover=undefined',
       '-I../../vendor/libbpf/include/uapi','-I../../vendor/libbpf/src']
obj='build/x86_context_program_host.o';binary='build/test_x86_context_program_host'
def run(name,cmd,source=None,expected=0):
    r=subprocess.run(list(map(str,cmd)),cwd=FORMAL,input=source,text=True,capture_output=True)
    (a.output/(name+'.log')).write_text(r.stdout+r.stderr)
    commands.append(dict(name=name,argv=list(map(str,cmd)),exit=r.returncode))
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if r.returncode!=expected:raise SystemExit(f'{name}: exit {r.returncode}, expected {expected}')
    return r

def build(name,skb,adapter,source=None):
    program='build/x86_context_'+('skb' if skb else 'xdp')+'.bpf.c'
    opts=['-DKPROG_X86_PROGRAM_EXPORT=1','-D__bpf_fastcall=']+(['-D__COMPCERT__'] if adapter else [])
    opts+=['-include','oracles/compcert_memory_host.h','-include','oracles/x86_program_environment_host.h']
    if source is None:unit=['-c',program]
    else:unit=['-iquote',str(FORMAL/'build'),'-iquote',str(ROOT/'kprog/x86'),'-x','c','-c','-']
    run(name+'-compile',flags+opts+unit+['-o',obj],source)
    run(name+'-link',flags+[f'-DSKB={skb}',f'-DADAPTER={adapter}',
        'oracles/test_x86_context_program_host.c',obj,'-o',binary])
    return program

for skb in [0,1]:
    for adapter in [0,1]:
        name=f'positive-{skb}-{adapter}';build(name,skb,adapter)
        run(name,['./'+binary]);results[name]={'returns':16,'refusal_prefixes':16}

header=ROOT/'kprog/x86/x86_sim_local_bpf.h'
original=header.read_text()
mutants={
    'pointer-low32':original.replace('((__u64)(unsigned long)kprog_c_context_pointer',
                                     '((__u32)(unsigned long)kprog_c_context_pointer'),
    'wrong-helper-context':original.replace('__x86_sim_helper_abi_base, __x86_sim_helper_ctx)',
                                            '__x86_sim_helper_abi_base, (void *)0)')}
assert original.count('((__u64)(unsigned long)kprog_c_context_pointer')==2
assert original.count('__x86_sim_helper_abi_base, __x86_sim_helper_ctx)')==1
for skb in [0,1]:
    program=FORMAL/('build/x86_context_'+('skb' if skb else 'xdp')+'.bpf.c')
    text=program.read_text();include='#include "../../x86/x86_sim_local_bpf.h"'
    assert text.count(include)==1
    for name,body in mutants.items():
        source=f'#line 1 "{program}"\n'+text.replace(include,f'#line 1 "{header}"\n'+body+f'\n#line 5 "{program}"')
        case=f'{name}-{skb}';build(case,skb,1,source)
        r=run(case,['./'+binary],expected=1)
        if 'x86 context program mismatch' not in r.stderr:raise SystemExit(case+': missing intended diagnostic')
        results[case]={'rejected':True}
# Restore ordinary products after the last in-memory mutation.
build('restore',1,1);run('restore',['./'+binary])
(a.output/'results.json').write_text(json.dumps(results,indent=2)+'\n')
print(json.dumps(results,indent=2))
