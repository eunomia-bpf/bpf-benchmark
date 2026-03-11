#!/usr/bin/env python3
from __future__ import annotations

import sys
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from _driver_impl_run_corpus_tracing_exec import *  # type: ignore[F403]
except ImportError:
    from corpus._driver_impl_run_corpus_tracing_exec import *  # type: ignore[F403]


def _main_through_driver() -> int:
    from micro.driver import main as driver_main

    return driver_main(["corpus", "tracing-exec", "--", *sys.argv[1:]])


if __name__ == "__main__":
    raise SystemExit(_main_through_driver())
