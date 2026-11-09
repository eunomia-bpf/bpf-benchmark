#!/usr/bin/env python3
"""Generate hardcoded x86-simulator verifier artifacts from micro Native ASM blocks."""

from __future__ import annotations

import argparse
import json
from collections import deque
import re
import subprocess
import sys
from dataclasses import replace
from dataclasses import dataclass
from pathlib import Path

import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from helper_abi import helper_idents, is_helper_symbol

from x86_abi import check_definedness

from generated_x86_alu_decode import ALU_AUX
from generated_x86_full_condition import CC_AUX
from generated_x86_opcode import X86_OPCODE, X86_OPCODE_NAME
from generated_x86_reg_lane_aux import c_reg_lane_aux
from generated_x86_specialization import (X86_SPECIALIZATION_AUX_CALL,
                                         X86_SPECIALIZATION_DIRECT_CALL)


REPO_ROOT = Path(__file__).resolve().parents[3]
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
STAGE2_PROGRAMS = REPO_ROOT / "kprog" / "test"
OUT_DIR = Path(__file__).resolve().parent
CONFIG = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
PROOF_OBJECT_DIR = OUT_DIR / "build" / "native-link"
MAX_REP_MOVS_COUNT = 64

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
    end_addr: int | None = None
    stack_width: int | None = None
    reloc_type: str | None = None
    symbol_offset: int = 0
    source_pointer: tuple[bool, str] | None = None


@dataclass(frozen=True)
class EncodedInsn:
    op: str
    dst: str
    src: str
    flags: str
    aux: str
    imm: str


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
    pending_prefix: tuple[int, list[int]] | None = None
    for line in text.splitlines():
        reloc = re.search(r"([0-9a-fA-F]+):\s+(R_X86_64_[A-Z0-9_]+)\s+(\S+)", line)
        if reloc is not None and insns:
            target = re.fullmatch(r"(.*?)([+-]0x[0-9a-fA-F]+)?", reloc.group(3))
            symbol, addend = target.groups()
            if insns[-1].end_addr is None:
                raise ValueError("relocation lacks its native instruction extent")
            offset = int(addend, 16) if addend else 0
            offset += insns[-1].end_addr-int(reloc.group(1),16)
            insns[-1] = replace(insns[-1], reloc_symbol=symbol,
                                reloc_type=reloc.group(2), symbol_offset=offset)
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
        addr = int(addr_text, 16)
        octets = [int(byte, 16) for byte in fields[1].split()]
        end_addr = addr + len(octets)
        # Objdump prints an inactive REX before a legacy prefix separately,
        # although the CPU consumes both prefixes as one instruction.
        if pending_prefix is not None:
            start, previous = pending_prefix
            if start + len(previous) != addr:
                raise ValueError(f"discontinuous x86 prefix at 0x{start:x}")
            addr, octets = start, previous + octets
            pending_prefix = None
        if re.fullmatch(r"rex(?:\.[WRXB]+)?", asm):
            pending_prefix = (addr, octets)
            continue
        asm = re.sub(r"^(?:(?:data16|rex(?:\.[WRXB]+)?)\s+)+", "", asm)
        if asm.startswith("lock "):
            asm = asm.removeprefix("lock ").strip()
        match = re.match(r"(?P<mnemonic>[a-z][a-z0-9]*)\s*(?P<operands>.*)$", asm)
        if match is None:
            continue
        mnemonic = match.group("mnemonic")
        stack_width = 16 if mnemonic in {"pushw", "popw"} else None
        if stack_width: mnemonic = mnemonic[:-1]
        if mnemonic in {"push", "pop"}:
            operand16, rex = False, 0
            for byte in octets:
                if byte in {0x66, 0x67, 0xf0, 0xf2, 0xf3, 0x2e, 0x36, 0x3e, 0x26, 0x64, 0x65}:
                    operand16 |= byte == 0x66
                    rex = 0
                elif 0x40 <= byte <= 0x4f:
                    rex = byte
                else:
                    break
            stack_width = 64 if rex & 8 or not operand16 else 16
        insns.append(NativeInsn(addr, asm, mnemonic,
                                split_operands(match.group("operands")),
                                end_addr=end_addr,
                                stack_width=stack_width))
    if pending_prefix is not None:
        raise ValueError(f"incomplete x86 prefix at 0x{pending_prefix[0]:x}")
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
    # Read binary bytes; objdump's ASCII column can itself look hexadecimal.
    from elftools.elf.elffile import ELFFile
    with obj.open("rb") as stream:
        section = ELFFile(stream).get_section_by_name(".native_link_rodata")
        return section.data() if section is not None else b""


