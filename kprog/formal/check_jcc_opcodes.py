#!/usr/bin/env python3
"""Check the Rust encoder's emitted jcc opcodes against the condition contract.

The x86 artifact encoder is Rust (`x86/native_lab/native_link`) and it emits
conditional jumps as *raw opcodes*, writing them next to a comment naming the
mnemonic: `append_x86_jcc_rel8(&mut body, 0x75); // jne skip ref update`. The
C-side simulator decides conditions from the `X86_CC_*` table. Neither side
reads the other, and the opcode is just a number, so an off-by-one in a
hand-written constant compiles, runs, and branches on the wrong condition.

What makes the two comparable is x86's own encoding rule: the short conditional
jump opcodes are `0x70 + condition_code`, and the `X86_CC_*` values are the
condition codes. So for each commented jcc site, the opcode must equal
`0x70 + X86_CC_<mnemonic suffix>`.

This checks every such site the encoder writes. It is a narrow but real
cross-language link: one side is Rust byte emission, the other is the generated
C condition contract, and nothing else in the tree joins them.

Usage: check_jcc_opcodes.py [--check]
"""

import argparse
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
# kprog/formal -> kprog -> repo
ENCODER = (ROOT.parent / "x86" / "native_lab" / "native_link" / "src"
           / "x86.rs")
SIM_H = ROOT.parent / "x86" / "x86_sim.h"

# Short-form conditional jump opcodes are 0x70 + condition code.
JCC_BASE = 0x70

# A commented jcc emission, in either of the two forms the encoder uses:
#   append_x86_jcc_rel8(&mut body, 0x75); // jne ...
#   bytes.extend_from_slice(&[0x73, len]); // jae ...
SITE = re.compile(
    r'(?:append_x86_jcc_rel(?:8|32)\([^;]*?0x([0-9a-f]{2})[^;]*;'
    r'|\[0x([0-9a-f]{2}),[^\]]*\];)\s*//\s*(j[a-z]+)')

CC = re.compile(r'#define\s+X86_CC_([A-Z]+)\s+(\d+)U')


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv[1:])

    if not ENCODER.exists() or not SIM_H.exists():
        print("check_jcc_opcodes: missing %s" % (ENCODER if not ENCODER.exists()
                                                 else SIM_H))
        return 1

    codes = {name.lower(): int(value) for name, value in
             CC.findall(SIM_H.read_text(errors="ignore"))}
    if not codes:
        print("check_jcc_opcodes: parsed no X86_CC_* codes from %s" % SIM_H)
        return 1

    sites = SITE.findall(ENCODER.read_text(errors="ignore"))
    if not sites:
        print("check_jcc_opcodes: found no commented jcc sites in %s" % ENCODER)
        return 1

    problems = []
    seen_any = 0
    for high, low, mnemonic in sites:
        opcode = int(high or low, 16)
        suffix = mnemonic[1:]
        if suffix not in codes:
            problems.append("%s: no X86_CC_%s in the contract"
                            % (mnemonic, suffix.upper()))
            continue
        want = JCC_BASE + codes[suffix]
        seen_any += 1
        if opcode != want:
            problems.append("%s: encoder writes 0x%02x, but 0x70 + "
                            "X86_CC_%s(%d) is 0x%02x"
                            % (mnemonic, opcode, suffix.upper(),
                               codes[suffix], want))

    if problems:
        print("check_jcc_opcodes: %d problem(s) over %d site(s)"
              % (len(problems), len(sites)))
        for p in problems:
            print("  " + p)
        return 1

    names = sorted({m for _, _, m in sites})
    print("check_jcc_opcodes: %d commented jcc site(s) (%s) all encode "
          "0x70 + their condition code"
          % (seen_any, ", ".join(names)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))