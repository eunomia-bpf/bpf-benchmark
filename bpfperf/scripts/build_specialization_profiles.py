#!/usr/bin/env python3
"""Admit raw deployment observations into strict bpfopt profile files.

This is deliberately separate from the benchmark runner: bpfprof records raw
observations, this tool applies an explicit training-time admission policy, and
bpfopt consumes only the resulting per-pass profile.  Empty admitted sets are
written as valid profiles so every program still traverses the configured pass.
"""

from __future__ import annotations

import argparse
from dataclasses import dataclass
import json
from pathlib import Path
import re
import struct
from typing import Any


PASS_NAMES = (
    "tail_call_icache",
    "hot_region_version",
    "loop_trip_spec",
    "context_specialize",
    "branch_flip",
)
PROGRAM_HASH_RE = re.compile(r"[0-9a-fA-F]{16}")
OUTPUT_STEM_RE = re.compile(r"(?:hash-[0-9a-f]{16}|prog-[1-9][0-9]*)")

BPF_LDX = 0x01
BPF_ST = 0x02
BPF_STX = 0x03
BPF_JMP = 0x05
BPF_JMP32 = 0x06
BPF_CLASS_MASK = 0x07
BPF_SIZE_MASK = 0x18
BPF_B = 0x10
BPF_H = 0x08
BPF_W = 0x00
BPF_DW = 0x18
BPF_OP_MASK = 0xF0
BPF_JA = 0x00
BPF_CALL = 0x80
BPF_EXIT = 0x90
BPF_JEQ = 0x10
BPF_JNE = 0x50
BPF_CALL_INSN = 0x85
BPF_CALLX_INSN = 0x8D
BPF_LD_IMM64 = 0x18
BPF_PSEUDO_CALL = 1
BPF_PSEUDO_FUNC = 4
BPF_MOV64_X = 0xBF
BPF_MOV64_K = 0xB7
BPF_MOV32_K = 0xB4
BPF_ADD64_K = 0x07
BPF_ADD64_X = 0x0F
BPF_AND64_K = 0x57
BPF_MODE_MASK = 0xE0
BPF_MEM = 0x60


class ProfileError(ValueError):
    pass


@dataclass(frozen=True)
class Insn:
    code: int
    dst: int
    src: int
    off: int
    imm: int


@dataclass(frozen=True)
class Admission:
    min_observations: int
    min_hot_permille: int
    max_tail_sites: int
    max_loop_sites: int
    max_context_fields: int

    def admits(self, observations: int, hot_count: int) -> bool:
        return (
            observations >= self.min_observations
            and hot_count > 0
            and hot_count <= observations
            and hot_count * 1000 >= observations * self.min_hot_permille
        )


@dataclass(frozen=True)
class ContextFieldHint:
    kind: str
    source: str
    offset: int
    width: int
    hot_value: int | None
    hot_bytes_hex: str | None
    context_data_offset: int | None
    context_data_end_offset: int | None
    load_pcs: tuple[int, ...]
    version: int | None = None

    def to_profile_field(self) -> dict[str, Any]:
        field: dict[str, Any] = {
            "kind": self.kind,
            "source": self.source,
            "offset": self.offset,
            "width": self.width,
            "load_pcs": list(self.load_pcs),
        }
        if self.kind == "context":
            field["hot_value"] = self.hot_value
        else:
            field.update(
                hot_bytes_hex=self.hot_bytes_hex,
                context_data_offset=self.context_data_offset,
                context_data_end_offset=self.context_data_end_offset,
            )
        return field


@dataclass
class EntryContextProvenance:
    context_registers: dict[int, int]
    frame_registers: dict[int, int]
    stack_context: dict[int, int]

    def copy(self) -> "EntryContextProvenance":
        return EntryContextProvenance(
            dict(self.context_registers),
            dict(self.frame_registers),
            dict(self.stack_context),
        )


def expect_object(value: Any, label: str) -> dict[str, Any]:
    if not isinstance(value, dict):
        raise ProfileError(f"{label} must be an object")
    return value


def expect_nonnegative_int(value: Any, label: str) -> int:
    if not isinstance(value, int) or isinstance(value, bool) or value < 0:
        raise ProfileError(f"{label} must be a nonnegative integer")
    return value


def constrained_branch_miss_rate(branch_samples: int, miss_samples: int) -> float:
    """Return the physical MLE for two independent fixed-period PMU streams."""
    if miss_samples == 0:
        return 0.0
    if branch_samples == 0 or miss_samples >= branch_samples:
        return 1.0
    return miss_samples / branch_samples


def expect_count_map(value: Any, label: str) -> dict[int, int]:
    obj = expect_object(value, label)
    result: dict[int, int] = {}
    for raw_key, raw_count in obj.items():
        if not isinstance(raw_key, str) or not raw_key.isdecimal():
            raise ProfileError(f"{label} keys must be decimal integers")
        key = int(raw_key)
        count = expect_nonnegative_int(raw_count, f"{label}[{raw_key}]")
        if count == 0:
            raise ProfileError(f"{label}[{raw_key}] must be positive")
        result[key] = count
    return result


def parse_context_field_hint(raw: str) -> ContextFieldHint:
    try:
        value = json.loads(raw)
    except json.JSONDecodeError as error:
        raise ProfileError(f"invalid --context-field-hint JSON: {error}") from error
    field = expect_object(value, "context field hint")
    common = {
        "kind",
        "source",
        "offset",
        "width",
        "load_pcs",
    }
    kind = field.get("kind")
    if kind == "packet":
        expected = common | {
            "hot_bytes_hex",
            "context_data_offset",
            "context_data_end_offset",
        }
    elif kind == "context":
        expected = common | {"hot_value"}
    else:
        raise ProfileError("context field hint kind must be packet or context")
    unknown = sorted(set(field) - (expected | {"version"}))
    missing = sorted(expected - set(field))
    if unknown:
        raise ProfileError(
            "context field hint has unknown keys: " + ",".join(unknown)
        )
    if missing:
        raise ProfileError(
            "context field hint is missing keys: " + ",".join(missing)
        )
    if field["source"] != "deployment_hint":
        raise ProfileError("context field hint requires source=deployment_hint")
    version = field.get("version")
    if version is not None:
        version = expect_nonnegative_int(version, "context field hint version")
    offset = expect_nonnegative_int(field["offset"], "context field hint offset")
    width = expect_nonnegative_int(field["width"], "context field hint width")
    if width not in (1, 2, 4, 8):
        raise ProfileError("context field hint width must be 1, 2, 4, or 8")
    if offset + width > 0xFFFFFFFF:
        raise ProfileError("context field hint range exceeds u32")
    hot_value: int | None = None
    hot_bytes_hex: str | None = None
    data_offset: int | None = None
    data_end_offset: int | None = None
    if kind == "packet":
        hot_bytes_hex = field["hot_bytes_hex"]
        if (
            not isinstance(hot_bytes_hex, str)
            or len(hot_bytes_hex) != width * 2
            or any(ch not in "0123456789abcdefABCDEF" for ch in hot_bytes_hex)
        ):
            raise ProfileError(
                "context field hint hot_bytes_hex must contain exactly width bytes"
            )
        hot_bytes_hex = hot_bytes_hex.lower()
        data_offset = expect_nonnegative_int(
            field["context_data_offset"], "context field hint context_data_offset"
        )
        data_end_offset = expect_nonnegative_int(
            field["context_data_end_offset"],
            "context field hint context_data_end_offset",
        )
        if data_offset == data_end_offset:
            raise ProfileError("context data and data_end offsets must differ")
    else:
        hot_value = expect_nonnegative_int(
            field["hot_value"], "context field hint hot_value"
        )
        if hot_value >= 1 << (width * 8):
            raise ProfileError("context field hint hot_value does not fit width")
    raw_load_pcs = field["load_pcs"]
    if not isinstance(raw_load_pcs, list) or not raw_load_pcs:
        raise ProfileError("context field hint load_pcs must be a nonempty array")
    load_pcs = tuple(
        expect_nonnegative_int(pc, "context field hint load pc")
        for pc in raw_load_pcs
    )
    if len(set(load_pcs)) != len(load_pcs):
        raise ProfileError("context field hint load_pcs contains duplicates")
    return ContextFieldHint(
        kind,
        "deployment_hint",
        offset,
        width,
        hot_value,
        hot_bytes_hex,
        data_offset,
        data_end_offset,
        tuple(sorted(load_pcs)),
        version,
    )


