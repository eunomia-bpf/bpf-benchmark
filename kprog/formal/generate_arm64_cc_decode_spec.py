#!/usr/bin/env python3
"""Generate the shared AArch64 condition-mnemonic to condition-code contract.

The AArch64 artifact encoder
(`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`) turns a textual
condition mnemonic into an `ARM64_COND_*` token. Seventeen mnemonics mark the
fifteen architectural condition codes: `cs`/`cc` are also spelled `hs`/`lo`,
so two mnemonics share each of those codes. The numeric codes themselves are
the shared `arm64_cond_spec.json` contract, re-read here so this table cannot
drift from the predicate the C simulator and the Lean model use.

Three outputs share one source:
  * `generated/arm64_cc_decode.h` — the C selector and its `_Static_assert`s
  * `KProgFormal/GeneratedArm64CcDecode.lean` — the Lean table
  * `kprog/arm64/micro-prog/generated_arm64_cc_decode.py` — the encoder's `COND`
"""

import argparse
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_cc_decode_spec.json"
COND_SPEC = ROOT / "arm64_cond_spec.json"
LEAN = ROOT / "KProgFormal/GeneratedArm64CcDecode.lean"
C_HEADER = ROOT / "generated/arm64_cc_decode.h"
PYTHON = ROOT.parent / "arm64/micro-prog/generated_arm64_cc_decode.py"

# The encoder's mnemonics, in the order `COND` defines them. The first two
# entries of each `cs`/`cc` pair are the canonical spellings; `hs` and `lo`
# are the architectural aliases. Every alias names a condition a canonical
# mnemonic also names.
EXPECTED: list[tuple[str, str, bool]] = [
    ("eq", "eq", False),
    ("ne", "ne", False),
    ("cs", "cs", False),
    ("hs", "cs", True),
    ("cc", "cc", False),
    ("lo", "cc", True),
    ("mi", "mi", False),
    ("pl", "pl", False),
    ("vs", "vs", False),
    ("vc", "vc", False),
    ("hi", "hi", False),
    ("ls", "ls", False),
    ("ge", "ge", False),
    ("lt", "lt", False),
    ("gt", "gt", False),
    ("le", "le", False),
    ("al", "al", False),
]


def cond_codes() -> list[tuple[str, int]]:
    """The `(name, code)` pairs of the shared condition contract, in its own
    order, read from `arm64_cond_spec.json` rather than restated here."""
    spec = json.loads(COND_SPEC.read_text())
    if (set(spec) != {"schema_version", "operation", "conditions"}
            or spec["operation"] != "arm64Condition"):
        raise SystemExit(f"invalid AArch64 condition specification: {spec!r}")
    return [(condition["name"], condition["code"])
            for condition in spec["conditions"]]


def load() -> list[dict[str, object]]:
    data = json.loads(SPEC.read_text())
    if (set(data) != {"schema_version", "operation", "rows"}
            or data["schema_version"] != 1
            or data["operation"] != "arm64CcDecode"):
        raise SystemExit(f"invalid AArch64 cc decode specification: {data!r}")
    rows = data["rows"]
    if len(rows) != len(EXPECTED):
        raise SystemExit(f"invalid AArch64 cc decode row list: {rows!r}")
    codes = dict(cond_codes())
    for row, expected in zip(rows, EXPECTED, strict=True):
        if set(row) != {"mnemonic", "cond", "alias"}:
            raise SystemExit(f"non-canonical AArch64 cc decode row: {row!r}")
        if (row["mnemonic"], row["cond"], row["alias"]) != expected:
            raise SystemExit(f"non-canonical AArch64 cc decode row: {row!r}")
        # Every row names a real condition.
        if row["cond"] not in codes:
            raise SystemExit(f"unknown AArch64 condition for row: {row!r}")
    # The canonical (non-alias) mnemonics name every condition exactly once,
    # in the contract's order; every alias names a condition a canonical
    # mnemonic also names, so the aliases add no new condition.
    canonical = [row["cond"] for row in rows if not row["alias"]]
    if canonical != [name for name, _ in cond_codes()]:
        raise SystemExit(f"non-exhaustive AArch64 cc decode mnemonics: {canonical!r}")
    for row in rows:
        if row["alias"] and row["cond"] not in canonical:
            raise SystemExit(f"AArch64 cc decode alias names no condition: {row!r}")
    if len({row["mnemonic"] for row in rows}) != len(rows):
        raise SystemExit("duplicate AArch64 cc decode mnemonic")
    return rows


def cond_name(row: dict[str, object]) -> str:
    return str(row["cond"]).upper()


def c_define(row: dict[str, object]) -> str:
    return f"ARM64_COND_{cond_name(row)}"


def mnemonic_ordinal(row: dict[str, object]) -> str:
    return str(row["mnemonic"]).upper()


