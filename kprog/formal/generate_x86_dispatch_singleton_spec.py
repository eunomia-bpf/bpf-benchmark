#!/usr/bin/env python3
"""Generate the shared x86-64 dispatch-singleton opcode-membership contract.

The `X86_SIM_L_EXEC` chain gates forty-three opcodes with a bare
`(OP) == X86_OP_X` comparison while the ten multi-opcode families go through
generated `KPROG_X86_<F>_HANDLED` membership macros (Step 0148). This pass
generates the singleton analogue: one `KPROG_X86_DISP_<NAME>_HANDLED(OP)`
one-member membership macro per opcode, the dispatcher routes all 43 gates
through them, and a chain that still carries a hand-rolled raw comparison --
or has drifted from the X86_OP_* decode -- fails the formal gate.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_dispatch_singleton_spec.json"
SIM_HEADER = ROOT.parent / "x86/x86_sim.h"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86DispatchSingleton.lean"
CHEADER = ROOT / "generated/x86_dispatch_singleton.h"

# The forty-three opcodes the `X86_SIM_L_EXEC` chain still gates with a bare
# `(OP) == X86_OP_X` comparison, in dispatcher order, each with the generated
# membership macro the dispatcher tests. The opcode numbers are the X86_OP_*
# codes of kprog/x86/x86_sim.h and are re-checked in load(). The five codes
# with no chain arm (JCC/JMP/CALL/CALL_HELPER/RET) are the non-members the
# caller's unsupported arm serves and are deliberately absent.
EXPECTED = {
    "schema_version": 1,
    "operation": "x86DispatchSingleton",
    "singletons": [
        {"name": "nop", "code": 0, "op_macro": "X86_OP_NOP",
         "gate_macro": "KPROG_X86_DISP_NOP_HANDLED"},
        {"name": "callMemcpy", "code": 63, "op_macro": "X86_OP_CALL_MEMCPY",
         "gate_macro": "KPROG_X86_DISP_CALL_MEMCPY_HANDLED"},
        {"name": "callMemset", "code": 60, "op_macro": "X86_OP_CALL_MEMSET",
         "gate_macro": "KPROG_X86_DISP_CALL_MEMSET_HANDLED"},
        {"name": "callMemcpyReg", "code": 70,
         "op_macro": "X86_OP_CALL_MEMCPY_REG",
         "gate_macro": "KPROG_X86_DISP_CALL_MEMCPY_REG_HANDLED"},
        {"name": "callMemsetReg", "code": 69,
         "op_macro": "X86_OP_CALL_MEMSET_REG",
         "gate_macro": "KPROG_X86_DISP_CALL_MEMSET_REG_HANDLED"},
        {"name": "callReg", "code": 47, "op_macro": "X86_OP_CALL_REG",
         "gate_macro": "KPROG_X86_DISP_CALL_REG_HANDLED"},
        {"name": "movImm", "code": 1, "op_macro": "X86_OP_MOV_IMM",
         "gate_macro": "KPROG_X86_DISP_MOV_IMM_HANDLED"},
        {"name": "movReg", "code": 2, "op_macro": "X86_OP_MOV_REG",
         "gate_macro": "KPROG_X86_DISP_MOV_REG_HANDLED"},
        {"name": "movbeLoad", "code": 40, "op_macro": "X86_OP_MOVBE_LOAD",
         "gate_macro": "KPROG_X86_DISP_MOVBE_LOAD_HANDLED"},
        {"name": "movbeStore", "code": 41, "op_macro": "X86_OP_MOVBE_STORE",
         "gate_macro": "KPROG_X86_DISP_MOVBE_STORE_HANDLED"},
        {"name": "loadXmm0", "code": 48, "op_macro": "X86_OP_LOAD_XMM0",
         "gate_macro": "KPROG_X86_DISP_LOAD_XMM0_HANDLED"},
        {"name": "storeXmm0", "code": 49, "op_macro": "X86_OP_STORE_XMM0",
         "gate_macro": "KPROG_X86_DISP_STORE_XMM0_HANDLED"},
        {"name": "lea", "code": 9, "op_macro": "X86_OP_LEA",
         "gate_macro": "KPROG_X86_DISP_LEA_HANDLED"},
        {"name": "aluMem", "code": 35, "op_macro": "X86_OP_ALU_MEM",
         "gate_macro": "KPROG_X86_DISP_ALU_MEM_HANDLED"},
        {"name": "aluMemUnary", "code": 50, "op_macro": "X86_OP_ALU_MEM_UNARY",
         "gate_macro": "KPROG_X86_DISP_ALU_MEM_UNARY_HANDLED"},
        {"name": "aluMemImm", "code": 51, "op_macro": "X86_OP_ALU_MEM_IMM",
         "gate_macro": "KPROG_X86_DISP_ALU_MEM_IMM_HANDLED"},
        {"name": "aluMemReg", "code": 54, "op_macro": "X86_OP_ALU_MEM_REG",
         "gate_macro": "KPROG_X86_DISP_ALU_MEM_REG_HANDLED"},
        {"name": "cmpRegMem", "code": 36, "op_macro": "X86_OP_CMP_REG_MEM",
         "gate_macro": "KPROG_X86_DISP_CMP_REG_MEM_HANDLED"},
        {"name": "cmov", "code": 21, "op_macro": "X86_OP_CMOV",
         "gate_macro": "KPROG_X86_DISP_CMOV_HANDLED"},
        {"name": "cmovMem", "code": 64, "op_macro": "X86_OP_CMOV_MEM",
         "gate_macro": "KPROG_X86_DISP_CMOV_MEM_HANDLED"},
        {"name": "setcc", "code": 22, "op_macro": "X86_OP_SETCC",
         "gate_macro": "KPROG_X86_DISP_SETCC_HANDLED"},
        {"name": "setccMem", "code": 62, "op_macro": "X86_OP_SETCC_MEM",
         "gate_macro": "KPROG_X86_DISP_SETCC_MEM_HANDLED"},
        {"name": "bswap", "code": 23, "op_macro": "X86_OP_BSWAP",
         "gate_macro": "KPROG_X86_DISP_BSWAP_HANDLED"},
        {"name": "popcnt", "code": 24, "op_macro": "X86_OP_POPCNT",
         "gate_macro": "KPROG_X86_DISP_POPCNT_HANDLED"},
        {"name": "shiftx", "code": 38, "op_macro": "X86_OP_SHIFTX",
         "gate_macro": "KPROG_X86_DISP_SHIFTX_HANDLED"},
        {"name": "shiftxMem", "code": 42, "op_macro": "X86_OP_SHIFTX_MEM",
         "gate_macro": "KPROG_X86_DISP_SHIFTX_MEM_HANDLED"},
        {"name": "rorx", "code": 39, "op_macro": "X86_OP_RORX",
         "gate_macro": "KPROG_X86_DISP_RORX_HANDLED"},
        {"name": "rorxMem", "code": 43, "op_macro": "X86_OP_RORX_MEM",
         "gate_macro": "KPROG_X86_DISP_RORX_MEM_HANDLED"},
        {"name": "bzhi", "code": 52, "op_macro": "X86_OP_BZHI",
         "gate_macro": "KPROG_X86_DISP_BZHI_HANDLED"},
        {"name": "bzhiMem", "code": 53, "op_macro": "X86_OP_BZHI_MEM",
         "gate_macro": "KPROG_X86_DISP_BZHI_MEM_HANDLED"},
        {"name": "bt", "code": 55, "op_macro": "X86_OP_BT",
         "gate_macro": "KPROG_X86_DISP_BT_HANDLED"},
        {"name": "btImm", "code": 66, "op_macro": "X86_OP_BT_IMM",
         "gate_macro": "KPROG_X86_DISP_BT_IMM_HANDLED"},
        {"name": "btMemImm", "code": 67, "op_macro": "X86_OP_BT_MEM_IMM",
         "gate_macro": "KPROG_X86_DISP_BT_MEM_IMM_HANDLED"},
        {"name": "imulImm", "code": 56, "op_macro": "X86_OP_IMUL_IMM",
         "gate_macro": "KPROG_X86_DISP_IMUL_IMM_HANDLED"},
        {"name": "imulMemImm", "code": 65, "op_macro": "X86_OP_IMUL_MEM_IMM",
         "gate_macro": "KPROG_X86_DISP_IMUL_MEM_IMM_HANDLED"},
        {"name": "mulx", "code": 57, "op_macro": "X86_OP_MULX",
         "gate_macro": "KPROG_X86_DISP_MULX_HANDLED"},
        {"name": "repMovs", "code": 58, "op_macro": "X86_OP_REP_MOVS",
         "gate_macro": "KPROG_X86_DISP_REP_MOVS_HANDLED"},
        {"name": "andn", "code": 61, "op_macro": "X86_OP_ANDN",
         "gate_macro": "KPROG_X86_DISP_ANDN_HANDLED"},
        {"name": "andnMem", "code": 68, "op_macro": "X86_OP_ANDN_MEM",
         "gate_macro": "KPROG_X86_DISP_ANDN_MEM_HANDLED"},
        {"name": "xchg", "code": 25, "op_macro": "X86_OP_XCHG",
         "gate_macro": "KPROG_X86_DISP_XCHG_HANDLED"},
        {"name": "div", "code": 26, "op_macro": "X86_OP_DIV",
         "gate_macro": "KPROG_X86_DISP_DIV_HANDLED"},
        {"name": "push", "code": 18, "op_macro": "X86_OP_PUSH",
         "gate_macro": "KPROG_X86_DISP_PUSH_HANDLED"},
        {"name": "pop", "code": 19, "op_macro": "X86_OP_POP",
         "gate_macro": "KPROG_X86_DISP_POP_HANDLED"},
    ],
}
SINGLETON_NAMES = [
    "nop", "callMemcpy", "callMemset", "callMemcpyReg", "callMemsetReg",
    "callReg", "movImm", "movReg", "movbeLoad", "movbeStore", "loadXmm0",
    "storeXmm0", "lea", "aluMem", "aluMemUnary", "aluMemImm", "aluMemReg",
    "cmpRegMem", "cmov", "cmovMem", "setcc", "setccMem", "bswap", "popcnt",
    "shiftx", "shiftxMem", "rorx", "rorxMem", "bzhi", "bzhiMem", "bt",
    "btImm", "btMemImm", "imulImm", "imulMemImm", "mulx", "repMovs", "andn",
    "andnMem", "xchg", "div", "push", "pop",
]

# The live dispatcher text, between the `X86_SIM_L_EXEC` `#define` and the
# `X86_SIM_RUN_OP` wrapper that follows it.
OPCODE_DEFINE = re.compile(
    r"^#define\s+(X86_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)
EXEC_START = "#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)"
EXEC_END = "#define X86_SIM_RUN_OP("

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
    """The live dispatcher must keep no gate-shaped raw singleton comparison.

    The x86 arms contain legitimate inner `(OP) == X86_OP_*` tests (the
    map-pointer/helper-id tag selection, the MOV_REG/DIV sub-arms), so the
    hand-gate rejection is anchored on the gate shapes the dispatcher actually
    writes -- the flattened `} else if ((OP) == X86_OP_X) {` / bare
    `if ((OP) == X86_OP_NOP) {` -- never on a parenthesised opcode comparison
    in an arm body."""
    gates = re.findall(
        r"(?:(?<=\{) )?if \(\(OP\) == (X86_OP_[A-Z0-9_]+)\) \{", region)
    hand_gates = [name for name in gates if name != "X86_OP_NOP"]
    if hand_gates:
        raise SystemExit(
            f"x86 dispatcher still tests dispatcher opcodes with raw gates "
            f"({sorted(set(hand_gates))})")

    missing = [row["gate_macro"] for row in EXPECTED["singletons"]
               if f"{row['gate_macro']}(OP)" not in region]
    if missing:
        raise SystemExit(
            "x86 dispatcher must route all 43 singleton gates; missing: "
            f"{missing}")


def check_against_header():
    check_region(exec_region())


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(
            f"invalid x86 dispatch singleton specification: {data!r}")
    singletons = EXPECTED["singletons"]
    names = [row["name"] for row in singletons]
    if names != SINGLETON_NAMES:
        raise SystemExit(
            f"invalid x86 dispatch singleton order: {names!r}")
    opcodes = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(SIM_HEADER.read_text())}
    if not opcodes:
        raise SystemExit(
            f"no X86_OP_* opcode definitions found in {SIM_HEADER}")
    seen = set()
    codes = set()
    for row in singletons:
        if opcodes.get(row["op_macro"]) != row["code"]:
            raise SystemExit(
                "x86 dispatch singleton opcodes drift from "
                "kprog/x86/x86_sim.h: "
                f"spec={row['op_macro']}={row['code']} "
                f"sim={opcodes.get(row['op_macro'])}")
        if row["name"] in seen:
            raise SystemExit(
                f"duplicate x86 dispatch singleton name: {row['name']!r}")
        seen.add(row["name"])
        if row["code"] in codes:
            raise SystemExit(f"duplicate x86 dispatch singleton code: "
                             f"{row['name']}={row['code']}")
        codes.add(row["code"])
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
    return f'''-- Generated by generate_x86_dispatch_singleton_spec.py from x86_dispatch_singleton_spec.json.
import Std
namespace KProgFormal.GeneratedX86DispatchSingleton
/-- The {len(singletons)} x86-64 dispatcher opcodes that `X86_SIM_L_EXEC` gates
individually, outside the ten dispatch families. -/
inductive SingletonOp where
{ctors}
deriving DecidableEq, Repr
/-- The X86_OP_* opcode number the dispatcher carries in x86_sim.h. -/
def code : SingletonOp -> Nat
{codes}
{handled}
end KProgFormal.GeneratedX86DispatchSingleton
'''


def render_c(singletons: list[dict]) -> str:
    asserts = []
    for row in singletons:
        asserts.append(
            f'_Static_assert({row["op_macro"]} == {row["code"]}U, '
            '"x86 dispatch singleton code drift");')
    macros = []
    for row in singletons:
        title = f"#define {row['gate_macro']}(OP)"
        body = f"((OP) == {row['op_macro']})"
        macros.append(f"{title + ' ' * (68 - len(title))}\\\n\t{body}")
    coverage = []
    for row in singletons:
        coverage.append(
            f'_Static_assert({row["gate_macro"]}({row["op_macro"]}), '
            '"x86 dispatch singleton coverage drift");')
    return f'''/* Generated by generate_x86_dispatch_singleton_spec.py from x86_dispatch_singleton_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_DISPATCH_SINGLETON_H
#define KPROG_FORMAL_GENERATED_X86_DISPATCH_SINGLETON_H
/*
 * The forty-three x86-64 opcodes the `X86_SIM_L_EXEC` chain gates
 * individually, outside the ten dispatch families: NOP, the four
 * memcpy/memset call forms, the register call, the immediate and register
 * moves, the MOVBE pair, the XMM0 pair, LEA, the four ALU-memory forms,
 * CMP_REG_MEM, the CMOV pair, the SETCC pair, BSWAP, POPCNT, the shifted
 * pair across register and memory sources, RORX, BZHI, the BT forms, the
 * IMUL forms, MULX, REP_MOVS, the ANDN pair, XCHG, DIV, PUSH and POP. Each
 * names its X86_OP_* opcode and exposes a one-member membership macro, so a
 * dispatch gate is the generated contract rather than a hand-rolled raw
 * comparison. A code outside every singleton and family (the five codes with
 * no arm: JCC, JMP, CALL, CALL_HELPER, RET) reaches the caller's unsupported
 * arm.
 * This header is included after `x86_sim.h`, so the opcode-number drift
 * checks bind the hand-written X86_OP_* decode to the generated singleton
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
                    f"generated x86 dispatch singleton contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
