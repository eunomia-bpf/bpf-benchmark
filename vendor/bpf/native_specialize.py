#!/usr/bin/env python3
"""Load-time .rodata specialization of one native translation unit.

Input: the preprocessed unit and declaration index that
native_specialize_prepares.py wrote at build time, and the bytes the program's
.rodata map carries at load time. Output: a unit in which each frozen .rodata
global is a plain constant carrying those bytes, so clang folds every read of
it and every branch it decides.

The rewrite keeps the original declaration (so the type spelling the program
wrote stays as it is) and inserts, after it, a byte-image constant plus a
#define that routes the name to it:

    const volatile int targ_pid = 0;
    ->
    const union { unsigned char b[4]; const int v; } targ_pid
        __attribute__((unused)) = { .b = { 0xe8,0x00,0x00,0x00 } };
    #define targ_pid (targ_pid.v)

The declaration is replaced in place, so the object keeps its name, its offset
in .rodata and its size; the loader resolves the .rodata symbol addresses from
exactly that layout. A union between the byte image and the constant type is a
compile-time constant for scalar, struct and array declarations alike, and an
array declaration uses its element type and element count so `sizeof (name)`
keeps the declared extent.

Usage: native_specialize.py --unit <unit.i> --decls <unit.decls.json>
                            --rodata <bytes.bin> --output <unit.specialized.i>
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

MAX_INITIALIZER_BYTES = 1 << 16
ARRAY_TYPE = "^(.+)\\[(\\d+)\\]$"


def byte_image(data: bytes) -> str:
    return ", ".join(f"0x{byte:02x}" for byte in data)


def strip_volatile(type_text: str) -> str:
    return " ".join(word for word in type_text.split()
                    if word not in ("volatile", "const"))


def specialization(name: str, entry: dict, data: bytes) -> str:
    """The declaration that replaces the original, plus the macro that routes
    the name to the constant member."""
    # An array type's brackets belong after the member name: the recorded
    # "const volatile int[64]" becomes "const int v[64]". A scalar or struct
    # type is used as written.
    member = strip_volatile(entry["type"])
    declarator = f"{member} v"
    if entry.get("array_type"):
        base, brackets = member.split("[", 1)
        declarator = f"{base} v[{brackets}"
    return (f"const union {{ unsigned char b[{len(data)}]; const {declarator}; }} "
            f"{name} __attribute__((unused)) = {{ .b = {{ {byte_image(data)} }} }};\n"
            f"#undef {name}\n#define {name} ({name}.v)")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--unit", required=True)
    parser.add_argument("--decls", required=True)
    parser.add_argument("--rodata", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--map-name", default="")
    args = parser.parse_args()

    unit = Path(args.unit)
    index = json.loads(Path(args.decls).read_text())
    rodata = Path(args.rodata).read_bytes()
    lines = unit.read_text().split("\n")

    # Back to front, so inserting text never shifts a later line number.
    applied = 0
    for entry in sorted(index["declarations"], key=lambda e: e["line"], reverse=True):
        offset, size = entry["offset"], entry["size"]
        if offset + size > len(rodata):
            sys.exit(f"{entry['name']}: bytes {offset}..{offset + size} past the "
                     f"{len(rodata)}-byte .rodata image")
        if size > MAX_INITIALIZER_BYTES:
            sys.exit(f"{entry['name']}: {size}-byte initializer exceeds "
                     f"{MAX_INITIALIZER_BYTES}")
        at = entry["line"] - 1
        lines[at] = specialization(entry["name"], entry, rodata[offset:offset + size])
        applied += 1

    Path(args.output).write_text("\n".join(lines))
    print(f"{index['object']}: {applied} declarations from {len(rodata)} "
          f"{args.map_name or '.rodata'} bytes", file=sys.stderr)


if __name__ == "__main__":
    main()