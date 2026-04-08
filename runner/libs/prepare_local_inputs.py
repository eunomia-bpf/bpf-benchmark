from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import load_manifest_environment


def _die(message: str) -> "NoReturn":
    print(f"[prepare-local-inputs][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _run_shell_action(script: str, *, env: dict[str, str]) -> None:
    completed = subprocess.run(
        ["/bin/bash", "-lc", script],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _kvm_local_prep_script() -> str:
    return """
set -euo pipefail
die() {
    printf '[prepare-local-inputs][ERROR] %s\n' "$*" >&2
    exit 1
}
source "$ROOT_DIR/runner/scripts/kvm_local_prep_lib.sh"
kvm_prepare_local_action
"""


def _aws_local_prep_script() -> str:
    return """
set -euo pipefail
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_local_prep_lib.sh"
aws_prepare_local_action
"""


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {1, 2}:
        _die("usage: prepare_local_inputs.py <manifest_path> [remote_prep_state_path]")
    manifest_path = Path(args[0]).resolve()
    remote_prep_state_path = Path(args[1]).resolve() if len(args) == 2 and args[1] else None
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    load_manifest_environment(manifest_path)
    env = os.environ.copy()
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["MANIFEST_PATH"] = str(manifest_path)
    host_python_bin = env.get("RUN_HOST_PYTHON_BIN", "").strip()
    if not host_python_bin:
        _die("manifest host python is missing")
    env["HOST_PYTHON_BIN"] = host_python_bin

    executor = env.get("RUN_EXECUTOR", "").strip()
    if executor == "kvm":
        _run_shell_action(_kvm_local_prep_script(), env=env)
        return
    if executor == "aws-ssh":
        if remote_prep_state_path is None:
            _die("AWS local prep requires an explicit remote-prep state path")
        if not remote_prep_state_path.is_file():
            _die(f"AWS remote-prep state is missing: {remote_prep_state_path}")
        env["ACTION"] = "run"
        env["AWS_REMOTE_PREP_STATE_PATH"] = str(remote_prep_state_path)
        _run_shell_action(_aws_local_prep_script(), env=env)
        return
    _die(f"unsupported executor for local prep: {executor}")


if __name__ == "__main__":
    main()
