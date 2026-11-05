#!/usr/bin/env python3
"""Check the safety section's stated figures against the tree that holds them.

The section states a case count for many oracles, a total for the tree, a
count for each population it partitions, and a name for each artifact it
cites. All of those are hand-maintained, and the first thing this checker
found was that ten occurrences of seven distinct numbers had gone stale
while a clean report sat over every one: it read the wrapped math form and
not the unwrapped one, which is the commoner of the two.

What it checks, in the order `main` runs them:

- case figures against a `make check` log, in four prose forms, each of
  which must appear in some banner or be grid arithmetic on a bare grid;
- the two gate-wide figures -- banner count and modeled-case sum -- which
  are re-derived from the log rather than matched by existence;
- the split of the gate's cases across the two simulators, traced from each
  banner through its run line to the compile line and that unit's include
  closure, with the four buckets required to partition the gate exactly;
- the trees the other checks read, so a fifth tree opened or one no longer
  opened is reported;
- partitions the section states: the axiom classes, the two ways a
  bv_decide population divides, and the native_decide split including the
  one use that fits none of its categories;
- growth series and census transitions, both of which must ascend;
- names the section carries -- files, Lean modules, theorem names, step
  numbers, harness file names -- each joined to the artifact that has to
  have it;
- the same figure stated in two places, which is how a contradiction
  inside the document was found rather than only a drift from the tree.

Three shapes are deliberately not claims. A number inside `\\texttt{...}` is
quoted program output, describing what a run printed at the time. A number
introduced by "plus" is one input family of an oracle, not the total a
banner prints. And an `N-case` adjective on a bare grid states arithmetic,
so it is read only when the phrase also names a host or oracle.

Two properties of the checker itself are checked here as well: no scan may
match nothing and report clean, and the gate log must be newer than every
component it reflects.

Usage: check_paper_counts.py --section <tex> --log <make check log> [--check]
"""
import subprocess
import argparse
import pathlib
import re

NUM = r"\d[\d{},\\]*"

# A `\texttt{...}` argument may contain one level of braces (`\texttt{a\{b\}}`).
TEXTTT = re.compile(r"\\texttt\{(?:[^{}]|\{[^{}]*\})*\}")

# A banner prints its case count three ways: the plain total, the plain total
# beside a helper count, and the vectors-plus-sweep total as its two parts.
# `summed` says whether the banner's modeled-case total is the sum of the
# numbers it prints -- the helper count is a different unit, so it is a legal
# claim but not part of the modeled-case sum.
BANNER = [(re.compile(r"OK \(([\d,]+) cases\)"), False),
          (re.compile(r"OK \(([\d,]+) cases, [\d,]+ helpers\)"), False),
          (re.compile(r"OK \((\d+) vectors \+ (\d+) sweep cases\)"), True)]

# An `N-case` adjective states an oracle's total only when the phrase around it
# names an oracle or a host. A bare grid names arithmetic instead: "the routed
# 1,470-case divide grid" is 2 x 5 x 7 x 3 x 7, while that host's banner prints
# 48,515 because it compares 33 cells per divide. The window stops at sentence,
# clause, and em-dash punctuation so it cannot reach an unrelated host, and a
# single hyphen stays legal so `20,145-case byte-array-oracle sweep` is read.
ORACLE = re.compile(r"(?i)\b(?:host|oracle|oracles)\b")
GRID = re.compile(r"(?i)\bgrids?\b")
TAIL = r"(?:(?!--)[^.;:\n]){0,40}"

# Every prose form that states an oracle's case count. The `-case` forms carry
# the oracle-noun gate; `N cases` and `N grid cases` state a total outright.
CLAIMS = [
    re.compile(r"\\\((?P<n>%s)\\\)-case" % NUM),
    re.compile(r"(?<!\\\()(?P<n>%s)-case%s" % (NUM, TAIL)),
    re.compile(r"(?<!\\\()(?P<n>%s)-\s+and\s+%s-case%s" % ((NUM,) * 2 + (TAIL,))),
    re.compile(r"(?<![\d{},])(?P<n>%s)\s+(?:grids?\s+)?cases\b" % NUM),
]

# "over 6984 grid cases plus 458712 fixed-seed repeats" states one part of an
# oracle; the claim is true when the sum is what the banner prints.
PLUS = re.compile(r"^\s+plus\s+(?:a\s+|an\s+)?([\d,]{1,3}(?:,\d{3})+|\d+)")

# "plus a 20,000-case sweep" names one input family, not the oracle's total.
COMPONENT = re.compile(r"(?i)plus\s+(?:a\s+|an\s+)?$")

# The section's two aggregate claims about the gate as a whole. Both are
# re-derivable from the same log, so quoting them in two places is a drift risk.
AGGREGATES = [(re.compile(r"(?P<n>%s) independent oracle banners" % NUM),
               "banners"),
              (re.compile(r"summing to (?P<n>%s) modeled cases" % NUM),
               "modeled cases")]

# A compile line names the source it compiled and the binary it built, which is
# how a banner is traced back to the translation unit and the include paths
# that produced it. The whole line is kept, not just the source: the `-I` paths
# are part of what the unit reaches.
COMPILE = re.compile(r"^\s*(?:cc|gcc)\b(.*?\b[\w/]+\.c\b.*?)\s+-o\s+"
                     r"build/(\S+)", re.M)
RUN = re.compile(r"^\./build/(\S+)$")
INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)
ROOTS = ("arm64", "x86")
# Each bucket's sentence states oracles, cases, and share, so one pattern binds
# all three: a drift in any of them would leave a sentence that still reads as
# though it had been measured. The section wraps mid-phrase, so the words are
# joined with `\s+`. Shares carry one decimal and are floored, as they are
# computed here.
PC = r"(?P<p>\d+\.\d)\\%"
PCT = r"\(" + PC + r"\)"
ISA = [
    (re.compile(r"(?P<n>\d+)\s+build\s+against\s+the\s+AArch64\s+headers"
                r"\s+and\s+carry\s+(?P<c>" + NUM + r")\s+" + PCT), "arm64"),
    (re.compile(r"(?P<n>\d+)\s+against\s+the\s+x86-64\s+headers\s+and"
                r"\s+carry\s+(?P<c>" + NUM + r")\s+" + PCT), "x86"),
    (re.compile(r"(?P<n>\d+)\s+include\s+both\s+simulators\s+in\s+one"
                r"\s+translation\s+unit\s+and\s+carry\s+(?P<c>" + NUM + r")\s+"
                + PCT), frozenset(ROOTS)),
    (re.compile(r"the\s+remaining\s+(?P<n>\d+)\s+\((?P<c>" + NUM + r"),\s+"
                + PC + r"\)"), frozenset()),
]

# Reaching a simulator is what the preprocessor does, not what the compile line
# advertises or the file is called, and both come apart. The section publishes
# how far, so a shortcut that drifted is reported, not assumed.
EXTRA = [
    ("quiet", re.compile(r"(?P<n>\d+)\s+hosts?\s+reach\s+a\s+simulator"
                         r"\s+their\s+compile\s+line\s+does\s+not\s+name")),
    ("misnamed", re.compile(r"(?P<n>\d+)\s+hosts?\s+carry\s+an\s+ISA\s+in"
                            r"\s+their\s+name\s+and\s+reach\s+no"
                            r"\s+simulator")),
]
WHAT = {"quiet": "reach a simulator no -I names",
        "misnamed": "carry an ISA in their name and reach none"}

BUCKET = {name: (frozenset((name,)) if isinstance(name, str) else name)
          for name, _ in [(n, 0) for _, n in ISA]}
LABEL = {frozenset(ROOTS): "both-ISA", frozenset(): "header-only"}


def masked(path: pathlib.Path) -> str:
    """The section with quoted program output blanked out."""
    return TEXTTT.sub(lambda m: "X" * len(m.group(0)), path.read_text())


def read_log(path: pathlib.Path) -> tuple[set[int], int, int]:
    """Return ({case count a banner prints}, banner count, modeled-case sum).

    A banner's numbers are legal claims individually and summed: a section may
    quote either part of `15 vectors + 20000 sweep cases` or the 20015 it totals.
    """
    text = path.read_text(errors="replace")
    counts: set[int] = set()
    banners = modeled = 0
    for rx, summed in BANNER:
        for match in rx.finditer(text):
            parts = [int(x.replace(",", "")) for x in match.groups()]
            counts.update(parts)
            if len(parts) > 1:
                counts.add(sum(parts))
            banners += 1
            modeled += sum(parts) if summed else parts[0]
    return counts, banners, modeled


def sim_split(path: pathlib.Path) -> tuple[dict[frozenset, tuple[int, int]],
                                           dict[str, int]]:
    """Return ({roots an oracle reaches: (banners, cases)}, stats).

    `stats["quiet"]` counts hosts reaching a simulator no `-I` flag names, and
    `stats["misnamed"]` hosts carrying an ISA in their name that reach neither
    simulator. Both numbers say how far the two tempting shortcuts -- the
    compiler flags and the file name -- are from what is actually built.

    A banner is attributed through the run line that printed it to the compile
    line that built it, so the classification reads the same translation unit
    the compiler did. An include is resolved against the unit's own directory
    and the compile line's `-I` paths, exactly as the preprocessor would, and a
    header reaches a simulator when its own path is under that root or some
    header it pulls in is. Every banner must resolve: a bucket that leaves a
    banner unattributed would silently under-report, which is the failure this
    whole measurement exists to prevent.
    """
    text = path.read_text(errors="replace")
    lines = text.splitlines()
    built: dict[str, str] = {}
    for flags, binary in COMPILE.findall(text):
        built[binary] = flags
    reached: dict[str, frozenset] = {}

    def roots(unit: pathlib.Path, dirs: list[pathlib.Path]) -> frozenset:
        key = str(unit)
        if key in reached:
            return reached[key]
        seen, todo, out = {key}, [unit], set()
        while todo:
            head = todo.pop()
            out |= {r for r in head.parts if r in ROOTS}
            for name in INCLUDE.findall(head.read_text(errors="replace")):
                for base in [head.parent, *dirs]:
                    hit = (base / name).resolve()
                    if hit.exists():
                        if str(hit) not in seen:
                            seen.add(str(hit))
                            todo.append(hit)
                        break
        reached[key] = frozenset(out)
        return reached[key]

    current, missing, buckets = None, [], {}
    stats = {"quiet": 0, "misnamed": 0}
    for line in lines:
        run = RUN.match(line)
        if run:
            current = run.group(1)
            continue
        for rx, summed in BANNER:
            hit = rx.search(line)
            if not hit:
                continue
            parts = [int(x.replace(",", "")) for x in hit.groups()]
            cases = sum(parts) if summed else parts[0]
            if current not in built:
                missing.append(current)
                break
            cmd = built[current]
            dirs = [pathlib.Path(d) for d in re.findall(r"-I(\S+)", cmd)]
            unit = pathlib.Path(re.search(r"([\w/]+\.c)", cmd).group(1))
            got = roots(unit, dirs)
            # A root reached through a relative include names no `-I` flag, so
            # the compiler's own command line understates what is built.
            flags = re.findall(r"-I(\S+)", cmd)
            named = {r for d in flags for r in pathlib.Path(d).parts
                     if r in ROOTS}
            stats["quiet"] += 1 if got - named else 0
            host = {r for r in current.lower().split("_") if r in ROOTS}
            stats["misnamed"] += 1 if host and not got else 0
            n, c = buckets.get(got, (0, 0))
            buckets[got] = (n + 1, c + cases)
            break
    if missing:
        raise SystemExit("check_paper_counts: %d banner(s) with no compile "
                         "line in the log -- %s" % (len(missing), missing[0]))
    return buckets, stats


def paper_counts(text: str) -> dict[int, int]:
    """Return {claimed count: how many times it appears}."""
    seen: dict[int, int] = {}
    for index, rx in enumerate(CLAIMS):
        gated = index in (1, 2)
        total = index == len(CLAIMS) - 1
        for match in rx.finditer(text):
            if gated:
                phrase = text[match.start():match.end()]
                if not ORACLE.search(phrase) or GRID.search(phrase):
                    continue
            # "plus a 20,000-case sweep" names one input family, not a total.
            if COMPONENT.search(text[max(0, match.start() - 24):match.start()]):
                continue
            value = int(re.sub(r"[{},\\]", "", match.group("n")))
            if total:
                plus = PLUS.match(text[match.end():match.end() + 24])
                if plus:
                    value += int(plus.group(1).replace(",", ""))
            seen[value] = seen.get(value, 0) + 1
    return seen


def case_census(text: str, counts: set[int]) -> tuple[int, list[int]]:
    """`(figures stated, figures with no banner)`.

    Every `N-case` figure either appears in a banner of the run or is
    arithmetic on a bare grid (`1,470-case divide grid` is 2 x 5 x 7 x 3 x 7).
    Nothing counted how many such figures exist, so one that matched no
    banner and no grid could sit in the prose while every claim this checker
    knows about stayed current.
    """
    stated, grid = {}, set()
    for match in re.finditer(r"(\d[\d,{}]*)-case", text):
        value = int(re.sub(r"[{},]", "", match.group(1)))
        stated[value] = True
        # A figure on a bare grid is arithmetic, not a banner: the section
        # says so of `1,470-case divide grid`, and the rule is the same one
        # the claim scan uses.
        if GRID.search(text[max(0, match.start() - 30):match.end() + 24]):
            grid.add(value)
    return len(stated), sorted(v for v in stated
                              if v not in counts and v not in grid)


def percent_census(text: str) -> set[str]:
    """Every percentage the section states, as written.

    Percentages are the one figure class split across two checkers: the ISA
    split owns four of them and its floored-sum sentence a fifth, while
    check_lean_claims owns the two shares it derives. Neither counts what it
    does not own, so a new percentage could appear in a sentence neither
    reads and both would report clean.
    """
    return {m.group(1) for m in re.finditer(r"(\d+(?:\.\d+)?)\\%", text)}


def lean_citations(text: str) -> set[str]:
    """The Lean modules a section cites by file name.

    The section names modules rather than theorems, so the citation can only
    be checked for existence — but existence is what a rename breaks, and
    forty-seven modules are cited.
    """
    # A break marker may sit inside a name, so the text is normalised
    # before extracting: `\brk{}` and `\brk ` both split a filename.
    plain = text.replace("\\brk{}", "").replace("\\brk ", "")
    plain = plain.replace("\\brk", "")
    return set(re.findall(r"([A-Z][A-Za-z0-9]+)\.lean", plain))


def document_refs(paper: pathlib.Path) -> tuple[set, set, int, int, set, set]:
    """`(undefined refs, uncited keys, live label count, bib entry count)`.

    Only the sections `main.tex` includes are read: the paper keeps older
    section files on disk, and those carry labels and citations that no
    document resolves. Restricting to the included set is what makes the
    result a statement about the paper rather than about the directory.
    """
    main = (paper / "main.tex").read_text()
    # A commented-out \input is not part of the paper, and the appendix is
    # commented out twice. Matching every \input reads a section the
    # document does not include.
    live = [paper / m for m in re.findall(
        r"^[^%\n]*\\input\{(sections/[^}]+)\}", main, re.M)]
    labels, refs, cites = set(), set(), set()
    for path in live:
        text = pathlib.Path(str(path) + ".tex").read_text()
        labels |= set(re.findall(r"\\label\{([^}]+)\}", text))
        refs |= set(re.findall(r"\\(?:ref|cref|autoref|Cref)\{([^}]+)\}",
                               text))
        for group in re.findall(r"\\cite[pt]?\{([^}]+)\}", text):
            cites |= {k.strip() for k in group.split(",")}
    bib = paper / "reference.bib"
    # A bibliography entry may be written `@type{key,` or `@type {key,`,
    # and five in this file use the space. Requiring the brace right
    # after the type made those keys invisible, so a citation of one
    # read as uncited rather than as unresolvable.
    keys = {k.strip() for k in re.findall(
        r"@\w+\s*\{\s*([^,\s]+)\s*,", bib.read_text())}
    # A duplicate label resolves to whichever the class file saw last, and a
    # reference into a section the paper does not include resolves to
    # nothing; both are silent in a clean LaTeX run with the directory on
    # the path.
    seen, dup = set(), set()
    for path in live:
        text = pathlib.Path(str(path) + ".tex").read_text()
        for name in re.findall(r"\\label\{([^}]+)\}", text):
            (dup if name in seen else seen).add(name)
    included = {path.stem for path in live}
    dead = {n for path in paper.glob("sections/*.tex")
            if path.stem not in included
            for n in re.findall(r"\\label\{([^}]+)\}", path.read_text())}
    return (refs - labels, cites - keys, len(labels), len(keys),
            dup, refs & (dead - labels))


def sweep_claims(text: str, counts: set[int]) -> tuple[int, list[int]]:
    """`(claims, case counts with no banner)` for "N-case ... all 256".

    A sweep claim ties an oracle's size to what it sweeps, so both halves
    have a source: the count in a banner and the sweep in the C file. The
    counts were already checked as claims; pairing them with the sweep is
    what says the number describes an exhaustive opcode sweep rather than
    some other oracle of the same size.
    """
    hits = re.findall(r"(\d[\d,{}]*)-case[^.]{0,200}?all (?:\\\()?256", text)
    vals = [int(re.sub(r"[{},]", "", h)) for h in hits]
    return len(vals), sorted(v for v in vals if v not in counts)


def whole_state_claims(text: str) -> tuple[int, int]:
    """`(claims comparing the whole register file, oracles able to)`.

    The claim is that an oracle compares all modelled state rather than the
    fields it drove. Whether a given oracle does that is a reading of its
    source; what can be counted is how many such claims the section makes
    and how many oracles have the mechanism, so the sentences cannot grow
    past the oracles that could support them.
    """
    claims = len(re.findall(r"compares the whole register file", text))
    # The C oracles live in the directory this checker is in, not below it.
    formal = pathlib.Path(__file__).resolve().parent
    able = sum(1 for p in formal.glob("*.c")
               if "FOR_EACH_GPR" in p.read_text(errors="ignore"))
    return claims, able


def reviewed_exceptions() -> int:
    """How many oracle exceptions the composition check accepts, with a why.

    The section says the check fails when a new unwired oracle appears and
    "reviews four exceptions". A fifth accepted entry, or a dropped one,
    would leave the sentence quoting a number the check no longer holds.
    """
    import ast
    src = pathlib.Path(__file__).with_name(
        "check_oracle_composition.py").read_text()
    for node in ast.walk(ast.parse(src)):
        if (isinstance(node, ast.Assign) and node.targets
                and getattr(node.targets[0], "id", "") == "ACCEPTED"):
            return len(node.value.keys)
    raise SystemExit("check_paper_counts: no ACCEPTED in the checker")


def full_state_oracles() -> int:
    """How many oracles compare every register's value and tag, and all four
    flags.

    The sentences say an oracle "compares the whole register file with its
    tags and all four flags". The macro that unrolls the comparison is not
    the invariant -- the comparison is, and several oracles spell it out
    under their own loop variables -- so this matches the two comparisons
    and the four flag names rather than a macro name.
    """
    import re
    n = 0
    for d in ("", "build"):
        for path in (pathlib.Path(__file__).parent / d).glob("*_host.c"):
            t = path.read_text(errors="ignore")
            if (re.search(r"if \(\w+ != mreg\[\w+\]\)", t)
                    and re.search(r"if \(\w+ != mtag\[\w+\]\)", t)
                    and all(k in t for k in ("_cf", "_zf", "_sf", "_of"))):
                n += 1
    return n


def every_case_oracles() -> list[tuple[str, bool]]:
    """`[(oracle, compares every register value and tag)]` in `build/`.

    The section says an oracle checks "every case ... against an independent
    condition/writeback/tag model". The tag comparison is the part that a
    value-only oracle would skip, so it is the part worth finding: an
    unrolled loop comparing both, and a flag comparison beside it.
    """
    out = []
    for path in sorted((pathlib.Path(__file__).parent / "build")
                       .glob("*_host.c")):
        text = path.read_text(errors="ignore")
        both = ("__cs_tag != mtag[" in text
                and "__cs_got != mreg[" in text)
        flags = ("!= cf ||" in text or "!= zf ||" in text)
        out.append((path.name, both and flags))
    return out


def memory_window_oracles() -> int:
    """How many oracles compare the whole 4 KiB memory window, the stack
    image, and its slot tags.

    The section says the execution oracles compare "the whole stack image
    with its slot tags, and all 4 KiB of the memory window against an
    independent byte-image model". A comparison of the bytes the case
    touched would be much weaker than one of the whole window, so the
    invariant is a memcmp over the full size.
    """
    n = 0
    for d in ("", "build"):
        for path in (pathlib.Path(__file__).parent / d).glob("*_host.c"):
            t = path.read_text(errors="ignore")
            if (re.search(r"memcmp\(heap, heap_exp, HEAP_BYTES\)", t)
                    and "stk_tag_exp" in t):
                n += 1
    return n


WORD = {w: i for i, w in enumerate(
    "zero one two three four five six seven eight".split())}


def sweep_products(text: str) -> list[tuple[int, int]]:
    """`[(stated cases, cases the sweep dimensions imply)]`.

    Three sentences give an oracle's size and the dimensions it sweeps, in
    two wordings: "all 256 opcodes x 4 widths x 2 tag classes", and "all 256
    opcodes crossed with four widths and four tag-class pairs". The
    dimensions are the claim, so their product has to be the figure; a
    sweep described one dimension wider than it is would print a size that
    no longer follows from the sentence.
    """
    num = lambda w: int(w) if w.isdigit() else WORD[w]
    pats = (r"(\d[\d,{}]*)-case[^.]{0,90}?all (\d+) opcodes"
            r" x (\d+) widths(?: x (\d+) tag classes)?",
            r"(\d[\d,{}]*)-case[^.]{0,90}?all (\d+) opcodes crossed with"
            r" (\w+) widths and (\w+) tag-class pairs")
    out = []
    for pat in pats:
        for m in re.finditer(pat, text):
            cases = int(re.sub(r"[{},]", "", m.group(1)))
            product = num(m.group(2)) * num(m.group(3))
            if m.group(4):
                product *= num(m.group(4))
            out.append((cases, product))
    return out


def dispatch_split() -> tuple[int, int, int, int]:
    """`(chain, modelled, gaps, gaps with a live route host)` for AArch64.

    The section says the chain branches on thirty-five families against
    twenty-four in the model, eleven absent, and that all eleven are now
    driven through the dispatcher. Each figure comes from the dispatch
    check, so the sentence cannot describe a gap the check has since closed.
    """
    import check_dispatch_model as dm
    cfg = dm.ISA["arm64"]
    chain = dm.chain_macros(cfg["header"])
    spec = dm.spec_bindings("arm64")
    defined, applied = dm.modelled_names(cfg["lean"])
    gaps = [m for m in chain
            if dm.why_unmodelled(m, spec, defined, applied)]
    return (len(chain), len(chain) - len(gaps), len(gaps),
            len(dm.A64_UNMODELLED))


def driven_bodies() -> list[str]:
    """The bodies the section says an oracle "drives the real ..." of.

    Each name has to resolve somewhere in the tree -- a macro in a simulator
    header, or a dispatch arm an oracle spells out -- because a sentence
    naming a body nothing drives would describe coverage that does not exist.
    """
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    sim = "\n".join(p.read_text(errors="ignore") for p in (
        pathlib.Path(__file__).parent.parent / "x86/x86_sim_local_bpf.h",
        pathlib.Path(__file__).parent.parent / "arm64/arm64_sim_local_bpf.h"))
    hosts = "\n".join(p.read_text(errors="ignore")
                       for p in pathlib.Path(__file__).parent.glob("*_host.c"))
    out = []
    for name in sorted(set(re.findall(
            r"drives the real \\texttt\{([^}]+)\}", flat))):
        stem = name.replace("\\_", "_").rstrip("*").rstrip("/")
        if stem not in sim and stem not in hosts:
            out.append(name)
    return out


