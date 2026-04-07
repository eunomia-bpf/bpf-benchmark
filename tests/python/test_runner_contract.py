from __future__ import annotations

import os
from pathlib import Path
import subprocess
import sys


ROOT_DIR = Path(__file__).resolve().parents[2]


def _run_bash(script: str, *, env: dict[str, str] | None = None) -> subprocess.CompletedProcess[str]:
    merged_env = os.environ.copy()
    if env:
        merged_env.update(env)
    return subprocess.run(
        ["/bin/bash", "-lc", script],
        cwd=ROOT_DIR,
        env=merged_env,
        text=True,
        capture_output=True,
        check=True,
    )


def test_run_contract_uses_explicit_repo_selection_fields() -> None:
    env = {
        "AWS_X86_REGION": "us-east-1",
        "AWS_X86_PROFILE": "test-profile",
        "AWS_X86_KEY_NAME": "test-key",
        "AWS_X86_KEY_PATH": "/tmp/test-key.pem",
        "AWS_X86_SECURITY_GROUP_ID": "sg-12345678",
        "AWS_X86_SUBNET_ID": "subnet-12345678",
    }
    script = """
source runner/scripts/load_run_contract.sh
manifest="$(mktemp)"
run_contract_write_manifest aws-x86 e2e "$manifest"
cat "$manifest"
rm -f "$manifest"
"""
    completed = _run_bash(script, env=env)
    manifest = completed.stdout
    assert "RUN_BUNDLED_REPOS_CSV=" in manifest
    assert "RUN_FETCH_REPOS_CSV=" in manifest
    assert "RUN_BENCHMARK_REPOS_CSV=" not in manifest


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
                "RUN_REMOTE_WORKLOAD_TOOL_ROOT=.cache/workload-tools",
                "RUN_REMOTE_WORKLOAD_TOOL_BIN=.cache/workload-tools/bin",
                "",
            ]
        ),
        encoding="utf-8",
    )

    subprocess.run(
        [
            "/bin/bash",
            "runner/scripts/validate_guest_prereqs.sh",
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
            "/bin/bash",
            "runner/scripts/validate_guest_prereqs.sh",
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
