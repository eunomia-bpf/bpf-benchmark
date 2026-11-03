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

The safety section's non-vacuity sentence is the third target. It makes three
claims about theorem content, and each is now measured against a class defined
by its statement, not its name: table-length theorems, refinement equalities
between a hand-written and a generated list, and sweeps that pin values outside
the range they sweep. A class with no members fails loudly rather than reading
as true prose.

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
# The C side of the consumption claim: a header counts as consumed when a gate
# translation unit reaches it through this directive, directly or transitively.
INCLUDE = re.compile(r'^\s*#\s*include\s*[<"]([^">]+)[>"]', re.M)

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

# The dispatch-sweep shapes: a conjunct that sweeps a finite range with `.all`,
# and a conjunct that pins one value outside it. Both are read from the
# statement, and the pair is what the paper's clause is about -- a sweep alone
# says nothing about the values the table does not cover.
SWEEP_RANGE = re.compile(r"^\(\(List\.(?:fin)?[Rr]ange \w+\)\.all", re.S)

# A table's image at every width: `List.map f [..]` equated to a literal list.
# The mapped name must be a generated def, so an ordinary arithmetic identity
# over a hand list does not join the class.
MAP_IMAGE = re.compile(r"List\.map\b.*?\[[^\]]*\][^=]*=\s*\[", re.S)
NON_MEMBER = re.compile(r"^\(.* = none\)$", re.S)


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
    """`{name: length}` for every `def <name> ... := [...]` in `src`.

    The literal may start on the line after the `:=`: seven spec lists in the
    tree wrap that way, and requiring the bracket on the same line hid them
    from every rule that reads a list length, which undercounted the
    refinement equalities by seven.
    """
    out = {}
    for m in re.finditer(r"^def (\w+)[^\n]* :=[ \t]*\n?[ \t]*\[", src, re.M):
        out[m.group(1)] = literal_length(src, src.index("[", m.end() - 1))
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
    and its binders carry the colons and parentheses that the length, pair, and
    sweep shapes must not see.
    """
    cut = statement_cut(block, name)
    return block[:block.find(":=")][cut + 1:] if cut >= 0 else ""


def conjuncts(prop):
    """Split a proposition into its top-level conjuncts.

    The sweep theorems are conjunctions, so membership has to be decided per
    part. Depth tracking keeps a `∧` inside a subexpression in its parent, and
    an empty part is dropped rather than counted as a check.
    """
    parts, depth, start = [], 0, 0
    for i, char in enumerate(prop):
        if char in "([{":
            depth += 1
        elif char in ")]}":
            depth -= 1
        elif char == "∧" and depth == 0:
            parts.append(prop[start:i])
            start = i + 1
    parts.append(prop[start:])
    return [p.strip() for p in parts if p.strip()]


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


def image_pairs(block, name, gen_defs):
    """How many `List.map f <literal> = <literal>` conjuncts a theorem states.

    The non-vacuity sentence quantifies over the theorems that close by `rfl`
    or `decide` over a table, then names the shapes that class holds. The
    first three shapes were enumerated; a fourth sat outside them, so the
    enumeration was not the exhaustive set its universal claim implied. A
    stacked write's ladder is a generated function over a generated table, and
    the theorem that pins its image at all four widths closes by `rfl` over a
    literal list -- content, but in no counted class. Membership is the
    conjunct's own shape: a `List.map` applied to a literal list and equated
    to a literal list, where the mapped name is a generated definition. The
    figure is the number of such conjuncts, since a theorem that pinned one
    width and dropped the rest would still read as though it had pinned all.
    """
    count = 0
    for part in conjuncts(statement(block, name)):
        if not MAP_IMAGE.search(part):
            continue
        if any(re.search(r"\b" + re.escape(g) + r"\b", part)
               for g in gen_defs):
            count += 1
    return count


def sweep_checks(block, name):
    """How many explicit outside-the-range checks a sweep theorem carries.

    The clause's third half said the dispatch sweep "pairs its range over the
    armed ids with explicit non-membership checks", which no measurement
    distinguished from a bare round trip: a theorem that swept the range and
    pinned nothing outside it would have satisfied the sentence. A member is
    therefore a conjunction with exactly one swept range and at least one
    conjunct pinning a single value to `none`, and the figure is the smallest
    such count -- one fewer than that and the claim fails.
    """
    parts = conjuncts(statement(block, name))
    swept = [p for p in parts if SWEEP_RANGE.match(p)]
    outside = [p for p in parts if NON_MEMBER.match(p)]
    return len(outside) if len(swept) == 1 and outside else None


def flat(text):
    """Collapse whitespace so a claim wrapped across source lines still matches."""
    return re.sub(r"\s+", " ", text)


def family(root, pattern, prefix, suffix):
    """The contract names one generated-artifact family carries.

    The three families spell the same contract three ways -- `arm64_ldrsx_op`
    in the spec, `arm64_ldrsx_op.h` in the header,
    `GeneratedArm64LdrsxOp.lean` in the module -- so the caller compares them
    with underscores dropped and case folded away.
    """
    return [os.path.basename(p)[len(prefix):-len(suffix)]
            for p in glob.glob(os.path.join(root, pattern))]


def artifact_families(root):
    """The sizes of the three artifact families, with the pairing verified.

    Both documents publish the figure, and both call the relationship a
    pairing: the section says the artifacts are "paired one-to-one with
    [their] specification ... so no specification is rendered on only one
    side", and the README claims the 138/138/138 split "is verified as a
    bijection in both directions rather than inferred from equal counts".
    Neither sentence was checked by anything -- three counts were published and
    no names were compared, so a contract rendered only in C, or a header with
    no spec behind it, would have left all three figures correct and both
    sentences false. Comparing names is what makes the claim a measurement.
    """
    fams = {
        "spec": family(root, "*_spec.json", "", "_spec.json"),
        "header": family(root, "generated/*.h", "", ".h"),
        "module": family(root, "KProgFormal/Generated*.lean", "Generated",
                         ".lean"),
    }
    norm = {k: {n.replace("_", "").lower() for n in v}
            for k, v in fams.items()}
    for kind, names in fams.items():
        if len(names) != len(norm[kind]):
            raise SystemExit("check_lean_claims: two %s files normalize to "
                             "one name" % kind)
    for other in ("header", "module"):
        gap = norm["spec"] ^ norm[other]
        if gap:
            raise SystemExit(
                "check_lean_claims: spec and %s families are not one-to-one "
                "-- %s" % (other, ", ".join(sorted(gap))))
    return {k: len(v) for k, v in fams.items()}


def checked_generators(makefile, specs):
    """The specs whose generator the gate re-derives with `--check`.

    The section says "every generator re-derives its output on each run and
    fails on any byte difference (all 138 pass --check)". Nothing bound that
    figure: delete a generator's `--check` line from the Makefile and the spec
    files on disk still number 138, so the published count holds while the
    sentence goes false for that one contract. Comparing the invoked names
    against the spec family is the only reading on which the parenthetical
    carries information, and the symmetric difference is used deliberately --
    a `--check` line whose spec no longer exists is a command the gate runs
    against nothing, and drift in either direction is worth the same failure.
    """
    checked = {m.group(1) for m in
               re.finditer(r"generate_(\w+)_spec\.py.*--check", makefile)}
    gap = set(specs) ^ checked
    if gap:
        raise SystemExit(
            "check_lean_claims: spec files and `--check` generators are not "
            "one-to-one -- %s" % ", ".join(sorted(gap)))
    return len(checked)


def scrub_c(text):
    """Blank C comments and string literals, preserving every offset.

    Counting a token by textual occurrence is wrong for C: a generated header's
    doc comment can name the very thing being counted. `_Static_assert` is
    spelled twice that way, which is how the published figure came to be two
    higher than the number of assertions the compiler actually checks. Blanking
    to spaces keeps offsets stable, so a scan can still match delimiters.
    """
    blank = lambda m: " " * len(m.group(0))
    text = re.sub(r"/\*.*?\*/", blank, text, flags=re.S)
    text = re.sub(r"//[^\n]*", blank, text)
    return re.sub(r'"(?:[^"\\]|\\.)*"', blank, text)


def c_names(text):
    """The macro and enum-member names a C translation unit declares."""
    names = set(re.findall(r"#define\s+([A-Za-z_]\w*)", text))
    for body in re.findall(r"enum\s+\w*\s*\{([^}]*)\}", text, re.S):
        names |= set(re.findall(r"\b([A-Z][A-Z0-9_]{2,})\b", body))
    return names


def assert_conditions(text):
    """Each `_Static_assert` condition, found by balanced-paren scanning.

    A regexp cannot do this: the condition is a C expression whose parentheses
    nest to any depth, and the argument ends with a message string after the
    last comma. One match per directive is what the count has to mean.
    """
    out = []
    for m in re.finditer(r"_Static_assert\s*\(", text):
        i = m.end()
        depth = 1
        j = i
        while depth:
            if text[j] == "(":
                depth += 1
            elif text[j] == ")":
                depth -= 1
            j += 1
        out.append(text[i:j - 1])
    return out


def static_asserts(root):
    """The compile-time pins the generated headers carry, and how many of them
    name a hand-written constant.

    Both documents say the generated headers "carry 1,051 `_Static_assert`s
    that tie the hand-written decode constants to the generated tables". The
    figure was a textual count, and it was wrong twice over. Two of the 1,051
    spellings sit inside a comment, so only 1,049 assertions exist -- the
    number an earlier step had recorded before "correcting" it upward. And 263
    of those compare two generated renderings (a table's count against a
    literal, one header's code against another's) and name no hand-written
    constant at all, so the sentence characterized 786 of them as though it
    characterized all. The hand-written constants are read from the sibling
    architecture roots for the same reason the `#include` closure is: confining
    the scan to this directory finds none of them.
    """
    hand = set()
    for here in ("", "..", "../x86", "../arm64"):
        for path in glob.glob(os.path.join(root, here, "**", "*.h"),
                              recursive=True):
            if os.sep + ".lake" + os.sep in path or os.sep + "build" + os.sep \
                    in path or os.sep + "generated" + os.sep in path:
                continue
            hand |= c_names(scrub_c(open(path, errors="ignore").read()))
    if not hand:
        raise SystemExit(
            "check_lean_claims: no hand-written C constants found near %s -- "
            "the simulator headers are not where the scan looks" % root)
    gen_headers = sorted(glob.glob(os.path.join(root, "generated", "*.h")))
    if not gen_headers:
        raise SystemExit("check_lean_claims: no generated headers under %s"
                         % root)
    total = ties = 0
    for path in gen_headers:
        for cond in assert_conditions(scrub_c(
                open(path, errors="ignore").read())):
            total += 1
            if set(re.findall(r"[A-Za-z_]\w*", cond)) & hand:
                ties += 1
    return total, ties


def consumed_modules(gen, reached):
    """How many generated Lean modules a gate root imports.

    The section's consumption claim has a Lean half -- "all 138 modules are
    reachable through import from a Lean file the gate checks" -- and it was no
    more checked than the C half. Reachability means imported, transitively, by
    a module the gate runs `lake env lean` on: a generated module nothing
    imports is type-checked by nothing, so the figure would stay at 138 while
    the sentence went false.
    """
    dead = sorted(gen - reached)
    if dead:
        raise SystemExit(
            "check_lean_claims: %d of %d generated modules are imported by no "
            "gate root -- %s" % (len(dead), len(gen), ", ".join(dead)))
    return len(gen)


def consumed_headers(root, makefile):
    """The C-side reachability: headers reached, directly included, gate units.

    The section says every contract is consumed on both sides -- "all 138
    headers are #include-reachable from a C file the gate compiles (some only
    through the simulator header that includes them)". Before this function no
    checker followed an include, so an orphan header left the figure at 138 and
    the sentence false. The scan starts at the `.c` files the gate Makefile
    names, not at every `.c` on disk, and follows `#include` transitively
    because reaching a header through the header that includes it is what the
    sentence allows. A generated basename resolves only to its canonical
    `generated/` path, so a build-directory copy cannot stand in for the
    artifact the gate ships. All three figures are returned because the README
    quotes each of them: the split between direct and indirect inclusion is the
    part a reader would otherwise have to take on trust.
    """
    units = sorted({m for m in re.findall(r"[\w./-]+\.c", makefile)
                    if os.path.exists(os.path.join(root, m))})
    sources = []
    for here in ("", "..", "../x86", "../arm64"):
        for ext in ("c", "h"):
            sources += glob.glob(os.path.join(root, here, "**", "*." + ext),
                                 recursive=True)
    includes, by_name = {}, {}
    for path in sources:
        if os.sep + ".lake" + os.sep in path:
            continue
        includes[path] = INCLUDE.findall(open(path, errors="ignore").read())
        by_name.setdefault(os.path.basename(path), []).append(path)
    canonical = set(glob.glob(os.path.join(root, "generated", "*.h")))
    for name in by_name:
        path = os.path.join(root, "generated", name)
        if path in canonical:
            by_name[name] = [path]
    # Direct inclusion is read off the same parse, before the closure runs, so
    # the split the README quotes is a by-product rather than a second scan.
    direct = {os.path.basename(h) for u in units
              for h in includes.get(os.path.join(root, u), ())
              if os.path.join(root, "generated", os.path.basename(h))
              in canonical}
    seen = set()
    stack = [os.path.join(root, u) for u in units]
    while stack:
        for head in includes.get(stack.pop(), ()):
            for target in by_name.get(os.path.basename(head), ()):
                if target not in seen:
                    seen.add(target)
                    stack.append(target)
    orphan = sorted(os.path.basename(p) for p in canonical - seen)
    if orphan:
        raise SystemExit(
            "check_lean_claims: %d of %d generated headers reach no gate "
            "translation unit -- %s"
            % (len(orphan), len(canonical), ", ".join(orphan)))
    return len(canonical), len(direct), len(units)


def scan_tree(root):
    """Recompute every claim from the Lean sources and the gate Makefile."""
    # Both documents publish the artifact-family figure, so the three families
    # are measured here and their pairing enforced before any figure is read.
    fams = artifact_families(root)
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
    gen_defs = {}
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
            gen_defs[stem] = set(re.findall(r"^def (\w+)", src, re.M))
    for stem in own_lists:
        merged = {}
        for imp in imports[stem]:
            if imp.startswith("Generated"):
                merged.update(own_lists[imp])
        gen_lists[stem] = merged
    visible = {s: set().union(*[gen_defs.get(i, set()) for i in imports[s]])
               if imports[s] else set() for s in imports}
    counters = {"table": [], "pair": [], "sweep": [], "image": [],
                "total": [], "derived": [], "unstated": []}
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
            length = table_length_count(block, m.group(1), imports[stem],
                                        gen_counts)
            if length is not None:
                counters["table"].append(length)
            pair = refinement_pair(block, m.group(1), own_lists[stem],
                                   gen_lists[stem])
            if pair is not None:
                counters["pair"].append(pair)
            swept = sweep_checks(block, m.group(1))
            if swept is not None:
                counters["sweep"].append(swept)
            if m.group(1).endswith("_ops_total") and "cases op" in block:
                counters["total"].append(1)
            # A vacuous arm proves its conjuncts from a contradictory
            # hypothesis. Closing it with `simp_all` over the family lists
            # works and hides why, so the tree's six arms are required to
            # derive from the totality theorem that supplies the absurdity.
            if "nonmember" in m.group(1) and "∉" in block[:block.find(":=")]:
                body = block[block.find(":="):]
                if "absurd" in body:
                    counters["derived"].append(1)
                else:
                    counters["unstated"].append(m.group(1))
            image = image_pairs(block, m.group(1),
                                visible.get(stem, set()))
            if image:
                counters["image"].append(image)
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
        # The artifact-family figures the two documents publish: the contract
        # count, and the two renderings of it. `artifact_families` has already
        # refused to return unless all three families name the same contracts.
        "specs": fams["spec"],
        "headers": fams["header"],
        "gen_mods": fams["module"],
        # The non-vacuity sentence's three clauses each quote a figure from
        # one of these classes. All three are asserted non-empty there, so an
        # empty list -- the theorems renamed, or a shape restated so the rule
        # minimum.
        "table_length": len(counters["table"]),
        "table_min_count": min(counters["table"]),
        "table_max_count": max(counters["table"]),
        # How many equalities equate two list literals, and how short their
        # shorter side gets: the figure that says none compares a table with
        # itself or with `[]`.
        "refine_pairs": len(counters["pair"]),
        "refine_min_entries": min(counters["pair"]),
        # How many sweeps pair a range with outside checks, and the fewest such
        # checks any one of them carries.
        # The fourth shape the sentence's enumeration left outside itself: a
        # generated table's image at every width, pinned by a literal list.
        "images": len(counters["image"]),
        # The nonmember arm of each dispatch contract is vacuous only because
        # its umbrella list covers every constructor, which the doc comment
        # asserted and nothing proved. Four `*_ops_total` theorems now do, and
        # the count is published so the sentence cannot outlive them.
        "ops_total": len(counters["total"]),
        # A name that says "nonmember" while its proof never argues from the
        # absurd hypothesis is a vacuous arm closed the old way.
        "vacuous_derived": len(counters["derived"]),
        "vacuous_unstated": counters["unstated"],
        "sweeps": len(counters["sweep"]),
        "sweep_min_checks": min(counters["sweep"]),
    }
    for arch in arch_mods:
        out[arch + "_mods"] = arch_mods[arch]
        out[arch + "_thms"] = arch_thms[arch]
    # The section's other half of the pairing claim: every contract is consumed
    # on both sides. A count short of the family size raises rather than being
    # published -- an artifact the gate cannot reach is the failure the
    # sentence rules out, not a size change. The direct/indirect split is
    # published too so the README's per-side figures all come from one scan.
    c_reached, c_direct, c_units = consumed_headers(root, makefile)
    out["c_consumed"] = c_reached
    out["c_direct"] = c_direct
    out["c_units"] = c_units
    out["c_indirect"] = c_reached - c_direct
    # The third generator-side figure: how many specs the gate re-derives with
    # `--check`. Bound to the spec family, because the published count tracks
    # the files on disk and would not notice a dropped Makefile line.
    out["checked"] = checked_generators(
        makefile, family(root, "*_spec.json", "", "_spec.json"))
    # The compile-time pinning figure: how many assertions the generated
    # headers carry, and how many of them name a hand-written constant. Both
    # documents published a textual count that included two comment mentions,
    # and characterized every assertion as a tie to the hand-written decode.
    out["asserts"], out["assert_ties"] = static_asserts(root)
    out["lean_consumed"] = consumed_modules(set(gen_counts), seen)
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
    # The clause's second half named "the exactness theorems" with no rule,
    # and the five theorems that end `_exact` are not that class: one is a
    # boundary conjunction and four compare a projection of a table, not a
    # list. The paper now names the class the rule finds.
    (re.compile(r'the (\d+) refinement equalities'), ("refine_pairs",)),
    (re.compile(r'both sides hold at least (\d+)'), ("refine_min_entries",)),
    # The third half paired a sweep with "explicit non-membership checks"
    # without saying what made a theorem a pair rather than a bare round trip,
    # so a sweep that pinned nothing outside its range kept it true.
    (re.compile(r'the (\d+) dispatch sweeps'), ("sweeps",)),
    (re.compile(r'at least (\d+) explicit'), ("sweep_min_checks",)),
    # The sentence's universal -- the theorems that close by `rfl` or `decide`
    # over a table carry content -- ranged over a population its three named
    # shapes did not cover, so a stacked write's ladder image sat outside it.
    # The fourth shape is bound for the same reason as the others: the
    # enumeration now names every form the rule finds.
    (re.compile(r'the (\d+) table-image theorems'), ("images",)),
    (re.compile(r'until (\d+) totality theorems'), ("ops_total",)),
    (re.compile(r'all (\d+) nonmember arms derive'), ("vacuous_derived",)),
    # The section opens by claiming the artifacts are paired one-to-one with
    # their specifications, and states the figure three times in one sentence.
    # All three counts were hand-kept and the pairing was asserted, never
    # checked: a contract rendered on one side only would have left the numbers
    # right and the sentence false. `artifact_families` compares the names.
    (re.compile(r'(\d[\d,]*) specifications into (\d[\d,]*) C headers '
                r'and (\d[\d,]*)'), ("specs", "headers", "gen_mods")),
    (re.compile(r'from (\d[\d,]*) shared specifications each rendered'),
     ("specs",)),
    (re.compile(r'every one of the (\d[\d,]*) is also consumed'), ("specs",)),
    # The sentence's second half asserted consumption without measuring it: a
    # contract orphaned on one side left all three counts at 138 and made the
    # sentence false. Both figures now come from a reachability closure -- C
    # `#include` from the translation units the gate Makefile compiles, Lean
    # `import` from the roots it runs -- and either closure raising means the
    # claim is not merely unchecked but unsatisfiable.
    (re.compile(r'all (\d+) headers are'), ("c_consumed",)),
    (re.compile(r'all (\d+) modules are'), ("lean_consumed",)),
    # "all 138 pass --check" was the last generator-side figure left unbound:
    # the count followed the spec files on disk, so deleting a generator's
    # `--check` line kept 138 correct while the claim went false for that one
    # contract. It now names the invocations the gate really runs.
    (re.compile(r'all (\d+) pass'), ("checked",)),
    # The compile-time sentence stated one figure and characterized all of it
    # wrongly. The count was textual, so it read two comment mentions as
    # assertions, and a quarter of the real ones relate two generated
    # renderings to each other without naming a hand-written constant.
    (re.compile(r'(\d[\d{},\\]*) \\texttt\{\\_Static'), ("asserts",)),
    (re.compile(r'of which (\d+) name a hand-written'), ("assert_ties",)),
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
    # The reachability sentence quotes three figures of its own -- how many
    # translation units the gate compiles, and how the reached headers split
    # between direct and indirect inclusion. All three came out of the same
    # scan, so leaving them hand-kept would have made the new sentence the
    # only unbound part of the paragraph it explains.
    (re.compile(r'from the (\d+) `\.c` files'), ("c_units",)),
    (re.compile(r'(\d+) headers are included'), ("c_direct",)),
    (re.compile(r'the other (\d+) only'), ("c_indirect",)),
    # The README's mutation survey states its own denominator, "Of the 138
    # generators that exist", and it is the same set the section's `--check`
    # parenthetical counts. Bound to one figure, the two documents cannot
    # disagree about how many generators there are.
    (re.compile(r'(\d[\d,]*)\*{0,2} generators that exist'), ("checked",)),
    # The README states the same three family figures and, unlike the section,
    # asserts the pairing outright ("verified as a bijection in both
    # directions"). That sentence described a check that did not exist; now it
    # names the one that does.
    (re.compile(r'(\d[\d,]*) `\*_spec\.json` contracts'), ("specs",)),
    (re.compile(r'\((\d[\d,]*)/(\d[\d,]*)/(\d[\d,]*)\)'),
     ("specs", "headers", "gen_mods")),
    # The README repeated the section's compile-time sentence, with the same
    # textual count and the same over-broad characterization, so both documents
    # now read off one measurement of each figure.
    (re.compile(r'(\d[\d,]*) `_Static_assert'), ("asserts",)),
    (re.compile(r'(\d+) of which name a simulator'), ("assert_ties",)),
    (re.compile(r'the other (\d+) tie generated'), ("assert_own",)),
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
    # A nonmember arm closed without naming the absurdity is the old proof
    # shape back again: nothing published would change, so it raises here.
    if actual["vacuous_unstated"]:
        raise SystemExit(
            "check_lean_claims: %d vacuous arm(s) do not derive from their "
            "totality theorem -- %s"
            % (len(actual["vacuous_unstated"]),
               ", ".join(actual["vacuous_unstated"])))
    # The README states the split, so the second half is published as a figure
    # too. Derived here rather than stored: it is the total minus the ties, and
    # a stored third number could disagree with the other two.
    actual["assert_own"] = actual["asserts"] - actual["assert_ties"]
    bad = []
    for path, claims in targets:
        text = flat(pathlib.Path(path).read_text())
        seen_any = False
        for pattern, names in claims:
            seen = False
            for m in pattern.finditer(text):
                seen = seen_any = True
                for i, name in enumerate(names, start=1):
                    claimed = number(m.group(i))
                    if claimed != actual[name]:
                        bad.append(("%s: %s" % (path.name, m.group(0)[:48]),
                                    name, claimed, actual[name]))
            # A pattern that matches nothing binds nothing, so the figure it
            # guards goes unread while the run stays green -- the same failure
            # as a stale number, one step earlier. Rewording one clause used to
            # retire it silently; now the clause has to be somewhere.
            if not seen:
                bad.append(("%s: %r matches nothing, so its figure went "
                            "unread" % (path.name, pattern.pattern[:44]),
                            "-", "-", "-"))
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
          "%d quantified by cases, %d/%d contracts consumed (C/Lean)"
          " -- all claims current"
          % (actual["theorems"], actual["native_decide"],
             actual["native_modules"], actual["modules"],
             actual["refines"], actual["refines_decided"],
             actual["quant_cases"], actual["c_consumed"],
             actual["lean_consumed"]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))