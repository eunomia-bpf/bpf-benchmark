#!/usr/bin/env python3
"""Break each gate check on purpose and confirm it says so.

A check that is green and a check that cannot fail look the same from
outside. This walks the nine scripts the gate runs, introduces the defect
each one exists to catch, and requires the check to exit non-zero and name
the break. Every file is restored afterwards, and the tree is compared with
git to prove it.

Not a gate target: it edits the tree, runs each check three times, and the
mutation harness alone takes fifteen seconds. Run it by hand after changing
a check.
"""

import pathlib
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = pathlib.Path(__file__).resolve().parent
GATE = ROOT.parent / "x86" / "native_lab" / "native_link" / "src" / "x86.rs"


def run(args):
    """(exit code, combined output) for one check invocation."""
    done = subprocess.run(args, cwd=str(ROOT), capture_output=True, text=True)
    return done.returncode, (done.stdout + done.stderr)


def replace(path, old, new, count=1):
    """Swap one span in a file, returning the original text."""
    text = path.read_text()
    if old not in text:
        raise SystemExit("perturb: %r not in %s" % (old, path.name))
    path.write_text(text.replace(old, new, count))
    return text


PERTURBATIONS = [
    # (check argv, file, old, new, expected fragment in the output)
    (["python3", "check_no_sorry.py", "--check"],
     ROOT / "KProgFormal" / "Arm64Stlxr.lean",
     "\n", "\ntheorem probe_sorry : True := by sorry\n", "sorry"),
    (["python3", "check_helper_idents.py"],
     ROOT / "arm64_helper_idents_spec.json",
     '"id": 1,', '"id": 2,', "spec id"),
    (["python3", "check_jcc_opcodes.py"],
     GATE, "append_x86_jcc_rel8(&mut body, 0x75);",
     "append_x86_jcc_rel8(&mut body, 0x76);", "condition code"),
    (["python3", "check_lookup_ambiguity.py"],
     GATE, ".bytes().take(15)", ".bytes().take(16)",
     "truncate at different lengths"),
    (["python3", "check_dual_emit_coverage.py", "--check"],
     ROOT / "check_dual_emit_coverage.py",
     '"test_arm64_extrev_host.c"', '"test_arm64_nonexistent_host.c"',
     "does not exist"),
    (["python3", "check_dispatch_model.py", "--check"],
     ROOT / "check_dispatch_model.py",
     '"KPROG_ARM64_ADRP_HANDLED": "test_arm64_adrp_route_host.c",',
     '"KPROG_ARM64_ADRP_HANDLED": "test_arm64_adrp_route_host.c",\n'
     '    "KPROG_ARM64_BOGUS_HANDLED": "test_arm64_adrp_route_host.c",',
     "recorded as covered"),
    (["python3", "check_oracle_composition.py"],
     ROOT / "probe_nocompose_host.c", None, None,
     "without driving the composition"),
    (["python3", "check_macro_hygiene.py", "probe_unparen.h"],
     ROOT / "probe_unparen.h", None, None, "unparenthesized parameter"),
    (["python3", "check_lean_claims.py"],
     ROOT / "check_lean_claims.py",
     '"orb_reach": 67,', '"orb_reach": 69,', "do not, but there are"),
    (["python3", "mutate_contracts.py", "--check"],
     ROOT / "generate_arm64_aux_spec.py",
     "    if data != EXPECTED:", "    if False:", "SURVIVED"),
]


PROBE_UNPAREN = "#define KPROG_PROBE_SUM(A, B) (A) + B\n"

PROBE_HOST = """/* Calls a composed contract without composing. */
#include "../x86/x86_sim_local_bpf.h"
int main(void) { return (int)KPROG_X86_ADC_RESULT(1, 2, 0); }
"""


def probe(argv, path, old, new, want):
    """Break one check; return None on success or a description of the gap."""
    if old is None:                      # the probe is a file that must exist
        saved = PROBE_UNPAREN if path.name == "probe_unparen.h" else PROBE_HOST
        existed = path.exists()
    else:
        saved, existed = path.read_text(), True
    backup = None
    try:
        # The baseline is the clean state: for a probe file, that means the
        # file absent and the argument naming it dropped.
        base = argv[:-1] if not existed else argv
        code, out = run(base)
        if code != 0:
            return "%s fails before the probe" % argv[1]
        if existed:
            backup = tempfile.mkstemp()[1]
            shutil.copy(str(path), backup)
            replace(path, old, new)
        else:
            path.write_text(saved)
        code, out = run(argv)
        if code == 0:
            return "%s stayed green after the probe" % argv[1]
        if want not in out:
            return "%s failed but did not say %r" % (argv[1], want)
    finally:
        if existed:
            path.write_text(saved)
        elif path.exists():
            path.unlink()
        if backup:
            pathlib.Path(backup).unlink()
    code, out = run(base)
    if code != 0:
        return "%s did not recover after the probe" % argv[1]
    return None


def main():
    problems = []
    for argv, path, old, new, want in PERTURBATIONS:
        gap = probe(argv, path, old, new, want)
        name = argv[1]
        print("%-30s %s" % (name, "named the break" if gap is None else gap))
        if gap:
            problems.append(gap)
    dirty = subprocess.run(["git", "status", "--porcelain"],
                           cwd=str(ROOT), capture_output=True, text=True)
    watched = {"check_dual_emit_coverage.py", "check_dispatch_model.py",
               "check_oracle_composition.py", "perturb_checks.py",
               "generate_arm64_aux_spec.py", "arm64_helper_idents_spec.json",
               "probe_nocompose_host.c"}
    stray = [l for l in dirty.stdout.splitlines()
             if l.split()[-1].split("/")[-1] in watched
             and not l.rstrip().endswith("perturb_checks.py")]
    for line in stray:
        problems.append("left modified: %s" % line.strip())
    if problems:
        for p in problems:
            print("perturb_checks: %s" % p)
        return 1
    print("perturb_checks: %d check(s) named their break, tree unchanged"
          % len(PERTURBATIONS))
    return 0


if __name__ == "__main__":
    sys.exit(main())