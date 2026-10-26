#!/usr/bin/env python3
"""Mutation harness for the Step-0-pack x86 memory AUX layout contract.

Family files (watched, restored byte-exact after every row):
  x86_mem_aux_spec.json              four-field little-endian layout
  generate_x86_mem_aux_spec.py       exact EXPECTED + render_lean/render_c
  generated/x86_mem_aux.h            KPROG_X86_MEM_AUX packer + 4 decoders
  KProgFormal/GeneratedX86MemAux.lean  the generated pack/decoders module
  KProgFormal/X86MemAux.lean         independent byte-concat spec + theorems
  test_x86_mem_aux_host.c            7904-case simulator-alias host oracle
  ../x86/x86_sim.h                   the X86_MEM_AUX*/X86_REG_AUX_* aliasing
                                     + the six static-assert drift pins

Detectors:
  gen        `python3 generate_x86_mem_aux_spec.py --check`
  lean_chain `lake build KProgFormal.X86MemAux` (olean refresh) then
             `lake env lean KProgFormal/X86MemAux.lean` (self-contained: no
             downstream Lean module imports the hand module, so the chain
             elaborates the hand file itself and catches its own proof break)
  host       compile+run test_x86_mem_aux_host.c (-I. -I../x86, real
             simulator aliases exercised)
  route      compile+run test_x86_mem_read_dispatch_host.c with the vendor
             libbpf include path (compiles x86_sim_local_bpf.h, whose
             memory-index and ALU bodies call the X86_MEM_AUX_* accessors;
             a drifted accessor the contract host never reaches still
             breaks here)
"""
from __future__ import annotations

import subprocess
from pathlib import Path

FORMAL = Path(__file__).resolve().parent.parent
SPEC = FORMAL / "x86_mem_aux_spec.json"
GENPY = FORMAL / "generate_x86_mem_aux_spec.py"
GHEADER = FORMAL / "generated/x86_mem_aux.h"
GLEAN = FORMAL / "KProgFormal/GeneratedX86MemAux.lean"
HAND = FORMAL / "KProgFormal/X86MemAux.lean"
TEST_HOST = FORMAL / "test_x86_mem_aux_host.c"
SIM_HEADER = FORMAL.parent / "x86/x86_sim.h"

WATCHED = [SPEC, GENPY, GHEADER, GLEAN, HAND, TEST_HOST, SIM_HEADER]


def run(cmd, timeout=1200):
    try:
        return subprocess.run(cmd, cwd=FORMAL, timeout=timeout,
                              capture_output=True, text=True).returncode
    except subprocess.TimeoutExpired:
        return 124


HOST_INC = ["-I.", "-I../x86", "-I../../kprog",
            "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/"
            "prefix/include/bpf"]


def detect_gen() -> int:
    return run(["python3", "generate_x86_mem_aux_spec.py", "--check"], 300)


def detect_lean_chain() -> int:
    rc = run(["lake", "build", "KProgFormal.X86MemAux"], 600)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86MemAux.lean"], 600)


def detect_host() -> int:
    out = "build/mut_aux_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.", "-I../x86",
              "test_x86_mem_aux_host.c", "-o", out], 300)
    if rc != 0:
        return rc
    return run([out], 300)


def detect_route() -> int:
    out = "build/mut_aux_route"
    rc = run(["cc", "-Wall", "-Wextra", "-O2"] + HOST_INC +
             ["test_x86_mem_read_dispatch_host.c", "-o", out], 300)
    if rc != 0:
        return rc
    return run([out], 300)


DETECTORS = {"gen": detect_gen, "lean_chain": detect_lean_chain,
             "host": detect_host, "route": detect_route}


def restore(blobs: dict[Path, bytes]) -> None:
    for path, data in blobs.items():
        if path.read_bytes() != data:
            path.write_bytes(data)


