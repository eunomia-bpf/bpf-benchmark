#!/usr/bin/env python3
"""Generate hardcoded arm64-simulator verifier artifacts from micro native code."""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from collections import OrderedDict, deque
from dataclasses import dataclass, replace
from pathlib import Path

import yaml

from generated_arm64_cc_decode import COND
from generated_arm64_decode import ALU, BITFIELD, MOD, SHIFT
from generated_arm64_helper_idents import HELPER_IDENTS


REPO_ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(REPO_ROOT / "kprog"))
from arm64_abi import check_definedness
OUT_DIR = Path(__file__).resolve().parent
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
STAGE2_PROGRAMS = REPO_ROOT / "kprog" / "test"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
PROOF_OBJECT_DIR = OUT_DIR / "build" / "native-link"

WIDTH_CONST = {1: "ARM64_WIDTH_8", 2: "ARM64_WIDTH_16", 4: "ARM64_WIDTH_32", 8: "ARM64_WIDTH_64"}

# ALU/SHIFT/MOD/BITFIELD mnemonic-to-code tables come from the generated
# module (kprog/formal/arm64_decode_spec.json); the condition mnemonic-to-code
# table from kprog/formal/arm64_cc_decode_spec.json; the BPF helper-ident
# table from kprog/formal/arm64_helper_idents_spec.json. All imported at the
# top.
GPR_WRITE_OPS = {
    "add", "sub", "and", "bic", "eor", "orr", "orn",
    "adds", "subs", "ands", "bics", "adrp",
    "mov", "movk", "lsl", "lsr", "asr", "ror",
    "madd", "msub", "mul", "umull", "umulh", "umaddl", "smaddl", "udiv",
    "mvn", "neg", "cneg", "extr", "ubfx", "sbfx", "ubfiz", "bfxil", "bfi",
    "rev", "rev16", "sxtb", "sxth", "sxtw", "ldr", "ldur", "ldaxr", "ldxr", "ldrb", "ldurb", "ldrh", "ldurh",
    "ldrsb", "ldrsh", "ldrsw",
    "ldp", "stlxr", "stxr", "csel", "cinc", "cinv", "csinc", "csinv", "csneg", "cset", "csetm", "fmov",
}


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
    reloc_symbol: str | None = None
    reloc_addend: int = 0
    source_pointer: tuple[bool, str] | None = None


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


