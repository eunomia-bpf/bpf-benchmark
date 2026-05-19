#!/usr/bin/env python3
"""Generate ReverseSim JSON proof definitions from micro Native ASM blocks.

This is intentionally separate from generate_micro_sim_proofs.py, which emits
generated .bpf.c sources. This script only writes JSON artifacts for the planned
bytecode-linker path: C owns simulator/template semantics, Python only records
the fixed native instruction stream, and the loader later links those records
with verifier-visible BPF template bytecode.
"""

from __future__ import annotations

import argparse
import ast
import json
import re
from pathlib import Path
from typing import Any

import generate_micro_sim_proofs as cgen


REPO_ROOT = Path(__file__).resolve().parents[3]
MICRO_PROGRAMS = REPO_ROOT / "micro" / "programs"
OUT_DIR = Path(__file__).resolve().parent / "build" / "json-proofs"
SCHEMA = "reversesim.x86.micro-proof.v0"
FLOW_NORMAL = 0
FLOW_JCC = 1
FLOW_JMP = 2
FLOW_CALL = 3
FLOW_RET = 4
SIMULATOR_STEP = "x86_sim_step"

NUMERIC_CONSTS = {
    "X86_OP_NOP": 0x00,
    "X86_OP_MOV_IMM": 0x01,
    "X86_OP_MOV_REG": 0x02,
    "X86_OP_ADD_IMM": 0x03,
    "X86_OP_ADD_REG": 0x04,
    "X86_OP_XOR_REG": 0x05,
    "X86_OP_MOV_LOAD": 0x06,
    "X86_OP_MOV_STORE_IMM": 0x07,
    "X86_OP_MOV_STORE_REG": 0x08,
    "X86_OP_LEA": 0x09,
    "X86_OP_ALU_IMM": 0x0A,
    "X86_OP_ALU_REG": 0x0B,
    "X86_OP_CMP_IMM": 0x0C,
    "X86_OP_CMP_REG": 0x0D,
    "X86_OP_TEST_IMM": 0x0E,
    "X86_OP_TEST_REG": 0x0F,
    "X86_OP_JCC": 0x10,
    "X86_OP_JMP": 0x11,
    "X86_OP_PUSH": 0x12,
    "X86_OP_POP": 0x13,
    "X86_OP_CALL": 0x14,
    "X86_OP_CMOV": 0x15,
    "X86_OP_SETCC": 0x16,
    "X86_OP_BSWAP": 0x17,
    "X86_OP_POPCNT": 0x18,
    "X86_OP_XCHG": 0x19,
    "X86_OP_DIV": 0x1A,
    "X86_OP_SHLD_IMM": 0x1B,
    "X86_OP_SHRD_IMM": 0x1C,
    "X86_OP_CMP_MEM_IMM": 0x1D,
    "X86_OP_TEST_MEM_IMM": 0x1E,
    "X86_OP_CMP_MEM_REG": 0x1F,
    "X86_OP_MOVZX_REG": 0x20,
    "X86_OP_MOVSX_REG": 0x21,
    "X86_OP_MOVSX_LOAD": 0x22,
    "X86_OP_ALU_MEM": 0x23,
    "X86_OP_RET": 0xFF,
    "X86_OP_MOV_IMM64": 0x01,
    "X86_OP_MOV_REG64": 0x02,
    "X86_OP_ADD_IMM64": 0x03,
    "X86_OP_ADD_REG64": 0x04,
    "X86_OP_XOR_REG32": 0x05,
    "X86_ALU_ADD": 0,
    "X86_ALU_SUB": 1,
    "X86_ALU_XOR": 2,
    "X86_ALU_OR": 3,
    "X86_ALU_AND": 4,
    "X86_ALU_SHL": 5,
    "X86_ALU_SHR": 6,
    "X86_ALU_SAR": 7,
    "X86_ALU_ROL": 8,
    "X86_ALU_IMUL": 9,
    "X86_ALU_INC": 10,
    "X86_ALU_NOT": 11,
    "X86_ALU_SBB": 12,
    "X86_CC_O": 0,
    "X86_CC_NO": 1,
    "X86_CC_B": 2,
    "X86_CC_AE": 3,
    "X86_CC_E": 4,
    "X86_CC_NE": 5,
    "X86_CC_BE": 6,
    "X86_CC_A": 7,
    "X86_CC_S": 8,
    "X86_CC_NS": 9,
    "X86_CC_L": 12,
    "X86_CC_GE": 13,
    "X86_CC_LE": 14,
    "X86_CC_G": 15,
    "X86_WIDTH_8": 1,
    "X86_WIDTH_16": 2,
    "X86_WIDTH_32": 4,
    "X86_WIDTH_64": 8,
    "X86_RAX": 0,
    "X86_RCX": 1,
    "X86_RDX": 2,
    "X86_RBX": 3,
    "X86_RSP": 4,
    "X86_RBP": 5,
    "X86_RSI": 6,
    "X86_RDI": 7,
    "X86_R8": 8,
    "X86_R9": 9,
    "X86_R10": 10,
    "X86_R11": 11,
    "X86_R12": 12,
    "X86_R13": 13,
    "X86_R14": 14,
    "X86_R15": 15,
    "X86_REG_NONE": 0xFF,
    "X86_PTR_RODATA": 4,
}


