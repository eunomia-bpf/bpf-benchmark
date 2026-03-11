#!/usr/bin/env python3
"""Generate publication-quality figures for the eBPF JIT benchmark paper."""

from __future__ import annotations

import argparse
import json
import math
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import numpy as np
from matplotlib.colors import to_rgb
from matplotlib.lines import Line2D
from matplotlib.patches import Patch
from scipy.stats import linregress, wilcoxon


plt.rcParams.update(
    {
        "font.size": 9,
        "font.family": "serif",
        "figure.dpi": 300,
        "savefig.dpi": 300,
        "savefig.bbox": "tight",
        "pdf.fonttype": 42,
        "ps.fonttype": 42,
        "axes.grid": True,
        "axes.axisbelow": True,
        "grid.alpha": 0.3,
        "grid.linestyle": ":",
        "axes.spines.top": False,
        "axes.spines.right": False,
    }
)

MICRO_DIR = Path(__file__).resolve().parent
RESULTS_DIR = MICRO_DIR / "results"
FIGURES_DIR = RESULTS_DIR / "figures"
PURE_JIT_RESULTS = RESULTS_DIR / "pure_jit_authoritative.json"
CAUSAL_RESULTS_CANDIDATES = (
    RESULTS_DIR / "causal_isolation_authoritative.json",
    RESULTS_DIR / "pure_jit_with_cmov.json",
    RESULTS_DIR / "pure_jit.latest.json",
)


def first_existing_path(candidates: Iterable[Path]) -> Path:
    candidate_list = tuple(candidates)
    for candidate in candidate_list:
        if candidate.exists():
            return candidate
    return candidate_list[0]


CAUSAL_RESULTS = first_existing_path(CAUSAL_RESULTS_CANDIDATES)
CATEGORY_MAP = {
    "baseline": {"label": "baseline", "color": "#4E79A7"},
    "alu-mix": {"label": "alu\nmix", "color": "#F28E2B"},
    "control-flow": {"label": "control\nflow", "color": "#E15759"},
    "dependency-ilp": {"label": "dependency\nILP", "color": "#76B7B2"},
    "loop-shape": {"label": "loop\nshape", "color": "#59A14F"},
    "memory-local": {"label": "memory\nlocal", "color": "#EDC948"},
    "program-scale": {"label": "program\nscale", "color": "#B07AA1"},
    "call-overhead": {"label": "call\noverhead", "color": "#BAB0AC"},
    "call-size": {"label": "call\nsize", "color": "#9C755F"},
}
CATEGORY_ORDER = tuple(CATEGORY_MAP)
CATEGORY_LABELS = {name: meta["label"] for name, meta in CATEGORY_MAP.items()}
CATEGORY_COLORS = {name: meta["color"] for name, meta in CATEGORY_MAP.items()}
RUNTIME_COLORS = {
    "llvmbpf": "#2E8B57",
    "kernel": "#C44E52",
}
GEOMEAN_COLOR = "#4C72B0"
PARITY_COLOR = "#7A7A7A"
HIGHLIGHT_COLOR = "#F2C14E"
HIGHLIGHT_EDGE = "#7A5C00"
BOOTSTRAP_ITERATIONS = 10_000
BOOTSTRAP_SEED = 0
OUTLIER_Z_THRESHOLD = 1.5


@dataclass(frozen=True)
class BenchmarkRecord:
    name: str
    category: str
    exec_ratio: float
    code_size_ratio: float
    compile_ratio: float
    exec_significant: bool
    adjusted_pvalue: float


@dataclass(frozen=True)
class CategorySummary:
    category: str
    exec_geomean: float
    code_geomean: float


