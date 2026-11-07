#!/usr/bin/env python3
"""Production classic ROR/ROL lanes, CL aliases, flags and RMW addressing."""
import ctypes
import importlib.util
from pathlib import Path
import subprocess
import sys
from check_reference_x86_legacy_shift import numeric
from check_x86_memory_widths import accesses, instructions_by_function

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT.parent / 'x86/micro-prog'))
spec = importlib.util.spec_from_file_location('rotate_encoder', ROOT.parent / 'x86/micro-prog/generate_micro_sim_proofs.py')
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)
MASK = (1 << 64) - 1
REGS = ['X86_'+r for r in ('RAX','RCX','RDX','RBX','RSP','RBP','RSI','RDI',*[f'R{i}' for i in range(8,16)])]


def main():
    folder = ROOT / 'build/rotate-handler'
    folder.mkdir(parents=True, exist_ok=True)
    includes = ['-include', str(ROOT/'oracles/arm64_entry_environment_host.h'),
        '-I'+str(ROOT.parent/'x86/micro-prog'), '-I'+str(ROOT), '-I'+str(ROOT.parent/'x86'),
        '-I'+str(ROOT.parents[1]/'vendor/libbpf/src'), '-I/usr/include/x86_64-linux-gnu']
    forms = [('ror', name, bits, reg, shift, None) for name,(reg,bits,shift) in g.REGS.items()]
    forms += [('rol', name, 8, reg, shift, None) for name,(reg,bits,shift) in g.REGS.items() if shift]
    for bits, ptr in ((8,'BYTE'),(16,'WORD'),(32,'DWORD'),(64,'QWORD')):
        forms += [('ror', ptr+' PTR ['+addr+']', bits, 'X86_RAX', 0, route)
                  for route,addr in [('direct','rdi+3'),('index','rdi+rsi*2-1'),('stack','rsp+3')]]
    source = ['#define X86_SIM_ENABLE_STACK 1', '#include "x86_sim_local_bpf.h"']
    cases = []
    for op,operand,bits,reg,lane,memory in forms:
        for count in dict.fromkeys([0,1,bits,bits+1,255,'cl']):
            insn = g.NativeInsn(0, f'{op} {operand},{count}', op, (operand,str(count)))
            encoded = g.encode(insn,{})
            step = g.direct_step_statement(encoded) + ";"
            name = 'probe'+str(len(cases))
            setup = 'X86_SIM_ENTRY_RAW(data);'
            for i,r in enumerate(REGS):
                setup += f'X86_SIM_L_WRITE_REG_PTR({r},(void *)(long)({i+17}ULL));'
            setup += f'X86_SIM_L_WRITE_REG_PTR({reg},(void *)(long)a);' if not memory else ''
            setup += ('X86_SIM_L_WRITE_REG_PTR(X86_RCX,(void *)(long)((a&~255ULL)|(n&255)));' if reg=='X86_RCX' and not memory else 'X86_SIM_L_WRITE_REG_PTR(X86_RCX,(void *)(long)n);') if count=='cl' else ''
            if memory:
                setup += 'X86_SIM_L_WRITE_REG_PTR(X86_RDI,data);X86_SIM_L_WRITE_REG_PTR(X86_RSI,(void *)2);'
                if memory=='stack': setup += f'X86_SIM_L_WRITE_REG_PTR(X86_RSP,(void *)-16L);X86_SIM_L_STACK_WRITE(-13,{g.WIDTH_CONST[bits]},a);'
            for flag,bit in [('cf',0),('pf',2),('af',4),('zf',6),('sf',7),('of',11)]: setup += f'__x86_{flag}=(flags>>{bit})&1;'
            output = ''.join(f'out[{i}]=X86_SIM_L_READ_REG({r});' for i,r in enumerate(REGS))
            output += 'out[16]=__x86_cf|(__x86_pf<<2)|(__x86_af<<4)|(__x86_zf<<6)|(__x86_sf<<7)|(__x86_of<<11);'
            if memory=='stack': output += f'out[17]=X86_SIM_L_STACK_READ(-13,{g.WIDTH_CONST[bits]});'
            source.append(f'void {name}(unsigned long long a,unsigned long long n,unsigned long long flags,unsigned char *data,unsigned long long *out){{{setup}{step}{output}}}')
            cases.append((name,op,bits,reg,lane,memory,count))
    path = folder/'host.c'; path.write_text('\n'.join(source)+'\n')
    subprocess.run(['cc','-O2','-shared','-fPIC','-fsanitize=undefined','-fno-sanitize-recover=undefined',*includes,path,'-o',folder/'host.so'],check=True)
    library = ctypes.CDLL(str(folder/'host.so')); total = 0
    for name,op,bits,reg,lane,memory,count in cases:
        fn = getattr(library,name); fn.argtypes = [ctypes.c_uint64]*3+[ctypes.POINTER(ctypes.c_ubyte),ctypes.POINTER(ctypes.c_uint64)]; fn.restype = None
        for n in ([0,1,7,8,15,16,17,31,32,33,63,64,65,127,128,255] if count=='cl' else [count]):
            for a in [0,1,MASK,0xABCDEF0123456789,0x8000000000000081]:
                for flags in (0x202,0xAD7):
                    data = (ctypes.c_ubyte*16)(*([0xA5]*16)); out = (ctypes.c_uint64*18)()
                    expected_regs = list(range(17,33))
                    if not memory: expected_regs[REGS.index(reg)] = a
                    if count=='cl': expected_regs[1] = (a&~255)|n if reg=='X86_RCX' and not memory else n
                    if memory:
                        expected_regs[7] = ctypes.addressof(data); expected_regs[6] = 2
                        if memory=='stack': expected_regs[4] = (-16)&MASK
                        data[3:3+bits//8] = list((a&((1<<bits)-1)).to_bytes(bits//8,'little'))
                        value_in = a
                    else: value_in = expected_regs[REGS.index(reg)] >> lane
                    value,out_flags,defined = numeric(op,bits,value_in,n,flags)
                    if not memory:
                        index = REGS.index(reg); mask = ((1<<bits)-1)<<lane
                        expected_regs[index] = value if bits==32 else (expected_regs[index]&~mask)|(value<<lane)
                    fn(a,n,flags,data,out)
                    assert list(out)[:16]==expected_regs,(name,a,n,list(out)[:16],expected_regs)
                    assert (out[16]^out_flags)&defined&0x8D5==0,(name,a,n,out[16],out_flags)
                    if memory:
                        assert (out[17] if memory=='stack' else int.from_bytes(bytes(data)[3:3+bits//8],'little'))==value,(name,a,n,value,list(out))
                        assert bytes(data)[:3]==bytes([0xA5]*3) and bytes(data)[3+bits//8:]==bytes([0xA5]*(13-bits//8))
                    total += 1
    # Compile actual rendered artifacts; this exercises the direct-call table
    # and prevents host-only fixes from silently disappearing in BPF lowering.
    artifacts = 0
    for bits,operand in [(8,'ah'),(16,'ax'),(32,'eax'),(64,'rax'),(8,'ch'),(8,'cl'),
                         (8,'BYTE PTR [rdi+3]'),(16,'WORD PTR [rdi+3]'),
                         (32,'DWORD PTR [rdi+3]'),(64,'QWORD PTR [rdi+3]')]:
        for count in ('0','1','8','cl'):
            body = [g.NativeInsn(0,'mov rax,1','mov',('rax','1')),
                g.NativeInsn(1,'mov rcx,1','mov',('rcx','1')),
                g.NativeInsn(2,f'ror {operand},{count}','ror',(operand,count)),
                g.NativeInsn(3,'xor eax,eax','xor',('eax','eax')),g.NativeInsn(4,'ret','ret',())]
            name = 'rotate_bpf'+str(artifacts); p = folder/(name+'.c')
            p.write_text(g.render_program(name,body,kind='raw',program_section='xdp'))
            subprocess.run(['clang-18','-target','bpfel','-O2','-D__TARGET_ARCH_x86',*includes,'-c',p,'-o',p.with_suffix('.o')],check=True)
            if 'PTR' in operand:
                assembly = subprocess.check_output(['llvm-objdump-18','-d',p.with_suffix('.o')],text=True)
                functions = instructions_by_function(assembly)
                assert len(functions)==1, assembly
                actual_accesses = accesses(next(iter(functions.values())))
                expected_accesses = [('read',3,bits//8),('write',3,bits//8)]
                assert actual_accesses==expected_accesses, (operand,count,actual_accesses,expected_accesses)
            artifacts += 1
    print(f'x86 classic rotates: {len(cases)} encoded handlers, {total} register/CL/flag/RMW results, {artifacts} rendered BPF artifacts PASS')


if __name__ == '__main__': main()
