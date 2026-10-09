#!/usr/bin/env python3
"""Generate the shared x86-64 `POPCNT` flag-block contract.

The hand-written `X86_OP_POPCNT` arm of `X86_SIM_L_EXEC` in
`kprog/x86/x86_sim_local_bpf.h` computes the population count of the
width-narrowed source and then writes the four arithmetic flags as a block:

  * `CF` is cleared;
  * `OF` is cleared;
  * `SF` is cleared (the instruction does not derive it from the result);
  * `ZF` is set exactly when the width-narrowed source is zero.

The `POPCNT` *value* (`kprog_x86_popcount_value`) is a separate generated
contract (`GeneratedX86Popcount.lean`); this contract covers only the flag
block the arm applies alongside the result. The flag shape is *not* the logical
shape -- `SET_LOGIC_FLAGS` derives `SF` from the result's sign, whereas `POPCNT`
pins `SF` to zero and keys `ZF` on the *source* -- so `POPCNT` gets its own
transition.

The generated C macro `KPROG_X86_SET_POPCNT_FLAGS` names that transition, and
the simulator's `X86_SIM_L_SET_POPCNT_FLAGS` wrapper feeds it the narrowed-source
zero. The generator is independent of the arm it describes: it holds its own
literal flag table and re-derives the live arm text from the simulator header,
then requires the routed arm to go through the wrapper and to set no flag by
hand.

The generated header is included by `x86_sim_local_bpf.h` after the `X86_OP_*`
decodes, exactly as the opcode/ALU mirrors.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_popcnt_flags_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86PopcntFlags.lean"
CHEADER = ROOT / "generated/x86_popcnt_flags.h"

NAMES = ("cf", "zf", "sf", "of")
OPCODE = 24
OPCODE_DEFINE = "X86_OP_POPCNT"
ZERO_SOURCE = "narrowed_source_is_zero"
# The independent flag table: CF, SF, and OF are constant zero; ZF is the one
# input (the narrowed-source zero predicate).
FLAGS = {
    "cf": {"op": "const", "value": False},
    "zf": {"op": "input", "name": "zero"},
    "sf": {"op": "const", "value": False},
    "of": {"op": "const", "value": False},
}
EXPECTED = {
    "schema_version": 1,
    "operation": "x86PopcntFlags",
    "opcode": OPCODE,
    "opcode_define": OPCODE_DEFINE,
    "zero_source": ZERO_SOURCE,
    "flags": FLAGS,
}

# The live POPCNT arm, between its opener and the `SHIFTX` arm.
ARM_START = "} else if ((OP) == X86_OP_POPCNT) {"
ARM_END = "} else if ((OP) == X86_OP_SHIFTX) {"
ARM_OPCODE = "X86_OP_POPCNT"
ARM_VALUE = "x86_popcount64("
ARM_FLAG_SET = "X86_SIM_L_SET_POPCNT_FLAGS(__x86_l_src, __x86_l_width)"
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
    """The live POPCNT arm must route its flag block through the generated
    transition and set no flag by hand."""
    region = arm_region()
    if ARM_OPCODE not in region:
        raise SystemExit("x86 popcnt arm does not name the popcnt opcode")
    if ARM_VALUE not in region:
        raise SystemExit("x86 popcnt arm does not compute the popcount value")
    if ARM_FLAG_SET not in region:
        raise SystemExit(
            "x86 popcnt arm does not route its flag block through the "
            "generated transition")
    if ARM_HAND_FLAGS in region:
        raise SystemExit(
            "x86 popcnt arm sets its flags by hand instead of through the "
            "generated transition")
    if flat(region).count("} else if ((OP) ==") != 1:
        raise SystemExit("x86 popcnt arm region is not exactly one arm")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 popcnt flags keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 popcnt flags specification: {data!r}")
    if list(data["flags"]) != list(NAMES):
        raise SystemExit(f"non-canonical x86 popcnt flag list: {data['flags']!r}")
    for expr in data["flags"].values():
        if expr not in ({"op": "const", "value": False},
                        {"op": "input", "name": "zero"}):
            raise SystemExit(f"invalid x86 popcnt flag expression: {expr!r}")
    inputs = [name for name, expr in data["flags"].items()
              if expr["op"] == "input"]
    if inputs != ["zf"]:
        raise SystemExit(
            "x86 popcnt flags must take exactly the zero input at ZF")
    check_against_header()
    return EXPECTED


def expr(value, lean):
    if value["op"] == "input":
        return value["name"] if lean else value["name"].upper()
    return ("1" if value["value"] else "0") if not lean else \
        ("true" if value["value"] else "false")


def render_lean(spec: dict) -> str:
    flags = spec["flags"]
    fields = "\n".join(f"  {name} : Bool" for name in NAMES)
    values = ", ".join(f"{name} := {expr(flags[name], True)}" for name in NAMES)
    return f'''-- Generated by generate_x86_popcnt_flags_spec.py from x86_popcnt_flags_spec.json.
import Std
namespace KProgFormal.GeneratedX86PopcntFlags
/-- The `X86_OP_POPCNT` opcode the arm is keyed on. -/
def opcode : Nat := {spec["opcode"]}
/-- The width in bits of the opcode the arm selects on. -/
def opcodeBits : Nat := 8
/-- The source the `ZF` input is derived from: the width-narrowed source
operand being zero. -/
def zeroSource : String := "{spec["zero_source"]}"
/-- The four arithmetic flags after an x86 `POPCNT`: `CF`/`SF`/`OF` are cleared
and `ZF` is the narrowed-source zero predicate. -/
structure Flags where
{fields}
  deriving DecidableEq, Repr
/-- The `POPCNT` flag transition: the one input is the narrowed-source zero
predicate, which is exactly `ZF`. -/
def eval (zero : Bool) : Flags := {{ {values} }}
end KProgFormal.GeneratedX86PopcntFlags
'''


def render_c(spec: dict) -> str:
    flags = spec["flags"]
    assigns = " \\\n".join(
        f"\t\t(C_{name.upper()}) = {expr(flags[name], False)};"
        for name in NAMES)
    return f'''/* Generated by generate_x86_popcnt_flags_spec.py from x86_popcnt_flags_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_POPCNT_FLAGS_H
#define KPROG_FORMAL_GENERATED_X86_POPCNT_FLAGS_H
/*
 * x86-64 `POPCNT` flag block: `CF`/`SF`/`OF` are cleared and `ZF` is set
 * exactly when the width-narrowed source operand is zero. Unlike
 * `KPROG_X86_SET_LOGIC_FLAGS`, `SF` is not derived from the result's sign, so
 * this is a distinct transition. The one input `ZERO` is the narrowed-source
 * zero predicate.
 */
#define KPROG_X86_SET_POPCNT_FLAGS(C_CF, C_ZF, C_SF, C_OF, ZERO)            \\
\tdo {{ \\
{assigns} \\
\t}} while (0)
_Static_assert({OPCODE_DEFINE} == {OPCODE}U,
\t       "x86 popcnt opcode drift");
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
                    f"generated x86 popcnt flags contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
