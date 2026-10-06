#!/usr/bin/env python3
"""Generate the shared AArch64 source-modifier (extend/shift) contract.

The generated Lean definition `GeneratedArm64Mod.value` and the C macro
`KPROG_ARM64_MOD_VALUE` implement the eleven modifier arms applied by the
simulator's `ARM64_SIM_L_MOD_VALUE` macro: the no-op arm plus shift, rotate and
extend arms.

The per-arm expressions are the spec's `lean` and `c` strings.  The eleven
operations and their numeric codes must match the modifier table of
arm64_decode_spec.json exactly, so the numeric case labels in the C macro track
the ARM64_MOD_* constants of the generated arm64_decode.h without including it.

The C macro is expression-shaped and has no unsupported arm: every modifier code
in the table is handled, which the generator asserts per code through
KPROG_ARM64_MOD_HANDLED and which Lean restates as a code-range theorem.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_mod_spec.json"
DECODE_SPEC = ROOT / "arm64_decode_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedArm64Mod.lean"
CHEADER = ROOT / "generated/arm64_mod.h"

# Extra x86-style helper names the generated C does not have; the arms inline
# the rotate so the header stays include-free.
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64Mod",
    "operations": [
        {"name": "none", "code": 0, "lean": "value", "c": ""},
        {"name": "lsl", "code": 1,
         "lean": "(value <<< k) &&& mask width",
         "c": "((__kprog_a64_mod_value << __kprog_a64_mod_amount) & "
              "KPROG_ARM64_WIDTH_MASK(WIDTH))"},
        {"name": "lsr", "code": 2,
         "lean": "(value &&& mask width) >>> k",
         "c": "((__kprog_a64_mod_value & KPROG_ARM64_WIDTH_MASK(WIDTH)) >> "
              "__kprog_a64_mod_amount)"},
        {"name": "asr", "code": 3,
         "lean": "if width = .w32 then BitVec.signExtend 64 "
                 "((value.setWidth 32).sshiftRight' k) else value.sshiftRight' k",
         "asr": True, "c": ""},
        {"name": "ror", "code": 4,
         "lean": "if width = .w32 then (let v := value &&& mask .w32; "
                 "if k = 0 then v else ((v >>> k) ||| (v <<< (32 - k))) &&& mask .w32) "
                 "else if k = 0 then value else (value >>> k) ||| (value <<< (64 - k))",
         "ror": True, "c": ""},
        {"name": "uxtw", "code": 5,
         "lean": "(value &&& 0xffffffff) <<< shift",
         "c": "(((__u64)(__u32)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
        {"name": "sxtw", "code": 6,
         "lean": "(BitVec.signExtend 64 (value.setWidth 32)) <<< shift",
         "c": "(((__u64)(__s64)(__s32)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
        {"name": "uxth", "code": 7,
         "lean": "(value &&& 0xffff) <<< shift",
         "c": "(((__u64)(__u16)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
        {"name": "sxth", "code": 8,
         "lean": "(BitVec.signExtend 64 (value.setWidth 16)) <<< shift",
         "c": "(((__u64)(__s64)(__s16)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
        {"name": "uxtb", "code": 9,
         "lean": "(value &&& 0xff) <<< shift",
         "c": "(((__u64)(__u8)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
        {"name": "sxtb", "code": 10,
         "lean": "(BitVec.signExtend 64 (value.setWidth 8)) <<< shift",
         "c": "(((__u64)(__s64)(__s8)__kprog_a64_mod_value) << "
              "__kprog_a64_mod_shift)"},
    ],
}


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 modifier specification: {data!r}")
    ops = EXPECTED["operations"]
    names = [row["name"] for row in ops]
    if names != ["none", "lsl", "lsr", "asr", "ror",
                 "uxtw", "sxtw", "uxth", "sxth", "uxtb", "sxtb"]:
        raise SystemExit(f"invalid arm64 modifier order: {ops!r}")
    if [row["code"] for row in ops] != list(range(11)):
        raise SystemExit(f"invalid arm64 modifier codes: {ops!r}")
    decode = json.loads(DECODE_SPEC.read_text())
    if (set(decode) != {"schema_version", "operation", "tables"}
            or decode["schema_version"] != 1
            or decode["operation"] != "arm64Decode"):
        raise SystemExit(f"invalid arm64 decode specification: {decode!r}")
    mod_table = decode["tables"]["mod"]
    # The decode table spells the no-op modifier with an empty mnemonic.
    if [tuple(row[key] for key in ("mnemonic", "macro", "code"))
            for row in mod_table] != [
            ("" if row["name"] == "none" else row["name"],
             "ARM64_MOD_" + row["name"].upper(),
             row["code"])
            for row in ops]:
        raise SystemExit(
            "arm64 modifier codes drift from the arm64 decode modifier table: "
            f"spec={[(row['name'], row['code']) for row in ops]} "
            f"decode={[(row['mnemonic'], row['code']) for row in mod_table]}")
    return ops


def render_lean(ops: list[dict]) -> str:
    arms = "\n".join(f"  | .{row['name']} => {row['lean']}" for row in ops)
    return f'''-- Generated by generate_arm64_mod_spec.py from arm64_mod_spec.json.
import KProgFormal.GeneratedArm64Decode
import KProgFormal.GeneratedArm64Width
namespace KProgFormal.GeneratedArm64Mod
open GeneratedArm64ModDecode (Mod)
open GeneratedArm64Width (Width mask)
/-- Shared AArch64 source-modifier value. The match arms follow the generated
Arm64Decode Mod codes; the shift amount `k` is the hardware-masked amount, and
the extend arms apply their shift unmasked exactly like the C macro. -/
def value (mod : Mod) (value : BitVec 64) (shift : BitVec 64)
    (width : Width) : BitVec 64 :=
  let k := shift &&& (if width = .w32 then 31 else 63)
  match mod with
{arms}
end KProgFormal.GeneratedArm64Mod
'''


def render_c(ops: list[dict]) -> str:
    codes = "\n".join(
        f"_Static_assert(ARM64_MOD_{row['name'].upper()} == {row['code']}U, "
        '"arm64 modifier code drift");'
        for row in ops)
    handled = " || \\\n\t".join(
        f"((MOD) == ARM64_MOD_{row['name'].upper()})" for row in ops)
    coverage = "\n".join(
        f"_Static_assert(KPROG_ARM64_MOD_HANDLED(ARM64_MOD_{row['name'].upper()}), "
        '"arm64 modifier coverage drift");'
        for row in ops)
    body = ["\t({",
            "\t\t__u64 __kprog_a64_mod_value = (VALUE);",
            "\t\t__u8 __kprog_a64_mod = (MOD);",
            "\t\t__u8 __kprog_a64_mod_shift = (SHIFT);",
            "\t\t__u8 __kprog_a64_mod_amount =",
            "\t\t\t(__u8)(__kprog_a64_mod_shift &",
            "\t\t\t      ((WIDTH) == ARM64_WIDTH_32 ? 31U : 63U));",
            "",
            "\t\tswitch (__kprog_a64_mod) {"]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:                          ")
        if row.get("asr"):
            body += [
                "\t\t\tif ((WIDTH) == ARM64_WIDTH_32)",
                "\t\t\t\t__kprog_a64_mod_value = (__u64)((__s32)__kprog_a64_mod_value >>",
                "\t\t\t\t\t__kprog_a64_mod_amount);",
                "\t\t\telse",
                "\t\t\t\t__kprog_a64_mod_value = (__u64)((__s64)__kprog_a64_mod_value >>",
                "\t\t\t\t\t__kprog_a64_mod_amount);",
            ]
        elif row.get("ror"):
            body += [
                "\t\t\tif ((WIDTH) == ARM64_WIDTH_32) {",
                "\t\t\t\t__u32 __kprog_a64_mod_w32 = (__u32)__kprog_a64_mod_value;",
                "",
                "\t\t\t\t__kprog_a64_mod_value = __kprog_a64_mod_amount",
                "\t\t\t\t\t? (__u64)((__kprog_a64_mod_w32 >> __kprog_a64_mod_amount) |",
                "\t\t\t\t\t\t  (__kprog_a64_mod_w32 << (32U - __kprog_a64_mod_amount)))",
                "\t\t\t\t\t: (__u64)__kprog_a64_mod_w32;",
                "\t\t\t} else if (__kprog_a64_mod_amount) {",
                "\t\t\t\t__kprog_a64_mod_value =",
                "\t\t\t\t\t(__kprog_a64_mod_value >> __kprog_a64_mod_amount) |",
                "\t\t\t\t\t(__kprog_a64_mod_value << (64U - __kprog_a64_mod_amount));",
                "\t\t\t}",
            ]
        elif row["c"]:
            body.append(f"\t\t\t__kprog_a64_mod_value = {row['c']};")
        body.append("\t\t\tbreak;")
    body += [
        "\t\t}",
        "\t\t__kprog_a64_mod_value;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_mod_spec.py from arm64_mod_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MOD_H
#define KPROG_FORMAL_GENERATED_ARM64_MOD_H
/*
 * The handler is total: every modifier code of the AArch64 modifier table has
 * exactly one arm, including the ARM64_MOD_NONE identity arm, so there is no
 * unsupported arm and no default case.
 */
{codes}
#define KPROG_ARM64_MOD_HANDLED(MOD)                                        \\
\t({handled})
{coverage}
/*
 * The numeric case labels 0U..10U track the ARM64_MOD_* values defined in
 * generated/arm64_decode.h. This header intentionally does not include
 * arm64_decode.h, so it stays usable standalone; load() re-checks the codes
 * against arm64_decode_spec.json and exits 1 if they drift. The extend arms
 * apply SHIFT unmasked like the hardware, so a SHIFT of 64 or more is outside
 * the modelled domain.
 */
#define KPROG_ARM64_MOD_VALUE(MOD, VALUE, SHIFT, WIDTH)                     \\
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
                    f"generated arm64 modifier contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
