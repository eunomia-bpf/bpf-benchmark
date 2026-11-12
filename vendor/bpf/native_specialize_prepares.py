#!/usr/bin/env python3
"""Prepare one native object for load-time .rodata specialization.

For a native object <.native.o> built by this Makefile, write a directory with:

  <name>.i          the preprocessed translation unit, one line per source line,
                    carried into the image so the load-time compile needs no
                    include paths and no build-machine headers;
  <name>.decls.json the .rodata declarations that the load-time step rewrites:
                    name, type spelling, byte offset and size in .rodata.

The .rodata globals of a BPF program are its frozen configuration: the loader
knows their contents at load time (they live in the program's own .rodata map)
and the JIT's verifier folds the branches they decide. The load-time step
replaces each declaration with a constant carrying the loaded bytes, so clang
folds the same branches in the native code at compile time.

Usage: native_specialize_prepares.py --object <path.native.o> --output-dir <dir> -- <clang argv...>
The clang argv after -- is the exact command that produced the object, with the
input source and -o <object> omitted; it is rerun with -E -P to preprocess.
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

RODATA_PREFIX = ".rodata"
# The .rodata section a declaration lives in, in order of specificity: a
# declaration in .rodata.str1.1 is a string, one in .rodata.config is a Cilium
# configuration variable, one in .rodata is a plain global.
AST_VAR_DECL = re.compile(
    r"^[|`]?-VarDecl 0x[0-9a-f]+ <line:(\d+):(\d+), col:(\d+)> col:(\d+) "
    r"(?:used |referenced )?(\w+) '([^']*)'(.*)$"
)


def run(argv: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(argv, capture_output=True, text=True)


def section_index(object_path: Path) -> tuple[dict[int, tuple[str, int, int]], dict[str, tuple[int, int, int]]]:
    """Section index -> (name, address, size), plus name -> (index, address, size)."""
    out = run(["readelf", "-SW", str(object_path)]).stdout
    by_index: dict[int, tuple[str, int, int]] = {}
    by_name: dict[str, tuple[int, int, int]] = {}
    for line in out.splitlines():
        m = re.match(r"^\s*\[\s*(\d+)\]\s+(\S+)\s+(\S+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)", line)
        if not m:
            continue
        index, name, _, addr, off, size = m.groups()
        entry = (name, int(addr, 16), int(size, 16))
        by_index[int(index)] = entry
        by_name[name] = (int(index), int(addr, 16), int(size, 16))
    return by_index, by_name


def rodata_globals(object_path: Path) -> dict[str, tuple[str, int, int]]:
    """Every named object in a .rodata section: name -> (section, offset, size)."""
    by_index, _ = section_index(object_path)
    out = run(["readelf", "-sW", str(object_path)]).stdout
    symbols: dict[str, tuple[str, int, int]] = {}
    for line in out.splitlines():
        fields = line.split()
        if len(fields) < 8 or not fields[0].endswith(":") or not fields[6].isdigit():
            continue
        if fields[3] != "OBJECT" or fields[4] != "GLOBAL":
            continue
        name = fields[7]
        index = int(fields[6])
        section = by_index.get(index)
        if not section or not section[0].startswith(RODATA_PREFIX):
            continue
        if name in symbols:
            continue
        symbols[name] = (section[0], int(fields[1], 16) - section[1], int(fields[2]))
    return symbols


def unit_name(object_path: Path) -> str:
    """The unit's file name: the object's, with a .i suffix."""
    name = object_path.name
    for suffix in (".native.o", ".plain.o", ".rodata.o", ".o"):
        if name.endswith(suffix):
            return name[: -len(suffix)] + ".i"
    return name + ".i"


def preprocess(object_path: Path, output: Path, clang_argv: list[str]) -> None:
    argv = list(clang_argv) + ["-E", "-P", "-o", str(output)]
    result = run(argv)
    if result.returncode != 0:
        sys.stderr.write(result.stderr)
        raise SystemExit(f"preprocess failed for {object_path}")


def array_length(type_text: str) -> int:
    """The declared element count of an array type, 0 for a non-array type."""
    m = re.match(r"^.+\[(\d+)\]$", type_text)
    return int(m.group(1)) if m else 0


def declarations(unit: Path) -> dict[str, dict[str, object]]:
    """Top-level volatile declarations of the preprocessed unit, by name."""
    result = run(["clang-18", "-fsyntax-only", "-Xclang", "-ast-dump", "-x", "c", str(unit)])
    if result.returncode != 0:
        sys.stderr.write(result.stderr)
        raise SystemExit(f"ast dump failed for {unit}")
    found: dict[str, dict[str, object]] = {}
    for line in result.stdout.splitlines():
        m = AST_VAR_DECL.match(line)
        if not m:
            continue
        line_no, col, _end_col, name_col, name, type_text, rest = m.groups()
        if "volatile" not in type_text:
            continue
        found[name] = {
            "line": int(line_no),
            "name_column": int(name_col),
            "name": name,
            "type": type_text,
            "array_length": array_length(type_text),
            "has_initializer": " cinit" in rest,
        }
    return found


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--object", required=True)
    parser.add_argument("--output-dir", required=True)
    parser.add_argument("clang", nargs=argparse.REMAINDER)
    args = parser.parse_args()

    object_path = Path(args.object).resolve()
    output_dir = Path(args.output_dir).resolve()
    clang_argv = args.clang[1:] if args.clang and args.clang[0] == "--" else args.clang
    if not clang_argv:
        raise SystemExit("missing clang command after --")

    output_dir.mkdir(parents=True, exist_ok=True)
    unit = output_dir / unit_name(object_path)
    preprocess(object_path, unit, clang_argv)

    rodata = rodata_globals(object_path)
    decls = declarations(unit)
    entries = []
    for name, (section, offset, size) in sorted(rodata.items()):
        decl = decls.get(name)
        if not decl:
            continue
        entries.append({
            "name": name,
            "section": section,
            "offset": offset,
            "size": size,
            "line": decl["line"],
            "name_column": decl["name_column"],
            "type": decl["type"],
            "array_length": decl["array_length"],
            "has_initializer": decl["has_initializer"],
        })

    index = unit.with_suffix(".decls.json")
    index.write_text(json.dumps({
        "object": object_path.name,
        "unit": unit.name,
        "rodata": [{"section": name, "size": size} for name, _index, (_n, _a, size) in
                   sorted((k, v[0], v) for k, v in section_index(object_path)[1].items()
                          if k.startswith(RODATA_PREFIX))],
        "declarations": entries,
    }, indent=1) + "\n")
    print(f"{object_path.name}: {len(entries)} .rodata declarations, unit {unit.stat().st_size} bytes")


if __name__ == "__main__":
    main()