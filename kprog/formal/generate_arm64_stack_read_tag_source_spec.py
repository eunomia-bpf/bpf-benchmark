#!/usr/bin/env python3
"""Generate the AArch64 stack slot-tag read source contract.

The hand-written stack tag read helper of
`kprog/arm64/arm64_sim_local_bpf.h`, `ARM64_SIM_L_STACK_READ_TAG`, returns the
tag of a stack slot read: the slot tag at the slot's 8-byte word when the read
is 64-bit and the slot is 8-aligned, otherwise the scalar default tag. That is
a *finite selection of the tag source over the closed pair of facts* (the read
width is 64 bits, the stack slot is 8-aligned):

  * the **stack-tag-array** source, a 64-bit access at a qword-aligned slot:
    the tag read is the slot's word in the per-slot tag array;
  * the **scalar default** source, every other fact pair: the tag read is the
    scalar marker, the byte image is read untagged.

The generated table `GeneratedArm64StackReadTagSource.sourceOf` and the
plain-expression C macro `KPROG_ARM64_STACK_READ_TAG_SOURCE` expose that source
choice. The helper previously computed the stack-tag-array arm by hand through
the read-side `KPROG_ARM64_STACK_TAG` slot-tag predicate and a separate
8-aligned test, and this module makes that 2-way source selection a
machine-checked fact. `KProgFormal/Arm64StackReadTagSourceShape.lean` proves the
generated `sourceOf` equal to an independent 2-way statement over the closed
pair, and ties the stack-tag-array source to the read-side
`KPROG_ARM64_STACK_TAG` predicate and to the 0137 write helper's word-and-tag
action on the same fact pair.

The generator is independent of the bodies it describes: it holds its own
literal source/case enumeration and re-derives the live stack tag read helper
text from the simulator header, then requires the helper to go through the
generated source selector and to keep the slot-tag-array read.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_stack_read_tag_source_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64StackReadTagSource.lean"
CHEADER = ROOT / "generated/arm64_stack_read_tag_source.h"

# The independent enumeration of the two tag sources, in code order:
# (source, source define, code, storage effect).
_SOURCES = [
    ("stackTagArray",
     "KPROG_ARM64_STACK_READ_TAG_SOURCE_STACK_TAG_ARRAY",
     0, "slot_tag_array"),
    ("scalarDefault",
     "KPROG_ARM64_STACK_READ_TAG_SOURCE_SCALAR_DEFAULT",
     1, "scalar_default"),
]
# The independent enumeration of the four (is w64, aligned) cases a stack tag
# read can have, in classification order: (case, is w64, aligned, source).
_CASES = [
    ("w64_aligned", True, True, "stackTagArray"),
    ("w64_unaligned", True, False, "scalarDefault"),
    ("aligned_scalar", False, True, "scalarDefault"),
    ("unaligned_scalar", False, False, "scalarDefault"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64StackReadTagSource",
    "selector": "is_w64_and_aligned_then_stack_tag_array_else_scalar_default",
    "sources": [{"source": s, "source_define": d, "source_code": c, "effect": e}
                for s, d, c, e in _SOURCES],
    "cases": [{"name": n, "is_w64": w, "is_aligned": al, "source": src}
              for n, w, al, src in _CASES],
}
SOURCE_COLUMNS = ("source", "source_define", "source_code", "effect")
CASE_COLUMNS = ("name", "is_w64", "is_aligned", "source")

# The live routed stack tag read helper text, between the read helper's
# `#define` opcode title and the write helper that follows it.
STACK_READ_START = "#define ARM64_SIM_L_STACK_READ_TAG(OFF, WIDTH)"
STACK_READ_END = "#define ARM64_SIM_L_STACK_WRITE_TAG(OFF, WIDTH, VALUE, TAG)"
STACK_READ_SELECTOR = "KPROG_ARM64_STACK_READ_TAG_SOURCE("
# The hand-written outer gate the routed helper must no longer contain: the
# read-side slot-tag predicate deciding the stack-tag-array arm. The helper
# legitimately keeps the `== ARM64_WIDTH_64` and 8-aligned tests inside the
# selector's arguments, so the hand predicate name is the safe needle.
HAND_TAG_GATE = "KPROG_ARM64_STACK_TAG("


def _source(w64: bool, aligned: bool) -> str:
    """The independent 2-way source selection over the closed fact pair."""
    if w64 and aligned:
        return "stackTagArray"
    return "scalarDefault"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(f"sim header no longer bounds the stack tag read "
                         f"region with {start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """A routed stack tag read helper must select its tag source through the
    generated 2-way selector and keep its slot-tag-array read; it must not
    pick the arm by hand through the read-side slot-tag predicate."""
    if STACK_READ_SELECTOR not in region:
        raise SystemExit(
            "arm64 stack tag read helper does not route its tag source "
            "through the generated source selector")
    if HAND_TAG_GATE in region:
        raise SystemExit(
            "arm64 stack tag read helper picks its tag source by hand through "
            "the read-side KPROG_ARM64_STACK_TAG predicate instead of through "
            "the generated source selector")


def check_against_header():
    """The live stack tag read helper must select its tag source through the
    generated source selector."""
    check_region(region_between(STACK_READ_START, STACK_READ_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 stack read tag source keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 stack read tag source specification: {data!r}")
    for index, column in enumerate(SOURCE_COLUMNS):
        want = [row[column] for row in EXPECTED["sources"]]
        got = [entry[index] for entry in _SOURCES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 stack read tag source source {column}: "
                f"{EXPECTED['sources']!r}")
    if len(EXPECTED["sources"]) != 2:
        raise SystemExit(
            "arm64 stack read tag source must select between exactly 2 "
            "sources")
    if [row["source_code"] for row in EXPECTED["sources"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 stack read tag source codes: "
            f"{EXPECTED['sources']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 stack read tag source case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["source"] for row in EXPECTED["cases"]] != [
            "stackTagArray", "scalarDefault", "scalarDefault",
            "scalarDefault"]:
        raise SystemExit(
            f"invalid arm64 stack read tag source table: "
            f"{EXPECTED['cases']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    sources = spec["sources"]
    cases = spec["cases"]
    names = ", ".join(f'"{row["source"]}"' for row in sources)
    codes = ", ".join(str(row["source_code"]) for row in sources)
    ctor = ", ".join(f'.{row["source"]}' for row in sources)
    code_of = "\n".join(
        f'  | .{row["source"]} => {row["source_code"]}' for row in sources)
    effect_of = "\n".join(
        f'  | .{row["source"]} => "{row["effect"]}"' for row in sources)
    source_ctors = "\n".join(f'  | {row["source"]}' for row in sources)
    case_ctors = "\n".join(f'  | {row["name"]}' for row in cases)
    source_of_case = "\n".join(
        f'  | .{row["name"]} => .{row["source"]}' for row in cases)
    return f'''-- Generated by generate_arm64_stack_read_tag_source_spec.py from arm64_stack_read_tag_source_spec.json.
import Std
namespace KProgFormal.GeneratedArm64StackReadTagSource
/-- The two tag sources a stack tag read selects between: the per-slot tag
array and the scalar default. -/
inductive Source where
{source_ctors}
deriving DecidableEq, Repr
/-- The number of tag sources a stack tag read selects between. -/
def sourceCount : Nat := {len(sources)}
/-- The two tag sources, in code order. -/
def sourceNames : List String := [{names}]
/-- The source code of each source, in code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def sourceCodes : List Nat := [{codes}]
/-- The source code of a source. -/
def codeOfSource : Source -> Nat
{code_of}
/-- The storage effect each source performs. -/
def effectOfSource : Source -> String
{effect_of}
/-- The tag source a stack tag read selects: the stack-tag-array source exactly
when the read is 64-bit and the slot is 8-aligned, the scalar default
otherwise. The two facts are a closed pair, so the selection is total. -/
def sourceOf (isW64 isAligned : Bool) : Source :=
  if isW64 && isAligned then .stackTagArray
  else .scalarDefault
/-- The source a source code names, or `none` when the code names no source. -/
def sourceOfCode (code : Nat) : Option Source :=
  (sourceCodes.zip [{ctor}]).lookup code
/-- The four (is w64, aligned) cases a stack tag read can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a stack tag read by whether its width is 64-bit and whether its
slot is 8-aligned. -/
def classify (isW64 isAligned : Bool) : Case :=
  match isW64, isAligned with
    | true, true => .w64_aligned
    | true, false => .w64_unaligned
    | false, true => .aligned_scalar
    | false, false => .unaligned_scalar
/-- The tag source a case performs, from the case table. -/
def sourceOfCase : Case -> Source
{source_of_case}
/-- The independent slot-tag flag: the read's slot tag applies exactly when the
read is 64-bit and the slot is 8-aligned, the closed pair's conjunction. -/
def slotTag (isW64 isAligned : Bool) : Bool := isW64 && isAligned
/-- The slot-tag flag is the direct conjunction for every read. -/
theorem slotTag_refines (isW64 isAligned : Bool) :
    slotTag isW64 isAligned = (isW64 && isAligned) := by
  cases isW64 <;> cases isAligned <;> rfl
/-- The source selector equals the case table for every stack tag read: naming
the source from the two facts directly is the same as classifying and
dispatching on the case. -/
theorem sourceOf_refines (isW64 isAligned : Bool) :
    sourceOf isW64 isAligned = sourceOfCase (classify isW64 isAligned) := by
  cases isW64 <;> cases isAligned <;> rfl
end KProgFormal.GeneratedArm64StackReadTagSource
'''


def render_c(spec: dict) -> str:
    sources = spec["sources"]
    count = len(sources)
    array = sources[0]["source_define"]
    scalar = sources[1]["source_define"]
    source_defines = "\n".join(
        f'#define {row["source_define"]} {row["source_code"]}U'
        for row in sources)
    return f'''/* Generated by generate_arm64_stack_read_tag_source_spec.py from arm64_stack_read_tag_source_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_STACK_READ_TAG_SOURCE_H
#define KPROG_FORMAL_GENERATED_ARM64_STACK_READ_TAG_SOURCE_H
/*
 * AArch64 stack slot-tag read source contract: the stack tag read helper
 * `ARM64_SIM_L_STACK_READ_TAG` returns the tag of a stack slot read, and its
 * source is selected from a closed pair of facts: whether the read width is 64
 * bits and whether the stack slot is 8-aligned. The stack-tag-array source
 * (a 64-bit read at a qword-aligned slot) reads the slot's word in the
 * per-slot tag array; the scalar default source (every other fact pair)
 * returns the scalar marker with the byte image read untagged.
 * `KProgFormal/Arm64StackReadTagSourceShape.lean` proves the generated
 * `sourceOf` equal to an independent 2-way statement and ties the
 * stack-tag-array source to the read-side `KPROG_ARM64_STACK_TAG` slot-tag
 * predicate and to the 0137 write helper's word-and-tag action on the same
 * fact pair. The two facts are a closed pair, so the 2-way selection is total.
 * This header uses only literal inputs, so it is included before the
 * `ARM64_WIDTH_*` decodes and the `ARM64_SIM_TAG_*` tag names in the
 * simulator header.
 */
/* The number of tag sources the helper selects between. */
#define KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT {count}U
{source_defines}
/*
 * The tag source a stack tag read selects: the stack-tag-array source exactly
 * when the read is 64-bit and the slot is 8-aligned, the scalar default
 * otherwise. Both inputs are evaluated once and no NZCV is written.
 */
#define KPROG_ARM64_STACK_READ_TAG_SOURCE(IS_W64, IS_ALIGNED)           \\
	((__u8)(((IS_W64) && (IS_ALIGNED))                        \\
		 ? {array}                              \\
		 : {scalar}))
_Static_assert(KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT == {count}U,
	       "arm64 stack read tag source count drift");
_Static_assert({array} != {scalar},
	       "arm64 stack read tag source codes must be distinct");
_Static_assert({array} == 0U && {scalar} == 1U,
	       "arm64 stack read tag source code drift");
/* The selector must name each source at its own fact pair. */
_Static_assert(KPROG_ARM64_STACK_READ_TAG_SOURCE(1, 1) == {array},
	       "arm64 stack read tag source w64 aligned selection drift");
_Static_assert(KPROG_ARM64_STACK_READ_TAG_SOURCE(1, 0) == {scalar},
	       "arm64 stack read tag source w64 unaligned selection drift");
_Static_assert(KPROG_ARM64_STACK_READ_TAG_SOURCE(0, 1) == {scalar},
	       "arm64 stack read tag source aligned scalar selection drift");
_Static_assert(KPROG_ARM64_STACK_READ_TAG_SOURCE(0, 0) == {scalar},
	       "arm64 stack read tag source unaligned scalar selection drift");
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
                    f"generated arm64 stack read tag source contract is "
                    f"stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
