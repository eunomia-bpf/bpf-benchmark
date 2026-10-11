#!/usr/bin/env python3
"""Generate the shared x86-64 `MULX` width-keyed arm-selection contract.

The hand-written `X86_SIM_L_EXEC_MULX` macro in
`kprog/x86/x86_sim_local_bpf.h` selects between two bodies on the *resolved*
operand width (`__x86_l_width`, already the effective width):

  * at the 32-bit width it multiplies the two zero-extended low words into one
    64-bit product and splits that product into the low and high halves of the
    destination / auxiliary destination;
  * at every other width it takes the four-limb radix-`2^32` ladder for the
    high half and the plain 64-bit product for the low half.

The width is *already* routed through `X86_SIM_L_EFFECTIVE_WIDTH` (the
generated `KPROG_X86_WIDTH_EFFECTIVE` contract), and the second-destination
guard through `KPROG_X86_REG_PRESENT`; the arm test itself was the remaining
inline `if (__x86_l_width == X86_WIDTH_32)`.

The two arms produce the *same* value only below the operand width: the 32-bit
arm's low word equals the 64-bit low half truncated, but the high halves come
from different decompositions (a single 32x32 product split in two versus the
carry-propagated limb ladder), and at every wider width the ladder arm is the
only correct one. The generated table `GeneratedX86MulxArm.armOf` and the C
macro `KPROG_X86_MULX_ARM` name that arm for a resolved width code.

The generator is independent of the arm it describes: it holds its own literal
enumeration and re-derives the live `X86_SIM_L_EXEC_MULX` macro text from the
simulator header, then requires the routed macro to go through the generated
selector.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_MULX` / `X86_WIDTH_*` decodes, exactly as the opcode mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_mulx_arm_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86MulxArm.lean"
CHEADER = ROOT / "generated/x86_mulx_arm.h"

# The independent enumeration of the two arms, in selection order:
# (arm, arm define, is_special_width, effect, width_class).
_ARMS = [
    ("singleProduct", "KPROG_X86_MULX_ARM_SINGLE_PRODUCT", 1,
     "single_product_split", "w32"),
    ("limbLadder", "KPROG_X86_MULX_ARM_LIMB_LADDER", 0,
     "four_limb_ladder", "other"),
]
WIDTH_CODE_BITS = 8
OPCODE = 57
OPCODE_DEFINE = "X86_OP_MULX"
SPECIAL_WIDTH = 4
EXPECTED = {
    "schema_version": 1,
    "operation": "x86MulxArmSelector",
    "selector": "single_width_code_then_arm",
    "width_code_bits": WIDTH_CODE_BITS,
    "opcode_define": OPCODE_DEFINE,
    "opcode": OPCODE,
    "special_width_define": "KPROG_X86_MULX_SPECIAL_WIDTH",
    "special_width_code": SPECIAL_WIDTH,
    "arms": [{"arm": arm, "arm_define": define, "is_special_width": is_special,
              "effect": effect, "width_class": width_class}
             for arm, define, is_special, effect, width_class in _ARMS],
}

# The live routed macro, between its opener and the `REP_MOVS_ONE` macro.
ARM_START = "#define X86_SIM_L_EXEC_MULX(DST, SRC, AUX, FLAGS)"
ARM_END = "#define X86_SIM_L_REP_MOVS_ONE(WIDTH, INDEX)"
ARM_SELECTOR = ("KPROG_X86_MULX_ARM(__x86_l_width) == "
                "KPROG_X86_MULX_ARM_SINGLE_PRODUCT")
ARM_SINGLE_PRODUCT = "(__u64)(__u32)__x86_l_lhs *"
ARM_LADDER = "__x86_l_p3"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live MULX macro must route through the generated width selector."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 mulx arm does not route through the generated selector")
    if ARM_SINGLE_PRODUCT not in region:
        raise SystemExit(
            "x86 mulx single-product arm does not split a 32x32 product")
    if ARM_LADDER not in region:
        raise SystemExit("x86 mulx limb-ladder arm is gone")
    if re.search(r"__x86_l_width\s*==\s*X86_WIDTH_32", region):
        raise SystemExit(
            "x86 mulx arm restates the raw 32-bit width test inline")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 mulx arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 mulx arm specification: {data!r}")
    arms = EXPECTED["arms"]
    if [row["arm"] for row in arms] != [a for a, _d, _f, _e, _c in _ARMS]:
        raise SystemExit(f"invalid x86 mulx arm names: {arms!r}")
    if [row["arm_define"] for row in arms] != [d for _a, d, _f, _e, _c
                                               in _ARMS]:
        raise SystemExit(f"invalid x86 mulx arm defines: {arms!r}")
    if [row["is_special_width"] for row in arms] != [f for _a, _d, f, _e, _c
                                                     in _ARMS]:
        raise SystemExit(f"invalid x86 mulx special-width flags: {arms!r}")
    if [row["effect"] for row in arms] != [e for _a, _d, _f, e, _c in _ARMS]:
        raise SystemExit(f"invalid x86 mulx arm effects: {arms!r}")
    if [row["width_class"] for row in arms] != [c for _a, _d, _f, _e, c
                                                in _ARMS]:
        raise SystemExit(f"invalid x86 mulx width classes: {arms!r}")
    if len([row for row in arms if row["is_special_width"]]) != 1:
        raise SystemExit("x86 mulx must name exactly one special-width arm")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["width_code_bits"]
    opcode = spec["opcode"]
    special = spec["special_width_code"]
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
    return f'''-- Generated by generate_x86_mulx_arm_spec.py from x86_mulx_arm_spec.json.
import Std
namespace KProgFormal.GeneratedX86MulxArm
/-- The two bodies the `X86_SIM_L_EXEC_MULX` macro selects between on the
resolved operand width. -/
inductive Arm where
  | singleProduct
  | limbLadder
deriving DecidableEq, Repr
/-- The number of bodies the `MULX` macro selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the resolved width code the arm selects on. -/
def widthCodeBits : Nat := {bits}
/-- The `X86_OP_MULX` opcode the arm implements. -/
def opcode : Nat := {opcode}
/-- The 32-bit width code the single-product arm is selected at. -/
def specialWidthCode : Nat := {special}
/-- The body each resolved width code selects, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The effect each body performs on the two product halves. -/
def effectOfArm : Arm -> String
{effects}
/-- The width class each body operates in. -/
def widthClassOfArm : Arm -> String
{width_class}
/-- Whether a resolved width code is the special 32-bit width. -/
def isSpecialWidth (width : Nat) : Bool := width == specialWidthCode
/-- The body a resolved width code selects: the single-product arm at the
32-bit width code, the four-limb ladder arm at every other code. -/
def armOf (width : Nat) : Arm :=
  if width = specialWidthCode then .singleProduct else .limbLadder
/-- The body an arm code names, or `none` when the code names no arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86MulxArm
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    opcode = spec["opcode"]
    special = spec["special_width_code"]
    single = arms[0]["arm_define"]
    ladder = arms[1]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    width_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_MULX_ARM(X86_WIDTH_{w}) == {want}, '
        f'"x86 mulx width arm drift");'
        for w, want in (("32", single), ("8", ladder), ("16", ladder),
                        ("64", ladder)))
    return f'''/* Generated by generate_x86_mulx_arm_spec.py from x86_mulx_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_MULX_ARM_H
#define KPROG_FORMAL_GENERATED_X86_MULX_ARM_H
/*
 * x86-64 `MULX` width-keyed arm-selection contract: the `X86_SIM_L_EXEC_MULX`
 * macro selects between two bodies on the resolved operand width. At the
 * {special} (32-bit) width code it multiplies the two zero-extended low words
 * into one 64-bit product and splits it; at every other code it takes the
 * four-limb radix-`2^32` ladder for the high half and the plain 64-bit
 * product for the low half. The two arms agree on the low word only; the
 * carry-propagated ladder is the correct high half at every wider width,
 * which is exactly what the selector distinguishes.
 * `KProgFormal/X86MulxArmHandler.lean` proves the generated `armOf` equals an
 * independent construction and that the single-product arm is exactly the
 * 32-bit split of the zero-extended low-word product.
 * This header is included after the `X86_OP_MULX` / `X86_WIDTH_*` decodes, so
 * the drift checks bind the hand-written constants to the generated table.
 */
/* The width codes, including the 0 "absent" code. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
/* The resolved width code the single-product arm is selected at. */
#define KPROG_X86_MULX_SPECIAL_WIDTH {special}U
/* The number of bodies the arm selects between. */
#define KPROG_X86_MULX_ARM_COUNT {count}U
{arm_defines}
/*
 * The body a resolved width code selects: the single-product arm at the
 * 32-bit code, the four-limb ladder arm at every other code. The input is
 * evaluated once.
 */
#define KPROG_X86_MULX_ARM(WIDTH)                                           \\
\t(((__u8)((WIDTH))) == KPROG_X86_MULX_SPECIAL_WIDTH                  \\
\t\t ? {single} : {ladder})
_Static_assert({spec["opcode_define"]} == {opcode}U,
\t       "x86 mulx opcode drift");
_Static_assert(X86_WIDTH_32 == KPROG_X86_MULX_SPECIAL_WIDTH,
\t       "x86 mulx special-width code drift");
_Static_assert(KPROG_X86_MULX_ARM_COUNT == {count}U,
\t       "x86 mulx arm count drift");
_Static_assert({single} != {ladder},
\t       "x86 mulx arm codes must be distinct");
/* The width code selector must name the single-product arm only at 32 bits. */
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
                    f"generated x86 mulx arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
