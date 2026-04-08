from __future__ import annotations

import subprocess
from pathlib import Path

import pytest

from runner.libs import prepare_local_inputs


def test_prepare_local_inputs_dispatches_kvm(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    manifest.write_text(
        "RUN_EXECUTOR=kvm\n"
        "RUN_SUITE_NAME=test\n"
        "RUN_HOST_PYTHON_BIN=python3\n",
        encoding="utf-8",
    )
    seen: dict[str, object] = {}

    def fake_run(cmd, *, cwd, env, text, capture_output, check):  # type: ignore[no-untyped-def]
        seen["cmd"] = cmd
        seen["cwd"] = cwd
        seen["env"] = env
        return subprocess.CompletedProcess(cmd, 0)

    monkeypatch.setattr(subprocess, "run", fake_run)
    prepare_local_inputs.main([str(manifest), str(local_state)])
    command = seen["cmd"]
    assert command[:2] == ["/bin/bash", "-lc"]
    assert "kvm_local_prep_lib.sh" in command[2]
    assert seen["env"]["MANIFEST_PATH"] == str(manifest.resolve())
    assert seen["env"]["LOCAL_STATE_PATH"] == str(local_state.resolve())


def test_prepare_local_inputs_requires_remote_state_for_aws(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    manifest.write_text(
        "RUN_EXECUTOR=aws-ssh\n"
        "RUN_SUITE_NAME=test\n"
        "RUN_HOST_PYTHON_BIN=python3\n",
        encoding="utf-8",
    )

    with pytest.raises(SystemExit) as excinfo:
        prepare_local_inputs.main([str(manifest), str(local_state)])

    assert excinfo.value.code == 1
