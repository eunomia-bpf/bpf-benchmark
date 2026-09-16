#!/usr/bin/env python3
"""Generate the shared AArch64 conditional-select contract.

The generated Lean definition `GeneratedArm64Csel.value` and the C macro
`KPROG_ARM64_CSEL_VALUE` implement the eight value handlers the simulator
applies for the AArch64 conditional-select family. Each takes the already
evaluated condition result (`TAKEN`), the two source registers and the
destination width, and produces the selected value:

  * `CSEL`   selects `SRC` when taken and `SRC2` otherwise;
  * `CINC`   selects `SRC + 1` when taken and `SRC` otherwise;
  * `CSET`   selects `1` when taken and `0` otherwise;
  * `CSETM`  selects all ones when taken and `0` otherwise;
  * `CINV`   selects the complement of `SRC` when taken and `SRC` otherwise;
  * `CSINV`  selects `SRC` when taken and the complement of `SRC2` otherwise;
  * `CSINC`  selects `SRC` when taken and `SRC2 + 1` otherwise;
  * `CSNEG`  selects `SRC` when taken and the negation of `SRC2` otherwise.

The condition itself is the generated `KPROG_ARM64_EVAL_COND` contract, which
`KProgFormal/Arm64ControlFlow.lean` already proves equal to the architectural
condition semantics; this contract composes that predicate with the value
selection. The opcodes are the raw ARM64_OP_* values of
native-sim/arm64/arm64_sim.h and are not contiguous, so the numeric case labels
are the architectural opcode numbers, which `load()` re-checks and the emitted
`_Static_assert`s pin.

The C macro evaluates each operand exactly once and writes no NZCV (the family
only reads flags); the result is the raw 64-bit value and the caller applies the
destination width.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_csel_spec.json"
FLAGS_SPEC = ROOT / "arm64_flags_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64Csel.lean"
CHEADER = ROOT / "generated/arm64_csel.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Csel",
    "operations": [
        {"name": "csel", "code": 28, "macro": "ARM64_OP_CSEL",
         "taken": "src", "not_taken": "src2"},
        {"name": "cinc", "code": 29, "macro": "ARM64_OP_CINC",
         "taken": "src + 1", "not_taken": "src"},
        {"name": "cset", "code": 30, "macro": "ARM64_OP_CSET",
         "taken": "1", "not_taken": "0"},
        {"name": "cinv", "code": 52, "macro": "ARM64_OP_CINV",
         "taken": "~~~src", "not_taken": "src"},
        {"name": "csinv", "code": 61, "macro": "ARM64_OP_CSINV",
         "taken": "src", "not_taken": "~~~src2"},
        {"name": "csinc", "code": 62, "macro": "ARM64_OP_CSINC",
         "taken": "src", "not_taken": "src2 + 1"},
        {"name": "csetm", "code": 68, "macro": "ARM64_OP_CSETM",
         "taken": "~~~(0 : BitVec 64)", "not_taken": "0"},
        {"name": "csneg", "code": 69, "macro": "ARM64_OP_CSNEG",
         "taken": "src", "not_taken": "-src2"},
    ],
}

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

# C expressions for the selected arm, kept separate from the Lean strings so the
# two forms are written independently.
C_TAKEN = {
    "csel": "__kprog_a64_csel_src",
    "cinc": "__kprog_a64_csel_src + 1",
    "cset": "1",
    "cinv": "~__kprog_a64_csel_src",
    "csinv": "__kprog_a64_csel_src",
    "csinc": "__kprog_a64_csel_src",
    "csetm": "~0ULL",
    "csneg": "__kprog_a64_csel_src",
}
C_NOT_TAKEN = {
    "csel": "__kprog_a64_csel_src2",
    "cinc": "__kprog_a64_csel_src",
    "cset": "0",
    "cinv": "__kprog_a64_csel_src",
    "csinv": "~__kprog_a64_csel_src2",
    "csinc": "__kprog_a64_csel_src2 + 1",
    "csetm": "0",
    "csneg": "-__kprog_a64_csel_src2",
}


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 conditional-select spec: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["csel", "cinc", "cset", "cinv", "csinv", "csinc",
                 "csetm", "csneg"]:
        raise SystemExit(f"invalid arm64 conditional-select order: {ops!r}")
    if [row["macro"] for row in ops] != [
            "ARM64_OP_" + row["name"].upper() for row in ops]:
        raise SystemExit(f"invalid arm64 conditional-select macros: {ops!r}")
    if len({row["code"] for row in ops}) != len(ops):
        raise SystemExit(f"invalid arm64 conditional-select opcodes: {ops!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    for row in ops:
        if opcodes.get(row["macro"]) != row["code"]:
            raise SystemExit(
                "arm64 conditional-select opcodes drift from native-sim/arm64/"
                f"arm64_sim.h: spec={row['macro']}={row['code']:#x} "
                f"sim={row['macro']}={opcodes.get(row['macro'])}")
    flags = json.loads(FLAGS_SPEC.read_text())
    if (set(flags) != {"schema_version", "operation", "families",
                       "width_rule", "overflow"}
            or flags["schema_version"] != 1
            or flags["operation"] != "arm64Flags"):
        raise SystemExit(f"invalid arm64 flags specification: {flags!r}")
    families = flags["families"]
    for row in ops:
        if row["name"] in families:
            raise SystemExit(
                f"arm64 conditional-select operation {row['name']} writes no "
                f"NZCV but the arm64 flag specification declares it as a flag "
                f"family: {families!r}")
    return ops


def render_lean(ops: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in ops)
    opcodes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in ops)
    mnemonics = "\n".join(
        f"  | .{row['name']} => \"{row['name'].upper()}\"" for row in ops)
    arms = "\n".join(
        f"  | .{row['name']} => if taken then {row['taken']} "
        f"else {row['not_taken']}" for row in ops)
    return f'''-- Generated by generate_arm64_csel_spec.py from arm64_csel_spec.json.
namespace KProgFormal.GeneratedArm64Csel
/-- The eight AArch64 conditional-select operations applied by the simulator's
conditional-select handler. The constructors are named after the ARM64_OP_*
opcode each one carries. -/
inductive Csel where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the operation carries in arm64_sim.h. -/
def code : Csel -> Nat
{opcodes}
/-- The ARM instruction mnemonic of the operation. -/
def mnemonic : Csel -> String
{mnemonics}
/-- Shared AArch64 conditional-select value. `taken` is the already evaluated
condition result; `src` and `src2` are the two source registers. Each arm keeps
the two candidate values distinct so the selection is the only free operation. -/
def value (op : Csel) (taken : Bool) (src src2 : BitVec 64) : BitVec 64 :=
  match op with
{arms}
end KProgFormal.GeneratedArm64Csel
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert(ARM64_OP_{row['name'].upper()} == {row['code']}U, "
        '"arm64 conditional-select code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((OP) == ARM64_OP_{row['name'].upper()})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_CSEL_HANDLED("
        f"ARM64_OP_{row['name'].upper()}), "
        '"arm64 conditional-select coverage drift");'
        for row in ops)
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_csel_op = (OP);",
        "\t\t__u64 __kprog_a64_csel_src = (SRC);",
        "\t\t__u64 __kprog_a64_csel_src2 = (SRC2);",
        "\t\tint __kprog_a64_csel_taken = (TAKEN) ? 1 : 0;",
        "\t\t__u64 __kprog_a64_csel_result = 0;",
        "",
        "\t\tswitch (__kprog_a64_csel_op) {",
    ]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        body.append("\t\t\t__kprog_a64_csel_result = __kprog_a64_csel_taken")
        body.append(f"\t\t\t\t? {C_TAKEN[row['name']]}")
        body.append(f"\t\t\t\t: {C_NOT_TAKEN[row['name']]};")
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_csel_result;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_csel_spec.py from arm64_csel_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_CSEL_H
#define KPROG_FORMAL_GENERATED_ARM64_CSEL_H
/*
 * The eight arms are the AArch64 conditional-select family (CSEL/CINC/CSET/
 * CSETM/CINV/CSINV/CSINC/CSNEG). Each selects one of the two candidate values
 * on the already evaluated condition result. Every opcode of the family has
 * exactly one arm; an opcode outside the family reaches the caller-supplied
 * unsupported arm. The family reads flags but writes none.
 */
{codes}
#define KPROG_ARM64_CSEL_HANDLED(OP)                                        \\
\t({handled})
{coverage}
/*
 * The numeric case labels 28U, 29U, 30U, 52U, 61U, 62U, 68U and 69U track the
 * ARM64_OP_CSEL/CINC/CSET/CINV/CSINV/CSINC/CSETM/CSNEG values defined in
 * native-sim/arm64/arm64_sim.h; the family is not contiguous. This header
 * intentionally does not include arm64_sim.h, so it stays usable standalone;
 * load() re-checks the codes against arm64_sim.h and exits 1 if they drift.
 * SRC, SRC2 and TAKEN are each evaluated exactly once and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller applies the destination width.
 */
#define KPROG_ARM64_CSEL_VALUE(OP, SRC, SRC2, TAKEN, UNSUPPORTED)           \\
{continued}
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    ops = load()
    for path, expected in ((LEAN, render_lean(ops)), (CHEADER, render_c(ops))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 conditional-select contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
