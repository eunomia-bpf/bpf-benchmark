#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


HELPER_SYMBOL_RE = re.compile(r"^_bpf_helper_ext_(\d+)$")
PSEUDO_MAP_FD_SYMBOL_RE = re.compile(r"^__llvmbpf_pseudo_map_fd_([0-9a-fA-F]{8})$")
PSEUDO_MAP_VALUE_SYMBOL_RE = re.compile(
    r"^__llvmbpf_pseudo_map_value_fd_([0-9a-fA-F]{8})_off_([0-9a-fA-F]{8})$"
)
PSEUDO_CALL_SYMBOL_RE = re.compile(r"^__llvmbpf_pseudo_call_pc_([0-9a-fA-F]{8})$")
SHF_EXECINSTR = 0x4
BPF_LD_IMM64_OPCODE = 0x18
BPF_CALL_OPCODE = 0x85
BPF_EXIT_OPCODE = 0x95
BPF_PSEUDO_MAP_FD = 1
BPF_PSEUDO_MAP_VALUE = 2
BPF_PSEUDO_CALL = 1


@dataclass
class PostprocessSummary:
    input_path: str
    output_path: str
    output_bin_path: str | None
    helper_call_rewrites: int
    rewritten_helpers: list[dict[str, Any]]
    pseudo_call_rewrites: int
    rewritten_pseudo_calls: list[dict[str, Any]]
    pseudo_map_ld_rewrites: int
    rewritten_pseudo_map_lds: list[dict[str, Any]]
    precision_compare_rewrites: int
    rewritten_precision_compares: list[dict[str, Any]]
    appended_original_subprog_insns: int
    removed_sections: list[str]
    executable_sections: list[dict[str, Any]]

    def to_dict(self) -> dict[str, Any]:
        return {
            "input_path": self.input_path,
            "output_path": self.output_path,
            "output_bin_path": self.output_bin_path,
            "helper_call_rewrites": self.helper_call_rewrites,
            "rewritten_helpers": self.rewritten_helpers,
            "pseudo_call_rewrites": self.pseudo_call_rewrites,
            "rewritten_pseudo_calls": self.rewritten_pseudo_calls,
            "pseudo_map_ld_rewrites": self.pseudo_map_ld_rewrites,
            "rewritten_pseudo_map_lds": self.rewritten_pseudo_map_lds,
            "precision_compare_rewrites": self.precision_compare_rewrites,
            "rewritten_precision_compares": self.rewritten_precision_compares,
            "appended_original_subprog_insns": self.appended_original_subprog_insns,
            "removed_sections": self.removed_sections,
            "executable_sections": self.executable_sections,
        }


def require_tool(name: str) -> str:
    path = shutil.which(name)
    if not path:
        raise RuntimeError(f"required tool not found in PATH: {name}")
    return path


def run_command(argv: list[str]) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        argv,
        text=True,
        capture_output=True,
        check=False,
    )
    if completed.returncode != 0:
        raise RuntimeError(
            f"command failed rc={completed.returncode}: {' '.join(argv)}\n"
            f"stdout:\n{completed.stdout}\n"
            f"stderr:\n{completed.stderr}"
        )
    return completed


def _decode_i32_bits(hex_text: str) -> int:
    return int(hex_text, 16) & 0xFFFFFFFF


def _decode_insn(raw: bytearray, file_offset: int) -> tuple[int, int, int, int]:
    return (
        raw[file_offset],
        raw[file_offset + 1],
        int.from_bytes(raw[file_offset + 2 : file_offset + 4], byteorder="little", signed=True),
        int.from_bytes(raw[file_offset + 4 : file_offset + 8], byteorder="little", signed=True),
    )


def _writes_reg(opcode: int, regs: int, reg: int) -> bool:
    insn_class = opcode & 0x07
    dst_reg = regs & 0x0F
    if insn_class in {0x00, 0x01, 0x04, 0x07}:
        return dst_reg == reg
    if insn_class in {0x05, 0x06} and opcode == BPF_CALL_OPCODE:
        return reg == 0
    return False


