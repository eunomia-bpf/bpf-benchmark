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

# Every conditional-jump emission, commented or not. The two forms differ only
# in the opcode base: the short form is 0x70 + condition code and the near form
# is 0x80 + condition code.
# Both spellings the encoder uses, and the name it binds the site to -- that
# binding is often the only statement of which condition was intended:
#   let jbe_out = append_x86_jcc_rel32(&mut bytes, 0x86);
#   append_x86_jcc_rel8(&mut body, 0x75); // jne skip ref update
SITE = re.compile(
    r'(?:let\s+(?P<bind>\w+)\s*=\s*)?append_x86_jcc_rel(8|32)\('
    r'[^;]*?0x([0-9a-f]{2})[^;]*;'
    r'(?:\s*//\s*([a-z]+))?')

# The base each form adds to the condition code.
BASE = {"8": 0x70, "32": 0x80}

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

    # condition code -> mnemonic, from the contract itself
    by_code = {value: name.lower() for name, value in codes.items()}

    by_code = {value: name.lower() for name, value in codes.items()}

    problems = []
    sites = []
    commented = 0
    named = 0
    for m in SITE.finditer(ENCODER.read_text(errors="ignore")):
        bind, form, ophex, mnemonic = (m.group("bind"), m.group(2),
                                        m.group(3), m.group(4))
        opcode = int(ophex, 16)
        base = BASE[form]
        width = "rel8" if form == "8" else "rel32"
        code = opcode - base

        # The site must name a condition, either in its comment or in the
        # identifier it binds. A binding like `jbe_out` is the only statement
        # of intent for an uncommented emission.
        intent = mnemonic
        if intent is None and bind:
            bm = re.match(r'j([a-z]+?)_?out$', bind)
            if bm:
                intent = "j" + bm.group(1)
        if intent:
            suffix = intent[1:]
            if suffix not in codes:
                problems.append("%s: no X86_CC_%s in the contract"
                                % (intent, suffix.upper()))
                continue
            if codes[suffix] != code:
                problems.append(
                    "%s at %s: opcode 0x%02x implies condition code %d, "
                    "but X86_CC_%s is %d"
                    % (intent, width, opcode, code, suffix.upper(),
                       codes[suffix]))
                continue
            if mnemonic:
                commented += 1
            else:
                named += 1
        else:
            if code not in by_code:
                problems.append(
                    "%s opcode 0x%02x implies condition code %d, which is "
                    "not in the contract" % (width, opcode, code))
                continue
        sites.append((opcode, code))

    if not sites and not problems:
        print("check_jcc_opcodes: found no conditional-jump sites in %s"
              % ENCODER)
        return 1

    if problems:
        print("check_jcc_opcodes: %d problem(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    print("check_jcc_opcodes: %d conditional-jump site(s) all encode "
          "their condition code (%d by mnemonic comment, %d by binding "
          "name)" % (len(sites), commented, named))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))