def rodata_bytes(obj: Path) -> bytes:
    result = subprocess.run(
        ["aarch64-linux-gnu-objdump", "-s", "-j", ".native_link_rodata", str(obj)],
        cwd=REPO_ROOT, check=False, text=True, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
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


def load_rodata_blobs(obj: Path) -> dict[str, bytes]:
    data = rodata_bytes(obj)
    if not data:
        return {}
    result = subprocess.run(["aarch64-linux-gnu-objdump", "-t", str(obj)],
                            cwd=REPO_ROOT, check=True, text=True,
                            stdout=subprocess.PIPE)
    out: dict[str, bytes] = {}
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
        if size <= 0 or offset + size > len(data):
            raise ValueError(f"native readonly extent exceeds its section: {name} offset={offset} size={size}")
        out[name] = data[offset:offset+size]
    return out


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


def parse_flat_instructions(text: str) -> list[NativeInsn]:
    insns: list[NativeInsn] = []
    insn_re = re.compile(r"^\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+\t([a-z0-9.]+)\s*(.*)$")
    for line in text.splitlines():
        reloc = re.search(r"\bR_AARCH64_[A-Z0-9_]+\s+(\S+)", line)
        if reloc is not None and insns:
            expression = reloc.group(1)
            suffix = re.search(r"([+-])0x([0-9a-fA-F]+)$", expression)
            symbol = expression[:suffix.start()] if suffix else expression
            addend = (int(suffix[2], 16) * (-1 if suffix[1] == '-' else 1)) if suffix else 0
            insns[-1] = NativeInsn(
                insns[-1].addr,
                insns[-1].mnemonic,
                insns[-1].operands,
                insns[-1].raw,
                symbol,
                addend,
            )
            continue
        m_insn = insn_re.match(line)
        if not m_insn:
            continue
        operands = m_insn.group(3).split("//", 1)[0].strip()
        asm = f"{m_insn.group(2)} {operands}".strip()
        addr = int(m_insn.group(1), 16)
        insns.append(NativeInsn(addr, m_insn.group(2), split_operands(operands), asm))
    return [normalize_alias(insn) for insn in insns]


def parse_native_linked_program(
    bench: Bench,
    proof_object_dir: Path,
) -> tuple[OrderedDict[str, list[NativeInsn]], dict[str, bytes | tuple[int, int]]]:
    symbol = bench.symbol
    proof_obj = proof_object_dir / f"{bench.name}.proof.o"
    if not proof_obj.is_file():
        raise RuntimeError(f"missing proof object for {bench.name}: {proof_obj}")
    rodata16 = load_rodata_blobs(proof_obj)
    disasm = subprocess.run(
        ["aarch64-linux-gnu-objdump", "-dr", str(proof_obj)],
        cwd=REPO_ROOT, check=True, text=True, stdout=subprocess.PIPE,
    )
    insns = parse_flat_instructions(disasm.stdout)
    if not insns:
        raise RuntimeError(f"{bench.name}: no arm64 native-link instructions parsed")
    return OrderedDict([(symbol, insns)]), rodata16


def branch_target(operand: str) -> int:
    return int(operand.split()[0], 16)


def program_kind(item: dict) -> str:
    tags = set(item.get("tags", []))
    if "cgroup-skb" in tags or "cgroup_skb" in tags:
        return "cgroup_skb"
    if "tc" in tags:
        return "tc"
    return "xdp"


def default_program_symbol(item: dict) -> str:
    name = item["name"]
    tags = set(item.get("tags", []))
    if "stage2" in tags:
        return name
    if "cgroup-skb" in tags or "cgroup_skb" in tags or "tc" in tags:
        return f"{name}_prog"
    return f"{name}_xdp"


def load_benches(config_path: Path) -> list[Bench]:
    data = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    return [
        Bench(item["name"], default_program_symbol(item), program_kind(item))
        for item in data["benchmarks"]
    ]


def is_helper_symbol(symbol: str | None) -> bool:
    return bool(symbol and symbol in HELPER_IDENTS.values())


def c_comment(text: str) -> str:
    return text.replace("*/", "* /")


def source_prelude(source: Path) -> str:
    text = source.read_text(encoding="utf-8")
    match = re.search(r'\nSEC\("[^"]+"\)\s+int\s+', text)
    if match is None:
        return ""
    prelude = text[:match.start()].strip()
    return prelude.replace(
        '#include "include/native_helpers.h"',
        '#include "../../test/include/native_helpers.h"',
    )


def c_u64(value: int) -> str:
    return f"{value & 0xffffffffffffffff}ULL"


def c_ptr_u64(expr: str) -> str:
    return f"((__u64)(long){expr})"


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
    if reg in {"sp", "wsp"}:
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
    m_ext = re.fullmatch(r"(uxtw|sxtw|uxth|sxth|uxtb|sxtb|uxtx|sxtx)(?:\s+#(0x[0-9a-f]+|[0-9]+))?", text)
    if m_ext:
        extension, shift = m_ext.group(1), int(m_ext.group(2) or "0", 0)
        if shift > 4:
            raise ValueError(f"invalid AArch64 extend shift: {text}")
        # ExtendReg takes min(source-size, operand-size); full-size extensions
        # have the same active bits as LSL, including W-form truncation.
        return MOD["lsl" if extension in {"uxtx", "sxtx"} else extension], shift
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


def rodata_ident_map(rodata16: dict[str, bytes | tuple[int, int]]) -> dict[str, str]:
    return {symbol: f"__arm64_rodata_{index}" for index, symbol in enumerate(rodata16)}


def c_ident(prefix: str, value: str, index: int) -> str:
    ident = re.sub(r"[^A-Za-z0-9_]", "_", value)
    ident = re.sub(r"_+", "_", ident).strip("_")
    if not ident or ident[0].isdigit():
        ident = f"{prefix}_{ident}"
    return f"{ident}_{index}"


def normalize_alias(insn: NativeInsn) -> NativeInsn:
    """Normalize aliases before both ABI/CFG analysis and operation encoding."""
    op, ops = insn.mnemonic, insn.operands
    if op in {"movz", "movn"}:
        if len(ops) not in {2, 3} or ops[0].lower() in {"sp", "wsp"}:
            raise ValueError(f"invalid move-wide operands: {insn.raw}")
        reg_const(ops[0])
        bits = 8 * reg_width(ops[0])
        immediate, shift = parse_imm(ops[1]), 0
        if len(ops) == 3:
            suffix = re.fullmatch(r"lsl\s+#(0x[0-9a-f]+|[0-9]+)", ops[2].lower())
            if not suffix:
                raise ValueError(f"invalid move-wide shift: {insn.raw}")
            shift = int(suffix[1], 0)
        if not 0 <= immediate <= 0xffff or shift % 16 or not 0 <= shift < bits:
            raise ValueError(f"invalid move-wide immediate or column: {insn.raw}")
        value = immediate << shift
        if op == "movn":
            value = ~value
        value &= (1 << bits) - 1
        return replace(insn, mnemonic="mov", operands=(ops[0], f"#{value:#x}"))
    if op == "negs":
        if len(ops) not in {2, 3} or any(reg.lower() in {"sp", "wsp"} for reg in ops[:2]):
            raise ValueError(f"invalid NEGS operands: {insn.raw}")
        if len(ops) == 3 and not re.fullmatch(r"(?:lsl|lsr|asr)\s+#(?:0x[0-9a-f]+|[0-9]+)", ops[2].lower()):
            raise ValueError(f"invalid NEGS modifier: {insn.raw}")
        mod, shift = parse_modifier(ops, 2)
        if (mod not in {"ARM64_MOD_NONE", "ARM64_MOD_LSL", "ARM64_MOD_LSR", "ARM64_MOD_ASR"}
                or reg_width(ops[0]) != reg_width(ops[1]) or shift >= 8 * reg_width(ops[0])):
            raise ValueError(f"invalid NEGS shift or register width: {insn.raw}")
        zero = "wzr" if reg_width(ops[0]) == 4 else "xzr"
        return replace(insn, mnemonic="subs", operands=(ops[0], zero, *ops[1:]))
    return insn


def encode(insn: NativeInsn, rodata_idents: dict[str, str], reloc_idents: dict[str, str]) -> Encoded:
    insn = normalize_alias(insn)
    op = insn.mnemonic
    ops = insn.operands
    if op == "nop":
        return Encoded("ARM64_OP_NOP")
    if op == "adrp":
        if not insn.reloc_symbol:
            raise ValueError(f"unsupported adrp without relocation: {insn.raw}")
        if insn.source_pointer is not None:
            return Encoded("ARM64_OP_ADRP_GOT", reg_const(ops[0]), imm=c_ptr_u64(insn.source_pointer[1]))
        if insn.reloc_symbol in rodata_idents:
            return Encoded(
                "ARM64_OP_ADRP_RODATA",
                reg_const(ops[0]),
                imm=c_ptr_u64(f"((const __u8 *){rodata_idents[insn.reloc_symbol]} + {insn.reloc_addend})")
                    if insn.reloc_addend else c_ptr_u64(rodata_idents[insn.reloc_symbol]),
            )
        if is_helper_symbol(insn.reloc_symbol):
            raise ValueError(f"unsupported adrp helper relocation: {insn.raw}")
        reloc_ident = reloc_idents.get(insn.reloc_symbol, insn.reloc_symbol)
        return Encoded("ARM64_OP_ADRP_GOT", reg_const(ops[0]),
                       imm=c_ptr_u64(f"&{reloc_ident}"))
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
    if op in {"mul", "umull", "umulh", "udiv"}:
        op_const = {"mul": "ARM64_OP_MUL", "umull": "ARM64_OP_UMULL", "umulh": "ARM64_OP_UMULH", "udiv": "ARM64_OP_UDIV"}[op]
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])))
    if op == "umaddl":
        return Encoded("ARM64_OP_UMADDL", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]), reg_const(ops[3]),
                       width="ARM64_WIDTH_64")
    if op == "smaddl":
        return Encoded("ARM64_OP_SMADDL", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]), reg_const(ops[3]),
                       width="ARM64_WIDTH_64")
    if op in {"mvn", "neg"}:
        mod, shift = parse_modifier(ops, 2)
        return Encoded("ARM64_OP_MVN" if op == "mvn" else "ARM64_OP_NEG",
                       reg_const(ops[0]), reg_const(ops[1]), width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "cneg":
        return Encoded("ARM64_OP_CNEG", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])), aux=COND[ops[2]])
    if op == "orn":
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_ORN_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "extr":
        return Encoded("ARM64_OP_EXTR", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])), imm=c_u64(parse_imm(ops[3])))
    if op in BITFIELD:
        return Encoded("ARM64_OP_BITFIELD", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_BITFIELD({BITFIELD[op]}, {parse_imm(ops[2])}, {parse_imm(ops[3])})")
    if op in {"rev", "rev16", "sxtb", "sxth", "sxtw"}:
        op_const = {"rev": "ARM64_OP_REV", "rev16": "ARM64_OP_REV16", "sxtb": "ARM64_OP_SXTB", "sxth": "ARM64_OP_SXTH", "sxtw": "ARM64_OP_SXTW"}[op]
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), width=width_const(reg_width(ops[0])))
    if op == "ldr" and ops[0].lower() == "q0":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LOAD_Q0", src=mem.base, src2=mem.index,
                       aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldr" and ops[0].lower() == "d0":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LOAD_D0", src=mem.base, src2=mem.index,
                       aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op in {"ldr", "ldur", "ldaxr", "ldxr", "ldrb", "ldurb", "ldrh", "ldurh"}:
        width = 1 if op in {"ldrb", "ldurb"} else 2 if op in {"ldrh", "ldurh"} else reg_width(ops[0])
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LOAD", reg_const(ops[0]), mem.base, mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldrsb":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LDRSB", reg_const(ops[0]), mem.base, mem.index,
                       width=width_const(reg_width(ops[0])), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldrsh":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LDRSH", reg_const(ops[0]), mem.base, mem.index,
                       width=width_const(reg_width(ops[0])), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldrsw":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_LDRSW", reg_const(ops[0]), mem.base, mem.index,
                       width=width_const(reg_width(ops[0])), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "ldp":
        mem = parse_mem(ops, 2)
        width = reg_width(ops[0])
        return Encoded("ARM64_OP_LDP", reg_const(ops[0]), reg_const(ops[1]), mem.base, mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "str" and ops[0].lower() == "q0":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_STORE_Q0", dst=mem.base, src2=mem.index,
                       aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "str" and ops[0].lower() == "d0":
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_STORE_D0", dst=mem.base, src2=mem.index,
                       aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op in {"str", "stur", "strb", "sturb", "strh", "sturh"}:
        width = 1 if op in {"strb", "sturb"} else 2 if op in {"strh", "sturh"} else reg_width(ops[0])
        mem = parse_mem(ops, 1)
        return Encoded("ARM64_OP_STORE", mem.base, reg_const(ops[0]), mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op == "stp":
        mem = parse_mem(ops, 2)
        width = reg_width(ops[0])
        return Encoded("ARM64_OP_STP", mem.base, reg_const(ops[0]), reg_const(ops[1]), mem.index,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(mem.offset))
    if op in {"stlxr", "stxr"}:
        mem = parse_mem(ops, 2)
        width = reg_width(ops[1])
        return Encoded("ARM64_OP_STLXR", reg_const(ops[0]), reg_const(ops[1]), mem.base,
                       width=width_const(width), aux=mem_aux(mem), imm=c_u64(insn.addr))
    if op in {"cmp", "tst"}:
        width = width_const(reg_width(ops[0]))
        imm = ops[1].startswith("#")
        mod, shift = ("ARM64_MOD_NONE", 0) if imm else parse_modifier(ops, 2)
        aux = f"ARM64_AUX_ALU(0, {mod}, {shift})"
        op_const = ("ARM64_OP_CMP_IMM" if imm else "ARM64_OP_CMP_REG") if op == "cmp" else \
                   ("ARM64_OP_TST_IMM" if imm else "ARM64_OP_TST_REG")
        return Encoded(op_const, reg_const(ops[0]), "ARM64_REG_NONE" if imm else reg_const(ops[1]),
                       width=width, aux=aux, imm=c_u64(parse_shifted_imm(ops, 1)) if imm else "0")
    if op == "cmn" and ops[1].startswith("#"):
        return Encoded("ARM64_OP_CMN_IMM", reg_const(ops[0]),
                       width=width_const(reg_width(ops[0])),
                       imm=c_u64(parse_shifted_imm(ops, 1)))
    if op == "cmn":
        mod, shift = parse_modifier(ops, 2)
        return Encoded("ARM64_OP_CMN_REG", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "subs" and ops[2].startswith("#"):
        return Encoded("ARM64_OP_SUBS_IMM", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       imm=c_u64(parse_shifted_imm(ops, 2)))
    if op == "subs":
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_SUBS_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "adds" and ops[2].startswith("#"):
        return Encoded("ARM64_OP_ADDS_IMM", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       imm=c_u64(parse_shifted_imm(ops, 2)))
    if op == "adds":
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_ADDS_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "bics" and ops[0] in {"wzr", "xzr"}:
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_TST_BIC_REG", reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[1])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "bics":
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_BICS_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "ands":
        if ops[2].startswith("#"):
            return Encoded("ARM64_OP_ANDS_IMM", reg_const(ops[0]), reg_const(ops[1]),
                           width=width_const(reg_width(ops[0])),
                           imm=c_u64(parse_shifted_imm(ops, 2)))
        mod, shift = parse_modifier(ops, 3)
        return Encoded("ARM64_OP_ANDS_REG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_ALU(0, {mod}, {shift})")
    if op == "ccmp":
        imm = ops[1].startswith("#")
        op_const = "ARM64_OP_CCMP_IMM" if imm else "ARM64_OP_CCMP_REG"
        return Encoded(op_const, reg_const(ops[0]), "ARM64_REG_NONE" if imm else reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])),
                       aux=f"ARM64_AUX_CCMP({COND[ops[3]]}, {parse_imm(ops[2])})",
                       imm=c_u64(parse_imm(ops[1])) if imm else "0")
    if op in {"csel", "cinc", "cset", "csetm"}:
        if op == "cset":
            return Encoded("ARM64_OP_CSET", reg_const(ops[0]), width=width_const(reg_width(ops[0])), aux=COND[ops[1]])
        if op == "csetm":
            return Encoded("ARM64_OP_CSETM", reg_const(ops[0]), width=width_const(reg_width(ops[0])), aux=COND[ops[1]])
        op_const = "ARM64_OP_CSEL" if op == "csel" else "ARM64_OP_CINC"
        src2 = reg_const(ops[2]) if op == "csel" else "ARM64_REG_NONE"
        return Encoded(op_const, reg_const(ops[0]), reg_const(ops[1]), src2,
                       width=width_const(reg_width(ops[0])), aux=COND[ops[-1]])
    if op == "cinv":
        return Encoded("ARM64_OP_CINV", reg_const(ops[0]), reg_const(ops[1]),
                       width=width_const(reg_width(ops[0])), aux=COND[ops[2]])
    if op == "csinv":
        return Encoded("ARM64_OP_CSINV", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])), aux=COND[ops[3]])
    if op == "csinc":
        return Encoded("ARM64_OP_CSINC", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])), aux=COND[ops[3]])
    if op == "csneg":
        return Encoded("ARM64_OP_CSNEG", reg_const(ops[0]), reg_const(ops[1]), reg_const(ops[2]),
                       width=width_const(reg_width(ops[0])), aux=COND[ops[3]])
    if op == "fmov":
        dst, src = ops
        vector = re.fullmatch(r"([ds])([0-9]|[12][0-9]|3[01])", dst)
        if vector and src.startswith("x" if vector[1] == "d" else "w"):
            return Encoded("ARM64_OP_FMOV", src=reg_const(src), src2=vector[2],
                           width="ARM64_WIDTH_64" if vector[1] == "d" else "ARM64_WIDTH_32",
                           aux="ARM64_FMOV_D_FROM_X" if vector[1] == "d" else "ARM64_FMOV_S_FROM_W")
        vector = re.fullmatch(r"([ds])([0-9]|[12][0-9]|3[01])", src)
        if vector and dst.startswith("x" if vector[1] == "d" else "w"):
            return Encoded("ARM64_OP_FMOV", reg_const(dst), src2=vector[2],
                           width="ARM64_WIDTH_64" if vector[1] == "d" else "ARM64_WIDTH_32",
                           aux="ARM64_FMOV_X_FROM_D" if vector[1] == "d" else "ARM64_FMOV_W_FROM_S")
    if op == "cnt":
        if ops not in [("v0.8b", "v0.8b"), ("v0.16b", "v0.16b")]:
            raise ValueError(f"unsupported CNT operands: {insn.raw}")
        return Encoded("ARM64_OP_CNT", aux="16" if ops[0] == "v0.16b" else "8")
    if op == "uaddlv":
        if ops not in [("h0", "v0.8b"), ("h0", "v0.16b")]:
            raise ValueError(f"unsupported UADDLV operands: {insn.raw}")
        return Encoded("ARM64_OP_UADDLV", aux="16" if ops[1] == "v0.16b" else "8")
    raise ValueError(f"unsupported arm64 instruction: {insn.raw}")


