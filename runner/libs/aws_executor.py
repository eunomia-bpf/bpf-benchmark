from __future__ import annotations

import os
import shutil
import subprocess
import sys
from collections.abc import Callable
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.run_contract import RunConfig
from runner.libs.state_file import write_state
from runner.libs.workspace_layout import remote_transfer_roots

_die = partial(fail, "aws-executor")


def _require(contract: RunConfig, name: str) -> str:
    try:
        return contract.required(name)
    except RuntimeError as exc:
        _die(str(exc))


def _save_state(ctx: aws_common.AwsExecutorContext, *, instance_id: str, instance_ip: str, kernel_release: str = "") -> None:
    write_state(ctx.state_file, {"STATE_INSTANCE_ID": instance_id, "STATE_INSTANCE_IP": instance_ip,
                                  "STATE_REGION": ctx.aws_region, "STATE_KERNEL_RELEASE": kernel_release})


def _require_aws_success(completed: subprocess.CompletedProcess[str], *, operation: str) -> None:
    if completed.returncode == 0:
        return
    detail = completed.stderr.strip() or completed.stdout.strip()
    if detail:
        _die(f"{operation} failed: {detail}")
    raise SystemExit(completed.returncode)


def _effective_name_tag(ctx: aws_common.AwsExecutorContext) -> str:
    base_tag = _require(ctx.contract, "RUN_NAME_TAG")
    if ctx.action != "terminate":
        return f"{base_tag}-{ctx.run_token}"
    return base_tag


def _describe_instance_type(ctx: aws_common.AwsExecutorContext, instance_id: str) -> str:
    completed = aws_common._aws_cmd(
        ctx, "ec2", "describe-instances",
        "--instance-ids", instance_id,
        "--query", "Reservations[0].Instances[0].InstanceType",
        "--output", "text",
        capture_output=True,
    )
    return completed.stdout.strip() if completed.returncode == 0 else ""


def _describe_instance_launch_contract(ctx: aws_common.AwsExecutorContext, instance_id: str) -> tuple[str, str, str, str]:
    completed = aws_common._aws_cmd(ctx, "ec2", "describe-instances", "--instance-ids", instance_id, "--query",
        "Reservations[0].Instances[0].[ImageId,KeyName,SubnetId,join(',', sort_by(SecurityGroups,&GroupId)[].GroupId)]",
        "--output", "text", capture_output=True)
    if completed.returncode != 0:
        return "", "", "", ""
    parts = completed.stdout.strip().split()
    return (parts[0], parts[1], parts[2], parts[3]) if len(parts) >= 4 else ("", "", "", "")


def _lookup_existing_instance(ctx: aws_common.AwsExecutorContext, *, ami_id: str, key_name: str,
                               security_group_id: str, subnet_id: str) -> tuple[str, str, str]:
    completed = aws_common._aws_cmd(ctx, "ec2", "describe-instances", "--filters",
        f"Name=tag:Name,Values={_effective_name_tag(ctx)}", f"Name=image-id,Values={ami_id}",
        f"Name=instance-type,Values={_require(ctx.contract, 'RUN_INSTANCE_TYPE')}",
        f"Name=key-name,Values={key_name}", f"Name=instance.group-id,Values={security_group_id}",
        f"Name=subnet-id,Values={subnet_id}", "Name=instance-state-name,Values=pending,running",
        "--query", "Reservations[].Instances[0].[InstanceId,State.Name,PublicIpAddress]",
        "--output", "text", capture_output=True)
    if completed.returncode != 0:
        return "", "", ""
    tokens = completed.stdout.strip().split()
    return (tokens[0], tokens[1], tokens[2]) if len(tokens) >= 3 else ("", "", "")


def _resolve_root_device_name(ctx: aws_common.AwsExecutorContext, ami_id: str) -> str:
    completed = aws_common._aws_cmd(ctx, "ec2", "describe-images", "--image-ids", ami_id,
                                     "--query", "Images[0].RootDeviceName", "--output", "text", capture_output=True)
    _require_aws_success(completed, operation=f"describe root device for AMI {ami_id}")
    root_device_name = completed.stdout.strip()
    return root_device_name if root_device_name and root_device_name != "None" else "/dev/xvda"


def _instance_state_is_reusable(state: str) -> bool:
    return state in {"pending", "running"}


