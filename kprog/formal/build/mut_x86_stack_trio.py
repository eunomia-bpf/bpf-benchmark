#!/usr/bin/env python3
"""Mutation harness for the three x86-64 stack contracts the simulator routes
its frame accesses through: the stack-index map (step 0074), the stack-arena
storage model (step 0075), and the stack word-path/byte-ladder arm selection
(step 0120).

Each mutation perturbs one anchor in the family's contract surface and must be
caught by the detector it names (gen, the generator's --check; lean_chain, the
generated Lean build plus the hand refinement module; host, the compiled
cross-check oracle; route, the routed-simulator cross-check oracle driven
through the real `x86_sim_local_bpf.h` region). The four unmutated detectors
stay green before and after; mutations declared `equivalent` must keep every
detector green.

  gen        python3 generate_x86_stack_{index,arena,arm}_spec.py --check
  lean_chain lake build KProgFormal.GeneratedX86Stack{Index,Arena,Arm} &&
             lake env lean KProgFormal/{X86StackIndex,X86StackArena,
             X86StackArmShape}.lean
  host       compile+run test_x86_stack_{index,arena,arm}_host.c
  route      compile+run test_x86_stack_arm_route_host.c

`validate_anchors` simulates every mutation's edits in order against a running
copy so a later anchor may match text an earlier edit of the same mutation
produced.
"""
import subprocess
import sys
from pathlib import Path

FORMAL = Path(__file__).resolve().parent.parent
ROOT = FORMAL.parent

# --- stack-index family (step 0074) ---
IDX_SPEC = FORMAL / "x86_stack_index_spec.json"
IDX_GENPY = FORMAL / "generate_x86_stack_index_spec.py"
IDX_GHEADER = FORMAL / "generated/x86_stack_index.h"
IDX_GLEAN = FORMAL / "KProgFormal/GeneratedX86StackIndex.lean"
IDX_HAND = FORMAL / "KProgFormal/X86StackIndex.lean"
IDX_HOST = FORMAL / "test_x86_stack_index_host.c"

# --- stack-arena family (step 0075) ---
ARN_SPEC = FORMAL / "x86_stack_arena_spec.json"
ARN_GENPY = FORMAL / "generate_x86_stack_arena_spec.py"
ARN_GHEADER = FORMAL / "generated/x86_stack_arena.h"
ARN_GLEAN = FORMAL / "KProgFormal/GeneratedX86StackArena.lean"
ARN_HAND = FORMAL / "KProgFormal/X86StackArena.lean"
ARN_HOST = FORMAL / "test_x86_stack_arena_host.c"

# --- stack-arm family (step 0120) ---
ARM_SPEC = FORMAL / "x86_stack_arm_spec.json"
ARM_GENPY = FORMAL / "generate_x86_stack_arm_spec.py"
ARM_GHEADER = FORMAL / "generated/x86_stack_arm.h"
ARM_GLEAN = FORMAL / "KProgFormal/GeneratedX86StackArm.lean"
ARM_HAND = FORMAL / "KProgFormal/X86StackArmShape.lean"
ARM_HOST = FORMAL / "test_x86_stack_arm_host.c"
ARM_ROUTE = FORMAL / "test_x86_stack_arm_route_host.c"
LOCAL = ROOT / "x86/x86_sim_local_bpf.h"

WATCHED = [IDX_SPEC, IDX_GENPY, IDX_GHEADER, IDX_GLEAN, IDX_HAND, IDX_HOST,
           ARN_SPEC, ARN_GENPY, ARN_GHEADER, ARN_GLEAN, ARN_HAND, ARN_HOST,
           ARM_SPEC, ARM_GENPY, ARM_GHEADER, ARM_GLEAN, ARM_HAND, ARM_HOST,
           ARM_ROUTE, LOCAL]

HOST_INC = ["-I.", "-I../x86", "-I../../kprog",
            "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/"
            "include/bpf"]


def run(cmd, cwd, timeout=900):
    try:
        return subprocess.run(cmd, cwd=cwd, timeout=timeout).returncode
    except subprocess.TimeoutExpired:
        return 124


def detect_index_gen():
    return run(["python3", "generate_x86_stack_index_spec.py", "--check"],
               FORMAL)


def detect_index_lean_chain():
    rc = run(["lake", "build", "KProgFormal.GeneratedX86StackIndex"], FORMAL)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86StackIndex.lean"],
               FORMAL)


def detect_index_host():
    out = "build/mut_trio_index_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.",
              "test_x86_stack_index_host.c", "-o", out], FORMAL)
    if rc != 0:
        return rc
    return run([out], FORMAL)