def load_rodata_blobs(obj: Path) -> dict[str, bytes]:
    from elftools.elf.elffile import ELFFile
    data = rodata_bytes(obj)
    if not data:
        return {}
    with obj.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        if symbols is None:
            raise ValueError("native readonly section lacks its symbol table")
        index = elf.get_section_index(".native_link_rodata")
        out: dict[str, bytes] = {}
        for symbol in symbols.iter_symbols():
            if symbol["st_shndx"] != index or symbol["st_info"]["type"] != "STT_OBJECT":
                continue
            offset, size, name = symbol["st_value"], symbol["st_size"], symbol.name
            if size <= 0 or offset + size > len(data):
                raise ValueError(f"native readonly extent exceeds its section: {name} offset={offset} size={size}")
            out[name] = data[offset:offset + size]
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
    rodata16 = load_rodata_blobs(proof_obj)
    disasm = subprocess.run(
        ["objdump", "-dr", "--insn-width=16", "-Mintel", str(proof_obj)], cwd=REPO_ROOT, check=True, text=True,
        stdout=subprocess.PIPE)
    symbols = text_symbol_addrs(proof_obj)
    insns = [
        replace(insn, reloc_target=symbols[insn.reloc_symbol]+insn.symbol_offset)
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
    # Address-taken functions may be reached only through an indirect CALL.
    sub_starts = sorted(set(sub_starts) | {
        addr for addr in text_symbol_addrs(proof_object_dir / f"{name}.proof.o").values()
        if addr in insn_addrs and addr != entry_addr
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
        # GNU objdump spells SIB no-base absolute operands as ds:0x...,
        # including LEA, even when the source assembly used [disp32].
        absolute = operand.rsplit(":", 1)[-1].strip()
        if is_int(absolute):
            return "X86_REG_NONE", "X86_REG_NONE", 0, parse_int(absolute)
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
    return re.match(r"(0x[0-9a-fA-F]+|[0-9a-fA-F]+)\b", operand.strip()) is not None


def enc(op: str, dst: str = "X86_REG_NONE", src: str = "X86_REG_NONE",
        flags: str = "X86_WIDTH_64", aux: str = "0", imm: str = "0") -> EncodedInsn:
    # Every opcode an artifact step carries is resolved through the generated
    # x86 opcode contract, so a token the simulator does not define, or a
    # canonical name the contract does not know, fails generation here instead
    # of emitting a step the simulator cannot dispatch.
    name = X86_OPCODE_NAME.get(op, op)
    define = X86_OPCODE.get(name)
    if define is None:
        raise SystemExit(f"unknown x86 opcode: {op}")
    return EncodedInsn(define, dst, src, flags, aux, imm)


def is_indirect_branch(insn: NativeInsn) -> bool:
    return (insn.mnemonic in {"jmp", "call"} and bool(insn.operands) and
            not has_direct_branch_target(insn.operands[0]) and
            not is_helper_symbol(insn.reloc_symbol) and
            insn.reloc_symbol not in {"memcpy", "memset"})


def rodata_ident_map(rodata16: dict[str, tuple[int, int]]) -> dict[str, str]:
    return {symbol: f"__x86_rodata_{index}" for index, symbol in enumerate(rodata16)}


def relocated_data_address(insn: NativeInsn, rodata_idents: dict[str,str]) -> str:
    if not insn.reloc_symbol:
        raise ValueError(f"missing native data relocation: {insn.raw}")
    base = rodata_idents.get(insn.reloc_symbol, f"&{insn.reloc_symbol}")
    return c_ptr_u64(f"((__u8 *)({base}) + ({insn.symbol_offset}))")


def encode(insn: NativeInsn, rodata_idents: dict[str, str]) -> EncodedInsn:
    op = insn.mnemonic
    ops = insn.operands
    if insn.source_pointer is not None:
        is_value, expression = insn.source_pointer
        dst = reg_info(ops[0]) if ops else None
        address_form = (op == "lea" and insn.reloc_type == "R_X86_64_PC32") or (
            op == "mov" and insn.reloc_type and "GOTPCREL" in insn.reloc_type)
        if not address_form or dst is None or dst[1] != 64 or insn.symbol_offset:
            raise ValueError(f"source-map address needs a zero-offset 64-bit LEA/GOT load: {insn.raw}")
        return enc("X86_OP_MOV_LOAD_MAP_PTR", dst=dst[0],
                   aux="X86_MAP_PTR_AUX_VALUE" if is_value else "0",
                   imm=c_ptr_u64(expression))
    if insn.reloc_type=="R_X86_64_PC32" and op not in {
        "mov","movabs","movzx","movsx","movsxd","lea","popcnt","div"
    }:
        raise ValueError(f"unresolved PC-relative data instruction: {insn.raw}")
    if insn.reloc_type and "GOTPCREL" in insn.reloc_type and insn.symbol_offset:
        raise ValueError(f"nonzero native GOT slot displacement: {insn.raw}")

    high_regs = [reg_info(operand) for operand in ops]
    high_positions = [index for index, reg in enumerate(high_regs)
                      if reg is not None and reg[2] != 0]
    high_supported = (
        (op in {"mov", "movabs"} and len(ops) == 2 and (
            (reg_info(ops[0]) is not None and
             (is_int(ops[1]) or reg_info(ops[1]) is not None or is_mem(ops[1]))) or
            (is_mem(ops[0]) and reg_info(ops[1]) is not None))) or
        (op in {"add", "adc", "sub", "sbb"} and len(ops) == 2 and
         reg_info(ops[0]) is not None and
         (is_int(ops[1]) or reg_info(ops[1]) is not None)) or
        (op in {"cmp", "test"} and len(ops) == 2 and
         reg_info(ops[0]) is not None and
         (is_int(ops[1]) or reg_info(ops[1]) is not None)) or
        (op in {"rol", "ror"} and len(ops) == 2 and reg_info(ops[0]) is not None) or
        (op == "div" and len(ops) == 1 and reg_info(ops[0]) is not None) or
        (op in {"movzx", "movsx"} and len(ops) == 2 and
         reg_info(ops[0]) is not None and reg_info(ops[1]) is not None) or
        (op in {"dec", "inc", "neg", "not"} and len(ops) == 1 and
         reg_info(ops[0]) is not None) or
        (op.startswith("set") and op in CC_AUX and len(ops) == 1 and
         reg_info(ops[0]) is not None)
    )
    if high_positions and not high_supported:
        raise ValueError(
            f"unsupported high-byte register operand(s) {high_positions}: {insn.raw}"
        )

    if op in {"nop", "data16", "cs"}:
        return enc("X86_OP_NOP")
    if op == "ret":
        return enc("X86_OP_RET")
    if op == "jmp":
        if len(ops) != 1 or not has_direct_branch_target(ops[0]):
            raise ValueError(f"unsupported indirect jump target in {insn.raw}")
        return enc("X86_OP_JMP", imm=c_u64(branch_target(ops[0])))
    if op in CC_AUX and op.startswith("j"):
        return enc("X86_OP_JCC", aux=CC_AUX[op],
                   imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op == "call":
        if is_helper_symbol(insn.reloc_symbol):
            return enc("X86_OP_CALL_HELPER", imm=f"X86_SIM_HELPER_{insn.reloc_symbol}")
        if insn.reloc_symbol == "memcpy":
            if insn.sim_imm is None:
                return enc("X86_OP_CALL_MEMCPY_REG", imm=c_u64(0))
            return enc("X86_OP_CALL_MEMCPY", imm=c_u64(insn.sim_imm))
        if insn.reloc_symbol == "memset":
            if insn.sim_imm is None:
                return enc("X86_OP_CALL_MEMSET_REG", imm=c_u64(0))
            return enc("X86_OP_CALL_MEMSET", imm=c_u64(insn.sim_imm))
        if ops:
            call_reg = reg_info(ops[0])
            if call_reg is not None:
                return enc("X86_OP_CALL_REG", src=call_reg[0])
        return enc("X86_OP_CALL", imm=c_u64(branch_target(ops[0]) if ops else 0))
    if op == "push":
        if len(ops) != 1:
            raise ValueError(f"cannot encode {insn.raw}")
        src = reg_info(ops[0])
        width = insn.stack_width or (src[1] if src else operand_width(ops[0]))
        if width not in {16,64}:
            raise ValueError(f"invalid long-mode PUSH width in {insn.raw}")
        if src:
            return enc("X86_OP_PUSH",src=src[0],flags=WIDTH_CONST[width])
        if is_int(ops[0]) and insn.reloc_symbol is None:
            return enc("X86_OP_PUSH",flags=WIDTH_CONST[width],aux="X86_PUSHPOP_AUX_IMM",
                       imm=c_u64(parse_int(ops[0])))
        if is_mem(ops[0]):
            return enc("X86_OP_PUSH",src=mem_base_reg(ops[0]),flags=WIDTH_CONST[width],
                       aux=f"({mem_aux(ops[0],width)} | X86_PUSHPOP_AUX_MEM)",
                       imm=c_u64(mem_disp(ops[0])))
        raise ValueError(f"cannot encode PUSH source in {insn.raw}")
    if op == "pop":
        if len(ops) != 1:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        width = insn.stack_width or (dst[1] if dst else operand_width(ops[0]))
        if width not in {16,64}:
            raise ValueError(f"invalid long-mode POP width in {insn.raw}")
        if dst:
            return enc("X86_OP_POP",dst=dst[0],flags=WIDTH_CONST[width])
        if is_mem(ops[0]):
            return enc("X86_OP_POP",dst=mem_base_reg(ops[0]),flags=WIDTH_CONST[width],
                       aux=f"({mem_aux(ops[0],width)} | X86_PUSHPOP_AUX_MEM)",
                       imm=c_u64(mem_disp(ops[0])))
        raise ValueError(f"cannot encode POP destination in {insn.raw}")
    if op.startswith("set") and op in CC_AUX:
        dst = reg_info(ops[0]) if ops else None
        if dst is None:
            if ops and is_mem(ops[0]):
                return enc("X86_OP_SETCC_MEM", dst=mem_base_reg(ops[0]),
                           aux=f"({mem_aux(ops[0], 8)} | X86_REG_AUX_SRC_SHIFT({CC_AUX[op]}))",
                           imm=c_u64(mem_disp(ops[0])))
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SETCC", dst=dst[0], flags="X86_WIDTH_8",
                   aux=c_reg_lane_aux(CC_AUX[op], dst_shift=dst[2]))
    if op.startswith("cmov") and op in CC_AUX:
        dst = reg_info(ops[0]) if len(ops) > 0 else None
        src = reg_info(ops[1]) if len(ops) > 1 else None
        if dst is not None and len(ops) > 1 and is_mem(ops[1]):
            width = operand_width(ops[1], dst[1])
            return enc("X86_OP_CMOV_MEM", dst=dst[0],
                       src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst[1]],
                       aux=f"({mem_aux(ops[1], width)} | X86_REG_AUX_SRC_SHIFT({CC_AUX[op]}))",
                       imm=c_u64((mem_disp(ops[1]) & 0xffffffff) << 32))
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
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux("0", dst_shift=dst_reg[2]),
                       imm=c_u64(parse_int(src)))
        if dst_reg and src_reg:
            return enc("X86_OP_MOV_REG", dst=dst_reg[0], src=src_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux("0", dst_shift=dst_reg[2],
                                          src_shift=src_reg[2]))
        if dst_reg and is_mem(src):
            if dst_reg[2]:
                if operand_width(src, dst_reg[1]) != 8:
                    raise ValueError(f"high-byte load requires a byte memory operand: {insn.raw}")
                if insn.reloc_symbol and (is_helper_symbol(insn.reloc_symbol) or
                        insn.reloc_type not in {"R_X86_64_PC32", "R_X86_64_32", "R_X86_64_32S"}):
                    raise ValueError(f"unresolved high-byte data relocation: {insn.raw}")
                address = relocated_data_address(insn,rodata_idents) if insn.reloc_symbol else c_u64(mem_disp(src))
                value = f"X86_SIM_L_READ_MEM_VALUE({mem_base_reg(src)}, {mem_aux(src)}, {address}, X86_WIDTH_8, 0)"
                return enc("X86_OP_MOV_IMM", dst=dst_reg[0], flags="X86_WIDTH_8",
                           aux=c_reg_lane_aux("0", dst_shift=dst_reg[2]), imm=value)
            if insn.reloc_type=="R_X86_64_PC32":
                return enc("X86_OP_MOV_LOAD",dst=dst_reg[0],src="X86_REG_NONE",
                           flags=WIDTH_CONST[dst_reg[1]],
                           aux=mem_aux(src,operand_width(src,dst_reg[1])),
                           imm=relocated_data_address(insn,rodata_idents))
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
        dst_reg, src_reg = reg_info(ops[0]), reg_info(ops[1])
        if dst_reg is None or dst_reg[1] not in (16, 32, 64):
            raise ValueError(f"cannot encode {insn.raw}")
        source_width = src_reg[1] if src_reg else operand_width(ops[1], 0)
        legal = (source_width, dst_reg[1]) in {(16,16),(32,32),(32,64)} if op == "movsxd" else \
            source_width in (8,16) and source_width <= dst_reg[1]
        if not legal:
            raise ValueError(f"invalid widening-move widths: {insn.raw}")
        if src_reg:
            if src_reg[2] and (dst_reg[1] == 64 or dst_reg[0] not in {
                    "X86_RAX", "X86_RCX", "X86_RDX", "X86_RBX", "X86_RSP", "X86_RBP", "X86_RSI", "X86_RDI"}):
                raise ValueError(f"high-byte source cannot use a REX prefix: {insn.raw}")
            src = f"KPROG_X86_MOVX_HIGH_SOURCE({src_reg[0]})" if src_reg[2] else src_reg[0]
            return enc("X86_OP_MOVSX_REG" if op in {"movsx", "movsxd"} else "X86_OP_MOVZX_REG",
                       dst=dst_reg[0], src=src, flags=WIDTH_CONST[dst_reg[1]], aux=WIDTH_CONST[source_width])
        if is_mem(ops[1]):
            return enc("X86_OP_MOVSX_LOAD" if op in {"movsx", "movsxd"} else "X86_OP_MOV_LOAD",
                       dst=dst_reg[0], src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst_reg[1]], aux=mem_aux(ops[1], source_width),
                       imm=relocated_data_address(insn,rodata_idents)
                           if insn.reloc_type=="R_X86_64_PC32" else c_u64(mem_disp(ops[1])))
        raise ValueError(f"cannot encode {insn.raw}")

    if op in {"cwd", "cdq", "cqo"}:
        if ops:
            raise ValueError(f"cannot encode {insn.raw}")
        width = {"cwd": 16, "cdq": 32, "cqo": 64}[op]
        value = f"(0ULL - ((X86_SIM_L_READ_REG(X86_RAX) >> {width - 1}) & 1ULL))"
        return enc("X86_OP_MOV_IMM", dst="X86_RDX", flags=WIDTH_CONST[width], imm=value)

    if op in {"cbw", "cwde", "cdqe"}:
        if ops:
            raise ValueError(f"cannot encode {insn.raw}")
        target, source = {"cbw": (16,8), "cwde": (32,16), "cdqe": (64,32)}[op]
        return enc("X86_OP_MOVSX_REG", dst="X86_RAX", src="X86_RAX",
                   flags=WIDTH_CONST[target], aux=WIDTH_CONST[source])

    if op == "lea":
        if len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        dst_reg = reg_info(ops[0])
        if dst_reg is None:
            raise ValueError(f"cannot encode {insn.raw}")
        if "[rip" in ops[1].lower():
            return enc("X86_OP_LEA", dst=dst_reg[0], src="X86_REG_NONE",
                       flags=WIDTH_CONST[dst_reg[1]], aux="X86_LEA_AUX_RODATA",
                       imm=relocated_data_address(insn,rodata_idents)
                           if insn.reloc_symbol else c_u64(mem_disp(ops[1])))
        # A 32-bit address is zero-extended even when LEA writes a 64-bit
        # register. The existing 32-bit writeback performs exactly that
        # truncation; 16-bit destinations retain their partial-register write.
        address32 = any(reg_info(name) is not None and reg_info(name)[1] == 32
                        for name in re.findall(r"[A-Za-z][A-Za-z0-9]*", ops[1]))
        width = min(dst_reg[1], 32) if address32 else dst_reg[1]
        base, index, scale_log2, displacement = parse_mem_terms(ops[1])
        # Unit-scale RCX uses the equivalent base form, keeping the
        # ordinary address encoding distinct from the RODATA AUX marker.
        if (width == 64 and base == "X86_REG_NONE" and
                index == "X86_RCX" and scale_log2 == 0):
            return enc("X86_OP_LEA", dst=dst_reg[0], src="X86_RCX",
                       flags=WIDTH_CONST[width],
                       aux="X86_MEM_AUX(X86_REG_NONE, 0)",
                       imm=c_u64(displacement))
        return enc("X86_OP_LEA", dst=dst_reg[0], src=mem_base_reg(ops[1]),
                   flags=WIDTH_CONST[width], aux=mem_aux(ops[1]),
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
                       aux=c_reg_lane_aux("0", dst_reg[2]),
                       imm=c_u64(parse_int(ops[1])))
        if dst_reg and src_reg:
            if op in {"cmp", "test"} and dst_reg[1] != src_reg[1]:
                raise ValueError(
                    f"mismatched register operand widths: {insn.raw}"
                )
            return enc("X86_OP_CMP_REG" if op == "cmp" else "X86_OP_TEST_REG",
                       dst=dst_reg[0], src=src_reg[0], flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux("0", dst_reg[2], src_reg[2]))
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
                       imm=c_u64((mem_disp(ops[0]) & 0xffffffff) << 32))
        if is_mem(ops[0]) and is_int(ops[1]):
            return enc("X86_OP_CMP_MEM_IMM" if op == "cmp" else "X86_OP_TEST_MEM_IMM",
                       dst=mem_base_reg(ops[0]),
                       flags=WIDTH_CONST[operand_width(ops[0], width)],
                       aux=mem_aux(ops[0]),
                       imm=c_u64((parse_int(ops[1]) & 0xffffffff) | ((mem_disp(ops[0]) & 0xffffffff) << 32)))
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
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux(ALU_AUX[op], dst_reg[2]),
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
                           imm=c_u64((parse_int(ops[2]) & 0xffffffff) | ((mem_disp(ops[1]) & 0xffffffff) << 32)))
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
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux(ALU_AUX[op], dst_reg[2]),
                       imm=c_u64(parse_int(ops[1])))
        if dst_reg and src_reg:
            if op in {"add", "adc", "sub", "sbb"} and dst_reg[1] != src_reg[1]:
                raise ValueError(
                    f"mismatched register operand widths: {insn.raw}"
                )
            return enc("X86_OP_ALU_REG", dst=dst_reg[0], src=src_reg[0],
                       flags=WIDTH_CONST[dst_reg[1]],
                       aux=c_reg_lane_aux(ALU_AUX[op], dst_reg[2], src_reg[2]))
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
                       imm=c_u64((parse_int(ops[1]) & 0xffffffff) | ((mem_disp(ops[0]) & 0xffffffff) << 32)))
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
                       imm=c_u64((parse_int(ops[1]) & 0xffffffff) | ((mem_disp(ops[0]) & 0xffffffff) << 32)))
        if dst is None or src is None:
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_BT", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]])

    if op == "mulx":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        hi = reg_info(ops[0])
        lo = reg_info(ops[1])
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
                       imm=c_u64((mem_disp(ops[2]) & 0xffffffff) << 32))
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
        if dst is None or dst[1] not in (16, 32, 64) or len(ops) != 2:
            raise ValueError(f"cannot encode {insn.raw}")
        if src is not None and src[1] == dst[1]:
            return enc("X86_OP_POPCNT", dst=dst[0], src=src[0], flags=WIDTH_CONST[dst[1]])
        if is_mem(ops[1]) and operand_width(ops[1], dst[1]) == dst[1]:
            return enc("X86_OP_POPCNT_MEM", dst=dst[0], src=mem_base_reg(ops[1]),
                       flags=WIDTH_CONST[dst[1]], aux=mem_aux(ops[1]),
                       imm=relocated_data_address(insn, rodata_idents)
                           if insn.reloc_type == "R_X86_64_PC32" else c_u64(mem_disp(ops[1])))
        raise ValueError(f"cannot encode {insn.raw}")
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
    if op == "ror":
        if len(ops) != 2 or not (is_int(ops[1]) or ops[1] == "cl"):
            raise ValueError(f"cannot encode {insn.raw}")
        count = (c_u64(parse_int(ops[1]) & 255) if is_int(ops[1]) else
                 "X86_SIM_L_READ_REG_WIDTH_SHIFT(X86_RCX, X86_WIDTH_8, 0)")
        dst = reg_info(ops[0])
        if dst is not None:
            return enc("X86_OP_ROR", dst=dst[0], flags=WIDTH_CONST[dst[1]],
                       aux=c_reg_lane_aux("0", dst[2]), imm=count)
        if is_mem(ops[0]):
            width = operand_width(ops[0], 0)
            if width not in WIDTH_CONST:
                raise ValueError(f"ROR memory operand requires its native width: {insn.raw}")
            address = (relocated_data_address(insn, rodata_idents) if insn.reloc_symbol
                       else c_u64(mem_disp(ops[0])))
            return enc("X86_OP_ROR_MEM", dst=mem_base_reg(ops[0]), flags=WIDTH_CONST[width],
                       aux=f"({mem_aux(ops[0], width)} | X86_REG_AUX_SRC_SHIFT({count}))",
                       imm=address)
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
        if len(ops) != 1:
            raise ValueError(f"cannot encode {insn.raw}")
        src = reg_info(ops[0])
        if src is not None:
            if src[2]:
                return enc("X86_OP_DIV", src="X86_REG_NONE", flags=WIDTH_CONST[src[1]],
                    imm=f"X86_SIM_L_READ_REG_WIDTH_SHIFT({src[0]}, X86_WIDTH_8, 8)")
            return enc("X86_OP_DIV", src=src[0], flags=WIDTH_CONST[src[1]])
        if is_mem(ops[0]):
            width = operand_width(ops[0], 0)
            if width not in WIDTH_CONST:
                raise ValueError(f"DIV memory operand requires its native width: {insn.raw}")
            if insn.reloc_symbol and (is_helper_symbol(insn.reloc_symbol) or
                    insn.reloc_type not in {"R_X86_64_PC32", "R_X86_64_32", "R_X86_64_32S"}):
                raise ValueError(f"unresolved DIV data relocation: {insn.raw}")
            address = relocated_data_address(insn,rodata_idents) if insn.reloc_symbol else c_u64(mem_disp(ops[0]))
            value = f"X86_SIM_L_READ_MEM_VALUE({mem_base_reg(ops[0])}, {mem_aux(ops[0])}, {address}, {WIDTH_CONST[width]}, 0)"
            return enc("X86_OP_DIV", src="X86_REG_NONE", flags=WIDTH_CONST[width], imm=value)
        raise ValueError(f"cannot encode {insn.raw}")
    if op == "shld":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is None or src is None or not (is_int(ops[2]) or ops[2] == "cl"):
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SHLD_IMM", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])) if is_int(ops[2]) else
                   "X86_SIM_L_READ_REG_WIDTH_SHIFT(X86_RCX, X86_WIDTH_8, 0)")
    if op == "shrd":
        if len(ops) != 3:
            raise ValueError(f"cannot encode {insn.raw}")
        dst = reg_info(ops[0])
        src = reg_info(ops[1])
        if dst is None or src is None or not (is_int(ops[2]) or ops[2] == "cl"):
            raise ValueError(f"cannot encode {insn.raw}")
        return enc("X86_OP_SHRD_IMM", dst=dst[0], src=src[0],
                   flags=WIDTH_CONST[dst[1]], imm=c_u64(parse_int(ops[2])) if is_int(ops[2]) else
                   "X86_SIM_L_READ_REG_WIDTH_SHIFT(X86_RCX, X86_WIDTH_8, 0)")

    raise ValueError(f"unsupported mnemonic: {insn.raw}")


