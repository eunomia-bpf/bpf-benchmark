#!/usr/bin/env python3
"""Detect accepted condition, CFG and register mutations of actual clang bytes."""
from pathlib import Path
import os
import subprocess
import sys

from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parent
original = root / "build/cmov-block.bpf.o"
with original.open("rb") as stream:
    elf = ELFFile(stream)
    locations = {}
    for symbol in elf.get_section_by_name(".symtab").iter_symbols():
        if symbol.name in ("tv_cmov16", "tv_cmov32", "tv_cmov64"):
            section = elf.get_section(symbol["st_shndx"])
            locations[symbol.name] = section["sh_offset"] + symbol["st_value"]

cases = [
    ("unchanged", None, 0, b""),
    ("wrong-condition", "tv_cmov64", 8 + 4, b"\x80"),
    ("wrong-successor", "tv_cmov16", 16 + 2, b"\x03"),
    ("wrong-source", "tv_cmov32", 24 + 1, b"\x10"),
]
for name, symbol, offset, replacement in cases:
    directory = root / "build/cmov-mutations" / name
    directory.mkdir(parents=True, exist_ok=True)
    artifact = bytearray(original.read_bytes())
    if symbol is not None:
        position = locations[symbol] + offset
        if artifact[position:position + len(replacement)] == replacement:
            raise SystemExit(f"{name}: mutation does not change the artifact")
        artifact[position:position + len(replacement)] = replacement
    path = directory / "artifact.bpf.o"
    path.write_bytes(artifact)
    subprocess.run([sys.executable, str(root / "extract_blocks.py"), str(path),
                    str(directory / "CompiledBlocks.lean")], check=True)
    result = subprocess.run([os.environ.get("MAKE", "make"), "--no-print-directory",
                             "cmov-certificate", f"CMOV_BLOCK_DIR={directory.relative_to(root)}"],
                            cwd=root, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (directory / "certificate.log").write_bytes(result.stdout)
    if symbol is None:
        if result.returncode:
            raise SystemExit(f"unchanged artifact failed: {directory}/certificate.log")
        print("unchanged clang artifact: PASS", flush=True)
    else:
        # Decode/extraction/import failure is not evidence that the theorem
        # notices a changed program: require its own semantic proof to fail.
        if (not result.returncode or b"CmovCertificate.lean:" not in result.stdout or
                b"The prover found" not in result.stdout):
            raise SystemExit(f"{name}: semantic rejection missing: {directory}/certificate.log")
        print(f"{name}: PASS (compiled artifact rejected)", flush=True)
