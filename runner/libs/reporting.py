from __future__ import annotations

import math
import random
import statistics
from dataclasses import dataclass
from typing import Mapping, Sequence

from micro.catalog import ManifestSpec, load_manifest_from_results
from runner.libs.statistics import geometric_mean


PRIMARY_RUNTIME = "llvmbpf"
BASELINE_RUNTIME = "kernel"


@dataclass(frozen=True)
class ComparisonSummary:
    geomean: float | None
    ci: tuple[float, float] | None
    wins: tuple[int, int, int]


@dataclass(frozen=True)
class BenchmarkStatistics:
    name: str
    category: str | None
    family: str | None
    level: str | None
    llvmbpf_exec_ns: float | None
    kernel_exec_ns: float | None
    llvmbpf_compile_ns: float | None
    kernel_compile_ns: float | None
    raw_exec_ratio: float | None
    adjusted_exec_ratio: float | None
    adjusted_exec_ci: tuple[float, float] | None
    is_baseline: bool = False


@dataclass(frozen=True)
class GroupStatistics:
    group_name: str
    benchmark_count: int
    adjusted_geomean: float | None
    adjusted_ci: tuple[float, float] | None
    wins: tuple[int, int, int]


@dataclass(frozen=True)
class PerfRuntimeStatistics:
    runtime: str
    benchmark_count: int
    hardware_counters_observed: int
    total_runtime_records: int
    ipc_median: float | None
    branch_miss_rate_median: float | None
    cache_miss_rate_median: float | None


@dataclass(frozen=True)
class RQReport:
    suite_name: str
    manifest: ManifestSpec | None
    result_benchmark_count: int
    baseline_name: str | None
    raw_exec_summary: ComparisonSummary
    adjusted_exec_summary: ComparisonSummary | None
    benchmarks: tuple[BenchmarkStatistics, ...]
    category_groups: tuple[GroupStatistics, ...]
    family_groups: tuple[GroupStatistics, ...]
    directional_advantages: tuple[BenchmarkStatistics, ...]
    directional_disadvantages: tuple[BenchmarkStatistics, ...]
    perf_runtimes: tuple[PerfRuntimeStatistics, ...]
    bootstrap_iterations: int
    bootstrap_seed: int


def _mapping(value: object) -> Mapping[str, object]:
    if isinstance(value, Mapping):
        return value
    return {}


def _sequence(value: object) -> Sequence[object]:
    if isinstance(value, Sequence) and not isinstance(value, (str, bytes, bytearray)):
        return value
    return ()


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


def bootstrap_geometric_mean_ci(values: list[float], iterations: int, seed: int) -> tuple[float, float] | None:
    filtered = [value for value in values if value > 0.0]
    if not filtered: return None
    if len(filtered) == 1: return (filtered[0], filtered[0])
    rng = random.Random(seed)
    bootstraps: list[float] = []
    for _ in range(iterations):
        sample = [filtered[rng.randrange(len(filtered))] for _ in range(len(filtered))]
        if (estimate := geometric_mean(sample)) is not None:
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
        resample = lambda s: [s[rng.randrange(len(s))] for _ in range(len(s))]  # noqa: E731
        numerator = float(statistics.median(resample(numerator_samples)))
        denominator = float(statistics.median(resample(denominator_samples)))
        if baseline_numerator_samples is not None and baseline_denominator_samples is not None:
            numerator = max(numerator - float(statistics.median(resample(baseline_numerator_samples))), 0.0)
            denominator = max(denominator - float(statistics.median(resample(baseline_denominator_samples))), 0.0)
        if numerator > 0.0 and denominator > 0.0:
            bootstraps.append(numerator / denominator)
    if not bootstraps:
        return None
    bootstraps.sort()
    return percentile(bootstraps, 0.025), percentile(bootstraps, 0.975)


def _metric_median(run: Mapping[str, object], metric: str) -> float | None:
    summary = run.get(metric)
    if isinstance(summary, Mapping):
        value = summary.get("median")
        if value is not None:
            return float(value)
    return None


def _run_lookup(benchmark: Mapping[str, object]) -> dict[str, Mapping[str, object]]:
    return {str(run["runtime"]): _mapping(run) for run in _sequence(benchmark.get("runs")) if isinstance(run, Mapping)}


