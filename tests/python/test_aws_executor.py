from __future__ import annotations

import json
from pathlib import Path

import pytest

from runner.libs import aws_executor


def _write_manifest(path: Path, lines: list[str]) -> None:
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def test_build_context_uses_shared_and_dedicated_state_dirs(tmp_path: Path) -> None:
    shared_manifest = tmp_path / "shared.env"
    _write_manifest(
        shared_manifest,
        [
            "RUN_TARGET_NAME=aws-x86",
            "RUN_TOKEN=run.shared.test",
            "RUN_AWS_INSTANCE_MODE=shared",
            "RUN_AWS_REGION=us-east-1",
            "RUN_AWS_PROFILE=test-profile",
            "RUN_AWS_KEY_PATH=/tmp/test-key.pem",
        ],
    )
    dedicated_manifest = tmp_path / "dedicated.env"
    _write_manifest(
        dedicated_manifest,
        [
            "RUN_TARGET_NAME=aws-arm64",
            "RUN_TOKEN=run.dedicated.test",
            "RUN_AWS_INSTANCE_MODE=dedicated",
            "RUN_AWS_REGION=us-east-1",
            "RUN_AWS_PROFILE=test-profile",
            "RUN_AWS_KEY_PATH=/tmp/test-key.pem",
        ],
    )

    shared_ctx = aws_executor._build_context("run", shared_manifest, None)
    dedicated_ctx = aws_executor._build_context("run", dedicated_manifest, None)

    assert shared_ctx.state_dir == shared_ctx.shared_state_dir
    assert dedicated_ctx.state_dir == dedicated_ctx.run_state_dir


def test_run_action_requires_remote_contract_and_bundle_state(tmp_path: Path) -> None:
    manifest = tmp_path / "manifest.env"
    _write_manifest(
        manifest,
        [
            "RUN_TARGET_NAME=aws-x86",
            "RUN_TOKEN=run.aws-x86.test",
            "RUN_SUITE_NAME=test",
            "RUN_AWS_INSTANCE_MODE=shared",
            "RUN_AWS_REGION=us-east-1",
            "RUN_AWS_PROFILE=test-profile",
            "RUN_AWS_KEY_PATH=/tmp/test-key.pem",
        ],
    )
    local_state = tmp_path / "local-state.json"
    local_state.write_text(json.dumps({"RUN_BUNDLE_TAR": "/tmp/missing-bundle.tar.gz"}) + "\n", encoding="utf-8")

    ctx = aws_executor._build_context("run", manifest, local_state)

    with pytest.raises(SystemExit):
        aws_executor._run_action(ctx)
