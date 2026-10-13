#!/usr/bin/env python3
"""Generate the shared x86-64 dispatch-family opcode-membership contract.

The x86-64 simulator's `X86_SIM_L_EXEC` opcode chain in
`kprog/x86/x86_sim_local_bpf.h` selected a handler for each *group* of opcodes
with a hand-written `(OP) == X86_OP_A || (OP) == X86_OP_B` disjunction. The
same membership list is now a generated contract: this script emits, from
`x86_dispatch_family_spec.json`,

  * `generated/x86_dispatch_family.h` -- one plain-expression membership macro
    `KPROG_X86_<FAMILY>_HANDLED(OP)` per family, plus `_Static_assert`s that pin
    each family member's `X86_OP_*` opcode number (drift check against
    `kprog/x86/x86_sim.h`) and that every named member is accepted by its
    generated macro (coverage check), and
  * `KProgFormal/GeneratedX86DispatchFamily.lean` -- the `DispatchOp` opcode
    enumeration the Lean refinement proofs range over, the opcode-number
    `code` table, and the per-family membership predicates.

`load()` re-parses the live `kprog/x86/x86_sim.h` opcode defines and rejects a
spec whose codes drift from them, and re-reads the live `X86_SIM_L_EXEC` region
so it must route every family through the generated macro and must have dropped
the raw `||` hand gate. `--check` re-reads the committed outputs and rejects
drift without rewriting.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_dispatch_family_spec.json"
SIM_HEADER = ROOT.parent / "x86/x86_sim.h"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86DispatchFamily.lean"
CHEADER = ROOT / "generated/x86_dispatch_family.h"

# The ten dispatch families that select a handler for a *set* of opcodes through
# one arm of the `X86_SIM_L_EXEC` chain, in dispatcher order, each with the
# generated membership macro the dispatcher tests and its member opcodes in the
# order the live gate tests them. The opcode numbers are the X86_OP_* codes of
# kprog/x86/x86_sim.h and are re-checked in load().
EXPECTED = {
    "schema_version": 1,
    "operation": "x86DispatchFamily",
    "families": [
        {"name": "movLoadPtr", "macro": "KPROG_X86_MOV_LOAD_PTR_HANDLED",
         "members": [
             {"name": "movLoadMapPtr", "code": 44,
              "macro": "X86_OP_MOV_LOAD_MAP_PTR"},
             {"name": "movLoadHelperId", "code": 45,
              "macro": "X86_OP_MOV_LOAD_HELPER_ID"}]},
        {"name": "movxReg", "macro": "KPROG_X86_MOVX_REG_HANDLED",
         "members": [
             {"name": "movzxReg", "code": 32, "macro": "X86_OP_MOVZX_REG"},
             {"name": "movsxReg", "code": 33, "macro": "X86_OP_MOVSX_REG"}]},
        {"name": "movLoad", "macro": "KPROG_X86_MOV_LOAD_HANDLED",
         "members": [
             {"name": "movLoad", "code": 6, "macro": "X86_OP_MOV_LOAD"},
             {"name": "movLoadScalar", "code": 37,
              "macro": "X86_OP_MOV_LOAD_SCALAR"},
             {"name": "movsxLoad", "code": 34, "macro": "X86_OP_MOVSX_LOAD"}]},
        {"name": "movStore", "macro": "KPROG_X86_MOV_STORE_HANDLED",
         "members": [
             {"name": "movStoreImm", "code": 7, "macro": "X86_OP_MOV_STORE_IMM"},
             {"name": "movStoreReg", "code": 8,
              "macro": "X86_OP_MOV_STORE_REG"}]},
        {"name": "aluImm", "macro": "KPROG_X86_ALU_IMM_HANDLED",
         "members": [
             {"name": "aluImm", "code": 10, "macro": "X86_OP_ALU_IMM"},
             {"name": "addImm", "code": 3, "macro": "X86_OP_ADD_IMM"}]},
        {"name": "aluReg", "macro": "KPROG_X86_ALU_REG_HANDLED",
         "members": [
             {"name": "aluReg", "code": 11, "macro": "X86_OP_ALU_REG"},
             {"name": "addReg", "code": 4, "macro": "X86_OP_ADD_REG"},
             {"name": "xorReg", "code": 5, "macro": "X86_OP_XOR_REG"}]},
        {"name": "cmpImm", "macro": "KPROG_X86_CMP_IMM_HANDLED",
         "members": [
             {"name": "cmpImm", "code": 12, "macro": "X86_OP_CMP_IMM"},
             {"name": "testImm", "code": 14, "macro": "X86_OP_TEST_IMM"}]},
        {"name": "cmpReg", "macro": "KPROG_X86_CMP_REG_HANDLED",
         "members": [
             {"name": "cmpReg", "code": 13, "macro": "X86_OP_CMP_REG"},
             {"name": "testReg", "code": 15, "macro": "X86_OP_TEST_REG"}]},
        {"name": "cmpMem", "macro": "KPROG_X86_CMP_MEM_HANDLED",
         "members": [
             {"name": "cmpMemImm", "code": 29, "macro": "X86_OP_CMP_MEM_IMM"},
             {"name": "testMemImm", "code": 30,
              "macro": "X86_OP_TEST_MEM_IMM"},
             {"name": "cmpMemReg", "code": 31, "macro": "X86_OP_CMP_MEM_REG"},
             {"name": "testMemReg", "code": 59,
              "macro": "X86_OP_TEST_MEM_REG"}]},
        {"name": "doubleShift", "macro": "KPROG_X86_DOUBLE_SHIFT_HANDLED",
         "members": [
             {"name": "shldImm", "code": 27, "macro": "X86_OP_SHLD_IMM"},
             {"name": "shrdImm", "code": 28, "macro": "X86_OP_SHRD_IMM"}]},
    ],
}
FAMILY_NAMES = ["movLoadPtr", "movxReg", "movLoad", "movStore", "aluImm",
                "aluReg", "cmpImm", "cmpReg", "cmpMem", "doubleShift"]

OPCODE_DEFINE = re.compile(
    r"^#define\s+(X86_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)

# The live dispatcher text, between the `X86_SIM_L_EXEC` `#define` and the
# `X86_SIM_RUN_OP` wrapper that follows it.
EXEC_START = "#define X86_SIM_L_EXEC(OP"
EXEC_END = "#define X86_SIM_RUN_OP(OP"


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
    membership macro and must not test the raw `||` opcode set by hand."""
    for row in EXPECTED["families"]:
        needle = f"{row['macro']}(OP)"
        if needle not in region:
            raise SystemExit(
                f"x86 dispatcher does not route the {row['name']} family "
                f"through the generated membership macro ({needle})")
        hand = " || ".join(f"(OP) == {m['macro']}" for m in row["members"])
        if hand in region:
            raise SystemExit(
                f"x86 dispatcher still tests the raw {row['name']} opcode "
                f"set by hand ({hand})")