def detect_arena_gen():
    return run(["python3", "generate_x86_stack_arena_spec.py", "--check"],
               FORMAL)


def detect_arena_lean_chain():
    rc = run(["lake", "build", "KProgFormal.GeneratedX86StackArena"], FORMAL)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86StackArena.lean"],
               FORMAL)


def detect_arena_host():
    out = "build/mut_trio_arena_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.",
              "test_x86_stack_arena_host.c", "-o", out], FORMAL)
    if rc != 0:
        return rc
    return run([out], FORMAL)


def detect_arm_gen():
    return run(["python3", "generate_x86_stack_arm_spec.py", "--check"],
               FORMAL)


def detect_arm_lean_chain():
    rc = run(["lake", "build", "KProgFormal.GeneratedX86StackArm"], FORMAL)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86StackArmShape.lean"],
               FORMAL)


def detect_arm_host():
    out = "build/mut_trio_arm_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.",
              "test_x86_stack_arm_host.c", "-o", out], FORMAL)
    if rc != 0:
        return rc
    return run([out], FORMAL)


def detect_arm_route():
    out = "build/mut_trio_arm_route"
    rc = run(["cc", "-Wall", "-Wextra", "-O2"] + HOST_INC +
             ["test_x86_stack_arm_route_host.c", "-o", out], FORMAL)
    if rc != 0:
        return rc
    return run([out], FORMAL)


DETECTORS = {
    "index_gen": detect_index_gen,
    "index_lean_chain": detect_index_lean_chain,
    "index_host": detect_index_host,
    "arena_gen": detect_arena_gen,
    "arena_lean_chain": detect_arena_lean_chain,
    "arena_host": detect_arena_host,
    "arm_gen": detect_arm_gen,
    "arm_lean_chain": detect_arm_lean_chain,
    "arm_host": detect_arm_host,
    "arm_route": detect_arm_route,
}



def regen_index():
    return run(["python3", "generate_x86_stack_index_spec.py"], FORMAL)


def regen_arena():
    return run(["python3", "generate_x86_stack_arena_spec.py"], FORMAL)


def regen_arm():
    return run(["python3", "generate_x86_stack_arm_spec.py"], FORMAL)


REGEN = {
    "index_gen": regen_index,
    "index_lean_chain": regen_index,
    "index_host": regen_index,
    "arena_gen": regen_arena,
    "arena_lean_chain": regen_arena,
    "arena_host": regen_arena,
    "arm_gen": regen_arm,
    "arm_lean_chain": regen_arm,
    "arm_host": regen_arm,
    "arm_route": regen_arm,
}


def mutate(path, old, new, count=1):
    text = path.read_text()
    path.write_text(text.replace(old, new, count))


# ================= stack-index anchors =================
ISI_OP = '"operation":"x86StackIndex"'
ISI_SCHEMA = '"schema_version":1'
ISI_BASE = '"index_base":"capacity"'
ISI_STEP = '"index_step":1'
ISI_ACCU = '"accumulate":"wrapping64"'
ISI_MASK = '"index_mask_bits":32'
IGI_OP = '    "operation": "x86StackIndex",'
IGI_BASE = '    "index_base": "capacity",'
IGI_MASK = '    "index_mask_bits": 32,'
IGI_LEAN_PATH = 'LEAN = ROOT / "KProgFormal/GeneratedX86StackIndex.lean"'
IGI_CHEADER_PATH = 'CHEADER = ROOT / "generated/x86_stack_index.h"'
IGI_LEAN_BODY = '  (capacity + off).truncate 32'
IGI_C_MACRO = '((__u32)((__s64)(OFF) + (__s64)(CAPACITY)))'
IGH_MACRO = '((__u32)((__s64)(OFF) + (__s64)(CAPACITY)))'
IGN_INDEX = '  (capacity + off).truncate 32'
IHN_SPECDEF = '  BitVec.setWidth 32 (off + capacity)'
IHN_EXAMPLE = 'index 64 (-56) = 8'

# ================= stack-arena anchors =================
ASI_OP = '"operation":"x86StackArena"'
ASI_SCHEMA = '"schema_version":1'
ASI_SHIFT = '"word_shift":3'
ASI_MASK = '"word_mask":"0x7"'
ASI_ROUND = '"capacity_round":"ceil8"'
ASI_ALIAS = '"arena_alias":"b-q-union"'
ASI_ASSEMBLE = '"assemble":"little_endian8"'
AGI_OP = '    "operation": "x86StackArena",'
AGI_LEAN_PATH = 'LEAN = ROOT / "KProgFormal/GeneratedX86StackArena.lean"'
AGI_CHEADER_PATH = 'CHEADER = ROOT / "generated/x86_stack_arena.h"'
AGI_LEAN_WIDX = ('def wordIndex (index : BitVec 32) : BitVec 32 := '
                 'index >>> {shift}')
