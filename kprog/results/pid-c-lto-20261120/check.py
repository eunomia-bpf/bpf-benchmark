"""Use the installed compiler and real shared header's PID macro."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

root=Path('/workspaces/repository');here=Path(__file__).resolve().parent
out=Path(sys.argv[1]);mode=sys.argv[2];assert mode in {'before','after'}
out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/pid-c-lto');build.mkdir(parents=True,exist_ok=True)
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
from inline_scalar import pid_source
from inline_array import KernelTypes,field_offset
kernel='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
types=KernelTypes(kernel)
try:
    task=types.lib.btf__find_by_name_kind(types.btf,b'task_struct',4)
    offsets={name:field_offset(types,task,name.lower()) for name in ['PID','TGID']}
finally:types.close()
commands=[]
def run(args):
    args=list(map(str,args));p=subprocess.run(args,capture_output=True,text=True)
    commands.append(dict(command=args,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode();return p.stdout
run(['clang-18','-target','bpf','-O1','-emit-llvm','-c',here/'fixture.c','-o',build/'input.bc'])
run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',build/'input.bc','-o',build/'native.bc'])
flags=['-target','x86_64-linux-gnu','-O3','-march=native','-foptimize-sibling-calls',
       '-fomit-frame-pointer','-mno-red-zone','-mgeneral-regs-only','-fno-stack-protector',
       '-fno-asynchronous-unwind-tables','-fno-unwind-tables']
lowered=build/'native.bc'
if mode=='after':
    (build/'pid.c').write_text(pid_source(kernel))
    run(['clang-18',*flags,'-emit-llvm','-c',build/'pid.c','-o',build/'pid.bc'])
    run(['llvm-link-18',lowered,build/'pid.bc','-o',build/'linked.bc']);lowered=build/'linked.bc'
run(['clang-18',*flags,'-mllvm','-force-attribute=noredzone','-c',lowered,'-o',build/'native.o'])
(out/'native.asm').write_text(run(['llvm-objdump-18','-dr',build/'native.o']))
run(['gcc','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
     '-DBEFORE='+str(int(mode=='before')),'-DMAX_OFFSET='+str(max(offsets.values())),
     *['-D'+key+'='+str(value) for key,value in offsets.items()],here/'driver.c',build/'native.o','-o',build/'execute'])
execution=run([build/'execute'])
run([root/'kprog/x86/native_lab/native_link/target/release/native-link','--input',build/'native.o',
     '--symbol','two_pids','--mode','proof','--preserve-entry-abi','--output',build/'pid.proof.o'])
(out/'report.json').write_text(json.dumps(dict(mode=mode,offsets=offsets,execution=execution,
    proof_linked=True,scope='Imported native helper/header ABI and arithmetic, current-task host provider; no live-kernel timing or app-equivalence claim'),indent=2)+'\n')
with tarfile.open(out/'native-inputs.tar.gz','w:gz') as archive:archive.add(build,arcname='program-inputs')
print(execution,end='')
