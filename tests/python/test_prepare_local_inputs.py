from __future__ import annotations

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

    def fake_kvm_local_prep(*, manifest_path: Path, local_state_path: Path, env: dict[str, str], phases: list[str]) -> None:
        seen["manifest_path"] = manifest_path
        seen["local_state_path"] = local_state_path
        seen["env"] = env
        seen["phases"] = phases

    monkeypatch.setattr(prepare_local_inputs, "run_kvm_local_prep", fake_kvm_local_prep)
    prepare_local_inputs.main([str(manifest), str(local_state)])
    assert seen["manifest_path"] == manifest.resolve()
    assert seen["local_state_path"] == local_state.resolve()
    assert seen["env"]["MANIFEST_PATH"] == str(manifest.resolve())
    assert seen["env"]["LOCAL_STATE_PATH"] == str(local_state.resolve())
    assert seen["phases"] == ["base", "runtime", "test_outputs", "upstream_selftests"]


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


def test_prepare_local_inputs_dispatches_aws_without_base_phase(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    remote_state = tmp_path / "remote-state.json"
    remote_state.write_text('{\n  "STATE_INSTANCE_IP": "127.0.0.1"\n}\n', encoding="utf-8")
    manifest.write_text(
        "RUN_EXECUTOR=aws-ssh\n"
        "RUN_SUITE_NAME=test\n"
        "RUN_TARGET_ARCH=x86_64\n"
        "RUN_HOST_PYTHON_BIN=python3\n",
        encoding="utf-8",
    )
    seen: dict[str, object] = {}

    def fake_aws_local_prep(
        *,
        manifest_path: Path,
        local_state_path: Path,
        remote_prep_state_path: Path,
        env: dict[str, str],
        phases: list[str],
    ) -> None:
        seen["manifest_path"] = manifest_path
        seen["local_state_path"] = local_state_path
        seen["remote_prep_state_path"] = remote_prep_state_path
        seen["env"] = env
        seen["phases"] = phases

    monkeypatch.setattr(prepare_local_inputs, "run_aws_local_prep", fake_aws_local_prep)
    prepare_local_inputs.main([str(manifest), str(local_state), str(remote_state)])

    assert seen["manifest_path"] == manifest.resolve()
    assert seen["local_state_path"] == local_state.resolve()
    assert seen["remote_prep_state_path"] == remote_state.resolve()
    assert seen["env"]["MANIFEST_PATH"] == str(manifest.resolve())
    assert seen["env"]["LOCAL_STATE_PATH"] == str(local_state.resolve())
    assert seen["phases"] == ["runtime", "test_outputs", "upstream_selftests"]
