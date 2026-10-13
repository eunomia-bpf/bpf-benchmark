#!/usr/bin/env python3
"""Generate the shared x86-64 ALU-token flag-body-selection contract.

The hand-written `X86_SIM_L_SET_ALU_FLAGS` macro in
`kprog/x86/x86_sim_local_bpf.h` sets the x86 condition flags after an ALU
operation. It was a chain of `if ((ALU) == X86_ALU_*)` tests that selected the
flag body from the operation token (`X86_ALU_*`, the ALU decode), plus the two
flag-preservation side effects the increment/decrement families need:

  * the ADD and ADC codes set the sum flags `X86_SIM_L_SET_ADD_FLAGS(lhs, rhs,
    result, width)`;
  * the INC code sets the *increment* sum flags `X86_SIM_L_SET_ADD_FLAGS(lhs, 1,
    result, width)` and then restores the incoming carry (`__x86_cf`), the
    architectural `INC` carry-preservation;
  * the DEC code sets the *decrement* difference flags
    `X86_SIM_L_SET_SUB_FLAGS(lhs, 1, result, width)` and then restores the
    incoming carry, the architectural `DEC` carry-preservation;
  * the SUB code sets the difference flags `X86_SIM_L_SET_SUB_FLAGS(lhs, rhs,
    result, width)`;
  * the SBB code sets the borrow-difference flags
    `X86_SIM_L_SET_SBB_FLAGS(lhs, rhs, 0, result, width)` (the routed body only
    runs with no incoming borrow; `X86_ALU_ADC` shares the add body here even
    though its outer guard sends it down the carry-sensitive path);
  * the NEG code sets the negated difference flags `X86_SIM_L_SET_SUB_FLAGS(0,
    lhs, result, width)`;
  * the NOT code leaves the flags untouched via `KPROG_X86_PRESERVE_FLAGS()`;
  * the SHL/SHR/SAR/ROL codes set the shift flags
    `X86_SIM_L_SET_SHIFT_FLAGS(lhs, rhs, result, alu, width)`, passing the token
    through so the shift-flag contract takes each family's path;
  * the IMUL code sets the multiply overflow flags
    `X86_SIM_L_SET_IMUL_FLAGS(lhs, rhs, width)` (only `CF`/`OF`; the destination
    result is not consulted);
  * every other code — the bitwise XOR/OR/AND families — sets the logic flags
    `X86_SIM_L_SET_LOGIC_FLAGS(result, width)`.

The final arm is the *default*: every code no earlier family claims reaches the
logic body, so the selector is total over the whole `__u8` token and there is
no unsupported case. The token→body map is not injective: the ADD and ADC codes
both reach the add body, and the SHL/SHR/SAR/ROL codes all reach the shift body.
The generated table `GeneratedX86AluFlagArm.armOf` and the C macro
`KPROG_X86_ALU_FLAG_ARM` name that body for an `X86_ALU_*` token.

The generator is independent of the arm it describes: it holds its own literal
enumeration of the ten flag families, re-derives the live `X86_SIM_L_SET_ALU_FLAGS`
macro text from the simulator header, requires the routed macro to go through
the generated selector, and cross-checks every `X86_ALU_*` token against the
hand-written `x86_alu_decode_spec.json` decode so the arm tokens cannot drift.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_ALU_*` decodes, exactly as the opcode/ALU mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_alu_flag_arm_spec.json"
DECODE_SPEC = ROOT / "x86_alu_decode_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86AluFlagArm.lean"
CHEADER = ROOT / "generated/x86_alu_flag_arm.h"

# The independent enumeration of the ten flag bodies, in selection order:
# (arm, arm define, token codes, token defines, flag body, case macro,
#  carry-flag restore, effect).
_ARMS = [
    ("add", "KPROG_X86_ALU_FLAG_ARM_ADD", [0, 15],
     ["X86_ALU_ADD", "X86_ALU_ADC"], "add_flags",
     "X86_SIM_L_SET_ADD_FLAGS", False, "sum_flags"),
    ("inc", "KPROG_X86_ALU_FLAG_ARM_INC", [10],
     ["X86_ALU_INC"], "add_flags",
     "X86_SIM_L_SET_ADD_FLAGS", True, "increment_flags_preserve_cf"),
    ("dec", "KPROG_X86_ALU_FLAG_ARM_DEC", [13],
     ["X86_ALU_DEC"], "sub_flags",
     "X86_SIM_L_SET_SUB_FLAGS", True, "decrement_flags_preserve_cf"),
    ("sub", "KPROG_X86_ALU_FLAG_ARM_SUB", [1],
     ["X86_ALU_SUB"], "sub_flags",
     "X86_SIM_L_SET_SUB_FLAGS", False, "difference_flags"),
    ("sbb", "KPROG_X86_ALU_FLAG_ARM_SBB", [12],
     ["X86_ALU_SBB"], "sbb_flags",
     "X86_SIM_L_SET_SBB_FLAGS", False, "borrow_difference_flags"),
    ("neg", "KPROG_X86_ALU_FLAG_ARM_NEG", [14],
     ["X86_ALU_NEG"], "sub_flags",
     "X86_SIM_L_SET_SUB_FLAGS", False, "negation_flags"),
    ("not", "KPROG_X86_ALU_FLAG_ARM_NOT", [11],
     ["X86_ALU_NOT"], "preserve_flags",
     "KPROG_X86_PRESERVE_FLAGS", False, "flags_unchanged"),
    ("shift", "KPROG_X86_ALU_FLAG_ARM_SHIFT", [5, 6, 7, 8],
     ["X86_ALU_SHL", "X86_ALU_SHR", "X86_ALU_SAR", "X86_ALU_ROL"], "shift_flags",
     "X86_SIM_L_SET_SHIFT_FLAGS", False, "shift_flags"),
    ("imul", "KPROG_X86_ALU_FLAG_ARM_IMUL", [9],
     ["X86_ALU_IMUL"], "imul_flags",
     "X86_SIM_L_SET_IMUL_FLAGS", False, "multiply_overflow_flags"),
    ("logic", "KPROG_X86_ALU_FLAG_ARM_LOGIC", [2, 3, 4],
     ["X86_ALU_XOR", "X86_ALU_OR", "X86_ALU_AND"], "logic_flags",
     "X86_SIM_L_SET_LOGIC_FLAGS", False, "bitwise_flags_default"),
]
ALU_CODE_BITS = 8
EXPECTED = {
    "schema_version": 1,
    "operation": "x86AluFlagArmSelector",
    "selector": "alu_token_then_flag_body",
    "alu_code_bits": ALU_CODE_BITS,
    "arms": [{"arm": arm, "arm_define": define, "alu_codes": codes,
              "alu_defines": defines, "flag_body": body, "case_macro": macro,
              "cf_restore": restore, "effect": effect}
             for arm, define, codes, defines, body, macro, restore, effect
             in _ARMS],
}
COLUMNS = ("arm", "arm_define", "alu_codes", "alu_defines", "flag_body",
           "case_macro", "cf_restore", "effect")

# The live routed macro text, between the `SET_ALU_FLAGS` macro opener and the
# `EVAL_CC` macro that follows it.
ARM_START = "#define X86_SIM_L_SET_ALU_FLAGS(LHS, RHS, RESULT, ALU, WIDTH)"
ARM_END = "#define X86_SIM_L_EVAL_CC(CC)"
ARM_SELECTOR = "KPROG_X86_ALU_FLAG_ARM((ALU))"
# Needles from the hand-written token ladder that must be gone after routing.
ARM_HAND_LADDER = [
    "X86_ALU_ADD ||", "X86_ALU_SHL ||", "X86_ALU_INC)", "X86_ALU_IMUL)",
    "X86_ALU_NEG)",
]
# The signatures each routed body must still apply, so routing did not drop a
# body's operand shape (the INC/DEC `1`, the NEG `0` lhs, the shift token
# pass-through, the imul result drop, the preserve side effect).
ARM_BODY_SIGNATURES = [
    "X86_SIM_L_SET_ADD_FLAGS((LHS), (RHS), (RESULT), (WIDTH))",
    "X86_SIM_L_SET_ADD_FLAGS((LHS), 1, (RESULT), (WIDTH))",
    "X86_SIM_L_SET_SUB_FLAGS((LHS), 1, (RESULT), (WIDTH))",
    "X86_SIM_L_SET_SUB_FLAGS((LHS), (RHS), (RESULT), (WIDTH))",
    "X86_SIM_L_SET_SUB_FLAGS(0, (LHS), (RESULT), (WIDTH))",
    "X86_SIM_L_SET_SBB_FLAGS((LHS), (RHS), 0, (RESULT), (WIDTH))",
    "X86_SIM_L_SET_SHIFT_FLAGS((LHS), (RHS), (RESULT), (ALU), (WIDTH))",
    "X86_SIM_L_SET_IMUL_FLAGS((LHS), (RHS), (WIDTH))",
    "X86_SIM_L_SET_LOGIC_FLAGS((RESULT), (WIDTH))",
    "KPROG_X86_PRESERVE_FLAGS()",
]


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live ALU-flags macro must route entirely through the generated
    selector and keep every body's operand shape."""
    region = arm_region()
    if ARM_SELECTOR not in region:
        raise SystemExit(
            "x86 alu flag arm does not route through the generated selector")
    for needle in ARM_HAND_LADDER:
        if needle in region:
            raise SystemExit(
                f"x86 alu flag arm still selects {needle!r} by hand")
    for signature in ARM_BODY_SIGNATURES:
        if signature not in region:
            raise SystemExit(
                f"x86 alu flag arm does not route {signature}")
    if "__x86_l_old_cf" not in region:
        raise SystemExit(
            "x86 alu flag arm does not preserve the incoming carry for the "
            "increment/decrement families")
    if "case " not in region or "default:" not in region:
        raise SystemExit(
            "x86 alu flag arm does not dispatch through the selector cases")
    for row in _ARMS[:-1]:
        if row[1] not in region:
            raise SystemExit(
                f"x86 alu flag arm does not name the routed arm {row[1]}")
    if _ARMS[-1][5] not in region:
        raise SystemExit(
            f"x86 alu flag arm default does not route {_ARMS[-1][5]}")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 alu flag arm keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid x86 alu flag arm specification: {data!r}")
    arms = EXPECTED["arms"]
    for index, column in enumerate(COLUMNS):
        want = [row[column] for row in arms]
        got = [entry[index] for entry in _ARMS]
        if want != got:
            raise SystemExit(f"invalid x86 alu flag arm {column}: {arms!r}")
    # Each arm's token codes and defines must line up.
    for row in arms:
        if len(row["alu_codes"]) != len(row["alu_defines"]):
            raise SystemExit(
                f"x86 alu flag arm {row['arm']} code/define length drift")
    # The routed families (everything but the default) must claim disjoint
    # tokens and exactly the tokens the default family does not.
    routed = arms[:-1]
    default = arms[-1]
    routed_codes = [code for row in routed for code in row["alu_codes"]]
    if len(set(routed_codes)) != len(routed_codes):
        raise SystemExit("x86 alu flag arm routed tokens must be distinct")
    if set(routed_codes) & set(default["alu_codes"]):
        raise SystemExit("x86 alu flag arm default tokens overlap the routed ones")
    if set(routed_codes) | set(default["alu_codes"]) != set(range(16)):
        raise SystemExit(
            "x86 alu flag arm does not cover every X86_ALU_* token")
    # The two collapses the token→body map has must be exactly ADD/ADC and the
    # four shifts; the carry-restoring families must be exactly INC and DEC.
    if set(_ARMS[0][2]) != {0, 15}:
        raise SystemExit("x86 alu flag arm add family must be ADD and ADC")
    if set(_ARMS[7][2]) != {5, 6, 7, 8}:
        raise SystemExit(
            "x86 alu flag arm shift family must be SHL/SHR/SAR/ROL")
    if {row["arm"] for row in arms if row["cf_restore"]} != {"inc", "dec"}:
        raise SystemExit(
            "x86 alu flag arm carry-preserving families must be INC and DEC")
    # Cross-check every token against the ALU decode contract, so an arm token
    # cannot drift from the X86_ALU_* decode the simulator uses.
    decode = json.loads(DECODE_SPEC.read_text())
    codes = {row["mnemonic"]: row["code"] for row in decode["operations"]}
    for row in arms:
        for define, code in zip(row["alu_defines"], row["alu_codes"]):
            mnemonic = define[len("X86_ALU_"):].lower()
            if codes.get(mnemonic) != code:
                raise SystemExit(
                    f"x86 alu flag arm token {define} is {code}, but the ALU "
                    f"decode names {codes.get(mnemonic)}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    arms = spec["arms"]
    bits = spec["alu_code_bits"]
    routed = arms[:-1]
    default = arms[-1]
    names = ", ".join(f'"{row["arm"]}"' for row in arms)
    codes = ", ".join(str(index) for index, _row in enumerate(arms))
    ctor = ", ".join(f".{row['arm']}" for row in arms)
    code_of = "\n".join(
        f'  | .{row["arm"]} => {index}' for index, row in enumerate(arms))
    alu_codes = "".join(
        f'  | .{row["arm"]} => [{", ".join(str(c) for c in row["alu_codes"])}]\n'
        for row in arms)
    body_of = "\n".join(
        f'  | .{row["arm"]} => "{row["flag_body"]}"' for row in arms)
    macro_of = "\n".join(
        f'  | .{row["arm"]} => "{row["case_macro"]}"' for row in arms)
    restore_of = "\n".join(
        f'  | .{row["arm"]} => {"true" if row["cf_restore"] else "false"}'
        for row in arms)
    effect_of = "\n".join(
        f'  | .{row["arm"]} => "{row["effect"]}"' for row in arms)
    ladder = "\n".join(
        f'  {"if" if index == 0 else "else if"} alu = {code} then .{row["arm"]}'
        for index, (code, row) in enumerate(
            (code, row) for row in routed for code in row["alu_codes"]))
    return f'''-- Generated by generate_x86_alu_flag_arm_spec.py from x86_alu_flag_arm_spec.json.
import Std
namespace KProgFormal.GeneratedX86AluFlagArm
/-- The flag bodies `X86_SIM_L_SET_ALU_FLAGS` selects between on the
`X86_ALU_*` operation token. -/
inductive Arm where
  | add
  | inc
  | dec
  | sub
  | sbb
  | neg
  | not
  | shift
  | imul
  | logic
deriving DecidableEq, Repr
/-- The number of flag bodies the macro selects between. -/
def armCount : Nat := {len(arms)}
/-- The width in bits of the ALU token the body selects on. -/
def aluCodeBits : Nat := {bits}
/-- The body each arm names, in selection order. -/
def armNames : List String := [{names}]
/-- The arm code of each body, in selection order. -/
def armCodes : List Nat := [{codes}]
/-- The arm code of a body. -/
def codeOfArm : Arm -> Nat
{code_of}
/-- The `X86_ALU_*` token codes each body handles: the sum body at ADD and ADC,
the increment body at INC, the decrement body at DEC, the difference body at
SUB, the borrow-difference body at SBB, the negation body at NEG, the no-op body
at NOT, the shift body at SHL/SHR/SAR/ROL, the multiply body at IMUL, and the
default bitwise body at XOR/OR/AND (the codes no earlier body claims). -/
def aluCodesOfArm : Arm -> List Nat
{alu_codes}/-- The flag block each body applies to the flags. -/
def flagBodyOfArm : Arm -> String
{body_of}
/-- The simulator case macro each body routes through. -/
def caseMacroOfArm : Arm -> String
{macro_of}
/-- Whether the body restores the incoming carry flag after its flag block (the
increment/decrement bodies do; every other body leaves its block's `CF`). -/
def cfRestoreOfArm : Arm -> Bool
{restore_of}
/-- The effect each body performs on the flags. -/
def effectOfArm : Arm -> String
{effect_of}
/-- The flag body a token selects: the add body at the ADD and ADC codes, the
inc body at the inc code, the dec body at the dec code, the sub body at the sub
code, the sbb body at the sbb code, the neg body at the neg code, the not body
at the not code, the shift body at the SHL/SHR/SAR/ROL codes, the imul body at
the imul code, and the logic body at every other code (the XOR/OR/AND default),
so the selector is total over the whole token. -/
def armOf (alu : Nat) : Arm :=
{ladder}
  else .{default["arm"]}
/-- The body a token code names, or `none` when the code names no arm. -/
def armOfCode (code : Nat) : Option Arm :=
  (armCodes.zip [{ctor}]).lookup code
end KProgFormal.GeneratedX86AluFlagArm
'''


def selector_macro(tests: list[tuple[str, str]], default: str) -> str:
    """A token ternary ladder ending in the default arm. Each test is wrapped
    in its own parentheses and continued with a backslash, so the whole
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
    routed = arms[:-1]
    default = arms[-1]
    arm_defines = "\n".join(
        f'#define {row["arm_define"]} {index}U'
        for index, row in enumerate(arms))
    code_asserts = "\n".join(
        f'_Static_assert({define} == {code}U,\n'
        f'\t       "x86 alu flag arm {row["arm"]} token drift");'
        for row in arms
        for define, code in zip(row["alu_defines"], row["alu_codes"]))
    distinct = " && ".join(
        f'{a["arm_define"]} != {b["arm_define"]}'
        for i, a in enumerate(arms) for b in arms[i + 1:])
    tests = [(f'((__u8)((ALU))) == {define}', row["arm_define"])
             for row in routed for define in row["alu_defines"]]
    selector = selector_macro(tests, default["arm_define"])
    select_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_ALU_FLAG_ARM({define}) == '
        f'{row["arm_define"]},\n'
        f'\t       "x86 alu flag arm {row["arm"]} selection drift");'
        for row in routed for define in row["alu_defines"])
    default_asserts = "\n".join(
        f'_Static_assert(KPROG_X86_ALU_FLAG_ARM({define}) == '
        f'{default["arm_define"]},\n'
        f'\t       "x86 alu flag arm default body drift");'
        for define in default["alu_defines"])
    return f'''/* Generated by generate_x86_alu_flag_arm_spec.py from x86_alu_flag_arm_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_ALU_FLAG_ARM_H
#define KPROG_FORMAL_GENERATED_X86_ALU_FLAG_ARM_H
/*
 * x86-64 ALU-token flag-body-selection contract: `X86_SIM_L_SET_ALU_FLAGS`
 * selects between ten flag-setting bodies on the `X86_ALU_*` operation token.
 * The token→body map is not injective: the ADD and ADC codes both reach the add
 * body, and the SHL/SHR/SAR/ROL codes all reach the shift body. The
 * increment/decrement families set their sum/difference flags and then restore
 * the incoming carry (the architectural `INC`/`DEC` carry-preservation); the
 * not family leaves the flags untouched; the multiply family writes only
 * `CF`/`OF`; and the logic family is the default the bitwise XOR/OR/AND codes
 * (and any other token) reach, so the selector is total and there is no
 * unsupported case.
 * `KProgFormal/X86AluFlagArmShape.lean` proves the generated `armOf` equals an
 * independent token ladder built on the ALU contract's own codes, that the
 * token→body map is exactly the ten families with the two collapses, that the
 * increment/decrement families are exactly the carry-restoring ones, and that
 * the case table and the effects cannot drift.
 * This header is included after the `X86_ALU_*` decodes, so the drift checks
 * bind the hand-written constants to the generated table.
 */
/* The number of flag bodies the macro selects between. */
#define KPROG_X86_ALU_FLAG_ARM_COUNT {count}U
{arm_defines}
/*
 * The flag body an `X86_ALU_*` token selects: the bodies above at their own
 * token codes and the logic body at every other code. The input is evaluated
 * once per test.
 */
#define KPROG_X86_ALU_FLAG_ARM(ALU)                                         \\
{selector}
_Static_assert(KPROG_X86_ALU_FLAG_ARM_COUNT == {count}U,
\t       "x86 alu flag arm count drift");
{code_asserts}
_Static_assert({distinct},
\t       "x86 alu flag arm codes must be distinct");
/* The token selector must name each body at its own `X86_ALU_*` codes. */
{select_asserts}
/* The selector is total: the bitwise default body is what every other token
 * reaches. */
{default_asserts}
_Static_assert(KPROG_X86_ALU_FLAG_ARM(0xffU) == {default["arm_define"]},
\t       "x86 alu flag arm unknown token must reach the default body");
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
                    f"generated x86 alu flag arm contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
