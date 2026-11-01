#!/usr/bin/env python3
"""Mutation-test every generator's emitted C and report what catches the mutant.

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
    no-host             no host calls the affected contract
    compile-fail        the C no longer builds (a static assertion, usually)
    host-caught         a host ran and reported a mismatch
    SURVIVED            nothing noticed

Only SURVIVED is a defect. The distribution is the useful output: it says how
much of the contract surface is guarded at generation time versus at test time.

Usage: mutate_contracts.py [--check]
"""

import argparse
import glob
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
CC = ["-Wall", "-Wextra", "-O2", "-I.", "-I../arm64", "-I../x86",
      "-I../../kprog",
      "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf"]

# Tokens that only appear in Lean expressions.
LEAN = ("BitVec", "|||", "&&&", "<<<", ">>>", "signExtend", "setWidth",
        "toNat", "match ", "Nat", "ZMod")

LIT = re.compile(r'\b(0x[0-9a-fA-F]{2,}|\d{2,})\b')


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
    src = open(os.path.join("generated", header), errors="ignore").read()
    names = set(re.findall(r'#define (KPROG_[A-Z0-9_]+)\(', src))
    names |= set(re.findall(r'static\s+\S+\s+(kprog_[a-z0-9_]+)\(', src))
    if not names:
        return None
    pat = re.compile(r'\b(?:%s)\b' % "|".join(sorted(names, key=len,
                                                      reverse=True)))
    for f in sorted(glob.glob("test_*host.c") + glob.glob("cross_*host.c")):
        if pat.search(open(f, errors="ignore").read()):
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


def run(gen):
    picked = mutate(gen)
    if not picked:
        return None
    src, start, end, replacement, desc = picked
    stem = os.path.basename(gen)[len("generate_"):-len("_spec.py")]
    header = stem + ".h"
    host = host_for(header)
    try:
        open(gen, "w").write(src[:start] + replacement + src[end:])
        if subprocess.run([sys.executable, gen], capture_output=True).returncode:
            outcome = "generator-rejected"
        elif host is None:
            outcome = "no-host"
        else:
            build = subprocess.run(["gcc"] + CC + [host, "-o", "/tmp/_mutant"],
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
    results = [r for r in (run(g) for g in sorted(
        glob.glob("generate_*_spec.py"))) if r]

    tally = {}
    for _, _, outcome in results:
        tally[outcome] = tally.get(outcome, 0) + 1

    for stem, desc, outcome in results:
        if outcome == "SURVIVED":
            print("SURVIVED %-34s %s" % (stem, desc))

    print("mutate_contracts: %d generator(s) tested -- %s"
          % (len(results),
             ", ".join("%s %d" % (k, tally[k]) for k in sorted(tally))))

    survived = tally.get("SURVIVED", 0)
    if args.check and survived:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))