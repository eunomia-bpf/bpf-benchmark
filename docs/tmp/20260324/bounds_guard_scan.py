#!/usr/bin/env python3

import json
import re
import subprocess
from collections import deque
from pathlib import Path

import yaml


ROOT = Path(__file__).resolve().parents[3]
MACRO_CORPUS = ROOT / "corpus/config/macro_corpus.yaml"
UAPI_BPF_H = ROOT / "vendor/linux-framework/include/uapi/linux/bpf.h"
FILTER_C = ROOT / "vendor/linux-framework/net/core/filter.c"


CONST = "const"
AFF = "aff"
UNK = ("unk",)


def const(v):
    return (CONST, int(v))


def aff(sym, scale, c):
    return (AFF, sym, int(scale), int(c))


def is_const(v):
    return isinstance(v, tuple) and v and v[0] == CONST


def is_aff(v):
    return isinstance(v, tuple) and v and v[0] == AFF


def expr_key(v):
    if is_const(v):
        return ("const", None, 0)
    if is_aff(v):
        return ("aff", v[1], v[2])
    return None


def expr_const(v):
    if is_const(v):
        return v[1]
    if is_aff(v):
        return v[3]
    raise ValueError(f"non-comparable expr: {v}")


def expr_add(a, b):
    if is_const(a) and is_const(b):
        return const(a[1] + b[1])
    if is_aff(a) and is_const(b):
        return aff(a[1], a[2], a[3] + b[1])
    if is_const(a) and is_aff(b):
        return aff(b[1], b[2], a[1] + b[3])
    if is_aff(a) and is_aff(b) and a[1] == b[1] and a[2] == b[2]:
        return aff(a[1], a[2], a[3] + b[3])
    return UNK


def expr_sub(a, b):
    if is_const(a) and is_const(b):
        return const(a[1] - b[1])
    if is_aff(a) and is_const(b):
        return aff(a[1], a[2], a[3] - b[1])
    return UNK


def expr_shift_left(a, imm):
    if is_const(a):
        return const(a[1] << imm)
    if is_aff(a):
        return aff(a[1], a[2] << imm, a[3] << imm)
    return UNK


def expr_plus_one(a):
    if is_const(a):
        return const(a[1] + 1)
    if is_aff(a):
        return aff(a[1], a[2], a[3] + 1)
    return UNK


def is_pkt_ptr(v):
    return isinstance(v, tuple) and v and v[0] in {"pkt_data", "ptr"}


def ptr_epoch(v):
    return v[1]


def ptr_expr(v):
    if v[0] == "pkt_data":
        return const(0)
    return v[2]


def is_pkt_end(v):
    return isinstance(v, tuple) and v and v[0] == "pkt_end"


def reg_join(a, b):
    return a if a == b else UNK


def facts_join(a, b):
    out = {}
    for root, facts_a in a.items():
        if root not in b:
            continue
        facts_b = b[root]
        common = {}
        for key, bound_a in facts_a.items():
            if key in facts_b:
                common[key] = min(bound_a, facts_b[key])
        if common:
            out[root] = common
    return out


class State:
    __slots__ = ("regs", "facts", "epoch")

    def __init__(self, regs=None, facts=None, epoch=0):
        self.regs = regs or [UNK] * 11
        self.facts = facts or {}
        self.epoch = epoch

    def copy(self):
        return State(
            regs=self.regs.copy(),
            facts={root: facts.copy() for root, facts in self.facts.items()},
            epoch=self.epoch,
        )

    def join(self, other):
        changed = False

        new_regs = [reg_join(a, b) for a, b in zip(self.regs, other.regs)]
        if new_regs != self.regs:
            self.regs = new_regs
            changed = True

        new_facts = facts_join(self.facts, other.facts)
        if new_facts != self.facts:
            self.facts = new_facts
            changed = True

        new_epoch = self.epoch if self.epoch == other.epoch else None
        if new_epoch != self.epoch:
            self.epoch = new_epoch
            changed = True

        return changed

    def add_fact(self, root, expr):
        key = expr_key(expr)
        if key is None:
            return
        cur = self.facts.setdefault(root, {})
        bound = expr_const(expr)
        if cur.get(key, -10**18) < bound:
            cur[key] = bound

    def strongest_fact(self, root, expr):
        key = expr_key(expr)
        if key is None:
            return None
        return self.facts.get(root, {}).get(key)

    def invalidate_packet(self, exact):
        self.facts = {}
        for regno, value in enumerate(self.regs):
            if is_pkt_ptr(value) or is_pkt_end(value):
                self.regs[regno] = UNK
        if exact and self.epoch is not None:
            self.epoch += 1
        else:
            self.epoch = None


