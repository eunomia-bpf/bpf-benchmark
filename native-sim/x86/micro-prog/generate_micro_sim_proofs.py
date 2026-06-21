#!/usr/bin/env python3
"""Generate hardcoded x86-simulator verifier artifacts from micro Native ASM blocks."""

from __future__ import annotations

import argparse
import re
import subprocess
from dataclasses import replace
from dataclasses import dataclass
from pathlib import Path

import yaml


REPO_ROOT = Path(__file__).resolve().parents[3]
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
STAGE2_PROGRAMS = REPO_ROOT / "native-sim" / "test"
OUT_DIR = Path(__file__).resolve().parent
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
PROOF_OBJECT_DIR = OUT_DIR / "build" / "native-link"
MAX_REP_MOVS_COUNT = 64
MAX_MEMSET_COUNT = 1024
CHUNKED_PROOF_INSN_THRESHOLD = 2048
CHUNKED_PROOF_CHUNK_INSNS = 384
CHUNKED_PROOF_PC_DONE = "0xffffffffffffffffULL"

PTR_WIDTH = {
    "BYTE": 8,
    "WORD": 16,
    "DWORD": 32,
    "QWORD": 64,
}

REGS: dict[str, tuple[str, int, int]] = {}
for base, names in {
    "RAX": ("rax", "eax", "ax", "al", "ah"),
    "RBX": ("rbx", "ebx", "bx", "bl", "bh"),
    "RCX": ("rcx", "ecx", "cx", "cl", "ch"),
    "RDX": ("rdx", "edx", "dx", "dl", "dh"),
    "RSP": ("rsp", "esp", "sp", "spl"),
    "RBP": ("rbp", "ebp", "bp", "bpl"),
    "RSI": ("rsi", "esi", "si", "sil"),
    "RDI": ("rdi", "edi", "di", "dil"),
    "R8": ("r8", "r8d", "r8w", "r8b"),
    "R9": ("r9", "r9d", "r9w", "r9b"),
    "R10": ("r10", "r10d", "r10w", "r10b"),
    "R11": ("r11", "r11d", "r11w", "r11b"),
    "R12": ("r12", "r12d", "r12w", "r12b"),
    "R13": ("r13", "r13d", "r13w", "r13b"),
    "R14": ("r14", "r14d", "r14w", "r14b"),
    "R15": ("r15", "r15d", "r15w", "r15b"),
}.items():
    for name in names:
        width = 64
        if name.endswith("d") or name in {"eax", "ebx", "ecx", "edx", "esp", "ebp", "esi", "edi"}:
            width = 32
        if name.endswith("w") or name in {"ax", "bx", "cx", "dx", "sp", "bp", "si", "di"}:
            width = 16
        if name.endswith("b") or name in {"al", "ah", "bl", "bh", "cl", "ch", "dl", "dh", "spl", "bpl", "sil", "dil"}:
            width = 8
        shift = 8 if name in {"ah", "bh", "ch", "dh"} else 0
        REGS[name] = (f"X86_{base}", width, shift)

ALU_AUX = {
    "add": "X86_ALU_ADD",
    "sub": "X86_ALU_SUB",
    "xor": "X86_ALU_XOR",
    "or": "X86_ALU_OR",
    "and": "X86_ALU_AND",
    "adc": "X86_ALU_ADC",
    "shl": "X86_ALU_SHL",
    "shr": "X86_ALU_SHR",
    "sar": "X86_ALU_SAR",
    "rol": "X86_ALU_ROL",
    "imul": "X86_ALU_IMUL",
    "inc": "X86_ALU_INC",
    "dec": "X86_ALU_DEC",
    "not": "X86_ALU_NOT",
    "neg": "X86_ALU_NEG",
    "sbb": "X86_ALU_SBB",
}

CC_AUX = {
    "ja": "X86_CC_A",
    "jae": "X86_CC_AE",
    "jb": "X86_CC_B",
    "jbe": "X86_CC_BE",
    "je": "X86_CC_E",
    "jne": "X86_CC_NE",
    "jg": "X86_CC_G",
    "jge": "X86_CC_GE",
    "jl": "X86_CC_L",
    "jle": "X86_CC_LE",
    "js": "X86_CC_S",
    "jns": "X86_CC_NS",
    "cmova": "X86_CC_A",
    "cmovb": "X86_CC_B",
    "cmovbe": "X86_CC_BE",
    "cmove": "X86_CC_E",
    "cmovg": "X86_CC_G",
    "cmovge": "X86_CC_GE",
    "cmovae": "X86_CC_AE",
    "cmovl": "X86_CC_L",
    "cmovle": "X86_CC_LE",
    "cmovne": "X86_CC_NE",
    "cmovns": "X86_CC_NS",
    "cmovs": "X86_CC_S",
    "seta": "X86_CC_A",
    "setae": "X86_CC_AE",
    "setb": "X86_CC_B",
    "setbe": "X86_CC_BE",
    "sete": "X86_CC_E",
    "setg": "X86_CC_G",
    "setge": "X86_CC_GE",
    "setl": "X86_CC_L",
    "setle": "X86_CC_LE",
    "setne": "X86_CC_NE",
    "setns": "X86_CC_NS",
    "sets": "X86_CC_S",
}

WIDTH_CONST = {
    8: "X86_WIDTH_8",
    16: "X86_WIDTH_16",
    32: "X86_WIDTH_32",
    64: "X86_WIDTH_64",
}

@dataclass(frozen=True)
class Bench:
    name: str
    kind: str


@dataclass(frozen=True)
class NativeInsn:
    addr: int
    raw: str
    mnemonic: str
    operands: tuple[str, ...]
    reloc_symbol: str | None = None
    reloc_target: int | None = None
    sim_imm: int | None = None


@dataclass(frozen=True)
class EncodedInsn:
    op: str
    dst: str
    src: str
    flags: str
    aux: str
    imm: str


@dataclass(frozen=True)
class ChunkInsn:
    insn: NativeInsn
    is_subroutine: bool
    next_addr: int | None


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


def parse_asm_text(text: str) -> list[NativeInsn]:
    insns: list[NativeInsn] = []
    for line in text.splitlines():
        reloc = re.search(r"\bR_X86_64_[A-Z0-9_]+\s+(\S+)", line)
        if reloc is not None and insns:
            symbol = re.sub(r"([+-]0x[0-9a-fA-F]+)$", "", reloc.group(1))
            insns[-1] = replace(insns[-1], reloc_symbol=symbol)
            continue
        if ":" not in line:
            continue
        prefix, rest = line.split(":", 1)
        addr_text = prefix.strip()
        if not re.fullmatch(r"[0-9a-fA-F]+", addr_text):
            continue
        fields = rest.split("\t")
        if len(fields) < 3:
            continue
        asm = fields[-1].split("#", 1)[0].strip()
        if not asm or asm.startswith("<"):
            continue
        if asm.startswith("lock "):
            asm = asm.removeprefix("lock ").strip()
        match = re.match(r"(?P<mnemonic>[a-z][a-z0-9]*)\s*(?P<operands>.*)$", asm)
        if match is None:
            continue
        insns.append(NativeInsn(int(addr_text, 16), asm, match.group("mnemonic"),
                                split_operands(match.group("operands"))))
    return insns


def section_size(obj: Path, section: str) -> int:
    result = subprocess.run(["objdump", "-h", str(obj)], cwd=REPO_ROOT,
                            check=True, text=True, stdout=subprocess.PIPE)
    for line in result.stdout.splitlines():
        fields = line.split()
        if len(fields) >= 3 and fields[1] == section:
            return int(fields[2], 16)
    raise RuntimeError(f"{obj}: missing section {section}")


