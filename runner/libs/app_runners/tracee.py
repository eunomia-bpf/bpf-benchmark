from __future__ import annotations

import json
import os
import re
import shlex
import subprocess
import threading
import time
from collections import Counter, deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence
from urllib.error import URLError
from urllib.request import urlopen

import yaml

from .. import ROOT_DIR, resolve_bpftool_binary, run_command, tail_text, which
from ..agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from ..bpf_stats import sample_bpf_stats
from ..process_fd import dup_fd_from_process
from ..workload import (
    WorkloadResult,
    resolve_workload_tool,
    run_block_io_load,
    run_connect_storm,
    run_file_open_load,
    run_network_load,
    run_open_storm,
    run_scheduler_load,
    run_tracee_default_load,
    run_user_exec_loop,
)
from .base import AppRunner
from .setup_support import pick_host_executable, repo_artifact_root


TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
)
TRACEE_HEALTH_HOST = "127.0.0.1"
TRACEE_HEALTH_PORT = 3366


def _tracee_runtime_dir() -> Path:
    explicit = os.environ.get("BPFREJIT_TRACEE_RUNTIME_DIR", "").strip()
    if explicit:
        candidate = Path(explicit).expanduser()
    else:
        runtime_tmpdir = os.environ.get("BPFREJIT_RUNTIME_TMPDIR", "").strip()
        if not runtime_tmpdir:
            raise RuntimeError("BPFREJIT_RUNTIME_TMPDIR is required for the Tracee runner")
        candidate = Path(runtime_tmpdir).expanduser() / "tracee"
    candidate.mkdir(parents=True, exist_ok=True)
    if not os.access(candidate, os.W_OK | os.X_OK):
        raise RuntimeError(f"Tracee runtime directory is not writable/executable: {candidate}")
    return candidate


def _tracee_event_output_path() -> Path:
    return _tracee_runtime_dir() / "events.json"


