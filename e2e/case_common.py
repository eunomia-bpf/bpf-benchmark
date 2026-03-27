"""Shared helpers for e2e benchmark cases.

Consolidates utility functions that were previously copy-pasted across
tracee, tetragon, bpftrace, katran, and scx case files.
"""
from __future__ import annotations

import json
import platform
import statistics
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

from runner.libs import (
    ROOT_DIR,
    run_command,
    write_json,
    write_text,
)


# ---------------------------------------------------------------------------
# Path helpers
# ---------------------------------------------------------------------------

def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


def _program_names_match(live_name: str, object_program_name: str) -> bool:
    if not live_name or not object_program_name:
        return False
    return (
        live_name == object_program_name
        or object_program_name.startswith(live_name)
        or live_name.startswith(object_program_name)
    )


def build_map_capture_specs(
    live_programs: Sequence[Mapping[str, object]],
    *,
    repo_name: str,
    object_paths: Sequence[Path],
    runner_binary: Path | None = None,
) -> dict[str, object]:
    from runner.libs.object_discovery import discover_object_programs

    discovered_candidates: list[dict[str, str]] = []
    discovery_errors: list[str] = []
    if runner_binary is None or not runner_binary.exists():
        missing_runner = "not provided" if runner_binary is None else relpath(runner_binary)
        discovery_errors.append(f"runner binary unavailable for object discovery: {missing_runner}")
    else:
        for object_path in object_paths:
            try:
                listing = discover_object_programs(runner_binary, object_path)
            except Exception as exc:
                discovery_errors.append(f"{relpath(object_path)}: {exc}")
                continue
            for entry in listing:
                discovered_candidates.append(
                    {
                        "object_name": object_path.name,
                        "program_name": entry.name,
                    }
                )

    program_specs: list[dict[str, object]] = []
    unmatched_programs: list[str] = []
    ambiguous_programs: list[dict[str, object]] = []
    seen_targets: set[tuple[str, str, str]] = set()

    for program in live_programs:
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        live_name = str(program.get("name") or f"prog_{prog_id}")

        matches = [item for item in discovered_candidates if _program_names_match(live_name, item["program_name"])]
        exact_matches = [item for item in matches if item["program_name"] == live_name]
        selected: dict[str, str] | None = None

        if len(exact_matches) == 1:
            selected = exact_matches[0]
        elif len(matches) == 1:
            selected = matches[0]
        elif len(matches) > 1:
            ambiguous_programs.append(
                {
                    "prog_id": prog_id,
                    "live_name": live_name,
                    "matches": [f"{item['object_name']}:{item['program_name']}" for item in matches],
                }
            )
        else:
            unmatched_programs.append(live_name)

        object_name = "unknown"
        program_name = live_name
        if selected is not None:
            object_name = selected["object_name"]
            program_name = selected["program_name"]

        if (repo_name, object_name, program_name) in seen_targets:
            program_name = f"{program_name}_prog{prog_id}"
        seen_targets.add((repo_name, object_name, program_name))
        program_specs.append(
            {
                "prog_id": prog_id,
                "repo": repo_name,
                "object": object_name,
                "program": program_name,
                "qualified_prog_name": f"{repo_name}/{object_name}:{program_name}",
            }
        )

    return {
        "program_specs": program_specs,
        "discovered_object_paths": [relpath(path) for path in object_paths],
        "discovery_errors": discovery_errors,
        "unmatched_programs": unmatched_programs,
        "ambiguous_programs": ambiguous_programs,
    }


