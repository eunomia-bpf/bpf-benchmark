from __future__ import annotations

import json
import os
import re
import shlex
import socket
import subprocess
import tempfile
import threading
import time
from collections import Counter, deque
from pathlib import Path
from typing import Any, Mapping, Sequence
from urllib.error import URLError
from urllib.request import urlopen

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, tail_text, which
from ..agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from ..bpf_stats import sample_bpf_stats
from ..process_fd import dup_fd_from_process
from ..workload import (
    WorkloadResult,
    run_block_io_load,
    run_connect_storm,
    run_file_open_load,
    run_network_load,
    run_open_storm,
    run_scheduler_load,
    run_tracee_default_load,
    run_user_exec_loop,
)


TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
)
TRACEE_RUNTIME_DIR = Path("/var/tmp/tracee")
TRACEE_EVENT_OUTPUT_PATH = TRACEE_RUNTIME_DIR / "events.json"
TRACEE_HEALTH_HOST = "127.0.0.1"
TRACEE_HEALTH_PORT = 3366


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._condition = threading.Condition(self._lock)
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_tail: deque[str] = deque(maxlen=200)
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

    def consume_event_file(self, path: Path, stop_event: threading.Event) -> None:
        handle = None
        try:
            while True:
                if handle is None:
                    if stop_event.is_set():
                        return
                    try:
                        handle = path.open("r", encoding="utf-8", errors="replace")
                    except FileNotFoundError:
                        time.sleep(0.05)
                        continue
                raw_line = handle.readline()
                if raw_line:
                    line = raw_line.rstrip()
                    with self._lock:
                        self.event_tail.append(line)
                    self._parse_event_line(line)
                    continue
                if stop_event.is_set():
                    break
                time.sleep(0.05)
        finally:
            if handle is not None:
                for raw_line in handle:
                    line = raw_line.rstrip()
                    with self._lock:
                        self.event_tail.append(line)
                    self._parse_event_line(line)
                handle.close()

    def _parse_event_line(self, line: str) -> None:
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            return
        if not isinstance(payload, Mapping):
            return
        event_name = payload.get("eventName") or payload.get("event_name") or payload.get("name")
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
                "event_tail": list(self.event_tail),
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
        self.event_thread: threading.Thread | None = None
        self.event_stop = threading.Event()
        self.command_used: list[str] | None = None
        self.programs: list[dict[str, object]] = []
        self.program_fds: dict[int, int] = {}

    def __enter__(self) -> "TraceeAgentSession":
        preexisting_ids = set(sample_bpf_stats(_current_prog_ids()))
        failures: list[str] = []
        tracee_tmpdir = TRACEE_RUNTIME_DIR
        tracee_tmpdir.mkdir(parents=True, exist_ok=True)
        TRACEE_EVENT_OUTPUT_PATH.unlink(missing_ok=True)
        for command in self.commands:
            self.collector = TraceeOutputCollector()
            self.event_stop = threading.Event()
            proc = start_agent(
                command[0],
                command[1:],
                env={
                    "HOME": os.environ.get("HOME", str(ROOT_DIR)),
                    "TMPDIR": str(tracee_tmpdir),
                    "TMP": str(tracee_tmpdir),
                    "TEMP": str(tracee_tmpdir),
                },
            )
            self.process = proc
            self.command_used = command
            assert proc.stdout is not None
            assert proc.stderr is not None
            self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(proc.stdout,), daemon=True)
            self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(proc.stderr,), daemon=True)
            self.event_thread = threading.Thread(
                target=self.collector.consume_event_file,
                args=(TRACEE_EVENT_OUTPUT_PATH, self.event_stop),
                daemon=True,
            )
            self.stdout_thread.start()
            self.stderr_thread.start()
            self.event_thread.start()

            try:
                healthy = wait_healthy(
                    proc,
                    self.load_timeout,
                    lambda: _tracee_healthz_ready(TRACEE_HEALTH_HOST, TRACEE_HEALTH_PORT)
                    and bool(
                        [item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]
                    ),
                )
            except Exception:
                self.close()
                raise
            if healthy:
                programs = [item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]
                if programs:
                    try:
                        self.programs = programs
                        self.program_fds = {}
                        for program in programs:
                            prog_id = int(program.get("id", -1))
                            program_name = str(program.get("name") or prog_id)
                            owner_refs = [
                                ref
                                for ref in (program.get("owner_fds") or [])
                                if int(ref.get("pid", -1)) == (proc.pid or -1)
                            ]
                            if not owner_refs:
                                raise RuntimeError(
                                    f"Tracee program {program_name!r} (id={prog_id}) did not expose a loader-owned FD"
                                )
                            self.program_fds[prog_id] = dup_fd_from_process(
                                int(proc.pid or -1),
                                int(owner_refs[0]["fd"]),
                            )
                    except Exception:
                        self.close()
                        raise
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
        close_errors: list[str] = []
        for fd in self.program_fds.values():
            try:
                os.close(fd)
            except OSError as exc:
                close_errors.append(f"failed to close Tracee program fd {fd}: {exc}")
        self.program_fds.clear()
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        self.event_stop.set()
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None
        if self.event_thread is not None:
            self.event_thread.join(timeout=2.0)
            self.event_thread = None
        if close_errors:
            raise RuntimeError("; ".join(close_errors))

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
        if not candidate.exists():
            raise RuntimeError(f"Tracee binary not found: {candidate}")
        return str(candidate)
    scripted = str(setup_result.get("tracee_binary") or "").strip()
    if scripted:
        candidate = Path(scripted).resolve()
        if not candidate.exists():
            raise RuntimeError(f"Tracee setup reported a missing binary: {candidate}")
        return str(candidate)
    return None


def _ensure_empty_signatures_dir() -> Path:
    sig_dir = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "signatures"
    sig_dir.mkdir(parents=True, exist_ok=True)
    return sig_dir


def _tracee_healthz_ready(host: str, port: int) -> bool:
    try:
        with urlopen(f"http://{host}:{int(port)}/healthz", timeout=1.0) as response:
            return int(getattr(response, "status", 0) or 0) == 200
    except (OSError, URLError):
        return False


def _tracee_output_args(event_output_path: Path) -> list[str]:
    return ["--output", f"json:{event_output_path}"]


def build_tracee_commands(binary: str, events: Sequence[str], extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_text = ",".join(str(event) for event in events)
    sig_dir = _ensure_empty_signatures_dir()
    output_args = _tracee_output_args(TRACEE_EVENT_OUTPUT_PATH)
    return [[
        binary,
        "--events",
        event_text,
        *output_args,
        "--server",
        "healthz",
        "--server",
        f"http-address=:{TRACEE_HEALTH_PORT}",
        "--signatures-dir",
        str(sig_dir),
        *extra_args,
    ]]


def _format_launch_failure(command: Sequence[str], proc: subprocess.Popen[str] | None, snapshot: Mapping[str, object]) -> str:
    rendered = " ".join(shlex.quote(part) for part in command)
    combined = "\n".join(
        (snapshot.get("stderr_tail") or [])
        + (snapshot.get("stdout_tail") or [])
        + (snapshot.get("event_tail") or [])
    )
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
    if kind == "tracee_default":
        return run_tracee_default_load(duration_s)
    if kind == "block_io":
        return run_block_io_load(duration_s)
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
