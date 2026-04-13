from __future__ import annotations

import json
import os
import shlex
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Sequence


ROOT_DIR = Path(__file__).resolve().parents[2]
RESULTS_DIR = ROOT_DIR / "e2e" / "results"
DEFAULT_BPFTOOL_CANDIDATES = (
    ROOT_DIR / "vendor" / "linux-framework" / "tools" / "bpf" / "bpftool" / "bpftool",
    ROOT_DIR / "runner" / "build" / "vendor" / "bpftool" / "bpftool",
    Path("/usr/local/sbin/bpftool"),
)
BPFTOOL_ENV_VARS = ("BPFTOOL_BIN", "BPFTOOL")


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def scratch_date_stamp(now: datetime | None = None) -> str:
    current = now or datetime.now().astimezone()
    return current.astimezone().strftime("%Y%m%d")


def docs_tmp_dir(*parts: str | Path, stamp: str | None = None, ensure: bool = True) -> Path:
    path = ROOT_DIR / "docs" / "tmp" / (stamp or scratch_date_stamp())
    for part in parts:
        path /= str(part)
    if ensure:
        path.mkdir(parents=True, exist_ok=True)
    return path

def tail_text(text: str, *, max_lines: int = 12, max_chars: int = 4000) -> str:
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


def which(tool: str) -> str | None:
    from shutil import which as _which

    return _which(tool)


def resolve_binary(tool: str, *, env_vars: Sequence[str] = ()) -> str:
    for env_var in env_vars:
        candidate = os.environ.get(env_var, "").strip()
        if not candidate:
            continue
        resolved = which(candidate)
        if resolved is None:
            expanded = Path(candidate).expanduser()
            if expanded.is_file() and os.access(expanded, os.X_OK):
                resolved = str(expanded.resolve())
        if resolved is None:
            raise RuntimeError(f"{env_var} is set to {candidate!r}, but no executable was found")
        return resolved

    resolved = which(tool)
    if resolved is not None:
        return resolved

    hints = ", ".join(env_vars)
    if hints:
        raise RuntimeError(f"{tool} is required; set {hints} to an explicit binary if it is not on PATH")
    raise RuntimeError(f"{tool} is required")


def _resolve_explicit_binary(candidate: str | Path) -> str | None:
    candidate_text = str(candidate).strip()
    if not candidate_text:
        return None
    resolved = which(candidate_text)
    if resolved is not None:
        return resolved
    expanded = Path(candidate_text).expanduser()
    if expanded.is_file() and os.access(expanded, os.X_OK):
        return str(expanded.resolve())
    return None


def resolve_bpftool_binary() -> str:
    for env_var in BPFTOOL_ENV_VARS:
        candidate = os.environ.get(env_var, "")
        resolved = _resolve_explicit_binary(candidate)
        if resolved is None and candidate.strip():
            raise RuntimeError(f"{env_var} is set to {candidate!r}, but no executable was found")
        if resolved is not None:
            return resolved
    for candidate in DEFAULT_BPFTOOL_CANDIDATES:
        resolved = _resolve_explicit_binary(candidate)
        if resolved is not None:
            return resolved
    return resolve_binary("bpftool")


def run_command(
    command: Sequence[str],
    *,
    cwd: Path | None = None,
    env: dict[str, str] | None = None,
    capture_output: bool = True,
    text: bool = True,
    check: bool = True,
    timeout: int | float | None = None,
    pass_fds: Sequence[int] = (),
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        list(command),
        cwd=cwd or ROOT_DIR,
        env=env,
        capture_output=capture_output,
        text=text,
        check=False,
        timeout=timeout,
        pass_fds=tuple(pass_fds),
    )
    if check and completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout or "")
        rendered = " ".join(shlex.quote(part) for part in command)
        raise RuntimeError(f"command failed ({completed.returncode}): {rendered}\n{details}")
    return completed


def run_json_command(
    command: Sequence[str],
    *,
    cwd: Path | None = None,
    env: dict[str, str] | None = None,
    timeout: int | float | None = None,
) -> Any:
    completed = run_command(command, cwd=cwd, env=env, timeout=timeout)
    payload = completed.stdout.strip()
    if not payload:
        raise RuntimeError(f"command returned no JSON: {' '.join(command)}")
    return json.loads(payload)


def result_date_stamp(now: datetime | None = None) -> str:
    current = now or datetime.now(timezone.utc)
    return current.astimezone(timezone.utc).strftime("%Y%m%d")


def smoke_output_path(results_dir: Path, suite: str, *, stamp: str | None = None) -> Path:
    return results_dir / f"{suite}_smoke_{stamp or result_date_stamp()}.json"


def write_json(path: Path, payload: Any) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")


def write_text(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)