def merge_entry_context_provenance(
    current: EntryContextProvenance, incoming: EntryContextProvenance
) -> EntryContextProvenance:
    def common(left: dict[int, int], right: dict[int, int]) -> dict[int, int]:
        return {key: value for key, value in left.items() if right.get(key) == value}

    return EntryContextProvenance(
        common(current.context_registers, incoming.context_registers),
        common(current.frame_registers, incoming.frame_registers),
        common(current.stack_context, incoming.stack_context),
    )


def memory_width(code: int) -> int | None:
    return {BPF_B: 1, BPF_H: 2, BPF_W: 4, BPF_DW: 8}.get(
        code & BPF_SIZE_MASK
    )


def kill_stack_context_range(
    stack_context: dict[int, int], start: int, width: int
) -> None:
    end = start + width
    for slot in list(stack_context):
        if max(start, slot) < min(end, slot + 8):
            stack_context.pop(slot)


def transfer_entry_context_provenance(
    state: EntryContextProvenance, insn: Insn
) -> EntryContextProvenance:
    result = state.copy()
    context = result.context_registers
    frame = result.frame_registers
    stack = result.stack_context
    klass = insn.code & BPF_CLASS_MASK

    if insn.code == BPF_MOV64_X:
        context_origin = context.get(insn.src)
        frame_origin = frame.get(insn.src)
        context.pop(insn.dst, None)
        frame.pop(insn.dst, None)
        if context_origin is not None:
            context[insn.dst] = context_origin
        elif frame_origin is not None:
            frame[insn.dst] = frame_origin
        return result

    if insn.code == BPF_ADD64_K:
        if insn.dst in context:
            context[insn.dst] += insn.imm
        if insn.dst in frame:
            frame[insn.dst] += insn.imm
        return result

    load_width = ldx_width(insn.code)
    if load_width is not None:
        frame_origin = frame.get(insn.src)
        context.pop(insn.dst, None)
        frame.pop(insn.dst, None)
        if (
            insn.code & BPF_MODE_MASK == BPF_MEM
            and load_width == 8
            and frame_origin is not None
        ):
            stack_origin = stack.get(frame_origin + insn.off)
            if stack_origin is not None:
                context[insn.dst] = stack_origin
        return result

    if klass in (BPF_ST, BPF_STX):
        frame_origin = frame.get(insn.dst)
        width = memory_width(insn.code)
        if frame_origin is not None and width is not None:
            stack_offset = frame_origin + insn.off
            kill_stack_context_range(stack, stack_offset, width)
            if (
                klass == BPF_STX
                and insn.code & BPF_MODE_MASK == BPF_MEM
                and width == 8
                and insn.src in context
            ):
                stack[stack_offset] = context[insn.src]
        return result

    if insn.code in (BPF_CALL_INSN, BPF_CALLX_INSN):
        # BPF helpers and BPF-to-BPF callees preserve r6-r9 and the caller's
        # stack frame. They may clobber the return and argument registers.
        for reg in range(0, 6):
            context.pop(reg, None)
            frame.pop(reg, None)
        return result

    if klass in (0x00, 0x04, 0x07):
        context.pop(insn.dst, None)
        frame.pop(insn.dst, None)
    return result


def entry_context_successors(pc: int, insn: Insn, limit: int) -> tuple[int, ...]:
    if insn.code == BPF_LD_IMM64:
        return (pc + 2,) if pc + 2 < limit else ()
    klass = insn.code & BPF_CLASS_MASK
    if klass not in (BPF_JMP, BPF_JMP32):
        return (pc + 1,) if pc + 1 < limit else ()
    operation = insn.code & BPF_OP_MASK
    if operation == BPF_EXIT:
        return ()
    if operation == BPF_CALL:
        return (pc + 1,) if pc + 1 < limit else ()
    target = pc + 1 + insn.off
    if target < 0:
        raise ProfileError(
            f"context provenance branch pc {pc} targets out-of-range pc {target}"
        )
    if operation == BPF_JA:
        return (target,) if target < limit else ()
    successors = [target] if target < limit else []
    if pc + 1 < limit and pc + 1 != target:
        successors.append(pc + 1)
    return tuple(successors)


def entry_context_provenance_by_pc(
    insns: list[Insn], last_site: int
) -> list[EntryContextProvenance | None]:
    limit = last_site + 1
    states: list[EntryContextProvenance | None] = [None] * limit
    states[0] = EntryContextProvenance({1: 0}, {10: 0}, {})
    worklist = [0]
    while worklist:
        pc = worklist.pop()
        state = states[pc]
        assert state is not None
        outgoing = transfer_entry_context_provenance(state, insns[pc])
        for successor in entry_context_successors(pc, insns[pc], limit):
            current = states[successor]
            merged = (
                outgoing.copy()
                if current is None
                else merge_entry_context_provenance(current, outgoing)
            )
            if current is None or merged != current:
                states[successor] = merged
                worklist.append(successor)
    return states


