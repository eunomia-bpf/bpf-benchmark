#!/usr/bin/env python3
"""Generate the shared AArch64 stack word-path/byte-ladder body-selection contract.

The hand-written stack helpers of `kprog/arm64/arm64_sim_local_bpf.h` reach the
stack arena (the `__a64_stack` union of overlapping byte and word views) through
two alternative *bodies*:

  * the **word** body, which touches the word arena `q[]` directly, and is only
    valid when the resolved access width is the full 64-bit code *and* the
    resolved stack index is qword-aligned (`KPROG_ARM64_STACK_WORD_ALIGNED`), so
    a single `q[INDEX >> 3]` covers exactly the byte window `[index, index + 8)`;
  * the **byte** body, the little-endian byte ladder over `b[]`
    (`KPROG_ARM64_LOAD_BYTES`), which covers every other width and every
    unaligned index.

`ARM64_SIM_L_STACK_READ` selects between those two bodies from the *same* closed
pair of facts (width is 64, index is 8-aligned) that decides the stack slot tag,
so a single predicate names the body for a 64-bit test and an alignment test.
The generated table `GeneratedArm64StackArm.armOf` and the plain-expression C
macro `KPROG_ARM64_STACK_ARM` expose that body choice; the crate's existing
`KPROG_ARM64_STACK_TAG` predicate names the tag decision over the same facts.

The generator is independent of the bodies it describes: it holds its own
literal case enumeration and re-derives the live stack-read helper text from the
simulator header, then requires the helper to go through the generated selector
and to keep the word-arena and byte-ladder bodies.

`KProgFormal/Arm64StackArmShape.lean` proves the generated table equals an
independent construction from the literals, and ties the two facts to the
`Arm64Width` 64-bit code and the `Arm64StackArena` alignment guard.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_stack_arm_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64StackArm.lean"
CHEADER = ROOT / "generated/arm64_stack_arm.h"

# The independent enumeration of the two bodies a stack access selects between,
# in selection order: (arm, arm define, body).
_ARMS = [
    ("word", "KPROG_ARM64_STACK_ARM_WORD", "word_arena_access"),
    ("byte", "KPROG_ARM64_STACK_ARM_BYTE", "byte_ladder_access"),
]
# The independent enumeration of the four (width, alignment) cases a stack
# access can have, in classification order: (case, is 64-bit, aligned, word).
_CASES = [
    ("qword", True, True, True),
    ("sub_qword_aligned", False, True, False),
    ("qword_unaligned", True, False, False),
    ("sub_qword_unaligned", False, False, False),
]
WIDTH64 = 8
WIDTH64_DEFINE = "ARM64_WIDTH_64"
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64StackArm",
    "selector": "w64_and_aligned_then_word_else_byte",
    "width64_define": WIDTH64_DEFINE,
    "width64_code": WIDTH64,
    "arms": [{"arm": arm, "arm_define": define, "body": body}
             for arm, define, body in _ARMS],
    "cases": [{"name": name, "w64": w64, "aligned": aligned, "word": word}
              for name, w64, aligned, word in _CASES],
}
ARM_COLUMNS = ("arm", "arm_define", "body")
CASE_COLUMNS = ("name", "w64", "aligned", "word")

# The live routed stack-read helper text, between the read helper's `#define`
# opcode title and the read-tag helper's. (The write path already routes its
# slot-tag gate through `KPROG_ARM64_STACK_TAG`, so the open body-selection
# surface is the read helper.)
STACK_READ_START = "#define ARM64_SIM_L_STACK_READ(OFF, WIDTH)"
STACK_READ_END = "#define ARM64_SIM_L_STACK_READ_TAG(OFF, WIDTH)"
STACK_SELECTOR = "KPROG_ARM64_STACK_ARM("
WORD_ARENA = "__a64_stack.q"
WORD_INDEX = "KPROG_ARM64_STACK_WORD_INDEX("
BYTE_ARENA = "__a64_stack.b["
READ_LADDER = "KPROG_ARM64_LOAD_BYTES("
# The hand-written selection the routed helper must no longer contain: the width
# test conjoined with the alignment test. The byte-ladder body uses no `&&`, so
# its presence means the body choice is still made by hand.
HAND_AND_TEST = "ARM64_WIDTH_64 &&"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def stack_read_region():
    return region_between(STACK_READ_START, STACK_READ_END)


def check_region(region, ladder):
    """A routed stack helper must select its body through the generated
    two-fact selector and still keep the word-arena and byte-ladder bodies; it
    must not select by hand."""
    if STACK_SELECTOR not in region:
        raise SystemExit(
            "arm64 stack helper does not route through the generated selector")
    if WORD_ARENA not in region or WORD_INDEX not in region:
        raise SystemExit(
            "arm64 stack helper does not touch the word arena slot")
    if BYTE_ARENA not in region:
        raise SystemExit("arm64 stack helper does not touch the byte arena")
    if ladder not in region:
        raise SystemExit(
            "arm64 stack helper does not keep the byte-ladder body")
    if HAND_AND_TEST in region:
        raise SystemExit(
            "arm64 stack helper selects its body by hand instead of through "
            "the generated selector")


def check_against_header():
    """The live stack-read helper must route its body choice through the
    generated selector."""
    check_region(stack_read_region(), READ_LADDER)


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid arm64 stack arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 stack arm specification: {data!r}")
    for index, column in enumerate(ARM_COLUMNS):
        want = [row[column] for row in EXPECTED["arms"]]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid arm64 stack arm arm {column}: "
                             f"{EXPECTED['arms']!r}")
    if len(EXPECTED["arms"]) != 2:
        raise SystemExit("arm64 stack arm must select between exactly 2 bodies")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(f"invalid arm64 stack arm case {column}: "
                             f"{EXPECTED['cases']!r}")
    if [row["word"] for row in EXPECTED["cases"]] != [
            True, False, False, False]:
        raise SystemExit(f"invalid arm64 stack arm table: {EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    cases = spec["cases"]
    width64 = spec["width64_code"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(code) for code, _row
                      in zip((1, 0), arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {code}' for code, row in zip((1, 0), arms))
    body_of = "\n".join(
        f'  | .{row["arm"]} => "{row["body"]}"' for row in arms)
    case_ctors = "\n".join(f"  | {row['name']}" for row in cases)
    case_table = "\n".join(
        f"  | .{row['name']} => {'true' if row['word'] else 'false'}"
        for row in cases)
    classify = []
    for w64 in (True, False):
        for aligned in (True, False):
            row = next(r for r in cases
                       if r["w64"] == w64 and r["aligned"] == aligned)
            classify.append(f"    | {'true' if w64 else 'false'}, "
                            f"{'true' if aligned else 'false'} => .{row['name']}")
    classify = "\n".join(classify)
    arm_of_case = "\n".join(
        f"  | .{row['name']} => .{'word' if row['word'] else 'byte'}"
        for row in cases)
    return f'''-- Generated by generate_arm64_stack_arm_spec.py from arm64_stack_arm_spec.json.
import Std
namespace KProgFormal.GeneratedArm64StackArm
/-- The two bodies a stack access selects between: the direct word-arena access
and the little-endian byte ladder. -/
inductive Arm where
  | {arms[0]["arm"]}
  | {arms[1]["arm"]}
deriving DecidableEq, Repr
/-- The number of bodies a stack access selects between. -/
def armCount : Nat := {len(arms)}
/-- The full 64-bit width code the word body is selected at. -/
def width64Code : Nat := {width64}
/-- The two bodies a stack access selects between, in arm-code order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in arm-code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The storage body each arm performs on the stack arena. -/
def bodyOfArm : Arm -> String
{body_of}
/-- The body a 64-bit test and an alignment test select: the word-arena body
exactly when the access is 64-bit and the resolved index is qword-aligned, the
byte-ladder body otherwise. The two facts are a closed pair, so the selection is
total. -/
def armOf (isW64 isAligned : Bool) : Arm :=
  if isW64 && isAligned then .{arms[0]["arm"]} else .{arms[1]["arm"]}
/-- The body an arm code names, or `none` when the code names no body. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
/-- The four (width, alignment) cases a stack access can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify an access by whether it is 64-bit and whether its index is
qword-aligned. -/
def classify (isW64 isAligned : Bool) : Case :=
  match isW64, isAligned with
{classify}
/-- Whether a case is served by the word-arena body. -/
def wordBody : Case -> Bool
{case_table}
/-- Independent statement of the selection: an access uses the word-arena body
exactly when it is 64-bit and qword-aligned. -/
def wordSpec (isW64 isAligned : Bool) : Bool := isW64 && isAligned
/-- The four-case table agrees with the independent `&&` statement for every
access: classifying then testing the table equals the direct conjunction. -/
theorem word_refines (isW64 isAligned : Bool) :
    wordBody (classify isW64 isAligned) = wordSpec isW64 isAligned := by
  cases isW64 <;> cases isAligned <;> rfl
/-- The body a case selects, from the case table. -/
def armOfCase : Case -> Arm
{arm_of_case}
/-- The body selector equals the case table for every access: naming the body
from the two facts directly is the same as classifying and dispatching on the
case. -/
theorem armOf_refines (isW64 isAligned : Bool) :
    armOf isW64 isAligned = armOfCase (classify isW64 isAligned) := by
  cases isW64 <;> cases isAligned <;> rfl
end KProgFormal.GeneratedArm64StackArm
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    width = spec["width64_code"]
    word = arms[0]["arm_define"]
    byte = arms[1]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {code}U'
        for code, row in zip((1, 0), arms))
    return f'''/* Generated by generate_arm64_stack_arm_spec.py from arm64_stack_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_STACK_ARM_H
#define KPROG_FORMAL_GENERATED_ARM64_STACK_ARM_H
/*
 * AArch64 stack word-path/byte-ladder body-selection contract: the stack
 * helper `ARM64_SIM_L_STACK_READ` selects between two bodies from a closed pair
 * of facts: whether the resolved access width is the full {width} (64-bit)
 * code, and whether the resolved stack index is qword-aligned. Only when both
 * hold does the helper touch the word arena `q[INDEX >> 3]`, covering exactly
 * the byte window; every other width and every unaligned index goes through the
 * little-endian byte ladder over `b[]`. `KProgFormal/Arm64StackArmShape.lean`
 * proves the generated `armOf` equal to an independent construction from the
 * width and alignment facts, tied to the `Arm64Width` 64-bit code and the
 * `Arm64StackArena` alignment guard.
 * This header is included after the `ARM64_WIDTH_*` decodes and the
 * `arm64_stack_arena.h` guard, so the drift checks bind the hand-written 64-bit
 * code to the generated table.
 */
/* The full 64-bit width code the word body is selected at. */
#define KPROG_ARM64_STACK_ARM_WIDTH64 {width}U
/* The number of bodies the helper selects between. */
#define KPROG_ARM64_STACK_ARM_COUNT {count}U
{arm_defines}
/*
 * The body a 64-bit test and an alignment test select: the word-arena body
 * exactly when the access is 64-bit and the resolved index is qword-aligned,
 * the byte-ladder body otherwise. Both inputs are evaluated once.
 */
#define KPROG_ARM64_STACK_ARM(IS_W64, IS_ALIGNED)                           \\
\t((__u8)(((IS_W64) && (IS_ALIGNED)) ? 1 : 0))
_Static_assert(KPROG_ARM64_STACK_ARM_WIDTH64 == {width}U,
\t       "arm64 stack arm 64-bit width code drift");
_Static_assert(ARM64_WIDTH_64 == KPROG_ARM64_STACK_ARM_WIDTH64,
\t       "arm64 stack arm 64-bit width code drift");
_Static_assert(KPROG_ARM64_STACK_ARM_COUNT == {count}U,
\t       "arm64 stack arm count drift");
_Static_assert({word} != {byte},
\t       "arm64 stack arm codes must be distinct");
_Static_assert(KPROG_ARM64_STACK_ARM_WORD == 1U && KPROG_ARM64_STACK_ARM_BYTE == 0U,
\t       "arm64 stack arm code drift");
/* The selector must name each body at its own width/alignment pair. */
_Static_assert(KPROG_ARM64_STACK_ARM(1, 1) == {word},
\t       "arm64 stack arm word selection drift");
_Static_assert(KPROG_ARM64_STACK_ARM(1, 0) == {byte},
\t       "arm64 stack arm unaligned selection drift");
_Static_assert(KPROG_ARM64_STACK_ARM(0, 1) == {byte},
\t       "arm64 stack arm narrow selection drift");
_Static_assert(KPROG_ARM64_STACK_ARM(0, 0) == {byte},
\t       "arm64 stack arm narrow unaligned selection drift");
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
                    f"generated arm64 stack arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
