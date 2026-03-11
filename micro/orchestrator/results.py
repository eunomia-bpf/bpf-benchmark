from __future__ import annotations

import json
import math
import statistics
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping, Sequence, TypedDict


class SummaryStats(TypedDict):
    count: int
    mean: float | int | None
    median: float | int | None
    min: float | int | None
    max: float | int | None
    p95: float | int | None
    stdev: float | int | None


class CodeSizeSummary(TypedDict, total=False):
    bpf_bytecode_bytes: int
    native_code_bytes: int
    inflation_ratio: float


class PerfCounterMeta(TypedDict, total=False):
    requested: bool
    collected: bool
    include_kernel: bool
    scope: str
    error: str


class DirectiveScanSummary(TypedDict, total=False):
    performed: bool
    cmov_sites: int
    wide_sites: int
    rotate_sites: int
    lea_sites: int
    total_sites: int


class RecompileSummary(TypedDict, total=False):
    requested: bool
    mode: str
    policy_generated: bool
    policy_bytes: int
    syscall_attempted: bool
    applied: bool
    error: str


class RunnerSample(TypedDict, total=False):
    compile_ns: int
    exec_ns: int
    timing_source: str
    opt_level: int
    no_cmov: bool
    wall_exec_ns: int
    exec_cycles: int
    tsc_freq_hz: int
    result: int
    retval: int
    jited_prog_len: int
    xlated_prog_len: int
    native_code_size: int
    bpf_insn_count: int
    code_size: CodeSizeSummary
    disabled_passes: list[str]
    phases_ns: dict[str, int]
    perf_counters: dict[str, int]
    perf_counters_meta: PerfCounterMeta
    directive_scan: DirectiveScanSummary
    recompile: RecompileSummary


@dataclass(frozen=True, slots=True)
class UnifiedResultRecord:
    """Core schema shared by micro suite, corpus recompile, and rigorous drivers."""

    suite: str
    target: Mapping[str, object]
    backend: str
    policy_mode: str
    transport: str = "local"
    manifest: str | None = None
    host: Mapping[str, object] | None = None
    inventory: Mapping[str, object] | None = None
    artifacts: Mapping[str, object] | None = None
    compile: Mapping[str, object] | None = None
    execution: Mapping[str, object] | None = None
    directive_scan: Mapping[str, object] | None = None
    recompile: Mapping[str, object] | None = None
    perf_counters: Mapping[str, object] | None = None
    samples: Sequence[RunnerSample] = field(default_factory=tuple)
    statistics: Mapping[str, object] | None = None
    correctness: Mapping[str, object] | None = None
    metadata: Mapping[str, object] | None = None


def load_json(path: str | Path) -> Any:
    return json.loads(Path(path).read_text())


def parse_last_json_line(stdout: str, *, label: str = "runner") -> Any:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"{label} produced no JSON output")
    try:
        return json.loads(lines[-1])
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"unable to parse {label} JSON output: {exc}") from exc


def parse_json_lines(stdout: str) -> list[Any]:
    payloads: list[Any] = []
    for line in stdout.splitlines():
        text = line.strip()
        if not text or (not text.startswith("{") and not text.startswith("[")):
            continue
        try:
            payloads.append(json.loads(text))
        except json.JSONDecodeError:
            continue
    return payloads


def zero_directive_scan() -> dict[str, int]:
    return {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }


def normalize_directive_scan(scan: Mapping[str, object] | None) -> dict[str, int]:
    normalized = zero_directive_scan()
    if not scan:
        return normalized
    for field in ("cmov_sites", "wide_sites", "rotate_sites", "lea_sites"):
        normalized[field] = int(scan.get(field, 0) or 0)
    normalized["total_sites"] = int(
        scan.get(
            "total_sites",
            normalized["cmov_sites"] + normalized["wide_sites"] + normalized["rotate_sites"] + normalized["lea_sites"],
        )
        or 0
    )
    return normalized


