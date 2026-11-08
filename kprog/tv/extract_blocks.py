#!/usr/bin/env python3
"""Expose exact ELF BPF entry bytes to Lean; never certify from disassembly."""
from pathlib import Path
import argparse
import struct

from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser()
parser.add_argument("object", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
with args.object.open("rb") as stream:
    elf = ELFFile(stream)
    if elf["e_machine"] != "EM_BPF" or not elf.little_endian:
        raise SystemExit("expected little-endian BPF ELF")
    symbols = elf.get_section_by_name(".symtab")
    rows = ["import BPF", "set_option maxRecDepth 100000", "namespace KProgTV.Compiled"]
    immediates, offsets = set(), set()
    for symbol in symbols.iter_symbols():
        if symbol["st_info"]["type"] != "STT_FUNC":
            continue
        section_id = symbol["st_shndx"]
        if not isinstance(section_id, int):
            raise SystemExit(f"unresolved BPF function: {symbol.name}")
        section = elf.get_section(section_id)
        start, size = symbol["st_value"], symbol["st_size"]
        for relocation in elf.iter_sections():
            if relocation["sh_type"] in ("SHT_REL", "SHT_RELA") and relocation["sh_info"] == section_id:
                if any(start <= item["r_offset"] < start + size for item in relocation.iter_relocations()):
                    raise SystemExit(f"{symbol.name}: needs linked relocation metadata")
        data = section.data()[start:start + size]
        if len(data) != size or not data or size % 8:
            raise SystemExit(f"{symbol.name}: invalid BPF function extent")
        if not symbol.name.isidentifier() or not symbol.name.isascii():
            raise SystemExit(f"invalid Lean symbol: {symbol.name}")
        rows.append(f"def {symbol.name} : Array KProgFormal.Reference.Byte := #[" +
                    ", ".join(f"0x{byte:02x}" for byte in data) + "]")
        for index in range(size // 8):
            code, registers, offset, immediate = struct.unpack_from("<BBHI", data, 8 * index)
            immediates.add(immediate)
            offsets.add(offset)
            rows.append(f"@[simp] theorem {symbol.name}_decode_{index} : " +
                        f"BPF.decode {symbol.name} {index} = .ok " +
                        f"⟨{code}, {registers % 16}, {registers // 16}, {offset}, {immediate}⟩ := by rfl")
    for value in sorted(immediates):
        signed = value if value < 2**31 else value - 2**32
        rows.append(f"@[simp] theorem imm_{value} : " +
                    f"(BitVec.ofNat 32 {value}).signExtend 64 = BitVec.ofNat 64 {signed % 2**64} := by decide")
    for value in sorted(offsets):
        signed = value if value < 2**15 else value - 2**16
        rows.append(f"@[simp] theorem off_{value} : " +
                    f"(BitVec.ofNat 16 {value}).toInt = ({signed} : Int) := by decide")
    rows.append("end KProgTV.Compiled")
    args.output.write_text("\n".join(rows) + "\n")
