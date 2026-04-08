from __future__ import annotations

import subprocess
from pathlib import Path

from runner.libs.run_contract import (
    _filtered_manifest_inputs,
    build_manifest,
    build_target_manifest,
    main as run_contract_main,
    parse_manifest,
    render_null_assignments,
    render_shell_assignments,
    write_manifest_file,
)

ROOT_DIR = Path(__file__).resolve().parents[2]


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


def test_test_manifest_includes_upstream_test_progs_selection_contract() -> None:
    manifest = build_manifest(
        "x86-kvm",
        "test",
        env={"BZIMAGE": "/tmp/bzImage"},
    )
    assert manifest["RUN_UPSTREAM_TEST_PROGS_FILTERS"] == "verifier,jit"
    assert manifest["RUN_UPSTREAM_TEST_PROGS_DENY"] == "verifier_private_stack"


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

    assert completed.returncode != 0
    assert "manifest remote workload-tool bin is missing" in completed.stderr
