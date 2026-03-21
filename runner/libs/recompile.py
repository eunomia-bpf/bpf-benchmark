"""BpfReJIT v2 REJIT helpers.

This module provides the Python-side interface for the v2 REJIT syscall path.
The v1 scanner/policy-blob recompile logic has been removed.
"""
from __future__ import annotations

import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(frozen=True, slots=True)
class RejitTarget:
    prog_id: int
    rejit_program: str | None = None  # optional replacement ELF path


def enumerate_program_record(
    scanner: Path | str,
    prog_id: int,
    *,
    timeout_seconds: int = 60,
) -> dict[str, Any]:
    """Run daemon enumerate --prog-id <prog_id> --all --json and return the parsed record.

    Returns a dict with keys such as ``name``, ``total_sites``, ``sites``, and ``type``.
    Raises RuntimeError on non-zero exit or unparseable output.
    """
    command = [
        str(scanner),
        "enumerate",
        "--prog-id",
        str(prog_id),
        "--all",
        "--json",
    ]
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(
            f"enumerate --prog-id {prog_id} failed (rc={completed.returncode}): {detail}"
        )
    stdout = completed.stdout.strip()
    if not stdout:
        raise RuntimeError(f"enumerate --prog-id {prog_id} produced no output")
    # Accept the last non-empty line as JSON (daemon may emit progress lines first)
    for line in reversed(stdout.splitlines()):
        line = line.strip()
        if not line:
            continue
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(payload, dict):
            return payload
    raise RuntimeError(
        f"enumerate --prog-id {prog_id} output did not contain a JSON object:\n{stdout[:2000]}"
    )


def scan_programs(
    prog_ids: list[int],
    scanner: Path | str,
    *,
    prog_fds: dict[int, int] | None = None,
    timeout_seconds: int = 60,
) -> dict[int, dict[str, Any]]:
    """Run enumerate_program_record for each prog_id in prog_ids.

    Returns a dict mapping prog_id to the enumerate record dict.
    Silently omits entries where enumeration fails.
    """
    results: dict[int, dict[str, Any]] = {}
    for prog_id in prog_ids:
        try:
            record = enumerate_program_record(scanner, prog_id, timeout_seconds=timeout_seconds)
            results[prog_id] = {"enumerate_record": record}
        except Exception:
            pass
    return results


__all__ = [
    "RejitTarget",
    "enumerate_program_record",
    "scan_programs",
]