def normalize_runner_sample(sample: Mapping[str, object]) -> RunnerSample:
    normalized: RunnerSample = dict(sample)
    normalized.setdefault("disabled_passes", [])
    normalized.setdefault("code_size", {})
    normalized.setdefault("phases_ns", {})
    normalized.setdefault("perf_counters", {})
    normalized.setdefault(
        "perf_counters_meta",
        {
            "requested": False,
            "collected": False,
            "include_kernel": False,
            "scope": "full_repeat_raw",
            "error": "",
        },
    )
    normalized.setdefault(
        "directive_scan",
        {"performed": False, **zero_directive_scan()},
    )
    normalized.setdefault(
        "recompile",
        {
            "requested": False,
            "mode": "none",
            "policy_generated": False,
            "policy_bytes": 0,
            "syscall_attempted": False,
            "applied": False,
            "error": "",
        },
    )
    return normalized


def parse_runner_sample(stdout: str) -> RunnerSample:
    payload = parse_last_json_line(stdout)
    if not isinstance(payload, dict):
        raise RuntimeError("runner sample payload was not a JSON object")
    return normalize_runner_sample(payload)


def summarize_per_benchmark_samples(samples: Sequence[Mapping[str, object]]) -> dict[str, object]:
    counter_summary = summarize_named_counters(samples, "perf_counters")
    code_size_ratios = [
        float(code_size.get("inflation_ratio"))
        for sample in samples
        for code_size in [sample.get("code_size")]
        if isinstance(code_size, Mapping) and code_size.get("inflation_ratio") is not None
    ]
    return {
        "sample_count": len(samples),
        "compile_ns": summarize_optional_ns(samples, "compile_ns"),
        "exec_ns": summarize_optional_ns(samples, "exec_ns"),
        "wall_exec_ns": summarize_optional_ns(samples, "wall_exec_ns"),
        "phases_ns": summarize_phase_timings(samples),
        "perf_counters": counter_summary,
        "perf_counters_meta": summarize_perf_counter_meta(samples),
        "derived_perf_metrics": derive_perf_metrics(counter_summary),
        "inflation_ratio": float_summary(code_size_ratios) if code_size_ratios else None,
    }


def geometric_mean(values: Sequence[float | int]) -> float | None:
    positive = [float(value) for value in values if float(value) > 0.0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def ns_summary(values: Sequence[int]) -> SummaryStats:
    if not values:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
            "p95": None,
            "stdev": None,
        }

    sorted_values = sorted(values)
    p95_index = min(len(sorted_values) - 1, math.ceil(len(sorted_values) * 0.95) - 1)
    return {
        "count": len(values),
        "mean": statistics.mean(values),
        "median": statistics.median(values),
        "min": sorted_values[0],
        "max": sorted_values[-1],
        "p95": sorted_values[p95_index],
        "stdev": statistics.stdev(values) if len(values) > 1 else 0,
    }


def float_summary(values: Sequence[float | int]) -> SummaryStats:
    if not values:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
            "p95": None,
            "stdev": None,
        }

    sorted_values = sorted(float(value) for value in values)
    p95_index = min(len(sorted_values) - 1, math.ceil(len(sorted_values) * 0.95) - 1)
    return {
        "count": len(sorted_values),
        "mean": statistics.mean(sorted_values),
        "median": statistics.median(sorted_values),
        "min": sorted_values[0],
        "max": sorted_values[-1],
        "p95": sorted_values[p95_index],
        "stdev": statistics.stdev(sorted_values) if len(sorted_values) > 1 else 0,
    }


def summarize_phase_timings(samples: Sequence[Mapping[str, object]]) -> dict[str, SummaryStats]:
    buckets: dict[str, list[int]] = {}
    for sample in samples:
        phases = sample.get("phases_ns")
        if not isinstance(phases, Mapping):
            continue
        for name, value in phases.items():
            buckets.setdefault(str(name), []).append(int(value))
    return {name: ns_summary(values) for name, values in buckets.items()}


