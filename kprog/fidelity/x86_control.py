#!/usr/bin/env python3
"""Finite x86 control observers emitted through the production program encoder."""
import importlib.util
import json
from pathlib import Path
import shutil
import subprocess
import sys
from generate import native_wrapper
from tcb import includes, imports

ROOT=Path(__file__).resolve().parents[2]
BASE=0x1000000
REGS=['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]


def forms():
    out=[]
    for reg in REGS:
        if reg=='rsp':
            continue  # A code target in RSP would also become the CALL stack.
        out.append((f'CALL {reg} / RET',f'lea {reg},[rip+1f]; call {reg}; jmp finish; 1: add rdx,rbx; ret'))
        out.append((f'JMP {reg}',f'lea {reg},[rip+1f]; jmp {reg}; 1: add rdx,rbx; jmp finish'))
    out += [
        ('CALL finite choice','test dl,1; jz 1f; lea r10,[rip+2f]; jmp 3f; 1: lea r10,[rip+4f]; 3: call r10; jmp finish; 2: add rax,rbx; ret; 4: sub rax,rbx; ret'),
        ('JMP finite copied choice','test dl,1; jz 1f; lea r10,[rip+2f]; jmp 3f; 1: lea r10,[rip+4f]; 3: mov r11,r10; jmp r11; 2: add rax,rbx; jmp finish; 4: sub rax,rbx; jmp finish'),
        ('nested direct CALL','call 1f; jmp finish; 1: call 2f; add rax,rbx; ret; 2: add rdx,rcx; ret'),
        ('nested indirect CALL','lea r10,[rip+1f]; call r10; jmp finish; 1: lea r11,[rip+2f]; call r11; add rax,rbx; ret; 2: add rdx,rcx; ret'),
        ('CALL stack return address','call 1f; jmp finish; 1: mov rax,[rsp]; ret'),
    ]
    return out


def main():
    out=Path(sys.argv[1]).resolve();out.mkdir(parents=True,exist_ok=True)
    sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
    spec=importlib.util.spec_from_file_location('encoder',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    enc=importlib.util.module_from_spec(spec);sys.modules[spec.name]=enc;spec.loader.exec_module(enc)
    snapshot=out/'snapshot'
    for p in includes(ROOT/'kprog/x86/x86_sim_local_bpf.h')|imports(Path(enc.__file__)):
        target=snapshot/p.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,target)
    assembly=['.intel_syntax noprefix','.section .kprog_native,"ax",@progbits']
    matrix=forms()
    for i,(_,body) in enumerate(matrix):
        body=body.replace('finish',f'outer_done_{i}')
        body+=f'; .global outer_done_{i}; outer_done_{i}: jmp native_next_{i}'
        assembly += [f'.org {i*4096}',native_wrapper('x86',i,body)]
    assembly += ['.section .note.GNU-stack,"",@progbits']
    (out/'native.S').write_text('\n'.join(assembly)+'\n')
    subprocess.run(['cc','-c',out/'native.S','-o',out/'native.o'],check=True)
    dump=subprocess.check_output(['objdump','-d','-Mintel','--insn-width=16',f'--adjust-vma={BASE}',out/'native.o'],text=True)
    (out/'native.asm').write_text(dump);insns=enc.parse_asm_text(dump)
    symbols={}
    for line in subprocess.check_output(['nm',out/'native.o'],text=True).splitlines():
        fields=line.split()
        if len(fields)==3:symbols[fields[2]]=int(fields[0],16)+BASE
    functions=[];entries=[];coverage=[]
    for i,(name,_) in enumerate(matrix):
        code=[x for x in insns if symbols[f'native_pc_{i}']<=x.addr<symbols[f'native_next_{i}']]
        targets=enc.indirect_targets(code,exit_addr=symbols[f'outer_done_{i}'])
        call_labels={target:f'x86_l_{target:x}' for dests in targets.values() for kind,target in dests if kind=='code'}
        for x in code:
            if x.mnemonic=='call' and not enc.is_indirect_branch(x):
                target=enc.branch_target(x.operands[0]);call_labels[target]=f'x86_l_{target:x}'
        returns=[code[j+1].addr for j,x in enumerate(code[:-1]) if x.mnemonic=='call']
        emitted=[]
        for j,x in enumerate(code):
            emitted.append(f'x86_l_{x.addr:x}:;')
            if x.addr==symbols[f'outer_done_{i}']:
                emitted.append('goto observed;');continue
            enc.append_branch_or_ret(emitted,x,{x.addr for x in code},next_addr=code[j+1].addr if j+1<len(code) else None,
                call_functions=call_labels,ret_statement='X86_SIM_X86_SUB_RET(return_dispatch);',targets=targets)
        emitted += ['goto observed;','return_dispatch: switch (__x86_sim_ret_addr) {']
        emitted += [f'case 0x{addr:x}ULL: goto x86_l_{addr:x};' for addr in returns]
        emitted += ['default: abort();','}']
        init=['X86_SIM_L_DECLARE_STATE(); X86_SIM_L_DECLARE_STACK(); __u8 __x86_sim_abi_kind=KPROG_ABI_KIND_XDP;',
              '__x86_native_stack_base=native_stack_base;']
        init += [f'__x86_{reg}.ptr=(void *)(uintptr_t)s->r[{j}];' for j,reg in enumerate(REGS)]
        init += ['for(unsigned k=0;k<64;k++) __x86_stack_mem.b[k]=s->stack[k];',
                 '__x86_cf=s->flags&1; __x86_pf=(s->flags>>2)&1; __x86_af=(s->flags>>4)&1; __x86_zf=(s->flags>>6)&1; __x86_sf=(s->flags>>7)&1; __x86_of=(s->flags>>11)&1;',
                 '__x86_xmm0_lo=s->vec[0]; __x86_xmm0_hi=s->vec[1];']
        finish=['observed:;']+[f's->r[{j}]='+('(uintptr_t)__x86_rsp.ptr;' if reg=='rsp' else f'X86_SIM_L_READ_REG({j});') for j,reg in enumerate(REGS)]
        finish += ['for(unsigned k=0;k<64;k++) s->stack[k]=__x86_stack_mem.b[k];',
                   's->flags=__x86_cf|((uint64_t)__x86_pf<<2)|((uint64_t)__x86_af<<4)|((uint64_t)__x86_zf<<6)|((uint64_t)__x86_sf<<7)|((uint64_t)__x86_of<<11);',
                   's->vec[0]=__x86_xmm0_lo; s->vec[1]=__x86_xmm0_hi;']
        functions += [f'extern void native_{i}(struct state *);',f'extern unsigned char native_pc_{i},native_next_{i};',f'static void sim_{i}(struct state *s) {{',*init,*emitted,*finish,'}']
        entries.append(f'{{{json.dumps(name)},"X86_CONTROL",native_{i},sim_{i},0x8d5U,64,0,6,&native_pc_{i},&native_next_{i}}}')
        coverage.append(dict(assembly=name,opcode='X86_CONTROL',native_instructions=len(code)))
    prelude=['#include "../driver.h"','#include <stdlib.h>','#define X86_SIM_ENABLE_STACK 1',f'#include "{snapshot}/kprog/x86/x86_sim_local_bpf.h"','extern uint64_t native_stack_base;', 'extern void __x86_sim_unresolved_indirect_target(void) __attribute__((error("indirect target was not eliminated by specialization")));']
    (out/'generated.c').write_text('\n'.join(prelude+functions+['const struct form forms[]={',',\n'.join(entries),'};','const unsigned form_count=sizeof(forms)/sizeof(forms[0]);'])+'\n')
    (out/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
    print(f'generated {len(matrix)} real x86 finite-control observers')


if __name__=='__main__':main()