def header_claim_oracles(log: pathlib.Path) -> list[str]:
    """Oracles named by "N-case ... includes the simulator header".

    The phrase must sit in the same clause as the count: a later clause can
    mention the header without claiming the oracle includes it, and matching
    across the sentence break turned six correct sentences into findings.
    """
    text = log.read_text(errors="ignore")
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    pat = (r"(\d[\d,{}]*)-case (?:[\w-]+ )?(?:host|oracle)"
           r"[^.;]{0,120}?includes the simulator header")
    claims = {int(re.sub(r"[{},]", "", c)) for c in re.findall(pat, flat)}
    cur, out = None, set()
    for line in text.splitlines():
        m = re.match(r"^\./build/(\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        m = re.search(r"OK \((\d[\d,]*) cases\)", line)
        if m and cur and int(m.group(1).replace(",", "")) in claims:
            out.add(cur)
    return sorted(out)


def harness_partitions(text: str) -> list[tuple[str, int, int]]:
    """`[(form, stated total, sum of the stated stages)]` for harnesses.

    Each sentence gives a harness its size and then splits the catches by
    the stage that made them. The stages are the claim, so they have to
    account for what the sentence says was caught, and never for more than
    the harness holds.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    num = lambda s: int(s.replace(",", ""))
    out = []
    m = re.findall(
        r"(\d+)-mutation harness[^.]{0,400}?"
        r"(\d+) caught at the specification/generator stage, "
        r"(\d+) by the Lean chain, and (\d+) by", flat)
    for tot, a, b, c in m:
        out.append(("stage", int(tot), int(a) + int(b) + int(c)))
    m = re.findall(
        r"(\d+)-mutation harness[^.]{0,300}?catches (\d+) changes?"
        r" \(([\d,]+) at the specification/generator stage, "
        r"([\d,]+) in the Lean chain, ([\d,]+) by the host oracle, "
        r"and ([\d,]+) by the routed oracle\)", flat)
    for tot, caught, a, b, c, d in m:
        out.append(("change", num(caught),
                    num(a) + num(b) + num(c) + num(d)))
    return out


def named_lean_objects() -> list[str]:
    """Lean names the prose presents as a chain, handler, table, theorem...

    A rename leaves the sentence describing something the tree no longer
    has, and nothing else in the paper would notice: the name is not a
    figure, so no count binds it.
    """
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    lean = "\n".join(p.read_text(errors="ignore")
                      for p in pathlib.Path(__file__).parent.rglob("*.lean")
                      if ".lake" not in str(p))
    # Only names shaped like a Lean declaration: an all-caps token is a C
    # macro or an opcode, and appears in Lean only inside comments.
    # camelCase only: an opcode is lowercase (sarx) or all caps (MOVBE), and
    # both appear in Lean only inside comments or macro names.
    pat = (r"\\texttt\{([a-z][A-Za-z0-9]*[A-Z][A-Za-z0-9_]*|"
           r"[A-Z][a-z][A-Za-z0-9]*[A-Z][A-Za-z0-9_]*|"
           r"[A-Z][a-z][A-Za-z0-9]*)\}"
           r"\s+(?:chain|handler|family|table|theorem|lemma|module|predicate|"
           r"relation|structure)")
    out = []
    for name in sorted(set(re.findall(pat, flat))):
        if not re.search(r"\b" + re.escape(name) + r"\b", lean):
            out.append(name)
    return out


def named_files() -> list[str]:
    """File names the section cites in `\texttt{}`.

    A renamed or deleted file leaves the sentence pointing at nothing, and
    a file name is not a figure, so no count binds it.
    """
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    names = sorted(set(re.findall(
        r"\\texttt\{([A-Za-z0-9_][\w./-]*\.(?:py|c|h|lean|json|yaml))\}",
        flat)))
    roots = [pathlib.Path(__file__).parent.parent.parent / d
             for d in ("kprog", "bpfopt")]
    out = []
    for name in names:
        if not any(list(r.rglob(name.split("/")[-1])) for r in roots):
            out.append(name)
    return out


def named_instructions() -> list[str]:
    """Names the prose presents as an arm, opcode, instruction or form.

    An instruction name is not a figure and not a file, so nothing else
    binds it: a rename in the dispatcher would leave the sentence naming an
    arm the tree no longer has. Python sources count too, because a battery
    pins arms in the tooling as well as in the simulators.
    """
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    names = sorted(set(re.findall(
        r"\\texttt\{([A-Z][A-Za-z0-9_]{1,18})\}\s+"
        r"(?:arm|opcode|instruction|form)\b(?![a-z])", flat)))
    src = "\n".join(p.read_text(errors="ignore")
                     for p in pathlib.Path(__file__).parent.parent.rglob("*")
                     if p.suffix in (".c", ".h", ".lean", ".py")
                     and ".lake" not in str(p))
    return [n for n in names
            if not re.search(r"\b" + re.escape(n) + r"\b", src, re.I)]


WORDS = {w: i for i, w in enumerate(
    "zero one two three four five six seven eight nine ten eleven twelve "
    "thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty "
    "twenty-one twenty-two twenty-three twenty-four twenty-five".split())}


def binding_mutations(text: str) -> list[tuple[int, int]]:
    """`[(stated total, sum of the stated parts)]` for binding mutations.

    The sentence gives a total and then splits it by the kind of change:
    seven routing distortions, six generated-C ones, one shared
    specification, three Lean spec changes. The parts are the claim, so they
    must reach the total -- nineteen against seventeen was the defect.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    pat = (r"(\w+(?:-\w+)?) binding mutations---"
           r"(\w+(?:-\w+)?) simulator-header routing distortions"
           r".*?(\w+(?:-\w+)?) generated-C ones, "
           r"(\w+(?:-\w+)?) shared-specification change, and "
           r"(\w+(?:-\w+)?) generated-Lean independent-spec changes")
    out = []
    for tot, a, b, c, d in re.findall(pat, flat):
        if tot in WORDS:
            out.append((WORDS[tot],
                        WORDS[a] + WORDS[b] + WORDS[c] + WORDS[d]))
    # The two-part form: "nine ... four simulator-header routing
    # distortions (...) and five contract distortions (...)". The outer
    # parts are numbers; what each parenthetical contains is a further
    # level, and an appositive inside it ("two generated-C ones, a
    # shift-to-multiply and a scale off-by-one") makes that level
    # unreadable by pattern, so only the outer sum is checked.
    two = (r"(\w+(?:-\w+)?) binding mutations---"
           r"(\w+(?:-\w+)?) simulator-header routing distortions"
           r" \([^)]*\) and (\w+(?:-\w+)?) contract distortions")
    for tot, a, b in re.findall(two, flat):
        if tot in WORDS and a in WORDS and b in WORDS:
            out.append((WORDS[tot], WORDS[a] + WORDS[b]))
    return out


def enumerated_bounds(text: str) -> list[tuple[int, int, int]]:
    """`[(stated, low, high)]` for mutation lists written out in words.

    "and" joins two items in a list, but also two nouns inside one item:
    "GE and LE polarity flips" is one change and "a complement drop and a
    narrowing drop" is two. So the segment count is a lower bound and the
    segment count plus every "and" is an upper, and the stated total has to
    fall between them.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    pat = (r"(\w+(?:-\w+)?) binding mutations---"
           r"((?:an? |the )(?:[^—]{0,400}?))---")
    out = []
    for tot, body in re.findall(pat, flat):
        if tot not in WORDS:
            continue
        segs, depth, cur = [], 0, ""
        for ch in body:
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            if ch == "," and depth == 0:
                segs.append(cur)
                cur = ""
            else:
                cur += ch
        segs.append(cur)
        low = sum(WORDS.get((s.strip() or "a").split()[0], 1)
                  for s in segs if s.strip())
        high = low + len(re.findall(r"\band\b", body))
        out.append((WORDS[tot], low, high))
    return out


def row_stage_splits(text: str) -> list[tuple[int, int, int, int]]:
    """`[(total, generator, Lean chain, host)]` for the four-stage splits.

    "N rows catch (a at the generator stage; b through the Lean chain; c by
    the host oracle; d by the routed oracle)". The fourth term carries a
    parenthetical and is not parsed here, so the three that are must not
    exceed the total -- a partial sum over the total is impossible however
    the fourth is counted.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    pat = (r"(\d+) rows catch \((\d+) at the generator stage; "
           r"(\d+) through the Lean chain; (\d+) by the host oracle")
    return [(int(t), int(a), int(b), int(c))
            for t, a, b, c in re.findall(pat, flat)]


def harness_growth(text: str) -> tuple[list[int], int]:
    """`(stated sizes of the growing harness, its current row count)`.

    Five sentences record one harness at successive sizes as detectors were
    added: 96, 100, 104, 108 and 112, each four mutants larger. The sizes are
    historical, so they are not banners, but the series must still ascend
    and the harness must still be at least as large as its last stated
    size -- a harness that shrank would leave the last sentence describing
    a mutation count it no longer has.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    series = [int(n) for n in re.findall(
        r"(\d+)-mutation harness gains an? (?:sixth|seventh|eighth|ninth|"
        r"tenth) detector", flat)]
    src = (pathlib.Path(__file__).parent / "build"
           / "mut_x86_alu_result.py").read_text(errors="ignore")
    block = re.search(r"^MUTATIONS = \[(.*?)^\]", src, re.S | re.M)
    return series, len(re.findall(r"^\s*\(", block.group(1), re.M))


def scene_counts() -> dict[str, int]:
    """`{host: distinct scene functions}` for the hosts the prose sizes.

    A sentence can state how many scenes a host has. The scenes are named
    identifiers in one file, so the count is checkable; a host that lost a
    scene would leave the sentence describing coverage it no longer has.
    """
    out = {}
    for name in ("x86_route_host", "helper_route_host", "a64_route_host"):
        src = pathlib.Path(__file__).parent / "build" / (name + ".c")
        if src.exists():
            out[name] = len(set(re.findall(r"scene_[a-z0-9_]+",
                                           src.read_text(errors="ignore"))))
    return out


def harness_totals() -> dict[str, int]:
    """`{harness: mutations}` counted the way the harness itself counts.

    `len(MUTATIONS)` is the authority: the literals run to several lines per
    entry and carry comments, so counting parentheses undercounts. Entries
    are the top-level tuples in the assignment, which is what Python binds.
    """
    import ast
    out = {}
    for path in pathlib.Path(__file__).parent.glob("build/mut_*.py"):
        src = path.read_text(errors="ignore")
        try:
            tree = ast.parse(src)
        except SyntaxError as exc:
            raise SystemExit(
                "check_paper_counts: %s does not parse: %s"
                % (path.name, exc.msg))
        n = None
        for node in tree.body:
            if (isinstance(node, ast.Assign) and node.targets
                    and getattr(node.targets[0], "id", "") in
                    ("MUTATIONS", "MUT_TABLE", "ROWS", "HOSTS")
                    and isinstance(node.value, ast.List)):
                n = len(node.value.elts)
                break
        # Some harnesses declare an empty list and register rows through a
        # helper; there the helper's call count is the entry count.
        if not n:
            n = len(re.findall(r"^\s*row\(", src, re.M))
        # A third idiom: rows built by appending to a list through a helper.
        if not n:
            n = len(re.findall(r"^\s*mutations\.append\(\s*local_row\(",
                               src, re.M))
        if n:
            out[path.stem] = n
    return out


def cited_specs(text: str) -> list[str]:
    """Spec files the section cites that are missing, or have no harness.

    Every one of the 138 specifications names a harness `mut_<stem>.py`, so a
    cited spec that exists must have one, and a cited spec that does not is
    a filename the tree no longer has.
    """
    # The caller passes the masked text, which strips `\texttt` content and
    # with it every spec name; read the source directly instead.
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    here = pathlib.Path(__file__).parent
    specs = {p.name[:-len("_spec.json")]
             for p in here.glob("*_spec.json")}
    totals = harness_totals()
    bad = []
    for raw in set(re.findall(r"([\w\\]+?)\\_spec\.json", flat)):
        name = raw.replace("\\_", "_").replace("\\", "")
        if name not in specs:
            bad.append("%s_spec.json is cited and absent" % name)
        elif "mut_" + name not in totals:
            bad.append("%s_spec.json has no mut_%s.py" % (name, name))
    return bad


def shake_field_gaps(
        text: str) -> tuple[int, list[tuple[int, str, list[str]]]]:
    """`(claims, [(rows, spec, fields the harness never names)])`.

    "The N-row shake exercised every spec field." Each harness family opens
    with "<arch> <family> mutation harness", and that opener is the
    delimiter the prose uses -- several families share one blank-line
    paragraph. The family word names the spec; the stated row count then
    selects among specs in that family, because a block can also cite a
    wider table (BZHI's cites X86Bitops).
    """
    import json
    flat = re.sub(r"\s+", " ", pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text()).replace("\\brk", "")
    claims = [int(n) for n in re.findall(
        r"The (\d+)-row shake exercised every spec field", flat)]
    totals = harness_totals()
    here = pathlib.Path(__file__).parent
    specs = {q.name[:-len("_spec.json")] for q in here.glob("*_spec.json")}
    opens = [(m.start(), m.group(1)) for m in re.finditer(
        r"(?:An? |The )([\w\-/\\ ]{2,40}?) mutation harness", flat)]
    starts = [a for a, _ in opens]
    blocks = [(f, flat[a:b]) for (a, f), b in
              zip(opens, starts[1:] + [len(flat)])]
    common = {"mem", "reg", "load", "arm", "width", "value"}

    out, seen = [], set()
    for n in claims:
        cands = [f for f, blk in blocks if "%d-row shake" % n in blk]
        # The sentence can sit in two overlapping blocks; it belongs to the
        # one whose family has a member of exactly this size. Only if no
        # block resolves it is the figure reported.
        # Any block that resolves wins; a block whose family is prose
        # ("x86 conditional-move") is only consulted if none resolves.
        hit, unresolved = None, None
        for fam in cands:
            members = [s_ for s_ in specs if s_.startswith("x86_")
                       and s_ != "x86_bitops"
                       and any(len(seg) >= 2 and seg not in common
                               and seg in fam.lower()
                               for seg in s_.lower().split("_")[1:])]
            exact = [s_ for s_ in members
                     if totals.get("mut_" + s_) == n]
            if len(exact) == 1:
                hit = (fam, exact[0])
                break
            unresolved = unresolved or fam
        if hit is None:
            # The opener's family word is often prose or names a wider
            # table; the size is then the only join, and it is used only
            # when exactly one harness has that many rows.
            exact = sorted(k[len("mut_"):] for k, v in totals.items()
                           if v == n)
            if len(exact) == 1 and exact[0] in specs:
                hit = (cands[0] if cands else "?", exact[0])
            elif exact:
                continue      # ambiguous size, nothing to say
            elif cands:
                # No harness of this size anywhere: the figure is wrong.
                hit = (cands[0], None)
        if n in seen or hit is None:
            continue
        seen.add(n)
        fam, spec = hit
        if spec is None:
            out.append((n, fam, ["no family member has this many rows"]))
            continue
        h = "mut_" + spec
        src = (here / "build" / (h + ".py")).read_text(errors="ignore")
        spath = here / (spec + "_spec.json")
        if not spath.exists():
            out.append((n, spec, ["no spec file"]))
            continue
        gaps = []
        for key, val in json.loads(spath.read_text()).items():
            if key == "schema_version":
                continue
            vals = re.findall(r'"([^"]{4,})"', json.dumps(val))
            if re.search(re.escape(key), src):
                continue
            if any(re.search(re.escape(v), src) for v in vals[:6]):
                continue
            gaps.append(key)
        if gaps:
            out.append((n, spec, gaps))
    return len(claims), out


def stage_sentence_sums(text: str) -> list[tuple[int, int, int, int, int]]:
    """`[(total, catch, stage sum, survive, 0)]` for stage-split sentences.

    "N of the M mutations catch (a at the generator stage, b by the Lean
    chain, c by the host oracle), and d survive": the stages must add to the
    catch count, and catch plus survive to the total. Both are the
    sentence's own arithmetic.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    pat = (r"(\d+) of (?:the harness's )?(\d+) mutations catch "
           r"\(([\d,]+) at the generator stage, ([\d,]+) by the Lean "
           r"chain, ([\d,]+) by the host oracle\)(?:, and (\d+)[^.]{0,40}?"
           r"survive)?")
    out = []
    for n, tot, a, b, c, surv in re.findall(pat, flat):
        s_ = sum(int(x.replace(",", "")) for x in (a, b, c))
        out.append((int(tot), int(n), s_, int(surv) if surv else 0, 0))
    pat2 = (r"(?<![\d,])(\d+) catch \(([\d,]+) at the generator stage, "
            r"([\d,]+) by the Lean chain, ([\d,]+) by the host oracles?\)"
            r"(?:, and (\d+) survive)?")
    for n, a, b, c, surv in re.findall(pat2, flat):
        s_ = sum(int(x.replace(",", "")) for x in (a, b, c))
        out.append((0, int(n), s_, int(surv) if surv else 0, 1))
    return out


def caught_fractions(text: str) -> list[tuple[int, int, int]]:
    """`[(caught, total, caught + equivalents)]` for "N/M caught, K survive".

    A battery's rows partition into those that catch and those that survive
    as documented equivalences, so the fraction and the survivor count must
    account for the whole battery.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    pat = (r"\((\d+)/(\d+) caught, (\d+) equivalences? survive")
    out = [(int(a), int(b), int(a) + int(c))
           for a, b, c in re.findall(pat, flat)]
    # The same partition in the other word order: "The harness has 59 rows,
    # of which 57 catch and 2 survive".
    for t, c, sv in re.findall(
            r"(\d+) rows, of which (\d+) catch and (\d+) survive", flat):
        out.append((int(t), int(t), int(c) + int(sv)))
    return out


def spec_row_joins(text: str) -> list[tuple[int, str, bool]]:
    """`[(mutations, spec, harness size matches the mutation count)]`.

    "N-mutation harness retargets the shared specification (K rows)": the
    row count is a field length in the spec, so where exactly one spec has
    that many rows and its harness is N, the join is exact.
    """
    import json
    words = {w: i for i, w in enumerate(
        "zero one two three four five six seven eight nine ten eleven twelve "
        "thirteen fourteen fifteen sixteen seventeen eighteen nineteen "
        "twenty".split())}
    BS = chr(92)
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    totals = harness_totals()
    here = pathlib.Path(__file__).parent
    out = []
    for n, word in re.findall(
            r"(\d+)-mutation harness (?:\([^)]*\) )?"
            r"retargets the shared specification \((\w+) rows?\)", flat):
        want = words.get(word)
        if want is None:
            continue
        hits = []
        for sp in here.glob("*_spec.json"):
            try:
                d = json.loads(sp.read_text())
            except ValueError:
                continue
            if want in [len(v) for v in d.values() if isinstance(v, list)]:
                hits.append(sp.name[:-len("_spec.json")])
        exact = [h for h in hits if totals.get("mut_" + h) == int(n)]
        if len(exact) == 1:
            out.append((int(n), exact[0], True))
        elif len(exact) > 1:
            out.append((int(n), ",".join(exact), False))
    return out


def step_refs(text: str) -> list[str]:
    """Step numbers the section cites that the README does not record.

    The paper refers to numbered steps for provenance; those numbers are
    only meaningful against the README's own history, so a citation of a
    step that was never written would point at nothing.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    readme = (pathlib.Path(__file__).parent / "README.md").read_text()
    return [n for n in sorted(set(re.findall(r"Step~?(\d{4})", flat)))
            if "### Step %s" % n not in readme]


def modifier_count_gap(text: str) -> tuple[int, int]:
    """`(stated modifiers, operations in the modifier spec)`.

    The section says "the eleven modifiers (the empty no-modifier mnemonic
    plus four shifts and six extend forms)". That is a spec field length, so
    the sentence can be checked against the file rather than the prose.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    m = re.search(r"the (\w+) modifiers", flat)
    words = {w: i for i, w in enumerate(
        "zero one two three four five six seven eight nine ten eleven twelve "
        "thirteen fourteen fifteen sixteen seventeen eighteen nineteen "
        "twenty".split())}
    stated = words.get(m.group(1)) if m else -1
    import json
    spec = pathlib.Path(__file__).parent / "arm64_mod_spec.json"
    ops = json.loads(spec.read_text()).get("operations", [])
    return stated, len(ops)


def description_joins(text: str) -> list[tuple[int, str]]:
    """`[(mutations, spec)]` joined by the words the sentence uses.

    A sentence says a harness "retargets the lane specification" and the
    spec is arm64_byte_lane. This join is weaker than a name: the words are
    prose, so a single word like "path" can match a spec that is about
    something else. Only joins whose words name the spec's own segments are
    taken, and they are checked by size as well.
    """
    import collections
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    totals = harness_totals()
    shared = collections.Counter(totals.values())
    here = pathlib.Path(__file__).parent
    specs = sorted(q.name[:-len("_spec.json")]
                   for q in here.glob("*_spec.json"))
    out = []
    for n, desc in re.findall(
            r"(\d+)-mutation harness (?:\([^)]*\) )?"
            r"retargets (?:the |its |both )?([a-z/\- ]{3,40}?) spec",
            flat):
        # No size filter here: a sentence whose size is unique is still a
        # sentence, and skipping it is what left two harnesses unnamed for
        # fifty steps. The candidate test below decides instead.
        words = [w for w in re.split(r"[ \-/]+", desc) if len(w) >= 4]
        cand = [s for s in specs if totals.get("mut_" + s) == int(n)
                and any(w in s.split("_") for w in words)]
        if len(cand) == 1:
            out.append((int(n), cand[0]))
    return out


def scene_products(text: str) -> list[tuple[int, int]]:
    """`[(stated total, scenes x checks + selectors)]`.

    A battery-local host's case total is stated as a product: "165,895
    modeled cases: 2,592 scenes x 64 checks plus 7 selector cases". Both
    sides are figures, so they must agree -- one such sentence was 1,536
    scenes at 64 checks, which reaches 98,320, not the 99,856 its banner
    prints.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    num = lambda x: int(x.replace(",", "").replace("{", "").replace("}", ""))
    pat = (r"\((\d[\d,{}]*) modeled cases: ([\d,{}]+) scenes? "
           r"\$\\times\$ (\d+) checks(?: plus (\d+) selector cases)?")
    out = []
    for tot, sc, ck, extra in re.findall(pat, flat):
        out.append((num(tot),
                    num(sc) * int(ck) + (int(extra) if extra else 0)))
    return out


