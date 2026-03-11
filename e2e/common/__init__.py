from __future__ import annotations

import json
import os
import shlex
import subprocess
import sys
from pathlib import Path
from typing import Any, Sequence


ROOT_DIR = Path(__file__).resolve().parents[2]
RESULTS_DIR = ROOT_DIR / "e2e" / "results"
DEFAULT_VENV_ACTIVATE = Path("/home/yunwei37/workspace/.venv/bin/activate")
BPFTOOL_ENV_VARS = ("BPFTOOL_BIN", "BPFTOOL")


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


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


def resolve_bpftool_binary() -> str:
    return resolve_binary("bpftool", env_vars=BPFTOOL_ENV_VARS)


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
    chown_to_invoking_user(path)


def write_text(path: Path, text: str) -> None:
    ensure_parent(path)
    path.write_text(text)
    chown_to_invoking_user(path)


def describe_command(command: Sequence[str]) -> str:
    return " ".join(shlex.quote(part) for part in command)


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
        raise SystemExit("passwordless sudo is required for e2e benchmarking")
    script_argv = list(argv if argv is not None else sys.argv)
    os.execvp("sudo", ["sudo", "-n", sys.executable, *script_argv])


__all__ = [
    "BPFTOOL_ENV_VARS",
    "DEFAULT_VENV_ACTIVATE",
    "RESULTS_DIR",
    "ROOT_DIR",
    "chown_to_invoking_user",
    "describe_command",
    "ensure_parent",
    "ensure_root",
    "resolve_binary",
    "resolve_bpftool_binary",
    "run_command",
    "run_json_command",
    "sudo_available",
    "tail_text",
    "which",
    "write_json",
    "write_text",
]
