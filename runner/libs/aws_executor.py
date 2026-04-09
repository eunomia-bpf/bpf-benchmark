from __future__ import annotations

import shutil
import shlex
import subprocess
import sys
import tarfile
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail

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


def _cleanup_failed_dedicated_run(ctx: AwsExecutorContext, state: dict[str, str] | None = None) -> None:
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


def _stream_workspace_to_remote(
    ctx: AwsExecutorContext,
    ip: str,
    local_workspace: Path,
    remote_workspace: str,
) -> None:
    transfer_entries = ["runner"]
    if _require_scalar(ctx.contract, "RUN_NEEDS_DAEMON_BINARY") == "1":
        transfer_entries.append("daemon")
    if _require_scalar(ctx.contract, "RUN_NEEDS_KINSN_MODULES") == "1":
        transfer_entries.append("module")
    if ctx.suite_name == "test":
        transfer_entries.append("tests")
    if ctx.suite_name == "micro":
        transfer_entries.append("micro")
    if ctx.suite_name in {"corpus", "e2e"}:
        transfer_entries.append("corpus")
    if ctx.suite_name == "e2e":
        transfer_entries.append("e2e")
    selected_entries = [
        entry
        for entry in dict.fromkeys(transfer_entries)
        if (local_workspace / entry).exists()
    ]
    if not selected_entries:
        _die(f"no local workspace entries selected for {ctx.target_name}/{ctx.suite_name}")
    tar_command = [
        "tar",
        "--exclude=runner/repos",
        "--exclude=runner/repos/*",
        "--exclude=runner/repos/**",
        "--exclude=e2e/cases/katran/bin",
        "--exclude=e2e/cases/katran/bin/*",
        "--exclude=e2e/cases/katran/lib",
        "--exclude=e2e/cases/katran/lib/*",
        "--exclude=corpus/results",
        "--exclude=e2e/results",
        "--exclude=micro/results",
        "--exclude=__pycache__",
        "-C",
        str(local_workspace),
        "-chf",
        "-",
        *selected_entries,
    ]
    remote_command = (
        "set -euo pipefail; "
        f"rm -rf {shlex.quote(remote_workspace)}; "
        f"mkdir -p {shlex.quote(remote_workspace)}; "
        f"tar -xf - -C {shlex.quote(remote_workspace)}"
    )
    ssh_command = [
        "ssh",
        *aws_common._ssh_base_args(ctx, ip),
        f"{ctx.remote_user}@{ip}",
        f"bash -lc {shlex.quote(remote_command)}",
    ]
    tar_proc = subprocess.Popen(
        tar_command,
        cwd=local_workspace,
        stdout=subprocess.PIPE,
        text=False,
    )
    try:
        ssh_completed = subprocess.run(
            ssh_command,
            cwd=ROOT_DIR,
            stdin=tar_proc.stdout,
            check=False,
        )
    finally:
        if tar_proc.stdout is not None:
            tar_proc.stdout.close()
    tar_return = tar_proc.wait()
    if tar_return != 0:
        raise SystemExit(tar_return)
    if ssh_completed.returncode != 0:
        raise SystemExit(ssh_completed.returncode)


def _run_remote_suite(ctx: AwsExecutorContext, ip: str) -> None:
    _wait_for_ssh(ctx, ip)
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_result_dir = ctx.results_dir / stamp
    local_archive = local_result_dir / "results.tar.gz"
    local_log = local_result_dir / "remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_archive = f"{remote_run_dir}/results.tar.gz"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_python = _require_scalar(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    local_workspace = ROOT_DIR
    remote_workspace = f"{remote_run_dir}/workspace"
    local_result_dir.mkdir(parents=True, exist_ok=True)

    _ssh_bash(
        ctx,
        ip,
        remote_run_dir,
        script="""
set -euo pipefail
run_dir="$1"
rm -rf "$run_dir"
mkdir -p "$run_dir"
""",
    )
    _stream_workspace_to_remote(ctx, ip, local_workspace, remote_workspace)
    _scp_to(ctx, ip, ctx.manifest_path, f"{remote_workspace}/run-contract.env")
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
test -f "$workspace/run-contract.env"
env PYTHONPATH="$workspace${PYTHONPATH:+:$PYTHONPATH}" \
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
rm -rf "$1"
""",
        check=False,
    )
    print(
        f"[aws-executor] Fetched {ctx.target_name}/{ctx.suite_name} results to {local_result_dir}",
        file=sys.stderr,
    )


def _run_shared(ctx: AwsExecutorContext) -> None:
    with _locked_file(ctx.remote_execution_lock):
        with _locked_file(ctx.state_lock):
            state = _load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("shared AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip)


def _run_dedicated(ctx: AwsExecutorContext) -> None:
    state = {}
    try:
        with _locked_file(ctx.state_lock):
            state = _load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die("dedicated AWS run is missing STATE_INSTANCE_IP before remote execution")
        _run_remote_suite(ctx, instance_ip)
    except BaseException:
        _cleanup_failed_dedicated_run(ctx, state)
        raise
    _terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_action(ctx: AwsExecutorContext) -> None:
    dedicated_execute_started = False
    try:
        if not ctx.remote_user:
            _die("manifest RUN_REMOTE_USER is empty")
        if not ctx.remote_stage_dir:
            _die("manifest RUN_REMOTE_STAGE_DIR is empty")
        if not ctx.key_path.is_file():
            _die(f"manifest RUN_AWS_KEY_PATH does not exist: {ctx.key_path}")
        if ctx.instance_mode == "shared":
            _run_shared(ctx)
            return
        dedicated_execute_started = True
        _run_dedicated(ctx)
    except BaseException:
        if ctx.instance_mode == "dedicated" and not dedicated_execute_started:
            _cleanup_failed_dedicated_run(ctx)
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
