#!/usr/bin/env python3
from __future__ import annotations

import argparse
import math
import re
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

from benchmark_catalog import CONFIG_PATH, load_suite


ROOT_DIR = Path(__file__).resolve().parent
DEFAULT_DUMPS_DIR = ROOT_DIR / "jit-dumps"
DEFAULT_OUTPUT = DEFAULT_DUMPS_DIR / "report.md"
RUNTIMES = ("llvmbpf", "kernel")
ROOT_CAUSE_BENCHMARKS = ("bitcount", "code_clone_8", "fixed_loop_large", "dep_chain_short")

BRANCH_RE = re.compile(r"^j[a-z0-9]*$")
STACK_SLOT_RE = re.compile(r"(?:^|[,\s])(?:-?(?:0x)?[0-9a-f]+)?\(%r(?:sp|bp)(?:,[^)]*)?\)")
ADDRESS_RE = re.compile(r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}(?:\s+|$))+)(.*?)\s*$")
TARGET_ADDR_RE = re.compile(r"^\s*(?:0x)?([0-9a-f]+)")
REGISTER_RE = re.compile(r"%[a-z][a-z0-9]*")
PREFIX_TOKENS = {
    "addr32",
    "bnd",
    "cs",
    "data16",
    "ds",
    "es",
    "fs",
    "gs",
    "lock",
    "notrack",
    "rep",
    "repe",
    "repne",
    "repnz",
    "repz",
    "ss",
}
BYTE_LOAD_MNEMONICS = {"movzbq", "movzbl"}
BMI_MNEMONICS = ("blsr", "blsi", "bzhi", "shrx", "shlx", "sarx", "pdep", "pext", "tzcnt", "lzcnt", "popcnt")
NON_DESTRUCTIVE_THREE_OPERAND = {"bzhi", "pdep", "pext", "rorx", "sarx", "shlx", "shrx"}
CALLEE_SAVED_REGS = {"rbx", "rbp", "r12", "r13", "r14", "r15"}


def build_register_aliases() -> dict[str, str]:
    groups = {
        "rax": ("rax", "eax", "ax", "al", "ah"),
        "rbx": ("rbx", "ebx", "bx", "bl", "bh"),
        "rcx": ("rcx", "ecx", "cx", "cl", "ch"),
        "rdx": ("rdx", "edx", "dx", "dl", "dh"),
        "rsi": ("rsi", "esi", "si", "sil"),
        "rdi": ("rdi", "edi", "di", "dil"),
        "rbp": ("rbp", "ebp", "bp", "bpl"),
        "rsp": ("rsp", "esp", "sp", "spl"),
        "rip": ("rip",),
    }
    aliases: dict[str, str] = {}
    for canonical, names in groups.items():
        for name in names:
            aliases[name] = canonical
    for index in range(8, 16):
        aliases[f"r{index}"] = f"r{index}"
        aliases[f"r{index}d"] = f"r{index}"
        aliases[f"r{index}w"] = f"r{index}"
        aliases[f"r{index}b"] = f"r{index}"
    return aliases


REGISTER_ALIASES = build_register_aliases()


@dataclass
class Instruction:
    address: int
    size: int
    text: str
    mnemonic: str
    operands: str


@dataclass(frozen=True)
class MemoryOperand:
    offset: int
    base: str | None
    index: str | None


@dataclass(frozen=True)
class FragmentInfo:
    base: str
    offsets: frozenset[int]
    load_sites: frozenset[int]


@dataclass(frozen=True)
class ByteRecomposeCandidate:
    base: str
    offsets: tuple[int, ...]
    load_sites: tuple[int, ...]
    end_address: int


@dataclass(frozen=True)
class LoopDependency:
    loop_start: int | None
    loop_end: int | None
    branch_mnemonic: str | None
    chain_length: int | None
    loop_insns: int | None


@dataclass
class Metrics:
    total_insns: int | None
    prologue: int | None
    spills: int | None
    branches: int | None
    calls: int | None
    spectre: int | None
    nops: int | None
    byte_recompose_sequences: int | None = None
    byte_recompose_loads: int | None = None
    bmi: int | None = None
    bmi_breakdown: tuple[tuple[str, int], ...] = ()
    cmovs: int | None = None
    rorx: int | None = None
    saved_regs: tuple[str, ...] = ()
    unused_saved_regs: tuple[str, ...] = ()
    nop_bytes: int | None = None
    direct_loads: int | None = None
    direct_stores: int | None = None
    dependency: LoopDependency | None = None
    empty: bool = False
    missing: bool = False

    def value_for(self, category: str) -> int | None:
        return {
            "total_insns": self.total_insns,
            "prologue": self.prologue,
            "spills": self.spills,
            "branches": self.branches,
            "calls": self.calls,
            "spectre": self.spectre,
            "nops": self.nops,
            "byte_recompose_loads": self.byte_recompose_loads,
        }[category]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare kernel vs llvmbpf JIT disassembly for the pure-JIT micro suite.")
    parser.add_argument("dumps_dir_pos", nargs="?", help="Optional positional dumps directory.")
    parser.add_argument("--dumps-dir", dest="dumps_dir_opt", default=None, help="Directory containing <bench>.<runtime>.asm dumps.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Optional markdown output path.")
    args = parser.parse_args()
    args.dumps_dir = args.dumps_dir_opt or args.dumps_dir_pos or str(DEFAULT_DUMPS_DIR)
    return args


def parse_disasm_line(line: str) -> tuple[int, int, str] | None:
    match = ADDRESS_RE.match(line)
    if not match:
        return None
    address = int(match.group(1), 16)
    size = len(match.group(2).split())
    text = match.group(3).strip()
    return address, size, text


