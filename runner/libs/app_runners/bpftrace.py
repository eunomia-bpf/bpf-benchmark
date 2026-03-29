from __future__ import annotations

from pathlib import Path
from typing import Any, NoReturn, Sequence

from .. import which
from ..agent import start_agent, stop_agent
from ..workload import WorkloadResult
from .bpftrace_support import SCRIPTS, ScriptSpec, finalize_process_output, run_named_workload, wait_for_attached_programs


DEFAULT_ATTACH_TIMEOUT_S = 20


class BpftraceRunner:
    def __init__(
        self,
        *,
        object_path: Path | str | None = None,
        script_path: Path | str | None = None,
        script_name: str | None = None,
        workload_kind: str | None = None,
        expected_programs: int | None = None,
        expected_program_names: Sequence[str] = (),
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_S,
    ) -> None:
        self.object_path = None if object_path is None else Path(object_path).resolve()
        self.script_path = None if script_path is None else Path(script_path).resolve()
        self.script_name = str(script_name or "").strip()
        self.workload_kind = workload_kind
        self.expected_programs = int(expected_programs or 0)
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.attach_timeout_s = int(attach_timeout_s)
        self.process: Any | None = None
        self.programs: list[dict[str, object]] = []
        self.process_output: dict[str, object] = {}

    def _fail_start(self, message: str) -> NoReturn:
        try:
            self.stop()
        except Exception as exc:
            raise RuntimeError(f"{message}; stop failed: {exc}") from exc
        stderr_tail = str(self.process_output.get("stderr_tail") or "").strip()
        stdout_tail = str(self.process_output.get("stdout_tail") or "").strip()
        details = [message]
        if stderr_tail:
            details.append(f"stderr tail:\n{stderr_tail}")
        elif stdout_tail:
            details.append(f"stdout tail:\n{stdout_tail}")
        raise RuntimeError("\n".join(details))

    @property
    def pid(self) -> int | None:
        return None if self.process is None else int(self.process.pid or 0)

    def _resolve_script(self) -> tuple[Path, str, int]:
        specs = {spec.name: spec for spec in SCRIPTS}
        if self.script_name:
            spec = specs.get(self.script_name)
            if spec is None:
                raise RuntimeError(f"unknown bpftrace script: {self.script_name}")
            return spec.script_path.resolve(), spec.workload_kind, spec.expected_programs
        if self.script_path is not None:
            if not self.script_path.exists():
                raise RuntimeError(f"bpftrace script not found: {self.script_path}")
            stem = self.script_path.name.removesuffix(".bt")
            spec = specs.get(stem)
            return self.script_path, self.workload_kind or (spec.workload_kind if spec else ""), int(self.expected_programs or (spec.expected_programs if spec else 1))
        if self.object_path is not None and self.object_path.suffix == ".bt":
            self.script_path = self.object_path
            return self._resolve_script()
        raise RuntimeError("BpftraceRunner requires script_name or script_path")

    def start(self) -> list[int]:
        if self.process is not None:
            raise RuntimeError("BpftraceRunner is already running")

        bpftrace_binary = which("bpftrace")
        if bpftrace_binary is None:
            raise RuntimeError("bpftrace is required but not present in PATH")
        script_path, workload_kind, expected_programs = self._resolve_script()
        self.workload_kind = self.workload_kind or workload_kind
        self.expected_programs = int(self.expected_programs or expected_programs or 1)
        self.process = start_agent(bpftrace_binary, ["-q", str(script_path)])
        programs = wait_for_attached_programs(
            self.process,
            expected_count=self.expected_programs,
            timeout_s=self.attach_timeout_s,
        )
        if not programs:
            self._fail_start(f"bpftrace did not attach any BPF programs for {script_path.name}")
        if len(programs) < self.expected_programs:
            attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
            self._fail_start(
                f"bpftrace attached {len(programs)} programs, expected at least {self.expected_programs}: {attached_names}"
            )
        if self.expected_program_names:
            expected = set(self.expected_program_names)
            matched = [program for program in programs if str(program.get("name") or "") in expected]
            found = {str(program.get("name") or "") for program in matched}
            missing = [name for name in self.expected_program_names if name not in found]
            if missing:
                attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
                self._fail_start(f"bpftrace did not attach expected programs {missing}; attached {attached_names}")
            programs = matched
        self.script_path = script_path
        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.process is None:
            raise RuntimeError("BpftraceRunner is not running")
        if not self.workload_kind:
            raise RuntimeError("bpftrace workload kind is not resolved")
        return run_named_workload(self.workload_kind, max(1, int(round(seconds))))

    def stop(self) -> None:
        if self.process is None:
            return
        process = self.process
        self.process = None
        stop_agent(process, timeout=8)
        self.process_output = finalize_process_output(process)


__all__ = ["BpftraceRunner", "SCRIPTS", "ScriptSpec", "finalize_process_output", "run_named_workload", "wait_for_attached_programs"]
