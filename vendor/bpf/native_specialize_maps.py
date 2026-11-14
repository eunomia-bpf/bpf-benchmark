#!/usr/bin/env python3
"""Give bpf_map_lookup_elem a C body built from the load-time map layout.

The loader already lowers an array lookup to address arithmetic in the linked
blob, but it does so after clang has compiled the program, so everything the
program does with the returned pointer -- the NULL check, the field offsets, the
branches on the loaded value -- stays as it was compiled. With the map layout
known while clang runs, the lookup itself is address arithmetic and the caller
folds through it.

The map declarations a BPF program writes carry the layout:

    struct config_map {
        int (*type)[BPF_MAP_TYPE_ARRAY];
        int (*max_entries)[1];          <- the entry count
        typeof(u32) *key;                 <- the key type
        typeof(config_entry_t) *value;    <- the value type
    } config_map __attribute__((section(".maps"), used));

so each map's kind and shape are read from the program's own declarations and
the body is emitted per map:

  array, percpu array  address arithmetic, the index range check inline
  hash family          a direct call to the map's lookup function

The result is the same expression the loader patches into the machine code, one
level earlier, where clang can fold around it.

Usage: native_specialize_maps.py --unit <unit.i|unit.specialized.i>
                                  --output <unit.maps.i> [--report <file.json>]
"""
from __future__ import annotations

import argparse
import subprocess
import json
import re
import sys
from pathlib import Path

# The kernel's own layout constants, as the loader and the linker use them.
PERCPU_BASE_ADDR = 0  # gs:[this_cpu_off], supplied when --percpu is used
ARRAY_VALUE_OFFSET = 304
PERCPU_ARRAY_PPTRS_OFFSET = 304
HTAB_KEY_OFFSET = 48

MAP_DECL = re.compile(
    r"^(?:struct (\w+) |struct )\{\n"
    r"(?P<body>(?:[^\n]*\n)*?)"
    r"\} (\w+)"
    # OTel puts diagnostics pragmas between the declarator and its attribute, so
    # the attribute is looked for on the lines that follow.
    r"(?:\s*\n#pragma[^\n]*)*\s*"
    r"__attribute__\(\(section\(\"\.maps\"\), used\)\)"
    r"(?:\s*\n#pragma[^\n]*)*\s*;",
    re.M)

# One field of a map declaration: `int(*(type))[...]`, `typeof(T) *(key);` and
# so on. Cilium writes the fields in its own order, so each is looked up by name
# rather than by position.
# One field of a map declaration. Cilium writes `int(*(type))[X]` and
# `typeof(T) *(key)` -- the parentheses are part of the declarator -- while the
# older form writes `int (*type)[X]`, so both shapes are accepted and a field is
# looked up by its name rather than by position.
MAP_FIELD = re.compile(
    r"\(\s*\*\s*\(\s*(\w+)\s*\)\s*\)\s*\[([^\]]*)\]"
    r"|\bint\s*\(\s*\*\s*(\w+)\s*\)\s*\[([^\]]*)\]"
    r"|\btypeof\((.+?)\)\s*\*\s*\(?\s*(\w+)\s*\)?\s*;")

# BPF map types, from uapi/linux/bpf.h, that the inline body handles.
ARRAY_TYPES = {"BPF_MAP_TYPE_ARRAY": "array",
               "BPF_MAP_TYPE_PERCPU_ARRAY": "percpu_array"}

# Hash kinds the loader lowers to a call plus the element's key offset. They
# stay calls unless --hash is given, because the loader already adds the
# offset and a C body only repeats it.
HASH_TYPES = {"BPF_MAP_TYPE_HASH", "BPF_MAP_TYPE_LRU_HASH",
              "BPF_MAP_TYPE_PERCPU_HASH", "BPF_MAP_TYPE_HASH_OF_MAPS"}

# Key sizes for the hash element offset. The two key types the six
# applications' maps use are the fixed-width scalars u32 and u64; anything else
# takes its size from the loaded map metadata.
KEY_SIZES = {"u32": 4, "__u32": 4, "int": 4, "u64": 8, "__u64": 8,
             "unsigned int": 4, "unsigned long long": 8, "u16": 2, "__u16": 2}
