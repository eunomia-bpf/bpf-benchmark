from __future__ import annotations

from collections import Counter, defaultdict
import json
import statistics
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping, Sequence, TypedDict

from .statistics import (
    SummaryStats,
    derive_perf_metrics,
    float_summary,
    geometric_mean,
    ns_summary,
    summarize_named_counters,
    summarize_optional_ns,
    summarize_perf_counter_meta,
    summarize_phase_timings,
)


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


class RejitSummary(TypedDict, total=False):
    """Canonical rejit summary — output by C++ runner, consumed by all drivers."""
    requested: bool
    mode: str
    syscall_attempted: bool
    applied: bool
    insn_cnt: int
    error: str
    total_sites_applied: int
    passes_applied: list[str]
    pass_details: list[dict[str, Any]]
    insn_delta: int
    verifier_retries: int
    final_disabled_passes: list[str]
    daemon_response: dict


class RunnerSample(TypedDict, total=False):
    phase: str
    compile_ns: int
    exec_ns: int
    timing_source: str
    timing_source_wall: str
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
    rejit: RejitSummary


@dataclass(frozen=True, slots=True)
class UnifiedResultRecord:
    """Core schema shared by micro suite, corpus rejit, and rigorous drivers."""

    suite: str
    target: Mapping[str, object]
    backend: str
    policy_mode: str
    transport: str = "local"
    manifest: str | None = None
    host: Mapping[str, object] | None = None
    artifacts: Mapping[str, object] | None = None
    compile: Mapping[str, object] | None = None
    execution: Mapping[str, object] | None = None
    rejit: Mapping[str, object] | None = None
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


def parse_runner_samples(stdout: str) -> list[RunnerSample]:
    samples: list[RunnerSample] = []
    for payload in parse_json_lines(stdout):
        if isinstance(payload, dict):
            samples.append(normalize_runner_sample(payload))
    return samples


def collapse_command_samples(samples: Sequence[RunnerSample]) -> list[RunnerSample]:
    collapsed: list[RunnerSample] = []
    index = 0
    while index < len(samples):
        sample = samples[index]
        if (
            sample.get("phase") == "stock"
            and index + 1 < len(samples)
            and samples[index + 1].get("phase") == "rejit"
        ):
            collapsed.append(samples[index + 1])
            index += 2
            continue
        collapsed.append(sample)
        index += 1
    return collapsed


def parse_command_samples(stdout: str) -> list[RunnerSample]:
    return collapse_command_samples(parse_runner_samples(stdout))


def _normalize_phase_name(phase: object) -> object:
    if phase == ("re" "compile"):
        return "rejit"
    return phase


def _default_rejit() -> dict:
    """Default rejit summary with all canonical fields."""
    return {
        "requested": False,
        "mode": "none",
        "syscall_attempted": False,
        "applied": False,
        "insn_cnt": 0,
        "error": "",
        "total_sites_applied": 0,
        "passes_applied": [],
        "insn_delta": 0,
        "verifier_retries": 0,
        "final_disabled_passes": [],
    }


def normalize_runner_sample(sample: Mapping[str, object]) -> RunnerSample:
    normalized: RunnerSample = dict(sample)
    normalized_phase = _normalize_phase_name(sample.get("phase"))
    if normalized_phase is not None:
        normalized["phase"] = normalized_phase
    normalized.setdefault("timing_source_wall", "unavailable")
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

    raw_rejit = sample.get("rejit") or {}
    rejit_defaults = _default_rejit()
    rejit_defaults.update(raw_rejit)
    normalized["rejit"] = rejit_defaults

    return normalized


def parse_runner_sample(stdout: str) -> RunnerSample:
    samples = parse_runner_samples(stdout)
    if not samples:
        raise RuntimeError("runner sample payload was not a JSON object")
    return samples[-1]


