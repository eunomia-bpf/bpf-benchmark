#!/usr/bin/env python3
"""Generate the shared x86-64 specialization-dispatch contract.

O2 (specialization preservation) says a JIT specialization must not insert a
safety check that native execution does not perform. For the x86 simulator the
load-bearing, machine-checkable content of O2 is the *dispatch selection*: for
each canonical `X86_OP_*` token, which specialized step the artifact encoder
emits and which specialized body the simulator's own `X86_SIM_L_EXEC` chain
runs. If the two select the same body, the encoder can replace the generic
`X86_SIM_RUN_OP` step with a direct call without changing the modeled state.

The contract fixes, per canonical token, four facts:

  - `dispatch`: how the encoder routes the token ---
      `directMacro`   the encoder emits a specialized call (a `DIRECT_STEP_MACROS`
                      row, an aux-gated override, `X86_SIM_BPF_CALL_ID`, or
                      `X86_SIM_BPF_CALL_REG`);
      `branchHandler` the encoder emits it through `append_branch_or_ret` /
                      `ret_statement` (the four control-transfer tokens), never
                      as a chain step;
      `genericRunOp`  the encoder emits the generic `X86_SIM_RUN_OP` step, which
                      runs the token through the `X86_SIM_L_EXEC` chain;
  - `chain_macro`: the `X86_SIM_L_EXEC_*`/`X86_SIM_BPF_CALL_*` handler the
    token's `X86_SIM_L_EXEC` arm calls, or "" for an arm that is inline or has
    no arm (`X86_OP_JCC/JMP/CALL/RET` and `X86_OP_CALL_HELPER` are handled
    outside the chain);
  - `direct_call`: the specialized call template the encoder emits at aux 0,
    with `{op} {dst} {src} {flags} {aux} {imm}` placeholders, or "";
  - `aux_call`: the aux-gated call template the encoder emits for the six
    lane-shift-sensitive tokens (`MOV_IMM`, `MOV_REG`, `CMP_IMM`, `TEST_IMM`,
    `CMP_REG`, `TEST_REG`) when aux is nonzero, or "".

The macro name of a call is its text up to the first `(`. The
`X86_SIM_L_EXEC` chain in `kprog/x86/x86_sim_local_bpf.h` is parsed here, so a
spec row and the real chain cannot drift; `test_x86_specialization_chain_host.c`
re-parses the chain independently at test time. The canonical token list comes
from `kprog/x86/x86_sim.h`.

The no-insertion property is fixed over the tokens both paths serve: where the
chain handler and the encoder call are both present they name the same body.

Housekeep: several direct rows are byte-identical mirror rows
(`MOV_LOAD_SCALAR`/`MOVSX_LOAD` share `MOV_LOAD`, `ADD_IMM` aliases `ALU_IMM`,
`ADD_REG`/`XOR_REG` alias `ALU_REG`); the encoder itself never emits the alias
spellings, but the table stays a superset so a caller-supplied alias still
routes. The contract pins the target equality rather than treating the alias
rows as drift.

`X86_OP_CALL_HELPER` is the one token with an encoder call
(`X86_SIM_BPF_CALL_ID`) and no chain arm: the simulator reaches that body
through the helper-call branch, not through `X86_SIM_L_EXEC`. This is benign.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_specialization_spec.json"
SIM_HEADER = ROOT.parent / "x86/x86_sim.h"
CHAIN_HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86Specialization.lean"
C_HEADER = ROOT / "generated/x86_specialization.h"
PYTHON = ROOT.parent / "x86/micro-prog/generated_x86_specialization.py"

# The independent enumeration, in the order `kprog/x86/x86_sim.h` defines the
# tokens: (token, dispatch, chain_macro, direct_call, aux_call).
EXPECTED = [
    ("X86_OP_NOP", "genericRunOp", "", "", ""),
    ("X86_OP_MOV_IMM", "directMacro", "", "X86_SIM_L_EXEC_MOV_IMM({dst}, {flags}, {imm})", "X86_SIM_L_EXEC_MOV_IMM_AUX({dst}, {flags}, {aux}, {imm})"),
    ("X86_OP_MOV_REG", "directMacro", "", "X86_SIM_L_EXEC_MOV_REG({dst}, {src}, {flags})", "X86_SIM_L_EXEC_MOV_REG_AUX({dst}, {src}, {flags}, {aux})"),
    ("X86_OP_ADD_IMM", "directMacro", "X86_SIM_L_EXEC_ALU_IMM", "X86_SIM_L_EXEC_ALU_IMM({dst}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ADD_REG", "directMacro", "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_XOR_REG", "directMacro", "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_MOV_LOAD", "directMacro", "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_MOV_STORE_IMM", "directMacro", "X86_SIM_L_EXEC_STORE", "X86_SIM_L_EXEC_STORE({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_MOV_STORE_REG", "directMacro", "X86_SIM_L_EXEC_STORE", "X86_SIM_L_EXEC_STORE({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_LEA", "directMacro", "X86_SIM_L_EXEC_LEA", "X86_SIM_L_EXEC_LEA({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ALU_IMM", "directMacro", "X86_SIM_L_EXEC_ALU_IMM", "X86_SIM_L_EXEC_ALU_IMM({dst}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ALU_REG", "directMacro", "X86_SIM_L_EXEC_ALU_REG", "X86_SIM_L_EXEC_ALU_REG({dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_CMP_IMM", "directMacro", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX", "X86_SIM_L_EXEC_CMP_IMM_OP({op}, {dst}, {flags}, {imm})", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX({op}, {dst}, {flags}, {aux}, {imm})"),
    ("X86_OP_CMP_REG", "directMacro", "X86_SIM_L_EXEC_CMP_REG_OP_AUX", "X86_SIM_L_EXEC_CMP_REG_OP({op}, {dst}, {src}, {flags})", "X86_SIM_L_EXEC_CMP_REG_OP_AUX({op}, {dst}, {src}, {flags}, {aux})"),
    ("X86_OP_TEST_IMM", "directMacro", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX", "X86_SIM_L_EXEC_CMP_IMM_OP({op}, {dst}, {flags}, {imm})", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX({op}, {dst}, {flags}, {aux}, {imm})"),
    ("X86_OP_TEST_REG", "directMacro", "X86_SIM_L_EXEC_CMP_REG_OP_AUX", "X86_SIM_L_EXEC_CMP_REG_OP({op}, {dst}, {src}, {flags})", "X86_SIM_L_EXEC_CMP_REG_OP_AUX({op}, {dst}, {src}, {flags}, {aux})"),
    ("X86_OP_JCC", "branchHandler", "", "", ""),
    ("X86_OP_JMP", "branchHandler", "", "", ""),
    ("X86_OP_PUSH", "directMacro", "X86_SIM_L_EXEC_PUSH", "X86_SIM_L_EXEC_PUSH({src})", ""),
    ("X86_OP_POP", "directMacro", "X86_SIM_L_EXEC_POP", "X86_SIM_L_EXEC_POP({dst}, {flags})", ""),
    ("X86_OP_CALL", "branchHandler", "", "", ""),
    ("X86_OP_CMOV", "directMacro", "X86_SIM_L_EXEC_CMOV", "X86_SIM_L_EXEC_CMOV({dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_SETCC", "directMacro", "X86_SIM_L_EXEC_SETCC_STEP", "X86_SIM_L_EXEC_SETCC({dst}, {aux})", ""),
    ("X86_OP_BSWAP", "genericRunOp", "", "", ""),
    ("X86_OP_POPCNT", "genericRunOp", "", "", ""),
    ("X86_OP_XCHG", "genericRunOp", "", "", ""),
    ("X86_OP_DIV", "genericRunOp", "", "", ""),
    ("X86_OP_SHLD_IMM", "genericRunOp", "", "", ""),
    ("X86_OP_SHRD_IMM", "genericRunOp", "", "", ""),
    ("X86_OP_CMP_MEM_IMM", "directMacro", "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_TEST_MEM_IMM", "directMacro", "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_CMP_MEM_REG", "directMacro", "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_MOVZX_REG", "directMacro", "", "X86_SIM_L_EXEC_MOVX_REG({op}, {dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_MOVSX_REG", "directMacro", "", "X86_SIM_L_EXEC_MOVX_REG({op}, {dst}, {src}, {flags}, {aux})", ""),
    ("X86_OP_MOVSX_LOAD", "directMacro", "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ALU_MEM", "directMacro", "X86_SIM_L_EXEC_ALU_MEM", "X86_SIM_L_EXEC_ALU_MEM({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_CMP_REG_MEM", "directMacro", "X86_SIM_L_EXEC_CMP_REG_MEM", "X86_SIM_L_EXEC_CMP_REG_MEM({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_MOV_LOAD_SCALAR", "directMacro", "X86_SIM_L_EXEC_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_SHIFTX", "genericRunOp", "", "", ""),
    ("X86_OP_RORX", "genericRunOp", "", "", ""),
    ("X86_OP_MOVBE_LOAD", "genericRunOp", "X86_SIM_L_EXEC_MOVBE_LOAD", "", ""),
    ("X86_OP_MOVBE_STORE", "genericRunOp", "X86_SIM_L_EXEC_MOVBE_STORE", "", ""),
    ("X86_OP_SHIFTX_MEM", "genericRunOp", "", "", ""),
    ("X86_OP_RORX_MEM", "genericRunOp", "", "", ""),
    ("X86_OP_MOV_LOAD_MAP_PTR", "genericRunOp", "", "", ""),
    ("X86_OP_MOV_LOAD_HELPER_ID", "genericRunOp", "", "", ""),
    ("X86_OP_CALL_HELPER", "directMacro", "", "X86_SIM_BPF_CALL_ID({imm})", ""),
    ("X86_OP_CALL_REG", "directMacro", "X86_SIM_BPF_CALL_REG", "X86_SIM_BPF_CALL_REG({src})", ""),
    ("X86_OP_LOAD_XMM0", "genericRunOp", "X86_SIM_L_EXEC_LOAD_XMM0", "", ""),
    ("X86_OP_STORE_XMM0", "genericRunOp", "X86_SIM_L_EXEC_STORE_XMM0", "", ""),
    ("X86_OP_ALU_MEM_UNARY", "directMacro", "X86_SIM_L_EXEC_ALU_MEM_UNARY", "X86_SIM_L_EXEC_ALU_MEM_UNARY({dst}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ALU_MEM_IMM", "directMacro", "X86_SIM_L_EXEC_ALU_MEM_IMM", "X86_SIM_L_EXEC_ALU_MEM_IMM({dst}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_BZHI", "genericRunOp", "X86_SIM_L_EXEC_BZHI", "", ""),
    ("X86_OP_BZHI_MEM", "genericRunOp", "X86_SIM_L_EXEC_BZHI_MEM", "", ""),
    ("X86_OP_ALU_MEM_REG", "directMacro", "X86_SIM_L_EXEC_ALU_MEM_REG", "X86_SIM_L_EXEC_ALU_MEM_REG({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_BT", "directMacro", "X86_SIM_L_EXEC_BT", "X86_SIM_L_EXEC_BT({dst}, {src}, {flags})", ""),
    ("X86_OP_IMUL_IMM", "directMacro", "X86_SIM_L_EXEC_IMUL_IMM", "X86_SIM_L_EXEC_IMUL_IMM({dst}, {src}, {flags}, {imm})", ""),
    ("X86_OP_MULX", "directMacro", "X86_SIM_L_EXEC_MULX", "X86_SIM_L_EXEC_MULX({dst}, {src}, {aux}, {flags})", ""),
    ("X86_OP_REP_MOVS", "directMacro", "X86_SIM_L_EXEC_REP_MOVS", "X86_SIM_L_EXEC_REP_MOVS({flags}, {imm})", ""),
    ("X86_OP_TEST_MEM_REG", "directMacro", "X86_SIM_L_EXEC_CMP_MEM", "X86_SIM_L_EXEC_CMP_MEM({op}, {dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_CALL_MEMSET", "directMacro", "X86_SIM_L_EXEC_CALL_MEMSET", "X86_SIM_L_EXEC_CALL_MEMSET({imm})", ""),
    ("X86_OP_ANDN", "directMacro", "X86_SIM_L_EXEC_ANDN", "X86_SIM_L_EXEC_ANDN({dst}, {src}, {aux}, {flags})", ""),
    ("X86_OP_SETCC_MEM", "directMacro", "X86_SIM_L_EXEC_SETCC_MEM", "X86_SIM_L_EXEC_SETCC_MEM({dst}, {aux}, {imm})", ""),
    ("X86_OP_CALL_MEMCPY", "directMacro", "X86_SIM_L_EXEC_CALL_MEMCPY", "X86_SIM_L_EXEC_CALL_MEMCPY({imm})", ""),
    ("X86_OP_CMOV_MEM", "directMacro", "X86_SIM_L_EXEC_CMOV_MEM", "X86_SIM_L_EXEC_CMOV_MEM({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_IMUL_MEM_IMM", "directMacro", "X86_SIM_L_EXEC_IMUL_MEM_IMM", "X86_SIM_L_EXEC_IMUL_MEM_IMM({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_BT_IMM", "directMacro", "X86_SIM_L_EXEC_BT_IMM", "X86_SIM_L_EXEC_BT_IMM({dst}, {flags}, {imm})", ""),
    ("X86_OP_BT_MEM_IMM", "directMacro", "X86_SIM_L_EXEC_BT_MEM_IMM", "X86_SIM_L_EXEC_BT_MEM_IMM({dst}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_ANDN_MEM", "directMacro", "X86_SIM_L_EXEC_ANDN_MEM", "X86_SIM_L_EXEC_ANDN_MEM({dst}, {src}, {flags}, {aux}, {imm})", ""),
    ("X86_OP_CALL_MEMSET_REG", "directMacro", "X86_SIM_L_EXEC_CALL_MEMSET_REG", "X86_SIM_L_EXEC_CALL_MEMSET_REG({imm})", ""),
    ("X86_OP_CALL_MEMCPY_REG", "directMacro", "X86_SIM_L_EXEC_CALL_MEMCPY_REG", "X86_SIM_L_EXEC_CALL_MEMCPY_REG({imm})", ""),
    ("X86_OP_RET", "branchHandler", "", "", ""),
]
COLUMNS = ("token", "dispatch", "chain_macro", "direct_call", "aux_call")

OPCODE_DEFINE = re.compile(
    r"^#define\s+(X86_OP_[A-Z0-9_]+)\s+0x[0-9a-fA-F]+U\s*$", re.M)
CHAIN_START = "#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)"
CHAIN_END = "#define X86_SIM_RUN_OP("
HANDLER = re.compile(r"(X86_SIM_(?:L_EXEC_[A-Z0-9_]+|BPF_CALL_[A-Z0-9_]+))\s*\(")


def macro_name(call):
    """The macro a call template invokes: its text up to the first `(`."""
    return call.split("(", 1)[0] if call else ""


def canonical_tokens():
    return OPCODE_DEFINE.findall(SIM_HEADER.read_text())


def chain_arms():
    """One text block per `(OP) == ...` arm of the `X86_SIM_L_EXEC` body.

    Brace depth is tracked so a nested `if` body does not split an arm and a
    multi-token `||` disjunction inside one guard stays one arm; a naive split
    on the `} else if (` text would over-split."""
    text = CHAIN_HEADER.read_text()
    start = text.index(CHAIN_START)
    end = text.index(CHAIN_END, start)
    body = text[start:end]
    i = body.index("{", body.index("do {"))
    depth = 0
    begin = i + 1
    while True:
        if body[i] == "{":
            depth += 1
        elif body[i] == "}":
            depth -= 1
            if depth == 0:
                break
        i += 1
    inner = body[begin:i]
    arms = []
    depth = 0
    begin = 0
    j = 0
    boundary = re.compile(r"\}\s*else\s+if\s*\(")
    while j < len(inner):
        ch = inner[j]
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                match = boundary.match(inner, j)
                if match:
                    arms.append(inner[begin:j + 1])
                    begin = match.end()
                    j = match.end()
                    continue
        j += 1
    arms.append(inner[begin:])
    return arms


def arm_handler(arm):
    """The single step handler the arm calls; "" when the arm is inline or calls
    more than one handler (the double-shift arms call `L_SET_SHIFT_FLAGS`
    twice, which is why this is not a chain step macro)."""
    names = []
    for match in HANDLER.finditer(arm):
        if match.group(1) not in names:
            names.append(match.group(1))
    return names[0] if len(names) == 1 else ""


def chain_table():
    table = {}
    for arm in chain_arms():
        handler = arm_handler(arm)
        for token in re.findall(r"\(OP\)\s*==\s*(X86_OP_[A-Z0-9_]+)", arm):
            table[token] = handler
    return table


def strip_aux(name):
    return name[:-len("_AUX")] if name.endswith("_AUX") else name


def strip_step(name):
    return name[:-len("_STEP")] if name.endswith("_STEP") else name


def same_body(left, right):
    return strip_step(strip_aux(left)) == strip_step(strip_aux(right))


def check_against_chain(rows):
    chain = chain_table()
    canonical = canonical_tokens()
    for row in rows:
        token = row["token"]
        if token not in canonical:
            raise SystemExit("specialization row for unknown token: " + token)
        if chain.get(token, "") != row["chain_macro"]:
            raise SystemExit(
                "chain drift for {}: header has {!r}, contract says {!r}".format(
                    token, chain.get(token, ""), row["chain_macro"]))
    extra = set(chain) - set(canonical)
    if extra:
        raise SystemExit("chain names non-canonical tokens: " + repr(sorted(extra)))


def check_consistency(rows):
    """The class of a row must match its call columns, and the no-insertion
    property must hold: a token the chain and the encoder both serve selects the
    same body."""
    if [row["token"] for row in rows] != canonical_tokens():
        raise SystemExit(
            "specialization rows do not cover the canonical tokens in order")
    for row in rows:
        token = row["token"]
        has_direct = bool(row["direct_call"])
        has_chain = bool(row["chain_macro"])
        if row["dispatch"] == "directMacro" and not has_direct:
            raise SystemExit("directMacro row {} has no direct_call".format(token))
        if row["dispatch"] == "genericRunOp" and has_direct:
            raise SystemExit(
                "genericRunOp row {} names an encoder call".format(token))
        if row["dispatch"] == "branchHandler" and (has_direct or has_chain):
            raise SystemExit(
                "branchHandler row {} names a handler".format(token))
        if has_chain and has_direct:
            if not same_body(row["chain_macro"], macro_name(row["direct_call"])):
                raise SystemExit(
                    "no-insertion violation for {}: chain {} vs encoder {}".format(
                        token, row["chain_macro"], row["direct_call"]))
        if row["aux_call"]:
            name = macro_name(row["aux_call"])
            ref = macro_name(row["direct_call"])
            if not same_body(name, ref):
                raise SystemExit(
                    "aux override for {} diverges from the base body".format(token))
            if has_chain and not same_body(row["chain_macro"], name):
                raise SystemExit(
                    "aux override for {} does not match the chain body".format(token))


def schema(data):
    if set(data) != {"schema_version", "operation", "rows", "aux_gated"}:
        raise SystemExit("invalid x86 specialization specification: " + repr(data))
    if data["schema_version"] != 1 or data["operation"] != "x86Specialization":
        raise SystemExit("invalid x86 specialization specification: " + repr(data))
    rows = data["rows"]
    if rows != [dict(zip(COLUMNS, row)) for row in EXPECTED]:
        raise SystemExit("invalid x86 specialization table: " + repr(rows))
    aux = [row["token"] for row in rows if row["aux_call"]]
    if data["aux_gated"] != aux:
        raise SystemExit("invalid aux-gated list: " + repr(data["aux_gated"]))
    return rows


def load():
    return schema(json.loads(SPEC.read_text()))


def camel(token):
    parts = token[len("X86_OP_"):].split("_")
    return parts[0].lower() + "".join(part.capitalize() for part in parts[1:])


DISPATCH_C = {
    "directMacro": "KPROG_X86_SPEC_DIRECT_MACRO",
    "branchHandler": "KPROG_X86_SPEC_BRANCH_HANDLER",
    "genericRunOp": "KPROG_X86_SPEC_GENERIC_RUN_OP",
}


def render_lean(rows):
    head = """-- Generated by generate_x86_specialization_spec.py from
