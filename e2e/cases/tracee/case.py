from __future__ import annotations

import argparse
import ctypes
import json
import os
import platform
import re
import statistics
import subprocess
import sys
import threading
from collections import Counter, deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from e2e.common import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    chown_to_invoking_user,
    ensure_root,
    resolve_bpftool_binary,
    run_command,
    smoke_output_path,
    tail_text,
    which,
    write_json,
    write_text,
)
from e2e.common.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy  # noqa: E402
from e2e.common.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from e2e.common.recompile import PolicyTarget, apply_recompile, resolve_policy_files, scan_programs  # noqa: E402
from e2e.common.workload import (  # noqa: E402
    WorkloadResult,
    run_exec_storm,
    run_file_io,
    run_network_load,
    run_scheduler_load,
)
try:  # noqa: E402
    from micro.orchestrator.inventory import ProgramInventoryEntry, discover_object_programs
except ModuleNotFoundError:  # noqa: E402
    sys.path.insert(0, str(ROOT_DIR / "micro"))
    from orchestrator.inventory import ProgramInventoryEntry, discover_object_programs

try:  # noqa: E402
    from e2e.run_e2e_tracee import Libbpf as ManualLibbpf
    from e2e.run_e2e_tracee import ManualTraceeSession
except ModuleNotFoundError:  # noqa: E402
    sys.path.insert(0, str(ROOT_DIR / "e2e"))
    from run_e2e_tracee import Libbpf as ManualLibbpf
    from run_e2e_tracee import ManualTraceeSession


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "tracee")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "tracee-e2e-real.md"
DEFAULT_TRACEE_OBJECT = ROOT_DIR / "corpus" / "build" / "tracee" / "tracee.bpf.o"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
)
MANUAL_PROGRAM_NAMES = (
    "tracepoint__sched__sched_process_exec",
    "trace_security_file_open",
    "trace_security_socket_connect",
    "lsm_file_open_test",
)
SYS_PIDFD_GETFD = 438


def _dup_fd_from_process(pid: int, target_fd: int) -> int | None:
    try:
        pidfd = os.pidfd_open(int(pid), 0)
    except (AttributeError, OSError):
        pidfd = None
    if pidfd is not None:
        try:
            libc = ctypes.CDLL(None, use_errno=True)
            libc.syscall.restype = ctypes.c_long
            result = int(libc.syscall(SYS_PIDFD_GETFD, int(pidfd), int(target_fd), 0))
            if result >= 0:
                return result
        finally:
            os.close(pidfd)
    try:
        return os.open(f"/proc/{pid}/fd/{target_fd}", os.O_RDONLY | os.O_CLOEXEC)
    except OSError:
        return None


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_counts: Counter[str] = Counter()
        self.total_events = 0
        self.latest_stats: dict[str, int] = {}

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stdout_tail.append(line)
            self._parse_event_line(line)
            self._parse_stats_line(line)
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stderr_tail.append(line)
            self._parse_stats_line(line)
        pipe.close()

    def _parse_event_line(self, line: str) -> None:
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            return
        if not isinstance(payload, Mapping):
            return
        event_name = payload.get("eventName") or payload.get("event_name")
        if not event_name:
            return
        with self._lock:
            self.event_counts[str(event_name)] += 1
            self.total_events += 1

    def _parse_stats_line(self, line: str) -> None:
        match = TRACEE_STATS_PATTERN.search(line)
        if not match:
            return
        stats = {
            "event_count": int(match.group("events")),
            "lost_event_count": int(match.group("lost")),
            "lost_write_count": int(match.group("lost_writes") or 0),
        }
        with self._lock:
            self.latest_stats = stats

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "event_counts": dict(self.event_counts),
                "total_events": self.total_events,
                "latest_stats": dict(self.latest_stats),
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


