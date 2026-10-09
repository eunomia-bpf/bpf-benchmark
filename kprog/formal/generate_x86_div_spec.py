#!/usr/bin/env python3
"""Generate the shared x86-64 `DIV` resolved-width case-dispatch contract.

The hand-written `X86_OP_DIV` arm of `X86_SIM_L_EXEC` in
`kprog/x86/x86_sim_local_bpf.h` selects between four quotient/remainder bodies
on the *resolved* operand width (`__x86_l_width`, already the effective width):

  * at the byte width code it divides the low word of `RAX` by the byte divisor
    and packs the quotient into `RAX`'s low byte and the remainder into its
    second byte (one register write, no high-half dividend register);
  * at the word width code it divides the `RDX:AX` pair by the word divisor and
    writes `AX` and `DX` (two writes, `RDX` is the high half);
  * at the dword width code it divides the `RDX:EAX` pair by the dword divisor
    and writes `EAX` and `EDX` (two writes, `RDX` is the high half);
  * at every other code it divides the `RDX:RAX` pair by the qword divisor: as
    the CPU's `DIV` does, when the high half `RDX` is zero it writes the
    quotient to `RAX` and the remainder to `RDX`, and when `RDX` is nonzero it
    traps into the architectural overflow result (`RAX` = all ones, `RDX`
    preserved). This is the one case with a *high-half gate*.

The ladder's final arm is the *default*: it is the body selected by every width
code that is not one of the byte/word/dword codes, so the selector is total
(since `__x86_l_width` is already resolved, absent never reaches it directly,
but the contract is defined for every code). The generated table
`GeneratedX86Div.armOf` and the C macro `KPROG_X86_DIV_ARM` name that case for a
resolved width code.

The generator is independent of the table it describes: it holds its own
literal enumeration and re-derives the live `X86_OP_DIV` arm text from the
simulator header, then requires the routed arm to go through the generated
selector.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_OP_DIV` / `X86_WIDTH_*` decodes, exactly as the opcode mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_div_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86Div.lean"
CHEADER = ROOT / "generated/x86_div.h"

# The independent enumeration of the four cases, in selection order:
# (arm, arm define, width code, write count, dividend high register,
#  high-half gate, effect, width class).
_ARMS = [
    ("b8", "KPROG_X86_DIV_ARM_B8", 1, 1, "none", 0,
     "byte_quotient_packed", "narrow"),
    ("b16", "KPROG_X86_DIV_ARM_B16", 2, 2, "rdx", 0,
     "word_quotient_remainder", "narrow"),
    ("b32", "KPROG_X86_DIV_ARM_B32", 4, 2, "rdx", 0,
     "dword_quotient_remainder", "narrow"),
    ("b64", "KPROG_X86_DIV_ARM_B64", 8, 2, "rdx", 1,
     "qword_quotient_remainder", "full"),
]
WIDTH_CODE_BITS = 8
OPCODE = 26
OPCODE_DEFINE = "X86_OP_DIV"
EXPECTED = {
    "schema_version": 1,
    "operation": "x86DivCaseSelector",
    "selector": "resolved_width_code_then_case",
    "width_code_bits": WIDTH_CODE_BITS,
    "opcode_define": OPCODE_DEFINE,
    "opcode": OPCODE,
    "arms": [{"arm": arm, "arm_define": define, "width_code": code,
              "write_count": writes, "dividend_high": high,
              "high_gate": gate, "effect": effect, "width_class": width_class}
             for arm, define, code, writes, high, gate, effect, width_class
             in _ARMS],
}
COLUMNS = ("arm", "arm_define", "width_code", "write_count", "dividend_high",
           "high_gate", "effect", "width_class")

# The live routed arm text, between the `DIV` arm opener and the `SHLD_IMM` arm.
ARM_START = "} else if ((OP) == X86_OP_DIV) {"
ARM_END = "} else if ((OP) == X86_OP_SHLD_IMM ||"
ARM_SELECTOR = "KPROG_X86_DIV_ARM(__x86_l_width)"
ARM_WIDTH_WRITE = "X86_SIM_L_WRITE_REG_WIDTH"
ARM_HIGH_READ = "X86_SIM_L_READ_REG(X86_RDX)"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live DIV arm must route through the generated width-code selector."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 div arm does not route through the generated selector")
    for _arm, define, _c, _w, _h, _g, _e, _wc in _ARMS[:-1]:
        if define not in region:
            raise SystemExit(
                f"x86 div arm case {define} is not routed")
    if "} else {" not in region:
        raise SystemExit("x86 div default arm is not routed")
    if ARM_WIDTH_WRITE not in region:
        raise SystemExit("x86 div arm has no width write")
    if ARM_HIGH_READ not in region:
        raise SystemExit("x86 div arm does not read the high-half dividend")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 div keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 div specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid x86 div {column}: {arms!r}")
    if [row["write_count"] for row in arms if row["arm"] == "b8"] != [1]:
        raise SystemExit("x86 div byte arm must make exactly one write")
    if any(row["write_count"] != 2 for row in arms if row["arm"] != "b8"):
        raise SystemExit("x86 div wider arms must make two writes")
    if [row["high_gate"] for row in arms if row["high_gate"]] != [1]:
        raise SystemExit("x86 div must name exactly one high-half-gated arm")
    if arms[-1]["high_gate"] != 1:
        raise SystemExit("x86 div default arm must be the high-half-gated one")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["width_code_bits"]
    opcode = spec["opcode"]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}' for index, row in enumerate(arms))
    width_code_of = "\n".join(
        f'  | .{row["arm"]} => {row["width_code"]}' for row in arms)
    write_count_of = "\n".join(
        f'  | .{row["arm"]} => {row["write_count"]}' for row in arms)
    high_of = "\n".join(
        f'  | .{row["arm"]} => "{row["dividend_high"]}"' for row in arms)
    gate_of = "\n".join(
        f'  | .{row["arm"]} => {"true" if row["high_gate"] else "false"}'
        for row in arms)
    effects = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    width_class = "\n".join(
        f'  | .{row["arm"]} => "{row["width_class"]}"' for row in arms)
    ladder = "\n".join(
        f'  {"if" if index == 0 else "else if"} width = {row["width_code"]} '
        f'then .{row["arm"]}'
        for index, row in enumerate(arms[:-1]))
    last = arms[-1]["arm"]
    return f'''-- Generated by generate_x86_div_spec.py from x86_div_spec.json.
import Std
namespace KProgFormal.GeneratedX86Div
/-- The four quotient/remainder bodies the `X86_OP_DIV` arm selects between on
the resolved operand width. -/
inductive Arm where
  | b8
  | b16
  | b32
  | b64
deriving DecidableEq, Repr
/-- The number of quotient/remainder bodies the `X86_OP_DIV` arm selects
between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the resolved width code the arm selects on. -/
def widthCodeBits : Nat := {bits}
/-- The `X86_OP_DIV` opcode the arm implements. -/
def opcode : Nat := {opcode}
/-- The case each resolved width code selects, in selection order. -/
def armNames : List String := [{names}]
/-- The case code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The case code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The resolved width code each body operates at. -/
def widthCodeOfArm : Arm -> Nat
{width_code_of}
/-- The number of register writes each body performs. -/
def writeCountOfArm : Arm -> Nat
{write_count_of}
/-- The high-half dividend register each body consumes, or `"none"` when the
body divides a single register at the byte width. -/
def dividendHighOfArm : Arm -> String
{high_of}
/-- Whether each body gates its split on the high-half dividend register being
zero (the architectural `DIV` overflow gate). -/
def highGateOfArm : Arm -> Bool
{gate_of}
/-- The effect each body performs on the quotient/remainder registers. -/
def effectOfArm : Arm -> String
{effects}
/-- The width class each body operates in. -/
def widthClassOfArm : Arm -> String
{width_class}
/-- The body a resolved width code selects: the byte/word/dword cases at their
own codes and the qword case at every other code, so the selector is total. -/
def armOf (width : Nat) : Arm :=
{ladder}
  else .{last}
/-- The body a case code names, or `none` when the code names no body. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86Div
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
    opcode = spec["opcode"]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    first = arms[0]["arm_define"]
    # The width-coded cases tested in order, each as (condition, arm define).
    tests = [(f'((__u8)((WIDTH))) == X86_WIDTH_{row["width_code"] * 8}',
              row["arm_define"]) for row in arms[:-1]]
    last = arms[-1]["arm_define"]
    selector = selector_macro(tests, last)
    width_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_DIV_ARM(X86_WIDTH_{row["width_code"] * 8}) == '
        f'{row["arm_define"]}, "x86 div width arm drift");'
        for row in arms)
    return f'''/* Generated by generate_x86_div_spec.py from x86_div_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_DIV_H
#define KPROG_FORMAL_GENERATED_X86_DIV_H
/*
 * x86-64 `DIV` resolved-width case-dispatch contract: the `X86_OP_DIV` arm of
 * `X86_SIM_L_EXEC` selects between four quotient/remainder bodies on the
 * resolved operand width. Its ladder is closed over the four X86_WIDTH_* codes:
 * the byte case at the byte code, the word case at the word code, the dword
 * case at the dword code, and the qword case at every other code, so the
 * selector is total and there is no unsupported case. The byte case divides a
 * single register and packs the quotient and remainder into it (one write, no
 * high-half dividend); the wider cases divide the high:low register pair and
 * write both registers, and the qword case alone gates its split on the
 * high-half dividend being zero (the architectural `DIV` overflow gate).
 * `KProgFormal/X86DivHandler.lean` proves the generated `armOf` equals an
 * independent width-code ladder, that the case table is exactly the four
 * bodies, and that each arm's width code, write count, high-half dividend
 * register, and high-half gate match the architectural `DIV` split.
 * This header is included after the `X86_OP_DIV` / `X86_WIDTH_*` decodes, so
 * the drift checks bind the hand-written constants to the generated table.
 */
/* The width codes, including the 0 "absent" code. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
/* The number of quotient/remainder bodies the arm selects between. */
#define KPROG_X86_DIV_ARM_COUNT {count}U
{arm_defines}
/*
 * The body a resolved width code selects: the byte/word/dword cases at their
 * own codes and the qword case at every other code. The input is evaluated
 * once per test.
 */
#define KPROG_X86_DIV_ARM(WIDTH)                                            \\
{selector}
_Static_assert({spec["opcode_define"]} == {opcode}U,
\t       "x86 div opcode drift");
_Static_assert(KPROG_X86_DIV_ARM_COUNT == {count}U,
\t       "x86 div arm count drift");
_Static_assert({first} != {last},
\t       "x86 div arm codes must be distinct");
/* The width-code selector must name each case at its own resolved width. */
{width_asserts}
/* The selector is total: no width code is left without a case. */
_Static_assert(KPROG_X86_DIV_ARM(0) == {last},
\t       "x86 div absent code must reach the default arm");
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
                    f"generated x86 div contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
