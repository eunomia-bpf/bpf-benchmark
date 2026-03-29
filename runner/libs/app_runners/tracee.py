from __future__ import annotations

from pathlib import Path
from typing import Any, NoReturn, Sequence

import yaml

from .. import ROOT_DIR
from ..workload import WorkloadResult, run_user_exec_loop


DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"
DEFAULT_SETUP_SCRIPT = ROOT_DIR / "e2e" / "cases" / "tracee" / "setup.sh"
DEFAULT_LOAD_TIMEOUT_S = 20


def _default_events() -> tuple[str, ...]:
    payload = yaml.safe_load(DEFAULT_CONFIG.read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        return ()
    return tuple(str(event) for event in (payload.get("events") or []) if str(event).strip())


class TraceeRunner:
    def __init__(
        self,
        *,
        object_path: Path | str | None = None,
        tracee_binary: Path | str | None = None,
        events: Sequence[str] = (),
        extra_args: Sequence[str] = (),
        expected_program_names: Sequence[str] = (),
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        setup_script: Path | str = DEFAULT_SETUP_SCRIPT,
        skip_setup: bool = False,
    ) -> None:
        self.object_path = None if object_path is None else Path(object_path).resolve()
        self.tracee_binary = None if tracee_binary is None else Path(tracee_binary).resolve()
        self.events = tuple(str(event) for event in (events or _default_events()) if str(event).strip())
        self.extra_args = tuple(str(arg) for arg in extra_args)
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.load_timeout_s = int(load_timeout_s)
        self.setup_script = Path(setup_script).resolve()
        self.skip_setup = bool(skip_setup)
        self.session: Any | None = None
        self.programs: list[dict[str, object]] = []
        self.process_output: dict[str, object] = {}
        self.setup_result: dict[str, object] = {"returncode": 0, "tracee_binary": None, "stdout_tail": "", "stderr_tail": ""}

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
        return None if self.session is None else self.session.pid

    @property
    def collector(self) -> Any | None:
        return None if self.session is None else self.session.collector

    @property
    def program_fds(self) -> dict[int, int]:
        return {} if self.session is None else dict(self.session.program_fds)

    def _resolve_binary(self, tracee_case: Any) -> str:
        resolved = tracee_case.resolve_tracee_binary(None if self.tracee_binary is None else str(self.tracee_binary), self.setup_result)
        if resolved is None and not self.skip_setup:
            self.setup_result = tracee_case.run_setup_script(self.setup_script)
            if int(self.setup_result.get("returncode", 0) or 0) != 0:
                details = str(self.setup_result.get("stderr_tail") or self.setup_result.get("stdout_tail") or self.setup_result)
                raise RuntimeError(f"Tracee setup failed: {details}")
            resolved = tracee_case.resolve_tracee_binary(
                None if self.tracee_binary is None else str(self.tracee_binary),
                self.setup_result,
            )
        if resolved is None:
            raise RuntimeError("Tracee binary not found; provide --tracee-binary or run the Tracee setup script")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("TraceeRunner is already running")
        if not self.events:
            raise RuntimeError("TraceeRunner requires at least one Tracee event")
        from e2e.cases.tracee import case as tracee_case

        tracee_binary = self._resolve_binary(tracee_case)
        commands = tracee_case.build_tracee_commands(tracee_binary, self.events, self.extra_args)
        session = tracee_case.TraceeAgentSession(commands, self.load_timeout_s)
        session.__enter__()
        self.session = session
        programs = [dict(program) for program in session.programs]
        if not programs:
            self._fail_start("Tracee did not attach any BPF programs")
        if self.expected_program_names:
            expected = set(self.expected_program_names)
            matched = [program for program in programs if str(program.get("name") or "") in expected]
            found = {str(program.get("name") or "") for program in matched}
            missing = [name for name in self.expected_program_names if name not in found]
            if missing:
                attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
                self._fail_start(f"Tracee did not attach expected programs {missing}; attached {attached_names}")
            programs = matched
        self.tracee_binary = Path(tracee_binary).resolve()
        self.programs = programs
        return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TraceeRunner is not running")
        return run_user_exec_loop(max(1, int(round(seconds))), mark_fallback=False)

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        snapshot = session.collector_snapshot()
        process = session.process
        session.close()
        self.process_output = {
            "returncode": None if process is None else process.returncode,
            "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
            "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
            "latest_stats": snapshot.get("latest_stats") or {},
        }


__all__ = ["TraceeRunner"]
