from __future__ import annotations

import fcntl
import os
import shutil
import subprocess
import sys
import tarfile
from contextlib import contextmanager
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import NoReturn

from runner.libs import ROOT_DIR
from runner.libs.run_contract import parse_manifest
from runner.libs.state_file import read_state


def _die(message: str) -> NoReturn:
    print(f"[aws-executor][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _require_scalar(contract: dict[str, str | list[str]], name: str) -> str:
    value = contract.get(name, "")
    if isinstance(value, list):
        _die(f"manifest {name} must be a scalar")
    scalar = value.strip()
    if not scalar:
        _die(f"manifest {name} is empty")
    return scalar


def _optional_scalar(contract: dict[str, str | list[str]], name: str, default: str = "") -> str:
    value = contract.get(name, default)
    if isinstance(value, list):
        _die(f"manifest {name} must be a scalar")
    return value.strip()


@dataclass(frozen=True)
class AwsExecutorContext:
    action: str
    manifest_path: Path
    contract: dict[str, str | list[str]]
    local_state_path: Path | None
    target_name: str
    suite_name: str
    run_token: str
    instance_mode: str
    remote_user: str
    remote_stage_dir: str
    key_path: Path
    aws_region: str
    aws_profile: str
    target_cache_dir: Path
    shared_state_dir: Path
    run_state_dir: Path
    state_dir: Path
    state_file: Path
    run_prep_root: Path
    results_dir: Path

    @property
    def remote_execution_lock(self) -> Path:
        return self.shared_state_dir / "remote-exec.lock"

    @property
    def state_lock(self) -> Path:
        return self.state_dir / "instance.lock"


def _build_context(action: str, manifest_path: Path, local_state_path: Path | None) -> AwsExecutorContext:
    contract = parse_manifest(manifest_path)
    target_name = _require_scalar(contract, "RUN_TARGET_NAME")
    run_token = _require_scalar(contract, "RUN_TOKEN")
    instance_mode = _optional_scalar(contract, "RUN_AWS_INSTANCE_MODE", "shared")
    if instance_mode not in {"shared", "dedicated"}:
        _die(f"unsupported RUN_AWS_INSTANCE_MODE: {instance_mode}")
    target_cache_dir = ROOT_DIR / ".cache" / target_name
    shared_state_dir = target_cache_dir / "state"
    run_state_dir = target_cache_dir / "run-state" / run_token
    if action != "terminate" and instance_mode == "dedicated":
        state_dir = run_state_dir
    else:
        state_dir = shared_state_dir
    return AwsExecutorContext(
        action=action,
        manifest_path=manifest_path,
        contract=contract,
        local_state_path=local_state_path,
        target_name=target_name,
        suite_name=_optional_scalar(contract, "RUN_SUITE_NAME"),
        run_token=run_token,
        instance_mode=instance_mode,
        remote_user=_optional_scalar(contract, "RUN_REMOTE_USER"),
        remote_stage_dir=_optional_scalar(contract, "RUN_REMOTE_STAGE_DIR"),
        key_path=Path(_optional_scalar(contract, "RUN_AWS_KEY_PATH")).resolve(),
        aws_region=_require_scalar(contract, "RUN_AWS_REGION"),
        aws_profile=_require_scalar(contract, "RUN_AWS_PROFILE"),
        target_cache_dir=target_cache_dir,
        shared_state_dir=shared_state_dir,
        run_state_dir=run_state_dir,
        state_dir=state_dir,
        state_file=state_dir / "instance.json",
        run_prep_root=target_cache_dir / "runs" / run_token,
        results_dir=target_cache_dir / "results",
    )


@contextmanager
def _locked_file(path: Path):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(handle.fileno(), fcntl.LOCK_UN)


def _aws_cmd(ctx: AwsExecutorContext, *args: str, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    command = ["aws", "--profile", ctx.aws_profile, "--region", ctx.aws_region, *args]
    return subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        capture_output=capture_output,
        check=False,
    )


def _describe_instance(ctx: AwsExecutorContext, instance_id: str) -> tuple[str, str, str]:
    completed = _aws_cmd(
        ctx,
        "ec2",
        "describe-instances",
        "--instance-ids",
        instance_id,
        "--query",
        "Reservations[0].Instances[0].[InstanceId,State.Name,PublicIpAddress]",
        "--output",
        "text",
        capture_output=True,
    )
    if completed.returncode != 0:
        return "", "", ""
    tokens = completed.stdout.strip().split()
    if len(tokens) < 3:
        return "", "", ""
    return tokens[0], tokens[1], tokens[2]


def _lookup_target_instance_ids(ctx: AwsExecutorContext) -> list[str]:
    completed = _aws_cmd(
        ctx,
        "ec2",
        "describe-instances",
        "--filters",
        "Name=tag:Project,Values=bpf-benchmark",
        f"Name=tag:Role,Values={ctx.target_name}",
        "Name=instance-state-name,Values=pending,running,stopping,stopped",
        "--query",
        "Reservations[].Instances[].InstanceId",
        "--output",
        "text",
        capture_output=True,
    )
    if completed.returncode != 0:
        return []
    return [token for token in completed.stdout.split() if token and token != "None"]


def _ssh_base_args(ctx: AwsExecutorContext, ip: str) -> list[str]:
    del ip
    return [
        "-o",
        "BatchMode=yes",
        "-o",
        "StrictHostKeyChecking=no",
        "-o",
        "UserKnownHostsFile=/dev/null",
        "-o",
        "ConnectTimeout=15",
        "-i",
        str(ctx.key_path),
    ]


def _ssh_bash(
    ctx: AwsExecutorContext,
    ip: str,
    *args: str,
    script: str,
    check: bool = True,
    capture_output: bool = False,
) -> subprocess.CompletedProcess[str]:
    command = [
        "ssh",
        *_ssh_base_args(ctx, ip),
        f"{ctx.remote_user}@{ip}",
        "bash",
        "-s",
        "--",
        *args,
    ]
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        input=script,
        text=True,
        capture_output=capture_output,
        check=False,
    )
    if check and completed.returncode != 0:
        raise SystemExit(completed.returncode)
    return completed


