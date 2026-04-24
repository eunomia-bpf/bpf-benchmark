from __future__ import annotations

import argparse
import sys
import threading
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs.app_runners.tetragon import (  # noqa: E402
    TetragonRunner,
    describe_agent_exit,
    inspect_tetragon_setup,
    resolve_tetragon_binary,
)
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    sample_cpu_usage,
    sample_total_cpu_usage,
    start_sampler_thread,
)
from runner.libs.rejit import applied_site_totals_from_rejit_result  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    LifecycleAbort,
    host_metadata,
    summarize_numbers,
    percent_delta,
    speedup_ratio,
    run_case_lifecycle,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_DURATION_S = 30
DEFAULT_SMOKE_DURATION_S = 8
DEFAULT_LOAD_TIMEOUT_S = 20
DEFAULT_TIMEOUT_S = 180


@dataclass(frozen=True)
class WorkloadSpec:
    name: str
    kind: str
    metric: str
    value: int = 0


DEFAULT_WORKLOADS = (
    WorkloadSpec(
        name="exec_storm",
        kind="exec_storm",
        metric="bogo-ops/s",
        value=2,
    ),
    WorkloadSpec(
        name="file_io",
        kind="file_io",
        metric="ops/s",
    ),
    WorkloadSpec(
        name="open_storm",
        kind="open_storm",
        metric="bogo-ops/s",
        value=2,
    ),
    WorkloadSpec(
        name="connect_storm",
        kind="connect_storm",
        metric="ops/s",
    ),
)

def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def load_config(path: Path) -> dict[str, object]:
    payload = yaml.safe_load(path.read_text())
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid config payload in {path}")
    return payload


def workload_specs_from_config(config: Mapping[str, object]) -> tuple[WorkloadSpec, ...]:
    raw_workloads = config.get("workloads")
    if not isinstance(raw_workloads, Sequence) or isinstance(raw_workloads, (str, bytes)):
        return DEFAULT_WORKLOADS

    workloads: list[WorkloadSpec] = []
    for index, raw_workload in enumerate(raw_workloads):
        if not isinstance(raw_workload, Mapping):
            raise RuntimeError(f"invalid tetragon workload entry at index {index}")
        name = str(raw_workload.get("name") or raw_workload.get("kind") or f"workload_{index}")
        kind = str(raw_workload.get("kind") or name)
        metric = str(raw_workload.get("metric") or "ops/s")
        value = int(raw_workload.get("value", 0) or 0)
        workloads.append(
            WorkloadSpec(
                name=name,
                kind=kind,
                metric=metric,
                value=value,
            )
        )
    return tuple(workloads) or DEFAULT_WORKLOADS

def measure_workload(
    runner: TetragonRunner,
    workload_spec: WorkloadSpec,
    duration_s: int,
    prog_ids: list[int],
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
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

    workload_result = runner.run_workload_spec(
        {
            "kind": workload_spec.kind,
            "value": workload_spec.value,
        },
        duration_s,
    )

    for thread in threads:
        thread.join()
    if sampler_errors:
        raise RuntimeError("; ".join(sampler_errors))
    if not system_cpu_holder:
        raise RuntimeError("system cpu sampler produced no data")
    if agent_pid is not None and agent_pid not in cpu_holder:
        raise RuntimeError(f"agent cpu sampler produced no data for pid={agent_pid}")

    after_bpf = sample_bpf_stats(prog_ids)
    bpf_delta = compute_delta(before_bpf, after_bpf)
    total_events = int((bpf_delta.get("summary") or {}).get("total_events", 0) or 0)
    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_total = None
    if agent_cpu is not None:
        agent_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    return {
        "name": workload_spec.name,
        "kind": workload_spec.kind,
        "metric": workload_spec.metric,
        "app_throughput": workload_result.ops_per_sec,
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "events_total": total_events,
        "events_per_sec": (total_events / workload_result.duration_s) if workload_result.duration_s > 0 else None,
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_total,
        },
        "system_cpu": system_cpu_holder,
        "bpf": bpf_delta,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
    }


