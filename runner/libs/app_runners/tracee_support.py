from __future__ import annotations

import ctypes
import json
import os
import re
import shlex
import subprocess
import tempfile
import threading
import time
from collections import Counter, deque
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, tail_text, which
from ..agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from ..metrics import sample_bpf_stats
from ..workload import (
    WorkloadResult,
    run_connect_storm,
    run_dd_read_load,
    run_file_open_load,
    run_network_load,
    run_open_storm,
    run_scheduler_load,
    run_user_exec_loop,
)


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
        self._condition = threading.Condition(self._lock)
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_counts: Counter[str] = Counter()
        self.events: deque[dict[str, object]] = deque(maxlen=4096)
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
            normalized_event_name = str(event_name)
            self.event_counts[normalized_event_name] += 1
            self.total_events += 1
            self.events.append(
                {
                    "event_name": normalized_event_name,
                    "line": line,
                    "payload": dict(payload),
                    "observed_monotonic_ns": time.monotonic_ns(),
                }
            )
            self._condition.notify_all()

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
                "recent_events": list(self.events),
                "total_events": self.total_events,
                "latest_stats": dict(self.latest_stats),
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }

    def wait_for_event(
        self,
        *,
        event_names: Sequence[str],
        marker_tokens: Sequence[str],
        min_observed_ns: int,
        timeout_s: float,
    ) -> dict[str, object] | None:
        wanted_names = {str(name) for name in event_names if str(name)}
        tokens = [str(token) for token in marker_tokens if str(token)]
        deadline = time.monotonic() + max(0.0, float(timeout_s))

        def find_match() -> dict[str, object] | None:
            for record in reversed(self.events):
                observed_ns = int(record.get("observed_monotonic_ns", 0) or 0)
                if observed_ns < min_observed_ns:
                    break
                event_name = str(record.get("event_name") or "")
                if wanted_names and event_name not in wanted_names:
                    continue
                raw_line = str(record.get("line") or "")
                if tokens and not all(token in raw_line for token in tokens):
                    continue
                return dict(record)
            return None

        with self._condition:
            match = find_match()
            while match is None:
                remaining = deadline - time.monotonic()
                if remaining <= 0:
                    return None
                self._condition.wait(timeout=remaining)
                match = find_match()
            return match


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
        preexisting_ids = set(sample_bpf_stats(_current_prog_ids()))
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
                programs = [item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]
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
    if CACHED_TRACEE_BINARY.exists():
        return str(CACHED_TRACEE_BINARY)
    if Path("/tmp/tracee-bin/tracee").exists():
        return "/tmp/tracee-bin/tracee"
    return None


def _ensure_empty_signatures_dir() -> Path:
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

def run_tracee_workload(spec: Mapping[str, object], duration_s: int) -> WorkloadResult:
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind == "read":
        return run_dd_read_load(duration_s)
    if kind == "exec_storm":
        return run_user_exec_loop(duration_s)
    if kind in {"file_io", "file_open"}:
        if which("stress-ng") is None:
            raise RuntimeError("stress-ng is required for the Tracee file_open workload")
        return run_file_open_load(duration_s)
    if kind == "open_storm":
        return run_open_storm(duration_s)
    if kind in {"network", "connect_storm"}:
        if kind == "network":
            if which("wrk") is None:
                raise RuntimeError("wrk is required for the Tracee network workload")
            return run_network_load(duration_s)
        return run_connect_storm(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")