AGI_LEAN_WALIGNED = ('def wordAligned (index : BitVec 32) : Bool := '
                     '(index &&& {mask}) == 0')
AGI_C_WIDX = ('#define KPROG_X86_STACK_WORD_INDEX(INDEX) '
              '((__u32)(INDEX) >> {shift})')
AGH_WIDX = '#define KPROG_X86_STACK_WORD_INDEX(INDEX) ((__u32)(INDEX) >> 3)'
AGH_BYTE = '((__u8)(((__u64)(WORD)) >> (8U * (__u32)(K))))'
AGH_WORDS = '(((__u32)(CAPACITY) + 7U) / 8U)'
AGH_ASSEMBLE = '(((__u64)((__u8)(BYTE))) << (8U * (__u32)(K)))'
AGN_WIDX = 'def wordIndex (index : BitVec 32) : BitVec 32 := index >>> 3'
AGN_WALIGNED = 'def wordAligned (index : BitVec 32) : Bool := (index &&& 7) == 0'
AGN_WORDS = 'def words (capacity : BitVec 32) : BitVec 32 :=\n  (capacity + 7) / 8'
AHN_WIDX = ('def x86StackArenaWordIndexSpec (index : BitVec 32) : BitVec 32 '
            ':= index / 8')
AHN_WORDS = 'capacity >>> 3 + (if capacity &&& 7 == 0 then 0 else 1)'
AHN_EXAMPLE_BODY = '    words 128 = 16 \u2227 words 64 = 8 \u2227 words 1 = 1 \u2227'

# ================= stack-arm anchors (from step 0120 harness) =================
SSA_W64 = '"name": "qword", "w64": true,'
SSA_WORD = '"aligned": true, "word": true}'
SSA_BODY_WORD = '"body": "word_arena_access"'
SSA_ARM_WORD = '"arm": "word",'
SSA_DEFINE_WORD = '"arm_define": "KPROG_X86_STACK_ARM_WORD",'
SSA_NAME_QWORD = '"name": "qword",'
SSA_WIDTH64 = '"width64_code": 8,'
SSA_SELECTOR = '"selector": "w64_and_aligned_then_word_else_byte"'
GSA_WIDTH64 = "WIDTH64 = 8"
GSA_WORD_ARENA = 'WORD_ARENA = "__x86_stack_mem.q"'
GSA_SELECTOR = 'STACK_SELECTOR = "KPROG_X86_STACK_ARM("'
GSA_BYTE_ARENA = 'BYTE_ARENA = "__x86_stack_mem.b["'
GSA_HAND_AND = 'HAND_AND_TEST = "X86_WIDTH_64 &&"'
GSA_ARM_OF = ('  if isW64 && isAligned then .{arms[0]["arm"]} '
              'else .{arms[1]["arm"]}')
GSA_WORD_SPEC = ('def wordSpec (isW64 isAligned : Bool) : Bool := '
                 'isW64 && isAligned')
GSA_MACRO = 'KPROG_X86_STACK_ARM(IS_W64, IS_ALIGNED)'
GSA_ROOT = "ROOT = Path(__file__).resolve().parent"
GHA_WIDTH64 = "#define KPROG_X86_STACK_ARM_WIDTH64 8U"
GHA_COUNT = "#define KPROG_X86_STACK_ARM_COUNT 2U"
GHA_WORD_CODE = "#define KPROG_X86_STACK_ARM_WORD 1U"
GHA_BYTE_CODE = "#define KPROG_X86_STACK_ARM_BYTE 0U"
GHA_MACRO = '\t((__u8)(((IS_W64) && (IS_ALIGNED)) ? 1 : 0))'
GHA_ASSERT_WORD = ('_Static_assert(KPROG_X86_STACK_ARM(1, 1) == '
                   'KPROG_X86_STACK_ARM_WORD,')
