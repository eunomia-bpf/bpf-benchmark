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
SHF_EXECINSTR = 0x4
BPF_CALL_OPCODE = 0x85
BPF_EXIT_OPCODE = 0x95


@dataclass
class PostprocessSummary:
    input_path: str
    output_path: str
    output_bin_path: str | None
    helper_call_rewrites: int
    rewritten_helpers: list[dict[str, Any]]
    removed_sections: list[str]
    executable_sections: list[dict[str, Any]]

    def to_dict(self) -> dict[str, Any]:
        return {
            "input_path": self.input_path,
            "output_path": self.output_path,
            "output_bin_path": self.output_bin_path,
            "helper_call_rewrites": self.helper_call_rewrites,
            "rewritten_helpers": self.rewritten_helpers,
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


def _patch_helper_calls(input_path: Path, output_path: Path) -> PostprocessSummary:
    raw = bytearray(input_path.read_bytes())
    rewritten_helpers: list[dict[str, Any]] = []
    removed_sections: list[str] = []
    executable_sections: list[dict[str, Any]] = []

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

        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue

            target = elf.get_section(section["sh_info"])
            if target["sh_type"] != "SHT_PROGBITS" or not (int(target["sh_flags"]) & SHF_EXECINSTR):
                continue

            symtab = elf.get_section(section["sh_link"])
            helper_reloc_count = 0
            other_reloc_count = 0

            for relocation in section.iter_relocations():
                symbol = symtab.get_symbol(relocation["r_info_sym"])
                match = HELPER_SYMBOL_RE.fullmatch(symbol.name)
                if not match:
                    other_reloc_count += 1
                    continue

                helper_id = int(match.group(1))
                helper_reloc_count += 1
                insn_offset = int(relocation["r_offset"])
                if insn_offset % 8 != 0:
                    raise RuntimeError(
                        f"{input_path}: helper relocation {symbol.name} has non-insn offset {insn_offset}"
                    )
                if insn_offset + 8 > int(target["sh_size"]):
                    raise RuntimeError(
                        f"{input_path}: helper relocation {symbol.name} points past {target.name}"
                    )

                file_offset = int(target["sh_offset"]) + insn_offset
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

            if helper_reloc_count > 0 and other_reloc_count == 0:
                removed_sections.append(section.name)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_bytes(raw)
    return PostprocessSummary(
        input_path=str(input_path),
        output_path=str(output_path),
        output_bin_path=None,
        helper_call_rewrites=len(rewritten_helpers),
        rewritten_helpers=rewritten_helpers,
        removed_sections=removed_sections,
        executable_sections=executable_sections,
    )


def postprocess_roundtrip_object(
    input_path: Path,
    output_path: Path,
    *,
    output_bin_path: Path | None = None,
) -> dict[str, Any]:
    summary = _patch_helper_calls(input_path, output_path)

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
        run_command(
            [
                require_tool("llvm-objcopy"),
                "--dump-section",
                f".text={output_bin_path}",
                str(output_path),
            ]
        )
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