def summarize_named_counters(samples: Sequence[Mapping[str, object]], field_name: str) -> dict[str, SummaryStats]:
    buckets: dict[str, list[int]] = {}
    for sample in samples:
        counters = sample.get(field_name)
        if not isinstance(counters, Mapping):
            continue
        for name, value in counters.items():
            buckets.setdefault(str(name), []).append(int(value))
    return {name: ns_summary(values) for name, values in buckets.items()}


def summarize_optional_ns(samples: Sequence[Mapping[str, object]], field_name: str) -> SummaryStats | None:
    values = [
        int(value)
        for sample in samples
        if (value := sample.get(field_name)) is not None
    ]
    if not values:
        return None
    return ns_summary(values)


def summarize_perf_counter_meta(samples: Sequence[Mapping[str, object]]) -> dict[str, object]:
    metas = [
        meta if isinstance(meta, Mapping) else {}
        for sample in samples
        for meta in [sample.get("perf_counters_meta", {})]
    ]
    hardware_counter_names = (
        "cycles",
        "instructions",
        "branches",
        "branch_misses",
        "cache_references",
        "cache_misses",
    )
    software_counter_names = (
        "task_clock_ns",
        "context_switches",
        "cpu_migrations",
        "page_faults",
    )
    collected_samples = sum(1 for meta in metas if meta.get("collected"))
    errors: dict[str, int] = {}
    for meta in metas:
        error = str(meta.get("error", ""))
        if not error:
            continue
        errors[error] = errors.get(error, 0) + 1
    include_kernel = next((meta.get("include_kernel") for meta in metas if meta.get("collected")), None)
    scope = next((meta.get("scope") for meta in metas if meta.get("scope")), "full_repeat_raw")
    hardware_counters_observed = any(
        any(int(sample.get("perf_counters", {}).get(name, 0)) > 0 for name in hardware_counter_names)
        for sample in samples
    )
    software_counters_observed = any(
        any(int(sample.get("perf_counters", {}).get(name, 0)) > 0 for name in software_counter_names)
        for sample in samples
    )
    return {
        "requested": any(bool(meta.get("requested")) for meta in metas),
        "collected_samples": collected_samples,
        "include_kernel": include_kernel,
        "scope": scope,
        "hardware_counters_observed": hardware_counters_observed,
        "software_counters_observed": software_counters_observed,
        "errors": errors,
    }


def derive_perf_metrics(counter_summary: Mapping[str, Mapping[str, float | int | None]]) -> dict[str, float]:
    derived: dict[str, float] = {}

    def median_of(name: str) -> float | None:
        summary = counter_summary.get(name)
        if not summary:
            return None
        value = summary.get("median")
        if value is None:
            return None
        return float(value)

    cycles = median_of("cycles")
    instructions = median_of("instructions")
    branches = median_of("branches")
    branch_misses = median_of("branch_misses")
    cache_refs = median_of("cache_references")
    cache_misses = median_of("cache_misses")

    if cycles not in (None, 0.0) and instructions is not None:
        derived["ipc_median"] = instructions / cycles
    if branches not in (None, 0.0) and branch_misses is not None:
        derived["branch_miss_rate_median"] = branch_misses / branches
    if cache_refs not in (None, 0.0) and cache_misses is not None:
        derived["cache_miss_rate_median"] = cache_misses / cache_refs

    return derived


__all__ = [
    "CodeSizeSummary",
    "DirectiveScanSummary",
    "PerfCounterMeta",
    "RecompileSummary",
    "RunnerSample",
    "SummaryStats",
    "UnifiedResultRecord",
    "derive_perf_metrics",
    "float_summary",
    "geometric_mean",
    "load_json",
    "normalize_runner_sample",
    "ns_summary",
    "normalize_directive_scan",
    "parse_json_lines",
    "parse_last_json_line",
    "parse_runner_sample",
    "summarize_named_counters",
    "summarize_optional_ns",
    "summarize_per_benchmark_samples",
    "summarize_perf_counter_meta",
    "summarize_phase_timings",
    "zero_directive_scan",
]
