#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import re
import statistics
import sys
import threading
import time
from dataclasses import dataclass
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
    write_json,
    write_text,
)
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from runner.libs.rejit import benchmark_rejit_enabled_passes  # noqa: E402
from runner.libs.workload import (  # noqa: E402
    WorkloadResult,
    run_dd_read_load,
    run_exec_storm,
    run_scheduler_load,
    run_tcp_connect_load,
)
from e2e.case_common import (  # noqa: E402
    CaseLifecycleState,
    attach_pending_result_metadata,
    host_metadata,
    percent_delta,
    run_case_lifecycle,
)


DEFAULT_SCRIPT_DIR = Path(__file__).with_name("scripts")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "bpftrace")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "bpftrace-real-e2e.md"
DEFAULT_REPORT_MD = ROOT_DIR / "docs" / "tmp" / "bpftrace-real-e2e-report.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_DURATION_S = 30
MIN_BPFTRACE_VERSION = (0, 16, 0)


@dataclass(frozen=True, slots=True)
class ScriptSpec:
    name: str
    script_path: Path
    description: str
    expected_programs: int
    workload_kind: str


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="tcplife",
        script_path=DEFAULT_SCRIPT_DIR / "tcplife.bt",
        description="kprobe tcp_set_state: TCP session lifespan with IPv4/IPv6 struct field access, bswap, ntop, 3 maps",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
    ScriptSpec(
        name="biosnoop",
        script_path=DEFAULT_SCRIPT_DIR / "biosnoop.bt",
        description="tracepoint block_io_start/done: per-I/O latency with tuple-keyed maps and bitwise ops (dev >> 20)",
        expected_programs=2,
        workload_kind="dd_read",
    ),
    ScriptSpec(
        name="runqlat",
        script_path=DEFAULT_SCRIPT_DIR / "runqlat.bt",
        description="tracepoint sched_wakeup/wakeup_new/switch: run queue latency histogram, 3 probes",
        expected_programs=3,
        workload_kind="scheduler",
    ),
    ScriptSpec(
        name="tcpretrans",
        script_path=DEFAULT_SCRIPT_DIR / "tcpretrans.bt",
        description="kprobe tcp_retransmit_skb: TCP retransmit tracing with 12-entry state string map, ntop/bswap",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
    ScriptSpec(
        name="capable",
        script_path=DEFAULT_SCRIPT_DIR / "capable.bt",
        description="kprobe cap_capable: security capability checks with 41-entry string map lookup",
        expected_programs=1,
        workload_kind="exec_storm",
    ),
    ScriptSpec(
        name="vfsstat",
        script_path=DEFAULT_SCRIPT_DIR / "vfsstat.bt",
        description="kprobe vfs_read*/write*/fsync/open/create: per-function counters with interval printing",
        expected_programs=6,
        workload_kind="dd_read",
    ),
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the real end-to-end bpftrace benchmark case.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--report-md", default=str(DEFAULT_REPORT_MD))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--duration", type=int, default=30)
    parser.add_argument("--smoke-duration", type=int, default=5)
    parser.add_argument("--attach-timeout", type=int, default=20)
    parser.add_argument("--script", action="append", dest="scripts")
    parser.add_argument("--smoke", action="store_true")
    return parser.parse_args()


def prepend_guest_tools_to_path() -> None:
    preferred = "/usr/local/sbin"
    current = os.environ.get("PATH", "")
    parts = [part for part in current.split(os.pathsep) if part]
    if preferred not in parts:
        os.environ["PATH"] = preferred + (os.pathsep + current if current else "")


def parse_version(text: str) -> tuple[int, int, int] | None:
    match = re.search(r"(\d+)\.(\d+)(?:\.(\d+))?", text)
    if not match:
        return None
    major, minor, patch = match.groups()
    return int(major), int(minor), int(patch or 0)


def version_at_least(version: tuple[int, int, int] | None, minimum: tuple[int, int, int]) -> bool:
    return version is not None and version >= minimum


