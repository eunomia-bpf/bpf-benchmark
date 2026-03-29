#!/usr/bin/env bash
# AWS x86 benchmark workflow for Amazon Linux 2023.
#
# Usage:
#   AWS_X86_KEY_NAME=... AWS_X86_KEY_PATH=... AWS_X86_SECURITY_GROUP_ID=... AWS_X86_SUBNET_ID=... \
#     runner/scripts/aws_x86.sh full
#
# Commands:
#   launch     Launch or reuse a tagged x86 EC2 instance.
#   setup      Upload the local x86 bzImage + kernel modules, install, reboot, verify.
#   benchmark  Upload the local runner/daemon/corpus bundle, load module/x86 kinsn modules, run benchmarks.
#   terminate  Terminate the EC2 instance and clear cached state.
#   full       launch -> setup -> benchmark -> terminate, with EXIT cleanup if setup/benchmark fails.
#
# Local inputs:
#   - kernel image: vendor/linux-framework/arch/x86/boot/bzImage
#   - runner binary: runner/build/micro_exec
#   - daemon binary: daemon/target/release/bpfrejit-daemon
#   - kinsn modules: module/x86/*.ko
#   - smoke corpus: corpus/build/katran/balancer.bpf.o
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
CACHE_DIR="${AWS_X86_CACHE_DIR:-$ROOT_DIR/.cache/aws-x86}"
ARTIFACT_DIR="$CACHE_DIR/artifacts"
STATE_DIR="$CACHE_DIR/state"
STATE_FILE="$STATE_DIR/instance.env"
RESULTS_DIR="$CACHE_DIR/results"
MODULES_STAGE_DIR="$CACHE_DIR/modules-stage"
BENCHMARK_BUNDLE_DIR="$CACHE_DIR/benchmark-bundle"
BENCHMARK_BUNDLE_TAR="$CACHE_DIR/benchmark-bundle.tar.gz"
KERNEL_RELEASE_FILE="$CACHE_DIR/kernel-release"

AWS_X86_NAME_TAG="${AWS_X86_NAME_TAG:-bpf-benchmark-x86}"
AWS_X86_INSTANCE_TYPE="${AWS_X86_INSTANCE_TYPE:-t3.micro}"
AWS_X86_ROOT_VOLUME_SIZE_GB="${AWS_X86_ROOT_VOLUME_SIZE_GB:-32}"
AWS_X86_PROFILE="${AWS_X86_PROFILE:-codex-ec2}"
AWS_X86_REMOTE_USER="${AWS_X86_REMOTE_USER:-ec2-user}"
AWS_X86_REMOTE_STAGE_DIR="${AWS_X86_REMOTE_STAGE_DIR:-/home/${AWS_X86_REMOTE_USER}/bpf-benchmark-x86}"
AWS_X86_REMOTE_KERNEL_STAGE_DIR="${AWS_X86_REMOTE_KERNEL_STAGE_DIR:-/home/${AWS_X86_REMOTE_USER}/codex-kernel-stage-x86}"
AWS_X86_AMI_PARAM="${AWS_X86_AMI_PARAM:-/aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-x86_64}"
AWS_X86_BENCH_ITERATIONS="${AWS_X86_BENCH_ITERATIONS:-1}"
AWS_X86_BENCH_WARMUPS="${AWS_X86_BENCH_WARMUPS:-0}"
AWS_X86_BENCH_REPEAT="${AWS_X86_BENCH_REPEAT:-10}"
AWS_X86_BENCH_CPU="${AWS_X86_BENCH_CPU:-0}"
AWS_X86_REMOTE_RESULT_JSON="${AWS_X86_REMOTE_RESULT_JSON:-x86_t3_micro.json}"
AWS_REGION_VALUE="${AWS_REGION:-${AWS_DEFAULT_REGION:-}}"

KERNEL_DIR="${KERNEL_DIR:-$ROOT_DIR/vendor/linux-framework}"
KERNEL_BUILD_LOCK_FILE="${KERNEL_BUILD_LOCK_FILE:-$ROOT_DIR/.cache/kernel-build.lock}"
KERNEL_CONFIG_STAMP_FILE="$KERNEL_DIR/.bpfrejit_config.stamp"
KERNEL_DEFCONFIG_SRC="$ROOT_DIR/vendor/bpfrejit_defconfig"
X86_BZIMAGE="${X86_BZIMAGE:-$KERNEL_DIR/arch/x86/boot/bzImage}"
X86_VMLINUX="${X86_VMLINUX:-$KERNEL_DIR/vmlinux}"
X86_RUNNER="${X86_RUNNER:-$ROOT_DIR/runner/build/micro_exec}"
X86_DAEMON="${X86_DAEMON:-$ROOT_DIR/daemon/target/release/bpfrejit-daemon}"
X86_KINSN_MODULE_DIR="${X86_KINSN_MODULE_DIR:-$ROOT_DIR/module/x86}"
X86_KINSN_LOAD_SCRIPT="${X86_KINSN_LOAD_SCRIPT:-$ROOT_DIR/module/load_all.sh}"
SMOKE_CORPUS_OBJECT="${SMOKE_CORPUS_OBJECT:-$ROOT_DIR/corpus/build/katran/balancer.bpf.o}"

STATE_INSTANCE_ID=""
STATE_INSTANCE_IP=""
STATE_REGION=""
STATE_KEY_PATH=""
STATE_KEY_NAME=""
STATE_KERNEL_RELEASE=""
FULL_LIFECYCLE_INSTANCE_ID=""
FULL_LIFECYCLE_LAUNCH_OUTPUT=""
FULL_LIFECYCLE_CLEANUP_RUNNING=0
FULL_LIFECYCLE_CLEANUP_TOKEN=""
FULL_LIFECYCLE_WATCHER_PID=""
AWS_X86_KERNEL_CACHE_VERSION=3