def rodata_bytes(obj: Path) -> bytes:
    result = subprocess.run(["objdump", "-s", "-j", ".native_link_rodata", str(obj)],
                            cwd=REPO_ROOT, check=False, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode != 0:
        return b""
    out = bytearray()
    for line in result.stdout.splitlines():
        fields = line.split()
        if len(fields) < 2 or not re.fullmatch(r"[0-9a-fA-F]+", fields[0]):
            continue
        for field in fields[1:]:
            if not re.fullmatch(r"[0-9a-fA-F]+", field) or len(field) % 2:
                break
            out.extend(int(field[i:i + 2], 16) for i in range(0, len(field), 2))
    return bytes(out)


def load_rodata16(obj: Path) -> dict[str, tuple[int, int]]:
    data = rodata_bytes(obj)
    if not data:
        return {}
    result = subprocess.run(["objdump", "-t", str(obj)], cwd=REPO_ROOT,
                            check=True, text=True, stdout=subprocess.PIPE)
    out: dict[str, tuple[int, int]] = {}
    for line in result.stdout.splitlines():
        fields = line.split()
        if ".native_link_rodata" not in fields:
            continue
        idx = fields.index(".native_link_rodata")
        if idx + 2 >= len(fields):
            continue
        offset = int(fields[0], 16)
        size = int(fields[idx + 1], 16)
        name = fields[-1]
        if size >= 16 and offset + 16 <= len(data):
            out[name] = (
                int.from_bytes(data[offset:offset + 8], "little"),
                int.from_bytes(data[offset + 8:offset + 16], "little"),
            )
    return out


def text_symbol_addrs(obj: Path) -> dict[str, int]:
    result = subprocess.run(["objdump", "-t", str(obj)], cwd=REPO_ROOT,
                            check=True, text=True, stdout=subprocess.PIPE)
    out: dict[str, int] = {}
    for line in result.stdout.splitlines():
        fields = line.split()
        if len(fields) >= 6 and ".text" in fields:
            out[fields[-1]] = int(fields[0], 16)
    return out


def parse_native_link_blob(
    name: str,
    proof_object_dir: Path,
) -> tuple[list[NativeInsn], int, dict[str, tuple[int, int]]]:
    proof_obj = proof_object_dir / f"{name}.proof.o"
    if not proof_obj.is_file():
        raise RuntimeError(f"missing proof object for {name}: {proof_obj}")
    rodata16 = load_rodata16(proof_obj)
    disasm = subprocess.run(
        ["objdump", "-dr", "-Mintel", str(proof_obj)], cwd=REPO_ROOT, check=True, text=True,
        stdout=subprocess.PIPE)
    symbols = text_symbol_addrs(proof_obj)
    insns = [
        replace(insn, reloc_target=symbols.get(insn.reloc_symbol))
        if insn.reloc_symbol in symbols else insn
        for insn in parse_asm_text(disasm.stdout)
    ]
    return insns, section_size(proof_obj, ".text"), rodata16


def parse_proof_object_program(
    name: str,
    proof_object_dir: Path,
) -> tuple[list[NativeInsn], dict[str, list[NativeInsn]], int | None, dict[str, tuple[int, int]]]:
    return parse_native_linked_program(name, proof_object_dir)


def normalize_native_link_entry_returns(
    insns: list[NativeInsn], blob_len: int
) -> list[NativeInsn]:
    out: list[NativeInsn] = []
    for insn in insns:
        if (
            insn.mnemonic == "jmp"
            and insn.operands
            and branch_target(insn.operands[0]) == blob_len
        ):
            out.append(
                NativeInsn(
                    addr=insn.addr,
                    raw=f"{insn.raw} ; native-link entry RET",
                    mnemonic="ret",
                    operands=(),
                )
            )
        else:
            out.append(insn)
    return out


def parse_native_linked_program(
    name: str,
    proof_object_dir: Path,
) -> tuple[list[NativeInsn], dict[str, list[NativeInsn]], int, dict[str, tuple[int, int]]]:
    insns, blob_len, rodata16 = parse_native_link_blob(name, proof_object_dir)
    insns = normalize_native_link_entry_returns(insns, blob_len)
    if not insns:
        return [], {}, blob_len, rodata16

    entry_addr = insns[0].addr
    insn_addrs = {insn.addr for insn in insns}
    exit_addr = max(
        [blob_len, *[
            branch_target(insn.operands[0])
            for insn in insns
            if insn.mnemonic in CC_AUX or insn.mnemonic == "jmp"
            if insn.operands
            if branch_target(insn.operands[0]) not in insn_addrs
        ]]
    )
    sub_starts = sorted({
        insn.reloc_target if insn.reloc_target is not None else branch_target(insn.operands[0])
        for insn in insns
        if insn.mnemonic == "call"
        and not is_helper_symbol(insn.reloc_symbol)
        and insn.operands
        and (insn.reloc_target is not None or has_direct_branch_target(insn.operands[0]))
        and (insn.reloc_symbol is None or insn.reloc_target is not None)
        and (insn.reloc_target if insn.reloc_target is not None else branch_target(insn.operands[0])) in insn_addrs
        and (insn.reloc_target if insn.reloc_target is not None else branch_target(insn.operands[0])) != entry_addr
    })
    if not sub_starts:
        return insns, {}, exit_addr, rodata16

    entry_end = sub_starts[0]
    entry = [insn for insn in insns if insn.addr < entry_end]
    subfunctions: dict[str, list[NativeInsn]] = {}
    for index, start in enumerate(sub_starts):
        end = sub_starts[index + 1] if index + 1 < len(sub_starts) else exit_addr
        fn_insns = [insn for insn in insns if start <= insn.addr < end]
        if fn_insns:
            subfunctions[f"native_link_sub_{start:x}"] = fn_insns
    return entry, subfunctions, exit_addr, rodata16


def parse_int(text: str) -> int:
    text = text.strip()
    if text.startswith("-"):
        return -parse_int(text[1:])
    return int(text, 16) if text.lower().startswith("0x") else int(text, 10)


def is_int(text: str) -> bool:
    return re.fullmatch(r"-?(0x[0-9a-fA-F]+|\d+)", text.strip()) is not None


def c_u64(value: int) -> str:
    return f"{value & 0xffffffffffffffff}ULL"


def c_ptr_u64(expr: str) -> str:
    return f"((__u64)(long){expr})"


def reg_info(operand: str) -> tuple[str, int, int] | None:
    return REGS.get(operand.strip().lower())


def is_mem(operand: str) -> bool:
    return "[" in operand and "]" in operand


def operand_width(operand: str, default: int = 64) -> int:
    stripped = operand.strip()
    for name, width in PTR_WIDTH.items():
        if stripped.startswith(f"{name} PTR"):
            return width
    parsed = reg_info(stripped)
    if parsed is not None:
        return parsed[1]
    return default


def mem_base_reg(operand: str) -> str:
    return parse_mem_terms(operand)[0]


def parse_mem_terms(operand: str) -> tuple[str, str, int, int]:
    inner_match = re.search(r"\[(.*?)\]", operand)
    if inner_match is None:
        return "X86_REG_NONE", "X86_REG_NONE", 0, 0
    inner = inner_match.group(1).replace(" ", "").replace("-", "+-")
    base = "X86_REG_NONE"
    index = "X86_REG_NONE"
    scale_log2 = 0
    disp = 0
    for part in filter(None, inner.split("+")):
        if "*" in part:
            reg_text, scale_text = part.split("*", 1)
            parsed = reg_info(reg_text)
            if parsed is not None:
                index = parsed[0]
            scale = parse_int(scale_text)
            scale_log2 = {1: 0, 2: 1, 4: 2, 8: 3}.get(scale, 0)
            continue
        parsed = reg_info(part)
        if parsed is not None:
            if base == "X86_REG_NONE":
                base = parsed[0]
            else:
                index = parsed[0]
            continue
        if is_int(part):
            disp += parse_int(part)
    return base, index, scale_log2, disp


def mem_aux(operand: str, mem_width: int | None = None,
            src_shift: int = 0) -> str:
    _base, index, scale_log2, _disp = parse_mem_terms(operand)
    if mem_width is not None:
        base = f"X86_MEM_AUX_FULL({index}, {scale_log2}, {WIDTH_CONST[mem_width]})"
    else:
        base = f"X86_MEM_AUX({index}, {scale_log2})"
    if src_shift:
        return f"({base} | X86_REG_AUX_SRC_SHIFT({src_shift}))"
    return base


def mem_disp(operand: str) -> int:
    return parse_mem_terms(operand)[3]


def branch_target(operand: str) -> int:
    match = re.match(r"(0x[0-9a-fA-F]+|[0-9a-fA-F]+)", operand.strip())
    return int(match.group(1), 16) if match is not None else 0


def has_direct_branch_target(operand: str) -> bool:
    return re.match(r"(0x[0-9a-fA-F]+|[0-9a-fA-F]+)", operand.strip()) is not None


def enc(op: str, dst: str = "X86_REG_NONE", src: str = "X86_REG_NONE",
        flags: str = "X86_WIDTH_64", aux: str = "0", imm: str = "0") -> EncodedInsn:
    return EncodedInsn(op, dst, src, flags, aux, imm)


def is_helper_symbol(symbol: str | None) -> bool:
    return bool(symbol and symbol.startswith("bpf_"))


def rodata_ident_map(rodata16: dict[str, tuple[int, int]]) -> dict[str, str]:
    return {symbol: f"__x86_rodata_{index}" for index, symbol in enumerate(rodata16)}


def encode(insn: NativeInsn, rodata_idents: dict[str, str]) -> EncodedInsn:
    op = insn.mnemonic
    ops = insn.operands

    if op in {"nop", "data16", "cs"}:
        return enc("X86_OP_NOP")
    if op == "ret":
        return enc("X86_OP_RET")
    if op == "jmp":
        return enc("X86_OP_JMP", imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op in CC_AUX and op.startswith("j"):
        return enc("X86_OP_JCC", aux=CC_AUX[op],
                   imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op == "call":
        if is_helper_symbol(insn.reloc_symbol):
            return enc("X86_OP_CALL_HELPER", imm=f"X86_SIM_HELPER_{insn.reloc_symbol}")
        if insn.reloc_symbol == "memcpy":
            if insn.sim_imm is None:
                return enc("X86_OP_CALL_MEMCPY_REG", imm=c_u64(MAX_MEMSET_COUNT))
            if insn.sim_imm < 0 or insn.sim_imm > MAX_MEMSET_COUNT:
                raise ValueError(f"memcpy length {insn.sim_imm} exceeds simulator bound in {insn.raw}")
            return enc("X86_OP_CALL_MEMCPY", imm=c_u64(insn.sim_imm))
        if insn.reloc_symbol == "memset":
            if insn.sim_imm is None:
                return enc("X86_OP_CALL_MEMSET_REG", imm=c_u64(MAX_MEMSET_COUNT))
            if insn.sim_imm < 0 or insn.sim_imm > MAX_MEMSET_COUNT:
                raise ValueError(f"memset length {insn.sim_imm} exceeds simulator bound in {insn.raw}")
            return enc("X86_OP_CALL_MEMSET", imm=c_u64(insn.sim_imm))
        if ops:
            call_reg = reg_info(ops[0])
            if call_reg is not None:
                return enc("X86_OP_CALL_REG", src=call_reg[0])
        return enc("X86_OP_CALL", imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op == "push":
        src = reg_info(ops[0]) if ops else None
        return enc("X86_OP_PUSH", src=src[0] if src else "X86_REG_NONE",
                   flags=WIDTH_CONST.get(src[1], "X86_WIDTH_64") if src else "X86_WIDTH_64")
    if op == "pop":
        dst = reg_info(ops[0]) if ops else None
        return enc("X86_OP_POP", dst=dst[0] if dst else "X86_REG_NONE",
                   flags=WIDTH_CONST.get(dst[1], "X86_WIDTH_64") if dst else "X86_WIDTH_64")
    if op.startswith("set") and op in CC_AUX:
        dst = reg_info(ops[0]) if ops else None
        if dst is None:
            if ops and is_mem(ops[0]):
                return enc("X86_OP_SETCC_MEM", dst=mem_base_reg(ops[0]),
                           aux=f"({mem_aux(ops[0], 8)} | X86_REG_AUX_SRC_SHIFT({CC_AUX[op]}))",
                           imm=c_u64(mem_disp(ops[0])))
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SETCC", dst=dst[0], flags="X86_WIDTH_8", aux=CC_AUX[op])
    if op.startswith("cmov") and op in CC_AUX:
        dst = reg_info(ops[0]) if len(ops) > 0 else None
        src = reg_info(ops[1]) if len(ops) > 1 else None
        if dst is not None and len(ops) > 1 and is_mem(ops[1]):
            width = operand_width(ops[1], dst[1])
            return enc("X86_OP_CMOV_MEM", dst=dst[0],
                       src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst[1]],
                       aux=f"({mem_aux(ops[1], width)} | X86_REG_AUX_SRC_SHIFT({CC_AUX[op]}))",
                       imm=c_u64(mem_disp(ops[1])))
        if dst is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_CMOV", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]], aux=CC_AUX[op])

    if op in {"mov", "movabs"}:
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst, src = ops
        dst_reg = reg_info(dst)
        src_reg = reg_info(src)
        if dst_reg and is_int(src):
            return enc("X86_OP_MOV_IMM", dst=dst_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], imm=c_u64(parse_int(src)))
        if dst_reg and src_reg:
            return enc("X86_OP_MOV_REG", dst=dst_reg[0], src=src_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]])
        if dst_reg and is_mem(src):
            if is_helper_symbol(insn.reloc_symbol):
                return enc("X86_OP_MOV_LOAD_HELPER_ID", dst=dst_reg[0],
                           imm=f"X86_SIM_HELPER_{insn.reloc_symbol}")
            if insn.reloc_symbol:
                if insn.reloc_symbol in rodata_idents:
                    raise ValueError(f"unsupported scalar rodata load: {insn.raw}")
                return enc("X86_OP_MOV_LOAD_MAP_PTR", dst=dst_reg[0],
                           imm=c_ptr_u64(f"&{insn.reloc_symbol}"))
            return enc("X86_OP_MOV_LOAD", dst=dst_reg[0], src=mem_base_reg(src),
                       flags=WIDTH_CONST[operand_width(src, dst_reg[1])],
                       aux=mem_aux(src),
                       imm=c_u64(mem_disp(src)))
        if is_mem(dst) and is_int(src):
            imm32 = parse_int(src) & 0xffffffff
            disp32 = mem_disp(dst) & 0xffffffff
            return enc("X86_OP_MOV_STORE_IMM", dst=mem_base_reg(dst),
                       flags=WIDTH_CONST[operand_width(dst)],
                       aux=mem_aux(dst),
                       imm=c_u64(imm32 | (disp32 << 32)))
        if is_mem(dst) and src_reg:
            return enc("X86_OP_MOV_STORE_REG", dst=mem_base_reg(dst),
                       src=src_reg[0], flags=WIDTH_CONST[operand_width(dst)],
                       aux=mem_aux(dst, src_shift=src_reg[2]),
                       imm=c_u64(mem_disp(dst)))
        raise ValueError(f"cannot encode {insn.raw}")

    if op in {"movaps", "movups"}:
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst, src = ops
        if dst.lower() == "xmm0" and is_mem(src):
            if insn.reloc_symbol:
                if insn.reloc_symbol not in rodata_idents:
                    raise ValueError(f"unsupported xmm reloc load: {insn.raw}")
                return enc("X86_OP_LOAD_XMM0", src="X86_REG_NONE",
                           imm=c_ptr_u64(rodata_idents[insn.reloc_symbol]))
            return enc("X86_OP_LOAD_XMM0", src=mem_base_reg(src),
                       aux=mem_aux(src), imm=c_u64(mem_disp(src)))
        if is_mem(dst) and src.lower() == "xmm0":
            return enc("X86_OP_STORE_XMM0", dst=mem_base_reg(dst),
                       aux=mem_aux(dst), imm=c_u64(mem_disp(dst)))
        raise ValueError(f"cannot encode {insn.raw}")

    if op in {"movzx", "movsx", "movsxd"}:
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        src_reg = reg_info(ops[1])
        if dst_reg is None:
            raise ValueError(f"cannot encode {insn.raw}")
        if src_reg:
            return enc("X86_OP_MOVSX_REG" if op in {"movsx", "movsxd"} else "X86_OP_MOVZX_REG",
                       dst=dst_reg[0], src=src_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], aux=WIDTH_CONST[src_reg[1]])
        if is_mem(ops[1]):
            mem_width = operand_width(ops[1], 32 if op == "movsxd" else dst_reg[1])
            return enc("X86_OP_MOVSX_LOAD" if op in {"movsx", "movsxd"} else "X86_OP_MOV_LOAD",
                       dst=dst_reg[0], src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst_reg[1]], aux=mem_aux(ops[1], mem_width),
                       imm=c_u64(mem_disp(ops[1])))
        raise ValueError(f"cannot encode {insn.raw}")

    if op == "cdqe":
        if ops:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_MOVSX_REG", dst="X86_RAX", src="X86_RAX",
                   flags="X86_WIDTH_64", aux="X86_WIDTH_32")

    if op == "lea":
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        if dst_reg is None:
            raise ValueError(f"cannot encode {insn.raw}")
        if "[rip" in ops[1].lower():
            return enc("X86_OP_LEA", dst=dst_reg[0], src="X86_REG_NONE",
                       flags=WIDTH_CONST[dst_reg[1]], aux="X86_LEA_AUX_RODATA",
                       imm=c_u64(mem_disp(ops[1])))
        return enc("X86_OP_LEA", dst=dst_reg[0], src=mem_base_reg(ops[1]),
                   flags=WIDTH_CONST[dst_reg[1]], aux=mem_aux(ops[1]),
                   imm=c_u64(mem_disp(ops[1])))

    if op in {"cmp", "test"}:
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        src_reg = reg_info(ops[1])
        width = operand_width(ops[0], src_reg[1] if src_reg else 64)
        if dst_reg and is_int(ops[1]):
            return enc("X86_OP_CMP_IMM" if op == "cmp" else "X86_OP_TEST_IMM",
                       dst=dst_reg[0], flags=WIDTH_CONST[dst_reg[1]],
                       imm=c_u64(parse_int(ops[1])))
        if dst_reg and src_reg:
            return enc("X86_OP_CMP_REG" if op == "cmp" else "X86_OP_TEST_REG",
                       dst=dst_reg[0], src=src_reg[0], flags=WIDTH_CONST[dst_reg[1]])
        if op == "cmp" and dst_reg and is_mem(ops[1]):
            return enc("X86_OP_CMP_REG_MEM",
                       dst=dst_reg[0], src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=mem_aux(ops[1], operand_width(ops[1], dst_reg[1])),
                       imm=c_u64(mem_disp(ops[1])))
        if op == "cmp" and is_mem(ops[0]) and src_reg:
            return enc("X86_OP_CMP_MEM_REG",
                       dst=mem_base_reg(ops[0]), src=src_reg[0],
                       flags=WIDTH_CONST[operand_width(ops[0], src_reg[1])],
                       aux=mem_aux(ops[0]),
                       imm=c_u64(mem_disp(ops[0])))
        if op == "test" and is_mem(ops[0]) and src_reg:
            return enc("X86_OP_TEST_MEM_REG",
                       dst=mem_base_reg(ops[0]), src=src_reg[0],
                       flags=WIDTH_CONST[operand_width(ops[0], src_reg[1])],
                       aux=mem_aux(ops[0]),
                       imm=c_u64(mem_disp(ops[0])))
        if is_mem(ops[0]) and is_int(ops[1]):
            return enc("X86_OP_CMP_MEM_IMM" if op == "cmp" else "X86_OP_TEST_MEM_IMM",
                       dst=mem_base_reg(ops[0]),
                       flags=WIDTH_CONST[operand_width(ops[0], width)],
                       aux=mem_aux(ops[0]),
                       imm=c_u64(parse_int(ops[1]) + (mem_disp(ops[0]) << 32)))
        if is_mem(ops[0]) or is_mem(ops[1]):
            raise ValueError(f"unsupported memory compare/test form: {insn.raw}")
        raise ValueError(f"cannot encode {insn.raw}")

    if op in ALU_AUX:
        if op in {"inc", "dec", "not", "neg"}:
            if len(ops) != 1:
                raise ValueError(f"cannot encode {insn.raw}")
            dst_reg = reg_info(ops[0])
            if dst_reg is None and is_mem(ops[0]):
                width = operand_width(ops[0], 64)
                return enc("X86_OP_ALU_MEM_UNARY",
                           dst=mem_base_reg(ops[0]),
                           flags=WIDTH_CONST[width],
                           aux=f"({mem_aux(ops[0], width)} | X86_MEM_AUX_ALU_OP({ALU_AUX[op]}))",
                           imm=c_u64(mem_disp(ops[0])))
            if dst_reg is None:
                raise ValueError(f"cannot encode {insn.raw}")
            imm = "1" if op in {"inc", "dec"} else "0"
            return enc("X86_OP_ALU_IMM", dst=dst_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], aux=ALU_AUX[op],
                       imm=imm)
        if op == "imul" and len(ops) == 3:
            dst = reg_info(ops[0])
            src = reg_info(ops[1])
            if dst is not None and is_mem(ops[1]) and is_int(ops[2]):
                width = operand_width(ops[1], dst[1])
                return enc("X86_OP_IMUL_MEM_IMM", dst=dst[0],
                           src=mem_base_reg(ops[1]),
                           flags=WIDTH_CONST[dst[1]],
                           aux=mem_aux(ops[1], width),
                           imm=c_u64(parse_int(ops[2]) + (mem_disp(ops[1]) << 32)))
            if dst is None or src is None or not is_int(ops[2]):
                raise ValueError(f"cannot encode {insn.raw}")
            return enc("X86_OP_IMUL_IMM", dst=dst[0], src=src[0],
                       flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])))
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        src_reg = reg_info(ops[1])
        if dst_reg and is_int(ops[1]):
            return enc("X86_OP_ALU_IMM", dst=dst_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], aux=ALU_AUX[op],
                       imm=c_u64(parse_int(ops[1])))
        if dst_reg and src_reg:
            return enc("X86_OP_ALU_REG", dst=dst_reg[0], src=src_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], aux=ALU_AUX[op])
        if dst_reg and is_mem(ops[1]):
            return enc("X86_OP_ALU_MEM", dst=dst_reg[0],
                       src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=f"({mem_aux(ops[1], operand_width(ops[1], dst_reg[1]))} | X86_MEM_AUX_ALU_OP({ALU_AUX[op]}))",
                       imm=c_u64(mem_disp(ops[1])))
        if is_mem(ops[0]) and src_reg:
            width = operand_width(ops[0], src_reg[1])
            return enc("X86_OP_ALU_MEM_REG",
                       dst=mem_base_reg(ops[0]), src=src_reg[0],
                       flags=WIDTH_CONST[width],
                       aux=f"({mem_aux(ops[0], width)} | X86_MEM_AUX_ALU_OP({ALU_AUX[op]}))",
                       imm=c_u64(mem_disp(ops[0])))
        if is_mem(ops[0]) and is_int(ops[1]):
            return enc("X86_OP_ALU_MEM_IMM",
                       dst=mem_base_reg(ops[0]),
                       flags=WIDTH_CONST[operand_width(ops[0], 64)],
                       aux=f"({mem_aux(ops[0])} | X86_MEM_AUX_ALU_OP({ALU_AUX[op]}))",
                       imm=c_u64(parse_int(ops[1]) + (mem_disp(ops[0]) << 32)))
        if is_mem(ops[0]) or is_mem(ops[1]):
            raise ValueError(f"unsupported memory ALU form: {insn.raw}")
        raise ValueError(f"cannot encode {insn.raw}")

    if op == "bt":
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is not None and is_int(ops[1]):
            return enc("X86_OP_BT_IMM", dst=dst[0],
                       flags=WIDTH_CONST[dst[1]],
                       imm=c_u64(parse_int(ops[1])))
        if is_mem(ops[0]) and is_int(ops[1]):
            width = operand_width(ops[0], 64)
            return enc("X86_OP_BT_MEM_IMM", dst=mem_base_reg(ops[0]),
                       flags=WIDTH_CONST[width],
                       aux=mem_aux(ops[0], width),
                       imm=c_u64(parse_int(ops[1]) + (mem_disp(ops[0]) << 32)))
        if dst is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_BT", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]])

    if op == "mulx":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        lo = reg_info(ops[0])
        hi = reg_info(ops[1])
        src = reg_info(ops[2])
        if lo is None or hi is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_MULX", dst=lo[0], src=src[0],
                   flags=WIDTH_CONST[lo[1]], aux=hi[0])

    if op == "andn":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src1 = reg_info(ops[1])
        src2 = reg_info(ops[2])
        if dst is not None and src1 is not None and is_mem(ops[2]):
            width = operand_width(ops[2], dst[1])
            return enc("X86_OP_ANDN_MEM", dst=dst[0], src=src1[0],
                       flags=WIDTH_CONST[dst[1]],
                       aux=f"({mem_aux(ops[2], width)} | X86_REG_AUX_SRC_SHIFT({mem_base_reg(ops[2])}))",
                       imm=c_u64(mem_disp(ops[2])))
        if dst is None or src1 is None or src2 is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_ANDN", dst=dst[0], src=src1[0],
                   flags=WIDTH_CONST[dst[1]], aux=src2[0])

    if op == "rep":
        if len(ops) != 2 or not ops[0].startswith("movs ") or not is_mem(ops[0]) or not is_mem(ops[1]):
            raise ValueError(f"cannot encode {insn.raw}")
        if insn.sim_imm is None:
            raise ValueError(f"cannot encode variable-length {insn.raw}")
        if insn.sim_imm < 0 or insn.sim_imm > MAX_REP_MOVS_COUNT:
            raise ValueError(f"rep movs count {insn.sim_imm} exceeds simulator bound in {insn.raw}")
        return enc("X86_OP_REP_MOVS", flags=WIDTH_CONST[operand_width(ops[0])],
                   imm=c_u64(insn.sim_imm))

    if op == "bzhi":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        count = reg_info(ops[2])
        if dst is None or count is None:
            raise ValueError(f"cannot encode {insn.raw}")
        if src is not None:
            return enc("X86_OP_BZHI", dst=dst[0], src=src[0],
                       flags=WIDTH_CONST[dst[1]], aux=count[0])
        if is_mem(ops[1]):
            width = operand_width(ops[0], operand_width(ops[1], dst[1]))
            return enc("X86_OP_BZHI_MEM", dst=dst[0], src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[width],
                       aux=f"({mem_aux(ops[1], width)} | X86_REG_AUX_SRC_SHIFT({count[0]}))",
                       imm=c_u64(mem_disp(ops[1])))
        raise ValueError(f"cannot encode {insn.raw}")

    if op == "bswap":
        dst = reg_info(ops[0]) if ops else None
        if dst is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_BSWAP", dst=dst[0], flags=WIDTH_CONST[dst[1]])
    if op == "popcnt":
        dst = reg_info(ops[0]) if len(ops) > 0 else None
        src = reg_info(ops[1]) if len(ops) > 1 else None
        if dst is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_POPCNT", dst=dst[0], src=src[0], flags=WIDTH_CONST[dst[1]])
    if op == "xchg":
        dst = reg_info(ops[0]) if len(ops) > 0 else None
        src = reg_info(ops[1]) if len(ops) > 1 else None
        if dst is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_XCHG", dst=dst[0], src=src[0], flags=WIDTH_CONST[dst[1]])
    if op == "movbe":
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        src_reg = reg_info(ops[1])
        if dst_reg is not None and is_mem(ops[1]):
            width = operand_width(ops[0], operand_width(ops[1], dst_reg[1]))
            return enc("X86_OP_MOVBE_LOAD", dst=dst_reg[0],
                       src=mem_base_reg(ops[1]), flags=WIDTH_CONST[width],
                       aux=mem_aux(ops[1], width), imm=c_u64(mem_disp(ops[1])))
        if is_mem(ops[0]) and src_reg is not None:
            width = operand_width(ops[0], src_reg[1])
            return enc("X86_OP_MOVBE_STORE", dst=mem_base_reg(ops[0]),
                       src=src_reg[0], flags=WIDTH_CONST[width],
                       aux=mem_aux(ops[0], width), imm=c_u64(mem_disp(ops[0])))
        raise ValueError(f"cannot encode {insn.raw}")
    if op in {"shlx", "shrx", "sarx"}:
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        count = reg_info(ops[2])
        if dst is None or count is None:
            raise ValueError(f"cannot encode {insn.raw}")
        alu = {"shlx": "X86_ALU_SHL", "shrx": "X86_ALU_SHR", "sarx": "X86_ALU_SAR"}[op]
        if src is not None:
            return enc("X86_OP_SHIFTX", dst=dst[0], src=src[0],
                       flags=WIDTH_CONST[dst[1]], aux=count[0], imm=alu)
        if is_mem(ops[1]):
            packed = f"(({mem_disp(ops[1]) & 0xffffffff}ULL << 32) | {alu})"
            return enc("X86_OP_SHIFTX_MEM", dst=dst[0],
                       src=mem_base_reg(ops[1]), flags=WIDTH_CONST[dst[1]],
                       aux=f"({mem_aux(ops[1], dst[1])} | X86_REG_AUX_SRC_SHIFT({count[0]}))",
                       imm=packed)
        raise ValueError(f"cannot encode {insn.raw}")
    if op == "rorx":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is None or not is_int(ops[2]):
            raise ValueError(f"cannot encode {insn.raw}")
        if src is not None:
            return enc("X86_OP_RORX", dst=dst[0], src=src[0],
                       flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])))
        if is_mem(ops[1]):
            packed = ((mem_disp(ops[1]) & 0xffffffff) << 32) | (parse_int(ops[2]) & 0xff)
            return enc("X86_OP_RORX_MEM", dst=dst[0],
                       src=mem_base_reg(ops[1]), flags=WIDTH_CONST[dst[1]],
                       aux=mem_aux(ops[1], dst[1]), imm=c_u64(packed))
        raise ValueError(f"cannot encode {insn.raw}")
    if op == "div":
        src = reg_info(ops[0]) if ops else None
        return enc("X86_OP_DIV", src=src[0] if src else "X86_REG_NONE",
                   flags=WIDTH_CONST[src[1]] if src else "X86_WIDTH_64")
    if op == "shld":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is None or src is None or not is_int(ops[2]):
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SHLD_IMM", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])))
    if op == "shrd":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is None or src is None or not is_int(ops[2]):
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SHRD_IMM", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])))

    raise ValueError(f"unsupported mnemonic: {insn.raw}")


