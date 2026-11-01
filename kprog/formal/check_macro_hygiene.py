#!/usr/bin/env python3
"""Check that every generated C flag/condition macro parenthesizes its
parameters.

A macro whose body uses a parameter as an operand of a binary operator is
correct only for arguments that happen to bind tightly. The five x86 flag
generators originally emitted `(A < B)` with bare `A`, so a call passing
`a & mask` expanded to `(a & mask < b)`, which C parses as
`a & (mask < b)` -- the carry computed from the wrong comparison. The
condition evaluators had the same defect: `(N == V)` became
`(a + b == V)`, i.e. `a + (b == V)`. Neither showed up in the simulators,
which pass only plain variables at every call site.

The rule this enforces: a parameter must appear either strictly as `(P)`,
or as a whole function-call argument (followed by `,` or `)` with the
enclosing paren closing immediately), or adjacent only to operators that
bind tighter than any caller's expression could break -- which in practice
means the `(P)` form. Anything else is reported with its context.

Exit 1 with a list of offenders.
"""

import glob
import os
import re
import sys

BINARY = r'(?:<<|>>|<=|>=|==|!=|&&|\|\||[<>+\-*/%&|^])'

# Parameters that are arguments to a call rather than operands, and the
# `void` placeholder.
SKIP = {"void", "UNSUPPORTED"}


def params_of(first_line):
    m = re.match(r'#define\s+(\w+)\(([^)]*)\)', first_line)
    if not m:
        return None, None
    return m.group(1), [p.strip() for p in m.group(2).split(',') if p.strip()]


def macros(path):
    lines = open(path).read().split("\n")
    i = 0
    while i < len(lines):
        if lines[i].startswith("#define"):
            buf = [lines[i]]
            while lines[i].rstrip().endswith("\\"):
                i += 1
                buf.append(lines[i])
            yield "\n".join(buf)
        i += 1


def offenders(paths):
    out = []
    for path in sorted(paths):
        for macro in macros(path):
            first = macro.split("\n")[0]
            name, ps = params_of(first)
            if not ps:
                continue
            # A macro written on one line has its body on the same line as the
            # parameter list. Taking only what follows the first newline left
            # every single-line macro unchecked -- 323 of them, 621 parameters --
            # while the summary still reported all headers as clean.
            head, _, rest = macro.partition("\n")
            body = rest if rest else head[head.index(")") + 1:]
            for p in ps:
                if p in SKIP:
                    continue
                for m in re.finditer(r'(?<![\w])' + re.escape(p) + r'(?![\w])', body):
                    s, e = m.start(), m.end()
                    before = body[s - 1] if s > 0 else ""
                    after = body[e] if e < len(body) else ""
                    if before == "(" and after == ")":
                        continue  # strictly (P)
                    tail = body[e:e + 8]
                    head = body[max(0, s - 8):s]
                    if re.match(r'\s*' + BINARY, tail) or re.search(BINARY + r'\s*$', head):
                        out.append((path, name, p,
                                    body[max(0, s - 45):s + 45].replace("\n", " ")))
    return out


def main(argv):
    # Patterns are relative to this script, so the check works from any cwd.
    here = os.path.dirname(os.path.abspath(__file__))
    # The default covers every header the simulators compile, not just the
    # generated ones: the defect this check exists for was found in a
    # hand-written condition evaluator, so restricting the scan to generated/
    # left the population that produced the bug unexamined.
    defaults = ["generated/*.h", "../x86/*.h", "../arm64/*.h"]
    patterns = [os.path.join(here, p) for p in (argv[1:] or defaults)]
    paths = []
    for pat in patterns:
        paths.extend(glob.glob(pat))
    if not paths:
        print("check_macro_hygiene: no headers matched %s" % " ".join(patterns))
        return 1
    bad = offenders(paths)
    if bad:
        print("check_macro_hygiene: %d unparenthesized parameter use(s)" % len(bad))
        for path, name, p, ctx in bad:
            print("  %s: %s [%s]: ...%s..." % (path, name, p, ctx))
        return 1
    # Named separately from the contract count: `generated/*.h` is one per
    # contract, and the rest are the hand-written simulator headers.
    gen = [q for q in paths if os.sep + "generated" + os.sep in q]
    print("check_macro_hygiene: all %d headers parenthesize their parameters "
          "(%d generated, %d hand-written)"
          % (len(paths), len(gen), len(paths) - len(gen)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))