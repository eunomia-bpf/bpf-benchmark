#!/usr/bin/env python3
"""Assemble actual instructions, decode with the production encoder, emit paired CPU/simulator functions."""
import argparse
import importlib.util
import json
from pathlib import Path
import subprocess
import shutil
from tcb import includes, imports
import sys

ROOT = Path(__file__).resolve().parents[2]


def x86_forms(cc_aux):
    forms = ["push rbx", "pop rax", "push bx", "pop ax", "nop", "cbw", "cwde", "cdqe", "cwd", "cdq", "cqo", "movups xmm0, XMMWORD PTR [rdi]", "movups XMMWORD PTR [rdi], xmm0"]
    forms += ["mov rax, rsp", "mov eax, esp", "lea rax, [rsp+16]", "cmp rsp, 0",
              "mov rsp, rax", "mov esp, eax", "lea rsp, [rsp+16]", "add rsp, 16",
              "push rsp", "pop rsp", "push sp", "pop sp"]
    forms += [f"push {n}" for n in [-2147483648, -128, -1, 0, 1, 127, 128, 0x12345678]]
    forms += ["pushw -7", "push QWORD PTR [rdi+8]", "push WORD PTR [rdi+8]",
              "pop QWORD PTR [rdi+8]", "pop WORD PTR [rdi+8]",
              "push QWORD PTR [rsp-16]", "pop QWORD PTR [rsp-16]"]
    # Active REX.W overrides 66; a later 66 invalidates the preceding REX.
    forms += [".byte "+", ".join(f"0x{x:02x}" for x in sequence)
              for opcode in [[0x53], [0xff,0xf3], [0x58], [0x8f,0xc0]]
              for prefix in [[0x66,0x48], [0x48,0x66]]
              for sequence in [prefix+opcode]]
    for width, a, b, mem in [(8, "al", "bl", "BYTE"), (16, "ax", "bx", "WORD"), (32, "eax", "ebx", "DWORD"), (64, "rax", "rbx", "QWORD"), (8, "ah", "bh", "BYTE")]:
        m = f"{mem} PTR [rdi+8]"
        forms += [f"mov {a}, {b}", f"mov {a}, 0x7f", f"mov {m}, {a}"]
        if a != "ah":
            forms += [f"mov {a}, {m}", f"mov {m}, 0x7f"]
        for op in ["add", "adc", "sub", "sbb", "cmp", "test"]:
            forms += [f"{op} {a}, {b}", f"{op} {a}, 0x7f"]
            if a != "ah":
                forms += [f"{op} {m}, {a}", f"{op} {m}, 0x7f"]
                if op != "test":
                    forms += [f"{op} {a}, {m}"]
        for op in ["and", "or", "xor"]:
            if a == "ah":
                continue  # production encoder explicitly rejects these high-byte forms
            forms += [f"{op} {a}, {b}", f"{op} {a}, 0x7f", f"{op} {a}, {m}", f"{op} {m}, {a}", f"{op} {m}, 0x7f"]
        for op in ["inc", "dec", "neg", "not"]:
            forms += [f"{op} {a}"]
            if a != "ah":
                forms += [f"{op} {m}"]
        if a == "ah":
            continue
        forms += [f"xchg {a}, {b}"]
        for op in ["shl", "shr", "sar", "rol", "ror"]:
            forms += [f"{op} {a}, {n}" for n in [0, 1, 7, 8, 15, 16, 31, 32, 63, 64, 255]]
            forms += [f"{op} {a}, cl"]
        if width >= 16:
            forms += [f"imul {a}, {b}", f"imul {a}, {m}", f"imul {a}, {b}, -7", f"imul {a}, {m}, -7", f"popcnt {a}, {b}", f"popcnt {a}, {m}", f"div {b}", f"bt {a}, {b}", f"bt {a}, 7", f"bt {m}, 7", f"movbe {a}, {m}", f"movbe {m}, {a}"]
            for op in ["shld", "shrd"]:
                forms += [f"{op} {a}, {b}, {n}" for n in [0, 1, 7, 15]]
        if width >= 32:
            c = "ecx" if width == 32 else "rcx"
            forms += [f"lea {a}, [rdi+rbx*4-7]", f"bswap {a}", f"andn {a}, {b}, {c}", f"andn {a}, {b}, {m}", f"bzhi {a}, {b}, {c}", f"bzhi {a}, {m}, {c}", f"mulx {a}, {b}, {c}"]
            for op in ["shlx", "shrx", "sarx", "rorx"]:
                count = "7" if op == "rorx" else c
                forms += [f"{op} {a}, {b}, {count}", f"{op} {a}, {m}, {count}"]
    for op in ["rol", "ror"]:
        for reg in ["ah", "ch", "dh", "bh"]:
            forms += [f"{op} {reg}, {n}" for n in [0,1,7,8,15,16,31,32,63,64,255]]
            forms += [f"{op} {reg}, cl"]
    for mem in ["BYTE", "WORD", "DWORD", "QWORD"]:
        forms += [f"ror {mem} PTR [rdi+8], {n}" for n in [0,1,7,8,15,16,31,32,63,64,255]]
        forms += [f"ror {mem} PTR [rdi+8], cl"]
    for dst in ["ax", "eax", "rax"]:
        for src, mem in [("bl", "BYTE"), ("bx", "WORD")]:
            if dst == "ax" and src == "bx":
                continue
            for op in ["movzx", "movsx"]:
                forms += [f"{op} {dst}, {src}", f"{op} {dst}, {mem} PTR [rdi+8]"]
    forms += ["movsxd rax, ebx", "movsxd rax, DWORD PTR [rdi+8]"]
    # LEA computes address bits without dereferencing: vary writeback width,
    # SIB scale/base, address-size override, displacement and register aliases.
    forms += [f"lea {dst}, {address}"
              for dst in ["ax", "eax", "rax", "r8w", "r8d", "r8"]
              for address in ["[rbx]", "[rbx+127]", "[rbx-128]",
                              "[rbx+rcx*2-7]", "[r8+r9*4+2147483647]",
                              "[r8+r9*8-2147483648]", "[rcx*8+127]",
                              "[0x12345678]", "[ebx+ecx*4-7]",
                              "[r8d+r9d*8+127]"]]
    forms += ["lea rbx, [rbx+rcx*8]", "lea rcx, [rbx+rcx*8]",
              "lea r9, [r8+r9*2-7]"]
    forms += [f"lea {dst}, {segment}:[rbx+rcx*2-7]"
              for dst in ["ax", "eax", "rax"] for segment in ["fs", "gs"]]
    forms += [f"mov {reg}, BYTE PTR {address}"
              for reg in ["ah", "ch", "dh", "bh"]
              for address in ["[rdi+8]", "[rsi+16]", "[rsp-16]"]]
    for mnemonic in (name for name in cc_aux if name.startswith("set")):
        forms += [f"{mnemonic} al", f"{mnemonic} ah", f"{mnemonic} BYTE PTR [rdi+8]"]
    for mnemonic in (name for name in cc_aux if name.startswith("cmov")):
        for a, b, m in [("ax", "bx", "WORD"), ("eax", "ebx", "DWORD"), ("rax", "rbx", "QWORD")]:
            forms += [f"{mnemonic} {a}, {b}", f"{mnemonic} {a}, {m} PTR [rdi+8]"]
    # Exercise the production same-register XOR fast path at every native lane.
    for registers in [
        ("al", "cl", "dl", "bl", "spl", "bpl", "sil", "dil"),
        ("ax", "cx", "dx", "bx", "sp", "bp", "si", "di"),
        ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"),
        ("rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"),
    ]:
        forms += [f"xor {reg}, {reg}" for reg in registers]
    forms += [f"xor r{reg}{suffix}, r{reg}{suffix}"
              for reg in range(8, 16) for suffix in ("b", "w", "d", "")]
    return list(dict.fromkeys(forms))


