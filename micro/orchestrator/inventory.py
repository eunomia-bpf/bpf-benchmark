from __future__ import annotations

import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Mapping, Protocol

from .commands import build_list_programs_command
from .results import parse_last_json_line


@dataclass(frozen=True, slots=True)
class ProgramInventoryEntry:
    name: str
    section_name: str
    insn_count: int
    prog_type: int
    expected_attach_type: int
    prog_type_name: str
    attach_type_name: str
    object_path: Path | None = None


@dataclass(frozen=True, slots=True)
class TargetInventoryEntry:
    kind: str
    target_name: str
    object_path: Path
    program_name: str | None = None
    section_name: str | None = None
    io_mode: str | None = None
    input_size: int | None = None


class MicroBenchmarkLike(Protocol):
    name: str
    program_object: Path
    io_mode: str
    kernel_input_size: int


def _to_program_entry(record: Mapping[str, object], *, object_path: Path | None = None) -> ProgramInventoryEntry:
    return ProgramInventoryEntry(
        name=str(record.get("name", "")),
        section_name=str(record.get("section_name", "")),
        insn_count=int(record.get("insn_count", 0) or 0),
        prog_type=int(record.get("prog_type", 0) or 0),
        expected_attach_type=int(record.get("expected_attach_type", 0) or 0),
        prog_type_name=str(record.get("prog_type_name", "")),
        attach_type_name=str(record.get("attach_type_name", "")),
        object_path=object_path,
    )


def parse_program_inventory(stdout: str, *, object_path: Path | None = None) -> list[ProgramInventoryEntry]:
    payload = parse_last_json_line(stdout, label="list-programs")
    if not isinstance(payload, list):
        raise RuntimeError("list-programs output was not a JSON array")
    return [_to_program_entry(record, object_path=object_path) for record in payload if isinstance(record, dict)]


def discover_object_programs(
    runner_binary: Path | str,
    object_path: Path | str,
    *,
    timeout_seconds: int = 180,
) -> list[ProgramInventoryEntry]:
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
    return parse_program_inventory(completed.stdout, object_path=resolved_object)


def inventory_for_micro_benchmarks(benchmarks: Iterable[MicroBenchmarkLike]) -> list[TargetInventoryEntry]:
    return [
        TargetInventoryEntry(
            kind="micro",
            target_name=benchmark.name,
            object_path=benchmark.program_object,
            program_name=benchmark.name,
            io_mode=benchmark.io_mode,
            input_size=benchmark.kernel_input_size,
        )
        for benchmark in benchmarks
    ]


def inventory_for_corpus_object(
    runner_binary: Path | str,
    object_path: Path | str,
    *,
    timeout_seconds: int = 180,
) -> list[TargetInventoryEntry]:
    resolved_object = Path(object_path).resolve()
    return [
        TargetInventoryEntry(
            kind="corpus",
            target_name=entry.name,
            object_path=resolved_object,
            program_name=entry.name,
            section_name=entry.section_name,
        )
        for entry in discover_object_programs(
            runner_binary,
            resolved_object,
            timeout_seconds=timeout_seconds,
        )
    ]


def load_corpus_paths_from_build_report(report_path: Path) -> tuple[list[Path], str]:
    payload = json.loads(report_path.read_text())
    summary = payload.get("summary") or {}
    object_paths = summary.get("compiled_objects") or []
    if not object_paths:
        object_paths = [
            record["object_path"]
            for record in payload.get("records", [])
            if record.get("status") == "ok" and record.get("object_path")
        ]

    seen: set[Path] = set()
    resolved: list[Path] = []
    for raw_path in object_paths:
        path = Path(raw_path).resolve()
        if path in seen or not path.exists():
            continue
        seen.add(path)
        resolved.append(path)
    return sorted(resolved), f"expanded build report `{report_path}`"


def collect_corpus_object_paths(
    repo_root: Path,
    *,
    corpus_build_report: Path | None = None,
) -> tuple[list[Path], str]:
    report_path = corpus_build_report
    if report_path is None:
        candidate = repo_root / "corpus" / "results" / "expanded_corpus_build.json"
        if candidate.exists():
            report_path = candidate

    if report_path is not None and report_path.exists():
        return load_corpus_paths_from_build_report(report_path.resolve())

    return sorted((repo_root / "corpus").rglob("*.bpf.o")), "filesystem scan under `corpus/`"


__all__ = [
    "ProgramInventoryEntry",
    "TargetInventoryEntry",
    "collect_corpus_object_paths",
    "discover_object_programs",
    "inventory_for_corpus_object",
    "inventory_for_micro_benchmarks",
    "load_corpus_paths_from_build_report",
    "parse_program_inventory",
]
