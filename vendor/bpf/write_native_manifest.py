#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
from collections import defaultdict
from pathlib import Path
from typing import Iterable


BPF_LD_IMM64 = 0x18
BPF_CALL = 0x85


def source_object_for_native(root: Path, native_obj: Path) -> Path:
    name = native_obj.name
    if not name.endswith(".native.o"):
        raise SystemExit(f"cannot infer source BPF object for {native_obj}")
    return root / f"{name[:-len('.native.o')]}.o"


def scan_bpf_source_helpers(source_obj: Path) -> dict[str, set[int]]:
    try:
        from elftools.elf.elffile import ELFFile
    except ImportError as exc:
        raise SystemExit("pyelftools is required for --source-object-root") from exc

    by_program: dict[str, set[int]] = defaultdict(set)
    with source_obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise SystemExit(f"source BPF object has no .symtab: {source_obj}")
        for sym in symtab.iter_symbols():
            info = sym["st_info"]
            if info["type"] != "STT_FUNC" or info["bind"] not in {"STB_GLOBAL", "STB_WEAK"}:
                continue
            if not isinstance(sym["st_shndx"], int):
                continue
            section = elf.get_section(sym["st_shndx"])
            if section is None or not (section["sh_flags"] & 0x4):
                continue
            data = section.data()
            start = int(sym["st_value"])
            size = int(sym["st_size"])
            if size <= 0:
                continue
            end = start + size
            if start < 0 or end > len(data) or size % 8 != 0:
                raise SystemExit(f"invalid BPF function bounds for {sym.name} in {source_obj}")
            helpers = by_program[sym.name[:15]]
            body = data[start:end]
            for off in range(0, len(body), 8):
                insn = body[off:off + 8]
                if insn[0] == BPF_CALL and insn[1] == 0:
                    helpers.add(int.from_bytes(insn[4:8], "little", signed=True))
                elif insn[0] == BPF_LD_IMM64:
                    # Skip the second half of an ldimm64 pair.
                    continue
    return by_program


def helper_signature(helpers: set[int] | None, ids: Iterable[int]) -> tuple[tuple[int, ...], tuple[int, ...]]:
    if helpers is None:
        return (), ()
    required = tuple(sorted(helper for helper in ids if helper in helpers))
    forbidden = tuple(sorted(helper for helper in ids if helper not in helpers))
    return required, forbidden


def parse_object_spec(raw: str) -> tuple[Path, dict[str, object]]:
    parts = raw.split(",")
    if not parts or not parts[0]:
        raise SystemExit("--object requires a native object path")
    path = Path(parts[0])
    attrs: dict[str, object] = {}
    for part in parts[1:]:
        key, sep, value = part.partition("=")
        if sep != "=" or not key or not value:
            raise SystemExit(f"invalid --object attribute: {part!r}")
        if key == "prog_type":
            attrs["prog_type"] = int(value, 0)
        elif key == "source_map_prefix":
            attrs.setdefault("source_map_prefixes", []).append(value)
        else:
            raise SystemExit(f"unsupported --object attribute: {key}")
    return path, attrs


def text_symbols(llvm_nm: str, obj: Path, skip_prefixes: tuple[str, ...]) -> list[str]:
    completed = subprocess.run(
        [llvm_nm, "--defined-only", "--format=posix", str(obj)],
        check=True,
        capture_output=True,
        text=True,
    )
    out: list[str] = []
    for line in completed.stdout.splitlines():
        fields = line.split()
        if len(fields) < 2 or fields[1] not in {"T", "t"}:
            continue
        symbol = fields[0]
        if any(symbol.startswith(prefix) for prefix in skip_prefixes):
            continue
        out.append(symbol)
    if not out:
        raise SystemExit(f"no native text symbols in {obj}")
    return out