BODY = """
/* Load-time map lookup bodies: the layout the loader holds at program load. */
static inline __attribute__((always_inline)) void *__sp_lookup_{name}(void *map, const void *key)
{{
{body}
}}
"""

ARRAY_BODY = """    unsigned int __k;
    __builtin_memcpy(&__k, key, sizeof(__k));
    if (__k >= {entries}u)
        return (void *)0;
    return (void *)((char *)map + {value_offset}u + (unsigned long)__k * {elem_size}u);"""

# A percpu array's value lives in the per-CPU area: the array slot holds a
# pointer and the loader adds gs:[&this_cpu_off] to it. That address is a
# run-time kallsyms value, so a C body built at build time cannot carry it and
# the loader keeps percpu arrays; this body serves --percpu, where the address
# is supplied as PERCPU_BASE_ADDR.
PERCPU_ARRAY_BODY = """    unsigned int __k;
    __builtin_memcpy(&__k, key, sizeof(__k));
    if (__k >= {entries}u)
        return (void *)0;
    void *__pp = *(void **)((char *)map + {value_offset}u +
                            (unsigned long)__k * {elem_size}u);
    if ((unsigned long)__pp == 0)
        return (void *)0;
    unsigned long __cpu_off;
    __asm__ __volatile__("movq %%gs:%c1, %0" : "=r"(__cpu_off)
                         : "i"({cpu_off}));
    return (void *)((char *)__pp + __cpu_off);"""

# The loader's own hash post-processing: the map's lookup function runs, then
# the element's key offset is added, so the program's NULL check sees the same
# pointer the linked blob gives it.
HASH_BODY = """    void *__v = __sp_htab_lookup(map, key);
    if ((unsigned long)__v == 0)
        return (void *)0;
    return (void *)((char *)__v + {key_offset}u);"""


# A map's entry count is a constant expression in the unit, not a literal: upstream
# sources write it as a product of size macros (`(512 * 2)`) or in hex
# (`0x00fffffe`), and the frontend has already expanded the macros away.  Accept
# any expression built from integer literals and the four arithmetic operators
# and evaluate it here; anything else stays unresolved, as before.
ENTRIES_EXPR = re.compile(r"^[\s0-9a-fA-FxX()*+\-]*$")
INT_LITERAL = re.compile(r"0[xX][0-9a-fA-F]+|\d+|[()+\-*/]")


def constant_entries(text: str) -> "int | None":
    """The entry count of a map declaration, or None if it is not a constant."""
    if not text or not ENTRIES_EXPR.fullmatch(text):
        return None
    tokens = INT_LITERAL.findall(text)
    if not tokens:
        return None
    expr = "".join(token if token in "()+-*/" else f"({token})" for token in tokens)
    try:
        value = eval(expr, {"__builtins__": {}}, {})  # literals and operators only
    except Exception:
        return None
    return value if isinstance(value, int) and value > 0 else None


def declarations(unit: Path) -> list[dict[str, object]]:
    """Every map declaration in the unit, with the layout its fields carry."""
    text = unit.read_text()
    found: list[dict[str, object]] = []
    for match in MAP_DECL.finditer(text):
        named, body, name = match.groups()
        fields: dict[str, str] = {}
        for field in MAP_FIELD.finditer(body):
            cil_square, cil_type, old_square, old_type, typeof_text, typeof_name = \
                field.groups()
            if cil_square is not None:
                fields[cil_square] = cil_type
            elif old_square is not None:
                fields[old_square] = old_type
            elif typeof_name is not None:
                fields[typeof_name] = typeof_text
        type_text = fields.get("type", "").strip()
        entries = constant_entries(fields.get("max_entries", "").strip())
        if not type_text or entries is None:
            continue
        key_type = (fields.get("key") or "").strip()
        found.append({
            "name": name,
            "struct": named or name,
            "type": type_text,
            "entries": entries,
            "key_type": key_type,
            "key_size": KEY_SIZES.get(key_type, 0),
            "value_type": (fields.get("value") or "").strip(),
            "offset": match.start(),
        })
    return found


