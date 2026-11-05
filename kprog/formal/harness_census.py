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
import re
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
    # Two `row` shapes exist. The detector one is
    # row(name, "gen"|"lean_chain"|"host"|..., edits, equivalent=...); the
    # path one is row(name, SOME_PATH, old, new), a different family that
    # names a file rather than a detector. Counting the second as rows with
    # an unknown detector classified a third of the tree by guesswork.
    shape = next((n for n in ast.walk(tree)
                  if isinstance(n, ast.FunctionDef) and n.name == "row"), None)
    args = [a.arg for a in shape.args.args] if shape else []
    if len(args) >= 4 and args[3] == "new":
        return []
    # A third shape, row(name, edits, equivalent=...), names no detector
    # because the harness runs one of them; its rows still count, and the
    # detector is the single one the harness uses.
    detectorless = len(args) >= 2 and args[1] == "edits"
    for node in ast.walk(tree):
        if isinstance(node, ast.Call) and getattr(node.func, "id", "") == "row":
            det = ("host" if detectorless else
                   getattr(node.args[1], "value", None)
                   if len(node.args) > 1 and
                   isinstance(node.args[1], ast.Constant) else
                   # A module constant selects a file rather than naming a
                   # detector; the harnesses that do this run the host
                   # detector unless the constant is the Lean source.
                   "lean" if isinstance(node.args[1], ast.Name) and
                   node.args[1].id.startswith("LEAN") else
                   # A (label, callable) pair names its detector in the
                   # first element.
                   node.args[1].elts[0].value
                   if isinstance(node.args[1], ast.Tuple)
                   and isinstance(node.args[1].elts[0], ast.Constant) else
                   "host" if len(node.args) > 1 else "?")
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
            # Two arities appear: (name, detector, edits, equivalent) and
            # (name, detector, edits, False, equivalent). The flag is the
            # last element either way, and reading a fixed index silently
            # found no equivalences in the five-element harnesses.
            last = row.elts[-1]
            equiv = isinstance(last, ast.Constant) and last.value is True
            out.append((getattr(row.elts[0], "value", "?"), det, equiv))
    return out


def step_of(path):
    """The Step number a harness's docstring cites, or `None`.

    The paper names contracts, never scripts, so a claim and its harness can
    only be matched through the Step both cite. Most harnesses carry one in
    the module docstring; the rest need an explicit index before their
    figures can be checked from source.
    """
    doc = ast.get_docstring(ast.parse(open(path, errors="ignore").read())) or ""
    hit = re.search(r"Step (\d{4})", doc)
    return hit.group(1) if hit else None


def census(path):
    """`(rows, caught, {detector: caught count}, equivalent)`."""
    found = rows(path)
    caught = [r for r in found if not r[2]]
    return (len(found), len(caught),
            collections.Counter(d for _, d, _ in caught),
            len(found) - len(caught), found)


def partitions(path):
    """`(all-rows by detector, caught by detector, caught count)`.

    Detector names are normalised to the three the prose distinguishes: the
    harnesses write `lean_chain` where the section writes "the Lean chain",
    and a few use their own names for the host oracle.
    """
    found = rows(path)

    def norm(det):
        # Recognise by prefix, and say so when a label fits none of them: a
        # default bucket silently classified a third of the tree's rows as
        # host, and the figure looked like a measurement.
        if det.startswith("lean") or det == "chain":
            return "lean"
        if det.startswith("gen") or det == "movk_gen":
            return "gen"
        if det.startswith("route"):
            return "route"
        if det.startswith("host"):
            return "host"
        return "UNKNOWN:" + det

    caught = [r for r in found if not r[2]]
    return (collections.Counter(norm(d) for _, d, _ in found),
            collections.Counter(norm(d) for _, d, _ in caught), len(caught))


def detectors(body):
    """`{gen, lean, host}` counts from a claim's parenthetical breakdown.

    The section names the third and fourth detectors several ways and can put
    a clause in an em dash between two counts, so the counts are read by
    label. A claim whose split matches a harness under either partition is
    matched on that partition, because the section uses both.
    """
    body = re.sub(r"---.*?---", "", body)
    out = collections.Counter()
    for count, name in re.findall(
            r"(\d+) (?:by|at|in|through) (?:the )?(generator(?:'s)?"
            r"[\w\s-]{0,24}checks|generator stage|Lean chain|"
            r"(?:[\d,]+-case )?host oracle|rout\w* oracle|"
            r"route scanner)", body):
        out["gen" if "generator" in name else
            "lean" if "Lean" in name else
            "route" if "rout" in name else "host"] += int(count)
    # A count written as a word: "plus the one movk-regex catch". The harness
    # has one such row and it is caught, so it belongs to the host total the
    # claim is asserting.
    out["gen"] += len(re.findall(r"\bthe one [\w-]+ catch", body))
    return out


