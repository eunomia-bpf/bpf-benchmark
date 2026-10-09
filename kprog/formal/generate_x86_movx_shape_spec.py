#!/usr/bin/env python3
"""Generate the shared x86-64 `MOVZX`/`MOVSX` register-source shape contract.

The hand-written `X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm of `X86_SIM_L_EXEC`
in `kprog/x86/x86_sim_local_bpf.h` (and the shared `X86_SIM_L_EXEC_MOVX_REG`
body it mirrors) reads the raw 64-bit source register and then selects *which
extension function* widens the source lane at the *source* width:

  * `X86_OP_MOVSX_REG` sign-extends the source lane (`x86_sign_extend`), so a
    negative lane keeps its sign across the widened destination;
  * `X86_OP_MOVZX_REG` zero-extends it (`x86_apply_width`), discarding the sign,
    and is the arm's default for every other opcode.

Only the *which function* choice is keyed on the opcode. The source width the
chosen function is applied at is a separate decision — `(AUX) ? (AUX) :
__x86_l_width` — and is not part of this contract (it is the width resolution
`x86_width_effective` names, Step 0105); the destination-width writeback is the
plain partial-register write.

The narrow/sign-extend *values* and the writeback are already proved by
`GeneratedX86Signed.lean` / `GeneratedX86Width.lean` / `GeneratedX86RegWrite.lean`
and composed by `X86MovxRegHandler.lean`; this contract covers the *arm
selection* the routed body performs: opcode to extension function. The generated
table `GeneratedX86MovxShape.armOf` and the C macro `KPROG_X86_MOVX_SHAPE` name
that function for an opcode.

The generator is independent of the arm it describes: it holds its own literal
enumeration and re-derives the live MOVX arm text from the simulator header,
then requires the routed arm to go through the generated selector.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_MOVZX_REG` / `X86_OP_MOVSX_REG` decodes, exactly as the opcode mirror.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_movx_shape_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86MovxShape.lean"
CHEADER = ROOT / "generated/x86_movx_shape.h"

# The independent enumeration of the two arms, in selection order:
# (arm, arm define, opcode, opcode define, result function, effect).
_ARMS = [
    ("sign_extend", "KPROG_X86_MOVX_SHAPE_SIGN_EXTEND", 33, "X86_OP_MOVSX_REG",
     "sign_extend", "sign_extend_source_lane"),
    ("zero_extend", "KPROG_X86_MOVX_SHAPE_ZERO_EXTEND", 32, "X86_OP_MOVZX_REG",
     "zero_extend", "zero_extend_source_lane"),
]
OPCODE_BITS = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86MovxShapeSelector",
    "selector": "opcode_then_arm",
    "opcode_bits": OPCODE_BITS,
    "arms": [{"arm": arm, "arm_define": define, "opcode": opcode,
              "opcode_define": opcode_define, "result": result,
              "effect": effect}
             for arm, define, opcode, opcode_define, result, effect in _ARMS],
}
COLUMNS = ("arm", "arm_define", "opcode", "opcode_define", "result", "effect")

# The live routed arm text, between the MOVX arm opener (a `\`-continued `||`)
# and the `MOV_LOAD` arm. The opener is located after `flat()`.
ARM_START = "} else if ((OP) == X86_OP_MOVZX_REG ||"
ARM_END = "} else if ((OP) == X86_OP_MOV_LOAD ||"
# The standalone shared body, between its `#define` and the next `#define`.
MACRO_START = "#define X86_SIM_L_EXEC_MOVX_REG(OP, DST, SRC, FLAGS, AUX)"
MACRO_END = "#define X86_SIM_L_EXEC_CMP_IMM_OP_AUX(OP, DST, FLAGS, AUX, IMM)"
ARM_SELECTOR = "KPROG_X86_MOVX_SHAPE((OP))"
ARM_SIGN_ARM = "KPROG_X86_MOVX_SHAPE_SIGN_EXTEND"
ARM_SIGN_CALL = "x86_sign_extend("
ARM_ZERO_CALL = "x86_apply_width("


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
    """A routed MOVX body must select its extension function through the
    generated opcode selector, name the sign-extend arm, and still compute both
    extension functions; it must not select by hand."""
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 movx shape body does not route through the generated selector")
    if ARM_SIGN_ARM not in region:
        raise SystemExit("x86 movx shape body does not name the sign-extend arm")
    if ARM_SIGN_CALL not in region:
        raise SystemExit(
            "x86 movx shape body does not compute the sign extension")
    if ARM_ZERO_CALL not in region:
        raise SystemExit(
            "x86 movx shape body does not compute the zero extension")
    if exactly_one_arm and region.count("} else if ((OP) ==") != 1:
        raise SystemExit("x86 movx shape arm region is not exactly one arm")
    if "X86_OP_MOVSX_REG ?" in region:
        raise SystemExit(
            "x86 movx shape body selects its extension function by hand "
            "instead of through the generated selector")


def check_against_header():
    """Both live MOVX bodies (the standalone shared macro and the routed arm)
    must route their extension-function choice through the generated opcode
    selector."""
    check_region(arm_region(), exactly_one_arm=True)
    check_region(macro_region(), exactly_one_arm=False)


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 movx shape keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 movx shape specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid x86 movx shape {column}: {arms!r}")
    if len({row["opcode"] for row in arms}) != len(arms):
        raise SystemExit("x86 movx shape opcodes must be distinct")
    if [row["result"] for row in arms if row["result"] not in
            ("sign_extend", "zero_extend")] != []:
        raise SystemExit(
            "x86 movx shape results must name the extension functions")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["opcode_bits"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}' for index, row in enumerate(arms))
    opcode_of = "\n".join(
        f'  | .{row["arm"]} => {row["opcode"]}' for row in arms)
    result_of = "\n".join(
        f'  | .{row["arm"]} => "{row["result"]}"' for row in arms)
    effect_of = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    first = arms[0]
    other = arms[1]["arm"]
    return f'''-- Generated by generate_x86_movx_shape_spec.py from x86_movx_shape_spec.json.
import Std
namespace KProgFormal.GeneratedX86MovxShape
/-- The two extension functions the `X86_OP_MOVZX_REG` / `X86_OP_MOVSX_REG`
arm selects between on the opcode. -/
inductive Arm where
  | {first["arm"]}
  | {other}
deriving DecidableEq, Repr
/-- The number of extension functions the MOVX arm selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the opcode the arm selects on. -/
def opcodeBits : Nat := {bits}
/-- The extension function each opcode selects, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each extension function, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of an extension function. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The opcode each extension function implements. -/
def opcodeOfArm : Arm -> Nat
{opcode_of}
/-- The extension function each arm performs (`x86_sign_extend` /
`x86_apply_width`). -/
def resultOfArm : Arm -> String
{result_of}
/-- The effect each arm performs on the widened source lane. -/
def effectOfArm : Arm -> String
{effect_of}
/-- The extension function an opcode selects: the sign extension at
`X86_OP_MOVSX_REG`, the zero extension at every other opcode (the arm only runs
for the two MOVX opcodes, so the default is the zero extension). -/
def armOf (op : Nat) : Arm :=
  if op = {first["opcode"]} then .{first["arm"]} else .{other}
/-- The extension function an arm code names, or `none` when the code names no
arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86MovxShape
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    first = arms[0]
    last = arms[1]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    opcode_asserts = "\n".join(
        f'_Static_assert({row["opcode_define"]} == {row["opcode"]}U,\n'
        f'\t       "x86 movx shape {row["arm"]} opcode drift");'
        for row in arms)
    arm_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_MOVX_SHAPE({row["opcode_define"]}) == '
        f'{row["arm_define"]},\n'
        f'\t       "x86 movx shape {row["arm"]} selection drift");'
        for row in arms)
    return f'''/* Generated by generate_x86_movx_shape_spec.py from x86_movx_shape_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_MOVX_SHAPE_H
#define KPROG_FORMAL_GENERATED_X86_MOVX_SHAPE_H
/*
 * x86-64 `MOVZX`/`MOVSX` register-source opcode-keyed extension-shape contract:
 * the `X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm of `X86_SIM_L_EXEC` (and the
 * shared `X86_SIM_L_EXEC_MOVX_REG` body) selects which extension function widens
 * the raw source lane on the opcode, not the operands. The `X86_OP_MOVSX_REG`
 * body sign-extends the source lane (`x86_sign_extend`); the `X86_OP_MOVZX_REG`
 * body zero-extends it (`x86_apply_width`) and is the default for every other
 * opcode. The *source width* the selected function is applied at is a separate
 * decision (the width resolution `x86_width_effective` names); the
 * destination-width writeback is the plain partial-register write.
 * `KProgFormal/X86MovxShape.lean` proves the generated `armOf` equal to an
 * independent construction from the opcode literals, that the two arm
 * name/code/opcode/result/effect tables are exactly the two extension functions,
 * and that each opcode selects its own function.
 * This header is included after the `X86_OP_MOVZX_REG` / `X86_OP_MOVSX_REG`
 * decodes, so the drift checks bind the hand-written constants to the generated
 * table.
 */
/* The number of extension functions the arm selects between. */
#define KPROG_X86_MOVX_SHAPE_COUNT {count}U
{arm_defines}
/*
 * The extension function an opcode selects: the sign extension at
 * `X86_OP_MOVSX_REG`, the zero extension at every other opcode. The input is
 * evaluated once.
 */
#define KPROG_X86_MOVX_SHAPE(OP)                                            \\
\t(((__u8)((OP))) == {first["opcode_define"]}                                 \\
\t\t ? {first["arm_define"]} : {last["arm_define"]})
_Static_assert(KPROG_X86_MOVX_SHAPE_COUNT == {count}U,
\t       "x86 movx shape count drift");
{opcode_asserts}
_Static_assert({first["arm_define"]} != {last["arm_define"]},
\t       "x86 movx shape arm codes must be distinct");
/* The opcode selector must name each extension function at its own opcode. */
{arm_asserts}
/* The selector is total: an opcode that is not the movsx opcode reaches the
 * zero-extension default. */
_Static_assert(KPROG_X86_MOVX_SHAPE(0) == {last["arm_define"]},
\t       "x86 movx shape absent opcode must reach the default arm");
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
                    f"generated x86 movx shape contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
