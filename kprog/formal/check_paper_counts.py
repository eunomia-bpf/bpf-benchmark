#!/usr/bin/env python3
"""Check the paper's claimed oracle case counts against a gate log.

The safety section states the case count of many oracles, and those figures are
hand-maintained. Ten occurrences of seven distinct numbers were stale when this
checker was widened, and none of them was caught by the narrower version that
read only the wrapped form. Four prose forms state a case count: the hyphenated
wrapped form `\\(167{,}480\\)-case routed oracle`, the same form without the math
wrapper, the ellipsis `71,664- and 536-case contract oracles`, and the spelled
form `over 9504 grid cases`. The wrapped form appears at 52 sites and the
unwrapped form at 178. The unwrapped form is the commonest by far, and it was
the one that drifted, because nothing read it: a clean report sat over every
stale figure.

This script extracts every claim it can from a section, reads the counts out of
a `make check` log, and reports any claim with no matching banner. It cannot
tell *which* banner a claim means, only that the number exists in the gate --
which is enough to catch a stale figure, since a stale one matches nothing. The
section's two gate-wide figures, the banner count and the modeled-case sum, are
re-derived exactly rather than matched by existence, because both are stated
once and countable from the log.

Three prose shapes are deliberately not claims. A number inside `\\texttt{...}`
is quoted program output, describing what a run printed at the time; the MOVBE
`OK (16 cases)` line records a bug that no longer exists and matches nothing. A
number introduced by "plus" is one input family of an oracle ("15 fixed vectors
plus a 20,000-case sweep"), not the total any banner prints. And an `N-case`
adjective on a bare grid states arithmetic -- `1,470-case divide grid` is 2 x 5
x 7 x 3 x 7 -- so it is read only when the phrase also names a host or oracle.

The section also splits the gate's cases across the simulators and states that
the split comes from what the gate builds. That too is now measured: each
banner is traced through its run line to the compile line that built it, and
the include closure of that translation unit says which simulator root it
reaches. The four buckets must partition the gate exactly, and the two tempting
shortcuts are measured rather than asserted: the hosts that reach a simulator
through a relative include that no -I names, and the hosts that carry an ISA in
their file name while reaching no simulator. Both counts appear in the section,
so a shortcut that drifted is reported rather than assumed.

Usage: check_paper_counts.py --section <tex> --log <make check log> [--check]
"""
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
    return set(re.findall(r"([A-Z][A-Za-z0-9]+)\.lean", text))


