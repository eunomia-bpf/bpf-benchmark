#!/usr/bin/env python3
"""Mutation harness for the Step-0259 x86 register-lane AUX layout contract.

Family files (watched, restored byte-exact after every row):
  x86_reg_lane_aux_spec.json         three-field lane layout (payload,
                                     dst_shift<<8, src_shift<<16)
  generate_x86_reg_lane_aux_spec.py  exact EXPECTED + render_lean/render_c/
                                     render_python (byte-exact --check)
  generated/x86_reg_lane_aux.h       KPROG_X86_REG_LANE_AUX packer + 3
                                     decoders
  KProgFormal/GeneratedX86RegLaneAux.lean  generated pack/decoders module
  KProgFormal/X86RegLaneAux.lean     independent concat spec + theorems
  test_x86_reg_lane_aux_host.c       7629-case simulator-alias host oracle
  ../x86/micro-prog/generated_x86_reg_lane_aux.py
                                     the micro-prog encoder (c_reg_lane_aux)
  ../x86/x86_sim.h                   the three static-assert lane-drift pins

Detectors:
  gen        `python3 generate_x86_reg_lane_aux_spec.py --check` (byte-compares
             the four rendered outputs, including the micro-prog encoder)
  lean_chain `lake build KProgFormal.X86RegLaneAux KProgFormal.X86AluDecode
             KProgFormal.X86SetccHandler` then
             `lake env lean KProgFormal/X86RegLaneAux.lean` (X86AluDecode and
             X86SetccHandler consume the hand-module roundtrip theorems, so a
             rename or repaint those consumers reference breaks the chain;
             X86MovHandler imports the generated module without using any
             RegLaneAux name and is not part of the chain)
  host       compile+run test_x86_reg_lane_aux_host.c (-I. -I../x86, real
             decoders exercised over the 19^3 grid)
  route      compile+run test_x86_alu_result_route_host.c with the vendor
             libbpf include path (compiles x86_sim_local_bpf.h, whose ALU
             bodies call the KPROG_X86_REG_LANE_AUX_* decoders at the
             EXEC_ALU_IMM/EXEC_ALU_REG call sites; a drifted call site the
             contract host never reaches still breaks here)

The moving contract: every row's classification was probed live against the
running detectors before being pinned here; equivalences are documented
survivals (a repaint the driven streams cannot distinguish), not skipped rows.
"""
from __future__ import annotations

import subprocess
from pathlib import Path

FORMAL = Path(__file__).resolve().parent.parent
SPEC = FORMAL / "x86_reg_lane_aux_spec.json"
GENPY = FORMAL / "generate_x86_reg_lane_aux_spec.py"
GHEADER = FORMAL / "generated/x86_reg_lane_aux.h"
GLEAN = FORMAL / "KProgFormal/GeneratedX86RegLaneAux.lean"
HAND = FORMAL / "KProgFormal/X86RegLaneAux.lean"
TEST_HOST = FORMAL / "test_x86_reg_lane_aux_host.c"
ENCODER = FORMAL.parent / "x86/micro-prog/generated_x86_reg_lane_aux.py"
SIM_HEADER = FORMAL.parent / "x86/x86_sim.h"
SIM_LBPF = FORMAL.parent / "x86/x86_sim_local_bpf.h"

WATCHED = [SPEC, GENPY, GHEADER, GLEAN, HAND, TEST_HOST, ENCODER, SIM_HEADER,
           SIM_LBPF]


def run(cmd, timeout=1200):
    try:
        return subprocess.run(cmd, cwd=FORMAL, timeout=timeout,
                              capture_output=True, text=True).returncode
    except subprocess.TimeoutExpired:
        return 124


HOST_INC = ["-I.", "-I../x86", "-I../../kprog",
            "-I../../runner/build-host-docker-llvmbpf/vendor/libbpf/"
            "prefix/include/bpf"]

LEAN_CHAIN_MODULES = ["KProgFormal.X86RegLaneAux", "KProgFormal.X86AluDecode",
                      "KProgFormal.X86SetccHandler"]


def detect_gen() -> int:
    return run(["python3", "generate_x86_reg_lane_aux_spec.py", "--check"],
               300)


def detect_lean_chain() -> int:
    rc = run(["lake", "build"] + LEAN_CHAIN_MODULES, 600)
    if rc != 0:
        return rc
    return run(["lake", "env", "lean", "KProgFormal/X86RegLaneAux.lean"], 600)


def detect_host() -> int:
    out = "build/mut_rl_aux_host"
    rc = run(["cc", "-Wall", "-Wextra", "-O2", "-I.", "-I../x86",
              "test_x86_reg_lane_aux_host.c", "-o", out], 300)
    if rc != 0:
        return rc
    return run([out], 300)