def ensure_artifacts(runner_binary: Path, daemon_binary: Path) -> None:
    if not runner_binary.exists():
        raise RuntimeError(f"micro_exec not found: {runner_binary}")
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def ensure_required_tools() -> dict[str, object]:
    bpftrace_path = which("bpftrace")
    bpftool_path = which("bpftool")
    if bpftrace_path is None:
        raise RuntimeError("bpftrace is required but not present in PATH")
    if bpftool_path is None:
        raise RuntimeError("bpftool is required but not present in PATH")

    version_result = run_command(["bpftrace", "--version"], timeout=30)
    version_text = (version_result.stdout or version_result.stderr).strip()
    version = parse_version(version_text)
    if not version_at_least(version, MIN_BPFTRACE_VERSION):
        raise RuntimeError(
            f"bpftrace {version_text or 'unknown'} does not meet the required >= "
            f"{MIN_BPFTRACE_VERSION[0]}.{MIN_BPFTRACE_VERSION[1]}"
        )

    bpftool_version = run_command(["bpftool", "version"], timeout=30)
    return {
        "bpftrace_path": bpftrace_path,
        "bpftrace_version_text": version_text,
        "bpftrace_version": version,
        "bpftool_path": bpftool_path,
        "bpftool_version_text": tail_text(bpftool_version.stdout or bpftool_version.stderr, max_lines=3),
        "stress_ng_path": which("stress-ng"),
        "fio_path": which("fio"),
        "curl_path": which("curl"),
    }


def selected_scripts(args: argparse.Namespace) -> list[ScriptSpec]:
    if args.smoke:
        return [next(spec for spec in SCRIPTS if spec.name == "capable")]
    if not args.scripts:
        return list(SCRIPTS)
    wanted = {name.strip() for name in args.scripts if name and name.strip()}
    return [spec for spec in SCRIPTS if spec.name in wanted]


def wait_for_attached_programs(
    process: Any,
    *,
    expected_count: int,
    timeout_s: int,
) -> list[dict[str, object]]:
    deadline = time.monotonic() + timeout_s
    last_nonempty: list[dict[str, object]] = []
    stable_ids: tuple[int, ...] | None = None
    stable_rounds = 0
    while time.monotonic() < deadline:
        matches = find_bpf_programs(int(process.pid or 0))
        if matches:
            last_nonempty = matches
            ids = tuple(int(item.get("id", 0)) for item in matches)
            if ids == stable_ids:
                stable_rounds += 1
            else:
                stable_ids = ids
                stable_rounds = 1
            if len(matches) >= expected_count and stable_rounds >= 2:
                return matches
        elif process.poll() is not None and not last_nonempty:
            break
        time.sleep(0.5)
    return last_nonempty


def aggregate_site_totals(records: Mapping[int, Mapping[str, object]]) -> dict[str, int]:
    totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    for record in records.values():
        counts = record.get("sites") or record.get("counts") or {}
        for field in totals:
            totals[field] += int(counts.get(field, 0) or 0)
    return totals