def _exec_samples(run: Mapping[str, object]) -> list[float]:
    samples: list[float] = []
    for sample in _sequence(run.get("samples")):
        if not isinstance(sample, Mapping):
            continue
        value = sample.get("exec_ns")
        if value is None:
            continue
        samples.append(float(value))
    return samples


def _safe_ratio(numerator: float | None, denominator: float | None) -> float | None:
    if numerator in (None, 0) or denominator in (None, 0):
        return None
    return float(numerator) / float(denominator)


def _benchmark_raw_ratio(
    benchmark: Mapping[str, object],
    llvmbpf_exec_ns: float | None,
    kernel_exec_ns: float | None,
) -> float | None:
    runtime_comparison = _mapping(benchmark.get("runtime_comparison"))
    raw_ratio = runtime_comparison.get("llvmbpf_over_kernel_exec_ratio")
    if raw_ratio is not None:
        return float(raw_ratio)
    return _safe_ratio(llvmbpf_exec_ns, kernel_exec_ns)


def _benchmark_adjusted_ratio(
    benchmark: Mapping[str, object],
    llvmbpf_run: Mapping[str, object],
    kernel_run: Mapping[str, object],
) -> float | None:
    runtime_comparison = _mapping(benchmark.get("runtime_comparison"))
    adjusted_ratio = runtime_comparison.get("llvmbpf_over_kernel_adjusted_exec_ratio")
    if adjusted_ratio is not None:
        return float(adjusted_ratio)

    llvmbpf_adjusted = _mapping(llvmbpf_run.get("baseline_adjustment")).get("median_minus_baseline_ns")
    kernel_adjusted = _mapping(kernel_run.get("baseline_adjustment")).get("median_minus_baseline_ns")
    if llvmbpf_adjusted in (None, 0) or kernel_adjusted in (None, 0):
        return None
    return float(llvmbpf_adjusted) / float(kernel_adjusted)


def _detect_baseline_name(results: Mapping[str, object], manifest: ManifestSpec | None) -> str | None:
    if manifest is not None and manifest.analysis.baseline_benchmark is not None:
        return manifest.analysis.baseline_benchmark
    benchmark_names = {str(benchmark.get("name")) for benchmark in _sequence(results.get("benchmarks")) if isinstance(benchmark, Mapping)}
    if "simple" in benchmark_names:
        for benchmark in _sequence(results.get("benchmarks")):
            runtime_comparison = _mapping(_mapping(benchmark).get("runtime_comparison"))
            if runtime_comparison.get("llvmbpf_over_kernel_adjusted_exec_ratio") is not None:
                return "simple"
    return None


def win_counts(ratios: list[float], tie_epsilon: float = 0.02) -> tuple[int, int, int]:
    llvmbpf_wins = sum(1 for r in ratios if r < 1.0 and abs(r - 1.0) > tie_epsilon)
    kernel_wins = sum(1 for r in ratios if r > 1.0 and abs(r - 1.0) > tie_epsilon)
    ties = len(ratios) - llvmbpf_wins - kernel_wins
    return llvmbpf_wins, kernel_wins, ties


def _ordered_group_values(
    benchmarks: Sequence[BenchmarkStatistics],
    field_name: str,
    preferred_order: Sequence[str],
) -> list[str]:
    ordered: list[str] = []
    seen: set[str] = set()
    for value in preferred_order:
        if value not in seen:
            ordered.append(value)
            seen.add(value)
    for benchmark in benchmarks:
        value = getattr(benchmark, field_name)
        if value is None or value in seen:
            continue
        ordered.append(value)
        seen.add(value)
    return ordered


