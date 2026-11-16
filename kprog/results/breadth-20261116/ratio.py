#!/usr/bin/env python3
"""Throughput and per-call ratio for one run directory, on the 2026-05-29 parser.

Reads a corpus run directory and prints, per arm, the workload samples, the
throughput ratio (median of the native arm over median of the eBPF arm) and the
per-call BPF time (run_time_ns_delta / run_cnt_delta over records with
run_cnt_delta >= 100), which is what stats=1 provides and stats=0 does not.

The parser is kprog/docs/archive/native_eval_20260529.py, the same one the
README tables quote; this file only adds the two-arm arrangement and cannot
disagree with it. matplotlib is stubbed because the parser imports it for its
own figure output.

Usage: ratio.py <run-dir> [<run-dir> ...]
"""

from __future__ import annotations

import math
import statistics
import sys
import types
from pathlib import Path

ROOT = Path("/workspaces/repository")
sys.path.insert(0, str(ROOT / "kprog" / "docs" / "archive"))

_stub = types.ModuleType("matplotlib")
_stub.use = lambda *a, **k: None
_pyplot = types.ModuleType("matplotlib.pyplot")
_pyplot.figure = lambda *a, **k: None
_stub.pyplot = _pyplot
sys.modules.setdefault("matplotlib", _stub)
sys.modules.setdefault("matplotlib.pyplot", _pyplot)

import native_eval_20260529 as P  # noqa: E402

ARMS = ("baseline", "post_rejit")


def workload(app: dict, arm: str) -> list[float]:
    return [sample[0] for sample in P.phase_samples(app, arm)]


def ratio(run_dir: Path) -> None:
    app, path = P.load_app(str(run_dir))
    print(f"== {path.name}")
    print(f"   status={app.get('status')} error={str(app.get('error'))[:60]}")
    medians = {}
    for arm in ARMS:
        samples = workload(app, arm)
        bpf_ns, retained, records = P.bpf_aggregate(app, arm)
        progs = len(((app.get(arm) or {}).get("bpf") or {}))
        if samples:
            medians[arm] = statistics.median(samples)
            print(
                f"   {arm:11s} progs={progs:3d} units={[round(v) for v in samples]}"
                f" median={round(medians[arm])}"
            )
        else:
            print(f"   {arm:11s} progs={progs:3d} units=[] (no workload samples)")
        if retained:
            print(
                f"   {arm:11s} per-call={bpf_ns:.1f} ns over {retained}/{records}"
                f" records with run_cnt_delta>=100"
            )
        else:
            print(f"   {arm:11s} per-call=n/a ({records} records, none retained)")
    if len(medians) == 2 and medians["baseline"]:
        print(f"   throughput = {medians['post_rejit'] / medians['baseline']:.3f}x")
    base_ns, _, _ = P.bpf_aggregate(app, "baseline")
    post_ns, _, _ = P.bpf_aggregate(app, "post_rejit")
    if not math.isnan(base_ns) and not math.isnan(post_ns) and post_ns:
        print(f"   per-call   = {base_ns / post_ns:.3f}x")


def main(argv: list[str]) -> int:
    if len(argv) < 2:
        print(__doc__.split("Usage:")[1].strip(), file=sys.stderr)
        return 2
    for arg in argv[1:]:
        run_dir = Path(arg)
        if not run_dir.is_absolute():
            run_dir = ROOT / run_dir
        ratio(run_dir)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))