def detect_route() -> int:
    """ALU result route (EXEC_ALU_IMM/EXEC_ALU_REG decoder call sites) plus
    the cmpop route (EXEC_CMPOP mem-reg lane call sites); either failing is
    a catch."""
    for host in ("test_x86_alu_result_route_host.c",
                 "test_x86_cmpop_route_host.c"):
        out = "build/mut_rl_aux_route"
        rc = run(["cc", "-Wall", "-Wextra", "-O1"] + HOST_INC +
                 [host, "-o", out], 300)
        if rc != 0:
            return rc
        rc = run([out], 300)
        if rc != 0:
            return rc
    return 0



DETECTORS = {"gen": detect_gen, "lean_chain": detect_lean_chain,
             "host": detect_host, "route": detect_route}


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
F_PAY = '{"name":"payload","shift":0,"mask":"0xff"}'
F_DST = '{"name":"dst_shift","shift":8,"mask":"0xff"}'
F_SRC = '{"name":"src_shift","shift":16,"mask":"0xff"}'
SV = '"schema_version":1'
OP = '"operation":"x86RegLaneAux"'
VBS = '"valid_byte_shifts":[0,8]'

row("spec_ver_repaint", "gen", [(SPEC, SV, '"schema_version":2', 1)])
row("spec_op_repaint", "gen", [(SPEC, OP, '"operation":"x86RegLaneAuxX"', 1)])
row("spec_field_pay_repaint", "gen",
    [(SPEC, F_PAY, '{"name":"payloadX","shift":0,"mask":"0xff"}', 1)])
row("spec_field_pay_shift", "gen",
    [(SPEC, F_PAY, '{"name":"payload","shift":1,"mask":"0xff"}', 1)])
row("spec_field_dst_repaint", "gen",
    [(SPEC, F_DST, '{"name":"dst_shiftX","shift":8,"mask":"0xff"}', 1)])
row("spec_field_dst_shift", "gen",
    [(SPEC, F_DST, '{"name":"dst_shift","shift":9,"mask":"0xff"}', 1)])
row("spec_field_src_repaint", "gen",
    [(SPEC, F_SRC, '{"name":"src_shiftX","shift":16,"mask":"0xff"}', 1)])
row("spec_field_src_shift", "gen",
    [(SPEC, F_SRC, '{"name":"src_shift","shift":17,"mask":"0xff"}', 1)])
row("spec_field_dst_mask", "gen",
    [(SPEC, F_DST, '{"name":"dst_shift","shift":8,"mask":"0xfe"}', 1)])
row("spec_field_order", "gen",
    [(SPEC, F_DST + "," + F_SRC, F_SRC + "," + F_DST, 1)])
row("spec_vbs_repaint", "gen",
    [(SPEC, VBS, '"valid_byte_shifts":[0,9]', 1)])
row("spec_vbs_members", "gen",
    [(SPEC, VBS, '"valid_byte_shifts":[8]', 1)])
row("spec_tail_trailing_space", "gen",
    [(SPEC, VBS + "}\n", VBS + "} \n", 1)], equivalent=True)

# --- generator pins: EXPECTED template + render code (byte-exact --check) ---
row("gen_ev_ver", "gen",
    [(GENPY, '"schema_version": 1,', '"schema_version": 2,', 1)])
row("gen_ev_op", "gen",
    [(GENPY, '"operation": "x86RegLaneAux",',
      '"operation": "x86RegLaneAuxX",', 1)])
row("gen_ev_field_pay", "gen",
    [(GENPY, '{"name": "payload", "shift": 0, "mask": "0xff"},',
      '{"name": "payload", "shift": 1, "mask": "0xff"},', 1)])
row("gen_ev_field_dst", "gen",
    [(GENPY, '{"name": "dst_shift", "shift": 8, "mask": "0xff"},',
      '{"name": "dst_shift", "shift": 9, "mask": "0xff"},', 1)])
row("gen_ev_field_src", "gen",
    [(GENPY, '{"name": "src_shift", "shift": 16, "mask": "0xff"},',
      '{"name": "src_shift", "shift": 17, "mask": "0xff"},', 1)])
row("gen_ev_vbs", "gen",
    [(GENPY, '"valid_byte_shifts": [0, 8],', '"valid_byte_shifts": [0, 9],',
      1)])
row("gen_render_lean_pack_or", "gen",
    [(GENPY, "BitVec.or (BitVec.and payload 0xff)",
      "BitVec.or (BitVec.and payload 0xfe)", 1)])
row("gen_render_lean_pack_dst", "gen",
    [(GENPY, "BitVec.or (BitVec.shiftLeft (BitVec.and dstShift 0xff) 8)",
      "BitVec.or (BitVec.shiftLeft (BitVec.and dstShift 0xff) 9)", 1)])