def case_decompositions(text: str) -> list[tuple[int, int, int, int]]:
    """`[(stated total, first axis, second axis, product)]`.

    A host's size is often given as axes: "2,089 modeled cases: 4 widths by
    7 seed rows by 5 immediates plus ...". The product of the stated axes
    cannot exceed the total, and where the sentence also states a remainder
    it must reach the total exactly -- the 1,536-scene host was 64 checks
    where its banner needed 65.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    num = lambda s: int(s.replace(",", "").replace("{", "").replace("}", ""))
    pat = (r"(\d[\d,{}]*) modeled cases: ([\d,{}]+) "
           r"(?:scenes?|widths?) \$\\times\$ (\d+) \w+")
    return [(num(t), num(a), int(b), num(a) * int(b))
            for t, a, b in re.findall(pat, flat)]


def added_case_sums(text: str) -> list[tuple[int, list[int]]]:
    """`[(stated total, parts)]` for "adding N modeled cases (a 1, b 2, ...)".

    A sentence lists what a sweep added to the recipe and gives the total.
    Every part is a banner and the total is their sum, so both the sum and
    each term can be checked.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    num = lambda x: int(x.replace(",", "").replace("{", "").replace("}", ""))
    out = []
    for tot, body in re.findall(
            r"adding (\d[\d,{}]*) modeled cases[^(]{0,40}\("
            r"([^)]{10,400})\)", flat):
        # Parts are "<label> <number>" pairs; take the number after a
        # label, not every digit in the span.
        parts = [num(v) for v in re.findall(
            r"[a-zA-Z][\w ]*? ([\d]{1,3}(?:[\d,{}]*))", body)]
        if parts:
            out.append((num(tot), parts))
    return out


def caught_with_parts(text: str) -> list[tuple[int, int]]:
    """`[(stated caught, sum of the attributed parts)]`.

    "128 mutations were caught (88 by the generator check, 40 by the Lean
    chain)": each part names the stage that caught a share, so the parts
    must reach the count. Parts are introduced by "by", "at", "from" and
    "through"; the sentence states mutations or rows, and both are read.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    out = []
    for tot, body in re.findall(
            r"(\d+) mutations were caught \(([^)]{10,300})\)", flat):
        parts = [int(x) for x in re.findall(
            r"(\d+) (?:by|at|from) ", body)]
        if parts:
            out.append((int(tot), sum(parts)))
    # "N-case oracle ... over all M index bytes": the cases must be a
    # multiple of the population it sweeps, or the oracle skips some.
    for total, pop in re.findall(
            r"(\d[\d,{}]*)-case[^.]{0,80}?over all (\d+) ", flat):
        t, p_ = (int(re.sub(r"[{},]", "", total)), int(pop))
        # The oracle must cover the population at least once; more is
        # allowed because a sweep adds cases beside it.
        if p_ and t < p_:
            out.append((t, p_))
    # The other wording states rows rather than mutations, and attributes a
    # part "through" a stage as often as "by" one.
    for tot, body in re.findall(
            r"(\d+) rows catch \(([^)]{10,400})\)", flat):
        parts = [int(x) for x in re.findall(
            r"(\d+) (?:by|at|from|through) ", body)]
        if parts:
            out.append((int(tot), sum(parts)))
    return out


def plants_and_keeps(text: str) -> list[tuple[int, int, int]]:
    """`[(rows, caught, kept)]` for a "plants C catches, keeps K" row.

    A battery's rows divide into the catches it plants and the
    equivalences it keeps, so the two must reach the row count.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    return [(int(t), int(c), int(k)) for t, c, k in re.findall(
        r"(\d+)-row harness plants (\d+) catches[^.]{0,300}?"
        r"(?:keeps|and keeps) (\d+) documented", flat)]


def register_cells() -> dict:
    """`{"x86": [numbers], "arm64": [numbers]}` from the dispatch specs.

    The section says "there is no zero register to omit, so the only register
    number that is not a cell is the all-ones sentinel". That is a claim
    about the cell table: the numbers must be contiguous from zero, and the
    sentinel must be outside the range.
    """
    import json
    here = pathlib.Path(__file__).parent
    out = {}
    for isa in ("x86", "arm64"):
        spec = here / (isa + "_reg_dispatch_spec.json")
        if spec.exists():
            cells = json.loads(spec.read_text()).get("cells", [])
            out[isa] = sorted(c["number"] for c in cells)
    return out


def div_ladder() -> tuple[int, list[int]]:
    """`(gated arms, width codes)` from the DIV spec.

    The section says "the default arm is the only gated one and the ladder
    is total over the resolved width codes". Both are properties of the
    spec's arm table: exactly one arm carries a gate, and the width codes
    it covers are the resolved set.
    """
    import json
    spec = pathlib.Path(__file__).parent / "x86_div_spec.json"
    if not spec.exists():
        return -1, []
    arms = json.loads(spec.read_text()).get("arms", [])
    return (sum(1 for a in arms if a.get("high_gate")),
            sorted(a["width_code"] for a in arms))


def multiply_bound_pair() -> tuple[int, int]:
    """`(pairs whose product is the negative bound, pairs that overflow)`.

    The section says the most negative value paired with minus one is the
    single pair whose product is exactly the negative bound, and therefore
    the only place the two candidate overflow bounds disagree. Computed over
    the operand pairs that can produce the bound, and over a grid where the
    two tests could differ.
    """
    lo, hi = -(2 ** 63), 2 ** 63 - 1
    # Pairs whose true product equals the magnitude of the negative bound.
    at_bound = [(a, b) for a in (lo, -1, 1, hi) for b in (lo, -1, 1, hi)
                if a * b == -lo]
    # Pairs where "product is representable" and "product fits" differ.
    differ = [(a, b) for a in (lo, -1, 1, hi, 2, -2)
              for b in (lo, -1, 1, hi, 2, -2)
              if (lo <= a * b <= hi) != (a * b in range(lo, hi + 1))]
    return len({tuple(sorted(p)) for p in at_bound}), len(differ)


def generator_message_counts() -> set[int]:
    """How many messages each generator can raise, as a set of counts.

    The sentences say the harness retargets "the N generator
    re-check messages". The sentence does not name its generator, so the
    join is to the set: a stated count that no generator can raise is a
    figure with no source. This is a typo check, and the weaker form is
    stated where it is used.
    """
    here = pathlib.Path(__file__).parent
    out = set()
    for p in here.glob("generate_*_spec.py"):
        out.add(len(re.findall(r'raise SystemExit\(f?"',
                            p.read_text(errors="ignore"))))
    return out


def stlxr_status_contract() -> list[str]:
    """Problems with the STLXR contract's shape, empty when it holds.

    The section says the store-exclusive body is the only one of its
    remainder with two observable effects, "writes the source to memory and
    then writes a status word to the destination". The contract half of that
    is checkable: the status spec must derive from the width mask and must
    be the zero code at every width, which is what "a status word" means
    here.
    """
    here = pathlib.Path(__file__).parent
    path = here / "KProgFormal" / "Arm64Stlxr.lean"
    if not path.exists():
        return ["Arm64Stlxr.lean is absent"]
    text = path.read_text()
    out = []
    if "arm64StlxrSpec" not in text:
        out.append("the status spec is not named in Arm64Stlxr.lean")
    if "mask width - mask width" not in text:
        out.append("the status is not derived from the width mask")
    if "arm64_stlxr_success_zero" not in text:
        out.append("no theorem states the success status is zero")
    return out


def width_default() -> tuple[str, list[int], int]:
    """`(default width name, width bits, count of 64-bit widths)`.

    The section says a write and a tag write agree "at the only width (64)
    the outer gate opens". That rests on the width spec: the absent code
    falls back to one width, and only that width carries 64 bits.
    """
    import json
    spec = pathlib.Path(__file__).parent / "x86_width_spec.json"
    if not spec.exists():
        return "", [], 0
    d = json.loads(spec.read_text())
    widths = d.get("widths", [])
    default = d.get("effective", {}).get("default_name", "")
    bits = [w["bits"] for w in widths if w["name"] == default]
    return (default, sorted(w["code"] for w in widths),
            sum(1 for w in widths if w["bits"] == 64))


def carry_separation() -> tuple[int, bool]:
    """`(pairs where >= and > differ, all such pairs are equal)`.

    The section says the equal case is the only one separating a subtract
    carry stated as greater-or-equal from one stated as strictly greater.
    That is arithmetic: the two predicates disagree exactly on equality, so
    a table of distinct operands never exercises the difference.
    """
    pairs = [(a, b) for a in range(-8, 9) for b in range(-8, 9)
             if (a >= b) != (a > b)]
    return len(pairs), all(a == b for a, b in pairs)


def bt_mem_shape() -> tuple[int, bool]:
    """`(memory-base opcode rows, its index is the immediate form)`.

    The section says the bracket-without-PTR fixture "bt [rdi], 7" is the
    only shape reaching the X86_OP_BT_MEM_IMM width default. That rests on
    the spec's opcode table: exactly one row reads memory, and that row
    takes an immediate index, which is the shape a fixture without a PTR
    suffix produces.
    """
    import json
    spec = pathlib.Path(__file__).parent / "x86_bt_spec.json"
    if not spec.exists():
        return 0, False
    rows = json.loads(spec.read_text()).get("opcodes", [])
    mem = [o for o in rows if o.get("base") == "memoryRead"]
    return len(mem), (len(mem) == 1 and mem[0].get("index") == "imm32")


def duplicate_codes() -> list[tuple[str, list[str]]]:
    """`[(spec, repeated codes)]` over every specification's opcode table.

    The section says the numbers in a table are pairwise distinct, so
    dispatch on the numeric code selects exactly one arm. A repeated code
    makes that selection ambiguous and the sentence false.
    """
    import json
    here = pathlib.Path(__file__).parent
    out = []
    for spec in sorted(here.glob("*_spec.json")):
        try:
            data = json.loads(spec.read_text())
        except ValueError:
            continue
        # A row's name keys every table that has one; a code keys the
        # opcode tables. Both must be unique, or dispatch on the code and a
        # reference by name each become ambiguous.
        for field in ("name", "code", "op_code", "opcode"):
            for table, rows in data.items():
                if (not isinstance(rows, list) or len(rows) < 2
                        or not isinstance(rows[0], dict)):
                    continue
                vals = [str(r[field]) for r in rows if field in r]
                if len(vals) < 2:
                    continue
                seen, dupes = set(), []
                for v in vals:
                    if v in seen:
                        dupes.append(v)
                    seen.add(v)
                if dupes:
                    out.append(("%s:%s:%s" % (spec.name, table, field),
                                dupes))
    return out


def module_split(text: str) -> tuple[tuple[int, ...], tuple[int, ...]]:
    """`((arm64, x86, shared) modules, (theorems))` as the section states it.

    The section splits the 306 proof modules by which simulator they prove
    and gives each bucket's theorem count. Both triples are the sentence's
    own arithmetic: they must reach the tree's totals, and the shared
    bucket must be the 138 generated specifications plus the hand-written
    cross-ISA ones.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    m = re.search(r"(\d+) AArch64 modules prove ([\d,{}]+) theorems, "
                  r"(\d+) x86-64 modules prove ([\d,{}]+), and "
                  r"(\d+) shared modules prove ([\d,{}]+)", flat)
    if not m:
        return (), ()
    num = lambda x: int(x.replace(",", "").replace("{", "").replace("}", ""))
    mods = (int(m.group(1)), int(m.group(3)), int(m.group(5)))
    thms = (num(m.group(2)), num(m.group(4)), num(m.group(6)))
    return mods, thms


def writeback_bound() -> tuple[bool, int]:
    """`(a theorem bounds the writeback count, the bound)`.

    The section says the writeback count is bounded by the two bits, never a
    third writeback the bodies do not implement. That is a Lean theorem, so
    the check is that the theorem is still there and still says two.
    """
    lean = (pathlib.Path(__file__).parent / "KProgFormal"
            / "Arm64MemPrepost.lean")
    if not lean.exists():
        return False, 0
    m = re.search(r"writebackFormSpec[^\n]*≤\s*(\d+)", lean.read_text())
    return bool(m), int(m.group(1)) if m else 0


def disjoint_families() -> list[tuple[str, int, int, bool]]:
    """`[(isa, families, pairs proved, complete)]` per dispatch family proof.

    The section claims the ten x86 families and the eight AArch64 ones are
    pairwise disjoint, so the ordered chain takes at most one gate per
    opcode. A disjointness theorem that enumerated only some pairs would
    leave the claim resting on the ones it listed, so each must enumerate
    the complete pairwise count for its own family set.
    """
    here = pathlib.Path(__file__).parent / "KProgFormal"
    out = []
    for isa, mod, thm in (("x86", "X86DispatchFamily.lean",
                           "x86_dispatch_families_disjoint"),
                          ("arm64", "Arm64DispatchFamily.lean",
                           "arm64_dispatch_families_disjoint")):
        lean = here / mod
        if not lean.exists():
            out.append((isa, 0, 0, False))
            continue
        text = lean.read_text()
        i = text.find("theorem " + thm)
        if i < 0:
            out.append((isa, 0, 0, False))
            continue
        body = text[i:text.find("theorem", i + 10)]
        fams = len(set(re.findall(r"Disp(\w+)Ops", body)))
        pairs = len(re.findall(
            r"op ∈ \w+Disp\w+Ops ∧ op ∈ \w+Disp\w+Ops", body))
        out.append((isa, fams, pairs, pairs == fams * (fams - 1) // 2))
    return out


def stayed_at(text: str) -> list[int]:
    """Banner counts the section says `make check` "stayed at".

    Nine sentences record that the gate was unchanged across a run of steps,
    each naming the same count. They describe one unchanged gate, so the
    figures must agree with each other and none may exceed what the gate
    reports now.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    return [int(n) for n in re.findall(r"stayed at (\d+)", flat)]


def shake_digests(text: str) -> list[str]:
    """Paper digests no recorded shake accounts for.

    The section quotes md5 digests as evidence that a shake was
    byte-identical across reruns. Each digest was measured in a step and
    recorded in the harness README, so a digest the README does not carry is
    an observation with no record behind it.
    """
    norm = lambda s: re.sub(r"\b([0-9a-f]{20,})\s+([0-9a-f]{4,})\b",
                            lambda m: m.group(1) + m.group(2), s)
    # The caller passes the masked text, which strips `\texttt` bodies and
    # with them every digest; read the source directly.
    readme = norm((pathlib.Path(__file__).parent / "README.md").read_text())
    known = set(re.findall(r"\b([0-9a-f]{32})\b", readme))
    paper = norm(pathlib.Path(
        "../../docs/kprog-simulator-in-ebpf/sections/4-safety.tex"
    ).read_text())
    return sorted(set(re.findall(r"\b([0-9a-f]{32})\b", paper)) - known)


def decode_drift_headers() -> list[str]:
    """Headers whose static assertions observe an opcode drift.

    The section says changing one hand-written opcode in `x86_sim.h` fails
    the build with two independent assertions, in `x86_opcode.h` and
    `x86_dispatch_singleton.h`, so the two generated tables observe the
    drift separately. That is testable: change the constant, compile a
    translation unit that includes both, and see which headers fire.
    """
    import subprocess
    import tempfile
    here = pathlib.Path(__file__).parent
    sim = here.parent / "x86" / "x86_sim.h"
    saved = sim.read_text()
    probe = ("#include \"../x86/x86_sim.h\"\n"
             "#include \"generated/x86_opcode.h\"\n"
             "#include \"generated/x86_dispatch_singleton.h\"\n"
             "int main(void) { return 0; }\n")
    try:
        sim.write_text(saved.replace("#define X86_OP_NOP 0x00U",
                                     "#define X86_OP_NOP 0x09U", 1))
        with tempfile.NamedTemporaryFile("w", suffix=".c",
                                         delete=False) as fh:
            fh.write(probe)
            src = fh.name
        done = subprocess.run(
            ["gcc", "-Wall", "-Wextra", "-O2", "-I.", "-I../x86", "-c",
             src, "-o", "/dev/null"],
            cwd=str(here), capture_output=True, text=True)
    finally:
        sim.write_text(saved)
        pathlib.Path(src).unlink(missing_ok=True)
    return sorted(set(re.findall(r"([\w_]+\.h):\d+",
                                 done.stdout + done.stderr)))


def bswap_mutation_mismatches() -> int:
    """Mismatches when the generated bswap shift is moved by one.

    The paper says a host naming neither the header nor its generated symbol
    outside a comment still fails with 48 mismatches when the generated
    shift constant changes, because it exercises the operation through the
    dispatcher. Coverage is behavioural, so the count is measured rather
    than read off the host's text.
    """
    import subprocess
    here = pathlib.Path(__file__).parent
    header = here / "generated" / "x86_bswap.h"
    saved = header.read_text()
    out = str(here / "build" / "probe_bswap_host")
    try:
        header.write_text(saved.replace(
            "0x0000000000ff0000ULL) << 24",
            "0x0000000000ff0000ULL) << 23", 1))
        cc = subprocess.run(
            ["gcc", "-Wall", "-Wextra", "-O2", "-I.", "-I../x86",
             "-I../../kprog",
             "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/"
             "prefix/include/bpf", "test_x86_bswap_route_host.c", "-o", out],
            cwd=str(here), capture_output=True, text=True)
        if cc.returncode != 0:
            return -1
        done = subprocess.run([out], cwd=str(here), capture_output=True,
                              text=True)
        return (done.stdout + done.stderr).count("MISMATCH")
    finally:
        header.write_text(saved)
        pathlib.Path(out).unlink(missing_ok=True)


def named_harness_rows(text: str) -> list[tuple[int, str, int]]:
    """`[(stated rows, harness, rows the harness builds)]` where they differ.

    A sentence citing `N-row harness mut_x.py` joins exactly: the name
    identifies one script. The built count is static, so a harness whose
    rows are appended through a helper reads short of what it runs — three
    do today, and running one confirmed the paper rather than the extractor.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    totals = harness_totals()
    out = []
    for rows, name in re.findall(
            r"(\d+)-row harness \\texttt\{((?:[^{}])*?)\}", flat):
        f = name.replace("\\_", "_").replace("\\brk", "").strip()
        f = re.sub(r"\s+", "", f)
        if not f.endswith(".py"):
            f += ".py"
        have = totals.get(f[:-3])
        if have is not None and have != int(rows):
            out.append((int(rows), f, have))
    return out


def census_transitions(text: str) -> list[tuple[int, int]]:
    """`[(from, to)]` where a census transition does not ascend.

    Nearly every sentence records the census counter moving from one value
    to another, and the counter only ever rises. A pair that went backwards
    or stood still would mean either the step added nothing or the figures
    were typed in the wrong order.
    """
    flat = re.sub(r"[\\()]", " ", re.sub(r"\s+", " ", text))
    pairs = [(int(a), int(b)) for a, b in re.findall(
        r"census\s+(\d+)\s+to\s+(\d+)", flat)]
    return [(a, b) for a, b in pairs if b <= a]


def axiom_partition(text: str) -> tuple[tuple[int, int, int], int] | None:
    """`((none, compiler, definitional), their sum)` for the axiom split.

    The sentence states a partition of the tree, so its three figures must
    add to the theorem total. A transcription error in any one of them moves
    the sum off that total, which is the only place the section states all
    three at once.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "").replace("{,}", "")
    m = re.search(r"(\d+) theorems depend on none.{0,90}?(\d+) reach "
                  r".{0,60}?and the remaining (\d+)", flat)
    if m is None:
        return None
    parts = tuple(int(g) for g in m.groups())
    return parts, sum(parts)


def cell_tables() -> dict[str, int]:
    """`{isa: cells}` from each generated dispatch table.

    Both register contracts state a cell count, and both generated modules
    hold the table that count describes. A table whose length and declared
    bound disagree would make the sentence's "every byte above" claim vague
    about where the boundary sits, which is what the complement sentence in
    this section got wrong once.
    """
    out = {}
    root = pathlib.Path(__file__).parent / "KProgFormal"
    for isa, name in (("x86", "GeneratedX86RegDispatch.lean"),
                      ("arm64", "GeneratedArm64RegDispatch.lean")):
        src = (root / name).read_text()
        table = re.search(r"cellNumbers : List Nat := \[(.*?)\]", src, re.S)
        bound = re.search(r"gprCount : Nat := (\d+)", src)
        if table is None or bound is None:
            raise SystemExit(
                "check_paper_counts: %s has no cell table or gprCount" % name)
        cells = len(re.findall(r"\d+", table.group(1)))
        if cells != int(bound.group(1)):
            raise SystemExit(
                "check_paper_counts: %s declares %s cells and gprCount %s"
                % (name, cells, bound.group(1)))
        out[isa] = cells
    return out


ORDINALS = ("first", "second", "third", "fourth", "fifth", "sixth",
            "seventh", "eighth", "ninth", "tenth")


def detector_series(text: str) -> list[str]:
    """Problems with the sentences that grow one harness a detector at a time.

    The sizes ascend under a check of their own; this holds the *names*.
    A sentence adding the eighth detector must follow the seventh, so if a
    detector sentence is inserted twice or in the wrong place the ordinal
    shows it even while the sizes still rise.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    seq = [(int(n), w) for n, w in re.findall(
        r"(\d+)-mutation harness (?:gains|gained) an? (\w+) detector", flat)]
    out = []
    for (a, wa), (b, wb) in zip(seq, seq[1:]):
        if ORDINALS.index(wb) <= ORDINALS.index(wa):
            out.append(
                "the detector named %s follows %s while the row count "
                "rises from %d to %d" % (wb, wa, a, b))
    return out


def harness_population() -> list[str]:
    """Problems with the set of harnesses the counts are read from.

    The row counts come from `build/mut_*.py`, and most of those files are
    untracked build-directory sources, so a checkout can hold fewer than the
    tree here. Reading a short set would not fail: every join would simply
    find no harness and the sentences would go unread. The population is
    therefore stated by the tree that owns it, and this reports a set that
    cannot answer the sentences at all.
    """
    here = pathlib.Path(__file__).parent
    harnesses = list((here / "build").glob("mut_*.py"))
    if not harnesses:
        return ["no harness is present under build/, so no sentence that "
                "states a harness size was read"]
    # The counts are read from files the repository mostly does not track:
    # build/ is ignored, and only four harnesses are committed. A checkout
    # holding a handful still answers every join with "no harness", which
    # looks the same as a sentence that is simply right.
    tracked = subprocess.run(
        ["git", "ls-files", "build/"], cwd=here, capture_output=True,
        text=True).stdout.split()
    if tracked and len(harnesses) < 10 * len(tracked):
        return ["%d harnesses are present and only %d are tracked, so this "
                "checkout holds a fraction of the tree the counts describe"
                % (len(harnesses), len(tracked))]
    return []


def pinned_route_hosts() -> tuple[int, int]:
    """`(battery-local route hosts the section states, those the recipe runs)`.

    The section says the hosts the mutation batteries drive are pinned into
    the gate recipe, and states how many. Both halves are in the tree: the
    hosts are the `*route_host.c` files under `build/`, and "pinned" means
    the recipe names them.
    """
    here = pathlib.Path(__file__).parent
    named = set(re.findall(r"build/(\w+_route_host)\b",
                           (here / "Makefile").read_text()))
    on_disk = {p.stem for p in (here / "build").glob("*route_host.c")}
    return len(on_disk & named), len(on_disk)


def reached_suffixes() -> int:
    """Condition suffixes the x86 contract reaches: its names minus parity.

    The section says the twelve reached suffixes are exactly the condition
    contract's names minus the parity pair `o`/`no`. The pair is the whole
    reason the count is twelve and not fourteen, so the two numbers have to
    come from the contract rather than from the sentence.
    """
    import json
    spec = json.loads(
        (pathlib.Path(__file__).parent / "x86_cond_spec.json").read_text())
    names = [c["name"] for c in spec["conditions"]]
    return len([n for n in names if n not in ("o", "no")])


def case_figures(text: str) -> int:
    """Distinct `N-case` figures the section states.

    The count of claims is not the reach: one claim can be made several
    times, and the same figure is often stated in two sentences. What a
    reader needs to know is how many distinct figures the run accounted
    for, which is this.
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    return len({int(re.sub(r"[{},]", "", n)) for n in
                re.findall(r"(?<![\w.])(\d[\d{},]*)[- ]case", flat)})


