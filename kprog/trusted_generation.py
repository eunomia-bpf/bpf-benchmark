"""Strict generation view shared by trusted ISA workers.

The service derives this view from kernel-pinned source/map identities.
These functions accept no producer paths, C source or compiler flags.
"""
from io import BytesIO
import re
from elftools.elf.elffile import ELFFile

def u32(value, field):
    if type(value) is not int or not 0 <= value <= 0xffffffff:
        raise ValueError(f"{field} must be an unsigned 32-bit integer")
    return value


def declarations(metadata):
    if type(metadata) is not dict or set(metadata) != {"version", "prog_type", "section", "maps"}:
        raise ValueError("generation metadata requires only version, prog_type, section and maps")
    if type(metadata["version"]) is not int or metadata["version"] != 1:
        raise ValueError("generation metadata version must be 1")
    prog_type = u32(metadata["prog_type"], "prog_type")
    if prog_type == 0:
        raise ValueError("program type must be explicit")
    section = metadata["section"]
    if not isinstance(section, str) or not section or any(ord(c) < 32 or ord(c) > 126 for c in section):
        raise ValueError("program section must be nonempty printable ASCII")
    if type(metadata["maps"]) is not list:
        raise ValueError("maps must be a list of typed declarations")
    lines = ["#include <linux/bpf.h>", "#include <bpf_helpers.h>"]
    names = set()
    fields = {"map_type", "key_size", "value_size", "max_entries", "map_flags"}
    inner_count = 0

    def emit(item, label, name=None, tag=None):
        nonlocal inner_count
        required = fields | ({"name"} if name is not None else set())
        if type(item) is not dict or set(item) - {"inner_map"} != required:
            raise ValueError(f"{label} requires exactly the typed map fields")
        for field in fields:
            u32(item[field], f"{label}.{field}")
        if item["map_type"] == 0:
            raise ValueError(f"{label} type must be explicit")
        is_outer = item["map_type"] in {12, 13}
        if is_outer != ("inner_map" in item):
            raise ValueError(f"{label} inner template must match its map-in-map type")
        inner_type = None
        if is_outer:
            inner_type = f"__trusted_inner_{inner_count}"
            inner_count += 1
            emit(item["inner_map"], label + ".inner_map", tag=inner_type)
        lines.extend(["struct " + tag + " {" if tag else "struct {", f'    __uint(type, {item["map_type"]});',
            f'    __uint(key_size, {item["key_size"]});',
            f'    __uint(value_size, {item["value_size"]});',
            f'    __uint(max_entries, {item["max_entries"]});',
            f'    __uint(map_flags, {item["map_flags"]});'])
        if inner_type is not None:
            lines.append(f"    __array(values, struct {inner_type});")
        lines.append(f'}} {name} SEC(".maps");' if name is not None else "};")

    for index, item in enumerate(metadata["maps"]):
        if type(item) is not dict:
            raise ValueError(f"map {index} must be a typed declaration")
        name = item.get("name")
        if not isinstance(name, str) or re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name) is None or name in names:
            raise ValueError(f"map {index} has an invalid or duplicate identifier")
        names.add(name)
        emit(item, f"map {name}", name)
    return "\n".join(lines) + "\n", names



def validate_native(native_bytes, entry_symbol, machine):
    if not isinstance(native_bytes, bytes) or not native_bytes:
        raise ValueError("native request must contain ELF bytes")
    if not isinstance(entry_symbol, str) or re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", entry_symbol) is None:
        raise ValueError("entry symbol must be a C identifier")
    elf = ELFFile(BytesIO(native_bytes))
    if not elf.little_endian or elf.elfclass != 64 or elf["e_type"] != "ET_REL" or elf["e_machine"] != machine:
        raise ValueError(f"native request must be a little-endian {machine} relocatable ELF")
    table = elf.get_section_by_name(".symtab")
    entries = [] if table is None else [s for s in table.iter_symbols() if s.name == entry_symbol and s["st_info"]["type"] == "STT_FUNC" and type(s["st_shndx"]) is int]
    if len(entries) != 1 or not entries[0]["st_size"]:
        raise ValueError("native entry must name exactly one defined nonempty function")
    entry = entries[0]
    section = elf.get_section(entry["st_shndx"])
    if not section["sh_flags"] & 4 or entry["st_value"] + entry["st_size"] > section["sh_size"]:
        raise ValueError("native entry must lie wholly in executable section bytes")
