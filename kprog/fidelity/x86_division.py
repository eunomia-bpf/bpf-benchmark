#!/usr/bin/env python3
"""Observe CPU #DE state and the production DIV macro; use the canonical reference."""
import argparse
import csv
import json
from pathlib import Path
import subprocess
import sys
import generate

ROOT = Path(__file__).resolve().parents[2]
SIGNAL_OBSERVER = r'''
#define _GNU_SOURCE 1
#include "driver.h"
#include <signal.h>
#include <setjmp.h>
#include <ucontext.h>
#include <unistd.h>
#include <string.h>
extern uint64_t native_stack_base;
unsigned fault_simulator;
static sigjmp_buf fault_return;
static struct state fault_input, fault_result;
static const struct form *fault_form;
static volatile sig_atomic_t fault_native;
static unsigned char signal_stack[65536];
static void divide_signal(int signal, siginfo_t *info, void *context)
{
    ucontext_t *uc = context;
    if (signal != SIGFPE || info->si_code != FPE_INTDIV ||
        (uintptr_t)uc->uc_mcontext.gregs[REG_RIP] != (uintptr_t)fault_form->pc)
        _exit(121);
    static const int registers[] = {REG_RAX,REG_RCX,REG_RDX,REG_RBX,
        REG_RSP,REG_RBP,REG_RSI,REG_RDI,REG_R8,REG_R9,REG_R10,REG_R11,
        REG_R12,REG_R13,REG_R14,REG_R15};
    fault_result = fault_input;
    for (unsigned i=0;i<16;i++)
        fault_result.r[i] = uc->uc_mcontext.gregs[registers[i]];
    fault_result.r[4] -= native_stack_base;
    fault_result.flags = uc->uc_mcontext.gregs[REG_EFL];
    memcpy(fault_result.vec, &uc->uc_mcontext.fpregs->_xmm[0],16);
    memcpy(fault_result.stack,(void *)(uintptr_t)(native_stack_base-64),64);
    fault_native = 1;
    siglongjmp(fault_return,1);
}
static int install_divide_observer(void)
{
    stack_t stack = {.ss_sp=signal_stack,.ss_size=sizeof(signal_stack)};
    struct sigaction action = {.sa_sigaction=divide_signal,
        .sa_flags=SA_SIGINFO|SA_ONSTACK};
    sigemptyset(&action.sa_mask);
    return sigaltstack(&stack,NULL) || sigaction(SIGFPE,&action,NULL);
}
extern const int division_sources[];
extern const unsigned division_lanes[];
'''
PREPARE_INPUT = r'''
            /* Input generation only: actual CPU and canonical execution decide
             * success/fault. Include zero, overflow, nonzero-high and random. */
            uint64_t width_mask = form->width==64 ? UINT64_MAX :
                (UINT64_C(1)<<form->width)-1;
            uint64_t divisor = c%4==0 ? 0 : c%4==1 ? 1 :
                c%4==2 ? width_mask : (random64()&width_mask);
            int source = division_sources[j];
            unsigned lane = division_lanes[j];
            if (source < 0) {
                for (unsigned b=0;b<form->width/8;b++) memory[40+b]=divisor>>(8*b);
            } else {
                uint64_t mask=width_mask<<lane;
                input.r[source]=(input.r[source]&~mask)|((divisor<<lane)&mask);
            }
            if (c%4==1 || c%4==2) {
                uint64_t high=c%4==1 ? width_mask : divisor/2;
                if (form->width==8) input.r[0]=(input.r[0]&~UINT64_C(0xff00))|(high<<8);
                else input.r[2]=(input.r[2]&~width_mask)|high;
            }
'''


