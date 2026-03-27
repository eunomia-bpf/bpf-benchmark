from __future__ import annotations

import argparse
import ctypes
import json
import os
import re
import shlex
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

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    resolve_bpftool_binary,
    run_command,
    smoke_output_path,
    tail_text,
    which,
)
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from runner.libs.rejit import apply_daemon_rejit, scan_programs  # noqa: E402
from runner.libs.workload import (  # noqa: E402
    WorkloadResult,
    run_exec_storm,
    run_file_io,
    run_network_load,
    run_scheduler_load,
)
from e2e.case_common import (  # noqa: E402
    build_map_capture_specs,
    capture_map_state,
    git_sha,
    host_metadata,
    summarize_numbers,
    percent_delta,
    persist_results,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "tracee")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "tracee-e2e-real.md"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
CACHED_TRACEE_BINARY = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "tracee"
TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
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
        failures: list[str] = []
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
            failures.append(_format_launch_failure(command, proc, snapshot))
            self.close()
        if not failures:
            failures.append("Tracee never became healthy")
        raise RuntimeError(f"failed to launch Tracee: {' | '.join(failures)}")

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


def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


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
    # Check the repo-local cached binary (shared into VM via --rwdir)
    if CACHED_TRACEE_BINARY.exists():
        return str(CACHED_TRACEE_BINARY)
    if Path("/tmp/tracee-bin/tracee").exists():
        return "/tmp/tracee-bin/tracee"
    return None


def _ensure_empty_signatures_dir() -> Path:
    """Ensure an empty signatures directory exists so tracee does not error out."""
    sig_dir = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "signatures"
    sig_dir.mkdir(parents=True, exist_ok=True)
    return sig_dir


def build_tracee_commands(binary: str, events: Sequence[str], extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_text = ",".join(str(event) for event in events)
    sig_dir = _ensure_empty_signatures_dir()
    return [[binary, "--events", event_text, "--output", "json", "--signatures-dir", str(sig_dir), *extra_args]]


def _format_launch_failure(command: Sequence[str], proc: subprocess.Popen[str] | None, snapshot: Mapping[str, object]) -> str:
    rendered = " ".join(shlex.quote(part) for part in command)
    combined = "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or []))
    details = tail_text(combined, max_lines=40, max_chars=8000)
    if proc is not None and proc.poll() is not None:
        reason = f"command exited with code {proc.returncode}"
    else:
        reason = "command did not become healthy"
    if details:
        return f"{rendered}: {reason}: {details}"
    return f"{rendered}: {reason}"


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
        return {"comparable": False, "reason": "rejit did not apply successfully"}

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
    ]
    if payload.get("status") == "skipped":
        lines.extend(
            [
                "## Result",
                "",
                "- Status: `SKIP`",
                f"- Reason: `{payload.get('skip_reason', 'unknown')}`",
            ]
        )
        limitations = payload.get("limitations") or []
        if limitations:
            lines.extend(["", "## Limitations", ""])
            for limitation in limitations:
                lines.append(f"- {limitation}")
        lines.append("")
        return "\n".join(lines)

    lines.extend(["## Baseline", ""])
    baseline = payload["baseline"]
    for workload in baseline["workloads"]:
        lines.append(
            f"- {workload['name']}: app={workload.get('ops_per_sec')} {workload['metric']}, "
            f"events/s={workload.get('events_per_sec')}, drops={workload.get('drop_counters')}, "
            f"agent_cpu={((workload.get('agent_cpu') or {}).get('total_pct'))}, "
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}"
        )
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


def skip_payload(
    *,
    config: Mapping[str, object],
    duration_s: int,
    tracee_binary: str | None,
    setup_result: Mapping[str, object],
    smoke: bool,
    reason: str,
    limitations: Sequence[str],
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "skipped",
        "mode": "skipped",
        "skip_reason": reason,
        "smoke": smoke,
        "duration_s": duration_s,
        "tracee_binary": tracee_binary,
        "tracee_programs": [],
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "baseline": None,
        "scan_results": {},
        "rejit_result": None,
        "post_rejit": None,
        "comparison": {"comparable": False, "reason": reason},
        "limitations": list(limitations),
        "map_capture": None,
    }


def run_tracee_case(args: argparse.Namespace) -> dict[str, object]:
    config = load_config(Path(args.config).resolve())
    duration_s = int(args.duration or config.get("measurement_duration_s") or 60)
    if args.smoke and not args.duration:
        duration_s = int(config.get("smoke_duration_s") or 10)

    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)

    setup_result = {
        "returncode": 0,
        "tracee_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_setup_script(Path(args.setup_script).resolve())

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Setup script returned non-zero; only the real Tracee binary path was attempted.")

    tracee_binary = resolve_tracee_binary(args.tracee_binary, setup_result)
    if tracee_binary is None:
        return skip_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=None,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            reason="Tracee binary is unavailable in this environment; manual .bpf.o fallback is forbidden.",
            limitations=limitations,
        )

    workloads = list(config.get("workloads") or [])
    events = list(config.get("events") or [])
    commands = build_tracee_commands(tracee_binary, events, args.tracee_extra_arg or [])

    try:
        map_capture: dict[str, object] | None = None
        with enable_bpf_stats():
            with TraceeAgentSession(commands, load_timeout=int(args.load_timeout)) as session:
                prog_ids = [int(program["id"]) for program in session.programs]
                baseline = run_phase(
                    workloads,
                    duration_s,
                    prog_ids,
                    prog_fds=session.program_fds,
                    agent_pid=session.pid,
                    collector=session.collector,
                )
                if args.capture_maps:
                    capture_plan = build_map_capture_specs(
                        session.programs,
                        repo_name="tracee",
                        object_paths=sorted((ROOT_DIR / "corpus" / "build" / "tracee").glob("*.bpf.o")),
                        runner_binary=Path(args.runner).resolve(),
                    )
                    map_capture = {
                        "discovery": {
                            key: value
                            for key, value in capture_plan.items()
                            if key != "program_specs"
                        }
                    }
                scan_results = scan_programs(prog_ids, daemon_binary, prog_fds=session.program_fds)
                rejit_result = apply_daemon_rejit(daemon_binary, prog_ids)
                if args.capture_maps and map_capture is not None:
                    optimize_results = (
                        rejit_result.get("per_program")
                        if isinstance(rejit_result.get("per_program"), Mapping)
                        else {}
                    )
                    map_capture["result"] = capture_map_state(
                        captured_from="e2e/tracee",
                        program_specs=capture_plan["program_specs"],
                        optimize_results=optimize_results,
                    )
                if rejit_result["applied"]:
                    post_rejit = run_phase(
                        workloads,
                        duration_s,
                        prog_ids,
                        prog_fds=session.program_fds,
                        agent_pid=session.pid,
                        collector=session.collector,
                    )
                else:
                    post_rejit = None
    except Exception as exc:
        return skip_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            reason=f"Tracee binary could not run on this kernel: {exc}",
            limitations=limitations,
        )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "ok",
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
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "rejit_result": rejit_result,
        "post_rejit": post_rejit,
        "comparison": compare_phases(baseline, post_rejit),
        "limitations": limitations,
        "map_capture": map_capture,
    }
    return payload


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Tracee real end-to-end benchmark.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--tracee-binary")
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--runner", default=str(ROOT_DIR / "runner" / "build" / "micro_exec"))
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--tracee-extra-arg", action="append", default=[])
    parser.add_argument("--capture-maps", action="store_true")
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
    persist_results(payload, output_json, Path(args.output_md).resolve(), build_markdown)
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
