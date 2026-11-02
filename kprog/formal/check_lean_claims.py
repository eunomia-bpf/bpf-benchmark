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
# An attribute sits on the same line as its theorem, so the pattern accepts a
# leading `@[...]`: `@[simp] theorem arm64MulToNatMask32` is a proved
# declaration like any other, and anchoring on a bare column-0 `theorem` left
# the published count one short of the tree.
THEOREM = re.compile(r'^(?:@\[[^\]]*\]\s*)?theorem (\w+)'
                     r'[^\n]*(?:\n[ \t].*)*', re.M)

# A docstring line can itself begin with `theorem` when prose wraps mid-sentence,
# and the pattern above matches at any line start, so the raw count can exceed
# the number of declarations. A real declaration always reaches a `:=` before
# the next top-level declaration; prose never does. Rejecting the prose keeps
# the published count honest -- it had drifted by one before this check existed.
PROOF = ":="

# The table-length shape: a statement whose whole proposition is one list's
# length equal to a name. Anchoring at the end of the statement keeps an
# implication -- which only assumes a length -- out of the class.
TABLE_LENGTH = re.compile(r"(\w+)\.length = (\w+)\s*$")

# The refinement-equality shape: a statement that is exactly one bare list
# name equal to another. Binding on bare names is what keeps the class the
# paper describes -- a hand-written list against the generated list it
# restates -- and leaves out the statements that only *imply* such an
# equality after unfolding a selector (`sourceOf base = spec base`), assert a
# conjunction, or compare a projection of a table (`table.map f`).
LIST_PAIR = re.compile(r"^(\w+) = (\w+)\s*$")


def literal_length(src, open_at):
    """Top-level element count of the `[...]` literal starting at `open_at`.

    The length is what makes "both sides are non-empty" a measurement, so the
    scan counts commas at depth one and skips string literals, whose contents
    carry commas and brackets (`["bpf_map_lookup_elem", ...]`).
    """
    depth, i, n, in_string = 0, open_at, 0, False
    while True:
        char = src[i]
        if in_string:
            if char == "\\":
                i += 2
                continue
            in_string = char != '"'
        elif char == '"':
            in_string = True
        elif char in "([{":
            depth += 1
        elif char in ")]}":
            depth -= 1
            if depth == 0:
                break
        elif char == "," and depth == 1:
            n += 1
        i += 1
    return 0 if not src[open_at + 1:i].strip() else n + 1


def list_lengths(src):
    """`{name: length}` for every `def <name> ... := [...]` in `src`."""
    out = {}
    for m in re.finditer(r"^def (\w+)[^\n]* := \[", src, re.M):
        out[m.group(1)] = literal_length(src, src.index("[", m.end() - 3))
    return out


def statement_cut(block, name):
    """Where a theorem's binders end and its proposition starts.

    Splitting on the first `:` would stop at the first binder's own colon, so
    the scan tracks bracket depth and cuts at the depth-zero colon. The name,
    not the block's start, anchors the scan: a leading attribute would shift
    every binder by its length. Returns -1 for a block with no such colon.
    """
    head = block[:block.find(":=")]
    start = head.index("theorem " + name) + len("theorem " + name)
    depth = 0
    for i in range(start + 1, len(head)):
        char = head[i]
        if char in "([":
            depth += 1
        elif char in ")]":
            depth -= 1
        elif char == ":" and depth == 0:
            return i
    return -1


def signature(block, name):
    """The binders between `theorem <name>` and the statement's colon."""
    cut = statement_cut(block, name)
    if cut < 0:
        return ""
    head = block[:block.find(":=")]
    start = head.index("theorem " + name) + len("theorem " + name)
    return head[start + 1:cut]


def statement(block, name):
    """The proposition, with the name and binders cut off.

    A rule anchored with `^` needs this rather than the declaration head:
    `theorem foo (x : Bool) : table = spec x` begins with the word `theorem`,
    and its binders carry the colons and parentheses that the length and pair
    shapes must not see.
    """
    cut = statement_cut(block, name)
    return block[:block.find(":=")][cut + 1:] if cut >= 0 else ""


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

