#!/usr/bin/env python3
"""Generate the x86-64 `_CMOV` / `_CMOV_MEM` handler-composition contract.

The check compares the JSON specification against the tables embedded here and
the rendered Lean and C against the modules on disk, so a hand edit to either
the spec or a generated file fails the `make check` target.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_cmov_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86Cmov.lean"
CHEADER = ROOT / "generated/x86_cmov.h"

# The two opcodes, and the condition source each one reads.
OPCODE_ORDER = (
    ("cmov", "X86_OP_CMOV", "0x15", "wholeWord"),
    ("cmovMem", "X86_OP_CMOV_MEM", "0x40", "sourceShift"),
)

# The two condition sources: the AUX field each decoder takes, and the Lean
# low-byte decoder that composes the truncating model onto the byte table.
CONDITION_ORDER = (
    ("wholeWord", "KPROG_X86_CMOV_CONDITION_WHOLE_WORD", 0,
     "aux_whole_word", "conditionByte"),
    ("sourceShift", "KPROG_X86_CMOV_CONDITION_SOURCE_SHIFT", 1,
     "aux_source_shift_byte", "sourceShiftCode"),
)

# The two writeback arms, selected by the 64-bit write-width test.
WRITEBACK_ORDER = (
    ("pointerTag", "KPROG_X86_CMOV_WRITEBACK_POINTER_TAG", 0, True),
    ("scalarize", "KPROG_X86_CMOV_WRITEBACK_SCALARIZE", 1, False),
)

# The 14 accepted `X86_CC_*` codes, as `KPROG_X86_EVAL_CC` compares them.
CONDITION_CODES = (
    (0, "o"), (1, "no"), (2, "b"), (3, "ae"), (4, "e"), (5, "ne"),
    (6, "be"), (7, "a"), (8, "s"), (9, "ns"), (12, "l"), (13, "ge"),
    (14, "le"), (15, "g"),
)


def _rows() -> tuple[list[dict], list[dict], list[dict], list[dict]]:
    condition_rows = [
        {
            "source": name,
            "source_define": define,
            "source_code": code,
            "decoder": decoder,
            "lean": lean,
        }
        for name, define, code, decoder, lean in CONDITION_ORDER
    ]
    opcode_rows = [
        {
            "op": name,
            "op_define": define,
            "op_code": code,
            "condition_source": source,
        }
        for name, define, code, source in OPCODE_ORDER
    ]
    writeback_rows = [
        {
            "is64": is64,
            "writeback": name,
            "writeback_define": define,
            "writeback_code": code,
        }
        for name, define, code, is64 in WRITEBACK_ORDER
    ]
    cond_rows = [{"code": code, "cond": cond} for code, cond in CONDITION_CODES]
    return opcode_rows, condition_rows, writeback_rows, cond_rows


OPCODE_ROWS, CONDITION_ROWS, WRITEBACK_ROWS, COND_ROWS = _rows()

EXPECTED = {
    "schema_version": 1,
    "operation": "x86CmovHandler",
    "selector": "aux_word_condition_and_flags_width_with_source_writeback",
    "opcode_rows": OPCODE_ROWS,
    "condition_rows": CONDITION_ROWS,
    "writeback_rows": WRITEBACK_ROWS,
    "condition_codes": COND_ROWS,
    "width": {
        "define": "X86_WIDTH_64",
        "code": 8,
        "field": "flags",
        "lean": "resolveWidth",
    },
    "mem_width": {
        "field": "aux_mem_width",
        "shift": 16,
        "mask": "0xff",
        "decoder": "X86_MEM_AUX_MEM_WIDTH",
        "fallback": "flags_width",
    },
    "disp": {
        "field": "imm_high_half",
        "shift": 32,
        "lean": "dispSpec",
    },
}


def load() -> tuple[list[dict], list[dict], list[dict], list[dict]]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 cmov specification: {data!r}")
    sources = {row["source"] for row in EXPECTED["condition_rows"]}
    for row in EXPECTED["opcode_rows"]:
        if row["condition_source"] not in sources:
            raise SystemExit(f"invalid x86 cmov condition source: {row!r}")
    ops = [row["op"] for row in EXPECTED["opcode_rows"]]
    if len(set(ops)) != len(ops):
        raise SystemExit(f"duplicate x86 cmov opcode: {ops!r}")
    codes = [row["code"] for row in EXPECTED["condition_codes"]]
    if len(set(codes)) != len(codes) or any(not 0 <= c < 256 for c in codes):
        raise SystemExit(f"invalid x86 cmov condition codes: {codes!r}")
    return (EXPECTED["opcode_rows"], EXPECTED["condition_rows"],
            EXPECTED["writeback_rows"], EXPECTED["condition_codes"])


def render_lean(opcode_rows: list[dict], condition_rows: list[dict],
                writeback_rows: list[dict], cond_rows: list[dict]) -> str:
    source_table = "\n".join(
        f"  | .{row['op']} => .{row['condition_source']}"
        for row in opcode_rows)
    decoder_table = "\n".join(
        f"  | .{row['source']} => {row['lean']}" for row in condition_rows)
    writeback_table = "\n".join(
        f"  | {'true' if row['is64'] else 'false'} => .{row['writeback']}"
        for row in writeback_rows)

    def chain(test: str, width: int) -> str:
        lines = []
        for i, row in enumerate(cond_rows):
            keyword = "if" if i == 0 else "else if"
            lines.append(f"  {keyword} {test} = BitVec.ofNat {width} "
                         f"{row['code']} then some .{row['cond']}")
        return "\n".join(lines)

    byte_table = chain("condByte", 8)
    word_table = chain("aux", 32)
    return f'''-- Generated by generate_x86_cmov_spec.py from x86_cmov_spec.json.
import KProgFormal.GeneratedX86Cond
import KProgFormal.GeneratedX86Setcc
import KProgFormal.GeneratedX86Store
namespace KProgFormal.GeneratedX86Cmov
open GeneratedX86Store (Code)
/-- The two opcodes this contract covers. -/
inductive X86CmovOp where
  | cmov
  | cmovMem
  deriving DecidableEq, Repr
/-- The low byte of the AUX word. `KPROG_X86_EVAL_CC`'s accepted codes are all
below 16, so a word whose bits 8..31 are zero names the same condition as its
low byte; outside that domain the whole-word comparison of the register form
rejects the word while this decode alone would still accept it, and only the
full-width test is faithful. -/
def conditionByte (aux : BitVec 32) : BitVec 8 := aux.setWidth 8
/-- The AUX byte the memory form `X86_OP_CMOV_MEM` reads its condition code
from: the source-shift byte at bits 24..31, which is what
`X86_REG_AUX_GET_SRC_SHIFT` decodes. The two opcodes name different conditions
with one encoding. -/
def sourceShiftCode (aux : BitVec 32) : BitVec 8 := (aux >>> 24).setWidth 8
/-- The condition source the handler selects for an opcode. -/
inductive ConditionSource where
  | wholeWord
  | sourceShift
  deriving DecidableEq, Repr
/-- The generated condition-source table, one row per opcode. -/
def conditionSource : X86CmovOp -> ConditionSource
{source_table}
/-- The AUX decode each condition source composes the byte table with. -/
def decode : ConditionSource -> BitVec 32 -> BitVec 8
{decoder_table}
/-- The AUX byte the composed byte-table model reads for an opcode. -/
def opConditionCode (op : X86CmovOp) (aux : BitVec 32) : BitVec 8 :=
  decode (conditionSource op) aux
/-- The condition a raw byte denotes: the byte compared against the accepted
`X86_CC_*` codes, and `none` for every code outside that subset (the parity
codes and every code from 16 up). The table is closed over the codes
`KPROG_X86_EVAL_CC` compares against, so an unsupported code is a defined
false, not a missing arm. -/
def condOfByte (condByte : BitVec 8) : Option GeneratedX86Cond.Cond :=
{byte_table}
  else none
/-- The condition the register form's *whole-word* comparison denotes: the AUX
word itself compared against the accepted codes, so a word with any of bits
8..31 set matches nothing and takes the C default. This is the faithful
statement of `KPROG_X86_EVAL_CC((AUX), ...)`. -/
def condOf (aux : BitVec 32) : Option GeneratedX86Cond.Cond :=
{word_table}
  else none
/-- The truncating byte-table model of the register form: the byte table
composed with the low-byte decode. It agrees with `condOf` exactly on the words
whose bits 8..31 are zero. -/
def condOfAux (aux : BitVec 32) : Option GeneratedX86Cond.Cond :=
  condOfByte (conditionByte aux)
/-- The memory form's condition table: the byte table composed with the
source-shift decode, out of the same 256-value byte space. The C handler
extracts a `__u8` here and promotes it to `int`, so the byte table is exact. -/
def condOfSrcShift (aux : BitVec 32) : Option GeneratedX86Cond.Cond :=
  condOfByte (sourceShiftCode aux)
/-- The condition table for an opcode, stated at the same AUX word for both
rows. -/
def condOfOp (op : X86CmovOp) (aux : BitVec 32) :
    Option GeneratedX86Cond.Cond :=
  match conditionSource op with
  | .wholeWord => condOf aux
  | .sourceShift => condOfSrcShift aux
/-- The condition expression table, a restatement of `KPROG_X86_EVAL_CC`'s
boolean arms: the same conditions, each with the same expression. -/
def evalCond (cf zf sf of : Bool) (cond : GeneratedX86Cond.Cond) : Bool :=
  GeneratedX86Setcc.evalCond cf zf sf of cond
/-- The raw condition evaluation of the register form's whole-word comparison:
the condition table composed with the expression table, and `false` for every
unsupported code, which is what the C macro's `: 0` default yields. -/
def evalRaw (cf zf sf of : Bool) (aux : BitVec 32) : Bool :=
  match condOf aux with
  | some cond => evalCond cf zf sf of cond
  | none => false
/-- The raw condition evaluation of an opcode at the same AUX word. -/
def evalRawOp (cf zf sf of : Bool) (op : X86CmovOp) (aux : BitVec 32) :
    Bool :=
  match condOfOp op aux with
  | some cond => evalCond cf zf sf of cond
  | none => false
/-- The write width the handler resolves from the opcode's FLAGS code, with a
64-bit fallback when it carries none. -/
def resolveWidth (flags : Code) : Code := GeneratedX86Store.resolveWidth flags
/-- The memory width of the memory form: the AUX memory-width byte when present
and otherwise the resolved write width — the same two-level fallback the shared
memory read uses. -/
def resolveMemWidth (aux flags : Code) : Code :=
  let write := resolveWidth flags
  if aux = Code.absent then write else aux
/-- The writeback arm the 64-bit write-width test selects. -/
inductive WriteBack where
  | pointerTag
  | scalarize
  deriving DecidableEq, Repr
/-- The generated writeback table over the one fact the handler's width test
consults: whether the resolved write width is 64 bits. -/
def writeBack : Bool -> WriteBack
{writeback_table}
end KProgFormal.GeneratedX86Cmov
'''


def render_c(opcode_rows: list[dict], condition_rows: list[dict],
             writeback_rows: list[dict], cond_rows: list[dict]) -> str:
    condition_defines = "\n".join(
        f"#define {row['source_define']} {row['source_code']}U"
        for row in condition_rows)
    writeback_defines = "\n".join(
        f"#define {row['writeback_define']} {row['writeback_code']}U"
        for row in writeback_rows)
    op_asserts = "\n".join(
        "_Static_assert(" + row["op_define"] + " == " + row["op_code"] +
        ("U, \"x86 cmov opcode drift\");" if row["op"] == "cmov" else
         "U, \"x86 cmov_mem opcode drift\");")
        for row in opcode_rows)
    return f'''/* Generated by generate_x86_cmov_spec.py from x86_cmov_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_CMOV_H
#define KPROG_FORMAL_GENERATED_X86_CMOV_H
/*
 * x86-64 `CMOV` / `CMOV_MEM` handler-composition contract. The register form's
 * condition code is the whole AUX word, the memory form's the AUX source-shift
 * byte at bits 24..31; the write width is the opcode's FLAGS code with a 64-bit
 * fallback, the memory form's access width has a second fallback to that write
 * width, and the writeback preserves the source's provenance only at 64 bits.
 * The contract selects these; the condition expression table stays in
 * KPROG_X86_EVAL_CC, the addressing offset in KPROG_X86_MEM_OFFSET, the memory
 * read dispatch in KPROG_X86_MEM_READ_SRC, the load in KPROG_X86_MEM_LOAD, and
 * the narrow write in KPROG_X86_WRITE_REG_WIDTH.
 */
{op_asserts}
_Static_assert(X86_WIDTH_64 == 8U, "x86 cmov width drift");
/*
 * The write width: the opcode's FLAGS code, or 64 bits when it carries none.
 * FLAGS is evaluated once.
 */
#define KPROG_X86_CMOV_WIDTH(FLAGS) \\
\t((__u8)((FLAGS) ? (FLAGS) : X86_WIDTH_64))
/*
 * The condition of the register form is the whole AUX word. `X86_SIM_L_EVAL_CC`
 * hands `KPROG_X86_EVAL_CC` all 32 bits, and the macro's positive `int`
 * `X86_CC_*` literals compare against the promoted word through C's usual
 * conversions: an equality on the low byte *and* a test that bits 8..31 are
 * zero. Truncating to the low byte before the call accepts words the real
 * comparison rejects, so the contract compares the whole word.
 */
#define KPROG_X86_CMOV_CONDITION(AUX) (AUX)
/* The condition-source codes. */
{condition_defines}
/*
 * The register form's low byte, and the memory form's condition code: the
 * source-shift byte at bits 24..31, the same field the register forms of the
 * store and load handlers use for their shift amount. This is the *truncating*
 * model of the register form, and the exact statement of the memory form, whose
 * C handler forms a `__u8` and promotes it back to `int`.
 */
#define KPROG_X86_CMOV_CONDITION_BYTE(AUX) ((__u8)(AUX))
#define KPROG_X86_CMOV_MEM_CONDITION(AUX) ((__u8)(((AUX) >> 24) & 0xffU))
/*
 * The memory form's access width: the AUX memory-width byte at bits 16..23, or
 * the resolved write width when the addressing mode carries none. AUX and FLAGS
 * are each evaluated once.
 */
#define KPROG_X86_CMOV_MEM_WIDTH(AUX, FLAGS) \\
\t((__u8)((((AUX) >> 16) & 0xffU) ? (((AUX) >> 16) & 0xffU) \\
\t\t: KPROG_X86_CMOV_WIDTH(FLAGS)))
/*
 * The memory form's displacement is the *high* half of the instruction artifact
 * sign-extended into 64 bits — the immediate store's slice, not the
 * whole-artifact slice the memory `SETCC` consumes.
 */
#define KPROG_X86_CMOV_MEM_DISP(IMM) ((__s64)(__s32)((IMM) >> 32))
/* The writeback codes. */
{writeback_defines}
/*
 * IS_64 is the result of the write-width test. At 64 bits the destination
 * receives the source's pointer and provenance tag verbatim; at every narrower
 * width the source is read at 64 bits and written through the scalarizing
 * partial-register write. IS_64 is evaluated once.
 */
#define KPROG_X86_CMOV_WRITEBACK(IS_64)                                    \\
\t({{                                                                \\
\t\t__u8 __kprog_x86_cmov_wb;                                 \\
\t\tif (IS_64)                                                \\
\t\t\t__kprog_x86_cmov_wb =                                  \\
\t\t\t\tKPROG_X86_CMOV_WRITEBACK_POINTER_TAG;           \\
\t\telse                                                       \\
\t\t\t__kprog_x86_cmov_wb =                                  \\
\t\t\t\tKPROG_X86_CMOV_WRITEBACK_SCALARIZE;             \\
\t\t__kprog_x86_cmov_wb;                                       \\
\t}})
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    for path, render in ((LEAN, render_lean), (CHEADER, render_c)):
        expected = render(*load())
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 cmov contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
