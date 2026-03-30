from __future__ import annotations

import os
import subprocess
import tempfile
import time
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Any, Mapping, NoReturn, Sequence

import yaml

from .. import ROOT_DIR, run_command, tail_text
from ..agent import find_bpf_programs, stop_agent
from ..workload import (
    WorkloadResult,
    run_bind_storm,
    run_dd_read_load,
    run_exec_storm,
    run_file_io,
    run_file_open_load,
    run_named_workload as run_shared_workload,
    run_scheduler_load,
    run_tcp_connect_load,
    run_user_exec_loop,
)


DEFAULT_SETUP_SCRIPT = ROOT_DIR / "e2e" / "cases" / "bcc" / "setup.sh"
DEFAULT_TOOLS_DIR = ROOT_DIR / "runner" / "repos" / "bcc" / "libbpf-tools"
DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "bcc" / "config.yaml"
DEFAULT_ATTACH_TIMEOUT_SECONDS = 20


@dataclass(frozen=True, slots=True)
class BCCWorkloadSpec:
    name: str
    workload_kind: str
    expected_programs: int
    spawn_timeout_s: int
    tool_args: tuple[str, ...]


@dataclass(slots=True)
class ToolProcessSession:
    process: subprocess.Popen[str]
    tempdir: Any
    stdout_path: Path
    stderr_path: Path
    stdout_handle: Any
    stderr_handle: Any


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


def run_setup_script(setup_script: Path = DEFAULT_SETUP_SCRIPT) -> dict[str, object]:
    completed = run_command(["bash", str(setup_script)], check=False, timeout=1800)
    result: dict[str, object] = {
        "returncode": completed.returncode,
        "tools_dir": None,
        "stdout_tail": tail_text(completed.stdout or "", max_lines=60, max_chars=12000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=60, max_chars=12000),
    }
    for line in (completed.stdout or "").splitlines():
        if line.startswith("BCC_TOOLS_DIR="):
            value = line.split("=", 1)[1].strip()
            result["tools_dir"] = value or None
            break
    return result


def resolve_tools_dir(
    explicit: str | Path | None = None,
    *,
    setup_result: Mapping[str, object] | None = None,
) -> Path:
    if explicit:
        candidate = Path(explicit)
        if candidate.is_dir():
            return candidate.resolve()
    env_dir = os.environ.get("BCC_TOOLS_DIR", "").strip()
    if env_dir:
        candidate = Path(env_dir)
        if candidate.is_dir():
            return candidate.resolve()
    setup_dir = str((setup_result or {}).get("tools_dir") or "").strip()
    if setup_dir:
        candidate = Path(setup_dir)
        if candidate.is_dir():
            return candidate.resolve()
    output_subdir = DEFAULT_TOOLS_DIR / ".output"
    if output_subdir.is_dir():
        return output_subdir.resolve()
    return DEFAULT_TOOLS_DIR.resolve()


def find_tool_binary(tools_dir: Path, tool_name: str) -> Path | None:
    for candidate in (tools_dir / tool_name, tools_dir.parent / tool_name):
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return candidate.resolve()
    return None


def wait_for_attached_programs(
    process: subprocess.Popen[str],
    *,
    expected_count: int,
    timeout_s: int,
) -> list[dict[str, object]]:
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


def _run_named_workload(kind: str, duration_s: float) -> WorkloadResult:
    whole_seconds = max(1, int(round(duration_s)))
    normalized = str(kind or "").strip()
    if normalized == "mixed":
        return _run_mixed_workload(duration_s)
    if kind == "tcp_connect":
        return run_tcp_connect_load(whole_seconds)
    if kind == "dd_read":
        return run_dd_read_load(whole_seconds)
    if kind == "scheduler":
        return run_scheduler_load(whole_seconds)
    if kind == "exec_storm":
        return run_exec_storm(whole_seconds, rate=2)
    if kind == "exec_loop":
        return run_user_exec_loop(whole_seconds)
    if kind == "file_open":
        return run_file_open_load(whole_seconds)
    if kind == "bind_storm":
        return run_bind_storm(whole_seconds)
    if normalized == "fio":
        return run_file_io(whole_seconds)
    if normalized == "file_open_storm":
        return run_file_open_load(whole_seconds)
    if normalized == "hackbench":
        return run_scheduler_load(whole_seconds)
    if normalized == "network":
        # BCC's network tools are mostly connect-oriented; a TCP connect loop is
        # the lightest workload that still fires these probes reliably in VM.
        return run_tcp_connect_load(whole_seconds)
    if normalized == "mixed_system":
        return _run_mixed_workload(duration_s)
    try:
        return run_shared_workload(normalized, whole_seconds)
    except RuntimeError as exc:
        raise RuntimeError(f"unsupported BCC workload kind: {kind!r}") from exc


def _run_mixed_workload(duration_s: float) -> WorkloadResult:
    segments = (
        ("exec_loop", 0.25),
        ("file_open", 0.20),
        ("dd_read", 0.20),
        ("tcp_connect", 0.20),
        ("bind_storm", 0.10),
        ("scheduler", 0.05),
    )
    remaining = max(1.0, float(duration_s))
    results: list[WorkloadResult] = []
    for index, (kind, share) in enumerate(segments, start=1):
        if index == len(segments):
            slice_seconds = max(1.0, remaining)
        else:
            slice_seconds = max(1.0, round(duration_s * share))
            remaining -= slice_seconds
        results.append(_run_named_workload(kind, slice_seconds))
    total_duration = sum(result.duration_s for result in results)
    total_ops = sum(result.ops_total for result in results)
    stdout = "\n".join(result.stdout for result in results if result.stdout)
    stderr = "\n".join(result.stderr for result in results if result.stderr)
    return WorkloadResult(
        ops_total=total_ops,
        ops_per_sec=(total_ops / total_duration) if total_duration > 0 else None,
        duration_s=total_duration,
        stdout=tail_text(stdout, max_lines=80, max_chars=12000),
        stderr=tail_text(stderr, max_lines=80, max_chars=12000),
    )