def parse_instruction(line: str) -> Instruction | None:
    parsed = parse_disasm_line(line)
    if parsed is None:
        return None

    address, size, text = parsed
    if not text or text.endswith(":"):
        return None

    parts = text.split()
    index = 0
    while index < len(parts):
        token = parts[index]
        if token.startswith("."):
            return None
        if token in PREFIX_TOKENS or token.startswith("rex"):
            index += 1
            continue
        break

    if index >= len(parts):
        return None

    mnemonic = parts[index]
    operands = " ".join(parts[index + 1 :]).strip()
    return Instruction(address=address, size=size, text=text, mnemonic=mnemonic, operands=operands)


def load_instructions(path: Path) -> list[Instruction]:
    instructions: list[Instruction] = []
    for line in path.read_text(errors="replace").splitlines():
        parsed = parse_disasm_line(line)
        if parsed is None:
            continue

        _, size, text = parsed
        if not text:
            if instructions:
                instructions[-1].size += size
            continue

        instruction = parse_instruction(line)
        if instruction is not None:
            instructions.append(instruction)
    return instructions


def canonical_register(token: str) -> str | None:
    normalized = token.strip().lstrip("*").strip()
    if normalized.startswith("%"):
        normalized = normalized[1:]
    return REGISTER_ALIASES.get(normalized.lower())


def split_operands(operands: str) -> list[str]:
    if not operands:
        return []
    result: list[str] = []
    current: list[str] = []
    depth = 0
    for char in operands:
        if char == "(":
            depth += 1
        elif char == ")" and depth > 0:
            depth -= 1
        if char == "," and depth == 0:
            piece = "".join(current).strip()
            if piece:
                result.append(piece)
            current = []
            continue
        current.append(char)
    piece = "".join(current).strip()
    if piece:
        result.append(piece)
    return result


def parse_int_literal(text: str) -> int:
    return int(text, 0)


def parse_memory_operand(operand: str) -> MemoryOperand | None:
    normalized = operand.strip().lstrip("*").strip()
    if "(" not in normalized or not normalized.endswith(")"):
        return None

    prefix, remainder = normalized.split("(", 1)
    inside = remainder[:-1]
    parts = [part.strip() for part in inside.split(",")]
    base = canonical_register(parts[0]) if len(parts) >= 1 and parts[0] else None
    index = canonical_register(parts[1]) if len(parts) >= 2 and parts[1] else None
    offset = parse_int_literal(prefix.strip()) if prefix.strip() else 0
    return MemoryOperand(offset=offset, base=base, index=index)


def operand_register(operand: str) -> str | None:
    normalized = operand.strip().lstrip("*").strip()
    if "(" in normalized:
        return None
    return canonical_register(normalized)


def operand_is_memory(operand: str) -> bool:
    return parse_memory_operand(operand) is not None


def is_stack_memory_operand(operand: str) -> bool:
    memory = parse_memory_operand(operand)
    if memory is None:
        return False
    return memory.base in {"rbp", "rsp"} or memory.index in {"rbp", "rsp"}


def registers_in_operand(operand: str) -> set[str]:
    registers: set[str] = set()
    for token in REGISTER_RE.findall(operand):
        canonical = canonical_register(token)
        if canonical is not None:
            registers.add(canonical)
    return registers


def registers_in_instruction(inst: Instruction) -> set[str]:
    registers: set[str] = set()
    for operand in split_operands(inst.operands):
        registers.update(registers_in_operand(operand))
    return registers


def is_stack_adjust(inst: Instruction, register: str) -> bool:
    if inst.mnemonic not in {"sub", "subq", "add", "addq"}:
        return False
    return register in inst.operands


def is_frame_move(inst: Instruction, src: str, dst: str) -> bool:
    if not inst.mnemonic.startswith("mov"):
        return False
    normalized = inst.operands.replace(" ", "")
    return normalized == f"{src},{dst}"


def is_entry_padding(inst: Instruction) -> bool:
    return inst.mnemonic == "endbr64" or is_nop(inst)


def is_exit_padding(inst: Instruction) -> bool:
    return is_nop(inst) or inst.mnemonic == "int3"


def prologue_bounds(instructions: list[Instruction]) -> tuple[int, int]:
    start = 0
    while start < len(instructions) and is_entry_padding(instructions[start]):
        start += 1

    body_start = start
    while body_start < len(instructions):
        inst = instructions[body_start]
        if inst.mnemonic.startswith("push"):
            body_start += 1
        elif is_stack_adjust(inst, "%rsp"):
            body_start += 1
        elif is_frame_move(inst, "%rsp", "%rbp"):
            body_start += 1
        else:
            break

    end = len(instructions) - 1
    while end >= 0 and is_exit_padding(instructions[end]):
        end -= 1
    if end >= 0 and instructions[end].mnemonic.startswith("ret"):
        end -= 1

    while end >= 0:
        inst = instructions[end]
        if inst.mnemonic.startswith("pop"):
            end -= 1
        elif is_stack_adjust(inst, "%rsp"):
            end -= 1
        elif inst.mnemonic == "leave":
            end -= 1
        elif is_frame_move(inst, "%rbp", "%rsp"):
            end -= 1
        else:
            break

    return body_start, end + 1


def prologue_size(instructions: list[Instruction]) -> int:
    count = 0
    index = 0
    while index < len(instructions) and is_entry_padding(instructions[index]):
        index += 1

    while index < len(instructions):
        inst = instructions[index]
        if inst.mnemonic.startswith("push"):
            count += 1
        elif is_stack_adjust(inst, "%rsp"):
            count += 1
        elif is_frame_move(inst, "%rsp", "%rbp"):
            pass
        else:
            break
        index += 1

    index = len(instructions) - 1
    while index >= 0 and is_exit_padding(instructions[index]):
        index -= 1
    if index >= 0 and instructions[index].mnemonic.startswith("ret"):
        index -= 1

    while index >= 0:
        inst = instructions[index]
        if inst.mnemonic.startswith("pop"):
            count += 1
        elif is_stack_adjust(inst, "%rsp"):
            count += 1
        elif inst.mnemonic == "leave":
            count += 1
        elif is_frame_move(inst, "%rbp", "%rsp"):
            pass
        else:
            break
        index -= 1

    return count


