#!/usr/bin/env python3
"""Generate the shared x86-64 `MOV_REG` three-way arm-selection contract.

The hand-written `X86_OP_MOV_REG` arm of `X86_SIM_L_EXEC` in
`kprog/x86/x86_sim_local_bpf.h` (and the shared `X86_SIM_L_EXEC_MOV_REG_AUX`
body it mirrors) selects between three bodies from two facts about the operands:

  * whether the *resolved* operand width (`__x86_l_width`, already the effective
    width) is 64 bits — the pointer family — or narrower — the value arm;
  * whether the encoded source register *is* the stack pointer (register
    identity).

The arms are:

  * `STACK_PTR`: at width 64 with the stack pointer as source, the destination
    receives the abstract frame base plus the source cell value
    (`X86_SIM_L_STACK_PTR`) and is tagged stack provenance;
  * `POINTER`: at width 64 with any other source, the destination receives the
    source cell whole (`X86_SIM_L_READ_REG_PTR`) with the source cell's own
    provenance tag;
  * `NARROW`: at every narrower width, the source is observed through its
    decoded byte lane (`X86_SIM_L_READ_REG_WIDTH_SHIFT`) and written through the
    destination lane (`X86_SIM_L_WRITE_REG_WIDTH_SHIFT`), scalarizing
    provenance.

The stack-pointer test is *nested inside* the width test, so a narrow `mov`
ignores register identity entirely: the three-way selection collapses to the
value arm at every sub-64 width, whatever the source register. This is what
`X86MovHandler.lean` proves as `x86_mov_reg_narrow_ignores_rsp`. The two
64-bit arms differ only in the tag and the stack-base resolution, which is
`x86_mov_reg_rsp_uses_stack_base` versus `x86_mov_reg_copies_provenance`.

The generated table `GeneratedX86MovRegArm.armOf` and the plain-expression C
macro `KPROG_X86_MOV_REG_ARM` name that arm for a resolved width and a source
register. The selector is written as a plain nested ternary (not a GCC
statement expression) precisely so the generated header can also carry
compile-time `_Static_assert` drift checks, unlike the `x86_mem_dispatch.h`
selector.

The generator is independent of the arm it describes: it holds its own literal
enumeration and re-derives the live MOV_REG arm text from the simulator header,
then requires *both* routed bodies to go through the generated selector.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_MOV_REG` / `X86_WIDTH_*` / `X86_RSP` decodes, exactly as the opcode
mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_mov_reg_arm_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86MovRegArm.lean"
CHEADER = ROOT / "generated/x86_mov_reg_arm.h"

# The independent enumeration of the three arms, in selection order:
# (arm, arm define, effect, width_class).
_ARMS = [
    ("stackPtr", "KPROG_X86_MOV_REG_ARM_STACK_PTR", "stack_base_pointer_write",
     "full"),
    ("pointer", "KPROG_X86_MOV_REG_ARM_POINTER", "provenance_pointer_write",
     "full"),
    ("narrow", "KPROG_X86_MOV_REG_ARM_NARROW", "width_scalarizing_write",
     "narrow"),
]
OPCODE = 2
OPCODE_DEFINE = "X86_OP_MOV_REG"
FULL_WIDTH = 8
RSP = 4
EXPECTED = {
    "schema_version": 1,
    "operation": "x86MovRegArmSelector",
    "selector": "width64_and_rsp_then_arm",
    "opcode_define": OPCODE_DEFINE,
    "opcode": OPCODE,
    "full_width_define": "KPROG_X86_MOV_REG_FULL_WIDTH",
    "full_width_code": FULL_WIDTH,
    "rsp_define": "X86_RSP",
    "rsp_code": RSP,
    "arms": [{"arm": arm, "arm_define": define, "effect": effect,
              "width_class": width_class}
             for arm, define, effect, width_class in _ARMS],
}
COLUMNS = ("arm", "arm_define", "effect", "width_class")

# The live routed arm text, between the MOV_REG arm opener and the MOVX arm.
ARM_START = "} else if ((OP) == X86_OP_MOV_REG) {"
ARM_END = "} else if ((OP) == X86_OP_MOVZX_REG ||"
# The standalone shared body, between its `#define` and the next `#define`.
MACRO_START = "#define X86_SIM_L_EXEC_MOV_REG_AUX(DST, SRC, FLAGS, AUX)"
MACRO_END = "#define X86_SIM_L_EXEC_MOV_REG(DST, SRC, FLAGS)"
ARM_SELECTOR = "KPROG_X86_MOV_REG_ARM(__x86_l_width, (SRC))"
ARM_STACK_TEST = "KPROG_X86_MOV_REG_ARM_STACK_PTR"
ARM_POINTER_TEST = "KPROG_X86_MOV_REG_ARM_POINTER"
ARM_NARROW_TEST = "KPROG_X86_MOV_REG_ARM_NARROW"
ARM_STACK_BODY = "X86_SIM_L_STACK_PTR("
ARM_POINTER_READ = "X86_SIM_L_READ_REG_PTR(SRC)"
ARM_POINTER_TAG = "X86_SIM_L_REG_TAG(SRC)"
ARM_NARROW_READ = "X86_SIM_L_READ_REG_WIDTH_SHIFT("
ARM_NARROW_WRITE = "X86_SIM_L_WRITE_REG_WIDTH_SHIFT("
# The hand-written ladder the routed body must no longer contain.
HAND_WIDTH_TEST = "X86_WIDTH_64"
HAND_RSP_TEST = "== X86_RSP"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def arm_region():
    return region_between(ARM_START, ARM_END)


def macro_region():
    return region_between(MACRO_START, MACRO_END)


def check_region(region, exactly_one_arm):
    """A routed MOV_REG body must select its arm through the generated
    two-fact selector, name all three arms, and still compute the stack-base,
    pointer, and narrow writebacks; it must not select by hand."""
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 mov_reg arm body does not route through the generated selector")
    for name, test in (("stack_ptr", ARM_STACK_TEST),
                       ("pointer", ARM_POINTER_TEST),
                       ("narrow", ARM_NARROW_TEST)):
        if test not in region:
            raise SystemExit(f"x86 mov_reg arm body does not name the {name} arm")
    if ARM_STACK_BODY not in region:
        raise SystemExit(
            "x86 mov_reg arm body does not resolve the stack base")
    if ARM_POINTER_READ not in region or ARM_POINTER_TAG not in region:
        raise SystemExit(
            "x86 mov_reg arm body does not move the source pointer and tag")
    if ARM_NARROW_READ not in region or ARM_NARROW_WRITE not in region:
        raise SystemExit(
            "x86 mov_reg arm body does not do the narrow lane read/write")
    if HAND_WIDTH_TEST in region:
        raise SystemExit(
            "x86 mov_reg arm body tests the width by hand instead of through "
            "the generated selector")
    if HAND_RSP_TEST in region:
        raise SystemExit(
            "x86 mov_reg arm body tests the stack pointer by hand instead of "
            "through the generated selector")
    if exactly_one_arm and region.count("} else if ((OP) ==") != 1:
        raise SystemExit("x86 mov_reg arm region is not exactly one arm")


def check_against_header():
    """Both live MOV_REG bodies (the standalone shared macro and the routed
    arm) must route their arm choice through the generated selector."""
    check_region(arm_region(), exactly_one_arm=True)
    check_region(macro_region(), exactly_one_arm=False)


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 mov_reg arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 mov_reg arm specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid x86 mov_reg arm {column}: {arms!r}")
    if len(arms) != 3:
        raise SystemExit("x86 mov_reg arm must select between exactly 3 arms")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    opcode = spec["opcode"]
    full = spec["full_width_code"]
    rsp = spec["rsp_code"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}' for index, row in enumerate(arms))
    effect_of = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    width_class = "\n".join(
        f'  | .{row["arm"]} => "{row["width_class"]}"' for row in arms)
    return f'''-- Generated by generate_x86_mov_reg_arm_spec.py from x86_mov_reg_arm_spec.json.
import Std
namespace KProgFormal.GeneratedX86MovRegArm
/-- The three bodies the `X86_OP_MOV_REG` arm selects between: the stack-base
pointer write, the provenance-preserving pointer write, and the narrow
scalarizing value write. -/
inductive Arm where
  | {arms[0]["arm"]}
  | {arms[1]["arm"]}
  | {arms[2]["arm"]}
deriving DecidableEq, Repr
/-- The number of bodies the `X86_OP_MOV_REG` arm selects between. -/
def armCount : Nat := {len(arms)}
/-- The `X86_OP_MOV_REG` opcode the arm implements. -/
def opcode : Nat := {opcode}
/-- The full 64-bit width code the pointer family is selected at. -/
def fullWidthCode : Nat := {full}
/-- The stack-pointer register number the stack-base arm is selected at. -/
def rspCode : Nat := {rsp}
/-- The body each width/register pair selects, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The effect each body performs on the destination cell. -/
def effectOfArm : Arm -> String
{effect_of}
/-- The width class each body operates in. -/
def widthClassOfArm : Arm -> String
{width_class}
/-- The body a resolved width code and a source register number select: at the
full 64-bit width code the stack-base arm when the source is the stack pointer
and the provenance pointer arm otherwise; the narrow scalarizing arm at every
other code. The stack-pointer test is nested inside the width test, so a narrow
width ignores register identity. -/
def armOf (width rsp : Nat) : Arm :=
  if width = fullWidthCode then
    (if rsp = rspCode then .{arms[0]["arm"]} else .{arms[1]["arm"]})
  else .{arms[2]["arm"]}
/-- The body an arm code names, or `none` when the code names no arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86MovRegArm
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    full = spec["full_width_code"]
    rsp = spec["rsp_code"]
    stack = arms[0]["arm_define"]
    pointer = arms[1]["arm_define"]
    narrow = arms[2]["arm_define"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    select_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RSP) == '
        f'{stack}, "{a}");'
        for a in ("x86 mov_reg arm stack-ptr selection drift",))
    return f'''/* Generated by generate_x86_mov_reg_arm_spec.py from x86_mov_reg_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_MOV_REG_ARM_H
#define KPROG_FORMAL_GENERATED_X86_MOV_REG_ARM_H
/*
 * x86-64 `MOV_REG` three-way arm-selection contract: the `X86_OP_MOV_REG` arm
 * of `X86_SIM_L_EXEC` (and the shared `X86_SIM_L_EXEC_MOV_REG_AUX` body)
 * selects between three bodies from the resolved operand width and the source
 * register identity. At the full {full} (64-bit) width code the source register
 * being the stack pointer selects the stack-base arm
 * (`X86_SIM_L_STACK_PTR`, tagged stack provenance); any other source selects
 * the pointer arm, moving the whole source cell with its own provenance tag.
 * At every narrower code the narrow arm observes the source through its decoded
 * byte lane and writes the destination lane, scalarizing provenance. The
 * stack-pointer test is nested inside the width test, so a narrow `mov` ignores
 * register identity.
 * `KProgFormal/X86MovRegShape.lean` proves the generated `armOf` equal to an
 * independent construction from the width and register literals, and that each
 * arm's effect is the composition `X86MovHandler.lean` proves.
 * This header is included after the `X86_OP_MOV_REG` / `X86_WIDTH_*` /
 * `X86_RSP` decodes, so the drift checks bind the hand-written constants to the
 * generated table.
 */
/* The full 64-bit width code the pointer family is selected at. */
#define KPROG_X86_MOV_REG_FULL_WIDTH {full}U
/* The number of bodies the arm selects between. */
#define KPROG_X86_MOV_REG_ARM_COUNT {count}U
{arm_defines}
/*
 * The body a resolved width code and a source register select: at the full
 * 64-bit code the stack-base arm when the source is the stack pointer and the
 * pointer arm otherwise; the narrow arm at every other code. The two inputs are
 * each evaluated once.
 */
#define KPROG_X86_MOV_REG_ARM(W, RSP)                                       \\
\t((((__u8)((W))) == KPROG_X86_MOV_REG_FULL_WIDTH)                    \\
\t\t ? ((((__u8)((RSP))) == X86_RSP)                            \\
\t\t\t    ? {stack}               \\
\t\t\t    : {pointer})                \\
\t\t : {narrow})
_Static_assert(X86_OP_MOV_REG == {spec["opcode"]}U,
\t       "x86 mov_reg arm opcode drift");
_Static_assert(X86_WIDTH_64 == KPROG_X86_MOV_REG_FULL_WIDTH,
\t       "x86 mov_reg arm full-width code drift");
_Static_assert(X86_RSP == {rsp}U,
\t       "x86 mov_reg arm stack-pointer code drift");
_Static_assert(KPROG_X86_MOV_REG_ARM_COUNT == {count}U,
\t       "x86 mov_reg arm count drift");
_Static_assert({stack} != {pointer} && {pointer} != {narrow} && {stack} != {narrow},
\t       "x86 mov_reg arm codes must be distinct");
/* The selector must name each arm at its own width/register pair. */
{select_asserts}
_Static_assert(KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RAX) == {pointer},
\t       "x86 mov_reg arm pointer selection drift");
_Static_assert(KPROG_X86_MOV_REG_ARM(X86_WIDTH_32, X86_RSP) == {narrow},
\t       "x86 mov_reg arm narrow selection ignores rsp drift");
_Static_assert(KPROG_X86_MOV_REG_ARM(X86_WIDTH_8, X86_RAX) == {narrow},
\t       "x86 mov_reg arm narrow selection drift");
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
                    f"generated x86 mov_reg arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
