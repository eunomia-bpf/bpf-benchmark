from __future__ import annotations

from pathlib import Path

from runner.libs import run_target_suite


def test_benchmark_all_fans_out_parallel_for_aws(monkeypatch, tmp_path: Path) -> None:
    def fake_write_target_manifest(target_name: str, manifest_path: Path) -> None:
        manifest_path.write_text("RUN_EXECUTOR=aws-ssh\n", encoding="utf-8")

    spawned: list[list[str]] = []

    class FakePopen:
        def __init__(self, command: list[str], cwd: Path) -> None:
            spawned.append(command)
            self.returncode = 0

        def wait(self) -> int:
            return 0

    monkeypatch.setattr(run_target_suite, "_write_target_manifest", fake_write_target_manifest)
    monkeypatch.setattr(run_target_suite.subprocess, "Popen", FakePopen)

    run_target_suite._benchmark_action("aws-x86", "all")

    assert len(spawned) == 3
    assert spawned[0][-3:] == ["run", "aws-x86", "micro"]
    assert spawned[1][-3:] == ["run", "aws-x86", "corpus"]
    assert spawned[2][-3:] == ["run", "aws-x86", "e2e"]


def test_benchmark_all_runs_serially_for_kvm(monkeypatch, tmp_path: Path) -> None:
    def fake_write_target_manifest(target_name: str, manifest_path: Path) -> None:
        manifest_path.write_text("RUN_EXECUTOR=kvm\n", encoding="utf-8")

    seen: list[tuple[str, str]] = []

    def fake_run_action(target_name: str, suite_name: str) -> None:
        seen.append((target_name, suite_name))

    monkeypatch.setattr(run_target_suite, "_write_target_manifest", fake_write_target_manifest)
    monkeypatch.setattr(run_target_suite, "_run_action", fake_run_action)

    run_target_suite._benchmark_action("x86-kvm", "all")

    assert seen == [("x86-kvm", "micro"), ("x86-kvm", "corpus"), ("x86-kvm", "e2e")]
