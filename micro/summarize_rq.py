#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import random
import statistics
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
MICRO_DIR = REPO_ROOT / "micro"
RESULTS_DIR = MICRO_DIR / "results"
DEFAULT_RESULTS_CANDIDATES = (
    RESULTS_DIR / "pure_jit.latest.json",
    RESULTS_DIR / "runtime.latest.json",
    RESULTS_DIR / "latest.json",
)
DEFAULT_CORPUS = REPO_ROOT / "corpus" / "inventory.json"


def first_existing_path(candidates: tuple[Path, ...]) -> Path:
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return candidates[0]


DEFAULT_RESULTS = first_existing_path(DEFAULT_RESULTS_CANDIDATES)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Summarize current micro results against the active RQs.")
    parser.add_argument("--results", default=str(DEFAULT_RESULTS), help="Path to a run_micro JSON result file.")
    parser.add_argument("--corpus", default=str(DEFAULT_CORPUS), help="Path to a corpus inventory JSON file.")
    parser.add_argument("--output", help="Optional markdown output path.")
    parser.add_argument(
        "--bootstrap-iterations",
        type=int,
        default=5000,
        help="Bootstrap iterations for suite/category confidence intervals.",
    )
    parser.add_argument(
        "--bootstrap-seed",
        type=int,
        default=20260306,
        help="Random seed for bootstrap resampling.",
    )
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def format_ns(value: object) -> str:
    if value is None:
        return "n/a"
    number = float(value)
    if number >= 1_000_000:
        return f"{number / 1_000_000:.3f} ms"
    if number >= 1_000:
        return f"{number / 1_000:.3f} us"
    return f"{number:.0f} ns"


def format_ratio_value(value: object) -> str:
    if value in (None, 0):
        return "n/a"
    return f"{float(value):.2f}x"


def format_ratio(numerator: object, denominator: object) -> str:
    if numerator in (None, 0) or denominator in (None, 0):
        return "n/a"
    return format_ratio_value(float(numerator) / float(denominator))


def format_ci(interval: tuple[float, float] | None) -> str:
    if interval is None:
        return "n/a"
    low, high = interval
    return f"[{low:.2f}x, {high:.2f}x]"


def percentile(sorted_values: list[float], probability: float) -> float:
    if not sorted_values:
        raise ValueError("cannot compute percentile of an empty sample")
    if len(sorted_values) == 1:
        return sorted_values[0]
    rank = probability * (len(sorted_values) - 1)
    lower = int(math.floor(rank))
    upper = int(math.ceil(rank))
    if lower == upper:
        return sorted_values[lower]
    weight = rank - lower
    return sorted_values[lower] * (1.0 - weight) + sorted_values[upper] * weight