def baseline() -> list[str]:
    bad = []
    for name, detector in DETECTORS.items():
        if detector() != 0:
            bad.append(name)
    return bad


def validate_anchors() -> bool:
    """Every anchor must be present exactly its declared count against a
    running copy of the watched files (later edits match earlier output)."""
    for name, _det, edits, _equiv in MUTATIONS:
        sim: dict[Path, str] = {}
        for path, old, new, count in edits:
            if count == 0:
                continue
            text = sim.get(path)
            if text is None:
                text = path.read_text()
            found = text.count(old)
            if found != count:
                print(f"ANCHOR FAIL {name}: {old[:64]!r} in {path.name} "
                      f"found={found} want={count}")
                return False
            sim[path] = text.replace(old, new)
    return True



MUTATIONS: list[tuple[str, str, list[tuple[Path, str, str, int]], bool]] = []


def row(name: str, det: str, edits: list, equivalent: bool = False) -> None:
    MUTATIONS.append((name, det, edits, equivalent))


# --- compact spec anchors (the generator compares the parsed JSON against
# EXPECTED, so every field-level edit is a data-level catch) -----------------
F_IDX = '{\n      "name": "index",\n      "shift": 0\n    }'
F_SCL = '{\n      "name": "scale_log2",\n      "shift": 8\n    }'
F_WID = '{\n      "name": "mem_width",\n      "shift": 16\n    }'
F_OP = '{\n      "name": "op",\n      "shift": 24\n    }'
SV = '"schema_version": 1'
OP = '"operation": "x86MemAux"'

row("spec_ver_repaint", "gen", [(SPEC, SV, '"schema_version": 2', 1)])
row("spec_op_repaint", "gen", [(SPEC, OP, '"operation": "x86MemAuxX"', 1)])
row("spec_word_bits", "gen",
    [(SPEC, '"word_bits": 32', '"word_bits": 33', 1)])
row("spec_field_bits", "gen",
    [(SPEC, '"field_bits": 8', '"field_bits": 7', 1)])
row("spec_field_idx_repaint", "gen",
    [(SPEC, F_IDX, '{\n      "name": "indexX",\n      "shift": 0}', 1)])
row("spec_field_idx_shift", "gen",
    [(SPEC, F_IDX, '{\n      "name": "index",\n      "shift": 1}', 1)])
row("spec_field_scl_repaint", "gen",
    [(SPEC, F_SCL, '{\n      "name": "scale_log2X",\n      "shift": 8}',
      1)])
row("spec_field_scl_shift", "gen",
    [(SPEC, F_SCL, '{\n      "name": "scale_log2",\n      "shift": 9}',
      1)])
row("spec_field_wid_repaint", "gen",
    [(SPEC, F_WID, '{\n      "name": "mem_widthX",\n      "shift": 16}',
      1)])
row("spec_field_wid_shift", "gen",
    [(SPEC, F_WID, '{\n      "name": "mem_width",\n      "shift": 17}',
      1)])
row("spec_field_op_repaint", "gen",
    [(SPEC, F_OP, '{\n      "name": "opX",\n      "shift": 24}', 1)])
row("spec_field_order", "gen",
    [(SPEC, F_IDX + ",\n    " + F_SCL,
      F_SCL + ",\n    " + F_IDX, 1)])
row("spec_none_repaint", "gen",
    [(SPEC, '"index_none": "0xff"', '"index_none": "0xfe"', 1)])

# --- generator pins: EXPECTED template + render code (byte-exact --check) ---
row("gen_ev_word_bits", "gen",
    [(GENPY, '"word_bits": 32,', '"word_bits": 33,', 1)])
row("gen_ev_field_idx", "gen",
    [(GENPY, '{"name": "index", "shift": 0},',
      '{"name": "index", "shift": 1},', 1)])
row("gen_ev_field_scl", "gen",
    [(GENPY, '{"name": "scale_log2", "shift": 8},',
      '{"name": "scale_log2", "shift": 9},', 1)])
