#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import statistics
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

import numpy as np
from elftools.elf.elffile import ELFFile
from scipy.stats import linregress, pearsonr, spearmanr


ROOT_DIR = Path(__file__).resolve().parent.parent.parent
REPO_ROOT = ROOT_DIR.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from corpus.analyze_bytecode import SHF_EXECINSTR, is_skipped_section, parse_section_bytecode


DEFAULT_INPUT = ROOT_DIR / "results" / "pure_jit_authoritative.json"
DEFAULT_OUTPUT = ROOT_DIR / "results" / "performance_deep_analysis.md"
DEFAULT_PROGRAM_DIR = ROOT_DIR / "programs"
CATEGORY_ORDER = (
    "baseline",
    "alu-mix",
    "control-flow",
    "dependency-ilp",
    "loop-shape",
    "memory-local",
    "program-scale",
    "call-size",
)
HIGH_VARIANCE_THRESHOLD = 0.10
OUTLIER_Z_THRESHOLD = 1.5


@dataclass(frozen=True)
class BenchmarkRecord:
    name: str
    category: str
    llvmbpf_exec_mean: float
    kernel_exec_mean: float
    exec_ratio: float
    llvmbpf_compile_mean: float
    kernel_compile_mean: float
    compile_ratio: float
    llvmbpf_code_bytes: float
    kernel_code_bytes: float
    code_ratio: float
    bpf_insn_count: int | None
    branch_count: int | None
    llvmbpf_cv: float
    kernel_cv: float
    effect_size: float
    effect_class: str


@dataclass(frozen=True)
class CategorySummary:
    category: str
    benchmark_count: int
    exec_geomean: float
    code_geomean: float
    llvmbpf_wins: int
    kernel_wins: int


@dataclass(frozen=True)
class RegressionOutlier:
    name: str
    code_ratio: float
    exec_ratio: float
    predicted_exec_ratio: float
    residual: float
    residual_z: float


@dataclass(frozen=True)
class CorrelationSummary:
    pearson_r: float
    pearson_p: float
    spearman_rho: float
    spearman_p: float
    slope: float
    intercept: float
    r_squared: float


@dataclass(frozen=True)
class FeatureImportance:
    feature: str
    raw_coefficient: float
    standardized_beta: float
    drop_in_r2: float
    univariate_r2: float


@dataclass(frozen=True)
class PredictionModel:
    benchmark_count: int
    r_squared: float
    intercept: float
    features: tuple[FeatureImportance, ...]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate a deep performance analysis report for authoritative pure-JIT data.")
    parser.add_argument("--input", default=str(DEFAULT_INPUT), help="Authoritative JSON input path.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Markdown report output path.")
    parser.add_argument("--program-dir", default=str(DEFAULT_PROGRAM_DIR), help="Directory containing compiled benchmark objects.")
    return parser.parse_args()


def load_results(path: Path) -> dict[str, object]:
    return json.load(open(path))


def get_run(benchmark: dict[str, object], runtime: str) -> dict[str, object]:
    for run in benchmark.get("runs", []):
        if str(run.get("runtime")) == runtime:
            return run
    raise KeyError(f"benchmark {benchmark.get('name', '<unknown>')} missing runtime {runtime}")


def extract_samples(run: dict[str, object], key: str) -> np.ndarray:
    values = [float(sample[key]) for sample in run.get("samples", []) if sample.get(key) is not None]
    if not values:
        raise ValueError(f"run {run.get('runtime', '<unknown>')} has no {key} samples")
    return np.asarray(values, dtype=np.float64)


def sample_stdev(values: np.ndarray) -> float:
    if values.size <= 1:
        return 0.0
    return float(np.std(values, ddof=1))


def coefficient_of_variation(values: np.ndarray) -> float:
    mean_value = float(np.mean(values))
    if mean_value == 0.0:
        return math.nan
    return sample_stdev(values) / mean_value


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
        if delta == 0.0:
            return 0.0
        return math.copysign(math.inf, delta)
    return (lhs_mean - rhs_mean) / math.sqrt(pooled_var)


