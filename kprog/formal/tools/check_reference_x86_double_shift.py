#!/usr/bin/env python3
"""SHLD/SHRD defined results, undefined lanes, GNU encodings and CPU flags."""
import copy
from check_reference import assert_native_state
import ctypes
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1<<64)-1
STATUS = 0x8D5


def encoding(left,bits,dst,src,count):
    rex = (8 if bits==64 else 0) | (4 if src>=8 else 0) | (1 if dst>=8 else 0)
    prefix = (b'\x66' if bits==16 else b'') + (bytes([0x40+rex]) if rex else b'')
    opcode = (0xA4 if left else 0xAC) + int(count=='cl')
    return prefix+bytes([0x0F,opcode,0xC0+8*(src%8)+dst%8])+(b'' if count=='cl' else bytes([count]))


def numeric(left,bits,a,b,count,old):
    lane = (1<<bits)-1; a &= lane; b &= lane; n = count & (63 if bits==64 else 31)
    pair = (a<<bits)|b if left else (b<<bits)|a
    result = (((pair<<n)>>bits) if left else (pair>>n)) & lane
    if not n: return result,old,MASK,False
    cf = ((a>>(bits-n if left else n-1))&1) if n<=bits else 0
    of = ((a^result)>>(bits-1))&1 if n==1 else (old>>11)&1
    flags = (old&~0x8C5)|cf|(of<<11)|((result>>(bits-1))<<7)|(int(result==0)<<6)|(int((result&255).bit_count()%2==0)<<2)
    defined = MASK^STATUS if n>bits else MASK^0x10 if n==1 else MASK^0x810
    return result,flags,defined,n>bits


