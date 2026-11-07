#!/usr/bin/env python3
"""Exercise encoder-produced high-byte memory loads, aliases and access widths."""
import importlib.util
from pathlib import Path
import subprocess
import sys
from check_x86_memory_widths import accesses, instructions_by_function

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0,str(ROOT.parent/"x86/micro-prog"))
spec = importlib.util.spec_from_file_location("high_load_encoder",ROOT.parent/"x86/micro-prog/generate_micro_sim_proofs.py")
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)


def main():
    folder=ROOT/"build/high-load"
    folder.mkdir(parents=True,exist_ok=True)
    includes=["-include", str(ROOT/"oracles/arm64_entry_environment_host.h"), "-I"+str(ROOT.parent/"x86/micro-prog"),"-I"+str(ROOT),
              "-I"+str(ROOT.parent/"x86"),"-I"+str(ROOT.parents[1]/"vendor/libbpf/src"),"-I/usr/include/x86_64-linux-gnu"]
    cases=[]
    for base,high in (("rax","ah"),("rcx","ch"),("rdx","dh"),("rbx","bh")):
        for kind in ("direct","negative","index","alias","stack","readonly"):
            prefix=[]
            address="rdi+3"
            if kind=="negative": prefix=[("lea",("rdi","[rdi+6]"))];address="rdi-3"
            if kind=="index": prefix=[("mov",("rcx","2"))];address="rdi+rcx*2-1"
            if kind=="alias": prefix=[("mov",(base,"rdi"))];address=base+"+3"
            if kind=="stack":
                prefix=[("sub",("rsp","8")),("mov",("dl","BYTE PTR [rdi+3]")),("mov",("BYTE PTR [rsp+3]","dl"))]
                address="rsp+3"
            if kind=="readonly": address="rip+0"
            body=[g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(prefix)]
            load=g.NativeInsn(len(body),f"mov {high},BYTE PTR [{address}]","mov",(high,f"BYTE PTR [{address}]"),
                reloc_symbol="datum" if kind=="readonly" else None,
                reloc_type="R_X86_64_PC32" if kind=="readonly" else None,symbol_offset=3 if kind=="readonly" else 0)
            body.append(load)
            body.append(g.NativeInsn(len(body),f"movzx eax,{high}","movzx",("eax",high)))
            if kind=="stack": body.append(g.NativeInsn(len(body),"add rsp,8","add",("rsp","8")))
            body.append(g.NativeInsn(len(body),"ret","ret",()))
            name=f"high_load_{high}_{kind}"
            program=g.render_program(name,body,kind="raw",program_section="xdp",
                rodata16={"datum":bytes([0x50+17*i & 255 for i in range(16)])} if kind=="readonly" else None)
            path=folder/(name+".c")
            count=1 if kind=="readonly" else 256
            expected="0x83U" if kind=="readonly" else "b"
            path.write_text(program+f'\nint main(void) {{unsigned char data[16]={{0}};for(unsigned b=0;b<{count};b++){{data[3]=b;if((unsigned){name}_x86_sim_xdp(data)!={expected})return 1;}}return 0;}}\n')
            subprocess.run(["cc","-O2","-fsanitize=undefined","-fno-sanitize-recover=undefined",*includes,
                            str(path),"-o",str(path.with_suffix(""))],check=True)
            subprocess.run([str(path.with_suffix(""))],check=True)
            path.write_text(program)
            subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,
                            "-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
            cases.append(name)
        # Inspect the actual encoded expression in a raw pointer probe. The
        # incoming GPR starts nonzero, so the high lane also preserves low bits.
        load=g.NativeInsn(0,f"mov {high},BYTE PTR [rdi+3]","mov",(high,"BYTE PTR [rdi+3]"))
        encoded=g.encode(load,{})
        path=folder/f"probe_{high}.c"
        path.write_text('#include "x86_sim_local_bpf.h"\n__u64 probe(void *p){X86_SIM_ENTRY_RAW(p);\n'+
            f'X86_SIM_L_WRITE_REG_PTR_TAG({g.reg_info(high)[0]},(void *)0x12345678UL,X86_SIM_TAG_SCALAR);\n'+
            f'X86_SIM_L_EXEC_MOV_IMM_AUX({encoded.dst},{encoded.flags},{encoded.aux},{encoded.imm});\n'+
            f'return X86_SIM_L_READ_REG({g.reg_info(high)[0]});}}\n')
        subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,
                        "-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
        assembly=subprocess.check_output(["llvm-objdump-18","-d",str(path.with_suffix(".o"))],text=True)
        path.with_suffix(".asm").write_text(assembly)
        functions=instructions_by_function(assembly)
        assert len(functions)==1 and accesses(next(iter(functions.values())))==[("read",3,1)],assembly
    print(f"x86 high-byte loads: {len(cases)} encoded host/BPF programs, 5124 byte/alias/stack/readonly results and four exact one-byte BPF reads OK")


if __name__=="__main__":
    main()