INSN_RE = re.compile(r"^\s*(\d+):\s+(.*)$")
COND_RE = re.compile(
    r"^if ([rw]\d+)\s+(==|!=|>=|<=|>|<|s>=|s<=|s>|s<)\s+([rw]\d+|[-+]?0x[0-9a-f]+|[-+]?\d+)\s+goto\s+([+-]0x[0-9a-f]+|[+-]?\d+)"
)
MOV_REG_RE = re.compile(r"^([rw]\d+) = ([rw]\d+)$")
MOV_IMM_RE = re.compile(r"^([rw]\d+) = ([-+]?0x[0-9a-f]+|[-+]?\d+)( ll)?$")
LOAD_RE = re.compile(r"^([rw]\d+) = \*\((.+)\)\((.+)\)$")
ADDR_RE = re.compile(r"^([rw]\d+) ([+-]) (0x[0-9a-f]+|\d+)$")
ALU_IMM_RE = re.compile(r"^([rw]\d+)\s+([+\-]|<<|>>|&|\||\*)=\s+([-+]?0x[0-9a-f]+|[-+]?\d+)$")
ALU_REG_RE = re.compile(r"^([rw]\d+)\s+([+\-]|&|\|)=\s+([rw]\d+)$")
CALL_RE = re.compile(r"^call ([+-]?0x[0-9a-f]+|[+-]?\d+)")
GOTO_RE = re.compile(r"^goto ([+-]0x[0-9a-f]+|[+-]?\d+)")
SECTION_RE = re.compile(r"^\s*\d+\s+(\S+)\s+[0-9a-fA-F]+\s+[0-9a-fA-F]+\s+TEXT\b")


def reg_index(token):
    return int(token[1:])


def parse_int(token):
    return int(token, 0)


def load_helper_ids():
    helper_ids = {}
    for line in UAPI_BPF_H.read_text().splitlines():
        match = re.search(r"FN\(([^,]+),\s*([0-9]+),", line)
        if match:
            helper_ids[int(match.group(2))] = match.group(1)
    return helper_ids


def load_mutating_helper_names():
    names = set()
    in_switch = False
    for line in FILTER_C.read_text().splitlines():
        if "bool bpf_helper_changes_pkt_data" in line:
            in_switch = True
            continue
        if not in_switch:
            continue
        match = re.search(r"case BPF_FUNC_([A-Za-z0-9_]+):", line)
        if match:
            names.add(match.group(1))
        if "default:" in line:
            break
    return names


def selected_corpus_files():
    with MACRO_CORPUS.open() as handle:
        data = yaml.safe_load(handle)
    files = {}
    for prog in data["programs"]:
        family = prog.get("family")
        source = prog.get("source")
        if family not in {"cilium", "katran", "xdp-tools"}:
            continue
        files[source] = family
    return files


def program_sections(path):
    out = subprocess.check_output(["llvm-objdump", "-h", str(path)], text=True)
    sections = []
    for line in out.splitlines():
        match = SECTION_RE.match(line)
        if not match:
            continue
        section = match.group(1)
        if section.startswith("xdp") or section.startswith("tc"):
            sections.append(section)
    return sections


def disassemble(path, section):
    out = subprocess.check_output(
        ["llvm-objdump", "-dr", "--no-show-raw-insn", f"--section={section}", str(path)],
        text=True,
    )
    insns = []
    for line in out.splitlines():
        if "R_BPF_" in line:
            continue
        match = INSN_RE.match(line)
        if not match:
            continue
        idx = int(match.group(1))
        text = match.group(2).strip()
        insns.append((idx, text))
    return insns


def parse_load(text):
    match = LOAD_RE.match(text)
    if not match:
        return None
    dst = reg_index(match.group(1))
    addr = match.group(3)
    addr_match = ADDR_RE.match(addr)
    if not addr_match:
        return None
    base = reg_index(addr_match.group(1))
    off = parse_int(addr_match.group(3))
    if addr_match.group(2) == "-":
        off = -off
    return dst, base, off


def transfer_reg_alu_imm(value, op, imm):
    if is_pkt_ptr(value):
        if value[0] == "pkt_data":
            base = const(0)
        else:
            base = value[2]
        if op == "+":
            return ("ptr", value[1], expr_add(base, const(imm)))
        if op == "-":
            return ("ptr", value[1], expr_sub(base, const(imm)))
        return UNK

    if is_const(value) or is_aff(value):
        if op == "+":
            return expr_add(value, const(imm))
        if op == "-":
            return expr_sub(value, const(imm))
        if op == "<<":
            return expr_shift_left(value, imm)
        if is_const(value):
            if op == ">>":
                return const((value[1] % (1 << 64)) >> imm)
            if op == "&":
                return const(value[1] & imm)
            if op == "|":
                return const(value[1] | imm)
            if op == "*":
                return const(value[1] * imm)
    return UNK