def c_comment(text: str) -> str:
    return text.replace("*/", "* /")


# The specialized step for each token the encoder can lower directly, and the
# aux-gated override for the six lane-shift-sensitive tokens. Both come from the
# machine-checked specialization contract in
# `kprog/formal/x86_specialization_spec.json` (the `directMacro` and
# aux-gated rows): `X86_SPECIALIZATION_DIRECT_CALL` is the call the encoder
# emits at aux 0, `X86_SPECIALIZATION_AUX_CALL` the one it emits for nonzero
# aux. `kprog/formal/KProgFormal/X86Specialization.lean` proves each of these
# calls names the same body the simulator's own `X86_SIM_L_EXEC` chain runs, so
# lowering a token here cannot insert a step the chain does not perform (O2).
DIRECT_STEP_MACROS = dict(X86_SPECIALIZATION_DIRECT_CALL)
AUX_STEP_MACROS = dict(X86_SPECIALIZATION_AUX_CALL)

# Every macro-table key must be an opcode the generated contract defines: a
# typo'd key would otherwise silently miss the table lookup and fall back to the
# generic `X86_SIM_RUN_OP` step. The table is deliberately a superset of the
# opcodes the encoder emits: `MOV_LOAD_SCALAR`, `ADD_IMM`, `ADD_REG`, and
# `XOR_REG` are reachable only through the alias spellings, which the encoder
# never produces (`alu`/`xor reg, reg` lower through `ALU_IMM`/`ALU_REG`).
for _macro_key in DIRECT_STEP_MACROS:
    if _macro_key not in X86_OPCODE_NAME:
        raise SystemExit(f"unknown x86 opcode in DIRECT_STEP_MACROS: {_macro_key}")
