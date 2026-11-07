#!/usr/bin/env python3
"""Legacy XMM0 moves: all bytes/lanes, native alignment and permission faults."""
import copy
import ctypes
import json
from pathlib import Path
import random
import re
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def encoding(op, base, index=None, scale=1, displacement=0, address32=False, segment=0, rexw=False):
    prefix = (bytes([segment]) if segment else b'') + (b'\x67' if address32 else b'')
    rex = 0x40 + (8 if rexw else 0) + (base // 8) + (2 if index is not None and index >= 8 else 0)
    sib = index is not None or base % 8 == 4
    return prefix + (bytes([rex]) if rex != 0x40 else b'') + bytes([0x0f, op, 0x80 + (4 if sib else base % 8)]) + \
        (bytes([({1:0,2:1,4:2,8:3}[scale] << 6) + (4 if index is None else index % 8)*8 + base % 8]) if sib else b'') + \
        (displacement & 0xffffffff).to_bytes(4, 'little')


def main():
    folder = ROOT/'build/xmm0-reference'; folder.mkdir(parents=True, exist_ok=True)
    ops = [(0x10,False,False,'movups'),(0x11,True,False,'movups'),(0x28,False,True,'movaps'),(0x29,True,True,'movaps')]
    # The actual instruction, not C memcpy, anchors all128 bits and flag preservation.
    source = ['#include <stdint.h>']
    for op,store,aligned,mnemonic in ops:
        instruction = f'{mnemonic} %%xmm0,(%[p])' if store else f'{mnemonic} (%[p]),%%xmm0'
        source.append(f'void f{op}(void *p,void *in,void *out,uint64_t old,uint64_t *flags){{uint64_t f;'
            f'__asm__ volatile("pushfq;pushq %[old];popfq;movdqu (%[in]),%%xmm0;{instruction};'
            'movdqu %%xmm0,(%[out]);pushfq;popq %[f];popfq"'
            ':[f]"=&r"(f):[p]"r"(p),[in]"r"(in),[out]"r"(out),[old]"r"(old):"xmm0","cc","memory");*flags=f;}')
    (folder/'cpu.c').write_text('\n'.join(source)+'\n')
    subprocess.run(['cc','-O2','-shared','-fPIC','-mno-red-zone',folder/'cpu.c','-o',folder/'cpu.so'],check=True)
    library = ctypes.CDLL(str(folder/'cpu.so')); rng = random.Random(0x584d4d30); cpu_count = 0
    for op,store,aligned,_ in ops:
        fn = getattr(library,f'f{op}'); fn.argtypes = [ctypes.c_void_p]*3+[ctypes.c_uint64,ctypes.POINTER(ctypes.c_uint64)]; fn.restype = None
        for offset in ([0] if aligned else range(16)):
            for _ in range(32):
                backing = ctypes.create_string_buffer(64); address = (ctypes.addressof(backing)+15)&~15; address += offset
                data = rng.randbytes(16); incoming = rng.randbytes(16)
                ctypes.memmove(address,data,16); src = ctypes.create_string_buffer(incoming); out = ctypes.create_string_buffer(16)
                for flags in (0x202,0xAD7):
                    ctypes.memmove(address,data,16); result = ctypes.c_uint64()
                    fn(address,src,out,flags,ctypes.byref(result))
                    assert out.raw == (incoming if store else data)
                    assert ctypes.string_at(address,16) == (incoming if store else data)
                    assert (result.value ^ flags)&0x8D5 == 0
                    cpu_count += 1
    # Capture the faulting architectural XMM from ucontext before longjmp can clobber it.
    fault_source = r'''
#define _GNU_SOURCE
#include <signal.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <ucontext.h>
#include <unistd.h>
static sigjmp_buf env;
static unsigned char caught[16];
static volatile sig_atomic_t signal_seen;
static void fault(int sig,siginfo_t *info,void *opaque) {
  (void)info;ucontext_t *ctx=opaque;
  memcpy(caught,&ctx->uc_mcontext.fpregs->_xmm[0],16);
  signal_seen=sig;siglongjmp(env,1);
}
int main(void) {
  struct sigaction action={0};action.sa_sigaction=fault;action.sa_flags=SA_SIGINFO;
  if(sigaction(SIGSEGV,&action,0)) return 1;
  size_t size=sysconf(_SC_PAGESIZE);
  unsigned char *memory=mmap(0,size*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
  if(memory==MAP_FAILED) return 2;
  unsigned char initial[16],before[16];for(int i=0;i<16;i++)initial[i]=i*17+3;
  int count=0;
  for(int op=0;op<4;op++)for(int offset=0;offset<16;offset++) {
    if(op<2 && offset!=0) continue;
    if(op>=2 && offset==0) continue;
    memset(memory,0x5a,size*2);
    unsigned char *p=offset ? memory+offset : memory+size-8;
    memcpy(before,p,16);
    if(mprotect(memory+size,size,PROT_NONE)) return 3;
    signal_seen=0;
    if(sigsetjmp(env,1)==0) {
      __asm__ volatile("movdqu (%0),%%xmm0"::"r"(initial):"xmm0","memory");
      switch(op) {
      case 0: __asm__ volatile("movups (%0),%%xmm0"::"r"(p):"xmm0","memory");break;
      case 1: __asm__ volatile("movups %%xmm0,(%0)"::"r"(p):"memory");break;
      case 2: __asm__ volatile("movaps (%0),%%xmm0"::"r"(p):"xmm0","memory");break;
      case 3: __asm__ volatile("movaps %%xmm0,(%0)"::"r"(p):"memory");break;
      }
      return 4;
    }
    if(mprotect(memory+size,size,PROT_READ|PROT_WRITE)) return 5;
    if(signal_seen!=SIGSEGV || memcmp(caught,initial,16) || memcmp(p,before,16)) return 6;
    count++;
  }
  if(munmap(memory,size*2)) return 7;
  printf("%d",count);return 0;
}
'''
    (folder/'fault.c').write_text(fault_source)
    subprocess.run(['cc','-O2','-mno-red-zone',folder/'fault.c','-o',folder/'fault'],check=True)
    fault_count = int(subprocess.check_output([folder/'fault'],text=True)); assert fault_count==32
    names = ['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]
    assembly = ['.intel_syntax noprefix','.text']; forms = []
    for op,store,aligned,mnemonic in ops:
        for base in range(16):
            for index,scale,disp in ((None,1,0),(12 if base!=12 else 11,8,-23)):
                code = encoding(op,base,index,scale,disp)
                operand = f'XMMWORD PTR [{names[base]}' + (f'+{names[index]}*{scale}' if index is not None else '') + (str(disp) if disp<0 else '') + ']'
                assembly += [f'p{len(forms)}:',f'{mnemonic} '+(operand+',xmm0' if store else 'xmm0,'+operand)]
                # GNU prefers disp0/disp8, so compare via disassembled operands below.
                forms.append((op,store,aligned,base,index,scale,disp,code))
    (folder/'encodings.s').write_text('\n'.join(assembly)+'\n')
    subprocess.run(['as','--64',folder/'encodings.s','-o',folder/'encodings.o'],check=True)
    dis = subprocess.check_output(['objdump','-dw','-Mintel',folder/'encodings.o'],text=True)
    assembled = [bytes.fromhex(m[1]) for m in re.finditer(r'^\s*[0-9a-f]+:\s+((?:[0-9a-f]{2}\s+)+)mov[au]ps',dis,re.M)]
    assert len(assembled)==len(forms)
    cases = []
    def add(op,store,aligned,code,base,index,scale,disp,offset,bad,addr32=False,segment=0,rip=False,absolute=False,all_initialized=False):
        address = ((0xffffffe0 if addr32 else (MASK-7 if offset%2 else 0x2000))+offset)&MASK
        segbase = 0x10000 if segment else 0
        address = (address+segbase)&MASK
        state = dict(registers=[rng.getrandbits(64) for _ in range(16)],flags=rng.getrandbits(64),pc=MASK-2,
            xmm0=rng.getrandbits(128),fs_base=segbase if segment==0x64 else 0,gs_base=segbase if segment==0x65 else 0,memory=[])
        if rip: address = (state['pc']+len(code)+disp+segbase)&MASK
        elif absolute: address = (disp+segbase)&MASK
        else:
            value = (address-segbase-disp-(state['registers'][index]*scale if index is not None else 0))&MASK
            state['registers'][base] = (value&0xffffffff)+(1<<40) if addr32 else value
        for i in range(-2,18):
            state['memory'].append(dict(address=(address+i)&MASK,value=rng.randrange(256),
                readable=not (not store and bad==i),writable=not(store and bad==i),initialized=all_initialized or bool(i%3)))
        expected = copy.deepcopy(state);expected.update(pc=(state['pc']+len(code))&MASK,events=[],fault=None,defined_flags=MASK)
        if aligned and address%16: expected['fault'] = dict(kind='alignment',address=address,bytes=16)
        elif bad is not None: expected['fault'] = dict(kind='write' if store else 'read',address=address,bytes=16)
        if expected['fault']:
            expected['pc'] = state['pc'];expected['events'] = [dict(kind='fault',fault=expected['fault'])]
        else:
            transferred = [(state['xmm0']>>(8*i))&255 for i in range(16)] if store else [c['value'] for c in state['memory'][2:18]]
            if store:
                for cell,value in zip(expected['memory'][2:18],transferred): cell.update(value=value,initialized=True)
            else: expected['xmm0'] = int.from_bytes(bytes(transferred),'little')
            expected['events'] = [dict(kind='write' if store else 'read',address=address,value=transferred,initialized=store or all(c['initialized'] for c in state['memory'][2:18]))]
        cases.append((dict(isa='x86_64',native_bytes=list(code),state=state),expected))
    for row,gnu in zip(forms,assembled):
        op,store,aligned,base,index,scale,disp,code = row
        for offset in range(16):
            for bad in (None,0,8,15): add(op,store,aligned,code,base,index,scale,disp,offset,bad)
        add(op,store,aligned,gnu,base,index,scale,disp,0,None)
    for op,store,aligned,_ in ops:
        for bad in (None,*range(16)):
            for segment in (0,0x64,0x65):
                for addr32 in (False,True):
                    add(op,store,aligned,encoding(op,15,12,4,-17,addr32,segment,True),15,12,4,-17,0,bad,addr32,segment)
            add(op,store,aligned,bytes([0x0f,op,5,0x10,0,0,0]),0,None,1,16,0,bad,rip=True)
            add(op,store,aligned,bytes([0x0f,op,4,0x25,0,0x20,0,0]),0,None,1,0x2000,0,bad,absolute=True)
    for op,store,aligned,_ in ops:
        add(op,store,aligned,b'\x40'*12+bytes([0x0f,op,7]),7,None,1,0,0,None)
        add(op,store,aligned,encoding(op,7),7,None,1,0,0,None,all_initialized=True)
    binary = ROOT/'.lake/build/bin/reference'
    for start in range(0,len(cases),512):
        batch = cases[start:start+512]
        result = subprocess.run([binary],input=''.join(json.dumps(r)+'\n' for r,_ in batch),text=True,capture_output=True,check=True)
        actual = [json.loads(line) for line in result.stdout.splitlines()];assert len(actual)==len(batch)
        for (request,expected),observed in zip(batch,actual): assert observed==expected,(request,observed,expected)
    for code in ('0f10','0f1004','0f10c0','0f1008','440f1000','660f1000','f20f1000','f30f1000','66'*12+'0f1000','40'*13+'0f1000'):
        request = copy.deepcopy(cases[0][0]); request['native_bytes'] = list(bytes.fromhex(code))
        result = subprocess.run([binary],input=json.dumps(request)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(request,result)
    print(f'x86 XMM0: {cpu_count} CPU lane/flag + {fault_count} precise native fault cases, {len(forms)} GNU encodings, {len(cases)} full-state memory/alignment/fault cases PASS')


if __name__=='__main__': main()
