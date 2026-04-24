from __future__ import annotations

import argparse
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.katran import (  # noqa: E402
    DEFAULT_CONCURRENCY,
    DEFAULT_INTERFACE,
    KatranRunner,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    host_metadata,
    percent_delta,
    run_app_runner_lifecycle,
    speedup_ratio,
)
from runner.libs.metrics import sample_total_cpu_usage, start_sampler_thread  # noqa: E402


DEFAULT_DURATION_S = 5


def _measurement_bpf_avg_ns(phase: Mapping[str, object] | None) -> float | None:
    measurement = phase.get("measurement") if isinstance(phase, Mapping) else {}
    bpf = measurement.get("bpf") if isinstance(measurement, Mapping) else {}
    summary = bpf.get("summary") if isinstance(bpf, Mapping) else {}
    value = summary.get("avg_ns_per_run") if isinstance(summary, Mapping) else None
    return float(value) if isinstance(value, (int, float)) else None


def _measurement_workload_ops(phase: Mapping[str, object] | None) -> float | None:
    measurement = phase.get("measurement") if isinstance(phase, Mapping) else {}
    workload = measurement.get("workload") if isinstance(measurement, Mapping) else {}
    value = workload.get("ops_per_sec") if isinstance(workload, Mapping) else None
    return float(value) if isinstance(value, (int, float)) else None


def measure_workload(
    runner: KatranRunner,
    duration_s: int,
    prog_ids: list[int],
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    system_cpu_holder: dict[str, float] = {}
    sampler_errors: list[str] = []
    system_thread = start_sampler_thread(
        label="system cpu",
        errors=sampler_errors,
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
    )
    try:
        workload_result = runner.run_workload(duration_s)
    finally:
        system_thread.join()
    if sampler_errors:
        raise RuntimeError("; ".join(sampler_errors))
    if not system_cpu_holder:
        raise RuntimeError("system cpu sampler produced no data")
    after_bpf = sample_bpf_stats(prog_ids)
    return {
        "workload": workload_result.to_dict(),
        "bpf": compute_delta(before_bpf, after_bpf),
        "system_cpu": system_cpu_holder,
        "runner_summary": dict(runner.last_request_summary),
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    comparison = payload.get("comparison") if isinstance(payload.get("comparison"), Mapping) else {}
    lines = [
        "# Katran End-to-End Benchmark",
        "",
        f"- Generated: {payload.get('generated_at')}",
        f"- Status: `{payload.get('status')}`",
        f"- Workload: `{((payload.get('workload_spec') or {}).get('kind') if isinstance(payload.get('workload_spec'), Mapping) else 'unknown')}`",
        f"- Duration: `{payload.get('duration_s')}s`",
        f"- BPF speedup (baseline/rejit): `{comparison.get('bpf_speedup') if comparison.get('bpf_speedup') is not None else 'n/a'}`",
        f"- Workload throughput ratio (rejit/baseline): `{comparison.get('workload_ratio_rejit_over_baseline') if comparison.get('workload_ratio_rejit_over_baseline') is not None else 'n/a'}`",
    ]
    reason = str(comparison.get("reason") or "").strip()
    if reason:
        lines.append(f"- Comparison note: `{reason}`")
    return "\n".join(lines)


def run_katran_case(args: argparse.Namespace) -> dict[str, object]:
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")

    duration_override = int(args.duration or 0)
    duration_s = int(duration_override or DEFAULT_DURATION_S)
    workload_spec = {"kind": "network"}
    runner = KatranRunner(
        iface=DEFAULT_INTERFACE,
        router_peer_iface=None,
        concurrency=DEFAULT_CONCURRENCY,
        workload_spec=workload_spec,
    )

    def workload(lifecycle: object, _phase_name: str) -> dict[str, object]:
        prog_ids = list(getattr(lifecycle, "prog_ids", []) or [])
        return {
            "status": "ok",
            "measurement": measure_workload(runner, duration_s, prog_ids),
        }

    with enable_bpf_stats():
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=prepared_daemon_session,
            runner=runner,
            measure=workload,
        )

    baseline = dict(lifecycle_result.baseline or {})
    post_rejit = dict(lifecycle_result.post_rejit or {}) if lifecycle_result.post_rejit is not None else None
    rejit_result = dict(lifecycle_result.rejit_result or {})
    baseline_bpf_avg_ns = _measurement_bpf_avg_ns(baseline)
    rejit_bpf_avg_ns = _measurement_bpf_avg_ns(post_rejit)
    baseline_ops = _measurement_workload_ops(baseline)
    rejit_ops = _measurement_workload_ops(post_rejit)
    comparison_reason = ""
    status = "ok"
    error_message = str(rejit_result.get("error") or "").strip()
    if error_message:
        status = "error"
        comparison_reason = error_message
    elif post_rejit is None:
        status = "error"
        comparison_reason = "post-ReJIT measurement is missing"

    comparison = {
        "comparable": post_rejit is not None,
        "reason": comparison_reason,
        "baseline_bpf_avg_ns": baseline_bpf_avg_ns,
        "rejit_bpf_avg_ns": rejit_bpf_avg_ns,
        "bpf_speedup": speedup_ratio(baseline_bpf_avg_ns, rejit_bpf_avg_ns),
        "baseline_workload_ops_per_sec": baseline_ops,
        "rejit_workload_ops_per_sec": rejit_ops,
        "workload_ratio_rejit_over_baseline": (float(rejit_ops) / float(baseline_ops)) if baseline_ops not in (None, 0) and rejit_ops is not None else None,
        "system_cpu_busy_delta_pct": percent_delta(
            ((baseline.get("measurement") or {}).get("system_cpu") or {}).get("busy_pct") if isinstance(baseline.get("measurement"), Mapping) else None,
            ((post_rejit.get("measurement") or {}).get("system_cpu") or {}).get("busy_pct") if isinstance((post_rejit or {}).get("measurement"), Mapping) else None,
        ),
    }
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": status,
        "duration_s": duration_s,
        "workload_spec": dict(workload_spec),
        "daemon": str(Path(args.daemon).resolve()),
        "host": host_metadata(),
        "programs": list(lifecycle_result.artifacts.get("programs") or []),
        "baseline": baseline,
        "scan_results": dict(lifecycle_result.scan_results),
        "rejit_result": rejit_result,
        "post_rejit": post_rejit,
        "comparison": comparison,
    }
    if status == "error" and comparison_reason:
        payload["error_message"] = comparison_reason
    return payload