row("gen_ev_field_wid", "gen",
    [(GENPY, '{"name": "mem_width", "shift": 16},',
      '{"name": "mem_width", "shift": 17},', 1)])
row("gen_ev_field_op", "gen",
    [(GENPY, '{"name": "op", "shift": 24},',
      '{"name": "op", "shift": 25},', 1)])
row("gen_ev_none", "gen",
    [(GENPY, '"index_none": "0xff",', '"index_none": "0xfe",', 1)])
row("gen_lean_name_scl", "gen",
    [(GENPY, '"scale_log2": "scaleLog2",', '"scale_log2X": "scaleLog2",', 1)])
row("gen_lean_name_wid", "gen",
    [(GENPY, '"mem_width": "memWidth",', '"mem_widthX": "memWidth",', 1)])
row("gen_c_name_idx", "gen",
    [(GENPY, '"index": "INDEX",', '"indexX": "INDEX",', 1)])
row("gen_render_mask", "gen",
    [(GENPY, 'f"  BitVec.and aux 0xff"', 'f"  BitVec.or aux 0xff"', 1)])
row("gen_render_shift", "gen",
    [(GENPY, 'BitVec.shiftLeft (BitVec.and {name} 0xff) {shift}',
      'BitVec.shiftRight (BitVec.and {name} 0xff) {shift}', 1)])
row("gen_render_c_mask", "gen",
    [(GENPY, 'term = f"((__u32)({name}) & 0xffU)"',
      'term = f"((__u32)({name}) & 0xfeU)"', 1)])
row("gen_render_c_shift", "gen",
    [(GENPY, 'if shift:\n            term = f"({term} << {shift})"',
      'if shift:\n            term = f"({term} >> {shift})"', 1)])
row("gen_render_decoder", "gen",
    [(GENPY, 'f"  BitVec.and (aux >>> {shift}) 0xff")',
      'f"  BitVec.and (aux << {shift}) 0xff")', 1)])
row("gen_render_c_dec", "gen",
    [(GENPY, 'f"((__u8)(((AUX) >> {shift}) & 0xffU))")',
      'f"((__u8)(((AUX) << {shift}) & 0xffU))")', 1)])
row("gen_msg_load", "gen",
    [(GENPY, 'invalid x86 memory AUX specification:',
      'invalidx x86 memory AUX specification:', 1)], equivalent=True)
row("gen_msg_stale", "gen",
    [(GENPY, 'generated x86 memory AUX contract is stale:',
      'generatedx x86 memory AUX contract is stale:', 1)], equivalent=True)
GH_PACK = ("#define KPROG_X86_MEM_AUX(INDEX, SCALE_LOG2, MEM_WIDTH, OP) "
           "\\\n\t")
# --- generated header pins (byte-exact under --check) ------------------------
GH_IDX_DEC = "#define KPROG_X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xffU))"
GH_SCL_DEC = "#define KPROG_X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 8) & 0xffU))"
GH_WID_DEC = "#define KPROG_X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 16) & 0xffU))"
GH_OP_DEC = "#define KPROG_X86_MEM_AUX_OP(AUX) ((__u8)(((AUX) >> 24) & 0xffU))"
GH_NONE = "#define KPROG_X86_MEM_AUX_INDEX_NONE 0xffU"
GH_PACK_IDX = "(((__u32)(INDEX) & 0xffU) | \\"
GH_PACK_SCL = "\t (((__u32)(SCALE_LOG2) & 0xffU) << 8) | \\"
GH_PACK_WID = "\t (((__u32)(MEM_WIDTH) & 0xffU) << 16) | \\"
GH_PACK_OP = "\t (((__u32)(OP) & 0xffU) << 24))"

row("gh_guard", "gen",
    [(GHEADER, "#ifndef KPROG_FORMAL_GENERATED_X86_MEM_AUX_H",
      "#ifndef KPROG_FORMAL_GENERATED_X86_MEM_AUX_HX", 1)])