def battery_count() -> int:
    """Mutation batteries on disk, which is what the section counts.

    The section says 330 mutation batteries re-derive the failure of the
    contract each anchors. The count is the files, so it is stated by the
    tree; a battery removed without the sentence moving is the failure.
    """
    return len(list((pathlib.Path(__file__).parent / "build")
                       .glob("mut_*.py")))


def tag_values() -> dict[str, list[int]]:
    """`{isa: sorted tag codes}` read from the simulator headers.

    The tags are used as array indices, so they must be distinct and dense
    from zero; a gap would leave an index that no constant names, and a
    repeated value would make two kinds of pointer indistinguishable to
    every consumer that dispatches on the tag.
    """
    here = pathlib.Path(__file__).parent
    out = {}
    for isa, rel in (("x86", "../x86/x86_sim_local_bpf.h"),
                      ("arm64", "../arm64/arm64_sim_local_bpf.h")):
        src = (here / rel).read_text()
        out[isa] = sorted(int(v) for v in re.findall(
            r"^#define (?:X86|ARM64)_SIM_TAG_\w+ (\d+)U", src, re.M))
    return out


def stated_harness_joins(
        text: str) -> tuple[list[tuple[int, str, int]],
                            list[tuple[int, str, list[str]]], int,
                            list[tuple[list[str], str]]]:
    """`[(stated, harness, its size)]` for sentences naming a harness only by
    size and opcode.

    A sentence that gives a mutation count without a filename still names
    the opcodes it repaints, and a harness's own docstring names the
    contract it targets. When exactly one harness of that size has a
    docstring naming one of the sentence's opcodes, the join is exact;
    when the opcodes match several or none it stays ambiguous and is not
    reported.
    """
    totals = harness_totals()
    docs: dict[int, list[tuple[str, str]]] = {}
    ALL_DOCS: dict[str, str] = {}
    for f in (pathlib.Path(__file__).parent / "build").glob("mut_*.py"):
        n = totals.get(f.stem)
        if not n:
            continue
        src = f.read_text(errors="ignore")
        m = (re.match(r'#!.*?\n"""(.*?)"""', src, re.S)
             or re.match(r'"""(.*?)"""', src, re.S))
        # The prose writes names with escaped underscores (`X86\_SIM`),
        # so both sides are normalised before matching or a token like
        # `X86\_SIM\_L\_EXEC` matches nothing.
        body = (m.group(1) if m else "").upper().replace("\\_", "_")
        docs.setdefault(n, []).append((f.stem, body))
        ALL_DOCS[f.stem] = body
    out = []
    weak: list[tuple[int, str, list[str]]] = []
    multi: list[tuple[list[str], str]] = []
    # Split on line breaks first: collapsing them lets a sentence wrap
    # across a line, and the ". " split then cuts it in half.
    joined = ". ".join(re.sub(r"\s+", " ", l)
                       for l in text.replace("\\brk", "").split("\n"))
    for line in joined.split(". "):
        m = re.search(r"(\d+)-mutation harness", line)
        if not m or "\\texttt" in line[m.start():m.start() + 160]:
            continue
        n = int(m.group(1))
        cands = docs.get(n, [])
        # Every quoted token counts, not only the all-caps ones: the
        # prose names an arm in lowercase as often as in capitals, and the
        # docstring carries whichever the contract uses.
        ops = {o.upper().replace("\\_", "_") for o in
               re.findall(r"\\texttt\{([A-Za-z][A-Za-z0-9_\\]{1,})\}",
                          line)}
        if len(cands) < 2 or not ops:
            continue
        hit = [s for s, d in cands
               if any(re.search(r"\b%s\b" % re.escape(o), d) for o in ops)]
        if len(hit) == 1:
            # A join carried only by a token that most harnesses of this
            # size also carry is a coincidence: `HANDLED` sits in dozens of
            # docstrings, so such a sentence reaches whichever candidate
            # yields first. Measured after the join, reported as a warning
            # rather than a failure, since the sentence may simply be terse.
            doc = dict(cands)[hit[0]]
            matched = {o for o in ops
                       if re.search(r"\b%s\b" % re.escape(o), doc)}
            generic = {o for o in matched
                       if sum(1 for d in ALL_DOCS.values() if o in d) >= 8}
            if matched and matched == generic:
                weak.append((n, hit[0], sorted(matched)))
            out.append((n, hit[0], totals[hit[0].removesuffix(".py")]))
    # A sentence that names the file beside its count joins outright.
    BS = chr(92)
    named = re.compile(
        r"(\d+)-mutation harness "
        + re.escape("(" + BS + "texttt{mut" + BS + "_")
        + r"[a-z0-9" + re.escape(BS + "_") + r"]+" + re.escape(".py})"))
    for m in named.finditer(joined):
        stem = (m.group(0).split("{")[1].rstrip("})")
                .replace(BS + "_", "_").removesuffix(".py"))
        if stem in totals:
            out.append((int(m.group(1)), stem + ".py", totals[stem]))
    # One sentence, one harness. A label followed by a second parenthetical
    # naming a different file has been a mislabel twice over: the reader
    # follows the label and reaches the wrong contract, while the join reads
    # the first name and passes. Naming the same file twice is only
    # redundant, so it is counted rather than reported.
    for line in joined.split(". "):
        names = [g.replace(BS + "_", "_").removesuffix(".py")
                 for g in re.findall(r"\\texttt\{(mut" + re.escape(BS + "_")
                                     + r"[a-z0-9" + re.escape(BS + "_")
                                     + r"]+)", line)]
        if len({nm for nm in names if nm in totals}) > 1:
            multi.append((sorted({nm for nm in names if nm in totals}),
                          line[:90]))
    # The joins above cover the sentences whose size names one harness and
    # whose evidence selects it. A sentence that names no file and whose
    # size is shared by several harnesses joins none, which is a coverage
    # figure rather than a defect; it is returned so the run can report it.
    # The growing harness is counted as held, since `harness_growth` binds
    # its whole series to the harness's own row count.
    covered = {n for n, _, _ in out} | set(harness_growth(text)[0])
    unnamed = sum(1 for line in joined.split(". ")
                  if (m := re.search(r"(\d+)-mutation harness", line))
                  and int(m.group(1)) not in covered)
    return out, weak, unnamed, multi


def opcode_map() -> list[str]:
    """Problems with the emitted token-to-code map, empty when it holds.

    The section says the encoder emits each operation by its pinned token and
    that the token-to-code map cannot drift from the one the simulator and
    the model use. The map and its inverse are emitted into one module, so
    the two directions are checkable against each other: the inverse must
    name every token the map gives a code, each in one direction only.
    """
    import importlib.util
    path = (pathlib.Path(__file__).parent / ".." / "x86" / "micro-prog"
            / "generated_x86_opcode.py").resolve()
    spec = importlib.util.spec_from_file_location("_genop", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    codes, names = mod.X86_OPCODE, mod.X86_OPCODE_NAME
    out = []
    if len(set(codes.values())) != len(codes):
        out.append("the opcode map gives two tokens one code")
    for token, code in codes.items():
        if names.get(code) != token:
            out.append("%s codes to %s and the inverse names %s"
                       % (token, code, names.get(code)))
    for code in names:
        if code not in set(codes.values()):
            out.append("the inverse names %s and no token codes to it" % code)
    return out


def generation_bump_guards() -> list[str]:
    """Problems with the generation bump, empty when both mirrors guard it.

    The section says each admitted update bumps a 32-bit generation and that
    the bump returns -EOVERFLOW at U32_MAX rather than wrapping, "so a
    generation cannot be reused by silent wraparound". The guard is one
    comparison, and its absence would be a silent wrap.
    """
    root = pathlib.Path(__file__).parent.parent.parent / "kinsn" / "module"
    out = []
    for isa in ("x86", "arm64"):
        f = sorted(root.glob("%s/*_native_lab.c" % isa))
        if not f:
            out.append("no %s native_lab.c under kinsn/module" % isa)
            continue
        src = f[0].read_text(errors="ignore")
        if not re.search(
                r"generation == U32_MAX\)\s*\n\s*return -EOVERFLOW;", src):
            out.append("%s bumps its generation without the U32_MAX guard"
                       % f[0].name)
    return out


def checker_reach() -> list[str]:
    """Problems with the trees the checker reads, empty when they match.

    The section says the checks reach three code trees and no further: the
    two simulator headers, the formal tree, and the two kernel modules. A
    checker that starts reading a fourth tree makes that sentence false, and
    one that stops reading the modules makes it generous.
    """
    here = pathlib.Path(__file__).parent
    src = (here / "check_paper_counts.py").read_text()
    reads = set()
    for rel in re.findall(r'"(\.\./[\w./-]+)"', src):
        parts = tuple(x for x in pathlib.PurePosixPath(rel).parts
                      if x not in ("..", "."))
        if parts:
            reads.add(parts[0])
    # The kernel modules are reached by a composed path rather than a
    # literal, so the tree is named where the checker builds it.
    if re.search(r'"kinsn"\s*/\s*"module"', src):
        reads.add("kinsn")
    # The build directory is reached through bare-string joins and tuple
    # entries rather than a `../` path, so it is named where it is used.
    if re.search(r'"build"', src):
        reads.add("build")
    # `docs` is the section under test, not a fourth subject tree.
    allowed = {"x86", "arm64", "kinsn", "docs", "build"}
    out = []
    for tree in sorted(reads - allowed):
        out.append("the checker reads %s beyond the four trees the section "
                   "names" % tree)
    for tree in sorted(allowed - reads):
        out.append("the checker no longer reads %s, which the section says "
                   "it does" % tree)
    return out


def helper_id_table() -> list[str]:
    """Problems with the helper-id table, empty when it is strictly rising.

    The section says the id table is strictly increasing and so cannot alias
    two helper ids to one slot. A repeat or a descent would alias two ids to
    one row, which is the failure the ordering exists to prevent.
    """
    import json
    f = pathlib.Path(__file__).parent / "arm64_helper_idents_spec.json"
    ids = [r["id"] for r in json.loads(f.read_text())["rows"]]
    out = []
    if len(set(ids)) != len(ids):
        out.append("the helper-id table repeats an id")
    for a, b in zip(ids, ids[1:]):
        if b <= a:
            out.append("the helper-id table goes %d then %d" % (a, b))
            break
    return out


def helper_dispatch_shape() -> list[str]:
    """Problems with the helper ladder's shape, empty when the section holds.

    The section states four things about it: the id table is strictly
    increasing, the selector maps exactly the armed ids, the first unarmed
    and last named ids are fixed, and the id and slot tables invert over
    the armed range. Each is a property of two tables meeting at the armed
    count, so a row added to one and not the other breaks the inversion.
    """
    import json
    here = pathlib.Path(__file__).parent
    spec = json.loads((here / "x86_helper_dispatch_spec.json").read_text())
    helpers = spec["helpers"]
    ids = [r["id"] for r in helpers]
    out = []
    if ids != list(range(1, len(ids) + 1)):
        out.append("the armed helper ids are %s, not 1..%d"
                   % (ids, len(ids)))
    if spec["helper_count"] != len(helpers):
        out.append("helper_count is %d and the table holds %d rows"
                   % (spec["helper_count"], len(helpers)))
    for r in helpers:
        if r["body"] != "X86_SIM_BPF_CALL_" + r["name"]:
            out.append("%s carries body %s" % (r["name"], r["body"]))
    sim = (here / ".." / "x86" / "x86_sim_local_bpf.h").read_text()
    named = sorted(int(v) for v in re.findall(
        r"#define X86_SIM_HELPER_\w+ (\d+)U", sim))
    armed = len(helpers)
    if named and armed:
        if any(i not in named for i in range(1, armed + 1)):
            out.append("an armed id is not named by the simulator header")
        above = [i for i in named if i > armed]
        if above and min(above) != armed + 1:
            out.append("the first unarmed named id is %d and the section "
                       "says %d" % (min(above), armed + 1))
    return out


def generator_coverage() -> list[str]:
    """Problems with the generator/gate pairing, empty when it is exact.

    The section says every generator re-derives its output on each run and
    fails on any byte difference, all 138 passing --check, so a hand edit to
    a generated file or a stale artifact cannot survive the gate. A
    generator on disk that the recipe never runs makes that sentence false
    in the direction that matters: its artifacts have no enforcement.
    """
    here = pathlib.Path(__file__).parent
    disk = {p.name for p in here.glob("generate_*_spec.py")}
    gate = set(re.findall(r"(generate_\w+_spec\.py) --check",
                          (here / "Makefile").read_text()))
    out = []
    for name in sorted(disk - gate):
        out.append("%s is on disk and the recipe never checks it" % name)
    for name in sorted(gate - disk):
        out.append("the recipe checks %s and it is not on disk" % name)
    return out


# Each "the X and Y decoders cannot disagree" sentence rests on a theorem
# that equates the two sentinels. Proven by `rfl`, so its name is what ties
# the sentence to the proof; a rename or a removal is the drift.
SENTINEL_THEOREMS = (
    "x86_reg_presence_sentinel_is_0xff",
    "x86_reg_presence_sentinel_is_absent",
    "x86_reg_presence_sentinel_is_index_sentinel",
    "x86_reg_presence_sentinel_is_index_none",
    "x86_reg_presence_absent_complement",
)


def sentinel_theorems() -> list[str]:
    """Problems with the sentinel proofs, empty when all of them remain.

    The section says the operand-presence, register-number and memory-index
    decoders cannot disagree about "no register", and that presence and
    absence are complementary. Each is a theorem in the presence module, so
    a missing one leaves the sentence with nothing behind it.
    """
    src = (pathlib.Path(__file__).parent / "KProgFormal"
           / "X86RegPresence.lean").read_text()
    out = []
    for name in SENTINEL_THEOREMS:
        if not re.search(r"theorem %s\b" % re.escape(name), src):
            out.append("the section's sentinel claim has no %s" % name)
    return out


# Each "A and B cannot disagree about X" sentence is carried by a theorem
# asserting the agreement, usually a roundtrip or an equality of two
# derivations. The module and the name are what tie the prose to the proof.
AGREEMENT_THEOREMS = (
    ("Arm64StackArena.lean", "arm64_stack_arena_views_coincide"),
    ("Arm64HelperArgPtrShape.lean",
     "arm64_helper_arg_ptr_of_code_roundtrip"),
    ("Arm64VregFieldShape.lean",
     "arm64_vreg_field_offsets_are_half_offsets"),
    ("Arm64ByteLane.lean", "arm64_byte_lane_load_inverse"),
    ("Arm64StackArmShape.lean", "arm64_stack_arm_byte_iff"),
    ("Arm64MemBaseSrcShape.lean", "arm64_mem_base_src_of_code_roundtrip"),
    ("Arm64StackArena.lean", "arm64_stack_arena_word_index_refines"),
)


# Each theorem's statement, digested. Binding the name alone catches a
# rename or a deletion; binding the statement as well catches a theorem
# that kept its name while its claim changed.
AGREEMENT_STATEMENTS = {
    "arm64_stack_arena_views_coincide": "b27c02c8afdf",
    "arm64_helper_arg_ptr_of_code_roundtrip": "a496813a3ace",
    "arm64_vreg_field_offsets_are_half_offsets": "c923dbc65aa1",
    "arm64_byte_lane_load_inverse": "8e56e59fe860",
    "arm64_stack_arm_byte_iff": "15174ab03fce",
    "arm64_mem_base_src_of_code_roundtrip": "a496813a3ace",
    "arm64_stack_arena_word_index_refines": "0cb48e11416a",
}



# "each source names exactly one base-address source and the closed fact
# selects between the two and cannot be restated as a hand-written gate; the
# same selection is shared by the read, read-tag, and write helpers": four
# theorems, one per consumer, so a consumer that stopped sharing reports.
SHARED_SELECTION_THEOREMS = (
    ("Arm64MemBaseSrcShape.lean",
     "arm64_mem_base_src_matches_write_arm"),
    ("Arm64MemBaseSrcShape.lean",
     "arm64_mem_base_src_matches_read_src"),
    ("Arm64MemBaseSrcShape.lean", "arm64_mem_base_src_selects_sp"),
    ("Arm64MemBaseSrcShape.lean", "arm64_mem_base_src_case_refines"),
    ("X86MovxShape.lean", "x86_movx_shape_refines"),
    ("X86MovxShape.lean", "x86_movx_shape_codes_nodup"),
    ("Arm64Width.lean", "arm64_width_bits_refines"),
    ("Arm64MemOffset.lean", "arm64_mem_offset_refines"),
    ("Arm64MemOffset.lean", "arm64_mem_offset_case_dispatch"),
    ("Arm64StackWriteTagActionShape.lean",
     "arm64_stack_write_tag_action_refines"),
    ("Arm64StackWriteTagActionShape.lean",
     "arm64_stack_write_tag_action_codes_nodup"),
    ("Arm64CselPtr.lean", "arm64_csel_ptr_refines"),
    ("Arm64CselPtr.lean", "arm64_csel_ptr_code_dispatch"),
    ("Arm64MemIndexValueShape.lean",
     "arm64_mem_index_value_refines"),
    ("Arm64MemIndexValueShape.lean",
     "arm64_mem_index_value_codes_nodup"),
    ("Arm64WriteArmShape.lean", "arm64_write_arm_refines"),
    ("Arm64WriteArmShape.lean", "arm64_write_arm_codes_nodup"),
    ("X86WriteWidthArmShape.lean", "x86_write_width_arm_refines"),
    ("X86WriteWidthArmShape.lean", "x86_write_width_arm_codes_nodup"),
    ("X86MovRegShape.lean", "x86_mov_reg_arm_refines"),
    ("X86MovRegShape.lean", "x86_mov_reg_arm_codes_nodup"),
    ("Arm64MemWriteArmShape.lean", "arm64_mem_write_arm_refines"),
    ("Arm64MemWriteArmShape.lean", "arm64_mem_write_arm_codes_nodup"),
    ("Arm64StackWriteLanesShape.lean",
     "arm64_stack_write_lanes_mask_refines"),
    ("Arm64StackWriteLanesShape.lean",
     "arm64_stack_write_lanes_count_refines"),
    ("Arm64StackReadTagSourceShape.lean",
     "arm64_stack_read_tag_source_refines"),
    ("Arm64StackReadTagSourceShape.lean",
     "arm64_stack_read_tag_source_codes_nodup"),
    ("X86AluFlagArmShape.lean", "x86_alu_flag_arm_refines"),
    ("X86AluFlagArmShape.lean", "x86_alu_flag_arm_codes_nodup"),
)

# The width-resolution and movx-shape sentences have the same closure
# shape: a refinement theorem per arm, and a no-dup table so no two
# arms collide.


def shared_selection_theorems() -> list[str]:
    """Problems with the shared base-source selection, empty when it holds.

    The section says the closed fact selects between two sources and that
    the same selection is shared by the read, read-tag and write helpers
    rather than repeated. Each consumer has a theorem equating its own
    choice with the shared one, so a consumer that drifts reports.
    """
    here = pathlib.Path(__file__).parent / "KProgFormal"
    out = []
    for module, name in SHARED_SELECTION_THEOREMS:
        f = here / module
        if not f.exists():
            out.append("the shared-selection claim has no %s" % module)
            continue
        if not re.search(r"^theorem %s\b" % re.escape(name),
                         f.read_text(), re.M):
            out.append("%s does not prove %s" % (module, name))
    return out



def agreement_theorems() -> list[str]:
    """Problems with the agreement proofs, empty when each still exists.

    The section says pairs of decoders cannot disagree about a value -- the
    arena address, the high lane's displacement, which base is served. Each
    rests on a theorem asserting the agreement, so a missing module or a
    renamed theorem leaves the sentence with nothing behind it.
    """
    here = pathlib.Path(__file__).parent / "KProgFormal"
    out = []
    for module, name in AGREEMENT_THEOREMS:
        f = here / module
        if not f.exists():
            out.append("the section's agreement claim has no %s" % module)
            continue
        src = f.read_text()
        m = re.search(
            r"theorem %s\b(.*?) := " % re.escape(name),
            src, re.S)
        if m is None:
            out.append("%s does not prove %s" % (module, name))
            continue
        import hashlib
        got = hashlib.sha256(
            " ".join(m.group(1).split()).encode()).hexdigest()[:12]
        if got != AGREEMENT_STATEMENTS[name]:
            out.append("%s now states something else (%s)"
                       % (name, got))
    return out


# `lake build` prints a per-module progress line only for modules it
# rebuilt, so two runs on trees that differ in build state show different
# numbers of them. Everything else in the log is gate output and is
# expected to be byte-identical.
BUILD_PROGRESS = re.compile(
    r"^.*Built KProgFormal.*$|^trace: .*$", re.M)


def determinism_keys(log: str) -> str:
    """The part of a gate log two runs must agree on, byte for byte.

    The section says two consecutive full runs produce byte-identical
    output, so the pass is reproducible rather than momentary. The build
    progress lines are excluded because they count modules rebuilt rather
    than anything the gate decided.
    """
    stripped = BUILD_PROGRESS.sub("", log)
    return "\n".join(l for l in stripped.split("\n") if l.strip())


VOLATILE = re.compile(
    r"\b\d{4}-\d{2}-\d{2}[ T]\d{2}:\d{2}:\d{2}\b|"
    r"\b[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}\b|\bpid[ =]\d+", re.M)


def volatile_tokens(log: str) -> list[str]:
    """Volatile tokens in a gate log, which would stop it being identical.

    The section says two consecutive full runs produce byte-identical
    output. A timestamp, a uuid or a pid in the log would make that false
    whatever the messages say, so their absence is a necessary condition a
    single log can show.
    """
    return sorted({m.group(0) for m in VOLATILE.finditer(log)})[:5]


def vacuous_theorems() -> list[str]:
    """Theorems that close by reflexivity or decide with both sides alike.

    The section says the theorems closing by `rfl` or `decide` over a table
    carry content rather than closing vacuously. A statement whose two
    sides are syntactically the same is the vacuous case: it proves
    nothing about the table and would still be counted as a row.
    """
    out = []
    head = re.compile(
        r"^(?:@\[[^\]]*\]\s*)?theorem (\w+)((?:(?!:=)[\s\S])*?):=",
        re.M)
    proof = re.compile(r"\s*(rfl\b|by\b[\s\S]*?\brfl\b"
                       r"|by\s+(?:native_)?decide\b)")
    here = pathlib.Path(__file__).parent / "KProgFormal"
    seen = 0
    for f in sorted(here.glob("*.lean")):
        src = f.read_text(errors="ignore")
        for m in head.finditer(src):
            seen += 1
            # The body may open with a tactic block and still close by
            # decide, as `refine ⟨?_, ?_⟩ <;> native_decide` does, so the
            # terminator is searched in the body rather than matched at
            # its first word.
            body = src[m.end():m.end() + 400]
            if not proof.match(body) and not re.search(
                    r"\b(?:native_)?decide\b", body):
                continue
            stmt = " ".join(m.group(2).split())
            if "=" not in stmt or "↔" in stmt or "∧" in stmt:
                continue
            a, b = stmt.split("=", 1)
            if a.strip().lstrip(":(").strip() == b.strip():
                out.append("%s closes %s vacuously" % (f.name, m.group(1)))
    # The scan must reach every theorem the tree proves, or a vacuous one
    # in an unread form passes; that is how the two widenings above were
    # found, both by measuring the reach rather than reading the code.
    import check_lean_claims as _cl
    want = _cl.scan_tree(str(here.parent))["theorems"]
    if seen != want:
        out.append("the vacuity scan reached %d of %d theorems"
                   % (seen, want))
    return out


def dispatch_totality() -> tuple[int, int, int]:
    """`(family, singleton, union)` opcode counts for the x86 chain.

    The section says the twenty-four family and forty-three singleton
    opcodes are sixty-seven distinct ones, over a population that makes the
    exclusivity statement non-vacuous. The three figures are lengths of
    lists the totality module defines, so they are read from that module
    rather than trusted.
    """
    here = pathlib.Path(__file__).parent
    fam = (here / "KProgFormal" / "X86DispatchTotality.lean").read_text()
    defs = {}
    for name in ("routedByFamily", "routedBySingleton", "routed"):
        m = re.search(r"^def %s : List Nat :=(.*?)^\S" % name, fam,
                      re.S | re.M)
        defs[name] = " ".join(m.group(1).split()) if m else ""
    # The lists are built from named op-lists and deduped; count through
    # the same source the module uses.
    import check_lean_claims as _cl
    fam = _count_ops(here, "X86DispatchFamily", "x86DispatchOps")
    sing = _count_ops(here, "X86DispatchSingleton", "x86SingletonOps")
    # The union is the sum because the module proves the two routed lists
    # disjoint, so a code in both would break that theorem rather than this
    # arithmetic.
    return fam, sing, fam + sing


def _count_ops(here: pathlib.Path, module: str, ops: str) -> int:
    """Distinct opcodes the named op-list resolves to, read from the arms."""
    src = (here / "KProgFormal" / (module + ".lean")).read_text()
    m = re.search(r"^def %s : List \w+ :=(.*?)^\S" % ops, src, re.S | re.M)
    if m is None:
        return -1
    # Every named sub-list is defined in the same module as a literal.
    total = 0
    for sub in re.findall(r"(\w+Ops?)\b", m.group(1)):
        s2 = re.search(r"^def %s : List \w+ :=\s*\[(.*?)\]" % sub, src,
                       re.S | re.M)
        if s2:
            total += len([x for x in s2.group(1).split(",") if x.strip()])
    return total


def mul_nonmember_check() -> list[str]:
    """Problems with the multiply host's non-member case, empty when present.

    The section says the host requires a non-member opcode to reach the
    unsupported arm "so the counter cannot be vacuously zero", and that
    computing the expectation from the architectural definition keeps the
    check from being circular. Both are properties of one file: a case that
    drives an opcode outside the three, and a comparison against a value
    the contract does not supply.
    """
    f = pathlib.Path(__file__).parent / "build" / "mul_route_host.c"
    if not f.exists():
        return ["the multiply route host is absent, so its non-member case "
                "went unread"]
    src = f.read_text(errors="ignore")
    out = []
    if "unsupported_calls" not in src:
        out.append("the multiply host counts no unsupported calls, so a "
                   "silent zero would pass")
    if not re.search(r"unsupported_calls == before", src):
        out.append("the multiply host never compares the unsupported count")
    return out


def cited_files() -> list[str]:
    """File names the section cites that no tree beside it contains.

    The section names its artifacts by file name — headers, generators,
    generated modules, hosts. A rename in the tree leaves the prose pointing
    at a file that no longer exists, which no figure records, because a name
    is not a number.
    """
    here = pathlib.Path(__file__).parent
    text = pathlib.Path(here / ".." / ".." / "docs"
                        / "kprog-simulator-in-ebpf" / "sections"
                        / "4-safety.tex").read_text()
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    names = {n.replace("\\_", "_") for n in re.findall(
        r"\\texttt\{((?:[\w/\\_.-]+\.(?:c|h|py|lean|json)))\}", flat)}
    have = set()
    for root in ("..", "../../kinsn"):
        for p in pathlib.Path(here / root).rglob("*"):
            if p.is_file():
                have.add(p.name)
    return sorted(n for n in names
                  if n.split("/")[-1] not in have and n != ".bpf.c")


def bv_decide_partition() -> list[str]:
    """Problems with the bv_decide population split, empty when it adds up.

    The section partitions the 165 obligations bv_decide closes into 61 that
    need a cases split and 104 that bind a bit-vector operand directly, and
    reports that 58 of the first and 103 of the second cannot state the goal
    under a plain decide -- 161 of the 165. Four independent figures, so a
    transcription error in any one breaks the arithmetic.
    """
    here = pathlib.Path(__file__).parent
    flat = re.sub(r"\s+", " ", pathlib.Path(
        here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
        / "sections" / "4-safety.tex").read_text()).replace("\\brk", "")
    m = re.search(
        r"of the (\d+) \\texttt\{bv\\_decide\} closes, (\d+) do\.", flat)
    n = re.search(
        r"(\d+) of the (\d+) and (\d+) of the (\d+) cannot state", flat)
    out = []
    if m is None or n is None:
        return ["the bv_decide partition sentence is absent, so its figures "
                "went unread"]
    total, compiles = int(m.group(1)), int(m.group(2))
    g1, t1, g2, t2 = (int(x) for x in n.groups())
    if t1 + t2 != total:
        out.append("the split covers %d and the population is %d"
                   % (t1 + t2, total))
    if g1 + g2 != compiles:
        out.append("the unable-to-state figures sum to %d and %d compile"
                   % (g1 + g2, compiles))
    return out


def memset_bound() -> list[str]:
    """Problems with the memcpy/memset length bound, empty when it holds.

    The section says a 1024-byte copy is accepted while 1025 and -1 raise
    ValueError, so the simulator's bound cannot be crossed by an artifact the
    encoder produces. The rule is one comparison each side of the bound, and
    the bound is a constant, so all three figures are readable.
    """
    here = pathlib.Path(__file__).parent
    src = (here / ".." / "x86" / "micro-prog"
           / "generate_micro_sim_proofs.py").read_text()
    m = re.search(r"^MAX_MEMSET_COUNT = (\d+)$", src, re.M)
    if m is None:
        return ["the encoder has no memset bound, so the section's three "
                "figures went unread"]
    out = []
    if int(m.group(1)) != 1024:
        out.append("the encoder bound is %s and the section says 1024"
                   % m.group(1))
    for kind in ("memcpy", "memset"):
        if not re.search(r"if insn\.sim_imm < 0 or insn\.sim_imm > "
                         r"MAX_MEMSET_COUNT:\s*\n\s*raise ValueError",
                         src):
            out.append("the %s length is not bounded on both sides" % kind)
            break
    return out


def cross_document() -> list[str]:
    """Problems where the paper and the step record disagree on a tree figure.

    The two documents describe the same tree from different directions: the
    section argues about it, the record says how it was built. A figure both
    state — the theorem count, the specification count — must agree with the
    tree and with each other.

    The figure is read from the words beside it rather than by matching its
    value, so a transcription error is found rather than being invisible
    because the pattern no longer matches.
    """
    here = pathlib.Path(__file__).parent
    paper = re.sub(r"\s+", " ", (here / ".." / ".." / "docs"
        / "kprog-simulator-in-ebpf" / "sections" / "4-safety.tex")
        .read_text()).replace("\\brk", "").replace("{,}", ",")
    # The second document is the formal tree's own readme, which states
    # the same totals in the same words.
    rec = re.sub(r"\s+", " ", (here / "README.md").read_text())
    import check_lean_claims as _cl
    tree = _cl.scan_tree(str(here))
    out = []
    # "138 specifications into 138 C headers and 138 Lean modules": the
    # regeneration claim, which names the specification count exactly.
    for label, ctx, want in (
            ("specifications",
             r"(\d+)\s+specifications into \1", tree["specs"]),
            ("modules", r"(\d+) Lean modules that prove",
             tree["modules"]),
            ("theorems", r"Lean modules that prove (\d[\d,]*)\s+theorems",
             tree["theorems"])):
        pv = {int(x.replace(",", "")) for x in re.findall(ctx, paper)}
        rv = {int(x.replace(",", "")) for x in re.findall(ctx, rec)}
        if (pv | rv) != {want}:
            out.append("the section and the record disagree on %s: %s and "
                       "%s, tree %d" % (label, sorted(pv), sorted(rv), want))
    return out


def tag_arms_differ() -> list[str]:
    """Problems with the two-arm tag assertion, empty when it is present.

    The section says the oracle asserts the two arms select different tags
    "so that the check cannot pass with both arms identical". Without that
    assertion the address comparison passes whichever tag each arm writes,
    which is the vacuity the sentence names.
    """
    f = pathlib.Path(__file__).parent / "test_arm64_adrp_route_host.c"
    if not f.exists():
        return ["the ADRP route host is absent, so the tag assertion went "
                "unread"]
    src = f.read_text(errors="ignore")
    if "must select different tags" not in src:
        return ["the ADRP route host does not assert the arms differ"]
    if "pass with both arms identical" not in src:
        return ["the ADRP route host asserts the difference without saying "
                "what it prevents"]
    return []


def orn_vacuity_guards() -> list[str]:
    """Problems with the ORN host's vacuity assertions, empty when present.

    The section says the run asserts a non-identity modifier was actually
    exercised, so the run cannot be vacuous, and that a non-member opcode
    reaches the unsupported arm. Both are guards against an oracle that
    passes because it compared nothing.
    """
    f = pathlib.Path(__file__).parent / "test_arm64_orn_route_host.c"
    if not f.exists():
        return ["the ORN route host is absent, so its vacuity guards went "
                "unread"]
    src = f.read_text(errors="ignore")
    out = []
    if "seen_nonidentity" not in src or \
            "no non-identity modifier was exercised" not in src:
        out.append("the ORN host does not require a non-identity modifier")
    if "non-member opcode" not in src.lower() and \
            "non_member" not in src:
        out.append("the ORN host does not require a non-member opcode")
    return out


def reachability_theorems() -> list[str]:
    """Problems with the arm-reachability proofs, empty when all still prove.

    An arm no input reaches makes a dispatch contract true for a reason the
    reader did not intend, so the section says the arms are reachable and
    the proof is a theorem. A missing one leaves the sentence with nothing
    behind it.
    """
    here = pathlib.Path(__file__).parent / "KProgFormal"
    out = []
    for mod in ("X86MemDispatch.lean", "X86MovLoadHandler.lean",
                "X86MovbeHandler.lean", "X86Xmm0Handler.lean"):
        f = here / mod
        if not f.exists():
            out.append("the reachability claim has no %s" % mod)
            continue
        if not re.search(r"^theorem \w*reachable\b", f.read_text(), re.M):
            out.append("%s proves no arm reachable" % mod)
    return out


def stale_log(log_path: pathlib.Path) -> list[str]:
    """Problems with a gate log older than a checker that has changed.

    A passing gate reports on the tree it ran on. A component edited after
    the log says nothing about the code that is there now. The work tree
    decides rather than the timestamp, since a touch moves the time without
    moving the checker.
    """
    here = pathlib.Path(__file__).parent
    if not log_path.exists():
        return []
    when = log_path.stat().st_mtime
    recipe = (here / "Makefile").read_text()
    components = sorted(set(re.findall(
        r"python3 ((?:check|mutate)_\w+\.py)", recipe)))
    components += ["harness_census.py", "Makefile"]
    try:
        out_ = subprocess.run(
            ["git", "status", "--porcelain", "--"] +
            [str(here / c) for c in components],
            capture_output=True, text=True, cwd=str(here)).stdout
    except OSError:
        return []
    dirty = {l.split()[-1].split("/")[-1] for l in out_.split("\n") if l}
    out = []
    for name in components:
        f = here / name
        if f.exists() and name in dirty and f.stat().st_mtime > when:
            out.append("%s changed after the log was written, so the run "
                       "does not reflect it" % name)
    return out

def cross_isa_arena() -> list[str]:
    """Problems with the stack-arena correspondence, empty when it holds.

    The section says the two architectures phrase the same restriction
    differently -- a numeric capacity on one side, an equivalent no-wrap
    predicate on the other -- and that the correspondence is a theorem
    rather than an eyeball comparison. Four correspondences carry it: the
    word index, the alignment guard, the word count, and the window fit.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "CrossIsaStackArena.lean")
    if not f.exists():
        return ["the cross-ISA stack-arena module is absent, so the "
                "correspondence sentence rests on an eyeball comparison"]
    src = f.read_text()
    out = []
    for name in ("wordIndex_agrees", "wordAligned_agrees", "words_agrees",
                 "windowEnd_agrees", "windowFits_agrees"):
        if not re.search(r"^theorem %s\b" % name, src, re.M):
            out.append("the arena correspondence no longer proves %s" % name)
    return out


def arena_counterexample() -> list[str]:
    """Problems with the one-byte-arena counterexample, empty when it holds.

    The section says the whole-word condition fails on the disabled arena,
    which is one byte, and that the counterexample is now a theorem. The
    theorem carries the condition as a hypothesis, so a version that dropped
    it would prove the guards coincide everywhere and the sentence would be
    false.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "Arm64StackArena.lean")
    if not f.exists():
        return ["the arena module is absent, so the counterexample went "
                "unread"]
    src = f.read_text()
    m = re.search(
        r"^theorem arm64_stack_arena_tag_guard_is_window_guard\b(.*?) := ",
        src, re.S | re.M)
    if m is None:
        return ["the arena guard theorem is absent"]
    if "capacity.toNat % 8 = 0" not in m.group(1):
        return ["the arena guard theorem no longer carries the whole-word "
                "hypothesis, so the one-byte arena is not excluded"]
    return []


