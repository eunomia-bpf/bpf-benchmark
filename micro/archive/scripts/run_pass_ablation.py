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
    from _driver_impl_run_pass_ablation import main as run_pass_ablation_main
except ImportError:
    from micro._driver_impl_run_pass_ablation import main as run_pass_ablation_main


if __name__ == "__main__":
    raise SystemExit(run_pass_ablation_main(sys.argv[1:]))