def _run_local_make(*args: str, env: dict[str, str] | None = None) -> None:
    completed = subprocess.run(
        ["make", "-C", str(ROOT_DIR), *args],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _require_kernel_release(release_file: Path, *, arch: str) -> str:
    if not release_file.is_file():
        _die(f"missing {arch} kernel release file: {release_file}")
    kernel_release = release_file.read_text(encoding="utf-8").strip()
    if not kernel_release:
        _die(f"empty {arch} kernel release file: {release_file}")
    return kernel_release


def _require_modules_root(modules_root: Path, *, arch: str) -> Path:
    if not modules_root.is_dir():
        _die(f"missing canonical {arch} kernel modules root: {modules_root}")
    return modules_root


def _build_x86_kernel_artifacts() -> tuple[str, Path, Path]:
    build_dir = ROOT_DIR / ".cache" / "x86-kernel-build"
    kernel_image = build_dir / "arch" / "x86" / "boot" / "bzImage"
    modules_target = ROOT_DIR / ".cache" / "repo-artifacts" / "x86_64" / "kernel-modules" / "lib" / "modules"
    _run_local_make(str(kernel_image), str(modules_target), "RUN_TARGET_ARCH=x86_64", f"JOBS={max(os.cpu_count() or 1, 1)}")
    if not kernel_image.is_file():
        _die(f"missing x86 AWS kernel image: {kernel_image}")
    kernel_release = _require_kernel_release(build_dir / "include" / "config" / "kernel.release", arch="x86")
    return kernel_release, kernel_image, _require_modules_root(modules_target / kernel_release, arch="x86")


def _build_arm64_kernel_artifacts(ctx: aws_common.AwsExecutorContext) -> tuple[str, Path, Path]:
    build_dir = ctx.target_root / "kernel-build"
    base_config = ctx.target_root / "config-al2023-arm64"
    kernel_image = build_dir / "arch" / "arm64" / "boot" / "vmlinuz.efi"
    modules_target = ROOT_DIR / ".cache" / "repo-artifacts" / "arm64" / "kernel-modules" / "lib" / "modules"
    _run_local_make(str(kernel_image), str(modules_target), "RUN_TARGET_ARCH=arm64",
                    f"ARM64_AWS_BUILD_DIR={build_dir}", f"ARM64_AWS_BASE_CONFIG={base_config}",
                    f"JOBS={max(os.cpu_count() or 1, 1)}")
    if not kernel_image.is_file():
        _die(f"missing ARM64 AWS kernel image: {kernel_image}")
    kernel_release = _require_kernel_release(build_dir / "include" / "config" / "kernel.release", arch="ARM64")
    return kernel_release, kernel_image, _require_modules_root(modules_target / kernel_release, arch="ARM64")


def _remote_kernel_release(ctx: aws_common.AwsExecutorContext, ip: str) -> str:
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    completed = aws_common._run_remote_helper(ctx, ip, remote_python, "uname-r", capture_output=True)
    return completed.stdout.strip()


def _remote_root_volume_size_gb(ctx: aws_common.AwsExecutorContext, ip: str) -> int | None:
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    completed = aws_common._run_remote_helper(ctx, ip, remote_python, "root-volume-size-gb", check=False, capture_output=True)
    if completed.returncode != 0:
        return None
    value = completed.stdout.strip()
    if not value.isdigit():
        return None
    return int(value)


def _remote_has_runtime_btf(ctx: aws_common.AwsExecutorContext, ip: str) -> bool:
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    return aws_common._run_remote_helper(ctx, ip, remote_python, "has-runtime-btf", check=False).returncode == 0


def _remote_has_sched_ext(ctx: aws_common.AwsExecutorContext, ip: str) -> bool:
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    return aws_common._run_remote_helper(ctx, ip, remote_python, "has-sched-ext", check=False).returncode == 0


def _ordered_unique(tokens: list[str]) -> list[str]:
    ordered: list[str] = []
    for token in tokens:
        if token and token not in ordered:
            ordered.append(token)
    return ordered


def _remote_required_commands(contract: RunConfig) -> list[str]:
    python_bin = _require(contract, "RUN_REMOTE_PYTHON_BIN")
    container_runtime = _require(contract, "RUN_CONTAINER_RUNTIME")
    commands = [
        container_runtime, "curl", "dracut", "file", "grubby", "insmod",
        "ip", python_bin, "rsync", "taskset", "tar",
    ]
    return _ordered_unique(commands)


def _verify_remote_base_prereqs(ctx: aws_common.AwsExecutorContext, ip: str) -> bool:
    commands = _remote_required_commands(ctx.contract)
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    return aws_common._run_remote_helper(
        ctx, ip, remote_python, "verify-base-prereqs", ",".join(commands), check=False,
    ).returncode == 0


def _require_remote_base_prereqs(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    if not _verify_remote_base_prereqs(ctx, ip):
        _die("AWS instance image is missing required base prerequisites; bake them into the AMI")


def _refresh_aws_arm64_base_config(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    completed = aws_common._run_remote_helper(ctx, ip, remote_python, "print-kernel-config", check=False, capture_output=True)
    if completed.returncode != 0:
        _die(f"failed to capture AWS ARM64 base kernel config from {ip}")
    base_config = ctx.target_root / "config-al2023-arm64"
    base_config.parent.mkdir(parents=True, exist_ok=True)
    base_config.write_text(completed.stdout, encoding="utf-8")
    remote_release = _remote_kernel_release(ctx, ip)
    base_config.with_suffix(".release").write_text(remote_release + "\n", encoding="utf-8")


def _sync_kernel_stage(ctx: aws_common.AwsExecutorContext, ip: str, *, kernel_release: str,
                        kernel_image: Path, modules_root: Path, remote_kernel_stage_dir: str) -> None:
    aws_common._ssh_exec(ctx, ip, "mkdir", "-p", f"{remote_kernel_stage_dir}/boot",
                          f"{remote_kernel_stage_dir}/lib/modules/{kernel_release}")
    aws_common._scp_to(ctx, ip, kernel_image, f"{remote_kernel_stage_dir}/boot/")
    aws_common._rsync_to(ctx, ip, modules_root, f"{remote_kernel_stage_dir}/lib/modules/{kernel_release}",
                          excludes=("build", "source"))


def _setup_kernel_instance(ctx: aws_common.AwsExecutorContext, ip: str, *, arch_label: str, setup_helper: str,
                            build_kernel_artifacts: Callable[[aws_common.AwsExecutorContext], tuple[str, Path, Path]],
                            refresh_arm64_base_config: bool = False) -> None:
    state = aws_common._load_instance_state(ctx)
    if not (instance_id := state.get("STATE_INSTANCE_ID", "").strip()):
        _die(f"{arch_label} setup requires a cached instance ID")
    aws_common._wait_for_ssh(ctx, ip)
    if refresh_arm64_base_config:
        _refresh_aws_arm64_base_config(ctx, ip)
    _require_remote_base_prereqs(ctx, ip)
    kernel_release, kernel_image, modules_root = build_kernel_artifacts(ctx)
    setup_stamp = f"setup_{kernel_release}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    setup_result_dir = ctx.results_dir / setup_stamp
    setup_result_dir.mkdir(parents=True, exist_ok=True)
    remote_kernel_stage_dir = _require(ctx.contract, "RUN_REMOTE_KERNEL_STAGE_DIR")
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    _sync_kernel_stage(ctx, ip, kernel_release=kernel_release, kernel_image=kernel_image,
                       modules_root=modules_root, remote_kernel_stage_dir=remote_kernel_stage_dir)
    aws_common._run_remote_helper(ctx, ip, remote_python, setup_helper, kernel_release, remote_kernel_stage_dir)
    for sub_cmd in (("reboot-instances", "--instance-ids", instance_id), ("wait", "instance-status-ok", "--instance-ids", instance_id)):
        if (c := aws_common._aws_cmd(ctx, "ec2", *sub_cmd)).returncode != 0:
            raise SystemExit(c.returncode)
    _, _, updated_ip = aws_common._describe_instance(ctx, instance_id)
    if not updated_ip or updated_ip == "None":
        _die(f"instance {instance_id} has no public IP after {arch_label} reboot")
    aws_common._wait_for_ssh(ctx, updated_ip)
    verify = aws_common._run_remote_helper(ctx, updated_ip, remote_python, "verify-kernel", kernel_release, "1", capture_output=True)
    (setup_result_dir / "setup_verify.log").write_text(verify.stdout, encoding="utf-8")
    _save_state(ctx, instance_id=instance_id, instance_ip=updated_ip, kernel_release=kernel_release)


def _setup_instance(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    if ctx.target_name == "aws-arm64":
        _setup_kernel_instance(ctx, ip, arch_label="ARM64", setup_helper="setup-kernel-arm64",
                                build_kernel_artifacts=_build_arm64_kernel_artifacts, refresh_arm64_base_config=True)
        return
    if ctx.target_name == "aws-x86":
        _setup_kernel_instance(ctx, ip, arch_label="x86", setup_helper="setup-kernel-x86",
                                build_kernel_artifacts=lambda _ctx: _build_x86_kernel_artifacts())
        return
    _die(f"unsupported AWS target for setup: {ctx.target_name}")


def _launch_instance(ctx: aws_common.AwsExecutorContext) -> None:
    key_name = _require(ctx.contract, "RUN_AWS_KEY_NAME")
    key_path = Path(_require(ctx.contract, "RUN_AWS_KEY_PATH")).resolve()
    security_group_id = _require(ctx.contract, "RUN_AWS_SECURITY_GROUP_ID")
    subnet_id = _require(ctx.contract, "RUN_AWS_SUBNET_ID")
    root_volume_gb = _require(ctx.contract, "RUN_ROOT_VOLUME_GB")
    if not root_volume_gb.isdigit() or int(root_volume_gb) <= 0:
        _die("RUN_ROOT_VOLUME_GB must be a positive integer")
    if not key_path.is_file():
        _die(f"SSH key does not exist: {key_path}")
    ami_id = ctx.contract.scalar("RUN_AMI_ID")
    if not ami_id:
        ami_param = _require(ctx.contract, "RUN_AMI_PARAM")
        completed = aws_common._aws_cmd(ctx, "ssm", "get-parameter", "--name", ami_param,
                                         "--query", "Parameter.Value", "--output", "text", capture_output=True)
        _require_aws_success(completed, operation=f"resolve AMI param {ami_param}")
        ami_id = completed.stdout.strip()
    state = aws_common._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    instance_state, instance_ip = "", ""
    if instance_id:
        _, instance_state, instance_ip = aws_common._describe_instance(ctx, instance_id)
        instance_type = _describe_instance_type(ctx, instance_id)
        current_image_id, current_key_name, current_subnet_id, current_security_groups = _describe_instance_launch_contract(ctx, instance_id)
        should_terminate = (instance_state in {"stopped", "stopping"}
                            or instance_type != _require(ctx.contract, "RUN_INSTANCE_TYPE")
                            or current_image_id != ami_id or current_key_name != key_name
                            or current_subnet_id != subnet_id or current_security_groups != security_group_id)
        if should_terminate:
            aws_common._terminate_instance(ctx, instance_id)
            instance_id = instance_state = instance_ip = ""
    if not instance_id or not _instance_state_is_reusable(instance_state):
        instance_id, instance_state, instance_ip = _lookup_existing_instance(
            ctx, ami_id=ami_id, key_name=key_name, security_group_id=security_group_id, subnet_id=subnet_id)
    if not instance_id or instance_id == "None":
        root_device_name = _resolve_root_device_name(ctx, ami_id)
        completed = aws_common._aws_cmd(ctx, "ec2", "run-instances",
            "--image-id", ami_id, "--instance-type", _require(ctx.contract, "RUN_INSTANCE_TYPE"),
            "--key-name", key_name, "--security-group-ids", security_group_id, "--subnet-id", subnet_id,
            "--block-device-mappings",
            f"DeviceName={root_device_name},Ebs={{VolumeSize={root_volume_gb},VolumeType=gp3,DeleteOnTermination=true}}",
            "--tag-specifications",
            f"ResourceType=instance,Tags=[{{Key=Name,Value={_effective_name_tag(ctx)}}},{{Key=Project,Value=bpf-benchmark}},{{Key=Role,Value={ctx.target_name}}}]",
            "--count", "1", "--query", "Instances[0].InstanceId", "--output", "text", capture_output=True)
        _require_aws_success(completed, operation=f"launch instance for {ctx.run_token}")
        instance_id = completed.stdout.strip()
    _save_state(ctx, instance_id=instance_id, instance_ip=instance_ip, kernel_release=state.get("STATE_KERNEL_RELEASE", ""))
    for sub_cmd in (("wait", "instance-running", "--instance-ids", instance_id), ("wait", "instance-status-ok", "--instance-ids", instance_id)):
        if (c := aws_common._aws_cmd(ctx, "ec2", *sub_cmd)).returncode != 0:
            raise SystemExit(c.returncode)
    _, _, instance_ip = aws_common._describe_instance(ctx, instance_id)
    if not instance_ip or instance_ip == "None":
        _die(f"instance {instance_id} has no public IP")
    _save_state(ctx, instance_id=instance_id, instance_ip=instance_ip, kernel_release=state.get("STATE_KERNEL_RELEASE", ""))


def _ensure_instance_for_suite(ctx: aws_common.AwsExecutorContext) -> str:
    if not ctx.remote_user: _die("run config RUN_REMOTE_USER is empty")
    if not ctx.remote_stage_dir: _die("run config RUN_REMOTE_STAGE_DIR is empty")
    if not ctx.key_path.is_file(): _die(f"run config RUN_AWS_KEY_PATH does not exist: {ctx.key_path}")
    state = aws_common._load_instance_state(ctx)
    if not state.get("STATE_INSTANCE_IP", "").strip():
        _launch_instance(ctx)
        state = aws_common._load_instance_state(ctx)
    if not (instance_ip := state.get("STATE_INSTANCE_IP", "").strip()):
        _die(f"failed to resolve {ctx.target_name} instance IP")
    aws_common._wait_for_ssh(ctx, instance_ip)

    root_volume_gb = _remote_root_volume_size_gb(ctx, instance_ip)
    if root_volume_gb is not None and root_volume_gb < int(_require(ctx.contract, "RUN_ROOT_VOLUME_GB")):
        aws_common._terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
        _launch_instance(ctx)
        state = aws_common._load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        aws_common._wait_for_ssh(ctx, instance_ip)

    def _maybe_setup(reason: bool) -> str | None:
        if not reason: return None
        _setup_instance(ctx, instance_ip)
        s2 = aws_common._load_instance_state(ctx)
        return s2.get("STATE_INSTANCE_IP", instance_ip).strip() or instance_ip

    if result := _maybe_setup(not state.get("STATE_KERNEL_RELEASE", "").strip()): return result
    if result := _maybe_setup(_remote_kernel_release(ctx, instance_ip) != state.get("STATE_KERNEL_RELEASE", "").strip()): return result
    _require_remote_base_prereqs(ctx, instance_ip)
    if result := _maybe_setup(ctx.contract.scalar("RUN_SUITE_NEEDS_RUNTIME_BTF", "0") == "1" and not _remote_has_runtime_btf(ctx, instance_ip)): return result
    if result := _maybe_setup(ctx.contract.scalar("RUN_SUITE_NEEDS_SCHED_EXT", "0") == "1" and not _remote_has_sched_ext(ctx, instance_ip)): return result
    return instance_ip


def _suite_results_relative_path(suite_name: str) -> str:
    suite = suite_name.strip()
    if suite in {"micro", "corpus", "e2e"}:
        return f"{suite}/results"
    if suite == "test":
        return "tests/results"
    _die(f"unsupported suite for result sync: {suite_name}")


def _sync_remote_roots(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    a = ctx.contract.artifacts
    selected_roots = remote_transfer_roots(
        suite_name=ctx.contract.identity.suite_name,
        target_arch=ctx.contract.identity.target_arch,
        needs_runner_binary=a.needs_runner_binary == "1",
        needs_daemon_binary=a.needs_daemon_binary == "1",
        needs_kinsn_modules=a.needs_kinsn_modules == "1",
        needs_workload_tools=a.needs_workload_tools == "1",
        native_repos=list(a.native_repos),
        scx_packages=list(a.scx_packages),
    )
    if not selected_roots:
        _die("derived remote transfer roots selected no existing roots")
    missing_roots = [e for e in selected_roots if not (ROOT_DIR / e).exists()]
    if missing_roots:
        _die("derived remote transfer roots list missing local roots: " + ", ".join(missing_roots))
    aws_common._ssh_exec(ctx, ip, "mkdir", "-p", ctx.remote_stage_dir)
    for entry in selected_roots:
        source_path = ROOT_DIR / entry
        remote_path = f"{ctx.remote_stage_dir}/{entry}"
        aws_common._ssh_exec(ctx, ip, "mkdir", "-p", os.path.dirname(remote_path))
        if source_path.is_dir():
            aws_common._ssh_exec(ctx, ip, "mkdir", "-p", remote_path)
            aws_common._rsync_to(ctx, ip, source_path, remote_path, excludes=("results/", "__pycache__/"))
        else:
            aws_common._scp_to(ctx, ip, source_path, remote_path)


def _sync_remote_results(ctx: aws_common.AwsExecutorContext, ip: str, remote_workspace: str) -> Path | None:
    relative_results = _suite_results_relative_path(ctx.suite_name)
    remote_results = f"{remote_workspace}/{relative_results}"
    local_results = ROOT_DIR / relative_results
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    if aws_common._run_remote_helper(ctx, ip, remote_python, "path-exists", remote_results, check=False).returncode != 0:
        return None
    aws_common._rsync_from(ctx, ip, remote_results, local_results)
    return local_results


def _run_remote_suite(ctx: aws_common.AwsExecutorContext, ip: str, suite_args_path: Path | None) -> None:
    aws_common._wait_for_ssh(ctx, ip)
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_log_dir = ctx.results_dir / "logs"
    local_log = local_log_dir / f"{stamp}.remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_python = _require(ctx.contract, "RUN_REMOTE_PYTHON_BIN")
    remote_workspace = ctx.remote_stage_dir
    local_log_dir.mkdir(parents=True, exist_ok=True)
    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)

    aws_common._run_remote_helper(ctx, ip, remote_python, "prepare-dir", remote_run_dir)
    _sync_remote_roots(ctx, ip)
    aws_common._scp_to(ctx, ip, ctx.config_path, f"{remote_run_dir}/run-contract.json")
    remote_suite_args_path = ""
    if suite_args_path is not None:
        remote_suite_args_path = f"{remote_run_dir}/suite-args.json"
        aws_common._scp_to(ctx, ip, suite_args_path, remote_suite_args_path)
    remote_completed = aws_common._run_remote_helper(
        ctx, ip, remote_python,
        "run-workspace",
        remote_workspace,
        f"{remote_run_dir}/run-contract.json",
        remote_log,
        remote_python,
        *([remote_suite_args_path] if remote_suite_args_path else []),
        check=False,
    )
    if aws_common._run_remote_helper(ctx, ip, remote_python, "path-exists", remote_log, check=False).returncode == 0:
        aws_common._scp_from(ctx, ip, remote_log, local_log)
    local_results = _sync_remote_results(ctx, ip, remote_workspace)
    if remote_completed.returncode != 0:
        _die(f"remote {ctx.target_name}/{ctx.suite_name} suite failed; inspect {local_log}")
    print(f"[aws-executor] Synced {ctx.target_name}/{ctx.suite_name} results to "
          + (str(local_results) if local_results is not None else "no result directory"), file=sys.stderr)


def _cleanup_failed_run(ctx: aws_common.AwsExecutorContext, state: dict[str, str] | None = None) -> None:
    current_state = dict(state or {})
    if not current_state:
        current_state = aws_common._load_instance_state(ctx)
    instance_id = current_state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            aws_common._terminate_instance(ctx, instance_id)
        except Exception as exc:
            print(f"[aws-executor][WARN] failed to terminate failed-run instance {instance_id}: {exc}", file=sys.stderr)
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def cleanup_failed_run_for_config(config_path: Path) -> None:
    if not config_path.is_file():
        return
    ctx = aws_common._build_context("run", config_path)
    _cleanup_failed_run(ctx)


def _run_aws(ctx: aws_common.AwsExecutorContext, suite_args_path: Path | None) -> None:
    state = {}
    try:
        instance_ip = _ensure_instance_for_suite(ctx)
        state = aws_common._load_instance_state(ctx)
        _run_remote_suite(ctx, instance_ip, suite_args_path)
    except BaseException:
        _cleanup_failed_run(ctx, state or None)
        raise
    aws_common._terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) < 2:
        _die("usage: aws_executor.py <run|terminate> <config_path> [suite_args_path]")
    action = args[0]
    config_path = Path(args[1]).resolve()
    if not config_path.is_file():
        _die(f"run config is missing: {config_path}")
    ctx = aws_common._build_context(action, config_path)
    if action == "run":
        if len(args) < 3:
            _die("usage: aws_executor.py run <config_path> <suite_args_path>")
        if len(args) > 3:
            _die("usage: aws_executor.py run <config_path> <suite_args_path>")
        suite_args_path = Path(args[2]).resolve()
        if not suite_args_path.is_file():
            _die(f"suite args file is missing: {suite_args_path}")
        _run_aws(ctx, suite_args_path)
        return
    if action == "terminate":
        if len(args) != 2:
            _die("usage: aws_executor.py terminate <config_path>")
        aws_common._terminate_instance(ctx)
        return
    _die(f"unsupported aws executor action: {action}")


if __name__ == "__main__":
    main()
