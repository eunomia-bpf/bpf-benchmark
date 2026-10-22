#!/usr/bin/env python3
"""Mutation harness for the STEP 0104 operand-register presence contract.

Each mutation perturbs one of the five contract files and requires the paired
detector to notice:
  gen        python3 generate_x86_reg_presence_spec.py --check
  lean_chain lake build deps && lake env lean KProgFormal/X86RegPresence.lean
  host       compile+run test_x86_reg_presence_host.c

The contract fixes the operand-register presence decision: a decoded
register byte is a register unless it is the sentinel 0xff (X86_REG_NONE),
which the memory-operand bodies discard. The generated side carries the Arm
inductive, sentinel, absent/present rows, the arm selector, and the
PRESENT/ABSENT/ARM macros; the hand Lean module restates both predicates and
the arm table against the literal 0xff, proves the three refinements, links
the sentinel to the memory-index and packed-AUX sentinels, and shows both
arms reachable plus five canonical examples. The host oracle sweeps all 256
bytes over the three macros, checks the two predicates complementary and the
arm/present cross-consistency, and pins the sentinel value.
`validate_anchors` simulates every mutation's edits in order against a
running copy so a later anchor may match text an earlier edit of the same
mutation produced. Mutations marked `equivalent` must keep every detector
green.
"""
import subprocess
import sys
from pathlib import Path

FORMAL = Path(__file__).resolve().parent.parent

SPEC = FORMAL / "x86_reg_presence_spec.json"
GENPY = FORMAL / "generate_x86_reg_presence_spec.py"
GHEADER = FORMAL / "generated/x86_reg_presence.h"
GLEAN = FORMAL / "KProgFormal/GeneratedX86RegPresence.lean"
HAND = FORMAL / "KProgFormal/X86RegPresence.lean"
TEST_HOST = FORMAL / "test_x86_reg_presence_host.c"

WATCHED = [SPEC, GENPY, GHEADER, GLEAN, HAND, TEST_HOST]


def run(cmd, cwd, timeout=1500):
    try:
        return subprocess.run(cmd, cwd=cwd, timeout=timeout).returncode
    except subprocess.TimeoutExpired:
        return 124


def detect_gen():
    return run(["python3", "generate_x86_reg_presence_spec.py",
                "--check"], FORMAL)


def detect_lean_chain():
    rc = run(["lake", "build", "KProgFormal.GeneratedX86RegPresence",
              "KProgFormal.GeneratedX86MemIndex",
              "KProgFormal.GeneratedX86MemAux"], FORMAL)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86RegPresence.lean"],
               FORMAL)


def detect_host():
    out = "build/mut_x86_reg_presence_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.",
              "test_x86_reg_presence_host.c", "-o", out], FORMAL)
    if rc != 0:
        return rc
    return run([out], FORMAL)


DETECTORS = {
    "gen": detect_gen,
    "lean_chain": detect_lean_chain,
    "host": detect_host,
}


def mutate(path, old, new, count=1):
    text = path.read_text()
    if text.count(old) != count:
        raise SystemExit(f"anchor {old!r} in {path.name} not found {count}x")
    path.write_text(text.replace(old, new, count))


MUTATIONS = []
def row(name, det, edits, equivalent=False):
    """Append one mutation row; edits are (path, old, new, count) tuples."""
    MUTATIONS.append((name, det, [(p, o, n, c) for p, o, n, c in edits], False,
                     equivalent))


A_TUPLE = str(SPEC)
A_GEN = str(GENPY)
A_GH = str(GHEADER)
A_GL = str(GLEAN)
A_HA = str(HAND)
A_TH = str(TEST_HOST)

# ---------------- spec anchors ----------------
SPEC_OP = '"operation": "x86RegPresence"'
SPEC_BITS = '"reg_bits": 8,'
SPEC_SENTINEL = '"sentinel": 255,'
SPEC_GPR = '{"name": "present", "code": 0, "absent": false}'
SPEC_ABSENT = '{"name": "absent", "code": 1, "absent": true}'

