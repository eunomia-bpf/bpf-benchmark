#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ROOT_DIR, write_json  # noqa: E402


_HEX_RE = re.compile(r"^[0-9a-f]*$")


@dataclass(frozen=True, slots=True)
class ProgramSpec:
    prog_id: int
    repo: str
    object_name: str
    program_name: str
    qualified_prog_name: str | None = None


@dataclass(frozen=True, slots=True)
class InlineMapEntry:
    map_id: int
    key_hex: str
    value_hex: str


@dataclass(frozen=True, slots=True)
class InlineCaptureProgram:
    prog_id: int
    kernel_prog_name: str
    inlined_map_entries: tuple[InlineMapEntry, ...]


def _sanitize_segment(value: str) -> str:
    sanitized = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip())
    return sanitized or "unknown"


def _normalize_hex(value: object, *, field_name: str) -> str:
    text = str(value or "").strip().lower()
    if text.startswith("0x"):
        text = text[2:]
    if len(text) % 2 != 0 or _HEX_RE.fullmatch(text) is None:
        raise ValueError(f"invalid {field_name}: {value!r}")
    return text


def _normalize_spec_record(raw: Mapping[str, object]) -> ProgramSpec:
    prog_id = int(raw.get("prog_id", 0) or 0)
    repo = str(raw.get("repo", "live") or "live")
    object_name = str(raw.get("object", "unknown") or "unknown")
    program_name = str(raw.get("program", f"prog_{prog_id}") or f"prog_{prog_id}")
    qualified = raw.get("qualified_prog_name")
    qualified_name = None if qualified in (None, "") else str(qualified)
    if prog_id <= 0:
        raise ValueError(f"invalid program spec: {raw}")
    return ProgramSpec(
        prog_id=prog_id,
        repo=repo,
        object_name=object_name,
        program_name=program_name,
        qualified_prog_name=qualified_name,
    )


def load_program_specs(path: Path | None) -> dict[int, ProgramSpec] | None:
    if path is None:
        return None
    payload = json.loads(path.read_text())
    if not isinstance(payload, list):
        raise RuntimeError(f"program spec file must contain a JSON array: {path}")
    specs: dict[int, ProgramSpec] = {}
    for item in payload:
        if not isinstance(item, Mapping):
            raise RuntimeError(f"program spec entry is not a JSON object: {item!r}")
        spec = _normalize_spec_record(item)
        specs[spec.prog_id] = spec
    return specs


def _normalize_inline_map_entry(raw: Mapping[str, object]) -> InlineMapEntry:
    map_id = int(raw.get("map_id", 0) or 0)
    if map_id <= 0:
        raise ValueError(f"invalid inline map entry: {raw}")
    return InlineMapEntry(
        map_id=map_id,
        key_hex=_normalize_hex(raw.get("key_hex", ""), field_name="key_hex"),
        value_hex=_normalize_hex(raw.get("value_hex", ""), field_name="value_hex"),
    )


def load_inline_capture_programs(path: Path) -> dict[int, InlineCaptureProgram]:
    payload = json.loads(path.read_text())
    if not isinstance(payload, list):
        raise RuntimeError(f"inline capture file must contain a JSON array: {path}")

    programs: dict[int, InlineCaptureProgram] = {}
    for item in payload:
        if not isinstance(item, Mapping):
            raise RuntimeError(f"inline capture entry is not a JSON object: {item!r}")
        prog_id = int(item.get("prog_id", 0) or 0)
        if prog_id <= 0:
            raise RuntimeError(f"invalid inline capture entry: {item!r}")
        raw_entries = item.get("inlined_map_entries", [])
        if not isinstance(raw_entries, list):
            raise RuntimeError(f"inlined_map_entries must be a JSON array for prog_id={prog_id}")
        normalized_entries: list[InlineMapEntry] = []
        for raw_entry in raw_entries:
            if not isinstance(raw_entry, Mapping):
                raise RuntimeError(
                    f"inline capture entry for prog_id={prog_id} contains a non-object value: {raw_entry!r}"
                )
            normalized_entries.append(_normalize_inline_map_entry(raw_entry))
        programs[prog_id] = InlineCaptureProgram(
            prog_id=prog_id,
            kernel_prog_name=str(item.get("kernel_prog_name") or f"prog_{prog_id}"),
            inlined_map_entries=tuple(normalized_entries),
        )
    return programs


def _default_program_spec(prog_id: int, kernel_prog_name: str) -> ProgramSpec:
    base_name = kernel_prog_name or f"prog_{prog_id}"
    safe_name = _sanitize_segment(base_name)
    return ProgramSpec(
        prog_id=prog_id,
        repo="live",
        object_name="unknown",
        program_name=safe_name,
        qualified_prog_name=f"live/unknown:{base_name}",
    )


def _program_fixture_path(fixture_root: Path, spec: ProgramSpec) -> Path:
    return (
        fixture_root
        / _sanitize_segment(spec.repo)
        / _sanitize_segment(spec.object_name)
        / f"{_sanitize_segment(spec.program_name)}.json"
    )


