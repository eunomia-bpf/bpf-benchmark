from __future__ import annotations

from runner.libs.aws_remote_prep import REMOTE_PREREQ_ASSETS


def test_remote_prereq_assets_include_manifest_parser_and_exclude_run_contract() -> None:
    assets = {src for src, _dest in REMOTE_PREREQ_ASSETS}
    assert "runner/libs/manifest_file.py" in assets
    assert "runner/libs/run_contract.py" not in assets
