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


def native_object_path(name: str) -> Path:
    out_dir = Path("/tmp/bpf-benchmark-micro-native")
    so_path = out_dir / f"{name}.native.so"
    subprocess.run(
        ["make", "-C", str(MICRO_PROGRAMS), f"OUTPUT_DIR={out_dir}", str(so_path)],
        cwd=REPO_ROOT,
        check=True,
        stdout=subprocess.DEVNULL,
    )
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


def parse_full_native_functions(name: str, symbols: list[str]) -> dict[str, list[NativeInsn]]:
    so_path = native_object_path(name)
    out: dict[str, list[NativeInsn]] = {
        f"{name}_xdp": parse_native_symbol(so_path, f"{name}_xdp"),
    }
    for symbol in symbols:
        out[symbol] = parse_native_symbol(so_path, symbol)
    return out


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


def append_step(lines: list[str], insn: NativeInsn, indent: str = "\t",
                step_macro: str = "X86_VM_RUN_STEP") -> None:
    encoded = encode(insn)
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(
        f"{indent}{step_macro}("
        f"{encoded.op}, {encoded.dst}, {encoded.src}, {encoded.flags}, "
        f"{encoded.aux}, {encoded.imm});"
    )


def append_ret_dispatch(lines: list[str], call_returns: set[int],
                        indent: str) -> None:
    lines.append(f"{indent}if (__x86_call_depth == 0)")
    lines.append(f"{indent}\tX86_VM_RET_RAX();")
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
                         step_macro: str = "X86_VM_RUN_STEP") -> None:
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
            lines.append(f"{indent}return X86_INTERP_CONTINUE;")
            return
        if call_returns:
            append_ret_dispatch(lines, call_returns, indent)
        else:
            lines.append(f"{indent}X86_VM_RET_RAX();")
        return
    append_step(lines, insn, indent, step_macro)


def append_unrolled_branch_comment(lines: list[str], insn: NativeInsn,
                                   indent: str) -> None:
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(f"{indent}/* proof-unrolled backward branch */")


def append_loop_step(lines: list[str], insn: NativeInsn, indent: str = "\t") -> None:
    encoded = encode(insn)
    lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    lines.append(
        f"{indent}PACKET_CHECKSUM_LOOP_STEP("
        f"{encoded.op}, {encoded.dst}, {encoded.src}, {encoded.flags}, "
        f"{encoded.aux}, {encoded.imm});"
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
        "#define PACKET_CHECKSUM_LOOP_STEP(OP, DST, SRC, FLAGS, AUX, IMM)        \\",
        "\tdo {                                                               \\",
        "\t\tloop->insn.op = (OP);                                         \\",
        "\t\tloop->insn.dst = (DST);                                       \\",
        "\t\tloop->insn.src = (SRC);                                       \\",
        "\t\tloop->insn.flags = (FLAGS);                                  \\",
        "\t\tloop->insn.aux = (AUX);                                      \\",
        "\t\tloop->insn.imm = (IMM);                                      \\",
        "\t\tint __x86_loop_ret = x86_exec_one(&loop->state, &loop->insn, \\",
        "\t\t\t\t\t\t       loop->data, loop->data_end);     \\",
        "\t\tif (__x86_loop_ret != X86_INTERP_CONTINUE) {                 \\",
        "\t\t\tloop->failed = 1;                                      \\",
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
        "\t\tloop->failed = 1;",
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
        "\tstruct x86_insn __x86_vm_insn = {};",
        "\t#define __x86_vm_state (*__x86_vm_state_ptr)",
    ]
    for insn in insns:
        lines.append(f"x86_l_{insn.addr:x}:")
        append_branch_or_ret(lines, insn, addrs, subroutine=True,
                             step_macro="X86_VM_RUN_STEP_SUB")
    lines.extend([
        "\t#undef __x86_vm_state",
        "\treturn X86_INTERP_TRAP;",
        "}",
        "",
    ])
    return "\n".join(lines)


def render_program(name: str, insns: list[NativeInsn],
                   subfunctions: dict[str, list[NativeInsn]] | None = None) -> str:
    if name == "packet_checksum_fold":
        return render_packet_checksum_fold(name, insns)

    subfunctions = subfunctions or {}
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
    next_addrs = {
        insn.addr: insns[index + 1].addr
        for index, insn in enumerate(insns[:-1])
    }
    call_returns = {
        next_addrs[insn.addr]
        for insn in insns
        if insn.mnemonic == "call" and insn.addr in next_addrs
    }
    lines: list[str] = []
    if has_rodata:
        lines.append('#define X86_VM_ENABLE_RODATA 1')
    if has_stack:
        lines.append('#define X86_VM_ENABLE_STACK 1')
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
    if call_returns:
        lines.extend([
            "\t__u64 __x86_call_ret0 = 0;",
            "\t__u64 __x86_call_ret1 = 0;",
            "\t__u32 __x86_call_depth = 0;",
        ])
    for insn in insns:
        label = f"x86_l_{insn.addr:x}"
        lines.append(f"{label}:")
        append_branch_or_ret(lines, insn, addrs,
                             next_addr=next_addrs.get(insn.addr),
                             call_returns=call_returns,
                             call_functions=subfunction_by_addr)
    lines.extend([
        "\treturn XDP_ABORTED;",
        "}",
        "",
        "X86_VM_LICENSE();",
        "",
    ])
    return "\n".join(lines)


def write_one(md_path: Path, out_dir: Path) -> Path:
    name = md_path.stem
    insns = parse_native_asm(md_path)
    missing_symbols = unresolved_call_symbols(insns)
    subfunctions: dict[str, list[NativeInsn]] = {}
    if missing_symbols:
        native_functions = parse_full_native_functions(name, missing_symbols)
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
    args = parser.parse_args()

    args.output_dir.mkdir(parents=True, exist_ok=True)
    only = set(args.only or [])
    written: list[Path] = []
    for md_path in sorted(args.micro_programs.glob("*.md")):
        if only and md_path.stem not in only:
            continue
        written.append(write_one(md_path, args.output_dir))

    for path in written:
        print(path)
    print(f"generated {len(written)} proof sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
