#!/usr/bin/env python3
"""Fail when the proof tree contains a placeholder or an added axiom.

`lake build` reports a `sorry` as a *warning* and still exits 0, so a gate
that only builds proves the tree compiles, not that it is complete: planting
`theorem t : (1 : Nat) = 1 := by sorry` in a generated module builds cleanly.
The README's "no `sorry`, no `axiom`" is therefore a property of the current
tree rather than something the gate enforces. This script enforces it.

The README's claim is stronger than "no sorry": it says no `sorry`, no `axiom`,
and no `opaque`/`unsafe`/`partial` definitions. Each of those is checked here,
because each is a way to make a theorem true-by-assertion rather than by proof
and `lake build` treats every one of them as ordinary. `native_decide`,
`bv_decide`, and `omega` are proofs and are allowed.
"""
import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
MODULES = ROOT / "KProgFormal"

# A whole-word `sorry`/`admit` outside a line comment, and any `axiom`
# declaration. Identifier *suffixes* such as `mySorry` do not count, but the
# axiom itself does: `exact sorryAx _ true` proves any proposition, builds with
# only a warning, and was previously let through by the negative lookahead here,
# which is the one form of assertion the check most needed to catch.
PLACEHOLDER = re.compile(
    r"(?<![\w'])(?P<kw>sorry|admit)(?!\w)|(?<![\w'])sorryAx(?![\w'])")
# A declaration keyword in command position: `axiom foo`, `opaque foo`,
# `unsafe def foo`, `partial def foo`. Indented forms are commands inside a
# section or namespace, so leading whitespace is allowed.
DECL = re.compile(r"^\s*(axiom|opaque|unsafe|partial)\s", re.M)


def strip_comments(text: str) -> str:
    """Blank out block and line comments, respecting nesting.

    Lean's block comments nest, so the non-greedy `/-(.*?)-/` this used to
    apply closes at the *first* `-/`, which is the inner one, and everything
    the outer comment still covers is then scanned as code: either a false
    positive or a missed placeholder, depending on what the comment contains.
    Nesting is not decorative in this tree, so track depth.

    Comment characters become spaces and their newlines are kept, so a
    reported line number is the line number in the source.
    """
    out = []
    depth = 0
    i = 0
    n = len(text)
    while i < n:
        two = text[i:i + 2]
        if depth == 0 and two == "--":
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        if two == "/-":
            depth += 1
            i += 2
            continue
        if depth and two == "-/":
            depth -= 1
            i += 2
            continue
        c = text[i]
        if depth:
            out.append("\n" if c == "\n" else " ")
        else:
            out.append(c)
        i += 1
    return "".join(out)


def scan(path: pathlib.Path) -> list[str]:
    body = strip_comments(path.read_text())
    found = []
    for m in PLACEHOLDER.finditer(body):
        line = body[: m.start()].count("\n") + 1
        # Either alternative may match; report whichever did.
        found.append(
            f"{path.relative_to(ROOT)}:{line}: {m.groupdict()['kw'] or 'sorryAx'}")
    for m in DECL.finditer(body):
        line = body[: m.start()].count("\n") + 1
        found.append(
            f"{path.relative_to(ROOT)}:{line}: {m.group(1)} declaration")
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
        print(f"no sorry/admit/axiom/opaque/unsafe/partial in "
              f"{len(list(MODULES.glob('*.lean')))} modules")
    else:
        for p in problems:
            print(p)


if __name__ == "__main__":
    main()