def row_claim_matches(text, root):
    """`[(harness, caught in paper, caught in harness)]` for "N rows catch".

    The same comparison as claim_matches for the family that says "rows",
    which is forty claims against the other family's eleven. Both are read
    the same way; only the wording differs.
    """
    tables = {}
    for path in sorted(glob.glob(os.path.join(root, "build", "mut_*.py"))):
        if rows(path):
            tables[os.path.basename(path)] = partitions(path)
    out = []
    for hit in re.finditer(r"(\d+) rows catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)",
                           re.sub(r"\s+", " ", text.replace("\\brk", ""))):
        caught, breakdown = int(hit.group(1)), detectors(hit.group(2))
        if len(breakdown) < 3:
            continue
        for name, parts in tables.items():
            if any(all(part.get(k, 0) == breakdown.get(k, 0)
                       for k in ("gen", "lean", "host", "route"))
                   for part in parts[:2]):
                out.append((name, caught, parts[2]))
                break
    return out


def total_matches(text, tables):
    """`[(harness, declared total, harness rows)]` for "N-mutation harness".

    The declared mutation total is a separate figure from the caught count,
    and it is the one a reader uses to size the harness. It is parsed from
    the nearest preceding "N-mutation harness" phrase, since a paragraph
    describes one harness.
    """
    flat_text = re.sub(r"\s+", " ", text.replace("\\brk", ""))
    out = []
    for hit in re.finditer(r"(\d+) rows catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)",
                           flat_text):
        breakdown = detectors(hit.group(2))
        if len(breakdown) < 3:
            continue
        lead = flat_text[max(0, hit.start() - 900):hit.start()]
        declared = re.findall(r"(\d+)-mutation harness", lead)
        if not declared:
            continue
        for name, parts in tables.items():
            if any(all(part.get(k, 0) == breakdown.get(k, 0)
                       for k in ("gen", "lean", "host", "route"))
                   for part in parts[:2]):
                out.append((name, int(declared[-1]), sum(parts[0].values())))
                break
    return out


def survivor_matches(text, tables):
    """`[(harness, stated survivors, harness equivalents)]`.

    The third figure a harness claim states: how many of its rows survive as
    documented equivalences. It is the harness's equivalent count, and it is
    checked the same way as the other two, by resolving the harness from the
    detector split.
    """
    flat_text = re.sub(r"\s+", " ", text.replace("\\brk", ""))
    out = []
    for hit in re.finditer(r"(\d+) rows catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)"
                           r"\s*and\s*(\d+) surviv", flat_text):
        breakdown = detectors(hit.group(2))
        if len(breakdown) < 3:
            continue
        for name, parts in tables.items():
            if any(all(part.get(k, 0) == breakdown.get(k, 0)
                       for k in ("gen", "lean", "host", "route"))
                   for part in parts[:2]):
                out.append((name, int(hit.group(3)),
                            sum(parts[0].values()) - parts[2]))
                break
    return out


def claim_matches(text, root):
    """`[(harness, caught in paper, caught in source)]` for matched claims.

    Only claims whose three-way split matches one harness are returned; the
    rest need an identity the prose does not give, and are left to the
    recorded checks in check_lean_claims.py.
    """
    tables = {}
    for path in sorted(glob.glob(os.path.join(root, "build", "mut_*.py"))):
        found = rows(path)
        if found:
            tables[os.path.basename(path)] = partitions(path)
    out = []
    for hit in re.finditer(r"(\d+) catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)",
                           re.sub(r"\s+", " ", text.replace("\\brk", ""))):
        caught, breakdown = int(hit.group(1)), detectors(hit.group(2))
        if len(breakdown) < 3:
            continue
        for name, parts in tables.items():
            hit_part = [part for part in parts[:2]
                        if all(part.get(k, 0) == breakdown.get(k, 0)
                               for k in ("gen", "lean", "host", "route"))]
            if hit_part:
                out.append((name, caught, parts[2]))
                break
    return out


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
        print("%-30s step=%s rows=%3d catch=%3d equiv=%3d | by row %s"
              % (os.path.basename(path), step_of(path) or "-", total, caught,
                 equiv, split))
    if unread:
        print("\n%d harness(es) expose no row table: %s"
              % (len(unread), ", ".join(unread[:6])))
    return 0


if __name__ == "__main__":
    # No bytecode cache: a stale one made this script print a harness's split
    # as 29/17/11 while the source said 30/17/12, which is worse than no
    # census at all because the wrong numbers look reproducible.
    sys.dont_write_bytecode = True
    sys.exit(main(sys.argv))