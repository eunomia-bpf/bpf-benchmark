from __future__ import annotations

import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping

from .commands import build_list_programs_command
from .results import parse_last_json_line


@dataclass(frozen=True, slots=True)
class ProgramListingEntry:
    name: str
    section_name: str
    insn_count: int
    prog_type: int
    expected_attach_type: int
    prog_type_name: str
    attach_type_name: str
    object_path: Path | None = None


def _to_program_entry(record: Mapping[str, object], *, object_path: Path | None = None) -> ProgramListingEntry:
    return ProgramListingEntry(
        name=str(record.get("name", "")),
        section_name=str(record.get("section_name", "")),
        insn_count=int(record.get("insn_count", 0) or 0),
        prog_type=int(record.get("prog_type", 0) or 0),
        expected_attach_type=int(record.get("expected_attach_type", 0) or 0),
        prog_type_name=str(record.get("prog_type_name", "")),
        attach_type_name=str(record.get("attach_type_name", "")),
        object_path=object_path,
    )


def parse_program_listing(stdout: str, *, object_path: Path | None = None) -> list[ProgramListingEntry]:
    payload = parse_last_json_line(stdout, label="list-programs")
    if not isinstance(payload, list):
        raise RuntimeError("list-programs output was not a JSON array")
    return [_to_program_entry(record, object_path=object_path) for record in payload if isinstance(record, dict)]


def discover_object_programs(
    runner_binary: Path | str,
    object_path: Path | str,
    *,
    timeout_seconds: int = 180,
) -> list[ProgramListingEntry]:
    resolved_object = Path(object_path).resolve()
    command = build_list_programs_command(runner_binary, resolved_object)
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(command)}\n{details}")
    return parse_program_listing(completed.stdout, object_path=resolved_object)


__all__ = [
    "ProgramListingEntry",
    "discover_object_programs",
    "parse_program_listing",
]
