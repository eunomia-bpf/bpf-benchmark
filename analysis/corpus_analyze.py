#!/usr/bin/env python3
"""Analyze corpus result.json files using paper-grade methodology.

Implements the methodology documented in CLAUDE.md "Performance Calculation
Methodology". Framework code does NOT contain any aggregation; this script
is the analysis-side tool.

Usage:
    python analysis/corpus_analyze.py <result_dir|metadata.json|result.json>
        [--threshold N]    Filter min(b_runs, p_runs) >= N (default: 100)
        [--per-app]        Print per-app breakdown (rich table sorted by Method B)
        [--per-pass]       Add per-pass apply-count columns to the per-app table
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


def collect_app_pass_stats(payload: dict) -> dict:
    """For each app, accumulate per-pass {applied, matched, skipped, errors} and
    raw base/post run_time_ns + run_cnt totals across paper-grade progs."""
    from collections import defaultdict
    apps: dict[str, dict] = {}
    for app in payload.get("results", []):
        name = app["app"]
        per_prog = (app.get("rejit_result") or {}).get("per_program") or {}
        pass_apply: dict[str, int] = defaultdict(int)
        pass_match: dict[str, int] = defaultdict(int)
        pass_skip: dict[str, int] = defaultdict(int)
        pass_err: dict[str, int] = defaultdict(int)
        for pinfo in per_prog.values():
            for ps in pinfo.get("passes", []):
                sm = ps.get("bpfopt_summary") or {}
                pn = ps.get("pass") or sm.get("pass") or "?"
                pass_apply[pn] += int(sm.get("sites_applied") or 0)
                pass_match[pn] += int(sm.get("sites_matched") or 0)
                pass_skip[pn] += int(sm.get("sites_skipped") or 0)
                if ps.get("error"):
                    pass_err[pn] += 1
        apps[name] = {
            "pass_apply": dict(pass_apply),
            "pass_match": dict(pass_match),
            "pass_skip": dict(pass_skip),
            "pass_err": dict(pass_err),
        }
    return apps


def print_per_app(payload: dict, progs: list[dict], per_pass: bool) -> None:
    from collections import defaultdict
    by_app: dict[str, list[dict]] = defaultdict(list)
    for p in progs:
        by_app[p["app"]].append(p)
    pass_stats = collect_app_pass_stats(payload)

    pass_names: list[str] = []
    for app_stat in pass_stats.values():
        for pn in app_stat["pass_apply"]:
            if pn not in pass_names:
                pass_names.append(pn)
    pass_names = [pn for pn in pass_names if any(pass_stats[a]["pass_apply"].get(pn, 0) > 0 or pass_stats[a]["pass_err"].get(pn, 0) > 0 for a in pass_stats)]

    rows = []
    for app, pp in by_app.items():
        rs = [p["ratio"] for p in pp]
        b_geomean = geomean(rs)
        c_agg = run_weighted_aggregate(pp)
        wins = sum(1 for r in rs if r < 1.0)
        losses = sum(1 for r in rs if r > 1.0)
        # weighted per-iter ns across paper-grade progs in this app:
        b_ns_iter = sum(p["b_avg_ns"] * p["min_runs"] for p in pp) / sum(p["min_runs"] for p in pp)
        p_ns_iter = sum(p["p_avg_ns"] * p["min_runs"] for p in pp) / sum(p["min_runs"] for p in pp)
        applied_total = sum(pass_stats.get(app, {}).get("pass_apply", {}).values())
        err_total = sum(pass_stats.get(app, {}).get("pass_err", {}).values())
        rows.append({
            "app": app,
            "progs": len(pp),
            "min_runs": sum(p["min_runs"] for p in pp),
            "applied": applied_total,
            "errors": err_total,
            "base_ns": b_ns_iter,
            "post_ns": p_ns_iter,
            "delta_ns": p_ns_iter - b_ns_iter,
            "B": b_geomean,
            "C": c_agg,
            "wins": wins,
            "losses": losses,
        })

    rows.sort(key=lambda r: r["B"] if r["B"] == r["B"] else 1.0)

    print(f"\n## Per-app breakdown (sorted by Method B ascending = best speedup first)")

    base_cols = [
        ("App", 33, "left"),
        ("progs", 5, "right"),
        ("min_runs", 13, "right"),
        ("applied", 7, "right"),
        ("errs", 5, "right"),
        ("base_ns/iter", 13, "right"),
        ("post_ns/iter", 13, "right"),
        ("delta_ns", 11, "right"),
        ("Method B*", 9, "right"),
        ("Method C", 9, "right"),
        ("W/L", 7, "right"),
    ]

    pass_cols = [(pn, max(7, len(pn)), "right") for pn in pass_names] if per_pass else []
    cols = base_cols[:3] + pass_cols + base_cols[3:]

    def render_cell(value, col):
        name, width, align = col
        s = str(value)
        return s.ljust(width) if align == "left" else s.rjust(width)

    header = "  ".join(render_cell(c[0], c) for c in cols)
    print(header)
    print("  ".join("-" * c[1] for c in cols))

    for r in rows:
        cells = [
            r["app"], f"{r['progs']}", f"{r['min_runs']:,}",
        ]
        if per_pass:
            ps = pass_stats.get(r["app"], {}).get("pass_apply", {})
            cells.extend(str(ps.get(pn, 0)) for pn in pass_names)
        cells.extend([
            f"{r['applied']}",
            f"{r['errors']}",
            f"{r['base_ns']:,.1f}",
            f"{r['post_ns']:,.1f}",
            f"{r['delta_ns']:+,.1f}",
            f"{r['B']:.4f}" if r["B"] == r["B"] else "n/a",
            f"{r['C']:.4f}" if r["C"] == r["C"] else "n/a",
            f"{r['wins']}/{r['losses']}",
        ])
        print("  ".join(render_cell(v, c) for v, c in zip(cells, cols)))


def report(path: Path, threshold: int, per_app: bool, verbose: bool, per_pass: bool = False) -> int:
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
        print_per_app(payload, progs, per_pass=per_pass)

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
    ap.add_argument("--per-app", action="store_true", help="print per-app breakdown (sorted by Method B)")
    ap.add_argument("--per-pass", action="store_true",
                    help="add per-pass apply-count columns to the per-app table")
    ap.add_argument("--verbose", action="store_true",
                    help="print every retained per-program ratio")
    args = ap.parse_args()
    try:
        result_json = find_result_json(args.target)
    except FileNotFoundError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    return report(result_json, args.threshold, args.per_app, args.verbose, args.per_pass)


if __name__ == "__main__":
    sys.exit(main())
