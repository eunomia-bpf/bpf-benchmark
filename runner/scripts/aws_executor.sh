#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
ACTION="${1:?usage: aws_executor.sh <run|terminate> <manifest_path>}"
MANIFEST_PATH="${2:?usage: aws_executor.sh <run|terminate> <manifest_path>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-executor][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

CACHE_DIR="$ROOT_DIR/.cache/${RUN_TARGET_NAME}"
STATE_DIR="$CACHE_DIR/state"
STATE_FILE="$STATE_DIR/instance.env"
ARTIFACT_DIR="$CACHE_DIR/artifacts"
RESULTS_DIR="$CACHE_DIR/results"
MODULES_STAGE_DIR="$CACHE_DIR/modules-stage"
LOCAL_REPO_ROOT="$CACHE_DIR/repos"
LOCAL_PROMOTE_ROOT="$CACHE_DIR/bundle-inputs"
AWS_REMOTE_PREREQS_STAMP="${AWS_REMOTE_PREREQS_STAMP:-/var/tmp/bpf-benchmark/prereqs.ready}"
KERNEL_DIR="${KERNEL_DIR:-$ROOT_DIR/vendor/linux-framework}"
KERNEL_BUILD_LOCK_FILE="${KERNEL_BUILD_LOCK_FILE:-$ROOT_DIR/.cache/kernel-build.lock}"
KERNEL_DEFCONFIG_SRC="${KERNEL_DEFCONFIG_SRC:-$ROOT_DIR/vendor/bpfrejit_defconfig}"
KERNEL_CONFIG_STAMP_FILE="$KERNEL_DIR/.bpfrejit_config.stamp"
X86_BZIMAGE="${X86_BZIMAGE:-$KERNEL_DIR/arch/x86/boot/bzImage}"
X86_VMLINUX="${X86_VMLINUX:-$KERNEL_DIR/vmlinux}"
X86_KINSN_MODULE_DIR="${X86_KINSN_MODULE_DIR:-$ROOT_DIR/module/x86}"
X86_UPSTREAM_SELFTEST_DIR="${X86_UPSTREAM_SELFTEST_DIR:-$ROOT_DIR/.cache/upstream-bpf-selftests}"
ARM64_WORKTREE_DIR="${ARM64_WORKTREE_DIR:-$ROOT_DIR/.worktrees/linux-framework-arm64-src}"
ARM64_AWS_BUILD_DIR="${ARM64_AWS_BUILD_DIR:-$ROOT_DIR/.cache/aws-arm64/kernel-build}"
ARM64_AWS_BASE_CONFIG="${ARM64_AWS_BASE_CONFIG:-$ROOT_DIR/.cache/aws-arm64/config-al2023-arm64}"
ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR="${ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR:-$ROOT_DIR/vendor/linux-framework/tools/testing/selftests/bpf/test_kmods}"
ARM64_UPSTREAM_TEST_KMODS_DIR="${ARM64_UPSTREAM_TEST_KMODS_DIR:-$ROOT_DIR/.cache/aws-arm64/upstream-selftests-kmods-arm64}"
ARM64_CROSSBUILD_OUTPUT_DIR="${ARM64_CROSSBUILD_OUTPUT_DIR:-$ROOT_DIR/.cache/aws-arm64/binaries}"
ARM64_TEST_ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-$CACHE_DIR/test-artifacts}"
ARM64_TEST_UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/unittest/build-arm64}"
ARM64_TEST_NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/negative/build-arm64}"
ARM64_UPSTREAM_SELFTEST_DIR="${ARM64_UPSTREAM_SELFTEST_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests}"
ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec.real}"
ARM64_CROSS_DAEMON="${ARM64_CROSS_DAEMON:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon}"
ARM64_CROSS_DAEMON_REAL="${ARM64_CROSS_DAEMON_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon.real}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/lib}"
ARM64_KATRAN_SERVER_BINARY="${ARM64_KATRAN_SERVER_BINARY:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/bin/katran_server_grpc}"
ARM64_KATRAN_SERVER_LIB_DIR="${ARM64_KATRAN_SERVER_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/lib}"
CROSS_COMPILE_PREFIX="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}"
AWS_REGION_VALUE="${AWS_REGION:-${AWS_DEFAULT_REGION:-}}"
AWS_PROFILE_VALUE="${AWS_PROFILE:-codex-ec2}"
BUILD_KERNEL_RELEASE=""
STATE_INSTANCE_ID=""
STATE_INSTANCE_IP=""
STATE_REGION=""
STATE_KEY_PATH=""
STATE_KEY_NAME=""
STATE_SECURITY_GROUP_ID=""
STATE_SUBNET_ID=""
STATE_KERNEL_RELEASE=""

log() {
    printf '[aws-executor] %s\n' "$*" >&2
}

die() {
    printf '[aws-executor][ERROR] %s\n' "$*" >&2
    exit 1
}

require_local_path() {
    local path="$1"
    local description="$2"
    [[ -e "$path" ]] || die "${description} not found: ${path}"
}

dir_has_entries() {
    local path="$1"
    [[ -d "$path" ]] || return 1
    find "$path" -mindepth 1 -maxdepth 1 -print -quit 2>/dev/null | grep -q .
}

ensure_dirs() {
    mkdir -p "$CACHE_DIR" "$STATE_DIR" "$ARTIFACT_DIR" "$RESULTS_DIR"
}

with_kernel_lock() (
    mkdir -p "$(dirname "$KERNEL_BUILD_LOCK_FILE")"
    exec 9>"$KERNEL_BUILD_LOCK_FILE"
    flock 9
    "$@"
)

load_state() {
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KEY_PATH \
        STATE_KEY_NAME \
        STATE_SECURITY_GROUP_ID \
        STATE_SUBNET_ID \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KEY_PATH=""
    STATE_KEY_NAME=""
    STATE_SECURITY_GROUP_ID=""
    STATE_SUBNET_ID=""
    STATE_KERNEL_RELEASE=""
    if [[ -f "$STATE_FILE" ]]; then
        # shellcheck disable=SC1090
        source "$STATE_FILE"
    fi
}

save_state() {
    local instance_id="$1"
    local instance_ip="$2"
    local region="$3"
    local key_path="$4"
    local key_name="$5"
    local kernel_release="${6:-}"
    local security_group_id="${7:-}"
    local subnet_id="${8:-}"
    ensure_dirs
    cat >"$STATE_FILE" <<EOF
STATE_INSTANCE_ID=$(printf '%q' "$instance_id")
STATE_INSTANCE_IP=$(printf '%q' "$instance_ip")
STATE_REGION=$(printf '%q' "$region")
STATE_KEY_PATH=$(printf '%q' "$key_path")
STATE_KEY_NAME=$(printf '%q' "$key_name")
STATE_KERNEL_RELEASE=$(printf '%q' "$kernel_release")
STATE_SECURITY_GROUP_ID=$(printf '%q' "$security_group_id")
STATE_SUBNET_ID=$(printf '%q' "$subnet_id")
EOF
}

