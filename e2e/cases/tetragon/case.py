#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import sys
import threading
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    smoke_output_path,
    tail_text,
    which,
)
from runner.libs.app_runners.tetragon import (  # noqa: E402
    TetragonAgentSession,
    TetragonRunner,
    describe_agent_exit,
    resolve_tetragon_binary,
    run_exec_storm_in_cgroup as runner_run_exec_storm_in_cgroup,
    run_setup_script,
    run_tetragon_workload,
)
from runner.libs.daemon_session import DaemonSession  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from runner.libs.rejit import benchmark_rejit_enabled_passes  # noqa: E402
from runner.libs.workload import WorkloadResult  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    LifecycleAbort,
    host_metadata,
    summarize_numbers,
    percent_delta,
    prepare_daemon_session,
    speedup_ratio,
    persist_results,
    run_case_lifecycle,
)


DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_CONFIG = Path(__file__).with_name("config_execve_rate.yaml")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "tetragon")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "tetragon-real-e2e.md"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_BPFTOOL = "/usr/local/sbin/bpftool"
DEFAULT_DURATION_S = 30
DEFAULT_SMOKE_DURATION_S = 8
DEFAULT_LOAD_TIMEOUT_S = 20
DEFAULT_TIMEOUT_S = 180


@dataclass(frozen=True, slots=True)
class WorkloadSpec:
    name: str
    kind: str
    metric: str
    description: str
    value: int = 0


DEFAULT_WORKLOADS = (
    WorkloadSpec(
        name="stress_exec",
        kind="exec_storm",
        metric="bogo-ops/s",
        description="stress-ng execve workload",
        value=2,
    ),
    WorkloadSpec(
        name="file_io",
        kind="file_io",
        metric="ops/s",
        description="fio or dd file workload",
    ),
    WorkloadSpec(
        name="open_storm",
        kind="open_storm",
        metric="bogo-ops/s",
        description="stress-ng open workload",
        value=2,
    ),
    WorkloadSpec(
        name="connect_storm",
        kind="connect_storm",
        metric="ops/s",
        description="rapid loopback TCP connect storm",
    ),
)



def bpftool_binary() -> str:
    try:
        return resolve_bpftool_binary()
    except RuntimeError:
        if Path(DEFAULT_BPFTOOL).exists():
            return DEFAULT_BPFTOOL
        return "bpftool"


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
        description = str(raw_workload.get("description") or "")
        value = int(raw_workload.get("value", 0) or 0)
        workloads.append(
            WorkloadSpec(
                name=name,
                kind=kind,
                metric=metric,
                description=description,
                value=value,
            )
        )
    return tuple(workloads) or DEFAULT_WORKLOADS


def select_tetragon_programs(
    live_programs: Sequence[Mapping[str, object]],
    config: Mapping[str, object],
    *,
    config_key: str = "target_programs",
    allow_all_when_unset: bool = True,
) -> list[dict[str, object]]:
    available_programs = [dict(program) for program in live_programs if isinstance(program, Mapping)]
    requested_names = [
        str(name).strip()
        for name in (config.get(config_key) or [])
        if str(name).strip()
    ]
    if not requested_names:
        return available_programs if allow_all_when_unset else []

    selected: list[dict[str, object]] = []
    missing: list[str] = []
    for requested_name in requested_names:
        matched = False
        for program in live_programs:
            if not isinstance(program, Mapping):
                continue
            live_name = str(program.get("name") or "")
            if live_name == requested_name and dict(program) not in selected:
                selected.append(dict(program))
                matched = True
        if not matched:
            missing.append(requested_name)
    if missing:
        raise RuntimeError(
            f"configured {config_key} not found in live Tetragon programs: {', '.join(missing)}"
        )
    return selected


def run_workload(spec: WorkloadSpec, duration_s: int) -> WorkloadResult:
    return run_workload_with_options(spec, duration_s, exec_workload_cgroup=False)


