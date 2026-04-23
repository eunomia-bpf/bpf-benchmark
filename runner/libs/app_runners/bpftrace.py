from __future__ import annotations

import threading
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping

from .. import ROOT_DIR, tail_text, which
from ..agent import bpftool_prog_show_records, start_agent, stop_agent
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .process_support import ProcessOutputCollector, wait_until_program_set_stable

DEFAULT_SCRIPT_DIR = ROOT_DIR / "e2e" / "cases" / "bpftrace" / "scripts"


@dataclass(frozen=True)
class ScriptSpec:
    name: str
    script_path: Path
    workload_spec: Mapping[str, object]


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="tcplife",
        script_path=DEFAULT_SCRIPT_DIR / "tcplife.bt",
        workload_spec={"kind": "tcp_connect"},
    ),
    ScriptSpec(
        name="biosnoop",
        script_path=DEFAULT_SCRIPT_DIR / "biosnoop.bt",
        workload_spec={"kind": "block_io"},
    ),
    ScriptSpec(
        name="runqlat",
        script_path=DEFAULT_SCRIPT_DIR / "runqlat.bt",
        workload_spec={"kind": "scheduler"},
    ),
    ScriptSpec(
        name="tcpretrans",
        script_path=DEFAULT_SCRIPT_DIR / "tcpretrans.bt",
        workload_spec={"kind": "tcp_retransmit"},
    ),
    ScriptSpec(
        name="capable",
        script_path=DEFAULT_SCRIPT_DIR / "capable.bt",
        workload_spec={"kind": "exec_storm"},
    ),
    ScriptSpec(
        name="vfsstat",
        script_path=DEFAULT_SCRIPT_DIR / "vfsstat.bt",
        workload_spec={"kind": "vfs_create_write_fsync"},
    ),
)


def finalize_process_output(process: Any, collector: ProcessOutputCollector | None = None) -> dict[str, object]:
    if collector is not None:
        snapshot = collector.snapshot()
        stdout_tail = "\n".join(str(line) for line in (snapshot.get("stdout_tail") or []))
        stderr_tail = "\n".join(str(line) for line in (snapshot.get("stderr_tail") or []))
        return {
            "returncode": process.returncode,
            "stdout_tail": tail_text(stdout_tail, max_lines=40, max_chars=8000),
            "stderr_tail": tail_text(stderr_tail, max_lines=40, max_chars=8000),
        }

    stdout = ""
    stderr = ""
    try:
        stdout, stderr = process.communicate(timeout=1)
    except Exception:
        if process.stdout is not None:
            try:
                stdout = process.stdout.read()
            except Exception:
                stdout = ""
        if process.stderr is not None:
            try:
                stderr = process.stderr.read()
            except Exception:
                stderr = ""
    return {
        "returncode": process.returncode,
        "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
    }


DEFAULT_ATTACH_TIMEOUT_S = 60


class BpftraceRunner(AppRunner):
    def __init__(
        self,
        *,
        script_path: Path | str | None = None,
        script_name: str | None = None,
        workload_spec: Mapping[str, object] | None = None,
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_S,
    ) -> None:
        super().__init__()
        self.script_path = None if script_path is None else Path(script_path).resolve()
        self.script_name = str(script_name or "").strip()
        self.workload_spec = dict(workload_spec or {})
        self.attach_timeout_s = int(attach_timeout_s)
        self.process: Any | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def _resolve_script(self) -> tuple[Path, dict[str, object]]:
        specs = {spec.name: spec for spec in SCRIPTS}
        if self.script_name:
            spec = specs.get(self.script_name)
            if spec is None:
                raise RuntimeError(f"unknown bpftrace script: {self.script_name}")
            return spec.script_path.resolve(), dict(spec.workload_spec)
        if self.script_path is not None:
            if not self.script_path.exists():
                raise RuntimeError(f"bpftrace script not found: {self.script_path}")
            stem = self.script_path.name.removesuffix(".bt")
            spec = specs.get(stem)
            return self.script_path, dict(self.workload_spec or (spec.workload_spec if spec else {}))
        raise RuntimeError("BpftraceRunner requires script_name or script_path")


    def start(self) -> list[int]:
        if self.process is not None:
            raise RuntimeError("BpftraceRunner is already running")

        bpftrace_binary = which("bpftrace")
        if bpftrace_binary is None:
            raise RuntimeError("bpftrace is required but not present in PATH")
        script_path, workload_spec = self._resolve_script()
        if not self.workload_spec:
            self.workload_spec = dict(workload_spec)
        before_ids = {
            int(record.get("id", 0) or 0)
            for record in bpftool_prog_show_records()
            if int(record.get("id", 0) or 0) > 0
        }
        self.process = start_agent(bpftrace_binary, ["-q", str(script_path)])
        self.command_used = [bpftrace_binary, "-q", str(script_path)]
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
        programs = wait_until_program_set_stable(before_ids=before_ids, timeout_s=self.attach_timeout_s)
        if not programs:
            self._fail_start(f"bpftrace did not attach any BPF programs for {script_path.name}")
        self.script_path = script_path
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
        self.process_output = finalize_process_output(process, self.collector)
        if stop_error is not None:
            raise RuntimeError(str(stop_error)) from stop_error


__all__ = ["BpftraceRunner", "SCRIPTS", "ScriptSpec", "finalize_process_output"]
