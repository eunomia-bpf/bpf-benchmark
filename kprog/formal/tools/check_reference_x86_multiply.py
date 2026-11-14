#!/usr/bin/env python3
"""IMUL native encodings, full signed products, CPU flags and precise reads."""
import copy
from check_reference import assert_native_state
import ctypes
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def signed(value, bits):
    value &= (1 << bits) - 1
    return value - (1 << bits) if value >> (bits - 1) else value


def main():
    folder = ROOT / 'build/multiply-reference'; folder.mkdir(parents=True, exist_ok=True)
    source = ['#include <stdint.h>']
    for bits,suffix,operand in ((16,'w','%w'),(32,'l','%k'),(64,'q','%')):
        source.append(f'uint64_t multiply{bits}(uint64_t a,uint64_t b,uint64_t old,uint64_t *out){{uint64_t f;'
            '__asm__ volatile("pushfq;pushq %3;popfq;imul'+suffix+' '+operand+'2,'+operand+'0;pushfq;popq %1;popfq"'
            ':"+a"(a),"=r"(f):"r"(b),"r"(old):"cc","memory");*out=f;return a;}')
    for bits, suffix, operand in ((8,'b','b'),(16,'w','w'),(32,'l','k'),(64,'q','')):
        source.append('void unsigned'+str(bits)+'(uint64_t a,uint64_t b,uint64_t h,uint64_t old,uint64_t *out){uint64_t f;'
            '__asm__ volatile("pushfq;pushq %[old];popfq;mul'+suffix+' %'+operand+'[b];pushfq;popq %[f];popfq"'
            ':[a]"+a"(a),[h]"+d"(h),[f]"=&r"(f):[b]"c"(b),[old]"r"(old):"cc","memory");out[0]=a;out[1]=h;out[2]=f;}')
    (folder/'cpu.c').write_text('\n'.join(source)+'\n')
    subprocess.run(['cc','-O2','-shared','-fPIC','-mno-red-zone',folder/'cpu.c','-o',folder/'cpu.so'],check=True)
    cpu=ctypes.CDLL(str(folder/'cpu.so')); cases=[]; cpu_count=0

    def add(code,bits,left,right,*,dst=0,src=3,immediate=False,memory=False,fault=False,address=0x2001):
        state=dict(registers=[0xABCDEF0123456789+17*i for i in range(16)],flags=0xAD7,
                   pc=MASK-3,xmm0=(1<<127)+17,fs_base=0,gs_base=0,memory=[])
        state['registers'][7]=address
        state['registers'][dst]=0xFEDCBA9876543210 if immediate else left
        if not memory: state['registers'][src]=left if immediate else right
        else:
            value=left if immediate else right
            state['memory']=[dict(address=(address+i)&MASK,value=(value>>(8*i))&255,
                readable=not(fault and i==bits//8-1),writable=False,initialized=False) for i in range(bits//8)]
        request=dict(isa='x86_64',native_bytes=list(bytes.fromhex(code)),state=state)
        expected=copy.deepcopy(state)
        product=signed(left,bits)*signed(right,bits)
        overflow=not(-(1<<(bits-1))<=product<(1<<(bits-1)))
        value=product&((1<<bits)-1)
        expected.update(pc=(state['pc']+len(request['native_bytes']))&MASK,events=[],fault=None,
                        defined_flags=MASK^0xD4)
        if fault:
            expected['pc']=state['pc'];expected['defined_flags']=MASK
            expected['fault']=dict(kind='read',address=address,bytes=bits//8)
            expected['events']=[dict(kind='fault',fault=expected['fault'])]
        else:
            old=state['registers'][dst]
            expected['registers'][dst]=value if bits==32 else (old&~((1<<bits)-1))|value
            expected['flags']=(state['flags']&~0x801)|(0x801 if overflow else 0)
            if memory: expected['events']=[dict(kind='read',address=address,
                value=[c['value'] for c in state['memory']],initialized=False)]
        cases.append((request,expected))

    for bits,prefix in ((16,'66'),(32,''),(64,'48')):
        fn=getattr(cpu,'multiply'+str(bits));fn.argtypes=[ctypes.c_uint64]*3+[ctypes.POINTER(ctypes.c_uint64)];fn.restype=ctypes.c_uint64
        edge=[0,1,2,-1,-2,(1<<(bits-1))-1,1<<(bits-1),(1<<bits)-1,0x8123456789ABCDEF]
        for a in edge:
            for b in edge:
                left=a&MASK;right=b&MASK
                product=signed(left,bits)*signed(right,bits)
                overflow=not(-(1<<(bits-1))<=product<(1<<(bits-1)))
                flags=ctypes.c_uint64();value=fn(left,right,0xAD7,ctypes.byref(flags))
                expected=product&((1<<bits)-1)
                expected=expected if bits==32 else (left&~((1<<bits)-1))|expected
                assert value==expected and flags.value&0x801==(0x801 if overflow else 0),(bits,a,b,value,flags.value)
                cpu_count+=1
                add(prefix+'0fafc3',bits,left,right)
                add(prefix+'0faf07',bits,left,right,memory=True)
                for immediate in (-128,-7,0,127):
                    add(prefix+'6bc3'+f'{immediate&255:02x}',bits,left,immediate&MASK,immediate=True)
                    add(prefix+'6b07'+f'{immediate&255:02x}',bits,left,immediate&MASK,immediate=True,memory=True)
            for immediate in (-(1<<(min(bits,32)-1)),(1<<(min(bits,32)-1))-1):
                raw=(immediate&((1<<min(bits,32))-1)).to_bytes(min(bits,32)//8,'little').hex()
                add(prefix+'69c3'+raw,bits,a&MASK,immediate&MASK,immediate=True)
                add(prefix+'6907'+raw,bits,a&MASK,immediate&MASK,immediate=True,memory=True)
            add(prefix+'0fafc0',bits,a&MASK,a&MASK,src=0)
            add(prefix+'6bc0f9',bits,a&MASK,(-7)&MASK,immediate=True,src=0)
        add(prefix+'0faf07',bits,0x123,0x8123,memory=True,fault=True)
        add(prefix+'6b07f9',bits,0x123,(-7)&MASK,immediate=True,memory=True,fault=True)
    # REX extension, prefix ordering, RIP-relative trailing immediate and PC wrap.
    add('4c0fafc0',64,0x8000000000000000,2,dst=8,src=0)
    add('490fafc0',64,2,0x8000000000000000,src=8)
    add('48660fafc3',16,0x1234,0xFFFE)
    add('66480fafc3',64,0x1234,MASK)
    add('486b0500000000f9',64,0x1234,(-7)&MASK,immediate=True,memory=True,address=4)
    add('4869050000000000000080',64,0x1234,(-0x80000000)&MASK,immediate=True,memory=True,address=7)
    unsigned_count = 0
    for bits in (8,16,32,64):
        fn = getattr(cpu,'unsigned'+str(bits))
        fn.argtypes = [ctypes.c_uint64]*4+[ctypes.POINTER(ctypes.c_uint64)]
        narrow = (1 << bits)-1
        forms = [(src,False,False,False) for src in range(16)]
        if bits == 8: forms += [(src,True,False,False) for src in range(4)]
        forms += [(7,False,True,fault) for fault in (False,True)]
        for src,high_byte,memory,fault in forms:
            for left,right in ((0,1),(1,1),(MASK,MASK),(1 << (bits-1),2),(0x8123456789abcdef,0xfedcba9876543210)):
                registers = [(0xabcdef0123456789+17*i)&MASK for i in range(16)]
                registers[0],registers[2] = left,0x87654321fedcba98
                if src not in (0,2): registers[src] = right
                if memory: registers[7] = 0x2001
                value = right if memory else (registers[src] >> 8) if high_byte else registers[src]
                product = (registers[0]&narrow)*(value&narrow)
                low,high = product&narrow,product >> bits
                wanted = registers.copy()
                def write(index,value,width):
                    wanted[index] = value if width >= 32 else (wanted[index]&~((1 << width)-1))|value
                if bits == 8: write(0,product,16)
                else: write(0,low,bits);write(2,high,bits)
                anchor = (ctypes.c_uint64*3)()
                fn(registers[0],value,registers[2],0xAD7,anchor)
                assert list(anchor)[:2] == [wanted[0],wanted[2]], (bits,src,registers,list(anchor),wanted)
                assert anchor[2]&0x801 == (0x801 if high else 0), (bits,src,product,list(anchor))
                rex = (8 if bits==64 else 0)+(1 if src>=8 else 0)
                # Byte codes4..7 need REX for SPL/BPL/SIL/DIL instead of AH..BH.
                prefix = ([0x66] if bits==16 else [])+([0x40+rex] if rex or (bits==8 and src>=4 and not memory) else [])
                code = prefix+[0xF6 if bits==8 else 0xF7,(0x20 if memory else 0xE0)+(src+4 if high_byte else src)%8]
                state = dict(registers=registers,flags=0xAD7,pc=0x4000,xmm0=(1 << 127)+17,fs_base=0,gs_base=0,memory=[])
                if memory:
                    state['memory'] = [dict(address=0x2001+i,value=(value >> (8*i))&255,readable=not(fault and i==bits//8-1),writable=False,initialized=False) for i in range(bits//8)]
                expected = copy.deepcopy(state)
                expected.update(registers=wanted,flags=(0xAD7&~0x801)|(0x801 if high else 0),pc=0x4000+len(code),events=[],fault=None,defined_flags=MASK^0xD4)
                if memory: expected['events'] = [dict(kind='read',address=0x2001,value=[c['value'] for c in state['memory']],initialized=False)]
                if fault:
                    expected = copy.deepcopy(state)
                    reason = dict(kind='read',address=0x2001,bytes=bits//8)
                    expected.update(fault=reason,events=[dict(kind='fault',fault=reason)],defined_flags=MASK)
                cases.append((dict(isa='x86_64',native_bytes=code,state=state),expected))
                unsigned_count += 1
    print(f'x86 unsigned MUL: {unsigned_count} hardware/Python pair-product and native state cases: every GPR/high8 source, RAX/RDX aliases, exact memory reads/faults')
    binary=ROOT/'.lake/build/bin/reference'
    for start in range(0,len(cases),1024):
        batch=cases[start:start+1024]
        result=subprocess.run([str(binary)],input=''.join(json.dumps(r)+'\n' for r,_ in batch),text=True,capture_output=True,check=True)
        actual=[json.loads(line) for line in result.stdout.splitlines()];assert len(actual)==len(batch)
        for (request,expected),observed in zip(batch,actual): assert_native_state(observed, expected, (request,observed,expected))
    for code in ('0faf','486bc3','6669c300','66'*13+'0fafc3'):
        request=copy.deepcopy(cases[0][0]);request['native_bytes']=list(bytes.fromhex(code))
        result=subprocess.run([str(binary)],input=json.dumps(request)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(request,result)
    print(f'x86 IMUL: {cpu_count} actual CPU products/CF/OF and {len(cases)} full-state native/alias/memory/fault cases PASS')


if __name__=='__main__': main()
