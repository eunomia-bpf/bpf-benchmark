#!/usr/bin/env python3
"""Generate the AArch64 vector-register half state-field contract.

The hand-written AArch64 vector memory step of
`kprog/arm64/arm64_sim_local_bpf.h` -- `ARM64_SIM_L_DQ_MEM_STEP`, which every
`.D0`/`.Q0` load and store wrapper routes through -- moves the vector register
one 64-bit half at a time. Each moved half lands in one of the two 64-bit state
fields the vector register file is split into; the step picked that state field
by hand from the single closed fact that the moved half's slot offset is the
high half's offset:

    if (__a64_vreg_off == (__s64) KPROG_ARM64_VREG_HIGH_OFFSET)
            __a64_v0_hi = __a64_dq_value;
    else
            __a64_v0 = __a64_dq_value;

The state field is selected from a *single closed fact* -- whether the half the
plan names at this position is the high half, whose slot offset is the high
half's offset:

  * the **low** field, the first 64-bit state field of the vector register
    (`__a64_v0`, slot offset 0): the half the plan names is the low half, so its
    slot offset is the low half's offset, not the high half's;
  * the **high** field, the second 64-bit state field (`__a64_v0_hi`, slot
    offset 8): the half the plan names is the high half, so its slot offset is
    the high half's offset.

The generated table `GeneratedArm64VregField.fieldOf` and the plain-expression
C macro `KPROG_ARM64_VREG_FIELD` expose that field choice. The body previously
picked the state field by hand through the offset test, and this module makes
that 2-way field selection a machine-checked fact.

`KProgFormal/Arm64VregFieldShape.lean` proves the generated `fieldOf` equal to
an independent 2-way statement over the single fact, and ties the choice to the
vector-register contract (`GeneratedArm64Vreg.halfOffset` / `plan`) that fixes
which state field each half maps into and in which order the halves are touched.
The fact is closed, so the 2-way selection is total.

The generator is independent of the bodies it describes: it holds its own
literal field/case enumeration and re-derives the live vector memory step
region from the simulator header, then requires the step to go through the
generated field selector and to keep the hand offset test out.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_vreg_field_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64VregField.lean"
CHEADER = ROOT / "generated/arm64_vreg_field.h"

# The independent enumeration of the two vector-register half state fields, in
# code order: (field, field define, code, effect).
_FIELDS = [
    ("low",
     "KPROG_ARM64_VREG_LOW_FIELD",
     0, "low_half_state_field"),
    ("high",
     "KPROG_ARM64_VREG_HIGH_FIELD",
     1, "high_half_state_field"),
]
# The independent enumeration of the two (is high field) cases a moved half can
# have, in classification order: (case, is high field, field).
_CASES = [
    ("high_field", True, "high"),
    ("low_field", False, "low"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64VregField",
    "selector": "offset_is_high_then_high_field_else_low_field",
    "fields": [{"field": f, "field_define": d, "field_code": c, "effect": e}
               for f, d, c, e in _FIELDS],
    "cases": [{"name": n, "is_high_field": h, "field": fld}
              for n, h, fld in _CASES],
}
FIELD_COLUMNS = ("field", "field_define", "field_code", "effect")
CASE_COLUMNS = ("name", "is_high_field", "field")

# The live routed vector memory step text, between the step's own `#define` and
# the plain `.D0` load wrapper that follows it. The step is the one place the
# moved half's state field is chosen.
FIELD_REGION_START = "#define ARM64_SIM_L_DQ_MEM_STEP("
FIELD_REGION_END = "#define ARM64_SIM_L_LOAD_D0_MEM("
FIELD_SELECTOR = "KPROG_ARM64_VREG_FIELD("
# The hand-written offset test the routed step must no longer contain: the moved
# half's slot offset deciding the state field by hand. The step legitimately
# keeps the offset comparison as the selector's argument, so the `if (`-led
# offset test is the safe needle.
HAND_GATE = "if (__a64_vreg_off == (__s64) KPROG_ARM64_VREG_HIGH_OFFSET)"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(
            f"sim header no longer bounds the vector memory step region with "
            f"{start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """The vector memory step must select its state field through the
    generated 2-way selector; the region must not pick the state field by hand
    through the offset test."""
    if FIELD_SELECTOR not in region:
        raise SystemExit(
            "arm64 vector memory step does not route its state field "
            "through the generated field selector")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 vector memory step picks its state field by hand through "
            "the offset test instead of through the generated field selector")


def check_against_header():
    """The live vector memory step must select its state field through the
    generated field selector."""
    check_region(region_between(FIELD_REGION_START, FIELD_REGION_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 vreg field keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 vreg field specification: {data!r}")
    for index, column in enumerate(FIELD_COLUMNS):
        want = [row[column] for row in EXPECTED["fields"]]
        got = [entry[index] for entry in _FIELDS]
        if want != got:
            raise SystemExit(
                f"invalid arm64 vreg field {column}: {EXPECTED['fields']!r}")
    if len(EXPECTED["fields"]) != 2:
        raise SystemExit(
            "arm64 vreg field must select between exactly 2 fields")
    if [row["field_code"] for row in EXPECTED["fields"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 vreg field codes: {EXPECTED['fields']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 vreg field case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["field"] for row in EXPECTED["cases"]] != ["high", "low"]:
        raise SystemExit(
            f"invalid arm64 vreg field table: {EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    fields = spec["fields"]
    cases = spec["cases"]
    names = ", ".join(f'"{row["field"]}"' for row in fields)
    codes = ", ".join(str(row["field_code"]) for row in fields)
    ctor = ", ".join(f'.{row["field"]}' for row in fields)
    code_of = "\n".join(
        f'  | .{row["field"]} => {row["field_code"]}' for row in fields)
    effect_of = "\n".join(
        f'  | .{row["field"]} => "{row["effect"]}"' for row in fields)
    field_ctors = "\n".join(f'  | {row["field"]}' for row in fields)
    case_ctors = "\n".join(f'  | {row["name"]}' for row in cases)
    field_of_case = "\n".join(
        f'  | .{row["name"]} => .{row["field"]}' for row in cases)
    return f'''-- Generated by generate_arm64_vreg_field_spec.py from arm64_vreg_field_spec.json.
import Std
namespace KProgFormal.GeneratedArm64VregField
/-- The two 64-bit vector-register state fields a moved half lands in: the low
half's field `__a64_v0` and the high half's field `__a64_v0_hi`. -/
inductive Field where
{field_ctors}
deriving DecidableEq, Repr
/-- The number of vector-register state fields a moved half selects
between. -/
def fieldCount : Nat := {len(fields)}
/-- The two vector-register state fields, in code order. -/
def fieldNames : List String := [{names}]
/-- The field code of each state field, in code order; the codes are the values
the selector yields so the table and the macro cannot disagree. -/
def fieldCodes : List Nat := [{codes}]
/-- The field code of a state field. -/
def codeOfField : Field -> Nat
{code_of}
/-- The state-field effect each field performs. -/
def effectOfField : Field -> String
{effect_of}
/-- The vector-register state field a moved half lands in: the high half's
field exactly when the half the plan names is the high half (its slot offset is
the high half's offset), the low half's field otherwise. The fact is closed, so
the selection is total. -/
def fieldOf (isHighField : Bool) : Field :=
  if isHighField then .high
  else .low
/-- The state field a field code names, or `none` when the code names no
field. -/
def fieldOfCode (code : Nat) : Option Field :=
  (fieldCodes.zip [{ctor}]).lookup code
/-- The two (is high field) cases a moved half can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a moved half by whether it is the high half. -/
def classify (isHighField : Bool) : Case :=
  match isHighField with
  | true => .high_field
  | false => .low_field
/-- The vector-register state field a case performs, from the case table. -/
def fieldOfCase : Case -> Field
{field_of_case}
/-- The independent high-field fact: the high half's state field applies
exactly when the half the plan names is the high half, the closed fact. -/
def highFieldFact (isHighField : Bool) : Bool := isHighField
/-- The high-field fact is the identity for every moved half. -/
theorem highFieldFact_refines (isHighField : Bool) :
    highFieldFact isHighField = isHighField := by
  rfl
/-- The field selector equals the case table for every moved half: naming the
state field from the fact directly is the same as classifying and dispatching
on the case. -/
theorem fieldOf_refines (isHighField : Bool) :
    fieldOf isHighField = fieldOfCase (classify isHighField) := by
  cases isHighField <;> rfl
end KProgFormal.GeneratedArm64VregField
'''


def render_c(spec: dict) -> str:
    fields = spec["fields"]
    count = len(fields)
    low = fields[0]["field_define"]
    high = fields[1]["field_define"]
    field_defines = "\n".join(
        f'#define {row["field_define"]} {row["field_code"]}U'
        for row in fields)
    return f'''/* Generated by generate_arm64_vreg_field_spec.py from arm64_vreg_field_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_VREG_FIELD_H
#define KPROG_FORMAL_GENERATED_ARM64_VREG_FIELD_H
/*
 * AArch64 vector-register half state-field contract: the vector memory step
 * (`ARM64_SIM_L_DQ_MEM_STEP`) moves the SIMD register's halves one at a time,
 * and each moved half lands in one of the two 64-bit state fields the vector
 * register file is split into. The field is selected from the single closed
 * fact: whether the half the plan names at this position is the high half,
 * whose slot offset is the high half's offset (`KPROG_ARM64_VREG_HIGH_OFFSET`,
 * the offset `KPROG_ARM64_VREG_HALF_OFFSET` yields for the high half). The low
 * field is the low half `__a64_v0` at slot offset 0; the high field is the
 * high half `__a64_v0_hi` at slot offset 8. `KProgFormal/
 * Arm64VregFieldShape.lean` proves the generated `fieldOf` equal to an
 * independent 2-way statement and ties the choice to the vector-register
 * contract (`GeneratedArm64Vreg.halfOffset` / `plan`) that fixes which state
 * field each half maps into and in which order the halves are touched. The
 * fact is closed, so the 2-way selection is total. This header uses only
 * literal inputs, but it cross-pins its field choice to the half offsets, so
 * it is included after `generated/arm64_vreg.h`.
 */
/* The number of state fields a moved half selects between. */
#define KPROG_ARM64_VREG_FIELD_COUNT {count}U
{field_defines}
/*
 * The vector-register state field a moved half lands in: the high half's field
 * exactly when the moved half's slot offset is the high half's offset, the low
 * half's field otherwise. The input is evaluated once and no NZCV is written.
 */
#define KPROG_ARM64_VREG_FIELD(IS_HIGH_FIELD)                  \\
	((__u8)(((IS_HIGH_FIELD)) ? {high} : {low}))
_Static_assert(KPROG_ARM64_VREG_FIELD_COUNT == {count}U,
	       "arm64 vreg field count drift");
_Static_assert({low} != {high},
	       "arm64 vreg field codes must be distinct");
_Static_assert({low} == 0U && {high} == 1U,
	       "arm64 vreg field code drift");
/* The selector's fact is the moved half's slot offset being the high half's
 * offset, so the two vector half offsets must name the two state fields. */
_Static_assert(KPROG_ARM64_VREG_FIELD(KPROG_ARM64_VREG_HIGH_OFFSET ==
	       KPROG_ARM64_VREG_HIGH_OFFSET) == {high},
	       "arm64 vreg field high half selection drift");
_Static_assert(KPROG_ARM64_VREG_FIELD(KPROG_ARM64_VREG_LOW_OFFSET ==
	       KPROG_ARM64_VREG_HIGH_OFFSET) == {low},
	       "arm64 vreg field low half selection drift");
/* The selector must name each state field at its own fact. */
_Static_assert(KPROG_ARM64_VREG_FIELD(1) == {high},
	       "arm64 vreg field high selection drift");
_Static_assert(KPROG_ARM64_VREG_FIELD(0) == {low},
	       "arm64 vreg field low selection drift");
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
                    f"generated arm64 vreg field contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