@dataclass
class PacketProvenanceState:
    context_pointers: dict[int, int]
    packet_pointers: dict[int, int]
    scalar_constants: dict[int, int]
    stack_packet_pointers: dict[int, int]
    packet_epoch_changed: bool = False

    def copy(self) -> "PacketProvenanceState":
        return PacketProvenanceState(
            dict(self.context_pointers),
            dict(self.packet_pointers),
            dict(self.scalar_constants),
            dict(self.stack_packet_pointers),
            self.packet_epoch_changed,
        )

    def key(self) -> tuple[Any, ...]:
        return (
            tuple(sorted(self.context_pointers.items())),
            tuple(sorted(self.packet_pointers.items())),
            tuple(sorted(self.scalar_constants.items())),
            tuple(sorted(self.stack_packet_pointers.items())),
            self.packet_epoch_changed,
        )


def validate_packet_hint_provenance(
    hints: list[ContextFieldHint],
    insns: list[Insn],
    data_offset: int,
) -> dict[int, int]:
    width_by_opcode = {0x71: 1, 0x69: 2, 0x61: 4, 0x79: 8}
    expected_sites: dict[int, tuple[ContextFieldHint, int]] = {
        pc: (hint, width_by_opcode[insns[pc].code])
        for hint in hints
        for pc in hint.load_pcs
    }
    last_site = max(expected_sites)
    known_packet_bytes: dict[int, int] = {}
    for hint in hints:
        assert hint.hot_bytes_hex is not None
        for relative, byte in enumerate(bytes.fromhex(hint.hot_bytes_hex)):
            offset = hint.offset + relative
            previous = known_packet_bytes.get(offset)
            if previous is not None and previous != byte:
                raise ProfileError("context field hints disagree on packet bytes")
            known_packet_bytes[offset] = byte

    states: list[dict[tuple[Any, ...], PacketProvenanceState]] = [
        {} for _ in range(last_site + 1)
    ]
    initial = PacketProvenanceState({1: 0}, {}, {}, {})
    states[0][initial.key()] = initial
    worklist: list[tuple[int, tuple[Any, ...]]] = [(0, initial.key())]
    packet_mutating_helpers = {44, 54, 65}
    max_states_per_pc = 128
    reached_offsets: dict[int, set[int]] = {pc: set() for pc in expected_sites}

    def enqueue(pc: int, state: PacketProvenanceState) -> None:
        if pc < 0 or pc > last_site:
            return
        key = state.key()
        if key in states[pc]:
            return
        if len(states[pc]) >= max_states_per_pc:
            raise ProfileError(
                f"packet provenance exceeded {max_states_per_pc} states at pc {pc}"
            )
        states[pc][key] = state
        worklist.append((pc, key))

    while worklist:
        pc, state_key = worklist.pop()
        state = states[pc][state_key]
        insn = insns[pc]
        if pc in expected_sites:
            hint, load_width = expected_sites[pc]
            pointer_offset = state.packet_pointers.get(insn.src)
            actual_offset = (
                None if pointer_offset is None else pointer_offset + insn.off
            )
            if state.packet_epoch_changed:
                raise ProfileError(
                    f"packet epoch changed before context hint load pc {pc}"
                )
            if (
                actual_offset is None
                or actual_offset < hint.offset
                or actual_offset + load_width > hint.offset + hint.width
            ):
                raise ProfileError(
                    f"context field hint load pc {pc} lacks entry packet provenance"
                )
            reached_offsets[pc].add(actual_offset)

        outgoing = state.copy()
        context = outgoing.context_pointers
        packet = outgoing.packet_pointers
        constants = outgoing.scalar_constants
        stack_packet = outgoing.stack_packet_pointers
        klass = insn.code & BPF_CLASS_MASK

        if insn.code == BPF_LD_IMM64:
            if pc + 1 >= len(insns):
                raise ProfileError("truncated LD_IMM64 in packet provenance")
            constants[insn.dst] = (
                (insns[pc + 1].imm & 0xFFFFFFFF) << 32
            ) | (insn.imm & 0xFFFFFFFF)
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            enqueue(pc + 2, outgoing)
            continue
        if insn.code == BPF_MOV64_X:
            context_origin = context.get(insn.src)
            packet_origin = packet.get(insn.src)
            scalar = constants.get(insn.src)
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            constants.pop(insn.dst, None)
            if context_origin is not None:
                context[insn.dst] = context_origin
            elif packet_origin is not None:
                packet[insn.dst] = packet_origin
            elif scalar is not None:
                constants[insn.dst] = scalar
            enqueue(pc + 1, outgoing)
            continue
        if insn.code == BPF_MOV64_K:
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            constants[insn.dst] = insn.imm & 0xFFFFFFFFFFFFFFFF
            enqueue(pc + 1, outgoing)
            continue
        if insn.code == BPF_ADD64_K:
            if insn.dst in context:
                context[insn.dst] += insn.imm
            if insn.dst in packet:
                packet[insn.dst] += insn.imm
            if insn.dst in constants:
                constants[insn.dst] = (
                    constants[insn.dst] + insn.imm
                ) & 0xFFFFFFFFFFFFFFFF
            enqueue(pc + 1, outgoing)
            continue
        if insn.code == BPF_ADD64_X:
            source = constants.get(insn.src)
            if source is not None and insn.dst in context:
                context[insn.dst] += source
            elif source is not None and insn.dst in packet:
                packet[insn.dst] += source
            else:
                context.pop(insn.dst, None)
                packet.pop(insn.dst, None)
            if insn.dst in constants and source is not None:
                constants[insn.dst] = (
                    constants[insn.dst] + source
                ) & 0xFFFFFFFFFFFFFFFF
            else:
                constants.pop(insn.dst, None)
            enqueue(pc + 1, outgoing)
            continue
        if insn.code == BPF_AND64_K:
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            if insn.dst in constants:
                constants[insn.dst] &= insn.imm & 0xFFFFFFFFFFFFFFFF
            enqueue(pc + 1, outgoing)
            continue

        load_width = ldx_width(insn.code)
        if load_width is not None:
            source_context_offset = context.get(insn.src)
            source_packet_offset = packet.get(insn.src)
            stack_packet_offset = (
                stack_packet.get(insn.off)
                if load_width == 8 and insn.src == 10
                else None
            )
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            constants.pop(insn.dst, None)
            if stack_packet_offset is not None:
                packet[insn.dst] = stack_packet_offset
            elif (
                load_width == 4
                and source_context_offset is not None
                and source_context_offset + insn.off == data_offset
            ):
                packet[insn.dst] = 0
            elif source_packet_offset is not None:
                start = source_packet_offset + insn.off
                raw = [known_packet_bytes.get(start + index) for index in range(load_width)]
                if all(byte is not None for byte in raw):
                    constants[insn.dst] = int.from_bytes(
                        bytes(int(byte) for byte in raw), "little"
                    )
            enqueue(pc + 1, outgoing)
            continue

        if klass in (BPF_ST, BPF_STX):
            store_width = {
                BPF_B: 1,
                BPF_H: 2,
                BPF_W: 4,
                BPF_DW: 8,
            }.get(insn.code & BPF_SIZE_MASK)
            if insn.dst == 10 and store_width is not None:
                store_start = insn.off
                store_end = store_start + store_width
                for slot in list(stack_packet):
                    if max(store_start, slot) < min(store_end, slot + 8):
                        stack_packet.pop(slot)
                if (
                    klass == BPF_STX
                    and store_width == 8
                    and insn.src in packet
                ):
                    stack_packet[insn.off] = packet[insn.src]
            if insn.dst in packet:
                outgoing.packet_epoch_changed = True
            enqueue(pc + 1, outgoing)
            continue
        if insn.code in (BPF_CALL_INSN, BPF_CALLX_INSN):
            if (
                insn.code == BPF_CALL_INSN
                and insn.src != BPF_PSEUDO_CALL
                and insn.imm in packet_mutating_helpers
            ):
                outgoing.packet_epoch_changed = True
            for reg in range(0, 6):
                context.pop(reg, None)
                packet.pop(reg, None)
                constants.pop(reg, None)
            enqueue(pc + 1, outgoing)
            continue

        if klass in (BPF_JMP, BPF_JMP32):
            operation = insn.code & BPF_OP_MASK
            if operation == BPF_EXIT:
                continue
            if operation == BPF_CALL:
                enqueue(pc + 1, outgoing)
                continue
            target = pc + 1 + insn.off
            if operation == BPF_JA:
                enqueue(target, outgoing)
                continue
            fallthrough = pc + 1
            constant = constants.get(insn.dst)
            if not (insn.code & 0x08) and operation in (BPF_JEQ, BPF_JNE):
                immediate = insn.imm & 0xFFFFFFFFFFFFFFFF
                if constant is not None:
                    equal = constant == immediate
                    take = equal if operation == BPF_JEQ else not equal
                    enqueue(target if take else fallthrough, outgoing)
                    continue
                taken = outgoing.copy()
                not_taken = outgoing.copy()
                if operation == BPF_JEQ:
                    taken.scalar_constants[insn.dst] = immediate
                else:
                    not_taken.scalar_constants[insn.dst] = immediate
                enqueue(target, taken)
                enqueue(fallthrough, not_taken)
                continue
            enqueue(target, outgoing.copy())
            enqueue(fallthrough, outgoing)
            continue

        if klass in (0x00, 0x04, 0x07):
            context.pop(insn.dst, None)
            packet.pop(insn.dst, None)
            constants.pop(insn.dst, None)
        enqueue(pc + 1, outgoing)

    missing = sorted(pc for pc, offsets in reached_offsets.items() if not offsets)
    if missing:
        raise ProfileError(
            "context field hint load pcs are unreachable: "
            + ",".join(str(pc) for pc in missing)
        )
    ambiguous = {
        pc: sorted(offsets)
        for pc, offsets in reached_offsets.items()
        if len(offsets) != 1
    }
    if ambiguous:
        raise ProfileError(
            "context field hint load pcs have ambiguous packet offsets: "
            + json.dumps(ambiguous, sort_keys=True)
        )
    resolved = {pc: next(iter(offsets)) for pc, offsets in reached_offsets.items()}
    for hint in hints:
        covered: set[int] = set()
        for pc in hint.load_pcs:
            start = resolved[pc]
            width = width_by_opcode[insns[pc].code]
            covered.update(range(start, start + width))
        if covered != set(range(hint.offset, hint.offset + hint.width)):
            raise ProfileError(
                "context field hint load_pcs do not cover every field byte"
            )
    return resolved