def geometric_mean(values: list[float]) -> float | None:
    filtered = [value for value in values if value > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def bootstrap_geometric_mean_ci(
    values: list[float],
    iterations: int,
    seed: int,
) -> tuple[float, float] | None:
    filtered = [value for value in values if value > 0.0]
    if not filtered:
        return None
    if len(filtered) == 1:
        return (filtered[0], filtered[0])

    rng = random.Random(seed)
    bootstraps: list[float] = []
    for _ in range(iterations):
        sample = [filtered[rng.randrange(len(filtered))] for _ in range(len(filtered))]
        estimate = geometric_mean(sample)
        if estimate is not None:
            bootstraps.append(estimate)

    bootstraps.sort()
    return percentile(bootstraps, 0.025), percentile(bootstraps, 0.975)


def bootstrap_ratio_ci(
    numerator_samples: list[float],
    denominator_samples: list[float],
    iterations: int,
    seed: int,
    baseline_numerator_samples: list[float] | None = None,
    baseline_denominator_samples: list[float] | None = None,
) -> tuple[float, float] | None:
    if not numerator_samples or not denominator_samples:
        return None

    rng = random.Random(seed)
    bootstraps: list[float] = []
    for _ in range(iterations):
        numerator_resample = [numerator_samples[rng.randrange(len(numerator_samples))] for _ in range(len(numerator_samples))]
        denominator_resample = [
            denominator_samples[rng.randrange(len(denominator_samples))] for _ in range(len(denominator_samples))
        ]
        numerator = float(statistics.median(numerator_resample))
        denominator = float(statistics.median(denominator_resample))

        if baseline_numerator_samples is not None and baseline_denominator_samples is not None:
            baseline_num_resample = [
                baseline_numerator_samples[rng.randrange(len(baseline_numerator_samples))]
                for _ in range(len(baseline_numerator_samples))
            ]
            baseline_den_resample = [
                baseline_denominator_samples[rng.randrange(len(baseline_denominator_samples))]
                for _ in range(len(baseline_denominator_samples))
            ]
            numerator = max(numerator - float(statistics.median(baseline_num_resample)), 0.0)
            denominator = max(denominator - float(statistics.median(baseline_den_resample)), 0.0)

        if numerator > 0.0 and denominator > 0.0:
            bootstraps.append(numerator / denominator)

    if not bootstraps:
        return None

    bootstraps.sort()
    return percentile(bootstraps, 0.025), percentile(bootstraps, 0.975)


def run_lookup(benchmark: dict[str, object]) -> dict[str, dict[str, object]]:
    return {str(run["runtime"]): run for run in benchmark["runs"]}


def exec_samples(run: dict[str, object]) -> list[float]:
    return [float(sample["exec_ns"]) for sample in run.get("samples", []) if sample.get("exec_ns") is not None]


def benchmark_raw_ratio(benchmark: dict[str, object]) -> float | None:
    runtime_comparison = benchmark.get("runtime_comparison", {})
    if runtime_comparison.get("llvmbpf_over_kernel_exec_ratio") is not None:
        return float(runtime_comparison["llvmbpf_over_kernel_exec_ratio"])

    runs = run_lookup(benchmark)
    llvm = runs.get("llvmbpf", {})
    kernel = runs.get("kernel", {})
    llvm_exec = llvm.get("exec_ns", {}).get("median")
    kernel_exec = kernel.get("exec_ns", {}).get("median")
    if llvm_exec in (None, 0) or kernel_exec in (None, 0):
        return None
    return float(llvm_exec) / float(kernel_exec)


def win_counts(ratios: list[float], tie_epsilon: float = 0.02) -> tuple[int, int, int]:
    llvmbpf_wins = 0
    kernel_wins = 0
    ties = 0
    for ratio in ratios:
        if abs(ratio - 1.0) <= tie_epsilon:
            ties += 1
        elif ratio < 1.0:
            llvmbpf_wins += 1
        else:
            kernel_wins += 1
    return llvmbpf_wins, kernel_wins, ties


def perf_runtime_summary(results: dict[str, object]) -> dict[str, dict[str, object]]:
    runtime_metrics: dict[str, dict[str, list[float]]] = {}
    for benchmark in results.get("benchmarks", []):
        for run in benchmark.get("runs", []):
            runtime = str(run["runtime"])
            bucket = runtime_metrics.setdefault(
                runtime,
                {"ipc": [], "branch_miss": [], "cache_miss": [], "hw_counter": []},
            )
            derived = run.get("derived_metrics", {})
            meta = run.get("perf_counters_meta", {})
            if derived.get("ipc_median") is not None:
                bucket["ipc"].append(float(derived["ipc_median"]))
            if derived.get("branch_miss_rate_median") is not None:
                bucket["branch_miss"].append(float(derived["branch_miss_rate_median"]))
            if derived.get("cache_miss_rate_median") is not None:
                bucket["cache_miss"].append(float(derived["cache_miss_rate_median"]))
            bucket["hw_counter"].append(1.0 if meta.get("hardware_counters_observed") else 0.0)

    summary: dict[str, dict[str, object]] = {}
    for runtime, metrics in runtime_metrics.items():
        hw_seen = sum(1 for flag in metrics["hw_counter"] if flag > 0.0)
        total = len(metrics["hw_counter"])
        summary[runtime] = {
            "benchmarks": total,
            "hw_observed": f"{hw_seen}/{total}" if total else "0/0",
            "ipc_median": statistics.median(metrics["ipc"]) if metrics["ipc"] else None,
            "branch_miss_rate_median": statistics.median(metrics["branch_miss"]) if metrics["branch_miss"] else None,
            "cache_miss_rate_median": statistics.median(metrics["cache_miss"]) if metrics["cache_miss"] else None,
        }
    return summary


def summarize_results(results: dict[str, object], bootstrap_iterations: int, bootstrap_seed: int) -> str:
    lines: list[str] = []
    host = results.get("host", {})
    defaults = results.get("defaults", {})
    suite_name = str(results.get("suite", "unknown"))
    benchmarks = list(results.get("benchmarks", []))

    lines.append("# Characterization Summary")
    lines.append("")
    lines.append("## Environment")
    lines.append("")
    lines.append(f"- Suite: `{suite_name}`")
    lines.append(f"- Host: `{host.get('hostname', 'unknown')}` on `{host.get('platform', 'unknown')}`")
    lines.append(
        f"- Requested defaults: iterations={defaults.get('iterations')}, "
        f"warmups={defaults.get('warmups')}, repeat={defaults.get('repeat')}, "
        f"perf_counters={defaults.get('perf_counters')}"
    )
    lines.append(f"- Shuffle seed: `{defaults.get('shuffle_seed')}`")
    lines.append(f"- Bootstrap summary statistics: iterations={bootstrap_iterations}, seed={bootstrap_seed}")

    raw_ratios = [ratio for benchmark in benchmarks if (ratio := benchmark_raw_ratio(benchmark)) is not None]
    adjusted_ratios = [
        float(benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio"))
        for benchmark in benchmarks
        if benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio") is not None
    ]

    lines.append("")
    lines.append("## Suite-Level Comparison")
    lines.append("")
    lines.append("| Metric | Value | 95% bootstrap CI |")
    lines.append("| --- | ---: | ---: |")
    raw_gmean = geometric_mean(raw_ratios)
    raw_ci = bootstrap_geometric_mean_ci(raw_ratios, bootstrap_iterations, bootstrap_seed)
    lines.append(
        f"| Raw exec `llvmbpf/kernel` geometric mean | {format_ratio_value(raw_gmean)} | {format_ci(raw_ci)} |"
    )
    if suite_name in ("micro_pure_jit", "micro_staged_codegen"):
        adjusted_gmean = geometric_mean(adjusted_ratios)
        adjusted_ci = bootstrap_geometric_mean_ci(adjusted_ratios, bootstrap_iterations, bootstrap_seed + 1)
        lines.append(
            f"| Baseline-adjusted exec `llvmbpf/kernel` geometric mean | {format_ratio_value(adjusted_gmean)} | {format_ci(adjusted_ci)} |"
        )

    raw_wins = win_counts(raw_ratios)
    lines.append(
        f"| Raw wins (`llvmbpf / kernel / tie`) | `{raw_wins[0]} / {raw_wins[1]} / {raw_wins[2]}` | n/a |"
    )
    if suite_name in ("micro_pure_jit", "micro_staged_codegen"):
        adjusted_wins = win_counts(adjusted_ratios)
        lines.append(
            f"| Adjusted wins (`llvmbpf / kernel / tie`) | `{adjusted_wins[0]} / {adjusted_wins[1]} / {adjusted_wins[2]}` | n/a |"
        )

    lines.append("")
    lines.append("## Benchmark-Level Comparison")
    lines.append("")
    if suite_name in ("micro_pure_jit", "micro_staged_codegen"):
        lines.append(
            "The adjusted ratio subtracts each runtime's own `simple` median from the benchmark median before forming "
            "the `llvmbpf/kernel` ratio. This is the primary pure-jit view."
        )
        lines.append("Calibration-oriented baseline rows are kept in the table, but excluded from directional rankings.")
        lines.append("")
        lines.append(
            "| Benchmark | Category | Family | Level | llvmbpf exec | kernel exec | Raw ratio | Adjusted ratio | Adjusted ratio 95% CI |"
        )
        lines.append("| --- | --- | --- | --- | ---: | ---: | ---: | ---: | ---: |")

        baseline_record = next((benchmark for benchmark in benchmarks if benchmark.get("name") == "simple"), None)
        baseline_runs = run_lookup(baseline_record) if baseline_record is not None else {}
        baseline_name = str(baseline_record["name"]) if baseline_record is not None else None
        baseline_llvm_samples = exec_samples(baseline_runs["llvmbpf"]) if "llvmbpf" in baseline_runs else []
        baseline_kernel_samples = exec_samples(baseline_runs["kernel"]) if "kernel" in baseline_runs else []

        for index, benchmark in enumerate(benchmarks):
            runs = run_lookup(benchmark)
            llvm = runs.get("llvmbpf", {})
            kernel = runs.get("kernel", {})
            llvm_exec = llvm.get("exec_ns", {}).get("median")
            kernel_exec = kernel.get("exec_ns", {}).get("median")
            adj_ratio = benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio")
            ci = None
            if benchmark.get("name") != baseline_name:
                ci = bootstrap_ratio_ci(
                    exec_samples(llvm),
                    exec_samples(kernel),
                    bootstrap_iterations,
                    bootstrap_seed + 101 + index,
                    baseline_llvm_samples,
                    baseline_kernel_samples,
                )
            lines.append(
                f"| `{benchmark['name']}` | `{benchmark.get('category', '-')}` | `{benchmark.get('family', '-')}` | "
                f"`{benchmark.get('level', '-')}` | {format_ns(llvm_exec)} | {format_ns(kernel_exec)} | "
                f"{format_ratio(llvm_exec, kernel_exec)} | {format_ratio_value(adj_ratio)} | {format_ci(ci)} |"
            )
    else:
        lines.append("| Benchmark | Category | Family | llvmbpf exec | kernel exec | Raw ratio |")
        lines.append("| --- | --- | --- | ---: | ---: | ---: |")
        for benchmark in benchmarks:
            runs = run_lookup(benchmark)
            llvm = runs.get("llvmbpf", {})
            kernel = runs.get("kernel", {})
            llvm_exec = llvm.get("exec_ns", {}).get("median")
            kernel_exec = kernel.get("exec_ns", {}).get("median")
            lines.append(
                f"| `{benchmark['name']}` | `{benchmark.get('category', '-')}` | `{benchmark.get('family', '-')}` | "
                f"{format_ns(llvm_exec)} | {format_ns(kernel_exec)} | {format_ratio(llvm_exec, kernel_exec)} |"
            )

    if suite_name in ("micro_pure_jit", "micro_staged_codegen"):
        for grouping_key, heading in (("category", "Category-Level"), ("family", "Family-Level")):
            grouped: dict[str, list[float]] = {}
            for benchmark in benchmarks:
                ratio = benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio")
                if ratio is None:
                    continue
                grouped.setdefault(str(benchmark.get(grouping_key, "unknown")), []).append(float(ratio))

            lines.append("")
            lines.append(f"## {heading} Adjusted Summary")
            lines.append("")
            lines.append("| Group | Benchmarks | Adjusted gmean | 95% bootstrap CI | Wins (`llvmbpf/kernel/tie`) |")
            lines.append("| --- | ---: | ---: | ---: | --- |")
            for index, (group_name, ratios) in enumerate(sorted(grouped.items())):
                ci = bootstrap_geometric_mean_ci(ratios, bootstrap_iterations, bootstrap_seed + 1000 + index)
                wins = win_counts(ratios)
                lines.append(
                    f"| `{group_name}` | {len(ratios)} | {format_ratio_value(geometric_mean(ratios))} | "
                    f"{format_ci(ci)} | `{wins[0]}/{wins[1]}/{wins[2]}` |"
                )

        ranked = [
            (
                str(benchmark["name"]),
                str(benchmark.get("family", "-")),
                str(benchmark.get("level", "-")),
                float(benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio")),
            )
            for benchmark in benchmarks
            if benchmark.get("runtime_comparison", {}).get("llvmbpf_over_kernel_adjusted_exec_ratio") is not None
            if benchmark.get("category") != "baseline"
        ]
        ranked.sort(key=lambda item: item[3])

        lines.append("")
        lines.append("## Directional Findings")
        lines.append("")
        lines.append("### Strongest llvmbpf advantages")
        lines.append("")
        for name, family, level, ratio in ranked[:5]:
            lines.append(f"- `{name}` (`{family}`, `{level}`): adjusted `llvmbpf/kernel = {ratio:.2f}x`")

        lines.append("")
        lines.append("### Kernel-leading or parity cases")
        lines.append("")
        for name, family, level, ratio in reversed(ranked[-5:]):
            lines.append(f"- `{name}` (`{family}`, `{level}`): adjusted `llvmbpf/kernel = {ratio:.2f}x`")

    perf_summary = perf_runtime_summary(results)
    if perf_summary:
        lines.append("")
        lines.append("## Perf-Counter Signal")
        lines.append("")
        lines.append("| Runtime | Benchmarks | HW counters observed | Median IPC across suite | Median branch-miss rate | Median cache-miss rate |")
        lines.append("| --- | ---: | --- | ---: | ---: | ---: |")
        for runtime, summary in sorted(perf_summary.items()):
            lines.append(
                f"| `{runtime}` | {summary['benchmarks']} | {summary['hw_observed']} | "
                f"{summary['ipc_median'] if summary['ipc_median'] is not None else 'n/a'} | "
                f"{summary['branch_miss_rate_median'] if summary['branch_miss_rate_median'] is not None else 'n/a'} | "
                f"{summary['cache_miss_rate_median'] if summary['cache_miss_rate_median'] is not None else 'n/a'} |"
            )

    return "\n".join(lines)


def summarize_corpus(corpus: dict[str, object]) -> str:
    lines = [
        "",
        "## Corpus Snapshot",
        "",
        "| Repo | Program sources |",
        "| --- | ---: |",
    ]
    for repo in corpus.get("repos", []):
        lines.append(f"| `{repo['name']}` | {repo.get('num_program_sources', 0)} |")
    lines.append(f"| **Total** | **{corpus.get('total_program_sources', 0)}** |")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    results = load_json(Path(args.results).resolve())
    report = summarize_results(results, args.bootstrap_iterations, args.bootstrap_seed)

    corpus_path = Path(args.corpus).resolve()
    if corpus_path.exists():
        report = report + "\n" + summarize_corpus(load_json(corpus_path))

    if args.output:
        output_path = Path(args.output).resolve()
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(report + "\n")
        print(f"[done] wrote {output_path}")
        return 0

    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