def classify_effect_size(value: float) -> str:
    magnitude = abs(value)
    if magnitude < 0.5:
        return "small"
    if magnitude <= 0.8:
        return "medium"
    return "large"


def geometric_mean(values: list[float]) -> float:
    if not values:
        return math.nan
    if any(value <= 0.0 or not math.isfinite(value) for value in values):
        return math.nan
    return float(math.exp(sum(math.log(value) for value in values) / len(values)))


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
    return float(statistics.median(values))


def extract_bpf_insn_count(run: dict[str, object]) -> int | None:
    counts: list[int] = []
    for sample in run.get("samples", []):
        value = sample.get("bpf_insn_count")
        if value is None:
            code_size = sample.get("code_size", {})
            byte_count = code_size.get("bpf_bytecode_bytes")
            if byte_count is not None:
                counts.append(int(byte_count) // 8)
            continue
        counts.append(int(value))
    if not counts:
        return None
    return int(statistics.median(counts))


def extract_branch_count(object_path: Path) -> int | None:
    if not object_path.exists():
        return None

    total_branches = 0
    with object_path.open("rb") as handle:
        elf = ELFFile(handle)
        for section in elf.iter_sections():
            section_name = section.name or ""
            if is_skipped_section(section_name):
                continue
            if not (section.header["sh_flags"] & SHF_EXECINSTR):
                continue
            section_metrics, _ = parse_section_bytecode(section.data())
            total_branches += int(section_metrics["branch_count"])
    return total_branches


def build_benchmark_records(results: dict[str, object], program_dir: Path) -> list[BenchmarkRecord]:
    records: list[BenchmarkRecord] = []
    for benchmark in results.get("benchmarks", []):
        name = str(benchmark["name"])
        category = str(benchmark["category"])
        llvmbpf_run = get_run(benchmark, "llvmbpf")
        kernel_run = get_run(benchmark, "kernel")

        llvmbpf_exec = extract_samples(llvmbpf_run, "exec_ns")
        kernel_exec = extract_samples(kernel_run, "exec_ns")
        llvmbpf_compile = extract_samples(llvmbpf_run, "compile_ns")
        kernel_compile = extract_samples(kernel_run, "compile_ns")

        llvmbpf_code_bytes = extract_native_code_bytes(llvmbpf_run)
        kernel_code_bytes = extract_native_code_bytes(kernel_run)
        if llvmbpf_code_bytes is None or kernel_code_bytes in (None, 0.0):
            raise ValueError(f"benchmark {name} is missing native code-size data")

        llvmbpf_exec_mean = float(np.mean(llvmbpf_exec))
        kernel_exec_mean = float(np.mean(kernel_exec))
        llvmbpf_compile_mean = float(np.mean(llvmbpf_compile))
        kernel_compile_mean = float(np.mean(kernel_compile))
        effect_size = cohen_d(llvmbpf_exec, kernel_exec)

        records.append(
            BenchmarkRecord(
                name=name,
                category=category,
                llvmbpf_exec_mean=llvmbpf_exec_mean,
                kernel_exec_mean=kernel_exec_mean,
                exec_ratio=llvmbpf_exec_mean / kernel_exec_mean,
                llvmbpf_compile_mean=llvmbpf_compile_mean,
                kernel_compile_mean=kernel_compile_mean,
                compile_ratio=llvmbpf_compile_mean / kernel_compile_mean,
                llvmbpf_code_bytes=llvmbpf_code_bytes,
                kernel_code_bytes=kernel_code_bytes,
                code_ratio=llvmbpf_code_bytes / kernel_code_bytes,
                bpf_insn_count=extract_bpf_insn_count(llvmbpf_run),
                branch_count=extract_branch_count(program_dir / f"{name}.bpf.o"),
                llvmbpf_cv=coefficient_of_variation(llvmbpf_exec),
                kernel_cv=coefficient_of_variation(kernel_exec),
                effect_size=effect_size,
                effect_class=classify_effect_size(effect_size),
            )
        )
    return records


def summarize_categories(records: list[BenchmarkRecord]) -> list[CategorySummary]:
    grouped: dict[str, list[BenchmarkRecord]] = defaultdict(list)
    for record in records:
        grouped[record.category].append(record)

    summaries: list[CategorySummary] = []
    for category in CATEGORY_ORDER:
        category_records = grouped.get(category, [])
        if not category_records:
            continue
        summaries.append(
            CategorySummary(
                category=category,
                benchmark_count=len(category_records),
                exec_geomean=geometric_mean([record.exec_ratio for record in category_records]),
                code_geomean=geometric_mean([record.code_ratio for record in category_records]),
                llvmbpf_wins=sum(1 for record in category_records if record.exec_ratio < 1.0),
                kernel_wins=sum(1 for record in category_records if record.exec_ratio > 1.0),
            )
        )
    return summaries


def correlation_summary(x: list[float], y: list[float]) -> CorrelationSummary:
    pearson = pearsonr(x, y)
    spearman = spearmanr(x, y)
    fit = linregress(x, y)
    return CorrelationSummary(
        pearson_r=float(pearson.statistic),
        pearson_p=float(pearson.pvalue),
        spearman_rho=float(spearman.statistic),
        spearman_p=float(spearman.pvalue),
        slope=float(fit.slope),
        intercept=float(fit.intercept),
        r_squared=float(fit.rvalue**2),
    )


def identify_outliers(records: list[BenchmarkRecord], threshold: float = OUTLIER_Z_THRESHOLD) -> list[RegressionOutlier]:
    fit = linregress([record.code_ratio for record in records], [record.exec_ratio for record in records])
    residuals = np.asarray(
        [
            record.exec_ratio - (fit.intercept + fit.slope * record.code_ratio)
            for record in records
        ],
        dtype=np.float64,
    )
    residual_std = sample_stdev(residuals)
    outliers: list[RegressionOutlier] = []
    for record, residual in zip(records, residuals):
        predicted = float(fit.intercept + fit.slope * record.code_ratio)
        residual_z = 0.0 if residual_std == 0.0 else float(residual / residual_std)
        if abs(residual_z) < threshold:
            continue
        outliers.append(
            RegressionOutlier(
                name=record.name,
                code_ratio=record.code_ratio,
                exec_ratio=record.exec_ratio,
                predicted_exec_ratio=predicted,
                residual=float(residual),
                residual_z=residual_z,
            )
        )
    outliers.sort(key=lambda row: abs(row.residual_z), reverse=True)
    return outliers


def fit_linear_model(x: np.ndarray, y: np.ndarray) -> tuple[np.ndarray, float]:
    coefficients, _, _, _ = np.linalg.lstsq(x, y, rcond=None)
    predictions = x @ coefficients
    ss_res = float(np.sum((y - predictions) ** 2))
    ss_tot = float(np.sum((y - np.mean(y)) ** 2))
    if ss_tot == 0.0:
        return coefficients, 1.0
    return coefficients, 1.0 - (ss_res / ss_tot)


def zscore(values: np.ndarray) -> np.ndarray:
    stdev = sample_stdev(values)
    if stdev == 0.0:
        return np.zeros_like(values)
    return (values - np.mean(values)) / stdev


def build_prediction_model(records: list[BenchmarkRecord]) -> PredictionModel:
    usable_records = [
        record for record in records if record.bpf_insn_count is not None and record.branch_count is not None
    ]
    feature_names = ("bpf_insn_count", "branch_count", "code_ratio")
    if not usable_records:
        return PredictionModel(benchmark_count=0, r_squared=math.nan, intercept=math.nan, features=tuple())

    y = np.asarray([record.exec_ratio for record in usable_records], dtype=np.float64)
    feature_columns = {
        "bpf_insn_count": np.asarray([float(record.bpf_insn_count) for record in usable_records], dtype=np.float64),
        "branch_count": np.asarray([float(record.branch_count) for record in usable_records], dtype=np.float64),
        "code_ratio": np.asarray([record.code_ratio for record in usable_records], dtype=np.float64),
    }

    x = np.column_stack([np.ones(len(usable_records), dtype=np.float64)] + [feature_columns[name] for name in feature_names])
    coefficients, full_r2 = fit_linear_model(x, y)

    x_standardized = np.column_stack(
        [np.ones(len(usable_records), dtype=np.float64)] + [zscore(feature_columns[name]) for name in feature_names]
    )
    y_standardized = zscore(y)
    standardized_coefficients, _ = fit_linear_model(x_standardized, y_standardized)

    feature_rows: list[FeatureImportance] = []
    for index, feature_name in enumerate(feature_names, start=1):
        reduced_x = np.delete(x, index, axis=1)
        _, reduced_r2 = fit_linear_model(reduced_x, y)

        univariate_x = np.column_stack([np.ones(len(usable_records), dtype=np.float64), feature_columns[feature_name]])
        _, univariate_r2 = fit_linear_model(univariate_x, y)

        feature_rows.append(
            FeatureImportance(
                feature=feature_name,
                raw_coefficient=float(coefficients[index]),
                standardized_beta=float(standardized_coefficients[index]),
                drop_in_r2=float(full_r2 - reduced_r2),
                univariate_r2=float(univariate_r2),
            )
        )

    feature_rows.sort(key=lambda row: abs(row.standardized_beta), reverse=True)
    return PredictionModel(
        benchmark_count=len(usable_records),
        r_squared=float(full_r2),
        intercept=float(coefficients[0]),
        features=tuple(feature_rows),
    )


def format_float(value: float | None, precision: int = 3) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:.{precision}f}"