log() {
    printf '[aws-x86] %s\n' "$*" >&2
}

warn() {
    printf '[aws-x86][WARN] %s\n' "$*" >&2
}

die() {
    printf '[aws-x86][ERROR] %s\n' "$*" >&2
    exit 1
}

usage() {
    cat <<'EOF'
usage: aws_x86.sh <launch|setup|benchmark|terminate|full> [arg]

Commands:
  launch               Launch or reuse a tagged EC2 x86 instance.
  setup <instance_ip>  Upload/install the local x86 kernel + modules, reboot, verify.
  benchmark <ip>       Upload local x86 binaries/modules and run smoke benchmarks.
  terminate <id>       Terminate the EC2 instance and clear cached state.
  full                 Launch -> setup -> benchmark -> terminate, with EXIT cleanup.

Required env for launch/full:
  AWS_X86_KEY_NAME
  AWS_X86_KEY_PATH
  AWS_X86_SECURITY_GROUP_ID
  AWS_X86_SUBNET_ID

Optional env:
  AWS_X86_PROFILE              default: codex-ec2
  AWS_REGION / AWS_DEFAULT_REGION
                               override region instead of profile config
  AWS_X86_INSTANCE_TYPE        default: t3.micro
  AWS_X86_ROOT_VOLUME_SIZE_GB  default: 32
  AWS_X86_NAME_TAG             default: bpf-benchmark-x86
  AWS_X86_AMI_ID               override the AL2023 x86_64 AMI
  AWS_X86_BENCH_ITERATIONS     default: 1
  AWS_X86_BENCH_WARMUPS        default: 0
  AWS_X86_BENCH_REPEAT         default: 10
EOF
}

ensure_dirs() {
    mkdir -p "$CACHE_DIR" "$STATE_DIR" "$RESULTS_DIR"
}

with_kernel_lock() (
    mkdir -p "$(dirname "$KERNEL_BUILD_LOCK_FILE")"
    exec 9>"$KERNEL_BUILD_LOCK_FILE"
    flock 9
    "$@"
)

load_state() {
    if [[ -f "$STATE_FILE" ]]; then
        # shellcheck disable=SC1090
        source "$STATE_FILE"
    fi
}

save_state() {
    ensure_dirs
    local instance_id="$1"
    local instance_ip="$2"
    local region="$3"
    local key_path="$4"
    local key_name="$5"
    local kernel_release="${6:-}"
    cat >"$STATE_FILE" <<EOF
STATE_INSTANCE_ID=$(printf '%q' "$instance_id")
STATE_INSTANCE_IP=$(printf '%q' "$instance_ip")
STATE_REGION=$(printf '%q' "$region")
STATE_KEY_PATH=$(printf '%q' "$key_path")
STATE_KEY_NAME=$(printf '%q' "$key_name")
STATE_KERNEL_RELEASE=$(printf '%q' "$kernel_release")
EOF
}

clear_state() {
    rm -f "$STATE_FILE"
}

resolve_region() {
    if [[ -n "$AWS_REGION_VALUE" ]]; then
        printf '%s\n' "$AWS_REGION_VALUE"
        return
    fi
    if region="$(_aws configure get region 2>/dev/null)" && [[ -n "$region" ]]; then
        printf '%s\n' "$region"
        return
    fi
    die "AWS region is unset. Export AWS_REGION/AWS_DEFAULT_REGION or configure region in profile ${AWS_X86_PROFILE}."
}

_aws() {
    AWS_PAGER="" aws --profile "$AWS_X86_PROFILE" "$@"
}

aws_cmd() {
    local region="$1"
    shift
    _aws --region "$region" "$@"
}

ensure_aws_identity() {
    local region
    region="$(resolve_region)"
    aws_cmd "$region" sts get-caller-identity >/dev/null
}

list_instances() {
    local region="${1:-$(resolve_region)}"
    log "Checking for residual EC2 instances in ${region}"
    aws_cmd "$region" ec2 describe-instances \
        --filters Name=instance-state-name,Values=pending,running,stopping,stopped \
        --query 'Reservations[].Instances[].[InstanceId,InstanceType,State.Name]' \
        --output table || true
}

list_tagged_instances() {
    local region="${1:-$(resolve_region)}"
    log "Checking tagged ${AWS_X86_NAME_TAG} instances in ${region}"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${AWS_X86_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].[InstanceId,InstanceType,State.Name,PublicIpAddress]' \
        --output table || true
}

ensure_no_tagged_instances() {
    local region="${1:-$(resolve_region)}"
    local instance_ids
    instance_ids="$(aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${AWS_X86_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].InstanceId' \
        --output text 2>/dev/null || true)"
    if [[ -n "$instance_ids" && "$instance_ids" != "None" ]]; then
        die "Residual ${AWS_X86_NAME_TAG} instances remain: ${instance_ids}"
    fi
}

preflight_instance_check() {
    ensure_aws_identity
    list_instances "$(resolve_region)"
    list_tagged_instances "$(resolve_region)"
}

require_env_var() {
    local name="$1"
    local value="${!name:-}"
    [[ -n "$value" ]] || die "$name is required"
}

current_key_path() {
    local key_path="${AWS_X86_KEY_PATH:-${STATE_KEY_PATH:-}}"
    [[ -n "$key_path" ]] || die "AWS_X86_KEY_PATH is required for SSH operations"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"
    printf '%s\n' "$key_path"
}

