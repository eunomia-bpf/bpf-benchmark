from __future__ import annotations

import os
import shlex
import subprocess
import threading
import time
from collections import deque
from pathlib import Path
from typing import Any, Mapping, Sequence
from urllib.error import URLError
from urllib.request import urlopen

from .. import ROOT_DIR, run_command, tail_text, which
from ..agent import (
    bpftool_prog_show_records,
    start_agent,
    stop_agent,
    wait_healthy,
)
from ..workload import (
    WorkloadResult,
    resolve_workload_tool,
    run_block_io_load,
    run_connect_storm,
    run_file_open_load,
    run_named_workload,
    run_network_load,
    run_open_storm,
    run_scheduler_load,
    run_tracee_default_load,
    run_tracee_io_vector_mix_workload,
    run_tracee_module_load_loop_workload,
    run_tracee_system_edge_mix_workload,
    run_user_exec_loop,
)
from .base import AppRunner
from .process_support import AgentSession, wait_until_program_set_stable
from .setup_support import pick_host_executable, repo_artifact_root


TRACEE_HEALTH_HOST = "127.0.0.1"
TRACEE_HEALTH_PORT = 3366
TRACEE_OUTPUT_MODE = "none"


def _tracee_runtime_dir() -> Path:
    if explicit := os.environ.get("BPFREJIT_TRACEE_RUNTIME_DIR", "").strip():
        candidate = Path(explicit).expanduser()
    else:
        tmpdir = os.environ.get("TMPDIR", "").strip()
        if not tmpdir:
            raise RuntimeError("TMPDIR is required for the Tracee runner")
        candidate = Path(tmpdir).expanduser() / "tracee"
    candidate.mkdir(parents=True, exist_ok=True)
    if not os.access(candidate, os.W_OK | os.X_OK):
        raise RuntimeError(f"Tracee runtime directory is not writable/executable: {candidate}")
    return candidate


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock: self.stdout_tail.append(line)
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock: self.stderr_tail.append(line)
        pipe.close()

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }


class TraceeAgentSession(AgentSession):
    def __init__(self, commands: Sequence[Sequence[str]], load_timeout: int) -> None:
        super().__init__(load_timeout)
        self.commands = [list(command) for command in commands]
        self.collector = TraceeOutputCollector()
        self.command_used: list[str] | None = None

    def __enter__(self) -> "TraceeAgentSession":
        preexisting_ids = {
            int(record["id"])
            for record in bpftool_prog_show_records()
            if "id" in record
        }
        failures: list[str] = []
        tracee_tmpdir = _tracee_runtime_dir()
        tracee_tmpdir.mkdir(parents=True, exist_ok=True)
        for command in self.commands:
            self.collector = TraceeOutputCollector()
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
            self._start_io_threads()

            def _health_check() -> bool:
                return (
                    _tracee_healthz_ready(TRACEE_HEALTH_HOST, TRACEE_HEALTH_PORT)
                    or _tracee_collector_has_activity(self.collector)
                ) and bool(
                    [
                        record
                        for record in bpftool_prog_show_records()
                        if int(record.get("id", -1) or -1) not in preexisting_ids
                    ]
                )

            try:
                healthy = wait_healthy(proc, self.load_timeout, _health_check)
            except Exception:
                self.close()
                raise
            if healthy:
                programs = wait_until_program_set_stable(before_ids=preexisting_ids, timeout_s=self.load_timeout)
                if programs:
                    self.programs = [dict(program) for program in programs]
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
        if self.process is not None:
            stop_agent(self.process, timeout=DEFAULT_STOP_TIMEOUT_S); self.process = None
        self._join_io_threads()


def inspect_tracee_setup() -> dict[str, object]:
    artifact_binary = repo_artifact_root() / "tracee" / "bin" / "tracee"
    tracee_binary = pick_host_executable(artifact_binary)
    if tracee_binary is None:
        return {"returncode": 1, "tracee_binary": None, "stdout_tail": "",
                "stderr_tail": f"missing upstream Tracee container artifact under {artifact_binary}"}
    vp = run_command([str(tracee_binary), "--version"], check=False, timeout=30)
    if vp.returncode != 0:
        vp = run_command([str(tracee_binary), "version"], check=False, timeout=30)
    if vp.returncode != 0:
        return {"returncode": vp.returncode, "tracee_binary": str(tracee_binary),
                "stdout_tail": tail_text(vp.stdout or "", max_lines=40, max_chars=8000),
                "stderr_tail": tail_text(vp.stderr or "", max_lines=40, max_chars=8000)}
    tracee_ebpf = tracee_binary.parent / "tracee-ebpf"
    stdout_tail = f"TRACEE_BINARY={tracee_binary}"
    if tracee_ebpf.is_file():
        stdout_tail += f"\nTRACEE_EBPF_BINARY={tracee_ebpf}"
    return {"returncode": 0, "tracee_binary": str(tracee_binary),
            "stdout_tail": stdout_tail, "stderr_tail": ""}


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
    return bool(snapshot.get("stdout_tail") or snapshot.get("stderr_tail"))


