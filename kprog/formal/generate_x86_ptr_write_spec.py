#!/usr/bin/env python3
"""Generate the x86-64 pointer-write provenance contract.

The two x86-64 opcodes `X86_SIM_L_EXEC` dispatches without a width —
`X86_OP_MOV_LOAD_MAP_PTR` and `X86_OP_MOV_LOAD_HELPER_ID` — both write a
register's *pointer* bits together with a provenance tag rather than a
width-confined lane: `MAP_PTR` writes `(void *)(long)IMM` with the map-pointer
tag, `HELPER_ID` writes a width-64 scalar lane first and then the same pointer
bits with the helper-id tag. The generated Lean definition
`GeneratedX86PtrWrite.tagOf` and the C selector `KPROG_X86_PTR_WRITE_TAG` carry
the opcode-to-tag table; `width64`/`KPROG_X86_PTR_WRITE_IS_HELPER_ID` carries the
one opcode fact the contract needs — only `HELPER_ID` performs the preliminary
width-64 scalar write.

The selector has three rows because the simulated tag space carries three
pointer-write tags (scalar, map-pointer, helper-id), but only the two pointer
opcodes reach it, each with exactly one fact set; the generated C selector
therefore has an out-of-range row (`KPROG_X86_PTR_WRITE_TAG_ANY`) that the Lean
side models as `none`, so the predicate is total. The tag codes are the sim's
`X86_SIM_TAG_*` values, which the host oracle pins; a tag code is *not* a width,
and neither opcode consults the `FLAGS` width the dispatch chain computed.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_ptr_write_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86PtrWrite.lean"
CHEADER = ROOT / "generated/x86_ptr_write.h"

EXPECTED = {
    "schema_version": 1,
    "operation": "x86PtrWrite",
    "selector": "opcode_then_provenance_tag",
    "tag_rows": [
        {
            "tag": "scalar",
            "code": 0,
            "tag_define": "KPROG_X86_PTR_WRITE_TAG_SCALAR",
            "sim_define": "X86_SIM_TAG_SCALAR",
        },
        {
            "tag": "mapPtr",
            "code": 5,
            "tag_define": "KPROG_X86_PTR_WRITE_TAG_MAP_PTR",
            "sim_define": "X86_SIM_TAG_MAP_PTR",
        },
        {
            "tag": "helperId",
            "code": 7,
            "tag_define": "KPROG_X86_PTR_WRITE_TAG_HELPER_ID",
            "sim_define": "X86_SIM_TAG_HELPER_ID",
        },
    ],
    "opcode_rows": [
        {
            "op": "movLoadMapPtr",
            "op_define": "X86_OP_MOV_LOAD_MAP_PTR",
            "op_code": "0x2c",
            "tag": "mapPtr",
            "writes_width64": False,
        },
        {
            "op": "movLoadHelperId",
            "op_define": "X86_OP_MOV_LOAD_HELPER_ID",
            "op_code": "0x2d",
            "tag": "helperId",
            "writes_width64": True,
        },
    ],
}

TAG_ORDER = ("scalar", "mapPtr", "helperId")
TAG_DEFINES = {
    "scalar": "KPROG_X86_PTR_WRITE_TAG_SCALAR",
    "mapPtr": "KPROG_X86_PTR_WRITE_TAG_MAP_PTR",
    "helperId": "KPROG_X86_PTR_WRITE_TAG_HELPER_ID",
}
TAG_CODES = {"scalar": 0, "mapPtr": 5, "helperId": 7}
TAG_SIM_DEFINES = {
    "scalar": "X86_SIM_TAG_SCALAR",
    "mapPtr": "X86_SIM_TAG_MAP_PTR",
    "helperId": "X86_SIM_TAG_HELPER_ID",
}

OP_ORDER = ("movLoadMapPtr", "movLoadHelperId")
OP_DEFINES = {
    "movLoadMapPtr": "X86_OP_MOV_LOAD_MAP_PTR",
    "movLoadHelperId": "X86_OP_MOV_LOAD_HELPER_ID",
}
OP_CODES = {"movLoadMapPtr": "0x2c", "movLoadHelperId": "0x2d"}
OP_TAGS = {"movLoadMapPtr": "mapPtr", "movLoadHelperId": "helperId"}
OP_WIDTH64 = {"movLoadMapPtr": False, "movLoadHelperId": True}


def load():
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 ptr-write specification: {data!r}")
    tag_rows = EXPECTED["tag_rows"]
    opcode_rows = EXPECTED["opcode_rows"]
    if [row["tag"] for row in tag_rows] != list(TAG_ORDER):
        raise SystemExit(f"invalid x86 ptr-write tag row order: {tag_rows!r}")
    if len({row["code"] for row in tag_rows}) != len(tag_rows):
        raise SystemExit(f"duplicate x86 ptr-write tag code: {tag_rows!r}")
    for row in tag_rows:
        if row["code"] != TAG_CODES[row["tag"]]:
            raise SystemExit(f"invalid x86 ptr-write tag code: {row!r}")
        if row["tag_define"] != TAG_DEFINES[row["tag"]]:
            raise SystemExit(f"invalid x86 ptr-write tag define: {row!r}")
        if row["sim_define"] != TAG_SIM_DEFINES[row["tag"]]:
            raise SystemExit(f"invalid x86 ptr-write sim tag: {row!r}")
    if [row["op"] for row in opcode_rows] != list(OP_ORDER):
        raise SystemExit(f"invalid x86 ptr-write opcode row order: {opcode_rows!r}")
    if len({row["op_code"] for row in opcode_rows}) != len(opcode_rows):
        raise SystemExit(f"duplicate x86 ptr-write opcode: {opcode_rows!r}")
    for row in opcode_rows:
        if row["op_define"] != OP_DEFINES[row["op"]]:
            raise SystemExit(f"invalid x86 ptr-write opcode define: {row!r}")
        if row["op_code"] != OP_CODES[row["op"]]:
            raise SystemExit(f"invalid x86 ptr-write opcode code: {row!r}")
        if row["tag"] != OP_TAGS[row["op"]]:
            raise SystemExit(f"invalid x86 ptr-write opcode tag: {row!r}")
        if row["writes_width64"] != OP_WIDTH64[row["op"]]:
            raise SystemExit(f"invalid x86 ptr-write width-64 flag: {row!r}")
        if row["tag"] == "scalar":
            raise SystemExit(f"x86 ptr-write opcode scalarizes: {row!r}")
    return tag_rows, opcode_rows


def render_lean(tag_rows, opcode_rows) -> str:
    tag_ctors = "\n".join(f"  | {row['tag']}" for row in tag_rows)
    op_ctors = "\n".join(f"  | {row['op']}" for row in opcode_rows)
    tag_table = "\n".join(
        f"  | .{row['op']} => .{row['tag']}" for row in opcode_rows)
    width_table = "\n".join(
        f"  | .{row['op']} => {'true' if row['writes_width64'] else 'false'}"
        for row in opcode_rows)
    # The selector mirrors the C `if/else if` chain over the two opcode facts,
    # map-pointer test first: the first binder varies slowest, and the all-true
    # row resolves to the map-pointer tag because that test precedes the
    # helper-id test. A real opcode sets exactly one fact.
    select = []
    for is_map_ptr in (True, False):
        for is_helper_id in (True, False):
            if is_map_ptr:
                select.append("  | true, {} => some .mapPtr".format(
                    "true" if is_helper_id else "false"))
            elif is_helper_id:
                select.append("  | false, true => some .helperId")
            else:
                select.append("  | false, false => none")
    select_table = "\n".join(select)
    code_table = "\n".join(
        f"  | .{row['tag']} => {row['code']}" for row in tag_rows)
    return f'''-- Generated by generate_x86_ptr_write_spec.py from x86_ptr_write_spec.json.
import Std
namespace KProgFormal.GeneratedX86PtrWrite
/-- The provenance tags a pointer write can carry. This is the simulated tag
space, not a width: every one of these tags names a class of register content,
and the plain `scalar` tag is a legal member of the table even though no
pointer-write opcode selects it. -/
inductive Tag where
{tag_ctors}
deriving DecidableEq, Repr
/-- The two x86-64 opcodes whose register write installs pointer bits and a
provenance tag without a width: the map-pointer load and the helper-id load. -/
inductive Op where
{op_ctors}
deriving DecidableEq, Repr
/-- The sim tag code each tag carries, pinned to the simulator's
`X86_SIM_TAG_*` values by the generated C header and the host oracle. A tag
code is not a width. -/
def code : Tag -> Nat
{code_table}
/-- The opcode-to-tag table: the one row per opcode the C dispatch chain
selects. `MAP_PTR` installs the map-pointer tag, `HELPER_ID` the helper-id
tag; no row is the scalar tag, because neither opcode scalarizes its
provenance. -/
def tagOf : Op -> Tag
{tag_table}
/-- Whether the opcode's write also performs a width-64 scalar lane write
before installing the pointer bits and tag. Only `HELPER_ID` does; `MAP_PTR`
writes no width at all. -/
def width64 : Op -> Bool
{width_table}
/-- The tag selector over the two opcode facts the C dispatch chain tests,
`MAP_PTR` first. A real opcode sets exactly one fact, so the selector is
single-valued there; the all-false row is the C chain's fallthrough, modelled
as `none` so the selector is total. -/
def tagOfSelectors (isMapPtr isHelperId : Bool) : Option Tag :=
  match isMapPtr, isHelperId with
{select_table}
end KProgFormal.GeneratedX86PtrWrite
'''


def render_c(tag_rows, opcode_rows) -> str:
    op_asserts = "\n".join(
        f'_Static_assert({row["op_define"]} == {row["op_code"]}U, '
        f'"x86 ptr-write {row["op"]} opcode drift");'
        for row in opcode_rows)
    tag_defines = "\n".join(
        f"#define {TAG_DEFINES[row['tag']]} {row['code']}U" for row in tag_rows)
    tag_checks = "\n".join(
        f'_Static_assert({TAG_DEFINES[row["tag"]]} == {row["sim_define"]}, '
        f'"x86 ptr-write {row["tag"]} tag drift");'
        for row in tag_rows)
    return f'''/* Generated by generate_x86_ptr_write_spec.py from x86_ptr_write_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_PTR_WRITE_H
#define KPROG_FORMAL_GENERATED_X86_PTR_WRITE_H
/*
 * x86-64 pointer-write provenance contract. `X86_OP_MOV_LOAD_MAP_PTR` and
 * `X86_OP_MOV_LOAD_HELPER_ID` are the two opcodes whose register write installs
 * pointer bits together with a provenance tag and no width-confined lane; the
 * generated selector carries the opcode-to-tag table, and the width-64 test
 * carries the one further opcode fact the contract needs - only `HELPER_ID`
 * performs a width-64 scalar lane write before the pointer write, which the
 * pointer write then replaces bit for bit. The two opcode arms call this
 * selector for the tag and then perform the pointer write through
 * X86_SIM_L_WRITE_REG_PTR_TAG.
 *
 * The tag codes are the sim's X86_SIM_TAG_* values and are pinned below; a tag
 * code is not a width, so neither opcode consults the FLAGS width the shared
 * dispatch chain computed.
 */
{op_asserts}
/* The provenance tag codes, in the sim's X86_SIM_TAG_* order. */
{tag_defines}
{tag_checks}
/* The C chain's fallthrough code: no opcode fact set. */
#define KPROG_X86_PTR_WRITE_TAG_ANY 0xffU
/*
 * IS_MAP_PTR and IS_HELPER_ID are the two opcode facts the dispatch chain
 * tests, in that order. A real opcode sets exactly one, yielding the
 * map-pointer or helper-id tag; the all-false row is the chain's fallthrough,
 * which reaches no register write and yields the out-of-range code. Each input
 * is evaluated once. No flags are written.
 */
#define KPROG_X86_PTR_WRITE_TAG(IS_MAP_PTR, IS_HELPER_ID)                   \\
\t({{                                                                 \\
\t\t__u8 __kprog_x86_pw_tag;                                      \\
\t\tif (IS_MAP_PTR)                                             \\
\t\t\t__kprog_x86_pw_tag = KPROG_X86_PTR_WRITE_TAG_MAP_PTR;\\
\t\telse if (IS_HELPER_ID)                                      \\
\t\t\t__kprog_x86_pw_tag =                                \\
\t\t\t\tKPROG_X86_PTR_WRITE_TAG_HELPER_ID;          \\
\t\telse                                                       \\
\t\t\t__kprog_x86_pw_tag = KPROG_X86_PTR_WRITE_TAG_ANY;   \\
\t\t__kprog_x86_pw_tag;                                        \\
\t}})
/*
 * TAG is a selected tag code. Only the helper-id tag carries the preliminary
 * width-64 scalar lane write; the map-pointer tag writes no width at all. TAG
 * is evaluated once. No flags are written.
 */
#define KPROG_X86_PTR_WRITE_IS_HELPER_ID(TAG)                               \\
\t((TAG) == KPROG_X86_PTR_WRITE_TAG_HELPER_ID)
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    tag_rows, opcode_rows = load()
    for path, expected in (
            (LEAN, render_lean(tag_rows, opcode_rows)),
            (CHEADER, render_c(tag_rows, opcode_rows))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 ptr-write contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
