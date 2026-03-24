from __future__ import annotations

import json
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Any

import yaml

from . import ROOT_DIR, ensure_parent


def _read_log_tail(path: Path, *, limit: int = 16384) -> str:
    if not path.exists():
        return ""
    try:
        size = path.stat().st_size
        with path.open("rb") as handle:
            if size > limit:
                handle.seek(-limit, 2)
            payload = handle.read().decode("utf-8", errors="replace")
    except OSError:
        return ""
    return payload


def run_batch_runner(
    runner_binary: Path | str,
    *,
    spec_payload: dict[str, Any],
    timeout_seconds: int | float | None = None,
    cwd: Path | None = None,
    temp_dir: Path | None = None,
    capture_logs: bool = False,
    write_progress: bool = False,
) -> dict[str, Any]:
    base_dir = temp_dir or (ROOT_DIR / "docs" / "tmp")
    base_dir.mkdir(parents=True, exist_ok=True)

    with tempfile.TemporaryDirectory(prefix="runner-batch-", dir=base_dir) as tmpdir:
        tmp_path = Path(tmpdir)
        spec_path = tmp_path / "spec.yaml"
        result_path = tmp_path / "result.json"
        progress_path = tmp_path / "progress.json"
        stdout_path = tmp_path / "stdout.log"
        stderr_path = tmp_path / "stderr.log"

        spec_path.write_text(yaml.safe_dump(spec_payload, sort_keys=False), encoding="utf-8")
        command = [
            str(runner_binary),
            "run-batch",
            "--spec",
            str(spec_path),
            "--result-json",
            str(result_path),
        ]
        if write_progress:
            command.extend(["--progress-json", str(progress_path)])

        started = time.perf_counter()
        stdout = ""
        stderr = ""
        with stdout_path.open("w", encoding="utf-8") as stdout_handle, stderr_path.open(
            "w", encoding="utf-8"
        ) as stderr_handle:
            try:
                completed = subprocess.run(
                    command,
                    cwd=cwd or ROOT_DIR,
                    stdout=stdout_handle,
                    stderr=stderr_handle,
                    text=True,
                    timeout=timeout_seconds,
                    check=False,
                )
                timed_out = False
                returncode = completed.returncode
            except subprocess.TimeoutExpired:
                timed_out = True
                returncode = None

        if capture_logs or timed_out or returncode not in (0, 2, None):
            stdout = _read_log_tail(stdout_path)
            stderr = _read_log_tail(stderr_path)

        payload = None
        if result_path.exists():
            payload = json.loads(result_path.read_text(encoding="utf-8"))
        progress_payload = None
        if write_progress and progress_path.exists():
            progress_payload = json.loads(progress_path.read_text(encoding="utf-8"))

        completed_with_job_errors = returncode == 2
        ok = (returncode in (0, 2)) and not timed_out and payload is not None
        error = None
        if timed_out:
            error = f"batch runner timed out after {timeout_seconds} seconds"
        elif returncode not in (0, 2, None):
            error = f"batch runner exited with code {returncode}"

        return {
            "ok": ok,
            "completed_with_job_errors": completed_with_job_errors,
            "returncode": returncode,
            "timed_out": timed_out,
            "duration_seconds": time.perf_counter() - started,
            "stdout": stdout,
            "stderr": stderr,
            "error": error,
            "result": payload,
            "progress": progress_payload,
        }


def write_batch_spec(path: Path, payload: dict[str, Any]) -> None:
    ensure_parent(path)
    path.write_text(yaml.safe_dump(payload, sort_keys=False), encoding="utf-8")


__all__ = [
    "run_batch_runner",
    "write_batch_spec",
]
