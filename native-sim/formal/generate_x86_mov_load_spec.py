#!/usr/bin/env python3
"""Generate the x86-64 `MOV_LOAD` handler-composition contract.

This contract models `X86_SIM_L_EXEC_MOV_LOAD`, the single handler body that
`X86_OP_MOV_LOAD`, `X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD` all route
to. Two things are generated.

1. `width_rows` resolves the *two* width codes the handler computes from the
   memory width field of AUX and the opcode's `FLAGS` code:

     ::

         write_width = FLAGS ? FLAGS : X86_WIDTH_64
         mem_width   = X86_MEM_AUX_MEM_WIDTH(AUX)
         if (!mem_width) mem_width = write_width

   The fallback chain is what makes this selector different from the shared
   read body's own `X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)`: here an absent AUX
   memory width is filled from the *write* width, and an absent write width is
   filled from 64 bits, so an AUX-absent access reads at the opcode's write
   width. The table is closed over the five `X86_WIDTH_*` codes (including the
   0 "absent" code), so both resolutions are total and have no unsupported arm.

2. `arm_rows` is the closed arm table over the five facts the handler's branch
   chain consults: whether the base register is the stack pointer (register
   identity), whether the opcode is `_MOV_LOAD`, whether the resolved memory
   width is 64 bits, whether the resolved write width is 64 bits, and whether
   the base register carries the ABI tag. The arms are:

     - `stackRead` — a stack-pointer base always reads through the stack
       helper, at any width and whatever the base register's tag;
     - `abiPtrWrite` — only `_MOV_LOAD` at 64-bit memory *and* 64-bit write
       width with an ABI-tagged non-stack base; this arm writes the loaded
       pointer together with its ABI provenance tag;
     - `ordinary` — every other access: an ordinary byte-ladder load at the
       resolved memory width (sign-extended for `_MOVSX_LOAD`) followed by a
       partial-register write at the resolved write width.

   The x86-specific asymmetries: the first test is register identity rather
   than a memory tag, so the stack arm overrides the ABI arm; the ABI arm is
   gated on `_MOV_LOAD` (neither `_MOV_LOAD_SCALAR` nor `_MOVSX_LOAD` can take
   it); and the ABI arm is additionally gated on a 64-bit write width, so an
   ABI base reached by a narrow opcode falls through to the ordinary scalar
   load. The contract selects the arm and resolves the two widths; it does not
   restate the value transformation (sign extension) or the ABI tag policy.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_mov_load_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86MovLoad.lean"
CHEADER = ROOT / "generated/x86_mov_load.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86MovLoadHandler",
    "selector": "width_resolution_then_op_and_abi_tag_arm",
    "width_rows": [
        {"aux_width": 0, "flags_width": 0, "mem_width": 8,
         "write_width": 8, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_64"},
        {"aux_width": 0, "flags_width": 1, "mem_width": 1,
         "write_width": 1, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_8"},
        {"aux_width": 0, "flags_width": 2, "mem_width": 2,
         "write_width": 2, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_16"},
        {"aux_width": 0, "flags_width": 4, "mem_width": 4,
         "write_width": 4, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_32"},
        {"aux_width": 0, "flags_width": 8, "mem_width": 8,
         "write_width": 8, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_64"},
        {"aux_width": 1, "flags_width": 0, "mem_width": 1,
         "write_width": 8, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_64"},
        {"aux_width": 1, "flags_width": 1, "mem_width": 1,
         "write_width": 1, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_8"},
        {"aux_width": 1, "flags_width": 2, "mem_width": 1,
         "write_width": 2, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_16"},
        {"aux_width": 1, "flags_width": 4, "mem_width": 1,
         "write_width": 4, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_32"},
        {"aux_width": 1, "flags_width": 8, "mem_width": 1,
         "write_width": 8, "mem_define": "X86_WIDTH_8", "write_define": "X86_WIDTH_64"},
        {"aux_width": 2, "flags_width": 0, "mem_width": 2,
         "write_width": 8, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_64"},
        {"aux_width": 2, "flags_width": 1, "mem_width": 2,
         "write_width": 1, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_8"},
        {"aux_width": 2, "flags_width": 2, "mem_width": 2,
         "write_width": 2, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_16"},
        {"aux_width": 2, "flags_width": 4, "mem_width": 2,
         "write_width": 4, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_32"},
        {"aux_width": 2, "flags_width": 8, "mem_width": 2,
         "write_width": 8, "mem_define": "X86_WIDTH_16", "write_define": "X86_WIDTH_64"},
        {"aux_width": 4, "flags_width": 0, "mem_width": 4,
         "write_width": 8, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_64"},
        {"aux_width": 4, "flags_width": 1, "mem_width": 4,
         "write_width": 1, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_8"},
        {"aux_width": 4, "flags_width": 2, "mem_width": 4,
         "write_width": 2, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_16"},
        {"aux_width": 4, "flags_width": 4, "mem_width": 4,
         "write_width": 4, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_32"},
        {"aux_width": 4, "flags_width": 8, "mem_width": 4,
         "write_width": 8, "mem_define": "X86_WIDTH_32", "write_define": "X86_WIDTH_64"},
        {"aux_width": 8, "flags_width": 0, "mem_width": 8,
         "write_width": 8, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_64"},
        {"aux_width": 8, "flags_width": 1, "mem_width": 8,
         "write_width": 1, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_8"},
        {"aux_width": 8, "flags_width": 2, "mem_width": 8,
         "write_width": 2, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_16"},
        {"aux_width": 8, "flags_width": 4, "mem_width": 8,
         "write_width": 4, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_32"},
        {"aux_width": 8, "flags_width": 8, "mem_width": 8,
         "write_width": 8, "mem_define": "X86_WIDTH_64", "write_define": "X86_WIDTH_64"},
    ],
    "arm_rows": [
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": True, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": True, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": False, "arm": "stackRead",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_STACK"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": True, "arm": "abiPtrWrite",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ABI_PTR"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": True, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": True, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": True,
         "write_is_64": False, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": True, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": True, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
        {"is_rsp": False, "is_mov_load": False, "mem_is_64": False,
         "write_is_64": False, "base_is_abi": False, "arm": "ordinary",
         "arm_define": "KPROG_X86_MOV_LOAD_ARM_ORDINARY"},
    ],
}

WIDTH_ORDER = (0, 1, 2, 4, 8)

ARM_ORDER = tuple(
    (is_rsp, is_mov_load, mem64, write64, is_abi)
    for is_rsp in (True, False)
    for is_mov_load in (True, False)
    for mem64 in (True, False)
    for write64 in (True, False)
    for is_abi in (True, False))

ARM_DEFINES = {
    "stackRead": "KPROG_X86_MOV_LOAD_ARM_STACK",
    "abiPtrWrite": "KPROG_X86_MOV_LOAD_ARM_ABI_PTR",
    "ordinary": "KPROG_X86_MOV_LOAD_ARM_ORDINARY",
}

ARM_CODES = {"stackRead": 0, "abiPtrWrite": 1, "ordinary": 2}

WIDTH_DEFINES = {
    0: "KPROG_X86_MOV_LOAD_WIDTH_ABSENT",
    1: "X86_WIDTH_8",
    2: "X86_WIDTH_16",
    4: "X86_WIDTH_32",
    8: "X86_WIDTH_64",
}


def load() -> tuple[list[dict], list[dict]]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 mov-load specification: {data!r}")
    width_rows = EXPECTED["width_rows"]
    arm_rows = EXPECTED["arm_rows"]
    if [(row["aux_width"], row["flags_width"]) for row in width_rows] != \
            [(a, f) for a in WIDTH_ORDER for f in WIDTH_ORDER]:
        raise SystemExit(f"invalid x86 mov-load width row order: {width_rows!r}")
    for row in width_rows:
        write = row["flags_width"] or 8
        mem = row["aux_width"] or write
        if (row["write_width"], row["mem_width"]) != (write, mem):
            raise SystemExit(f"invalid x86 mov-load width resolution: {row!r}")
        if row["write_define"] != WIDTH_DEFINES[write]:
            raise SystemExit(f"invalid x86 mov-load write define: {row!r}")
        if row["mem_define"] != WIDTH_DEFINES[mem]:
            raise SystemExit(f"invalid x86 mov-load mem define: {row!r}")
    if [(row["is_rsp"], row["is_mov_load"], row["mem_is_64"],
         row["write_is_64"], row["base_is_abi"]) for row in arm_rows] != \
            list(ARM_ORDER):
        raise SystemExit(f"invalid x86 mov-load arm row order: {arm_rows!r}")
    for row in arm_rows:
        if row["is_rsp"]:
            arm = "stackRead"
        elif (row["is_mov_load"] and row["mem_is_64"] and
              row["write_is_64"] and row["base_is_abi"]):
            arm = "abiPtrWrite"
        else:
            arm = "ordinary"
        if row["arm"] != arm:
            raise SystemExit(f"invalid x86 mov-load arm: {row!r}")
        if row["arm_define"] != ARM_DEFINES[arm]:
            raise SystemExit(f"invalid x86 mov-load arm define: {row!r}")
    return width_rows, arm_rows


def render_lean(width_rows: list[dict], arm_rows: list[dict]) -> str:
    code_of = {0: "absent", 1: "b8", 2: "b16", 4: "b32", 8: "b64"}
    width_table = "\n".join(
        f"  | .{code_of[row['aux_width']]}, .{code_of[row['flags_width']]} => "
        f"(.{code_of[row['write_width']]}, .{code_of[row['mem_width']]})"
        for row in width_rows)
    arm_table = "\n".join(
        f"  | {'true' if row['is_rsp'] else 'false'}, "
        f"{'true' if row['is_mov_load'] else 'false'}, "
        f"{'true' if row['mem_is_64'] else 'false'}, "
        f"{'true' if row['write_is_64'] else 'false'}, "
        f"{'true' if row['base_is_abi'] else 'false'} => .{row['arm']}"
        for row in arm_rows)
    return f'''-- Generated by generate_x86_mov_load_spec.py from x86_mov_load_spec.json.
import Std
namespace KProgFormal.GeneratedX86MovLoad
/-- The five width codes an x86 access width can carry, including the `absent`
code 0 used when the addressing mode or opcode supplies none. -/
inductive Code where
  | absent
  | b8
  | b16
  | b32
  | b64
deriving DecidableEq, Repr
/-- The resolved write and memory widths of a `MOV_LOAD`, returned as the pair
`(write_width, mem_width)`. The write width defaults to 64 bits when the opcode
carries no width, and the memory width defaults to the resolved write width
when the addressing mode carries none. -/
def resolveWidth : Code -> Code -> Code \u00d7 Code
{width_table}
/-- The arm the `MOV_LOAD` handler selects. -/
inductive Arm where
  | stackRead
  | abiPtrWrite
  | ordinary
  deriving DecidableEq, Repr
/-- The generated arm table over the five facts the handler's branch chain
consults: register identity, the opcode, the two resolved widths, and the base
register's memory tag. -/
def arm : Bool -> Bool -> Bool -> Bool -> Bool -> Arm
{arm_table}
end KProgFormal.GeneratedX86MovLoad
'''


def render_c(width_rows: list[dict], arm_rows: list[dict]) -> str:
    arm_defines = "\n".join(
        f"#define {name} {code}U"
        for name, code in (("KPROG_X86_MOV_LOAD_ARM_STACK", 0),
                           ("KPROG_X86_MOV_LOAD_ARM_ABI_PTR", 1),
                           ("KPROG_X86_MOV_LOAD_ARM_ORDINARY", 2)))
    width_defines = "\n".join(
        f"#define {WIDTH_DEFINES[code]} {code}U"
        for code in (8, 1, 2, 4, 0))
    return f'''/* Generated by generate_x86_mov_load_spec.py from x86_mov_load_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_MOV_LOAD_H
#define KPROG_FORMAL_GENERATED_X86_MOV_LOAD_H
/*
 * x86-64 `MOV_LOAD` handler-composition contract. The width resolution is
 * closed over the five X86_WIDTH_* codes (including the 0 "absent" code): the
 * write width defaults to 64 bits and the memory width defaults to the write
 * width, so both are total and there is no unsupported arm. The arm table is
 * closed over its five selector facts. Unlike the shared read body the first
 * test is register identity (is the base the stack pointer) rather than a
 * memory tag, the ABI pointer arm is gated on `_MOV_LOAD` and on a 64-bit
 * write width, and every other access takes the ordinary scalar load at the
 * resolved memory width. The contract selects an arm and resolves the two
 * widths; the value transformation (sign extension) and the ABI tag policy
 * stay in X86_SIM_L_EXEC_MOV_LOAD.
 */
{arm_defines}

/* The AUX memory-width codes, including the 0 "absent" code. */
{width_defines}
/*
 * FLAGS_WIDTH is the opcode's FLAGS code, 0 when it carries none; the write
 * width defaults to 64 bits. No flags are written.
 */
#define KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS_WIDTH)                         \\
\t({{                                                                 \\
\t\t__u8 __kprog_x86_ml_write = (FLAGS_WIDTH) ?                    \\
\t\t\t(FLAGS_WIDTH) : X86_WIDTH_64;                           \\
\t\t__kprog_x86_ml_write;                                       \\
\t}})
/*
 * AUX is the addressing AUX word; its memory-width field is 0 when the mode
 * carries no width, in which case the write width is used. Each input is
 * evaluated once. No flags are written.
 */
#define KPROG_X86_MOV_LOAD_MEM_WIDTH(FLAGS_WIDTH, AUX)                      \\
\t({{                                                                 \\
\t\t__u8 __kprog_x86_ml_mem = X86_MEM_AUX_MEM_WIDTH(AUX);          \\
\t\tif (!__kprog_x86_ml_mem)                                    \\
\t\t\t__kprog_x86_ml_mem =                                 \\
\t\t\t\tKPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS_WIDTH);    \\
\t\t__kprog_x86_ml_mem;                                         \\
\t}})
/*
 * BASE_IS_RSP is true when the base register is the stack pointer; IS_MOV_LOAD
 * is true only for the plain `_MOV_LOAD` opcode; MEM_WIDTH and WRITE_WIDTH are
 * the two resolved width codes; BASE_TAG is the base register's memory tag.
 * Each input is evaluated once. No flags are written.
 */
#define KPROG_X86_MOV_LOAD_ARM(BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH,         \\
\t\t\t       WRITE_WIDTH, BASE_TAG)                       \\
\t({{                                                                 \\
\t\t__u8 __kprog_x86_ml_arm;                                    \\
\t\tif (BASE_IS_RSP)                                            \\
\t\t\t__kprog_x86_ml_arm = KPROG_X86_MOV_LOAD_ARM_STACK;  \\
\t\telse if ((IS_MOV_LOAD) &&                                   \\
\t\t\t (MEM_WIDTH) == X86_WIDTH_64 &&                     \\
\t\t\t (WRITE_WIDTH) == X86_WIDTH_64 &&                   \\
\t\t\t (BASE_TAG) == X86_SIM_TAG_ABI)                     \\
\t\t\t__kprog_x86_ml_arm =                                 \\
\t\t\t\tKPROG_X86_MOV_LOAD_ARM_ABI_PTR;              \\
\t\telse                                                        \\
\t\t\t__kprog_x86_ml_arm =                                 \\
\t\t\t\tKPROG_X86_MOV_LOAD_ARM_ORDINARY;             \\
\t\t__kprog_x86_ml_arm;                                         \\
\t}})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    width_rows, arm_rows = load()
    for path, expected in ((LEAN, render_lean(width_rows, arm_rows)),
                           (CHEADER, render_c(width_rows, arm_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 mov-load contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
