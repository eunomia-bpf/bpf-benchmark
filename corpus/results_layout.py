from __future__ import annotations

import re
from datetime import datetime, timezone
from pathlib import Path


RESULT_FILE_RE = re.compile(r"^(?P<suite>.+)_(?P<kind>authoritative|smoke)_(?P<date>\d{8})\.json$")


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
