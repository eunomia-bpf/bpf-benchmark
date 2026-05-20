#!/usr/bin/env python3
"""Generate hardcoded arm64-simulator verifier artifacts from micro native code."""

from __future__ import annotations

import argparse
import re
import subprocess
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path

import yaml


REPO_ROOT = Path(__file__).resolve().parents[3]
OUT_DIR = Path(__file__).resolve().parent
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
ARM64_BUILD_DIR = MICRO_PROGRAMS / "build-arm64"

WIDTH_CONST = {1: "ARM64_WIDTH_8", 2: "ARM64_WIDTH_16", 4: "ARM64_WIDTH_32", 8: "ARM64_WIDTH_64"}
ALU = {"add": "ARM64_ALU_ADD", "sub": "ARM64_ALU_SUB", "and": "ARM64_ALU_AND",
       "bic": "ARM64_ALU_BIC", "eor": "ARM64_ALU_EOR", "orr": "ARM64_ALU_ORR"}
SHIFT = {"lsl": "ARM64_SHIFT_LSL", "lsr": "ARM64_SHIFT_LSR", "asr": "ARM64_SHIFT_ASR", "ror": "ARM64_SHIFT_ROR"}
MOD = {"": "ARM64_MOD_NONE", "lsl": "ARM64_MOD_LSL", "lsr": "ARM64_MOD_LSR",
       "asr": "ARM64_MOD_ASR", "ror": "ARM64_MOD_ROR", "uxtw": "ARM64_MOD_UXTW",
       "sxtw": "ARM64_MOD_SXTW", "uxth": "ARM64_MOD_UXTH", "sxth": "ARM64_MOD_SXTH",
       "uxtb": "ARM64_MOD_UXTB", "sxtb": "ARM64_MOD_SXTB"}
COND = {"eq": "ARM64_COND_EQ", "ne": "ARM64_COND_NE", "cs": "ARM64_COND_CS",
        "hs": "ARM64_COND_CS", "cc": "ARM64_COND_CC", "lo": "ARM64_COND_CC",
        "mi": "ARM64_COND_MI", "pl": "ARM64_COND_PL", "vs": "ARM64_COND_VS",
        "vc": "ARM64_COND_VC", "hi": "ARM64_COND_HI", "ls": "ARM64_COND_LS",
        "ge": "ARM64_COND_GE", "lt": "ARM64_COND_LT", "gt": "ARM64_COND_GT",
        "le": "ARM64_COND_LE", "al": "ARM64_COND_AL"}
BITFIELD = {"ubfx": "ARM64_BITFIELD_UBFX", "sbfx": "ARM64_BITFIELD_SBFX",
            "ubfiz": "ARM64_BITFIELD_UBFIZ", "bfxil": "ARM64_BITFIELD_BFXIL",
            "bfi": "ARM64_BITFIELD_BFI"}


@dataclass(frozen=True)
class Bench:
    name: str
    symbol: str
    kind: str


@dataclass(frozen=True)
class NativeInsn:
    addr: int
    mnemonic: str
    operands: tuple[str, ...]
    raw: str


@dataclass(frozen=True)
class MemRef:
    base: str
    index: str
    mod: str
    shift: int
    offset: int
    flags: int


@dataclass(frozen=True)
class Encoded:
    op: str
    dst: str = "ARM64_REG_NONE"
    src: str = "ARM64_REG_NONE"
    src2: str = "ARM64_REG_NONE"
    src3: str = "ARM64_REG_NONE"
    width: str = "ARM64_WIDTH_64"
    aux: str = "0"
    imm: str = "0"


def run_objdump(native_so: Path) -> str:
    result = subprocess.run(["aarch64-linux-gnu-objdump", "-d", str(native_so)],
                            check=False, capture_output=True, text=True)
    if result.returncode != 0:
        raise RuntimeError(result.stderr.strip() or result.stdout.strip())
    return result.stdout


def split_operands(text: str) -> tuple[str, ...]:
    parts: list[str] = []
    cur: list[str] = []
    depth = 0
    for ch in text:
        if ch == "[":
            depth += 1
        elif ch == "]":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
            continue
        cur.append(ch)
    if cur:
        parts.append("".join(cur).strip())
    return tuple(parts)


