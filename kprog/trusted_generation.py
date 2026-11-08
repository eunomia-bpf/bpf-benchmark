"""Generation metadata shared by trusted ISA workers.

The service derives this view from kernel-pinned source/map identities.
These functions accept no producer paths, C source or compiler flags.
"""
from io import BytesIO
import re
import json
from elftools.elf.elffile import ELFFile

def elf_symbol(name):
    if not isinstance(name,str) or re.fullmatch(r"[A-Za-z_.$][A-Za-z0-9_.$]*",name) is None:
        raise ValueError("native symbol must be an explicit ELF identifier")
    return name


def c_symbol_aliases(names,prefix):
    """Keep ELF identities while giving dotted/static symbols legal C names."""
    names=list(names)
    for name in names:elf_symbol(name)
    if len(set(names))!=len(names):raise ValueError("duplicate native symbol")
    reserved=set(names);result={}
    for index,name in enumerate(names):
        if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*",name):result[name]=name
        else:
            candidate=prefix+str(index)
            while candidate in reserved:candidate+="_"
            reserved.add(candidate);result[name]=candidate
    return result


def u32(value, field):
    if type(value) is not int or not 0 <= value <= 0xffffffff:
        raise ValueError(f"{field} must be an unsigned 32-bit integer")
    return value


def declarations(metadata):
    prog_type = metadata["prog_type"]
    section = metadata["section"]
    lines = ["#include <linux/bpf.h>", "#include <bpf_helpers.h>"]
    names = set()
    c_names = c_symbol_aliases([item.get("name") if type(item) is dict else None for item in metadata["maps"]], "__trusted_map_decl_")
    fields = {"map_type", "key_size", "value_size", "max_entries", "map_flags"}
    inner_count = 0

    def emit(item, label, name=None, tag=None):
        nonlocal inner_count
        is_outer = item["map_type"] in {12, 13}
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
        if name is None:lines.append("};")
        else:
            alias = "" if c_names[name] == name else " __asm__(" + json.dumps(name) + ")"
            lines.append(f'}} {c_names[name]}{alias} SEC(".maps");')

    for index, item in enumerate(metadata["maps"]):
        name = item.get("name")
        if elf_symbol(name) in names:
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
    if not elf.little_endian or elf.elfclass != 64 or elf["e_type"] not in {"ET_REL", "ET_DYN"} or elf["e_machine"] != machine:
        raise ValueError(f"native request must be a little-endian {machine} relocatable or shared ELF")
    table = elf.get_section_by_name(".symtab")
    entries = [] if table is None else [s for s in table.iter_symbols() if s.name == entry_symbol and s["st_info"]["type"] == "STT_FUNC" and type(s["st_shndx"]) is int]
    if len(entries) != 1 or not entries[0]["st_size"]:
        raise ValueError("native entry must name exactly one defined nonempty function")
    entry = entries[0]
    section = elf.get_section(entry["st_shndx"])
    offset = entry["st_value"] - section["sh_addr"]
    if not section["sh_flags"] & 4 or offset < 0 or offset + entry["st_size"] > section["sh_size"]:
        raise ValueError("native entry must lie wholly in executable section bytes")
