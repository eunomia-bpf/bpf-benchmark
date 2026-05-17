#!/usr/bin/env python3
"""Translate x86 native asm text into a handcraft.c candidate.

The converter is intentionally conservative: instructions that cannot be
represented one-to-one by the current handcraft BPF/kinsn surface are emitted as
explicit warnings in the generated C, but they do not stop generation.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass, replace
from pathlib import Path


BPF_REG_BY_X86 = {
    "rax": "BPF_REG_0",
    "rdi": "BPF_REG_1",
    "rsi": "BPF_REG_2",
    "rdx": "BPF_REG_3",
    "rcx": "BPF_REG_4",
    "r8": "BPF_REG_5",
    "r9": "HC_X86_R9",
    "r10": "HC_X86_R10",
    "r11": "HC_X86_R11",
    "r12": "HC_X86_R12",
    "rsp": "HC_X86_RSP",
    "rbp": "HC_X86_RBP",
    "rbx": "BPF_REG_6",
    "r13": "BPF_REG_7",
    "r14": "BPF_REG_8",
    "r15": "BPF_REG_9",
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
BRANCH_DELTA = "__BRANCH_DELTA__"
X86_DISP = "__X86_DISP__"
X86_NEAR = "__X86_NEAR__"
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
    "jo": "BPF_JNE",
    "jno": "BPF_JEQ",
    "jp": "BPF_JNE",
    "jnp": "BPF_JEQ",
}
JCC_SELECTOR = {
    "ja": "MICRO_HANDCRAFT_BPF_X86_JA",
    "jae": "MICRO_HANDCRAFT_BPF_X86_JAE",
    "jb": "MICRO_HANDCRAFT_BPF_X86_JB",
    "jbe": "MICRO_HANDCRAFT_BPF_X86_JBE",
    "je": "MICRO_HANDCRAFT_BPF_X86_JE",
    "jne": "MICRO_HANDCRAFT_BPF_X86_JNE",
    "jg": "MICRO_HANDCRAFT_BPF_X86_JG",
    "jge": "MICRO_HANDCRAFT_BPF_X86_JGE",
    "jl": "MICRO_HANDCRAFT_BPF_X86_JL",
    "jle": "MICRO_HANDCRAFT_BPF_X86_JLE",
    "js": "MICRO_HANDCRAFT_BPF_X86_JS",
    "jns": "MICRO_HANDCRAFT_BPF_X86_JNS",
}
BRANCH_PROOF_LEN = {
    "MICRO_HANDCRAFT_BPF_X86_JA": 15,
    "MICRO_HANDCRAFT_BPF_X86_JAE": 13,
    "MICRO_HANDCRAFT_BPF_X86_JB": 12,
    "MICRO_HANDCRAFT_BPF_X86_JBE": 14,
    "MICRO_HANDCRAFT_BPF_X86_JE": 12,
    "MICRO_HANDCRAFT_BPF_X86_JNE": 13,
    "MICRO_HANDCRAFT_BPF_X86_JG": 15,
    "MICRO_HANDCRAFT_BPF_X86_JGE": 12,
    "MICRO_HANDCRAFT_BPF_X86_JL": 13,
    "MICRO_HANDCRAFT_BPF_X86_JLE": 14,
    "MICRO_HANDCRAFT_BPF_X86_JS": 12,
    "MICRO_HANDCRAFT_BPF_X86_JNS": 13,
    "MICRO_HANDCRAFT_BPF_X86_JMP": 1,
}
BRANCH_DIRECT_PROOF_LEN = 14
BRANCH_PROOF_FLAGS = "HC_X86_BRANCH_PROOF_FLAGS"
BRANCH_PROOF_CMP_RR = "HC_X86_BRANCH_PROOF_CMP_RR"
DIRECT_CMP_JCC = {"ja", "jae", "jb", "jbe", "je", "jne", "jg", "jge", "jl", "jle"}
X86_PSEUDO_REG_TOKENS = (
    "HC_X86_R9",
    "HC_X86_R10",
    "HC_X86_R11",
    "HC_X86_R12",
    "HC_X86_RBP",
    "HC_X86_RSP",
)
SCRATCH_BPF_REG_TOKENS = {"BPF_REG_6", "BPF_REG_7", "BPF_REG_8"}


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


def parse_native_asm(text: str) -> list[NativeInsn]:
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


def is_shadow_reg_name(name: str) -> bool:
    return name.startswith("HC_X86_")


def arch_payload(regs: tuple[tuple[str, int, str], ...]) -> bool:
    return any(item[2] == "rbp" for item in regs)


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


def machine_alu_rr_payload(dst: tuple[str, int, str], src: tuple[str, int, str]) -> str:
    macro = "HC_X86_ARCH_RR_PAYLOAD" if arch_payload((dst, src)) else "HC_X86_ALU_RR_PAYLOAD"
    return f"{macro}({dst[0]}, {src[0]})"


def machine_alu_imm_payload(dst: tuple[str, int, str], imm: int) -> str:
    macro = "HC_X86_ARCH_IMM_PAYLOAD" if dst[2] == "rbp" else "HC_X86_ALU_IMM_PAYLOAD"
    return f"{macro}({dst[0]}, {c_s32(imm)})"


def reg_imm_payload(reg_name: str, imm: int) -> str:
    return f"HC_REG_IMM_PAYLOAD({reg_name}, {imm})"


def x86_imm_payload(dst: tuple[str, int, str], imm: int) -> str:
    macro = "HC_X86_ARCH_IMM_PAYLOAD" if dst[2] == "rbp" else "HC_X86_IMM_PAYLOAD"
    return f"{macro}({dst[0]}, {imm})"


def reg_payload(reg_name: str) -> str:
    return f"HC_REG_PAYLOAD({reg_name})"


def mem_payload_macro(base_name: str) -> str:
    return "HC_X86_ARCH_MEM_PAYLOAD" if base_name == "rbp" else "HC_X86_MEM_PAYLOAD"


def store_payload_macro(base_name: str, byte_lane: bool = False) -> str:
    if base_name == "rbp":
        return "HC_X86_ARCH_STORE_BYTE_PAYLOAD" if byte_lane else "HC_X86_ARCH_STORE_PAYLOAD"
    return "HC_X86_STORE_BYTE_PAYLOAD" if byte_lane else "HC_X86_STORE_PAYLOAD"


def store_imm_payload_macro(base_name: str) -> str:
    return "HC_X86_ARCH_STORE_IMM_PAYLOAD" if base_name == "rbp" else "HC_X86_STORE_IMM_PAYLOAD"


def stack_reg_payload(operand: str) -> str | None:
    parsed = reg(operand)
    if parsed is None:
        return None
    base, _width = parsed
    if base == "rbp":
        return "HC_X86_RBP"
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
    if base_reg[0] == "BPF_REG_1" and index is None and size == "BPF_DW" and off in {0, 8}:
        bpf_off = 0 if off == 0 else 4
        return Translation(
            "context-abi",
            (f"HC_LDX(BPF_W, {dst[0]}, BPF_REG_1, {bpf_off})",),
            f"native xdp_md 64-bit field at off {off} maps to BPF XDP u32 ctx field at off {bpf_off}",
        )
    if index is not None:
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"SIB index {index} scale {scale} is not expressible")
        target = {"BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL", "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL", "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL", "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ"}.get(size)
        if target is None:
            return Translation("warning-unmapped", (), f"SIB load size {size} has no current selector")
        if base_reg[2] == "rbp":
            return Translation("warning-unmapped", (), f"SIB base rbp needs an arch-SIB payload form: {mem_op}")
        payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
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
        return Translation("abi-boundary", ("HC_EXIT()",), "native ret maps to the BPF program exit boundary")
    if op == "call" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            return Translation("warning-unmapped", (), f"cannot parse x86 call target: {insn.raw}")
        return Translation("abi-boundary", (f"HC_CALL({BRANCH_DELTA})",), "native direct call maps to BPF pseudo call", target_addr)
    if op in JCC_OP:
        target_addr = parse_branch_target(ops[0]) if len(ops) == 1 else None
        selector = JCC_SELECTOR.get(op)
        if target_addr is None:
            return Translation("warning-unmapped", (), f"cannot parse x86 branch target: {insn.raw}")
        if selector is None:
            return Translation("warning-unmapped", (), f"{op} needs shadow flag support before it can be a branch kinsn", target_addr)
        payload = f"HC_X86_BRANCH_PAYLOAD({BRANCH_DELTA}, {X86_DISP}, {X86_NEAR})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op} branch kinsn", target_addr)
    if op == "jmp" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            return Translation("warning-unmapped", (), f"needs a machine-level x86 indirect-branch kinsn for target {ops[0]}")
        payload = f"HC_X86_BRANCH_PAYLOAD({BRANCH_DELTA}, {X86_DISP}, {X86_NEAR})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_JMP)",), "jmp branch kinsn", target_addr)
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
            macro = "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" if base_reg[2] == "rbp" else "HC_X86_CMP_MEM_IMM_PAYLOAD"
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
                if is_bpf_reg_name(dst_reg[0]) and dst_reg[0] != "BPF_REG_10":
                    return Translation("exact-bpf", (f"HC_LD_IMM64_RAW({dst_reg[0]}, 0, {imm}ULL)",), "movabs via BPF_LD_IMM64; x86 JIT emits movabs")
                return Translation("warning-unmapped", (), f"movabs into {dst_reg[0]} needs a machine-level immediate-load kinsn")
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
        payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
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
        payload = (
            f"HC_LEA_PAYLOAD({dst[0]}, {base_reg[0] if base_reg else 0}, "
            f"{index_reg[0] if index_reg else 0}, {slog2}, {1 if base_reg else 0}, "
            f"{1 if index_reg else 0}, {disp})"
        )
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), note)
    if op == "rol" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst and ops[1].lower() == "cl" and dst[1] in {32, 64}:
            selector = "MICRO_HANDCRAFT_BPF_X86_ROLQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_ROLL"
            width = "q" if dst[1] == 64 else "l"
            macro = "HC_ROTATE_ARCH_CL_PAYLOAD" if dst[2] == "rbp" else "HC_ROTATE_CL_PAYLOAD"
            return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, BPF_REG_4), {selector})",), f"rol{width} cl kinsn")
        if dst and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            macro = "HC_ROTATE_ARCH_PAYLOAD" if dst[2] == "rbp" else "HC_ROTATE_PAYLOAD"
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLQ)",), "rolq imm kinsn")
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN({macro}({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLL)",), "roll imm kinsn")
            if dst[1] == 16 and parse_int(ops[1]) == 8:
                reg_imm = "HC_REG_IMM_ARCH_PAYLOAD" if dst[2] == "rbp" else "HC_REG_IMM_PAYLOAD"
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
                if base_reg[2] == "rbp":
                    return Translation("warning-unmapped", (), f"ALU SIB base rbp needs an arch-SIB payload form: {insn.raw}")
                payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} SIB memory-source kinsn")
            if index is not None and op == "xor" and dst[1] == 8 and size == "BPF_B":
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                if base_reg[2] == "rbp":
                    return Translation("warning-unmapped", (), f"ALU SIB base rbp needs an arch-SIB payload form: {insn.raw}")
                payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
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
            macro = "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" if base_reg[2] == "rbp" else "HC_X86_CMP_MEM_IMM_PAYLOAD"
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
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCL)",), "incl reg kinsn")
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCQ)",), "incq reg kinsn")
            return Translation("warning-unmapped", (), f"inc width {dst[1]} needs a machine-level inc kinsn")
        return Translation("warning-unmapped", (), unsupported_reg_note("INC destination", ops[0]))
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


def jcc_proof_from_flag_producer(branch: NativeInsn, producer: NativeInsn) -> tuple[bool, str] | None:
    if branch.mnemonic not in DIRECT_CMP_JCC:
        return None
    if producer.mnemonic != "cmp" or len(producer.operands) != 2:
        return None
    lhs = bpf_reg(producer.operands[0])
    rhs = bpf_reg(producer.operands[1])
    if lhs is None or rhs is None or lhs[1] != rhs[1] or lhs[1] not in {32, 64}:
        if lhs is None or lhs[1] not in {32, 64} or not is_int(producer.operands[1]):
            return None
        return lhs[1] == 32, BRANCH_PROOF_CMP_RR
    return lhs[1] == 32, BRANCH_PROOF_CMP_RR


def translate_all(insns: list[NativeInsn]) -> list[Translation]:
    translations: list[Translation] = []
    flag_producer: NativeInsn | None = None
    for insn in insns:
        trans = translate(insn)
        if insn.mnemonic in JCC_OP and flag_producer is not None:
            proof = jcc_proof_from_flag_producer(insn, flag_producer)
            if proof is not None:
                is32, proof_kind = proof
                code = tuple(
                    item.replace(
                        "HC_X86_BRANCH_PAYLOAD(",
                        f"HC_X86_BRANCH_PROOF_PAYLOAD(",
                    ).replace(
                        ")",
                        f", {1 if is32 else 0}, {proof_kind})",
                        1,
                    ) if item.startswith("HC_KINSN(HC_X86_BRANCH_PAYLOAD(") else item
                    for item in trans.code
                )
                trans = Translation(trans.status, code,
                                    f"{trans.note}; verifier proof from preceding {flag_producer.mnemonic}",
                                    trans.target_addr)
        translations.append(trans)
        if insn.mnemonic in {"cmp", "test"}:
            flag_producer = insn
        elif insn.mnemonic in ALU_OP or insn.mnemonic in {"imul", "popcnt", "sbb", "inc", "rol", "shl", "shr", "sar"}:
            flag_producer = None
    return translations



def bpf_insn_len(code: str) -> int:
    if code.startswith("HC_INIT_X86_STACK("):
        return 3
    if code.startswith("HC_LD_IMM64_RAW("):
        return 2
    if code.startswith("HC_KINSN("):
        return 2
    return 1


def branch_native_len(insn: NativeInsn, near: int) -> int:
    if insn.mnemonic == "jmp":
        return 5 if near else 2
    if insn.mnemonic in JCC_OP:
        return 6 if near else 2
    return insn.size


def branch_initial_near(insn: NativeInsn) -> int:
    if insn.mnemonic == "jmp":
        return 1 if insn.size >= 5 else 0
    if insn.mnemonic in JCC_OP:
        return 1 if insn.size >= 6 else 0
    return 0


def exit_epilogue_len(translations: list[Translation]) -> int:
    used = {6, 7, 8}
    for trans in translations:
        for code in trans.code:
            if "BPF_REG_9" in code:
                used.add(9)
    pop_len = {6: 1, 7: 2, 8: 2, 9: 2}
    return sum(pop_len[reg] for reg in sorted(used)) + 2


def x86_layout(insns: list[NativeInsn], translations: list[Translation],
               near_by_index: dict[int, int]) -> tuple[list[int], list[int]]:
    first_exit = next((i for i, item in enumerate(insns) if item.mnemonic == "ret"), None)
    epilogue_len = exit_epilogue_len(translations)
    exit_len_by_index: dict[int, int] = {}
    offsets: list[int] = []

    for _ in range(4):
        offsets = []
        off = 0
        cleanup = None if first_exit is None else offsets[first_exit] if first_exit < len(offsets) else None
        for index, (insn, trans) in enumerate(zip(insns, translations, strict=True)):
            offsets.append(off)
            if insn.mnemonic == "ret":
                if index == first_exit:
                    length = epilogue_len
                    cleanup = off
                else:
                    target = cleanup if cleanup is not None else 0
                    short_disp = target - (off + 2)
                    length = 2 if -128 <= short_disp <= 127 else 5
                exit_len_by_index[index] = length
            elif insn.mnemonic in JCC_OP or insn.mnemonic == "jmp":
                length = branch_native_len(insn, near_by_index.get(index, branch_initial_near(insn)))
            elif trans.status == "padding" or trans.status.startswith("warning"):
                length = 0
            elif trans.status == "abi-boundary" and any(code.startswith("HC_CALL(") for code in trans.code):
                length = 5
            elif trans.status == "exact-bpf" and any(code.startswith("HC_LD_IMM64_RAW(") for code in trans.code):
                length = 10
            elif trans.status == "context-abi":
                length = max(insn.size, 4)
            else:
                length = insn.size
            off += length

    lengths = []
    for index, insn in enumerate(insns):
        if insn.mnemonic == "ret":
            lengths.append(exit_len_by_index.get(index, epilogue_len))
        elif insn.mnemonic in JCC_OP or insn.mnemonic == "jmp":
            lengths.append(branch_native_len(insn, near_by_index.get(index, branch_initial_near(insn))))
        else:
            next_off = offsets[index + 1] if index + 1 < len(offsets) else off
            lengths.append(next_off - offsets[index])
    return offsets, lengths


def relocate_x86_branches(insns: list[NativeInsn], translations: list[Translation],
                          index_by_addr: dict[int, int]) -> list[Translation]:
    near_by_index = {
        index: branch_initial_near(insn)
        for index, insn in enumerate(insns)
        if insn.mnemonic in JCC_OP or insn.mnemonic == "jmp"
    }

    for _ in range(4):
        offsets, lengths = x86_layout(insns, translations, near_by_index)
        changed = False
        for index, trans in enumerate(translations):
            if trans.target_addr is None or index not in near_by_index:
                continue
            target_index = index_by_addr.get(trans.target_addr)
            if target_index is None:
                continue
            short_len = branch_native_len(insns[index], 0)
            short_disp = offsets[target_index] - (offsets[index] + short_len)
            want_near = 0 if -128 <= short_disp <= 127 else 1
            if near_by_index[index] != want_near:
                near_by_index[index] = want_near
                changed = True
        if not changed:
            break

    offsets, lengths = x86_layout(insns, translations, near_by_index)
    patched: list[Translation] = []
    for index, trans in enumerate(translations):
        if trans.target_addr is None or index not in near_by_index:
            patched.append(trans)
            continue
        target_index = index_by_addr.get(trans.target_addr)
        if target_index is None:
            patched.append(trans)
            continue
        disp = offsets[target_index] - (offsets[index] + lengths[index])
        near = near_by_index[index]
        code = tuple(item.replace(X86_DISP, str(disp)).replace(X86_NEAR, str(near))
                     for item in trans.code)
        patched.append(Translation(trans.status, code, trans.note, trans.target_addr))
    return patched


def kinsn_selector(code: str) -> str | None:
    if not code.startswith("HC_KINSN("):
        return None
    head = code.rsplit(",", 1)
    if len(head) != 2:
        return None
    return head[1].strip().rstrip(")")


def has_x86_pseudo_reg(code: str) -> bool:
    return any(token in code for token in X86_PSEUDO_REG_TOKENS)


def payload_args(code: str, macro: str) -> list[str]:
    match = re.search(rf"{re.escape(macro)}\(([^)]*)\)", code)
    if not match:
        return []
    return [item.strip() for item in match.group(1).split(",")]


def payload_arg_is_scratch(code: str, macro: str, index: int) -> bool:
    args = payload_args(code, macro)
    return len(args) > index and args[index] in SCRATCH_BPF_REG_TOKENS


def payload_arg_is_pseudo(code: str, macro: str, index: int) -> bool:
    args = payload_args(code, macro)
    return len(args) > index and args[index] in X86_PSEUDO_REG_TOKENS


def proof_insn_len(code: str) -> int:
    selector = kinsn_selector(code)
    if selector is None:
        return bpf_insn_len(code)
    if selector == "MICRO_HANDCRAFT_BPF_X86_PUSHQ":
        return 11
    if selector == "MICRO_HANDCRAFT_BPF_X86_POPQ":
        return 12
    if selector in BRANCH_PROOF_LEN:
        if "HC_X86_BRANCH_PROOF_PAYLOAD" in code and BRANCH_PROOF_CMP_RR in code:
            return BRANCH_DIRECT_PROOF_LEN
        return BRANCH_PROOF_LEN[selector]
    if "MICRO_HANDCRAFT_BPF_X86_CMP" in selector:
        if "HC_X86_CMP_SIB_RR_PAYLOAD" in code:
            match = re.search(r"HC_X86_CMP_SIB_RR_PAYLOAD\([^,]+,[^,]+,\s*([^,]+),", code)
            add_count = 1 << int(match.group(1), 0) if match else 1
            return 17 + add_count + (1 if "HC_X86_R" in code else 0)
        if "HC_X86_CMP_MEM_IMM_PAYLOAD" in code or "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" in code:
            narrow = selector in {"MICRO_HANDCRAFT_BPF_X86_CMPB", "MICRO_HANDCRAFT_BPF_X86_CMPW"}
            arch = "HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD" in code
            return 16 + (2 if narrow else 0) + (1 if arch else 0)
        if selector in {"MICRO_HANDCRAFT_BPF_X86_CMPB", "MICRO_HANDCRAFT_BPF_X86_CMPW"}:
            if "HC_X86_ARCH_RR_PAYLOAD" in code:
                return 23
            if "HC_X86_RR_PAYLOAD" in code:
                return 27
            return 19 if "HC_X86_ARCH_IMM_PAYLOAD" in code else 14
        if "HC_X86_ARCH_RR_PAYLOAD" in code:
            return 17 + code.count("HC_X86_R")
        if "HC_X86_ARCH_IMM_PAYLOAD" in code or ("HC_X86_IMM_PAYLOAD" in code and "HC_X86_R" in code):
            return 18
        if "HC_X86_IMM_PAYLOAD" in code:
            return 17
        return 17
    if "MICRO_HANDCRAFT_BPF_X86_TEST" in selector:
        return 12
    if selector in {"MICRO_HANDCRAFT_BPF_X86_MOVB", "MICRO_HANDCRAFT_BPF_X86_MOVW",
                    "MICRO_HANDCRAFT_BPF_X86_MOVL", "MICRO_HANDCRAFT_BPF_X86_MOVQ"}:
        if "HC_X86_STORE_IMM_PAYLOAD" in code:
            return 1
        if "HC_X86_FRAME_PAYLOAD" in code:
            return 8
        if "HC_X86_IMM_PAYLOAD" in code and not has_x86_pseudo_reg(code):
            return 1
        if "HC_X86_RR_PAYLOAD" in code and not has_x86_pseudo_reg(code):
            return 1 if selector != "MICRO_HANDCRAFT_BPF_X86_MOVL" else 3
        if "HC_X86_MEM_PAYLOAD" in code and not has_x86_pseudo_reg(code):
            return 8 if payload_arg_is_scratch(code, "HC_X86_MEM_PAYLOAD", 0) else 1
        return 8
    if selector in {"MICRO_HANDCRAFT_BPF_X86_MOVZBL", "MICRO_HANDCRAFT_BPF_X86_MOVZWL"}:
        if "HC_X86_MEM_PAYLOAD" in code and not has_x86_pseudo_reg(code):
            return 8 if payload_arg_is_scratch(code, "HC_X86_MEM_PAYLOAD", 0) else 1
        if "HC_X86_RR_PAYLOAD" in code and not has_x86_pseudo_reg(code):
            return 2
        if "HC_X86_RR_PAYLOAD" in code and not payload_arg_is_pseudo(code, "HC_X86_RR_PAYLOAD", 0):
            return 2
        return 10
    if selector in {"MICRO_HANDCRAFT_BPF_X86_LEAQ", "MICRO_HANDCRAFT_BPF_X86_LEAL"}:
        if not has_x86_pseudo_reg(code):
            return 2
        return 11
    if selector in {"MICRO_HANDCRAFT_BPF_X86_ROLL", "MICRO_HANDCRAFT_BPF_X86_ROLQ"}:
        if "HC_ROTATE_PAYLOAD" in code:
            return 12
        return 16
    if selector.startswith("MICRO_HANDCRAFT_BPF_X86_") and selector[-1:] in {"L", "Q"}:
        if "HC_X86_ALU_IMM_PAYLOAD" in code:
            return 9 if has_x86_pseudo_reg(code) else 1
        if "HC_X86_ALU_RR_PAYLOAD" in code:
            return 11 if has_x86_pseudo_reg(code) else 1
    if "MICRO_HANDCRAFT_BPF_X86_" in selector:
        if has_x86_pseudo_reg(code):
            return 8
        return 1
    return 2


def relocate_branch_offsets(insns: list[NativeInsn], translations: list[Translation]) -> list[Translation]:
    pc_by_addr: dict[int, int] = {}
    pc_by_index: list[int] = []
    index_by_addr: dict[int, int] = {}
    bpf_lens: list[int] = []
    proof_lens: list[int] = []
    pc = 0
    for index, (insn, trans) in enumerate(zip(insns, translations, strict=True)):
        pc_by_addr.setdefault(insn.addr, pc)
        index_by_addr.setdefault(insn.addr, index)
        pc_by_index.append(pc)
        bpf_len = sum(bpf_insn_len(code) for code in trans.code)
        proof_len = sum(proof_insn_len(code) for code in trans.code)
        bpf_lens.append(bpf_len)
        proof_lens.append(proof_len)
        pc += bpf_len

    def kinsn_stage_delta(source_index: int, target_index: int) -> int:
        source_pc = sum(bpf_lens[:source_index])
        if target_index <= source_index:
            target_pc = sum(bpf_lens[:target_index])
        else:
            target_pc = source_pc + proof_lens[source_index]
            target_pc += sum(proof_lens[source_index + 1:target_index])
        return target_pc - source_pc

    patched: list[Translation] = []
    for index, trans in enumerate(translations):
        if trans.target_addr is None:
            patched.append(trans)
            continue
        target_pc = pc_by_addr.get(trans.target_addr)
        if target_pc is None:
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
                delta = kinsn_stage_delta(index, index_by_addr[trans.target_addr])
            else:
                delta = target_pc - code_pc
            code.append(item.replace(BRANCH_DELTA, str(delta)))
            code_pc += bpf_insn_len(item)
        code = tuple(code)
        patched.append(Translation(trans.status, code, trans.note, trans.target_addr))
    return relocate_x86_branches(insns, patched, index_by_addr)


def write_outputs(insns: list[NativeInsn], translations: list[Translation], output: Path) -> None:
    warnings = sum(1 for item in translations if item.status.startswith("warning"))
    output_lines = [
        '#include "handcraft_common.h"',
        "",
        "#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \\",
        "    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \\",
        "     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \\",
        "     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))",
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
    args = parser.parse_args()

    insns = parse_native_asm(args.input.read_text())
    translations = relocate_branch_offsets(insns, translate_all(insns))
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
