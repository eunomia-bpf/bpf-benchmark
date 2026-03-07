#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

import numpy as np
from scipy.stats import mannwhitneyu, wilcoxon


ROOT_DIR = Path(__file__).resolve().parent
DEFAULT_INPUT = ROOT_DIR / "results" / "pure_jit_rigorous.json"
DEFAULT_OUTPUT = ROOT_DIR / "results" / "pure_jit_rigorous_analysis.md"
BOOTSTRAP_ITERATIONS = 10_000
DEFAULT_SEED = 0
RUNTIME_ORDER = ("llvmbpf", "kernel")
METRIC_CHOICES = ("exec_ns", "wall_exec_ns")
KERNEL_EXEC_SUBRESOLUTION_NS = 100.0
KERNEL_EXEC_SUBRESOLUTION_NOTE = "kernel exec < 100ns: below ktime resolution"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Analyze statistical properties of pure-JIT microbenchmark results.")
    parser.add_argument("input", nargs="?", default=str(DEFAULT_INPUT), help="Input benchmark JSON.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Markdown report output path.")
    parser.add_argument(
        "--metric",
        default="exec_ns",
        choices=METRIC_CHOICES,
        help="Execution metric to analyze: exec_ns (default) or wall_exec_ns.",
    )
    parser.add_argument(
        "--bootstrap-iterations",
        type=int,
        default=BOOTSTRAP_ITERATIONS,
        help="Bootstrap iterations for confidence intervals.",
    )
    parser.add_argument("--seed", type=int, default=DEFAULT_SEED, help="Random seed for reproducible bootstrap resampling.")
    return parser.parse_args()


