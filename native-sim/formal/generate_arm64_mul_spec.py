#!/usr/bin/env python3
"""Generate the shared AArch64 multiply-family contract.

The generated Lean definition `GeneratedArm64Mul.value` and the C macro
`KPROG_ARM64_MUL_VALUE` implement the eight arms applied by the simulator's
multiply handler in `ARM64_SIM_L_EXEC`: multiply-add (MADD), multiply-subtract
(MSUB), multiply (MUL), unsigned multiply long (UMULL), unsigned divide (UDIV),
unsigned multiply high (UMULH), unsigned multiply-add long (UMADDL) and signed
multiply-add long (SMADDL).

Unlike the ALU/shift/modifier/bitfield contracts, the multiply family is not a
decode table: its opcodes are AArch64 `ARM64_OP_*` opcode constants, which are
not contiguous (`0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x2e, 0x3b, 0x40`).  The numeric
case labels in the C macro are therefore those opcode values, spelled per arm
instead of derived from a table index.  `load()` parses `native-sim/arm64/
arm64_sim.h` and exits 1 if any `ARM64_OP_<NAME>` value drifts from the spec, and
the emitted `_Static_assert`s pin the same values at compile time, so the labels
cannot silently diverge from the simulator's opcode numbers.

The multiply family writes no NZCV: the handler stores only the destination
register and never reaches the ADD/SUB/logical flag contract.  `load()`
cross-checks `arm64_flags_spec.json` and exits 1 if any multiply mnemonic is
declared as a flag family, so a multiply flag family cannot be introduced
silently.

The per-arm expressions are the spec's `lean` and `c` strings.  The C macro is
expression-shaped and has one arm per multiply opcode; an opcode outside the
family reaches the caller-supplied unsupported arm.  KPROG_ARM64_MUL_HANDLED
names exactly the eight handled opcodes, which the generator asserts per opcode
and which Lean restates as an opcode-set theorem.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_mul_spec.json"
FLAGS_SPEC = ROOT / "arm64_flags_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64Mul.lean"
CHEADER = ROOT / "generated/arm64_mul.h"

# UMULH is the exact high word of the 128-bit product, computed with four 32x32
# partial products and one carry, exactly like the C helper it replaces. The
# partial products are hoisted so the two operands are used at their full width
# only through explicit 32-bit halves.
UMULH_ARM = [
    "\t\t\t{",
    "\t\t\t\t__u64 __kprog_a64_mul_lo =",
    "\t\t\t\t\t(__u64)(__u32)__kprog_a64_mul_lhs *",
    "\t\t\t\t\t(__u64)(__u32)__kprog_a64_mul_rhs;",
    "\t\t\t\t__u64 __kprog_a64_mul_mid1 =",
    "\t\t\t\t\t(__kprog_a64_mul_lhs >> 32) *",
    "\t\t\t\t\t(__u64)(__u32)__kprog_a64_mul_rhs;",
    "\t\t\t\t__u64 __kprog_a64_mul_mid2 =",
    "\t\t\t\t\t(__u64)(__u32)__kprog_a64_mul_lhs *",
    "\t\t\t\t\t(__kprog_a64_mul_rhs >> 32);",
    "\t\t\t\t__u64 __kprog_a64_mul_hi =",
    "\t\t\t\t\t(__kprog_a64_mul_lhs >> 32) *",
    "\t\t\t\t\t(__kprog_a64_mul_rhs >> 32);",
    "\t\t\t\t__u64 __kprog_a64_mul_carry =",
    "\t\t\t\t\t((__kprog_a64_mul_lo >> 32) +",
    "\t\t\t\t\t (__u64)(__u32)__kprog_a64_mul_mid1 +",
    "\t\t\t\t\t (__u64)(__u32)__kprog_a64_mul_mid2) >> 32;",
    "",
    "\t\t\t\t__kprog_a64_mul_result =",
    "\t\t\t\t\t__kprog_a64_mul_hi + (__kprog_a64_mul_mid1 >> 32) +",
    "\t\t\t\t\t(__kprog_a64_mul_mid2 >> 32) + __kprog_a64_mul_carry;",
    "\t\t\t}",
]

UMULH_LEAN = (
    "(let lhsLo := lhs &&& 0xffffffff; let lhsHi := lhs >>> 32; "
    "let rhsLo := rhs &&& 0xffffffff; let rhsHi := rhs >>> 32; "
    "let lo := lhsLo * rhsLo; let mid1 := lhsHi * rhsLo; "
    "let mid2 := lhsLo * rhsHi; let hi := lhsHi * rhsHi; "
    "let carry := ((lo >>> 32) + (mid1 &&& 0xffffffff) + "
    "(mid2 &&& 0xffffffff)) >>> 32; "
    "hi + (mid1 >>> 32) + (mid2 >>> 32) + carry)"
)

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Mul",
    "operations": [
        {"name": "madd", "code": 10, "macro": "ARM64_OP_MADD",
         "lean": "lhs * rhs + addend",
         "c": "__kprog_a64_mul_lhs * __kprog_a64_mul_rhs + "
              "__kprog_a64_mul_addend"},
        {"name": "msub", "code": 11, "macro": "ARM64_OP_MSUB",
         "lean": "addend - lhs * rhs",
         "c": "__kprog_a64_mul_addend - __kprog_a64_mul_lhs * "
              "__kprog_a64_mul_rhs"},
        {"name": "mul", "code": 12, "macro": "ARM64_OP_MUL",
         "lean": "lhs * rhs",
         "c": "__kprog_a64_mul_lhs * __kprog_a64_mul_rhs"},
        {"name": "umull", "code": 13, "macro": "ARM64_OP_UMULL",
         "lean": "(lhs &&& 0xffffffff) * (rhs &&& 0xffffffff)",
         "c": "(__u64)(__u32)__kprog_a64_mul_lhs * "
              "(__u64)(__u32)__kprog_a64_mul_rhs"},
        {"name": "udiv", "code": 14, "macro": "ARM64_OP_UDIV",
         "lean": "if rhs = 0 then 0 else lhs / rhs",
         "c": "__kprog_a64_mul_rhs ? __kprog_a64_mul_lhs / "
              "__kprog_a64_mul_rhs : 0"},
        {"name": "umulh", "code": 46, "macro": "ARM64_OP_UMULH",
         "lean": UMULH_LEAN, "umulh": True, "c": ""},
        {"name": "umaddl", "code": 59, "macro": "ARM64_OP_UMADDL",
         "lean": "(lhs &&& 0xffffffff) * (rhs &&& 0xffffffff) + addend",
         "c": "(__u64)(__u32)__kprog_a64_mul_lhs * "
              "(__u64)(__u32)__kprog_a64_mul_rhs + "
              "__kprog_a64_mul_addend"},
        {"name": "smaddl", "code": 64, "macro": "ARM64_OP_SMADDL",
         "lean": "(BitVec.signExtend 64 (lhs.setWidth 32)) * "
                 "(BitVec.signExtend 64 (rhs.setWidth 32)) + addend",
         "c": "(__u64)((__s64)(__s32)__kprog_a64_mul_lhs * "
              "(__s64)(__s32)__kprog_a64_mul_rhs + "
              "(__s64)__kprog_a64_mul_addend)"},
    ],
}

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 multiply specification: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["madd", "msub", "mul", "umull", "udiv", "umulh",
                 "umaddl", "smaddl"]:
        raise SystemExit(f"invalid arm64 multiply order: {ops!r}")
    if [row["macro"] for row in ops] != [
            "ARM64_OP_" + row["name"].upper() for row in ops]:
        raise SystemExit(f"invalid arm64 multiply macros: {ops!r}")
    if len({row["code"] for row in ops}) != len(ops):
        raise SystemExit(f"invalid arm64 multiply opcodes: {ops!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    for row in ops:
        if opcodes.get(row["macro"]) != row["code"]:
            raise SystemExit(
                "arm64 multiply opcodes drift from native-sim/arm64/"
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
                f"arm64 multiply operation {row['name']} writes no NZCV but "
                f"the arm64 flag specification declares it as a flag family: "
                f"{families!r}")
    return ops


def render_lean(ops: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in ops)
    opcodes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in ops)
    mnemonics = "\n".join(
        f"  | .{row['name']} => \"{row['name'].upper()}\"" for row in ops)
    arms = "\n".join(f"  | .{row['name']} => {row['lean']}" for row in ops)
    return f'''-- Generated by generate_arm64_mul_spec.py from arm64_mul_spec.json.
namespace KProgFormal.GeneratedArm64Mul
/-- The eight AArch64 multiply-family operations applied by the simulator's
multiply handler. The constructors are named after the ARM64_OP_* opcode each
one carries. -/
inductive Mul where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the operation carries in arm64_sim.h. -/
def code : Mul -> Nat
{opcodes}
/-- The ARM instruction mnemonic of the operation. -/
def mnemonic : Mul -> String
{mnemonics}
/-- Shared AArch64 multiply-family value. `lhs` and `rhs` are the two register
operands; `addend` is the accumulator read only by the multiply-add arms. The
long arms widen the low 32 bits of both operands, zero-extending for the
unsigned ones and sign-extending for SMADDL; UDIV keeps the architectural
divide-by-zero result of zero. -/
def value (op : Mul) (lhs rhs addend : BitVec 64) : BitVec 64 :=
  match op with
{arms}
end KProgFormal.GeneratedArm64Mul
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert(ARM64_OP_{row['name'].upper()} == {row['code']}U, "
        '"arm64 multiply code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((OP) == ARM64_OP_{row['name'].upper()})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_MUL_HANDLED("
        f"ARM64_OP_{row['name'].upper()}), "
        '"arm64 multiply coverage drift");'
        for row in ops)
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_mul_op = (OP);",
        "\t\t__u64 __kprog_a64_mul_lhs = (LHS);",
        "\t\t__u64 __kprog_a64_mul_rhs = (RHS);",
        "\t\t__u64 __kprog_a64_mul_addend = (ADDEND);",
        "\t\t__u64 __kprog_a64_mul_result = 0;",
        "",
        "\t\tswitch (__kprog_a64_mul_op) {",
    ]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        if row.get("umulh"):
            body += UMULH_ARM
        else:
            body.append(f"\t\t\t__kprog_a64_mul_result = {row['c']};")
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_mul_result;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_mul_spec.py from arm64_mul_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MUL_H
#define KPROG_FORMAL_GENERATED_ARM64_MUL_H
/*
 * The eight multiply-family arms are MADD/MSUB (multiply-add and
 * multiply-subtract), MUL, UMULL/UMADDL (unsigned 32x32 widening long
 * multiply, with and without accumulator), SMADDL (signed 32x32 widening
 * multiply-add), UDIV (with the architectural divide-by-zero result of zero)
 * and UMULH (the high word of the full 64x64 product). Every opcode of the
 * family has exactly one arm; an opcode outside the family reaches the
 * caller-supplied unsupported arm.
 */
{codes}
#define KPROG_ARM64_MUL_HANDLED(OP)                                         \\
\t({handled})
{coverage}
/*
 * The numeric case labels 10U, 11U, 12U, 13U, 14U, 46U, 59U and 64U track the
 * ARM64_OP_MADD/MSUB/MUL/UMULL/UDIV/UMULH/UMADDL/SMADDL values defined in
 * native-sim/arm64/arm64_sim.h; the family is not contiguous. This header
 * intentionally does not include arm64_sim.h, so it stays usable standalone;
 * load() re-checks the codes against arm64_sim.h and exits 1 if they drift.
 * LHS, RHS and ADDEND are each evaluated exactly once, and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller applies the destination width
 * afterwards.
 */
#define KPROG_ARM64_MUL_VALUE(OP, LHS, RHS, ADDEND, UNSUPPORTED)            \\
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
                    f"generated arm64 multiply contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()