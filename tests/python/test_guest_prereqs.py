from __future__ import annotations

import os
from pathlib import Path

import pytest

from runner.libs import guest_prereqs


def test_resolve_remote_workload_tool_bin_requires_manifest_value(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    monkeypatch.setenv("RUN_WORKLOAD_TOOLS_CSV", "wrk")
    monkeypatch.delenv("RUN_REMOTE_WORKLOAD_TOOL_BIN", raising=False)
    with pytest.raises(SystemExit):
        guest_prereqs.resolve_remote_workload_tool_bin(tmp_path)


def test_validate_guest_prereqs_accepts_bundled_tool(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    tool_bin = workspace / ".cache" / "workload-tools" / "bin"
    tool_bin.mkdir(parents=True)
    bundled_tool = tool_bin / "wrk"
    bundled_tool.write_text("#!/usr/bin/env bash\nexit 0\n", encoding="utf-8")
    bundled_tool.chmod(0o755)
    monkeypatch.setenv("RUN_BPFTOOL_BIN", "true")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_BIN", "python3")
    monkeypatch.setenv("RUN_REMOTE_COMMANDS_CSV", "")
    monkeypatch.setenv("RUN_WORKLOAD_TOOLS_CSV", "wrk")
    monkeypatch.setenv("RUN_BUNDLED_WORKLOAD_TOOLS_CSV", "wrk")
    monkeypatch.setenv("RUN_REMOTE_WORKLOAD_TOOL_BIN", ".cache/workload-tools/bin")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_MODULES_CSV", "")
    guest_prereqs.validate_guest_prereqs(workspace)


def test_install_guest_prereqs_rejects_missing_bundled_tool(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    fake_bin = workspace / "bin"
    fake_bin.mkdir()
    for tool_name in ("bpftool", "python3"):
        tool_path = fake_bin / tool_name
        tool_path.write_text("#!/usr/bin/env bash\nexit 0\n", encoding="utf-8")
        tool_path.chmod(0o755)
    monkeypatch.setenv("PATH", str(fake_bin))
    monkeypatch.setenv("RUN_BPFTOOL_BIN", "bpftool")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_BIN", "python3")
    monkeypatch.setenv("RUN_REMOTE_COMMANDS_CSV", "")
    monkeypatch.setenv("RUN_WORKLOAD_TOOLS_CSV", "wrk")
    monkeypatch.setenv("RUN_BUNDLED_WORKLOAD_TOOLS_CSV", "wrk")
    monkeypatch.setenv("RUN_REMOTE_WORKLOAD_TOOL_BIN", ".cache/workload-tools/bin")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_MODULES_CSV", "")
    monkeypatch.setenv("RUN_GUEST_PACKAGE_MANAGER", "dnf")
    with pytest.raises(SystemExit):
        guest_prereqs.install_guest_prereqs(workspace)


def test_validate_guest_prereqs_checks_modules_with_remote_python(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    monkeypatch.setenv("RUN_BPFTOOL_BIN", "true")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_BIN", "python3")
    monkeypatch.setenv("RUN_REMOTE_COMMANDS_CSV", "")
    monkeypatch.setenv("RUN_WORKLOAD_TOOLS_CSV", "")
    monkeypatch.setenv("RUN_BUNDLED_WORKLOAD_TOOLS_CSV", "")
    monkeypatch.setenv("RUN_REMOTE_PYTHON_MODULES_CSV", "PyYAML")

    observed: list[tuple[str, str]] = []

    def fake_python_module_available(python_bin: str, import_name: str, *, path_value: str) -> bool:
        observed.append((python_bin, import_name))
        return True

    monkeypatch.setattr(guest_prereqs, "python_module_available", fake_python_module_available)
    guest_prereqs.validate_guest_prereqs(workspace)
    assert observed == [("python3", "yaml")]
