#!/usr/bin/env python3
"""Check encoded DIV values and retain the real BPF native-fault marker."""
import importlib.util
from pathlib import Path
import struct
import subprocess
import sys
from check_x86_memory_widths import instructions_by_function
ROOT=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(ROOT.parent/"x86/micro-prog"))
spec=importlib.util.spec_from_file_location("divide_encoder",ROOT.parent/"x86/micro-prog/generate_micro_sim_proofs.py")
g=importlib.util.module_from_spec(spec)
sys.modules[spec.name]=g
spec.loader.exec_module(g)


def main():
    folder=ROOT/"build/divide-handler"
    folder.mkdir(parents=True,exist_ok=True)
    includes=["-include", str(ROOT/"oracles/arm64_entry_environment_host.h"), "-I"+str(ROOT.parent/"x86/micro-prog"),"-I"+str(ROOT),"-I"+str(ROOT.parent/"x86"),
        "-I"+str(ROOT.parents[1]/"vendor/libbpf/src"),"-I/usr/include/x86_64-linux-gnu"]
    byte_names={8:"cl",16:"cx",32:"ecx",64:"rcx"}
    ptr_names={8:"BYTE",16:"WORD",32:"DWORD",64:"QWORD"}
    for width in (8,16,32,64):
        for kind in (("reg","mem","high") if width==8 else ("reg","mem")):
            memory, high_byte = kind=="mem", kind=="high"
            operand=ptr_names[width]+" PTR [rdi+16]" if memory else "ch" if high_byte else byte_names[width]
            rows=[("mov",("rax","QWORD PTR [rdi]")),("mov",("rdx","QWORD PTR [rdi+8]"))]
            if not memory: rows.append(("mov",("rcx","QWORD PTR [rdi+16]")))
            rows += [("div",(operand,)),("mov",("QWORD PTR [rdi+24]","rax")),
                     ("mov",("QWORD PTR [rdi+32]","rdx")),("xor",("eax","eax")),("ret",())]
            insns=[g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(rows)]
            name=f"divide_{width}_{kind}"
            program=g.render_program(name,insns,kind="raw",program_section="xdp")
            path=folder/(name+".c")
            # Construct only nonfaulting CPU inputs; high < divisor guarantees
            # a representable quotient, including nonzero high halves at64bit.
            source=program+f'''
int main(void) {{
  unsigned long long seed=0x1191827733abcdefULL;
  for(unsigned i=0;i<2048;++i) {{
    seed=seed*6364136223846793005ULL+1;
    unsigned long long mask={hex((1<<width)-1)}ULL,divisor=(seed&mask)|1;
    unsigned long long high=(seed>>1)%divisor,low=seed^0xa9a5a7a1b8b2b4b6ULL;
    if({width}==8)low=(low&~65535ULL)|(high<<8)|(low&255);
    unsigned long long data[5]={{low,high,divisor << {8 if high_byte else 0},0,0}};
    unsigned long long q=low,r=high;
    __asm__ volatile("div{'b %h2' if high_byte else {8:'b %b2',16:'w %w2',32:'l %k2',64:'q %2'}[width]}" : "+a"(q),"+d"(r) : "{'c' if high_byte else 'r'}"(divisor << {8 if high_byte else 0}) : "cc");
    if({name}_x86_sim_xdp(data)!=0 || data[3]!=q || data[4]!=r)return 1;
  }}
  return 0;
}}
'''
            path.write_text(source)
            subprocess.run(["cc","-O2","-fsanitize=undefined","-fno-sanitize-recover=undefined",*includes,str(path),"-o",str(path.with_suffix(""))],check=True)
            subprocess.run([str(path.with_suffix(""))],check=True)
            path.write_text(program)
            subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,"-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
        for overflow in ((False,True,"high") if width==8 else (False,True)):
            rows=[("mov",("rax","0x100" if width==8 and overflow else "0")),
                  ("mov",("rdx","1" if overflow else "0")),("mov",("rcx","1" if overflow else "0")),
                  ("div",("ah" if overflow=="high" else byte_names[width],)),("ret",())]
            insns=[g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(rows)]
            name=f"fault_{width}_{overflow}"
            path=folder/(name+".c")
            path.write_text(g.render_program(name,insns,kind="raw",program_section="xdp"))
            subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,"-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
            assembly=subprocess.check_output(["llvm-objdump-18","-d",str(path.with_suffix(".o"))],text=True)
            path.with_suffix(".asm").write_text(assembly)
            functions=instructions_by_function(assembly)
            instructions=[struct.unpack("<BBhi",raw) for body in functions.values() for raw in body]
            marker=[(0xb7,0,0,0),(0x7b,0,0,0),(0x95,0,0,0)]
            assert any(instructions[i:i+3]==marker for i in range(len(instructions)-2)),assembly
    for width,low,high,result in ((8,"ax",None,130),(16,"ax","dx",0)):
        rows=[("mov",(low,"260" if width==8 else "1")),("mov",(byte_names[width],"2"))]
        if high: rows.append(("mov",(high,"0")))
        rows += [("div",(byte_names[width],)),("movzx",("eax","al" if width==8 else "ax")),("ret",())]
        insns=[g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(rows)]
        name=f"narrow_divide_{width}"
        program=g.render_program(name,insns,kind="raw",program_section="xdp")
        path=folder/(name+".c")
        path.write_text(program+f"\nint main(void){{return {name}_x86_sim_xdp((void*)0)!={result};}}\n")
        subprocess.run(["cc","-O2",*includes,str(path),"-o",str(path.with_suffix(""))],check=True)
        subprocess.run([str(path.with_suffix(""))],check=True)
        path.write_text(program)
        subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,"-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
    print("x86 DIV handler:18432 actual CPU/encoded register-memory/high-byte results,9 valid BPF compiles and9 retained zero/overflow/AX-alias fault markers;2 narrow-result controls OK")



if __name__=="__main__":
    main()