row("gh_guard_def", "gen",
    [(GHEADER, "#define KPROG_FORMAL_GENERATED_X86_MEM_AUX_H",
      "#define KPROG_FORMAL_GENERATED_X86_MEM_AUX_HX", 1)])
row("gh_pack_name", "gen",
    [(GHEADER, "#define KPROG_X86_MEM_AUX(INDEX, SCALE_LOG2, MEM_WIDTH, OP)",
      "#define KPROG_X86_MEM_AUXX(INDEX, SCALE_LOG2, MEM_WIDTH, OP)", 1)])
row("gh_packer_idx", "gen",
    [(GHEADER, GH_PACK + GH_PACK_IDX,
      GH_PACK.replace("KPROG_X86_MEM_AUX(INDEX", "KPROG_X86_MEM_AUXX(INDEX")
      + "\t(((__u32)(INDEX) & 0xfeU) | \\", 1)])
row("gh_packer_wid", "gen",
    [(GHEADER, GH_PACK_WID,
      "\t (((__u32)(MEM_WIDTH) & 0xffU) << 17) | \\", 1)])
row("gh_packer_op", "gen",
    [(GHEADER, GH_PACK_OP,
      "\t (((__u32)(OP) & 0xffU) << 25))", 1)])
row("gh_packer_scale_mask", "gen",
    [(GHEADER, GH_PACK_SCL,
      "\t (((__u32)(SCALE_LOG2) & 0x7fU) << 8) | \\", 1)])
row("gh_packer_op_nobracket", "gen",
    [(GHEADER, GH_PACK_OP, "\t (((__u32)(OP) & 0xffU) << 24))  ", 1)])
row("gh_dec_idx", "gen",
    [(GHEADER, GH_IDX_DEC,
      "#define KPROG_X86_MEM_AUX_INDEX(AUX) ((__u8)((AUX) & 0xfeU))", 1)])
row("gh_dec_scl", "gen",
    [(GHEADER, GH_SCL_DEC,
      "#define KPROG_X86_MEM_AUX_SCALE_LOG2(AUX) ((__u8)(((AUX) >> 9) & 0xffU))",
      1)])
row("gh_dec_wid", "gen",
    [(GHEADER, GH_WID_DEC,
      "#define KPROG_X86_MEM_AUX_MEM_WIDTH(AUX) ((__u8)(((AUX) >> 17) & 0xffU))",
      1)])
row("gh_dec_op", "gen",
    [(GHEADER, GH_OP_DEC,
      "#define KPROG_X86_MEM_AUX_OP(AUX) ((__u8)(((AUX) >> 25) & 0xffU))", 1)])
row("gh_dec_op_trailing_space", "gen",
    [(GHEADER, GH_OP_DEC,
      "#define KPROG_X86_MEM_AUX_OP(AUX) ((__u8)(((AUX) >> 24) & 0xffU)) ",
      1)])
row("gh_none", "gen",
    [(GHEADER, GH_NONE,
      "#define KPROG_X86_MEM_AUX_INDEX_NONE 0xfeU", 1)])
row("gl_pack_idx_mask", "gen",
    [(GLEAN, "(BitVec.and index 0xff)", "(BitVec.and index 0xfe)", 1)])
row("gl_pack_scl_shift", "gen",
    [(GLEAN, "(BitVec.shiftLeft (BitVec.and scaleLog2 0xff) 8)",
      "(BitVec.shiftLeft (BitVec.and scaleLog2 0xff) 9)", 1)])
row("gl_pack_wid_shift", "gen",
    [(GLEAN, "(BitVec.shiftLeft (BitVec.and memWidth 0xff) 16)",
      "(BitVec.shiftLeft (BitVec.and memWidth 0xff) 17)", 1)])