def table_length_count(block, name, imports, gen_counts):
    """The generated count a table-length theorem asserts, else `None`.

    Membership is decided by the statement, never by the name: `*_length`
    matches 49 theorems, four of which assert no length equality at all (their
    right-hand side is a function of a width), and renaming would silently move
    the class either way. The name on the right must resolve to a generated
    `def <name> : Nat := <digits>` through the module's own imports, which is
    what makes the figure a property of the tree rather than of a string:
    `armCount` is 2 in one generated specification and 4 in another, so the
    resolution is per module and the value reported is the smaller of the ones
    the module can actually see.
    """
    shape = TABLE_LENGTH.search(statement(block, name))
    if shape is None:
        return None
    values = [gen_counts[imp][shape.group(2)] for imp in imports
              if shape.group(2) in gen_counts.get(imp, ())]
    return min(values) if values else None


def refinement_pair(block, name, own, gen_lists):
    """The shorter side of a hand-list/generated-list equality, else `None`.

    The paper's exactness clause says these theorems assert two independently
    defined lists equal and that both sides measure non-empty. Neither half was
    measurable: the class had no membership rule, so the clause named nothing.
    Membership is the statement again -- one bare name equal to another -- with
    one side a literal list in this module and the other a literal list in a
    generated module this one imports, which is what "independently defined"
    means here. Counting both sides is what makes "non-empty" a measurement.
    """
    shape = LIST_PAIR.match(statement(block, name).strip())
    if shape is None:
        return None
    hand, table = own.get(shape.group(1)), gen_lists.get(shape.group(2))
    if hand is None:
        hand, table = own.get(shape.group(2)), gen_lists.get(shape.group(1))
    return min(hand, table) if None not in (hand, table) else None


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
    # The section splits the tree by architecture. A module counts toward an
    # architecture when its own file name starts with that prefix; everything
    # else -- the generated specifications and the cross-ISA compositions -- is
    # shared, the same sense of `shared` the section uses for its 138 generated
    # specs. Splitting on the file name alone is what makes the three buckets
    # sum to the published module and theorem totals.
    arch_mods = {"arm64": 0, "x86": 0, "shared": 0}
    arch_thms = {"arm64": 0, "x86": 0, "shared": 0}
    # The section also claims its table-length and exactness theorems carry
    # content. The rules live in table_length_count and refinement_pair; both
    # record what each theorem measures, not just that it exists, so the
    # sentence's halves -- no count is zero, both sides non-empty -- become
    # measurements rather than assertions.
    imports, gen_counts, own_lists, gen_lists = {}, {}, {}, {}
    for path in mods:
        stem = os.path.basename(path)[:-5]
        src = open(path, errors="ignore").read()
        imports[stem] = set(
            re.findall(r'^import KProgFormal\.(\w+)', src, re.M))
        own_lists[stem] = list_lengths(src)
        if stem.startswith("Generated"):
            gen_counts[stem] = {
                m.group(1): int(m.group(2)) for m in
                re.finditer(r"^def (\w+) : Nat := (\d+)", src, re.M)}
    for stem in own_lists:
        merged = {}
        for imp in imports[stem]:
            if imp.startswith("Generated"):
                merged.update(own_lists[imp])
        gen_lists[stem] = merged
    table_counts = []
    pair_counts = []
    for path in mods:
        src = open(path, errors="ignore").read()
        stem = os.path.basename(path)[:-5]
        arch = ("arm64" if stem.startswith("Arm64") else
                "x86" if stem.startswith("X86") else "shared")
        proved = 0
        for m in THEOREM.finditer(src):
            block = m.group(0)
            if PROOF not in block:
                continue
            proved += 1
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
            asserted = table_length_count(block, m.group(1), imports[stem],
                                          gen_counts)
            if asserted is not None:
                table_counts.append(asserted)
            pair = refinement_pair(block, m.group(1), own_lists[stem],
                                   gen_lists[stem])
            if pair is not None:
                pair_counts.append(pair)
        arch_mods[arch] += 1
        arch_thms[arch] += proved

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

    out = {
        "theorems": theorems,
        "native_decide": native_decide,
        "native_modules": len(native_modules),
        "modules": len(seen),
        "refines": refines,
        "refines_decided": refines_decided,
        "quant_cases": quant_cases,
        "table_length": len(table_counts),
        # The section states the range these theorems compare against, so both
        # ends are published. Both classes are asserted non-empty there, and an
        # empty list -- the theorems renamed or the constants turned into
        # expressions -- must fail loudly rather than report a vacuous range.
        "table_min_count": min(table_counts),
        "table_max_count": max(table_counts),
        # The exactness clause quotes how many equalities equate two list
        # literals and how short their shorter side gets, which is the figure
        # that says none of them compares one list against itself or against
        # `[]`.
        "refine_pairs": len(pair_counts),
        "refine_min_entries": min(pair_counts),
    }
    for arch in arch_mods:
        out[arch + "_mods"] = arch_mods[arch]
        out[arch + "_thms"] = arch_thms[arch]
    return out


