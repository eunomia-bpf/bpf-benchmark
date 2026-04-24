from __future__ import annotations

import argparse
import sys
import threading
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import which  # noqa: E402
from runner.libs.app_runners.setup_support import repo_artifact_root  # noqa: E402
from runner.libs.app_runners.base import AppRunner  # noqa: E402
from runner.libs.app_runners.scx import ScxRunner, read_scx_ops  # noqa: E402
from runner.libs.bpf_stats import compute_delta, sample_bpf_stats  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    sample_cpu_usage,
    sample_total_cpu_usage,
    start_sampler_thread,
)
from runner.libs.rejit import applied_site_totals_from_rejit_result  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    host_metadata,
    summarize_numbers,
    percent_delta,
    run_case_lifecycle,
)


DEFAULT_LOAD_TIMEOUT = 20
DEFAULT_DURATION_S = 10


def default_scx_binary() -> Path:
    return repo_artifact_root() / "scx" / "bin" / "scx_rusty"


def read_proc_stat_fields() -> dict[str, int]:
    wanted = ("ctxt", "processes", "procs_running")
    fields: dict[str, int] = {}
    try:
        lines = Path("/proc/stat").read_text().splitlines()
    except OSError as exc:
        raise RuntimeError(f"failed to read /proc/stat: {exc}") from exc
    for line in lines:
        parts = line.split()
        if len(parts) < 2 or parts[0] not in wanted:
            continue
        try:
            fields[parts[0]] = int(parts[1])
        except ValueError as exc:
            raise RuntimeError(f"failed to parse /proc/stat field {parts[0]!r}: {parts[1]!r}") from exc
    missing = [field for field in wanted if field not in fields]
    if missing:
        raise RuntimeError("/proc/stat is missing required fields: " + ", ".join(missing))
    return fields


def format_site_breakdown(site_totals: Mapping[str, object]) -> str:
    ordered_fields = (
        ("map_inline_sites", "map_inline"),
        ("const_prop_sites", "const_prop"),
        ("dce_sites", "dce"),
        ("cmov_sites", "cond_select"),
        ("wide_sites", "wide_mem"),
        ("rotate_sites", "rotate"),
        ("extract_sites", "extract"),
        ("endian_sites", "endian_fusion"),
        ("bounds_check_merge_sites", "bounds_check_merge"),
        ("skb_load_bytes_spec_sites", "skb_load_bytes_spec"),
        ("bulk_memory_sites", "bulk_memory"),
        ("branch_flip_sites", "branch_flip"),
        ("other_sites", "other"),
    )
    parts = [
        f"{label}={int(site_totals.get(field_name, 0) or 0)}"
        for field_name, label in ordered_fields
        if int(site_totals.get(field_name, 0) or 0) > 0
    ]
    return ", ".join(parts) if parts else "none"