row("gl_pack_op_shift", "gen",
    [(GLEAN, "(BitVec.shiftLeft (BitVec.and op 0xff) 24)",
      "(BitVec.shiftLeft (BitVec.and op 0xff) 25)", 1)])
row("gl_dec_idx", "gen",
    [(GLEAN, "def index (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and aux 0xff",
      "def index (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and aux 0xfe", 1)])
row("gl_dec_scl", "gen",
    [(GLEAN, "def scaleLog2 (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 8) 0xff",
      "def scaleLog2 (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 9) 0xff", 1)])
row("gl_dec_wid", "gen",
    [(GLEAN, "def memWidth (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 16) 0xff",
      "def memWidth (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 17) 0xff", 1)])
row("gl_dec_op", "gen",
    [(GLEAN, "def op (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 24) 0xff",
      "def op (aux : BitVec 32) : BitVec 32 :=\n"
      "  BitVec.and (aux >>> 25) 0xff", 1)])
row("gl_index_none", "gen",
    [(GLEAN, "def indexNone : BitVec 32 := 0xff",
      "def indexNone : BitVec 32 := 0xfe", 1)])

# --- hand module (lean_chain elaborates it; no downstream consumers, so
# every break is the module's own proof chain) -------------------------------
row("hd_spec_concat_op", "lean_chain",
    [(HAND, "  opTag.setWidth 8 ++ memWidthCode.setWidth 8 ++\n"
      "    scaleExp.setWidth 8 ++ indexReg.setWidth 8",
      "  opTag.setWidth 8 ++ memWidthCode.setWidth 8 ++\n"
      "    scaleExp.setWidth 8 ++ (indexReg.setWidth 8 +++ 1)", 1)])
row("hd_spec_op_bump", "lean_chain",
    [(HAND, "opTag.setWidth 8", "opTag.setWidth 9", 1)])
row("hd_pack_refines_repaint", "lean_chain",
    [(HAND, "    pack indexReg scaleExp memWidthCode opTag =\n"
      "      x86MemAuxSpec indexReg scaleExp memWidthCode opTag",
      "    pack indexReg scaleExp memWidthCode opTag =\n"
      "      x86MemAuxSpec indexReg scaleExp memWidthCode (opTag +++ 1)", 1)])
row("hd_index_rt", "lean_chain",
    [(HAND, "    index (pack indexReg scaleExp memWidthCode opTag) =\n"
      "      BitVec.and indexReg 0xff",
      "    index (pack indexReg scaleExp memWidthCode opTag) =\n"
      "      BitVec.and indexReg 0xfe", 1)])
row("hd_scale_rt", "lean_chain",
    [(HAND, "    scaleLog2 (pack indexReg scaleExp memWidthCode opTag) ="
      "\n      BitVec.and scaleExp 0xff",
      "    scaleLog2 (pack indexReg scaleExp memWidthCode opTag) ="
      "\n      BitVec.and scaleExp 0xfe", 1)])
row("hd_width_rt", "lean_chain",
    [(HAND, "    memWidth (pack indexReg scaleExp memWidthCode opTag) ="
      "\n      BitVec.and memWidthCode 0xff",
      "    memWidth (pack indexReg scaleExp memWidthCode opTag) ="
      "\n      BitVec.and memWidthCode 0xfe", 1)])
row("hd_op_rt", "lean_chain",
    [(HAND, "    op (pack indexReg scaleExp memWidthCode opTag) =\n"
      "      BitVec.and opTag 0xff",
      "    op (pack indexReg scaleExp memWidthCode opTag) =\n"
      "      BitVec.and opTag 0xfe", 1)])
row("hd_non_interfering_arm3", "lean_chain",
    [(HAND, "      memWidth (pack indexReg scaleExp memWidthCode opTag) =\n"
      "        BitVec.and memWidthCode 0xff ∧",
      "      memWidth (pack indexReg scaleExp memWidthCode opTag) =\n"
      "        BitVec.and memWidthCode 0xfe ∧", 1)])