def c_comment(text: str) -> str:
    return text.replace("*/", "* /")


DIRECT_STEP_MACROS = {
    "X86_OP_MOV_LOAD_MAP_PTR": "X86_SIM_L_WRITE_REG_MAP_PTR({dst}, (void *)(long)({imm}))",
    "X86_OP_MOV_LOAD_HELPER_ID": "X86_SIM_L_WRITE_REG_HELPER_ID({dst}, {imm})",
    "X86_OP_CALL_HELPER": "X86_SIM_BPF_CALL_ID({imm})",
    "X86_OP_CALL_MEMCPY": "X86_SIM_L_EXEC_CALL_MEMCPY({imm})",
    "X86_OP_CALL_MEMSET": "X86_SIM_L_EXEC_CALL_MEMSET({imm})",
    "X86_OP_CALL_MEMCPY_REG": "X86_SIM_L_EXEC_CALL_MEMCPY_REG({imm})",
    "X86_OP_CALL_MEMSET_REG": "X86_SIM_L_EXEC_CALL_MEMSET_REG({imm})",
    "X86_OP_CALL_REG": "X86_SIM_BPF_CALL_REG({src})",
    "X86_OP_MOV_IMM": "X86_SIM_L_EXEC_MOV_IMM({dst}, {flags}, {imm})",
    "X86_OP_MOV_REG": "X86_SIM_L_EXEC_MOV_REG({dst}, {src}, {flags})",
    "X86_OP_MOVZX_REG": "X86_SIM_L_EXEC_MOVX_REG({op}, {dst}, {src}, {flags}, {aux})",
    "X86_OP_MOVSX_REG": "X86_SIM_L_EXEC_MOVX_REG({op}, {dst}, {src}, {flags}, {aux})",
    "X86_OP_MOV_LOAD": "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_MOV_LOAD_SCALAR": "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_MOVSX_LOAD": "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_MOV_STORE_IMM": "X86_SIM_L_EXEC_STORE({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_MOV_STORE_REG": "X86_SIM_L_EXEC_STORE({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_LEA": "X86_SIM_L_EXEC_LEA({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_ALU_IMM": "X86_SIM_L_EXEC_ALU_IMM({dst}, {flags}, {aux}, {imm})",
    "X86_OP_ADD_IMM": "X86_SIM_L_EXEC_ALU_IMM({dst}, {flags}, {aux}, {imm})",
    "X86_OP_ALU_REG": "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})",
    "X86_OP_ADD_REG": "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})",
    "X86_OP_XOR_REG": "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})",
    "X86_OP_ALU_MEM": "X86_SIM_L_EXEC_ALU_MEM({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_ALU_MEM_UNARY": "X86_SIM_L_EXEC_ALU_MEM_UNARY({dst}, {flags}, {aux}, {imm})",
    "X86_OP_ALU_MEM_IMM": "X86_SIM_L_EXEC_ALU_MEM_IMM({dst}, {flags}, {aux}, {imm})",
    "X86_OP_ALU_MEM_REG": "X86_SIM_L_EXEC_ALU_MEM_REG({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_CMP_IMM": "X86_SIM_L_EXEC_CMP_IMM_OP({op}, {dst}, {flags}, {imm})",
    "X86_OP_TEST_IMM": "X86_SIM_L_EXEC_CMP_IMM_OP({op}, {dst}, {flags}, {imm})",
    "X86_OP_CMP_REG": "X86_SIM_L_EXEC_CMP_REG_OP({op}, {dst}, {src}, {flags})",
    "X86_OP_TEST_REG": "X86_SIM_L_EXEC_CMP_REG_OP({op}, {dst}, {src}, {flags})",
    "X86_OP_CMP_MEM_IMM": "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_TEST_MEM_IMM": "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_CMP_MEM_REG": "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_TEST_MEM_REG": "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_CMP_REG_MEM": "X86_SIM_L_EXEC_CMP_REG_MEM({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_CMOV": "X86_SIM_L_EXEC_CMOV({dst}, {src}, {flags}, {aux})",
    "X86_OP_CMOV_MEM": "X86_SIM_L_EXEC_CMOV_MEM({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_SETCC": "X86_SIM_L_EXEC_SETCC({dst}, {aux})",
    "X86_OP_SETCC_MEM": "X86_SIM_L_EXEC_SETCC_MEM({dst}, {aux}, {imm})",
    "X86_OP_BT": "X86_SIM_L_EXEC_BT({dst}, {src}, {flags})",
    "X86_OP_BT_IMM": "X86_SIM_L_EXEC_BT_IMM({dst}, {flags}, {imm})",
    "X86_OP_BT_MEM_IMM": "X86_SIM_L_EXEC_BT_MEM_IMM({dst}, {flags}, {aux}, {imm})",
    "X86_OP_IMUL_IMM": "X86_SIM_L_EXEC_IMUL_IMM({dst}, {src}, {flags}, {imm})",
    "X86_OP_IMUL_MEM_IMM": "X86_SIM_L_EXEC_IMUL_MEM_IMM({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_MULX": "X86_SIM_L_EXEC_MULX({dst}, {src}, {aux}, {flags})",
    "X86_OP_REP_MOVS": "X86_SIM_L_EXEC_REP_MOVS({flags}, {imm})",
    "X86_OP_ANDN": "X86_SIM_L_EXEC_ANDN({dst}, {src}, {aux}, {flags})",
    "X86_OP_ANDN_MEM": "X86_SIM_L_EXEC_ANDN_MEM({dst}, {src}, {flags}, {aux}, {imm})",
    "X86_OP_PUSH": "X86_SIM_L_EXEC_PUSH({src})",
    "X86_OP_POP": "X86_SIM_L_EXEC_POP({dst}, {flags})",
}


