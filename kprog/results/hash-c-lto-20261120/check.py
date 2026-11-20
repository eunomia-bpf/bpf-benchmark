"""Compile native program/helper C with existing tools; never build a tool."""
import json
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository')
here=Path(__file__).resolve().parent
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/hash-c-lto');build.mkdir(parents=True,exist_ok=True)
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
from inline_array import lookup_source,hash_layout
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
compiler='/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'
commands=[]
def run(args):
    args=list(map(str,args));p=subprocess.run(args,capture_output=True,text=True)
    commands.append(dict(command=args,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode();return p.stdout
layout=hash_layout(kernel)
(build/'helpers.c').write_text(lookup_source(kernel,hashes=[('map_a',8),('map_b',16)]))
run(['clang-18','-target','bpf','-O1','-emit-llvm','-c',here/'fixture.c','-o',build/'input.bc'])
run([compiler,build/'input.bc','-o',build/'native.bc','--helper-list',build/'helpers.txt',
     '--array-map','map_a','--array-map','map_b'])
helpers=(build/'helpers.txt').read_text().splitlines()
assert helpers==['__kprog_array_lookup'],helpers
run(['clang-18','-O3','-mgeneral-regs-only','-emit-llvm','-c',build/'helpers.c','-o',build/'helpers.bc'])
run(['llvm-link-18',build/'native.bc',build/'helpers.bc','-o',build/'linked.bc'])
run(['clang-18','-O3','-march=native','-mgeneral-regs-only','-mno-red-zone',
     '-fomit-frame-pointer','-fno-stack-protector','-c',build/'linked.bc','-o',build/'native.o'])
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
     '-I'+str(root/'vendor/linux-framework/include'),
     *['-D'+k.upper()+'='+str(v) for k,v in layout.items()],here/'driver.c',build/'native.o','-o',build/'execute'])
execution=run([build/'execute'])
undefined=run(['llvm-nm-18','--undefined-only',build/'native.o'])
report=dict(layout=layout,helpers=helpers,execution=execution.strip(),undefined_symbols=undefined,
    raw=str(out),scope='Kernel-header hash oracle, native helper C and installed compiler ABI, including mixed key shapes/generic retention/nulls restart. No stock/app/performance result.')
(out/'report.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2),flush=True)
