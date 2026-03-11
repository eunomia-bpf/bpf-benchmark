#!/usr/bin/env python3
from __future__ import annotations

import sys

try:
    from _driver_impl_run_corpus_v5_framework import *  # type: ignore[F403]
except ImportError:
    from micro._driver_impl_run_corpus_v5_framework import *  # type: ignore[F403]


def _main_through_driver() -> int:
    try:
        from driver import main as driver_main
    except ImportError:
        from micro.driver import main as driver_main
    return driver_main(["corpus", "v5-framework", "--", *sys.argv[1:]])


if __name__ == "__main__":
    raise SystemExit(_main_through_driver())
