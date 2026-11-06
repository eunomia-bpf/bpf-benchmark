#!/usr/bin/env python3
"""Generate BZHI flags: count-versus-width CF, result ZF/SF, and clear OF.

Value/count/width selection is checked separately. This contract pins the
flag inputs and checks that the production handler routes through the wrapper.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SPEC = ROOT / "contracts/x86_bzhi_flags_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/Generated/GeneratedX86BzhiFlags.lean"
CHEADER = ROOT / "generated/x86_bzhi_flags.h"

NAMES = ("cf", "zf", "sf", "of")
OPCODES = (("bzhi", "X86_OP_BZHI", 52), ("bzhiMem", "X86_OP_BZHI_MEM", 53))
CF_SOURCE = "masked_count_at_least_width_bits"
ZF_SOURCE = "result_is_zero"
SF_SOURCE = "result_is_negative"
FLAGS = {
    "cf": {"op": "input", "name": "count_at_least_width_bits"},
    "zf": {"op": "input", "name": "result_is_zero"},
    "sf": {"op": "input", "name": "result_is_negative"},
    "of": {"op": "const", "value": False},
}
EXPECTED = {
    "schema_version": 1,
    "operation": "x86BzhiFlags",
    "opcodes": [
        {"name": name, "define": define, "code": code}
        for name, define, code in OPCODES
    ],
    "cf_source": CF_SOURCE,
    "zf_source": ZF_SOURCE,
    "sf_source": SF_SOURCE,
    "flags": FLAGS,
}

# The live BZHI step composition, from its opener to the `X86_SIM_L_EXEC_BZHI`
# wrapper that follows it. The region is one macro: the two thin
# `X86_SIM_L_EXEC_BZHI`/`_BZHI_MEM` wrappers start at `ARM_END`, so narrowing
# there keeps the "exactly one macro" check meaningful.
ARM_START = "#define X86_SIM_L_EXEC_BZHI_STEP("
ARM_END = "#define X86_SIM_L_EXEC_BZHI(DST"
ARM_VALUE = "kprog_x86_bzhi_value("
ARM_FLAG_SET = ("X86_SIM_L_SET_BZHI_FLAGS(__x86_l_count, __x86_l_bits, "
                "__x86_l_result)")
ARM_HAND_FLAGS = "__x86_cf ="

def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def arm_region():
    text = HEADER.read_text()
    start = text.index(ARM_START)
    end = text.index(ARM_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_against_header():
    """The live BZHI step must route its flag block through the generated
    transition and set no flag by hand."""
    region = arm_region()
    if ARM_VALUE not in region:
        raise SystemExit("x86 bzhi step does not compute the masked-clear value")
    if ARM_FLAG_SET not in region:
        raise SystemExit(
            "x86 bzhi step does not route its flag block through the "
            "generated transition")
    if ARM_HAND_FLAGS in region:
        raise SystemExit(
            "x86 bzhi step sets its flags by hand instead of through the "
            "generated transition")
    if flat(region).count("#define") != 1:
        raise SystemExit("x86 bzhi step region is not exactly one macro")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 bzhi flags keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 bzhi flags specification: {data!r}")
    if list(data["flags"]) != list(NAMES):
        raise SystemExit(f"non-canonical x86 bzhi flag list: {data['flags']!r}")
    for expr in data["flags"].values():
        if expr not in ({"op": "const", "value": False},
                        {"op": "input", "name": "count_at_least_width_bits"},
                        {"op": "input", "name": "result_is_zero"},
                        {"op": "input", "name": "result_is_negative"}):
            raise SystemExit(f"invalid x86 bzhi flag expression: {expr!r}")
    inputs = [name for name, expr in data["flags"].items()
              if expr["op"] == "input"]
    if inputs != ["cf", "zf", "sf"]:
        raise SystemExit(
            "x86 bzhi flags must take exactly the count-vs-width CF input and "
            "the result-zero ZF and result-sign SF inputs, in that order")
    check_against_header()
    return EXPECTED


def input_params() -> list:
    """The unique input parameter names, in flag order."""
    seen = []
    for name in NAMES:
        expr_ = FLAGS[name]
        if expr_["op"] == "input" and expr_["name"] not in seen:
            seen.append(expr_["name"])
    return seen


def lean_name(name: str) -> str:
    return name.split("_")[0] + "".join(
        part.title() for part in name.split("_")[1:])


def expr(value, lean):
    if value["op"] == "input":
        return lean_name(value["name"]) if lean else value["name"].upper()
    return ("1" if value["value"] else "0") if not lean else \
        ("true" if value["value"] else "false")


def render_lean(spec: dict) -> str:
    flags = spec["flags"]
    fields = "\n".join(f"  {name} : Bool" for name in NAMES)
    values = ", ".join(f"{name} := {expr(flags[name], True)}" for name in NAMES)
    params = " ".join(f"({lean_name(name)} : Bool)" for name in input_params())
    asserts = "\n".join(
        f'/-- The `{define}` opcode the arm is keyed on. -/\n'
        f'def opcode{name[0].upper()}{name[1:]} : Nat := {code}'
        for name, define, code in OPCODES)
    return f'''-- Generated by generate_x86_bzhi_flags_spec.py from x86_bzhi_flags_spec.json.
import Std
namespace KProgFormal.GeneratedX86BzhiFlags
{asserts}
/-- The width in bits of each opcode the arm selects on. -/
def opcodeBits : Nat := 8
/-- The source the `CF` input is derived from: the byte-masked count reaching
the resolved width's bit count. -/
def cfSource : String := "{spec["cf_source"]}"
/-- The source the `ZF` input is derived from: the cleared result being zero. -/
def zfSource : String := "{spec["zf_source"]}"
/-- The source of SF is the sign of the width-confined result. -/
def sfSource : String := "{spec["sf_source"]}"
/-- BZHI defines CF/ZF/SF and clears OF. -/
structure Flags where
{fields}
  deriving DecidableEq, Repr
/-- Inputs are the count comparison, zero predicate and sign predicate. -/
def eval {params} : Flags := {{ {values} }}
end KProgFormal.GeneratedX86BzhiFlags
'''


def render_c(spec: dict) -> str:
    flags = spec["flags"]
    assigns = " \\\n".join(
        f"\t\t(C_{name.upper()}) = {expr(flags[name], False)};"
        for name in NAMES)
    params = ", ".join(name.upper() for name in input_params())
    asserts = "\n".join(
        f"_Static_assert({define} == {code}U,\n"
        f'\t       "x86 bzhi opcode drift");'
        for name, define, code in OPCODES)
    return f'''/* Generated by generate_x86_bzhi_flags_spec.py from x86_bzhi_flags_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_BZHI_FLAGS_H
#define KPROG_FORMAL_GENERATED_X86_BZHI_FLAGS_H
/* BZHI: CF is count >= width bits, ZF/SF follow the result, OF is clear. */
#define KPROG_X86_SET_BZHI_FLAGS(C_CF, C_ZF, C_SF, C_OF, {params})          \\
\tdo {{ \\
{assigns} \\
\t}} while (0)
{asserts}
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
                    f"generated x86 bzhi flags contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
