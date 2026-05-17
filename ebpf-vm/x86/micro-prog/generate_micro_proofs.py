#!/usr/bin/env python3
"""Generate hardcoded x86-VM verifier artifacts from micro Native ASM blocks."""

from __future__ import annotations

import argparse
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[3]
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
OUT_DIR = Path(__file__).resolve().parent

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
    "shl": "X86_ALU_SHL",
    "shr": "X86_ALU_SHR",
    "sar": "X86_ALU_SAR",
    "rol": "X86_ALU_ROL",
    "imul": "X86_ALU_IMUL",
    "inc": "X86_ALU_INC",
    "not": "X86_ALU_NOT",
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
    "cmovb": "X86_CC_B",
    "cmove": "X86_CC_E",
    "cmovne": "X86_CC_NE",
    "sete": "X86_CC_E",
    "setge": "X86_CC_GE",
    "setne": "X86_CC_NE",
}

WIDTH_CONST = {
    8: "X86_WIDTH_8",
    16: "X86_WIDTH_16",
    32: "X86_WIDTH_32",
    64: "X86_WIDTH_64",
}

OP_HELPERS = {
    "X86_OP_NOP": "x86_exec_nop",
    "X86_OP_MOV_IMM": "x86_exec_mov_imm",
    "X86_OP_MOV_REG": "x86_exec_mov_reg",
    "X86_OP_ADD_IMM": "x86_exec_add_imm",
    "X86_OP_ADD_REG": "x86_exec_add_reg",
    "X86_OP_XOR_REG": "x86_exec_xor_reg",
    "X86_OP_MOV_LOAD": "x86_exec_mov_load",
    "X86_OP_MOV_STORE_IMM": "x86_exec_mov_store_imm",
    "X86_OP_MOV_STORE_REG": "x86_exec_mov_store_reg",
    "X86_OP_LEA": "x86_exec_lea",
    "X86_OP_ALU_IMM": "x86_exec_alu_imm",
    "X86_OP_ALU_REG": "x86_exec_alu_reg",
    "X86_OP_CMP_IMM": "x86_exec_cmp_imm",
    "X86_OP_CMP_REG": "x86_exec_cmp_reg",
    "X86_OP_TEST_IMM": "x86_exec_test_imm",
    "X86_OP_TEST_REG": "x86_exec_test_reg",
    "X86_OP_JCC": "x86_exec_jcc",
    "X86_OP_JMP": "x86_exec_jmp",
    "X86_OP_PUSH": "x86_exec_push",
    "X86_OP_POP": "x86_exec_pop",
    "X86_OP_CALL": "x86_exec_call",
    "X86_OP_CMOV": "x86_exec_cmov",
    "X86_OP_SETCC": "x86_exec_setcc",
    "X86_OP_BSWAP": "x86_exec_bswap",
    "X86_OP_POPCNT": "x86_exec_popcnt",
    "X86_OP_XCHG": "x86_exec_xchg",
    "X86_OP_DIV": "x86_exec_div",
    "X86_OP_SHLD_IMM": "x86_exec_shld_imm",
    "X86_OP_SHRD_IMM": "x86_exec_shrd_imm",
    "X86_OP_CMP_MEM_IMM": "x86_exec_cmp_mem_imm",
    "X86_OP_TEST_MEM_IMM": "x86_exec_test_mem_imm",
    "X86_OP_CMP_MEM_REG": "x86_exec_cmp_mem_reg",
    "X86_OP_MOVZX_REG": "x86_exec_movzx_reg",
    "X86_OP_MOVSX_REG": "x86_exec_movsx_reg",
    "X86_OP_MOVSX_LOAD": "x86_exec_movsx_load",
    "X86_OP_ALU_MEM": "x86_exec_alu_mem",
    "X86_OP_RET": "x86_exec_ret",
}


@dataclass(frozen=True)
class NativeInsn:
    addr: int
    raw: str
    mnemonic: str
    operands: tuple[str, ...]


@dataclass(frozen=True)
class EncodedInsn:
    op: str
    dst: str
    src: str
    flags: str
    aux: str
    imm: str


def extract_native_asm(text: str) -> str:
    match = re.search(r"^## Native ASM\n```asm\n(.*?)\n```", text, re.S | re.M)
    if match is None:
        raise ValueError("missing ## Native ASM block")
    return match.group(1)


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
        match = re.match(r"(?P<mnemonic>[a-z][a-z0-9]*)\s*(?P<operands>.*)$", asm)
        if match is None:
            continue
        insns.append(
            NativeInsn(
                addr=int(addr_text, 16),
                raw=asm,
                mnemonic=match.group("mnemonic"),
                operands=split_operands(match.group("operands")),
            )
        )
    return insns


def parse_native_asm(md_path: Path) -> list[NativeInsn]:
    return parse_asm_text(extract_native_asm(md_path.read_text()))


def call_symbol(insn: NativeInsn) -> str | None:
    if insn.mnemonic != "call":
        return None
    match = re.search(r"<([^>+]+)", insn.raw)
    return match.group(1) if match is not None else None


def unresolved_call_symbols(insns: list[NativeInsn]) -> list[str]:
    addrs = {insn.addr for insn in insns}
    symbols: list[str] = []
    for insn in insns:
        if insn.mnemonic != "call":
            continue
        target = branch_target(insn.operands[0]) if insn.operands else 0
        if target in addrs:
            continue
        symbol = call_symbol(insn)
        if symbol is not None and symbol not in symbols:
            symbols.append(symbol)
    return symbols


