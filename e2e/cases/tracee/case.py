from __future__ import annotations

import argparse
import itertools
import math
import random
import socket
import statistics
import sys
import tempfile
import threading
import time
import uuid
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import run_command, tail_text  # noqa: E402
from runner.libs.app_runners.tracee import (  # noqa: E402
    TraceeOutputCollector,
    TraceeRunner,
    build_tracee_commands,
    inspect_tracee_setup,
    resolve_tracee_binary,
    run_tracee_workload,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    sample_cpu_usage,
    sample_total_cpu_usage,
    start_sampler_thread,
)
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    LifecycleAbort,
    host_metadata,
    percentile,
    summarize_numbers,
    percent_delta,
    run_case_lifecycle,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SAMPLE_COUNT = 5
DEFAULT_SMOKE_SAMPLE_COUNT = 2
DEFAULT_WARMUP_DURATION_S = 5
DEFAULT_SMOKE_WARMUP_DURATION_S = 2
DEFAULT_LATENCY_PROBE_COUNT = 8
DEFAULT_SMOKE_LATENCY_PROBE_COUNT = 3
DEFAULT_LATENCY_PROBE_TIMEOUT_S = 5.0
DEFAULT_LOAD_TIMEOUT_S = 120
DEFAULT_LATENCY_PROBE_ATTEMPTS = 3
DEFAULT_BOOTSTRAP_ITERATIONS = 2000
DEFAULT_BOOTSTRAP_SEED = 20260328
def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def load_config(path: Path) -> dict[str, object]:
    payload = yaml.safe_load(path.read_text())
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid config payload in {path}")
    return payload


def _filtered_float_values(values: Sequence[float | int | None]) -> list[float]:
    filtered: list[float] = []
    for value in values:
        if value is None:
            continue
        numeric = float(value)
        if math.isnan(numeric):
            continue
        filtered.append(numeric)
    return filtered


def bootstrap_mean_ci(
    values: Sequence[float | int | None],
    *,
    iterations: int,
    seed: int,
) -> dict[str, float] | None:
    filtered = _filtered_float_values(values)
    if not filtered:
        return None
    if len(filtered) == 1:
        return {"low": filtered[0], "high": filtered[0]}
    rng = random.Random(seed)
    samples: list[float] = []
    for _ in range(max(1, int(iterations))):
        resample = [filtered[rng.randrange(len(filtered))] for _ in range(len(filtered))]
        samples.append(float(statistics.mean(resample)))
    samples.sort()
    low = percentile(samples, 2.5)
    high = percentile(samples, 97.5)
    if low is None or high is None:
        return None
    return {"low": float(low), "high": float(high)}


def summarize_numeric_distribution(
    values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, float | int | dict[str, float] | None]:
    filtered = _filtered_float_values(values)
    summary = dict(summarize_numbers(filtered))
    summary["stdev"] = statistics.stdev(filtered) if len(filtered) > 1 else (0.0 if filtered else None)
    summary["p95"] = percentile(filtered, 95) if filtered else None
    summary["p99"] = percentile(filtered, 99) if filtered else None
    summary["mean_ci95"] = bootstrap_mean_ci(filtered, iterations=ci_iterations, seed=ci_seed)
    return summary


def exact_paired_permutation_pvalue(before_values: Sequence[float | int | None], after_values: Sequence[float | int | None]) -> float | None:
    deltas = [
        float(after) - float(before)
        for before, after in zip(before_values, after_values)
        if before is not None and after is not None
    ]
    non_zero_deltas = [delta for delta in deltas if abs(delta) > 1e-12]
    if not non_zero_deltas:
        return None

    observed = abs(sum(non_zero_deltas))
    if len(non_zero_deltas) <= 14:
        total = 0
        extreme = 0
        for signs in itertools.product((-1.0, 1.0), repeat=len(non_zero_deltas)):
            total += 1
            candidate = abs(sum(sign * delta for sign, delta in zip(signs, non_zero_deltas)))
            if candidate >= observed - 1e-12:
                extreme += 1
        return extreme / total if total > 0 else None

    rng = random.Random(DEFAULT_BOOTSTRAP_SEED + len(non_zero_deltas))
    total = 20000
    extreme = 0
    for _ in range(total):
        candidate = abs(sum((1.0 if rng.random() >= 0.5 else -1.0) * delta for delta in non_zero_deltas))
        if candidate >= observed - 1e-12:
            extreme += 1
    return extreme / total