def build(out):
    forms=[];sources=[];lanes=[]
    for bits,names in [(8,['al','cl','dl','bl','ah','ch','dh','bh','sil','dil','r8b']),
                       (16,['ax','cx','dx','bx','r8w']),
                       (32,['eax','ecx','edx','ebx','r8d']),
                       (64,['rax','rcx','rdx','rbx','r8'])]:
        for i,name in enumerate(names):
            forms.append('div '+name)
            if bits==8:
                sources.append([0,1,2,3,0,1,2,3,6,7,8][i]);lanes.append(8 if 4<=i<8 else 0)
            else:sources.append([0,1,2,3,8][i]);lanes.append(0)
        forms.append(f'div {dict([(8,"BYTE"),(16,"WORD"),(32,"DWORD"),(64,"QWORD")])[bits]} PTR [rdi+8]')
        sources.append(-1);lanes.append(0)
    generate.x86_forms=lambda _:forms
    sys.argv=['generate.py','--arch','x86','--out',str(out)]
    generate.main()
    path=out/'generated.c';text=path.read_text()
    prefix=text[:text.index('extern unsigned char native_pc_0')]
    prefix+='\nextern unsigned fault_simulator;\n#undef X86_SIM_L_DIVIDE_FAULT\n#define X86_SIM_L_DIVIDE_FAULT() do { fault_simulator=1; goto observed_divide_fault; } while(0)\n'
    chunks=[]
    for i in range(len(forms)):
        start=text.index(f'extern unsigned char native_pc_{i},')
        end=text.index(f'extern unsigned char native_pc_{i+1},')
        chunk=text[start:end]
        assert chunk.count('s->r[0] =')==1
        chunks.append(chunk.replace('s->r[0] =','observed_divide_fault:;\ns->r[0] =',1))
    entries=text.split('const struct form forms[] = {\n',1)[1].split('\n};',1)[0].splitlines()[:len(forms)]
    path.write_text(prefix+''.join(chunks)+'const struct form forms[] = {\n'+'\n'.join(entries)+'\n};\nconst unsigned form_count=sizeof(forms)/sizeof(forms[0]);\n'+
        'const int division_sources[]={'+','.join(map(str,sources))+'};\n'+
        'const unsigned division_lanes[]={'+','.join(map(str,lanes))+'};\n')
    coverage=json.loads((out/'coverage.json').read_text())[:len(forms)]
    (out/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
    native='.intel_syntax noprefix\n.text\n'+'\n'.join(generate.native_wrapper('x86',i,assembly) for i,assembly in enumerate(forms))+'\n.section .note.GNU-stack,"",%progbits\n'
    (out/'native.S').write_text(native)
    driver=(ROOT/'kprog/fidelity/driver.c').read_text()
    driver=SIGNAL_OBSERVER+driver
    driver=driver.replace('    char *end;','    if (install_divide_observer()) { perror("install divide observer"); return 1; }\n    char *end;',1)
    driver=driver.replace('    if (trace) {\n        uint64_t fs_base=0,gs_base=0;','    {\n        uint64_t fs_base=0,gs_base=0;',1)
    old='            if (form->mode == 1) { input.r[2] = 0; input.r[3] |= 1; } /* non-faulting DIV */\n'
    assert old in driver;driver=driver.replace(old,'')
    driver=driver.replace('            memcpy(before, memory, sizeof(memory));',PREPARE_INPUT+'\n            memcpy(before, memory, sizeof(memory));',1)
    driver=driver.replace('            form->native(&native);','''            fault_input=input; fault_form=form; fault_native=0;
            if (sigsetjmp(fault_return,1)==0) form->native(&native);
            else native=fault_result;''',1)
    driver=driver.replace('            form->sim(&sim);','            fault_simulator=0; form->sim(&sim);',1)
    driver=driver.replace('            uint64_t mask = form->flag_mask;','            uint64_t mask = fault_native || fault_simulator ? UINT64_C(0x8d5) : 0;',1)
    driver=driver.replace('            int differs = memcmp(', '            int differs = (unsigned)fault_native != fault_simulator || memcmp(',1)
    driver=driver.replace('"mismatches.jsonl"','"observations.jsonl"',1)
    driver=driver.replace('            if (differs) {\n                bad++;','            if (differs) bad++;\n            {',1)
    anchor='                state_json(mismatches, &input);'
    assert driver.count(anchor)==1
    driver=driver.replace(anchor,'''                state_json(mismatches, &input);
                fprintf(mismatches, ",\\"native_fault\\":%u,\\"simulator_fault\\":%u,\\"mismatch\\":%d,\\"memory_base\\":%" PRIuPTR, (unsigned)fault_native, fault_simulator, differs, (uintptr_t)memory);''',1)
    (out/'fault-driver.c').write_text(driver)
    (out/'observer-source.json').write_text(json.dumps({'forms':forms,'sources':sources,'lanes':lanes},indent=2)+'\n')


def reference(observations, binary, out):
    metadata=json.loads((observations.parent/'native-code.json').read_text())
    summary={};bad=0
    with observations.open() as trace,(out/'reference-mismatches.jsonl').open('w') as failures:
        while True:
            records=[]
            for _ in range(1024):
                line=trace.readline()
                if not line:break
                records.append(json.loads(line))
            if not records:break
            requests=[]
            for r in records:
                initial=r['input'];stack_base=int(r['native_stack_base'],16)
                registers=[int(x,16) for x in initial['registers'][:16]];registers[4]=(registers[4]+stack_base)&((1<<64)-1)
                code=metadata['forms'][r['form']]
                memory=[]
                if '[' in r['assembly']:
                    memory=[dict(address=r['memory_base']+i,value=v,readable=True,writable=True,initialized=True) for i,v in enumerate(bytes.fromhex(r['memory_input']))]
                requests.append(dict(isa='x86_64',native_bytes=code['native_bytes'],state=dict(registers=registers,flags=int(initial['flags'],16),pc=code['pc'],xmm0=int(initial['vector'][0],16)+(int(initial['vector'][1],16)<<64),fs_base=metadata['fs_base'],gs_base=metadata['gs_base'],memory=memory)))
            encoded=''.join(json.dumps(r)+'\n' for r in requests)
            run=subprocess.run([str(binary)],input=encoded,text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
            if run.returncode:
                (out/'reference-error.txt').write_text(run.stderr)
                (out/'reference-failed-requests.jsonl').write_text(encoded)
                raise RuntimeError(run.stderr)
            responses=[json.loads(line) for line in run.stdout.splitlines()]
            assert len(responses)==len(records),'incomplete reference stream'
            for r,request,response in zip(records,requests,responses):
                counts=summary.setdefault(r['form'],dict(assembly=r['assembly'],cases=0,native_faults=0,simulator_faults=0,cpu_mismatches=0,simulator_mismatches=0))
                counts['cases']+=1;counts['native_faults']+=r['native_fault'];counts['simulator_faults']+=r['simulator_fault']
                registers=response['registers'].copy();registers[4]=(registers[4]-int(r['native_stack_base'],16))&((1<<64)-1)
                code=metadata['forms'][r['form']]
                def differs(which):
                    state=r[which];fault=r['native_fault' if which=='native' else 'simulator_fault']
                    return (response['fault']!=(None if not fault else {'kind':'divide'}) or
                        response['pc']!=(code['pc'] if fault else code['next_pc']) or
                        [int(x,16) for x in state['registers'][:16]]!=registers or
                        ((int(state['flags'],16)^response['flags'])&(0x8d5 if fault else 0))!=0 or
                        int(state['vector'][0],16)+(int(state['vector'][1],16)<<64)!=response['xmm0'] or
                        state['stack']!=r['input']['stack'] or
                        r['memory_native' if which=='native' else 'memory_simulator']!=r['memory_input'])
                cpu_bad=differs('native');sim_bad=differs('simulator')
                if (response['memory']!=request['state']['memory'] or
                    any(event['kind']=='write' for event in response['events'])):cpu_bad=sim_bad=True
                counts['cpu_mismatches']+=cpu_bad;counts['simulator_mismatches']+=sim_bad;bad+=cpu_bad+sim_bad
                if cpu_bad or sim_bad:failures.write(json.dumps(dict(observation=r,request=request,reference=response))+'\n')
    with (out/'reference-forms.tsv').open('w') as f:
        writer=csv.DictWriter(f,fieldnames=list(next(iter(summary.values()))),delimiter='\t',lineterminator='\n');writer.writeheader();writer.writerows(summary.values())
    print('DIV CPU/reference cases',sum(r['cases'] for r in summary.values()),'faults',sum(r['native_faults'] for r in summary.values()),'mismatches',bad)
    return int(bad!=0)


def main():
    p=argparse.ArgumentParser();sub=p.add_subparsers(dest='command',required=True)
    b=sub.add_parser('build');b.add_argument('out',type=Path)
    r=sub.add_parser('reference');r.add_argument('observations',type=Path);r.add_argument('binary',type=Path);r.add_argument('out',type=Path)
    a=p.parse_args()
    if a.command=='build':build(a.out);return 0
    return reference(a.observations,a.binary,a.out)

if __name__=='__main__':raise SystemExit(main())
