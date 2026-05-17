"""Small frozen BPF template instantiator for the ReverseJIT JSON path.

This module is intentionally not part of the Rust loader. It is the prototype
location for verifier-facing templates that should later become fixed proof
artifacts with per-template refinement proofs.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Any


BPF_LDX = 0x01
BPF_LD = 0x00
BPF_ST = 0x02
BPF_STX = 0x03
BPF_ALU = 0x04
BPF_JMP = 0x05
BPF_ALU64 = 0x07
BPF_W = 0x00
BPF_H = 0x08
BPF_B = 0x10
BPF_DW = 0x18
BPF_IMM = 0x00
BPF_MEM = 0x60
BPF_K = 0x00
BPF_X = 0x08
BPF_ADD = 0x00
BPF_SUB = 0x10
BPF_MUL = 0x20
BPF_OR = 0x40
BPF_AND = 0x50
BPF_LSH = 0x60
BPF_RSH = 0x70
BPF_XOR = 0xA0
BPF_MOV = 0xB0
BPF_JA = 0x00
BPF_JEQ = 0x10
BPF_JGT = 0x20
BPF_JGE = 0x30
BPF_JNE = 0x50
BPF_EXIT = 0x90

BPF_REG_0 = 0
BPF_REG_1 = 1
BPF_REG_2 = 2
BPF_REG_6 = 6
BPF_REG_7 = 7
BPF_REG_8 = 8
BPF_REG_9 = 9
BPF_REG_10 = 10

X86_OP_NOP = 0x00
X86_OP_MOV_IMM = 0x01
X86_OP_MOV_REG = 0x02
X86_OP_MOV_LOAD = 0x06
X86_OP_MOV_STORE_IMM = 0x07
X86_OP_MOV_STORE_REG = 0x08
X86_OP_LEA = 0x09
X86_OP_ALU_IMM = 0x0A
X86_OP_ALU_REG = 0x0B
X86_OP_CMP_IMM = 0x0C
X86_OP_CMP_REG = 0x0D
X86_OP_TEST_IMM = 0x0E
X86_OP_CMOV = 0x15
X86_OP_SETCC = 0x16
X86_OP_CMP_MEM_IMM = 0x1D
X86_OP_CMP_MEM_REG = 0x1F
X86_OP_MOVZX_REG = 0x20
X86_OP_PUSH = 0x12
X86_OP_POP = 0x13
X86_OP_POPCNT = 0x18
X86_OP_RET = 0xFF

X86_ALU_ADD = 0
X86_ALU_XOR = 2
X86_ALU_OR = 3
X86_ALU_AND = 4
X86_ALU_SHL = 5
X86_ALU_SHR = 6
X86_ALU_IMUL = 9
X86_ALU_INC = 10
X86_ALU_NOT = 11
X86_CC_A = 7
X86_CC_B = 2
X86_CC_BE = 6
X86_CC_E = 4
X86_CC_NE = 5
X86_REG_NONE = 0xFF
X86_WIDTH_8 = 1
X86_WIDTH_16 = 2
X86_WIDTH_32 = 4
X86_WIDTH_64 = 8

X86_RAX = 0
X86_RCX = 1
X86_RDX = 2
X86_RSP = 4
X86_RBP = 5
X86_RSI = 6
X86_RDI = 7

FLOW_NORMAL = 0
FLOW_JCC = 1
FLOW_JMP = 2
FLOW_RET = 4

VALUE_BASE = -8
FLAG_CF = -264
FLAG_ZF = -272
STACK0_VALUE = -296


class UnsupportedTemplate(RuntimeError):
    pass


@dataclass
class BpfBuilder:
    insns: list[dict[str, Any]]

    def emit(self, code: int, dst: int = 0, src: int = 0, off: int = 0,
             imm: int = 0, *, label: str | None = None,
             target: str | None = None, comment: str = "") -> None:
        self.insns.append({
            "code": code & 0xFF,
            "dst": dst & 0x0F,
            "src": src & 0x0F,
            "off": off,
            "imm": imm_i32(imm),
            **({"label": label} if label else {}),
            **({"target": target} if target else {}),
            **({"comment": comment} if comment else {}),
        })

    def ld_imm64(self, dst: int, imm: int, *, label: str | None = None,
                 comment: str = "") -> None:
        value = imm & 0xFFFFFFFFFFFFFFFF
        self.emit(BPF_LD | BPF_DW | BPF_IMM, dst, 0, 0, value & 0xFFFFFFFF,
                  label=label, comment=comment)
        self.emit(0, 0, 0, 0, value >> 32)

    def ldx(self, size: int, dst: int, src: int, off: int, *, label: str | None = None,
            comment: str = "") -> None:
        self.emit(BPF_LDX | size | BPF_MEM, dst, src, off, label=label, comment=comment)

    def stx(self, size: int, dst: int, src: int, off: int, *, comment: str = "") -> None:
        self.emit(BPF_STX | size | BPF_MEM, dst, src, off, comment=comment)

    def st(self, size: int, dst: int, off: int, imm: int, *, comment: str = "") -> None:
        self.emit(BPF_ST | size | BPF_MEM, dst, 0, off, imm, comment=comment)

    def mov_imm(self, dst: int, imm: int, *, label: str | None = None,
                comment: str = "") -> None:
        self.emit(BPF_ALU64 | BPF_MOV | BPF_K, dst, 0, 0, imm, label=label, comment=comment)

    def mov_reg(self, dst: int, src: int, *, label: str | None = None,
                comment: str = "") -> None:
        self.emit(BPF_ALU64 | BPF_MOV | BPF_X, dst, src, label=label, comment=comment)

    def alu_imm(self, op: int, dst: int, imm: int, *, comment: str = "") -> None:
        self.emit(BPF_ALU64 | op | BPF_K, dst, 0, 0, imm, comment=comment)

    def alu32_imm(self, op: int, dst: int, imm: int, *, comment: str = "") -> None:
        self.emit(BPF_ALU | op | BPF_K, dst, 0, 0, imm, comment=comment)

    def alu_reg(self, op: int, dst: int, src: int, *, comment: str = "") -> None:
        self.emit(BPF_ALU64 | op | BPF_X, dst, src, comment=comment)

    def alu32_reg(self, op: int, dst: int, src: int, *, comment: str = "") -> None:
        self.emit(BPF_ALU | op | BPF_X, dst, src, comment=comment)

    def jmp_imm(self, op: int, dst: int, imm: int, target: str, *,
                comment: str = "") -> None:
        self.emit(BPF_JMP | op | BPF_K, dst, 0, 0, imm, target=target, comment=comment)

    def jmp_reg(self, op: int, dst: int, src: int, target: str, *,
                comment: str = "") -> None:
        self.emit(BPF_JMP | op | BPF_X, dst, src, target=target, comment=comment)

    def ja(self, target: str, *, comment: str = "") -> None:
        self.emit(BPF_JMP | BPF_JA, target=target, comment=comment)

    def exit(self, *, comment: str = "") -> None:
        self.emit(BPF_JMP | BPF_EXIT, comment=comment)


def build_bpf_program(records: list[dict[str, Any]]) -> dict[str, Any]:
    builder = BpfBuilder([])
    while True:
        loop_edges = infer_loop_edges(records)
        expanded = unroll_innermost_loops(records, loop_edges)
        if expanded is records:
            break
        records = expanded
    records = prune_unreachable_records(records)
    loop_edges = infer_loop_edges(records)
    loop_entries = loop_entries_by_target(records, loop_edges)
    prelude_loop_edges = [
        edge for (source, target), edge in loop_edges.items()
        if target not in loop_entries
    ]
    emit_prelude(builder, prelude_loop_edges)
    for record in label_records(records, loop_edges):
        if entry := loop_entries.get(record["index"]):
            emit_loop_entry(builder, entry)
        emit_record(builder, record)
    if any(insn.get("target") == "bpf_abort" for insn in builder.insns):
        emit_abort(builder)
    return {
        "kind": "template_instantiated_bpf_v0",
        "proof_note": (
            "Rust loader only links these BPF instructions. x86 semantics are "
            "confined to the named templates that produced them."
        ),
        "insns": builder.insns,
    }


def infer_loop_edges(records: list[dict[str, Any]]) -> dict[tuple[int, int], dict[str, int]]:
    by_index = {record["index"]: record for record in records}
    loop_edges: dict[tuple[int, int], dict[str, int]] = {}
    for record in records:
        if record.get("target_bpf_label_override"):
            continue
        if record["flow"] not in (FLOW_JCC, FLOW_JMP):
            continue
        target = record["target"]
        if target > record["index"]:
            continue
        if by_index[target]["flow"] == FLOW_RET:
            continue
        if record["flow"] == FLOW_JMP:
            bound = infer_forward_exit_loop_bound(by_index, target, record["index"])
            if bound is None:
                raise UnsupportedTemplate(f"backedge needs a static loop template: {record['asm']}")
            loop_edges[(record["index"], target)] = {
                "slot": len(loop_edges) % 4,
                "bound": bound,
                "target": int(target),
            }
            continue
        prev = find_previous_flag_cmp_imm(by_index, target, record["index"])
        if record["flow"] != FLOW_JCC or prev is None:
            raise UnsupportedTemplate(f"backedge needs a static loop template: {record['asm']}")
        if prev["op"] != X86_OP_CMP_IMM:
            raise UnsupportedTemplate(f"unsupported bounded-loop branch: {record['asm']}")
        if record["aux"] == X86_CC_NE:
            bound = prev["imm"] & 0xFFFFFFFF
        elif record["aux"] == X86_CC_A:
            bound = 64
        elif record["aux"] == X86_CC_B:
            bound = (prev["imm"] & 0xFFFFFFFF) + 1
        else:
            raise UnsupportedTemplate(f"unsupported bounded-loop branch: {record['asm']}")
        if bound == 0 or bound > 65536:
            raise UnsupportedTemplate(f"unsupported loop bound {bound}: {record['asm']}")
        loop_edges[(record["index"], target)] = {
            "slot": len(loop_edges) % 4,
            "bound": int(bound),
            "target": int(target),
        }
    return loop_edges


def prune_unreachable_records(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    by_index = {record["index"]: record for record in records}
    worklist = [0]
    seen: set[int] = set()
    while worklist:
        index = worklist.pop()
        if index in seen or index not in by_index:
            continue
        seen.add(index)
        record = by_index[index]
        if record["flow"] == FLOW_RET:
            continue
        if record["flow"] == FLOW_JCC:
            if not record.get("target_bpf_label_override"):
                worklist.append(record["target"])
            if not record.get("next_bpf_label_override"):
                worklist.append(record["next"])
        elif record["flow"] == FLOW_JMP:
            if not record.get("target_bpf_label_override"):
                worklist.append(record["target"])
        else:
            if not record.get("next_bpf_label_override"):
                worklist.append(record["next"])
    return [record for record in records if record["index"] in seen]


def find_previous_flag_cmp_imm(by_index: dict[int, dict[str, Any]],
                               loop_target: int,
                               branch_index: int) -> dict[str, Any] | None:
    for index in range(branch_index - 1, loop_target - 1, -1):
        record = by_index[index]
        if record["op"] == X86_OP_CMP_IMM:
            return record
        if record["op"] in (
            X86_OP_CMP_REG,
            X86_OP_CMP_MEM_IMM,
            X86_OP_CMP_MEM_REG,
            X86_OP_TEST_IMM,
            X86_OP_ALU_IMM,
            X86_OP_ALU_REG,
        ):
            return None
    return None


def infer_forward_exit_loop_bound(by_index: dict[int, dict[str, Any]],
                                  target: int, latch: int) -> int | None:
    for index in range(target + 1, latch):
        cmp_record = by_index.get(index - 1)
        branch = by_index.get(index)
        if cmp_record is None or branch is None:
            continue
        if cmp_record["op"] != X86_OP_CMP_IMM or branch["flow"] != FLOW_JCC:
            continue
        if branch["target"] <= latch:
            continue
        if branch["aux"] not in (X86_CC_A, X86_CC_BE, X86_CC_NE, X86_CC_E):
            continue
        imm = cmp_record["imm"] & 0xFFFFFFFF
        if imm == 0 or imm > 65536:
            continue
        return int(imm + 2)
    return None


def unroll_innermost_loops(records: list[dict[str, Any]],
                           loop_edges: dict[tuple[int, int],
                                            dict[str, int]]) -> list[dict[str, Any]]:
    if not loop_edges:
        return records
    selected_targets: set[int] = set()
    ranges = [
        (target, source, edge["bound"])
        for (source, target), edge in loop_edges.items()
    ]
    for target, source, _bound in ranges:
        for outer_target, outer_source, _outer_bound in ranges:
            if outer_target < target and source < outer_source:
                selected_targets.add(target)
    if not selected_targets:
        selected_targets = {target for _source, target in loop_edges}

    unroll_by_target = {
        target: (source, edge["bound"])
        for (source, target), edge in loop_edges.items()
        if target in selected_targets
    }
    expanded_records = sum(
        (source - target + 1) * bound
        for target, (source, bound) in unroll_by_target.items()
    )
    if expanded_records > 5000:
        return records
    tail_by_loop = {
        target: tail
        for target, (source, _bound) in unroll_by_target.items()
        if (tail := straight_return_tail(records, source + 1)) is not None
    }
    out: list[dict[str, Any]] = []
    orig_to_new: dict[int, int] = {}
    clone_to_new: dict[tuple[int, int, int], int] = {}
    clone_meta: dict[int, tuple[int, int, int, int]] = {}
    skipped: set[int] = set()
    next_index = 0
    i = 0
    by_index = {record["index"]: record for record in records}
    while i < len(records):
        record = records[i]
        index = record["index"]
        if index in skipped:
            i += 1
            continue
        if index in unroll_by_target:
            latch, bound = unroll_by_target[index]
            for iteration in range(bound):
                for orig_index in range(index, latch + 1):
                    clone = dict(by_index[orig_index])
                    clone["original_index"] = orig_index
                    clone["unrolled_iteration"] = iteration
                    clone["index"] = next_index
                    refresh_local_labels(clone, next_index)
                    clone_to_new[(index, orig_index, iteration)] = next_index
                    clone_meta[next_index] = (index, latch, bound, iteration)
                    out.append(clone)
                    next_index += 1
            skipped.update(range(index, latch + 1))
            if index in tail_by_loop:
                skipped.update(record["index"] for record in tail_by_loop[index])
            i += latch - index + 1
            continue
        clone = dict(record)
        clone["original_index"] = index
        clone["index"] = next_index
        refresh_local_labels(clone, next_index)
        orig_to_new[index] = next_index
        out.append(clone)
        next_index += 1
        i += 1

    for record in out:
        rewrite_unrolled_edges(record, orig_to_new, clone_to_new, clone_meta,
                               tail_by_loop)
    return out


def refresh_local_labels(record: dict[str, Any], index: int) -> None:
    if record.get("local_bound_abort"):
        label = bound_abort_label(index)
        record["local_bound_abort"] = {"label": label}
        record["target_bpf_label_override"] = label
    if record.get("inline_tail"):
        label = inline_tail_label(index)
        record["inline_tail"] = {
            **record["inline_tail"],
            "label": label,
        }
        record["next_bpf_label_override"] = label


def rewrite_unrolled_edges(record: dict[str, Any], orig_to_new: dict[int, int],
                           clone_to_new: dict[tuple[int, int, int], int],
                           clone_meta: dict[int, tuple[int, int, int, int]],
                           tail_by_loop: dict[int, list[dict[str, Any]]]) -> None:
    def map_dst(dst: int, *, is_target: bool) -> int:
        if record["index"] in clone_meta:
            loop_target, latch, bound, iteration = clone_meta[record["index"]]
            orig_index = record["original_index"]
            if is_target and orig_index == latch and dst == loop_target:
                if iteration + 1 < bound:
                    return clone_to_new[(loop_target, loop_target, iteration + 1)]
                record["target_bpf_label_override"] = bound_abort_label(record["index"])
                record["local_bound_abort"] = {
                    "label": bound_abort_label(record["index"]),
                }
                return dst
            if (
                not is_target
                and orig_index == latch
                and dst == latch + 1
                and loop_target in tail_by_loop
            ):
                record["next_bpf_label_override"] = inline_tail_label(record["index"])
                record["inline_tail"] = {
                    "label": inline_tail_label(record["index"]),
                    "records": tail_by_loop[loop_target],
                }
                return dst
            if loop_target <= dst <= latch:
                return clone_to_new[(loop_target, dst, iteration)]
        for (loop_target, orig_index, iteration), new_index in clone_to_new.items():
            if dst == orig_index and iteration == 0:
                return new_index
            if dst == loop_target and iteration == 0:
                return clone_to_new[(loop_target, loop_target, 0)]
        return orig_to_new.get(dst, dst)

    if record["flow"] in (FLOW_JCC, FLOW_JMP):
        record["target"] = map_dst(record["target"], is_target=True)
    if record["flow"] != FLOW_RET:
        record["next"] = map_dst(record["next"], is_target=False)


def straight_return_tail(records: list[dict[str, Any]],
                         start: int) -> list[dict[str, Any]] | None:
    by_index = {record["index"]: record for record in records}
    tail: list[dict[str, Any]] = []
    index = start
    while index in by_index:
        record = by_index[index]
        tail.append(record)
        if record["flow"] == FLOW_RET:
            return tail
        if record["flow"] != FLOW_NORMAL or record["next"] != index + 1:
            return None
        index = record["next"]
    return None


def label_records(records: list[dict[str, Any]],
                  loop_edges: dict[tuple[int, int], dict[str, int]]) -> list[dict[str, Any]]:
    by_index = {record["index"]: record for record in records}
    loop_targets = set(loop_entries_by_target(records, loop_edges))
    labeled: list[dict[str, Any]] = []
    for record in records:
        item = dict(record)
        item["bpf_label"] = x86_label(record["index"])
        if record["flow"] == FLOW_JCC:
            edge = loop_edges.get((record["index"], record["target"]))
            inline_return = is_backward_return_target(record, by_index)
            item["target_bpf_label"] = (
                record["target_bpf_label_override"]
                if record.get("target_bpf_label_override")
                else loop_guard_label(record["index"], record["target"])
                if edge is not None
                else inline_return_label(record["index"], record["target"])
                if inline_return
                else entry_or_x86_label(record["target"], loop_targets)
            )
            item["next_bpf_label"] = (
                record["next_bpf_label_override"]
                if record.get("next_bpf_label_override")
                else entry_or_x86_label(record["next"], loop_targets)
            )
            if inline_return:
                item["inline_return"] = {
                    "label": inline_return_label(record["index"], record["target"]),
                }
            if edge is not None:
                item["loop_guard"] = {
                    **edge,
                    "target_label": x86_label(record["target"]),
                    "guard_label": loop_guard_label(record["index"], record["target"]),
                }
        elif record["flow"] == FLOW_JMP:
            edge = loop_edges.get((record["index"], record["target"]))
            inline_return = is_backward_return_target(record, by_index)
            item["target_bpf_label"] = (
                record["target_bpf_label_override"]
                if record.get("target_bpf_label_override")
                else loop_guard_label(record["index"], record["target"])
                if edge is not None
                else inline_return_label(record["index"], record["target"])
                if inline_return
                else entry_or_x86_label(record["target"], loop_targets)
            )
            if inline_return:
                item["inline_return"] = {
                    "label": inline_return_label(record["index"], record["target"]),
                }
            if edge is not None:
                item["loop_guard"] = {
                    **edge,
                    "target_label": x86_label(record["target"]),
                    "guard_label": loop_guard_label(record["index"], record["target"]),
                }
        elif record["flow"] != FLOW_RET and record["next"] in by_index:
            item["next_bpf_label"] = (
                record["next_bpf_label_override"]
                if record.get("next_bpf_label_override")
                else entry_or_x86_label(record["next"], loop_targets)
            )
        labeled.append(item)
    return labeled


def loop_entries_by_target(records: list[dict[str, Any]],
                           loop_edges: dict[tuple[int, int],
                                            dict[str, int]]) -> dict[int, dict[str, int]]:
    entries: dict[int, dict[str, int]] = {}
    incoming = non_backedge_incoming_targets(records, loop_edges)
    for (_source, target), edge in loop_edges.items():
        if target not in incoming:
            continue
        if target in entries:
            raise UnsupportedTemplate(f"multiple loop latches for header {target}")
        entries[target] = edge
    return entries


def non_backedge_incoming_targets(records: list[dict[str, Any]],
                                  loop_edges: dict[tuple[int, int],
                                                   dict[str, int]]) -> set[int]:
    loop_edge_keys = set(loop_edges)
    targets: set[int] = set()
    by_index = {record["index"]: record for record in records}
    for record in records:
        successors: list[int] = []
        if record["flow"] == FLOW_JCC:
            if not record.get("target_bpf_label_override"):
                successors.append(record["target"])
            if not record.get("next_bpf_label_override"):
                successors.append(record["next"])
        elif record["flow"] == FLOW_JMP:
            if not record.get("target_bpf_label_override"):
                successors.append(record["target"])
        elif record["flow"] != FLOW_RET and not record.get("next_bpf_label_override"):
            successors.append(record["next"])
        for target in successors:
            if target in by_index and (record["index"], target) not in loop_edge_keys:
                targets.add(target)
    return targets


def entry_or_x86_label(index: int, loop_targets: set[int]) -> str:
    return loop_entry_label(index) if index in loop_targets else x86_label(index)


def x86_label(index: int) -> str:
    return f"x86_{index}"


def loop_entry_label(index: int) -> str:
    return f"x86_loop_entry_{index}"


def loop_guard_label(index: int, target: int) -> str:
    return f"x86_loop_guard_{index}_{target}"


def inline_return_label(index: int, target: int) -> str:
    return f"x86_inline_ret_{index}_{target}"


def inline_tail_label(index: int) -> str:
    return f"x86_inline_tail_{index}"


def bound_abort_label(index: int) -> str:
    return f"x86_bound_abort_{index}"


def is_backward_return_target(record: dict[str, Any],
                              by_index: dict[int, dict[str, Any]]) -> bool:
    target = record["target"]
    return target <= record["index"] and by_index[target]["flow"] == FLOW_RET


def emit_prelude(builder: BpfBuilder, prelude_loop_edges: list[dict[str, int]]) -> None:
    builder.ldx(BPF_W, BPF_REG_6, BPF_REG_1, 0, comment="xdp.data")
    builder.ldx(BPF_W, BPF_REG_7, BPF_REG_1, 4, comment="xdp.data_end")
    for reg in range(16):
        builder.mov_imm(BPF_REG_0, 0)
        builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, value_off(reg), comment=f"init vreg {reg}")
    builder.mov_imm(BPF_REG_0, 0)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_CF, comment="init cf")
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_ZF, comment="init zf")
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, STACK0_VALUE, comment="init stack0")
    for edge in prelude_loop_edges:
        builder.mov_imm(loop_fuel_reg(edge["slot"]), edge["bound"],
                        comment=f"init rotated loop fuel {edge['slot']}")


def emit_record(builder: BpfBuilder, record: dict[str, Any]) -> None:
    label = record["bpf_label"]
    flow = record["flow"]
    if flow == FLOW_JCC:
        emit_jcc(builder, record, label)
        return
    if flow == FLOW_JMP:
        builder.emit(BPF_JMP | BPF_JA, label=label,
                     target=record["target_bpf_label"], comment=record["asm"])
        if guard := record.get("loop_guard"):
            emit_loop_guard(builder, guard)
        if inline_return := record.get("inline_return"):
            emit_inline_return(builder, inline_return)
        if inline_tail := record.get("inline_tail"):
            emit_inline_tail(builder, inline_tail)
        if local_abort := record.get("local_bound_abort"):
            emit_local_abort(builder, local_abort)
        return
    if flow == FLOW_RET:
        builder.ldx(BPF_DW, BPF_REG_0, BPF_REG_10, value_off(X86_RAX), label=label,
                    comment=record["asm"])
        builder.exit(comment="return virtual rax")
        return
    if flow != FLOW_NORMAL:
        raise UnsupportedTemplate(f"unsupported flow {flow}: {record['asm']}")

    op = record["op"]
    if op == X86_OP_NOP:
        builder.mov_reg(BPF_REG_0, BPF_REG_0, label=label, comment=record["asm"])
    elif op == X86_OP_MOV_LOAD:
        emit_mov_load(builder, record, label)
    elif op == X86_OP_ALU_REG and record["aux"] == X86_ALU_XOR:
        emit_xor_reg(builder, record, label)
    elif op == X86_OP_ALU_REG:
        emit_alu_reg(builder, record, label)
    elif op == X86_OP_ALU_IMM:
        emit_alu_imm(builder, record, label)
    elif op == X86_OP_CMP_IMM:
        emit_cmp_imm(builder, record, label)
    elif op == X86_OP_CMP_REG:
        emit_cmp_reg(builder, record, label)
    elif op == X86_OP_CMP_MEM_IMM:
        emit_cmp_mem_imm(builder, record, label)
    elif op == X86_OP_CMP_MEM_REG:
        emit_cmp_mem_reg(builder, record, label)
    elif op == X86_OP_TEST_IMM:
        emit_test_imm(builder, record, label)
    elif op == X86_OP_SETCC:
        emit_setcc(builder, record, label)
    elif op == X86_OP_CMOV:
        emit_cmov(builder, record, label)
    elif op == X86_OP_LEA:
        emit_lea(builder, record, label)
    elif op == X86_OP_PUSH:
        emit_push(builder, record, label)
    elif op == X86_OP_POP:
        emit_pop(builder, record, label)
    elif op == X86_OP_MOV_REG:
        emit_mov_reg(builder, record, label)
    elif op == X86_OP_MOVZX_REG:
        emit_movzx_reg(builder, record, label)
    elif op == X86_OP_MOV_STORE_IMM:
        emit_store_imm(builder, record, label)
    elif op == X86_OP_MOV_STORE_REG:
        emit_store_reg(builder, record, label)
    elif op == X86_OP_MOV_IMM:
        emit_mov_imm(builder, record, label)
    elif op == X86_OP_POPCNT:
        emit_popcnt(builder, record, label)
    else:
        raise UnsupportedTemplate(f"unsupported template op=0x{op:x}: {record['asm']}")


def emit_loop_entry(builder: BpfBuilder, entry: dict[str, int]) -> None:
    builder.mov_imm(loop_fuel_reg(entry["slot"]), entry["bound"],
                    label=loop_entry_label(int(entry["target"])),
                    comment=f"init loop fuel {entry['slot']}")


def emit_mov_load(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    if record["src"] == X86_RDI and record["imm"] == 0:
        builder.mov_imm(BPF_REG_0, 0, label=label, comment=record["asm"])
        store_value(builder, record["dst"], BPF_REG_0)
        return
    if record["src"] == X86_RDI and record["imm"] == 8:
        builder.mov_reg(BPF_REG_0, BPF_REG_7, label=label, comment=record["asm"])
        builder.alu_reg(BPF_SUB, BPF_REG_0, BPF_REG_6)
        store_value(builder, record["dst"], BPF_REG_0)
        return
    emit_mem_load(builder, BPF_REG_0, record, label)
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])


def emit_xor_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["dst"], label=label, comment=record["asm"])
    load_value(builder, BPF_REG_8, record["src"])
    builder.alu_reg(BPF_XOR, BPF_REG_0, BPF_REG_8)
    if record["flags"] == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, BPF_REG_0, -1)
    store_value(builder, record["dst"], BPF_REG_0)
    set_flags_from_value(builder, BPF_REG_0, label)


def emit_alu_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["dst"], label=label, comment=record["asm"])
    load_value(builder, BPF_REG_8, record["src"])
    op = record["aux"]
    if op == X86_ALU_ADD:
        emit_width_alu_reg(builder, BPF_ADD, record["flags"], BPF_REG_0, BPF_REG_8)
    elif op == X86_ALU_XOR:
        emit_width_alu_reg(builder, BPF_XOR, record["flags"], BPF_REG_0, BPF_REG_8)
    elif op == X86_ALU_OR:
        emit_width_alu_reg(builder, BPF_OR, record["flags"], BPF_REG_0, BPF_REG_8)
    elif op == X86_ALU_SHL:
        emit_width_alu_reg(builder, BPF_LSH, record["flags"], BPF_REG_0, BPF_REG_8)
    elif op == X86_ALU_SHR:
        emit_width_alu_reg(builder, BPF_RSH, record["flags"], BPF_REG_0, BPF_REG_8)
    elif op == X86_ALU_IMUL:
        emit_width_alu_reg(builder, BPF_MUL, record["flags"], BPF_REG_0, BPF_REG_8)
    else:
        raise UnsupportedTemplate(f"unsupported alu_reg template: {record['asm']}")
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])
    set_flags_from_value(builder, BPF_REG_0, label)


def emit_alu_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["dst"], label=label, comment=record["asm"])
    op = record["aux"]
    imm = imm_i32(record["imm"])
    if op == X86_ALU_ADD:
        emit_width_alu_imm(builder, BPF_ADD, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_XOR:
        emit_width_alu_imm(builder, BPF_XOR, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_AND:
        emit_width_alu_imm(builder, BPF_AND, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_SHL:
        emit_width_alu_imm(builder, BPF_LSH, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_SHR:
        emit_width_alu_imm(builder, BPF_RSH, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_INC:
        emit_width_alu_imm(builder, BPF_ADD, record["flags"], BPF_REG_0, imm)
    elif op == X86_ALU_NOT:
        emit_width_alu_imm(builder, BPF_XOR, record["flags"], BPF_REG_0, -1)
    else:
        raise UnsupportedTemplate(f"unsupported alu_imm template: {record['asm']}")
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])
    set_flags_from_value(builder, BPF_REG_0, label)


def emit_cmp_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_8, record["dst"], label=label, comment=record["asm"])
    load_value(builder, BPF_REG_9, record["src"])
    emit_cmp_values(builder, BPF_REG_8, BPF_REG_9, label)


def emit_cmp_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_8, record["dst"], label=label, comment=record["asm"])
    builder.mov_imm(BPF_REG_9, imm_i32(record["imm"]))
    emit_cmp_values(builder, BPF_REG_8, BPF_REG_9, label)


def emit_cmp_mem_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    emit_mem_load(builder, BPF_REG_8, record, label)
    builder.mov_imm(BPF_REG_9, imm_i32(record["imm"] & 0xFFFFFFFF))
    emit_cmp_values(builder, BPF_REG_8, BPF_REG_9, label)


def emit_cmp_mem_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    emit_mem_load(builder, BPF_REG_8, record, label)
    load_value(builder, BPF_REG_9, record["src"])
    emit_cmp_values(builder, BPF_REG_8, BPF_REG_9, label)


def emit_test_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["dst"], label=label, comment=record["asm"])
    builder.alu_imm(BPF_AND, BPF_REG_0, imm_i32(record["imm"]))
    set_flags_from_value(builder, BPF_REG_0, label)


def emit_setcc(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    true_label = f"{label}_setcc_true"
    done_label = f"{label}_setcc_done"
    emit_cc_branch(builder, record["aux"], true_label, label, record["asm"])
    builder.mov_imm(BPF_REG_0, 0)
    builder.ja(done_label)
    builder.mov_imm(BPF_REG_0, 1, label=true_label)
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])
    builder.mov_reg(BPF_REG_0, BPF_REG_0, label=done_label)


def emit_cmov(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    skip_label = f"{label}_cmov_skip"
    if record["aux"] == X86_CC_E:
        load_flag(builder, BPF_REG_0, FLAG_ZF, label=label, comment=record["asm"])
        builder.jmp_imm(BPF_JEQ, BPF_REG_0, 0, skip_label)
    elif record["aux"] == X86_CC_NE:
        load_flag(builder, BPF_REG_0, FLAG_ZF, label=label, comment=record["asm"])
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, skip_label)
    elif record["aux"] == X86_CC_B:
        load_flag(builder, BPF_REG_0, FLAG_CF, label=label, comment=record["asm"])
        builder.jmp_imm(BPF_JEQ, BPF_REG_0, 0, skip_label)
    else:
        raise UnsupportedTemplate(f"unsupported cmov template: {record['asm']}")
    load_value(builder, BPF_REG_0, record["src"])
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])
    builder.mov_reg(BPF_REG_0, BPF_REG_0, label=skip_label)


def emit_lea(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["src"], label=label, comment=record["asm"])
    builder.alu_imm(BPF_ADD, BPF_REG_0, imm_i32(record["imm"]))
    if record["flags"] == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, BPF_REG_0, -1)
    store_value(builder, record["dst"], BPF_REG_0)


def emit_push(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["src"], label=label, comment=record["asm"])
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, saved_reg_off(record["src"]))
    load_value(builder, BPF_REG_0, X86_RSP)
    builder.alu_imm(BPF_ADD, BPF_REG_0, -8)
    store_value(builder, X86_RSP, BPF_REG_0)


def emit_pop(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    builder.ldx(BPF_DW, BPF_REG_0, BPF_REG_10, saved_reg_off(record["dst"]), label=label,
                comment=record["asm"])
    store_value(builder, record["dst"], BPF_REG_0)
    load_value(builder, BPF_REG_0, X86_RSP)
    builder.alu_imm(BPF_ADD, BPF_REG_0, 8)
    store_value(builder, X86_RSP, BPF_REG_0)


def emit_mov_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["src"], label=label, comment=record["asm"])
    if record["flags"] == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, BPF_REG_0, -1)
    store_value(builder, record["dst"], BPF_REG_0)


def emit_movzx_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["src"], label=label, comment=record["asm"])
    width = record["aux"] & 0xFF
    if width == X86_WIDTH_8:
        builder.alu_imm(BPF_AND, BPF_REG_0, 0xFF)
    elif width == X86_WIDTH_16:
        builder.alu_imm(BPF_AND, BPF_REG_0, 0xFFFF)
    elif width == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, BPF_REG_0, -1)
    else:
        raise UnsupportedTemplate(f"unsupported movzx width: {record['asm']}")
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])


def emit_store_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    if record["dst"] != X86_RCX:
        raise UnsupportedTemplate(f"prototype store template only supports [rcx+disp]: {record['asm']}")
    disp = imm_i32(record["imm"] >> 32)
    width = record["flags"]
    emit_packet_ptr(builder, BPF_REG_8, X86_RCX, X86_REG_NONE, 0, disp, width, label, record["asm"])
    builder.st(width_to_bpf_size(width), BPF_REG_8, 0, record["imm"] & 0xFFFFFFFF)


def emit_store_reg(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    disp = imm_i32(record["imm"])
    width = record["flags"]
    emit_packet_ptr(builder, BPF_REG_8, record["dst"], mem_index(record["aux"]),
                    mem_scale(record["aux"]), disp, width, label, record["asm"])
    load_value(builder, BPF_REG_0, record["src"])
    builder.stx(width_to_bpf_size(width), BPF_REG_8, BPF_REG_0, 0)


def emit_mov_imm(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    builder.mov_imm(BPF_REG_0, imm_i32(record["imm"]), label=label, comment=record["asm"])
    if record["flags"] == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, BPF_REG_0, -1)
    store_value(builder, record["dst"], BPF_REG_0)


def emit_popcnt(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    load_value(builder, BPF_REG_0, record["src"], label=label, comment=record["asm"])
    builder.mov_reg(BPF_REG_8, BPF_REG_0)
    builder.alu_imm(BPF_RSH, BPF_REG_8, 1)
    builder.ld_imm64(BPF_REG_9, 0x5555555555555555)
    builder.alu_reg(BPF_AND, BPF_REG_8, BPF_REG_9)
    builder.alu_reg(BPF_SUB, BPF_REG_0, BPF_REG_8)
    builder.mov_reg(BPF_REG_8, BPF_REG_0)
    builder.alu_imm(BPF_RSH, BPF_REG_8, 2)
    builder.ld_imm64(BPF_REG_9, 0x3333333333333333)
    builder.alu_reg(BPF_AND, BPF_REG_0, BPF_REG_9)
    builder.alu_reg(BPF_AND, BPF_REG_8, BPF_REG_9)
    builder.alu_reg(BPF_ADD, BPF_REG_0, BPF_REG_8)
    builder.mov_reg(BPF_REG_8, BPF_REG_0)
    builder.alu_imm(BPF_RSH, BPF_REG_8, 4)
    builder.alu_reg(BPF_ADD, BPF_REG_0, BPF_REG_8)
    builder.ld_imm64(BPF_REG_9, 0x0F0F0F0F0F0F0F0F)
    builder.alu_reg(BPF_AND, BPF_REG_0, BPF_REG_9)
    builder.ld_imm64(BPF_REG_9, 0x0101010101010101)
    builder.alu_reg(BPF_MUL, BPF_REG_0, BPF_REG_9)
    builder.alu_imm(BPF_RSH, BPF_REG_0, 56)
    store_value_width(builder, record["dst"], BPF_REG_0, record["flags"])
    set_flags_from_value(builder, BPF_REG_0, label)


def emit_jcc(builder: BpfBuilder, record: dict[str, Any], label: str) -> None:
    if emit_cc_branch(builder, record["aux"], record["target_bpf_label"], label, record["asm"]):
        if next_label := record.get("next_bpf_label"):
            builder.ja(next_label)
        if guard := record.get("loop_guard"):
            emit_loop_guard(builder, guard)
        if inline_return := record.get("inline_return"):
            emit_inline_return(builder, inline_return)
        if inline_tail := record.get("inline_tail"):
            emit_inline_tail(builder, inline_tail)
        if local_abort := record.get("local_bound_abort"):
            emit_local_abort(builder, local_abort)
        return
    raise UnsupportedTemplate(f"unsupported jcc template: {record['asm']}")


def emit_inline_return(builder: BpfBuilder, inline_return: dict[str, str]) -> None:
    builder.ldx(BPF_DW, BPF_REG_0, BPF_REG_10, value_off(X86_RAX),
                label=inline_return["label"], comment="inline backward ret target")
    builder.exit(comment="return virtual rax")


def emit_inline_tail(builder: BpfBuilder, inline_tail: dict[str, Any]) -> None:
    records = inline_tail["records"]
    labels = [
        str(inline_tail["label"]) if index == 0 else f"{inline_tail['label']}_{index}"
        for index in range(len(records))
    ]
    for index, record in enumerate(records):
        clone = dict(record)
        clone["bpf_label"] = labels[index]
        if clone["flow"] != FLOW_RET and index + 1 < len(labels):
            clone["next_bpf_label"] = labels[index + 1]
        emit_record(builder, clone)


def emit_local_abort(builder: BpfBuilder, local_abort: dict[str, str]) -> None:
    builder.mov_imm(BPF_REG_0, 0, label=local_abort["label"],
                    comment="bounded loop abort")
    builder.exit()


def emit_loop_guard(builder: BpfBuilder, guard: dict[str, int | str]) -> None:
    label = str(guard["guard_label"])
    out_of_fuel = f"{label}_empty"
    fuel = loop_fuel_reg(int(guard["slot"]))
    builder.mov_reg(fuel, fuel, label=label, comment=f"loop fuel {guard['slot']}")
    builder.jmp_imm(BPF_JEQ, fuel, 0, out_of_fuel)
    builder.alu_imm(BPF_ADD, fuel, -1)
    builder.ja(str(guard["target_label"]))
    builder.emit(BPF_JMP | BPF_JA, label=out_of_fuel, target="bpf_abort")


def emit_cc_branch(builder: BpfBuilder, cc: int, target: str, label: str,
                   asm: str) -> bool:
    if cc == X86_CC_A:
        next_label = f"{label}_cc_false"
        load_flag(builder, BPF_REG_0, FLAG_CF, label=label, comment=asm)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, next_label)
        load_flag(builder, BPF_REG_0, FLAG_ZF)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, next_label)
        builder.ja(target)
        builder.mov_reg(BPF_REG_0, BPF_REG_0, label=next_label)
        return True
    if cc == X86_CC_BE:
        load_flag(builder, BPF_REG_0, FLAG_CF, label=label, comment=asm)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, target)
        load_flag(builder, BPF_REG_0, FLAG_ZF)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, target)
        return True
    if cc == X86_CC_B:
        load_flag(builder, BPF_REG_0, FLAG_CF, label=label, comment=asm)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, target)
        return True
    if cc == X86_CC_NE:
        load_flag(builder, BPF_REG_0, FLAG_ZF, label=label, comment=asm)
        builder.jmp_imm(BPF_JEQ, BPF_REG_0, 0, target)
        return True
    if cc == X86_CC_E:
        load_flag(builder, BPF_REG_0, FLAG_ZF, label=label, comment=asm)
        builder.jmp_imm(BPF_JNE, BPF_REG_0, 0, target)
        return True
    return False


def emit_cmp_values(builder: BpfBuilder, lhs: int, rhs: int, prefix: str) -> None:
    not_equal = f"{prefix}_cmp_not_equal"
    no_carry = f"{prefix}_cmp_no_carry"
    builder.mov_imm(BPF_REG_0, 0)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_ZF)
    builder.jmp_reg(BPF_JNE, lhs, rhs, not_equal)
    builder.mov_imm(BPF_REG_0, 1)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_ZF)
    builder.mov_imm(BPF_REG_0, 0, label=not_equal)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_CF)
    builder.jmp_reg(BPF_JGE, lhs, rhs, no_carry)
    builder.mov_imm(BPF_REG_0, 1)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_0, FLAG_CF)
    builder.mov_reg(BPF_REG_0, BPF_REG_0, label=no_carry)


def emit_mem_load(builder: BpfBuilder, dst: int, record: dict[str, Any],
                  label: str) -> None:
    disp = imm_i32(record["imm"] >> 32) if record["op"] == X86_OP_CMP_MEM_IMM else imm_i32(record["imm"])
    width = mem_width(record["aux"]) or record["flags"]
    emit_packet_ptr(builder, BPF_REG_8, record["src"] if record["op"] == X86_OP_MOV_LOAD else record["dst"],
                    mem_index(record["aux"]), mem_scale(record["aux"]), disp,
                    width, label, record["asm"])
    builder.ldx(width_to_bpf_size(width), dst, BPF_REG_8, 0)


def emit_packet_ptr(builder: BpfBuilder, out: int, base_reg: int, index_reg: int,
                    scale_log2: int, disp: int, width: int, label: str,
                    asm: str) -> None:
    builder.mov_reg(out, BPF_REG_6, label=label, comment=asm)
    load_value(builder, BPF_REG_0, base_reg)
    builder.alu_reg(BPF_ADD, out, BPF_REG_0)
    if index_reg != X86_REG_NONE:
        load_value(builder, BPF_REG_0, index_reg)
        if scale_log2:
            builder.alu_imm(BPF_LSH, BPF_REG_0, scale_log2)
        builder.alu_reg(BPF_ADD, out, BPF_REG_0)
    if disp != 0:
        builder.alu_imm(BPF_ADD, out, disp)
    builder.mov_reg(BPF_REG_0, out)
    builder.alu_imm(BPF_ADD, BPF_REG_0, width)
    abort_label = f"{label}_mem_abort"
    ok_label = f"{label}_mem_ok"
    builder.jmp_reg(BPF_JGT, BPF_REG_0, BPF_REG_7, abort_label)
    builder.ja(ok_label)
    builder.mov_imm(BPF_REG_0, 0, label=abort_label, comment="packet bounds abort")
    builder.exit()
    builder.mov_reg(BPF_REG_0, BPF_REG_0, label=ok_label)


def emit_width_alu_imm(builder: BpfBuilder, op: int, width: int, dst: int,
                       imm: int) -> None:
    if width == X86_WIDTH_32:
        builder.alu32_imm(op, dst, imm)
    else:
        builder.alu_imm(op, dst, imm)


def emit_width_alu_reg(builder: BpfBuilder, op: int, width: int, dst: int,
                       src: int) -> None:
    if width == X86_WIDTH_32:
        builder.alu32_reg(op, dst, src)
    else:
        builder.alu_reg(op, dst, src)


def set_flags_from_value(builder: BpfBuilder, value_reg: int, prefix: str) -> None:
    nonzero = f"{prefix}_value_nonzero"
    builder.mov_imm(BPF_REG_8, 0)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_8, FLAG_CF)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_8, FLAG_ZF)
    builder.jmp_imm(BPF_JNE, value_reg, 0, nonzero)
    builder.mov_imm(BPF_REG_8, 1)
    builder.stx(BPF_DW, BPF_REG_10, BPF_REG_8, FLAG_ZF)
    builder.mov_reg(BPF_REG_8, BPF_REG_8, label=nonzero)


def emit_abort(builder: BpfBuilder) -> None:
    builder.mov_imm(BPF_REG_0, 0, label="bpf_abort", comment="XDP_ABORTED")
    builder.exit()


def load_value(builder: BpfBuilder, dst: int, reg: int, *, label: str | None = None,
               comment: str = "") -> None:
    builder.ldx(BPF_DW, dst, BPF_REG_10, value_off(reg), label=label, comment=comment)


def store_value(builder: BpfBuilder, reg: int, src: int) -> None:
    builder.stx(BPF_DW, BPF_REG_10, src, value_off(reg))


def store_value_width(builder: BpfBuilder, reg: int, src: int, width: int) -> None:
    if width == X86_WIDTH_64:
        store_value(builder, reg, src)
        return
    if width == X86_WIDTH_32:
        builder.alu32_imm(BPF_AND, src, -1)
        store_value(builder, reg, src)
        return
    if width in (X86_WIDTH_8, X86_WIDTH_16):
        mask = 0xFF if width == X86_WIDTH_8 else 0xFFFF
        load_value(builder, BPF_REG_9, reg)
        builder.alu_imm(BPF_AND, BPF_REG_9, ~mask)
        builder.alu_imm(BPF_AND, src, mask)
        builder.alu_reg(BPF_OR, src, BPF_REG_9)
        store_value(builder, reg, src)
        return
    raise UnsupportedTemplate(f"unsupported write width {width}")


def load_flag(builder: BpfBuilder, dst: int, off: int, *, label: str | None = None,
              comment: str = "") -> None:
    builder.ldx(BPF_DW, dst, BPF_REG_10, off, label=label, comment=comment)


def value_off(reg: int) -> int:
    return VALUE_BASE - reg * 8


def saved_reg_off(reg: int) -> int:
    return STACK0_VALUE - reg * 8


def loop_fuel_reg(slot: int) -> int:
    return BPF_REG_2 + slot


def mem_index(aux: int) -> int:
    return aux & 0xFF


def mem_scale(aux: int) -> int:
    return (aux >> 8) & 0xFF


def mem_width(aux: int) -> int | None:
    width = (aux >> 16) & 0xFF
    return width or None


def width_to_bpf_size(width: int) -> int:
    if width == 1:
        return BPF_B
    if width == 2:
        return BPF_H
    if width == 4:
        return BPF_W
    if width == 8:
        return BPF_DW
    raise UnsupportedTemplate(f"unsupported memory width {width}")


def imm_i32(value: int) -> int:
    value &= 0xFFFFFFFF
    if value >= 0x80000000:
        return value - 0x100000000
    return value