def parse_functions(text: str) -> tuple[dict[str, list[NativeInsn]], dict[int, str]]:
    functions: dict[str, list[NativeInsn]] = OrderedDict()
    by_addr: dict[int, str] = {}
    current: str | None = None
    func_re = re.compile(r"^([0-9a-f]+) <([^>]+)>:$")
    insn_re = re.compile(r"^\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+\t([a-z0-9.]+)\s*(.*)$")
    for line in text.splitlines():
        m_func = func_re.match(line)
        if m_func:
            current = m_func.group(2)
            functions[current] = []
            by_addr[int(m_func.group(1), 16)] = current
            continue
        if current is None:
            continue
        m_insn = insn_re.match(line)
        if not m_insn:
            continue
        operands = m_insn.group(3).split("//", 1)[0].strip()
        asm = f"{m_insn.group(2)} {operands}".strip()
        functions[current].append(NativeInsn(int(m_insn.group(1), 16),
                                             m_insn.group(2),
                                             split_operands(operands),
                                             asm))
    return functions, by_addr


def branch_target(operand: str) -> int:
    return int(operand.split()[0], 16)


def collect_functions(functions: dict[str, list[NativeInsn]],
                      by_addr: dict[int, str],
                      entry: str) -> OrderedDict[str, list[NativeInsn]]:
    selected: OrderedDict[str, list[NativeInsn]] = OrderedDict()

    def add(symbol: str) -> None:
        if symbol in selected:
            return
        insns = functions.get(symbol)
        if not insns:
            raise RuntimeError(f"missing arm64 native symbol: {symbol}")
        selected[symbol] = insns
        for insn in insns:
            if insn.mnemonic == "bl":
                target = branch_target(insn.operands[0])
                target_symbol = by_addr.get(target)
                if target_symbol is None:
                    raise RuntimeError(f"unresolved arm64 call target in {insn.raw}")
                add(target_symbol)

    add(entry)
    return selected


def program_kind(item: dict) -> str:
    tags = set(item.get("tags", []))
    if "cgroup-skb" in tags or "cgroup_skb" in tags:
        return "cgroup_skb"
    if "tc" in tags:
        return "tc"
    return "xdp"


def load_benches() -> list[Bench]:
    data = yaml.safe_load(CONFIG.read_text(encoding="utf-8"))
    return [
        Bench(item["name"], item.get("program_name", f"{item['name']}_xdp"), program_kind(item))
        for item in data["benchmarks"]
    ]


def c_comment(text: str) -> str:
    return text.replace("*/", "* /")


def c_u64(value: int) -> str:
    return f"{value & 0xffffffffffffffff}ULL"


def parse_imm(text: str) -> int:
    text = text.strip()
    if not text.startswith("#"):
        raise ValueError(f"expected immediate: {text}")
    return int(text[1:], 0)


def parse_shifted_imm(parts: tuple[str, ...], index: int) -> int:
    value = parse_imm(parts[index])
    if index + 1 >= len(parts):
        return value
    mod, shift = parse_modifier(parts, index + 1)
    if mod != "ARM64_MOD_LSL":
        raise ValueError(f"unsupported immediate modifier: {', '.join(parts[index + 1:])}")
    return value << shift


def reg_const(reg: str) -> str:
    reg = reg.strip().lower()
    if reg in {"xzr", "wzr"}:
        return "ARM64_XZR"
    if reg == "sp":
        return "ARM64_SP"
    m = re.fullmatch(r"[xw]([0-9]|[12][0-9]|30)", reg)
    if not m:
        raise ValueError(f"unsupported register: {reg}")
    return f"ARM64_X{m.group(1)}"


def reg_width(reg: str) -> int:
    return 4 if reg.strip().lower().startswith("w") else 8


def width_const(width: int) -> str:
    return WIDTH_CONST[width]


def parse_modifier(parts: tuple[str, ...], index: int) -> tuple[str, int]:
    if index >= len(parts):
        return "ARM64_MOD_NONE", 0
    text = ", ".join(parts[index:]).strip().lower()
    m_shift = re.fullmatch(r"(lsl|lsr|asr|ror)\s+#(0x[0-9a-f]+|[0-9]+)", text)
    if m_shift:
        return MOD[m_shift.group(1)], int(m_shift.group(2), 0)
    m_ext = re.fullmatch(r"(uxtw|sxtw|uxth|sxth|uxtb|sxtb)(?:\s+#(0x[0-9a-f]+|[0-9]+))?", text)
    if m_ext:
        return MOD[m_ext.group(1)], int(m_ext.group(2) or "0", 0)
    raise ValueError(f"unsupported operand modifier: {text}")