class BCCRunner:
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
        setup_script: Path | str = DEFAULT_SETUP_SCRIPT,
    ) -> None:
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
        self.setup_script = Path(setup_script).resolve()
        self.setup_result: dict[str, object] = {
            "returncode": 0,
            "tools_dir": None,
            "stdout_tail": "",
            "stderr_tail": "",
        }
        self.tools_dir = resolve_tools_dir(tools_dir)
        self.tool_binary = Path(tool_binary).resolve() if tool_binary is not None else None
        self.session: ToolProcessSession | None = None
        self.programs: list[dict[str, object]] = []
        self.process_output: dict[str, object] = {}

    def _resolve_tool_binary(self) -> Path:
        if self.tool_binary is not None:
            if not self.tool_binary.exists():
                raise RuntimeError(f"BCC tool binary not found: {self.tool_binary}")
            if not os.access(self.tool_binary, os.X_OK):
                raise RuntimeError(f"BCC tool binary is not executable: {self.tool_binary}")
            return self.tool_binary

        self.setup_result = run_setup_script(self.setup_script)
        if int(self.setup_result.get("returncode", 0) or 0) != 0:
            stderr_tail = str(self.setup_result.get("stderr_tail") or "")
            raise RuntimeError(f"BCC setup failed: {stderr_tail or self.setup_result}")
        self.tools_dir = resolve_tools_dir(self.tools_dir, setup_result=self.setup_result)

        tool_binary = find_tool_binary(self.tools_dir, self.tool_name)
        if tool_binary is None:
            raise RuntimeError(f"BCC tool '{self.tool_name}' not found in {self.tools_dir}")
        self.tool_binary = tool_binary
        return tool_binary

    def _fail_start(self, message: str) -> NoReturn:
        stop_error = ""
        try:
            self.stop()
        except Exception as exc:
            stop_error = str(exc)
        details: list[str] = [message]
        stderr_tail = str(self.process_output.get("stderr_tail") or "").strip()
        stdout_tail = str(self.process_output.get("stdout_tail") or "").strip()
        if stderr_tail:
            details.append(f"stderr tail:\n{stderr_tail}")
        elif stdout_tail:
            details.append(f"stdout tail:\n{stdout_tail}")
        if stop_error:
            details.append(f"stop error: {stop_error}")
        raise RuntimeError("\n".join(details))

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError(f"BCC tool {self.tool_name} is already running")

        tool_binary = self._resolve_tool_binary()
        tempdir = tempfile.TemporaryDirectory(prefix=f"bcc-{tool_binary.name}-")
        stdout_path = Path(tempdir.name) / "stdout.log"
        stderr_path = Path(tempdir.name) / "stderr.log"
        stdout_handle = stdout_path.open("w", encoding="utf-8")
        stderr_handle = stderr_path.open("w", encoding="utf-8")
        process = subprocess.Popen(
            [str(tool_binary), *self.tool_args],
            cwd=ROOT_DIR,
            env=os.environ.copy(),
            stdin=subprocess.DEVNULL,
            stdout=stdout_handle,
            stderr=stderr_handle,
            text=True,
            bufsize=1,
        )
        self.session = ToolProcessSession(
            process=process,
            tempdir=tempdir,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
            stdout_handle=stdout_handle,
            stderr_handle=stderr_handle,
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
            expected = set(self.expected_program_names)
            matched = [program for program in programs if str(program.get("name") or "") in expected]
            found = {str(program.get("name") or "") for program in matched}
            missing = [name for name in self.expected_program_names if name not in found]
            if missing:
                attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
                return self._fail_start(
                    f"BCC tool {self.tool_name} did not attach expected programs {missing}; attached {attached_names}"
                )
            programs = matched

        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"BCC tool {self.tool_name} is not running")
        return _run_named_workload(self.workload_kind, seconds)

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
        for handle in (session.stdout_handle, session.stderr_handle):
            try:
                handle.flush()
            except Exception as exc:
                io_errors.append(f"failed to flush {handle.name}: {exc}")
            try:
                handle.close()
            except Exception as exc:
                io_errors.append(f"failed to close {handle.name}: {exc}")

        stdout = ""
        stderr = ""
        try:
            stdout = session.stdout_path.read_text(encoding="utf-8", errors="replace")
        except OSError as exc:
            io_errors.append(f"failed to read {session.stdout_path}: {exc}")
        try:
            stderr = session.stderr_path.read_text(encoding="utf-8", errors="replace")
        except OSError as exc:
            io_errors.append(f"failed to read {session.stderr_path}: {exc}")
        self.process_output = {
            "returncode": session.process.returncode,
            "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
            "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
        }
        session.tempdir.cleanup()

        failures: list[str] = []
        if stop_error is not None:
            failures.append(str(stop_error))
        failures.extend(io_errors)
        if failures:
            raise RuntimeError("; ".join(failures))


__all__ = [
    "BCCRunner",
    "find_tool_binary",
    "resolve_tools_dir",
    "run_setup_script",
]