def label(addr: int) -> str:
    return f"arm64_l_{addr:x}"


def target_register(reg: str) -> int | None:
    match = re.fullmatch(r"[xw]([0-9]|[12][0-9]|30)", reg)
    return int(match.group(1)) if match else None


def indirect_targets(insns: list[NativeInsn]) -> dict[int, frozenset[tuple[str, int]]]:
    """Finite reaching constants, joined over the native CFG, never last-seen guesses.

    This is specialization analysis, not an executable ISA reference. Unknown
    values stay unknown; every emitted dispatch also checks the actual value.
    Code pointers are offsets in the same local code space as call/ret labels.
    """
    by_addr = {i.addr: i for i in insns}
    next_addr = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    # An adjacent CMP fact is usable only if every edge executes that CMP.
    entries = {branch_target(i.operands[-1]) for i in insns
               if i.mnemonic in {"b", "cbz", "cbnz", "tbz", "tbnz"}
               or i.mnemonic.startswith("b.")}
    entries |= {branch_target(i.operands[1]) for i in insns if i.mnemonic == "adr"}
    entries |= {branch_target(i.operands[0]) for i in insns
                if i.mnemonic == "bl" and not i.reloc_symbol}
    entries |= {next_addr[i.addr] for i in insns if i.mnemonic in {"bl", "blr"}}
    states = {insns[0].addr: (None,) * 31}
    queue = deque([insns[0].addr])
    # Scalars come only from literal definitions; arithmetic is not guessed.
    def read(state, reg):
        index = target_register(reg)
        if reg in {"xzr", "wzr"}:
            return frozenset({("scalar", 0)})
        return state[index] if index is not None else None

    def joined(left, right):
        return None if left is None or right is None else left | right

    def push(addr, state):
        if addr not in by_addr:
            raise ValueError(f"branch target 0x{addr:x} is outside the linked program")
        old = states.get(addr)
        merged = state if old is None else tuple(joined(a, b) for a, b in zip(old, state))
        if old != merged:
            states[addr] = merged
            queue.append(addr)

    while queue:
        addr = queue.popleft()
        insn = by_addr[addr]
        op, args = insn.mnemonic, insn.operands
        incoming = states[addr]
        outgoing = list(incoming)
        if op in GPR_WRITE_OPS or op == "adr":
            written = [args[0]]
            if op == "ldp":
                written.append(args[1])
            for reg in written:
                index = target_register(reg)
                if index is not None:
                    outgoing[index] = None
        if op == "mov":
            index = target_register(args[0])
            if index is not None:
                if args[1].startswith("#"):
                    value = parse_shifted_imm(args, 1) & ((1 << (reg_width(args[0]) * 8)) - 1)
                    outgoing[index] = frozenset({("scalar", value)})
                else:
                    values = read(incoming, args[1])
                    if reg_width(args[0]) == 8:
                        outgoing[index] = values
                    elif values is not None and all(k == "scalar" for k, v in values):
                        outgoing[index] = frozenset((k, v & 0xffffffff) for k, v in values)
        elif op == "adr":
            index = target_register(args[0])
            if index is not None:
                outgoing[index] = frozenset({("code", branch_target(args[1]))})
        elif op == "csel" and reg_width(args[0]) == 8:
            index = target_register(args[0])
            if index is not None:
                outgoing[index] = joined(read(incoming, args[1]), read(incoming, args[2]))
        # Pre/post-index loads and stores also write their address register.
        for position, arg in enumerate(args):
            if arg.startswith("[") and (arg.endswith("!") or position + 1 < len(args)):
                base = split_operands(arg.removeprefix("[").split("]", 1)[0])[0]
                index = target_register(base)
                if index is not None:
                    outgoing[index] = None
        if op in {"bl", "blr"}:
            # AAPCS caller-saved registers cannot retain an old helper ID.
            outgoing[:19] = [None] * 19
            outgoing[30] = None
            if op == "bl" and not insn.reloc_symbol:
                callee = list(incoming)
                callee[30] = frozenset({("code", next_addr[addr])})
                push(branch_target(args[0]), tuple(callee))
        if op == "b":
            push(branch_target(args[0]), tuple(outgoing))
        elif op.startswith("b.") or op in {"cbz", "cbnz", "tbz", "tbnz"}:
            taken, fallthrough = tuple(outgoing), tuple(outgoing)
            previous = by_addr.get(addr - 4)
            # This fact comes from the actual hardware CMP/branch pair. In
            # particular, Cilium reuses a map value proven ==1 as helper ID1.
            if (op in {'b.eq', 'b.ne'} and addr not in entries and previous is not None
                    and previous.mnemonic == 'cmp' and reg_width(previous.operands[0]) == 8
                    and previous.operands[1].startswith('#')):
                index = target_register(previous.operands[0])
                if index is not None:
                    equal = list(outgoing)
                    equal[index] = frozenset({('scalar', parse_shifted_imm(previous.operands, 1))})
                    if op == 'b.eq':
                        taken = tuple(equal)
                    else:
                        fallthrough = tuple(equal)
            push(branch_target(args[-1]), taken)
            if addr in next_addr:
                push(next_addr[addr], fallthrough)
        elif op in {"br", "blr"}:
            values = read(incoming, args[0])
            if values is not None:
                for kind, target in values:
                    if kind == "code":
                        callee = list(incoming)
                        if op == "blr":
                            callee[30] = frozenset({("code", next_addr[addr])})
                        push(target, tuple(callee))
            if op == "blr" and addr in next_addr:
                push(next_addr[addr], tuple(outgoing))
        elif op != "ret" and addr in next_addr:
            push(next_addr[addr], tuple(outgoing))

    targets = {}
    for insn in insns:
        if insn.mnemonic not in {"br", "blr"}:
            continue
        if insn.addr not in states:
            # The instructions remain emitted; LLVM removes unreachable labels.
            continue
        values = read(states[insn.addr], insn.operands[0])
        if values is None:
            raise ValueError(f"unbounded indirect target at 0x{insn.addr:x}: {insn.raw}")
        for kind, target in values:
            if kind == "code" and target in by_addr:
                continue
            if kind == "scalar" and target in HELPER_IDENTS:
                continue
            raise ValueError(f"invalid indirect target {kind}:0x{target:x} at 0x{insn.addr:x}")
        targets[insn.addr] = values
    return targets