def lookup_value_size(value_sizes: dict[str, int], name: str) -> int | None:
    """The loaded value size of a map, by its name or its 15-character form."""
    if name in value_sizes:
        return value_sizes[name]
    for loaded, size in value_sizes.items():
        if len(loaded) == 15 and name.startswith(loaded):
            return size
    return None


def lookup_key_size(key_sizes: dict[str, int], name: str) -> int | None:
    if name in key_sizes:
        return key_sizes[name]
    for loaded, size in key_sizes.items():
        if len(loaded) == 15 and name.startswith(loaded):
            return size
    return None


def size_of(unit: Path, type_text: str, flags: list[str]) -> int | None:
    """The size clang gives a declared value type, or None if it will not compile.

    The capture gives the sizes of the maps a program loaded, which is the only
    source when the value type is opaque; but the declaration names the type, so
    when the unit defines that type its size is one compile away and the map need
    not have been captured.

    The size is emitted as an array extent, so it arrives as the symbol's size
    column rather than as data to be located and read.
    """
    probe = unit.with_suffix(".size.c")
    out = unit.with_suffix(".size.o")
    probe.write_text(
        f'#include "{unit.resolve()}"\n'
        f"char __sp_size_value[sizeof({type_text})];\n")
    result = subprocess.run(["clang-18", *flags, "-w", "-c", str(probe), "-o", str(out)],
                            capture_output=True, text=True)
    if result.returncode != 0:
        return None
    symbols = subprocess.run(["llvm-nm-18", "--defined-only", "--print-size",
                              str(out)], capture_output=True, text=True).stdout
    for line in symbols.splitlines():
        parts = line.split()
        if len(parts) >= 4 and parts[3] == "__sp_size_value":
            return int(parts[1], 16)
    return None


def body_for(map_decl: dict, value_size: int, include_hash: bool = False,
             include_percpu: bool = False) -> str | None:
    """The inline body for one map, or None when it keeps the helper call."""
    kind = ARRAY_TYPES.get(str(map_decl["type"]))
    if kind == "percpu_array" and not include_percpu:
        return None
    if kind is None:
        if include_hash and str(map_decl["type"]) in HASH_TYPES:
            return HASH_BODY.format(key_offset=HTAB_KEY_OFFSET +
                                    ((int(map_decl["key_size"]) + 7) & ~7))
        return None
    elem_size = (value_size + 7) & ~7
    if kind == "array":
        return ARRAY_BODY.format(entries=map_decl["entries"],
                                 value_offset=ARRAY_VALUE_OFFSET,
                                 elem_size=elem_size)
    return PERCPU_ARRAY_BODY.format(entries=map_decl["entries"],
                                    value_offset=PERCPU_ARRAY_PPTRS_OFFSET,
                                    elem_size=8,
                                    cpu_off=PERCPU_BASE_ADDR)


DEFAULT_BODY = """
static inline __attribute__((always_inline)) void *__sp_map_lookup_default(void *map, const void *key)
{
    return __sp_bpf_map_lookup_elem(map, key);
}
"""

DISPATCH = """
@ARMS@"""

# Katran calls the helper by name with no indirection at all, so the unit has
# plain calls: bpf_map_lookup_elem(&map, &key).
# The key is usually the address of a local, but Katran also passes the address
# of a struct member (`&pckt.real_index`), so a member chain is accepted.
LOOKUP_PLAIN = re.compile(
    r"\bbpf_map_lookup_elem\(&(?P<map>\w+), &(?P<key>\w+(?:\.\w+)*)\)")