def validate_context_field_hints(
    hints: list[ContextFieldHint], insns: list[Insn]
) -> dict[int, int]:
    seen_sites: set[int] = set()
    ranges: list[tuple[str, int, int]] = []
    width_by_opcode = {0x71: 1, 0x69: 2, 0x61: 4, 0x79: 8}
    for hint in hints:
        start = hint.offset
        end = hint.offset + hint.width
        for other_kind, other_start, other_end in ranges:
            if hint.kind == other_kind and max(start, other_start) < min(
                end, other_end
            ):
                raise ProfileError("context field hints have overlapping field ranges")
        ranges.append((hint.kind, start, end))
        covered: set[int] = set()
        for pc in hint.load_pcs:
            if pc >= len(insns):
                raise ProfileError(f"context field hint load pc {pc} is out of range")
            if pc in seen_sites:
                raise ProfileError(f"context field hint load pc {pc} is reused")
            seen_sites.add(pc)
            insn = insns[pc]
            load_width = width_by_opcode.get(insn.code)
            if load_width is None:
                raise ProfileError(
                    f"context field hint load pc {pc} is not an LDX memory load"
                )
            load_start = insn.off
            load_end = load_start + load_width
            if hint.kind == "context" and (
                load_start != start
                or load_width != hint.width
            ):
                raise ProfileError(
                    "generic context hint requires exact field loads"
                )
            if hint.kind == "context" and (
                load_start < start or load_end > end
            ):
                raise ProfileError(
                    f"context field hint load pc {pc} is outside its field"
                )
            if hint.kind == "context":
                covered.update(range(load_start, load_end))
        if hint.kind == "context" and covered != set(range(start, end)):
            raise ProfileError(
                "context field hint load_pcs do not cover every field byte"
            )

    if not hints:
        return {}

    context_hints = [hint for hint in hints if hint.kind == "context"]
    if context_hints:
        expected_context_sites = {
            pc: hint for hint in context_hints for pc in hint.load_pcs
        }
        last_context_site = max(expected_context_sites)
        provenance = entry_context_provenance_by_pc(insns, last_context_site)
        for pc, hint in expected_context_sites.items():
            state = provenance[pc]
            insn = insns[pc]
            origin = None if state is None else state.context_registers.get(insn.src)
            if origin is None or origin + insn.off != hint.offset:
                raise ProfileError(
                    f"context field hint load pc {pc} lacks entry context provenance"
                )

    packet_hints = [hint for hint in hints if hint.kind == "packet"]
    if not packet_hints:
        return {}
    data_contexts = {
        (hint.context_data_offset, hint.context_data_end_offset)
        for hint in packet_hints
    }
    if len(data_contexts) != 1:
        raise ProfileError("context field hints use different packet data contexts")
    data_offset, _data_end_offset = next(iter(data_contexts))
    return validate_packet_hint_provenance(packet_hints, insns, data_offset)


def load_raw_profile(path: Path) -> dict[str, Any]:
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise ProfileError(f"cannot read raw profile {path}: {error}") from error
    root = expect_object(value, str(path))
    expect_nonnegative_int(root.get("prog_id"), "raw profile prog_id")
    per_site = root.get("per_site")
    if per_site is None:
        raise ProfileError("raw profile requires per_site")
    expect_object(per_site, "raw profile per_site")
    return root