# ---------------- generator anchors ----------------
GENPY_OP = '"operation": "x86RegPresence",'
GENPY_SENTINEL = '"sentinel": 255,'
GENPY_PRESENT = '{"name": "present", "code": 0, "absent": False},'
GENPY_ABSENT = '{"name": "absent", "code": 1, "absent": True},'
GENPY_ARM_ROWS = ('    absent_rows = "\\n".join(\n'
                  '        f"  | .{row[\'name\']} => "\n'
                  '        f"{\'true\' if row[\'absent\'] else \'false\'}" for row in arms)')
GENPY_PRESENT_ROWS = ('    present_rows = "\\n".join(\n'
                      '        f"  | .{row[\'name\']} => "\n'
                      '        f"{\'false\' if row[\'absent\'] else \'true\'}" for row in arms)')
GENPY_LEAN_ARM = ('def arm (regByte : BitVec {bits}) : Arm :=\n'
                  '  if regByte = sentinel then .{absent_name} else .{present_name}')
GENPY_LEAN_PATH = 'LEAN = ROOT / "KProgFormal/GeneratedX86RegPresence.lean"'
GENPY_C_PRESENT = '\\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL) ? 1 : 0))\n'
GENPY_C_ABSENT = '\\t((__u8)(((REG) == KPROG_X86_REG_SENTINEL) ? 1 : 0))\n'
GENPY_C_ARM = ('\\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL)                          \\\\\n'
               '\\t\\t ? KPROG_X86_REG_ARM_{present_name}                          \\\\\n'
               '\\t\\t : KPROG_X86_REG_ARM_{absent_name}))\n')
GENPY_SPEC_MSG = 'invalid x86 register-presence specification:'
GENPY_ORDER_MSG = 'invalid x86 register-presence arm order:'
GENPY_CODES_MSG = 'invalid x86 register-presence arm codes:'
GENPY_FLAGS_MSG = 'invalid x86 register-presence arm flags:'
GENPY_STALE = 'if args.check:'

# ---------------- generated C anchors ----------------
GH_ARM_PRESENT = '#define KPROG_X86_REG_ARM_PRESENT 0U'
GH_ARM_ABSENT = '#define KPROG_X86_REG_ARM_ABSENT 1U'
GH_SENTINEL = '#define KPROG_X86_REG_SENTINEL 0xffU'
GH_PRESENT = ('\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL) ? 1 : 0))')
GH_ABSENT = ('\t((__u8)(((REG) == KPROG_X86_REG_SENTINEL) ? 1 : 0))')
GH_ARM = ('\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL)                          \\\n'
          '\t\t ? KPROG_X86_REG_ARM_PRESENT                          \\\n'
          '\t\t : KPROG_X86_REG_ARM_ABSENT))')
GH_PRESENT_HDR = '#define KPROG_X86_REG_PRESENT(REG)'
GH_ARM_HDR = '#define KPROG_X86_REG_ARM(REG)'
GH_IFNDEF = '#ifndef KPROG_FORMAL_GENERATED_X86_REG_PRESENCE_H'

# ---------------- generated Lean anchors ----------------
GL_ARM = ('  if regByte = sentinel then .absent else .present')
GL_ABSENT_ROW = '  | .absent => true'
GL_PRESENT_ROW = '  | .present => false'
GL_SENTINEL = 'def sentinel : BitVec 8 := 0xff'
GL_NS = 'namespace KProgFormal.GeneratedX86RegPresence'

# ---------------- hand Lean anchors ----------------
HAND_ARM_SPEC = ('def x86RegArmSpec (regByte : BitVec 8) : Arm :=\n'
                 '  if regByte = (0xff : BitVec 8) then .absent else .present')
HAND_PRESENT_SPEC = ('def x86RegPresentSpec (regByte : BitVec 8) : Bool :=\n'
                     '  decide (regByte ≠ (0xff : BitVec 8))')
HAND_ABSENT_SPEC = ('def x86RegAbsentSpec (regByte : BitVec 8) : Bool :=\n'
                    '  decide (regByte = (0xff : BitVec 8))')
