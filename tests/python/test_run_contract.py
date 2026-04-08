from __future__ import annotations

import os
from pathlib import Path

from runner.libs.run_contract import load_manifest_environment, parse_manifest


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