ssh_base_args() {
    local key_path
    key_path="$(current_key_path)"
    printf '%s\0' \
        -i "$key_path" \
        -o StrictHostKeyChecking=no \
        -o UserKnownHostsFile=/dev/null \
        -o ConnectTimeout=10 \
        -o ServerAliveInterval=30 \
        -o ServerAliveCountMax=20
}

ssh_bash() {
    local ip="$1"
    shift
    local target="${AWS_X86_REMOTE_USER}@${ip}"
    local cmd="bash -s --"
    local arg
    while (($#)); do
        arg="$1"
        cmd+=" $(printf '%q' "$arg")"
        shift
    done
    local ssh_args=()
    while IFS= read -r -d '' value; do
        ssh_args+=("$value")
    done < <(ssh_base_args)
    ssh "${ssh_args[@]}" "$target" "$cmd"
}

scp_to() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    local target="${AWS_X86_REMOTE_USER}@${ip}:${dest}"
    local scp_args=(-q)
    while IFS= read -r -d '' value; do
        scp_args+=("$value")
    done < <(ssh_base_args)
    scp "${scp_args[@]}" "$src" "$target"
}

scp_from() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    local target="${AWS_X86_REMOTE_USER}@${ip}:${src}"
    local scp_args=(-q)
    while IFS= read -r -d '' value; do
        scp_args+=("$value")
    done < <(ssh_base_args)
    scp "${scp_args[@]}" "$target" "$dest"
}

wait_for_ssh() {
    local ip="$1"
    local attempt
    for attempt in $(seq 1 60); do
        if ssh_bash "$ip" <<'EOF' >/dev/null 2>&1
set -euo pipefail
true
EOF
        then
            return 0
        fi
        sleep 5
    done
    die "SSH did not become ready on ${ip}"
}

lookup_existing_instance() {
    local region="$1"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${AWS_X86_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running" \
        --query 'Reservations[].Instances[0].[InstanceId,State.Name,PublicIpAddress]' \
        --output text 2>/dev/null || true
}

describe_instance() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query 'Reservations[0].Instances[0].[InstanceId,State.Name,PublicIpAddress]' \
        --output text 2>/dev/null || true
}

resolve_root_device_name() {
    local region="$1"
    local ami_id="$2"
    local root_device_name
    root_device_name="$(aws_cmd "$region" ec2 describe-images \
        --image-ids "$ami_id" \
        --query 'Images[0].RootDeviceName' \
        --output text)"
    [[ -n "$root_device_name" && "$root_device_name" != "None" ]] \
        || die "AMI ${ami_id} has no root device name"
    printf '%s\n' "$root_device_name"
}