del _macro_key
for _aux_key in AUX_STEP_MACROS:
    if _aux_key not in X86_OPCODE_NAME:
        raise SystemExit(f"unknown x86 opcode in AUX_STEP_MACROS: {_aux_key}")
del _aux_key


def direct_step_statement(encoded: EncodedInsn) -> str | None:
    if encoded.aux != "0":
        template = AUX_STEP_MACROS.get(encoded.op)
        if template is not None:
            return template.format(
                op=encoded.op,
                dst=encoded.dst,
                src=encoded.src,
                flags=encoded.flags,
                aux=encoded.aux,
                imm=encoded.imm,
            )
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


def code_address(insn: NativeInsn) -> int | None:
    if insn.mnemonic != "lea" or "[rip" not in insn.raw.lower():
        return None
    if insn.reloc_target is not None:
        return insn.reloc_target
    if insn.reloc_symbol is None and insn.end_addr is not None:
        return (insn.end_addr + mem_disp(insn.operands[1])) & 0xffffffffffffffff
    return None


def indirect_targets(insns: list[NativeInsn], exit_addr: int | None = None,
                     function_starts: set[int] | None = None
                     ) -> dict[int, frozenset[tuple[str, int]]]:
    """Join finite reaching definitions on the native CFG, without execution fuel.

    Only literal definitions, code addresses and exact register copies create
    values. Other writes become unknown, so cycles terminate on a finite lattice
    of source definitions rather than a guessed iteration bound. This analysis
    selects dispatch cases; C still dispatches on the actual architectural value.
    """
    registers = tuple(dict.fromkeys(info[0] for info in REGS.values()))
    indices = {reg: i for i, reg in enumerate(registers)}
    helpers = helper_idents()
    helper_numbers = {name: number for number, name in helpers.items()}
    by_addr = {i.addr: i for i in insns}
    following = {a.addr: b.addr for a, b in zip(insns, insns[1:])}
    starts = sorted(function_starts or {insns[0].addr})
    owners = {addr: max(start for start in starts if start <= addr) for addr in by_addr}
    returns: dict[int, set[int]] = {}
    states = {insns[0].addr: (None,) * len(registers)}
    queue = deque(states)

    def read(state, operand):
        reg = reg_info(operand)
        if reg is None:
            return None
        values = state[indices[reg[0]]]
        if values is None or reg[1] == 64:
            return values
        if any(kind == "code" for kind, value in values):
            return None
        return frozenset((kind, (value >> reg[2]) & ((1 << reg[1]) - 1))
                         for kind, value in values)

    def joined(a, b):
        return None if a is None or b is None else a | b

    def push(target, state):
        if target == exit_addr:
            return
        if target not in by_addr:
            raise ValueError(f"native CFG target 0x{target:x} is not an instruction")
        old = states.get(target)
        merged = state if old is None else tuple(joined(a, b) for a, b in zip(old, state))
        if merged != old:
            states[target] = merged
            queue.append(target)

    def call_edge(target, addr, state):
        push(target, state)
        continuation = following[addr]
        destinations = returns.setdefault(owners[target], set())
        if continuation not in destinations:
            destinations.add(continuation)
            queue.extend(a for a in states if by_addr[a].mnemonic == "ret"
                         and owners[a] == owners[target])

    while queue:
        addr = queue.popleft()
        insn = by_addr[addr]
        op, args = insn.mnemonic, insn.operands
        incoming = states[addr]
        outgoing = list(incoming)
        dst = reg_info(args[0]) if args else None
        if dst and op not in {"cmp", "test", "bt", "push", "jmp", "call"}:
            outgoing[indices[dst[0]]] = None
        implicit = []
        if op in {"mul", "imul", "div", "idiv"} and len(args) == 1:
            implicit = ["X86_RAX", "X86_RDX"]
        elif op in {"cqo", "cdq", "cwd"}:
            implicit = ["X86_RDX"]
        elif op == "cdqe":
            implicit = ["X86_RAX"]
        elif op == "rep":
            implicit = ["X86_RSI", "X86_RDI", "X86_RCX"]
        elif op in {"xchg", "xadd", "mulx"}:
            implicit = [canonical_reg(a) for a in args[:2]]
        elif op == "cmpxchg":
            implicit = ["X86_RAX"]
        for reg in implicit:
            if reg is not None:
                outgoing[indices[reg]] = None
        if dst and op in {"mov", "movabs"} and dst[1] in {32, 64}:
            value = None
            if is_int(args[1]):
                value = frozenset({("scalar", parse_int(args[1]) & ((1 << dst[1]) - 1))})
            elif reg_info(args[1]):
                value = read(incoming, args[1])
            elif insn.reloc_symbol in helper_numbers:
                value = frozenset({("scalar", helper_numbers[insn.reloc_symbol])})
            if dst[1] == 32 and value is not None:
                value = None if any(k == "code" for k, v in value) else frozenset(
                    (k, v & 0xffffffff) for k, v in value)
            outgoing[indices[dst[0]]] = value
        elif dst and op.startswith("cmov") and dst[1] == 64:
            outgoing[indices[dst[0]]] = joined(read(incoming, args[0]), read(incoming, args[1]))
        elif dst and code_address(insn) in by_addr and dst[1] == 64:
            outgoing[indices[dst[0]]] = frozenset({("code", code_address(insn))})
        outgoing = tuple(outgoing)
        indirect = is_indirect_branch(insn)
        if indirect:
            values = read(incoming, args[0])
            if values is not None:
                for kind, target in values:
                    if kind == "code":
                        if op == "call":
                            call_edge(target, addr, outgoing)
                        else:
                            push(target, outgoing)
            helper_call = values is not None and any(k == "scalar" for k, v in values)
        else:
            helper_call = op == "call" and (is_helper_symbol(insn.reloc_symbol) or
                                             insn.reloc_symbol in {"memcpy", "memset"})
            if op in {"jmp", "call"} and not helper_call:
                target = insn.reloc_target if insn.reloc_target is not None else branch_target(args[0])
                if op == "call":
                    call_edge(target, addr, outgoing)
                else:
                    push(target, outgoing)
        if op == "ret":
            # Join return contexts of this callee; don't assume ABI preservation.
            for target in returns.get(owners[addr], set()):
                push(target, outgoing)
        elif helper_call:
            clobbered = list(outgoing)
            for reg in ("RAX", "RCX", "RDX", "RSI", "RDI", "R8", "R9", "R10", "R11"):
                clobbered[indices["X86_" + reg]] = None
            if addr in following:
                push(following[addr], tuple(clobbered))
        elif op not in {"jmp", "call"}:
            if op in CC_AUX and op.startswith("j"):
                push(insn.reloc_target if insn.reloc_target is not None
                     else branch_target(args[0]), outgoing)
            if addr in following:
                push(following[addr], outgoing)

    targets = {}
    for insn in insns:
        if not is_indirect_branch(insn):
            continue
        if insn.addr not in states:
            continue
        values = read(states[insn.addr], insn.operands[0])
        if values is None:
            raise ValueError(f"unresolved finite indirect target at 0x{insn.addr:x}: {insn.raw}")
        for kind, target in values:
            if kind == "code" and target in by_addr:
                continue
            if insn.mnemonic == "call" and kind == "scalar" and target in helpers:
                continue
            raise ValueError(f"invalid indirect target {kind}:0x{target:x} at 0x{insn.addr:x}")
        targets[insn.addr] = values
    return targets


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
    # These encodings embed the memory expression in IMM, so recovery
    # surrounds expression evaluation as well as the operation body.
    dst = reg_info(insn.operands[0]) if insn.operands else None
    memory = None
    recovery_dst = "X86_REG_NONE"
    if (insn.mnemonic in {"mov", "movabs"} and len(insn.operands) == 2 and
            dst is not None and dst[2] and is_mem(insn.operands[1])):
        memory, recovery_dst = insn.operands[1], dst[0]
    elif insn.mnemonic == "div" and is_mem(insn.operands[0]):
        memory, recovery_dst = insn.operands[0], "X86_RAX"
    if memory is not None:
        lines.append(f"{indent}if (!X86_SIM_L_READ_RECOVERY_MEM({mem_base_reg(memory)}, {recovery_dst}, {mem_aux(memory)}, x86_simm({c_u64(mem_disp(memory))}))) {{")
        append_encoded_step(lines, encoded, indent + "\t", step_macro)
        lines.append(f"{indent}}}")
        return
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