def ensure_artifacts(daemon_binary: Path, scheduler_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")
    if not scheduler_binary.exists():
        raise RuntimeError(f"scx_rusty binary not found: {scheduler_binary}")


def workload_specs() -> list[dict[str, str]]:
    required = (
        ("hackbench", {"name": "hackbench", "kind": "hackbench", "metric": "runs/s"}),
        ("stress-ng", {"name": "stress-ng-cpu", "kind": "stress_ng_cpu", "metric": "bogo-ops/s"}),
        ("sysbench", {"name": "sysbench-cpu", "kind": "sysbench_cpu", "metric": "events/s"}),
    )
    missing = [binary for binary, _spec in required if not which(binary)]
    if missing:
        raise RuntimeError(
            "scx benchmark requires fixed workload generators in PATH: " + ", ".join(missing)
        )
    return [dict(spec) for _binary, spec in required]


def measure_workload(
    runner: AppRunner,
    workload_spec: Mapping[str, object],
    duration_s: int,
    *,
    agent_pid: int | None,
    prog_ids: Sequence[int],
) -> dict[str, object]:
    logical_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not logical_prog_ids:
        raise RuntimeError("scx workload measurement requires at least one live program id")
    logical_programs = [
        dict(program)
        for program in getattr(runner, "programs", [])
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    ]
    if isinstance(runner, ScxRunner):
        before_bpf, before_live_prog_id_map, before_live_programs = _sample_scx_program_stats(
            runner,
            logical_prog_ids,
            previous_programs=logical_programs,
        )
    else:
        before_bpf = sample_bpf_stats(logical_prog_ids)
        before_live_prog_id_map = {}
        before_live_programs = []
    before_proc = read_proc_stat_fields()
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

    workload_result = runner.run_workload_spec(workload_spec, duration_s)
    extra = dict(runner.last_workload_details)
    if isinstance(runner, ScxRunner):
        after_bpf, after_live_prog_id_map, after_live_programs = _sample_scx_program_stats(
            runner,
            logical_prog_ids,
            previous_programs=logical_programs,
        )
    else:
        after_bpf = sample_bpf_stats(logical_prog_ids)
        after_live_prog_id_map = {}
        after_live_programs = []

    for thread in threads:
        thread.join()
    if sampler_errors:
        raise RuntimeError("; ".join(sampler_errors))
    if not system_cpu_holder:
        raise RuntimeError("system cpu sampler produced no data")
    if agent_pid is not None and agent_pid not in cpu_holder:
        raise RuntimeError(f"agent cpu sampler produced no data for pid={agent_pid}")

    after_proc = read_proc_stat_fields()
    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_cpu_total = None
    if agent_cpu is not None:
        agent_cpu_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    ctxt_delta = max(0, int(after_proc.get("ctxt", 0)) - int(before_proc.get("ctxt", 0)))
    proc_delta = max(0, int(after_proc.get("processes", 0)) - int(before_proc.get("processes", 0)))

    return {
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "command": extra.get("command", []),
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "latency_ms_p50": extra.get("latency_ms_p50"),
        "latency_ms_p95": extra.get("latency_ms_p95"),
        "iterations": extra.get("iterations"),
        "context_switches_total": ctxt_delta,
        "context_switches_per_sec": (ctxt_delta / workload_result.duration_s) if workload_result.duration_s > 0 else None,
        "processes_started": proc_delta,
        "bpf": compute_delta(before_bpf, after_bpf),
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_cpu_total,
        },
        "system_cpu": system_cpu_holder,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
        "live_prog_id_maps": {
            "before": {str(logical_id): int(live_id) for logical_id, live_id in before_live_prog_id_map.items()},
            "after": {str(logical_id): int(live_id) for logical_id, live_id in after_live_prog_id_map.items()},
        },
        "live_programs": {
            "before": before_live_programs,
            "after": after_live_programs,
        },
    }


def _scx_logical_program_name_map(
    logical_prog_ids: Sequence[int],
    previous_programs: Sequence[Mapping[str, object]],
) -> dict[int, str]:
    wanted = {int(prog_id) for prog_id in logical_prog_ids if int(prog_id) > 0}
    return {
        int(program["id"]): str(program["name"]).strip()
        for program in previous_programs
        if int(program.get("id", 0) or 0) in wanted and str(program.get("name") or "").strip()
    }


