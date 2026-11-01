#!/usr/bin/env python3
"""Re-derive the harness README's counts from the tree and report drift.

Every figure in the README's claims block is measurable here, and each had
drifted at least once: the census counter, the route-host count, the step
count, and the unnamed-harness pair. Rather than keep them accurate by hand,
this script recomputes each and diffs it against what the README says.

It reports rather than fails by default, because several figures legitimately
change with every step and a hard gate would demand a README edit per commit.
`--check` fails when a figure disagrees, for use in review.
"""
import argparse
import glob
import os
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
README = ROOT / "README.md"


def census() -> tuple[int, int]:
    text = README.read_text()
    vals = [int(g) for m in re.finditer(r"ensus [\(\s]?(\d+)\s*(?:->|\\to)\s*(\d+)", text)
            for g in m.groups()]
    return (len(vals) // 2, max(vals) if vals else 0)


def route_hosts() -> int:
    mk = (ROOT / "Makefile").read_text()
    return len(set(re.findall(r"build/(\w*route_host)\.c", mk)))


def batteries() -> tuple[int, int, int]:
    names = [os.path.basename(p) for p in glob.glob(str(ROOT / "build/mut_*.py"))]
    text = README.read_text()
    unnamed = [b for b in names if b not in text]
    mk = (ROOT / "Makefile").read_text()
    runs = {m for m in re.findall(r"\./build/(test_\w+)\s*$", mk, re.M)}
    gated = 0
    for b in unnamed:
        src = (ROOT / "build" / b).read_text()
        if any(n in runs for n in re.findall(r"(test_\w+?)\.c", src)):
            gated += 1
    return len(names), len(unnamed), len(unnamed) and gated


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true",
                        help="exit 1 when a measured figure disagrees with the README")
    args = parser.parse_args()

    steps, last = census()
    total_bats, unnamed, unnamed_gated = batteries()
    text = README.read_text()
    drift = []

    WORDS = {"thirteen": 13, "fourteen": 14, "fifteen": 15}

    def expect(label, measured, pattern):
        m = re.search(pattern, text)
        if not m:
            drift.append(f"{label}: README has no figure (measured {measured})")
            return
        stated = m.group(1)
        value = WORDS.get(stated)
        if value is None:
            value = int(stated) if stated.isdigit() else None
        if value != measured:
            drift.append(f"{label}: README says {stated}, tree has {measured}")

    expect("census last value",
           last, r"the counter's last value is (\d+)")
    expect("steps with a census transition",
           steps, r"and (\d+) steps\n?record an explicit")
    expect("route hosts in the recipe",
           route_hosts(), r"the (thirteen|fourteen|fifteen) route hosts those")
    expect("batteries on disk", total_bats,
           r"The (\d+) `build/mut_\*\.py` batteries")
    expect("unnamed harnesses", unnamed,
           r"— (\d+) harnesses\nare never named")
    expect("unnamed harnesses driving a gated host", unnamed_gated,
           r"but (\d+) of them drive a tracked")

    for d in dict.fromkeys(drift):
        print(d)
    if args.check and drift:
        raise SystemExit(1)
    if not drift:
        print("README counts agree with the tree")


if __name__ == "__main__":
    main()
