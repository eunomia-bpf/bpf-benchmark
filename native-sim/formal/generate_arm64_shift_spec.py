#!/usr/bin/env python3
"""Generate the shared AArch64 shift (LSL/LSR/ASR/ROR) contract.

The generated Lean definition `GeneratedArm64Shift.value` and the C macro
`KPROG_ARM64_SHIFT_VALUE` implement the four AArch64 shifts the simulator's
`ARM64_OP_SHIFT_IMM`/`ARM64_OP_SHIFT_REG` handler applies to a source register.

The generated form mirrors the existing C helpers: the shift amount is masked to
the width's bit count (31 for 32-bit, 63 otherwise) and the result is narrowed to
the destination width; LSR masks the operand before shifting; ASR shifts in the
destination width's signed domain; ROR rotates the narrowed operand.

The emitted micro kernels use all four shifts at both widths, so the contract
covers the complete shift table and has no unsupported arm: every ARM64_SHIFT_*
code is handled.

The C macro evaluates each operand exactly once and writes no NZCV; the result is
the raw 64-bit value and the caller applies the destination width.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_shift_spec.json"
DECODE_SPEC = ROOT / "arm64_decode_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedArm64Shift.lean"
CHEADER = ROOT / "generated/arm64_shift.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Shift",
    "operations": [
        {"name": "lsl", "code": 0, "macro": "ARM64_SHIFT_LSL"},
        {"name": "lsr", "code": 1, "macro": "ARM64_SHIFT_LSR"},
        {"name": "asr", "code": 2, "macro": "ARM64_SHIFT_ASR"},
        {"name": "ror", "code": 3, "macro": "ARM64_SHIFT_ROR"},
    ],
}

# C bodies for each arm, kept separate from the Lean strings so the two forms are
# written independently. Each is a list of C statements/lines. The rotate arms
# inline the rotation (as the modifier contract does) so the translated header
# stays include-free and calls no hand-written helper.
C_BODY = {
    "lsl": [
        "\t\t\t__kprog_a64_shift_result =",
        "\t\t\t\t(__kprog_a64_shift_value << __kprog_a64_shift_k) &",
        "\t\t\t\t__kprog_a64_shift_wmask;",
    ],
    "lsr": [
        "\t\t\t__kprog_a64_shift_result =",
        "\t\t\t\t(__kprog_a64_shift_value & __kprog_a64_shift_wmask) >>",
        "\t\t\t\t__kprog_a64_shift_k;",
    ],
    "asr": [
        "\t\t\t__kprog_a64_shift_result = __kprog_a64_shift_32",
        "\t\t\t\t? (__u64)((__s32)__kprog_a64_shift_value >> __kprog_a64_shift_k)",
        "\t\t\t\t: (__u64)((__s64)__kprog_a64_shift_value >> __kprog_a64_shift_k);",
    ],
    "ror": [
        "\t\t\tif (__kprog_a64_shift_32) {",
        "\t\t\t\t__u32 __kprog_a64_shift_w32 = (__u32)__kprog_a64_shift_value;",
        "",
        "\t\t\t\t__kprog_a64_shift_result = __kprog_a64_shift_k",
        "\t\t\t\t\t? (__u64)((__kprog_a64_shift_w32 >> __kprog_a64_shift_k) |",
        "\t\t\t\t\t\t  (__kprog_a64_shift_w32 << (32U - __kprog_a64_shift_k)))",
        "\t\t\t\t\t: (__u64)__kprog_a64_shift_w32;",
        "\t\t\t} else {",
        "\t\t\t\t__kprog_a64_shift_result = __kprog_a64_shift_k",
        "\t\t\t\t\t? (__kprog_a64_shift_value >> __kprog_a64_shift_k) |",
        "\t\t\t\t\t  (__kprog_a64_shift_value << (64U - __kprog_a64_shift_k))",
        "\t\t\t\t\t: __kprog_a64_shift_value;",
        "\t\t\t}",
    ],
}


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 shift specification: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["lsl", "lsr", "asr", "ror"]:
        raise SystemExit(f"invalid arm64 shift order: {ops!r}")
    if [row["macro"] for row in ops] != [
            "ARM64_SHIFT_" + row["name"].upper() for row in ops]:
        raise SystemExit(f"invalid arm64 shift macros: {ops!r}")
    if [row["code"] for row in ops] != [0, 1, 2, 3]:
        raise SystemExit(f"invalid arm64 shift codes: {ops!r}")
    # The shift table is owned by arm64_decode_spec.json/arm64_decode.h; the
    # shift contract must agree with it so the C handler's ARM64_SHIFT_* switch
    # tags and the Lean codes cannot drift apart.
    data = json.loads(DECODE_SPEC.read_text())
    table = {row["mnemonic"]: (row["macro"], row["code"])
             for row in data["tables"]["shift"]}
    for row in ops:
        if table.get(row["name"]) != (row["macro"], row["code"]):
            raise SystemExit(
                "arm64 shift codes drift from arm64_decode_spec.json: "
                f"spec={row['name']}={row['code']} "
                f"decode={table.get(row['name'])}")
    return ops


def render_lean(ops: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in ops)
    codes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in ops)
    mnemonics = "\n".join(
        f"  | .{row['name']} => \"{row['name'].upper()}\"" for row in ops)
    arms = {
        "lsl": "    narrow (narrow value width <<< k) width",
        "lsr": "    (value &&& mask width) >>> k",
        "asr": ("    if width = .w32 then\n"
                "      BitVec.signExtend 64 ((value.setWidth 32).sshiftRight' k)\n"
                "    else value.sshiftRight' k"),
        "ror": ("    if width = .w32 then\n"
                "      (let v := value &&& mask .w32\n"
                "       if k = 0 then v\n"
                "       else ((v >>> k) ||| (v <<< (BitVec.ofNat 64 32 - k)))"
                " &&& mask .w32)\n"
                "    else if k = 0 then value\n"
                "    else (value >>> k) ||| (value <<< (BitVec.ofNat 64 64 - k))"),
    }
    body = "\n".join(f"  | .{row['name']} =>\n{arms[row['name']]}"
                     for row in ops)
    return f'''-- Generated by generate_arm64_shift_spec.py from arm64_shift_spec.json.
import Std
import KProgFormal.GeneratedArm64Decode
import KProgFormal.GeneratedArm64Width
namespace KProgFormal.GeneratedArm64Shift
open GeneratedArm64ShiftDecode (Shift)
open GeneratedArm64Width (Width mask narrow)
/-- The shared AArch64 shift value: the four ARM64_SHIFT_* operations applied to
a source register. `k` is the hardware-masked shift amount and the result is
narrowed to the destination width. -/
def value (kind : Shift) (value amount : BitVec 64) (width : Width) :
    BitVec 64 :=
  let k := amount &&& (if width = .w32 then 31 else 63)
  match kind with
{body}
/-- The ARM64_SHIFT_* code of each operation, matching the decode table. -/
def code : Shift -> Nat
{codes}
/-- The AArch64 mnemonic of each shift. -/
def mnemonic : Shift -> String
{mnemonics}
end KProgFormal.GeneratedArm64Shift
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert({row['macro']} == {row['code']}U, "
        '"arm64 shift code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((SHIFT) == {row['macro']})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_SHIFT_HANDLED({row['macro']}), "
        '"arm64 shift coverage drift");'
        for row in ops)
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_shift_op = (SHIFT);",
        "\t\t__u64 __kprog_a64_shift_value = (VALUE);",
        "\t\t__u64 __kprog_a64_shift_amount = (AMOUNT);",
        "\t\t__u64 __kprog_a64_shift_width = (WIDTH);",
        "\t\tint __kprog_a64_shift_32 ="
        " __kprog_a64_shift_width == ARM64_WIDTH_32;",
        "\t\t__u64 __kprog_a64_shift_wmask ="
        " KPROG_ARM64_WIDTH_MASK(__kprog_a64_shift_width);",
        "\t\t__u64 __kprog_a64_shift_k = __kprog_a64_shift_amount &"
        " (__kprog_a64_shift_width == ARM64_WIDTH_32 ? 31ULL : 63ULL);",
        "\t\t__u64 __kprog_a64_shift_result = 0;",
        "",
        "\t\tswitch (__kprog_a64_shift_op) {",
    ]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        body.extend(C_BODY[row["name"]])
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_shift_result;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_shift_spec.py from arm64_shift_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_SHIFT_H
#define KPROG_FORMAL_GENERATED_ARM64_SHIFT_H
/*
 * The four arms are the AArch64 shift family (LSL/LSR/ASR/ROR) applied by the
 * shift handler. Every ARM64_SHIFT_* code has exactly one arm, so the macro is
 * total over SHIFT and no unsupported arm is needed; a code outside the table
 * still reaches the caller-supplied unsupported arm.
 *
 * The rotations are inlined, so this header calls no hand-written helper. It
 * includes the shared width contract for ARM64_WIDTH_32 and
 * KPROG_ARM64_WIDTH_MASK so it is usable standalone.
 */
#include "arm64_width.h"
{codes}
#define KPROG_ARM64_SHIFT_HANDLED(SHIFT)                                    \\
\t({handled})
{coverage}
/*
 * The numeric case labels 0U..3U track the ARM64_SHIFT_LSL/LSR/ASR/ROR values
 * defined in native-sim/arm64/arm64_sim.h. SHIFT is the shift kind, VALUE the
 * source operand, AMOUNT the raw shift amount and WIDTH the destination width
 * code. VALUE and AMOUNT are each evaluated exactly once and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller applies the destination width.
 */
#define KPROG_ARM64_SHIFT_VALUE(SHIFT, VALUE, AMOUNT, WIDTH, UNSUPPORTED)   \\
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
                    f"generated arm64 shift contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
