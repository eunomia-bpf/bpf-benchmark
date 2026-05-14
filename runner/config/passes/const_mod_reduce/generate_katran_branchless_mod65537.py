#!/usr/bin/env python3
"""Generate the Katran branchless mod65537 probe artifact from raw bpf_insn[].

This is a host-side helper for the benchmark-only artifact loader. It does not
call bpfopt or any BPF syscall.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


EXPECTED_INPUT_SHA = "1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e"
EXPECTED_OUTPUT_SHA = "1929357b97f00f4a8ed653fad7c7ed84a0ee810adcb9a325b8db6b06f9a985e5"


def insn_unpack(raw: bytes | bytearray, pc: int) -> tuple[int, int, int, int]:
    return struct.unpack_from("<BBhi", raw, pc * 8)


def insn_pack(code: int, regs: int, off: int, imm: int) -> bytes:
    return struct.pack("<BBhi", code, regs, off, imm)


def regs(dst: int, src: int = 0) -> int:
    return (dst & 0x0F) | ((src & 0x0F) << 4)


def alu64_imm(op: int, dst: int, imm: int) -> bytes:
    return insn_pack(0x07 | op, regs(dst), 0, imm)


def alu64_reg(op: int, dst: int, src: int) -> bytes:
    return insn_pack(0x0F | op, regs(dst, src), 0, 0)


def mov64_reg(dst: int, src: int) -> bytes:
    return alu64_reg(0xB0, dst, src)


REPLACEMENT = b"".join(
    [
        mov64_reg(1, 0),          # r1 = r0
        alu64_imm(0x70, 1, 16),   # r1 >>= 16
        alu64_imm(0x50, 1, 65535),# r1 &= 65535
        alu64_imm(0x50, 0, 65535),# r0 &= 65535
        alu64_reg(0x10, 0, 1),    # r0 -= r1
        mov64_reg(1, 0),          # r1 = r0
        alu64_imm(0x70, 1, 63),   # r1 >>= 63
        alu64_reg(0x00, 0, 1),    # r0 += r1
        alu64_imm(0x60, 1, 16),   # r1 <<= 16
        alu64_reg(0x00, 0, 1),    # r0 += r1
    ]
)


def is_katran_site(raw: bytes | bytearray, pc: int, insn_count: int) -> bool:
    if pc + 6 >= insn_count:
        return False
    return (
        insn_unpack(raw, pc) == (0x67, 0x00, 0, 32)
        and insn_unpack(raw, pc + 1) == (0x77, 0x00, 0, 32)
        and insn_unpack(raw, pc + 2) == (0x97, 0x00, 0, 65537)
        and insn_unpack(raw, pc + 3)[0:2] == (0x79, 0xA1)
        and insn_unpack(raw, pc + 4) == (0x61, 0x11, 4, 0)
        and insn_unpack(raw, pc + 5) == (0x27, 0x01, 0, 65537)
        and insn_unpack(raw, pc + 6) == (0x0F, 0x01, 0, 0)
    )


def find_sites(raw: bytes | bytearray) -> list[int]:
    insn_count = len(raw) // 8
    sites: list[int] = []
    pc = 0
    while pc < insn_count:
        if is_katran_site(raw, pc, insn_count):
            sites.append(pc)
            pc += 7
        else:
            pc += 1
    return sites


def patch_relative_references(raw: bytes, new: bytearray, copied_old_to_new: dict[int, int], sites: list[int]) -> None:
    def old_to_new(old_pc: int) -> int | None:
        extra = 0
        for site in sites:
            if old_pc < site:
                break
            if old_pc == site:
                return old_pc + extra
            if old_pc < site + 3:
                return None
            extra += 7
        return old_pc + extra

    def removed_pc(old_pc: int) -> bool:
        return any(site <= old_pc < site + 3 for site in sites)

    def patch_insn(new_pc: int, code: int, regs_byte: int, off: int, imm: int) -> None:
        struct.pack_into("<BBhi", new, new_pc * 8, code, regs_byte, off, imm)

    for old_pc, new_pc in copied_old_to_new.items():
        if removed_pc(old_pc):
            continue

        code, regs_byte, off, imm = insn_unpack(raw, old_pc)
        cls = code & 0x07
        op = code & 0xF0
        src = (regs_byte >> 4) & 0x0F

        if cls in (0x05, 0x06) and code not in (0x85, 0x95):
            if cls == 0x06 and op == 0x00:
                old_target = old_pc + 1 + imm
                new_target = old_to_new(old_target)
                if new_target is None:
                    raise RuntimeError(f"branch at pc {old_pc} targets removed interior pc {old_target}")
                new_delta = new_target - new_pc - 1
                if not -(2**31) <= new_delta < 2**31:
                    raise RuntimeError(f"JA32 delta overflow at pc {old_pc}: {new_delta}")
                patch_insn(new_pc, code, regs_byte, off, new_delta)
            else:
                old_target = old_pc + 1 + off
                new_target = old_to_new(old_target)
                if new_target is None:
                    raise RuntimeError(f"branch at pc {old_pc} targets removed interior pc {old_target}")
                new_delta = new_target - new_pc - 1
                if not -(2**15) <= new_delta < 2**15:
                    raise RuntimeError(f"branch delta overflow at pc {old_pc}: {new_delta}")
                patch_insn(new_pc, code, regs_byte, new_delta, imm)
        elif code == 0x85 and src == 1:
            old_target = old_pc + 1 + imm
            new_target = old_to_new(old_target)
            if new_target is None:
                raise RuntimeError(f"pseudo-call at pc {old_pc} targets removed interior pc {old_target}")
            new_delta = new_target - new_pc - 1
            if not -(2**31) <= new_delta < 2**31:
                raise RuntimeError(f"pseudo-call delta overflow at pc {old_pc}: {new_delta}")
            patch_insn(new_pc, code, regs_byte, off, new_delta)
        elif code == 0x18 and src == 4:
            old_target = old_pc + 1 + imm
            new_target = old_to_new(old_target)
            if new_target is None:
                raise RuntimeError(f"pseudo-func ldimm64 at pc {old_pc} targets removed interior pc {old_target}")
            new_delta = new_target - new_pc - 1
            if not -(2**31) <= new_delta < 2**31:
                raise RuntimeError(f"pseudo-func delta overflow at pc {old_pc}: {new_delta}")
            patch_insn(new_pc, code, regs_byte, off, new_delta)


def generate(raw: bytes) -> tuple[bytes, dict[str, object]]:
    if len(raw) % 8 != 0:
        raise RuntimeError(f"input byte length {len(raw)} is not a multiple of 8")

    sites = find_sites(raw)
    site_set = set(sites)
    insn_count = len(raw) // 8
    new = bytearray()
    copied_old_to_new: dict[int, int] = {}

    pc = 0
    while pc < insn_count:
        if pc in site_set:
            copied_old_to_new[pc] = len(new) // 8
            new.extend(REPLACEMENT)
            pc += 3
            continue
        copied_old_to_new[pc] = len(new) // 8
        new.extend(raw[pc * 8 : (pc + 1) * 8])
        pc += 1

    patch_relative_references(raw, new, copied_old_to_new, sites)

    report = {
        "pass": "const_mod_reduce",
        "sites_applied": len(sites),
        "sites_matched": len(sites),
        "sites_skipped": 0,
        "skip_reasons": {},
        "diagnostics": [f"host-generated branchless mod65537 patch at raw PC {pc}" for pc in sites],
        "insn_count_before": insn_count,
        "insn_count_after": len(new) // 8,
        "insn_delta": (len(new) // 8) - insn_count,
    }
    return bytes(new), report


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="raw input bpf_insn[] testbin")
    parser.add_argument("output", type=Path, help="raw output bpf_insn[] artifact")
    parser.add_argument("--report", type=Path, help="optional JSON report path")
    parser.add_argument("--expected-input-sha", default=EXPECTED_INPUT_SHA)
    parser.add_argument("--expected-output-sha", default=EXPECTED_OUTPUT_SHA)
    args = parser.parse_args()

    raw = args.input.read_bytes()
    input_sha = sha256(raw)
    if args.expected_input_sha and input_sha != args.expected_input_sha:
        raise RuntimeError(f"input sha256 mismatch: got {input_sha}, expected {args.expected_input_sha}")

    output, report = generate(raw)
    output_sha = sha256(output)
    if args.expected_output_sha and output_sha != args.expected_output_sha:
        raise RuntimeError(f"output sha256 mismatch: got {output_sha}, expected {args.expected_output_sha}")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(output)
    if args.report is not None:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(json.dumps(report, indent=2) + "\n")


if __name__ == "__main__":
    main()
