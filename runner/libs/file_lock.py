from __future__ import annotations

import fcntl
import re
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator

from runner.libs import ROOT_DIR


def _lock_path(name: str) -> Path:
    token = re.sub(r"[^0-9A-Za-z_.-]+", "_", name.strip())
    if not token:
        token = "runner"
    return ROOT_DIR / ".cache" / "runner-locks" / f"{token}.lock"


@contextmanager
def runner_lock(name: str) -> Iterator[Path]:
    path = _lock_path(name)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as lock_file:
        fcntl.flock(lock_file.fileno(), fcntl.LOCK_EX)
        try:
            yield path
        finally:
            fcntl.flock(lock_file.fileno(), fcntl.LOCK_UN)