@dataclass(frozen=True)
class CausalRuntimeSummary:
    benchmark: str
    runtime: str
    median_exec_ns: float
    ci_low: float
    ci_high: float


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--pure-json", default=str(PURE_JIT_RESULTS), help="Path to the 31-benchmark authoritative JSON.")
    parser.add_argument(
        "--causal-json",
        default=str(CAUSAL_RESULTS),
        help="Path to a causal-capable JSON result file. Defaults to the first existing causal results candidate.",
    )
    parser.add_argument("--figures-dir", default=str(FIGURES_DIR), help="Output directory for generated PDF figures.")
    parser.add_argument(
        "--bootstrap-iterations",
        type=int,
        default=BOOTSTRAP_ITERATIONS,
        help="Bootstrap iterations for causal-isolation median confidence intervals.",
    )
    parser.add_argument(
        "--seed",
        type=int,
        default=BOOTSTRAP_SEED,
        help="Random seed for deterministic bootstrap confidence intervals.",
    )
    return parser.parse_args()


def load_results(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def get_run(benchmark: dict[str, object], runtime: str) -> dict[str, object]:
    for run in benchmark.get("runs", []):
        if str(run.get("runtime")) == runtime:
            return run
    raise KeyError(f"benchmark {benchmark.get('name', '<unknown>')} missing runtime {runtime}")


def extract_metric_samples_with_iteration(run: dict[str, object], metric: str) -> list[tuple[int, float]]:
    values: list[tuple[int, float]] = []
    for fallback_index, sample in enumerate(run.get("samples", [])):
        metric_value = sample.get(metric)
        if metric_value is None:
            continue
        raw_index = sample.get("iteration_index", fallback_index)
        try:
            iteration_index = int(raw_index)
        except (TypeError, ValueError):
            iteration_index = fallback_index
        values.append((iteration_index, float(metric_value)))
    if not values:
        raise ValueError(f"run {run.get('runtime', '<unknown>')} has no {metric} samples")
    values.sort(key=lambda item: item[0])
    return values


def extract_metric_samples(run: dict[str, object], metric: str) -> np.ndarray:
    return np.asarray(
        [value for _, value in extract_metric_samples_with_iteration(run, metric)],
        dtype=np.float64,
    )


def extract_metric_center(run: dict[str, object], metric: str, center: str = "median") -> float:
    summary = run.get(metric)
    if isinstance(summary, dict):
        value = summary.get(center)
        if value is not None:
            return float(value)

    values = extract_metric_samples(run, metric)
    if center == "median":
        return float(np.median(values))
    if center == "mean":
        return float(np.mean(values))
    raise ValueError(f"unsupported center: {center}")


def extract_native_code_bytes(run: dict[str, object]) -> float:
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
        raise ValueError(f"run {run.get('runtime', '<unknown>')} is missing native code size data")
    return float(np.median(np.asarray(values, dtype=np.float64)))


def paired_wilcoxon_pvalue(lhs_run: dict[str, object], rhs_run: dict[str, object], metric: str) -> float:
    lhs_samples = extract_metric_samples_with_iteration(lhs_run, metric)
    rhs_samples = extract_metric_samples_with_iteration(rhs_run, metric)

    lhs_by_iteration: dict[int, float] = {}
    rhs_by_iteration: dict[int, float] = {}
    lhs_duplicates = False
    rhs_duplicates = False

    for iteration_index, value in lhs_samples:
        if iteration_index in lhs_by_iteration:
            lhs_duplicates = True
        lhs_by_iteration[iteration_index] = value
    for iteration_index, value in rhs_samples:
        if iteration_index in rhs_by_iteration:
            rhs_duplicates = True
        rhs_by_iteration[iteration_index] = value

    if lhs_duplicates or rhs_duplicates:
        return math.nan

    paired_indexes = sorted(set(lhs_by_iteration) & set(rhs_by_iteration))
    if not paired_indexes or set(lhs_by_iteration) != set(rhs_by_iteration):
        return math.nan

    lhs_values = np.asarray([lhs_by_iteration[index] for index in paired_indexes], dtype=np.float64)
    rhs_values = np.asarray([rhs_by_iteration[index] for index in paired_indexes], dtype=np.float64)

    try:
        return float(wilcoxon(lhs_values, rhs_values, alternative="two-sided").pvalue)
    except ValueError:
        if np.allclose(lhs_values, rhs_values):
            return 1.0
        return math.nan


def benjamini_hochberg_adjusted_pvalues(pvalues: list[float]) -> list[float]:
    adjusted = [math.nan] * len(pvalues)
    ranked = [(index, pvalue) for index, pvalue in enumerate(pvalues) if math.isfinite(pvalue)]
    if not ranked:
        return adjusted

    ranked.sort(key=lambda item: item[1])
    total = len(ranked)
    previous = 1.0
    for rank, (index, pvalue) in reversed(list(enumerate(ranked, start=1))):
        corrected = min(previous, (pvalue * total) / rank, 1.0)
        adjusted[index] = corrected
        previous = corrected
    return adjusted


def percentile_interval(values: np.ndarray) -> tuple[float, float]:
    clean_values = values[np.isfinite(values)]
    if clean_values.size == 0:
        return math.nan, math.nan
    low, high = np.percentile(clean_values, [2.5, 97.5])
    return float(low), float(high)


def bootstrap_median_ci(values: np.ndarray, iterations: int, seed: int) -> tuple[float, float]:
    rng = np.random.default_rng(seed)
    indices = rng.integers(0, values.size, size=(iterations, values.size))
    medians = np.median(values[indices], axis=1)
    return percentile_interval(medians)


def geometric_mean(values: list[float]) -> float:
    if not values or any(value <= 0.0 or not math.isfinite(value) for value in values):
        return math.nan
    return float(math.exp(sum(math.log(value) for value in values) / len(values)))


def sample_stdev(values: np.ndarray) -> float:
    if values.size <= 1:
        return 0.0
    return float(np.std(values, ddof=1))


def lighten_color(color: str, amount: float = 0.45) -> tuple[float, float, float]:
    red, green, blue = to_rgb(color)
    return (
        red + (1.0 - red) * amount,
        green + (1.0 - green) * amount,
        blue + (1.0 - blue) * amount,
    )


def format_ratio(value: float) -> str:
    return f"{value:.2f}x" if value < 10.0 else f"{value:.1f}x"


def format_ns(value: float) -> str:
    return f"{value:.1f}" if value < 100.0 else f"{value:.0f}"


def require_known_category(category: str) -> str:
    if category not in CATEGORY_MAP:
        known = ", ".join(CATEGORY_ORDER)
        raise KeyError(f"unknown benchmark category {category!r}; known categories: {known}")
    return category


def is_causal_isolation_benchmark(benchmark: dict[str, object]) -> bool:
    if str(benchmark.get("family", "")) == "causal-isolation":
        return True
    if str(benchmark.get("category", "")) == "causal-isolation":
        return True
    tags = benchmark.get("tags", [])
    if isinstance(tags, list):
        return any(str(tag) == "causal-isolation" for tag in tags)
    return False


def build_benchmark_records(results: dict[str, object]) -> list[BenchmarkRecord]:
    records: list[dict[str, object]] = []
    exec_pvalues: list[float] = []

    for benchmark in results.get("benchmarks", []):
        llvmbpf_run = get_run(benchmark, "llvmbpf")
        kernel_run = get_run(benchmark, "kernel")

        llvmbpf_exec = extract_metric_samples(llvmbpf_run, "exec_ns")
        kernel_exec = extract_metric_samples(kernel_run, "exec_ns")
        llvmbpf_exec_median = extract_metric_center(llvmbpf_run, "exec_ns", center="median")
        kernel_exec_median = extract_metric_center(kernel_run, "exec_ns", center="median")
        llvmbpf_compile_median = extract_metric_center(llvmbpf_run, "compile_ns", center="median")
        kernel_compile_median = extract_metric_center(kernel_run, "compile_ns", center="median")
        category = require_known_category(str(benchmark["category"]))

        records.append(
            {
                "name": str(benchmark["name"]),
                "category": category,
                "exec_ratio": float(llvmbpf_exec_median / kernel_exec_median),
                "code_size_ratio": extract_native_code_bytes(llvmbpf_run) / extract_native_code_bytes(kernel_run),
                "compile_ratio": float(llvmbpf_compile_median / kernel_compile_median),
            }
        )
        exec_pvalues.append(paired_wilcoxon_pvalue(llvmbpf_run, kernel_run, "exec_ns"))

    adjusted_pvalues = benjamini_hochberg_adjusted_pvalues(exec_pvalues)
    return [
        BenchmarkRecord(
            name=str(record["name"]),
            category=str(record["category"]),
            exec_ratio=float(record["exec_ratio"]),
            code_size_ratio=float(record["code_size_ratio"]),
            compile_ratio=float(record["compile_ratio"]),
            exec_significant=bool(math.isfinite(adjusted_pvalue) and adjusted_pvalue < 0.05),
            adjusted_pvalue=adjusted_pvalue,
        )
        for record, adjusted_pvalue in zip(records, adjusted_pvalues)
    ]


def summarize_categories(records: list[BenchmarkRecord]) -> list[CategorySummary]:
    summaries: list[CategorySummary] = []
    for category in CATEGORY_ORDER:
        category_records = [record for record in records if record.category == category]
        if not category_records:
            continue
        summaries.append(
            CategorySummary(
                category=category,
                exec_geomean=geometric_mean([record.exec_ratio for record in category_records]),
                code_geomean=geometric_mean([record.code_size_ratio for record in category_records]),
            )
        )
    return summaries


def build_causal_summaries(results: dict[str, object], iterations: int, seed: int) -> list[CausalRuntimeSummary]:
    summaries: list[CausalRuntimeSummary] = []
    causal_benchmarks = [benchmark for benchmark in results.get("benchmarks", []) if is_causal_isolation_benchmark(benchmark)]
    if not causal_benchmarks:
        raise ValueError("causal results file does not contain any causal-isolation benchmarks")
    for benchmark_index, benchmark in enumerate(causal_benchmarks):
        for runtime_index, runtime in enumerate(("llvmbpf", "kernel")):
            run = get_run(benchmark, runtime)
            exec_samples = extract_metric_samples(run, "exec_ns")
            ci_low, ci_high = bootstrap_median_ci(
                exec_samples,
                iterations=iterations,
                seed=seed + benchmark_index * 101 + runtime_index,
            )
            summaries.append(
                CausalRuntimeSummary(
                    benchmark=str(benchmark["name"]),
                    runtime=runtime,
                    median_exec_ns=extract_metric_center(run, "exec_ns", center="median"),
                    ci_low=ci_low,
                    ci_high=ci_high,
                )
            )
    return summaries


def add_bar_labels(ax: plt.Axes, bars, values: list[float], scale: float, formatter) -> None:
    for bar, value in zip(bars, values):
        height = bar.get_height()
        ax.text(
            bar.get_x() + (bar.get_width() / 2.0),
            height + scale,
            formatter(value),
            ha="center",
            va="bottom",
            fontsize=7.5,
        )


def plot_ratio_bars(
    records: list[BenchmarkRecord],
    metric: str,
    output_path: Path,
    xlabel: str,
    win_label: str,
    loss_label: str,
    show_significance: bool = False,
    highlight_wins: bool = False,
) -> None:
    metric_values = [getattr(record, metric) for record in records]
    geomean = geometric_mean(metric_values)
    ordered = sorted(records, key=lambda record: getattr(record, metric))
    values = [getattr(record, metric) for record in ordered]
    labels = [record.name for record in ordered]
    y = np.arange(len(ordered))
    max_value = max(max(values), 1.0, geomean)
    x_margin = 0.16 if highlight_wins else 0.12
    x_limit = max_value * (1.0 + x_margin)

    fig_height = max(6.0, 0.28 * len(ordered) + 0.8)
    fig, ax = plt.subplots(figsize=(8.6, fig_height), constrained_layout=True)

    label_offset = max_value * 0.015
    has_wins = False
    has_losses = False
    for index, record in enumerate(ordered):
        value = getattr(record, metric)
        is_win = value < 1.0
        has_wins = has_wins or is_win
        has_losses = has_losses or not is_win
        facecolor = RUNTIME_COLORS["llvmbpf"] if is_win else RUNTIME_COLORS["kernel"]
        hatch = None
        if show_significance and not record.exec_significant:
            facecolor = lighten_color(facecolor, amount=0.45)
            hatch = "////"

        ax.barh(
            index,
            value,
            height=0.72,
            color=facecolor,
            edgecolor="#333333",
            linewidth=0.7,
            hatch=hatch,
        )

        if highlight_wins and is_win:
            star_x = min(value + label_offset * 1.8, x_limit * 0.985)
            ax.scatter(
                [star_x],
                [index],
                marker="*",
                s=65,
                color=HIGHLIGHT_COLOR,
                edgecolors=HIGHLIGHT_EDGE,
                linewidths=0.6,
                zorder=4,
            )

        text_x = value + label_offset
        text_color = "#222222"
        text_ha = "left"
        if value > x_limit * 0.88:
            text_x = value - label_offset
            text_color = "white"
            text_ha = "right"
        ax.text(text_x, index, format_ratio(value), va="center", ha=text_ha, fontsize=7.3, color=text_color)

    ax.axvline(1.0, color=PARITY_COLOR, linestyle="--", linewidth=1.0)
    ax.axvline(geomean, color=GEOMEAN_COLOR, linestyle="-.", linewidth=1.2)
    ax.text(
        geomean,
        0.99,
        f"gmean {format_ratio(geomean)}",
        transform=ax.get_xaxis_transform(),
        rotation=90,
        ha="right",
        va="top",
        color=GEOMEAN_COLOR,
        fontsize=8,
    )

    ax.set_xlim(0.0, x_limit)
    ax.set_yticks(y, labels)
    ax.invert_yaxis()
    ax.set_xlabel(xlabel)
    ax.set_ylabel("Benchmark")
    ax.grid(True, axis="x")
    ax.grid(False, axis="y")
    ax.xaxis.set_major_locator(mticker.MaxNLocator(7))
    ax.xaxis.set_major_formatter(mticker.FormatStrFormatter("%.1f" if max_value >= 10.0 else "%.2f"))

    legend_handles: list[object] = []
    if has_wins:
        legend_handles.append(Patch(facecolor=RUNTIME_COLORS["llvmbpf"], edgecolor="#333333", label=win_label))
    if has_losses:
        legend_handles.append(Patch(facecolor=RUNTIME_COLORS["kernel"], edgecolor="#333333", label=loss_label))
    if show_significance:
        legend_handles.append(
            Patch(
                facecolor="#DDDDDD",
                edgecolor="#666666",
                hatch="////",
                label="Non-significant exec result",
            )
        )
    if highlight_wins:
        legend_handles.append(
            Line2D(
                [0],
                [0],
                marker="*",
                color="none",
                markerfacecolor=HIGHLIGHT_COLOR,
                markeredgecolor=HIGHLIGHT_EDGE,
                markersize=8,
                label="llvmbpf compile-time win",
            )
        )
    legend_handles.extend(
        [
            Line2D([0], [0], color=PARITY_COLOR, linestyle="--", linewidth=1.0, label="Parity (1.0x)"),
            Line2D([0], [0], color=GEOMEAN_COLOR, linestyle="-.", linewidth=1.2, label=f"Geomean ({format_ratio(geomean)})"),
        ]
    )
    ax.legend(handles=legend_handles, frameon=False, loc="lower right", fontsize=8)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(output_path)
    plt.close(fig)


def plot_category_breakdown(records: list[BenchmarkRecord], output_path: Path) -> None:
    summaries = summarize_categories(records)
    categories = [summary.category for summary in summaries]
    exec_geomeans = [summary.exec_geomean for summary in summaries]
    code_geomeans = [summary.code_geomean for summary in summaries]

    x = np.arange(len(categories))
    width = 0.36
    fig, ax = plt.subplots(figsize=(8.4, 4.2), constrained_layout=True)

    exec_bars = ax.bar(
        x - width / 2.0,
        exec_geomeans,
        width,
        color="#4C72B0",
        edgecolor="#333333",
        linewidth=0.7,
        label="Execution geomean",
    )
    code_bars = ax.bar(
        x + width / 2.0,
        code_geomeans,
        width,
        color="#DD8452",
        edgecolor="#333333",
        linewidth=0.7,
        label="Code-size geomean",
    )

    max_value = max(max(exec_geomeans), max(code_geomeans), 1.0)
    ax.axhline(1.0, color=PARITY_COLOR, linestyle="--", linewidth=1.0)
    ax.set_ylim(0.0, max_value * 1.22)
    ax.set_ylabel("Geomean ratio (llvmbpf / kernel)")
    ax.set_xticks(x, [CATEGORY_LABELS[category] for category in categories])
    ax.grid(True, axis="y")
    ax.grid(False, axis="x")
    ax.legend(frameon=False, ncol=2, loc="upper left")
    add_bar_labels(ax, exec_bars, exec_geomeans, max_value * 0.02, format_ratio)
    add_bar_labels(ax, code_bars, code_geomeans, max_value * 0.02, format_ratio)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(output_path)
    plt.close(fig)


def plot_size_vs_exec_scatter(records: list[BenchmarkRecord], output_path: Path) -> None:
    x = np.asarray([record.code_size_ratio for record in records], dtype=np.float64)
    y = np.asarray([record.exec_ratio for record in records], dtype=np.float64)
    fit = linregress(x, y)
    predicted = fit.intercept + fit.slope * x
    residuals = y - predicted
    residual_stdev = sample_stdev(residuals)

    fig, ax = plt.subplots(figsize=(7.4, 5.4), constrained_layout=True)
    for category in CATEGORY_ORDER:
        category_records = [record for record in records if record.category == category]
        if not category_records:
            continue
        ax.scatter(
            [record.code_size_ratio for record in category_records],
            [record.exec_ratio for record in category_records],
            s=46,
            color=CATEGORY_COLORS[category],
            edgecolor="white",
            linewidth=0.5,
            alpha=0.95,
            label=category,
        )

    x_min = max(0.0, min(float(x.min()) - 0.05, 0.15))
    x_max = max(float(x.max()) + 0.07, 1.15)
    y_min = max(0.0, min(float(y.min()) - 0.08, 0.15))
    y_max = max(float(y.max()) + 0.10, 1.15)
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)

    regression_x = np.linspace(x_min, x_max, 200)
    regression_y = fit.intercept + fit.slope * regression_x
    ax.plot(regression_x, regression_y, color="#222222", linewidth=1.2)
    ax.axvline(1.0, color=PARITY_COLOR, linestyle="--", linewidth=1.0)
    ax.axhline(1.0, color=PARITY_COLOR, linestyle="--", linewidth=1.0)

    fit_text = f"fit: y = {fit.intercept:.2f} + {fit.slope:.2f}x\n$R^2$ = {fit.rvalue ** 2:.02f}"
    ax.text(
        0.02,
        0.98,
        fit_text,
        transform=ax.transAxes,
        ha="left",
        va="top",
        fontsize=8,
        bbox={"boxstyle": "round,pad=0.25", "facecolor": "white", "edgecolor": "#BBBBBB", "alpha": 0.85},
    )

    outlier_offsets = [(-18, 10), (6, 12), (8, -14), (-22, -10), (10, 16), (-20, 14)]
    for index, record in enumerate(records):
        residual_z = 0.0 if residual_stdev == 0.0 else float(residuals[index] / residual_stdev)
        if abs(residual_z) < OUTLIER_Z_THRESHOLD:
            continue
        offset = outlier_offsets[index % len(outlier_offsets)]
        ax.annotate(
            record.name,
            (record.code_size_ratio, record.exec_ratio),
            xytext=offset,
            textcoords="offset points",
            fontsize=7.5,
            arrowprops={"arrowstyle": "-", "linewidth": 0.6, "color": "#555555"},
        )

    quadrant_positions = {
        "smaller + slower": ((x_min + 1.0) / 2.0, (1.0 + y_max) / 2.0),
        "smaller + faster": ((x_min + 1.0) / 2.0, (y_min + 1.0) / 2.0),
        "larger + slower": ((1.0 + x_max) / 2.0, (1.0 + y_max) / 2.0),
        "larger + faster": ((1.0 + x_max) / 2.0, (y_min + 1.0) / 2.0),
    }
    for label, position in quadrant_positions.items():
        ax.text(
            position[0],
            position[1],
            label,
            ha="center",
            va="center",
            fontsize=8,
            color="#666666",
            bbox={"boxstyle": "round,pad=0.2", "facecolor": "white", "edgecolor": "none", "alpha": 0.65},
        )

    ax.set_xlabel("Code-size ratio (llvmbpf / kernel)")
    ax.set_ylabel("Execution-time ratio (llvmbpf / kernel)")
    ax.grid(True, axis="both")
    ax.legend(frameon=False, ncol=4, loc="upper center", bbox_to_anchor=(0.5, -0.16), fontsize=8)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(output_path)
    plt.close(fig)


