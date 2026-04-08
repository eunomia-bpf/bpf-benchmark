from __future__ import annotations

import sys
from pathlib import Path
from typing import NoReturn


def fail(tag: str, message: str) -> NoReturn:
    print(f"[{tag}][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def require_path(path: Path, description: str, *, tag: str) -> None:
    if not path.exists():
        fail(tag, f"{description} not found: {path}")


def require_nonempty_dir(path: Path, description: str, *, tag: str) -> None:
    if not path.is_dir():
        fail(tag, f"{description} is not a directory: {path}")
    try:
        next(path.iterdir())
    except StopIteration:
        fail(tag, f"{description} is empty: {path}")
