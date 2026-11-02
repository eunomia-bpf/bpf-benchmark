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

This script reports every `*host.c` that (a) includes a simulator header, (b)
calls at least one KPROG_* contract macro, and (c) never calls an X86_SIM_L_* /
ARM64_SIM_L_* composition macro. Category (c) is a proxy, not a proof -- a host
can drive the simulator some other way -- so the script also names the contract
macros each such host calls. It fails when a host matches all three *and* the
contract it calls is one the simulator reaches through a SIM_L_* composition,
which is computed by reading the simulator sources; when a simulator header is
missing or states no composition; and when a recorded exception stops applying,
because that reason then no longer describes the tree.

"""

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
CONTRACT = re.compile(r'\b(KPROG_[A-Z0-9_]+)\s*\(')


def sim_composed_contracts():
    """Contract macros the simulator reaches from inside a SIM_L_* macro.

    Returns (contracts, problems). A header that is missing, or that states no
    `SIM_L_*` definition at all, is a problem rather than a skip: silently
    dropping one architecture's header leaves the other's contracts as the
    whole set, and the check keeps passing over half of the tree.
    """
    out = set()
    problems = []
    for arch, paths in SIM.items():
        found = 0
        for p in paths:
            if not p.exists():
                problems.append("missing simulator header %s" % p)
                continue
            src = p.read_text(errors="ignore")
            # Each SIM_L_ definition body, from #define to the next #define.
            for m in re.finditer(
                    r'#define\s+((?:X86|ARM64)_SIM_L_\w+)\(([^)]*)\)([\s\S]*?)'
                    r'(?=^#define|\Z)', src, re.M):
                found += 1
                out |= set(CONTRACT.findall(m.group(3)))
        if not found:
            problems.append("%s simulator states no SIM_L_* composition"
                            % arch)
    return out, problems


def main(argv):
    composed, problems = sim_composed_contracts()

    # Every host that links against a simulator, whatever it is named: the
    # earlier `test_*` / `cross_*` globs would have missed a host named any
    # other way, and width_fallback_host.c already is one.
    findings = {}
    for path in sorted(ROOT.glob("*host.c")):
        src = path.read_text(errors="ignore")
        if not INCLUDES_SIM.search(src) or COMPOSITION.search(src):
            continue
        # Only a gap if the contract it tests is one the simulator composes.
        composed_here = sorted(set(CONTRACT.findall(src)) & composed)
        if composed_here:
            findings[path.name] = composed_here

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

    for name, macros in sorted(findings.items()):
        if name not in ACCEPTED:
            problems.append("%s calls %s without driving the composition"
                            % (name, ", ".join(macros[:3])))
    # An exception whose host no longer needs one is stale: it either started
    # driving the composition or stopped calling a composed contract, and
    # either way the reason recorded here no longer describes the tree.
    for name in sorted(ACCEPTED):
        if name not in findings:
            problems.append("ACCEPTED entry %s is stale -- it no longer calls "
                            "a composed contract without the composition"
                            % name)

    if problems:
        print("check_oracle_composition: %d finding(s)" % len(problems))
        for p in problems:
            print("  " + p)
        print("Add an entry to ACCEPTED with the host that does cover the "
              "composition, or drive it here.")
        return 1

    print("check_oracle_composition: every oracle that calls a "
          "simulator-composed contract drives the composition, or is one of "
          "%d reviewed exceptions" % len(findings))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))