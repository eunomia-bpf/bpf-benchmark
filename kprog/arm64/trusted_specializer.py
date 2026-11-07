"""AArch64 generation worker for the kernel-backed trusted specializer.

The common service supplies kernel-copied native bytes and normalized metadata
whose program/map identities it checked against the pinned source program.
Transport, capability registration, proof upload and request binding belong to
that service. This module only generates fresh artifacts in its private job dir.
"""
from __future__ import annotations

import hashlib
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog/arm64/micro-prog"))
_SPEC = importlib.util.spec_from_file_location("kprog_arm64_trusted_generator",
    ROOT / "kprog/arm64/micro-prog/generate_micro_sim_proofs.py")
gen = importlib.util.module_from_spec(_SPEC)
sys.modules[_SPEC.name] = gen
_SPEC.loader.exec_module(gen)


def _u32(value, field):
    if type(value) is not int or not 0 <= value <= 0xffffffff:
        raise ValueError(f"{field} must be an unsigned 32-bit integer")
    return value


def _declarations(metadata):
    if type(metadata) is not dict or set(metadata) != {"version", "prog_type", "section", "maps"}:
        raise ValueError("ARM metadata requires only version, prog_type, section and maps")
    if type(metadata["version"]) is not int or metadata["version"] != 1:
        raise ValueError("ARM metadata version must be 1")
    prog_type = _u32(metadata["prog_type"], "prog_type")
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
            _u32(item[field], f"{label}.{field}")
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


def specialize(native_bytes: bytes, entry_symbol: str, metadata: dict,
               output_dir: Path, native_link: Path) -> dict:
    """Generate from one immutable native request, without any proof/source input.

    ``metadata`` is the generation view, normalized by the common trusted
    service from the pinned program/maps. It has no paths, C or compiler flags.
    The returned paths are freshly created worker outputs, never producer paths.
    """
    if not isinstance(native_bytes, bytes) or not native_bytes:
        raise ValueError("native request must contain ELF bytes")
    if not isinstance(entry_symbol, str) or re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", entry_symbol) is None:
        raise ValueError("entry symbol must be a C identifier")
    declarations, names = _declarations(metadata)
    output_dir = Path(output_dir).resolve()
    output_dir.mkdir(parents=True, mode=0o700)
    native = output_dir / "request.native.o"
    native.write_bytes(native_bytes)
    with native.open("rb") as stream:
        elf = ELFFile(stream)
        if not elf.little_endian or elf.elfclass != 64 or elf["e_type"] != "ET_REL" or elf["e_machine"] != "EM_AARCH64":
            raise ValueError("native request must be a little-endian AArch64 relocatable ELF")
        table = elf.get_section_by_name(".symtab")
        entries = [] if table is None else [s for s in table.iter_symbols() if s.name == entry_symbol and s["st_info"]["type"] == "STT_FUNC" and type(s["st_shndx"]) is int]
        if len(entries) != 1 or not entries[0]["st_size"]:
            raise ValueError("native entry must name exactly one defined nonempty function")
    declarations_file = output_dir / "maps.h"
    declarations_file.write_text(declarations)
    name = "trusted_arm64"
    native_proof = output_dir / (name + ".proof.o")

    def run(command):
        command = [str(x) for x in command]
        result = subprocess.run(command, text=True, capture_output=True)
        with (output_dir / "commands.jsonl").open("a") as log:
            log.write(json.dumps(dict(command=command, returncode=result.returncode,
                                     stdout=result.stdout, stderr=result.stderr)) + "\n")
        result.check_returncode()

    run([native_link, "--input", native, "--symbol", entry_symbol,
         "--mode", "proof", "--preserve-entry-abi", "--output", native_proof])
    functions, rodata = gen.parse_native_linked_program(gen.Bench(name, entry_symbol, "raw"), output_dir)
    kind = {6: "xdp", 3: "tc", 8: "cgroup_skb"}.get(metadata["prog_type"], "raw")
    source = output_dir / (name + ".bpf.c")
    text = gen.render_program(name, entry_symbol, functions, kind, rodata16=rodata,
        linked_exit=True, program_section=metadata["section"],
        original_source=declarations_file, original_symbols=names)
    text = text.replace('#include "../arm64_sim_local_bpf.h"',
                        '#include ' + json.dumps(str(ROOT / "kprog/arm64/arm64_sim_local_bpf.h")))
    source.write_text(text)
    obj = output_dir / (name + ".bpf.o")
    run(["clang", "-g", "-O2", "-mcpu=v4", "-target", "bpf",
         "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_arm64",
         "-I", ROOT / "vendor/libbpf/include/uapi", "-I", ROOT / "vendor/libbpf/src",
         "-I", "/usr/include/x86_64-linux-gnu", "-c", source, "-o", obj])
    result = dict(native_object=str(native), native_proof_object=str(native_proof),
        simulator_object=str(obj), simulator_program=name + "_arm64_sim_xdp",
        symbol=entry_symbol, native_sha256=hashlib.sha256(native_bytes).hexdigest())
    (output_dir / "artifacts.json").write_text(json.dumps(result, indent=2) + "\n")
    return result
