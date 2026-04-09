from __future__ import annotations

import subprocess
from pathlib import Path

import pytest

from runner.libs.manifest_file import (
    parse_manifest,
    render_null_assignments,
    render_shell_assignments,
)
from runner.libs.prereq_contract import tool_packages
from runner.libs.run_contract import (
    _filtered_manifest_inputs,
    build_manifest,
    build_target_manifest,
    main as run_contract_main,
    write_manifest_file,
)
from runner.libs.state_file import read_state

ROOT_DIR = Path(__file__).resolve().parents[2]


def test_dnf_tc_contract_installs_iproute_tc() -> None:
    assert tool_packages("dnf", "tc") == ("iproute-tc",)


def test_parse_manifest_reads_scalars_and_arrays(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "RUN_TARGET_NAME=aws-x86\n"
        "RUN_REMOTE_PYTHON_BIN=python3.11\n"
        "RUN_CORPUS_ARGV=( --foo 'bar baz' )\n",
        encoding="utf-8",
    )
    parsed = parse_manifest(manifest)
    assert parsed["RUN_TARGET_NAME"] == "aws-x86"
    assert parsed["RUN_REMOTE_PYTHON_BIN"] == "python3.11"
    assert parsed["RUN_CORPUS_ARGV"] == ["--foo", "bar baz"]


def test_render_shell_assignments_preserves_scalars_and_arrays(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "RUN_TARGET_NAME=aws-x86\n"
        "RUN_CORPUS_ARGV=( --foo 'bar baz' )\n",
        encoding="utf-8",
    )
    rendered = render_shell_assignments(manifest)
    assert "RUN_TARGET_NAME=aws-x86" in rendered
    assert "RUN_CORPUS_ARGV=( --foo 'bar baz' )" in rendered


def test_run_contract_export_cli_prints_shell_assignments(capsys, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text("RUN_TARGET_NAME=aws-x86\n", encoding="utf-8")
    run_contract_main(["export", str(manifest)])
    assert capsys.readouterr().out.strip() == "RUN_TARGET_NAME=aws-x86"


def test_render_null_assignments_preserves_scalars_and_arrays(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "RUN_TARGET_NAME=aws-x86\n"
        "RUN_CORPUS_ARGV=( --foo 'bar baz' )\n",
        encoding="utf-8",
    )
    rendered = render_null_assignments(manifest)
    assert rendered == b"RUN_TARGET_NAME=aws-x86\0RUN_CORPUS_ARGV=--foo 'bar baz'\0"


def test_read_state_rejects_empty_file(tmp_path: Path) -> None:
    state = tmp_path / "state.json"
    state.write_text("", encoding="utf-8")
    with pytest.raises(SystemExit) as excinfo:
        read_state(state)
    assert excinfo.value.code == 1


def test_manifest_writer_emits_explicit_run_token(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    env = {
        "AWS_X86_REGION": "us-east-1",
        "AWS_X86_PROFILE": "test-profile",
        "AWS_X86_KEY_NAME": "test-key",
        "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
        "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
        "AWS_X86_SUBNET_ID": "subnet-12345678",
        "RUN_TOKEN": "explicit-token",
    }
    write_manifest_file(manifest, build_manifest("aws-x86", "test", env=env))
    assert "RUN_TOKEN=explicit-token" in manifest.read_text(encoding="utf-8")


def test_target_manifest_writer_resolves_aws_identity_contract() -> None:
    manifest = build_target_manifest(
        "aws-x86",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
        },
    )
    assert manifest["RUN_TARGET_NAME"] == "aws-x86"
    assert manifest["RUN_AWS_REGION"] == "us-east-1"
    assert manifest["RUN_AWS_PROFILE"] == "test-profile"
    assert manifest["RUN_GUEST_PACKAGE_MANAGER"] == "dnf"


def test_filtered_manifest_inputs_keep_only_target_relevant_keys() -> None:
    filtered = _filtered_manifest_inputs(
        "aws-x86",
        {
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "UNRELATED_FLAG": "keep-me-out",
            "PYTHON": "python3",
        },
    )
    assert filtered["AWS_X86_REGION"] == "us-east-1"
    assert filtered["AWS_X86_PROFILE"] == "test-profile"
    assert filtered["AWS_X86_KEY_NAME"] == "test-key"
    assert filtered["PYTHON"] == "python3"
    assert "UNRELATED_FLAG" not in filtered


def test_filtered_manifest_inputs_do_not_read_local_config_side_plane(tmp_path: Path) -> None:
    filtered = _filtered_manifest_inputs(
        "aws-x86",
        {
            "PYTHON": "python3",
        },
    )

    assert filtered == {"PYTHON": "python3"}


def test_test_manifest_includes_upstream_test_progs_selection_contract() -> None:
    manifest = build_manifest(
        "x86-kvm",
        "test",
        env={"BZIMAGE": "/tmp/bzImage"},
    )
    assert manifest["RUN_UPSTREAM_TEST_PROGS_FILTERS"] == "verifier,jit"
    assert manifest["RUN_UPSTREAM_TEST_PROGS_DENY"] == "verifier_private_stack"


def test_test_manifest_adds_scx_repo_to_fetch_repos() -> None:
    manifest = build_manifest(
        "x86-kvm",
        "test",
        env={"BZIMAGE": "/tmp/bzImage"},
    )
    assert manifest["RUN_SCX_PACKAGES_CSV"] == "scx_rusty"
    assert manifest["RUN_FETCH_REPOS_CSV"] == "scx"


def test_micro_manifest_requires_explicit_llvm_contract() -> None:
    with pytest.raises(SystemExit) as excinfo:
        build_manifest("x86-kvm", "micro", env={"BZIMAGE": "/tmp/bzImage"})
    assert excinfo.value.code == 1


def test_micro_manifest_records_explicit_llvm_dir(tmp_path: Path) -> None:
    llvm_dir = tmp_path / "llvm" / "lib" / "cmake" / "llvm"
    llvm_dir.mkdir(parents=True)
    manifest = build_manifest(
        "x86-kvm",
        "micro",
        env={"BZIMAGE": "/tmp/bzImage", "LLVM_DIR": str(llvm_dir)},
    )
    assert manifest["RUN_LLVM_DIR"] == str(llvm_dir.resolve())


def test_e2e_manifest_enables_katran_bundle_for_default_all_cases() -> None:
    manifest = build_manifest(
        "aws-x86",
        "e2e",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
        },
    )
    assert manifest["RUN_E2E_CASES"] == "all"
    assert manifest["RUN_NEEDS_KATRAN_BUNDLE"] == "1"