-- x86_specialization_spec.json.
import Std

namespace KProgFormal.GeneratedX86Specialization

/-- How the artifact encoder routes an x86-64 token. -/
inductive Dispatch where
  | directMacro
  | branchHandler
  | genericRunOp
  deriving DecidableEq, Repr

/-- The canonical x86-64 tokens. -/
inductive Op where
"""
    ctors = "\n".join("  | " + camel(row["token"]) for row in rows)
    mid = ("\n  deriving DecidableEq, Repr\n\n"
           "/-- The encoder's dispatch class. -/\ndef dispatch : Op -> Dispatch\n")
    disp = "\n".join("  | .{} => .{}".format(camel(row["token"]), row["dispatch"])
                     for row in rows)
    names = "\n".join('  | .{} => "{}"'.format(camel(row["token"]), row["token"])
                      for row in rows)
    chain = "\n".join('  | .{} => "{}"'.format(camel(row["token"]), row["chain_macro"])
                      for row in rows)
    direct = "\n".join('  | .{} => "{}"'.format(camel(row["token"]),
                                                   macro_name(row["direct_call"]))
                       for row in rows)
    aux = "\n".join('  | .{} => "{}"'.format(camel(row["token"]),
                                              macro_name(row["aux_call"]))
                    for row in rows)
    tail = ("\n/-- The `X86_OP_*` spelling of the token, as `kprog/x86/x86_sim.h`\n"
            "defines it. -/\ndef tokenName : Op -> String\n" + names +
            "\n\n/-- The `X86_SIM_L_EXEC` handler the token's chain arm calls, or \"\". -/\n"
            "def chainMacro : Op -> String\n" + chain +
            "\n\n/-- The specialized macro the encoder emits at aux 0, or \"\". -/\n"
            "def directMacro : Op -> String\n" + direct +
            "\n\n/-- The aux-gated macro the encoder emits for nonzero aux, or \"\". -/\n"
            "def auxMacro : Op -> String\n" + aux +
            "\n\nend KProgFormal.GeneratedX86Specialization\n")
    return head + ctors + mid + disp + tail


def render_c(rows):
    cases = "\n".join("\tcase {}: return {};".format(
        row["token"], DISPATCH_C[row["dispatch"]]) for row in rows)
    return """/* Generated by generate_x86_specialization_spec.py from
 * x86_specialization_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_SPECIALIZATION_H
#define KPROG_FORMAL_GENERATED_X86_SPECIALIZATION_H
/*
 * The encoder's dispatch class for each canonical x86-64 token. `directMacro`
 * is a specialized `X86_SIM_L_EXEC_*`/`X86_SIM_BPF_CALL_*` body, `branchHandler`
 * is the control-transfer path, and `genericRunOp` runs the token through the
 * `X86_SIM_L_EXEC` chain.
 */
