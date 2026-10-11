#!/usr/bin/env python3
"""Generate the shared x86 branch/select-mnemonic to condition-code contract.

The x86 artifact encoder spells a `jcc`/`cmovcc`/`setcc` condition as a textual
mnemonic (`ja`, `cmovbe`, `setns`, ...). Each mnemonic is a family prefix plus
the condition suffix; the encoder resolves the suffix to an `X86_CC_*` code in
`kprog/x86/x86_sim.h`, whose numeric values are the shared condition contract
`x86_cond_spec.json`. This generator renders that mnemonic -> code table to
Lean, C, and the encoder's own Python table from one specification, and
cross-checks every row against the condition contract read at load time.
"""

import argparse
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_cc_decode_spec.json"
COND_SPEC = ROOT / "x86_cond_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedX86CcDecode.lean"
C_HEADER = ROOT / "generated/x86_cc_decode.h"
PYTHON = ROOT.parent / "x86/micro-prog/generated_x86_cc_decode.py"

# The encoder's mnemonics, in the order `CC_AUX` defines them: the two-suffix
# jump family, then the three-suffix cmov family, then the set family. Every
# suffix is a condition name in `x86_cond_spec.json`; the parity names `o`/`no`
# are the two the encoder does not spell.
FAMILIES = ["j", "cmov", "set"]
SUFFIXES = ["a", "ae", "b", "be", "e", "ne", "g", "ge", "l", "le", "s", "ns"]
EXPECTED = [
    ("ja", "j", "a"),
    ("jae", "j", "ae"),
    ("jb", "j", "b"),
    ("jbe", "j", "be"),
    ("je", "j", "e"),
    ("jne", "j", "ne"),
    ("jg", "j", "g"),
    ("jge", "j", "ge"),
    ("jl", "j", "l"),
    ("jle", "j", "le"),
    ("js", "j", "s"),
    ("jns", "j", "ns"),
    ("cmova", "cmov", "a"),
    ("cmovb", "cmov", "b"),
    ("cmovbe", "cmov", "be"),
    ("cmove", "cmov", "e"),
    ("cmovg", "cmov", "g"),
    ("cmovge", "cmov", "ge"),
    ("cmovae", "cmov", "ae"),
    ("cmovl", "cmov", "l"),
    ("cmovle", "cmov", "le"),
    ("cmovne", "cmov", "ne"),
    ("cmovns", "cmov", "ns"),
    ("cmovs", "cmov", "s"),
    ("seta", "set", "a"),
    ("setae", "set", "ae"),
    ("setb", "set", "b"),
    ("setbe", "set", "be"),
    ("sete", "set", "e"),
    ("setg", "set", "g"),
    ("setge", "set", "ge"),
    ("setl", "set", "l"),
    ("setle", "set", "le"),
    ("setne", "set", "ne"),
    ("setns", "set", "ns"),
    ("sets", "set", "s"),
]


def cond_codes() -> dict[str, int]:
    """The condition suffix -> `X86_CC_*` code map, read from the shared
    condition contract rather than restated here."""
    spec = json.loads(COND_SPEC.read_text())
    if (set(spec) != {"schema_version", "operation", "conditions"}
            or spec["operation"] != "x86Condition"):
        raise SystemExit(f"invalid x86 condition specification: {spec!r}")
    return {condition["name"]: condition["code"]
            for condition in spec["conditions"]}


def load() -> list[dict[str, object]]:
    data = json.loads(SPEC.read_text())
    if (set(data) != {"schema_version", "operation", "families", "suffixes",
                      "rows"}
            or data["schema_version"] != 1
            or data["operation"] != "x86CcDecode"
            or data["families"] != FAMILIES
            or data["suffixes"] != SUFFIXES):
        raise SystemExit(f"invalid x86 cc decode specification: {data!r}")
    rows = data["rows"]
    if len(rows) != len(EXPECTED):
        raise SystemExit(f"invalid x86 cc decode row list: {rows!r}")
    codes = cond_codes()
    for row, expected in zip(rows, EXPECTED, strict=True):
        actual = (row.get("mnemonic"), row.get("family"), row.get("suffix"))
        if set(row) != {"mnemonic", "family", "suffix", "cond"}:
            raise SystemExit(f"non-canonical x86 cc decode row: {row!r}")
        if actual != expected:
            raise SystemExit(f"non-canonical x86 cc decode row: {row!r}")
        # The mnemonic is exactly the family prefix plus the suffix, the
        # suffix names the condition, and each suffix is a real condition.
        if row["cond"] != row["suffix"] or row["suffix"] not in codes:
            raise SystemExit(f"unknown x86 condition for row: {row!r}")
        if row["mnemonic"] != row["family"] + row["suffix"]:
            raise SystemExit(f"non-composed x86 cc decode mnemonic: {row!r}")
    for family in FAMILIES:
        present = [row["suffix"] for row in rows if row["family"] == family]
        if len(set(present)) != len(present):
            raise SystemExit(f"duplicate suffix in family {family!r}")
        if len(present) != len(SUFFIXES):
            raise SystemExit(f"family {family!r} is not exhaustive")
    if len({row["mnemonic"] for row in rows}) != len(rows):
        raise SystemExit("duplicate x86 cc decode mnemonic")
    return rows


def cond_name(row: dict[str, object]) -> str:
    return str(row["suffix"]).upper()


def c_define(row: dict[str, object]) -> str:
    return f"X86_CC_{cond_name(row)}"


