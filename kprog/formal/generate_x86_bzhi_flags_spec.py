#!/usr/bin/env python3
"""Generate the shared x86-64 `BZHI`/`BZHI_MEM` flag-block contract.

The hand-written `X86_SIM_L_EXEC_BZHI_STEP` composition in
`kprog/x86/x86_sim_local_bpf.h` clears the source's bits at or above the
byte-masked count and then writes the four arithmetic flags as a block:

  * `CF` is the byte-masked count reaching the *width's* bit count
    (`count >= bits`), a real comparison against the resolved width;
  * `OF` is cleared;
  * `SF` is cleared (the instruction does not derive it from the result);
  * `ZF` is the real zero test of the *cleared result*.

The `BZHI` *value* (`kprog_x86_bzhi_value`) and the value/count/width selection
are separate generated contracts (`GeneratedX86Bzhi.lean`); this contract
covers only the flag block the step applies alongside the result. The flag
shape is not the logical shape -- `SET_LOGIC_FLAGS` derives `SF` from the
result's sign and `CF` from a borrow, whereas `BZHI` pins `SF`/`OF` to zero,
keys `ZF` on the result, and keys `CF` on the count-versus-width comparison --
so `BZHI` gets its own transition. Unlike `POPCNT`, whose single flag input is
the source-zero predicate, `BZHI` takes *two* inputs: the count-versus-width
`CF` and the result-zero `ZF`.

The generated C macro `KPROG_X86_SET_BZHI_FLAGS` names that transition, and the
simulator's `X86_SIM_L_SET_BZHI_FLAGS` wrapper feeds it the byte-masked count,
the resolved width's bit count, and the cleared result. The generator is
independent of the arm it describes: it holds its own literal flag table and
re-derives the live step text from the simulator header, then requires the
routed step to go through the wrapper and to set no flag by hand.

The generated header is included by `x86_sim_local_bpf.h` alongside the other
`X86_OP_*` mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_bzhi_flags_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86BzhiFlags.lean"
CHEADER = ROOT / "generated/x86_bzhi_flags.h"

NAMES = ("cf", "zf", "sf", "of")
OPCODES = (("bzhi", "X86_OP_BZHI", 52), ("bzhiMem", "X86_OP_BZHI_MEM", 53))
CF_SOURCE = "masked_count_at_least_width_bits"
ZF_SOURCE = "result_is_zero"
# The independent flag table: SF and OF are constant zero; CF and ZF are the two
# inputs (the count-versus-width comparison and the result-zero predicate).
FLAGS = {
    "cf": {"op": "input", "name": "count_at_least_width_bits"},
    "zf": {"op": "input", "name": "result_is_zero"},
    "sf": {"op": "const", "value": False},
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
                        {"op": "input", "name": "result_is_zero"}):
            raise SystemExit(f"invalid x86 bzhi flag expression: {expr!r}")
    inputs = [name for name, expr in data["flags"].items()
              if expr["op"] == "input"]
    if inputs != ["cf", "zf"]:
        raise SystemExit(
            "x86 bzhi flags must take exactly the count-vs-width CF input and "
            "the result-zero ZF input, in that order")
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
/-- The four arithmetic flags after an x86 `BZHI`/`BZHI_MEM`: `SF`/`OF` are
cleared, `CF` is the count-versus-width comparison, and `ZF` is the result-zero
predicate. -/
structure Flags where
{fields}
  deriving DecidableEq, Repr
/-- The `BZHI` flag transition: the two inputs are the count-versus-width
comparison (`CF`) and the result-zero predicate (`ZF`). -/
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
/*
 * x86-64 `BZHI`/`BZHI_MEM` flag block: `SF`/`OF` are cleared, `CF` is set
 * exactly when the byte-masked count reaches the resolved width's bit count,
 * and `ZF` is set exactly when the cleared result is zero. Unlike
 * `KPROG_X86_SET_LOGIC_FLAGS`, `SF` is not derived from the result's sign and
 * `CF` is not a borrow, so this is a distinct transition. The two inputs are
 * `{input_params()[0].upper()}` and `{input_params()[1].upper()}`.
 */
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