class TraceeOutputCollector:
    def __init__(self, event_output_path: Path | None = None) -> None:
        self._lock = threading.Lock()
        self._condition = threading.Condition(self._lock)
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_tail: deque[str] = deque(maxlen=200)
        self.event_counts: Counter[str] = Counter()
        self.events: deque[dict[str, object]] = deque(maxlen=16384)
        self.total_events = 0
        self.latest_stats: dict[str, int] = {}
        self.event_output_path = None if event_output_path is None else Path(event_output_path)

    @staticmethod
    def _payload_timestamp_ns(payload: Mapping[str, object]) -> int | None:
        raw_timestamp = str(payload.get("timestamp") or "").strip()
        if not raw_timestamp:
            return None
        normalized = raw_timestamp.replace("Z", "+00:00")
        try:
            parsed = datetime.fromisoformat(normalized)
        except ValueError:
            return None
        if parsed.tzinfo is None:
            parsed = parsed.replace(tzinfo=timezone.utc)
        return int(parsed.timestamp() * 1_000_000_000)

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
                    "event_time_ns": self._payload_timestamp_ns(payload),
                    "observed_monotonic_ns": time.monotonic_ns(),
                    "source": "collector",
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
        tracee_tmpdir = _tracee_runtime_dir()
        event_output_path = _tracee_event_output_path()
        tracee_tmpdir.mkdir(parents=True, exist_ok=True)
        event_output_path.unlink(missing_ok=True)
        for command in self.commands:
            self.collector = TraceeOutputCollector(event_output_path)
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
                args=(event_output_path, self.event_stop),
                daemon=True,
            )
            self.stdout_thread.start()
            self.stderr_thread.start()
            self.event_thread.start()

            try:
                healthy = wait_healthy(
                    proc,
                    self.load_timeout,
                    lambda: (
                        _tracee_healthz_ready(TRACEE_HEALTH_HOST, TRACEE_HEALTH_PORT)
                        or _tracee_collector_has_activity(self.collector)
                    )
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


def inspect_tracee_setup() -> dict[str, object]:
    corpus_binary = repo_artifact_root() / "tracee" / "bin" / "tracee"
    tracee_binary = pick_host_executable(corpus_binary)
    if tracee_binary is None:
        return {
            "returncode": 1,
            "tracee_binary": None,
            "stdout_tail": "",
            "stderr_tail": f"missing repo-managed Tracee binary under {corpus_binary}",
        }
    version_probe = run_command([str(tracee_binary), "--version"], check=False, timeout=30)
    if version_probe.returncode != 0:
        version_probe = run_command([str(tracee_binary), "version"], check=False, timeout=30)
    if version_probe.returncode != 0:
        return {
            "returncode": version_probe.returncode,
            "tracee_binary": str(tracee_binary),
            "stdout_tail": tail_text(version_probe.stdout or "", max_lines=40, max_chars=8000),
            "stderr_tail": tail_text(version_probe.stderr or "", max_lines=40, max_chars=8000),
        }
    return {
        "returncode": 0,
        "tracee_binary": str(tracee_binary),
        "stdout_tail": f"TRACEE_BINARY={tracee_binary}",
        "stderr_tail": "",
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


def _tracee_signatures_dir() -> Path:
    sig_dir = _tracee_runtime_dir() / "signatures"
    sig_dir.mkdir(parents=True, exist_ok=True)
    return sig_dir


def _tracee_healthz_ready(host: str, port: int) -> bool:
    try:
        with urlopen(f"http://{host}:{int(port)}/healthz", timeout=1.0) as response:
            return int(getattr(response, "status", 0) or 0) == 200
    except (OSError, URLError):
        return False


def _tracee_collector_has_activity(collector: TraceeOutputCollector) -> bool:
    snapshot = collector.snapshot()
    return bool(snapshot.get("event_tail") or snapshot.get("stdout_tail") or snapshot.get("stderr_tail"))


def _tracee_output_args(event_output_path: Path) -> list[str]:
    return ["--output", f"json:{event_output_path}"]


def build_tracee_commands(binary: str, events: Sequence[str], extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_text = ",".join(str(event) for event in events)
    sig_dir = _tracee_signatures_dir()
    output_args = _tracee_output_args(_tracee_event_output_path())
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
            resolve_workload_tool("wrk")
            return run_network_load(duration_s)
        return run_connect_storm(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")


DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"
DEFAULT_LOAD_TIMEOUT_S = 20
DEFAULT_STARTUP_SETTLE_S = 5.0


def _default_events() -> tuple[str, ...]:
    payload = yaml.safe_load(DEFAULT_CONFIG.read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise RuntimeError(f"Tracee config must be a mapping: {DEFAULT_CONFIG}")
    raw_events = payload.get("events") or []
    if not isinstance(raw_events, Sequence) or isinstance(raw_events, (str, bytes, bytearray)):
        raise RuntimeError(f"Tracee config field 'events' must be a sequence: {DEFAULT_CONFIG}")
    return tuple(str(event) for event in raw_events if str(event).strip())


class TraceeRunner(AppRunner):
    required_remote_commands = ("ip", "taskset", "setpriv", "curl", "wrk")

    def __init__(
        self,
        *,
        tracee_binary: Path | str | None = None,
        events: Sequence[str] = (),
        extra_args: Sequence[str] = (),
        expected_program_names: Sequence[str] = (),
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        startup_settle_s: float = DEFAULT_STARTUP_SETTLE_S,
        workload_spec: Mapping[str, object] | None = None,
    ) -> None:
        super().__init__()
        self.tracee_binary = None if tracee_binary is None else Path(tracee_binary).resolve()
        self.events = tuple(str(event) for event in (events or _default_events()) if str(event).strip())
        self.extra_args = tuple(str(arg) for arg in extra_args)
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.load_timeout_s = int(load_timeout_s)
        self.startup_settle_s = float(startup_settle_s)
        self.session: Any | None = None
        self.setup_result: dict[str, object] = {"returncode": 0, "tracee_binary": None, "stdout_tail": "", "stderr_tail": ""}
        self.workload_spec: Mapping[str, object] = dict(workload_spec or {"kind": "exec_storm"})

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    @property
    def collector(self) -> TraceeOutputCollector | None:
        return None if self.session is None else self.session.collector

    @property
    def program_fds(self) -> dict[int, int]:
        return {} if self.session is None else dict(self.session.program_fds)

    def _resolve_binary(self) -> str:
        resolved = resolve_tracee_binary(None if self.tracee_binary is None else str(self.tracee_binary), self.setup_result)
        if resolved is None:
            self.setup_result = inspect_tracee_setup()
            if int(self.setup_result.get("returncode", 0) or 0) != 0:
                details = str(self.setup_result.get("stderr_tail") or self.setup_result.get("stdout_tail") or self.setup_result)
                raise RuntimeError(f"Tracee setup failed: {details}")
            resolved = resolve_tracee_binary(
                None if self.tracee_binary is None else str(self.tracee_binary),
                self.setup_result,
            )
        if resolved is None:
            raise RuntimeError("Tracee binary not found; provide --tracee-binary or prepare the repo-managed Tracee binary")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("TraceeRunner is already running")
        if not self.events:
            raise RuntimeError("TraceeRunner requires at least one Tracee event")

        tracee_binary = self._resolve_binary()
        commands = build_tracee_commands(tracee_binary, self.events, self.extra_args)
        session = TraceeAgentSession(commands, self.load_timeout_s)
        session.__enter__()
        self.session = session
        self.command_used = list(session.command_used or [])
        programs = [dict(program) for program in session.programs]
        if not programs:
            self._fail_start("Tracee did not attach any BPF programs")
        if self.expected_program_names:
            programs = self._filter_expected_programs(
                programs,
                self.expected_program_names,
                owner_label="Tracee",
            )
        self.tracee_binary = Path(tracee_binary).resolve()
        self.programs = programs
        # Tracee can expose loader-owned program FDs before the probes begin
        # processing events on slow single-vCPU TCG guests. Settle startup here
        # so corpus/e2e measurements begin only after the native loader is ready.
        if self.startup_settle_s > 0.0:
            time.sleep(self.startup_settle_s)
        return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        return run_tracee_workload(self.workload_spec, max(1, int(round(seconds))))

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        return run_tracee_workload(workload_spec, max(1, int(round(seconds))))

    def select_corpus_program_ids(
        self,
        initial_stats: Mapping[int, Mapping[str, object]],
        final_stats: Mapping[int, Mapping[str, object]],
    ) -> list[int] | None:
        selected: list[int] = []
        for program in self.programs:
            prog_id = int(program.get("id", 0) or 0)
            if prog_id <= 0:
                continue
            before = initial_stats.get(prog_id) or {}
            after = final_stats.get(prog_id) or {}
            run_cnt_delta = int(after.get("run_cnt", 0) or 0) - int(before.get("run_cnt", 0) or 0)
            run_time_delta = int(after.get("run_time_ns", 0) or 0) - int(before.get("run_time_ns", 0) or 0)
            if run_cnt_delta > 0 or run_time_delta > 0:
                selected.append(prog_id)
        return selected

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        snapshot = session.collector_snapshot()
        process = session.process
        session.close()
        self.process_output = {
            "returncode": None if process is None else process.returncode,
            "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
            "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
            "latest_stats": snapshot.get("latest_stats") or {},
        }


__all__ = [
    "TraceeAgentSession",
    "TraceeOutputCollector",
    "TraceeRunner",
    "build_tracee_commands",
    "inspect_tracee_setup",
    "resolve_tracee_binary",
    "run_tracee_workload",
]
