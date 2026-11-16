#!/usr/bin/env python3
"""Run the actual readonly oracle and reject three C-adapter regressions."""
import argparse
import json
from pathlib import Path
import re
import subprocess

FORMAL=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args();a.output=a.output.resolve();a.output.mkdir(parents=True,exist_ok=False)
flags=['cc','-std=c11','-Wall','-Wextra','-O1','-fsanitize=undefined','-fno-sanitize-recover=undefined',
       '-I../../vendor/libbpf/include/uapi','-I../../vendor/libbpf/src','-iquote',str(FORMAL/'oracles'),'-iquote',str(FORMAL/'build')]
exe='build/test_x86_readonly_host';source=FORMAL/'oracles/test_x86_readonly_host.c'
program=FORMAL/'build/x86_readonly_profile.bpf.c';body=program.read_text()
commands=[];results={}
def run(name,cmd,text=None,expected=0):
    r=subprocess.run(list(map(str,cmd)),cwd=FORMAL,input=text,text=True,capture_output=True)
    (a.output/(name+'.log')).write_text(r.stdout+r.stderr);commands.append(dict(name=name,argv=list(map(str,cmd)),exit=r.returncode))
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if r.returncode!=expected:raise SystemExit(f'{name}: exit {r.returncode}, expected {expected}')
    return r

def compile_case(name,adapter,text=None):
    opts=['-D__COMPCERT__'] if adapter else []
    unit=['-x','c','-','-x','none'] if text is not None else [str(source)]
    run(name+'-compile',flags+opts+unit+['build/x86_readonly_profile.native.o','-o',exe],text)
for adapter in [0,1]:
    name='positive-'+str(adapter);compile_case(name,adapter);r=run(name,['./'+exe])
    results[name]=r.stdout.strip()
assert body.count('__u64 value = 0;')==53
assert body.count('(OUTPUT) = __x86_ro_into;')==1
mutants={
    'missing-zero-init':body.replace('__u64 value = 0;','__u64 value = ~0ULL;'),
    'lost-output':body.replace('(OUTPUT) = __x86_ro_into;','(OUTPUT) = 0;'),
    'copy-width-eight':re.sub(r'(KPROG_C_COPY_BYTES\(&value, __x86_rodata_0 \+ \d+, )\d+(\);)',r'\g<1>8\2',body)}
include='#include "../build/x86_readonly_profile.bpf.c"';observer=source.read_text();assert observer.count(include)==1
for name,changed in mutants.items():
    assert changed!=body
    text=f'#line 1 "{source}"\n'+observer.replace(include,f'#line 1 "{program}"\n'+changed+f'\n#line 15 "{source}"')
    compile_case(name,1,text);r=run(name,['./'+exe],expected=1)
    if 'readonly mismatch' not in r.stderr:raise SystemExit(name+': missing intended diagnostic')
    results[name]={'rejected':True}
compile_case('restore',1);run('restore',['./'+exe])
(a.output/'results.json').write_text(json.dumps(results,indent=2)+'\n');print(json.dumps(results,indent=2))
