#!/usr/bin/env python3
"""Generate the AArch64 memory base-address source contract.

The hand-written AArch64 memory helpers of
`kprog/arm64/arm64_sim_local_bpf.h` -- `ARM64_SIM_L_MEM_READ`,
`ARM64_SIM_L_MEM_READ_TAG` and `ARM64_SIM_L_MEM_WRITE` -- each compute the
base address of a stack-arena access inside their stack arm:

    __s64 base = (BASE) == ARM64_SP ? __a64_sp
                                    : (__s64)(long)ARM64_SIM_L_READ_REG_PTR(BASE);

The base address is selected from a *single closed fact* -- whether the base
register is the stack pointer:

  * the **stack pointer register** source, a `BASE` that is `ARM64_SP`: the
    base address is the simulator's stack pointer `__a64_sp` itself;
  * the **general-purpose register arena base** source, every other `BASE`:
    the base address is the base register's raw pointer value, which the
    simulator indexes the arena with.

The generated table `GeneratedArm64MemBaseSrc.sourceOf` and the
plain-expression C macro `KPROG_ARM64_MEM_BASE_SRC` expose that source choice.
The three helpers previously picked the base address by hand through the
`BASE == ARM64_SP` ternary, and this module makes that 2-way source selection a
machine-checked fact. `KProgFormal/Arm64MemBaseSrcShape.lean` proves the
generated `sourceOf` equal to an independent 2-way statement over the single
fact, and ties the stack-pointer source to the 0123
`KPROG_ARM64_MEM_WRITE_ARM` store body selection and the
`KPROG_ARM64_MEM_READ_SRC` load dispatch stack split. The fact is closed, so
the 2-way selection is total.

The generator is independent of the bodies it describes: it holds its own
literal source/case enumeration and re-derives the live memory-helper region
from the simulator header, then requires every memory body to go through the
generated source selector and to keep the hand ternary out.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_mem_base_src_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64MemBaseSrc.lean"
CHEADER = ROOT / "generated/arm64_mem_base_src.h"

# The independent enumeration of the two base-address sources, in code order:
# (source, source define, code, value effect).
_SOURCES = [
    ("spRegister",
     "KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER",
     0, "stack_pointer_register"),
    ("gprBase",
     "KPROG_ARM64_MEM_BASE_SRC_GPR_BASE",
     1, "gpr_arena_base"),
]
# The independent enumeration of the two (base is SP) cases a memory helper's
# base register can have, in classification order:
# (case, base is SP, source).
_CASES = [
    ("base_is_sp", True, "spRegister"),
    ("base_is_gpr", False, "gprBase"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64MemBaseSrc",
    "selector": "base_is_sp_then_sp_register_else_gpr_base",
    "sources": [{"source": s, "source_define": d, "source_code": c, "effect": e}
                for s, d, c, e in _SOURCES],
    "cases": [{"name": n, "base_is_sp": b, "source": src}
              for n, b, src in _CASES],
}
SOURCE_COLUMNS = ("source", "source_define", "source_code", "effect")
CASE_COLUMNS = ("name", "base_is_sp", "source")

# The live memory-helper region of the simulator header, from the scalar load
# helper `ARM64_SIM_L_MEM_READ` to the vector `.D0`/`.Q0` memory step that
# follows the store helper. All three bodies that compute a stack base address
# (`MEM_READ`, `MEM_READ_TAG`, `MEM_WRITE`) lie inside it.
MEM_REGION_START = "#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH)"
MEM_REGION_END = "#define ARM64_SIM_L_DQ_MEM_STEP("
MEM_SELECTOR = "KPROG_ARM64_MEM_BASE_SRC("
# The hand-written base ternary the routed bodies must no longer contain: the
# `BASE == ARM64_SP` test deciding the base address. The bodies legitimately
# keep the `== ARM64_SP` test inside the selector's argument (`BASE_IS_SP`), so
# the ternary's `? __a64_sp` is the safe needle.
HAND_GATE = "== ARM64_SP ? __a64_sp"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.find(start_marker)
    end = text.find(end_marker, start + 1)
    if start < 0 or end < 0:
        raise SystemExit(
            f"sim header no longer bounds the memory-helper region with "
            f"{start_marker!r} .. {end_marker!r}")
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """Every routed memory body must select its base-address source through
    the generated 2-way selector and must keep the stack-pointer arm; the
    region must not pick the base address by hand through the base ternary."""
    if MEM_SELECTOR not in region:
        raise SystemExit(
            "arm64 memory helpers do not route their base-address source "
            "through the generated source selector")
    if HAND_GATE in region:
        raise SystemExit(
            "arm64 memory helpers pick their base address by hand through "
            "the stack-pointer ternary instead of through the generated "
            "source selector")


def check_against_header():
    """The live memory helpers must select their base-address source through
    the generated source selector."""
    check_region(region_between(MEM_REGION_START, MEM_REGION_END))


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(
            f"invalid arm64 memory base source keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 memory base source specification: {data!r}")
    for index, column in enumerate(SOURCE_COLUMNS):
        want = [row[column] for row in EXPECTED["sources"]]
        got = [entry[index] for entry in _SOURCES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 memory base source {column}: "
                f"{EXPECTED['sources']!r}")
    if len(EXPECTED["sources"]) != 2:
        raise SystemExit(
            "arm64 memory base source must select between exactly 2 "
            "sources")
    if [row["source_code"] for row in EXPECTED["sources"]] != [0, 1]:
        raise SystemExit(
            f"invalid arm64 memory base source codes: "
            f"{EXPECTED['sources']!r}")
    for index, column in enumerate(CASE_COLUMNS):
        want = [row[column] for row in EXPECTED["cases"]]
        got = [entry[index] for entry in _CASES]
        if want != got:
            raise SystemExit(
                f"invalid arm64 memory base source case {column}: "
                f"{EXPECTED['cases']!r}")
    if [row["source"] for row in EXPECTED["cases"]] != [
            "spRegister", "gprBase"]:
        raise SystemExit(
            f"invalid arm64 memory base source table: "
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
    return f'''-- Generated by generate_arm64_mem_base_src_spec.py from arm64_mem_base_src_spec.json.
import Std
namespace KProgFormal.GeneratedArm64MemBaseSrc
/-- The two base-address sources an AArch64 memory helper selects between: the
stack pointer register and the base register's own arena pointer. -/
inductive Source where
{source_ctors}
deriving DecidableEq, Repr
/-- The number of base-address sources a memory helper selects between. -/
def sourceCount : Nat := {len(sources)}
/-- The two base-address sources, in code order. -/
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
/-- The base-address source a memory helper selects: the stack pointer
register source exactly when the base register is the stack pointer, the base
register's own arena pointer otherwise. The fact is closed, so the selection
is total. -/
def sourceOf (baseIsSp : Bool) : Source :=
  if baseIsSp then .spRegister
  else .gprBase
/-- The source a source code names, or `none` when the code names no source. -/
def sourceOfCode (code : Nat) : Option Source :=
  (sourceCodes.zip [{ctor}]).lookup code
/-- The two (base is SP) cases a memory helper's base register can have. -/
inductive Case where
{case_ctors}
deriving DecidableEq, Repr
/-- Classify a memory helper by whether its base register is the stack
pointer. -/
def classify (baseIsSp : Bool) : Case :=
  match baseIsSp with
  | true => .base_is_sp
  | false => .base_is_gpr
/-- The base-address source a case performs, from the case table. -/
def sourceOfCase : Case -> Source
{source_of_case}
/-- The independent stack-pointer fact: the base register is the stack
pointer, the closed fact. -/
def spBase (baseIsSp : Bool) : Bool := baseIsSp
/-- The stack-pointer fact is the identity for every base register. -/
theorem spBase_refines (baseIsSp : Bool) :
    spBase baseIsSp = baseIsSp := by
  rfl
/-- The source selector equals the case table for every memory helper: naming
the source from the fact directly is the same as classifying and dispatching
on the case. -/
theorem sourceOf_refines (baseIsSp : Bool) :
    sourceOf baseIsSp = sourceOfCase (classify baseIsSp) := by
  cases baseIsSp <;> rfl
end KProgFormal.GeneratedArm64MemBaseSrc
'''


def render_c(spec: dict) -> str:
    sources = spec["sources"]
    count = len(sources)
    sp = sources[0]["source_define"]
    gpr = sources[1]["source_define"]
    source_defines = "\n".join(
        f'#define {row["source_define"]} {row["source_code"]}U'
        for row in sources)
    return f'''/* Generated by generate_arm64_mem_base_src_spec.py from arm64_mem_base_src_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MEM_BASE_SRC_H
#define KPROG_FORMAL_GENERATED_ARM64_MEM_BASE_SRC_H
/*
 * AArch64 memory base-address source contract: the scalar memory helpers
 * `ARM64_SIM_L_MEM_READ`, `ARM64_SIM_L_MEM_READ_TAG` and
 * `ARM64_SIM_L_MEM_WRITE` each compute the base address of a stack-arena
 * access, and its source is selected from the single closed fact: whether the
 * base register is the stack pointer. The stack pointer register source (a
 * base of `ARM64_SP`) is the simulator's stack pointer `__a64_sp` itself; the
 * general-purpose register arena base source (every other base) is the base
 * register's raw pointer value, the value the simulator indexes the arena
 * with. `KProgFormal/Arm64MemBaseSrcShape.lean` proves the generated
 * `sourceOf` equal to an independent 2-way statement and ties the
 * stack-pointer source to the 0123 store body selection
 * (`KPROG_ARM64_MEM_WRITE_ARM`) and the load dispatch stack split
 * (`KPROG_ARM64_MEM_READ_SRC`). The fact is closed, so the 2-way selection is
 * total. This header uses only literal inputs, so it is included before the
 * `ARM64_SIM_TAG_*` tag names in the simulator header.
 */
/* The number of base-address sources the helper selects between. */
#define KPROG_ARM64_MEM_BASE_SRC_COUNT {count}U
{source_defines}
/*
 * The base-address source a memory helper selects: the stack pointer register
 * source exactly when the base register is the stack pointer, the base
 * register's own arena pointer otherwise. The input is evaluated once and no
 * NZCV is written.
 */
#define KPROG_ARM64_MEM_BASE_SRC(BASE_IS_SP)                  \\
	((__u8)(((BASE_IS_SP)) ? {sp} : {gpr}))
_Static_assert(KPROG_ARM64_MEM_BASE_SRC_COUNT == {count}U,
	       "arm64 mem base src count drift");
_Static_assert({sp} != {gpr},
	       "arm64 mem base src codes must be distinct");
_Static_assert({sp} == 0U && {gpr} == 1U,
	       "arm64 mem base src code drift");
/* The selector must name each source at its own fact. */
_Static_assert(KPROG_ARM64_MEM_BASE_SRC(1) == {sp},
	       "arm64 mem base src stack pointer selection drift");
_Static_assert(KPROG_ARM64_MEM_BASE_SRC(0) == {gpr},
	       "arm64 mem base src gpr base selection drift");
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
                    f"generated arm64 memory base source contract is "
                    f"stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
