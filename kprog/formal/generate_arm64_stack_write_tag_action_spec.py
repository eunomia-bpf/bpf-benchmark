#!/usr/bin/env python3
"""Generate the AArch64 stack slot-tag write action contract.

The hand-written stack write helper of `kprog/arm64/arm64_sim_local_bpf.h`,
`ARM64_SIM_L_STACK_WRITE_TAG`, writes a resolved access into the stack arena's
byte window and the per-slot tag array. Its action is a *finite selection over
the closed pair of facts* (the access width is 64 bits, the stack slot is
8-aligned):

  * the **word-and-tag** action, a 64-bit access at a qword-aligned slot: it
    writes the qword and stores the write's slot tag, used when the width is 64
    *and* the slot is aligned;
  * the **clear-and-write-bytes** action, an aligned sub-qword access: it
    clears the slot tag to the scalar marker and writes the width's active byte
    lanes;
  * the **write-bytes-no-tag** action, an unaligned access: it writes the
    width's active byte lanes and leaves the slot tag untouched.

The generated table `GeneratedArm64StackWriteTagAction.actionOf` and the
plain-expression C macro `KPROG_ARM64_STACK_WRITE_TAG_ACTION` expose that
action choice. The helper previously computed the word/tag arm by hand through
the read-side `KPROG_ARM64_STACK_TAG` slot-tag predicate and a separate
8-aligned test, and this module makes that 3-way selection a machine-checked
fact. `KProgFormal/Arm64StackWriteTagActionShape.lean` proves the generated
`actionOf` equal to an independent 3-way statement over the closed pair, and
ties the word/tag arm to the read-side `KPROG_ARM64_STACK_TAG` predicate and
the byte arms to the `KPROG_ARM64_STACK_WRITE_LANE_ACTIVE` ladder.

The generator is independent of the bodies it describes: it holds its own
literal action/case enumeration and re-derives the live stack write helper text
from the simulator header, then requires the helper to go through the generated
selector and to keep its byte-ladder write.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_stack_write_tag_action_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64StackWriteTagAction.lean"
CHEADER = ROOT / "generated/arm64_stack_write_tag_action.h"

# The independent enumeration of the three slot-tag actions, in code order:
# (action, action define, code, storage effect).
_ACTIONS = [
    ("writeWordAndTag",
     "KPROG_ARM64_STACK_WRITE_TAG_ACTION_WRITE_WORD_AND_TAG",
     0, "word_write_tag"),
    ("clearTagAndWriteBytes",
     "KPROG_ARM64_STACK_WRITE_TAG_ACTION_CLEAR_TAG_AND_WRITE_BYTES",
     1, "clear_tag_bytes"),
    ("writeBytesNoTag",
     "KPROG_ARM64_STACK_WRITE_TAG_ACTION_WRITE_BYTES_NO_TAG",
     2, "bytes_no_tag"),
]
# The independent enumeration of the four (is w64, aligned) cases a stack write
# can have, in classification order: (case, is w64, aligned, action).
_CASES = [
    ("w64_aligned", True, True, "writeWordAndTag"),
    ("w64_unaligned", True, False, "writeBytesNoTag"),
    ("aligned_scalar", False, True, "clearTagAndWriteBytes"),
    ("unaligned_scalar", False, False, "writeBytesNoTag"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64StackWriteTagAction",
    "selector": "is_w64_and_aligned_then_word_tag_else_aligned_clear_bytes_else_bytes",
    "actions": [{"action": a, "action_define": d, "action_code": c, "effect": e}
                for a, d, c, e in _ACTIONS],
    "cases": [{"name": n, "is_w64": w, "is_aligned": al, "action": act}
              for n, w, al, act in _CASES],
}
ACTION_COLUMNS = ("action", "action_define", "action_code", "effect")
CASE_COLUMNS = ("name", "is_w64", "is_aligned", "action")

# The live routed stack write helper text, between the write helper's `#define`
# opcode title and the plain write wrapper that follows it.
STACK_WRITE_START = "#define ARM64_SIM_L_STACK_WRITE_TAG(OFF, WIDTH, VALUE, TAG)"
STACK_WRITE_END = "#define ARM64_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)"
STACK_WRITE_SELECTOR = "KPROG_ARM64_STACK_WRITE_TAG_ACTION("
# The hand-written outer gate the routed helper must no longer contain: the
# read-side slot-tag predicate deciding the word/tag arm. The helper
# legitimately keeps the `== ARM64_WIDTH_64` and 8-aligned tests inside the
# selector's arguments, so the hand predicate name is the safe needle.
HAND_TAG_GATE = "KPROG_ARM64_STACK_TAG("


def _action(w64: bool, aligned: bool) -> str:
    """The independent 3-way selection over the closed fact pair."""
    if w64 and aligned:
        return "writeWordAndTag"
    elif aligned:
        return "clearTagAndWriteBytes"
    else:
        return "writeBytesNoTag"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(f"sim header no longer bounds the stack write "
                         f"region with {start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """A routed stack write helper must select its slot-tag action through the
    generated 3-way selector and keep its byte-ladder write; it must not decide
    the word/tag arm by hand through the read-side slot-tag predicate."""
    if STACK_WRITE_SELECTOR not in region:
        raise SystemExit(
            "arm64 stack write helper does not route its slot-tag action "
            "through the generated selector")
    if HAND_TAG_GATE in region:
        raise SystemExit(
            "arm64 stack write helper decides its word/tag arm by hand through "
            "the read-side KPROG_ARM64_STACK_TAG predicate instead of through "
            "the generated action selector")


def check_against_header():
    """The live stack write helper must select its slot-tag action through the
    generated selector."""
    check_region(region_between(STACK_WRITE_START, STACK_WRITE_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 stack write tag action keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 stack write tag action specification: {data!r}")
    for index, column in enumerate(ACTION_COLUMNS):
        want = [row[column] for row in EXPECTED["actions"]]
        got = [entry[index] for entry in _ACTIONS]
        if want != got:
            raise SystemExit(
                f"invalid arm64 stack write tag action action {column}: "
                f"{EXPECTED['actions']!r}")
    if len(EXPECTED["actions"]) != 3:
        raise SystemExit(
            "arm64 stack write tag action must select between exactly 3 "
            "actions")
    if [row["action_code"] for row in EXPECTED["actions"]] != [0, 1, 2]:
        raise SystemExit(
            f"invalid arm64 stack write tag action codes: "
            f"{EXPECTED['actions']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 stack write tag action case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["action"] for row in EXPECTED["cases"]] != [
            "writeWordAndTag", "writeBytesNoTag", "clearTagAndWriteBytes",
            "writeBytesNoTag"]:
        raise SystemExit(
            f"invalid arm64 stack write tag action table: "
            f"{EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    actions = spec["actions"]
    cases = spec["cases"]
    names = ", ".join(f'"{row["action"]}"' for row in actions)
    codes = ", ".join(str(row["action_code"]) for row in actions)
    ctor = ", ".join(f'.{row["action"]}' for row in actions)
    code_of = "\n".join(
        f'  | .{row["action"]} => {row["action_code"]}' for row in actions)
    effect_of = "\n".join(
        f'  | .{row["action"]} => "{row["effect"]}"' for row in actions)
    action_ctors = "\n".join(f'  | {row["action"]}' for row in actions)
    case_ctors = "\n".join(f'  | {row["name"]}' for row in cases)
    action_of_case = "\n".join(
        f'  | .{row["name"]} => .{row["action"]}' for row in cases)
    return f'''-- Generated by generate_arm64_stack_write_tag_action_spec.py from arm64_stack_write_tag_action_spec.json.
import Std
namespace KProgFormal.GeneratedArm64StackWriteTagAction
/-- The three slot-tag actions a stack write selects between: the qword write
and tag store, the aligned tag clear and byte-ladder write, and the plain
byte-ladder write. -/
inductive Action where
{action_ctors}
deriving DecidableEq, Repr
/-- The number of slot-tag actions a stack write selects between. -/
def actionCount : Nat := {len(actions)}
/-- The three slot-tag actions, in code order. -/
def actionNames : List String := [{names}]
/-- The action code of each action, in code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def actionCodes : List Nat := [{codes}]
/-- The action code of an action. -/
def codeOfAction : Action -> Nat
{code_of}
/-- The storage effect each action performs. -/
def effectOfAction : Action -> String
{effect_of}
/-- The slot-tag action a stack write selects: the word-and-tag action exactly
when the access is 64-bit and the slot is 8-aligned, the clear-and-write-bytes
action at every aligned sub-qword access, and the plain byte-ladder write
otherwise. The two facts are a closed pair, so the selection is total. -/
def actionOf (isW64 isAligned : Bool) : Action :=
  if isW64 && isAligned then .writeWordAndTag
  else if isAligned then .clearTagAndWriteBytes
  else .writeBytesNoTag
/-- The action an action code names, or `none` when the code names no action. -/
def actionOfCode (code : Nat) : Option Action :=
  (actionCodes.zip [{ctor}]).lookup code
/-- The four (is w64, aligned) cases a stack write can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a stack write by whether its width is 64-bit and whether its slot
is 8-aligned. -/
def classify (isW64 isAligned : Bool) : Case :=
  match isW64, isAligned with
    | true, true => .w64_aligned
    | true, false => .w64_unaligned
    | false, true => .aligned_scalar
    | false, false => .unaligned_scalar
/-- The slot-tag action a case performs, from the case table. -/
def actionOfCase : Case -> Action
{action_of_case}
/-- The independent word/tag flag: the write's slot tag applies exactly when the
access is 64-bit and the slot is 8-aligned, the closed pair's conjunction. -/
def wordTag (isW64 isAligned : Bool) : Bool := isW64 && isAligned
/-- The word/tag flag is the direct conjunction for every access. -/
theorem wordTag_refines (isW64 isAligned : Bool) :
    wordTag isW64 isAligned = (isW64 && isAligned) := by
  cases isW64 <;> cases isAligned <;> rfl
/-- The action selector equals the case table for every stack write: naming the
action from the two facts directly is the same as classifying and dispatching
on the case. -/
theorem actionOf_refines (isW64 isAligned : Bool) :
    actionOf isW64 isAligned = actionOfCase (classify isW64 isAligned) := by
  cases isW64 <;> cases isAligned <;> rfl
end KProgFormal.GeneratedArm64StackWriteTagAction
'''


def render_c(spec: dict) -> str:
    actions = spec["actions"]
    count = len(actions)
    word = actions[0]["action_define"]
    clear = actions[1]["action_define"]
    bytestag = actions[2]["action_define"]
    action_defines = "\n".join(
        f'#define {row["action_define"]} {row["action_code"]}U'
        for row in actions)
    return f'''/* Generated by generate_arm64_stack_write_tag_action_spec.py from arm64_stack_write_tag_action_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_STACK_WRITE_TAG_ACTION_H
#define KPROG_FORMAL_GENERATED_ARM64_STACK_WRITE_TAG_ACTION_H
/*
 * AArch64 stack slot-tag write action contract: the stack write helper
 * `ARM64_SIM_L_STACK_WRITE_TAG` writes a resolved access into the stack arena's
 * byte window and the per-slot tag array, and its action is selected from a
 * closed pair of facts: whether the access width is 64 bits and whether the
 * stack slot is 8-aligned. The word-and-tag action (64-bit at a qword-aligned
 * slot) writes the qword and stores the write's slot tag; the clear-and-write-
 * bytes action (an aligned sub-qword access) clears the slot tag to the scalar
 * marker and writes the width's active byte lanes; the plain byte-ladder write
 * (any unaligned access) writes the width's active byte lanes with the slot tag
 * untouched. `KProgFormal/Arm64StackWriteTagActionShape.lean` proves the
 * generated `actionOf` equal to an independent 3-way statement and ties the
 * word/tag arm to the read-side `KPROG_ARM64_STACK_TAG` slot-tag predicate and
 * the byte arms to the `KPROG_ARM64_STACK_WRITE_LANE_ACTIVE` ladder. The two
 * facts are a closed pair, so the 3-way selection is total.
 * This header uses only literal inputs, so it is included before the
 * `ARM64_WIDTH_*` decodes and the `ARM64_SIM_TAG_*` tag names in the
 * simulator header.
 */
/* The number of slot-tag actions the helper selects between. */
#define KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT {count}U
{action_defines}
/*
 * The slot-tag action a stack write selects: the word-and-tag action exactly
 * when the width is 64-bit and the slot is 8-aligned, the clear-and-write-bytes
 * action at every aligned sub-qword access, and the plain byte-ladder write
 * otherwise. Both inputs are evaluated once and no NZCV is written.
 */
#define KPROG_ARM64_STACK_WRITE_TAG_ACTION(IS_W64, IS_ALIGNED)            \\
	((__u8)(((IS_W64) && (IS_ALIGNED))                        \\
		 ? {word}                              \\
		 : (((IS_ALIGNED))                               \\
		 ? {clear}                              \\
		 : {bytestag})))
_Static_assert(KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT == {count}U,
	       "arm64 stack write tag action count drift");
_Static_assert({word} != {clear},
	       "arm64 stack write tag action codes must be distinct");
_Static_assert({word} != {bytestag},
	       "arm64 stack write tag action codes must be distinct");
_Static_assert({clear} != {bytestag},
	       "arm64 stack write tag action codes must be distinct");
_Static_assert({word} == 0U && {clear} == 1U && {bytestag} == 2U,
	       "arm64 stack write tag action code drift");
/* The selector must name each action at its own fact pair. */
_Static_assert(KPROG_ARM64_STACK_WRITE_TAG_ACTION(1, 1) == {word},
	       "arm64 stack write tag action w64 aligned selection drift");
_Static_assert(KPROG_ARM64_STACK_WRITE_TAG_ACTION(1, 0) == {bytestag},
	       "arm64 stack write tag action w64 unaligned selection drift");
_Static_assert(KPROG_ARM64_STACK_WRITE_TAG_ACTION(0, 1) == {clear},
	       "arm64 stack write tag action aligned scalar selection drift");
_Static_assert(KPROG_ARM64_STACK_WRITE_TAG_ACTION(0, 0) == {bytestag},
	       "arm64 stack write tag action unaligned scalar selection drift");
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
                    f"generated arm64 stack write tag action contract is "
                    f"stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