def format_ratio(value: float | None, precision: int = 3) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:.{precision}f}x"


def format_percent(value: float | None, precision: int = 1) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value * 100:.{precision}f}%"


def format_pvalue(value: float | None) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    if value < 1e-4:
        return f"{value:.2e}"
    return f"{value:.4f}"


def winner_label(exec_ratio: float) -> str:
    if exec_ratio < 1.0:
        return "llvmbpf"
    if exec_ratio > 1.0:
        return "kernel"
    return "tie"


def runtime_noise_label(record: BenchmarkRecord) -> str:
    if math.isnan(record.llvmbpf_cv) or math.isnan(record.kernel_cv):
        return "n/a"
    if math.isclose(record.llvmbpf_cv, record.kernel_cv):
        return "tie"
    return "llvmbpf" if record.llvmbpf_cv > record.kernel_cv else "kernel"


def effect_direction_label(effect_size: float) -> str:
    if not math.isfinite(effect_size) or effect_size == 0.0:
        return "tie"
    return "kernel" if effect_size > 0.0 else "llvmbpf"


def render_key_findings(
    records: list[BenchmarkRecord],
    category_summaries: list[CategorySummary],
    code_exec_correlation: CorrelationSummary,
    outliers: list[RegressionOutlier],
    compile_correlation: CorrelationSummary,
    compile_fit: linregress,
    prediction_model: PredictionModel,
) -> list[str]:
    suite_exec_geomean = geometric_mean([record.exec_ratio for record in records])
    suite_code_geomean = geometric_mean([record.code_ratio for record in records])
    llvmbpf_wins = sum(1 for record in records if record.exec_ratio < 1.0)
    best_categories = sorted(category_summaries, key=lambda row: row.exec_geomean)[:3]
    worst_categories = sorted(category_summaries, key=lambda row: row.exec_geomean, reverse=True)[:2]
    kernel_noisier = sum(1 for record in records if runtime_noise_label(record) == "kernel")
    llvmbpf_noisier = sum(1 for record in records if runtime_noise_label(record) == "llvmbpf")
    effect_counts = Counter(record.effect_class for record in records)
    compile_crossover = None
    if compile_fit.slope != 0.0:
        compile_crossover = (1.0 - compile_fit.intercept) / compile_fit.slope

    lines = [
        "## Key Findings",
        "",
        (
            f"- llvmbpf wins `{llvmbpf_wins}/{len(records)}` benchmarks overall with a suite exec geomean of "
            f"`{format_ratio(suite_exec_geomean)}` and a code-size geomean of `{format_ratio(suite_code_geomean)}`."
        ),
        (
            f"- The biggest LLVM-friendly categories are "
            f"{', '.join(f'`{row.category}` ({format_ratio(row.exec_geomean)})' for row in best_categories)}, "
            f"while `{worst_categories[0].category}` and `{worst_categories[1].category}` regress."
        ),
        (
            f"- Code-size reduction is a weak predictor of steady-state speed: Pearson `r={format_float(code_exec_correlation.pearson_r)}` "
            f"(p=`{format_pvalue(code_exec_correlation.pearson_p)}`) and Spearman "
            f"`rho={format_float(code_exec_correlation.spearman_rho)}` (p=`{format_pvalue(code_exec_correlation.spearman_p)}`)."
        ),
        (
            f"- The largest code-size/performance paradox outliers are "
            f"{', '.join(f'`{row.name}`' for row in outliers[:5])}; positive residuals mean llvmbpf is slower than its code shrink alone would suggest."
        ),
        (
            f"- Kernel execution timing is noisier on `{kernel_noisier}/{len(records)}` benchmarks versus "
            f"`{llvmbpf_noisier}/{len(records)}` for llvmbpf. Most differences are practically meaningful: "
            f"`{effect_counts.get('large', 0)}` large, `{effect_counts.get('medium', 0)}` medium, `{effect_counts.get('small', 0)}` small."
        ),
        (
            f"- Compile-time penalty falls only weakly with size (Pearson `r={format_float(compile_correlation.pearson_r)}`, "
            f"p=`{format_pvalue(compile_correlation.pearson_p)}`); the fitted crossover is "
            f"`{format_float(compile_crossover, 0) if compile_crossover is not None else 'n/a'}` BPF insns, but the data do not show a clean monotonic threshold. "
            f"The static-feature runtime model is also weak (`R²={format_float(prediction_model.r_squared)}`)."
        ),
        "",
    ]
    return lines