def _scx_live_prog_id_map(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[dict[int, int], list[dict[str, object]]]:
    logical_ids = [int(prog_id) for prog_id in logical_prog_ids if int(prog_id) > 0]
    if not logical_ids:
        return {}, []
    logical_name_by_id = _scx_logical_program_name_map(logical_ids, previous_programs)
    refreshed_programs = runner.refresh_live_programs()
    live_id_by_name = {
        str(program.get("name") or "").strip(): int(program.get("id", 0) or 0)
        for program in refreshed_programs
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    }
    live_ids = {int(program.get("id", 0) or 0) for program in refreshed_programs}
    logical_to_live: dict[int, int] = {}
    for logical_id in logical_ids:
        program_name = logical_name_by_id.get(int(logical_id), "")
        live_id = int(live_id_by_name.get(program_name, 0) or 0)
        if live_id > 0:
            logical_to_live[int(logical_id)] = live_id
            continue
        if int(logical_id) in live_ids:
            logical_to_live[int(logical_id)] = int(logical_id)
    return logical_to_live, [dict(program) for program in refreshed_programs]


def _sample_scx_program_stats(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[dict[int, dict[str, object]], dict[int, int], list[dict[str, object]]]:
    logical_to_live, refreshed_programs = _scx_live_prog_id_map(
        runner,
        logical_prog_ids,
        previous_programs=previous_programs,
    )
    sampled_prog_ids = sorted({int(live_id) for live_id in logical_to_live.values() if int(live_id) > 0})
    if not sampled_prog_ids:
        raise RuntimeError("scx runner did not expose any live scheduler programs for BPF stats sampling")
    raw_stats = sample_bpf_stats(sampled_prog_ids)
    live_to_logical = {
        int(live_id): int(logical_id)
        for logical_id, live_id in logical_to_live.items()
        if int(logical_id) > 0 and int(live_id) > 0
    }
    remapped: dict[int, dict[str, object]] = {}
    for sampled_prog_id, record in raw_stats.items():
        logical_prog_id = live_to_logical.get(int(sampled_prog_id))
        if logical_prog_id is None:
            continue
        entry = dict(record)
        entry["sampled_prog_id"] = int(sampled_prog_id)
        entry["id"] = int(logical_prog_id)
        remapped[int(logical_prog_id)] = entry
    if not remapped:
        raise RuntimeError("scx BPF stats sampling returned no logical program records")
    return remapped, logical_to_live, refreshed_programs


def _resolve_scx_scheduler_prog_ids(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[list[int], dict[int, int], list[dict[str, object]]]:
    logical_ids = [int(prog_id) for prog_id in logical_prog_ids if int(prog_id) > 0]
    if not logical_ids:
        return [], {}, []
    logical_to_live, refreshed_programs = _scx_live_prog_id_map(
        runner,
        logical_ids,
        previous_programs=previous_programs,
    )
    scheduler_prog_ids = [
        int(logical_to_live.get(logical_prog_id, 0) or 0)
        for logical_prog_id in logical_ids
        if int(logical_to_live.get(logical_prog_id, 0) or 0) > 0
    ]
    if scheduler_prog_ids:
        return scheduler_prog_ids, logical_to_live, refreshed_programs
    return [], logical_to_live, refreshed_programs


def summarize_phase(workloads: Sequence[Mapping[str, object]]) -> dict[str, object]:
    return {
        "throughput": summarize_numbers([record.get("ops_per_sec") for record in workloads]),
        "bpf_avg_ns_per_run": summarize_numbers(
            [
                (((record.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run"))
                for record in workloads
            ]
        ),
        "context_switches_per_sec": summarize_numbers([record.get("context_switches_per_sec") for record in workloads]),
        "latency_ms_p50": summarize_numbers([record.get("latency_ms_p50") for record in workloads]),
        "latency_ms_p95": summarize_numbers([record.get("latency_ms_p95") for record in workloads]),
        "agent_cpu_total_pct": summarize_numbers(
            [
                ((record.get("agent_cpu") or {}).get("total_pct") if isinstance(record.get("agent_cpu"), Mapping) else None)
                for record in workloads
            ]
        ),
        "system_cpu_busy_pct": summarize_numbers(
            [
                ((record.get("system_cpu") or {}).get("busy_pct") if isinstance(record.get("system_cpu"), Mapping) else None)
                for record in workloads
            ]
        ),
    }


def run_phase(
    runner: AppRunner,
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    *,
    agent_pid: int | None,
    prog_ids: Sequence[int],
) -> dict[str, object]:
    active_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not active_prog_ids:
        raise RuntimeError("scx runner did not expose any live scheduler programs")
    records = [
        measure_workload(
            runner,
            workload_spec,
            duration_s,
            agent_pid=agent_pid,
            prog_ids=active_prog_ids,
        )
        for workload_spec in workloads
    ]
    return {
        "workloads": records,
        "summary": summarize_phase(records),
    }


def compare_phases(baseline: Mapping[str, object] | None, post: Mapping[str, object] | None) -> dict[str, object]:
    if not baseline or not post:
        return {"comparable": False, "reason": "post-ReJIT measurements are unavailable"}

    baseline_by_name = {record["name"]: record for record in baseline.get("workloads") or []}
    post_by_name = {record["name"]: record for record in post.get("workloads") or []}
    workload_rows: list[dict[str, object]] = []
    for name in sorted(set(baseline_by_name) & set(post_by_name)):
        before = baseline_by_name[name]
        after = post_by_name[name]
        before_cpu = ((before.get("agent_cpu") or {}).get("total_pct"))
        after_cpu = ((after.get("agent_cpu") or {}).get("total_pct"))
        before_bpf = (((before.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run"))
        after_bpf = (((after.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run"))
        workload_rows.append(
            {
                "name": name,
                "throughput_delta_pct": percent_delta(before.get("ops_per_sec"), after.get("ops_per_sec")),
                "bpf_avg_ns_delta_pct": percent_delta(before_bpf, after_bpf),
                "bpf_avg_ns_speedup": None
                if before_bpf in (None, 0) or after_bpf in (None, 0)
                else (float(before_bpf) / float(after_bpf)),
                "context_switches_delta_pct": percent_delta(
                    before.get("context_switches_per_sec"),
                    after.get("context_switches_per_sec"),
                ),
                "latency_p50_delta_pct": percent_delta(before.get("latency_ms_p50"), after.get("latency_ms_p50")),
                "agent_cpu_delta_pct": percent_delta(before_cpu, after_cpu),
            }
        )
    return {"comparable": True, "workloads": workload_rows}

def build_markdown(payload: Mapping[str, object]) -> str:
    status = str(payload.get("status") or "")
    lines = [
        "# scx_rusty End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Kernel: `{payload['host']['kernel']}`",
        f"- Scheduler binary: `{payload['scheduler_binary']}`",
    ]
    if status != "ok":
        lines.extend(
            [
                "",
                "## Result",
                "",
                "- Status: `ERROR`",
                f"- Reason: `{payload.get('error_message') or 'unknown'}`",
            ]
        )
    lines.extend(["", "## Loaded Programs", ""])
    site_totals = ((payload.get("site_summary") or {}).get("site_totals") or {})
    lines.append(
        f"- Programs: `{len(payload.get('scheduler_programs') or [])}`; "
        f"applied sites total=`{site_totals.get('total_sites')}`, "
        f"breakdown=`{format_site_breakdown(site_totals)}`"
    )
    lines.append(f"- Active ops: `{payload.get('scheduler_ops') or []}`")
    lines.extend(["", "## Baseline", ""])
    baseline = payload.get("baseline") or {}
    for workload in baseline.get("workloads") or []:
        bpf_avg_ns = (((workload.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run"))
        lines.append(
            f"- {workload['name']}: throughput={workload.get('ops_per_sec')} {workload['metric']}, "
            f"avg_ns={bpf_avg_ns}, "
            f"lat_p50_ms={workload.get('latency_ms_p50')}, "
            f"ctx/s={workload.get('context_switches_per_sec')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}"
        )
    post = payload.get("post_rejit")
    if post:
        lines.extend(["", "## Post-ReJIT", ""])
        for workload in post.get("workloads") or []:
            bpf_avg_ns = (((workload.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run"))
            lines.append(
                f"- {workload['name']}: throughput={workload.get('ops_per_sec')} {workload['metric']}, "
                f"avg_ns={bpf_avg_ns}, "
                f"lat_p50_ms={workload.get('latency_ms_p50')}, "
                f"ctx/s={workload.get('context_switches_per_sec')}, "
                f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}"
            )
    comparison = payload.get("comparison") or {}
    lines.extend(["", "## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: throughput_delta={workload.get('throughput_delta_pct')}%, "
                f"bpf_avg_ns_delta={workload.get('bpf_avg_ns_delta_pct')}%, "
                f"bpf_speedup={workload.get('bpf_avg_ns_speedup')}, "
                f"ctx_delta={workload.get('context_switches_delta_pct')}%, "
                f"lat_p50_delta={workload.get('latency_p50_delta_pct')}%, "
                f"agent_cpu_delta={workload.get('agent_cpu_delta_pct')}%"
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


def run_scx_case(args: argparse.Namespace) -> dict[str, object]:
    duration_s = int(args.duration or DEFAULT_DURATION_S)
    scheduler_binary = default_scx_binary().resolve()
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary, scheduler_binary)

    workloads = workload_specs()

    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")
    scheduler_program_ids: list[int] = []
    scheduler_programs: list[dict[str, object]] = []

    def setup() -> dict[str, object]:
        return {}

    def start(_: object) -> CaseLifecycleState:
        nonlocal scheduler_program_ids, scheduler_programs
        runner = ScxRunner(
            scheduler_binary=scheduler_binary,
            load_timeout_s=DEFAULT_LOAD_TIMEOUT,
            workload_spec={"name": "hackbench", "kind": "hackbench", "metric": "runs/s"},
        )
        runner.start()
        scheduler_programs = [dict(program) for program in runner.programs]
        scheduler_program_ids = [
            int(program.get("id", 0) or 0)
            for program in scheduler_programs
            if int(program.get("id", 0) or 0) > 0
        ]
        return CaseLifecycleState(
            runtime=runner,
            prog_ids=list(scheduler_program_ids),
            artifacts={
                "programs": runner.programs,
                "scheduler_programs": runner.programs,
                "rejit_policy_context": {
                    "repo": "scx",
                    "level": "e2e",
                },
            },
        )

    def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
        nonlocal scheduler_program_ids, scheduler_programs
        runner = lifecycle.runtime
        if not isinstance(runner, AppRunner):
            raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
        prog_ids = [int(prog_id) for prog_id in lifecycle.prog_ids if int(prog_id) > 0]
        if phase_name == "post_rejit":
            if not isinstance(runner, ScxRunner):
                raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
            scheduler_program_ids, _, scheduler_programs = _resolve_scx_scheduler_prog_ids(
                runner,
                lifecycle.prog_ids,
                previous_programs=scheduler_programs or list(lifecycle.artifacts.get("scheduler_programs") or []),
            )
            prog_ids = list(scheduler_program_ids)
        return run_phase(runner, workloads, duration_s, agent_pid=runner.pid, prog_ids=prog_ids)

    def after_baseline(_: object, lifecycle: CaseLifecycleState, baseline: Mapping[str, object]) -> Mapping[str, object]:
        nonlocal scheduler_program_ids, scheduler_programs
        del baseline
        runner = lifecycle.runtime
        if not isinstance(runner, ScxRunner):
            raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
        previous_programs = [
            dict(program)
            for program in (lifecycle.artifacts.get("scheduler_programs") or [])
            if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
        ]
        if not previous_programs:
            previous_programs = [
                dict(program)
                for program in getattr(runner, "programs", [])
                if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
            ]
        scheduler_program_ids, _, scheduler_programs = _resolve_scx_scheduler_prog_ids(
            runner,
            lifecycle.prog_ids,
            previous_programs=previous_programs,
        )
        if not scheduler_program_ids:
            raise RuntimeError("scx baseline could not resolve live scheduler program ids for daemon apply")
        return {}

    def resolve_rejit_prog_ids(
        _: object,
        lifecycle: CaseLifecycleState,
        baseline: Mapping[str, object],
    ) -> Sequence[int]:
        del lifecycle, baseline
        return list(scheduler_program_ids)

    def stop(_: object, lifecycle: CaseLifecycleState) -> None:
        runner = lifecycle.runtime
        if not isinstance(runner, AppRunner):
            raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
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
        after_baseline=after_baseline,
        resolve_rejit_prog_ids=resolve_rejit_prog_ids,
    )
    if lifecycle_result.state is None:
        raise RuntimeError("scx lifecycle completed without a live session")
    runner = lifecycle_result.state.runtime
    if not isinstance(runner, AppRunner):
        raise RuntimeError(f"scx lifecycle returned a non-runner runtime: {type(runner).__name__}")
    scheduler_programs = list(lifecycle_result.artifacts.get("scheduler_programs") or [])
    scheduler_ops = read_scx_ops()
    baseline = lifecycle_result.baseline
    rejit_result = lifecycle_result.rejit_result
    post_rejit = lifecycle_result.post_rejit
    runtime_counters_available = any(
        (((record.get("bpf") or {}).get("summary") or {}).get("avg_ns_per_run")) not in (None, 0)
        for record in ((baseline or {}).get("workloads") or [])
        if isinstance(record, Mapping)
    )
    limitations: list[str] = []
    if not runtime_counters_available:
        limitations.append(
            "selected scx workloads did not accumulate measurable per-program run_cnt/run_time_ns during this run."
        )
    per_program_records: Mapping[object, object] = {}
    if isinstance(rejit_result, Mapping):
        raw_per_program = rejit_result.get("per_program")
        if raw_per_program is None:
            per_program_records = {}
        elif isinstance(raw_per_program, Mapping):
            per_program_records = raw_per_program
        else:
            raise RuntimeError("scx REJIT result is missing per_program records")

    site_summary = {
        "programs_with_sites": sum(
            1
            for record in per_program_records.values()
            if int(
                applied_site_totals_from_rejit_result(record if isinstance(record, Mapping) else None).get(
                    "total_sites",
                    0,
                )
                or 0
            ) > 0
        ),
        "site_totals": applied_site_totals_from_rejit_result(rejit_result if isinstance(rejit_result, Mapping) else None),
    }
    site_totals = site_summary.get("site_totals")
    if not isinstance(site_totals, Mapping):
        raise RuntimeError("scx REJIT site summary is missing site_totals")
    applied_site_total_value = site_totals.get("total_sites")
    if isinstance(applied_site_total_value, bool) or not isinstance(applied_site_total_value, int):
        raise RuntimeError("scx REJIT site_totals.total_sites must be a non-negative integer")
    if applied_site_total_value < 0:
        raise RuntimeError("scx REJIT site_totals.total_sites must be a non-negative integer")
    comparison = compare_phases(baseline, post_rejit)

    error_message = ""
    rejit_error = ""
    if isinstance(rejit_result, Mapping):
        rejit_error = str(rejit_result.get("error") or "").strip()
    if rejit_error:
        limitations.append(f"Partial ReJIT/apply errors were reported: {rejit_error}")
    if post_rejit is None:
        error_message = "scx post-ReJIT phase is missing"

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if error_message else "ok",
        "duration_s": duration_s,
        "scheduler_binary": str(scheduler_binary),
        "scheduler_programs": scheduler_programs,
        "scheduler_ops": scheduler_ops,
        "host": host_metadata(),
        "baseline": baseline,
        "site_summary": site_summary,
        "post_rejit": post_rejit,
        "comparison": comparison,
        "limitations": limitations,
    }
    if error_message:
        payload["error_message"] = error_message
    return payload
