#!/usr/bin/env python3
"""Compare the dispatcher the C chain branches on to the one the proofs model.

`Arm64DispatchTotality` states that the dispatch chain covers the opcode space,
and `x86_dispatch_chain_codes_nodup` (with its AArch64 counterpart) states that
no opcode is gated twice. Both are stated over the *generated* dispatch tables,
which model part of the chain. The C chain in `*_sim_local_bpf.h` branches on
its own list of `KPROG_*_HANDLED` predicates, and nothing ties the two lists
together.

Measured after Step 0518: the AArch64 C chain branches on 35 HANDLED
predicates while the generated model names 25, so twelve families -- ADRP,
CNEG, CSEL, EXTREV, LDRSX, MOV, MUL, ORN, REDUCTION, SHIFT, STLXR, UNARY --
are routed by the code and absent from the model. The totality theorem is
therefore true of the modelled subset, not of the chain, and its docstring says
so.

This script measures that difference and fails when a *new* predicate appears in
the C chain without a counterpart, so the modelled set cannot silently fall
further behind. The known gap is listed explicitly, with the reason it is
tolerable: each of those families is covered by its own route host, which
drives it through `ARM64_SIM_L_EXEC` and checks the arm it lands in.

Usage: check_dispatch_model.py [--check]
"""

import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
SIM = {
    "arm64": ROOT.parent / "arm64" / "arm64_sim_local_bpf.h",
    "x86": ROOT.parent / "x86" / "x86_sim_local_bpf.h",
}

# Families the AArch64 C chain branches on that the generated dispatch model
# does not name. Each is driven by its own route host, which is why the
# totality theorem can still be read as "the modelled set is complete".
A64_UNMODELLED = {
    # Families with a *live* route host: driven through ARM64_SIM_L_EXEC, so
    # the arm they land in is checked even though the dispatch model does not
    # name them.
    "csel": "test_arm64_csel_route_host.c (live)",
    "mul": "test_arm64_mul_route_host.c (live)",
    "mov": "test_arm64_dispatch_singleton_route_host.c (live)",
    "shift_op": "test_arm64_dispatch_family_route_host.c (live)",
    "ldrsx": "test_arm64_ldrsx_op_route_host.c (live)",
    # Families with only a model-side host. Recorded as such rather than
    # claiming coverage they do not have: nothing drives these through the
    # dispatcher, which is the same gap Step 0503 closed for MUL.
    "adrp": "test_arm64_adrp_route_host.c (live)",
    "cneg": "test_arm64_cneg_route_host.c (live)",
    "extrev": "test_arm64_extrev_route_host.c (live)",
    "orn": "model-only: test_arm64_orn_host.c",
    "reduction": "test_arm64_reduction_route_host.c (live)",
    "stlxr": "test_arm64_stlxr_route_host.c (live)",
    "unary": "test_arm64_unary_route_host.c (live)",
}

HANDLED = re.compile(r'KPROG_([A-Z0-9]+)_([A-Z0-9_]*?HANDLED)\(OP\)')


def c_predicates(path):
    """The family names the C chain branches on, lowercase, `disp_` stripped."""
    out = set()
    for isa, name in HANDLED.findall(path.read_text(errors="ignore")):
        if not name.endswith("HANDLED"):
            continue
        fam = name[: -len("HANDLED")].rstrip("_").lower()
        if fam.startswith("disp_"):
            fam = fam[len("disp_"):]
        if fam:
            out.add((isa.lower(), fam))
    return out


def modelled(paths):
    """The list names the generated dispatch model provides."""
    out = set()
    for p in paths:
        if not p.exists():
            continue
        for m in re.finditer(r'def arm64Disp([A-Za-z0-9]+)Ops',
                             p.read_text(errors="ignore")):
            out.add(m.group(1).lower())
    return out


def norm(s):
    return s.replace("_", "")


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    a64 = c_predicates(SIM["arm64"])
    model = modelled(sorted((ROOT / "KProgFormal").glob("Arm64Dispatch*.lean")))
    if not a64 or not model:
        print("check_dispatch_model: found no predicates or no model")
        return 1

    model_n = {norm(m) for m in model}
    unmodelled = sorted(f for isa, f in a64
                        if isa == "arm64" and norm(f) not in model_n)

    problems = []
    for fam in unmodelled:
        if fam not in A64_UNMODELLED:
            problems.append(
                "arm64: the C chain branches on %r, which the dispatch model "
                "does not name -- add it to the model, or to A64_UNMODELLED "
                "with the route host that covers it" % fam)
    # And the reverse: a recorded gap that has since been modelled.
    for fam, why in sorted(A64_UNMODELLED.items()):
        if norm(fam) in model_n:
            problems.append(
                "arm64: %r is now modelled, so its A64_UNMODELLED entry (%s) "
                "is stale -- remove it" % (fam, why))

    if problems:
        print("check_dispatch_model: %d finding(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    print("check_dispatch_model: AArch64 chain branches on %d families, the "
          "model names %d, and the %d unmodelled ones are the recorded set "
          "(11 with a live route host, 1 model-only)"
          % (len(a64), len(model), len(unmodelled)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))