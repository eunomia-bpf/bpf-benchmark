#!/usr/bin/env python3
"""Near CALL/RET at native instruction boundaries, including stack/target faults."""
import copy
import json
from pathlib import Path
import random
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    folder=ROOT/'build/call-reference';folder.mkdir(parents=True,exist_ok=True)
    regs=['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]
    forms=[f'call *%{r}' for r in regs]+['call common_land','call *(%rdi)','call *(%rsp)',
        'call *-8(%rsp)','call *target_slot(%rip)','call *(%rdi,%rcx,8)',
        'ret','ret $8','ret $65535','.byte 0x66,0xc3','.byte 0x67,0xc3','.byte 0x48,0xc3']
    assembly=['.text','.hidden common_land','.hidden target_slot']
    for kind,instruction in enumerate(forms):
        assembly += [f'.globl cpu{kind},insn{kind},next{kind}',f'.type cpu{kind},@function',f'cpu{kind}:',
            'movq %rdi,%r11','pushq 128(%r11)','popfq','movdqu 136(%r11),%xmm0']
        assembly += [f'movq {8*i}(%r11),%{r}' for i,r in enumerate(regs) if r!='r11']
        assembly += ['movq 88(%r11),%r11',f'insn{kind}:',instruction,f'next{kind}:','int3']
    assembly += ['.globl common_land','common_land:','int3','.section .note.GNU-stack,"",@progbits']
    (folder/'cpu.S').write_text('\n'.join(assembly)+'\n')
    declarations='\n'.join(f'extern void cpu{k}(const uint64_t*);extern unsigned char insn{k}[],next{k}[];' for k in range(len(forms)))
    source=r'''
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/mman.h>
#include <ucontext.h>
#include <unistd.h>
DECLARATIONS
extern unsigned char common_land[];
uint64_t target_slot;
static sigjmp_buf checkpoint;
static uint64_t after[21],after_xmm[2];static volatile sig_atomic_t caught_signal;
static void stopped(int sig,siginfo_t *info,void *opaque){
 ucontext_t *u=opaque;
 const int ids[16]={REG_RAX,REG_RCX,REG_RDX,REG_RBX,REG_RSP,REG_RBP,REG_RSI,REG_RDI,REG_R8,REG_R9,REG_R10,REG_R11,REG_R12,REG_R13,REG_R14,REG_R15};
 for(int i=0;i<16;i++)after[i]=u->uc_mcontext.gregs[ids[i]];
 after[16]=u->uc_mcontext.gregs[REG_EFL];after[17]=u->uc_mcontext.gregs[REG_RIP]-(sig==SIGTRAP?1:0);after[18]=u->uc_mcontext.gregs[REG_TRAPNO];after[19]=u->uc_mcontext.gregs[REG_ERR];after[20]=(uintptr_t)info->si_addr;
 memcpy(after_xmm,&u->uc_mcontext.fpregs->_xmm[0],16);caught_signal=sig;siglongjmp(checkpoint,1);
}
struct cell{uintptr_t address;unsigned char before;int readable,writable;};
static struct cell cells[128];static int ncells;
static void memory(uintptr_t start,int size,uintptr_t smid,uintptr_t dmid,size_t page){
 for(int i=0;i<size;i++){
  uintptr_t a=start+i;int present=0;for(int j=0;j<ncells;j++)if(cells[j].address==a)present=1;
  if(present)continue;
  int permitted=(a>=smid&&a<smid+page)||(a>=dmid&&a<dmid+page)||(a>=(uintptr_t)&target_slot&&a<(uintptr_t)&target_slot+8);
  cells[ncells++]=(struct cell){a,*(unsigned char*)a,permitted,permitted};
 }
}
static uint64_t random_word(uint64_t *s){*s^=*s<<13;*s^=*s>>7;*s^=*s<<17;return *s;}
static void numbers(const uint64_t *v,int n){printf("[");for(int i=0;i<n;i++)printf("%s%lu",i?",":"",v[i]);printf("]");}
static int run(int kind,int mode,int seed,size_t page){
 unsigned char *stack=mmap(0,3*page,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
 unsigned char *data=mmap(0,3*page,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
 if(stack==MAP_FAILED||data==MAP_FAILED)return 1;
 for(size_t i=0;i<3*page;i++){stack[i]=i*17+5;data[i]=i*13+11;}
 uint64_t in[19],rng=0x43414c4c+seed;for(int i=0;i<19;i++)in[i]=random_word(&rng);
 uintptr_t rsp=(uintptr_t)stack+page+128;
 if(mode==2||mode==4)rsp=kind>=22?(uintptr_t)stack+2*page-4:(uintptr_t)stack+page+4;
 in[4]=rsp;in[16]=seed%2?0xad7:0x202;
 uint64_t target=mode==1||mode==4?0x0200000000000000ull:(uintptr_t)common_land;
 uintptr_t source=0;
 if(kind<16){if(kind!=4)in[kind]=target;else target=rsp;}
 else if(kind==17||kind==21){
  source=mode==3?(uintptr_t)data+page-4:(uintptr_t)data+page+128;
  in[7]=source;if(kind==21){in[1]=3;in[7]-=24;}
 }else if(kind==18)source=rsp;
 else if(kind==19)source=rsp-8;
 else if(kind==20){source=(uintptr_t)&target_slot;target_slot=target;}
 else if(kind>=22)source=rsp;
 if(source)memcpy((void*)source,&target,8);
 ncells=0;memory(rsp-16,40,(uintptr_t)stack+page,(uintptr_t)data+page,page);
 if(source)memory(source,8,(uintptr_t)stack+page,(uintptr_t)data+page,page);
 if(mprotect(stack,page,PROT_NONE)||mprotect(stack+2*page,page,PROT_NONE)||mprotect(data,page,PROT_NONE)||mprotect(data+2*page,page,PROT_NONE))return 2;
 void(*fn[])(const uint64_t*)={FUNCTIONS};
 unsigned char *ip[]={INSTRUCTIONS},*next[]={NEXTS};
 caught_signal=0;
 if(sigsetjmp(checkpoint,1)==0){fn[kind](in);return 3;}
 __asm__ volatile("cld":::"cc");
 if(mprotect(stack,3*page,PROT_READ|PROT_WRITE)||mprotect(data,3*page,PROT_READ|PROT_WRITE))return 4;
 printf("{\"kind\":%d,\"mode\":%d,\"signal\":%d,\"trap\":%lu,\"pc\":%lu,\"target\":%lu,\"source\":%lu,\"code\":[",kind,mode,caught_signal,after[18],(uintptr_t)ip[kind],target,source);
 for(int i=0;i<next[kind]-ip[kind];i++)printf("%s%d",i?",":"",ip[kind][i]);
 printf("],\"page_error\":%lu,\"fault_address\":%lu,\"registers\":",after[19],after[20]);numbers(in,16);printf(",\"flags\":%lu,\"xmm\":",in[16]);numbers(in+17,2);
 printf(",\"after_registers\":");numbers(after,16);printf(",\"after_flags\":%lu,\"after_pc\":%lu,\"after_xmm\":",after[16],after[17]);numbers(after_xmm,2);
 printf(",\"memory\":[");for(int i=0;i<ncells;i++)printf("%s{\"address\":%lu,\"value\":%u,\"after\":%u,\"readable\":%s,\"writable\":%s,\"initialized\":true}",i?",":"",cells[i].address,cells[i].before,*(unsigned char*)cells[i].address,cells[i].readable?"true":"false",cells[i].writable?"true":"false");printf("]}\n");
 if(munmap(stack,3*page)||munmap(data,3*page))return 5;return 0;
}
int main(void){
 size_t page=sysconf(_SC_PAGESIZE);void *alt=mmap(0,65536,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);if(alt==MAP_FAILED)return 6;
 stack_t ss={.ss_sp=alt,.ss_size=65536};if(sigaltstack(&ss,0))return 7;
 struct sigaction action={0};action.sa_sigaction=stopped;action.sa_flags=SA_SIGINFO|SA_ONSTACK;
 if(sigaction(SIGTRAP,&action,0)||sigaction(SIGSEGV,&action,0)||sigaction(SIGBUS,&action,0))return 8;
 for(int kind=0;kind<28;kind++)for(int mode=0;mode<5;mode++)for(int seed=0;seed<4;seed++){
  if((kind==4||kind==16)&&(mode==1||mode==4))continue;
  if(mode==3&&kind!=17&&kind!=18&&kind!=19&&kind!=21)continue;
  if(mode==3&&(kind==18||kind==19))continue;
  int rc=run(kind,mode,seed,page);if(rc)return rc;
 }
 ss.ss_flags=SS_DISABLE;if(sigaltstack(&ss,0)||munmap(alt,65536))return 9;return 0;
}
'''
    source=source.replace('DECLARATIONS',declarations).replace('FUNCTIONS',','.join(f'cpu{k}' for k in range(len(forms))))
    source=source.replace('INSTRUCTIONS',','.join(f'insn{k}' for k in range(len(forms)))).replace('NEXTS',','.join(f'next{k}' for k in range(len(forms))))
    (folder/'cpu.c').write_text(source)
    subprocess.run(['cc','-O2','-mno-red-zone',folder/'cpu.c',folder/'cpu.S','-o',folder/'cpu'],check=True)
    cpu_output=subprocess.check_output([folder/'cpu'],text=True)
    (folder/'cpu.jsonl').write_text(cpu_output)
    cpu_rows=[json.loads(line) for line in cpu_output.splitlines()]
    rng=random.Random(0x4e454152);cases=[]
    def expected(request,call,target,source=None,release=0):
        s=copy.deepcopy(request['state']);events=[];fault=None;cells={c['address']:c for c in s['memory']}
        def read(address):
            nonlocal fault
            addresses=[(address+i)&MASK for i in range(8)]
            if not all(a in cells and cells[a]['readable'] for a in addresses):fault=dict(kind='read',address=address,bytes=8);return None
            value=[cells[a]['value'] for a in addresses];events.append(dict(kind='read',address=address,value=value,initialized=all(cells[a]['initialized'] for a in addresses)))
            return int.from_bytes(bytes(value),'little')
        if source is not None:target=read(source)
        if fault is None and call:
            address=(s['registers'][4]-8)&MASK
            if not all((address+i)&MASK in cells and cells[(address+i)&MASK]['writable'] for i in range(8)):
                fault=dict(kind='write',address=address,bytes=8)
        if fault is None:
            bits=s.get('linear_address_bits',48);canonical=target&((1<<bits)-1)
            if canonical&(1<<(bits-1)):canonical|=MASK^((1<<bits)-1)
            if canonical!=target:fault=dict(kind='non_canonical',address=target)
        if fault is None:
            if call:
                address=(s['registers'][4]-8)&MASK;addresses=[(address+i)&MASK for i in range(8)]
                value=list(((s['pc']+len(request['native_bytes']))&MASK).to_bytes(8,'little'))
                for a,b in zip(addresses,value):cells[a].update(value=b,initialized=True)
                events.append(dict(kind='write',address=address,value=value,initialized=True));s['registers'][4]=address
            else:s['registers'][4]=(s['registers'][4]+8+release)&MASK
            if fault is None:s['pc']=target
        if fault:events.append(dict(kind='fault',fault=fault))
        s.update(events=events,fault=fault,defined_flags=MASK);return s
    for row in cpu_rows:
        kind=row['kind'];call=kind<22
        s=dict(registers=row['registers'],flags=row['flags'],pc=row['pc'],xmm0=row['xmm'][0]+(row['xmm'][1]<<64),fs_base=0,gs_base=0,
            memory=[{k:v for k,v in c.items() if k!='after'} for c in row['memory']])
        request=dict(isa='x86_64',native_bytes=row['code'],state=s)
        e=expected(request,call,row['target'],row['source'] or None,8 if kind==23 else 65535 if kind==24 else 0)
        assert e['registers']==row['after_registers'],(row,e)
        assert e['pc']==row['after_pc'],(row,e)
        assert (e['flags']^row['after_flags'])&0xcd5==0,(row,e)
        assert e['xmm0']==row['after_xmm'][0]+(row['after_xmm'][1]<<64),(row,e)
        assert [c['value'] for c in e['memory']]==[c['after'] for c in row['memory']],(row,e)
        if e['fault']:
            assert row['trap']==(13 if e['fault']['kind']=='non_canonical' else 14),(row,e)
            if row['trap']==14:
                assert bool(row['page_error']&2)==(e['fault']['kind']=='write') and not row['page_error']&16,(row,e)
                assert ((row['fault_address']-e['fault']['address'])&MASK)<8,(row,e)
        else:
            assert row['signal']==5 or (kind==4 and row['after_pc']==s['registers'][4] and row['page_error']&16),(row,e)
        cases.append((request,e))
    # Explicit paging profiles, signed rel32, aliases/first faults, all register
    # numbers, prefixes and imm16 releases. Inputs outside the hardware profile
    # are tested by the same canonical step, never by a second decoder.
    targets=[0,1,0x7fffffffffff,0x800000000000,0xfffffffffffffffe,0xffff800000000000,0x00ffffffffffffff,0x0100000000000000,0xff00000000000000,MASK]
    def add(code,call,target,source=None,release=0,bits=None,bad=None,reg=None):
        s=dict(registers=[rng.getrandbits(64) for _ in range(16)],flags=0xad7,pc=0x1000,xmm0=rng.getrandbits(128),fs_base=0,gs_base=0,memory=[])
        if bits is not None:s['linear_address_bits']=bits
        s['registers'][4]=0x4008
        if reg is not None:s['registers'][reg]=target
        if not call:source=s['registers'][4]
        if call and source is not None:s['registers'][7]=source
        cells={}
        for a in range(0x3ff0,0x4020):cells[a]=dict(address=a,value=rng.randrange(256),readable=True,writable=True,initialized=False)
        if source is not None:
            for i,b in enumerate(target.to_bytes(8,'little')):cells[(source+i)&MASK]=dict(address=(source+i)&MASK,value=b,readable=not(bad=='read' and i==7),writable=True,initialized=bool(i%2))
        if bad=='write':cells[(s['registers'][4]-1)&MASK]['writable']=False
        s['memory']=list(cells.values());r=dict(isa='x86_64',native_bytes=list(code),state=s);cases.append((r,expected(r,call,target,source,release)))
    for bits in (None,48,57):
        for target in targets:
            for reg in [r for r in range(16) if r!=4]:
                add((bytes([0x41]) if reg>=8 else b'')+bytes([0xff,0xd0+reg%8]),True,target,bits=bits,reg=reg)
            for bad in (None,'read','write'):
                add(bytes.fromhex('ff17'),True,target,source=0x5000,bits=bits,bad=bad)
                for release in (0,8,65535):add(b'\xc3' if release==0 else b'\xc2'+release.to_bytes(2,'little'),False,target,release=release,bits=bits,bad=bad)
    for prefix in (b'',b'\x66',b'\x67',b'\x48',b'\x40'*10):
        for displacement in (0,1,-1,0x7fffffff,-0x80000000):
            code=prefix+b'\xe8'+(displacement&0xffffffff).to_bytes(4,'little')
            add(code,True,(0x1000+len(code)+displacement)&MASK)
    # Real CALL->callee NOP->RET->caller JMP->NOP, with the return slot produced
    # by CALL itself. Each byte extent and returned successor is checked.
    path_count=0
    for base in (0x1000,MASK-6):
        for bits in (48,57):
            r=copy.deepcopy(cases[0][0]);r['state']['pc']=base;r['state']['linear_address_bits']=bits
            r['state']['registers'][4]=0x4008
            r['state']['memory']=[dict(address=a,value=rng.randrange(256),readable=True,writable=True,initialized=False) for a in range(0x3ff0,0x4020)]
            r['native_bytes']=list(bytes.fromhex('e803000000eb049090c39090'))
            first=dict(isa='x86_64',native_bytes=r['native_bytes'][:5],state=copy.deepcopy(r['state']))
            e=expected(first,True,(base+8)&MASK)
            second=dict(isa='x86_64',native_bytes=[0xc3],state={k:v for k,v in e.items() if k not in ('events','fault','defined_flags')})
            last=expected(second,False,0,source=second['state']['registers'][4]);last['events']=e['events']+last['events'];last['pc']=(base+12)&MASK
            r.update(native_base=base,native_path=[dict(offset=o,length=n) for o,n in ((0,5),(8,1),(9,1),(5,2),(11,1))])
            cases.append((r,last));path_count+=1
    binary=ROOT/'.lake/build/bin/reference'
    for start in range(0,len(cases),64):
        batch=cases[start:start+64]
        result=subprocess.run([binary],input=''.join(json.dumps(r)+'\n' for r,_ in batch),text=True,capture_output=True,check=True)
        actual=[json.loads(line) for line in result.stdout.splitlines()];assert len(actual)==len(batch)
        for (r,e),a in zip(batch,actual):assert a==e,(r,a,e)
    for value in (0,47,49,64,'48',None):
        r=copy.deepcopy(cases[0][0]);r['state']['linear_address_bits']=value
        result=subprocess.run([binary],input=json.dumps(r)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(r,result)
    for code in ('e8','e8000000','ff','ff14','c2','c208','40'*11+'e800000000'):
        r=copy.deepcopy(cases[0][0]);r['native_bytes']=list(bytes.fromhex(code))
        result=subprocess.run([binary],input=json.dumps(r)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(r,result)
    for bad in ([dict(offset=0,length=6)], [dict(offset=0,length=5),dict(offset=9,length=1)]):
        r=copy.deepcopy(cases[-1][0]);r['native_path']=bad
        result=subprocess.run([binary],input=json.dumps(r)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(r,result)
    print(f'x86 near CALL/RET: {len(cpu_rows)} actual CPU complete-state/trap cases, {len(cases)} canonical full-state/profile/fault transitions including {path_count} composed native paths PASS')


if __name__=='__main__':main()
