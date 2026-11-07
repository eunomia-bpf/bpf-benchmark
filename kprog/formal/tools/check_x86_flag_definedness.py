#!/usr/bin/env python3
"""Reject observable undefined PF/AF/overshift state; admit defined parity uses."""
import importlib.util
from pathlib import Path
import sys
import subprocess

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT.parent / "x86/micro-prog"))
spec = importlib.util.spec_from_file_location("flag_generator", ROOT.parent / "x86/micro-prog/generate_micro_sim_proofs.py")
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)


def main():
    cases = 0

    def check(body, error=None):
        nonlocal cases
        instructions = [g.NativeInsn(i, op + " " + ",".join(args), op, args)
                        for i, (op, args) in enumerate(body)]
        try:
            g.render_program("flag_definedness", instructions)
        except ValueError as exc:
            assert error is not None and error in str(exc), (body, str(exc), error)
        else:
            assert error is None, ("undefined state accepted", body, error)
        cases += 1

    finish = [("mov", ("eax", "2")), ("ret", ())]
    initialize = [("mov", ("eax", "15")), ("mov", ("ebx", "1"))]
    # All newly exposed spellings must reach the real encoder, not just a
    # separate lookup table. Branches fall through and target the same return.
    for suffix in ("o", "no", "p", "np", "pe", "po"):
        for family, args in (("j", ("4",)), ("cmov", ("eax", "ebx")), ("set", ("al",))):
            check(initialize + [("cmp", ("eax", "ebx")), (family + suffix, args)] + finish)
    for op in ("add", "sub", "adc", "sbb", "cmp", "test"):
        prefix = [("mov", ("dx", "WORD PTR [rdi]")), ("cmp", ("rdi", "rdi"))]
        for suffix in ("p", "np"):
            check(prefix + [(op, ("edx", "1")), ("set" + suffix, ("al",))] + finish)
        check(prefix + [(op, ("edx", "1")), ("seto", ("al",))] + finish,
              None if op == "test" else "undefined native ABI flags")
    check([("test", ("rbx", "0")), ("setp", ("al",))] + finish)
    check([("test", ("rbx", "rbx")), ("setp", ("al",))] + finish, "undefined native ABI flags")
    check([("mov", ("dh", "3")), ("add", ("edx", "1")), ("setp", ("al",))] + finish,
          "undefined native ABI flags")
    for op, args in (("andn", ("eax", "eax", "ebx")), ("bzhi", ("eax", "eax", "ebx")),
                     ("imul", ("eax", "ebx")), ("div", ("ebx",))):
        prefix = initialize + [("mov", ("edx", "0")), (op, args)]
        check(prefix + [("setp", ("al",))] + finish, "undefined native ABI flags")
        check(prefix + [("cmp", ("eax", "eax")), ("setp", ("al",))] + finish)
    for op, args in (("xor", ("eax", "eax")), ("and", ("eax", "ebx")), ("or", ("eax", "ebx")),
                     ("neg", ("eax",)), ("inc", ("eax",)), ("dec", ("eax",)), ("popcnt", ("eax", "ebx"))):
        check(initialize + [(op, args), ("setp", ("al",))] + finish)
    for op in ("shl", "shr", "sar"):
        check(initialize + [(op, ("eax", "1")), ("setp", ("al",))] + finish)
        check(initialize + [(op, ("eax", "0")), ("setp", ("al",))] + finish, "undefined native ABI flags")
        check(initialize + [("cmp", ("eax", "ebx")), (op, ("eax", "0")), ("setp", ("al",))] + finish)
    for op in ("rol",):
        check(initialize + [("cmp", ("eax", "ebx")), (op, ("eax", "1")), ("setp", ("al",))] + finish)
        check(initialize + [(op, ("eax", "1")), ("setp", ("al",))] + finish, "undefined native ABI flags")
    for op in ("shld", "shrd"):
        for count in ("17", "31", "cl"):
            prefix = initialize + [("mov", ("cl", "BYTE PTR [rdi]")), (op, ("ax", "bx", count))]
            check(prefix + [("setp", ("al",))] + finish, "undefined native ABI flags")
            check(prefix + [("movzx", ("eax", "ax")), ("ret", ())], "undefined native ABI register eax")
            check(prefix + finish)
        check(initialize + [(op, ("ax", "bx", "16")), ("setp", ("al",))] + finish)
    low = [("mov", ("dx", "WORD PTR [rdi]"))]
    for op, immediate in (("and", "0xffff"), ("or", "0xffff0000")):
        for register in (False, True):
            prefix = low + ([("mov", ("ecx", immediate))] if register else [])
            check(prefix + [(op, ("edx", "ecx" if register else immediate)),
                            ("mov", ("eax", "edx")), ("ret", ())])
    for op, immediate in (("and", "0x1ffff"), ("or", "0xfffe0000"), ("xor", "1")):
        prefix = low + [(op, ("edx", immediate))]
        check(prefix + [("mov", ("eax", "edx")), ("ret", ())], "undefined native ABI register eax")
        check(prefix + [("movzx", ("eax", "dx")), ("ret", ())])
    check([("and", ("edx", "0xffffff00")), ("setp", ("al",))] + finish)
    check([("and", ("edx", "0xffffff00")), ("sete", ("al",))] + finish, "undefined native ABI flags")
    for op, immediate in (("and", "0"), ("or", "0xffffffff"), ("xor", "rax")):
        check([(op, ("rax", immediate)), ("ret", ())])
    # Native 64-bit logical immediates sign-extend from32; treating the raw
    # positive spelling as zero-extended would invent a known sign flag.
    check([("test", ("rbx", "0xffffffff")), ("sets", ("al",))] + finish, "undefined native ABI flags")
    check([("test", ("rbx", "0x80000000")), ("setp", ("al",))] + finish)
    check([("test", ("rbx", "0x80000000")), ("sets", ("al",))] + finish, "undefined native ABI flags")
    for op in ("inc", "dec", "neg", "not"):
        prefix = low + [(op, ("edx",))]
        check(prefix + [("movzx", ("eax", "dx")), ("ret", ())])
        check(prefix + [("mov", ("eax", "edx")), ("ret", ())], "undefined native ABI register eax")
        if op != "not":
            check(prefix + [("setp", ("al",))] + finish)
            check(prefix + [("sets", ("al",))] + finish, "undefined native ABI flags")
    for op in ("inc", "dec"):
        check(initialize + [(op, ("eax",)), ("setb", ("al",))] + finish, "undefined native ABI flags")
        check(initialize + [("cmp", ("eax", "ebx")), (op, ("eax",)), ("setb", ("al",))] + finish)
    check(initialize + [("not", ("eax",)), ("setp", ("al",))] + finish, "undefined native ABI flags")
    check(initialize + [("cmp", ("eax", "ebx")), ("not", ("eax",)), ("setp", ("al",))] + finish)
    for op in ("inc", "dec"):
        inverse = "dec" if op == "inc" else "inc"
        check([(op, ("rsp",)), (inverse, ("rsp",))] + finish)
    for op, initial, observe in (("cbw", ("al", "BYTE PTR [rdi]"), ("movzx", ("eax", "ax"))),
                                 ("cwde", ("ax", "WORD PTR [rdi]"), ("mov", ("eax", "eax"))),
                                 ("cdqe", ("ax", "WORD PTR [rdi]"), ("movzx", ("eax", "ax")))):
        check([("mov", initial), (op, ()), observe, ("ret", ())])
        check([(op, ()), ("ret", ())], "undefined native ABI register")
    check([("mov", ("ax", "WORD PTR [rdi]")),
           ("movsx", ("eax", "ah")), ("ret", ())])
    print(f"x86 flag definedness: {cases} encoder/ABI condition and undefined-result cases OK")
    check_compiled_counts()
    check_compiled_movx()


