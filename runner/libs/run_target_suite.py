from __future__ import annotations

import os
import re
import secrets
import shutil
import subprocess
import sys
import tempfile
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
from runner.libs.run_contract import build_manifest, build_target_manifest, write_manifest_file


CACHE_DIR = ROOT_DIR / ".cache" / "runner-contracts"


_die = partial(fail, "run-target-suite")


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
    ctx = aws_common._build_context("run", manifest_path, None)
    if ctx.instance_mode != "dedicated":
        return
    state: dict[str, str] = {}
    if ctx.state_file.is_file():
        state = aws_common._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            aws_common._terminate_instance(ctx, instance_id)
        except Exception:
            pass
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


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
    success = False
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
            success = True
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
            success = True
            return
        _die(f"unsupported executor: {executor}")
    finally:
        if prep_cleanup_armed:
            _cleanup_failed_dedicated_aws_prep(manifest_path)
        if success:
            for path in (manifest_path, local_state_path, remote_prep_state_path):
                path.unlink(missing_ok=True)
        else:
            for path in (manifest_path, local_state_path, remote_prep_state_path):
                if path.exists():
                    print(f"[run-target-suite][ERROR] preserved debug artifact: {path}", file=sys.stderr)


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
