#!/usr/bin/env python3
"""Check native widening moves: source width/lane, writeback, aliases and faults."""
import copy
import json
import importlib.util
import sys
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def main():
    cases = []

    def add(code, sw, tw, signed, value, *, src=1, dst=0, lane=0, memory=False, fault=False):
        request = dict(native_bytes=list(bytes.fromhex(code)), state=dict(
            registers=[0xABCDEF0123450000 + i for i in range(16)], flags=0xAD7,
            pc=0x1000, xmm0=(1 << 127) + 7, fs_base=0, gs_base=0, memory=[]))
        state = request["state"]
        if memory:
            state["registers"][src] = 0x2001
            state["memory"] = [dict(address=0x2001 + i, value=(value >> (8*i)) & 255,
                readable=not (fault and i == sw-1), writable=False, initialized=False) for i in range(sw)]
        else:
            state["registers"][src] = value
        expected = copy.deepcopy(state)
        expected.update(pc=state["pc"]+len(request["native_bytes"]), events=[], fault=None, defined_flags=MASK)
        if fault:
            expected.update(pc=state["pc"], fault=dict(kind="read", address=0x2001, bytes=sw))
            expected["events"] = [dict(kind="fault", fault=expected["fault"])]
        else:
            raw = (value >> lane) & ((1 << (8*sw))-1)
            result = raw - (1 << (8*sw)) if signed and raw & (1 << (8*sw-1)) else raw
            result &= (1 << (8*tw))-1
            expected["registers"][dst] = (state["registers"][dst] & ~0xFFFF) | result if tw == 2 else result
            if memory:
                expected["events"] = [dict(kind="read", address=0x2001,
                    value=[c["value"] for c in state["memory"]], initialized=False)]
        cases.append((request, expected))

    values = [0, 1, 0x7F, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF,
              0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0xAABBCCDD987681FA, MASK]
    for sw, signed, opcode in ((1, False, "b6"), (2, False, "b7"), (1, True, "be"), (2, True, "bf")):
        for tw, prefix in ((2, "66"), (4, ""), (8, "48")):
            if sw > tw: continue
            for value in values:
                for modrm, src, dst, memory in (("c1", 1, 0, False), ("c0", 0, 0, False),
                                               ("01", 1, 0, True), ("09", 1, 1, True)):
                    add(prefix+"0f"+opcode+modrm, sw, tw, signed, value, src=src, dst=dst, memory=memory)
                if sw == 1 and tw != 8:
                    add(prefix+"0f"+opcode+"c4", sw, tw, signed, value, src=0, lane=8)
                rex = "4d" if tw == 8 else "45"
                add(("66" if tw == 2 else "")+rex+"0f"+opcode+"c1", sw, tw, signed, value, src=9, dst=8)
                if sw == 1:
                    add(("66" if tw == 2 else "")+("48" if tw == 8 else "40")+"0f"+opcode+"c4",
                        sw, tw, signed, value, src=4)
            add(prefix+"0f"+opcode+"01", sw, tw, signed, MASK, memory=True, fault=True)
    for tw, prefix, sw in ((2, "66", 2), (4, "", 4), (8, "48", 4)):
        for value in values:
            add(prefix+"63c1", sw, tw, True, value)
            add(prefix+"6301", sw, tw, True, value, memory=True)
        add(prefix+"6301", sw, tw, True, MASK, memory=True, fault=True)
    for tw, prefix, sw in ((2, "66", 1), (4, "", 2), (8, "48", 4)):
        for value in values: add(prefix+"98", sw, tw, True, value, src=0)
    # 0x99 sign-high has no explicit operands. Prefix order determines the
    # active width, and only DX/EDX/RDX may change.
    for code, width in (("6699",16),("99",32),("4899",64),("664899",64),
                        ("486699",16),("4099",32),("666699",16)):
        for value in values:
            for flags in (0,0xAD7,MASK):
                request = dict(native_bytes=list(bytes.fromhex(code)), state=dict(
                    registers=[0xABCDEF0123450000+i for i in range(16)], flags=flags,
                    pc=0x1000, xmm0=(1 << 127)+7, fs_base=0, gs_base=0, memory=[]))
                request["state"]["registers"][0] = value
                expected = copy.deepcopy(request["state"])
                high = (1 << width)-1 if value & (1 << (width-1)) else 0
                expected["registers"][2] = ((expected["registers"][2] & ~0xFFFF) | high) if width==16 else high
                expected.update(pc=0x1000+len(request["native_bytes"]),events=[],fault=None,defined_flags=MASK)
                cases.append((request,expected))
    run = subprocess.run([str(ROOT/".lake/build/bin/reference")],
        input="".join(json.dumps(r)+"\n" for r, _ in cases), text=True, stdout=subprocess.PIPE, check=True)
    outputs = [json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs) == len(cases)
    for (request, expected), actual in zip(cases, outputs): assert actual == expected, (request, actual, expected)
    print(f"x86 widening reference: {len(cases)} source/destination widths, byte lanes, aliases, exact reads/faults and accumulator/sign-high cases OK")