row("gen_render_lean_pack_src", "gen",
    [(GENPY, "BitVec.shiftLeft (BitVec.and srcShift 0xff) 16))",
      "BitVec.shiftLeft (BitVec.and srcShift 0xff) 17))", 1)])
row("gen_render_lean_dec_payload", "gen",
    [(GENPY, "def payload (aux : BitVec 32) : BitVec 32 := BitVec.and aux 0xff",
      "def payload (aux : BitVec 32) : BitVec 32 := BitVec.and aux 0xfe", 1)])
row("gen_render_lean_dec_dst", "gen",
    [(GENPY, "def dstShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 8) 0xff",
      "def dstShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 9) 0xff", 1)])
row("gen_render_lean_dec_src", "gen",
    [(GENPY, "def srcShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 16) 0xff",
      "def srcShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 17) 0xff", 1)])
row("gen_render_c_pack1", "gen",
    [(GENPY, "\\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\\\",
      "\\t(((__u32)(PAYLOAD) & 0xfeU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\\\", 1)])
row("gen_render_c_pack2", "gen",
    [(GENPY, "\\t (((__u32)(SRC_SHIFT) & 0xffU) << 16))",
      "\\t (((__u32)(SRC_SHIFT) & 0xffU) << 17))", 1)])
row("gen_render_c_dec_payload", "gen",
    [(GENPY, "#define KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)"
      " ((__u8)((AUX) & 0xffU))",
      "#define KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)"
      " ((__u8)((AUX) & 0xfeU))", 1)])
row("gen_render_c_dec_dst", "gen",
    [(GENPY, "\\t((__u8)(((AUX) >> 8) & 0xffU))",
      "\\t((__u8)(((AUX) >> 9) & 0xffU))", 1)])
row("gen_render_c_dec_src", "gen",
    [(GENPY, "\\t((__u8)(((AUX) >> 16) & 0xffU))",
      "\\t((__u8)(((AUX) >> 17) & 0xffU))", 1)])
row("gen_render_py_vbs", "gen",
    [(GENPY, "VALID_BYTE_SHIFTS = frozenset({0, 8})",
      "VALID_BYTE_SHIFTS = frozenset({0, 9})", 1)])
row("gen_render_py_check", "gen",
    [(GENPY, "if dst_shift not in VALID_BYTE_SHIFTS"
      " or src_shift not in VALID_BYTE_SHIFTS:",
      "if dst_shift not in VALID_BYTE_SHIFTS"
      " and src_shift not in VALID_BYTE_SHIFTS:", 1)])
row("gen_render_py_err", "gen",
    [(GENPY, 'f"invalid x86 byte lane shifts: dst={dst_shift}'
      ' src={src_shift}"',
      'f"invalid x86 byte lane shifts: dst={dst_shift}'
      ' srw={src_shift}"', 1)])
row("gen_render_py_bare", "gen",
    [(GENPY, "if dst_shift == 0 and src_shift == 0:\n        return payload",
      "if dst_shift == 0 and src_shift == 0:\n        return payload * 1",
      1)])
row("gen_render_py_ret", "gen",
    [(GENPY, 'return f"KPROG_X86_REG_LANE_AUX(({payload}), {dst_shift},'
      ' {src_shift})"',
      'return f"KPROG_X86_REG_LANE_AUX(({payload}), {dst_shift} + 0, '
      '{src_shift})"', 1)])
row("gen_msg_invalid_spec", "gen",
    [(GENPY, "invalid x86 register-lane AUX specification:",
      "invalidx x86 register-lane AUX specification:", 1)], equivalent=True)
row("gen_msg_stale", "gen",
    [(GENPY, "generated x86 register-lane AUX contract is stale:",
      "generatedx x86 register-lane AUX contract is stale:", 1)],
    equivalent=True)
row("gen_python_path", "gen",
    [(GENPY, 'PYTHON = ROOT.parent / "x86/micro-prog/'
      'generated_x86_reg_lane_aux.py"',
      'PYTHON = ROOT.parent / "x86/micro-prog/'
      'generated_x86_reg_lane_aux.py "', 1)])

# --- encoder module rows (bytes identical to gen_render_py_* outputs; the
# --check byte-compare treats the encoder as the fourth render target) -------
row("enc_vbs_repaint", "gen",
    [(ENCODER, "VALID_BYTE_SHIFTS = frozenset({0, 8})",
      "VALID_BYTE_SHIFTS = frozenset({0, 9})", 1)])
row("enc_check_and_or", "gen",
    [(ENCODER, "if dst_shift not in VALID_BYTE_SHIFTS"
      " or src_shift not in VALID_BYTE_SHIFTS:",
      "if dst_shift not in VALID_BYTE_SHIFTS"
      " and src_shift not in VALID_BYTE_SHIFTS:", 1)])
row("enc_err_msg", "gen",
    [(ENCODER, 'f"invalid x86 byte lane shifts: dst={dst_shift}'
      ' src={src_shift}"',
      'f"invalid x86 byte lane shifts: dst={dst_shift}'
      ' srw={src_shift}"', 1)])
row("enc_bare_clause", "gen",
    [(ENCODER, "if dst_shift == 0 and src_shift == 0:\n        return payload",
      "if dst_shift == 0 and src_shift == 0:\n        return payload * 1",
      1)])
row("enc_pack_fstring", "gen",
    [(ENCODER, 'return f"KPROG_X86_REG_LANE_AUX(({payload}), {dst_shift}, '
      '{src_shift})"',
      'return f"KPROG_X86_REG_LANE_AUX(({payload}), {dst_shift} + 0, '
      '{src_shift})"', 1)])
row("enc_genmark", "gen",
    [(ENCODER, "# Generated by generate_x86_reg_lane_aux_spec.py",
      "# regenerated by generate_x86_reg_lane_aux_spec.py", 1)])

# --- generated header pins (byte-exact under --check) -----------------------
GH_GUARD = "KPROG_FORMAL_GENERATED_X86_REG_LANE_AUX_H"
GH_PACK_HDR = ("#define KPROG_X86_REG_LANE_AUX(PAYLOAD, DST_SHIFT, SRC_SHIFT)"
               "              \\\n\t")

row("gh_guard_ifndef", "gen",
    [(GHEADER, "#ifndef " + GH_GUARD, "#ifndef " + GH_GUARD + "X", 1)])
row("gh_guard_define", "gen",
    [(GHEADER, "#define " + GH_GUARD, "#define " + GH_GUARD + "X", 1)])
row("gh_pack_name", "gen",
    [(GHEADER, "#define KPROG_X86_REG_LANE_AUX(PAYLOAD, DST_SHIFT, SRC_SHIFT)",
      "#define KPROG_X86_REG_LANE_AUXX(PAYLOAD, DST_SHIFT, SRC_SHIFT)", 1)])
row("gh_pack_trailing_ws", "gen",
    [(GHEADER, GH_PACK_HDR,
      GH_PACK_HDR.replace("\\\\\n", " \\\n"), 1)], equivalent=True)
row("gh_packer_pay_mask", "gen",
    [(GHEADER, "\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\",
      "\t(((__u32)(PAYLOAD) & 0xfeU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\", 1)])
row("gh_packer_dst_shift", "gen",
    [(GHEADER, "\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\",
      "\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 9) | \\", 1)])
row("gh_packer_src_shift", "gen",
    [(GHEADER, "\t (((__u32)(SRC_SHIFT) & 0xffU) << 16))",
      "\t (((__u32)(SRC_SHIFT) & 0xffU) << 17))", 1)])
row("gh_packer_dst_mask", "gen",
    [(GHEADER, "\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0xffU)"
      " << 8) | \\",
      "\t(((__u32)(PAYLOAD) & 0xffU) | (((__u32)(DST_SHIFT) & 0x7fU)"
      " << 8) | \\", 1)])
row("gh_dec_payload", "gen",
    [(GHEADER, "#define KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)"
      " ((__u8)((AUX) & 0xffU))",
      "#define KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)"
      " ((__u8)((AUX) & 0xfeU))", 1)])
row("gh_dec_dst_hdr", "gen",
    [(GHEADER, "#define KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX)"
      "                              \\",
      "#define KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX)"
      "                             \\", 1)])
row("gh_dec_dst", "gen",
    [(GHEADER, "\t((__u8)(((AUX) >> 8) & 0xffU))",
      "\t((__u8)(((AUX) >> 9) & 0xffU))", 1)])
row("gh_dec_src", "gen",
    [(GHEADER, "\t((__u8)(((AUX) >> 16) & 0xffU))",
      "\t((__u8)(((AUX) >> 17) & 0xffU))", 1)])
row("gh_genmark_missing", "gen",
    [(GHEADER, "/* Generated by generate_x86_reg_lane_aux_spec.py from"
      " x86_reg_lane_aux_spec.json. */",
      "/* produced by generate_x86_reg_lane_aux_spec.py from"
      " x86_reg_lane_aux_spec.json. */", 1)])

# --- generated lean pins ----------------------------------------------------
row("gl_pack_pay_mask", "lean_chain",
    [(GLEAN, "  BitVec.or (BitVec.and payload 0xff)",
      "  BitVec.or (BitVec.and payload 0xfe)", 1)])
row("gl_pack_dst_shift", "lean_chain",
    [(GLEAN, "(BitVec.or (BitVec.shiftLeft (BitVec.and dstShift 0xff) 8)",
      "(BitVec.or (BitVec.shiftLeft (BitVec.and dstShift 0xff) 9)", 1)])
row("gl_pack_src_shift", "lean_chain",
    [(GLEAN, "(BitVec.shiftLeft (BitVec.and srcShift 0xff) 16))",
      "(BitVec.shiftLeft (BitVec.and srcShift 0xff) 17))", 1)])
row("gl_dec_payload", "lean_chain",
    [(GLEAN, "def payload (aux : BitVec 32) : BitVec 32 := BitVec.and aux 0xff",
      "def payload (aux : BitVec 32) : BitVec 32 := BitVec.and aux 0xfe", 1)])
row("gl_dec_dst", "lean_chain",
    [(GLEAN, "def dstShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 8) 0xff",
      "def dstShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 9) 0xff", 1)])
row("gl_dec_src", "lean_chain",
    [(GLEAN, "def srcShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 16) 0xff",
      "def srcShift (aux : BitVec 32) : BitVec 32 :="
      " BitVec.and (aux >>> 17) 0xff", 1)])
row("gl_dec_dst_rename", "lean_chain",
    [(GLEAN, "def dstShift (aux : BitVec 32)", "def dstShiftX (aux : BitVec 32)",
      1)])
row("gl_genmark_repaint", "gen",
    [(GLEAN, "-- Generated by generate_x86_reg_lane_aux_spec.py from"
      " x86_reg_lane_aux_spec.json.",
      "-- produced by generate_x86_reg_lane_aux_spec.py from"
      " x86_reg_lane_aux_spec.json.", 1)])
row("gl_namespace_end", "lean_chain",
    [(GLEAN, "end KProgFormal.GeneratedX86RegLaneAux",
      "end KProgFormal.GeneratedX86RegLaneAuxX", 1)])

# --- hand module (lean_chain elaborates it; X86AluDecode references
# x86_reg_lane_aux_payload_roundtrip and X86SetccHandler references
# x86_reg_lane_aux_payload_roundtrip + _dst_roundtrip, so renames/repaints
# those consumers play break the chain; unconsumed-theorem edits only break
# the hand file's own proof chain) -------------------------------------------
row("hd_spec_concat_dst", "lean_chain",
    [(HAND, "  0#8 ++ srcShift.setWidth 8 ++ dstShift.setWidth 8"
      " ++ payloadByte.setWidth 8",
      "  0#8 ++ srcShift.setWidth 8 ++ dstShift.setWidth 9"
      " ++ payloadByte.setWidth 8", 1)])
row("hd_spec_concat_reorder", "lean_chain",
    [(HAND, "  0#8 ++ srcShift.setWidth 8 ++ dstShift.setWidth 8"
      " ++ payloadByte.setWidth 8",
      "  0#8 ++ srcShift.setWidth 8 ++ payloadByte.setWidth 8"
      " ++ dstShift.setWidth 8", 1)])
row("hd_pack_refines_payload_repaint", "lean_chain",
    [(HAND, "      x86RegLaneAuxSpec payloadByte dstShift srcShift := by",
      "      x86RegLaneAuxSpec payloadByte dstShift (srcShift +++ 1) := by",
      1)])
row("hd_payload_rt_rhs0", "lean_chain",
    [(HAND, "    GeneratedX86RegLaneAux.payload (pack payload dstShift"
      " srcShift) =\n      BitVec.and payload 0xff",
      "    GeneratedX86RegLaneAux.payload (pack payload dstShift"
      " srcShift) =\n      BitVec.and payload 0xfe", 1)])
row("hd_dst_rt_rhs0", "lean_chain",
    [(HAND, "    GeneratedX86RegLaneAux.dstShift (pack payload dstShift"
      " srcShift) =\n      BitVec.and dstShift 0xff",
      "    GeneratedX86RegLaneAux.dstShift (pack payload dstShift"
      " srcShift) =\n      BitVec.and dstShift 0xfe", 1)])
row("hd_src_rt_rhs0", "lean_chain",
    [(HAND, "    GeneratedX86RegLaneAux.srcShift (pack payload dstShift"
      " srcShift) =\n      BitVec.and srcShift 0xff",
      "    GeneratedX86RegLaneAux.srcShift (pack payload dstShift"
      " srcShift) =\n      BitVec.and srcShift 0xfe", 1)])
row("hd_ni_payload_arm", "lean_chain",
    [(HAND, "    GeneratedX86RegLaneAux.payload (pack payload dstShift"
      " srcShift) =\n        BitVec.and payload 0xff ∧",
      "    GeneratedX86RegLaneAux.payload (pack payload dstShift"
      " srcShift) =\n        BitVec.and payload 0xfe ∧", 1)])
row("hd_ni_refine_shape", "lean_chain",
    [(HAND, "  refine ⟨?_, ?_, ?_⟩", "  refine ⟨?_, ?_, ?_, ?_⟩", 1)])
row("hd_unfold_typed_dst", "lean_chain",
    [(HAND, "        BitVec.ofNat 32 (x86ByteShiftSpec dst) /\\",
      "        BitVec.ofNat 32 (x86ByteShiftSpec dst) + 1 /\\", 1)])
row("hd_typed_src_rhs", "lean_chain",
    [(HAND, "      GeneratedX86RegLaneAux.srcShift aux =\n"
      "        BitVec.ofNat 32 (x86ByteShiftSpec src) := by",
      "      GeneratedX86RegLaneAux.srcShift aux =\n"
      "        BitVec.ofNat 32 (x86ByteShiftSpec src) + 0 := by", 1)],
    equivalent=True)
row("hd_example_value", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_example : pack 2 8 0 = 0x0802 := by",
      "theorem x86_reg_lane_aux_example : pack 2 8 0 = 0x0803 := by", 1)])
row("hd_payload_rt_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_payload_roundtrip",
      "theorem x86_reg_lane_aux_payload_roundtripX", 1)])
row("hd_dst_rt_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_dst_roundtrip",
      "theorem x86_reg_lane_aux_dst_roundtripX", 1)])
