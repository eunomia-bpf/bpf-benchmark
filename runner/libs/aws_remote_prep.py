from __future__ import annotations

import os
import shlex
import subprocess
import sys
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import parse_manifest
from runner.libs.state_file import read_state, write_state


def _die(message: str) -> "NoReturn":
    print(f"[aws-remote-prep][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _shell_script() -> str:
    return """
set -euo pipefail
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_kernel_artifacts_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_remote_prep_lib.sh"
with_state_lock ensure_instance_for_suite
"""


def _base_env_from_contract(contract: dict[str, str | list[str]]) -> dict[str, str]:
    env: dict[str, str] = {}
    for name in ("PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL"):
        value = os.environ.get(name, "").strip()
        if value:
            env[name] = value
    for name, value in contract.items():
        env[name] = shlex.join(value) if isinstance(value, list) else value
    return env


def _state_file_path(contract: dict[str, str | list[str]]) -> Path:
    target_name = str(contract.get("RUN_TARGET_NAME", "")).strip()
    run_token = str(contract.get("RUN_TOKEN", "")).strip()
    instance_mode = str(contract.get("RUN_AWS_INSTANCE_MODE", "shared")).strip() or "shared"
    if not target_name:
        _die("manifest RUN_TARGET_NAME is empty")
    if not run_token:
        _die("manifest RUN_TOKEN is empty")
    target_cache_dir = ROOT_DIR / ".cache" / target_name
    if instance_mode == "dedicated":
        return target_cache_dir / "run-state" / run_token / "instance.json"
    return target_cache_dir / "state" / "instance.json"


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 2:
        _die("usage: aws_remote_prep.py <manifest_path> <state_path>")
    manifest_path = Path(args[0]).resolve()
    state_path = Path(args[1]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    contract = parse_manifest(manifest_path)
    env = _base_env_from_contract(contract)
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["PYTHONPATH"] = f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}"
    env["RUN_CONTRACT_PYTHON_BIN"] = sys.executable
    env["ACTION"] = "run"
    env["MANIFEST_PATH"] = str(manifest_path)
    env.pop("AWS_REMOTE_PREP_STATE_PATH", None)
    completed = subprocess.run(
        ["/bin/bash", "-lc", _shell_script()],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    state = read_state(_state_file_path(contract))
    write_state(
        state_path,
        {
            "STATE_INSTANCE_ID": state.get("STATE_INSTANCE_ID", ""),
            "STATE_INSTANCE_IP": state.get("STATE_INSTANCE_IP", ""),
            "STATE_REGION": state.get("STATE_REGION", ""),
            "STATE_KERNEL_RELEASE": state.get("STATE_KERNEL_RELEASE", ""),
        },
    )


if __name__ == "__main__":
    main()