def eval_numeric(expr: str) -> int:
    text = expr.strip().removesuffix("ULL")
    text = re.sub(
        r"X86_MEM_AUX_FULL\(([^,]+),\s*([^,]+),\s*([^)]+)\)",
        lambda m: str(
            (eval_numeric(m.group(1)) & 0xFF)
            | ((eval_numeric(m.group(2)) & 0xFF) << 8)
            | ((eval_numeric(m.group(3)) & 0xFF) << 16)
        ),
        text,
    )
    text = re.sub(
        r"X86_MEM_AUX\(([^,]+),\s*([^)]+)\)",
        lambda m: str(
            (eval_numeric(m.group(1)) & 0xFF)
            | ((eval_numeric(m.group(2)) & 0xFF) << 8)
        ),
        text,
    )
    text = re.sub(
        r"X86_REG_AUX_SRC_SHIFT\(([^)]+)\)",
        lambda m: str((eval_numeric(m.group(1)) & 0xFF) << 24),
        text,
    )
    text = re.sub(
        r"X86_MEM_AUX_ALU_OP\(([^)]+)\)",
        lambda m: str((eval_numeric(m.group(1)) & 0xFF) << 24),
        text,
    )
    for name, value in sorted(NUMERIC_CONSTS.items(), key=lambda item: -len(item[0])):
        text = re.sub(rf"\b{name}\b", str(value), text)
    tree = ast.parse(text, mode="eval")
    allowed = (
        ast.Expression,
        ast.BinOp,
        ast.UnaryOp,
        ast.Constant,
        ast.Add,
        ast.Sub,
        ast.BitOr,
        ast.BitAnd,
        ast.LShift,
        ast.RShift,
        ast.USub,
        ast.UAdd,
    )
    if not all(isinstance(node, allowed) for node in ast.walk(tree)):
        raise ValueError(f"unsafe numeric expression: {expr}")
    return int(eval(compile(tree, "<numeric-expr>", "eval"), {"__builtins__": {}}, {})) & 0xFFFFFFFFFFFFFFFF


def feature_flags(functions: dict[str, list[cgen.NativeInsn]]) -> dict[str, bool]:
    all_insns = [insn for insns in functions.values() for insn in insns]
    return {
        "rodata": any("[rip" in insn.raw.lower() for insn in all_insns),
        "native_stack": any(
            insn.mnemonic in {"push", "pop"}
            or "[rsp" in insn.raw.lower()
            or "[rbp" in insn.raw.lower()
            for insn in all_insns
        ),
        "native_calls": any(insn.mnemonic == "call" for insn in all_insns),
        "conditional_branches": any(
            insn.mnemonic in cgen.CC_AUX and insn.mnemonic.startswith("j")
            for insn in all_insns
        ),
    }


def branch_target(insn: cgen.NativeInsn) -> str | None:
    if not insn.operands:
        return None
    target = cgen.branch_target(insn.operands[0])
    if target == 0:
        return None
    return f"0x{target:x}"


def control_flow(insn: cgen.NativeInsn, encoded: cgen.EncodedInsn) -> dict[str, Any] | None:
    if insn.mnemonic in cgen.CC_AUX and insn.mnemonic.startswith("j"):
        return {
            "kind": "conditional_branch",
            "condition": encoded.aux,
            "target": branch_target(insn),
        }
    if insn.mnemonic == "jmp":
        return {"kind": "branch", "target": branch_target(insn)}
    if insn.mnemonic == "call":
        return {
            "kind": "call",
            "target": branch_target(insn),
            "symbol": cgen.call_symbol(insn),
        }
    if insn.mnemonic == "ret":
        return {"kind": "return"}
    return None