def transfer_reg_alu_reg(dst_value, op, src_value):
    if is_pkt_ptr(dst_value):
        if dst_value[0] == "pkt_data":
            base = const(0)
        else:
            base = dst_value[2]
        if is_const(src_value) or is_aff(src_value):
            if op == "+":
                return ("ptr", dst_value[1], expr_add(base, src_value))
            if op == "-":
                return ("ptr", dst_value[1], expr_sub(base, src_value))
        return UNK

    if (is_const(dst_value) or is_aff(dst_value)) and (is_const(src_value) or is_aff(src_value)):
        if op == "+":
            return expr_add(dst_value, src_value)
        if op == "-":
            return expr_sub(dst_value, src_value)
        if op in {"&", "|"} and is_const(dst_value) and is_const(src_value):
            if op == "&":
                return const(dst_value[1] & src_value[1])
            return const(dst_value[1] | src_value[1])
    return UNK


def classify_guard(op, left, right):
    def classify(ptr_value, end_value, direction):
        if not is_pkt_ptr(ptr_value) or not is_pkt_end(end_value):
            return None
        if ptr_epoch(ptr_value) != end_value[1]:
            return None
        expr = ptr_expr(ptr_value)
        if direction == "ptr_left":
            if op == ">":
                return "fall", ptr_value[1], expr
            if op == ">=":
                return "fall", ptr_value[1], expr_plus_one(expr)
            if op == "<":
                return "jump", ptr_value[1], expr_plus_one(expr)
            if op == "<=":
                return "jump", ptr_value[1], expr
        if direction == "end_left":
            if op == ">":
                return "jump", ptr_value[1], expr_plus_one(expr)
            if op == ">=":
                return "jump", ptr_value[1], expr
            if op == "<":
                return "fall", ptr_value[1], expr
            if op == "<=":
                return "fall", ptr_value[1], expr_plus_one(expr)
        return None

    out = classify(left, right, "ptr_left")
    if out is not None:
        return out
    return classify(right, left, "end_left")