def append_indirect(lines: list[str], insn: NativeInsn,
                    targets: frozenset[tuple[str, int]], next_addr: int | None,
                    indent: str) -> None:
    reg = reg_info(insn.operands[0])
    if reg is None or reg[1] != 64:
        raise ValueError(f"indirect target needs a 64-bit register: {insn.raw}")
    helpers = helper_idents()
    lines.extend([f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */",
                  f"{indent}{{",
                  f"{indent}\t__u64 __x86_target = X86_SIM_L_READ_REG({reg[0]});",
                  f"{indent}\tswitch (X86_SIM_L_REG_TAG({reg[0]})) {{"])
    for kind, tag in (("code", "X86_SIM_TAG_CODE"), ("scalar", "X86_SIM_TAG_SCALAR"),
                      ("scalar", "X86_SIM_TAG_HELPER_ID")):
        choices = sorted(target for k, target in targets if k == kind)
        if not choices:
            continue
        lines.extend([f"{indent}\tcase {tag}:", f"{indent}\t\tswitch (__x86_target) {{"])
        for target in choices:
            if kind == "code":
                if insn.mnemonic == "call":
                    if next_addr is None:
                        raise ValueError(f"missing CALL continuation: {insn.raw}")
                    action = f"X86_SIM_X86_CALL(x86_l_{target:x}, 0x{next_addr:x}ULL);"
                else:
                    action = f"goto x86_l_{target:x};"
            else:
                action = f"X86_SIM_BPF_CALL_{helpers[target]}(); break;"
            lines.append(f"{indent}\t\tcase 0x{target:x}ULL: {action}")
        lines.extend([f"{indent}\t\tdefault: __x86_sim_unresolved_indirect_target();",
                      f"{indent}\t\t}}", f"{indent}\t\tbreak;"])
    lines.extend([f"{indent}\tdefault: __x86_sim_unresolved_indirect_target();",
                  f"{indent}\t}}", f"{indent}}}"])


