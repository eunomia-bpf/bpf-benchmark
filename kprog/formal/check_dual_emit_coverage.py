#!/usr/bin/env python3
"""Check that a dual-emitted generator's *C* output is covered, and say by what.

Most generators render one specification into two languages: a C header and a
Lean module. The Lean module carries a refinement theorem, so a mistake in the
Lean formula is caught at build time. The C formula is a *separate string
literal* in the same generator, and the proof says nothing about it.

That is not a defect in the proof -- it is the boundary of what it covers. The
boundary was measured, not assumed: mutating `mid1 >> 32` to `>> 16` in the C
string of the arm64 multiply generator leaves `lake env lean
KProgFormal/Arm64Mul.lean` green, because the Lean formula is a different
literal that still says `>>> 32`. The same holds for the AArch64
extract/reverse/extend generator, whose C `<< 56` can become `<< 55` with the
Lean proof still passing.

So the C needs its own oracle, and this script records which generator's C is
covered and by which host. It fails when a generator writes shift arithmetic
twice (C and Lean) and no host references its header -- meaning a C-only
mutation would survive the whole gate.

Usage: check_dual_emit_coverage.py [--check]
"""

import argparse
import glob
import os
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent

# C-string shift, excluding Lean's ">>>" and "<<<". A bare `<<` or a `>>` with
# exactly one preceding `>` is C; three-character shifts are Lean.
C_SHIFT = re.compile(r'(?<![<>])>>\s*\d|(?<!<)<<(?!<)\s*\d')
LEAN_SHIFT = re.compile(r'>>>\s*\d|<<<\s*\d')

# Generators whose C arithmetic is covered by a specific host. Each entry was
# confirmed by mutating the C string and watching that host fail.
COVERED = {
    "generate_arm64_mul_spec.py":
        "test_arm64_mul_wide_host.c (umulh decomposition) and "
        "test_arm64_mul_route_host.c (through the dispatcher)",
    "generate_arm64_extrev_spec.py":
        "test_arm64_extrev_host.c",
    "generate_x86_bswap_spec.py":
        "test_x86_bswap_route_host.c and the cross-ISA differential host",
    "generate_x86_popcount_spec.py":
        "test_x86_popcount_host.c",
    "generate_x86_cmov_spec.py":
        "test_x86_cmov_host.c (C mutation >>25 fails it)",
    "generate_x86_reg_lane_aux_spec.py":
        "test_x86_reg_lane_aux_host.c (C mutation <<8 trips the static "
        "assertion in x86_sim.h before the host even runs)",
    "generate_x86_setcc_mem_spec.py":
        "test_x86_setcc_mem_host.c (C mutation >>25 fails it)",
}


# The C entry points a generated header defines. A host usually reaches a
# generated header through the simulator header rather than including it, so it
# names the *symbol* and never the file -- `test_x86_bswap_route_host.c` calls
# `kprog_x86_bswap_value` and covers `x86_bswap.h` while never mentioning it.
C_SYMBOL = re.compile(r'\bkprog_[A-Za-z0-9_]+')


def header_symbols(header):
    """The `kprog_*` names a generated header defines."""
    path = ROOT / "generated" / header
    if not path.exists():
        return set()
    return set(C_SYMBOL.findall(path.read_text(errors="ignore")))


def strip_comments(text):
    """Drop C comments, so a symbol match means the host *uses* it.

    `test_x86_bswap_route_host.c` names `kprog_x86_bswap_value` once, in a
    comment explaining what the generated macro does; it reaches the contract
    through the dispatcher instead. Counting that as a use would make the
    symbol test weaker than the file-name test it replaces.
    """
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"(?m)//.*$", " ", text)


def hosts_mentioning(header):
    """Hosts that include the given generated header or call into it.

    Matching the file name alone under-reports transitive coverage, which is
    how most hosts reach a generated contract -- `test_x86_movbe_host.c` covers
    `x86_bswap.h` by calling the generated symbol. Either form counts; a symbol
    is credited only outside comments.
    """
    syms = header_symbols(header)
    out = []
    for f in glob.glob(str(ROOT / "test_*host.c")) + \
            glob.glob(str(ROOT / "cross_*host.c")):
        raw = open(f, errors="ignore").read()
        if header in raw or any(sym in strip_comments(raw) for sym in syms):
            out.append(os.path.basename(f))
    return out


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    dual = []
    for g in sorted(glob.glob(str(ROOT / "generate_*.py"))):
        s = open(g, errors="ignore").read()
        if LEAN_SHIFT.search(s) and C_SHIFT.search(s):
            dual.append(os.path.basename(g))

    # The strings beside each COVERED key are the evidence for the summary's
    # claim, but the key alone was checked -- a note naming a host that does not
    # exist, or one that never reaches the header, passed unchanged. Validate the
    # note itself so the claim is machine-checked rather than remembered.
    NOTE_HOST = re.compile(r"([A-Za-z0-9_]+\.c)")

    problems = []
    for name in dual:
        header = name[len("generate_"):-len("_spec.py")] + ".h"
        hosts = hosts_mentioning(header)

        # Only the file's existence is checked, deliberately. Whether a host
        # covers a contract cannot be decided statically: the bswap route host
        # names neither `x86_bswap.h` nor `kprog_x86_bswap_value` outside a
        # comment, yet mutating the generated `<< 24` to `<< 23` fails it with
        # 48 mismatches, because it drives BSWAP through the dispatcher. A
        # static "does not reach" rule reported exactly that host as a
        # finding. Coverage is established by the mutation test the note
        # records, not by the text of the host.
        note = COVERED.get(name)
        if note:
            for claimed in NOTE_HOST.findall(note):
                if not (ROOT / claimed).exists():
                    problems.append(
                        "%s is recorded as covered by %s, which does not exist"
                        % (name, claimed))

        if not hosts:
            problems.append(
                "%s writes its arithmetic twice but no host names %s, so a "
                "C-only mutation would survive the gate" % (name, header))
        elif name not in COVERED:
            problems.append(
                "%s is dual-emitted and covered by %s, but is not recorded in "
                "COVERED -- confirm the C-only mutation fails that host, then "
                "add it" % (name, ", ".join(hosts[:2])))

    if problems:
        print("check_dual_emit_coverage: %d finding(s) over %d dual-emitted "
              "generator(s)" % (len(problems), len(dual)))
        for p in problems:
            print("  " + p)
        return 1

    # What this verifies, stated exactly: every dual-emitted generator has a
    # host that references its header or its symbols, is recorded in COVERED,
    # and names host files that exist. That a recording was established by
    # mutating the C string alone is a fact about how it was produced and is
    # not re-derived here -- see Step 0532 for why the difference matters.
    print("check_dual_emit_coverage: %d dual-emitted generator(s); each one's "
          "C output has a host that references it, each is recorded against "
          "host files that exist (the mutation that established each "
          "recording is not re-run here)" % len(dual))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))