def count_spills(instructions: list[Instruction]) -> int:
    count = 0
    for inst in instructions:
        if not inst.mnemonic.startswith("mov"):
            continue
        if STACK_SLOT_RE.search(inst.operands):
            count += 1
    return count


def count_branches(instructions: list[Instruction]) -> int:
    return sum(1 for inst in instructions if BRANCH_RE.match(inst.mnemonic))


def count_calls(instructions: list[Instruction]) -> int:
    return sum(1 for inst in instructions if inst.mnemonic.startswith("call"))


def is_nop(inst: Instruction) -> bool:
    if re.search(r"\bnop[a-z]*\b", inst.text):
        return True
    if inst.mnemonic == "xchg" and inst.operands.replace(" ", "") in {"%ax,%ax", "%eax,%eax", "%rax,%rax"}:
        return True
    return False


def branch_target(inst: Instruction) -> int | None:
    if not BRANCH_RE.match(inst.mnemonic):
        return None
    match = TARGET_ADDR_RE.match(inst.operands.lstrip("*").strip())
    if not match:
        return None
    try:
        return int(match.group(1), 16)
    except ValueError:
        return None


def call_target(inst: Instruction) -> int | None:
    if not inst.mnemonic.startswith("call"):
        return None
    match = TARGET_ADDR_RE.match(inst.operands.lstrip("*").strip())
    if not match:
        return None
    try:
        return int(match.group(1), 16)
    except ValueError:
        return None


def looks_like_retpoline_thunk(window: list[Instruction]) -> bool:
    mnemonics = [inst.mnemonic for inst in window]
    if any(mnemonic == "lfence" for mnemonic in mnemonics):
        return True
    if any(mnemonic == "pause" for mnemonic in mnemonics):
        return True
    if any(inst.mnemonic.startswith("push") for inst in window) and any(inst.mnemonic.startswith("ret") for inst in window):
        return True
    if any(inst.mnemonic == "jmp" or inst.mnemonic.startswith("jmp") for inst in window) and any(
        inst.mnemonic.startswith("ret") for inst in window
    ):
        return True
    return False


def count_spectre(instructions: list[Instruction]) -> int:
    address_to_index = {inst.address: index for index, inst in enumerate(instructions)}
    lfence_count = sum(1 for inst in instructions if inst.mnemonic == "lfence")
    pause_count = sum(1 for inst in instructions if inst.mnemonic == "pause")
    retpoline_calls = 0
    retpoline_window_indexes: set[int] = set()

    for inst in instructions:
        target = call_target(inst)
        if target is None:
            continue
        target_index = address_to_index.get(target)
        if target_index is None:
            continue
        window = instructions[target_index : target_index + 8]
        if looks_like_retpoline_thunk(window):
            retpoline_calls += 1
            retpoline_window_indexes.update(range(target_index, min(target_index + 8, len(instructions))))

    spectre_nops = sum(1 for index, inst in enumerate(instructions) if index in retpoline_window_indexes and is_nop(inst))
    return lfence_count + pause_count + retpoline_calls + spectre_nops


def is_contiguous_byte_range(offsets: frozenset[int]) -> bool:
    if not offsets:
        return False
    ordered = sorted(offsets)
    return ordered[-1] - ordered[0] + 1 == len(ordered)


def candidate_should_keep(candidate: ByteRecomposeCandidate, all_candidates: list[ByteRecomposeCandidate]) -> bool:
    if len(candidate.offsets) != 4:
        return True
    offset_set = set(candidate.offsets)
    load_set = set(candidate.load_sites)
    for other in all_candidates:
        if other is candidate or other.base != candidate.base or len(other.offsets) != 8:
            continue
        if offset_set.issubset(set(other.offsets)) and load_set.issubset(set(other.load_sites)):
            return False
    return True


def analyze_byte_recompose_patterns(instructions: list[Instruction]) -> tuple[int, int]:
    register_fragments: dict[str, FragmentInfo] = {}
    candidates: list[ByteRecomposeCandidate] = []

    for inst in instructions:
        operands = split_operands(inst.operands)
        dest_reg: str | None = None

        if inst.mnemonic in BYTE_LOAD_MNEMONICS and len(operands) == 2:
            memory = parse_memory_operand(operands[0])
            dest_reg = operand_register(operands[1])
            if memory is not None and memory.base is not None and dest_reg is not None:
                register_fragments[dest_reg] = FragmentInfo(
                    base=memory.base,
                    offsets=frozenset({memory.offset}),
                    load_sites=frozenset({inst.address}),
                )
            elif dest_reg is not None:
                register_fragments.pop(dest_reg, None)
            continue

        if inst.mnemonic.startswith("mov") and not inst.mnemonic.startswith("movz") and len(operands) == 2:
            src_reg = operand_register(operands[0])
            dest_reg = operand_register(operands[1])
            if src_reg is not None and dest_reg is not None:
                fragment = register_fragments.get(src_reg)
                if fragment is not None:
                    register_fragments[dest_reg] = fragment
                else:
                    register_fragments.pop(dest_reg, None)
                continue

        if inst.mnemonic in {"shl", "shlq", "shr", "shrq"} and len(operands) == 2:
            dest_reg = operand_register(operands[1])
            if dest_reg is not None:
                if operand_register(operands[0]) is not None:
                    register_fragments.pop(dest_reg, None)
                else:
                    try:
                        shift = parse_int_literal(operands[0].lstrip("$"))
                    except ValueError:
                        shift = -1
                    if shift < 0 or shift % 8 != 0:
                        register_fragments.pop(dest_reg, None)
                continue

        if inst.mnemonic in {"or", "orq", "orl"} and len(operands) == 2:
            src_reg = operand_register(operands[0])
            dest_reg = operand_register(operands[1])
            if src_reg is not None and dest_reg is not None:
                src_fragment = register_fragments.get(src_reg)
                dest_fragment = register_fragments.get(dest_reg)
                if src_fragment is not None and dest_fragment is not None and src_fragment.base == dest_fragment.base:
                    merged_offsets = src_fragment.offsets | dest_fragment.offsets
                    if len(merged_offsets) == len(src_fragment.offsets) + len(dest_fragment.offsets):
                        merged = FragmentInfo(
                            base=src_fragment.base,
                            offsets=merged_offsets,
                            load_sites=src_fragment.load_sites | dest_fragment.load_sites,
                        )
                        register_fragments[dest_reg] = merged
                        if len(merged.offsets) in {4, 8} and is_contiguous_byte_range(merged.offsets):
                            candidates.append(
                                ByteRecomposeCandidate(
                                    base=merged.base,
                                    offsets=tuple(sorted(merged.offsets)),
                                    load_sites=tuple(sorted(merged.load_sites)),
                                    end_address=inst.address,
                                )
                            )
                        continue
                register_fragments.pop(dest_reg, None)
                continue

        _, writes = instruction_read_write_sets(inst)
        for written in writes:
            if written != "flags":
                register_fragments.pop(written, None)

    kept_candidates = [candidate for candidate in candidates if candidate_should_keep(candidate, candidates)]
    sequences = len(kept_candidates)
    byte_loads = sum(len(candidate.load_sites) for candidate in kept_candidates)
    return sequences, byte_loads