def render_report(input_path: Path, program_dir: Path, records: list[BenchmarkRecord]) -> str:
    category_summaries = summarize_categories(records)
    code_exec_correlation = correlation_summary(
        [record.code_ratio for record in records],
        [record.exec_ratio for record in records],
    )
    outliers = identify_outliers(records)
    compile_correlation = correlation_summary(
        [float(record.bpf_insn_count) for record in records if record.bpf_insn_count is not None],
        [record.compile_ratio for record in records if record.bpf_insn_count is not None],
    )
    compile_fit = linregress(
        [float(record.bpf_insn_count) for record in records if record.bpf_insn_count is not None],
        [record.compile_ratio for record in records if record.bpf_insn_count is not None],
    )
    prediction_model = build_prediction_model(records)
    generated_at = datetime.now(timezone.utc).isoformat()
    branch_count_coverage = sum(1 for record in records if record.branch_count is not None)

    high_variance_records = [
        record
        for record in records
        if record.llvmbpf_cv > HIGH_VARIANCE_THRESHOLD or record.kernel_cv > HIGH_VARIANCE_THRESHOLD
    ]
    high_variance_records.sort(key=lambda record: max(record.llvmbpf_cv, record.kernel_cv), reverse=True)

    effect_summary = Counter(record.effect_class for record in records)
    effect_by_direction: dict[str, Counter[str]] = defaultdict(Counter)
    for record in records:
        effect_by_direction[record.effect_class][effect_direction_label(record.effect_size)] += 1

    compile_faster_records = [record for record in records if record.compile_ratio < 1.0]
    compile_faster_records.sort(key=lambda record: record.compile_ratio)
    compile_crossover = None
    if compile_fit.slope != 0.0:
        compile_crossover = (1.0 - compile_fit.intercept) / compile_fit.slope

    lines = [
        "# Deep Performance Analysis",
        "",
        f"- Input JSON: `{input_path}`",
        f"- Program objects: `{program_dir}`",
        f"- Generated at: `{generated_at}`",
        f"- Benchmarks analyzed: `{len(records)}`",
        f"- Branch-count source: static bytecode analysis of `micro/programs/*.bpf.o` (`{branch_count_coverage}/{len(records)}` coverage) because the manifest does not expose numeric branch counts.",
        "",
    ]

    lines.extend(
        render_key_findings(
            records=records,
            category_summaries=category_summaries,
            code_exec_correlation=code_exec_correlation,
            outliers=outliers,
            compile_correlation=compile_correlation,
            compile_fit=compile_fit,
            prediction_model=prediction_model,
        )
    )

    lines.extend(
        [
            "## 1. Per-Category Performance Breakdown",
            "",
            "| Category | Benchmarks | Exec geomean (L/K) | Code-size geomean (L/K) | llvmbpf wins | kernel wins |",
            "| --- | ---: | ---: | ---: | ---: | ---: |",
        ]
    )
    for summary in category_summaries:
        lines.append(
            f"| {summary.category} | {summary.benchmark_count} | {format_ratio(summary.exec_geomean)} | "
            f"{format_ratio(summary.code_geomean)} | {summary.llvmbpf_wins} | {summary.kernel_wins} |"
        )

    lines.extend(
        [
            "",
            "| Rank | Category | Exec geomean (L/K) | Interpretation |",
            "| --- | --- | ---: | --- |",
        ]
    )
    for rank, summary in enumerate(sorted(category_summaries, key=lambda row: row.exec_geomean), start=1):
        interpretation = "llvmbpf benefit" if summary.exec_geomean < 1.0 else "kernel benefit"
        lines.append(f"| {rank} | {summary.category} | {format_ratio(summary.exec_geomean)} | {interpretation} |")

    lines.extend(
        [
            "",
            "## 2. Performance-vs-Code-Size Correlation",
            "",
            "| Metric | Value |",
            "| --- | ---: |",
            f"| Pearson r | {format_float(code_exec_correlation.pearson_r)} |",
            f"| Pearson p-value | {format_pvalue(code_exec_correlation.pearson_p)} |",
            f"| Spearman rho | {format_float(code_exec_correlation.spearman_rho)} |",
            f"| Spearman p-value | {format_pvalue(code_exec_correlation.spearman_p)} |",
            f"| Linear fit slope | {format_float(code_exec_correlation.slope)} |",
            f"| Linear fit intercept | {format_float(code_exec_correlation.intercept)} |",
            f"| Linear-fit R² | {format_float(code_exec_correlation.r_squared)} |",
            "",
            (
                "Outliers below use standardized residuals from the linear fit "
                f"`exec_ratio = {format_float(code_exec_correlation.intercept)} + {format_float(code_exec_correlation.slope)} * code_ratio`; "
                f"threshold is `|z| >= {OUTLIER_Z_THRESHOLD}`."
            ),
            "",
            "| Benchmark | Code ratio (L/K) | Exec ratio (L/K) | Predicted exec ratio | Residual | Residual z-score | Reading |",
            "| --- | ---: | ---: | ---: | ---: | ---: | --- |",
        ]
    )
    for row in outliers:
        reading = "slower than code size suggests" if row.residual > 0.0 else "faster than code size suggests"
        lines.append(
            f"| {row.name} | {format_ratio(row.code_ratio)} | {format_ratio(row.exec_ratio)} | "
            f"{format_ratio(row.predicted_exec_ratio)} | {format_float(row.residual)} | {format_float(row.residual_z, 2)} | {reading} |"
        )
    if not outliers:
        lines.append("| _none_ | n/a | n/a | n/a | n/a | n/a | no residual outliers crossed the threshold |")

    lines.extend(
        [
            "",
            "## 3. Execution Time Distribution Analysis",
            "",
            (
                f"High-variance benchmarks are flagged when either runtime has `CV > {format_percent(HIGH_VARIANCE_THRESHOLD)}`. "
                "Kernel-noisier means the kernel CV exceeds llvmbpf's CV for the same benchmark."
            ),
            "",
            "| Benchmark | llvmbpf CV | kernel CV | High variance? | Noisier runtime |",
            "| --- | ---: | ---: | --- | --- |",
        ]
    )
    for record in sorted(records, key=lambda row: max(row.llvmbpf_cv, row.kernel_cv), reverse=True):
        lines.append(
            f"| {record.name} | {format_percent(record.llvmbpf_cv)} | {format_percent(record.kernel_cv)} | "
            f"{'Yes' if record in high_variance_records else 'No'} | {runtime_noise_label(record)} |"
        )

    kernel_noisier = sum(1 for record in records if runtime_noise_label(record) == "kernel")
    llvmbpf_noisier = sum(1 for record in records if runtime_noise_label(record) == "llvmbpf")
    lines.extend(
        [
            "",
            "| Summary metric | Value |",
            "| --- | ---: |",
            f"| Benchmarks with CV > 10% in either runtime | {len(high_variance_records)} / {len(records)} |",
            f"| llvmbpf-only high variance | {sum(1 for record in high_variance_records if record.llvmbpf_cv > HIGH_VARIANCE_THRESHOLD and record.kernel_cv <= HIGH_VARIANCE_THRESHOLD)} |",
            f"| kernel-only high variance | {sum(1 for record in high_variance_records if record.kernel_cv > HIGH_VARIANCE_THRESHOLD and record.llvmbpf_cv <= HIGH_VARIANCE_THRESHOLD)} |",
            f"| high variance in both runtimes | {sum(1 for record in high_variance_records if record.llvmbpf_cv > HIGH_VARIANCE_THRESHOLD and record.kernel_cv > HIGH_VARIANCE_THRESHOLD)} |",
            f"| Kernel noisier benchmarks | {kernel_noisier} / {len(records)} |",
            f"| llvmbpf noisier benchmarks | {llvmbpf_noisier} / {len(records)} |",
            f"| Median llvmbpf CV | {format_percent(float(np.median([record.llvmbpf_cv for record in records])))} |",
            f"| Median kernel CV | {format_percent(float(np.median([record.kernel_cv for record in records])))} |",
            "",
            "## 4. Effect Size Spectrum",
            "",
            "| Class | Count | Favoring llvmbpf | Favoring kernel |",
            "| --- | ---: | ---: | ---: |",
            f"| small | {effect_summary.get('small', 0)} | {effect_by_direction['small'].get('llvmbpf', 0)} | {effect_by_direction['small'].get('kernel', 0)} |",
            f"| medium | {effect_summary.get('medium', 0)} | {effect_by_direction['medium'].get('llvmbpf', 0)} | {effect_by_direction['medium'].get('kernel', 0)} |",
            f"| large | {effect_summary.get('large', 0)} | {effect_by_direction['large'].get('llvmbpf', 0)} | {effect_by_direction['large'].get('kernel', 0)} |",
            "",
            "| Benchmark | Cohen's d | Magnitude | Direction | Exec ratio (L/K) |",
            "| --- | ---: | --- | --- | ---: |",
        ]
    )
    for record in sorted(records, key=lambda row: abs(row.effect_size), reverse=True):
        lines.append(
            f"| {record.name} | {format_float(record.effect_size)} | {record.effect_class} | "
            f"{effect_direction_label(record.effect_size)} | {format_ratio(record.exec_ratio)} |"
        )

    lines.extend(
        [
            "",
            "## 5. Compile Time vs Program Complexity",
            "",
            "| Metric | Value |",
            "| --- | ---: |",
            f"| Pearson r (insns vs compile ratio) | {format_float(compile_correlation.pearson_r)} |",
            f"| Pearson p-value | {format_pvalue(compile_correlation.pearson_p)} |",
            f"| Spearman rho | {format_float(compile_correlation.spearman_rho)} |",
            f"| Spearman p-value | {format_pvalue(compile_correlation.spearman_p)} |",
            f"| Linear fit slope | {format_float(compile_correlation.slope)} |",
            f"| Linear fit intercept | {format_float(compile_correlation.intercept)} |",
            f"| Linear-fit R² | {format_float(compile_correlation.r_squared)} |",
            f"| Estimated ratio=1 crossover | {format_float(compile_crossover, 0) if compile_crossover is not None else 'n/a'} BPF insns |",
            "",
            (
                "Empirically, llvmbpf already beats kernel compile time for a handful of mid-sized programs, "
                "so program size alone is not a reliable crossover predictor."
            ),
            "",
            "| Benchmark | BPF insns | Compile ratio (L/K) | Winner |",
            "| --- | ---: | ---: | --- |",
        ]
    )
    for record in sorted(records, key=lambda row: (row.bpf_insn_count or 0, row.compile_ratio)):
        lines.append(
            f"| {record.name} | {record.bpf_insn_count if record.bpf_insn_count is not None else 'n/a'} | "
            f"{format_ratio(record.compile_ratio)} | {winner_label(record.compile_ratio)} |"
        )

    lines.extend(
        [
            "",
            "| Empirical compile-time win set | BPF insn count | Compile ratio (L/K) |",
            "| --- | ---: | ---: |",
        ]
    )
    for record in compile_faster_records:
        lines.append(
            f"| {record.name} | {record.bpf_insn_count if record.bpf_insn_count is not None else 'n/a'} | {format_ratio(record.compile_ratio)} |"
        )
    if not compile_faster_records:
        lines.append("| _none_ | n/a | n/a |")

    lines.extend(
        [
            "",
            "## 6. Performance Prediction from Static Features",
            "",
            (
                "This model uses benchmark-level `exec_ratio` as the target and "
                "`bpf_insn_count`, `branch_count`, and `code_ratio` as features. "
                "Branch counts come from static bytecode analysis of the compiled benchmark objects."
            ),
            "",
            "| Metric | Value |",
            "| --- | ---: |",
            f"| Benchmarks with full feature coverage | {prediction_model.benchmark_count} / {len(records)} |",
            f"| Model R² | {format_float(prediction_model.r_squared)} |",
            f"| Intercept | {format_float(prediction_model.intercept)} |",
            "",
            "| Feature | Raw coefficient | Standardized beta | Drop in R² when removed | Univariate R² |",
            "| --- | ---: | ---: | ---: | ---: |",
        ]
    )
    for feature in prediction_model.features:
        lines.append(
            f"| {feature.feature} | {format_float(feature.raw_coefficient)} | {format_float(feature.standardized_beta)} | "
            f"{format_float(feature.drop_in_r2)} | {format_float(feature.univariate_r2)} |"
        )

    lines.extend(
        [
            "",
            "Interpretation: positive coefficients increase `llvmbpf/kernel` exec ratio and therefore predict worse llvmbpf runtime. "
            "Negative coefficients predict relative llvmbpf speedups. The low `R²` means these static features explain only a small fraction of the runtime spread.",
            "",
        ]
    )

    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    program_dir = Path(args.program_dir).resolve()

    results = load_results(input_path)
    records = build_benchmark_records(results, program_dir)
    report = render_report(input_path, program_dir, records)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(report + "\n")
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
