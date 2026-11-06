"""Reproduce LEA-to-RSP representation drift without dereferencing a bad model address."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
OUT=HERE/'sp-lea'
if sys.argv[1]=='prepare':
    shutil.copytree(HERE/'bcc-real-7/simulator',OUT/'before',dirs_exist_ok=False)
    shutil.copytree(OUT/'before',OUT/'after',dirs_exist_ok=False)
    for name in ('kprog/x86/x86_sim_local_bpf.h','kprog/formal/generated/ptr_add.h'):
        shutil.copy2(ROOT/name,OUT/'after'/name)
    (OUT/'native.S').write_text('''.intel_syntax noprefix
.text
.globl sp_lea_native
.type sp_lea_native,@function
sp_lea_native:
 sub rsp,32
 lea rsp,[rsp+16]
 mov QWORD PTR [rsp-8],42
 mov rax,QWORD PTR [rsp-8]
 lea rsp,[rsp-16]
 add rsp,32
 ret
.size sp_lea_native,.-sp_lea_native
.section .note.GNU-stack,"",@progbits
''')
    (OUT/'host.c').write_text('''#include <stdint.h>
#include <stdio.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 32U
#include HEADER
extern unsigned long sp_lea_native(void);
int main(void) {
 X86_SIM_ENTRY_RAW(0);
 unsigned long native=sp_lea_native();
 X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_SUB,32);
 X86_SIM_L_EXEC_LEA(X86_RSP,X86_RSP,X86_WIDTH_64,X86_MEM_AUX(X86_REG_NONE,0),16);
 intptr_t offset=(intptr_t)__x86_rsp.ptr;
 printf("native=%lu model_sp=%ld expected_sp=-16 tag=%u\\n",native,(long)offset,__x86_rsp_tag);
 if(offset!=-16) return 1;
 X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM,X86_RSP,X86_REG_NONE,X86_WIDTH_64,0,0xfffffff80000002aULL);
 X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD,X86_RAX,X86_RSP,X86_WIDTH_64,0,(uint64_t)-8);
 X86_SIM_L_EXEC_LEA(X86_RSP,X86_RSP,X86_WIDTH_64,X86_MEM_AUX(X86_REG_NONE,0),(uint64_t)-16);
 X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_ADD,32);
 printf("model_return=%lu final_sp=%ld\\n",(unsigned long)(uintptr_t)__x86_rax.ptr,(long)(intptr_t)__x86_rsp.ptr);
 return native!=42 || (uintptr_t)__x86_rax.ptr!=native || (intptr_t)__x86_rsp.ptr!=0;
}
''')
elif sys.argv[1]=='check':
    for phase,expected in [('before',1),('after',0)]:
        command=[str(OUT/(phase+'-host'))]
        result=subprocess.run(command,text=True,capture_output=True,timeout=20)
        row=dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
        (OUT/(phase+'.json')).write_text(json.dumps(row,indent=2)+'\n')
        print(phase,row,flush=True)
        if result.returncode!=expected:raise RuntimeError(row)
else:raise SystemExit('expected prepare or check')