row("hd_none_rt", "lean_chain",
    [(HAND, "    index (pack indexNone scaleExp memWidthCode opTag) ="
      " indexNone",
      "    index (pack indexNone scaleExp memWidthCode opTag) ="
      " (indexNone +++ 1)", 1)])
row("hd_none_is_ff", "lean_chain",
    [(HAND, "theorem x86_mem_aux_index_none_is_0xff : indexNone = 0xff",
      "theorem x86_mem_aux_index_none_is_0xff : indexNone = 0xfe", 1)])
row("hd_example_repaint", "lean_chain",
    [(HAND, "    pack 1 2 3 4 = 0x04030201",
      "    pack 1 2 3 4 = 0x04030202", 1)])
row("hd_srclane_example", "lean_chain",
    [(HAND, "    memWidth (pack 0 0 8 8) = 8 ∧ op (pack 0 0 8 8) = 8",
      "    memWidth (pack 0 0 8 8) = 8 ∧ op (pack 0 0 8 8) = 9", 1)])
row("hd_spec_rename", "lean_chain",
    [(HAND, "def x86MemAuxSpec ", "def x86MemAuxSpecX ", 1)])
row("hd_pack_refines_rename", "lean_chain",
    [(HAND, "theorem x86_mem_aux_pack_refines",
      "theorem x86_mem_aux_pack_refinesX", 1)], equivalent=True)
row("host_index_ret", "host",
    [(TEST_HOST,
      '\tcheck_field("index", X86_MEM_AUX_INDEX(aux_op), index & 0xffU,'
      ' aux_op);',
      '\tcheck_field("index", X86_MEM_AUX_INDEX(aux_op), index ^ 1U,'
      ' aux_op);', 1)])
row("host_scale_ret", "host",
    [(TEST_HOST, '\tcheck_field("scale", X86_MEM_AUX_SCALE_LOG2(aux_op),'
      ' scale & 0xffU,',
      '\tcheck_field("scale", X86_MEM_AUX_SCALE_LOG2(aux_op),'
      ' scale ^ 1U,', 1)])
row("host_width_ret", "host",
    [(TEST_HOST, '\tcheck_field("mem_width",'
      ' X86_MEM_AUX_MEM_WIDTH(aux_op), width & 0xffU,',
      '\tcheck_field("mem_width", X86_MEM_AUX_MEM_WIDTH(aux_op),'
      ' width ^ 1U,', 1)])
row("host_alu_ret", "host",
    [(TEST_HOST, '\tcheck_field("alu_op", X86_MEM_AUX_GET_ALU_OP(aux_op),'
      ' op & 0xffU,',
      '\tcheck_field("alu_op", X86_MEM_AUX_GET_ALU_OP(aux_op),'
      ' op ^ 1U,', 1)])
row("host_srcshift_ret", "host",
    [(TEST_HOST, '\tcheck_field("src_shift",'
      ' X86_REG_AUX_GET_SRC_SHIFT(aux_op), op & 0xffU,',
      '\tcheck_field("src_shift", X86_REG_AUX_GET_SRC_SHIFT(aux_op),'
      ' op ^ 1U,', 1)])
row("host_op_slot", "host",
    [(TEST_HOST, '\tcheck_field("op_slot", X86_MEM_AUX_ALU_OP(op),'
      ' (op & 0xffU) << 24,',
      '\tcheck_field("op_slot", X86_MEM_AUX_ALU_OP(op),'
      ' (op & 0xffU) << 23,', 1)])
row("host_srcshift_slot", "host",
    [(TEST_HOST, '\tcheck_field("src_shift_slot",'
      ' X86_REG_AUX_SRC_SHIFT(op),\n\t\t    (op & 0xffU) << 24,',
      '\tcheck_field("src_shift_slot", X86_REG_AUX_SRC_SHIFT(op),'
      '\n\t\t    (op & 0xffU) << 25,', 1)])
