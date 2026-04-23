from __future__ import annotations

import os
import subprocess
import threading
import time
from collections import deque
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, tail_text
from ..agent import bpftool_prog_show_records, stop_agent, wait_healthy


def wait_until_program_set_stable(
    *,
    before_ids: Sequence[int] = (),
    timeout_s: float,
    stable_window_s: float = 2.0,
    poll_interval_s: float = 0.2,
) -> list[dict[str, object]]:
    baseline_ids = {int(prog_id) for prog_id in before_ids if int(prog_id) > 0}
    deadline = time.monotonic() + max(0.0, float(timeout_s))
    stable_window = max(0.0, float(stable_window_s))
    poll_interval = max(0.05, float(poll_interval_s))
    last_ids: tuple[int, ...] | None = None
    last_change_at: float | None = None
    last_programs: list[dict[str, object]] = []
    while True:
        now = time.monotonic()
        programs = [
            dict(record)
            for record in bpftool_prog_show_records()
            if int(record.get("id", -1) or -1) not in baseline_ids
        ]
        programs.sort(key=lambda item: int(item.get("id", 0) or 0))
        program_ids = tuple(int(program.get("id", 0) or 0) for program in programs)
        if program_ids != last_ids:
            last_ids = program_ids
            last_change_at = now
            last_programs = [dict(program) for program in programs]
        elif programs and last_change_at is not None and (now - last_change_at) >= stable_window:
            return [dict(program) for program in programs]
        if now >= deadline:
            preview = ",".join(str(pid) for pid in (last_ids or ())[:12]) or "<none>"
            raise RuntimeError(
                "BPF program set did not stabilize before timeout "
                f"(timeout_s={timeout_s}, last_program_count={len(last_programs)}, "
                f"last_program_ids={preview})"
            )
        time.sleep(min(poll_interval, max(0.0, deadline - now)))


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
        self.before_ids: set[int] = set()

    def __enter__(self) -> "ManagedProcessSession":
        merged_env = dict(os.environ)
        if self.env is not None:
            merged_env.update(self.env)
        self.before_ids = {
            int(record.get("id", 0) or 0)
            for record in bpftool_prog_show_records()
            if int(record.get("id", 0) or 0) > 0
        }
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
        self.programs = wait_until_program_set_stable(before_ids=self.before_ids, timeout_s=self.load_timeout_s)
        if not self.programs:
            self.close()
            raise RuntimeError("native app became healthy but no BPF programs were discovered")
        return self

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def _discover_programs(self) -> list[dict[str, object]]:
        programs = [
            dict(record)
            for record in bpftool_prog_show_records()
            if int(record.get("id", -1) or -1) not in self.before_ids
        ]
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
