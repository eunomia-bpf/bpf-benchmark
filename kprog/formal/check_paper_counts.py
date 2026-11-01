#!/usr/bin/env python3
"""Check the paper's claimed oracle case counts against a gate log.

The safety section states the case count of many oracles, and those figures are
hand-maintained. Ten occurrences of seven distinct numbers were stale when this
checker was widened, and none of them was caught by the narrower version that
read only the wrapped form. Four prose forms state a case count: the hyphenated
wrapped form `\\(167{,}480\\)-case routed oracle`, the same form without the math
wrapper, the ellipsis `71,664- and 536-case contract oracles`, and the spelled
form `over 9504 grid cases`. The wrapped form appears at 52 sites and the
unwrapped form at 178. The unwrapped form is the commonest by far, and it was
the one that drifted, because nothing read it: a clean report sat over every
stale figure.

This script extracts every claim it can from a section, reads the counts out of
a `make check` log, and reports any claim with no matching banner. It cannot
tell *which* banner a claim means, only that the number exists in the gate --
which is enough to catch a stale figure, since a stale one matches nothing.

Three prose shapes are deliberately not claims. A number inside `\\texttt{...}`
is quoted program output, describing what a run printed at the time; the MOVBE
`OK (16 cases)` line records a bug that no longer exists and matches nothing. A
number introduced by "plus" is one input family of an oracle ("15 fixed vectors
plus a 20,000-case sweep"), not the total any banner prints. And an `N-case`
adjective on a bare grid states arithmetic -- `1,470-case divide grid` is 2 x 5
x 7 x 3 x 7 -- so it is read only when the phrase also names a host or oracle.

Usage: check_paper_counts.py --section <tex> --log <make check log> [--check]
"""
import argparse
import pathlib
import re

NUM = r"\d[\d{},\\]*"

# A `\texttt{...}` argument may contain one level of braces (`\texttt{a\{b\}}`).
TEXTTT = re.compile(r"\\texttt\{(?:[^{}]|\{[^{}]*\})*\}")

# Cases a banner actually prints: the plain total, the helper-augmented total,
# and the vectors-plus-sweep total (printed as parts, claimed as a sum).
BANNER = [re.compile(r"OK \(([\d,]+) cases\)"),
          re.compile(r"OK \(([\d,]+) cases, [\d,]+ helpers\)"),
          re.compile(r"OK \((\d+) vectors \+ (\d+) sweep cases\)")]

# An `N-case` adjective states an oracle's total only when the phrase around it
# names an oracle or a host. A bare grid names arithmetic instead: "the routed
# 1,470-case divide grid" is 2 x 5 x 7 x 3 x 7, while that host's banner prints
# 48,515 because it compares 33 cells per divide. The window stops at sentence,
# clause, and em-dash punctuation so it cannot reach an unrelated host, and a
# single hyphen stays legal so `20,145-case byte-array-oracle sweep` is read.
ORACLE = re.compile(r"(?i)\b(?:host|oracle|oracles)\b")
GRID = re.compile(r"(?i)\bgrids?\b")
TAIL = r"(?:(?!--)[^.;:\n]){0,40}"

# Every prose form that states an oracle's case count. The `-case` forms carry
# the oracle-noun gate; `N cases` and `N grid cases` state a total outright.
CLAIMS = [
    re.compile(r"\\\((?P<n>%s)\\\)-case" % NUM),
    re.compile(r"(?<!\\\()(?P<n>%s)-case%s" % (NUM, TAIL)),
    re.compile(r"(?<!\\\()(?P<n>%s)-\s+and\s+%s-case%s" % ((NUM,) * 2 + (TAIL,))),
    re.compile(r"(?<![\d{},])(?P<n>%s)\s+(?:grids?\s+)?cases\b" % NUM),
]

# "over 6984 grid cases plus 458712 fixed-seed repeats" states one part of an
# oracle; the claim is true when the sum is what the banner prints.
PLUS = re.compile(r"^\s+plus\s+(?:a\s+|an\s+)?([\d,]{1,3}(?:,\d{3})+|\d+)")

# "plus a 20,000-case sweep" names one input family, not the oracle's total.
COMPONENT = re.compile(r"(?i)plus\s+(?:a\s+|an\s+)?$")


def log_counts(path: pathlib.Path) -> set[int]:
    """Every case count a banner prints, including a sum's parts."""
    text = path.read_text(errors="replace")
    counts: set[int] = set()
    for rx in BANNER:
        for match in rx.finditer(text):
            parts = [int(x.replace(",", "")) for x in match.groups()]
            counts.update(parts)
            if len(parts) > 1:
                counts.add(sum(parts))
    return counts


def paper_counts(path: pathlib.Path) -> dict[int, int]:
    """Return {claimed count: how many times it appears}."""
    # Quoted program output is not a claim about the current gate.
    text = TEXTTT.sub(lambda m: "X" * len(m.group(0)), path.read_text())
    seen: dict[int, int] = {}
    for index, rx in enumerate(CLAIMS):
        gated = index in (1, 2)
        total = index == len(CLAIMS) - 1
        for match in rx.finditer(text):
            if gated:
                phrase = text[match.start():match.end()]
                if not ORACLE.search(phrase) or GRID.search(phrase):
                    continue
            # "plus a 20,000-case sweep" names one input family, not a total.
            if COMPONENT.search(text[max(0, match.start() - 24):match.start()]):
                continue
            value = int(re.sub(r"[{},\\]", "", match.group("n")))
            if total:
                plus = PLUS.match(text[match.end():match.end() + 24])
                if plus:
                    value += int(plus.group(1).replace(",", ""))
            seen[value] = seen.get(value, 0) + 1
    return seen


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--section", default="sections/4-safety.tex")
    parser.add_argument("--log", required=True)
    parser.add_argument("--check", action="store_true",
                        help="exit 1 when a claim matches no banner")
    args = parser.parse_args()

    claimed = paper_counts(pathlib.Path(args.section))
    measured = log_counts(pathlib.Path(args.log))
    stale = sorted(c for c in claimed if c not in measured)

    for c in stale:
        print(f"claim {c:,} appears {claimed[c]}x but no banner reports it")
    if args.check and stale:
        raise SystemExit(1)
    if not stale:
        print(f"all {len(claimed)} claimed case counts appear in the gate log")


if __name__ == "__main__":
    main()