HAND_ARM_REF = 'theorem x86_reg_presence_arm_refines (regByte : BitVec 8) :'
HAND_PRESENT_REF = 'theorem x86_reg_presence_present_refines (regByte : BitVec 8) :'
HAND_ABSENT_REF = 'theorem x86_reg_presence_absent_refines (regByte : BitVec 8) :'
HAND_SENTINEL_ARM = ('theorem x86_reg_presence_sentinel_is_absent : '
                     'arm sentinel = .absent := rfl')
HAND_INDEX_LINK = ('theorem x86_reg_presence_sentinel_is_index_sentinel :\n'
                   '    sentinel = indexSentinel := rfl')
HAND_SENTINEL_IS_0XFF = (
    'theorem x86_reg_presence_sentinel_is_0xff : sentinel = 0xff := rfl')
HAND_COMPLEMENT = 'theorem x86_reg_presence_absent_complement (regByte : BitVec 8) :'
HAND_DISPATCH = 'theorem x86_reg_presence_case_dispatch :'
HAND_EXAMPLES = 'theorem x86_reg_presence_examples :'
HAND_NS = 'namespace KProgFormal'

# ---------------- host anchors ----------------
TH_WANT_PRESENT = '\t\t__u8 want_present = reg != 0xffU ? 1U : 0U;'
TH_WANT_ABSENT = '\t\t__u8 want_absent = reg == 0xffU ? 1U : 0U;'
TH_WANT_ARM = ('\t\t__u8 want_arm = reg == 0xffU ? KPROG_X86_REG_ARM_ABSENT\n'
               '\t\t\t\t\t     : KPROG_X86_REG_ARM_PRESENT;')
TH_CROSS = ('\t\tif (got_present != (1U - got_absent)) {')
TH_ARM_AGREE = ('\t\tif (got_present !=\n'
                '\t\t    (got_arm == KPROG_X86_REG_ARM_PRESENT)) {')
TH_SENTINEL_CHK = '\tif (KPROG_X86_REG_SENTINEL != 0xffU) {'
TH_MSG_OK = 'x86 reg presence host cross-check: OK (%lu cases)'

# ---------------- spec rows ----------------
row("spec_operation_drift", "gen",
    [(A_TUPLE, SPEC_OP, '"operation": "x86RegPresenceX"', 1)]),
row("spec_bits_drift", "gen",
    [(A_TUPLE, SPEC_BITS, '"reg_bits": 16,', 1)]),
row("spec_sentinel_drift", "gen",
    [(A_TUPLE, SPEC_SENTINEL, '"sentinel": 254,', 1)]),
row("spec_present_absent_drift", "gen",
    [(A_TUPLE, SPEC_GPR, '{"name": "present", "code": 0, "absent": true}', 1)]),
row("spec_absent_code_drift", "gen",
    [(A_TUPLE, SPEC_ABSENT, '{"name": "absent", "code": 3, "absent": true}', 1)]),

# ---------------- generator rows ----------------
row("generator_expected_op_drift", "gen",
    [(A_GEN, GENPY_OP, '"operation": "x86RegPresenceX",', 1)]),
row("generator_expected_sentinel_drift", "gen",
    [(A_GEN, GENPY_SENTINEL, '"sentinel": 254,', 1)]),
row("generator_expected_present_drift", "gen",
    [(A_GEN, GENPY_PRESENT, '{"name": "present", "code": 0, "absent": True},', 1)]),
row("generator_expected_absent_drift", "gen",
    [(A_GEN, GENPY_ABSENT, '{"name": "absent", "code": 1, "absent": False},', 1)]),
row("generator_arm_rows_flip", "gen",
    [(A_GEN, GENPY_ARM_ROWS,
      '    absent_rows = "\\n".join(\n'
      '        f"  | .{row[\'name\']} => "\n'
      '        f"{\'false\' if row[\'absent\'] else \'true\'}" for row in arms)', 1)]),