def _rewrite_precision_compare_patterns(
    raw: bytearray,
    *,
    target_name: str,
    section_offset: int,
    section_size: int,
) -> list[dict[str, Any]]:
    rewritten: list[dict[str, Any]] = []
    insn_count = section_size // 8

    for insn_index in range(insn_count - 4):
        file_offset = section_offset + insn_index * 8
        op0, regs0, off0, imm0 = _decode_insn(raw, file_offset)
        op1, regs1, off1, imm1 = _decode_insn(raw, file_offset + 8)

        dst0 = regs0 & 0x0F
        src0 = (regs0 >> 4) & 0x0F
        dst1 = regs1 & 0x0F
        src1 = (regs1 >> 4) & 0x0F

        if op0 != 0xBC or off0 != 0 or imm0 != 0:
            continue
        if op1 != 0x54 or off1 != 0 or imm1 != 0xFFFF:
            continue
        if dst0 != dst1:
            continue
        if src1 != 0:
            continue

        compare_limit = min(insn_count - 1, insn_index + 6)
        for compare_index in range(insn_index + 2, compare_limit):
            compare_offset = section_offset + compare_index * 8
            op2, regs2, off2, imm2 = _decode_insn(raw, compare_offset)
            op3, regs3, off3, imm3 = _decode_insn(raw, compare_offset + 8)

            dst2 = regs2 & 0x0F
            src2 = (regs2 >> 4) & 0x0F
            dst3 = regs3 & 0x0F
            src3 = (regs3 >> 4) & 0x0F

            if (op2 & 0x07) != 0x06 or src2 != 0:
                continue
            if op3 != 0x57 or off3 != 0 or imm3 != 0xFFFF:
                continue
            if dst2 != dst0:
                continue
            if src0 != dst3:
                continue
            if src3 != 0:
                continue

            blocked = False
            for middle_index in range(insn_index + 2, compare_index):
                middle_offset = section_offset + middle_index * 8
                middle_op, middle_regs, _, _ = _decode_insn(raw, middle_offset)
                if _writes_reg(middle_op, middle_regs, dst0) or _writes_reg(middle_op, middle_regs, src0):
                    blocked = True
                    break
            if blocked:
                continue

            raw[compare_offset + 1] = src0 | (src2 << 4)
            rewritten.append(
                {
                    "section": target_name,
                    "insn_index": compare_index,
                    "old_compare_reg": dst2,
                    "new_compare_reg": src0,
                    "compare_opcode": f"0x{op2:02x}",
                    "compare_imm": imm2,
                    "compare_off": off2,
                }
            )
            break

    return rewritten


def _collect_original_subprog_region(original_bin_path: Path) -> tuple[int, bytes]:
    original = original_bin_path.read_bytes()
    if len(original) % 8 != 0:
        raise RuntimeError(f"{original_bin_path}: bytecode length {len(original)} is not 8-byte aligned")

    targets: list[int] = []
    insn_count = len(original) // 8
    for insn_index in range(insn_count):
        file_offset = insn_index * 8
        opcode = original[file_offset]
        regs = original[file_offset + 1]
        src_reg = (regs >> 4) & 0x0F
        imm = int.from_bytes(original[file_offset + 4 : file_offset + 8], byteorder="little", signed=True)
        if opcode != BPF_CALL_OPCODE or src_reg != BPF_PSEUDO_CALL:
            continue
        target_pc = insn_index + 1 + imm
        if target_pc < 0 or target_pc >= insn_count:
            raise RuntimeError(
                f"{original_bin_path}: pseudo-call at insn {insn_index} targets out-of-range pc {target_pc}"
            )
        targets.append(target_pc)

    if not targets:
        raise RuntimeError(f"{original_bin_path}: no original pseudo-call targets found")

    subprog_base_pc = min(targets)
    return subprog_base_pc, original[subprog_base_pc * 8 :]