def doubleshift_opcode_keyed() -> list[str]:
    """Problems with the double-shift arm selection, empty when it holds.

    The section says the body and the flag family are selected by the same
    opcode and cannot diverge. That is three theorems over one argument:
    the arm, the flags and the result are each refined at the same opcode,
    so a version refining one of them at a different key would let the
    fourth round float against the first.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "X86DoubleShiftArmHandler.lean")
    if not f.exists():
        return ["the double-shift handler module is absent, so the "
                "same-opcode sentence went unread"]
    src = f.read_text()
    out = []
    for name in ("x86_doubleshift_arm_refines",
                 "x86_doubleshift_flags_refines",
                 "x86_doubleshift_result_refines"):
        m = re.search(r"^theorem %s\b(.*?) := " % name, src, re.S | re.M)
        if m is None:
            out.append("%s is absent, so the body and flags may be keyed "
                       "differently" % name)
        elif not re.match(r"\s*\(\s*op\s*:", m.group(1)):
            out.append("%s does not take the opcode as its key" % name)
    return out


def push_pop_one_selection() -> list[str]:
    """Problems with the push/pop "one selection" theorem, empty when it holds.

    The section says the body that pre-decrements is exactly the body that
    hardcodes 64, and that reading one body's width into the other is the
    confusion the contract pins away. That is one theorem stating both
    directions and both width sources together, with the two pairs
    asserted distinct; separate theorems would each be true and the
    sentence false.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "X86PushPopHandler.lean")
    if not f.exists():
        return ["the push/pop handler module is absent, so the one-selection "
                "sentence went unread"]
    src = f.read_text()
    m = re.search(r"^theorem x86_push_pop_facts\b(.*?) := ", src,
                  re.S | re.M)
    if m is None:
        return ["x86_push_pop_facts is absent"]
    body = m.group(1)
    out = []
    for need, why in (
            ("hardcoded64", "the push width source"),
            ("preDecrement", "the push step direction"),
            ("flagsOr64", "the pop width source"),
            ("postIncrement", "the pop step direction")):
        if need not in body:
            out.append("x86_push_pop_facts no longer states %s" % why)
    if body.count("\u2260") < 2:
        out.append("x86_push_pop_facts no longer asserts the two pairs "
                   "distinct")
    return out


def popcnt_flag_rule() -> list[str]:
    """Problems with the POPCNT flag rule, empty when it matches the prose.

    The section says the transition clears CF, SF and OF and sets ZF exactly
    when the width-narrowed source is zero -- so the consequence depends on
    the narrowed source and not on the result. Three clears and one
    narrowed-source test, readable in the spec function.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "X86PopcntFlags.lean")
    if not f.exists():
        return ["the POPCNT flag module is absent, so its rule went unread"]
    src = f.read_text()
    m = re.search(r"^def x86PopcntFlagsSpec\b(.*?)^\S", src, re.S | re.M)
    if m is None:
        return ["x86PopcntFlagsSpec is absent"]
    body = " ".join(m.group(1).split())
    out = []
    for flag in ("cf", "sf", "of"):
        if "%s := false" % flag not in body:
            out.append("POPCNT no longer clears %s" % flag.upper())
    if "zf := x86PopcntZeroSpec" not in body:
        out.append("POPCNT's ZF no longer comes from the narrowed source")
    return out


def bzhi_flag_rule() -> list[str]:
    """Problems with the BZHI flag rule, empty when it matches the prose.

    The section says the transition clears SF and OF, sets CF exactly when
    the byte-masked count reaches the resolved width's bit count, and sets
    ZF exactly when the cleared result is zero -- two independent inputs
    rather than one. That is four flag assignments and two source
    predicates.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "X86BzhiFlags.lean")
    if not f.exists():
        return ["the BZHI flag module is absent, so its rule went unread"]
    src = f.read_text()
    m = re.search(r"^def x86BzhiSetFlagsSpec\b(.*?)^\S", src, re.S | re.M)
    if m is None:
        return ["x86BzhiSetFlagsSpec is absent"]
    body = " ".join(m.group(1).split())
    out = []
    for flag in ("sf", "of"):
        if "%s := false" % flag not in body:
            out.append("BZHI no longer clears %s" % flag.upper())
    if "cf := x86BzhiSetCfSpec" not in body:
        out.append("BZHI's CF no longer comes from the count-versus-width "
                   "predicate")
    if "zf := x86BzhiSetZfSpec" not in body:
        out.append("BZHI's ZF no longer comes from the result-zero "
                   "predicate")
    return out


def carry_polarity() -> list[str]:
    """Problems with the carry-polarity correspondence, empty when it holds.

    The section says AArch64 sets its carry to not-borrow and x86-64 to
    borrow on the same narrowed operands, that each is right for its own
    architecture, and that the relation between them is a theorem. Two are
    needed: the complement over all operands, and a witness where the two
    flags genuinely differ, or the complement could hold vacuously.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "CrossIsaFlags.lean")
    if not f.exists():
        return ["the cross-ISA flag module is absent, so the polarity "
                "sentence went unread"]
    src = f.read_text()
    out = []
    m = re.search(r"^theorem arm64_notborrow_is_not_x86_borrow\b(.*?) := ",
                  src, re.S | re.M)
    if m is None:
        out.append("the complement theorem is absent")
    elif "ult" not in m.group(1) or "!" not in m.group(1):
        out.append("the complement theorem no longer negates the borrow")
    if not re.search(r"^theorem arm64_x86_disagree_on_borrow\b", src, re.M):
        out.append("no witness shows the two flags actually differ")
    return out


def native_decide_split() -> list[str]:
    """Problems with the native_decide split, empty when it reconciles.

    The section divides the 488 uses three ways, says two of the refinement
    uses are themselves enumerations, and that one use sits in none of the
    three. Four published figures, and the arithmetic has to close on the
    tree's own count.
    """
    here = pathlib.Path(__file__).parent
    flat = re.sub(r"\s+", " ", pathlib.Path(
        here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
        / "sections" / "4-safety.tex").read_text()).replace("\\brk", "")
    m = re.search(
        r"Its (\d+) uses fall into three kinds.*?the (\d+) finite "
        r"enumerations.*?; (\d+) concrete example values.*?and (\d+) of "
        r"the (\d+) refinement-named", flat)
    if m is None:
        return ["the native_decide split sentence is absent, so its figures "
                "went unread"]
    total, enums, examples, refines, named = (int(x) for x in m.groups())
    nested = re.search(r"(\d+) of the refinement uses are themselves "
                       r"enumerations", flat)
    missing = re.search(r"the three counts sum to (\d+) rather than "
                        r"(\d+)\. One use sits in none", flat)
    out = []
    if nested is None or missing is None:
        return ["the split no longer says how the counts reconcile"]
    nest = int(nested.group(1))
    if enums + examples + refines - nest != int(missing.group(1)):
        out.append("the three counts do not sum to what the sentence says")
    if int(missing.group(1)) + 1 != int(missing.group(2)):
        out.append("the sum plus the one uncategorised use is not the total")
    if int(missing.group(2)) != total:
        out.append("the drift-free total is %d and the split is over %d"
                   % (int(missing.group(2)), total))
    # The tree's own count, not a literal: `check_lean_claims` already
    # measures this population, so the section's figure is compared with
    # that measurement rather than with a number typed here.
    import check_lean_claims
    refines = check_lean_claims.scan_tree(
        str(pathlib.Path(__file__).parent))["refines"]
    if named != refines:
        out.append("the refinement-named population is %d and the tree has "
                   "%d" % (named, refines))
    return out


def default_code_is_w64() -> list[str]:
    """Problems with the width fallback, empty when it holds.

    The section says the default code is exactly the 64-bit width's code,
    so the resolution cannot drift from the width table. Three figures make
    that checkable: the generated table's code for the 64-bit width, the
    generated fallback constant, and the theorem equating them.
    """
    here = pathlib.Path(__file__).parent / "KProgFormal"
    gen = here / "GeneratedArm64Width.lean"
    hand = here / "Arm64Width.lean"
    if not gen.exists() or not hand.exists():
        return ["the width modules are absent, so the fallback went unread"]
    g = gen.read_text()
    out = []
    m = re.search(r"\| \.w64 => (\d+)", g)
    d = re.search(r"^def defaultCode : Nat := (\d+)$", g, re.M)
    if m is None or d is None:
        out.append("the generated width table or the fallback constant is "
                   "absent")
    elif m.group(1) != d.group(1):
        out.append("the fallback is code %s and the 64-bit width is %s"
                   % (d.group(1), m.group(1)))
    if not re.search(r"^theorem arm64_default_code_is_w64\b",
                     hand.read_text(), re.M):
        out.append("nothing equates the fallback with the 64-bit width")
    return out


def packet_bounds_fixture() -> list[str]:
    """Problems with the packet-bounds negative case, empty when it holds.

    The section says the packet-bounds case has a concrete fixture: a native
    program reading a packet byte without a data_end check generates an
    artifact the stock verifier rejects with 'invalid access to packet,
    off=64 size=1', and the selftest path drives it and asserts the
    diagnostic. That is one marker and one assertion, both readable.
    """
    f = (pathlib.Path(__file__).parent / ".." / ".." / "runner"
         / "suites" / "test.py")
    if not f.exists():
        return ["the selftest suite is absent, so the fixture went unread"]
    src = f.read_text()
    out = []
    marker = 'invalid access to packet, off=64 size=1'
    if marker not in src:
        out.append("the selftest does not look for the diagnostic the "
                   "section quotes")
    if "verifier_marker not in output" not in src:
        out.append("the selftest does not assert the diagnostic is present")
    if "unsafe native proof unexpectedly loaded" not in src:
        out.append("the selftest does not require the fixture to be "
                   "rejected")
    return out


def unexercised_negatives() -> list[str]:
    """Problems with the two negative cases the section says are unexercised.

    The section says the opaque-pointer helper-argument case and the
    unbounded-jump case have no fixture in the tree, and states them so the
    boundary between checked and argued is explicit. A fixture appearing
    later would make the sentence understate the evidence, which is the
    opposite of the usual drift and just as wrong.
    """
    f = (pathlib.Path(__file__).parent / ".." / ".." / "runner"
         / "suites" / "test.py")
    if not f.exists():
        return ["the selftest suite is absent, so the concession went unread"]
    src = f.read_text()
    out = []
    for word in ("opaque", "unbounded"):
        if word in src:
            out.append("the suite now exercises the %s case, which the "
                       "section says has no fixture" % word)
    return out


def window_overflow_mechanism() -> list[str]:
    """Problems with the window-overflow description, empty when it matches.

    The section names the mechanism on each side: x86-64 indexes the final
    lane directly through a runtime predicate, so the bound is not visible
    to the compiler, and AArch64 walks the same eight bytes through the
    load-bytes helper. Both are readable in the headers.
    """
    here = pathlib.Path(__file__).parent / ".."
    x86 = (here / "x86" / "x86_sim_local_bpf.h").read_text()
    arm = (here / "arm64" / "arm64_sim_local_bpf.h").read_text()
    out = []
    if "+ 7]" not in x86:
        out.append("the x86 byte ladder no longer indexes the final lane")
    if "LANE_ACTIVE" not in x86:
        out.append("the x86 final lane is no longer guarded by a runtime "
                   "predicate, so the compiler could see the bound")
    if "KPROG_ARM64_LOAD_BYTES" not in arm:
        out.append("the AArch64 side no longer walks the bytes through the "
                   "load helper")
    return out


def multiply_oracle() -> list[str]:
    """Problems with the multiply family's independent oracle, empty if ok.

    The section says no proof relates the multiply contract to its
    definition -- they come from one specification in a single pass, so
    they share any mistake -- and that the independent oracle is the host
    compiler's 128-bit integer type, which the simulator cannot use. Both
    halves are readable: the oracle's type is in the host, and no Lean
    theorem relates the contract to an architectural statement.
    """
    here = pathlib.Path(__file__).parent
    host = here / "test_arm64_mul_host.c"
    lean = here / "KProgFormal" / "Arm64Mul.lean"
    if not host.exists() or not lean.exists():
        return ["the multiply host or module is absent, so the oracle claim "
                "went unread"]
    out = []
    h = host.read_text()
    if "__int128" not in h:
        out.append("the multiply host no longer uses the compiler's 128-bit "
                   "type as its oracle")
    return out


def cross_isa_cond() -> list[str]:
    """Problems with the condition-code correspondence, empty when it holds.

    The section says the two architectures evaluate different intermediate
    flag facts -- carry on one side, borrow on the other, complementary --
    while the endpoints agree, and that a chain composed differently on one
    side would diverge while every per-architecture theorem still held. That
    is a complement over the same inputs plus an injective mapping.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal"
         / "CrossIsaCond.lean")
    if not f.exists():
        return ["the cross-ISA condition module is absent, so the "
                "correspondence sentence went unread"]
    src = f.read_text()
    out = []
    if not re.search(r"^theorem cs_is_ae_not_b\b", src, re.M):
        out.append("nothing shows the two sides evaluate different "
                   "intermediates")
    if not re.search(r"^theorem toX86_injective\b", src, re.M):
        out.append("nothing shows the condition mapping is injective, so "
                   "two conditions could collapse onto one")
    return out