#define KPROG_X86_SPEC_DIRECT_MACRO 0U
#define KPROG_X86_SPEC_BRANCH_HANDLER 1U
#define KPROG_X86_SPEC_GENERIC_RUN_OP 2U
#define KPROG_X86_SPEC_COUNT {count}U
static inline __u8 kprog_x86_spec_dispatch(__u8 op)
{{
\tswitch (op) {{
{cases}
\tdefault: return KPROG_X86_SPEC_GENERIC_RUN_OP;
\t}}
}}
#endif
""".format(count=len(rows), cases=cases)


def render_python(rows):
    dispatch = "\n".join('    "{}": "{}",'.format(row["token"], row["dispatch"])
                         for row in rows)
    direct = "\n".join('    "{}": "{}",'.format(row["token"], row["direct_call"])
                       for row in rows if row["direct_call"])
    aux = "\n".join('    "{}": "{}",'.format(row["token"], row["aux_call"])
                    for row in rows if row["aux_call"])
    return """# Generated by generate_x86_specialization_spec.py from
# x86_specialization_spec.json.
# The encoder's dispatch class for each canonical x86-64 token.
X86_SPECIALIZATION_DISPATCH = {{
{dispatch}
}}
# The specialized call the encoder emits at aux 0, as a `str.format` template
# over the op, dst, src, flags, aux and imm operands.
X86_SPECIALIZATION_DIRECT_CALL = {{
{direct}
}}
# The aux-gated call the encoder emits for nonzero aux. Every aux-gated token
# runs through `X86_SIM_L_EXEC_<TOKEN>_AUX` (or its `_STEP` spelling) on both the
# chain and the encoder, so the override selects the same body the chain does.
X86_SPECIALIZATION_AUX_CALL = {{
{aux}
}}
""".format(dispatch=dispatch, direct=direct, aux=aux)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    rows = load()
    check_against_chain(rows)
    check_consistency(rows)
    outputs = (
        (LEAN, render_lean(rows)),
        (C_HEADER, render_c(rows)),
        (PYTHON, render_python(rows)),
    )
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    "generated x86 specialization contract is stale: " + str(path))
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
