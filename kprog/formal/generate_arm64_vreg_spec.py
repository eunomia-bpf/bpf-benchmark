#!/usr/bin/env python3
"""Generate the AArch64 vector-register-file half-mapping contract.

The generated Lean step `GeneratedArm64Vreg` and the C macro
`KPROG_ARM64_VREG_*` describe how the four vector memory-transfer opcodes map
onto the simulator's two 64-bit vector-register state fields:

  * the 128-bit vector register is split into two independent 64-bit halves; the
    low half lives in `__a64_v0` (slot offset 0) and the high half in
    `__a64_v0_hi` (slot offset 8);
  * a `.D0` transfer touches the low half only; a `.Q0` transfer touches the low
    half and then the high half, in that order;
  * the two halves are distinct slots, so a `.Q0` transfer that aliased them
    would not satisfy the plan.

The state-field names are re-checked against kprog/arm64/arm64_sim_local_bpf.h
by `load()`. The offset and select macros read their argument once; no NZCV is
written. This contract is distinct from `arm64_dq_mem_refines`, which fixes the
*memory* lanes a transfer touches, not which vector-register state field each
lane maps into.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_vreg_spec.json"
STATE_HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64Vreg.lean"
CHEADER = ROOT / "generated/arm64_vreg.h"

LOW_FIELD = "__a64_v0"
HIGH_FIELD = "__a64_v0_hi"
LOW_OFFSET = 0
HIGH_OFFSET = 8

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Vreg",
    "selector": "vector_register_file_half_mapping_and_write_order",
    "state_fields": {"low": LOW_FIELD, "high": HIGH_FIELD},
    "low_offset": LOW_OFFSET,
    "high_offset": HIGH_OFFSET,
    "opcodes": [
        {"name": "loadD0", "define": "ARM64_OP_LOAD_D0", "code": "0x28",
         "codeIndex": 0, "access": "load", "halves": "one"},
        {"name": "loadQ0", "define": "ARM64_OP_LOAD_Q0", "code": "0x2a",
         "codeIndex": 1, "access": "load", "halves": "two"},
        {"name": "storeD0", "define": "ARM64_OP_STORE_D0", "code": "0x29",
         "codeIndex": 2, "access": "store", "halves": "one"},
        {"name": "storeQ0", "define": "ARM64_OP_STORE_Q0", "code": "0x2b",
         "codeIndex": 3, "access": "store", "halves": "two"},
    ],
}

OP_ORDER = ("loadD0", "loadQ0", "storeD0", "storeQ0")
OP_DEFINES = {"loadD0": "ARM64_OP_LOAD_D0", "loadQ0": "ARM64_OP_LOAD_Q0",
              "storeD0": "ARM64_OP_STORE_D0", "storeQ0": "ARM64_OP_STORE_Q0"}
OP_CODES = {"loadD0": "0x28", "loadQ0": "0x2a", "storeD0": "0x29",
            "storeQ0": "0x2b"}
OP_CODE_INDEX = {"loadD0": 0, "loadQ0": 1, "storeD0": 2, "storeQ0": 3}
OP_ACCESS = {"loadD0": "load", "loadQ0": "load", "storeD0": "store",
             "storeQ0": "store"}
OP_HALVES = {"loadD0": "one", "loadQ0": "two", "storeD0": "one",
             "storeQ0": "two"}

# The Lean plan literal and the C half-select body per half count.
HALF_PLAN = {"one": "[.low]", "two": "[.low, .high]"}
C_HALF_SELECT = {
    "one": "KPROG_ARM64_VREG_HALF_LOW",
    "two": "((N) == 0U ? KPROG_ARM64_VREG_HALF_LOW : KPROG_ARM64_VREG_HALF_HIGH)",
}


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 vector-register specification: {data!r}")
    ops = data["opcodes"]
    for key, table in (("name", OP_ORDER), ("define", OP_DEFINES),
                       ("code", OP_CODES), ("codeIndex", OP_CODE_INDEX),
                       ("access", OP_ACCESS), ("halves", OP_HALVES)):
        expected_col = [table[n] if isinstance(table, dict) else n
                        for n in OP_ORDER]
        if [row[key] for row in ops] != expected_col:
            raise SystemExit(
                f"invalid arm64 vector-register {key} column: {ops!r}")
    if len({row["define"] for row in ops}) != len(ops):
        raise SystemExit(f"duplicate arm64 vector-register opcode: {ops!r}")
    if data["low_offset"] != LOW_OFFSET or data["high_offset"] != HIGH_OFFSET:
        raise SystemExit(f"invalid arm64 vector-register offsets: {data!r}")
    if data["low_offset"] == data["high_offset"]:
        raise SystemExit(f"arm64 vector-register halves alias: {data!r}")
    text = STATE_HEADER.read_text()
    for field in (LOW_FIELD, HIGH_FIELD):
        if f"__u64 {field} = 0" not in text:
            raise SystemExit(
                f"arm64 vector-register state drift from "
                f"kprog/arm64/arm64_sim_local_bpf.h: {field}")
    return data


def render_lean(spec: dict) -> str:
    ops = spec["opcodes"]
    op_ctors = "\n".join(f"  | {row['name']}" for row in ops)
    access_arms = "\n".join(
        f"  | .{row['name']} => .{row['access']}" for row in ops)
    halves_arms = "\n".join(
        f"  | .{row['name']} => .{row['halves']}" for row in ops)
    index_arms = "\n".join(
        f"  | .{row['name']} => {row['codeIndex']}" for row in ops)
    plan_arms = "\n".join(
        f"  | .{row['name']} => {HALF_PLAN[row['halves']]}" for row in ops)
    return f'''-- Generated by generate_arm64_vreg_spec.py from arm64_vreg_spec.json.
import Std
namespace KProgFormal.GeneratedArm64Vreg
/-- The four vector memory-transfer opcodes this contract spans. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- Whether the opcode loads into or stores from the vector register file. -/
inductive Access where
  | load
  | store
deriving DecidableEq, Repr
/-- Which 64-bit half of the 128-bit vector register an access touches: the low
half `__a64_v0` or the high half `__a64_v0_hi`. -/
inductive Half where
  | low
  | high
deriving DecidableEq, Repr
/-- How many vector-register halves the opcode moves. -/
inductive Halves where
  | one
  | two
deriving DecidableEq, Repr
/-- The access direction of each opcode. -/
def access : Op -> Access
{access_arms}
/-- The number of vector-register halves each opcode moves. -/
def halves : Op -> Halves
{halves_arms}
/-- The arm index of the opcode in the four-way dispatch chain, decoded from the
opcode code, so the chain order is a checked fact. -/
def armIndex : Op -> Nat
{index_arms}
/-- The number of halves a half count moves. -/
def halfCount : Halves -> Nat
  | .one => 1
  | .two => 2
/-- The state-field slot offset of a half: the low half is the first 64-bit
field, the high half follows one 64-bit field higher. -/
def halfOffset : Half -> Nat
  | .low => {spec["low_offset"]}
  | .high => {spec["high_offset"]}
/-- The ordered half plan of each opcode, the order the bodies read or write
state: the low half alone (`.D0`) or the low half then the high half (`.Q0`). -/
def plan : Op -> List Half
{plan_arms}
end KProgFormal.GeneratedArm64Vreg
'''


def render_c(spec: dict) -> str:
    ops = spec["opcodes"]
    low = spec["low_offset"]
    high = spec["high_offset"]

    op_asserts = "\n".join(
        f'_Static_assert({row["define"]} == {row["code"]}U, '
        f'"arm64 vreg {row["name"]} opcode drift");'
        for row in ops)
    def cont(text: str) -> str:
        return "\t" + text.ljust(63) + "\\"

    def suffix(row: dict) -> str:
        return row["define"].replace("ARM64_OP_", "")

    handled = "\n".join(
        (cont("((OP) == %s)%s" % (row["define"], " ||"))
         if i < len(ops) - 1
         else "\t((OP) == %s)" % row["define"])
        for i, row in enumerate(ops))
    handled_asserts = "\n".join(
        f'_Static_assert(KPROG_ARM64_VREG_HANDLED({row["define"]}), '
        f'"arm64 vreg coverage drift");'
        for row in ops)
    access_defs = "\n".join(
        f'#define KPROG_ARM64_VREG_OP_{suffix(row)}_ACCESS '
        f'KPROG_ARM64_VREG_ACCESS_{row["access"].upper()}'
        for row in ops)
    halves_defs = "\n".join(
        f'#define KPROG_ARM64_VREG_OP_{suffix(row)}_HALVES '
        f'{1 if row["halves"] == "one" else 2}U'
        for row in ops)
    index_defs = "\n".join(
        f'#define KPROG_ARM64_VREG_OP_{suffix(row)}_INDEX '
        f'{row["codeIndex"]}U'
        for row in ops)
    select_defs = "\n".join(
        f'#define KPROG_ARM64_VREG_OP_{suffix(row)}_SELECT(N) '
        f'{C_HALF_SELECT[row["halves"]]}'
        for row in ops)

    index_branches = "\n".join(
        cont("else if ((OP) == %s)" % row["define"]) + "\n" +
        cont("\t__kprog_a64_vreg_idx = %dU;" % row["codeIndex"])
        for row in ops[1:-1])
    return f'''/* Generated by generate_arm64_vreg_spec.py from arm64_vreg_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_VREG_H
#define KPROG_FORMAL_GENERATED_ARM64_VREG_H
/*
 * AArch64 vector-register-file half mapping. The 128-bit vector register is
 * split into two independent 64-bit state fields: the low half `{spec["state_fields"]["low"]}`
 * at slot offset {low} and the high half `{spec["state_fields"]["high"]}` at slot offset {high}. A `.D0`
 * transfer touches the low half only; a `.Q0` transfer touches the low half and
 * then the high half. The memory offset and the pre/post base adjustment stay in
 * their own proved contracts; this contract fixes which state field each half
 * maps into and in which order the halves are touched.
 */
{op_asserts}
#define KPROG_ARM64_VREG_HANDLED(OP)                                        \\
{handled}
{handled_asserts}
/* The low and high half slot offsets, distinct 64-bit state fields. */
#define KPROG_ARM64_VREG_LOW_OFFSET {low}U
#define KPROG_ARM64_VREG_HIGH_OFFSET {high}U
_Static_assert(KPROG_ARM64_VREG_LOW_OFFSET != KPROG_ARM64_VREG_HIGH_OFFSET,
\t       "arm64 vreg half offsets alias");
/* The two half selectors and the two access-direction codes. */
#define KPROG_ARM64_VREG_HALF_LOW 0U
#define KPROG_ARM64_VREG_HALF_HIGH 1U
#define KPROG_ARM64_VREG_ACCESS_LOAD 0U
#define KPROG_ARM64_VREG_ACCESS_STORE 1U
/* The slot offset of a half: low half at offset {low}, high half at offset {high}. */
#define KPROG_ARM64_VREG_HALF_OFFSET(HALF)                                  \\
\t((HALF) == KPROG_ARM64_VREG_HALF_HIGH ? KPROG_ARM64_VREG_HIGH_OFFSET \\
\t\t\t\t\t      : KPROG_ARM64_VREG_LOW_OFFSET)
/*
 * Access direction of each opcode: 0 loads into the vector register file, 1
 * stores from it.
 */
{access_defs}
/*
 * Half count of each opcode: 1 touches the low half only (`.D0`), 2 touches the
 * low half then the high half (`.Q0`).
 */
{halves_defs}
/*
 * The arm index of each opcode in the four-way `OP == LOAD_D0 / LOAD_Q0 /
 * STORE_D0 / STORE_Q0` chain, decoded from the opcode code so the chain order is
 * a checked fact.
 */
{index_defs}
#define KPROG_ARM64_VREG_INDEX(OP)                                    \\
\t({{                                                              \\
{cont("__u32 __kprog_a64_vreg_idx;")}
{cont("if ((OP) == %s)" % ops[0]["define"])}
{cont("\t__kprog_a64_vreg_idx = %dU;" % ops[0]["codeIndex"])}
{index_branches}
{cont("else")}
{cont("\t__kprog_a64_vreg_idx = %dU;" % ops[-1]["codeIndex"])}
{cont("__kprog_a64_vreg_idx;")}
\t}})                                                              \\
\t/* the compound expression yields the arm index */
/*
 * The half plan of each opcode: `SELECT(N)` yields the half index touched at
 * plan position `N`, low half first. A `.D0` opcode ignores `N`.
 */
{select_defs}
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    spec = load()
    for path, expected in ((LEAN, render_lean(spec)), (CHEADER, render_c(spec))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 vector-register contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
