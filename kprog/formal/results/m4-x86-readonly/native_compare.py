#!/usr/bin/env python3
"""Compare actual readonly producer C across the emitter adaptation."""
import argparse
import ast
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

FORMAL=Path(__file__).resolve().parents[2];ROOT=FORMAL.parents[1]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--output',type=Path,required=True)
p.add_argument('--before',default='a85db64d2')
a=p.parse_args();a.output=a.output.resolve();a.output.mkdir(parents=True,exist_ok=False)
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as producer
script=FORMAL/'tools/compare_c_header.py'
spec=importlib.util.spec_from_file_location('native_compare_helpers',script)
helper=importlib.util.module_from_spec(spec);spec.loader.exec_module(helper)
old=subprocess.check_output(['git','show',a.before+':kprog/x86/micro-prog/generate_micro_sim_proofs.py'],cwd=ROOT,text=True)
node=next(n for n in ast.parse(old).body if isinstance(n,ast.FunctionDef) and n.name=='readonly_load_declarations')
namespace=dict(producer.__dict__);exec(compile(ast.get_source_segment(old,node),'<historical readonly emitter>','exec'),namespace)
current=producer.readonly_load_declarations
instructions,functions,end,data=producer.parse_proof_object_program('x86_readonly_profile',FORMAL/'build')
source=FORMAL/'build/x86_readonly_profile.bpf.c';product=FORMAL/'build/x86_readonly_profile.bpf.o';unit=FORMAL/'build/x86_readonly_profile.i'
def render(emitter):
    producer.readonly_load_declarations=emitter
    try:s=producer.render_program('x86_readonly_profile',instructions,functions,kind='raw',program_section='socket',exit_addr=end,rodata16=data)
    finally:producer.readonly_load_declarations=current
    return s.replace('#include "../x86_sim_local_bpf.h"','#include "../../x86/x86_sim_local_bpf.h"')
previous=render(namespace['readonly_load_declarations']);present=render(current)
assert source.read_text()==present
flags=[str(ROOT/'kprog/stock-path/bin/clang'),'-g','-O2','-mcpu=v4','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_x86','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-iquote',str(source.parent),'-iquote',str(ROOT/'kprog/x86')]
commands=[]
def run(name,cmd,text=None):
    r=subprocess.run(list(map(str,cmd)),cwd=FORMAL,input=text,text=True,capture_output=True)
    (a.output/(name+'.log')).write_text(r.stdout+r.stderr);commands.append(dict(name=name,argv=list(map(str,cmd)),exit=r.returncode))
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');r.check_returncode()
observed={}
for name,text in [('before',previous),('after',present)]:
    run(name+'-preprocess',flags+['-E','-x','c','-','-o',unit],f'#line 1 "{source}"\n'+text)
    run(name+'-compile',flags+['-c',unit,'-o',product]);observed[name]=helper.allocated(product)
run('normal-compile',flags+['-c',source,'-o',product]);normal=helper.allocated(product)
assert observed['before']==observed['after']==normal,'readonly default BPF output changed'
sections,relocs=normal
result={'before':a.before,'allocated_sections_equal':True,'allocated_relocations_equal':True,'current_stream_equals_normal_build':True,'allocated_section_bytes':{n:len(v) for n,v in sections.items()},'allocated_relocations':len(relocs),'readonly_objects':{n:len(v) for n,v in data.items()}}
(a.output/'result.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