def append_branch_or_ret(lines: list[str], insn: NativeInsn, addrs: set[int],
                         indent: str = "\t", next_addr: int | None = None,
                         call_functions: dict[int, str] | None = None,
                         subroutine: bool = False,
                         step_macro: str = "X86_SIM_RUN_OP",
                         ret_statement: str = "X86_SIM_X86_RET();",
                         return_targets: set[int] | None = None,
                         rodata_idents: dict[str, str] | None = None,
                         targets: dict[int, frozenset[tuple[str, int]]] | None = None) -> None:
    branch_macro = "X86_SIM_X86_SUB_JCC" if subroutine else "X86_SIM_X86_JCC"
    jump_macro = "X86_SIM_X86_SUB_JMP" if subroutine else "X86_SIM_X86_JMP"
    return_targets = return_targets or set()
    if is_indirect_branch(insn):
        append_indirect(lines, insn, (targets or {}).get(insn.addr, frozenset()), next_addr, indent)
        return
    address = code_address(insn)
    if address in addrs and reg_info(insn.operands[0])[1] == 64:
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        lines.append(f"{indent}X86_SIM_X86_CODE_ADDRESS({reg_info(insn.operands[0])[0]}, 0x{address:x}ULL);")
        return
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
        if len(insn.operands) != 1 or not has_direct_branch_target(insn.operands[0]):
            raise ValueError(f"unsupported indirect jump target in {insn.raw}")
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
    if insn.mnemonic == "ud2":
        lines.append(f"{indent}/* 0x{insn.addr:x}: {c_comment(insn.raw)} */")
        lines.append(f"{indent}X86_SIM_L_INVALID_OPCODE_FAULT();")
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
                          rodata_idents: dict[str, str] | None = None,
                          targets: dict[int, frozenset[tuple[str, int]]] | None = None,
                          all_addrs: set[int] | None = None) -> str:
    insns = annotated_fixed_count_ops(insns)
    addrs = all_addrs or {insn.addr for insn in insns}
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
                             rodata_idents=rodata_idents, targets=targets)
    lines.append("")
    return "\n".join(lines)


