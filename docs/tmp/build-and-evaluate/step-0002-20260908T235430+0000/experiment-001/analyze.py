#!/usr/bin/env python3
"""Validate and summarize the current-revision native opportunity experiment.

This is deliberately a post-hoc research script.  It does not participate in
the benchmark framework and never modifies the raw result.
"""

from __future__ import annotations

import argparse
import json
import math
import pathlib
import random
import statistics
from typing import Any


EXPECTED_RUNTIMES = ("kernel", "native_kernel")
NATIVE_PHASES = {
    "blob_upload_ns",
    "companion_load_ns",
    "native_link_cache_lookup_ns",
    "native_load_ns",
    "prog_load_ns",
    "prog_run_wall_ns",
}
BOOTSTRAP_SEED = 20260909
BOOTSTRAP_REPETITIONS = 50_000


def geometric_mean(values: list[float]) -> float:
    if not values or any(value <= 0 for value in values):
        raise ValueError("geometric mean requires nonempty positive values")
    return math.exp(math.fsum(math.log(value) for value in values) / len(values))


def percentile(sorted_values: list[float], quantile: float) -> float:
    position = (len(sorted_values) - 1) * quantile
    lower = math.floor(position)
    upper = math.ceil(position)
    if lower == upper:
        return sorted_values[lower]
    weight = position - lower
    return sorted_values[lower] * (1 - weight) + sorted_values[upper] * weight


def load_result(path: pathlib.Path) -> dict[str, Any]:
    document = json.loads(path.read_text())
    if document.get("status") != "completed":
        raise ValueError(f"raw result status is {document.get('status')!r}, not completed")
    benchmarks = document.get("benchmarks")
    if not isinstance(benchmarks, list):
        raise ValueError("raw result has no benchmarks list")
    return document