def direct_step_statement(encoded: EncodedInsn) -> str | None:
    template = DIRECT_STEP_MACROS.get(encoded.op)
    if template is None:
        return None
    return template.format(
        op=encoded.op,
        dst=encoded.dst,
        src=encoded.src,
        flags=encoded.flags,
        aux=encoded.aux,
        imm=encoded.imm,
    )


def canonical_reg(reg: str) -> str | None:
    info = reg_info(reg)
    return info[0] if info is not None else None


def annotated_fixed_count_ops(insns: list[NativeInsn]) -> list[NativeInsn]:
    values: dict[str, int] = {}
    out: list[NativeInsn] = []
    for insn in insns:
        annotated = insn
        if insn.mnemonic == "rep":
            count = values.get("X86_RCX")
            if count is not None:
                annotated = replace(insn, sim_imm=count)
        elif insn.mnemonic == "call" and insn.reloc_symbol in {"memcpy", "memset"}:
            count = values.get("X86_RDX")
            if count is not None:
                annotated = replace(insn, sim_imm=count)
        out.append(annotated)

        if insn.mnemonic == "mov" and len(insn.operands) == 2:
            dst = canonical_reg(insn.operands[0])
            if dst is not None:
                if is_int(insn.operands[1]):
                    values[dst] = parse_int(insn.operands[1])
                else:
                    values.pop(dst, None)
            continue
        if insn.mnemonic == "xor" and len(insn.operands) == 2:
            dst = canonical_reg(insn.operands[0])
            src = canonical_reg(insn.operands[1])
            if dst is not None:
                if dst == src:
                    values[dst] = 0
                else:
                    values.pop(dst, None)
            continue
        if insn.operands:
            dst = canonical_reg(insn.operands[0])
            if dst is not None:
                values.pop(dst, None)
    return out