row("hd_src_rt_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_src_roundtrip",
      "theorem x86_reg_lane_aux_src_roundtripX", 1)], equivalent=True)
row("hd_pack_refines_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_pack_refines",
      "theorem x86_reg_lane_aux_pack_refinesX", 1)], equivalent=True)
row("hd_non_interfering_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_fields_non_interfering",
      "theorem x86_reg_lane_aux_fields_non_interferingX", 1)],
    equivalent=True)
row("hd_typed_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_typed_lanes_roundtrip",
      "theorem x86_reg_lane_aux_typed_lanes_roundtripX", 1)],
    equivalent=True)
row("hd_example_rename", "lean_chain",
    [(HAND, "theorem x86_reg_lane_aux_example :",
      "theorem x86_reg_lane_aux_exampleX :", 1)], equivalent=True)
row("hd_specdef_rename", "lean_chain",
    [(HAND, "def x86RegLaneAuxSpec ", "def x86RegLaneAuxSpecX ", 1)])

# --- dedicated contract host -------------------------------------------------
row("host_payload_ret", "host",
    [(TEST_HOST, '\tcheck_field("payload", KPROG_X86_REG_LANE_AUX_PAYLOAD(aux),'
      '\n\t\t    payload & 0xffU, aux);',
      '\tcheck_field("payload", KPROG_X86_REG_LANE_AUX_PAYLOAD(aux),'
      '\n\t\t    payload ^ 1U, aux);', 1)])
