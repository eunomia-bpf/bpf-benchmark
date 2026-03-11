#!/usr/bin/env python3
"""Analyze time-series stability of benchmark results.

For each benchmark x runtime pair, this script:
  1. Plots exec_ns vs iteration index (saved as PNG).
  2. Computes lag-1 autocorrelation ACF(1).
  3. Splits samples into first/second half and runs a Wilcoxon signed-rank
     test to detect drift.
  4. Computes a rolling mean (window=5) to visualize trends.

Outputs a markdown report summarizing stability across the suite.
"""
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

import matplotlib
matplotlib.use("Agg")  # non-interactive backend
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import wilcoxon


ROOT_DIR = Path(__file__).resolve().parent.parent.parent
DEFAULT_INPUT = ROOT_DIR / "results" / "pure_jit_rigorous.json"
DEFAULT_OUTPUT = ROOT_DIR / "results" / "stability_analysis.md"
PLOT_DIR = ROOT_DIR / "results" / "stability"
ROLLING_WINDOW = 5
ACF_THRESHOLD = 0.3
DRIFT_ALPHA = 0.05


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Analyze time-series stability of benchmark results."
    )
    parser.add_argument(
        "input",
        nargs="?",
        default=str(DEFAULT_INPUT),
        help="Input benchmark JSON (default: %(default)s).",
    )
    parser.add_argument(
        "--output",
        default=str(DEFAULT_OUTPUT),
        help="Markdown report output path (default: %(default)s).",
    )
    parser.add_argument(
        "--plot-dir",
        default=str(PLOT_DIR),
        help="Directory for per-benchmark PNG plots (default: %(default)s).",
    )
    parser.add_argument(
        "--window",
        type=int,
        default=ROLLING_WINDOW,
        help="Rolling mean window size (default: %(default)s).",
    )
    return parser.parse_args()


def load_results(path: Path) -> dict:
    return json.loads(path.read_text())


def extract_exec_samples(run: dict) -> np.ndarray:
    """Extract exec_ns values preserving iteration order."""
    values = [
        float(s["exec_ns"])
        for s in run.get("samples", [])
        if s.get("exec_ns") is not None
    ]
    if not values:
        raise ValueError(
            f"run {run.get('runtime', '<unknown>')} has no exec_ns samples"
        )
    return np.asarray(values, dtype=np.float64)


def lag1_autocorrelation(x: np.ndarray) -> float:
    """Compute lag-1 autocorrelation coefficient."""
    n = x.size
    if n < 3:
        return math.nan
    mean = np.mean(x)
    var = np.var(x, ddof=0)
    if var == 0:
        return 0.0
    cov = np.sum((x[:-1] - mean) * (x[1:] - mean)) / n
    return float(cov / var)


def half_split_wilcoxon(x: np.ndarray) -> tuple[float, float, float, float]:
    """Split samples into halves and run Wilcoxon signed-rank test.

    Returns (p_value, first_half_mean, second_half_mean, drift_pct).
    If the halves are unequal length, truncate the longer one.
    """
    n = x.size
    half = n // 2
    if half < 5:
        return math.nan, float(np.mean(x[:half])), float(np.mean(x[half:])), math.nan

    first = x[:half]
    second = x[half : half + half]  # same length as first

    first_mean = float(np.mean(first))
    second_mean = float(np.mean(second))
    drift_pct = (
        (second_mean - first_mean) / first_mean * 100.0
        if first_mean != 0
        else math.nan
    )

    # Wilcoxon signed-rank test requires paired samples of equal length
    # and that not all differences are zero.
    diff = second - first
    if np.all(diff == 0):
        return 1.0, first_mean, second_mean, drift_pct

    try:
        stat, p_value = wilcoxon(first, second, alternative="two-sided")
        return float(p_value), first_mean, second_mean, drift_pct
    except ValueError:
        # Can happen if sample size is too small or all differences are zero
        return math.nan, first_mean, second_mean, drift_pct


def rolling_mean(x: np.ndarray, window: int) -> np.ndarray:
    """Compute rolling/moving average with given window size."""
    if x.size < window:
        return np.full(x.size, np.nan)
    cumsum = np.cumsum(x)
    cumsum = np.insert(cumsum, 0, 0)
    rolling = (cumsum[window:] - cumsum[:-window]) / window
    # Pad front with NaN so output aligns with input indices
    pad = np.full(window - 1, np.nan)
    return np.concatenate([pad, rolling])


def plot_time_series(
    benchmark_name: str,
    runtime: str,
    exec_ns: np.ndarray,
    roll_mean: np.ndarray,
    window: int,
    plot_dir: Path,
) -> Path:
    """Plot exec_ns vs iteration index with rolling mean overlay."""
    fig, ax = plt.subplots(figsize=(10, 4))
    indices = np.arange(exec_ns.size)

    ax.scatter(indices, exec_ns, s=12, alpha=0.5, label="exec_ns", color="steelblue")
    valid_mask = ~np.isnan(roll_mean)
    ax.plot(
        indices[valid_mask],
        roll_mean[valid_mask],
        color="red",
        linewidth=1.5,
        label=f"rolling mean (w={window})",
    )

    ax.set_xlabel("Iteration index")
    ax.set_ylabel("exec_ns")
    ax.set_title(f"{benchmark_name} [{runtime}]")
    ax.legend(loc="upper right", fontsize=8)
    ax.grid(True, alpha=0.3)

    fig.tight_layout()
    filename = f"{benchmark_name}_{runtime}.png"
    out_path = plot_dir / filename
    fig.savefig(str(out_path), dpi=120)
    plt.close(fig)
    return out_path


