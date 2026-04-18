from __future__ import annotations

import os
import shlex
import shutil
import subprocess
import sys
import time
from datetime import datetime, timezone
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.file_lock import runner_lock
from runner.libs.run_contract import RunConfig, read_run_config_file
from runner.libs.state_file import write_state
from runner.libs.suite_commands import build_runtime_container_command, runtime_container_host_dirs
from runner.libs.suite_args import read_suite_args_file
from runner.libs.workspace_layout import runtime_container_image_tar_path

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
    completed = aws_common._aws_cmd(ctx, "ec2", "describe-instances",
        "--instance-ids", instance_id, "--query", "Reservations[0].Instances[0].InstanceType",
        "--output", "text", capture_output=True)
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
    completed = subprocess.run(["make", "-C", str(ROOT_DIR), *args],
                               cwd=ROOT_DIR, env=env, text=True, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _local_build_jobs() -> int:
    for name in ("IMAGE_BUILD_JOBS", "JOBS"):
        value = os.environ.get(name, "").strip()
        if value.isdigit() and int(value) > 0:
            return int(value)
    return max(os.cpu_count() or 1, 1)


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


def _build_x86_kernel_artifacts(ctx: aws_common.AwsExecutorContext) -> tuple[str, Path, Path]:
    del ctx
    build_dir = ROOT_DIR / ".cache" / "x86-kernel-build"
    kernel_image = build_dir / "arch" / "x86" / "boot" / "bzImage"
    modules_target = ROOT_DIR / ".cache" / "repo-artifacts" / "x86_64" / "kernel-modules" / "lib" / "modules"
    _run_local_make(str(kernel_image), str(modules_target), "RUN_TARGET_ARCH=x86_64",
                    f"X86_BUILD_DIR={build_dir}",
                    f"JOBS={_local_build_jobs()}")
    if not kernel_image.is_file():
        _die(f"missing x86 kernel image: {kernel_image}")
    kernel_release = _require_kernel_release(build_dir / "include" / "config" / "kernel.release", arch="x86")
    return kernel_release, kernel_image, _require_modules_root(modules_target / kernel_release, arch="x86")


def _build_arm64_kernel_artifacts(ctx: aws_common.AwsExecutorContext) -> tuple[str, Path, Path]:
    build_dir = ctx.target_root / "kernel-build"
    kernel_image = build_dir / "arch" / "arm64" / "boot" / "vmlinuz.efi"
    modules_target = ROOT_DIR / ".cache" / "repo-artifacts" / "arm64" / "kernel-modules" / "lib" / "modules"
    _run_local_make(str(kernel_image), str(modules_target), "RUN_TARGET_ARCH=arm64",
                    f"ARM64_AWS_BUILD_DIR={build_dir}", f"JOBS={_local_build_jobs()}")
    if not kernel_image.is_file():
        _die(f"missing ARM64 AWS kernel image: {kernel_image}")
    kernel_release = _require_kernel_release(build_dir / "include" / "config" / "kernel.release", arch="ARM64")
    return kernel_release, kernel_image, _require_modules_root(modules_target / kernel_release, arch="ARM64")


def _remote_kernel_release(ctx: aws_common.AwsExecutorContext, ip: str) -> str:
    completed = aws_common._ssh_exec(ctx, ip, "uname", "-r", capture_output=True)
    return completed.stdout.strip()


def _remote_boot_id(ctx: aws_common.AwsExecutorContext, ip: str) -> str:
    completed = aws_common._ssh_exec(
        ctx, ip, "cat", "/proc/sys/kernel/random/boot_id", check=False, capture_output=True)
    return completed.stdout.strip() if completed.returncode == 0 else ""


def _reboot_and_wait_for_new_boot(ctx: aws_common.AwsExecutorContext,
                                  instance_id: str, previous_boot_id: str) -> str:
    completed = aws_common._aws_cmd(
        ctx, "ec2", "reboot-instances", "--instance-ids", instance_id, capture_output=True)
    _require_aws_success(completed, operation=f"reboot instance {instance_id}")

    attempts: list[str] = []
    for attempt in range(1, 121):
        _, state, ip = aws_common._describe_instance(ctx, instance_id)
        if ip and ip != "None":
            probe = aws_common._ssh_exec(
                ctx, ip, "cat", "/proc/sys/kernel/random/boot_id", check=False, capture_output=True)
            boot_id = probe.stdout.strip()
            attempts.append(
                f"attempt={attempt} state={state} ip={ip} rc={probe.returncode} boot_id={boot_id}\n"
                f"stdout={probe.stdout.strip()}\n"
                f"stderr={probe.stderr.strip()}\n"
            )
            if probe.returncode == 0 and boot_id and boot_id != previous_boot_id:
                return ip
        else:
            attempts.append(f"attempt={attempt} state={state} ip={ip}\n")
        time.sleep(5)

    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)
    log_path = ctx.run_state_dir / f"wait-for-reboot-{instance_id}.log"
    log_path.write_text("\n".join(attempts), encoding="utf-8")
    last = attempts[-1].strip() if attempts else "no reboot attempts recorded"
    _die(f"timed out waiting for {instance_id} to reboot; last probe: {last}; full log: {log_path}")


