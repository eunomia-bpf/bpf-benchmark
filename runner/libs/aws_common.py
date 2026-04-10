from __future__ import annotations

import os
import shlex
import subprocess
from dataclasses import dataclass
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
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
    target_name: str
    suite_name: str
    run_token: str
    remote_user: str
    remote_stage_dir: str
    key_path: Path
    aws_region: str
    aws_profile: str
    target_root: Path
    run_state_dir: Path
    state_file: Path
    results_dir: Path


def _build_context(action: str, manifest_path: Path) -> AwsExecutorContext:
    contract = parse_manifest(manifest_path)
    target_name = _require_scalar(contract, "RUN_TARGET_NAME")
    run_token = _require_scalar(contract, "RUN_TOKEN")
    target_root = ROOT_DIR / ".cache" / target_name
    run_state_dir = target_root / "run-state" / run_token
    return AwsExecutorContext(
        action=action,
        manifest_path=manifest_path,
        contract=contract,
        target_name=target_name,
        suite_name=_optional_scalar(contract, "RUN_SUITE_NAME"),
        run_token=run_token,
        remote_user=_optional_scalar(contract, "RUN_REMOTE_USER"),
        remote_stage_dir=_optional_scalar(contract, "RUN_REMOTE_STAGE_DIR"),
        key_path=Path(_optional_scalar(contract, "RUN_AWS_KEY_PATH")).resolve(),
        aws_region=_require_scalar(contract, "RUN_AWS_REGION"),
        aws_profile=_require_scalar(contract, "RUN_AWS_PROFILE"),
        target_root=target_root,
        run_state_dir=run_state_dir,
        state_file=run_state_dir / "instance.json",
        results_dir=target_root / "results",
    )


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


def _ssh_exec(
    ctx: AwsExecutorContext,
    ip: str,
    *remote_command: str,
    check: bool = True,
    capture_output: bool = False,
) -> subprocess.CompletedProcess[str]:
    rendered = shlex.join(remote_command)
    command = [
        "ssh",
        *_ssh_base_args(ctx, ip),
        f"{ctx.remote_user}@{ip}",
        rendered,
    ]
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        capture_output=capture_output,
        check=False,
    )
    if check and completed.returncode != 0:
        raise SystemExit(completed.returncode)
    return completed


def _remote_helper_local_path() -> Path:
    return ROOT_DIR / "runner" / "libs" / "aws_remote_host.py"


def _remote_helper_remote_path(ctx: AwsExecutorContext) -> str:
    return f"{ctx.remote_stage_dir}/.runner-tools/aws_remote_host.py"


def _ensure_remote_helper(ctx: AwsExecutorContext, ip: str) -> str:
    remote_helper_path = _remote_helper_remote_path(ctx)
    remote_helper_dir = str(Path(remote_helper_path).parent)
    _ssh_exec(ctx, ip, "mkdir", "-p", remote_helper_dir)
    _scp_to(ctx, ip, _remote_helper_local_path(), remote_helper_path)
    return remote_helper_path


def _run_remote_helper(
    ctx: AwsExecutorContext,
    ip: str,
    remote_python: str,
    *helper_args: str,
    check: bool = True,
    capture_output: bool = False,
) -> subprocess.CompletedProcess[str]:
    remote_helper_path = _ensure_remote_helper(ctx, ip)
    return _ssh_exec(
        ctx,
        ip,
        remote_python,
        remote_helper_path,
        *helper_args,
        check=check,
        capture_output=capture_output,
    )


def _scp_to(ctx: AwsExecutorContext, ip: str, src: Path, dest: str, *, recursive: bool = False) -> None:
    command = ["scp", *_ssh_base_args(ctx, ip)]
    if recursive:
        command.append("-r")
    command.extend([str(src), f"{ctx.remote_user}@{ip}:{dest}"])
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _rsync_to(ctx: AwsExecutorContext, ip: str, src: Path, dest: str) -> None:
    command = [
        "rsync",
        "-a",
        "--delete",
        "-e",
        shlex.join(["ssh", *_ssh_base_args(ctx, ip)]),
        f"{src}/",
        f"{ctx.remote_user}@{ip}:{dest}/",
    ]
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _scp_from(ctx: AwsExecutorContext, ip: str, src: str, dest: Path, *, recursive: bool = False) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    command = ["scp", *_ssh_base_args(ctx, ip)]
    if recursive:
        command.append("-r")
    command.extend([f"{ctx.remote_user}@{ip}:{src}", str(dest)])
    completed = subprocess.run(
        command,
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