def analyze_section(path, family, section, helper_ids, mutating_helper_ids):
    insns = disassemble(path, section)
    if not insns:
        return None

    prog_type = "xdp" if section.startswith("xdp") else "tc"
    data_off = 0 if prog_type == "xdp" else 0x4C
    end_off = 4 if prog_type == "xdp" else 0x50

    idxs = [idx for idx, _ in insns]
    position = {idx: pos for pos, idx in enumerate(idxs)}
    next_idx = {idxs[pos]: (idxs[pos + 1] if pos + 1 < len(idxs) else None) for pos in range(len(idxs))}

    entry = State()
    entry.regs[1] = ("ctx",)
    entry.regs[10] = ("fp",)

    in_states = {idxs[0]: entry}
    queue = deque([idxs[0]])

    seen_site = set()
    sites = []

    def merge_to(target, state):
        if target is None:
            return
        if target not in in_states:
            in_states[target] = state
            queue.append(target)
            return
        current = in_states[target]
        if current.join(state):
            queue.append(target)

    while queue:
        idx = queue.popleft()
        state = in_states[idx].copy()
        text = insns[position[idx]][1]

        match = MOV_REG_RE.match(text)
        if match:
            dst, src = reg_index(match.group(1)), reg_index(match.group(2))
            state.regs[dst] = state.regs[src]
            merge_to(next_idx[idx], state)
            continue

        match = MOV_IMM_RE.match(text)
        if match:
            dst = reg_index(match.group(1))
            state.regs[dst] = const(parse_int(match.group(2)))
            merge_to(next_idx[idx], state)
            continue

        parsed_load = parse_load(text)
        if parsed_load is not None:
            dst, base, off = parsed_load
            base_value = state.regs[base]
            if base_value == ("ctx",) and off == data_off:
                state.regs[dst] = ("pkt_data", state.epoch)
            elif base_value == ("ctx",) and off == end_off:
                state.regs[dst] = ("pkt_end", state.epoch)
            elif is_pkt_ptr(base_value):
                state.regs[dst] = aff(f"load@{section}:{idx}", 1, 0)
            else:
                state.regs[dst] = UNK
            merge_to(next_idx[idx], state)
            continue

        match = ALU_IMM_RE.match(text)
        if match:
            dst = reg_index(match.group(1))
            op = match.group(2)
            imm = parse_int(match.group(3))
            state.regs[dst] = transfer_reg_alu_imm(state.regs[dst], op, imm)
            merge_to(next_idx[idx], state)
            continue

        match = ALU_REG_RE.match(text)
        if match:
            dst = reg_index(match.group(1))
            op = match.group(2)
            src = reg_index(match.group(3))
            state.regs[dst] = transfer_reg_alu_reg(state.regs[dst], op, state.regs[src])
            merge_to(next_idx[idx], state)
            continue

        match = CALL_RE.match(text)
        if match:
            call_imm = parse_int(match.group(1))
            for regno in range(6):
                state.regs[regno] = UNK
            if call_imm < 0:
                state.invalidate_packet(exact=False)
            elif call_imm in mutating_helper_ids:
                state.invalidate_packet(exact=True)
            merge_to(next_idx[idx], state)
            continue

        match = GOTO_RE.match(text)
        if match:
            target = idx + 1 + parse_int(match.group(1))
            merge_to(target, state)
            continue

        match = COND_RE.match(text)
        if match:
            left = state.regs[reg_index(match.group(1))]
            op = match.group(2)
            raw_right = match.group(3)
            if raw_right.startswith(("r", "w")):
                right = state.regs[reg_index(raw_right)]
            else:
                right = const(parse_int(raw_right))

            target = idx + 1 + parse_int(match.group(4))
            fallthrough = next_idx[idx]

            guard = classify_guard(op, left, right)
            if guard is not None:
                safe_edge, root, expr = guard
                existing = state.strongest_fact(root, expr)
                comparable = expr_key(expr) is not None
                redundant = comparable and existing is not None and existing >= expr_const(expr)

                key = (str(path), section, idx)
                if key not in seen_site:
                    seen_site.add(key)
                    sites.append(
                        {
                            "idx": idx,
                            "text": text,
                            "safe_edge": safe_edge,
                            "root": root,
                            "expr": expr,
                            "comparable": comparable,
                            "redundant": redundant,
                        }
                    )

                jump_state = state.copy()
                fall_state = state.copy()
                if safe_edge == "jump":
                    jump_state.add_fact(root, expr)
                else:
                    fall_state.add_fact(root, expr)
                merge_to(target, jump_state)
                merge_to(fallthrough, fall_state)
            else:
                merge_to(target, state.copy())
                merge_to(fallthrough, state)
            continue

        if text == "exit":
            continue

        merge_to(next_idx[idx], state)

    guards = len(sites)
    comparable = sum(1 for site in sites if site["comparable"])
    redundant = sum(1 for site in sites if site["redundant"])
    return {
        "family": family,
        "path": str(path.relative_to(ROOT)),
        "section": section,
        "prog_type": prog_type,
        "guards": guards,
        "comparable_guards": comparable,
        "redundant_guards": redundant,
        "sites": sites,
    }


def summarize(results):
    families = {}
    prog_types = {}
    total = {"sections": 0, "guards": 0, "comparable_guards": 0, "redundant_guards": 0}

    def add_bucket(bucket, key, result):
        entry = bucket.setdefault(
            key,
            {"sections": 0, "guards": 0, "comparable_guards": 0, "redundant_guards": 0},
        )
        entry["sections"] += 1
        entry["guards"] += result["guards"]
        entry["comparable_guards"] += result["comparable_guards"]
        entry["redundant_guards"] += result["redundant_guards"]

    for result in results:
        total["sections"] += 1
        total["guards"] += result["guards"]
        total["comparable_guards"] += result["comparable_guards"]
        total["redundant_guards"] += result["redundant_guards"]
        add_bucket(families, result["family"], result)
        add_bucket(prog_types, result["prog_type"], result)

    return {"total": total, "families": families, "prog_types": prog_types}


def main():
    helper_ids = load_helper_ids()
    mutating_names = load_mutating_helper_names()
    mutating_helper_ids = {helper_id for helper_id, name in helper_ids.items() if name in mutating_names}

    files = selected_corpus_files()
    results = []
    for rel_path, family in sorted(files.items()):
        path = ROOT / rel_path
        for section in program_sections(path):
            result = analyze_section(path, family, section, helper_ids, mutating_helper_ids)
            if result is not None:
                results.append(result)

    payload = {"summary": summarize(results), "sections": results}
    print(json.dumps(payload, indent=2))


if __name__ == "__main__":
    main()