def _remote_root_volume_size_gb(ctx: aws_common.AwsExecutorContext, ip: str) -> int | None:
    script = (
        "root_source=$(findmnt -n -o SOURCE / 2>/dev/null) || exit 1; "
        "root_device=\"$root_source\"; "
        "parent=$(lsblk -no PKNAME \"$root_source\" 2>/dev/null | head -1) && "
        "[ -n \"$parent\" ] && root_device=\"/dev/$parent\"; "
        "size=$(lsblk -nb -o SIZE \"$root_device\" 2>/dev/null | head -1) || exit 1; "
        "[ -n \"$size\" ] && echo $(( (size + 1073741824 - 1) / 1073741824 ))"
    )
    completed = aws_common._ssh_exec(ctx, ip, "bash", "-c", script, check=False, capture_output=True)
    if completed.returncode != 0:
        return None
    value = completed.stdout.strip()
    return int(value) if value.isdigit() else None


def _remote_has_runtime_btf(ctx: aws_common.AwsExecutorContext, ip: str) -> bool:
    return aws_common._ssh_exec(
        ctx, ip, "bash", "-c",
        "test -f /sys/kernel/btf/vmlinux && test -s /sys/kernel/btf/vmlinux",
        check=False,
    ).returncode == 0


def _remote_has_sched_ext(ctx: aws_common.AwsExecutorContext, ip: str) -> bool:
    return aws_common._ssh_exec(
        ctx, ip, "test", "-e", "/sys/kernel/sched_ext/state",
        check=False,
    ).returncode == 0