def rel_object(output: Path, obj: Path) -> str:
    try:
        return str(obj.resolve().relative_to(output.parent.resolve()))
    except ValueError:
        return str(obj)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--app", required=True)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--llvm-nm", required=True)
    parser.add_argument("--object", action="append", required=True)
    parser.add_argument("--skip-prefix", action="append", default=["LBB", "__check_"])
    parser.add_argument("--dedupe-program", choices=("none", "last"), default="none")
    parser.add_argument("--source-object-root", type=Path)
    parser.add_argument("--helper-disambiguate", action="append", type=lambda v: int(v, 0), default=[])
    args = parser.parse_args()

    output: Path = args.output
    entries_by_key: dict[tuple[object, ...], set[str]] = defaultdict(set)
    native_object_by_key: dict[tuple[object, ...], str] = {}
    helper_require_by_key: dict[tuple[object, ...], tuple[int, ...]] = {}
    helper_forbid_by_key: dict[tuple[object, ...], tuple[int, ...]] = {}
    selected_by_program: dict[tuple[object, ...], tuple[str, set[str]]] = {}
    selected_helpers_by_program: dict[tuple[object, ...], tuple[tuple[int, ...], tuple[int, ...]]] = {}
    source_helpers_cache: dict[Path, dict[str, set[int]]] = {}
    for raw in args.object:
        obj, attrs = parse_object_spec(raw)
        rel = rel_object(output, obj)
        source_helpers: dict[str, set[int]] | None = None
        if args.source_object_root:
            source_obj = source_object_for_native(args.source_object_root, obj)
            if not source_obj.is_file():
                raise SystemExit(f"source BPF object not found for {obj}: {source_obj}")
            source_helpers = source_helpers_cache.setdefault(
                source_obj, scan_bpf_source_helpers(source_obj))
        prefixes = attrs.get("source_map_prefixes") or [None]
        for symbol in text_symbols(args.llvm_nm, obj, tuple(args.skip_prefix)):
            program = symbol[:15]
            required, forbidden = helper_signature(
                None if source_helpers is None else source_helpers.get(program),
                args.helper_disambiguate)
            for prefix in prefixes:
                if args.dedupe_program == "last":
                    key = (program, attrs.get("prog_type"), prefix, required, forbidden)
                    if key not in selected_by_program or selected_by_program[key][0] != rel:
                        selected_by_program[key] = (rel, set())
                        selected_helpers_by_program[key] = (required, forbidden)
                    selected_by_program[key][1].add(symbol)
                else:
                    key = (program, rel, attrs.get("prog_type"), prefix, required, forbidden)
                    native_object_by_key[key] = rel
                    helper_require_by_key[key] = required
                    helper_forbid_by_key[key] = forbidden
                    entries_by_key[key].add(symbol)

    if args.dedupe_program == "last":
        for key, (rel, symbols) in selected_by_program.items():
            program, prog_type, prefix, required, forbidden = key
            out_key = (program, rel, prog_type, prefix, required, forbidden)
            native_object_by_key[out_key] = rel
            helper_require_by_key[out_key] = selected_helpers_by_program[key][0]
            helper_forbid_by_key[out_key] = selected_helpers_by_program[key][1]
            entries_by_key[out_key].update(symbols)

    objects: list[dict[str, object]] = []
    for key in sorted(entries_by_key):
        program, rel, prog_type, prefix, _required, _forbidden = key
        symbols = sorted(entries_by_key[key])
        entry: dict[str, object] = {
            "program": program,
            "native_object": native_object_by_key[key],
        }
        if len(symbols) == 1:
            entry["symbol"] = symbols[0]
        if prog_type is not None:
            entry["prog_type"] = prog_type
        if prefix is not None:
            entry["source_map_prefix"] = prefix
        required = helper_require_by_key.get(key, ())
        forbidden = helper_forbid_by_key.get(key, ())
        if required:
            if len(required) != 1:
                raise SystemExit("manifest supports one required helper discriminator")
            entry["source_has_helper"] = required[0]
        if forbidden:
            if len(forbidden) != 1:
                raise SystemExit("manifest supports one forbidden helper discriminator")
            entry["source_lacks_helper"] = forbidden[0]
        objects.append(entry)

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(
        json.dumps(
            {
                "version": 1,
                "app": args.app,
                "status": "native-objects-proof-linked",
                "objects": objects,
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )


if __name__ == "__main__":
    main()