def load_results(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def extract_exec_samples_with_iteration(run: dict[str, object], metric: str) -> list[dict[str, float | int]]:
    values: list[dict[str, float | int]] = []
    for fallback_index, sample in enumerate(run.get("samples", [])):
        metric_value = sample.get(metric)
        if metric_value is None:
            continue
        raw_iteration_index = sample.get("iteration_index", fallback_index)
        try:
            iteration_index = int(raw_iteration_index)
        except (TypeError, ValueError):
            iteration_index = fallback_index
        values.append(
            {
                "iteration_index": iteration_index,
                "value": float(metric_value),
            }
        )
    if not values:
        raise ValueError(f"run {run.get('runtime', '<unknown>')} has no {metric} samples")
    values.sort(key=lambda sample: int(sample["iteration_index"]))
    return values


def extract_exec_samples(run: dict[str, object], metric: str) -> np.ndarray:
    values = [float(sample["value"]) for sample in extract_exec_samples_with_iteration(run, metric)]
    return np.asarray(values, dtype=np.float64)


def index_exec_samples_by_iteration(
    exec_samples: list[dict[str, float | int]],
) -> tuple[dict[int, float], list[int]]:
    indexed_samples: dict[int, float] = {}
    duplicate_iteration_indexes: list[int] = []
    for sample in exec_samples:
        iteration_index = int(sample["iteration_index"])
        if iteration_index in indexed_samples:
            duplicate_iteration_indexes.append(iteration_index)
        indexed_samples[iteration_index] = float(sample["value"])
    return indexed_samples, duplicate_iteration_indexes


def extract_compile_samples(run: dict[str, object]) -> np.ndarray | None:
    values = [float(sample["compile_ns"]) for sample in run.get("samples", []) if sample.get("compile_ns") is not None]
    if not values:
        return None
    return np.asarray(values, dtype=np.float64)


def extract_native_code_bytes(run: dict[str, object]) -> float | None:
    values: list[float] = []
    for sample in run.get("samples", []):
        code_size = sample.get("code_size", {})
        native_code_bytes = code_size.get("native_code_bytes")
        if native_code_bytes is None:
            native_code_bytes = sample.get("native_code_size")
        if native_code_bytes is None:
            native_code_bytes = sample.get("jited_prog_len")
        if native_code_bytes is not None:
            values.append(float(native_code_bytes))
    if not values:
        return None
    return float(np.median(np.asarray(values, dtype=np.float64)))


def percentile_interval(values: np.ndarray) -> tuple[float, float]:
    clean_values = values[np.isfinite(values)]
    if clean_values.size == 0:
        return math.nan, math.nan
    low, high = np.percentile(clean_values, [2.5, 97.5])
    return float(low), float(high)


def bootstrap_mean_ci(values: np.ndarray, iterations: int, rng: np.random.Generator) -> tuple[float, float]:
    sample_count = values.size
    indices = rng.integers(0, sample_count, size=(iterations, sample_count))
    means = values[indices].mean(axis=1)
    return percentile_interval(means)


def bootstrap_ratio_distribution(
    lhs: np.ndarray,
    rhs: np.ndarray,
    iterations: int,
    rng: np.random.Generator,
) -> np.ndarray:
    lhs_indices = rng.integers(0, lhs.size, size=(iterations, lhs.size))
    rhs_indices = rng.integers(0, rhs.size, size=(iterations, rhs.size))
    lhs_means = lhs[lhs_indices].mean(axis=1)
    rhs_means = rhs[rhs_indices].mean(axis=1)
    ratios = np.full(iterations, np.nan, dtype=np.float64)
    np.divide(lhs_means, rhs_means, out=ratios, where=rhs_means != 0)
    return ratios


def sample_stdev(values: np.ndarray) -> float:
    if values.size <= 1:
        return 0.0
    return float(np.std(values, ddof=1))


def cohen_d(lhs: np.ndarray, rhs: np.ndarray) -> float:
    lhs_mean = float(np.mean(lhs))
    rhs_mean = float(np.mean(rhs))
    lhs_var = float(np.var(lhs, ddof=1)) if lhs.size > 1 else 0.0
    rhs_var = float(np.var(rhs, ddof=1)) if rhs.size > 1 else 0.0
    pooled_denom = lhs.size + rhs.size - 2
    if pooled_denom <= 0:
        return math.nan
    pooled_var = (((lhs.size - 1) * lhs_var) + ((rhs.size - 1) * rhs_var)) / pooled_denom
    if pooled_var <= 0:
        delta = lhs_mean - rhs_mean
        if delta == 0:
            return 0.0
        return math.copysign(math.inf, delta)
    return (lhs_mean - rhs_mean) / math.sqrt(pooled_var)


def geometric_mean(values: list[float]) -> float:
    if not values:
        return math.nan
    if any(value <= 0 for value in values):
        return math.nan
    return float(math.exp(sum(math.log(value) for value in values) / len(values)))


def benjamini_hochberg_adjusted_pvalues(pvalues: list[float]) -> list[float]:
    adjusted_pvalues = [math.nan] * len(pvalues)
    ranked_pvalues = [
        (index, pvalue)
        for index, pvalue in enumerate(pvalues)
        if math.isfinite(pvalue)
    ]
    if not ranked_pvalues:
        return adjusted_pvalues

    ranked_pvalues.sort(key=lambda item: item[1])
    total = len(ranked_pvalues)
    previous_adjusted = 1.0

    for rank, (index, pvalue) in reversed(list(enumerate(ranked_pvalues, start=1))):
        adjusted = min(previous_adjusted, (pvalue * total) / rank, 1.0)
        adjusted_pvalues[index] = adjusted
        previous_adjusted = adjusted

    return adjusted_pvalues


def format_float(value: float | None, precision: int = 2) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:,.{precision}f}"


def format_ci(low: float | None, high: float | None, precision: int = 2) -> str:
    if low is None or high is None or not math.isfinite(low) or not math.isfinite(high):
        return "n/a"
    return f"[{format_float(low, precision)}, {format_float(high, precision)}]"


def format_ratio(value: float | None) -> str:
    return format_float(value, precision=3)


def format_pvalue(value: float | None) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    if value < 1e-4:
        return f"{value:.2e}"
    return f"{value:.4f}"


def format_int(value: int | float | None) -> str:
    if value is None or not math.isfinite(float(value)):
        return "n/a"
    return f"{int(round(float(value))):,}"