def _patch_helper_calls(input_path: Path, output_path: Path, original_bin_path: Path | None) -> tuple[PostprocessSummary, bytes | None]:
    raw = bytearray(input_path.read_bytes())
    rewritten_helpers: list[dict[str, Any]] = []
    rewritten_pseudo_calls: list[dict[str, Any]] = []
    rewritten_pseudo_map_lds: list[dict[str, Any]] = []
    rewritten_precision_compares: list[dict[str, Any]] = []
    removed_sections: list[str] = []
    executable_sections: list[dict[str, Any]] = []
    text_section_range: tuple[int, int] | None = None

    with input_path.open("rb") as f:
        elf = ELFFile(f)
        for section in elf.iter_sections():
            flags = int(section["sh_flags"])
            if section["sh_type"] == "SHT_PROGBITS" and flags & SHF_EXECINSTR:
                data = section.data()
                last_opcode = data[-8] if len(data) >= 8 else None
                executable_sections.append(
                    {
                        "name": section.name,
                        "size_bytes": len(data),
                        "ends_with_exit_or_jmp": bool(
                            last_opcode is not None and last_opcode in {0x05, BPF_EXIT_OPCODE}
                        ),
                        "last_opcode": None if last_opcode is None else f"0x{last_opcode:02x}",
                    }
                )
                rewritten_precision_compares.extend(
                    _rewrite_precision_compare_patterns(
                        raw,
                        target_name=section.name,
                        section_offset=int(section["sh_offset"]),
                        section_size=int(section["sh_size"]),
                    )
                )
                if section.name == ".text":
                    start = int(section["sh_offset"])
                    end = start + int(section["sh_size"])
                    text_section_range = (start, end)

        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue

            target = elf.get_section(section["sh_info"])
            if target["sh_type"] != "SHT_PROGBITS" or not (int(target["sh_flags"]) & SHF_EXECINSTR):
                continue

            symtab = elf.get_section(section["sh_link"])
            helper_reloc_count = 0
            pseudo_call_reloc_count = 0
            pseudo_map_reloc_count = 0
            other_reloc_count = 0

            for relocation in section.iter_relocations():
                symbol = symtab.get_symbol(relocation["r_info_sym"])
                insn_offset = int(relocation["r_offset"])
                if insn_offset % 8 != 0:
                    raise RuntimeError(
                        f"{input_path}: relocation {symbol.name} has non-insn offset {insn_offset}"
                    )
                file_offset = int(target["sh_offset"]) + insn_offset

                helper_match = HELPER_SYMBOL_RE.fullmatch(symbol.name)
                if helper_match:
                    helper_id = int(helper_match.group(1))
                    helper_reloc_count += 1
                    if insn_offset + 8 > int(target["sh_size"]):
                        raise RuntimeError(
                            f"{input_path}: helper relocation {symbol.name} points past {target.name}"
                        )

                    opcode = raw[file_offset]
                    regs = raw[file_offset + 1]
                    if opcode != BPF_CALL_OPCODE:
                        raise RuntimeError(
                            f"{input_path}: helper relocation {symbol.name} at {target.name}+0x{insn_offset:x} "
                            f"does not target a BPF_CALL insn (opcode=0x{opcode:02x})"
                        )

                    old_src = (regs >> 4) & 0xF
                    raw[file_offset + 1] = regs & 0x0F
                    raw[file_offset + 4 : file_offset + 8] = helper_id.to_bytes(
                        4, byteorder="little", signed=True
                    )
                    rewritten_helpers.append(
                        {
                            "section": target.name,
                            "insn_index": insn_offset // 8,
                            "symbol": symbol.name,
                            "helper_id": helper_id,
                            "old_src_reg": old_src,
                        }
                    )
                    continue

                pseudo_call_match = PSEUDO_CALL_SYMBOL_RE.fullmatch(symbol.name)
                if pseudo_call_match:
                    pseudo_call_reloc_count += 1
                    if insn_offset + 8 > int(target["sh_size"]):
                        raise RuntimeError(
                            f"{input_path}: pseudo-call relocation {symbol.name} points past {target.name}"
                        )

                    opcode = raw[file_offset]
                    regs = raw[file_offset + 1]
                    if opcode != BPF_CALL_OPCODE:
                        raise RuntimeError(
                            f"{input_path}: pseudo-call relocation {symbol.name} at {target.name}+0x{insn_offset:x} "
                            f"does not target a BPF_CALL insn (opcode=0x{opcode:02x})"
                        )

                    old_src = (regs >> 4) & 0xF
                    target_pc = _decode_i32_bits(pseudo_call_match.group(1))
                    rewritten_pseudo_calls.append(
                        {
                            "section": target.name,
                            "insn_index": insn_offset // 8,
                            "symbol": symbol.name,
                            "target_pc": target_pc,
                            "old_src_reg": old_src,
                        }
                    )
                    continue

                pseudo_map_fd_match = PSEUDO_MAP_FD_SYMBOL_RE.fullmatch(symbol.name)
                pseudo_map_value_match = PSEUDO_MAP_VALUE_SYMBOL_RE.fullmatch(symbol.name)
                if not pseudo_map_fd_match and not pseudo_map_value_match:
                    other_reloc_count += 1
                    continue

                pseudo_map_reloc_count += 1
                if insn_offset + 16 > int(target["sh_size"]):
                    raise RuntimeError(
                        f"{input_path}: pseudo-map relocation {symbol.name} points past {target.name}"
                    )
                opcode = raw[file_offset]
                regs = raw[file_offset + 1]
                if opcode != BPF_LD_IMM64_OPCODE:
                    raise RuntimeError(
                        f"{input_path}: pseudo-map relocation {symbol.name} at {target.name}+0x{insn_offset:x} "
                        f"does not target a BPF_LD_IMM64 insn (opcode=0x{opcode:02x})"
                    )

                dst_reg = regs & 0x0F
                old_src = (regs >> 4) & 0xF
                if pseudo_map_fd_match:
                    pseudo_src = BPF_PSEUDO_MAP_FD
                    map_fd_bits = _decode_i32_bits(pseudo_map_fd_match.group(1))
                    offset_bits = 0
                    kind = "map_fd"
                else:
                    pseudo_src = BPF_PSEUDO_MAP_VALUE
                    assert pseudo_map_value_match is not None
                    map_fd_bits = _decode_i32_bits(pseudo_map_value_match.group(1))
                    offset_bits = _decode_i32_bits(pseudo_map_value_match.group(2))
                    kind = "map_value"

                raw[file_offset + 1] = dst_reg | (pseudo_src << 4)
                raw[file_offset + 4 : file_offset + 8] = map_fd_bits.to_bytes(
                    4, byteorder="little", signed=False
                )
                raw[file_offset + 12 : file_offset + 16] = offset_bits.to_bytes(
                    4, byteorder="little", signed=False
                )
                rewritten_pseudo_map_lds.append(
                    {
                        "section": target.name,
                        "insn_index": insn_offset // 8,
                        "symbol": symbol.name,
                        "kind": kind,
                        "map_fd_bits": f"0x{map_fd_bits:08x}",
                        "offset_bits": f"0x{offset_bits:08x}",
                        "old_src_reg": old_src,
                        "new_src_reg": pseudo_src,
                        }
                    )

            if helper_reloc_count + pseudo_map_reloc_count > 0 and pseudo_call_reloc_count == 0 and other_reloc_count == 0:
                removed_sections.append(section.name)

    appended_original_subprog_insns = 0
    output_bin_bytes: bytes | None = None
    if rewritten_pseudo_calls:
        if text_section_range is None:
            raise RuntimeError(f"{input_path}: pseudo-call rewrite requires a .text executable section")
        if original_bin_path is None:
            raise RuntimeError(f"{input_path}: pseudo-call rewrite requires original_bin_path")

        subprog_base_pc, appended_original_subprog_bytes = _collect_original_subprog_region(original_bin_path)
        appended_original_subprog_insns = len(appended_original_subprog_bytes) // 8
        start, end = text_section_range
        main_text = bytearray(raw[start:end])
        main_insn_count = len(main_text) // 8

        for rewrite in rewritten_pseudo_calls:
            insn_index = int(rewrite["insn_index"])
            target_pc = int(rewrite["target_pc"])
            target_final_pc = main_insn_count + (target_pc - subprog_base_pc)
            relative_imm = target_final_pc - insn_index - 1
            file_offset = insn_index * 8
            regs = main_text[file_offset + 1]
            main_text[file_offset + 1] = (regs & 0x0F) | (BPF_PSEUDO_CALL << 4)
            main_text[file_offset + 4 : file_offset + 8] = relative_imm.to_bytes(
                4, byteorder="little", signed=True
            )
            rewrite["new_src_reg"] = BPF_PSEUDO_CALL
            rewrite["new_imm"] = relative_imm
            rewrite["subprog_base_pc"] = subprog_base_pc
            rewrite["final_target_pc"] = target_final_pc

        output_bin_bytes = bytes(main_text) + appended_original_subprog_bytes

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_bytes(raw)
    return (
        PostprocessSummary(
            input_path=str(input_path),
            output_path=str(output_path),
            output_bin_path=None,
            helper_call_rewrites=len(rewritten_helpers),
            rewritten_helpers=rewritten_helpers,
            pseudo_call_rewrites=len(rewritten_pseudo_calls),
            rewritten_pseudo_calls=rewritten_pseudo_calls,
            pseudo_map_ld_rewrites=len(rewritten_pseudo_map_lds),
            rewritten_pseudo_map_lds=rewritten_pseudo_map_lds,
            precision_compare_rewrites=len(rewritten_precision_compares),
            rewritten_precision_compares=rewritten_precision_compares,
            appended_original_subprog_insns=appended_original_subprog_insns,
            removed_sections=removed_sections,
            executable_sections=executable_sections,
        ),
        output_bin_bytes,
    )


