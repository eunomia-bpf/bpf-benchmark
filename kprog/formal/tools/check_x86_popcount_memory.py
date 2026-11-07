#!/usr/bin/env python3
"""Exercise actual encoded POPCNT memory steps, aliases, displacements and BPF."""
import importlib.util
from pathlib import Path
import subprocess
import sys

from check_x86_memory_widths import accesses, instructions_by_function

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT.parent / "x86/micro-prog"))
spec = importlib.util.spec_from_file_location("popcount_encoder", ROOT.parent / "x86/micro-prog/generate_micro_sim_proofs.py")
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)


def main():
    folder = ROOT / "build/popcount-memory"
    folder.mkdir(parents=True, exist_ok=True)
    source = ['#define X86_SIM_USE_STATE_STRUCT', '#define X86_SIM_ENABLE_STACK 1',
        '#include "../x86/x86_sim_local_bpf.h"', '#include "oracles/x86_no_helpers_host.h"',
        '#include <string.h>', 'static __u8 datum[64];']
    variants = [
        ("rdi+17", "rax", 0, False), ("rdi-3", "rax", 20, False),
        ("rdi+rcx*4-3", "rax", 12, False), ("rdi+17", "rdi", 0, False),
        ("rdi+rcx*4-3", "rcx", 12, False), ("rsp-15", "rax", 0, True),
        ("rip+0", "rax", 0, False)]
    for width, qualifier in ((2, "WORD"), (4, "DWORD"), (8, "QWORD")):
        for n, (address, destination, _, _) in enumerate(variants):
            dst = {"rax": ("ax", "eax", "rax"), "rdi": ("di", "edi", "rdi"),
                   "rcx": ("cx", "ecx", "rcx")}[destination][{2: 0, 4: 1, 8: 2}[width]]
            insn = g.NativeInsn(0, f"popcnt {dst}, {qualifier} PTR [{address}]", "popcnt", (dst, f"{qualifier} PTR [{address}]"),
                reloc_symbol="datum" if n == 6 else None, reloc_type="R_X86_64_PC32" if n == 6 else None,
                symbol_offset=17 if n == 6 else 0)
            encoded = g.encode(insn, {"datum": "datum"})
            assert encoded.op == "X86_OP_POPCNT_MEM", encoded
            source += [f'static void run_{width}_{n}(struct x86_sim_state *state) {{',
                'X86_SIM_L_BIND_COMMON_STATE(state);',
                f'X86_SIM_L_EXEC({encoded.op},{encoded.dst},{encoded.src},{encoded.flags},{encoded.aux},{encoded.imm});', '}']
    source += ['int main(void) { unsigned cases = 0;',
        'for (unsigned flags=0; flags<64; flags++) for (unsigned pattern=0; pattern<66; pattern++) {',
        '__u64 value = pattern < 64 ? 1ULL << pattern : pattern == 64 ? 0 : ~0ULL;']
    for width in (2, 4, 8):
        for n, (_, dst, offset, stack) in enumerate(variants):
            source += ['{ struct x86_sim_state state = {0};',
                'memset(datum,0xa5,sizeof datum);',
                f'for(unsigned i=0;i<{width};i++) datum[17+i]=value>>(8*i);',
                '__u8 before[64]; memcpy(before,datum,sizeof datum);',
                'state.rax.ptr=(void *)0xaabbccdd11223344UL;',
                f'state.rdi.ptr=datum+{offset}; state.rcx.ptr=(void *)2UL; state.rsp.ptr=(void *)(unsigned long)-32L;',
                'state.xmm0_lo=0x123456789UL;state.xmm0_hi=0x987654321UL;',
                'state.cf=flags&1;state.pf=(flags>>1)&1;state.af=(flags>>2)&1;',
                'state.zf=(flags>>3)&1;state.sf=(flags>>4)&1;state.of=(flags>>5)&1;']
            if stack:
                source += [f'for(unsigned i=0;i<{width};i++) state.stack_mem.b[KPROG_X86_STACK_INDEX(-47,X86_SIM_STACK_BYTES)+i]=datum[17+i];']
            source += ['struct x86_sim_state expected=state;',
                f'__u64 narrowed=value & (~0ULL>>(64-{width*8})), count=0;',
                f'for(unsigned bit=0;bit<{width*8};bit++) count+=(narrowed>>bit)&1;',
                f'__u64 old=(unsigned long)state.{dst}.ptr;',
                f'expected.{dst}.ptr=(void *)(unsigned long)'+('((old & ~0xffffULL)|count);' if width==2 else 'count;'),
                f'expected.{dst}_tag=X86_SIM_TAG_SCALAR;',
                'expected.cf=expected.pf=expected.af=expected.sf=expected.of=0;expected.zf=narrowed==0;',
                f'run_{width}_{n}(&state);',
                f'if(memcmp(&state,&expected,sizeof state)||memcmp(before,datum,sizeof datum)) {{ fprintf(stderr,"POPCNT memory mismatch width={width} variant={n} flags=%u pattern=%u\\n",flags,pattern);return 1;}}',
                '(void)old;cases++;}']
    source += ['} printf("x86 encoded POPCNT memory: %u full-state cases OK\\n",cases); return 0; }']
    path = folder / "memory.c"
    path.write_text("\n".join(source))
    includes = ["-include", str(ROOT/"oracles/arm64_entry_environment_host.h"), "-I"+str(ROOT.parent / "x86/micro-prog"), "-I"+str(ROOT), "-I"+str(ROOT.parent / "x86"), "-I"+str(ROOT.parents[1] / "vendor/libbpf/src")]
    for compiler in ("cc", "clang-18"):
        obj = folder / (compiler + ".o")
        exe = folder / compiler
        subprocess.run([compiler, "-O2", "-fsanitize=undefined", "-fno-sanitize-recover=undefined", *includes,
                        "-c", str(path), "-o", str(obj)], check=True)
        subprocess.run(["cc", "-fsanitize=undefined", str(obj), "-o", str(exe)], check=True)
        subprocess.run([str(exe)], check=True)
    for args in (("al", "bl"), ("eax", "bx"), ("ax", "DWORD PTR [rdi]"), ("eax",), ("eax", "ebx", "ecx")):
        try:
            g.encode(g.NativeInsn(0, "popcnt " + ",".join(args), "popcnt", args), {})
        except ValueError:
            pass
        else:
            raise AssertionError(("malformed POPCNT accepted", args))
    for width, dst, ptr in ((2, "ax", "WORD"), (4, "eax", "DWORD"), (8, "rax", "QWORD")):
        body = [g.NativeInsn(0, "popcnt memory", "popcnt", (dst, f"{ptr} PTR [rdi]"))]
        if width == 2: body.append(g.NativeInsn(1, "movzx eax,ax", "movzx", ("eax", "ax")))
        body.append(g.NativeInsn(2, "ret", "ret", ()))
        c = folder / f"bpf-{width}.c"
        c.write_text(g.render_program(f"popcount_memory_{width}", body))
        subprocess.run(["clang-18", "-target", "bpfel", "-O2", "-D__TARGET_ARCH_x86", *includes,
            "-I/usr/include/x86_64-linux-gnu", "-c", str(c), "-o", str(c.with_suffix(".o"))], check=True)
        encoded = g.encode(body[0], {})
        probe = folder / f"probe-{width}.c"
        probe.write_text('#include "x86_sim_local_bpf.h"\n__u64 probe(void *pointer) {\n' +
            'X86_SIM_ENTRY_RAW(pointer);\n' +
            f'X86_SIM_L_EXEC({encoded.op},{encoded.dst},{encoded.src},{encoded.flags},{encoded.aux},{encoded.imm});\n' +
            'return X86_SIM_L_READ_REG(X86_RAX); }\n')
        subprocess.run(["clang-18", "-target", "bpfel", "-O2", "-D__TARGET_ARCH_x86", *includes,
            "-I/usr/include/x86_64-linux-gnu", "-c", str(probe), "-o", str(probe.with_suffix(".o"))], check=True)
        assembly = subprocess.check_output(["llvm-objdump-18", "-d", str(probe.with_suffix(".o"))], text=True)
        probe.with_suffix(".asm").write_text(assembly)
        functions = instructions_by_function(assembly)
        assert len(functions) == 1, assembly
        instructions = next(iter(functions.values()))
        assert accesses(instructions) == [("read", 0, width)], assembly
    readonly = g.NativeInsn(0, "popcnt rax,QWORD PTR [rip+0]", "popcnt", ("rax", "QWORD PTR [rip+0]"),
        reloc_symbol="datum", reloc_type="R_X86_64_PC32", symbol_offset=17)
    c = folder / "readonly.c"
    c.write_text(g.render_program("popcount_readonly", [readonly, g.NativeInsn(1, "ret", "ret", ())],
        rodata16={"datum": bytes(range(64))}))
    subprocess.run(["clang-18", "-target", "bpfel", "-O2", "-D__TARGET_ARCH_x86", *includes,
        "-I/usr/include/x86_64-linux-gnu", "-c", str(c), "-o", str(c.with_suffix(".o"))], check=True)
    relocations = subprocess.check_output(["llvm-readelf-18", "-r", str(c.with_suffix(".o"))], text=True)
    c.with_suffix(".relocs").write_text(relocations)
    assert ".rodata.native.0" in relocations, relocations
    print("x86 POPCNT memory: five malformed encodings rejected; three raw BPF steps retain one exact-width read; four rendered programs compile including readonly relocation")


if __name__ == "__main__":
    main()