row("generator_present_rows_flip", "gen",
    [(A_GEN, GENPY_PRESENT_ROWS,
      '    present_rows = "\\n".join(\n'
      '        f"  | .{row[\'name\']} => "\n'
      '        f"{\'true\' if row[\'absent\'] else \'false\'}" for row in arms)', 1)]),
row("generator_lean_arm_swap", "gen",
    [(A_GEN, GENPY_LEAN_ARM,
      'def arm (regByte : BitVec {bits}) : Arm :=\n'
      '  if regByte = sentinel then .{present_name} else .{absent_name}', 1)]),
row("generator_c_present_or", "gen",
    [(A_GEN, GENPY_C_PRESENT,
      '\\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL) ? 0 : 1))\n', 1)]),
row("generator_c_absent_or", "gen",
    [(A_GEN, GENPY_C_ABSENT,
      '\\t((__u8)(((REG) == KPROG_X86_REG_SENTINEL) ? 0 : 1))\n', 1)]),
row("generator_c_arm_swap", "gen",
    [(A_GEN, GENPY_C_ARM,
      '\\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL)                          \\\\\n'
      '\\t\\t ? KPROG_X86_REG_ARM_ABSENT                          \\\\\n'
      '\\t\\t : KPROG_X86_REG_ARM_PRESENT))\n', 1)]),
row("generator_lean_path_drift", "gen",
    [(A_GEN, GENPY_LEAN_PATH, 'LEAN = ROOT / "KProgFormal/GeneratedX86RegPresenceX.lean"', 1)]),
row("equivalent_generator_spec_msg_repaint", "gen",
    [(A_GEN, GENPY_SPEC_MSG, 'invalid x86 register-presence specificationX:', 1)],
    equivalent=True),
row("equivalent_generator_order_msg_repaint", "gen",
    [(A_GEN, GENPY_ORDER_MSG, 'invalid x86 register-presence arm orderX:', 1)],
    equivalent=True),
row("equivalent_generator_codes_msg_repaint", "gen",
    [(A_GEN, GENPY_CODES_MSG, 'invalid x86 register-presence arm codesX:', 1)],
    equivalent=True),
row("equivalent_generator_flags_msg_repaint", "gen",
    [(A_GEN, GENPY_FLAGS_MSG, 'invalid x86 register-presence arm flagsX:', 1)],
    equivalent=True),
row("equivalent_generator_stale_gate_survives", "gen",
    [(A_GEN, GENPY_STALE, 'if False and args.check:', 1)],
    equivalent=True),

# ---------------- generated C rows ----------------
row("generated_c_arm_present_code_collide", "host",
    [(A_GH, GH_ARM_PRESENT, '#define KPROG_X86_REG_ARM_PRESENT 1U', 1)]),
row("generated_c_arm_absent_code_collide", "host",
    [(A_GH, GH_ARM_ABSENT, '#define KPROG_X86_REG_ARM_ABSENT 0U', 1)]),
row("generated_c_sentinel_drift", "host",
    [(A_GH, GH_SENTINEL, '#define KPROG_X86_REG_SENTINEL 0xfeU', 1)]),
row("generated_c_present_polarity", "host",
    [(A_GH, GH_PRESENT, '\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL) ? 0 : 1))', 1)]),
row("generated_c_present_swap", "host",
    [(A_GH, GH_PRESENT, '\t((__u8)(((REG) == KPROG_X86_REG_SENTINEL) ? 1 : 0))', 1)]),
row("generated_c_absent_swap", "host",
    [(A_GH, GH_ABSENT, '\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL) ? 1 : 0))', 1)]),
row("generated_c_arm_swap", "host",
    [(A_GH, GH_ARM,
      '\t((__u8)(((REG) != KPROG_X86_REG_SENTINEL)                          \\\n'
      '\t\t ? KPROG_X86_REG_ARM_ABSENT                          \\\n'
      '\t\t : KPROG_X86_REG_ARM_PRESENT))', 1)]),
row("generated_c_present_hdr_drift", "gen",
    [(A_GH, GH_PRESENT_HDR, '#define KPROG_X86_REG_PRESENTX(REG)', 1)]),
