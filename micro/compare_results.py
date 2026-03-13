#!/usr/bin/env python3
"""Compare two micro benchmark result JSON files.

Usage:
    python3 micro/compare_results.py old.json new.json
    make compare OLD=micro/results/old.json NEW=micro/results/new.json

For each benchmark present in both files, reports:
  - old kernel-recompile ratio (llvmbpf/kernel or recompile/kernel)
  - new kernel-recompile ratio
  - delta (new - old)
  - flag if |delta| > 5%

Also reports overall geomean of ratios (old, new) and the geomean delta.
"""
from __future__ import annotations

import json
import math
import sys
from pathlib import Path
from typing import NamedTuple


SIGNIFICANT_DELTA = 0.05  # 5% threshold for flagging


class BenchRow(NamedTuple):
    name: str
    old_ratio: float | None
    new_ratio: float | None


def _extract_ratio(benchmark_record: dict, numerator_runtime: str, denominator_runtime: str) -> float | None:
    """Extract exec_ns median ratio: numerator_runtime / denominator_runtime."""
    runs_by_name: dict[str, dict] = {}
    for run in benchmark_record.get("runs", []):
        rt = str(run.get("runtime", ""))
        runs_by_name[rt] = run

    num_run = runs_by_name.get(numerator_runtime)
    den_run = runs_by_name.get(denominator_runtime)
    if num_run is None or den_run is None:
        return None

    num_val = num_run.get("exec_ns", {}).get("median")
    den_val = den_run.get("exec_ns", {}).get("median")
    if num_val is None or den_val is None or float(den_val) == 0.0:
        return None
    return float(num_val) / float(den_val)


def _infer_comparison_pair(benchmarks: list[dict]) -> tuple[str, str]:
    """Infer which runtimes to compare: prefer kernel-recompile/kernel, fall back to llvmbpf/kernel."""
    runtime_names: set[str] = set()
    for b in benchmarks:
        for run in b.get("runs", []):
            runtime_names.add(str(run.get("runtime", "")))

    if "kernel-recompile" in runtime_names and "kernel" in runtime_names:
        return "kernel-recompile", "kernel"
    if "llvmbpf" in runtime_names and "kernel" in runtime_names:
        return "llvmbpf", "kernel"
    # Fall back to first two found
    names = sorted(runtime_names)
    if len(names) >= 2:
        return names[0], names[1]
    return "", ""


def _geomean(values: list[float]) -> float | None:
    if not values:
        return None
    try:
        log_sum = sum(math.log(v) for v in values if v > 0)
        return math.exp(log_sum / len(values))
    except (ValueError, ZeroDivisionError):
        return None


def _load_benchmarks(path: Path) -> list[dict]:
    data = json.loads(path.read_text())
    # Support both top-level list and {"benchmarks": [...]} format
    if isinstance(data, list):
        return data
    return data.get("benchmarks", [])


def _provenance_summary(path: Path) -> str:
    try:
        data = json.loads(path.read_text())
        prov = data.get("provenance", {})
        ts = prov.get("timestamp", data.get("generated_at", "?"))
        kc = prov.get("kernel_commit", "?")[:12]
        env = prov.get("environment", "?")
        return f"{ts[:19]}  kernel={kc}  env={env}"
    except Exception:
        return str(path)


