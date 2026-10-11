#!/usr/bin/env python3
"""Generate the shared AArch64 dispatch-singleton opcode-membership contract.

The `ARM64_SIM_L_EXEC` opcode chain still tests sixteen opcodes with a bare
`(OP) == ARM64_OP_X` gate: NOP, MOVK, BITFIELD, CMN_IMM, CMN_REG, TST_BIC_REG,
BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0, STORE_D0, LOAD_Q0, STORE_Q0 and FMOV.
This contract names each one in a shared spec and generates a one-member
membership macro (`KPROG_ARM64_DISP_<NAME>_HANDLED(OP)`), so the dispatcher's
gate is the generated contract rather than a hand-rolled raw comparison, and so
the opcode number is pinned to kprog/arm64/arm64_sim.h in one place.

Given `--check` the generator verifies the checked-in header and Lean module are
exactly what the spec renders and does not rewrite them.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_dispatch_singleton_spec.json"
SIM_HEADER = ROOT.parent / "arm64/arm64_sim.h"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64DispatchSingleton.lean"
CHEADER = ROOT / "generated/arm64_dispatch_singleton.h"

# The sixteen opcodes the `ARM64_SIM_L_EXEC` chain still gates with a bare
# `(OP) == ARM64_OP_X` comparison, in dispatcher order, each with the generated
# membership macro the dispatcher tests. The opcode numbers are the ARM64_OP_*
# codes of kprog/arm64/arm64_sim.h and are re-checked in load().
EXPECTED = {
    "schema_version": 1,
    "operation": "arm64DispatchSingleton",
    "singletons": [
        {"name": "nop", "code": 0, "op_macro": "ARM64_OP_NOP",
         "gate_macro": "KPROG_ARM64_DISP_NOP_HANDLED"},
        {"name": "movk", "code": 5, "op_macro": "ARM64_OP_MOVK",
         "gate_macro": "KPROG_ARM64_DISP_MOVK_HANDLED"},
        {"name": "bitfield", "code": 18, "op_macro": "ARM64_OP_BITFIELD",
         "gate_macro": "KPROG_ARM64_DISP_BITFIELD_HANDLED"},
        {"name": "cmnImm", "code": 51, "op_macro": "ARM64_OP_CMN_IMM",
         "gate_macro": "KPROG_ARM64_DISP_CMN_IMM_HANDLED"},
        {"name": "cmnReg", "code": 58, "op_macro": "ARM64_OP_CMN_REG",
         "gate_macro": "KPROG_ARM64_DISP_CMN_REG_HANDLED"},
        {"name": "tstBicReg", "code": 44, "op_macro": "ARM64_OP_TST_BIC_REG",
         "gate_macro": "KPROG_ARM64_DISP_TST_BIC_REG_HANDLED"},
        {"name": "bicsReg", "code": 67, "op_macro": "ARM64_OP_BICS_REG",
         "gate_macro": "KPROG_ARM64_DISP_BICS_REG_HANDLED"},
        {"name": "load", "code": 31, "op_macro": "ARM64_OP_LOAD",
         "gate_macro": "KPROG_ARM64_DISP_LOAD_HANDLED"},
        {"name": "store", "code": 32, "op_macro": "ARM64_OP_STORE",
         "gate_macro": "KPROG_ARM64_DISP_STORE_HANDLED"},
        {"name": "ldp", "code": 33, "op_macro": "ARM64_OP_LDP",
         "gate_macro": "KPROG_ARM64_DISP_LDP_HANDLED"},
        {"name": "stp", "code": 34, "op_macro": "ARM64_OP_STP",
         "gate_macro": "KPROG_ARM64_DISP_STP_HANDLED"},
        {"name": "loadD0", "code": 40, "op_macro": "ARM64_OP_LOAD_D0",
         "gate_macro": "KPROG_ARM64_DISP_LOAD_D0_HANDLED"},
        {"name": "storeD0", "code": 41, "op_macro": "ARM64_OP_STORE_D0",
         "gate_macro": "KPROG_ARM64_DISP_STORE_D0_HANDLED"},
        {"name": "loadQ0", "code": 42, "op_macro": "ARM64_OP_LOAD_Q0",
         "gate_macro": "KPROG_ARM64_DISP_LOAD_Q0_HANDLED"},
        {"name": "storeQ0", "code": 43, "op_macro": "ARM64_OP_STORE_Q0",
         "gate_macro": "KPROG_ARM64_DISP_STORE_Q0_HANDLED"},
        {"name": "fmov", "code": 35, "op_macro": "ARM64_OP_FMOV",
         "gate_macro": "KPROG_ARM64_DISP_FMOV_HANDLED"},
    ],
}
SINGLETON_NAMES = ["nop", "movk", "bitfield", "cmnImm", "cmnReg", "tstBicReg",
                   "bicsReg", "load", "store", "ldp", "stp", "loadD0",
                   "storeD0", "loadQ0", "storeQ0", "fmov"]

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
    """The live dispatcher must route each singleton opcode through the generated
    membership macro and must not test the raw opcode by hand."""
    for row in EXPECTED["singletons"]:
        needle = f"{row['gate_macro']}(OP)"
        if needle not in region:
            raise SystemExit(
                f"arm64 dispatcher does not route the {row['name']} opcode "
                f"through the generated membership macro ({needle})")
        hand = re.compile(r"\(OP\)\s*==\s*" + re.escape(row["op_macro"]) +
                          r"(?![A-Z0-9_])")
        if hand.search(region):
            raise SystemExit(
                f"arm64 dispatcher still tests the raw {row['name']} opcode "
                f"by hand ((OP) == {row['op_macro']})")


def check_against_header():
    check_region(exec_region())


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 dispatch singleton specification: {data!r}")
    singletons = EXPECTED["singletons"]
    names = [row["name"] for row in singletons]
    if names != SINGLETON_NAMES:
        raise SystemExit(
            f"invalid arm64 dispatch singleton order: {names!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no ARM64_OP_* opcode definitions found in {SIM_HEADER}")
    seen = set()
    for row in singletons:
        if opcodes.get(row["op_macro"]) != row["code"]:
            raise SystemExit(
                "arm64 dispatch singleton opcodes drift from "
                "kprog/arm64/arm64_sim.h: "
                f"spec={row['op_macro']}={row['code']} "
                f"sim={opcodes.get(row['op_macro'])}")
        if row["name"] in seen:
            raise SystemExit(
                f"duplicate arm64 dispatch singleton name: {row['name']!r}")
        seen.add(row["name"])
    check_against_header()
    return singletons


def render_lean(singletons: list[dict]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in singletons)
    codes = "\n".join(f"  | .{row['name']} => {row['code']}"
                      for row in singletons)
    handled = []
    for row in singletons:
        handled.append(f"/-- Whether the opcode is the {row['name']} dispatch "
                       f"singleton (`{row['gate_macro']}`). -/\n"
                       f"def {row['name']}Handled (op : SingletonOp) : Bool :=\n"
                       f"  op == .{row['name']}")
    handled = "\n\n".join(handled)
    return f'''-- Generated by generate_arm64_dispatch_singleton_spec.py from arm64_dispatch_singleton_spec.json.
import Std
namespace KProgFormal.GeneratedArm64DispatchSingleton
/-- The sixteen AArch64 dispatcher opcodes that `ARM64_SIM_L_EXEC` gates
individually, outside the immediate/register dispatch families. -/
inductive SingletonOp where
{ctors}
deriving DecidableEq, Repr
/-- The ARM64_OP_* opcode number the dispatcher carries in arm64_sim.h. -/
def code : SingletonOp -> Nat
{codes}
{handled}
end KProgFormal.GeneratedArm64DispatchSingleton
'''


def render_c(singletons: list[dict]) -> str:
    asserts = []
    for row in singletons:
        asserts.append(
            f'_Static_assert({row["op_macro"]} == {row["code"]}U, '
            '"arm64 dispatch singleton code drift");')
    macros = []
    for row in singletons:
        title = f"#define {row['gate_macro']}(OP)"
        body = f"((OP) == {row['op_macro']})"
        macros.append(f"{title + ' ' * (68 - len(title))}\\\n\t{body}")
    coverage = []
    for row in singletons:
        coverage.append(
            f'_Static_assert({row["gate_macro"]}({row["op_macro"]}), '
            '"arm64 dispatch singleton coverage drift");')
    return f'''/* Generated by generate_arm64_dispatch_singleton_spec.py from arm64_dispatch_singleton_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_DISPATCH_SINGLETON_H
#define KPROG_FORMAL_GENERATED_ARM64_DISPATCH_SINGLETON_H
/*
 * The sixteen AArch64 opcodes the `ARM64_SIM_L_EXEC` chain gates individually,
 * outside the immediate/register dispatch families: NOP, MOVK, BITFIELD,
 * CMN_IMM, CMN_REG, TST_BIC_REG, BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0,
 * STORE_D0, LOAD_Q0, STORE_Q0 and FMOV. Each names its ARM64_OP_* opcode and
 * exposes a one-member membership macro, so a dispatch gate is the generated
 * contract rather than a hand-rolled raw comparison. A code outside every
 * singleton reaches the caller's unsupported arm.
 * This header is included after `arm64_sim.h`, so the opcode-number drift
 * checks bind the hand-written ARM64_OP_* decode to the generated singleton
 * set.
 */
{chr(10).join(asserts)}
/* Each singleton's opcode, tested by the dispatcher. */
{chr(10).join(macros)}
/* Every singleton must be named by its generated membership macro. */
{chr(10).join(coverage)}
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    singletons = load()
    outputs = ((LEAN, render_lean(singletons)), (CHEADER, render_c(singletons)))
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated arm64 dispatch singleton contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