row("generated_c_arm_hdr_drift", "gen",
    [(A_GH, GH_ARM_HDR, '#define KPROG_X86_REG_ARMX(REG)', 1)]),
row("generated_c_ifndef_drift", "gen",
    [(A_GH, GH_IFNDEF, '#ifndef KPROG_FORMAL_GENERATED_X86_REG_PRESENCEX_H', 1)]),

# ---------------- generated Lean rows ----------------
row("generated_lean_arm_swap", "lean_chain",
    [(A_GL, GL_ARM, '  if regByte = sentinel then .present else .absent', 1)]),
row("generated_lean_absent_row_untag", "lean_chain",
    [(A_GL, GL_ABSENT_ROW, '  | .absent => false', 1)]),
row("generated_lean_present_row_tag", "lean_chain",
    [(A_GL, GL_PRESENT_ROW, '  | .present => true', 1)]),
row("generated_lean_sentinel_drift", "lean_chain",
    [(A_GL, GL_SENTINEL, 'def sentinel : BitVec 8 := 0xfe', 1)]),
row("generated_lean_ns_drift", "lean_chain",
    [(A_GL, GL_NS, 'namespace KProgFormal.GeneratedX86RegPresenceX', 1)]),

# ---------------- hand Lean rows ----------------
row("hand_arm_spec_swap", "lean_chain",
    [(A_HA, HAND_ARM_SPEC,
      'def x86RegArmSpec (regByte : BitVec 8) : Arm :=\n'
      '  if regByte = (0xff : BitVec 8) then .present else .absent', 1)]),
row("hand_present_spec_or", "lean_chain",
    [(A_HA, HAND_PRESENT_SPEC,
      'def x86RegPresentSpec (regByte : BitVec 8) : Bool :=\n'
      '  decide (regByte ≠ (0xff : BitVec 8)) || decide (regByte = (0xff : BitVec 8))', 1)]),
row("hand_absent_spec_swap", "lean_chain",
    [(A_HA, HAND_ABSENT_SPEC,
      'def x86RegAbsentSpec (regByte : BitVec 8) : Bool :=\n'
      '  decide (regByte ≠ (0xff : BitVec 8))', 1)]),
row("hand_arm_ref_rename_survives", "lean_chain",
    [(A_HA, HAND_ARM_REF, 'theorem x86_reg_presence_arm_refinesX (regByte : BitVec 8) :', 1)],
    equivalent=True),
row("hand_present_ref_rename_survives", "lean_chain",
    [(A_HA, HAND_PRESENT_REF, 'theorem x86_reg_presence_present_refinesX (regByte : BitVec 8) :', 1)],
    equivalent=True),
row("hand_absent_ref_rename_survives", "lean_chain",
    [(A_HA, HAND_ABSENT_REF, 'theorem x86_reg_presence_absent_refinesX (regByte : BitVec 8) :', 1)],
    equivalent=True),
row("hand_sentinel_pin_drift", "lean_chain",
    [(A_HA, HAND_SENTINEL_IS_0XFF,
      'theorem x86_reg_presence_sentinel_is_0xff : sentinel = 0xfe := rfl', 1)]),
row("hand_sentinel_arm_flip", "lean_chain",
    [(A_HA, HAND_SENTINEL_ARM,
      'theorem x86_reg_presence_sentinel_is_absent : arm sentinel = .present := rfl', 1)]),
row("hand_index_link_width_drift", "lean_chain",
    [(A_HA, HAND_INDEX_LINK,
      'theorem x86_reg_presence_sentinel_is_index_sentinel :\n'
      '    sentinel.setWidth 32 = indexSentinel := rfl', 1)]),
row("hand_complement_tag", "lean_chain",
    [(A_HA, HAND_COMPLEMENT,
      '    absent (arm regByte) = present regByte := by', 1)]),
row("hand_dispatch_rename_survives", "lean_chain",
    [(A_HA, HAND_DISPATCH, 'theorem x86_reg_presence_case_dispatchX :', 1)],
    equivalent=True),
