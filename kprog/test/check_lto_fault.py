"""Catch dropping verifier-visible architectural faults during native LTO."""
import ctypes
import json
from pathlib import Path
import resource
import signal
import subprocess
import sys

if sys.argv[1]=='--fault-child':
    resource.setrlimit(resource.RLIMIT_CORE,(0,0))
    library=ctypes.CDLL(sys.argv[2])
    execute=getattr(library,sys.argv[3])
    execute.argtypes=[ctypes.c_uint]
    execute(0)
    raise AssertionError('LTO fault returned normally')

compiler, output = map(Path,sys.argv[1:])
root=Path(__file__).resolve().parents[2]
output.mkdir(parents=True)
commands=[]

def run(command, expected=0):
    done=subprocess.run([str(x) for x in command],capture_output=True,text=True)
    commands.append(dict(command=[str(x) for x in command],returncode=done.returncode,
                         stdout=done.stdout,stderr=done.stderr))
    (output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if done.returncode!=expected:
        raise RuntimeError(f'command exit {done.returncode}, expected {expected}: {done.stderr}')
    return done

source=root/'kprog/test/lto_fault.c'
prefix=root/'runner/build-llvmbpf/vendor/libbpf/prefix/include/bpf'
frontend=['clang-18','-target','bpf','-mcpu=v4','-O2','-emit-llvm','-I'+str(root),
          '-I'+str(prefix),'-I/usr/include/x86_64-linux-gnu','-c',source]
run([*frontend,'-o',output/'source.bc'])
run([compiler,output/'source.bc','-o',output/'native.bc'])
run(['llvm-dis-18',output/'native.bc','-o',output/'native.ll'])
run(['clang-18','-O3','-shared','-fPIC','-mgeneral-regs-only',output/'native.bc','-o',output/'fixture.so'])
library=ctypes.CDLL(str(output/'fixture.so'))
cases=[]
for name in ['architectural_fault','dispatch_fault']:
    execute=getattr(library,name)
    execute.argtypes=[ctypes.c_uint]
    execute.restype=ctypes.c_uint
    for value in [1,7,0x7fffffff,0xffffffff]:
        actual=execute(value)
        expected=(value+3)&0xffffffff
        if actual!=expected: raise AssertionError((name,value,actual,expected))
        cases.append(dict(function=name,value=value,actual=actual))
    run([sys.executable,Path(__file__).resolve(),'--fault-child',output/'fixture.so',name],-signal.SIGILL)
run([*frontend,'-DUNKNOWN_ASM','-o',output/'unknown.bc'])
run([compiler,output/'unknown.bc','-o',output/'unknown.native.bc'],1)
result=dict(safe_vectors=cases,faulting_children=2,unknown_asm_rejected=True,
            scope='Native LTO compiler host regression, not application execution or verifier acceptance')
(output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(dict(safe_vectors=len(cases),faulting_children=2,unknown_asm_rejected=True)))