class TraceeAgentSession:
    def __init__(self, commands: Sequence[Sequence[str]], load_timeout: int) -> None:
        self.commands = [list(command) for command in commands]
        self.load_timeout = load_timeout
        self.process: subprocess.Popen[str] | None = None
        self.collector = TraceeOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.command_used: list[str] | None = None
        self.programs: list[dict[str, object]] = []
        self.program_fds: dict[int, int] = {}

    def __enter__(self) -> "TraceeAgentSession":
        preexisting = sample_bpf_stats(_current_prog_ids())
        preexisting_ids = set(preexisting)
        last_error = "Tracee never became healthy"
        for command in self.commands:
            self.collector = TraceeOutputCollector()
            proc = start_agent(command[0], command[1:], env={"HOME": os.environ.get("HOME", str(ROOT_DIR))})
            self.process = proc
            self.command_used = command
            assert proc.stdout is not None
            assert proc.stderr is not None
            self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(proc.stdout,), daemon=True)
            self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(proc.stderr,), daemon=True)
            self.stdout_thread.start()
            self.stderr_thread.start()

            healthy = wait_healthy(
                proc,
                self.load_timeout,
                lambda: bool([item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]),
            )
            if healthy:
                programs = [
                    item
                    for item in find_bpf_programs(proc.pid or 0)
                    if int(item.get("id", -1)) not in preexisting_ids
                ]
                if programs:
                    self.programs = programs
                    self.program_fds = {}
                    for program in programs:
                        prog_id = int(program.get("id", -1))
                        for ref in program.get("owner_fds") or []:
                            if int(ref.get("pid", -1)) != (proc.pid or -1):
                                continue
                            dup_fd = _dup_fd_from_process(int(proc.pid or -1), int(ref["fd"]))
                            if dup_fd is None:
                                continue
                            self.program_fds[prog_id] = dup_fd
                            break
                    return self
            snapshot = self.collector.snapshot()
            last_error = tail_text("\n".join(snapshot.get("stderr_tail") or snapshot.get("stdout_tail") or []))
            self.close()
        raise RuntimeError(f"failed to launch Tracee: {last_error}")

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        for fd in self.program_fds.values():
            try:
                os.close(fd)
            except OSError:
                pass
        self.program_fds.clear()
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


def _current_prog_ids() -> list[int]:
    payload = run_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30).stdout
    parsed = json.loads(payload)
    if not isinstance(parsed, list):
        return []
    return [int(record["id"]) for record in parsed if isinstance(record, dict) and "id" in record]


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


def ensure_artifacts(runner_binary: Path, scanner_binary: Path) -> None:
    if not runner_binary.exists():
        run_command(["make", "-C", "micro", "micro_exec", "programs"], timeout=1800)
    if not scanner_binary.exists():
        run_command(
            ["cmake", "-S", "scanner", "-B", "scanner/build", "-DCMAKE_BUILD_TYPE=Release"],
            timeout=600,
        )
        run_command(
            ["cmake", "--build", "scanner/build", "--target", "bpf-jit-scanner", "-j"],
            timeout=1800,
        )


def load_config(path: Path) -> dict[str, object]:
    payload = yaml.safe_load(path.read_text())
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid config payload in {path}")
    return payload


def run_setup_script(setup_script: Path) -> dict[str, object]:
    completed = run_command(["bash", str(setup_script)], check=False, timeout=1800)
    tracee_binary = ""
    for line in (completed.stdout or "").splitlines():
        if line.startswith("TRACEE_BINARY="):
            tracee_binary = line.split("=", 1)[1].strip()
            break
    return {
        "returncode": completed.returncode,
        "tracee_binary": tracee_binary or None,
        "stdout_tail": tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    }


def resolve_tracee_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).resolve()
        if candidate.exists():
            return str(candidate)
    scripted = str(setup_result.get("tracee_binary") or "").strip()
    if scripted and Path(scripted).exists():
        return scripted
    for candidate in ("tracee", "tracee-ebpf"):
        resolved = which(candidate)
        if resolved:
            return resolved
    if Path("/tmp/tracee-bin/tracee").exists():
        return "/tmp/tracee-bin/tracee"
    return None