def append_step(lines: list[str], insn: NativeInsn, indent: str = "\t",
                step_macro: str = "X86_SIM_RUN_OP",
                rodata_idents: dict[str, str] | None = None) -> None:
    encoded = encode(insn, rodata_idents or {})
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    append_encoded_step(lines, encoded, indent, step_macro)


def append_encoded_step(lines: list[str], encoded: EncodedInsn,
                        indent: str, step_macro: str) -> None:
    if step_macro == "X86_SIM_RUN_OP":
        direct = direct_step_statement(encoded)
        if direct is not None:
            lines.append(f"{indent}{direct};")
            return
    lines.append(
        f"{indent}{step_macro}("
        f"{encoded.op}, {encoded.dst}, {encoded.src}, "
        f"{encoded.flags}, {encoded.aux}, {encoded.imm});"
    )


def append_branch_or_ret(lines: list[str], insn: NativeInsn, addrs: set[int],
                         indent: str = "\t", next_addr: int | None = None,
                         call_functions: dict[int, str] | None = None,
                         subroutine: bool = False,
                         step_macro: str = "X86_SIM_RUN_OP",
                         ret_statement: str = "X86_SIM_X86_RET();",
                         return_targets: set[int] | None = None,
                         rodata_idents: dict[str, str] | None = None) -> None:
    branch_macro = "X86_SIM_X86_SUB_JCC" if subroutine else "X86_SIM_X86_JCC"
    jump_macro = "X86_SIM_X86_SUB_JMP" if subroutine else "X86_SIM_X86_JMP"
    return_targets = return_targets or set()
    if insn.mnemonic in CC_AUX and insn.mnemonic.startswith("j"):
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if target in return_targets:
            lines.append(f"{indent}if (X86_SIM_L_EVAL_CC({CC_AUX[insn.mnemonic]}))")
            lines.append(f"{indent}\t{ret_statement}")
            return
        if target in addrs:
            lines.append(
                f"{indent}{branch_macro}({CC_AUX[insn.mnemonic]}, "
                f"0x{insn.addr:x}, 0x{target:x}, x86_l_{target:x});"
            )
        else:
            raise ValueError(f"unsupported external branch target in {insn.raw}")
        return
    if insn.mnemonic == "jmp":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if target in return_targets:
            lines.append(f"{indent}{ret_statement}")
            return
        if target in addrs:
            lines.append(
                f"{indent}{jump_macro}(0x{insn.addr:x}, 0x{target:x}, "
                f"x86_l_{target:x});"
            )
        else:
            raise ValueError(f"unsupported external jump target in {insn.raw}")
        return
    if insn.mnemonic == "call":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        if is_helper_symbol(insn.reloc_symbol) or insn.reloc_symbol in {"memcpy", "memset"}:
            encoded = encode(insn, rodata_idents or {})
            append_encoded_step(lines, encoded, indent, step_macro)
            return
        if insn.operands:
            call_reg = reg_info(insn.operands[0])
            if call_reg is not None:
                encoded = encode(insn, rodata_idents or {})
                append_encoded_step(lines, encoded, indent, step_macro)
                return
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if call_functions and target in call_functions:
            if next_addr is None:
                raise ValueError(f"cannot compute return address for {insn.raw}")
            lines.append(
                f"{indent}X86_SIM_X86_CALL({call_functions[target]}, "
                f"0x{next_addr:x}ULL);"
            )
            return
        raise ValueError(f"unsupported unresolved call target in {insn.raw}")
        return
    if insn.mnemonic == "ret":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        lines.append(f"{indent}{ret_statement}")
        return
    append_step(lines, insn, indent, step_macro, rodata_idents)


