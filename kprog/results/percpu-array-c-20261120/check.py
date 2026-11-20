"""Native program/helper compilation with installed tools, never a tool build."""
import json
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository');here=Path(__file__).resolve().parent
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/percpu-array-c');build.mkdir(parents=True,exist_ok=True)
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
from inline_array import lookup_source,field_offset,KernelTypes
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
types=KernelTypes(kernel)
try:
    array=types.lib.btf__find_by_name_kind(types.btf,b'bpf_array',4)
    mapping=types.lib.btf__find_by_name_kind(types.btf,b'bpf_map',4)
    base=field_offset(types,array,'map')
    layout=dict(LIMIT=field_offset(types,mapping,'max_entries'),
                MASK=field_offset(types,array,'index_mask')-base,
                STRIDE=field_offset(types,array,'elem_size')-base,
                PPTRS=field_offset(types,array,'pptrs')-base)
finally:
    types.close()
commands=[]
def run(args):
    args=list(map(str,args));p=subprocess.run(args,capture_output=True,text=True)
    commands.append(dict(command=args,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode();return p.stdout
(build/'helpers.c').write_text(lookup_source(kernel,percpu_arrays=['counts','same']))
run(['clang-18','-target','bpf','-O1','-emit-llvm','-c',here/'fixture.c','-o',build/'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',build/'input.bc',
     '-o',build/'native.bc','--helper-list',build/'helpers.txt','--array-map','counts','--array-map','same'])
run(['clang-18','-O3','-march=native','-mgeneral-regs-only','-mno-red-zone',
     '-fomit-frame-pointer','-fno-stack-protector','-emit-llvm','-c',build/'helpers.c','-o',build/'helpers.bc'])
run(['llvm-link-18',build/'native.bc',build/'helpers.bc','-o',build/'linked.bc'])
run(['clang-18','-O3','-march=native','-mgeneral-regs-only','-mno-red-zone',
     '-mllvm','-force-attribute=noredzone','-fomit-frame-pointer','-fno-stack-protector',
     '-c',build/'linked.bc','-o',build/'native.o'])
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
     *['-D'+k+'='+str(v) for k,v in layout.items()],here/'driver.c',build/'native.o','-o',build/'execute'])
result=run([build/'execute'])
(out/'native.asm').write_text(run(['llvm-objdump-18','-dr',build/'native.o']))
(out/'report.json').write_text(json.dumps(dict(layout=layout,execution=result.strip(),
    scope='Actual installed lookup ABI and native C key/bounds/mask/pptr/alias behavior. CPU translation uses a host stub; kernel helper behavior and app performance require live execution.'),indent=2)+'\n')
print(result,flush=True)
