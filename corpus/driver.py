#!/usr/bin/env python3
from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from corpus.modes import packet_main, run_linear_mode

MODE_NAMES = {"packet", "tracing", "perf", "code-size"}


def main(argv: list[str] | None = None) -> int:
    raw_args = list(sys.argv[1:] if argv is None else argv)
    if not raw_args or raw_args[0] not in MODE_NAMES:
        raise SystemExit("expected one of: packet, tracing, perf, code-size")

    mode_name, *remaining = raw_args
    if mode_name == "packet":
        return packet_main(remaining)
    return run_linear_mode(mode_name, remaining)


if __name__ == "__main__":
    raise SystemExit(main())