GNA_COUNT = "def armCount : Nat := 2"
GNA_WIDTH64 = "def width64Code : Nat := 8"
GNA_NAMES = 'def armNames : List String := ["word", "byte"]'
GNA_CODES = "def armCodes : List Nat := [1, 0]"
GNA_ARM_OF = "  if isW64 && isAligned then .word else .byte"
GNA_WORD_CODE = "  | .word => 1"
GNA_BYTE_CODE = "  | .byte => 0"
GNA_QWORD_BODY = "  | .qword => true"
HNA_WIDTH64_DEF = "def x86StackArmWidth64Spec : Nat := 8"
HNA_SPEC_DEF = ("def x86StackArmSpec (isW64 isAligned : Bool) : Arm :=\n"
                "  if isW64 && isAligned then .word else .byte")
HNA_NAMES_DEF = 'def x86StackArmNamesSpec : List String := ["word", "byte"]'
HNA_CODES_DEF = "def x86StackArmCodesSpec : List Nat := [1, 0]"
HNA_DISPATCH = "    armOf true true = .word \u2227 armOf true false = .byte \u2227"
HNA_BODIES = 'bodyOfArm .word = "word_arena_access" \u2227'
LOC_INCLUDE = '#include "../formal/generated/x86_stack_arm.h"\n'
LOC_WORD_ARENA = "__x86_stack_mem.q"
LOC_WORD_INDEX = "KPROG_X86_STACK_WORD_INDEX("
LOC_ASSEMBLE = "KPROG_X86_STACK_ASSEMBLE("
SEL_W = 'if (KPROG_X86_STACK_ARM(                                  \\\n\t\t\t    (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) ==         \\\n\t\t\t\t    X86_WIDTH_64,                         \\\n\t\t\t    KPROG_X86_STACK_WORD_ALIGNED(                 \\\n\t\t\t\t    __x86_stw_index))) {'
SEL_R = 'if (KPROG_X86_STACK_ARM(                                  \\\n\t\t\t    (X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) ==         \\\n\t\t\t\t    X86_WIDTH_64,                         \\\n\t\t\t    KPROG_X86_STACK_WORD_ALIGNED(                 \\\n\t\t\t\t    __x86_str_index))) {'
SEL_W_HAND = ('if ((X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) == X86_WIDTH_64 &&   \\\n'
              '\t\t\t    KPROG_X86_STACK_WORD_ALIGNED(__x86_stw_index)) {  \\\n')
SEL_R_HAND = ('if ((X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)) == X86_WIDTH_64 &&   \\\n'
              '\t\t\t    KPROG_X86_STACK_WORD_ALIGNED(__x86_str_index)) {  \\\n')

