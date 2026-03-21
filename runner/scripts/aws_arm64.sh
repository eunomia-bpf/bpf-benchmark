#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
CACHE_DIR="${AWS_ARM64_CACHE_DIR:-$ROOT_DIR/.cache/aws-arm64}"
ARTIFACT_DIR="$CACHE_DIR/artifacts"
STATE_DIR="$CACHE_DIR/state"
STATE_FILE="$STATE_DIR/instance.env"
RESULTS_DIR="$CACHE_DIR/results"
MODULES_STAGE_DIR="$CACHE_DIR/modules-stage"
BENCHMARK_BUNDLE_DIR="$CACHE_DIR/benchmark-bundle"
BENCHMARK_BUNDLE_TAR="$CACHE_DIR/benchmark-bundle.tar.gz"
KERNEL_RELEASE_FILE="$CACHE_DIR/kernel-release"

AWS_ARM64_NAME_TAG="${AWS_ARM64_NAME_TAG:-bpf-benchmark-arm64}"
AWS_ARM64_INSTANCE_TYPE="${AWS_ARM64_INSTANCE_TYPE:-t4g.micro}"
AWS_ARM64_PROFILE="${AWS_ARM64_PROFILE:-codex-ec2}"
AWS_ARM64_REMOTE_USER="${AWS_ARM64_REMOTE_USER:-ec2-user}"
AWS_ARM64_REMOTE_STAGE_DIR="${AWS_ARM64_REMOTE_STAGE_DIR:-/home/${AWS_ARM64_REMOTE_USER}/bpf-benchmark-arm64}"
AWS_ARM64_REMOTE_KERNEL_STAGE_DIR="${AWS_ARM64_REMOTE_KERNEL_STAGE_DIR:-/home/${AWS_ARM64_REMOTE_USER}/codex-kernel-stage}"
AWS_ARM64_AMI_PARAM="${AWS_ARM64_AMI_PARAM:-/aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64}"
AWS_ARM64_BENCH_ITERATIONS="${AWS_ARM64_BENCH_ITERATIONS:-1}"
AWS_ARM64_BENCH_WARMUPS="${AWS_ARM64_BENCH_WARMUPS:-0}"
AWS_ARM64_BENCH_REPEAT="${AWS_ARM64_BENCH_REPEAT:-10}"
AWS_REGION_VALUE="${AWS_REGION:-${AWS_DEFAULT_REGION:-}}"

ARM64_BUILD_DIR="${ARM64_BUILD_DIR:-$ROOT_DIR/vendor/linux-framework/build-arm64}"
ARM64_WORKTREE_DIR="${ARM64_WORKTREE_DIR:-$ROOT_DIR/.worktrees/linux-framework-arm64-src}"
ARM64_CROSSBUILD_OUTPUT_DIR="${ARM64_CROSSBUILD_OUTPUT_DIR:-$CACHE_DIR/binaries}"
ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec.real}"
ARM64_CROSS_SCANNER="${ARM64_CROSS_SCANNER:-$ARM64_CROSSBUILD_OUTPUT_DIR/scanner/build/bpf-jit-scanner}"
ARM64_CROSS_SCANNER_REAL="${ARM64_CROSS_SCANNER_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/scanner/build/bpf-jit-scanner.real}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/lib}"
CROSS_COMPILE_PREFIX="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}"
SCANNER_SMOKE_OBJECT="${SCANNER_SMOKE_OBJECT:-$ROOT_DIR/corpus/build/katran/balancer.bpf.o}"
SCANNER_SMOKE_POLICY_DIR="${SCANNER_SMOKE_POLICY_DIR:-$ROOT_DIR/corpus/policies/katran/balancer}"
SCANNER_SMOKE_PROGRAM="${SCANNER_SMOKE_PROGRAM:-balancer_ingress}"

STATE_INSTANCE_ID=""
STATE_INSTANCE_IP=""
STATE_REGION=""
STATE_KEY_PATH=""
STATE_KEY_NAME=""
STATE_KERNEL_RELEASE=""
FULL_LIFECYCLE_INSTANCE_ID=""

