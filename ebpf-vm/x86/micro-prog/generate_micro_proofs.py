#!/usr/bin/env python3
"""Generate hardcoded x86-VM verifier artifacts from micro Native ASM blocks."""

from __future__ import annotations

import argparse
import re
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

REGS: dict[str, tuple[str, int]] = {}
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
        REGS[name] = (f"X86_{base}", width)

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


def parse_native_asm(md_path: Path) -> list[NativeInsn]:
    insns: list[NativeInsn] = []
    for line in extract_native_asm(md_path.read_text()).splitlines():
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


def parse_int(text: str) -> int:
    text = text.strip()
    if text.startswith("-"):
        return -parse_int(text[1:])
    return int(text, 16) if text.lower().startswith("0x") else int(text, 10)


def is_int(text: str) -> bool:
    return re.fullmatch(r"-?(0x[0-9a-fA-F]+|\d+)", text.strip()) is not None


def c_u64(value: int) -> str:
    return f"{value & 0xffffffffffffffff}ULL"


def reg_info(operand: str) -> tuple[str, int] | None:
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
    match = re.search(r"\[([a-z0-9]+)", operand.lower())
    if match is None:
        return "X86_REG_NONE"
    parsed = reg_info(match.group(1))
    return parsed[0] if parsed is not None else "X86_REG_NONE"


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


def mem_aux(operand: str, mem_width: int | None = None) -> str:
    _base, index, scale_log2, _disp = parse_mem_terms(operand)
    if mem_width is not None:
        return f"X86_MEM_AUX_FULL({index}, {scale_log2}, {WIDTH_CONST[mem_width]})"
    return f"X86_MEM_AUX({index}, {scale_log2})"


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
                       aux=mem_aux(dst),
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
        return enc("X86_OP_LEA", dst=dst_reg[0], src=mem_base_reg(ops[1]),
                   flags=WIDTH_CONST[dst_reg[1]], imm=c_u64(mem_disp(ops[1])))

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


def render_program(name: str, insns: list[NativeInsn]) -> str:
    addrs = {insn.addr for insn in insns}
    lines = [
        '#include "../x86_vm_bpf.h"',
        "",
        "SEC(\"xdp\")",
        f"int {name}_x86_vm_xdp(struct xdp_md *ctx)",
        "{",
        "\tX86_VM_DECLARE_XDP(ctx);",
    ]
    for insn in insns:
        label = f"x86_l_{insn.addr:x}"
        lines.append(f"{label}:")
        lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        if insn.mnemonic in CC_AUX and insn.mnemonic.startswith("j"):
            target = branch_target(insn.operands[0]) if insn.operands else 0
            if target in addrs:
                lines.append(f"\tif (x86_eval_cc(&__x86_vm_state, {CC_AUX[insn.mnemonic]}))")
                lines.append(f"\t\tgoto x86_l_{target:x};")
            else:
                lines.append(f"\tif (x86_eval_cc(&__x86_vm_state, {CC_AUX[insn.mnemonic]}))")
                lines.append("\t\treturn XDP_ABORTED;")
            continue
        if insn.mnemonic == "jmp":
            target = branch_target(insn.operands[0]) if insn.operands else 0
            if target in addrs:
                lines.append(f"\tgoto x86_l_{target:x};")
            else:
                lines.append("\treturn XDP_ABORTED;")
            continue
        if insn.mnemonic == "ret":
            lines.append("\tX86_VM_RET_RAX();")
            continue
        encoded = encode(insn)
        lines.append(
            "\tX86_VM_RUN_STEP("
            f"{encoded.op}, {encoded.dst}, {encoded.src}, {encoded.flags}, "
            f"{encoded.aux}, {encoded.imm});"
        )
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
    if not insns:
        raise ValueError(f"{md_path}: no native instructions parsed")
    output = out_dir / f"{name}.bpf.c"
    output.write_text(render_program(name, insns))
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