def parse_mem(parts: tuple[str, ...], index: int) -> MemRef:
    text = parts[index].strip().lower()
    post = 0
    flags = 0
    if index + 1 < len(parts) and parts[index + 1].strip().startswith("#"):
        post = parse_imm(parts[index + 1])
        flags |= 2
    pre = text.endswith("!")
    if pre:
        text = text[:-1]
        flags |= 1
    m = re.fullmatch(r"\[(.*)\]", text)
    if not m:
        raise ValueError(f"unsupported memory operand: {parts[index]}")
    inner = split_operands(m.group(1))
    base = reg_const(inner[0])
    offset = post if post else 0
    idx = "ARM64_REG_NONE"
    mod = "ARM64_MOD_NONE"
    shift = 0
    if len(inner) >= 2:
        if inner[1].startswith("#"):
            offset = parse_imm(inner[1])
        else:
            idx = reg_const(inner[1])
            mod, shift = parse_modifier(inner, 2)
    return MemRef(base, idx, mod, shift, offset, flags)


def mem_aux(mem: MemRef) -> str:
    flag_expr = "0"
    if mem.flags == 1:
        flag_expr = "ARM64_MEM_PRE"
    elif mem.flags == 2:
        flag_expr = "ARM64_MEM_POST"
    return f"ARM64_AUX_MEM({mem.index}, {mem.mod}, {mem.shift}, {flag_expr})"


def reg_or_imm(text: str) -> bool:
    return text.strip().startswith("#")