def arm64_forms():
    forms = ["nop"]
    for width in ["w", "x"]:
        a, b, c, d = [f"{width}{i}" for i in range(4)]
        for op in ["add", "sub", "and", "bic", "eor", "orr", "orn", "adds", "subs", "ands", "bics"]:
            forms += [f"{op} {a}, {b}, {c}", f"{op} {a}, {b}, {c}, lsl #3"]
            if op in ["add", "sub", "adds", "subs"]:
                forms += [f"{op} {a}, {b}, #127"]
        for op in ["cmp", "cmn", "tst"]:
            forms += [f"{op} {b}, {c}", f"{op} {b}, {c}, lsl #3"]
        for op in ["cmp", "cmn"]:
            forms += [f"{op} {b}, #{n}" for n in [0, 127, 4095]]
            forms += [f"{op} {b}, #1, lsl #12"]
        for modifier in ["", ", lsr #7", ", asr #31", ", ror #7"]:
            forms += [f"bics {width}zr, {b}, {c}{modifier}"]
        bits = 32 if width == "w" else 64
        masks = [1, 0xff, (1 << (bits - 1)), (1 << (bits // 2)) - 1,
                 int("00ff" * (bits // 16), 16), int("aa" * (bits // 8), 16)]
        for immediate in masks:
            for op in ["and", "orr", "eor", "ands"]:
                forms += [f"{op} {a}, {source}, #{immediate:#x}"
                          for source in [b, a, width + "zr"]]
                if op != "ands":
                    forms += [f"{op} {'wsp' if width == 'w' else 'sp'}, {b}, #{immediate:#x}"]
            forms += [f"tst {source}, #{immediate:#x}" for source in [b, width + "zr"]]
        forms += [f"mov {a}, {b}", f"mov {a}, #127", f"movk {a}, #0xdead, lsl #16"]
        stack_register = "wsp" if width == "w" else "sp"
        forms += [f"mov {a}, {stack_register}", f"mov {stack_register}, {a}"]
        for op in ["mvn", "neg", "rev", "rev16", "sxtb", "sxth"]:
            forms += [f"{op} {a}, {'w1' if op in ['sxtb', 'sxth'] else b}"]
        for op in ["mvn", "neg"]:
            for modifier in (["lsl", "lsr", "asr", "ror"] if op=="mvn" else ["lsl", "lsr", "asr"]):
                for amount in [0,1,31 if width=="w" else 63]:
                    forms += [f"{op} {a}, {b}, {modifier} #{amount}"]
        for op in ["mul", "udiv"]:
            forms += [f"{op} {a}, {b}, {c}"]
        for op in ["madd", "msub"]:
            forms += [f"{op} {a}, {b}, {c}, {d}"]
        for op in ["lsl", "lsr", "asr", "ror"]:
            forms += [f"{op} {a}, {b}, {c}"]
            forms += [f"{op} {a}, {b}, #{n}" for n in [0, 1, 7, 31]]
        forms += [f"extr {a}, {b}, {c}, #7"]
        for op in ["ubfx", "sbfx", "ubfiz", "bfxil", "bfi"]:
            forms += [f"{op} {a}, {b}, #7, #13"]
        for cc in ["eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"]:
            for op in ["csel", "csinc", "csinv", "csneg"]:
                forms += [f"{op} {a}, {b}, {c}, {cc}"]
            if cc not in ["al", "nv"]:
                for op in ["cinc", "cinv", "cneg"]:
                    forms += [f"{op} {a}, {b}, {cc}"]
                forms += [f"cset {a}, {cc}", f"csetm {a}, {cc}"]
            forms += [f"ccmp {b}, {c}, #5, {cc}", f"ccmp {b}, #7, #10, {cc}"]
        for op in ["ldr", "str", "ldur", "stur"]:
            forms += [f"{op} {a}, [x4, #8]"]
        for op in ["ldr", "str"]:
            forms += [f"{op} {a}, [x4, #8]!", f"{op} {a}, [x4], #8", f"{op} {a}, [x4, x5, lsl #{2 if width == 'w' else 3}]"]
        for op in ["ldrb", "ldrh", "strb", "strh"]:
            forms += [f"{op} w0, [x4, #8]"]
        for op in ["ldrsb", "ldrsh"]:
            forms += [f"{op} {a}, [x4, #8]"]
    forms += ["sxtw x0, w1", "umulh x0, x1, x2", "umull x0, w1, w2", "umaddl x0, w1, w2, x3", "smaddl x0, w1, w2, x3", "ldrsw x0, [x4, #8]", "ldp x0, x1, [x4, #8]", "stp x0, x1, [x4, #8]", "fmov d0, x0", "fmov x0, d0", "fmov s0, w0", "fmov w0, s0", "cnt v0.8b, v0.8b", "cnt v0.16b, v0.16b", "uaddlv h0, v0.8b", "uaddlv h0, v0.16b", "ldr q0, [x4, #16]", "str q0, [x4, #16]"]
    for op in ["ldr", "str", "ldur", "stur"]:
        forms += [f"{op} d0, [x4, #8]"]
    for op in ["ldr", "str"]:
        forms += [f"{op} d0, [x4, #8]!", f"{op} d0, [x4], #8",
                  f"{op} d0, [x4, x5, lsl #3]"]
    forms += ["ldur q0, [x4, #16]", "stur q0, [x4, #16]"]
    return list(dict.fromkeys(forms))


def native_wrapper(arch, index, instruction, stack_kind=None, stack_bytes=0):
    name = f"native_{index}"
    lines = [f".global {name}", f".type {name}, %function", f"{name}:"]
    if arch == "x86":
        regs = ["rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"] + [f"r{i}" for i in range(8, 16)]
        lines += [f"push {r}" for r in ["rbx", "rbp", "r12", "r13", "r14", "r15"]]
        lines += ["push rdi", "mov r15, rdi"]
        for lane in range(4):
            lines += [f"movdqu xmm{lane+1}, [r15+{280+lane*16}]", f"movdqu [rsp-{64-lane*16}], xmm{lane+1}"]
        lines += ["push QWORD PTR [r15+256]", "popfq", "movdqu [rsp-16], xmm4", "movdqu xmm0, [r15+264]"]
        lines += [f"mov {r}, [r15+{i*8}]" for i, r in enumerate(regs) if r not in ["rsp", "r15"]]
        before = -stack_bytes if stack_kind == "X86_OP_POP" else 0
        lines += ["mov r15, [r15+120]", "mov QWORD PTR [rip+native_stack_base], rsp"]
        if before:
            lines += [f"lea rsp, [rsp{before:+d}]"]
        lines += [f".global native_pc_{index}", f"native_pc_{index}:", instruction, f".global native_next_{index}", f"native_next_{index}:"]
        lines += ["movq xmm5, rsp", "mov rsp, QWORD PTR [rip+native_stack_base]"]
        lines += [f"movdqu xmm{lane+1}, [rsp-{64-lane*16}]" for lane in range(4)]
        lines += ["push r15", "pushfq", "push rax", "mov rax, [rsp+24]"]
        lines += [f"movdqu [rax+{280+lane*16}], xmm{lane+1}" for lane in range(4)]
        lines += [f"mov [rax+{i*8}], {r}" for i, r in enumerate(regs) if r not in ["rsp", "rax", "r15"]]
        lines += ["movq rdx, xmm5", "sub rdx, QWORD PTR [rip+native_stack_base]", "mov [rax+32], rdx",
                  "mov rdx, [rsp]", "mov [rax], rdx", "mov rdx, [rsp+8]", "mov [rax+256], rdx", "mov rdx, [rsp+16]", "mov [rax+120], rdx", "movdqu [rax+264], xmm0", "add rsp, 24", "pop rdi"]
        lines += [f"pop {r}" for r in ["r15", "r14", "r13", "r12", "rbp", "rbx"]]
        lines += ["ret"]
    else:
        lines += ["sub sp, sp, #128"]
        lines += [f"stp x{i}, x{i+1}, [sp, #{(i-19)*8}]" for i in range(19, 31, 2)]
        lines += ["str x0, [sp, #96]", "mov x30, x0", "ldr x1, [x30, #256]", "msr nzcv, x1", "add x1, x30, #264", "ldr q0, [x1]"]
        lines += ["adrp x1, native_stack_base", "mov x2, sp", "str x2, [x1, :lo12:native_stack_base]"]
        lines += [f"ldr x{i}, [x30, #{i*8}]" for i in range(30)]
        lines += ["ldr x30, [x30, #240]", f".global native_pc_{index}", f"native_pc_{index}:", instruction, f".global native_next_{index}", f"native_next_{index}:"]
        # D1/D2 are observer temporaries outside the modeled V0. Capture the
        # real SP before restoring the wrapper's frame or dereferencing it.
        lines += ["fmov d1, x0", "fmov d2, x30", "adrp x0, native_stack_base",
                  "ldr x0, [x0, :lo12:native_stack_base]", "mov x30, sp", "sub x30, x30, x0",
                  "mov sp, x0", "ldr x0, [sp, #96]", "str x30, [x0, #248]",
                  "fmov x30, d2", "fmov x0, d1", "stp x0, x30, [sp, #112]", "ldr x0, [sp, #96]"]
        lines += [f"str x{i}, [x0, #{i*8}]" for i in range(1, 30)]
        lines += ["mrs x1, nzcv", "str x1, [x0, #256]", "add x1, x0, #264", "str q0, [x1]", "ldp x1, x2, [sp, #112]", "str x1, [x0]", "str x2, [x0, #240]"]
        lines += [f"ldp x{i}, x{i+1}, [sp, #{(i-19)*8}]" for i in range(19, 31, 2)]
        lines += ["add sp, sp, #128", "ret"]
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", choices=["x86", "arm64"], required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    arch, out = args.arch, args.out
    sys.path.insert(0, str(ROOT / "kprog" / arch / "micro-prog"))
    spec = importlib.util.spec_from_file_location("encoder", ROOT / "kprog" / arch / "micro-prog/generate_micro_sim_proofs.py")
    encoder = importlib.util.module_from_spec(spec)
    sys.modules["encoder"] = encoder
    spec.loader.exec_module(encoder)
    forms = x86_forms(encoder.CC_AUX) if arch == "x86" else arm64_forms()
    out.mkdir(parents=True, exist_ok=True)
    snapshot = out.resolve()/'snapshot'
    for path in includes(ROOT/f'kprog/{arch}/{arch}_sim_local_bpf.h') | imports(Path(encoder.__file__)):
        target = snapshot/path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path,target)
    # One object is decoded in bulk; the wrapper assembly is assembled separately.
    source = (".intel_syntax noprefix\n" if arch == "x86" else "") + ".text\n" + "\n".join(forms) + "\n"
    (out / "instructions.S").write_text(source)
    compiler = "cc" if arch == "x86" else "aarch64-linux-gnu-gcc"
    subprocess.run([compiler, "-c", str(out / "instructions.S"), "-o", str(out / "instructions.o")], check=True)
    command = ["objdump", "-d", "-Mintel", "--insn-width=16"] if arch == "x86" else ["aarch64-linux-gnu-objdump", "-d"]
    disassembly = subprocess.check_output(command + [str(out / "instructions.o")], text=True)
    (out / "instructions.asm").write_text(disassembly)
    insns = encoder.parse_asm_text(disassembly) if arch == "x86" else encoder.parse_flat_instructions(disassembly)
    if len(insns) != len(forms):
        raise RuntimeError(f"decoded {len(insns)} instructions for {len(forms)} forms")
    c = ['#include "../driver.h"', '#include <stdlib.h>', '#include <string.h>', '#define X86_SIM_ENABLE_STACK 1', f'#include "{snapshot}/kprog/{arch}/{arch}_sim_local_bpf.h"']
    if arch == "x86":
        c += ['extern uint64_t native_stack_base;']
    if arch == "arm64":
        c += ['extern uint64_t native_stack_base;', 'static void arm64_sim_unsupported_opcode(void) { abort(); }', 'unsigned long native_lab_entry_input(unsigned int kind) { if (kind == NATIVE_LAB_INPUT_SP) return native_stack_base; fputs("unexpected numeric observer environment input\\n", stderr); exit(1); }']
    entries, coverage = [], []
    pairs = [(assembly, encoder.encode(insn, {}) if arch == "x86" else encoder.encode(insn, {}, {}), None, assembly, insn.raw) for assembly, insn in zip(forms, insns)]
    if arch == "x86":
        for mnemonic, cc in encoder.CC_AUX.items():
            if not mnemonic.startswith("j"):
                continue
            for backward in [False, True]:
                body = (f"jmp 2f; 1: mov rax, 1; jmp 3f; 2: mov rax, 0; {mnemonic} 1b; 3:" if backward else f"{mnemonic} 1f; mov rax, 0; jmp 2f; 1: mov rax, 1; 2:")
                step = (f"goto condition; taken: __x86_rax.ptr=(void *)1; goto done; condition: __x86_rax.ptr=0; X86_SIM_X86_JCC({cc}, 2, 1, taken); done:;" if backward else f"X86_SIM_X86_JCC({cc}, 0, 1, taken); __x86_rax.ptr=0; goto done; taken: __x86_rax.ptr=(void *)1; done:;")
                pairs.append((f"{mnemonic} {'backward' if backward else 'forward'}", encoder.enc("X86_OP_JCC"), step, body, body))
        body = "jmp 1f; mov rax, 0; 1: mov rax, 1"
        pairs.append(("jmp forward", encoder.enc("X86_OP_JMP"), "X86_SIM_X86_JMP(0,1,taken); __x86_rax.ptr=0; taken: __x86_rax.ptr=(void *)1;", body, body))
        i = len(pairs)
        body = f"call 1f; .global return_{i}; return_{i}: jmp 2f; 1: mov rax, QWORD PTR [rsp]; ret; 2:"
        step = f"extern unsigned char return_{i}; X86_SIM_X86_CALL(subroutine,(uintptr_t)&return_{i}); dispatch: goto done; subroutine: __x86_rax.ptr=(void *)(uintptr_t)X86_SIM_L_STACK_READ(-8,X86_WIDTH_64); X86_SIM_X86_SUB_RET(dispatch); done:;"
        pairs.append(("call and ret (stack return address)", encoder.enc("X86_OP_CALL"), step, body, body))
        for width, suffix in [(8,"b"),(16,"w"),(32,"d"),(64,"q")]:
            body = f"rep movs{suffix}"
            pairs.append((body, encoder.enc("X86_OP_REP_MOVS", flags=f"X86_WIDTH_{width}", imm="8"), None, body, body))
    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):
        c += [f"extern unsigned char native_pc_{i}, native_next_{i};", f"extern void native_{i}(struct state *);", f"static void sim_{i}(struct state *s) {{"]
        if arch == "x86":
            c += ["X86_SIM_L_DECLARE_STATE(); X86_SIM_L_DECLARE_STACK(); __u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;", "__x86_native_stack_base = native_stack_base;"]
            regs = ["rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"] + [f"r{j}" for j in range(8, 16)]
            c += [f"__x86_{reg}.ptr = (void *)(uintptr_t)s->r[{j}];" for j, reg in enumerate(regs)]
            c += ["for (unsigned k=0;k<64;k++) __x86_stack_mem.b[k]=s->stack[k];"]
            c += ["__x86_cf = s->flags & 1; __x86_pf = (s->flags >> 2) & 1; __x86_af = (s->flags >> 4) & 1; __x86_zf = (s->flags >> 6) & 1; __x86_sf = (s->flags >> 7) & 1; __x86_of = (s->flags >> 11) & 1;", "__x86_xmm0_lo = s->vec[0]; __x86_xmm0_hi = s->vec[1];"]
            step = special if special is not None else encoder.direct_step_statement(encoded)
            if step is None:
                step = f"X86_SIM_RUN_OP({encoded.op}, {encoded.dst}, {encoded.src}, {encoded.flags}, {encoded.aux}, {encoded.imm});"
            c += [step + ";"]
            c += [f"s->r[{j}] = " + (f"(uintptr_t)__x86_{reg}.ptr;" if reg == "rsp" else f"X86_SIM_L_READ_REG({j});") for j, reg in enumerate(regs)]
            c += ["for (unsigned k=0;k<64;k++) s->stack[k]=__x86_stack_mem.b[k];"]
            c += ["s->flags = __x86_cf | ((uint64_t)__x86_pf << 2) | ((uint64_t)__x86_af << 4) | ((uint64_t)__x86_zf << 6) | ((uint64_t)__x86_sf << 7) | ((uint64_t)__x86_of << 11);", "s->vec[0] = __x86_xmm0_lo; s->vec[1] = __x86_xmm0_hi;"]
            width = next((bits for bits in [8, 16, 32, 64] if encoded.flags == f"X86_WIDTH_{bits}"), 64)
            op = assembly.split()[0]
            mode, count, mask = 0, 0, 0x8d5
            if encoded.op in ["X86_OP_PUSH", "X86_OP_POP"]:
                mode, count = 5, (-width//8 if encoded.op == "X86_OP_POP" else 0)
            if op == "rep": mode = 4
            if op == "div": mode, mask = 1, 0
            if op == "imul": mask = 0x801
            if op == "bt": mask = 0x41
            if op in ["and", "or", "xor", "test"]: mask &= ~0x10
            if op in ["andn", "bzhi"]: mask = 0x8c1
            if op in ["shl", "shr", "sar", "rol", "ror", "shld", "shrd"]:
                mode = 3 if op in ["rol", "ror"] else 2
                count = 256 if assembly.endswith("cl") else int(assembly.rsplit(", ", 1)[1])
        else:
            c += ["ARM64_SIM_L_DECLARE_STATE(); ARM64_SIM_L_DECLARE_STACK(); __a64_sp = s->r[31]; __u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;"]
            c += [f"__a64_x{j}.x = s->r[{j}];" for j in range(31)]
            c += ["__a64_n = (s->flags >> 31) & 1; __a64_z = (s->flags >> 30) & 1; __a64_c = (s->flags >> 29) & 1; __a64_v = (s->flags >> 28) & 1;", "__a64_v0 = s->vec[0]; __a64_v0_hi = s->vec[1];"]
            emitted = []
            encoder.append_insn(emitted, insns[i], {insns[i].addr}, insns[i].addr+4,
                                frozenset(), {}, {})
            c += emitted
            c += [f"s->r[{j}] = ARM64_SIM_L_READ_REG({j});" for j in range(31)]
            c += ["s->r[31] = __a64_sp;", "s->flags = ((uint64_t)__a64_n << 31) | ((uint64_t)__a64_z << 30) | ((uint64_t)__a64_c << 29) | ((uint64_t)__a64_v << 28);", "s->vec[0] = __a64_v0; s->vec[1] = __a64_v0_hi;"]
            mode, count, mask, width = 0, 0, 0xf0000000, 64
        c += ["}"]
        entries += [f"{{{json.dumps(assembly)}, {json.dumps(encoded.op)}, native_{i}, sim_{i}, {mask}U, {width}, {count}, {mode}, &native_pc_{i}, &native_next_{i}}}"]
        coverage += [{"assembly": assembly, "decoded": decoded, "opcode": encoded.op}]
    c += ["const struct form forms[] = {", ",\n".join(entries), "};", "const unsigned form_count = sizeof(forms) / sizeof(forms[0]);"]
    (out / "generated.c").write_text("\n".join(c) + "\n")
    native = (".intel_syntax noprefix\n" if arch == "x86" else "") + ".text\n"
    native += "\n".join(native_wrapper(arch, i, pair[3], pair[1].op,
                         next((bits//8 for bits in [16,64] if pair[1].flags == f"X86_WIDTH_{bits}"), 0)
                         if arch == "x86" else 0) for i, pair in enumerate(pairs))
    native += '\n.section .note.GNU-stack,"",%progbits\n'
    (out / "native.S").write_text(native)
    (out / "coverage.json").write_text(json.dumps(coverage, indent=2) + "\n")
    print(f"generated {len(pairs)} {arch} CPU/simulator pairs")


if __name__ == "__main__":
    main()
