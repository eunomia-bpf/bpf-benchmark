#!/usr/bin/env python3
"""Check that the two architectures resolve a lookup site the same way.

Both encoders answer the same question -- given a native map name, which
link-plan lookup site is this? -- and both account for the fact that the kernel
stores at most `BPF_OBJ_NAME_LEN - 1` bytes of a map name, so a longer source
name is compared by its truncated form.

They answer it with different *structures*, and that difference has a
consequence:

  x86     an exact pass, then a separate truncated pass that `bail!`s when two
          sites truncate-match the same name;

  AArch64 one predicate that accepts either an exact or a truncated match,
          used with `find`, so the first of several matching sites wins.

So for a name that truncation-matches more than one site, x86 reports an error
and AArch64 silently picks one. The same program can lower on one architecture
and fail on the other, or lower onto a different site.

This script measures that difference rather than assuming it, and fails if the
two ever converge *without* someone deciding they should -- the point is that
the divergence be known, not that either shape is wrong. A convergence is
equally worth a look, since it would mean one side changed.

Usage: check_lookup_ambiguity.py [--check]
"""

import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
_SRC = ROOT.parent / "x86" / "native_lab" / "native_link" / "src"
X86 = _SRC / "x86.rs"
A64 = _SRC / "main.rs"
BPF_H = (ROOT.parent.parent / "vendor" / "linux-framework" / "include"
         / "uapi" / "linux" / "bpf.h")

# The truncation length both sides implement.
TRUNC = re.compile(r'\.bytes\(\)\.take\((\d+)\)')
# x86's ambiguity error, matched as a bail! so a comment mentioning the
# phrase does not satisfy it.
# x86 reports ambiguity for both the lookup and the update path; a comment or
# a test assertion mentioning the phrase does not count, so the pattern is
# anchored on the bail! that raises it.
X86_AMBIG = re.compile(
    r'bail!\(\s*\n\s*"x86 [^"]*truncation-matches multiple', re.S)
# AArch64's single folded predicate.
A64_FOLDED = re.compile(
    r'source_map_name == native_map_name\s*\n\s*\|\|\s*\w*truncate')


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    for p in (X86, A64):
        if not p.exists():
            print("check_lookup_ambiguity: missing %s" % p)
            return 1

    x86 = X86.read_text(errors="ignore")
    a64 = A64.read_text(errors="ignore")

    problems = []

    # Both must truncate at the same length, and that length must be the
    # kernel's name limit minus the terminator.
    lens = {int(m) for m in TRUNC.findall(x86)} | \
           {int(m) for m in TRUNC.findall(a64)}
    if BPF_H.exists():
        m = re.search(r'#define\s+BPF_OBJ_NAME_LEN\s+(\d+)U', BPF_H.read_text(
            errors="ignore"))
        if m:
            want = int(m.group(1)) - 1
            if lens != {want}:
                problems.append(
                    "truncation lengths %s, but BPF_OBJ_NAME_LEN - 1 is %d"
                    % (sorted(lens), want))
    if len(lens) != 1:
        problems.append("the two sides truncate at different lengths: %s"
                        % sorted(lens))

    x86_errors = bool(X86_AMBIG.search(x86))
    a64_folds = bool(A64_FOLDED.search(a64))
    a64_errors = bool(X86_AMBIG.search(a64))

    # The measured divergence: x86 errors on ambiguity, AArch64 folds the two
    # comparisons into one find. If either changes, say so.
    # Both the lookup and the update path must report it, not just one.
    for kind in ("bpf_map_lookup_elem", "bpf_map_update_elem"):
        if kind not in x86:
            continue
        if not re.search(r'bail!\(\s*\n\s*"x86 %s[^"]*'
                         r'truncation-matches multiple' % kind, x86, re.S):
            problems.append("x86's %s path no longer reports a "
                            "truncation-ambiguous name" % kind)
    if not x86_errors:
        problems.append("x86 no longer reports a truncation-ambiguous name, "
                        "so ambiguity may now be resolved silently there too")
    if a64_errors:
        problems.append("AArch64 now reports truncation ambiguity -- if that "
                        "is intended, update this check's expectation")
    if not a64_folds:
        problems.append("AArch64's lookup predicate no longer folds exact and "
                        "truncated matching into one comparison; re-measure")

    if problems:
        print("check_lookup_ambiguity: %d finding(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    print("check_lookup_ambiguity: both sides truncate at %d (the kernel's "
          "name limit); x86 errors on a truncation-ambiguous name and "
          "AArch64 resolves it by first match, which is the known divergence"
          % lens.pop())
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))