def compute_per_benchmark_statistics(
    results: Mapping[str, object],
    *,
    manifest: ManifestSpec | None = None,
    bootstrap_iterations: int = 5000,
    bootstrap_seed: int = 20260306,
) -> tuple[BenchmarkStatistics, ...]:
    resolved_manifest = manifest or load_manifest_from_results(results)
    baseline_name = _detect_baseline_name(results, resolved_manifest)
    manifest_targets = resolved_manifest.targets_by_name if resolved_manifest is not None else {}

    baseline_benchmark = None
    if baseline_name is not None:
        for benchmark in _sequence(results.get("benchmarks")):
            benchmark_mapping = _mapping(benchmark)
            if str(benchmark_mapping.get("name")) == baseline_name:
                baseline_benchmark = benchmark_mapping
                break

    baseline_runs = _run_lookup(baseline_benchmark or {})
    baseline_llvmbpf_samples = _exec_samples(baseline_runs.get(PRIMARY_RUNTIME, {}))
    baseline_kernel_samples = _exec_samples(baseline_runs.get(BASELINE_RUNTIME, {}))

    statistics_rows: list[BenchmarkStatistics] = []
    for index, raw_benchmark in enumerate(_sequence(results.get("benchmarks"))):
        benchmark = _mapping(raw_benchmark)
        name = str(benchmark.get("name", ""))
        mt = manifest_targets.get(name)
        runs = _run_lookup(benchmark)
        llvmbpf_run = runs.get(PRIMARY_RUNTIME, {})
        kernel_run = runs.get(BASELINE_RUNTIME, {})
        llvmbpf_exec_ns = _metric_median(llvmbpf_run, "exec_ns")
        kernel_exec_ns = _metric_median(kernel_run, "exec_ns")
        adjusted_ratio = _benchmark_adjusted_ratio(benchmark, llvmbpf_run, kernel_run)
        ci = None
        if adjusted_ratio is not None and baseline_name is not None and name != baseline_name and baseline_llvmbpf_samples and baseline_kernel_samples:
            ci = bootstrap_ratio_ci(_exec_samples(llvmbpf_run), _exec_samples(kernel_run),
                                    bootstrap_iterations, bootstrap_seed + 101 + index,
                                    baseline_llvmbpf_samples, baseline_kernel_samples)
        statistics_rows.append(BenchmarkStatistics(
            name=name,
            category=str(benchmark.get("category", mt.category if mt is not None else "")) or None,
            family=str(benchmark.get("family", mt.family if mt is not None else "")) or None,
            level=str(benchmark.get("level", mt.level if mt is not None else "")) or None,
            llvmbpf_exec_ns=llvmbpf_exec_ns, kernel_exec_ns=kernel_exec_ns,
            llvmbpf_compile_ns=_metric_median(llvmbpf_run, "compile_ns"),
            kernel_compile_ns=_metric_median(kernel_run, "compile_ns"),
            raw_exec_ratio=_benchmark_raw_ratio(benchmark, llvmbpf_exec_ns, kernel_exec_ns),
            adjusted_exec_ratio=adjusted_ratio, adjusted_exec_ci=ci, is_baseline=(name == baseline_name),
        ))
    return tuple(statistics_rows)


def _comparison_summary(
    ratios: list[float],
    *,
    iterations: int,
    seed: int,
) -> ComparisonSummary:
    return ComparisonSummary(
        geomean=geometric_mean(ratios),
        ci=bootstrap_geometric_mean_ci(ratios, iterations, seed),
        wins=win_counts(ratios),
    )


def _group_statistics(
    benchmarks: Sequence[BenchmarkStatistics],
    *,
    field_name: str,
    preferred_order: Sequence[str],
    bootstrap_iterations: int,
    bootstrap_seed: int,
) -> tuple[GroupStatistics, ...]:
    grouped: dict[str, list[float]] = {}
    for benchmark in benchmarks:
        value = getattr(benchmark, field_name)
        ratio = benchmark.adjusted_exec_ratio
        if value is None or ratio is None:
            continue
        grouped.setdefault(value, []).append(float(ratio))

    rows: list[GroupStatistics] = []
    for index, value in enumerate(_ordered_group_values(benchmarks, field_name, preferred_order)):
        ratios = grouped.get(value, [])
        if not ratios:
            continue
        rows.append(
            GroupStatistics(
                group_name=value,
                benchmark_count=len(ratios),
                adjusted_geomean=geometric_mean(ratios),
                adjusted_ci=bootstrap_geometric_mean_ci(ratios, bootstrap_iterations, bootstrap_seed + 1000 + index),
                wins=win_counts(ratios),
            )
        )
    return tuple(rows)


