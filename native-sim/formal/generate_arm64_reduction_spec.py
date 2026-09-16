#!/usr/bin/env python3
"""Generate the shared AArch64 vector-lane reduction (CNT/UADDLV) contract.

The generated Lean definition `GeneratedArm64Reduction.value` and the C macro
`KPROG_ARM64_REDUCTION_VALUE` implement the two byte-lane reductions the
simulator applies to the vector register `v0`:

  - CNT: replace each byte with the number of set bits in that byte, keeping the
    eight results in their own bytes;
  - UADDLV: sum the eight byte values into the low 16 bits.

Both are byte-lane reductions, so the contract is stated over the eight byte
lanes of the 64-bit value and carries the `ARM64_OP_CNT`/`ARM64_OP_UADDLV`
opcode numbers, which `load()` re-checks against native-sim/arm64/arm64_sim.h.

The C macro evaluates the value exactly once and writes no NZCV; the result is
the raw 64-bit value and the caller stores it back into `v0`.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_reduction_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64Reduction.lean"
CHEADER = ROOT / "generated/arm64_reduction.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Reduction",
    "operations": [
        {"name": "cnt", "code": 36, "macro": "ARM64_OP_CNT"},
        {"name": "uaddlv", "code": 37, "macro": "ARM64_OP_UADDLV"},
    ],
}

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

# C bodies. The popcount is written out per byte so the macro calls no
# hand-written helper; the byte lanes are the C `__builtin_popcountll` of a
# masked byte, exactly the value the independent Lean model sums.
C_BODY = {
    "cnt": [
        f"\t\t\t__kprog_a64_red_out |= (__u64)__builtin_popcountll("
        f"(__kprog_a64_red_value >> {8 * i}) & 0xffULL) << {8 * i};"
        for i in range(8)
    ],
    "uaddlv": [
        f"\t\t\t__kprog_a64_red_out += (__kprog_a64_red_value >> {8 * i})"
        f" & 0xffULL;"
        for i in range(8)
    ],
}


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 reduction specification: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["cnt", "uaddlv"]:
        raise SystemExit(f"invalid arm64 reduction order: {ops!r}")
    if [row["macro"] for row in ops] != [
            "ARM64_OP_" + row["name"].upper() for row in ops]:
        raise SystemExit(f"invalid arm64 reduction macros: {ops!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    for row in ops:
        if opcodes.get(row["macro"]) != row["code"]:
            raise SystemExit(
                "arm64 reduction opcodes drift from native-sim/arm64/"
                f"arm64_sim.h: spec={row['macro']}={row['code']:#x} "
                f"sim={row['macro']}={opcodes.get(row['macro'])}")
    return ops


def render_lean(ops: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in ops)
    codes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in ops)
    mnemonics = "\n".join(
        f"  | .{row['name']} => \"{row['name'].upper()}\"" for row in ops)
    arms = {
        # CNT: each byte lane is replaced by that byte's popcount, built
        # additively from the byte's eight bits.
        "cnt": (
            "  | .cnt =>\n"
            "    let b0 := (value >>> 0) &&& 0xff\n"
            "    let b1 := (value >>> 8) &&& 0xff\n"
            "    let b2 := (value >>> 16) &&& 0xff\n"
            "    let b3 := (value >>> 24) &&& 0xff\n"
            "    let b4 := (value >>> 32) &&& 0xff\n"
            "    let b5 := (value >>> 40) &&& 0xff\n"
            "    let b6 := (value >>> 48) &&& 0xff\n"
            "    let b7 := (value >>> 56) &&& 0xff\n"
            "    (popCountBits b0).setWidth 64 |||\n"
            "    ((popCountBits b1).setWidth 64) <<< 8 |||\n"
            "    ((popCountBits b2).setWidth 64) <<< 16 |||\n"
            "    ((popCountBits b3).setWidth 64) <<< 24 |||\n"
            "    ((popCountBits b4).setWidth 64) <<< 32 |||\n"
            "    ((popCountBits b5).setWidth 64) <<< 40 |||\n"
            "    ((popCountBits b6).setWidth 64) <<< 48 |||\n"
            "    ((popCountBits b7).setWidth 64) <<< 56"),
        # UADDLV: sum of the eight byte lanes.
        "uaddlv": (
            "  | .uaddlv =>\n"
            "    let b0 := (value >>> 0) &&& 0xff\n"
            "    let b1 := (value >>> 8) &&& 0xff\n"
            "    let b2 := (value >>> 16) &&& 0xff\n"
            "    let b3 := (value >>> 24) &&& 0xff\n"
            "    let b4 := (value >>> 32) &&& 0xff\n"
            "    let b5 := (value >>> 40) &&& 0xff\n"
            "    let b6 := (value >>> 48) &&& 0xff\n"
            "    let b7 := (value >>> 56) &&& 0xff\n"
            "    b0 + b1 + b2 + b3 + b4 + b5 + b6 + b7"),
    }
    body = "\n".join(arms[row["name"]] for row in ops)
    return f'''-- Generated by generate_arm64_reduction_spec.py from arm64_reduction_spec.json.
import Std
namespace KProgFormal.GeneratedArm64Reduction
/-- Byte-lane popcount: the number of set bits in a byte, built additively from
its eight bits so the value is a plain sum with no popcount primitive. -/
def popCountBits (x : BitVec 64) : BitVec 8 :=
  (x.extractLsb' 0 1).setWidth 8 + (x.extractLsb' 1 1).setWidth 8 +
  (x.extractLsb' 2 1).setWidth 8 + (x.extractLsb' 3 1).setWidth 8 +
  (x.extractLsb' 4 1).setWidth 8 + (x.extractLsb' 5 1).setWidth 8 +
  (x.extractLsb' 6 1).setWidth 8 + (x.extractLsb' 7 1).setWidth 8
/-- The two byte-lane reductions the simulator applies to the vector register. -/
inductive Reduction where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the reduction carries in arm64_sim.h. -/
def code : Reduction -> Nat
{codes}
/-- The AArch64 mnemonic of the reduction. -/
def mnemonic : Reduction -> String
{mnemonics}
/-- Shared AArch64 byte-lane reduction value. CNT replicates each byte's
popcount into that byte; UADDLV sums the eight bytes. -/
def value (op : Reduction) (value : BitVec 64) : BitVec 64 :=
  match op with
{body}
end KProgFormal.GeneratedArm64Reduction
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert({row['macro']} == {row['code']}U, "
        '"arm64 reduction code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((OP) == {row['macro']})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_REDUCTION_HANDLED({row['macro']}), "
        '"arm64 reduction coverage drift");'
        for row in ops)
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_red_op = (OP);",
        "\t\t__u64 __kprog_a64_red_value = (VALUE);",
        "\t\t__u64 __kprog_a64_red_out = 0;",
        "\t\t__u64 __kprog_a64_red_result = 0;",
        "",
        "\t\tswitch (__kprog_a64_red_op) {",
    ]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        body.extend(C_BODY[row["name"]])
        body.append("\t\t\t__kprog_a64_red_result = __kprog_a64_red_out;")
        body.append("\t\t\t__kprog_a64_red_out = 0;")
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_red_result;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_reduction_spec.py from arm64_reduction_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_REDUCTION_H
#define KPROG_FORMAL_GENERATED_ARM64_REDUCTION_H
/*
 * The two arms are the AArch64 byte-lane reductions the simulator applies to
 * the vector register: CNT (per-byte popcount) and UADDLV (sum of the eight
 * bytes). The popcount is written out per byte, so the macro calls no
 * hand-written helper. An opcode outside the two reaches the caller-supplied
 * unsupported arm.
 */
{codes}
#define KPROG_ARM64_REDUCTION_HANDLED(OP)                                   \\
\t({handled})
{coverage}
/*
 * The numeric case labels 36U and 37U track the ARM64_OP_CNT/UADDLV values
 * defined in native-sim/arm64/arm64_sim.h. OP is the opcode, VALUE the vector
 * register contents. VALUE is evaluated exactly once and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller stores it back into v0.
 */
#define KPROG_ARM64_REDUCTION_VALUE(OP, VALUE, UNSUPPORTED)                 \\
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
                    f"generated arm64 reduction contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