def plot_causal_isolation(summaries: list[CausalRuntimeSummary], output_path: Path) -> None:
    benchmarks = list(dict.fromkeys(summary.benchmark for summary in summaries))
    runtime_order = ("llvmbpf", "kernel")
    summary_lookup = {(summary.benchmark, summary.runtime): summary for summary in summaries}

    x = np.arange(len(benchmarks))
    width = 0.36
    fig, ax = plt.subplots(figsize=(7.4, 4.0), constrained_layout=True)

    for runtime_index, runtime in enumerate(runtime_order):
        means: list[float] = []
        lower_errors: list[float] = []
        upper_errors: list[float] = []
        for benchmark in benchmarks:
            summary = summary_lookup[(benchmark, runtime)]
            means.append(summary.median_exec_ns)
            lower_errors.append(max(0.0, summary.median_exec_ns - summary.ci_low))
            upper_errors.append(max(0.0, summary.ci_high - summary.median_exec_ns))

        offset = (-width / 2.0) if runtime == "llvmbpf" else (width / 2.0)
        bars = ax.bar(
            x + offset,
            means,
            width,
            yerr=[lower_errors, upper_errors],
            capsize=3,
            color=RUNTIME_COLORS[runtime],
            edgecolor="#333333",
            linewidth=0.7,
            error_kw={"linewidth": 0.8, "ecolor": "#333333"},
            label=runtime,
        )
        add_bar_labels(ax, bars, means, max(means) * 0.025, format_ns)

    ax.set_ylabel("Median execution time (ns)")
    ax.set_xticks(x, [benchmark.replace("_", "\n") for benchmark in benchmarks])
    ax.grid(True, axis="y")
    ax.grid(False, axis="x")
    ax.legend(frameon=False, ncol=2, loc="upper left")

    output_path.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(output_path)
    plt.close(fig)


