from __future__ import annotations

from abc import ABC, abstractmethod
from typing import Mapping, NoReturn, Sequence

from ..workload import WorkloadResult


class AppRunner(ABC):
    def __init__(self) -> None:
        self.programs: list[dict[str, object]] = []
        self.artifacts: dict[str, object] = {}
        self.process_output: dict[str, object] = {}
        self.command_used: list[str] = []

    @abstractmethod
    def start(self) -> list[int]:
        raise NotImplementedError

    @abstractmethod
    def run_workload(self, seconds: float) -> WorkloadResult:
        raise NotImplementedError

    @abstractmethod
    def stop(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def select_corpus_program_ids(
        self,
        initial_stats: Mapping[int, Mapping[str, object]],
        final_stats: Mapping[int, Mapping[str, object]],
    ) -> list[int] | None:
        raise NotImplementedError

    @abstractmethod
    def corpus_measurement_mode(self) -> str:
        raise NotImplementedError

    @property
    @abstractmethod
    @property
    def program_fds(self) -> Mapping[int, int]:
        raise NotImplementedError

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

    def _filter_expected_programs(
        self,
        programs: Sequence[dict[str, object]],
        expected_program_names: Sequence[str],
        *,
        owner_label: str,
    ) -> list[dict[str, object]]:
        expected = tuple(str(name) for name in expected_program_names if str(name).strip())
        selected = [dict(program) for program in programs]
        if not expected:
            return selected
        expected_set = set(expected)
        matched = [program for program in selected if str(program.get("name") or "") in expected_set]
        found = {str(program.get("name") or "") for program in matched}
        missing = [name for name in expected if name not in found]
        if missing:
            attached = sorted(str(program.get("name") or "") for program in selected if str(program.get("name") or "").strip())
            self._fail_start(f"{owner_label} did not attach expected programs {missing}; attached {attached}")
        return matched


__all__ = ["AppRunner"]