def build_runtime_rows(
    results: dict[str, object],
    iterations: int,
    rng: np.random.Generator,
    metric: str,
) -> tuple[list[dict[str, object]], list[dict[str, object]]]:
    runtime_rows: list[dict[str, object]] = []
    comparison_rows: list[dict[str, object]] = []

    for benchmark in results.get("benchmarks", []):
        benchmark_name = benchmark["name"]
        runs_by_runtime: dict[str, dict[str, object]] = {
            run["runtime"]: run for run in benchmark.get("runs", [])
        }

        for runtime in RUNTIME_ORDER:
            run = runs_by_runtime.get(runtime)
            if run is None:
                continue
            exec_samples = extract_exec_samples(run, metric)
            mean_value = float(np.mean(exec_samples))
            mean_ci_low, mean_ci_high = bootstrap_mean_ci(exec_samples, iterations, rng)
            stdev_value = sample_stdev(exec_samples)
            runtime_rows.append(
                {
                    "benchmark": benchmark_name,
                    "runtime": runtime,
                    "n": int(exec_samples.size),
                    "mean": mean_value,
                    "mean_ci_low": mean_ci_low,
                    "mean_ci_high": mean_ci_high,
                    "median": float(np.median(exec_samples)),
                    "stdev": stdev_value,
                    "cv": stdev_value / mean_value if mean_value != 0 else math.nan,
                    "min": float(np.min(exec_samples)),
                    "max": float(np.max(exec_samples)),
                }
            )

        lhs_run = runs_by_runtime.get("llvmbpf")
        rhs_run = runs_by_runtime.get("kernel")
        if lhs_run is None or rhs_run is None:
            continue

        lhs_exec_samples = extract_exec_samples_with_iteration(lhs_run, metric)
        rhs_exec_samples = extract_exec_samples_with_iteration(rhs_run, metric)
        lhs_exec = extract_exec_samples(lhs_run, metric)
        rhs_exec = extract_exec_samples(rhs_run, metric)
        ratio_distribution = bootstrap_ratio_distribution(lhs_exec, rhs_exec, iterations, rng)
        ratio_low, ratio_high = percentile_interval(ratio_distribution)
        lhs_mean = float(np.mean(lhs_exec))
        rhs_mean = float(np.mean(rhs_exec))
        if metric == "exec_ns":
            kernel_exec_mean_ns = rhs_mean
        else:
            try:
                kernel_exec_mean_ns = float(np.mean(extract_exec_samples(rhs_run, "exec_ns")))
            except ValueError:
                kernel_exec_mean_ns = math.nan
        kernel_exec_below_resolution = (
            math.isfinite(kernel_exec_mean_ns) and kernel_exec_mean_ns < KERNEL_EXEC_SUBRESOLUTION_NS
        )
        code_size_lhs = extract_native_code_bytes(lhs_run)
        code_size_rhs = extract_native_code_bytes(rhs_run)
        code_size_ratio = None
        if code_size_lhs is not None and code_size_rhs not in (None, 0):
            code_size_ratio = code_size_lhs / code_size_rhs

        mann_whitney = mannwhitneyu(lhs_exec, rhs_exec, alternative="two-sided")
        lhs_exec_by_iteration, lhs_duplicate_iterations = index_exec_samples_by_iteration(lhs_exec_samples)
        rhs_exec_by_iteration, rhs_duplicate_iterations = index_exec_samples_by_iteration(rhs_exec_samples)
        lhs_iteration_indexes = set(lhs_exec_by_iteration)
        rhs_iteration_indexes = set(rhs_exec_by_iteration)
        paired_iteration_indexes = sorted(lhs_iteration_indexes & rhs_iteration_indexes)
        paired_exec_samples = [
            {
                "iteration_index": iteration_index,
                "llvmbpf": lhs_exec_by_iteration[iteration_index],
                "kernel": rhs_exec_by_iteration[iteration_index],
            }
            for iteration_index in paired_iteration_indexes
        ]
        pairing_notes: list[str] = []
        if len(lhs_exec) != len(rhs_exec):
            pairing_notes.append(f"sample count mismatch: llvmbpf={len(lhs_exec)}, kernel={len(rhs_exec)}")
        if lhs_duplicate_iterations:
            pairing_notes.append("duplicate llvmbpf iteration_index values")
        if rhs_duplicate_iterations:
            pairing_notes.append("duplicate kernel iteration_index values")
        if lhs_iteration_indexes != rhs_iteration_indexes:
            pairing_notes.append(
                "iteration_index mismatch "
                f"(missing in llvmbpf={len(rhs_iteration_indexes - lhs_iteration_indexes)}, "
                f"missing in kernel={len(lhs_iteration_indexes - rhs_iteration_indexes)})"
            )
        if pairing_notes or not paired_exec_samples:
            paired_pvalue = math.nan
        else:
            paired_lhs_exec = np.asarray([sample["llvmbpf"] for sample in paired_exec_samples], dtype=np.float64)
            paired_rhs_exec = np.asarray([sample["kernel"] for sample in paired_exec_samples], dtype=np.float64)
            try:
                wilcoxon_result = wilcoxon(paired_lhs_exec, paired_rhs_exec, alternative="two-sided")
            except ValueError as exc:
                if np.allclose(paired_lhs_exec, paired_rhs_exec):
                    paired_pvalue = 1.0
                else:
                    pairing_notes.append(f"paired Wilcoxon unavailable: {exc}")
                    paired_pvalue = math.nan
            else:
                paired_pvalue = float(wilcoxon_result.pvalue)
        notes = pairing_notes.copy()
        if kernel_exec_below_resolution:
            notes.append(KERNEL_EXEC_SUBRESOLUTION_NOTE)
        comparison_rows.append(
            {
                "benchmark": benchmark_name,
                "lhs_exec": lhs_exec,
                "rhs_exec": rhs_exec,
                "lhs_exec_samples": lhs_exec_samples,
                "rhs_exec_samples": rhs_exec_samples,
                "paired_exec_samples": paired_exec_samples,
                "exec_ratio": lhs_mean / rhs_mean if rhs_mean != 0 else math.nan,
                "exec_ratio_ci_low": ratio_low,
                "exec_ratio_ci_high": ratio_high,
                "cohen_d": cohen_d(lhs_exec, rhs_exec),
                "mann_whitney_pvalue": float(mann_whitney.pvalue),
                "wilcoxon_paired_pvalue": paired_pvalue,
                "kernel_exec_mean_ns": kernel_exec_mean_ns,
                "kernel_exec_below_resolution": kernel_exec_below_resolution,
                "pairing_note": "; ".join(pairing_notes) if pairing_notes else None,
                "notes": "; ".join(notes) if notes else None,
                "significant": False,
                "code_size_ratio": code_size_ratio,
                "code_size_llvmbpf": code_size_lhs,
                "code_size_kernel": code_size_rhs,
            }
        )

    return runtime_rows, comparison_rows