def encode(insn: NativeInsn) -> Encoded:
    op = insn.mnemonic
    ops = insn.operands
    if op == "nop":
        return Encoded("ARM64_OP_NOP")
    if op == "mov":
        dst, src = ops[0], ops[1]
        if src.startswith("#"):
            return Encoded("ARM64_OP_MOV_IMM", reg_const(dst), width=width_const(reg_width(dst)), imm=c_u64(parse_shifted_imm(ops, 1)))
        return Encoded("ARM64_OP_MOV_REG", reg_const(dst), reg_const(src), width=width_const(reg_width(dst)))
    if op == "movk":
        shift = 0
        if len(ops) > 2:
            mod, shift = parse_modifier(ops, 2)
            if mod != "ARM64_MOD_LSL":
                raise ValueError(f"unsupported movk shift: {insn.raw}")
        return Encoded("ARM64_OP_MOVK", reg_const(ops[0]), width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_MOVK({shift})", imm=c_u64(parse_imm(ops[1])))
    if op in ALU:
        width = width_const(reg_width(ops[0]))
        aux = f"ARM64_AUX_ALU({ALU[op]}, ARM64_MOD_NONE, 0)"
        if reg_or_imm(ops[2]):
            return Encoded("ARM64_OP_ALU_IMM", reg_const(ops[0]), reg_const(ops[1]), width=width,
                           aux=aux, imm=c_u64(parse_shifted_imm(ops, 2)))
        mod, shift = parse_modifier(ops, 3)
        aux = f"ARM64_AUX_ALU({ALU[op]}, {mod}, {shift})"
        return Encoded("ARM64_OP_ALU_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width, aux=aux)
    if op in SHIFT:
        width = width_const(reg_width(ops[0]))
        if ops[2].startswith("#"):
            return Encoded("ARM64_OP_SHIFT_IMM", reg_const(ops[0]), reg_const(ops[1]), width=width,
                           aux=f"ARM64_AUX_SHIFT({SHIFT[op]})", imm=c_u64(parse_imm(ops[2])))
        return Encoded("ARM64_OP_SHIFT_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width, aux=f"ARM64_AUX_SHIFT({SHIFT[op]})")
    if op in {"madd", "msub"}:
        return Encoded("ARM64_OP_MADD" if op == "madd" else "ARM64_OP_MSUB",
                       reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]), reg_const(ops[3]),
                       width=width_const(reg_width(ops[0])))
    if op in {"mul", "umull", "udiv"}:
        op_const = {"mul": "ARM64_OP_MUL", "umull": "ARM64_OP_UMULL", "udiv": "ARM64_OP_UDIV"}[op]
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])))
    if op in {"mvn", "neg"}:
        return Encoded("ARM64_OP_MVN" if op == "mvn" else "ARM64_OP_NEG",
                       reg_const(ops[0]), reg_const(ops[1]), width=width_const(reg_width(ops[0])))
    if op == "extr":
        return Encoded("ARM64_OP_EXTR", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])), imm=c_u64(parse_imm(ops[3])))
    if op in BITFIELD:
        return Encoded("ARM64_OP_BITFIELD", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_BITFIELD({BITFIELD[op]}, {parse_imm(ops[2])}, {parse_imm(ops[3])})")
    if op in {"rev", "rev16", "sxth"}:
        op_const = {"rev": "ARM64_OP_REV", "rev16": "ARM64_OP_REV16", "sxth": "ARM64_OP_SXTH"}[op]
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), width=width_const(reg_width(ops[0])))
    if op in {"ldr", "ldur", "ldrb", "ldurb", "ldrh", "ldurh"}:
        width = 1 if op in {"ldrb", "ldurb"} else 2 if op in {"ldrh", "ldurh"} else reg_width(ops[0])
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LOAD", reg_const(ops[0]), mem.base, mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldp":
        mem = parse_mem(ops, 2)
        width = reg_width(ops[0])
        return Encoded("ARM64_OP_LDP", reg_const(ops[0]), reg_const(ops[1]), mem.base, mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op in {"str", "stur", "strb", "strh"}:
        width = 1 if op == "strb" else 2 if op == "strh" else reg_width(ops[0])
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_STORE", mem.base, reg_const(ops[0]), mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "stp":
        mem = parse_mem(ops, 2)
        width = reg_width(ops[0])
        return Encoded("ARM64_OP_STP", mem.base, reg_const(ops[0]), reg_const(ops[1]), mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op in {"cmp", "tst"}:
        width = width_const(reg_width(ops[0]))
        imm = ops[1].startswith("#")
        mod, shift = ("ARM64_MOD_NONE", 0) if imm else parse_modifier(ops, 2)
        aux = f"ARM64_AUX_ALU(0, {mod}, {shift})"
        op_const = ("ARM64_OP_CMP_IMM" if imm else "ARM64_OP_CMP_REG") if op == "cmp" else \
                   ("ARM64_OP_TST_IMM" if imm else "ARM64_OP_TST_REG")
        return Encoded(op_const, reg_const(ops[0]), "ARM64_REG_NONE" if imm else reg_const(ops[1]),
                       width=width, aux=aux, imm=c_u64(parse_shifted_imm(ops, 1)) if imm else "0")
    if op == "ccmp":
        imm = ops[1].startswith("#")
        op_const = "ARM64_OP_CCMP_IMM" if imm else "ARM64_OP_CCMP_REG"
        return Encoded(op_const, reg_const(ops[0]), "ARM64_REG_NONE" if imm else reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_CCMP({COND[ops[3]]}, {parse_imm(ops[2])})",
                       imm=c_u64(parse_imm(ops[1])) if imm else "0")
    if op in {"csel", "cinc", "cset"}:
        if op == "cset":
            return Encoded("ARM64_OP_CSET", reg_const(ops[0]), width=width_const(reg_width(ops[0])), aux=COND[ops[1]])
        op_const = "ARM64_OP_CSEL" if op == "csel" else "ARM64_OP_CINC"
        src2 = reg_const(ops[2]) if op == "csel" else "ARM64_REG_NONE"
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), src2,
                       width=width_const(reg_width(ops[0])), aux=COND[ops[-1]])
    if op == "fmov":
        dst, src = ops
        if dst.startswith("d") and src.startswith("x"):
            return Encoded("ARM64_OP_FMOV", src=reg_const(src), aux="ARM64_FMOV_D_FROM_X")
        if dst.startswith("x") and src.startswith("d"):
            return Encoded("ARM64_OP_FMOV", reg_const(dst), width="ARM64_WIDTH_64", aux="ARM64_FMOV_X_FROM_D")
        if dst.startswith("s") and src.startswith("w"):
            return Encoded("ARM64_OP_FMOV", src=reg_const(src), aux="ARM64_FMOV_S_FROM_W")
        if dst.startswith("w") and src.startswith("s"):
            return Encoded("ARM64_OP_FMOV", reg_const(dst), width="ARM64_WIDTH_32", aux="ARM64_FMOV_W_FROM_S")
    if op == "cnt":
        return Encoded("ARM64_OP_CNT")
    if op == "uaddlv":
        return Encoded("ARM64_OP_UADDLV")
    raise ValueError(f"unsupported arm64 instruction: {insn.raw}")


def label(addr: int) -> str:
    return f"arm64_l_{addr:x}"


