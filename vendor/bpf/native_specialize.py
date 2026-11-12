#!/usr/bin/env python3
"""Load-time .rodata specialization of one native translation unit.

Input: the preprocessed unit and declaration index that
native_specialize_prepares.py wrote at build time, and the bytes the program's
.rodata map carries at load time. Output: a unit in which each frozen .rodata
global is a plain constant carrying those bytes, so clang folds every read of
it and every branch it decides.

The rewrite keeps the original declaration and inserts, after it, a byte-image
constant plus a #define that routes the name to it. Keeping the declaration is
what preserves the object's .rodata layout: the loader patches every native
.rodata symbol to map_value_addr + its own offset, so a reordered section would
read another global's bytes.

    const volatile int targ_pid = 0;
    static const union { unsigned char b[4]; const int v; }
        __sp_targ_pid __attribute__((unused)) = { .b = { 0xe8,0x00,0x00,0x00 } };
    #undef targ_pid
    #define targ_pid (__sp_targ_pid.v)

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
import re
import sys
from pathlib import Path

MAX_INITIALIZER_BYTES = 1 << 16
# Pragmas that name a macro, with the value the program's headers give it.
PRAGMA_MACRO_VALUES = {"MAX_IPV4_OPTS": 3}
ARRAY_TYPE = "^(.+)\\[(\\d+)\\]$"


def byte_image(data: bytes) -> str:
    return ", ".join(f"0x{byte:02x}" for byte in data)


def constants_block_line(lines: list[str], entries: list[dict]) -> int:
    """Where the constant block goes.

    Three constraints: after every declaration of every name it rewrites
    (cilium's ASSIGN_CONFIG declares a global and then defines it), at file
    scope (a static const inside a function body is an error, and the first read
    of a name is usually inside a function), and before the first read of any
    of them, or that read keeps the map load.

    The scan walks from the last declaration and stops at the first line where
    the brace depth is back to zero -- the end of the statement that declares
    the globals -- then extends past any type definition the constants name.
    """
    last_declaration = max(e.get("end_line", e["line"]) for e in entries)
    depth = 0
    boundary = last_declaration
    for at in range(last_declaration - 1, len(lines)):
        depth += lines[at].count("{") - lines[at].count("}")
        boundary = at + 1
        if depth <= 0:
            break
    names = [e["name"] for e in entries]
    first_read = len(lines)
    for name in names:
        for at in range(boundary, len(lines)):
            if name in lines[at]:
                first_read = min(first_read, at)
                break
    return min(boundary, first_read) if first_read > boundary else boundary


def _unused_block_line(lines: list[str], names: list[str]) -> int:
    """Where the constant block goes: after the last line a name or its type needs.

    A constant's member type may be a union the unit defines further down, and
    the #define must follow every declaration of the name, so the block goes
    after the last of those lines and before the first read that follows it.
    """
    needed = set(names)
    last = 0
    for at, line in enumerate(lines):
        for name in needed:
            if name in line:
                last = at
                break
    # A type's closing line (`};`) follows its last member mention.
    for at in range(last, min(len(lines), last + 4)):
        if lines[at].strip().startswith("}"):
            last = at
    return last + 1


def assigned_in_source(lines: list[str], entry: dict) -> bool:
    """True when the program itself gives the global a value.

    Such a global is already a compile-time constant (cilium's ASSIGN_CONFIG
    hardcodes a few), so the loaded image cannot change it and the rewrite would
    only add a second definition.
    """
    name = entry["name"]
    for at in range(max(0, entry["line"] - 1), min(len(lines), entry["line"] + 12)):
        line = lines[at]
        position = line.find(name)
        while position >= 0:
            if "=" in line[position + len(name):].split(";")[0]:
                return True
            position = line.find(name, position + 1)
    return False


def type_definition_end(lines: list[str], type_text: str) -> int:
    """The last line that closes a definition of the constant's own type.

    A declaration's type may name a union or struct the unit defines further
    down (cilium's `union macaddr`), and the constant needs the complete type.
    """
    name = strip_volatile(type_text).split()[-1].split("[")[0]
    if not name or not (name.startswith(("union", "struct")) or True):
        return 0
    last = 0
    pattern = re.compile(rf"^\s*(?:union|struct)\s+{re.escape(name)}\s*\{{|^\}}\s*{re.escape(name)}\s*;")
    for at, line in enumerate(lines, start=1):
        if pattern.match(line):
            last = at
    return last


def definition_end(lines: list[str], entry: dict) -> int | None:
    """The last line that declares `name`, so the #define follows every one.

    A program may declare a global and then define it on a following statement
    (cilium's ASSIGN_CONFIG writes `void __check_x(...)` and the defining
    declaration on one line), so the search runs over the lines the AST reports
    for the name and takes the last one where it is declared rather than read.
    """
    name = entry["name"]
    lines_from = max(0, entry["line"] - 1)
    last = None
    for at in range(lines_from, min(len(lines), lines_from + 12)):
        line = lines[at]
        if name not in line:
            continue
        for position in range(len(line)):
            if line.startswith(name, position):
                after = line[position + len(name):].lstrip()
                if after.startswith(("=", ";", "[")):
                    last = at
                break
    return last


def strip_volatile(type_text: str) -> str:
    return " ".join(word for word in type_text.split()
                    if word not in ("volatile", "const"))


def specialization(name: str, entry: dict, data: bytes) -> str:
    """The constant that carries the loaded bytes, plus the macro that routes
    the name to it. The original declaration stays in place, which keeps the
    object's .rodata layout."""
    # An array type's brackets belong after the member name: the recorded
    # "const volatile int[64]" becomes "const int v[64]". A scalar or struct
    # type is used as written.
    member = strip_volatile(entry["type"])
    declarator = f"{member} v"
    if entry.get("array_type"):
        base, brackets = member.split("[", 1)
        declarator = f"{base} v[{brackets}"
    constant = f"__sp_{name}"
    return (f"static const union {{ unsigned char b[{len(data)}]; const {declarator}; }}\n"
            f"    {constant} __attribute__((unused)) = {{ .b = {{ {byte_image(data)} }} }};\n"
            f"#undef {name}\n#define {name} ({constant}.v)")


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

    # Each constant goes right after the last declaration of its name, so every
    # read that follows is folded (a program may declare one twice -- cilium's
    # ASSIGN_CONFIG writes a bare declaration and then the defining one -- so the
    # #define has to follow both). Back to front keeps line numbers valid.
    applied = 0
    tail: list[str] = []
    for entry in index["declarations"]:
        offset, size = entry["offset"], entry["size"]
        if offset + size > len(rodata):
            sys.exit(f"{entry['name']}: bytes {offset}..{offset + size} past the "
                     f"{len(rodata)}-byte .rodata image")
        if size > MAX_INITIALIZER_BYTES:
            sys.exit(f"{entry['name']}: {size}-byte initializer exceeds "
                     f"{MAX_INITIALIZER_BYTES}")
        if assigned_in_source(lines, entry):
            continue
        tail.append(specialization(entry["name"], entry, rodata[offset:offset + size]))
        applied += 1

    text = "\n".join(lines)
    # A pragma keeps its macro through preprocessing (#pragma
    # unroll(MAX_IPV4_OPTS) in cilium), so the names are given their values.
    pragma_macros = set(re.findall(r"#pragma \w+\((\w+)\)", text))
    preamble = "".join(f"#ifndef {name}\n#define {name} {PRAGMA_MACRO_VALUES[name]}\n#endif\n"
                       for name in sorted(pragma_macros) if name in PRAGMA_MACRO_VALUES)
    if tail:
        # The constants and their #defines go just before the first function
        # body: every type the declarations name is complete by then, and every
        # read of a global follows, so the #define reaches all of them.
        boundary = constants_block_line(lines, index["declarations"])
        block = ("\n/* --- frozen .rodata as constants (native_specialize.py) --- */\n"
                 + "\n".join(tail) + "\n")
        lines.insert(boundary, block)
        text = "\n".join(lines)
    Path(args.output).write_text(preamble + text)
    print(f"{index['object']}: {applied} declarations from {len(rodata)} "
          f"{args.map_name or '.rodata'} bytes", file=sys.stderr)


if __name__ == "__main__":
    main()