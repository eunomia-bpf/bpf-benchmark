from __future__ import annotations

from pathlib import Path

import pytest

from runner.libs import aws_local_prep, execute_workspace, local_prep_common, prepare_local_inputs

ROOT_DIR = Path(__file__).resolve().parents[2]


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


def test_prepare_local_inputs_test_suite_fetches_repos_before_scx(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    manifest.write_text(
        "RUN_EXECUTOR=kvm\n"
        "RUN_SUITE_NAME=test\n"
        "RUN_HOST_PYTHON_BIN=python3\n"
        "RUN_FETCH_REPOS_CSV=scx\n"
        "RUN_SCX_PACKAGES_CSV=scx_rusty\n",
        encoding="utf-8",
    )
    seen: dict[str, object] = {}

    def fake_kvm_local_prep(*, manifest_path: Path, local_state_path: Path, env: dict[str, str], phases: list[str]) -> None:
        seen["phases"] = phases

    monkeypatch.setattr(prepare_local_inputs, "run_kvm_local_prep", fake_kvm_local_prep)
    prepare_local_inputs.main([str(manifest), str(local_state)])

    assert seen["phases"] == ["base", "runtime", "test_outputs", "upstream_selftests", "fetch_repos", "scx"]


def test_execute_workspace_runs_install_validate_then_suite(monkeypatch, tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    manifest = tmp_path / "run-contract.env"
    manifest.write_text("RUN_TARGET_NAME=x86-kvm\nRUN_SUITE_NAME=test\n", encoding="utf-8")

    calls: list[str] = []

    def fake_parse_manifest(path: Path) -> dict[str, str]:
        calls.append(f"parse:{path.name}")
        return {"RUN_TARGET_NAME": "x86-kvm", "RUN_SUITE_NAME": "test"}

    def fake_install_guest_prereqs(path: Path, contract: dict[str, str]) -> None:
        calls.append(f"install:{path.name}:{contract['RUN_SUITE_NAME']}")

    def fake_validate_guest_prereqs(path: Path, contract: dict[str, str]) -> None:
        calls.append(f"validate:{path.name}:{contract['RUN_TARGET_NAME']}")

    class FakeSuite:
        def run(self) -> None:
            calls.append("run")

    def fake_from_contract(
        workspace_path: Path,
        manifest_path: Path,
        archive_path: Path | None,
        contract: dict[str, str],
    ) -> FakeSuite:
        calls.append(f"contract:{workspace_path.name}:{manifest_path.name}:{archive_path}")
        assert contract["RUN_TARGET_NAME"] == "x86-kvm"
        return FakeSuite()

    monkeypatch.setattr(execute_workspace, "parse_manifest", fake_parse_manifest)
    monkeypatch.setattr(execute_workspace, "install_guest_prereqs", fake_install_guest_prereqs)
    monkeypatch.setattr(execute_workspace, "validate_guest_prereqs", fake_validate_guest_prereqs)
    monkeypatch.setattr(execute_workspace.SuiteEntrypoint, "from_contract", staticmethod(fake_from_contract))

    execute_workspace.main([str(workspace), str(manifest)])

    assert calls == [
        "parse:run-contract.env",
        "install:workspace:test",
        "validate:workspace:x86-kvm",
        "contract:workspace:run-contract.env:None",
        "run",
    ]


def test_x86_bundle_inputs_use_native_katran_stage_root(tmp_path: Path) -> None:
    promote_root = tmp_path / "bundle-inputs"
    test_artifacts_root = promote_root / "test-artifacts"
    repo_root = promote_root / "runner" / "repos"

    values = local_prep_common.x86_bundle_inputs(
        promote_root=promote_root,
        local_repo_root=repo_root,
        test_artifacts_root=test_artifacts_root,
    )

    assert values["RUN_KATRAN_SERVER_BINARY"] == str(promote_root / "corpus" / "build" / "katran" / "bin" / "katran_server_grpc")
    assert values["RUN_KATRAN_SERVER_LIB_DIR"] == str(promote_root / "corpus" / "build" / "katran" / "lib")


def test_aws_arm64_container_build_uses_container_python_and_llvmbpf_env(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    remote_state = tmp_path / "remote-state.json"
    remote_state.write_text("{}\n", encoding="utf-8")

    prep = aws_local_prep.AWSPrep(
        env={
            "RUN_TOKEN": "run.aws-arm64.corpus.test",
            "RUN_TARGET_NAME": "aws-arm64",
            "RUN_TARGET_ARCH": "arm64",
            "RUN_HOST_PYTHON_BIN": str(tmp_path / ".venv" / "bin" / "python3"),
        },
        manifest_path=manifest,
        local_state_path=local_state,
        remote_prep_state_path=remote_state,
    )

    seen: dict[str, object] = {}

    monkeypatch.setattr(prep, "_ensure_arm64_crossbuild_image", lambda: None)

    def fake_run_command(command: list[str], *, env: dict[str, str], cwd: Path = ROOT_DIR) -> None:
        seen["command"] = command
        seen["env"] = env

    monkeypatch.setattr(aws_local_prep, "run_command", fake_run_command)

    prep._run_arm64_container_build(runtime_targets_csv="runner", llvmbpf_setting="ON", bench_repos_csv="bcc")

    command = seen["command"]
    assert "ARM64_HOST_PYTHON_BIN=python3" in command
    assert f"ARM64_HOST_PYTHON_BIN={prep.host_python_bin}" not in command
    assert "MICRO_EXEC_ENABLE_LLVMBPF=ON" in command