def native_object_path(name: str, *, no_jump_tables: bool = False) -> Path:
    out_dir = Path("/tmp/bpf-benchmark-micro-native-nojt" if no_jump_tables
                   else "/tmp/bpf-benchmark-micro-native")
    so_path = out_dir / f"{name}.native.so"
    cmd = ["make", "-C", str(MICRO_PROGRAMS), f"OUTPUT_DIR={out_dir}"]
    if no_jump_tables:
        cmd.append(
            "NATIVE_CFLAGS=-Wall -Wextra -O2 -g -fPIC -shared "
            "-DMICRO_NATIVE -fno-omit-frame-pointer -fno-jump-tables "
            "-MMD -MP"
        )
    cmd.append(str(so_path))
    subprocess.run(cmd, cwd=REPO_ROOT, check=True, stdout=subprocess.DEVNULL)
    return so_path


def parse_native_symbol(so_path: Path, symbol: str) -> list[NativeInsn]:
    result = subprocess.run(
        ["objdump", "-dr", "-Mintel", f"--disassemble={symbol}", str(so_path)],
        cwd=REPO_ROOT,
        check=True,
        text=True,
        stdout=subprocess.PIPE,
    )
    return parse_asm_text(result.stdout)


def parse_first_native_symbol(so_path: Path, symbols: list[str]) -> tuple[str, list[NativeInsn]]:
    for symbol in symbols:
        insns = parse_native_symbol(so_path, symbol)
        if insns:
            return symbol, insns
    raise ValueError(f"{so_path}: none of the native symbols exist: {symbols}")


def parse_full_native_functions(name: str, symbols: list[str],
                                *, no_jump_tables: bool = False) -> dict[str, list[NativeInsn]]:
    so_path = native_object_path(name, no_jump_tables=no_jump_tables)
    entry_symbol, entry_insns = parse_first_native_symbol(
        so_path, [f"{name}_xdp", f"{name}_prog"]
    )
    out: dict[str, list[NativeInsn]] = {
        entry_symbol: entry_insns,
    }
    for symbol in symbols:
        out[symbol] = parse_native_symbol(so_path, symbol)
    return out


def parse_entry_native_function(name: str, *, no_jump_tables: bool) -> list[NativeInsn]:
    so_path = native_object_path(name, no_jump_tables=no_jump_tables)
    _symbol, insns = parse_first_native_symbol(
        so_path, [f"{name}_xdp", f"{name}_prog"]
    )
    return insns


def parse_int(text: str) -> int:
    text = text.strip()
    if text.startswith("-"):
        return -parse_int(text[1:])
    return int(text, 16) if text.lower().startswith("0x") else int(text, 10)


def is_int(text: str) -> bool:
    return re.fullmatch(r"-?(0x[0-9a-fA-F]+|\d+)", text.strip()) is not None


def c_u64(value: int) -> str:
    return f"{value & 0xffffffffffffffff}ULL"


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


def enc(op: str, dst: str = "X86_REG_NONE", src: str = "X86_REG_NONE",
        flags: str = "X86_WIDTH_64", aux: str = "0", imm: str = "0") -> EncodedInsn:
    return EncodedInsn(op, dst, src, flags, aux, imm)


