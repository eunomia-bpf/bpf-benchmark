from __future__ import annotations

import argparse
import json
import os
import platform
import re
import shlex
import statistics
import subprocess
import sys
import threading
import time
from collections import deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    chown_to_invoking_user,
    ensure_root,
    run_command,
    smoke_output_path,
    tail_text,
    which,
    write_json,
    write_text,
)
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy  # noqa: E402
from runner.libs.metrics import sample_cpu_usage, sample_total_cpu_usage  # noqa: E402
from runner.libs.recompile import apply_daemon_rejit, scan_programs  # noqa: E402
from runner.libs.vm import run_in_vm, write_guest_script  # noqa: E402
from runner.libs.workload import WorkloadResult  # noqa: E402


DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "scx")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "scx-e2e.md"
DEFAULT_SCX_BINARY = ROOT_DIR / "corpus" / "repos" / "scx" / "target" / "release" / "scx_rusty"
DEFAULT_SCX_REPO = ROOT_DIR / "corpus" / "repos" / "scx"
DEFAULT_SCX_OBJECT = ROOT_DIR / "corpus" / "build" / "scx" / "scx_rusty_main.bpf.o"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "build" / "bpfrejit-daemon"
DEFAULT_KERNEL = ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BPFTOOL = Path("/usr/local/sbin/bpftool")
DEFAULT_LOAD_TIMEOUT = 20
DEFAULT_DURATION_S = 30
DEFAULT_SMOKE_DURATION_S = 10

HACKBENCH_TIME_RE = re.compile(r"Time:\s*([0-9.]+)")
STRESS_NG_CPU_RE = re.compile(
    r"stress-ng: metrc: .*?\bcpu\s+([0-9.]+)\s+([0-9.]+)\s+[0-9.]+\s+[0-9.]+\s+([0-9.]+)"
)
SYSBENCH_EVENTS_RE = re.compile(r"events per second:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_TOTAL_EVENTS_RE = re.compile(r"total number of events:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_LATENCY_AVG_RE = re.compile(r"avg:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_LATENCY_P95_RE = re.compile(r"95th percentile:\s*([0-9.]+)", re.IGNORECASE)


class LineCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            with self._lock:
                self.stdout_tail.append(raw_line.rstrip())
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            with self._lock:
                self.stderr_tail.append(raw_line.rstrip())
        pipe.close()

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


class ScxSchedulerSession:
    def __init__(self, binary: Path, extra_args: Sequence[str], load_timeout: int) -> None:
        self.binary = binary
        self.extra_args = list(extra_args)
        self.load_timeout = int(load_timeout)
        self.process: subprocess.Popen[str] | None = None
        self.collector = LineCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.programs: list[dict[str, object]] = []
        self.command_used: list[str] | None = None

    def __enter__(self) -> "ScxSchedulerSession":
        command_text = " ".join(
            [
                "ulimit -l unlimited >/dev/null 2>&1 || true;",
                "exec",
                shlex.quote(str(self.binary)),
                "--stats",
                "1",
                *[shlex.quote(str(arg)) for arg in self.extra_args],
            ]
        )
        self.command_used = ["bash", "-lc", command_text]
        self.process = start_agent(
            "bash",
            ["-lc", command_text],
            env={"PATH": preferred_path()},
        )
        assert self.process.stdout is not None
        assert self.process.stderr is not None
        self.stdout_thread = threading.Thread(
            target=self.collector.consume_stdout,
            args=(self.process.stdout,),
            daemon=True,
        )
        self.stderr_thread = threading.Thread(
            target=self.collector.consume_stderr,
            args=(self.process.stderr,),
            daemon=True,
        )
        self.stdout_thread.start()
        self.stderr_thread.start()

        healthy = wait_healthy(
            self.process,
            self.load_timeout,
            lambda: read_scx_state() == "enabled" and bool(self._discover_programs()),
        )
        if not healthy:
            snapshot = self.collector.snapshot()
            details = tail_text(
                "\n".join(
                    list(snapshot.get("stderr_tail") or [])
                    + list(snapshot.get("stdout_tail") or [])
                ),
                max_lines=40,
                max_chars=8000,
            )
            self.close()
            raise RuntimeError(f"scx_rusty did not become healthy: {details}")

        self.programs = self._discover_programs()
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def _discover_programs(self) -> list[dict[str, object]]:
        if self.pid is None:
            return []
        programs = [
            item
            for item in find_bpf_programs(self.pid)
            if str(item.get("type", "")) == "struct_ops"
        ]
        programs.sort(key=lambda item: int(item.get("id", 0)))
        return programs

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def preferred_path() -> str:
    current = os.environ.get("PATH", "")
    prefix = "/usr/local/sbin"
    parts = [part for part in current.split(":") if part]
    if prefix in parts:
        return current
    return f"{prefix}:{current}" if current else prefix


def git_sha() -> str:
    try:
        return run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    except Exception:
        return "unknown"


def host_metadata() -> dict[str, object]:
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha(),
    }


def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    filtered = [float(value) for value in values if value is not None]
    if not filtered:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
        }
    return {
        "count": len(filtered),
        "mean": statistics.mean(filtered),
        "median": statistics.median(filtered),
        "min": min(filtered),
        "max": max(filtered),
    }