def postprocess_roundtrip_object(
    input_path: Path,
    output_path: Path,
    *,
    output_bin_path: Path | None = None,
    original_bin_path: Path | None = None,
) -> dict[str, Any]:
    summary, output_bin_bytes = _patch_helper_calls(input_path, output_path, original_bin_path)

    if summary.removed_sections:
        tmp_path = output_path.with_suffix(output_path.suffix + ".tmp")
        tmp_path.write_bytes(output_path.read_bytes())
        remove_cmd = [require_tool("llvm-objcopy")]
        for section_name in summary.removed_sections:
            remove_cmd.append(f"--remove-section={section_name}")
        remove_cmd.extend([str(tmp_path), str(output_path)])
        run_command(remove_cmd)
        tmp_path.unlink()

    if output_bin_path is not None:
        output_bin_path.parent.mkdir(parents=True, exist_ok=True)
        if output_bin_bytes is None:
            run_command(
                [
                    require_tool("llvm-objcopy"),
                    "--dump-section",
                    f".text={output_bin_path}",
                    str(output_path),
                ]
            )
        else:
            output_bin_path.write_bytes(output_bin_bytes)
        summary.output_bin_path = str(output_bin_path)

    return summary.to_dict()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Patch llvmbpf round-trip BPF ELF objects for verifier-friendly helper calls"
    )
    parser.add_argument("--input", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--output-bin", type=Path, default=None)
    parser.add_argument("--summary-json", type=Path, default=None)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    summary = postprocess_roundtrip_object(
        args.input.resolve(),
        args.output.resolve(),
        output_bin_path=None if args.output_bin is None else args.output_bin.resolve(),
    )
    rendered = json.dumps(summary, indent=2, sort_keys=False)
    print(rendered)
    if args.summary_json is not None:
        args.summary_json.parent.mkdir(parents=True, exist_ok=True)
        args.summary_json.write_text(rendered + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
