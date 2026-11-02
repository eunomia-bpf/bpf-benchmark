#!/usr/bin/env python3
"""Mutation-test the generators' emitted C and report what catches the mutant.

A generator that renders a specification into a C header can be wrong in its
arithmetic while every cross-check still passes, because the cross-checks
compare the generated file to *the same generator's* output. The question this
script answers is the only one that settles it: if a numeric literal in the
emitted C changes, does anything notice?

For each generator it finds the first *meaningful* numeric literal inside an
emitted-C string -- skipping Lean expressions, static-assert and printf
messages, Python format padding, and prose -- bumps it by one, regenerates, and
records the first of these to fire:

    generator-rejected  the generator's own validation refused the change
    inert               the regenerated C was byte-identical, so the literal
                        never reached the header and nothing was tested
    no-host             the C changed, but no host calls the affected contract
    compile-fail        the emitted C no longer builds. A renamed identifier
                        inside a static assertion counts -- the compiler saw
                        the change, though no value did -- and is reported as
                        this rather than as an arithmetic change
    host-caught         a host ran and reported a mismatch
    SURVIVED            the C changed and nothing noticed

`inert` is counted separately from `no-host` on purpose: the first says the
mutation was vacuous, the second that a real change has no test. Collapsing
them, as an earlier version did, reported a generator as untested-by-absence
when it had in fact been tested by nothing.

The third outcome means the generator was not tested at all:

    no-literal          the generator's strings hold no bump-able literal

It covers most generators, and for a knowable reason: of those, 60 do emit
numeric constants, but read them from a spec JSON and interpolate them into
the header, so no source literal exists to bump -- only a data change reaches
them -- and the remaining 47 emit no numeric constant at all. The banner
therefore reports tested against the number of generators that exist.

Only SURVIVED is a defect. The distribution is the useful output: it says how
much of the contract surface is guarded at generation time versus at test time.

Usage: mutate_contracts.py [--check]
"""

import argparse
import glob
import hashlib
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
CC = ["-Wall", "-Wextra", "-O2", "-I.", "-I../arm64", "-I../x86",
      "-I../../kprog",
      "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/"
      "include/bpf"]

# Tokens that only appear in Lean expressions.
LEAN = ("BitVec", "|||", "&&&", "<<<", ">>>", "signExtend", "setWidth",
        "toNat", "match ", "Nat", "ZMod")

LIT = re.compile(r'\b(0x[0-9a-fA-F]{2,}|\d{2,})\b')

# Outcomes where something actually noticed the mutation.
GUARDED = ("compile-fail", "generator-rejected", "host-caught")

# Outcomes where the C changed and nothing noticed -- a coverage gap.
UNGUARDED = ("SURVIVED", "no-host")

# Outcomes that mean "this generator was not tested", with the reason shown.
UNTESTED = (("inert", "the emitted C did not change"),
            ("no-literal", "no bump-able literal in the generator"))


def meaningful(text):
    """True when a literal here changes semantics, not prose or formatting."""
    if any(k in text for k in LEAN):
        return False
    if re.search(r'\bdrift\b|\bmismatch\b|%[a-z]', text):
        return False
    if "' ' * (" in text or '" " * (' in text:
        return False
    if text.count(" ") >= 3 and not re.search(r'[=;()]', text):
        return False
    # A sentence ending in a colon is a diagnostic prefix the generator prints
    # from its own Python-side check, not part of the emitted C.
    if text.rstrip().endswith(":"):
        return False
    return bool(LIT.search(text))


def host_for(header):
    """The first host that calls one of this header's macros.

    Matching on the header name alone is too strict: several hosts reach a
    contract transitively through another header, so a caller is identified by
    the *macro names* the header exports rather than by an include line.
    """
    src = open(os.path.join("generated", header)).read()
    names = set(re.findall(r'#define (KPROG_[A-Z0-9_]+)\(', src))
    names |= set(re.findall(r'static\s+\S+\s+(kprog_[a-z0-9_]+)\(', src))
    if not names:
        return None
    pat = re.compile(r'\b(?:%s)\b' % "|".join(sorted(names, key=len,
                                                      reverse=True)))
    for f in sorted(glob.glob("test_*host.c") + glob.glob("cross_*host.c")):
        if pat.search(open(f).read()):
            return f
    return None


def mutate(gen):
    """Return (offset, end, replacement) for the first meaningful literal."""
    src = open(gen).read()
    for m in re.finditer(r'"([^"\n]*)"', src):
        text = m.group(1)
        if not meaningful(text):
            continue
        for lit in LIT.finditer(text):
            value = int(lit.group(1), 0)
            if value < 2:
                continue
            replacement = hex(value + 1) if lit.group(1).startswith("0x") \
                else str(value + 1)
            return (src, m.start(1) + lit.start(1),
                    m.start(1) + lit.end(1), replacement,
                    "%s -> %s" % (lit.group(1), replacement))
    return None


def digest(header):
    """The content of a generated header; a missing one is an error."""
    return hashlib.sha256(open(os.path.join("generated", header),
                               "rb").read()).hexdigest()


def run(gen):
    stem = os.path.basename(gen)[len("generate_"):-len("_spec.py")]
    header = stem + ".h"
    picked = mutate(gen)
    if not picked:
        return (stem, "", "no-literal")
    src, start, end, replacement, desc = picked
    before = digest(header)
    try:
        open(gen, "w").write(src[:start] + replacement + src[end:])
        gen_run = subprocess.run([sys.executable, gen], capture_output=True)
        if gen_run.returncode:
            outcome = "generator-rejected"
        elif digest(header) == before:
            outcome = "inert"
        else:
            host = host_for(header)
            if host is None:
                outcome = "no-host"
            else:
                build = subprocess.run(["gcc"] + CC + [host, "-o",
                                                       "/tmp/_mutant"],
                                       capture_output=True)
                if build.returncode:
                    outcome = "compile-fail"
                else:
                    r = subprocess.run(["/tmp/_mutant"], capture_output=True,
                                       timeout=900)
                    outcome = "host-caught" if r.returncode else "SURVIVED"
    finally:
        open(gen, "w").write(src)
        subprocess.run([sys.executable, gen], capture_output=True)
    return (stem, desc, outcome)


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    os.chdir(ROOT)
    results = [run(g) for g in sorted(glob.glob("generate_*_spec.py"))]

    tally = {}
    for _, _, outcome in results:
        tally[outcome] = tally.get(outcome, 0) + 1

    for stem, desc, outcome in results:
        if outcome in UNGUARDED:
            print("%-9s %-34s %s" % (outcome.upper(), stem, desc))

    guarded = sum(tally.get(k, 0) for k in GUARDED)
    loose = sum(tally.get(k, 0) for k in UNGUARDED)
    print("mutate_contracts: %d of %d generator(s) guarded -- %s -- %d "
          "changed and nothing noticed -- %d not tested: %s"
          % (guarded, len(results),
             ", ".join("%s %d" % (k, tally[k]) for k in sorted(GUARDED)
                       if k in tally),
             loose, len(results) - guarded - loose,
             ", ".join("%s %d (%s)" % (k, tally[k], why)
                       for k, why in UNTESTED if k in tally)))

    survived = tally.get("SURVIVED", 0)
    if args.check and survived:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