launch_instance() {
    ensure_dirs
    load_state
    ensure_aws_identity

    require_env_var AWS_X86_KEY_NAME
    require_env_var AWS_X86_KEY_PATH
    require_env_var AWS_X86_SECURITY_GROUP_ID
    require_env_var AWS_X86_SUBNET_ID

    local region key_path key_name instance_id="" instance_state="" instance_ip="" ami_id root_device_name
    region="$(resolve_region)"
    key_path="${AWS_X86_KEY_PATH}"
    key_name="${AWS_X86_KEY_NAME}"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"
    [[ "$AWS_X86_ROOT_VOLUME_SIZE_GB" =~ ^[1-9][0-9]*$ ]] \
        || die "AWS_X86_ROOT_VOLUME_SIZE_GB must be a positive integer"

    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$STATE_INSTANCE_ID")"
    fi

    if [[ -z "$instance_id" || "$instance_id" == "None" || "$instance_state" == "terminated" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(lookup_existing_instance "$region")"
    fi

    if [[ -n "$instance_id" && "$instance_id" != "None" ]]; then
        log "Reusing existing EC2 instance ${instance_id} (${instance_state})"
    else
        if [[ -n "${AWS_X86_AMI_ID:-}" ]]; then
            ami_id="${AWS_X86_AMI_ID}"
        else
            ami_id="$(aws_cmd "$region" ssm get-parameter \
                --name "$AWS_X86_AMI_PARAM" \
                --query 'Parameter.Value' \
                --output text)"
        fi
        root_device_name="$(resolve_root_device_name "$region" "$ami_id")"

        log "Launching ${AWS_X86_INSTANCE_TYPE} in ${region} using AMI ${ami_id} with ${AWS_X86_ROOT_VOLUME_SIZE_GB}GB root volume"
        instance_id="$(aws_cmd "$region" ec2 run-instances \
            --image-id "$ami_id" \
            --instance-type "$AWS_X86_INSTANCE_TYPE" \
            --key-name "$key_name" \
            --block-device-mappings "DeviceName=${root_device_name},Ebs={DeleteOnTermination=true,VolumeSize=${AWS_X86_ROOT_VOLUME_SIZE_GB},VolumeType=gp3}" \
            --security-group-ids "$AWS_X86_SECURITY_GROUP_ID" \
            --subnet-id "$AWS_X86_SUBNET_ID" \
            --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${AWS_X86_NAME_TAG}},{Key=Project,Value=bpf-benchmark},{Key=Role,Value=x86-baremetal}]" \
            --count 1 \
            --query 'Instances[0].InstanceId' \
            --output text)"
    fi

    log "Waiting for instance ${instance_id} to enter running state"
    aws_cmd "$region" ec2 wait instance-running --instance-ids "$instance_id"
    log "Waiting for instance ${instance_id} status checks"
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$instance_ip" && "$instance_ip" != "None" ]] || die "Instance ${instance_id} has no public IP"

    save_state "$instance_id" "$instance_ip" "$region" "$key_path" "$key_name" "${STATE_KERNEL_RELEASE:-}"

    printf 'INSTANCE_ID=%s\n' "$instance_id"
    printf 'INSTANCE_IP=%s\n' "$instance_ip"
    printf 'AWS_REGION=%s\n' "$region"
}

require_kernel_config_value() {
    local config_file="$1"
    local key="$2"
    local expected="$3"
    rg -qx "${key}=${expected}" "$config_file" >/dev/null \
        || die "kernel config ${key} must be ${expected} in ${config_file}"
}

require_kernel_module_artifact() {
    local modules_root="$1"
    local module_path="$2"
    local candidate
    for candidate in \
        "$modules_root/$module_path" \
        "$modules_root/$module_path.zst" \
        "$modules_root/$module_path.xz" \
        "$modules_root/$module_path.gz"; do
        if [[ -f "$candidate" ]]; then
            return
        fi
    done
    die "kernel module artifact missing from ${modules_root}: ${module_path}{,.zst,.xz,.gz}"
}

x86_kernel_manifest_path() {
    local kernel_release="$1"
    printf '%s\n' "$ARTIFACT_DIR/manifest-${kernel_release}.env"
}

cached_x86_kernel_artifacts_ready() {
    local kernel_release="$1"
    local manifest
    manifest="$(x86_kernel_manifest_path "$kernel_release")"
    [[ -f "$manifest" ]] || return 1
    rg -qx "AWS_X86_KERNEL_CACHE_VERSION=${AWS_X86_KERNEL_CACHE_VERSION}" "$manifest" >/dev/null || return 1
}

write_x86_kernel_manifest() {
    local kernel_release="$1"
    local manifest
    manifest="$(x86_kernel_manifest_path "$kernel_release")"
    cat >"$manifest" <<EOF
AWS_X86_KERNEL_CACHE_VERSION=${AWS_X86_KERNEL_CACHE_VERSION}
AWS_X86_CONFIG_NET_VENDOR_AMAZON=y
AWS_X86_CONFIG_ENA_ETHERNET=m
AWS_X86_CONFIG_NVME_CORE=m
AWS_X86_CONFIG_BLK_DEV_NVME=m
AWS_X86_CONFIG_XFS_FS=m
AWS_X86_CONFIG_EXT4_FS=m
AWS_X86_CONFIG_VIRTIO_NET=m
AWS_X86_CONFIG_VIRTIO_BLK=m
EOF
}

_prepare_x86_aws_config_locked() {
    local config_file="$KERNEL_DIR/.config"
    local config_script="$KERNEL_DIR/scripts/config"

    [[ -f "$KERNEL_DEFCONFIG_SRC" ]] || die "x86 defconfig missing: ${KERNEL_DEFCONFIG_SRC}"
    [[ -x "$config_script" ]] || die "kernel config helper missing: ${config_script}"

    if [[ ! -f "$config_file" ]]; then
        cp "$KERNEL_DEFCONFIG_SRC" "$config_file"
    elif ! diff -q "$KERNEL_DEFCONFIG_SRC" "$config_file" >/dev/null 2>&1; then
        cp "$KERNEL_DEFCONFIG_SRC" "$config_file"
    fi

    "$config_script" --file "$config_file" \
        --enable UNWINDER_ORC \
        --disable UNWINDER_FRAME_POINTER \
        --disable DEBUG_INFO_BTF_MODULES \
        --set-str SYSTEM_TRUSTED_KEYS "" \
        --set-str SYSTEM_REVOCATION_KEYS "" \
        --enable NET_VENDOR_AMAZON \
        --module ENA_ETHERNET \
        --module NVME_CORE \
        --module BLK_DEV_NVME \
        --module XFS_FS \
        --module EXT4_FS \
        --module VIRTIO_NET \
        --module VIRTIO_BLK
    rm -f "$KERNEL_CONFIG_STAMP_FILE"
    make -C "$KERNEL_DIR" olddefconfig >/dev/null

    require_kernel_config_value "$config_file" "CONFIG_NET_VENDOR_AMAZON" "y"
    require_kernel_config_value "$config_file" "CONFIG_ENA_ETHERNET" "m"
    require_kernel_config_value "$config_file" "CONFIG_NVME_CORE" "m"
    require_kernel_config_value "$config_file" "CONFIG_BLK_DEV_NVME" "m"
    require_kernel_config_value "$config_file" "CONFIG_XFS_FS" "m"
    require_kernel_config_value "$config_file" "CONFIG_EXT4_FS" "m"
    require_kernel_config_value "$config_file" "CONFIG_VIRTIO_NET" "m"
    require_kernel_config_value "$config_file" "CONFIG_VIRTIO_BLK" "m"
}

prepare_x86_aws_config() {
    with_kernel_lock _prepare_x86_aws_config_locked
}

_build_local_x86_kernel_after_config_locked() {
    log "Building local x86 kernel image"
    make -C "$KERNEL_DIR" -j"$(nproc)" bzImage modules_prepare >/dev/null
    if [[ -f "$KERNEL_DIR/vmlinux.symvers" ]]; then
        cp "$KERNEL_DIR/vmlinux.symvers" "$KERNEL_DIR/Module.symvers"
    fi
}

_build_local_x86_kernel_locked() {
    _prepare_x86_aws_config_locked
    _build_local_x86_kernel_after_config_locked
}

build_local_x86_kernel() {
    with_kernel_lock _build_local_x86_kernel_locked
}

_build_kernel_artifacts_locked() {
    _prepare_x86_aws_config_locked
    if [[ -f "$KERNEL_RELEASE_FILE" ]]; then
        local cached_release cached_vmlinux cached_image cached_modules
        cached_release="$(<"$KERNEL_RELEASE_FILE")"
        cached_vmlinux="$ARTIFACT_DIR/vmlinux-$cached_release"
        cached_image="$ARTIFACT_DIR/bzImage-$cached_release"
        cached_modules="$ARTIFACT_DIR/modules-$cached_release.tar.gz"
        if [[ -f "$cached_vmlinux" && -f "$cached_image" && -f "$cached_modules" ]] && \
            cached_x86_kernel_artifacts_ready "$cached_release"; then
            log "Reusing cached x86 kernel artifacts for ${cached_release}"
            printf '%s\n' "$cached_release"
            return
        fi
    fi

    _build_local_x86_kernel_after_config_locked

    log "Building local x86 kernel modules"
    rm -f "$KERNEL_DIR/modules.order"
    make -C "$KERNEL_DIR" -j"$(nproc)" modules >/dev/null

    local version_file="$KERNEL_DIR/include/config/kernel.release"
    [[ -f "$version_file" ]] || die "kernel release file missing: $version_file"
    local kernel_release
    kernel_release="$(<"$version_file")"
    mkdir -p "$ARTIFACT_DIR"
    rm -rf "$MODULES_STAGE_DIR"
    mkdir -p "$MODULES_STAGE_DIR"
    make -C "$KERNEL_DIR" INSTALL_MOD_PATH="$MODULES_STAGE_DIR" modules_install >/dev/null
    rm -f "$MODULES_STAGE_DIR/lib/modules/$kernel_release/build" \
          "$MODULES_STAGE_DIR/lib/modules/$kernel_release/source"
    local modules_root="$MODULES_STAGE_DIR/lib/modules/$kernel_release"
    require_kernel_module_artifact "$modules_root" "kernel/drivers/net/ethernet/amazon/ena/ena.ko"
    require_kernel_module_artifact "$modules_root" "kernel/drivers/nvme/host/nvme-core.ko"
    require_kernel_module_artifact "$modules_root" "kernel/drivers/nvme/host/nvme.ko"
    require_kernel_module_artifact "$modules_root" "kernel/fs/ext4/ext4.ko"
    require_kernel_module_artifact "$modules_root" "kernel/fs/xfs/xfs.ko"
    require_kernel_module_artifact "$modules_root" "kernel/drivers/net/virtio_net.ko"
    require_kernel_module_artifact "$modules_root" "kernel/drivers/block/virtio_blk.ko"

    cp "$X86_VMLINUX" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    cp "$X86_BZIMAGE" "$ARTIFACT_DIR/bzImage-$kernel_release"
    tar -C "$MODULES_STAGE_DIR" -czf "$ARTIFACT_DIR/modules-$kernel_release.tar.gz" lib/modules
    printf '%s\n' "$kernel_release" > "$KERNEL_RELEASE_FILE"
    write_x86_kernel_manifest "$kernel_release"

    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        save_state "$STATE_INSTANCE_ID" "${STATE_INSTANCE_IP:-}" "${STATE_REGION:-${AWS_REGION_VALUE:-}}" \
            "${STATE_KEY_PATH:-${AWS_X86_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_X86_KEY_NAME:-}}" \
            "$kernel_release"
    fi

    printf '%s\n' "$kernel_release"
}

build_kernel_artifacts() {
    ensure_dirs
    with_kernel_lock _build_kernel_artifacts_locked
}

ensure_remote_runtime_prereqs() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
sudo dnf -y install \
    bpftool \
    dracut \
    elfutils-libelf \
    grubby \
    gzip \
    kmod \
    ncurses-libs \
    python3 \
    python3.11 \
    python3.11-pip \
    tar \
    util-linux \
    zlib \
    zstd >/dev/null
if ! rpm -q python3.11-pyyaml >/dev/null 2>&1; then
    if ! sudo dnf -y install python3.11-pyyaml >/dev/null 2>&1; then
        sudo python3.11 -m pip install --quiet PyYAML >/dev/null
    fi
fi
command -v bpftool >/dev/null
command -v dracut >/dev/null
command -v grubby >/dev/null
command -v python3 >/dev/null
command -v python3.11 >/dev/null
command -v insmod >/dev/null
python3.11 -c 'import yaml' >/dev/null
command -v taskset >/dev/null
EOF
}

