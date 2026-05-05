#!/usr/bin/env python3
"""Analyze corpus result.json files using paper-grade methodology.

Implements the methodology documented in CLAUDE.md "Performance Calculation
Methodology". Framework code does NOT contain any aggregation; this script
is the analysis-side tool.

Usage:
    python analysis/corpus_analyze.py <result_dir|metadata.json|result.json>
        [--threshold N]    Filter min(b_runs, p_runs) >= N (default: 100)
        [--per-app]        Print per-app breakdown
        [--verbose]        Print every retained per-program ratio
"""
from __future__ import annotations

import argparse
import json
import math
import sys
from pathlib import Path
from statistics import mean, stdev


def find_result_json(target: Path) -> Path:
    """Accept a corpus run dir, metadata.json, or result.json."""
    if target.is_file():
        if target.name == "result.json":
            return target
        if target.name == "metadata.json":
            details = target.parent / "details" / "result.json"
            if details.is_file():
                return details
        raise FileNotFoundError(f"{target} is not a result.json or metadata.json")
    candidate = target / "details" / "result.json"
    if candidate.is_file():
        return candidate
    candidate = target / "result.json"
    if candidate.is_file():
        return candidate
    raise FileNotFoundError(f"no result.json under {target}")


def collect_per_program(payload: dict, min_runs: int) -> list[dict]:
    """Build per-program ratio records from raw counter deltas."""
    out: list[dict] = []
    for app in payload.get("results", []):
        baseline = (app.get("baseline") or {}).get("bpf") or {}
        post = (app.get("post_rejit") or {}).get("bpf") or {}
        for pid in set(baseline) & set(post):
            b, p = baseline[pid], post[pid]
            b_runs = int(b.get("run_cnt_delta") or 0)
            p_runs = int(p.get("run_cnt_delta") or 0)
            if b_runs <= 0 or p_runs <= 0:
                continue
            b_time = int(b.get("run_time_ns_delta") or 0)
            p_time = int(p.get("run_time_ns_delta") or 0)
            if b_time <= 0 or p_time < 0:
                continue
            b_avg = b_time / b_runs
            p_avg = p_time / p_runs
            if b_avg <= 0 or p_avg <= 0:
                continue
            min_r = min(b_runs, p_runs)
            if min_r < min_runs:
                continue
            out.append({
                "app": app["app"],
                "prog_id": int(pid),
                "name": p.get("name") or b.get("name") or f"id-{pid}",
                "type": p.get("type") or b.get("type") or "",
                "min_runs": min_r,
                "b_avg_ns": b_avg,
                "p_avg_ns": p_avg,
                "ratio": p_avg / b_avg,
            })
    return out


def geomean(xs: list[float]) -> float:
    if not xs:
        return float("nan")
    return math.exp(sum(math.log(x) for x in xs) / len(xs))


def run_weighted_aggregate(progs: list[dict]) -> float:
    num = sum(p["p_avg_ns"] * p["min_runs"] for p in progs)
    den = sum(p["b_avg_ns"] * p["min_runs"] for p in progs)
    return num / den if den else float("nan")


def fmt(x: float, fmt_spec: str = ".4f") -> str:
    if x != x:  # NaN
        return "n/a"
    return format(x, fmt_spec)


def report(path: Path, threshold: int, per_app: bool, verbose: bool) -> int:
    payload = json.loads(Path(path).read_text())
    suite_status = payload.get("status", "?")
    samples = payload.get("samples", "?")
    duration = payload.get("workload_seconds", "?")
    progs = collect_per_program(payload, threshold)

    print(f"# Corpus analysis: {path}")
    print(f"  suite status:    {suite_status}")
    print(f"  samples:         {samples}")
    print(f"  workload_secs:   {duration}")
    print(f"  threshold:       min(b_runs, p_runs) >= {threshold}")
    print(f"  retained progs:  {len(progs)}")

    if not progs:
        print("\n(no programs retained at this threshold)")
        return 0

    ratios = [p["ratio"] for p in progs]
    wins = sum(1 for r in ratios if r < 1.0)
    losses = sum(1 for r in ratios if r > 1.0)
    ties = sum(1 for r in ratios if r == 1.0)

    print(f"\n## Global metrics (CLAUDE.md methodology)")
    print(f"  Method B  per-program geomean:   {fmt(geomean(ratios))}")
    print(f"  Method C  run-weighted aggregate: {fmt(run_weighted_aggregate(progs))}")
    print(f"  wins/losses/ties:                 {wins}/{losses}/{ties}")
    print(f"  ratio min / max / median:         {min(ratios):.4f} / {max(ratios):.4f} / {sorted(ratios)[len(ratios)//2]:.4f}")

    if len(ratios) > 1:
        m = mean(ratios)
        sd = stdev(ratios)
        cv = sd / m * 100 if m > 0 else 0
        print(f"  ratio CV (across progs):          {cv:.1f}%")

    if per_app:
        print(f"\n## Per-app breakdown")
        from collections import defaultdict
        groups = defaultdict(list)
        for p in progs:
            groups[p["app"]].append(p)
        header = f"{'App':<40} {'N':<5} {'B geomean':<11} {'C run-wt':<11} {'wins/losses':<14} {'top runs':<10}"
        print(header)
        print("=" * len(header))
        for app, pp in sorted(groups.items()):
            rs = [p["ratio"] for p in pp]
            w = sum(1 for r in rs if r < 1.0)
            l = sum(1 for r in rs if r > 1.0)
            top = max(p["min_runs"] for p in pp)
            print(f"{app:<40} {len(pp):<5} {fmt(geomean(rs)):<11} {fmt(run_weighted_aggregate(pp)):<11} {w}/{l:<11} {top:>9}")

    if verbose:
        print(f"\n## Per-program detail")
        progs_sorted = sorted(progs, key=lambda p: p["ratio"])
        print(f"{'App':<35} {'PID':<5} {'Name':<35} {'min_runs':<10} {'b_avg(ns)':<12} {'p_avg(ns)':<12} {'ratio':<8}")
        for p in progs_sorted:
            print(f"{p['app']:<35} {p['prog_id']:<5} {p['name']:<35} {p['min_runs']:<10} {p['b_avg_ns']:<12.2f} {p['p_avg_ns']:<12.2f} {p['ratio']:<8.4f}")

    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("target", type=Path,
                    help="corpus result dir, metadata.json, or result.json")
    ap.add_argument("--threshold", type=int, default=100,
                    help="min_runs filter (default: 100, per CLAUDE.md)")
    ap.add_argument("--per-app", action="store_true", help="print per-app breakdown")
    ap.add_argument("--verbose", action="store_true",
                    help="print every retained per-program ratio")
    args = ap.parse_args()
    try:
        result_json = find_result_json(args.target)
    except FileNotFoundError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    return report(result_json, args.threshold, args.per_app, args.verbose)


if __name__ == "__main__":
    sys.exit(main())
