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
STAGE2_PROGRAMS = REPO_ROOT / "native-sim" / "test"
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
PROOF_OBJECT_DIR = OUT_DIR / "build" / "native-link"

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
HELPER_IDENTS = {
    1: "bpf_map_lookup_elem",
    2: "bpf_map_update_elem",
    3: "bpf_map_delete_elem",
    4: "bpf_probe_read",
    6: "bpf_trace_printk",
    8: "bpf_get_smp_processor_id",
    9: "bpf_skb_store_bytes",
    10: "bpf_l3_csum_replace",
    11: "bpf_l4_csum_replace",
    12: "bpf_tail_call",
    14: "bpf_get_current_pid_tgid",
    15: "bpf_get_current_uid_gid",
    16: "bpf_get_current_comm",
    21: "bpf_redirect",
    23: "bpf_clone_redirect",
    25: "bpf_perf_event_output",
    26: "bpf_skb_load_bytes",
    27: "bpf_get_stackid",
    28: "bpf_csum_diff",
    35: "bpf_get_current_task",
    37: "bpf_current_task_under_cgroup",
    38: "bpf_skb_under_cgroup",
    43: "bpf_skb_change_proto",
    44: "bpf_skb_change_type",
    45: "bpf_probe_read_str",
    50: "bpf_skb_adjust_room",
    67: "bpf_get_stack",
    68: "bpf_skb_load_bytes_relative",
    69: "bpf_fib_lookup",
    80: "bpf_get_current_cgroup_id",
    95: "bpf_sk_fullsock",
    112: "bpf_probe_read_user",
    113: "bpf_probe_read_kernel",
    114: "bpf_probe_read_user_str",
    115: "bpf_probe_read_kernel_str",
    125: "bpf_ktime_get_boot_ns",
    152: "bpf_redirect_neigh",
    158: "bpf_get_current_task_btf",
    175: "bpf_task_pt_regs",
}
GPR_WRITE_OPS = {
    "add", "sub", "and", "bic", "eor", "orr", "orn",
    "adds", "subs",
    "mov", "movk", "lsl", "lsr", "asr", "ror",
    "madd", "msub", "mul", "umull", "umulh", "umaddl", "smaddl", "udiv",
    "mvn", "neg", "cneg", "extr", "ubfx", "sbfx", "ubfiz", "bfxil", "bfi",
    "rev", "rev16", "sxtb", "sxth", "sxtw", "ldr", "ldur", "ldaxr", "ldxr", "ldrb", "ldurb", "ldrh", "ldurh",
    "ldrsb", "ldrsh", "ldrsw",
    "ldp", "stlxr", "stxr", "csel", "cinc", "cinv", "csinc", "csinv", "cset", "fmov",
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


def load_rodata16(obj: Path) -> dict[str, tuple[int, int]]:
    data = rodata_bytes(obj)
    if not data:
        return {}
    result = subprocess.run(["aarch64-linux-gnu-objdump", "-t", str(obj)],
                            cwd=REPO_ROOT, check=True, text=True,
                            stdout=subprocess.PIPE)
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
            symbol = re.sub(r"([+-]0x[0-9a-fA-F]+)$", "", reloc.group(1))
            insns[-1] = NativeInsn(
                insns[-1].addr,
                insns[-1].mnemonic,
                insns[-1].operands,
                insns[-1].raw,
                symbol,
            )
            continue
        m_insn = insn_re.match(line)
        if not m_insn:
            continue
        operands = m_insn.group(3).split("//", 1)[0].strip()
        asm = f"{m_insn.group(2)} {operands}".strip()
        addr = int(m_insn.group(1), 16)
        insns.append(NativeInsn(addr, m_insn.group(2), split_operands(operands), asm))
    return insns


def parse_native_linked_program(
    bench: Bench,
    proof_object_dir: Path,
) -> tuple[OrderedDict[str, list[NativeInsn]], dict[str, tuple[int, int]]]:
    symbol = bench.symbol
    proof_obj = proof_object_dir / f"{bench.name}.proof.o"
    if not proof_obj.is_file():
        raise RuntimeError(f"missing proof object for {bench.name}: {proof_obj}")
    rodata16 = load_rodata16(proof_obj)
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
    return bool(symbol and symbol.startswith("bpf_"))


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


def rodata_ident_map(rodata16: dict[str, tuple[int, int]]) -> dict[str, str]:
    return {symbol: f"__arm64_rodata_{index}" for index, symbol in enumerate(rodata16)}


def c_ident(prefix: str, value: str, index: int) -> str:
    ident = re.sub(r"[^A-Za-z0-9_]", "_", value)
    ident = re.sub(r"_+", "_", ident).strip("_")
    if not ident or ident[0].isdigit():
        ident = f"{prefix}_{ident}"
    return f"{ident}_{index}"


def encode(insn: NativeInsn, rodata_idents: dict[str, str], reloc_idents: dict[str, str]) -> Encoded:
    op = insn.mnemonic
    ops = insn.operands
    if op == "nop":
        return Encoded("ARM64_OP_NOP")
    if op == "adrp":
        if not insn.reloc_symbol:
            raise ValueError(f"unsupported adrp without relocation: {insn.raw}")
        if insn.reloc_symbol in rodata_idents:
            return Encoded(
                "ARM64_OP_ADRP_RODATA",
                reg_const(ops[0]),
                imm=c_ptr_u64(rodata_idents[insn.reloc_symbol]),
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
        return Encoded("ARM64_OP_MVN" if op == "mvn" else "ARM64_OP_NEG",
                       reg_const(ops[0]), reg_const(ops[1]), width=width_const(reg_width(ops[0])))
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
    if op in {"str", "stur", "strb", "strh", "sturh"}:
        width = 1 if op == "strb" else 2 if op in {"strh", "sturh"} else reg_width(ops[0])
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
                       width=width_const(width), aux=mem_aux(mem))
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
    if op in {"csel", "cinc", "cset"}:
        if op == "cset":
            return Encoded("ARM64_OP_CSET", reg_const(ops[0]), width=width_const(reg_width(ops[0])), aux=COND[ops[1]])
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


def blr_target_reg(insn: NativeInsn) -> str | None:
    if insn.mnemonic != "blr" or len(insn.operands) != 1:
        return None
    target = insn.operands[0]
    if not re.fullmatch(r"x([0-9]+)", target):
        return None
    return target[1:]


def written_gpr(insn: NativeInsn) -> str | None:
    if insn.mnemonic not in GPR_WRITE_OPS:
        return None
    if not insn.operands:
        return None
    dst = insn.operands[0]
    if re.fullmatch(r"[wx]([0-9]+)", dst):
        return dst[1:]
    return None


def mov_immediate(insn: NativeInsn) -> int | None:
    if insn.mnemonic != "mov" or len(insn.operands) != 2:
        return None
    if not insn.operands[1].startswith("#"):
        return None
    try:
        return parse_imm(insn.operands[1])
    except ValueError:
        return None


def mov_source_gpr(insn: NativeInsn) -> str | None:
    if insn.mnemonic != "mov" or len(insn.operands) != 2:
        return None
    src = insn.operands[1]
    if re.fullmatch(r"[wx]([0-9]+)", src):
        return src[1:]
    return None


def helper_calls_by_addr(insns: list[NativeInsn]) -> dict[int, str]:
    reg_imms: dict[str, int] = {}
    last_helper_imms: dict[str, int] = {}
    helpers: dict[int, str] = {}
    for insn in insns:
        target = blr_target_reg(insn)
        if target is not None:
            helper = HELPER_IDENTS.get(reg_imms.get(target, -1))
            if helper is None:
                helper = HELPER_IDENTS.get(last_helper_imms.get(target, -1))
            if helper is not None:
                helpers[insn.addr] = helper

        dst = written_gpr(insn)
        if dst is None:
            continue
        imm = mov_immediate(insn)
        if imm is not None:
            reg_imms[dst] = imm
            if imm in HELPER_IDENTS:
                last_helper_imms[dst] = imm
            continue
        src = mov_source_gpr(insn)
        if src is not None and src in reg_imms:
            reg_imms[dst] = reg_imms[src]
            if reg_imms[src] in HELPER_IDENTS:
                last_helper_imms[dst] = reg_imms[src]
            continue
        reg_imms.pop(dst, None)
    return helpers


def append_insn(lines: list[str], insn: NativeInsn, all_addrs: set[int],
                next_addr: int | None,
                helper_call: str | None,
                rodata_idents: dict[str, str],
                reloc_idents: dict[str, str]) -> None:
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
        if is_helper_symbol(insn.reloc_symbol):
            lines.append(f"\tARM64_SIM_BPF_CALL_{insn.reloc_symbol}();")
            return
        target = branch_target(insn.operands[0])
        if target not in all_addrs or next_addr is None:
            raise ValueError(f"unsupported call target in {insn.raw}")
        lines.append(f"\tARM64_SIM_A64_CALL({label(target)}, 0x{next_addr:x}ULL);")
        return
    if op == "blr":
        if helper_call is not None:
            lines.append(f"\tARM64_SIM_BPF_CALL_{helper_call}();")
            return
    if op == "ret":
        lines.append("\tARM64_SIM_A64_RET();")
        return
    enc = encode(insn, rodata_idents, reloc_idents)
    lines.append(
        f"\tARM64_SIM_RUN_OP3({enc.op}, {enc.dst}, {enc.src}, {enc.src2}, {enc.src3}, "
        f"{enc.width}, {enc.aux}, {enc.imm});"
    )


def render_program(name: str, symbol: str, functions: OrderedDict[str, list[NativeInsn]],
                   kind: str, prelude: str = "",
                   rodata16: dict[str, tuple[int, int]] | None = None,
                   linked_exit: bool = False) -> str:
    rodata16 = rodata16 or {}
    all_insns = [insn for fn in functions.values() for insn in fn]
    all_addrs = {insn.addr for insn in all_insns}
    next_by_addr = {
        insns[index].addr: insns[index + 1].addr
        for insns in functions.values()
        for index in range(len(insns) - 1)
    }
    helper_by_addr = {
        addr: helper
        for insns in functions.values()
        for addr, helper in helper_calls_by_addr(insns).items()
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
    ])
    if prelude:
        lines.append(prelude.rstrip())
        lines.append("")
    rodata_idents = rodata_ident_map(rodata16)
    for symbol, ident in rodata_idents.items():
        lo, hi = rodata16[symbol]
        lines.append(f"static const __u64 {ident}[2] = {{{c_u64(lo)}, {c_u64(hi)}}};")
    if rodata_idents:
        lines.append("")
    map_symbols = sorted({
        insn.reloc_symbol
        for insn in all_insns
        if insn.reloc_symbol
        and insn.reloc_symbol not in rodata_idents
        and not is_helper_symbol(insn.reloc_symbol)
    })
    reloc_idents = {
        symbol: c_ident("__arm64_reloc", symbol, index)
        for index, symbol in enumerate(map_symbols)
    }
    for map_symbol in map_symbols:
        map_ident = reloc_idents[map_symbol]
        lines.extend([
            "struct {",
            "\t__uint(type, BPF_MAP_TYPE_ARRAY);",
            "\t__uint(max_entries, 1);",
            "\t__type(key, __u32);",
            "\t__type(value, __u64);",
            f"}} {map_ident} SEC(\".maps\");",
            "",
        ])
    lines.extend([
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
            append_insn(lines, insn, all_addrs, next_by_addr.get(insn.addr),
                        helper_by_addr.get(insn.addr),
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


def generate_one(bench: Bench, source_dir: Path, output_dir: Path, proof_object_dir: Path) -> Path:
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
