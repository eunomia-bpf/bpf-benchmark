#!/usr/bin/env python3
"""Pair finite stack-alias sequences with the actual production encoder/CPU wrapper."""
import argparse
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

REGS = ['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]


def forms():
    result = [
        ('copy and restore SP', 'mov rax,rsp; mov rsp,rax'),
        ('LEA alias and restore SP', 'lea rax,[rsp-16]; mov rsp,rax; add rsp,16'),
        ('LEA alias to LEA SP', 'lea rax,[rsp-16]; lea rsp,[rax+16]'),
        ('copy alias and compare SP', 'mov rax,rsp; mov rcx,rax; cmp rcx,rsp'),
        ('alias load', 'lea rax,[rsp-16]; mov rdx,[rax]'),
        ('alias store', 'lea rax,[rsp-16]; mov DWORD PTR [rax],ecx'),
        ('alias LEA chain', 'lea rax,[rsp-16]; lea rdx,[rax+8]'),
        ('alias self copy', 'lea rax,[rsp-16]; mov rax,rax'),
        ('alias scalar add', 'mov rax,rsp; add rax,16'),
        ('alias scalar subtract', 'mov rax,rsp; sub rax,16'),
        ('full spill and restore SP', 'lea rax,[rsp-16]; mov [rsp-8],rax; mov rax,[rsp-8]; mov rsp,rax; add rsp,16'),
        ('alias PUSH POP', 'mov rax,rsp; push rax; pop rax'),
        ('alias PUSHW POPW', 'mov rax,rsp; push ax; pop dx'),
    ]
    for dst in ['al','ah','ax','eax']:
        result.append((f'alias partial write {dst}',f'mov rax,rsp; mov {dst},1'))
    for dst in ['al','ah','ax','eax']:
        result.append((f'alias partial add {dst}',f'mov rax,rsp; add {dst},1'))
    for reg, memory, load in [('al','BYTE','movzx edx'),('ax','WORD','movzx edx'),('eax','DWORD','mov edx'),('rax','QWORD','mov rdx')]:
        result.append((f'alias spill {memory}',f'mov rax,rsp; mov {memory} PTR [rsp-16],{reg}; {load},{memory} PTR [rsp-16]'))
    result += [
        ('LEA AX from SP', 'lea ax,[rsp+16]'),
        ('LEA EAX from SP', 'lea eax,[rsp+16]'),
        ('LEA SP from SP', 'lea sp,[rsp+16]'),
        ('LEA ESP from SP', 'lea esp,[rsp+16]'),
        ('LEA CX from alias', 'lea rax,[rsp-16]; lea cx,[rax+8]'),
        ('LEA ECX from alias', 'lea rax,[rsp-16]; lea ecx,[rax+8]'),
        ('MOV SP self', 'mov rsp,rsp'),
        ('LEA SP self full', 'lea rsp,[rsp+16]'),
    ]
    result += [
        ('stack alias full XCHG', 'mov rax,rsp; xchg rax,rcx'),
        ('stack alias full XCHG reverse', 'mov rax,rsp; xchg rcx,rax'),
        ('stack alias full XCHG round trip', 'mov rax,rsp; xchg rax,rcx; xchg rax,rcx'),
        ('SP XCHG restore', 'mov rdx,rsp; xchg rax,rsp; mov rsp,rdx'),
        ('scalar SP read restore', 'mov rdx,rsp; mov rsp,rax; mov rcx,rsp; mov rsp,rdx'),
        ('stack alias XCHG32 control', 'mov rax,rsp; xchg eax,ecx'),
        ('stack alias XCHG16 control', 'mov rax,rsp; xchg ax,cx'),
    ]
    result += [
        ('CMOV stack alias taken', 'mov rax,rsp; cmp ecx,ecx; cmovz rcx,rax'),
        ('CMOV stack alias not taken', 'mov rax,rsp; cmp ecx,ecx; cmovnz rcx,rax'),
        ('CMOV from SP', 'cmp ecx,ecx; cmovz rax,rsp'),
        ('CMOV to SP restore', 'mov rdx,rsp; cmp ecx,ecx; cmovz rsp,rax; mov rcx,rsp; mov rsp,rdx'),
        ('CMOV partial alias', 'mov rax,rsp; cmp ecx,ecx; cmovz cx,ax'),
        ('CMOV false32 alias', 'mov rax,rsp; cmp ecx,ecx; cmovnz eax,ecx'),
        ('CMOV SP self', 'cmp ecx,ecx; cmovz rsp,rsp'),
    ]
    return result


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    a=parser.parse_args();root=a.source.resolve();out=a.out.resolve();out.mkdir(parents=True,exist_ok=True)
    sys.path.insert(0,str(root/'kprog/fidelity'));sys.path.insert(0,str(root/'kprog/x86/micro-prog'))
    spec=importlib.util.spec_from_file_location('frozen_generator',root/'kprog/fidelity/generate.py')
    generator=importlib.util.module_from_spec(spec);spec.loader.exec_module(generator)
    spec=importlib.util.spec_from_file_location('frozen_encoder',root/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
    encoder=importlib.util.module_from_spec(spec);sys.modules[spec.name]=encoder;spec.loader.exec_module(encoder)
    matrix=forms();assembly=['.intel_syntax noprefix','.text']
    for index,(_,body) in enumerate(matrix):
        assembly.append(generator.native_wrapper('x86',index,body.replace('; ','\n')))
    assembly.append('.section .note.GNU-stack,"",%progbits')
    (out/'native.S').write_text('\n'.join(assembly)+'\n')
    subprocess.run(['cc','-c',out/'native.S','-o',out/'native.o'],check=True)
    dump=subprocess.check_output(['objdump','-d','-Mintel','--insn-width=16',out/'native.o'],text=True)
    (out/'native.asm').write_text(dump)
    instructions=encoder.parse_asm_text(dump)
    symbols={}
    for line in subprocess.check_output(['nm',out/'native.o'],text=True).splitlines():
        fields=line.split()
        if len(fields)==3:symbols[fields[2]]=int(fields[0],16)
    c=['#include "'+str(root/'kprog/fidelity/driver.h')+'"','#include <stdlib.h>',
       '#define X86_SIM_ENABLE_STACK 1','#include "'+str(root/'kprog/x86/x86_sim_local_bpf.h')+'"',
       'extern uint64_t native_stack_base;']
    entries=[];coverage=[]
    for index,(name,body) in enumerate(matrix):
        selected=[i for i in instructions if symbols[f'native_pc_{index}']<=i.addr<symbols[f'native_next_{index}']]
        if len(selected)!=len(body.split('; ')):raise ValueError('sequence disassembly extent mismatch: '+name)
        c += [f'extern void native_{index}(struct state *);',f'extern unsigned char native_pc_{index},native_next_{index};',
              f'static void sim_{index}(struct state *s) {{',
              'X86_SIM_L_DECLARE_STATE(); X86_SIM_L_DECLARE_STACK(); __u8 __x86_sim_abi_kind=KPROG_ABI_KIND_XDP;',
              '__x86_native_stack_base=native_stack_base;']
        c += [f'__x86_{reg}.ptr=(void *)(uintptr_t)s->r[{i}];' for i,reg in enumerate(REGS)]
        c += ['for (unsigned k=0;k<64;k++) __x86_stack_mem.b[k]=s->stack[k];',
              '__x86_cf=s->flags&1; __x86_pf=(s->flags>>2)&1; __x86_af=(s->flags>>4)&1; __x86_zf=(s->flags>>6)&1; __x86_sf=(s->flags>>7)&1; __x86_of=(s->flags>>11)&1;',
              '__x86_xmm0_lo=s->vec[0]; __x86_xmm0_hi=s->vec[1];']
        for instruction in selected:
            encoded=encoder.encode(instruction,{})
            step=encoder.direct_step_statement(encoded)
            if step is None:step=f'X86_SIM_RUN_OP({encoded.op},{encoded.dst},{encoded.src},{encoded.flags},{encoded.aux},{encoded.imm});'
            c.append(step+';')
        c += [f's->r[{i}]='+('(uintptr_t)__x86_rsp.ptr;' if reg=='rsp' else f'X86_SIM_L_READ_REG({i});') for i,reg in enumerate(REGS)]
        c += ['for (unsigned k=0;k<64;k++) s->stack[k]=__x86_stack_mem.b[k];',
              's->flags=__x86_cf|((uint64_t)__x86_pf<<2)|((uint64_t)__x86_af<<4)|((uint64_t)__x86_zf<<6)|((uint64_t)__x86_sf<<7)|((uint64_t)__x86_of<<11);',
              's->vec[0]=__x86_xmm0_lo; s->vec[1]=__x86_xmm0_hi;','}']
        label=name+': '+body
        entries.append(f'{{{json.dumps(label)},"X86_STACK_COMPOSITE",native_{index},sim_{index},0x8d5U,64,0,0,&native_pc_{index},&native_next_{index}}}')
        coverage.append(dict(assembly=label,opcode='X86_STACK_COMPOSITE',native_instructions=len(selected)))
    c += ['const struct form forms[]={',',\n'.join(entries),'};','const unsigned form_count=sizeof(forms)/sizeof(forms[0]);']
    (out/'generated.c').write_text('\n'.join(c)+'\n');(out/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
    print(f'generated {len(matrix)} stack-alias CPU/production sequences')


if __name__=='__main__':main()
