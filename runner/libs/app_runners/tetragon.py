from __future__ import annotations

import tempfile
from pathlib import Path
from typing import Any, Mapping, NoReturn, Sequence

import yaml

from .. import ROOT_DIR
from ..workload import WorkloadResult
from .tetragon_support import (
    TetragonAgentSession,
    describe_agent_exit,
    resolve_tetragon_binary,
    run_exec_storm_in_cgroup,
    run_setup_script,
    run_tetragon_workload,
    write_tetragon_policies,
)


DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "tetragon" / "config_execve_rate.yaml"
DEFAULT_SETUP_SCRIPT = ROOT_DIR / "e2e" / "cases" / "tetragon" / "setup.sh"
DEFAULT_LOAD_TIMEOUT_S = 20


def _default_extra_args() -> tuple[str, ...]:
    payload = yaml.safe_load(DEFAULT_CONFIG.read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        return ()
    return tuple(str(arg) for arg in (payload.get("tetragon_extra_args") or []) if str(arg).strip())


class TetragonRunner:
    def __init__(
        self,
        *,
        object_path: Path | str | None = None,
        tetragon_binary: Path | str | None = None,
        tetragon_extra_args: Sequence[str] = (),
        expected_program_names: Sequence[str] = (),
        load_timeout_s: int = DEFAULT_LOAD_TIMEOUT_S,
        setup_script: Path | str = DEFAULT_SETUP_SCRIPT,
        skip_setup: bool = False,
    ) -> None:
        self.object_path = None if object_path is None else Path(object_path).resolve()
        self.tetragon_binary = None if tetragon_binary is None else Path(tetragon_binary).resolve()
        self.tetragon_extra_args = tuple(str(arg) for arg in (tetragon_extra_args or _default_extra_args()) if str(arg).strip())
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.load_timeout_s = int(load_timeout_s)
        self.setup_script = Path(setup_script).resolve()
        self.skip_setup = bool(skip_setup)
        self.setup_result: dict[str, object] = {"returncode": 0, "tetragon_binary": None, "tetra_binary": None, "stdout_tail": "", "stderr_tail": ""}
        self.tempdir: tempfile.TemporaryDirectory[str] | None = None
        self.policy_paths: list[Path] = []
        self.command: list[str] = []
        self.session: Any | None = None
        self.programs: list[dict[str, object]] = []
        self.process_output: dict[str, object] = {}
        self.workload_spec: Mapping[str, object] = {"kind": "exec_storm", "value": 2}
        self.exec_workload_cgroup = any(arg == "--cgroup-rate" for arg in self.tetragon_extra_args)

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

    def _resolve_binary(self) -> str:
        resolved = resolve_tetragon_binary(None if self.tetragon_binary is None else str(self.tetragon_binary), self.setup_result)
        if resolved is None and not self.skip_setup:
            self.setup_result = run_setup_script(self.setup_script)
            if int(self.setup_result.get("returncode", 0) or 0) != 0:
                details = str(self.setup_result.get("stderr_tail") or self.setup_result.get("stdout_tail") or self.setup_result)
                raise RuntimeError(f"Tetragon setup failed: {details}")
            resolved = resolve_tetragon_binary(
                None if self.tetragon_binary is None else str(self.tetragon_binary),
                self.setup_result,
            )
        if resolved is None:
            raise RuntimeError("Tetragon binary not found; provide --tetragon-binary or run the Tetragon setup script")
        return resolved

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError("TetragonRunner is already running")

        tetragon_binary = self._resolve_binary()
        self.tempdir = tempfile.TemporaryDirectory(prefix="tetragon-policy-")
        policy_dir = Path(self.tempdir.name)
        self.policy_paths = write_tetragon_policies(policy_dir)
        self.command = [tetragon_binary, *self.tetragon_extra_args, "--tracing-policy-dir", str(policy_dir)]
        session = TetragonAgentSession(self.command, self.load_timeout_s)
        try:
            session.__enter__()
        except Exception:
            self.tempdir.cleanup()
            self.tempdir = None
            raise
        self.session = session
        self.tetragon_binary = Path(tetragon_binary).resolve()
        programs = [dict(program) for program in session.programs]
        if not programs:
            self._fail_start("Tetragon did not attach any BPF programs")
        if self.expected_program_names:
            expected = set(self.expected_program_names)
            matched = [program for program in programs if str(program.get("name") or "") in expected]
            found = {str(program.get("name") or "") for program in matched}
            missing = [name for name in self.expected_program_names if name not in found]
            if missing:
                attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
                self._fail_start(f"Tetragon did not attach expected programs {missing}; attached {attached_names}")
            programs = matched
        self.programs = programs
        return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError("TetragonRunner is not running")
        return run_tetragon_workload(
            self.workload_spec,
            max(1, int(round(seconds))),
            exec_workload_cgroup=self.exec_workload_cgroup,
        )

    def stop(self) -> None:
        if self.session is None and self.tempdir is None:
            return
        errors: list[str] = []
        if self.session is not None:
            session = self.session
            self.session = None
            self.process_output = session.collector_snapshot()
            try:
                session.close()
            except Exception as exc:
                errors.append(str(exc))
        if self.tempdir is not None:
            try:
                self.tempdir.cleanup()
            except Exception as exc:
                errors.append(str(exc))
            self.tempdir = None
        if errors:
            raise RuntimeError("; ".join(errors))


__all__ = [
    "TetragonAgentSession",
    "TetragonRunner",
    "describe_agent_exit",
    "resolve_tetragon_binary",
    "run_exec_storm_in_cgroup",
    "run_setup_script",
    "run_tetragon_workload",
    "write_tetragon_policies",
]