def check_against_header():
    """The live dispatcher must route every dispatch family through the
    generated membership macros."""
    check_region(exec_region())


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(
            f"invalid x86 dispatch family specification: {data!r}")
    families = EXPECTED["families"]
    names = [row["name"] for row in families]
    if names != FAMILY_NAMES:
        raise SystemExit(f"invalid x86 dispatch family order: {names!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no X86_OP_* opcode definitions found in {SIM_HEADER}")
    seen = set()
    for row in families:
        if len(row["members"]) < 2:
            raise SystemExit(
                f"x86 dispatch family {row['name']} must have two or more "
                f"members: {row!r}")
        for item in row["members"]:
            if opcodes.get(item["macro"]) != item["code"]:
                raise SystemExit(
                    "x86 dispatch family opcodes drift from "
                    "kprog/x86/x86_sim.h: "
                    f"spec={item['macro']}={item['code']} "
                    f"sim={opcodes.get(item['macro'])}")
            if item["name"] in seen:
                raise SystemExit(
                    f"duplicate x86 dispatch opcode name: {item['name']!r}")
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
    n_ops = sum(len(row["members"]) for row in families)
    return f'''-- Generated by generate_x86_dispatch_family_spec.py from x86_dispatch_family_spec.json.
import Std
namespace KProgFormal.GeneratedX86DispatchFamily
/-- The {n_ops} x86-64 dispatcher opcodes that form the ten dispatch
families. -/
inductive DispatchOp where
{ctors}
deriving DecidableEq, Repr
/-- The X86_OP_* opcode number the dispatcher carries in x86_sim.h. -/
def code : DispatchOp -> Nat
{codes}
{handled}
end KProgFormal.GeneratedX86DispatchFamily
'''


def render_c(families: list[dict]) -> str:
    asserts = []
    for row in families:
        for item in row["members"]:
            asserts.append(
                f'_Static_assert({item["macro"]} == {item["code"]}U, '
                '"x86 dispatch family code drift");')
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
                '"x86 dispatch family coverage drift");')
    return f'''/* Generated by generate_x86_dispatch_family_spec.py from x86_dispatch_family_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_DISPATCH_FAMILY_H
#define KPROG_FORMAL_GENERATED_X86_DISPATCH_FAMILY_H
/*
 * The ten x86-64 dispatch families of the `X86_SIM_L_EXEC` opcode chain that
 * select a handler for a set of opcodes through one arm: the map-pointer/
 * helper-id load pair, the MOVZX/MOVSX register pair, the MOV_LOAD family, the
 * MOV_STORE pair, the ALU-immediate pair, the ALU-register triple, the CMP/TEST
 * immediate pair, the CMP/TEST register pair, the CMP/TEST memory quad, and the
 * SHLD/SHRD immediate pair. Each family names its member opcode set and exposes
 * it as a plain-expression membership macro, so the dispatcher's family gate is
 * the generated contract rather than a hand-rolled `||` of raw X86_OP_*
 * comparisons. A code outside every family reaches the caller's unsupported
 * arm.
 * This header is included after `x86_sim.h`, so the opcode-number drift checks
 * bind the hand-written X86_OP_* decode to the generated member sets.
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
                    f"generated x86 dispatch family contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
