from __future__ import annotations

import argparse
import sys
import threading
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
)
from runner.libs.app_runners.katran import (  # noqa: E402
    DEFAULT_CONCURRENCY,
    DEFAULT_INTERFACE,
    KatranRunner,
)
from runner.libs.case_common import (  # noqa: E402
    host_metadata,
    percent_delta,
    rejit_result_has_any_apply,
    run_app_runner_lifecycle,
    speedup_ratio,
)
from runner.libs.metrics import compute_delta, enable_bpf_stats, sample_bpf_stats, sample_total_cpu_usage, start_sampler_thread  # noqa: E402


DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "katran")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "katran-e2e.md"
DEFAULT_DURATION_S = 20
DEFAULT_SMOKE_DURATION_S = 5


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Katran end-to-end benchmark case.")
    parser.add_argument(
        "--daemon",
        default=str(ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"),
        help="Path to the bpfrejit-daemon binary.",
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path to write the JSON result payload.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path to write the Markdown summary.",
    )
    parser.add_argument(
        "--smoke",
        action="store_true",
        help="Run the smoke-sized Katran workload duration.",
    )
    parser.add_argument(
        "--duration",
        type=int,
        help="Override the Katran workload duration in seconds.",
    )
    parser.add_argument(
        "--smoke-duration",
        type=int,
        default=DEFAULT_SMOKE_DURATION_S,
        help="Smoke-mode workload duration in seconds.",
    )
    parser.add_argument(
        "--iface",
        default=DEFAULT_INTERFACE,
        help="Interface used by the Katran runner.",
    )
    parser.add_argument(
        "--router-peer-iface",
        help="Optional peer interface used by the Katran router helper.",
    )
    parser.add_argument(
        "--concurrency",
        type=int,
        default=DEFAULT_CONCURRENCY,
        help="Katran request generator concurrency.",
    )
    parser.add_argument(
        "--workload",
        default="network",
        help="Katran workload profile to execute.",
    )
    parser.add_argument(
        "--rejit-passes",
        default=None,
        help="Comma-separated ReJIT passes to enable. Pass an empty string to run zero passes.",
    )
    parser.add_argument(
        "--no-kinsn",
        action="store_true",
        help="Disable loading kinsn modules for this Katran run.",
    )
    return parser


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
        f"- Workload: `{payload.get('workload_kind')}`",
        f"- Duration: `{payload.get('duration_s')}s`",
        f"- Smoke: `{payload.get('smoke')}`",
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

    smoke_duration_s = int(getattr(args, "smoke_duration", DEFAULT_SMOKE_DURATION_S) or DEFAULT_SMOKE_DURATION_S)
    duration_override = int(getattr(args, "duration", 0) or 0)
    duration_s = int(duration_override or (smoke_duration_s if args.smoke else DEFAULT_DURATION_S))
    workload_kind = str(getattr(args, "workload", "") or "network")
    runner = KatranRunner(
        iface=str(getattr(args, "iface", DEFAULT_INTERFACE)),
        router_peer_iface=getattr(args, "router_peer_iface", None),
        concurrency=int(getattr(args, "concurrency", DEFAULT_CONCURRENCY)),
        workload_kind=workload_kind,
    )

    def workload(lifecycle: object, _phase_name: str) -> dict[str, object]:
        prog_ids = list(getattr(lifecycle, "target_prog_ids", []) or [])
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
    elif rejit_result_has_any_apply(rejit_result) and post_rejit is None:
        status = "error"
        comparison_reason = "post-ReJIT measurement is missing"
    elif post_rejit is None:
        comparison_reason = "no Katran program was applied; post-ReJIT measurement skipped"

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
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "workload_kind": workload_kind,
        "daemon": str(Path(args.daemon).resolve()),
        "host": host_metadata(),
        "runner_artifacts": dict(lifecycle_result.artifacts.get("runner_artifacts") or {}),
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
