#!/usr/bin/env python3
"""Compare the dispatcher the C chain branches on to the one the proofs model.

`Arm64DispatchTotality` states that the dispatch chain covers the opcode space,
and `x86_dispatch_chain_codes_nodup` (with its AArch64 counterpart) states that
no opcode is gated twice. Both are stated over the *generated* dispatch tables,
which model part of the chain. The C chain in `*_sim_local_bpf.h` branches on
its own list of `KPROG_*_HANDLED` predicates, and nothing tied the two lists
together.

The tie is the dispatch spec. Every `*_dispatch_*_spec.json` binds a C macro to
the family name the generator uses -- `"macro": "KPROG_ARM64_SHIFT_OP_HANDLED"`
alongside `"name": "shiftOp"`. That name is what `Generated*Dispatch*.lean`
defines a predicate for, and what the hand-written module applies to `op`.
So a family counts as modelled only on three agreeing artifacts: the spec binds
the macro, the generated module defines `<name>Handled`, and a proof states
something about `<name>Handled op`.

That replaces a string comparison, which could not work. The C chain calls the
shift family `SHIFT_OP` and the Lean table `arm64DispShiftOps`; no amount of
stripping `disp_` or underscores bridges `shift_op` to `shift`, so a family the
proofs do model was reported missing, and the aggregate `def arm64DispatchOps`
was read as a family named `atch`. Measured on the current tree: the AArch64
chain branches on 35 predicates, 24 are modelled three ways over, and 11 are
routed by code alone.

The tie is checked in both directions. A spec entry whose macro the chain has
stopped branching on, and a generated predicate no spec binds, both mean the
generator and the chain have drifted and the proofs are no longer about the
code that runs.

Those eleven are tolerable for one reason, and it is now measured rather than
asserted: each is driven through the dispatcher by its own route host. An entry
is accepted only while its host exists, is compiled and run by the recipe, and
calls `ARM64_SIM_L_EXEC` -- the three things that make the sentence true. An
entry whose host has been renamed, dropped from the gate, or rewritten to call
the arm directly fails, as does one whose family has since been modelled or
whose predicate has stopped being applied in a proof.
"""

import glob
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
ISA = {
    "arm64": {
        "header": ROOT.parent / "arm64" / "arm64_sim_local_bpf.h",
        "lean": "Arm64",
    },
    "x86": {
        "header": ROOT.parent / "x86" / "x86_sim_local_bpf.h",
        "lean": "X86",
    },
}

# Families the AArch64 C chain branches on that the proofs do not model. Each
# value names the route host that covers the family; the host is not taken on
# trust -- it is checked against the recipe and against its own source.
A64_UNMODELLED = {
    "KPROG_ARM64_ADRP_HANDLED": "test_arm64_adrp_route_host.c",
    "KPROG_ARM64_CNEG_HANDLED": "test_arm64_cneg_route_host.c",
    "KPROG_ARM64_CSEL_HANDLED": "test_arm64_csel_route_host.c",
    "KPROG_ARM64_EXTREV_HANDLED": "test_arm64_extrev_route_host.c",
    "KPROG_ARM64_LDRSX_HANDLED": "test_arm64_ldrsx_op_route_host.c",
    "KPROG_ARM64_MOV_HANDLED": "test_arm64_dispatch_singleton_route_host.c",
    "KPROG_ARM64_MUL_HANDLED": "test_arm64_mul_route_host.c",
    "KPROG_ARM64_ORN_HANDLED": "test_arm64_orn_route_host.c",
    "KPROG_ARM64_REDUCTION_HANDLED": "test_arm64_reduction_route_host.c",
    "KPROG_ARM64_STLXR_HANDLED": "test_arm64_stlxr_route_host.c",
    "KPROG_ARM64_UNARY_HANDLED": "test_arm64_unary_route_host.c",
}

# The entry contexts each chain must route, and the macro a host sets to
# declare that it exercises one.
ABI_KINDS = ("XDP", "SKB")


def chain_macros(path):
    """The `KPROG_*_HANDLED` predicates the C chain actually branches on."""
    return set(re.findall(r"\b(KPROG_[A-Z0-9_]*HANDLED)\s*\(",
                          path.read_text()))


def spec_bindings(isa):
    """`{C macro: family name}` as the generator's own spec declares it."""
    out = {}
    for p in sorted(ROOT.glob("%s_dispatch_*_spec.json" % isa)):
        for entries in json.loads(p.read_text()).values():
            if not isinstance(entries, list):
                continue
            for e in entries:
                if not isinstance(e, dict) or "name" not in e:
                    continue
                for v in e.values():
                    if isinstance(v, str) and v.startswith("KPROG_") \
                            and v.endswith("_HANDLED"):
                        out[v] = (e["name"], p.name)
    return out


def modelled_names(lean):
    """(defined predicates, predicates a proof applies to `op`)."""
    defined, applied = set(), set()
    for p in ROOT.glob("KProgFormal/Generated%sDispatch*.lean" % lean):
        defined.update(re.findall(r"def ([A-Za-z0-9]+)Handled\b",
                                  p.read_text()))
    for p in sorted(ROOT.glob("KProgFormal/%sDispatch*.lean" % lean)):
        if p.name.startswith("Generated"):
            continue
        applied.update(re.findall(
            r"(?<![A-Za-z0-9_])([A-Za-z0-9]+)Handled\s+op\b", p.read_text()))
    return defined, applied


def gate_hosts():
    """The host binaries the recipe runs.

    A source file the gate never builds contributes nothing to it, so it cannot
    be the evidence for a claim about what the gate enforces.
    """
    mk = (ROOT / "Makefile").read_text()
    return set(re.findall(r"\./build/((?:test|cross)_\w+)\s*$", mk, re.M))


