#!/usr/bin/env python3
from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from corpus.modes import packet_main


def main(argv: list[str] | None = None) -> int:
    return packet_main(list(sys.argv[1:] if argv is None else argv))


if __name__ == "__main__":
    raise SystemExit(main())
