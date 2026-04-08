from __future__ import annotations

import subprocess
from pathlib import Path

from runner.libs import portable_runtime, runner_artifacts


def test_require_file_contains_follows_symlinks(monkeypatch, tmp_path: Path) -> None:
    target = tmp_path / "target"
    target.write_text("x\n", encoding="utf-8")
    link = tmp_path / "link"
    link.symlink_to(target.name)
    seen: dict[str, list[str]] = {}

    def fake_run(command: list[str], **kwargs) -> subprocess.CompletedProcess[str]:
        seen["command"] = command
        return subprocess.CompletedProcess(command, 0, stdout="ELF 64-bit LSB pie executable, x86-64\n", stderr="")

    monkeypatch.setattr(runner_artifacts.subprocess, "run", fake_run)

    runner_artifacts.require_file_contains(link, "x86-64", "test binary")

    assert seen["command"] == ["file", "-L", str(link)]


def test_portable_runtime_arch_check_follows_symlinks(monkeypatch, tmp_path: Path) -> None:
    link = tmp_path / "libbpf.so.1"
    link.symlink_to("libbpf.so.1.7.0")
    seen: dict[str, list[str]] = {}

    def fake_run(command: list[str], *, env=None, cwd=None) -> subprocess.CompletedProcess[str]:
        seen["command"] = command
        return subprocess.CompletedProcess(command, 0, stdout="ELF 64-bit LSB shared object, x86-64\n", stderr="")

    monkeypatch.setattr(portable_runtime, "_run", fake_run)

    portable_runtime._require_arch_signature(link, "x86-64", "portable x86 libbpf output")

    assert seen["command"] == ["file", "-L", str(link)]


def test_remote_entrypoints_avoid_runtime_pep604_casts() -> None:
    root = Path(__file__).resolve().parents[2]
    for relpath in (
        "runner/libs/execute_workspace.py",
        "runner/libs/suite_entrypoint.py",
    ):
        text = (root / relpath).read_text(encoding="utf-8")
        assert "cast(dict[str, str | list[str]], contract)" not in text
