from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR, tail_text, which
from ..agent import start_agent, stop_agent
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .process_support import wait_for_attached_programs

DEFAULT_SCRIPT_DIR = ROOT_DIR / "e2e" / "cases" / "bpftrace" / "scripts"


@dataclass(frozen=True)
class ScriptSpec:
    name: str
    script_path: Path
    description: str
    expected_programs: int
    workload_kind: str


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="tcplife",
        script_path=DEFAULT_SCRIPT_DIR / "tcplife.bt",
        description="kprobe tcp_set_state: TCP session lifespan with IPv4/IPv6 struct field access, bswap, ntop, 3 maps",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
    ScriptSpec(
        name="biosnoop",
        script_path=DEFAULT_SCRIPT_DIR / "biosnoop.bt",
        description="tracepoint block_io_start/done: per-I/O latency with tuple-keyed maps and bitwise ops (dev >> 20)",
        expected_programs=2,
        workload_kind="block_io",
    ),
    ScriptSpec(
        name="runqlat",
        script_path=DEFAULT_SCRIPT_DIR / "runqlat.bt",
        description="tracepoint sched_wakeup/wakeup_new/switch: run queue latency histogram, 3 probes",
        expected_programs=3,
        workload_kind="scheduler",
    ),
    ScriptSpec(
        name="tcpretrans",
        script_path=DEFAULT_SCRIPT_DIR / "tcpretrans.bt",
        description="kprobe tcp_retransmit_skb: TCP retransmit tracing with 12-entry state string map, ntop/bswap",
        expected_programs=1,
        workload_kind="tcp_retransmit",
    ),
    ScriptSpec(
        name="capable",
        script_path=DEFAULT_SCRIPT_DIR / "capable.bt",
        description="kprobe cap_capable: security capability checks with 41-entry string map lookup",
        expected_programs=1,
        workload_kind="exec_storm",
    ),
    ScriptSpec(
        name="vfsstat",
        script_path=DEFAULT_SCRIPT_DIR / "vfsstat.bt",
        description="kprobe vfs_read*/write*/fsync/open/create: per-function counters with interval printing",
        expected_programs=2,
        workload_kind="vfs_create_write_fsync",
    ),
)


def finalize_process_output(process: Any) -> dict[str, object]:
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


DEFAULT_ATTACH_TIMEOUT_S = 20


class BpftraceRunner(AppRunner):
    def __init__(
        self,
        *,
        script_path: Path | str | None = None,
        script_name: str | None = None,
        workload_kind: str | None = None,
        expected_programs: int | None = None,
        expected_program_names: Sequence[str] = (),
        attach_timeout_s: int = DEFAULT_ATTACH_TIMEOUT_S,
    ) -> None:
        super().__init__()
        self.script_path = None if script_path is None else Path(script_path).resolve()
        self.script_name = str(script_name or "").strip()
        self.workload_kind = workload_kind
        self.expected_programs = int(expected_programs or 0)
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.attach_timeout_s = int(attach_timeout_s)
        self.process: Any | None = None

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
        self.command_used = [bpftrace_binary, "-q", str(script_path)]
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
            programs = self._filter_expected_programs(
                programs,
                self.expected_program_names,
                owner_label="bpftrace",
            )
        self.script_path = script_path
        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.process is None:
            raise RuntimeError("BpftraceRunner is not running")
        if not self.workload_kind:
            raise RuntimeError("bpftrace workload kind is not resolved")
        return run_named_workload(
            self.workload_kind,
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
        stop_agent(process, timeout=8)
        self.process_output = finalize_process_output(process)


__all__ = ["BpftraceRunner", "SCRIPTS", "ScriptSpec", "finalize_process_output", "wait_for_attached_programs"]