def apply_benjamini_hochberg_correction(comparison_rows: list[dict[str, object]], alpha: float = 0.05) -> None:
    for row in comparison_rows:
        row["adjusted_pvalue"] = math.nan
        row["paired_wilcoxon_pvalue_bh"] = math.nan
        row["significant"] = False
        row["significant_bh"] = False

    adjusted_pvalues = benjamini_hochberg_adjusted_pvalues(
        [float(row["wilcoxon_paired_pvalue"]) for row in comparison_rows]
    )
    for row, adjusted_pvalue in zip(comparison_rows, adjusted_pvalues):
        row["adjusted_pvalue"] = adjusted_pvalue
        row["paired_wilcoxon_pvalue_bh"] = adjusted_pvalue
        row["significant"] = bool(adjusted_pvalue < alpha)
        row["significant_bh"] = row["significant"]


def build_suite_summary(
    comparison_rows: list[dict[str, object]],
    iterations: int,
    rng: np.random.Generator,
    metric: str,
) -> dict[str, object]:
    ratios = [float(row["exec_ratio"]) for row in comparison_rows if math.isfinite(float(row["exec_ratio"]))]
    suite_bootstrap: list[np.ndarray] = []
    for row in comparison_rows:
        lhs_exec = row["lhs_exec"]
        rhs_exec = row["rhs_exec"]
        suite_bootstrap.append(bootstrap_ratio_distribution(lhs_exec, rhs_exec, iterations, rng))

    geomean_ci_low = math.nan
    geomean_ci_high = math.nan
    if suite_bootstrap:
        ratio_matrix = np.vstack(suite_bootstrap)
        valid_columns = np.all(np.isfinite(ratio_matrix) & (ratio_matrix > 0), axis=0)
        if np.any(valid_columns):
            suite_distribution = np.exp(np.mean(np.log(ratio_matrix[:, valid_columns]), axis=0))
            geomean_ci_low, geomean_ci_high = percentile_interval(suite_distribution)

    subresolution_rows = [row for row in comparison_rows if row.get("kernel_exec_below_resolution")]
    non_subresolution_rows = [row for row in comparison_rows if not row.get("kernel_exec_below_resolution")]
    non_subresolution_adjusted_pvalues = benjamini_hochberg_adjusted_pvalues(
        [float(row["wilcoxon_paired_pvalue"]) for row in non_subresolution_rows]
    )

    return {
        "metric": metric,
        "benchmark_count": len(comparison_rows),
        "geometric_mean_ratio": geometric_mean(ratios),
        "geometric_mean_ci_low": geomean_ci_low,
        "geometric_mean_ci_high": geomean_ci_high,
        "paired_test_available_count": sum(
            1 for row in comparison_rows if math.isfinite(float(row.get("paired_wilcoxon_pvalue_bh", math.nan)))
        ),
        "subresolution_benchmark_count": len(subresolution_rows),
        "non_subresolution_benchmark_count": len(non_subresolution_rows),
        "significant_count": sum(1 for row in comparison_rows if row["significant"]),
        "significant_bh_count": sum(1 for row in comparison_rows if row.get("significant_bh")),
        "non_subresolution_significant_count": sum(
            1 for adjusted_pvalue in non_subresolution_adjusted_pvalues if math.isfinite(adjusted_pvalue) and adjusted_pvalue < 0.05
        ),
    }


