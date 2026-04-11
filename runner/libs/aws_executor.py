from __future__ import annotations

import shutil
import os
import sys
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.workspace_layout import remote_transfer_roots

_die = partial(fail, "aws-executor")


def _suite_results_relative_path(suite_name: str) -> str:
    suite = suite_name.strip()
    if suite in {"micro", "corpus", "e2e"}:
        return f"{suite}/results"
    if suite == "test":
        return "tests/results"
    _die(f"unsupported suite for result sync: {suite_name}")


def _cleanup_failed_run(ctx: aws_common.AwsExecutorContext, state: dict[str, str] | None = None) -> None:
    current_state = dict(state or {})
    if not current_state:
        current_state = aws_common._load_instance_state(ctx)
    instance_id = current_state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            aws_common._terminate_instance(ctx, instance_id)
        except Exception:
            pass
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def cleanup_failed_run_for_manifest(manifest_path: Path) -> None:
    if not manifest_path.is_file():
        return
    ctx = aws_common._build_context("run", manifest_path)
    _cleanup_failed_run(ctx)


def _sync_remote_roots(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
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
    aws_common._ssh_exec(ctx, ip, "mkdir", "-p", ctx.remote_stage_dir)
    for entry in selected_roots:
        source_path = ROOT_DIR / entry
        remote_path = f"{ctx.remote_stage_dir}/{entry}"
        remote_parent = os.path.dirname(remote_path)
        aws_common._ssh_exec(ctx, ip, "mkdir", "-p", remote_parent)
        if source_path.is_dir():
            aws_common._ssh_exec(ctx, ip, "mkdir", "-p", remote_path)
            aws_common._rsync_to(ctx, ip, source_path, remote_path, excludes=("results/", "__pycache__/"))
        else:
            aws_common._scp_to(ctx, ip, source_path, remote_path)


def _sync_remote_results(ctx: aws_common.AwsExecutorContext, ip: str, remote_workspace: str) -> Path | None:
    relative_results = _suite_results_relative_path(ctx.suite_name)
    remote_results = f"{remote_workspace}/{relative_results}"
    local_results = ROOT_DIR / relative_results
    exists = aws_common._run_remote_helper(
        ctx,
        ip,
        aws_common._require_scalar(ctx.contract, "RUN_REMOTE_PYTHON_BIN"),
        "path-exists",
        remote_results,
        check=False,
    ).returncode == 0
    if not exists:
        return None
    aws_common._rsync_from(ctx, ip, remote_results, local_results)
    return local_results


def _run_remote_suite(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    aws_common._wait_for_ssh(ctx, ip)
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_log_dir = ctx.results_dir / "logs"
    local_log = local_log_dir / f"{stamp}.remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_python = aws_common._require_scalar(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    remote_workspace = ctx.remote_stage_dir
    local_log_dir.mkdir(parents=True, exist_ok=True)
    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)

    aws_common._run_remote_helper(ctx, ip, remote_python, "prepare-dir", remote_run_dir)
    _sync_remote_roots(ctx, ip)
    aws_common._scp_to(ctx, ip, ctx.manifest_path, f"{remote_run_dir}/run-contract.env")
    remote_completed = aws_common._run_remote_helper(
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
    log_exists = aws_common._run_remote_helper(
        ctx,
        ip,
        remote_python,
        "path-exists",
        remote_log,
        check=False,
    ).returncode == 0
    if log_exists:
        aws_common._scp_from(ctx, ip, remote_log, local_log)
    local_results = _sync_remote_results(ctx, ip, remote_workspace)
    if remote_completed.returncode != 0:
        _die(f"remote {ctx.target_name}/{ctx.suite_name} suite failed; inspect {local_log}")
    print(
        "[aws-executor] Synced "
        f"{ctx.target_name}/{ctx.suite_name} results to "
        + (str(local_results) if local_results is not None else "no result directory"),
        file=sys.stderr,
    )


def _run_aws(ctx: aws_common.AwsExecutorContext) -> None:
    state = {}
    try:
        state = aws_common._load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip)
    except BaseException:
        _cleanup_failed_run(ctx, state)
        raise
    aws_common._terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_action(ctx: aws_common.AwsExecutorContext) -> None:
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
    ctx = aws_common._build_context(action, manifest_path)
    if action == "run":
        _run_action(ctx)
        return
    if action == "terminate":
        aws_common._terminate_instance(ctx)
        return
    _die(f"unsupported aws executor action: {action}")


if __name__ == "__main__":
    main()
