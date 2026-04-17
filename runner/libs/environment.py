from __future__ import annotations

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


def require_existing_paths(paths: Sequence[str | Path]) -> None:
    missing = [str(Path(path)) for path in paths if not Path(path).exists()]
    if missing:
        raise SystemExit("missing required artifacts:\n" + "\n".join(missing))


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

    if strict_failures:
        for failure in strict_failures:
            print(f"[ERROR] {failure}", file=sys.stderr)
        raise SystemExit(1)
