#!/usr/bin/env python3
"""Generate the AArch64 memory index-value source contract.

The hand-written AArch64 memory address offset of
`kprog/arm64/arm64_sim_local_bpf.h` -- `ARM64_SIM_L_MEM_BASE_OFF`, which every
scalar load/store helper and the vector/pair memory steps build their address
offset from -- adds the source-modified index register value to the immediate
exactly when the addressing mode carries an index register:

    (INDEX) ? ARM64_SIM_L_MOD_VALUE((INDEX), MOD(AUX), SHIFT(AUX),
                                    ARM64_WIDTH_64)
            : 0

The index value is selected from a *single closed fact* -- whether the
addressing mode carries an index register, the same `has_index` fact the offset
contract `KPROG_ARM64_MEM_OFFSET` and the presence contract
`KPROG_ARM64_MEM_INDEX_PRESENT` already consume:

  * the **source-modified index register value** source, an addressing mode
    that names an index register: the offset carries the register's value after
    the addressing mode's source modifier and shift;
  * the **zero** source, an addressing mode with no index register (the
    sentinel index operand): the offset carries no index contribution, so the
    value is a literal zero.

The generated table `GeneratedArm64MemIndexValue.sourceOf` and the
plain-expression C macro `KPROG_ARM64_MEM_INDEX_VALUE` expose that source
choice. The body previously picked the index value by hand through the
`has_index` ternary, and this module makes that 2-way source selection a
machine-checked fact. `KProgFormal/Arm64MemIndexValueShape.lean` proves the
generated `sourceOf` equal to an independent 2-way statement over the single
fact, and ties the register source to the 0102
`GeneratedArm64MemIndex.present` presence fact and the zero source to the
`GeneratedArm64MemOffset.value` offset the index value feeds. The fact is
closed, so the 2-way selection is total.

The generator is independent of the bodies it describes: it holds its own
literal source/case enumeration and re-derives the live memory-base-offset
region from the simulator header, then requires the body to go through the
generated source selector and to keep the hand ternary out.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_mem_index_value_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64MemIndexValue.lean"
CHEADER = ROOT / "generated/arm64_mem_index_value.h"

# The independent enumeration of the two index-value sources, in code order:
# (source, source define, code, value effect).
_SOURCES = [
    ("registerIndex",
     "KPROG_ARM64_MEM_INDEX_VALUE_REGISTER",
     0, "modified_index_register_value"),
    ("zero",
     "KPROG_ARM64_MEM_INDEX_VALUE_ZERO",
     1, "zero_index_value"),
]
# The independent enumeration of the two (has index) cases an addressing mode
# can have, in classification order:
# (case, has index, source).
_CASES = [
    ("has_index", True, "registerIndex"),
    ("no_index", False, "zero"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64MemIndexValue",
    "selector": "has_index_then_modified_register_else_zero",
    "sources": [{"source": s, "source_define": d, "source_code": c, "effect": e}
                for s, d, c, e in _SOURCES],
    "cases": [{"name": n, "has_index": h, "source": src}
              for n, h, src in _CASES],
}
SOURCE_COLUMNS = ("source", "source_define", "source_code", "effect")
CASE_COLUMNS = ("name", "has_index", "source")

# The live memory-address-offset region of the simulator header: the scalar
# `ARM64_SIM_L_MEM_BASE_OFF` body that computes the base offset, up to the
# pre/post-indexed writeback step that follows it. The offset body is the one
# place the index value contributes to the address at `has_index`.
MEM_REGION_START = "#define ARM64_SIM_L_MEM_BASE_OFF(AUX, INDEX, IMM)"
MEM_REGION_END = "#define ARM64_SIM_L_MEM_PREPOST_STEP(BASE, DELTA)"
MEM_SELECTOR = "KPROG_ARM64_MEM_INDEX_VALUE("
# The hand-written index-value ternary the routed body must no longer contain:
# the `has_index` fact deciding the index value directly. The body legitim-
# ately keeps the fact (as the selector's argument and the offset's HAS_INDEX
# input), so the ternary's `has_index ? MOD_VALUE` is the safe needle.
HAND_GATE = "__a64_mbo_has_index ? ARM64_SIM_L_MOD_VALUE((INDEX),"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(
            f"sim header no longer bounds the memory-base-offset region with "
            f"{start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """The memory-base-offset body must select its index value through the
    generated 2-way selector and must keep the register arm; the region must
    not pick the index value by hand through the `has_index` ternary."""
    if MEM_SELECTOR not in region:
        raise SystemExit(
            "arm64 memory-base-offset body does not route its index value "
            "through the generated source selector")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 memory-base-offset body picks its index value by hand "
            "through the `has_index` ternary instead of through the generated "
            "source selector")


def check_against_header():
    """The live memory-base-offset body must select its index value through
    the generated source selector."""
    check_region(region_between(MEM_REGION_START, MEM_REGION_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 memory index value keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 memory index value specification: {data!r}")
    for index, column in enumerate(SOURCE_COLUMNS):
        want = [row[column] for row in EXPECTED["sources"]]
        got = [entry[index] for entry in _SOURCES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 memory index value {column}: "
                f"{EXPECTED['sources']!r}")
    if len(EXPECTED["sources"]) != 2:
        raise SystemExit(
            "arm64 memory index value must select between exactly 2 sources")
    if [row["source_code"] for row in EXPECTED["sources"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 memory index value codes: "
            f"{EXPECTED['sources']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 memory index value case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["source"] for row in EXPECTED["cases"]] != [
            "registerIndex", "zero"]:
        raise SystemExit(
            f"invalid arm64 memory index value table: {EXPECTED['cases']!r}")
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
    return f'''-- Generated by generate_arm64_mem_index_value_spec.py from arm64_mem_index_value_spec.json.
import Std
namespace KProgFormal.GeneratedArm64MemIndexValue
/-- The two index-value sources a memory address offset selects between: the
source-modified index register value and a literal zero. -/
inductive Source where
{source_ctors}
deriving DecidableEq, Repr
/-- The number of index-value sources a memory address offset selects
between. -/
def sourceCount : Nat := {len(sources)}
/-- The two index-value sources, in code order. -/
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
/-- The index-value source a memory address offset selects: the source-modified
index register value exactly when the addressing mode carries an index
register, a literal zero otherwise. The fact is closed, so the selection is
total. -/
def sourceOf (hasIndex : Bool) : Source :=
  if hasIndex then .registerIndex
  else .zero
/-- The source a source code names, or `none` when the code names no source. -/
def sourceOfCode (code : Nat) : Option Source :=
  (sourceCodes.zip [{ctor}]).lookup code
/-- The two (has index) cases an addressing mode can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify an addressing mode by whether it carries an index register. -/
def classify (hasIndex : Bool) : Case :=
  match hasIndex with
  | true => .has_index
  | false => .no_index
/-- The index-value source a case performs, from the case table. -/
def sourceOfCase : Case -> Source
{source_of_case}
/-- The independent index-presence fact: the addressing mode carries an index
register, the closed fact. -/
def indexPresent (hasIndex : Bool) : Bool := hasIndex
/-- The index-presence fact is the identity for every addressing mode. -/
theorem indexPresent_refines (hasIndex : Bool) :
    indexPresent hasIndex = hasIndex := by
  rfl
/-- The source selector equals the case table for every addressing mode: naming
the source from the fact directly is the same as classifying and dispatching on
the case. -/
theorem sourceOf_refines (hasIndex : Bool) :
    sourceOf hasIndex = sourceOfCase (classify hasIndex) := by
  cases hasIndex <;> rfl
end KProgFormal.GeneratedArm64MemIndexValue
'''


def render_c(spec: dict) -> str:
    sources = spec["sources"]
    count = len(sources)
    reg = sources[0]["source_define"]
    zero = sources[1]["source_define"]
    source_defines = "\n".join(
        f'#define {row["source_define"]} {row["source_code"]}U'
        for row in sources)
    return f'''/* Generated by generate_arm64_mem_index_value_spec.py from arm64_mem_index_value_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MEM_INDEX_VALUE_H
#define KPROG_FORMAL_GENERATED_ARM64_MEM_INDEX_VALUE_H
/*
 * AArch64 memory index-value source contract: the memory address offset
 * (`ARM64_SIM_L_MEM_BASE_OFF`) adds the source-modified index register value
 * to the immediate exactly when the addressing mode carries an index register,
 * and its source is selected from the single closed fact: whether the
 * addressing mode carries an index register. The source-modified index
 * register value source (an addressing mode that names an index register) is
 * the index register's value after the addressing mode's source modifier and
 * shift; the zero source (the sentinel index operand) is a literal zero, so
 * the offset carries no index contribution. `KProgFormal/
 * Arm64MemIndexValueShape.lean` proves the generated `sourceOf` equal to an
 * independent 2-way statement and ties the register source to the 0102
 * presence fact (`GeneratedArm64MemIndex.present`) and the zero source to the
 * offset the value feeds (`GeneratedArm64MemOffset.value`). The fact is
 * closed, so the 2-way selection is total. This header uses only literal
 * inputs, so it is included before the `ARM64_SIM_L_MEM_BASE_OFF` body.
 */
/* The number of index-value sources the offset selects between. */
#define KPROG_ARM64_MEM_INDEX_VALUE_COUNT {count}U
{source_defines}
/*
 * The index-value source a memory address offset selects: the source-modified
 * index register value exactly when the addressing mode carries an index
 * register, a literal zero otherwise. The input is evaluated once and no NZCV
 * is written.
 */
#define KPROG_ARM64_MEM_INDEX_VALUE(HAS_INDEX)                  \\
	((__u8)(((HAS_INDEX)) ? {reg} : {zero}))
_Static_assert(KPROG_ARM64_MEM_INDEX_VALUE_COUNT == {count}U,
	       "arm64 mem index value count drift");
_Static_assert({reg} != {zero},
	       "arm64 mem index value codes must be distinct");
_Static_assert({reg} == 0U && {zero} == 1U,
	       "arm64 mem index value code drift");
/* The selector must name each source at its own fact. */
_Static_assert(KPROG_ARM64_MEM_INDEX_VALUE(1) == {reg},
	       "arm64 mem index value register selection drift");
_Static_assert(KPROG_ARM64_MEM_INDEX_VALUE(0) == {zero},
	       "arm64 mem index value zero selection drift");
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
                    f"generated arm64 memory index value contract is "
                    f"stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