def readonly_load_declarations(objects: list[tuple[str, bytes]]) -> list[str]:
    """Represent immutable native bytes as finite C values at their exact offsets.

    The compile-time base choice preserves object identity. Each unrepresented
    address or access width retains the ordinary memory operation.
    """
    lines = []
    for name, data in objects:
        lines.extend([
            f"static __always_inline __u64 {name}_value(__u64 offset, __u8 width)",
            "{", "\tswitch (width) {",
        ])
        for width in (1, 2, 4, 8):
            lines.append(f"\tcase {width}: switch (offset) {{")
            for offset in range(len(data) - width + 1):
                lines.extend([
                    f"\tcase {offset}: {{",
                    "\t\t__u64 value = 0;",
                    f"\t\t__builtin_memcpy(&value, {name} + {offset}, {width});",
                    '\t\t__asm__("" : "+r"(value));',
                    "\t\treturn value;", "\t}",
                ])
            lines.append("\t} break;")
        lines.extend([
            "\t}",
            f"\treturn KPROG_X86_MEM_LOAD((const __u8 *){name} + offset, width);",
            "}", "",
        ])
    if objects:
        lines.extend([
            "#undef X86_SIM_L_NATIVE_DATA_LOAD",
            "#define X86_SIM_L_NATIVE_DATA_LOAD(BASE, OFF, WIDTH) \\",
            "({ const void *__x86_ro_base = (BASE); __u64 __x86_ro_off = (OFF); \\",
            "   __u8 __x86_ro_width = (WIDTH); __u64 __x86_ro_value; \\",
        ])
        for name, _ in objects:
            lines.extend([
                "   if (__builtin_constant_p((__u64)(long)__x86_ro_base - "
                f"(__u64)(long){name})) \\",
                f"       __x86_ro_value = {name}_value("
                f"(__u64)(long)__x86_ro_base - (__u64)(long){name} + "
                "__x86_ro_off, __x86_ro_width); else \\",
            ])
        lines.extend([
            "       __x86_ro_value = KPROG_X86_MEM_LOAD("
            "KPROG_PTR_ADD64_BITS(__x86_ro_base, __x86_ro_off), __x86_ro_width); \\",
            "   __x86_ro_value; })", "",
        ])
    return lines


