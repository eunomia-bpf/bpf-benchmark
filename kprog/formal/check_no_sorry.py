#!/usr/bin/env python3
"""Fail when the proof tree contains a placeholder or an added axiom.

`lake build` reports a `sorry` as a *warning* and still exits 0, so a gate
that only builds proves the tree compiles, not that it is complete: planting
`theorem t : (1 : Nat) = 1 := by sorry` in a generated module builds cleanly.
The README's "no `sorry`, no `axiom`" is therefore a property of the current
tree rather than something the gate enforces. This script enforces it.

Three placeholders are rejected: `sorry`, `admit`, and `axiom` declarations.
`native_decide`, `bv_decide`, and `omega` are proofs and are allowed.
"""
import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
MODULES = ROOT / "KProgFormal"

# A whole-word `sorry`/`admit` outside a line comment, and any `axiom`
# declaration. `sorryAx` and identifiers containing the word do not count.
PLACEHOLDER = re.compile(r"(?<![\w'])(sorry|admit)(?![\w'])")
AXIOM = re.compile(r"^\s*axiom\s+\w", re.M)


def strip_comments(text: str) -> str:
    text = re.sub(r"/-.*?-/", "", text, flags=re.S)
    return "\n".join(line.split("--")[0] for line in text.split("\n"))


def scan(path: pathlib.Path) -> list[str]:
    body = strip_comments(path.read_text())
    found = []
    for m in PLACEHOLDER.finditer(body):
        line = body[: m.start()].count("\n") + 1
        found.append(f"{path.relative_to(ROOT)}:{line}: {m.group(1)}")
    for m in AXIOM.finditer(body):
        line = body[: m.start()].count("\n") + 1
        found.append(f"{path.relative_to(ROOT)}:{line}: axiom declaration")
    return found


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true",
                        help="fail if any placeholder is present (the gate mode)")
    args = parser.parse_args()

    problems = []
    for path in sorted(MODULES.glob("*.lean")):
        problems.extend(scan(path))

    if args.check:
        if problems:
            for p in problems:
                print(f"placeholder in proof tree: {p}", file=sys.stderr)
            raise SystemExit(1)
        print(f"no sorry/admit/axiom in {len(list(MODULES.glob('*.lean')))} modules")
    else:
        for p in problems:
            print(p)


if __name__ == "__main__":
    main()