def _perf_runtime_statistics(results: Mapping[str, object]) -> tuple[PerfRuntimeStatistics, ...]:
    runtime_metrics: dict[str, dict[str, list[float]]] = {}
    for raw_benchmark in _sequence(results.get("benchmarks")):
        for raw_run in _sequence(_mapping(raw_benchmark).get("runs")):
            run = _mapping(raw_run)
            runtime = str(run.get("runtime", ""))
            if not runtime: continue
            bucket = runtime_metrics.setdefault(runtime, {"ipc": [], "branch_miss": [], "cache_miss": [], "hw_counter": []})
            derived = _mapping(run.get("derived_metrics"))
            meta = _mapping(run.get("perf_counters_meta"))
            for key, field in (("ipc", "ipc_median"), ("branch_miss", "branch_miss_rate_median"), ("cache_miss", "cache_miss_rate_median")):
                if derived.get(field) is not None: bucket[key].append(float(derived[field]))
            bucket["hw_counter"].append(1.0 if meta.get("hardware_counters_observed") else 0.0)
    rows: list[PerfRuntimeStatistics] = []
    for runtime in sorted(runtime_metrics):
        m = runtime_metrics[runtime]
        n = len(m["hw_counter"])
        rows.append(PerfRuntimeStatistics(
            runtime=runtime, benchmark_count=n, hardware_counters_observed=sum(1 for v in m["hw_counter"] if v > 0.0),
            total_runtime_records=n, ipc_median=statistics.median(m["ipc"]) if m["ipc"] else None,
            branch_miss_rate_median=statistics.median(m["branch_miss"]) if m["branch_miss"] else None,
            cache_miss_rate_median=statistics.median(m["cache_miss"]) if m["cache_miss"] else None,
        ))
    return tuple(rows)


def build_rq_report(
    results: Mapping[str, object],
    *,
    manifest: ManifestSpec | None = None,
    bootstrap_iterations: int = 5000,
    bootstrap_seed: int = 20260306,
) -> RQReport:
    resolved_manifest = manifest or load_manifest_from_results(results)
    benchmark_rows = compute_per_benchmark_statistics(
        results,
        manifest=resolved_manifest,
        bootstrap_iterations=bootstrap_iterations,
        bootstrap_seed=bootstrap_seed,
    )
    raw_ratios = [ratio for benchmark in benchmark_rows if (ratio := benchmark.raw_exec_ratio) is not None]
    adjusted_ratios = [ratio for benchmark in benchmark_rows if (ratio := benchmark.adjusted_exec_ratio) is not None]
    baseline_name = _detect_baseline_name(results, resolved_manifest)

    category_order = resolved_manifest.categories if resolved_manifest is not None else ()
    family_order = resolved_manifest.families if resolved_manifest is not None else ()
    category_groups = _group_statistics(
        benchmark_rows,
        field_name="category",
        preferred_order=category_order,
        bootstrap_iterations=bootstrap_iterations,
        bootstrap_seed=bootstrap_seed,
    )
    family_groups = _group_statistics(
        benchmark_rows,
        field_name="family",
        preferred_order=family_order,
        bootstrap_iterations=bootstrap_iterations,
        bootstrap_seed=bootstrap_seed + 500,
    )

    ranked = [
        benchmark
        for benchmark in benchmark_rows
        if benchmark.adjusted_exec_ratio is not None
        if not benchmark.is_baseline
        if benchmark.category != "baseline"
    ]
    ranked.sort(key=lambda benchmark: float(benchmark.adjusted_exec_ratio))

    adjusted_summary = None
    if adjusted_ratios or baseline_name is not None:
        adjusted_summary = _comparison_summary(
            adjusted_ratios,
            iterations=bootstrap_iterations,
            seed=bootstrap_seed + 1,
        )

    return RQReport(
        suite_name=str(results.get("suite", resolved_manifest.suite_name if resolved_manifest is not None else "unknown")),
        manifest=resolved_manifest,
        result_benchmark_count=len(tuple(_sequence(results.get("benchmarks")))),
        baseline_name=baseline_name,
        raw_exec_summary=_comparison_summary(raw_ratios, iterations=bootstrap_iterations, seed=bootstrap_seed),
        adjusted_exec_summary=adjusted_summary,
        benchmarks=benchmark_rows,
        category_groups=category_groups,
        family_groups=family_groups,
        directional_advantages=tuple(ranked[:5]),
        directional_disadvantages=tuple(reversed(ranked[-5:])),
        perf_runtimes=_perf_runtime_statistics(results),
        bootstrap_iterations=bootstrap_iterations,
        bootstrap_seed=bootstrap_seed,
    )


