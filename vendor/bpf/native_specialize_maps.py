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
import json
import re
import sys
from pathlib import Path

# The kernel's own layout constants, as the loader and the linker use them.
ARRAY_VALUE_OFFSET = 304
PERCPU_ARRAY_PPTRS_OFFSET = 304
HTAB_KEY_OFFSET = 48

MAP_DECL = re.compile(
    r"^struct (\w+) \{\n"
    r"(?:\s+int \(\*type\)\[(\w+)\];\n)?"
    r"(?:\s+int \(\*max_entries\)\[(\d+)\];\n)?"
    r"(?:\s+typeof\((.+?)\) \*key;\n)?"
    r"(?:\s+typeof\((.+?)\) \*value;\n)?"
    r"\} (\w+) __attribute__\(\(section\(\"\.maps\"\), used\)\);",
    re.M)

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

ARRAY_BODY = """    __u32 __k;
    __builtin_memcpy(&__k, key, sizeof(__k));
    if (__k >= {entries}u)
        return (void *)0;
    return (void *)((char *)map + {value_offset}u + (unsigned long)__k * {elem_size}u);"""

PERCPU_ARRAY_BODY = """    __u32 __k;
    __builtin_memcpy(&__k, key, sizeof(__k));
    if (__k >= {entries}u)
        return (void *)0;
    return (void *)((char *)map + {value_offset}u + (unsigned long)__k * {elem_size}u);"""

# The loader's own hash post-processing: the map's lookup function runs, then
# the element's key offset is added, so the program's NULL check sees the same
# pointer the linked blob gives it.
HASH_BODY = """    void *__v = __sp_htab_lookup(map, key);
    if ((unsigned long)__v == 0)
        return (void *)0;
    return (void *)((char *)__v + {key_offset}u);"""


def declarations(unit: Path) -> list[dict[str, object]]:
    """Every map declaration in the unit, with the layout its fields carry."""
    text = unit.read_text()
    found: list[dict[str, object]] = []
    for match in MAP_DECL.finditer(text):
        struct, type_text, entries, key_type, value_type, name = match.groups()
        if not type_text or not entries:
            continue
        found.append({
            "name": name,
            "struct": struct,
            "type": type_text,
            "entries": int(entries),
            "key_type": (key_type or "").strip(),
            "key_size": KEY_SIZES.get((key_type or "").strip(), 0),
            "value_type": (value_type or "").strip(),
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


def body_for(map_decl: dict, value_size: int, include_hash: bool = False) -> str | None:
    """The inline body for one map, or None when it keeps the helper call."""
    kind = ARRAY_TYPES.get(str(map_decl["type"]))
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
                                    elem_size=8)


DEFAULT_BODY = """
static inline __attribute__((always_inline)) void *__sp_map_lookup_default(void *map, const void *key)
{
    return __sp_bpf_map_lookup_elem(map, key);
}
"""

DISPATCH = """
@ARMS@"""

# The preprocessed unit spells a lookup as the compat header's helper macro
# expansion, with the helper id and both arguments inline:
#   ((void *(*)(void *, const void *))native_helper_id2((unsigned long)(1),
#     (unsigned long)((&map)), (unsigned long)(&key)))((&map), (&key))
LOOKUP_CALL = re.compile(
    r"\(\(void \*\(\*\)\(void \*, const void \*\)\)native_helper_id2"
    r"\(\(unsigned long\)\(1\), \(unsigned long\)\(\(&(?P<map>\w+)\)\), "
    r"\(unsigned long\)\(\(?&(?P<key>\w+)\)?\)\)\)"
    r"\(\(&(?P=map)\), \(&(?P=key)\)\)")


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
    for match in LOOKUP_CALL.finditer(unit.read_text()):
        name = match.group("map")
        if name not in by_name:
            continue
        if name not in inlined:
            decl = by_name[name]
            value_size = lookup_value_size(value_sizes, name)
            if not value_size:
                continue
            key_size = decl["key_size"] or lookup_key_size(key_sizes, name) or 0
            decl["key_size"] = key_size
            body = body_for(decl, int(value_size), args.hash)
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
        name = match.group("map")
        if name not in inlined:
            return match.group(0)
        return f"__sp_lookup_{name}((&{name}), (&{match.group('key')}))"

    first_call = min(m.start() for m in LOOKUP_CALL.finditer(text))
    text = LOOKUP_CALL.sub(rewrite, text)
    # The bodies are plain C over the key and the returned pointer: they need
    # the extern declarations at the head of the unit and nothing of the map
    # types, so they go at the first blank line after those declarations,
    # ahead of every program body.
    decls_end = text.index("\n\n") + 1
    cut = decls_end
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