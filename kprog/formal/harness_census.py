#!/usr/bin/env python3
"""Report each mutation harness's row counts, split by named detector.

The safety section states, for every harness it describes, three numbers:
how many mutation rows the harness has, how many of them the detectors
catch, and how that caught set divides between the specification/generator
stage, the Lean chain and the host oracle. Those numbers were hand-kept, and
checking five of them against their harnesses found two that were each off
by one per detector while their totals were right.

The harness source already says all of it: every row names the detector that
must catch it, and a row marked `equivalent` must survive instead. This
script reads that structure with the AST rather than by text matching, so a
multi-line row call is counted once and its keyword arguments are seen.

Usage: harness_census.py [--root .] [module ...]
"""
import argparse
import ast
import collections
import glob
import os
import sys

DETECTORS = ("gen", "lean_chain", "host", "routed", "app")


def rows(path):
    """`[(name, detector, equivalent)]` for one harness.

    Two shapes appear in the tree: a `row(name, detector, edits,
    equivalent=...)` call, and a `MUTATIONS = [(name, detector, edits,
    equivalent), ...]` literal. Both are read structurally, because a
    regex over calls matched one row out of fifty-seven once the arguments
    wrapped.
    """
    tree = ast.parse(open(path, errors="ignore").read())
    out = []
    for node in ast.walk(tree):
        if isinstance(node, ast.Call) and getattr(node.func, "id", "") == "row":
            det = getattr(node.args[1], "value", "?") if len(node.args) > 1 \
                else "?"
            equiv = any(k.arg == "equivalent"
                        and isinstance(k.value, ast.Constant)
                        and k.value.value is True for k in node.keywords)
            out.append((getattr(node.args[0], "value", "?"), det,
                        equiv))
    if out:
        return out
    for node in tree.body:
        if not (isinstance(node, ast.Assign)
                and getattr(node.targets[0], "id", "") == "MUTATIONS"):
            continue
        for row in getattr(node.value, "elts", ()):
            if not isinstance(row, ast.Tuple) or len(row.elts) < 4:
                continue
            det = getattr(row.elts[1], "value", "?")
            last = row.elts[3]
            equiv = isinstance(last, ast.Constant) and last.value is True
            out.append((getattr(row.elts[0], "value", "?"), det, equiv))
    return out


def census(path):
    """`(rows, caught, {detector: caught count}, equivalent)`."""
    found = rows(path)
    caught = [r for r in found if not r[2]]
    return (len(found), len(caught),
            collections.Counter(d for _, d, _ in caught),
            len(found) - len(caught), found)


def main(argv):
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=here)
    ap.add_argument("modules", nargs="*")
    args = ap.parse_args(argv[1:])

    names = args.modules or [
        os.path.basename(p) for p in sorted(
            glob.glob(os.path.join(args.root, "build", "mut_*.py")))]
    unread = []
    for name in names:
        path = name if os.path.sep in name or name.endswith(".py") else None
        if path is None or not os.path.exists(path):
            path = os.path.join(args.root, "build", name)
        if not os.path.exists(path):
            path = os.path.join(args.root, "build", name + ".py")
        try:
            total, caught, dets, equiv, row_list = census(path)
        except SyntaxError:
            unread.append(name)
            continue
        if not total:
            unread.append(name)
            continue
        # The section's breakdown counts every row by the detector that must
        # catch it, and its "N catch" counts the rows that are not marked
        # equivalent. Both are printed, because the two differ by exactly the
        # equivalent rows and a reader comparing one against the other will
        # otherwise think a figure is wrong.
        everything = collections.Counter(d for _, d, _ in row_list)
        split = " ".join("%s=%d" % (d, everything[d]) for d in DETECTORS
                         if everything[d])
        print("%-30s rows=%3d catch=%3d equiv=%3d | by row %s"
              % (os.path.basename(path), total, caught, equiv, split))
    if unread:
        print("\n%d harness(es) expose no row table: %s"
              % (len(unread), ", ".join(unread[:6])))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))