row("hand_examples_rename_survives", "lean_chain",
    [(A_HA, HAND_EXAMPLES, 'theorem x86_reg_presence_examplesX :', 1)],
    equivalent=True),
row("hand_ns_drift", "lean_chain",
    [(A_HA, HAND_NS, 'namespace KProgFormalX', 1)]),

# ---------------- host rows ----------------
row("host_want_present_or", "host",
    [(A_TH, TH_WANT_PRESENT, '\t\t__u8 want_present = reg != 0xffU ? 0U : 1U;', 1)]),
row("host_want_absent_or", "host",
    [(A_TH, TH_WANT_ABSENT, '\t\t__u8 want_absent = reg == 0xffU ? 0U : 1U;', 1)]),
row("host_want_arm_swap", "host",
    [(A_TH, TH_WANT_ARM,
      '\t\t__u8 want_arm = reg == 0xffU ? KPROG_X86_REG_ARM_PRESENT\n'
      '\t\t\t\t\t     : KPROG_X86_REG_ARM_ABSENT;', 1)]),
row("host_cross_untag", "host",
    [(A_TH, TH_CROSS, '\t\tif (got_present != got_absent) {', 1)]),
row("host_arm_agree_swap", "host",
    [(A_TH, TH_ARM_AGREE,
      '\t\tif (got_present !=\n'
      '\t\t    (got_arm == KPROG_X86_REG_ARM_ABSENT)) {', 1)]),
row("host_sentinel_chk_drift", "host",
    [(A_TH, TH_SENTINEL_CHK, '\tif (KPROG_X86_REG_SENTINEL != 0xfeU) {', 1)]),
row("equivalent_host_msg_repaint", "host",
    [(A_TH, TH_MSG_OK, 'x86 reg presence host cross-check: OK (%lu case(s))', 1)],
    equivalent=True),


def baseline():
    """The three unmutated detectors must all be green."""
    bad = []
    for name in ("gen", "lean_chain", "host"):
        if DETECTORS[name]() != 0:
            bad.append(name)
    return bad


def validate_anchors():
    """Every mutation anchor must be present exactly its declared count, with
    each mutation's edits applied in order against the running text so a later
    anchor may match text an earlier edit of the same mutation produced."""
    for name, _det, edits, _regen, _equiv in MUTATIONS:
        sim = {Path(p): Path(p).read_text() for p, _o, _n, _c in edits}
        for path, old, new, count in edits:
            path = Path(path)
            text = sim[path]
            found = text.count(old)
            if found != count:
                print(f"ANCHOR FAIL {name}: {old!r} in {path.name} "
                      f"found={found} want={count}")
                return False
            sim[path] = text.replace(old, new)
    return True


def main():
    originals = {path: path.read_bytes() for path in WATCHED}

    def restore():
        for path, data in originals.items():
            if path.read_bytes() != data:
                path.write_bytes(data)

    if not validate_anchors():
        return 1

    bad = baseline()
    if bad:
        print(f"BASELINE FAILED: {', '.join(bad)}")
        return 1

    failures = 0
    survivors = 0
    for name, det, edits, _regen, equiv in MUTATIONS:
        try:
            for path, old, new, count in edits:
                mutate(Path(path), old, new, count)
            rc = DETECTORS[det]()
        finally:
            restore()
        caught = rc != 0
        if equiv:
            survivors += (not caught)
            if caught:
                print(f"FAIL {name}: marked equivalent but caught by {det}")
                failures += 1
            else:
                print(f"PASS {name:<55} SURVIVED by {det} (equivalent)")
            continue
        if caught:
            print(f"PASS {name:<55} caught by {det}")
        else:
            print(f"FAIL {name}: detector {det} survived but marked catchable")
            failures += 1

    bad = baseline()
    if bad:
        print(f"FINAL BASELINE FAILED: {', '.join(bad)}")
        failures += 1

    print(f"TOTAL {len(MUTATIONS)} mutations, {failures} failures, "
          f"{survivors} equivalences survived")
    if failures == 0:
        print("ALL AS EXPECTED")
        return 0
    return 1


if __name__ == "__main__":
    sys.exit(main())