def check_compiled_counts():
    """Compile actual encoder output: a textual macro typo must not pass ABI checks."""
    folder = ROOT / "build/x86_flag_conditions"
    folder.mkdir(parents=True, exist_ok=True)
    source = ['#define X86_SIM_USE_STATE_STRUCT', '#include "../x86/x86_sim_local_bpf.h"',
              '#include "oracles/x86_no_helpers_host.h"']
    for op in ("shld", "shrd"):
        for dst in ("rax", "rcx"):
            insn = g.NativeInsn(0, f"{op} {dst},rbx,cl", op, (dst, "rbx", "cl"))
            encoded = g.encode(insn, {})
            source += [f'static void {op}_{dst}(struct x86_sim_state *state, unsigned width) {{',
                'X86_SIM_L_BIND_COMMON_STATE(state);',
                f'X86_SIM_L_EXEC({encoded.op},{encoded.dst},{encoded.src},width,{encoded.aux},{encoded.imm});', '}']
    source.append(r'''
#include <stdio.h>
int main(void) {
  unsigned cases = 0;
  for (unsigned width = 2; width <= 8; width *= 2)
  for (unsigned count = 0; count < 256; count++)
  for (unsigned right = 0; right < 2; right++)
  for (unsigned alias = 0; alias < 2; alias++) {
    struct x86_sim_state state = {0};
    state.rax.ptr = (void *)0xaabbccdd12348001UL;
    state.rbx.ptr = (void *)0x112233448765abcdUL;
    state.rcx.ptr = (void *)(0x5a5a5a5a7ff00000UL | count);
    state.cf = state.pf = state.af = state.of = 1;
    unsigned bits = width * 8, c = count & (bits == 64 ? 63 : 31);
    unsigned long long old = (unsigned long)(alias ? state.rcx.ptr : state.rax.ptr);
    unsigned long long mask = ~0ULL >> (64 - bits), a = old & mask;
    unsigned long long b = (unsigned long)state.rbx.ptr & mask;
    unsigned __int128 pair = right ? ((unsigned __int128)b << bits) | a : ((unsigned __int128)a << bits) | b;
    unsigned long long r = !c ? a : right ? (unsigned long long)(pair >> c) & mask :
        (unsigned long long)((pair << c) >> bits) & mask;
    if (right) { if (alias) shrd_rcx(&state,width); else shrd_rax(&state,width); }
    else { if (alias) shld_rcx(&state,width); else shld_rax(&state,width); }
    unsigned long long actual = (unsigned long)(alias ? state.rcx.ptr : state.rax.ptr);
    /* At16-bit counts17..31 the entire result/status is ISA-undefined;
     * the unmodified upper register bits remain an architectural obligation. */
    if (c > bits) { if ((actual & ~mask) != (old & ~mask)) return 1; }
    else {
      unsigned long long want = width == 4 ? r : (old & ~mask) | r;
      if (actual != want) return 1;
      if (!c) { if (!state.cf || !state.pf || !state.af || !state.of) return 1; }
      else {
        unsigned parity = 1;
        for (unsigned bit = 0; bit < 8; bit++) parity ^= (r >> bit) & 1;
        unsigned cf = right ? (a >> (c-1)) & 1 : (a >> (bits-c)) & 1;
        if (state.cf != cf || state.pf != parity || state.zf != (r==0) || state.sf != (r >> (bits-1))) return 1;
        if (c == 1 && state.of != ((a ^ r) >> (bits-1))) return 1;
      }
    }
    if ((unsigned long)state.rbx.ptr != 0x112233448765abcdUL) return 1;
    cases++;
  }
  printf("x86 encoded CL double shifts: %u width/count/destination-alias cases OK\n",cases);
  return 0;
}
''')
    path = folder / "counts.c"
    path.write_text("\n".join(source))
    subprocess.run(["cc", "-O2", "-fsanitize=undefined", "-fno-sanitize-recover=undefined",
        "-I" + str(ROOT), "-I" + str(ROOT.parent / "x86"),
        "-I" + str(ROOT.parents[1] / "vendor/libbpf/src"), str(path), "-o", str(folder / "counts")], check=True)
    subprocess.run([str(folder / "counts")], check=True)
    for op in ("shld", "shrd"):
        body = [("mov", ("ecx", "DWORD PTR [rdi]")), ("mov", ("ebx", "1")),
                ("cmp", ("ecx", "ebx")), (op, ("ecx", "ebx", "cl")), ("cmovp", ("ecx", "ebx")),
                ("setnp", ("al",)), ("jp", ("7",)), ("mov", ("eax", "2")), ("ret", ())]
        insns = [g.NativeInsn(i, mnemonic + " " + ",".join(args), mnemonic, args)
                 for i, (mnemonic, args) in enumerate(body)]
        path = folder / f"{op}.bpf.c"
        path.write_text(g.render_program(op + "_conditions", insns))
        subprocess.run(["clang-18", "-g", "-O2", "-target", "bpf", "-D__TARGET_ARCH_x86",
            "-I" + str(ROOT.parent / "x86/micro-prog"),
            "-I" + str(ROOT.parents[1] / "vendor/libbpf/src"), "-I/usr/include/x86_64-linux-gnu",
            "-c", str(path), "-o", str(folder / f"{op}.bpf.o")], check=True)
    print("x86 generated CL/parity handler BPF compiles: both directions OK")


