from __future__ import annotations

from typing import Mapping, NoReturn

from ..workload import WorkloadResult


class AppRunner:
    def __init__(self) -> None:
        self.programs: list[dict[str, object]] = []
        self.artifacts: dict[str, object] = {}
        self.process_output: dict[str, object] = {}
        self.command_used: list[str] = []

    def start(self) -> list[int]:
        raise NotImplementedError

    def run_workload(self, seconds: float) -> WorkloadResult:
        raise NotImplementedError

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        raise NotImplementedError

    def stop(self) -> None:
        raise NotImplementedError

    @property
    def pid(self) -> int | None:
        raise NotImplementedError

    @property
    def last_workload_details(self) -> Mapping[str, object]:
        return {}

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
