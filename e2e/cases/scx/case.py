from __future__ import annotations

import argparse
import json
import os
import statistics
import sys
import threading
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    run_command,
    smoke_output_path,
    tail_text,
    which,
)
from runner.libs.app_runners.scx import ScxRunner, preferred_path, read_scx_ops, read_scx_state  # noqa: E402
from runner.libs.metrics import sample_cpu_usage, sample_total_cpu_usage  # noqa: E402
from runner.libs.rejit import benchmark_rejit_enabled_passes  # noqa: E402
from runner.libs.vm import run_in_vm, write_guest_script  # noqa: E402
from runner.libs.workload import WorkloadResult  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    host_metadata,
    open_prepared_daemon_session,
    summarize_numbers,
    percent_delta,
    percentile,
    persist_results,
    run_case_lifecycle,
)


DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "scx")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "scx-e2e.md"
DEFAULT_SCX_BINARY = ROOT_DIR / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"
DEFAULT_SCX_REPO = ROOT_DIR / "runner" / "repos" / "scx"
DEFAULT_SCX_OBJECT = ROOT_DIR / "corpus" / "build" / "scx" / "scx_rusty_main.bpf.o"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL = ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BPFTOOL = Path("/usr/local/sbin/bpftool")
DEFAULT_LOAD_TIMEOUT = 20
DEFAULT_DURATION_S = 30
DEFAULT_SMOKE_DURATION_S = 10


def read_proc_stat_fields() -> dict[str, int]:
    fields = {"ctxt": 0, "processes": 0, "procs_running": 0}
    try:
        lines = Path("/proc/stat").read_text().splitlines()
    except OSError:
        return fields
    for line in lines:
        parts = line.split()
        if len(parts) < 2 or parts[0] not in fields:
            continue
        try:
            fields[parts[0]] = int(parts[1])
        except ValueError:
            continue
    return fields


def aggregate_sites(records: Mapping[int | str, Mapping[str, object]]) -> dict[str, int]:
    totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    for record in records.values():
        sites = record.get("sites") or record.get("counts") or {}
        if not isinstance(sites, Mapping):
            continue
        for field in totals:
            totals[field] += int(sites.get(field, 0) or 0)
    return totals


def ensure_artifacts(daemon_binary: Path, scheduler_binary: Path, scx_repo: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")
    if not scheduler_binary.exists():
        raise RuntimeError(f"scx_rusty binary not found: {scheduler_binary}")
    if not scx_repo.exists():
        raise RuntimeError(f"scx repo missing: {scx_repo}")


def workload_specs() -> list[dict[str, str]]:
    specs: list[dict[str, str]] = []
    if which("hackbench"):
        specs.append({"name": "hackbench", "kind": "hackbench", "metric": "runs/s"})
    if which("stress-ng"):
        specs.append({"name": "stress-ng-cpu", "kind": "stress_ng_cpu", "metric": "bogo-ops/s"})
    if which("sysbench"):
        specs.append({"name": "sysbench-cpu", "kind": "sysbench_cpu", "metric": "events/s"})
    return specs


def measure_workload(
    runner: ScxRunner,
    workload_spec: Mapping[str, object],
    duration_s: int,
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    before_proc = read_proc_stat_fields()
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

    runner.workload_spec = dict(workload_spec)
    workload_result = runner.run_workload(duration_s)
    extra = dict(runner.last_workload_extra)

    for thread in threads:
        thread.join()

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
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_cpu_total,
        },
        "system_cpu": system_cpu_holder,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
    }