# The claims, as regular expressions over the section text, each with the share
# of the theorem count it also states.
CLAIMS = [
    (re.compile(r'(\d[\d{},\\]*) of the (\d[\d{},\\]*) theorems '
                r'\((\d+)\\%'), ("native_decide", "theorems", "share")),
    (re.compile(r'spread over (\d+) of the (\d[\d{},\\]*)'), ("native_modules", "modules")),
    (re.compile(r'over (\d+) Lean modules'), ("modules",)),
    # The totals sentence restates the module figure and the theorem figure
    # side by side. The module number was bound; the theorem number beside it
    # was not, and a document that quotes a figure in one sentence and binds it
    # in another still drifts when only one of the two is corrected.
    (re.compile(r'Lean modules that prove (\d[\d{},\\]*) theorems'),
     ("theorems",)),
    (re.compile(r'(\d+) of the (\d[\d{},\\]*) refinement-named theorems'),
     ("refines_decided", "refines")),
    (re.compile(r'(\d+) of those are universally quantified'), ("quant_cases",)),
    # The section's per-architecture sentence was the last hand-kept figure
    # in it, and it drifted with every module added since: the three buckets
    # it quotes summed to 294 modules and 1,941 theorems while the tree grew
    # past both. Binding all six numbers makes the split reproducible; they
    # are defined in scan_tree and sum to the two totals above.
    (re.compile(r'(\d+) AArch64 modules prove (\d[\d{},\\]*) theorems'),
     ("arm64_mods", "arm64_thms")),
    (re.compile(r'(\d+) x86-64 modules prove (\d[\d{},\\]*)'),
     ("x86_mods", "x86_thms")),
    (re.compile(r'(\d+) shared modules prove (\d[\d{},\\]*)'),
     ("shared_mods", "shared_thms")),
    # The non-vacuity sentence's table-length clause makes two claims, and
    # step 0488 left both to memory. "Nineteen" was the `*_codes_length`
    # subfamily when it was written and drifted with the `*_names_length` and
    # dispatch-table theorems added since. "No generated count is zero" could
    # not be refuted by any measurement -- zero theorems or a zero constant
    # both kept it true -- so the paper quotes the span instead, and the claim
    # fails the moment a generator emits an empty table.
    (re.compile(r'the (\d+) table-length theorems'), ("table_length",)),
    (re.compile(r'constants run from (\d+) to (\d+)'),
     ("table_min_count", "table_max_count")),
    # The clause's second half named "the exactness theorems" with no rule, and
    # the five theorems that end `_exact` are not the class it describes: one is
    # a boundary conjunction and the other four compare a projection of a table,
    # not a list. The paper now names the class the rule finds.
    (re.compile(r'the (\d+) refinement equalities'), ("refine_pairs",)),
    (re.compile(r'both sides hold at least (\d+)'), ("refine_min_entries",)),
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
    # The share is floored, never rounded: both documents say 23% for 488/2061
    # (23.6%), and a floored share cannot overstate how much rests on the
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