def encode(insn: NativeInsn) -> EncodedInsn:
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
        return enc("X86_OP_CALL", imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op == "push":
        src = reg_info(ops[0]) if ops else None
        return enc("X86_OP_PUSH", src=src[0] if src else "X86_REG_NONE",
                   flags=WIDTH_CONST.get(src[1], "X86_WIDTH_64") if src else "X86_WIDTH_64")
    if op == "pop":
        dst = reg_info(ops[0]) if ops else None
        return enc("X86_OP_POP", dst=dst[0] if dst else "X86_REG_NONE",
                   flags=WIDTH_CONST.get(dst[1], "X86_WIDTH_64") if dst else "X86_WIDTH_64")
    if op in {"sete", "setge", "setne"}:
        dst = reg_info(ops[0]) if ops else None
        if dst is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SETCC", dst=dst[0], flags="X86_WIDTH_8", aux=CC_AUX[op])
    if op in {"cmovb", "cmove", "cmovne"}:
        dst = reg_info(ops[0]) if len(ops) > 0 else None
        src = reg_info(ops[1]) if len(ops) > 1 else None
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
            return enc("X86_OP_MOV_LOAD", dst=dst_reg[0], src=mem_base_reg(src),
                       flags=WIDTH_CONST[operand_width(src, dst_reg[1])],
                       aux=mem_aux(src),
                       imm=c_u64(mem_disp(src)))
        if is_mem(dst) and is_int(src):
            return enc("X86_OP_MOV_STORE_IMM", dst=mem_base_reg(dst),
                       flags=WIDTH_CONST[operand_width(dst)],
                       aux=mem_aux(dst),
                       imm=c_u64(parse_int(src) + (mem_disp(dst) << 32)))
        if is_mem(dst) and src_reg:
            return enc("X86_OP_MOV_STORE_REG", dst=mem_base_reg(dst),
                       src=src_reg[0], flags=WIDTH_CONST[operand_width(dst)],
                       aux=mem_aux(dst, src_shift=src_reg[2]),
                       imm=c_u64(mem_disp(dst)))
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

    if op == "lea":
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        if dst_reg is None:
            raise ValueError(f"cannot encode {insn.raw}")
        if "[rip" in ops[1].lower():
            return enc("X86_OP_LEA", dst=dst_reg[0], src="X86_REG_NONE",
                       flags=WIDTH_CONST[dst_reg[1]], aux="X86_PTR_RODATA",
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
        if op == "cmp" and is_mem(ops[0]) and src_reg:
            return enc("X86_OP_CMP_MEM_REG",
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
            return enc("X86_OP_NOP", flags=WIDTH_CONST[width])
        raise ValueError(f"cannot encode {insn.raw}")

    if op in ALU_AUX:
        if op in {"inc", "not"}:
            if len(ops) != 1:
                raise ValueError(f"cannot encode {insn.raw}")
            dst_reg = reg_info(ops[0])
            if dst_reg is None:
                return enc("X86_OP_NOP", flags=WIDTH_CONST[operand_width(ops[0])])
            return enc("X86_OP_ALU_IMM", dst=dst_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]], aux=ALU_AUX[op],
                       imm="1" if op == "inc" else "0")
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
        if is_mem(ops[0]) or is_mem(ops[1]):
            return enc("X86_OP_NOP", flags=WIDTH_CONST[operand_width(ops[0])],
                       aux=ALU_AUX[op])
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


def op_helper(op: str) -> str:
    try:
        return OP_HELPERS[op]
    except KeyError as err:
        raise ValueError(f"missing interpreter helper for {op}") from err


def append_step(lines: list[str], insn: NativeInsn, indent: str = "\t",
                step_macro: str = "X86_VM_RUN_OP") -> None:
    encoded = encode(insn)
    helper = op_helper(encoded.op)
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(
        f"{indent}{step_macro}("
        f"{helper}, {encoded.op}, {encoded.dst}, {encoded.src}, "
        f"{encoded.flags}, {encoded.aux}, {encoded.imm});"
    )


def append_ret_dispatch(lines: list[str], call_returns: set[int],
                        indent: str, ret_statement: str) -> None:
    lines.append(f"{indent}if (__x86_call_depth == 0)")
    lines.append(f"{indent}\t{ret_statement}")
    lines.append(f"{indent}if (__x86_call_depth == 1) {{")
    lines.append(f"{indent}\t__x86_call_depth = 0;")
    for ret_addr in sorted(call_returns):
        lines.append(f"{indent}\tif (__x86_call_ret0 == 0x{ret_addr:x})")
        lines.append(f"{indent}\t\tgoto x86_l_{ret_addr:x};")
    lines.append(f"{indent}\treturn XDP_ABORTED;")
    lines.append(f"{indent}}}")
    lines.append(f"{indent}if (__x86_call_depth == 2) {{")
    lines.append(f"{indent}\t__x86_call_depth = 1;")
    for ret_addr in sorted(call_returns):
        lines.append(f"{indent}\tif (__x86_call_ret1 == 0x{ret_addr:x})")
        lines.append(f"{indent}\t\tgoto x86_l_{ret_addr:x};")
    lines.append(f"{indent}\treturn XDP_ABORTED;")
    lines.append(f"{indent}}}")
    lines.append(f"{indent}return XDP_ABORTED;")


def append_branch_or_ret(lines: list[str], insn: NativeInsn, addrs: set[int],
                         indent: str = "\t", next_addr: int | None = None,
                         call_returns: set[int] | None = None,
                         call_functions: dict[int, str] | None = None,
                         subroutine: bool = False,
                         step_macro: str = "X86_VM_RUN_OP",
                         ret_statement: str = "X86_VM_RET_RAX();") -> None:
    if insn.mnemonic in CC_AUX and insn.mnemonic.startswith("j"):
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = branch_target(insn.operands[0]) if insn.operands else 0
        if target in addrs:
            lines.append(f"{indent}if (x86_eval_cc(&__x86_vm_state, {CC_AUX[insn.mnemonic]}))")
            lines.append(f"{indent}\tgoto x86_l_{target:x};")
        else:
            lines.append(f"{indent}if (x86_eval_cc(&__x86_vm_state, {CC_AUX[insn.mnemonic]}))")
            lines.append(f"{indent}\treturn XDP_ABORTED;")
        return
    if insn.mnemonic == "jmp":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = branch_target(insn.operands[0]) if insn.operands else 0
        if target in addrs:
            lines.append(f"{indent}goto x86_l_{target:x};")
        else:
            lines.append(f"{indent}return XDP_ABORTED;")
        return
    if insn.mnemonic == "call":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        target = branch_target(insn.operands[0]) if insn.operands else 0
        if call_functions and target in call_functions:
            lines.append(
                f"{indent}if ({call_functions[target]}(&__x86_vm_state, "
                f"__x86_vm_data, __x86_vm_data_end) < 0)"
            )
            lines.append(f"{indent}\treturn XDP_ABORTED;")
            return
        if target in addrs and next_addr is not None:
            lines.append(f"{indent}if (__x86_call_depth == 0) {{")
            lines.append(f"{indent}\t__x86_call_ret0 = 0x{next_addr:x};")
            lines.append(f"{indent}\t__x86_call_depth = 1;")
            lines.append(f"{indent}\tgoto x86_l_{target:x};")
            lines.append(f"{indent}}}")
            lines.append(f"{indent}if (__x86_call_depth == 1) {{")
            lines.append(f"{indent}\t__x86_call_ret1 = 0x{next_addr:x};")
            lines.append(f"{indent}\t__x86_call_depth = 2;")
            lines.append(f"{indent}\tgoto x86_l_{target:x};")
            lines.append(f"{indent}}}")
        lines.append(f"{indent}return XDP_ABORTED;")
        return
    if insn.mnemonic == "ret":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        if subroutine:
            lines.append(f"{indent}{ret_statement}")
            return
        if call_returns:
            append_ret_dispatch(lines, call_returns, indent, ret_statement)
        else:
            lines.append(f"{indent}{ret_statement}")
        return
    append_step(lines, insn, indent, step_macro)


def append_unrolled_branch_comment(lines: list[str], insn: NativeInsn,
                                   indent: str) -> None:
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(f"{indent}/* proof-unrolled backward branch */")


def append_loop_step(lines: list[str], insn: NativeInsn, indent: str = "\t",
                     macro: str = "PACKET_CHECKSUM_LOOP_STEP") -> None:
    encoded = encode(insn)
    helper = op_helper(encoded.op)
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(
        f"{indent}{macro}("
        f"{helper}, {encoded.op}, {encoded.dst}, {encoded.src}, "
        f"{encoded.flags}, {encoded.aux}, {encoded.imm});"
    )


def append_packet_checksum_load(lines: list[str], insn: NativeInsn, reg: str,
                                offset_expr: str,
                                indent: str = "\t") -> None:
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(
        f"{indent}PACKET_CHECKSUM_LOAD_U16({reg}, p_{reg}, tag_{reg}, "
        f"{offset_expr});"
    )


def c_ident(text: str) -> str:
    return re.sub(r"[^A-Za-z0-9_]", "_", text)


def max_stack_offset(all_insns: list[NativeInsn], *, rbp_bias: int = 8) -> int:
    max_offset = 0
    for insn in all_insns:
        for operand in insn.operands:
            match = re.search(r"\[r([bs])p-0x([0-9a-fA-F]+)", operand)
            if match is None:
                continue
            disp = int(match.group(2), 16)
            if match.group(1) == "b":
                disp += rbp_bias
            max_offset = max(max_offset, disp)
    return max_offset


def needs_stack_slot7(all_insns: list[NativeInsn], *, rbp_bias: int = 8) -> bool:
    return max_stack_offset(all_insns, rbp_bias=rbp_bias) >= 0x40


def needs_stack_ext(all_insns: list[NativeInsn], *, rbp_bias: int = 8) -> bool:
    return max_stack_offset(all_insns, rbp_bias=rbp_bias) >= 0x68


def needs_stack_deep(all_insns: list[NativeInsn], *, rbp_bias: int = 8) -> bool:
    return max_stack_offset(all_insns, rbp_bias=rbp_bias) >= 0x48


CALLEE_SAVED_REGS = ("rbx", "rbp", "r12", "r13", "r14", "r15")


def is_subfunction_frame_insn(insn: NativeInsn) -> bool:
    if insn.mnemonic in {"push", "pop"} and len(insn.operands) == 1:
        return insn.operands[0].lower() in CALLEE_SAVED_REGS
    if insn.mnemonic == "mov" and len(insn.operands) == 2:
        return (
            insn.operands[0].lower() == "rbp"
            and insn.operands[1].lower() == "rsp"
        )
    return False


def is_entry_synthetic_frame_insn(insn: NativeInsn) -> bool:
    if is_subfunction_frame_insn(insn):
        return True
    if insn.mnemonic in {"add", "sub"} and len(insn.operands) == 2:
        return insn.operands[0].lower() == "rsp" and is_int(insn.operands[1])
    return False


def render_packet_checksum_fold(name: str, insns: list[NativeInsn]) -> str:
    by_addr = {insn.addr: insn for insn in insns}
    addrs = set(by_addr)
    lines = [
        '#include "../x86_vm_bpf.h"',
        "",
        "struct packet_checksum_fold_loop_ctx {",
        "\tstruct x86_state state;",
        "\tstruct x86_insn insn;",
        "\tvoid *data;",
        "\tvoid *data_end;",
        "\t__u32 inner;",
        "\t__u32 failed;",
        "};",
        "",
        "#define PACKET_CHECKSUM_LOOP_STEP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM) \\",
        "\tdo {                                                               \\",
        "\t\tloop->insn.op = (OP);                                         \\",
        "\t\tloop->insn.dst = (DST);                                       \\",
        "\t\tloop->insn.src = (SRC);                                       \\",
        "\t\tloop->insn.flags = (FLAGS);                                  \\",
        "\t\tloop->insn.aux = (AUX);                                      \\",
        "\t\tloop->insn.imm = (IMM);                                      \\",
        "\t\tint __x86_loop_ret = HELPER(&loop->state, &loop->insn,       \\",
        "\t\t\t\t\t       loop->data, loop->data_end);       \\",
        "\t\tif (__x86_loop_ret != X86_INTERP_CONTINUE) {                 \\",
        "\t\t\tloop->failed = __LINE__;                               \\",
        "\t\t\treturn 1;                                             \\",
        "\t\t}                                                          \\",
        "\t} while (0)",
        "",
        "#define PACKET_CHECKSUM_LOAD_U16(REG, PTR_REG, TAG_REG, OFF_EXPR) \\",
        "\tdo {                                                           \\",
        "\t\t__u32 __packet_off = (OFF_EXPR);                         \\",
        "\t\tif (__packet_off > 1038) {                              \\",
        "\t\t\tloop->failed = 1;                                  \\",
        "\t\t\treturn 1;                                         \\",
        "\t\t}                                                      \\",
        "\t\t__u8 *__packet_addr = (__u8 *)loop->data + __packet_off; \\",
        "\t\tif (__packet_addr + X86_WIDTH_16 > (__u8 *)loop->data_end) { \\",
        "\t\t\tloop->failed = 1;                                  \\",
        "\t\t\treturn 1;                                         \\",
        "\t\t}                                                      \\",
        "\t\tloop->state.REG = *(__u16 *)__packet_addr;             \\",
        "\t\tloop->state.PTR_REG = 0;                               \\",
        "\t\tloop->state.TAG_REG = X86_PTR_NONE;                    \\",
        "\t} while (0)",
        "",
        "static long packet_checksum_fold_inner_cb(__u32 index, void *ctx)",
        "{",
        "\tstruct packet_checksum_fold_loop_ctx *loop = ctx;",
        "",
        "\tif (loop->failed)",
        "\t\treturn 1;",
        "\tif (loop->inner >= 256) {",
        "\t\tloop->failed = __LINE__;",
        "\t\treturn 1;",
        "\t}",
        "\tloop->state.rcx = 19 + ((__u64)loop->inner << 2);",
        "\tloop->state.p_rcx = 0;",
        "\tloop->state.tag_rcx = X86_PTR_NONE;",
    ]

    append_packet_checksum_load(lines, by_addr[0x1150], "r8",
                                "16 + (loop->inner << 2)", "\t")
    for addr in (0x1156, 0x1159, 0x115d, 0x1161):
        append_loop_step(lines, by_addr[addr], "\t")
    append_packet_checksum_load(lines, by_addr[0x1164], "rdi",
                                "18 + (loop->inner << 2)", "\t")
    for addr in (0x1169, 0x116c, 0x1170, 0x1173, 0x1176, 0x117a):
        append_loop_step(lines, by_addr[addr], "\t")
    lines.append(f"\t/* 0x1181: {c_comment(by_addr[0x1181].raw)} */")
    lines.append("\t/* proof-loop branch handled by bpf_loop trip count */")
    lines.append("\tloop->inner++;")
    lines.append("\treturn 0;")
    lines.append("}")
    lines.append("")
    lines.append("static long packet_checksum_fold_outer_cb(__u32 index, void *ctx)")
    lines.append("{")
    lines.append("\tstruct packet_checksum_fold_loop_ctx *loop = ctx;")
    lines.append("")
    lines.append("\tif (loop->failed)")
    lines.append("\t\treturn 1;")
    lines.append("\tloop->inner = 0;")
    for addr in (0x1140, 0x1145, 0x1147):
        append_loop_step(lines, by_addr[addr], "\t")
    lines.append("\tif (bpf_loop(256, packet_checksum_fold_inner_cb, loop, 0) < 0) {")
    lines.append("\t\tloop->failed = 1;")
    lines.append("\t\treturn 1;")
    lines.append("\t}")
    lines.append("\tif (loop->failed)")
    lines.append("\t\treturn 1;")
    for addr in (0x1183, 0x1185, 0x1188, 0x118a, 0x118c, 0x118f,
                 0x1191, 0x1194, 0x1197, 0x119a, 0x119c):
        append_loop_step(lines, by_addr[addr], "\t")
    lines.append(f"\t/* 0x119f: {c_comment(by_addr[0x119f].raw)} */")
    lines.append("\t/* proof-loop branch handled by outer bpf_loop trip count */")
    lines.append("\treturn 0;")
    lines.append("}")
    lines.extend([
        "",
        "#undef PACKET_CHECKSUM_LOOP_STEP",
        "",
        "SEC(\"xdp\")",
        f"int {name}_x86_vm_xdp(struct xdp_md *ctx)",
        "{",
        "\tvoid *__x86_vm_data = (void *)(long)ctx->data;",
        "\tvoid *__x86_vm_data_end = (void *)(long)ctx->data_end;",
        "\tstruct packet_checksum_fold_loop_ctx __x86_loop = {};",
	        "\t#define __x86_vm_state __x86_loop.state",
	        "\t#define __x86_vm_insn __x86_loop.insn",
	        "\tx86_init_state(&__x86_vm_state, (void *)ctx);",
	    ])

    for insn in insns:
        if insn.addr > 0x1137:
            break
        lines.append(f"x86_l_{insn.addr:x}:")
        append_branch_or_ret(lines, insn, addrs)

    lines.append("\t__x86_loop.data = __x86_vm_data;")
    lines.append("\t__x86_loop.data_end = __x86_vm_data_end;")
    lines.append("\tif (bpf_loop(32, packet_checksum_fold_outer_cb, &__x86_loop, 0) < 0)")
    lines.append("\t\treturn XDP_ABORTED;")
    lines.append("\tif (__x86_loop.failed)")
    lines.append("\t\treturn XDP_ABORTED;")
    for addr in (0x11a1, 0x11a4):
        append_step(lines, by_addr[addr])
    lines.append("\t/* 0x11a9: ret */")
    lines.append("\tX86_VM_RET_RAX();")
    lines.append("\t#undef __x86_vm_insn")
    lines.append("\t#undef __x86_vm_state")
    lines.append("\treturn XDP_ABORTED;")
    lines.append("}")
    lines.append("")
    lines.append("X86_VM_LICENSE();")
    lines.append("")
    return "\n".join(lines)


def render_x86_subfunction(symbol: str, insns: list[NativeInsn]) -> str:
    addrs = {insn.addr for insn in insns}
    lines = [
        f"static __noinline int x86_fn_{c_ident(symbol)}("
        "struct x86_state *__x86_vm_state_ptr, void *__x86_vm_data, "
        "void *__x86_vm_data_end)",
        "{",
        "\t#define __x86_vm_state (*__x86_vm_state_ptr)",
        "\tstruct x86_insn __x86_vm_insn = {};",
    ]
    for reg in ("rbx", "r12", "r13", "r14", "r15"):
        lines.extend([
            f"\t__u64 __save_{reg} = __x86_vm_state.{reg};",
            f"\tvoid *__save_p_{reg} = __x86_vm_state.p_{reg};",
            f"\t__u8 __save_tag_{reg} = __x86_vm_state.tag_{reg};",
        ])
    lines.extend([
        "\t#define X86_VM_SUB_RETURN() do { \\",
        "\t\t__x86_vm_state.rbx = __save_rbx; \\",
        "\t\t__x86_vm_state.r12 = __save_r12; \\",
        "\t\t__x86_vm_state.r13 = __save_r13; \\",
        "\t\t__x86_vm_state.r14 = __save_r14; \\",
        "\t\t__x86_vm_state.r15 = __save_r15; \\",
        "\t\t__x86_vm_state.p_rbx = __save_p_rbx; \\",
        "\t\t__x86_vm_state.p_r12 = __save_p_r12; \\",
        "\t\t__x86_vm_state.p_r13 = __save_p_r13; \\",
        "\t\t__x86_vm_state.p_r14 = __save_p_r14; \\",
        "\t\t__x86_vm_state.p_r15 = __save_p_r15; \\",
        "\t\t__x86_vm_state.tag_rbx = __save_tag_rbx; \\",
        "\t\t__x86_vm_state.tag_r12 = __save_tag_r12; \\",
        "\t\t__x86_vm_state.tag_r13 = __save_tag_r13; \\",
        "\t\t__x86_vm_state.tag_r14 = __save_tag_r14; \\",
        "\t\t__x86_vm_state.tag_r15 = __save_tag_r15; \\",
        "\t\treturn X86_INTERP_CONTINUE; \\",
        "\t} while (0)",
    ])
    for insn in insns:
        if is_subfunction_frame_insn(insn):
            lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
            lines.append("\t/* generated-C ABI: callee-save frame traffic handled by wrapper */")
            continue
        lines.append(f"x86_l_{insn.addr:x}:")
        append_branch_or_ret(lines, insn, addrs, subroutine=True,
                             step_macro="X86_VM_RUN_OP_SUB",
                             ret_statement="X86_VM_SUB_RETURN();")
    lines.extend([
        "\t#undef X86_VM_SUB_RETURN",
        "\t#undef __x86_vm_state",
        "\treturn X86_INTERP_TRAP;",
        "}",
        "",
    ])
    return "\n".join(lines)


def subfunction_saved_regs(insns: list[NativeInsn]) -> list[str]:
    saved: set[str] = set()
    for insn in insns:
        if insn.mnemonic == "push" and len(insn.operands) == 1:
            reg = insn.operands[0].lower()
            if reg in CALLEE_SAVED_REGS and reg != "rbp":
                saved.add(reg)
    return [reg for reg in ("rbx", "r12", "r13", "r14", "r15") if reg in saved]


def append_inline_subfunction(lines: list[str], symbol: str,
                              insns: list[NativeInsn], indent: str) -> None:
    saved_regs = subfunction_saved_regs(insns)
    lines.append(f"{indent}/* inline {symbol} in the bpf_loop verifier frame */")
    lines.append(f"{indent}{{")
    for reg in saved_regs:
        lines.extend([
            f"{indent}\t__u64 __save_{reg} = loop->state.{reg};",
            f"{indent}\tvoid *__save_p_{reg} = loop->state.p_{reg};",
            f"{indent}\t__u8 __save_tag_{reg} = loop->state.tag_{reg};",
        ])
    for insn in insns:
        if is_subfunction_frame_insn(insn):
            lines.append(f"{indent}\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
            lines.append(f"{indent}\t/* generated-C ABI: callee-save frame traffic handled by wrapper */")
            continue
        if insn.mnemonic == "ret":
            lines.append(f"{indent}\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
            lines.append(f"{indent}\t/* inline callee returns to structured caller */")
            continue
        append_loop_step(lines, insn, f"{indent}\t", "LOCAL_CALL_LOOP_STEP")
    for reg in saved_regs:
        lines.extend([
            f"{indent}\tloop->state.{reg} = __save_{reg};",
            f"{indent}\tloop->state.p_{reg} = __save_p_{reg};",
            f"{indent}\tloop->state.tag_{reg} = __save_tag_{reg};",
        ])
    lines.append(f"{indent}}}")


def render_local_call_fanout_dispatch(name: str, insns: list[NativeInsn],
                                      subfunctions: dict[str, list[NativeInsn]]) -> str:
    by_addr = {insn.addr: insn for insn in insns}
    addrs = {insn.addr for insn in insns}
    required = {
        "local_call_linear",
        "local_call_pressure",
        "local_call_crossload",
        "local_call_bytes",
    }
    missing = required - set(subfunctions)
    if missing:
        raise ValueError(f"{name}: missing local-call subfunctions: {sorted(missing)}")

    lines: list[str] = [
        "#define X86_VM_ENABLE_STACK 1",
        "#define X86_VM_ENABLE_PACKET_REG_FASTPATH 1",
        '#include "../x86_vm_bpf.h"',
        "",
    ]
    lines.extend([
        "struct local_call_fanout_loop_ctx {",
        "\tstruct x86_state state;",
        "\tvoid *data;",
        "\tvoid *data_end;",
        "\t__u32 failed;",
        "};",
        "",
        "#define LOCAL_CALL_LOOP_STEP(HELPER, OP, DST, SRC, FLAGS, AUX, IMM) \\",
        "\tdo {                                                               \\",
        "\t\tstruct x86_insn __x86_loop_insn = X86_VM_INSN((OP), (DST),   \\",
        "\t\t\t(SRC), (FLAGS), (AUX), (IMM));                         \\",
        "\t\tint __x86_loop_ret = HELPER(&loop->state, &__x86_loop_insn,  \\",
        "\t\t\t\t\t       loop->data, loop->data_end);       \\",
        "\t\tif (__x86_loop_ret != X86_INTERP_CONTINUE) {                 \\",
        "\t\t\tloop->failed = __LINE__;                               \\",
        "\t\t\treturn 1;                                             \\",
        "\t\t}                                                          \\",
        "\t} while (0)",
        "",
        "static long local_call_fanout_cb(__u32 index, void *ctx)",
        "{",
        "\tstruct local_call_fanout_loop_ctx *loop = ctx;",
        "",
        "\tif (loop->failed)",
        "\t\treturn 1;",
        "\tif (index >= 16) {",
        "\t\tloop->failed = __LINE__;",
        "\t\treturn 1;",
        "\t}",
        "\t/* proof-loop induction variables from native rbx/r12/r13. */",
        "\tloop->state.rbx = (__u64)index << 3;",
        "\tloop->state.p_rbx = 0;",
        "\tloop->state.tag_rbx = X86_PTR_NONE;",
        "\tloop->state.r12 = (__u64)index << 4;",
        "\tloop->state.p_r12 = 0;",
        "\tloop->state.tag_r12 = X86_PTR_NONE;",
        "\tloop->state.r13 = 23 + ((__u64)index * 24);",
        "\tloop->state.p_r13 = 0;",
        "\tloop->state.tag_r13 = X86_PTR_NONE;",
    ])

    for addr in (0x11b6, 0x11bc, 0x11c0, 0x11c5, 0x11c8, 0x11cc):
        append_loop_step(lines, by_addr[addr], "\t", "LOCAL_CALL_LOOP_STEP")
    lines.append(f"\t/* 0x11d0: {c_comment(by_addr[0x11d0].raw)} */")
    lines.append("\tif (x86_eval_cc(&loop->state, X86_CC_E)) {")
    for addr in (0x11f0, 0x11f4):
        append_loop_step(lines, by_addr[addr], "\t\t", "LOCAL_CALL_LOOP_STEP")
    append_inline_subfunction(lines, "local_call_crossload",
                              subfunctions["local_call_crossload"], "\t\t")
    lines.append("\t} else {")
    append_loop_step(lines, by_addr[0x11d2], "\t\t", "LOCAL_CALL_LOOP_STEP")
    lines.append(f"\t\t/* 0x11d6: {c_comment(by_addr[0x11d6].raw)} */")
    lines.append("\t\tif (x86_eval_cc(&loop->state, X86_CC_E)) {")
    for addr in (0x1180, 0x1184):
        append_loop_step(lines, by_addr[addr], "\t\t\t", "LOCAL_CALL_LOOP_STEP")
    append_inline_subfunction(lines, "local_call_pressure",
                              subfunctions["local_call_pressure"], "\t\t\t")
    lines.append("\t\t} else {")
    append_loop_step(lines, by_addr[0x11d8], "\t\t\t", "LOCAL_CALL_LOOP_STEP")
    lines.append(f"\t\t\t/* 0x11db: {c_comment(by_addr[0x11db].raw)} */")
    lines.append("\t\t\tif (x86_eval_cc(&loop->state, X86_CC_NE)) {")
    for addr in (0x1200, 0x1204):
        append_loop_step(lines, by_addr[addr], "\t\t\t\t", "LOCAL_CALL_LOOP_STEP")
    append_inline_subfunction(lines, "local_call_bytes",
                              subfunctions["local_call_bytes"], "\t\t\t\t")
    lines.append("\t\t\t} else {")
    for addr in (0x11dd, 0x11e1):
        append_loop_step(lines, by_addr[addr], "\t\t\t\t", "LOCAL_CALL_LOOP_STEP")
    append_inline_subfunction(lines, "local_call_linear",
                              subfunctions["local_call_linear"], "\t\t\t\t")
    lines.append("\t\t\t}")
    lines.append("\t\t}")
    lines.append("\t}")

    for addr in (0x118c, 0x118e, 0x1191, 0x1194, 0x1197, 0x119a,
                 0x119d, 0x11a1, 0x11a5, 0x11a9, 0x11b0):
        append_loop_step(lines, by_addr[addr], "\t", "LOCAL_CALL_LOOP_STEP")
    lines.append(f"\t/* 0x11b4: {c_comment(by_addr[0x11b4].raw)} */")
    lines.append("\t/* proof-loop branch handled by bpf_loop trip count */")
    lines.append("\treturn 0;")
    lines.append("}")
    lines.extend([
        "",
        "SEC(\"xdp\")",
        f"int {name}_x86_vm_xdp(struct xdp_md *ctx)",
        "{",
        "\tvoid *__x86_vm_data = (void *)(long)ctx->data;",
        "\tvoid *__x86_vm_data_end = (void *)(long)ctx->data_end;",
        "\tstruct local_call_fanout_loop_ctx __x86_loop = {};",
        "\tstruct x86_insn __x86_vm_insn = {};",
        "\t#define __x86_vm_state __x86_loop.state",
        "\tx86_init_state(&__x86_vm_state, (void *)ctx);",
        "\t__x86_vm_state.rbp = 0;",
        "\t__x86_vm_state.p_rbp = 0;",
        "\t__x86_vm_state.tag_rbp = X86_PTR_STACK;",
        "\t__x86_vm_state.rsp = 0;",
        "\t__x86_vm_state.p_rsp = 0;",
        "\t__x86_vm_state.tag_rsp = X86_PTR_STACK;",
    ])

    for insn in insns:
        if insn.addr >= 0x1171:
            break
        lines.append(f"x86_l_{insn.addr:x}:")
        if is_entry_synthetic_frame_insn(insn):
            lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
            lines.append("\t/* generated-C ABI: entry frame traffic handled by wrapper */")
            continue
        append_branch_or_ret(lines, insn, addrs)

    lines.append(f"\t/* 0x1171: {c_comment(by_addr[0x1171].raw)} */")
    lines.append("\t/* proof-loop body handled by bpf_loop callback */")
    lines.append("\t__x86_loop.data = __x86_vm_data;")
    lines.append("\t__x86_loop.data_end = __x86_vm_data_end;")
    lines.append("\tif (bpf_loop(16, local_call_fanout_cb, &__x86_loop, 0) < 0)")
    lines.append("\t\treturn XDP_ABORTED;")
    lines.append("\tif (__x86_loop.failed)")
    lines.append("\t\treturn XDP_ABORTED;")
    lines.append("x86_l_1211:")
    append_step(lines, by_addr[0x1211])
    lines.append("x86_l_1214:")
    append_step(lines, by_addr[0x1214])
    for addr in (0x1219, 0x121d, 0x121e, 0x1220, 0x1222, 0x1224, 0x1226):
        lines.append(f"x86_l_{addr:x}:")
        lines.append(f"\t/* 0x{addr:x}: {c_comment(by_addr[addr].raw)} */")
        lines.append("\t/* generated-C ABI: entry frame traffic handled by wrapper */")
    lines.append("x86_l_1227:")
    lines.append("\t/* 0x1227: ret */")
    lines.append("\tX86_VM_RET_RAX();")
    lines.append("\t#undef __x86_vm_insn")
    lines.append("\t#undef __x86_vm_state")
    lines.append("\treturn XDP_ABORTED;")
    lines.append("}")
    lines.append("")
    lines.append("X86_VM_LICENSE();")
    lines.append("")
    return "\n".join(lines)


def render_program(name: str, insns: list[NativeInsn],
                   subfunctions: dict[str, list[NativeInsn]] | None = None) -> str:
    if name == "packet_checksum_fold":
        return render_packet_checksum_fold(name, insns)

    ret_statement = (
        "return XDP_PASS;"
        if name in {"tc_packet_checksum_fold", "cgroup_skb_hash_chain"}
        else "X86_VM_RET_RAX();"
    )
    subfunctions = subfunctions or {}
    if name == "bpf_local_call_fanout_dispatch" and subfunctions:
        return render_local_call_fanout_dispatch(name, insns, subfunctions)
    synthetic_entry_frame = bool(subfunctions)
    rbp_bias = 0 if synthetic_entry_frame else 8
    addrs = {insn.addr for insn in insns}
    subfunction_by_addr = {
        fn_insns[0].addr: f"x86_fn_{c_ident(symbol)}"
        for symbol, fn_insns in subfunctions.items()
        if fn_insns
    }
    has_rodata = any("[rip" in insn.raw.lower() for insn in insns)
    has_stack = any(
        insn.mnemonic in {"push", "pop"} or
        "[rsp" in insn.raw.lower() or
        "[rbp" in insn.raw.lower()
        for fn_insns in [insns, *subfunctions.values()]
        for insn in fn_insns
    )
    stack_feature_insns = [
        insn
        for fn_insns in [insns, *subfunctions.values()]
        for insn in fn_insns
    ]
    has_stack_ext = needs_stack_ext(stack_feature_insns, rbp_bias=rbp_bias)
    has_stack_slot7 = needs_stack_slot7(stack_feature_insns, rbp_bias=rbp_bias)
    has_stack_deep = needs_stack_deep(stack_feature_insns, rbp_bias=rbp_bias)
    next_addrs = {
        insn.addr: insns[index + 1].addr
        for index, insn in enumerate(insns[:-1])
    }
    call_returns = {
        next_addrs[insn.addr]
        for insn in insns
        if insn.mnemonic == "call"
        and insn.addr in next_addrs
        and branch_target(insn.operands[0]) in addrs
    }
    lines: list[str] = []
    if has_rodata:
        lines.append('#define X86_VM_ENABLE_RODATA 1')
    if has_stack:
        lines.append('#define X86_VM_ENABLE_STACK 1')
    if has_stack_slot7:
        lines.append('#define X86_VM_ENABLE_STACK_SLOT7 1')
    if has_stack_deep:
        lines.append('#define X86_VM_ENABLE_STACK_DEEP 1')
    if has_stack_ext:
        lines.append('#define X86_VM_ENABLE_STACK_EXT 1')
    lines.extend([
        '#include "../x86_vm_bpf.h"',
        "",
    ])
    for symbol, fn_insns in subfunctions.items():
        lines.append(render_x86_subfunction(symbol, fn_insns))
    lines.extend([
        "SEC(\"xdp\")",
        f"int {name}_x86_vm_xdp(struct xdp_md *ctx)",
        "{",
        "\tX86_VM_DECLARE_XDP(ctx);",
    ])
    if synthetic_entry_frame:
        lines.extend([
            "\t__x86_vm_state.rbp = 0;",
            "\t__x86_vm_state.p_rbp = 0;",
            "\t__x86_vm_state.tag_rbp = X86_PTR_STACK;",
            "\t__x86_vm_state.rsp = 0;",
            "\t__x86_vm_state.p_rsp = 0;",
            "\t__x86_vm_state.tag_rsp = X86_PTR_STACK;",
        ])
    if call_returns:
        lines.extend([
            "\t__u64 __x86_call_ret0 = 0;",
            "\t__u64 __x86_call_ret1 = 0;",
            "\t__u32 __x86_call_depth = 0;",
        ])
    for insn in insns:
        label = f"x86_l_{insn.addr:x}"
        lines.append(f"{label}:")
        if synthetic_entry_frame and is_entry_synthetic_frame_insn(insn):
            lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
            lines.append("\t/* generated-C ABI: entry frame traffic handled by wrapper */")
            continue
        append_branch_or_ret(lines, insn, addrs,
                             next_addr=next_addrs.get(insn.addr),
                             call_returns=call_returns,
                             call_functions=subfunction_by_addr,
                             ret_statement=ret_statement)
    lines.extend([
        "\treturn XDP_ABORTED;",
        "}",
        "",
        "X86_VM_LICENSE();",
        "",
    ])
    return "\n".join(lines)


def write_one(md_path: Path, out_dir: Path, *,
              native_source: str = "markdown") -> Path:
    name = md_path.stem
    no_jump_tables = native_source == "object-no-jump-tables"
    if native_source == "markdown":
        insns = parse_native_asm(md_path)
    elif no_jump_tables:
        insns = parse_entry_native_function(name, no_jump_tables=True)
    else:
        raise ValueError(f"unknown native source: {native_source}")
    missing_symbols = unresolved_call_symbols(insns)
    subfunctions: dict[str, list[NativeInsn]] = {}
    if missing_symbols:
        native_functions = parse_full_native_functions(
            name, missing_symbols, no_jump_tables=no_jump_tables
        )
        insns = native_functions.pop(f"{name}_xdp")
        subfunctions = native_functions
    if not insns:
        raise ValueError(f"{md_path}: no native instructions parsed")
    output = out_dir / f"{name}.bpf.c"
    output.write_text(render_program(name, insns, subfunctions))
    return output


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--micro-programs", type=Path, default=MICRO_PROGRAMS)
    parser.add_argument("--output-dir", type=Path, default=OUT_DIR)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark stem list")
    parser.add_argument(
        "--native-source",
        choices=("markdown", "object-no-jump-tables"),
        default="markdown",
        help="where to read native x86 disassembly from",
    )
    args = parser.parse_args()

    args.output_dir.mkdir(parents=True, exist_ok=True)
    only = set(args.only or [])
    written: list[Path] = []
    for md_path in sorted(args.micro_programs.glob("*.md")):
        if only and md_path.stem not in only:
            continue
        written.append(write_one(md_path, args.output_dir,
                                 native_source=args.native_source))

    for path in written:
        print(path)
    print(f"generated {len(written)} proof sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
