"""Catch lost ghost tags from omitted alias destinations or sparse bindings."""
import fcntl
import ctypes
import json
from pathlib import Path
import re
import subprocess
import sys

root=Path('/workspaces/repository')
sys.path[0]=str(root/'kprog/x86')
import trusted_specializer as adapter
gen=adapter.gen
out,build=map(Path,sys.argv[1:])
out.mkdir(parents=True,exist_ok=True)
build.mkdir(parents=True,exist_ok=True)
commands=[]
def run(command):
    command=list(map(str,command))
    p=subprocess.run(command,text=True,capture_output=True)
    commands.append(dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode()
    return p.stdout

cases={
 'direct':(['sub rsp,0x40','mov QWORD PTR [rsp+0x8],rdi'],[1]),
 'alias':(['sub rsp,0x40','lea rbx,[rsp+0x28]','mov QWORD PTR [rbx],rdi'],[5]),
 'unaligned':(['sub rsp,0x40','mov QWORD PTR [rsp+0x9],rdi'],[]),
 'narrow':(['sub rsp,0x40','mov DWORD PTR [rsp+0x8],edi'],[]),
 'external':(['sub rsp,0x40','mov QWORD PTR [rdi],rsp'],[]),
 'unknown':(['sub rsp,0x40','mov rcx,QWORD PTR [rdi]','mov QWORD PTR [rsp+rcx],rdi'],list(range(8))),
 'register_add':(['sub rsp,0x40','lea rbx,[rsp+0x8]','mov rcx,QWORD PTR [rdi]',
                 'add rbx,rcx','mov QWORD PTR [rbx],rdi'],list(range(8))),
 'unknown_inc':(['sub rsp,0x40','lea rbx,[rsp+0x8]','mov rcx,QWORD PTR [rdi]',
                 'add rbx,rcx','inc rbx','mov QWORD PTR [rbx],rdi'],list(range(8))),
 'scalar_plus_pointer':(['sub rsp,0x40','mov rbx,0x8','add rbx,rsp',
                        'mov QWORD PTR [rbx],rdi'],list(range(8))),
 'index_pointer':(['sub rsp,0x40','lea rbx,[rsp+0x8]','lea rcx,[rbx*1]',
                   'mov QWORD PTR [rcx],rdi'],list(range(8))),
 'unknown_rsp':(['mov rsp,rdi','mov QWORD PTR [rsp],rdi'],[0]),
 'zero_shift':(['sub rsp,0x40','lea rbx,[rsp+0x8]','shl rbx,0',
                'mov QWORD PTR [rbx],rdi'],[1]),
 'zero_rotate':(['sub rsp,0x40','lea rbx,[rsp+0x8]','ror rbx,0',
                 'mov QWORD PTR [rbx],rdi'],[1]),
 'unknown_shift':(['sub rsp,0x40','lea rbx,[rsp+0x8]','mov rcx,QWORD PTR [rdi]',
                   'shl rbx,cl','mov QWORD PTR [rbx],rdi'],list(range(8))),
 'conditional_memory':(['sub rsp,0x40','lea rbx,[rsp+0x8]','test edi,edi',
                        'cmove rbx,QWORD PTR [rdi]','mov QWORD PTR [rbx],rdi'],[1]),
 'join':(['sub rsp,0x40','test edi,edi','je 0x5','lea rbx,[rsp+0x8]',
          'jmp 0x6','lea rbx,[rsp+0x28]','mov QWORD PTR [rbx],rdi'],[1,5]),
 'loop':(['sub rsp,0x40','lea rbx,[rsp+0x8]','mov QWORD PTR [rbx],rdi',
          'add rbx,0x8','test edi,edi','jne 0x2'],list(range(8))),
 'partial':(['sub rsp,0x40','mov QWORD PTR [rsp+0x8],rdi',
             'mov BYTE PTR [rsp+0x9],0'],[1]),
 'immediate':(['sub rsp,0x40','mov QWORD PTR [rsp+0x28],0x12345678',
               'mov rax,QWORD PTR [rsp+0x28]'],[]),
 'immediate_unknown':(['sub rsp,0x40','mov rcx,QWORD PTR [rdi]',
                       'mov QWORD PTR [rsp+rcx],0'],[]),
 'immediate_erases':(['sub rsp,0x40','mov QWORD PTR [rsp+0x8],rdi',
                      'mov QWORD PTR [rsp+0x8],0'],[1]),
}
rows=[]
b_sources={}
for name,(assembly,expected) in cases.items():
    assembly=assembly+['add rsp,0x40']+([] if name=='immediate' else ['xor eax,eax'])+['ret']
    instructions=[]
    for pc,text in enumerate(assembly):
        op,operands=text.split(' ',1) if ' ' in text else (text,'')
        instructions.append(gen.NativeInsn(pc,text,op,gen.split_operands(operands)))
    source=gen.render_program(name,instructions,kind='raw',program_section='kprobe/trusted')
    declaration=next(line for line in source.splitlines() if line.startswith('#define X86_SIM_STACK_VALUE_WORDS'))
    words=[int(word) for word in re.findall(r'M\((\d+)\)',declaration)]
    rows.append(dict(case=name,expected=expected,observed=words))
    (out/'selection.json').write_text(json.dumps(rows,indent=2)+'\n')
    assert words==expected,(name,expected,words)
    if name in {'direct','join','narrow','immediate'}:
        b_sources[name]=source

observations={}
for mode,words in {'full':range(8),'sparse':[1,5]}.items():
    definition='-DX86_SIM_STACK_VALUE_WORDS(M)='+' '.join(f'M({i})' for i in words)
    run(['clang-18','-O3','-fsanitize=undefined','-fno-sanitize-recover=all',
         '-fno-sanitize-link-runtime',
         '-mno-red-zone','-I'+str(root/'vendor/libbpf/src'),
         '-I'+str(root/'vendor/libbpf/include/uapi'),definition,
         root/'kprog/results/sparse-stack-cache-20261119/oracle.c','-lubsan','-o',build/'oracle'])
    observations[mode]=json.loads(run([build/'oracle']))
assert observations['full']==observations['sparse'],observations
(out/'oracle-result.json').write_text(json.dumps(observations,indent=2)+'\n')
print(json.dumps(observations),flush=True)
# Only B emission reads the mutable compiler base. The host selection and
# shared-C checks above are independent of the runtime image rebuild.
with open('/workspaces/.agent-state/kprog-lanes/locks/image','a') as lock:
    fcntl.flock(lock,fcntl.LOCK_SH)
    for name,source in b_sources.items():
        fixture=build/'fixture.bpf.c'
        fixture.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
            '#include '+json.dumps(str(root/'kprog/x86/x86_sim_local_bpf.h'))))
        adapter.compile_simulator(root/'kprog/stock-path/bin/clang',fixture,
            build/'fixture.bpf.o',run,
            bounds_compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds'))
        if name=='immediate':
            run(['/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir',
                 fixture.with_suffix('.bounds-input.bc'),'-o',build/'native.bc'])
            run(['clang-18','-O3','-shared','-fPIC','-mno-red-zone','-mgeneral-regs-only',
                 build/'native.bc','-o',build/'execute.so'])
            program=ctypes.CDLL(str(build/'execute.so')).immediate_x86_sim_xdp
            program.argtypes=[ctypes.c_void_p];program.restype=ctypes.c_int
            observed=program(None)
            assert observed==0x12345678,observed
(out/'result.json').write_text(json.dumps(dict(selection_cases=len(rows),b_emission_cases=4,
    immediate_native_result=observed,
    shared_c=observations,scope='Generator selection, actual B emission and shared-C tag/alias/partial-write/replant checks; no stock/app/timing claim.'),indent=2)+'\n')
print(json.dumps(observations),flush=True)
