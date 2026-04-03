from __future__ import annotations

import io
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.app_runners import bcc


class _FakeProcess:
    def __init__(self, *, stdout_text: str = "", stderr_text: str = "") -> None:
        self.pid = 4321
        self.returncode: int | None = None
        self.stdout = io.StringIO(stdout_text)
        self.stderr = io.StringIO(stderr_text)

    def poll(self) -> int | None:
        return self.returncode


def _make_tool(tmp_path: Path, name: str = "execsnoop") -> Path:
    tool = tmp_path / name
    tool.write_text("#!/bin/sh\nexit 0\n", encoding="utf-8")
    tool.chmod(0o755)
    return tool


def test_bcc_runner_uses_tool_args_from_shared_config(monkeypatch, tmp_path: Path) -> None:
    monkeypatch.setattr(
        bcc,
        "_bcc_tool_specs",
        lambda: {
            "execsnoop": bcc.BCCWorkloadSpec(
                name="execsnoop",
                workload_kind="exec_loop",
                expected_programs=2,
                spawn_timeout_s=15,
                tool_args=("-T", "-U", "-u", "65534"),
            )
        },
    )

    runner = bcc.BCCRunner(tool_name="execsnoop", tools_dir=tmp_path)

    assert runner.tool_args == ("-T", "-U", "-u", "65534")


def test_bcc_runner_start_fails_when_attached_program_count_is_short(monkeypatch, tmp_path: Path) -> None:
    process = _FakeProcess()
    monkeypatch.setattr(bcc.subprocess, "Popen", lambda *_args, **_kwargs: process)
    monkeypatch.setattr(
        bcc,
        "wait_for_attached_programs",
        lambda *_args, **_kwargs: [{"id": 101, "name": "tracepoint__syscalls__sys_enter_execve"}],
    )
    monkeypatch.setattr(
        bcc,
        "stop_agent",
        lambda proc, timeout=8: setattr(proc, "returncode", 0) or 0,
    )

    runner = bcc.BCCRunner(
        tool_binary=_make_tool(tmp_path),
        tool_name="execsnoop",
        expected_programs=2,
        attach_timeout_s=1,
    )

    try:
        runner.start()
    except RuntimeError as exc:
        assert "attached 1 programs, expected at least 2" in str(exc)
    else:
        raise AssertionError("runner.start() unexpectedly succeeded")
    assert runner.session is None


def test_bcc_runner_start_fails_when_expected_program_names_are_missing(monkeypatch, tmp_path: Path) -> None:
    process = _FakeProcess()
    monkeypatch.setattr(bcc.subprocess, "Popen", lambda *_args, **_kwargs: process)
    monkeypatch.setattr(
        bcc,
        "wait_for_attached_programs",
        lambda *_args, **_kwargs: [
            {"id": 101, "name": "tracepoint__syscalls__sys_enter_execve"},
            {"id": 102, "name": "tracepoint__syscalls__sys_exit_execve"},
        ],
    )
    monkeypatch.setattr(
        bcc,
        "stop_agent",
        lambda proc, timeout=8: setattr(proc, "returncode", 0) or 0,
    )

    runner = bcc.BCCRunner(
        tool_binary=_make_tool(tmp_path),
        tool_name="execsnoop",
        expected_programs=2,
        expected_program_names=(
            "tracepoint__syscalls__sys_enter_execve",
            "tracepoint__syscalls__sys_enter_execveat",
        ),
        attach_timeout_s=1,
    )

    try:
        runner.start()
    except RuntimeError as exc:
        assert "did not attach expected programs" in str(exc)
        assert "tracepoint__syscalls__sys_enter_execveat" in str(exc)
    else:
        raise AssertionError("runner.start() unexpectedly succeeded")
    assert runner.session is None


def test_bcc_tail_capture_keeps_bounded_tail() -> None:
    capture = bcc._TailCapture(max_lines=2, max_chars=20)
    capture.append("line-1\n")
    capture.append("line-2\n")
    capture.append("line-3\n")

    rendered = capture.render()

    assert "line-1" not in rendered
    assert "line-2" in rendered
    assert "line-3" in rendered


def test_bcc_runner_stop_captures_process_output(monkeypatch, tmp_path: Path) -> None:
    process = _FakeProcess(stdout_text="out-1\nout-2\n", stderr_text="err-1\n")
    monkeypatch.setattr(bcc.subprocess, "Popen", lambda *_args, **_kwargs: process)
    monkeypatch.setattr(
        bcc,
        "wait_for_attached_programs",
        lambda *_args, **_kwargs: [{"id": 101, "name": "tracepoint__syscalls__sys_enter_execve"}],
    )
    monkeypatch.setattr(
        bcc,
        "stop_agent",
        lambda proc, timeout=8: setattr(proc, "returncode", 0) or 0,
    )

    runner = bcc.BCCRunner(
        tool_binary=_make_tool(tmp_path),
        tool_name="execsnoop",
        expected_programs=1,
        attach_timeout_s=1,
    )

    assert runner.start() == [101]

    runner.stop()

    assert runner.process_output["returncode"] == 0
    assert "out-1" in str(runner.process_output["stdout_tail"])
    assert "out-2" in str(runner.process_output["stdout_tail"])
    assert "err-1" in str(runner.process_output["stderr_tail"])
