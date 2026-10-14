#!/usr/bin/env python3
"""Generate the shared x86 ALU op-step (result) contract for Lean and C.

The generated Lean definition `GeneratedX86AluResult.result` and the C macro
`KPROG_X86_ALU_RESULT` restate the sixteen ALU result formulas the x86-64
simulator's `x86_alu_result` dispatcher performs, one arm per `X86_ALU_*
operation code. The per-op expressions are the spec's `lean` and `c` strings;
arm expressions reference `(LHS)`/`(RHS)`/`(WIDTH)` and the delegated result
helpers (`KPROG_X86_ADC_RESULT`, `KPROG_X86_SBB_RESULT`,
`KPROG_X86_NOT_RESULT`, `kprog_x86_shl|shr|sar|rol_result`) exactly as the
hand-written dispatcher does, so the macro is the dispatcher's arm table
rather than a second formulation. The sixteen operations and their numeric
codes must match the ALU table of x86_alu_decode_spec.json exactly, so the
numeric case labels in the C macro track the `X86_ALU_*` constants of the
generated x86_alu_decode.h without including it. Any other operation code
takes the caller's `UNSUPPORTED` action with the result left at `(LHS)` (the
dispatcher's own fall-through returns the left operand; the simulator routes
only the sixteen real codes through it).
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_alu_result_spec.json"
DECODE_SPEC = ROOT / "x86_alu_decode_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86AluResult.lean"
CHEADER = ROOT / "generated/x86_alu_result.h"
SHIFT_NAMES = ("shl", "shr", "sar", "rol")
NAMES = ["add", "sub", "xor", "or", "and", "shl", "shr", "sar", "rol",
         "imul", "inc", "not", "sbb", "dec", "neg", "adc"]
OPERATION_BITS = 8
DEFAULT_LEAN = "lhs"
DEFAULT_C = "(LHS)"
EXPECTED = {
    "schema_version": 1,
    "operation": "x86AluResult",
    "operation_bits": OPERATION_BITS,
    "width_kind": "GeneratedX86Width.Width",
    "default_lean": DEFAULT_LEAN,
    "default_c": DEFAULT_C,
    "operations": [
        {"name": "add", "code": 0,
         "lean": "GeneratedX86Adc.result lhs rhs false",
         "c": "KPROG_X86_ADC_RESULT(LHS, RHS, 0)"},
        {"name": "sub", "code": 1,
         "lean": "GeneratedX86SbbResult.result lhs rhs false",
         "c": "KPROG_X86_SBB_RESULT(LHS, RHS, 0)"},
        {"name": "xor", "code": 2, "lean": "lhs ^^^ rhs",
         "c": "(LHS) ^ (RHS)"},
        {"name": "or", "code": 3, "lean": "lhs ||| rhs",
         "c": "(LHS) | (RHS)"},
        {"name": "and", "code": 4, "lean": "lhs &&& rhs",
         "c": "(LHS) & (RHS)"},
        {"name": "shl", "code": 5,
         "lean": "GeneratedX86ShiftResult.shl lhs rhs width",
         "c": "kprog_x86_shl_result(LHS, RHS, WIDTH)"},
        {"name": "shr", "code": 6,
         "lean": "GeneratedX86ShiftResult.shr lhs rhs width",
         "c": "kprog_x86_shr_result(LHS, RHS, WIDTH)"},
        {"name": "sar", "code": 7,
         "lean": "GeneratedX86ShiftResult.sar lhs rhs width",
         "c": "kprog_x86_sar_result(LHS, RHS, WIDTH)"},
        {"name": "rol", "code": 8,
         "lean": "GeneratedX86ShiftResult.rol lhs rhs width",
         "c": "kprog_x86_rol_result(LHS, RHS, WIDTH)"},
        {"name": "imul", "code": 9, "lean": "lhs * rhs",
         "c": "(LHS) * (RHS)"},
        {"name": "inc", "code": 10,
         "lean": "GeneratedX86Adc.result lhs 1 false",
         "c": "KPROG_X86_ADC_RESULT(LHS, 1, 0)"},
        {"name": "not", "code": 11,
         "lean": "GeneratedX86Not.result lhs",
         "c": "KPROG_X86_NOT_RESULT(LHS)"},
        {"name": "sbb", "code": 12,
         "lean": "GeneratedX86SbbResult.result lhs rhs false",
         "c": "KPROG_X86_SBB_RESULT(LHS, RHS, 0)"},
        {"name": "dec", "code": 13,
         "lean": "GeneratedX86SbbResult.result lhs 1 false",
         "c": "KPROG_X86_SBB_RESULT(LHS, 1, 0)"},
        {"name": "neg", "code": 14,
         "lean": "GeneratedX86SbbResult.result 0 lhs false",
         "c": "KPROG_X86_SBB_RESULT(0, LHS, 0)"},
        {"name": "adc", "code": 15,
         "lean": "GeneratedX86Adc.result lhs rhs false",
         "c": "KPROG_X86_ADC_RESULT(LHS, RHS, 0)"},
    ],
}


def load() -> list[dict]:
    data = json.loads(SPEC.read_text())
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 alu result specification: {data!r}")
    ops = EXPECTED["operations"]
    if [row["name"] for row in ops] != NAMES:
        raise SystemExit(f"invalid x86 alu operation order: {ops!r}")
    if [row["code"] for row in ops] != list(range(len(NAMES))):
        raise SystemExit(f"invalid x86 alu result codes: {ops!r}")
    if EXPECTED["default_lean"] != DEFAULT_LEAN:
        raise SystemExit("invalid x86 alu result default lean")
    if EXPECTED["default_c"] != DEFAULT_C:
        raise SystemExit("invalid x86 alu result default c")
    if EXPECTED["operation_bits"] != OPERATION_BITS:
        raise SystemExit("invalid x86 alu result operation bits")
    decode = json.loads(DECODE_SPEC.read_text())
    if (set(decode) != {"schema_version", "operation", "operations"}
            or decode["schema_version"] != 1
            or decode["operation"] != "x86AluDecode"):
        raise SystemExit(f"invalid x86 alu decode specification: {decode!r}")
    alu_table = decode["operations"]
    if [tuple(row[key] for key in ("mnemonic", "code"))
            for row in alu_table] != [
            (row["name"], row["code"]) for row in ops]:
        raise SystemExit(
            "x86 alu result codes drift from the x86 alu decode table: "
            f"result={[(row['name'], row['code']) for row in ops]} "
            f"decode={[(row['mnemonic'], row['code']) for row in alu_table]}")
    for row in ops:
        if (row["name"] in SHIFT_NAMES) != \
                ("GeneratedX86ShiftResult." in row["lean"]):
            raise SystemExit(
                f"invalid x86 alu result shift delegation: {row!r}")
            raise SystemExit("x86 alu result not arm must not read rhs")
    return ops


def render_lean(ops: list[dict]) -> str:
    arms = "\n".join(f"  | .{row['name']} => {row['lean']}" for row in ops)
    return f'''-- Generated by generate_x86_alu_result_spec.py from x86_alu_result_spec.json.
import KProgFormal.GeneratedX86AluDecode
import KProgFormal.GeneratedX86ShiftResult
import KProgFormal.GeneratedX86Adc
import KProgFormal.GeneratedX86SbbResult
import KProgFormal.GeneratedX86Not
namespace KProgFormal.GeneratedX86AluResult
open GeneratedX86AluDecode (Alu)
/-- Shared x86-64 ALU op-step result: the sixteen arm formulas the simulator's
`x86_alu_result` dispatcher selects between, keyed on the generated
`X86AluDecode` table. Shift arms delegate to the generated shift-result
helpers at the caller's width; every other code returns the left operand. -/
def result (op : Alu) (lhs rhs : BitVec 64) (width : GeneratedX86Width.Width) :
    BitVec 64 :=
  match op with
{arms}
end KProgFormal.GeneratedX86AluResult
'''


def render_c(ops: list[dict]) -> str:
    body = ["\t({", "\t\t__u64 __kprog_x86_alu_res = (LHS);",
            "\t\tswitch ((OP)) {"]
    for row in ops:
        body.append(f"\t\tcase {row['code']}U:")
        body.append(f"\t\t\t__kprog_x86_alu_res = {row['c']};")
        body.append("\t\t\tbreak;")
    body += [
        "\t\tdefault:",
        "\t\t\tUNSUPPORTED;",
        "\t\t\tbreak;",
        "\t\t}",
        "\t\t__kprog_x86_alu_res;",
    ]
    continued = " \\\n".join(body)
    head = '''/* Generated by generate_x86_alu_result_spec.py from x86_alu_result_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_ALU_RESULT_H
#define KPROG_FORMAL_GENERATED_X86_ALU_RESULT_H
/*
 * The numeric case labels 0U..15U track the X86_ALU_* values defined in
 * generated/x86_alu_decode.h. This header intentionally does not include
 * x86_alu_decode.h, so it stays usable standalone; load() re-checks the codes
 * against x86_alu_decode_spec.json and exits 1 if they drift. The shift arms
 * delegate to the generated shift-result helpers and the carry/borrow/not
 * arms to the generated one-step macros, so the macro restates the hand
 * dispatcher's arm expressions exactly and no result formula is duplicated.
 * The result starts at the left operand, so the default arm (every operation
 * code beyond the sixteen case labels) keeps it, and `UNSUPPORTED` is the
 * caller's action at that arm.
 */
#define KPROG_X86_ALU_RESULT(LHS, RHS, OP, WIDTH, UNSUPPORTED)              \\
'''
    return head + continued + " \\\n\t})\n#endif\n"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    ops = load()
    for path, expected in ((LEAN, render_lean(ops)),
                           (CHEADER, render_c(ops))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 alu result contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
