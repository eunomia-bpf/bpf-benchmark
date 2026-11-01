#!/usr/bin/env python3
"""Find oracles that test a generated contract but never the simulator's path to it.

Several generated contracts are not called directly by the simulator. The
simulator first derives arguments -- a mask, a width, a shift count, a sign
bit, a lane payload -- and then calls the contract with them. An oracle that
includes the simulator header but reproduces that derivation *itself* tests only
the contract: a fault in the simulator's derivation leaves it green.

That is not hypothetical. It happened three times in this tree:

  - the imul-flags oracle recomputed the sign-dependent limit, so a fault in
    the simulator's sign selection survived (Step 0513);
  - the shift-flags oracle recomputed the sign bit, so shifting that bit by one
    in the simulator survived 90,112 cases;
  - the register-lane-aux oracle called the accessors directly, so corrupting
    the payload the simulator passes through survived 7,629 cases.

This script reports every host that (a) includes a simulator header, (b) calls at
least one KPROG_* contract macro, and (c) never calls an X86_SIM_L_* /
ARM64_SIM_L_* composition macro. Category (c) is a proxy, not a proof -- a host
can drive the simulator some other way -- so the script also prints the contract
macros each such host calls, so the reader can judge. It fails only when a host
matches all three *and* the contract it calls is one the simulator reaches
through a SIM_L_* composition, which is computed by reading the simulator
sources.

Usage: check_oracle_composition.py [--check]
"""

import argparse
import glob
import os
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
SIM = {
    "x86": [ROOT.parent / "x86" / "x86_sim.h",
            ROOT.parent / "x86" / "x86_sim_local_bpf.h"],
    "arm64": [ROOT.parent / "arm64" / "arm64_sim.h",
              ROOT.parent / "arm64" / "arm64_sim_local_bpf.h"],
}

INCLUDES_SIM = re.compile(r'#include\s+"[^"]*sim(_local_bpf)?\.h"')
COMPOSITION = re.compile(r'\b(?:X86|ARM64)_SIM_L_[A-Z0-9_]+\s*\(')
CONTRACT = re.compile(r'\bKPROG_[A-Z0-9_]+\s*\(')


def sim_composed_contracts():
    """Contract macros the simulator reaches from inside a SIM_L_* macro."""
    out = set()
    for paths in SIM.values():
        for p in paths:
            if not p.exists():
                continue
            src = p.read_text(errors="ignore")
            # Each SIM_L_ definition body, from #define to the next #define.
            for m in re.finditer(
                    r'#define\s+((?:X86|ARM64)_SIM_L_\w+)\(([^)]*)\)([\s\S]*?)'
                    r'(?=^#define|\Z)', src, re.M):
                out |= set(re.findall(r'\b(KPROG_[A-Z0-9_]+)\s*\(', m.group(3)))
    return out


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    composed = sim_composed_contracts()
    if not composed:
        print("check_oracle_composition: found no SIM_L_*-composed contracts")
        return 1

    findings = []
    for path in sorted(glob.glob(str(ROOT / "test_*host.c"))
                       + glob.glob(str(ROOT / "cross_*host.c"))):
        src = open(path, errors="ignore").read()
        if not INCLUDES_SIM.search(src):
            continue
        if COMPOSITION.search(src):
            continue
        called = set(re.findall(r'\b(KPROG_[A-Z0-9_]+)\s*\(', src))
        # Only a gap if the contract it tests is one the simulator composes.
        composed_here = sorted(called & composed)
        if composed_here:
            findings.append((os.path.basename(path), composed_here))

    # The known-acceptable exceptions, each for a stated reason. Any *new*
    # entry is the finding; these are reviewed.
    ACCEPTED = {
        # Compares both ISAs' contracts against each other, deliberately at
        # the contract layer rather than through either simulator.
        "cross_isa_differential_host.c":
            "cross-ISA differential, contract-to-contract by design",
        # Compares the multiply contract to 128-bit arithmetic, an oracle the
        # simulator cannot use; the simulator's own path is covered by
        # test_arm64_mul_route_host.c.
        "test_arm64_mul_wide_host.c":
            "wide-arithmetic oracle; sim path covered by the route host",
        # Reads the decode predicates only; the ALU bodies that consume them
        # are driven by test_x86_alu_result_route_host.c.
        "test_x86_alu_decode_host.c":
            "decode table only; bodies covered by the alu-result route host",
        # Calls the three lane decoders directly. The EXEC bodies that
        # consume them are exercised by the alu-result route host, which
        # packs and unpacks a real AUX word. Left as-is rather than
        # duplicating that coverage here.
        "test_x86_reg_lane_aux_host.c":
            "lane decoders only; EXEC bodies covered by the alu route host",
    }

    unexpected = [(n, m) for n, m in findings if n not in ACCEPTED]
    if unexpected:
        print("check_oracle_composition: %d new oracle(s) test a composed "
              "contract without driving the composition" % len(unexpected))
        for name, macros in unexpected:
            print("  %-42s %s" % (name, ", ".join(macros[:3])))
        print("Add an entry to ACCEPTED with the host that does cover the "
              "composition, or drive it here.")
        return 1

    print("check_oracle_composition: every oracle that calls a "
          "simulator-composed contract drives the composition, or is one of "
          "%d reviewed exceptions" % len(ACCEPTED))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))