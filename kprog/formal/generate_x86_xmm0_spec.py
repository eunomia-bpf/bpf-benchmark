#!/usr/bin/env python3
"""Generate the x86-64 `LOAD_XMM0` / `STORE_XMM0` handler-composition contract.

This contract models `X86_SIM_L_EXEC_LOAD_XMM0` and
`X86_SIM_L_EXEC_STORE_XMM0`, the two handlers `X86_OP_LOAD_XMM0` (`0x30`) and
`X86_OP_STORE_XMM0` (`0x31`) route to. The two bodies move a *pair* of 8-byte
scalar lanes: the load writes the register pair `__x86_xmm0_lo` / `_hi` from two
consecutive memory (or stack) windows at offset `+0` and `+8`, the store writes
the pair back to those two windows. Three tables are generated.

1. `opcode_rows` fixes the two opcodes, each with three further facts: the
   direction (the load reads, the store writes), the ordinary arm's *base form*,
   and the displacement form.

2. `arm_rows` selects the target from one fact: whether the base/destination
   register is the stack pointer. A stack-pointer operand reads or writes the C
   stack helper's frame; every other operand reads or writes process memory.
   Both arms move exactly the same two lanes at the same offsets.

3. `lane_rows` fixes the pair layout: two lanes, at byte offsets 0 and 8 within
   the pair, each 8 bytes wide. The pair is *not* a reversed or interleaved
   vector — two independent little-endian windows.

The base form is the asymmetry that makes the two opcodes non-unifiable. Both
bodies compute the addressing offset `disp + (index << scale)` before the arm
split, but they consume it differently when the operand is `X86_REG_NONE`: the
load's `X86_REG_NONE` operand *is* the raw absolute immediate pointer
`(void *)(long)IMM`, sign-reinterpreted, with the addressing offset discarded
entirely; the store's `X86_REG_NONE` operand is the null pointer and the
addressing offset *is* always added. Neither body resolves a width — both
hardcode `X86_WIDTH_64` for both lanes — and neither writes a GPR, a tag, or a
flag.

Unlike the pointer-write contract, this one is oracle-only: the sim's two
`X86_SIM_L_EXEC_*_XMM0` bodies do not call the generated macros. The host
cross-check `test_x86_xmm0_host.c` drives the generated tables and macros
against a hand-written model of the two bodies, and the Lean module
`X86Xmm0Handler.lean` refines the generated tables against independent
statements; the C bodies themselves remain in the trusted computing base.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_xmm0_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86Xmm0.lean"
CHEADER = ROOT / "generated/x86_xmm0.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86Xmm0Handler",
    "selector": "opcode_operand_form_then_register_identity_arm",
    "opcode_rows": [
        {
            "op": "loadXmm0",
            "op_define": "X86_OP_LOAD_XMM0",
            "op_code": "0x30",
            "direction": "load",
            "base_form": "absImmPtr",
            "disp": "signedImm",
        },
        {
            "op": "storeXmm0",
            "op_define": "X86_OP_STORE_XMM0",
            "op_code": "0x31",
            "direction": "store",
            "base_form": "nullBasePlusDisp",
            "disp": "signedImm",
        },
    ],
    "arm_rows": [
        {
            "is_rsp": True,
            "arm": "stackPair",
            "arm_define": "KPROG_X86_XMM0_ARM_STACK",
        },
        {
            "is_rsp": False,
            "arm": "memoryPair",
            "arm_define": "KPROG_X86_XMM0_ARM_MEMORY",
        },
    ],
    "lane_rows": [
        {
            "lane": 0,
            "lane_define": "KPROG_X86_XMM0_LANE_LO",
            "byte_offset": 0,
        },
        {
            "lane": 1,
            "lane_define": "KPROG_X86_XMM0_LANE_HI",
            "byte_offset": 8,
        },
    ],
}

OP_ORDER = ("loadXmm0", "storeXmm0")
OP_DEFINES = {"loadXmm0": "X86_OP_LOAD_XMM0", "storeXmm0": "X86_OP_STORE_XMM0"}
OP_CODES = {"loadXmm0": "0x30", "storeXmm0": "0x31"}
OP_DIRECTIONS = {"loadXmm0": "load", "storeXmm0": "store"}
OP_BASE_FORMS = {"loadXmm0": "absImmPtr", "storeXmm0": "nullBasePlusDisp"}
OP_DISPS = {"loadXmm0": "signedImm", "storeXmm0": "signedImm"}

DIRECTION_ORDER = ("load", "store")

DISP_ORDER = ("immHighHalf", "signedImm")

ARM_ORDER = (True, False)
ARM_DEFINES = {
    "stackPair": "KPROG_X86_XMM0_ARM_STACK",
    "memoryPair": "KPROG_X86_XMM0_ARM_MEMORY",
}
ARM_CODES = {"stackPair": 0, "memoryPair": 1}

LANE_ORDER = (0, 1)
LANE_DEFINES = {0: "KPROG_X86_XMM0_LANE_LO", 1: "KPROG_X86_XMM0_LANE_HI"}
LANE_OFFSETS = {0: 0, 1: 8}

BASE_FORM_ORDER = ("absImmPtr", "nullBasePlusDisp")
BASE_FORM_DEFINES = {
    "absImmPtr": "KPROG_X86_XMM0_BASE_ABS_IMM",
    "nullBasePlusDisp": "KPROG_X86_XMM0_BASE_NULL_PLUS_DISP",
}
BASE_FORM_CODES = {"absImmPtr": 0, "nullBasePlusDisp": 1}


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 xmm0 specification: {data!r}")
    opcode_rows = EXPECTED["opcode_rows"]
    arm_rows = EXPECTED["arm_rows"]
    lane_rows = EXPECTED["lane_rows"]
    if [row["op"] for row in opcode_rows] != list(OP_ORDER):
        raise SystemExit(f"invalid x86 xmm0 opcode row order: {opcode_rows!r}")
    if len({row["op_code"] for row in opcode_rows}) != len(opcode_rows):
        raise SystemExit(f"duplicate x86 xmm0 opcode: {opcode_rows!r}")
    if len({row["direction"] for row in opcode_rows}) != len(opcode_rows):
        raise SystemExit(f"duplicate x86 xmm0 direction: {opcode_rows!r}")
    if [row["base_form"] for row in opcode_rows] != list(BASE_FORM_ORDER):
        raise SystemExit(f"duplicate x86 xmm0 base form: {opcode_rows!r}")
    for row in opcode_rows:
        if row["op_define"] != OP_DEFINES[row["op"]]:
            raise SystemExit(f"invalid x86 xmm0 opcode define: {row!r}")
        if row["op_code"] != OP_CODES[row["op"]]:
            raise SystemExit(f"invalid x86 xmm0 opcode code: {row!r}")
        if row["direction"] != OP_DIRECTIONS[row["op"]]:
            raise SystemExit(f"invalid x86 xmm0 direction: {row!r}")
        if row["base_form"] != OP_BASE_FORMS[row["op"]]:
            raise SystemExit(f"invalid x86 xmm0 base form: {row!r}")
        if row["disp"] != OP_DISPS[row["op"]]:
            raise SystemExit(f"invalid x86 xmm0 disp form: {row!r}")
        if row["base_form"] not in BASE_FORM_ORDER:
            raise SystemExit(f"invalid x86 xmm0 base form name: {row!r}")
        if row["disp"] not in DISP_ORDER:
            raise SystemExit(f"invalid x86 xmm0 disp form name: {row!r}")
    # The load's ordinary arm and the store's ordinary arm take *opposite* base
    # forms; if they ever agreed, the two opcodes would share one addressing
    # rule and the asymmetry this contract pins would be gone.
    forms = [row["base_form"] for row in opcode_rows]
    if forms[0] != "absImmPtr" or forms[1] != "nullBasePlusDisp":
        raise SystemExit(f"x86 xmm0 base forms collapsed: {forms!r}")
    if [row["is_rsp"] for row in arm_rows] != list(ARM_ORDER):
        raise SystemExit(f"invalid x86 xmm0 arm row order: {arm_rows!r}")
    for row in arm_rows:
        arm = "stackPair" if row["is_rsp"] else "memoryPair"
        if row["arm"] != arm:
            raise SystemExit(f"invalid x86 xmm0 arm: {row!r}")
        if row["arm_define"] != ARM_DEFINES[arm]:
            raise SystemExit(f"invalid x86 xmm0 arm define: {row!r}")
    if [row["lane"] for row in lane_rows] != list(LANE_ORDER):
        raise SystemExit(f"invalid x86 xmm0 lane row order: {lane_rows!r}")
    if len({row["byte_offset"] for row in lane_rows}) != len(lane_rows):
        raise SystemExit(f"duplicate x86 xmm0 lane offset: {lane_rows!r}")
    for row in lane_rows:
        if row["lane_define"] != LANE_DEFINES[row["lane"]]:
            raise SystemExit(f"invalid x86 xmm0 lane define: {row!r}")
        if row["byte_offset"] != LANE_OFFSETS[row["lane"]]:
            raise SystemExit(f"invalid x86 xmm0 lane offset: {row!r}")
    # The pair is two consecutive 8-byte lanes: lane 1 sits exactly one lane
    # width past lane 0, so the pair is not reversed or interleaved.
    if lane_rows[1]["byte_offset"] - lane_rows[0]["byte_offset"] != 8:
        raise SystemExit(f"x86 xmm0 lanes are not consecutive: {lane_rows!r}")
    return opcode_rows, arm_rows, lane_rows


def render_lean(opcode_rows, arm_rows, lane_rows) -> str:
    op_ctors = "\n".join(f"  | {row['op']}" for row in opcode_rows)
    dir_ctors = "\n".join(f"  | {name}" for name in DIRECTION_ORDER)
    disp_ctors = "\n".join(f"  | {name}" for name in DISP_ORDER)
    base_ctors = "\n".join(f"  | {name}" for name in BASE_FORM_ORDER)
    arm_ctors = "\n".join(f"  | {row['arm']}" for row in arm_rows)
    lane_ctors = "\n".join(
        f"  | {'lo' if row['lane'] == 0 else 'hi'}" for row in lane_rows)
    direction_table = "\n".join(
        f"  | .{row['op']} => .{row['direction']}" for row in opcode_rows)
    disp_table = "\n".join(
        f"  | .{row['op']} => .{row['disp']}" for row in opcode_rows)
    base_table = "\n".join(
        f"  | .{row['op']} => .{row['base_form']}" for row in opcode_rows)
    arm_table = "\n".join(
        f"  | {'true' if row['is_rsp'] else 'false'} => .{row['arm']}"
        for row in arm_rows)
    lane_table = "\n".join(
        f"  | .{'lo' if row['lane'] == 0 else 'hi'} => {row['byte_offset']}"
        for row in lane_rows)
    return f'''-- Generated by generate_x86_xmm0_spec.py from x86_xmm0_spec.json.
import Std
namespace KProgFormal.GeneratedX86Xmm0
/-- The two x86-64 opcodes that move a pair of 8-byte lanes through the XMM0
register pair: the load reads the pair from memory, the store writes it. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- Which way the pair moves. The direction is fixed per opcode and is not a
width: both directions move the same two 8-byte lanes. -/
inductive Direction where
{dir_ctors}
deriving DecidableEq, Repr
/-- The direction each opcode moves the pair. -/
def direction : Op -> Direction
{direction_table}
/-- The displacement form the opcode takes from the instruction-immediate
artifact. Both opcodes take the *whole* field sign-reinterpreted; the immediate
store's high-half slice is deliberately not in this table. -/
inductive DispForm where
{disp_ctors}
deriving DecidableEq, Repr
/-- The displacement form each opcode takes. -/
def dispForm : Op -> DispForm
{disp_table}
/-- How an opcode's ordinary arm resolves a `X86_REG_NONE` operand: the load's
operand *is* the raw absolute immediate pointer and the addressing offset is
discarded, the store's operand is the null pointer and the offset is added. -/
inductive BaseForm where
{base_ctors}
deriving DecidableEq, Repr
/-- The ordinary-arm base form each opcode uses. The two opcodes take opposite
forms, which is what keeps them from sharing one addressing rule. -/
def baseForm : Op -> BaseForm
{base_table}
/-- The two targets either body can move the pair to or from: the C stack
helper's frame for a stack-pointer operand, process memory for every other
operand. Both arms move exactly the same two lanes at the same offsets. -/
inductive Arm where
{arm_ctors}
deriving DecidableEq, Repr
/-- The generated arm table over the one fact either body's branch chain
consults: whether the operand register is the stack pointer. -/
def arm : Bool -> Arm
{arm_table}
/-- The two lanes of the register pair, low first. -/
inductive Lane where
{lane_ctors}
deriving DecidableEq, Repr
/-- How many lanes the pair carries. -/
def laneCount : Nat := {len(lane_rows)}
/-- The byte offset of each lane within the pair. The lanes are consecutive and
each one lane width wide, so the pair is two independent little-endian windows
rather than a reversed or interleaved vector. -/
def laneOffset : Lane -> Nat
{lane_table}
end KProgFormal.GeneratedX86Xmm0
'''


def render_c(opcode_rows, arm_rows, lane_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["op_define"]} == {row["op_code"]}U, '
        f'"x86 xmm0 {row["op"]} opcode drift");'
        for row in opcode_rows)
    arm_defines = "\n".join(
        f"#define {ARM_DEFINES[row['arm']]} {ARM_CODES[row['arm']]}U"
        for row in arm_rows)
    base_defines = "\n".join(
        f"#define {BASE_FORM_DEFINES[name]} {BASE_FORM_CODES[name]}U"
        for name in BASE_FORM_ORDER)
    lane_defines = "\n".join(
        f"#define {LANE_DEFINES[row['lane']]} {row['byte_offset']}U"
        for row in lane_rows)
    return f'''/* Generated by generate_x86_xmm0_spec.py from x86_xmm0_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_XMM0_H
#define KPROG_FORMAL_GENERATED_X86_XMM0_H
/*
 * x86-64 `LOAD_XMM0` / `STORE_XMM0` handler-composition contract. Both opcodes
 * move a pair of 8-byte scalar lanes between the XMM0 register pair and two
 * consecutive windows at offset +0 and +8, at the hardcoded width 64; neither
 * body resolves a width, writes a GPR, a tag, or a flag. The arm table is
 * closed over the one fact either body's branch chain consults - whether the
 * operand register is the stack pointer; the base-form table records how each
 * opcode's ordinary arm resolves a X86_REG_NONE operand, which is the
 * asymmetry that keeps the two opcodes from sharing one addressing rule. The
 * contract selects these; the lane values, the addressing offset, and the
 * memory accesses stay in the two C handlers, which select the arm, base form,
 * and lane offsets through these macros.
 */
{op_asserts}
{arm_defines}
{base_defines}
{lane_defines}

/* The pair is two consecutive lanes of one lane width each. */
#define KPROG_X86_XMM0_LANES {len(lane_rows)}U
#define KPROG_X86_XMM0_LANE_BYTES 8U
_Static_assert(X86_WIDTH_64 == 8U, "x86 width code drift");
_Static_assert(KPROG_X86_XMM0_LANE_BYTES == X86_WIDTH_64,
\t       "x86 xmm0 lane width drift");
_Static_assert(KPROG_X86_XMM0_LANE_HI - KPROG_X86_XMM0_LANE_LO ==
\t       KPROG_X86_XMM0_LANE_BYTES, "x86 xmm0 lanes not consecutive");
/*
 * BASE_IS_RSP is true when the operand register is the stack pointer; a
 * stack-pointer operand moves the pair through the C stack helper, every other
 * operand through process memory. Both arms move the same two lanes at the
 * same offsets. The input is evaluated once. No flags are written.
 */
#define KPROG_X86_XMM0_ARM(BASE_IS_RSP)                                     \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_xmm0_arm;                                 \\
\t\tif (BASE_IS_RSP)                                           \\
\t\t\t__kprog_x86_xmm0_arm =                             \\
\t\t\t\tKPROG_X86_XMM0_ARM_STACK;                  \\
\t\telse                                                       \\
\t\t\t__kprog_x86_xmm0_arm =                             \\
\t\t\t\tKPROG_X86_XMM0_ARM_MEMORY;                 \\
\t\t__kprog_x86_xmm0_arm;                                      \\
\t}})
/*
 * LANE_INDEX is 0 for the low lane and 1 for the high lane; the table maps
 * each index to the lane's byte offset within the pair. Two consecutive
 * 8-byte windows, low lane first. The input is evaluated once.
 */
#define KPROG_X86_XMM0_LANE_OFFSET(LANE_INDEX)                              \\
\t(((LANE_INDEX) == 0U) ? KPROG_X86_XMM0_LANE_LO                     \\
\t\t\t      : KPROG_X86_XMM0_LANE_HI)
/*
 * OP_IS_LOAD is true for `X86_OP_LOAD_XMM0`; the table gives the ordinary
 * arm's base form. The load's X86_REG_NONE operand is the raw absolute
 * immediate pointer, the store's is the null pointer. The input is evaluated
 * once.
 */
#define KPROG_X86_XMM0_BASE_FORM(OP_IS_LOAD)                                \\
\t((OP_IS_LOAD) ? KPROG_X86_XMM0_BASE_ABS_IMM                        \\
\t\t       : KPROG_X86_XMM0_BASE_NULL_PLUS_DISP)
/*
 * Whether the ordinary arm adds the addressing offset to its base. The load's
 * absolute-immediate form discards the offset; a register base and the store's
 * null-base form both add it. Inputs are evaluated once.
 */
#define KPROG_X86_XMM0_ADDS_DISP(BASE_IS_NONE, BASE_FORM)                   \\
\t(((BASE_FORM) == KPROG_X86_XMM0_BASE_ABS_IMM)                      \\
\t\t ? !(BASE_IS_NONE) : 1U)
/*
 * The ordinary arm's base pointer. A X86_REG_NONE operand contributes the
 * opcode's base form: the load's absolute-immediate form reads it as the raw
 * instruction-immediate artifact, sign reinterpreted, while the store's
 * null-base form reads it as the null pointer. Every register operand
 * contributes the register's pointer value, whatever the opcode. BASE_IS_NONE
 * and BASE_FORM select between the readings. Inputs are evaluated once.
 */
#define KPROG_X86_XMM0_BASE_PTR(BASE_IS_NONE, BASE_FORM, IMM, REG_PTR)      \\
	((BASE_IS_NONE)                                                    \\
		 ? (((BASE_FORM) == KPROG_X86_XMM0_BASE_ABS_IMM)           \\
			    ? (void *)(long)(IMM) : (void *)0)         \\
		 : (void *)(REG_PTR))
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    opcode_rows, arm_rows, lane_rows = load()
    for path, expected in (
            (LEAN, render_lean(opcode_rows, arm_rows, lane_rows)),
            (CHEADER, render_c(opcode_rows, arm_rows, lane_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 xmm0 contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)

if __name__ == "__main__":
    main()