row("host_dst_ret", "host",
    [(TEST_HOST, 'check_field("dst_shift", KPROG_X86_REG_LANE_AUX_DST_SHIFT'
      '(aux),\n\t\t    dst_shift & 0xffU, aux);',
      'check_field("dst_shift", KPROG_X86_REG_LANE_AUX_DST_SHIFT(aux),'
      '\n\t\t    dst_shift ^ 1U, aux);', 1)])
row("host_src_ret", "host",
    [(TEST_HOST, 'check_field("src_shift", KPROG_X86_REG_LANE_AUX_SRC_SHIFT'
      '(aux),\n\t\t    src_shift & 0xffU, aux);',
      'check_field("src_shift", KPROG_X86_REG_LANE_AUX_SRC_SHIFT(aux),'
      '\n\t\t    src_shift ^ 1U, aux);', 1)])
row("host_restate_payload", "host",
    [(TEST_HOST, 'check_field("payload>>0", (aux >> 0) & 0xffU,'
      ' payload & 0xffU, aux);',
      'check_field("payload>>0", (aux >> 0) & 0xffU, payload ^ 1U, aux);',
      1)])
row("host_restate_dst", "host",
    [(TEST_HOST, 'check_field("dst_shift>>8", (aux >> 8) & 0xffU,'
      ' dst_shift & 0xffU, aux);',
      'check_field("dst_shift>>8", (aux >> 8) & 0xffU, dst_shift ^ 1U,'
      ' aux);', 1)])
