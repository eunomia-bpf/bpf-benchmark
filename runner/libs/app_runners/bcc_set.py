from __future__ import annotations

import os
import subprocess
import threading
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from .. import ROOT_DIR, tail_text
from ..agent import bpftool_prog_show_records
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .bcc import (
    BCCRunner,
    DEFAULT_ATTACH_TIMEOUT_SECONDS,
    ToolProcessSession,
    _TailCapture,
    _drain_stream,
    _prepare_bcc_kernel_source,
    _prepare_bcc_python_compat,
)

BCC_SET_WORKLOAD = "stress_ng_os_io_network"


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


def _current_program_ids() -> set[int]:
    return {
        int(record.get("id", 0) or 0)
        for record in bpftool_prog_show_records()
        if int(record.get("id", 0) or 0) > 0
    }


def _dedupe_programs(programs: Sequence[Mapping[str, object]]) -> list[dict[str, object]]:
    deduped: dict[int, dict[str, object]] = {}
    for program in programs:
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        deduped[prog_id] = dict(program)
    return [deduped[prog_id] for prog_id in sorted(deduped)]


def _program_records_for_ids(program_ids: Sequence[int]) -> list[dict[str, object]]:
    requested_ids = {int(prog_id) for prog_id in program_ids if int(prog_id) > 0}
    records_by_id: dict[int, dict[str, object]] = {}
    for record in bpftool_prog_show_records():
        prog_id = int(record.get("id", 0) or 0)
        if prog_id in requested_ids:
            records_by_id[prog_id] = dict(record)
    missing = sorted(requested_ids.difference(records_by_id))
    if missing:
        raise RuntimeError(f"bpftool did not report BCC child program IDs from fdinfo: {missing}")
    return [records_by_id[prog_id] for prog_id in sorted(records_by_id)]


def _program_ids_from_fdinfo(pid: int) -> list[int]:
    fdinfo_dir = Path("/proc") / str(int(pid)) / "fdinfo"
    try:
        paths = sorted(fdinfo_dir.iterdir(), key=lambda path: path.name)
    except FileNotFoundError:
        return []
    except PermissionError as exc:
        raise RuntimeError(f"cannot inspect BCC child fdinfo for pid {pid}: {exc}") from exc
    ids: set[int] = set()
    for path in paths:
        try:
            text = path.read_text(encoding="utf-8", errors="replace")
        except FileNotFoundError:
            continue
        except PermissionError as exc:
            raise RuntimeError(f"cannot read BCC child fdinfo {path}: {exc}") from exc
        for line in text.splitlines():
            if not line.startswith("prog_id:"):
                continue
            _, raw_value = line.split(":", 1)
            try:
                prog_id = int(raw_value.strip())
            except ValueError as exc:
                raise RuntimeError(f"invalid prog_id in BCC child fdinfo {path}: {line!r}") from exc
            if prog_id > 0:
                ids.add(prog_id)
    return sorted(ids)


