from __future__ import annotations

import io
import os
import subprocess
import threading
from collections import deque
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Mapping, Sequence

import yaml

from .. import ROOT_DIR, tail_text
from ..agent import stop_agent
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .process_support import wait_for_attached_programs
from .setup_support import binary_matches_host_arch, first_existing_dir, repo_artifact_root

DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "bcc" / "config.yaml"
DEFAULT_ATTACH_TIMEOUT_SECONDS = 20


def _default_tools_dir() -> Path:
    return repo_artifact_root() / "bcc" / "libbpf-tools"


@dataclass(frozen=True)
class BCCWorkloadSpec:
    name: str
    workload_kind: str
    expected_programs: int
    spawn_timeout_s: int
    tool_args: tuple[str, ...]


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


@lru_cache(maxsize=1)
def _bcc_tool_specs() -> dict[str, BCCWorkloadSpec]:
    payload = yaml.safe_load(DEFAULT_CONFIG.read_text(encoding="utf-8"))
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"BCC config must be a mapping: {DEFAULT_CONFIG}")
    tools = payload.get("tools")
    if not isinstance(tools, list):
        raise RuntimeError(f"BCC config field 'tools' must be a sequence: {DEFAULT_CONFIG}")
    specs: dict[str, BCCWorkloadSpec] = {}
    for entry in tools:
        if not isinstance(entry, Mapping):
            raise RuntimeError(f"BCC config field 'tools' contains a non-mapping entry: {DEFAULT_CONFIG}")
        name = str(entry.get("name") or "").strip()
        if not name:
            raise RuntimeError(f"BCC config field 'tools' contains an entry without a name: {DEFAULT_CONFIG}")
        specs[name] = BCCWorkloadSpec(
            name=name,
            workload_kind=str(entry.get("workload_kind") or "mixed"),
            expected_programs=int(entry.get("expected_programs", 1) or 1),
            spawn_timeout_s=int(entry.get("spawn_timeout_s", DEFAULT_ATTACH_TIMEOUT_SECONDS) or DEFAULT_ATTACH_TIMEOUT_SECONDS),
            tool_args=tuple(str(arg) for arg in entry.get("tool_args", []) if str(arg).strip()),
        )
    return specs