def render_lean(rows: list[dict[str, object]], codes: dict[str, int]) -> str:
    ctors = "\n".join(f"  | {row['mnemonic']}" for row in rows)
    conds = "\n".join(
        f'  | .{row["mnemonic"]} => "{row["cond"]}"' for row in rows)
    mnemonics = "\n".join(
        f'  | .{row["mnemonic"]} => "{row["mnemonic"]}"' for row in rows)
    defines = "\n".join(
        f'  | .{row["mnemonic"]} => "{c_define(row)}"' for row in rows)
    code_rows = "\n".join(
        f"  | .{row['mnemonic']} => {codes[str(row['cond'])]}" for row in rows)
    alias_rows = "\n".join(
        f"  | .{row['mnemonic']} => {'true' if row['alias'] else 'false'}"
        for row in rows)
    return f'''-- Generated by generate_arm64_cc_decode_spec.py from arm64_cc_decode_spec.json.
import Std
namespace KProgFormal.GeneratedArm64CcDecode
inductive Mnemonic
{ctors}
  deriving DecidableEq, Repr
def cond : Mnemonic -> String
{conds}
def mnemonic : Mnemonic -> String
{mnemonics}
def define : Mnemonic -> String
{defines}
def code : Mnemonic -> Nat
{code_rows}
def isAlias : Mnemonic -> Bool
{alias_rows}
end KProgFormal.GeneratedArm64CcDecode
'''


def render_c(rows: list[dict[str, object]], codes: dict[str, int]) -> str:
    # One code pin per distinct condition, in contract order.
    asserts = "\n".join(
        f'_Static_assert(ARM64_COND_{name.upper()} == {code}U, '
        f'"AArch64 cc decode condition code drift");'
        for name, code in cond_codes())
    count = "\n".join(
        f"#define KPROG_ARM64_CC_DECODE_MNEMONIC_{mnemonic_ordinal(row)} {index}U"
        for index, row in enumerate(rows))
    text = "\n".join(
        f'#define KPROG_ARM64_CC_DECODE_MNEMONIC_TEXT_'
        f'{mnemonic_ordinal(row)} "{row["mnemonic"]}"' for row in rows)
    arms = []
    for index, row in enumerate(rows):
        prefix = "\t((MNEMONIC)" if index == 0 else "\t (MNEMONIC)"
        arms.append(f"{prefix} == KPROG_ARM64_CC_DECODE_MNEMONIC_"
                    f"{mnemonic_ordinal(row)} ? {c_define(row)} :")
    selector = " \\\n".join(arms)
    per_mnemonic = "\n".join(
        f'_Static_assert(KPROG_ARM64_CC_DECODE_COND('
        f'KPROG_ARM64_CC_DECODE_MNEMONIC_{mnemonic_ordinal(row)}) == '
        f'{c_define(row)}, "AArch64 cc decode mnemonic selection drift");'
        for row in rows)
    alias_rows = [row for row in rows if row["alias"]]
    aliases = "\n".join(
        f'_Static_assert(KPROG_ARM64_CC_DECODE_COND('
        f'KPROG_ARM64_CC_DECODE_MNEMONIC_{mnemonic_ordinal(row)}) == '
        f'ARM64_COND_{cond_name(row)}, "AArch64 cc decode alias drift");'
        for row in alias_rows)
    return f'''/* Generated by generate_arm64_cc_decode_spec.py from arm64_cc_decode_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_CC_DECODE_H
#define KPROG_FORMAL_GENERATED_ARM64_CC_DECODE_H
/*
 * The AArch64 artifact encoder's textual condition mnemonics. Every mnemonic
 * selects an `ARM64_COND_*` code, whose numeric values are pinned by the
 * shared condition contract. There are {len(rows)} mnemonics for {len(set(r["cond"] for r in rows))}
 * conditions: `hs` and `lo` are the architectural aliases of `cs` and `cc`.
 */
{asserts}
#define KPROG_ARM64_CC_DECODE_MNEMONIC_COUNT {len(rows)}U
#define KPROG_ARM64_CC_DECODE_CONDITION_COUNT {len(set(r["cond"] for r in rows))}U
{count}
{text}
/*
 * The `ARM64_COND_*` code a mnemonic selects. The input is evaluated once. A
 * mnemonic code outside the table reaches the 0 default; the table is total
 * over its own mnemonic codes.
 */
#define KPROG_ARM64_CC_DECODE_COND(MNEMONIC)                                \\
{selector} \\
\t 0)
_Static_assert(KPROG_ARM64_CC_DECODE_MNEMONIC_COUNT == {len(rows)}U,
	       "AArch64 cc decode mnemonic count drift");
_Static_assert(KPROG_ARM64_CC_DECODE_CONDITION_COUNT ==
	       {len(set(r["cond"] for r in rows))}U,
	       "AArch64 cc decode condition count drift");
{per_mnemonic}
/* The selector is total: a mnemonic code past the table reaches the default. */
_Static_assert(KPROG_ARM64_CC_DECODE_COND(
	KPROG_ARM64_CC_DECODE_MNEMONIC_COUNT) == 0,
	       "AArch64 cc decode absent mnemonic must reach the default arm");
/* The aliases name the same condition as their canonical spelling. */
{aliases}
#endif
'''


def render_python(rows: list[dict[str, object]]) -> str:
    entries = "\n".join(
        f'    "{row["mnemonic"]}": "{c_define(row)}",' for row in rows)
    return f'''# Generated by generate_arm64_cc_decode_spec.py from arm64_cc_decode_spec.json.
COND = {{
{entries}
}}
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    rows = load()
    codes = dict(cond_codes())
    outputs = (
        (LEAN, render_lean(rows, codes)),
        (C_HEADER, render_c(rows, codes)),
        (PYTHON, render_python(rows)),
    )
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated AArch64 cc decode contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
