#!/usr/bin/env python3
"""Re-derive the harness README's counts from the tree and report drift.

Every figure the README's claims block states about the tree is measurable
here, and each had drifted at least once: the census counter and its step
count, the route-host count, the battery count (stated twice, in the claims
block and again in the census note below it), the unnamed-harness pair, and
the split of unbuilt `build/*.c` into ad-hoc probes and stale duplicates.
Rather than keep them accurate by hand, this script recomputes each and diffs
it against what the README says. The banner and case-count figures are not
here; `check_paper_counts.py` measures those against a log.

It reports rather than fails by default, because several figures legitimately
change with every step and a hard gate would demand a README edit per commit.
`--check` fails when a figure disagrees, for use in review.
"""
import argparse
import glob
import os
import pathlib
import re

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


def scratch() -> tuple[int, int]:
    """The unbuilt sources under build/, split as the README splits them.

    It claims 41 ad-hoc probes and two stale duplicates, and that is all of
    what the recipe does not build -- a third kind of scratch file, or a probe
    that stopped matching `nb*`/`onebar*`, would leave the sentence true in
    every part and false in the whole.
    """
    mk = (ROOT / "Makefile").read_text()
    built = set(re.findall(r"build/([\w.]+\.c)", mk))
    unbuilt = [p.name for p in (ROOT / "build").glob("*.c")
               if p.name not in built]
    adhoc = [n for n in unbuilt if re.match(r"(?:nb|onebar)", n)]
    return len(adhoc), len(unbuilt) - len(adhoc)


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
    return len(names), len(unnamed), gated


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true",
                        help="exit 1 when a measured figure disagrees with the README")
    args = parser.parse_args()

    steps, last = census()
    total_bats, unnamed, unnamed_gated = batteries()
    probes, duplicates = scratch()
    text = README.read_text()
    drift = []

    WORDS = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5,
             "six": 6, "seven": 7, "eight": 8, "nine": 9, "ten": 10,
             "eleven": 11, "twelve": 12, "thirteen": 13, "fourteen": 14,
             "fifteen": 15, "sixteen": 16, "seventeen": 17,
             "eighteen": 18, "nineteen": 19, "twenty": 20}

    def expect(label, measured, *patterns):
        """Check every place the README states this figure.

        Two of them are stated twice, in the claims block and again in the
        census note below it, and only one was compared -- so the note could
        be edited while the block still agreed, under a green run.
        """
        seen = False
        for pattern in patterns:
            m = re.search(pattern, text)
            if not m:
                continue
            seen = True
            stated = m.group(1)
            value = WORDS.get(stated)
            if value is None:
                value = int(stated) if stated.isdigit() else None
            if value != measured:
                drift.append(f"{label}: README says {stated}, tree has "
                             f"{measured}")
        if not seen:
            drift.append(f"{label}: README has no figure (measured "
                         f"{measured})")

    expect("census last value",
           last, r"the counter's last value is (\d+)")
    expect("steps with a census transition",
           steps, r"and (\d+) steps\n?record an explicit")
    expect("route hosts in the recipe",
           route_hosts(), r"the (\w+) route hosts those")
    expect("batteries on disk", total_bats,
           r"The (\d+) `build/mut_\*\.py` batteries",
           r"(\d+)\n`build/mut_\*\.py` files exist")
    expect("unnamed harnesses", unnamed,
           r"— (\d+) harnesses\nare never named")
    expect("unnamed harnesses driving a gated host", unnamed_gated,
           r"but (\d+) of them drive a tracked")
    expect("ad-hoc probes under build/", probes,
           r"coverage: (\d+) are\nad-hoc probes")
    expect("stale duplicate sources under build/", duplicates,
           r"the (\w+) large ones are stale copies")

    for d in dict.fromkeys(drift):
        print(d)
    if args.check and drift:
        raise SystemExit(1)
    if not drift:
        print("README counts agree with the tree")


if __name__ == "__main__":
    main()