def describe_metric_timing(results: dict[str, object], metric: str) -> str:
    runtime_sources: dict[str, set[str]] = {}
    for benchmark in results.get("benchmarks", []):
        for run in benchmark.get("runs", []):
            runtime = str(run.get("runtime", "<unknown>"))
            source = str(run.get("timing_source", "unknown"))
            runtime_sources.setdefault(runtime, set()).add(source)

    if metric == "exec_ns":
        if not runtime_sources:
            return "`exec_ns` from each sample's `exec_ns` field; timing source unavailable."
        source_list = ", ".join(
            f"{runtime}={','.join(sorted(sources))}"
            for runtime, sources in sorted(runtime_sources.items())
        )
        return f"`exec_ns` from each sample's `exec_ns` field; `timing_source` by runtime: {source_list}."

    if not runtime_sources:
        return (
            "`wall_exec_ns` from each sample's `wall_exec_ns` field; this is the runtime-reported wall-time "
            "estimate per repeat when available."
        )
    source_list = ", ".join(
        f"{runtime} exec_ns timing={','.join(sorted(sources))}"
        for runtime, sources in sorted(runtime_sources.items())
    )
    return (
        "`wall_exec_ns` from each sample's `wall_exec_ns` field; this is the runtime-reported wall-time "
        f"estimate per repeat when available. Paired `exec_ns` timing sources: {source_list}."
    )