def build_tracee_commands(binary: str, events: Sequence[str], extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_text = ",".join(str(event) for event in events)
    candidates = [
        [binary, "--events", event_text, "--output", "json", *extra_args],
        [binary, "--events", event_text, "--output", "destinations.stdout.format=json", *extra_args],
        [binary, "--events", event_text, "--output", "format:json", *extra_args],
    ]
    deduped: list[list[str]] = []
    seen: set[tuple[str, ...]] = set()
    for command in candidates:
        key = tuple(command)
        if key in seen:
            continue
        deduped.append(command)
        seen.add(key)
    return deduped


def run_workload(spec: Mapping[str, object], duration_s: int) -> WorkloadResult:
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind == "exec_storm":
        return run_exec_storm(duration_s, int(spec.get("rate", 4) or 4))
    if kind == "file_io":
        return run_file_io(duration_s)
    if kind == "network":
        return run_network_load(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")


def measure_workload(
    workload_spec: Mapping[str, object],
    duration_s: int,
    prog_ids: list[int],
    *,
    prog_fds: dict[int, int] | None,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids, prog_fds=prog_fds)
    before_tracee = collector.snapshot() if collector is not None else None
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

    workload_result = run_workload(workload_spec, duration_s)

    for thread in threads:
        thread.join()

    after_bpf = sample_bpf_stats(prog_ids, prog_fds=prog_fds)
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
        total_events = int(after_tracee.get("total_events", 0)) - int(before_tracee.get("total_events", 0))
    else:
        event_counts = {}
        drop_counters = {}
        total_events = int(bpf_delta["summary"]["total_events"])

    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_cpu_total = None
    if agent_cpu is not None:
        agent_cpu_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    return {
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "command_template": str(workload_spec.get("command", "")),
        "app_throughput": workload_result.ops_per_sec,
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "events_total": total_events,
        "events_per_sec": (total_events / workload_result.duration_s) if workload_result.duration_s > 0 else None,
        "event_counts": event_counts,
        "drop_counters": drop_counters,
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


def compare_phases(baseline: Mapping[str, object], post: Mapping[str, object] | None) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "recompile did not apply successfully"}

    baseline_by_name = {record["name"]: record for record in baseline.get("workloads") or []}
    post_by_name = {record["name"]: record for record in post.get("workloads") or []}
    workload_rows: list[dict[str, object]] = []
    for name in sorted(set(baseline_by_name) & set(post_by_name)):
        before = baseline_by_name[name]
        after = post_by_name[name]
        before_cpu = ((before.get("agent_cpu") or {}).get("total_pct"))
        after_cpu = ((after.get("agent_cpu") or {}).get("total_pct"))
        before_drops = int(((before.get("drop_counters") or {}).get("lost_event_count", 0) or 0))
        after_drops = int(((after.get("drop_counters") or {}).get("lost_event_count", 0) or 0))
        workload_rows.append(
            {
                "name": name,
                "app_throughput_delta_pct": percent_delta(before.get("ops_per_sec"), after.get("ops_per_sec")),
                "events_per_sec_delta_pct": percent_delta(before.get("events_per_sec"), after.get("events_per_sec")),
                "bpf_avg_ns_delta_pct": percent_delta(
                    ((before.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                    ((after.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")),
                ),
                "agent_cpu_delta_pct": percent_delta(before_cpu, after_cpu),
                "lost_event_count_delta": after_drops - before_drops,
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


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# Tracee Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Tracee binary: `{payload.get('tracee_binary') or 'unavailable'}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{payload['setup']['returncode']}`",
        f"- Setup tracee binary: `{payload['setup'].get('tracee_binary') or 'missing'}`",
        "",
        "## Baseline",
        "",
    ]
    baseline = payload["baseline"]
    for workload in baseline["workloads"]:
        lines.append(
            f"- {workload['name']}: app={workload.get('ops_per_sec')} {workload['metric']}, "
            f"events/s={workload.get('events_per_sec')}, drops={workload.get('drop_counters')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
        )
    lines.extend(["", "## Recompile", ""])
    recompile_summary = payload["recompile_summary"]
    lines.append(f"- Applied programs: `{recompile_summary['applied_programs']}` / `{recompile_summary['requested_programs']}`")
    lines.append(f"- Applied successfully: `{recompile_summary['applied']}`")
    if recompile_summary.get("errors"):
        lines.append(f"- Errors: `{recompile_summary['errors']}`")
    lines.append("")
    post = payload.get("post_rejit")
    if post:
        lines.extend(["## Post-ReJIT", ""])
        for workload in post["workloads"]:
            lines.append(
                f"- {workload['name']}: app={workload.get('ops_per_sec')} {workload['metric']}, "
                f"events/s={workload.get('events_per_sec')}, drops={workload.get('drop_counters')}, "
                f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
                f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
            )
        lines.append("")
    comparison = payload.get("comparison") or {}
    lines.extend(["## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads", []):
            lines.append(
                f"- {workload['name']}: app_delta={workload.get('app_throughput_delta_pct')}%, "
                f"events_delta={workload.get('events_per_sec_delta_pct')}%, "
                f"cpu_delta={workload.get('agent_cpu_delta_pct')}%, "
                f"bpf_ns_delta={workload.get('bpf_avg_ns_delta_pct')}%"
            )
    else:
        lines.append(f"- Comparable: `False`")
        lines.append(f"- Reason: `{comparison.get('reason', 'unknown')}`")
    limitations = payload.get("limitations") or []
    if limitations:
        lines.extend(["", "## Limitations", ""])
        for limitation in limitations:
            lines.append(f"- {limitation}")
    lines.append("")
    return "\n".join(lines)


def select_manual_programs(inventory: Sequence[ProgramInventoryEntry]) -> list[ProgramInventoryEntry]:
    by_name = {entry.name: entry for entry in inventory}
    missing = [name for name in MANUAL_PROGRAM_NAMES if name not in by_name]
    if missing:
        raise RuntimeError(f"manual Tracee fallback is missing programs: {', '.join(missing)}")
    return [by_name[name] for name in MANUAL_PROGRAM_NAMES]


def resolve_tracee_policy_files(tracee_object: Path, program_ids_by_name: Mapping[str, int]) -> dict[int, str]:
    return resolve_policy_files(
        PolicyTarget(
            prog_id=int(prog_id),
            object_path=tracee_object,
            program_name=name,
        )
        for name, prog_id in program_ids_by_name.items()
        if int(prog_id) > 0
    )


def build_policy_summary(policy_files: Mapping[int, str], prog_ids: Sequence[int]) -> dict[str, int]:
    return {
        "configured_programs": len(policy_files),
        "fallback_programs": max(0, len(prog_ids) - len(policy_files)),
    }


def run_phase(
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    prog_ids: list[int],
    *,
    prog_fds: dict[int, int] | None,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
) -> dict[str, object]:
    records = [
        measure_workload(
            workload_spec,
            duration_s,
            prog_ids,
            prog_fds=prog_fds,
            agent_pid=agent_pid,
            collector=collector,
        )
        for workload_spec in workloads
    ]
    return {
        "workloads": records,
        "summary": summarize_phase(records),
    }


def run_manual_fallback(
    *,
    config: Mapping[str, object],
    duration_s: int,
    tracee_object: Path,
    runner_binary: Path,
    scanner_binary: Path,
    setup_result: Mapping[str, object],
    smoke: bool,
) -> dict[str, object]:
    inventory = discover_object_programs(runner_binary, tracee_object)
    selected = select_manual_programs(inventory)
    workloads = list(config.get("workloads") or [])
    limitations = [
        "Tracee daemon was unavailable, so this result uses manual BPF program loading from corpus/build/tracee/tracee.bpf.o.",
        "Agent event counts and drop counters are unavailable in manual fallback mode; events_total is estimated from BPF run_cnt deltas.",
        "Agent CPU is unavailable in manual fallback mode; only host busy CPU is reported.",
    ]

    with enable_bpf_stats():
        with ManualTraceeSession(ManualLibbpf(), tracee_object, selected) as session:
            prog_ids = [int(handle.prog_id) for handle in session.program_handles.values()]
            prog_fds = {int(handle.prog_id): int(handle.prog_fd) for handle in session.program_handles.values()}
            policy_files = resolve_tracee_policy_files(
                tracee_object,
                {name: int(handle.prog_id) for name, handle in session.program_handles.items()},
            )
            baseline = run_phase(workloads, duration_s, prog_ids, prog_fds=prog_fds, agent_pid=None, collector=None)
            scan_results = scan_programs(prog_ids, scanner_binary, prog_fds=prog_fds)
            recompile_results = apply_recompile(
                prog_ids,
                scanner_binary,
                prog_fds=prog_fds,
                policy_files=policy_files,
            )
            applied = sum(1 for record in recompile_results.values() if record.get("applied"))
            post = run_phase(workloads, duration_s, prog_ids, prog_fds=prog_fds, agent_pid=None, collector=None) if applied > 0 else None

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "manual_fallback",
        "smoke": smoke,
        "duration_s": duration_s,
        "tracee_binary": None,
        "tracee_programs": [
            {"name": entry.name, "section_name": entry.section_name}
            for entry in selected
        ],
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "baseline": baseline,
        "policy_matches": {str(key): value for key, value in policy_files.items()},
        "policy_summary": build_policy_summary(policy_files, prog_ids),
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "recompile_results": {str(key): value for key, value in recompile_results.items()},
        "recompile_summary": {
            "requested_programs": len(prog_ids),
            "applied_programs": applied,
            "applied": applied > 0,
            "errors": sorted({record.get("error", "") for record in recompile_results.values() if record.get("error")}),
        },
        "post_rejit": post,
        "comparison": compare_phases(baseline, post),
        "limitations": limitations,
    }
    return payload


def run_tracee_case(args: argparse.Namespace) -> dict[str, object]:
    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])
    config = load_config(Path(args.config).resolve())
    duration_s = int(args.duration or config.get("measurement_duration_s") or 60)
    if args.smoke and not args.duration:
        duration_s = int(config.get("smoke_duration_s") or 10)

    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    tracee_object = Path(args.tracee_object).resolve()
    ensure_artifacts(runner_binary, scanner_binary)

    setup_result = {
        "returncode": 0,
        "tracee_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_setup_script(Path(args.setup_script).resolve())

    tracee_binary = resolve_tracee_binary(args.tracee_binary, setup_result)
    if tracee_binary is None:
        return run_manual_fallback(
            config=config,
            duration_s=duration_s,
            tracee_object=tracee_object,
            runner_binary=runner_binary,
            scanner_binary=scanner_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
        )

    workloads = list(config.get("workloads") or [])
    events = list(config.get("events") or [])
    limitations: list[str] = []
    commands = build_tracee_commands(tracee_binary, events, args.tracee_extra_arg or [])

    with enable_bpf_stats():
        with TraceeAgentSession(commands, load_timeout=int(args.load_timeout)) as session:
            prog_ids = [int(program["id"]) for program in session.programs]
            policy_files = resolve_tracee_policy_files(
                tracee_object,
                {
                    str(program.get("name", "")).strip(): int(program.get("id", 0))
                    for program in session.programs
                    if int(program.get("id", 0) or 0) > 0 and str(program.get("name", "")).strip()
                },
            )
            baseline = run_phase(
                workloads,
                duration_s,
                prog_ids,
                prog_fds=session.program_fds,
                agent_pid=session.pid,
                collector=session.collector,
            )
            scan_results = scan_programs(prog_ids, scanner_binary, prog_fds=session.program_fds)
            recompile_results = apply_recompile(
                prog_ids,
                scanner_binary,
                prog_fds=session.program_fds,
                policy_files=policy_files,
            )
            applied = sum(1 for record in recompile_results.values() if record.get("applied"))
            if applied == 0:
                limitations.append("BPF_PROG_JIT_RECOMPILE did not apply on this kernel; post-ReJIT measurement was skipped.")
            post = (
                run_phase(
                    workloads,
                    duration_s,
                    prog_ids,
                    prog_fds=session.program_fds,
                    agent_pid=session.pid,
                    collector=session.collector,
                )
                if applied > 0
                else None
            )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "tracee_daemon",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "tracee_binary": tracee_binary,
        "tracee_launch_command": commands,
        "tracee_programs": session.programs,
        "setup": setup_result,
        "host": host_metadata(),
        "config": dict(config),
        "baseline": baseline,
        "policy_matches": {str(key): value for key, value in policy_files.items()},
        "policy_summary": build_policy_summary(policy_files, prog_ids),
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "recompile_results": {str(key): value for key, value in recompile_results.items()},
        "recompile_summary": {
            "requested_programs": len(prog_ids),
            "applied_programs": applied,
            "applied": applied > 0,
            "errors": sorted({record.get("error", "") for record in recompile_results.values() if record.get("error")}),
        },
        "post_rejit": post,
        "comparison": compare_phases(baseline, post),
        "limitations": limitations,
    }
    return payload


def persist_results(payload: Mapping[str, object], output_json: Path, output_md: Path) -> None:
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))
    chown_to_invoking_user(output_md)


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Tracee real end-to-end benchmark.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--tracee-binary")
    parser.add_argument("--tracee-object", default=str(DEFAULT_TRACEE_OBJECT))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER))
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--tracee-extra-arg", action="append", default=[])
    parser.add_argument("--skip-setup", action="store_true")
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_tracee_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "tracee")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve())
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
