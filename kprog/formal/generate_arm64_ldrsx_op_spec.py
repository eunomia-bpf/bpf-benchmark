#!/usr/bin/env python3
"""Generate the shared AArch64 sign-extending-load operand-source contract.

Each of the three load-sign-extend handler arms (`LDRSB`, `LDRSW`, `LDRSH`)
reads a fixed memory width and then sign-extends the loaded value into the
destination. The sign-extension is performed by the shared extract/reverse/
extend contract (formal/generated/arm64_extrev.h), which is keyed on the
sign-extending *opcode*; the load arm therefore has to translate its own load
opcode into the matching sign-extending opcode (`SXTB` for a byte load, `SXTW`
for a word load, `SXTH` for a halfword load) with an inlined ternary

    __u64 sxop = (OP) == ARM64_OP_LDRSB ? ARM64_OP_SXTB :
        (OP) == ARM64_OP_LDRSW ? ARM64_OP_SXTW : ARM64_OP_SXTH;

This contract pins that translation: the derived sign-extending opcode is a
total function of the load opcode, and the sign position it extends from (bit 7,
bit 15, or bit 31) matches the load width. The generated Lean
`GeneratedArm64LdrsxOp.sxCode` and the C macro `KPROG_ARM64_LDRSX_SXOP` return
the `ARM64_OP_SX*` opcode for each load; the six opcode numbers are re-checked
against kprog/arm64/arm64_sim.h, so a drift there fails `--check`.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_ldrsx_op_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64LdrsxOp.lean"
CHEADER = ROOT / "generated/arm64_ldrsx_op.h"

# The live dispatcher arm derives its sign-extending opcode with an inlined
# ternary over the three load opcodes; the derived opcode must come from the
# generated macro instead, and none of the three sign opcodes may still appear
# in the dispatcher body by hand. `signBits` is the bit the load extends from
# (the bit count of the load width), named here for the independent Lean spec.
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64LdrsxOp",
    "loads": [
        {"name": "ldrSb", "code": 54, "macro": "ARM64_OP_LDRSB",
         "sx": {"name": "sxtb", "code": 60, "macro": "ARM64_OP_SXTB"},
         "signBits": 8},
        {"name": "ldrSw", "code": 57, "macro": "ARM64_OP_LDRSW",
         "sx": {"name": "sxtw", "code": 47, "macro": "ARM64_OP_SXTW"},
         "signBits": 32},
        {"name": "ldrSh", "code": 63, "macro": "ARM64_OP_LDRSH",
         "sx": {"name": "sxth", "code": 21, "macro": "ARM64_OP_SXTH"},
         "signBits": 16},
    ],
}

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

# The live dispatcher text, between the `ARM64_SIM_L_EXEC` `#define` and the
# `ARM64_SIM_RUN_OP3` wrapper that follows it.
EXEC_START = "#define ARM64_SIM_L_EXEC(OP"
EXEC_END = "#define ARM64_SIM_RUN_OP3("

# The local wrapper the dispatcher calls, and the generated macro it must
# delegate to with the caller's unsupported arm.
WRAPPER_CALL = "ARM64_SIM_L_LDRSX_SXOP((OP)"
WRAPPER_DEF = (
    "#define ARM64_SIM_L_LDRSX_SXOP(OP)"
    "                                          \\\n"
    "\tKPROG_ARM64_LDRSX_SXOP((OP), ARM64_SIM_L_UNSUPPORTED_OPCODE())")


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def exec_region():
    text = HEADER.read_text()
    start = text.index(EXEC_START)
    end = text.index(EXEC_END, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def check_region(region):
    """The live dispatcher must derive the sign-extending opcode through the
    local wrapper (which delegates to the generated macro), and must not name
    any sign-extending opcode by hand."""
    if WRAPPER_CALL not in region:
        raise SystemExit(
            "arm64 dispatcher does not derive the sign-extending opcode "
            "through the generated selector")
    for row in EXPECTED["loads"]:
        hand = re.compile(r"(?<![A-Z0-9_])" + re.escape(row["sx"]["macro"]) +
                          r"(?![A-Z0-9_])")
        if hand.search(region):
            raise SystemExit(
                "arm64 dispatcher still names the raw sign-extending opcode "
                f"{row['sx']['macro']} by hand")


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid arm64 ldrsx op specification: {data!r}")
    loads = EXPECTED["loads"]
    if [row["name"] for row in loads] != ["ldrSb", "ldrSw", "ldrSh"]:
        raise SystemExit(f"invalid arm64 ldrsx op order: {loads!r}")
    if [row["sx"]["name"] for row in loads] != ["sxtb", "sxtw", "sxth"]:
        raise SystemExit(f"invalid arm64 ldrsx op sign order: {loads!r}")
    if [row["signBits"] for row in loads] != [8, 32, 16]:
        raise SystemExit(f"invalid arm64 ldrsx op sign bits: {loads!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    for row in loads:
        for item in (row, row["sx"]):
            if opcodes.get(item["macro"]) != item["code"]:
                raise SystemExit(
                    "arm64 ldrsx op opcodes drift from "
                    "kprog/arm64/arm64_sim.h: "
                    f"spec={item['macro']}={item['code']:#x} "
                    f"sim={opcodes.get(item['macro'])}")
    if WRAPPER_DEF not in HEADER.read_text():
        raise SystemExit(
            "arm64 ldrsx op wrapper does not delegate to the generated macro")
    check_region(exec_region())
    return loads


def render_lean(loads: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in loads)
    codes = "\n".join(f"  | .{row['name']} => {row['code']}" for row in loads)
    sxcodes = "\n".join(
        f"  | .{row['name']} => {row['sx']['code']}" for row in loads)
    signbits = "\n".join(
        f"  | .{row['name']} => {row['signBits']}" for row in loads)
    return f'''-- Generated by generate_arm64_ldrsx_op_spec.py from arm64_ldrsx_op_spec.json.
import Std
namespace KProgFormal.GeneratedArm64LdrsxOp
/-- The three AArch64 sign-extending load opcodes. -/
inductive LdrSxLoad where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* load opcode number the load carries in arm64_sim.h. -/
def code : LdrSxLoad -> Nat
{codes}
/-- The sign-extending opcode the load's handler must hand to the shared
extract/reverse/extend contract: SXTB for a byte load, SXTW for a word load,
SXTH for a halfword load. This is a total function of the load opcode. -/
def sxCode : LdrSxLoad -> Nat
{sxcodes}
/-- The number of bits the load sign-extends from, fixed by the load width: 8
for LDRSB, 16 for LDRSH, 32 for LDRSW. -/
def signBits : LdrSxLoad -> Nat
{signbits}
end KProgFormal.GeneratedArm64LdrsxOp
'''


def render_c(loads: list[dict]) -> str:
    asserts = []
    for row in loads:
        asserts.append(
            f'_Static_assert({row["macro"]} == {row["code"]}U, '
            '"arm64 ldrsx op load code drift");')
        asserts.append(
            f'_Static_assert({row["sx"]["macro"]} == {row["sx"]["code"]}U, '
            '"arm64 ldrsx op sign code drift");')
    body = [
        "\t({",
        "\t\t__u64 __kprog_a64_ldrsx_sxop = (OP);",
        "\t\t__u64 __kprog_a64_ldrsx_sx = 0;",
        "",
        "\t\tswitch (__kprog_a64_ldrsx_sxop) {",
    ]
    for row in loads:
        body.append(f"\t\tcase {row['code']}U:                          ")
        body.append(
            f"\t\t\t__kprog_a64_ldrsx_sx = {row['sx']['macro']};")
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_a64_ldrsx_sx;",
        "\t})",
    ]
    continued = " \\\n".join(body)
    return f'''/* Generated by generate_arm64_ldrsx_op_spec.py from arm64_ldrsx_op_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_LDRSX_OP_H
#define KPROG_FORMAL_GENERATED_ARM64_LDRSX_OP_H
/*
 * The sign-extending opcode each load-sign-extend arm derives from its load
 * opcode before handing the loaded value to the shared extract/reverse/extend
 * contract: SXTB for LDRSB, SXTW for LDRSW, SXTH for LDRSH. The sign position
 * follows the load width (bit 7, bit 31, bit 15 respectively). An opcode
 * outside the family reaches the caller-supplied unsupported arm.
 */
{chr(10).join(asserts)}
/*
 * The numeric case labels 54U, 57U, and 63U track the ARM64_OP_LDRSB,
 * ARM64_OP_LDRSW, and ARM64_OP_LDRSH values defined in
 * kprog/arm64/arm64_sim.h. OP is the load opcode, read once. The result is the
 * ARM64_OP_SX* opcode the extract/reverse/extend contract sign-extends with.
 */
#define KPROG_ARM64_LDRSX_SXOP(OP, UNSUPPORTED)                             \\
{continued}
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    loads = load()
    outputs = ((LEAN, render_lean(loads)), (CHEADER, render_c(loads)))
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 ldrsx op contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
