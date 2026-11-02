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
condition codes. So for each jcc site, the opcode must equal
`0x70 + X86_CC_<mnemonic suffix>`.

It then applies the same argument twice more: to the AArch64 B.cond words the
same crate emits, whose condition lives in a literal's low four bits, and to
the two architectures' bpf_tail_call lowerings, whose limit, comparison and
increment must agree with each other and with the kernel's. Each link is
narrow -- one side is Rust byte emission, the other is a generated C contract
or the vendored kernel -- and nothing else in the tree joins them.
"""

import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent
# kprog/formal -> kprog -> repo
_SRC = ROOT.parent / "x86" / "native_lab" / "native_link" / "src"
ENCODER = _SRC / "x86.rs"
# The AArch64 branch encodings live in the same crate's main.rs.
ENCODER_A64 = _SRC / "main.rs"
SIM_H = ROOT.parent / "x86" / "x86_sim.h"
# The kernel's own tail-call limit, the value both lowerings have to match.
BPF_H = (ROOT.parent.parent / "vendor" / "linux-framework" / "include"
         / "linux" / "bpf.h")
FILES = (ENCODER, ENCODER_A64, SIM_H, BPF_H)

# Every constant this check reads is a Rust integer literal, and Rust admits
# several spellings of the same value: `0xEB`, `0xeb`, `0XEB`, `0x1_F`, `235`.
# Reading only one of them makes a site vanish from a check that claims to see
# every one, which is exactly how the three unconditional jumps went unseen, so
# literals are parsed rather than pattern-matched on a preferred form.
INT_LIT = re.compile(r'(?:0[xX][0-9a-fA-F](?:_?[0-9a-fA-F])*|\d+(?:_\d+)*)\Z')


def literal(token):
    """The value of a Rust integer literal, or None if it is not one."""
    token = token.strip()
    return int(token, 0) if INT_LIT.match(token) else None


# Every jump the helper emits, commented or not. The two forms differ only in
# the opcode base: the short form is 0x70 + condition code and the near form is
# 0x80 + condition code. A site states its intent either in a trailing comment
# or in the identifier it binds -- that binding is often the only statement of
# which condition was meant:
#   let jbe_out = append_x86_jcc_rel32(&mut bytes, 0x86);
#   append_x86_jcc_rel8(&mut body, 0x75); // jne skip ref update
# How the pattern matches was settled by mutation, not by reading. The opcode is
# the call's second argument, split off the argument list rather than searched
# for in it, and the class excludes newline so a call cannot reach past its own
# line: the old `[^;]*?` ran from the helper's own `fn` definition down to a
# later `0x86`, making the definition a phantom site. The opcode is parsed as a
# literal, because the old `0x[0-9a-f]{2}` class was case-sensitive and silently
# dropped the three unconditional jumps the encoder writes as `0xEB`. A mnemonic
# comment is matched without regard to case, so an uppercase one states its
# intent instead of falling through unverified.
SITE = re.compile(
    r'(?:let\s+(?P<bind>\w+)\s*=\s*)?(?<!fn )append_x86_jcc_rel(8|32)\('
    r'([^)\n]*)\)[^;\n]*(?:;\s*(?://\s*(\w+)))?')

# The base each form adds to the condition code.
BASE = {"8": 0x70, "32": 0x80}

# The helper is also how the encoder emits a short unconditional jump: it
# pushes opcode + zero displacement, which for 0xEB is `jmp rel8` whose
# displacement is patched later. Such a site states no condition, so it is
# checked as the jump it is instead of being left unseen.
JMP_REL8 = 0xEB

CC = re.compile(r'#define\s+X86_CC_([A-Z]+)\s+(\d+)U')

# AArch64 conditional branches are built from a literal whose low four bits
# are the condition code. The buffer-index name states which check the branch
# belongs to, so the expected code is a property of the site, not of the
# number: bounds and limit branches are "greater or equal" (CS), a module
# existence test is equality (EQ), and the invalid-argument test is "higher"
# (HI). Written out so a changed constant is reported against the check it
# implements.
A64_COND = {"eq": 0, "ne": 1, "cs": 2, "cc": 3, "mi": 4, "pl": 5, "vs": 6,
            "vc": 7, "hi": 8, "ls": 9, "ge": 10, "lt": 11, "gt": 12,
            "le": 13, "al": 14}
A64_SITE = re.compile(
    r'words\[(\w+)\]\s*=\s*a64_patch_b_cond\(([^,;\n]+),')

# site-name prefix -> the condition the check requires
A64_INTENT = (
    ("null", "cs"),      # same cmp X9, max_entries: X9 >= max is out of range
    ("bounds", "cs"),
    ("limit", "cs"),
    ("eexist", "eq"),
    ("invalid", "hi"),
)


def a64_check():
    """Check each AArch64 B.cond site's encoded condition against its check.

    Returns (problems, site_count).
    """
    out = []
    seen = 0
    for m in A64_SITE.finditer(ENCODER_A64.read_text(errors="ignore")):
        site, token = m.group(1), m.group(2)
        raw = literal(token)
        if raw is None:
            out.append("%s: %s is not a plain word literal"
                       % (site, token.strip()))
            continue
        seen += 1
        if raw & ~0xf != 0x5400_0000:
            out.append("%s: 0x%08x is not a B.cond encoding" % (site, raw))
            continue
        cond = raw & 0xf
        want = None
        for prefix, name in A64_INTENT:
            if site.startswith(prefix):
                want = name
                break
        if want is None:
            out.append("%s: no stated intent for this site" % site)
            continue
        if cond != A64_COND[want]:
            out.append("%s: encodes condition %d, but the check requires "
                       "%s (%d)" % (site, cond, want.upper(), A64_COND[want]))
    return out, seen


# The two architectures lower bpf_tail_call independently, each in its own
# module, with its own spelling of the kernel's limit. The same program lowered
# either way must behave the same, so the decisions that matter -- compare
# against the limit, branch on unsigned >=, increment by one -- have to agree,
# and the limit they agree on has to be the kernel's.
TC_LIMIT = re.compile(r'const MAX_TAIL_CALL_CNT: \w+ = ([^;]+);')
TC_KERNEL = re.compile(r'^#define\s+MAX_TAIL_CALL_CNT\s+([^\n]+)', re.M)
# What the x86 lowering emits is a byte array; the assembly text beside it is a
# human note about those bytes. The operand is therefore read from the array:
# `0x48, 0x83, 0x38, imm8` is `cmp qword ptr [rax], imm8` and
# `0x48, 0x83, 0x00, 0x01` is `add qword ptr [rax], 1`. The operand is captured
# however it is spelled, so an expression the check cannot resolve is reported
# rather than passed.
TC_X86_CMP = re.compile(r'\[\s*0x48,\s*0x83,\s*0x38,\s*([^)\]\n]+)\s*[\]\)]')
TC_X86_INC = re.compile(r'\[\s*0x48,\s*0x83,\s*0x00,\s*([^)\]\n]+)\s*[\]\)]')
# x86 branches the limit test with jae (unsigned >=); that opcode is itself a
# jcc site and is checked as one. AArch64 branches with CS, which a64_check
# checks as the `limit` site, so what is left is that it compares at all.
TC_X86_BRANCH = re.compile(r'append_x86_jcc_rel32\(&mut bytes, 0x83\)')
TC_A64_CMP = re.compile(r'a64_cmp_imm64\(X12,\s*([^)]+)\)')
TC_A64_INC = re.compile(r'a64_add_imm64\(X12,\s*X12,\s*([^)]+)\)')


def emitted(token, limit):
    """Resolve an emitted operand: the limit's value, or its literal."""
    token = token.strip()
    return limit if token == "MAX_TAIL_CALL_CNT" else literal(token)