def _invocation_failure_reason(record: Mapping[str, object] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample")
    if not isinstance(sample, Mapping):
        return "unknown"
    rejit = sample.get("rejit")
    if isinstance(rejit, Mapping) and rejit.get("error"):
        return str(rejit["error"])
    return "unknown"


def summarize_corpus_batch_results(
    program_records: Sequence[Mapping[str, Any]],
    object_records: Sequence[Mapping[str, Any]],
    *,
    effective_mode: str = "vm",
) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in program_records
        if record.get("baseline_compile")
        and record["baseline_compile"].get("ok")
        and record.get("rejit_compile")
        and record["rejit_compile"].get("ok")
    ]
    measured_pairs = [
        record
        for record in program_records
        if record.get("baseline_run")
        and record["baseline_run"].get("ok")
        and record.get("rejit_run")
        and record["rejit_run"].get("ok")
    ]
    applied_programs = [record for record in program_records if record.get("applied_passes")]
    compile_pass_counts: Counter[str] = Counter()
    run_pass_counts: Counter[str] = Counter()
    for record in program_records:
        compile_pass_counts.update(record.get("compile_passes_applied") or [])
        run_pass_counts.update(record.get("run_passes_applied") or [])

    failure_reasons: Counter[str] = Counter()
    rejit_failures: Counter[str] = Counter()
    for record in program_records:
        if record.get("record_error"):
            failure_reasons[str(record["record_error"])] += 1
            continue
        for key in ("baseline_compile", "rejit_compile", "baseline_run", "rejit_run"):
            raw = record.get(key)
            if raw and not raw.get("ok"):
                failure_reasons[_invocation_failure_reason(raw)] += 1
        for key in ("rejit_compile", "rejit_run"):
            raw = record.get(key)
            if raw and raw.get("ok"):
                sample = raw.get("sample") or {}
                rejit = sample.get("rejit") or {}
                if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                    rejit_failures[str(rejit["error"])] += 1

    size_ratios = [record["size_ratio"] for record in compile_pairs if record.get("size_ratio") is not None]
    exec_ratios = [record["speedup_ratio"] for record in measured_pairs if record.get("speedup_ratio") is not None]

    def aggregate_rows(grouped: Mapping[str, list[Mapping[str, Any]]], label_key: str) -> list[dict[str, Any]]:
        rows: list[dict[str, Any]] = []
        for label, items in grouped.items():
            grouped_compile = [item for item in items if item in compile_pairs]
            grouped_measured = [item for item in items if item in measured_pairs]
            rows.append(
                {
                    label_key: label,
                    "programs": len(items),
                    "compile_pairs": len(grouped_compile),
                    "measured_pairs": len(grouped_measured),
                    "applied_programs": sum(1 for item in items if item.get("applied_passes")),
                    "code_size_ratio_geomean": geometric_mean(
                        [item["size_ratio"] for item in grouped_compile if item.get("size_ratio") is not None]
                    ),
                    "exec_ratio_geomean": geometric_mean(
                        [item["speedup_ratio"] for item in grouped_measured if item.get("speedup_ratio") is not None]
                    ),
                }
            )
        rows.sort(key=lambda item: (-item["programs"], item[label_key]))
        return rows

    grouped_by_repo: dict[str, list[Mapping[str, Any]]] = defaultdict(list)
    grouped_by_object: dict[str, list[Mapping[str, Any]]] = defaultdict(list)
    for record in program_records:
        grouped_by_repo[str(record["repo"])].append(record)
        grouped_by_object[str(record["canonical_object_name"])].append(record)

    return {
        "effective_mode": effective_mode,
        "objects_attempted": len(object_records),
        "targets_attempted": len(program_records),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "applied_programs": len(applied_programs),
        "code_size_ratio_geomean": geometric_mean(size_ratios),
        "code_size_delta_median_pct": (
            statistics.median(
                [record["size_delta_pct"] for record in compile_pairs if record.get("size_delta_pct") is not None]
            )
            if compile_pairs
            else None
        ),
        "exec_ratio_geomean": geometric_mean(exec_ratios),
        "exec_ratio_median": statistics.median(exec_ratios) if exec_ratios else None,
        "exec_ratio_min": min(exec_ratios) if exec_ratios else None,
        "exec_ratio_max": max(exec_ratios) if exec_ratios else None,
        "pass_counts": dict(sorted((compile_pass_counts + run_pass_counts).items())),
        "compile_pass_counts": dict(sorted(compile_pass_counts.items())),
        "run_pass_counts": dict(sorted(run_pass_counts.items())),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "rejit_failure_reasons": dict(rejit_failures.most_common(16)),
        "by_repo": aggregate_rows(grouped_by_repo, "repo"),
        "by_object": aggregate_rows(grouped_by_object, "canonical_object_name"),
    }


__all__ = [
    "CodeSizeSummary",
    "PerfCounterMeta",
    "RejitSummary",
    "RunnerSample",
    "collapse_command_samples",
    "SummaryStats",
    "UnifiedResultRecord",
    "derive_perf_metrics",
    "float_summary",
    "geometric_mean",
    "load_json",
    "normalize_runner_sample",
    "ns_summary",
    "parse_json_lines",
    "parse_last_json_line",
    "parse_command_samples",
    "parse_runner_sample",
    "parse_runner_samples",
    "summarize_corpus_batch_results",
    "summarize_named_counters",
    "summarize_optional_ns",
    "summarize_perf_counter_meta",
    "summarize_phase_timings",
]