setup_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "setup requires an instance IP"

    load_state
    log "Waiting for SSH on ${ip}"
    wait_for_ssh "$ip"
    ensure_remote_runtime_prereqs "$ip"

    local kernel_release kernel_image modules_tar verify_log kernel_release_output
    kernel_release_output="$(mktemp "${TMPDIR:-/tmp}/aws-x86-kernel-release.XXXXXX")"
    build_kernel_artifacts >"$kernel_release_output"
    kernel_release="$(<"$kernel_release_output")"
    rm -f "$kernel_release_output"
    kernel_image="$ARTIFACT_DIR/bzImage-$kernel_release"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    verify_log="$RESULTS_DIR/setup_verify_${kernel_release}_$(date -u +%Y%m%d_%H%M%S).log"

    ssh_bash "$ip" "$AWS_X86_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
stage_dir="$1"
mkdir -p "$stage_dir/boot"
EOF

    scp_to "$ip" "$kernel_image" "$AWS_X86_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$AWS_X86_REMOTE_KERNEL_STAGE_DIR/"

    log "Installing kernel ${kernel_release} on ${ip}"
    ssh_bash "$ip" "$kernel_release" "$AWS_X86_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
ver="$1"
stage_dir="$2"
stock="/boot/vmlinuz-$(uname -r)"
title="Codex x86 ($ver)"

sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 \
    "$stage_dir/boot/bzImage-$ver" \
    "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force "/boot/initramfs-$ver.img" "$ver"
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "$stock"
sudo grub2-reboot "$title"
sudo nohup bash -c 'sleep 1; systemctl reboot' >/dev/null 2>&1 &
EOF

    sleep 15
    wait_for_ssh "$ip"
    log "Verifying rebooted kernel on ${ip}"
    ssh_bash "$ip" "$kernel_release" <<'EOF' | tee "$verify_log"
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
sudo grub2-editenv list || true
test "$(uname -r)" = "$ver"
EOF

    save_state "${STATE_INSTANCE_ID:-}" "$ip" "${STATE_REGION:-${AWS_REGION_VALUE:-}}" \
        "${STATE_KEY_PATH:-${AWS_X86_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_X86_KEY_NAME:-}}" \
        "$kernel_release"
    log "Setup verification log: ${verify_log}"
}

require_local_path() {
    local path="$1"
    local description="$2"
    [[ -e "$path" ]] || die "${description} not found: ${path}"
}

ensure_local_runner() {
    if [[ ! -x "$X86_RUNNER" ]]; then
        log "Building local x86 runner"
        make -C "$ROOT_DIR" runner >/dev/null
    fi
    file "$X86_RUNNER" | grep -F "x86-64" >/dev/null \
        || die "local micro_exec is not an x86_64 binary: ${X86_RUNNER}"
}

ensure_local_daemon() {
    if [[ ! -x "$X86_DAEMON" ]]; then
        log "Building local x86 daemon"
        make -C "$ROOT_DIR" daemon >/dev/null
    fi
    file "$X86_DAEMON" | grep -F "x86-64" >/dev/null \
        || die "local daemon is not an x86_64 binary: ${X86_DAEMON}"
}

ensure_local_kinsn_modules() {
    log "Ensuring local x86 kinsn modules are built"
    build_local_x86_kernel
    [[ -f "$KERNEL_DIR/Module.symvers" ]] || die "kernel Module.symvers missing: ${KERNEL_DIR}/Module.symvers"
    make -C "$ROOT_DIR/module/x86" KDIR="$KERNEL_DIR" >/dev/null
    local ko_count
    ko_count="$(find "$X86_KINSN_MODULE_DIR" -maxdepth 1 -name '*.ko' | wc -l | tr -d ' ')"
    [[ "$ko_count" -gt 0 ]] || die "no x86 kinsn modules found under ${X86_KINSN_MODULE_DIR}"
}

stage_runtime_libs() {
    local binary="$1"
    local dest_dir="$2"
    mkdir -p "$dest_dir"
    local dep
    while IFS= read -r dep; do
        [[ -n "$dep" ]] || continue
        case "$dep" in
            not\ found:*)
                die "missing runtime library for ${binary}: ${dep#not found:}"
                ;;
            */ld-linux-*.so*|*/libc.so.*|*/libm.so.*)
                continue
                ;;
        esac
        [[ -f "$dep" ]] || continue
        cp -L "$dep" "$dest_dir/"
    done < <(ldd "$binary" | awk '
        /=> not found/ { print "not found:" $1; next }
        /=>/ { print $3; next }
        /^\// { print $1 }
    ')
}