def return_targets(insns, indirect):
    """Call-site continuations reaching each return, excluding callee CFGs.

    Each emitted return still tests actual LR. This removes impossible
    cross-subroutine edges from the global return ladder, not value checks.
    """
    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    callers = {insns[0].addr: set()}
    for i in insns:
        targets = ({branch_target(i.operands[0])} if i.mnemonic == 'bl' and not i.reloc_symbol
                   else {v for k, v in indirect.get(i.addr, ()) if k == 'code'}
                   if i.mnemonic == 'blr' else set())
        for target in targets:
            callers.setdefault(target, set()).add(following[i.addr])
    returns = {i.addr: set() for i in insns if i.mnemonic in {'ret', 'br'}}
    for entry, continuations in callers.items():
        pending, seen = [entry], set()
        while pending:
            addr = pending.pop()
            if addr in seen:
                continue
            seen.add(addr)
            i = by_addr[addr]
            op = i.mnemonic
            if op in {'ret', 'br'}:
                returns.setdefault(addr, set()).update(continuations)
            if op == 'ret':
                continue
            if op == 'br':
                pending.extend(v for k, v in indirect.get(addr, ()) if k == 'code')
                continue
            if op == 'b' or op.startswith('b.') or op in {'cbz', 'cbnz', 'tbz', 'tbnz'}:
                pending.append(branch_target(i.operands[-1]))
            if op != 'b' and addr in following:
                pending.append(following[addr])
    return returns


