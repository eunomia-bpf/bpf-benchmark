#!/usr/bin/env python3
"""Check the paper's Lean-side counts against the repository itself.

`check_paper_counts.py` verifies the *oracle case counts*, which it can do by
looking for a matching banner in a `make check` log. It cannot verify the other
numbers the safety section states -- how many theorems the development proves,
how many modules carry them, how many are discharged by native_decide -- because
those are not banners.

They were hand-maintained, and three of them had drifted: the module count was
nine behind, and the native_decide figures were stale on all three of their
numbers. A stale figure is invisible to a reader and to every existing gate,
which is the same failure mode the case-count checker was written for.

This script recomputes each claim from the tree and reports any that disagree.

Usage: check_lean_claims.py [--section <tex>] [--check]
"""

import argparse
import glob
import os
import pathlib
import re
import sys

# A theorem runs from its `theorem` line to the next top-level declaration; the
# bodies are not indented consistently enough to use indentation.
THEOREM = re.compile(r'^theorem (\w+)[\s\S]*?(?=^theorem |^def |^end |\Z)',
                     re.M)


def scan_tree(root):
    """Recompute every claim from the Lean sources and the gate Makefile."""
    mods = glob.glob(os.path.join(root, "KProgFormal", "*.lean"))
    theorems = 0
    native_decide = 0
    native_modules = set()
    for path in mods:
        src = open(path, errors="ignore").read()
        for m in THEOREM.finditer(src):
            theorems += 1
            if "native_decide" in m.group(0):
                native_decide += 1
                native_modules.add(os.path.basename(path))

    # The module figure the paper quotes is the transitive closure of the gate's
    # roots, not the file count: a module no proof imports is not compiled by
    # the gate and should not be counted as proved.
    graph = {}
    for path in mods:
        name = os.path.basename(path)[:-5]
        graph[name] = set(
            re.findall(r'^import KProgFormal\.(\w+)',
                       open(path, errors="ignore").read(), re.M))
    makefile = open(os.path.join(root, "Makefile")).read()
    roots = set(re.findall(r'lake env lean KProgFormal/(\w+)\.lean', makefile))
    seen, stack = set(), list(roots)
    while stack:
        name = stack.pop()
        if name in seen:
            continue
        seen.add(name)
        stack.extend(graph.get(name, ()))

    return {
        "theorems": theorems,
        "native_decide": native_decide,
        "native_modules": len(native_modules),
        "modules": len(seen),
    }


# The claims, as regular expressions over the section text, each with the share
# of the theorem count it also states.
CLAIMS = [
    (re.compile(r'(\d[\d{},\\]*) of the (\d[\d{},\\]*) theorems '
                r'\((\d+)\\%'), ("native_decide", "theorems", "share")),
    (re.compile(r'spread over (\d+) of the (\d[\d{},\\]*)'), ("native_modules", "modules")),
    (re.compile(r'over (\d+) Lean modules'), ("modules",)),
]


def number(text):
    return int(re.sub(r'[{},\\]', '', text))


def check(section_path, root):
    text = pathlib.Path(section_path).read_text()
    actual = scan_tree(root)
    actual["share"] = 100 * actual["native_decide"] // actual["theorems"]
    bad = []
    seen_any = False
    for pattern, names in CLAIMS:
        for m in pattern.finditer(text):
            seen_any = True
            for i, name in enumerate(names, start=1):
                claimed = number(m.group(i))
                if claimed != actual[name]:
                    bad.append((m.group(0).strip()[:60], name, claimed,
                                actual[name]))
    if not seen_any:
        bad.append(("no Lean-side claim matched", "-", "-", "-"))
    return bad, actual


def main(argv):
    here = pathlib.Path(__file__).resolve().parent
    ap = argparse.ArgumentParser()
    ap.add_argument("--section", default=str(
        here.parent.parent / "docs" / "kprog-simulator-in-ebpf" / "sections"
        / "4-safety.tex"))
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    bad, actual = check(args.section, here)
    if bad:
        print("check_lean_claims: %d stale claim(s)" % len(bad))
        for text, name, claimed, real in bad:
            print("  %r: %s claims %s, tree has %s"
                  % (text, name, claimed, real))
        return 1
    print("check_lean_claims: %d theorems, %d native_decide over %d modules, "
          "%d modules -- all claims current"
          % (actual["theorems"], actual["native_decide"],
             actual["native_modules"], actual["modules"]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))