# (name, detector, edits, regen_key, equivalent)
MUTATIONS = [
    # ---------------------- stack-index family ----------------------
    ("idx_spec_op_drift", "index_gen",
     [(IDX_SPEC, ISI_OP, '"operation":"x86StackIndexX"', 1)], None, False),
    ("idx_spec_base_drift", "index_gen",
     [(IDX_SPEC, ISI_BASE, '"index_base":"top"', 1)], None, False),
    ("idx_spec_step_drift", "index_gen",
     [(IDX_SPEC, ISI_STEP, '"index_step":2', 1)], None, False),
    ("idx_spec_accu_drift", "index_gen",
     [(IDX_SPEC, ISI_ACCU, '"accumulate":"saturating64"', 1)], None, False),
    ("idx_spec_mask_drift", "index_gen",
     [(IDX_SPEC, ISI_MASK, '"index_mask_bits":33', 1)], None, False),
    ("idx_gen_op_drift", "index_gen",
     [(IDX_GENPY, IGI_OP, '    "operation": "x86StackIndexX",', 1)],
     None, False),
    ("idx_gen_base_drift", "index_gen",
     [(IDX_GENPY, IGI_BASE, '    "index_base": "top",', 1)], None, False),
    ("idx_gen_mask_drift", "index_gen",
     [(IDX_GENPY, IGI_MASK, '    "index_mask_bits": 33,', 1)], None, False),
    ("idx_gen_lean_path_drift", "index_gen",
     [(IDX_GENPY, IGI_LEAN_PATH,
       'LEAN = ROOT / "KProgFormal/GeneratedX86StackIndekx.lean"', 1)],
     None, False),
    ("idx_gen_cheader_path_drift", "index_gen",
     [(IDX_GENPY, IGI_CHEADER_PATH,
       'CHEADER = ROOT / "generated/x86_stack_indekx.h"', 1)], None, False),
    ("idx_gen_lean_body_drift", "index_lean_chain",
     [(IDX_GENPY, IGI_LEAN_BODY, '  (capacity + off).truncate 31', 1),
      (IDX_GLEAN, IGN_INDEX, '  (capacity + off).truncate 31', 1)],
     "index_gen", False),
    ("idx_gen_c_macro_drift", "index_host",
     [(IDX_GENPY, IGI_C_MACRO,
       '(((__u32)((__s64)(OFF) + (__s64)(CAPACITY) + 1)))', 1),
      (IDX_GHEADER, IGH_MACRO,
       '(((__u32)((__s64)(OFF) + (__s64)(CAPACITY) + 1)))', 1)],
     "index_gen", False),
    ("idx_ghdr_macro_drift", "index_host",
     [(IDX_GHEADER, IGH_MACRO,
       '(((__u32)((__s64)(OFF) - (__s64)(CAPACITY))))', 1)], None, False),
    ("idx_glean_truncate_drift", "index_lean_chain",
     [(IDX_GLEAN, IGN_INDEX, '  (capacity + off).truncate 31', 1)],
     None, False),
    ("idx_hand_specdef_drift", "index_lean_chain",
     [(IDX_HAND, IHN_SPECDEF,
       '  BitVec.setWidth 31 (off + capacity)', 1)], None, False),
    ("idx_hand_example_drift", "index_lean_chain",
     [(IDX_HAND, IHN_EXAMPLE, 'index 64 (-56) = 9', 1)], None, False),
    # ---------------------- stack-arena family ----------------------
    ("arn_spec_op_drift", "arena_gen",
     [(ARN_SPEC, ASI_OP, '"operation":"x86StackArenaX"', 1)], None, False),
    ("arn_spec_shift_drift", "arena_gen",
     [(ARN_SPEC, ASI_SHIFT, '"word_shift":4', 1)], None, False),
    ("arn_spec_mask_drift", "arena_gen",
     [(ARN_SPEC, ASI_MASK, '"word_mask":"0xf"', 1)], None, False),
    ("arn_spec_round_drift", "arena_gen",
     [(ARN_SPEC, ASI_ROUND, '"capacity_round":"floor8"', 1)], None, False),
    ("arn_spec_alias_drift", "arena_gen",
     [(ARN_SPEC, ASI_ALIAS, '"arena_alias":"b-q-struct"', 1)], None, False),
    ("arn_spec_assemble_drift", "arena_gen",
     [(ARN_SPEC, ASI_ASSEMBLE, '"assemble":"big_endian8"', 1)], None, False),
    ("arn_gen_op_drift", "arena_gen",
     [(ARN_GENPY, AGI_OP, '    "operation": "x86StackArenaX",', 1)],
     None, False),
    ("arn_gen_lean_path_drift", "arena_gen",
     [(ARN_GENPY, AGI_LEAN_PATH,
       'LEAN = ROOT / "KProgFormal/GeneratedX86StackArenaz.lean"', 1)],
     None, False),
    ("arn_gen_cheader_path_drift", "arena_gen",
     [(ARN_GENPY, AGI_CHEADER_PATH,
       'CHEADER = ROOT / "generated/x86_stack_arenaz.h"', 1)], None, False),
    ("arn_gen_lean_widx_drift", "arena_lean_chain",
     [(ARN_GENPY, AGI_LEAN_WIDX,
       'def wordIndex (index : BitVec 32) : BitVec 32 := index >>> {s}', 1),
      (ARN_GLEAN, AGN_WIDX,
       'def wordIndex (index : BitVec 32) : BitVec 32 := index >>> 4', 1)],
     None, False),
    ("arn_gen_lean_waligned_drift", "arena_gen",
     [(ARN_GENPY, AGI_LEAN_WALIGNED,
       'def wordAligned (index : BitVec 32) : Bool := '
       '(index &&& {mask}) != 0', 1)], None, False),
    ("arn_gen_c_widx_drift", "arena_host",
     [(ARN_GENPY, AGI_C_WIDX,
       '#define KPROG_X86_STACK_WORD_INDEX(INDEX) ((__u32)(INDEX) >> {s})', 1),
      (ARN_GHEADER, AGH_WIDX,
       '#define KPROG_X86_STACK_WORD_INDEX(INDEX) ((__u32)(INDEX) >> 4)', 1)],
     None, False),
    ("arn_ghdr_words_drift", "arena_host",
     [(ARN_GHEADER, AGH_WORDS, '(((__u32)(CAPACITY) + 7U) / 7U)', 1)],
     None, False),
    ("arn_ghdr_byte_drift", "arena_host",
     [(ARN_GHEADER, AGH_BYTE, '(((__u8)(((__u64)(WORD)) >> (4U * K))))', 1)],
     None, False),
    ("arn_ghdr_assemble_drift", "arena_host",
     [(ARN_GHEADER, AGH_ASSEMBLE, '(((__u64)((__u8)(BYTE))) << K)', 1)],
     None, False),
    ("arn_glean_widx_drift", "arena_lean_chain",
     [(ARN_GLEAN, AGN_WIDX,
       'def wordIndex (index : BitVec 32) : BitVec 32 := index >>> 4', 1)],
     None, False),
    ("arn_glean_waligned_drift", "arena_lean_chain",
     [(ARN_GLEAN, AGN_WALIGNED,
       'def wordAligned (index : BitVec 32) : Bool := (index &&& 7) != 0', 1)],
     None, False),
    ("arn_glean_words_drift", "arena_lean_chain",
     [(ARN_GLEAN, AGN_WORDS,
       'def words (capacity : BitVec 32) : BitVec 32 :=\n'
       '  (capacity + 7) / 7', 1)], None, False),
    ("arn_hand_widx_drift", "arena_lean_chain",
     [(ARN_HAND, AHN_WIDX,
       ':= index / 7', 1)], None, False),
    ("arn_hand_words_drift", "arena_lean_chain",
     [(ARN_HAND, AHN_WORDS,
       'capacity >>> 3 + (if capacity && 7 == 0 then 0 else 1)', 1)],
     None, False),
    ("arn_hand_example_drift", "arena_lean_chain",
     [(ARN_HAND, AHN_EXAMPLE_BODY, '    words 128 = 16 ∧ words 64 = 9 ∧ words 1 = 1 ∧', 1)],
     None, False),
    # ---------------------- stack-arm family ----------------------
    ("arm_spec_arm_swap", "arm_gen",
     [(ARM_SPEC, SSA_ARM_WORD, '"arm": "wordX",', 1)], None, False),
    ("arm_spec_body_swap", "arm_gen",
     [(ARM_SPEC, SSA_BODY_WORD, '"body": "byte_ladder_accessX"', 1)],
     None, False),
    ("arm_spec_define_swap", "arm_gen",
     [(ARM_SPEC, SSA_DEFINE_WORD,
       '"arm_define": "KPROG_X86_STACK_ARM_BYTE",', 1)], None, False),
    ("arm_spec_case_name_drift", "arm_gen",
     [(ARM_SPEC, SSA_NAME_QWORD, '"name": "quadword",', 1)], None, False),
    ("arm_spec_w64_drift", "arm_gen",
     [(ARM_SPEC, SSA_W64, '"name": "qword", "w64": false,', 1)], None, False),
    ("arm_spec_word_drift", "arm_gen",
     [(ARM_SPEC, SSA_WORD, '"aligned": true, "word": false}', 1)],
     None, False),
    ("arm_spec_width64_drift", "arm_gen",
     [(ARM_SPEC, SSA_WIDTH64, '"width64_code": 4,', 1)], None, False),
    ("arm_spec_selector_drift", "arm_gen",
     [(ARM_SPEC, SSA_SELECTOR,
       '"selector": "aligned_and_w64_then_word_else_byte"', 1)], None, False),
    ("arm_gen_width64_drift", "arm_gen",
     [(ARM_GENPY, GSA_WIDTH64, "WIDTH64 = 4", 1)], None, False),
    ("arm_gen_word_arena_drift", "arm_gen",
     [(ARM_GENPY, GSA_WORD_ARENA, 'WORD_ARENA = "__x86_stack_mem.qx"', 1)],
     None, False),
    ("arm_gen_selector_drift", "arm_gen",
     [(ARM_GENPY, GSA_SELECTOR,
       'STACK_SELECTOR = "KPROG_X86_STACK_ARMX("', 1)], None, False),
    ("arm_gen_byte_arena_drift", "arm_gen",
     [(ARM_GENPY, GSA_BYTE_ARENA, 'BYTE_ARENA = "__x86_stack_mem.z["', 1)],
     None, False),
    ("arm_gen_hand_and_drift", "arm_gen",
     [(ARM_GENPY, GSA_HAND_AND, 'HAND_AND_TEST = "KPROG_X86_STACK_ARM("', 1)],
     None, False),
    ("arm_gen_armof_drift", "arm_gen",
     [(ARM_GENPY, GSA_ARM_OF,
       '  if isW64 then .{arms[0]["arm"]} else .{arms[1]["arm"]}', 1)],
     None, False),
    ("arm_gen_wordspec_drift", "arm_gen",
     [(ARM_GENPY, GSA_WORD_SPEC,
       'def wordSpec (isW64 isAligned : Bool) : Bool := isW64 || isAligned',
       1)], None, False),
    ("arm_gen_macro_drift", "arm_gen",
     [(ARM_GENPY, GSA_MACRO, 'KPROG_X86_STACK_ARMX(IS_W64, IS_ALIGNED)', 1)],
     None, False),
    # --- generated C header ---
    ("arm_ghdr_width64_drift", "arm_gen",
     [(ARM_GHEADER, GHA_WIDTH64,
       "#define KPROG_X86_STACK_ARM_WIDTH64 4U", 1)], None, False),
    ("arm_ghdr_count_drift", "arm_gen",
     [(ARM_GHEADER, GHA_COUNT,
       "#define KPROG_X86_STACK_ARM_COUNT 3U", 1)], None, False),
    ("arm_ghdr_word_code_drift", "arm_host",
     [(ARM_GHEADER, GHA_WORD_CODE,
       "#define KPROG_X86_STACK_ARM_WORD 2U", 1)], None, False),
    ("arm_ghdr_byte_code_drift", "arm_host",
     [(ARM_GHEADER, GHA_BYTE_CODE,
       "#define KPROG_X86_STACK_ARM_BYTE 5U", 1)], None, False),
    ("arm_ghdr_macro_inverted", "arm_host",
     [(ARM_GHEADER, GHA_MACRO,
       '\t((__u8)(((IS_W64) && (IS_ALIGNED)) ? 0 : 1))', 1)], None, False),
    ("arm_ghdr_assert_swap", "arm_gen",
     [(ARM_GHEADER, GHA_ASSERT_WORD,
       "_Static_assert(KPROG_X86_STACK_ARM(1, 1) == "
       "KPROG_X86_STACK_ARM_BYTE,", 1)], None, False),
    # --- generated Lean ---
    ("arm_glean_count_drift", "arm_gen",
     [(ARM_GLEAN, GNA_COUNT, "def armCount : Nat := 3", 1)], None, False),
    ("arm_glean_width64_drift", "arm_gen",
     [(ARM_GLEAN, GNA_WIDTH64, "def width64Code : Nat := 4", 1)],
     None, False),
    ("arm_glean_names_drift", "arm_gen",
     [(ARM_GLEAN, GNA_NAMES,
       'def armNames : List String := ["word", "bytes"]', 1)], None, False),
    ("arm_glean_codes_drift", "arm_gen",
     [(ARM_GLEAN, GNA_CODES, "def armCodes : List Nat := [1, 0, 2]", 1)],
     None, False),
    ("arm_glean_armof_drift", "arm_gen",
     [(ARM_GLEAN, GNA_ARM_OF, "  if isW64 then .word else .byte", 1)],
     None, False),
    ("arm_glean_word_code_drift", "arm_lean_chain",
     [(ARM_GLEAN, GNA_WORD_CODE, "  | .word => 5", 1)], None, False),
    ("arm_glean_byte_code_drift", "arm_lean_chain",
     [(ARM_GLEAN, GNA_BYTE_CODE, "  | .byte => 5", 1)], None, False),
    ("arm_glean_qword_body_drift", "arm_lean_chain",
     [(ARM_GLEAN, GNA_QWORD_BODY, "  | .qword => false", 1)], None, False),
    # --- hand refinement ---
    ("arm_hand_width64_def_drift", "arm_lean_chain",
     [(ARM_HAND, HNA_WIDTH64_DEF, "def x86StackArmWidth64Spec : Nat := 4", 1)],
     None, False),
    ("arm_hand_spec_shape_drift", "arm_lean_chain",
     [(ARM_HAND, HNA_SPEC_DEF,
       "def x86StackArmSpec (isW64 isAligned : Bool) : Arm :=\n"
       "  if isW64 then .word else .byte", 1)], None, False),
    ("arm_hand_names_swap", "arm_lean_chain",
     [(ARM_HAND, HNA_NAMES_DEF,
       'def x86StackArmNamesSpec : List String := ["byte", "word"]', 1)],
     None, False),
    ("arm_hand_codes_swap", "arm_lean_chain",
     [(ARM_HAND, HNA_CODES_DEF,
       "def x86StackArmCodesSpec : List Nat := [0, 1]", 1)], None, False),
    ("arm_hand_dispatch_drift", "arm_lean_chain",
     [(ARM_HAND, HNA_DISPATCH,
       "    armOf true true = .byte \u2227 armOf true false = .byte \u2227",
       1)], None, False),
    ("arm_hand_bodies_drift", "arm_lean_chain",
     [(ARM_HAND, HNA_BODIES,
       'bodyOfArm .word = "byte_ladder_access" \u2227', 1)], None, False),
    # --- routed simulator body ---
    ("arm_local_include_dropped", "arm_route",
     [(LOCAL, LOC_INCLUDE, "", 1)], None, False),
    ("arm_local_selector_unrouted_w", "arm_gen",
     [(LOCAL, SEL_W, SEL_W_HAND, 1)], None, False),
    ("arm_local_selector_unrouted_r", "arm_gen",
     [(LOCAL, SEL_R, SEL_R_HAND, 1)], None, False),
    ("arm_local_word_arena_drift", "arm_route",
     [(LOCAL, LOC_WORD_ARENA, "__x86_stack_mem.z", 2)], None, False),
    ("arm_local_word_index_drift", "arm_route",
     [(LOCAL, LOC_WORD_INDEX, "KPROG_X86_STACK_WORD_INDEXX(", 2)],
     None, False),
    ("arm_local_byte_ladder_drift", "arm_route",
     [(LOCAL, LOC_ASSEMBLE, "KPROG_X86_STACK_ASSEMBLEX(", 7)],
     None, False),
    ("arm_local_word_index_macro_drift_route", "arm_route",
     [(LOCAL, LOC_WORD_ARENA + "                               \\",
       "__x86_stack_mem.z                               \\", 1)], None, False),
    # --- regen pair: rendered drift baked into all artifacts ---
    ("arm_gen_width64_regenerated", "arm_host",
     [(ARM_GENPY, GSA_WIDTH64, "WIDTH64 = 4", 1),
      (ARM_SPEC, SSA_WIDTH64, '"width64_code": 4,', 1)], "arm_gen", False),
    # ---------------------- genuine equivalences ----------------------
    ("equiv_local_comment_survives", "arm_route",
     [(LOCAL, "#include \"../formal/generated/x86_stack_arm.h\"",
       "#include \"../formal/generated/x86_stack_arm.h\" /* step 0257 */", 1)],
     None, True),
    ("equiv_idx_hand_comment_survives", "index_lean_chain",
     [(IDX_HAND, "namespace KProgFormal\n",
       "namespace KProgFormal\n-- step 0257\n", 1)], None, True),
    ("equiv_arm_gen_root_survives", "arm_gen",
     [(ARM_GENPY, GSA_ROOT, "ROOT = Path(__file__).parent.resolve()", 1)],
     None, True),
    ("equiv_idx_spec_ws_survives", "index_gen",
     [(IDX_SPEC, ISI_SCHEMA, '"schema_version": 1', 1)], None, True),
    ("equiv_arn_spec_ws_survives", "arena_gen",
     [(ARN_SPEC, ASI_SCHEMA, '"schema_version": 1', 1)], None, True),
]


