#!/usr/bin/env python3
"""Post-hoc native-loader evaluation summary helper.

This script reads corpus result artifacts and prints analysis-side metrics only.
It intentionally does not write back to benchmark result files.
"""

from __future__ import annotations

import argparse
import json
import math
import pathlib
import re
from collections import defaultdict
from statistics import mean


STRESS_RE = re.compile(
    r"stress-ng: metrc: \[\d+\]\s+"
    r"(?P<name>[A-Za-z0-9_./:-]+)\s+"
    r"(?P<ops>\d+)\s+"
    r"(?P<real>[0-9.]+)\s+"
    r"(?P<usr>[0-9.]+)\s+"
    r"(?P<sys>[0-9.]+)\s+"
    r"(?P<real_ops>[0-9.]+)\s+"
    r"(?P<usr_sys_ops>[0-9.]+)"
)
INT_LOOP_RE = re.compile(
    r"(?P<name>python3|ruby|nodejs|perl|php) int_loop "
    r"ops=(?P<ops>\d+) elapsed_s=(?P<elapsed>[0-9.]+)"
)
PKTGEN_RE = re.compile(
    r"(?P<pps>[0-9]+)pps\s+(?P<mbps>[0-9]+)Mb/sec "
    r"\((?P<bps>[0-9]+)bps\) errors:\s*(?P<errors>[0-9]+)"
)


def load_app_json(run_dir: pathlib.Path, safe_app: str) -> dict:
    path = run_dir / "details" / "apps" / f"{safe_app}.json"
    with path.open() as f:
        return json.load(f)


def text_fragments(workload: dict) -> list[tuple[str, str]]:
    fragments: list[tuple[str, str]] = []
    items = workload.get("components") or [workload]
    for item in items:
        name = item.get("workload_name") or workload.get("workload_name") or "workload"
        fragments.append((name, (item.get("stdout") or "") + "\n" + (item.get("stderr") or "")))
    return fragments


def phase_workload_metrics(app: dict, phase: str) -> dict[str, list[float]]:
    phase_data = app.get(phase) or {}
    metrics: dict[str, list[float]] = defaultdict(list)
    for workload in phase_data.get("workloads") or []:
        for component_name, text in text_fragments(workload):
            for match in STRESS_RE.finditer(text):
                metrics[f"stress/{match.group('name')}/ops_per_sec"].append(
                    float(match.group("real_ops"))
                )
            for match in INT_LOOP_RE.finditer(text):
                ops = float(match.group("ops"))
                elapsed = float(match.group("elapsed"))
                if elapsed > 0:
                    metrics[f"int_loop/{match.group('name')}/ops_per_sec"].append(ops / elapsed)
            for match in PKTGEN_RE.finditer(text):
                key_base = f"pktgen/{component_name}"
                metrics[f"{key_base}/pps"].append(float(match.group("pps")))
                metrics[f"{key_base}/errors"].append(float(match.group("errors")))
    return dict(metrics)


def bpf_program_rows(app: dict, phase: str) -> list[dict]:
    rows = []
    phase_data = app.get(phase) or {}
    for prog_id, prog in (phase_data.get("bpf") or {}).items():
        runs = int(prog.get("run_cnt_delta") or 0)
        nsecs = int(prog.get("run_time_ns_delta") or 0)
        avg_ns = (nsecs / runs) if runs else None
        rows.append(
            {
                "prog_id": str(prog_id),
                "name": prog.get("name") or "",
                "type": prog.get("type") or "",
                "runs": runs,
                "nsecs": nsecs,
                "avg_ns": avg_ns,
                "bytes_jited": prog.get("bytes_jited"),
                "bytes_xlated": prog.get("bytes_xlated"),
            }
        )
    return rows