def main():
    folder = ROOT/'build/double-shift-reference'; folder.mkdir(parents=True,exist_ok=True)
    source = ['#include <stdint.h>']
    for op in ('shld','shrd'):
        for bits,suffix,operand in ((16,'w','%w'),(32,'l','%k'),(64,'q','%')):
            source.append(f'uint64_t {op}{bits}(uint64_t a,uint64_t b,uint64_t n,uint64_t old,uint64_t *out){{uint64_t f;'
                '__asm__ volatile("pushfq;pushq %4;popfq;'+op+suffix+' %%cl,'+operand+'3,'+operand+'0;pushfq;popq %1;popfq"'
                ':"+a"(a),"=&r"(f):"c"(n),"r"(b),"r"(old):"cc","memory");*out=f;return a;}')
    (folder/'cpu.c').write_text('\n'.join(source)+'\n')
    subprocess.run(['cc','-O2','-shared','-fPIC','-mno-red-zone',folder/'cpu.c','-o',folder/'cpu.so'],check=True)
    cpu = ctypes.CDLL(str(folder/'cpu.so')); cpu_cases = 0; cases = []
    def add(left,bits,dst,src,count,a,b,flags,cl_amount=None):
        state = dict(registers=[(0xABCDEF0123456789+17*i)&MASK for i in range(16)],flags=flags,
            pc=MASK-1,xmm0=(1<<127)+79,fs_base=0x10000,gs_base=0x20000,memory=[])
        state['registers'][dst] = a;state['registers'][src] = b
        if count=='cl': state['registers'][1] = 0xF123456700000000|(((a^b) if cl_amount is None else cl_amount)&255)
        amount = state['registers'][1] if count=='cl' else count
        value,out_flags,defined,undefined = numeric(left,bits,state['registers'][dst],state['registers'][src],amount,flags)
        code = encoding(left,bits,dst,src,count)
        expected = copy.deepcopy(state);expected.update(pc=(state['pc']+len(code))&MASK,events=[],fault=None,flags=out_flags,defined_flags=defined)
        expected['registers'][dst] = value if bits==32 else (state['registers'][dst]&~((1<<bits)-1))|value
        if undefined: expected['defined_registers'] = [(MASK^((1<<bits)-1)) if r==dst else MASK for r in range(16)]
        cases.append((dict(isa='x86_64',native_bytes=list(code),state=state),expected))
    vectors = [(0,0),(1,MASK),(MASK,1),(0x8000000000008001,0x12345678ABCDEF01),(0xABCDEF0123456789,0xFEDCBA9876543210)]
    for left,op in ((True,'shld'),(False,'shrd')):
        for bits in (16,32,64):
            fn = getattr(cpu,op+str(bits));fn.argtypes = [ctypes.c_uint64]*4+[ctypes.POINTER(ctypes.c_uint64)];fn.restype = ctypes.c_uint64
            for n in range(256):
                for a,b in vectors:
                    for flags in (0x202,0xAD7):
                        value,out_flags,defined,undefined = numeric(left,bits,a,b,n,flags)
                        native_flags = ctypes.c_uint64();actual = fn(a,b,n,flags,ctypes.byref(native_flags))
                        expected = value if bits==32 else (a&~((1<<bits)-1))|value
                        register_mask = MASK^((1<<bits)-1) if undefined else MASK
                        assert (actual^expected)&register_mask==0,(op,bits,n,a,b,actual,expected,register_mask)
                        assert (native_flags.value^out_flags)&defined&STATUS==0,(op,bits,n,native_flags.value,out_flags,defined)
                        cpu_cases += 1
                        add(left,bits,0,3,n,a,b,flags)
                        if (a,b)==vectors[0]:
                            for dst in (0,1): add(left,bits,dst,3,'cl',a,b,flags,cl_amount=n)
            # Every source/destination register combination and both count
            # encodings, including RCX as source, destination and count.
            for dst in range(16):
                for src in range(16):
                    for n in (0,1,16,17,31,63,'cl'):
                        add(left,bits,dst,src,n,0xABCDEF0123456789,0xFEDCBA9876543210,0xAD7)
    names = {16:['ax','cx','dx','bx','sp','bp','si','di']+[f'r{i}w' for i in range(8,16)],
        32:['eax','ecx','edx','ebx','esp','ebp','esi','edi']+[f'r{i}d' for i in range(8,16)],
        64:['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]}
    asm = ['.intel_syntax noprefix','.text'];expected_codes = []
    for left,op in ((True,'shld'),(False,'shrd')):
        for bits in (16,32,64):
            for dst in range(16):
                for src in range(16):
                    for n in (254,'cl'):
                        asm += [f'p{len(expected_codes)}:',f'{op} {names[bits][dst]},{names[bits][src]},{n}']
                        expected_codes.append(encoding(left,bits,dst,src,n))
    (folder/'encodings.s').write_text('\n'.join(asm)+'\n')
    subprocess.run(['as','--64',folder/'encodings.s','-o',folder/'encodings.o'],check=True)
    disassembly = subprocess.check_output(['objdump','-d','-Mintel',folder/'encodings.o'],text=True)
    # Match both SHLD and SHRD spellings explicitly.
    actual_codes = [bytes.fromhex(m[1]) for m in re.finditer(r'^\s*[0-9a-f]+:\s+((?:[0-9a-f]{2}\s+)+)sh(?:ld|rd)\b',disassembly,re.M)]
    assert actual_codes==expected_codes,(len(actual_codes),len(expected_codes))
    binary = ROOT/'.lake/build/bin/reference'
    for start in range(0,len(cases),1024):
        batch = cases[start:start+1024]
        result = subprocess.run([str(binary)],input=''.join(json.dumps(r)+'\n' for r,_ in batch),text=True,capture_output=True,check=True)
        actual = [json.loads(line) for line in result.stdout.splitlines()];assert len(actual)==len(batch)
        for (request,expected),observed in zip(batch,actual): assert_native_state(observed, expected, (request,observed,expected))
    for code in ('0fa4c3','480fad','66'*12+'0fa4c301'):
        request = copy.deepcopy(cases[0][0]);request['native_bytes'] = list(bytes.fromhex(code))
        result = subprocess.run([str(binary)],input=json.dumps(request)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(request,result)
    print(f'x86 SHLD/SHRD: {cpu_cases} actual CPU cases with ISA masks, {len(expected_codes)} GNU encodings, {len(cases)} full-state cases PASS')


if __name__=='__main__': main()
