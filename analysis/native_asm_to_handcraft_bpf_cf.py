#!/usr/bin/env python3
"""Translate x86 native asm text into a handcraft.c candidate.

This experimental variant keeps branch/call/exit as ordinary BPF control-flow
instructions instead of emitting branch kinsns.  It is intentionally separate
from native_asm_to_handcraft.py so the strict machine-kinsn path remains visible.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass, replace
from pathlib import Path


BPF_REG_BY_X86 = {
    "rax": "HC_X86_RAX",
    "rdi": "HC_X86_RDI",
    "rsi": "HC_X86_RSI",
    "rdx": "HC_X86_RDX",
    "rcx": "HC_X86_RCX",
    "r8": "HC_X86_R8",
    "r9": "HC_X86_R9",
    "r10": "HC_X86_R10",
    "r11": "HC_X86_R11",
    "r12": "HC_X86_R12",
    "rsp": "HC_X86_RSP",
    "rbp": "HC_X86_RBP",
    "rbx": "HC_X86_RBX",
    "r13": "HC_X86_R13",
    "r14": "HC_X86_R14",
    "r15": "HC_X86_R15",
}

HIGH_BYTE_X86_REGS = {"ah", "bh", "ch", "dh"}
X86_REG_NAMES: dict[str, tuple[str, int]] = {}
for base, names in {
    "rax": ("rax", "eax", "ax", "al", "ah"),
    "rbx": ("rbx", "ebx", "bx", "bl", "bh"),
    "rcx": ("rcx", "ecx", "cx", "cl", "ch"),
    "rdx": ("rdx", "edx", "dx", "dl", "dh"),
    "rdi": ("rdi", "edi", "di", "dil"),
    "rsi": ("rsi", "esi", "si", "sil"),
    "r8": ("r8", "r8d", "r8w", "r8b"),
    "r9": ("r9", "r9d", "r9w", "r9b"),
    "r10": ("r10", "r10d", "r10w", "r10b"),
    "r11": ("r11", "r11d", "r11w", "r11b"),
    "r12": ("r12", "r12d", "r12w", "r12b"),
    "r13": ("r13", "r13d", "r13w", "r13b"),
    "r14": ("r14", "r14d", "r14w", "r14b"),
    "r15": ("r15", "r15d", "r15w", "r15b"),
    "rbp": ("rbp", "ebp", "bp", "bpl"),
    "rsp": ("rsp", "esp", "sp", "spl"),
}.items():
    for name in names:
        width = 64 if name.startswith("r") and not name.endswith(("d", "w", "b")) else 32
        if name.endswith("w") or name in {"ax", "bx", "cx", "dx", "di", "si", "bp", "sp"}:
            width = 16
        if name.endswith("b") or name in HIGH_BYTE_X86_REGS | {"al", "bl", "cl", "dl", "dil", "sil", "bpl", "spl"}:
            width = 8
        X86_REG_NAMES[name] = (base, width)

OBJ_LINE_RE = re.compile(r"^\s*(?P<addr>[0-9a-f]+):\s+(?P<bytes>(?:[0-9a-f]{2}\s+)+)\s*(?P<asm>.*)$")
ASM_LINE_RE = re.compile(r"^\s*(?P<mnemonic>[a-z][a-z0-9]*)\s*(?P<operands>.*)$")
FUNC_LABEL_RE = re.compile(r"^\s*(?P<addr>[0-9a-f]+)\s+<(?P<name>[^>]+)>:$")
BRANCH_DELTA = "__BRANCH_DELTA__"
BRANCH_OFF = f"({BRANCH_DELTA}) - 1"
RETURN_CODE = (
    "HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ)",
    "HC_EXIT()",
)
RETURN_BPF_LEN = 3
SIZE_BY_PTR = {"BYTE": "BPF_B", "WORD": "BPF_H", "DWORD": "BPF_W", "QWORD": "BPF_DW"}
DIRECT_LOAD_SELECTOR = {
    "BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL",
    "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL",
    "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL",
    "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ",
}
DIRECT_STORE_SELECTOR = {
    "BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVB",
    "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVW",
    "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL",
    "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ",
}
ALU_OP = {"add": "BPF_ADD", "sub": "BPF_SUB", "xor": "BPF_XOR", "or": "BPF_OR", "and": "BPF_AND", "shl": "BPF_LSH", "shr": "BPF_RSH"}
MACHINE_ALU_SELECTOR = {
    ("add", 64): "MICRO_HANDCRAFT_BPF_X86_ADDQ",
    ("add", 32): "MICRO_HANDCRAFT_BPF_X86_ADDL",
    ("add", 8): "MICRO_HANDCRAFT_BPF_X86_ADDB",
    ("sub", 64): "MICRO_HANDCRAFT_BPF_X86_SUBQ",
    ("sub", 32): "MICRO_HANDCRAFT_BPF_X86_SUBL",
    ("sub", 8): "MICRO_HANDCRAFT_BPF_X86_SUBB",
    ("and", 64): "MICRO_HANDCRAFT_BPF_X86_ANDQ",
    ("and", 32): "MICRO_HANDCRAFT_BPF_X86_ANDL",
    ("shr", 8): "MICRO_HANDCRAFT_BPF_X86_SHRB",
    ("xor", 64): "MICRO_HANDCRAFT_BPF_X86_XORQ",
    ("xor", 32): "MICRO_HANDCRAFT_BPF_X86_XORL",
    ("or", 64): "MICRO_HANDCRAFT_BPF_X86_ORQ",
    ("or", 32): "MICRO_HANDCRAFT_BPF_X86_ORL",
    ("or", 16): "MICRO_HANDCRAFT_BPF_X86_ORW",
    ("shl", 64): "MICRO_HANDCRAFT_BPF_X86_SHLQ",
    ("shl", 32): "MICRO_HANDCRAFT_BPF_X86_SHLL",
    ("shl", 8): "MICRO_HANDCRAFT_BPF_X86_SHLB",
    ("shr", 64): "MICRO_HANDCRAFT_BPF_X86_SHRQ",
    ("shr", 32): "MICRO_HANDCRAFT_BPF_X86_SHRL",
    ("sar", 64): "MICRO_HANDCRAFT_BPF_X86_SARQ",
    ("sar", 32): "MICRO_HANDCRAFT_BPF_X86_SARL",
}
JCC_OP = {
    "ja": "BPF_JGT",
    "jae": "BPF_JGE",
    "jb": "BPF_JLT",
    "jbe": "BPF_JLE",
    "je": "BPF_JEQ",
    "jne": "BPF_JNE",
    "jg": "BPF_JSGT",
    "jge": "BPF_JSGE",
    "jl": "BPF_JSLT",
    "jle": "BPF_JSLE",
    "js": "BPF_JSLT",
    "jns": "BPF_JSGE",
}
SHADOW_REG_OFF_BY_TOKEN = {
    "HC_X86_RAX": -512,
    "HC_X86_RCX": -504,
    "HC_X86_RDX": -496,
    "HC_X86_RBX": -488,
    "HC_X86_R9": -440,
    "HC_X86_R10": -432,
    "HC_X86_R11": -424,
    "HC_X86_R12": -416,
    "HC_X86_RSI": -464,
    "HC_X86_RDI": -456,
    "HC_X86_R8": -448,
    "HC_X86_R13": -408,
    "HC_X86_R14": -400,
    "HC_X86_R15": -392,
    "HC_X86_RBP": -472,
    "HC_X86_RSP": -480,
}
SHADOW_REG_OFFSETS = frozenset(SHADOW_REG_OFF_BY_TOKEN.values())
CONTEXT_KIND = "xdp"
SKB_DATA_OFF = 76
SKB_DATA_END_OFF = 80
SKB_CB0_OFF = 48
SKB_CB1_OFF = 52
@dataclass(frozen=True)
class NativeInsn:
    addr: int
    size: int
    raw: str
    mnemonic: str
    operands: tuple[str, ...]


@dataclass(frozen=True)
class Translation:
    status: str
    code: tuple[str, ...]
    note: str
    target_addr: int | None = None


def parse_int(text: str) -> int:
    text = text.strip()
    if text.startswith("-"):
        return -parse_int(text[1:])
    return int(text, 16) if text.lower().startswith("0x") else int(text, 10)


def is_int(text: str) -> bool:
    return re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", text.strip()) is not None


def parse_branch_target(text: str) -> int | None:
    match = re.match(r"\s*(0x[0-9a-fA-F]+|[0-9a-fA-F]+)", text)
    if match is None:
        return None
    token = match.group(1)
    return int(token, 16) if not token.startswith("0x") else int(token, 16)


def split_operands(text: str) -> tuple[str, ...]:
    parts: list[str] = []
    start = 0
    depth = 0
    for index, char in enumerate(text):
        if char == "[":
            depth += 1
        elif char == "]":
            depth -= 1
        elif char == "," and depth == 0:
            parts.append(text[start:index].strip())
            start = index + 1
    tail = text[start:].strip()
    if tail:
        parts.append(tail)
    return tuple(parts)


def extract_asm_text(text: str) -> str:
    match = re.search(r"^## Native ASM\n```asm\n(.*?)\n```", text, re.S | re.M)
    return match.group(1) if match else text


def reachable_asm_text(text: str, entry_symbol: str) -> str:
    functions: list[tuple[int, str, list[str]]] = []
    current: tuple[int, str, list[str]] | None = None
    for line in extract_asm_text(text).splitlines():
        label = FUNC_LABEL_RE.match(line)
        if label:
            if current is not None:
                functions.append(current)
            current = (int(label.group("addr"), 16), label.group("name"), [line])
            continue
        if current is not None:
            current[2].append(line)
    if current is not None:
        functions.append(current)

    by_name = {name: (addr, lines) for addr, name, lines in functions}
    by_addr = {addr: (name, lines) for addr, name, lines in functions}
    if entry_symbol not in by_name:
        return text

    work = [by_name[entry_symbol][0]]
    selected: set[int] = set()
    while work:
        addr = work.pop()
        if addr in selected:
            continue
        selected.add(addr)
        _name, lines = by_addr[addr]
        for line in lines:
            obj = OBJ_LINE_RE.match(line)
            if obj is None:
                continue
            parsed = ASM_LINE_RE.match(obj.group("asm").split("#", 1)[0].strip())
            if parsed is None or parsed.group("mnemonic") != "call":
                continue
            target = parse_branch_target(parsed.group("operands"))
            if target is not None and target in by_addr and target not in selected:
                work.append(target)

    out: list[str] = []
    for addr, _name, lines in sorted(functions):
        if addr in selected:
            out.extend(lines)
    return "\n".join(out)


def parse_native_asm(text: str, entry_symbol: str | None = None) -> list[NativeInsn]:
    if entry_symbol:
        text = reachable_asm_text(text, entry_symbol)
    insns: list[NativeInsn] = []
    for line in extract_asm_text(text).splitlines():
        obj = OBJ_LINE_RE.match(line)
        if obj:
            asm = obj.group("asm").split("#", 1)[0].strip()
            size = len(obj.group("bytes").split())
            if not asm:
                if insns:
                    insns[-1] = replace(insns[-1], size=insns[-1].size + size)
                continue
            if not asm or asm.startswith("<"):
                continue
            parsed = ASM_LINE_RE.match(asm)
            if not parsed:
                continue
            insns.append(NativeInsn(
                addr=int(obj.group("addr"), 16),
                size=size,
                raw=asm,
                mnemonic=parsed.group("mnemonic"),
                operands=split_operands(parsed.group("operands")),
            ))
            continue
        if line.startswith("\t") or line.startswith(" "):
            asm = line.split("#", 1)[0].strip()
            parsed = ASM_LINE_RE.match(asm)
            if parsed and not asm.startswith((".", "#")):
                insns.append(NativeInsn(0, 0, asm, parsed.group("mnemonic"), split_operands(parsed.group("operands"))))
    return insns


def reg(operand: str) -> tuple[str, int] | None:
    return X86_REG_NAMES.get(operand.strip().lower().lstrip("%"))


def unsupported_reg_note(role: str, operand: str) -> str:
    parsed = reg(operand)
    if parsed and parsed[0] in {"rbp", "rsp"}:
        return f"{role} {operand} needs explicit x86 {parsed[0]} shadow/frame-state payload"
    return f"{role} {operand} is not in the BPF JIT register file"


def bpf_reg(operand: str) -> tuple[str, int, str] | None:
    parsed = reg(operand)
    if parsed is None:
        return None
    base, width = parsed
    mapped = BPF_REG_BY_X86.get(base)
    if mapped is None:
        return None
    return mapped, width, base


def bpf_mem_base(operand: str | None) -> tuple[str, int, str] | None:
    if operand is None:
        return None
    parsed = reg(operand)
    if parsed and parsed[0] == "rbp":
        return "HC_X86_RBP", parsed[1], parsed[0]
    return bpf_reg(operand)


def byte_lane(operand: str) -> int:
    return 1 if operand.strip().lower() in HIGH_BYTE_X86_REGS else 0


def is_bpf_reg_name(name: str) -> bool:
    return name.startswith("BPF_REG_")


def is_runtime_bpf_reg_name(name: str) -> bool:
    return is_bpf_reg_name(name) and name != "BPF_REG_10"


def is_shadow_reg_name(name: str) -> bool:
    return name.startswith("HC_X86_")


def arch_payload(regs: tuple[tuple[str, int, str], ...]) -> bool:
    return any(is_shadow_reg_name(item[0]) for item in regs)


def arch_reg_note(insn: NativeInsn) -> str:
    return f"{insn.raw} needs an arch-register payload form for native rbp"


def reg_reg_payload(dst: tuple[str, int, str], src: tuple[str, int, str]) -> str:
    macro = "HC_X86_ARCH_RR_PAYLOAD" if arch_payload((dst, src)) else "HC_X86_RR_PAYLOAD"
    return f"{macro}({dst[0]}, {src[0]})"


def cmp_rr_payload(lhs: str, rhs: str) -> str:
    return f"HC_REG_REG_PAYLOAD({lhs}, {rhs})"


def byte_reg_reg_payload(dst: str, src: str) -> str:
    return f"HC_REG_REG_PAYLOAD({dst}, {src})"


def c_s32(value: int) -> str:
    value &= 0xffffffff
    if value >= 0x80000000:
        value -= 0x100000000
    return str(value)


def c_u64(value: int) -> str:
    return f"0x{value & 0xffffffffffffffff:x}ULL"


def movabs_bpf(dst: tuple[str, int, str], imm: int) -> tuple[str, ...] | None:
    if is_runtime_bpf_reg_name(dst[0]):
        return (f"HC_LD_IMM64_RAW({dst[0]}, 0, {c_u64(imm)})",)
    if dst[0] in SHADOW_REG_OFF_BY_TOKEN:
        return (
            f"HC_LD_IMM64_RAW(BPF_REG_6, 0, {c_u64(imm)})",
            f"HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD({dst[0]}, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ)",
        )
    return None


def context_load(dst: tuple[str, int, str], bpf_off: int) -> tuple[str, ...] | None:
    if is_runtime_bpf_reg_name(dst[0]):
        return (f"HC_LDX(BPF_W, {dst[0]}, BPF_REG_1, {bpf_off})",)
    if dst[0] in SHADOW_REG_OFF_BY_TOKEN:
        return (
            f"HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, {bpf_off})",
            f"HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD({dst[0]}, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ)",
        )
    return None


def sign_extend_32_to_64_bpf(dst: tuple[str, int, str], src: tuple[str, int, str]) -> tuple[str, ...] | None:
    if not is_bpf_reg_name(src[0]):
        return None
    if is_bpf_reg_name(dst[0]) and dst[0] != "BPF_REG_10":
        return (
            f"HC_MOV64_REG({dst[0]}, {src[0]})",
            f"HC_ALU64_IMM(BPF_LSH, {dst[0]}, 32)",
            f"HC_ALU64_IMM(BPF_ARSH, {dst[0]}, 32)",
        )
    off = SHADOW_REG_OFF_BY_TOKEN.get(dst[0])
    if off is None or src[0] == "BPF_REG_6":
        return None
    return (
        f"HC_MOV64_REG(BPF_REG_6, {src[0]})",
        "HC_ALU64_IMM(BPF_LSH, BPF_REG_6, 32)",
        "HC_ALU64_IMM(BPF_ARSH, BPF_REG_6, 32)",
        f"HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, {off})",
    )


def inc8_bpf(dst: tuple[str, int, str]) -> tuple[str, ...] | None:
    if not is_bpf_reg_name(dst[0]) or dst[0] == "BPF_REG_6":
        return None
    return (
        f"HC_MOV64_REG(BPF_REG_6, {dst[0]})",
        "HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff)",
        "HC_ALU64_IMM(BPF_ADD, BPF_REG_6, 1)",
        "HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff)",
        f"HC_ALU64_IMM(BPF_AND, {dst[0]}, -256)",
        f"HC_ALU64_REG(BPF_OR, {dst[0]}, BPF_REG_6)",
    )


def machine_alu_rr_payload(dst: tuple[str, int, str], src: tuple[str, int, str]) -> str:
    macro = "HC_X86_ARCH_RR_PAYLOAD" if arch_payload((dst, src)) else "HC_X86_ALU_RR_PAYLOAD"
    return f"{macro}({dst[0]}, {src[0]})"


def machine_alu_imm_payload(dst: tuple[str, int, str], imm: int) -> str:
    macro = "HC_X86_ARCH_IMM_PAYLOAD" if is_shadow_reg_name(dst[0]) else "HC_X86_ALU_IMM_PAYLOAD"
    return f"{macro}({dst[0]}, {c_s32(imm)})"


def reg_imm_payload(reg_name: str, imm: int) -> str:
    return f"HC_REG_IMM_PAYLOAD({reg_name}, {imm})"


def x86_imm_payload(dst: tuple[str, int, str], imm: int) -> str:
    macro = "HC_X86_ARCH_IMM_PAYLOAD" if is_shadow_reg_name(dst[0]) else "HC_X86_IMM_PAYLOAD"
    return f"{macro}({dst[0]}, {imm})"


def bpf_jmp_reg(op: str, lhs: tuple[str, int, str], rhs: tuple[str, int, str]) -> str:
    cls = "BPF_JMP32" if lhs[1] == 32 else "BPF_JMP"
    return f"HC_RAW({cls} | {op} | BPF_X, {lhs[0]}, {rhs[0]}, {BRANCH_OFF}, 0)"


def bpf_jmp_imm(op: str, lhs: tuple[str, int, str], imm: int) -> str:
    cls = "BPF_JMP32" if lhs[1] == 32 else "BPF_JMP"
    return f"HC_RAW({cls} | {op} | BPF_K, {lhs[0]}, 0, {BRANCH_OFF}, {c_s32(imm)})"


def bpf_ja() -> str:
    return f"HC_RAW(BPF_JMP | BPF_JA, 0, 0, {BRANCH_OFF}, 0)"


def load_operand_to_scratch(src: tuple[str, int, str], scratch: str) -> tuple[str, ...] | None:
    if is_runtime_bpf_reg_name(src[0]):
        if src[0] == scratch:
            return ()
        return (f"HC_MOV64_REG({scratch}, {src[0]})",)
    if src[0] in SHADOW_REG_OFF_BY_TOKEN:
        selector = "MICRO_HANDCRAFT_BPF_X86_MOVQ" if src[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_MOVL"
        return (f"HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD({scratch}, {src[0]}), {selector})",)
    return None


def branch_scratch_imm(op: str, lhs: tuple[str, int, str], imm: int) -> tuple[str, ...] | None:
    load = load_operand_to_scratch(lhs, "BPF_REG_6")
    if load is None:
        return None
    cls = "BPF_JMP32" if lhs[1] == 32 else "BPF_JMP"
    return (
        *load,
        f"HC_RAW({cls} | {op} | BPF_K, BPF_REG_6, 0, 1, {c_s32(imm)})",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def branch_scratch_reg(op: str, lhs: tuple[str, int, str], rhs: tuple[str, int, str]) -> tuple[str, ...] | None:
    lhs_load = load_operand_to_scratch(lhs, "BPF_REG_6")
    rhs_load = load_operand_to_scratch(rhs, "BPF_REG_7")
    if lhs_load is None or rhs_load is None:
        return None
    cls = "BPF_JMP32" if lhs[1] == 32 else "BPF_JMP"
    return (
        *lhs_load,
        *rhs_load,
        f"HC_RAW({cls} | {op} | BPF_X, BPF_REG_6, BPF_REG_7, 1, 0)",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def mask_to_width(scratch: str, width: int) -> tuple[str, ...]:
    if width == 8:
        return (f"HC_ALU64_IMM(BPF_AND, {scratch}, 0xff)",)
    if width == 16:
        return (f"HC_ALU64_IMM(BPF_AND, {scratch}, 0xffff)",)
    return ()


def is_signed_bpf_jmp(op: str) -> bool:
    return op in {"BPF_JSGT", "BPF_JSGE", "BPF_JSLT", "BPF_JSLE"}


def sign_extend_to_width(scratch: str, width: int) -> tuple[str, ...]:
    if width == 8:
        return (
            f"HC_ALU64_IMM(BPF_LSH, {scratch}, 56)",
            f"HC_RAW(BPF_ALU64 | BPF_ARSH | BPF_K, {scratch}, 0, 0, 56)",
        )
    if width == 16:
        return (
            f"HC_ALU64_IMM(BPF_LSH, {scratch}, 48)",
            f"HC_RAW(BPF_ALU64 | BPF_ARSH | BPF_K, {scratch}, 0, 0, 48)",
        )
    if width == 32:
        return (
            f"HC_ALU64_IMM(BPF_LSH, {scratch}, 32)",
            f"HC_RAW(BPF_ALU64 | BPF_ARSH | BPF_K, {scratch}, 0, 0, 32)",
        )
    return ()


def signed_imm_to_width(imm: int, width: int) -> int:
    mask = (1 << width) - 1
    value = imm & mask
    sign = 1 << (width - 1)
    return value - (1 << width) if value & sign else value


def normalize_for_branch(scratch: str, width: int, signed: bool) -> tuple[str, ...]:
    if signed:
        return sign_extend_to_width(scratch, width)
    return mask_to_width(scratch, width)


def branch_scratch_imm_width(op: str, lhs: tuple[str, int, str], imm: int, width: int) -> tuple[str, ...] | None:
    load = load_operand_to_scratch(lhs, "BPF_REG_6")
    if load is None:
        return None
    signed = is_signed_bpf_jmp(op)
    cls = "BPF_JMP" if signed or width > 32 else "BPF_JMP32"
    cmp_imm = signed_imm_to_width(imm, width) if signed else imm
    return (
        *load,
        *normalize_for_branch("BPF_REG_6", width, signed),
        f"HC_RAW({cls} | {op} | BPF_K, BPF_REG_6, 0, 1, {c_s32(cmp_imm)})",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def branch_scratch_reg_width(op: str, lhs: tuple[str, int, str], rhs: tuple[str, int, str], width: int) -> tuple[str, ...] | None:
    lhs_load = load_operand_to_scratch(lhs, "BPF_REG_6")
    rhs_load = load_operand_to_scratch(rhs, "BPF_REG_7")
    if lhs_load is None or rhs_load is None:
        return None
    signed = is_signed_bpf_jmp(op)
    cls = "BPF_JMP" if signed or width > 32 else "BPF_JMP32"
    return (
        *lhs_load,
        *rhs_load,
        *normalize_for_branch("BPF_REG_6", width, signed),
        *normalize_for_branch("BPF_REG_7", width, signed),
        f"HC_RAW({cls} | {op} | BPF_X, BPF_REG_6, BPF_REG_7, 1, 0)",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def load_mem_to_scratch(mem_op: str, scratch: str) -> tuple[str, ...] | None:
    mem = parse_mem(mem_op)
    size = size_from_mem(mem_op)
    if mem is None or size not in {"BPF_B", "BPF_H", "BPF_W", "BPF_DW"}:
        return None
    base, index, scale, off = mem
    if base is None:
        return None
    base_reg = bpf_mem_base(base)
    if base_reg is None:
        return None
    if index is None:
        if base_reg[0] in SHADOW_REG_OFF_BY_TOKEN:
            base_load = load_operand_to_scratch((base_reg[0], 64, base_reg[2]), scratch)
            if base_load is None:
                return None
            return (*base_load, f"HC_LDX({size}, {scratch}, {scratch}, {off})")
        if not is_runtime_bpf_reg_name(base_reg[0]):
            return None
        return (f"HC_LDX({size}, {scratch}, {base_reg[0]}, {off})",)
    index_reg = bpf_reg(index)
    slog2 = scale_log2(scale)
    if (index_reg is None or slog2 is None or
            not is_runtime_bpf_reg_name(base_reg[0]) or
            not is_runtime_bpf_reg_name(index_reg[0]) or
            base_reg[0] == scratch or index_reg[0] == scratch):
        return None
    return (
        f"HC_MOV64_REG({scratch}, {index_reg[0]})",
        f"HC_ALU64_IMM(BPF_LSH, {scratch}, {slog2})",
        f"HC_ALU64_REG(BPF_ADD, {scratch}, {base_reg[0]})",
        f"HC_LDX({size}, {scratch}, {scratch}, {off})",
    )


def mem_width(mem_op: str) -> int | None:
    size = size_from_mem(mem_op)
    return {"BPF_B": 8, "BPF_H": 16, "BPF_W": 32, "BPF_DW": 64}.get(size or "")


def branch_mem_imm(op: str, mem_op: str, imm: int) -> tuple[str, ...] | None:
    load = load_mem_to_scratch(mem_op, "BPF_REG_6")
    width = mem_width(mem_op)
    if load is None or width is None:
        return None
    signed = is_signed_bpf_jmp(op)
    cls = "BPF_JMP" if signed or width > 32 else "BPF_JMP32"
    cmp_imm = signed_imm_to_width(imm, width) if signed else imm
    return (
        *load,
        *normalize_for_branch("BPF_REG_6", width, signed),
        f"HC_RAW({cls} | {op} | BPF_K, BPF_REG_6, 0, 1, {c_s32(cmp_imm)})",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def branch_mem_reg(op: str, mem_op: str, rhs: tuple[str, int, str]) -> tuple[str, ...] | None:
    load_lhs = load_mem_to_scratch(mem_op, "BPF_REG_6")
    load_rhs = load_operand_to_scratch(rhs, "BPF_REG_7")
    width = mem_width(mem_op)
    if load_lhs is None or load_rhs is None or width is None:
        return None
    signed = is_signed_bpf_jmp(op)
    cls = "BPF_JMP" if signed or width > 32 else "BPF_JMP32"
    return (
        *load_lhs,
        *load_rhs,
        *normalize_for_branch("BPF_REG_6", width, signed),
        *normalize_for_branch("BPF_REG_7", min(width, rhs[1]), signed),
        f"HC_RAW({cls} | {op} | BPF_X, BPF_REG_6, BPF_REG_7, 1, 0)",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def branch_cmp_imm(op: str, lhs: tuple[str, int, str], imm: int) -> tuple[str, ...] | None:
    if is_runtime_bpf_reg_name(lhs[0]) and lhs[1] in {32, 64}:
        return (bpf_jmp_imm(op, lhs, imm),)
    if load_operand_to_scratch(lhs, "BPF_REG_6") is not None and lhs[1] in {8, 16, 32, 64}:
        return branch_scratch_imm(op, lhs, imm)
    return None


def branch_cmp_reg(op: str, lhs: tuple[str, int, str], rhs: tuple[str, int, str]) -> tuple[str, ...] | None:
    if lhs[1] != rhs[1] or lhs[1] not in {8, 16, 32, 64}:
        return None
    if (is_runtime_bpf_reg_name(lhs[0]) and
            is_runtime_bpf_reg_name(rhs[0]) and
            lhs[1] in {32, 64}):
        return (bpf_jmp_reg(op, lhs, rhs),)
    if (load_operand_to_scratch(lhs, "BPF_REG_6") is not None and
            load_operand_to_scratch(rhs, "BPF_REG_7") is not None and
            lhs[1] in {8, 16, 32, 64}):
        return branch_scratch_reg_width(op, lhs, rhs, lhs[1])
    return None


def branch_test_imm(lhs: tuple[str, int, str], imm: int, want_set: bool) -> tuple[str, ...] | None:
    if is_runtime_bpf_reg_name(lhs[0]) and lhs[1] in {32, 64}:
        if want_set:
            return (f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, {lhs[0]}, 0, {BRANCH_OFF}, {c_s32(imm)})",)
        return (
            f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, {lhs[0]}, 0, 1, {c_s32(imm)})",
            bpf_ja(),
        )

    if lhs[1] not in {8, 16, 32, 64}:
        return None
    load = load_operand_to_scratch(lhs, "BPF_REG_6")
    if load is None:
        return None
    mask = imm & ((1 << lhs[1]) - 1)
    if want_set:
        return (
            *load,
            *mask_to_width("BPF_REG_6", lhs[1]),
            f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, {c_s32(mask)})",
            "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
            bpf_ja(),
        )
    return (
        *load,
        *mask_to_width("BPF_REG_6", lhs[1]),
        f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, {c_s32(mask)})",
        bpf_ja(),
    )


def branch_mem_test_imm(mem_op: str, imm: int, want_set: bool) -> tuple[str, ...] | None:
    load = load_mem_to_scratch(mem_op, "BPF_REG_6")
    width = mem_width(mem_op)
    if load is None or width is None:
        return None
    mask = imm & ((1 << width) - 1)
    if want_set:
        return (
            *load,
            f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, {c_s32(mask)})",
            "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
            bpf_ja(),
        )
    return (
        *load,
        f"HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, {c_s32(mask)})",
        bpf_ja(),
    )


def branch_test_sign(lhs: tuple[str, int, str], want_set: bool) -> tuple[str, ...] | None:
    sign = 1 << (lhs[1] - 1)
    return branch_test_imm(lhs, sign, want_set)


def branch_mem_test_sign(mem_op: str, want_set: bool) -> tuple[str, ...] | None:
    width = mem_width(mem_op)
    if width is None:
        return None
    return branch_mem_test_imm(mem_op, 1 << (width - 1), want_set)


def branch_test_reg(lhs: tuple[str, int, str], rhs: tuple[str, int, str], want_set: bool) -> tuple[str, ...] | None:
    if lhs[1] != rhs[1] or lhs[1] not in {8, 16, 32, 64}:
        return None
    if not is_runtime_bpf_reg_name(lhs[0]) or not is_runtime_bpf_reg_name(rhs[0]):
        return None
    lhs_load = load_operand_to_scratch(lhs, "BPF_REG_6")
    rhs_load = load_operand_to_scratch(rhs, "BPF_REG_7")
    if lhs_load is None or rhs_load is None:
        return None
    op = "BPF_JNE" if want_set else "BPF_JEQ"
    return (
        *lhs_load,
        *rhs_load,
        f"HC_ALU64_REG(BPF_AND, BPF_REG_6, BPF_REG_7)",
        *mask_to_width("BPF_REG_6", lhs[1]),
        f"HC_RAW(BPF_JMP | {op} | BPF_K, BPF_REG_6, 0, 1, 0)",
        "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
        bpf_ja(),
    )


def reg_payload(reg_name: str) -> str:
    return f"HC_REG_PAYLOAD({reg_name})"


def mem_payload_macro(base_name: str) -> str:
    return "HC_X86_ARCH_MEM_PAYLOAD" if BPF_REG_BY_X86.get(base_name, "").startswith("HC_X86_") else "HC_X86_MEM_PAYLOAD"


def store_payload_macro(base_name: str, byte_lane: bool = False) -> str:
    if BPF_REG_BY_X86.get(base_name, "").startswith("HC_X86_"):
        return "HC_X86_ARCH_STORE_BYTE_PAYLOAD" if byte_lane else "HC_X86_ARCH_STORE_PAYLOAD"
    return "HC_X86_STORE_BYTE_PAYLOAD" if byte_lane else "HC_X86_STORE_PAYLOAD"


def store_imm_payload_macro(base_name: str) -> str:
    return "HC_X86_ARCH_STORE_IMM_PAYLOAD" if BPF_REG_BY_X86.get(base_name, "").startswith("HC_X86_") else "HC_X86_STORE_IMM_PAYLOAD"


def stack_reg_payload(operand: str) -> str | None:
    parsed = reg(operand)
    if parsed is None:
        return None
    base, _width = parsed
    mapped = BPF_REG_BY_X86.get(base)
    return mapped


def size_from_mem(text: str) -> str | None:
    for key, value in SIZE_BY_PTR.items():
        if text.strip().upper().startswith(f"{key} PTR"):
            return value
    return None


def parse_mem(text: str) -> tuple[str | None, str | None, int, int] | None:
    body_match = re.search(r"\[(.*)\]", text)
    if not body_match:
        return None
    body = body_match.group(1).replace(" ", "")
    body = body.replace("-", "+-")
    base: str | None = None
    index: str | None = None
    scale = 1
    disp = 0
    for token in filter(None, body.split("+")):
        if "*" in token:
            reg_name, scale_text = token.split("*", 1)
            index = reg_name
            scale = parse_int(scale_text)
        elif token == "rip":
            base = token
        elif reg(token):
            if base is None:
                base = token
            else:
                index = token
        else:
            disp += parse_int(token)
    return base, index, scale, disp


def scale_log2(scale: int) -> int | None:
    return {1: 0, 2: 1, 4: 2, 8: 3}.get(scale)


def translate_mem_load(dst_op: str, mem_op: str, size: str) -> Translation:
    dst = bpf_reg(dst_op)
    mem = parse_mem(mem_op)
    if dst is None:
        return Translation("warning-unmapped", (), unsupported_reg_note("destination register", dst_op))
    if mem is None:
        return Translation("warning-unmapped", (), f"unsupported memory operand {mem_op}")
    base, index, scale, off = mem
    if base is None:
        return Translation("warning-unmapped", (), "RIP/absolute memory is not expressible as verifier-safe BPF memory")
    base_reg = bpf_mem_base(base)
    if base_reg is None:
        return Translation("warning-unmapped", (), unsupported_reg_note("memory base", base))
    if base_reg[2] == "rdi" and index is None and size == "BPF_DW" and off in {0, 8}:
        if CONTEXT_KIND == "skb":
            bpf_off = SKB_DATA_OFF if off == 0 else SKB_DATA_END_OFF
            note = f"native skb shim field at off {off} maps to __sk_buff u32 ctx field at off {bpf_off}"
        else:
            bpf_off = 0 if off == 0 else 4
            note = f"native xdp_md 64-bit field at off {off} maps to BPF XDP u32 ctx field at off {bpf_off}"
        code = context_load(dst, bpf_off)
        if code is None:
            return Translation("warning-unmapped", (), f"context load destination {dst_op} is not writable")
        return Translation(
            "context-abi",
            code,
            note,
        )
    if index is not None:
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"SIB index {index} scale {scale} is not expressible")
        target = {"BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL", "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL", "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL", "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ"}.get(size)
        if target is None:
            return Translation("warning-unmapped", (), f"SIB load size {size} has no current selector")
        macro = "HC_X86_ARCH_SIB_PAYLOAD" if arch_payload((dst, base_reg, index_reg)) else "HC_X86_SIB_PAYLOAD"
        payload = f"{macro}({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), "indexed memory load via x86 SIB kinsn")
    target = DIRECT_LOAD_SELECTOR.get(size)
    if target is None:
        return Translation("warning-unmapped", (), f"direct load size {size} needs a machine-level mov/load kinsn")
    payload = f"{mem_payload_macro(base_reg[2])}({dst[0]}, {base_reg[0]}, {off})"
    note = "direct memory load via x86 kinsn selector"
    return Translation(
        "exact-kinsn",
        (f"HC_KINSN({payload}, {target})",),
        note,
    )


def translate(insn: NativeInsn) -> Translation:
    op = insn.mnemonic
    ops = insn.operands
    if op in {"nop", "data16"}:
        return Translation("padding", (), "padding is not part of BPF semantics")
    if op == "cs" and ops and ops[0].startswith("nop"):
        return Translation("padding", (), "prefixed nop padding is not part of BPF semantics")
    if op == "xchg" and len(ops) == 2 and ops[0] == "ax" and ops[1] == "ax":
        return Translation("padding", (), "xchg ax,ax is nop padding")
    if op in {"push", "pop"} and len(ops) == 1:
        payload_reg = stack_reg_payload(ops[0])
        if payload_reg is None:
            return Translation("warning-unmapped", (), f"{op} operand needs x86 stack register payload support: {insn.raw}")
        selector = "MICRO_HANDCRAFT_BPF_X86_PUSHQ" if op == "push" else "MICRO_HANDCRAFT_BPF_X86_POPQ"
        return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({payload_reg}), {selector})",), f"{op}q kinsn")
    if op == "leave":
        return Translation("warning-unmapped", (), "leave needs a machine-level x86 stack/control kinsn; cannot be ignored in strict handcraft mode")
    if op == "mov" and ops in {("rbp", "rsp"), ("rsp", "rbp")}:
        dst = "HC_X86_RBP" if ops[0] == "rbp" else "HC_X86_RSP"
        src = "HC_X86_RBP" if ops[1] == "rbp" else "HC_X86_RSP"
        return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_FRAME_PAYLOAD({dst}, {src}), MICRO_HANDCRAFT_BPF_X86_MOVQ)",), "movq frame-register kinsn")
    if op == "ret":
        return Translation("abi-boundary", RETURN_CODE, "native ret materializes x86 rax to BPF r0 then exits")
    if op == "call" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            return Translation("control-flow-gap", (), f"indirect/native call has no ordinary BPF pseudo-call target: {insn.raw}")
        return Translation("abi-boundary", (f"HC_CALL({BRANCH_DELTA})",), "native direct call maps to BPF pseudo call", target_addr)
    if op in JCC_OP:
        target_addr = parse_branch_target(ops[0]) if len(ops) == 1 else None
        if target_addr is None:
            return Translation("control-flow-gap", (), f"cannot parse x86 branch target: {insn.raw}")
        return Translation("control-flow-gap", (), f"{op} needs a direct verifier-visible branch from the preceding cmp/test", target_addr)
    if op == "jmp" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            dst = bpf_reg(ops[0])
            if dst is not None and is_bpf_reg_name(dst[0]):
                return Translation("exact-bpf", (f"HC_RAW(BPF_JMP | BPF_JA | BPF_X, {dst[0]}, 0, 0, 0)",),
                                   "native indirect jmp maps to ordinary BPF indirect jump")
            return Translation("control-flow-gap", (), f"indirect jmp target is not an ordinary BPF register: {ops[0]}")
        return Translation("exact-bpf", (bpf_ja(),), "native jmp maps to ordinary BPF JA", target_addr)
    if op == "cmp" and len(ops) == 2:
        lhs = bpf_reg(ops[0])
        rhs = bpf_reg(ops[1])
        if "[" in ops[0] and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            mem = parse_mem(ops[0])
            size = size_from_mem(ops[0])
            if mem is None or size not in {"BPF_B", "BPF_W", "BPF_DW"}:
                return Translation("warning-unmapped", (), f"CMP memory immediate form has unsupported size: {insn.raw}")
            base, index, scale, off = mem
            if base is None or index is not None:
                return Translation("warning-unmapped", (), f"CMP memory immediate form is not direct base+disp: {insn.raw}")
            base_reg = bpf_mem_base(base)
            if base_reg is None:
                return Translation("warning-unmapped", (), f"CMP memory base {base} is not in the BPF register file: {insn.raw}")
            selector = {
                "BPF_B": "MICRO_HANDCRAFT_BPF_X86_CMPB",
                "BPF_H": "MICRO_HANDCRAFT_BPF_X86_CMPW",
                "BPF_W": "MICRO_HANDCRAFT_BPF_X86_CMPL",
                "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_CMPQ",
            }[size]
            macro = "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" if is_shadow_reg_name(base_reg[0]) else "HC_X86_CMP_MEM_IMM_PAYLOAD"
            payload = f"{macro}({base_reg[0]}, {off}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), "cmp memory,imm kinsn")
        if "[" in ops[0] and rhs and rhs[1] == 64:
            mem = parse_mem(ops[0])
            size = size_from_mem(ops[0])
            if mem is None or size != "BPF_DW":
                return Translation("warning-unmapped", (), f"CMP memory source is not a qword operand: {insn.raw}")
            base, index, scale, off = mem
            if base is None or index is None:
                return Translation("warning-unmapped", (), f"CMP memory source is not indexed SIB: {insn.raw}")
            base_reg = bpf_mem_base(base)
            index_reg = bpf_reg(index)
            slog2 = scale_log2(scale)
            if base_reg is None or index_reg is None or slog2 is None:
                return Translation("warning-unmapped", (), f"CMP SIB operand is not in the BPF register file: {insn.raw}")
            payload = f"HC_X86_CMP_SIB_RR_PAYLOAD({base_reg[0]}, {index_reg[0]}, {slog2}, {off}, {rhs[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ)",), "cmpq SIB memory-source kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 64:
            payload = reg_reg_payload(lhs, rhs)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ)",), "cmpq reg,reg kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 32:
            payload = reg_reg_payload(lhs, rhs)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL)",), "cmpl reg,reg kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 16:
            payload = reg_reg_payload(lhs, rhs)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPW)",), "cmpw reg,reg kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 8:
            payload = reg_reg_payload(lhs, rhs)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPB)",), "cmpb reg,reg kinsn")
        if lhs and lhs[1] == 64 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = x86_imm_payload(lhs, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ)",), "cmpq reg,imm32 kinsn")
        if lhs and lhs[1] == 32 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = x86_imm_payload(lhs, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL)",), "cmpl reg,imm32 kinsn")
        if lhs and lhs[1] == 16 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = x86_imm_payload(lhs, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPW)",), "cmpw reg,imm16 kinsn")
        if lhs and lhs[1] == 8 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = x86_imm_payload(lhs, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPB)",), "cmpb reg,imm8 kinsn")
        return Translation("warning-unmapped", (), f"CMP operand form has no current kinsn selector: {insn.raw}")
    if len(ops) == 2 and op in {"mov", "movabs"}:
        dst, src = ops
        dst_reg = bpf_reg(dst)
        src_reg = bpf_reg(src)
        if dst_reg and src_reg:
            if dst_reg[1] == 64 and src_reg[1] == 64:
                payload = reg_reg_payload(dst_reg, src_reg)
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVQ)",),
                    "movq register-to-register kinsn",
                )
            if dst_reg[1] == 32 and src_reg[1] == 32:
                payload = reg_reg_payload(dst_reg, src_reg)
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVL)",),
                    "movl register-to-register kinsn",
                )
            return Translation("warning-unmapped", (), f"mixed-width register move {dst}, {src}")
        if dst_reg and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", src):
            imm = parse_int(src)
            if op == "movabs" or dst_reg[1] == 64 and abs(imm) > 0x7fffffff:
                code = movabs_bpf(dst_reg, imm)
                if code is None:
                    return Translation("warning-unmapped", (), f"movabs into {dst_reg[0]} needs a writable x86 shadow slot")
                return Translation("exact-bpf", code, "movabs via verifier-visible BPF immediate load")
            if dst_reg[1] == 32:
                payload = x86_imm_payload(dst_reg, imm)
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVL)",), "movl immediate kinsn")
            if dst_reg[1] == 64:
                payload = x86_imm_payload(dst_reg, imm)
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVQ)",), "movq immediate kinsn")
            if dst_reg[1] == 8:
                payload = x86_imm_payload(dst_reg, imm)
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVB)",), "movb immediate kinsn")
            return Translation("warning-unmapped", (), f"mov immediate width {dst_reg[1]} needs a consolidated mov kinsn form")
        mem_size = size_from_mem(src) or ("BPF_DW" if dst_reg and dst_reg[1] == 64 else "BPF_W")
        if dst_reg and "[" in src:
            return translate_mem_load(dst, src, mem_size)
        if "[" in dst and src_reg:
            mem = parse_mem(dst)
            size = size_from_mem(dst) or ("BPF_DW" if src_reg[1] == 64 else "BPF_W")
            if mem is None or mem[1] is not None:
                return Translation("warning-unmapped", (), f"store operand {dst} is not a direct base+disp memory reference")
            base = bpf_mem_base(mem[0])
            if base is None:
                return Translation("warning-unmapped", (), unsupported_reg_note("store base", mem[0] or "absolute"))
            if CONTEXT_KIND == "skb" and base[2] == "rdi" and size == "BPF_W" and mem[3] in {16, 20}:
                bpf_off = SKB_CB0_OFF if mem[3] == 16 else SKB_CB1_OFF
                payload = f"{store_payload_macro(base[2])}({src_reg[0]}, {base[0]}, {bpf_off})"
                return Translation(
                    "context-abi",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVL)",),
                    f"native skb shim cb store at off {mem[3]} maps to __sk_buff cb field at off {bpf_off}",
                )
            target = DIRECT_STORE_SELECTOR.get(size)
            if target is None:
                return Translation("warning-unmapped", (), f"store size {size} needs a machine-level mov/store kinsn")
            if size == "BPF_B" and byte_lane(src):
                payload = f"{store_payload_macro(base[2], True)}({src_reg[0]}, {base[0]}, {mem[3]}, 1)"
            else:
                payload = f"{store_payload_macro(base[2])}({src_reg[0]}, {base[0]}, {mem[3]})"
            note = "direct memory store via x86 kinsn selector"
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN({payload}, {target})",),
                note,
            )
        if "[" in dst and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", src):
            mem = parse_mem(dst)
            size = size_from_mem(dst) or "BPF_W"
            if mem is None or mem[1] is not None:
                return Translation("warning-unmapped", (), f"store operand {dst} is not a direct base+disp memory reference")
            base = bpf_mem_base(mem[0])
            if base is None:
                return Translation("warning-unmapped", (), unsupported_reg_note("store base", mem[0] or "absolute"))
            imm = parse_int(src)
            if CONTEXT_KIND == "skb" and base[2] == "rdi" and size == "BPF_W" and mem[3] in {16, 20}:
                bpf_off = SKB_CB0_OFF if mem[3] == 16 else SKB_CB1_OFF
                return Translation(
                    "context-abi",
                    (f"HC_KINSN({store_imm_payload_macro(base[2])}({base[0]}, {bpf_off}, {imm}), MICRO_HANDCRAFT_BPF_X86_MOVL)",),
                    f"native skb shim cb store at off {mem[3]} maps to __sk_buff cb field at off {bpf_off}",
                )
            if size == "BPF_B":
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({store_imm_payload_macro(base[2])}({base[0]}, {mem[3]}, {imm}), MICRO_HANDCRAFT_BPF_X86_MOVB)",),
                    "movb immediate memory store via x86 kinsn selector",
                )
            target = DIRECT_STORE_SELECTOR.get(size)
            if target is not None:
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({store_imm_payload_macro(base[2])}({base[0]}, {mem[3]}, {imm}), {target})",),
                    "mov immediate memory store via x86 kinsn selector",
                )
            return Translation("warning-unmapped", (), f"mov immediate store size {size} needs a machine-level store-immediate kinsn")
    if op == "movzx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] in {8, 16}:
            selector = "MICRO_HANDCRAFT_BPF_X86_MOVZBL" if src[1] == 8 else "MICRO_HANDCRAFT_BPF_X86_MOVZWL"
            return Translation("exact-kinsn", (f"HC_KINSN({reg_reg_payload(dst, src)}, {selector})",), f"movzx r32,r{src[1]} kinsn")
        size = size_from_mem(ops[1])
        if size not in {"BPF_B", "BPF_H"}:
            return Translation("warning-unmapped", (), f"movzx source size not recognized: {ops[1]}")
        return translate_mem_load(ops[0], ops[1], size)
    if op == "movsx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] == 16:
            return Translation("exact-kinsn", (f"HC_KINSN({reg_reg_payload(dst, src)}, MICRO_HANDCRAFT_BPF_X86_MOVSWL)",), "movswl reg kinsn")
        return Translation("warning-unmapped", (), f"movsx operands are not supported: {insn.raw}")
    if op == "movsxd" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst is None or dst[1] != 64:
            return Translation("warning-unmapped", (), f"movsxd destination {ops[0]} is not a 64-bit BPF JIT register")
        src = bpf_reg(ops[1])
        if src is not None and src[1] == 32:
            code = sign_extend_32_to_64_bpf(dst, src)
            if code is None:
                return Translation("warning-unmapped", (), f"movsxd {ops[0]}, {ops[1]} needs a verifier-visible scratch form")
            return Translation("exact-bpf", code, "movsxd reg32 via verifier-visible BPF sign extension")
        mem = parse_mem(ops[1])
        size = size_from_mem(ops[1])
        if mem is None or size != "BPF_W":
            return Translation("warning-unmapped", (), f"movsxd source is not a DWORD memory operand: {ops[1]}")
        base, index, scale, off = mem
        if base is None or index is None:
            return Translation("warning-unmapped", (), f"movsxd memory source is not indexed SIB: {ops[1]}")
        base_reg = bpf_mem_base(base)
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if base_reg is None or index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"movsxd SIB operand is not in the BPF register file: {ops[1]}")
        macro = "HC_X86_ARCH_SIB_PAYLOAD" if arch_payload((dst, base_reg, index_reg)) else "HC_X86_SIB_PAYLOAD"
        payload = f"{macro}({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVSXD)",), "movsxd SIB kinsn")
    if op == "lea" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        mem = parse_mem(ops[1])
        if dst is None or mem is None:
            return Translation("warning-unmapped", (), "LEA operands are not representable")
        base, index, scale, disp = mem
        base_reg = bpf_reg(base) if base else None
        index_reg = bpf_reg(index) if index else None
        slog2 = scale_log2(scale)
        if (base and base_reg is None) or (index and index_reg is None) or slog2 is None:
            return Translation("warning-unmapped", (), f"LEA base/index not in BPF register file: {ops[1]}")
        target = "MICRO_HANDCRAFT_BPF_X86_LEAQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_LEAL"
        note = "LEA via x86 kinsn selector"
        macro = "HC_LEA_ARCH_PAYLOAD" if arch_payload(tuple(item for item in (dst, base_reg, index_reg) if item)) else "HC_LEA_PAYLOAD"
        payload = (
            f"{macro}({dst[0]}, {base_reg[0] if base_reg else 0}, "
            f"{index_reg[0] if index_reg else 0}, {slog2}, {1 if base_reg else 0}, "
            f"{1 if index_reg else 0}, {disp})"
        )
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), note)
    if op == "rol" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst and ops[1].lower() == "cl" and dst[1] in {32, 64}:
            selector = "MICRO_HANDCRAFT_BPF_X86_ROLQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_ROLL"
            width = "q" if dst[1] == 64 else "l"
            macro = "HC_ROTATE_ARCH_CL_PAYLOAD" if is_shadow_reg_name(dst[0]) else "HC_ROTATE_CL_PAYLOAD"
            return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, HC_X86_RCX), {selector})",), f"rol{width} cl kinsn")
        if dst and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            macro = "HC_ROTATE_ARCH_PAYLOAD" if is_shadow_reg_name(dst[0]) else "HC_ROTATE_PAYLOAD"
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLQ)",), "rolq imm kinsn")
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLL)",), "roll imm kinsn")
            if dst[1] == 16 and parse_int(ops[1]) == 8:
                reg_imm = "HC_REG_IMM_ARCH_PAYLOAD" if is_shadow_reg_name(dst[0]) else "HC_REG_IMM_PAYLOAD"
                return Translation("exact-kinsn", (f"HC_KINSN({reg_imm}({dst[0]}, 8), MICRO_HANDCRAFT_BPF_X86_ROLW)",), "rolw imm8 kinsn")
        return Translation("warning-unmapped", (), f"ROL width/register not supported by current selectors: {ops[0]}")
    if op == "popcnt" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            if arch_payload((dst, src)):
                return Translation("warning-unmapped", (), arch_reg_note(insn))
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_POPCNTQ)",), "popcntq kinsn")
        return Translation("warning-unmapped", (), "only popcntq reg,reg is supported")
    if op == "imul" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            if arch_payload((dst, src)):
                return Translation("warning-unmapped", (), arch_reg_note(insn))
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_IMULQ)",), "imulq reg,reg kinsn")
        return Translation("warning-unmapped", (), f"IMUL operands are not in the 64-bit BPF JIT register file: {insn.raw}")
    if op == "not" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if not dst:
            return Translation("warning-unmapped", (), unsupported_reg_note("NOT destination", ops[0]))
        if dst[2] == "rbp":
            return Translation("warning-unmapped", (), arch_reg_note(insn))
        if dst[1] == 8:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_NOT_NARROW_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTB)",), "notb reg kinsn")
        if dst[1] == 16:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_NOT_NARROW_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTW)",), "notw reg kinsn")
        if dst[1] == 32:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTL)",), "notl reg kinsn")
        if dst[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTQ)",), "notq reg kinsn")
        return Translation("warning-unmapped", (), f"NOT width not supported: {ops[0]}")
    if op == "bswap" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if not dst:
            return Translation("warning-unmapped", (), unsupported_reg_note("BSWAP destination", ops[0]))
        if dst[2] == "rbp":
            return Translation("warning-unmapped", (), arch_reg_note(insn))
        payload = reg_payload(dst[0])
        if dst[1] == 32:
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_BSWAPL)",), "bswapl kinsn")
        if dst[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_BSWAPQ)",), "bswapq kinsn")
        return Translation("warning-unmapped", (), f"BSWAP width not supported: {ops[0]}")
    if op in {"shld", "shrd"} and len(ops) == 3:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if not dst or not src:
            return Translation("warning-unmapped", (), f"{op.upper()} operands need explicit native-register payload support: {insn.raw}")
        if dst[1] != src[1] or dst[1] not in {32, 64}:
            return Translation("warning-unmapped", (), f"{op.upper()} width is not supported: {insn.raw}")
        if not re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[2]):
            return Translation("warning-unmapped", (), f"{op.upper()} count is not an immediate: {insn.raw}")
        if op == "shld":
            selector = "MICRO_HANDCRAFT_BPF_X86_SHLDQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHLDL"
        else:
            selector = "MICRO_HANDCRAFT_BPF_X86_SHRDQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHRDL"
        macro = "HC_SHD_ARCH_PAYLOAD" if arch_payload((dst, src)) else "HC_SHD_PAYLOAD"
        return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, {src[0]}, {parse_int(ops[2])}), {selector})",), f"{op} imm kinsn")
    if op in ALU_OP and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst is None:
            return Translation("warning-unmapped", (), unsupported_reg_note("ALU destination", ops[0]))
        bpf_class = "BPF_ALU64" if dst[1] == 64 else "BPF_ALU"
        selector = MACHINE_ALU_SELECTOR.get((op, dst[1]))
        if src and selector:
            if op in {"shl", "shr"}:
                if src[2] != "rcx" or src[1] != 8:
                    return Translation("warning-unmapped", (), f"{op.upper()} variable count must be CL: {insn.raw}")
            elif dst[1] != src[1]:
                return Translation("warning-unmapped", (), f"{op.upper()} width is not supported: {insn.raw}")
            payload = machine_alu_rr_payload(dst, src)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} reg kinsn")
        if selector and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = machine_alu_imm_payload(dst, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} imm kinsn")
        if op == "xor" and src and dst[0] == src[0]:
            if dst[1] == 32:
                payload = machine_alu_rr_payload(dst, src)
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORL)",), "xorl zero-idiom kinsn")
            if dst[1] == 8:
                return Translation("exact-kinsn", (f"HC_KINSN({reg_reg_payload(dst, src)}, MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb zero-idiom kinsn")
            if is_shadow_reg_name(dst[0]):
                return Translation("warning-unmapped", (), f"{insn.raw} needs a shadow-aware xor kinsn")
            return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level xor zero-idiom kinsn")
        if op == "and" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"andb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {imm}), MICRO_HANDCRAFT_BPF_X86_ANDB)",), "andb imm kinsn")
        if op == "xor" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"xorb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN({x86_imm_payload(dst, imm)}, MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb imm kinsn")
        if op == "xor" and dst[1] == 8 and src:
            return Translation("exact-kinsn", (f"HC_KINSN({reg_reg_payload(dst, src)}, MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb reg kinsn")
        if op == "or" and dst[1] == 8 and src:
            payload = byte_reg_reg_payload(dst[0], src[0])
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_ORB)",), "orb reg kinsn")
        if src:
            if is_shadow_reg_name(dst[0]) or is_shadow_reg_name(src[0]):
                return Translation("warning-unmapped", (), f"{insn.raw} needs a shadow-aware ALU kinsn")
            return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level ALU register kinsn")
        if re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            if is_shadow_reg_name(dst[0]):
                return Translation("warning-unmapped", (), f"{insn.raw} needs a shadow-aware ALU immediate kinsn")
            return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level ALU immediate kinsn")
        if "[" in ops[1]:
            mem = parse_mem(ops[1])
            size = size_from_mem(ops[1]) or ("BPF_DW" if dst[1] == 64 else "BPF_W")
            if mem is None:
                return Translation("warning-unmapped", (), f"ALU memory source is not parseable: {ops[1]}")
            base, index, scale, off = mem
            if base is None:
                return Translation("warning-unmapped", (), "ALU RIP/absolute memory source is not verifier-safe BPF memory")
            base_reg = bpf_mem_base(base)
            if base_reg is None:
                return Translation("warning-unmapped", (), unsupported_reg_note("ALU memory base", base))
            if index is None and selector and dst[1] in {32, 64} and size == ("BPF_DW" if dst[1] == 64 else "BPF_W"):
                payload = f"{mem_payload_macro(base_reg[2])}({dst[0]}, {base_reg[0]}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} memory-source kinsn")
            if index is None and op == "xor" and dst[1] == 16 and size == "BPF_H":
                payload = f"{mem_payload_macro(base_reg[2])}({dst[0]}, {base_reg[0]}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORW)",), "xorw memory-source kinsn")
            if index is not None and selector and dst[1] in {32, 64} and size == ("BPF_DW" if dst[1] == 64 else "BPF_W"):
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                macro = "HC_X86_ARCH_SIB_PAYLOAD" if arch_payload((dst, base_reg, index_reg)) else "HC_X86_SIB_PAYLOAD"
                payload = f"{macro}({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} SIB memory-source kinsn")
            if index is not None and op == "xor" and dst[1] == 8 and size == "BPF_B":
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                macro = "HC_X86_ARCH_SIB_PAYLOAD" if arch_payload((dst, base_reg, index_reg)) else "HC_X86_SIB_PAYLOAD"
                payload = f"{macro}({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb SIB memory-source kinsn")
            return Translation("warning-unmapped", (), f"ALU memory source form has no current selector: {insn.raw}")
        return Translation("warning-unmapped", (), f"ALU source {ops[1]} is not supported")
    if op == "sar" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst is None:
            return Translation("warning-unmapped", (), unsupported_reg_note("SAR destination", ops[0]))
        if not re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("warning-unmapped", (), f"SAR source {ops[1]} is not an immediate")
        selector = MACHINE_ALU_SELECTOR.get(("sar", dst[1]))
        if selector:
            payload = machine_alu_imm_payload(dst, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"sar{dst[1]} imm kinsn")
        return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level sar kinsn")
    if op == "test" and len(ops) == 2:
        left = bpf_reg(ops[0])
        right = bpf_reg(ops[1])
        if "[" in ops[0] and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            mem = parse_mem(ops[0])
            size = size_from_mem(ops[0])
            if mem is None or size != "BPF_B":
                return Translation("warning-unmapped", (), f"test memory immediate form has unsupported size: {insn.raw}")
            base, index, scale, off = mem
            if base is None or index is not None:
                return Translation("warning-unmapped", (), f"test memory immediate form is not direct base+disp: {insn.raw}")
            base_reg = bpf_mem_base(base)
            if base_reg is None:
                return Translation("warning-unmapped", (), f"test memory base {base} is not in the BPF register file: {insn.raw}")
            macro = "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" if is_shadow_reg_name(base_reg[0]) else "HC_X86_CMP_MEM_IMM_PAYLOAD"
            payload = f"{macro}({base_reg[0]}, {off}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB)",), "testb memory,imm kinsn")
        if left and right and left[0] == right[0] and left[1] == 64:
            payload = reg_reg_payload(left, right)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTQ)",), "testq reg,reg kinsn")
        if left and right and left[1] == right[1] == 32:
            payload = reg_reg_payload(left, right)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTL)",), "testl reg,reg kinsn")
        if left and right and left[1] == right[1] == 16:
            payload = reg_reg_payload(left, right)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTW)",), "testw reg,reg kinsn")
        if left and right and left[1] == right[1] == 8:
            payload = reg_reg_payload(left, right)
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB)",), "testb reg,reg kinsn")
        if left and left[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = x86_imm_payload(left, parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB)",), "testb imm kinsn")
        return Translation("warning-unmapped", (), f"test operand form needs a machine-level test kinsn: {insn.raw}")
    if op == "inc" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if dst:
            if dst[2] == "rbp":
                return Translation("warning-unmapped", (), arch_reg_note(insn))
            if dst[1] == 8:
                code = inc8_bpf(dst)
                if code is None:
                    return Translation("warning-unmapped", (), f"incb {ops[0]} needs a verifier-visible scratch form")
                return Translation("exact-bpf", code, "incb via verifier-visible BPF low-byte update")
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCL)",), "incl reg kinsn")
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCQ)",), "incq reg kinsn")
            return Translation("warning-unmapped", (), f"inc width {dst[1]} needs a machine-level inc kinsn")
        return Translation("warning-unmapped", (), unsupported_reg_note("INC destination", ops[0]))
    if op == "div" and len(ops) == 1:
        src = bpf_reg(ops[0])
        if src and src[1] == 32:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({src[0]}), MICRO_HANDCRAFT_BPF_X86_DIVL)",), "divl reg kinsn")
        return Translation("warning-unmapped", (), f"DIV operand form needs a machine-level divl kinsn: {insn.raw}")
    if op in {"cmovne", "cmove", "cmovb"} and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == src[1] and dst[1] in {32, 64}:
            selector = {
                ("cmovne", 32): "MICRO_HANDCRAFT_BPF_X86_CMOVNEL",
                ("cmovne", 64): "MICRO_HANDCRAFT_BPF_X86_CMOVNEQ",
                ("cmove", 32): "MICRO_HANDCRAFT_BPF_X86_CMOVEL",
                ("cmove", 64): "MICRO_HANDCRAFT_BPF_X86_CMOVEQ",
                ("cmovb", 32): "MICRO_HANDCRAFT_BPF_X86_CMOVBL",
                ("cmovb", 64): "MICRO_HANDCRAFT_BPF_X86_CMOVBQ",
            }[(op, dst[1])]
            macro = "HC_CMOV_ARCH_STACK_PAYLOAD" if arch_payload((dst, src)) else "HC_CMOV_STACK_PAYLOAD"
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN({macro}({dst[0]}, {src[0]}), {selector})",),
                "cmov kinsn using module shadow flags",
            )
        return Translation("warning-unmapped", (), f"{op} operands are not supported")
    if op in {"sete", "setne", "setge"} and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if dst:
            if dst[2] == "rbp":
                return Translation("warning-unmapped", (), arch_reg_note(insn))
            selector = {
                "sete": "MICRO_HANDCRAFT_BPF_X86_SETE",
                "setne": "MICRO_HANDCRAFT_BPF_X86_SETNE",
                "setge": "MICRO_HANDCRAFT_BPF_X86_SETGE",
            }[op]
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_SETCC_STACK_PAYLOAD({dst[0]}), {selector})",),
                "setcc kinsn using module shadow flags",
            )
        return Translation("warning-unmapped", (), unsupported_reg_note("SETcc destination", ops[0]))
    if op == "sbb" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst and dst[1] == 32 and is_int(ops[1]) and parse_int(ops[1]) == 0:
            if dst[2] == "rbp":
                return Translation("warning-unmapped", (), arch_reg_note(insn))
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_X86_ALU_IMM_PAYLOAD({dst[0]}, 0), MICRO_HANDCRAFT_BPF_X86_SBBL)",),
                "sbbl imm0 kinsn using module shadow CF",
            )
        return Translation("warning-unmapped", (), f"SBB operand form has no current kinsn selector: {insn.raw}")
    return Translation("warning-unmapped", (), f"unsupported mnemonic or operand form: {insn.raw}")


def direct_bpf_jcc_from_cmp(branch: NativeInsn, producer: NativeInsn) -> tuple[str, ...] | None:
    if branch.mnemonic not in JCC_OP or producer.mnemonic != "cmp" or len(producer.operands) != 2:
        return None
    if branch.mnemonic not in {"ja", "jae", "jb", "jbe", "je", "jne", "jg", "jge", "jl", "jle"}:
        return None
    op = JCC_OP[branch.mnemonic]
    if "[" in producer.operands[0]:
        rhs_reg = bpf_reg(producer.operands[1])
        if rhs_reg is not None:
            return branch_mem_reg(op, producer.operands[0], rhs_reg)
        if is_int(producer.operands[1]):
            return branch_mem_imm(op, producer.operands[0], parse_int(producer.operands[1]))
        return None
    lhs = bpf_reg(producer.operands[0])
    rhs = bpf_reg(producer.operands[1])
    if lhs is not None and rhs is not None:
        return branch_cmp_reg(op, lhs, rhs)
    if lhs is not None and lhs[1] in {8, 16, 32, 64} and is_int(producer.operands[1]):
        return branch_cmp_imm(op, lhs, parse_int(producer.operands[1]))
    return None


def direct_bpf_jcc_from_test(branch: NativeInsn, producer: NativeInsn) -> tuple[str, ...] | None:
    if producer.mnemonic != "test" or len(producer.operands) != 2:
        return None
    if "[" in producer.operands[0] and is_int(producer.operands[1]):
        imm = parse_int(producer.operands[1])
        if branch.mnemonic == "jne":
            return branch_mem_test_imm(producer.operands[0], imm, True)
        if branch.mnemonic == "je":
            return branch_mem_test_imm(producer.operands[0], imm, False)
        if branch.mnemonic == "js":
            return branch_mem_test_sign(producer.operands[0], True)
        if branch.mnemonic == "jns":
            return branch_mem_test_sign(producer.operands[0], False)
        return None
    lhs = bpf_reg(producer.operands[0])
    rhs = bpf_reg(producer.operands[1])
    if lhs is not None and rhs is not None and lhs[1] == rhs[1] and lhs[1] in {8, 16, 32, 64}:
        if branch.mnemonic == "je":
            if lhs[0] == rhs[0]:
                return branch_test_imm(lhs, (1 << lhs[1]) - 1, False)
            return branch_test_reg(lhs, rhs, False)
        if branch.mnemonic == "jne":
            if lhs[0] == rhs[0]:
                return branch_test_imm(lhs, (1 << lhs[1]) - 1, True)
            return branch_test_reg(lhs, rhs, True)
        if branch.mnemonic == "js":
            return branch_test_sign(lhs, True)
        if branch.mnemonic == "jns":
            return branch_test_sign(lhs, False)
    if lhs is not None and lhs[1] in {8, 16, 32, 64} and is_int(producer.operands[1]):
        imm = parse_int(producer.operands[1])
        if branch.mnemonic == "jne":
            return branch_test_imm(lhs, imm, True)
        if branch.mnemonic == "je":
            return branch_test_imm(lhs, imm, False)
        if branch.mnemonic == "js":
            return branch_test_sign(lhs, True)
        if branch.mnemonic == "jns":
            return branch_test_sign(lhs, False)
    return None


def direct_bpf_jcc_from_result(branch: NativeInsn, producer: NativeInsn) -> tuple[str, ...] | None:
    if len(producer.operands) < 1:
        return None
    dst = bpf_reg(producer.operands[0])
    if dst is None:
        return None
    if branch.mnemonic == "je":
        return branch_test_imm(dst, (1 << dst[1]) - 1, False)
    if branch.mnemonic == "jne":
        return branch_test_imm(dst, (1 << dst[1]) - 1, True)
    if branch.mnemonic == "js":
        return branch_test_sign(dst, True)
    if branch.mnemonic == "jns":
        return branch_test_sign(dst, False)
    return None


def direct_bpf_jcc(branch: NativeInsn, producer: NativeInsn | None) -> tuple[str, ...] | None:
    if producer is None:
        return None
    code: tuple[str, ...] | None
    if producer.mnemonic == "cmp":
        code = direct_bpf_jcc_from_cmp(branch, producer)
    elif producer.mnemonic == "test":
        code = direct_bpf_jcc_from_test(branch, producer)
    elif producer.mnemonic in ALU_OP or producer.mnemonic in {"inc", "sar"}:
        code = direct_bpf_jcc_from_result(branch, producer)
    else:
        return None
    if code is None:
        return None
    return code


INVERT_BPF_JMP_OP = {
    "BPF_JEQ": "BPF_JNE",
    "BPF_JNE": "BPF_JEQ",
    "BPF_JGT": "BPF_JLE",
    "BPF_JGE": "BPF_JLT",
    "BPF_JLT": "BPF_JGE",
    "BPF_JLE": "BPF_JGT",
    "BPF_JSGT": "BPF_JSLE",
    "BPF_JSGE": "BPF_JSLT",
    "BPF_JSLT": "BPF_JSGE",
    "BPF_JSLE": "BPF_JSGT",
}


def set_branch_off(code: str, off: int) -> str:
    if BRANCH_OFF in code:
        return code.replace(BRANCH_OFF, str(off))
    return re.sub(r",\s*-?\d+\s*,\s*([^,()]+)\)$", rf", {off}, \1)", code)


def invert_branch_code(code: str) -> str | None:
    for op, inverted in INVERT_BPF_JMP_OP.items():
        marker = f"| {op} |"
        if marker in code:
            return set_branch_off(code.replace(marker, f"| {inverted} |", 1), RETURN_BPF_LEN)
    return None


def translate_all(insns: list[NativeInsn]) -> list[Translation]:
    translations: list[Translation] = []
    flag_producer: tuple[int, NativeInsn] | None = None
    for index, insn in enumerate(insns):
        trans = translate(insn)
        if insn.mnemonic in JCC_OP:
            if flag_producer is None:
                trans = Translation("control-flow-gap", (), f"{insn.mnemonic} has no verifier-visible flag producer", trans.target_addr)
            else:
                producer_index, producer = flag_producer
                code = direct_bpf_jcc(insn, producer)
                if code is not None:
                    trans = Translation("exact-bpf", code,
                                        f"{insn.mnemonic} ordinary BPF branch from preceding {producer.mnemonic}",
                                        trans.target_addr)
                    if producer.mnemonic in {"cmp", "test"} and producer_index == index - 1:
                        translations[producer_index] = Translation(
                            "absorbed-control-flow",
                            (),
                            f"{producer.mnemonic} folded into following ordinary BPF {insn.mnemonic}",
                        )
                else:
                    trans = Translation("control-flow-gap", (), f"{insn.mnemonic} after {producer.mnemonic} has no direct BPF branch form", trans.target_addr)
        translations.append(trans)
        if insn.mnemonic in {"cmp", "test"}:
            flag_producer = (index, insn)
        elif insn.mnemonic in ALU_OP or insn.mnemonic in {"inc", "shl", "shr", "sar"}:
            flag_producer = (index, insn)
        elif insn.mnemonic in {"imul", "popcnt", "sbb", "rol", "div"}:
            flag_producer = None
    return translations


def localize_exit_targets(insns: list[NativeInsn], translations: list[Translation]) -> list[Translation]:
    exit_targets = {
        insn.addr
        for insn, trans in zip(insns, translations, strict=True)
        if trans.code and trans.code[-1] == "HC_EXIT()"
    }
    localized: list[Translation] = []
    for trans in translations:
        if trans.target_addr not in exit_targets:
            localized.append(trans)
            continue
        if trans.code == (bpf_ja(),):
            localized.append(Translation(trans.status, RETURN_CODE, trans.note, None))
            continue
        if len(trans.code) == 1 and BRANCH_OFF in trans.code[0]:
            inverted = invert_branch_code(trans.code[0])
            if inverted is not None:
                localized.append(Translation(
                    trans.status,
                    (inverted, *RETURN_CODE),
                    trans.note,
                    None,
                ))
                continue
            localized.append(Translation(
                trans.status,
                (
                    trans.code[0].replace(BRANCH_OFF, "1"),
                    "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)",
                    *RETURN_CODE,
                ),
                trans.note,
                None,
            ))
            continue
        if trans.code and trans.code[-1] == bpf_ja():
            if len(trans.code) >= 3 and trans.code[-2] == "HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0)":
                inverted = invert_branch_code(trans.code[-3])
                if inverted is not None:
                    localized.append(Translation(
                        trans.status,
                        (*trans.code[:-3], inverted, *RETURN_CODE),
                        trans.note,
                        None,
                    ))
                    continue
            localized.append(Translation(
                trans.status,
                (*trans.code[:-1], *RETURN_CODE),
                trans.note,
                None,
            ))
            continue
        localized.append(trans)
    return localized



def bpf_insn_len(code: str) -> int:
    if code.startswith("HC_INIT_X86_STACK("):
        return 3
    if code.startswith("HC_LD_IMM64_RAW("):
        return 2
    if code.startswith("HC_KINSN("):
        return 2
    return 1


def relocate_branch_offsets(insns: list[NativeInsn], translations: list[Translation]) -> list[Translation]:
    pc_by_addr: dict[int, int] = {}
    pc_by_index: list[int] = []
    bpf_lens: list[int] = []
    pc = 0
    for index, (insn, trans) in enumerate(zip(insns, translations, strict=True)):
        pc_by_addr.setdefault(insn.addr, pc)
        pc_by_index.append(pc)
        bpf_len = sum(bpf_insn_len(code) for code in trans.code)
        bpf_lens.append(bpf_len)
        pc += bpf_len

    patched: list[Translation] = []
    for index, trans in enumerate(translations):
        if trans.target_addr is None:
            patched.append(trans)
            continue
        target_pc = pc_by_addr.get(trans.target_addr)
        if target_pc is None:
            if trans.status in {"abi-boundary", "exact-bpf"}:
                patched.append(Translation(
                    "control-flow-gap",
                    (),
                    f"{trans.note}; target 0x{trans.target_addr:x} is outside parsed asm",
                    trans.target_addr,
                ))
                continue
            patched.append(Translation(
                "warning-unmapped",
                (),
                f"{trans.note}; branch target 0x{trans.target_addr:x} is outside parsed asm",
                trans.target_addr,
            ))
            continue
        code = []
        code_pc = pc_by_index[index]
        for item in trans.code:
            if item.startswith("HC_KINSN("):
                if BRANCH_DELTA in item:
                    raise ValueError(f"kinsn payload cannot carry program branch target: 0x{insns[index].addr:x}")
                delta = 0
            else:
                delta = target_pc - code_pc
            code.append(item.replace(BRANCH_DELTA, str(delta)))
            code_pc += bpf_insn_len(item)
        code = tuple(code)
        patched.append(Translation(trans.status, code, trans.note, trans.target_addr))
    return patched


def write_outputs(insns: list[NativeInsn], translations: list[Translation], output: Path) -> None:
    warnings = sum(1 for item in translations if item.status.startswith("warning"))
    output_lines = [
        '#include "handcraft_common.h"',
        "",
        "#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \\",
        "    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \\",
        "     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \\",
        "     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))",
        "#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \\",
        "    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))",
        "",
    ]
    if warnings:
        output_lines.extend([
            "/*",
            f" * native asm to handcraft warnings: {warnings}",
            " *",
        ])
        for insn, trans in zip(insns, translations, strict=True):
            if trans.status.startswith("warning"):
                output_lines.append(f" * - 0x{insn.addr:x}: {insn.raw} [{trans.status}: {trans.note}]")
        output_lines.extend([" */", ""])
    output_lines.append("static const struct bpf_insn program[] = {")
    output_lines.extend([
        "    HC_INIT_X86_STACK(),",
        "    HC_MOV64_IMM(BPF_REG_6, 0),",
        "    HC_MOV64_IMM(BPF_REG_7, 0),",
        "    HC_MOV64_IMM(BPF_REG_8, 0),",
        "    HC_MOV64_IMM(BPF_REG_9, 0),",
    ])
    for insn, trans in zip(insns, translations, strict=True):
        prefix = f"    /* 0x{insn.addr:x}: {insn.raw} [{trans.status}: {trans.note}] */"
        output_lines.append(prefix)
        for code in trans.code:
            output_lines.append(f"    {code},")
    output_lines.extend(["};", "", "HC_EXPORT_PROGRAM(program)", ""])
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(output_lines))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True, type=Path, help="native asm plain text or micro md containing a Native ASM section")
    parser.add_argument("--output", required=True, type=Path, help="generated .handcraft.c path")
    parser.add_argument("--entry-symbol", help="entry function when the input contains full objdump output")
    parser.add_argument("--context-kind", choices=("xdp", "skb"), default="xdp")
    args = parser.parse_args()

    global CONTEXT_KIND
    CONTEXT_KIND = args.context_kind
    insns = parse_native_asm(args.input.read_text(), args.entry_symbol)
    translations = relocate_branch_offsets(insns, localize_exit_targets(insns, translate_all(insns)))
    fatal = [
        (insn, trans)
        for insn, trans in zip(insns, translations, strict=True)
        if not trans.code and trans.status not in {"padding", "absorbed-control-flow"}
    ]
    if fatal:
        for insn, trans in fatal:
            print(f"error: 0x{insn.addr:x}: {insn.raw}: {trans.status}: {trans.note}")
        return 1
    write_outputs(insns, translations, args.output)
    warnings = sum(1 for item in translations if item.status.startswith("warning"))
    exact = sum(1 for item in translations if item.status == "exact-kinsn")
    padding = sum(1 for item in translations if item.status == "padding")
    print(
        f"insns={len(insns)} exact_kinsn={exact} "
        f"padding={padding} warnings={warnings}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
