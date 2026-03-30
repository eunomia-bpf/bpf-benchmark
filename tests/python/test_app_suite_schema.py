from __future__ import annotations

import sys
from pathlib import Path

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.app_suite_schema import load_app_suite_from_yaml


def test_load_app_suite_from_yaml_supports_shared_workload_schema_and_top_level_args(tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "defaults": {"samples": 200, "duration_s": 10},
                "apps": [
                    {
                        "name": "bcc/execsnoop",
                        "runner": "bcc",
                        "tool": "execsnoop",
                        "workload": {
                            "corpus": "exec_storm",
                            "e2e": "exec_storm",
                        },
                    },
                    {
                        "name": "katran",
                        "runner": "katran",
                        "workload": {
                            "corpus": "test_run",
                            "e2e": "network",
                        },
                    },
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )

    suite, summary = load_app_suite_from_yaml(manifest_path)

    assert summary["selected_apps"] == 2
    assert suite.defaults["samples"] == 200
    assert suite.apps[0].args == {"tool": "execsnoop"}
    assert suite.apps[0].workload_for("corpus") == "exec_storm"
    assert suite.apps[1].workload_for("corpus") == "test_run"
    assert suite.apps[1].workload_for("e2e") == "network"


def test_load_app_suite_from_yaml_rejects_legacy_string_workload(tmp_path: Path) -> None:
    manifest_path = tmp_path / "macro_apps.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 1,
                "apps": [
                    {
                        "name": "tracee",
                        "runner": "tracee",
                        "workload": "exec_storm",
                    }
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )

    with pytest.raises(SystemExit, match="must be a mapping with corpus/e2e keys"):
        load_app_suite_from_yaml(manifest_path)