def append_indirect(lines, insn, targets, next_addr):
    register = reg_const(insn.operands[0])
    lines.extend(["\t{", f"\t\t__u64 __a64_target = ARM64_SIM_L_READ_REG({register});",
                  f"\t\tif (ARM64_SIM_L_REG_TAG({register}) == ARM64_SIM_TAG_CODE) {{",
                  "\t\t\tswitch (__a64_target) {"])
    for kind, target in sorted(targets):
        if kind == "code":
            action = (f"ARM64_SIM_A64_CALL({label(target)}, 0x{next_addr:x}ULL);"
                      if insn.mnemonic == "blr" else f"goto {label(target)};")
            lines.append(f"\t\t\tcase 0x{target:x}ULL: {action} break;")
    lines.extend(["\t\t\tdefault: ARM64_SIM_L_REJECT_PC(); break;", "\t\t\t}",
                  "\t\t} else {", "\t\t\tswitch (__a64_target) {"])
    for kind, target in sorted(targets):
        if kind == "scalar":
            link = f"ARM64_SIM_A64_LINK(0x{next_addr:x}ULL); " if insn.mnemonic == "blr" else ""
            tail = " ARM64_SIM_A64_RET();" if insn.mnemonic == "br" else ""
            lines.append(f"\t\t\tcase {target}ULL: {link}ARM64_SIM_BPF_CALL_{HELPER_IDENTS[target]}();{tail} break;")
    lines.extend(["\t\t\tdefault: ARM64_SIM_L_REJECT_PC(); break;", "\t\t\t}", "\t\t}", "\t}"])