def merge_raw_profiles(raw_profiles: list[dict[str, Any]]) -> dict[str, Any]:
    if not raw_profiles:
        raise ProfileError("at least one raw profile is required")
    prog_ids = sorted(
        expect_nonnegative_int(raw.get("prog_id"), "raw profile prog_id")
        for raw in raw_profiles
    )
    if any(prog_id == 0 for prog_id in prog_ids):
        raise ProfileError("raw profile prog_id must be positive")
    merged: dict[str, Any] = {
        "prog_id": prog_ids[0],
        "source_prog_ids": prog_ids,
        "duration_ms": max(
            expect_nonnegative_int(raw.get("duration_ms", 0), "raw profile duration_ms")
            for raw in raw_profiles
        ),
        "run_cnt_delta": sum(
            expect_nonnegative_int(raw.get("run_cnt_delta", 0), "raw profile run_cnt_delta")
            for raw in raw_profiles
        ),
        "run_time_ns_delta": sum(
            expect_nonnegative_int(
                raw.get("run_time_ns_delta", 0), "raw profile run_time_ns_delta"
            )
            for raw in raw_profiles
        ),
        "per_site": {},
    }
    per_site: dict[str, dict[str, Any]] = merged["per_site"]
    for raw in raw_profiles:
        for raw_pc, raw_site in expect_object(raw.get("per_site"), "raw profile per_site").items():
            if not isinstance(raw_pc, str) or not raw_pc.isdecimal():
                raise ProfileError("raw profile per_site keys must be decimal PCs")
            site = expect_object(raw_site, f"raw profile per_site[{raw_pc}]")
            branch_count = expect_nonnegative_int(
                site.get("branch_count"), f"raw profile per_site[{raw_pc}].branch_count"
            )
            branch_misses = expect_nonnegative_int(
                site.get("branch_misses"), f"raw profile per_site[{raw_pc}].branch_misses"
            )
            taken = expect_nonnegative_int(
                site.get("taken"), f"raw profile per_site[{raw_pc}].taken"
            )
            not_taken = expect_nonnegative_int(
                site.get("not_taken"), f"raw profile per_site[{raw_pc}].not_taken"
            )
            if taken + not_taken != branch_count:
                raise ProfileError(f"raw profile per_site[{raw_pc}] has inconsistent counters")
            out = per_site.setdefault(
                raw_pc,
                {"branch_count": 0, "branch_misses": 0, "taken": 0, "not_taken": 0},
            )
            out["branch_count"] += branch_count
            out["branch_misses"] += branch_misses
            out["taken"] += taken
            out["not_taken"] += not_taken
    for site in per_site.values():
        site["miss_rate"] = constrained_branch_miss_rate(
            site["branch_count"], site["branch_misses"]
        )

    for field_name, child_name in (("tail_call_sites", "key_counts"),):
        present = [field_name in raw for raw in raw_profiles]
        if any(present) and not all(present):
            raise ProfileError(f"{field_name} is missing from some raw profiles")
        if not any(present):
            continue
        merged_field: dict[str, dict[str, Any]] = {}
        for raw in raw_profiles:
            for raw_pc, raw_site in expect_object(raw[field_name], field_name).items():
                if not isinstance(raw_pc, str) or not raw_pc.isdecimal():
                    raise ProfileError(f"{field_name} keys must be decimal PCs")
                site = expect_object(raw_site, f"{field_name}[{raw_pc}]")
                counts = expect_count_map(site.get(child_name), f"{field_name}[{raw_pc}].{child_name}")
                observations = expect_nonnegative_int(
                    site.get("observations"), f"{field_name}[{raw_pc}].observations"
                )
                if sum(counts.values()) != observations:
                    raise ProfileError(f"{field_name}[{raw_pc}] counts disagree with observations")
                out = merged_field.setdefault(
                    raw_pc, {"observations": 0, child_name: {}}
                )
                out["observations"] += observations
                for key, count in counts.items():
                    text_key = str(key)
                    out[child_name][text_key] = out[child_name].get(text_key, 0) + count
        merged[field_name] = merged_field

    return merged


def load_bytecode(path: Path) -> list[Insn]:
    try:
        raw = path.read_bytes()
    except OSError as error:
        raise ProfileError(f"cannot read bytecode {path}: {error}") from error
    if not raw or len(raw) % 8:
        raise ProfileError("bytecode must be a non-empty multiple of 8 bytes")
    result = []
    for code, regs, off, imm in struct.iter_unpack("<BBhi", raw):
        result.append(Insn(code, regs & 0xF, regs >> 4, off, imm))
    return result


def site_counts(raw: dict[str, Any], pc: int) -> tuple[int, int, int]:
    entry = expect_object(raw["per_site"].get(str(pc)), f"per_site[{pc}]")
    branch_count = expect_nonnegative_int(
        entry.get("branch_count"), f"per_site[{pc}].branch_count"
    )
    taken = expect_nonnegative_int(entry.get("taken"), f"per_site[{pc}].taken")
    not_taken = expect_nonnegative_int(
        entry.get("not_taken"), f"per_site[{pc}].not_taken"
    )
    if taken + not_taken != branch_count:
        raise ProfileError(f"per_site[{pc}] taken+not_taken disagrees with branch_count")
    return branch_count, taken, not_taken


def conditional_branch_pcs(insns: list[Insn]) -> set[int]:
    return {
        pc
        for pc, insn in enumerate(insns)
        if insn.code & BPF_CLASS_MASK in (BPF_JMP, BPF_JMP32)
        and insn.code & BPF_OP_MASK not in (BPF_JA, BPF_CALL, BPF_EXIT)
    }


def entry_function_end(insns: list[Insn]) -> int:
    """Return the first local-subprogram PC, matching bpfopt's LLVM lifter."""
    start = len(insns)
    pc = 0
    while pc < len(insns):
        insn = insns[pc]
        target: int | None = None
        if insn.code in (BPF_CALL_INSN, BPF_CALLX_INSN) and insn.src == BPF_PSEUDO_CALL:
            target = pc + 1 + insn.imm
        elif insn.code == BPF_LD_IMM64 and insn.src == BPF_PSEUDO_FUNC:
            target = pc + 1 + insn.imm
            pc += 1
        if target is not None:
            if target < 0 or target >= len(insns):
                raise ProfileError("local subprogram target out of range")
            start = min(start, target)
        pc += 1
    return start


