#!/usr/bin/env python3
"""Translate x86 native asm text into a handcraft.c candidate.

The converter is intentionally conservative: instructions that cannot be
represented one-to-one by the current handcraft BPF/kinsn surface are emitted as
explicit warnings in the generated C and report, but they do not stop generation.
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
TEMP_REG_ORDER = ["BPF_REG_6", "BPF_REG_7", "BPF_REG_8", "BPF_REG_9", "BPF_REG_5", "BPF_REG_4", "BPF_REG_3"]

REG_ALIAS: dict[str, tuple[str, int]] = {}
for base, aliases in {
    "rax": ("rax", "eax", "ax", "al"),
    "rbx": ("rbx", "ebx", "bx", "bl"),
    "rcx": ("rcx", "ecx", "cx", "cl"),
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
    for alias in aliases:
        width = 64 if alias.startswith("r") and not alias.endswith(("d", "w", "b")) else 32
        if alias.endswith("w") or alias in {"ax", "bx", "cx", "dx", "di", "si", "bp", "sp"}:
            width = 16
        if alias.endswith("b") or alias in {"al", "bl", "cl", "dl", "dh", "dil", "sil", "bpl", "spl"}:
            width = 8
        REG_ALIAS[alias] = (base, width)

OBJ_LINE_RE = re.compile(r"^\s*(?P<addr>[0-9a-f]+):\s+(?P<bytes>(?:[0-9a-f]{2}\s+)+)\s*(?P<asm>.*)$")
ASM_LINE_RE = re.compile(r"^\s*(?P<mnemonic>[a-z][a-z0-9]*)\s*(?P<operands>.*)$")
SIZE_BY_PTR = {"BYTE": "BPF_B", "WORD": "BPF_H", "DWORD": "BPF_W", "QWORD": "BPF_DW"}
DIRECT_LOAD_SELECTOR = {
    "BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM",
    "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM",
    "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL_MEM",
    "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM",
}
DIRECT_STORE_SELECTOR = {
    "BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG",
    "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVW_MEM_REG",
    "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG",
    "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG",
}
ALU_OP = {"add": "BPF_ADD", "sub": "BPF_SUB", "xor": "BPF_XOR", "or": "BPF_OR", "and": "BPF_AND", "shl": "BPF_LSH", "shr": "BPF_RSH"}
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
    raw: str
    mnemonic: str
    operands: tuple[str, ...]


@dataclass(frozen=True)
class Translation:
    status: str
    code: tuple[str, ...]
    note: str
    target_addr: int | None = None


@dataclass(frozen=True)
class FlagProof:
    source: str
    lhs: str
    width: int
    rhs: str | None = None
    imm: int | None = None


def parse_int(text: str) -> int:
    text = text.strip()
    if text.startswith("-"):
        return -parse_int(text[1:])
    return int(text, 16) if text.lower().startswith("0x") else int(text, 10)


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
            insns.append(NativeInsn(
                addr=int(obj.group("addr"), 16),
                raw=asm,
                mnemonic=parsed.group("mnemonic"),
                operands=split_operands(parsed.group("operands")),
            ))
            continue
        if line.startswith("\t") or line.startswith(" "):
            asm = line.split("#", 1)[0].strip()
            parsed = ASM_LINE_RE.match(asm)
            if parsed and not asm.startswith((".", "#")):
                insns.append(NativeInsn(0, asm, parsed.group("mnemonic"), split_operands(parsed.group("operands"))))
    return insns


def reg(operand: str) -> tuple[str, int] | None:
    return REG_ALIAS.get(operand.strip().lower().lstrip("%"))


def bpf_reg(operand: str) -> tuple[str, int, str] | None:
    parsed = reg(operand)
    if parsed is None:
        return None
    base, width = parsed
    mapped = BPF_REG_BY_X86.get(base)
    if mapped is None:
        return None
    return mapped, width, base


def is_bpf_reg_name(name: str) -> bool:
    return name.startswith("BPF_REG_")


def is_shadow_reg_name(name: str) -> bool:
    return name.startswith("HC_X86_")


def translated_reg_warning(insn: NativeInsn) -> str | None:
    return None


def configure_temp_regs(insns: list[NativeInsn]) -> None:
    used: set[str] = set()
    for insn in insns:
        for operand in insn.operands:
            for token in re.findall(r"\b[a-z][a-z0-9]*\b", operand.lower()):
                parsed = reg(token)
                if parsed is None:
                    continue
                base = parsed[0]
                mapped = BPF_REG_BY_X86.get(base)
                if mapped is not None and is_bpf_reg_name(mapped):
                    used.add(mapped)
    candidates = ["BPF_REG_6", "BPF_REG_7", "BPF_REG_8", "BPF_REG_9", "BPF_REG_5", "BPF_REG_4", "BPF_REG_3"]
    globals()["TEMP_REG_ORDER"] = [reg_name for reg_name in candidates if reg_name not in used] + candidates


def reg_reg_payload(dst: str, src: str) -> tuple[str, str]:
    if is_shadow_reg_name(dst) or is_shadow_reg_name(src):
        tmp = temp_reg(dst, src)
        if tmp is None:
            return "", "no verifier temp register available"
        return f"HC_REG_REG_TMP_PAYLOAD({dst}, {src}, {tmp})", f"; verifier instantiate uses temp {tmp}"
    return f"HC_REG_REG_PAYLOAD({dst}, {src})", ""


def cmp_rr_payload(lhs: str, rhs: str) -> tuple[str, str]:
    if is_shadow_reg_name(lhs) or is_shadow_reg_name(rhs):
        tmp_lhs = temp_reg(lhs, rhs)
        tmp_rhs = temp_reg(lhs, rhs, tmp_lhs or "")
        if tmp_lhs is None or tmp_rhs is None:
            return "", "no verifier temp registers available"
        return f"HC_REG_REG_TMP2_PAYLOAD({lhs}, {rhs}, {tmp_lhs}, {tmp_rhs})", f"; verifier instantiate uses temps {tmp_lhs}/{tmp_rhs}"
    return f"HC_REG_REG_PAYLOAD({lhs}, {rhs})", ""


def reg_imm_payload(reg_name: str, imm: int) -> tuple[str, str]:
    if is_shadow_reg_name(reg_name):
        tmp = temp_reg(reg_name)
        if tmp is None:
            return "", "no verifier temp register available"
        return f"HC_REG_TMP_IMM_PAYLOAD({reg_name}, {tmp}, {imm})", f"; verifier instantiate uses temp {tmp}"
    return f"HC_REG_IMM_PAYLOAD({reg_name}, {imm})", ""


def reg_payload(reg_name: str) -> tuple[str, str]:
    if is_shadow_reg_name(reg_name):
        tmp = temp_reg(reg_name)
        if tmp is None:
            return "", "no verifier temp register available"
        return f"HC_REG_TMP_PAYLOAD({reg_name}, {tmp})", f"; verifier instantiate uses temp {tmp}"
    return f"HC_REG_PAYLOAD({reg_name})", ""


def temp_reg(*avoid: str) -> str | None:
    avoided = set(avoid)
    for candidate in TEMP_REG_ORDER:
        if candidate not in avoided:
            return candidate
    return None


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


def emit_ldx(size: str, dst: str, src: str, off: int) -> str:
    return f"HC_LDX({size}, {dst}, {src}, {off})"


def emit_stx(size: str, dst: str, src: str, off: int) -> str:
    return f"HC_STX({size}, {dst}, {src}, {off})"


def translate_cmp_jcc(cmp_insn: NativeInsn, jcc_insn: NativeInsn, placeholder: int) -> Translation:
    if len(cmp_insn.operands) != 2 or len(jcc_insn.operands) != 1:
        return Translation("warning-unmapped", (), "cmp/jcc operands are not supported")
    target_addr = parse_branch_target(jcc_insn.operands[0])
    if target_addr is None:
        return Translation("warning-unmapped", (), f"cannot parse branch target {jcc_insn.operands[0]}")
    op = JCC_OP.get(jcc_insn.mnemonic)
    if op is None:
        return Translation("warning-unmapped", (), f"branch {jcc_insn.mnemonic} has no BPF unsigned jmp mapping")

    lhs = bpf_reg(cmp_insn.operands[0])
    rhs = bpf_reg(cmp_insn.operands[1])
    if lhs and rhs and is_bpf_reg_name(lhs[0]) and is_bpf_reg_name(rhs[0]):
        return Translation(
            "bpf-branch",
            (f"HC_JMP_REG({op}, {lhs[0]}, {rhs[0]}, __OFF_{placeholder}__)",),
            f"lowered {cmp_insn.raw} + {jcc_insn.raw} to verifier-visible BPF branch",
            target_addr,
        )
    if lhs and is_bpf_reg_name(lhs[0]) and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", cmp_insn.operands[1]):
        return Translation(
            "bpf-branch",
            (f"HC_RAW(BPF_JMP | {op} | BPF_K, {lhs[0]}, 0, __OFF_{placeholder}__, {parse_int(cmp_insn.operands[1])})",),
            f"lowered {cmp_insn.raw} + {jcc_insn.raw} to verifier-visible BPF branch",
            target_addr,
        )
    if "[" in cmp_insn.operands[0] and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", cmp_insn.operands[1]):
        mem = parse_mem(cmp_insn.operands[0])
        size = size_from_mem(cmp_insn.operands[0]) or "BPF_W"
        if mem is not None and mem[1] is None:
            base = bpf_reg(mem[0] or "")
            tmp = temp_reg(base[0] if base else "")
            if base is not None and tmp is not None:
                return Translation(
                    "bpf-branch",
                    (
                        emit_ldx(size, tmp, base[0], mem[3]),
                        f"HC_RAW(BPF_JMP | {op} | BPF_K, {tmp}, 0, __OFF_{placeholder}__, {parse_int(cmp_insn.operands[1])})",
                    ),
                    f"lowered {cmp_insn.raw} + {jcc_insn.raw} to verifier-visible load+branch",
                    target_addr,
                )
    return Translation("warning-unmapped", (), f"cannot lower {cmp_insn.raw} + {jcc_insn.raw} to BPF branch")


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
    base_reg = bpf_reg(base)
    if base_reg is None:
        return Translation("warning-unmapped", (), f"memory base {base} is not in the BPF JIT register file")
    if base_reg[0] == "BPF_REG_1" and index is None and size == "BPF_DW" and off in {0, 8}:
        bpf_off = 0 if off == 0 else 4
        return Translation(
            "warning-context-abi",
            (emit_ldx("BPF_W", dst[0], base_reg[0], bpf_off),),
            f"native xdp_md uses 64-bit host pointer field at off {off}; BPF XDP ctx uses u32 field at off {bpf_off}",
        )
    if index is not None:
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"SIB index {index} scale {scale} is not expressible")
        target = {"BPF_B": "MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB", "BPF_H": "MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB", "BPF_W": "MICRO_HANDCRAFT_BPF_X86_MOVL_SIB", "BPF_DW": "MICRO_HANDCRAFT_BPF_X86_MOVQ_SIB"}.get(size)
        if target is None:
            return Translation("warning-unmapped", (), f"SIB load size {size} has no current selector")
        payload = f"HC_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), "indexed memory load via x86 SIB kinsn")
    target = DIRECT_LOAD_SELECTOR.get(size)
    if target is None:
        return Translation("bpf-jit", (emit_ldx(size, dst[0], base_reg[0], off),), "direct load; exactness depends on kernel BPF JIT encoding")
    return Translation(
        "exact-kinsn",
        (f"HC_KINSN(HC_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off}), {target})",),
        "direct memory load via x86 kinsn selector",
    )


def cmp_flag_kind(width: int, has_imm: bool) -> str:
    if width == 32:
        return "HC_FLAG_CMP_IMM32" if has_imm else "HC_FLAG_CMP_RR32"
    return "HC_FLAG_CMP_IMM64" if has_imm else "HC_FLAG_CMP_RR64"


def flag_proof_from_cmp(insn: NativeInsn) -> FlagProof | None:
    if insn.mnemonic != "cmp" or len(insn.operands) != 2:
        return None
    lhs = bpf_reg(insn.operands[0])
    rhs = bpf_reg(insn.operands[1])
    if lhs and rhs and lhs[1] == rhs[1] and lhs[1] in {32, 64}:
        return FlagProof("cmp_rr", lhs[0], lhs[1], rhs=rhs[0])
    if lhs and lhs[1] in {32, 64} and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", insn.operands[1]):
        return FlagProof("cmp_imm", lhs[0], lhs[1], imm=parse_int(insn.operands[1]))
    return None


def flag_proof_from_test(insn: NativeInsn) -> FlagProof | None:
    if insn.mnemonic != "test" or len(insn.operands) != 2:
        return None
    left = bpf_reg(insn.operands[0])
    right = bpf_reg(insn.operands[1])
    if left and right and left[0] == right[0] and left[1] == right[1] == 64:
        return FlagProof("test_reg", left[0], left[1])
    return None


def flags_preserved_by(insn: NativeInsn) -> bool:
    if insn.mnemonic in {"mov", "movabs", "movzx", "movsx", "lea", "nop", "data16"}:
        return True
    if insn.mnemonic == "cs" and insn.operands and insn.operands[0].startswith("nop"):
        return True
    return False


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
        return Translation("warning-unmapped", (), "native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR")
    if op == "ret":
        return Translation("bpf-jit", ("HC_EXIT()",), "BPF exit; kernel JIT emits the real return sequence")
    if op in JCC_OP or op == "jns":
        return Translation("warning-unmapped", (), "standalone x86 branch needs an immediately preceding cmp")
    if op == "jmp" and len(ops) == 1:
        target_addr = parse_branch_target(ops[0])
        if target_addr is None:
            return Translation("warning-unmapped", (), f"cannot parse branch target {ops[0]}")
        return Translation(
            "bpf-branch",
            ("HC_RAW(BPF_JMP | BPF_JA, 0, 0, __OFF_DIRECT__, 0)",),
            "lowered direct jmp to verifier-visible BPF jump",
            target_addr,
        )
    if op == "cmp" and len(ops) == 2:
        lhs = bpf_reg(ops[0])
        rhs = bpf_reg(ops[1])
        if lhs and rhs and lhs[1] == rhs[1] == 64:
            payload, note = cmp_rr_payload(lhs[0], rhs[0])
            if not payload:
                return Translation("warning-unmapped", (), f"CMP needs verifier temps: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ_RR)",), f"cmpq reg,reg kinsn{note}")
        if lhs and rhs and lhs[1] == rhs[1] == 32:
            payload, note = cmp_rr_payload(lhs[0], rhs[0])
            if not payload:
                return Translation("warning-unmapped", (), f"CMP needs verifier temps: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL_RR)",), f"cmpl reg,reg kinsn{note}")
        if lhs and lhs[1] == 64 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload, note = reg_imm_payload(lhs[0], parse_int(ops[1]))
            if not payload:
                return Translation("warning-unmapped", (), f"CMP needs verifier temp: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32)",), f"cmpq reg,imm32 kinsn{note}")
        if lhs and lhs[1] == 32 and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload, note = reg_imm_payload(lhs[0], parse_int(ops[1]))
            if not payload:
                return Translation("warning-unmapped", (), f"CMP needs verifier temp: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32)",), f"cmpl reg,imm32 kinsn{note}")
        return Translation("warning-unmapped", (), f"CMP operand form has no current kinsn selector: {insn.raw}")
    if len(ops) == 2 and op in {"mov", "movabs"}:
        dst, src = ops
        dst_reg = bpf_reg(dst)
        src_reg = bpf_reg(src)
        if dst_reg and src_reg:
            if dst_reg[1] == 64 and src_reg[1] == 64:
                payload, note = reg_reg_payload(dst_reg[0], src_reg[0])
                if not payload:
                    return Translation("warning-unmapped", (), f"movq needs verifier temp: {note}")
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVQ_RR)",),
                    f"movq register-to-register kinsn{note}",
                )
            if dst_reg[1] == 32 and src_reg[1] == 32:
                return Translation("bpf-jit", (f"HC_RAW(BPF_ALU | BPF_MOV | BPF_X, {dst_reg[0]}, {src_reg[0]}, 0, 0)",), "32-bit register move")
            return Translation("warning-unmapped", (), f"mixed-width register move {dst}, {src}")
        if dst_reg and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", src):
            imm = parse_int(src)
            if op == "movabs" or dst_reg[1] == 64 and abs(imm) > 0x7fffffff:
                return Translation("bpf-jit", (f"HC_LD_IMM64_RAW({dst_reg[0]}, 0, 0x{imm & ((1 << 64) - 1):x}ULL)",), "64-bit immediate load")
            if dst_reg[1] == 32:
                return Translation("bpf-jit", (f"HC_RAW(BPF_ALU | BPF_MOV | BPF_K, {dst_reg[0]}, 0, 0, {imm})",), "32-bit immediate move")
            return Translation("bpf-jit", (f"HC_MOV64_IMM({dst_reg[0]}, {imm})",), "64-bit immediate move")
        mem_size = size_from_mem(src) or ("BPF_DW" if dst_reg and dst_reg[1] == 64 else "BPF_W")
        if dst_reg and "[" in src:
            return translate_mem_load(dst, src, mem_size)
        if "[" in dst and src_reg:
            mem = parse_mem(dst)
            size = size_from_mem(dst) or ("BPF_DW" if src_reg[1] == 64 else "BPF_W")
            if mem is None or mem[1] is not None:
                return Translation("warning-unmapped", (), f"store operand {dst} is not a direct base+disp memory reference")
            base = bpf_reg(mem[0] or "")
            if base is None:
                return Translation("warning-unmapped", (), f"store base {mem[0]} is not in the BPF JIT register file")
            target = DIRECT_STORE_SELECTOR.get(size)
            if target is None:
                return Translation("bpf-jit", (emit_stx(size, base[0], src_reg[0], mem[3]),), "direct store")
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_MEM_PAYLOAD({src_reg[0]}, {base[0]}, {mem[3]}), {target})",),
                "direct memory store via x86 kinsn selector",
            )
        if "[" in dst and re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", src):
            mem = parse_mem(dst)
            size = size_from_mem(dst) or "BPF_W"
            if mem is None or mem[1] is not None:
                return Translation("warning-unmapped", (), f"store operand {dst} is not a direct base+disp memory reference")
            base = bpf_reg(mem[0] or "")
            if base is None:
                return Translation("warning-unmapped", (), f"store base {mem[0]} is not in the BPF JIT register file")
            imm = parse_int(src)
            if size == "BPF_B":
                return Translation(
                    "exact-kinsn",
                    (f"HC_KINSN(HC_STORE_IMM_PAYLOAD({base[0]}, {mem[3]}, {imm}), MICRO_HANDCRAFT_BPF_X86_MOVB_IMM_MEM)",),
                    "movb immediate memory store via x86 kinsn selector",
                )
            return Translation("bpf-jit", (f"HC_ST({size}, {base[0]}, {mem[3]}, {imm})",), "immediate memory store")
    if op == "movzx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] in {8, 16}:
            selector = "MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR" if src[1] == 8 else "MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR"
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), {selector})",), f"movzx r32,r{src[1]} kinsn")
        size = size_from_mem(ops[1])
        if size not in {"BPF_B", "BPF_H"}:
            return Translation("warning-unmapped", (), f"movzx source size not recognized: {ops[1]}")
        return translate_mem_load(ops[0], ops[1], size)
    if op == "movsx" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 32 and src[1] == 16:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_MOVSWL_RR)",), "movswl reg kinsn")
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
        base_reg = bpf_reg(base)
        index_reg = bpf_reg(index)
        slog2 = scale_log2(scale)
        if base_reg is None or index_reg is None or slog2 is None:
            return Translation("warning-unmapped", (), f"movsxd SIB operand is not in the BPF register file: {ops[1]}")
        tmp = temp_reg(dst[0], base_reg[0], index_reg[0])
        if tmp is None:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        payload = f"HC_SIB_TMP_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off}, {tmp})"
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB)",), f"movsxd SIB kinsn; verifier instantiate uses temp {tmp}")
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
        payload = (
            f"HC_LEA_PAYLOAD({dst[0]}, {base_reg[0] if base_reg else 0}, "
            f"{index_reg[0] if index_reg else 0}, {slog2}, {1 if base_reg else 0}, {1 if index_reg else 0}, {disp})"
        )
        return Translation("exact-kinsn", (f"HC_KINSN({payload}, {target})",), "LEA via x86 kinsn selector")
    if op == "rol" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst and ops[1].lower() == "cl" and dst[1] in {32, 64}:
            tmp_shift = temp_reg(dst[0], "BPF_REG_4")
            tmp_value = temp_reg(dst[0], "BPF_REG_4", tmp_shift or "")
            if tmp_shift is None or tmp_value is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            selector = "MICRO_HANDCRAFT_BPF_X86_ROLQ_CL" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_ROLL_CL"
            width = "q" if dst[1] == 64 else "l"
            return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_CL_PAYLOAD({dst[0]}, BPF_REG_4, {tmp_shift}, {tmp_value}), {selector})",), f"rol{width} cl kinsn; verifier instantiate uses temps {tmp_shift}/{tmp_value}")
        if dst and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            if dst[1] == 64:
                tmp = temp_reg(dst[0])
                if tmp is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_PAYLOAD({dst[0]}, {dst[0]}, {parse_int(ops[1])}, {tmp}), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM)",), f"rolq imm kinsn; verifier instantiate uses temp {tmp}")
            if dst[1] == 32:
                tmp = temp_reg(dst[0])
                if tmp is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                return Translation("exact-kinsn", (f"HC_KINSN(HC_ROTATE_PAYLOAD({dst[0]}, {dst[0]}, {parse_int(ops[1])}, {tmp}), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM)",), f"roll imm kinsn; verifier instantiate uses temp {tmp}")
            if dst[1] == 16 and parse_int(ops[1]) == 8:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM)",), "rolw imm8 kinsn")
        return Translation("warning-unmapped", (), f"ROL width/register not supported by current selectors: {ops[0]}")
    if op == "popcnt" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            tmp1 = temp_reg(dst[0], src[0])
            tmp2 = temp_reg(dst[0], src[0], tmp1 or "")
            if tmp1 is None or tmp2 is None:
                return Translation("warning-unmapped", (), f"no verifier temp registers available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_POPCNT_PAYLOAD({dst[0]}, {src[0]}, {tmp1}, {tmp2}), MICRO_HANDCRAFT_BPF_X86_POPCNTQ)",), f"popcntq kinsn; verifier instantiate uses temps {tmp1}/{tmp2}")
        return Translation("warning-unmapped", (), "only popcntq reg,reg is supported")
    if op == "imul" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == 64 and src[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_PAYLOAD({dst[0]}, {src[0]}), MICRO_HANDCRAFT_BPF_X86_IMULQ_RR)",), "imulq reg,reg kinsn")
        return Translation("warning-unmapped", (), f"IMUL operands are not in the 64-bit BPF JIT register file: {insn.raw}")
    if op == "not" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if not dst:
            return Translation("warning-unmapped", (), f"NOT destination {ops[0]} is not in the BPF JIT register file")
        if dst[1] == 8:
            tmp = temp_reg(dst[0])
            if tmp is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_NOT_NARROW_PAYLOAD({dst[0]}, {tmp}), MICRO_HANDCRAFT_BPF_X86_NOTB_R)",), f"notb reg kinsn; verifier instantiate uses temp {tmp}")
        if dst[1] == 16:
            tmp = temp_reg(dst[0])
            if tmp is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_NOT_NARROW_PAYLOAD({dst[0]}, {tmp}), MICRO_HANDCRAFT_BPF_X86_NOTW_R)",), f"notw reg kinsn; verifier instantiate uses temp {tmp}")
        if dst[1] == 32:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTL_R)",), "notl reg kinsn")
        if dst[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_NOTQ_R)",), "notq reg kinsn")
        return Translation("warning-unmapped", (), f"NOT width not supported: {ops[0]}")
    if op == "bswap" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if not dst:
            return Translation("warning-unmapped", (), f"BSWAP destination {ops[0]} is not in the BPF JIT register file")
        if dst[1] == 32:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_BSWAPL)",), "bswapl kinsn")
        if dst[1] == 64:
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_BSWAPQ)",), "bswapq kinsn")
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
        tmp = temp_reg(dst[0], src[0])
        if tmp is None:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        if op == "shld":
            selector = "MICRO_HANDCRAFT_BPF_X86_SHLDQ_IMM" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHLDL_IMM"
        else:
            selector = "MICRO_HANDCRAFT_BPF_X86_SHRDQ_IMM" if dst[1] == 64 else "MICRO_HANDCRAFT_BPF_X86_SHRDL_IMM"
        return Translation("exact-kinsn", (f"HC_KINSN(HC_SHD_PAYLOAD({dst[0]}, {src[0]}, {parse_int(ops[2])}, {tmp}), {selector})",), f"{op} imm kinsn; verifier instantiate uses temp {tmp}")
    if op in ALU_OP and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst is None:
            return Translation("warning-unmapped", (), f"ALU destination {ops[0]} is not in the BPF JIT register file")
        bpf_class = "BPF_ALU64" if dst[1] == 64 else "BPF_ALU"
        if op == "xor" and src and dst[0] == src[0]:
            return Translation("bpf-jit", (f"HC_RAW({bpf_class} | BPF_MOV | BPF_K, {dst[0]}, 0, 0, 0)",), "zero idiom")
        if op == "shr" and dst[1] == 64 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM)",), "shrq imm kinsn")
        if op == "and" and dst[1] == 32 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {parse_int(ops[1])}), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32)",), "andl imm32 kinsn")
        if op == "and" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"andb immediate is out of range: {insn.raw}")
            tmp = temp_reg(dst[0])
            if tmp is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_TMP_PAYLOAD({dst[0]}, {imm}, {tmp}), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM)",), f"andb imm kinsn; verifier instantiate uses temp {tmp}")
        if op == "add" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"addb immediate is out of range: {insn.raw}")
            tmp = temp_reg(dst[0])
            if tmp is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_TMP_PAYLOAD({dst[0]}, {imm}, {tmp}), MICRO_HANDCRAFT_BPF_X86_ADDB_IMM)",), f"addb imm kinsn; verifier instantiate uses temp {tmp}")
        if op == "xor" and dst[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            imm = parse_int(ops[1])
            if imm < 0 or imm > 0xff:
                return Translation("warning-unmapped", (), f"xorb immediate is out of range: {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_IMM_PAYLOAD({dst[0]}, {imm}), MICRO_HANDCRAFT_BPF_X86_XORB_IMM)",), "xorb imm kinsn")
        if op == "xor" and dst[1] == 8 and src:
            tmp = temp_reg(dst[0], src[0])
            if tmp is None:
                return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
            return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_REG_TMP_PAYLOAD({dst[0]}, {src[0]}, {tmp}), MICRO_HANDCRAFT_BPF_X86_XORB_RR)",), f"xorb reg kinsn; verifier instantiate uses temp {tmp}")
        if src:
            return Translation("bpf-jit", (f"HC_RAW({bpf_class} | {ALU_OP[op]} | BPF_X, {dst[0]}, {src[0]}, 0, 0)",), "ALU reg operation")
        if re.match(r"^-?(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("bpf-jit", (f"HC_RAW({bpf_class} | {ALU_OP[op]} | BPF_K, {dst[0]}, 0, 0, {parse_int(ops[1])})",), "ALU imm operation")
        if "[" in ops[1]:
            mem = parse_mem(ops[1])
            size = size_from_mem(ops[1]) or ("BPF_DW" if dst[1] == 64 else "BPF_W")
            if mem is None:
                return Translation("warning-unmapped", (), f"ALU memory source is not parseable: {ops[1]}")
            base, index, scale, off = mem
            if base is None:
                return Translation("warning-unmapped", (), "ALU RIP/absolute memory source is not verifier-safe BPF memory")
            base_reg = bpf_reg(base)
            if base_reg is None:
                return Translation("warning-unmapped", (), f"ALU memory base {base} is not in the BPF JIT register file")
            if index is None and op == "xor" and dst[1] == 32 and size == "BPF_W":
                tmp = temp_reg(dst[0], base_reg[0])
                if tmp is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                payload = f"HC_ALU_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off}, {tmp}, 0)"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORL_MEM)",), f"xorl memory-source kinsn; verifier instantiate uses temp {tmp}")
            if index is None and op == "add" and dst[1] == 32 and size == "BPF_W":
                tmp = temp_reg(dst[0], base_reg[0])
                if tmp is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                payload = f"HC_ALU_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off}, {tmp}, 0)"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_ADDL_MEM)",), f"addl memory-source kinsn; verifier instantiate uses temp {tmp}")
            if index is None and op == "xor" and dst[1] == 16 and size == "BPF_H":
                tmp1 = temp_reg(dst[0], base_reg[0])
                tmp2 = temp_reg(dst[0], base_reg[0], tmp1 or "")
                if tmp1 is None or tmp2 is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                payload = f"HC_ALU_MEM_PAYLOAD({dst[0]}, {base_reg[0]}, {off}, {tmp1}, {tmp2})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORW_MEM)",), f"xorw memory-source kinsn; verifier instantiate uses temps {tmp1}/{tmp2}")
            if index is not None and op == "xor" and dst[1] == 8 and size == "BPF_B":
                index_reg = bpf_reg(index)
                slog2 = scale_log2(scale)
                if index_reg is None or slog2 is None:
                    return Translation("warning-unmapped", (), f"ALU SIB index {index} scale {scale} is not expressible")
                tmp1 = temp_reg(dst[0], base_reg[0], index_reg[0])
                tmp2 = temp_reg(dst[0], base_reg[0], index_reg[0], tmp1 or "")
                if tmp1 is None or tmp2 is None:
                    return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
                payload = f"HC_ALU_SIB_PAYLOAD({dst[0]}, {base_reg[0]}, {index_reg[0]}, {slog2}, {off}, {tmp1}, {tmp2})"
                return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_XORB_SIB)",), f"xorb SIB memory-source kinsn; verifier instantiate uses temps {tmp1}/{tmp2}")
            return Translation("warning-unmapped", (), f"ALU memory source form has no current selector: {insn.raw}")
        return Translation("warning-unmapped", (), f"ALU source {ops[1]} is not supported")
    if op == "sar" and len(ops) == 2:
        dst = bpf_reg(ops[0])
        if dst is None:
            return Translation("warning-unmapped", (), f"SAR destination {ops[0]} is not in the BPF JIT register file")
        if not re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            return Translation("warning-unmapped", (), f"SAR source {ops[1]} is not an immediate")
        bpf_class = "BPF_ALU64" if dst[1] == 64 else "BPF_ALU"
        return Translation("bpf-jit", (f"HC_RAW({bpf_class} | BPF_ARSH | BPF_K, {dst[0]}, 0, 0, {parse_int(ops[1])})",), "SAR immediate maps directly to BPF ARSH")
    if op == "test" and len(ops) == 2:
        left = bpf_reg(ops[0])
        right = bpf_reg(ops[1])
        if left and right and left[0] == right[0] and left[1] == 64:
            payload, note = reg_payload(left[0])
            if not payload:
                return Translation("warning-unmapped", (), f"TEST needs verifier temp: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTQ_RR)",), f"testq reg,reg kinsn{note}")
        if left and right and left[1] == right[1] == 32:
            payload, note = cmp_rr_payload(left[0], right[0])
            if not payload:
                return Translation("warning-unmapped", (), f"TEST needs verifier temps: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTL_RR)",), f"testl reg,reg kinsn{note}")
        if left and right and left[1] == right[1] == 8:
            payload, note = cmp_rr_payload(left[0], right[0])
            if not payload:
                return Translation("warning-unmapped", (), f"TEST needs verifier temps: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB_RR)",), f"testb reg,reg kinsn{note}")
        if left and left[1] == 8 and re.match(r"^(0x[0-9a-fA-F]+|\d+)$", ops[1]):
            payload, note = reg_imm_payload(left[0], parse_int(ops[1]))
            if not payload:
                return Translation("warning-unmapped", (), f"TEST needs verifier temp: {note}")
            return Translation("exact-kinsn", (f"HC_KINSN({payload}, MICRO_HANDCRAFT_BPF_X86_TESTB_IMM)",), f"testb imm kinsn{note}")
        return Translation("warning-unmapped", (), "only testq reg,same-reg is supported")
    if op == "inc" and len(ops) == 1:
        dst = bpf_reg(ops[0])
        if dst:
            if dst[1] == 64:
                return Translation("exact-kinsn", (f"HC_KINSN(HC_REG_PAYLOAD({dst[0]}), MICRO_HANDCRAFT_BPF_X86_INCQ)",), "incq reg kinsn")
            bpf_class = "BPF_ALU64" if dst[1] == 64 else "BPF_ALU"
            return Translation("bpf-jit", (f"HC_RAW({bpf_class} | BPF_ADD | BPF_K, {dst[0]}, 0, 0, 1)",), "inc lowered to add immediate")
        return Translation("warning-unmapped", (), f"INC destination {ops[0]} is not in the BPF JIT register file")
    if op in {"cmovne", "cmove"} and len(ops) == 2:
        dst = bpf_reg(ops[0])
        src = bpf_reg(ops[1])
        if dst and src and dst[1] == src[1] and dst[1] in {32, 64}:
            return Translation("warning-unmapped", (), f"{op} needs an adjacent test/cmp proof payload")
        return Translation("warning-unmapped", (), f"{op} operands are not supported")
    if op in {"sete", "setne", "setge"}:
        return Translation("warning-unmapped", (), f"{op} is flag-bound; automatic conversion needs an adjacent cmp/test proof")
    if op == "cmovb":
        return Translation("warning-unmapped", (), "cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof")
    if op == "sbb":
        return Translation("warning-unmapped", (), "sbb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof")
    return Translation("warning-unmapped", (), f"unsupported mnemonic or operand form: {insn.raw}")


def translate_cmov_with_flags(insn: NativeInsn, flags: FlagProof) -> Translation:
    dst = bpf_reg(insn.operands[0])
    src = bpf_reg(insn.operands[1])
    if dst and src and dst[1] == src[1] and dst[1] in {32, 64}:
        tmp = temp_reg(dst[0], src[0])
        if tmp is None:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        if dst[1] == 64:
            selector = "MICRO_HANDCRAFT_BPF_X86_CMOVNEQ_RR" if insn.mnemonic == "cmovne" else "MICRO_HANDCRAFT_BPF_X86_CMOVEQ_RR"
        else:
            selector = "MICRO_HANDCRAFT_BPF_X86_CMOVNEL_RR" if insn.mnemonic == "cmovne" else "MICRO_HANDCRAFT_BPF_X86_CMOVEL_RR"
        if flags.source in {"test_reg", "cmp_rr", "cmp_imm"}:
            return Translation(
                "exact-kinsn",
                (f"HC_KINSN(HC_CMOV_STACK_PAYLOAD({dst[0]}, {src[0]}, {tmp}), {selector})",),
                f"cmov kinsn using adjacent shadow flags; verifier instantiate uses temp {tmp}",
            )
    return Translation("warning-unmapped", (), f"{insn.mnemonic} operands or flag proof are not supported")


def translate_setcc_with_flags(insn: NativeInsn, flags: FlagProof) -> Translation:
    if len(insn.operands) != 1:
        return Translation("warning-unmapped", (), f"{insn.mnemonic} operands are not supported")
    dst = bpf_reg(insn.operands[0])
    if dst is None:
        return Translation("warning-unmapped", (), f"SETcc destination {insn.operands[0]} is not in the BPF JIT register file")
    selector = {
        "sete": "MICRO_HANDCRAFT_BPF_X86_SETE_R",
        "setne": "MICRO_HANDCRAFT_BPF_X86_SETNE_R",
        "setge": "MICRO_HANDCRAFT_BPF_X86_SETGE_R",
    }[insn.mnemonic]
    if flags.source == "test_reg":
        tmp = temp_reg(dst[0], flags.lhs)
        if tmp is None or dst[0] == flags.lhs:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        return Translation(
            "exact-kinsn",
            (f"HC_KINSN(HC_SETCC_PAYLOAD({dst[0]}, {flags.lhs}, {tmp}), {selector})",),
            f"setcc kinsn using condition from adjacent test on {flags.lhs}",
        )
    if flags.source == "cmp_rr" and flags.rhs is not None:
        tmp_high = temp_reg(dst[0], flags.lhs, flags.rhs)
        tmp_cmp = temp_reg(dst[0], flags.lhs, flags.rhs, tmp_high or "")
        if tmp_high is None or tmp_cmp is None or dst[0] == flags.rhs:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        kind = cmp_flag_kind(flags.width, False)
        return Translation(
            "exact-kinsn",
            (f"HC_KINSN(HC_SETCC_CMP_RR_PAYLOAD({dst[0]}, {flags.lhs}, {flags.rhs}, {tmp_high}, {tmp_cmp}, {kind}), {selector})",),
            "setcc kinsn using adjacent cmp reg,reg proof payload",
        )
    if flags.source == "cmp_imm" and flags.imm is not None:
        tmp_high = temp_reg(dst[0], flags.lhs)
        tmp_cmp = temp_reg(dst[0], flags.lhs, tmp_high or "")
        if tmp_high is None or tmp_cmp is None:
            return Translation("warning-unmapped", (), f"no verifier temp register available for {insn.raw}")
        kind = cmp_flag_kind(flags.width, True)
        return Translation(
            "exact-kinsn",
            (f"HC_KINSN(HC_SETCC_CMP_IMM_PAYLOAD({dst[0]}, {flags.lhs}, {tmp_high}, {tmp_cmp}, {flags.imm}, {kind}), {selector})",),
            "setcc kinsn using adjacent cmp reg,imm proof payload",
        )
    return Translation("warning-unmapped", (), f"{insn.mnemonic} flag proof is not supported")


def translate_all(insns: list[NativeInsn]) -> list[Translation]:
    configure_temp_regs(insns)
    translations: list[Translation] = []
    pending_cmp: NativeInsn | None = None
    pending_flags: FlagProof | None = None
    for insn in insns:
        if insn.mnemonic == "cmp":
            trans = translate(insn)
            translations.append(trans)
            pending_cmp = insn
            pending_flags = flag_proof_from_cmp(insn)
            continue
        if pending_cmp is not None and insn.mnemonic in JCC_OP:
            trans = translate_cmp_jcc(pending_cmp, insn, len(translations))
            warning = translated_reg_warning(insn)
            if warning:
                trans = Translation(trans.status, trans.code, f"{trans.note}; {warning}", trans.target_addr)
            translations.append(trans)
            pending_cmp = None
            pending_flags = None
            continue
        if pending_flags is not None and insn.mnemonic in {"cmovne", "cmove"}:
            trans = translate_cmov_with_flags(insn, pending_flags)
            warning = translated_reg_warning(insn)
            if warning and trans.status not in {"warning-unmapped", "padding", "cmp-state"}:
                trans = Translation("warning-reg-remap", trans.code, f"{trans.note}; {warning}", trans.target_addr)
            translations.append(trans)
            pending_cmp = None
            continue
        if pending_flags is not None and insn.mnemonic in {"sete", "setne", "setge"}:
            trans = translate_setcc_with_flags(insn, pending_flags)
            warning = translated_reg_warning(insn)
            if warning and trans.status not in {"warning-unmapped", "padding", "cmp-state"}:
                trans = Translation("warning-reg-remap", trans.code, f"{trans.note}; {warning}", trans.target_addr)
            translations.append(trans)
            pending_cmp = None
            continue
        if pending_cmp is None and insn.mnemonic in {"je", "jne"} and translations:
            prior = insns[len(translations) - 1]
            if prior.mnemonic in {"and", "or", "xor", "add", "sub"} and prior.operands:
                flag_reg = bpf_reg(prior.operands[0])
                target_addr = parse_branch_target(insn.operands[0]) if insn.operands else None
                if flag_reg is not None and target_addr is not None:
                    op = "BPF_JEQ" if insn.mnemonic == "je" else "BPF_JNE"
                    trans = Translation(
                        "bpf-branch",
                        (f"HC_RAW(BPF_JMP | {op} | BPF_K, {flag_reg[0]}, 0, __OFF_{len(translations)}__, 0)",),
                        f"lowered flags from {prior.raw} + {insn.raw} to verifier-visible zero branch",
                        target_addr,
                    )
                    warning = translated_reg_warning(insn)
                    if warning:
                        trans = Translation(trans.status, trans.code, f"{trans.note}; {warning}", trans.target_addr)
                    translations.append(trans)
                    continue

        trans = translate(insn)
        if trans.status == "bpf-branch" and trans.code == ("HC_RAW(BPF_JMP | BPF_JA, 0, 0, __OFF_DIRECT__, 0)",):
            trans = Translation(
                trans.status,
                (f"HC_RAW(BPF_JMP | BPF_JA, 0, 0, __OFF_{len(translations)}__, 0)",),
                trans.note,
                trans.target_addr,
            )
        warning = translated_reg_warning(insn)
        if warning and trans.status not in {"warning-unmapped", "padding", "cmp-state"}:
            trans = Translation("warning-reg-remap", trans.code, f"{trans.note}; {warning}", trans.target_addr)
        translations.append(trans)
        pending_cmp = None if not flags_preserved_by(insn) else pending_cmp
        next_flags = flag_proof_from_test(insn)
        if next_flags is not None:
            pending_flags = next_flags
        elif not flags_preserved_by(insn):
            pending_flags = None
    return translations


def bpf_insn_len(code: str) -> int:
    if code.startswith("HC_KINSN(") or code.startswith("HC_LD_IMM64_RAW("):
        return 2
    return 1


def patch_branch_offsets(insns: list[NativeInsn], translations: list[Translation]) -> list[Translation]:
    pc_by_addr: dict[int, int] = {}
    call_pc_by_addr: dict[int, int] = {}
    pc_by_index: list[int] = []
    sidecar_pcs: set[int] = set()
    pc = 0
    for insn, trans in zip(insns, translations, strict=True):
        pc_by_addr.setdefault(insn.addr, pc)
        if trans.code and trans.code[0].startswith("HC_KINSN("):
            sidecar_pcs.add(pc)
            call_pc_by_addr.setdefault(insn.addr, pc + 1)
        pc_by_index.append(pc)
        pc += sum(bpf_insn_len(code) for code in trans.code)

    patched: list[Translation] = []
    for index, trans in enumerate(translations):
        if trans.target_addr is None:
            patched.append(trans)
            continue
        target_pc = call_pc_by_addr.get(trans.target_addr, pc_by_addr.get(trans.target_addr))
        if target_pc is None:
            patched.append(Translation(
                "warning-unmapped",
                (),
                f"{trans.note}; branch target 0x{trans.target_addr:x} is outside parsed asm",
                trans.target_addr,
            ))
            continue
        if target_pc in sidecar_pcs:
            target_pc += 1
        placeholder = f"__OFF_{index}__"
        code = []
        code_pc = pc_by_index[index]
        for item in trans.code:
            branch_pc = code_pc
            off = target_pc - (branch_pc + 1)
            code.append(item.replace(placeholder, str(off)))
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
    parser.add_argument("--report", type=Path, help=argparse.SUPPRESS)
    args = parser.parse_args()
    if args.report is not None:
        raise SystemExit("--report was removed; warnings are embedded in the generated handcraft C file")

    insns = parse_native_asm(args.input.read_text())
    translations = patch_branch_offsets(insns, translate_all(insns))
    write_outputs(insns, translations, args.output)
    warnings = sum(1 for item in translations if item.status.startswith("warning"))
    exact = sum(1 for item in translations if item.status == "exact-kinsn")
    bpf_jit = sum(1 for item in translations if item.status == "bpf-jit")
    bpf_branch = sum(1 for item in translations if item.status == "bpf-branch")
    padding = sum(1 for item in translations if item.status == "padding")
    print(
        f"insns={len(insns)} exact_kinsn={exact} bpf_jit={bpf_jit} "
        f"bpf_branch={bpf_branch} padding={padding} warnings={warnings}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