def render_program(name: str, insns: list[NativeInsn],
                   subfunctions: dict[str, list[NativeInsn]] | None = None,
                   kind: str = "xdp",
                   exit_addr: int | None = None,
                   source_prelude: str = "",
                   rodata16: dict[str, tuple[int, int] | bytes] | None = None,
                   program_section: str | None = None,
                   original_source: Path | None = None,
                   original_symbols: set[str] | None = None,
                   source_map_bindings: list[dict] | None = None,
                   trusted_map_bindings: list[dict] | None = None) -> str:
    if (original_source is None)!=(original_symbols is None):
        raise ValueError("original source and ELF symbols must be supplied together")
    rodata16 = {symbol:value for symbol,value in (rodata16 or {}).items()
                if original_symbols is None or symbol not in original_symbols}
    trusted_map_bindings = trusted_map_bindings or []
    trusted_names = set()
    if trusted_map_bindings:
        from trusted_generation import elf_symbol, c_symbol_aliases
    for binding in trusted_map_bindings:
        symbol, offset = binding["native_symbol"], binding["value_offset"]
        if elf_symbol(symbol) in trusted_names:
            raise ValueError("invalid/duplicate trusted native map symbol")
        if offset is not None and (type(offset) is not int or not 0 <= offset <= 0xffffffff):
            raise ValueError("trusted map value offset must be null or u32")
        trusted_names.add(symbol)
    trusted_idents = c_symbol_aliases([b["native_symbol"] for b in trusted_map_bindings], "__x86_trusted_map_") if trusted_map_bindings else {}
    rodata16 = {symbol:value for symbol,value in rodata16.items() if symbol not in trusted_names}
    ret_statement = "X86_SIM_X86_RET();"
    insns = annotated_fixed_count_ops(insns)
    subfunctions = {
        symbol: annotated_fixed_count_ops(fn_insns)
        for symbol, fn_insns in (subfunctions or {}).items()
    }
    all_insns = [*insns, *(i for fn in subfunctions.values() for i in fn)]
    source_map_bindings = source_map_bindings or []
    source_pointers = {}
    for binding in trusted_map_bindings:
        symbol, offset = binding["native_symbol"], binding["value_offset"]
        # The extern is the native symbol's bound address, including the
        # capsule's direct-value base. ELF addends remain relative to it.
        source_pointers[symbol] = (offset is not None, trusted_idents[symbol])
    for binding in source_map_bindings:
        symbol, proof_symbol = binding["native_symbol"], binding["proof_symbol"]
        if any(re.fullmatch(r"[A-Za-z_]\w*", item) is None for item in (symbol, proof_symbol)):
            raise ValueError("source-map symbols must be C identifiers")
        if symbol in source_pointers or binding["kind"] not in {1, 2}:
            raise ValueError("duplicate source-map identity or invalid source kind")
        if type(binding["source_insn"]) is not int or binding["source_insn"] < 0:
            raise ValueError("source-map instruction index must be nonnegative")
        offset = binding["value_offset"]
        if type(offset) is not int or offset < 0 or offset > 0xffffffff or (binding["kind"] == 1 and offset):
            raise ValueError("source-map value offset is invalid")
        source_pointers[symbol] = (binding["kind"] == 2, f"({proof_symbol} + {offset}ULL)")
    # A capsule can list maps unused by this particular entry. Annotate only
    # actual native relocations; never manufacture an unused program load.
    referenced = {i.reloc_symbol for i in all_insns}
    source_pointers = {name:value for name,value in source_pointers.items()
                       if name not in trusted_names or name in referenced}
    used = referenced & source_pointers.keys()
    def source_annotations(body):
        return [replace(i, source_pointer=source_pointers[i.reloc_symbol])
                if i.reloc_symbol in source_pointers else i for i in body]
    insns = source_annotations(insns)
    subfunctions = {symbol: source_annotations(body) for symbol, body in subfunctions.items()}
    all_insns = [*insns, *(i for fn in subfunctions.values() for i in fn)]
    has_indirect = any(is_indirect_branch(i) for i in all_insns)
    targets = indirect_targets(all_insns, exit_addr, {
        insns[0].addr, *(fn[0].addr for fn in subfunctions.values() if fn)
    }) if has_indirect else {}
    native_return_sites = set()
    stack_bytes = check_definedness(all_insns, targets, exit_addr,
        sys.modules[__name__], return_sites=native_return_sites)
    if kind == "raw":
        if not program_section:
            raise ValueError("raw context requires its real BPF program section")
        section = f'SEC({json.dumps(program_section)})'
        ctx_type = "void *"
        declare = "X86_SIM_ENTRY_RAW(ctx);"
    elif kind == "tc":
        section = 'SEC("tc")'
        ctx_type = "struct __sk_buff *"
        declare = "X86_SIM_ENTRY_SKB(ctx);"
    elif kind == "cgroup_skb":
        section = 'SEC("cgroup_skb/egress")'
        ctx_type = "struct __sk_buff *"
        declare = "X86_SIM_ENTRY_SKB(ctx);"
    elif kind == "xdp":
        section = 'SEC("xdp")'
        ctx_type = "struct xdp_md *"
        declare = "X86_SIM_ENTRY_XDP(ctx);"
    else:
        raise ValueError(f"unknown native entry ABI: {kind}")
    if program_section:
        section = f'SEC({json.dumps(program_section)})'
    addrs = {insn.addr for insn in all_insns}
    return_targets = {exit_addr} if exit_addr is not None else set()
    if exit_addr is not None:
        addrs.add(exit_addr)
    subroutine_label_by_addr = {
        fn_insns[0].addr: f"x86_l_{fn_insns[0].addr:x}"
        for symbol, fn_insns in subfunctions.items()
        if fn_insns
    }
    # The existing ABI analysis follows actual saved ReturnAddress values.
    # Helper fallthroughs are not produced by the modeled native CALL/RET.
    return_addrs = sorted(native_return_sites)
    has_stack = any(
        insn.mnemonic in {"push", "pop"} or
        "[rsp" in insn.raw.lower() or
        "[rbp" in insn.raw.lower()
        for fn_insns in [insns, *subfunctions.values()]
        for insn in fn_insns
    ) or bool(subfunctions)
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
        lines.append(f'#define X86_SIM_STACK_BYTES {max(1,(stack_bytes+7)//8*8)}U')
    stack_storage = max(1, (stack_bytes + 7) // 8 * 8) if has_stack else 1
    lines.append('#define X86_SIM_STACK_VALUE_WORDS(M) ' +
                 ' '.join(f'M({i})' for i in range((stack_storage + 7) // 8)))
    if original_source is not None:
        lines.extend(['#define LICENSE __x86_original_license',
                      f'#include {json.dumps(str(original_source.resolve()))}',
                      '#undef LICENSE'])
    lines.extend([
        f'#include "{sim_header}"',
        "",
    ])
    if has_indirect or subfunctions:
        lines.extend([
            '#if defined(__bpf__) || defined(__BPF__)',
            'static __attribute__((always_inline)) inline void',
            '__x86_sim_unresolved_indirect_target(void) {',
            '\tasm volatile("call -1" ::: "r0", "r1", "r2", "r3", "r4", "r5", "memory");',
            '}',
            '#else',
            'extern void __x86_sim_unresolved_indirect_target(void)',
            '\t__attribute__((error("indirect target was not eliminated by specialization")));',
            '#endif',
            '',
        ])
    if source_prelude:
        lines.append(source_prelude.rstrip())
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
        lines.append('static const char __x86_source_map_metadata[] SEC(".native_lab.source_maps") = '
                     + json.dumps(metadata) + ';')
        lines.append("")
    rodata_objects = []
    readonly_values = []
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
        readonly_values.append((ident, value))
        rodata_objects.append(dict(proof_section=section_name, proof_symbol=ident,
                                   native_symbol=symbol, size=len(value)))
    if rodata_idents:
        metadata = json.dumps(dict(version=1, objects=rodata_objects), separators=(",", ":"))
        lines.append('static const char __x86_rodata_metadata[] SEC(".native_lab.rodata") = '
                     + json.dumps(metadata) + ';')
        lines.append("")
    lines.extend(readonly_load_declarations(readonly_values))
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
                             rodata_idents=rodata_idents, targets=targets)
    if exit_addr is not None:
        lines.append(f"x86_l_{exit_addr:x}:")
        lines.append("\t/* native-link entry fallthrough exit */")
        lines.append(f"\t{ret_statement}")
    if subfunctions:
        for symbol, fn_insns in subfunctions.items():
            lines.append(render_x86_subroutine(
                symbol, fn_insns, subroutine_label_by_addr, rodata_idents, targets, addrs))
        lines.extend([
            "x86_sim_ret_dispatch:",
            "\tswitch (__x86_sim_ret_addr) {",
        ])
        for addr in return_addrs:
            lines.append(f"\tcase 0x{addr:x}ULL: goto x86_l_{addr:x};")
        lines.extend([
            "\tdefault: __x86_sim_unresolved_indirect_target();",
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