def build_compile_time_rows(
    results: dict[str, object],
    iterations: int,
    rng: np.random.Generator,
) -> tuple[list[dict[str, object]], dict[str, object]]:
    """Build per-benchmark compile time stats and suite-level geomean."""
    rows: list[dict[str, object]] = []

    for benchmark in results.get("benchmarks", []):
        benchmark_name = benchmark["name"]
        runs_by_runtime: dict[str, dict[str, object]] = {
            run["runtime"]: run for run in benchmark.get("runs", [])
        }

        lhs_run = runs_by_runtime.get("llvmbpf")
        rhs_run = runs_by_runtime.get("kernel")
        if lhs_run is None or rhs_run is None:
            continue

        lhs_compile = extract_compile_samples(lhs_run)
        rhs_compile = extract_compile_samples(rhs_run)
        if lhs_compile is None or rhs_compile is None:
            continue

        lhs_mean = float(np.mean(lhs_compile))
        rhs_mean = float(np.mean(rhs_compile))
        lhs_ci_low, lhs_ci_high = bootstrap_mean_ci(lhs_compile, iterations, rng)
        rhs_ci_low, rhs_ci_high = bootstrap_mean_ci(rhs_compile, iterations, rng)
        ratio = lhs_mean / rhs_mean if rhs_mean != 0 else math.nan

        rows.append(
            {
                "benchmark": benchmark_name,
                "llvmbpf_mean": lhs_mean,
                "llvmbpf_ci_low": lhs_ci_low,
                "llvmbpf_ci_high": lhs_ci_high,
                "kernel_mean": rhs_mean,
                "kernel_ci_low": rhs_ci_low,
                "kernel_ci_high": rhs_ci_high,
                "ratio": ratio,
            }
        )

    ratios = [float(row["ratio"]) for row in rows if math.isfinite(float(row["ratio"]))]
    summary = {
        "benchmark_count": len(rows),
        "geometric_mean_ratio": geometric_mean(ratios),
    }
    return rows, summary


