#!/usr/bin/env python3
"""Validate and summarize the proof-bound native execution experiment."""

from __future__ import annotations

import argparse
import json
import math
import pathlib
import random
import statistics
from typing import Any


RUNTIMES = ("kernel", "native_kernel")
BOUND_PHASES = {"proof_open_ns", "proof_verifier_load_ns", "prog_load_ns"}
SEED = 20260909
BOOTSTRAPS = 50_000


def geomean(values: list[float]) -> float:
    if not values or any(value <= 0 for value in values):
        raise ValueError("geomean requires positive values")
    return math.exp(math.fsum(math.log(value) for value in values) / len(values))


def percentile(values: list[float], q: float) -> float:
    pos = (len(values) - 1) * q
    lo, hi = math.floor(pos), math.ceil(pos)
    return values[lo] if lo == hi else values[lo] * (hi - pos) + values[hi] * (pos - lo)


def numeric(sample: dict[str, Any], key: str, where: str) -> float:
    value = sample.get(key)
    if not isinstance(value, (int, float)) or value <= 0:
        raise ValueError(f"{where}: invalid {key} {value!r}")
    return float(value)


def analyze(path: pathlib.Path) -> dict[str, Any]:
    doc = json.loads(path.read_text())
    if doc.get("status") != "completed":
        raise ValueError(f"status={doc.get('status')!r}, expected 'completed'")
    params = doc.get("provenance", {}).get("params", {})
    expected_params = {"samples": 15, "warmups": 1, "inner_repeat": 100_000}
    for key, expected in expected_params.items():
        if params.get(key) != expected:
            raise ValueError(f"{key}={params.get(key)!r}, expected {expected}")

    benchmarks = doc.get("benchmarks")
    if not isinstance(benchmarks, list) or len(benchmarks) != 29:
        raise ValueError("expected exactly 29 benchmarks")
    rows: list[dict[str, Any]] = []
    for bench in benchmarks:
        name = bench.get("name")
        runs = bench.get("runs")
        if not isinstance(name, str) or not isinstance(runs, list):
            raise ValueError("benchmark has no name/runs")
        by_runtime = {run.get("runtime"): run for run in runs}
        if set(by_runtime) != set(RUNTIMES) or len(runs) != 2:
            raise ValueError(f"{name}: expected exactly {RUNTIMES}")

        samples: dict[str, list[dict[str, Any]]] = {}
        for runtime in RUNTIMES:
            current = by_runtime[runtime].get("samples")
            if not isinstance(current, list) or len(current) != 15:
                raise ValueError(f"{name}/{runtime}: expected 15 samples")
            if [sample.get("sample_index") for sample in current] != list(range(15)):
                raise ValueError(f"{name}/{runtime}: non-canonical sample indexes")
            for index, sample in enumerate(current):
                where = f"{name}/{runtime}[{index}]"
                if sample.get("result") != bench.get("expected_result"):
                    raise ValueError(f"{where}: result mismatch")
                if sample.get("retval") != bench.get("expected_retval"):
                    raise ValueError(f"{where}: retval mismatch")
                if sample.get("timing_source") != "ktime":
                    raise ValueError(f"{where}: timing source is not ktime")
                numeric(sample, "exec_ns", where)
                numeric(sample, "compile_ns", where)
                phases = sample.get("phases_ns")
                if not isinstance(phases, dict):
                    raise ValueError(f"{where}: no phase timings")
                if runtime == "native_kernel":
                    missing = BOUND_PHASES - phases.keys()
                    if missing:
                        raise ValueError(f"{where}: missing bound phases {sorted(missing)}")
                    for phase in BOUND_PHASES:
                        numeric(phases, phase, where)
            samples[runtime] = current

        kernel_exec = [numeric(s, "exec_ns", name) for s in samples["kernel"]]
        native_exec = [numeric(s, "exec_ns", name) for s in samples["native_kernel"]]
        kernel_load = [numeric(s, "compile_ns", name) for s in samples["kernel"]]
        native_load = [numeric(s, "compile_ns", name) for s in samples["native_kernel"]]
        proof_load = [
            numeric(s["phases_ns"], "proof_verifier_load_ns", name)
            for s in samples["native_kernel"]
        ]
        proof_open = [
            numeric(s["phases_ns"], "proof_open_ns", name)
            for s in samples["native_kernel"]
        ]
        kernel_size = [numeric(s["code_size"], "native_code_bytes", name)
                       for s in samples["kernel"]]
        native_size = [numeric(s["code_size"], "native_code_bytes", name)
                       for s in samples["native_kernel"]]
        kernel_median = statistics.median(kernel_exec)
        native_median = statistics.median(native_exec)
        load_kernel_median = statistics.median(kernel_load)
        load_native_median = statistics.median(native_load)
        ratio = native_median / kernel_median
        rows.append({
            "name": name,
            "kernel_median_exec_ns": kernel_median,
            "native_median_exec_ns": native_median,
            "median_native_over_kernel": ratio,
            "median_kernel_over_native_speedup": 1.0 / ratio,
            "kernel_median_load_ns": load_kernel_median,
            "native_median_load_ns": load_native_median,
            "median_native_over_kernel_load": load_native_median / load_kernel_median,
            "proof_median_open_ns": statistics.median(proof_open),
            "proof_median_verifier_load_ns": statistics.median(proof_load),
            "median_native_over_kernel_code_size": (
                statistics.median(native_size) / statistics.median(kernel_size)
            ),
        })

    if len({row["name"] for row in rows}) != 29:
        raise ValueError("benchmark names are not unique")
    ratios = [row["median_native_over_kernel"] for row in rows]
    rng = random.Random(SEED)
    bootstrap = sorted(
        geomean([ratios[rng.randrange(len(ratios))] for _ in ratios])
        for _ in range(BOOTSTRAPS)
    )
    aggregate_ratio = geomean(ratios)
    kernel_load_medians = [row["kernel_median_load_ns"] for row in rows]
    native_load_medians = [row["native_median_load_ns"] for row in rows]
    return {
        "source": str(path),
        "metric_direction": "native_kernel / kernel; below 1 is faster",
        "benchmark_count": 29,
        "samples_per_runtime": 15,
        "correct_samples": 870,
        "bound_native_samples": 435,
        "aggregate": {
            "geomean_native_over_kernel_exec": aggregate_ratio,
            "geomean_kernel_over_native_speedup": 1.0 / aggregate_ratio,
            "bootstrap_95pct_native_over_kernel": [
                percentile(bootstrap, 0.025), percentile(bootstrap, 0.975)
            ],
            "bootstrap_seed": SEED,
            "bootstrap_repetitions": BOOTSTRAPS,
            "wins_native_faster": sum(value < 1 for value in ratios),
            "ties": sum(value == 1 for value in ratios),
            "losses_native_slower": sum(value > 1 for value in ratios),
            "geomean_native_over_kernel_code_size": geomean([
                row["median_native_over_kernel_code_size"] for row in rows
            ]),
            "geomean_native_over_kernel_load": geomean([
                row["median_native_over_kernel_load"] for row in rows
            ]),
            "median_of_program_median_kernel_load_ns": statistics.median(kernel_load_medians),
            "median_of_program_median_native_load_ns": statistics.median(native_load_medians),
            "median_of_program_median_proof_open_ns": statistics.median([
                row["proof_median_open_ns"] for row in rows
            ]),
            "median_of_program_median_proof_verifier_load_ns": statistics.median([
                row["proof_median_verifier_load_ns"] for row in rows
            ]),
        },
        "benchmarks": rows,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("result", type=pathlib.Path)
    parser.add_argument("--output", type=pathlib.Path)
    args = parser.parse_args()
    rendered = json.dumps(analyze(args.result), indent=2, sort_keys=True) + "\n"
    if args.output:
        args.output.write_text(rendered)
    print(rendered, end="")


if __name__ == "__main__":
    main()
