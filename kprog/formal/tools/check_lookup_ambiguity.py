#!/usr/bin/env python3
"""Check map-name width and reject ambiguous site selection on both ISAs.

Rust regressions exercise the real resolvers, including exact-name priority,
unique truncation, error-state preservation and per-call update metadata.
"""

import os
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
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

    x86 = X86.read_text()
    a64 = A64.read_text()
    problems = []

    # Each side states its own truncation length, and both must equal the
    # kernel's name limit less the terminator. Reading the length out of the
    # helper that applies it -- instead of out of any `take(N)` in the file --
    # is what stops a side that re-spells its iterator from dropping quietly
    # out of a comparison the other side still satisfies.
    stated = [trunc_length(text, where) for where, text in
              (("x86", x86), ("AArch64", a64))]
    problems += [p for _, p in stated if p]
    kernel = NAME_LEN.findall(BPF_H.read_text())
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

    # Both lookup and update paths must diagnose ambiguity before consuming
    # metadata. Functional regressions below verify behavior, beyond spelling.
    for kind in ("bpf_map_lookup_elem", "bpf_map_update_elem"):
        if not re.search(X86_AMBIG % kind, x86, re.S):
            problems.append("x86's %s path no longer reports a "
                            "truncation-ambiguous name" % kind)
    for kind in ("bpf_map_lookup_elem", "bpf_map_update_elem"):
        pattern = r'bail!\(\s*\n\s*"arm64 %s[^"]*truncation-matches multiple' % kind
        if not re.search(pattern, a64, re.S):
            problems.append("AArch64's %s path does not report truncation ambiguity" % kind)

    if problems:
        print("check_lookup_ambiguity: %d finding(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    env = dict(os.environ, CARGO_TARGET_DIR=str(ROOT / "build/native-link"))
    subprocess.run(["cargo", "test", "--locked", "--quiet", "--jobs", "1",
                    "--manifest-path", str(_SRC.parent / "Cargo.toml"), "_selection_"],
                   env=env, check=True)
    print("check_lookup_ambiguity: both ISAs truncate at %d and reject ambiguous map sites; "
          "production resolver regressions pass" % lengths[0])

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))