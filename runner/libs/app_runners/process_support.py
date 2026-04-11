from __future__ import annotations

import os
import subprocess
import threading
import time
from collections import deque
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, tail_text
from ..agent import find_bpf_programs, stop_agent, wait_healthy
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner


def wait_for_attached_programs(
    process: Any,
    *,
    expected_count: int,
    timeout_s: int,
) -> list[dict[str, object]]:
    """Poll bpftool until at least `expected_count` BPF programs are stably attached."""
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
    """Base class for agent sessions that start a process and consume its output."""

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
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
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
        merged_env = dict(os.environ)
        if self.env is not None:
            merged_env.update(self.env)
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
            healthy = wait_healthy(
                self.process,
                self.load_timeout_s,
                lambda: bool(self._discover_programs()),
            )
        except Exception:
            self.close()
            raise
        if not healthy:
            details = tail_text(
                "\n".join(
                    list(self.collector.snapshot().get("stderr_tail") or [])
                    + list(self.collector.snapshot().get("stdout_tail") or [])
                ),
                max_lines=40,
                max_chars=8000,
            )
            self.close()
            raise RuntimeError(f"native app did not attach BPF programs within {self.load_timeout_s}s: {details}")
        self.programs = self._discover_programs()
        if not self.programs:
            self.close()
            raise RuntimeError("native app became healthy but no BPF programs were discovered")
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def _discover_programs(self) -> list[dict[str, object]]:
        if self.pid is None or self.pid <= 0:
            return []
        programs = [dict(item) for item in find_bpf_programs(self.pid)]
        programs.sort(key=lambda item: int(item.get("id", 0) or 0))
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

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        del exc_type, exc, tb
        self.close()


class NativeProcessRunner(AppRunner):
    def __init__(
        self,
        *,
        loader_binary: Path | str | None = None,
        loader_args: Sequence[str] = (),
        expected_program_names: Sequence[str] = (),
        load_timeout_s: int = 20,
        workload_kind: str | None = None,
    ) -> None:
        super().__init__()
        self.loader_binary = None if loader_binary is None else Path(loader_binary).resolve()
        self.loader_args = tuple(str(arg) for arg in loader_args if str(arg).strip())
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
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
        programs = [dict(program) for program in session.programs]
        if not programs:
            self._fail_start("native app did not attach any BPF programs")
        if self.expected_program_names:
            programs = self._filter_expected_programs(
                programs,
                self.expected_program_names,
                owner_label="native app",
            )
        self.loader_binary = binary
        self.programs = programs
        return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"{type(self).__name__} is not running")
        if not self.workload_kind:
            raise RuntimeError(f"{type(self).__name__} requires an explicit workload_kind")
        return run_named_workload(self.workload_kind, seconds)

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