clear_state() {
    rm -f "$STATE_FILE"
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KEY_PATH \
        STATE_KEY_NAME \
        STATE_SECURITY_GROUP_ID \
        STATE_SUBNET_ID \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KEY_PATH=""
    STATE_KEY_NAME=""
    STATE_SECURITY_GROUP_ID=""
    STATE_SUBNET_ID=""
    STATE_KERNEL_RELEASE=""
}

resolve_region() {
    local region=""
    if [[ -n "$AWS_REGION_VALUE" ]]; then
        printf '%s\n' "$AWS_REGION_VALUE"
        return 0
    fi
    if region="$(AWS_PAGER="" aws --profile "$AWS_PROFILE_VALUE" configure get region 2>/dev/null)" && [[ -n "$region" ]]; then
        printf '%s\n' "$region"
        return 0
    fi
    die "AWS region is unset. Export AWS_REGION/AWS_DEFAULT_REGION or configure it in profile ${AWS_PROFILE_VALUE}."
}

_aws() {
    AWS_PAGER="" aws --profile "$AWS_PROFILE_VALUE" "$@"
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

lookup_existing_instance() {
    local region="$1"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${RUN_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running" \
        --query 'Reservations[].Instances[0].[InstanceId,State.Name,PublicIpAddress]' \
        --output text 2>/dev/null || true
}

lookup_any_tagged_instance() {
    local region="$1"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${RUN_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
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

instance_state_is_reusable() {
    case "${1:-}" in
        pending|running) return 0 ;;
    esac
    return 1
}

ssh_base_args() {
    local ip="$1"
    printf '%s\n' \
        -o BatchMode=yes \
        -o StrictHostKeyChecking=no \
        -o UserKnownHostsFile=/dev/null \
        -o ConnectTimeout=15 \
        -i "${STATE_KEY_PATH:-${AWS_KEY_PATH:-}}"
}

ssh_bash() {
    local ip="$1"
    shift
    ssh $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}" "bash -s -- $*"
}

scp_to() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    scp $(ssh_base_args "$ip") "$src" "${RUN_REMOTE_USER}@${ip}:$dest"
}

scp_from() {
    local ip="$1"
    local src="$2"
    local dest="$3"
    scp $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}:$src" "$dest"
}

wait_for_ssh() {
    local ip="$1"
    local attempt
    for attempt in $(seq 1 60); do
        if ssh $(ssh_base_args "$ip") "${RUN_REMOTE_USER}@${ip}" true >/dev/null 2>&1; then
            return 0
        fi
        sleep 5
    done
    die "timed out waiting for SSH on ${ip}"
}

resolve_root_device_name() {
    local region="$1"
    local ami_id="$2"
    local root_device_name
    root_device_name="$(aws_cmd "$region" ec2 describe-images \
        --image-ids "$ami_id" \
        --query 'Images[0].RootDeviceName' \
        --output text)"
    if [[ -z "$root_device_name" || "$root_device_name" == "None" ]]; then
        printf '/dev/xvda\n'
    else
        printf '%s\n' "$root_device_name"
    fi
}

launch_instance() {
    ensure_dirs
    load_state
    ensure_aws_identity

    local region key_path key_name security_group_id subnet_id instance_id="" instance_state="" instance_ip="" ami_id root_device_name
    region="$(resolve_region)"
    key_name="${RUN_AWS_KEY_NAME:-${STATE_KEY_NAME:-}}"
    key_path="${RUN_AWS_KEY_PATH:-${STATE_KEY_PATH:-}}"
    security_group_id="${RUN_AWS_SECURITY_GROUP_ID:-${STATE_SECURITY_GROUP_ID:-}}"
    subnet_id="${RUN_AWS_SUBNET_ID:-${STATE_SUBNET_ID:-}}"
    [[ -n "$key_name" ]] || die "AWS key name is unset for ${RUN_TARGET_NAME}"
    [[ -n "$key_path" ]] || die "AWS key path is unset for ${RUN_TARGET_NAME}"
    [[ -n "$security_group_id" ]] || die "AWS security group id is unset for ${RUN_TARGET_NAME}"
    [[ -n "$subnet_id" ]] || die "AWS subnet id is unset for ${RUN_TARGET_NAME}"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"
    [[ "$RUN_ROOT_VOLUME_GB" =~ ^[0-9]+$ ]] || die "RUN_ROOT_VOLUME_GB must be a positive integer"
    (( RUN_ROOT_VOLUME_GB > 0 )) || die "RUN_ROOT_VOLUME_GB must be greater than zero"

    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$STATE_INSTANCE_ID")"
        case "$instance_state" in
            stopped|stopping)
                terminate_instance "${STATE_INSTANCE_ID}"
                instance_id=""
                instance_state=""
                instance_ip=""
                ;;
        esac
    fi
    if [[ -z "$instance_id" || "$instance_id" == "None" ]] || ! instance_state_is_reusable "$instance_state"; then
        read -r instance_id instance_state instance_ip <<<"$(lookup_existing_instance "$region")"
    fi

    if [[ -z "$instance_id" || "$instance_id" == "None" ]]; then
        if [[ -n "${AWS_AMI_ID:-}" ]]; then
            ami_id="${AWS_AMI_ID}"
        else
            ami_id="$(aws_cmd "$region" ssm get-parameter --name "$RUN_AMI_PARAM" --query 'Parameter.Value' --output text)"
        fi
        root_device_name="$(resolve_root_device_name "$region" "$ami_id")"
        log "Launching ${RUN_TARGET_NAME} instance ${RUN_INSTANCE_TYPE} in ${region}"
        instance_id="$(aws_cmd "$region" ec2 run-instances \
            --image-id "$ami_id" \
            --instance-type "$RUN_INSTANCE_TYPE" \
            --key-name "$key_name" \
            --security-group-ids "$security_group_id" \
            --subnet-id "$subnet_id" \
            --block-device-mappings "DeviceName=${root_device_name},Ebs={VolumeSize=${RUN_ROOT_VOLUME_GB},VolumeType=gp3,DeleteOnTermination=true}" \
            --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${RUN_NAME_TAG}},{Key=Project,Value=bpf-benchmark},{Key=Role,Value=${RUN_TARGET_NAME}}]" \
            --count 1 \
            --query 'Instances[0].InstanceId' \
            --output text)"
    else
        log "Reusing existing EC2 instance ${instance_id} (${instance_state})"
    fi

    save_state "$instance_id" "${instance_ip:-}" "$region" "$key_path" "$key_name" "${STATE_KERNEL_RELEASE:-}" "$security_group_id" "$subnet_id"
    aws_cmd "$region" ec2 wait instance-running --instance-ids "$instance_id"
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$instance_ip" && "$instance_ip" != "None" ]] || die "instance ${instance_id} has no public IP"
    save_state "$instance_id" "$instance_ip" "$region" "$key_path" "$key_name" "${STATE_KERNEL_RELEASE:-}" "$security_group_id" "$subnet_id"
}