row("host_pack_full", "host",
    [(TEST_HOST, '__u32 aux = X86_MEM_AUX_FULL(index, scale, width);',
      '__u32 aux = X86_MEM_AUX_FULL(index, scale, width) ^ 0x1000000U;',
      1)])
row("host_pack_eq_full", "host",
    [(TEST_HOST, 'check_field("pack_eq_full", X86_MEM_AUX(index, scale) |'
      '\n\t\t\t\t\t X86_MEM_AUX_MEM_WIDTH(aux) << 16,',
      'check_field("pack_eq_full", X86_MEM_AUX(index, scale) |'
      '\n\t\t\t\t\t X86_MEM_AUX_MEM_WIDTH(aux) << 15,', 1)])
row("host_failures_noout", "host",
    [(TEST_HOST, '\tfailures++;\n\t}', '\t/* failures++ removed */\n\t}',
      1)], equivalent=True)
row("host_banner", "host",
    [(TEST_HOST, 'printf("x86 memory aux host cross-check: OK (%lu cases)'
      '\\n", cases);',
      'printf("x86 memory aux host cross-check: OKX (%lu cases)\\n",'
      ' cases);', 1)], equivalent=True)
row("host_exh_transpose", "host",
    [(TEST_HOST, 'aux = X86_MEM_AUX_FULL(0U, l, 0U);',
      'aux = X86_MEM_AUX_FULL(0U, l, 7U);', 1)], equivalent=True)
row("host_case_count_gate", "host",
    [(TEST_HOST, 'printf("x86 memory aux host cross-check: OK (%lu cases)'
      '\\n", cases);',
      'printf("x86 memory aux host cross-check: OK (%lu cases)\\n",'
      ' cases - 1);', 1)], equivalent=True)
# --- simulator header alias anchors (compiles through every detector's
# host/route paths; the sim header itself is a watched file) -----------------
row("sim_alias_index", "host",
    [(SIM_HEADER, "#define X86_MEM_AUX_INDEX(AUX) KPROG_X86_MEM_AUX_INDEX(AUX)",
      "#define X86_MEM_AUX_INDEX(AUX) KPROG_X86_MEM_AUX_SCALE_LOG2(AUX)", 1)])
row("sim_alias_scale", "host",
    [(SIM_HEADER,
      "#define X86_MEM_AUX_SCALE_LOG2(AUX) KPROG_X86_MEM_AUX_SCALE_LOG2(AUX)",
      "#define X86_MEM_AUX_SCALE_LOG2(AUX) KPROG_X86_MEM_AUX_MEM_WIDTH(AUX)",
      1)])
row("sim_alias_width", "host",
    [(SIM_HEADER,
      "#define X86_MEM_AUX_MEM_WIDTH(AUX) KPROG_X86_MEM_AUX_MEM_WIDTH(AUX)",
      "#define X86_MEM_AUX_MEM_WIDTH(AUX) KPROG_X86_MEM_AUX_OP(AUX)", 1)])
row("sim_alias_getsrc", "host",
    [(SIM_HEADER,
      "#define X86_REG_AUX_GET_SRC_SHIFT(AUX) KPROG_X86_MEM_AUX_OP(AUX)",
      "#define X86_REG_AUX_GET_SRC_SHIFT(AUX) KPROG_X86_MEM_AUX_MEM_WIDTH(AUX)",
      1)])
row("sim_alias_full", "host",
    [(SIM_HEADER,
      "#define X86_MEM_AUX_FULL(INDEX, SCALE_LOG2, MEM_WIDTH)      "
      "                \\\n\tKPROG_X86_MEM_AUX((INDEX), (SCALE_LOG2),"
      " (MEM_WIDTH), 0U)",
      "#define X86_MEM_AUX_FULL(INDEX, SCALE_LOG2, MEM_WIDTH)      "
      "                \\\n\tKPROG_X86_MEM_AUX((INDEX), (SCALE_LOG2),"
      " (MEM_WIDTH), 3U)",
      1)])