# Cilium's programs reach the same helper through a typed function pointer and
# the helper-id call, so the unit spells the lookup with the map and key as
# plain arguments:
#   ((__typeof__(map_lookup_elem))__native_helper_id(
#      (unsigned long)(BPF_FUNC_map_lookup_elem)))(&map, &key)
LOOKUP_TYPED = re.compile(
    r"\(\s*\(__typeof__\(map_lookup_elem\)\)__native_helper_id"
    r"\(\(unsigned long\)\(BPF_FUNC_map_lookup_elem\)\)\)"
    r"\(&(?P<map>\w+), &(?P<key>\w+)\)")

# The preprocessed unit spells a lookup as the compat header's helper macro
# expansion, with the helper id and both arguments inline. How many parentheses
# group each operand differs by program -- BCC and Tracee write ((&map)),
# tetragon (((&map))) -- so each group is matched as an optional parenthesis
# run and only the two identifiers are captured; the call that follows repeats
# them.
# The preprocessed unit spells a lookup as the compat header's helper macro
# expansion. Three programs write the surrounding expression differently -- BCC
# and Tracee with a (void *, const void *) cast and one paren level, tetragon
# with one more level, OTel with (void *, void *) and a space after the open
# paren -- so the grouping, the cast and the spacing are all matched loosely and
# only the two identifiers are captured. The pattern deliberately does not try to
# balance the parentheses itself: it finds the helper call, the two arguments
# that name the map and the key, and then the trailing call that repeats them.
LOOKUP_CALL = re.compile(
    r"\(\s*\(\s*void\s*\*\s*\(\s*\*\s*\)\s*\(\s*void\s*\*\s*,\s*(?:const\s+)?void\s*\*\s*\)\s*\)"
    r"\s*(?:__)?native_helper_id2\s*\(\s*\(\s*unsigned\s+long\s*\)\s*\(\s*1\s*\)\s*,"
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(*\s*&(?P<map>\w+)\s*\)*\s*,"
    r"\s*\(\s*unsigned\s+long\s*\)\s*\(*\s*&(?P<key>[\w>.\-\[\]]+)\s*\)*"
    r"[\s\S]{0,200}?\)\s*\(*\s*&(?P=map)\s*\)*\s*,\s*\(*\s*&(?P=key)\s*\)*")




# The preprocessed unit spells a lookup as the compat header's helper macro
# expansion, with the helper id and both arguments inline. How many parentheses
# group each operand differs by program -- BCC and Tracee write ((&map)),
# tetragon (((&map))) -- so the groups are matched as runs and only the two
# identifiers are captured; the call that follows repeats them.
_OPERAND = r"\(+(?P<{}>&?\w+)\)+"