def capture_map_state(
    *,
    captured_from: str,
    program_specs: Sequence[Mapping[str, object]],
    optimize_results: Mapping[int, Mapping[str, object]],
    fixture_root: Path | None = None,
) -> dict[str, object]:
    if not program_specs:
        return {
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "captured_from": captured_from,
            "status": "skipped",
            "reason": "no program specs were provided for map capture",
            "programs_seen": 0,
            "programs_selected": 0,
            "programs_written": 0,
            "programs": [],
            "skipped_programs": [],
            "errors": [],
        }

    inline_capture_programs: list[dict[str, object]] = []
    normalized_results: list[tuple[int, Mapping[str, object]]] = []
    for raw_prog_id, raw_result in optimize_results.items():
        if not isinstance(raw_result, Mapping):
            continue
        normalized_results.append((int(raw_prog_id), raw_result))

    for prog_id, result in sorted(normalized_results, key=lambda item: item[0]):
        kernel_prog_name = str(result.get("kernel_prog_name") or f"prog_{prog_id}")
        raw_entries = result.get("inlined_map_entries")
        inlined_map_entries = (
            [dict(entry) for entry in raw_entries if isinstance(entry, Mapping)]
            if isinstance(raw_entries, list)
            else []
        )
        inline_capture_programs.append(
            {
                "prog_id": prog_id,
                "kernel_prog_name": kernel_prog_name,
                "inlined_map_entries": inlined_map_entries,
            }
        )

    fixture_dir = fixture_root or (ROOT_DIR / "corpus" / "fixtures")
    script_path = ROOT_DIR / "runner" / "scripts" / "capture_map_state.py"
    if not script_path.exists():
        raise RuntimeError(f"map capture script is missing: {script_path}")

    with tempfile.TemporaryDirectory(prefix="map-capture-") as tempdir:
        tempdir_path = Path(tempdir)
        spec_path = tempdir_path / "program_specs.json"
        inline_capture_path = tempdir_path / "inline_capture.json"
        write_json(spec_path, list(program_specs))
        write_json(inline_capture_path, inline_capture_programs)
        command = [
            sys.executable or "python3",
            str(script_path),
            "--captured-from",
            captured_from,
            "--fixture-root",
            str(fixture_dir),
            "--program-specs",
            str(spec_path),
            "--inline-capture-json",
            str(inline_capture_path),
        ]
        completed = run_command(command, timeout=600)

    payload = json.loads(completed.stdout)
    if not isinstance(payload, dict):
        raise RuntimeError("map capture script returned a non-object JSON payload")
    return payload


# ---------------------------------------------------------------------------
# Provenance helpers
# ---------------------------------------------------------------------------

def git_sha() -> str:
    """Return the current HEAD commit hash, or 'unknown' on failure."""
    try:
        return run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    except Exception:
        return "unknown"


def host_metadata() -> dict[str, object]:
    """Collect basic host information for result provenance."""
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha(),
    }


# ---------------------------------------------------------------------------
# Statistical helpers
# ---------------------------------------------------------------------------

def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    """Compute count/mean/median/min/max over non-None numeric values."""
    filtered = [float(value) for value in values if value is not None]
    if not filtered:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
        }
    return {
        "count": len(filtered),
        "mean": statistics.mean(filtered),
        "median": statistics.median(filtered),
        "min": min(filtered),
        "max": max(filtered),
    }


def percent_delta(before: object, after: object) -> float | None:
    """Compute percentage change from *before* to *after*."""
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def percentile(values: Sequence[float], pct: float) -> float | None:
    """Linear-interpolation percentile over a sequence of floats."""
    items = sorted(float(value) for value in values)
    if not items:
        return None
    if len(items) == 1:
        return items[0]
    rank = max(0.0, min(1.0, pct / 100.0)) * (len(items) - 1)
    lower = int(rank)
    upper = min(len(items) - 1, lower + 1)
    weight = rank - lower
    return items[lower] * (1.0 - weight) + items[upper] * weight


def speedup_ratio(before: object, after: object) -> float | None:
    """Return before/after as a speedup multiplier, or None."""
    if before in (None, 0) or after in (None, 0):
        return None
    return float(before) / float(after)


# ---------------------------------------------------------------------------
# Result persistence
# ---------------------------------------------------------------------------

def persist_results(
    payload: Mapping[str, object],
    output_json: Path,
    output_md: Path,
    build_markdown: object,
) -> None:
    """Write JSON + markdown results and fix ownership.

    *build_markdown* must be a callable ``(payload) -> str`` supplied by
    the individual case, since each case has its own markdown format.
    """
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))  # type: ignore[operator]
