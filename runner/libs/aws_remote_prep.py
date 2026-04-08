from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import load_manifest_environment


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
load_state
printf 'STATE_INSTANCE_ID=%q\n' "${STATE_INSTANCE_ID:-}"
printf 'STATE_INSTANCE_IP=%q\n' "${STATE_INSTANCE_IP:-}"
printf 'STATE_REGION=%q\n' "${STATE_REGION:-}"
printf 'STATE_KERNEL_RELEASE=%q\n' "${STATE_KERNEL_RELEASE:-}"
"""


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 1:
        _die("usage: aws_remote_prep.py <manifest_path>")
    manifest_path = Path(args[0]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    load_manifest_environment(manifest_path)
    env = os.environ.copy()
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["ACTION"] = "run"
    env["MANIFEST_PATH"] = str(manifest_path)
    completed = subprocess.run(
        ["/bin/bash", "-lc", _shell_script()],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
