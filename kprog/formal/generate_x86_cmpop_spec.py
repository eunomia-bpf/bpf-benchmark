#!/usr/bin/env python3
"""Generate the x86-64 `CMP_IMM` / `CMP_REG` / `TEST_IMM` / `TEST_REG` /
`CMP_MEM_IMM` / `TEST_MEM_IMM` / `CMP_MEM_REG` / `TEST_MEM_REG`
handler-composition contract.

`X86_OP_CMP_IMM` (`0x0c`), `X86_OP_CMP_REG` (`0x0d`), `X86_OP_TEST_IMM`
(`0x0e`) and `X86_OP_TEST_REG` (`0x0f`) are the four opcodes served by the
`X86_SIM_L_EXEC_CMP_{IMM,REG}_OP[_AUX]` arms, which share one
`X86_SIM_L_EXEC_CMP_REG_STEP` composition. `X86_OP_CMP_MEM_IMM` (`0x1d`),
`X86_OP_TEST_MEM_IMM` (`0x1e`), `X86_OP_CMP_MEM_REG` (`0x1f`) and
`X86_OP_TEST_MEM_REG` (`0x3b`) are the four memory-source opcodes served by
`X86_SIM_L_EXEC_CMP_MEM`, which shares the same step with a memory
left-hand-side arm. Each body resolves one width `FLAGS ? FLAGS : 64`, builds a
left-hand side — the width/lane register read of the destination for the
register forms, the value loaded from the addressed memory for the memory forms
— builds a right-hand side — the decoded immediate for the `_IMM` forms, the
register for the `_REG` forms — and then writes one of two flag sets: a
zero-borrow subtraction for the `CMP` opcodes or the logical flags of the
width-narrowed conjunction for the `TEST` opcodes. No register is written. The
bodies share one `X86_SIM_L_EXEC_CMP_REG_STEP` composition that routes the
right-hand-side source through `KPROG_X86_CMPOP_RHS_SOURCE`, the flag kind
through `KPROG_X86_CMPOP_FLAG_KIND`, the left-hand-side source through
`KPROG_X86_CMPOP_LHS_SOURCE`, the displacement kind through
`KPROG_X86_CMPOP_DISP_KIND`, and the one width through
`KPROG_X86_CMPOP_WRITE_WIDTH`.

The contract pins the facts the eight opcodes share and the per-opcode ones
that separate them:

  * all eight resolve one width `FLAGS ? FLAGS : 64`;
  * the left-hand-side source is a per-opcode fact: the width/lane register
    read of the destination for the register forms, the addressed memory for
    the memory forms;
  * the right-hand side is a per-opcode fact: the decoded immediate for the
    `_IMM` forms (`x86_store_imm_value`), the register for the `_REG` forms;
  * the flag kind is a per-opcode fact: the `CMP` forms produce the same
    zero-borrow subtraction flags as `SUB`, the `TEST` forms the logical flags
    of the conjunction with `CF = OF = 0`;
  * the displacement kind is a per-opcode fact: `CMP_MEM_REG` takes the whole
    immediate as a signed displacement (`x86_simm`), every other memory form
    takes the high 32 bits as a store displacement (`x86_store_imm_disp`);
  * no body writes a register: the destination value and its provenance tag
    pass through unchanged.

Outputs (both regenerated whole, `--check` rejects any stale copy):
  * `KProgFormal/GeneratedX86CmpOp.lean`
  * `generated/x86_cmpop.h`
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_cmpop_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86CmpOp.lean"
CHEADER = ROOT / "generated/x86_cmpop.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86CmpOp",
    "selector": "flags_resolved_width_then_per_opcode_rhs_source_and_flag_kind_"
                "and_lhs_source_and_disp_kind_then_register_lane_read",
    "opcodes": [
        {"name": "cmpImm", "define": "X86_OP_CMP_IMM", "code": "0x0c",
         "rhs": "immediate", "flags": "sub", "lhs": "register",
         "disp": "simm"},
        {"name": "cmpReg", "define": "X86_OP_CMP_REG", "code": "0x0d",
         "rhs": "register", "flags": "sub", "lhs": "register",
         "disp": "simm"},
        {"name": "testImm", "define": "X86_OP_TEST_IMM", "code": "0x0e",
         "rhs": "immediate", "flags": "logic", "lhs": "register",
         "disp": "simm"},
        {"name": "testReg", "define": "X86_OP_TEST_REG", "code": "0x0f",
         "rhs": "register", "flags": "logic", "lhs": "register",
         "disp": "simm"},
        {"name": "cmpMemImm", "define": "X86_OP_CMP_MEM_IMM", "code": "0x1d",
         "rhs": "immediate", "flags": "sub", "lhs": "memory",
         "disp": "store"},
        {"name": "testMemImm", "define": "X86_OP_TEST_MEM_IMM", "code": "0x1e",
         "rhs": "immediate", "flags": "logic", "lhs": "memory",
         "disp": "store"},
        {"name": "cmpMemReg", "define": "X86_OP_CMP_MEM_REG", "code": "0x1f",
         "rhs": "register", "flags": "sub", "lhs": "memory",
         "disp": "simm"},
        {"name": "testMemReg", "define": "X86_OP_TEST_MEM_REG", "code": "0x3b",
         "rhs": "register", "flags": "logic", "lhs": "memory",
         "disp": "store"},
    ],
    "write_width_default": "b64",
}

OP_ORDER = ("cmpImm", "cmpReg", "testImm", "testReg",
            "cmpMemImm", "testMemImm", "cmpMemReg", "testMemReg")
OP_DEFINES = {"cmpImm": "X86_OP_CMP_IMM", "cmpReg": "X86_OP_CMP_REG",
              "testImm": "X86_OP_TEST_IMM", "testReg": "X86_OP_TEST_REG",
              "cmpMemImm": "X86_OP_CMP_MEM_IMM",
              "testMemImm": "X86_OP_TEST_MEM_IMM",
              "cmpMemReg": "X86_OP_CMP_MEM_REG",
              "testMemReg": "X86_OP_TEST_MEM_REG"}
OP_CODES = {"cmpImm": "0x0c", "cmpReg": "0x0d", "testImm": "0x0e",
            "testReg": "0x0f", "cmpMemImm": "0x1d", "testMemImm": "0x1e",
            "cmpMemReg": "0x1f", "testMemReg": "0x3b"}
OP_RHS = {"cmpImm": "immediate", "cmpReg": "register",
          "testImm": "immediate", "testReg": "register",
          "cmpMemImm": "immediate", "testMemImm": "immediate",
          "cmpMemReg": "register", "testMemReg": "register"}
OP_FLAGS = {"cmpImm": "sub", "cmpReg": "sub",
            "testImm": "logic", "testReg": "logic",
            "cmpMemImm": "sub", "testMemImm": "logic",
            "cmpMemReg": "sub", "testMemReg": "logic"}
OP_LHS = {"cmpImm": "register", "cmpReg": "register",
          "testImm": "register", "testReg": "register",
          "cmpMemImm": "memory", "testMemImm": "memory",
          "cmpMemReg": "memory", "testMemReg": "memory"}
OP_DISP = {"cmpImm": "simm", "cmpReg": "simm",
           "testImm": "simm", "testReg": "simm",
           "cmpMemImm": "store", "testMemImm": "store",
           "cmpMemReg": "simm", "testMemReg": "store"}

RHS_ORDER = ("immediate", "register")
FLAGS_ORDER = ("sub", "logic")

WRITE_WIDTH_DEFAULT = "b64"


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 cmpop specification: {data!r}")
    ops = data["opcodes"]
    for key, table in (("name", OP_ORDER), ("define", OP_DEFINES),
                       ("code", OP_CODES), ("rhs", OP_RHS),
                       ("flags", OP_FLAGS), ("lhs", OP_LHS),
                       ("disp", OP_DISP)):
        expected_col = [table[n] if isinstance(table, dict) else n
                        for n in OP_ORDER]
        if [row[key] for row in ops] != expected_col:
            raise SystemExit(f"invalid x86 cmpop {key} column: {ops!r}")
    if len({row["define"] for row in ops}) != len(ops):
        raise SystemExit(f"duplicate x86 cmpop opcode: {ops!r}")
    if data["write_width_default"] != WRITE_WIDTH_DEFAULT:
        raise SystemExit(f"invalid x86 cmpop write width default: {data!r}")
    return data


def _suffix(value, table):
    return table[value]


def render_lean(data, opcode_rows) -> str:
    op_ctors = "\n".join(f"  | {row['name']}" for row in opcode_rows)
    rhs_arms = "\n".join(
        f"  | .{row['name']} => .{row['rhs']}" for row in opcode_rows)
    flags_arms = "\n".join(
        f"  | .{row['name']} => .{row['flags']}" for row in opcode_rows)
    lhs_arms = "\n".join(
        f"  | .{row['name']} => .{row['lhs']}" for row in opcode_rows)
    disp_arms = "\n".join(
        f"  | .{row['name']} => .{row['disp']}" for row in opcode_rows)
    return f'''-- Generated by generate_x86_cmpop_spec.py from x86_cmpop_spec.json.
import Std
import KProgFormal.GeneratedX86Store
namespace KProgFormal.GeneratedX86CmpOp
open GeneratedX86Store (Code)
/-- The eight CMP/TEST opcodes this contract spans: the `CMP` forms produce the
zero-borrow subtraction flags, the `TEST` forms the logical flags; the `_IMM`
forms take the right-hand side from the decoded immediate, the `_REG` forms from
a register; the register forms read the left-hand side from the destination
register, the memory forms load it from memory. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- Where the right-hand side of the comparison comes from. -/
inductive RhsSource where
  | immediate
  | register
deriving DecidableEq, Repr
/-- Which flag production the opcode uses. -/
inductive FlagKind where
  | sub
  | logic
deriving DecidableEq, Repr
/-- Where the left-hand side of the comparison comes from. -/
inductive LhsSource where
  | register
  | memory
deriving DecidableEq, Repr
/-- How a memory form takes the displacement out of the raw immediate. -/
inductive DispKind where
  | simm
  | store
deriving DecidableEq, Repr
/-- The right-hand-side source each opcode uses. -/
def rhsSource : Op -> RhsSource
{rhs_arms}
/-- The flag kind each opcode uses. -/
def flagKind : Op -> FlagKind
{flags_arms}
/-- The left-hand-side source each opcode uses. -/
def lhsSource : Op -> LhsSource
{lhs_arms}
/-- The displacement kind each opcode uses. -/
def dispKind : Op -> DispKind
{disp_arms}
/-- The width a body falls back to when its opcode carries the "absent" FLAGS
code 0. -/
def writeWidthDefault : GeneratedX86Store.Code := .{WRITE_WIDTH_DEFAULT}
/-- The resolved width: the opcode's FLAGS code itself, or 64 bits when it
carries none - the width every CMP/TEST body narrows both operands to. -/
def resolveWidth : Code -> Code
  | .absent => .b64
  | .b8 => .b8
  | .b16 => .b16
  | .b32 => .b32
  | .b64 => .b64
end KProgFormal.GeneratedX86CmpOp
'''


def render_c(data, opcode_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["define"]} == {row["code"]}U, '
        f'"x86 cmpop {row["name"]} opcode drift");'
        for row in opcode_rows)
    op_source_defines = "\n".join(
        f'#define KPROG_X86_CMPOP_OP_{row["define"][len("X86_OP_"):]}_'
        f'RHS_SOURCE KPROG_X86_CMPOP_RHS_'
        f'{"IMMEDIATE" if row["rhs"] == "immediate" else "REGISTER"}\n'
        f'#define KPROG_X86_CMPOP_OP_{row["define"][len("X86_OP_"):]}_'
        f'FLAG_KIND KPROG_X86_CMPOP_FLAGS_'
        f'{"SUB" if row["flags"] == "sub" else "LOGIC"}\n'
        f'#define KPROG_X86_CMPOP_OP_{row["define"][len("X86_OP_"):]}_'
        f'LHS_SOURCE KPROG_X86_CMPOP_LHS_'
        f'{"MEMORY" if row["lhs"] == "memory" else "REGISTER"}\n'
        f'#define KPROG_X86_CMPOP_OP_{row["define"][len("X86_OP_"):]}_'
        f'DISP_KIND KPROG_X86_CMPOP_DISP_'
        f'{"STORE" if row["disp"] == "store" else "SIMM"}'
        for row in opcode_rows)
    lines = [
        "/* Generated by generate_x86_cmpop_spec.py from x86_cmpop_spec.json. */",
        "#ifndef KPROG_FORMAL_GENERATED_X86_CMPOP_H",
        "#define KPROG_FORMAL_GENERATED_X86_CMPOP_H",
        "/*",
        " * x86-64 `CMP_IMM` / `CMP_REG` / `TEST_IMM` / `TEST_REG` /",
        " * `CMP_MEM_IMM` / `TEST_MEM_IMM` / `CMP_MEM_REG` / `TEST_MEM_REG`",
        " * handler-composition contract. All eight bodies resolve one width",
        " * `FLAGS ? FLAGS : 64`. The left-hand side is a per-opcode fact: the",
        " * width/lane register read of the destination for the register forms, the",
        " * value loaded from the addressed memory for the memory forms. The",
        " * right-hand side is a per-opcode fact: the decoded immediate for the",
        " * `_IMM` forms, the register for the `_REG` forms. The flag kind is a",
        " * per-opcode fact: the `CMP` forms produce the zero-borrow subtraction",
        " * flags, the `TEST` forms the logical flags of the conjunction. The",
        " * displacement kind is a per-opcode fact: `CMP_MEM_REG` takes the whole",
        " * immediate as a signed displacement, every other memory form takes the",
        " * high 32 bits as a store displacement. No register is written.",
        " * The contract selects the opcodes, the right-hand-side source, the flag",
        " * kind, the left-hand-side source, and the displacement kind; the reads,",
        " * the subtraction/logical flag production, and the register preservation",
        " * stay in the one C step the eight bodies route through.",
        " */",
        op_asserts,
        "/* The FLAGS width codes, including the 0 \"absent\" code. */",
        "#define X86_WIDTH_8 1U",
        "#define X86_WIDTH_16 2U",
        "#define X86_WIDTH_32 4U",
        "#define X86_WIDTH_64 8U",
        "_Static_assert(X86_WIDTH_64 == 8U, \"x86 width code drift\");",
        "/* The width a body falls back to when its FLAGS code is absent. */",
        "#define KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT X86_WIDTH_64",
        "/*",
        " * The right-hand-side source, the flag kind, the left-hand-side source,",
        " * and the displacement kind of each opcode. All four are per-opcode table",
        " * entries: only the `_IMM` forms decode an immediate, only the `CMP` forms",
        " * produce subtraction flags, only the memory forms load the left-hand side",
        " * from memory, and only `CMP_MEM_REG` takes the immediate as a signed",
        " * displacement rather than the high 32 bits as a store displacement.",
        " */",
        "#define KPROG_X86_CMPOP_RHS_IMMEDIATE 0U",
        "#define KPROG_X86_CMPOP_RHS_REGISTER 1U",
        "#define KPROG_X86_CMPOP_FLAGS_SUB 0U",
        "#define KPROG_X86_CMPOP_FLAGS_LOGIC 1U",
        "#define KPROG_X86_CMPOP_LHS_REGISTER 0U",
        "#define KPROG_X86_CMPOP_LHS_MEMORY 1U",
        "#define KPROG_X86_CMPOP_DISP_SIMM 0U",
        "#define KPROG_X86_CMPOP_DISP_STORE 1U",
        op_source_defines,
        "#define KPROG_X86_CMPOP_RHS_SOURCE(OP_IS_REG) \\",
        "\t((OP_IS_REG) ? KPROG_X86_CMPOP_RHS_REGISTER : \\",
        "\t\t  KPROG_X86_CMPOP_RHS_IMMEDIATE)",
        "#define KPROG_X86_CMPOP_FLAG_KIND(OP_IS_TEST) \\",
        "\t((OP_IS_TEST) ? KPROG_X86_CMPOP_FLAGS_LOGIC : \\",
        "\t\t  KPROG_X86_CMPOP_FLAGS_SUB)",
        "#define KPROG_X86_CMPOP_LHS_SOURCE(OP_IS_MEM) \\",
        "\t((OP_IS_MEM) ? KPROG_X86_CMPOP_LHS_MEMORY : \\",
        "\t\t  KPROG_X86_CMPOP_LHS_REGISTER)",
        "#define KPROG_X86_CMPOP_DISP_KIND(OP_IS_CMP_MEM_REG) \\",
        "\t((OP_IS_CMP_MEM_REG) ? KPROG_X86_CMPOP_DISP_SIMM : \\",
        "\t\t  KPROG_X86_CMPOP_DISP_STORE)",
        "/*",
        " * FLAGS is the opcode's width code, with 0 the \"absent\" code; the resolved",
        " * width is the code itself, or the 64-bit default when it is absent. Both",
        " * operands are read at this one width.",
        " */",
        "#define KPROG_X86_CMPOP_WRITE_WIDTH(FLAGS) \\",
        "\t((FLAGS) ? (FLAGS) : KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT)",
        "#endif",
    ]
    return "\n".join(lines) + "\n"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    data = load()
    opcode_rows = [{"name": n, "define": OP_DEFINES[n], "code": OP_CODES[n],
                    "rhs": OP_RHS[n], "flags": OP_FLAGS[n], "lhs": OP_LHS[n],
                    "disp": OP_DISP[n]}
                   for n in OP_ORDER]
    for path, expected in ((LEAN, render_lean(data, opcode_rows)),
                           (CHEADER, render_c(data, opcode_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 cmpop contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
