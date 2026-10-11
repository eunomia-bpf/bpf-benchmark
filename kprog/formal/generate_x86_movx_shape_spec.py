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

Only the *which function* choice is keyed on the opcode. The *source width* the
chosen function is applied at is resolved by `KPROG_X86_MOVX_SRC_WIDTH`: the
decoded `AUX` field names the source width unless it is the absent code, in
which case the body falls back to its effective (FLAGS-resolved) width (the
`x86_width_effective` kernel, Step 0105). The destination-width writeback is the
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
WIDTH_SPEC = ROOT / "x86_width_spec.json"

# The independent enumeration of the two arms, in selection order:
# (arm, arm define, opcode, opcode define, result function, effect).
_ARMS = [
    ("sign_extend", "KPROG_X86_MOVX_SHAPE_SIGN_EXTEND", 33, "X86_OP_MOVSX_REG",
     "sign_extend", "sign_extend_source_lane"),
    ("zero_extend", "KPROG_X86_MOVX_SHAPE_ZERO_EXTEND", 32, "X86_OP_MOVZX_REG",
     "zero_extend", "zero_extend_source_lane"),
]

# The independent enumeration of the four width codes the MOVX body can operate
# at, keyed on their `x86_width_spec.json` names: (name, code, decode define).
# The generator re-derives the (name, code) pairs from the width specification
# and requires the live header's decodes, so the source-width contract cannot
# silently re-key on a changed width kernel.
_WIDTH_CODES = (("w8", 1, "X86_WIDTH_8"), ("w16", 2, "X86_WIDTH_16"),
                ("w32", 4, "X86_WIDTH_32"), ("w64", 8, "X86_WIDTH_64"))
# The independent source-width resolution of a MOVX body: the decoded `aux`
# field names the source width, unless it is the absent code, in which case the
# body falls back to its effective (`effective_width`) width.
_SOURCE_WIDTH = {"field": "aux", "absent_code": 0, "fallback": "effective_width"}
OPCODE_BITS = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86MovxShapeSelector",
    "selector": "opcode_then_arm",
    "opcode_bits": OPCODE_BITS,
    "source_width": dict(_SOURCE_WIDTH),
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
SRC_SELECTOR = "KPROG_X86_MOVX_SRC_WIDTH(("
SRC_RAW_FALLBACK = "src_width = (AUX) ? (AUX)"


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
    if SRC_SELECTOR not in region:
        raise SystemExit(
            "x86 movx shape body does not route its source width through the "
            "generated selector")
    if SRC_RAW_FALLBACK in region:
        raise SystemExit(
            "x86 movx shape body restates the source-width fallback by hand "
            "instead of through the generated selector")


def check_against_header():
    """Both live MOVX bodies (the standalone shared macro and the routed arm)
    must route their extension-function choice through the generated opcode
    selector."""
    check_region(arm_region(), exactly_one_arm=True)
    check_region(macro_region(), exactly_one_arm=False)


