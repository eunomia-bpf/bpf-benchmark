from __future__ import annotations

from pathlib import Path
from typing import Any, Mapping, Sequence

from .. import ROOT_DIR
from ..workload import WorkloadResult
from .base import AppRunner
from .scx_support import ScxSchedulerSession, preferred_path, read_scx_ops, read_scx_state, run_workload


DEFAULT_SCX_REPO = ROOT_DIR / "runner" / "repos" / "scx"
DEFAULT_SCX_BINARY = DEFAULT_SCX_REPO / "target" / "release" / "scx_rusty"
DEFAULT_LOAD_TIMEOUT_S = 20


def _scheduler_binary_for_name(scheduler: str | None) -> Path:
    normalized = str(scheduler or "").strip()
    if not normalized:
        return DEFAULT_SCX_BINARY
    return DEFAULT_SCX_REPO / "target" / "release" / f"scx_{normalized}"


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
        self.workload_spec: Mapping[str, object] = dict(
            workload_spec
            or {"name": "hackbench", "kind": "hackbench", "metric": "runs/s"}
        )
        self.last_workload_extra: dict[str, object] = {}

    @property
    def pid(self) -> int | None:
        return None if self.session is None else self.session.pid

    def collector_snapshot(self) -> dict[str, object]:
        return {} if self.session is None else self.session.collector_snapshot()

    def corpus_measurement_mode(self) -> str:
        return "app"

    @property
    def program_fds(self) -> dict[int, int]:
        return {} if self.session is None else dict(self.session.program_fds)

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


__all__ = ["ScxRunner", "ScxSchedulerSession", "preferred_path", "read_scx_ops", "read_scx_state", "run_workload"]
