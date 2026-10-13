#!/usr/bin/env python3
"""Generate the AArch64 write-register width body-selection contract.

The hand-written AArch64 writeback body of `kprog/arm64/arm64_sim_local_bpf.h`
-- `ARM64_SIM_L_WRITE_REG_WIDTH`, which every GPR write in the simulator routes
through -- first masks the value to the access width
(`KPROG_ARM64_APPLY_WIDTH`, owned by the `arm64_width.h` contract) and then
picks the writeback body by hand from a *single closed fact*: whether the
access width code is the 32-bit code:

    if ((WIDTH) == ARM64_WIDTH_32) {
            switch (REG) {
            ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG32_CASE)
            default: break;
            }
    } else {
            switch (REG) {
            ARM64_SIM_L_FOR_EACH_GPR(ARM64_SIM_L_WRITE_REG64_CASE)
            default: break;
            }
    }

The body is selected from that single closed fact -- whether the access width
code is 4, the 32-bit code:

  * the **narrow** body (`ARM64_SIM_L_WRITE_REG32_CASE`, storing
    `(__u32)__a64_l_next`): the access width code is the 32-bit code, so the
    writeback truncates the already-masked value to 32 bits;
  * the **full** body (`ARM64_SIM_L_WRITE_REG64_CASE`, storing
    `__a64_l_next`): every other width code -- the 8/16-bit codes as well as
    the 64-bit code and any code above it -- so the already-masked value is
    written back whole.

Because the value is masked to the width *before* the body choice, the two
bodies are observationally equal for every width the simulator reaches: at the
32-bit code the masked value's upper 32 bits are already zero, so truncating it
changes nothing; at the 8/16/64-bit codes the full body writes the already-8/16/
64-bit-masked value, equal to the truncating body. The selection is therefore a
genuine no-op on state, and only a wrong *selector code* (comparing against a
code other than 4) or a *swapped body assignment* (the 32-bit code reaching the
full body) is observable. The generated table and the plain-expression C macro
`KPROG_ARM64_WRITE_ARM` expose the selection so that wrong choice is a
machine-checked fact rather than a silent hand `if`.

`KProgFormal/Arm64WriteArmShape.lean` proves the generated `armOf` equal to an
independent 2-way statement over the single fact, tied to the `Arm64Width`
32-bit code (`arm64WidthCodeSpec .w32`) that the pre-truncation step masks with.
The fact is closed, so the 2-way selection is total. The `ARM64_SP` branch and
the `KPROG_ARM64_REG_WRITABLE` guard stay outside the selector: they are the
destination-identity contract, not the width body choice.

The generator is independent of the bodies it describes: it holds its own
literal arm/case enumeration and re-derives the live writeback body region from
the simulator header, then requires the body to go through the generated
selector and to keep the hand width test out.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_write_arm_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64WriteArm.lean"
CHEADER = ROOT / "generated/arm64_write_arm.h"

# The independent enumeration of the two writeback bodies, in arm-code order:
# (arm, arm define, body effect).
_ARMS = [
    ("full",
     "KPROG_ARM64_WRITE_ARM_FULL",
     "full_width_writeback"),
    ("narrow",
     "KPROG_ARM64_WRITE_ARM_NARROW",
     "narrow_width_writeback"),
]
# The independent enumeration of the two (is 32-bit width code) cases a
# writeback can have, in classification order: (case, is w32, full body).
_CASES = [
    ("w32", True, False),
    ("other", False, True),
]
W32 = 4
W32_DEFINE = "ARM64_WIDTH_32"
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64WriteArm",
    "selector": "w32_then_narrow_else_full",
    "w32_define": W32_DEFINE,
    "w32_code": W32,
    "arms": [{"arm": arm, "arm_define": define, "body": body}
             for arm, define, body in _ARMS],
    "cases": [{"name": name, "is_w32": w32, "full": full}
              for name, w32, full in _CASES],
}
ARM_COLUMNS = ("arm", "arm_define", "body")
CASE_COLUMNS = ("name", "is_w32", "full")

# The live routed writeback body text, between the body's own `#define` and the
# pointer-writeback helper that follows it. The width body choice is the one
# place the writeback selects its truncation.
WRITE_ARM_START = "#define ARM64_SIM_L_WRITE_REG_WIDTH("
WRITE_ARM_END = "#define ARM64_SIM_L_WRITE_REG_PTR("
WRITE_ARM_SELECTOR = "KPROG_ARM64_WRITE_ARM("
# The two writeback bodies the routed helper must keep, so the selection routes
# between the real truncating and full cases rather than replacing them.
FULL_CASE = "ARM64_SIM_L_WRITE_REG64_CASE)"
NARROW_CASE = "ARM64_SIM_L_WRITE_REG32_CASE)"
# The hand-written width test the routed body must no longer contain: the width
# code deciding the writeback body by hand. The body legitimately keeps the
# width code as the selector's argument, so the `if (`-led test is the safe
# needle.
HAND_GATE = "if ((WIDTH) == ARM64_WIDTH_32)"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(
            f"sim header no longer bounds the writeback body region with "
            f"{start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def write_arm_region():
    return region_between(WRITE_ARM_START, WRITE_ARM_END)


def check_region(region):
    """The writeback body must select its case through the generated 2-way
    selector, must keep both writeback bodies, and must not pick the body by
    hand through the width test."""
    if WRITE_ARM_SELECTOR not in region:
        raise SystemExit(
            "arm64 writeback body does not route through the generated write "
            "arm selector")
    if FULL_CASE not in region:
        raise SystemExit(
            "arm64 writeback body does not keep the full-width body")
    if NARROW_CASE not in region:
        raise SystemExit(
            "arm64 writeback body does not keep the narrow-width body")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 writeback body picks its case by hand through the width "
            "test instead of through the generated write arm selector")


def check_against_header():
    """The live writeback body must route its case choice through the generated
    selector."""
    check_region(write_arm_region())


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid arm64 write arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 write arm specification: {data!r}")
    for index, column in enumerate(ARM_COLUMNS):
        want = [row[column] for row in EXPECTED["arms"]]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid arm64 write arm arm {column}: "
                             f"{EXPECTED['arms']!r}")
    if len(EXPECTED["arms"]) != 2:
        raise SystemExit("arm64 write arm must select between exactly 2 bodies")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(f"invalid arm64 write arm case {column}: "
                             f"{EXPECTED['cases']!r}")
    if [row["full"] for row in EXPECTED["cases"]] != [False, True]:
        raise SystemExit(f"invalid arm64 write arm table: {EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    cases = spec["cases"]
    w32 = spec["w32_code"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(code) for code, _row in zip((0, 1), arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {code}' for code, row in zip((0, 1), arms))
    body_of = "\n".join(
        f'  | .{row["arm"]} => "{row["body"]}"' for row in arms)
    case_ctors = "\n".join(f"  | {row['name']}" for row in cases)
    case_table = "\n".join(
        f"  | .{row['name']} => {'true' if row['full'] else 'false'}"
        for row in cases)
    classify = []
    for w32v in (True, False):
        row = next(r for r in cases if r["is_w32"] == w32v)
        classify.append(
            f"    | {'true' if w32v else 'false'} => .{row['name']}")
    classify = "\n".join(classify)
    arm_of_case = "\n".join(
        f"  | .{row['name']} => .{'full' if row['full'] else 'narrow'}"
        for row in cases)
    return f'''-- Generated by generate_arm64_write_arm_spec.py from arm64_write_arm_spec.json.
import Std
namespace KProgFormal.GeneratedArm64WriteArm
/-- The two writeback bodies the write-register helper selects between: the full
value writeback and the 32-bit truncating writeback. -/
inductive Arm where
  | {arms[0]["arm"]}
  | {arms[1]["arm"]}
deriving DecidableEq, Repr
/-- The number of writeback bodies the helper selects between. -/
def armCount : Nat := {len(arms)}
/-- The 32-bit width code the narrow body is selected at. -/
def w32Code : Nat := {w32}
/-- The two writeback bodies, in arm-code order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in arm-code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The writeback effect each arm performs. -/
def bodyOfArm : Arm -> String
{body_of}
/-- The writeback body an access width selects: the full-value body exactly when
the width code is *not* the 32-bit code (the full-width body also serves the
8/16-bit codes, whose values are already masked narrower than 32 bits, and the
64-bit code), the 32-bit truncating body otherwise. The fact is closed, so the
selection is total. -/
def armOf (isW32 : Bool) : Arm :=
  if isW32 then .{arms[1]["arm"]} else .{arms[0]["arm"]}
/-- The writeback body an arm code names, or `none` when the code names no
body. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
/-- The two (is 32-bit width code) cases a writeback can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a writeback by whether its width code is the 32-bit code. -/
def classify (isW32 : Bool) : Case :=
  match isW32 with
{classify}
/-- Whether a case is served by the full-value body. -/
def fullBody : Case -> Bool
{case_table}
/-- Independent statement of the selection: a writeback uses the full-value body
exactly when its width code is not the 32-bit code. -/
def fullSpec (isW32 : Bool) : Bool := !isW32
/-- The two-case table agrees with the independent negation for every
writeback: classifying then testing the table equals the direct negation. -/
theorem full_refines (isW32 : Bool) :
    fullBody (classify isW32) = fullSpec isW32 := by
  cases isW32 <;> rfl
/-- The writeback body a case selects, from the case table. -/
def armOfCase : Case -> Arm
{arm_of_case}
/-- The writeback body selector equals the case table for every writeback:
naming the body from the width fact directly is the same as classifying and
dispatching on the case. -/
theorem armOf_refines (isW32 : Bool) :
    armOf isW32 = armOfCase (classify isW32) := by
  cases isW32 <;> rfl
end KProgFormal.GeneratedArm64WriteArm
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    w32 = spec["w32_code"]
    full = arms[0]["arm_define"]
    narrow = arms[1]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {code}U'
        for code, row in zip((0, 1), arms))
    return f'''/* Generated by generate_arm64_write_arm_spec.py from arm64_write_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_WRITE_ARM_H
#define KPROG_FORMAL_GENERATED_ARM64_WRITE_ARM_H
/*
 * AArch64 write-register width body-selection contract: the writeback body
 * `ARM64_SIM_L_WRITE_REG_WIDTH` first masks its value to the access width
 * (`KPROG_ARM64_APPLY_WIDTH`, owned by `generated/arm64_width.h`) and then
 * selects the writeback body from a single closed fact: whether the access
 * width code is the 32-bit code {w32}. The narrow body
 * `ARM64_SIM_L_WRITE_REG32_CASE` stores `(__u32)__a64_l_next`; the full body
 * `ARM64_SIM_L_WRITE_REG64_CASE` stores `__a64_l_next`. Because the value is
 * masked to the width before the choice, the two bodies are observationally
 * equal for every width the simulator reaches, so only a wrong selector code
 * or a swapped body assignment is observable.
 * `KProgFormal/Arm64WriteArmShape.lean` proves the generated `armOf` equal to
 * an independent 2-way statement, tied to the `Arm64Width` 32-bit code
 * (`arm64WidthCodeSpec .w32`) the pre-truncation step masks with. The `SP`
 * branch and the destination-presence guard stay outside the selector: they
 * are the destination-identity contract, not the width body choice.
 * This header binds the hand-written 32-bit code to the generated table, so it
 * is included after the `ARM64_WIDTH_*` decodes.
 */
/* The 32-bit width code the narrow body is selected at. */
#define KPROG_ARM64_WRITE_ARM_W32 {w32}U
/* The number of writeback bodies the helper selects between. */
#define KPROG_ARM64_WRITE_ARM_COUNT {count}U
{arm_defines}
/*
 * The writeback body an access width selects: the full-value body exactly when
 * the width code is not the 32-bit code, the 32-bit truncating body otherwise.
 * The input is evaluated once and no NZCV is written.
 */
#define KPROG_ARM64_WRITE_ARM(IS_W32)                                        \\
\t((__u8)(((IS_W32)) ? {narrow} : {full}))
_Static_assert(KPROG_ARM64_WRITE_ARM_W32 == {w32}U,
\t       "arm64 write arm 32-bit width code drift");
_Static_assert(ARM64_WIDTH_32 == KPROG_ARM64_WRITE_ARM_W32,
\t       "arm64 write arm 32-bit width code drift");
_Static_assert(KPROG_ARM64_WRITE_ARM_COUNT == {count}U,
\t       "arm64 write arm count drift");
_Static_assert({full} != {narrow},
\t       "arm64 write arm codes must be distinct");
_Static_assert(KPROG_ARM64_WRITE_ARM_FULL == 0U &&
\t       KPROG_ARM64_WRITE_ARM_NARROW == 1U,
\t       "arm64 write arm code drift");
/* The selector must name each body at its own width fact. */
_Static_assert(KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_32 == ARM64_WIDTH_32) == {narrow},
\t       "arm64 write arm narrow selection drift");
_Static_assert(KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_8 == ARM64_WIDTH_32) == {full},
\t       "arm64 write arm 8-bit selection drift");
_Static_assert(KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_16 == ARM64_WIDTH_32) == {full},
\t       "arm64 write arm 16-bit selection drift");
_Static_assert(KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_64 == ARM64_WIDTH_32) == {full},
\t       "arm64 write arm 64-bit selection drift");
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
                    f"generated arm64 write arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
