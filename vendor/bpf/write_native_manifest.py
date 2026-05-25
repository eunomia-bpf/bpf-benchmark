#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
from collections import defaultdict
from pathlib import Path


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
    args = parser.parse_args()

    output: Path = args.output
    entries_by_key: dict[tuple[object, ...], set[str]] = defaultdict(set)
    native_object_by_key: dict[tuple[object, ...], str] = {}
    selected_by_program: dict[tuple[object, ...], tuple[str, set[str]]] = {}
    for raw in args.object:
        obj, attrs = parse_object_spec(raw)
        rel = rel_object(output, obj)
        prefixes = attrs.get("source_map_prefixes") or [None]
        for symbol in text_symbols(args.llvm_nm, obj, tuple(args.skip_prefix)):
            program = symbol[:15]
            for prefix in prefixes:
                if args.dedupe_program == "last":
                    key = (program, attrs.get("prog_type"), prefix)
                    if key not in selected_by_program or selected_by_program[key][0] != rel:
                        selected_by_program[key] = (rel, set())
                    selected_by_program[key][1].add(symbol)
                else:
                    key = (program, rel, attrs.get("prog_type"), prefix)
                    native_object_by_key[key] = rel
                    entries_by_key[key].add(symbol)

    if args.dedupe_program == "last":
        for key, (rel, symbols) in selected_by_program.items():
            program, prog_type, prefix = key
            out_key = (program, rel, prog_type, prefix)
            native_object_by_key[out_key] = rel
            entries_by_key[out_key].update(symbols)

    objects: list[dict[str, object]] = []
    for key in sorted(entries_by_key):
        program, rel, prog_type, prefix = key
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