def program_kind(item: dict) -> str:
    tags = set(item.get("tags", []))
    if "cgroup-skb" in tags or "cgroup_skb" in tags:
        return "cgroup_skb"
    if "tc" in tags:
        return "tc"
    return "xdp"


def load_benches(config_path: Path) -> list[Bench]:
    data = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    return [Bench(item["name"], program_kind(item)) for item in data["benchmarks"]]


def source_prelude(source: Path) -> str:
    text = source.read_text(encoding="utf-8")
    match = re.search(r'\nSEC\("[^"]+"\)\s+int\s+', text)
    if match is None:
        return ""
    prelude = text[:match.start()].strip()
    prelude = prelude.replace(
        '#include "include/native_helpers.h"',
        '#include "../../test/include/native_helpers.h"',
    )
    return prelude


def proof_kind_for_source(bench: Bench, source: Path) -> str:
    _ = source
    return bench.kind


def render_x86_subroutine(symbol: str, insns: list[NativeInsn],
                          call_functions: dict[int, str],
                          rodata_idents: dict[str, str] | None = None) -> str:
    insns = annotated_fixed_count_ops(insns)
    addrs = {insn.addr for insn in insns}
    next_addrs = {
        insn.addr: insns[index + 1].addr
        for index, insn in enumerate(insns[:-1])
    }
    lines = [f"\t/* native subroutine {c_comment(symbol)} */"]
    for insn in insns:
        lines.append(f"x86_l_{insn.addr:x}:")
        append_branch_or_ret(lines, insn, addrs, subroutine=True,
                             next_addr=next_addrs.get(insn.addr),
                             call_functions=call_functions,
                             step_macro="X86_SIM_RUN_OP",
                             ret_statement=(
                                 "X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);"
                             ),
                             rodata_idents=rodata_idents)
    lines.append("")
    return "\n".join(lines)


def flatten_chunk_insns(insns: list[NativeInsn],
                        subfunctions: dict[str, list[NativeInsn]]) -> list[ChunkInsn]:
    out: list[ChunkInsn] = []
    sequences: list[tuple[bool, list[NativeInsn]]] = [(False, insns)]
    sequences.extend((True, fn_insns) for fn_insns in subfunctions.values())
    for is_subroutine, fn_insns in sequences:
        for index, insn in enumerate(fn_insns):
            next_addr = fn_insns[index + 1].addr if index + 1 < len(fn_insns) else None
            out.append(ChunkInsn(insn, is_subroutine, next_addr))
    return out