row("sim_static_assert_index", "host",
    [(SIM_HEADER,
      "_Static_assert(KPROG_X86_MEM_AUX_INDEX(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0xabU,",
      "_Static_assert(KPROG_X86_MEM_AUX_INDEX(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0xacU,", 1)])
row("sim_static_assert_scale", "host",
    [(SIM_HEADER,
      "_Static_assert(KPROG_X86_MEM_AUX_SCALE_LOG2(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 8U,",
      "_Static_assert(KPROG_X86_MEM_AUX_SCALE_LOG2(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 9U,", 1)])
row("sim_static_assert_width", "host",
    [(SIM_HEADER,
      "_Static_assert(KPROG_X86_MEM_AUX_MEM_WIDTH(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0x30U,",
      "_Static_assert(KPROG_X86_MEM_AUX_MEM_WIDTH(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0x31U,", 1)])
row("sim_static_assert_op", "host",
    [(SIM_HEADER,
      "_Static_assert(KPROG_X86_MEM_AUX_OP(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0x77U,",
      "_Static_assert(KPROG_X86_MEM_AUX_OP(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0x78U,", 1)])
row("sim_routed_allocator", "route",
    [(SIM_HEADER,
      "_Static_assert(KPROG_X86_MEM_AUX_INDEX(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0xabU,\n"
      "\t\"x86 memory AUX index byte drift\");",
      "/* static assert repaint */\n"
      "_Static_assert(KPROG_X86_MEM_AUX_INDEX(\n"
      "\tKPROG_X86_MEM_AUX(0xabU, 8U, 0x30U, 0x77U)) == 0xabU,\n"
      "\t\"x86 memory AUX index byte drift\");", 1)], equivalent=True)


def main() -> int:
    blobs = {path: path.read_bytes() for path in WATCHED}

    def restore() -> bool:
        dirty = False
        for path, data in blobs.items():
            if path.read_bytes() != data:
                path.write_bytes(data)
                dirty = True
        return dirty

    if not validate_anchors():
        restore()
        return 1
    bad = baseline()
    if bad:
        print(f"BASELINE FAILED: {', '.join(bad)}")
        return 1
    failures = 0
    survivors = 0
    try:
        for name, det, edits, equiv in MUTATIONS:
            if det.startswith("equivalent_"):
                # probe rows never execute a detector
                survivors += 1
                print(f"PASS {name:<44} probed-equivalent (no detector)")
                continue
            try:
                for path, old, new, count in edits:
                    if count == 0:
                        continue
                    text = Path(path).read_text()
                    if text.count(old) != count:
                        raise SystemExit(
                            f"anchor {old[:48]!r} in {Path(path).name} "
                            f"not found {count}x")
                    Path(path).write_text(text.replace(old, new, count))
                rc = DETECTORS[det]()
            finally:
                if restore():
                    print(f"(restored dirty files after {name})")
            caught = rc != 0
            if equiv:
                survivors += (not caught)
                if caught:
                    print(f"FAIL {name}: marked equivalent but caught")
                    failures += 1
                else:
                    print(f"PASS {name:<44} SURVIVED by {det} (equivalent)")
            elif caught:
                print(f"PASS {name:<44} caught by {det}")
            else:
                failures += 1
                print(f"FAIL {name}: {det} survived but marked catchable")
        bad = baseline()
        if bad:
            print(f"FINAL BASELINE FAILED: {', '.join(bad)}")
            failures += 1
        print(f"TOTAL {len(MUTATIONS)} mutations, {failures} failures, "
              f"{survivors} equivalences survived")
        print("ALL AS EXPECTED" if failures == 0 else "MUTATION MISMATCH")
        return 0 if failures == 0 else 1
    finally:
        restore()


if __name__ == "__main__":
    raise SystemExit(main())