def percentile(values: Sequence[float], pct: float) -> float | None:
    items = sorted(float(value) for value in values)
    if not items:
        return None
    if len(items) == 1:
        return items[0]
    rank = max(0.0, min(1.0, pct / 100.0)) * (len(items) - 1)
    lower = int(rank)
    upper = min(len(items) - 1, lower + 1)
    weight = rank - lower
    return items[lower] * (1.0 - weight) + items[upper] * weight


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def read_scx_state() -> str:
    path = Path("/sys/kernel/sched_ext/state")
    try:
        return path.read_text().strip()
    except OSError:
        return "missing"


def read_scx_ops() -> list[str]:
    root = Path("/sys/kernel/sched_ext")
    if not root.exists():
        return []
    values: list[str] = []
    for candidate in sorted(root.glob("*/ops")):
        try:
            text = candidate.read_text().strip()
        except OSError:
            continue
        if text:
            values.append(text)
    return values


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


def ensure_artifacts(scanner_binary: Path, scheduler_binary: Path, scx_repo: Path) -> None:
    if not scanner_binary.exists():
        run_command(
            ["cmake", "-S", "daemon", "-B", "daemon/build", "-DCMAKE_BUILD_TYPE=Release"],
            timeout=600,
        )
        run_command(
            ["cmake", "--build", "daemon/build", "--target", "bpfrejit-daemon", "-j"],
            timeout=1800,
        )
    if scheduler_binary.exists():
        return
    if not scx_repo.exists():
        raise RuntimeError(f"scx repo missing: {scx_repo}")
    run_command(
        ["cargo", "build", "--release", "-p", "scx_rusty"],
        cwd=scx_repo,
        timeout=7200,
    )
    if not scheduler_binary.exists():
        raise RuntimeError(f"scx_rusty binary missing after build: {scheduler_binary}")


def workload_specs() -> list[dict[str, str]]:
    specs: list[dict[str, str]] = []
    if which("hackbench"):
        specs.append({"name": "hackbench", "kind": "hackbench", "metric": "runs/s"})
    if which("stress-ng"):
        specs.append({"name": "stress-ng-cpu", "kind": "stress_ng_cpu", "metric": "bogo-ops/s"})
    if which("sysbench"):
        specs.append({"name": "sysbench-cpu", "kind": "sysbench_cpu", "metric": "events/s"})
    return specs


def run_hackbench(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    hackbench = which("hackbench")
    if hackbench is None:
        raise RuntimeError("hackbench is required for the hackbench workload")
    command = [hackbench, "-g", "4", "-l", "1000"]
    start = time.monotonic()
    deadline = start + float(duration_s)
    iteration_times: list[float] = []
    stdout_lines: list[str] = []
    stderr_lines: list[str] = []
    completed_runs = 0.0
    while time.monotonic() < deadline:
        iter_start = time.monotonic()
        completed = run_command(
            command,
            check=False,
            timeout=max(30, int(duration_s) + 10),
        )
        iter_elapsed = time.monotonic() - iter_start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"hackbench failed: {details}")
        combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
        match = HACKBENCH_TIME_RE.search(combined)
        iteration_times.append(float(match.group(1)) if match else iter_elapsed)
        stdout_lines.append(completed.stdout or "")
        stderr_lines.append(completed.stderr or "")
        completed_runs += 1.0
    elapsed = time.monotonic() - start
    result = WorkloadResult(
        ops_total=completed_runs,
        ops_per_sec=(completed_runs / elapsed) if elapsed > 0 else None,
        duration_s=elapsed,
        stdout=tail_text("\n".join(stdout_lines), max_lines=40, max_chars=8000),
        stderr=tail_text("\n".join(stderr_lines), max_lines=40, max_chars=8000),
    )
    return result, {
        "command": command,
        "iterations": int(completed_runs),
        "latency_ms_p50": None if not iteration_times else statistics.median(iteration_times) * 1000.0,
        "latency_ms_p95": None if not iteration_times else percentile(iteration_times, 95.0) * 1000.0,
    }