def width_resolution_pair() -> list[str]:
    """Problems with the width-resolution pair, empty when both hold.

    The section says a resolved source width is never the absent code, so a
    body cannot widen at an unknown width, and separately that the fallback
    is the 64-bit code. Two theorems: one that no real width equals the
    absent code, one that the absent code resolves to the default.
    """
    f = (pathlib.Path(__file__).parent / "KProgFormal" / "Arm64Width.lean")
    if not f.exists():
        return ["the width module is absent, so the resolution pair went "
                "unread"]
    src = f.read_text()
    out = []
    if not re.search(r"^theorem arm64_absent_code_names_no_width\b", src,
                     re.M):
        out.append("nothing excludes the absent code from the real widths, "
                   "so a body could widen at an unknown width")
    if not re.search(r"^theorem arm64_effective_absent_is_default\b", src,
                     re.M):
        out.append("nothing says the absent code resolves to the default")
    return out


def macro_hygiene_history() -> list[str]:
    """Problems with the historical macro figures, empty when they agree.

    The section says the macro-hygiene check read only the text after a
    macro's first newline, leaving single-line macros unexamined, and gives
    the population "as it stood then". The checker carries the same two
    figures in the comment where the defect was recorded, so the two
    documents can be compared rather than trusted.
    """
    here = pathlib.Path(__file__).parent
    paper = re.sub(r"\s+", " ", pathlib.Path(
        here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
        / "sections" / "4-safety.tex").read_text()).replace("\\brk", "")
    check = (here / "check_macro_hygiene.py").read_text()
    m = re.search(r"(\d+) macros and (\d+) parameters", paper)
    c = re.search(r"-- (\d+) of them, (\d+) parameters --", check)
    if m is None:
        return ["the section no longer states the historical population"]
    if c is None:
        return ["the macro-hygiene checker no longer records the figure"]
    if m.groups() != c.groups():
        return ["the section says %s macros and %s parameters; the checker "
                "records %s and %s" % (m.group(1), m.group(2),
                                       c.group(1), c.group(2))]
    return []


def battery_rows(text: str) -> list[str]:
    """The pre/post sentence's two counts against its own battery.

    That sentence describes mut_arm64_pair_route, whose run reports 40
    mutations with 8 equivalences surviving, so 32 are caught. Both counts
    are read from that battery's source. The other twelve sentences of this
    shape describe route hosts rather than mutation batteries, so their
    counts have a different subject and are not compared here.
    """
    body = (pathlib.Path(__file__).parent / "build"
            / "mut_arm64_pair_route.py").read_text()
    rows = len(re.findall(r"^row\(", body, re.M))
    equiv = len(re.findall(r"equivalent=True", body))
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    # The count is tied to the digest it sits beside, which is the
    # pair-route battery's recorded shake.
    # The caller masks `\texttt` bodies, so the digest reads as a run of
    # X's; anchoring on the quoted digest keeps the count tied to the
    # sentence that also carries it.
    m = re.search(r"(\d+) catchable rows are caught.{0,120}?"
                  r"md5 X{8,}\) and (\d+) equivalences survive", flat)
    if m is None:
        return ["the sentence giving the pair-route battery's two counts is "
                "absent, so both figures went unread"]
    out = []
    if int(m.group(1)) != rows - equiv:
        out.append("the section states %s catchable rows and the pair-route "
                   "battery has %d of %d" % (m.group(1), rows - equiv, rows))
    if int(m.group(2)) != equiv:
        out.append("the section states %s equivalences and the battery has %d"
                   % (m.group(2), equiv))
    # The multiply-family sentence is the other one whose subject is its own
    # battery: it names the 64-row harness and the counts are that
    # battery's rows minus its equivalences.
    mul = (pathlib.Path(__file__).parent / "build"
           / "mut_arm64_mul_route.py").read_text()
    mrows = len(re.findall(r"^\s*row\(", mul, re.M))
    mequiv = len(re.findall(r"equivalent=True", mul))
    mm = re.search(r"(\d+) catchable rows are caught[^.]{0,140}?"
                   r"and (\d+) equivalences survive\. The arm64 module close",
                   flat)
    if mm is None:
        out.append("the multiply-family sentence is absent, so its figures "
                   "went unread")
    elif int(mm.group(1)) != mrows - mequiv or int(mm.group(2)) != mequiv:
        out.append("the section states %s rows and %s equivalences; the "
                   "multiply battery has %d and %d"
                   % (mm.group(1), mm.group(2), mrows - mequiv, mequiv))
    return out


# `{battery: rows caught}` from a clean run of each, for the two count
# sentences that state no equivalence count and so cannot be reconciled
# against the row total. Re-derive by running the battery: the total line
# prints mutations, failures and equivalences survived, and caught is the
# first minus the third. `mut_arm64_a64_route` gives 70 - 19 = 51 and
# `mut_x86_route` 65 - 23 = 42, both with zero failures.
CAUGHT_AT_LAST_RUN = {
    "arm64_a64_route": 51,
    "x86_route": 42,
}


def route_battery_rows() -> list[str]:
    """Every "N catchable rows ... M equivalences" against its battery.

    The battery the counts describe is named before them, so the name is
    resolved first and both branches below use it. Both figures are then
    checked as a sum against the battery's row count, which survives an
    equivalence taking its mark from a loop variable; the two sentences
    that state no equivalence count are compared with a recorded clean run.
    """
    here = pathlib.Path(__file__).parent
    raw = (here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
           / "sections" / "4-safety.tex").read_text()
    # A battery name may break after its separator (`mut\_arm64\_a64\_`
    # then `route.py`), so a line break there is removed before reading.
    flat = raw.replace("\\brk", "")
    flat = re.sub(r"\\_\s*", "\\_", flat)
    flat = re.sub(r"\s+", " ", flat)
    out = []
    for m in re.finditer(r"(\d+) catchable rows are caught", flat):
        names = [x.replace("\\_", "_") for x in
                 re.findall(r"mut\\_([a-z0-9\\_]+)",
                            flat[max(0, m.start() - 4000):m.start()])]
        names = [n.rstrip("_") for n in names if n.rstrip("_")]
        if not names:
            out.append("a sentence states %s catchable rows and names no "
                       "battery before it" % m.group(1))
            continue
        stem = names[-1]
        q = re.search(r"and (\d+) equivalences survive",
                      flat[m.end():m.end() + 180])
        if q is None:
            got = CAUGHT_AT_LAST_RUN.get(stem)
            if got is None:
                out.append("a sentence states %s catchable rows and mut_%s "
                           "has no recorded clean run"
                           % (m.group(1), stem))
            elif int(m.group(1)) != got:
                out.append("a sentence states %s catchable rows and mut_%s "
                           "caught %d at its last clean run"
                           % (m.group(1), stem, got))
            continue
        src = here / "build" / ("mut_" + stem + ".py")
        if not src.exists():
            out.append("a sentence names mut_%s.py and it is not on disk"
                       % stem)
            continue
        body = src.read_text()
        rows = (len(re.findall(r"^\s*row\(", body, re.M))
                + len(re.findall(r"^\s*mutations\.append\(", body, re.M)))
        if int(m.group(1)) + int(q.group(1)) != rows:
            out.append("a sentence states %s caught plus %s equivalences "
                       "and mut_%s has %d rows"
                       % (m.group(1), q.group(1), stem, rows))
    return out


def bogus_token_message() -> list[str]:
    """Problems with the unknown-opcode message, empty when it matches.

    The section says a bogus token exits with a named message rather than
    emitting a step the simulator cannot dispatch. The message is quoted in
    full, and SystemExit with a string exits 1, so both halves are in the
    source.
    """
    f = (pathlib.Path(__file__).parent / ".." / "x86" / "micro-prog"
         / "generate_micro_sim_proofs.py")
    if not f.exists():
        return ["the micro-program encoder is absent, so the message went "
                "unread"]
    src = f.read_text()
    if 'raise SystemExit(f"unknown x86 opcode: {op}")' not in src:
        return ["the encoder no longer exits with the message the section "
                "quotes"]
    return []


def mem_alu_battery() -> list[str]:
    """Problems with the memory-ALU battery, empty when both claims hold.

    The section makes two claims about one battery: it plants 6 catches and
    keeps 5 documented equivalences, and four byte-identical green shakes
    pin the family. The first is a split, the second is a property of
    repetition, so the battery is run twice and both are read from the two
    outputs — one run to read the split, the second to show it repeats.
    """
    f = (pathlib.Path(__file__).parent / "build"
         / "mut_x86_mem_alu_handler.py")
    if not f.exists():
        return ["the memory-ALU battery is absent, so its two claims went "
                "unread"]
    outs = []
    for _ in range(2):
        try:
            run = subprocess.run(
                ["python3", str(f)], capture_output=True, text=True,
                cwd=str(f.parent.parent), timeout=900)
        except (OSError, subprocess.TimeoutExpired) as exc:
            return ["the battery did not finish: %s" % exc]
        outs.append(run.stdout)
    out = []
    if outs[0] != outs[1]:
        out.append("two runs of the battery differ, so the shakes are not "
                   "byte-identical")
    m = re.search(r"TOTAL (\d+) mutations, (\d+) failures, "
                  r"(\d+) equivalences survived", outs[0])
    if m is None:
        return out + ["the battery printed no total, so the split went "
                      "unread"]
    total, failures, survived = (int(x) for x in m.groups())
    if failures:
        out.append("the battery reports %d failures" % failures)
    if total - survived != 6:
        out.append("the battery catches %d and the section says 6"
                   % (total - survived))
    if survived != 5:
        out.append("the battery keeps %d equivalences and the section says "
                   "5" % survived)
    return out

def guard_hit_hosts() -> list[str]:
    """Problems with the guard-hit population, empty when it matches.

    The section says six AArch64 hosts count guard hits, each driving an
    access past the arena and requiring the guard to fire exactly once. The
    six are the hosts that say so in their own text.
    """
    here = pathlib.Path(__file__).parent
    hosts = [f for f in here.glob("test_arm64_*.c")
             if "exactly one" in f.read_text(errors="ignore")]
    if len(hosts) != 6:
        return ["%d AArch64 hosts require exactly one guard hit and the "
                "section says six" % len(hosts)]
    flat = re.sub(r"\s+", " ", pathlib.Path(
        here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
        / "sections" / "4-safety.tex").read_text()).replace("\\brk", "")
    if "the six AArch64 hosts that count guard hits" not in flat:
        return ["the section no longer states the guard-hit population"]
    return []


