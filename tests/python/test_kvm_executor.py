from __future__ import annotations

import tarfile
from pathlib import Path

from runner.libs import kvm_executor


def test_kvm_executor_builds_vm_command_from_manifest_and_local_state(
    monkeypatch,
    tmp_path: Path,
) -> None:
    bundle_root = tmp_path / "bundle"
    workspace = bundle_root / "workspace"
    (workspace / "runner/scripts").mkdir(parents=True)
    (workspace / "runner/scripts/execute_workspace.sh").write_text("#!/usr/bin/env bash\n", encoding="utf-8")
    (workspace / "run-contract.env").write_text("RUN_TARGET_NAME=x86-kvm\n", encoding="utf-8")

    bundle_tar = tmp_path / "bundle.tar.gz"
    with tarfile.open(bundle_tar, "w:gz") as archive:
        archive.add(workspace / "run-contract.env", arcname="run-contract.env")
        archive.add(
            workspace / "runner/scripts/execute_workspace.sh",
            arcname="runner/scripts/execute_workspace.sh",
        )

    manifest = tmp_path / "manifest.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_EXECUTOR=kvm",
                "RUN_HOST_PYTHON_BIN=python3",
                "RUN_VM_BACKEND=vng",
                "RUN_VM_EXECUTABLE=vng",
                "RUN_VM_LOCK_SCOPE=x86-kvm",
                "RUN_VM_KERNEL_IMAGE=/tmp/bzImage",
                "RUN_VM_TIMEOUT_SECONDS=3600",
                "RUN_TARGET_NAME=x86-kvm",
                "RUN_TARGET_ARCH=x86_64",
                "RUN_SUITE_NAME=test",
                "",
            ]
        ),
        encoding="utf-8",
    )
    local_state = tmp_path / "local-state.env"
    local_state.write_text(f"RUN_BUNDLE_TAR={bundle_tar}\n", encoding="utf-8")

    calls: list[list[str]] = []

    class Completed:
        returncode = 0

    def fake_run(command: list[str], **_: object):  # type: ignore[override]
        calls.append(command)
        return Completed()

    monkeypatch.setattr(kvm_executor.subprocess, "run", fake_run)

    try:
        kvm_executor.main([str(manifest), str(local_state)])
    except SystemExit as exc:
        assert exc.code == 0

    assert len(calls) == 1
    command = calls[0]
    assert command[0] == "python3"
    assert command[1].endswith("runner/scripts/run_vm_shell.py")
    assert "--vm-backend" in command
    assert "--command" in command
    assert "execute_workspace.sh" in command[command.index("--command") + 1]