def main() -> int:
    args = parse_args()
    pure_results = load_results(Path(args.pure_json))
    causal_results = load_results(Path(args.causal_json))
    figures_dir = Path(args.figures_dir)
    figures_dir.mkdir(parents=True, exist_ok=True)

    benchmark_records = build_benchmark_records(pure_results)
    causal_summaries = build_causal_summaries(causal_results, args.bootstrap_iterations, args.seed)

    outputs = [
        figures_dir / "exec_ratio_bars.pdf",
        figures_dir / "code_size_ratio_bars.pdf",
        figures_dir / "category_breakdown.pdf",
        figures_dir / "compile_ratio_bars.pdf",
        figures_dir / "size_vs_exec_scatter.pdf",
        figures_dir / "causal_isolation.pdf",
    ]

    plot_ratio_bars(
        benchmark_records,
        metric="exec_ratio",
        output_path=outputs[0],
        xlabel="Execution-time ratio (llvmbpf / kernel)",
        win_label="llvmbpf faster",
        loss_label="kernel faster",
        show_significance=True,
    )
    plot_ratio_bars(
        benchmark_records,
        metric="code_size_ratio",
        output_path=outputs[1],
        xlabel="Code-size ratio (llvmbpf / kernel)",
        win_label="llvmbpf smaller",
        loss_label="kernel smaller",
    )
    plot_category_breakdown(benchmark_records, outputs[2])
    plot_ratio_bars(
        benchmark_records,
        metric="compile_ratio",
        output_path=outputs[3],
        xlabel="Compile-time ratio (llvmbpf / kernel)",
        win_label="llvmbpf compiles faster",
        loss_label="kernel compiles faster",
        highlight_wins=True,
    )
    plot_size_vs_exec_scatter(benchmark_records, outputs[4])
    plot_causal_isolation(causal_summaries, outputs[5])

    print("Generated figures:")
    for output in outputs:
        print(f" - {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