def analyze(
    document: dict[str, Any],
    expected_benchmarks: int,
    expected_samples: int,
    expected_warmups: int,
    expected_inner_repeat: int,
) -> dict[str, Any]:
    params = document.get("provenance", {}).get("params", {})
    expected_params = {
        "samples": expected_samples,
        "warmups": expected_warmups,
        "inner_repeat": expected_inner_repeat,
    }
    for key, expected in expected_params.items():
        if params.get(key) != expected:
            raise ValueError(f"provenance {key}={params.get(key)!r}, expected {expected}")

    benchmark_rows: list[dict[str, Any]] = []
    for benchmark in document["benchmarks"]:
        name = benchmark.get("name")
        runs = benchmark.get("runs")
        if not isinstance(name, str) or not isinstance(runs, list):
            raise ValueError("benchmark is missing name or runs")
        by_runtime = {run.get("runtime"): run for run in runs}
        if set(by_runtime) != set(EXPECTED_RUNTIMES) or len(runs) != len(EXPECTED_RUNTIMES):
            raise ValueError(f"{name}: expected exactly {EXPECTED_RUNTIMES}, found {list(by_runtime)}")

        sample_maps: dict[str, dict[int, dict[str, Any]]] = {}
        for runtime in EXPECTED_RUNTIMES:
            run = by_runtime[runtime]
            samples = run.get("samples")
            if not isinstance(samples, list) or len(samples) != expected_samples:
                raise ValueError(
                    f"{name}/{runtime}: expected {expected_samples} samples, "
                    f"found {len(samples) if isinstance(samples, list) else 'none'}"
                )
            indexed: dict[int, dict[str, Any]] = {}
            for sample in samples:
                index = sample.get("sample_index")
                if not isinstance(index, int) or index in indexed:
                    raise ValueError(f"{name}/{runtime}: invalid or duplicate sample index {index!r}")
                if sample.get("result") != benchmark.get("expected_result"):
                    raise ValueError(f"{name}/{runtime}[{index}]: result mismatch")
                if sample.get("retval") != benchmark.get("expected_retval"):
                    raise ValueError(f"{name}/{runtime}[{index}]: retval mismatch")
                if sample.get("timing_source") != "ktime":
                    raise ValueError(
                        f"{name}/{runtime}[{index}]: expected ktime, "
                        f"found {sample.get('timing_source')!r}"
                    )
                exec_ns = sample.get("exec_ns")
                if not isinstance(exec_ns, (int, float)) or exec_ns <= 0:
                    raise ValueError(f"{name}/{runtime}[{index}]: invalid exec_ns {exec_ns!r}")
                compile_ns = sample.get("compile_ns")
                if not isinstance(compile_ns, (int, float)) or compile_ns <= 0:
                    raise ValueError(f"{name}/{runtime}[{index}]: invalid compile_ns {compile_ns!r}")
                phases = sample.get("phases_ns")
                if not isinstance(phases, dict):
                    raise ValueError(f"{name}/{runtime}[{index}]: missing phase timings")
                if runtime == "native_kernel" and not NATIVE_PHASES.issubset(phases):
                    missing = sorted(NATIVE_PHASES - set(phases))
                    raise ValueError(f"{name}/{runtime}[{index}]: missing native phases {missing}")
                indexed[index] = sample
            expected_indexes = set(range(expected_samples))
            if set(indexed) != expected_indexes:
                raise ValueError(f"{name}/{runtime}: sample indexes are not 0..{expected_samples - 1}")
            sample_maps[runtime] = indexed

        kernel_values = [float(sample_maps["kernel"][i]["exec_ns"]) for i in range(expected_samples)]
        native_values = [
            float(sample_maps["native_kernel"][i]["exec_ns"]) for i in range(expected_samples)
        ]
        kernel_compile = [
            float(sample_maps["kernel"][i]["compile_ns"]) for i in range(expected_samples)
        ]
        native_compile = [
            float(sample_maps["native_kernel"][i]["compile_ns"]) for i in range(expected_samples)
        ]
        paired_ratios = [native_values[i] / kernel_values[i] for i in range(expected_samples)]

        size_ratios: list[float] = []
        for index in range(expected_samples):
            kernel_size = sample_maps["kernel"][index].get("code_size", {}).get("native_code_bytes")
            native_size = sample_maps["native_kernel"][index].get("code_size", {}).get(
                "native_code_bytes"
            )
            if not isinstance(kernel_size, (int, float)) or kernel_size <= 0:
                raise ValueError(f"{name}/kernel[{index}]: invalid native code size")
            if not isinstance(native_size, (int, float)) or native_size <= 0:
                raise ValueError(f"{name}/native_kernel[{index}]: invalid native code size")
            size_ratios.append(float(native_size) / float(kernel_size))

        kernel_median = statistics.median(kernel_values)
        native_median = statistics.median(native_values)
        kernel_compile_median = statistics.median(kernel_compile)
        native_compile_median = statistics.median(native_compile)
        median_ratio = native_median / kernel_median
        benchmark_rows.append(
            {
                "name": name,
                "kernel_exec_ns": kernel_values,
                "native_kernel_exec_ns": native_values,
                "kernel_compile_ns": kernel_compile,
                "native_kernel_compile_ns": native_compile,
                "paired_native_over_kernel": paired_ratios,
                "kernel_median_exec_ns": kernel_median,
                "native_kernel_median_exec_ns": native_median,
                "median_native_over_kernel": median_ratio,
                "median_kernel_over_native_speedup": 1.0 / median_ratio,
                "median_native_over_kernel_code_size": statistics.median(size_ratios),
                "kernel_median_compile_ns": kernel_compile_median,
                "native_kernel_median_compile_ns": native_compile_median,
                "median_native_over_kernel_compile_time": (
                    native_compile_median / kernel_compile_median
                ),
            }
        )

    if len(benchmark_rows) != expected_benchmarks:
        raise ValueError(f"expected {expected_benchmarks} benchmarks, found {len(benchmark_rows)}")
    names = [row["name"] for row in benchmark_rows]
    if len(names) != len(set(names)):
        raise ValueError("benchmark names are not unique")

    ratios = [float(row["median_native_over_kernel"]) for row in benchmark_rows]
    rng = random.Random(BOOTSTRAP_SEED)
    bootstrap = sorted(
        geometric_mean([ratios[rng.randrange(len(ratios))] for _ in ratios])
        for _ in range(BOOTSTRAP_REPETITIONS)
    )
    aggregate_ratio = geometric_mean(ratios)
    return {
        "metric_direction": "native_kernel_exec_ns / kernel_exec_ns; below 1 is faster",
        "benchmark_count": len(benchmark_rows),
        "sample_count_per_runtime": expected_samples,
        "correct_sample_count": len(benchmark_rows) * expected_samples * len(EXPECTED_RUNTIMES),
        "aggregate": {
            "geomean_native_over_kernel": aggregate_ratio,
            "geomean_kernel_over_native_speedup": 1.0 / aggregate_ratio,
            "bootstrap_95pct_native_over_kernel": [
                percentile(bootstrap, 0.025),
                percentile(bootstrap, 0.975),
            ],
            "bootstrap_seed": BOOTSTRAP_SEED,
            "bootstrap_repetitions": BOOTSTRAP_REPETITIONS,
            "wins_native_faster": sum(ratio < 1 for ratio in ratios),
            "ties": sum(ratio == 1 for ratio in ratios),
            "losses_native_slower": sum(ratio > 1 for ratio in ratios),
            "geomean_native_over_kernel_code_size": geometric_mean(
                [float(row["median_native_over_kernel_code_size"]) for row in benchmark_rows]
            ),
            "geomean_native_over_kernel_compile_time": geometric_mean(
                [float(row["median_native_over_kernel_compile_time"]) for row in benchmark_rows]
            ),
        },
        "benchmarks": benchmark_rows,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("result", type=pathlib.Path, help="raw metadata.json or details/result.json")
    parser.add_argument("--expected-benchmarks", type=int, default=29)
    parser.add_argument("--expected-samples", type=int, default=15)
    parser.add_argument("--expected-warmups", type=int, default=1)
    parser.add_argument("--expected-inner-repeat", type=int, default=100_000)
    parser.add_argument("--output", type=pathlib.Path)
    args = parser.parse_args()

    summary = analyze(
        load_result(args.result),
        args.expected_benchmarks,
        args.expected_samples,
        args.expected_warmups,
        args.expected_inner_repeat,
    )
    rendered = json.dumps(summary, indent=2, sort_keys=True) + "\n"
    if args.output:
        args.output.write_text(rendered)
    print(rendered, end="")


if __name__ == "__main__":
    main()