def why_unmodelled(macro, spec, defined, applied):
    """Why a chain predicate is not modelled, or None if it is.

    Modelled means three artifacts agree: a dispatch spec binds the C macro
    to a family name, the generated module defines that predicate, and a
    hand-written proof applies it to `op`.
    """
    bound = spec.get(macro)
    if bound is None:
        return "no dispatch spec binds this macro"
    name, src = bound
    if name not in defined:
        return ("%s binds it to family %r, but Generated*Dispatch.lean "
                "defines no %sHandled" % (src, name, name))
    if name not in applied:
        return ("the generated module defines %sHandled, but no proof applies "
                "it to `op`" % name)
    return None


def main():
    runs = gate_hosts()
    if not runs:
        print("check_dispatch_model: the recipe runs no test/cross host")
        return 1

    problems = []
    chains, gaps_by_isa, specs = {}, {}, {}
    for isa, cfg in ISA.items():
        chain = chain_macros(cfg["header"])
        if not chain:
            print("check_dispatch_model: the %s chain branches on no HANDLED "
                  "predicate" % isa)
            return 1
        spec = spec_bindings(isa)
        defined, applied = modelled_names(cfg["lean"])
        chains[isa] = chain
        gaps = {}
        for macro in sorted(chain):
            why = why_unmodelled(macro, spec, defined, applied)
            if why:
                gaps[macro] = why
        gaps_by_isa[isa] = gaps
        specs[isa] = spec
        # The tie must hold in both directions: a spec entry the chain stopped
        # branching on, or a generated predicate no spec binds, means the
        # generator and the chain have drifted apart.
        for macro in sorted(set(spec) - chain):
            problems.append("%s: %s binds %s, but the chain no longer "
                            "branches on that macro"
                            % (isa, spec[macro][1], macro))
        for name in sorted(defined - {n for n, _ in spec.values()}):
            problems.append("%s: Generated%sDispatch.lean defines %sHandled, "
                            "which no dispatch spec binds to a chain macro"
                            % (isa, cfg["lean"], name))
        # x86 records no exceptions, so a gap there is a plain finding.
        if isa == "x86":
            for macro, why in sorted(gaps.items()):
                problems.append("x86: the chain branches on %s, which the "
                                "proofs do not model: %s" % (macro, why))

    # A64_UNMODELLED must be exactly the measured set, in both directions, and
    # each entry must still be covered by a route host the gate runs.
    for macro in sorted(set(gaps_by_isa["arm64"]) - set(A64_UNMODELLED)):
        problems.append(
            "arm64: the chain branches on %s, which the proofs do not model "
            "(%s) -- model it, or record it in A64_UNMODELLED with the route "
            "host that covers it" % (macro, gaps_by_isa["arm64"][macro]))
    live = 0
    for macro, host in sorted(A64_UNMODELLED.items()):
        why = []
        if macro not in chains["arm64"]:
            why.append("the chain no longer branches on it")
        elif macro not in gaps_by_isa["arm64"]:
            why.append("the proofs now model it as %sHandled"
                       % specs["arm64"][macro][0])
        elif not (ROOT / host).exists():
            why.append("the file does not exist")
        elif host[:-len(".c")] not in runs:
            why.append("the recipe never runs build/%s" % host[:-len(".c")])
        elif "ARM64_SIM_L_EXEC" not in (ROOT / host).read_text():
            why.append("it never calls ARM64_SIM_L_EXEC, so it does not reach "
                       "the chain these predicates describe")
        if why:
            problems.append("arm64: %s is recorded as covered by %s, but %s"
                            % (macro, host, ", ".join(why)))
        else:
            live += 1

    # Entry contexts: each must be exercised by a host the gate actually runs.
    sources = [pathlib.Path(f) for f in glob.glob(str(ROOT / "test_*host.c"))
               + glob.glob(str(ROOT / "cross_*host.c"))]
    ctx = {(isa, kind): 0 for isa in ISA for kind in ABI_KINDS}
    for f in sources:
        if f.stem not in runs:
            continue
        src = f.read_text()
        for isa in ISA:
            if not re.search(r"\b%s_" % isa, src):
                continue
            for kind in ABI_KINDS:
                if "KPROG_ABI_KIND_%s" % kind in src:
                    ctx[(isa, kind)] += 1
    for isa in ISA:
        for kind in ABI_KINDS:
            if not ctx[(isa, kind)]:
                problems.append(
                    "%s: no host the recipe runs exercises the %s entry "
                    "context -- the chain routes it, and nothing drives it"
                    % (isa, kind))

    if problems:
        print("check_dispatch_model: %d finding(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    print("check_dispatch_model: AArch64 chain branches on %d predicates, %d "
          "are modelled three ways over (a spec binds the macro, Generated* "
          "defines the predicate, a proof applies it), and the %d left are "
          "the recorded set, each driven by a route host the recipe runs (%d "
          "of %d verified live); x86 branches on %d and all are modelled; "
          "both entry contexts are exercised by gate-run hosts (arm64 %d XDP"
          " / %d SKB, x86 %d XDP / %d SKB)"
          % (len(chains["arm64"]),
             len(chains["arm64"]) - len(gaps_by_isa["arm64"]),
             len(gaps_by_isa["arm64"]), live, len(A64_UNMODELLED),
             len(chains["x86"]),
             ctx[("arm64", "XDP")], ctx[("arm64", "SKB")],
             ctx[("x86", "XDP")], ctx[("x86", "SKB")]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
