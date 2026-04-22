from __future__ import annotations

import os
import shlex
import subprocess
import time
from dataclasses import dataclass
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.run_contract import RunConfig, read_run_config_file
from runner.libs.state_file import read_state

_die = partial(fail, "aws-common")


@dataclass(frozen=True)
class AwsExecutorContext:
    action: str
    config_path: Path
    contract: RunConfig
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


def _build_context(action: str, config_path: Path) -> AwsExecutorContext:
    contract = read_run_config_file(config_path)
    target_name = contract.identity.target_name; run_token = contract.identity.token
    if not target_name: _die("run config target name is empty")
    if not run_token: _die("run config token is empty")
    target_root = ROOT_DIR / ".cache" / target_name
    run_state_dir = target_root / "run-state" / run_token
    return AwsExecutorContext(action=action, config_path=config_path, contract=contract,
                              target_name=target_name, suite_name=contract.identity.suite_name,
                              run_token=run_token, remote_user=contract.remote.user,
                              remote_stage_dir=contract.remote.stage_dir,
                              key_path=Path(contract.aws.key_path).resolve(),
                              aws_region=contract.aws.region, aws_profile=contract.aws.profile,
                              target_root=target_root, run_state_dir=run_state_dir,
                              state_file=run_state_dir / "instance.json", results_dir=target_root / "results")


def _aws_cmd(ctx: AwsExecutorContext, *args: str, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    env = {**os.environ, "AWS_PAGER": ""}
    return subprocess.run(["aws", "--profile", ctx.aws_profile, "--region", ctx.aws_region, *args],
                          cwd=ROOT_DIR, env=env, text=True, capture_output=capture_output, check=False)


def _require_aws_query_success(completed: subprocess.CompletedProcess[str], *, operation: str) -> None:
    stderr = completed.stderr.strip()
    if completed.returncode == 0 and not stderr:
        return
    detail = stderr or completed.stdout.strip() or f"exit code {completed.returncode}"
    _die(f"{operation} failed: {detail}")


def _describe_instance(ctx: AwsExecutorContext, instance_id: str) -> tuple[str, str, str]:
    completed = _aws_cmd(ctx, "ec2", "describe-instances", "--instance-ids", instance_id,
                         "--query", "Reservations[0].Instances[0].[InstanceId,State.Name,PublicIpAddress]",
                         "--output", "text", capture_output=True)
    _require_aws_query_success(completed, operation=f"describe instance {instance_id}")
    tokens = completed.stdout.strip().split()
    if not tokens or tokens[0] == "None":
        return "", "", ""
    if len(tokens) < 3:
        _die(
            f"describe instance {instance_id} returned unexpected output: "
            f"{completed.stdout.strip() or '<empty>'}"
        )
    return (
        "" if tokens[0] == "None" else tokens[0],
        "" if tokens[1] == "None" else tokens[1],
        "" if tokens[2] == "None" else tokens[2],
    )


def _lookup_target_instance_ids(ctx: AwsExecutorContext) -> list[str]:
    completed = _aws_cmd(ctx, "ec2", "describe-instances",
                         "--filters", "Name=tag:Project,Values=bpf-benchmark",
                         f"Name=tag:Role,Values={ctx.target_name}",
                         "Name=instance-state-name,Values=pending,running,stopping,stopped",
                         "--query", "Reservations[].Instances[].InstanceId", "--output", "text", capture_output=True)
    _require_aws_query_success(
        completed,
        operation=f"lookup target instances for {ctx.target_name}",
    )
    return [token for token in completed.stdout.split() if token and token != "None"]


def _ssh_base_args(ctx: AwsExecutorContext) -> list[str]:
    return [
        "-o", "BatchMode=yes",
        "-o", "StrictHostKeyChecking=no",
        "-o", "UserKnownHostsFile=/dev/null",
        "-o", "ConnectTimeout=5",
        "-i", str(ctx.key_path),
    ]


def _ssh_exec(ctx: AwsExecutorContext, ip: str, *remote_command: str, check: bool = True, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(["ssh", *_ssh_base_args(ctx), f"{ctx.remote_user}@{ip}", shlex.join(remote_command)],
                               cwd=ROOT_DIR, text=True, capture_output=capture_output, check=False)
    if check and completed.returncode != 0: raise SystemExit(completed.returncode)
    return completed


def _scp_to(ctx: AwsExecutorContext, ip: str, src: Path, dest: str) -> None:
    command = ["scp", *_ssh_base_args(ctx), str(src), f"{ctx.remote_user}@{ip}:{dest}"]
    completed = subprocess.run(command, cwd=ROOT_DIR, text=True, capture_output=False, check=False)
    if completed.returncode != 0: raise SystemExit(completed.returncode)


def _scp_from(ctx: AwsExecutorContext, ip: str, src: str, dest: Path) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    command = ["scp", *_ssh_base_args(ctx), f"{ctx.remote_user}@{ip}:{src}", str(dest)]
    completed = subprocess.run(command, cwd=ROOT_DIR, text=True, capture_output=False, check=False)
    if completed.returncode != 0: raise SystemExit(completed.returncode)


def _wait_for_ssh(ctx: AwsExecutorContext, ip: str) -> None:
    attempts: list[str] = []
    for attempt in range(1, 61):
        completed = subprocess.run(["ssh", *_ssh_base_args(ctx), f"{ctx.remote_user}@{ip}", "true"],
                                   cwd=ROOT_DIR, text=True, capture_output=True, check=False)
        if completed.returncode == 0: return
        attempts.append(
            f"attempt={attempt} rc={completed.returncode}\n"
            f"stdout={completed.stdout.strip()}\n"
            f"stderr={completed.stderr.strip()}\n"
        )
        time.sleep(5)
    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)
    log_path = ctx.run_state_dir / f"wait-for-ssh-{ip}.log"
    log_path.write_text("\n".join(attempts), encoding="utf-8")
    last = attempts[-1].strip() if attempts else "no ssh attempts recorded"
    fail("aws-common", f"timed out waiting for SSH on {ip}; last error: {last}; full log: {log_path}")


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
