#!/usr/bin/env python3
"""Check the paper's claimed oracle case counts against a gate log.

The safety section states the case count of many oracles ("an independent
\\(167{,}480\\)-case routed oracle includes the simulator header..."). Those
figures were hand-maintained and drifted: seven were stale when this was
written, six of them because coverage rows added case counts that nobody
propagated into the prose.

This script extracts every such claim from a section, reads the counts out of a
`make check` log, and reports any claim with no matching banner. It cannot tell
*which* banner a claim means, only that the number exists in the gate -- which
is enough to catch a stale figure, since a stale one matches nothing.

Usage: check_paper_counts.py --section <tex> --log <make check log> [--check]
"""
import argparse
import pathlib
import re
import sys

CLAIM = re.compile(r"\\\((\d[\d{},\\]*?)\\\)-case")


def log_counts(path: pathlib.Path) -> set[int]:
    text = path.read_text(errors="replace")
    counts = {int(x.replace(",", ""))
              for x in re.findall(r"OK \(([\d,]+) cases\)", text)}
    for m in re.finditer(r"OK \((\d+) vectors \+ (\d+) sweep cases\)", text):
        counts.add(int(m.group(1)) + int(m.group(2)))
    return counts


def paper_counts(path: pathlib.Path) -> dict[int, int]:
    """Return {claimed count: how many times it appears}."""
    seen: dict[int, int] = {}
    for m in CLAIM.finditer(path.read_text()):
        value = int(re.sub(r"[{},\\]", "", m.group(1)))
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
