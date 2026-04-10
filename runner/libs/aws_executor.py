from __future__ import annotations

import shutil
import os
import re
import sys
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.workspace_layout import remote_transfer_roots

_die = partial(fail, "aws-executor")

AwsExecutorContext = aws_common.AwsExecutorContext
_build_context = aws_common._build_context
_load_instance_state = aws_common._load_instance_state
_require_scalar = aws_common._require_scalar
_rsync_to = aws_common._rsync_to
_scp_from = aws_common._scp_from
_scp_to = aws_common._scp_to
_ssh_exec = aws_common._ssh_exec
_terminate_instance = aws_common._terminate_instance
_run_remote_helper = aws_common._run_remote_helper
_wait_for_ssh = aws_common._wait_for_ssh


def _artifact_dirs_from_log(log_path: Path, *, required: bool = True) -> list[str]:
    artifact_dirs: list[str] = []
    seen: set[str] = set()
    for line in log_path.read_text(encoding="utf-8").splitlines():
        match = re.match(r"^ARTIFACT_DIR=(.+)$", line.strip())
        if match:
            artifact_dir = match.group(1).strip()
            if artifact_dir and artifact_dir not in seen:
                seen.add(artifact_dir)
                artifact_dirs.append(artifact_dir)
    if required and not artifact_dirs:
        _die(f"remote suite log is missing ARTIFACT_DIR marker: {log_path}")
    return artifact_dirs


def _cleanup_failed_run(ctx: AwsExecutorContext, state: dict[str, str] | None = None) -> None:
    current_state = dict(state or {})
    if not current_state:
        current_state = _load_instance_state(ctx)
    instance_id = current_state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            _terminate_instance(ctx, instance_id)
        except Exception:
            pass
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _sync_remote_roots(ctx: AwsExecutorContext, ip: str) -> None:
    selected_roots = remote_transfer_roots(
        suite_name=str(ctx.contract.get("RUN_SUITE_NAME", "")).strip(),
        target_arch=str(ctx.contract.get("RUN_TARGET_ARCH", "")).strip(),
        executor=str(ctx.contract.get("RUN_EXECUTOR", "")).strip(),
        needs_runner_binary=str(ctx.contract.get("RUN_NEEDS_RUNNER_BINARY", "0")).strip() == "1",
        needs_daemon_binary=str(ctx.contract.get("RUN_NEEDS_DAEMON_BINARY", "0")).strip() == "1",
        needs_kinsn_modules=str(ctx.contract.get("RUN_NEEDS_KINSN_MODULES", "0")).strip() == "1",
        needs_workload_tools=str(ctx.contract.get("RUN_NEEDS_WORKLOAD_TOOLS", "0")).strip() == "1",
        native_repos=[
            entry.strip()
            for entry in str(ctx.contract.get("RUN_NATIVE_REPOS_CSV", "")).split(",")
            if entry.strip()
        ],
        scx_packages=[
            entry.strip()
            for entry in str(ctx.contract.get("RUN_SCX_PACKAGES_CSV", "")).split(",")
            if entry.strip()
        ],
    )
    if not selected_roots:
        _die("derived remote transfer roots selected no existing roots")
    missing_roots = [entry for entry in selected_roots if not (ROOT_DIR / entry).exists()]
    if missing_roots:
        _die(
            "derived remote transfer roots list missing local roots: "
            + ", ".join(missing_roots)
        )
    _ssh_exec(ctx, ip, "mkdir", "-p", ctx.remote_stage_dir)
    for entry in selected_roots:
        source_path = ROOT_DIR / entry
        remote_path = f"{ctx.remote_stage_dir}/{entry}"
        remote_parent = os.path.dirname(remote_path)
        _ssh_exec(ctx, ip, "mkdir", "-p", remote_parent)
        if source_path.is_dir():
            _ssh_exec(ctx, ip, "mkdir", "-p", remote_path)
            _rsync_to(ctx, ip, source_path, remote_path)
        else:
            _scp_to(ctx, ip, source_path, remote_path)


def _run_remote_suite(ctx: AwsExecutorContext, ip: str) -> None:
    _wait_for_ssh(ctx, ip)
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_log_dir = ctx.results_dir / "logs"
    local_log = local_log_dir / f"{stamp}.remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_python = _require_scalar(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    remote_workspace = ctx.remote_stage_dir
    local_log_dir.mkdir(parents=True, exist_ok=True)
    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)

    _run_remote_helper(ctx, ip, remote_python, "prepare-dir", remote_run_dir)
    _sync_remote_roots(ctx, ip)
    _scp_to(ctx, ip, ctx.manifest_path, f"{remote_run_dir}/run-contract.env")
    remote_completed = _run_remote_helper(
        ctx,
        ip,
        remote_python,
        "run-workspace",
        remote_workspace,
        f"{remote_run_dir}/run-contract.env",
        remote_log,
        remote_python,
        check=False,
    )
    log_exists = _run_remote_helper(
        ctx,
        ip,
        remote_python,
        "path-exists",
        remote_log,
        check=False,
    ).returncode == 0
    remote_artifact_dirs: list[str] = []
    local_artifact_dirs: list[Path] = []
    if log_exists:
        _scp_from(ctx, ip, remote_log, local_log)
        artifact_dirs = _artifact_dirs_from_log(local_log, required=remote_completed.returncode == 0)
        remote_artifact_dirs = [
            f"{remote_workspace}/{artifact_dir}"
            for artifact_dir in artifact_dirs
        ]
        local_artifact_dirs = [
            ROOT_DIR / artifact_dir
            for artifact_dir in artifact_dirs
        ]
        for remote_artifact_dir, local_artifact_dir in zip(remote_artifact_dirs, local_artifact_dirs):
            local_artifact_dir.parent.mkdir(parents=True, exist_ok=True)
            _scp_from(ctx, ip, remote_artifact_dir, local_artifact_dir.parent, recursive=True)
    if remote_completed.returncode != 0:
        _die(f"remote {ctx.target_name}/{ctx.suite_name} suite failed; inspect {local_log}")
    if len(local_artifact_dirs) == 1:
        shutil.copy2(local_log, local_artifact_dirs[0] / "aws-remote.log")
    print(
        "[aws-executor] Fetched "
        f"{ctx.target_name}/{ctx.suite_name} results to "
        + ", ".join(str(path) for path in local_artifact_dirs),
        file=sys.stderr,
    )


def _run_aws(ctx: AwsExecutorContext) -> None:
    state = {}
    try:
        state = _load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip)
    except BaseException:
        _cleanup_failed_run(ctx, state)
        raise
    _terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_action(ctx: AwsExecutorContext) -> None:
    execute_started = False
    try:
        if not ctx.remote_user:
            _die("manifest RUN_REMOTE_USER is empty")
        if not ctx.remote_stage_dir:
            _die("manifest RUN_REMOTE_STAGE_DIR is empty")
        if not ctx.key_path.is_file():
            _die(f"manifest RUN_AWS_KEY_PATH does not exist: {ctx.key_path}")
        execute_started = True
        _run_aws(ctx)
    except BaseException:
        if not execute_started:
            _cleanup_failed_run(ctx)
        raise


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) < 2:
        _die("usage: aws_executor.py <run|terminate> <manifest_path>")
    action = args[0]
    manifest_path = Path(args[1]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")
    ctx = _build_context(action, manifest_path)
    if action == "run":
        _run_action(ctx)
        return
    if action == "terminate":
        _terminate_instance(ctx)
        return
    _die(f"unsupported aws executor action: {action}")


if __name__ == "__main__":
    main()
