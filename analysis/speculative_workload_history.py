#!/usr/bin/env python3
"""Reconstruct paired workload-throughput batches from committed corpus data.

The corpus collector intentionally stores raw workload output.  This analysis
tool reads a declared interval of per-app artifacts from one Git revision,
validates their lifecycle and pass metadata, and computes post-load-time over
baseline workload-throughput ratios.  It never changes or summarizes data in
the benchmark framework.
"""
from __future__ import annotations

import argparse
import json
import math
import random
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

sys.path.insert(0, str(Path(__file__).resolve().parent))
from extract_workload_metrics import parse_kernel_pktgen, parse_stress_ng


RUN_RE = re.compile(r"^x86_kvm_corpus_(\d{8}_\d{6}_\d{6})$")
BOOTSTRAP_DRAWS = 100_000
BOOTSTRAP_SEED = 20_260_924


class EvidenceError(RuntimeError):
    """A historical artifact does not satisfy the declared comparison."""


@dataclass(frozen=True)
class RunResult:
    run: str
    introduced_by: str
    baseline: float
    optimized: float

    @property
    def ratio(self) -> float:
        return self.optimized / self.baseline


def git_text(*args: str) -> str:
    completed = subprocess.run(
        ["git", *args],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise EvidenceError(f"git {' '.join(args)} failed: {detail}")
    return completed.stdout


def load_json(ref: str, path: str) -> Mapping[str, Any]:
    try:
        payload = json.loads(git_text("show", f"{ref}:{path}"))
    except json.JSONDecodeError as exc:
        raise EvidenceError(f"invalid JSON at {ref}:{path}: {exc}") from exc
    if not isinstance(payload, Mapping):
        raise EvidenceError(f"expected an object at {ref}:{path}")
    return payload


def leaf_workloads(records: Iterable[Mapping[str, Any]]) -> Iterable[Mapping[str, Any]]:
    for record in records:
        components = record.get("components") or []
        if components:
            if not isinstance(components, list):
                raise EvidenceError("workload components must be a list")
            yield from leaf_workloads(components)
        else:
            yield record


def phase_throughput(app: Mapping[str, Any], phase: str, metric: str) -> float:
    phase_payload = app.get(phase)
    if not isinstance(phase_payload, Mapping):
        raise EvidenceError(f"missing {phase} payload")
    workloads = phase_payload.get("workloads") or []
    if not isinstance(workloads, list) or not workloads:
        raise EvidenceError(f"missing {phase} workloads")

    total = 0.0
    leaf_count = 0
    for workload in leaf_workloads(workloads):
        leaf_count += 1
        if int(workload.get("returncode", -1)) != 0:
            raise EvidenceError(f"{phase} workload returned {workload.get('returncode')}")
        config = workload.get("config") or {}
        tool = config.get("tool") if isinstance(config, Mapping) else None
        if metric == "pktgen-pps":
            if tool != "kernel_pktgen":
                raise EvidenceError(f"{phase} leaf uses {tool!r}, expected kernel_pktgen")
            parsed = parse_kernel_pktgen(str(workload.get("stdout") or ""))
            if "packets_per_second" not in parsed:
                raise EvidenceError(f"{phase} pktgen leaf has no unique completed result")
            total += float(parsed["packets_per_second"])
        elif metric == "stress-ng-bogo-ops":
            if tool != "stress-ng":
                raise EvidenceError(f"{phase} leaf uses {tool!r}, expected stress-ng")
            parsed = parse_stress_ng(
                str(workload.get("stdout") or ""),
                str(workload.get("stderr") or ""),
            )
            if not parsed.get("per_stressor"):
                raise EvidenceError(f"{phase} stress-ng leaf has no metric rows")
            total += float(parsed["bogo_ops_total"])
        else:  # argparse constrains this; keep the library path fail-fast.
            raise EvidenceError(f"unsupported metric {metric}")
    if leaf_count == 0 or total <= 0:
        raise EvidenceError(f"{phase} produced no positive throughput")
    return total


def selected_app_paths(ref: str, app_slug: str, start: str, end: str) -> list[tuple[str, str]]:
    start_match = RUN_RE.fullmatch(start)
    end_match = RUN_RE.fullmatch(end)
    if not start_match or not end_match:
        raise EvidenceError("start and end must be complete x86_kvm_corpus_<timestamp> names")
    start_stamp, end_stamp = start_match.group(1), end_match.group(1)
    if start_stamp > end_stamp:
        raise EvidenceError("start run is after end run")

    suffix = f"/details/apps/{app_slug}.json"
    selected: list[tuple[str, str]] = []
    for path in git_text("ls-tree", "-r", "--name-only", ref, "--", "corpus/results").splitlines():
        if not path.endswith(suffix):
            continue
        parts = path.split("/")
        if len(parts) < 4:
            continue
        match = RUN_RE.fullmatch(parts[2])
        if match and start_stamp <= match.group(1) <= end_stamp:
            selected.append((parts[2], path))
    return sorted(selected)


def introduction_commits(ref: str, paths: Sequence[str]) -> dict[str, str]:
    output = git_text(
        "log",
        "--format=@@%H",
        "--name-status",
        "--diff-filter=A",
        ref,
        "--",
        *paths,
    )
    commits: dict[str, str] = {}
    current = ""
    for line in output.splitlines():
        if line.startswith("@@"):
            current = line[2:]
            continue
        if line.startswith("A\t") and current:
            commits.setdefault(line.split("\t", 1)[1], current)
    missing = [path for path in paths if path not in commits]
    if missing:
        raise EvidenceError(f"no introducing commit found for: {', '.join(missing)}")
    return commits


def validate_and_measure(
    ref: str,
    app_name: str,
    expected_passes: Sequence[str],
    workload_seconds: float,
    metric: str,
    run: str,
    app_path: str,
    introduced_by: str,
) -> RunResult:
    root = f"corpus/results/{run}"
    metadata = load_json(ref, f"{root}/metadata.json")
    app = load_json(ref, app_path)

    if metadata.get("status") != "completed" or metadata.get("suite") != "corpus":
        raise EvidenceError(f"{run}: suite did not complete as corpus")
    if not math.isclose(float(metadata.get("workload_seconds", -1)), workload_seconds):
        raise EvidenceError(f"{run}: workload duration is not {workload_seconds:g}s")
    metadata_passes = (metadata.get("config") or {}).get("enabled_passes") or []
    if list(metadata_passes) != list(expected_passes):
        raise EvidenceError(f"{run}: metadata passes {metadata_passes!r} do not match")
    if app.get("app") != app_name:
        raise EvidenceError(f"{run}: app is {app.get('app')!r}, expected {app_name!r}")
    if app.get("status") != "ok" or app.get("error") not in ("", None):
        raise EvidenceError(f"{run}: app status/error is {app.get('status')!r}/{app.get('error')!r}")

    rejit = app.get("rejit_result") or {}
    if rejit.get("mode") != "loadtime" or rejit.get("status") != "ok":
        raise EvidenceError(f"{run}: expected successful load-time ReJIT")
    if list(rejit.get("enabled_passes") or []) != list(expected_passes):
        raise EvidenceError(f"{run}: app pass list does not match")

    baseline = phase_throughput(app, "baseline", metric)
    optimized = phase_throughput(app, "post_rejit", metric)
    return RunResult(run, introduced_by, baseline, optimized)


def format_count(value: float) -> str:
    return str(int(value)) if value.is_integer() else f"{value:.6f}"


def percentile(sorted_values: Sequence[float], probability: float) -> float:
    position = probability * (len(sorted_values) - 1)
    lower = int(math.floor(position))
    upper = int(math.ceil(position))
    if lower == upper:
        return sorted_values[lower]
    weight = position - lower
    return sorted_values[lower] * (1.0 - weight) + sorted_values[upper] * weight


def bootstrap_geomean_interval(ratios: Sequence[float]) -> tuple[float, float]:
    rng = random.Random(BOOTSTRAP_SEED)
    n = len(ratios)
    draws = []
    for _ in range(BOOTSTRAP_DRAWS):
        logs = [math.log(ratios[rng.randrange(n)]) for _ in range(n)]
        draws.append(math.exp(sum(logs) / n))
    draws.sort()
    return percentile(draws, 0.025), percentile(draws, 0.975)


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    parser.add_argument("--git-ref", required=True)
    parser.add_argument("--app", required=True, help="application name, for example cilium/agent")
    parser.add_argument("--start-run", required=True)
    parser.add_argument("--end-run", required=True)
    parser.add_argument("--passes", required=True, help="ordered comma-separated pass list")
    parser.add_argument(
        "--metric",
        required=True,
        choices=("pktgen-pps", "stress-ng-bogo-ops"),
    )
    parser.add_argument("--workload-seconds", type=float, default=180.0)
    parser.add_argument("--expected-runs", type=int, required=True)
    args = parser.parse_args(argv)

    try:
        ref = git_text("rev-parse", args.git_ref).strip()
        app_slug = args.app.replace("/", "__")
        selected = selected_app_paths(ref, app_slug, args.start_run, args.end_run)
        if len(selected) != args.expected_runs:
            raise EvidenceError(
                f"selected {len(selected)} runs, expected {args.expected_runs}: "
                + ", ".join(run for run, _ in selected)
            )
        commits = introduction_commits(ref, [path for _, path in selected])
        passes = [name for name in args.passes.split(",") if name]
        if not passes:
            raise EvidenceError("empty pass list")
        results: list[RunResult] = []
        invalid: list[tuple[str, str]] = []
        for run, path in selected:
            try:
                results.append(
                    validate_and_measure(
                        ref,
                        args.app,
                        passes,
                        args.workload_seconds,
                        args.metric,
                        run,
                        path,
                        commits[path],
                    )
                )
            except (EvidenceError, ValueError) as exc:
                invalid.append((run, str(exc)))
    except (EvidenceError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1

    print(f"# Historical workload-throughput reconstruction: {args.app}")
    print()
    print(f"Git revision: `{ref}`  ")
    print(f"Passes: `{','.join(passes)}`  ")
    print(f"Metric: `{args.metric}` (optimized / baseline)  ")
    print(f"Configured workload duration: `{args.workload_seconds:g}` seconds")
    print()
    if invalid:
        print("## Invalid rows")
        print()
        print("| Run | Reason |")
        print("| --- | --- |")
        for run, reason in invalid:
            print(f"| `{run}` | {reason} |")
        print()

    if not results:
        print("No valid rows were available for aggregation.")
        return 1

    ratios = [row.ratio for row in results]
    geomean = math.exp(sum(math.log(ratio) for ratio in ratios) / len(ratios))
    ci_low, ci_high = bootstrap_geomean_interval(ratios)
    wins = sum(ratio > 1.0 for ratio in ratios)
    losses = sum(ratio < 1.0 for ratio in ratios)
    ties = len(ratios) - wins - losses

    print("## Valid rows")
    print()
    print("| Run | Introduced by | Baseline | Optimized | Ratio |")
    print("| --- | --- | ---: | ---: | ---: |")
    for row in results:
        print(
            f"| `{row.run}` | `{row.introduced_by[:12]}` | "
            f"{format_count(row.baseline)} | {format_count(row.optimized)} | {row.ratio:.10f} |"
        )
    print()
    print(f"Geometric mean optimized/baseline: `{geomean:.10f}`  ")
    print(
        f"95% run-level percentile bootstrap interval: `{ci_low:.10f}`--`{ci_high:.10f}` "
        f"({BOOTSTRAP_DRAWS} draws, seed {BOOTSTRAP_SEED})  "
    )
    print(f"Wins/losses/ties: `{wins}/{losses}/{ties}`  ")
    print(f"Observed ratio range: `{min(ratios):.10f}`--`{max(ratios):.10f}`")
    if invalid:
        print(f"Inspected rows: `{len(results) + len(invalid)}`; invalid rows: `{len(invalid)}`")
        return 1
    print(f"Inspected rows: `{len(results)}`; invalid rows: `0`")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