def check_compiled_movx():
    folder = ROOT / "build/movx-encoding"
    folder.mkdir(parents=True, exist_ok=True)
    cases = []
    for signed in (False, True):
        for width in (16,32):
            for base, high, destination in (("rax","ah","ax"), ("rcx","ch","cx"),
                                           ("rdx","dh","dx"), ("rbx","bh","bx")):
                dst = "e"+destination if width == 32 else destination
                body = [("mov", (base, "0xABCDEF012345805A")),
                        ("movsx" if signed else "movzx", (dst,high))]
                if width == 16: body.append(("movzx", ("eax",dst)))
                elif dst != "eax": body.append(("mov", ("eax",dst)))
                body.append(("ret", ()))
                cases.append((body, (0xFF80 if width == 16 else 0xFFFFFF80) if signed else 0x80))
    for op, value, tail, expected in (("cbw","0x80",[("movzx",("eax","ax"))],0xFF80),
        ("cwde","0x8000",[],0xFFFF8000), ("cdqe","0x80000000",[("shr",("rax","32"))],0xFFFFFFFF)):
        cases.append(([("mov",("rax",value)),(op,())]+tail+[("ret",())],expected))
    includes = ["-I"+str(ROOT.parent/"x86/micro-prog"), "-I"+str(ROOT),
                "-I"+str(ROOT.parents[1]/"vendor/libbpf/src"), "-I/usr/include/x86_64-linux-gnu"]
    for n,(body,expected) in enumerate(cases):
        instructions = [g.NativeInsn(i,op+" "+",".join(args),op,args) for i,(op,args) in enumerate(body)]
        name = f"movx_encoding_{n}"
        program = g.render_program(name,instructions)
        path = folder/f"case-{n}.c"
        path.write_text(program+f'\nint main(void) {{struct xdp_md ctx={{0}};return (unsigned){name}_x86_sim_xdp(&ctx)!={expected}U;}}\n')
        subprocess.run(["cc","-O2","-fsanitize=undefined","-fno-sanitize-recover=undefined",*includes,
                        str(path),"-o",str(path.with_suffix(""))],check=True)
        subprocess.run([str(path.with_suffix(""))],check=True)
        path.write_text(program)
        subprocess.run(["clang-18","-target","bpfel","-O2","-D__TARGET_ARCH_x86",*includes,
                        "-c",str(path),"-o",str(path.with_suffix(".o"))],check=True)
    for op,args in (("movsx",("rax","ah")),("movzx",("r8d","bh")),("movzx",("ax","ebx")),
                    ("movsx",("al","bl")),("movsxd",("eax","bx"))):
        try:
            g.encode(g.NativeInsn(0,op+" "+",".join(args),op,args),{})
        except ValueError:
            continue
        raise AssertionError(("invalid width/REX widening move accepted",op,args))
    print(f"x86 encoded widening: {len(cases)} actual rendered host/BPF programs pass; five impossible widths/REX pairs rejected")


if __name__ == "__main__":
    main()