def _scp_to(ctx: AwsExecutorContext, ip: str, src: Path, dest: str) -> None:
    completed = subprocess.run(
        ["scp", *_ssh_base_args(ctx, ip), str(src), f"{ctx.remote_user}@{ip}:{dest}"],
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _scp_from(ctx: AwsExecutorContext, ip: str, src: str, dest: Path) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    completed = subprocess.run(
        ["scp", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}:{src}", str(dest)],
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _wait_for_ssh(ctx: AwsExecutorContext, ip: str) -> None:
    for _ in range(60):
        completed = subprocess.run(
            ["ssh", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}", "true"],
            cwd=ROOT_DIR,
            text=True,
            capture_output=True,
            check=False,
        )
        if completed.returncode == 0:
            return
        import time

        time.sleep(5)
    _die(f"timed out waiting for SSH on {ip}")


def _load_local_state(ctx: AwsExecutorContext) -> dict[str, str]:
    if ctx.local_state_path is None:
        return {}
    if not ctx.local_state_path.is_file():
        _die(f"local state file is missing: {ctx.local_state_path}")
    return read_state(ctx.local_state_path)


def _load_instance_state(ctx: AwsExecutorContext) -> dict[str, str]:
    if not ctx.state_file.is_file():
        return {}
    return read_state(ctx.state_file)


def _terminate_instance(ctx: AwsExecutorContext, explicit_instance_id: str = "") -> None:
    instance_id = explicit_instance_id.strip()
    if not instance_id:
        target_ids = _lookup_target_instance_ids(ctx)
        if target_ids:
            completed = _aws_cmd(ctx, "ec2", "terminate-instances", "--instance-ids", *target_ids)
            if completed.returncode != 0:
                raise SystemExit(completed.returncode)
            completed = _aws_cmd(ctx, "ec2", "wait", "instance-terminated", "--instance-ids", *target_ids)
            if completed.returncode != 0:
                raise SystemExit(completed.returncode)
        shutil.rmtree(ctx.shared_state_dir, ignore_errors=True)
        shutil.rmtree(ctx.target_cache_dir / "run-state", ignore_errors=True)
        return

    _, state, _ = _describe_instance(ctx, instance_id)
    if state not in {"terminated", "shutting-down", ""}:
        completed = _aws_cmd(ctx, "ec2", "terminate-instances", "--instance-ids", instance_id)
        if completed.returncode != 0:
            raise SystemExit(completed.returncode)
        completed = _aws_cmd(ctx, "ec2", "wait", "instance-terminated", "--instance-ids", instance_id)
        if completed.returncode != 0:
            raise SystemExit(completed.returncode)

    current_state = _load_instance_state(ctx)
    if current_state.get("STATE_INSTANCE_ID", "") == instance_id:
        ctx.state_file.unlink(missing_ok=True)


def _cleanup_local_run_prep_root(ctx: AwsExecutorContext) -> None:
    shutil.rmtree(ctx.run_prep_root, ignore_errors=True)


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
        _cleanup_local_run_prep_root(ctx)
        instance_id = state.get("STATE_INSTANCE_ID", "").strip()
        if instance_id:
            try:
                _terminate_instance(ctx, instance_id)
            except Exception:
                pass
        shutil.rmtree(ctx.run_state_dir, ignore_errors=True)
        raise
    _cleanup_local_run_prep_root(ctx)
    _terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_action(ctx: AwsExecutorContext) -> None:
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
    _run_dedicated(ctx, bundle_tar)


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
