#!/usr/bin/env python3
"""Check actual BPF primitive access kind, address, width and multiplicity."""
import argparse
from pathlib import Path
import re
import struct
import subprocess

ROOT = Path(__file__).resolve().parent.parent


def command(argv):
    try:
        return subprocess.run(argv, text=True, capture_output=True, check=True).stdout
    except OSError as error:
        raise SystemExit(f"memory widths: cannot run {argv[0]}: {error}") from error
    except subprocess.CalledProcessError as error:
        raise SystemExit(f"memory widths: {argv[0]} failed: {error.stderr}") from error


def accesses(instructions, fixed_displacement=None):
    # Register1 starts at the guest pointer; track pointer copies and constant
    # additions. Every other value is scalar. Unexpected control flow fails.
    registers = [None] * 11
    registers[1] = 0
    events = []
    for raw in instructions:
        code, packed, offset, immediate = struct.unpack("<BBhi", raw)
        dst, src = packed & 15, packed >> 4
        if dst >= 11 or src >= 11:
            raise SystemExit("memory widths: invalid BPF register")
        if code in (0x07, 0x17):
            if registers[dst] is not None:
                registers[dst] += immediate if code == 0x07 else -immediate
        elif code == 0xBF:
            registers[dst] = registers[src]
        elif code & 7 in (1, 2, 3) and code & 0xE0 == 0x60:
            kind = "read" if code & 7 == 1 else "write"
            pointer = registers[src if kind == "read" else dst]
            width = {0: 4, 8: 2, 16: 1, 24: 8}[code & 24]
            if pointer is None:
                raise SystemExit("memory widths: access lost its guest pointer")
            if fixed_displacement is not None and (pointer != 0 or offset != fixed_displacement):
                raise SystemExit("memory widths: fixed load modified its base or lost its literal displacement")
            events.append((kind, pointer + offset, width))
            if kind == "read":
                registers[dst] = None
        elif code == 0x95:
            pass
        elif code & 7 in (4, 7):
            registers[dst] = None
        else:
            raise SystemExit(f"memory widths: unexpected BPF opcode {code:#x}")
    return events


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--clang", default="clang-18")
    parser.add_argument("--objdump", default="llvm-objdump-18")
    parser.add_argument("--include-dir", type=Path, default=ROOT)
    parser.add_argument("--build-dir", type=Path, default=ROOT / "build/memory-widths")
    args = parser.parse_args()
    args.build_dir.mkdir(parents=True, exist_ok=True)
    obj = args.build_dir / "x86.bpf.o"
    command([args.clang, "-target", "bpfel", "-O2", "-g", "-I", str(args.include_dir),
             "-I", str(ROOT), "-c", str(ROOT / "oracles/test_x86_memory_widths.c"), "-o", str(obj)])
    disassembly = command([args.objdump, "-d", str(obj)])
    (args.build_dir / "x86.asm").write_text(disassembly)
    functions, current = {}, None
    for line in disassembly.splitlines():
        label = re.fullmatch(r"[0-9a-f]+ <([^>]+)>:", line)
        if label:
            current = label[1]
            if current in functions:
                raise SystemExit(f"memory widths: duplicate function {current}")
            functions[current] = []
            continue
        instruction = re.match(r"\s*\d+:((?:\s+[0-9a-f]{2}){8})\s", line)
        if instruction:
            if current is None:
                raise SystemExit("memory widths: instruction outside a function")
            functions[current].append(bytes.fromhex(instruction[1]))
    expected = {f"{kind}_{name}": [("read" if kind == "load" else "write", 3, width)]
                for name, width in [("b8", 1), ("b16", 2), ("b32", 4), ("b64", 8), ("default", 8)]
                for kind in ("load", "store")}
    fixed = {f"fixed_{name}_{suffix}": [("read", offset, width)]
             for name, width in [("b8", 1), ("b16", 2), ("b32", 4), ("b64", 8), ("default", 8)]
             for suffix, offset in [("context", 88), ("negative", -3), ("minimum", -32768), ("maximum", 32767)]}
    expected.update(fixed)
    if functions.keys() != expected.keys():
        raise SystemExit(f"memory widths: function set mismatch: {functions.keys() ^ expected.keys()}")
    for name, wanted in expected.items():
        actual = accesses(functions[name], wanted[0][1] if name in fixed else None)
        if actual != wanted:
            raise SystemExit(f"memory widths: {name}: got {actual}, expected {wanted}")
    for mode in (1, 2, 3):
        result = subprocess.run([args.clang, "-target", "bpfel", "-O2", "-I", str(args.include_dir),
            "-I", str(ROOT), f"-DKPROG_TEST_BAD_FIXED={mode}", "-c", str(ROOT / "oracles/test_x86_memory_widths.c"),
            "-o", str(args.build_dir / f"bad-fixed-{mode}.o")], text=True, capture_output=True)
        (args.build_dir / f"bad-fixed-{mode}.log").write_text(result.stdout + result.stderr)
        if result.returncode == 0 or "fixed load requires a constant signed16 displacement" not in result.stderr:
            raise SystemExit(f"memory widths: bad fixed displacement mode{mode} did not fail precisely: {result.stderr}")
    print("x86 BPF memory widths: ten generic + twenty fixed loads keep exact kind/address/width/count; fixed bases/displacements and three bad-offset rejections OK")


if __name__ == "__main__":
    main()