def chunk_for_addr(chunks: list[list[ChunkInsn]], addr: int) -> int | None:
    for index, chunk in enumerate(chunks):
        if any(item.insn.addr == addr for item in chunk):
            return index
    return None


def append_chunk_transfer(lines: list[str], target: int, current_chunk: set[int],
                          indent: str = "\t") -> None:
    if target in current_chunk:
        lines.append(f"{indent}goto x86_l_{target:x};")
    else:
        lines.append(f"{indent}return {c_u64(target)};")


def append_chunk_call(lines: list[str], target: int, return_addr: int,
                      current_chunk: set[int], indent: str = "\t") -> None:
    lines.append(f"{indent}__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;")
    lines.append(
        f"{indent}X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, "
        f"X86_WIDTH_64, {c_u64(return_addr)});"
    )
    lines.append(f"{indent}__x86_sim_call_depth++;")
    append_chunk_transfer(lines, target, current_chunk, indent)


def append_chunk_branch_or_ret(lines: list[str], item: ChunkInsn,
                               addrs: set[int], current_chunk: set[int],
                               call_targets: set[int],
                               return_targets: set[int],
                               rodata_idents: dict[str, str] | None = None) -> None:
    insn = item.insn
    indent = "\t"
    if insn.mnemonic in CC_AUX and insn.mnemonic.startswith("j"):
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if target in return_targets:
            lines.append(f"{indent}if (X86_SIM_L_EVAL_CC({CC_AUX[insn.mnemonic]}))")
            lines.append(f"{indent}\treturn {CHUNKED_PROOF_PC_DONE};")
            return
        if target not in addrs:
            raise ValueError(f"unsupported external branch target in {insn.raw}")
        lines.append(f"{indent}if (X86_SIM_L_EVAL_CC({CC_AUX[insn.mnemonic]})) {{")
        append_chunk_transfer(lines, target, current_chunk, indent + "\t")
        lines.append(f"{indent}}}")
        return
    if insn.mnemonic == "jmp":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if target in return_targets:
            lines.append(f"{indent}return {CHUNKED_PROOF_PC_DONE};")
            return
        if target not in addrs:
            raise ValueError(f"unsupported external jump target in {insn.raw}")
        append_chunk_transfer(lines, target, current_chunk, indent)
        return
    if insn.mnemonic == "call":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        if is_helper_symbol(insn.reloc_symbol) or insn.reloc_symbol in {"memcpy", "memset"}:
            encoded = encode(insn, rodata_idents or {})
            append_encoded_step(lines, encoded, indent, "X86_SIM_RUN_OP")
            return
        if insn.operands:
            call_reg = reg_info(insn.operands[0])
            if call_reg is not None:
                encoded = encode(insn, rodata_idents or {})
                append_encoded_step(lines, encoded, indent, "X86_SIM_RUN_OP")
                return
        target = (
            insn.reloc_target
            if insn.reloc_target is not None
            else branch_target(insn.operands[0]) if insn.operands else 0
        )
        if target in call_targets and item.next_addr is not None:
            append_chunk_call(lines, target, item.next_addr, current_chunk, indent)
            return
        raise ValueError(f"unsupported unresolved call target in {insn.raw}")
    if insn.mnemonic == "ret":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        lines.append(f"{indent}if (__x86_sim_call_depth == 0)")
        lines.append(f"{indent}\treturn {CHUNKED_PROOF_PC_DONE};")
        lines.append(f"{indent}__x86_sim_call_depth--;")
        lines.append(
            f"{indent}__x86_sim_ret_addr = X86_SIM_L_STACK_READ("
            f"(__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);"
        )
        lines.append(f"{indent}__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;")
        lines.append(f"{indent}return __x86_sim_ret_addr;")
        return
    append_step(lines, insn, indent, "X86_SIM_RUN_OP", rodata_idents)


def render_chunk_function(name: str, index: int, chunk: list[ChunkInsn],
                          addrs: set[int], call_targets: set[int],
                          return_targets: set[int],
                          rodata_idents: dict[str, str]) -> str:
    current_chunk = {item.insn.addr for item in chunk}
    lines = [
        f"static __noinline __u64 {name}_x86_chunk_{index}(",
        "\tstruct x86_sim_state *__x86_state, __u64 __x86_pc)",
        "{",
        "\tswitch (__x86_pc) {",
    ]
    for item in chunk:
        lines.append(f"\tcase {c_u64(item.insn.addr)}: goto x86_l_{item.insn.addr:x};")
    lines.extend([
        "\tdefault: return " + CHUNKED_PROOF_PC_DONE + ";",
        "\t}",
    ])
    for item in chunk:
        lines.append(f"x86_l_{item.insn.addr:x}:")
        append_chunk_branch_or_ret(lines, item, addrs, current_chunk,
                                   call_targets, return_targets, rodata_idents)
    last_next = chunk[-1].next_addr
    if last_next is None or last_next in return_targets:
        lines.append(f"\treturn {CHUNKED_PROOF_PC_DONE};")
    else:
        lines.append(f"\treturn {c_u64(last_next)};")
    lines.extend(["}", ""])
    return "\n".join(lines)


def render_chunked_program(name: str, insns: list[NativeInsn],
                           subfunctions: dict[str, list[NativeInsn]],
                           kind: str, exit_addr: int | None,
                           source_prelude: str,
                           rodata16: dict[str, tuple[int, int]]) -> str:
    insns = annotated_fixed_count_ops(insns)
    subfunctions = {
        symbol: annotated_fixed_count_ops(fn_insns)
        for symbol, fn_insns in subfunctions.items()
    }
    if kind == "tc":
        section = 'SEC("tc")'
        ctx_type = "struct __sk_buff *"
        abi_define = "#define __x86_sim_abi (__x86_state->skb_abi)"
        init_lines = [
            "\t__x86_sim_abi.data_end = (void *)(long)ctx->data_end;",
            "\t__x86_sim_abi.data = (void *)(long)ctx->data;",
            "\t__x86_sim_skb_ctx = ctx;",
        ]
    elif kind == "cgroup_skb":
        section = 'SEC("cgroup_skb/egress")'
        ctx_type = "struct __sk_buff *"
        abi_define = "#define __x86_sim_abi (__x86_state->skb_abi)"
        init_lines = [
            "\t__x86_sim_abi.data_end = (void *)(long)ctx->data_end;",
            "\t__x86_sim_abi.data = (void *)(long)ctx->data;",
            "\t__x86_sim_skb_ctx = ctx;",
        ]
    else:
        section = 'SEC("xdp")'
        ctx_type = "struct xdp_md *"
        abi_define = "#define __x86_sim_abi (__x86_state->xdp_abi)"
        init_lines = [
            "\t__x86_sim_abi.data = (void *)(long)ctx->data;",
            "\t__x86_sim_abi.data_end = (void *)(long)ctx->data_end;",
            "\t__x86_sim_skb_ctx = (struct __sk_buff *)0;",
        ]
    flat = flatten_chunk_insns(insns, subfunctions)
    chunks = [
        flat[index:index + CHUNKED_PROOF_CHUNK_INSNS]
        for index in range(0, len(flat), CHUNKED_PROOF_CHUNK_INSNS)
    ]
    addrs = {item.insn.addr for item in flat}
    return_targets = {exit_addr} if exit_addr is not None else set()
    call_targets = {
        fn_insns[0].addr
        for fn_insns in subfunctions.values()
        if fn_insns
    }
    if flat:
        call_targets.add(flat[0].insn.addr)
    has_stack = any(
        item.insn.mnemonic in {"push", "pop"} or
        "[rsp" in item.insn.raw.lower() or
        "[rbp" in item.insn.raw.lower()
        for item in flat
    ) or bool(subfunctions)
    has_stack_memory = any(
        "[rsp" in item.insn.raw.lower() or "[rbp" in item.insn.raw.lower()
        for item in flat
    )
    rodata_idents = rodata_ident_map(rodata16)
    lines: list[str] = []
    if has_stack:
        lines.append('#define X86_SIM_ENABLE_STACK 1')
        if has_stack_memory:
            lines.append('#define X86_SIM_ENABLE_STACK_DEEP 1')
    lines.extend([
        '#define X86_SIM_USE_STATE_STRUCT 1',
        '#include "../x86_sim_local_bpf.h"',
        abi_define,
        "",
    ])
    if source_prelude:
        lines.append(source_prelude.rstrip())
        lines.append("")
    for symbol, ident in rodata_idents.items():
        lo, hi = rodata16[symbol]
        lines.append(f"static const __u64 {ident}[2] = {{{c_u64(lo)}, {c_u64(hi)}}};")
    if rodata_idents:
        lines.append("")
    for index, chunk in enumerate(chunks):
        lines.append(render_chunk_function(name, index, chunk, addrs,
                                           call_targets, return_targets,
                                           rodata_idents))
    first_addr = flat[0].insn.addr
    max_steps = max(len(flat) * 4, len(flat) + 1024)
    lines.extend([
        section,
        f"int {name}_x86_sim_xdp({ctx_type}ctx)",
        "{",
        "\tstruct x86_sim_state __x86_state_storage = {};",
        "\tX86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);",
        *init_lines,
        "\t__x86_rdi.ptr = &__x86_sim_abi;",
        "\t__x86_rdi_tag = X86_SIM_TAG_ABI;",
        f"\t__u64 __x86_pc = {c_u64(first_addr)};",
        f"\tfor (__u32 __x86_iter = 0; __x86_iter < {max_steps}U; __x86_iter++) {{",
        f"\t\tif (__x86_pc == {CHUNKED_PROOF_PC_DONE})",
        "\t\t\tbreak;",
    ])
    for index, chunk in enumerate(chunks):
        min_addr = min(item.insn.addr for item in chunk)
        max_addr = max(item.insn.addr for item in chunk)
        prefix = "if" if index == 0 else "else if"
        lines.append(
            f"\t\t{prefix} (__x86_pc >= {c_u64(min_addr)} && "
            f"__x86_pc <= {c_u64(max_addr)})"
        )
        lines.append(f"\t\t\t__x86_pc = {name}_x86_chunk_{index}(__x86_state, __x86_pc);")
    lines.extend([
        "\t\telse",
        f"\t\t\t__x86_pc = {CHUNKED_PROOF_PC_DONE};",
        "\t}",
        f"\tif (__x86_pc != {CHUNKED_PROOF_PC_DONE})",
        "\t\tX86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);",
        "\tX86_SIM_X86_RET();",
        "}",
        "",
        "X86_SIM_LICENSE();",
        "",
    ])
    return "\n".join(lines)