def run_named_workload(kind: str, duration_s: int) -> WorkloadResult:
    if kind == "tcp_connect":
        return run_tcp_connect_load(duration_s)
    if kind == "dd_read":
        return run_dd_read_load(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    if kind == "exec_storm":
        return run_exec_storm(duration_s, rate=2)
    raise RuntimeError(f"unsupported workload kind: {kind}")


def measure_workload(
    workload_kind: str,
    duration_s: int,
    prog_ids: Sequence[int],
    *,
    agent_pid: int,
    initial_stats: Mapping[int, Mapping[str, object]] | None = None,
) -> dict[str, object]:
    before_bpf = {int(key): dict(value) for key, value in (initial_stats or sample_bpf_stats(list(prog_ids))).items()}
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    threads: list[threading.Thread] = []

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

    try:
        workload_result = run_named_workload(workload_kind, duration_s)
    finally:
        for thread in threads:
            thread.join()

    after_bpf = sample_bpf_stats(list(prog_ids))
    bpf_delta = compute_delta(before_bpf, after_bpf)
    agent_cpu = cpu_holder.get(agent_pid, {})
    total_pct = None
    if agent_cpu:
        total_pct = float(agent_cpu.get("user_pct", 0.0)) + float(agent_cpu.get("sys_pct", 0.0))

    return {
        "workload": workload_result.to_dict(),
        "initial_stats": {str(key): value for key, value in before_bpf.items()},
        "final_stats": {str(key): value for key, value in after_bpf.items()},
        "bpf": bpf_delta,
        "agent_cpu": {
            "user_pct": agent_cpu.get("user_pct"),
            "sys_pct": agent_cpu.get("sys_pct"),
            "total_pct": total_pct,
        },
        "system_cpu": system_cpu_holder,
    }


def finalize_process_output(process: Any) -> dict[str, object]:
    stdout = ""
    stderr = ""
    try:
        stdout, stderr = process.communicate(timeout=1)
    except Exception:
        if process.stdout is not None:
            try:
                stdout = process.stdout.read()
            except Exception:
                stdout = ""
        if process.stderr is not None:
            try:
                stderr = process.stderr.read()
            except Exception:
                stderr = ""
    return {
        "returncode": process.returncode,
        "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
    }


def run_phase(
    spec: ScriptSpec,
    *,
    duration_s: int,
    attach_timeout: int,
    daemon_binary: Path,
) -> tuple[dict[str, object], dict[str, object] | None]:
    """Run baseline then daemon-apply then rejit measurement for one bpftrace script.

    Returns (baseline, rejit) where rejit is None only when ReJIT was not applicable.
    """
    # TODO: Move the bpftrace session setup/start/workload/stop hooks into
    # runner/libs/app_runners/bpftrace.py so corpus and E2E share one lifecycle.
    programs: list[dict[str, object]] = []
    prog_ids: list[int] = []
    process_output: dict[str, object] = {}

    def setup() -> dict[str, object]:
        return {}

    def start(_: object) -> CaseLifecycleState:
        process = start_agent("bpftrace", ["-q", str(spec.script_path)])
        return CaseLifecycleState(runtime=process)

    def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
        process = lifecycle.runtime
        nonlocal programs
        nonlocal prog_ids
        if phase_name == "baseline" and not lifecycle.target_prog_ids:
            programs = wait_for_attached_programs(
                process,
                expected_count=spec.expected_programs,
                timeout_s=attach_timeout,
            )
            if not programs:
                return {
                    "status": "error",
                    "reason": "bpftrace did not attach any programs",
                    "measurement": None,
                }
            prog_ids = [int(program["id"]) for program in programs]
            lifecycle.target_prog_ids = list(prog_ids)
            lifecycle.apply_prog_ids = list(prog_ids)
        if not lifecycle.target_prog_ids:
            return {"status": "error", "reason": "no BPF programs are attached", "measurement": None}
        return {
            "status": "ok",
            "reason": "",
            "measurement": measure_workload(
                spec.workload_kind,
                duration_s,
                lifecycle.target_prog_ids,
                agent_pid=int(process.pid or 0),
                initial_stats=sample_bpf_stats(lifecycle.target_prog_ids),
            ),
        }

    def stop(_: object, lifecycle: CaseLifecycleState) -> None:
        nonlocal process_output
        process = lifecycle.runtime
        stop_agent(process, timeout=8)
        process_output = finalize_process_output(process)

    def cleanup(_: object) -> None:
        return None

    baseline_measurement: dict[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    rejit_apply: dict[str, object] | None = None
    post_measurement: dict[str, object] | None = None
    baseline_status = "error"
    baseline_reason = ""
    try:
        lifecycle_result = run_case_lifecycle(
            daemon_binary=daemon_binary,
            setup=setup,
            start=start,
            workload=workload,
            stop=stop,
            cleanup=cleanup,
            enabled_passes=benchmark_rejit_enabled_passes(),
        )
        if lifecycle_result.baseline is not None:
            baseline_status = str(lifecycle_result.baseline.get("status") or "error")
            baseline_reason = str(lifecycle_result.baseline.get("reason") or "")
            measurement = lifecycle_result.baseline.get("measurement")
            if isinstance(measurement, Mapping):
                baseline_measurement = dict(measurement)
        scan_results = lifecycle_result.scan_results
        rejit_apply = lifecycle_result.rejit_result
        if isinstance(lifecycle_result.post_rejit, Mapping):
            measurement = lifecycle_result.post_rejit.get("measurement")
            if isinstance(measurement, Mapping):
                post_measurement = dict(measurement)
    except Exception as exc:
        baseline_reason = str(exc)

    site_totals = aggregate_site_totals(scan_results) if scan_results else {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    baseline: dict[str, object] = {
        "phase": "baseline",
        "status": baseline_status,
        "reason": baseline_reason,
        "programs": programs,
        "prog_ids": prog_ids,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "site_totals": site_totals,
        "measurement": baseline_measurement,
        "process": process_output,
    }
    if baseline["status"] != "ok" and not baseline["reason"]:
        stderr_tail = str(process_output.get("stderr_tail") or "")
        stdout_tail = str(process_output.get("stdout_tail") or "")
        baseline["reason"] = stderr_tail or stdout_tail or "unknown failure"

    rejit: dict[str, object] | None = None
    if baseline["status"] == "ok" and rejit_apply is not None:
        if rejit_apply.get("applied"):
            rejit = {
                "phase": "post_rejit",
                "status": "ok",
                "reason": "",
                "programs": programs,
                "prog_ids": prog_ids,
                "scan_results": baseline["scan_results"],
                "site_totals": baseline["site_totals"],
                "rejit_result": rejit_apply,
                "measurement": post_measurement,
                "process": process_output,
            }
        else:
            rejit_error = str(rejit_apply.get("error") or "").strip()
            if rejit_error:
                rejit = {
                    "phase": "post_rejit",
                    "status": "error",
                    "reason": rejit_error,
                    "programs": programs,
                    "prog_ids": prog_ids,
                    "scan_results": baseline["scan_results"],
                    "site_totals": baseline["site_totals"],
                    "rejit_result": rejit_apply,
                    "measurement": None,
                    "process": process_output,
                }
    return baseline, rejit


def summarize_script(spec: ScriptSpec, baseline: Mapping[str, object], rejit: Mapping[str, object] | None) -> dict[str, object]:
    baseline_measurement = baseline.get("measurement") or {}
    rejit_measurement = (rejit or {}).get("measurement") or {}
    stock_avg_ns = ((baseline_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    rejit_avg_ns = ((rejit_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    workload_ops_baseline = ((baseline_measurement.get("workload") or {}).get("ops_per_sec"))
    workload_ops_rejit = ((rejit_measurement.get("workload") or {}).get("ops_per_sec"))
    cpu_baseline = ((baseline_measurement.get("agent_cpu") or {}).get("total_pct"))
    cpu_rejit = ((rejit_measurement.get("agent_cpu") or {}).get("total_pct"))
    sites = int(((rejit or {}).get("site_totals") or baseline.get("site_totals") or {}).get("total_sites", 0) or 0)
    speedup = None
    if stock_avg_ns not in (None, 0) and rejit_avg_ns not in (None, 0):
        speedup = float(stock_avg_ns) / float(rejit_avg_ns)

    note = ""
    if baseline.get("status") != "ok":
        note = str(baseline.get("reason") or "")
    elif rejit and rejit.get("status") != "ok":
        note = str(rejit.get("reason") or "")

    return {
        "name": spec.name,
        "sites": sites,
        "stock_avg_ns": stock_avg_ns,
        "rejit_avg_ns": rejit_avg_ns,
        "speedup": speedup,
        "workload_ops_baseline": workload_ops_baseline,
        "workload_ops_rejit": workload_ops_rejit,
        "cpu_baseline": cpu_baseline,
        "cpu_rejit": cpu_rejit,
        "avg_ns_delta_pct": percent_delta(stock_avg_ns, rejit_avg_ns),
        "workload_ops_delta_pct": percent_delta(workload_ops_baseline, workload_ops_rejit),
        "cpu_delta_pct": percent_delta(cpu_baseline, cpu_rejit),
        "baseline_status": baseline.get("status"),
        "rejit_status": None if rejit is None else rejit.get("status"),
        "note": note,
    }


def format_float(value: object, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.{digits}f}"


def format_ratio(value: object) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.3f}x"


def markdown_table(headers: Sequence[str], rows: Sequence[Sequence[object]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def geomean(values: Sequence[object]) -> float | None:
    positive = [float(value) for value in values if isinstance(value, (int, float)) and float(value) > 0]
    if not positive:
        return None
    return statistics.geometric_mean(positive)


def collect_record_errors(records: Sequence[Mapping[str, object]]) -> list[str]:
    errors: list[str] = []
    for record in records:
        name = str(record.get("name") or "unknown")
        baseline = record.get("baseline") or {}
        if isinstance(baseline, Mapping) and str(baseline.get("status") or "") == "error":
            reason = str(baseline.get("reason") or "unknown failure")
            errors.append(f"{name} baseline failed: {reason}")
        rejit = record.get("rejit") or {}
        if isinstance(rejit, Mapping) and str(rejit.get("status") or "") == "error":
            reason = str(rejit.get("reason") or "unknown failure")
            errors.append(f"{name} rejit failed: {reason}")
    return errors


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# bpftrace Real End-to-End Benchmark",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Host kernel: `{payload['host']['kernel']}`",
        f"- bpftrace: `{payload['tool_versions']['bpftrace_version_text']}`",
        f"- bpftool: `{payload['tool_versions']['bpftool_version_text']}`",
        f"- Daemon: `{payload['daemon']}`",
        "",
        "## Summary",
        "",
        f"- Scripts selected: `{len(payload['selected_scripts'])}`",
        f"- Baseline successes: `{payload['summary']['baseline_successes']}`",
        f"- ReJIT successes: `{payload['summary']['rejit_successes']}`",
        f"- Eligible-site scripts: `{payload['summary']['scripts_with_sites']}`",
        f"- Aggregate sites: `{payload['summary']['site_totals']['total_sites']}` "
        f"(cmov={payload['summary']['site_totals']['cmov_sites']}, "
        f"wide={payload['summary']['site_totals']['wide_sites']}, "
        f"rotate={payload['summary']['site_totals']['rotate_sites']}, "
        f"lea={payload['summary']['site_totals']['lea_sites']})",
        f"- Geomean speedup: `{format_ratio(payload['summary']['speedup_geomean'])}`",
        "",
        "## Per-Script",
        "",
    ]

    rows = []
    for record in payload["records"]:
        summary = record["summary"]
        rows.append(
            [
                summary["name"],
                summary["sites"],
                format_float(summary["stock_avg_ns"]),
                format_float(summary["rejit_avg_ns"]),
                format_ratio(summary["speedup"]),
                format_float(summary["workload_ops_baseline"]),
                format_float(summary["workload_ops_rejit"]),
                format_float(summary["cpu_baseline"]),
                format_float(summary["cpu_rejit"]),
                summary["note"] or "ok",
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Script",
                "Sites",
                "Stock ns",
                "ReJIT ns",
                "Speedup",
                "Ops/s Stock",
                "Ops/s ReJIT",
                "CPU% Stock",
                "CPU% ReJIT",
                "Notes",
            ],
            rows,
        )
    )
    lines.extend(["", "## Comparison", ""])
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- {summary['name']}: avg_ns_delta={format_float(summary['avg_ns_delta_pct'])}%, "
            f"ops_delta={format_float(summary['workload_ops_delta_pct'])}%, "
            f"cpu_delta={format_float(summary['cpu_delta_pct'])}%"
        )
    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.",
            "- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.",
            "- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.",
            "",
        ]
    )
    return "\n".join(lines)


def build_report(payload: Mapping[str, object]) -> str:
    improved = [
        record["summary"]["name"]
        for record in payload["records"]
        if isinstance(record["summary"].get("avg_ns_delta_pct"), (int, float))
        and float(record["summary"]["avg_ns_delta_pct"]) < 0
    ]
    regressed = [
        record["summary"]["name"]
        for record in payload["records"]
        if isinstance(record["summary"].get("avg_ns_delta_pct"), (int, float))
        and float(record["summary"]["avg_ns_delta_pct"]) > 0
    ]
    lines = [
        "# bpftrace Real E2E Report",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Run mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Guest kernel: `{payload['host']['kernel']}`",
        f"- bpftrace version: `{payload['tool_versions']['bpftrace_version_text']}`",
        "",
        "## Outcome",
        "",
        "- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.",
        f"- Scripts with detected sites: `{payload['summary']['scripts_with_sites']}`; aggregate site count: `{payload['summary']['site_totals']['total_sites']}`.",
        f"- Geomean BPF speedup across scripts with both baseline and ReJIT data: `{format_ratio(payload['summary']['speedup_geomean'])}`.",
        "",
        "## Per-Script",
        "",
    ]
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- `{summary['name']}`: sites={summary['sites']}, stock_ns={format_float(summary['stock_avg_ns'])}, "
            f"rejit_ns={format_float(summary['rejit_avg_ns'])}, speedup={format_ratio(summary['speedup'])}, "
            f"ops_stock={format_float(summary['workload_ops_baseline'])}, ops_rejit={format_float(summary['workload_ops_rejit'])}, "
            f"cpu_stock={format_float(summary['cpu_baseline'])}, cpu_rejit={format_float(summary['cpu_rejit'])}"
        )
        if summary["note"]:
            lines.append(f"- Note: {summary['note']}")
    lines.extend(
        [
            "",
            "## Comparison",
            "",
        ]
    )
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- `{summary['name']}` delta: avg_ns={format_float(summary['avg_ns_delta_pct'])}%, "
            f"ops={format_float(summary['workload_ops_delta_pct'])}%, "
            f"cpu={format_float(summary['cpu_delta_pct'])}%"
        )
    lines.extend(
        [
            "",
            "## Interpretation",
            "",
            "- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.",
            f"- Eligible CMOV-bearing scripts split by workload: improved={improved or ['none']}, regressed={regressed or ['none']}. The overall geomean across scripts with stock+ReJIT data is `{format_ratio(payload['summary']['speedup_geomean'])}`.",
            "- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.",
            "",
        ]
    )
    return "\n".join(lines)


def run_case(args: argparse.Namespace) -> dict[str, object]:
    prepend_guest_tools_to_path()

    runner_binary = Path(args.runner).resolve()
    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(runner_binary, daemon_binary)
    tool_versions = ensure_required_tools()

    scripts = selected_scripts(args)
    if not scripts:
        raise RuntimeError("no scripts selected")

    duration_s = int(args.smoke_duration if args.smoke else (args.duration or DEFAULT_DURATION_S))
    records: list[dict[str, object]] = []
    with enable_bpf_stats():
        for spec in scripts:
            baseline, rejit = run_phase(
                spec,
                duration_s=duration_s,
                attach_timeout=int(args.attach_timeout),
                daemon_binary=daemon_binary,
            )
            summary = summarize_script(spec, baseline, rejit)
            records.append(
                {
                    "name": spec.name,
                    "description": spec.description,
                    "script_path": str(spec.script_path),
                    "script_text": spec.script_path.read_text(),
                    "baseline": baseline,
                    "rejit": rejit,
                    "summary": summary,
                }
            )

    site_totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    speedups: list[float] = []
    baseline_successes = 0
    rejit_successes = 0
    scripts_with_sites = 0
    for record in records:
        baseline = record.get("baseline") or {}
        rejit = record.get("rejit") or {}
        summary = record.get("summary") or {}
        if baseline.get("status") == "ok":
            baseline_successes += 1
        if rejit.get("status") == "ok":
            rejit_successes += 1
        if int((summary.get("sites") or 0)) > 0:
            scripts_with_sites += 1
        counts = baseline.get("site_totals") or rejit.get("site_totals") or {}
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = summary.get("speedup")
        if isinstance(speedup, (int, float)) and float(speedup) > 0:
            speedups.append(float(speedup))

    errors = collect_record_errors(records)

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "selected_scripts": [spec.name for spec in scripts],
        "runner": str(runner_binary),
        "daemon": str(daemon_binary),
        "host": host_metadata(),
        "tool_versions": tool_versions,
        "records": records,
        "summary": {
            "baseline_successes": baseline_successes,
            "rejit_successes": rejit_successes,
            "scripts_with_sites": scripts_with_sites,
            "site_totals": site_totals,
            "speedup_geomean": geomean(speedups),
        },
    }
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload


def main() -> None:
    args = parse_args()
    payload = run_case(args)
    attach_pending_result_metadata(payload)

    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "bpftrace")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    report_md = Path(args.report_md).resolve()
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload) + "\n")
    write_text(report_md, build_report(payload) + "\n")
    print(f"[ok] wrote {output_json}")
    print(f"[ok] wrote {output_md}")
    print(f"[ok] wrote {report_md}")


if __name__ == "__main__":
    main()