class BccSetRunner(AppRunner):
    def __init__(
        self,
        *,
        tool_binaries: Mapping[str, Path | str],
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_SECONDS,
    ) -> None:
        super().__init__()
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = int(attach_timeout_s)
        self._before_ids: set[int] = set()
        self._tool_startup: dict[str, dict[str, object]] = {}
        self._children: dict[str, BCCRunner] = {}
        for spec in BCC_SET_TOOL_SPECS:
            binary = tool_binaries.get(spec.name)
            if binary is None:
                raise RuntimeError(f"bcc/set missing resolved tool binary for {spec.name}")
            self._children[spec.name] = BCCRunner(
                tool_binary=Path(binary),
                tool_args=spec.tool_args,
                workload_spec={"kind": BCC_SET_WORKLOAD},
                attach_timeout_s=self.attach_timeout_s,
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
        self._tool_startup = {}
        for spec in BCC_SET_TOOL_SPECS:
            self._record_tool_status(spec.name, status="pending")
        self._before_ids = _current_program_ids()

        spawned: list[str] = []
        for spec in BCC_SET_TOOL_SPECS:
            child = self._children[spec.name]
            try:
                self._spawn_child(child)
            except Exception as exc:
                self._record_tool_status(spec.name, status="failed", error=str(exc))
                continue
            spawned.append(spec.name)
            self._record_tool_status(spec.name, status="starting")

        if not spawned:
            raise RuntimeError(f"bcc/set failed to start any BCC tools: {self._failure_summary()}")
        if len(spawned) != len(BCC_SET_TOOL_SPECS):
            self._fail_start(f"bcc/set failed to start all BCC tools: {self._failure_summary()}")

        try:
            per_tool_prog_ids = self._wait_for_all_tool_program_ids(spawned)
        except Exception as exc:
            self._mark_exited_children()
            self._fail_start(f"bcc/set did not attach all BCC tools: {exc}")

        all_prog_ids = sorted({prog_id for prog_ids in per_tool_prog_ids.values() for prog_id in prog_ids})
        live_programs = _dedupe_programs(_program_records_for_ids(all_prog_ids))
        if not live_programs:
            self._fail_start("bcc/set did not expose any live BPF programs")

        self.programs = live_programs
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

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
        per_tool_output: dict[str, object] = {}
        for spec in BCC_SET_TOOL_SPECS:
            child = self._children[spec.name]
            try:
                child.stop()
            except Exception as exc:
                failures.append(f"{spec.name}: {exc}")
            per_tool_output[spec.name] = dict(child.process_output)
        self.process_output = {
            "tools": per_tool_output,
            "tool_startup": self._tool_startup_records(),
        }
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

    def _wait_for_all_tool_program_ids(
        self,
        tool_names: Sequence[str],
        *,
        poll_interval_s: float = 0.2,
    ) -> dict[str, list[int]]:
        deadline = time.monotonic() + max(0.0, float(self.attach_timeout_s))
        poll_interval = max(0.05, float(poll_interval_s))
        pending = set(tool_names)
        attached: dict[str, list[int]] = {}

        while pending:
            now = time.monotonic()
            for tool_name in list(pending):
                child = self._children[tool_name]
                process = child.session.process if child.session is not None else None
                if process is None:
                    self._record_tool_status(tool_name, status="failed", error="process handle is unavailable")
                    pending.remove(tool_name)
                    continue
                if process.poll() is not None:
                    self._record_tool_status(
                        tool_name,
                        status="failed",
                        error=self._process_exit_message(tool_name, child),
                    )
                    self._stop_failed_child(tool_name, child)
                    pending.remove(tool_name)
                    continue

                prog_ids = tuple(
                    prog_id
                    for prog_id in _program_ids_from_fdinfo(process.pid)
                    if prog_id not in self._before_ids
                )
                if prog_ids:
                    attached[tool_name] = list(prog_ids)
                    self._record_tool_status(tool_name, status="attached", prog_ids=prog_ids)
                    pending.remove(tool_name)

            failed = [
                tool_name
                for tool_name in tool_names
                if str((self._tool_startup.get(tool_name) or {}).get("status") or "") == "failed"
            ]
            if failed:
                raise RuntimeError(f"BCC tools failed before attachment: {', '.join(sorted(failed))}")
            if not pending:
                return attached
            if now >= deadline:
                for tool_name in sorted(pending):
                    self._record_tool_status(
                        tool_name,
                        status="timeout",
                        error=(
                            f"BCC tool {tool_name} did not expose any BPF program IDs "
                            f"within {self.attach_timeout_s}s"
                        ),
                    )
                raise RuntimeError(f"BCC tools timed out before attachment: {', '.join(sorted(pending))}")
            time.sleep(min(poll_interval, max(0.0, deadline - now)))

        return attached

    def _record_tool_status(
        self,
        tool_name: str,
        *,
        status: str,
        error: str = "",
        prog_ids: Sequence[int] = (),
    ) -> None:
        child = self._children[tool_name]
        record: dict[str, object] = {
            "tool": tool_name,
            "status": status,
            "pid": child.pid,
            "command": list(child.command_used or [str(child.tool_binary), *child.tool_args]),
            "prog_ids": [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0],
        }
        if error:
            record["error"] = tail_text(error, max_lines=20, max_chars=4000)
            output = self._child_output_snapshot(child)
            if output.get("stderr_tail"):
                record["stderr_tail"] = output["stderr_tail"]
            if output.get("stdout_tail"):
                record["stdout_tail"] = output["stdout_tail"]
        self._tool_startup[tool_name] = record
        self._sync_result_details()

    def _sync_result_details(self) -> None:
        self.artifacts["result_details"] = {
            "bcc_set": {
                "tool_startup": self._tool_startup_records(),
            },
        }

    def _tool_startup_records(self) -> list[dict[str, object]]:
        return [
            dict(self._tool_startup[spec.name])
            for spec in BCC_SET_TOOL_SPECS
            if spec.name in self._tool_startup
        ]

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

    def _process_exit_message(self, tool_name: str, child: BCCRunner) -> str:
        session = child.session
        returncode = None if session is None else session.process.poll()
        output = self._child_output_snapshot(child)
        combined = "\n".join(
            text
            for text in (output.get("stderr_tail", ""), output.get("stdout_tail", ""))
            if text
        )
        details = tail_text(combined, max_lines=40, max_chars=8000)
        message = f"BCC tool {tool_name} exited before bcc/set startup completed"
        if returncode is not None:
            message += f" (rc={returncode})"
        return message + (f": {details}" if details else "")

    def _stop_failed_child(self, tool_name: str, child: BCCRunner) -> None:
        try:
            child.stop()
        except Exception as exc:
            self._record_tool_status(tool_name, status="failed", error=f"{self._failure_error(tool_name)}; stop failed: {exc}")

    def _mark_exited_children(self) -> None:
        for tool_name, child in self._children.items():
            if child.session is None:
                continue
            if child.session.process.poll() is None:
                continue
            self._record_tool_status(tool_name, status="failed", error=self._process_exit_message(tool_name, child))
            self._stop_failed_child(tool_name, child)

    def _failure_error(self, tool_name: str) -> str:
        record = self._tool_startup.get(tool_name) or {}
        return str(record.get("error") or "tool failed")

    def _failure_summary(self) -> str:
        failures = [
            f"{record.get('tool')}: {record.get('status')}: {record.get('error')}"
            for record in self._tool_startup_records()
            if str(record.get("status") or "") in {"failed", "timeout"}
        ]
        return "; ".join(failures) if failures else "no per-tool failure details recorded"