def summarize_phase(workloads: Sequence[Mapping[str, object]]) -> dict[str, object]:
    return {
        "app_throughput": summarize_numbers([record.get("app_throughput") for record in workloads]),
        "events_per_sec": summarize_numbers([record.get("events_per_sec") for record in workloads]),
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
        "bpf_avg_ns_per_run": summarize_numbers(
            [
                ((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run"))
                for record in workloads
            ]
        ),
    }


def run_phase(
    runner: TetragonRunner,
    workloads: Sequence[WorkloadSpec],
    duration_s: int,
    prog_ids: list[int],
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    records = [
        measure_workload(
            runner,
            spec,
            duration_s,
            prog_ids,
            agent_pid=agent_pid,
        )
        for spec in workloads
    ]
    return {"workloads": records, "summary": summarize_phase(records)}


def aggregate_programs(phase: Mapping[str, object]) -> dict[str, dict[str, object]]:
    aggregated: dict[str, dict[str, object]] = {}
    for workload in phase.get("workloads") or []:
        programs = ((workload.get("bpf") or {}).get("programs") or {})
        for prog_id, record in programs.items():
            key = str(prog_id)
            target = aggregated.setdefault(
                key,
                {
                    "id": int(record.get("id", prog_id)),
                    "name": str(record.get("name", f"id-{prog_id}")),
                    "type": str(record.get("type", "")),
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


def build_program_summary(
    rejit_result: Mapping[str, object] | None,
    baseline: Mapping[str, object],
    post: Mapping[str, object] | None,
) -> list[dict[str, object]]:
    baseline_programs = aggregate_programs(baseline)
    post_programs = aggregate_programs(post or {})
    per_program: Mapping[object, object] = {}
    if isinstance(rejit_result, Mapping):
        raw_per_program = rejit_result.get("per_program")
        if raw_per_program is None:
            per_program = {}
        elif isinstance(raw_per_program, Mapping):
            per_program = raw_per_program
        else:
            raise RuntimeError("tetragon REJIT result is missing per_program records")
    rows: list[dict[str, object]] = []
    for prog_id in sorted(set(baseline_programs) | set(post_programs), key=int):
        before = baseline_programs.get(prog_id, {})
        after = post_programs.get(prog_id, {})
        apply_record = {}
        if per_program:
            apply_record = per_program.get(int(prog_id)) or per_program.get(str(prog_id)) or {}
            if not isinstance(apply_record, Mapping):
                raise RuntimeError(f"tetragon REJIT result is missing per-program apply record for prog {prog_id}")
        sites = applied_site_totals_from_rejit_result(apply_record if isinstance(apply_record, Mapping) else None).get("total_sites")
        stock_avg = before.get("avg_ns_per_run")
        rejit_avg = after.get("avg_ns_per_run")
        rows.append(
            {
                "id": int(prog_id),
                "name": str(after.get("name") or before.get("name") or f"id-{prog_id}"),
                "type": str(after.get("type") or before.get("type") or ""),
                "sites": int(sites or 0),
                "stock_avg_ns": stock_avg,
                "rejit_avg_ns": rejit_avg,
                "speedup": speedup_ratio(stock_avg, rejit_avg),
                "stock_events": before.get("run_cnt_delta"),
                "rejit_events": after.get("run_cnt_delta"),
            }
        )
    return rows


def compare_phases(baseline: Mapping[str, object], post: Mapping[str, object] | None) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "post-ReJIT phase is missing"}

    baseline_by_name = {record["name"]: record for record in baseline.get("workloads") or []}
    post_by_name = {record["name"]: record for record in post.get("workloads") or []}
    workload_rows: list[dict[str, object]] = []
    for name in sorted(set(baseline_by_name) & set(post_by_name)):
        before = baseline_by_name[name]
        after = post_by_name[name]
        workload_rows.append(
            {
                "name": name,
                "baseline_ops_per_sec": before.get("ops_per_sec"),
                "post_ops_per_sec": after.get("ops_per_sec"),
                "app_throughput_delta_pct": percent_delta(before.get("ops_per_sec"), after.get("ops_per_sec")),
                "baseline_events_per_sec": before.get("events_per_sec"),
                "post_events_per_sec": after.get("events_per_sec"),
                "events_per_sec_delta_pct": percent_delta(before.get("events_per_sec"), after.get("events_per_sec")),
                "baseline_agent_cpu_pct": ((before.get("agent_cpu") or {}).get("total_pct")),
                "post_agent_cpu_pct": ((after.get("agent_cpu") or {}).get("total_pct")),
                "agent_cpu_delta_pct": percent_delta(
                    ((before.get("agent_cpu") or {}).get("total_pct")),
                    ((after.get("agent_cpu") or {}).get("total_pct")),
                ),
                "bpf_avg_ns_delta_pct": percent_delta(
                    ((before.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                    ((after.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                ),
            }
        )
    return {"comparable": True, "workloads": workload_rows}


def append_preflight_markdown(lines: list[str], payload: Mapping[str, object]) -> None:
    preflight = payload.get("preflight")
    if not isinstance(preflight, Mapping):
        return

    activity = preflight.get("program_activity") if isinstance(preflight.get("program_activity"), Mapping) else {}
    program_activity = activity.get("programs") if isinstance(activity, Mapping) else {}

    lines.extend(["", "## Preflight", ""])
    for workload in preflight.get("workloads") or []:
        if not isinstance(workload, Mapping):
            continue
        lines.append(
            f"- {workload.get('name', 'unknown')}: "
            f"events/s={workload.get('events_per_sec')}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}, "
            f"program_runs={((program_activity or {}).get('total_run_cnt'))}"
        )


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# Tetragon Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Tetragon binary: `{payload.get('tetragon_binary') or 'unavailable'}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{payload['setup']['returncode']}`",
        f"- Setup tetragon binary: `{payload['setup'].get('tetragon_binary') or 'missing'}`",
    ]
    status = str(payload.get("status") or "")
    if status != "ok":
        result_reason = payload.get("error_message") or "unknown"
        lines.extend(
            [
                "",
                "## Result",
                "",
                "- Status: `ERROR`",
                f"- Reason: `{result_reason}`",
            ]
        )
        append_preflight_markdown(lines, payload)
        limitations = payload.get("limitations") or []
        if limitations:
            lines.extend(["", "## Limitations", ""])
            for limitation in limitations:
                lines.append(f"- {limitation}")
        lines.append("")
        return "\n".join(lines)

    baseline = payload["baseline"]
    post = payload.get("post_rejit")
    comparison = payload.get("comparison") or {}
    lines.extend(
        [
            "",
            "## Baseline",
            "",
            f"- Application throughput mean: `{baseline['summary']['app_throughput']['mean']}` ops/s",
            f"- Events/s mean: `{baseline['summary']['events_per_sec']['mean']}`",
            f"- Agent CPU mean: `{baseline['summary']['agent_cpu_total_pct']['mean']}`%",
            f"- BPF avg ns mean: `{baseline['summary']['bpf_avg_ns_per_run']['mean']}`",
            "",
        ]
    )
    for workload in baseline["workloads"]:
        lines.append(
            f"- {workload['name']}: ops/s={workload.get('ops_per_sec')}, "
            f"events/s={workload.get('events_per_sec')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
        )

    lines.extend(
        [
            "",
            "## Per-Program",
            "",
        ]
    )
    for program in payload.get("programs") or []:
        lines.append(
            f"- {program['name']} ({program['type']}): sites={program['sites']}, "
            f"stock_avg_ns={program['stock_avg_ns']}, rejit_avg_ns={program['rejit_avg_ns']}, "
            f"speedup={program['speedup']}"
        )

    if post:
        lines.extend(
            [
                "",
                "## Post-ReJIT",
                "",
                f"- Application throughput mean: `{post['summary']['app_throughput']['mean']}` ops/s",
                f"- Events/s mean: `{post['summary']['events_per_sec']['mean']}`",
                f"- Agent CPU mean: `{post['summary']['agent_cpu_total_pct']['mean']}`%",
                f"- BPF avg ns mean: `{post['summary']['bpf_avg_ns_per_run']['mean']}`",
                "",
            ]
        )
        for workload in post["workloads"]:
            lines.append(
                f"- {workload['name']}: ops/s={workload.get('ops_per_sec')}, "
                f"events/s={workload.get('events_per_sec')}, "
                f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
                f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
            )

    lines.extend(["", "## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads", []):
            lines.append(
                f"- {workload['name']}: baseline_ops/s={workload.get('baseline_ops_per_sec')}, "
                f"post_ops/s={workload.get('post_ops_per_sec')}, "
                f"app_delta={workload.get('app_throughput_delta_pct')}%, "
                f"baseline_cpu={workload.get('baseline_agent_cpu_pct')}, "
                f"post_cpu={workload.get('post_agent_cpu_pct')}, "
                f"cpu_delta={workload.get('agent_cpu_delta_pct')}%"
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


def error_payload(
    *,
    config: Mapping[str, object] | None,
    tetragon_binary: str | None,
    duration_s: int,
    smoke: bool,
    setup_result: Mapping[str, object],
    error_message: str,
    limitations: Sequence[str],
    preflight: Mapping[str, object] | None = None,
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error",
        "mode": "error",
        "error_message": error_message,
        "config": dict(config or {}),
        "smoke": smoke,
        "duration_s": duration_s,
        "tetragon_binary": tetragon_binary,
        "setup": dict(setup_result),
        "host": host_metadata(),
        "tetragon_programs": [],
        "baseline": None,
        "scan_results": {},
        "rejit_result": None,
        "post_rejit": None,
        "programs": [],
        "comparison": {"comparable": False, "reason": error_message},
        "limitations": list(limitations),
        "preflight": dict(preflight or {}) if preflight else None,
    }


def daemon_payload(
    *,
    config: Mapping[str, object],
    prepared_daemon_session: object,
    daemon_binary: Path,
    tetragon_binary: str,
    workloads: Sequence[WorkloadSpec],
    duration_s: int,
    preflight_duration_s: int,
    smoke: bool,
    load_timeout: int,
    setup_result: Mapping[str, object],
    limitations: list[str],
) -> dict[str, object]:
    preflight: dict[str, object] | None = None

    def setup() -> dict[str, object]:
        return {}

    def start(state: object) -> CaseLifecycleState:
        del state
        runner = TetragonRunner(
            tetragon_binary=tetragon_binary,
            load_timeout_s=load_timeout,
            setup_result=setup_result,
        )
        runner.start()
        tetragon_programs = [dict(program) for program in runner.programs]
        prog_ids = [int(program["id"]) for program in tetragon_programs if int(program.get("id", 0) or 0) > 0]
        return CaseLifecycleState(
            runtime=runner,
            prog_ids=prog_ids,
            artifacts={
                "tetragon_launch_command": list(runner.command),
                "tetragon_programs": tetragon_programs,
                "rejit_policy_context": {
                    "repo": "tetragon",
                    "level": "e2e",
                },
            },
        )

    def before_baseline(_: object, lifecycle: CaseLifecycleState) -> LifecycleAbort | None:
        nonlocal preflight
        if preflight_duration_s <= 0 or not workloads:
            return None
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        preflight = run_phase(
            runner,
            list(workloads),
            preflight_duration_s,
            lifecycle.prog_ids,
            agent_pid=runner.pid,
        )
        preflight["program_activity"] = {
            "programs": summarize_program_activity(preflight, lifecycle.prog_ids),
        }
        lifecycle.artifacts["preflight"] = preflight
        return None

    def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
        del phase_name
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        return run_phase(
            runner,
            workloads,
            duration_s,
            lifecycle.prog_ids,
            agent_pid=runner.pid,
        )

    def before_rejit(_: object, lifecycle: CaseLifecycleState, baseline: Mapping[str, object]) -> LifecycleAbort | None:
        del baseline
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        session = runner.session
        snapshot = {} if session is None else session.collector_snapshot()
        process = None if session is None else session.process
        exit_reason = describe_agent_exit("Tetragon", process, snapshot)
        if exit_reason is not None:
            limitations.append(f"{exit_reason}; aborting scan and ReJIT after the baseline phase.")
            return LifecycleAbort(
                status="error",
                reason=exit_reason,
            )
        return None

    def stop(_: object, lifecycle: CaseLifecycleState) -> None:
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        runner.stop()

    def cleanup(state: object) -> None:
        del state

    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")
    lifecycle_result = run_case_lifecycle(
        daemon_session=prepared_daemon_session,
        setup=setup,
        start=start,
        workload=workload,
        stop=stop,
        cleanup=cleanup,
        before_baseline=before_baseline,
        before_rejit=before_rejit,
    )
    if lifecycle_result.abort is not None:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            smoke=smoke,
            setup_result=setup_result,
            error_message=lifecycle_result.abort.reason,
            limitations=limitations,
            preflight=preflight,
        )
    if lifecycle_result.state is None or lifecycle_result.baseline is None:
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            smoke=smoke,
            setup_result=setup_result,
            error_message="Tetragon lifecycle completed without a baseline phase",
            limitations=limitations,
            preflight=preflight,
        )

    runner = lifecycle_result.state.runtime
    assert isinstance(runner, TetragonRunner)

    baseline = lifecycle_result.baseline
    scan_results = lifecycle_result.scan_results
    rejit_result = lifecycle_result.rejit_result or {"applied": False, "reason": "reJIT did not run"}
    post_rejit = lifecycle_result.post_rejit
    comparison = compare_phases(baseline, post_rejit)
    error_message = str(rejit_result.get("error") or "").strip()
    if not error_message and post_rejit is None:
        error_message = "Tetragon post-ReJIT phase is missing"

    limitations.append(
        "events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters."
    )
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if error_message else "ok",
        "mode": "tetragon_daemon",
        "smoke": smoke,
        "duration_s": duration_s,
        "tetragon_binary": tetragon_binary,
        "setup": dict(setup_result),
        "host": host_metadata(),
        "tetragon_launch_command": lifecycle_result.artifacts.get("tetragon_launch_command") or [],
        "config": dict(config),
        "tetragon_programs": lifecycle_result.artifacts.get("tetragon_programs") or [],
        "agent_logs": runner.process_output,
        "preflight": preflight,
        "baseline": baseline,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "rejit_result": rejit_result,
        "post_rejit": post_rejit,
        "site_summary": {
            "site_totals": applied_site_totals_from_rejit_result(rejit_result if isinstance(rejit_result, Mapping) else None),
        },
        "programs": build_program_summary(rejit_result if isinstance(rejit_result, Mapping) else None, baseline, post_rejit),
        "comparison": comparison,
        "limitations": limitations,
    }
    if error_message:
        payload["error_message"] = error_message
    return payload


def run_tetragon_case(args: argparse.Namespace) -> dict[str, object]:
    config = load_config(Path(getattr(args, "config", DEFAULT_CONFIG)).resolve())
    duration_s = int(
        args.duration
        or (
            int(config.get("smoke_duration_s", DEFAULT_SMOKE_DURATION_S) or DEFAULT_SMOKE_DURATION_S)
            if args.smoke
            else int(config.get("measurement_duration_s", DEFAULT_DURATION_S) or DEFAULT_DURATION_S)
        )
    )
    preflight_duration_s = int(config.get("preflight_duration_s", 0) or 0)
    workloads = workload_specs_from_config(config)
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)

    setup_result = inspect_tetragon_setup()

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Tetragon setup inspection failed before execution.")

    tetragon_binary = resolve_tetragon_binary(None, setup_result)
    if tetragon_binary is None:
        return error_payload(
            config=config,
            tetragon_binary=None,
            duration_s=duration_s,
            smoke=bool(args.smoke),
            setup_result=setup_result,
            error_message="Tetragon binary is unavailable in this environment; manual .bpf.o path is forbidden.",
            limitations=limitations,
        )

    with enable_bpf_stats():
        try:
            return daemon_payload(
                config=config,
                prepared_daemon_session=getattr(args, "_prepared_daemon_session", None),
                daemon_binary=daemon_binary,
                tetragon_binary=tetragon_binary,
                workloads=workloads,
                duration_s=duration_s,
                preflight_duration_s=preflight_duration_s,
                smoke=bool(args.smoke),
                load_timeout=DEFAULT_LOAD_TIMEOUT_S,
                setup_result=setup_result,
                limitations=limitations,
            )
        except Exception as exc:
            return error_payload(
                config=config,
                tetragon_binary=tetragon_binary,
                duration_s=duration_s,
                smoke=bool(args.smoke),
                setup_result=setup_result,
                error_message=f"Tetragon case could not run: {exc}",
                limitations=limitations,
            )