def render_rq_summary_markdown(
    results: Mapping[str, object],
    *,
    manifest: ManifestSpec | None = None,
    bootstrap_iterations: int = 5000,
    bootstrap_seed: int = 20260306,
) -> str:
    report = build_rq_report(
        results,
        manifest=manifest,
        bootstrap_iterations=bootstrap_iterations,
        bootstrap_seed=bootstrap_seed,
    )
    host = _mapping(results.get("host"))
    defaults = _mapping(results.get("defaults"))
    manifest_targets = report.manifest.target_count if report.manifest is not None else None

    lines: list[str] = ["# Characterization Summary", "", "## Environment", "",
                        f"- Suite: `{report.suite_name}`"]
    if report.manifest is not None:
        lines.append(f"- Manifest: `{report.manifest.manifest_path}`")
    lines += [
        f"- Host: `{host.get('hostname', 'unknown')}` on `{host.get('platform', 'unknown')}`",
        f"- Requested defaults: samples={defaults.get('samples')}, warmups={defaults.get('warmups')}, "
        f"inner_repeat={defaults.get('inner_repeat')}, perf_counters={defaults.get('perf_counters')}",
        f"- Shuffle seed: `{defaults.get('shuffle_seed')}`",
    ]
    if manifest_targets is not None:
        lines.append(f"- Results cover `{report.result_benchmark_count}` of `{manifest_targets}` manifest targets")
    lines += [
        f"- Bootstrap summary statistics: iterations={report.bootstrap_iterations}, seed={report.bootstrap_seed}",
        "", "## Suite-Level Comparison", "", "| Metric | Value | 95% bootstrap CI |", "| --- | ---: | ---: |",
        f"| Raw exec `llvmbpf/kernel` geometric mean | {format_ratio_value(report.raw_exec_summary.geomean)} | "
        f"{format_ci(report.raw_exec_summary.ci)} |",
    ]
    if report.adjusted_exec_summary is not None:
        lines.append(f"| Baseline-adjusted exec `llvmbpf/kernel` geometric mean | "
                     f"{format_ratio_value(report.adjusted_exec_summary.geomean)} | "
                     f"{format_ci(report.adjusted_exec_summary.ci)} |")
    raw_wins = report.raw_exec_summary.wins
    lines.append(f"| Raw wins (`llvmbpf / kernel / tie`) | `{raw_wins[0]} / {raw_wins[1]} / {raw_wins[2]}` | n/a |")
    if report.adjusted_exec_summary is not None:
        adjusted_wins = report.adjusted_exec_summary.wins
        lines.append(f"| Adjusted wins (`llvmbpf / kernel / tie`) | "
                     f"`{adjusted_wins[0]} / {adjusted_wins[1]} / {adjusted_wins[2]}` | n/a |")

    lines += ["", "## Benchmark-Level Comparison", ""]
    if report.adjusted_exec_summary is not None:
        lines.append("The adjusted ratio subtracts each runtime's own baseline median before forming the "
                     "`llvmbpf/kernel` ratio. This is the primary pure-jit view.")
        if report.baseline_name is not None:
            lines.append(f"Calibration-oriented baseline rows such as `{report.baseline_name}` stay in the table, "
                         "but are excluded from directional rankings.")
        lines += ["", "| Benchmark | Category | Family | Level | llvmbpf exec | kernel exec | Raw ratio | Adjusted ratio | Adjusted ratio 95% CI |",
                  "| --- | --- | --- | --- | ---: | ---: | ---: | ---: | ---: |"]
        for b in report.benchmarks:
            lines.append(f"| `{b.name}` | `{b.category or '-'}` | `{b.family or '-'}` | `{b.level or '-'}` | "
                         f"{format_ns(b.llvmbpf_exec_ns)} | {format_ns(b.kernel_exec_ns)} | "
                         f"{format_ratio(b.llvmbpf_exec_ns, b.kernel_exec_ns)} | "
                         f"{format_ratio_value(b.adjusted_exec_ratio)} | {format_ci(b.adjusted_exec_ci)} |")
    else:
        lines += ["| Benchmark | Category | Family | Level | llvmbpf exec | kernel exec | Raw ratio |",
                  "| --- | --- | --- | --- | ---: | ---: | ---: |"]
        for b in report.benchmarks:
            lines.append(f"| `{b.name}` | `{b.category or '-'}` | `{b.family or '-'}` | `{b.level or '-'}` | "
                         f"{format_ns(b.llvmbpf_exec_ns)} | {format_ns(b.kernel_exec_ns)} | "
                         f"{format_ratio(b.llvmbpf_exec_ns, b.kernel_exec_ns)} |")

    if report.adjusted_exec_summary is not None:
        for heading, groups in (("Category-Level", report.category_groups), ("Family-Level", report.family_groups)):
            lines += ["", f"## {heading} Adjusted Summary", "",
                      "| Group | Benchmarks | Adjusted gmean | 95% bootstrap CI | Wins (`llvmbpf/kernel/tie`) |",
                      "| --- | ---: | ---: | ---: | --- |"]
            for g in groups:
                lines.append(f"| `{g.group_name}` | {g.benchmark_count} | "
                              f"{format_ratio_value(g.adjusted_geomean)} | {format_ci(g.adjusted_ci)} | "
                              f"`{g.wins[0]}/{g.wins[1]}/{g.wins[2]}` |")
        lines += ["", "## Directional Findings", "", "### Strongest llvmbpf advantages", ""]
        for b in report.directional_advantages:
            lines.append(f"- `{b.name}` (`{b.family or '-'}`, `{b.level or '-'}`): "
                         f"adjusted `llvmbpf/kernel = {b.adjusted_exec_ratio:.2f}x`")
        lines += ["", "### Kernel-leading or parity cases", ""]
        for b in report.directional_disadvantages:
            lines.append(f"- `{b.name}` (`{b.family or '-'}`, `{b.level or '-'}`): "
                         f"adjusted `llvmbpf/kernel = {b.adjusted_exec_ratio:.2f}x`")
    if report.perf_runtimes:
        lines += ["", "## Perf-Counter Signal", "",
                  "| Runtime | Benchmarks | HW counters observed | Median IPC across suite | Median branch-miss rate | Median cache-miss rate |",
                  "| --- | ---: | --- | ---: | ---: | ---: |"]
        for r in report.perf_runtimes:
            lines.append(f"| `{r.runtime}` | {r.benchmark_count} | {r.hardware_counters_observed}/{r.total_runtime_records} | "
                         f"{r.ipc_median if r.ipc_median is not None else 'n/a'} | "
                         f"{r.branch_miss_rate_median if r.branch_miss_rate_median is not None else 'n/a'} | "
                         f"{r.cache_miss_rate_median if r.cache_miss_rate_median is not None else 'n/a'} |")
    return "\n".join(lines)


