from __future__ import annotations

import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Mapping

from elftools.elf.elffile import ELFFile

try:
    from . import authoritative_candidates
except ImportError:
    from runner.libs import authoritative_candidates

from .commands import build_list_programs_command
from .results import normalize_directive_scan, parse_last_json_line


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
class CorpusObjectDiscovery:
    corpus_paths: tuple[Path, ...]
    skipped_non_bpf: tuple[str, ...]
    corpus_source: str


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


def _is_bpf_machine(path: Path) -> bool:
    with path.open("rb") as handle:
        elf = ELFFile(handle)
        return int(elf.header["e_machine"]) == 247


def filter_bpf_object_paths(paths: Iterable[Path], repo_root: Path) -> tuple[list[Path], list[str]]:
    kept: list[Path] = []
    skipped: list[str] = []
    for path in paths:
        try:
            if _is_bpf_machine(path):
                kept.append(path)
                continue
        except Exception:
            pass
        skipped.append(path.relative_to(repo_root).as_posix())
    return kept, skipped


def collect_corpus_object_paths(
    repo_root: Path,
    *,
    corpus_build_report: Path | None = None,
) -> tuple[list[Path], str]:
    report_path = corpus_build_report
    if report_path is None:
        for candidate in authoritative_candidates(repo_root / "corpus" / "results", "expanded_corpus_build"):
            if candidate.exists():
                report_path = candidate
                break

    if report_path is not None and report_path.exists():
        return load_corpus_paths_from_build_report(report_path.resolve())

    return sorted((repo_root / "corpus").rglob("*.bpf.o")), "filesystem scan under `corpus/`"


def discover_corpus_objects(
    repo_root: Path,
    *,
    corpus_build_report: Path | None = None,
) -> CorpusObjectDiscovery:
    raw_paths, source = collect_corpus_object_paths(repo_root, corpus_build_report=corpus_build_report)
    corpus_paths, skipped = filter_bpf_object_paths(raw_paths, repo_root)
    return CorpusObjectDiscovery(
        corpus_paths=tuple(corpus_paths),
        skipped_non_bpf=tuple(sorted(skipped)),
        corpus_source=source,
    )


def load_packet_test_run_targets(
    inventory_json: Path,
    *,
    filters: list[str] | None = None,
    max_programs: int | None = None,
    require_inventory_sites: bool = False,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    payload = json.loads(inventory_json.read_text())
    selected: list[dict[str, Any]] = []
    for record in payload.get("programs", []):
        if not isinstance(record, Mapping):
            continue
        if record.get("strategy") != "packet_test_run":
            continue
        inventory_scan = normalize_directive_scan(record.get("directive_scan"))
        if require_inventory_sites and inventory_scan["total_sites"] <= 0:
            continue
        if not (record.get("baseline_run") or {}).get("ok"):
            continue
        selected.append(
            {
                "object_path": str(record["object_path"]),
                "source_name": str(record["source_name"]),
                "program_name": str(record["program_name"]),
                "section_name": str(record["section_name"]),
                "section_root": str(record.get("section_root") or ""),
                "prog_type_name": str(record.get("prog_type_name") or ""),
                "io_mode": str(record.get("io_mode") or "context"),
                "input_size": int(record.get("input_size") or 0),
                "memory_path": str(record["memory_path"]) if record.get("memory_path") else None,
                "can_test_run": True,
                "inventory_scan": inventory_scan,
                "inventory_speedup_ratio": record.get("speedup_ratio"),
                "inventory_baseline_exec_ns": ((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns"),
            }
        )

    if filters:
        lowered = [item.lower() for item in filters]
        selected = [
            record
            for record in selected
            if any(
                needle in record["object_path"].lower()
                or needle in record["program_name"].lower()
                or needle in record["source_name"].lower()
                or needle in record["section_name"].lower()
                or needle in record["prog_type_name"].lower()
                for needle in lowered
            )
        ]
    selected.sort(key=lambda item: (item["source_name"], item["object_path"], item["program_name"]))
    if max_programs is not None:
        selected = selected[:max_programs]

    return selected, dict(payload.get("summary") or {})


__all__ = [
    "CorpusObjectDiscovery",
    "ProgramInventoryEntry",
    "collect_corpus_object_paths",
    "discover_corpus_objects",
    "discover_object_programs",
    "filter_bpf_object_paths",
    "load_corpus_paths_from_build_report",
    "load_packet_test_run_targets",
    "parse_program_inventory",
]
