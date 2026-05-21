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

from .. import ROOT_DIR, run_command, tail_text
from ..agent import (
    start_agent,
    stop_agent,
    wait_healthy,
)
from ..rejit import app_shim_has_programs, skip_rejit_disables_shim, wait_for_app_shim_programs
from ..workload import (
    WorkloadResult,
    run_named_workload,
)
from .base import AppRunner
from .process_support import AgentSession
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
    def __init__(self, commands: Sequence[Sequence[str]]) -> None:
        super().__init__()
        self.commands = [list(command) for command in commands]
        self.collector = TraceeOutputCollector()
        self.command_used: list[str] | None = None

    def __enter__(self) -> "TraceeAgentSession":
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
                ) and (skip_rejit_disables_shim() or app_shim_has_programs(int(proc.pid)))

            try:
                healthy = wait_healthy(proc, None, _health_check)
            except Exception:
                self.close()
                raise
            if healthy:
                try:
                    wait_for_app_shim_programs(
                        app_pid=int(proc.pid),
                        process=proc,
                        snapshot=self.collector_snapshot,
                        process_name="Tracee",
                    )
                except Exception:
                    self.close()
                    raise
                self.programs = []
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
    vp = run_command([str(tracee_binary), "--version"], check=False)
    if vp.returncode != 0:
        vp = run_command([str(tracee_binary), "version"], check=False)
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
        with urlopen(f"http://{host}:{int(port)}/healthz") as response:
            return int(getattr(response, "status", 0) or 0) == 200
    except (OSError, URLError):
        return False


def _tracee_collector_has_activity(collector: TraceeOutputCollector) -> bool:
    snapshot = collector.snapshot()
    return bool(snapshot.get("stdout_tail") or snapshot.get("stderr_tail"))


def build_tracee_commands(binary: str, extra_args: Sequence[str] = ()) -> list[list[str]]:
    # --capabilities bypass=true keeps CAP_BPF + CAP_PERFMON effective for the
    # whole tracee process lifetime. Default tracee parks them in a separate
    # "EBPF ring" and only enters that ring around its own BPF syscalls; the
    # bpfrejit shim performs BPF_PROG_LOAD inline from a runner-driven socket
    # request, which lands outside the ring and would otherwise EPERM at
    # kernel/bpf/syscall.c:2913 (bpf_token_capable check).
    return [[binary, "--events", "*",
             "--output", TRACEE_OUTPUT_MODE,
             "--server", "healthz", "--server", f"http-address=:{TRACEE_HEALTH_PORT}",
             "--signatures-dir", str(_tracee_signatures_dir()),
             "--capabilities", "bypass=true",
             *extra_args]]


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
    if kind.startswith("stress_ng_") or kind in ("fio_randrw", "fio"):
        return run_named_workload(kind, duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")

DEFAULT_STARTUP_SETTLE_S = 5.0
DEFAULT_STOP_TIMEOUT_S = 300.0


class TraceeRunner(AppRunner):
    def __init__(
        self,
        *,
        tracee_binary: Path | str | None = None,
        extra_args: Sequence[str] = (),
        workload_spec: Mapping[str, object] | None = None,
    ) -> None:
        super().__init__()
        self.tracee_binary = None if tracee_binary is None else Path(tracee_binary).resolve()
        self.extra_args = tuple(str(arg) for arg in extra_args)
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
        session = TraceeAgentSession(commands)
        session.__enter__()
        self.session = session
        self.command_used = list(session.command_used or [])
        self.tracee_binary = Path(tracee_binary).resolve()
        self.programs = []
        if DEFAULT_STARTUP_SETTLE_S > 0.0:
            time.sleep(DEFAULT_STARTUP_SETTLE_S)
        return []

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
