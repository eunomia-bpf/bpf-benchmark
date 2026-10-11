#!/usr/bin/env python3
"""Generate the shared AArch64 dispatch-family opcode-membership contract.

The `ARM64_SIM_L_EXEC` dispatcher of `kprog/arm64/arm64_sim_local_bpf.h` routes
an instruction to its arm through a chain of opcode membership tests. Eight of
those tests select a *pair* of opcodes that share one arm - an immediate form and
a register form - and were written inline as a hand-rolled `||` of two raw
`ARM64_OP_*` comparisons:

    } else if ((OP) == ARM64_OP_SUBS_IMM || (OP) == ARM64_OP_SUBS_REG) {

The families are the operand-pair arms of the ALU, SHIFT, SUBS, ADDS, CMP, TST,
ANDS and CCMP instruction groups. This contract states the membership of each
family as its member opcode set and exposes it as the plain-expression C macro
`KPROG_ARM64_<F>_HANDLED(OP)`, which the dispatcher then tests. It is the same
shape as the already-generated `KPROG_ARM64_EXTREV_HANDLED` /
`KPROG_ARM64_MUL_HANDLED` / `KPROG_ARM64_UNARY_HANDLED` /
`KPROG_ARM64_SHIFT_HANDLED` family gates it now sits beside.

The generator is independent of the dispatcher it describes: it holds its own
literal opcode enumeration and re-derives the live dispatcher text from the
simulator header, then requires every converted gate to test the generated
membership macro and no gate to test the raw `||` pair any more, so a
not-yet-converted gate or a drifted member fails `--check`.

`KProgFormal/Arm64DispatchFamily.lean` proves each generated membership table
equal to an independently written list-membership statement and pins the family
member sets to the opcode numbers `kprog/arm64/arm64_sim.h` defines.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_dispatch_family_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64DispatchFamily.lean"
CHEADER = ROOT / "generated/arm64_dispatch_family.h"

# The eight dispatch families that select an immediate/register opcode pair, in
# dispatcher order, each with the macro the dispatcher tests and its member
# opcodes in the order the live gate tests them. The opcode numbers are the
# ARM64_OP_* codes of kprog/arm64/arm64_sim.h and are re-checked in load().
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64DispatchFamily",
    "families": [
        {"name": "alu", "macro": "KPROG_ARM64_ALU_HANDLED", "members": [
            {"name": "aluImm", "code": 6, "macro": "ARM64_OP_ALU_IMM"},
            {"name": "aluReg", "code": 7, "macro": "ARM64_OP_ALU_REG"}]},
        {"name": "shiftOp", "macro": "KPROG_ARM64_SHIFT_OP_HANDLED", "members": [
            {"name": "shiftImm", "code": 8, "macro": "ARM64_OP_SHIFT_IMM"},
            {"name": "shiftReg", "code": 9, "macro": "ARM64_OP_SHIFT_REG"}]},
        {"name": "subs", "macro": "KPROG_ARM64_SUBS_HANDLED", "members": [
            {"name": "subsImm", "code": 48, "macro": "ARM64_OP_SUBS_IMM"},
            {"name": "subsReg", "code": 50, "macro": "ARM64_OP_SUBS_REG"}]},
        {"name": "adds", "macro": "KPROG_ARM64_ADDS_HANDLED", "members": [
            {"name": "addsImm", "code": 49, "macro": "ARM64_OP_ADDS_IMM"},
            {"name": "addsReg", "code": 66, "macro": "ARM64_OP_ADDS_REG"}]},
        {"name": "cmp", "macro": "KPROG_ARM64_CMP_HANDLED", "members": [
            {"name": "cmpImm", "code": 22, "macro": "ARM64_OP_CMP_IMM"},
            {"name": "cmpReg", "code": 23, "macro": "ARM64_OP_CMP_REG"}]},
        {"name": "tst", "macro": "KPROG_ARM64_TST_HANDLED", "members": [
            {"name": "tstImm", "code": 24, "macro": "ARM64_OP_TST_IMM"},
            {"name": "tstReg", "code": 25, "macro": "ARM64_OP_TST_REG"}]},
        {"name": "ands", "macro": "KPROG_ARM64_ANDS_HANDLED", "members": [
            {"name": "andsReg", "code": 45, "macro": "ARM64_OP_ANDS_REG"},
            {"name": "andsImm", "code": 55, "macro": "ARM64_OP_ANDS_IMM"}]},
        {"name": "ccmp", "macro": "KPROG_ARM64_CCMP_HANDLED", "members": [
            {"name": "ccmpImm", "code": 26, "macro": "ARM64_OP_CCMP_IMM"},
            {"name": "ccmpReg", "code": 27, "macro": "ARM64_OP_CCMP_REG"}]},
    ],
}
FAMILY_NAMES = ["alu", "shiftOp", "subs", "adds", "cmp", "tst", "ands", "ccmp"]

OPCODE_DEFINE = re.compile(
    r"^#define\s+(ARM64_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

# The live dispatcher text, between the `ARM64_SIM_L_EXEC` `#define` and the
# `ARM64_SIM_RUN_OP3` wrapper that follows it.
EXEC_START = "#define ARM64_SIM_L_EXEC(OP"
EXEC_END = "#define ARM64_SIM_RUN_OP3("


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def exec_region():
    return region_between(EXEC_START, EXEC_END)


def check_region(region):
    """The live dispatcher must route each dispatch family through the generated
    membership macro and must not test the raw `||` opcode pair by hand."""
    for row in EXPECTED["families"]:
        needle = f"{row['macro']}(OP)"
        if needle not in region:
            raise SystemExit(
                f"arm64 dispatcher does not route the {row['name']} family "
                f"through the generated membership macro ({needle})")
        hand = " || ".join(f"(OP) == {m['macro']}" for m in row["members"])
        if hand in region:
            raise SystemExit(
                f"arm64 dispatcher still tests the raw {row['name']} opcode "
                f"pair by hand ({hand})")


def check_against_header():
    """The live dispatcher must route every dispatch family through the
    generated membership macros."""
    check_region(exec_region())


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 dispatch family specification: {data!r}")
    families = EXPECTED["families"]
    names = [row["name"] for row in families]
    if names != FAMILY_NAMES:
        raise SystemExit(f"invalid arm64 dispatch family order: {names!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    seen = set()
    for row in families:
        if len(row["members"]) != 2:
            raise SystemExit(
                f"arm64 dispatch family {row['name']} must have exactly two "
                f"members: {row!r}")
        for item in row["members"]:
            if opcodes.get(item["macro"]) != item["code"]:
                raise SystemExit(
                    "arm64 dispatch family opcodes drift from "
                    "kprog/arm64/arm64_sim.h: "
                    f"spec={item['macro']}={item['code']} "
                    f"sim={opcodes.get(item['macro'])}")
            if item["name"] in seen:
                raise SystemExit(
                    f"duplicate arm64 dispatch opcode name: {item['name']!r}")
            seen.add(item["name"])
    check_against_header()
    return families


def render_lean(families: list[dict]) -> str:
    ctors = "\n".join(
        f"  | {item['name']}"
        for row in families for item in row["members"])
    codes = "\n".join(
        f"  | .{item['name']} => {item['code']}"
        for row in families for item in row["members"])
    handled = []
    for row in families:
        disjuncts = " ||\n  ".join(
            f"(op == .{item['name']})" for item in row["members"])
        handled.append(f"/-- Whether the opcode is a member of the {row['name']} "
                       f"dispatch family (`{row['macro']}`). -/\n"
                       f"def {row['name']}Handled (op : DispatchOp) : Bool :=\n"
                       f"  {disjuncts}")
    handled = "\n\n".join(handled)
    return f'''-- Generated by generate_arm64_dispatch_family_spec.py from arm64_dispatch_family_spec.json.
import Std
namespace KProgFormal.GeneratedArm64DispatchFamily
/-- The sixteen AArch64 dispatcher opcodes that form the eight immediate/register
dispatch-family pairs the `ARM64_SIM_L_EXEC` chain tests. -/
inductive DispatchOp where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the dispatcher carries in arm64_sim.h. -/
def code : DispatchOp -> Nat
{codes}
{handled}
end KProgFormal.GeneratedArm64DispatchFamily
'''


def render_c(families: list[dict]) -> str:
    asserts = []
    for row in families:
        for item in row["members"]:
            asserts.append(
                f'_Static_assert({item["macro"]} == {item["code"]}U, '
                '"arm64 dispatch family code drift");')
    macros = []
    for row in families:
        body = " || \\\n\t".join(
            f"((OP) == {item['macro']})" for item in row["members"])
        title = f"#define {row['macro']}(OP)"
        macros.append(f"{title + ' ' * (68 - len(title))}\\\n\t({body})")
    coverage = []
    for row in families:
        for item in row["members"]:
            coverage.append(
                f'_Static_assert({row["macro"]}({item["macro"]}), '
                '"arm64 dispatch family coverage drift");')
    return f'''/* Generated by generate_arm64_dispatch_family_spec.py from arm64_dispatch_family_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_DISPATCH_FAMILY_H
#define KPROG_FORMAL_GENERATED_ARM64_DISPATCH_FAMILY_H
/*
 * The eight AArch64 dispatch families of the `ARM64_SIM_L_EXEC` opcode chain
 * that select an immediate and a register opcode through one arm: ALU, SHIFT,
 * SUBS, ADDS, CMP, TST, ANDS and CCMP. Each family names its member opcode set
 * and exposes it as a plain-expression membership macro, so the dispatcher's
 * family gate is the generated contract rather than a hand-rolled `||` of raw
 * ARM64_OP_* comparisons. A code outside every family reaches the caller's
 * unsupported arm.
 * This header is included after `arm64_sim.h`, so the opcode-number drift
 * checks bind the hand-written ARM64_OP_* decode to the generated member sets.
 */
{chr(10).join(asserts)}
/* Each family's member opcode set, tested by the dispatcher. */
{chr(10).join(macros)}
/* Every family member must be named by its generated membership macro. */
{chr(10).join(coverage)}
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    families = load()
    outputs = ((LEAN, render_lean(families)), (CHEADER, render_c(families)))
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 dispatch family contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
