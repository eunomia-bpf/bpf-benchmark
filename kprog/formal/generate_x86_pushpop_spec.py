#!/usr/bin/env python3
"""Generate the x86-64 `PUSH` / `POP` handler-composition contract.

This contract models the two stack-transfer handlers `X86_SIM_L_EXEC_PUSH` and
`X86_SIM_L_EXEC_POP` that `X86_OP_PUSH` (`0x12`) and `X86_OP_POP` (`0x13`)
route to. They share this contract because they are the same operation read
backwards, and the two facts that distinguish them are exactly the plausible
bugs:

  * the step *direction* — `PUSH` pre-decrements the stack pointer before its
    store, `POP` reads and writes its destination before post-incrementing the
    stack pointer; and
  * the width each body honours — `PUSH` hardcodes the 64-bit step width and
    ignores the opcode's `FLAGS` code, `POP` resolves the `FLAGS` code with a
    64-bit fallback and uses that *one* width for both its stack read and its
    destination-register write.

Both bodies step the stack pointer by exactly the same eight bytes regardless of
the width they honour, so the step amount is a single spec parameter, not a
function of the opcode. Neither body writes a flag, and neither writes a
register tag directly.

The contract selects these facts; the stack-pointer arithmetic, the stack
helper's byte framing, and the destination-register writeback stay in the one
shared `X86_SIM_L_EXEC_PUSH_POP_STEP` composition the two bodies route through.

Outputs (both regenerated whole, `--check` rejects any stale copy):
  * `KProgFormal/GeneratedX86PushPop.lean`
  * `generated/x86_pushpop.h`
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_pushpop_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86PushPop.lean"
CHEADER = ROOT / "generated/x86_pushpop.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86PushPopHandler",
    "selector": "opcode_step_direction_then_width_source",
    "stack_step": 8,
    "opcode_rows": [
        {"op": "push", "op_define": "X86_OP_PUSH", "op_code": "0x12",
         "step_direction": "preDecrement", "width_source": "hardcoded64"},
        {"op": "pop", "op_define": "X86_OP_POP", "op_code": "0x13",
         "step_direction": "postIncrement", "width_source": "flagsOr64"},
    ],
    "step_direction_rows": [
        {"step_direction": "preDecrement",
         "step_define": "KPROG_X86_PUSH_STEP_PRE_DECREMENT",
         "step_phase": "store"},
        {"step_direction": "postIncrement",
         "step_define": "KPROG_X86_PUSH_STEP_POST_INCREMENT",
         "step_phase": "load"},
    ],
    "width_source_rows": [
        {"width_source": "hardcoded64",
         "width_define": "KPROG_X86_PUSH_WIDTH_HARDCODED_64"},
        {"width_source": "flagsOr64",
         "width_define": "KPROG_X86_PUSH_WIDTH_FLAGS_OR_64"},
    ],
    "flags_width_rows": [
        {"flags_width": "resolved", "flags_define": "KPROG_X86_PUSH_FLAGS_RESOLVED"},
        {"flags_width": "absent", "flags_define": "KPROG_X86_PUSH_FLAGS_ABSENT"},
    ],
}

OP_ORDER = ("push", "pop")
OP_DEFINES = {"push": "X86_OP_PUSH", "pop": "X86_OP_POP"}
OP_CODES = {"push": "0x12", "pop": "0x13"}
OP_STEP_DIRECTIONS = {"push": "preDecrement", "pop": "postIncrement"}
OP_WIDTH_SOURCES = {"push": "hardcoded64", "pop": "flagsOr64"}

STEP_ORDER = ("preDecrement", "postIncrement")
STEP_DEFINES = {"preDecrement": "KPROG_X86_PUSH_STEP_PRE_DECREMENT",
                "postIncrement": "KPROG_X86_PUSH_STEP_POST_INCREMENT"}
STEP_PHASES = {"preDecrement": "store", "postIncrement": "load"}

WIDTH_SOURCE_ORDER = ("hardcoded64", "flagsOr64")
WIDTH_SOURCE_DEFINES = {"hardcoded64": "KPROG_X86_PUSH_WIDTH_HARDCODED_64",
                        "flagsOr64": "KPROG_X86_PUSH_WIDTH_FLAGS_OR_64"}

FLAGS_WIDTH_ORDER = ("resolved", "absent")
FLAGS_WIDTH_DEFINES = {"resolved": "KPROG_X86_PUSH_FLAGS_RESOLVED",
                       "absent": "KPROG_X86_PUSH_FLAGS_ABSENT"}

STACK_STEP = 8


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 pushpop specification: {data!r}")
    opcode_rows = EXPECTED["opcode_rows"]
    step_rows = EXPECTED["step_direction_rows"]
    width_rows = EXPECTED["width_source_rows"]
    flags_rows = EXPECTED["flags_width_rows"]
    if data["stack_step"] != STACK_STEP:
        raise SystemExit(f"invalid x86 pushpop stack step: {data!r}")
    if [row["op"] for row in opcode_rows] != list(OP_ORDER):
        raise SystemExit(f"invalid x86 pushpop opcode row order: {opcode_rows!r}")
    if len({row["op_code"] for row in opcode_rows}) != len(opcode_rows):
        raise SystemExit(f"duplicate x86 pushpop opcode: {opcode_rows!r}")
    for row in opcode_rows:
        if row["op_define"] != OP_DEFINES[row["op"]]:
            raise SystemExit(f"invalid x86 pushpop opcode define: {row!r}")
        if row["op_code"] != OP_CODES[row["op"]]:
            raise SystemExit(f"invalid x86 pushpop opcode code: {row!r}")
        if row["step_direction"] != OP_STEP_DIRECTIONS[row["op"]]:
            raise SystemExit(f"invalid x86 pushpop step direction: {row!r}")
        if row["width_source"] != OP_WIDTH_SOURCES[row["op"]]:
            raise SystemExit(f"invalid x86 pushpop width source: {row!r}")
    # The step direction and the width source are *independent* facts, but the
    # body that pre-decrements is the one that hardcodes 64 and the body that
    # post-increments is the one that resolves the FLAGS code. If the two
    # columns ever agreed the two facts would be one.
    for row in opcode_rows:
        predicted = "hardcoded64" if row["step_direction"] == "preDecrement" \
            else "flagsOr64"
        if row["width_source"] != predicted:
            raise SystemExit(f"x86 pushpop step/width collapsed: {row!r}")
    if [row["step_direction"] for row in step_rows] != list(STEP_ORDER):
        raise SystemExit(f"invalid x86 pushpop step row order: {step_rows!r}")
    for row in step_rows:
        if row["step_define"] != STEP_DEFINES[row["step_direction"]]:
            raise SystemExit(f"invalid x86 pushpop step define: {row!r}")
        if row["step_phase"] != STEP_PHASES[row["step_direction"]]:
            raise SystemExit(f"invalid x86 pushpop step phase: {row!r}")
    if [row["width_source"] for row in width_rows] != list(WIDTH_SOURCE_ORDER):
        raise SystemExit(f"invalid x86 pushpop width row order: {width_rows!r}")
    for row in width_rows:
        if row["width_define"] != WIDTH_SOURCE_DEFINES[row["width_source"]]:
            raise SystemExit(f"invalid x86 pushpop width define: {row!r}")
    if [row["flags_width"] for row in flags_rows] != list(FLAGS_WIDTH_ORDER):
        raise SystemExit(f"invalid x86 pushpop flags row order: {flags_rows!r}")
    for row in flags_rows:
        if row["flags_define"] != FLAGS_WIDTH_DEFINES[row["flags_width"]]:
            raise SystemExit(f"invalid x86 pushpop flags define: {row!r}")
    return opcode_rows, step_rows, width_rows, flags_rows


def render_lean(opcode_rows, step_rows, width_rows, flags_rows) -> str:
    op_ctors = "\n".join(f"  | {row['op']}" for row in opcode_rows)
    step_ctors = "\n".join(
        f"  | {row['step_direction']}" for row in step_rows)
    width_ctors = "\n".join(
        f"  | {row['width_source']}" for row in width_rows)
    flags_ctors = "\n".join(
        f"  | {row['flags_width']}" for row in flags_rows)
    step_table = "\n".join(
        f"  | .{row['op']} => .{row['step_direction']}"
        for row in opcode_rows)
    width_table = "\n".join(
        f"  | .{row['op']} => .{row['width_source']}"
        for row in opcode_rows)
    return f'''-- Generated by generate_x86_pushpop_spec.py from x86_pushpop_spec.json.
import Std
import KProgFormal.GeneratedX86Store
namespace KProgFormal.GeneratedX86PushPop
open GeneratedX86Store (Code)
/-- The two stack-transfer opcodes this contract spans: `PUSH` stores a source
register to the stack, `POP` loads a destination register from the stack. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- The direction the stack pointer steps around the body's single memory
access: `PUSH` decrements first and then stores, `POP` loads and writes its
destination and then increments. -/
inductive StepDirection where
{step_ctors}
deriving DecidableEq, Repr
/-- Which body a given opcode runs. -/
def stepDirection : Op -> StepDirection
{step_table}
/-- The width each body honours. `PUSH` hardcodes the 64-bit step width and
never consults the opcode's FLAGS code; `POP` resolves the FLAGS code with a
64-bit fallback and uses that one width for both its stack read and its
destination-register write. -/
inductive WidthSource where
{width_ctors}
deriving DecidableEq, Repr
/-- The width source each opcode uses. -/
def widthSource : Op -> WidthSource
{width_table}
/-- Whether an opcode's FLAGS code carries a width, or is the `absent` code 0
that `POP` defaults to 64 bits. Only `POP` consults this; `PUSH` hardcodes 64. -/
inductive FlagsWidth where
{flags_ctors}
deriving DecidableEq, Repr
/-- The FLAGS code's own reading: the `absent` code is the only code that
carries no width. -/
def flagsWidth : Code -> FlagsWidth
  | .absent => .absent
  | .b8 => .resolved
  | .b16 => .resolved
  | .b32 => .resolved
  | .b64 => .resolved
/-- The resolved width a `FLAGS`-honouring body uses: the code itself, or 64
bits when the opcode carries none. -/
def resolveWidth : Code -> Code
  | .absent => .b64
  | .b8 => .b8
  | .b16 => .b16
  | .b32 => .b32
  | .b64 => .b64
/-- The byte amount both bodies step the stack pointer by, whatever width they
honour. -/
def stackStep : Nat := {STACK_STEP}
end KProgFormal.GeneratedX86PushPop
'''


def render_c(opcode_rows, step_rows, width_rows, flags_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["op_define"]} == {row["op_code"]}U, '
        f'"x86 pushpop {row["op"]} opcode drift");'
        for row in opcode_rows)
    step_defines = "\n".join(
        f"#define {STEP_DEFINES[row['step_direction']]} {code}U"
        for code, row in enumerate(step_rows))
    width_defines = "\n".join(
        f"#define {WIDTH_SOURCE_DEFINES[row['width_source']]} {code}U"
        for code, row in enumerate(width_rows))
    flags_defines = "\n".join(
        f"#define {FLAGS_WIDTH_DEFINES[row['flags_width']]} {code}U"
        for code, row in enumerate(flags_rows))
    step_pre = STEP_DEFINES["preDecrement"]
    step_post = STEP_DEFINES["postIncrement"]
    width_hard = WIDTH_SOURCE_DEFINES["hardcoded64"]
    width_flags = WIDTH_SOURCE_DEFINES["flagsOr64"]
    flags_res = FLAGS_WIDTH_DEFINES["resolved"]
    flags_abs = FLAGS_WIDTH_DEFINES["absent"]
    return f'''/* Generated by generate_x86_pushpop_spec.py from x86_pushpop_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_PUSHPOP_H
#define KPROG_FORMAL_GENERATED_X86_PUSHPOP_H
/*
 * x86-64 `PUSH` / `POP` handler-composition contract. Both bodies step the
 * stack pointer by exactly {STACK_STEP} bytes; per opcode the contract fixes
 * the step direction (PUSH decrements before its store, POP increments after
 * its load and destination write) and the width each body honours (PUSH
 * hardcodes 64, POP resolves the opcode's FLAGS code with a 64-bit fallback).
 * The two facts are independent: the body that pre-decrements is the one that
 * hardcodes 64, the body that post-increments is the one that resolves the
 * FLAGS code. Neither body writes a flag. The contract selects these; the
 * stack-pointer arithmetic, the stack helper's byte framing, and the
 * destination-register writeback stay in the one shared
 * `X86_SIM_L_EXEC_PUSH_POP_STEP` composition the two bodies route through.
 */
{op_asserts}
/* The FLAGS width codes, including the 0 "absent" code. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#define KPROG_X86_PUSH_WIDTH_ABSENT 0U
_Static_assert(X86_WIDTH_64 == 8U, "x86 width code drift");
{step_defines}
{width_defines}
{flags_defines}

/* The byte amount both bodies step the stack pointer by. */
#define KPROG_X86_PUSH_STACK_STEP {STACK_STEP}U
/*
 * IS_POP is true for the `POP` opcode; the table gives whether the stack
 * pointer steps before the body's single memory access (PUSH: decrement then
 * store) or after the load and destination write (POP). The input is evaluated
 * once.
 */
#define KPROG_X86_PUSH_STEP_DIRECTION(IS_POP)                               \\
\t((IS_POP) ? {step_post} : {step_pre})
/*
 * IS_POP is true for the `POP` opcode; the table gives whether the body
 * hardcodes the 64-bit step width (PUSH) or resolves the opcode's FLAGS code
 * with a 64-bit fallback (POP). The input is evaluated once.
 */
#define KPROG_X86_PUSH_WIDTH_SOURCE(IS_POP)                                 \\
\t((IS_POP) ? {width_flags} : {width_hard})
/*
 * FLAGS_IS_ABSENT is true when the opcode carries the "absent" FLAGS code 0;
 * only the FLAGS-honouring body consults this, and an absent code resolves to
 * 64 bits. The input is evaluated once.
 */
#define KPROG_X86_PUSH_FLAGS_WIDTH(FLAGS_IS_ABSENT)                         \\
\t((FLAGS_IS_ABSENT) ? {flags_abs} : {flags_res})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    opcode_rows, step_rows, width_rows, flags_rows = load()
    for path, expected in (
            (LEAN, render_lean(opcode_rows, step_rows, width_rows, flags_rows)),
            (CHEADER, render_c(opcode_rows, step_rows, width_rows,
                               flags_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 pushpop contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
