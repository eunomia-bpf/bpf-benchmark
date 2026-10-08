#!/usr/bin/env python3
"""Generate the shared x86-64 opcode-number contract.

The simulator, the Lean model, and the artifact encoder each name the x86-64
opcodes by a symbolic `X86_OP_*` token, but only this contract fixes what each
token *is*. `kprog/x86/x86_sim.h` defines the tokens, and the generator re-reads
that header on every `--check`, so a renumbered, renamed, added, or dropped
opcode fails generation rather than silently desynchronising three consumers.

Three outputs share the one specification:

  * `generated/x86_opcode.h` pins every canonical token to its numeric code with
    a `_Static_assert`, so the C compiler refuses to build the simulator against
    a drifted `x86_sim.h`. It also pins the five width-suffixed aliases as
    *identities* (`X86_OP_MOV_IMM64 == X86_OP_MOV_IMM`) rather than literals,
    because an alias asserts sameness with its target, not a value.
  * `KProgFormal/GeneratedX86Opcode.lean` exposes the same table as an inductive
    family with `code`/`define` projections.
  * `x86/micro-prog/generated_x86_opcode.py` carries the name-to-token map the
    artifact encoder resolves through, so the encoder cannot emit a token the
    simulator does not define.

Every canonical name is derived from its token by lowerCamelCasing the part
after `X86_OP_`, and that derivation is re-checked here rather than trusted, so
the specification's `name` column is pinned to its `define` column.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_opcode_spec.json"
SIM_HEADER = ROOT.parent / "x86/x86_sim.h"
LEAN = ROOT / "KProgFormal/GeneratedX86Opcode.lean"
C_HEADER = ROOT / "generated/x86_opcode.h"
PYTHON = ROOT.parent / "x86/micro-prog/generated_x86_opcode.py"

# The independent enumeration of the 72 canonical opcodes, in the order
# `kprog/x86/x86_sim.h` defines them: (name, define, code).
EXPECTED = [
    ("nop", "X86_OP_NOP", 0x00),
    ("movImm", "X86_OP_MOV_IMM", 0x01),
    ("movReg", "X86_OP_MOV_REG", 0x02),
    ("addImm", "X86_OP_ADD_IMM", 0x03),
    ("addReg", "X86_OP_ADD_REG", 0x04),
    ("xorReg", "X86_OP_XOR_REG", 0x05),
    ("movLoad", "X86_OP_MOV_LOAD", 0x06),
    ("movStoreImm", "X86_OP_MOV_STORE_IMM", 0x07),
    ("movStoreReg", "X86_OP_MOV_STORE_REG", 0x08),
    ("lea", "X86_OP_LEA", 0x09),
    ("aluImm", "X86_OP_ALU_IMM", 0x0a),
    ("aluReg", "X86_OP_ALU_REG", 0x0b),
    ("cmpImm", "X86_OP_CMP_IMM", 0x0c),
    ("cmpReg", "X86_OP_CMP_REG", 0x0d),
    ("testImm", "X86_OP_TEST_IMM", 0x0e),
    ("testReg", "X86_OP_TEST_REG", 0x0f),
    ("jcc", "X86_OP_JCC", 0x10),
    ("jmp", "X86_OP_JMP", 0x11),
    ("push", "X86_OP_PUSH", 0x12),
    ("pop", "X86_OP_POP", 0x13),
    ("call", "X86_OP_CALL", 0x14),
    ("cmov", "X86_OP_CMOV", 0x15),
    ("setcc", "X86_OP_SETCC", 0x16),
    ("bswap", "X86_OP_BSWAP", 0x17),
    ("popcnt", "X86_OP_POPCNT", 0x18),
    ("xchg", "X86_OP_XCHG", 0x19),
    ("div", "X86_OP_DIV", 0x1a),
    ("shldImm", "X86_OP_SHLD_IMM", 0x1b),
    ("shrdImm", "X86_OP_SHRD_IMM", 0x1c),
    ("cmpMemImm", "X86_OP_CMP_MEM_IMM", 0x1d),
    ("testMemImm", "X86_OP_TEST_MEM_IMM", 0x1e),
    ("cmpMemReg", "X86_OP_CMP_MEM_REG", 0x1f),
    ("movzxReg", "X86_OP_MOVZX_REG", 0x20),
    ("movsxReg", "X86_OP_MOVSX_REG", 0x21),
    ("movsxLoad", "X86_OP_MOVSX_LOAD", 0x22),
    ("aluMem", "X86_OP_ALU_MEM", 0x23),
    ("cmpRegMem", "X86_OP_CMP_REG_MEM", 0x24),
    ("movLoadScalar", "X86_OP_MOV_LOAD_SCALAR", 0x25),
    ("shiftx", "X86_OP_SHIFTX", 0x26),
    ("rorx", "X86_OP_RORX", 0x27),
    ("movbeLoad", "X86_OP_MOVBE_LOAD", 0x28),
    ("movbeStore", "X86_OP_MOVBE_STORE", 0x29),
    ("shiftxMem", "X86_OP_SHIFTX_MEM", 0x2a),
    ("rorxMem", "X86_OP_RORX_MEM", 0x2b),
    ("movLoadMapPtr", "X86_OP_MOV_LOAD_MAP_PTR", 0x2c),
    ("movLoadHelperId", "X86_OP_MOV_LOAD_HELPER_ID", 0x2d),
    ("callHelper", "X86_OP_CALL_HELPER", 0x2e),
    ("callReg", "X86_OP_CALL_REG", 0x2f),
    ("loadXmm0", "X86_OP_LOAD_XMM0", 0x30),
    ("storeXmm0", "X86_OP_STORE_XMM0", 0x31),
    ("aluMemUnary", "X86_OP_ALU_MEM_UNARY", 0x32),
    ("aluMemImm", "X86_OP_ALU_MEM_IMM", 0x33),
    ("bzhi", "X86_OP_BZHI", 0x34),
    ("bzhiMem", "X86_OP_BZHI_MEM", 0x35),
    ("aluMemReg", "X86_OP_ALU_MEM_REG", 0x36),
    ("bt", "X86_OP_BT", 0x37),
    ("imulImm", "X86_OP_IMUL_IMM", 0x38),
    ("mulx", "X86_OP_MULX", 0x39),
    ("repMovs", "X86_OP_REP_MOVS", 0x3a),
    ("testMemReg", "X86_OP_TEST_MEM_REG", 0x3b),
    ("callMemset", "X86_OP_CALL_MEMSET", 0x3c),
    ("andn", "X86_OP_ANDN", 0x3d),
    ("setccMem", "X86_OP_SETCC_MEM", 0x3e),
    ("callMemcpy", "X86_OP_CALL_MEMCPY", 0x3f),
    ("cmovMem", "X86_OP_CMOV_MEM", 0x40),
    ("imulMemImm", "X86_OP_IMUL_MEM_IMM", 0x41),
    ("btImm", "X86_OP_BT_IMM", 0x42),
    ("btMemImm", "X86_OP_BT_MEM_IMM", 0x43),
    ("andnMem", "X86_OP_ANDN_MEM", 0x44),
    ("callMemsetReg", "X86_OP_CALL_MEMSET_REG", 0x45),
    ("callMemcpyReg", "X86_OP_CALL_MEMCPY_REG", 0x46),
    ("ret", "X86_OP_RET", 0xff),
]
ALIAS_EXPECTED = [
    ("movImm64", "X86_OP_MOV_IMM64", "X86_OP_MOV_IMM"),
    ("movReg64", "X86_OP_MOV_REG64", "X86_OP_MOV_REG"),
    ("addImm64", "X86_OP_ADD_IMM64", "X86_OP_ADD_IMM"),
    ("addReg64", "X86_OP_ADD_REG64", "X86_OP_ADD_REG"),
    ("xorReg32", "X86_OP_XOR_REG32", "X86_OP_XOR_REG"),
]

OPCODE_DEFINE = re.compile(
    r"^#define\s+(X86_OP_[A-Z0-9_]+)\s+0x([0-9a-fA-F]+)U\s*$", re.M)
ALIAS_DEFINE = re.compile(
    r"^#define\s+(X86_OP_[A-Z0-9_]+)\s+(X86_OP_[A-Z0-9_]+)\s*$", re.M)


def spec(data=None):
    if data is None:
        data = json.loads(SPEC.read_text())
    if set(data) != {"schema_version", "operation", "opcodes", "aliases"}:
        raise SystemExit(f"invalid x86 opcode specification: {data!r}")
    if data["schema_version"] != 1 or data["operation"] != "x86Opcode":
        raise SystemExit(f"invalid x86 opcode specification: {data!r}")
    rows = data["opcodes"]
    aliases = data["aliases"]
    if rows != [{"name": n, "define": d, "code": f"{c:#04x}"}
                for n, d, c in EXPECTED]:
        raise SystemExit(f"invalid x86 opcode table: {rows!r}")
    if aliases != [{"name": n, "define": d, "target": t}
                   for n, d, t in ALIAS_EXPECTED]:
        raise SystemExit(f"invalid x86 opcode alias table: {aliases!r}")
    return rows, aliases


def canonical_name(define):
    parts = define[len("X86_OP_"):].split("_")
    return parts[0].lower() + "".join(part.capitalize() for part in parts[1:])


def check_against_sim(rows, aliases):
    text = SIM_HEADER.read_text()
    defines = {name: int(value, 16)
               for name, value in OPCODE_DEFINE.findall(text)}
    alias_defines = dict(ALIAS_DEFINE.findall(text))
    if not defines:
        raise SystemExit(f"no X86_OP_* definitions found in {SIM_HEADER}")
    if set(defines) != {row["define"] for row in rows}:
        raise SystemExit(
            "x86 opcode set drift from kprog/x86/x86_sim.h: "
            f"missing={sorted({row['define'] for row in rows} - set(defines))} "
            f"extra={sorted(set(defines) - {row['define'] for row in rows})}")
    if set(alias_defines) != {row["define"] for row in aliases}:
        raise SystemExit(
            "x86 opcode alias set drift from kprog/x86/x86_sim.h: "
            f"got={sorted(alias_defines)}")
    seen = {}
    for row in rows:
        if defines[row["define"]] != int(row["code"], 16):
            raise SystemExit(
                "x86 opcode drift from kprog/x86/x86_sim.h: "
                f"spec={row['define']}={row['code']} "
                f"sim={defines[row['define']]:#x}")
        if canonical_name(row["define"]) != row["name"]:
            raise SystemExit(
                f"x86 opcode name {row['name']!r} is not the canonical "
                f"lowerCamelCase form of {row['define']}")
        if int(row["code"], 16) in seen:
            raise SystemExit(
                f"duplicate x86 opcode code {row['code']}: "
                f"{seen[int(row['code'], 16)]} and {row['define']}")
        seen[int(row["code"], 16)] = row["define"]
    for row in aliases:
        if alias_defines[row["define"]] != row["target"]:
            raise SystemExit(
                "x86 opcode alias drift from kprog/x86/x86_sim.h: "
                f"spec={row['define']}={row['target']} "
                f"sim={alias_defines[row['define']]}")
        if canonical_name(row["define"]) != row["name"]:
            raise SystemExit(
                f"x86 opcode alias name {row['name']!r} is not the canonical "
                f"lowerCamelCase form of {row['define']}")


def render_lean(rows):
    ctors = "\n".join(f"  | {row['name']}" for row in rows)
    codes = "\n".join(
        f"  | .{row['name']} => {int(row['code'], 16)}" for row in rows)
    defines = "\n".join(
        f'  | .{row["name"]} => "{row["define"]}"' for row in rows)
    return f'''-- Generated by generate_x86_opcode_spec.py from x86_opcode_spec.json.
import Std
namespace KProgFormal.GeneratedX86Opcode
/-- The opcode tokens the x86-64 simulator, the Lean model, and the artifact
encoder share. Each constructor is one `X86_OP_*` definition in
`kprog/x86/x86_sim.h`; the width-suffixed aliases are that header's own
spellings of an existing token and add no constructor here. -/
inductive Op where
{ctors}
  deriving DecidableEq, Repr
/-- The numeric opcode each token stands for. -/
def code : Op -> Nat
{codes}
/-- The `X86_OP_*` token spelling each constructor stands for. -/
def define : Op -> String
{defines}
end KProgFormal.GeneratedX86Opcode
'''


def render_c(rows, aliases):
    asserts = "\n".join(
        f'_Static_assert({row["define"]} == {row["code"]}U, '
        f'"x86 opcode {row["name"]} drift");' for row in rows)
    alias_asserts = "\n".join(
        f'_Static_assert({row["define"]} == {row["target"]}, '
        f'"x86 opcode {row["name"]} alias drift");' for row in aliases)
    count = len(rows)
    return f'''/* Generated by generate_x86_opcode_spec.py from x86_opcode_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_OPCODE_H
#define KPROG_FORMAL_GENERATED_X86_OPCODE_H
/*
 * The 72 canonical x86-64 opcode tokens and their numeric codes, re-derived
 * from kprog/x86/x86_sim.h at generation time. Each assert fails the build if
 * the header renumbers a token, so a simulator body, a Lean handler arm, and an
 * artifact step cannot silently disagree about what a token means. The five
 * width-suffixed aliases are pinned as identities with their target token,
 * because an alias names an existing opcode rather than introducing a code.
 */
{asserts}
{alias_asserts}
#define KPROG_X86_OPCODE_COUNT {count}U
#endif
'''


def render_python(rows):
    entries = "\n".join(
        f'    "{row["name"]}": "{row["define"]}",' for row in rows)
    by_define = "\n".join(
        f'    "{row["define"]}": "{row["name"]}",' for row in rows)
    return f'''# Generated by generate_x86_opcode_spec.py from x86_opcode_spec.json.
# The canonical name of each x86-64 opcode token; the artifact encoder resolves
# every opcode it emits through this table.
X86_OPCODE = {{
{entries}
}}
# The same table indexed by token, for checking a caller-supplied token.
X86_OPCODE_NAME = {{
{by_define}
}}
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    rows, aliases = spec()
    check_against_sim(rows, aliases)
    outputs = (
        (LEAN, render_lean(rows)),
        (C_HEADER, render_c(rows, aliases)),
        (PYTHON, render_python(rows)),
    )
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(f"generated x86 opcode contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