def sign_high_encoder():
    # Compare real encoder output with both an integer oracle and the actual
    # x86 CPU. Narrow destination writes must retain the other RDX bytes.
    sys.path.insert(0,str(ROOT.parent/"x86/micro-prog"))
    spec = importlib.util.spec_from_file_location("sign_high_encoder",ROOT.parent/"x86/micro-prog/generate_micro_sim_proofs.py")
    g = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = g
    spec.loader.exec_module(g)
    folder = ROOT/"build/sign-high"
    folder.mkdir(parents=True,exist_ok=True)
    includes = ["-include", str(ROOT/"oracles/arm64_entry_environment_host.h"), "-I"+str(ROOT.parent/"x86/micro-prog"),"-I"+str(ROOT),
        "-I"+str(ROOT.parent/"x86"),"-I"+str(ROOT.parents[1]/"vendor/libbpf/src"),"-I/usr/include/x86_64-linux-gnu"]
    for mnemonic,width in (("cwd",16),("cdq",32),("cqo",64)):
        rows = [("mov",("rax","QWORD PTR [rdi]")),("mov",("rdx","0xabcdef0123456789")),
                (mnemonic,()),("mov",("QWORD PTR [rdi+8]","rdx")),("xor",("eax","eax")),("ret",())]
        body = [g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(rows)]
        name = "sign_high_"+mnemonic
        program = g.render_program(name,body,kind="raw",program_section="xdp")
        path = folder/(name+".c")
        source = program+f'''
int main(void) {{
  unsigned long long seed=0x9182abcd77413301ULL;
  for(unsigned n=0;n<2048;n++) {{
    seed=seed*6364136223846793005ULL+1;
    unsigned long long data[2]={{seed,0}},cpu=0xabcdef0123456789ULL;
    unsigned long long want=(seed & (1ULL<<{width-1})) ? {hex((1<<width)-1)}ULL : 0;
    if({width}==16)want=(0xabcdef0123456789ULL & ~0xffffULL)|want;
    __asm__ volatile("{mnemonic}" : "+d"(cpu) : "a"(seed));
    if(cpu!=want || {name}_x86_sim_xdp(data)!=0 || data[1]!=want)return 1;
  }}
  return 0;
}}
'''
        path.write_text(source)
        subprocess.run(["cc","-O2","-fsanitize=undefined","-fno-sanitize-recover=undefined",*includes,
                        str(path),"-o",str(path.with_suffix(""))],check=True)
        subprocess.run([str(path.with_suffix(""))],check=True)
        path.write_text(program)
        # TRUNC32 uses BPF ALU32 (the w-register constraint), available at v3.
        subprocess.run(["clang-18","-target","bpfel","-mcpu=v3","-O2","-D__TARGET_ARCH_x86",*includes,
                        "-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
    print("x86 sign-high: 6144 actual CPU/encoded-handler results and all three BPF compilations OK")


if __name__ == "__main__":
    main()
    sign_high_encoder()
