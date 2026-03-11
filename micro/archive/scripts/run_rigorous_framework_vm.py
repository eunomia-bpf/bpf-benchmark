#!/usr/bin/env python3
from __future__ import annotations

import sys
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
MICRO_ROOT = SCRIPT_DIR.parent.parent
REPO_ROOT = MICRO_ROOT.parent
for candidate in (REPO_ROOT, MICRO_ROOT):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from _driver_impl_run_rigorous_framework_vm import *  # type: ignore[F403]
except ImportError:
    from micro._driver_impl_run_rigorous_framework_vm import *  # type: ignore[F403]


def _main_through_driver() -> int:
    try:
        from driver import main as driver_main
    except ImportError:
        from micro.driver import main as driver_main
    return driver_main(["rigorous", "--transport", "vm", "--", *sys.argv[1:]])


if __name__ == "__main__":
    raise SystemExit(_main_through_driver())