remote_kernel_release() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
uname -r
EOF
}

remote_root_volume_size_gb() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
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
EOF
}

remote_has_runtime_btf() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
test -s /sys/kernel/btf/vmlinux
EOF
}

remote_has_sched_ext() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
test -e /sys/kernel/sched_ext/state
EOF
}

elf_has_btf() {
    local elf_path="$1"
    readelf -S "$elf_path" 2>/dev/null | grep -F '.BTF' >/dev/null
}

modules_tar_has_entry() {
    local modules_tar="$1"
    local pattern="$2"
    tar -tzf "$modules_tar" 2>/dev/null | grep -E "$pattern" >/dev/null
}

config_symbol_value() {
    local config_path="$1"
    local symbol="$2"
    if grep -Eq "^${symbol}=y$" "$config_path"; then printf 'y\n'; return 0; fi
    if grep -Eq "^${symbol}=m$" "$config_path"; then printf 'm\n'; return 0; fi
    if grep -Eq "^# ${symbol} is not set$" "$config_path"; then printf 'n\n'; return 0; fi
    printf 'unknown\n'
}

prepare_x86_aws_config_locked() {
    local config_file="$KERNEL_DIR/.config"
    local config_script="$KERNEL_DIR/scripts/config"
    require_local_path "$KERNEL_DEFCONFIG_SRC" "x86 kernel defconfig"
    require_local_path "$config_script" "x86 kernel config helper"
    cp "$KERNEL_DEFCONFIG_SRC" "$config_file"
    "$config_script" --file "$config_file" \
        --enable UNWINDER_ORC \
        --disable UNWINDER_FRAME_POINTER \
        --disable DEBUG_INFO_BTF_MODULES \
        --set-str SYSTEM_TRUSTED_KEYS "" \
        --set-str SYSTEM_REVOCATION_KEYS "" \
        --enable NET_VENDOR_AMAZON \
        --enable ENA_ETHERNET \
        --module NVME_CORE \
        --module BLK_DEV_NVME \
        --module XFS_FS \
        --module EXT4_FS \
        --enable VIRTIO_NET \
        --enable VIRTIO_PCI \
        --module VIRTIO_BLK
    rm -f "$KERNEL_CONFIG_STAMP_FILE"
    make -C "$KERNEL_DIR" olddefconfig >/dev/null
}

build_x86_kernel_artifacts_locked() {
    local kernel_release modules_root
    BUILD_KERNEL_RELEASE=""
    prepare_x86_aws_config_locked
    log "Building x86 AWS kernel image and modules"
    make -C "$KERNEL_DIR" -j"$(nproc)" bzImage modules_prepare >/dev/null
    if [[ -f "$KERNEL_DIR/vmlinux.symvers" ]]; then
        cp "$KERNEL_DIR/vmlinux.symvers" "$KERNEL_DIR/Module.symvers"
    fi
    make -C "$KERNEL_DIR" -j"$(nproc)" modules >/dev/null

    kernel_release="$(<"$KERNEL_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "x86 kernel release is empty"
    rm -rf "$MODULES_STAGE_DIR"
    mkdir -p "$MODULES_STAGE_DIR" "$ARTIFACT_DIR"
    make -C "$KERNEL_DIR" INSTALL_MOD_PATH="$MODULES_STAGE_DIR" modules_install >/dev/null
    rm -f "$MODULES_STAGE_DIR/lib/modules/$kernel_release/build" "$MODULES_STAGE_DIR/lib/modules/$kernel_release/source"
    modules_root="$MODULES_STAGE_DIR/lib/modules/$kernel_release"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme-core.ko" "x86 nvme-core module"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme.ko" "x86 nvme module"
    require_local_path "$modules_root/kernel/fs/ext4/ext4.ko" "x86 ext4 module"
    require_local_path "$modules_root/kernel/fs/xfs/xfs.ko" "x86 xfs module"
    require_local_path "$modules_root/kernel/drivers/block/virtio_blk.ko" "x86 virtio_blk module"
    cp "$X86_VMLINUX" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    cp "$X86_BZIMAGE" "$ARTIFACT_DIR/bzImage-$kernel_release"
    tar -C "$MODULES_STAGE_DIR" -czf "$ARTIFACT_DIR/modules-$kernel_release.tar.gz" lib/modules
    BUILD_KERNEL_RELEASE="$kernel_release"
}

build_x86_kernel_artifacts() {
    ensure_dirs
    with_kernel_lock build_x86_kernel_artifacts_locked
}

arm64_build_config_matches_aws_base() {
    local current_config="$ARM64_AWS_BUILD_DIR/.config"
    local symbol base_value current_value
    [[ -f "$ARM64_AWS_BASE_CONFIG" && -f "$current_config" ]] || return 1
    for symbol in CONFIG_MODVERSIONS CONFIG_MODULE_SIG CONFIG_MODULE_SIG_ALL CONFIG_LOCALVERSION_AUTO; do
        base_value="$(config_symbol_value "$ARM64_AWS_BASE_CONFIG" "$symbol")"
        current_value="$(config_symbol_value "$current_config" "$symbol")"
        [[ "$base_value" == "$current_value" ]] || return 1
    done
    return 0
}

refresh_aws_arm64_base_config() {
    local ip="$1"
    local remote_release tmp_config
    remote_release="$(remote_kernel_release "$ip")"
    if [[ "$remote_release" != *.amzn2023.aarch64 ]]; then
        if [[ -f "$ARM64_AWS_BASE_CONFIG" ]]; then
            log "Keeping cached AWS ARM64 base config; current remote kernel is ${remote_release}"
            return 0
        fi
        die "cannot seed AWS ARM64 base config from non-stock kernel ${remote_release}; relaunch a fresh AL2023 instance"
    fi
    tmp_config="$(mktemp "${CACHE_DIR}/config-al2023-arm64.XXXXXX")"
    if ! ssh_bash "$ip" <<'EOF' >"$tmp_config"
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
EOF
    then
        rm -f "$tmp_config"
        die "failed to capture AWS ARM64 base kernel config from ${ip}"
    fi
    grep -F 'CONFIG_ARM64=y' "$tmp_config" >/dev/null || die "captured AWS ARM64 base config is invalid: ${tmp_config}"
    mv "$tmp_config" "$ARM64_AWS_BASE_CONFIG"
}

refresh_arm64_kernel_build_from_base() {
    [[ -f "$ARM64_AWS_BASE_CONFIG" ]] || die "AWS ARM64 base config is missing: ${ARM64_AWS_BASE_CONFIG}"
    rm -f "$ARM64_AWS_BUILD_DIR/.config" "$ARM64_AWS_BUILD_DIR/include/config/kernel.release" "$ARM64_AWS_BUILD_DIR/include/generated/utsrelease.h"
    ARM64_AWS_BUILD_DIR="$ARM64_AWS_BUILD_DIR" ARM64_AWS_BASE_CONFIG="$ARM64_AWS_BASE_CONFIG" \
        make -C "$ROOT_DIR" kernel-arm64-aws >/dev/null
}

