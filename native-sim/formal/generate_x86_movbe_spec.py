#!/usr/bin/env python3
"""Generate the x86-64 `MOVBE_LOAD` / `MOVBE_STORE` handler-composition
contract.

This contract models `X86_SIM_L_EXEC_MOVBE_LOAD` and
`X86_SIM_L_EXEC_MOVBE_STORE`, the two handlers `X86_OP_MOVBE_LOAD` (`0x28`) and
`X86_OP_MOVBE_STORE` (`0x29`) route to. Three tables are generated.

1. `opcode_rows` fixes the two opcodes the contract spans.

2. `width_rows` resolves the *single* width both handlers compute from the
   opcode's `FLAGS` code:

     ::

         width = FLAGS ? FLAGS : X86_WIDTH_64

   Both byte-reversal forms resolve exactly one width and use it for
   everything: the byte reversal, the memory access, and the written size
   (including the store's stack arm, which re-uses the same resolved width
   rather than re-deriving `EFFECTIVE_WIDTH`). The table is closed over the five
   `X86_WIDTH_*` codes (including the 0 "absent" code), so the resolution is
   total and has no unsupported arm.

3. `arm_rows` selects the store form's target from one fact: whether the
   base/destination register is the stack pointer. There is no ABI arm and no
   sign extension for either form: the load writes a register through the
   always-scalarizing partial-register write, the store writes memory.

The load form takes its arm from the *shared* memory read dispatch
(`KPROG_X86_MEM_READ_SRC`) rather than from this table, so `armFamily` below
records which arm contract the opcode consumes: the load consumes the shared
read dispatch, the store consumes the two-way stack/memory arm. The
displacement is deliberately absent from this contract: both forms take the
whole instruction-immediate artifact `(s64)IMM`, so the immediate store's
high-half slice `(s32)(IMM >> 32)` never applies — the contrast is pinned in the
handler module and restated, as a documentation macro, in the C header.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_movbe_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86Movbe.lean"
CHEADER = ROOT / "generated/x86_movbe.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86MovbeHandler",
    "selector": "opcode_operand_then_register_identity_arm",
    "opcode_rows": [
        {"op": "movbeLoad", "op_define": "X86_OP_MOVBE_LOAD", "op_code": "0x28",
         "arm_family": "memoryReadDispatch"},
        {"op": "movbeStore", "op_define": "X86_OP_MOVBE_STORE",
         "op_code": "0x29", "arm_family": "registerStoreArm"},
    ],
    "width_rows": [
        {"flags_width": 0, "width": 8,
         "width_define": "KPROG_X86_MOVBE_WIDTH_ABSENT"},
        {"flags_width": 1, "width": 1, "width_define": "X86_WIDTH_8"},
        {"flags_width": 2, "width": 2, "width_define": "X86_WIDTH_16"},
        {"flags_width": 4, "width": 4, "width_define": "X86_WIDTH_32"},
        {"flags_width": 8, "width": 8, "width_define": "X86_WIDTH_64"},
    ],
    "disp_rows": [
        {"op": "movbeLoad", "form": "signedImm"},
        {"op": "movbeStore", "form": "signedImm"},
    ],
    "arm_rows": [
        {"is_rsp": True, "arm": "stackWrite",
         "arm_define": "KPROG_X86_MOVBE_ARM_STACK"},
        {"is_rsp": False, "arm": "memoryStore",
         "arm_define": "KPROG_X86_MOVBE_ARM_MEMORY"},
    ],
}

OPCODE_ORDER = ("movbeLoad", "movbeStore")
OPCODE_DEFINES = {"movbeLoad": "X86_OP_MOVBE_LOAD",
                  "movbeStore": "X86_OP_MOVBE_STORE"}
OPCODE_CODES = {"movbeLoad": "0x28", "movbeStore": "0x29"}
ARM_FAMILIES = {"movbeLoad": "memoryReadDispatch",
                "movbeStore": "registerStoreArm"}

WIDTH_ORDER = (0, 1, 2, 4, 8)

WIDTH_DEFINES = {
    0: "KPROG_X86_MOVBE_WIDTH_ABSENT",
    1: "X86_WIDTH_8",
    2: "X86_WIDTH_16",
    4: "X86_WIDTH_32",
    8: "X86_WIDTH_64",
}

DISP_ORDER = ("movbeLoad", "movbeStore")
DISP_FORMS = {"movbeLoad": "signedImm", "movbeStore": "signedImm"}

ARM_ORDER = (True, False)
ARM_DEFINES = {
    "stackWrite": "KPROG_X86_MOVBE_ARM_STACK",
    "memoryStore": "KPROG_X86_MOVBE_ARM_MEMORY",
}

ARM_CODES = {"stackWrite": 0, "memoryStore": 1}


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 movbe specification: {data!r}")
    opcode_rows = EXPECTED["opcode_rows"]
    width_rows = EXPECTED["width_rows"]
    disp_rows = EXPECTED["disp_rows"]
    arm_rows = EXPECTED["arm_rows"]
    if [row["op"] for row in opcode_rows] != list(OPCODE_ORDER):
        raise SystemExit(f"invalid x86 movbe opcode row order: {opcode_rows!r}")
    for row in opcode_rows:
        if row["op_define"] != OPCODE_DEFINES[row["op"]]:
            raise SystemExit(f"invalid x86 movbe opcode define: {row!r}")
        if row["op_code"] != OPCODE_CODES[row["op"]]:
            raise SystemExit(f"invalid x86 movbe opcode code: {row!r}")
        if row["arm_family"] != ARM_FAMILIES[row["op"]]:
            raise SystemExit(f"invalid x86 movbe arm family: {row!r}")
    if [row["op"] for row in disp_rows] != list(DISP_ORDER):
        raise SystemExit(f"invalid x86 movbe disp row order: {disp_rows!r}")
    for row in disp_rows:
        if row["form"] != DISP_FORMS[row["op"]]:
            raise SystemExit(f"invalid x86 movbe disp form: {row!r}")
    if [row["flags_width"] for row in width_rows] != list(WIDTH_ORDER):
        raise SystemExit(f"invalid x86 movbe width row order: {width_rows!r}")
    for row in width_rows:
        width = row["flags_width"] or 8
        if row["width"] != width:
            raise SystemExit(f"invalid x86 movbe width resolution: {row!r}")
        if row["width_define"] != WIDTH_DEFINES[row["flags_width"]]:
            raise SystemExit(f"invalid x86 movbe width define: {row!r}")
    if [row["is_rsp"] for row in arm_rows] != list(ARM_ORDER):
        raise SystemExit(f"invalid x86 movbe arm row order: {arm_rows!r}")
    for row in arm_rows:
        arm = "stackWrite" if row["is_rsp"] else "memoryStore"
        if row["arm"] != arm:
            raise SystemExit(f"invalid x86 movbe arm: {row!r}")
        if row["arm_define"] != ARM_DEFINES[arm]:
            raise SystemExit(f"invalid x86 movbe arm define: {row!r}")
    return opcode_rows, width_rows, disp_rows, arm_rows


def render_lean(opcode_rows, width_rows, disp_rows, arm_rows) -> str:
    code_of = {0: "absent", 1: "b8", 2: "b16", 4: "b32", 8: "b64"}
    width_table = "\n".join(
        f"  | .{code_of[row['flags_width']]} => .{code_of[row['width']]}"
        for row in width_rows)
    family_table = "\n".join(
        f"  | .{row['op']} => .{row['arm_family']}"
        for row in opcode_rows)
    disp_table = "\n".join(
        f"  | .{row['op']} => .{row['form']}"
        for row in disp_rows)
    arm_table = "\n".join(
        f"  | {'true' if row['is_rsp'] else 'false'} => .{row['arm']}"
        for row in arm_rows)
    return f'''-- Generated by generate_x86_movbe_spec.py from x86_movbe_spec.json.
import Std
namespace KProgFormal.GeneratedX86Movbe
/-- The five width codes an x86 access width can carry, including the `absent`
code 0 used when the opcode supplies none. -/
inductive Code where
  | absent
  | b8
  | b16
  | b32
  | b64
deriving DecidableEq, Repr
/-- The resolved width both `MOVBE` forms use: the opcode's width code, or 64
bits when it carries none. One width serves the byte reversal, the memory
access, and the written size, for both the load and (stack arm included) the
store. -/
def resolveWidth : Code -> Code
{width_table}
/-- The two byte-reversal opcodes this contract spans: `MOVBE_LOAD` reads memory
and reverses into a register, `MOVBE_STORE` reverses a register and stores to
memory. -/
inductive Op where
  | movbeLoad
  | movbeStore
deriving DecidableEq, Repr
/-- The arm contract an opcode consumes: the load takes the shared memory read
dispatch, the store takes the two-way stack/memory arm. The two forms therefore
do *not* share an arm table, which is why they share this module but not this
selector. -/
inductive ArmFamily where
  | memoryReadDispatch
  | registerStoreArm
deriving DecidableEq, Repr
def armFamily : Op -> ArmFamily
{family_table}
/-- The displacement form the opcode uses for the instruction-immediate
artifact. Both `MOVBE` forms take the *whole* field sign-extended; the immediate
store's high-half slice is deliberately not in this table. -/
inductive DispForm where
  | immHighHalf
  | signedImm
deriving DecidableEq, Repr
def dispForm : Op -> DispForm
{disp_table}
/-- The target the store form selects. Only the store consults this table; the
load's arm comes from the shared memory read dispatch. -/
inductive Arm where
  | stackWrite
  | memoryStore
deriving DecidableEq, Repr
/-- The generated arm table over the one fact the store handler's branch chain
consults: whether the base/destination register is the stack pointer. -/
def arm : Bool -> Arm
{arm_table}
end KProgFormal.GeneratedX86Movbe
'''


def render_c(opcode_rows, width_rows, arm_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["op_define"]} == {row["op_code"]}U, '
        f'"x86 movbe {row["op"]} opcode drift");'
        for row in opcode_rows)
    arm_defines = "\n".join(
        f"#define {ARM_DEFINES[arm]} {ARM_CODES[arm]}U"
        for arm in ("stackWrite", "memoryStore"))
    width_defines = "\n".join(
        f"#define {WIDTH_DEFINES[code]} {code}U"
        for code in (1, 2, 4, 8, 0))
    return f'''/* Generated by generate_x86_movbe_spec.py from x86_movbe_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_MOVBE_H
#define KPROG_FORMAL_GENERATED_X86_MOVBE_H
/*
 * x86-64 `MOVBE_LOAD` / `MOVBE_STORE` handler-composition contract. Both forms
 * resolve exactly one width from the opcode's FLAGS code (`FLAGS ? FLAGS : 64`),
 * used for the byte reversal, the memory access, and the written size - the
 * store's stack arm included; the resolution is closed over the five
 * X86_WIDTH_* codes, so it is total and has no unsupported arm. The arm table is
 * closed over the one fact the store's branch chain consults - whether the
 * base/destination register is the stack pointer; the load instead takes its arm
 * from the shared memory read dispatch. The contract selects these; the byte
 * reversal, the value transformation, and the effective address stay in the two
 * C handlers.
 */
{op_asserts}
{arm_defines}

/* The FLAGS width codes, including the 0 "absent" code. */
{width_defines}
_Static_assert(X86_WIDTH_64 == 8U, "x86 width code drift");
/*
 * FLAGS_WIDTH is the opcode's FLAGS code, 0 when it carries none; the access
 * width then defaults to 64 bits. The same width drives the byte reversal, the
 * memory access, and the written size, for both MOVBE forms. No flags are
 * written.
 */
#define KPROG_X86_MOVBE_WIDTH(FLAGS_WIDTH)                                 \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_mb_width = (FLAGS_WIDTH) ?                   \\
\t\t\t(FLAGS_WIDTH) : X86_WIDTH_64;                          \\
\t\t__kprog_x86_mb_width;                                      \\
\t}})
/*
 * IMM is the instruction-immediate artifact field. Both MOVBE forms take the
 * whole field sign-extended, `(s64)IMM`; the immediate store's high-half slice
 * `(s32)((IMM) >> 32)` is a *different* slice of the same field and never
 * applies here. IMM is evaluated once. No flags are written.
 */
#define KPROG_X86_MOVBE_DISP(IMM)                                          \\
\t(__s64)(IMM)
/*
 * BASE_IS_RSP is true when the store's base/destination register is the stack
 * pointer; a stack-pointer destination writes through the stack helper, every
 * other destination through the ordinary little-endian store. Each input is
 * evaluated once. No flags are written. The load form does not consult this
 * table - it takes the shared memory read dispatch.
 */
#define KPROG_X86_MOVBE_ARM(BASE_IS_RSP)                                   \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_mb_arm;                                   \\
\t\tif (BASE_IS_RSP)                                           \\
\t\t\t__kprog_x86_mb_arm = KPROG_X86_MOVBE_ARM_STACK;    \\
\t\telse                                                       \\
\t\t\t__kprog_x86_mb_arm = KPROG_X86_MOVBE_ARM_MEMORY;   \\
\t\t__kprog_x86_mb_arm;                                        \\
\t}})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    opcode_rows, width_rows, disp_rows, arm_rows = load()
    for path, expected in (
            (LEAN, render_lean(opcode_rows, width_rows, disp_rows, arm_rows)),
            (CHEADER, render_c(opcode_rows, width_rows, arm_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 movbe contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
