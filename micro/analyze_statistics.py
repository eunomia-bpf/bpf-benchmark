#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

import numpy as np
from scipy.stats import mannwhitneyu


ROOT_DIR = Path(__file__).resolve().parent
DEFAULT_INPUT = ROOT_DIR / "results" / "pure_jit_rigorous.json"
DEFAULT_OUTPUT = ROOT_DIR / "results" / "pure_jit_rigorous_analysis.md"
BOOTSTRAP_ITERATIONS = 10_000
DEFAULT_SEED = 0
RUNTIME_ORDER = ("llvmbpf", "kernel")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Analyze statistical properties of pure-JIT microbenchmark results.")
    parser.add_argument("input", nargs="?", default=str(DEFAULT_INPUT), help="Input benchmark JSON.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Markdown report output path.")
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


def extract_exec_samples(run: dict[str, object]) -> np.ndarray:
    values = [float(sample["exec_ns"]) for sample in run.get("samples", []) if sample.get("exec_ns") is not None]
    if not values:
        raise ValueError(f"run {run.get('runtime', '<unknown>')} has no exec_ns samples")
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


def build_runtime_table_rows(
    results: dict[str, object],
    iterations: int,
    rng: np.random.Generator,
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
            exec_samples = extract_exec_samples(run)
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

        lhs_exec = extract_exec_samples(lhs_run)
        rhs_exec = extract_exec_samples(rhs_run)
        ratio_distribution = bootstrap_ratio_distribution(lhs_exec, rhs_exec, iterations, rng)
        ratio_low, ratio_high = percentile_interval(ratio_distribution)
        lhs_mean = float(np.mean(lhs_exec))
        rhs_mean = float(np.mean(rhs_exec))
        code_size_lhs = extract_native_code_bytes(lhs_run)
        code_size_rhs = extract_native_code_bytes(rhs_run)
        code_size_ratio = None
        if code_size_lhs is not None and code_size_rhs not in (None, 0):
            code_size_ratio = code_size_lhs / code_size_rhs

        mann_whitney = mannwhitneyu(lhs_exec, rhs_exec, alternative="two-sided")
        comparison_rows.append(
            {
                "benchmark": benchmark_name,
                "lhs_exec": lhs_exec,
                "rhs_exec": rhs_exec,
                "exec_ratio": lhs_mean / rhs_mean if rhs_mean != 0 else math.nan,
                "exec_ratio_ci_low": ratio_low,
                "exec_ratio_ci_high": ratio_high,
                "cohen_d": cohen_d(lhs_exec, rhs_exec),
                "mann_whitney_pvalue": float(mann_whitney.pvalue),
                "significant": bool(mann_whitney.pvalue < 0.05),
                "code_size_ratio": code_size_ratio,
                "code_size_llvmbpf": code_size_lhs,
                "code_size_kernel": code_size_rhs,
            }
        )

    return runtime_rows, comparison_rows


def build_suite_summary(
    comparison_rows: list[dict[str, object]],
    iterations: int,
    rng: np.random.Generator,
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

    return {
        "benchmark_count": len(comparison_rows),
        "geometric_mean_ratio": geometric_mean(ratios),
        "geometric_mean_ci_low": geomean_ci_low,
        "geometric_mean_ci_high": geomean_ci_high,
        "significant_count": sum(1 for row in comparison_rows if row["significant"]),
    }


def render_markdown(
    input_path: Path,
    results: dict[str, object],
    runtime_rows: list[dict[str, object]],
    comparison_rows: list[dict[str, object]],
    suite_summary: dict[str, object],
    iterations: int,
    seed: int,
) -> str:
    lines = [
        "# Pure JIT Rigorous Statistical Analysis",
        "",
        f"- Input JSON: `{input_path}`",
        f"- Suite manifest: `{results.get('manifest', 'unknown')}`",
        f"- Generated at: `{results.get('generated_at', 'unknown')}`",
        f"- Bootstrap iterations: `{iterations}`",
        f"- Bootstrap seed: `{seed}`",
        "- Exec ratio is defined as `mean(exec_ns_llvmbpf) / mean(exec_ns_kernel)`.",
        "- Ratio interpretation: values below `1.0` favor `llvmbpf`; values above `1.0` favor `kernel`.",
        "",
        "## Benchmark x Runtime Statistics",
        "",
        "| Benchmark | Runtime | N | Mean exec_ns | 95% CI (mean) | Median exec_ns | Stdev exec_ns | CV | Min exec_ns | Max exec_ns |",
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
            "| Benchmark | Exec Ratio (L/K) | 95% CI | Cohen's d | Mann-Whitney U p-value | Significant (p < 0.05) | Code-size Ratio (L/K) |",
            "| --- | ---: | --- | ---: | ---: | --- | ---: |",
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
            f"{format_pvalue(row['mann_whitney_pvalue'])} | "
            f"{'Yes' if row['significant'] else 'No'} | "
            f"{code_size_ratio} |"
        )

    lines.extend(
        [
            "",
            "## Suite Summary",
            "",
            "| Metric | Value |",
            "| --- | --- |",
            f"| Benchmarks compared | {suite_summary['benchmark_count']} |",
            f"| Geometric mean exec ratio (L/K) | {format_ratio(suite_summary['geometric_mean_ratio'])} |",
            (
                "| Geometric mean exec ratio 95% CI | "
                f"{format_ci(suite_summary['geometric_mean_ci_low'], suite_summary['geometric_mean_ci_high'], precision=3)} |"
            ),
            (
                "| Statistically significant benchmarks (p < 0.05) | "
                f"{suite_summary['significant_count']} / {suite_summary['benchmark_count']} |"
            ),
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
    runtime_rows, comparison_rows = build_runtime_table_rows(results, args.bootstrap_iterations, rng)
    suite_summary = build_suite_summary(comparison_rows, args.bootstrap_iterations, rng)
    report = render_markdown(
        input_path,
        results,
        runtime_rows,
        comparison_rows,
        suite_summary,
        args.bootstrap_iterations,
        args.seed,
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report)
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