def build_tracee_commands(binary: str, extra_args: Sequence[str] = ()) -> list[list[str]]:
    return [[binary, "--events", "*",
             "--output", TRACEE_OUTPUT_MODE,
             "--server", "healthz", "--server", f"http-address=:{TRACEE_HEALTH_PORT}",
             "--signatures-dir", str(_tracee_signatures_dir()), *extra_args]]


def _format_launch_failure(command: Sequence[str], proc: subprocess.Popen[str] | None, snapshot: Mapping[str, object]) -> str:
    rendered = " ".join(shlex.quote(part) for part in command)
    combined = "\n".join(
        (snapshot.get("stderr_tail") or [])
        + (snapshot.get("stdout_tail") or [])
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
    if kind.startswith("stress_ng_") or kind == "fio_randrw":
        return run_named_workload(kind, duration_s)
    if kind == "tracee_default":
        return run_tracee_default_load(duration_s)
    if kind == "tracee_system_edge_mix":
        return run_tracee_system_edge_mix_workload(duration_s)
    if kind == "tracee_module_load_loop":
        return run_tracee_module_load_loop_workload(duration_s)
    if kind == "tracee_io_vector_mix":
        return run_tracee_io_vector_mix_workload(duration_s)
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

DEFAULT_LOAD_TIMEOUT_S = 120
DEFAULT_STARTUP_SETTLE_S = 5.0
DEFAULT_STOP_TIMEOUT_S = 30.0
DEFAULT_EVENT_JOIN_TIMEOUT_S = 10.0


class TraceeRunner(AppRunner):
    def __init__(
        self,
        *,
        tracee_binary: Path | str | None = None,
        extra_args: Sequence[str] = (),
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        workload_spec: Mapping[str, object] | None = None,
    ) -> None:
        super().__init__()
        self.tracee_binary = None if tracee_binary is None else Path(tracee_binary).resolve()
        self.extra_args = tuple(str(arg) for arg in extra_args)
        self.load_timeout_s = int(load_timeout_s)
        self.session: Any | None = None
        self.setup_result: dict[str, object] = {"returncode": 0, "tracee_binary": None, "stdout_tail": "", "stderr_tail": ""}
        self.workload_spec: Mapping[str, object] = {} if workload_spec is None else dict(workload_spec)

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    @property
    def collector(self) -> TraceeOutputCollector | None:
        return None if self.session is None else self.session.collector

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
            raise RuntimeError("Tracee binary not found; provide --tracee-binary or prepare the upstream Tracee container artifact")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("TraceeRunner is already running")

        tracee_binary = self._resolve_binary()
        commands = build_tracee_commands(tracee_binary, self.extra_args)
        session = TraceeAgentSession(commands, self.load_timeout_s)
        session.__enter__()
        self.session = session
        self.command_used = list(session.command_used or [])
        programs = [dict(program) for program in session.programs]
        if not programs:
            self._fail_start("Tracee did not attach any BPF programs")
        self.tracee_binary = Path(tracee_binary).resolve()
        self.programs = programs
        if DEFAULT_STARTUP_SETTLE_S > 0.0:
            time.sleep(DEFAULT_STARTUP_SETTLE_S)
        return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        if not self.workload_spec:
            raise RuntimeError("TraceeRunner run_workload() requires workload_spec")
        return run_tracee_workload(self.workload_spec, max(1, int(round(seconds))))

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        return run_tracee_workload(workload_spec, max(1, int(round(seconds))))

    def stop(self) -> None:
        if self.session is None: return
        session, self.session = self.session, None
        snapshot = session.collector_snapshot()
        process = session.process
        session.close()
        self.process_output = {"returncode": None if process is None else process.returncode,
                               "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
                               "stderr_tail": "\n".join(snapshot.get("stderr_tail") or [])}
