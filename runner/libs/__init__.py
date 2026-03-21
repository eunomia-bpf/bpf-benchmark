from __future__ import annotations

import json
import os
import re
import shlex
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Sequence


ROOT_DIR = Path(__file__).resolve().parents[2]
RESULTS_DIR = ROOT_DIR / "e2e" / "results"
DEFAULT_BPFTOOL_CANDIDATES = (
    ROOT_DIR / "runner" / "build" / "vendor" / "bpftool" / "bpftool",
    Path("/usr/local/sbin/bpftool"),
)
DEFAULT_PERF_CANDIDATES = (
    ROOT_DIR / "vendor" / "linux-framework" / "tools" / "perf" / "perf",
)
RESULT_FILE_RE = re.compile(r"^(?P<suite>.+)_(?P<kind>authoritative|smoke)_(?P<date>\d{8})\.json$")
BPFTOOL_ENV_VARS = ("BPFTOOL_BIN", "BPFTOOL")
PERF_ENV_VARS = ("PERF_BIN", "PERF")


def _find_venv_activate() -> Path:
    candidates = [
        Path.home() / "workspace" / ".venv" / "bin" / "activate",
        Path.home() / ".venv" / "bin" / "activate",
        ROOT_DIR / ".venv" / "bin" / "activate",
        ROOT_DIR / "venv" / "bin" / "activate",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return candidates[0]


DEFAULT_VENV_ACTIVATE = _find_venv_activate()


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def result_date_stamp(now: datetime | None = None) -> str:
    current = now or datetime.now(timezone.utc)
    return current.astimezone(timezone.utc).strftime("%Y%m%d")


def authoritative_output_path(results_dir: Path, suite: str, *, stamp: str | None = None) -> Path:
    return results_dir / f"{suite}_authoritative_{stamp or result_date_stamp()}.json"


def smoke_output_path(results_dir: Path, suite: str, *, stamp: str | None = None) -> Path:
    return results_dir / f"{suite}_smoke_{stamp or result_date_stamp()}.json"


def latest_output_path(results_dir: Path, suite: str) -> Path:
    return results_dir / f"{suite}.latest.json"


def authoritative_candidates(results_dir: Path, suite: str) -> tuple[Path, ...]:
    latest = latest_output_path(results_dir, suite)
    dated = tuple(sorted(results_dir.glob(f"{suite}_authoritative_*.json"), reverse=True))
    return (latest, *dated)


def refresh_latest_alias(latest_path: Path, target_path: Path) -> None:
    _ = (latest_path, target_path)
    return


def maybe_refresh_latest_alias(path: Path) -> None:
    _ = path
    return


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


def resolve_perf_binary(*, required: bool = False) -> str | None:
    for env_var in PERF_ENV_VARS:
        candidate = os.environ.get(env_var, "")
        resolved = _resolve_explicit_binary(candidate)
        if resolved is None and candidate.strip():
            raise RuntimeError(f"{env_var} is set to {candidate!r}, but no executable was found")
        if resolved is not None:
            return resolved
    for candidate in DEFAULT_PERF_CANDIDATES:
        resolved = _resolve_explicit_binary(candidate)
        if resolved is not None:
            return resolved
    resolved = _resolve_explicit_binary("perf")
    if resolved is not None:
        return resolved
    if required:
        hints = ", ".join(PERF_ENV_VARS)
        raise RuntimeError(f"perf is required; run `make kernel-perf` or set {hints} to an explicit binary")
    return None


def prepare_bpftool_environment() -> str:
    resolved = resolve_bpftool_binary()
    os.environ["BPFTOOL_BIN"] = resolved
    bpftool_dir = str(Path(resolved).resolve().parent)
    current_path = os.environ.get("PATH", "")
    path_entries = [entry for entry in current_path.split(os.pathsep) if entry]
    if bpftool_dir not in path_entries:
        os.environ["PATH"] = bpftool_dir if not current_path else f"{bpftool_dir}{os.pathsep}{current_path}"
    return resolved


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


def chown_to_invoking_user(path: Path) -> None:
    uid_raw = os.environ.get("SUDO_UID")
    gid_raw = os.environ.get("SUDO_GID")
    if not uid_raw or not gid_raw:
        return
    try:
        os.chown(path, int(uid_raw), int(gid_raw))
    except OSError:
        return


def write_json(path: Path, payload: Any) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    maybe_refresh_latest_alias(path)
    chown_to_invoking_user(path)


def write_text(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)
    chown_to_invoking_user(path)


def sudo_available() -> bool:
    try:
        completed = subprocess.run(
            ["sudo", "-n", "true"],
            capture_output=True,
            text=True,
            check=False,
        )
    except OSError:
        return False
    return completed.returncode == 0


def ensure_root(argv: Sequence[str] | None = None) -> None:
    if os.geteuid() == 0:
        return
    if not sudo_available():
        raise SystemExit("passwordless sudo is required for benchmarking")
    script_argv = list(argv if argv is not None else sys.argv)
    sudo_cmd = ["sudo", "-n"]
    tmpdir = os.environ.get("TMPDIR", "").strip()
    if tmpdir:
        sudo_cmd.append(f"TMPDIR={tmpdir}")
    sudo_cmd.append(sys.executable)
    sudo_cmd.extend(script_argv)
    os.execvp("sudo", sudo_cmd)


__all__ = [
    "BPFTOOL_ENV_VARS",
    "DEFAULT_BPFTOOL_CANDIDATES",
    "DEFAULT_VENV_ACTIVATE",
    "RESULTS_DIR",
    "ROOT_DIR",
    "authoritative_candidates",
    "authoritative_output_path",
    "chown_to_invoking_user",
    "ensure_parent",
    "ensure_root",
    "latest_output_path",
    "maybe_refresh_latest_alias",
    "prepare_bpftool_environment",
    "refresh_latest_alias",
    "resolve_binary",
    "resolve_bpftool_binary",
    "result_date_stamp",
    "run_command",
    "run_json_command",
    "smoke_output_path",
    "sudo_available",
    "tail_text",
    "which",
    "write_json",
    "write_text",
]
