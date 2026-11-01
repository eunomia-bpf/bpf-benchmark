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
which is enough to catch a stale figure, since a stale one matches nothing. The
section's two gate-wide figures, the banner count and the modeled-case sum, are
re-derived exactly rather than matched by existence, because both are stated
once and countable from the log.

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

# A banner prints its case count three ways: the plain total, the plain total
# beside a helper count, and the vectors-plus-sweep total as its two parts.
# `summed` says whether the banner's modeled-case total is the sum of the
# numbers it prints -- the helper count is a different unit, so it is a legal
# claim but not part of the modeled-case sum.
BANNER = [(re.compile(r"OK \(([\d,]+) cases\)"), False),
          (re.compile(r"OK \(([\d,]+) cases, [\d,]+ helpers\)"), False),
          (re.compile(r"OK \((\d+) vectors \+ (\d+) sweep cases\)"), True)]

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

# The section's two aggregate claims about the gate as a whole. Both are
# re-derivable from the same log, so quoting them in two places is a drift risk.
AGGREGATES = [(re.compile(r"(?P<n>%s) independent oracle banners" % NUM),
               "banners"),
              (re.compile(r"summing to (?P<n>%s) modeled cases" % NUM),
               "modeled cases")]


def masked(path: pathlib.Path) -> str:
    """The section with quoted program output blanked out."""
    return TEXTTT.sub(lambda m: "X" * len(m.group(0)), path.read_text())


def read_log(path: pathlib.Path) -> tuple[set[int], int, int]:
    """Return ({case count a banner prints}, banner count, modeled-case sum).

    A banner's numbers are legal claims individually and summed: a section may
    quote either part of `15 vectors + 20000 sweep cases` or the 20015 it totals.
    """
    text = path.read_text(errors="replace")
    counts: set[int] = set()
    banners = modeled = 0
    for rx, summed in BANNER:
        for match in rx.finditer(text):
            parts = [int(x.replace(",", "")) for x in match.groups()]
            counts.update(parts)
            if len(parts) > 1:
                counts.add(sum(parts))
            banners += 1
            modeled += sum(parts) if summed else parts[0]
    return counts, banners, modeled


def paper_counts(text: str) -> dict[int, int]:
    """Return {claimed count: how many times it appears}."""
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

    text = masked(pathlib.Path(args.section))
    claimed = paper_counts(text)
    measured, banners, modeled = read_log(pathlib.Path(args.log))
    problems = [f"claim {c:,} appears {claimed[c]}x but no banner reports it"
                for c in sorted(c for c in claimed if c not in measured)]

    totals = {"banners": banners, "modeled cases": modeled}
    for rx, what in AGGREGATES:
        for match in rx.finditer(text):
            value = int(re.sub(r"[{},\\]", "", match.group("n")))
            if value != totals[what]:
                problems.append(f"claim {value:,} {what}; the log has "
                                f"{totals[what]:,}")

    for line in problems:
        print(line)
    if args.check and problems:
        raise SystemExit(1)
    if not problems:
        print(f"all {len(claimed)} claimed case counts, and both gate totals, "
              "match the log")


if __name__ == "__main__":
    main()