def tail_call_check():
    """The two architectures' bpf_tail_call lowerings must agree."""
    out = []
    x86_src = ENCODER.read_text(errors="ignore")
    a64_src = ENCODER_A64.read_text(errors="ignore")
    stated = [(where, TC_LIMIT.search(text)) for where, text in
              (("x86", x86_src), ("AArch64", a64_src))]
    missing = [where for where, hit in stated if hit is None]
    if missing:
        return ["%s no longer states MAX_TAIL_CALL_CNT" % " and ".join(missing)]
    kernels = TC_KERNEL.findall(BPF_H.read_text(errors="ignore"))
    if len(kernels) != 1:
        return ["%s states MAX_TAIL_CALL_CNT %d times" % (BPF_H, len(kernels))]
    limits = [literal(hit.group(1)) for _, hit in stated]
    tokens = [hit.group(1) for _, hit in stated]
    kernel = literal(kernels[0])
    if kernel is None or None in limits:
        return ["tail-call limit is not a plain literal: %s / %s"
                % (tokens, kernels)]
    if len(set(limits)) != 1:
        return ["the two lowerings state the tail-call limit %s" % tokens]
    if limits[0] != kernel:
        return ["the two lowerings use tail-call limit %d, but the kernel's "
                "MAX_TAIL_CALL_CNT is %d" % (limits[0], kernel)]
    limit = limits[0]

    for what, pattern, src, want in (
            ("the x86 comparison against the tail-call limit", TC_X86_CMP,
             x86_src, limit),
            ("the x86 increment of the tail-call count", TC_X86_INC, x86_src,
             1),
            ("the AArch64 comparison against the tail-call limit", TC_A64_CMP,
             a64_src, limit),
            ("the AArch64 increment of the tail-call count", TC_A64_INC,
             a64_src, 1)):
        m = pattern.search(src)
        if m is None:
            out.append("%s: the lowering no longer emits it" % what)
            continue
        got = emitted(m.group(1), limit)
        if got is None:
            out.append("%s reads %s, which is not a plain constant"
                       % (what, m.group(1).strip()))
        elif got != want:
            out.append("%s reads %s, which is not %d"
                       % (what, m.group(1).strip(), want))
    if not TC_X86_BRANCH.search(x86_src):
        out.append("x86's tail-call limit branch is no longer an "
                   "unsigned-greater-or-equal (jae)")
    return out


