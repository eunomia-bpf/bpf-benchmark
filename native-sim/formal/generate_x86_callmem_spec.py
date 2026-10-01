#!/usr/bin/env python3
"""Generate the x86-64 `CALL_MEMCPY` / `CALL_MEMSET` handler-composition
contract.

This contract models the four block-copy/block-fill handlers
`X86_SIM_L_EXEC_CALL_MEMCPY`, `X86_SIM_L_EXEC_CALL_MEMSET`,
`X86_SIM_L_EXEC_CALL_MEMCPY_REG`, and `X86_SIM_L_EXEC_CALL_MEMSET_REG` that
`X86_OP_CALL_MEMCPY` (`0x3f`), `X86_OP_CALL_MEMSET` (`0x3c`),
`X86_OP_CALL_MEMCPY_REG` (`0x46`), and `X86_OP_CALL_MEMSET_REG` (`0x45`) route
to. Three tables are generated.

1. `opcode_rows` fixes the four opcodes the contract spans and, per opcode, the
   three facts the bodies' branch chains read:

     * `kind` — copy (`MEMCPY`) or fill (`MEMSET`), the array body's shape;
     * `count_source` — whether the copied/filled length comes from the
       instruction-immediate artifact or from the `RDX` register; and
     * `bound_form` — whether the array bound is the hardcoded literal `1024`
       or the instruction-immediate artifact.

   The two facts are *independent*: `MEMSET`'s count is the immediate while its
   bound is the literal, whereas `MEMSET_REG`'s count is `RDX` while its bound
   is the immediate. Reading them as one fact is the plausible confusion, and
   `x86_call_mem_fixed_bound_is_literal` / `x86_call_mem_reg_bound_is_imm`
   pin the two apart.

2. `kind_rows`, `count_source_rows`, and `bound_form_rows` close the three
   selectors over their exact input domains, so each is total and has no
   unsupported arm.

The fixed bound is a literal parameter of the contract rather than a fifth
table, because the two hardcoded bodies always use the same `1024`; the two
immediate-bound bodies take `IMM` instead. The element width, the byte
addressing, the `RAX`/`RDI`-tag write, and the actual loads/stores stay in the
four C handlers.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_callmem_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86CallMem.lean"
CHEADER = ROOT / "generated/x86_callmem.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86CallMemHandler",
    "selector": "opcode_kind_then_count_source_and_bound_form",
    "fixed_bound": 1024,
    "opcode_rows": [
        {"op": "callMemcpy", "op_define": "X86_OP_CALL_MEMCPY",
         "op_code": "0x3f", "kind": "copy", "count_source": "imm",
         "bound_form": "fixedBound"},
        {"op": "callMemcpyReg", "op_define": "X86_OP_CALL_MEMCPY_REG",
         "op_code": "0x46", "kind": "copy", "count_source": "reg",
         "bound_form": "imm"},
        {"op": "callMemset", "op_define": "X86_OP_CALL_MEMSET",
         "op_code": "0x3c", "kind": "fill", "count_source": "imm",
         "bound_form": "fixedBound"},
        {"op": "callMemsetReg", "op_define": "X86_OP_CALL_MEMSET_REG",
         "op_code": "0x45", "kind": "fill", "count_source": "reg",
         "bound_form": "imm"},
    ],
    "kind_rows": [
        {"kind": "copy", "kind_define": "KPROG_X86_CALLMEM_COPY"},
        {"kind": "fill", "kind_define": "KPROG_X86_CALLMEM_FILL"},
    ],
    "count_source_rows": [
        {"count_source": "imm", "count_define": "KPROG_X86_CALLMEM_COUNT_IMM"},
        {"count_source": "reg", "count_define": "KPROG_X86_CALLMEM_COUNT_REG"},
    ],
    "bound_form_rows": [
        {"bound_form": "fixedBound",
         "bound_define": "KPROG_X86_CALLMEM_BOUND_FIXED"},
        {"bound_form": "imm", "bound_define": "KPROG_X86_CALLMEM_BOUND_IMM"},
    ],
}

OP_ORDER = ("callMemcpy", "callMemcpyReg", "callMemset", "callMemsetReg")
OP_DEFINES = {
    "callMemcpy": "X86_OP_CALL_MEMCPY",
    "callMemcpyReg": "X86_OP_CALL_MEMCPY_REG",
    "callMemset": "X86_OP_CALL_MEMSET",
    "callMemsetReg": "X86_OP_CALL_MEMSET_REG",
}
OP_CODES = {"callMemcpy": "0x3f", "callMemcpyReg": "0x46",
            "callMemset": "0x3c", "callMemsetReg": "0x45"}
OP_KINDS = {"callMemcpy": "copy", "callMemcpyReg": "copy",
            "callMemset": "fill", "callMemsetReg": "fill"}
OP_COUNT_SOURCES = {"callMemcpy": "imm", "callMemcpyReg": "reg",
                    "callMemset": "imm", "callMemsetReg": "reg"}
OP_BOUND_FORMS = {"callMemcpy": "fixedBound", "callMemcpyReg": "imm",
                  "callMemset": "fixedBound", "callMemsetReg": "imm"}

KIND_ORDER = ("copy", "fill")
KIND_DEFINES = {"copy": "KPROG_X86_CALLMEM_COPY",
                "fill": "KPROG_X86_CALLMEM_FILL"}
KIND_CODES = {"copy": 0, "fill": 1}

COUNT_SOURCE_ORDER = ("imm", "reg")
COUNT_SOURCE_DEFINES = {"imm": "KPROG_X86_CALLMEM_COUNT_IMM",
                        "reg": "KPROG_X86_CALLMEM_COUNT_REG"}
COUNT_SOURCE_CODES = {"imm": 0, "reg": 1}

BOUND_FORM_ORDER = ("fixedBound", "imm")
BOUND_FORM_DEFINES = {"fixedBound": "KPROG_X86_CALLMEM_BOUND_FIXED",
                      "imm": "KPROG_X86_CALLMEM_BOUND_IMM"}
BOUND_FORM_CODES = {"fixedBound": 0, "imm": 1}

FIXED_BOUND = 1024


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 callmem specification: {data!r}")
    opcode_rows = EXPECTED["opcode_rows"]
    kind_rows = EXPECTED["kind_rows"]
    count_rows = EXPECTED["count_source_rows"]
    bound_rows = EXPECTED["bound_form_rows"]
    if data["fixed_bound"] != FIXED_BOUND:
        raise SystemExit(f"invalid x86 callmem fixed bound: {data!r}")
    if [row["op"] for row in opcode_rows] != list(OP_ORDER):
        raise SystemExit(f"invalid x86 callmem opcode row order: {opcode_rows!r}")
    if len({row["op_code"] for row in opcode_rows}) != len(opcode_rows):
        raise SystemExit(f"duplicate x86 callmem opcode: {opcode_rows!r}")
    for row in opcode_rows:
        if row["op_define"] != OP_DEFINES[row["op"]]:
            raise SystemExit(f"invalid x86 callmem opcode define: {row!r}")
        if row["op_code"] != OP_CODES[row["op"]]:
            raise SystemExit(f"invalid x86 callmem opcode code: {row!r}")
        if row["kind"] != OP_KINDS[row["op"]]:
            raise SystemExit(f"invalid x86 callmem kind: {row!r}")
        if row["count_source"] != OP_COUNT_SOURCES[row["op"]]:
            raise SystemExit(f"invalid x86 callmem count source: {row!r}")
        if row["bound_form"] != OP_BOUND_FORMS[row["op"]]:
            raise SystemExit(f"invalid x86 callmem bound form: {row!r}")
    # The count source and the bound form are *independent*: the immediate
    # count bodies take the literal bound, the register count bodies take the
    # immediate bound. If they ever agreed the two facts would be one.
    for row in opcode_rows:
        predicted = "imm" if row["count_source"] == "reg" else "fixedBound"
        if row["bound_form"] != predicted:
            raise SystemExit(f"x86 callmem bound/count collapsed: {row!r}")
    if [row["kind"] for row in kind_rows] != list(KIND_ORDER):
        raise SystemExit(f"invalid x86 callmem kind row order: {kind_rows!r}")
    for row in kind_rows:
        if row["kind_define"] != KIND_DEFINES[row["kind"]]:
            raise SystemExit(f"invalid x86 callmem kind define: {row!r}")
    if [row["count_source"] for row in count_rows] != list(COUNT_SOURCE_ORDER):
        raise SystemExit(f"invalid x86 callmem count row order: {count_rows!r}")
    for row in count_rows:
        if row["count_define"] != COUNT_SOURCE_DEFINES[row["count_source"]]:
            raise SystemExit(f"invalid x86 callmem count define: {row!r}")
    if [row["bound_form"] for row in bound_rows] != list(BOUND_FORM_ORDER):
        raise SystemExit(f"invalid x86 callmem bound row order: {bound_rows!r}")
    for row in bound_rows:
        if row["bound_define"] != BOUND_FORM_DEFINES[row["bound_form"]]:
            raise SystemExit(f"invalid x86 callmem bound define: {row!r}")
    return opcode_rows, kind_rows, count_rows, bound_rows


def render_lean(opcode_rows, kind_rows, count_rows, bound_rows) -> str:
    op_ctors = "\n".join(f"  | {row['op']}" for row in opcode_rows)
    kind_ctors = "\n".join(f"  | {row['kind']}" for row in kind_rows)
    count_ctors = "\n".join(
        f"  | {row['count_source']}" for row in count_rows)
    bound_ctors = "\n".join(
        f"  | {row['bound_form']}" for row in bound_rows)
    kind_table = "\n".join(
        f"  | .{row['op']} => .{row['kind']}" for row in opcode_rows)
    count_table = "\n".join(
        f"  | .{row['op']} => .{row['count_source']}" for row in opcode_rows)
    bound_table = "\n".join(
        f"  | .{row['op']} => .{row['bound_form']}" for row in opcode_rows)
    return f'''-- Generated by generate_x86_callmem_spec.py from x86_callmem_spec.json.
import Std
namespace KProgFormal.GeneratedX86CallMem
/-- The four block-copy/block-fill opcodes this contract spans: `MEMCPY` and
`MEMSET` read their length from the instruction-immediate artifact, `MEMCPY_REG`
and `MEMSET_REG` from the `RDX` register. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- The array body's shape: `copy` moves byte by byte from a source, `fill`
writes one masked byte to every element. -/
inductive Kind where
{kind_ctors}
deriving DecidableEq, Repr
/-- Which body a given opcode runs. -/
def kind : Op -> Kind
{kind_table}
/-- Where the copied/filled length comes from: the instruction-immediate
artifact, or the `RDX` register the syscall ABI places the byte count in. -/
inductive CountSource where
{count_ctors}
deriving DecidableEq, Repr
/-- The length source each opcode uses. -/
def countSource : Op -> CountSource
{count_table}
/-- The array bound's form: the hardcoded literal `{FIXED_BOUND}`, or the
instruction-immediate artifact. -/
inductive BoundForm where
{bound_ctors}
deriving DecidableEq, Repr
/-- The bound form each opcode uses. Every immediate-count opcode takes the
literal bound and every register-count opcode the immediate bound. -/
def boundForm : Op -> BoundForm
{bound_table}
/-- The hardcoded array bound the two non-`IMM` bodies iterate to. -/
def fixedBound : Nat := {FIXED_BOUND}
end KProgFormal.GeneratedX86CallMem
'''


def render_c(opcode_rows, kind_rows, count_rows, bound_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["op_define"]} == {row["op_code"]}U, '
        f'"x86 callmem {row["op"]} opcode drift");'
        for row in opcode_rows)
    kind_defines = "\n".join(
        f"#define {KIND_DEFINES[row['kind']]} {KIND_CODES[row['kind']]}U"
        for row in kind_rows)
    count_defines = "\n".join(
        f"#define {COUNT_SOURCE_DEFINES[row['count_source']]} "
        f"{COUNT_SOURCE_CODES[row['count_source']]}U"
        for row in count_rows)
    bound_defines = "\n".join(
        f"#define {BOUND_FORM_DEFINES[row['bound_form']]} "
        f"{BOUND_FORM_CODES[row['bound_form']]}U"
        for row in bound_rows)
    return f'''/* Generated by generate_x86_callmem_spec.py from x86_callmem_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_CALLMEM_H
#define KPROG_FORMAL_GENERATED_X86_CALLMEM_H
/*
 * x86-64 `CALL_MEMCPY` / `CALL_MEMSET` handler-composition contract. The four
 * bodies move bytes one at a time at the hardcoded width 8; per opcode the
 * contract fixes the array body's shape (copy or fill), whether the length
 * comes from the instruction-immediate artifact or the RDX register, and
 * whether the array bound is the hardcoded literal {FIXED_BOUND} or the
 * immediate. The length source and the bound form are independent facts: the
 * immediate-count bodies take the literal bound, the register-count bodies the
 * immediate bound. The contract selects these; the element width, the byte
 * addressing, and the RAX/RDI-tag write stay in the four C handlers.
 */
{op_asserts}
{kind_defines}
{count_defines}
{bound_defines}

/* The hardcoded array bound the two immediate-count bodies iterate to. */
#define KPROG_X86_CALLMEM_FIXED_BOUND {FIXED_BOUND}U
/*
 * OP_IS_COPY is true for the two `MEMCPY` opcodes and false for the two
 * `MEMSET` opcodes; the table gives the array body's shape. The input is
 * evaluated once.
 */
#define KPROG_X86_CALLMEM_KIND(OP_IS_COPY)                                  \\
\t((OP_IS_COPY) ? KPROG_X86_CALLMEM_COPY : KPROG_X86_CALLMEM_FILL)
/*
 * OP_IS_REG is true for the two `*_REG` opcodes; the table gives whether the
 * copied/filled length comes from the RDX register (register-count bodies) or
 * the instruction-immediate artifact. The input is evaluated once.
 */
#define KPROG_X86_CALLMEM_COUNT_SOURCE(OP_IS_REG)                           \\
\t((OP_IS_REG) ? KPROG_X86_CALLMEM_COUNT_REG                         \\
\t\t      : KPROG_X86_CALLMEM_COUNT_IMM)
/*
 * OP_IS_REG is true for the two `*_REG` opcodes; the table gives whether the
 * array bound is the immediate (register-count bodies) or the hardcoded
 * literal (the two immediate-count bodies). The input is evaluated once.
 */
#define KPROG_X86_CALLMEM_BOUND_FORM(OP_IS_REG)                             \\
\t((OP_IS_REG) ? KPROG_X86_CALLMEM_BOUND_IMM                          \\
\t\t      : KPROG_X86_CALLMEM_BOUND_FIXED)
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    opcode_rows, kind_rows, count_rows, bound_rows = load()
    for path, expected in (
            (LEAN, render_lean(opcode_rows, kind_rows, count_rows, bound_rows)),
            (CHEADER, render_c(opcode_rows, kind_rows, count_rows,
                               bound_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 callmem contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