def count_bmi_usage(instructions: list[Instruction]) -> tuple[int, tuple[tuple[str, int], ...]]:
    breakdown = Counter(inst.mnemonic for inst in instructions if inst.mnemonic in BMI_MNEMONICS)
    total = sum(breakdown.values())
    return total, tuple(sorted(breakdown.items()))


def count_cmovs(instructions: list[Instruction]) -> int:
    return sum(1 for inst in instructions if inst.mnemonic.startswith("cmov"))


def count_direct_memory_accesses(instructions: list[Instruction]) -> tuple[int, int]:
    loads = 0
    stores = 0
    for inst in instructions:
        if not inst.mnemonic.startswith("mov") or inst.mnemonic.startswith("movz") or inst.mnemonic.startswith("movs"):
            continue
        operands = split_operands(inst.operands)
        if len(operands) != 2:
            continue
        src, dst = operands
        src_mem = operand_is_memory(src)
        dst_mem = operand_is_memory(dst)
        if src_mem == dst_mem:
            continue
        memory_operand = src if src_mem else dst
        if is_stack_memory_operand(memory_operand):
            continue
        if src_mem:
            loads += 1
        else:
            stores += 1
    return loads, stores


def analyze_saved_registers(instructions: list[Instruction]) -> tuple[tuple[str, ...], tuple[str, ...]]:
    saved_regs: list[str] = []
    index = 0
    while index < len(instructions) and is_entry_padding(instructions[index]):
        index += 1

    while index < len(instructions):
        inst = instructions[index]
        if inst.mnemonic.startswith("push"):
            operands = split_operands(inst.operands)
            reg = operand_register(operands[0]) if operands else None
            if reg in CALLEE_SAVED_REGS:
                saved_regs.append(reg)
            index += 1
            continue
        if is_stack_adjust(inst, "%rsp") or is_frame_move(inst, "%rsp", "%rbp"):
            index += 1
            continue
        break

    body_start, body_end = prologue_bounds(instructions)
    body_regs: set[str] = set()
    for inst in instructions[body_start:body_end]:
        body_regs.update(registers_in_instruction(inst))

    ordered_saved = tuple(dict.fromkeys(saved_regs))
    unused = tuple(reg for reg in ordered_saved if reg not in body_regs)
    return ordered_saved, unused


def mnemonic_sets_flags(inst: Instruction) -> bool:
    if is_nop(inst):
        return False
    if BRANCH_RE.match(inst.mnemonic) or inst.mnemonic.startswith("cmov"):
        return False
    if inst.mnemonic in {"lea", "leave", "endbr64", "int3"}:
        return False
    if inst.mnemonic.startswith("call") or inst.mnemonic.startswith("ret"):
        return False
    if inst.mnemonic.startswith("mov") or inst.mnemonic.startswith("push") or inst.mnemonic.startswith("pop"):
        return False
    return True


def is_zero_idiom(inst: Instruction, operands: list[str]) -> bool:
    if inst.mnemonic not in {"xor", "xorl", "xorq", "sub", "subl", "subq"}:
        return False
    if len(operands) != 2:
        return False
    left = operand_register(operands[0])
    right = operand_register(operands[1])
    return left is not None and left == right


