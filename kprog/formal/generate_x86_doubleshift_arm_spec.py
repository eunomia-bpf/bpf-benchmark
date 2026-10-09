#!/usr/bin/env python3
"""Generate the shared x86-64 `SHLD`/`SHRD` immediate-arm selection contract.

The hand-written `X86_OP_SHLD_IMM || X86_OP_SHRD_IMM` arm of `X86_SIM_L_EXEC`
in `kprog/x86/x86_sim_local_bpf.h` is keyed on the *opcode*, not the operand
width (both tokens are immediate-only and width-agnostic), and selects between
two bodies plus the flag family each body reports to the shift-flag contract:

  * `X86_OP_SHLD_IMM` computes the left double shift `x86_shld(dst, src, imm,
    width)` (fill the low bits from the top of `src`) and reports the `SHL`
    flag family (`X86_ALU_SHL`), so the shift-flag contract takes the
    left-count carry/overflow path;
  * `X86_OP_SHRD_IMM` computes the right double shift `x86_shrd(dst, src, imm,
    width)` (fill the high bits from the bottom of `src`) and reports the `SHR`
    flag family (`X86_ALU_SHR`), taking the right-count path.

Both bodies sit behind the count-zero *step gate*: when the hardware-masked
count `x86_shift_count(imm, width)` is zero neither the result function nor the
flag family is consulted -- the arm computes no result, writes no register, and
leaves every flag untouched (the architectural `SHLD`/`SHRD` count-zero no-op).

The double-shift *values* (`x86_shld`/`x86_shrd`) and the count-zero value
identity are already proved by `GeneratedX86DoubleShift.lean`; this contract
covers the *arm selection* the routed body performs: opcode to result function
and opcode to flag family, plus the step gate that guards both. The generated
table `GeneratedX86DoubleShiftArm.armOf`/`..armOfFlags` and the C macros
`KPROG_X86_DOUBLESHIFT_ARM`/`.._FLAGS` name that arm and family for an opcode.

The generator is independent of the arm it describes: it holds its own literal
enumeration and re-derives the live double-shift arm text from the simulator
header, then requires the routed arm to go through the generated selector and
flag-family macros.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM` / `X86_ALU_SHL` / `X86_ALU_SHR` decodes,
exactly as the opcode/ALU mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_doubleshift_arm_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86DoubleShiftArm.lean"
CHEADER = ROOT / "generated/x86_doubleshift_arm.h"

# The independent enumeration of the two arms, in selection order:
# (arm, arm define, opcode, opcode define, result function, flag family code,
#  flag family define, effect).
_ARMS = [
    ("shld", "KPROG_X86_DOUBLESHIFT_ARM_SHLD", 27, "X86_OP_SHLD_IMM",
     "shld", 5, "X86_ALU_SHL", "shift_left_fill_src_high"),
    ("shrd", "KPROG_X86_DOUBLESHIFT_ARM_SHRD", 28, "X86_OP_SHRD_IMM",
     "shrd", 6, "X86_ALU_SHR", "shift_right_fill_src_low"),
]
OPCODE_BITS = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86DoubleShiftArmSelector",
    "selector": "opcode_then_arm",
    "opcode_bits": OPCODE_BITS,
    "arms": [{"arm": arm, "arm_define": define, "opcode": opcode,
              "opcode_define": opcode_define, "result": result,
              "flag_family_code": flag_code,
              "flag_family_define": flag_define, "effect": effect}
             for arm, define, opcode, opcode_define, result, flag_code,
             flag_define, effect in _ARMS],
}
COLUMNS = ("arm", "arm_define", "opcode", "opcode_define", "result",
           "flag_family_code", "flag_family_define", "effect")

# The live routed arm text, between the double-shift arm opener and the `PUSH`
# arm. The opener spans a `\`-continued `||`, so it is located after `flat()`.
ARM_START = "} else if ((OP) == X86_OP_SHLD_IMM ||"
ARM_END = "} else if ((OP) == X86_OP_PUSH) {"
ARM_SELECTOR = "KPROG_X86_DOUBLESHIFT_ARM((OP))"
ARM_FLAGS = "KPROG_X86_DOUBLESHIFT_ARM_FLAGS((OP))"
ARM_SHLD_ARM = "KPROG_X86_DOUBLESHIFT_ARM_SHLD"
ARM_SHLD_CALL = "x86_shld("
ARM_SHRD_CALL = "x86_shrd("
ARM_STEP_GATE = "x86_shift_count((IMM), __x86_l_width) != 0"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live double-shift arm must route both its body and its flag family
    through the generated opcode selector, behind the count-zero step gate."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 doubleshift arm does not route through the generated selector")
    if ARM_FLAGS not in region:
        raise SystemExit(
            "x86 doubleshift arm does not route its flag family through the "
            "generated selector")
    if ARM_SHLD_ARM not in region:
        raise SystemExit("x86 doubleshift arm does not name the shld arm")
    if ARM_SHLD_CALL not in region:
        raise SystemExit("x86 doubleshift arm does not compute the shld value")
    if ARM_SHRD_CALL not in region:
        raise SystemExit("x86 doubleshift arm does not compute the shrd value")
    if ARM_STEP_GATE not in region:
        raise SystemExit(
            "x86 doubleshift arm has no count-zero step gate")
    if flat(region).count("} else if ((OP) ==") != 1:
        raise SystemExit(
            "x86 doubleshift arm region is not exactly one arm")
    if "X86_ALU_SHL" in region or "X86_ALU_SHR" in region:
        raise SystemExit(
            "x86 doubleshift arm selects its flag family by hand instead of "
            "through the generated selector")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 doubleshift arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid x86 doubleshift arm specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(
                f"invalid x86 doubleshift arm {column}: {arms!r}")
    if len({row["opcode"] for row in arms}) != len(arms):
        raise SystemExit(
            "x86 doubleshift arm opcodes must be distinct")
    if len({row["flag_family_code"] for row in arms}) != len(arms):
        raise SystemExit(
            "x86 doubleshift arm flag families must be distinct")
    if [row["result"] for row in arms if row["result"] not in
            ("shld", "shrd")] != []:
        raise SystemExit(
            "x86 doubleshift arm results must name the double-shift functions")
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
    flags_of = "\n".join(
        f'  | .{row["arm"]} => {row["flag_family_code"]}' for row in arms)
    effect_of = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    first = arms[0]
    other = arms[1]["arm"]
    return f'''-- Generated by generate_x86_doubleshift_arm_spec.py from x86_doubleshift_arm_spec.json.
import Std
namespace KProgFormal.GeneratedX86DoubleShiftArm
/-- The two bodies the `X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM` arm selects
between on the opcode. -/
inductive Arm where
  | {first["arm"]}
  | {other}
deriving DecidableEq, Repr
/-- The number of bodies the double-shift arm selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the opcode the arm selects on. -/
def opcodeBits : Nat := {bits}
/-- The body each opcode selects, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The opcode each body implements. -/
def opcodeOfArm : Arm -> Nat
{opcode_of}
/-- The double-shift function each body computes (`x86_shld`/`x86_shrd`). -/
def resultOfArm : Arm -> String
{result_of}
/-- The `X86_ALU_*` flag family each body reports to the shift-flag
contract: `{arms[0]["flag_family_code"]}` (SHL) for the left double shift and
`{arms[1]["flag_family_code"]}` (SHR) for the right double shift. -/
def flagFamilyOfArm : Arm -> Nat
{flags_of}
/-- The effect each body performs on the destination register. -/
def effectOfArm : Arm -> String
{effect_of}
/-- The body an opcode selects: the shld body at `X86_OP_SHLD_IMM`, the shrd
body at every other opcode (the arm only runs for the two double-shift
opcodes, so the default is the shrd body). -/
def armOf (op : Nat) : Arm :=
  if op = {first["opcode"]} then .{first["arm"]} else .{other}
/-- The flag family an opcode selects, stated as the family of the selected
body. -/
def armOfFlags (op : Nat) : Nat :=
  flagFamilyOfArm (armOf op)
/-- The body an arm code names, or `none` when the code names no arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86DoubleShiftArm
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
        f'\t       "x86 doubleshift arm {row["arm"]} opcode drift");'
        for row in arms)
    flag_asserts = "\n".join(
        f'_Static_assert({row["flag_family_define"]} == '
        f'{row["flag_family_code"]}U,\n'
        f'\t       "x86 doubleshift arm {row["arm"]} flag family drift");'
        for row in arms)
    arm_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_DOUBLESHIFT_ARM({row["opcode_define"]}) == '
        f'{row["arm_define"]},\n'
        f'\t       "x86 doubleshift arm {row["arm"]} selection drift");'
        for row in arms)
    flags_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_DOUBLESHIFT_ARM_FLAGS('
        f'{row["opcode_define"]}) == {row["flag_family_define"]},\n'
        f'\t       "x86 doubleshift arm {row["arm"]} flag family selection '
        f'drift");'
        for row in arms)
    return f'''/* Generated by generate_x86_doubleshift_arm_spec.py from x86_doubleshift_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_DOUBLESHIFT_ARM_H
#define KPROG_FORMAL_GENERATED_X86_DOUBLESHIFT_ARM_H
/*
 * x86-64 `SHLD`/`SHRD` immediate opcode-keyed arm-selection contract: the
 * `X86_OP_SHLD_IMM || X86_OP_SHRD_IMM` arm of `X86_SIM_L_EXEC` selects between
 * two bodies and their flag families on the opcode (both are immediate-only and
 * width-agnostic, so the arm is keyed on the opcode, not the operands). The
 * `X86_OP_SHLD_IMM` body computes the left double shift `x86_shld` and reports
 * the `X86_ALU_SHL` flag family; the `X86_OP_SHRD_IMM` body computes the right
 * double shift `x86_shrd` and reports the `X86_ALU_SHR` family. Both bodies sit
 * behind the count-zero *step gate*: at a hardware-masked count of zero neither
 * the result function nor the flag family is consulted, so the arm computes no
 * result, writes no register, and leaves every flag untouched.
 * `KProgFormal/X86DoubleShiftArmHandler.lean` proves the generated `armOf` and
 * `armOfFlags` equal an independent construction from the opcode literals, that
 * the two arm name/code/opcode/result/flag-family tables are exactly the two
 * bodies, and that the count-zero gate leaves the destination and the flags
 * untouched.
 * This header is included after the `X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM` /
 * `X86_ALU_SHL` / `X86_ALU_SHR` decodes, so the drift checks bind the
 * hand-written constants to the generated table.
 */
/* The number of bodies the arm selects between. */
#define KPROG_X86_DOUBLESHIFT_ARM_COUNT {count}U
{arm_defines}
/*
 * The body an opcode selects: the shld body at `X86_OP_SHLD_IMM`, the shrd body
 * at every other opcode. The input is evaluated once.
 */
#define KPROG_X86_DOUBLESHIFT_ARM(OP)                                       \\
\t(((__u8)((OP))) == {first["opcode_define"]}                                 \\
\t\t ? {first["arm_define"]} : {last["arm_define"]})
/*
 * The `X86_ALU_*` flag family an opcode reports to the shift-flag contract, so
 * the flag family is selected by the same opcode the body is. The input is
 * evaluated once.
 */
#define KPROG_X86_DOUBLESHIFT_ARM_FLAGS(OP)                                 \\
\t(((__u8)((OP))) == {first["opcode_define"]}                                 \\
\t\t ? {first["flag_family_define"]} : {last["flag_family_define"]})
_Static_assert(KPROG_X86_DOUBLESHIFT_ARM_COUNT == {count}U,
\t       "x86 doubleshift arm count drift");
{opcode_asserts}
{flag_asserts}
_Static_assert({first["arm_define"]} != {last["arm_define"]},
\t       "x86 doubleshift arm codes must be distinct");
_Static_assert({first["flag_family_define"]} != {last["flag_family_define"]},
\t       "x86 doubleshift arm flag families must be distinct");
/* The opcode selector must name each body at its own opcode. */
{arm_asserts}
/* The flag-family selector must name each family at its own opcode. */
{flags_asserts}
/* The selector is total: an opcode that is not the shld opcode reaches the
 * shrd body. */
_Static_assert(KPROG_X86_DOUBLESHIFT_ARM(0) == {last["arm_define"]},
\t       "x86 doubleshift arm absent opcode must reach the default arm");
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
                    f"generated x86 doubleshift arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