def load_width_codes():
    """Re-derive the four width codes from the public `x86_width_spec.json`
    kernel, so the source-width contract is stated against the width names the
    rest of the simulator uses rather than a private copy."""
    data = json.loads(WIDTH_SPEC.read_text())
    if data.get("operation") != "x86Width" or len(data.get("widths", [])) != 4:
        raise SystemExit(f"invalid x86 width specification: {data!r}")
    codes = tuple((w["name"], w["code"]) for w in data["widths"])
    want = tuple((name, code) for name, code, _define in _WIDTH_CODES)
    if codes != want:
        raise SystemExit(f"x86 width codes drifted from the MOVX contract: {codes!r}")
    return codes


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
    src = EXPECTED["source_width"]
    codes = load_width_codes()
    if src["absent_code"] != 0:
        raise SystemExit(f"non-canonical x86 movx source-width absent code: {src!r}")
    if src["absent_code"] in [code for _name, code, _define in _WIDTH_CODES]:
        raise SystemExit(
            f"x86 movx source-width absent code collides with a width code: {src!r}")
    if src["fallback"] != "effective_width":
        raise SystemExit(f"unknown x86 movx source-width fallback: {src!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["opcode_bits"]
    src = spec["source_width"]
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
    width_codes = ", ".join(str(code) for _name, code, _define in _WIDTH_CODES)
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
/-- The decoded field the MOVX body reads its source width from. -/
def srcWidthField : String := "{src["field"]}"
/-- The decoded source-width code that means "absent": a body that leaves its
`{src["field"]}` field empty falls back to its effective width. -/
def srcWidthAbsentCode : Nat := {src["absent_code"]}
/-- The source-width code each real width name resolves to, in width order. -/
def srcWidthCodes : List Nat := [{width_codes}]
/-- Resolve the decoded source width a MOVX body operates at: the decoded
`{src["field"]}` code unless it is the absent code ({src["absent_code"]}), in which case the body
falls back to its effective (FLAGS-resolved) width. The fallback is a separate
resolution (`effective_width`, the width kernel), not a width code. -/
def srcWidth (aux : Nat) (effective : Nat) : Nat :=
  if aux = srcWidthAbsentCode then effective else aux
'''


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    src = spec["source_width"]
    absent = src["absent_code"]
    first = arms[0]
    last = arms[1]
    width_names = ", ".join(define for _n, _c, define in _WIDTH_CODES)
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
    src_identity = "\n".join(
        f'_Static_assert(\n'
        f'\tKPROG_X86_MOVX_SRC_WIDTH({define}, X86_WIDTH_64) == {define},\n'
        f'\t"x86 movx source width {name} must be its own source width");'
        for name, _code, define in _WIDTH_CODES)
    src_distinct = "\n".join(
        f'_Static_assert(KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE != {define},\n'
        f'\t"x86 movx source width absent code collides with {name}");'
        for name, _code, define in _WIDTH_CODES)
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
 * opcode. The *source width* the selected function is applied at is resolved by
 * `KPROG_X86_MOVX_SRC_WIDTH`: the decoded `aux` field names the source width
 * unless it is the absent code, in which case the body falls back to its
 * effective (FLAGS-resolved) width; the destination-width writeback is the
 * plain partial-register write.
 * `KProgFormal/X86MovxShape.lean` proves the generated `armOf` equal to an
 * independent construction from the opcode literals, that the two arm
 * name/code/opcode/result/effect tables are exactly the two extension functions,
 * and that each opcode selects its own function, and that `srcWidth` is the
 * identity on every decoded width code and only rewrites the absent code.
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
/* The decoded source-width code that means "absent": a MOVX body that leaves
 * its `aux` field empty falls back to its effective width. */
#define KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE {absent}U
/*
 * Resolve the source width a MOVX body operates at: the decoded `aux` code
 * unless it is the absent code ({absent}), in which case the body falls back to the width it
 * passes as its effective width. The operands are evaluated as the body
 * evaluates them, and the selector is a plain ternary so it is usable from a
 * `_Static_assert`.
 */
#define KPROG_X86_MOVX_SRC_WIDTH(AUX, WIDTH)                                \\
\t(((__u8)((AUX))) == KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE ?              \\
\t (__u8)((WIDTH)) : (__u8)((AUX)))
_Static_assert(KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE == {absent}U,
\t       "x86 movx source width absent code drift");
/* The resolution is the identity on every real source width: only the absent
 * code is rewritten. The width decode names ({width_names}) are the ones the
 * rest of the simulator uses. */
{src_identity}
/* The absent code names no width, so it cannot alias a real source width. */
{src_distinct}
/* An absent `aux` field resolves to the effective width the body passes in,
 * not to a width code of its own. */
_Static_assert(
\tKPROG_X86_MOVX_SRC_WIDTH(KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE,
\t\t\t\t  X86_WIDTH_64) == X86_WIDTH_64,
\t"x86 movx source width absent field must fall back to the effective width");
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
