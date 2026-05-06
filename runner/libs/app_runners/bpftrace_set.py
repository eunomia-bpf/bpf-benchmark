from __future__ import annotations

import threading
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import tail_text, which
from ..agent import bpftool_prog_show_records, start_agent
from ..benchmark_net import BENCHMARK_IFACE
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .bpftrace import BpftraceRunner, DEFAULT_ATTACH_TIMEOUT_S
from .process_support import programs_after, wait_until_program_set_stable

BPFTRACE_SET_WORKLOAD = "stress_ng_os_io_network"


@dataclass(frozen=True)
class BpftraceSetScriptSpec:
    name: str


BPFTRACE_SET_SCRIPT_SPECS: tuple[BpftraceSetScriptSpec, ...] = (
    BpftraceSetScriptSpec("capable"),
    BpftraceSetScriptSpec("biosnoop"),
    BpftraceSetScriptSpec("vfsstat"),
    BpftraceSetScriptSpec("runqlat"),
    BpftraceSetScriptSpec("tcplife"),
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


def _program_ids_from_fdinfo(pid: int) -> list[int]:
    fdinfo_dir = Path("/proc") / str(int(pid)) / "fdinfo"
    try:
        paths = sorted(fdinfo_dir.iterdir(), key=lambda path: path.name)
    except FileNotFoundError:
        return []
    except PermissionError as exc:
        raise RuntimeError(f"cannot inspect bpftrace child fdinfo for pid {pid}: {exc}") from exc
    ids: set[int] = set()
    for path in paths:
        try:
            text = path.read_text(encoding="utf-8", errors="replace")
        except FileNotFoundError:
            continue
        except PermissionError as exc:
            raise RuntimeError(f"cannot read bpftrace child fdinfo {path}: {exc}") from exc
        for line in text.splitlines():
            if not line.startswith("prog_id:"):
                continue
            _, raw_value = line.split(":", 1)
            try:
                prog_id = int(raw_value.strip())
            except ValueError as exc:
                raise RuntimeError(f"invalid prog_id in bpftrace child fdinfo {path}: {line!r}") from exc
            if prog_id > 0:
                ids.add(prog_id)
    return sorted(ids)


class BpftraceSetRunner(AppRunner):
    def __init__(
        self,
        *,
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_S,
    ) -> None:
        super().__init__()
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = int(attach_timeout_s)
        self._before_ids: set[int] = set()
        self._script_startup: dict[str, dict[str, object]] = {}
        self._children: dict[str, BpftraceRunner] = {
            spec.name: BpftraceRunner(
                script_name=spec.name,
                workload_spec={"kind": BPFTRACE_SET_WORKLOAD},
                attach_timeout_s=self.attach_timeout_s,
            )
            for spec in BPFTRACE_SET_SCRIPT_SPECS
        }

    @property
    def pid(self) -> int | None:
        for child in self._children.values():
            if child.pid is not None:
                return child.pid
        return None

    def start(self) -> list[int]:
        if any(child.process is not None for child in self._children.values()):
            raise RuntimeError("bpftrace/set is already running")
        self.programs = []
        self._script_startup = {}
        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            self._record_script_status(spec.name, status="pending")
        self._before_ids = _current_program_ids()

        spawned: list[str] = []
        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            child = self._children[spec.name]
            try:
                self._spawn_child(child)
            except Exception as exc:
                self._record_script_status(spec.name, status="failed", error=str(exc))
                continue
            spawned.append(spec.name)
            self._record_script_status(spec.name, status="starting")

        if not spawned:
            raise RuntimeError(f"bpftrace/set failed to start any scripts: {self._failure_summary()}")

        try:
            programs = wait_until_program_set_stable(
                before_ids=self._before_ids,
                timeout_s=self.attach_timeout_s,
                discover_programs=lambda: programs_after(self._before_ids),
                process_name="bpftrace/set",
            )
        except Exception as exc:
            self._mark_exited_children()
            self._fail_start(f"bpftrace/set did not attach a stable BPF program set: {exc}")

        live_programs = _dedupe_programs(programs)
        if not live_programs:
            self._fail_start("bpftrace/set did not expose any live BPF programs")

        live_program_ids = {
            int(program.get("id", 0) or 0)
            for program in live_programs
            if int(program.get("id", 0) or 0) > 0
        }
        live_scripts = 0
        for script_name in spawned:
            child = self._children[script_name]
            process = child.process
            if process is None:
                self._record_script_status(script_name, status="failed", error="process handle is unavailable")
                continue
            if process.poll() is not None:
                self._record_script_status(
                    script_name,
                    status="failed",
                    error=self._process_exit_message(script_name, child),
                )
                self._stop_failed_child(script_name, child)
                continue
            prog_ids = [prog_id for prog_id in _program_ids_from_fdinfo(process.pid) if prog_id in live_program_ids]
            self._record_script_status(script_name, status="attached", prog_ids=prog_ids)
            live_scripts += 1

        if live_scripts == 0:
            self._fail_start(f"bpftrace/set failed to keep any scripts running: {self._failure_summary()}")

        self.programs = live_programs
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if not any(child.process is not None for child in self._children.values()):
            raise RuntimeError("bpftrace/set is not running")
        return run_named_workload(
            self._workload_kind(),
            max(1, int(round(seconds))),
            network_device=BENCHMARK_IFACE,
        )

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        requested = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if requested != BPFTRACE_SET_WORKLOAD:
            raise RuntimeError(f"bpftrace/set only supports workload {BPFTRACE_SET_WORKLOAD!r}; got {requested!r}")
        return self.run_workload(seconds)

    def stop(self) -> None:
        failures: list[str] = []
        per_tool_output: dict[str, object] = {}
        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            child = self._children[spec.name]
            try:
                child.stop()
            except Exception as exc:
                failures.append(f"{spec.name}: {exc}")
            per_tool_output[spec.name] = dict(child.process_output)
        self.process_output = {
            "tools": per_tool_output,
            "tool_startup": self._script_startup_records(),
        }
        if failures:
            raise RuntimeError("; ".join(failures))

    def _workload_kind(self) -> str:
        kind = str(self.workload_spec.get("kind") or self.workload_spec.get("name") or "").strip()
        if kind != BPFTRACE_SET_WORKLOAD:
            raise RuntimeError(f"bpftrace/set only supports workload {BPFTRACE_SET_WORKLOAD!r}; got {kind!r}")
        return kind

    def _spawn_child(self, child: BpftraceRunner) -> None:
        if child.process is not None:
            raise RuntimeError(f"bpftrace script {child.script_name} is already running")
        bpftrace_binary = which("bpftrace")
        if bpftrace_binary is None:
            raise RuntimeError("bpftrace is required but not present in PATH")
        script_path = child._resolve_script_path()
        child.command_used = [bpftrace_binary, "-q", str(script_path)]
        child.process = start_agent(bpftrace_binary, ["-q", str(script_path)])
        if child.process.stdout is None or child.process.stderr is None:
            child.process.kill()
            raise RuntimeError(f"bpftrace script {child.script_name} did not expose stdout/stderr pipes")
        child.stdout_thread = threading.Thread(
            target=child.collector.consume_stdout,
            args=(child.process.stdout,),
            daemon=True,
        )
        child.stderr_thread = threading.Thread(
            target=child.collector.consume_stderr,
            args=(child.process.stderr,),
            daemon=True,
        )
        child.stdout_thread.start()
        child.stderr_thread.start()

    def _record_script_status(
        self,
        script_name: str,
        *,
        status: str,
        error: str = "",
        prog_ids: Sequence[int] = (),
    ) -> None:
        child = self._children[script_name]
        record: dict[str, object] = {
            "tool": script_name,
            "status": status,
            "pid": child.pid,
            "command": list(child.command_used),
            "prog_ids": [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0],
        }
        if error:
            record["error"] = tail_text(error, max_lines=20, max_chars=4000)
            output = self._child_output_snapshot(child)
            if output.get("stderr_tail"):
                record["stderr_tail"] = output["stderr_tail"]
            if output.get("stdout_tail"):
                record["stdout_tail"] = output["stdout_tail"]
        self._script_startup[script_name] = record
        self._sync_result_details()

    def _sync_result_details(self) -> None:
        self.artifacts["result_details"] = {
            "bpftrace_set": {
                "tool_startup": self._script_startup_records(),
            },
        }

    def _script_startup_records(self) -> list[dict[str, object]]:
        return [
            dict(self._script_startup[spec.name])
            for spec in BPFTRACE_SET_SCRIPT_SPECS
            if spec.name in self._script_startup
        ]

    def _child_output_snapshot(self, child: BpftraceRunner) -> dict[str, str]:
        if child.process is None:
            return {
                "stdout_tail": str(child.process_output.get("stdout_tail") or ""),
                "stderr_tail": str(child.process_output.get("stderr_tail") or ""),
            }
        snapshot = child.collector.snapshot()
        return {
            "stdout_tail": tail_text(
                "\n".join(str(line) for line in (snapshot.get("stdout_tail") or [])),
                max_lines=40,
                max_chars=8000,
            ),
            "stderr_tail": tail_text(
                "\n".join(str(line) for line in (snapshot.get("stderr_tail") or [])),
                max_lines=40,
                max_chars=8000,
            ),
        }

    def _process_exit_message(self, script_name: str, child: BpftraceRunner) -> str:
        process: Any | None = child.process
        returncode = None if process is None else process.poll()
        output = self._child_output_snapshot(child)
        combined = "\n".join(
            text
            for text in (output.get("stderr_tail", ""), output.get("stdout_tail", ""))
            if text
        )
        details = tail_text(combined, max_lines=40, max_chars=8000)
        message = f"bpftrace script {script_name} exited before bpftrace/set startup completed"
        if returncode is not None:
            message += f" (rc={returncode})"
        return message + (f": {details}" if details else "")

    def _stop_failed_child(self, script_name: str, child: BpftraceRunner) -> None:
        try:
            child.stop()
        except Exception as exc:
            self._record_script_status(
                script_name,
                status="failed",
                error=f"{self._failure_error(script_name)}; stop failed: {exc}",
            )

    def _mark_exited_children(self) -> None:
        for script_name, child in self._children.items():
            if child.process is None:
                continue
            if child.process.poll() is None:
                continue
            self._record_script_status(
                script_name,
                status="failed",
                error=self._process_exit_message(script_name, child),
            )
            self._stop_failed_child(script_name, child)

    def _failure_error(self, script_name: str) -> str:
        record = self._script_startup.get(script_name) or {}
        return str(record.get("error") or "script failed")

    def _failure_summary(self) -> str:
        failures = [
            f"{record.get('tool')}: {record.get('error')}"
            for record in self._script_startup_records()
            if str(record.get("status") or "") == "failed"
        ]
        return "; ".join(failures) if failures else "no per-script failure details recorded"