def render_program(name: str, insns: list[NativeInsn],
                   subfunctions: dict[str, list[NativeInsn]] | None = None,
                   kind: str = "xdp",
                   exit_addr: int | None = None,
                   source_prelude: str = "",
                   rodata16: dict[str, tuple[int, int]] | None = None) -> str:
    ret_statement = "X86_SIM_X86_RET();"
    insns = annotated_fixed_count_ops(insns)
    subfunctions = {
        symbol: annotated_fixed_count_ops(fn_insns)
        for symbol, fn_insns in (subfunctions or {}).items()
    }
    total_insns = len(insns) + sum(len(fn_insns) for fn_insns in subfunctions.values())
    entry_addr = insns[0].addr if insns else None
    has_self_call = any(
        item.mnemonic == "call"
        and (
            item.reloc_target == entry_addr or
            (item.reloc_target is None and item.operands and
             has_direct_branch_target(item.operands[0]) and
             branch_target(item.operands[0]) == entry_addr)
        )
        for item in insns
    )
    if total_insns >= CHUNKED_PROOF_INSN_THRESHOLD or has_self_call:
        return render_chunked_program(name, insns, subfunctions, kind,
                                      exit_addr, source_prelude, rodata16 or {})
    if kind == "tc":
        section = 'SEC("tc")'
        ctx_type = "struct __sk_buff *"
        declare = "X86_SIM_ENTRY_SKB(ctx);"
    elif kind == "cgroup_skb":
        section = 'SEC("cgroup_skb/egress")'
        ctx_type = "struct __sk_buff *"
        declare = "X86_SIM_ENTRY_SKB(ctx);"
    else:
        section = 'SEC("xdp")'
        ctx_type = "struct xdp_md *"
        declare = "X86_SIM_ENTRY_XDP(ctx);"
    addrs = {insn.addr for insn in insns}
    return_targets = {exit_addr} if exit_addr is not None else set()
    if exit_addr is not None:
        addrs.add(exit_addr)
    subroutine_label_by_addr = {
        fn_insns[0].addr: f"x86_l_{fn_insns[0].addr:x}"
        for symbol, fn_insns in subfunctions.items()
        if fn_insns
    }
    return_addrs = sorted({
        fn_insns[index + 1].addr
        for fn_insns in [insns, *subfunctions.values()]
        for index, insn in enumerate(fn_insns[:-1])
        if insn.mnemonic == "call"
    })
    has_stack = any(
        insn.mnemonic in {"push", "pop"} or
        "[rsp" in insn.raw.lower() or
        "[rbp" in insn.raw.lower()
        for fn_insns in [insns, *subfunctions.values()]
        for insn in fn_insns
    ) or bool(subfunctions)
    has_stack_memory = any(
        "[rsp" in insn.raw.lower() or "[rbp" in insn.raw.lower()
        for fn_insns in [insns, *subfunctions.values()]
        for insn in fn_insns
    )
    next_addrs = {
        insn.addr: insns[index + 1].addr
        for index, insn in enumerate(insns[:-1])
    }
    rodata16 = rodata16 or {}
    rodata_idents = rodata_ident_map(rodata16)
    sim_header = "../x86_sim_local_bpf.h"
    lines: list[str] = []
    if has_stack:
        lines.append('#define X86_SIM_ENABLE_STACK 1')
        if has_stack_memory:
            lines.append('#define X86_SIM_ENABLE_STACK_DEEP 1')
    lines.extend([
        f'#include "{sim_header}"',
        "",
    ])
    if source_prelude:
        lines.append(source_prelude.rstrip())
        lines.append("")
    for symbol, ident in rodata_idents.items():
        lo, hi = rodata16[symbol]
        lines.append(f"static const __u64 {ident}[2] = {{{c_u64(lo)}, {c_u64(hi)}}};")
    if rodata_idents:
        lines.append("")
    lines.extend([
        section,
        f"int {name}_x86_sim_xdp({ctx_type}ctx)",
        "{",
        f"\t{declare}",
    ])
    for insn in insns:
        label = f"x86_l_{insn.addr:x}"
        lines.append(f"{label}:")
        append_branch_or_ret(lines, insn, addrs,
                             next_addr=next_addrs.get(insn.addr),
                             call_functions=subroutine_label_by_addr,
                             ret_statement=ret_statement,
                             return_targets=return_targets,
                             rodata_idents=rodata_idents)
    if exit_addr is not None:
        lines.append(f"x86_l_{exit_addr:x}:")
        lines.append("\t/* native-link entry fallthrough exit */")
        lines.append(f"\t{ret_statement}")
    if subfunctions:
        for symbol, fn_insns in subfunctions.items():
            lines.append(render_x86_subroutine(
                symbol, fn_insns, subroutine_label_by_addr, rodata_idents))
        lines.extend([
            "x86_sim_ret_dispatch:",
            "\tswitch (__x86_sim_ret_addr) {",
        ])
        for addr in return_addrs:
            lines.append(f"\tcase 0x{addr:x}ULL: goto x86_l_{addr:x};")
        lines.extend([
            "\t}",
            "",
        ])
    lines.extend(["}", "", "X86_SIM_LICENSE();", ""])
    return "\n".join(lines)


def write_one(bench: Bench, source_dir: Path, out_dir: Path, proof_object_dir: Path) -> Path:
    name = bench.name
    insns, subfunctions, exit_addr, rodata16 = parse_proof_object_program(name, proof_object_dir)
    if not insns:
        raise ValueError(f"{name}: no native instructions parsed")
    output = out_dir / f"{name}.bpf.c"
    source = source_dir / f"{name}.bpf.c"
    prelude = source_prelude(source) if source_dir == STAGE2_PROGRAMS else ""
    kind = proof_kind_for_source(bench, source) if source_dir == STAGE2_PROGRAMS else bench.kind
    output.write_text(render_program(name, insns, subfunctions,
                                     kind=kind,
                                     exit_addr=exit_addr,
                                     source_prelude=prelude,
                                     rodata16=rodata16))
    return output


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--micro-programs", type=Path)
    parser.add_argument("--output-dir", type=Path, default=OUT_DIR)
    parser.add_argument("--proof-object-dir", type=Path, default=PROOF_OBJECT_DIR)
    parser.add_argument("--config", type=Path, default=CONFIG)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark stem list")
    args = parser.parse_args()

    args.output_dir.mkdir(parents=True, exist_ok=True)
    source_dir = args.micro_programs or (STAGE2_PROGRAMS if "stage2" in args.config.stem else MICRO_PROGRAMS)
    only = set(args.only or [])
    written: list[Path] = []
    for bench in load_benches(args.config):
        if only and bench.name not in only:
            continue
        written.append(write_one(bench, source_dir, args.output_dir, args.proof_object_dir))

    for path in written:
        print(path)
    print(f"generated {len(written)} proof sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