def append_insn(lines: list[str], insn: NativeInsn, all_addrs: set[int],
                next_addr: int | None,
                targets: frozenset[tuple[str, int]] | None,
                rodata_idents: dict[str, str],
                reloc_idents: dict[str, str]) -> None:
    lines.append(f"\t/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
    op = insn.mnemonic
    if insn.source_pointer is not None and op == "ldr":
        mem = parse_mem(insn.operands, 1)
        if reg_width(insn.operands[0]) != 8 or mem.index != "ARM64_REG_NONE" or mem.offset or mem.flags or insn.reloc_addend:
            raise ValueError(f"source-map GOT load must retain its exact base: {insn.raw}")
        value, _ = insn.source_pointer
        tag = "ARM64_SIM_TAG_MAP_VALUE" if value else "ARM64_SIM_TAG_MAP_PTR"
        lines.append(f"\tARM64_SIM_L_WRITE_REG_PTR_TAG({reg_const(insn.operands[0])}, ARM64_SIM_L_READ_REG_PTR({mem.base}), {tag});")
        return
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
        if insn.operands[0].lower().startswith("w"):
            macro += "_W"
        lines.append(f"\t{macro}({reg_const(insn.operands[0])}, 0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op in {"tbz", "tbnz"}:
        target = branch_target(insn.operands[2])
        macro = "ARM64_SIM_A64_TBZ" if op == "tbz" else "ARM64_SIM_A64_TBNZ"
        lines.append(f"\t{macro}({reg_const(insn.operands[0])}, {parse_imm(insn.operands[1])}, 0x{insn.addr:x}, 0x{target:x}, {label(target)});")
        return
    if op == "bl":
        if insn.reloc_symbol in {"memcpy", "memset"}:
            lines.append(f"\tARM64_SIM_A64_LINK(0x{next_addr:x}ULL);")
            lines.append(f"\tARM64_SIM_LIBC_{insn.reloc_symbol.upper()}();")
            return
        if is_helper_symbol(insn.reloc_symbol):
            lines.append(f"\tARM64_SIM_A64_LINK(0x{next_addr:x}ULL);")
            lines.append(f"\tARM64_SIM_BPF_CALL_{insn.reloc_symbol}();")
            return
        target = branch_target(insn.operands[0])
        if target not in all_addrs or next_addr is None:
            raise ValueError(f"unsupported call target in {insn.raw}")
        lines.append(f"\tARM64_SIM_A64_CALL({label(target)}, 0x{next_addr:x}ULL);")
        return
    if op == "adr":
        lines.append(f"\tARM64_SIM_A64_ADR({reg_const(insn.operands[0])}, 0x{branch_target(insn.operands[1]):x}ULL);")
        return
    if op in {"br", "blr"}:
        append_indirect(lines, insn, targets or frozenset(), next_addr)
        return
    if op == "ret":
        register = reg_const(insn.operands[0]) if insn.operands else "ARM64_X30"
        lines.append(f"\tARM64_SIM_A64_RET_TO({register}, ARM64_SIM_RET_CASES_{insn.addr:x});")
        return
    enc = encode(insn, rodata_idents, reloc_idents)
    lines.append(
        f"\tARM64_SIM_RUN_KNOWN_OP3({enc.op}, {enc.dst}, {enc.src}, {enc.src2}, {enc.src3}, "
        f"{enc.width}, {enc.aux}, {enc.imm});"
    )


def render_program(name: str, symbol: str, functions: OrderedDict[str, list[NativeInsn]],
                   kind: str, prelude: str = "",
                   rodata16: dict[str, bytes | tuple[int, int]] | None = None,
                   linked_exit: bool = False, program_section: str | None = None,
                   original_source: Path | None = None,
                   original_symbols: set[str] | None = None,
                   source_map_bindings: list[dict] | None = None,
                   trusted_map_bindings: list[dict] | None = None) -> str:
    if (original_source is None) != (original_symbols is None):
        raise ValueError("original source and ELF-defined symbol set must be supplied together")
    rodata16 = {symbol: value for symbol, value in (rodata16 or {}).items()
                if original_symbols is None or symbol not in original_symbols}
    trusted_map_bindings = trusted_map_bindings or []
    trusted_names = set()
    if trusted_map_bindings:
        from trusted_generation import elf_symbol, c_symbol_aliases
    for binding in trusted_map_bindings:
        if set(binding) != {"native_symbol", "value_offset"}:
            raise ValueError("trusted map binding requires native_symbol/value_offset")
        symbol, offset = binding["native_symbol"], binding["value_offset"]
        if elf_symbol(symbol) in trusted_names:
            raise ValueError("invalid/duplicate trusted native map symbol")
        if offset is not None and (type(offset) is not int or not 0 <= offset <= 0xffffffff):
            raise ValueError("trusted map value offset must be null or u32")
        trusted_names.add(symbol)
    trusted_idents = c_symbol_aliases([b["native_symbol"] for b in trusted_map_bindings], "__arm64_trusted_map_") if trusted_map_bindings else {}
    rodata16 = {symbol: value for symbol, value in rodata16.items() if symbol not in trusted_names}
    source_map_bindings = source_map_bindings or []
    source_pointers = {}
    for binding in trusted_map_bindings:
        symbol, offset = binding["native_symbol"], binding["value_offset"]
        # The extern already denotes the native symbol's bound address,
        # including any capsule direct-value base. Do not add that base twice.
        source_pointers[symbol] = (offset is not None, trusted_idents[symbol])
    proof_symbols = set()
    for binding in source_map_bindings:
        if set(binding) != {"native_symbol", "source_insn", "proof_symbol", "kind", "value_offset"}:
            raise ValueError("source-map binding fields must be explicit")
        native, proof = binding["native_symbol"], binding["proof_symbol"]
        if any(not isinstance(item, str) or re.fullmatch(r"[A-Za-z_]\w*", item) is None for item in (native, proof)):
            raise ValueError("source-map symbols must be C identifiers")
        if native in source_pointers or proof in proof_symbols or type(binding["kind"]) is not int or binding["kind"] not in {1, 2}:
            raise ValueError("duplicate source-map symbol or invalid source kind")
        if type(binding["source_insn"]) is not int or binding["source_insn"] < 0:
            raise ValueError("source-map instruction index must be nonnegative")
        offset = binding["value_offset"]
        if type(offset) is not int or not 0 <= offset <= 0xffffffff or (binding["kind"] == 1 and offset):
            raise ValueError("source-map value offset is invalid")
        source_pointers[native] = (binding["kind"] == 2, f"({proof} + {offset}ULL)")
        proof_symbols.add(proof)
    functions = OrderedDict((fn, [replace(insn, source_pointer=source_pointers[insn.reloc_symbol])
        if insn.reloc_symbol in source_pointers else insn for insn in body]) for fn, body in functions.items())
    all_insns = [insn for fn in functions.values() for insn in fn]
    referenced = {insn.reloc_symbol for insn in all_insns}
    if {binding["native_symbol"] for binding in source_map_bindings} - referenced:
        raise ValueError("source-map binding has no native address relocation")
    if any(insn.source_pointer is not None and insn.mnemonic not in {"adrp", "ldr"} for insn in all_insns):
        raise ValueError("source-map binding requires an explicit GOT address/load pair")
    all_addrs = {insn.addr for insn in all_insns}
    next_by_addr = {
        insns[index].addr: insns[index + 1].addr
        for insns in functions.values()
        for index in range(len(insns) - 1)
    }
    targets_by_addr = indirect_targets(all_insns)
    stack_min, stack_max = check_definedness(all_insns, targets_by_addr, linked_exit, sys.modules[__name__])
    returns_by_addr = return_targets(all_insns, targets_by_addr)
    return_addrs = sorted(next_by_addr[insn.addr] for insn in all_insns
                          if insn.mnemonic in {"bl", "blr"})
    return_addrs = sorted(set(return_addrs) |
                         {branch_target(i.operands[1]) for i in all_insns if i.mnemonic == "adr"} |
                         {v for values in targets_by_addr.values() for k, v in values if k == "code"})
    uses_stack = bool(return_addrs) or any("[sp" in insn.raw.lower() for insn in all_insns)
    if kind == "raw":
        if not program_section:
            raise ValueError("raw context requires its real BPF program section")
        section, ctx, entry = f'SEC({json.dumps(program_section)})', 'void *', 'ARM64_SIM_ENTRY_RAW(ctx);'
    else:
        section, ctx, entry = {
            "xdp": ('SEC("xdp")', "struct xdp_md *", "ARM64_SIM_ENTRY_XDP(ctx);"),
            "tc": ('SEC("tc")', "struct __sk_buff *", "ARM64_SIM_ENTRY_SKB(ctx);"),
            "cgroup_skb": ('SEC("cgroup_skb/egress")', "struct __sk_buff *", "ARM64_SIM_ENTRY_SKB(ctx);"),
        }[kind]
    lines: list[str] = []
    for addr, targets in sorted(returns_by_addr.items()):
        cases = ' '.join(f'case 0x{target:x}ULL: goto {label(target)};' for target in sorted(targets))
        lines.append(f'#define ARM64_SIM_RET_CASES_{addr:x} {cases}')
    if uses_stack:
        stack_bias = ((-min(0, stack_min) + 7) // 8) * 8
        stack_bytes = max(8, ((stack_bias + max(0, stack_max) + 7) // 8) * 8)
        lines.extend(["#define ARM64_SIM_ENABLE_STACK 1",
                      f"#define ARM64_SIM_STACK_BIAS {stack_bias}LL",
                      f"#define ARM64_SIM_STACK_BYTES {stack_bytes}U"])
    if return_addrs:
        lines.append("#define ARM64_SIM_RETURN_CASES \\")
        for idx, addr in enumerate(return_addrs):
            tail = " \\" if idx + 1 < len(return_addrs) else ""
            lines.append(f"\tcase 0x{addr:x}ULL: goto {label(addr)};{tail}")
    if original_source is not None:
        lines.extend(['#define LICENSE __arm64_original_license',
                      f'#include {json.dumps(str(original_source.resolve()))}',
                      '#undef LICENSE'])
    lines.extend([
        '#include "../arm64_sim_local_bpf.h"',
        "",
    ])
    if prelude:
        lines.append(prelude.rstrip())
        lines.append("")
    for symbol in sorted(trusted_names & referenced):
        ident = trusted_idents[symbol]
        alias = '' if ident == symbol else ' __asm__(' + json.dumps(symbol) + ')'
        lines.append(f'extern __u8 {ident}[]{alias} __ksym;')
    if source_map_bindings:
        for binding in source_map_bindings:
            lines.append(f'extern __u8 {binding["proof_symbol"]}[] __ksym;')
        objects = [{key: binding[key] for key in ("native_symbol", "source_insn", "proof_symbol")}
                   for binding in source_map_bindings]
        metadata = json.dumps(dict(version=1, objects=objects), separators=(",", ":"))
        lines.append('static const char __arm64_source_map_metadata[] SEC(".native_lab.source_maps") = ' + json.dumps(metadata) + ';')
    rodata_idents = rodata_ident_map(rodata16)
    rodata_objects = []
    for index, (symbol, ident) in enumerate(rodata_idents.items()):
        value = rodata16[symbol]
        if not isinstance(value, bytes):
            lo, hi = value
            value = lo.to_bytes(8, "little") + hi.to_bytes(8, "little")
        if not value:
            raise ValueError(f"empty native readonly extent: {symbol}")
        section_name = f".rodata.native.{index}"
        values = ", ".join(f"0x{byte:02x}" for byte in value)
        lines.append(f'static const __u8 {ident}[{len(value)}] SEC("{section_name}") __attribute__((aligned(16))) = {{{values}}};')
        rodata_objects.append(dict(proof_section=section_name, proof_symbol=ident,
                                   native_symbol=symbol, size=len(value)))
    if rodata_idents:
        metadata = json.dumps(dict(version=1, objects=rodata_objects), separators=(",", ":"))
        lines.append('static const char __arm64_rodata_metadata[] SEC(".native_lab.rodata") = '
                     + json.dumps(metadata) + ';')
        lines.append("")
    map_symbols = sorted({
        insn.reloc_symbol
        for insn in all_insns
        if insn.reloc_symbol
        and insn.reloc_symbol not in rodata_idents
        and not is_helper_symbol(insn.reloc_symbol)
        and insn.reloc_symbol not in {"memcpy", "memset"}
        and insn.reloc_symbol not in source_pointers
    })
    source_maps = set(original_symbols or ()) | set(re.findall(r'\b([A-Za-z_]\w*)\s+SEC\(\s*"\.maps"\s*\)', prelude))
    if set(map_symbols) - source_maps:
        raise ValueError(f"native relocation lacks an original map declaration: {sorted(set(map_symbols) - source_maps)}")
    reloc_idents = {symbol: symbol for symbol in map_symbols}
    lines.extend([
        section,
        f"int {name}_arm64_sim_xdp({ctx}ctx)",
        "{",
        f"\t{entry}",
    ])
    incoming = set(return_addrs)
    for insn in all_insns:
        if insn.mnemonic in {'b', 'bl', 'cbz', 'cbnz', 'tbz', 'tbnz'} or insn.mnemonic.startswith('b.'):
            if not insn.reloc_symbol:
                incoming.add(branch_target(insn.operands[-1]))
    for fn_symbol, insns in functions.items():
        if fn_symbol != symbol:
            lines.append(f"\t/* native subroutine {c_comment(fn_symbol)} */")
        fused = set()
        for index, insn in enumerate(insns):
            if insn.addr in fused:
                continue
            lines.append(f"{label(insn.addr)}:")
            if insn.mnemonic == 'cmp' and index + 1 < len(insns):
                branch = insns[index + 1]
                if branch.mnemonic == 'b.gt' and branch.addr not in incoming:
                    enc = encode(insn, rodata_idents, reloc_idents)
                    lines.extend([f'\t/* 0x{insn.addr:x}: {c_comment(insn.raw)}; '
                                  f'0x{branch.addr:x}: {c_comment(branch.raw)} */',
                                  f'{label(branch.addr)}:',
                                  f'\tARM64_SIM_A64_CMP_GT({enc.op}, {enc.dst}, {enc.src}, '
                                  f'{enc.width}, {enc.aux}, {enc.imm}, '
                                  f'{label(branch_target(branch.operands[0]))});'])
                    fused.add(branch.addr)
                    continue
            append_insn(lines, insn, all_addrs, next_by_addr.get(insn.addr),
                        targets_by_addr.get(insn.addr),
                        rodata_idents, reloc_idents)
    if linked_exit:
        lines.extend([
            "\tARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, ARM64_SIM_L_READ_REG(ARM64_X7), ARM64_WIDTH_64);",
            "\tARM64_SIM_RET();",
        ])
    else:
        lines.append("\treturn 0;")
    lines.extend(["}", "", "ARM64_SIM_LICENSE();", ""])
    return "\n".join(lines)


def generate_one(bench: Bench, source_dir: Path, output_dir: Path,
                 proof_object_dir: Path) -> Path:
    selected, rodata16 = parse_native_linked_program(bench, proof_object_dir)
    output = output_dir / f"{bench.name}.bpf.c"
    source = source_dir / f"{bench.name}.bpf.c"
    prelude = source_prelude(source) if source_dir == STAGE2_PROGRAMS else ""
    output.write_text(
        render_program(bench.name, bench.symbol, selected, bench.kind,
          prelude=prelude, rodata16=rodata16, linked_exit=True),
        encoding="utf-8",
    )
    return output


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--micro-programs", type=Path, default=MICRO_PROGRAMS)
    parser.add_argument("--output-dir", type=Path, default=OUT_DIR)
    parser.add_argument("--proof-object-dir", type=Path, default=PROOF_OBJECT_DIR)
    parser.add_argument("--config", type=Path, default=CONFIG)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark stem list")
    args = parser.parse_args()
    args.output_dir.mkdir(parents=True, exist_ok=True)
    source_dir = args.micro_programs
    if source_dir == MICRO_PROGRAMS and "stage2" in args.config.stem:
        source_dir = STAGE2_PROGRAMS
    only = set(args.only or [])
    written = [
        generate_one(bench, source_dir, args.output_dir, args.proof_object_dir)
        for bench in load_benches(args.config)
        if not only or bench.name in only
    ]
    for path in written:
        print(path)
    print(f"generated {len(written)} proof sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
