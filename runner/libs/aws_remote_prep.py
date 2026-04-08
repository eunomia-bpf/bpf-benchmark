from __future__ import annotations

import os
import shlex
import subprocess
import sys
from pathlib import Path
from typing import NoReturn

from runner.libs import ROOT_DIR
from runner.libs import aws_executor
from runner.libs.run_contract import parse_manifest
from runner.libs.state_file import read_state, write_state


def _die(message: str) -> NoReturn:
    print(f"[aws-remote-prep][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _base_env_from_contract(contract: dict[str, str | list[str]]) -> dict[str, str]:
    env: dict[str, str] = {}
    for name in ("PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL"):
        value = os.environ.get(name, "").strip()
        if value:
            env[name] = value
    for name, value in contract.items():
        env[name] = shlex.join(value) if isinstance(value, list) else value
    return env


def _kernel_helper_env(ctx: aws_executor.AwsExecutorContext) -> dict[str, str]:
    env = _base_env_from_contract(ctx.contract)
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["PYTHONPATH"] = f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}"
    env["RUN_CONTRACT_PYTHON_BIN"] = sys.executable
    env["ACTION"] = "run"
    env["MANIFEST_PATH"] = str(ctx.manifest_path)
    env.pop("AWS_REMOTE_PREP_STATE_PATH", None)
    return env


def _run_kernel_helper_query(
    ctx: aws_executor.AwsExecutorContext,
    *,
    body: str,
    result_keys: tuple[str, ...],
) -> dict[str, str]:
    command = "\n".join(
        (
            "set -euo pipefail",
            'source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"',
            'source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"',
            'source "$ROOT_DIR/runner/scripts/aws_kernel_artifacts_lib.sh"',
            body,
        )
    )
    completed = subprocess.run(
        ["/bin/bash", "-lc", command],
        cwd=ROOT_DIR,
        env=_kernel_helper_env(ctx),
        text=True,
        capture_output=True,
        check=False,
    )
    if completed.returncode != 0:
        if completed.stdout:
            print(completed.stdout, file=sys.stderr, end="")
        if completed.stderr:
            print(completed.stderr, file=sys.stderr, end="")
        raise SystemExit(completed.returncode)
    values: dict[str, str] = {}
    for line in completed.stdout.splitlines():
        if "=" not in line:
            continue
        key, value = line.split("=", 1)
        values[key.strip()] = value.strip()
    missing = [key for key in result_keys if not values.get(key, "").strip()]
    if missing:
        _die(f"kernel helper did not report required values: {', '.join(missing)}")
    return values


def _effective_name_tag(ctx: aws_executor.AwsExecutorContext) -> str:
    base_tag = aws_executor._require_scalar(ctx.contract, "RUN_NAME_TAG")
    if ctx.action != "terminate" and ctx.instance_mode == "dedicated":
        return f"{base_tag}-{ctx.run_token}"
    return base_tag


def _save_state(
    ctx: aws_executor.AwsExecutorContext,
    *,
    instance_id: str,
    instance_ip: str,
    kernel_release: str = "",
) -> None:
    write_state(
        ctx.state_file,
        {
            "STATE_INSTANCE_ID": instance_id,
            "STATE_INSTANCE_IP": instance_ip,
            "STATE_REGION": ctx.aws_region,
            "STATE_KERNEL_RELEASE": kernel_release,
        },
    )


def _describe_instance_type(ctx: aws_executor.AwsExecutorContext, instance_id: str) -> str:
    completed = aws_executor._aws_cmd(
        ctx,
        "ec2",
        "describe-instances",
        "--instance-ids",
        instance_id,
        "--query",
        "Reservations[0].Instances[0].InstanceType",
        "--output",
        "text",
        capture_output=True,
    )
    if completed.returncode != 0:
        return ""
    return completed.stdout.strip()


def _describe_instance_launch_contract(ctx: aws_executor.AwsExecutorContext, instance_id: str) -> tuple[str, str, str, str]:
    completed = aws_executor._aws_cmd(
        ctx,
        "ec2",
        "describe-instances",
        "--instance-ids",
        instance_id,
        "--query",
        "Reservations[0].Instances[0].[ImageId,KeyName,SubnetId,join(',', sort_by(SecurityGroups,&GroupId)[].GroupId)]",
        "--output",
        "text",
        capture_output=True,
    )
    if completed.returncode != 0:
        return "", "", "", ""
    parts = completed.stdout.strip().split()
    if len(parts) < 4:
        return "", "", "", ""
    return parts[0], parts[1], parts[2], parts[3]


