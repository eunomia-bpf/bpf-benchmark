from __future__ import annotations

import sys
from typing import NoReturn


def fail(tag: str, message: str) -> NoReturn:
    print(f"[{tag}][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)
