#!/usr/bin/env python3
"""Generate the shared x86-64 `XCHG` width-keyed arm-selection contract.

The hand-written `X86_OP_XCHG` arm of `X86_SIM_L_EXEC` in
`kprog/x86/x86_sim_local_bpf.h` selects between two bodies on the *resolved*
operand width (`__x86_l_width`, already the effective width):

  * at the full 64-bit width it swaps the two destination/source register
    cells as *raw pointer cells*, reading each cell with the tag-preserving
    `X86_SIM_L_READ_REG_PTR` and writing each with the scalarizing
    `X86_SIM_L_WRITE_REG_PTR`; the swap moves the whole 64-bit cell and
    scalarizes both tags;
  * at every narrower width it reads the two cells as 64-bit values
    (`X86_SIM_L_READ_REG`) and writes each with `X86_SIM_L_WRITE_REG_WIDTH`, so
    the write is the partial-register writeback (8/16-bit preserve the old
    upper bits, 32-bit zero-extends, 64-bit replaces) and both tags scalarize.

The full-width arm is not a different *value* swap from the narrow arm at 64
bits -- both write a full 64-bit swap of the two cells -- it is a different
*implementation* (pointer-cell move versus width-masked value write), and the
selector distinguishes exactly the full 64-bit width code from every other
code. The generated table `GeneratedX86Xchg.armOf` and the C macro
`KPROG_X86_XCHG_ARM` name that arm for a resolved width code.

The generator is independent of the arm it describes: it holds its own literal
enumeration and re-derives the live `X86_OP_XCHG` arm text from the simulator
header, then requires the routed arm to go through the generated selector.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_XCHG` / `X86_WIDTH_*` decodes, exactly as the opcode mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_xchg_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86Xchg.lean"
CHEADER = ROOT / "generated/x86_xchg.h"

# The independent enumeration of the two arms, in selection order:
# (arm, arm define, is_full_width, effect, width_class).
_ARMS = [
    ("pointerSwap", "KPROG_X86_XCHG_ARM_POINTER_SWAP", 1, "pointer_swap",
     "full"),
    ("subwordSwap", "KPROG_X86_XCHG_ARM_SUBWORD_SWAP", 0, "width_value_swap",
     "narrow"),
]
WIDTH_CODE_BITS = 8
OPCODE = 25
OPCODE_DEFINE = "X86_OP_XCHG"
FULL_WIDTH = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86XchgSelector",
    "selector": "full_width_code_then_arm",
    "width_code_bits": WIDTH_CODE_BITS,
    "opcode_define": OPCODE_DEFINE,
    "opcode": OPCODE,
    "full_width_define": "KPROG_X86_XCHG_FULL_WIDTH",
    "full_width_code": FULL_WIDTH,
    "arms": [{"arm": arm, "arm_define": define, "is_full_width": is_full,
              "effect": effect, "width_class": width_class}
             for arm, define, is_full, effect, width_class in _ARMS],
}
COLUMNS = ("arm", "arm_define", "is_full_width", "effect", "width_class")

# The live routed arm text, between the `XCHG` arm opener and the `DIV` arm.
ARM_START = "} else if ((OP) == X86_OP_XCHG) {"
ARM_END = "} else if ((OP) == X86_OP_DIV) {"
ARM_SELECTOR = "KPROG_X86_XCHG_ARM(__x86_l_width) == KPROG_X86_XCHG_ARM_POINTER_SWAP"
ARM_POINTER_READ = "X86_SIM_L_READ_REG_PTR"
ARM_SUBWORD_WRITE = "X86_SIM_L_WRITE_REG_WIDTH"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live XCHG arm must route through the generated full-width selector."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 xchg arm does not route through the generated selector")
    if ARM_POINTER_READ not in region:
        raise SystemExit(
            "x86 xchg pointer arm does not read the raw pointer cells")
    if ARM_SUBWORD_WRITE not in region:
        raise SystemExit("x86 xchg subword arm has no width write")
    if "X86_SIM_L_WRITE_REG_PTR" not in region:
        raise SystemExit("x86 xchg pointer arm does not write pointer cells")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 xchg keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 xchg specification: {data!r}")
    arms = EXPECTED["arms"]
    if [row["arm"] for row in arms] != [a for a, _d, _f, _e, _c in _ARMS]:
        raise SystemExit(f"invalid x86 xchg arm names: {arms!r}")
    if [row["arm_define"] for row in arms] != [d for _a, d, _f, _e, _c
                                               in _ARMS]:
        raise SystemExit(f"invalid x86 xchg arm defines: {arms!r}")
    if [row["is_full_width"] for row in arms] != [f for _a, _d, f, _e, _c
                                                  in _ARMS]:
        raise SystemExit(f"invalid x86 xchg full-width flags: {arms!r}")
    if [row["effect"] for row in arms] != [e for _a, _d, _f, e, _c in _ARMS]:
        raise SystemExit(f"invalid x86 xchg arm effects: {arms!r}")
    if [row["width_class"] for row in arms] != [c for _a, _d, _f, _e, c
                                                in _ARMS]:
        raise SystemExit(f"invalid x86 xchg width classes: {arms!r}")
    if len([row for row in arms if row["is_full_width"]]) != 1:
        raise SystemExit("x86 xchg must name exactly one full-width arm")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["width_code_bits"]
    opcode = spec["opcode"]
    full = spec["full_width_code"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}'
        for index, row in enumerate(arms))
    effects = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    width_class = "\n".join(
        f'  | .{row["arm"]} => "{row["width_class"]}"' for row in arms)
    return f'''-- Generated by generate_x86_xchg_spec.py from x86_xchg_spec.json.
import Std
namespace KProgFormal.GeneratedX86Xchg
/-- The two bodies the `X86_OP_XCHG` arm selects between on the resolved
operand width. -/
inductive Arm where
  | pointerSwap
  | subwordSwap
deriving DecidableEq, Repr
/-- The number of bodies the `X86_OP_XCHG` arm selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the resolved width code the arm selects on. -/
def widthCodeBits : Nat := {bits}
/-- The `X86_OP_XCHG` opcode the arm implements. -/
def opcode : Nat := {opcode}
/-- The full 64-bit width code the pointer-swap arm is selected at. -/
def fullWidthCode : Nat := {full}
/-- The body each resolved width code selects, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The effect each body performs on the two register cells. -/
def effectOfArm : Arm -> String
{effects}
/-- The width class each body operates in. -/
def widthClassOfArm : Arm -> String
{width_class}
/-- Whether a resolved width code is the full 64-bit width. -/
def isFullWidth (width : Nat) : Bool := width == fullWidthCode
/-- The body a resolved width code selects: the pointer-swap arm at the full
64-bit width code, the subword-value-swap arm at every other code. -/
def armOf (width : Nat) : Arm :=
  if width = fullWidthCode then .pointerSwap else .subwordSwap
/-- The body an arm code names, or `none` when the code names no arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86Xchg
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    opcode = spec["opcode"]
    full = spec["full_width_code"]
    pointer = arms[0]["arm_define"]
    subword = arms[1]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    width_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_XCHG_ARM(X86_WIDTH_{w}) == {want}, '
        f'"x86 xchg width arm drift");'
        for w, want in (("64", pointer), ("32", subword), ("16", subword),
                        ("8", subword)))
    return f'''/* Generated by generate_x86_xchg_spec.py from x86_xchg_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_XCHG_H
#define KPROG_FORMAL_GENERATED_X86_XCHG_H
/*
 * x86-64 `XCHG` width-keyed arm-selection contract: the `X86_OP_XCHG` arm of
 * `X86_SIM_L_EXEC` selects between two bodies on the resolved operand width.
 * At the full {full} (64-bit) width code it swaps the two register cells as
 * raw pointer cells (`X86_SIM_L_READ_REG_PTR` / `X86_SIM_L_WRITE_REG_PTR`),
 * moving the whole 64-bit cell and scalarizing both tags; at every other code
 * it reads both cells as 64-bit values and writes each with
 * `X86_SIM_L_WRITE_REG_WIDTH`, the partial-register writeback (8/16-bit
 * preserve the old upper bits, 32-bit zero-extends, 64-bit replaces). The two
 * arms write the same 64-bit value swap at the full width; they differ only
 * below it, which is exactly what the selector distinguishes.
 * `KProgFormal/X86XchgHandler.lean` proves the generated `armOf` equals an
 * independent construction, that the pointer arm swaps the whole cells while
 * scalarizing, and that the subword arm's width-window writeback exchanges the
 * two values at the access width.
 * This header is included after the `X86_OP_XCHG` / `X86_WIDTH_*` decodes, so
 * the drift checks bind the hand-written constants to the generated table.
 */
/* The width codes, including the 0 "absent" code. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
/* The resolved width code the pointer-swap arm is selected at. */
#define KPROG_X86_XCHG_FULL_WIDTH {full}U
/* The number of bodies the arm selects between. */
#define KPROG_X86_XCHG_ARM_COUNT {count}U
{arm_defines}
/*
 * The body a resolved width code selects: the pointer-swap arm at the full
 * 64-bit code, the subword-value-swap arm at every other code. The input is
 * evaluated once.
 */
#define KPROG_X86_XCHG_ARM(WIDTH)                                           \\
\t(((__u8)((WIDTH))) == KPROG_X86_XCHG_FULL_WIDTH                     \\
\t\t ? {pointer} : {subword})
_Static_assert({spec["opcode_define"]} == {opcode}U,
\t       "x86 xchg opcode drift");
_Static_assert(X86_WIDTH_64 == KPROG_X86_XCHG_FULL_WIDTH,
\t       "x86 xchg full-width code drift");
_Static_assert(KPROG_X86_XCHG_ARM_COUNT == {count}U,
\t       "x86 xchg arm count drift");
_Static_assert({pointer} != {subword},
\t       "x86 xchg arm codes must be distinct");
/* The width code selector must name the pointer arm only at the full width. */
{width_asserts}
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
                    f"generated x86 xchg contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