def run_exec_storm_in_cgroup(duration_s: int | float, rate: int) -> WorkloadResult:
    return runner_run_exec_storm_in_cgroup(duration_s, rate)


def run_workload_with_options(
    spec: WorkloadSpec,
    duration_s: int,
    *,
    exec_workload_cgroup: bool,
) -> WorkloadResult:
    if spec.kind == "exec_storm" and exec_workload_cgroup:
        return run_exec_storm_in_cgroup(duration_s, spec.value or 2)
    return run_tetragon_workload(
        {"kind": spec.kind, "value": spec.value},
        duration_s,
        exec_workload_cgroup=False,
    )


def measure_workload(
    runner: TetragonRunner,
    workload_spec: WorkloadSpec,
    duration_s: int,
    prog_ids: list[int],
    *,
    agent_pid: int | None,
    exec_workload_cgroup: bool,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids)
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    threads: list[threading.Thread] = []

    if agent_pid is not None:
        cpu_thread = threading.Thread(
            target=lambda: cpu_holder.update(sample_cpu_usage([agent_pid], duration_s)),
            daemon=True,
        )
        cpu_thread.start()
        threads.append(cpu_thread)

    system_thread = threading.Thread(
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
        daemon=True,
    )
    system_thread.start()
    threads.append(system_thread)

    workload_result = runner.run_workload_spec(
        {"kind": workload_spec.kind, "value": workload_spec.value},
        duration_s,
        exec_workload_cgroup=exec_workload_cgroup,
    )

    for thread in threads:
        thread.join()

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
        "description": workload_spec.description,
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
    exec_workload_cgroup: bool,
) -> dict[str, object]:
    records = [
        measure_workload(
            runner,
            spec,
            duration_s,
            prog_ids,
            agent_pid=agent_pid,
            exec_workload_cgroup=exec_workload_cgroup,
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
    scan_results: Mapping[int, Mapping[str, object]],
    baseline: Mapping[str, object],
    post: Mapping[str, object] | None,
) -> list[dict[str, object]]:
    baseline_programs = aggregate_programs(baseline)
    post_programs = aggregate_programs(post or {})
    rows: list[dict[str, object]] = []
    for prog_id in sorted(set(baseline_programs) | set(post_programs), key=int):
        before = baseline_programs.get(prog_id, {})
        after = post_programs.get(prog_id, {})
        scan = scan_results.get(int(prog_id), {}) if isinstance(scan_results, dict) else {}
        sites = ((scan.get("sites") or {}).get("total_sites"))
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
        return {"comparable": False, "reason": "rejit did not apply successfully"}

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
    target_activity = activity.get("target_programs") if isinstance(activity, Mapping) else {}
    apply_activity = activity.get("apply_programs") if isinstance(activity, Mapping) else {}

    lines.extend(["", "## Preflight", ""])
    for workload in preflight.get("workloads") or []:
        if not isinstance(workload, Mapping):
            continue
        lines.append(
            f"- {workload.get('name', 'unknown')}: "
            f"events/s={workload.get('events_per_sec')}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}, "
            f"target_runs={((target_activity or {}).get('total_run_cnt'))}, "
            f"apply_runs={((apply_activity or {}).get('total_run_cnt'))}"
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
    daemon_binary: Path,
    tetragon_binary: str,
    tetragon_extra_args: Sequence[str],
    workloads: Sequence[WorkloadSpec],
    duration_s: int,
    preflight_duration_s: int,
    require_program_activity: bool,
    smoke: bool,
    load_timeout: int,
    setup_result: Mapping[str, object],
    limitations: list[str],
) -> dict[str, object]:
    preflight: dict[str, object] | None = None
    exec_workload_cgroup = any(arg == "--cgroup-rate" for arg in tetragon_extra_args)

    def setup() -> dict[str, object]:
        return {}

    def start(state: object) -> CaseLifecycleState:
        del state
        runner = TetragonRunner(
            tetragon_binary=tetragon_binary,
            tetragon_extra_args=tetragon_extra_args,
            load_timeout_s=load_timeout,
        )
        runner.start()
        selected_programs = select_tetragon_programs(runner.programs, config)
        prog_ids = [int(program["id"]) for program in selected_programs]
        if config.get("apply_programs"):
            apply_programs = select_tetragon_programs(
                runner.programs,
                config,
                config_key="apply_programs",
                allow_all_when_unset=False,
            )
            apply_prog_ids = [int(program["id"]) for program in apply_programs]
        else:
            apply_programs = [dict(program) for program in selected_programs]
            apply_prog_ids = list(prog_ids)
        return CaseLifecycleState(
            runtime=runner,
            target_prog_ids=prog_ids,
            apply_prog_ids=apply_prog_ids,
            artifacts={
                "tetragon_launch_command": list(runner.command),
                "policy_dir": None if runner.tempdir is None else runner.tempdir.name,
                "policy_paths": [str(path) for path in runner.policy_paths],
                "tetragon_programs": runner.programs,
                "selected_tetragon_programs": selected_programs,
                "apply_tetragon_programs": apply_programs,
            },
        )

    def before_baseline(_: object, lifecycle: CaseLifecycleState) -> LifecycleAbort | None:
        nonlocal preflight
        if preflight_duration_s <= 0 or not workloads:
            return None
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        preflight_prog_ids = sorted(set(lifecycle.target_prog_ids) | set(lifecycle.apply_prog_ids))
        preflight = run_phase(
            runner,
            list(workloads),
            preflight_duration_s,
            preflight_prog_ids,
            agent_pid=runner.pid,
            exec_workload_cgroup=exec_workload_cgroup,
        )
        preflight["program_activity"] = {
            "target_programs": summarize_program_activity(preflight, lifecycle.target_prog_ids),
            "apply_programs": summarize_program_activity(preflight, lifecycle.apply_prog_ids),
        }
        lifecycle.artifacts["preflight"] = preflight
        if not require_program_activity:
            return None

        target_run_cnt = int(
            ((preflight.get("program_activity") or {}).get("target_programs") or {}).get("total_run_cnt", 0) or 0
        )
        apply_run_cnt = int(
            ((preflight.get("program_activity") or {}).get("apply_programs") or {}).get("total_run_cnt", 0) or 0
        )
        if target_run_cnt <= 0:
            limitations.append(
                "Configured Tetragon workload did not execute the selected target programs during preflight."
            )
            return LifecycleAbort(
                status="error",
                reason="preflight observed zero target-program executions; invalid runtime measurement",
                artifacts={"preflight": preflight},
            )
        if config.get("apply_programs") and apply_run_cnt <= 0:
            limitations.append(
                "Configured Tetragon workload did not execute the configured apply programs during preflight."
            )
            return LifecycleAbort(
                status="error",
                reason="preflight observed zero apply-program executions; invalid optimization benchmark",
                artifacts={"preflight": preflight},
            )
        return None

    def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
        del phase_name
        runner = lifecycle.runtime
        assert isinstance(runner, TetragonRunner)
        return run_phase(
            runner,
            workloads,
            duration_s,
            lifecycle.target_prog_ids,
            agent_pid=runner.pid,
            exec_workload_cgroup=exec_workload_cgroup,
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

    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
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
        enabled_passes=benchmark_rejit_enabled_passes(),
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
    policy_dir = lifecycle_result.artifacts.get("policy_dir")
    policy_paths = lifecycle_result.artifacts.get("policy_paths") or []

    baseline = lifecycle_result.baseline
    scan_results = lifecycle_result.scan_results
    rejit_result = lifecycle_result.rejit_result or {"applied": False, "reason": "reJIT did not run"}
    post_rejit = lifecycle_result.post_rejit
    comparison = compare_phases(baseline, post_rejit)
    error_message = ""
    if not rejit_result.get("applied"):
        error_message = str(rejit_result.get("error") or rejit_result.get("reason") or "").strip()
        if not error_message:
            error_message = "Tetragon reJIT did not apply"
    elif post_rejit is None:
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
        "policy_dir": policy_dir,
        "policy_paths": [str(path) for path in policy_paths],
        "config": dict(config),
        "tetragon_programs": lifecycle_result.artifacts.get("tetragon_programs") or [],
        "selected_tetragon_programs": lifecycle_result.artifacts.get("selected_tetragon_programs") or [],
        "apply_tetragon_programs": lifecycle_result.artifacts.get("apply_tetragon_programs") or [],
        "agent_logs": runner.process_output,
        "preflight": preflight,
        "baseline": baseline,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "rejit_result": rejit_result,
        "post_rejit": post_rejit,
        "programs": build_program_summary(scan_results, baseline, post_rejit),
        "comparison": comparison,
        "limitations": limitations,
    }
    if error_message:
        payload["error_message"] = error_message
    return payload


def run_tetragon_case(args: argparse.Namespace) -> dict[str, object]:
    bpftool = str(Path(args.bpftool).resolve()) if Path(args.bpftool).exists() else str(args.bpftool)
    os.environ["BPFTOOL_BIN"] = bpftool
    if Path(bpftool).exists():
        os.environ["PATH"] = f"{Path(bpftool).parent}:{os.environ.get('PATH', '')}"

    config = load_config(Path(args.config).resolve())
    duration_s = int(
        args.duration
        or (
            int(config.get("smoke_duration_s", DEFAULT_SMOKE_DURATION_S) or DEFAULT_SMOKE_DURATION_S)
            if args.smoke
            else int(config.get("measurement_duration_s", DEFAULT_DURATION_S) or DEFAULT_DURATION_S)
        )
    )
    preflight_duration_s = int(config.get("preflight_duration_s", 0) or 0)
    require_program_activity = bool(config.get("require_program_activity", False))
    tetragon_extra_args = [
        str(value).strip()
        for value in (config.get("tetragon_extra_args") or [])
        if str(value).strip()
    ]
    workloads = workload_specs_from_config(config)
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)

    setup_result = {
        "returncode": 0,
        "tetragon_binary": None,
        "tetra_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    tetragon_binary = resolve_tetragon_binary(args.tetragon_binary, setup_result)
    if tetragon_binary is None:
        setup_result = run_setup_script(Path(args.setup_script).resolve())

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Setup script returned non-zero; only the real Tetragon binary path was attempted.")

    tetragon_binary = resolve_tetragon_binary(args.tetragon_binary, setup_result)
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

    if require_program_activity and preflight_duration_s <= 0:
        limitations.append("require_program_activity requires preflight_duration_s > 0.")
        return error_payload(
            config=config,
            tetragon_binary=tetragon_binary,
            duration_s=duration_s,
            smoke=bool(args.smoke),
            setup_result=setup_result,
            error_message="require_program_activity requires preflight_duration_s > 0",
            limitations=limitations,
        )

    with enable_bpf_stats():
        try:
            return daemon_payload(
                config=config,
                daemon_binary=daemon_binary,
                tetragon_binary=tetragon_binary,
                tetragon_extra_args=tetragon_extra_args,
                workloads=workloads,
                duration_s=duration_s,
                preflight_duration_s=preflight_duration_s,
                require_program_activity=require_program_activity,
                smoke=bool(args.smoke),
                load_timeout=int(args.load_timeout),
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


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Tetragon real end-to-end benchmark.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--tetragon-binary")
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--runner", default=str(ROOT_DIR / "runner" / "build" / "micro_exec"))
    parser.add_argument("--bpftool", default=DEFAULT_BPFTOOL)
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=DEFAULT_LOAD_TIMEOUT_S)
    parser.add_argument("--timeout", type=int, default=DEFAULT_TIMEOUT_S)
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    daemon_binary = Path(args.daemon).resolve()
    with DaemonSession.start(daemon_binary) as daemon_session:
        args._prepared_daemon_session = prepare_daemon_session(daemon_session, daemon_binary=daemon_binary)
        payload = run_tetragon_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "tetragon")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve(), build_markdown)
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
