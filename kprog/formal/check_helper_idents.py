#!/usr/bin/env python3
"""Check the AArch64 helper-ident table against the kernel's own helper enum.

`arm64_helper_idents_spec.json` states, for each of 61 BPF helpers, the kernel
id the encoder renumbers against. The ids are hand-maintained in that spec, and
the generated header's own assertions only pin them to the spec -- so a wrong
id there would generate a self-consistent header, pass every oracle, and
renumber a program onto the wrong helper at runtime.

The independent source is `bpf_helper_defs.h`, which the vendored libbpf ships
with one entry per helper:

    static void *(* const bpf_map_lookup_elem)(void *map, const void *key)
        = (void *) 1;

Parsing those gives the kernel's id for every name. This script compares the
spec's 61 rows against it and reports any name whose id differs, any name the
kernel does not define, and -- separately -- whether the set of names matches
what the simulator itself forwards to, since the header's docstring claims these
are "the ids the AArch64 simulator recognizes".

Usage: check_helper_idents.py [--check]
"""

import argparse
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent

# The vendored libbpf header, relative to the repo root (this file lives in
# kprog/formal).
DEFS = (ROOT.parent.parent / "runner" / "build-host-docker-llvmbpf" / "vendor"
        / "libbpf" / "prefix" / "include" / "bpf" / "bpf_helper_defs.h")

SPEC = ROOT / "arm64_helper_idents_spec.json"
SIM = ROOT.parent / "arm64" / "arm64_sim_local_bpf.h"

# One helper definition per entry:
#   static R (* const bpf_NAME)(...) = (void *) ID;
ENTRY = re.compile(r'\(\*\s*const\s+bpf_(\w+)\)[^=]*=\s*\(void \*\)\s*(\d+)')

# The simulator forwards to a helper by naming it in a macro.
SIM_CALL = re.compile(r'ARM64_SIM_BPF_CALL_bpf_([a-z0-9_]+)\s*\(')


def short(name):
    return name[4:] if name.startswith("bpf_") else name


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    if not DEFS.exists():
        print("check_helper_idents: kernel header not found at %s" % DEFS)
        return 1

    kern = {}
    for m in ENTRY.finditer(DEFS.read_text(errors="ignore")):
        kern[m.group(1)] = int(m.group(2))
    if not kern:
        print("check_helper_idents: parsed no helpers from %s" % DEFS)
        return 1

    spec = json.loads(SPEC.read_text())["rows"]
    sim_names = set(SIM_CALL.findall(SIM.read_text(errors="ignore")))

    wrong_id = []
    unknown = []
    for row in spec:
        name = short(row["name"])
        want = kern.get(name)
        if want is None:
            unknown.append(row["name"])
        elif want != row["id"]:
            wrong_id.append((row["name"], row["id"], want))

    # The header claims the table is the set the simulator recognizes, so the
    # two name sets must agree in both directions.
    spec_names = {short(r["name"]) for r in spec}
    not_forwarded = sorted(spec_names - sim_names)
    not_tabled = sorted(sim_names - spec_names)

    problems = (len(wrong_id) + len(unknown) + len(not_forwarded)
                + len(not_tabled))
    if problems:
        print("check_helper_idents: %d problem(s) over %d rows"
              % (problems, len(spec)))
        for name, got, want in wrong_id:
            print("  %s: spec id %d, kernel id %d" % (name, got, want))
        for name in unknown:
            print("  %s: not in the kernel's helper enum" % name)
        for name in not_forwarded:
            print("  %s: tabled but the simulator does not forward to it"
                  % name)
        for name in not_tabled:
            print("  %s: the simulator forwards to it but it is not tabled"
                  % name)
        return 1

    print("check_helper_idents: %d helpers, all ids match the kernel enum, "
          "and the name set matches what the simulator forwards to"
          % len(spec))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))