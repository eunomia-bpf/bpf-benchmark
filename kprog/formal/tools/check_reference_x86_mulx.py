#!/usr/bin/env python3
"""MULX exact unsigned products, VEX registers, aliases, flags and read faults."""
import copy
import ctypes
import json
from pathlib import Path
import random
import re
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def encoding(bits, high, low, source, memory=False):
    vex1 = 2 | ((1-(high//8)) << 7) | 0x40 | ((1-(source//8)) << 5)
    vex2 = (128 if bits==64 else 0) | ((15-low) << 3) | 3
    return bytes([0xC4,vex1,vex2,0xF6,(0 if memory else 0xC0)+8*(high%8)+source%8])


def main():
    folder = ROOT/'build/mulx-reference'; folder.mkdir(parents=True,exist_ok=True)
    names64 = ['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]
    names32 = ['eax','ecx','edx','ebx','esp','ebp','esi','edi']+[f'r{i}d' for i in range(8,16)]
    assembly = ['.intel_syntax noprefix','.text']; codes = []
    for bits,names in ((32,names32),(64,names64)):
        for high in range(16):
            for low in range(16):
                for source in range(16):
                    assembly += [f'p{len(codes)}:',f'mulx {names[high]},{names[low]},{names[source]}']
                    codes.append((bits,high,low,source,encoding(bits,high,low,source)))
    (folder/'encodings.s').write_text('\n'.join(assembly)+'\n')
    subprocess.run(['as','--64',folder/'encodings.s','-o',folder/'encodings.o'],check=True)
    disassembly = subprocess.check_output(['objdump','-d','-Mintel',folder/'encodings.o'],text=True)
    assembled = [bytes.fromhex(m[1]) for m in re.finditer(r'^\s*[0-9a-f]+:\s+((?:[0-9a-f]{2}\s+)+)mulx',disassembly,re.M)]
    assert assembled==[c[-1] for c in codes], (len(assembled),len(codes))
    # Ordinary, equal-destination, implicit/source-RDX and destination-RDX
    # CPU forms independently anchor the product and final-write priority.
    source = ['#include <stdint.h>']; anchors = []
    for bits,suffix,mod in ((32,'l','k'),(64,'q','')):
        for kind in ('ordinary','same','source_dx','low_dx','high_dx','all_dx'):
            name = kind+str(bits); anchors.append((name,bits,kind))
            outputs = '[lo]"=&r"(lo),[hi]"=&r"(hi),[f]"=&r"(f)'
            inputs = '[a]"d"(a),[b]"r"(b),[old]"r"(old)'
            instruction = f'mulx{suffix} %{mod}[b],%{mod}[lo],%{mod}[hi]'
            finish = 'out[0]=lo;out[1]=hi;'
            if kind=='same':
                outputs = '[lo]"=&r"(lo),[f]"=&r"(f)'
                instruction = f'mulx{suffix} %{mod}[b],%{mod}[lo],%{mod}[lo]'
                finish = 'out[0]=lo;out[1]=lo;'
            elif kind=='source_dx': instruction = f'mulx{suffix} %{mod}[a],%{mod}[lo],%{mod}[hi]'
            elif kind=='low_dx':
                outputs = '[lo]"+&d"(a),[hi]"=&r"(hi),[f]"=&r"(f)'
                inputs = '[b]"r"(b),[old]"r"(old)';finish = 'out[0]=a;out[1]=hi;'
            elif kind=='high_dx':
                outputs = '[lo]"=&r"(lo),[hi]"+&d"(a),[f]"=&r"(f)'
                inputs = '[b]"r"(b),[old]"r"(old)';finish = 'out[0]=lo;out[1]=a;'
            elif kind=='all_dx':
                outputs = '[lo]"+d"(a),[f]"=&r"(f)'
                inputs = '[old]"r"(old)'
                instruction = f'mulx{suffix} %{mod}[lo],%{mod}[lo],%{mod}[lo]'
                finish = 'out[0]=a;out[1]=a;'
            source.append(f'void {name}(uint64_t a,uint64_t b,uint64_t old,uint64_t *out){{uint64_t lo,hi,f;'
                f'__asm__ volatile("pushfq;pushq %[old];popfq;{instruction};pushfq;popq %[f];popfq":{outputs}:{inputs}:"cc","memory");{finish}out[2]=f;}}')
    (folder/'cpu.c').write_text('\n'.join(source)+'\n')
    subprocess.run(['cc','-O2','-shared','-fPIC','-mno-red-zone','-mbmi2',folder/'cpu.c','-o',folder/'cpu.so'],check=True)
    cpu = ctypes.CDLL(str(folder/'cpu.so')); cpu_cases = 0
    edges = [0,1,2,(1<<32)-1,1<<32,(1<<63)-1,1<<63,MASK,0xABCDEF0123456789]
    rng = random.Random(0x4D554C58)
    values = [(a,b) for a in edges for b in edges]+[(rng.getrandbits(64),rng.getrandbits(64)) for _ in range(64)]
    for name,bits,kind in anchors:
        fn = getattr(cpu,name);fn.argtypes = [ctypes.c_uint64]*3+[ctypes.POINTER(ctypes.c_uint64)];fn.restype = None
        mask = (1<<bits)-1
        for a,b in (list(dict.fromkeys((a,a) for a,_ in values)) if kind in ('source_dx','all_dx') else values):
            product = (a&mask)*((a if kind in ('source_dx','all_dx') else b)&mask)
            low,high = product&mask,product>>bits
            if kind in ('same','all_dx'): low = high
            for flags in (0x202,0xAD7):
                out = (ctypes.c_uint64*3)();fn(a,b,flags,out)
                assert list(out)[:2]==[low,high] and (out[2]^flags)&0x8D5==0,(name,a,b,flags,list(out),low,high)
                cpu_cases += 1
    cases = []
    def add(bits,high,low,reg,code,memory=False,fault=False,address=0x2001):
        state = dict(registers=[rng.getrandbits(64) for _ in range(16)],flags=0xAD7,
            pc=MASK-2,xmm0=(1<<127)+71,fs_base=0,gs_base=0,memory=[])
        value = rng.getrandbits(64)
        if memory:
            state['registers'][reg] = address
            if code[0]==0x67: state['registers'][reg] += 1<<40
            if code[0]==0x64: state['fs_base']=0x10000;state['registers'][reg]=(address-0x10000)&MASK
            if code[0]==0x65: state['gs_base']=0x20000;state['registers'][reg]=(address-0x20000)&MASK
            state['memory'] = [dict(address=(address+i)&MASK,value=(value>>(8*i))&255,
                readable=not(fault and i==bits//8-1),writable=False,initialized=False) for i in range(bits//8)]
        else: value = state['registers'][reg]
        expected = copy.deepcopy(state); expected.update(pc=(state['pc']+len(code))&MASK,events=[],fault=None,defined_flags=MASK)
        if fault:
            expected.update(pc=state['pc'],fault=dict(kind='read',address=address,bytes=bits//8))
            expected['events'] = [dict(kind='fault',fault=expected['fault'])]
        else:
            mask = (1<<bits)-1;product = (state['registers'][2]&mask)*(value&mask)
            expected['registers'][low] = product&mask
            expected['registers'][high] = product>>bits
            if memory: expected['events'] = [dict(kind='read',address=address,
                value=[c['value'] for c in state['memory']],initialized=False)]
        cases.append((dict(isa='x86_64',native_bytes=list(code),state=state),expected))
    for bits,high,low,reg,code in codes: add(bits,high,low,reg,code)
    for bits in (32,64):
        for high in range(16):
            for low in range(16):
                for fault in (False,True): add(bits,high,low,7,encoding(bits,high,low,7,True),memory=True,fault=fault)
        # RIP/address32/segment and extended-base encodings reuse canonical EA.
        rip = bytes([0xC4,0x62,0xB3 if bits==64 else 0x33,0xF6,5])+(0x1FFB).to_bytes(4,'little')
        for fault in (False,True): add(bits,8,9,7,rip,memory=True,fault=fault)
        for prefix in (b'',b'\x67',b'\x64',b'\x65'):
            add(bits,8,9,15,prefix+encoding(bits,8,9,15,True),memory=True)
    binary = ROOT/'.lake/build/bin/reference'
    for start in range(0,len(cases),1024):
        batch = cases[start:start+1024]
        result = subprocess.run([str(binary)],input=''.join(json.dumps(r)+'\n' for r,_ in batch),text=True,capture_output=True,check=True)
        actual = [json.loads(line) for line in result.stdout.splitlines()];assert len(actual)==len(batch)
        for (request,expected),observed in zip(batch,actual): assert observed==expected,(request,observed,expected)
    for code in ('c4e2fbf6','66c4e2fbf6c1','c4e2fff6c1','c4e3fbf6c1','66'*11+'c4e2fbf6c1'):
        request = copy.deepcopy(cases[0][0]);request['native_bytes'] = list(bytes.fromhex(code))
        result = subprocess.run([str(binary)],input=json.dumps(request)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(request,result)
    print(f'x86 MULX: {cpu_cases} actual CPU product/alias/flag cases, {len(codes)} GNU encodings, {len(cases)} full-state native/fault cases PASS')


if __name__=='__main__': main()