def summarize_phase(workloads: Sequence[Mapping[str, object]]) -> dict[str, object]:
    return {
        "throughput": summarize_numbers([record.get("ops_per_sec") for record in workloads]),
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
    runner: ScxRunner,
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    records = [
        measure_workload(runner, workload_spec, duration_s, agent_pid=agent_pid)
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
        workload_rows.append(
            {
                "name": name,
                "throughput_delta_pct": percent_delta(before.get("ops_per_sec"), after.get("ops_per_sec")),
                "context_switches_delta_pct": percent_delta(
                    before.get("context_switches_per_sec"),
                    after.get("context_switches_per_sec"),
                ),
                "latency_p50_delta_pct": percent_delta(before.get("latency_ms_p50"), after.get("latency_ms_p50")),
                "agent_cpu_delta_pct": percent_delta(before_cpu, after_cpu),
            }
        )
    return {"comparable": True, "workloads": workload_rows}


def probe_bpftool_register(object_path: Path, bpftool_binary: Path) -> dict[str, object]:
    before_state = read_scx_state()
    completed = run_command(
        [str(bpftool_binary), "struct_ops", "register", str(object_path)],
        check=False,
        timeout=60,
    )
    after_state = read_scx_state()
    after_ops = read_scx_ops()
    prog_count = 0
    prog_show = run_command([str(bpftool_binary), "-j", "-p", "prog", "show"], check=False, timeout=30)
    if prog_show.returncode == 0:
        try:
            payload = json.loads(prog_show.stdout)
        except json.JSONDecodeError:
            payload = []
        if isinstance(payload, list):
            prog_count = sum(
                1
                for item in payload
                if isinstance(item, Mapping) and str(item.get("type", "")) == "struct_ops"
            )
    return {
        "attempted": True,
        "bpftool": str(bpftool_binary),
        "returncode": completed.returncode,
        "before_state": before_state,
        "after_state": after_state,
        "after_ops": after_ops,
        "struct_ops_program_count_after": prog_count,
        "usable": completed.returncode == 0 and after_state == "enabled" and bool(after_ops),
        "stdout_tail": tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    }


def build_markdown(payload: Mapping[str, object]) -> str:
    status = str(payload.get("status") or "")
    lines = [
        "# scx_rusty End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Kernel: `{payload['host']['kernel']}`",
        f"- Scheduler binary: `{payload.get('scheduler_binary') or 'missing'}`",
        "",
        "## Preflight",
        "",
    ]
    preflight = payload.get("preflight") or {}
    lines.append(f"- sched_ext state before load: `{preflight.get('state_before')}`")
    lines.append(f"- workloads selected: `{preflight.get('available_workloads')}`")
    lines.append(
        f"- raw bpftool register usable: `{((preflight.get('bpftool_register_probe') or {}).get('usable'))}`"
    )
    lines.append(
        f"- runtime counters exposed via bpftool: `{preflight.get('runtime_counters_available')}`"
    )
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
    site_totals = ((payload.get("scan_summary") or {}).get("site_totals") or {})
    lines.append(
        f"- Programs: `{len(payload.get('scheduler_programs') or [])}`; "
        f"sites total=`{site_totals.get('total_sites')}`, "
        f"cmov=`{site_totals.get('cmov_sites')}`, "
        f"lea=`{site_totals.get('lea_sites')}`"
    )
    lines.append(f"- Active ops: `{payload.get('scheduler_ops') or []}`")
    lines.extend(["", "## Baseline", ""])
    baseline = payload.get("baseline") or {}
    for workload in baseline.get("workloads") or []:
        lines.append(
            f"- {workload['name']}: throughput={workload.get('ops_per_sec')} {workload['metric']}, "
            f"lat_p50_ms={workload.get('latency_ms_p50')}, "
            f"ctx/s={workload.get('context_switches_per_sec')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}"
        )
    post = payload.get("post_rejit")
    if post:
        lines.extend(["", "## Post-ReJIT", ""])
        for workload in post.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: throughput={workload.get('ops_per_sec')} {workload['metric']}, "
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
    os.environ["PATH"] = preferred_path()

    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
    scheduler_binary = Path(args.scheduler_binary).resolve()
    scx_repo = Path(args.scx_repo).resolve()
    object_path = Path(args.scheduler_object).resolve()
    daemon_binary = Path(args.daemon).resolve()
    bpftool_binary = Path(args.bpftool).resolve()
    ensure_artifacts(daemon_binary, scheduler_binary, scx_repo)

    workloads = workload_specs()
    if not workloads:
        raise RuntimeError("no scheduler workloads are available; expected hackbench, stress-ng, or sysbench")

    limitations: list[str] = []
    state_before = read_scx_state()
    bpftool_probe = probe_bpftool_register(object_path, bpftool_binary)
    if not bpftool_probe.get("usable"):
        limitations.append(
            "Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here."
        )

    baseline: dict[str, object] | None = None
    post_rejit: dict[str, object] | None = None
    rejit_result: dict[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    scheduler_programs: list[dict[str, object]] = []
    scheduler_snapshot: dict[str, object] = {}
    scheduler_ops: list[str] = []
    runtime_counters_available = False
    loader_error: str | None = None

    try:
        def setup() -> dict[str, object]:
            return {}

        def start(_: object) -> CaseLifecycleState:
            runner = ScxRunner(
                object_path=object_path,
                scheduler_binary=scheduler_binary,
                scheduler_extra_args=args.scheduler_extra_arg or [],
                load_timeout_s=int(args.load_timeout),
            )
            runner.start()
            return CaseLifecycleState(
                runtime=runner,
                target_prog_ids=[int(program["id"]) for program in runner.programs],
                artifacts={
                    "scheduler_programs": runner.programs,
                },
            )

        def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
            del phase_name
            runner = lifecycle.runtime
            assert isinstance(runner, ScxRunner)
            return run_phase(runner, workloads, duration_s, agent_pid=runner.pid)

        def stop(_: object, lifecycle: CaseLifecycleState) -> None:
            runner = lifecycle.runtime
            assert isinstance(runner, ScxRunner)
            runner.stop()

        def cleanup(_: object) -> None:
            return None

        with open_prepared_daemon_session(daemon_binary) as daemon_session:
            lifecycle_result = run_case_lifecycle(
                daemon_session=daemon_session,
                setup=setup,
                start=start,
                workload=workload,
                stop=stop,
                cleanup=cleanup,
                enabled_passes=benchmark_rejit_enabled_passes(),
                should_run_post_rejit=lambda result: int(
                    (((result.get("counts") or {}).get("applied_sites", 0)) or 0)
                ) > 0,
            )
        if lifecycle_result.state is None:
            raise RuntimeError("scx lifecycle completed without a live session")
        runner = lifecycle_result.state.runtime
        assert isinstance(runner, ScxRunner)
        scheduler_programs = list(lifecycle_result.artifacts.get("scheduler_programs") or [])
        scheduler_ops = read_scx_ops()
        scheduler_snapshot = dict(runner.process_output)
        runtime_counters_available = any(
            ("run_cnt" in program) or ("run_time_ns" in program)
            for program in scheduler_programs
        )
        if not runtime_counters_available:
            limitations.append(
                "bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable."
            )
        baseline = lifecycle_result.baseline
        scan_results = lifecycle_result.scan_results
        rejit_result = lifecycle_result.rejit_result
        post_rejit = lifecycle_result.post_rejit
    except Exception as exc:
        loader_error = str(exc)
        limitations.append(f"scx_rusty userspace loader failed: {loader_error}")

    mode = "scx_rusty_loader" if baseline is not None else "probe_only"
    scan_summary = {
        "scanned_programs": len(scan_results),
        "site_bearing_programs": sum(
            1
            for record in scan_results.values()
            if int(((record.get("sites") or {}).get("total_sites", 0) or 0)) > 0
        ),
        "site_totals": aggregate_sites(scan_results),
    }

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "ok" if baseline is not None else "error",
        "mode": mode,
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "scheduler_binary": str(scheduler_binary) if scheduler_binary.exists() else None,
        "scheduler_object": str(object_path),
        "scheduler_programs": scheduler_programs,
        "scheduler_ops": scheduler_ops,
        "scheduler_output": scheduler_snapshot,
        "host": host_metadata(),
        "preflight": {
            "state_before": state_before,
            "runtime_counters_available": runtime_counters_available,
            "available_workloads": [spec["name"] for spec in workloads],
            "bpftool_register_probe": bpftool_probe,
            "loader_error": loader_error,
        },
        "baseline": baseline,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "scan_summary": scan_summary,
        "rejit_result": rejit_result if baseline is not None else None,
        "post_rejit": post_rejit,
        "comparison": compare_phases(baseline, post_rejit),
        "limitations": limitations,
        "error_message": loader_error,
    }
    return payload


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the scx_rusty end-to-end benchmark.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--scheduler-binary", default=str(DEFAULT_SCX_BINARY))
    parser.add_argument("--scheduler-object", default=str(DEFAULT_SCX_OBJECT))
    parser.add_argument("--scx-repo", default=str(DEFAULT_SCX_REPO))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--bpftool", default=str(DEFAULT_BPFTOOL))
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=DEFAULT_LOAD_TIMEOUT)
    parser.add_argument("--scheduler-extra-arg", action="append", default=[])
    parser.add_argument("--vm", action="store_true")
    parser.add_argument("--kernel", default=str(DEFAULT_KERNEL))
    parser.add_argument("--cpus", type=int, default=4)
    parser.add_argument("--mem", default="4G")
    parser.add_argument("--timeout", type=int, default=3600)
    return parser


def run_scx_vm(args: argparse.Namespace) -> int:
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "scx")
    else:
        output_json = Path(args.output_json).resolve()
    guest_command = [
        "python3",
        "e2e/cases/scx/case.py",
        "--output-json",
        str(output_json),
        "--output-md",
        str(Path(args.output_md).resolve()),
        "--scheduler-binary",
        str(Path(args.scheduler_binary).resolve()),
        "--scheduler-object",
        str(Path(args.scheduler_object).resolve()),
        "--scx-repo",
        str(Path(args.scx_repo).resolve()),
        "--daemon",
        str(Path(args.daemon).resolve()),
        "--bpftool",
        str(Path(args.bpftool).resolve()),
        "--load-timeout",
        str(int(args.load_timeout)),
    ]
    if args.smoke:
        guest_command.append("--smoke")
    if args.duration is not None:
        guest_command.extend(["--duration", str(int(args.duration))])
    for extra_arg in args.scheduler_extra_arg or []:
        guest_command.extend(["--scheduler-extra-arg", extra_arg])

    guest_script = write_guest_script([guest_command])
    completed = run_in_vm(
        args.kernel,
        guest_script,
        args.cpus,
        args.mem,
        args.timeout,
        action="vm-e2e",
    )
    sys.stdout.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        raise SystemExit(
            f"vng run failed with exit {completed.returncode}: {tail_text(completed.stderr or completed.stdout)}"
        )
    return 0


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    if args.vm:
        return run_scx_vm(args)
    payload = run_scx_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "scx")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve(), build_markdown)
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