def encoded_insn(function: str, index: int, insn: cgen.NativeInsn) -> dict[str, Any]:
    encoded = cgen.encode(insn)
    entry: dict[str, Any] = {
        "index": index,
        "addr": f"0x{insn.addr:x}",
        "label": f"x86_l_{insn.addr:x}",
        "asm": insn.raw,
        "mnemonic": insn.mnemonic,
        "operands": list(insn.operands),
        "helper": SIMULATOR_STEP,
        "op": encoded.op,
        "dst": encoded.dst,
        "src": encoded.src,
        "flags": encoded.flags,
        "aux": encoded.aux,
        "imm": encoded.imm,
        "fragment": {
            "kind": "simulator_step",
            "function": function,
            "helper_symbol": SIMULATOR_STEP,
            "argument_record": {
                "op": encoded.op,
                "dst": encoded.dst,
                "src": encoded.src,
                "flags": encoded.flags,
                "aux": encoded.aux,
                "imm": encoded.imm,
            },
            "numeric_record": {
                "op": eval_numeric(encoded.op) & 0xFF,
                "dst": eval_numeric(encoded.dst) & 0xFF,
                "src": eval_numeric(encoded.src) & 0xFF,
                "flags": eval_numeric(encoded.flags) & 0xFF,
                "aux": eval_numeric(encoded.aux) & 0xFFFFFFFF,
                "imm": eval_numeric(encoded.imm),
            },
        },
    }
    flow = control_flow(insn, encoded)
    if flow is not None:
        entry["control_flow"] = flow
    return entry


def function_artifact(name: str, role: str,
                      insns: list[cgen.NativeInsn]) -> dict[str, Any]:
    return {
        "name": name,
        "role": role,
        "labels": {f"x86_l_{insn.addr:x}": index for index, insn in enumerate(insns)},
        "insns": [
            encoded_insn(name, index, insn)
            for index, insn in enumerate(insns)
        ],
    }


def linked_program(functions: dict[str, list[cgen.NativeInsn]],
                   entry_name: str) -> dict[str, Any]:
    flat: list[tuple[str, str, cgen.NativeInsn]] = []
    for symbol, insns in functions.items():
        role = "entry" if symbol == entry_name else "subprogram"
        flat.extend((symbol, role, insn) for insn in insns)

    index_by_addr = {insn.addr: index for index, (_sym, _role, insn) in enumerate(flat)}
    records: list[dict[str, Any]] = []
    for index, (symbol, role, insn) in enumerate(flat):
        encoded = cgen.encode(insn)
        numeric = {
            "op": eval_numeric(encoded.op) & 0xFF,
            "dst": eval_numeric(encoded.dst) & 0xFF,
            "src": eval_numeric(encoded.src) & 0xFF,
            "flags": eval_numeric(encoded.flags) & 0xFF,
            "aux": eval_numeric(encoded.aux) & 0xFFFFFFFF,
            "imm": eval_numeric(encoded.imm),
        }
        flow = FLOW_NORMAL
        target = index + 1
        if insn.mnemonic in cgen.CC_AUX and insn.mnemonic.startswith("j"):
            flow = FLOW_JCC
            target = index_by_addr[cgen.branch_target(insn.operands[0])]
        elif insn.mnemonic == "jmp":
            flow = FLOW_JMP
            target = index_by_addr[cgen.branch_target(insn.operands[0])]
        elif insn.mnemonic == "call":
            flow = FLOW_CALL
            target = index_by_addr[cgen.branch_target(insn.operands[0])]
        elif insn.mnemonic == "ret":
            flow = FLOW_RET
            target = 0
        records.append({
            "index": index,
            "function": symbol,
            "function_role": role,
            "addr": f"0x{insn.addr:x}",
            "asm": insn.raw,
            "helper": SIMULATOR_STEP,
            "flow": flow,
            "target": target,
            "next": index + 1,
            "entry_return": role == "entry" and insn.mnemonic == "ret",
            **numeric,
        })
    return {
        "entry_index": 0,
        "max_steps": max(4096, len(records) * 32),
        "insns": records,
    }


