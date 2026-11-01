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


def hosts_mentioning(header):
    """Hosts that include or name the given generated header."""
    out = []
    for f in glob.glob(str(ROOT / "test_*host.c")) + \
            glob.glob(str(ROOT / "cross_*host.c")):
        s = open(f, errors="ignore").read()
        if header in s:
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

    problems = []
    for name in dual:
        header = name[len("generate_"):-len("_spec.py")] + ".h"
        hosts = hosts_mentioning(header)
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

    print("check_dual_emit_coverage: %d dual-emitted generator(s); each one's "
          "C output is covered by a named host, and each was confirmed by "
          "mutating the C string only" % len(dual))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))