rebuild_arm64_kinsn_modules() {
    rm -f \
        "$ROOT_DIR"/module/arm64/*.ko \
        "$ROOT_DIR"/module/arm64/*.o \
        "$ROOT_DIR"/module/arm64/*.mod \
        "$ROOT_DIR"/module/arm64/*.mod.c \
        "$ROOT_DIR"/module/arm64/.*.cmd \
        "$ROOT_DIR"/module/arm64/.module-common.o \
        "$ROOT_DIR"/module/arm64/Module.symvers \
        "$ROOT_DIR"/module/arm64/modules.order
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules_prepare >/dev/null
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        M="$ROOT_DIR/module/arm64" modules >/dev/null
}

rebuild_arm64_upstream_test_kmods() {
    require_local_path "$ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR" "ARM64 upstream selftest kmod source dir"
    rm -rf "$ARM64_UPSTREAM_TEST_KMODS_DIR"
    mkdir -p "$(dirname "$ARM64_UPSTREAM_TEST_KMODS_DIR")"
    cp -a "$ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR" "$ARM64_UPSTREAM_TEST_KMODS_DIR"
    rm -f \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.ko \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.o \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.mod \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.mod.c \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/.*.cmd \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/.module-common.o \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/Module.symvers \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR"/modules.order
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        M="$ARM64_UPSTREAM_TEST_KMODS_DIR" modules >/dev/null
}

efi_binary_is_valid() {
    local image_path="$1"
    [[ -f "$image_path" ]] || return 1
    file "$image_path" 2>/dev/null | grep -F 'EFI application' >/dev/null
}

build_arm64_kernel_artifacts() {
    ensure_dirs
    BUILD_KERNEL_RELEASE=""
    rm -f \
        "$ARM64_AWS_BUILD_DIR/.config" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/Image" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" \
        "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi.elf" \
        "$ARM64_AWS_BUILD_DIR/vmlinux"
    log "Building ARM64 AWS kernel image and modules"
    ARM64_AWS_BUILD_DIR="$ARM64_AWS_BUILD_DIR" ARM64_AWS_BASE_CONFIG="$ARM64_AWS_BASE_CONFIG" \
        make -C "$ROOT_DIR" kernel-arm64-aws >/dev/null
    local kernel_release
    kernel_release="$(<"$ARM64_AWS_BUILD_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "ARM64 kernel release is empty"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules -j"$(nproc)" >/dev/null
    rm -rf "$MODULES_STAGE_DIR"
    mkdir -p "$MODULES_STAGE_DIR" "$ARTIFACT_DIR"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        INSTALL_MOD_PATH="$MODULES_STAGE_DIR" modules_install >/dev/null
    rm -f "$MODULES_STAGE_DIR/lib/modules/$kernel_release/build" "$MODULES_STAGE_DIR/lib/modules/$kernel_release/source"
    require_local_path "$ARM64_AWS_BUILD_DIR/vmlinux" "ARM64 vmlinux"
    require_local_path "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "ARM64 EFI kernel image"
    cp "$ARM64_AWS_BUILD_DIR/vmlinux" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    cp "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "$ARTIFACT_DIR/vmlinuz-$kernel_release.efi"
    tar -C "$MODULES_STAGE_DIR" -czf "$ARTIFACT_DIR/modules-$kernel_release.tar.gz" lib/modules
    elf_has_btf "$ARTIFACT_DIR/vmlinux-$kernel_release" || die "generated ARM64 vmlinux is missing .BTF"
    efi_binary_is_valid "$ARTIFACT_DIR/vmlinuz-$kernel_release.efi" || die "generated ARM64 EFI kernel image is invalid"
    modules_tar_has_entry "$ARTIFACT_DIR/modules-$kernel_release.tar.gz" '/modules\.dep$' || die "generated ARM64 modules archive is missing modules.dep"
    BUILD_KERNEL_RELEASE="$kernel_release"
}

ensure_x86_runner_ready() {
    make -C "$ROOT_DIR" runner >/dev/null
    file "$ROOT_DIR/runner/build/micro_exec" | grep -F "x86-64" >/dev/null || die "x86 runner is not an x86_64 binary"
}

ensure_x86_daemon_ready() {
    make -C "$ROOT_DIR" daemon >/dev/null
    file "$ROOT_DIR/daemon/target/release/bpfrejit-daemon" | grep -F "x86-64" >/dev/null || die "x86 daemon is not an x86_64 binary"
}

ensure_x86_kinsn_modules_ready() {
    make -C "$ROOT_DIR" kinsn-modules >/dev/null
    local ko_count
    ko_count="$(find "$X86_KINSN_MODULE_DIR" -maxdepth 1 -name '*.ko' | wc -l | tr -d ' ')"
    [[ "$ko_count" -gt 0 ]] || die "no x86 kinsn modules found under ${X86_KINSN_MODULE_DIR}"
}

ensure_x86_selftest_outputs() {
    make -C "$ROOT_DIR/runner" unittest-build negative-build >/dev/null
    file "$ROOT_DIR/tests/unittest/build/rejit_kinsn" | grep -F "x86-64" >/dev/null || die "x86 unittest binary is not x86_64"
    file "$ROOT_DIR/tests/negative/build/adversarial_rejit" | grep -F "x86-64" >/dev/null || die "x86 negative binary is not x86_64"
}

ensure_x86_upstream_selftests_ready() {
    make -C "$ROOT_DIR" upstream-selftests-build >/dev/null
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_verifier" "x86 upstream test_verifier"
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_progs" "x86 upstream test_progs"
}

ensure_cross_arm64_runtime() {
    local require_llvmbpf="${1:-0}"
    local llvmbpf_setting="${ARM64_CROSSBUILD_ENABLE_LLVMBPF:-OFF}"
    if [[ "$require_llvmbpf" == "1" ]]; then
        llvmbpf_setting=ON
    fi
    make -C "$ROOT_DIR" cross-arm64 ARM64_CROSSBUILD_ENABLE_LLVMBPF="$llvmbpf_setting" >/dev/null
    file "$ARM64_CROSS_RUNNER_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 runner is not an aarch64 binary"
    file "$ARM64_CROSS_DAEMON_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 daemon is not an aarch64 binary"
    dir_has_entries "$ARM64_CROSS_LIB_DIR" || die "ARM64 runtime lib dir is empty: ${ARM64_CROSS_LIB_DIR}"
}

ensure_arm64_kinsn_modules_ready() {
    local required_modules=(
        "$ROOT_DIR/module/arm64/bpf_bulk_memory.ko"
        "$ROOT_DIR/module/arm64/bpf_endian.ko"
        "$ROOT_DIR/module/arm64/bpf_extract.ko"
        "$ROOT_DIR/module/arm64/bpf_ldp.ko"
        "$ROOT_DIR/module/arm64/bpf_rotate.ko"
        "$ROOT_DIR/module/arm64/bpf_select.ko"
    )
    local module_path expected_release actual_release
    expected_release="${STATE_KERNEL_RELEASE:-}"
    if [[ -f "$ARM64_AWS_BASE_CONFIG" ]] && ! arm64_build_config_matches_aws_base; then
        refresh_arm64_kernel_build_from_base
    fi
    for module_path in "${required_modules[@]}"; do
        if [[ ! -f "$module_path" ]]; then
            rebuild_arm64_kinsn_modules
            break
        fi
        if [[ -n "$expected_release" ]]; then
            actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
            if [[ "$actual_release" != "$expected_release" ]]; then
                rebuild_arm64_kinsn_modules
                break
            fi
        fi
    done
    if [[ -n "$expected_release" ]]; then
        for module_path in "${required_modules[@]}"; do
            actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
            [[ "$actual_release" == "$expected_release" ]] || die "ARM64 kinsn module release mismatch for $(basename "$module_path")"
        done
    fi
}

ensure_arm64_upstream_test_kmods_ready() {
    local required_modules=(
        "$ARM64_UPSTREAM_TEST_KMODS_DIR/bpf_testmod.ko"
        "$ARM64_UPSTREAM_TEST_KMODS_DIR/bpf_test_no_cfi.ko"
        "$ARM64_UPSTREAM_TEST_KMODS_DIR/bpf_test_modorder_x.ko"
        "$ARM64_UPSTREAM_TEST_KMODS_DIR/bpf_test_modorder_y.ko"
        "$ARM64_UPSTREAM_TEST_KMODS_DIR/bpf_test_rqspinlock.ko"
    )
    local module_path expected_release actual_release
    expected_release="${STATE_KERNEL_RELEASE:-}"
    for module_path in "${required_modules[@]}"; do
        if [[ ! -f "$module_path" ]]; then
            rebuild_arm64_upstream_test_kmods
            break
        fi
        if [[ -n "$expected_release" ]]; then
            actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
            if [[ "$actual_release" != "$expected_release" ]]; then
                rebuild_arm64_upstream_test_kmods
                break
            fi
        fi
    done
    if [[ -n "$expected_release" ]]; then
        for module_path in "${required_modules[@]}"; do
            actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
            [[ "$actual_release" == "$expected_release" ]] || die "ARM64 upstream selftest kmod release mismatch for $(basename "$module_path")"
        done
    fi
}

ensure_arm64_selftest_outputs() {
    [[ -f "$ARM64_AWS_BUILD_DIR/vmlinux" ]] || die "AWS ARM64 selftest build requires ${ARM64_AWS_BUILD_DIR}/vmlinux"
    make -C "$ROOT_DIR" arm64-test-artifacts \
        VMLINUX_BTF="$ARM64_AWS_BUILD_DIR/vmlinux" \
        ARM64_TEST_ARTIFACTS_ROOT="$ARM64_TEST_ARTIFACTS_ROOT" \
        ARM64_TEST_UNITTEST_BUILD_DIR="$ARM64_TEST_UNITTEST_BUILD_DIR" \
        ARM64_TEST_NEGATIVE_BUILD_DIR="$ARM64_TEST_NEGATIVE_BUILD_DIR" \
        ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR="$ARM64_UPSTREAM_SELFTEST_DIR" >/dev/null
    file "$ARM64_TEST_UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "ARM aarch64" >/dev/null || die "ARM64 unittest binary is not aarch64"
    file "$ARM64_TEST_NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "ARM aarch64" >/dev/null || die "ARM64 negative binary is not aarch64"
    file "$ARM64_UPSTREAM_SELFTEST_DIR/test_verifier" | grep -F "ARM aarch64" >/dev/null || die "ARM64 upstream test_verifier is not aarch64"
    file "$ARM64_UPSTREAM_SELFTEST_DIR/test_progs" | grep -F "ARM aarch64" >/dev/null || die "ARM64 upstream test_progs is not aarch64"
}

ensure_selected_repos_fetched() {
    local repo_csv="$1"
    local repo
    local args=()
    [[ -n "$repo_csv" ]] || return 0
    mkdir -p "$LOCAL_REPO_ROOT"
    IFS=',' read -r -a _selected_repos <<<"$repo_csv"
    for repo in "${_selected_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    python3 "$ROOT_DIR/runner/scripts/fetch_corpus_repos.py" --repo-root "$LOCAL_REPO_ROOT" "${args[@]}" >/dev/null
}

ensure_x86_scx_artifacts_ready() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "scx"
    IFS=',' read -r -a _scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        python3 "$ROOT_DIR/runner/scripts/build_scx_artifacts.py" \
            --force \
            --repo-root "$LOCAL_REPO_ROOT" \
            --promote-root "$LOCAL_PROMOTE_ROOT" \
            --package "$package" >/dev/null
        file "$LOCAL_REPO_ROOT/scx/target/release/$package" | grep -F "x86-64" >/dev/null || die "x86 scx binary is not x86_64: $package"
        require_local_path "$LOCAL_PROMOTE_ROOT/corpus/build/scx/${package}_main.bpf.o" "x86 scx object ${package}_main.bpf.o"
    done
}

ensure_arm64_scx_artifacts_ready() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "scx"
    IFS=',' read -r -a _scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    make -C "$ROOT_DIR" cross-arm64-scx \
        ARM64_SOURCE_REPO_ROOT="$LOCAL_REPO_ROOT" \
        ARM64_CROSSBUILD_SCX_PACKAGES="$RUN_SCX_PACKAGES_CSV" >/dev/null
    for package in "${_scx_packages[@]}"; do
        file "$ARM64_CROSSBUILD_OUTPUT_DIR/runner/repos/scx/target/release/$package" | grep -F "ARM aarch64" >/dev/null \
            || die "ARM64 scx binary is not aarch64: $package"
        require_local_path "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/scx/${package}_main.bpf.o" "ARM64 scx object ${package}_main.bpf.o"
    done
}

ensure_x86_native_repo_artifacts_ready() {
    local repo args=()
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "$RUN_BENCHMARK_REPOS_CSV"
    mkdir -p "$LOCAL_PROMOTE_ROOT/corpus/build"
    IFS=',' read -r -a _native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    for repo in "${_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    RUNNER_REPOS_DIR_OVERRIDE="$LOCAL_REPO_ROOT" \
        KATRAN_SERVER_BINARY="$ROOT_DIR/e2e/cases/katran/bin/katran_server_grpc" \
        KATRAN_SERVER_LIB_DIR="$ROOT_DIR/e2e/cases/katran/lib" \
        python3 "$ROOT_DIR/runner/scripts/build_corpus_native.py" \
            --jobs "$(nproc)" \
            --build-root "$LOCAL_PROMOTE_ROOT/corpus/build" \
            "${args[@]}" >/dev/null
}

arm64_local_katran_bundle_available() {
    [[ -x "$ARM64_KATRAN_SERVER_BINARY" ]] || return 1
    file "$ARM64_KATRAN_SERVER_BINARY" | grep -F "ARM aarch64" >/dev/null || return 1
    dir_has_entries "$ARM64_KATRAN_SERVER_LIB_DIR"
}

ensure_arm64_native_repo_artifacts_ready() {
    local repo
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "$RUN_BENCHMARK_REPOS_CSV"
    IFS=',' read -r -a _native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    make -C "$ROOT_DIR" cross-arm64-bench \
        ARM64_SOURCE_REPO_ROOT="$LOCAL_REPO_ROOT" \
        ARM64_CROSSBUILD_BENCH_REPOS="$RUN_NATIVE_REPOS_CSV" >/dev/null
    for repo in "${_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        case "$repo" in
            bcc)
                [[ -d "$ARM64_CROSSBUILD_OUTPUT_DIR/runner/repos/bcc/libbpf-tools/.output" && \
                   -d "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/bcc/libbpf-tools" ]] \
                    || die "ARM64 BCC bundle is incomplete after cross-arm64-bench"
                ;;
            katran)
                arm64_local_katran_bundle_available && [[ -d "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/katran" ]] \
                    || die "ARM64 Katran bundle is incomplete after cross-arm64-bench"
                ;;
            tracee)
                [[ -x "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/tracee/bin/tracee" && \
                   -f "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/tracee/tracee.bpf.o" ]] \
                    || die "ARM64 Tracee bundle is incomplete after cross-arm64-bench"
                ;;
            tetragon)
                [[ -x "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/tetragon/bin/tetragon" ]] \
                    || die "ARM64 Tetragon bundle is incomplete after cross-arm64-bench"
                ;;
            *)
                die "unsupported ARM64 native repo prebuild: ${repo}"
                ;;
        esac
    done
}

prepare_local_test_artifacts() {
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
            ensure_arm64_scx_artifacts_ready
            ensure_arm64_kinsn_modules_ready
            ensure_arm64_selftest_outputs
            ensure_arm64_upstream_test_kmods_ready
            ;;
        aws-x86)
            ensure_x86_runner_ready
            ensure_x86_daemon_ready
            ensure_x86_scx_artifacts_ready
            ensure_x86_kinsn_modules_ready
            ensure_x86_selftest_outputs
            ensure_x86_upstream_selftests_ready
            ;;
        *)
            die "unsupported AWS test target: ${RUN_TARGET_NAME}"
            ;;
    esac
}

prepare_local_benchmark_artifacts() {
    make -C "$ROOT_DIR/micro" programs >/dev/null
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
            ensure_arm64_scx_artifacts_ready
            ensure_arm64_kinsn_modules_ready
            ensure_arm64_native_repo_artifacts_ready
            ;;
        aws-x86)
            ensure_x86_runner_ready
            ensure_x86_daemon_ready
            ensure_x86_scx_artifacts_ready
            ensure_x86_kinsn_modules_ready
            ensure_x86_native_repo_artifacts_ready
            ;;
        *)
            die "unsupported AWS benchmark target: ${RUN_TARGET_NAME}"
            ;;
    esac
}

prepare_local_suite_artifacts() {
    case "$RUN_SUITE_NAME" in
        test) prepare_local_test_artifacts ;;
        micro|corpus|e2e) prepare_local_benchmark_artifacts ;;
        *) die "unsupported suite for local artifact preparation: ${RUN_SUITE_NAME}" ;;
    esac
}

append_manifest_var() {
    local key="$1"
    local value="$2"
    printf '%s=%q\n' "$key" "$value" >>"$MANIFEST_PATH"
}

prepare_local_bundle() {
    local stage_token stage_root bundle_tar
    stage_token="$(basename "$MANIFEST_PATH" .env)"
    stage_root="$CACHE_DIR/staged/${stage_token}/workspace"
    bundle_tar="$CACHE_DIR/staged/${stage_token}.tar.gz"
    RUN_INPUT_STAGE_ROOT="$stage_root"
    RUN_BUNDLE_TAR="$bundle_tar"
    rm -rf "$stage_root"
    mkdir -p "$(dirname "$bundle_tar")"
    append_manifest_var "RUN_INPUT_STAGE_ROOT" "$RUN_INPUT_STAGE_ROOT"
    append_manifest_var "RUN_BUNDLE_TAR" "$RUN_BUNDLE_TAR"
    append_manifest_var "RUNNER_REPOS_ROOT_OVERRIDE" "$LOCAL_REPO_ROOT"
    append_manifest_var "BUNDLE_PROMOTE_ROOT" "$LOCAL_PROMOTE_ROOT"
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            append_manifest_var "ARM64_CROSSBUILD_OUTPUT_DIR" "$ARM64_CROSSBUILD_OUTPUT_DIR"
            append_manifest_var "ARM64_CROSS_RUNNER" "$ARM64_CROSS_RUNNER"
            append_manifest_var "ARM64_CROSS_RUNNER_REAL" "$ARM64_CROSS_RUNNER_REAL"
            append_manifest_var "ARM64_CROSS_DAEMON" "$ARM64_CROSS_DAEMON"
            append_manifest_var "ARM64_CROSS_DAEMON_REAL" "$ARM64_CROSS_DAEMON_REAL"
            append_manifest_var "ARM64_CROSS_LIB_DIR" "$ARM64_CROSS_LIB_DIR"
            append_manifest_var "ARM64_KATRAN_SERVER_BINARY" "$ARM64_KATRAN_SERVER_BINARY"
            append_manifest_var "ARM64_KATRAN_SERVER_LIB_DIR" "$ARM64_KATRAN_SERVER_LIB_DIR"
            append_manifest_var "ARM64_TEST_ARTIFACTS_ROOT" "$ARM64_TEST_ARTIFACTS_ROOT"
            append_manifest_var "ARM64_TEST_UNITTEST_BUILD_DIR" "$ARM64_TEST_UNITTEST_BUILD_DIR"
            append_manifest_var "ARM64_TEST_NEGATIVE_BUILD_DIR" "$ARM64_TEST_NEGATIVE_BUILD_DIR"
            append_manifest_var "ARM64_UPSTREAM_SELFTEST_DIR" "$ARM64_UPSTREAM_SELFTEST_DIR"
            append_manifest_var "ARM64_UPSTREAM_TEST_KMODS_DIR" "$ARM64_UPSTREAM_TEST_KMODS_DIR"
            ;;
        aws-x86)
            append_manifest_var "X86_RUNNER" "$X86_RUNNER"
            append_manifest_var "X86_DAEMON" "$X86_DAEMON"
            append_manifest_var "X86_UPSTREAM_SELFTEST_DIR" "$X86_UPSTREAM_SELFTEST_DIR"
            ;;
        *)
            die "unsupported AWS target for local bundle preparation: ${RUN_TARGET_NAME}"
            ;;
    esac
    "$ROOT_DIR/runner/scripts/build_remote_bundle.sh" "$MANIFEST_PATH" "$RUN_INPUT_STAGE_ROOT" "$RUN_BUNDLE_TAR"
}

prepare_local_inputs() {
    prepare_local_suite_artifacts
    prepare_local_bundle
}

setup_remote_runtime_prereqs() {
    local ip="$1"
    local remote_manifest="$RUN_REMOTE_STAGE_DIR/run-contract.env"
    ssh_bash "$ip" "$RUN_REMOTE_STAGE_DIR" <<'EOF'
set -euo pipefail
mkdir -p "$1"
EOF
    scp_to "$ip" "$ROOT_DIR/runner/scripts/aws_remote_prereqs.sh" "$RUN_REMOTE_STAGE_DIR/"
    scp_to "$ip" "$MANIFEST_PATH" "$remote_manifest"
    ssh_bash "$ip" "$RUN_REMOTE_STAGE_DIR/aws_remote_prereqs.sh" "$remote_manifest" "$AWS_REMOTE_PREREQS_STAMP" <<'EOF'
set -euo pipefail
helper="$1"
manifest="$2"
stamp_path="$3"
chmod +x "$helper"
sudo env PATH="$PATH" AWS_REMOTE_PREREQS_STAMP="$stamp_path" bash "$helper" "$manifest"
test -f "$stamp_path"
EOF
}

verify_remote_runtime_prereqs() {
    local ip="$1"
    ssh_bash "$ip" "$AWS_REMOTE_PREREQS_STAMP" <<'EOF'
set -euo pipefail
test -f "$1"
EOF
}

setup_x86_instance() {
    local ip="$1"
    local region instance_id kernel_release kernel_image modules_tar setup_stamp setup_result_dir verify_log
    load_state
    region="${STATE_REGION:-$(resolve_region)}"
    instance_id="${STATE_INSTANCE_ID:-}"
    [[ -n "$instance_id" ]] || die "x86 setup requires a cached instance ID"
    wait_for_ssh "$ip"
    setup_remote_runtime_prereqs "$ip"
    build_x86_kernel_artifacts
    kernel_release="$BUILD_KERNEL_RELEASE"
    [[ -n "$kernel_release" ]] || die "x86 kernel build did not produce a kernel release"
    kernel_image="$ARTIFACT_DIR/bzImage-$kernel_release"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    setup_stamp="setup_${kernel_release}_$(date -u +%Y%m%d_%H%M%S)"
    setup_result_dir="$RESULTS_DIR/$setup_stamp"
    verify_log="$setup_result_dir/setup_verify.log"
    mkdir -p "$setup_result_dir"

    ssh_bash "$ip" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
mkdir -p "$1/boot"
EOF
    scp_to "$ip" "$kernel_image" "$RUN_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$RUN_REMOTE_KERNEL_STAGE_DIR/"
    ssh_bash "$ip" "$kernel_release" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
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
EOF
    aws_cmd "$region" ec2 reboot-instances --instance-ids "$instance_id" >/dev/null
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r _ _ ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$ip" && "$ip" != "None" ]] || die "instance ${instance_id} has no public IP after x86 reboot"
    wait_for_ssh "$ip"
    ssh_bash "$ip" "$kernel_release" <<'EOF' | tee "$verify_log" >&2
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
EOF
    save_state "$instance_id" "$ip" "$region" "${STATE_KEY_PATH:-${AWS_X86_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_X86_KEY_NAME:-}}" "$kernel_release" "${STATE_SECURITY_GROUP_ID:-${AWS_X86_SECURITY_GROUP_ID:-}}" "${STATE_SUBNET_ID:-${AWS_X86_SUBNET_ID:-}}"
}

setup_arm64_instance() {
    local ip="$1"
    local region instance_id kernel_release kernel_image modules_tar setup_stamp setup_result_dir verify_log
    load_state
    region="${STATE_REGION:-$(resolve_region)}"
    instance_id="${STATE_INSTANCE_ID:-}"
    [[ -n "$instance_id" ]] || die "ARM64 setup requires a cached instance ID"
    wait_for_ssh "$ip"
    refresh_aws_arm64_base_config "$ip"
    setup_remote_runtime_prereqs "$ip"
    build_arm64_kernel_artifacts
    kernel_release="$BUILD_KERNEL_RELEASE"
    [[ -n "$kernel_release" ]] || die "ARM64 kernel build did not produce a kernel release"
    kernel_image="$ARTIFACT_DIR/vmlinuz-$kernel_release.efi"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    setup_stamp="setup_${kernel_release}_$(date -u +%Y%m%d_%H%M%S)"
    setup_result_dir="$RESULTS_DIR/$setup_stamp"
    verify_log="$setup_result_dir/setup_verify.log"
    mkdir -p "$setup_result_dir"

    ssh_bash "$ip" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
mkdir -p "$1/boot"
EOF
    scp_to "$ip" "$kernel_image" "$RUN_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$RUN_REMOTE_KERNEL_STAGE_DIR/"
    ssh_bash "$ip" "$kernel_release" "$RUN_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
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
EOF
    aws_cmd "$region" ec2 reboot-instances --instance-ids "$instance_id" >/dev/null
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r _ _ ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$ip" && "$ip" != "None" ]] || die "instance ${instance_id} has no public IP after ARM64 reboot"
    wait_for_ssh "$ip"
    ssh_bash "$ip" "$kernel_release" <<'EOF' | tee "$verify_log" >&2
set -euo pipefail
ver="$1"
uname -r
ip -brief addr show ens5 || ip -brief addr
sudo grubby --default-kernel
test "$(uname -r)" = "$ver"
test "$(sudo grubby --default-kernel)" = "/boot/vmlinuz-$ver"
test -s /sys/kernel/btf/vmlinux
test -e /sys/kernel/sched_ext/state
EOF
    save_state "$instance_id" "$ip" "$region" "${STATE_KEY_PATH:-${AWS_ARM64_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_ARM64_KEY_NAME:-}}" "$kernel_release" "${STATE_SECURITY_GROUP_ID:-${AWS_ARM64_SECURITY_GROUP_ID:-}}" "${STATE_SUBNET_ID:-${AWS_ARM64_SUBNET_ID:-}}"
}

setup_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "setup requires an instance IP"
    case "$RUN_TARGET_NAME" in
        aws-arm64) setup_arm64_instance "$ip" ;;
        aws-x86) setup_x86_instance "$ip" ;;
        *) die "unsupported AWS target for setup: ${RUN_TARGET_NAME}" ;;
    esac
}

run_remote_suite() {
    local ip="$1"
    local stamp local_result_dir local_archive local_log remote_archive remote_log
    wait_for_ssh "$ip"
    verify_remote_runtime_prereqs "$ip" || die "remote prerequisites stamp is missing on ${ip}; run setup first"
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "manifest is missing RUN_BUNDLE_TAR; local bundle preparation did not run"
    [[ -f "${RUN_BUNDLE_TAR}" ]] || die "prepared remote bundle is missing: ${RUN_BUNDLE_TAR}"

    stamp="${RUN_SUITE_NAME}_$(date -u +%Y%m%d_%H%M%S)"
    local_result_dir="$RESULTS_DIR/$stamp"
    local_archive="$local_result_dir/results.tar.gz"
    local_log="$local_result_dir/remote.log"
    remote_archive="$RUN_REMOTE_STAGE_DIR/${stamp}.tar.gz"
    remote_log="$RUN_REMOTE_STAGE_DIR/${stamp}.log"
    mkdir -p "$local_result_dir"

    ssh_bash "$ip" "$RUN_REMOTE_STAGE_DIR" <<'EOF'
set -euo pipefail
stage_dir="$1"
sudo pkill -f "$stage_dir/workspace" >/dev/null 2>&1 || true
sudo rm -rf "$stage_dir/workspace"
mkdir -p "$stage_dir"
EOF
    scp_to "$ip" "$RUN_BUNDLE_TAR" "$RUN_REMOTE_STAGE_DIR/bundle.tar.gz"
    local remote_status=0
    set +e
    ssh_bash "$ip" "$RUN_REMOTE_STAGE_DIR" "$remote_archive" "$remote_log" <<'EOF'
set -euo pipefail
stage_dir="$1"
archive_path="$2"
log_path="$3"
workspace="$stage_dir/workspace"
bundle_path="$stage_dir/bundle.tar.gz"
sudo rm -rf "$workspace"
mkdir -p "$workspace"
tar -xzf "$bundle_path" -C "$workspace"
rm -f "$bundle_path"
test -f "$workspace/run-contract.env"
# shellcheck disable=SC1090
source "$workspace/run-contract.env"
[[ -n "${RUN_SUITE_ENTRYPOINT:-}" ]] || exit 1
chmod +x "$workspace/$RUN_SUITE_ENTRYPOINT"
sudo -E env PYTHON_BIN=python3.11 bash "$workspace/$RUN_SUITE_ENTRYPOINT" \
    "$workspace" "$workspace/run-contract.env" "$archive_path" >"$log_path" 2>&1
EOF
    remote_status=$?
    set -e
    if ssh_bash "$ip" "$remote_log" <<'EOF' >/dev/null 2>&1
set -euo pipefail
test -f "$1"
EOF
    then
        scp_from "$ip" "$remote_log" "$local_log"
    fi
    (( remote_status == 0 )) || die "remote ${RUN_TARGET_NAME}/${RUN_SUITE_NAME} suite failed; inspect ${local_log}"
    scp_from "$ip" "$remote_archive" "$local_archive"
    tar -xzf "$local_archive" -C "$local_result_dir"
    log "Fetched ${RUN_TARGET_NAME}/${RUN_SUITE_NAME} results to ${local_result_dir}"
}

ensure_instance_for_suite() {
    local current_kernel root_volume_gb current_instance_id="" current_instance_state="" current_instance_ip=""
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r current_instance_id current_instance_state current_instance_ip <<<"$(describe_instance "${STATE_REGION:-$(resolve_region)}" "$STATE_INSTANCE_ID")"
        case "$current_instance_state" in
            stopped|stopping)
                terminate_instance "${STATE_INSTANCE_ID}"
                load_state
                STATE_INSTANCE_ID=""
                STATE_INSTANCE_IP=""
                ;;
            pending|running)
                if [[ -n "$current_instance_ip" && "$current_instance_ip" != "None" ]]; then
                    STATE_INSTANCE_IP="$current_instance_ip"
                fi
                ;;
            *)
                STATE_INSTANCE_ID=""
                STATE_INSTANCE_IP=""
                ;;
        esac
    fi
    if [[ -z "${STATE_INSTANCE_IP:-}" ]]; then
        launch_instance
        load_state
    fi
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || die "failed to resolve ${RUN_TARGET_NAME} instance IP"
    wait_for_ssh "$STATE_INSTANCE_IP"

    root_volume_gb="$(remote_root_volume_size_gb "$STATE_INSTANCE_IP")"
    if [[ "$root_volume_gb" =~ ^[0-9]+$ ]] && (( root_volume_gb < RUN_ROOT_VOLUME_GB )); then
        terminate_instance "${STATE_INSTANCE_ID:-}"
        launch_instance
        load_state
        wait_for_ssh "$STATE_INSTANCE_IP"
    fi

    if [[ -z "${STATE_KERNEL_RELEASE:-}" ]]; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi

    current_kernel="$(remote_kernel_release "$STATE_INSTANCE_IP")"
    if [[ "$current_kernel" != "$STATE_KERNEL_RELEASE" ]]; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
    if ! verify_remote_runtime_prereqs "$STATE_INSTANCE_IP"; then
        setup_remote_runtime_prereqs "$STATE_INSTANCE_IP"
        return 0
    fi
    if [[ "${RUN_SUITE_NEEDS_RUNTIME_BTF:-0}" == "1" ]] && ! remote_has_runtime_btf "$STATE_INSTANCE_IP"; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
    if [[ "${RUN_SUITE_NEEDS_SCHED_EXT:-0}" == "1" ]] && ! remote_has_sched_ext "$STATE_INSTANCE_IP"; then
        setup_instance "$STATE_INSTANCE_IP"
        load_state
        return 0
    fi
}

terminate_instance() {
    load_state
    ensure_aws_identity
    local region instance_id="${1:-${STATE_INSTANCE_ID:-}}" state
    region="$(resolve_region)"
    if [[ -z "$instance_id" || "$instance_id" == "None" ]]; then
        read -r instance_id state _ <<<"$(lookup_any_tagged_instance "$region")"
    else
        read -r _ state _ <<<"$(describe_instance "$region" "$instance_id")"
    fi
    [[ -n "$instance_id" && "$instance_id" != "None" ]] || die "terminate requires an instance ID"
    case "$state" in
        terminated|shutting-down|"") ;;
        *)
            aws_cmd "$region" ec2 terminate-instances --instance-ids "$instance_id" >/dev/null
            aws_cmd "$region" ec2 wait instance-terminated --instance-ids "$instance_id"
            ;;
    esac
    if [[ "$instance_id" == "${STATE_INSTANCE_ID:-}" ]]; then
        clear_state
    fi
}

main() {
    case "$ACTION" in
        run)
            ensure_instance_for_suite
            prepare_local_inputs
            run_remote_suite "$STATE_INSTANCE_IP"
            ;;
        terminate)
            terminate_instance "${STATE_INSTANCE_ID:-}"
            ;;
        *)
            die "unsupported aws executor action: ${ACTION}"
            ;;
    esac
}

main "$@"