def single_latch_natural_loops(insns: list[Insn]) -> dict[int, int]:
    """Return {header_pc: latch_pc} for reachable single-latch entry loops."""
    limit = entry_function_end(insns)
    if limit == 0:
        return {}

    def successors(pc: int) -> tuple[int, ...]:
        insn = insns[pc]
        if insn.code == BPF_LD_IMM64:
            target = pc + 2
            return (target,) if target < limit else ()
        klass = insn.code & BPF_CLASS_MASK
        if klass not in (BPF_JMP, BPF_JMP32):
            target = pc + 1
            return (target,) if target < limit else ()
        operation = insn.code & BPF_OP_MASK
        if operation == BPF_EXIT:
            return ()
        if operation == BPF_CALL:
            target = pc + 1
            return (target,) if target < limit else ()
        target = pc + 1 + insn.off
        if target < 0 or target >= limit:
            raise ProfileError(
                f"entry CFG branch pc {pc} targets out-of-range pc {target}"
            )
        if operation == BPF_JA:
            return (target,)
        fallthrough = pc + 1
        result = [target]
        if fallthrough < limit and fallthrough != target:
            result.append(fallthrough)
        return tuple(result)

    reachable = {0}
    worklist = [0]
    edges: dict[int, tuple[int, ...]] = {}
    while worklist:
        pc = worklist.pop()
        outgoing = successors(pc)
        edges[pc] = outgoing
        for target in outgoing:
            if target not in reachable:
                reachable.add(target)
                worklist.append(target)

    predecessors = {pc: set() for pc in reachable}
    for pc, outgoing in edges.items():
        for target in outgoing:
            if target in predecessors:
                predecessors[target].add(pc)

    dominators = {
        pc: ({0} if pc == 0 else set(reachable))
        for pc in reachable
    }
    changed = True
    while changed:
        changed = False
        for pc in sorted(reachable - {0}):
            incoming = predecessors[pc]
            if not incoming:
                updated = {pc}
            else:
                shared = set(reachable)
                for predecessor in incoming:
                    shared.intersection_update(dominators[predecessor])
                updated = shared | {pc}
            if updated != dominators[pc]:
                dominators[pc] = updated
                changed = True

    latches_by_header: dict[int, list[int]] = {}
    for latch_pc in sorted(reachable):
        insn = insns[latch_pc]
        klass = insn.code & BPF_CLASS_MASK
        operation = insn.code & BPF_OP_MASK
        if (
            klass not in (BPF_JMP, BPF_JMP32)
            or operation in (BPF_JA, BPF_CALL, BPF_EXIT)
            or insn.off >= 0
        ):
            continue
        header_pc = latch_pc + 1 + insn.off
        if header_pc in dominators[latch_pc]:
            latches_by_header.setdefault(header_pc, []).append(latch_pc)

    return {
        header_pc: latches[0]
        for header_pc, latches in sorted(latches_by_header.items())
        if len(latches) == 1
    }


def common_profile(pass_name: str, program_hash: str, raw: dict[str, Any]) -> dict[str, Any]:
    profile = {
        "schema_version": 1,
        "pass": pass_name,
        "program_hash": program_hash.lower(),
        "source_prog_id": raw["prog_id"],
    }
    if "source_prog_ids" in raw:
        profile["source_prog_ids"] = list(raw["source_prog_ids"])
    return profile


def build_tail_profile(
    raw: dict[str, Any], insns: list[Insn], program_hash: str, admission: Admission
) -> dict[str, Any]:
    candidates: list[tuple[int, int, int, int]] = []
    entry_end = entry_function_end(insns)
    if "tail_call_sites" not in raw:
        raise ProfileError("tail_call_icache requires collected tail_call_sites")
    sites = expect_object(raw["tail_call_sites"], "tail_call_sites")
    for raw_pc, raw_site in sites.items():
        if not isinstance(raw_pc, str) or not raw_pc.isdecimal():
            raise ProfileError("tail_call_sites keys must be decimal PCs")
        pc = int(raw_pc)
        site = expect_object(raw_site, f"tail_call_sites[{pc}]")
        key_counts = expect_count_map(site.get("key_counts"), f"tail_call_sites[{pc}].key_counts")
        observations = sum(key_counts.values())
        declared = expect_nonnegative_int(
            site.get("observations"), f"tail_call_sites[{pc}].observations"
        )
        if observations != declared:
            raise ProfileError(f"tail_call_sites[{pc}] key counts disagree with observations")
        if pc >= entry_end:
            continue
        hot_key, hot_count = max(key_counts.items(), key=lambda item: (item[1], -item[0]))
        if hot_key > 0xFFFFFFFF:
            raise ProfileError(f"tail_call_sites[{pc}] hot key exceeds u32")
        if (
            pc > 0
            and pc < len(insns)
            and insns[pc].code == 0x85
            and insns[pc].src != BPF_PSEUDO_CALL
            and insns[pc].imm == 12
        ):
            key_def = insns[pc - 1]
            if key_def.code in (BPF_MOV32_K, BPF_MOV64_K) and key_def.dst == 3:
                static_key = key_def.imm & 0xFFFFFFFF
                observed_keys = set(key_counts)
                if observed_keys != {static_key}:
                    raise ProfileError(
                        f"tail_call_sites[{pc}] PMU keys {sorted(observed_keys)} "
                        f"contradict static key {static_key}"
                    )
                # The stock verifier/JIT already sees a constant program-array
                # key. Re-emitting the same MOV is not a specialization.
                continue
        if admission.admits(observations, hot_count):
            candidates.append((hot_count, observations, pc, hot_key))
    candidates.sort(key=lambda item: (-item[0], -item[1], item[2], item[3]))
    profile = common_profile("tail_call_icache", program_hash, raw)
    profile["per_site"] = {
        str(pc): {
            "hot_key": hot_key,
            "observations": observations,
            "hot_count": hot_count,
        }
        for hot_count, observations, pc, hot_key in candidates[: admission.max_tail_sites]
    }
    return profile


def build_hot_region_profile(
    raw: dict[str, Any], insns: list[Insn], program_hash: str, admission: Admission
) -> dict[str, Any]:
    candidates: list[tuple[int, int, int, int]] = []
    entry_end = entry_function_end(insns)
    for raw_pc in expect_object(raw["per_site"], "per_site"):
        if not isinstance(raw_pc, str) or not raw_pc.isdecimal():
            raise ProfileError("per_site keys must be decimal PCs")
        pc = int(raw_pc)
        observations, taken, not_taken = site_counts(raw, pc)
        if pc >= entry_end:
            continue
        hot_count = max(taken, not_taken)
        if taken != not_taken and admission.admits(observations, hot_count):
            candidates.append((hot_count, observations, pc, taken))
    candidates.sort(key=lambda item: (-item[0], -item[1], item[2]))
    profile = common_profile("hot_region_version", program_hash, raw)
    profile["per_site"] = {}
    if candidates:
        _, observations, pc, taken = candidates[0]
        profile["per_site"][str(pc)] = {
            "branch_count": observations,
            "taken": taken,
            "not_taken": observations - taken,
        }
    return profile