def document_refs(paper: pathlib.Path) -> tuple[set, set, set, set]:
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
    keys = set(re.findall(r"@\w+\{([^,]+),", bib.read_text()))
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

    Eight sentences say an oracle "compares the whole register file with its
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

    Four sentences record one harness at successive sizes as detectors were
    added: 96, 100, 104, 108, each four mutants larger. The sizes are
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
    for name in ("x86_route_host", "helper_route_host"):
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
        except SyntaxError:
            continue
        n = None
        for node in tree.body:
            if (isinstance(node, ast.Assign) and node.targets
                    and getattr(node.targets[0], "id", "") in
                    ("MUTATIONS", "MUT_TABLE", "ROWS")
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
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    totals = harness_totals()
    here = pathlib.Path(__file__).parent
    out = []
    for n, word in re.findall(
            r"(\d+)-mutation harness retargets the shared specification "
            r"\((\w+) rows?\)", flat):
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
            r"(\d+)-mutation harness retargets (?:the |its |both )?"
            r"([a-z/\- ]{3,40}?) spec", flat):
        if shared.get(int(n), 0) <= 1:
            continue
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
    must reach the count. Parts are introduced by "by", "at" and "from".
    """
    flat = re.sub(r"\s+", " ", text).replace("\\brk", "")
    out = []
    for tot, body in re.findall(
            r"(\d+) mutations were caught \(([^)]{10,300})\)", flat):
        parts = [int(x) for x in re.findall(
            r"(\d+) (?:by|at|from) ", body)]
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

    Seventeen sentences say the harness retargets "the N generator
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
    if (n_labels, n_keys) != (9, 56):
        problems.append(
            "the document has %d live labels and the bib %d entries; 9 and "
            "56 when this was written" % (n_labels, n_keys))
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
    if len(cited) != 47:
        problems.append(
            "the section cites %d Lean modules and 47 were cited when this "
            "was written" % len(cited))
    # Sweep claims pair an oracle's size with what it sweeps. The case
    # counts are checked as claims already; this says the number belongs to
    # an exhaustive opcode sweep, and holds the population at twenty-two.
    n_sweeps, stray_sweeps = sweep_claims(text, measured)
    if stray_sweeps:
        problems.append(
            "%d sweep claim(s) print a case count no banner reports: %s"
            % (len(stray_sweeps), stray_sweeps))
    if n_sweeps != 22:
        problems.append(
            "the section makes %d 256-sweep claims and 22 when this was "
            "written" % n_sweeps)
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
    if len(products) != 3:
        problems.append(
            "the section states %d sweep dimension products; 3 when this "
            "was written" % len(products))
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
    if len(named) != 36:
        problems.append(
            "%d oracles are named by a header-inclusion claim; 36 when this "
            "was written" % len(named))
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
    if len(parts) != 4:
        problems.append(
            "the section states %d harness partitions; 4 when this was "
            "written" % len(parts))
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
    # A parenthesised "(N modeled cases" gives an oracle's size. Seven of
    # the ten are gate banners; the other three are battery-local hosts the
    # recipe does not run, which the sentences say by calling them
    # battery-local. A figure that stopped being a banner is reported, so a
    # stale size cannot hide among the witness figures.
    flat_n = re.sub(r"\{,\}", ",", flat_text)
    sizes = {int(n.replace(",", "")) for n in re.findall(
        r"\(([\d,]+) modeled cases", flat_n)}
    witnesses = {1801, 3890, 6509}
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
    for name in named_instructions():
        problems.append(
            "the section presents %s as an instruction and the tree has no "
            "such name" % name)
    # A binding-mutation sentence gives a total and splits it by the kind
    # of change. The parts must reach the total -- one said nineteen against
    # parts summing to seventeen.
    parts = binding_mutations(text)
    if len(parts) != 4:
        problems.append(
            "the section states %d binding-mutation splits; 4 when this "
            "was written" % len(parts))
    for total, summed in parts:
        if total != summed:
            problems.append(
                "a binding-mutation sentence states %d and its parts sum to "
                "%d" % (total, summed))
    # Mutation lists written out in words: word "and" is ambiguous, so the
    # total is bounded by the segment count and the segment count plus
    # every "and". A total outside that range cannot be right.
    bounds = enumerated_bounds(text)
    if len(bounds) != 22:
        problems.append(
            "the section states %d enumerated mutation lists; 22 when this "
            "was written" % len(bounds))
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
    if len(splits) != 24:
        problems.append(
            "the section states %d four-stage row splits; 24 when this was "
            "written" % len(splits))
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
    if len(series) != 5:
        problems.append(
            "the growing harness is recorded at %d sizes; 5 when this was "
            "written" % len(series))
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
        pat = (r"\((\w+) scenes?, 7\{\,\}056 modeled cases"
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
    if len(stated) != 31:
        problems.append(
            "the section sizes %d dedicated harnesses; 31 when this was "
            "written" % len(stated))
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
    if n_shakes != 15:
        problems.append(
            "the section states %d shake field claims; 15 when this was "
            "written" % n_shakes)
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
    if len(desc) != 2:
        problems.append(
            "the section states %d description-joined harnesses; 2 when "
            "this was written" % len(desc))
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
    if len(cw) != 18:
        problems.append(
            "the section states %d caught-with-parts counts; 18 when this "
            "was written" % len(cw))
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
    for isa, fams, pairs, complete in disjoint_families():
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
    if problems:
        # Print before exiting: a silent --check failure gives no evidence.
        for problem in problems:
            print("check_paper_counts: %s" % problem)
        raise SystemExit(1)
    if not problems:
        print(f"all {len(claimed)} claimed case counts, both gate totals, "
              f"and the {len(ISA)}-way simulator split over "
              f"{sum(n for n, _ in buckets.values())} banners match the "
              "log")


if __name__ == "__main__":
    main()
