from __future__ import annotations

import os
import re
import shlex
import statistics
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import resolve_bpftool_binary, run_command, run_json_command, tail_text, which
from ..agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from ..process_fd import dup_fd_from_process
from ..workload import WorkloadResult, resolve_workload_tool
from .base import AppRunner
from .process_support import AgentSession
from .setup_support import repo_artifact_root


HACKBENCH_TIME_RE = re.compile(r"Time:\s*([0-9.]+)")
STRESS_NG_CPU_RE = re.compile(
    r"stress-ng: metrc: .*?\bcpu\s+([0-9.]+)\s+([0-9.]+)\s+[0-9.]+\s+[0-9.]+\s+([0-9.]+)"
)
SYSBENCH_EVENTS_RE = re.compile(r"events per second:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_TOTAL_EVENTS_RE = re.compile(r"total number of events:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_LATENCY_AVG_RE = re.compile(r"avg:\s*([0-9.]+)", re.IGNORECASE)
SYSBENCH_LATENCY_P95_RE = re.compile(r"95th percentile:\s*([0-9.]+)", re.IGNORECASE)


def preferred_path() -> str:
    current = os.environ.get("PATH", "")
    prefix = "/usr/local/sbin"
    parts = [part for part in current.split(":") if part]
    if prefix in parts:
        return current
    return f"{prefix}:{current}" if current else prefix


def read_scx_state() -> str:
    path = Path("/sys/kernel/sched_ext/state")
    if not path.is_file():
        raise RuntimeError(f"sched_ext state file is missing: {path}")
    try:
        return path.read_text().strip()
    except OSError as exc:
        raise RuntimeError(f"failed to read sched_ext state from {path}: {exc}") from exc


def read_scx_ops() -> list[str]:
    root = Path("/sys/kernel/sched_ext")
    if not root.exists():
        raise RuntimeError(f"sched_ext root is missing: {root}")
    values: list[str] = []
    candidates = sorted(root.glob("*/ops"))
    if not candidates:
        state = read_scx_state()
        if state == "disabled":
            return []
        raise RuntimeError(f"sched_ext ops entries are missing under {root} while sched_ext state is {state!r}")
    for candidate in candidates:
        try:
            text = candidate.read_text().strip()
        except OSError as exc:
            raise RuntimeError(f"failed to read sched_ext ops entry {candidate}: {exc}") from exc
        if text:
            values.append(text)
    if not values:
        state = read_scx_state()
        if state == "disabled":
            return []
        raise RuntimeError(f"sched_ext ops entries under {root} were empty while sched_ext state is {state!r}")
    return values


def _program_id(program: Mapping[str, object]) -> int:
    return int(program.get("id", 0) or 0)


def _program_name(program: Mapping[str, object]) -> str:
    return str(program.get("name") or "").strip()


def _bpftool_struct_ops_programs() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned unexpected payload")
    programs = [
        dict(record)
        for record in payload
        if isinstance(record, Mapping) and str(record.get("type", "")) == "struct_ops"
    ]
    programs.sort(key=_program_id)
    return programs


class ScxSchedulerSession(AgentSession):
    def __init__(self, binary: Path, extra_args: Sequence[str], load_timeout: int) -> None:
        super().__init__(load_timeout)
        self.binary = binary
        self.extra_args = list(extra_args)
        self.program_fds: dict[int, int] = {}
        self.command_used: list[str] | None = None
        self.scheduler_program_names: set[str] = set()

    def __enter__(self) -> "ScxSchedulerSession":
        command_text = " ".join(["set -euo pipefail;", "ulimit -l unlimited;", "exec",
                                  shlex.quote(str(self.binary)), "--stats", "1",
                                  *[shlex.quote(str(arg)) for arg in self.extra_args]])
        self.command_used = ["bash", "-lc", command_text]
        self.process = start_agent("bash", ["-lc", command_text], env={"PATH": preferred_path()})
        self._start_io_threads()
        try:
            healthy = wait_healthy(self.process, self.load_timeout,
                                   lambda: read_scx_state() == "enabled" and bool(self._discover_owned_programs()))
        except Exception:
            self.close()
            raise
        if not healthy:
            snapshot = self.collector.snapshot()
            details = tail_text("\n".join(list(snapshot.get("stderr_tail") or []) + list(snapshot.get("stdout_tail") or [])),
                                max_lines=40, max_chars=8000)
            self.close()
            raise RuntimeError(f"scx_rusty did not become healthy: {details}")

        self.programs = self._discover_owned_programs()
        self._remember_scheduler_programs(self.programs)
        self.program_fds = self._dup_program_fds(self.programs, require_owner=True)
        return self

    def _discover_owned_programs(self) -> list[dict[str, object]]:
        if self.pid is None:
            return []
        programs = [
            item
            for item in find_bpf_programs(self.pid)
            if str(item.get("type", "")) == "struct_ops"
        ]
        programs.sort(key=_program_id)
        return programs

    def _remember_scheduler_programs(self, programs: Sequence[Mapping[str, object]]) -> None:
        self.scheduler_program_names.update(
            name
            for program in programs
            if (name := _program_name(program))
        )

    def _discover_live_scheduler_programs(self) -> list[dict[str, object]]:
        owned_programs = self._discover_owned_programs()
        self._remember_scheduler_programs(owned_programs)
        if not self.scheduler_program_names:
            return owned_programs

        owned_by_id = {_program_id(program): dict(program) for program in owned_programs}
        all_struct_ops = _bpftool_struct_ops_programs()
        live_programs: list[dict[str, object]] = []
        for program in all_struct_ops:
            if _program_name(program) not in self.scheduler_program_names:
                continue
            enriched = dict(program)
            owned = owned_by_id.get(_program_id(enriched))
            if owned is not None:
                if "owner_pids" in owned:
                    enriched["owner_pids"] = owned["owner_pids"]
                if "owner_fds" in owned:
                    enriched["owner_fds"] = owned["owner_fds"]
            live_programs.append(enriched)
        return live_programs

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def refresh_programs(self) -> list[dict[str, object]]:
        refreshed = self._discover_live_scheduler_programs()
        refreshed_fds = self._dup_program_fds(refreshed, require_owner=False)
        close_errors: list[str] = []
        for fd in self.program_fds.values():
            try:
                os.close(fd)
            except OSError as exc:
                close_errors.append(f"failed to close stale SCX program fd {fd}: {exc}")
        self.programs = refreshed
        self.program_fds = refreshed_fds
        if close_errors:
            raise RuntimeError("; ".join(close_errors))
        return [dict(program) for program in self.programs]

    def _dup_program_fds(self, programs: Sequence[Mapping[str, object]], *, require_owner: bool) -> dict[int, int]:
        if self.pid is None:
            raise RuntimeError("cannot duplicate scx program FDs without a live scheduler pid")
        duplicated: dict[int, int] = {}
        for program in programs:
            prog_id = int(program.get("id", -1))
            program_name = str(program.get("name") or prog_id)
            owner_refs = [ref for ref in (program.get("owner_fds") or []) if int(ref.get("pid", -1)) == int(self.pid)]
            if not owner_refs:
                if not require_owner:
                    continue
                raise RuntimeError(f"SCX program {program_name!r} (id={prog_id}) did not expose a scheduler-owned FD")
            duplicated[prog_id] = dup_fd_from_process(int(self.pid), int(owner_refs[0]["fd"]))
        return duplicated

    def close(self) -> None:
        close_errors: list[str] = []
        for fd in self.program_fds.values():
            try:
                os.close(fd)
            except OSError as exc:
                close_errors.append(f"failed to close SCX program fd {fd}: {exc}")
        self.program_fds.clear()
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        self._join_io_threads()
        if close_errors:
            raise RuntimeError("; ".join(close_errors))


def _percentile(values: Sequence[float], percentile: float) -> float:
    ordered = sorted(float(value) for value in values)
    if len(ordered) == 1:
        return ordered[0]
    rank = max(0.0, min(1.0, percentile / 100.0)) * (len(ordered) - 1)
    lower = int(rank)
    upper = min(len(ordered) - 1, lower + 1)
    weight = rank - lower
    return ordered[lower] * (1.0 - weight) + ordered[upper] * weight


def run_hackbench(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    hackbench = resolve_workload_tool("hackbench")
    command = [hackbench, "-g", "4", "-l", "1000"]
    start = time.monotonic()
    deadline = start + float(duration_s)
    iteration_times: list[float] = []
    stdout_lines: list[str] = []
    stderr_lines: list[str] = []
    completed_runs = 0.0
    while time.monotonic() < deadline:
        iter_start = time.monotonic()
        completed = run_command(command, check=False, timeout=max(30, int(duration_s) + 10))
        iter_elapsed = time.monotonic() - iter_start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"hackbench failed: {details}")
        combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
        match = HACKBENCH_TIME_RE.search(combined)
        iteration_times.append(float(match.group(1)) if match else iter_elapsed)
        stdout_lines.append(completed.stdout or "")
        stderr_lines.append(completed.stderr or "")
        completed_runs += 1.0
    elapsed = time.monotonic() - start
    result = WorkloadResult(
        ops_total=completed_runs,
        ops_per_sec=(completed_runs / elapsed) if elapsed > 0 else None,
        duration_s=elapsed,
        stdout=tail_text("\n".join(stdout_lines), max_lines=40, max_chars=8000),
        stderr=tail_text("\n".join(stderr_lines), max_lines=40, max_chars=8000),
    )
    return result, {
        "command": command,
        "iterations": int(completed_runs),
        "latency_ms_p50": None if not iteration_times else statistics.median(iteration_times) * 1000.0,
        "latency_ms_p95": None if not iteration_times else _percentile(iteration_times, 95.0) * 1000.0,
    }


def run_stress_ng_cpu(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the stress-ng-cpu workload")
    command = [stress_ng, "--cpu", "4", "--timeout", f"{max(1, int(duration_s))}s", "--metrics-brief"]
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(duration_s) + 60)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"stress-ng cpu failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    match = STRESS_NG_CPU_RE.search(combined)
    ops_total = float(match.group(1)) if match else 0.0
    ops_per_sec = float(match.group(3)) if match else ((ops_total / elapsed) if elapsed > 0 else None)
    result = WorkloadResult(
        ops_total=ops_total,
        ops_per_sec=ops_per_sec,
        duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    )
    return result, {"command": command, "latency_ms_p50": None, "latency_ms_p95": None}


def run_sysbench_cpu(duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    sysbench = resolve_workload_tool("sysbench")
    command = [sysbench, "cpu", "--threads=4", f"--time={max(1, int(duration_s))}", "run"]
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(duration_s) + 60)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"sysbench cpu failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    eps_match = SYSBENCH_EVENTS_RE.search(combined)
    total_match = SYSBENCH_TOTAL_EVENTS_RE.search(combined)
    lat_avg_match = SYSBENCH_LATENCY_AVG_RE.search(combined)
    lat_p95_match = SYSBENCH_LATENCY_P95_RE.search(combined)
    ops_total = float(total_match.group(1)) if total_match else 0.0
    ops_per_sec = float(eps_match.group(1)) if eps_match else ((ops_total / elapsed) if elapsed > 0 else None)
    result = WorkloadResult(
        ops_total=ops_total,
        ops_per_sec=ops_per_sec,
        duration_s=elapsed,
        stdout=tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        stderr=tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    )
    return result, {
        "command": command,
        "latency_ms_p50": float(lat_avg_match.group(1)) if lat_avg_match else None,
        "latency_ms_p95": float(lat_p95_match.group(1)) if lat_p95_match else None,
    }


def run_workload(spec: Mapping[str, object], duration_s: int) -> tuple[WorkloadResult, dict[str, object]]:
    kind = str(spec.get("kind", ""))
    if kind == "hackbench":
        return run_hackbench(duration_s)
    if kind == "stress_ng_cpu":
        return run_stress_ng_cpu(duration_s)
    if kind == "sysbench_cpu":
        return run_sysbench_cpu(duration_s)
    raise RuntimeError(f"unsupported scx workload kind: {kind}")

DEFAULT_LOAD_TIMEOUT_S = 20


def _default_scx_binary_dir() -> Path:
    return repo_artifact_root() / "scx" / "bin"


def _default_scx_binary() -> Path:
    return _default_scx_binary_dir() / "scx_rusty"


def _scheduler_binary_for_name(scheduler: str | None) -> Path:
    normalized = str(scheduler or "").strip()
    if not normalized:
        return _default_scx_binary()
    return _default_scx_binary_dir() / f"scx_{normalized}"


class ScxRunner(AppRunner):
    def __init__(
        self,
        *,
        scheduler: str = "rusty",
        scheduler_binary: Path | str | None = None,
        scheduler_extra_args: Sequence[str] = (),
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        workload_spec: Mapping[str, object] | None = None,
    ) -> None:
        super().__init__()
        self.scheduler = str(scheduler).strip()
        if not self.scheduler:
            raise RuntimeError("ScxRunner requires a scheduler name")
        inferred = _scheduler_binary_for_name(self.scheduler)
        self.scheduler_binary = Path(scheduler_binary).resolve() if scheduler_binary is not None else inferred.resolve()
        self.scheduler_extra_args = tuple(str(arg) for arg in scheduler_extra_args)
        self.load_timeout_s = int(load_timeout_s)
        self.session: Any | None = None
        self.workload_spec: Mapping[str, object] = dict(workload_spec or {"name": "hackbench", "kind": "hackbench", "metric": "runs/s"})
        self.last_workload_extra: dict[str, object] = {}

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    def collector_snapshot(self) -> dict[str, object]:
        return {} if self.session is None else self.session.collector_snapshot()

    @property
    def program_fds(self) -> dict[int, int]:
        return {} if self.session is None else dict(self.session.program_fds)

    @property
    def last_workload_details(self) -> Mapping[str, object]:
        return dict(self.last_workload_extra)

    def refresh_live_programs(self) -> list[dict[str, object]]:
        if self.session is None:
            raise RuntimeError("ScxRunner is not running")
        self.programs = self.session.refresh_programs()
        return [dict(program) for program in self.programs]

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("ScxRunner is already running")
        if not self.scheduler_binary.exists():
            raise RuntimeError(f"scx scheduler binary not found: {self.scheduler_binary}")
        session = ScxSchedulerSession(self.scheduler_binary, self.scheduler_extra_args, self.load_timeout_s)
        session.__enter__()
        self.session = session
        self.command_used = list(session.command_used or [])
        self.programs = [dict(program) for program in session.programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("ScxRunner is not running")
        result, extra = run_workload(self.workload_spec, max(1, int(round(seconds))))
        self.last_workload_extra = dict(extra)
        return result

    def run_workload_spec(self, workload_spec: Mapping[str, object], seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("ScxRunner is not running")
        result, extra = run_workload(workload_spec, max(1, int(round(seconds))))
        self.last_workload_extra = dict(extra)
        return result

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        self.process_output = session.collector_snapshot()
        session.close()
