from __future__ import annotations

import shutil
import sys
import tarfile
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.state_file import read_state

_die = partial(fail, "aws-executor")

AwsExecutorContext = aws_common.AwsExecutorContext
_build_context = aws_common._build_context
_load_instance_state = aws_common._load_instance_state
_locked_file = aws_common._locked_file
_require_scalar = aws_common._require_scalar
_scp_from = aws_common._scp_from
_scp_to = aws_common._scp_to
_ssh_bash = aws_common._ssh_bash
_terminate_instance = aws_common._terminate_instance
_wait_for_ssh = aws_common._wait_for_ssh


def _load_local_state(ctx: AwsExecutorContext) -> dict[str, str]:
    if ctx.local_state_path is None:
        return {}
    if not ctx.local_state_path.is_file():
        _die(f"local state file is missing: {ctx.local_state_path}")
    return read_state(ctx.local_state_path)


def _cleanup_local_run_prep_root(ctx: AwsExecutorContext) -> None:
    shutil.rmtree(ctx.run_prep_root, ignore_errors=True)


def _cleanup_failed_dedicated_run(ctx: AwsExecutorContext, state: dict[str, str] | None = None) -> None:
    _cleanup_local_run_prep_root(ctx)
    current_state = dict(state or {})
    if not current_state:
        with _locked_file(ctx.state_lock):
            current_state = _load_instance_state(ctx)
    instance_id = current_state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            _terminate_instance(ctx, instance_id)
        except Exception:
            pass
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_remote_suite(ctx: AwsExecutorContext, ip: str, bundle_tar: Path) -> None:
    _wait_for_ssh(ctx, ip)
    if not bundle_tar.is_file():
        _die(f"prepared remote bundle is missing: {bundle_tar}")
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_result_dir = ctx.results_dir / stamp
    local_archive = local_result_dir / "results.tar.gz"
    local_log = local_result_dir / "remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_archive = f"{remote_run_dir}/results.tar.gz"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_python = _require_scalar(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    local_result_dir.mkdir(parents=True, exist_ok=True)

    _ssh_bash(
        ctx,
        ip,
        remote_run_dir,
        script="""
set -euo pipefail
run_dir="$1"
sudo rm -rf "$run_dir"
mkdir -p "$run_dir"
""",
    )
    _scp_to(ctx, ip, bundle_tar, f"{remote_run_dir}/bundle.tar.gz")
    remote_completed = _ssh_bash(
        ctx,
        ip,
        remote_run_dir,
        remote_archive,
        remote_log,
        remote_python,
        script="""
set -euo pipefail
run_dir="$1"
archive_path="$2"
log_path="$3"
remote_python="$4"
workspace="$run_dir/workspace"
bundle_path="$run_dir/bundle.tar.gz"
sudo rm -rf "$workspace"
mkdir -p "$workspace"
tar -xzf "$bundle_path" -C "$workspace"
rm -f "$bundle_path"
test -f "$workspace/run-contract.env"
sudo -E env PYTHONPATH="$workspace${PYTHONPATH:+:$PYTHONPATH}" \
    "$remote_python" -m runner.libs.execute_workspace \
    "$workspace" "$workspace/run-contract.env" "$archive_path" >"$log_path" 2>&1
""",
        check=False,
    )
    log_exists = _ssh_bash(
        ctx,
        ip,
        remote_log,
        script="""
set -euo pipefail
test -f "$1"
""",
        check=False,
    ).returncode == 0
    if log_exists:
        _scp_from(ctx, ip, remote_log, local_log)
    if remote_completed.returncode != 0:
        _die(f"remote {ctx.target_name}/{ctx.suite_name} suite failed; inspect {local_log}")
    _scp_from(ctx, ip, remote_archive, local_archive)
    with tarfile.open(local_archive, "r:gz") as archive:
        archive.extractall(local_result_dir, filter="data")
    _ssh_bash(
        ctx,
        ip,
        remote_run_dir,
        script="""
set -euo pipefail
sudo rm -rf "$1"
""",
        check=False,
    )
    print(
        f"[aws-executor] Fetched {ctx.target_name}/{ctx.suite_name} results to {local_result_dir}",
        file=sys.stderr,
    )


def _run_shared(ctx: AwsExecutorContext, bundle_tar: Path) -> None:
    with _locked_file(ctx.remote_execution_lock):
        with _locked_file(ctx.state_lock):
            state = _load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("shared AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip, bundle_tar)


def _run_dedicated(ctx: AwsExecutorContext, bundle_tar: Path) -> None:
    state = {}
    try:
        with _locked_file(ctx.state_lock):
            state = _load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("dedicated AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip, bundle_tar)
    except BaseException:
        _cleanup_failed_dedicated_run(ctx, state)
        raise
    _cleanup_local_run_prep_root(ctx)
    _terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_action(ctx: AwsExecutorContext) -> None:
    dedicated_execute_started = False
    try:
        if ctx.local_state_path is None:
            _die("run requires a local state path")
        if not ctx.remote_user:
            _die("manifest RUN_REMOTE_USER is empty")
        if not ctx.remote_stage_dir:
            _die("manifest RUN_REMOTE_STAGE_DIR is empty")
        if not ctx.key_path.is_file():
            _die(f"manifest RUN_AWS_KEY_PATH does not exist: {ctx.key_path}")
        local_state = _load_local_state(ctx)
        bundle_tar_value = local_state.get("RUN_BUNDLE_TAR", "").strip()
        if not bundle_tar_value:
            _die("local bundle path is unset; run canonical local prep first")
        bundle_tar = Path(bundle_tar_value).resolve()
        if ctx.instance_mode == "shared":
            _run_shared(ctx, bundle_tar)
            return
        dedicated_execute_started = True
        _run_dedicated(ctx, bundle_tar)
    except BaseException:
        if ctx.instance_mode == "dedicated" and not dedicated_execute_started:
            _cleanup_failed_dedicated_run(ctx)
        raise


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) < 2:
        _die("usage: aws_executor.py <run|terminate> <manifest_path> [local_state_path]")
    action = args[0]
    manifest_path = Path(args[1]).resolve()
    local_state_path = Path(args[2]).resolve() if len(args) > 2 and args[2] else None
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")
    ctx = _build_context(action, manifest_path, local_state_path)
    if action == "run":
        _run_action(ctx)
        return
    if action == "terminate":
        _terminate_instance(ctx)
        return
    _die(f"unsupported aws executor action: {action}")


if __name__ == "__main__":
    main()