def paired_metric_report(
    before_values: Sequence[float | int | None],
    after_values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    before_filtered = _filtered_float_values(before_values)
    after_filtered = _filtered_float_values(after_values)
    paired = [
        (float(before), float(after))
        for before, after in zip(before_values, after_values)
        if before is not None and after is not None
    ]
    deltas = [after - before for before, after in paired]
    pct_deltas = [((after - before) / before) * 100.0 for before, after in paired if before != 0.0]
    p_value = exact_paired_permutation_pvalue([pair[0] for pair in paired], [pair[1] for pair in paired])
    return {
        "pairs": len(paired),
        "before": summarize_numeric_distribution(before_filtered, ci_iterations=ci_iterations, ci_seed=ci_seed),
        "after": summarize_numeric_distribution(after_filtered, ci_iterations=ci_iterations, ci_seed=ci_seed + 1),
        "delta": summarize_numeric_distribution(deltas, ci_iterations=ci_iterations, ci_seed=ci_seed + 2),
        "pct_delta": summarize_numeric_distribution(pct_deltas, ci_iterations=ci_iterations, ci_seed=ci_seed + 3),
        "p_value": p_value,
        "significant": p_value is not None and p_value <= 0.05,
    }


def summarize_latency_values(
    values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    summary = summarize_numeric_distribution(values, ci_iterations=ci_iterations, ci_seed=ci_seed)
    summary["p50"] = summary.get("median")
    return summary


def application_overhead_pct(control_value: float | int | None, observed_value: float | int | None) -> float | None:
    if control_value in (None, 0) or observed_value is None:
        return None
    return ((float(control_value) - float(observed_value)) / float(control_value)) * 100.0


def latency_probe_kind(spec: Mapping[str, object]) -> str:
    configured = str(spec.get("latency_probe_kind") or "").strip()
    if configured:
        return configured
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind == "tracee_default":
        return "exec"
    if kind in {"file_io", "file_open", "open_storm"}:
        return "file_open"
    if kind in {"network", "connect_storm"}:
        return "tcp_connect"
    return "exec"


def warmup_workload(spec: Mapping[str, object], duration_s: int | float) -> dict[str, object] | None:
    if float(duration_s) <= 0.0:
        return None
    result = run_tracee_workload(spec, max(1, int(duration_s)))
    return {
        "ops_total": result.ops_total,
        "ops_per_sec": result.ops_per_sec,
        "duration_s": result.duration_s,
        "stdout_tail": result.stdout,
        "stderr_tail": result.stderr,
    }


def _emit_exec_latency_probe() -> dict[str, object]:
    marker = f"tracee-exec-probe-{uuid.uuid4().hex}"
    with tempfile.TemporaryDirectory(prefix=f"{marker}-") as tempdir:
        script_path = Path(tempdir) / marker
        script_path.write_text("#!/bin/sh\nexit 0\n")
        script_path.chmod(0o755)
        started_wall_ns = time.time_ns()
        started_ns = time.monotonic_ns()
        completed = run_command([str(script_path)], check=False, timeout=5)
        probe_window_ns = time.monotonic_ns() - started_ns
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"exec latency probe failed: {details}")
    return {
        "marker": marker,
        "marker_tokens": [marker],
        "started_ns": started_ns,
        "started_wall_ns": started_wall_ns,
        "probe_window_ns": probe_window_ns,
    }


def _emit_file_open_latency_probe() -> dict[str, object]:
    marker = f"tracee-open-probe-{uuid.uuid4().hex}"
    with tempfile.NamedTemporaryFile(prefix=f"{marker}-", delete=False) as handle:
        probe_path = Path(handle.name)
        handle.write(b"tracee-probe\n")
    try:
        started_wall_ns = time.time_ns()
        started_ns = time.monotonic_ns()
        with probe_path.open("rb") as handle:
            handle.read(1)
        probe_window_ns = time.monotonic_ns() - started_ns
    finally:
        probe_path.unlink(missing_ok=True)
    return {
        "marker": marker,
        "marker_tokens": [marker],
        "started_ns": started_ns,
        "started_wall_ns": started_wall_ns,
        "probe_window_ns": probe_window_ns,
    }


def _emit_tcp_connect_latency_probe() -> dict[str, object]:
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(("127.0.0.1", 0))
    listener.listen(1)
    port = int(listener.getsockname()[1])
    accepted: dict[str, object] = {"error": None}

    def accept_once() -> None:
        try:
            conn, _ = listener.accept()
            conn.close()
        except OSError as exc:
            accepted["error"] = str(exc)

    thread = threading.Thread(target=accept_once, daemon=True)
    thread.start()
    try:
        started_wall_ns = time.time_ns()
        started_ns = time.monotonic_ns()
        with socket.create_connection(("127.0.0.1", port), timeout=2.0):
            pass
        probe_window_ns = time.monotonic_ns() - started_ns
    finally:
        listener.close()
        thread.join(timeout=1.0)
    if accepted["error"] is not None:
        raise RuntimeError(f"tcp connect latency probe failed: {accepted['error']}")
    return {
        "marker": str(port),
        "marker_tokens": ["127.0.0.1", str(port)],
        "started_ns": started_ns,
        "started_wall_ns": started_wall_ns,
        "probe_window_ns": probe_window_ns,
    }


def emit_latency_probe(spec: Mapping[str, object]) -> dict[str, object]:
    probe_kind = latency_probe_kind(spec)
    if probe_kind == "file_open":
        return _emit_file_open_latency_probe()
    if probe_kind == "tcp_connect":
        return _emit_tcp_connect_latency_probe()
    return _emit_exec_latency_probe()


def measure_latency_probes(
    workload_spec: Mapping[str, object],
    *,
    collector: TraceeOutputCollector,
    probe_count: int,
    timeout_s: float,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    def probe_latency_ms(emitted: Mapping[str, object], matched: Mapping[str, object]) -> float:
        event_time_ns = int(matched.get("event_time_ns", 0) or 0)
        started_wall_ns = int(emitted.get("started_wall_ns", 0) or 0)
        if event_time_ns > 0 and started_wall_ns > 0:
            return max(0.0, (event_time_ns - started_wall_ns) / 1_000_000.0)
        return max(
            0.0,
            (int(matched.get("observed_monotonic_ns", 0) or 0) - int(emitted["started_ns"])) / 1_000_000.0,
        )

    probe_rows: list[dict[str, object]] = []
    for probe_index in range(max(0, int(probe_count))):
        missed_attempts: list[dict[str, object]] = []
        emitted: dict[str, object] | None = None
        matched: dict[str, object] | None = None
        matched_attempt = 0
        for attempt in range(DEFAULT_LATENCY_PROBE_ATTEMPTS):
            emitted = emit_latency_probe(workload_spec)
            matched = collector.wait_for_event(
                marker_tokens=emitted["marker_tokens"],
                min_observed_ns=int(emitted["started_ns"]),
                timeout_s=timeout_s,
            )
            if matched is not None:
                matched_attempt = attempt
                break
            missed_attempts.append(
                {
                    "attempt": attempt,
                    "marker": emitted["marker"],
                    "marker_tokens": emitted["marker_tokens"],
                }
            )
            time.sleep(0.1)
        if matched is None:
            raise RuntimeError(
                f"Tracee latency probe was not detected for workload {workload_spec.get('name')}: "
                f"tokens={emitted['marker_tokens'] if emitted is not None else []}, "
                f"attempts={missed_attempts}"
            )
        assert emitted is not None
        latency_ms = probe_latency_ms(emitted, matched)
        probe_rows.append(
            {
                "index": probe_index,
                "attempt": matched_attempt,
                "event_name": matched["event_name"],
                "marker": emitted["marker"],
                "marker_tokens": emitted["marker_tokens"],
                "latency_ms": latency_ms,
                "match_source": str(matched.get("source") or "collector"),
                "missed_attempts": missed_attempts,
                "probe_window_ms": float(emitted["probe_window_ns"]) / 1_000_000.0,
            }
        )
    return {
        "probe_count": len(probe_rows),
        "probe_timeout_s": timeout_s,
        "probes": probe_rows,
        "summary": summarize_latency_values(
            [row["latency_ms"] for row in probe_rows],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed,
        ),
    }


def verify_phase_measurement(record: Mapping[str, object]) -> None:
    if int(record.get("event_parse_errors", 0) or 0) > 0:
        raise RuntimeError(
            f"{record.get('name')} encountered malformed Tracee event-file lines: "
            f"{record.get('event_parse_errors')}"
        )
    if int(record.get("events_total", 0) or 0) <= 0:
        raise RuntimeError(f"{record.get('name')} produced zero Tracee events")
    drops = record.get("drop_counters") or {}
    if int(drops.get("lost_event_count", 0) or 0) > 0 or int(drops.get("lost_write_count", 0) or 0) > 0:
        raise RuntimeError(f"{record.get('name')} lost Tracee events: {drops}")
    bpf_summary = (record.get("bpf") or {}).get("summary") or {}
    if int(bpf_summary.get("total_events", 0) or 0) <= 0:
        raise RuntimeError(f"{record.get('name')} produced zero Tracee BPF runtime events: {bpf_summary}")


def measure_workload(
    runner: TraceeRunner | None,
    workload_spec: Mapping[str, object],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
    phase_name: str,
    control_throughput: float | int | None,
    latency_probe: Mapping[str, object] | None,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    before_tracee = collector.snapshot() if collector is not None else None
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    sampler_errors: list[str] = []
    threads: list[threading.Thread] = []

    if agent_pid is not None:
        cpu_thread = start_sampler_thread(
            label=f"agent cpu pid={agent_pid}",
            errors=sampler_errors,
            target=lambda: cpu_holder.update(sample_cpu_usage([agent_pid], duration_s)),
        )
        threads.append(cpu_thread)

    system_thread = start_sampler_thread(
        label="system cpu",
        errors=sampler_errors,
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
    )
    threads.append(system_thread)

    if runner is None:
        workload_result = run_tracee_workload(workload_spec, duration_s)
    else:
        workload_result = runner.run_workload_spec(workload_spec, duration_s)

    for thread in threads:
        thread.join()
    if sampler_errors:
        raise RuntimeError("; ".join(sampler_errors))
    if not system_cpu_holder:
        raise RuntimeError("system cpu sampler produced no data")
    if agent_pid is not None and agent_pid not in cpu_holder:
        raise RuntimeError(f"agent cpu sampler produced no data for pid={agent_pid}")

    after_bpf = sample_bpf_stats(prog_ids)
    after_tracee = collector.snapshot() if collector is not None else None
    bpf_delta = compute_delta(before_bpf, after_bpf)

    if before_tracee is not None and after_tracee is not None:
        before_counts = Counter(before_tracee.get("event_counts") or {})
        after_counts = Counter(after_tracee.get("event_counts") or {})
        event_counts = {
            event_name: int(after_counts.get(event_name, 0) - before_counts.get(event_name, 0))
            for event_name in sorted(set(before_counts) | set(after_counts))
        }
        before_stats = before_tracee.get("latest_stats") or {}
        after_stats = after_tracee.get("latest_stats") or {}
        drop_counters = {
            field: int(after_stats.get(field, 0)) - int(before_stats.get(field, 0))
            for field in ("event_count", "lost_event_count", "lost_write_count")
        }
        event_parse_errors = (
            int(after_tracee.get("event_parse_error_count", 0) or 0)
            - int(before_tracee.get("event_parse_error_count", 0) or 0)
        )
        total_events = int(after_tracee.get("total_events", 0)) - int(before_tracee.get("total_events", 0))
    else:
        event_counts = {}
        drop_counters = {}
        event_parse_errors = 0
        total_events = None

    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_cpu_total = None
    if agent_cpu is not None:
        agent_cpu_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    overhead_pct = 0.0 if phase_name == "control" else application_overhead_pct(control_throughput, workload_result.ops_per_sec)
    return {
        "cycle_index": cycle_index,
        "phase": phase_name,
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "command_template": str(workload_spec.get("command", "")),
        "control_app_throughput": control_throughput,
        "application_overhead_pct": overhead_pct,
        "app_throughput": workload_result.ops_per_sec,
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "events_total": total_events,
        "events_per_sec": (
            (float(total_events) / workload_result.duration_s)
            if total_events is not None and workload_result.duration_s > 0
            else None
        ),
        "events_per_op": (
            (float(total_events) / float(workload_result.ops_total))
            if total_events is not None and workload_result.ops_total > 0
            else None
        ),
        "event_counts": event_counts,
        "drop_counters": drop_counters,
        "event_parse_errors": event_parse_errors,
        "event_parse_error_samples": (
            list(after_tracee.get("event_parse_error_samples") or [])
            if after_tracee is not None
            else []
        ),
        "latency_probe": None if latency_probe is None else dict(latency_probe),
        "latency_ms": None if latency_probe is None else dict(latency_probe.get("summary") or {}),
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_cpu_total,
        },
        "system_cpu": system_cpu_holder,
        "bpf": bpf_delta,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
}


def summarize_phase(
    workloads: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    return {
        "app_throughput": summarize_numeric_distribution(
            [record.get("app_throughput") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed,
        ),
        "events_per_sec": summarize_numeric_distribution(
            [record.get("events_per_sec") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 1,
        ),
        "application_overhead_pct": summarize_numeric_distribution(
            [record.get("application_overhead_pct") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 2,
        ),
        "agent_cpu_total_pct": summarize_numeric_distribution(
            [
                ((record.get("agent_cpu") or {}).get("total_pct") if isinstance(record.get("agent_cpu"), Mapping) else None)
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 3,
        ),
        "system_cpu_busy_pct": summarize_numeric_distribution(
            [
                ((record.get("system_cpu") or {}).get("busy_pct") if isinstance(record.get("system_cpu"), Mapping) else None)
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 4,
        ),
        "bpf_avg_ns_per_run": summarize_numeric_distribution(
            [
                ((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run"))
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 5,
        ),
        "detection_latency_ms_p99": summarize_numeric_distribution(
            [
                ((record.get("latency_ms") or {}).get("p99"))
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 6,
        ),
    }


def phase_records(phase: Mapping[str, object]) -> list[Mapping[str, object]]:
    samples = phase.get("samples")
    if isinstance(samples, list):
        return [record for record in samples if isinstance(record, Mapping)]
    workloads = phase.get("workloads")
    if isinstance(workloads, list):
        return [record for record in workloads if isinstance(record, Mapping)]
    return []


def summarize_workload_samples(
    samples: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> list[dict[str, object]]:
    groups: dict[str, list[Mapping[str, object]]] = {}
    for sample in samples:
        groups.setdefault(str(sample.get("name") or "unknown"), []).append(sample)

    rows: list[dict[str, object]] = []
    for index, name in enumerate(sorted(groups)):
        records = groups[name]
        rows.append(
            {
                "name": name,
                "kind": str(records[0].get("kind", "")),
                "metric": str(records[0].get("metric", "ops/s")),
                "sample_count": len(records),
                "app_throughput": summarize_numeric_distribution(
                    [record.get("app_throughput") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20),
                ),
                "events_per_sec": summarize_numeric_distribution(
                    [record.get("events_per_sec") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 1,
                ),
                "application_overhead_pct": summarize_numeric_distribution(
                    [record.get("application_overhead_pct") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 2,
                ),
                "detection_latency_ms_mean": summarize_numeric_distribution(
                    [((record.get("latency_ms") or {}).get("mean")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 3,
                ),
                "detection_latency_ms_p99": summarize_numeric_distribution(
                    [((record.get("latency_ms") or {}).get("p99")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 4,
                ),
                "agent_cpu_total_pct": summarize_numeric_distribution(
                    [((record.get("agent_cpu") or {}).get("total_pct")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 5,
                ),
                "system_cpu_busy_pct": summarize_numeric_distribution(
                    [((record.get("system_cpu") or {}).get("busy_pct")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 6,
                ),
                "bpf_avg_ns_per_run": summarize_numeric_distribution(
                    [((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 7,
                ),
                "lost_event_count": summarize_numeric_distribution(
                    [((record.get("drop_counters") or {}).get("lost_event_count")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 8,
                ),
                "correctness": {
                    "samples": len(records),
                    "all_zero_drops": all(
                        int(((record.get("drop_counters") or {}).get("lost_event_count", 0) or 0)) == 0
                        and int(((record.get("drop_counters") or {}).get("lost_write_count", 0) or 0)) == 0
                        for record in records
                    ),
                    "all_latency_probes_detected": all(
                        record.get("phase") == "control"
                        or int(((record.get("latency_probe") or {}).get("probe_count", 0) or 0)) > 0
                        for record in records
                    ),
                },
            }
        )
    return rows


def attach_control_phase_metrics(
    phase: Mapping[str, object],
    control_records: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    phase_copy = dict(phase)
    records = [dict(record) for record in (phase.get("workloads") or []) if isinstance(record, Mapping)]
    if str(phase.get("phase", "")) == "control":
        phase_copy["workloads"] = records
        phase_copy["summary"] = summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed)
        return phase_copy
    control_sequence = [record for record in control_records if isinstance(record, Mapping)]
    control_by_name: dict[str, Mapping[str, object]] = {}
    for record in control_sequence:
        for key in (record.get("name"), record.get("kind")):
            if key is None:
                continue
            control_by_name[str(key)] = record
    for index, record in enumerate(records):
        control_record = control_by_name.get(str(record.get("name") or record.get("kind") or ""))
        if control_record is None and index < len(control_sequence):
            control_record = control_sequence[index]
        control_throughput = None if control_record is None else control_record.get("app_throughput")
        record["control_app_throughput"] = control_throughput
        record["application_overhead_pct"] = application_overhead_pct(control_throughput, record.get("app_throughput"))
    phase_copy["workloads"] = records
    phase_copy["summary"] = summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed)
    return phase_copy


def aggregate_phase_samples(
    phase_name: str,
    samples: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    return {
        "phase": phase_name,
        "samples": [dict(sample) for sample in samples],
        "workloads": summarize_workload_samples(samples, ci_iterations=ci_iterations, ci_seed=ci_seed),
        "summary": summarize_phase(samples, ci_iterations=ci_iterations, ci_seed=ci_seed + 1000),
    }


def aggregate_programs(phase: Mapping[str, object]) -> dict[str, dict[str, object]]:
    aggregated: dict[str, dict[str, object]] = {}
    for workload in phase_records(phase):
        programs = ((workload.get("bpf") or {}).get("programs") or {})
        for prog_id, record in programs.items():
            key = str(prog_id)
            target = aggregated.setdefault(
                key,
                {
                    "id": int(record.get("id", prog_id)),
                    "name": str(record.get("name", f"id-{prog_id}")),
                    "run_cnt_delta": 0,
                    "run_time_ns_delta": 0,
                },
            )
            target["run_cnt_delta"] += int(record.get("run_cnt_delta", 0) or 0)
            target["run_time_ns_delta"] += int(record.get("run_time_ns_delta", 0) or 0)
    for record in aggregated.values():
        run_cnt = int(record["run_cnt_delta"])
        run_time = int(record["run_time_ns_delta"])
        record["avg_ns_per_run"] = (run_time / run_cnt) if run_cnt > 0 else None
    return aggregated


def summarize_program_activity(
    phase: Mapping[str, object],
    prog_ids: Sequence[int],
) -> dict[str, object]:
    aggregated = aggregate_programs(phase)
    rows: list[dict[str, object]] = []
    total_run_cnt = 0
    total_run_time_ns = 0
    for prog_id in [int(value) for value in prog_ids if int(value) > 0]:
        record = aggregated.get(str(prog_id), {})
        run_cnt = int(record.get("run_cnt_delta", 0) or 0)
        run_time_ns = int(record.get("run_time_ns_delta", 0) or 0)
        total_run_cnt += run_cnt
        total_run_time_ns += run_time_ns
        rows.append(
            {
                "id": prog_id,
                "name": str(record.get("name") or f"id-{prog_id}"),
                "run_cnt_delta": run_cnt,
                "run_time_ns_delta": run_time_ns,
                "avg_ns_per_run": (run_time_ns / run_cnt) if run_cnt > 0 else None,
            }
        )
    return {
        "programs": rows,
        "total_run_cnt": total_run_cnt,
        "total_run_time_ns": total_run_time_ns,
        "avg_ns_per_run": (total_run_time_ns / total_run_cnt) if total_run_cnt > 0 else None,
    }


def _phase_samples_by_workload_and_cycle(phase: Mapping[str, object]) -> dict[str, dict[int, Mapping[str, object]]]:
    grouped: dict[str, dict[int, Mapping[str, object]]] = {}
    for sample in phase_records(phase):
        grouped.setdefault(str(sample.get("name") or "unknown"), {})[int(sample.get("cycle_index", -1) or -1)] = sample
    return grouped


def compare_phases(
    baseline: Mapping[str, object],
    post: Mapping[str, object] | None,
    *,
    control: Mapping[str, object] | None = None,
    ci_iterations: int = DEFAULT_BOOTSTRAP_ITERATIONS,
    ci_seed: int = DEFAULT_BOOTSTRAP_SEED,
) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "post-ReJIT phase is missing"}

    baseline_by_name = _phase_samples_by_workload_and_cycle(baseline)
    post_by_name = _phase_samples_by_workload_and_cycle(post)
    control_by_name = _phase_samples_by_workload_and_cycle(control or {})
    workload_rows: list[dict[str, object]] = []
    for index, name in enumerate(sorted(set(baseline_by_name) & set(post_by_name))):
        common_cycles = sorted(set(baseline_by_name[name]) & set(post_by_name[name]))
        if not common_cycles:
            continue
        before_samples = [baseline_by_name[name][cycle] for cycle in common_cycles]
        after_samples = [post_by_name[name][cycle] for cycle in common_cycles]
        control_samples = [control_by_name.get(name, {}).get(cycle) for cycle in common_cycles]
        workload_rows.append(
            {
                "name": name,
                "pairs": len(common_cycles),
                "cycles": common_cycles,
                "control_app_throughput": summarize_numeric_distribution(
                    [None if sample is None else sample.get("app_throughput") for sample in control_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50),
                ),
                "app_throughput": paired_metric_report(
                    [sample.get("app_throughput") for sample in before_samples],
                    [sample.get("app_throughput") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 1,
                ),
                "events_per_sec": paired_metric_report(
                    [sample.get("events_per_sec") for sample in before_samples],
                    [sample.get("events_per_sec") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 2,
                ),
                "detection_latency_ms_p99": paired_metric_report(
                    [((sample.get("latency_ms") or {}).get("p99")) for sample in before_samples],
                    [((sample.get("latency_ms") or {}).get("p99")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 3,
                ),
                "application_overhead_pct": paired_metric_report(
                    [sample.get("application_overhead_pct") for sample in before_samples],
                    [sample.get("application_overhead_pct") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 4,
                ),
                "agent_cpu_total_pct": paired_metric_report(
                    [((sample.get("agent_cpu") or {}).get("total_pct")) for sample in before_samples],
                    [((sample.get("agent_cpu") or {}).get("total_pct")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 5,
                ),
                "bpf_avg_ns_per_run": paired_metric_report(
                    [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in before_samples],
                    [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 6,
                ),
                "lost_event_count": paired_metric_report(
                    [((sample.get("drop_counters") or {}).get("lost_event_count")) for sample in before_samples],
                    [((sample.get("drop_counters") or {}).get("lost_event_count")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 7,
                ),
            }
        )

    baseline_programs = aggregate_programs(baseline)
    post_programs = aggregate_programs(post)
    program_rows: list[dict[str, object]] = []
    for prog_id in sorted(set(baseline_programs) | set(post_programs), key=int):
        before = baseline_programs.get(prog_id, {})
        after = post_programs.get(prog_id, {})
        program_rows.append(
            {
                "id": int(prog_id),
                "name": str(after.get("name") or before.get("name") or f"id-{prog_id}"),
                "baseline_avg_ns_per_run": before.get("avg_ns_per_run"),
                "post_avg_ns_per_run": after.get("avg_ns_per_run"),
                "delta_pct": percent_delta(before.get("avg_ns_per_run"), after.get("avg_ns_per_run")),
            }
        )

    return {
        "comparable": True,
        "workloads": workload_rows,
        "programs": program_rows,
    }


def append_preflight_markdown(lines: list[str], preflight: Mapping[str, object]) -> None:
    lines.extend(["## Preflight", ""])
    activity = preflight.get("program_activity") if isinstance(preflight.get("program_activity"), Mapping) else {}
    program_activity = activity.get("programs") if isinstance(activity, Mapping) else None
    for workload in phase_records(preflight):
        details = [
            f"events/s={workload.get('events_per_sec')}",
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}",
        ]
        if isinstance(program_activity, Mapping):
            details.append(f"program_runs={program_activity.get('total_run_cnt')}")
        lines.append(f"- {workload['name']}: " + ", ".join(details))
    lines.append("")


def _summary_mean(summary: Mapping[str, object] | None) -> object:
    return None if summary is None else summary.get("mean")


def _summary_ci(summary: Mapping[str, object] | None) -> str:
    if summary is None:
        return "n/a"
    ci = summary.get("mean_ci95")
    if not isinstance(ci, Mapping):
        return "n/a"
    return f"[{ci.get('low')}, {ci.get('high')}]"


def _paired_delta_mean(report: Mapping[str, object] | None) -> object:
    if report is None:
        return None
    delta = report.get("pct_delta")
    if not isinstance(delta, Mapping):
        return None
    return delta.get("mean")


def build_markdown(payload: Mapping[str, object]) -> str:
    preflight = payload.get("preflight")
    lines = [
        "# Tracee Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Warmup per workload: `{payload.get('warmup_duration_s')}s`",
        f"- Paired cycles: `{payload.get('sample_count')}`",
        f"- Latency probes per phase: `{payload.get('latency_probe_count')}`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Tracee binary: `{payload.get('tracee_binary') or 'unavailable'}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{payload['setup']['returncode']}`",
        f"- Setup tracee binary: `{payload['setup'].get('tracee_binary') or 'missing'}`",
        "",
    ]
    status = str(payload.get("status") or "")
    if status != "ok":
        result_reason = payload.get("error_message") or "unknown"
        lines.extend(
            [
                "## Result",
                "",
                "- Status: `ERROR`",
                f"- Reason: `{result_reason}`",
            ]
        )
        if isinstance(preflight, Mapping):
            lines.append("")
            append_preflight_markdown(lines, preflight)
        limitations = payload.get("limitations") or []
        if limitations:
            lines.extend(["", "## Limitations", ""])
            for limitation in limitations:
                lines.append(f"- {limitation}")
        lines.append("")
        return "\n".join(lines)

    if isinstance(preflight, Mapping):
        append_preflight_markdown(lines, preflight)

    control = payload.get("control")
    if isinstance(control, Mapping):
        lines.extend(["## Control", ""])
        for workload in control.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
                f"app_ci95={_summary_ci(workload.get('app_throughput'))}"
            )
        lines.append("")

    lines.extend(["## Baseline", ""])
    baseline = payload["baseline"]
    for workload in baseline.get("workloads") or []:
        lines.append(
            f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
            f"events_mean={_summary_mean(workload.get('events_per_sec'))}/s, "
            f"latency_p99_mean={_summary_mean(workload.get('detection_latency_ms_p99'))} ms, "
            f"overhead_mean={_summary_mean(workload.get('application_overhead_pct'))}%, "
            f"bpf_avg_ns_mean={_summary_mean(workload.get('bpf_avg_ns_per_run'))}"
        )
    lines.append("")
    post = payload.get("post_rejit")
    if post:
        lines.extend(["## Post-ReJIT", ""])
        for workload in post.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
                f"events_mean={_summary_mean(workload.get('events_per_sec'))}/s, "
                f"latency_p99_mean={_summary_mean(workload.get('detection_latency_ms_p99'))} ms, "
                f"overhead_mean={_summary_mean(workload.get('application_overhead_pct'))}%, "
                f"bpf_avg_ns_mean={_summary_mean(workload.get('bpf_avg_ns_per_run'))}"
            )
        lines.append("")
    comparison = payload.get("comparison") or {}
    lines.extend(["## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads", []):
            lines.append(
                f"- {workload['name']}: "
                f"app_delta_mean={_paired_delta_mean(workload.get('app_throughput'))}%, "
                f"event_delta_mean={_paired_delta_mean(workload.get('events_per_sec'))}%, "
                f"overhead_delta_mean={_paired_delta_mean(workload.get('application_overhead_pct'))}%, "
                f"latency_p99_delta_mean={_paired_delta_mean(workload.get('detection_latency_ms_p99'))}%, "
                f"app_p={workload.get('app_throughput', {}).get('p_value')}, "
                f"overhead_p={workload.get('application_overhead_pct', {}).get('p_value')}"
            )
    else:
        lines.append("- Comparable: `False`")
        lines.append(f"- Reason: `{comparison.get('reason', 'unknown')}`")
    limitations = payload.get("limitations") or []
    if limitations:
        lines.extend(["", "## Limitations", ""])
        for limitation in limitations:
            lines.append(f"- {limitation}")
    lines.append("")
    return "\n".join(lines)


def run_phase(
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
    phase_name: str,
    warmup_duration_s: int | float,
    latency_probe_count: int,
    latency_probe_timeout_s: float,
    ci_iterations: int,
    ci_seed: int,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
    runner: TraceeRunner | None = None,
    control_records: Sequence[Mapping[str, object]] | None = None,
) -> dict[str, object]:
    del control_records
    records: list[dict[str, object]] = []
    for index, workload_spec in enumerate(workloads):
        warmup = warmup_workload(workload_spec, warmup_duration_s)
        latency_probe = None
        if collector is not None and phase_name != "control" and latency_probe_count > 0:
            latency_probe = measure_latency_probes(
                workload_spec,
                collector=collector,
                probe_count=latency_probe_count,
                timeout_s=latency_probe_timeout_s,
                ci_iterations=ci_iterations,
                ci_seed=ci_seed + (index * 10),
            )
        record = measure_workload(
            runner,
            workload_spec,
            duration_s,
            prog_ids,
            cycle_index=cycle_index,
            phase_name=phase_name,
            control_throughput=None,
            latency_probe=latency_probe,
            agent_pid=agent_pid,
            collector=collector,
        )
        record["warmup"] = warmup
        if phase_name != "control":
            verify_phase_measurement(record)
        records.append(record)
    return {
        "phase": phase_name,
        "cycle_index": cycle_index,
        "workloads": records,
        "summary": summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed + 1000),
    }


def error_payload(
    *,
    config: Mapping[str, object],
    duration_s: int,
    tracee_binary: str | None,
    setup_result: Mapping[str, object],
    smoke: bool,
    error_message: str,
    limitations: Sequence[str],
    preflight: Mapping[str, object] | None = None,
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error",
        "mode": "error",
        "error_message": error_message,
        "smoke": smoke,
        "duration_s": duration_s,
        "tracee_binary": tracee_binary,
        "tracee_programs": [],
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "preflight": None if preflight is None else dict(preflight),
        "control": None,
        "baseline": None,
        "paired_cycles": [],
        "scan_results": {},
        "rejit_result": None,
        "post_rejit": None,
        "comparison": {"comparable": False, "reason": error_message},
        "limitations": list(limitations),
    }


def run_tracee_case(args: argparse.Namespace) -> dict[str, object]:
    config = load_config(Path(getattr(args, "config", DEFAULT_CONFIG)).resolve())
    duration_override = int(getattr(args, "duration", 0) or 0)
    duration_s = int(duration_override or config.get("measurement_duration_s") or 20)
    if args.smoke and not duration_override:
        duration_s = int(config.get("smoke_duration_s") or 8)
    sample_count_value = config.get("smoke_sample_count") if args.smoke else config.get("sample_count")
    sample_count = int(sample_count_value or (DEFAULT_SMOKE_SAMPLE_COUNT if args.smoke else DEFAULT_SAMPLE_COUNT))
    preflight_duration_s = int(config.get("preflight_duration_s") or 0)
    warmup_value = config.get("smoke_warmup_duration_s") if args.smoke else config.get("warmup_duration_s")
    warmup_duration_s = float(warmup_value or (DEFAULT_SMOKE_WARMUP_DURATION_S if args.smoke else DEFAULT_WARMUP_DURATION_S))
    latency_probe_value = config.get("smoke_latency_probe_count") if args.smoke else config.get("latency_probe_count")
    if latency_probe_value is None:
        latency_probe_count = int(DEFAULT_SMOKE_LATENCY_PROBE_COUNT if args.smoke else DEFAULT_LATENCY_PROBE_COUNT)
    else:
        latency_probe_count = int(latency_probe_value)
    latency_probe_timeout_s = float(config.get("latency_probe_timeout_s") or DEFAULT_LATENCY_PROBE_TIMEOUT_S)
    statistics_config = config.get("statistics") if isinstance(config.get("statistics"), Mapping) else {}
    ci_iterations = int((statistics_config or {}).get("bootstrap_iterations") or DEFAULT_BOOTSTRAP_ITERATIONS)
    ci_seed = int((statistics_config or {}).get("bootstrap_seed") or DEFAULT_BOOTSTRAP_SEED)

    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)

    setup_result = inspect_tracee_setup()
    tracee_binary = resolve_tracee_binary(None, setup_result)

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Tracee setup inspection failed before execution.")
    if tracee_binary is None:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=None,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message="Tracee binary is unavailable in this environment; manual .bpf.o path is forbidden.",
            limitations=limitations,
        )

    workloads = list(config.get("workloads") or [])
    if not workloads:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message="Tracee config contains no workloads",
            limitations=limitations,
        )
    tracee_extra_args: list[str] = []
    commands = build_tracee_commands(tracee_binary, tracee_extra_args)
    preflight: dict[str, object] | None = None
    try:
        cycle_results: list[dict[str, object]] = []
        tracee_programs: list[dict[str, object]] = []
        prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
        if prepared_daemon_session is None:
            raise RuntimeError("prepared daemon session is required")
        with enable_bpf_stats():
            for cycle_index in range(sample_count):
                cycle_seed = ci_seed + (cycle_index * 5000)
                control_phase = run_phase(
                    workloads,
                    duration_s,
                    [],
                    cycle_index=cycle_index,
                    phase_name="control",
                    warmup_duration_s=warmup_duration_s,
                    latency_probe_count=0,
                    latency_probe_timeout_s=latency_probe_timeout_s,
                    ci_iterations=ci_iterations,
                    ci_seed=cycle_seed,
                    agent_pid=None,
                    collector=None,
                )
                control_records = tuple(dict(record) for record in (control_phase.get("workloads") or []))
                if not control_records:
                    raise RuntimeError("control phase produced no workload measurements")

                def setup() -> dict[str, object]:
                    return {}

                def start(_: object) -> CaseLifecycleState:
                    runner = TraceeRunner(
                        tracee_binary=tracee_binary,
                        extra_args=tracee_extra_args,
                        load_timeout_s=DEFAULT_LOAD_TIMEOUT_S,
                    )
                    runner.start()
                    prog_ids = [
                        int(program["id"])
                        for program in runner.programs
                        if int(program.get("id", 0) or 0) > 0
                    ]
                    return CaseLifecycleState(
                        runtime=runner,
                        prog_ids=prog_ids,
                        artifacts={
                            "tracee_programs": runner.programs,
                            "rejit_policy_context": {
                                "repo": "tracee",
                                "level": "e2e",
                            },
                        },
                    )

                def before_baseline(_: object, lifecycle: CaseLifecycleState) -> LifecycleAbort | None:
                    nonlocal preflight
                    if preflight is not None or preflight_duration_s <= 0:
                        return None
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    preflight = run_phase(
                        list(workloads),
                        preflight_duration_s,
                        lifecycle.prog_ids,
                        cycle_index=cycle_index,
                        phase_name="preflight",
                        warmup_duration_s=0,
                        latency_probe_count=0,
                        latency_probe_timeout_s=latency_probe_timeout_s,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + 250,
                        agent_pid=runner.pid,
                        collector=runner.collector,
                        runner=runner,
                    )
                    preflight["program_activity"] = {
                        "programs": summarize_program_activity(preflight, lifecycle.prog_ids),
                    }
                    lifecycle.artifacts["preflight"] = preflight
                    program_run_cnt = int(
                        ((preflight.get("program_activity") or {}).get("programs") or {}).get("total_run_cnt", 0)
                        or 0
                    )
                    if program_run_cnt <= 0:
                        raise RuntimeError(
                            "preflight observed zero Tracee program executions; "
                            "workload did not exercise the discovered program set"
                        )
                    return None

                def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    phase_result = run_phase(
                        workloads,
                        duration_s,
                        lifecycle.prog_ids,
                        cycle_index=cycle_index,
                        phase_name=phase_name,
                        warmup_duration_s=warmup_duration_s,
                        latency_probe_count=latency_probe_count,
                        latency_probe_timeout_s=latency_probe_timeout_s,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + (500 if phase_name == "post_rejit" else 0),
                        agent_pid=runner.pid,
                        collector=runner.collector,
                        runner=runner,
                        control_records=control_records,
                    )
                    return attach_control_phase_metrics(
                        phase_result,
                        control_records,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + (1500 if phase_name == "post_rejit" else 1000),
                    )

                def stop(_: object, lifecycle: CaseLifecycleState) -> None:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    runner.stop()

                def cleanup(_: object) -> None:
                    return None

                lifecycle_result = run_case_lifecycle(
                    daemon_session=prepared_daemon_session,
                    setup=setup,
                    start=start,
                    workload=workload,
                    stop=stop,
                    cleanup=cleanup,
                    before_baseline=before_baseline,
                )

                if lifecycle_result.abort is not None:
                    return error_payload(
                        config=config,
                        duration_s=duration_s,
                        tracee_binary=tracee_binary,
                        setup_result=setup_result,
                        smoke=bool(args.smoke),
                        error_message=lifecycle_result.abort.reason,
                        limitations=limitations,
                        preflight=preflight,
                    )

                if lifecycle_result.state is None or lifecycle_result.baseline is None:
                    raise RuntimeError(f"Tracee lifecycle cycle {cycle_index} completed without a baseline phase")
                if lifecycle_result.post_rejit is None:
                    raise RuntimeError(f"Tracee post-ReJIT phase is missing in cycle {cycle_index}")

                cycle_scan_results = lifecycle_result.scan_results
                cycle_baseline = lifecycle_result.baseline
                cycle_post_rejit = lifecycle_result.post_rejit
                cycle_comparison = compare_phases(
                    cycle_baseline,
                    cycle_post_rejit,
                    control=control_phase,
                    ci_iterations=ci_iterations,
                    ci_seed=cycle_seed + 1000,
                )
                cycle_results.append(
                    {
                        "cycle_index": cycle_index,
                        "control": control_phase,
                        "baseline": cycle_baseline,
                        "scan_results": {str(key): value for key, value in cycle_scan_results.items()},
                        "rejit_result": lifecycle_result.rejit_result,
                        "post_rejit": cycle_post_rejit,
                        "comparison": cycle_comparison,
                    }
                )

                if not tracee_programs:
                    tracee_programs = list(lifecycle_result.artifacts.get("tracee_programs") or [])
    except Exception as exc:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message=f"Tracee case could not run: {exc}",
            limitations=limitations,
            preflight=preflight,
        )

    control = aggregate_phase_samples(
        "control",
        [sample for cycle in cycle_results for sample in phase_records(cycle["control"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 20000,
    )
    baseline = aggregate_phase_samples(
        "baseline",
        [sample for cycle in cycle_results for sample in phase_records(cycle["baseline"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 25000,
    )
    post_rejit = aggregate_phase_samples(
        "post_rejit",
        [sample for cycle in cycle_results for sample in phase_records(cycle["post_rejit"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 30000,
    )
    comparison = compare_phases(
        baseline,
        post_rejit,
        control=control,
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 35000,
    )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "ok",
        "mode": "tracee_daemon_same_image_paired_with_control",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "sample_count": sample_count,
        "warmup_duration_s": warmup_duration_s,
        "latency_probe_count": latency_probe_count,
        "latency_probe_timeout_s": latency_probe_timeout_s,
        "tracee_binary": tracee_binary,
        "tracee_launch_command": commands,
        "tracee_programs": tracee_programs,
        "setup": setup_result,
        "host": host_metadata(),
        "config": dict(config),
        "statistics": {
            "bootstrap_iterations": ci_iterations,
            "bootstrap_seed": ci_seed,
            "significance_test": "exact_paired_permutation_on_signed_deltas",
        },
        "preflight": preflight,
        "control": control,
        "baseline": baseline,
        "paired_cycles": cycle_results,
        "scan_results": {str(cycle["cycle_index"]): cycle["scan_results"] for cycle in cycle_results},
        "rejit_result": {str(cycle["cycle_index"]): cycle["rejit_result"] for cycle in cycle_results},
        "post_rejit": post_rejit,
        "comparison": comparison,
        "limitations": limitations,
    }
    return payload
