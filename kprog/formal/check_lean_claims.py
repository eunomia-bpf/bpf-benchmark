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
# A statement that composes a step or handler: the shapes the section calls
# compositional obligations. `*_example` names an instantiation of one.
COMPOSES = re.compile(r"StepSpec|_step_|HandlerOf|handlerFor|compose")
COMPOSE_EXAMPLE = re.compile(r"example")

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
    widths, count = [], 0
    for part in conjuncts(statement(block, name)):
        if not MAP_IMAGE.search(part):
            continue
        if not any(re.search(r"\b" + re.escape(g) + r"\b", part)
                   for g in gen_defs):
            continue
        # Each match carries its own offset. Seeking the text instead would
        # measure the first occurrence twice whenever both sides are equal,
        # which makes the equality check below vacuous.
        lengths = [literal_length(part, m.start())
                   for m in re.finditer(r"\[[^\]]*\]", part)]
        # A map over a literal compared to a literal of a different length is
        # not the shape the sentence describes, and `= []` would satisfy a
        # bare count while pinning nothing. Equal, non-empty sides make the
        # conjunct say what the class claims it says.
        if len(lengths) < 2 or len(set(lengths)) != 1 or not lengths[0]:
            continue
        widths.append(lengths[0])
        count += 1
    # The sentence says every such theorem pins all four widths, so the
    # smallest width count is what that figure means.
    return (count, min(widths)) if widths else (0, 0)


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


def axiom_sample(root, modules):
    """`{module: {class}}` for a handful of modules, probed here.

    The full axiom census costs three minutes and is not a build target, so
    the recorded counts are spot-checked against four modules chosen to
    cover every class: one axiom-free, one with a single propext theorem,
    one whose theorems all assume the compiler, and one holding three
    classes at once. Each module is one `lake env lean` invocation.
    """
    import axiom_census

    out = {}
    seen = axiom_census.modules(root)
    for module in modules:
        names, space = seen[module]
        found = axiom_census.footprints(root, module, names, space)
        kinds = set()
        for axioms in found.values():
            if not axioms:
                kinds.add("none")
            elif "Lean.ofReduceBool" in axioms:
                kinds.add("compiler")
            elif "Classical.choice" in axioms:
                kinds.add("kernel-choice")
            else:
                kinds.add("kernel")
        out[module] = kinds
    return out


def harness_claims(text):
    """How many mutation-row claims the section contains, by its own wording.

    A count of claims rather than of parseable ones, so the parser can be
    held to it: a pattern that matched a third of the section reported a
    clean run and became the bug it was written to catch, which only a
    coverage count makes visible.
    """
    return len(re.findall(r"\d+ rows catch \(", flat(text)))


def detector_sums(text):
    """`[(caught, stage sum)]` for the "N catch (a at ..., b by ...)" family.

    The section writes these claims without the word "rows", and the third
    and fourth detectors are named several ways, so the counts are read by
    their detector label rather than by position. A parenthetical clause
    between the first two counts is dropped before the read.
    """
    pattern = re.compile(
        r"(\d+) catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)")
    labels = (r"(?:at the generator stage|by the Lean chain|in the Lean "
              r"chain|by the (?:[\d,]+-case )?host oracle|by the rout\w* "
              r"oracle|by the route scanner)")
    out = []
    for hit in pattern.finditer(flat(text)):
        body = re.sub(r"---.*?---", "", hit.group(2))
        stages = [int(n) for n in re.findall(r"(\d+) " + labels, body)]
        # "plus the one movk-regex catch" is a count written as a word, and
        # the harness has exactly one such row. It must be added after the
        # rest, because the label alternation stops at "the".
        stages += [1] * len(re.findall(r"\bthe one [\w-]+ catch", body))
        if len(stages) >= 3:
            out.append((int(hit.group(1)), sum(stages)))
    return out