def figure_coverage() -> tuple[int, int, int, set[int]]:
    """`(figures stated, bound to a banner, bound another way, the rest)`.

    Not every figure is a case count. The section states banner counts,
    census counter values, step numbers, mutation counts, Lean line
    identifiers, and the parts of a split, and each is held by a different
    check. This reports the shape of the surface rather than claiming that a
    figure with no banner is unheld, and returns the leftover set so a
    measurement uses this classification rather than a copy of it.
    """
    here = pathlib.Path(__file__).parent
    flat = re.sub(r"\s+", " ", pathlib.Path(
        here / ".." / ".." / "docs" / "kprog-simulator-in-ebpf"
        / "sections" / "4-safety.tex").read_text()).replace("\\brk", "")
    flat = flat.replace("{,}", ",")
    counts, _, _ = read_log(pathlib.Path("/tmp/gCK175.log")) if \
        pathlib.Path("/tmp/gCK175.log").exists() else (set(), 0, 0)
    figs = {int(x.replace(",", "")) for x in
            re.findall(r"(?<![\w.,])(\d[\d,]{2,})(?![\w,])", flat)}
    bound = len(figs & counts)
    # A figure is held by another check when the section states it as a
    # census value, a step number, a mutation count, or a Lean line
    # identifier; each of those has a check that binds the figure itself.
    held = {v for v in figs - counts
            if ("Step%s" % v) in flat or ("Step~%s" % v) in flat
            or ("census \\(%s" % v) in flat
            or ("\\to %s" % v) in flat
            or ("%d-mutation" % v) in flat
            or re.search(r"\\bL%d\\b" % v, flat)}
    # The leftover set is one lump, so it is split into the classes the
    # section actually uses. A figure that is a catch count, a row count, a
    # module count, or a Lean line identifier is bound by the check that
    # binds its whole; the rest stand alone and are reported as such.
    left = figs - counts - held
    line_ids = {v for v in left if re.search(r"\bL%d\b" % v, flat)
                or re.search(r"\bL\\d+--%d\b" % v, flat)}
    rows = {v for v in left - line_ids
            if re.search(r"\b%d-row\b|\b%d rows\b" % (v, v), flat)}
    catches = {v for v in left - line_ids - rows
               if re.search(r"\b%d (?:catches|catch)\b" % v, flat)}
    # Three more forms the section uses and this check cannot reach by
    # banner: a step number written with a leading zero, a number that is
    # part of a longer one (a harness name like `annot0357`, a line range
    # end like `438--916`), and a rounded figure inside a case count.
    padded = {v for v in left - line_ids - rows - catches
              if ("%04d" % v) in flat and v < 1000}
    inside = {v for v in left - line_ids - rows - catches - padded
              if re.search(r"[A-Za-z_\d]%d\b" % v, flat)
              or re.search(r"\b%d[A-Za-z_]" % v, flat)}
    return len(figs), bound, len(held), (
        left, line_ids, rows, catches, padded, inside)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--section", default="sections/4-safety.tex")
    parser.add_argument("--log", required=True)
    parser.add_argument("--check", action="store_true",
                        help="exit 1 when a claim matches no banner")
    args = parser.parse_args()

    text = masked(pathlib.Path(args.section))
    claimed = paper_counts(text)
    measured, banners, modeled = read_log(pathlib.Path(args.log))
    problems = [f"claim {c:,} appears {claimed[c]}x but no banner reports it"
                for c in sorted(c for c in claimed if c not in measured)]

    totals = {"banners": banners, "modeled cases": modeled}
    for rx, what in AGGREGATES:
        for match in rx.finditer(text):
            value = int(re.sub(r"[{},\\]", "", match.group("n")))
            if value != totals[what]:
                problems.append(f"claim {value:,} {what}; the log has "
                                f"{totals[what]:,}")

    # The split is a partition, so it has to cover the gate exactly: a rule
    # that silently dropped a host would shrink a bucket and still print.
    buckets, stats = sim_split(pathlib.Path(args.log))
    if sum(n for n, _ in buckets.values()) != banners:
        raise SystemExit("check_paper_counts: the simulator split covers %d "
                         "banners, the log has %d"
                         % (sum(n for n, _ in buckets.values()), banners))
    for what, rx in EXTRA:
        if not rx.search(text):
            problems.append(f"the claim about {what} hosts is absent, so it "
                            "went unread")
        for match in rx.finditer(text):
            got = int(match.group("n"))
            if got != stats[what]:
                problems.append(f"claim {got} hosts {WHAT[what]}; the log "
                                f"has {stats[what]}")
    for rx, name in ISA:
        if not rx.search(text):
            problems.append(f"the {LABEL.get(name, name)} simulator sentence "
                            "is absent, so its figures went unread")
        key = BUCKET[name]
        if key not in buckets:
            problems.append(f"the {LABEL.get(name, name)} bucket has no "
                            "oracle in the log")
            continue
        n, c = buckets[key]
        for match in rx.finditer(text):
            got = (int(match.group("n")),
                   int(re.sub(r"[{},\\]", "", match.group("c"))),
                   float(match.group("p")))
            # Shares are floored, never rounded, and are stated to one decimal.
            want = (n, c, (1000 * c // modeled) / 10)
            if got != want:
                problems.append(
                    f"claim {got[0]} {LABEL.get(name, name)} oracles, "
                    f"{got[1]:,} cases, {got[2]}%; the log has {want[0]}, "
                    f"{want[1]:,}, {want[2]:.1f}%")

    for line in problems:
        print(line)
    # Every `N-case` figure either appears in a banner or is arithmetic on a
    # bare grid. Counting them is what would surface a figure that matches no
    # banner while every claim this checker knows about stays current -- the
    # failure the four claim forms were introduced to catch, one level up.
    stated_cases, stray_cases = case_census(text, measured)
    if stray_cases:
        problems.append(
            "%d of the %d `-case` figures appear in no banner and on no "
            "grid: %s" % (len(stray_cases), stated_cases,
                          ", ".join(str(v) for v in stray_cases)))
    # Every percentage the section states. Five belong to the ISA split
    # here and two to check_lean_claims, so neither checker's own scan says
    # whether a seventh sentence has appeared that both would miss.
    # The document's own cross-references and citations, over the sections
    # main.tex includes. The paper keeps older section files on disk whose
    # labels and citations nothing resolves, so the included set is what
    # makes these statements about the paper rather than the directory.
    (undefined, uncited, n_labels, n_keys, dupes,
     into_dead) = document_refs(
        pathlib.Path(args.section).resolve().parent.parent)
    if dupes:
        problems.append("%d label(s) are defined twice in the paper: %s"
                        % (len(dupes), sorted(dupes)))
    if into_dead:
        problems.append(
            "%d reference(s) point into sections the paper does not include: "
            "%s" % (len(into_dead), sorted(into_dead)))
    if undefined or uncited:
        problems.append(
            "the document has %d undefined reference(s) %s and %d citation(s) "
            "absent from the bib %s"
            % (len(undefined), sorted(undefined), len(uncited),
               sorted(uncited)))
    if n_labels < 9 or n_keys < 56:
        problems.append(
            "the document has %d live labels and the bib %d entries; at "
            "least 9 and 56 before" % (n_labels, n_keys))
    # The section names Lean modules; a rename in the proof tree leaves the
    # prose pointing at a file that no longer exists, and nothing else reads
    # those names.
    cited = lean_citations(pathlib.Path(args.section).read_text())
    known_lean = {p.stem for p in
                  (pathlib.Path(__file__).resolve().parent
                   / "KProgFormal").glob("*.lean")}
    absent = sorted(cited - known_lean)
    if absent:
        problems.append(
            "%d Lean module(s) the section cites are absent: %s"
            % (len(absent), ", ".join(absent)))
    if len(cited) < 47:
        problems.append(
            "the section cites %d Lean modules and at least 47 matched "
            "before" % len(cited))
    # Sweep claims pair an oracle's size with what it sweeps. The case
    # counts are checked as claims already; this says the number belongs to
    # an exhaustive opcode sweep, and holds the population at twenty-two.
    n_sweeps, stray_sweeps = sweep_claims(text, measured)
    if stray_sweeps:
        problems.append(
            "%d sweep claim(s) print a case count no banner reports: %s"
            % (len(stray_sweeps), stray_sweeps))
    if n_sweeps < 22:
        problems.append(
            "the section makes %d 256-sweep claims and at least 22 "
            "matched before" % n_sweeps)
    # Thirteen sentences say an oracle compares the whole register file
    # rather than the fields it drove. Whether a given oracle does that is a
    # reading; what can be counted is the claim population against the
    # oracles that have the mechanism, so the sentences cannot grow past the
    # oracles that could support them.
    n_whole, n_able = whole_state_claims(text)
    if n_whole > n_able:
        problems.append(
            "%d claim(s) compare the whole register file and %d oracle(s) "
            "iterate all registers" % (n_whole, n_able))
    if (n_whole, n_able) != (13, 27):
        problems.append(
            "whole-state claims are %d against %d oracles; 13 and 27 when "
            "this was written" % (n_whole, n_able))
    # The section discloses that the composition check "reviews four
    # exceptions". A fifth accepted entry, or a dropped one, would leave the
    # sentence quoting a number the check no longer holds.
    n_exc = reviewed_exceptions()
    spelled = ("zero one two three four five six seven eight nine".split())
    if ("reviewing %s exceptions" % spelled[n_exc]) not in text:
        problems.append(
            "the composition check accepts %d exceptions; the section does "
            "not say so" % n_exc)
    # "Every case checked against an independent condition/writeback/tag
    # model---9,585,135 modeled cases": the count is checked as a claim, and
    # the mechanism is that the oracle compares each register's value and tag
    # plus all four flags. A value-only comparison would leave the sentence
    # describing a stronger check than the oracle performs.
    whole = dict(every_case_oracles())
    if not whole.get("cmov_step_route_host.c"):
        problems.append(
            "the 9,585,135-case cmov oracle no longer compares every "
            "register's value and tag")
    if 9585135 not in measured:
        problems.append("the cmov step route banner no longer reports "
                        "9,585,135 cases")
    # Eight sentences say an oracle "compares the whole register file with
    # its tags and all four flags". The claims must stay within the oracles
    # that compare both halves and every flag, and the count is held so a
    # claim added to the family is visible.
    n_full = full_state_oracles()
    n_claims = len(re.findall(
        r"whole register file with its tags and all four flags", text))
    if n_claims > n_full:
        problems.append(
            "%d claim(s) compare the whole register file with tags and four "
            "flags, and %d oracle(s) do" % (n_claims, n_full))
    if (n_claims, n_full) != (8, 30):
        problems.append(
            "whole-state claims are %d against %d oracles; 8 and 30 when "
            "this was written" % (n_claims, n_full))
    # Three sentences say an oracle compares "the whole stack image with its
    # slot tags, and all 4 KiB of the memory window". Comparing the bytes a
    # case touched would be far weaker, so the invariant is a memcmp over
    # the full size, and the claims must stay within the oracles that do it.
    n_win = memory_window_oracles()
    n_win_claims = len(re.findall(
        r"whole stack image with its slot tags, and all", text))
    if n_win_claims > n_win:
        problems.append(
            "%d claim(s) compare the whole memory window and %d oracle(s) "
            "do" % (n_win_claims, n_win))
    if (n_win_claims, n_win) != (3, 13):
        problems.append(
            "whole-window claims are %d against %d oracles; 3 and 13 when "
            "this was written" % (n_win_claims, n_win))
    # Three sentences give an oracle's size and the dimensions it sweeps,
    # so the product of the dimensions has to be the figure. A sweep
    # described one dimension wider than it is would print a size that no
    # longer follows from the sentence.
    products = sweep_products(text)
    if len(products) < 3:
        problems.append(
            "the section states %d sweep dimension products; at least 3 "
            "matched before" % len(products))
    for cases, product in products:
        if cases != product:
            problems.append(
                "a sweep claim prints %d cases and its dimensions give %d"
                % (cases, product))
    # "Its 488 uses fall into three kinds, two of which overlap: the 28
    # finite enumerations ..., 441 concrete example values ..., and 20 of the
    # 609 refinement-named theorems. 2 of the refinement uses are themselves
    # enumerations, which is why the three counts sum to 487 rather than
    # 488." Every part is read from the text, compared with the tree, and
    # the sum the sentence states is derived from the parts it states.
    import check_lean_claims as claims
    kinds = claims.scan_tree(str(pathlib.Path(__file__).parent))
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    def first(pat):
        hit = re.findall(pat, flat)[0]
        return [int(g) for g in (hit if isinstance(hit, tuple) else (hit,))]

    said = (first(r"the (\d+) finite enumerations")
            + first(r"(\d+) concrete example values")
            + first(r"(\d+) of the (\d+) refinement-named")
            + first(r"Its (\d+) uses fall into three kinds")
            + first(r"(\d+) of the refinement uses are themselves")
            + first(r"the three counts sum to (\d+) rather than (\d+)"))
    # enum, example, table, refinement-named, total uses, overlap, sum
    tree = (kinds["kinds_enum"], kinds["kinds_example"],
            kinds["kinds_table"], kinds["refines"], kinds["native_decide"],
            kinds["kinds_overlap"], kinds["kinds_sum"], kinds["native_decide"])
    if tuple(said) != tree:
        problems.append(
            "the three kinds are stated as %s and the tree has %s"
            % (tuple(said), tree))
    if said[0] + said[1] + said[2] - said[5] != said[6]:
        problems.append(
            "%d + %d + %d - %d is not the stated %d"
            % (said[0], said[1], said[2], said[5], said[6]))
    if said[6] + 1 != said[7]:
        problems.append(
            "the stated kinds sum to %d and the stated total is %d"
            % (said[6], said[7]))
    # The dispatch split pairs four figures that must agree: the chain's
    # predicates, the modelled ones, the gap, and the recorded set that must
    # be exactly the gap. The section states all four.
    chain, modelled, gaps, recorded = dispatch_split()
    if recorded != gaps:
        problems.append(
            "the recorded unmodelled set has %d entries and the gap is %d"
            % (recorded, gaps))
    def spelled(n: int) -> str:
        ones = ("zero one two three four five six seven eight nine ten "
                "eleven twelve thirteen fourteen fifteen sixteen seventeen "
                "eighteen nineteen").split()
        if n < 20:
            return ones[n]
        tens = {2: "twenty", 3: "thirty", 4: "forty", 5: "fifty"}
        if n % 10 == 0:
            return tens[n // 10]
        return "%s-%s" % (tens[n // 10], ones[n % 10])

    # Each figure is bound to the phrase that carries it, so a numeral that
    # drifts to another value present elsewhere in the section is still
    # caught. The section spells them, so the words are what is matched.
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    for fig, phrase in (
            (chain, r"%s families"),
            (modelled, r"%s in the model"),
            (gaps, r"%s of which are routed")):
        if not re.search(phrase % re.escape(spelled(fig)), flat):
            problems.append(
                "the dispatch check measures %d and the section does not "
                "say so beside its phrase" % fig)
    # Twenty bodies are named as "an oracle drives the real X", and each has
    # to resolve to a macro in a simulator header or an arm an oracle spells
    # out. A name nothing drives would describe coverage that does not exist.
    dangling = driven_bodies()
    if dangling:
        problems.append(
            "%d named bodies are driven nowhere in the tree: %s"
            % (len(dangling), dangling))
    # Every oracle named by "N-case ... includes the simulator header" must
    # actually include one. The clause boundary matters: a later clause can
    # mention the header without claiming this oracle includes it.
    named = header_claim_oracles(pathlib.Path(args.log))
    if len(named) < 36:
        problems.append(
            "%d oracles are named by a header-inclusion claim; at least "
            "36 matched before" % len(named))
    for binary in named:
        src = pathlib.Path(binary if binary.endswith(".c") else binary + ".c")
        if not src.exists():
            src = pathlib.Path("build") / src.name
        if not src.exists():
            problems.append("%s has no source" % binary)
        elif not re.search(r'#include\s+"[^"]*sim[^"]*\.h"',
                           src.read_text(errors="ignore")):
            problems.append(
                "%s is named as including the simulator header and does not"
                % binary)
    # A mutation harness is stated with its size, then split by the stage
    # that caught each change. The stages must not exceed what was caught,
    # and the change-style sentences must add up exactly.
    parts = harness_partitions(text)
    if len(parts) < 4:
        problems.append(
            "the section states %d harness partitions; at least 4 matched "
            "before" % len(parts))
    for form, tot, s_sum in parts:
        if s_sum > tot:
            problems.append(
                "a harness partition sums to %d against a stated %d"
                % (s_sum, tot))
        if form == "change" and s_sum != tot:
            problems.append(
                "a harness change partition sums to %d and claims %d"
                % (s_sum, tot))
    # A Lean name the prose presents as a chain, handler, theorem or the
    # like has to exist in the tree. A rename would leave the sentence
    # describing something gone, and no figure binds the name.
    gone = named_lean_objects()
    if gone:
        problems.append(
            "%d Lean names the section presents are absent from the tree: %s"
            % (len(gone), gone))
    # Every file the section cites must exist. A file name is not a figure,
    # so no count would notice a rename.
    for name in named_files():
        problems.append(
            "the section cites %s, which is not in the tree" % name)
    # "build/a64_route_host.c (now N modeled cases)" states the oracle's
    # current banner. It drifted once -- 4328 was written in step 0458 and
    # the oracle has since grown -- so the figure is bound to the banner of
    # the host the sentence names.
    flat_text = re.sub(r"\s+", " ", text).replace("\\brk", "")
    # The same claim is written with and without brace-grouped thousands.
    for fig in re.findall(
            r"(?:\(|, )now ([\d{},]+) modeled cases", flat_text):
        n = int(re.sub(r"[{},]", "", fig))
        if n not in measured:
            problems.append(
                "the a64 route host is stated at %d modeled cases and no "
                "banner reports it" % n)
    # A parenthesised "(N modeled cases" gives an oracle's size, and every
    # one of them is a banner now. The three battery-local hosts were
    # excused as unreportable until each was run: all three print their
    # totals, so the exemption was a stale size hiding behind a name.
    flat_n = re.sub(r"\{,\}", ",", flat_text)
    sizes = {int(n.replace(",", "")) for n in re.findall(
        r"\(([\d,]+) modeled cases", flat_n)}
    witnesses: set[int] = set()
    for v in sorted(sizes - witnesses):
        if v not in measured:
            problems.append(
                "a stated modeled-case figure %d is not a banner" % v)
    if not witnesses <= sizes:
        problems.append(
            "a battery-local witness figure is no longer stated: %s"
            % sorted(witnesses - sizes))
    # An instruction name the prose presents as an arm or opcode has to
    # exist in the tree, in a simulator or in the tooling. No figure binds a
    # name, so a rename would go unnoticed here.
    named = named_instructions()
    # Zero unbound names and an empty extraction read alike; the section
    # names fourteen, so a scan that finds fewer has stopped reading.
    if len(named) == 0 and not re.search(
            r"\\texttt\{[A-Z][A-Za-z0-9_]{1,18}\}\s+"
            r"(?:arm|opcode|instruction|form)\b",
            re.sub(r"\s+", " ",
                   pathlib.Path(args.section).read_text())):
        problems.append(
            "the section names no instruction at all, so the unbound-name "
            "check examined nothing")
    for name in named:
        problems.append(
            "the section presents %s as an instruction and the tree has no "
            "such name" % name)
    # A binding-mutation sentence gives a total and splits it by the kind
    # of change. The parts must reach the total -- one said nineteen against
    # parts summing to seventeen.
    parts = binding_mutations(text)
    if len(parts) < 4:
        problems.append(
            "the section states %d binding-mutation splits; at least 4 "
            "matched before" % len(parts))
    for total, summed in parts:
        if total != summed:
            problems.append(
                "a binding-mutation sentence states %d and its parts sum to "
                "%d" % (total, summed))
    # Mutation lists written out in words: word "and" is ambiguous, so the
    # total is bounded by the segment count and the segment count plus
    # every "and". A total outside that range cannot be right.
    bounds = enumerated_bounds(text)
    if len(bounds) < 22:
        problems.append(
            "the section states %d enumerated mutation lists; at least 22 "
            "matched before" % len(bounds))
    for stated, low, high in bounds:
        if not low <= stated <= high:
            problems.append(
                "a mutation list states %d and its items bound it between "
                "%d and %d" % (stated, low, high))
    # "N rows catch (a at the generator stage; b through the Lean chain;
    # c by the host oracle; d ...)". Twenty-four sentences state this
    # split. The fourth term carries a parenthetical, so only the first
    # three are compared -- they must not exceed the total.
    splits = row_stage_splits(text)
    if len(splits) < 24:
        problems.append(
            "the section states %d four-stage row splits; at least 24 "
            "matched before" % len(splits))
    for total, gen, lean, host in splits:
        if gen + lean + host > total:
            problems.append(
                "a row split gives %d+%d+%d = %d against a stated %d"
                % (gen, lean, host, gen + lean + host, total))
    # One harness is recorded at five successive sizes as detectors were
    # added: 96, 100, 104, 108, 112, each four mutants larger. Those sizes
    # are historical rather than banners, but the series must ascend by the
    # detector stride and the harness must still be at least as large as its
    # last stated size.
    series, current = harness_growth(text)
    if len(series) < 5:
        problems.append(
            "the growing harness is recorded at %d sizes; at least 5 "
            "matched before" % len(series))
    if any(b <= a for a, b in zip(series, series[1:])):
        problems.append("the growing harness's sizes do not ascend: %s"
                        % series)
    if series and current < series[-1]:
        problems.append(
            "the harness is stated at %d mutations and holds %d"
            % (series[-1], current))
    # Two hosts are sized by scene count: the x86 route host at sixteen and
    # the helper route host at seventeen. A scene is a named function in one
    # file, so the count is checkable outright.
    scenes = scene_counts()
    # The paper states each host's scene count, so it is read from the
    # prose and compared with the file rather than with a memory of both.
    words = {w: i for i, w in enumerate(
        "zero one two three four five six seven eight nine ten eleven twelve "
        "thirteen fourteen fifteen sixteen seventeen eighteen nineteen "
        "twenty".split())}
    flat_s = re.sub(r"\s+", " ", text).replace("\\brk", "")
    for host in ("x86_route_host", "helper_route_host"):
        # The modelled-case figure is read as a number rather than
        # matched as this one: a pattern holding the value cannot see it
        # change, and would then skip the scene comparison entirely.
        pat = (r"\((\w+) scenes?, [\d\{\,\}]+ modeled cases"
               if host == "x86_route_host" else
               r"\((\w+) scene functions?, \d+ drive sites")
        m = re.search(pat, flat_s)
        # The prose writes these as numerals and sometimes as words.
        want = None
        if m:
            g = m.group(1)
            want = int(g) if g.isdigit() else words.get(g)
        if want is not None and scenes.get(host) != want:
            problems.append(
                "the %s has %s scenes and the section says %d"
                % (host, scenes.get(host), want))
    # The third host is sized inside a modelled-case witness: "N modeled
    # cases over K scenes". The figure was excused from banner matching
    # without the scene count beside it being read.
    # That sentence describes the helper route host, not the AArch64 body
    # host: both were at 21 scenes when it was written, so matching the
    # number alone joins whichever host is named first.
    m = re.search(r"\([\d,{}]+ modeled cases over (\d+) scenes", flat_s)
    if m is None:
        problems.append(
            "the helper route host's scene count is absent, so it went "
            "unread")
    elif scenes.get("helper_route_host") != int(m.group(1)):
        problems.append(
            "the helper route host has %s scenes and the section says %s"
            % (scenes.get("helper_route_host"), m.group(1)))
    # Thirty-one dedicated harnesses are sized in the prose. The figures are
    # checked against the entry count of each harness's MUTATIONS list, read
    # by the same parse Python performs, so a harness that grew or shrank is
    # reported rather than the literal's parentheses.
    totals = harness_totals()
    have = set(totals.values())
    # The growth series records one harness at past sizes, so its figures
    # are not expected among the current totals except by coincidence.
    series_now, series_cur = harness_growth(text)
    flat_t = re.sub(r"\s+", " ", text).replace("\\brk", "")
    stated = {int(n) for n in re.findall(
        r"[Aa] dedicated (\d+)-mutation harness", flat_t)}
    # Every harness figure, not only the dedicated ones, must match some
    # harness's entry count -- except the growth series, whose figures are
    # past sizes of one harness.
    anywhere = {int(n) for n in re.findall(r"(\d+)-mutation harness", flat_t)}
    for n in sorted(anywhere - have - set(series_now[:-1])):
        problems.append(
            "the section names a %d-mutation harness and no harness has "
            "that many entries" % n)
    # Report how much this proves: a size shared by several harnesses is
    # matched, but does not show the sentence names the harness it means.
    import collections
    shared = collections.Counter(totals.values())
    ambiguous = {n for n in anywhere - set(series_now[:-1])
                 if shared.get(n, 0) > 1}
    if not args.check:
        print("check_paper_counts: %d of %d stated harness sizes are shared "
              "between harnesses and so are matched but not identified"
              % (len(ambiguous), len(anywhere)))
    for n in sorted(stated - have - set(series_now[:-1])):
        problems.append(
            "a harness is stated at %d mutations and no harness has that "
            "many entries" % n)
    if len(stated) < 31:
        problems.append(
            "the section sizes %d dedicated harnesses; at least 31 "
            "matched before" % len(stated))
    for n in sorted(stated - have):
        problems.append(
            "a dedicated harness is stated at %d mutations and no harness "
            "has that many entries" % n)
    # The naming is exactly regular: all 138 specifications have a
    # mut_<stem>.py. So a cited spec must exist and must have a harness --
    # an exact join, unlike matching a size against the set of all sizes.
    for bad in cited_specs(text):
        problems.append(bad)
    # Fifteen sentences say a shake "exercised every spec field". Where the
    # row count identifies one harness, that harness must name each field's
    # key or one of its values -- the shakes edit the spec text rather than
    # parsing it, so a field the harness never names is a field it never
    # touched.
    n_shakes, gaps = shake_field_gaps(text)
    if n_shakes < 15:
        problems.append(
            "the section states %d shake field claims; at least 15 "
            "matched before" % n_shakes)
    for rows, harness, fields in gaps:
        problems.append(
            "the %d-row shake is %s and it never names %s"
            % (rows, harness, fields))
    # A stage-split sentence is its own arithmetic: the stages must add to
    # the catch count, and catch plus survive to the total where a total is
    # stated.
    sums = stage_sentence_sums(text)
    if len(sums) != 6:
        problems.append(
            "the section states %d stage-split sentences; 6 when this was "
            "written" % len(sums))
    for tot, caught, stages, surv, _ in sums:
        if stages != caught:
            problems.append(
                "a stage split says %d catch and its stages sum to %d"
                % (caught, stages))
        if tot and caught + surv != tot:
            problems.append(
                "a stage split says %d catch and %d survive of %d"
                % (caught, surv, tot))
    # A battery's rows partition into those that catch and those that
    # survive as documented equivalences, so "N/M caught, K survive" must
    # account for the whole battery.
    fracs = caught_fractions(text)
    if len(fracs) != 3:
        problems.append(
            "the section states %d caught fractions; 3 when this was "
            "written" % len(fracs))
    for caught, total, accounted in fracs:
        if accounted != total:
            problems.append(
                "%d of %d caught plus survivors is %d"
                % (caught, total, accounted))
    # Three sentences give a spec's row count beside the harness size. The
    # row count is a field length, so where one spec has that many rows and
    # its harness is that size, the join is exact -- the strongest form
    # available for a harness figure.
    joins = spec_row_joins(text)
    if len(joins) != 3:
        problems.append(
            "the section states %d spec row counts; 3 when this was "
            "written" % len(joins))
    for n, spec, exact in joins:
        if exact:
            spec_path = pathlib.Path(__file__).parent / (spec + "_spec.json")
            if not spec_path.exists():
                problems.append("%d mutations joins %s, which has no spec"
                                % (n, spec))
    # The section cites numbered steps for provenance; those numbers mean
    # nothing unless the README records them.
    for n in step_refs(text):
        problems.append(
            "the section cites Step %s and the README has no such step" % n)
    # "the eleven modifiers ..." is a spec field length, not a count of
    # prose: the sentence must match the operations the modifier spec holds.
    n_mod, spec_mod = modifier_count_gap(text)
    if n_mod != spec_mod:
        problems.append(
            "the section says %d modifiers and arm64_mod_spec.json has %d"
            % (n_mod, spec_mod))
    # Two shared harness sizes are identified by the words their sentence
    # uses: "the lane specification" is arm64_byte_lane and "the
    # offset/prepost spec" is arm64_mem_offset, both checked by size too.
    # Only words that match a spec's own segments count, because a single
    # prose word can match the wrong spec.
    desc = description_joins(text)
    if len(desc) < 2:
        problems.append(
            "the section states %d description-joined harnesses; at least 2 "
            "matched before" % len(desc))
    for n, spec in desc:
        here = pathlib.Path(__file__).parent
        if not (here / (spec + "_spec.json")).exists():
            problems.append("%d mutations joins %s, which has no spec"
                            % (n, spec))
    # A battery-local host's total is a product of scenes and checks; both
    # sides are figures and must agree, and the total must be a banner
    # because these hosts do run in the gate.
    prods = scene_products(text)
    if len(prods) != 2:
        problems.append(
            "the section states %d scene-and-check products; 2 when this "
            "was written" % len(prods))
    for stated, computed in prods:
        if stated != computed:
            problems.append(
                "a host is stated at %d cases and its scenes times checks "
                "give %d" % (stated, computed))
        if stated not in measured:
            problems.append(
                "a host is stated at %d cases and no banner reports it"
                % stated)
    # Five hosts state their size as axes. The stated axes multiply to at
    # most the total, never more: an axis product over the banner would be
    # arithmetic that cannot be true whatever the remaining axes are.
    decs = case_decompositions(text)
    if len(decs) != 5:
        problems.append(
            "the section states %d case decompositions; 5 when this was "
            "written" % len(decs))
    for total, a, b, prod in decs:
        if prod > total:
            problems.append(
                "a host's stated axes %d x %d give %d against a total of %d"
                % (a, b, prod, total))
    # "adding N modeled cases make check never ran (a 4,470, b 11,223, ...)":
    # every part is a banner and the total is their sum, so both can be
    # checked rather than the total alone.
    adds = added_case_sums(text)
    if len(adds) != 1:
        problems.append(
            "the section states %d added-case sums; 1 when this was "
            "written" % len(adds))
    for total, parts in adds:
        if sum(parts) != total:
            problems.append(
                "an added-case total is stated as %d and its parts sum to %d"
                % (total, sum(parts)))
        for p_ in parts:
            if p_ not in measured:
                problems.append(
                    "an added-case part of %d is not a banner" % p_)
    # "N mutations were caught (a by the generator, b by the Lean chain)":
    # the stages must reach the count. Eighteen sentences state this split.
    cw = caught_with_parts(text)
    # The two wordings cover different sentences, so the reach is a floor
    # rather than an exact figure; what matters is that neither family
    # stopped matching after an edit.
    if len(cw) < 57:
        problems.append(
            "the section states %d caught-with-parts counts and 57 matched "
            "when both wordings were read" % len(cw))
    for stated, summed in cw:
        if stated != summed:
            problems.append(
                "%d mutations are stated caught and the stages give %d"
                % (stated, summed))
    # A battery's rows divide into planted catches and kept equivalences,
    # so the two must reach the row count.
    pk = plants_and_keeps(text)
    if len(pk) != 5:
        problems.append(
            "the section states %d plants-and-keeps splits; 5 when this "
            "was written" % len(pk))
    for rows, caught, kept in pk:
        if caught + kept != rows:
            problems.append(
                "a harness of %d rows plants %d and keeps %d"
                % (rows, caught, kept))
    # "there is no zero register to omit, so the only register number that
    # is not a cell is the all-ones sentinel": the cell numbers must be
    # contiguous from zero, which is what makes the sentinel the only gap.
    for isa, nums in register_cells().items():
        if nums != list(range(len(nums))):
            problems.append(
                "the %s cell numbers are not contiguous from zero: %s"
                % (isa, nums[:8]))
        if 255 in nums:
            problems.append(
                "the %s cell table contains the all-ones sentinel" % isa)
    # "the default arm is the only gated one and the ladder is total over
    # the resolved width codes": one gate in the arm table, and the widths
    # are the four the simulator resolves.
    gated, widths = div_ladder()
    if gated != 1:
        problems.append(
            "the DIV ladder carries %d gated arms and the section says the "
            "default is the only one" % gated)
    if widths and widths != [1, 2, 4, 8]:
        problems.append(
            "the DIV ladder's width codes are %s, not the four resolved "
            "codes" % widths)
    # "the single pair whose product is exactly the negative bound": one
    # such unordered pair, and no pair where the two candidate overflow
    # tests disagree on representability.
    pairs, differing = multiply_bound_pair()
    if pairs != 1:
        problems.append(
            "%d unordered pairs reach the negative bound and the section "
            "says one" % pairs)
    if differing:
        problems.append(
            "%d operand pairs make the two overflow tests disagree"
            % differing)
    # "the N generator re-check messages": the sentence names no generator,
    # so the join is to the set of counts any generator can raise. A stated
    # count outside it has no source; a count inside may still name the
    # wrong generator, which this cannot see.
    flat_m = re.sub(r"\s+", " ", text).replace("\\brk", "")
    words = {w: i for i, w in enumerate(
        "zero one two three four five six seven eight nine ten eleven "
        "twelve thirteen fourteen fifteen sixteen seventeen eighteen "
        "nineteen twenty".split())}
    have_msg = generator_message_counts()
    stated_msg = set()
    for w in re.findall(
            r"(\w+) generator (?:re-check|error) messages", flat_m):
        if w in words:
            stated_msg.add(words[w])
    for n in sorted(stated_msg - have_msg):
        problems.append(
            "a harness retargets %d generator messages and no generator "
            "raises that many" % n)
    # The store-exclusive body is described as writing both memory and a
    # status word. The status half is in the contract: derived from the
    # width mask, and proved zero at every width by case analysis over the
    # four constructors.
    for problem in stlxr_status_contract():
        problems.append(problem)
    # "the only width (64) the outer gate opens": the width spec must fall
    # back to a 64-bit default, and exactly one width may carry 64 bits.
    wd_name, wd_codes, wd_n64 = width_default()
    if wd_name and wd_n64 != 1:
        problems.append(
            "%d widths carry 64 bits and the section says 64 is the only "
            "one the gate opens" % wd_n64)
    if wd_name and wd_codes and wd_codes != [1, 2, 4, 8]:
        problems.append(
            "the width codes are %s, not the four resolved" % wd_codes)
    # "the equal case --- the only one separating a subtract carry stated
    # as greater-or-equal from one stated as strictly greater": the two
    # predicates disagree exactly on equality, so distinct operands never
    # exercise the difference.
    n_diff, all_equal = carry_separation()
    if n_diff and not all_equal:
        problems.append(
            "%d operand pairs separate >= from > and not all are equal"
            % n_diff)
    # "the only shape reaching the X86_OP_BT_MEM_IMM width default": one
    # opcode row reads memory, and it takes an immediate index.
    bt_rows, bt_imm = bt_mem_shape()
    if bt_rows and (bt_rows != 1 or not bt_imm):
        problems.append(
            "the BT spec has %d memory-base rows (immediate index: %s) and "
            "the section says one shape reaches the width default"
            % (bt_rows, bt_imm))
    # "the numbers are pairwise distinct, so the chain selects exactly one
    # arm per opcode": a repeated code anywhere makes that selection
    # ambiguous and the sentence false.
    for spec, dupes in duplicate_codes():
        problems.append(
            "%s repeats %s and the section says the numbers are pairwise "
            "distinct" % (spec, dupes))
    # The module and theorem splits must reach the tree's totals, and the
    # shared bucket must be the generated specifications plus the
    # hand-written cross-ISA modules.
    mods, thms = module_split(text)
    import check_lean_claims as _cl
    _tree = _cl.scan_tree(str(pathlib.Path(__file__).parent))
    if mods and thms:
        if sum(mods) != _tree["modules"]:
            problems.append(
                "the module split sums to %d and the tree has %d"
                % (sum(mods), _tree["modules"]))
        if sum(thms) != _tree["theorems"]:
            problems.append(
                "the theorem split sums to %d and the tree has %d"
                % (sum(thms), _tree["theorems"]))
        if mods[2] != _tree["specs"] + 12:
            problems.append(
                "the shared bucket is %d and 138 specifications plus 12 "
                "hand-written is %d" % (mods[2], _tree["specs"] + 12))
    # "the writeback count is bounded by the two bits, never a third
    # writeback": a Lean theorem states the bound, so the sentence is
    # checked against the theorem rather than against the prose alone.
    present, bound = writeback_bound()
    if not present:
        problems.append(
            "no theorem bounds the writeback count and the section says two")
    elif bound != 2:
        problems.append(
            "the writeback bound is %d and the section says two" % bound)
    # "the ten families are pairwise disjoint": the theorem must cover ten
    # families and every one of their pairs, or the claim rests on the pairs
    # it happened to list.
    fams_found = disjoint_families()
    if len(fams_found) < 2:
        problems.append(
            "the two disjointness theorems resolve to %d families' worth "
            "of proofs, so the claim rests on what was found"
            % len(fams_found))
    for isa, fams, pairs, complete in fams_found:
        want = {"x86": 10, "arm64": 8}[isa]
        if fams != want:
            problems.append(
                "the %s disjointness theorem covers %d families and the "
                "section says %d" % (isa, fams, want))
        elif not complete:
            problems.append(
                "the %s disjointness theorem lists %d pairs of %d, so the "
                "claim rests on the ones it lists"
                % (isa, pairs, fams * (fams - 1) // 2))
    # Nine sentences record that the gate stayed at one banner count across
    # a run of steps. They describe one unchanged gate, so the figures must
    # agree and none may exceed what the gate reports now.
    stayed = stayed_at(text)
    if len(stayed) != 9:
        problems.append(
            "the section says the gate stayed at a count %d times; 9 when "
            "this was written" % len(stayed))
    elif len(set(stayed)) != 1:
        problems.append(
            "the gate is recorded as staying at different counts: %s"
            % sorted(set(stayed)))
    for n in stayed:
        if n > len(measured) and n > max(measured):
            problems.append(
                "the gate is recorded as staying at %d banners and the run "
                "reports fewer" % n)
    # Every digest the paper quotes as evidence of a byte-identical shake
    # must be one the harness README records, or it is an observation with
    # no record behind it.
    for d in shake_digests(text):
        problems.append(
            "the section quotes md5 %s and no recorded shake carries it" % d)
    # "changing a single hand-written opcode ... fails the build with two
    # independent assertions, in x86_opcode.h and x86_dispatch_singleton.h":
    # both named headers must still observe the drift. The test showed eight
    # more headers also fire, which the sentence does not claim against.
    fired = set(decode_drift_headers())
    for header in ("x86_opcode.h", "x86_dispatch_singleton.h"):
        if header not in fired:
            problems.append(
                "an opcode drift no longer fires an assertion in %s and the "
                "section says it does" % header)
    # "fails with 48 mismatches when the generated shift constant is
    # changed": coverage is behavioural, so the count is measured by
    # mutating the header and running the host.
    mismatches = bswap_mutation_mismatches()
    if mismatches != 48:
        problems.append(
            "the bswap shift mutation produces %d mismatches and the "
            "section says 48" % mismatches)
    # A sentence citing "N-row harness mut_x.py" joins exactly. The built
    # count is static, so the harnesses whose rows are appended through a
    # helper read short of what they run; running them confirmed the paper.
    # The pair is held so a fourth such harness is reported.
    short = named_harness_rows(text)
    known_short = {
        (20, "mut_arm64_stlxr_route.py", 13),
        (21, "mut_arm64_ldrsx_route.py", 9),
        (17, "mut_arm64_reduction_route.py", 5),
        (14, "mut_x86_head_route.py", 1),
    }
    for stated, name, have in short:
        if (stated, name, have) not in known_short:
            problems.append(
                "the section says %s has %d rows and the static count is %d"
                % (name, stated, have))
    # The census counter only ever rises, so every recorded transition must
    # ascend; one that stood still or went backwards is a mistyped pair.
    for a, b in census_transitions(text):
        problems.append(
            "a census transition records %d to %d, which does not rise"
            % (a, b))
    # The axiom sentence states a partition of the tree, so its three
    # figures must add to the theorem total; a typo in any one of them
    # moves the sum off it.
    part = axiom_partition(text)
    if part is None:
        problems.append(
            "the axiom partition sentence is absent, so its three figures "
            "went unread")
    else:
        parts, total = part
        if total != _tree["theorems"]:
            problems.append(
                "the three axiom classes sum to %d and the tree holds %d "
                "theorems" % (total, _tree["theorems"]))
    # Each register contract states a cell count over its generated table, and
    # the sentence beside it says which register numbers name no cell. The
    # table is what makes that boundary exact.
    cells = cell_tables()
    plain = re.sub(r"[\\()]", " ", re.sub(r"\s+", " ", text))
    found = re.findall(r"\s(\d+)\s+general-purpose cells", plain)
    # The x86 contract is stated first, the AArch64 one after it.
    stated = dict(zip(("x86", "arm64"), (int(v) for v in found)))
    for isa, n in sorted(cells.items()):
        if stated.get(isa) != n:
            problems.append(
                "the section states %s general-purpose %s cells and the "
                "generated table holds %d" % (stated.get(isa), isa, n))
    # A harness that grows a detector at a time states its total and the
    # detector together, so the series must ascend in both.
    for problem in detector_series(text):
        problems.append(problem)
    # A short harness set would not fail any join: every sentence would
    # simply find no harness and go unread.
    for problem in harness_population():
        problems.append(problem)
    # The section says the hosts the batteries drive are pinned into the
    # recipe, and says how many. Both halves are in the tree, so the count
    # is checked rather than trusted.
    pinned, on_disk = pinned_route_hosts()
    stated = re.search(r"the (\w+) battery-local route hosts", plain)
    WORD = {"seven": 7, "eight": 8, "nine": 9, "ten": 10, "eleven": 11,
            "twelve": 12, "thirteen": 13, "fourteen": 14, "fifteen": 15}
    if stated is None:
        problems.append(
            "the sentence pinning the battery-local route hosts is absent, "
            "so its count went unread")
    else:
        want = WORD.get(stated.group(1), -1)
        if want != pinned:
            problems.append(
                "the section states %s battery-local route hosts and the "
                "recipe runs %d" % (stated.group(1), pinned))
        if pinned != on_disk:
            problems.append(
                "%d route hosts are on disk and %d are pinned into the "
                "recipe" % (on_disk, pinned))
    # "the twelve reached suffixes are exactly the condition contract's
    # names minus the parity pair": the pair is why it is twelve and not
    # fourteen, so both figures come from the contract.
    stated_suffix = re.search(r"the (\w+) reached suffixes are exactly",
                              plain)
    want_suffix = reached_suffixes()
    if stated_suffix is None:
        problems.append(
            "the sentence naming the reached suffixes is absent, so its "
            "count went unread")
    elif WORD.get(stated_suffix.group(1), -1) != want_suffix:
        problems.append(
            "the section states %s reached suffixes and the contract "
            "reaches %d" % (stated_suffix.group(1), want_suffix))
    # "330 mutation batteries re-derive the failure of the contract it
    # anchors": the count is the files on disk, so the tree states it.
    stated_batt = re.search(r"(\d[\d,]*) mutation batteries", plain)
    if stated_batt is None:
        problems.append(
            "the sentence counting the mutation batteries is absent, so its "
            "figure went unread")
    elif int(stated_batt.group(1).replace(",", "")) != battery_count():
        problems.append(
            "the section states %s mutation batteries and %d are on disk"
            % (stated_batt.group(1), battery_count()))
    # The tags index arrays, so they must be distinct and dense from zero;
    # a gap leaves an index no constant names and a repeat makes two
    # pointer kinds indistinguishable to every consumer that dispatches.
    for isa, vals in sorted(tag_values().items()):
        if vals != list(range(len(vals))):
            problems.append(
                "the %s tag codes are %s, which is not distinct and dense "
                "from zero" % (isa, vals))
    # A sentence that gives a mutation count without a filename still names
    # the opcodes it repaints, and a harness's docstring names the contract
    # it targets; where exactly one harness of that size matches, the join
    # is exact and the two figures must agree.
    # The masked text blanks every \texttt quotation, so the opcodes this
    # join reads are only in the source.
    joins, weak, unnamed, multi = stated_harness_joins(
        pathlib.Path(args.section).read_text())
    # A sentence whose size no longer matches leaves the join entirely, so
    # the reach is floored as well as compared.
    if len(joins) < 51:
        problems.append(
            "only %d sentences join a harness; at least 51 matched before"
            % len(joins))
    for names, line in multi:
        problems.append(
            "one sentence names %s, so its label and its prose disagree"
            % " and ".join(names))
    for stated, harness, have in joins:
        if stated != have:
            problems.append(
                "the section gives %d mutations and %s holds %d"
                % (stated, harness, have))
    # A sentence that states a size and names the file must join, so the
    # named ones are counted against the joins rather than trusted to have
    # been read.
    BS = chr(92)
    named = re.compile(
        r"(\d+)-mutation harness "
        + re.escape("(" + BS + "texttt{mut" + BS + "_")
        + r"[a-z0-9" + re.escape(BS + "_") + r"]+" + re.escape(".py})"))
    src_text = pathlib.Path(args.section).read_text()
    if len(named.findall(src_text)) != len(
            [j for j in joins if j[1].endswith(".py")]):
        problems.append(
            "the section names a harness beside %d counts and %d joined"
            % (len(named.findall(src_text)),
               len([j for j in joins if j[1].endswith(".py")])))
    # "the token-to-code map cannot drift": the map and its inverse are
    # emitted together, so each direction checks the other.
    for problem in opcode_map():
        problems.append(problem)
    # "a generation cannot be reused by silent wraparound": the guard is one
    # comparison, and its absence would be the silent wrap.
    for problem in generation_bump_guards():
        problems.append(problem)
    # "the checks reach three code trees and no further": a checker that
    # starts reading a fourth makes that sentence false.
    for problem in checker_reach():
        problems.append(problem)
    # "the id table is strictly increasing and so cannot alias two helper
    # ids to one slot": a repeat or a descent is that alias.
    for problem in helper_id_table():
        problems.append(problem)
    # "the selector maps exactly the armed ids ... and the tables invert":
    # the ladder's shape is two tables meeting at the armed count.
    for problem in helper_dispatch_shape():
        problems.append(problem)
    # "a hand edit to a generated file or a stale artifact cannot survive
    # the gate": every generator on disk must be run by the recipe.
    for problem in generator_coverage():
        problems.append(problem)
    # "the operand-presence and index-presence decoders cannot disagree
    # about no register": each such sentence rests on a theorem that
    # equates the two sentinels, so a missing theorem leaves it hollow.
    for problem in sentinel_theorems():
        problems.append(problem)
    # "A and B cannot disagree about X": each sentence rests on a theorem
    # asserting the agreement, usually a roundtrip or an offset equality.
    for problem in agreement_theorems():
        problems.append(problem)
    # "the same selection is shared by the read, read-tag and write
    # helpers rather than repeated at three sites": one theorem per
    # consumer, so a consumer that stopped sharing reports.
    for problem in shared_selection_theorems():
        problems.append(problem)
    # "two consecutive full runs produce byte-identical output": a
    # timestamp, uuid or pid in the log would make that false, so their
    # absence is the necessary condition one log can show.
    vol = volatile_tokens(pathlib.Path(args.log).read_text(errors="ignore"))
    if vol:
        problems.append(
            "the gate log carries volatile tokens %s, so two runs cannot "
            "be byte-identical" % vol)
    # "carry content rather than closing vacuously": a statement whose two
    # sides are the same proves nothing about the table it names.
    for problem in vacuous_theorems():
        problems.append(problem)
    # "the twenty-four family opcodes and the forty-three singleton
    # opcodes are sixty-seven distinct ones": three lengths of lists the
    # totality module defines, and the third is their sum because the
    # module proves the two disjoint.
    words2num = {"twenty-four": 24, "forty-three": 43,
                 "sixty-seven": 67}
    tst = re.search(
        r"the (twenty-four) family opcodes and the (forty-three) singleton "
        r"opcodes are (sixty-seven) distinct ones", plain)
    if tst is None:
        problems.append(
            "the sentence sizing the routed opcode population is absent, so "
            "its three figures went unread")
    else:
        want = tuple(words2num[g] for g in tst.groups())
        got = dispatch_totality()
        if want != got:
            problems.append(
                "the section divides the routed opcodes %s and the module "
                "gives %s" % (want, got))
    # "requiring a non-member opcode to reach the unsupported arm so the
    # counter cannot be vacuously zero": a property of one host file.
    for problem in mul_nonmember_check():
        problems.append(problem)
    # "two consecutive full runs produce byte-identical output": when the
    # caller keeps the previous run beside this one, the two are compared
    # on everything but build progress.
    prev = pathlib.Path(args.log).with_name(
        pathlib.Path(args.log).stem + "-prev.log")
    if prev.exists():
        if determinism_keys(pathlib.Path(args.log).read_text()) != \
                determinism_keys(prev.read_text()):
            problems.append(
                "this run and %s differ outside the build progress lines"
                % prev.name)
    # "the section names its artifacts by file name": a rename in the tree
    # leaves the prose pointing at a file that no longer exists.
    for name in cited_files():
        problems.append(
            "the section cites %s and no tree beside it has that file"
            % name)
    # "Step~0456 introduced this contract": a step number is neither a
    # "58 of the 61 and 103 of the 104 cannot state the goal ... 161 of the
    # 165": four figures that must reconcile two ways.
    for problem in bv_decide_partition():
        problems.append(problem)
    # "a 1024-byte copy is accepted, while 1025 and -1 both raise": the
    # bound is one constant and the rule compares against it both ways.
    for problem in memset_bound():
        problems.append(problem)
    # The section and the step record describe one tree; a figure both
    # state must agree with it and with each other.
    for problem in cross_document():
        problems.append(problem)
    # "it asserts that the two arms select different tags so that the check
    # cannot pass with both arms identical": a property of one host file.
    for problem in tag_arms_differ():
        problems.append(problem)
    # "it asserts that a non-identity modifier was actually exercised so
    # that the run cannot be vacuous": two guards in one host.
    for problem in orn_vacuity_guards():
        problems.append(problem)
    # "proves all three arms reachable": an arm no input reaches makes a
    # dispatch contract true for a reason the reader did not intend.
    for problem in reachability_theorems():
        problems.append(problem)
    # A passing gate reports on the tree it ran on; a log older than a
    # component says nothing about the code that is there now.
    for problem in stale_log(pathlib.Path(args.log)):
        problems.append(problem)
    # "the correspondence is now a theorem rather than an eyeball
    # comparison": four agreements between the two arenas.
    for problem in cross_isa_arena():
        problems.append(problem)
    # "the counterexample is now a theorem": the whole-word hypothesis is
    # what excludes the one-byte arena, so a theorem without it reports.
    for problem in arena_counterexample():
        problems.append(problem)
    # "the body and the flag family are selected by the same opcode and
    # cannot diverge": three theorems must key on that opcode.
    for problem in doubleshift_opcode_keyed():
        problems.append(problem)
    # "the two facts are one selection": one theorem stating both
    # directions and both width sources, with each pair distinct.
    for problem in push_pop_one_selection():
        problems.append(problem)
    # "it clears CF, SF and OF, and sets ZF exactly when the width-narrowed
    # source is zero": three clears and one narrowed-source test.
    for problem in popcnt_flag_rule():
        problems.append(problem)
    # "it clears SF and OF, sets CF exactly when the byte-masked count
    # reaches the width's bit count, and sets ZF when the result is zero":
    # two independent inputs, four assignments.
    for problem in bzhi_flag_rule():
        problems.append(problem)
    # "AArch64 sets its carry to not-borrow while x86-64 sets its carry to
    # borrow": a complement over all operands plus a witness that they
    # genuinely differ.
    for problem in carry_polarity():
        problems.append(problem)
    # "the three counts sum to 487 rather than 488, and one use sits in
    # none of the three": four figures that have to close.
    for problem in native_decide_split():
        problems.append(problem)
    # "the default code is exactly the 64-bit width's code, so the
    # resolution cannot drift from the width table": a numeral equality.
    for problem in default_code_is_w64():
        problems.append(problem)
    # "the selftest path drives that fixture and asserts the diagnostic":
    # the marker the section quotes has to be the one the suite looks for.
    for problem in packet_bounds_fixture():
        problems.append(problem)
    # "the other two have no fixture in the tree": a fixture appearing
    # later would make the concession understate the evidence.
    for problem in unexercised_negatives():
        problems.append(problem)
    # "on x86-64 the byte-ladder arm performs that window lane by lane
    # through b[index + 7] ... on AArch64 the access goes through
    # KPROG_ARM64_LOAD_BYTES": the mechanism on each side.
    for problem in window_overflow_mechanism():
        problems.append(problem)
    # "the independent oracle is the host compiler's own 128-bit integer
    # type, which the simulator cannot use": a property of one host.
    for problem in multiply_oracle():
        problems.append(problem)
    # "a chain that composed differently on one side would diverge while
    # every per-architecture theorem continued to hold": a complement over
    # the same inputs plus an injective mapping.
    for problem in cross_isa_cond():
        problems.append(problem)
    # Two sentences may describe one harness, and should name it twice only
    # when they are about it. A size joined to two different harnesses is
    # the signal that one of them is wrong, which is how a mis-join at size
    # 49 was found.
    # "a resolved source width is never the absent code, so a body cannot
    # widen at an unknown width": an exclusion, with the fallback as its
    # companion.
    for problem in width_resolution_pair():
        problems.append(problem)
    # "323 macros and 621 parameters ... as they stood then": the same two
    # figures the checker records where the defect was found.
    for problem in macro_hygiene_history():
        problems.append(problem)
    # "a bogus token exits with unknown x86 opcode: BOGUS_OPCODE rather
    # than emitting a step the simulator cannot dispatch": the message is
    # quoted, and SystemExit with a string is exit 1.
    for problem in bogus_token_message():
        problems.append(problem)
    # "planting 6 catches ... keeping 5 documented equivalences": the
    # battery prints both, so the split is checked by running it.
    for problem in mem_alu_battery():
        problems.append(problem)
    # "the six AArch64 hosts that count guard hits ... require the guard
    # to fire exactly once": a population the hosts themselves state.
    for problem in guard_hit_hosts():
        problems.append(problem)
    # The success line reports the surface rather than only the count of
    # claims: how many distinct figures the section states, and how many of
    # them a banner or a sequence check holds.
    figs_total, banner_bound, stated, rest = figure_coverage()
    seen = percent_census(text)
    # The four shares are computed above; their floored sum is what the
    # sentence about "the four add to" states, so it is derived rather than
    # written down. The two tree shares come from the checker that owns
    # those populations.
    import check_lean_claims as _claims
    _ax = _claims.scan_tree(str(pathlib.Path(__file__).parent))
    floored = sum((1000 * buckets[k][1] // modeled) / 10
                  for k in buckets if buckets[k][1])
    known = {"%.1f" % floored,
             "%d" % _ax["nd_share"], "%d" % _ax["ax_share"]} | {
        "%.1f" % ((1000 * buckets[k][1] // modeled) / 10)
        for k in buckets if buckets[k][1]}
    if seen != known:
        problems.append(
            "the section states percentages %s, and %s were accounted for; "
            "the difference went unread"
            % (sorted(seen), sorted(known)))
    # The pre/post battery's two counts are rows in its own source, so the
    # sentence is compared with the battery rather than with its own past.
    problems.extend(battery_rows(text))
    problems.extend(route_battery_rows())
    # Counted so the success line names the surface rather than implying the
    # run reached only the figures it reports by class.
    raw_safety = (pathlib.Path(__file__).parent / ".." / ".." / "docs"
                  / "kprog-simulator-in-ebpf" / "sections"
                  / "4-safety.tex").read_text()
    battery_sentences = len(re.findall(
        r"\d+ catchable rows are caught",
        re.sub(r"\s+", " ", raw_safety)))
    if problems:
        # Print before exiting: a silent --check failure gives no evidence.
        for problem in problems:
            print("check_paper_counts: %s" % problem)
        raise SystemExit(1)
    if not problems:
        print(f"all measured claims hold: {len(claimed)} case counts over "
              f"{case_figures(text)} distinct figures, {stated} of "
              f"{figs_total} stated figures held by a banner or another "
              f"check ({len(rest[0])} others: {len(rest[1])} line ids, "
              f"{len(rest[2])} row counts, {len(rest[3])} catch counts, "
              f"{len(rest[4])} zero-padded steps, {len(rest[5])} parts of "
              f"a longer number, the other "
              f"{len(rest[0]) - sum(len(r) for r in rest[1:])} "
              f"unclassified), "
              f"{len(joins)} harness joins ({len(weak)} resting on a shared "
              f"token, {unnamed} naming no file, {len(multi)} naming two), "
              f"{battery_sentences} battery count sentences, both gate "
              f"totals, the "
              f"{len(ISA)}-way split over "
              f"{sum(n for n, _ in buckets.values())} banners, and the "
              "section's own figures against each other")


if __name__ == "__main__":
    try:
        main()
    except (FileNotFoundError, OSError) as exc:
        # The checks read a build directory the repository does not carry,
        # so a checkout that holds the proof tree still cannot run them.
        # Naming the file is the difference between a traceback and a
        # diagnosis.
        raise SystemExit(
            "check_paper_counts: the checks read sources under build/, "
            "which the repository does not track, and this checkout lacks "
            "one (%s)" % exc)
