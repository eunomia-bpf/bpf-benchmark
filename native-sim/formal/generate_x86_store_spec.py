#!/usr/bin/env python3
"""Generate the x86-64 `MOV_STORE` handler-composition contract.

This contract models `X86_SIM_L_EXEC_STORE`, the single handler body that
`X86_OP_MOV_STORE_IMM` and `X86_OP_MOV_STORE_REG` both route to. Four things are
generated.

1. `width_rows` resolves the *single* width code the handler computes from the
   opcode's `FLAGS` code:

     ::

         width = FLAGS ? FLAGS : X86_WIDTH_64

   Unlike the shared read body there is no second, auxiliary memory width: the
   same resolved width is used for the immediate value (`x86_store_imm_value`)
   and for the memory write (`X86_SIM_L_STORE_ADDR`), and the stack arm writes
   at `X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)` — the same expression. The table is
   closed over the five `X86_WIDTH_*` codes (including the 0 "absent" code), so
   the resolution is total and has no unsupported arm.

2. `disp_rows` selects the displacement form from the opcode. The immediate
   form takes the *high half* of the instruction-immediate artifact,
   `(s32)(IMM >> 32)`, sign-extended into the 64-bit displacement field; the
   register form takes the whole artifact sign-extended, `(s64)IMM`. These are
   different slices of the same field, and conflating them is the plausible
   bug.

3. `value_rows` selects the stored value's source. The immediate form takes
   `KPROG_X86_IMMEDIATE_VALUE(IMM, width)`, the width-aware low-32-bit rule; the
   register form takes the register read at the full 64 bits.

4. `shift_rows` gates the AUX source shift on the opcode: the shift is applied
   only for the register form, and only the register form reads
   `X86_REG_AUX_GET_SRC_SHIFT(AUX)`.

`arm_rows` selects the store target from one fact: whether the destination
register is the stack pointer. A stack-pointer base writes through the stack
helper; every other destination writes through the ordinary little-endian store.
There is no ABI arm and no sign extension: the store writes no register, defines
no flags, and its only observable effect is memory. The contract selects the
arm and resolves the width/form/source/shift; it does not restate the value
transformation or the addressing arithmetic.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_store_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86Store.lean"
CHEADER = ROOT / "generated/x86_store.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86StoreHandler",
    "selector": "opcode_operand_then_register_identity_arm",
    "width_rows": [
        {"flags_width": 0, "width": 8, "width_define": "X86_WIDTH_64"},
        {"flags_width": 1, "width": 1, "width_define": "X86_WIDTH_8"},
        {"flags_width": 2, "width": 2, "width_define": "X86_WIDTH_16"},
        {"flags_width": 4, "width": 4, "width_define": "X86_WIDTH_32"},
        {"flags_width": 8, "width": 8, "width_define": "X86_WIDTH_64"},
    ],
    "disp_rows": [
        {"is_store_imm": True, "form": "immHighHalf"},
        {"is_store_imm": False, "form": "signedImm"},
    ],
    "value_rows": [
        {"is_store_imm": True, "source": "immediateWidth"},
        {"is_store_imm": False, "source": "registerRead"},
    ],
    "shift_rows": [
        {"is_store_imm": True, "shift": "zero"},
        {"is_store_imm": False, "shift": "auxSrcShift"},
    ],
    "arm_rows": [
        {"is_rsp": True, "arm": "stackWrite",
         "arm_define": "KPROG_X86_STORE_ARM_STACK"},
        {"is_rsp": False, "arm": "memoryStore",
         "arm_define": "KPROG_X86_STORE_ARM_MEMORY"},
    ],
}

WIDTH_ORDER = (0, 1, 2, 4, 8)

DISP_ORDER = (True, False)
DISP_FORMS = {True: "immHighHalf", False: "signedImm"}

VALUE_ORDER = (True, False)
VALUE_SOURCES = {True: "immediateWidth", False: "registerRead"}

SHIFT_ORDER = (True, False)
SHIFT_SOURCES = {True: "zero", False: "auxSrcShift"}

ARM_ORDER = (True, False)
ARM_DEFINES = {
    "stackWrite": "KPROG_X86_STORE_ARM_STACK",
    "memoryStore": "KPROG_X86_STORE_ARM_MEMORY",
}

ARM_CODES = {"stackWrite": 0, "memoryStore": 1}

WIDTH_DEFINES = {
    0: "KPROG_X86_STORE_WIDTH_ABSENT",
    1: "X86_WIDTH_8",
    2: "X86_WIDTH_16",
    4: "X86_WIDTH_32",
    8: "X86_WIDTH_64",
}


def load() -> tuple[list[dict], list[dict], list[dict], list[dict], list[dict]]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 store specification: {data!r}")
    width_rows = EXPECTED["width_rows"]
    disp_rows = EXPECTED["disp_rows"]
    value_rows = EXPECTED["value_rows"]
    shift_rows = EXPECTED["shift_rows"]
    arm_rows = EXPECTED["arm_rows"]
    if [row["flags_width"] for row in width_rows] != list(WIDTH_ORDER):
        raise SystemExit(f"invalid x86 store width row order: {width_rows!r}")
    for row in width_rows:
        width = row["flags_width"] or 8
        if row["width"] != width:
            raise SystemExit(f"invalid x86 store width resolution: {row!r}")
        if row["width_define"] != WIDTH_DEFINES[width]:
            raise SystemExit(f"invalid x86 store width define: {row!r}")
    for rows, order, key, field, table in (
            (disp_rows, DISP_ORDER, "is_store_imm", "form", DISP_FORMS),
            (value_rows, VALUE_ORDER, "is_store_imm", "source", VALUE_SOURCES),
            (shift_rows, SHIFT_ORDER, "is_store_imm", "shift", SHIFT_SOURCES)):
        if [row[key] for row in rows] != list(order):
            raise SystemExit(f"invalid x86 store selector row order: {rows!r}")
        for row in rows:
            if row[field] != table[row[key]]:
                raise SystemExit(f"invalid x86 store selector: {row!r}")
    if [row["is_rsp"] for row in arm_rows] != list(ARM_ORDER):
        raise SystemExit(f"invalid x86 store arm row order: {arm_rows!r}")
    for row in arm_rows:
        arm = "stackWrite" if row["is_rsp"] else "memoryStore"
        if row["arm"] != arm:
            raise SystemExit(f"invalid x86 store arm: {row!r}")
        if row["arm_define"] != ARM_DEFINES[arm]:
            raise SystemExit(f"invalid x86 store arm define: {row!r}")
    return width_rows, disp_rows, value_rows, shift_rows, arm_rows


def render_lean(width_rows: list[dict], disp_rows: list[dict],
                value_rows: list[dict], shift_rows: list[dict],
                arm_rows: list[dict]) -> str:
    code_of = {0: "absent", 1: "b8", 2: "b16", 4: "b32", 8: "b64"}
    width_table = "\n".join(
        f"  | .{code_of[row['flags_width']]} => .{code_of[row['width']]}"
        for row in width_rows)
    disp_table = "\n".join(
        f"  | {'true' if row['is_store_imm'] else 'false'} => .{row['form']}"
        for row in disp_rows)
    value_table = "\n".join(
        f"  | {'true' if row['is_store_imm'] else 'false'} => .{row['source']}"
        for row in value_rows)
    shift_table = "\n".join(
        f"  | {'true' if row['is_store_imm'] else 'false'} => .{row['shift']}"
        for row in shift_rows)
    arm_table = "\n".join(
        f"  | {'true' if row['is_rsp'] else 'false'} => .{row['arm']}"
        for row in arm_rows)
    return f'''-- Generated by generate_x86_store_spec.py from x86_store_spec.json.
import Std
namespace KProgFormal.GeneratedX86Store
/-- The five width codes an x86 access width can carry, including the `absent`
code 0 used when the opcode supplies none. -/
inductive Code where
  | absent
  | b8
  | b16
  | b32
  | b64
deriving DecidableEq, Repr
/-- The resolved store width: the opcode's width code, or 64 bits when it
carries none. One width serves both the immediate value and the memory write. -/
def resolveWidth : Code -> Code
{width_table}
/-- The displacement form the store uses for the instruction-immediate
artifact: the sign-extended high 32 bits for the immediate store, the
sign-extended whole field for the register store. -/
inductive DispForm where
  | immHighHalf
  | signedImm
  deriving DecidableEq, Repr
def dispForm : Bool -> DispForm
{disp_table}
/-- The source of the stored value: the width-aware immediate rule, or the
register read. -/
inductive ValueSource where
  | immediateWidth
  | registerRead
  deriving DecidableEq, Repr
def valueSource : Bool -> ValueSource
{value_table}
/-- The source of the AUX shift: the register store reads the AUX shift field,
the immediate store shifts by nothing. -/
inductive ShiftSource where
  | auxSrcShift
  | zero
  deriving DecidableEq, Repr
def shiftSource : Bool -> ShiftSource
{shift_table}
/-- The store target the handler selects. -/
inductive Arm where
  | stackWrite
  | memoryStore
  deriving DecidableEq, Repr
/-- The generated arm table over the one fact the handler's branch chain
consults: whether the destination register is the stack pointer. -/
def arm : Bool -> Arm
{arm_table}
end KProgFormal.GeneratedX86Store
'''


def render_c(width_rows: list[dict], disp_rows: list[dict],
             value_rows: list[dict], shift_rows: list[dict],
             arm_rows: list[dict]) -> str:
    arm_defines = "\n".join(
        f"#define {name} {code}U"
        for name, code in (("KPROG_X86_STORE_ARM_STACK", 0),
                           ("KPROG_X86_STORE_ARM_MEMORY", 1)))
    width_defines = "\n".join(
        f"#define {WIDTH_DEFINES[code]} {code}U"
        for code in (8, 1, 2, 4, 0))
    return f'''/* Generated by generate_x86_store_spec.py from x86_store_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_STORE_H
#define KPROG_FORMAL_GENERATED_X86_STORE_H
/*
 * x86-64 `MOV_STORE` handler-composition contract. The width resolution is
 * closed over the five X86_WIDTH_* codes (including the 0 "absent" code) and
 * yields one width, used for both the immediate value and the memory write; an
 * absent FLAGS code means 64 bits, so the resolution is total and there is no
 * unsupported arm. The displacement form, the value source, and the AUX shift
 * source are all selected by the opcode, and the arm table is closed over the
 * one fact the branch chain consults - whether the destination register is the
 * stack pointer. The contract selects these; the value transformation and the
 * effective address stay in X86_SIM_L_EXEC_STORE.
 */
{arm_defines}

/* The FLAGS width codes, including the 0 "absent" code. */
{width_defines}
/*
 * FLAGS_WIDTH is the opcode's FLAGS code, 0 when it carries none; the store
 * width then defaults to 64 bits. The same width is used for the immediate
 * value and for the memory write. No flags are written.
 */
#define KPROG_X86_STORE_WIDTH(FLAGS_WIDTH)                                 \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_st_width = (FLAGS_WIDTH) ?                    \\
\t\t\t(FLAGS_WIDTH) : X86_WIDTH_64;                          \\
\t\t__kprog_x86_st_width;                                      \\
\t}})
/*
 * IS_STORE_IMM is true only for `_MOV_STORE_IMM`; IMM is the instruction
 * immediate artifact field. The immediate store takes its displacement from the
 * artifact's high 32 bits, sign-extended; the register store takes the whole
 * field sign-extended. Each input is evaluated once. No flags are written.
 */
#define KPROG_X86_STORE_DISP(IS_STORE_IMM, IMM)                            \\
\t({{                                                                \\
\t\t__s64 __kprog_x86_st_disp = (IS_STORE_IMM) ?                   \\
\t\t\t(__s64)(__s32)((IMM) >> 32) : (__s64)(IMM);           \\
\t\t__kprog_x86_st_disp;                                       \\
\t}})
/*
 * IS_STORE_IMM selects the value's source; WIDTH is the resolved store width.
 * The immediate store takes the width-aware immediate rule, the register store
 * the register read. Each input is evaluated once. No flags are written.
 */
#define KPROG_X86_STORE_VALUE(IS_STORE_IMM, IMM, WIDTH, SRC_VALUE)         \\
\t({{                                                                \\
\t\t__u64 __kprog_x86_st_value = (IS_STORE_IMM) ?                  \\
\t\t\tKPROG_X86_IMMEDIATE_VALUE((IMM), (WIDTH)) :            \\
\t\t\t(SRC_VALUE);                                           \\
\t\t__kprog_x86_st_value;                                      \\
\t}})
/*
 * IS_STORE_IMM gates the AUX shift: only the register store reads the AUX
 * source-shift field. AUX is the register AUX word. Each input is evaluated
 * once. No flags are written.
 */
#define KPROG_X86_STORE_SRC_SHIFT(IS_STORE_IMM, AUX)                       \\
\t({{                                                                \\
\t\t__u32 __kprog_x86_st_shift = (IS_STORE_IMM) ? 0U :             \\
\t\t\t(__u32)X86_REG_AUX_GET_SRC_SHIFT(AUX);                 \\
\t\t__kprog_x86_st_shift;                                      \\
\t}})
/*
 * The stored value is shifted right by the resolved source shift, which is 0
 * unless the register store's AUX shift field is nonzero. No flags are written.
 */
#define KPROG_X86_STORE_SHIFTED_VALUE(VALUE, SHIFT)                        \\
\t({{                                                                \\
\t\t__u64 __kprog_x86_st_shifted = (VALUE) >> (SHIFT);            \\
\t\t__kprog_x86_st_shifted;                                    \\
\t}})
/*
 * BASE_IS_RSP is true when the destination register is the stack pointer; a
 * stack-pointer destination writes through the stack helper, every other
 * destination through the ordinary little-endian store. Each input is
 * evaluated once. No flags are written.
 */
#define KPROG_X86_STORE_ARM(BASE_IS_RSP)                                   \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_st_arm;                                   \\
\t\tif (BASE_IS_RSP)                                           \\
\t\t\t__kprog_x86_st_arm = KPROG_X86_STORE_ARM_STACK;    \\
\t\telse                                                       \\
\t\t\t__kprog_x86_st_arm = KPROG_X86_STORE_ARM_MEMORY;   \\
\t\t__kprog_x86_st_arm;                                        \\
\t}})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    width_rows, disp_rows, value_rows, shift_rows, arm_rows = load()
    for path, expected in (
            (LEAN, render_lean(width_rows, disp_rows, value_rows, shift_rows,
                               arm_rows)),
            (CHEADER, render_c(width_rows, disp_rows, value_rows, shift_rows,
                               arm_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 store contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
