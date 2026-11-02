#!/usr/bin/env python3
"""Check every document's Lean-side counts against the repository itself.

`check_paper_counts.py` verifies the *oracle case counts*, which it can do by
looking for a matching banner in a `make check` log. It cannot verify the other
numbers the safety section states -- how many theorems the development proves,
how many modules carry them, how many are discharged by native_decide -- because
those are not banners.

They were hand-maintained, and three of them had drifted: the module count was
nine behind, and the native_decide figures were stale on all three of their
numbers. A stale figure is invisible to a reader and to every existing gate,
which is the same failure mode the case-count checker was written for.

The harness README states the same figures and was still unchecked, so it drifted
silently while this script reported "all claims current": it read the paper only.
Both documents are now targets, and so is the refinement-named denominator they
share, whose definition is fixed in `refinement_named`.

Usage: check_lean_claims.py [--section <tex>] [--readme <md>]
"""

import argparse
import glob
import os
import pathlib
import re
import sys

# A theorem runs from its `theorem` line through every following indented line.
# A Lean proof script is always indented and any new top-level command starts at
# column zero, so indentation -- not a keyword list -- is what ends a declaration.
# The previous pattern stopped only at `theorem`, `def`, and `end`, so a theorem
# whose body was followed by an `example ... := by native_decide` absorbed that
# example and was miscounted as `native_decide` although its own script was
# `bv_decide`: `arm64_ccmp_decode_cond_low_bits` inflated both the theorem and
# the module figures by one.

THEOREM = re.compile(r'^theorem (\w+)[^\n]*(?:\n[ \t].*)*', re.M)

# A docstring line can itself begin with `theorem` when prose wraps mid-sentence,
# and the pattern above matches at any line start, so the raw count can exceed
# the number of declarations. A real declaration always reaches a `:=` before
# the next top-level declaration; prose never does. Rejecting the prose keeps
# the published count honest -- it had drifted by one before this check existed.
PROOF = ":="


def signature(block, name):
    """The binders between `theorem <name>` and the statement's colon.

    Splitting on the first `:` would stop at the first binder's own colon, so the
    scan tracks bracket depth and cuts at the depth-zero colon that separates the
    signature from the statement.
    """
    head = block[:block.find(":=")]
    depth = 0
    for i, char in enumerate(head):
        if char in "([":
            depth += 1
        elif char in ")]":
            depth -= 1
        elif char == ":" and depth == 0:
            return head[len("theorem " + name) + 1:i]
    return ""


def refinement_named(name):
    """Whether a theorem name states a refinement.

    The published denominator needs this to be spelled out: it is the substring
    `refine` in the name, which covers both `_refines` and the `_refine` names
    the generators emit (`arm64_reg_dispatch_names_refine`). Narrowing it to
    `refines` drops the eight `_refine` table equalities and their eight
    `native_decide` proofs, so the published "20 of the N" numerator -- which is
    exactly the finite-table equalities listed in the safety section -- stops
    being reproducible. Substring rather than word-boundary because the token is
    always a name component joined by underscores.
    """
    return "refine" in name.lower()


def flat(text):
    """Collapse whitespace so a claim wrapped across source lines still matches."""
    return re.sub(r"\s+", " ", text)


def scan_tree(root):
    """Recompute every claim from the Lean sources and the gate Makefile."""
    mods = glob.glob(os.path.join(root, "KProgFormal", "*.lean"))
    theorems = 0
    native_decide = 0
    native_modules = set()
    refines = 0
    refines_decided = 0
    quant_cases = 0
    for path in mods:
        src = open(path, errors="ignore").read()
        for m in THEOREM.finditer(src):
            block = m.group(0)
            if PROOF not in block:
                continue
            theorems += 1
            named = refinement_named(m.group(1))
            refines += named
            if "native_decide" in block:
                native_decide += 1
                refines_decided += named
                native_modules.add(os.path.basename(path))
                # The safety section claims its quantified native_decide proofs
                # are exhaustive case analyses over a finite type, so both halves
                # are measured: a binder in the signature and `cases` in the
                # script. A quantified proof closed some other way (one is
                # `refine`d and decided over `BitVec 64` binders) does not belong
                # to that sentence and is not counted.
                cut = block.find(":=")
                binders = signature(block, m.group(1))
                if "(" in binders and re.search(r'\bcases\b', block[cut:]):
                    quant_cases += 1

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
        "refines": refines,
        "refines_decided": refines_decided,
        "quant_cases": quant_cases,
    }


