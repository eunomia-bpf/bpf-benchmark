#!/usr/bin/env python3
"""Generate the shared AArch64 store body-selection contract.

The hand-written store helper of `kprog/arm64/arm64_sim_local_bpf.h`,
`ARM64_SIM_L_MEM_WRITE`, writes a resolved access to one of two *destinations*:

  * the **stack** body, which routes the access through the stack arena write
    helper `ARM64_SIM_L_STACK_WRITE_TAG` (and so through the stack slot-tag
    contract `KPROG_ARM64_STACK_TAG`), and is used when the base register is the
    stack pointer *or* its resolved tag names a stack slot;
  * the **memory** body, the plain little-endian byte store
    `ARM64_SIM_L_STORE_ADDR` (and so through the store-bytes contract
    `KPROG_ARM64_STORE_BYTES`), used for every other base.

The selection is the *same* closed predicate the load path uses: the generated
load dispatch `KPROG_ARM64_MEM_READ_SRC` selects its stack source exactly when
`BASE_IS_SP || TAG == ARM64_SIM_TAG_STACK`, and the store helper must select the
stack body on that identical predicate. The generated table
`GeneratedArm64MemWriteArm.armOf` and the plain-expression C macro
`KPROG_ARM64_MEM_WRITE_ARM` expose that body choice.

The generator is independent of the bodies it describes: it holds its own
literal case enumeration and re-derives the live store helper text from the
simulator header, then requires the helper to go through the generated selector
and to keep both bodies.

`KProgFormal/Arm64MemWriteArmShape.lean` proves the generated table equals an
independent construction from the literals, and ties the store classification to
the load path's own space/source table so the two cannot drift.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_mem_write_arm_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64MemWriteArm.lean"
CHEADER = ROOT / "generated/arm64_mem_write_arm.h"

# The independent enumeration of the two destinations a store selects between,
# in arm-code order: (arm, arm define, arm code, body).
_ARMS = [
    ("stackWrite", "KPROG_ARM64_MEM_WRITE_ARM_STACK", 0, "stack_write_tag"),
    ("memoryStore", "KPROG_ARM64_MEM_WRITE_ARM_MEMORY", 1,
     "little_endian_store"),
]
# The independent enumeration of the four (base is SP, stack-tagged) cases a
# store can have, in classification order: (case, base is SP, stack-tagged,
# stack body).
_CASES = [
    ("sp_tagged", True, True, True),
    ("sp_scalar", True, False, True),
    ("reg_tagged", False, True, True),
    ("reg_scalar", False, False, False),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64MemWriteArm",
    "selector": "base_is_sp_or_stack_tag_then_stack_else_memory",
    "arms": [{"arm": arm, "arm_define": define, "arm_code": code,
              "body": body}
             for arm, define, code, body in _ARMS],
    "cases": [{"name": name, "base_is_sp": bsp, "stack_tagged": tagged,
               "stack": stack}
              for name, bsp, tagged, stack in _CASES],
}
ARM_COLUMNS = ("arm", "arm_define", "arm_code", "body")
CASE_COLUMNS = ("name", "base_is_sp", "stack_tagged", "stack")

# The live routed store helper text, between the store helper's `#define`
# opcode title and the next `#define` (`ARM64_SIM_L_DQ_MEM_STEP`).
STORE_START = "#define ARM64_SIM_L_MEM_WRITE("
STORE_END = "#define ARM64_SIM_L_DQ_MEM_STEP("
STORE_SELECTOR = "KPROG_ARM64_MEM_WRITE_ARM("
STACK_BODY = "ARM64_SIM_L_STACK_WRITE_TAG("
MEMORY_BODY = "ARM64_SIM_L_STORE_ADDR("
# The hand-written selection the routed helper must no longer contain: the SP
# test disjoined with the stack-tag test. The two bodies use neither `||` nor the
# stack-tag comparison, so either spelling means the body choice is still made
# by hand.
HAND_SP_TEST = "ARM64_SP ||"
HAND_TAG_TEST = "== ARM64_SIM_TAG_STACK"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def store_region():
    return region_between(STORE_START, STORE_END)


def check_region(region):
    """A routed store helper must select its body through the generated
    two-fact selector and still keep both bodies; it must not select by hand."""
    if STORE_SELECTOR not in region:
        raise SystemExit(
            "arm64 store helper does not route through the generated selector")
    if STACK_BODY not in region:
        raise SystemExit(
            "arm64 store helper does not keep the stack-write body")
    if MEMORY_BODY not in region:
        raise SystemExit(
            "arm64 store helper does not keep the byte-store body")
    if HAND_SP_TEST in region or HAND_TAG_TEST in region:
        raise SystemExit(
            "arm64 store helper selects its body by hand instead of through "
            "the generated selector")


def check_against_header():
    """The live store helper must route its body choice through the generated
    selector."""
    check_region(store_region())


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid arm64 mem write arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 mem write arm specification: {data!r}")
    for index, column in enumerate(ARM_COLUMNS):
        want = [row[column] for row in EXPECTED["arms"]]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid arm64 mem write arm arm {column}: "
                             f"{EXPECTED['arms']!r}")
    if len(EXPECTED["arms"]) != 2:
        raise SystemExit("arm64 mem write arm must select between exactly 2 "
                         "destinations")
    if [row["arm_code"] for row in EXPECTED["arms"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 mem write arm codes: {EXPECTED['arms']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(f"invalid arm64 mem write arm case {column}: "
                             f"{EXPECTED['cases']!r}")
    if [row["stack"] for row in EXPECTED["cases"]] != [True, True, True, False]:
        raise SystemExit(
            f"invalid arm64 mem write arm table: {EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    cases = spec["cases"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(row["arm_code"]) for row in arms)
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {row["arm_code"]}' for row in arms)
    body_of = "\n".join(
        f'  | .{row["arm"]} => "{row["body"]}"' for row in arms)
    case_ctors = "\n".join(f"  | {row['name']}" for row in cases)
    case_table = "\n".join(
        f"  | .{row['name']} => {'true' if row['stack'] else 'false'}"
        for row in cases)
    classify = []
    for bsp in (True, False):
        for tagged in (True, False):
            row = next(r for r in cases
                       if r["base_is_sp"] == bsp
                       and r["stack_tagged"] == tagged)
            classify.append(f"    | {'true' if bsp else 'false'}, "
                            f"{'true' if tagged else 'false'} => .{row['name']}")
    classify = "\n".join(classify)
    arm_of_case = "\n".join(
        f"  | .{row['name']} => ."
        f"{'stackWrite' if row['stack'] else 'memoryStore'}"
        for row in cases)
    return f'''-- Generated by generate_arm64_mem_write_arm_spec.py from arm64_mem_write_arm_spec.json.
import Std
namespace KProgFormal.GeneratedArm64MemWriteArm
/-- The two destinations an AArch64 store selects between: the stack arena
write (through the slot-tag contract) and the plain little-endian byte store. -/
inductive Arm where
  | {arms[0]["arm"]}
  | {arms[1]["arm"]}
deriving DecidableEq, Repr
/-- The number of destinations a store selects between. -/
def armCount : Nat := {len(arms)}
/-- The two destinations a store selects between, in arm-code order. -/
def armNames : List String := [{names}]
/-- The arm code of each destination, in arm-code order; the codes are the
values the selector yields so the table and the macro cannot disagree. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a destination. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The storage effect each arm performs. -/
def bodyOfArm : Arm -> String
{body_of}
/-- The destination a store selects: the stack arena body exactly when the base
register is the stack pointer or its resolved tag names a stack slot, the plain
byte store otherwise. The two facts are a closed pair, so the selection is
total. -/
def armOf (baseIsSp stackTagged : Bool) : Arm :=
  if baseIsSp || stackTagged then .{arms[0]["arm"]} else .{arms[1]["arm"]}
/-- The destination an arm code names, or `none` when the code names no
destination. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
/-- The four (base is SP, stack-tagged) cases a store can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a store by whether its base is the stack pointer and whether its
resolved tag names a stack slot. -/
def classify (baseIsSp stackTagged : Bool) : Case :=
  match baseIsSp, stackTagged with
{classify}
/-- Whether a case is served by the stack body. -/
def stackBody : Case -> Bool
{case_table}
/-- Independent statement of the selection: a store uses the stack body exactly
when its base is the stack pointer or its tag names a stack slot. -/
def stackSpec (baseIsSp stackTagged : Bool) : Bool := baseIsSp || stackTagged
/-- The four-case table agrees with the independent `||` statement for every
store: classifying then testing the table equals the direct disjunction. -/
theorem stack_refines (baseIsSp stackTagged : Bool) :
    stackBody (classify baseIsSp stackTagged) =
      stackSpec baseIsSp stackTagged := by
  cases baseIsSp <;> cases stackTagged <;> rfl
/-- The destination a case selects, from the case table. -/
def armOfCase : Case -> Arm
{arm_of_case}
/-- The destination selector equals the case table for every store: naming the
destination from the two facts directly is the same as classifying and
dispatching on the case. -/
theorem armOf_refines (baseIsSp stackTagged : Bool) :
    armOf baseIsSp stackTagged = armOfCase (classify baseIsSp stackTagged) := by
  cases baseIsSp <;> cases stackTagged <;> rfl
end KProgFormal.GeneratedArm64MemWriteArm
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    stack = arms[0]["arm_define"]
    memory = arms[1]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {row["arm_code"]}U' for row in arms)
    return f'''/* Generated by generate_arm64_mem_write_arm_spec.py from arm64_mem_write_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MEM_WRITE_ARM_H
#define KPROG_FORMAL_GENERATED_ARM64_MEM_WRITE_ARM_H
/*
 * AArch64 store body-selection contract: the store helper
 * `ARM64_SIM_L_MEM_WRITE` writes a resolved access to one of two destinations,
 * selected from a closed pair of facts: whether the base register is the stack
 * pointer, and whether the base's resolved tag names a stack slot. When either
 * holds the access goes through the stack arena write helper
 * `ARM64_SIM_L_STACK_WRITE_TAG`; every other base goes through the plain
 * little-endian byte store `ARM64_SIM_L_STORE_ADDR` (the generated
 * `arm64_store_bytes.h` contract). This is the *same* predicate the load
 * dispatch `KPROG_ARM64_MEM_READ_SRC` (the generated `arm64_mem_dispatch.h`
 * contract) selects its stack source on; `KProgFormal/Arm64MemWriteArmShape.lean`
 * proves the generated `armOf` equal to an independent construction from the
 * facts and ties it to the load path's space/source table.
 * This header is included after the `ARM64_SIM_TAG_*` decodes, so the drift
 * checks bind the hand-written stack-tag name to the generated selection.
 */
/* The number of destinations the helper selects between. */
#define KPROG_ARM64_MEM_WRITE_ARM_COUNT {count}U
{arm_defines}
/*
 * The destination a store selects: the stack arena body exactly when the base
 * register is the stack pointer or its tag names a stack slot, the plain byte
 * store otherwise. Both inputs are evaluated once.
 */
#define KPROG_ARM64_MEM_WRITE_ARM(BASE_IS_SP, TAG)                          \\
\t((__u8)(((BASE_IS_SP) || (TAG) == ARM64_SIM_TAG_STACK)              \\
\t\t ? {stack}                       \\
\t\t : {memory}))
_Static_assert(KPROG_ARM64_MEM_WRITE_ARM_COUNT == {count}U,
\t       "arm64 mem write arm count drift");
_Static_assert({stack} != {memory},
\t       "arm64 mem write arm codes must be distinct");
_Static_assert({stack} == 0U && {memory} == 1U,
\t       "arm64 mem write arm code drift");
/* The selector must name each destination at its own fact pair. */
_Static_assert(KPROG_ARM64_MEM_WRITE_ARM(1, ARM64_SIM_TAG_SCALAR) == {stack},
\t       "arm64 mem write arm sp selection drift");
_Static_assert(KPROG_ARM64_MEM_WRITE_ARM(0, ARM64_SIM_TAG_STACK) == {stack},
\t       "arm64 mem write arm stack-tag selection drift");
_Static_assert(KPROG_ARM64_MEM_WRITE_ARM(1, ARM64_SIM_TAG_STACK) == {stack},
\t       "arm64 mem write arm sp tagged selection drift");
_Static_assert(KPROG_ARM64_MEM_WRITE_ARM(0, ARM64_SIM_TAG_SCALAR) == {memory},
\t       "arm64 mem write arm memory selection drift");
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    spec = load()
    for path, expected in ((LEAN, render_lean(spec)),
                           (CHEADER, render_c(spec))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 mem write arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
