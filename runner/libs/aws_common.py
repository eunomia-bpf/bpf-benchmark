from __future__ import annotations

import fcntl
import os
import shutil
import subprocess
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.run_contract import parse_manifest
from runner.libs.state_file import read_state


def _require_scalar(contract: dict[str, str | list[str]], name: str) -> str:
    value = contract.get(name, "")
    if isinstance(value, list):
        fail("aws-common", f"manifest {name} must be a scalar")
    scalar = value.strip()
    if not scalar:
        fail("aws-common", f"manifest {name} is empty")
    return scalar


def _optional_scalar(contract: dict[str, str | list[str]], name: str, default: str = "") -> str:
    value = contract.get(name, default)
    if isinstance(value, list):
        fail("aws-common", f"manifest {name} must be a scalar")
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
        fail("aws-common", f"unsupported RUN_AWS_INSTANCE_MODE: {instance_mode}")
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
    env = os.environ.copy()
    env["AWS_PAGER"] = ""
    return subprocess.run(
        command,
        cwd=ROOT_DIR,
        env=env,
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
    import time

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
        time.sleep(5)
    fail("aws-common", f"timed out waiting for SSH on {ip}")


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
