from __future__ import annotations

import os
import re
import secrets
import subprocess
import sys
import tempfile
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import build_manifest, build_target_manifest, parse_manifest, write_manifest_file


CACHE_DIR = ROOT_DIR / ".cache" / "runner-contracts"


def _die(message: str) -> "NoReturn":
    print(f"[run-target-suite][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _run_checked(command: list[str]) -> None:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _python_module_command(module: str, *args: str) -> list[str]:
    return [sys.executable, "-m", module, *args]

def _write_manifest(target_name: str, suite_name: str, run_token: str, manifest_path: Path) -> None:
    env = os.environ.copy()
    env["RUN_TOKEN"] = run_token
    write_manifest_file(manifest_path, build_manifest(target_name, suite_name, env=env))


def _write_target_manifest(target_name: str, manifest_path: Path) -> None:
    write_manifest_file(manifest_path, build_target_manifest(target_name, env=os.environ.copy()))


def _cleanup_failed_dedicated_aws_prep(manifest_path: Path) -> None:
    env = os.environ.copy()
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["ACTION"] = "run"
    env["MANIFEST_PATH"] = str(manifest_path)
    script = """
set -euo pipefail
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
[[ "${RUN_AWS_INSTANCE_MODE:-shared}" == "dedicated" ]] || exit 0
load_state
if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
    terminate_instance "${STATE_INSTANCE_ID}" || true
fi
rm -rf "$RUN_STATE_DIR"
"""
    subprocess.run(
        ["/bin/bash", "-lc", script],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )


def _temp_env_path(prefix: str) -> Path:
    CACHE_DIR.mkdir(parents=True, exist_ok=True)
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix=prefix,
        suffix=".env",
        dir=CACHE_DIR,
        delete=False,
    )
    handle.close()
    return Path(handle.name)


def _temp_json_path(prefix: str) -> Path:
    CACHE_DIR.mkdir(parents=True, exist_ok=True)
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix=prefix,
        suffix=".json",
        dir=CACHE_DIR,
        delete=False,
    )
    handle.close()
    return Path(handle.name)


def _run_token(target_name: str, suite_name: str) -> str:
    token = f"run.{target_name}.{suite_name}.{secrets.token_hex(4)}"
    return re.sub(r"[^0-9A-Za-z._-]+", "_", token)


def _run_action(target_name: str, suite_name: str) -> None:
    run_token = _run_token(target_name, suite_name)
    manifest_path = _temp_env_path(f"manifest.{run_token}.")
    local_state_path = _temp_json_path(f"local-state.{run_token}.")
    remote_prep_state_path = _temp_json_path(f"remote-state.{run_token}.")
    prep_cleanup_armed = False
    try:
        _write_manifest(target_name, suite_name, run_token, manifest_path)
        contract = parse_manifest(manifest_path)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor == "aws-ssh":
            if str(contract.get("RUN_AWS_INSTANCE_MODE", "shared")) == "dedicated":
                prep_cleanup_armed = True
            _run_checked(
                _python_module_command(
                    "runner.libs.aws_remote_prep",
                    str(manifest_path),
                    str(remote_prep_state_path),
                ),
            )
            _run_checked(
                _python_module_command(
                    "runner.libs.prepare_local_inputs",
                    str(manifest_path),
                    str(local_state_path),
                    str(remote_prep_state_path),
                ),
            )
            prep_cleanup_armed = False
            _run_checked(
                _python_module_command(
                    "runner.libs.aws_executor",
                    "run",
                    str(manifest_path),
                    str(local_state_path),
                )
            )
            return
        if executor == "kvm":
            _run_checked(
                _python_module_command(
                    "runner.libs.prepare_local_inputs",
                    str(manifest_path),
                    str(local_state_path),
                ),
            )
            _run_checked(
                _python_module_command(
                    "runner.libs.kvm_executor",
                    str(manifest_path),
                    str(local_state_path),
                )
            )
            return
        _die(f"unsupported executor: {executor}")
    finally:
        if prep_cleanup_armed:
            _cleanup_failed_dedicated_aws_prep(manifest_path)
        for path in (manifest_path, local_state_path, remote_prep_state_path):
            path.unlink(missing_ok=True)


def _benchmark_action(target_name: str, mode: str) -> None:
    if mode in {"micro", "corpus", "e2e"}:
        _run_action(target_name, mode)
        return
    if mode != "all":
        _die(f"unsupported benchmark mode: {mode}")
    target_manifest = _temp_env_path(f"benchmark-target.{target_name}.")
    try:
        _write_target_manifest(target_name, target_manifest)
        contract = parse_manifest(target_manifest)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor != "aws-ssh":
            for suite_name in ("micro", "corpus", "e2e"):
                _run_action(target_name, suite_name)
            return
        processes = [
            subprocess.Popen(
                [sys.executable, "-m", "runner.libs.run_target_suite", "run", target_name, suite_name],
                cwd=ROOT_DIR,
            )
            for suite_name in ("micro", "corpus", "e2e")
        ]
        status = 0
        for process in processes:
            process.wait()
            if process.returncode != 0 and status == 0:
                status = process.returncode
        if status != 0:
            raise SystemExit(status)
        return
    finally:
        target_manifest.unlink(missing_ok=True)


def _terminate_action(target_name: str) -> None:
    manifest_path = _temp_env_path(f"terminate.{target_name}.")
    try:
        _write_target_manifest(target_name, manifest_path)
        contract = parse_manifest(manifest_path)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor != "aws-ssh":
            _die("terminate is only valid for AWS targets")
        _run_checked(
            _python_module_command(
                "runner.libs.aws_executor",
                "terminate",
                str(manifest_path),
            )
        )
    finally:
        manifest_path.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: run_target_suite.py <run|benchmark|terminate> <target> [suite]")
    action = args[0]
    target_name = args[1] if len(args) > 1 else ""
    suite_name = args[2] if len(args) > 2 else ""
    if action == "run":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py run <target> <suite>")
        _run_action(target_name, suite_name)
        return
    if action == "benchmark":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py benchmark <target> <micro|corpus|e2e|all>")
        _benchmark_action(target_name, suite_name)
        return
    if action == "terminate":
        if not target_name:
            _die("usage: run_target_suite.py terminate <target>")
        _terminate_action(target_name)
        return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
