from __future__ import annotations

import os
import subprocess
import threading
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping

from .. import ROOT_DIR, tail_text
from ..agent import bpftool_prog_show_records
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .bcc import (
    BCCRunner,
    ToolProcessSession,
    _TailCapture,
    _drain_stream,
    _prepare_bcc_kernel_source,
    _prepare_bcc_python_compat,
)

BCC_SET_WORKLOAD = "stress_ng_os_io_network"
DEFAULT_BCC_SET_ATTACH_WAIT_SECONDS = 10


@dataclass(frozen=True)
class BccSetToolSpec:
    name: str
    tool_args: tuple[str, ...] = ()


BCC_SET_TOOL_SPECS: tuple[BccSetToolSpec, ...] = (
    BccSetToolSpec("capable"),
    BccSetToolSpec("biosnoop"),
    BccSetToolSpec("vfsstat"),
    BccSetToolSpec("opensnoop"),
    BccSetToolSpec("syscount", ("-L", "-i", "1")),
    BccSetToolSpec("tcpconnect"),
    BccSetToolSpec("tcplife"),
    BccSetToolSpec("runqlat"),
)


def _program_records_by_id() -> dict[int, dict[str, object]]:
    records: dict[int, dict[str, object]] = {}
    for record in bpftool_prog_show_records():
        prog_id = int(record.get("id", 0) or 0)
        if prog_id > 0:
            records[prog_id] = dict(record)
    return records


class BccSetRunner(AppRunner):
    def __init__(
        self,
        *,
        tool_binaries: Mapping[str, Path | str],
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_BCC_SET_ATTACH_WAIT_SECONDS,
    ) -> None:
        super().__init__()
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = float(attach_timeout_s)
        self._children: dict[str, BCCRunner] = {}
        for spec in BCC_SET_TOOL_SPECS:
            binary = tool_binaries.get(spec.name)
            if binary is None:
                raise RuntimeError(f"bcc/set missing resolved tool binary for {spec.name}")
            self._children[spec.name] = BCCRunner(
                tool_binary=Path(binary),
                tool_args=spec.tool_args,
                workload_spec={"kind": BCC_SET_WORKLOAD},
                attach_timeout_s=int(self.attach_timeout_s),
            )

    @property
    def pid(self) -> int | None:
        for child in self._children.values():
            if child.pid is not None:
                return child.pid
        return None

    def start(self) -> list[int]:
        if any(child.session is not None for child in self._children.values()):
            raise RuntimeError("bcc/set is already running")
        self.programs = []
        before_records = _program_records_by_id()

        for spec in BCC_SET_TOOL_SPECS:
            try:
                self._spawn_child(self._children[spec.name])
            except Exception as exc:
                self._fail_start(f"bcc/set failed to start {spec.name}: {exc}")

        time.sleep(max(0.0, self.attach_timeout_s))

        for spec in BCC_SET_TOOL_SPECS:
            self._raise_if_child_exited(spec.name, self._children[spec.name])

        after_records = _program_records_by_id()
        prog_ids = sorted(set(after_records).difference(before_records))
        if not prog_ids:
            self._fail_start(
                f"bcc/set added no BPF programs in {self.attach_timeout_s:g}s attach wait window"
            )
        self.programs = [after_records[prog_id] for prog_id in prog_ids]
        return prog_ids

    def run_workload(self, seconds: float) -> WorkloadResult:
        if not any(child.session is not None for child in self._children.values()):
            raise RuntimeError("bcc/set is not running")
        return run_named_workload(self._workload_kind(), seconds)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        requested = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if requested != BCC_SET_WORKLOAD:
            raise RuntimeError(f"bcc/set only supports workload {BCC_SET_WORKLOAD!r}; got {requested!r}")
        return self.run_workload(seconds)

    def stop(self) -> None:
        failures: list[str] = []
        for spec in BCC_SET_TOOL_SPECS:
            child = self._children[spec.name]
            try:
                child.stop()
            except Exception as exc:
                failures.append(f"{spec.name}: {exc}")
        self.process_output = self._combined_child_output()
        if failures:
            raise RuntimeError("; ".join(failures))

    def _workload_kind(self) -> str:
        kind = str(self.workload_spec.get("kind") or self.workload_spec.get("name") or "").strip()
        if kind != BCC_SET_WORKLOAD:
            raise RuntimeError(f"bcc/set only supports workload {BCC_SET_WORKLOAD!r}; got {kind!r}")
        return kind

    def _spawn_child(self, child: BCCRunner) -> None:
        if child.session is not None:
            raise RuntimeError(f"BCC tool {child.tool_name} is already running")
        tool_binary = child._resolve_tool_binary()
        tool_env = os.environ.copy()
        kernel_source = _prepare_bcc_kernel_source(tool_env)
        if kernel_source:
            child.artifacts["bcc_kernel_source"] = kernel_source
        child._compat_dir = _prepare_bcc_python_compat(tool_env)
        child.artifacts["bcc_python_compat_dir"] = str(child._compat_dir)
        command = [str(tool_binary), *child.tool_args]
        child.command_used = list(command)
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            env=tool_env,
            stdin=subprocess.DEVNULL,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            encoding="utf-8",
            errors="replace",
            bufsize=1,
        )
        if process.stdout is None or process.stderr is None:
            process.kill()
            process.wait(timeout=50)
            raise RuntimeError(f"BCC tool {child.tool_name} did not expose stdout/stderr pipes")
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
        child.session = ToolProcessSession(
            process=process,
            stdout_capture=stdout_capture,
            stderr_capture=stderr_capture,
            stdout_thread=stdout_thread,
            stderr_thread=stderr_thread,
        )

    def _raise_if_child_exited(self, tool_name: str, child: BCCRunner) -> None:
        process = None if child.session is None else child.session.process
        if process is None:
            self._fail_start(f"BCC tool {tool_name} process handle is unavailable")
        returncode = process.poll()
        if returncode is None:
            return
        details = self._child_error_tail(child)
        self._fail_start(
            f"BCC tool {tool_name} exited with rc={returncode}" + (f": {details}" if details else "")
        )

    def _child_output_snapshot(self, child: BCCRunner) -> dict[str, str]:
        if child.session is None:
            return {
                "stdout_tail": str(child.process_output.get("stdout_tail") or ""),
                "stderr_tail": str(child.process_output.get("stderr_tail") or ""),
            }
        return {
            "stdout_tail": child.session.stdout_capture.render(),
            "stderr_tail": child.session.stderr_capture.render(),
        }

    def _child_error_tail(self, child: BCCRunner) -> str:
        output = self._child_output_snapshot(child)
        combined = "\n".join(
            text
            for text in (output.get("stderr_tail", ""), output.get("stdout_tail", ""))
            if text
        )
        return tail_text(combined, max_lines=40, max_chars=8000)

    def _combined_child_output(self) -> dict[str, str]:
        stdout_parts: list[str] = []
        stderr_parts: list[str] = []
        for spec in BCC_SET_TOOL_SPECS:
            output = self._child_output_snapshot(self._children[spec.name])
            if output.get("stdout_tail"):
                stdout_parts.append(f"{spec.name}:\n{output['stdout_tail']}")
            if output.get("stderr_tail"):
                stderr_parts.append(f"{spec.name}:\n{output['stderr_tail']}")
        return {
            "stdout_tail": tail_text("\n".join(stdout_parts), max_lines=80, max_chars=16000),
            "stderr_tail": tail_text("\n".join(stderr_parts), max_lines=80, max_chars=16000),
        }
