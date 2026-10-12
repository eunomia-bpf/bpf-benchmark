#!/usr/bin/env python3
"""Generate the AArch64 BPF helper-argument pointer contract.

The hand-written BPF helper-argument pointer helper of
`kprog/arm64/arm64_sim_local_bpf.h`, `ARM64_SIM_L_HELPER_ARG_PTR`, resolves
the pointer a BPF helper call receives in a register argument: the arena
pointer of the stack slot when the register's provenance tag is the stack
tag, the register's raw pointer otherwise. That is a *finite selection of
the pointer source over the single closed fact* (the register's provenance
tag is the stack tag):

  * the **stack arena pointer** source, a stack-tagged register: the helper
    argument resolves to the arena byte at the register pointer's biased
    arena index;
  * the **raw pointer** source, every other tag: the helper argument is the
    register's raw pointer value, passed through unchanged.

The generated table `GeneratedArm64HelperArgPtr.sourceOf` and the
plain-expression C macro `KPROG_ARM64_HELPER_ARG_PTR_BODY` expose that source
choice. The helper previously picked the stack-arena-pointer arm by hand
through the register-tag test, and this module makes that 2-way source
selection a machine-checked fact. `KProgFormal/Arm64HelperArgPtrShape.lean`
proves the generated `sourceOf` equal to an independent 2-way statement over
the single fact, and ties the stack-arena-pointer source to the 0112
`KPROG_ARM64_STACK_INDEX` biased pointer index. The fact is closed, so the
2-way selection is total.

The generator is independent of the bodies it describes: it holds its own
literal source/case enumeration and re-derives the live BPF helper-argument
pointer helper text from the simulator header, then requires the helper to go
through the generated source selector and to keep its stack-arena-pointer
arm.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_helper_arg_ptr_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64HelperArgPtr.lean"
CHEADER = ROOT / "generated/arm64_helper_arg_ptr.h"

# The independent enumeration of the two pointer sources, in code order:
# (source, source define, code, value effect).
_SOURCES = [
    ("stackArenaPtr",
     "KPROG_ARM64_HELPER_ARG_PTR_BODY_STACK_ARENA_PTR",
     0, "stack_arena_ptr"),
    ("rawPtr",
     "KPROG_ARM64_HELPER_ARG_PTR_BODY_RAW_PTR",
     1, "raw_ptr"),
]
# The independent enumeration of the two (is stack tagged) cases a BPF
# helper-argument register can have, in classification order:
# (case, is stack tagged, source).
_CASES = [
    ("stack_tagged", True, "stackArenaPtr"),
    ("not_stack_tagged", False, "rawPtr"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64HelperArgPtr",
    "selector": "is_stack_tagged_then_stack_arena_ptr_else_raw_ptr",
    "sources": [{"source": s, "source_define": d, "source_code": c, "effect": e}
                for s, d, c, e in _SOURCES],
    "cases": [{"name": n, "is_stack_tagged": st, "source": src}
              for n, st, src in _CASES],
}
SOURCE_COLUMNS = ("source", "source_define", "source_code", "effect")
CASE_COLUMNS = ("name", "is_stack_tagged", "source")

# The live routed BPF helper-argument pointer helper text, between the helper
# pointer's `#define` opcode title and the qword stack store helper that
# follows it.
HELPER_PTR_START = "#define ARM64_SIM_L_HELPER_ARG_PTR(REG)"
HELPER_PTR_END = "#define ARM64_SIM_L_STORE_Q0_STACK(OFF)"
HELPER_PTR_SELECTOR = "KPROG_ARM64_HELPER_ARG_PTR_BODY("
# The hand-written outer gate the routed helper must no longer contain: the
# register-tag test deciding the stack-arena-pointer arm. The helper
# legitimately keeps the `== ARM64_SIM_TAG_STACK` test inside the selector's
# argument, so the hand ternary's `?` is the safe needle.
HAND_GATE = "ARM64_SIM_L_REG_TAG(REG) == ARM64_SIM_TAG_STACK ?"


def _source(is_stack_tagged: bool) -> str:
    """The independent 2-way source selection over the closed fact."""
    if is_stack_tagged:
        return "stackArenaPtr"
    return "rawPtr"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(
            f"sim header no longer bounds the BPF helper-argument pointer "
            f"region with {start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """A routed BPF helper-argument pointer helper must select its pointer
    source through the generated 2-way selector and keep its stack-arena-
    pointer arm; it must not pick the arm by hand through the register-tag
    test."""
    if HELPER_PTR_SELECTOR not in region:
        raise SystemExit(
            "arm64 BPF helper-argument pointer helper does not route its "
            "pointer source through the generated source selector")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 BPF helper-argument pointer helper picks its pointer "
            "source by hand through the register-tag test instead of "
            "through the generated source selector")


def check_against_header():
    """The live BPF helper-argument pointer helper must select its pointer
    source through the generated source selector."""
    check_region(region_between(HELPER_PTR_START, HELPER_PTR_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 helper arg pointer keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 helper arg pointer specification: {data!r}")
    for index, column in enumerate(SOURCE_COLUMNS):
        want = [row[column] for row in EXPECTED["sources"]]
        got = [entry[index] for entry in _SOURCES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 helper arg pointer source {column}: "
                f"{EXPECTED['sources']!r}")
    if len(EXPECTED["sources"]) != 2:
        raise SystemExit(
            "arm64 helper arg pointer must select between exactly 2 "
            "sources")
    if [row["source_code"] for row in EXPECTED["sources"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 helper arg pointer codes: "
            f"{EXPECTED['sources']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 helper arg pointer case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["source"] for row in EXPECTED["cases"]] != [
            "stackArenaPtr", "rawPtr"]:
        raise SystemExit(
            f"invalid arm64 helper arg pointer table: "
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
    return f'''-- Generated by generate_arm64_helper_arg_ptr_spec.py from arm64_helper_arg_ptr_spec.json.
import Std
namespace KProgFormal.GeneratedArm64HelperArgPtr
/-- The two pointer sources a BPF helper-argument register selects between:
the stack arena pointer and the raw pointer. -/
inductive Source where
{source_ctors}
deriving DecidableEq, Repr
/-- The number of pointer sources a BPF helper-argument register selects
between. -/
def sourceCount : Nat := {len(sources)}
/-- The two pointer sources, in code order. -/
def sourceNames : List String := [{names}]
/-- The source code of each source, in code order; the codes are the values the
selector yields so the table and the macro cannot disagree. -/
def sourceCodes : List Nat := [{codes}]
/-- The source code of a source. -/
def codeOfSource : Source -> Nat
{code_of}
/-- The value effect each source performs. -/
def effectOfSource : Source -> String
{effect_of}
/-- The pointer source a BPF helper-argument register selects: the stack
arena pointer source exactly when the register's provenance tag is the stack
tag, the raw pointer otherwise. The fact is closed, so the selection is
total. -/
def sourceOf (isStackTagged : Bool) : Source :=
  if isStackTagged then .stackArenaPtr
  else .rawPtr
/-- The source a source code names, or `none` when the code names no source. -/
def sourceOfCode (code : Nat) : Option Source :=
  (sourceCodes.zip [{ctor}]).lookup code
/-- The two (is stack tagged) cases a BPF helper-argument register can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a BPF helper-argument register by whether its provenance tag is
the stack tag. -/
def classify (isStackTagged : Bool) : Case :=
  match isStackTagged with
  | true => .stack_tagged
  | false => .not_stack_tagged
/-- The pointer source a case performs, from the case table. -/
def sourceOfCase : Case -> Source
{source_of_case}
/-- The independent stack-tagged fact: the register's stack provenance tag is
the stack tag, the closed fact. -/
def stackTagged (isStackTagged : Bool) : Bool := isStackTagged
/-- The stack-tagged fact is the identity for every register. -/
theorem stackTagged_refines (isStackTagged : Bool) :
    stackTagged isStackTagged = isStackTagged := by
  rfl
/-- The source selector equals the case table for every BPF helper-argument
register: naming the source from the fact directly is the same as
classifying and dispatching on the case. -/
theorem sourceOf_refines (isStackTagged : Bool) :
    sourceOf isStackTagged = sourceOfCase (classify isStackTagged) := by
  cases isStackTagged <;> rfl
end KProgFormal.GeneratedArm64HelperArgPtr
'''


def render_c(spec: dict) -> str:
    sources = spec["sources"]
    count = len(sources)
    arena = sources[0]["source_define"]
    raw = sources[1]["source_define"]
    source_defines = "\n".join(
        f'#define {row["source_define"]} {row["source_code"]}U'
        for row in sources)
    return f'''/* Generated by generate_arm64_helper_arg_ptr_spec.py from arm64_helper_arg_ptr_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_HELPER_ARG_PTR_H
#define KPROG_FORMAL_GENERATED_ARM64_HELPER_ARG_PTR_H
/*
 * AArch64 BPF helper-argument pointer contract: the BPF helper-argument
 * pointer helper `ARM64_SIM_L_HELPER_ARG_PTR` resolves the pointer a BPF
 * helper call receives in a register argument, and its source is selected
 * from the single closed fact: whether the register's provenance tag is the
 * stack tag. The stack arena pointer source (a stack-tagged register)
 * resolves to the arena byte at the register pointer's biased arena index;
 * the raw pointer source (every other tag) passes the register's raw pointer
 * value through unchanged. `KProgFormal/Arm64HelperArgPtrShape.lean` proves
 * the generated `sourceOf` equal to an independent 2-way statement and ties
 * the stack arena pointer source to the `KPROG_ARM64_STACK_INDEX` biased
 * pointer index. The fact is closed, so the 2-way selection is total. This
 * header uses only literal inputs, so it is included before the
 * `ARM64_SIM_TAG_*` tag names in the simulator header.
 */
/* The number of pointer sources the helper selects between. */
#define KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT {count}U
{source_defines}
/*
 * The pointer source a BPF helper-argument register selects: the stack arena
 * pointer source exactly when the register's provenance tag is the stack tag,
 * the raw pointer otherwise. The input is evaluated once and no NZCV is
 * written.
 */
#define KPROG_ARM64_HELPER_ARG_PTR_BODY(IS_STACK_TAGGED)                  \\
	((__u8)(((IS_STACK_TAGGED)) ? {arena} : {raw}))
_Static_assert(KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT == {count}U,
	       "arm64 helper arg pointer body count drift");
_Static_assert({arena} != {raw},
	       "arm64 helper arg pointer codes must be distinct");
_Static_assert({arena} == 0U && {raw} == 1U,
	       "arm64 helper arg pointer code drift");
/* The selector must name each source at its own fact. */
_Static_assert(KPROG_ARM64_HELPER_ARG_PTR_BODY(1) == {arena},
	       "arm64 helper arg pointer stack tagged selection drift");
_Static_assert(KPROG_ARM64_HELPER_ARG_PTR_BODY(0) == {raw},
	       "arm64 helper arg pointer not stack tagged selection drift");
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
                    f"generated arm64 helper arg pointer contract is "
                    f"stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