# The claims, as regular expressions over the section text, each with the share
# of the theorem count it also states.
CLAIMS = [
    (re.compile(r'(\d[\d{},\\]*) of the (\d[\d{},\\]*) theorems '
                r'\((\d+)\\%'), ("native_decide", "theorems", "share")),
    (re.compile(r'spread over (\d+) of the (\d[\d{},\\]*)'), ("native_modules", "modules")),
    (re.compile(r'over (\d+) Lean modules'), ("modules",)),
    (re.compile(r'(\d+) of the (\d[\d{},\\]*) refinement-named theorems'),
     ("refines_decided", "refines")),
    (re.compile(r'(\d+) of those are universally quantified'), ("quant_cases",)),
]

# The harness README states the same development from the harness side, in plain
# prose rather than LaTeX. It was the last document still hand-maintained: its
# theorem and native_decide figures had fallen behind the tree while every check
# stayed green, because the only reader of these numbers looked at the paper.
README_CLAIMS = [
    (re.compile(r'proving (\d[\d,]*) theorems'), ("theorems",)),
    (re.compile(r'(\d[\d,]*) of those \((\d+)%'), ("native_decide", "share")),
    (re.compile(r'(\d+) of the (\d[\d,]*) refinement-named theorems'),
     ("refines_decided", "refines")),
    (re.compile(r'(\d+) Lean modules'), ("modules",)),
]


def number(text):
    return int(re.sub(r'[{},\\]', '', text))


def check(targets, root):
    """Check each (path, claims) pair; a document that matches nothing is drift."""
    actual = scan_tree(root)
    # The share is floored, never rounded: both documents say 23% for 488/2060
    # (23.7%), and a floored share cannot overstate how much rests on the
    # compiler. Rounding here would turn a correct 23% into a stale claim.
    actual["share"] = 100 * actual["native_decide"] // actual["theorems"]
    bad = []
    for path, claims in targets:
        text = flat(pathlib.Path(path).read_text())
        seen_any = False
        for pattern, names in claims:
            for m in pattern.finditer(text):
                seen_any = True
                for i, name in enumerate(names, start=1):
                    claimed = number(m.group(i))
                    if claimed != actual[name]:
                        bad.append(("%s: %s" % (path.name, m.group(0)[:48]),
                                    name, claimed, actual[name]))
        if not seen_any:
            bad.append(("%s: no Lean-side claim matched" % path.name,
                        "-", "-", "-"))
    return bad, actual


def main(argv):
    here = pathlib.Path(__file__).resolve().parent
    ap = argparse.ArgumentParser()
    ap.add_argument("--section", default=str(
        here.parent.parent / "docs" / "kprog-simulator-in-ebpf" / "sections"
        / "4-safety.tex"))
    ap.add_argument("--readme", default=str(here / "README.md"))
    args = ap.parse_args(argv[1:])

    bad, actual = check([(pathlib.Path(args.section), CLAIMS),
                         (pathlib.Path(args.readme), README_CLAIMS)], here)
    if bad:
        print("check_lean_claims: %d stale claim(s)" % len(bad))
        for text, name, claimed, real in bad:
            print("  %r: %s claims %s, tree has %s"
                  % (text, name, claimed, real))
        return 1
    print("check_lean_claims: %d theorems, %d native_decide over %d modules, "
          "%d modules, %d refinement-named (%d by native_decide), "
          "%d quantified by cases -- all claims current"
          % (actual["theorems"], actual["native_decide"],
             actual["native_modules"], actual["modules"],
             actual["refines"], actual["refines_decided"],
             actual["quant_cases"]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))