def render_markdown(
    input_path: Path,
    results: dict[str, object],
    runtime_rows: list[dict[str, object]],
    comparison_rows: list[dict[str, object]],
    suite_summary: dict[str, object],
    compile_time_rows: list[dict[str, object]],
    compile_time_summary: dict[str, object],
    iterations: int,
    seed: int,
    metric: str,
) -> str:
    metric_timing_note = describe_metric_timing(results, metric)
    lines = [
        "# Pure JIT Rigorous Statistical Analysis",
        "",
        f"- Input JSON: `{input_path}`",
        f"- Suite manifest: `{results.get('manifest', 'unknown')}`",
        f"- Generated at: `{results.get('generated_at', 'unknown')}`",
        f"- Bootstrap iterations: `{iterations}`",
        f"- Bootstrap seed: `{seed}`",
        f"- Selected execution metric: `{metric}`.",
        f"- Metric timing source: {metric_timing_note}",
        f"- Exec ratio is defined as `mean({metric}_llvmbpf) / mean({metric}_kernel)`.",
        "- Ratio interpretation: values below `1.0` favor `llvmbpf`; values above `1.0` favor `kernel`.",
        "- Primary significance test: paired Wilcoxon signed-rank on matched `iteration_index` values with Benjamini-Hochberg correction.",
        "- Secondary significance test: raw Mann-Whitney U p-values are reported as supplementary context.",
        "",
        "## Benchmark x Runtime Statistics",
        "",
        f"| Benchmark | Runtime | N | Mean {metric} | 95% CI (mean) | Median {metric} | Stdev {metric} | CV | Min {metric} | Max {metric} |",
        "| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | ---: | ---: |",
    ]

    for row in runtime_rows:
        lines.append(
            "| "
            f"{row['benchmark']} | "
            f"{row['runtime']} | "
            f"{row['n']} | "
            f"{format_float(row['mean'])} | "
            f"{format_ci(row['mean_ci_low'], row['mean_ci_high'])} | "
            f"{format_float(row['median'])} | "
            f"{format_float(row['stdev'])} | "
            f"{format_ratio(row['cv'])} | "
            f"{format_float(row['min'])} | "
            f"{format_float(row['max'])} |"
        )

    lines.extend(
        [
            "",
            "## Cross-runtime Comparison",
            "",
            f"| Benchmark | {metric} Ratio (L/K) | 95% CI | Cohen's d | Paired Wilcoxon p | MWU p | Significant | Code-size Ratio (L/K) | Notes |",
            "| --- | ---: | --- | ---: | ---: | ---: | --- | ---: | --- |",
        ]
    )

    for row in comparison_rows:
        code_size_ratio = format_ratio(row["code_size_ratio"])
        if row["code_size_llvmbpf"] is not None and row["code_size_kernel"] is not None:
            code_size_ratio = (
                f"{code_size_ratio} "
                f"({format_int(row['code_size_llvmbpf'])}/{format_int(row['code_size_kernel'])})"
            )
        lines.append(
            "| "
            f"{row['benchmark']} | "
            f"{format_ratio(row['exec_ratio'])} | "
            f"{format_ci(row['exec_ratio_ci_low'], row['exec_ratio_ci_high'], precision=3)} | "
            f"{format_ratio(row['cohen_d'])} | "
            f"{format_pvalue(row['adjusted_pvalue'])} | "
            f"{format_pvalue(row['mann_whitney_pvalue'])} | "
            f"{'Yes' if row['significant'] else 'No'} | "
            f"{code_size_ratio} | "
            f"{row.get('notes') or ''} |"
        )

    lines.extend(
        [
            "",
            "## Suite Summary",
            "",
            "| Metric | Value |",
            "| --- | --- |",
            f"| Benchmarks compared | {suite_summary['benchmark_count']} |",
            f"| Geometric mean {suite_summary['metric']} ratio (L/K) | {format_ratio(suite_summary['geometric_mean_ratio'])} |",
            (
                f"| Geometric mean {suite_summary['metric']} ratio 95% CI | "
                f"{format_ci(suite_summary['geometric_mean_ci_low'], suite_summary['geometric_mean_ci_high'], precision=3)} |"
            ),
            (
                "| Benchmarks with valid paired Wilcoxon input | "
                f"{suite_summary['paired_test_available_count']} / {suite_summary['benchmark_count']} |"
            ),
            (
                "| Statistically significant benchmarks (BH-adjusted paired Wilcoxon p < 0.05) | "
                f"{suite_summary['significant_count']} / {suite_summary['benchmark_count']} |"
            ),
            (
                f"| Benchmarks with kernel exec < {format_int(KERNEL_EXEC_SUBRESOLUTION_NS)}ns "
                "(below ktime resolution) | "
                f"{suite_summary['subresolution_benchmark_count']} / {suite_summary['benchmark_count']} |"
            ),
            (
                "| Statistically significant benchmarks excluding sub-resolution kernels "
                "(BH-adjusted paired Wilcoxon p < 0.05) | "
                f"{suite_summary['non_subresolution_significant_count']} / "
                f"{suite_summary['non_subresolution_benchmark_count']} |"
            ),
            "",
        ]
    )

    if compile_time_rows:
        lines.extend(
            [
                "## Compile Time Analysis",
                "",
                "| Benchmark | llvmbpf compile_ns (mean) | llvmbpf 95% CI | kernel compile_ns (mean) | kernel 95% CI | Ratio (L/K) |",
                "| --- | ---: | --- | ---: | --- | ---: |",
            ]
        )

        for row in compile_time_rows:
            lines.append(
                "| "
                f"{row['benchmark']} | "
                f"{format_float(row['llvmbpf_mean'])} | "
                f"{format_ci(row['llvmbpf_ci_low'], row['llvmbpf_ci_high'])} | "
                f"{format_float(row['kernel_mean'])} | "
                f"{format_ci(row['kernel_ci_low'], row['kernel_ci_high'])} | "
                f"{format_ratio(row['ratio'])} |"
            )

        lines.extend(
            [
                "",
                f"**Suite geometric mean compile-time ratio (L/K):** {format_ratio(compile_time_summary['geometric_mean_ratio'])}",
                f"  (over {compile_time_summary['benchmark_count']} benchmarks)",
                "",
            ]
        )

    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    results = load_results(input_path)
    rng = np.random.default_rng(args.seed)
    runtime_rows, comparison_rows = build_runtime_rows(results, args.bootstrap_iterations, rng, args.metric)
    apply_benjamini_hochberg_correction(comparison_rows)
    suite_summary = build_suite_summary(comparison_rows, args.bootstrap_iterations, rng, args.metric)
    compile_time_rows, compile_time_summary = build_compile_time_rows(results, args.bootstrap_iterations, rng)
    report = render_markdown(
        input_path,
        results,
        runtime_rows,
        comparison_rows,
        suite_summary,
        compile_time_rows,
        compile_time_summary,
        args.bootstrap_iterations,
        args.seed,
        args.metric,
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report)
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