def matched_bpf_ratios(app: dict, min_runs: int) -> tuple[list[dict], list[str]]:
    baseline_groups: dict[tuple[str, str], list[dict]] = defaultdict(list)
    post_groups: dict[tuple[str, str], list[dict]] = defaultdict(list)
    for row in bpf_program_rows(app, "baseline"):
        baseline_groups[(row["name"], row["type"])].append(row)
    for row in bpf_program_rows(app, "post_rejit"):
        post_groups[(row["name"], row["type"])].append(row)

    warnings = []
    ratios = []
    for key, base_rows in sorted(baseline_groups.items()):
        post_rows = post_groups.get(key) or []
        if not post_rows:
            continue
        if len(base_rows) != len(post_rows):
            warnings.append(
                f"ambiguous count for {key[0]}/{key[1]}: baseline={len(base_rows)} post={len(post_rows)}"
            )
        base_sorted = sorted(
            base_rows,
            key=lambda r: (
                r["bytes_xlated"] or 0,
                r["bytes_jited"] or 0,
                r["prog_id"],
            ),
        )
        post_sorted = sorted(
            post_rows,
            key=lambda r: (
                r["bytes_xlated"] or 0,
                r["bytes_jited"] or 0,
                r["prog_id"],
            ),
        )
        for index, (base, post) in enumerate(zip(base_sorted, post_sorted)):
            if base["runs"] < min_runs or post["runs"] < min_runs:
                continue
            if not base["avg_ns"] or not post["avg_ns"]:
                continue
            ratio = post["avg_ns"] / base["avg_ns"]
            ratios.append(
                {
                    "name": key[0],
                    "type": key[1],
                    "ordinal": index,
                    "baseline_runs": base["runs"],
                    "post_runs": post["runs"],
                    "baseline_avg_ns": base["avg_ns"],
                    "post_avg_ns": post["avg_ns"],
                    "ratio": ratio,
                    "speedup": 1.0 / ratio if ratio else None,
                    "baseline_jited": base["bytes_jited"],
                    "post_jited": post["bytes_jited"],
                    "baseline_xlated": base["bytes_xlated"],
                    "post_xlated": post["bytes_xlated"],
                }
            )
    return ratios, warnings


def geomean(values: list[float]) -> float | None:
    if not values:
        return None
    return math.exp(mean(math.log(v) for v in values))


def shim_counts(run_dir: pathlib.Path, safe_app: str) -> dict[str, int | None]:
    path = run_dir / "details" / "shim-logs" / f"{safe_app}.post_rejit.log"
    if not path.exists():
        return {
            "replaced": None,
            "failed": None,
            "fatal": None,
            "no_manifest": None,
            "reloc_bounds": None,
            "indirect_call_ff_d0": None,
            "legacy_nop7": None,
        }
    text = path.read_text(errors="replace")
    lower = text.lower()
    return {
        "replaced": text.count("native-loader replaced"),
        "failed": lower.count("native-loader failed"),
        "fatal": lower.count("native-loader fatal"),
        "no_manifest": lower.count("native-loader enabled but no manifest object"),
        "reloc_bounds": lower.count("reloc bounds"),
        "indirect_call_ff_d0": lower.count("ff d0"),
        "legacy_nop7": lower.count("legacy nop7"),
    }


def summarize_run(label: str, run_dir: pathlib.Path, safe_app: str, min_runs: int) -> dict:
    app = load_app_json(run_dir, safe_app)
    ratios, warnings = matched_bpf_ratios(app, min_runs)
    speedups = [r["speedup"] for r in ratios if r.get("speedup")]
    workload = {
        phase: {
            metric: {
                "samples": len(values),
                "mean": mean(values),
                "values": values,
            }
            for metric, values in sorted(phase_workload_metrics(app, phase).items())
        }
        for phase in ("baseline", "post_rejit")
        if app.get(phase)
    }
    return {
        "label": label,
        "run_dir": str(run_dir),
        "safe_app": safe_app,
        "status": app.get("status"),
        "error": app.get("error"),
        "selected_workload": app.get("selected_workload"),
        "shim": shim_counts(run_dir, safe_app),
        "bpf": {
            "matched_programs_min_runs": len(ratios),
            "geomean_speedup": geomean(speedups),
            "wins": sum(1 for r in ratios if r["ratio"] < 0.995),
            "losses": sum(1 for r in ratios if r["ratio"] > 1.005),
            "ties": sum(1 for r in ratios if 0.995 <= r["ratio"] <= 1.005),
            "programs": ratios,
            "warnings": warnings,
        },
        "workload": workload,
    }


def parse_run_arg(value: str) -> tuple[str, pathlib.Path, str]:
    try:
        label, run_dir, safe_app = value.split(":", 2)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            "--run must be label:path:safe_app"
        ) from exc
    return label, pathlib.Path(run_dir), safe_app


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--run", action="append", type=parse_run_arg, required=True)
    parser.add_argument("--min-runs", type=int, default=100)
    parser.add_argument("--pretty", action="store_true")
    args = parser.parse_args()

    summaries = [
        summarize_run(label, run_dir, safe_app, args.min_runs)
        for label, run_dir, safe_app in args.run
    ]
    print(json.dumps(summaries, indent=2 if args.pretty else None, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