def c_template_plan(linked: dict[str, Any]) -> dict[str, Any]:
    return {
        "kind": "c_authored_simulator_helper_sequence",
        "granularity": "instruction_class",
        "dispatch": (
            "C-authored simulator/template dispatch from opcode/operand "
            "records; Python does not select x86_exec_* helpers"
        ),
        "alu_policy": "ALU semantics are selected inside C from opcode/aux",
        "control_flow_source": "linked_program.flow/target",
        "steps": [
            {
                "index": record["index"],
                "asm": record["asm"],
                "helper": record["helper"],
                "args": {
                    "op": record["op"],
                    "dst": record["dst"],
                    "src": record["src"],
                    "flags": record["flags"],
                    "aux": record["aux"],
                    "imm": record["imm"],
                },
                "flow": record["flow"],
                "target": record["target"],
            }
            for record in linked["insns"]
        ],
    }


def build_artifact(md_path: Path, *, native_source: str) -> dict[str, Any]:
    name = md_path.stem
    entry_symbols = [f"{name}_xdp", f"{name}_prog"]
    entry_name = entry_symbols[0]
    no_jump_tables = native_source == "object-no-jump-tables"
    if native_source == "markdown":
        entry_insns = cgen.parse_native_asm(md_path)
    elif no_jump_tables:
        so_path = cgen.native_object_path(name, no_jump_tables=True)
        entry_name, entry_insns = cgen.parse_first_native_symbol(so_path, entry_symbols)
    else:
        raise ValueError(f"unknown native source: {native_source}")
    missing_symbols = cgen.unresolved_call_symbols(entry_insns)
    subfunctions: dict[str, list[cgen.NativeInsn]] = {}
    native_symbol_disasm = no_jump_tables

    if missing_symbols:
        native_functions = cgen.parse_full_native_functions(
            name, missing_symbols, no_jump_tables=no_jump_tables
        )
        for symbol in entry_symbols:
            if symbol in native_functions:
                entry_name = symbol
                entry_insns = native_functions.pop(symbol)
                break
        subfunctions = native_functions
        native_symbol_disasm = True

    if not entry_insns:
        raise ValueError(f"{md_path}: no native instructions parsed")

    functions = {entry_name: entry_insns, **subfunctions}
    function_json = [function_artifact(entry_name, "entry", entry_insns)]
    function_json.extend(
        function_artifact(symbol, "subprogram", insns)
        for symbol, insns in sorted(subfunctions.items())
    )

    helpers = sorted({
        insn_json["helper"]
        for fn_json in function_json
        for insn_json in fn_json["insns"]
    })

    linked = linked_program(functions, entry_name)
    artifact = {
        "schema": SCHEMA,
        "name": name,
        "arch": "x86_64",
        "prog_type": "xdp",
        "entry": {
            "native_symbol": entry_name,
            "bpf_program": f"{name}_x86_sim_xdp",
        },
        "source": {
            "markdown": str(md_path.relative_to(REPO_ROOT)),
            "native_symbol_disasm": native_symbol_disasm,
            "native_source": native_source,
        },
        "simulator": {
            "state": "struct x86_state",
            "instruction": "struct x86_insn",
            "helpers": helpers,
            "linkage": "bpf_subprogram_or_inlined_fragment",
        },
        "features": feature_flags(functions),
        "functions": function_json,
        "linked_program": linked,
        "link": {
            "kind": "reversesim_simulator_helper_link",
            "loader_role": "schema_check_concat_resolve_fixups_load",
            "fixups": [],
        },
        "verifier_templates": c_template_plan(linked),
        "linker_status": (
            "pending: Rust linker still needs to consume C-authored helper "
            "templates; JSON intentionally contains no hardcoded BPF insns"
        ),
    }
    return artifact


def write_one(md_path: Path, out_dir: Path, *, native_source: str) -> Path:
    artifact = build_artifact(md_path, native_source=native_source)
    output = out_dir / f"{md_path.stem}.json"
    output.write_text(json.dumps(artifact, indent=2, sort_keys=True) + "\n")
    return output


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--micro-programs", type=Path, default=MICRO_PROGRAMS)
    parser.add_argument("--output-dir", type=Path, default=OUT_DIR)
    parser.add_argument("--only", nargs="*", help="optional micro benchmark stem list")
    parser.add_argument(
        "--native-source",
        choices=("markdown", "object-no-jump-tables"),
        default="object-no-jump-tables",
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
    print(f"generated {len(written)} JSON proof definitions")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