def build_loop_profile(
    raw: dict[str, Any], insns: list[Insn], program_hash: str, admission: Admission
) -> dict[str, Any]:
    # A conditional backward edge is a raw BPF loop latch. PMU LBR samples
    # attribute the target edge to `taken` and the exit/fallthrough edge to
    # `not_taken`. For a latch-tested loop, (backedges + exits) / exits is the
    # sampled mean trip count. This is intentionally an estimate from PMU
    # observations; no temporary BPF program or telemetry map is installed.
    candidates: list[tuple[int, int, int, int, int]] = []
    for header_pc, latch_pc in single_latch_natural_loops(insns).items():
        if str(latch_pc) not in raw["per_site"]:
            continue
        observations, backedge_count, exit_count = site_counts(raw, latch_pc)
        if observations < admission.min_observations:
            continue
        if backedge_count == 0 or exit_count == 0:
            continue
        trip_count = (observations + exit_count // 2) // exit_count
        if not 2 <= trip_count <= 127:
            continue
        candidates.append(
            (observations, backedge_count, header_pc, latch_pc, trip_count)
        )
    candidates.sort(key=lambda item: (-item[0], -item[1], item[2], item[3]))
    selected: list[tuple[int, int, int, int, int]] = []
    selected_headers: set[int] = set()
    for candidate in candidates:
        if candidate[2] in selected_headers:
            continue
        selected_headers.add(candidate[2])
        selected.append(candidate)
        if len(selected) == admission.max_loop_sites:
            break
    profile = common_profile("loop_trip_spec", program_hash, raw)
    profile["per_loop"] = {
        str(header_pc): {
            "trip_count": trip_count,
            "observations": observations,
            "backedge_count": backedge_count,
            "exit_count": observations - backedge_count,
            "latch_pc": latch_pc,
        }
        for observations, backedge_count, header_pc, latch_pc, trip_count in selected
    }
    return profile


def block_starts(insns: list[Insn]) -> set[int]:
    starts = {0}
    for pc, insn in enumerate(insns):
        if insn.code & BPF_CLASS_MASK not in (BPF_JMP, BPF_JMP32):
            continue
        if pc + 1 < len(insns):
            starts.add(pc + 1)
        operation = insn.code & BPF_OP_MASK
        if operation not in (0x80, 0x90):
            target = pc + 1 + insn.off
            if 0 <= target < len(insns):
                starts.add(target)
    return starts


def ldx_width(code: int) -> int | None:
    if code & BPF_CLASS_MASK != BPF_LDX:
        return None
    return {BPF_B: 1, BPF_H: 2, BPF_W: 4, BPF_DW: 8}.get(code & BPF_SIZE_MASK)


def context_compare_candidates(
    raw: dict[str, Any], insns: list[Insn], admission: Admission
) -> list[tuple[int, int, int, int, int, int]]:
    entry_insns = insns[:entry_function_end(insns)]
    pointer_offsets: dict[int, int] = {1: 0}
    scalar_fields: dict[int, tuple[int, int, int]] = {}
    starts = block_starts(entry_insns)
    candidates: list[tuple[int, int, int, int, int, int]] = []
    for pc, insn in enumerate(entry_insns):
        if pc in starts and pc != 0:
            pointer_offsets = {1: 0}
            scalar_fields = {}
        operation = insn.code & BPF_OP_MASK
        klass = insn.code & BPF_CLASS_MASK
        if klass in (BPF_JMP, BPF_JMP32) and operation in (BPF_JEQ, BPF_JNE) and insn.src == 0:
            field = scalar_fields.get(insn.dst)
            if field and str(pc) in raw["per_site"]:
                observations, taken, not_taken = site_counts(raw, pc)
                # Equality is proven only on JEQ's taken edge or JNE's
                # fallthrough edge. The opposite edge does not reveal a value.
                hot_count = taken if operation == BPF_JEQ else not_taken
                if admission.admits(observations, hot_count):
                    offset, width, load_pc = field
                    mask = (1 << (width * 8)) - 1
                    candidates.append(
                        (
                            hot_count,
                            observations,
                            offset,
                            width,
                            insn.imm & mask,
                            load_pc,
                        )
                    )
            continue

        width = ldx_width(insn.code)
        if width is not None:
            scalar_fields.pop(insn.dst, None)
            pointer_offsets.pop(insn.dst, None)
            if insn.src in pointer_offsets:
                offset = pointer_offsets[insn.src] + insn.off
                if offset >= 0:
                    scalar_fields[insn.dst] = (offset, width, pc)
            continue
        if insn.code == BPF_MOV64_X:
            scalar_fields.pop(insn.dst, None)
            if insn.src in pointer_offsets:
                pointer_offsets[insn.dst] = pointer_offsets[insn.src]
            else:
                pointer_offsets.pop(insn.dst, None)
            continue
        if insn.code == BPF_ADD64_K and insn.dst in pointer_offsets:
            pointer_offsets[insn.dst] += insn.imm
            continue

        # Conservative def kill for ALU/LD instructions. Store and jump
        # classes do not define dst; helper calls invalidate caller-clobbered
        # scalar provenance.
        if klass in (0x00, 0x01, 0x04, 0x07):
            pointer_offsets.pop(insn.dst, None)
            scalar_fields.pop(insn.dst, None)
        if insn.code in (0x85, 0x8D):
            for reg in range(0, 6):
                pointer_offsets.pop(reg, None)
                scalar_fields.pop(reg, None)
    return candidates


def build_context_profile(
    raw: dict[str, Any],
    insns: list[Insn],
    program_hash: str,
    admission: Admission,
    context_hints: list[ContextFieldHint] | None = None,
) -> dict[str, Any]:
    hints = context_hints or []
    candidates = context_compare_candidates(raw, insns, admission)
    candidates.sort(
        key=lambda item: (-item[0], -item[1], item[2], item[3], item[4], item[5])
    )

    def admitted_fields(group: list[ContextFieldHint]) -> list[dict[str, Any]]:
        resolved_packet_offsets = validate_context_field_hints(group, insns)
        if len(group) > admission.max_context_fields:
            raise ProfileError(
                "configured context field hints exceed max_context_fields"
            )
        selected: list[tuple[int, int, int, int, int, int]] = []
        seen_fields: set[tuple[str, int, int]] = {
            (hint.kind, hint.offset, hint.width) for hint in group
        }
        for candidate in candidates:
            if len(selected) + len(group) >= admission.max_context_fields:
                break
            identity = ("context", candidate[2], candidate[3])
            if identity in seen_fields:
                continue
            seen_fields.add(identity)
            selected.append(candidate)
        fields = []
        for hint in group:
            field = hint.to_profile_field()
            if hint.kind == "packet":
                field["load_offsets"] = [
                    resolved_packet_offsets[pc] for pc in hint.load_pcs
                ]
            fields.append(field)
        fields.extend([
            {
                "kind": "context",
                "source": "pmu_branch",
                "offset": offset,
                "width": width,
                "hot_value": hot_value,
                "observations": observations,
                "hot_count": hot_count,
                "load_pcs": [load_pc],
            }
            for hot_count, observations, offset, width, hot_value, load_pc in selected
        ])
        return fields

    profile = common_profile("context_specialize", program_hash, raw)
    versioned = [hint for hint in hints if hint.version is not None]
    if versioned:
        if len(versioned) != len(hints):
            raise ProfileError(
                "context field hints must either all specify version or all omit it"
            )
        version_ids = sorted({hint.version for hint in versioned})
        if version_ids != list(range(len(version_ids))):
            raise ProfileError(
                "context field hint versions must be contiguous starting at zero"
            )
        profile["versions"] = [
            {
                "fields": admitted_fields(
                    [hint for hint in versioned if hint.version == version]
                )
            }
            for version in version_ids
        ]
    else:
        profile["fields"] = admitted_fields(hints)
    return profile


def build_branch_flip_profile(
    raw: dict[str, Any], insns: list[Insn], program_hash: str
) -> dict[str, Any]:
    expected_pcs = conditional_branch_pcs(insns)
    raw_sites = expect_object(raw["per_site"], "per_site")
    observed_pcs: set[int] = set()
    for raw_pc in raw_sites:
        if not isinstance(raw_pc, str) or not raw_pc.isdecimal():
            raise ProfileError("per_site keys must be decimal PCs")
        observed_pcs.add(int(raw_pc))
    missing = sorted(expected_pcs - observed_pcs)
    if missing:
        raise ProfileError(
            "branch_flip PMU profile omitted conditional sites: "
            + ",".join(str(pc) for pc in missing)
        )
    extra = sorted(observed_pcs - expected_pcs)
    if extra:
        raise ProfileError(
            "branch_flip PMU profile contains non-conditional sites: "
            + ",".join(str(pc) for pc in extra)
        )
    run_cnt_delta = expect_nonnegative_int(
        raw.get("run_cnt_delta", 0), "raw profile run_cnt_delta"
    )
    observed_branches = sum(
        expect_nonnegative_int(
            expect_object(raw_sites[str(pc)], f"per_site[{pc}]").get(
                "branch_count"
            ),
            f"per_site[{pc}].branch_count",
        )
        for pc in expected_pcs
    )
    if expected_pcs and run_cnt_delta > 0 and observed_branches == 0:
        raise ProfileError(
            "branch_flip PMU profile has zero branch observations despite "
            f"run_cnt_delta={run_cnt_delta}"
        )

    profile = common_profile("branch_flip", program_hash, raw)
    profile["per_site"] = {}
    for pc in sorted(expected_pcs):
        site = expect_object(raw_sites[str(pc)], f"per_site[{pc}]")
        branch_count = expect_nonnegative_int(
            site.get("branch_count"), f"per_site[{pc}].branch_count"
        )
        branch_misses = expect_nonnegative_int(
            site.get("branch_misses"), f"per_site[{pc}].branch_misses"
        )
        taken = expect_nonnegative_int(site.get("taken"), f"per_site[{pc}].taken")
        not_taken = expect_nonnegative_int(
            site.get("not_taken"), f"per_site[{pc}].not_taken"
        )
        if taken + not_taken != branch_count:
            raise ProfileError(f"per_site[{pc}] has inconsistent counters")
        profile["per_site"][str(pc)] = {
            "branch_count": branch_count,
            "branch_misses": branch_misses,
            "miss_rate": constrained_branch_miss_rate(branch_count, branch_misses),
            "taken": taken,
            "not_taken": not_taken,
        }
    return profile


def build_profiles(
    raw: dict[str, Any],
    insns: list[Insn],
    program_hash: str,
    passes: list[str],
    admission: Admission,
    context_hints: list[ContextFieldHint] | None = None,
) -> dict[str, dict[str, Any]]:
    hints = context_hints or []
    builders = {
        "tail_call_icache": lambda: build_tail_profile(
            raw, insns, program_hash, admission
        ),
        "hot_region_version": lambda: build_hot_region_profile(
            raw, insns, program_hash, admission
        ),
        "loop_trip_spec": lambda: build_loop_profile(
            raw, insns, program_hash, admission
        ),
        "context_specialize": lambda: build_context_profile(
            raw, insns, program_hash, admission, hints
        ),
        "branch_flip": lambda: build_branch_flip_profile(
            raw, insns, program_hash
        ),
    }
    return {pass_name: builders[pass_name]() for pass_name in passes}


def write_profiles(
    output_root: Path,
    program_hash: str,
    profiles: dict[str, dict[str, Any]],
    output_stem: str | None = None,
) -> None:
    stem = output_stem or f"hash-{program_hash.lower()}"
    for pass_name, profile in profiles.items():
        directory = output_root / pass_name
        directory.mkdir(parents=True, exist_ok=True)
        path = directory / f"{stem}.json"
        path.write_text(json.dumps(profile, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--raw-profile", required=True, type=Path, action="append")
    parser.add_argument("--bytecode", required=True, type=Path)
    parser.add_argument("--program-hash", required=True)
    parser.add_argument("--output-root", required=True, type=Path)
    parser.add_argument("--output-stem")
    parser.add_argument("--pass", dest="passes", action="append", choices=PASS_NAMES, required=True)
    parser.add_argument("--min-observations", type=int, required=True)
    parser.add_argument("--min-hot-permille", type=int, required=True)
    parser.add_argument("--max-tail-sites", type=int, required=True)
    parser.add_argument("--max-loop-sites", type=int, required=True)
    parser.add_argument("--max-context-fields", type=int, required=True)
    parser.add_argument("--context-field-hint", action="append", default=[])
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        if not PROGRAM_HASH_RE.fullmatch(args.program_hash):
            raise ProfileError("--program-hash must be exactly 16 hexadecimal digits")
        if args.output_stem is not None and not OUTPUT_STEM_RE.fullmatch(
            args.output_stem
        ):
            raise ProfileError(
                "--output-stem must be hash-<16 lowercase hex> or prog-<positive id>"
            )
        limits = (
            args.min_observations,
            args.max_tail_sites,
            args.max_loop_sites,
            args.max_context_fields,
        )
        if any(value <= 0 for value in limits):
            raise ProfileError("observation and site limits must be positive")
        if not 501 <= args.min_hot_permille <= 1000:
            raise ProfileError("--min-hot-permille must be within 501..1000")
        admission = Admission(
            args.min_observations,
            args.min_hot_permille,
            args.max_tail_sites,
            args.max_loop_sites,
            args.max_context_fields,
        )
        raw = merge_raw_profiles([load_raw_profile(path) for path in args.raw_profile])
        insns = load_bytecode(args.bytecode)
        passes = list(dict.fromkeys(args.passes))
        context_hints = [
            parse_context_field_hint(raw_hint)
            for raw_hint in args.context_field_hint
        ]
        if context_hints and "context_specialize" not in passes:
            raise ProfileError(
                "--context-field-hint requires --pass context_specialize"
            )
        profiles = build_profiles(
            raw,
            insns,
            args.program_hash,
            passes,
            admission,
            context_hints,
        )
        write_profiles(
            args.output_root,
            args.program_hash,
            profiles,
            output_stem=args.output_stem,
        )
    except (ProfileError, OSError) as error:
        print(f"build_specialization_profiles: {error}", file=__import__("sys").stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
