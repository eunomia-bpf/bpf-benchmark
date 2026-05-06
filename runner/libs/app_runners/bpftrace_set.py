from __future__ import annotations

import threading
import time
from dataclasses import dataclass
from typing import Mapping

from .. import tail_text, which
from ..agent import bpftool_prog_show_records, start_agent
from ..benchmark_net import BENCHMARK_IFACE
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .bpftrace import BpftraceRunner

BPFTRACE_SET_WORKLOAD = "stress_ng_os_io_network"
DEFAULT_BPFTRACE_SET_ATTACH_WAIT_SECONDS = 10


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


def _program_records_by_id() -> dict[int, dict[str, object]]:
    records: dict[int, dict[str, object]] = {}
    for record in bpftool_prog_show_records():
        prog_id = int(record.get("id", 0) or 0)
        if prog_id > 0:
            records[prog_id] = dict(record)
    return records


class BpftraceSetRunner(AppRunner):
    def __init__(
        self,
        *,
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_BPFTRACE_SET_ATTACH_WAIT_SECONDS,
    ) -> None:
        super().__init__()
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = float(attach_timeout_s)
        self._children: dict[str, BpftraceRunner] = {
            spec.name: BpftraceRunner(
                script_name=spec.name,
                workload_spec={"kind": BPFTRACE_SET_WORKLOAD},
                attach_timeout_s=int(self.attach_timeout_s),
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
        before_records = _program_records_by_id()

        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            try:
                self._spawn_child(self._children[spec.name])
            except Exception as exc:
                self._fail_start(f"bpftrace/set failed to start {spec.name}: {exc}")

        time.sleep(max(0.0, self.attach_timeout_s))

        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            self._raise_if_child_exited(spec.name, self._children[spec.name])

        after_records = _program_records_by_id()
        prog_ids = sorted(set(after_records).difference(before_records))
        if not prog_ids:
            self._fail_start(
                f"bpftrace/set added no BPF programs in {self.attach_timeout_s:g}s attach wait window"
            )
        self.programs = [after_records[prog_id] for prog_id in prog_ids]
        return prog_ids

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
        for spec in BPFTRACE_SET_SCRIPT_SPECS:
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

    def _raise_if_child_exited(self, script_name: str, child: BpftraceRunner) -> None:
        process = child.process
        if process is None:
            self._fail_start(f"bpftrace script {script_name} process handle is unavailable")
        returncode = process.poll()
        if returncode is None:
            return
        details = self._child_error_tail(child)
        self._fail_start(
            f"bpftrace script {script_name} exited with rc={returncode}" + (f": {details}" if details else "")
        )

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

    def _child_error_tail(self, child: BpftraceRunner) -> str:
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
        for spec in BPFTRACE_SET_SCRIPT_SPECS:
            output = self._child_output_snapshot(self._children[spec.name])
            if output.get("stdout_tail"):
                stdout_parts.append(f"{spec.name}:\n{output['stdout_tail']}")
            if output.get("stderr_tail"):
                stderr_parts.append(f"{spec.name}:\n{output['stderr_tail']}")
        return {
            "stdout_tail": tail_text("\n".join(stdout_parts), max_lines=80, max_chars=16000),
            "stderr_tail": tail_text("\n".join(stderr_parts), max_lines=80, max_chars=16000),
        }
