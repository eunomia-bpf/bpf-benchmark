from __future__ import annotations

import threading
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, tail_text, which
from ..agent import bpftool_prog_show_records, start_agent, stop_agent
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .process_support import ProcessOutputCollector, programs_after, wait_until_program_set_stable

DEFAULT_SCRIPT_DIR = ROOT_DIR / "e2e" / "cases" / "bpftrace" / "scripts"


@dataclass(frozen=True)
class ScriptSpec:
    name: str
    script_path: Path
    workload_spec: Mapping[str, object]
    program_name_hints: tuple[str, ...]


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="tcplife",
        script_path=DEFAULT_SCRIPT_DIR / "tcplife.bt",
        workload_spec={"kind": "tcp_connect"},
        program_name_hints=("tcp_set_state",),
    ),
    ScriptSpec(
        name="biosnoop",
        script_path=DEFAULT_SCRIPT_DIR / "biosnoop.bt",
        workload_spec={"kind": "block_io"},
        program_name_hints=("block_io_start", "block_io_done"),
    ),
    ScriptSpec(
        name="runqlat",
        script_path=DEFAULT_SCRIPT_DIR / "runqlat.bt",
        workload_spec={"kind": "scheduler"},
        program_name_hints=("sched_switch", "sched_wakeup"),
    ),
    ScriptSpec(
        name="tcpretrans",
        script_path=DEFAULT_SCRIPT_DIR / "tcpretrans.bt",
        workload_spec={"kind": "tcp_retransmit"},
        program_name_hints=("tcp_retransmit",),
    ),
    ScriptSpec(
        name="capable",
        script_path=DEFAULT_SCRIPT_DIR / "capable.bt",
        workload_spec={"kind": "exec_storm"},
        program_name_hints=("cap_capable",),
    ),
    ScriptSpec(
        name="vfsstat",
        script_path=DEFAULT_SCRIPT_DIR / "vfsstat.bt",
        workload_spec={"kind": "vfs_create_write_fsync"},
        program_name_hints=("vfs_", "1"),
    ),
)

SCRIPT_BY_NAME: dict[str, ScriptSpec] = {spec.name: spec for spec in SCRIPTS}


DEFAULT_ATTACH_TIMEOUT_S = 60


class BpftraceRunner(AppRunner):
    def __init__(
        self,
        *,
        script_name: str,
        workload_spec: Mapping[str, object],
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_S,
    ) -> None:
        super().__init__()
        self.script_name = str(script_name).strip()
        if not self.script_name:
            raise RuntimeError("BpftraceRunner requires script_name")
        self.workload_spec = dict(workload_spec)
        self.attach_timeout_s = int(attach_timeout_s)
        self.process: Any | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def _resolve_script_spec(self) -> ScriptSpec:
        script_spec = SCRIPT_BY_NAME.get(self.script_name)
        if script_spec is None:
            raise RuntimeError(f"unknown bpftrace script: {self.script_name}")
        return script_spec

    @staticmethod
    def _program_name_matches(name: str, hints: Sequence[str]) -> bool:
        normalized_name = str(name or "").strip().lower()
        if not normalized_name:
            return False
        for raw_hint in hints:
            hint = str(raw_hint or "").strip().lower()
            if not hint:
                continue
            if len(hint) <= 2:
                if normalized_name == hint:
                    return True
                continue
            if normalized_name == hint or normalized_name.startswith(hint) or hint in normalized_name:
                return True
        return False

    def _discover_script_programs(self, before_ids: Sequence[int]) -> list[dict[str, object]]:
        script_spec = self._resolve_script_spec()
        matched = [
            dict(program)
            for program in programs_after(before_ids)
            if self._program_name_matches(str(program.get("name") or ""), script_spec.program_name_hints)
        ]
        matched.sort(key=lambda item: int(item.get("id", 0) or 0))
        return matched

    def start(self) -> list[int]:
        if self.process is not None:
            raise RuntimeError("BpftraceRunner is already running")

        bpftrace_binary = which("bpftrace")
        if bpftrace_binary is None:
            raise RuntimeError("bpftrace is required but not present in PATH")
        script_spec = self._resolve_script_spec()
        script_path = script_spec.script_path.resolve()
        before_ids = {
            int(record.get("id", 0) or 0)
            for record in bpftool_prog_show_records()
            if int(record.get("id", 0) or 0) > 0
        }
        self.command_used = [bpftrace_binary, "-q", str(script_path)]
        self.process = start_agent(bpftrace_binary, ["-q", str(script_path)])
        if self.process.stdout is None or self.process.stderr is None:
            self.process.kill()
            raise RuntimeError("bpftrace did not expose stdout/stderr pipes")
        self.stdout_thread = threading.Thread(
            target=self.collector.consume_stdout,
            args=(self.process.stdout,),
            daemon=True,
        )
        self.stderr_thread = threading.Thread(
            target=self.collector.consume_stderr,
            args=(self.process.stderr,),
            daemon=True,
        )
        self.stdout_thread.start()
        self.stderr_thread.start()
        programs = wait_until_program_set_stable(
            before_ids=before_ids,
            timeout_s=self.attach_timeout_s,
            discover_programs=lambda: self._discover_script_programs(before_ids),
            process=self.process,
            collector_snapshot=self.collector.snapshot,
            process_name=f"bpftrace ({script_spec.name})",
        )
        if not programs:
            self._fail_start(f"bpftrace did not attach any BPF programs for {script_path.name}")
        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.process is None:
            raise RuntimeError("BpftraceRunner is not running")
        kind = str(self.workload_spec.get("kind") or self.workload_spec.get("name") or "").strip()
        if not kind:
            raise RuntimeError("bpftrace workload kind is not resolved")
        return run_named_workload(
            kind,
            max(1, int(round(seconds))),
            network_as_tcp_connect=True,
        )

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        if self.process is None:
            raise RuntimeError("BpftraceRunner is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError("bpftrace workload spec is missing a workload kind")
        return run_named_workload(
            requested_kind,
            max(1, int(round(seconds))),
            network_as_tcp_connect=True,
        )

    def stop(self) -> None:
        if self.process is None:
            return
        process = self.process
        self.process = None
        stop_error: Exception | None = None
        try:
            stop_agent(process, timeout=8)
        except Exception as exc:
            stop_error = exc
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None
        snapshot = self.collector.snapshot()
        self.process_output = {
            "returncode": process.returncode,
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
        if stop_error is not None:
            raise RuntimeError(str(stop_error)) from stop_error
