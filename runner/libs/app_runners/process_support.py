from __future__ import annotations

import os
import subprocess
import threading
from collections import deque
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, tail_text
from ..agent import stop_agent
from ..rejit import wait_for_app_shim_programs
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner


def describe_process_exit(process_name: str, process: Any | None, snapshot: Mapping[str, object]) -> str | None:
    if process is None:
        return f"{process_name} process handle is unavailable"
    returncode = process.poll()
    if returncode is None:
        return None
    combined = "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or []))
    details = tail_text(combined, max_lines=40, max_chars=8000)
    return f"{process_name} exited with code {returncode}" + (f": {details}" if details else "")


class ProcessOutputCollector:
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


class AgentSession:
    def __init__(self, load_timeout: int) -> None:
        self.load_timeout = int(load_timeout)
        self.process: Any | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.programs: list[dict[str, object]] = []

    def _start_io_threads(self) -> None:
        assert self.process is not None
        assert self.process.stdout is not None
        assert self.process.stderr is not None
        self.stdout_thread = threading.Thread(
            target=self.collector.consume_stdout, args=(self.process.stdout,), daemon=True
        )
        self.stderr_thread = threading.Thread(
            target=self.collector.consume_stderr, args=(self.process.stderr,), daemon=True
        )
        self.stdout_thread.start()
        self.stderr_thread.start()

    def _join_io_threads(self) -> None:
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=20.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=20.0)
            self.stderr_thread = None

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def __enter__(self) -> "AgentSession":
        raise NotImplementedError

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        self.close()

    def close(self) -> None:
        raise NotImplementedError


class ManagedProcessSession:
    def __init__(
        self,
        command: Sequence[str],
        *,
        load_timeout_s: int,
        cwd: Path | None = None,
        env: Mapping[str, str] | None = None,
    ) -> None:
        self.command = [str(item) for item in command]
        self.load_timeout_s = int(load_timeout_s)
        self.cwd = None if cwd is None else Path(cwd).resolve()
        self.env = None if env is None else {str(key): str(value) for key, value in env.items()}
        self.process: Any | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.programs: list[dict[str, object]] = []

    def __enter__(self) -> "ManagedProcessSession":
        from ..agent import _shim_env_for, _SHIM_SOCK_DIR
        merged_env = dict(os.environ)
        # Inject LD_PRELOAD + shim socket dir based on the target binary's libc
        # variant, same contract as agent.start_agent for bpftrace/bcc/tracee.
        # Without this, katran's ManagedProcessSession spawns without the shim
        # and apply_rejit can't find a per-pid socket.
        merged_env.update(_shim_env_for(self.command[0]))
        if self.env is not None:
            merged_env.update(self.env)
        os.makedirs(_SHIM_SOCK_DIR, exist_ok=True)
        self.process = subprocess.Popen(
            self.command,
            cwd=self.cwd or ROOT_DIR,
            env=merged_env,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        assert self.process.stdout is not None
        assert self.process.stderr is not None
        self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(self.process.stdout,), daemon=True)
        self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(self.process.stderr,), daemon=True)
        self.stdout_thread.start()
        self.stderr_thread.start()
        try:
            wait_for_app_shim_programs(
                app_pid=int(self.process.pid),
                timeout_s=self.load_timeout_s,
                process=self.process,
                snapshot=self.collector_snapshot,
                process_name="native app",
            )
        except Exception:
            self.close()
            raise
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        if self.process is not None:
            stop_agent(self.process, timeout=80)
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=20.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=20.0)
            self.stderr_thread = None

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        del exc_type, exc, tb
        self.close()


class NativeProcessRunner(AppRunner):
    def __init__(
        self,
        *,
        loader_binary: Path | str | None = None,
        loader_args: Sequence[str] = (),
        load_timeout_s: int = 200,
        workload_kind: str | None = None,
    ) -> None:
        super().__init__()
        self.loader_binary = None if loader_binary is None else Path(loader_binary).resolve()
        self.loader_args = tuple(str(arg) for arg in loader_args if str(arg).strip())
        self.load_timeout_s = int(load_timeout_s)
        self.workload_kind = str(workload_kind or "").strip()
        self.session: ManagedProcessSession | None = None

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return ()

    def _resolve_binary(self) -> Path:
        candidates: list[Path] = []
        if self.loader_binary is not None:
            candidates.append(self.loader_binary)
        candidates.extend(candidate.resolve() for candidate in self._default_binary_candidates())
        for candidate in candidates:
            if candidate.is_file() and os.access(candidate, os.X_OK):
                return candidate
        rendered = ", ".join(str(candidate) for candidate in candidates) or "<none>"
        raise RuntimeError(f"native app binary not found or not executable; tried: {rendered}")

    def _command(self, binary: Path) -> list[str]:
        return [str(binary), *self.loader_args]

    def _command_cwd(self) -> Path | None:
        return ROOT_DIR

    def _command_env(self) -> Mapping[str, str] | None:
        return None

    def _run_workload(self, seconds: float) -> WorkloadResult:
        if not self.workload_kind:
            raise RuntimeError(f"{type(self).__name__} requires an explicit workload_kind")
        return run_named_workload(self.workload_kind, seconds)

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError(f"{type(self).__name__} is already running")
        binary = self._resolve_binary()
        command = self._command(binary)
        session = ManagedProcessSession(
            command,
            load_timeout_s=self.load_timeout_s,
            cwd=self._command_cwd(),
            env=self._command_env(),
        )
        session.__enter__()
        self.session = session
        self.command_used = list(command)
        self.loader_binary = binary
        self.programs = []
        return []

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        return self._run_workload(seconds)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds)

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        process = session.process
        self.session = None
        snapshot = session.collector_snapshot()
        session.close()
        self.process_output = {
            "returncode": None if process is None else process.returncode,
            "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
            "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
        }
