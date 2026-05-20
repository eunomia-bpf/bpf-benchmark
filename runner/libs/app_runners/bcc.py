from __future__ import annotations

import io
import os
import subprocess
import threading
from collections import deque
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from .. import tail_text
from ..agent import stop_agent
from .base import AppRunner

DEFAULT_ATTACH_TIMEOUT_SECONDS = 150


@dataclass
class ToolProcessSession:
    process: subprocess.Popen[str]
    stdout_capture: "_TailCapture"
    stderr_capture: "_TailCapture"
    stdout_thread: threading.Thread
    stderr_thread: threading.Thread


class _TailCapture:
    def __init__(self, *, max_lines: int, max_chars: int) -> None:
        self.max_lines = max(1, int(max_lines))
        self.max_chars = max(1, int(max_chars))
        self._chunks: deque[str] = deque()
        self._chars = 0
        self._lock = threading.Lock()

    def append(self, text: str) -> None:
        if not text:
            return
        with self._lock:
            self._chunks.append(text)
            self._chars += len(text)
            while self._chars > self.max_chars and self._chunks:
                removed = self._chunks.popleft()
                self._chars -= len(removed)

    def render(self) -> str:
        with self._lock:
            return tail_text("".join(self._chunks), max_lines=self.max_lines, max_chars=self.max_chars)


def _drain_stream(stream: io.TextIOBase, capture: _TailCapture) -> None:
    with stream:
        for chunk in stream:
            capture.append(chunk)


def inspect_bcc_setup() -> dict[str, object]:
    return {
        "returncode": 0,
        "tools_dir": "/usr/local/bin",
        "stdout_tail": "",
        "stderr_tail": "",
    }


def resolve_tools_dir(
    explicit: str | Path | None = None,
    *,
    setup_result: Mapping[str, object] | None = None,
) -> Path:
    if explicit:
        candidate = Path(explicit)
        if candidate.is_dir():
            return candidate.resolve()
    setup_dir = str((setup_result or {}).get("tools_dir") or "").strip()
    if setup_dir:
        for item in setup_dir.split(os.pathsep):
            candidate = Path(item)
            if candidate.is_dir():
                return candidate.resolve()
    return Path("/usr/local/bin")


def find_tool_binary(tools_dir: Path, tool_name: str) -> Path | None:
    binary_name = str(tool_name).strip()
    if not binary_name or binary_name.endswith("-bpfcc"):
        return None
    candidate = tools_dir / binary_name
    if candidate.is_file() and os.access(candidate, os.X_OK):
        with candidate.open("rb") as file_obj:
            if file_obj.read(4) == b"\x7fELF":
                return candidate.resolve()
    return None


class BCCRunner(AppRunner):
    def __init__(
        self,
        *,
        tool_binary: Path | str,
        tool_args: Sequence[str],
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_SECONDS,
    ) -> None:
        super().__init__()
        self.tool_binary = Path(tool_binary).resolve()
        self.tool_name = self.tool_binary.name
        self.tool_args = tuple(str(arg) for arg in tool_args if str(arg).strip())
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = int(attach_timeout_s)
        self.session: ToolProcessSession | None = None

    @property
    def pid(self) -> int | None:
        return None if self.session is None else int(self.session.process.pid or 0)

    def _resolve_tool_binary(self) -> Path:
        if not self.tool_binary.exists():
            raise RuntimeError(f"BCC libbpf-tool binary not found: {self.tool_binary}")
        if not os.access(self.tool_binary, os.X_OK):
            raise RuntimeError(f"BCC libbpf-tool binary is not executable: {self.tool_binary}")
        return self.tool_binary

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        stop_error: Exception | None = None
        try:
            stop_agent(session.process, timeout=80)
        except Exception as exc:
            stop_error = exc

        io_errors: list[str] = []
        for name, thread in (("stdout", session.stdout_thread), ("stderr", session.stderr_thread)):
            thread.join(timeout=20.0)
            if thread.is_alive():
                io_errors.append(f"timed out waiting for BCC {name} capture thread to drain")
        self.process_output = {
            "returncode": session.process.returncode,
            "stdout_tail": session.stdout_capture.render(),
            "stderr_tail": session.stderr_capture.render(),
        }

        failures: list[str] = []
        if stop_error is not None:
            failures.append(str(stop_error))
        failures.extend(io_errors)
        if failures:
            raise RuntimeError("; ".join(failures))