def test_corpus_filters_prune_unrelated_runner_prep_contracts() -> None:
    manifest = build_manifest(
        "aws-x86",
        "corpus",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
            "AWS_X86_CORPUS_FILTERS": "bcc/",
        },
    )
    assert manifest["RUN_CORPUS_FILTERS"] == "bcc/"
    assert manifest["RUN_BUNDLED_REPOS_CSV"] == "bcc"
    assert manifest["RUN_NATIVE_REPOS_CSV"] == "bcc"
    assert manifest["RUN_FETCH_REPOS_CSV"] == "bcc"
    assert manifest["RUN_SCX_PACKAGES_CSV"] == ""
    assert manifest["RUN_SUITE_NEEDS_SCHED_EXT"] == "0"
    assert manifest["RUN_NEEDS_KATRAN_BUNDLE"] == "0"
    assert manifest["RUN_REMOTE_COMMANDS_CSV"] == "curl,file,ip,tar,taskset"
    assert manifest["RUN_WORKLOAD_TOOLS_CSV"] == "stress-ng,fio,hackbench,wrk"


def test_corpus_filters_keep_katran_bundle_when_selected() -> None:
    manifest = build_manifest(
        "aws-x86",
        "corpus",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
            "AWS_X86_CORPUS_FILTERS": "katran",
        },
    )
    assert manifest["RUN_BUNDLED_REPOS_CSV"] == "katran"
    assert manifest["RUN_NATIVE_REPOS_CSV"] == "katran"
    assert manifest["RUN_FETCH_REPOS_CSV"] == "katran"
    assert manifest["RUN_NEEDS_KATRAN_BUNDLE"] == "1"


def test_e2e_case_selection_prunes_irrelevant_workload_tools_and_remote_commands() -> None:
    manifest = build_manifest(
        "aws-x86",
        "e2e",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
            "AWS_X86_E2E_CASES": "scx",
        },
    )
    assert manifest["RUN_BUNDLED_REPOS_CSV"] == "scx"
    assert manifest["RUN_NATIVE_REPOS_CSV"] == ""
    assert manifest["RUN_FETCH_REPOS_CSV"] == "scx"
    assert manifest["RUN_SCX_PACKAGES_CSV"] == "scx_rusty"
    assert manifest["RUN_SUITE_NEEDS_SCHED_EXT"] == "1"
    assert manifest["RUN_WORKLOAD_TOOLS_CSV"] == "stress-ng,hackbench,sysbench"
    assert manifest["RUN_REMOTE_COMMANDS_CSV"] == "ip,taskset"


