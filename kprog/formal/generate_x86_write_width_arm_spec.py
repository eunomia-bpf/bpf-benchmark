#!/usr/bin/env python3
"""Generate the shared x86-64 register-write width body-selection contract.

The hand-written `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` macro in
`kprog/x86/x86_sim_local_bpf.h` writes a value back into a GPR at the
*resolved* operand width (`__x86_wr_width`, already the effective width). It
selects between four writeback bodies on that width:

  * at the byte width code it writes one byte lane of the register (the lane
    chosen by the destination shift) via `KPROG_X86_WRITE_REG8`, scalarizing the
    cell;
  * at the word width code it writes the low word via `KPROG_X86_WRITE_REG16`,
    preserving the register's upper six bytes;
  * at the dword width code it writes the low dword via `KPROG_X86_WRITE_REG32`,
    zeroing the register's upper half;
  * at every other code — including the 64-bit code and the absent code — it
    writes the full qword via `KPROG_X86_WRITE_REG64`.

The ladder's final arm is the *default*: it is the body selected by every width
code that is not one of the byte/word/dword codes, so the selector is total and
there is no unsupported case (since `__x86_wr_width` is already resolved, absent
never reaches it directly, but the contract is defined for every code). The
generated table `GeneratedX86WriteWidthArm.armOf` and the C macro
`KPROG_X86_WRITE_WIDTH_ARM` name that body for a resolved width code.

Unlike the narrower-width *values* the other x86 arms compute, these four bodies
are genuinely observable at distinct widths: the width is applied *inside* each
body's write macro (`KPROG_X86_WRITE_REG8` writes a single byte lane,
`KPROG_X86_WRITE_REG16` the low word, `KPROG_X86_WRITE_REG32` the low dword, and
`KPROG_X86_WRITE_REG64` the whole register), and `__x86_wr_next` is not
pre-masked. A wrong selector code or a swapped body therefore changes the
written register bytes.

The generator is independent of the table it describes: it holds its own
literal enumeration and re-derives the live `X86_SIM_L_WRITE_REG_WIDTH_SHIFT`
macro text from the simulator header, then requires the routed macro to go
through the generated selector and to route each body's case macro.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_WIDTH_*` decodes, exactly as the opcode mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_write_width_arm_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86WriteWidthArm.lean"
CHEADER = ROOT / "generated/x86_write_width_arm.h"

# The independent enumeration of the four bodies, in selection order:
# (arm, arm define, width code, body, case macro, width class).
_ARMS = [
    ("b8", "KPROG_X86_WRITE_WIDTH_ARM_B8", 1, "byte_lane_writeback",
     "X86_SIM_L_WRITE_REG8_VALUE_CASE", "narrow"),
    ("b16", "KPROG_X86_WRITE_WIDTH_ARM_B16", 2, "word_writeback",
     "X86_SIM_L_WRITE_REG16_VALUE_CASE", "narrow"),
    ("b32", "KPROG_X86_WRITE_WIDTH_ARM_B32", 4, "dword_writeback",
     "X86_SIM_L_WRITE_REG32_VALUE_CASE", "narrow"),
    ("b64", "KPROG_X86_WRITE_WIDTH_ARM_B64", 8, "qword_writeback",
     "X86_SIM_L_WRITE_REG64_VALUE_CASE", "full"),
]
WIDTH_CODE_BITS = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86WriteWidthArmSelector",
    "selector": "resolved_width_code_then_write_body",
    "width_code_bits": WIDTH_CODE_BITS,
    "arms": [{"arm": arm, "arm_define": define, "width_code": code,
              "body": body, "case_macro": macro, "width_class": width_class}
             for arm, define, code, body, macro, width_class in _ARMS],
}
COLUMNS = ("arm", "arm_define", "width_code", "body", "case_macro",
           "width_class")

# The live routed macro text, between the `_SHIFT` macro opener and the
# delegating wrapper.
ARM_START = "#define X86_SIM_L_WRITE_REG_WIDTH_SHIFT(REG, VALUE, WIDTH, DST_SHIFT)"
ARM_END = "#define X86_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH)"
ARM_SELECTOR = "KPROG_X86_WRITE_WIDTH_ARM("
ARM_HAND_LADDER = "if (__x86_wr_width == X86_WIDTH_8)"
ARM_DEFAULT = "} else {"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live write-width macro must route through the generated selector."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 write width macro does not route through the generated "
            "selector")
    for _arm, define, _c, _b, _m, _wc in _ARMS[:-1]:
        if define not in region:
            raise SystemExit(
                f"x86 write width body {define} is not routed")
    for _arm, _define, _c, _b, macro, _wc in _ARMS:
        if macro not in region:
            raise SystemExit(
                f"x86 write width case macro {macro} is not routed")
    if ARM_DEFAULT not in region:
        raise SystemExit("x86 write width default body is not routed")
    if ARM_HAND_LADDER in region:
        raise SystemExit(
            "x86 write width macro still contains the hand width ladder")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 write width keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 write width specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid x86 write width {column}: {arms!r}")
    if [row["width_class"] for row in arms] != \
            ["narrow", "narrow", "narrow", "full"]:
        raise SystemExit("x86 write width classes must be the width ladder")
    if arms[-1]["width_code"] != 8:
        raise SystemExit("x86 write width default body must be the qword one")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["width_code_bits"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}' for index, row in enumerate(arms))
    width_code_of = "\n".join(
        f'  | .{row["arm"]} => {row["width_code"]}' for row in arms)
    body_of = "\n".join(
        f'  | .{row["arm"]} => "{row["body"]}"' for row in arms)
    macro_of = "\n".join(
        f'  | .{row["arm"]} => "{row["case_macro"]}"' for row in arms)
    width_class = "\n".join(
        f'  | .{row["arm"]} => "{row["width_class"]}"' for row in arms)
    ladder = "\n".join(
        f'  {"if" if index == 0 else "else if"} width = {row["width_code"]} '
        f'then .{row["arm"]}'
        for index, row in enumerate(arms[:-1]))
    last = arms[-1]["arm"]
    return f'''-- Generated by generate_x86_write_width_arm_spec.py from x86_write_width_arm_spec.json.
import Std
namespace KProgFormal.GeneratedX86WriteWidthArm
/-- The four register-writeback bodies `X86_SIM_L_WRITE_REG_WIDTH_SHIFT`
selects between on the resolved operand width. -/
inductive Arm where
  | b8
  | b16
  | b32
  | b64
deriving DecidableEq, Repr
/-- The number of writeback bodies the macro selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the resolved width code the body selects on. -/
def widthCodeBits : Nat := {bits}
/-- The body each resolved width code selects, in selection order. -/
def armNames : List String := [{names}]
/-- The case code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The case code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The resolved width code each body writes back at. -/
def widthCodeOfArm : Arm -> Nat
{width_code_of}
/-- The writeback each body performs on the destination register. -/
def bodyOfArm : Arm -> String
{body_of}
/-- The simulator case macro each body routes through. -/
def caseMacroOfArm : Arm -> String
{macro_of}
/-- The width class each body writes back in. -/
def widthClassOfArm : Arm -> String
{width_class}
/-- The body a resolved width code selects: the byte/word/dword bodies at their
own codes and the qword body at every other code, so the selector is total. -/
def armOf (width : Nat) : Arm :=
{ladder}
  else .{last}
/-- The body a case code names, or `none` when the code names no body. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86WriteWidthArm
'''


def selector_macro(tests: list[tuple[str, str]], default: str) -> str:
    """A width-code ternary ladder ending in the default arm. Each test is
    wrapped in its own parentheses and continued with a backslash, so the whole
    expression stays a single preprocessor logical line."""
    lines = []
    for depth, (cond, define) in enumerate(tests):
        pad = "\t" * (depth + 1)
        lines.append(f"\t({pad}({cond}) \\")
        lines.append(f"\t{pad}\t? {define} : \\")
    pad = "\t" * (len(tests) + 1)
    lines.append(f"\t{pad}{default}")
    body = "\n".join(lines)
    return body + ")" * len(tests)


def render_c(spec: dict) -> str:
    arms = spec["arms"]
    count = len(arms)
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    first = arms[0]["arm_define"]
    # The width-coded bodies tested in order, each as (condition, arm define).
    tests = [(f'((__u8)((CODE))) == X86_WIDTH_{row["width_code"] * 8}',
              row["arm_define"]) for row in arms[:-1]]
    last = arms[-1]["arm_define"]
    selector = selector_macro(tests, last)
    width_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_WRITE_WIDTH_ARM(X86_WIDTH_{row["width_code"] * 8}) == '
        f'{row["arm_define"]}, "x86 write width arm drift");'
        for row in arms)
    return f'''/* Generated by generate_x86_write_width_arm_spec.py from x86_write_width_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_WRITE_WIDTH_ARM_H
#define KPROG_FORMAL_GENERATED_X86_WRITE_WIDTH_ARM_H
/*
 * x86-64 register-writeback resolved-width body-selection contract:
 * `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` selects between four GPR writeback bodies
 * on the resolved operand width. Its ladder is closed over the four X86_WIDTH_*
 * codes: the byte body at the byte code, the word body at the word code, the
 * dword body at the dword code, and the qword body at every other code, so the
 * selector is total and there is no unsupported case. The width is applied
 * inside each body's write macro (a single byte lane, the low word, the low
 * dword, or the full register), so the four bodies write the destination
 * register genuinely differently.
 * `KProgFormal/X86WriteWidthArmShape.lean` proves the generated `armOf` equals
 * an independent width-code ladder, that the case table is exactly the four
 * bodies, and that each body's width code, writeback, case macro, and width
 * class match the architectural width ladder.
 * This header is included after the `X86_WIDTH_*` decodes, so the drift checks
 * bind the hand-written constants to the generated table.
 */
/* The width codes, including the 0 "absent" code. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
/* The number of writeback bodies the macro selects between. */
#define KPROG_X86_WRITE_WIDTH_ARM_COUNT {count}U
{arm_defines}
/*
 * The writeback body a resolved width code selects: the byte/word/dword bodies
 * at their own codes and the qword body at every other code. The input is
 * evaluated once per test.
 */
#define KPROG_X86_WRITE_WIDTH_ARM(CODE)                                     \\
{selector}
_Static_assert(KPROG_X86_WRITE_WIDTH_ARM_COUNT == {count}U,
\t       "x86 write width arm count drift");
_Static_assert({first} != {last},
\t       "x86 write width arm codes must be distinct");
/* The width-code selector must name each body at its own resolved width. */
{width_asserts}
/* The selector is total: no width code is left without a body. */
_Static_assert(KPROG_X86_WRITE_WIDTH_ARM(0) == {last},
\t       "x86 write width absent code must reach the default body");
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
                    f"generated x86 write width contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