def format_float(value: float | None, precision: int = 4) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:.{precision}f}"


def format_pvalue(value: float | None) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    if value < 1e-4:
        return f"{value:.2e}"
    return f"{value:.4f}"


def analyze_and_report(
    results: dict,
    input_path: Path,
    output_path: Path,
    plot_dir: Path,
    window: int,
) -> str:
    """Run stability analysis on all benchmark x runtime pairs."""
    plot_dir.mkdir(parents=True, exist_ok=True)

    rows: list[dict] = []

    for benchmark in results.get("benchmarks", []):
        bench_name = benchmark["name"]
        for run in benchmark.get("runs", []):
            runtime = run["runtime"]
            try:
                exec_ns = extract_exec_samples(run)
            except ValueError:
                continue

            acf1 = lag1_autocorrelation(exec_ns)
            p_value, first_mean, second_mean, drift_pct = half_split_wilcoxon(exec_ns)
            roll = rolling_mean(exec_ns, window)

            plot_path = plot_time_series(bench_name, runtime, exec_ns, roll, window, plot_dir)

            rows.append(
                {
                    "benchmark": bench_name,
                    "runtime": runtime,
                    "n": int(exec_ns.size),
                    "acf1": acf1,
                    "p_value": p_value,
                    "first_half_mean": first_mean,
                    "second_half_mean": second_mean,
                    "drift_pct": drift_pct,
                    "plot": plot_path.name,
                }
            )

    # Build markdown report
    lines = [
        "# Benchmark Stability Analysis",
        "",
        f"- Input: `{input_path}`",
        f"- Generated from suite: `{results.get('suite', 'unknown')}`",
        f"- Rolling window: {window}",
        f"- ACF(1) threshold: |ACF(1)| > {ACF_THRESHOLD}",
        f"- Drift significance level: p < {DRIFT_ALPHA}",
        "",
        "## Time-Series Stability Table",
        "",
        "| Benchmark | Runtime | N | ACF(1) | Drift p-value | 1st-half mean | 2nd-half mean | Drift% |",
        "| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]

    for row in rows:
        lines.append(
            f"| {row['benchmark']} "
            f"| {row['runtime']} "
            f"| {row['n']} "
            f"| {format_float(row['acf1'])} "
            f"| {format_pvalue(row['p_value'])} "
            f"| {format_float(row['first_half_mean'], 2)} "
            f"| {format_float(row['second_half_mean'], 2)} "
            f"| {format_float(row['drift_pct'], 2)} |"
        )

    # Summary statistics
    significant_drift = sum(
        1 for r in rows if math.isfinite(r["p_value"]) and r["p_value"] < DRIFT_ALPHA
    )
    strong_acf = sum(
        1 for r in rows if math.isfinite(r["acf1"]) and abs(r["acf1"]) > ACF_THRESHOLD
    )
    total = len(rows)

    lines.extend(
        [
            "",
            "## Summary",
            "",
            f"- Total benchmark x runtime pairs analyzed: **{total}**",
            f"- Pairs with significant drift (Wilcoxon p < {DRIFT_ALPHA}): "
            f"**{significant_drift} / {total}**",
            f"- Pairs with strong autocorrelation (|ACF(1)| > {ACF_THRESHOLD}): "
            f"**{strong_acf} / {total}**",
            "",
        ]
    )

    if significant_drift > 0:
        lines.append("### Benchmarks with significant drift")
        lines.append("")
        for row in rows:
            if math.isfinite(row["p_value"]) and row["p_value"] < DRIFT_ALPHA:
                lines.append(
                    f"- **{row['benchmark']}** [{row['runtime']}]: "
                    f"p={format_pvalue(row['p_value'])}, "
                    f"drift={format_float(row['drift_pct'], 2)}%"
                )
        lines.append("")

    if strong_acf > 0:
        lines.append("### Benchmarks with strong autocorrelation")
        lines.append("")
        for row in rows:
            if math.isfinite(row["acf1"]) and abs(row["acf1"]) > ACF_THRESHOLD:
                lines.append(
                    f"- **{row['benchmark']}** [{row['runtime']}]: "
                    f"ACF(1)={format_float(row['acf1'])}"
                )
        lines.append("")

    lines.append(
        f"Plots saved to `{plot_dir}/`."
    )
    lines.append("")

    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    plot_dir = Path(args.plot_dir).resolve()

    results = load_results(input_path)
    report = analyze_and_report(results, input_path, output_path, plot_dir, args.window)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report)
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
