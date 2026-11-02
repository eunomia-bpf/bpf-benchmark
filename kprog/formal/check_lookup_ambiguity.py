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
"""

import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
_SRC = ROOT.parent / "x86" / "native_lab" / "native_link" / "src"
X86 = _SRC / "x86.rs"
A64 = _SRC / "main.rs"
BPF_H = (ROOT.parent.parent / "vendor" / "linux-framework" / "include"
         / "uapi" / "linux" / "bpf.h")
FILES = (X86, A64, BPF_H)

# The truncation length each side implements, read from the helper that does
# it. A file-wide search for `.bytes().take(N)` would miss a side that spells
# the iterator differently and would pick up an unrelated `take` elsewhere, so
# the name is anchored and the length is required to be stated: a helper that
# no longer says how far it truncates is reported, not dropped from a set that
# still has the other side's 15.
TRUNC_FN = re.compile(
    r'fn\s+(\w*truncate_bpf_obj_name)\s*\([^)]*\)[^{]*\{(.*?)\}', re.S)
TRUNC_TAKE = re.compile(r'\.take\(\s*(\d+)\s*\)')
# The kernel's own name limit, spelled either way the uapi header admits.
NAME_LEN = re.compile(r'^#define\s+BPF_OBJ_NAME_LEN\s+(\d+)U?\s*$', re.M)
# x86's ambiguity error, matched as a bail! so a comment or a test assertion
# mentioning the phrase does not satisfy it. Both the lookup and the update
# path must raise it, not just one.
X86_AMBIG = r'bail!\(\s*\n\s*"x86 %s[^"]*truncation-matches multiple'
# AArch64's expected divergence, and the error that would end it. Its messages
# are not prefixed "x86", so the absence is tested without that prefix.
A64_FOLDED = re.compile(
    r'source_map_name == native_map_name\s*\n\s*\|\|\s*\w*truncate')
A64_AMBIG = re.compile(
    r'bail!\(\s*\n\s*"[^"]*truncation-matches multiple', re.S)


def trunc_length(text, where):
    """The length the file's truncation helper states, plus any problem."""
    hits = TRUNC_FN.findall(text)
    if len(hits) != 1:
        return None, ("%s states %d truncation helper(s); this check reads "
                      "one per file" % (where, len(hits)))
    name, body = hits[0]
    takes = TRUNC_TAKE.findall(body)
    if len(takes) != 1:
        return None, ("%s's %s does not state exactly one truncation length "
                      "(found %d)" % (where, name, len(takes)))
    return int(takes[0]), None


def main(argv):
    for f in FILES:
        if not f.exists():
            print("check_lookup_ambiguity: missing %s" % f)
            return 1

    x86 = X86.read_text(errors="ignore")
    a64 = A64.read_text(errors="ignore")
    problems = []

    # Each side states its own truncation length, and both must equal the
    # kernel's name limit less the terminator. Reading the length out of the
    # helper that applies it -- instead of out of any `take(N)` in the file --
    # is what stops a side that re-spells its iterator from dropping quietly
    # out of a comparison the other side still satisfies.
    stated = [trunc_length(text, where) for where, text in
              (("x86", x86), ("AArch64", a64))]
    problems += [p for _, p in stated if p]
    kernel = NAME_LEN.findall(BPF_H.read_text(errors="ignore"))
    if len(kernel) != 1:
        problems.append("%s states BPF_OBJ_NAME_LEN %d times"
                        % (BPF_H, len(kernel)))
    lengths = [n for n, p in stated if p is None]
    if len(lengths) == 2 and len(kernel) == 1:
        want = int(kernel[0]) - 1
        if lengths[0] != lengths[1]:
            problems.append("the two sides truncate at different lengths: %s"
                            % sorted(lengths))
        elif lengths[0] != want:
            problems.append("both sides truncate at %d, but "
                            "BPF_OBJ_NAME_LEN - 1 is %d" % (lengths[0], want))

    # The measured divergence: x86 errors on an ambiguous name -- on the
    # lookup path and the update path, not just one -- while AArch64 folds the
    # two comparisons into a single `find`. If either shape changes, say so.
    for kind in ("bpf_map_lookup_elem", "bpf_map_update_elem"):
        if not re.search(X86_AMBIG % kind, x86, re.S):
            problems.append("x86's %s path no longer reports a "
                            "truncation-ambiguous name" % kind)
    if A64_AMBIG.search(a64):
        problems.append("AArch64 now reports truncation ambiguity -- if that "
                        "is intended, update this check's expectation")
    if not A64_FOLDED.search(a64):
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
          % lengths[0])
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))