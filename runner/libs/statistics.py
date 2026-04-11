from __future__ import annotations

import math
import statistics
from typing import Mapping, Sequence, TypedDict


class SummaryStats(TypedDict):
    count: int
    mean: float | int | None
    median: float | int | None
    min: float | int | None
    max: float | int | None
    p95: float | int | None
    stdev: float | int | None


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
