#!/usr/bin/env python3
"""Report the axiom footprint of every theorem the gate proves.

The safety section states that the tree divides three ways under
`#print axioms` -- theorems depending on no axioms, theorems reaching
`Lean.ofReduceBool` and so assuming the compiler, and theorems using only
`propext`/`Quot.sound`/`Classical.choice` -- and quotes six figures from
that split. Those figures were recorded from throwaway probes twice, and were
wrong both times: the first probe scored "does not depend on any axioms"
through a string test that also matched its error path, and the second
counted one class instead of the tree.

This script is the reproducible source. It is deliberately not a Makefile
target: 306 `lake env lean` invocations cost several minutes, and the gate
already takes seven. It prints the counts; `check_lean_claims.py` holds them
as recorded values and enforces that they partition the tree, so a stale
figure fails there while a fresh one is regenerated here.

Usage: axiom_census.py [--root .]
"""
import argparse
import collections
import glob
import os
import re
import subprocess
import sys
import tempfile

THEOREM = re.compile(r'^(?:@\[[^\]]*\]\s*)?theorem (\w+)[^\n]*(?:\n[ \t].*)*',
                     re.M)


def modules(root):
    """`{module: ([theorem], namespace)}` for every proved theorem.

    The namespace is read from the source rather than assumed to be the
    module name: three modules declare one that differs (`DispatchTotality`
    in `Arm64DispatchTotality`), and a name outside `KProgFormal`'s
    namespace does not resolve.
    """
    out = {}
    for path in sorted(glob.glob(os.path.join(root, "KProgFormal", "*.lean"))):
        src = open(path, errors="ignore").read()
        names = [m.group(1) for m in THEOREM.finditer(src) if ":=" in m.group(0)]
        if not names:
            continue
        space = re.search(r"^namespace (KProgFormal(?:\.\w+)*)", src, re.M)
        out[os.path.basename(path)[:-5]] = (
            names, space.group(1) if space else "KProgFormal")
    return out


def footprints(root, module, names, space):
    """`{theorem: frozenset(axiom)}` for one module, in one invocation.

    One invocation per module rather than per theorem: `#print axioms` costs
    0.55 s whether it prints one theorem or forty, and the whole tree is 306
    modules. A module whose theorems are not in `KProgFormal`'s namespace is
    retried with the module name as a namespace, which three modules need.
    """
    for prefix in ("KProgFormal", space):
        body = "\n".join("#print axioms %s.%s" % (prefix, name)
                          for name in names)
        handle, path = tempfile.mkstemp(suffix=".lean")
        with os.fdopen(handle, "w") as fh:
            fh.write("import KProgFormal.%s\n%s\n" % (module, body))
        done = subprocess.run(["lake", "env", "lean", path],
                              capture_output=True, text=True, cwd=root,
                              timeout=1800)
        os.unlink(path)
        found, missing = {}, 0
        for line in (done.stdout + done.stderr).splitlines():
            hit = re.match(r"'.*?\.(\w+)' (depends on axioms: (.*)|"
                           r"does not depend on any axioms)", line)
            if not hit:
                continue
            found[hit.group(1)] = (frozenset()
                                   if hit.group(3) is None
                                   else frozenset(a.strip()
                                                  for a in hit.group(3)
                                                  .strip("[]").split(",")))
        missing = [n for n in names if n not in found]
        if not missing:
            return found
    raise SystemExit("axiom_census: no footprint for %s in %s"
                     % (", ".join(missing), module))


def main(argv):
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=here)
    args = ap.parse_args(argv[1:])

    counts = collections.Counter()
    choice = collections.Counter()
    for module, (names, space) in modules(args.root).items():
        for name, axioms in footprints(args.root, module, names,
                                       space).items():
            if not axioms:
                counts["none"] += 1
            elif "Lean.ofReduceBool" in axioms:
                counts["compiler"] += 1
            elif "Classical.choice" in axioms:
                counts["kernel-choice"] += 1
            else:
                counts["kernel"] += 1
            if "Classical.choice" in axioms:
                choice["all"] += 1
                if "Lean.ofReduceBool" in axioms:
                    choice["compiler"] += 1
                else:
                    choice["kernel-only"] += 1
    total = sum(counts.values())
    for key in ("none", "compiler", "kernel", "kernel-choice"):
        print("%-14s %d" % (key, counts[key]))
    print("%-14s %d" % ("total", total))
    print("choice: %d all, %d of them compiler-assuming, %d kernel-only"
          % (choice["all"], choice["compiler"], choice["kernel-only"]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))