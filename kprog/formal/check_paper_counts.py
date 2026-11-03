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
    seen = percent_census(text)
    known = {"46.4", "48.3", "0.8", "4.3", "99.8", "23", "30"}
    if seen != known:
        problems.append(
            "the section states percentages %s, and %s were accounted for; "
            "the difference went unread"
            % (sorted(seen), sorted(known)))
    if args.check and problems:
        raise SystemExit(1)
    if not problems:
        print(f"all {len(claimed)} claimed case counts, both gate totals, "
              f"and the {len(ISA)}-way simulator split over "
              f"{sum(n for n, _ in buckets.values())} banners match the "
              "log")


if __name__ == "__main__":
    main()