def test_e2e_bpftrace_case_keeps_curl_and_tc_workload_tools() -> None:
    manifest = build_manifest(
        "aws-x86",
        "e2e",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
            "AWS_X86_E2E_CASES": "bpftrace",
        },
    )
    assert manifest["RUN_REMOTE_COMMANDS_CSV"] == "ip,taskset"
    assert manifest["RUN_WORKLOAD_TOOLS_CSV"] == "stress-ng,fio,hackbench,bpftrace,wrk,tc"


def test_e2e_tracee_case_does_not_require_wrk_by_default() -> None:
    manifest = build_manifest(
        "aws-x86",
        "e2e",
        env={
            "AWS_X86_REGION": "us-east-1",
            "AWS_X86_PROFILE": "test-profile",
            "AWS_X86_KEY_NAME": "test-key",
            "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
            "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
            "AWS_X86_SUBNET_ID": "subnet-12345678",
            "AWS_X86_E2E_CASES": "tracee",
        },
    )
    assert manifest["RUN_WORKLOAD_TOOLS_CSV"] == ""
    assert manifest["RUN_REMOTE_COMMANDS_CSV"] == "ip,taskset,curl"


def test_install_guest_prereqs_brings_up_loopback_when_ip_is_available(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    from runner.libs import guest_prereqs

    workspace = tmp_path / "workspace"
    workspace.mkdir()
    commands: list[list[str]] = []

    monkeypatch.setattr(guest_prereqs, "have_cmd", lambda command_name, *, path_value=None: True)
    monkeypatch.setattr(
        guest_prereqs,
        "python_module_available",
        lambda python_bin, import_name, *, path_value: True,
    )
    monkeypatch.setattr(
        guest_prereqs,
        "run_command",
        lambda command, *, path_value, sudo=False, quiet=False: commands.append(list(command)),
    )

    guest_prereqs.install_guest_prereqs(
        workspace,
        {
            "RUN_BPFTOOL_BIN": "true",
            "RUN_REMOTE_PYTHON_BIN": "python3",
            "RUN_REMOTE_COMMANDS_CSV": "ip",
            "RUN_WORKLOAD_TOOLS_CSV": "",
            "RUN_BUNDLED_WORKLOAD_TOOLS_CSV": "",
            "RUN_REMOTE_PYTHON_MODULES_CSV": "",
            "RUN_GUEST_PACKAGE_MANAGER": "dnf",
        },
    )

    assert commands == [["ip", "link", "set", "lo", "up"]]


def test_runtime_path_value_includes_standard_sbin_dirs(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    from runner.libs.guest_prereqs import runtime_path_value

    monkeypatch.setenv("PATH", "/usr/bin:/bin")
    workspace = tmp_path / "workspace"
    workspace.mkdir()

    path_value = runtime_path_value(workspace, {})

    assert "/usr/sbin" in path_value.split(":")
    assert "/sbin" in path_value.split(":")


def test_validate_guest_prereqs_accepts_bundled_workload_tools(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    tool_bin = workspace / ".cache" / "workload-tools" / "bin"
    tool_bin.mkdir(parents=True)
    bundled_tool = tool_bin / "wrk"
    bundled_tool.write_text("#!/usr/bin/env bash\nexit 0\n", encoding="utf-8")
    bundled_tool.chmod(0o755)

    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_BPFTOOL_BIN=true",
                "RUN_REMOTE_PYTHON_BIN=python3",
                "RUN_REMOTE_COMMANDS_CSV=",
                "RUN_WORKLOAD_TOOLS_CSV=wrk",
                "RUN_BUNDLED_WORKLOAD_TOOLS_CSV=wrk",
                "RUN_REMOTE_WORKLOAD_TOOL_BIN=.cache/workload-tools/bin",
                "",
            ]
        ),
        encoding="utf-8",
    )

    subprocess.run(
        [
            "python3",
            "-m",
            "runner.libs.guest_prereqs",
            "validate",
            str(workspace),
            str(manifest),
        ],
        cwd=ROOT_DIR,
        check=True,
        capture_output=True,
        text=True,
    )


def test_validate_guest_prereqs_requires_explicit_remote_tool_bin(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_BPFTOOL_BIN=true",
                "RUN_REMOTE_PYTHON_BIN=python3",
                "RUN_REMOTE_COMMANDS_CSV=",
                "RUN_WORKLOAD_TOOLS_CSV=wrk",
                "RUN_BUNDLED_WORKLOAD_TOOLS_CSV=",
                "",
            ]
        ),
        encoding="utf-8",
    )

    completed = subprocess.run(
        [
            "python3",
            "-m",
            "runner.libs.guest_prereqs",
            "validate",
            str(workspace),
            str(manifest),
        ],
        cwd=ROOT_DIR,
        check=False,
        capture_output=True,
        text=True,
    )

    assert completed.returncode == 0