def harness_sums(text):
    """`[(total, sum of stages, survivors)]` for each mutation-row claim.

    A harness paragraph states its row count, splits the caught rows across
    three detectors, and says how many survive as equivalences. The stated
    count must equal the stage sum: one paragraph said 93 rows catch while
    its own stages added to 101, so the number a reader would quote and the
    breakdown beside it disagreed. The survivors are a separate class and are
    not part of the sum.
    """
    # The stage clauses carry parenthetical expansions and either commas or
    # semicolons between them, so the inner group is matched to the closing
    # paren and the three counts are then read by their labels. A tighter
    # pattern matched only a third of the claims and reported a clean run.
    pattern = re.compile(
        r"(\d+) rows catch \(([^)]*(?:\([^)]*\)[^)]*)*)\)")
    out = []
    for hit in pattern.finditer(flat(text)):
        stages = [int(n) for n in re.findall(
            r"(\d+) (?:at|through|by) the", hit.group(2))]
        if len(stages) == 3:
            out.append((int(hit.group(1)), sum(stages)))
    return out


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
    # A table-image theorem may pin a generated function or a hand-written
    # independent spec, and either is a table in the sense the sentence means.
    # Confining the lookup to generated modules hid ten theorems that state
    # the same thing about a spec defined in their own module.
    all_defs = {}
    for path in mods:
        all_defs[os.path.basename(path)[:-5]] = set(re.findall(
            r"^def (\w+)", open(path, errors="ignore").read(), re.M))
    # Only generated *tables* -- literal lists -- are what the sentence means
    # by a table. Counting every generated def would take the population to
    # 675 theorems, most of which compare a folded value rather than a table,
    # and the enumeration is not about those.
    generated_names = gen_lists
    visible = {}
    for s in imports:
        seen_defs = set(all_defs[s])
        for imp in imports[s]:
            seen_defs |= all_defs.get(imp, set())
        visible[s] = seen_defs
    compose = [0, 0, 0]
    ident = [0, 0, 0]
    bvshape = [0, 0, [], 0]
    sweep = [set(), 0]
    counters = {"table": [], "pair": [], "sweep": [], "image": [],
                "width": [], "total": [], "derived": [], "unstated": [],
                "tabled": [], "outside": [],
                "kind": [0, 0, 0, [], 0], "split_bv": []}
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
            # An identity over bit-vector binders, and whether bv_decide
            # closes it. The section said bv_decide closes most of them; the
            # measurement says a quarter, and the rest cite, rewrite, or
            # simplify, so the sentence states the share.
            bsig = signature(block, m.group(1))
            bstmt = statement(block, m.group(1)).strip()
            if "BitVec" in bsig and re.search(r"[^<>=!]=(?!=)", bstmt):
                ident[0] += 1
                bbody = block[block.find(":="):]
                if re.search(r"\bbv_decide\b", bbody):
                    ident[1] += 1
                elif "native_decide" in bbody:
                    ident[2] += 1
            # The paragraph says none of the bv_decide identities reduces a
            # product of two wide operands. That is exactly testable: no
            # product of two non-constant bit-vector terms in a statement the
            # tactic closes.
            if re.search(r"\bbv_decide\b|\bnative_decide\b",
                         block[block.find(":="):]):
                sweep[0].add(stem)
                sweep[1] += 1
            if "bv_decide" in block and "native_decide" not in block:
                # One statement may carry several products; the published
                # figure is statements, so count the theorem once.
                if re.search(r"(\w+)\s*\*\s*(\w+)",
                             statement(block, m.group(1))):
                    bvshape[3] += 1
                for mul in re.finditer(r"(\w+)\s*\*\s*(\w+)",
                                       statement(block, m.group(1))):
                    if not any(re.fullmatch(r"\d+", g) for g in mul.groups()):
                        bvshape[2].append(m.group(1))
                bbody = block[block.find(":="):]
                if re.search(r"\bcases\b", bbody):
                    bvshape[0] += 1
                elif re.search(r"[(\[{]", signature(block, m.group(1))):
                    bvshape[1] += 1
            # Composition-shaped statements, and how their proofs close: the
            # section states this split rather than denying evaluation.
            stmt_only = block[:block.find(":=")]
            if COMPOSES.search(stmt_only):
                compose[0] += 1
                if "native_decide" not in block[block.find(":="):]:
                    compose[1] += 1
                elif not COMPOSE_EXAMPLE.search(m.group(1)):
                    bounded = bool(re.search(r"[(\[{]",
                                             signature(block, m.group(1))))
                    if bounded:
                        compose[2] += 1
            if "native_decide" in block:
                # Classify the use: a bounded enumeration (binders, split by
                # cases), an example (no binders), a refinement-named table
                # equality, or none of the three.
                sig = signature(block, m.group(1))
                bound = bool(re.search(r"[(\[{]", sig))
                split = bool(re.search(r"\bcases\b", block[block.find(":="):]))
                # The three kinds are not disjoint: two refinement-named
                # uses are also bounded enumerations. Each kind is counted as
                # a population of its own, and the section says the three sum
                # to one fewer than the construct's total for that reason.
                named_use = refinement_named(m.group(1))
                if bound and split:
                    counters["kind"][0] += 1
                if named_use:
                    counters["kind"][2] += 1
                    if bound and split:
                        counters["kind"][4] += 1
                if not bound and not named_use:
                    counters["kind"][1] += 1
                if not (bound and split) and not named_use and bound:
                    counters["kind"][3].append(m.group(1))
                # The sentence also says a bit-vector binder is left free
                # rather than split, which is what keeps the split finite. A
                # `cases` over one would make the statement's finiteness a
                # multiple of 2^64 and the sentence false.
                if bound and split:
                    for var in re.findall(
                            r"((?:\w+\s+)+):\s*BitVec", sig):
                        if any(re.search(r"\bcases\s+" + re.escape(v) + r"\b",
                                         block[block.find(":="):])
                               for v in var.split()):
                            counters["split_bv"].append(m.group(1))
                native_decide += 1
                refines_decided += named
                native_modules.add(os.path.basename(path))
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
            # The sentence's universal is "the theorems that close by rfl or
            # decide over a table", and the enumeration after it is the whole
            # of that population: 77 theorems name a generated table, and 77
            # fall in the four classes. A theorem that named one and matched
            # none would make the enumerated list read as exhaustive when it
            # had stopped being so, so both sides are counted here.
            inclass = any(c for c in (
                table_length_count(block, m.group(1), imports[stem],
                                   gen_counts) is not None,
                refinement_pair(block, m.group(1), own_lists[stem],
                                gen_lists[stem]) is not None,
                sweep_checks(block, m.group(1)) is not None,
                image_pairs(block, m.group(1), visible[stem])[0] > 0))
            if "native_decide" not in block and re.search(
                    r"\brfl\b|\bdecide\b", block[block.find(":="):]):
                stmt = block[:block.find(":=")]
                if any(re.search(r"\b" + re.escape(g) + r"\b", stmt)
                       for g in generated_names[stem]):
                    counters["tabled"].append(1)
                    if not inclass:
                        counters["outside"].append(m.group(1))
            image = image_pairs(block, m.group(1),
                                visible.get(stem, set()))
            if image[0]:
                counters["image"].append(image[0])
                counters["width"].append(image[1])
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
        # The paragraph pairs "306 modules that prove 2,065 theorems", and the
        # theorem count iterates every file on disk while the module count is
        # the gate's reachable closure. They agree only while every file is
        # reachable, so an unreachable module would inflate the theorem figure
        # with proofs the gate never compiles.
        "unreachable": sorted(set(graph) - seen),
        "refines": refines,
        "refines_decided": refines_decided,

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
        # The population the non-vacuity sentence quantifies over. Each
        # theorem counted here names a generated table and closes by rfl or
        # decide; every one must also fall in a counted class, so the
        # enumeration cannot quietly describe part of its own subject.
        "tabled": len(counters["tabled"]),
        "tabled_outside": counters["outside"],
        # The section says native_decide's uses fall into three kinds and
        # names them, so the partition is measured: enumerations over a finite
        # type, example values, and refinement-named table equalities. A
        # theorem in none of them would leave the sentence describing most of
        # the construct's use while reading as though it described all.
        "kinds_enum": counters["kind"][0],
        "kinds_example": counters["kind"][1],
        "kinds_table": counters["kind"][2],
        "kinds_other": counters["kind"][3],
        # The overlap that keeps the three kinds from summing to the total.
        "kinds_overlap": counters["kind"][4],
        "split_bitvec": counters["split_bv"],
        "ident_total": ident[0],
        "ident_bv": ident[1],
        # bv_decide proofs split by `cases` (the stated mechanism) versus
        # binding a bit-vector directly (which reaches the same wall without a
        # split). The paragraph now distinguishes them.
        "bv_cases": bvshape[0],
        "bv_direct": bvshape[1],
        "bv_products": bvshape[2],
        "bv_products_n": bvshape[3],
        "sweep_modules": len(sweep[0]),
        "sweep_theorems": sweep[1],
        "bv_total": bvshape[0] + bvshape[1],
        # 165 closes under bv_decide; with the token replaced by
        # `decide +revert` two of them compile and 159 do not. This is a
        # recorded sweep result, not a tree property.
        "bv_revert_recovered": 2,
        # Recorded sweep outputs: the failure mode of each group.
        "unstated_cases": 58,
        "unstated_direct": 103,
        # Recorded #print axioms results over the 165 bv_decide proofs.
        # The whole tree, measured with #print axioms: axiom-free, compiler-
        # assuming, and axiomatic-but-kernel-only.
        "ax_none": 617,
        "ax_orb": 623,
        "ax_kernel": 825,
        # The scanned forms, counted from check_no_sorry.py rather than
        # restated: sorry/admit is one class, then the four declaration
        # keywords.
        "nossorry_forms": 1 + len(
            re.search(r'DECL = re\.compile\(r"\^\\s\*\(([^)]*)\)',
                      open(os.path.join(root, "check_no_sorry.py")).read()
                      ).group(1).split("|")),
        # Four modules spanning every class, re-probed here rather than
        # trusted; the full census is too slow for a build target.
        "ax_sample": axiom_sample(root, ("X86MemDispatch",
                                         "Arm64DispatchTotality",
                                         "CrossIsaRev", "Arm64Stlxr")),
        "ax_choice": 40,
        "ax_native": 483,
        "ax_choice_all": 179,
        "ax_choice_both": 139,
        # The share is derived, floored like every other share here, so the
        # sentence cannot round 2065-partitioning counts up to "a third".
        "ax_share": 100 * 623 // 2065,
        "orb_reach": 69,
        "orb_kernel": 96,
        "ident_nd": ident[2],
        "ident_cite": ident[0] - ident[1] - ident[2],
        "ident_share": 100 * ident[1] // max(ident[0], 1),
        "compose_total": compose[0],
        "compose_cited": compose[1],
        "compose_eval": compose[0] - compose[1],
        "compose_comp": compose[2],
        "kinds_sum": (counters["kind"][0] + counters["kind"][1]
                      + counters["kind"][2] - counters["kind"][4]),
        "images": len(counters["image"]),
        "image_min_widths": min(counters["width"]) if counters["width"] else 0,
        "image_max_widths": max(counters["width"]) if counters["width"] else 0,
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
    (re.compile(r'Its (\d+) uses fall into three kinds'), ("native_decide",)),
    (re.compile(r'the (\d+) finite enumerations over a'), ("kinds_enum",)),
    # The third kind counts refinement-named uses, not the narrower
    # "table equals list" shape: several of them refine a generated handler
    # against an independent one, and the sentence now says refinement.
    (re.compile(r'and (\d+) of the 609 refinement-named'), ("kinds_table",)),
    (re.compile(r'(\d+) of the refinement uses are themselves'),
     ("kinds_overlap",)),
    (re.compile(r'sum to (\d+) rather than'), ("kinds_sum",)),
    (re.compile(r'(\d+) concrete example values'), ("kinds_example",)),
    (re.compile(r'The (\d+) enumerations are universally quantified'),
     ("kinds_enum",)),
    # The section claimed compositional obligations are never discharged by
    # evaluation. Reading the statements finds 165 compositions, 151 of which
    # cite or rewrite, and two that rewrite once and then decide a finite
    # table -- so the sentence states the split instead of denying it.
    # The paragraph said bv_decide closes most value and flag identities.
    # Measuring by statement shape gives a quarter, so the sentence states the
    # share and the split instead of a direction.
    # The axiom footprint decides whether a closed goal is trusted like
    # native_decide's. Measured per theorem: 69 of the 165 bv_decide proofs
    # reach Lean.ofReduceBool and 96 do not, so the blanket claim was wrong.
    (re.compile(r'The other (\d+) discharge entirely'), ("orb_kernel",)),
    # The population the deployment claim covers is the one that assumes the
    # compiler, and the two documents' figures are counts of that, not of the
    # tactics' whole populations.
    (re.compile(r'Of the (\d+) theorems\s+stating an equality'),
     ("ident_total",)),
    (re.compile(r'binders, (\d+) are closed by'), ("ident_bv",)),
    (re.compile(r'and (\d+) by \\texttt\{native'), ("ident_nd",)),
    (re.compile(r'and the other (\d+) cite'), ("ident_cite",)),
    # The last clause: no bv_decide identity reduces a product of two wide
    # operands. Three statements contain a product and each multiplies by the
    # byte width, so the count is published and the shape is guarded.
    (re.compile(r'none of the (\d+) statements it closes that'),
     ("bv_products_n",)),
    # The re-discharge sweep's scope: "every module that uses either tactic"
    # was a universal with no figure. Both halves are tree-derivable, so the
    # sentence states them and neither can drift while the sweep's result is
    # quoted from prose.
    (re.compile(r'all\s+(\d+) modules that use either tactic'),
     ("sweep_modules",)),
    (re.compile(r'closing (\d+) theorems between them'), ("sweep_theorems",)),
    # The substitution result, measured by recompiling: of the native_decide
    # theorems one fails a bare decide, and of the bv_decide ones all but
    # four do. The denominators are tree-derivable; the numerators are the
    # sweep's output and are bound so the sentence cannot drift away from it.
    # Only the denominators are tree-derivable; the numerators come from the
    # recompile sweep and are recorded, not recomputed, in this checker.
    (re.compile(r'of the (\d+) obligations'), ("native_decide",)),
    (re.compile(r'\s+place, and of the (\d+)'), ("bv_total",)),
    # The revert experiment moves the bv count by two and the native count by
    # nothing, which is what rules out the tactic swap as the explanation.
    (re.compile(r'Reverting recovers (\d+),\s+both'),
     ("bv_revert_recovered",)),
    # The two-group split does not predict the failure mode: both groups are
    # dominated by goals the plain tactic cannot state, and none is stated
    # then fails. The four figures are sweep outputs; the group sizes are
    # tree-derivable and bound.
    (re.compile(r'(\d+) of the (\d+) and (\d+) of the (\d+) cannot state'),
     ("unstated_cases", "bv_cases", "unstated_direct", "bv_direct")),
    (re.compile(r'\. On (\d+) of those the plain'), ("bv_cases",)),
    (re.compile(r'The other (\d+)\s+bind a bit-vector'), ("bv_direct",)),
    (re.compile(r'of the (\d+) theorems whose statement composes'),
     ("compose_total",)),
    (re.compile(r', (\d+) are proved by'), ("compose_cited",)),
    (re.compile(r'and the (\d+) that do\s+evaluate'), ("compose_eval",)),
    (re.compile(r'except (\d+)\. Those'), ("compose_comp",)),
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
    (re.compile(r"All (\d+) theorems that close over a generated table"),
     ("tabled",)),
    (re.compile(r'the (\d+) table-length theorems'), ("table_length",)),
    # The tree divides three ways under #print axioms, measured over all 2065
    # theorems: axiom-free, compiler-assuming, and axiomatic-but-kernel-only.
    # The section states the split, so all three are bound.
    (re.compile(r'(\d+) theorems depend on none at\s+all,\s+(\d+) reach'),
     ("ax_none", "ax_orb")),
    (re.compile(r'remaining (\d+) use only'), ("ax_kernel",)),
    (re.compile(r'with (\d+) of those also drawing'), ("ax_choice",)),
    (re.compile(r'gives (\d+), since (\d+) of the'), ("ax_choice_all",
                                                       "ax_choice_both")),
    (re.compile(r'therefore covers (\d+)\\% of the'), ("ax_share",)),
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
    (re.compile(r"families they pin run from (\d+) to (\d+)"),
     ("image_min_widths", "image_max_widths")),
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
    # The sentence named five forms and called them six. The count is bound
    # to the checker's own keyword list, so adding a scanned form without
    # changing the sentence (or the reverse) is reported.
    (re.compile(r'reached by (\d+) of the (\d+)\s+\\texttt\{bv'),
     ("orb_reach", "bv_total")),
    (re.compile(r'and by (\d+) of the (\d+)\s+\\texttt\{native'),
     ("ax_native", "native_decide")),
    (re.compile(r'checks all (\d+) forms'), ("nossorry_forms",)),
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
    # The sentence enumerates the theorems that close over a table. A tabled
    # theorem outside every class would leave the enumeration describing part
    # of its own subject while reading as though it described all of it.
    if actual["tabled_outside"]:
        raise SystemExit(
            "check_lean_claims: %d theorem(s) close over a generated table "
            "and fall in no counted class -- %s"
            % (len(actual["tabled_outside"]),
               ", ".join(actual["tabled_outside"])))
    # The section says native_decide's uses fall into three kinds and adds the
    # one that does not. A second would make that sentence false while every
    # figure in it stayed right.
    if len(actual["kinds_other"]) > 1:
        raise SystemExit(
            "check_lean_claims: %d native_decide theorem(s) fall outside the "
            "three kinds -- %s"
            % (len(actual["kinds_other"]), ", ".join(actual["kinds_other"])))
    if actual["kinds_other"] != ["x86_mov_reg_arm_matches_handler"]:
        raise SystemExit(
            "check_lean_claims: the out-of-partition theorem is now %r, but "
            "the section names x86_mov_reg_arm_matches_handler"
            % (actual["kinds_other"],))
    # A product of two wide operands closed by bv_decide would falsify the
    # sentence's last clause, and would also be the interesting case for the
    # kernel-budget argument, so it raises rather than being counted.
    # The sweep's scope is the union of the two tactic counts, and the
    # sentence quotes 480 of one and 4 of the other as the re-discharge
    # result. If the union stopped matching, the quoted denominators would
    # describe a population the tree no longer has.
    if actual["sweep_theorems"] != (actual["native_decide"]
                                    + actual["bv_cases"]
                                    + actual["bv_direct"]):
        raise SystemExit(
            "check_lean_claims: the sweep's %d theorems are not the %d "
            "native_decide plus %d bv_decide ones"
            % (actual["sweep_theorems"], actual["native_decide"],
               actual["bv_cases"] + actual["bv_direct"]))
    if actual["bv_products"]:
        raise SystemExit(
            "check_lean_claims: %d bv_decide identity(ies) reduce a product "
            "of two wide operands -- %s"
            % (len(actual["bv_products"]), ", ".join(actual["bv_products"])))
    if actual["split_bitvec"]:
        raise SystemExit(
            "check_lean_claims: %d enumeration(s) case-split a bit-vector "
            "binder, which the section says stays free -- %s"
            % (len(actual["split_bitvec"]),
               ", ".join(actual["split_bitvec"])))
    # The four axiom figures partition the tree, so they must sum to the
    # theorem count. They are recorded from a #print axioms sweep rather than
    # recomputed here, which is exactly why the sum needs checking: adding a
    # theorem would otherwise leave the published split describing a tree
    # that no longer exists, and every figure would still match its own
    # pattern.
    ax_sum = actual["ax_none"] + actual["ax_orb"] + actual["ax_kernel"]
    # The choice figures are three views of one population, so they must
    # agree: every theorem drawing on choice either also reaches the compiler
    # axiom or sits in the kernel-only class. A partial re-measurement would
    # leave all three matching their own patterns while the identity broke.
    if (actual["ax_choice_all"] - actual["ax_choice_both"]
            != actual["ax_choice"]):
        raise SystemExit(
            "check_lean_claims: the choice figures disagree -- %d drawing on "
            "it, %d of them also reaching Lean.ofReduceBool, %d kernel-only"
            % (actual["ax_choice_all"], actual["ax_choice_both"],
               actual["ax_choice"]))
    if actual["ax_choice"] > actual["ax_kernel"]:
        raise SystemExit(
            "check_lean_claims: %d kernel-only theorems draw on choice but "
            "the kernel-only class has %d"
            % (actual["ax_choice"], actual["ax_kernel"]))
    # The section distinguishes checks the build runs from those it does not.
    # Keeping that true costs one scan of the Makefile: a checker moved into
    # the gate without the sentence changing, or the reverse, would make the
    # prose describe a build that no longer exists.
    makefile = open(os.path.join(root, "Makefile")).read()
    in_gate = {c for c in ("check_paper_counts", "check_readme_counts")
               if c in makefile}
    if in_gate:
        raise SystemExit(
            "check_lean_claims: %s now runs in the build, but the section "
            "says the case-count script is outside it"
            % ", ".join(sorted(in_gate)))
    # The axiom counts are recorded from axiom_census.py, which needs ~3 min
    # and is therefore not a build target. A sample of four modules, one per
    # class, is affordable here and would have caught all three historical
    # errors in those figures: a mis-scored axiom-free class, a wrong class
    # count, and dropped theorems from a namespace mismatch.
    sample = {"X86MemDispatch": {"none"},
              "Arm64DispatchTotality": {"none", "kernel"},
              "CrossIsaRev": {"compiler", "kernel"},
              "Arm64Stlxr": {"none", "kernel", "compiler"}}
    if actual["ax_sample"] != sample:
        raise SystemExit(
            "check_lean_claims: the axiom spot check disagrees -- %r, "
            "recorded %r; re-run axiom_census.py"
            % (actual["ax_sample"], sample))
    # Every mutation-row claim's stated count must equal its own detector
    # breakdown. One said 93 while its stages added to 101.
    section_text = pathlib.Path(targets[0][0]).read_text()
    sums = harness_sums(section_text)
    claims = harness_claims(section_text)
    # The section writes these claims in two forms: "N rows catch (...)",
    # which carries the detector split, and the split-first form used where
    # the stages describe the run rather than the caught subset. The parser
    # must account for every claim of the first form, since a pattern that
    # silently misses some is indistinguishable from a clean section.
    split_first = len(re.findall(r"rows split \d+ at the generator stage",
                                 flat(section_text)))
    if sums and len(sums) + split_first < claims:
        raise SystemExit(
            "check_lean_claims: parsed %d of %d harness row claims, so the "
            "rest went unread" % (len(sums), claims))
    alert = [(t, st) for t, st in sums if t != st]
    if alert:
        raise SystemExit(
            "check_lean_claims: %d harness claim(s) disagree with their own "
            "stage breakdown -- %s"
            % (len(alert), "; ".join("%d stated, %d in stages" % (t, st)
                                     for t, st in alert)))
    # The detector-attribution family ("N catch (a at ..., b by ...)") has
    # five claims whose stage counts do not sum to the caught figure. They are
    # recorded rather than corrected: fixing them needs the harness re-run,
    # and the section gives no note explaining the difference, so the
    # discrepancy is surfaced here instead of being silently tolerated.
    # The breakdown counts every row by the detector that must catch it, and
    # the catch figure excludes the rows marked equivalent, so the two differ
    # by exactly the survivor count. Where a claim states its survivors the
    # relation is checked; where it does not, the stage sum only has to be at
    # least the catch figure, since a breakdown can never lose a caught row.
    short = [(a, b) for a, b in detector_sums(section_text) if b < a]
    if short:
        raise SystemExit(
            "check_lean_claims: %d detector claim(s) have a stage sum below "
            "their caught count -- %s"
            % (len(short), "; ".join("%d catch, %d in stages" % (a, b)
                                     for a, b in short)))
    # The harness claims state a caught count and a detector split, and the
    # harness states both. Until now the checker only required the claim to be
    # internally consistent, which every wrong figure in this family also was;
    # six of eleven drifted from their harness before this was measured.
    import harness_census

    compared = harness_census.claim_matches(section_text, root)
    drifted = [(name, paper, source) for name, paper, source in compared
               if paper != source]
    if drifted:
        raise SystemExit(
            "check_lean_claims: %d harness claim(s) disagree with their "
            "harness -- %s"
            % (len(drifted),
               "; ".join("%s says %d, harness has %d" % d for d in drifted)))
    # The forty "N rows catch" claims are the same measurement in the other
    # wording, and they were only ever checked for internal consistency too.
    # They resolve at the same cost and all forty agree today.
    rowed = harness_census.row_claim_matches(section_text, root)
    row_drift = [(n, paper, source) for n, paper, source in rowed
                 if paper != source]
    if row_drift:
        raise SystemExit(
            "check_lean_claims: %d row claim(s) disagree with their harness "
            "-- %s" % (len(row_drift),
                       "; ".join("%s says %d, harness has %d" % d
                                 for d in row_drift)))
    if len(rowed) < 44:
        raise SystemExit(
            "check_lean_claims: only %d row claims resolved to a harness, "
            "and 44 did when this was written; a claim that matches nothing "
            "went unread" % len(rowed))
    # The declared mutation total is the other figure a reader sizes a
    # harness by, and it was compared to nothing. Twenty-three claims carry
    # one alongside a catch count, and all twenty-three agree.
    import glob as _glob

    tables = {os.path.basename(p): harness_census.partitions(p)
              for p in _glob.glob(os.path.join(root, "build", "mut_*.py"))
              if harness_census.rows(p)}
    totals = harness_census.total_matches(section_text, tables)
    total_drift = [(n, a, b) for n, a, b in totals if a != b]
    if total_drift:
        raise SystemExit(
            "check_lean_claims: %d mutation total(s) disagree with their "
            "harness -- %s" % (len(total_drift),
                               "; ".join("%s says %d, harness has %d" % d
                                         for d in total_drift)))
    # Totals that stand beside no catch claim: the tree can only say whether
    # some harness has that many rows. Forty of the forty-three distinct
    # totals are a harness's present size; the other three describe stages a
    # harness grew through, which no file records, so they are exempt.
    sizes = {sum(parts[0].values()) for parts in tables.values()}
    flat_section = harness_census.re.sub(r"\s+", " ",
                                         section_text.replace("\\brk", ""))
    stray = sorted({int(m.group(1))
                    for m in harness_census.re.finditer(
                        r"(\d+)-mutation harness", flat_section)}
                   - sizes)
    if stray != [96, 100, 108]:
        raise SystemExit(
            "check_lean_claims: mutation totals %r match no harness size; "
            "96, 100 and 108 were the exempt growth stages" % (stray,))
    # Those three are stages of one harness growing by four mutants at each
    # step, and the stages between them are stated too: 96, 100, 104 and 108
    # name the sixth through ninth detectors. The arithmetic is the only
    # thing about them the tree can confirm, so it is checked.
    # The four stages must also appear in order, because one of the sizes
    # (104) is a different harness's present size as well and a presence
    # test alone cannot tell the two apart.
    stages = [96, 100, 104, 108]
    positions = [flat_section.find("%d-mutation harness" % t) for t in stages]
    ordered = [t for _, t in sorted(zip(positions, stages))]
    if -1 in positions or ordered != stages:
        raise SystemExit(
            "check_lean_claims: the growth stages appear at %r, so a stage "
            "went missing or was renumbered" % (positions,))
    if any(b - a != 4 for a, b in zip(stages, stages[1:])):
        raise SystemExit(
            "check_lean_claims: the growth stages no longer advance by four")
    if len(totals) < 23:
        raise SystemExit(
            "check_lean_claims: only %d mutation totals resolved to a "
            "harness, and 23 did when this was written" % len(totals))
    # The third figure: how many rows survive as documented equivalences.
    # Nine claims state it beside the other two, and all nine agree.
    survivors = harness_census.survivor_matches(section_text, tables)
    surv_drift = [(n, a, b) for n, a, b in survivors if a != b]
    if surv_drift:
        raise SystemExit(
            "check_lean_claims: %d survivor count(s) disagree with their "
            "harness -- %s" % (len(surv_drift),
                               "; ".join("%s says %d, harness has %d" % d
                                         for d in surv_drift)))
    if len(survivors) < 9:
        raise SystemExit(
            "check_lean_claims: only %d survivor counts resolved to a "
            "harness, and 9 did when this was written" % len(survivors))
    if len(compared) < 11:
        raise SystemExit(
            "check_lean_claims: only %d harness claims resolved to a harness, "
            "and the section states 11; a claim that matches nothing went "
            "unread" % len(compared))
    if actual["unreachable"]:
        raise SystemExit(
            "check_lean_claims: %d module(s) are not reachable from the "
            "gate's roots, so their theorems are counted but never compiled "
            "-- %s" % (len(actual["unreachable"]),
                       ", ".join(actual["unreachable"])))
    if ax_sum != actual["theorems"]:
        raise SystemExit(
            "check_lean_claims: the recorded axiom split sums to %d, the "
            "tree has %d theorems; re-run the #print axioms sweep"
            % (ax_sum, actual["theorems"]))
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
          "%d bounded enumerations, %d/%d contracts consumed (C/Lean)"
          " -- all claims current"
          % (actual["theorems"], actual["native_decide"],
             actual["native_modules"], actual["modules"],
             actual["refines"], actual["refines_decided"],
             actual["kinds_enum"], actual["c_consumed"],
             actual["lean_consumed"]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))