row("host_restate_src", "host",
    [(TEST_HOST, 'check_field("src_shift>>16", (aux >> 16) & 0xffU,'
      ' src_shift & 0xffU,',
      'check_field("src_shift>>16", (aux >> 16) & 0xffU, src_shift ^ 1U,',
      1)])
row("host_restate_shift_dir", "host",
    [(TEST_HOST, 'check_field("dst_shift>>8", (aux >> 8) & 0xffU,'
      ' dst_shift & 0xffU, aux);',
      'check_field("dst_shift>>8", (aux << 8) & 0xffU, dst_shift & 0xffU,'
      ' aux);', 1)])
row("host_packer_painted", "host",
    [(TEST_HOST,
      '\t__u32 aux = KPROG_X86_REG_LANE_AUX(payload, dst_shift, src_shift);',
      '\t__u32 aux = KPROG_X86_REG_LANE_AUX(payload, dst_shift,'
      ' src_shift ^ 1U);', 1)])
row("host_top_byte_pin_drop", "host",
    [(TEST_HOST, 'check_field("top_byte", (aux >> 24) & 0xffU, 0U, aux);',
      '/* top-byte pin dropped */', 1)], equivalent=True)
row("host_exhaustive_transpose", "host",
    [(TEST_HOST, 'check_packed(l, 0U, 0U, &cases);',
      'check_packed(0U, 0U, l, &cases);', 1)], equivalent=True)