ensure_benchmark_bundle() {
    log "Preparing local x86 benchmark bundle"
    ensure_local_runner
    ensure_local_daemon
    ensure_local_kinsn_modules
    make -C "$ROOT_DIR/micro" programs >/dev/null

    require_local_path "$ROOT_DIR/micro/driver.py" "micro driver"
    require_local_path "$ROOT_DIR/runner/libs/catalog.py" "shared benchmark catalog"
    require_local_path "$ROOT_DIR/micro/config/micro_pure_jit.yaml" "micro suite manifest"
    require_local_path "$ROOT_DIR/micro/programs/simple.bpf.o" "simple micro object"
    require_local_path "$ROOT_DIR/runner/libs/__init__.py" "runner python helpers"
    require_local_path "$ROOT_DIR/runner/scripts/x86_remote_benchmark.py" "x86 remote benchmark runner"
    require_local_path "$SMOKE_CORPUS_OBJECT" "daemon smoke object"
    require_local_path "$X86_KINSN_LOAD_SCRIPT" "kinsn module loader"

    rm -rf "$BENCHMARK_BUNDLE_DIR"
    mkdir -p \
        "$BENCHMARK_BUNDLE_DIR/runner/libs" \
        "$BENCHMARK_BUNDLE_DIR/runner/scripts" \
        "$BENCHMARK_BUNDLE_DIR/runner/build" \
        "$BENCHMARK_BUNDLE_DIR/daemon/target/release" \
        "$BENCHMARK_BUNDLE_DIR/lib" \
        "$BENCHMARK_BUNDLE_DIR/micro/programs" \
        "$BENCHMARK_BUNDLE_DIR/micro/generated-inputs" \
        "$BENCHMARK_BUNDLE_DIR/micro/config" \
        "$BENCHMARK_BUNDLE_DIR/corpus/build/katran" \
        "$BENCHMARK_BUNDLE_DIR/module/x86"

    cp "$X86_RUNNER" "$BENCHMARK_BUNDLE_DIR/runner/build/micro_exec"
    cp "$X86_DAEMON" "$BENCHMARK_BUNDLE_DIR/daemon/target/release/bpfrejit-daemon"
    stage_runtime_libs "$X86_RUNNER" "$BENCHMARK_BUNDLE_DIR/lib"
    stage_runtime_libs "$X86_DAEMON" "$BENCHMARK_BUNDLE_DIR/lib"

    cp "$ROOT_DIR"/micro/*.py "$BENCHMARK_BUNDLE_DIR/micro/"
    cp -a "$ROOT_DIR/micro/config/." "$BENCHMARK_BUNDLE_DIR/micro/config/"
    cp -a "$ROOT_DIR/micro/programs/." "$BENCHMARK_BUNDLE_DIR/micro/programs/"
    cp -a "$ROOT_DIR/micro/generated-inputs/." "$BENCHMARK_BUNDLE_DIR/micro/generated-inputs/"

    cp -a "$ROOT_DIR/runner/libs/." "$BENCHMARK_BUNDLE_DIR/runner/libs/"
    cp "$ROOT_DIR/runner/scripts/x86_remote_benchmark.py" \
        "$BENCHMARK_BUNDLE_DIR/runner/scripts/"

    cp "$SMOKE_CORPUS_OBJECT" "$BENCHMARK_BUNDLE_DIR/corpus/build/katran/balancer.bpf.o"
    cp "$X86_KINSN_LOAD_SCRIPT" "$BENCHMARK_BUNDLE_DIR/module/load_all.sh"
    cp "$X86_KINSN_MODULE_DIR"/*.ko "$BENCHMARK_BUNDLE_DIR/module/x86/"

    tar -C "$BENCHMARK_BUNDLE_DIR" -czf "$BENCHMARK_BUNDLE_TAR" .
}

benchmark_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "benchmark requires an instance IP"

    load_state
    ensure_benchmark_bundle
    wait_for_ssh "$ip"

    local stamp local_bundle_dir local_archive
    stamp="$(date -u +%Y%m%d_%H%M%S)"
    local_bundle_dir="$RESULTS_DIR/benchmark_${stamp}"
    local_archive="$RESULTS_DIR/benchmark_${stamp}.tar.gz"
    mkdir -p "$local_bundle_dir"

    ssh_bash "$ip" "$AWS_X86_REMOTE_STAGE_DIR" <<'EOF'
set -euo pipefail
root="$1"
rm -rf "$root"
mkdir -p "$root/results"
EOF
    scp_to "$ip" "$BENCHMARK_BUNDLE_TAR" "$AWS_X86_REMOTE_STAGE_DIR/"

    log "Running full x86 benchmark suite on ${ip}"
    ssh_bash "$ip" "$AWS_X86_REMOTE_STAGE_DIR" \
        "$AWS_X86_BENCH_ITERATIONS" "$AWS_X86_BENCH_WARMUPS" "$AWS_X86_BENCH_REPEAT" \
        "$AWS_X86_BENCH_CPU" "$AWS_X86_REMOTE_RESULT_JSON" "$STATE_INSTANCE_ID" \
        "$AWS_X86_INSTANCE_TYPE" "$AWS_X86_PROFILE" "$(resolve_region)" <<'EOF'
set -euo pipefail
root="$1"
iterations="$2"
warmups="$3"
repeat="$4"
cpu="$5"
result_json="$6"
instance_id="$7"
instance_type="$8"
aws_profile="$9"
aws_region="${10}"
results_dir="$root/results"

cd "$root"
tar -xzf benchmark-bundle.tar.gz
mkdir -p "$results_dir"

sudo -n env PATH="/usr/sbin:/usr/bin:/sbin:/bin:${PATH}" \
    bash "$root/module/load_all.sh"

sudo -n env \
    PATH="/usr/sbin:/usr/bin:/sbin:/bin:${PATH}" \
    LD_LIBRARY_PATH="$root/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" \
    PYTHONPATH="$root" \
    python3.11 "$root/runner/scripts/x86_remote_benchmark.py" \
        --output "$results_dir/$result_json" \
        --iterations "$iterations" \
        --warmups "$warmups" \
        --repeat "$repeat" \
        --cpu "$cpu" \
        --instance-id "$instance_id" \
        --instance-type "$instance_type" \
        --aws-profile "$aws_profile" \
        --aws-region "$aws_region"

sudo -n chown -R "$(id -un):$(id -gn)" "$results_dir"

tar -C "$root" -czf "$root/results.tar.gz" results
EOF

    scp_from "$ip" "$AWS_X86_REMOTE_STAGE_DIR/results.tar.gz" "$local_archive"
    tar -xzf "$local_archive" -C "$local_bundle_dir"
    log "Benchmark results: ${local_bundle_dir}/results/"
}

terminate_instance() {
    local instance_id="${1:-${STATE_INSTANCE_ID:-}}"
    [[ -n "$instance_id" ]] || die "terminate requires an instance ID"

    load_state
    ensure_aws_identity
    local region
    region="$(resolve_region)"

    log "Terminating instance ${instance_id}"
    aws_cmd "$region" ec2 terminate-instances --instance-ids "$instance_id" >/dev/null
    aws_cmd "$region" ec2 wait instance-terminated --instance-ids "$instance_id"

    if [[ "$instance_id" == "${STATE_INSTANCE_ID:-}" ]]; then
        clear_state
    fi

    list_instances "$region"
    list_tagged_instances "$region"
    ensure_no_tagged_instances "$region"
}

full_lifecycle_cleanup_instance_id() {
    if [[ -n "${FULL_LIFECYCLE_INSTANCE_ID:-}" ]]; then
        printf '%s\n' "$FULL_LIFECYCLE_INSTANCE_ID"
        return
    fi

    # launch_instance persists state before full_lifecycle parses stdout, so a
    # signal in that window must recover the instance id from the state file.
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        printf '%s\n' "$STATE_INSTANCE_ID"
    fi
}

start_full_lifecycle_watcher() {
    local instance_id="$1"
    local region="$2"
    local watcher_script

    command -v setsid >/dev/null || die "setsid is required for x86 AWS cleanup watcher"
    FULL_LIFECYCLE_CLEANUP_TOKEN="$(mktemp "${STATE_DIR}/aws-x86-cleanup.XXXXXX")"
    watcher_script="$(cat <<'EOF'
set -euo pipefail
trap "" INT TERM HUP
parent_pid="$1"
instance_id="$2"
profile="$3"
region="$4"
token="$5"
state_file="$6"

while kill -0 "$parent_pid" 2>/dev/null; do
    [[ -f "$token" ]] || exit 0
    sleep 1
done

[[ -f "$token" ]] || exit 0
AWS_PAGER="" aws --profile "$profile" --region "$region" ec2 terminate-instances --instance-ids "$instance_id" >/dev/null
AWS_PAGER="" aws --profile "$profile" --region "$region" ec2 wait instance-terminated --instance-ids "$instance_id" >/dev/null
rm -f "$token" "$state_file"
EOF
)"
    setsid bash -c "$watcher_script" bash \
        "$$" "$instance_id" "$AWS_X86_PROFILE" "$region" \
        "$FULL_LIFECYCLE_CLEANUP_TOKEN" "$STATE_FILE" >/dev/null 2>&1 &
    FULL_LIFECYCLE_WATCHER_PID="$!"
}

stop_full_lifecycle_watcher() {
    if [[ -n "${FULL_LIFECYCLE_CLEANUP_TOKEN:-}" ]]; then
        rm -f "$FULL_LIFECYCLE_CLEANUP_TOKEN"
        FULL_LIFECYCLE_CLEANUP_TOKEN=""
    fi
    FULL_LIFECYCLE_WATCHER_PID=""
}

full_lifecycle_cleanup() {
    local status="$1"
    local reason="$2"
    local cleanup_instance_id=""

    if [[ "${FULL_LIFECYCLE_CLEANUP_RUNNING:-0}" -eq 1 ]]; then
        return
    fi
    FULL_LIFECYCLE_CLEANUP_RUNNING=1
    trap - EXIT
    trap '' INT TERM
    stop_full_lifecycle_watcher

    if [[ -n "${FULL_LIFECYCLE_LAUNCH_OUTPUT:-}" ]]; then
        rm -f "$FULL_LIFECYCLE_LAUNCH_OUTPUT"
        FULL_LIFECYCLE_LAUNCH_OUTPUT=""
    fi

    cleanup_instance_id="$(full_lifecycle_cleanup_instance_id)"
    if [[ -z "$cleanup_instance_id" ]]; then
        log "Lifecycle cleanup (${reason}, status=${status}) found no instance to terminate"
        return
    fi

    log "Lifecycle cleanup (${reason}, status=${status}) terminating ${cleanup_instance_id}"
    if terminate_instance "$cleanup_instance_id"; then
        FULL_LIFECYCLE_INSTANCE_ID=""
        log "Terminated ${cleanup_instance_id}"
        return
    fi

    warn "Automatic termination failed for ${cleanup_instance_id}; terminate it manually."
}

full_lifecycle_exit_trap() {
    local status=$?
    full_lifecycle_cleanup "$status" "EXIT"
    exit "$status"
}

full_lifecycle_signal_trap() {
    local signal="$1"
    local status=128
    case "$signal" in
        INT)
            status=130
            ;;
        TERM)
            status=143
            ;;
        *)
            status=1
            ;;
    esac

    warn "Received ${signal}; terminating x86 AWS lifecycle instance"
    full_lifecycle_cleanup "$status" "$signal"
    exit "$status"
}

full_lifecycle() {
    ensure_benchmark_bundle

    local instance_id="" instance_ip=""
    trap full_lifecycle_exit_trap EXIT
    trap 'full_lifecycle_signal_trap INT' INT
    trap 'full_lifecycle_signal_trap TERM' TERM

    FULL_LIFECYCLE_LAUNCH_OUTPUT="$(mktemp "${TMPDIR:-/tmp}/aws-x86-launch.XXXXXX")"
    launch_instance >"$FULL_LIFECYCLE_LAUNCH_OUTPUT"
    instance_id="$(awk -F= '/^INSTANCE_ID=/{print $2}' "$FULL_LIFECYCLE_LAUNCH_OUTPUT")"
    instance_ip="$(awk -F= '/^INSTANCE_IP=/{print $2}' "$FULL_LIFECYCLE_LAUNCH_OUTPUT")"
    rm -f "$FULL_LIFECYCLE_LAUNCH_OUTPUT"
    FULL_LIFECYCLE_LAUNCH_OUTPUT=""
    [[ -n "$instance_id" && -n "$instance_ip" ]] || die "failed to capture launched instance state"
    FULL_LIFECYCLE_INSTANCE_ID="$instance_id"
    start_full_lifecycle_watcher "$instance_id" "$(resolve_region)"

    wait_for_ssh "$instance_ip"
    setup_instance "$instance_ip"
    benchmark_instance "$instance_ip"
}

main() {
    local command="${1:-}"
    case "$command" in
        launch)
            preflight_instance_check
            launch_instance
            ;;
        setup)
            shift
            preflight_instance_check
            load_state
            setup_instance "${1:-${STATE_INSTANCE_IP:-}}"
            ;;
        benchmark)
            shift
            preflight_instance_check
            load_state
            benchmark_instance "${1:-${STATE_INSTANCE_IP:-}}"
            ;;
        terminate)
            shift
            preflight_instance_check
            load_state
            terminate_instance "${1:-${STATE_INSTANCE_ID:-}}"
            ;;
        full)
            preflight_instance_check
            full_lifecycle
            ;;
        -h|--help|help|"")
            usage
            ;;
        *)
            usage
            die "unknown command: $command"
            ;;
    esac
}

main "$@"
