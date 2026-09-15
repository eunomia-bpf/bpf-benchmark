#!/usr/bin/env python3
"""Generate the shared AArch64 extract/reverse/extend contract.

The generated Lean definition `GeneratedArm64Extrev.value` and the C macro
`KPROG_ARM64_EXTREV_VALUE` implement the six value handlers the simulator
applies for the AArch64 bit-field extract (`EXTR`), byte reverse (`REV`,
`REV16`) and sign-extend (`SXTB`, `SXTH`, `SXTW`) opcodes:

  * `EXTR` reads two registers (`SRC`, `SRC2`) and the masked immediate shift,
    and produces the low `bits` of the rotate-left of the concatenation
    `SRC : SRC2`.
  * `REV`/`REV16` reverse the byte order of a single register, `REV` over the
    whole width and `REV16` within each 16-bit unit.
  * `SXTB`/`SXTH`/`SXTW` sign-extend the low 8/16/32 bits of a single register.

The opcodes are the raw ARM64_OP_* values of native-sim/arm64/arm64_sim.h and
are not contiguous, so the numeric case labels are the architectural opcode
numbers, which `load()` re-checks against arm64_sim.h and the emitted
`_Static_assert`s pin at compile time.

The C macro evaluates each operand exactly once and writes no NZCV; the result
is the raw 64-bit value and the caller applies the destination width, exactly
like the multiply contract.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_extrev_spec.json"
FLAGS_SPEC = ROOT / "arm64_flags_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64Extrev.lean"
CHEADER = ROOT / "generated/arm64_extrev.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Extrev",
    "operations": [
        {"name": "extr", "code": 17, "macro": "ARM64_OP_EXTR",
         "lean": "(let k := shift &&& (BitVec.ofNat 64 (nb - 1)); "
                 "(src2 >>> k) ||| "
                 "(if k = 0 then 0 else src <<< (BitVec.ofNat 64 nb - k)))"},
        {"name": "rev", "code": 19, "macro": "ARM64_OP_REV",
         "lean": "rev src width"},
        {"name": "rev16", "code": 20, "macro": "ARM64_OP_REV16",
         "lean": "rev16 src width"},
        {"name": "sxth", "code": 21, "macro": "ARM64_OP_SXTH",
         "lean": "signExtend src 16"},
        {"name": "sxtw", "code": 47, "macro": "ARM64_OP_SXTW",
         "lean": "signExtend src 32"},
        {"name": "sxtb", "code": 60, "macro": "ARM64_OP_SXTB",
         "lean": "signExtend src 8"},
    ],
}

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

REV_LEAN = '''/-- C-shaped byte reversal over the destination width. The 32-bit arm reverses
the low four bytes and the 64-bit arm reverses all eight, each as an explicit
shift-and-or ladder. -/
def rev (value : BitVec 64) (width : Width) : BitVec 64 :=
  if width = .w32 then
    (((value &&& 0xff) <<< 24) ||| (((value >>> 8) &&& 0xff) <<< 16) |||
     (((value >>> 16) &&& 0xff) <<< 8) ||| ((value >>> 24) &&& 0xff))
  else
    (((value &&& 0xff) <<< 56) ||| (((value >>> 8) &&& 0xff) <<< 48) |||
     (((value >>> 16) &&& 0xff) <<< 40) ||| (((value >>> 24) &&& 0xff) <<< 32) |||
     (((value >>> 32) &&& 0xff) <<< 24) ||| (((value >>> 40) &&& 0xff) <<< 16) |||
     (((value >>> 48) &&& 0xff) <<< 8) ||| ((value >>> 56) &&& 0xff))

/-- C-shaped byte reversal within each 16-bit unit over the destination width.
The 32-bit arm swaps the two bytes of each 16-bit half of the low word; the
64-bit arm does the same across four halves. -/
def rev16 (value : BitVec 64) (width : Width) : BitVec 64 :=
  if width = .w32 then
    ((value &&& 0x00ff00ff) <<< 8) ||| ((value &&& 0xff00ff00) >>> 8)
  else
    ((value &&& 0x00ff00ff00ff00ff) <<< 8) |||
    ((value &&& 0xff00ff00ff00ff00) >>> 8)

/-- C-shaped sign extension of the low `nb` bits: mask, flip the sign bit, and
subtract it back. -/
def signExtend (value : BitVec 64) (nb : Nat) : BitVec 64 :=
  ((value &&& BitVec.ofNat 64 (2^nb - 1)) ^^^ BitVec.ofNat 64 (2^(nb - 1)))
    - BitVec.ofNat 64 (2^(nb - 1))
'''


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 extract/reverse/extend spec: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["extr", "rev", "rev16", "sxth", "sxtw", "sxtb"]:
        raise SystemExit(f"invalid arm64 extract order: {ops!r}")
    if [row["macro"] for row in ops] != [
            "ARM64_OP_" + row["name"].upper() for row in ops]:
        raise SystemExit(f"invalid arm64 extract macros: {ops!r}")
    if len({row["code"] for row in ops}) != len(ops):
        raise SystemExit(f"invalid arm64 extract opcodes: {ops!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    for row in ops:
        if opcodes.get(row["macro"]) != row["code"]:
            raise SystemExit(
                "arm64 extract opcodes drift from native-sim/arm64/"
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
                f"arm64 extract operation {row['name']} writes no NZCV but the "
                f"arm64 flag specification declares it as a flag family: "
                f"{families!r}")
    return ops


def render_lean(ops: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in ops)
    opcodes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in ops)
    mnemonics = "\n".join(
        f"  | .{row['name']} => \"{row['name'].upper()}\"" for row in ops)
    arms = "\n".join(f"  | .{row['name']} => {row['lean']}" for row in ops)
    return f'''-- Generated by generate_arm64_extrev_spec.py from arm64_extrev_spec.json.
import KProgFormal.GeneratedArm64Width
namespace KProgFormal.GeneratedArm64Extrev
open KProgFormal.GeneratedArm64Width (Width bits)
{REV_LEAN}/-- The six AArch64 extract/reverse/extend operations applied by the simulator's
extract/reverse/extend handler. The constructors are named after the ARM64_OP_*
opcode each one carries. -/
inductive Extrev where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the operation carries in arm64_sim.h. -/
def code : Extrev -> Nat
{opcodes}
/-- The ARM instruction mnemonic of the operation. -/
def mnemonic : Extrev -> String
{mnemonics}
/-- Shared AArch64 extract/reverse/extend value. `src` is the source register
and `src2` is the second source read only by EXTR; `shift` is the EXTR shift
and `width` is the destination width code. EXTR rotates the concatenation
`src : src2` left by the masked shift and keeps the low `bits`; REV/REV16
reverse the byte order over the whole width and within each 16-bit unit; the
SXT arms sign-extend the low 8/16/32 bits. -/
def value (op : Extrev) (src src2 shift : BitVec 64) (width : Width) :
    BitVec 64 :=
  let nb := bits width
  match op with
{arms}
end KProgFormal.GeneratedArm64Extrev
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert(ARM64_OP_{row['name'].upper()} == {row['code']}U, "
        '"arm64 extract code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((OP) == ARM64_OP_{row['name'].upper()})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_EXTREV_HANDLED("
        f"ARM64_OP_{row['name'].upper()}), "
        '"arm64 extract coverage drift");'
        for row in ops)
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_ext_op = (OP);",
        "\t\t__u64 __kprog_a64_ext_src = (SRC);",
        "\t\t__u64 __kprog_a64_ext_src2 = (SRC2);",
        "\t\t__u64 __kprog_a64_ext_shift = (SHIFT);",
        "\t\t__u64 __kprog_a64_ext_width = (WIDTH);",
        "\t\t__u64 __kprog_a64_ext_bits =",
        "\t\t\tKPROG_ARM64_WIDTH_BITS(__kprog_a64_ext_width);",
        "\t\t__u64 __kprog_a64_ext_result = 0;",
        "",
        "\t\tswitch (__kprog_a64_ext_op) {",
    ]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        if row["name"] == "extr":
            body += [
                "\t\t\t__kprog_a64_ext_shift =",
                "\t\t\t\t__kprog_a64_ext_shift & (__kprog_a64_ext_bits - 1);",
                "\t\t\t__kprog_a64_ext_result =",
                "\t\t\t\t(__kprog_a64_ext_src2 >> __kprog_a64_ext_shift) |",
                "\t\t\t\t(__kprog_a64_ext_shift",
                "\t\t\t\t\t? __kprog_a64_ext_src",
                "\t\t\t\t\t  << (__kprog_a64_ext_bits"
                " - __kprog_a64_ext_shift)",
                "\t\t\t\t\t: 0);",
            ]
        elif row["name"] == "rev":
            body += [
                "\t\t\tif (__kprog_a64_ext_width == ARM64_WIDTH_32) {",
                "\t\t\t\t__u32 __kprog_a64_ext_w32 = (__u32)__kprog_a64_ext_src;",
                "",
                "\t\t\t\t__kprog_a64_ext_result =",
                "\t\t\t\t\t((__u64)(__kprog_a64_ext_w32 & 0xffU) << 24) |",
                "\t\t\t\t\t((__u64)((__kprog_a64_ext_w32 >> 8) & 0xffU) << 16) |",
                "\t\t\t\t\t((__u64)((__kprog_a64_ext_w32 >> 16) & 0xffU) << 8) |",
                "\t\t\t\t\t((__u64)((__kprog_a64_ext_w32 >> 24) & 0xffU));",
                "\t\t\t} else {",
                "\t\t\t\t__kprog_a64_ext_result =",
                "\t\t\t\t\t((__kprog_a64_ext_src & 0xffULL) << 56) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 8) & 0xffULL) << 48) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 16) & 0xffULL) << 40) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 24) & 0xffULL) << 32) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 32) & 0xffULL) << 24) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 40) & 0xffULL) << 16) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 48) & 0xffULL) << 8) |",
                "\t\t\t\t\t(((__kprog_a64_ext_src >> 56) & 0xffULL));",
                "\t\t\t}",
            ]
        elif row["name"] == "rev16":
            body += [
                "\t\t\tif (__kprog_a64_ext_width == ARM64_WIDTH_32) {",
                "\t\t\t\t__kprog_a64_ext_result =",
                "\t\t\t\t\t((__kprog_a64_ext_src & 0x00ff00ffULL) << 8) |",
                "\t\t\t\t\t((__kprog_a64_ext_src & 0xff00ff00ULL) >> 8);",
                "\t\t\t} else {",
                "\t\t\t\t__kprog_a64_ext_result =",
                "\t\t\t\t\t((__kprog_a64_ext_src",
                "\t\t\t\t\t  & 0x00ff00ff00ff00ffULL) << 8) |",
                "\t\t\t\t\t((__kprog_a64_ext_src",
                "\t\t\t\t\t  & 0xff00ff00ff00ff00ULL) >> 8);",
                "\t\t\t}",
            ]
        elif row["name"].startswith("sxt"):
            nbits = {"sxtb": 8, "sxth": 16, "sxtw": 32}[row["name"]]
            body += [
                "\t\t\t__kprog_a64_ext_result =",
                f"\t\t\t\t(((__kprog_a64_ext_src & 0x{(1 << nbits) - 1:x}ULL)",
                f"\t\t\t\t  ^ 0x{1 << (nbits - 1):x}ULL)"
                f" - 0x{1 << (nbits - 1):x}ULL);",
            ]
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_ext_result;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_extrev_spec.py from arm64_extrev_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_EXTREV_H
#define KPROG_FORMAL_GENERATED_ARM64_EXTREV_H
/*
 * The six arms are EXTR (extract of a rotated register pair), REV/REV16 (byte
 * reversal over the whole width and within each 16-bit unit) and
 * SXTB/SXTH/SXTW (sign extension of the low 8/16/32 bits). Every opcode of the
 * family has exactly one arm; an opcode outside the family reaches the
 * caller-supplied unsupported arm. All six write no NZCV.
 */
{codes}
#define KPROG_ARM64_EXTREV_HANDLED(OP)                                      \\
\t({handled})
{coverage}
/*
 * The numeric case labels 17U, 19U, 20U, 21U, 47U and 60U track the
 * ARM64_OP_EXTR/REV/REV16/SXTH/SXTW/SXTB values defined in
 * native-sim/arm64/arm64_sim.h; the family is not contiguous. This header
 * intentionally does not include arm64_sim.h, so it stays usable standalone;
 * load() re-checks the codes against arm64_sim.h and exits 1 if they drift.
 * SRC, SRC2 and SHIFT are each evaluated exactly once, and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller applies the destination width
 * afterwards, which is also the architectural narrowing of EXTR. WIDTH is a
 * width code and must be one of ARM64_WIDTH_8/16/32/64.
 */
#define KPROG_ARM64_EXTREV_VALUE(OP, SRC, SRC2, SHIFT, WIDTH, UNSUPPORTED)  \\
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
                    f"generated arm64 extract contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
