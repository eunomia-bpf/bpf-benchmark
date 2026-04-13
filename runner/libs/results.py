from __future__ import annotations

import json
from pathlib import Path
from typing import Any, TypedDict

from .statistics import (
    derive_perf_metrics,
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
