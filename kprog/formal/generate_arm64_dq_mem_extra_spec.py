#!/usr/bin/env python3
"""Generate the AArch64 vector lane extra-offset contract.

The hand-written vector memory step of `kprog/arm64/arm64_sim_local_bpf.h`,
`ARM64_SIM_L_DQ_MEM_STEP`, moves the SIMD register's halves to or from memory
one lane at a time. The memory byte offset of each moved lane is a *finite
selection over the closed pair of facts* (the lane is the first plan position,
and a high lane is present at all):

  * the **first-lane** offset, zero, for the low lane of every transfer: the
    first plan position always reads or writes at the base offset;
  * the **high-lane** offset, one 64-bit lane stride above the low lane, for the
    `.Q0` transfer's second position;
  * the **single-lane** offset, zero, when the plan has only one position, so
    the second fact is never consulted.

The generated table `GeneratedArm64DqMemExtra.extraOffsetOf` and the plain-
expression C macro `KPROG_ARM64_DQ_MEM_EXTRA` expose that offset choice. The
step previously computed the per-position extra offset by hand through a nested
ternary on `__a64_vreg_p == 0U` and `__a64_dq_lanes > 1U`, and this module makes
that 3-way selection a machine-checked fact. `KProgFormal/Arm64DqMemExtraShape.lean`
proves the generated `extraOffsetOf` equal to an independent 3-way statement
over the closed pair, and ties the high-lane offset to the 0141 DQ lane stride
(`GeneratedArm64DqMem.laneCount` / `transfer`) and the 0143 half plan
(`GeneratedArm64Vreg.plan` / `halfOffset`).

The generator is independent of the body it describes: it holds its own literal
outcome/case enumeration and re-derives the live step text from the simulator
header, then requires the step to go through the generated selector and to keep
the hand nested ternary out.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_dq_mem_extra_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64DqMemExtra.lean"
CHEADER = ROOT / "generated/arm64_dq_mem_extra.h"

# The independent enumeration of the three lane extra offsets, in code order:
# (outcome, outcome define, code, offset bytes, plan effect).
_OUTCOMES = [
    ("firstLane",
     "KPROG_ARM64_DQ_MEM_EXTRA_FIRST_LANE_BYTES",
     0, 0, "plan_first_lane_offset"),
    ("highLane",
     "KPROG_ARM64_DQ_MEM_EXTRA_HIGH_LANE_BYTES",
     1, 8, "plan_high_lane_offset"),
    ("singleLane",
     "KPROG_ARM64_DQ_MEM_EXTRA_SINGLE_LANE_BYTES",
     2, 0, "plan_single_lane_offset"),
]
# The independent enumeration of the four (is first lane, high present) cases a
# moved lane can have, in classification order:
# (case, is first lane, high present, outcome).
_CASES = [
    ("first_lane_high", True, True, "firstLane"),
    ("first_lane_no_high", True, False, "firstLane"),
    ("high_lane", False, True, "highLane"),
    ("single_lane", False, False, "singleLane"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64DqMemExtraOffset",
    "selector": "first_lane_then_zero_else_high_lane_present_then_high_lane_stride_else_zero",
    "outcomes": [{"outcome": o, "outcome_define": d, "outcome_code": c,
                  "offset_bytes": b, "effect": e}
                 for o, d, c, b, e in _OUTCOMES],
    "cases": [{"name": n, "is_first_lane": f, "high_present": h,
               "outcome": o}
              for n, f, h, o in _CASES],
}
OUTCOME_COLUMNS = ("outcome", "outcome_define", "outcome_code", "offset_bytes",
                   "effect")
CASE_COLUMNS = ("name", "is_first_lane", "high_present", "outcome")

# The live routed vector memory step text, between the step's own `#define` and
# the plain `.D0` load wrapper that follows it.
EXTRA_REGION_START = "#define ARM64_SIM_L_DQ_MEM_STEP("
EXTRA_REGION_END = "#define ARM64_SIM_L_LOAD_D0_MEM("
EXTRA_SELECTOR = "KPROG_ARM64_DQ_MEM_EXTRA("
# The hand-written nested ternary the routed step must no longer contain: the
# first-position test deciding the extra offset by hand. The step legitimately
# keeps the two fact tests inside the selector's arguments (the lane position
# and the lane count), so the ternary's `?`-terminated first-position test is
# the safe needle.
HAND_GATE = "= __a64_vreg_p == 0U ?"


def _outcome(is_first_lane: bool, high_present: bool) -> str:
    """The independent 3-way selection over the closed fact pair."""
    if is_first_lane:
        return "firstLane"
    if high_present:
        return "highLane"
    return "singleLane"


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
    """The routed vector memory step must select its per-lane extra offset
    through the generated 3-way selector and must not pick the offset by hand
    through the first-position ternary."""
    if EXTRA_SELECTOR not in region:
        raise SystemExit(
            "arm64 vector memory step does not route its per-lane extra "
            "offset through the generated selector")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 vector memory step picks its per-lane extra offset by hand "
            "through the first-position ternary instead of through the "
            "generated selector")


def check_against_header():
    """The live vector memory step must select its per-lane extra offset
    through the generated selector."""
    check_region(region_between(EXTRA_REGION_START, EXTRA_REGION_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 dq mem extra keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 dq mem extra specification: {data!r}")
    for index, column in enumerate(OUTCOME_COLUMNS):
        want = [row[column] for row in EXPECTED["outcomes"]]
        got = [entry[index] for entry in _OUTCOMES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 dq mem extra outcome {column}: "
                f"{EXPECTED['outcomes']!r}")
    if len(EXPECTED["outcomes"]) != 3:
        raise SystemExit(
            "arm64 dq mem extra must select between exactly 3 outcomes")
    if [row["outcome_code"] for row in EXPECTED["outcomes"]] != [0, 1, 2]:
        raise SystemExit(
            f"invalid arm64 dq mem extra codes: {EXPECTED['outcomes']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 dq mem extra case {column}: "
                f"{EXPECTED['cases']!r}")
    for row in EXPECTED["cases"]:
        if _outcome(row["is_first_lane"], row["high_present"]) != row["outcome"]:
            raise SystemExit(
                f"invalid arm64 dq mem extra table: {EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    outcomes = spec["outcomes"]
    cases = spec["cases"]
    names = ", ".join(f'"{row["outcome"]}"' for row in outcomes)
    codes = ", ".join(str(row["outcome_code"]) for row in outcomes)
    ctor = ", ".join(f'.{row["outcome"]}' for row in outcomes)
    code_of = "\n".join(
        f'  | .{row["outcome"]} => {row["outcome_code"]}' for row in outcomes)
    effect_of = "\n".join(
        f'  | .{row["outcome"]} => "{row["effect"]}"' for row in outcomes)
    outcome_ctors = "\n".join(f'  | {row["outcome"]}' for row in outcomes)
    case_ctors = "\n".join(f'  | {row["name"]}' for row in cases)
    outcome_of_case = "\n".join(
        f'  | .{row["name"]} => .{row["outcome"]}' for row in cases)
    return f'''-- Generated by generate_arm64_dq_mem_extra_spec.py from arm64_dq_mem_extra_spec.json.
import Std
namespace KProgFormal.GeneratedArm64DqMemExtra
/-- The three per-lane extra byte offsets a vector memory step selects between:
the first plan position's zero offset, the high lane's one-lane-stride offset,
and the single-position zero offset. -/
inductive Outcome where
{outcome_ctors}
deriving DecidableEq, Repr
/-- The number of per-lane extra offsets the step selects between. -/
def outcomeCount : Nat := {len(outcomes)}
/-- The three per-lane extra offsets, in code order. -/
def outcomeNames : List String := [{names}]
/-- The outcome code of each offset, in code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def outcomeCodes : List Nat := [{codes}]
/-- The outcome code of an offset. -/
def codeOfOutcome : Outcome -> Nat
{code_of}
/-- The plan effect each offset performs. -/
def effectOfOutcome : Outcome -> String
{effect_of}
/-- The per-lane extra offset a vector memory step selects: the first-lane
offset exactly when the lane is the first plan position, the high-lane offset at
every later position of a transfer that has a high lane, and the single-lane
offset when the transfer has only one position. The two facts are a closed
pair, so the selection is total. -/
def extraOffsetOf (isFirstLane hasHighLane : Bool) : Outcome :=
  if isFirstLane then .firstLane
  else if hasHighLane then .highLane
  else .singleLane
/-- The offset an outcome code names, or `none` when the code names no
offset. -/
def outcomeOfCode (code : Nat) : Option Outcome :=
  (outcomeCodes.zip [{ctor}]).lookup code
/-- The four (is first lane, high lane present) cases a moved lane can
have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a moved lane by whether it is the first plan position and whether
the transfer has a high lane at all. -/
def classify (isFirstLane hasHighLane : Bool) : Case :=
  match isFirstLane, hasHighLane with
    | true, true => .first_lane_high
    | true, false => .first_lane_no_high
    | false, true => .high_lane
    | false, false => .single_lane
/-- The per-lane extra offset a case performs, from the case table. -/
def outcomeOfCase : Case -> Outcome
{outcome_of_case}
/-- The independent high-lane fact: the high-lane offset applies exactly when
the lane is not the first plan position and a high lane is present, the closed
pair's ordered conjunction. -/
def highLaneFact (isFirstLane hasHighLane : Bool) : Bool :=
  hasHighLane && !isFirstLane
/-- The high-lane fact is the direct conjunction for every moved lane. -/
theorem highLaneFact_refines (isFirstLane hasHighLane : Bool) :
    highLaneFact isFirstLane hasHighLane = (hasHighLane && !isFirstLane) := by
  cases isFirstLane <;> cases hasHighLane <;> rfl
/-- The offset selector equals the case table for every moved lane: naming the
offset from the two facts directly is the same as classifying and dispatching
on the case. -/
theorem extraOffsetOf_refines (isFirstLane hasHighLane : Bool) :
    extraOffsetOf isFirstLane hasHighLane =
      outcomeOfCase (classify isFirstLane hasHighLane) := by
  cases isFirstLane <;> cases hasHighLane <;> rfl
end KProgFormal.GeneratedArm64DqMemExtra
'''


def render_c(spec: dict) -> str:
    outcomes = spec["outcomes"]
    count = len(outcomes)
    first = outcomes[0]["outcome_define"]
    high = outcomes[1]["outcome_define"]
    single = outcomes[2]["outcome_define"]
    first_off = first + "_OFFSET"
    high_off = high + "_OFFSET"
    single_off = single + "_OFFSET"
    outcome_defines = "\n".join(
        f'#define {row["outcome_define"]} {row["outcome_code"]}U'
        for row in outcomes)
    offset_defines = "\n".join(
        f'#define {row["outcome_define"]}_OFFSET {row["offset_bytes"]}U'
        for row in outcomes)
    return f'''/* Generated by generate_arm64_dq_mem_extra_spec.py from arm64_dq_mem_extra_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_DQ_MEM_EXTRA_H
#define KPROG_FORMAL_GENERATED_ARM64_DQ_MEM_EXTRA_H
/*
 * AArch64 vector lane extra-offset contract: the vector memory step
 * `ARM64_SIM_L_DQ_MEM_STEP` moves the SIMD register's halves to or from memory
 * one lane at a time, and each moved lane's byte offset is selected from a
 * closed pair of facts: whether the lane is the first plan position and whether
 * the transfer has a high lane at all. The first-lane offset is zero, the
 * high-lane offset is one 64-bit lane stride above the low lane for the second
 * position of a `.Q0` transfer, and the single-lane offset is zero for the
 * second fact of a one-position transfer. `KProgFormal/Arm64DqMemExtraShape.lean`
 * proves the generated `extraOffsetOf` equal to an independent 3-way statement
 * and ties the high-lane offset to the DQ lane stride
 * (`KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE` / `GeneratedArm64DqMem.transfer`) and
 * the half plan (`GeneratedArm64Vreg.plan` / `halfOffset`). The two facts are a
 * closed pair, so the 3-way selection is total. This header uses only literal
 * inputs, so it is included after the `ARM64_DQ_MEM` lane stride defines and
 * before the `ARM64_WIDTH_*` decodes and the `ARM64_SIM_TAG_*` tag names in the
 * simulator header.
 */
/* The number of per-lane extra offsets the step selects between. */
#define KPROG_ARM64_DQ_MEM_EXTRA_COUNT {count}U
/* The per-lane extra offset of each outcome. */
{outcome_defines}
/* The byte offset of each outcome. */
{offset_defines}
/*
 * The per-lane extra offset a vector memory step selects: the first-lane offset
 * exactly when the lane is the first plan position, the high-lane offset at
 * every later position of a transfer that has a high lane, and the single-lane
 * offset when the transfer has only one position. Both inputs are evaluated
 * once and no NZCV is written.
 */
#define KPROG_ARM64_DQ_MEM_EXTRA(IS_FIRST_LANE, HAS_HIGH_LANE)             \\
	((__s64)(((IS_FIRST_LANE))                       \\
		 ? {first_off}                    \\
		 : (((HAS_HIGH_LANE))                    \\
		 ? {high_off}                     \\
		 : {single_off})))
_Static_assert(KPROG_ARM64_DQ_MEM_EXTRA_COUNT == {count}U,
	       "arm64 dq mem extra count drift");
_Static_assert({first} != {high},
	       "arm64 dq mem extra codes must be distinct");
_Static_assert({first} != {single},
	       "arm64 dq mem extra codes must be distinct");
_Static_assert({high} != {single},
	       "arm64 dq mem extra codes must be distinct");
_Static_assert({first} == 0U && {high} == 1U && {single} == 2U,
	       "arm64 dq mem extra code drift");
/* The offset of the high lane is the DQ lane stride; the first and
 * single-position offsets are the base offset. */
_Static_assert({high_off} == KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE,
	       "arm64 dq mem extra high lane offset drift");
_Static_assert({first_off} == 0U && {single_off} == 0U,
	       "arm64 dq mem extra base offset drift");
/* The selector must name each offset at its own fact pair. */
_Static_assert(KPROG_ARM64_DQ_MEM_EXTRA(1, 1) == {first_off},
	       "arm64 dq mem extra first lane selection drift");
_Static_assert(KPROG_ARM64_DQ_MEM_EXTRA(1, 0) == {first_off},
	       "arm64 dq mem extra first lane single selection drift");
_Static_assert(KPROG_ARM64_DQ_MEM_EXTRA(0, 1) == {high_off},
	       "arm64 dq mem extra high lane selection drift");
_Static_assert(KPROG_ARM64_DQ_MEM_EXTRA(0, 0) == {single_off},
	       "arm64 dq mem extra single lane selection drift");
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
                    f"generated arm64 dq mem extra contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
