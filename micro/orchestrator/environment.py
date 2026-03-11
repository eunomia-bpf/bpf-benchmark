from __future__ import annotations

import subprocess
import sys
from pathlib import Path
from typing import Mapping, Sequence


def read_required_text(path: str | Path) -> str:
    return Path(path).read_text().strip()


def read_optional_text(path: str | Path, default: str = "unknown") -> str:
    try:
        return Path(path).read_text().strip()
    except OSError:
        return default


def resolve_path(value: str | Path, base_dir: str | Path) -> Path:
    path = Path(value)
    if path.is_absolute():
        return path
    return (Path(base_dir) / path).resolve()


def resolve_optional_path(value: str | Path | None, base_dir: str | Path) -> Path | None:
    if value is None:
        return None
    return resolve_path(value, base_dir)


def sudo_available() -> bool:
    try:
        completed = subprocess.run(
            ["sudo", "-n", "true"],
            capture_output=True,
            text=True,
        )
    except OSError:
        return False
    return completed.returncode == 0


def ensure_build_steps(
    build_commands: Mapping[str, Sequence[str]],
    *,
    root_dir: str | Path,
    build_order: Sequence[str],
) -> None:
    for step in build_order:
        command = list(build_commands[step])
        print(f"[build] {step}: {' '.join(command)}")
        completed = subprocess.run(command, cwd=Path(root_dir), text=True)
        if completed.returncode != 0:
            raise RuntimeError(f"build step failed: {step}")


def validate_publication_environment(
    host: Mapping[str, object],
    *,
    cpu: str | int | None,
    strict: bool,
) -> None:
    strict_failures: list[str] = []

    def report_publication_issue(message: str) -> None:
        if strict:
            strict_failures.append(message)
            return
        print(f"[WARN] {message}")

    governor = str(host.get("cpu_governor", "unknown"))
    if governor != "performance":
        report_publication_issue(
            f"CPU governor is '{governor}', not 'performance'. "
            "Results may have frequency scaling noise."
        )

    no_turbo = str(host.get("turbo_state", "unknown"))
    if no_turbo != "1":
        report_publication_issue(
            "Turbo boost is enabled. Consider disabling for stable measurements."
        )

    perf_event_paranoid = str(host.get("perf_event_paranoid", "unknown"))
    try:
        perf_event_paranoid_value = int(perf_event_paranoid)
    except ValueError:
        perf_event_paranoid_value = None
    if perf_event_paranoid_value is not None and perf_event_paranoid_value > 1:
        print(f"[WARN] perf_event_paranoid={perf_event_paranoid}. Some perf counters may not be available.")

    if cpu is None:
        report_publication_issue(
            "No CPU affinity set. Consider using --cpu for isolated measurements."
        )

    if not sudo_available():
        report_publication_issue(
            "sudo -n is not available. Passwordless sudo is required for publication-grade runs."
        )

    if strict_failures:
        for failure in strict_failures:
            print(f"[ERROR] {failure}", file=sys.stderr)
        raise SystemExit(1)


__all__ = [
    "ensure_build_steps",
    "read_optional_text",
    "read_required_text",
    "resolve_optional_path",
    "resolve_path",
    "sudo_available",
    "validate_publication_environment",
]