def baseline():
    """All ten unmutated detectors must be green."""
    bad = []
    for name, detector in DETECTORS.items():
        if detector() != 0:
            bad.append(name)
    return bad


def validate_anchors():
    """Every mutation anchor must be present exactly its declared count, with
    each mutation's edits applied in order against the running text so a later
    anchor may match text an earlier edit of the same mutation produced."""
    for name, _det, edits, _regen, _equiv in MUTATIONS:
        sim = {path: path.read_text() for path, _o, _n, _c in edits}
        for path, old, new, count in edits:
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
    for name, det, edits, regen_key, equiv in MUTATIONS:
        try:
            for path, old, new, count in edits:
                mutate(path, old, new, count)
            if regen_key is not None and REGEN[regen_key]() != 0:
                raise SystemExit("regen failed")
            rc = DETECTORS[det]()
        finally:
            restore()
        caught = rc != 0
        ok = caught if not equiv else (not caught)
        if ok:
            what = f"caught by {det}" if not equiv else f"SURVIVED by {det}"
            print(f"PASS {name:<48} {what}")
        else:
            got = "SURVIVED by %s" % det if not caught else "caught by %s" % det
            print(f"FAIL {name:<48} expected "
                  f"{'caught' if not equiv else 'SURVIVED'}, got {got}")
            failures += 1

    bad = baseline()
    if bad:
        print(f"FINAL BASELINE FAILED: {', '.join(bad)}")
        failures += 1

    print(f"TOTAL {len(MUTATIONS)} mutations, {failures} failures")
    if failures == 0:
        print("ALL AS EXPECTED")
        return 0
    print("MISMATCH")
    return 1


if __name__ == "__main__":
    sys.exit(main())