def inspect_bcc_setup() -> dict[str, object]:
    artifact_build_output = _default_tools_dir() / ".output"
    build_output = first_existing_dir(artifact_build_output)
    if build_output is None:
        return {
            "returncode": 1,
            "tools_dir": None,
            "stdout_tail": "",
            "stderr_tail": f"missing BCC libbpf-tools artifact output under {artifact_build_output}",
        }

    for tool_name in _bcc_tool_specs():
        candidate = build_output / tool_name
        if not candidate.is_file() or not os.access(candidate, os.X_OK):
            return {
                "returncode": 1,
                "tools_dir": str(build_output),
                "stdout_tail": "",
                "stderr_tail": f"missing repo-managed BCC libbpf-tools under {build_output}; missing {tool_name}",
            }
        if not binary_matches_host_arch(candidate):
            return {
                "returncode": 1,
                "tools_dir": str(build_output),
                "stdout_tail": "",
                "stderr_tail": f"BCC tool artifact has the wrong architecture: {candidate}",
            }

    return {
        "returncode": 0,
        "tools_dir": str(build_output),
        "stdout_tail": f"BCC_TOOLS_DIR={build_output}",
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
        candidate = Path(setup_dir)
        if candidate.is_dir():
            return candidate.resolve()
    output_subdir = _default_tools_dir() / ".output"
    if output_subdir.is_dir():
        return output_subdir.resolve()
    return _default_tools_dir().resolve()


def find_tool_binary(tools_dir: Path, tool_name: str) -> Path | None:
    for candidate in (tools_dir / tool_name, tools_dir.parent / tool_name):
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return candidate.resolve()
    return None


class BCCRunner(AppRunner):
    required_remote_commands = ("ip", "taskset", "setpriv", "curl", "stress-ng", "fio", "dd", "hackbench", "wrk")

    def __init__(
        self,
        *,
        tool_binary: Path | str | None = None,
        tool_name: str | None = None,
        tool_args: Sequence[str] | None = None,
        workload_kind: str | None = None,
        expected_programs: int | None = None,
        expected_program_names: Sequence[str] = (),
        attach_timeout_s: int | None = None,
        tools_dir: Path | str | None = None,
    ) -> None:
        super().__init__()
        resolved_tool_name = str(tool_name or "").strip()
        if not resolved_tool_name and tool_binary is None:
            raise RuntimeError("BCCRunner requires tool_binary or tool_name")

        spec = _bcc_tool_specs().get(resolved_tool_name)
        self.tool_name = resolved_tool_name or Path(str(tool_binary)).name
        self.tool_args = (
            tuple(str(arg) for arg in tool_args if str(arg).strip())
            if tool_args is not None
            else (spec.tool_args if spec else ())
        )
        self.workload_kind = workload_kind or (spec.workload_kind if spec else "mixed")
        self.expected_programs = int(expected_programs or (spec.expected_programs if spec else max(1, len(tuple(expected_program_names)) or 1)))
        self.attach_timeout_s = int(attach_timeout_s or (spec.spawn_timeout_s if spec else DEFAULT_ATTACH_TIMEOUT_SECONDS))
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.setup_result: dict[str, object] = {
            "returncode": 0,
            "tools_dir": None,
            "stdout_tail": "",
            "stderr_tail": "",
        }
        self.explicit_tools_dir = Path(tools_dir).resolve() if tools_dir is not None else None
        self.tools_dir = resolve_tools_dir(self.explicit_tools_dir)
        self.tool_binary = Path(tool_binary).resolve() if tool_binary is not None else None
        self.session: ToolProcessSession | None = None

    @property
    def pid(self) -> int | None:
        return None if self.session is None else int(self.session.process.pid or 0)

    def _resolve_tool_binary(self) -> Path:
        if self.tool_binary is not None:
            if not self.tool_binary.exists():
                raise RuntimeError(f"BCC tool binary not found: {self.tool_binary}")
            if not os.access(self.tool_binary, os.X_OK):
                raise RuntimeError(f"BCC tool binary is not executable: {self.tool_binary}")
            return self.tool_binary

        self.setup_result = inspect_bcc_setup()
        if int(self.setup_result.get("returncode", 0) or 0) != 0:
            stderr_tail = str(self.setup_result.get("stderr_tail") or "")
            raise RuntimeError(f"BCC setup failed: {stderr_tail or self.setup_result}")
        self.tools_dir = resolve_tools_dir(self.explicit_tools_dir, setup_result=self.setup_result)

        tool_binary = find_tool_binary(self.tools_dir, self.tool_name)
        if tool_binary is None:
            raise RuntimeError(f"BCC tool '{self.tool_name}' not found in {self.tools_dir}")
        self.tool_binary = tool_binary
        return tool_binary

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError(f"BCC tool {self.tool_name} is already running")

        tool_binary = self._resolve_tool_binary()
        command = [str(tool_binary), *self.tool_args]
        self.command_used = list(command)
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            env=os.environ.copy(),
            stdin=subprocess.DEVNULL,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        if process.stdout is None or process.stderr is None:
            process.kill()
            raise RuntimeError(f"BCC tool {self.tool_name} did not expose stdout/stderr pipes")
        stdout_capture = _TailCapture(max_lines=40, max_chars=8000)
        stderr_capture = _TailCapture(max_lines=40, max_chars=8000)
        stdout_thread = threading.Thread(
            target=_drain_stream,
            args=(process.stdout, stdout_capture),
            daemon=True,
        )
        stderr_thread = threading.Thread(
            target=_drain_stream,
            args=(process.stderr, stderr_capture),
            daemon=True,
        )
        stdout_thread.start()
        stderr_thread.start()
        self.session = ToolProcessSession(
            process=process,
            stdout_capture=stdout_capture,
            stderr_capture=stderr_capture,
            stdout_thread=stdout_thread,
            stderr_thread=stderr_thread,
        )
        programs = wait_for_attached_programs(
            process,
            expected_count=self.expected_programs,
            timeout_s=self.attach_timeout_s,
        )
        if not programs:
            return self._fail_start(
                f"BCC tool {self.tool_name} did not attach any BPF programs within {self.attach_timeout_s}s"
            )
        if len(programs) < self.expected_programs:
            attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
            return self._fail_start(
                f"BCC tool {self.tool_name} attached {len(programs)} programs, expected at least {self.expected_programs}: {attached_names}"
            )

        if self.expected_program_names:
            programs = self._filter_expected_programs(
                programs,
                self.expected_program_names,
                owner_label=f"BCC tool {self.tool_name}",
            )

        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"BCC tool {self.tool_name} is not running")
        return run_named_workload(self.workload_kind, seconds, network_as_tcp_connect=True)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"BCC tool {self.tool_name} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"BCC tool {self.tool_name} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds, network_as_tcp_connect=True)

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        stop_error: Exception | None = None
        try:
            stop_agent(session.process, timeout=8)
        except Exception as exc:
            stop_error = exc

        io_errors: list[str] = []
        for name, thread in (("stdout", session.stdout_thread), ("stderr", session.stderr_thread)):
            thread.join(timeout=2.0)
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