def run_stress_ng_cpu(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the stress-ng-cpu workload")
    command = [
        stress_ng,
        "--cpu",
        "4",
        "--timeout",
        f"{max(1, int(duration_s))}s",
        "--metrics-brief",
    ]
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(duration_s) + 60)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"stress-ng cpu failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    match = STRESS_NG_CPU_RE.search(combined)
    ops_total = float(match.group(1)) if match else 0.0
    ops_per_sec = float(match.group(3)) if match else ((ops_total / elapsed) if elapsed > 0 else None)
    result = WorkloadResult(
        ops_total=ops_total,
        ops_per_sec=ops_per_sec,
        duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    )
    return result, {"command": command, "latency_ms_p50": None, "latency_ms_p95": None}


def run_sysbench_cpu(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    sysbench = which("sysbench")
    if sysbench is None:
        raise RuntimeError("sysbench is required for the sysbench-cpu workload")
    command = [
        sysbench,
        "cpu",
        "--threads=4",
        f"--time={max(1, int(duration_s))}",
        "run",
    ]
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(duration_s) + 60)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"sysbench cpu failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    eps_match = SYSBENCH_EVENTS_RE.search(combined)
    total_match = SYSBENCH_TOTAL_EVENTS_RE.search(combined)
    lat_avg_match = SYSBENCH_LATENCY_AVG_RE.search(combined)
    lat_p95_match = SYSBENCH_LATENCY_P95_RE.search(combined)
    ops_total = float(total_match.group(1)) if total_match else 0.0
    ops_per_sec = float(eps_match.group(1)) if eps_match else ((ops_total / elapsed) if elapsed > 0 else None)
    result = WorkloadResult(
        ops_total=ops_total,
        ops_per_sec=ops_per_sec,
        duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    )
    return result, {
        "command": command,
        "latency_ms_p50": float(lat_avg_match.group(1)) if lat_avg_match else None,
        "latency_ms_p95": float(lat_p95_match.group(1)) if lat_p95_match else None,
    }


def run_workload(spec: Mapping[str, object], duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    kind = str(spec.get("kind", ""))
    if kind == "hackbench":
        return run_hackbench(duration_s)
    if kind == "stress_ng_cpu":
        return run_stress_ng_cpu(duration_s)
    if kind == "sysbench_cpu":
        return run_sysbench_cpu(duration_s)
    raise RuntimeError(f"unsupported scx workload kind: {kind}")


def measure_workload(
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

    workload_result, extra = run_workload(workload_spec, duration_s)

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
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    *,
    agent_pid: int | None,
) -> dict[str, object]:
    records = [
        measure_workload(workload_spec, duration_s, agent_pid=agent_pid)
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
    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])
    os.environ["PATH"] = preferred_path()

    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
    scheduler_binary = Path(args.scheduler_binary).resolve()
    scx_repo = Path(args.scx_repo).resolve()
    object_path = Path(args.scheduler_object).resolve()
    scanner_binary = Path(args.scanner).resolve()
    bpftool_binary = Path(args.bpftool_binary).resolve()
    ensure_artifacts(scanner_binary, scheduler_binary, scx_repo)

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
        with ScxSchedulerSession(
            scheduler_binary,
            args.scheduler_extra_arg or [],
            load_timeout=int(args.load_timeout),
        ) as session:
            scheduler_programs = session.programs
            scheduler_ops = read_scx_ops()
            scheduler_snapshot = session.collector_snapshot()
            runtime_counters_available = any(
                ("run_cnt" in program) or ("run_time_ns" in program)
                for program in scheduler_programs
            )
            if not runtime_counters_available:
                limitations.append(
                    "bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable."
                )
            prog_ids = [int(program["id"]) for program in scheduler_programs]
            baseline = run_phase(workloads, duration_s, agent_pid=session.pid)
            scan_results = scan_programs(prog_ids, scanner_binary)
            rejit_result = apply_daemon_rejit(scanner_binary, prog_ids)
            if rejit_result["applied"]:
                post_rejit = run_phase(workloads, duration_s, agent_pid=session.pid)
            else:
                post_rejit = None
            scheduler_snapshot = session.collector_snapshot()
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
    }
    return payload


def persist_results(payload: Mapping[str, object], output_json: Path, output_md: Path) -> None:
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))
    chown_to_invoking_user(output_md)


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the scx_rusty end-to-end benchmark.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--scheduler-binary", default=str(DEFAULT_SCX_BINARY))
    parser.add_argument("--scheduler-object", default=str(DEFAULT_SCX_OBJECT))
    parser.add_argument("--scx-repo", default=str(DEFAULT_SCX_REPO))
    parser.add_argument("--scanner", default=str(DEFAULT_DAEMON))
    parser.add_argument("--bpftool-binary", default=str(DEFAULT_BPFTOOL))
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
        "--scanner",
        str(Path(args.scanner).resolve()),
        "--bpftool-binary",
        str(Path(args.bpftool_binary).resolve()),
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
    completed = run_in_vm(args.kernel, guest_script, args.cpus, args.mem, args.timeout)
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
    persist_results(payload, output_json, Path(args.output_md).resolve())
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