def instruction_read_write_sets(inst: Instruction) -> tuple[set[str], set[str]]:
    operands = split_operands(inst.operands)
    reads: set[str] = set()
    writes: set[str] = set()

    if inst.mnemonic == "leave":
        reads.add("rbp")
        writes.update({"rbp", "rsp"})
        return reads, writes

    if inst.mnemonic.startswith("ret"):
        reads.add("rsp")
        writes.add("rsp")
        return reads, writes

    if inst.mnemonic.startswith("call"):
        reads.update(registers_in_instruction(inst))
        reads.add("rsp")
        writes.add("rsp")
        return reads, writes

    if inst.mnemonic.startswith("push"):
        if operands:
            reads.update(registers_in_operand(operands[0]))
        reads.add("rsp")
        writes.add("rsp")
        return reads, writes

    if inst.mnemonic.startswith("pop"):
        reads.add("rsp")
        writes.add("rsp")
        if operands:
            dest_reg = operand_register(operands[0])
            if dest_reg is not None:
                writes.add(dest_reg)
            else:
                reads.update(registers_in_operand(operands[0]))
        return reads, writes

    if BRANCH_RE.match(inst.mnemonic):
        reads.add("flags")
        reads.update(registers_in_instruction(inst))
        return reads, writes

    if inst.mnemonic.startswith("cmov") and len(operands) == 2:
        reads.add("flags")
        reads.update(registers_in_operand(operands[0]))
        reads.update(registers_in_operand(operands[1]))
        dest_reg = operand_register(operands[1])
        if dest_reg is not None:
            writes.add(dest_reg)
        return reads, writes

    if inst.mnemonic.startswith("cmp") or inst.mnemonic.startswith("test"):
        for operand in operands:
            reads.update(registers_in_operand(operand))
        writes.add("flags")
        return reads, writes

    if inst.mnemonic == "lea" and len(operands) == 2:
        reads.update(registers_in_operand(operands[0]))
        dest_reg = operand_register(operands[1])
        if dest_reg is not None:
            writes.add(dest_reg)
        return reads, writes

    if inst.mnemonic == "imul":
        if len(operands) == 1:
            reads.update(registers_in_operand(operands[0]))
            writes.update({"rax", "rdx", "flags"})
            return reads, writes
        if len(operands) == 2:
            reads.update(registers_in_operand(operands[0]))
            reads.update(registers_in_operand(operands[1]))
            dest_reg = operand_register(operands[1])
            if dest_reg is not None:
                writes.add(dest_reg)
            writes.add("flags")
            return reads, writes
        if len(operands) == 3:
            reads.update(registers_in_operand(operands[1]))
            dest_reg = operand_register(operands[2])
            if dest_reg is not None:
                writes.add(dest_reg)
            writes.add("flags")
            return reads, writes

    if inst.mnemonic in NON_DESTRUCTIVE_THREE_OPERAND and len(operands) == 3:
        reads.update(registers_in_operand(operands[0]))
        reads.update(registers_in_operand(operands[1]))
        dest_reg = operand_register(operands[2])
        if dest_reg is not None:
            writes.add(dest_reg)
        if mnemonic_sets_flags(inst):
            writes.add("flags")
        return reads, writes

    if inst.mnemonic.startswith("mov") and len(operands) == 2:
        reads.update(registers_in_operand(operands[0]))
        if operand_is_memory(operands[1]):
            reads.update(registers_in_operand(operands[1]))
        dest_reg = operand_register(operands[1])
        if dest_reg is not None:
            writes.add(dest_reg)
        return reads, writes

    if len(operands) == 1:
        operand = operands[0]
        reads.update(registers_in_operand(operand))
        dest_reg = operand_register(operand)
        if dest_reg is not None:
            writes.add(dest_reg)
        if mnemonic_sets_flags(inst):
            writes.add("flags")
        return reads, writes

    if len(operands) >= 2:
        for operand in operands[:-1]:
            reads.update(registers_in_operand(operand))

        destination = operands[-1]
        dest_reg = operand_register(destination)
        if dest_reg is not None:
            if not is_zero_idiom(inst, operands):
                reads.add(dest_reg)
            writes.add(dest_reg)
        elif operand_is_memory(destination):
            reads.update(registers_in_operand(destination))

        if mnemonic_sets_flags(inst):
            writes.add("flags")
        return reads, writes

    return reads, writes


def estimate_dependency_chain(loop_instructions: list[Instruction]) -> int:
    last_depth: dict[str, int] = {}
    max_depth = 0
    for inst in loop_instructions:
        reads, writes = instruction_read_write_sets(inst)
        depth = max((last_depth.get(register, 0) for register in reads), default=0)
        if not writes:
            max_depth = max(max_depth, depth)
            continue
        current = depth + 1
        for written in writes:
            last_depth[written] = current
        max_depth = max(max_depth, current)
    return max_depth


def analyze_dependency_chain(instructions: list[Instruction]) -> LoopDependency:
    address_to_index = {inst.address: index for index, inst in enumerate(instructions)}
    best: LoopDependency | None = None

    for index, inst in enumerate(instructions):
        target = branch_target(inst)
        if target is None or target >= inst.address:
            continue
        start_index = address_to_index.get(target)
        if start_index is None or start_index > index:
            continue
        loop_instructions = instructions[start_index : index + 1]
        candidate = LoopDependency(
            loop_start=target,
            loop_end=inst.address,
            branch_mnemonic=inst.mnemonic,
            chain_length=estimate_dependency_chain(loop_instructions),
            loop_insns=len(loop_instructions),
        )
        if best is None:
            best = candidate
            continue
        if (candidate.chain_length or 0) > (best.chain_length or 0):
            best = candidate
            continue
        if (candidate.chain_length or 0) == (best.chain_length or 0) and (candidate.loop_insns or 0) > (best.loop_insns or 0):
            best = candidate

    return best or LoopDependency(None, None, None, None, None)


def analyze_asm(path: Path) -> Metrics:
    if not path.exists():
        return Metrics(None, None, None, None, None, None, None, missing=True)

    instructions = load_instructions(path)
    if not instructions:
        return Metrics(0, 0, 0, 0, 0, 0, 0, empty=True)

    byte_recompose_sequences, byte_recompose_loads = analyze_byte_recompose_patterns(instructions)
    bmi_total, bmi_breakdown = count_bmi_usage(instructions)
    saved_regs, unused_saved_regs = analyze_saved_registers(instructions)
    direct_loads, direct_stores = count_direct_memory_accesses(instructions)

    return Metrics(
        total_insns=len(instructions),
        prologue=prologue_size(instructions),
        spills=count_spills(instructions),
        branches=count_branches(instructions),
        calls=count_calls(instructions),
        spectre=count_spectre(instructions),
        nops=sum(1 for inst in instructions if is_nop(inst)),
        byte_recompose_sequences=byte_recompose_sequences,
        byte_recompose_loads=byte_recompose_loads,
        bmi=bmi_total,
        bmi_breakdown=bmi_breakdown,
        cmovs=count_cmovs(instructions),
        rorx=sum(1 for inst in instructions if inst.mnemonic == "rorx"),
        saved_regs=saved_regs,
        unused_saved_regs=unused_saved_regs,
        nop_bytes=sum(inst.size for inst in instructions if is_nop(inst)),
        direct_loads=direct_loads,
        direct_stores=direct_stores,
        dependency=analyze_dependency_chain(instructions),
    )


def format_metric(value: int | None) -> str:
    if value is None:
        return "n/a"
    return str(value)


