#!/usr/bin/env python3
"""Compare BPF counter costs between two corpus artifacts.

This is an analysis-side helper. It reads raw per-app corpus JSON payloads and
computes per-program ratios outside the benchmark framework.
"""
from __future__ import annotations

import argparse
import json
import math
import sys
from collections import defaultdict
from pathlib import Path
from statistics import mean, stdev

sys.path.insert(0, str(Path(__file__).resolve().parent))
from corpus_analyze import find_result_json, _hydrate_results_from_apps_dir


def geomean(xs: list[float]) -> float:
    return math.exp(sum(math.log(x) for x in xs) / len(xs)) if xs else float("nan")


def fmt(x: float, fmt_spec: str = ".6f") -> str:
    return "n/a" if x != x else format(x, fmt_spec)


def load_apps(target: Path) -> dict[str, dict]:
    result_json = find_result_json(target)
    payload = json.loads(result_json.read_text())
    payload = _hydrate_results_from_apps_dir(payload, result_json)
    return {app["app"]: app for app in payload.get("results", [])}


def pairing_key(rec: dict, pair_by: str) -> tuple:
    if pair_by == "name-type":
        return (rec.get("name") or "", rec.get("type") or "")
    if pair_by == "stable":
        return (
            rec.get("name") or "",
            rec.get("type") or "",
            int(rec.get("bytes_xlated") or 0),
            int(rec.get("bytes_jited") or 0),
        )
    raise ValueError(pair_by)


def run_sort_key(rec: dict) -> tuple[int, int, str]:
    return (
        int(rec.get("run_cnt_delta") or 0),
        int(rec.get("run_time_ns_delta") or 0),
        str(rec.get("id") or ""),
    )


def phase_bpf(app: dict, phase: str) -> dict:
    return (app.get(phase) or {}).get("bpf") or {}


def collect(
    left_apps: dict[str, dict],
    right_apps: dict[str, dict],
    left_phase: str,
    right_phase: str,
    pair_by: str,
    min_runs: int,
) -> list[dict]:
    rows: list[dict] = []
    for app_name in sorted(set(left_apps) & set(right_apps)):
        left = phase_bpf(left_apps[app_name], left_phase)
        right = phase_bpf(right_apps[app_name], right_phase)
        left_groups: dict[tuple, list[dict]] = defaultdict(list)
        right_groups: dict[tuple, list[dict]] = defaultdict(list)
        for rec in left.values():
            left_groups[pairing_key(rec, pair_by)].append(rec)
        for rec in right.values():
            right_groups[pairing_key(rec, pair_by)].append(rec)
        for key in sorted(set(left_groups) & set(right_groups)):
            left_recs = sorted(left_groups[key], key=run_sort_key, reverse=True)
            right_recs = sorted(right_groups[key], key=run_sort_key, reverse=True)
            for idx, (lrec, rrec) in enumerate(zip(left_recs, right_recs)):
                left_runs = int(lrec.get("run_cnt_delta") or 0)
                right_runs = int(rrec.get("run_cnt_delta") or 0)
                left_time = int(lrec.get("run_time_ns_delta") or 0)
                right_time = int(rrec.get("run_time_ns_delta") or 0)
                if min(left_runs, right_runs) < min_runs:
                    continue
                if left_runs <= 0 or right_runs <= 0 or left_time <= 0 or right_time <= 0:
                    continue
                left_avg = left_time / left_runs
                right_avg = right_time / right_runs
                rows.append({
                    "app": app_name,
                    "name": rrec.get("name") or lrec.get("name") or str(key),
                    "type": rrec.get("type") or lrec.get("type") or "",
                    "occurrence": idx,
                    "min_runs": min(left_runs, right_runs),
                    "left_avg_ns": left_avg,
                    "right_avg_ns": right_avg,
                    "ratio": right_avg / left_avg,
                })
    return rows


def print_summary(rows: list[dict], per_app: bool, verbose: bool) -> None:
    print(f"  retained progs:  {len(rows)}")
    if not rows:
        print("\n(no programs retained at this threshold)")
        return
    ratios = [r["ratio"] for r in rows]
    wins = sum(1 for r in ratios if r < 1.0)
    losses = sum(1 for r in ratios if r > 1.0)
    ties = sum(1 for r in ratios if r == 1.0)
    print("\n## Global metrics")
    print(f"  geomean right/left:              {fmt(geomean(ratios))}")
    print(f"  speedup left/right:              {fmt(1 / geomean(ratios))}")
    print(f"  wins/losses/ties:                {wins}/{losses}/{ties}")
    print(f"  ratio min / max / median:        {min(ratios):.4f} / {max(ratios):.4f} / {sorted(ratios)[len(ratios)//2]:.4f}")
    if len(ratios) > 1:
        m = mean(ratios)
        print(f"  ratio CV (across progs):         {stdev(ratios) / m * 100:.1f}%")

    if per_app:
        by_app: dict[str, list[dict]] = defaultdict(list)
        for row in rows:
            by_app[row["app"]].append(row)
        print("\n## Per-app breakdown")
        print(f"{'App':<35} {'progs':>5} {'min_runs':>13} {'geomean':>10} {'speedup':>10} {'W/L':>7}")
        print(f"{'-'*35} {'-'*5:>5} {'-'*13:>13} {'-'*10:>10} {'-'*10:>10} {'-'*7:>7}")
        for app, app_rows in sorted(by_app.items()):
            app_ratios = [r["ratio"] for r in app_rows]
            g = geomean(app_ratios)
            aw = sum(1 for r in app_ratios if r < 1.0)
            al = sum(1 for r in app_ratios if r > 1.0)
            min_runs = sum(r["min_runs"] for r in app_rows)
            print(f"{app:<35} {len(app_rows):>5} {min_runs:>13,} {g:>10.6f} {1/g:>10.6f} {aw:>3}/{al:<3}")

    if verbose:
        print("\n## Per-program detail")
        print(f"{'App':<35} {'Name':<35} {'Type':<14} {'min_runs':>10} {'left_ns':>12} {'right_ns':>12} {'ratio':>10}")
        for row in sorted(rows, key=lambda r: r["ratio"]):
            print(
                f"{row['app']:<35} {row['name']:<35} {row['type']:<14} "
                f"{row['min_runs']:>10} {row['left_avg_ns']:>12.2f} "
                f"{row['right_avg_ns']:>12.2f} {row['ratio']:>10.6f}"
            )


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("left", type=Path, help="control corpus result dir/metadata/result.json")
    ap.add_argument("right", type=Path, help="treatment corpus result dir/metadata/result.json")
    ap.add_argument("--left-phase", default="baseline", choices=("baseline", "post_rejit"))
    ap.add_argument("--right-phase", default="baseline", choices=("baseline", "post_rejit"))
    ap.add_argument("--left-label", default="left")
    ap.add_argument("--right-label", default="right")
    ap.add_argument("--threshold", type=int, default=100)
    ap.add_argument("--pair-by", choices=("name-type", "stable"), default="name-type")
    ap.add_argument("--per-app", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    rows = collect(
        load_apps(args.left),
        load_apps(args.right),
        args.left_phase,
        args.right_phase,
        args.pair_by,
        args.threshold,
    )
    print("# Corpus cross-artifact comparison")
    print(f"  left:            {args.left_label} ({args.left}) [{args.left_phase}]")
    print(f"  right:           {args.right_label} ({args.right}) [{args.right_phase}]")
    print(f"  threshold:       min(left_runs, right_runs) >= {args.threshold}")
    print(f"  pair_by:         {args.pair_by}")
    print_summary(rows, args.per_app, args.verbose)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