row("host_case_count_paint", "host",
    [(TEST_HOST, 'printf("x86 register lane aux host cross-check: OK'
      ' (%lu cases)\\n",\n\t       cases);',
      'printf("x86 register lane aux host cross-check: OK (%lu cases)\\n",'
      '\n\t       cases - 1);', 1)], equivalent=True)
row("host_banner_paint", "host",
    [(TEST_HOST, 'printf("x86 register lane aux host cross-check: OK'
      ' (%lu cases)\\n",\n\t       cases);',
      'printf("x86 register lane aux host cross-check: OKX (%lu cases)\\n",'
      '\n\t       cases);', 1)], equivalent=True)
row("host_failure_gate", "host",
    [(TEST_HOST, 'if (failures) {',
      'if (0) {', 1)], equivalent=True)

# --- routed call sites in x86_sim_local_bpf.h (route detector compiles it
# through the ALU result route; sibling swaps are hidden where the driven
# aux lanes are always equal) -------------------------------------------------
L_IMM_PAYLOAD = ('\t\t__u8 __x86_l_alu =                                      \\\n'
                 '\t\t\tKPROG_X86_REG_LANE_AUX_PAYLOAD(__x86_l_aux);       \\\n'
                 '\t\t__u8 __x86_l_dst_shift =                                  \\\n'
                 '\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(__x86_l_aux);       \\\n'
                 '\t\t__u64 __x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \\\n'
                 '\t\t\t(DST), __x86_l_width, __x86_l_dst_shift);           \\\n'
                 '\t\t__u64 __x86_l_rhs = x86_store_imm_value((IMM),'
                 ' __x86_l_width);\\')
L_ALUREG_SRC = ('\t\t__u64 __x86_l_rhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(       \\\n'
                '\t\t\t(SRC), __x86_l_width,                              \\\n'
                '\t\t\tKPROG_X86_REG_LANE_AUX_SRC_SHIFT(__x86_l_aux));      \\')
L_CMP_DST = ('\t\telse                                                       \\\n'
             '\t\t\t__x86_l_lhs = X86_SIM_L_READ_REG_WIDTH_SHIFT(      \\\n'
             '\t\t\t\t(DST), __x86_l_width,                      \\\n'
             '\t\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(          \\\n'
             '\t\t\t\t\t__x86_l_aux));                     \\')
L_CMP_SRC = ('\t\t\t\t\t\tKPROG_X86_REG_LANE_AUX_SRC_SHIFT(\\\n'
             '\t\t\t\t\t\t\t__x86_l_aux));    \\')
L_MOVIMM_DST = '\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));              \\\n'
L_SETCC_SHIFT = ('KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX);              \\\n'
                 '\t\t__u8 __x86_l_sc_lane = KPROG_X86_SETCC_LANE(                \\\n'
                 '\t\t\t__x86_l_sc_shift);                                   \\')
L_SETCC_PAYLOAD = ('KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX))),                     \\\n'
                   '\t\t\tX86_WIDTH_8,')
L_MOVREG_NARROW = ('\t\t\t__u64 __x86_l_value = X86_SIM_L_READ_REG_WIDTH_SHIFT(\\\n'
                   '\t\t\t\t(SRC), __x86_l_width,                         \\\n'
                   '\t\t\t\tKPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));       \\\n'
                   '\t\t\tX86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),'
                   ' __x86_l_value,\\\n'
                   '\t\t\t\t__x86_l_width,                                \\\n'
                   '\t\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));        \\\n')