def main(argv):
    for f in FILES:
        if not f.exists():
            print("check_jcc_opcodes: missing %s" % f)
            return 1

    codes = {name.lower(): int(value) for name, value in
             CC.findall(SIM_H.read_text(errors="ignore"))}
    if not codes:
        print("check_jcc_opcodes: parsed no X86_CC_* codes from %s" % SIM_H)
        return 1

    src = ENCODER.read_text(errors="ignore")
    matches = list(SITE.finditer(src))

    # condition code -> mnemonic, from the contract itself
    by_code = {value: name.lower() for name, value in codes.items()}

    problems = []
    commented = 0
    named = 0
    unconditional = 0
    for m in matches:
        bind, form, args, comment = (m.group("bind"), m.group(2),
                                     m.group(3), m.group(4))
        width = "rel8" if form == "8" else "rel32"
        head, _, token = args.rpartition(",")
        if not head.strip():
            problems.append("%s call passes no opcode: (%s)"
                            % (width, args.strip()))
            continue
        opcode = literal(token)
        if opcode is None:
            problems.append("%s opcode %s is not a plain literal"
                            % (width, token.strip()))
            continue
        code = opcode - BASE[form]

        # The site must name a condition, either in its comment or in the
        # identifier it binds. A binding like `jbe_out` is the only statement
        # of intent for an uncommented emission. The comment is read in lower
        # case: the suffix names are lower case in the contract, and an
        # uppercase spelling still states the same intent.
        intent = comment.lower() if comment else None
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
            if comment:
                commented += 1
            else:
                named += 1
        elif form == "8" and opcode == JMP_REL8:
            # `jmp rel8`: no condition, so nothing to reconcile with the
            # contract. It is counted, not skipped, so the summary states every
            # emission the helper writes.
            unconditional += 1
        else:
            if code not in by_code:
                problems.append(
                    "%s opcode 0x%02x implies condition code %d, which is "
                    "not in the contract" % (width, opcode, code))
                continue

    conditional = commented + named
    if not conditional and not unconditional:
        print("check_jcc_opcodes: found no jump emissions in %s" % ENCODER)
        return 1

    if problems:
        print("check_jcc_opcodes: %d problem(s)" % len(problems))
        for p in problems:
            print("  " + p)
        return 1

    # ---- AArch64 B.cond ------------------------------------------------
    # The AArch64 encoder builds conditional branches from a literal word
    # whose low four bits are the condition code, so the same argument
    # applies: the constant is only a number, and a wrong one branches on the
    # wrong condition. The site's buffer-index name states the intent.
    a64, a64_seen = a64_check()
    if a64:
        print("check_jcc_opcodes: %d problem(s) in the AArch64 B.cond sites"
              % len(a64))
        for p in a64:
            print("  " + p)
        return 1

    # ---- the two architectures must lower tail calls alike -------------
    tc = tail_call_check()
    if tc:
        print("check_jcc_opcodes: %d problem(s) in the tail-call lowering"
              % len(tc))
        for p in tc:
            print("  " + p)
        return 1

    print("check_jcc_opcodes: %d conditional-jump site(s) all encode their "
          "condition code (%d by mnemonic comment, %d by binding name), "
          "%d unconditional jmp rel8 site(s), %d AArch64 B.cond site(s) match "
          "their named check, and the two tail-call lowerings agree"
          % (conditional, commented, named, unconditional, a64_seen))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))