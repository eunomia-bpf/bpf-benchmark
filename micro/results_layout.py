from __future__ import annotations

import os
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
    latest_path.parent.mkdir(parents=True, exist_ok=True)
    if latest_path.exists() or latest_path.is_symlink():
        latest_path.unlink()
    latest_path.symlink_to(Path(os.path.relpath(target_path, latest_path.parent)))


def maybe_refresh_latest_alias(path: Path) -> None:
    match = RESULT_FILE_RE.fullmatch(path.name)
    if match is None or match.group("kind") != "authoritative":
        return
    refresh_latest_alias(latest_output_path(path.parent, match.group("suite")), path)