L_DISPMOV_IMM = ('\t\t} else if (KPROG_X86_DISP_MOV_IMM_HANDLED(OP)) {'
                 '          \\\n'
                 '\t\t\tX86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), (IMM),         \\\n'
                 '\t\t\t\t__x86_l_width,                                \\\n'
                 '\t\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));        \\\n')
L_DISPMOV_NARROW = ('\t\t\t\t__u64 __x86_l_value =                    \\\n'
                    '\t\t\t\t\tX86_SIM_L_READ_REG_WIDTH_SHIFT(   \\\n'
                    '\t\t\t\t\t\t(SRC), __x86_l_width,        \\\n'
                    '\t\t\t\t\t\tKPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));\\\n'
                    '\t\t\t\tX86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST),   \\\n'
                    '\t\t\t\t\t__x86_l_value, __x86_l_width,      \\\n'
                    '\t\t\t\t\tKPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));\\\n')

row("route_alu_imm_payload", "route",
    [(SIM_LBPF, L_IMM_PAYLOAD,
      L_IMM_PAYLOAD.replace("KPROG_X86_REG_LANE_AUX_PAYLOAD(__x86_l_aux);",
                            "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(__x86_l_aux);"),
      1)])
row("route_alu_reg_src_lane_zero", "route",
    [(SIM_LBPF, L_ALUREG_SRC,
      L_ALUREG_SRC.replace("KPROG_X86_REG_LANE_AUX_SRC_SHIFT(__x86_l_aux));",
                           "0U);"), 1)])
row("route_cmp_memreg_dst_lane", "route",
    [(SIM_LBPF, L_CMP_DST,
      L_CMP_DST.replace("KPROG_X86_REG_LANE_AUX_DST_SHIFT(          \\",
                        "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(          \\"), 1)])
row("route_cmp_mnemonic4_src_lane", "route",
    [(SIM_LBPF, L_CMP_SRC,
      L_CMP_SRC.replace("KPROG_X86_REG_LANE_AUX_SRC_SHIFT(\\",
                        "KPROG_X86_REG_LANE_AUX_DST_SHIFT(\\"), 1)])
row("route_mov_imm_aux_decoder", "route",
    [(SIM_LBPF, L_MOVIMM_DST + "\t} while (0)",
      L_MOVIMM_DST.replace("KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));",
                           "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));")
      + "\t} while (0)", 1)], equivalent=True)
row("route_mov_reg_narrow_lanes", "route",
    [(SIM_LBPF, L_MOVREG_NARROW,
      L_MOVREG_NARROW.replace("KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));",
                              "KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));"), 1)],
    equivalent=True)
row("route_setcc_step_lane", "route",
    [(SIM_LBPF, L_SETCC_SHIFT,
      L_SETCC_SHIFT.replace("KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX);",
                            "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX);"), 1)],
    equivalent=True)
row("route_setcc_payload_pin", "route",
    [(SIM_LBPF, L_SETCC_PAYLOAD,
      L_SETCC_PAYLOAD.replace("KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX))),",
                              "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX))),"), 1)],
    equivalent=True)
row("route_dispmov_imm_lane", "route",
    [(SIM_LBPF, L_DISPMOV_IMM,
      L_DISPMOV_IMM.replace("KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));",
                            "KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));"), 1)],
    equivalent=True)
row("route_dispmov_reg_lanes", "route",
    [(SIM_LBPF, L_DISPMOV_NARROW,
      L_DISPMOV_NARROW.replace("KPROG_X86_REG_LANE_AUX_SRC_SHIFT(AUX));\\",
                               "KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX));\\"),
      1)], equivalent=True)

# --- simulator header static-assert lane pins (compiled through every
# host/route detector; repainted value breaks compilation immediately) --------
row("sim_assert_payload_value", "host",
    [(SIM_HEADER, "KPROG_X86_REG_LANE_AUX(0xabU, 8U, 0U)) == 0xabU,",
      "KPROG_X86_REG_LANE_AUX(0xabU, 8U, 0U)) == 0xacU,", 1)])
row("sim_assert_dst_value", "host",
    [(SIM_HEADER, "KPROG_X86_REG_LANE_AUX(0U, 8U, 0U)) == 8U,",
      "KPROG_X86_REG_LANE_AUX(0U, 8U, 0U)) == 9U,", 1)])
row("sim_assert_src_value", "host",
    [(SIM_HEADER, "KPROG_X86_REG_LANE_AUX(0U, 0U, 8U)) == 8U,",
      "KPROG_X86_REG_LANE_AUX(0U, 0U, 8U)) == 9U,", 1)])


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