def _ensure_remote_docker(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    script = r"""
set -eu
if ! command -v docker >/dev/null 2>&1; then
    if command -v dnf >/dev/null 2>&1; then
        sudo dnf install -y docker
    elif command -v yum >/dev/null 2>&1; then
        sudo yum install -y docker
    elif command -v apt-get >/dev/null 2>&1; then
        sudo apt-get update
        sudo DEBIAN_FRONTEND=noninteractive apt-get install -y docker.io
    else
        echo 'cannot install docker: no dnf, yum, or apt-get found' >&2
        exit 1
    fi
fi
if command -v systemctl >/dev/null 2>&1; then
    sudo systemctl enable --now docker
else
    sudo service docker start
fi
sudo docker info >/dev/null
""".strip()
    aws_common._ssh_exec(ctx, ip, "bash", "-c", script)


def _runtime_container_image(ctx: aws_common.AwsExecutorContext) -> str:
    image = ctx.contract.remote.runtime_container_image.strip()
    if not image:
        _die("run config RUN_RUNTIME_CONTAINER_IMAGE is empty")
    return image


def _remote_runtime_image_tar(ctx: aws_common.AwsExecutorContext) -> Path:
    return runtime_container_image_tar_path(Path(ctx.remote_stage_dir), ctx.contract.identity.target_arch)


def _ensure_remote_runtime_image_loaded(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    _ensure_remote_docker(ctx, ip)
    _sync_remote_roots(ctx, ip)
    aws_common._ssh_exec(ctx, ip, "sudo", "docker", "load", "-i", str(_remote_runtime_image_tar(ctx)))


def _tar_transform_pattern(value: str) -> str:
    return "".join(f"\\{char}" if char in "\\.^$*[]" else char for char in value).replace("#", "\\#")


def _tar_transform_replacement(value: str) -> str:
    return value.replace("\\", "\\\\").replace("&", "\\&").replace("#", "\\#")


def _deploy_kernel_artifacts(ctx: aws_common.AwsExecutorContext, ip: str,
                             kernel_release: str, kernel_image: Path,
                             modules_root: Path) -> None:
    tar_cmd = [
        "tar", "--owner=0", "--group=0", "--numeric-owner", "-cpf", "-",
        "-C", str(kernel_image.parent),
        "--transform",
        f"s#^{_tar_transform_pattern(kernel_image.name)}$#"
        f"boot/{_tar_transform_replacement(f'vmlinuz-{kernel_release}')}#",
        kernel_image.name,
        "-C", str(modules_root.parent),
        "--transform",
        f"s#^{_tar_transform_pattern(kernel_release)}#"
        f"lib/modules/{_tar_transform_replacement(kernel_release)}#",
        kernel_release,
    ]
    install_script = r"""
set -eu
release=$1
kernel_path="/boot/vmlinuz-${release}"
initrd_path="/boot/initramfs-${release}.img"
kernel_title="bpf-benchmark ${release}"
rm -rf -- "/host/lib/modules/${release}" "/host${kernel_path}"
tar -C /host -xpf -
chroot /host /bin/sh -c '
set -eux
release=$1
kernel_path=$2
initrd_path=$3
kernel_title=$4
depmod "${release}"
dracut --force "${initrd_path}" "${release}"
grubby --info="${kernel_path}" >/dev/null 2>&1 || grubby --add-kernel="${kernel_path}" --initrd="${initrd_path}" --title="${kernel_title}" --copy-default
grubby --set-default="${kernel_path}" || true
[ "$(grubby --default-kernel)" = "${kernel_path}" ]
' sh "${release}" "${kernel_path}" "${initrd_path}" "${kernel_title}"
""".strip()
    install_container_cmd = [
        "sudo", "docker", "run", "--rm", "-i",
        "--privileged", "--pid=host",
        "-v", "/:/host",
        "-v", "/dev:/host/dev",
        "-v", "/proc:/host/proc",
        "-v", "/sys:/host/sys",
        "-v", "/run:/host/run",
        _runtime_container_image(ctx),
        "/bin/sh", "-c", install_script, "kernel-install", kernel_release,
    ]
    extract_cmd = [
        "ssh", *aws_common._ssh_base_args(ctx), f"{ctx.remote_user}@{ip}",
        shlex.join(install_container_cmd),
    ]
    with subprocess.Popen(tar_cmd, stdout=subprocess.PIPE, cwd=ROOT_DIR) as tar_proc:
        rc = subprocess.run(extract_cmd, stdin=tar_proc.stdout, cwd=ROOT_DIR, text=False, check=False).returncode
        tar_proc.stdout.close()  # type: ignore[union-attr]
        tar_proc.wait()
        if tar_proc.returncode != 0:
            _die(f"tar failed while streaming kernel artifacts for {kernel_release}")
    if rc != 0:
        _die(f"remote kernel installer container failed on {ip} for {kernel_release}")


def _setup_instance(ctx: aws_common.AwsExecutorContext, ip: str) -> None:
    state = aws_common._load_instance_state(ctx)
    if not (instance_id := state.get("STATE_INSTANCE_ID", "").strip()):
        _die("setup requires a cached instance ID")
    aws_common._wait_for_ssh(ctx, ip)
    previous_boot_id = _remote_boot_id(ctx, ip)
    if not previous_boot_id:
        _die(f"failed to read pre-reboot boot_id from {ip}")

    target_arch = ctx.contract.identity.target_arch.strip() or ctx.target_name
    with runner_lock(f"artifact-build.{target_arch}"):
        if ctx.target_name == "aws-arm64":
            kernel_release, kernel_image, modules_root = _build_arm64_kernel_artifacts(ctx)
        elif ctx.target_name == "aws-x86":
            kernel_release, kernel_image, modules_root = _build_x86_kernel_artifacts(ctx)
        else:
            _die(f"unsupported AWS target for setup: {ctx.target_name}")

        setup_result_dir = ctx.results_dir / f"setup_{kernel_release}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
        setup_result_dir.mkdir(parents=True, exist_ok=True)

        _deploy_kernel_artifacts(ctx, ip, kernel_release, kernel_image, modules_root)

    updated_ip = _reboot_and_wait_for_new_boot(ctx, instance_id, previous_boot_id)
    if not updated_ip or updated_ip == "None":
        _die(f"instance {instance_id} has no public IP after reboot")

    verify_script = (
        f"set -e; "
        f"uname -r; "
        f"ip -brief addr show ens5 2>/dev/null || ip -brief addr; "
        f"sudo grubby --default-kernel; "
        f"[ \"$(uname -r)\" = \"{kernel_release}\" ] || {{ echo 'kernel mismatch' >&2; exit 1; }}; "
        f"[ \"$(sudo grubby --default-kernel)\" = \"/boot/vmlinuz-{kernel_release}\" ] || {{ echo 'grubby default mismatch' >&2; exit 1; }}; "
        f"test -s /sys/kernel/btf/vmlinux || {{ echo 'BTF not available' >&2; exit 1; }}"
    )
    verify = aws_common._ssh_exec(
        ctx, updated_ip, "bash", "-c", verify_script, check=False, capture_output=True)
    (setup_result_dir / "setup_verify.log").write_text(verify.stdout, encoding="utf-8")
    if verify.stderr:
        (setup_result_dir / "setup_verify.stderr.log").write_text(verify.stderr, encoding="utf-8")
    if verify.returncode != 0:
        _die(f"setup verify failed after reboot; inspect {setup_result_dir / 'setup_verify.log'}")
    _save_state(ctx, instance_id=instance_id, instance_ip=updated_ip, kernel_release=kernel_release)


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

    _ensure_remote_runtime_image_loaded(ctx, instance_ip)

    def _maybe_setup(reason: bool) -> str | None:
        if not reason: return None
        _setup_instance(ctx, instance_ip)
        s2 = aws_common._load_instance_state(ctx)
        return s2.get("STATE_INSTANCE_IP", instance_ip).strip() or instance_ip

    if result := _maybe_setup(not state.get("STATE_KERNEL_RELEASE", "").strip()): return result
    if result := _maybe_setup(_remote_kernel_release(ctx, instance_ip) != state.get("STATE_KERNEL_RELEASE", "").strip()): return result
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
    image_tar = runtime_container_image_tar_path(ROOT_DIR, ctx.contract.identity.target_arch)
    try:
        relative_image_tar = image_tar.relative_to(ROOT_DIR).as_posix()
    except ValueError:
        _die(f"runtime image tar is outside repository root: {image_tar}")
    if not image_tar.is_file():
        _die(f"runtime image tar does not exist: {image_tar}")
    aws_common._ssh_exec(ctx, ip, "mkdir", "-p", ctx.remote_stage_dir)
    remote_path = f"{ctx.remote_stage_dir}/{relative_image_tar}"
    aws_common._ssh_exec(ctx, ip, "mkdir", "-p", str(Path(remote_path).parent))
    aws_common._scp_to(ctx, ip, image_tar, remote_path)


def _sync_remote_results(ctx: aws_common.AwsExecutorContext, ip: str, remote_workspace: str) -> Path | None:
    relative_results = _suite_results_relative_path(ctx.suite_name)
    remote_results = f"{remote_workspace}/{relative_results}"
    local_results = ROOT_DIR / relative_results
    if aws_common._ssh_exec(ctx, ip, "test", "-e", remote_results, check=False).returncode != 0:
        return None
    _pull_remote_dir(ctx, ip, remote_results, local_results)
    return local_results


def _pull_remote_dir(ctx: aws_common.AwsExecutorContext, ip: str, remote_path: str, local_path: Path) -> None:
    local_path.mkdir(parents=True, exist_ok=True)
    remote_cmd = f"tar -C {shlex.quote(remote_path)} -cpf - ."
    extract_cmd = ["tar", "-C", str(local_path), "-xpf", "-"]
    with subprocess.Popen(["ssh", *aws_common._ssh_base_args(ctx), f"{ctx.remote_user}@{ip}", remote_cmd],
                          stdout=subprocess.PIPE, cwd=ROOT_DIR) as ssh_proc:
        rc = subprocess.run(extract_cmd, stdin=ssh_proc.stdout, cwd=ROOT_DIR, text=False, check=False).returncode
        ssh_proc.stdout.close()  # type: ignore[union-attr]
        ssh_proc.wait()
    if ssh_proc.returncode != 0:
        _die(f"remote tar failed while streaming {ip}:{remote_path}")
    if rc != 0:
        _die(f"local tar extract failed for {ip}:{remote_path} into {local_path}")


def _remote_runtime_container_command(
    ctx: aws_common.AwsExecutorContext,
    remote_workspace: str,
    suite_args_path: Path | None,
) -> list[str]:
    suite_args = read_suite_args_file(suite_args_path) if suite_args_path is not None else []
    return build_runtime_container_command(
        Path(remote_workspace),
        read_run_config_file(ctx.config_path),
        suite_args,
        die=_die,
    )


def _remote_result_dir_command(remote_workspace: str) -> str:
    dirs = [str(path) for path in runtime_container_host_dirs(Path(remote_workspace))]
    return shlex.join(["mkdir", "-p", *dirs])


def _run_remote_suite(ctx: aws_common.AwsExecutorContext, ip: str, suite_args_path: Path | None) -> None:
    aws_common._wait_for_ssh(ctx, ip)
    _ensure_remote_docker(ctx, ip)
    stamp = f"{ctx.suite_name}_{ctx.run_token}_{datetime.now(timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    local_log_dir = ctx.results_dir / "logs"
    local_log = local_log_dir / f"{stamp}.remote.log"
    remote_run_dir = f"{ctx.remote_stage_dir}/runs/{stamp}"
    remote_log = f"{remote_run_dir}/remote.log"
    remote_workspace = ctx.remote_stage_dir
    local_log_dir.mkdir(parents=True, exist_ok=True)
    ctx.run_state_dir.mkdir(parents=True, exist_ok=True)

    # prepare-dir: mkdir with correct ownership
    aws_common._ssh_exec(ctx, ip, "bash", "-c",
        f"mkdir -p {shlex.quote(remote_run_dir)} && "
        f"chown $(id -u):$(id -g) {shlex.quote(remote_run_dir)} 2>/dev/null || true"
    )
    suite_cmd = shlex.join(_remote_runtime_container_command(ctx, remote_workspace, suite_args_path))
    log_dir_cmd = f"mkdir -p {shlex.quote(str(Path(remote_log).parent))}"
    run_cmd = (
        f"{log_dir_cmd} && "
        f"{_remote_result_dir_command(remote_workspace)} && "
        f"sudo {suite_cmd} >{shlex.quote(remote_log)} 2>&1"
    )
    remote_completed = aws_common._ssh_exec(ctx, ip, "bash", "-c", run_cmd, check=False)
    if aws_common._ssh_exec(ctx, ip, "test", "-e", remote_log, check=False).returncode == 0:
        aws_common._scp_from(ctx, ip, remote_log, local_log)
    local_results = _sync_remote_results(ctx, ip, remote_workspace)
    if remote_completed.returncode != 0:
        _die(f"remote {ctx.target_name}/{ctx.suite_name} suite failed; inspect {local_log}")
    remote_scratch = str(Path(remote_workspace) / "docs" / "tmp" / "runtime-container-tmp" / ctx.run_token)
    aws_common._ssh_exec(ctx, ip, "sudo", "rm", "-rf", "--", remote_scratch, check=False)
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
    print(f"[aws-executor][WARN] preserved failed-run state: {ctx.run_state_dir}", file=sys.stderr)


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
