"""Compile native test inputs with installed tools; test actual imported C dispatch."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

root=Path('/workspaces/repository'); here=Path(__file__).resolve().parent
out=Path(sys.argv[1]);mode=sys.argv[2];assert mode in {'before','after'}
out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/dynamic-array-c');build.mkdir(parents=True,exist_ok=True)
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
import inline_array
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
types=inline_array.KernelTypes(kernel)
try:
    mapping=types.lib.btf__find_by_name_kind(types.btf,b'bpf_map',4)
    array=types.lib.btf__find_by_name_kind(types.btf,b'bpf_array',4)
    ops=types.lib.btf__find_by_name_kind(types.btf,b'bpf_map_ops',4)
    offset=inline_array.field_offset;base=offset(types,array,'map')
    layout=dict(TYPE=offset(types,mapping,'map_type'),OPS=offset(types,mapping,'ops'),
                LOOKUP=offset(types,ops,'map_lookup_elem'),LIMIT=offset(types,mapping,'max_entries'),
                STRIDE=offset(types,array,'elem_size')-base,MASK=offset(types,array,'index_mask')-base,
                VALUES=offset(types,array,'value')-base)
finally:types.close()
commands=[]
def run(args):
    args=list(map(str,args));p=subprocess.run(args,capture_output=True,text=True)
    commands.append(dict(command=args,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode();return p.stdout
source=inline_array.lookup_source(kernel)
if mode=='after':source+=inline_array.dynamic_lookup_source(kernel)
(build/'helpers.c').write_text(source)
run(['clang-18','-target','bpf','-O1','-emit-llvm','-c',
     root/'kprog/results/percpu-array-c-20261120/fixture.c','-o',build/'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',build/'input.bc',
     '-o',build/'native.bc','--array-map','counts','--array-map','same'])
flags=['-target','x86_64-linux-gnu','-O3','-march=native','-foptimize-sibling-calls',
       '-fomit-frame-pointer','-mno-red-zone','-mgeneral-regs-only','-fno-stack-protector',
       '-fno-asynchronous-unwind-tables','-fno-unwind-tables']
run(['clang-18',*flags,'-emit-llvm','-c',build/'helpers.c','-o',build/'helpers.bc'])
run(['llvm-link-18',build/'native.bc',build/'helpers.bc','-o',build/'linked.bc'])
run(['clang-18',*flags,'-mllvm','-force-attribute=noredzone','-c',build/'linked.bc','-o',build/'native.o'])
assembly=run(['llvm-objdump-18','-dr',build/'native.o']);(out/'native.asm').write_text(assembly)
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all','-DBEFORE='+str(int(mode=='before')),
     *['-D'+k+'='+str(v) for k,v in layout.items()],here/'driver.c',build/'native.o','-o',build/'execute'])
execution=run([build/'execute'])
with tarfile.open(out/'native-inputs.tar.gz','w:gz') as archive:archive.add(build,arcname=build.name)
(out/'report.json').write_text(json.dumps(dict(mode=mode,layout=layout,execution=execution,
    scope='Actual installed BPF-to-native lowering plus C/host map-op providers, not live kernel callback or app performance.'),indent=2)+'\n')
print(execution,end='')