log() {
    printf '[aws-arm64] %s\n' "$*" >&2
}

warn() {
    printf '[aws-arm64][WARN] %s\n' "$*" >&2
}

die() {
    printf '[aws-arm64][ERROR] %s\n' "$*" >&2
    exit 1
}

usage() {
    cat <<'EOF'
usage: aws_arm64.sh <launch|setup|benchmark|terminate|full> [arg]

Commands:
  launch               Launch or reuse a tagged EC2 ARM64 instance.
  setup <instance_ip>  Upload/install the ARM64 kernel + modules, reboot, verify.
  benchmark <ip>       Upload local cross-built ARM64 binaries and run smoke benchmarks.
  terminate <id>       Terminate the EC2 instance and clear cached state.
  full                 Local cross-build -> launch -> setup -> benchmark -> terminate.

Required env for launch/full:
  AWS_ARM64_KEY_NAME
  AWS_ARM64_KEY_PATH
  AWS_ARM64_SECURITY_GROUP_ID
  AWS_ARM64_SUBNET_ID

Optional env:
  AWS_ARM64_PROFILE            default: codex-ec2
  AWS_REGION / AWS_DEFAULT_REGION
                               override region instead of profile config
  AWS_ARM64_INSTANCE_TYPE      default: t4g.micro
  AWS_ARM64_NAME_TAG           default: bpf-benchmark-arm64
  AWS_ARM64_AMI_ID             override the AL2023 ARM64 AMI
  AWS_ARM64_BENCH_ITERATIONS   default: 1
  AWS_ARM64_BENCH_WARMUPS      default: 0
  AWS_ARM64_BENCH_REPEAT       default: 10
EOF
}

ensure_dirs() {
    mkdir -p "$CACHE_DIR" "$STATE_DIR" "$RESULTS_DIR"
}

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
    die "AWS region is unset. Export AWS_REGION/AWS_DEFAULT_REGION or configure region in profile ${AWS_ARM64_PROFILE}."
}

_aws() {
    AWS_PAGER="" aws --profile "$AWS_ARM64_PROFILE" "$@"
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
    log "Checking tagged ${AWS_ARM64_NAME_TAG} instances in ${region}"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${AWS_ARM64_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].[InstanceId,InstanceType,State.Name,PublicIpAddress]' \
        --output table || true
}