def append_insn(lines: list[str], insn: NativeInsn, all_addrs: set[int],
                next_addr: int | None) -> None:
    lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    op = insn.mnemonic
    if op.startswith("b."):
        target = branch_target(insn.operands[0])
        lines.append(f"\tARM64_SIM_A64_JCC({COND[op.split('.', 1)[1]]}, 0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op == "b":
        target = branch_target(insn.operands[0])
        lines.append(f"\tARM64_SIM_A64_JMP(0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op in {"cbz", "cbnz"}:
        target = branch_target(insn.operands[1])
        macro = "ARM64_SIM_A64_CBZ" if op == "cbz" else "ARM64_SIM_A64_CBNZ"
        lines.append(f"\t{macro}({reg_const(insn.operands[0])}, 0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op in {"tbz", "tbnz"}:
        target = branch_target(insn.operands[2])
        macro = "ARM64_SIM_A64_TBZ" if op == "tbz" else "ARM64_SIM_A64_TBNZ"
        lines.append(f"\t{macro}({reg_const(insn.operands[0])}, {parse_imm(insn.operands[1])}, 0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op == "bl":
        target = branch_target(insn.operands[0])
        if target not in all_addrs or next_addr is None:
            raise ValueError(f"unsupported call target in {insn.raw}")
        lines.append(f"\tARM64_SIM_A64_CALL({label(target)}, 0x{next_addr:x}ULL);")
        return
    if op == "ret":
        lines.append("\tARM64_SIM_A64_RET();")
        return
    enc = encode(insn)
    lines.append(
        f"\tARM64_SIM_RUN_OP3({enc.op}, {enc.dst}, {enc.src}, {enc.src2}, {enc.src3}, "
        f"{enc.width}, {enc.aux}, {enc.imm});"
    )


def render_program(name: str, symbol: str, functions: OrderedDict[str, list[NativeInsn]], kind: str) -> str:
    all_insns = [insn for fn in functions.values() for insn in fn]
    all_addrs = {insn.addr for insn in all_insns}
    next_by_addr = {
        insns[index].addr: insns[index + 1].addr
        for insns in functions.values()
        for index in range(len(insns) - 1)
    }
    return_addrs = sorted(next_by_addr[insn.addr] for insn in all_insns if insn.mnemonic == "bl")
    uses_stack = bool(return_addrs) or any("[sp" in insn.raw.lower() for insn in all_insns)
    section, ctx, entry = {
        "xdp": ('SEC("xdp")', "struct xdp_md *", "ARM64_SIM_ENTRY_XDP(ctx);"),
        "tc": ('SEC("tc")', "struct __sk_buff *", "ARM64_SIM_ENTRY_SKB(ctx);"),
        "cgroup_skb": ('SEC("cgroup_skb/egress")', "struct __sk_buff *", "ARM64_SIM_ENTRY_SKB(ctx);"),
    }[kind]
    lines: list[str] = []
    if uses_stack:
        lines.append("#define ARM64_SIM_ENABLE_STACK 1")
    if return_addrs:
        lines.append("#define ARM64_SIM_RETURN_CASES \\")
        for idx, addr in enumerate(return_addrs):
            tail = " \\" if idx + 1 < len(return_addrs) else ""
            lines.append(f"\tcase 0x{addr:x}ULL: __a64_lr = 0; goto {label(addr)};{tail}")
    lines.extend([
        '#include "../arm64_sim_local_bpf.h"',
        "",
        section,
        f"int {name}_arm64_sim_xdp({ctx}ctx)",
        "{",
        f"\t{entry}",
    ])
    for fn_symbol, insns in functions.items():
        if fn_symbol != symbol:
            lines.append(f"\t/* native subroutine {c_comment(fn_symbol)} */")
        for insn in insns:
            lines.append(f"{label(insn.addr)}:")
            append_insn(lines, insn, all_addrs, next_by_addr.get(insn.addr))
    lines.extend(["\treturn 0;", "}", "", "ARM64_SIM_LICENSE();", ""])
    return "\n".join(lines)


def generate_one(bench: Bench, output_dir: Path, build_dir: Path) -> Path:
    native_so = build_dir / f"{bench.name}.native.so"
    if not native_so.is_file():
        raise RuntimeError(f"missing arm64 native object: {native_so}")
    functions, by_addr = parse_functions(run_objdump(native_so))
    selected = collect_functions(functions, by_addr, bench.symbol)
    output = output_dir / f"{bench.name}.bpf.c"
    output.write_text(render_program(bench.name, bench.symbol, selected, bench.kind), encoding="utf-8")
    return output


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--micro-programs", type=Path, default=MICRO_PROGRAMS)
    parser.add_argument("--output-dir", type=Path, default=OUT_DIR)
    parser.add_argument("--native-build-dir", type=Path, default=ARM64_BUILD_DIR)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark stem list")
    args = parser.parse_args()
    args.output_dir.mkdir(parents=True, exist_ok=True)
    only = set(args.only or [])
    written = [
        generate_one(bench, args.output_dir, args.native_build_dir)
        for bench in load_benches()
        if not only or bench.name in only
    ]
    for path in written:
        print(path)
    print(f"generated {len(written)} proof sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
