from __future__ import annotations

import os
from pathlib import Path

from runner.libs.run_contract import (
    build_manifest,
    build_target_manifest,
    load_manifest_environment,
    main as run_contract_main,
    parse_manifest,
    render_null_assignments,
    render_shell_assignments,
    write_manifest_file,
)


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


def test_load_manifest_environment_sets_shell_joined_array(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "RUN_TARGET_NAME=aws-x86\n"
        "RUN_E2E_ARGV=( --case tracee '--flag=quoted value' )\n",
        encoding="utf-8",
    )
    monkeypatch.delenv("RUN_E2E_ARGV", raising=False)
    load_manifest_environment(manifest)
    assert os.environ["RUN_TARGET_NAME"] == "aws-x86"
    assert os.environ["RUN_E2E_ARGV"] == "--case tracee '--flag=quoted value'"


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


def test_test_manifest_includes_upstream_test_progs_selection_contract() -> None:
    manifest = build_manifest(
        "x86-kvm",
        "test",
        env={"BZIMAGE": "/tmp/bzImage"},
    )
    assert manifest["RUN_UPSTREAM_TEST_PROGS_FILTERS"] == "verifier,jit"
    assert manifest["RUN_UPSTREAM_TEST_PROGS_DENY"] == "verifier_private_stack"