def format_regs(registers: tuple[str, ...]) -> str:
    return ",".join(registers) if registers else "-"


def format_loop(loop: LoopDependency | None) -> str:
    if loop is None or loop.loop_start is None or loop.loop_end is None or loop.branch_mnemonic is None:
        return "n/a"
    return f"0x{loop.loop_start:x}-0x{loop.loop_end:x} {loop.branch_mnemonic}"


def safe_ratio(numerator: int | None, denominator: int | None) -> float | None:
    if numerator is None or denominator in (None, 0):
        return None
    return numerator / denominator


def geometric_mean(values: Iterable[float]) -> float | None:
    filtered = [value for value in values if value > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def dominant_reason(kernel: Metrics, llvm: Metrics) -> str:
    deltas = {
        "byte_recompose_loads": (kernel.byte_recompose_loads or 0) - (llvm.byte_recompose_loads or 0),
        "spectre": (kernel.spectre or 0) - (llvm.spectre or 0),
        "calls": (kernel.calls or 0) - (llvm.calls or 0),
        "nops": (kernel.nops or 0) - (llvm.nops or 0),
        "spills": (kernel.spills or 0) - (llvm.spills or 0),
        "prologue": (kernel.prologue or 0) - (llvm.prologue or 0),
        "branches": (kernel.branches or 0) - (llvm.branches or 0),
    }
    positive = {name: delta for name, delta in deltas.items() if delta > 0}
    if not positive:
        return "little measured structural difference"

    sorted_positive = sorted(positive.items(), key=lambda item: item[1], reverse=True)
    label_map = {
        "byte_recompose_loads": "byte-wise load/recompose ladders",
        "spectre": "spectre/retpoline scaffolding",
        "calls": "call-based scaffolding",
        "nops": "nop/alignment padding",
        "spills": "stack spill/fill traffic",
        "prologue": "frame setup/teardown",
        "branches": "branch-heavy lowering",
    }

    leader, leader_value = sorted_positive[0]
    reason = f"kernel adds more {label_map[leader]}"
    if len(sorted_positive) > 1:
        runner_up, runner_up_value = sorted_positive[1]
        if runner_up_value * 4 >= leader_value * 3:
            reason += f" plus {label_map[runner_up]}"
    return reason


def category_ratio_rows(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> list[tuple[str, str]]:
    categories = [
        ("Total insns", "total_insns"),
        ("Prologue", "prologue"),
        ("Spills", "spills"),
        ("Branches", "branches"),
        ("Calls", "calls"),
        ("Spectre", "spectre"),
        ("NOPs", "nops"),
    ]
    rows: list[tuple[str, str]] = []
    for label, key in categories:
        ratios = []
        for runtime_metrics in metrics_by_benchmark.values():
            llvm = runtime_metrics["llvmbpf"]
            kernel = runtime_metrics["kernel"]
            ratio = safe_ratio(llvm.value_for(key), kernel.value_for(key))
            if ratio is not None:
                ratios.append(ratio)
        avg = geometric_mean(ratios)
        rows.append((label, "n/a" if avg is None else f"{avg:.2f}x"))
    return rows


def measured_extra_summary(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> list[tuple[str, int]]:
    categories = ["byte_recompose_loads", "prologue", "spills", "branches", "calls", "spectre", "nops"]
    totals = {category: 0 for category in categories}
    for runtime_metrics in metrics_by_benchmark.values():
        llvm = runtime_metrics["llvmbpf"]
        kernel = runtime_metrics["kernel"]
        for category in categories:
            llvm_value = llvm.value_for(category)
            kernel_value = kernel.value_for(category)
            if llvm_value is None or kernel_value is None:
                continue
            totals[category] += max(kernel_value - llvm_value, 0)
    return sorted(totals.items(), key=lambda item: item[1], reverse=True)


def suite_total(metrics_by_benchmark: dict[str, dict[str, Metrics]], runtime: str, attribute: str) -> int:
    total = 0
    for runtime_metrics in metrics_by_benchmark.values():
        value = getattr(runtime_metrics[runtime], attribute)
        if isinstance(value, int):
            total += value
    return total


def suite_bmi_breakdown(metrics_by_benchmark: dict[str, dict[str, Metrics]], runtime: str) -> Counter[str]:
    counter: Counter[str] = Counter()
    for runtime_metrics in metrics_by_benchmark.values():
        counter.update(dict(runtime_metrics[runtime].bmi_breakdown))
    return counter


def suite_unused_saved_count(metrics_by_benchmark: dict[str, dict[str, Metrics]], runtime: str) -> int:
    return sum(len(runtime_metrics[runtime].unused_saved_regs) for runtime_metrics in metrics_by_benchmark.values())


def format_breakdown(counter: Counter[str]) -> str:
    if not counter:
        return "none"
    return ", ".join(f"`{mnemonic}`={count}" for mnemonic, count in sorted(counter.items()))


def root_cause_note(benchmark: str, kernel: Metrics, llvm: Metrics) -> str:
    notes: list[str] = []
    kernel_chain = kernel.dependency.chain_length if kernel.dependency else None
    llvm_chain = llvm.dependency.chain_length if llvm.dependency else None
    if kernel_chain is not None and llvm_chain is not None and kernel_chain > llvm_chain + 1:
        notes.append("kernel hot loop is more serialized")

    byte_tax = (kernel.byte_recompose_loads or 0) - (llvm.byte_recompose_loads or 0)
    if byte_tax > 0:
        notes.append(f"kernel pays +{byte_tax} extra byte-loads before the loop-carried mix")

    bmi_gap = (llvm.bmi or 0) - (kernel.bmi or 0)
    if bmi_gap > 0:
        notes.append("LLVM substitutes BMI bit-manip ops")

    cmov_gap = (llvm.cmovs or 0) - (kernel.cmovs or 0)
    if cmov_gap > 0:
        notes.append("LLVM removes branch edges with cmov")

    rorx_gap = (llvm.rorx or 0) - (kernel.rorx or 0)
    if rorx_gap > 0:
        notes.append("LLVM uses rorx where kernel synthesizes rotates")

    if benchmark == "bitcount" and (llvm.bmi or 0) > 0:
        notes.append("LLVM gets a direct popcount-style clear-lowest-bit step")
    if benchmark == "dep_chain_short" and byte_tax > 0:
        notes.append("the verifier-safe load ladder extends the critical path")
    if benchmark == "code_clone_8" and byte_tax > 0:
        notes.append("kernel rebuilds the per-iteration 64-bit lane before the cloned mixers")
    if benchmark == "fixed_loop_large" and rorx_gap > 0:
        notes.append("rotate-heavy math stays tighter in LLVM")

    return "; ".join(dict.fromkeys(notes)) if notes else "no single dominant structural cause stood out"


def render_report(metrics_by_benchmark: dict[str, dict[str, Metrics]]) -> str:
    lines: list[str] = []
    lines.append("# JIT Instruction Analysis")
    lines.append("")
    lines.append("| Benchmark | Runtime | Total insns | Prologue | Spills | Branches | Calls | Spectre | NOPs |")
    lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")

    warnings: list[str] = []
    benchmark_deltas: list[tuple[int, float, str, str]] = []

    for benchmark, runtime_metrics in metrics_by_benchmark.items():
        for runtime in RUNTIMES:
            metrics = runtime_metrics[runtime]
            if metrics.missing:
                warnings.append(f"{benchmark} {runtime}: missing asm dump")
            elif metrics.empty:
                warnings.append(f"{benchmark} {runtime}: empty asm dump")
            lines.append(
                f"| {benchmark} | {runtime} | {format_metric(metrics.total_insns)} | "
                f"{format_metric(metrics.prologue)} | {format_metric(metrics.spills)} | "
                f"{format_metric(metrics.branches)} | {format_metric(metrics.calls)} | "
                f"{format_metric(metrics.spectre)} | {format_metric(metrics.nops)} |"
            )

        llvm = runtime_metrics["llvmbpf"]
        kernel = runtime_metrics["kernel"]
        if llvm.total_insns is None or kernel.total_insns is None:
            continue
        delta = kernel.total_insns - llvm.total_insns
        ratio = safe_ratio(kernel.total_insns, llvm.total_insns) or 0.0
        benchmark_deltas.append((delta, ratio, benchmark, dominant_reason(kernel, llvm)))

    lines.append("")
    lines.append("## Summary")
    lines.append("")
    lines.append("### Average llvmbpf/kernel Ratio")
    lines.append("")
    lines.append("| Category | Ratio |")
    lines.append("| --- | ---: |")
    for label, ratio in category_ratio_rows(metrics_by_benchmark):
        lines.append(f"| {label} | {ratio} |")

    lines.append("")
    lines.append("### Where Kernel Adds Instructions")
    lines.append("")
    extra_rows = measured_extra_summary(metrics_by_benchmark)
    extra_total = sum(value for _, value in extra_rows)
    if extra_total == 0:
        lines.append("- No consistent positive category deltas were measured.")
    else:
        lines.append("- Measured categories overlap, so these shares are directional rather than additive.")
        for category, value in extra_rows[:3]:
            share = (value / extra_total) * 100.0
            if category == "byte_recompose_loads":
                label = "Byte recompose loads"
            else:
                label = category.capitalize()
            lines.append(f"- {label}: +{value} instructions ({share:.1f}% of measured positive deltas)")

    if benchmark_deltas:
        benchmark_deltas.sort(key=lambda item: item[0], reverse=True)
        biggest = benchmark_deltas[0]
        smallest = min(benchmark_deltas, key=lambda item: abs(item[0]))
        lines.append("")
        lines.append("### Biggest/Smallest Gaps")
        lines.append("")
        lines.append(
            f"- Biggest kernel inflation: `{biggest[2]}` with +{biggest[0]} instructions "
            f"({biggest[1]:.2f}x kernel/llvmbpf), mainly because {biggest[3]}."
        )
        lines.append(
            f"- Closest match: `{smallest[2]}` with {smallest[0]:+d} instructions "
            f"({smallest[1]:.2f}x kernel/llvmbpf), indicating {smallest[3]}."
        )

    lines.append("")
    lines.append("## Pattern Analysis")
    lines.append("")
    lines.append("### Memory Access and Recomposition")
    lines.append("")
    lines.append(
        "- Byte-recompose counts are heuristic matches for 32/64-bit values rebuilt from byte loads, shifts, and ors; they count code sites, not dynamic executions."
    )
    lines.append(
        f"- Suite totals: kernel has {suite_total(metrics_by_benchmark, 'kernel', 'byte_recompose_sequences')} recompose sites "
        f"covering {suite_total(metrics_by_benchmark, 'kernel', 'byte_recompose_loads')} byte-load instructions, while llvmbpf has "
        f"{suite_total(metrics_by_benchmark, 'llvmbpf', 'byte_recompose_sequences')} sites covering "
        f"{suite_total(metrics_by_benchmark, 'llvmbpf', 'byte_recompose_loads')} byte-load instructions."
    )
    lines.append(
        f"- Direct non-stack `mov` traffic: kernel loads/stores = "
        f"{suite_total(metrics_by_benchmark, 'kernel', 'direct_loads')}/{suite_total(metrics_by_benchmark, 'kernel', 'direct_stores')}, "
        f"llvmbpf loads/stores = {suite_total(metrics_by_benchmark, 'llvmbpf', 'direct_loads')}/"
        f"{suite_total(metrics_by_benchmark, 'llvmbpf', 'direct_stores')}."
    )
    lines.append("")
    lines.append(
        "| Benchmark | K recompose seqs | K byte-loads | K mov loads | K mov stores | L recompose seqs | L byte-loads | L mov loads | L mov stores |"
    )
    lines.append("| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |")
    for benchmark, runtime_metrics in metrics_by_benchmark.items():
        kernel = runtime_metrics["kernel"]
        llvm = runtime_metrics["llvmbpf"]
        lines.append(
            f"| {benchmark} | {format_metric(kernel.byte_recompose_sequences)} | {format_metric(kernel.byte_recompose_loads)} | "
            f"{format_metric(kernel.direct_loads)} | {format_metric(kernel.direct_stores)} | "
            f"{format_metric(llvm.byte_recompose_sequences)} | {format_metric(llvm.byte_recompose_loads)} | "
            f"{format_metric(llvm.direct_loads)} | {format_metric(llvm.direct_stores)} |"
        )

    lines.append("")
    lines.append("### Bit Manipulation and Branchless Lowering")
    lines.append("")
    lines.append(
        f"- Kernel BMI-family breakdown: {format_breakdown(suite_bmi_breakdown(metrics_by_benchmark, 'kernel'))}."
    )
    lines.append(
        f"- llvmbpf BMI-family breakdown: {format_breakdown(suite_bmi_breakdown(metrics_by_benchmark, 'llvmbpf'))}."
    )
    lines.append(
        f"- Conditional moves: kernel={suite_total(metrics_by_benchmark, 'kernel', 'cmovs')} vs "
        f"llvmbpf={suite_total(metrics_by_benchmark, 'llvmbpf', 'cmovs')}."
    )
    lines.append("")
    lines.append("| Benchmark | K BMI | L BMI | K cmov | L cmov |")
    lines.append("| --- | ---: | ---: | ---: | ---: |")
    for benchmark, runtime_metrics in metrics_by_benchmark.items():
        kernel = runtime_metrics["kernel"]
        llvm = runtime_metrics["llvmbpf"]
        lines.append(
            f"| {benchmark} | {format_metric(kernel.bmi)} | {format_metric(llvm.bmi)} | "
            f"{format_metric(kernel.cmovs)} | {format_metric(llvm.cmovs)} |"
        )

    lines.append("")
    lines.append("### Prologues and Alignment")
    lines.append("")
    lines.append(
        f"- Saved-but-unused callee-saved registers across the suite: kernel={suite_unused_saved_count(metrics_by_benchmark, 'kernel')} vs "
        f"llvmbpf={suite_unused_saved_count(metrics_by_benchmark, 'llvmbpf')}."
    )
    lines.append(
        f"- Aggregate NOP bytes: kernel={suite_total(metrics_by_benchmark, 'kernel', 'nop_bytes')} vs "
        f"llvmbpf={suite_total(metrics_by_benchmark, 'llvmbpf', 'nop_bytes')}."
    )
    lines.append("")
    lines.append("| Benchmark | K saves | K unused | L saves | L unused | K NOPs | K NOP bytes | L NOPs | L NOP bytes |")
    lines.append("| --- | --- | --- | --- | --- | ---: | ---: | ---: | ---: |")
    for benchmark, runtime_metrics in metrics_by_benchmark.items():
        kernel = runtime_metrics["kernel"]
        llvm = runtime_metrics["llvmbpf"]
        lines.append(
            f"| {benchmark} | {format_regs(kernel.saved_regs)} | {format_regs(kernel.unused_saved_regs)} | "
            f"{format_regs(llvm.saved_regs)} | {format_regs(llvm.unused_saved_regs)} | "
            f"{format_metric(kernel.nops)} | {format_metric(kernel.nop_bytes)} | "
            f"{format_metric(llvm.nops)} | {format_metric(llvm.nop_bytes)} |"
        )

    lines.append("")
    lines.append("## Root Cause Analysis")
    lines.append("")
    lines.append(
        "- Dependency-chain estimates use the strongest backward-edge loop in each function. They are heuristics over register/flag flow, not cycle-accurate throughput models."
    )
    lines.append("")
    lines.append("| Benchmark | Kernel loop | K chain | LLVM loop | L chain | Kernel pattern tax | LLVM shortcuts | Likely root cause |")
    lines.append("| --- | --- | ---: | --- | ---: | --- | --- | --- |")
    for benchmark in ROOT_CAUSE_BENCHMARKS:
        runtime_metrics = metrics_by_benchmark[benchmark]
        kernel = runtime_metrics["kernel"]
        llvm = runtime_metrics["llvmbpf"]
        kernel_tax = (
            f"{format_metric(kernel.byte_recompose_sequences)} seqs / "
            f"{format_metric(kernel.byte_recompose_loads)} byte-loads"
        )
        llvm_shortcuts = (
            f"{format_metric(llvm.direct_loads)} mov-loads, {format_metric(llvm.bmi)} BMI, "
            f"{format_metric(llvm.cmovs)} cmov, {format_metric(llvm.rorx)} rorx"
        )
        lines.append(
            f"| {benchmark} | {format_loop(kernel.dependency)} | {format_metric(kernel.dependency.chain_length if kernel.dependency else None)} | "
            f"{format_loop(llvm.dependency)} | {format_metric(llvm.dependency.chain_length if llvm.dependency else None)} | "
            f"{kernel_tax} | {llvm_shortcuts} | {root_cause_note(benchmark, kernel, llvm)} |"
        )

    if warnings:
        lines.append("")
        lines.append("### Warnings")
        lines.append("")
        for warning in warnings:
            lines.append(f"- {warning}")

    lines.append("")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    suite = load_suite(CONFIG_PATH)
    dumps_dir = Path(args.dumps_dir).resolve()
    metrics_by_benchmark: dict[str, dict[str, Metrics]] = {}

    for benchmark in suite.benchmarks.values():
        runtime_metrics: dict[str, Metrics] = {}
        for runtime in RUNTIMES:
            asm_path = dumps_dir / f"{benchmark.name}.{runtime}.asm"
            runtime_metrics[runtime] = analyze_asm(asm_path)
        metrics_by_benchmark[benchmark.name] = runtime_metrics

    report = render_report(metrics_by_benchmark)
    print(report, end="")

    if args.output:
        output_path = Path(args.output).resolve()
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(report)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
