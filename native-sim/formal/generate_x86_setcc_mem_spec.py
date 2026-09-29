#!/usr/bin/env python3
"""Generate the x86-64 `_SETCC_MEM` handler-composition contract.

The generated Lean module `GeneratedX86SetccMem` and the C header
`generated/x86_setcc_mem.h` carry the four facts the memory form of the
`SETCC` handler consults that its register form does not:

  - the condition code is read from the AUX *source-shift* byte at bits 24..31
    (`X86_REG_AUX_GET_SRC_SHIFT`), not from the register-lane payload byte at
    bits 0..7 that `X86_OP_SETCC` reads;
  - the access width is the opcode's constant 8-bit code, so the write always
    touches exactly one byte;
  - the base pointer is process null when the destination register is
    `X86_REG_NONE`, and the destination register's value otherwise;
  - the arm is the stack helper for an `X86_RSP` destination and the ordinary
    little-endian store for every other destination.

The two selectors are not independent booleans: both are tests of the same
destination register number, and `X86_REG_NONE` (0xff) is not `X86_RSP` (4), so
a null base can never take the stack arm. The generated tables are stated over
the decoded boolean predicates, which is what the C branch chain tests, and the
handler module proves the register-number statements refine them.

The condition *table* itself is not re-emitted: the memory form accepts the
same 14 `X86_CC_*` codes as the register form, so this contract composes the
generated `GeneratedX86Setcc.condOf` / `evalCond` table with the source-shift
byte decode rather than restating it.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_setcc_mem_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86SetccMem.lean"
CHEADER = ROOT / "generated/x86_setcc_mem.h"

# The raw codes of the two selectors, in the order of the generated tables: the
# Lean constructor, the C code, and the C define a caller compares against.
BASE_ORDER = (
    (True, "nullBase", "KPROG_X86_SETCC_MEM_BASE_NULL", 0),
    (False, "registerBase", "KPROG_X86_SETCC_MEM_BASE_REGISTER", 1),
)

ARM_ORDER = (
    (True, "stackWrite", "KPROG_X86_SETCC_MEM_ARM_STACK", 0),
    (False, "memoryStore", "KPROG_X86_SETCC_MEM_ARM_MEMORY", 1),
)

EXPECTED = {
    "schema_version": 1,
    "operation": "x86SetccMemHandler",
    "selector": "aux_source_shift_byte_condition_and_register_number",
    "opcode": {"define": "X86_OP_SETCC_MEM", "code": "0x3e"},
    "condition_field": {
        "field": "source_shift",
        "shift": 24,
        "mask": "0xff",
        "decoder": "X86_REG_AUX_GET_SRC_SHIFT",
        "lean": "conditionCode",
        "cond_table": "GeneratedX86Setcc.condOf",
    },
    "width": {"define": "X86_WIDTH_8", "code": 1, "bits": 8, "lean": "w8"},
    "none_reg": {"define": "X86_REG_NONE", "code": "0xff"},
    "rsp_reg": {"define": "X86_RSP", "code": "4"},
    "base_rows": [
        {
            "dst_is_none": is_none,
            "base": name,
            "base_define": define,
            "base_code": code,
        }
        for is_none, name, define, code in BASE_ORDER
    ],
    "arm_rows": [
        {
            "dst_is_rsp": is_rsp,
            "arm": name,
            "arm_define": define,
            "arm_code": code,
        }
        for is_rsp, name, define, code in ARM_ORDER
    ],
}

BASE_NAMES = {is_none: name for is_none, name, _, _ in BASE_ORDER}
BASE_DEFINES = {name: define for _, name, define, _ in BASE_ORDER}
BASE_CODES = {name: code for _, name, _, code in BASE_ORDER}
ARM_NAMES = {is_rsp: name for is_rsp, name, _, _ in ARM_ORDER}
ARM_DEFINES = {name: define for _, name, define, _ in ARM_ORDER}
ARM_CODES = {name: code for _, name, _, code in ARM_ORDER}


def load() -> tuple[list[dict], list[dict]]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 setcc_mem specification: {data!r}")
    base_rows = EXPECTED["base_rows"]
    arm_rows = EXPECTED["arm_rows"]
    if [row["dst_is_none"] for row in base_rows] != [r[0] for r in BASE_ORDER]:
        raise SystemExit(f"invalid x86 setcc_mem base row order: {base_rows!r}")
    for row in base_rows:
        name = BASE_NAMES[row["dst_is_none"]]
        if row["base"] != name:
            raise SystemExit(f"invalid x86 setcc_mem base: {row!r}")
        if row["base_define"] != BASE_DEFINES[name]:
            raise SystemExit(f"invalid x86 setcc_mem base define: {row!r}")
        if row["base_code"] != BASE_CODES[name]:
            raise SystemExit(f"invalid x86 setcc_mem base code: {row!r}")
    if [row["dst_is_rsp"] for row in arm_rows] != [r[0] for r in ARM_ORDER]:
        raise SystemExit(f"invalid x86 setcc_mem arm row order: {arm_rows!r}")
    for row in arm_rows:
        name = ARM_NAMES[row["dst_is_rsp"]]
        if row["arm"] != name:
            raise SystemExit(f"invalid x86 setcc_mem arm: {row!r}")
        if row["arm_define"] != ARM_DEFINES[name]:
            raise SystemExit(f"invalid x86 setcc_mem arm define: {row!r}")
        if row["arm_code"] != ARM_CODES[name]:
            raise SystemExit(f"invalid x86 setcc_mem arm code: {row!r}")
    return base_rows, arm_rows


def render_lean(base_rows: list[dict], arm_rows: list[dict]) -> str:
    base_table = "\n".join(
        f"  | {'true' if row['dst_is_none'] else 'false'} => .{row['base']}"
        for row in base_rows)
    arm_table = "\n".join(
        f"  | {'true' if row['dst_is_rsp'] else 'false'} => .{row['arm']}"
        for row in arm_rows)
    return f'''-- Generated by generate_x86_setcc_mem_spec.py from x86_setcc_mem_spec.json.
import KProgFormal.GeneratedX86Setcc
import KProgFormal.GeneratedX86Store
import KProgFormal.GeneratedX86Width
namespace KProgFormal.GeneratedX86SetccMem
/-- The AUX byte `X86_SIM_L_EXEC_SETCC_MEM` reads its condition code from: the
source-shift byte at bits 24..31, which is what `X86_REG_AUX_GET_SRC_SHIFT`
decodes. The register form `X86_OP_SETCC` reads the payload byte at bits 0..7
instead, so the same AUX word names different conditions for the two opcodes. -/
def conditionCode (aux : BitVec 32) : BitVec 8 := (aux >>> 24).setWidth 8
/-- The condition the raw source-shift byte denotes, composed with the generated
register-form condition table: the memory form accepts the same 14 `X86_CC_*`
codes out of the same 256-value byte space. -/
def condOf (aux : BitVec 32) : Option GeneratedX86Cond.Cond :=
  GeneratedX86Setcc.condOf (conditionCode aux)
/-- The raw condition evaluation: the generated condition table composed with
the generated expression table, and `false` for every unsupported code, which is
what the C macro's `: 0` default yields. -/
def evalRaw (cf zf sf of : Bool) (aux : BitVec 32) : Bool :=
  match condOf aux with
  | some cond => GeneratedX86Setcc.evalCond cf zf sf of cond
  | none => false
/-- The destination register number the handler treats as "no destination". -/
def noneReg : BitVec 8 := BitVec.ofNat 8 0xff
/-- The destination register number the stack helper stores into. -/
def rspReg : BitVec 8 := BitVec.ofNat 8 4
/-- The null-base test, the first branch the handler's base-pointer computation
performs. -/
def isNoneReg (reg : BitVec 8) : Bool := reg == noneReg
/-- The stack-arm test, an equality on the same destination register number the
null-base test consults. -/
def isRspReg (reg : BitVec 8) : Bool := reg == rspReg
/-- The base the handler forms before it selects an arm. -/
inductive Base where
  | nullBase
  | registerBase
  deriving DecidableEq, Repr
/-- The generated base table over the one fact the handler's base-pointer test
consults: whether the destination register is `X86_REG_NONE`. -/
def base : Bool -> Base
{base_table}
/-- The generated arm table over the one fact the handler's branch chain
consults: whether the destination register is the stack pointer. -/
def arm : Bool -> GeneratedX86Store.Arm
{arm_table}
/-- The access width is the opcode's constant 8-bit code, so neither a FLAGS
field nor an AUX memory-width field can move it. -/
def width : GeneratedX86Width.Width := .w8
end KProgFormal.GeneratedX86SetccMem
'''


def render_c(base_rows: list[dict], arm_rows: list[dict]) -> str:
    base_defines = "\n".join(
        f"#define {row['base_define']} {row['base_code']}U" for row in base_rows)
    arm_defines = "\n".join(
        f"#define {row['arm_define']} {row['arm_code']}U" for row in arm_rows)
    return f'''/* Generated by generate_x86_setcc_mem_spec.py from x86_setcc_mem_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_SETCC_MEM_H
#define KPROG_FORMAL_GENERATED_X86_SETCC_MEM_H
/*
 * x86-64 `SETCC_MEM` handler-composition contract. The condition code comes
 * from the AUX source-shift byte, the width is the opcode's constant 8-bit
 * code, and the destination register number drives both the base-pointer test
 * and the arm test. The contract selects these; the condition expression table
 * stays in KPROG_X86_EVAL_CC, the effective address in KPROG_X86_MEM_OFFSET,
 * and the write in KPROG_X86_MEM_STORE.
 */
#define KPROG_X86_SETCC_MEM_NONE_REG 0xffU
#define KPROG_X86_SETCC_MEM_RSP_REG 4U
/* The opcode's constant access width: the 8-bit width code, one byte wide. */
#define KPROG_X86_SETCC_MEM_WIDTH_CODE 1U
_Static_assert(KPROG_X86_SETCC_MEM_NONE_REG == X86_REG_NONE,
\t       "x86 setcc_mem null-base register drift");
_Static_assert(KPROG_X86_SETCC_MEM_RSP_REG == X86_RSP,
\t       "x86 setcc_mem stack register drift");
_Static_assert(KPROG_X86_SETCC_MEM_WIDTH_CODE == X86_WIDTH_8,
\t       "x86 setcc_mem width drift");
_Static_assert(X86_OP_SETCC_MEM == 0x3eU, "x86 setcc_mem opcode drift");
/*
 * AUX is the register AUX word. The condition code is the source-shift byte at
 * bits 24..31, the same field the register forms of the immediate store and
 * load handlers use for their shift amount; the payload byte at bits 0..7
 * names nothing for this opcode.
 */
#define KPROG_X86_SETCC_MEM_CONDITION(AUX) ((__u8)(((AUX) >> 24) & 0xffU))
/* The base-pointer codes. */
{base_defines}
/*
 * DST is the destination register number. KPROG_X86_SETCC_MEM_BASE_NULL means
 * the handler forms process null as the base pointer and adds the addressing
 * offset to it; the base test is evaluated before the arm test, so a null base
 * is what the arm store then writes through. DST is evaluated once.
 */
#define KPROG_X86_SETCC_MEM_BASE(DST)                                      \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_scm_base;                                 \\
\t\tif ((DST) == KPROG_X86_SETCC_MEM_NONE_REG)                    \\
\t\t\t__kprog_x86_scm_base =                                 \\
\t\t\t\tKPROG_X86_SETCC_MEM_BASE_NULL;                  \\
\t\telse                                                       \\
\t\t\t__kprog_x86_scm_base =                                 \\
\t\t\t\tKPROG_X86_SETCC_MEM_BASE_REGISTER;              \\
\t\t__kprog_x86_scm_base;                                       \\
\t}})
/* The arm codes. */
{arm_defines}
/*
 * DST_IS_RSP is true when the destination register number is the stack pointer;
 * a stack-pointer destination writes through the stack helper, every other
 * destination through the ordinary one-byte little-endian store. The null-base
 * register is not the stack pointer, so a null base always takes the memory
 * arm. DST_IS_RSP is evaluated once.
 */
#define KPROG_X86_SETCC_MEM_ARM(DST_IS_RSP)                                \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_scm_arm;                                  \\
\t\tif (DST_IS_RSP)                                            \\
\t\t\t__kprog_x86_scm_arm = KPROG_X86_SETCC_MEM_ARM_STACK;  \\
\t\telse                                                       \\
\t\t\t__kprog_x86_scm_arm =                                  \\
\t\t\t\tKPROG_X86_SETCC_MEM_ARM_MEMORY;                 \\
\t\t__kprog_x86_scm_arm;                                        \\
\t}})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    base_rows, arm_rows = load()
    for path, expected in (
            (LEAN, render_lean(base_rows, arm_rows)),
            (CHEADER, render_c(base_rows, arm_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 setcc_mem contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