ensure_no_tagged_instances() {
    local region="${1:-$(resolve_region)}"
    local instance_ids
    instance_ids="$(aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${AWS_ARM64_NAME_TAG}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].InstanceId' \
        --output text 2>/dev/null || true)"
    if [[ -n "$instance_ids" && "$instance_ids" != "None" ]]; then
        die "Residual ${AWS_ARM64_NAME_TAG} instances remain: ${instance_ids}"
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
    local key_path="${AWS_ARM64_KEY_PATH:-${STATE_KEY_PATH:-}}"
    [[ -n "$key_path" ]] || die "AWS_ARM64_KEY_PATH is required for SSH operations"
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
    local target="${AWS_ARM64_REMOTE_USER}@${ip}"
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
    local target="${AWS_ARM64_REMOTE_USER}@${ip}:${dest}"
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
    local target="${AWS_ARM64_REMOTE_USER}@${ip}:${src}"
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
            "Name=tag:Name,Values=${AWS_ARM64_NAME_TAG}" \
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

launch_instance() {
    ensure_dirs
    load_state
    ensure_aws_identity

    require_env_var AWS_ARM64_KEY_NAME
    require_env_var AWS_ARM64_KEY_PATH
    require_env_var AWS_ARM64_SECURITY_GROUP_ID
    require_env_var AWS_ARM64_SUBNET_ID

    local region key_path key_name instance_id="" instance_state="" instance_ip="" ami_id instance_record
    region="$(resolve_region)"
    key_path="${AWS_ARM64_KEY_PATH}"
    key_name="${AWS_ARM64_KEY_NAME}"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"

    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$STATE_INSTANCE_ID")"
    fi

    if [[ -z "$instance_id" || "$instance_id" == "None" || "$instance_state" == "terminated" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(lookup_existing_instance "$region")"
    fi

    if [[ -n "$instance_id" && "$instance_id" != "None" ]]; then
        log "Reusing existing EC2 instance ${instance_id} (${instance_state})"
    else
        if [[ -n "${AWS_ARM64_AMI_ID:-}" ]]; then
            ami_id="${AWS_ARM64_AMI_ID}"
        else
            ami_id="$(aws_cmd "$region" ssm get-parameter \
                --name "$AWS_ARM64_AMI_PARAM" \
                --query 'Parameter.Value' \
                --output text)"
        fi

        log "Launching ${AWS_ARM64_INSTANCE_TYPE} in ${region} using AMI ${ami_id}"
        instance_id="$(aws_cmd "$region" ec2 run-instances \
            --image-id "$ami_id" \
            --instance-type "$AWS_ARM64_INSTANCE_TYPE" \
            --key-name "$key_name" \
            --security-group-ids "$AWS_ARM64_SECURITY_GROUP_ID" \
            --subnet-id "$AWS_ARM64_SUBNET_ID" \
            --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${AWS_ARM64_NAME_TAG}},{Key=Project,Value=bpf-benchmark},{Key=Role,Value=arm64-baremetal}]" \
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

prepare_arm64_config() {
    local build_config="$ARM64_BUILD_DIR/.config"
    local cached_config="$CACHE_DIR/config-al2023-arm64"

    if [[ -f "$build_config" || ! -f "$cached_config" ]]; then
        return
    fi

    log "Seeding ARM64 build config from ${cached_config}"
    make -C "$ROOT_DIR" arm64-worktree >/dev/null
    mkdir -p "$ARM64_BUILD_DIR"
    cp "$cached_config" "$build_config"
    "$ARM64_WORKTREE_DIR/scripts/config" --file "$build_config" \
        -e BPF -e BPF_SYSCALL -e BPF_JIT \
        -e NET_VENDOR_AMAZON -e ENA_ETHERNET
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" olddefconfig >/dev/null
}

build_kernel_artifacts() {
    ensure_dirs
    if [[ -f "$KERNEL_RELEASE_FILE" ]]; then
        local cached_release cached_vmlinux cached_image cached_modules
        cached_release="$(<"$KERNEL_RELEASE_FILE")"
        cached_vmlinux="$ARTIFACT_DIR/vmlinux-$cached_release"
        cached_image="$ARTIFACT_DIR/vmlinuz-$cached_release.efi"
        cached_modules="$ARTIFACT_DIR/modules-$cached_release.tar.gz"
        if [[ -f "$cached_vmlinux" && -f "$cached_image" && -f "$cached_modules" ]]; then
            log "Reusing cached ARM64 kernel artifacts for ${cached_release}"
            printf '%s\n' "$cached_release"
            return
        fi
    fi

    prepare_arm64_config

    log "Building ARM64 kernel image"
    make -C "$ROOT_DIR" kernel-arm64 >&2

    local version_file="$ARM64_BUILD_DIR/include/config/kernel.release"
    [[ -f "$version_file" ]] || die "kernel release file missing: $version_file"
    local kernel_release
    kernel_release="$(<"$version_file")"

    if [[ ! -f "$ARM64_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" ]]; then
        log "Building ARM64 vmlinuz.efi"
        make -C "$ARM64_WORKTREE_DIR" O="$ARM64_BUILD_DIR" \
            ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
            vmlinuz.efi -j"$(nproc)" >&2
    fi

    if [[ ! -f "$ARM64_BUILD_DIR/modules.order" ]]; then
        log "Building ARM64 modules"
        make -C "$ARM64_WORKTREE_DIR" O="$ARM64_BUILD_DIR" \
            ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
            modules -j"$(nproc)" >&2
    fi

    mkdir -p "$ARTIFACT_DIR"
    rm -rf "$MODULES_STAGE_DIR"
    mkdir -p "$MODULES_STAGE_DIR"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        INSTALL_MOD_PATH="$MODULES_STAGE_DIR" modules_install >/dev/null
    rm -f "$MODULES_STAGE_DIR/lib/modules/$kernel_release/build" \
          "$MODULES_STAGE_DIR/lib/modules/$kernel_release/source"

    cp "$ARM64_BUILD_DIR/vmlinux" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    cp "$ARM64_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" \
        "$ARTIFACT_DIR/vmlinuz-$kernel_release.efi"
    tar -C "$MODULES_STAGE_DIR" -czf "$ARTIFACT_DIR/modules-$kernel_release.tar.gz" lib/modules
    printf '%s\n' "$kernel_release" > "$KERNEL_RELEASE_FILE"

    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        save_state "$STATE_INSTANCE_ID" "${STATE_INSTANCE_IP:-}" "${STATE_REGION:-${AWS_REGION_VALUE:-}}" \
            "${STATE_KEY_PATH:-${AWS_ARM64_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_ARM64_KEY_NAME:-}}" \
            "$kernel_release"
    fi

    printf '%s\n' "$kernel_release"
}

ensure_remote_runtime_prereqs() {
    local ip="$1"
    ssh_bash "$ip" <<'EOF'
set -euo pipefail
sudo dnf -y install bpftool dracut grubby tar gzip elfutils-libelf zlib zstd >/dev/null
command -v bpftool >/dev/null
command -v dracut >/dev/null
command -v grubby >/dev/null
EOF
}

setup_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "setup requires an instance IP"

    load_state
    log "Waiting for SSH on ${ip}"
    wait_for_ssh "$ip"
    ensure_remote_runtime_prereqs "$ip"

    local kernel_release kernel_image modules_tar verify_log
    kernel_release="$(build_kernel_artifacts)"
    kernel_image="$ARTIFACT_DIR/vmlinuz-$kernel_release.efi"
    modules_tar="$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
    verify_log="$RESULTS_DIR/setup_verify_${kernel_release}_$(date -u +%Y%m%d_%H%M%S).log"

    ssh_bash "$ip" "$AWS_ARM64_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
stage_dir="$1"
mkdir -p "$stage_dir/boot"
EOF

    scp_to "$ip" "$kernel_image" "$AWS_ARM64_REMOTE_KERNEL_STAGE_DIR/boot/"
    scp_to "$ip" "$modules_tar" "$AWS_ARM64_REMOTE_KERNEL_STAGE_DIR/"

    log "Installing kernel ${kernel_release} on ${ip}"
    ssh_bash "$ip" "$kernel_release" "$AWS_ARM64_REMOTE_KERNEL_STAGE_DIR" <<'EOF'
set -euo pipefail
ver="$1"
stage_dir="$2"
stock="/boot/vmlinuz-$(uname -r)"
title="Codex ARM64 ($ver)"

sudo tar -xzf "$stage_dir/modules-$ver.tar.gz" -C /
sudo install -o root -g root -m 0755 \
    "$stage_dir/boot/vmlinuz-$ver.efi" \
    "/boot/vmlinuz-$ver"
sudo depmod -a "$ver"
sudo dracut --force "/boot/initramfs-$ver.img" "$ver"
sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
    --initrd "/boot/initramfs-$ver.img" \
    --title "$title" \
    --copy-default
sudo grubby --set-default "$stock"
sudo grub2-reboot "$title"
# Detach the reboot so SSH exits cleanly and local control flow can wait for reconnect.
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
        "${STATE_KEY_PATH:-${AWS_ARM64_KEY_PATH:-}}" "${STATE_KEY_NAME:-${AWS_ARM64_KEY_NAME:-}}" \
        "$kernel_release"
    log "Setup verification log: ${verify_log}"
}

require_local_path() {
    local path="$1"
    local description="$2"
    [[ -e "$path" ]] || die "${description} not found: ${path}"
}

ensure_cross_arm64_artifacts() {
    if [[ ! -x "$ARM64_CROSS_RUNNER" || ! -x "$ARM64_CROSS_RUNNER_REAL" || \
          ! -x "$ARM64_CROSS_SCANNER" || ! -x "$ARM64_CROSS_SCANNER_REAL" || \
          ! -d "$ARM64_CROSS_LIB_DIR" ]]; then
        log "Building local AL2023-compatible ARM64 userspace artifacts"
        make -C "$ROOT_DIR" cross-arm64 >/dev/null
    fi

    file "$ARM64_CROSS_RUNNER_REAL" | grep -F "ARM aarch64" >/dev/null \
        || die "cross-built micro_exec is not an ARM64 binary: ${ARM64_CROSS_RUNNER_REAL}"
    file "$ARM64_CROSS_SCANNER_REAL" | grep -F "ARM aarch64" >/dev/null \
        || die "cross-built scanner is not an ARM64 binary: ${ARM64_CROSS_SCANNER_REAL}"
}

ensure_benchmark_bundle() {
    log "Preparing local ARM64 benchmark bundle"
    ensure_cross_arm64_artifacts
    make -C "$ROOT_DIR/micro" programs >/dev/null

    require_local_path "$ROOT_DIR/micro/programs/simple.bpf.o" "simple micro object"
    require_local_path "$ROOT_DIR/micro/programs/load_byte_recompose.bpf.o" "load_byte_recompose micro object"
    require_local_path "$ROOT_DIR/micro/generated-inputs/simple.mem" "simple input"
    require_local_path "$ROOT_DIR/micro/generated-inputs/load_byte_recompose.mem" "load_byte_recompose input"
    require_local_path "$ROOT_DIR/micro/policies/load_byte_recompose.yaml" "load_byte_recompose policy"
    require_local_path "$SCANNER_SMOKE_OBJECT" "scanner smoke object"
    require_local_path "$SCANNER_SMOKE_POLICY_DIR/${SCANNER_SMOKE_PROGRAM}.policy.yaml" "scanner smoke policy"

    rm -rf "$BENCHMARK_BUNDLE_DIR"
    mkdir -p \
        "$BENCHMARK_BUNDLE_DIR/runner/build" \
        "$BENCHMARK_BUNDLE_DIR/scanner/build" \
        "$BENCHMARK_BUNDLE_DIR/lib" \
        "$BENCHMARK_BUNDLE_DIR/micro/programs" \
        "$BENCHMARK_BUNDLE_DIR/micro/generated-inputs" \
        "$BENCHMARK_BUNDLE_DIR/micro/policies" \
        "$BENCHMARK_BUNDLE_DIR/corpus/build/katran" \
        "$BENCHMARK_BUNDLE_DIR/corpus/policies/katran/balancer"

    cp "$ARM64_CROSS_RUNNER" "$BENCHMARK_BUNDLE_DIR/runner/build/micro_exec"
    cp "$ARM64_CROSS_RUNNER_REAL" "$BENCHMARK_BUNDLE_DIR/runner/build/micro_exec.real"
    cp "$ARM64_CROSS_SCANNER" "$BENCHMARK_BUNDLE_DIR/scanner/build/bpf-jit-scanner"
    cp "$ARM64_CROSS_SCANNER_REAL" "$BENCHMARK_BUNDLE_DIR/scanner/build/bpf-jit-scanner.real"
    cp -a "$ARM64_CROSS_LIB_DIR/." "$BENCHMARK_BUNDLE_DIR/lib/"

    cp "$ROOT_DIR/micro/programs/simple.bpf.o" "$BENCHMARK_BUNDLE_DIR/micro/programs/"
    cp "$ROOT_DIR/micro/programs/load_byte_recompose.bpf.o" "$BENCHMARK_BUNDLE_DIR/micro/programs/"
    cp "$ROOT_DIR/micro/generated-inputs/simple.mem" "$BENCHMARK_BUNDLE_DIR/micro/generated-inputs/"
    cp "$ROOT_DIR/micro/generated-inputs/load_byte_recompose.mem" "$BENCHMARK_BUNDLE_DIR/micro/generated-inputs/"
    cp "$ROOT_DIR/micro/policies/load_byte_recompose.yaml" "$BENCHMARK_BUNDLE_DIR/micro/policies/"

    cp "$SCANNER_SMOKE_OBJECT" "$BENCHMARK_BUNDLE_DIR/corpus/build/katran/balancer.bpf.o"
    cp -a "$SCANNER_SMOKE_POLICY_DIR/." "$BENCHMARK_BUNDLE_DIR/corpus/policies/katran/balancer/"

    tar -C "$BENCHMARK_BUNDLE_DIR" -czf "$BENCHMARK_BUNDLE_TAR" .
}

benchmark_instance() {
    local ip="${1:-${STATE_INSTANCE_IP:-}}"
    [[ -n "$ip" ]] || die "benchmark requires an instance IP"

    ensure_benchmark_bundle
    wait_for_ssh "$ip"

    local stamp local_bundle_dir local_archive
    stamp="$(date -u +%Y%m%d_%H%M%S)"
    local_bundle_dir="$RESULTS_DIR/benchmark_${stamp}"
    local_archive="$RESULTS_DIR/benchmark_${stamp}.tar.gz"
    mkdir -p "$local_bundle_dir"

    ssh_bash "$ip" "$AWS_ARM64_REMOTE_STAGE_DIR" <<'EOF'
set -euo pipefail
root="$1"
rm -rf "$root"
mkdir -p "$root/results"
EOF
    scp_to "$ip" "$BENCHMARK_BUNDLE_TAR" "$AWS_ARM64_REMOTE_STAGE_DIR/"

    log "Running ARM64 micro + scanner smoke on ${ip}"
    ssh_bash "$ip" "$AWS_ARM64_REMOTE_STAGE_DIR" \
        "$AWS_ARM64_BENCH_ITERATIONS" "$AWS_ARM64_BENCH_WARMUPS" "$AWS_ARM64_BENCH_REPEAT" \
        "$SCANNER_SMOKE_PROGRAM" <<'EOF'
set -euo pipefail
root="$1"
iterations="$2"
warmups="$3"
repeat="$4"
scanner_program="$5"
results_dir="$root/results"
bpffs_root="/sys/fs/bpf/arm64-crossbuild-smoke"
pin_dir="$bpffs_root/progs"
map_dir="$bpffs_root/maps"
load_object="$root/corpus/build/katran/balancer.bpf.o"
policy_dir="$root/corpus/policies/katran/balancer"

cleanup() {
    sudo -n rm -rf "$bpffs_root" || true
}
trap cleanup EXIT

cd "$root"
tar -xzf benchmark-bundle.tar.gz
mkdir -p "$results_dir"
sudo -n mountpoint -q /sys/fs/bpf || sudo -n mount -t bpf bpf /sys/fs/bpf

run_series() {
    local name="$1"
    shift
    local warmup_index iteration_index
    for ((warmup_index = 0; warmup_index < warmups; warmup_index++)); do
        sudo -n "$root/runner/build/micro_exec" run-kernel "$@" >/dev/null
    done
    for ((iteration_index = 1; iteration_index <= iterations; iteration_index++)); do
        sudo -n "$root/runner/build/micro_exec" run-kernel "$@" \
            > "$results_dir/$name.iter${iteration_index}.json"
    done
}

attempt_loadall() {
    local label="$1"
    shift
    sudo -n bpftool "$@" >"$results_dir/$label.stdout" 2>"$results_dir/$label.stderr"
}

run_series simple.kernel \
    --program "$root/micro/programs/simple.bpf.o" \
    --memory "$root/micro/generated-inputs/simple.mem" \
    --io-mode staged \
    --input-size 64 \
    --repeat "$repeat"

run_series load_byte_recompose.kernel \
    --program "$root/micro/programs/load_byte_recompose.bpf.o" \
    --memory "$root/micro/generated-inputs/load_byte_recompose.mem" \
    --io-mode staged \
    --input-size 1032 \
    --repeat "$repeat"

run_series load_byte_recompose.kernel_recompile \
    --program "$root/micro/programs/load_byte_recompose.bpf.o" \
    --memory "$root/micro/generated-inputs/load_byte_recompose.mem" \
    --policy-file "$root/micro/policies/load_byte_recompose.yaml" \
    --io-mode staged \
    --input-size 1032 \
    --repeat "$repeat"

uname -r > "$results_dir/uname.txt"
ip -brief addr show ens5 > "$results_dir/network.txt" || ip -brief addr > "$results_dir/network.txt"
sudo -n grubby --default-kernel > "$results_dir/default-kernel.txt" || true
sudo -n grub2-editenv list > "$results_dir/grubenv.txt" || true
sudo -n bpftool version > "$results_dir/bpftool-version.txt"

sudo -n rm -rf "$bpffs_root"
sudo -n mkdir -p "$pin_dir" "$map_dir"

if [[ -r /sys/kernel/btf/vmlinux ]]; then
    if ! attempt_loadall scanner.loadall.kernel_btf \
        prog loadall "$load_object" "$pin_dir" kernel_btf /sys/kernel/btf/vmlinux type xdp pinmaps "$map_dir"; then
        if grep -qi 'kernel_btf' "$results_dir/scanner.loadall.kernel_btf.stderr" && \
           grep -Eqi 'expected no more arguments|unknown option|unrecognized option|invalid argument' \
               "$results_dir/scanner.loadall.kernel_btf.stderr"; then
            attempt_loadall scanner.loadall.fallback \
                prog loadall "$load_object" "$pin_dir" type xdp pinmaps "$map_dir"
        else
            cat "$results_dir/scanner.loadall.kernel_btf.stderr" >&2
            exit 1
        fi
    fi
else
    attempt_loadall scanner.loadall.no_btf \
        prog loadall "$load_object" "$pin_dir" type xdp pinmaps "$map_dir"
fi

sudo -n test -e "$pin_dir/$scanner_program"
sudo -n bpftool -j prog show pinned "$pin_dir/$scanner_program" > "$results_dir/scanner.prog.json"
prog_id="$(sudo -n bpftool prog show pinned "$pin_dir/$scanner_program" | awk '/^[0-9]+:/ {sub(/:/,"",$1); print $1; exit}')"
test -n "$prog_id"
printf '%s\n' "$prog_id" > "$results_dir/scanner.prog_id.txt"

sudo -n "$root/scanner/build/bpf-jit-scanner" enumerate --prog-id "$prog_id" --json \
    > "$results_dir/scanner.enumerate.json"
sudo -n "$root/scanner/build/bpf-jit-scanner" enumerate --prog-id "$prog_id" --recompile \
    --policy-dir "$policy_dir" --json > "$results_dir/scanner.recompile.json"

tar -C "$root" -czf "$root/results.tar.gz" results
EOF

    scp_from "$ip" "$AWS_ARM64_REMOTE_STAGE_DIR/results.tar.gz" "$local_archive"
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

full_lifecycle() {
    ensure_benchmark_bundle

    local instance_id="" instance_ip=""
    cleanup() {
        local status=$?
        local cleanup_instance_id="${FULL_LIFECYCLE_INSTANCE_ID:-}"
        trap - EXIT
        if [[ -n "$cleanup_instance_id" ]]; then
            if terminate_instance "$cleanup_instance_id"; then
                log "Terminated ${cleanup_instance_id}"
            else
                warn "Automatic termination failed for ${cleanup_instance_id}; terminate it manually."
            fi
        fi
        exit "$status"
    }
    trap cleanup EXIT

    launch_instance >/tmp/aws-arm64-launch.$$ 
    instance_id="$(awk -F= '/^INSTANCE_ID=/{print $2}' /tmp/aws-arm64-launch.$$)"
    instance_ip="$(awk -F= '/^INSTANCE_IP=/{print $2}' /tmp/aws-arm64-launch.$$)"
    rm -f /tmp/aws-arm64-launch.$$
    [[ -n "$instance_id" && -n "$instance_ip" ]] || die "failed to capture launched instance state"
    FULL_LIFECYCLE_INSTANCE_ID="$instance_id"

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