def _format_dimension_counts(counts: Mapping[str, int]) -> str:
    if not counts:
        return "n/a"
    return ", ".join(f"`{name}` ({count})" for name, count in counts.items())


def render_corpus_summary_markdown(corpus: Mapping[str, object], *, manifest: ManifestSpec | None = None) -> str:
    lines: list[str] = ["", "## Corpus Snapshot", ""]
    if manifest is not None and manifest.manifest_kind == "macro":
        lines += [f"- Macro suite targets: `{manifest.target_count}`",
                  f"- Macro categories: {_format_dimension_counts(manifest.dimensions['category'].counts)}",
                  f"- Macro test methods: {_format_dimension_counts(manifest.dimensions['test_method'].counts)}",
                  f"- Macro program types: {_format_dimension_counts(manifest.dimensions['prog_type'].counts)}", ""]
    repos = corpus.get("repos")
    if isinstance(repos, Sequence) and not isinstance(repos, (str, bytes, bytearray)):
        lines += ["| Repo | Program sources | .bpf.c files |", "| --- | ---: | ---: |"]
        for repo in repos:
            if isinstance(repo, Mapping):
                lines.append(f"| `{repo.get('name', 'unknown')}` | {repo.get('num_program_sources', 0)} | {repo.get('num_bpf_c', 0)} |")
        lines.append(f"| **Total** | **{corpus.get('total_program_sources', 0)}** | **{corpus.get('total_bpf_c', 0)}** |")
        return "\n".join(lines)
    summary = corpus.get("summary")
    if isinstance(summary, Mapping):
        lines += ["| Metric | Value |", "| --- | ---: |"]
        for key in ("projects", "object_files", "measured_objects", "programs_found", "loadable_programs", "true_runnable_programs"):
            if key in summary: lines.append(f"| `{key}` | {summary[key]} |")
    return "\n".join(lines)