def _lookup_existing_instance(
    ctx: aws_executor.AwsExecutorContext,
    *,
    ami_id: str,
    key_name: str,
    security_group_id: str,
    subnet_id: str,
) -> tuple[str, str, str]:
    completed = aws_executor._aws_cmd(
        ctx,
        "ec2",
        "describe-instances",
        "--filters",
        f"Name=tag:Name,Values={_effective_name_tag(ctx)}",
        f"Name=image-id,Values={ami_id}",
        f"Name=instance-type,Values={aws_executor._require_scalar(ctx.contract, 'RUN_INSTANCE_TYPE')}",
        f"Name=key-name,Values={key_name}",
        f"Name=instance.group-id,Values={security_group_id}",
        f"Name=subnet-id,Values={subnet_id}",
        "Name=instance-state-name,Values=pending,running",
        "--query",
        "Reservations[].Instances[0].[InstanceId,State.Name,PublicIpAddress]",
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


def _resolve_root_device_name(ctx: aws_executor.AwsExecutorContext, ami_id: str) -> str:
    completed = aws_executor._aws_cmd(
        ctx,
        "ec2",
        "describe-images",
        "--image-ids",
        ami_id,
        "--query",
        "Images[0].RootDeviceName",
        "--output",
        "text",
        capture_output=True,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    root_device_name = completed.stdout.strip()
    if not root_device_name or root_device_name == "None":
        return "/dev/xvda"
    return root_device_name


def _instance_state_is_reusable(state: str) -> bool:
    return state in {"pending", "running"}


def _remote_kernel_release(ctx: aws_executor.AwsExecutorContext, ip: str) -> str:
    completed = aws_executor._ssh_bash(
        ctx,
        ip,
        script="""
set -euo pipefail
uname -r
""",
        capture_output=True,
    )
    return completed.stdout.strip()


def _remote_root_volume_size_gb(ctx: aws_executor.AwsExecutorContext, ip: str) -> int | None:
    completed = aws_executor._ssh_bash(
        ctx,
        ip,
        script="""
set -euo pipefail
root_source="$(findmnt -n -o SOURCE /)"
[[ -n "$root_source" ]] || exit 1
root_device="$root_source"
parent_kname="$(lsblk -no PKNAME "$root_source" 2>/dev/null | head -n1 || true)"
if [[ -n "$parent_kname" ]]; then
    root_device="/dev/${parent_kname}"
fi
size_bytes="$(lsblk -nb -o SIZE "$root_device" 2>/dev/null | head -n1 || true)"
[[ -n "$size_bytes" ]] || exit 1
echo $(((size_bytes + 1073741824 - 1) / 1073741824))
""",
        check=False,
        capture_output=True,
    )
    if completed.returncode != 0:
        return None
    value = completed.stdout.strip()
    if not value.isdigit():
        return None
    return int(value)


def _remote_has_runtime_btf(ctx: aws_executor.AwsExecutorContext, ip: str) -> bool:
    return (
        aws_executor._ssh_bash(
            ctx,
            ip,
            script="""
set -euo pipefail
test -s /sys/kernel/btf/vmlinux
""",
            check=False,
        ).returncode
        == 0
    )


def _remote_has_sched_ext(ctx: aws_executor.AwsExecutorContext, ip: str) -> bool:
    return (
        aws_executor._ssh_bash(
            ctx,
            ip,
            script="""
set -euo pipefail
test -e /sys/kernel/sched_ext/state
""",
            check=False,
        ).returncode
        == 0
    )


def _remote_base_prereq_dir(ctx: aws_executor.AwsExecutorContext) -> str:
    return f"{ctx.remote_stage_dir}/prereq/base"


def _remote_base_prereq_stamp_path(ctx: aws_executor.AwsExecutorContext) -> str:
    return f"{_remote_base_prereq_dir(ctx)}/base.ready"


def _setup_remote_base_prereqs(ctx: aws_executor.AwsExecutorContext, ip: str) -> None:
    remote_prereq_dir = _remote_base_prereq_dir(ctx)
    remote_stamp_path = _remote_base_prereq_stamp_path(ctx)
    remote_manifest = f"{remote_prereq_dir}/run-contract.env"
    remote_runner_root = f"{remote_prereq_dir}/runner"
    remote_runner_lib_root = f"{remote_runner_root}/libs"
    aws_executor._ssh_bash(
        ctx,
        ip,
        remote_prereq_dir,
        script="""
set -euo pipefail
mkdir -p "$1"
""",
    )
    aws_executor._ssh_bash(
        ctx,
        ip,
        remote_runner_lib_root,
        script="""
set -euo pipefail
mkdir -p "$1"
""",
    )
    aws_executor._scp_to(ctx, ip, ctx.manifest_path, remote_manifest)
    for rel_src, rel_dest in (
        ("runner/__init__.py", "__init__.py"),
        ("runner/libs/__init__.py", "libs/__init__.py"),
        ("runner/libs/prereq_contract.py", "libs/prereq_contract.py"),
        ("runner/libs/run_contract.py", "libs/run_contract.py"),
        ("runner/libs/aws_remote_prereqs.py", "libs/aws_remote_prereqs.py"),
    ):
        aws_executor._scp_to(ctx, ip, ROOT_DIR / rel_src, f"{remote_runner_root}/{rel_dest}")
    aws_executor._ssh_bash(
        ctx,
        ip,
        remote_prereq_dir,
        remote_manifest,
        remote_stamp_path,
        script="""
set -euo pipefail
prereq_root="$1"
manifest="$2"
stamp_path="$3"
python_bin=""
for candidate in python3 python; do
    if command -v "$candidate" >/dev/null 2>&1; then
        python_bin="$candidate"
        break
    fi
done
[[ -n "$python_bin" ]] || {
    echo "[aws-remote-prereqs][ERROR] no Python launcher is available" >&2
    exit 1
}
sudo env PATH="$PATH" PYTHONPATH="$prereq_root" \
    "$python_bin" -m runner.libs.aws_remote_prereqs "$manifest" "$stamp_path"
test -f "$stamp_path"
""",
    )


def _verify_remote_base_prereqs(ctx: aws_executor.AwsExecutorContext, ip: str) -> bool:
    return (
        aws_executor._ssh_bash(
            ctx,
            ip,
            _remote_base_prereq_stamp_path(ctx),
            script="""
set -euo pipefail
test -f "$1"
""",
            check=False,
        ).returncode
        == 0
    )


def _refresh_aws_arm64_base_config(ctx: aws_executor.AwsExecutorContext, ip: str) -> None:
    env = _kernel_helper_env(ctx)
    base_config_path = Path(env["ARM64_AWS_BASE_CONFIG"])
    remote_release = _remote_kernel_release(ctx, ip)
    if not remote_release.endswith(".amzn2023.aarch64"):
        if base_config_path.is_file():
            return
        _die(f"cannot seed AWS ARM64 base config from non-stock kernel {remote_release}; relaunch a fresh AL2023 instance")
    tmp_config = base_config_path.parent / f"{base_config_path.name}.tmp"
    completed = aws_executor._ssh_bash(
        ctx,
        ip,
        script="""
set -euo pipefail
release="$(uname -r)"
if [[ -r "/boot/config-$release" ]]; then
    cat "/boot/config-$release"
    exit 0
fi
if command -v zcat >/dev/null 2>&1 && [[ -r /proc/config.gz ]]; then
    zcat /proc/config.gz
    exit 0
fi
exit 1
""",
        check=False,
        capture_output=True,
    )
    if completed.returncode != 0:
        _die(f"failed to capture AWS ARM64 base kernel config from {ip}")
    tmp_config.parent.mkdir(parents=True, exist_ok=True)
    tmp_config.write_text(completed.stdout, encoding="utf-8")
    if "CONFIG_ARM64=y" not in completed.stdout:
        tmp_config.unlink(missing_ok=True)
        _die(f"captured AWS ARM64 base config is invalid: {tmp_config}")
    tmp_config.replace(base_config_path)


def _build_x86_kernel_artifacts(ctx: aws_executor.AwsExecutorContext) -> tuple[str, Path, Path]:
    values = _run_kernel_helper_query(
        ctx,
        body="""
build_x86_kernel_artifacts
printf 'BUILD_KERNEL_RELEASE=%s\n' "$BUILD_KERNEL_RELEASE"
printf 'KERNEL_IMAGE=%s\n' "$ARTIFACT_DIR/bzImage-$BUILD_KERNEL_RELEASE"
printf 'MODULES_TAR=%s\n' "$ARTIFACT_DIR/modules-$BUILD_KERNEL_RELEASE.tar.gz"
""",
        result_keys=("BUILD_KERNEL_RELEASE", "KERNEL_IMAGE", "MODULES_TAR"),
    )
    return (
        values["BUILD_KERNEL_RELEASE"],
        Path(values["KERNEL_IMAGE"]).resolve(),
        Path(values["MODULES_TAR"]).resolve(),
    )


def _build_arm64_kernel_artifacts(ctx: aws_executor.AwsExecutorContext) -> tuple[str, Path, Path]:
    values = _run_kernel_helper_query(
        ctx,
        body="""
build_arm64_kernel_artifacts
printf 'BUILD_KERNEL_RELEASE=%s\n' "$BUILD_KERNEL_RELEASE"
printf 'KERNEL_IMAGE=%s\n' "$ARTIFACT_DIR/vmlinuz-$BUILD_KERNEL_RELEASE.efi"
printf 'MODULES_TAR=%s\n' "$ARTIFACT_DIR/modules-$BUILD_KERNEL_RELEASE.tar.gz"
""",
        result_keys=("BUILD_KERNEL_RELEASE", "KERNEL_IMAGE", "MODULES_TAR"),
    )
    return (
        values["BUILD_KERNEL_RELEASE"],
        Path(values["KERNEL_IMAGE"]).resolve(),
        Path(values["MODULES_TAR"]).resolve(),
    )


def _setup_x86_instance(ctx: aws_executor.AwsExecutorContext, ip: str) -> None:
    state = aws_executor._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    if not instance_id:
        _die("x86 setup requires a cached instance ID")
    aws_executor._wait_for_ssh(ctx, ip)
    _setup_remote_base_prereqs(ctx, ip)
    kernel_release, kernel_image, modules_tar = _build_x86_kernel_artifacts(ctx)
    setup_stamp = f"setup_{kernel_release}_{aws_executor.datetime.now(aws_executor.timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    setup_result_dir = ctx.results_dir / setup_stamp
    verify_log = setup_result_dir / "setup_verify.log"
    setup_result_dir.mkdir(parents=True, exist_ok=True)
    aws_executor._ssh_bash(
        ctx,
        ip,
        ctx.contract.get("RUN_REMOTE_KERNEL_STAGE_DIR", ""),  # type: ignore[arg-type]
        script="""
set -euo pipefail
mkdir -p "$1/boot"
""",
    )
    remote_kernel_stage_dir = aws_executor._require_scalar(ctx.contract, "RUN_REMOTE_KERNEL_STAGE_DIR")
    aws_executor._scp_to(ctx, ip, kernel_image, f"{remote_kernel_stage_dir}/boot/")
    aws_executor._scp_to(ctx, ip, modules_tar, f"{remote_kernel_stage_dir}/")
    aws_executor._ssh_bash(
        ctx,
        ip,
        kernel_release,
        remote_kernel_stage_dir,
        script="""
set -euo pipefail
ver="$1"
stage_dir="$2"
title="Codex x86 ($ver)"
primary_netdev="$(ip -brief link | awk '$1 != "lo" { print $1; exit }')"
[[ -n "$primary_netdev" ]] || exit 1
primary_mac="$(cat "/sys/class/net/$primary_netdev/address")"
[[ -n "$primary_mac" ]] || exit 1

sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 "$stage_dir/boot/bzImage-$ver" "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force --no-hostonly --add-drivers "nvme nvme-core xfs ext4 virtio_blk" "/boot/initramfs-$ver.img" "$ver"
cat <<EOF_LINK | sudo tee /etc/systemd/network/10-codex-ena.link >/dev/null
[Match]
MACAddress=${primary_mac}

[Link]
Name=ens5
EOF_LINK
cat <<EOF_NET | sudo tee /etc/systemd/network/10-codex-ena.network >/dev/null
[Match]
MACAddress=${primary_mac}

[Network]
DHCP=yes
LinkLocalAddressing=yes
IPv6AcceptRA=yes
EOF_NET
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "/boot/vmlinuz-$ver"
""",
    )
    completed = aws_executor._aws_cmd(ctx, "ec2", "reboot-instances", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    completed = aws_executor._aws_cmd(ctx, "ec2", "wait", "instance-status-ok", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    _, _, updated_ip = aws_executor._describe_instance(ctx, instance_id)
    if not updated_ip or updated_ip == "None":
        _die(f"instance {instance_id} has no public IP after x86 reboot")
    aws_executor._wait_for_ssh(ctx, updated_ip)
    verify = aws_executor._ssh_bash(
        ctx,
        updated_ip,
        kernel_release,
        script="""
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
""",
        capture_output=True,
    )
    verify_log.write_text(verify.stdout, encoding="utf-8")
    _save_state(ctx, instance_id=instance_id, instance_ip=updated_ip, kernel_release=kernel_release)


def _setup_arm64_instance(ctx: aws_executor.AwsExecutorContext, ip: str) -> None:
    state = aws_executor._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    if not instance_id:
        _die("ARM64 setup requires a cached instance ID")
    aws_executor._wait_for_ssh(ctx, ip)
    _refresh_aws_arm64_base_config(ctx, ip)
    _setup_remote_base_prereqs(ctx, ip)
    kernel_release, kernel_image, modules_tar = _build_arm64_kernel_artifacts(ctx)
    setup_stamp = f"setup_{kernel_release}_{aws_executor.datetime.now(aws_executor.timezone.utc).strftime('%Y%m%d_%H%M%S')}"
    setup_result_dir = ctx.results_dir / setup_stamp
    verify_log = setup_result_dir / "setup_verify.log"
    setup_result_dir.mkdir(parents=True, exist_ok=True)
    remote_kernel_stage_dir = aws_executor._require_scalar(ctx.contract, "RUN_REMOTE_KERNEL_STAGE_DIR")
    aws_executor._ssh_bash(
        ctx,
        ip,
        remote_kernel_stage_dir,
        script="""
set -euo pipefail
mkdir -p "$1/boot"
""",
    )
    aws_executor._scp_to(ctx, ip, kernel_image, f"{remote_kernel_stage_dir}/boot/")
    aws_executor._scp_to(ctx, ip, modules_tar, f"{remote_kernel_stage_dir}/")
    aws_executor._ssh_bash(
        ctx,
        ip,
        kernel_release,
        remote_kernel_stage_dir,
        script="""
set -euo pipefail
ver="$1"
stage_dir="$2"
title="Codex ARM64 ($ver)"
sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 "$stage_dir/boot/vmlinuz-$ver.efi" "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force "/boot/initramfs-$ver.img" "$ver"
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "/boot/vmlinuz-$ver"
""",
    )
    completed = aws_executor._aws_cmd(ctx, "ec2", "reboot-instances", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    completed = aws_executor._aws_cmd(ctx, "ec2", "wait", "instance-status-ok", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    _, _, updated_ip = aws_executor._describe_instance(ctx, instance_id)
    if not updated_ip or updated_ip == "None":
        _die(f"instance {instance_id} has no public IP after ARM64 reboot")
    aws_executor._wait_for_ssh(ctx, updated_ip)
    verify = aws_executor._ssh_bash(
        ctx,
        updated_ip,
        kernel_release,
        script="""
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
""",
        capture_output=True,
    )
    verify_log.write_text(verify.stdout, encoding="utf-8")
    _save_state(ctx, instance_id=instance_id, instance_ip=updated_ip, kernel_release=kernel_release)


def _setup_instance(ctx: aws_executor.AwsExecutorContext, ip: str) -> None:
    if ctx.target_name == "aws-arm64":
        _setup_arm64_instance(ctx, ip)
        return
    if ctx.target_name == "aws-x86":
        _setup_x86_instance(ctx, ip)
        return
    _die(f"unsupported AWS target for setup: {ctx.target_name}")


def _launch_instance(ctx: aws_executor.AwsExecutorContext) -> None:
    key_name = aws_executor._require_scalar(ctx.contract, "RUN_AWS_KEY_NAME")
    key_path = Path(aws_executor._require_scalar(ctx.contract, "RUN_AWS_KEY_PATH")).resolve()
    security_group_id = aws_executor._require_scalar(ctx.contract, "RUN_AWS_SECURITY_GROUP_ID")
    subnet_id = aws_executor._require_scalar(ctx.contract, "RUN_AWS_SUBNET_ID")
    root_volume_gb = aws_executor._require_scalar(ctx.contract, "RUN_ROOT_VOLUME_GB")
    if not root_volume_gb.isdigit() or int(root_volume_gb) <= 0:
        _die("RUN_ROOT_VOLUME_GB must be a positive integer")
    if not key_path.is_file():
        _die(f"SSH key does not exist: {key_path}")
    ami_id = aws_executor._optional_scalar(ctx.contract, "RUN_AMI_ID")
    if not ami_id:
        ami_param = aws_executor._require_scalar(ctx.contract, "RUN_AMI_PARAM")
        completed = aws_executor._aws_cmd(
            ctx,
            "ssm",
            "get-parameter",
            "--name",
            ami_param,
            "--query",
            "Parameter.Value",
            "--output",
            "text",
            capture_output=True,
        )
        if completed.returncode != 0:
            raise SystemExit(completed.returncode)
        ami_id = completed.stdout.strip()

    state = aws_executor._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    instance_state = ""
    instance_ip = ""
    if instance_id:
        _, instance_state, instance_ip = aws_executor._describe_instance(ctx, instance_id)
        instance_type = _describe_instance_type(ctx, instance_id)
        current_image_id, current_key_name, current_subnet_id, current_security_groups = _describe_instance_launch_contract(ctx, instance_id)
        if instance_state in {"stopped", "stopping"}:
            aws_executor._terminate_instance(ctx, instance_id)
            instance_id = ""
            instance_state = ""
            instance_ip = ""
        elif instance_type != aws_executor._require_scalar(ctx.contract, "RUN_INSTANCE_TYPE"):
            aws_executor._terminate_instance(ctx, instance_id)
            instance_id = ""
            instance_state = ""
            instance_ip = ""
        elif (
            current_image_id != ami_id
            or current_key_name != key_name
            or current_subnet_id != subnet_id
            or current_security_groups != security_group_id
        ):
            aws_executor._terminate_instance(ctx, instance_id)
            instance_id = ""
            instance_state = ""
            instance_ip = ""

    if not instance_id or not _instance_state_is_reusable(instance_state):
        instance_id, instance_state, instance_ip = _lookup_existing_instance(
            ctx,
            ami_id=ami_id,
            key_name=key_name,
            security_group_id=security_group_id,
            subnet_id=subnet_id,
        )

    if not instance_id or instance_id == "None":
        root_device_name = _resolve_root_device_name(ctx, ami_id)
        completed = aws_executor._aws_cmd(
            ctx,
            "ec2",
            "run-instances",
            "--image-id",
            ami_id,
            "--instance-type",
            aws_executor._require_scalar(ctx.contract, "RUN_INSTANCE_TYPE"),
            "--key-name",
            key_name,
            "--security-group-ids",
            security_group_id,
            "--subnet-id",
            subnet_id,
            "--block-device-mappings",
            f"DeviceName={root_device_name},Ebs={{VolumeSize={root_volume_gb},VolumeType=gp3,DeleteOnTermination=true}}",
            "--tag-specifications",
            f"ResourceType=instance,Tags=[{{Key=Name,Value={_effective_name_tag(ctx)}}},{{Key=Project,Value=bpf-benchmark}},{{Key=Role,Value={ctx.target_name}}}]",
            "--count",
            "1",
            "--query",
            "Instances[0].InstanceId",
            "--output",
            "text",
            capture_output=True,
        )
        if completed.returncode != 0:
            raise SystemExit(completed.returncode)
        instance_id = completed.stdout.strip()

    _save_state(ctx, instance_id=instance_id, instance_ip=instance_ip, kernel_release=state.get("STATE_KERNEL_RELEASE", ""))
    completed = aws_executor._aws_cmd(ctx, "ec2", "wait", "instance-running", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    completed = aws_executor._aws_cmd(ctx, "ec2", "wait", "instance-status-ok", "--instance-ids", instance_id)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    _, _, instance_ip = aws_executor._describe_instance(ctx, instance_id)
    if not instance_ip or instance_ip == "None":
        _die(f"instance {instance_id} has no public IP")
    _save_state(ctx, instance_id=instance_id, instance_ip=instance_ip, kernel_release=state.get("STATE_KERNEL_RELEASE", ""))


def _ensure_instance_for_suite(ctx: aws_executor.AwsExecutorContext) -> dict[str, str]:
    if not ctx.remote_user:
        _die("manifest RUN_REMOTE_USER is empty")
    if not ctx.remote_stage_dir:
        _die("manifest RUN_REMOTE_STAGE_DIR is empty")
    if not ctx.key_path.is_file():
        _die(f"manifest RUN_AWS_KEY_PATH does not exist: {ctx.key_path}")
    with aws_executor._locked_file(ctx.state_lock):
        state = aws_executor._load_instance_state(ctx)
        if not state.get("STATE_INSTANCE_IP", "").strip():
            _launch_instance(ctx)
            state = aws_executor._load_instance_state(ctx)
        instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
        if not instance_ip:
            _die(f"failed to resolve {ctx.target_name} instance IP")
        aws_executor._wait_for_ssh(ctx, instance_ip)

        root_volume_gb = _remote_root_volume_size_gb(ctx, instance_ip)
        required_root_volume_gb = int(aws_executor._require_scalar(ctx.contract, "RUN_ROOT_VOLUME_GB"))
        if root_volume_gb is not None and root_volume_gb < required_root_volume_gb:
            aws_executor._terminate_instance(ctx, state.get("STATE_INSTANCE_ID", "").strip())
            _launch_instance(ctx)
            state = aws_executor._load_instance_state(ctx)
            instance_ip = state.get("STATE_INSTANCE_IP", "").strip()
            aws_executor._wait_for_ssh(ctx, instance_ip)

        if not state.get("STATE_KERNEL_RELEASE", "").strip():
            _setup_instance(ctx, instance_ip)
            state = aws_executor._load_instance_state(ctx)
            return state

        current_kernel = _remote_kernel_release(ctx, instance_ip)
        if current_kernel != state.get("STATE_KERNEL_RELEASE", "").strip():
            _setup_instance(ctx, instance_ip)
            state = aws_executor._load_instance_state(ctx)
            return state

        if not _verify_remote_base_prereqs(ctx, instance_ip):
            _setup_remote_base_prereqs(ctx, instance_ip)

        if aws_executor._optional_scalar(ctx.contract, "RUN_SUITE_NEEDS_RUNTIME_BTF", "0") == "1" and not _remote_has_runtime_btf(ctx, instance_ip):
            _setup_instance(ctx, instance_ip)
            state = aws_executor._load_instance_state(ctx)
            return state

        if aws_executor._optional_scalar(ctx.contract, "RUN_SUITE_NEEDS_SCHED_EXT", "0") == "1" and not _remote_has_sched_ext(ctx, instance_ip):
            _setup_instance(ctx, instance_ip)
            state = aws_executor._load_instance_state(ctx)
            return state

        return aws_executor._load_instance_state(ctx)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 2:
        _die("usage: aws_remote_prep.py <manifest_path> <state_path>")
    manifest_path = Path(args[0]).resolve()
    state_path = Path(args[1]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")
    ctx = aws_executor._build_context("run", manifest_path, None)
    state = _ensure_instance_for_suite(ctx)
    write_state(
        state_path,
        {
            "STATE_INSTANCE_ID": state.get("STATE_INSTANCE_ID", ""),
            "STATE_INSTANCE_IP": state.get("STATE_INSTANCE_IP", ""),
            "STATE_REGION": state.get("STATE_REGION", ""),
            "STATE_KERNEL_RELEASE": state.get("STATE_KERNEL_RELEASE", ""),
        },
    )


if __name__ == "__main__":
    main()
