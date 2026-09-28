#!/usr/bin/env python3
"""Generate the x86-64 `_SETCC` handler-composition contract.

This contract models `X86_SIM_L_EXEC_SETCC`, the one-line body `X86_OP_SETCC`
routes to:

    X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),
        X86_SIM_L_EVAL_CC(KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)),
        X86_WIDTH_8, KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX))

Two decodes are generated, because they are the two places a plausible bug
hides and the two places the simulator's raw encoding meets the Lean model.

1. `cond_rows` is the condition-code table. The C macro `KPROG_X86_EVAL_CC`
   consumes the *raw* condition byte out of the AUX payload lane and compares it
   against the `X86_CC_*` constants with a `: 0` default, while the Lean side
   `GeneratedX86Cond.eval` consumes the `Cond` inductive. Neither statement is
   the other, so each row records three independent facts: the raw code the C
   compares against, the `Cond` constructor it denotes, and a boolean
   expression for the condition. `condOf` is generated from the raw codes,
   `evalCond` from the expressions — it is *not* a call into
   `GeneratedX86Cond.eval`, so the handler proof that the two agree has real
   content: a transposition in either the generated code table or the
   expression table is caught. `evalRaw` composes them and yields `false` for
   every code outside the accepted subset, which is a real semantic choice, not
   an omission — the accepted subset excludes the parity codes.

2. `lane_rows` is the destination byte-lane table. The C `KPROG_X86_WRITE_REG8`
   tests `BYTE_SHIFT == 8U`, so *only* the exact value 8 selects the high byte
   and every other value selects the low byte — not "nonzero selects high", the
   natural wrong reading. The table is closed over the one fact the branch
   consults: whether the decoded AUX destination shift equals 8.

The contract selects the condition and the lane; the writeback is the register
write-at contract, and the AUX payload/destination-shift decodes stay in
`KPROG_X86_REG_LANE_AUX_*`.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_setcc_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86Setcc.lean"
CHEADER = ROOT / "generated/x86_setcc.h"

# The accepted condition subset, in the order of the generated `Cond`
# inductive: Lean constructor, raw `X86_CC_*` code and define the C macro
# compares against, and an independent boolean expression for the condition.
# The expressions restate `KPROG_X86_EVAL_CC`'s arms; they are deliberately not
# a reference to the `Cond` table so the handler proof has content.
COND_ORDER = (
    ("o", "X86_CC_O", 0, "of"),
    ("no", "X86_CC_NO", 1, "!of"),
    ("b", "X86_CC_B", 2, "cf"),
    ("ae", "X86_CC_AE", 3, "!cf"),
    ("e", "X86_CC_E", 4, "zf"),
    ("ne", "X86_CC_NE", 5, "!zf"),
    ("be", "X86_CC_BE", 6, "cf || zf"),
    ("a", "X86_CC_A", 7, "!cf && !zf"),
    ("s", "X86_CC_S", 8, "sf"),
    ("ns", "X86_CC_NS", 9, "!sf"),
    ("l", "X86_CC_L", 12, "sf != of"),
    ("ge", "X86_CC_GE", 13, "sf == of"),
    ("le", "X86_CC_LE", 14, "zf || (sf != of)"),
    ("g", "X86_CC_G", 15, "!zf && (sf == of)"),
)

UNSUPPORTED_CC_CODES = (10, 11)

EXPECTED = {
    "schema_version": 1,
    "operation": "x86SetccHandler",
    "selector": "aux_condition_code_and_destination_lane",
    "cond_rows": [
        {
            "cond": name,
            "cc_code": code,
            "cc_define": define,
            "expr": expr,
        }
        for name, define, code, expr in COND_ORDER
    ],
    "unsupported_cc_codes": list(UNSUPPORTED_CC_CODES),
    "lane_rows": [
        {
            "dst_shift_is_eight": True,
            "lane": "high",
            "lane_define": "KPROG_X86_SETCC_LANE_HIGH",
        },
        {
            "dst_shift_is_eight": False,
            "lane": "low",
            "lane_define": "KPROG_X86_SETCC_LANE_LOW",
        },
    ],
}

COND_INDEX = {name: index for index, (name, _, _, _) in enumerate(COND_ORDER)}
COND_CODES = {name: code for name, _, code, _ in COND_ORDER}
COND_DEFINES = {name: define for name, define, _, _ in COND_ORDER}
COND_EXPRS = {name: expr for name, _, _, expr in COND_ORDER}

LANE_ORDER = (True, False)
LANE_NAMES = {True: "high", False: "low"}
LANE_DEFINES = {
    "high": "KPROG_X86_SETCC_LANE_HIGH",
    "low": "KPROG_X86_SETCC_LANE_LOW",
}
LANE_CODES = {"low": 0, "high": 1}

SUPPORTED_CODES = sorted(COND_CODES.values())


def load() -> tuple[list[dict], list[dict]]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 setcc specification: {data!r}")
    cond_rows = EXPECTED["cond_rows"]
    lane_rows = EXPECTED["lane_rows"]
    if len(cond_rows) != len(COND_ORDER):
        raise SystemExit(f"invalid x86 setcc condition count: {cond_rows!r}")
    seen_codes: set[int] = set()
    for row in cond_rows:
        name = row["cond"]
        if name not in COND_INDEX:
            raise SystemExit(f"unknown x86 setcc condition: {row!r}")
        if row["cc_code"] != COND_CODES[name]:
            raise SystemExit(f"invalid x86 setcc condition code: {row!r}")
        if row["cc_define"] != COND_DEFINES[name]:
            raise SystemExit(f"invalid x86 setcc condition define: {row!r}")
        if row["expr"] != COND_EXPRS[name]:
            raise SystemExit(f"invalid x86 setcc condition expression: {row!r}")
        if row["cc_code"] in seen_codes:
            raise SystemExit(f"duplicate x86 setcc condition code: {row!r}")
        seen_codes.add(row["cc_code"])
        if row["cc_code"] in UNSUPPORTED_CC_CODES:
            raise SystemExit(f"unsupported code in x86 setcc table: {row!r}")
    if sorted(seen_codes) != SUPPORTED_CODES:
        raise SystemExit(f"incomplete x86 setcc condition table: {seen_codes!r}")
    if sorted(SUPPORTED_CODES + list(UNSUPPORTED_CC_CODES)) != list(range(16)):
        raise SystemExit("unsupported x86 setcc codes are not exact")
    if [row["dst_shift_is_eight"] for row in lane_rows] != list(LANE_ORDER):
        raise SystemExit(f"invalid x86 setcc lane row order: {lane_rows!r}")
    for row in lane_rows:
        lane = LANE_NAMES[row["dst_shift_is_eight"]]
        if row["lane"] != lane:
            raise SystemExit(f"invalid x86 setcc lane: {row!r}")
        if row["lane_define"] != LANE_DEFINES[lane]:
            raise SystemExit(f"invalid x86 setcc lane define: {row!r}")
    return cond_rows, lane_rows


def render_lean(cond_rows: list[dict], lane_rows: list[dict]) -> str:
    cond_of_arms = "\n  else ".join(
        f"if cc = {row['cc_code']} then some .{row['cond']}"
        for row in cond_rows)
    cond_of_body = "  " + cond_of_arms + "\n  else none"
    eval_cond_arms = "\n".join(
        f"  | .{row['cond']} => {row['expr']}" for row in cond_rows)
    lane_table = "\n".join(
        f"  | {'true' if row['dst_shift_is_eight'] else 'false'} => .{row['lane']}"
        for row in lane_rows)
    return f'''-- Generated by generate_x86_setcc_spec.py from x86_setcc_spec.json.
import KProgFormal.GeneratedX86Cond
import KProgFormal.GeneratedX86RegWrite
namespace KProgFormal.GeneratedX86Setcc
/-- The condition the raw `X86_CC_*` code denotes, or `none` for a code
outside the accepted subset (the parity codes and every code from 16 up). The
table is closed over the codes `KPROG_X86_EVAL_CC` compares against, so an
unsupported code is a defined false, not a missing arm. -/
def condOf (cc : BitVec 8) : Option GeneratedX86Cond.Cond :=
{cond_of_body}
/-- The condition evaluation, a restatement of `KPROG_X86_EVAL_CC`'s boolean
arms: the same conditions, each with the same expression. It is built from the
expressions, not from `GeneratedX86Cond.eval`, so a proof that the two agree is
the content that catches a transposed arm in either table. -/
def evalCond (cf zf sf of : Bool) : GeneratedX86Cond.Cond -> Bool
{eval_cond_arms}
/-- The raw condition-code evaluation: the generated condition table composed
with the generated expression table, and `false` for every unsupported code,
which is what the C macro's `: 0` default yields. -/
def evalRaw (cf zf sf of : Bool) (cc : BitVec 8) : Bool :=
  match condOf cc with
  | some cond => evalCond cf zf sf of cond
  | none => false
/-- The destination byte lane the handler writes. -/
inductive Lane where
  | low
  | high
  deriving DecidableEq, Repr
/-- The generated lane table over the one fact the C `KPROG_X86_WRITE_REG8`
branch consults: whether the decoded AUX destination shift equals 8. The
comparison is an equality, so every value other than 8 selects the low byte. -/
def lane : Bool -> Lane
{lane_table}
/-- Bridge from the generated lane to the register write-at lane the
writeback contract uses. -/
def toRegLane : Lane -> GeneratedX86RegWrite.ByteLane
  | .low => .low
  | .high => .high
end KProgFormal.GeneratedX86Setcc
'''


def render_c(cond_rows: list[dict], lane_rows: list[dict]) -> str:
    lane_defines = "\n".join(
        f"#define {LANE_DEFINES[name]} {LANE_CODES[name]}U"
        for name in ("low", "high"))
    cond_asserts = "\n".join(
        f'_Static_assert({row["cc_define"]} == {row["cc_code"]}U, '
        f'"x86 condition code drift");'
        for row in cond_rows)
    cond_rows_c = "\n".join(
        f"\t (CC) == {row['cc_define']} ? {row['cc_code']}U : \\"
        for row in cond_rows)
    unsupported = ", ".join(str(code) for code in UNSUPPORTED_CC_CODES)
    return f'''/* Generated by generate_x86_setcc_spec.py from x86_setcc_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_SETCC_H
#define KPROG_FORMAL_GENERATED_X86_SETCC_H
{cond_asserts}
#define KPROG_X86_SETCC_COND_NONE 0xffffU
/*
 * The raw condition byte is one of the supported `X86_CC_*` codes, or
 * KPROG_X86_SETCC_COND_NONE for a code outside the accepted subset. The fold
 * returns the matched code itself, so it also exposes the completeness of the
 * accepted subset to a caller that wants it. CC is the AUX payload byte.
 */
#define KPROG_X86_SETCC_COND_MATCHED(CC)                                   \\
{cond_rows_c}
\t KPROG_X86_SETCC_COND_NONE
/* The destination byte-lane codes. */
{lane_defines}
/*
 * DST_SHIFT is the decoded AUX destination shift
 * (`KPROG_X86_REG_LANE_AUX_DST_SHIFT`). The C write helper tests the exact
 * value 8, so only 8 selects the high byte and every other value the low byte.
 */
#define KPROG_X86_SETCC_LANE(DST_SHIFT)                                    \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_sc_lane;                                  \\
\t\tif ((DST_SHIFT) == 8U)                                     \\
\t\t\t__kprog_x86_sc_lane = KPROG_X86_SETCC_LANE_HIGH;   \\
\t\telse                                                       \\
\t\t\t__kprog_x86_sc_lane = KPROG_X86_SETCC_LANE_LOW;    \\
\t\t__kprog_x86_sc_lane;                                       \\
\t}})
/*
 * The unsupported raw condition codes, listed so a reader does not have to
 * derive the complement.
 */
#define KPROG_X86_SETCC_UNSUPPORTED_CC_CODES "{unsupported}"
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    cond_rows, lane_rows = load()
    for path, expected in (
            (LEAN, render_lean(cond_rows, lane_rows)),
            (CHEADER, render_c(cond_rows, lane_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 setcc contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