# The preprocessed unit spells a lookup as the compat header's helper macro
# expansion, with the helper id and both arguments inline:
#   ((void *(*)(void *, const void *))native_helper_id2((unsigned long)(1),
#     (unsigned long)((&map)), (unsigned long)(&key)))((&map), (&key))
# The parentheses around the operands differ by program: BCC and Tracee spell
# ((&map)), tetragon (((&map))), so the grouping is matched loosely and only the
# identifiers are captured.
_GROUP = r"\(+\s*(?P<{}>&?\s*\w+)\s*\)+"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--unit", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--report", default="")
    parser.add_argument("--value-sizes", default="",
                        help="JSON: map name -> value size, from the loaded maps")
    parser.add_argument("--key-sizes", default="",
                        help="JSON: map name -> key size, from the loaded maps")
    parser.add_argument("--hash", action="store_true",
                        help="also give the hash family a body (a call plus the key offset)")
    parser.add_argument("--type-sizes", action="store_true",
                        help="size a map's value type from the unit when the "
                             "capture did not record the map")
    parser.add_argument("--percpu", action="store_true",
                        help="also inline percpu arrays (needs --percpu-base)")
    args = parser.parse_args()

    unit = Path(args.unit)
    output = Path(args.output)
    maps = declarations(unit)
    value_sizes = json.loads(Path(args.value_sizes).read_text()) if args.value_sizes else {}
    key_sizes = json.loads(Path(args.key_sizes).read_text()) if args.key_sizes else {}

    by_name = {str(m["name"]): m for m in maps}
    bodies: list[str] = []
    inlined: dict[str, dict[str, object]] = {}
    counts: dict[str, int] = {}

    have_call = False
    text_in = unit.read_text()
    # One unit uses one convention, but matching both costs nothing and keeps
    # the rule working if a program mixes them.
    calls = (list(LOOKUP_CALL.finditer(text_in))
             + list(LOOKUP_TYPED.finditer(text_in))
             + list(LOOKUP_PLAIN.finditer(text_in)))
    for match in calls:
        name = match.group("map").lstrip("&")
        if name not in by_name:
            continue
        if name not in inlined:
            decl = by_name[name]
            value_size = lookup_value_size(value_sizes, name)
            if not value_size and args.type_sizes and decl["value_type"]:
                value_size = size_of(unit, str(decl["value_type"]), [])
            if not value_size:
                continue
            key_size = decl["key_size"] or lookup_key_size(key_sizes, name) or 0
            decl["key_size"] = key_size
            body = body_for(decl, int(value_size), args.hash, args.percpu)
            if body is None:
                continue
            bodies.append(BODY.format(name=name, body=body))
            inlined[name] = {"name": name, "type": decl["type"],
                             "entries": decl["entries"],
                             "value_size": int(value_size),
                             "key_size": key_size}
        counts[name] = counts.get(name, 0) + 1
        have_call = True

    if not inlined:
        print(f"{unit.name}: no map lookup to inline", file=sys.stderr)
        output.write_text(unit.read_text())
        return

    text = unit.read_text()

    def rewrite(match: "re.Match[str]") -> str:
        name = match.group("map").lstrip("&")
        if name not in inlined:
            return match.group(0)
        return f"__sp_lookup_{name}((&{name}), (&{match.group('key').lstrip('&')}))"

    first_call = min(m.start() for m in calls)
    text = LOOKUP_PLAIN.sub(rewrite, LOOKUP_TYPED.sub(rewrite, LOOKUP_CALL.sub(rewrite, text)))
    # The bodies are plain C over the key and the returned pointer: they need
    # the extern declarations at the head of the unit and nothing of the map
    # types, so they go at the first blank line after those declarations,
    # ahead of every program body.
    # A unit with no blank line before its first lookup (otel's system_config is
    # one long sequence) has nowhere to put the bodies at the head, so they go
    # immediately before the first call instead.
    # At file scope: a line that ends a definition (`}` or `;`) and leaves the
    # brace depth at zero, taken from the first call backwards.
    blank = text.find("\n\n")
    if 0 <= blank < first_call and text.count("{", 0, blank) == text.count("}", 0, blank):
        cut = blank + 1
    else:
        cut = 0
        depth = 0
        for index, line in enumerate(text.splitlines(keepends=True)):
            depth += line.count("{") - line.count("}")
            end = sum(len(l) for l in text.splitlines(keepends=True)[:index + 1])
            if end > first_call:
                break
            if depth == 0 and line.rstrip().endswith(("}", ";")):
                cut = end
    assert cut <= first_call, (cut, first_call)
    prelude = (
        "\n/* --- load-time map lookup bodies (native_specialize_maps.py) --- */\n"
        "extern void *__sp_bpf_map_lookup_elem(void *map, const void *key);\n"
        "extern void *__sp_htab_lookup(void *map, const void *key);\n"
        + "".join(bodies))
    output.write_text(text[:cut] + prelude + text[cut:])
    total = sum(counts.values())
    print(f"{unit.name}: {total} lookup sites in {len(inlined)} maps inlined "
          f"({sum(1 for a in inlined.values() if a['type'] == 'BPF_MAP_TYPE_ARRAY')} array, "
          f"{sum(1 for a in inlined.values() if a['type'] == 'BPF_MAP_TYPE_PERCPU_ARRAY')} percpu array, "
          f"{sum(1 for a in inlined.values() if a['type'] in HASH_TYPES)} hash family)",
          file=sys.stderr)
    if args.report:
        Path(args.report).write_text(json.dumps(
            {"maps": list(inlined.values()), "sites": counts}, indent=1) + "\n")


if __name__ == "__main__":
    main()