def compare(old_path: Path, new_path: Path) -> int:
    old_benchmarks = _load_benchmarks(old_path)
    new_benchmarks = _load_benchmarks(new_path)

    # Index by name
    old_by_name = {b["name"]: b for b in old_benchmarks}
    new_by_name = {b["name"]: b for b in new_benchmarks}

    # Infer runtime pair (prefer new file's runtimes)
    num_rt, den_rt = _infer_comparison_pair(new_benchmarks or old_benchmarks)
    if not num_rt or not den_rt:
        print("ERROR: cannot infer runtime pair from result files.", file=sys.stderr)
        return 1

    all_names = sorted(set(old_by_name) | set(new_by_name))

    rows: list[BenchRow] = []
    for name in all_names:
        old_rec = old_by_name.get(name)
        new_rec = new_by_name.get(name)
        old_ratio = _extract_ratio(old_rec, num_rt, den_rt) if old_rec else None
        new_ratio = _extract_ratio(new_rec, num_rt, den_rt) if new_rec else None
        rows.append(BenchRow(name=name, old_ratio=old_ratio, new_ratio=new_ratio))

    # Print header
    print(f"\nComparing results:")
    print(f"  OLD: {_provenance_summary(old_path)}")
    print(f"       {old_path}")
    print(f"  NEW: {_provenance_summary(new_path)}")
    print(f"       {new_path}")
    print(f"  Ratio: {num_rt} / {den_rt}  (lower=faster numerator)\n")

    col_w = max((len(r.name) for r in rows), default=20)
    header = f"{'Benchmark':{col_w}}  {'OLD ratio':>10}  {'NEW ratio':>10}  {'Delta':>10}  Flag"
    sep = "-" * len(header)
    print(header)
    print(sep)

    old_ratios_shared: list[float] = []
    new_ratios_shared: list[float] = []
    regressions: list[str] = []
    improvements: list[str] = []

    for row in rows:
        old_str = f"{row.old_ratio:.4f}" if row.old_ratio is not None else "  n/a  "
        new_str = f"{row.new_ratio:.4f}" if row.new_ratio is not None else "  n/a  "
        flag = ""
        delta_str = "  n/a  "
        if row.old_ratio is not None and row.new_ratio is not None:
            delta = row.new_ratio - row.old_ratio
            delta_str = f"{delta:+.4f}"
            if abs(delta) >= SIGNIFICANT_DELTA:
                if delta > 0:
                    flag = "WORSE"
                    regressions.append(row.name)
                else:
                    flag = "BETTER"
                    improvements.append(row.name)
            old_ratios_shared.append(row.old_ratio)
            new_ratios_shared.append(row.new_ratio)

        print(f"{row.name:{col_w}}  {old_str:>10}  {new_str:>10}  {delta_str:>10}  {flag}")

    print(sep)

    # Overall geomean
    old_geomean = _geomean(old_ratios_shared)
    new_geomean = _geomean(new_ratios_shared)
    old_geo_str = f"{old_geomean:.4f}" if old_geomean is not None else "  n/a  "
    new_geo_str = f"{new_geomean:.4f}" if new_geomean is not None else "  n/a  "
    geo_delta_str = "  n/a  "
    if old_geomean is not None and new_geomean is not None:
        geo_delta = new_geomean - old_geomean
        geo_delta_str = f"{geo_delta:+.4f}"

    print(f"{'GEOMEAN (shared)':{col_w}}  {old_geo_str:>10}  {new_geo_str:>10}  {geo_delta_str:>10}")
    print()

    if improvements:
        print(f"Significant improvements (>{int(SIGNIFICANT_DELTA*100)}%): {', '.join(improvements)}")
    if regressions:
        print(f"Significant regressions  (>{int(SIGNIFICANT_DELTA*100)}%): {', '.join(regressions)}")
    if not improvements and not regressions:
        print(f"No significant changes (threshold: {int(SIGNIFICANT_DELTA*100)}%).")
    print()

    return 0


def main(argv: list[str] | None = None) -> int:
    args = (argv if argv is not None else sys.argv[1:])
    if len(args) != 2:
        print(f"Usage: {sys.argv[0]} OLD.json NEW.json", file=sys.stderr)
        return 1
    old_path = Path(args[0])
    new_path = Path(args[1])
    for p in (old_path, new_path):
        if not p.exists():
            print(f"ERROR: file not found: {p}", file=sys.stderr)
            return 1
    return compare(old_path, new_path)


if __name__ == "__main__":
    raise SystemExit(main())