def _group_inlined_entries(
    entries: Sequence[InlineMapEntry],
) -> list[dict[str, object]]:
    entries_by_map: dict[int, dict[str, str]] = {}
    for entry in entries:
        entries_by_map.setdefault(entry.map_id, {})[entry.key_hex] = entry.value_hex

    return [
        {
            "map_id": map_id,
            "entries": [
                {"key_hex": key_hex, "value_hex": value_hex}
                for key_hex, value_hex in sorted(by_key.items())
            ],
        }
        for map_id, by_key in sorted(entries_by_map.items())
    ]


def capture_program(
    program: InlineCaptureProgram,
    spec: ProgramSpec,
    *,
    captured_from: str,
    fixture_root: Path,
) -> dict[str, object]:
    qualified_prog_name = (
        spec.qualified_prog_name
        or f"{spec.repo}/{spec.object_name}:{spec.program_name}"
    )
    fixture_path = _program_fixture_path(fixture_root, spec)
    maps_payload = _group_inlined_entries(program.inlined_map_entries)

    fixture_payload = {
        "prog_id": int(program.prog_id),
        "prog_name": qualified_prog_name,
        "kernel_prog_name": program.kernel_prog_name,
        "captured_from": captured_from,
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "maps": maps_payload,
    }
    write_json(fixture_path, fixture_payload)
    return {
        "prog_id": int(program.prog_id),
        "kernel_prog_name": program.kernel_prog_name,
        "prog_name": qualified_prog_name,
        "fixture_path": str(fixture_path.resolve()),
        "map_count": len(maps_payload),
        "inline_entry_count": len(program.inlined_map_entries),
        "map_errors": [],
    }


def capture_all_programs(
    *,
    captured_from: str,
    fixture_root: Path,
    program_specs: Mapping[int, ProgramSpec] | None,
    inline_capture_programs: Mapping[int, InlineCaptureProgram],
) -> dict[str, object]:
    programs_seen = len(inline_capture_programs)
    results: list[dict[str, object]] = []
    skipped_programs: list[dict[str, object]] = []
    errors: list[dict[str, object]] = []

    if program_specs is not None:
        requested_program_ids = sorted(int(prog_id) for prog_id in program_specs)
        for prog_id in sorted(inline_capture_programs):
            if prog_id not in program_specs:
                skipped_programs.append(
                    {"prog_id": int(prog_id), "reason": "not requested by program_specs"}
                )
    else:
        requested_program_ids = sorted(int(prog_id) for prog_id in inline_capture_programs)

    for prog_id in requested_program_ids:
        program = inline_capture_programs.get(prog_id)
        if program is None:
            skipped_programs.append(
                {
                    "prog_id": int(prog_id),
                    "reason": "requested program ID was not present in inline capture data",
                }
            )
            continue

        spec = (
            program_specs[prog_id]
            if program_specs is not None
            else _default_program_spec(prog_id, program.kernel_prog_name)
        )
        try:
            results.append(
                capture_program(
                    program,
                    spec,
                    captured_from=captured_from,
                    fixture_root=fixture_root,
                )
            )
        except Exception as exc:
            errors.append({"prog_id": int(prog_id), "error": str(exc)})

    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "captured_from": captured_from,
        "fixture_root": str(fixture_root.resolve()),
        "programs_seen": programs_seen,
        "programs_selected": len(requested_program_ids),
        "programs_written": len(results),
        "programs": results,
        "skipped_programs": skipped_programs,
        "errors": errors,
    }


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Write per-program map fixtures from daemon optimize inline-entry data."
    )
    parser.add_argument("--captured-from", required=True, help="Provenance label such as e2e/tracee.")
    parser.add_argument(
        "--fixture-root",
        default=str(ROOT_DIR / "corpus" / "fixtures"),
        help="Root directory where per-program fixtures will be written.",
    )
    parser.add_argument(
        "--program-specs",
        help="Optional JSON array of per-program output specs; when set, only those program IDs are captured.",
    )
    parser.add_argument(
        "--inline-capture-json",
        required=True,
        help="JSON array describing per-program daemon optimize results and inlined map entries.",
    )
    parser.add_argument(
        "--manifest-json",
        help="Optional path to also write the summary manifest as JSON.",
    )
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    fixture_root = Path(args.fixture_root).resolve()
    fixture_root.mkdir(parents=True, exist_ok=True)
    program_specs = load_program_specs(
        Path(args.program_specs).resolve() if args.program_specs else None
    )
    inline_capture_programs = load_inline_capture_programs(
        Path(args.inline_capture_json).resolve()
    )
    manifest = capture_all_programs(
        captured_from=str(args.captured_from),
        fixture_root=fixture_root,
        program_specs=program_specs,
        inline_capture_programs=inline_capture_programs,
    )
    if args.manifest_json:
        write_json(Path(args.manifest_json).resolve(), manifest)
    json.dump(manifest, sys.stdout, indent=2, sort_keys=True)
    sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
