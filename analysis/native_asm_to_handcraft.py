#!/usr/bin/env python3
"""Translate x86 native asm text into a handcraft.c candidate.

The converter is intentionally conservative: instructions that cannot be
represented one-to-one by the current handcraft BPF/kinsn surface are emitted as
explicit warnings in the generated C, but they do not stop generation.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
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
BRANCH_OFF = "__BRANCH_OFF__"
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
    ("sub", 64): "MICRO_HANDCRAFT_BPF_X86_SUBQ",
    ("sub", 32): "MICRO_HANDCRAFT_BPF_X86_SUBL",
    ("and", 64): "MICRO_HANDCRAFT_BPF_X86_ANDQ",
    ("and", 32): "MICRO_HANDCRAFT_BPF_X86_ANDL",
    ("shr", 8): "MICRO_HANDCRAFT_BPF_X86_SHRB",
    ("xor", 64): "MICRO_HANDCRAFT_BPF_X86_XORQ",
    ("xor", 32): "MICRO_HANDCRAFT_BPF_X86_XORL",
    ("or", 64): "MICRO_HANDCRAFT_BPF_X86_ORQ",
    ("or", 32): "MICRO_HANDCRAFT_BPF_X86_ORL",
    ("shl", 64): "MICRO_HANDCRAFT_BPF_X86_SHLQ",
    ("shl", 32): "MICRO_HANDCRAFT_BPF_X86_SHLL",
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
}


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
            if not asm or asm.startswith("<"):
                continue
            parsed = ASM_LINE_RE.match(asm)
            if not parsed:
                continue
            size = len(obj.group("bytes").split())
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
    if operand.strip().lower().lstrip("%") == "rbp":
        return "HC_X86_RBP_STACK_BASE", 64, "rbp"
    return bpf_reg(operand)


def byte_lane(operand: str) -> int:
    return 1 if operand.strip().lower() in HIGH_BYTE_X86_REGS else 0


def is_bpf_reg_name(name: str) -> bool:
    return name.startswith("BPF_REG_")


def is_shadow_reg_name(name: str) -> bool:
    return name.startswith("HC_X86_")


def reg_reg_payload(dst: str, src: str) -> str:
    return f"HC_X86_RR_PAYLOAD({dst}, {src})"


def cmp_rr_payload(lhs: str, rhs: str) -> str:
    return f"HC_REG_REG_PAYLOAD({lhs}, {rhs})"


def byte_reg_reg_payload(dst: str, src: str) -> str:
    return f"HC_REG_REG_PAYLOAD({dst}, {src})"


def c_s32(value: int) -> str:
    value &= 0xffffffff
    if value >= 0x80000000:
        value -= 0x100000000
    return str(value)


def machine_alu_rr_payload(dst: str, src: str) -> str:
    return f"HC_X86_ALU_RR_PAYLOAD({dst}, {src})"


def machine_alu_imm_payload(dst: str, imm: int) -> str:
    return f"HC_X86_ALU_IMM_PAYLOAD({dst}, {c_s32(imm)})"


def reg_imm_payload(reg_name: str, imm: int) -> str:
    return f"HC_REG_IMM_PAYLOAD({reg_name}, {imm})"


def reg_payload(reg_name: str) -> str:
    return f"HC_REG_PAYLOAD({reg_name})"


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
        return Translation("warning-unmapped", (), f"destination register {dst_op} is not in the BPF JIT register file")
    if mem is None:
        return Translation("warning-unmapped", (), f"unsupported memory operand {mem_op}")
    base, index, scale, off = mem
    if base is None:
        return Translation("warning-unmapped", (), "RIP/absolute memory is not expressible as verifier-safe BPF memory")
    base_reg = bpf_mem_base(base)
    if base_reg is None:
        return Translation("warning-unmapped", (), f"memory base {base} is not in the BPF JIT register file")
    if base_reg[0] == "BPF_REG_1" and index is None and size == "BPF_DW" and off in {0, 8}:
        bpf_off = 0 if off == 0 else 4
        return Translation(
            "warning-context-abi",
            (),
            f"native xdp_md uses 64-bit host pointer field at off {off}; BPF XDP ctx uses u32 field at off {bpf_off}",
        )
    if index is not None:
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"SIB index {index} scale {scale} is not expressible")
        target = {"BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL", "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL", "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL", "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ"}.get(size)
        if target is None:
            return Translation("warning-unmapped", (), f"SIB load size {size} has no current selector")
        payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), "indexed memory load via x86 SIB kinsn")
    target = DIRECT_LOAD_SELECTOR.get(size)
    if target is None:
        return Translation("warning-unmapped", (), f"direct load size {size} needs a machine-level mov/load kinsn")
    payload = f"HC_X86_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off})"
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
    if op in {"push", "pop", "leave"}:
        return Translation("warning-unmapped", (), "needs a machine-level x86 stack/control kinsn; cannot be ignored in strict handcraft mode")
    if op == "mov" and ops in {("rbp", "rsp"), ("rsp", "rbp")}:
        return Translation("warning-unmapped", (), "native rbp/rsp move needs explicit x86 frame-state payload")
    if op == "ret":
        return Translation("abi-boundary", ("HC_EXIT()",), "native ret maps to the BPF program exit boundary")
    if op in JCC_OP or op == "jns":
        target_addr = parse_branch_target(ops[0]) if len(ops) == 1 else None
        note = "needs a machine-level x86 conditional-branch kinsn"
        return Translation("warning-unmapped", (), note, target_addr)
    if op == "jmp" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            return Translation("warning-unmapped", (), f"cannot parse branch target {ops[0]}")
        return Translation("warning-unmapped", (), "needs a machine-level x86 branch kinsn", target_addr)
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
                "BPF_W": "MICRO_HANDCRAFT_BPF_X86_CMPL",
                "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_CMPQ",
            }[size]
            payload = f"HC_X86_CMP_MEM_IMM_PAYLOAD({base_reg[0]}, {off}, {parse_int(ops[1])})"
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
            payload = f"HC_X86_RR_PAYLOAD({lhs[0]}, {rhs[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ)",), "cmpq reg,reg kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 32:
            payload = f"HC_X86_RR_PAYLOAD({lhs[0]}, {rhs[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL)",), "cmpl reg,reg kinsn")
        if lhs and rhs and lhs[1] == rhs[1] == 8:
            payload = f"HC_X86_RR_PAYLOAD({lhs[0]}, {rhs[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPB)",), "cmpb reg,reg kinsn")
        if lhs and lhs[1] == 64 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = f"HC_X86_IMM_PAYLOAD({lhs[0]}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ)",), "cmpq reg,imm32 kinsn")
        if lhs and lhs[1] == 32 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = f"HC_X86_IMM_PAYLOAD({lhs[0]}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL)",), "cmpl reg,imm32 kinsn")
        if lhs and lhs[1] == 8 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = f"HC_X86_IMM_PAYLOAD({lhs[0]}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPB)",), "cmpb reg,imm8 kinsn")
        return Translation("warning-unmapped", (), f"CMP operand form has no current kinsn selector: {insn.raw}")
    if len(ops) == 2 and op in {"mov", "movabs"}:
        dst, src = ops
        dst_reg = bpf_reg(dst)
        src_reg = bpf_reg(src)
        if dst_reg and src_reg:
            if dst_reg[1] == 64 and src_reg[1] == 64:
                payload = reg_reg_payload(dst_reg[0], src_reg[0])
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVQ)",),
                    "movq register-to-register kinsn",
                )
            if dst_reg[1] == 32 and src_reg[1] == 32:
                payload = reg_reg_payload(dst_reg[0], src_reg[0])
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVL)",),
                    "movl register-to-register kinsn",
                )
            return Translation("warning-unmapped", (), f"mixed-width register move {dst}, {src}")
        if dst_reg and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", src):
            imm = parse_int(src)
            if op == "movabs" or dst_reg[1] == 64 and abs(imm) > 0x7fffffff:
                return Translation("warning-unmapped", (), f"movabs into {dst_reg[0]} needs a machine-level immediate-load kinsn")
            if dst_reg[1] == 32:
                payload = f"HC_X86_IMM_PAYLOAD({dst_reg[0]}, {imm})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVL)",), "movl immediate kinsn")
            if dst_reg[1] == 64:
                payload = f"HC_X86_IMM_PAYLOAD({dst_reg[0]}, {imm})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVQ)",), "movq immediate kinsn")
            if dst_reg[1] == 8:
                payload = f"HC_X86_IMM_PAYLOAD({dst_reg[0]}, {imm})"
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
                return Translation("warning-unmapped", (), f"store base {mem[0]} is not in the BPF JIT register file")
            target = DIRECT_STORE_SELECTOR.get(size)
            if target is None:
                return Translation("warning-unmapped", (), f"store size {size} needs a machine-level mov/store kinsn")
            if size == "BPF_B" and byte_lane(src):
                payload = f"HC_X86_STORE_BYTE_PAYLOAD({src_reg[0]}, {base[0]}, {mem[3]}, 1)"
            else:
                payload = f"HC_X86_STORE_PAYLOAD({src_reg[0]}, {base[0]}, {mem[3]})"
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
                return Translation("warning-unmapped", (), f"store base {mem[0]} is not in the BPF JIT register file")
            imm = parse_int(src)
            if size == "BPF_B":
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN(HC_X86_STORE_IMM_PAYLOAD({base[0]}, {mem[3]}, {imm}), MICRO_HANDCRAFT_BPF_X86_MOVB)",),
                    "movb immediate memory store via x86 kinsn selector",
                )
            target = DIRECT_STORE_SELECTOR.get(size)
            if target is not None:
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN(HC_X86_STORE_IMM_PAYLOAD({base[0]}, {mem[3]}, {imm}), {target})",),
                    "mov immediate memory store via x86 kinsn selector",
                )
            return Translation("warning-unmapped", (), f"mov immediate store size {size} needs a machine-level store-immediate kinsn")
    if op == "movzx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] in {8, 16}:
            selector = "MICRO_HANDCRAFT_BPF_X86_MOVZBL" if src[1] == 8 else "MICRO_HANDCRAFT_BPF_X86_MOVZWL"
            return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_RR_PAYLOAD({dst[0]}, {src[0]}), {selector})",), f"movzx r32,r{src[1]} kinsn")
        size = size_from_mem(ops[1])
        if size not in {"BPF_B", "BPF_H"}:
            return Translation("warning-unmapped", (), f"movzx source size not recognized: {ops[1]}")
        return translate_mem_load(ops[0], ops[1], size)
    if op == "movsx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] == 16:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_RR_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_MOVSWL)",), "movswl reg kinsn")
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
            return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_CL_PAYLOAD({dst[0]}, BPF_REG_4), {selector})",), f"rol{width} cl kinsn")
        if dst and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_PAYLOAD({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLQ)",), "rolq imm kinsn")
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_PAYLOAD({dst[0]}, {dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ROLL)",), "roll imm kinsn")
            if dst[1] == 16 and parse_int(ops[1]) == 8:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, 8), MICRO_HANDCRAFT_BPF_X86_ROLW)",), "rolw imm8 kinsn")
        return Translation("warning-unmapped", (), f"ROL width/register not supported by current selectors: {ops[0]}")
    if op == "popcnt" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_POPCNTQ)",), "popcntq kinsn")
        return Translation("warning-unmapped", (), "only popcntq reg,reg is supported")
    if op == "imul" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_IMULQ)",), "imulq reg,reg kinsn")
        return Translation("warning-unmapped", (), f"IMUL operands are not in the 64-bit BPF JIT register file: {insn.raw}")
    if op == "not" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if not dst:
            return Translation("warning-unmapped", (), f"NOT destination {ops[0]} is not in the BPF JIT register file")
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
            return Translation("warning-unmapped", (), f"BSWAP destination {ops[0]} is not in the BPF JIT register file")
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
            return Translation("warning-unmapped", (), f"{op.upper()} operands are not in the BPF JIT register file: {insn.raw}")
        if dst[1] != src[1] or dst[1] not in {32, 64}:
            return Translation("warning-unmapped", (), f"{op.upper()} width is not supported: {insn.raw}")
        if not re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[2]):
            return Translation("warning-unmapped", (), f"{op.upper()} count is not an immediate: {insn.raw}")
        if op == "shld":
            selector = "MICRO_HANDCRAFT_BPF_X86_SHLDQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHLDL"
        else:
            selector = "MICRO_HANDCRAFT_BPF_X86_SHRDQ" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHRDL"
        return Translation("exact-kinsn", (f"HC_KINSN(HC_SHD_PAYLOAD({dst[0]}, {src[0]}, {parse_int(ops[2])}), {selector})",), f"{op} imm kinsn")
    if op in ALU_OP and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst is None:
            return Translation("warning-unmapped", (), f"ALU destination {ops[0]} is not in the BPF JIT register file")
        bpf_class = "BPF_ALU64" if dst[1] == 64 else "BPF_ALU"
        selector = MACHINE_ALU_SELECTOR.get((op, dst[1]))
        if src and selector:
            if op in {"shl", "shr"}:
                if src[2] != "rcx" or src[1] != 8:
                    return Translation("warning-unmapped", (), f"{op.upper()} variable count must be CL: {insn.raw}")
            elif dst[1] != src[1]:
                return Translation("warning-unmapped", (), f"{op.upper()} width is not supported: {insn.raw}")
            payload = machine_alu_rr_payload(dst[0], src[0])
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} reg kinsn")
        if selector and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = machine_alu_imm_payload(dst[0], parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} imm kinsn")
        if op == "xor" and src and dst[0] == src[0]:
            if dst[1] == 32:
                payload = machine_alu_rr_payload(dst[0], src[0])
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORL)",), "xorl zero-idiom kinsn")
            if dst[1] == 8:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_RR_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb zero-idiom kinsn")
            if is_shadow_reg_name(dst[0]):
                return Translation("warning-unmapped", (), f"{insn.raw} needs a shadow-aware xor kinsn")
            return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level xor zero-idiom kinsn")
        if op == "and" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"andb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {imm}), MICRO_HANDCRAFT_BPF_X86_ANDB)",), "andb imm kinsn")
        if op == "add" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"addb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {imm}), MICRO_HANDCRAFT_BPF_X86_ADDB)",), "addb imm kinsn")
        if op == "xor" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"xorb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_IMM_PAYLOAD({dst[0]}, {imm}), MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb imm kinsn")
        if op == "xor" and dst[1] == 8 and src:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_X86_RR_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb reg kinsn")
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
                return Translation("warning-unmapped", (), f"ALU memory base {base} is not in the BPF JIT register file")
            if index is None and selector and dst[1] in {32, 64} and size == ("BPF_DW" if dst[1] == 64 else "BPF_W"):
                payload = f"HC_X86_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} memory-source kinsn")
            if index is None and op == "xor" and dst[1] == 16 and size == "BPF_H":
                payload = f"HC_X86_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORW)",), "xorw memory-source kinsn")
            if index is not None and selector and dst[1] in {32, 64} and size == ("BPF_DW" if dst[1] == 64 else "BPF_W"):
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"{op}{dst[1]} SIB memory-source kinsn")
            if index is not None and op == "xor" and dst[1] == 8 and size == "BPF_B":
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                payload = f"HC_X86_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORB)",), "xorb SIB memory-source kinsn")
            return Translation("warning-unmapped", (), f"ALU memory source form has no current selector: {insn.raw}")
        return Translation("warning-unmapped", (), f"ALU source {ops[1]} is not supported")
    if op == "sar" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst is None:
            return Translation("warning-unmapped", (), f"SAR destination {ops[0]} is not in the BPF JIT register file")
        if not re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("warning-unmapped", (), f"SAR source {ops[1]} is not an immediate")
        selector = MACHINE_ALU_SELECTOR.get(("sar", dst[1]))
        if selector:
            payload = machine_alu_imm_payload(dst[0], parse_int(ops[1]))
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, {selector})",), f"sar{dst[1]} imm kinsn")
        return Translation("warning-unmapped", (), f"{insn.raw} needs a machine-level sar kinsn")
    if op == "test" and len(ops) == 2:
        left = bpf_reg(ops[0])
        right = bpf_reg(ops[1])
        if left and right and left[0] == right[0] and left[1] == 64:
            payload = f"HC_X86_RR_PAYLOAD({left[0]}, {right[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTQ)",), "testq reg,reg kinsn")
        if left and right and left[1] == right[1] == 32:
            payload = f"HC_X86_RR_PAYLOAD({left[0]}, {right[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTL)",), "testl reg,reg kinsn")
        if left and right and left[1] == right[1] == 8:
            payload = f"HC_X86_RR_PAYLOAD({left[0]}, {right[0]})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB)",), "testb reg,reg kinsn")
        if left and left[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload = f"HC_X86_IMM_PAYLOAD({left[0]}, {parse_int(ops[1])})"
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB)",), "testb imm kinsn")
        return Translation("warning-unmapped", (), "only testq reg,same-reg is supported")
    if op == "inc" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if dst:
            if dst[1] == 32:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCL)",), "incl reg kinsn")
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCQ)",), "incq reg kinsn")
            return Translation("warning-unmapped", (), f"inc width {dst[1]} needs a machine-level inc kinsn")
        return Translation("warning-unmapped", (), f"INC destination {ops[0]} is not in the BPF JIT register file")
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
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_CMOV_STACK_PAYLOAD({dst[0]}, {src[0]}), {selector})",),
                "cmov kinsn using module shadow flags",
            )
        return Translation("warning-unmapped", (), f"{op} operands are not supported")
    if op in {"sete", "setne"} and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if dst:
            selector = "MICRO_HANDCRAFT_BPF_X86_SETE" if op == "sete" else "MICRO_HANDCRAFT_BPF_X86_SETNE"
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_SETCC_STACK_PAYLOAD({dst[0]}), {selector})",),
                "setcc kinsn using module shadow flags",
            )
        return Translation("warning-unmapped", (), f"SETcc destination {ops[0]} is not in the BPF JIT register file")
    if op == "setge":
        return Translation("warning-unmapped", (), "setge needs SF/OF shadow-flag support")
    if op == "sbb" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst and dst[1] == 32 and is_int(ops[1]) and parse_int(ops[1]) == 0:
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_X86_ALU_IMM_PAYLOAD({dst[0]}, 0), MICRO_HANDCRAFT_BPF_X86_SBBL)",),
                "sbbl imm0 kinsn using module shadow CF",
            )
        return Translation("warning-unmapped", (), f"SBB operand form has no current kinsn selector: {insn.raw}")
    return Translation("warning-unmapped", (), f"unsupported mnemonic or operand form: {insn.raw}")


def translate_all(insns: list[NativeInsn]) -> list[Translation]:
    return [translate(insn) for insn in insns]


def bpf_insn_len(code: str) -> int:
    if code.startswith("HC_KINSN("):
        return 2
    return 1


def relocate_branch_offsets(insns: list[NativeInsn], translations: list[Translation]) -> list[Translation]:
    pc_by_addr: dict[int, int] = {}
    pc_by_index: list[int] = []
    pc = 0
    for insn, trans in zip(insns, translations, strict=True):
        pc_by_addr.setdefault(insn.addr, pc)
        pc_by_index.append(pc)
        pc += sum(bpf_insn_len(code) for code in trans.code)

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
            off = target_pc - (code_pc + 1)
            code.append(item.replace(BRANCH_OFF, str(off)))
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
        "    HC_MOV64_IMM(BPF_REG_6, 0),",
        "    HC_MOV64_IMM(BPF_REG_7, 0),",
        "    HC_MOV64_IMM(BPF_REG_8, 0),",
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