def render_lean(rows: list[dict[str, object]], codes: dict[str, int]) -> str:
    families = "\n".join(f"  | {family}" for family in FAMILIES)
    ctors = "\n".join(f"  | {row['mnemonic']}" for row in rows)
    family_rows = "\n".join(
        f"  | .{row['mnemonic']} => .{row['family']}" for row in rows)
    family_text = "\n".join(f'  | .{family} => "{family}"'
                            for family in FAMILIES)
    suffixes = "\n".join(
        f'  | .{row["mnemonic"]} => "{row["suffix"]}"' for row in rows)
    mnemonics = "\n".join(
        f'  | .{row["mnemonic"]} => "{row["mnemonic"]}"' for row in rows)
    defines = "\n".join(
        f'  | .{row["mnemonic"]} => "{c_define(row)}"' for row in rows)
    code_rows = "\n".join(
        f"  | .{row['mnemonic']} => {codes[row['suffix']]}" for row in rows)
    return f'''-- Generated by generate_x86_cc_decode_spec.py from x86_cc_decode_spec.json.
import Std
namespace KProgFormal.GeneratedX86CcDecode
inductive Family
{families}
  deriving DecidableEq, Repr
inductive Mnemonic
{ctors}
  deriving DecidableEq, Repr
def family : Mnemonic -> Family
{family_rows}
def familyText : Family -> String
{family_text}
def suffix : Mnemonic -> String
{suffixes}
def mnemonic : Mnemonic -> String
{mnemonics}
def define : Mnemonic -> String
{defines}
def code : Mnemonic -> Nat
{code_rows}
end KProgFormal.GeneratedX86CcDecode
'''


def render_c(rows: list[dict[str, object]], codes: dict[str, int]) -> str:
    used = [suffix for suffix in SUFFIXES]
    asserts = "\n".join(
        f'_Static_assert(X86_CC_{suffix.upper()} == {codes[suffix]}U, '
        f'"x86 cc decode condition code drift");' for suffix in used)
    count = "\n".join(
        f"#define KPROG_X86_CC_DECODE_SUFFIX_{suffix.upper()} {index}U"
        for index, suffix in enumerate(used))
    text = "\n".join(
        f'#define KPROG_X86_CC_DECODE_SUFFIX_TEXT_{suffix.upper()} "{suffix}"'
        for suffix in used)
    arms = []
    for index, suffix in enumerate(used):
        prefix = "\t((SUFFIX)" if index == 0 else "\t (SUFFIX)"
        arms.append(f"{prefix} == KPROG_X86_CC_DECODE_SUFFIX_{suffix.upper()}"
                    f" ? X86_CC_{suffix.upper()} :")
    selector = " \\\n".join(arms)
    per_suffix = "\n".join(
        f'_Static_assert(KPROG_X86_CC_DECODE_CC('
        f'KPROG_X86_CC_DECODE_SUFFIX_{suffix.upper()}) == '
        f'X86_CC_{suffix.upper()}, "x86 cc decode suffix selection drift");'
        for suffix in used)
    family_defs = "\n".join(
        f'#define KPROG_X86_CC_DECODE_FAMILY_{family.upper()} "{family}"'
        for family in FAMILIES)
    mnemonic_defs = "\n".join(
        f'#define KPROG_X86_CC_DECODE_MNEMONIC_{row["mnemonic"].upper()} '
        f'"{row["mnemonic"]}"' for row in rows)
    return f'''/* Generated by generate_x86_cc_decode_spec.py from x86_cc_decode_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_CC_DECODE_H
#define KPROG_FORMAL_GENERATED_X86_CC_DECODE_H
/*
 * The x86 artifact encoder's textual `jcc`/`cmovcc`/`setcc` condition
 * mnemonics. A mnemonic is a family prefix plus a condition suffix; the
 * suffix alone selects the `X86_CC_*` code, whose numeric values are pinned
 * by the shared condition contract. The 12 suffixes this table reaches are
 * the condition names minus the parity pair `o`/`no`.
 */
{asserts}
#define KPROG_X86_CC_DECODE_SUFFIX_COUNT {len(used)}U
{count}
{text}
/*
 * The `X86_CC_*` code a suffix selects. The input is evaluated once. A suffix
 * code outside the table reaches the 0 default, which is not a suffix the
 * encoder ever produces; the table is total over its own suffix codes.
 */
#define KPROG_X86_CC_DECODE_CC(SUFFIX)                                      \\
{selector} \\
\t 0)
_Static_assert(KPROG_X86_CC_DECODE_SUFFIX_COUNT == {len(used)}U,
	       "x86 cc decode suffix count drift");
{per_suffix}
/* The selector is total: a suffix code past the table reaches the default. */
_Static_assert(KPROG_X86_CC_DECODE_CC(KPROG_X86_CC_DECODE_SUFFIX_COUNT) == 0,
	       "x86 cc decode absent suffix must reach the default arm");
/* The family prefixes the encoder composes its mnemonics from. */
{family_defs}
/* The 36 mnemonics the encoder spells, each the family prefix plus the suffix
 * text of the suffix it decodes to. */
{mnemonic_defs}
#endif
'''


def render_python(rows: list[dict[str, object]]) -> str:
    entries = "\n".join(
        f'    "{row["mnemonic"]}": "{c_define(row)}",' for row in rows)
    return f'''# Generated by generate_x86_cc_decode_spec.py from x86_cc_decode_spec.json.
CC_AUX = {{
{entries}
}}
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    rows = load()
    codes = cond_codes()
    outputs = (
        (LEAN, render_lean(rows, codes)),
        (C_HEADER, render_c(rows, codes)),
        (PYTHON, render_python(rows)),
    )
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 cc decode contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
