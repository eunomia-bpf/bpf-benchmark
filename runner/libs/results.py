from __future__ import annotations

import json
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
    for line_number, line in enumerate(stdout.splitlines(), start=1):
        text = line.strip()
        if not text or (not text.startswith("{") and not text.startswith("[")):
            continue
        try:
            payloads.append(json.loads(text))
        except json.JSONDecodeError as exc:
            raise RuntimeError(f"unable to parse JSON line {line_number}: {exc}: {text[:200]}") from exc
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
    "summarize_named_counters",
    "summarize_optional_ns",
    "summarize_perf_counter_meta",
    "summarize_phase_timings",
]
