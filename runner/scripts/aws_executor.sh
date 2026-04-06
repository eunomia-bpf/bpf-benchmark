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
HOST_PYTHON_BIN="${RUN_HOST_PYTHON_BIN:-}"
[[ -n "$HOST_PYTHON_BIN" ]] || {
    printf '[aws-executor][ERROR] manifest host python is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

RUN_AWS_INSTANCE_MODE="${RUN_AWS_INSTANCE_MODE:-shared}"
case "$RUN_AWS_INSTANCE_MODE" in
    shared|dedicated) ;;
    *)
        printf '[aws-executor][ERROR] unsupported RUN_AWS_INSTANCE_MODE: %s\n' "$RUN_AWS_INSTANCE_MODE" >&2
        exit 1
        ;;
esac

MANIFEST_HASH="$(sha256sum "$MANIFEST_PATH" | awk '{print $1}')"
RUN_TOKEN="$(basename "$MANIFEST_PATH" .env)"
TARGET_CACHE_DIR="$ROOT_DIR/.cache/${RUN_TARGET_NAME}"
SHARED_STATE_DIR="$TARGET_CACHE_DIR/state"
RUN_STATE_DIR="$TARGET_CACHE_DIR/run-state/$RUN_TOKEN"
if [[ "$ACTION" == "run" && "$RUN_AWS_INSTANCE_MODE" == "dedicated" ]]; then
    RUN_NAME_TAG="${RUN_NAME_TAG}-${RUN_TOKEN}"
    STATE_DIR="$RUN_STATE_DIR"
else
    STATE_DIR="$SHARED_STATE_DIR"
fi
STATE_FILE="$STATE_DIR/instance.env"
RUN_PREP_ROOT="$TARGET_CACHE_DIR/runs/$RUN_TOKEN"
ARTIFACT_DIR="$RUN_PREP_ROOT/artifacts"
RESULTS_DIR="$TARGET_CACHE_DIR/results"
MODULES_STAGE_DIR="$RUN_PREP_ROOT/modules-stage"
LOCAL_REPO_ROOT="$RUN_PREP_ROOT/repos"
LOCAL_PROMOTE_ROOT="$RUN_PREP_ROOT/bundle-inputs"
SETUP_ARTIFACT_CACHE_ROOT="$TARGET_CACHE_DIR/setup-artifacts"
KERNEL_DIR="${KERNEL_DIR:-$ROOT_DIR/vendor/linux-framework}"
X86_KERNEL_BUILD_LOCK_FILE="${X86_KERNEL_BUILD_LOCK_FILE:-$ROOT_DIR/.cache/kernel-build-x86.lock}"
ARM64_KERNEL_BUILD_LOCK_FILE="${ARM64_KERNEL_BUILD_LOCK_FILE:-$ROOT_DIR/.cache/kernel-build-arm64.lock}"
KERNEL_DEFCONFIG_SRC="${KERNEL_DEFCONFIG_SRC:-$ROOT_DIR/vendor/bpfrejit_defconfig}"
KERNEL_CONFIG_STAMP_FILE="$KERNEL_DIR/.bpfrejit_config.stamp"
X86_BZIMAGE="${X86_BZIMAGE:-$KERNEL_DIR/arch/x86/boot/bzImage}"
X86_VMLINUX="${X86_VMLINUX:-$KERNEL_DIR/vmlinux}"
X86_KINSN_MODULE_DIR="${X86_KINSN_MODULE_DIR:-$ROOT_DIR/module/x86}"
X86_SETUP_ARTIFACT_ROOT="${X86_SETUP_ARTIFACT_ROOT:-$SETUP_ARTIFACT_CACHE_ROOT/x86}"
X86_KINSN_MODULE_BUILD_SRC="${X86_KINSN_MODULE_BUILD_SRC:-$RUN_PREP_ROOT/module-src/x86}"
X86_KINSN_MODULE_STAGE_DIR="${X86_KINSN_MODULE_STAGE_DIR:-$RUN_PREP_ROOT/test-artifacts/kinsn-modules/x86}"
X86_TEST_ARTIFACTS_ROOT="${X86_TEST_ARTIFACTS_ROOT:-$RUN_PREP_ROOT/test-artifacts}"
X86_RUNNER_BUILD_DIR="${X86_RUNNER_BUILD_DIR:-$LOCAL_PROMOTE_ROOT/runner/build}"
X86_RUNNER="${X86_RUNNER:-$X86_RUNNER_BUILD_DIR/micro_exec}"
X86_DAEMON_TARGET_DIR="${X86_DAEMON_TARGET_DIR:-$LOCAL_PROMOTE_ROOT/daemon/target}"
X86_DAEMON="${X86_DAEMON:-$X86_DAEMON_TARGET_DIR/release/bpfrejit-daemon}"
X86_TEST_UNITTEST_BUILD_DIR="${X86_TEST_UNITTEST_BUILD_DIR:-$X86_TEST_ARTIFACTS_ROOT/unittest/build}"
X86_TEST_NEGATIVE_BUILD_DIR="${X86_TEST_NEGATIVE_BUILD_DIR:-$X86_TEST_ARTIFACTS_ROOT/negative/build}"
X86_UPSTREAM_SELFTEST_DIR="${X86_UPSTREAM_SELFTEST_DIR:-$X86_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests}"
MICRO_PROGRAMS_GENERATED_DIR="${MICRO_PROGRAMS_GENERATED_DIR:-$LOCAL_PROMOTE_ROOT/micro/programs}"
ARM64_WORKTREE_DIR="${ARM64_WORKTREE_DIR:-$ROOT_DIR/.worktrees/linux-framework-arm64-src}"
ARM64_AWS_BUILD_DIR="${ARM64_AWS_BUILD_DIR:-$ROOT_DIR/.cache/aws-arm64/kernel-build}"
ARM64_AWS_BASE_CONFIG="${ARM64_AWS_BASE_CONFIG:-$ROOT_DIR/.cache/aws-arm64/config-al2023-arm64}"
ARM64_SETUP_ARTIFACT_ROOT="${ARM64_SETUP_ARTIFACT_ROOT:-$ROOT_DIR/.cache/aws-arm64/setup-artifacts}"
ARM64_CROSSBUILD_ROOT="${ARM64_CROSSBUILD_ROOT:-$RUN_PREP_ROOT/arm64-cross}"
ARM64_CROSSBUILD_OUTPUT_DIR="${ARM64_CROSSBUILD_OUTPUT_DIR:-$LOCAL_PROMOTE_ROOT}"
ARM64_CROSSBUILD_BUILD_ROOT="${ARM64_CROSSBUILD_BUILD_ROOT:-$ARM64_CROSSBUILD_ROOT/build}"
ARM64_CROSSBUILD_CARGO_HOME="${ARM64_CROSSBUILD_CARGO_HOME:-$ARM64_CROSSBUILD_ROOT/cargo-home}"
ARM64_KINSN_MODULE_BUILD_SRC="${ARM64_KINSN_MODULE_BUILD_SRC:-$RUN_PREP_ROOT/module-src/arm64}"
ARM64_KINSN_MODULE_STAGE_DIR="${ARM64_KINSN_MODULE_STAGE_DIR:-$RUN_PREP_ROOT/test-artifacts/kinsn-modules/arm64}"
ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR="${ARM64_UPSTREAM_TEST_KMODS_SOURCE_DIR:-$ROOT_DIR/vendor/linux-framework/tools/testing/selftests/bpf/test_kmods}"
ARM64_UPSTREAM_TEST_KMODS_DIR="${ARM64_UPSTREAM_TEST_KMODS_DIR:-$ROOT_DIR/.cache/aws-arm64/upstream-selftests-kmods-arm64}"
ARM64_TEST_ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-$RUN_PREP_ROOT/test-artifacts}"
ARM64_TEST_UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/unittest/build-arm64}"
ARM64_TEST_NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/negative/build-arm64}"
ARM64_UPSTREAM_SELFTEST_DIR="${ARM64_UPSTREAM_SELFTEST_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests}"
ARM64_HOST_DAEMON_ROOT="${ARM64_HOST_DAEMON_ROOT:-$RUN_PREP_ROOT/arm64-daemon-host-cross}"
ARM64_HOST_DAEMON_TARGET_DIR="${ARM64_HOST_DAEMON_TARGET_DIR:-$ARM64_HOST_DAEMON_ROOT/target}"
ARM64_HOST_DAEMON_OUTPUT_DIR="${ARM64_HOST_DAEMON_OUTPUT_DIR:-$ARM64_HOST_DAEMON_ROOT/output}"
ARM64_HOST_DAEMON_BINARY="${ARM64_HOST_DAEMON_BINARY:-$ARM64_HOST_DAEMON_OUTPUT_DIR/bpfrejit-daemon}"
ARM64_HOST_DAEMON_CARGO_HOME="${ARM64_HOST_DAEMON_CARGO_HOME:-$ARM64_HOST_DAEMON_ROOT/cargo-home}"
ARM64_HOST_SCX_ROOT="${ARM64_HOST_SCX_ROOT:-$RUN_PREP_ROOT/arm64-scx-host-cross}"
ARM64_HOST_SCX_BUILD_ROOT="${ARM64_HOST_SCX_BUILD_ROOT:-$ARM64_HOST_SCX_ROOT/build}"
ARM64_HOST_SCX_CARGO_HOME="${ARM64_HOST_SCX_CARGO_HOME:-$ARM64_HOST_SCX_ROOT/cargo-home}"
ARM64_SOURCE_REPO_ROOT="${ARM64_SOURCE_REPO_ROOT:-$LOCAL_REPO_ROOT}"
ARM64_SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$ROOT_DIR/.cache/aws-arm64/sysroot}"
ARM64_SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$ROOT_DIR/.cache/aws-arm64/sysroot.lock}"
ARM64_SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
ARM64_SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-${RUN_REMOTE_USER:-}}"
ARM64_SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-${RUN_AWS_KEY_PATH:-}}"
ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec.real}"
ARM64_CROSS_DAEMON="${ARM64_CROSS_DAEMON:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon}"
ARM64_CROSS_DAEMON_REAL="${ARM64_CROSS_DAEMON_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon.real}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/lib}"
ARM64_KATRAN_SERVER_BINARY="${ARM64_KATRAN_SERVER_BINARY:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/bin/katran_server_grpc}"
ARM64_KATRAN_SERVER_LIB_DIR="${ARM64_KATRAN_SERVER_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/lib}"
CROSS_COMPILE_PREFIX="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}"
AWS_REGION_VALUE="${RUN_AWS_REGION:-}"
AWS_PROFILE_VALUE="${RUN_AWS_PROFILE:-}"
BUILD_KERNEL_RELEASE=""
STATE_INSTANCE_ID=""
STATE_INSTANCE_IP=""
STATE_REGION=""
STATE_KERNEL_RELEASE=""
DEDICATED_RUN_ACTIVE=0

log() {
    printf '[aws-executor] %s\n' "$*" >&2
}

aws_instance_mode_is_shared() {
    [[ "$RUN_AWS_INSTANCE_MODE" == "shared" ]]
}

aws_instance_mode_is_dedicated() {
    [[ "$RUN_AWS_INSTANCE_MODE" == "dedicated" ]]
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

require_nonempty_dir() {
    local path="$1"
    local description="$2"
    [[ -d "$path" ]] || die "${description} is not a directory: ${path}"
    find "$path" -mindepth 1 -print -quit 2>/dev/null | grep -q . || die "${description} is empty: ${path}"
}

dir_has_entries() {
    local path="$1"
    [[ -d "$path" ]] || return 1
    find "$path" -mindepth 1 -maxdepth 1 -print -quit 2>/dev/null | grep -q .
}

configure_arm64_sysroot_contract() {
    [[ "${RUN_TARGET_NAME:-}" == "aws-arm64" ]] || return 0
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || die "ARM64 sysroot source requires a resolved instance IP"
    [[ -n "${RUN_REMOTE_USER:-}" ]] || die "ARM64 sysroot source requires RUN_REMOTE_USER"
    [[ -n "${RUN_AWS_KEY_PATH:-}" ]] || die "ARM64 sysroot source requires RUN_AWS_KEY_PATH"
    ARM64_SYSROOT_REMOTE_HOST="$STATE_INSTANCE_IP"
    ARM64_SYSROOT_REMOTE_USER="$RUN_REMOTE_USER"
    ARM64_SYSROOT_SSH_KEY_PATH="$RUN_AWS_KEY_PATH"
}

git_path_is_clean() {
    local repo_root="$1"
    local pathspec="${2:-}"
    if [[ -n "$pathspec" ]]; then
        git -C "$repo_root" diff --quiet -- "$pathspec" || return 1
        git -C "$repo_root" diff --cached --quiet -- "$pathspec" || return 1
    else
        git -C "$repo_root" diff --quiet || return 1
        git -C "$repo_root" diff --cached --quiet || return 1
    fi
}

snapshot_git_subtree() {
    local repo_root="$1"
    local src_rel="$2"
    local dest="$3"
    local strip_components=0
    git -C "$repo_root" rev-parse --verify HEAD >/dev/null 2>&1 \
        || die "expected git checkout for promoted snapshot: ${repo_root}"
    if [[ -n "$src_rel" ]]; then
        git_path_is_clean "$repo_root" "$src_rel" \
            || die "git subtree has local modifications and cannot be promoted: ${repo_root}/${src_rel}"
        strip_components="$(awk -F/ '{print NF}' <<<"$src_rel")"
    else
        git_path_is_clean "$repo_root" \
            || die "git checkout has local modifications and cannot be promoted: ${repo_root}"
    fi
    mkdir -p "$dest"
    if [[ -n "$src_rel" ]]; then
        git -C "$repo_root" archive --format=tar HEAD -- "$src_rel" \
            | tar -xf - -C "$dest" --strip-components="$strip_components"
    else
        git -C "$repo_root" archive --format=tar HEAD | tar -xf - -C "$dest"
    fi
    find "$dest" -mindepth 1 -print -quit 2>/dev/null | grep -q . \
        || die "promoted snapshot is empty: ${repo_root}${src_rel:+/${src_rel}}"
}

stage_module_binaries() {
    local source_dir="$1"
    local stage_dir="$2"
    local ko_count
    require_local_path "$source_dir" "kinsn module source dir"
    rm -rf "$stage_dir"
    mkdir -p "$stage_dir"
    find "$source_dir" -maxdepth 1 -type f -name '*.ko' -exec cp '{}' "$stage_dir/" \;
    ko_count="$(find "$stage_dir" -maxdepth 1 -name '*.ko' | wc -l | tr -d ' ')"
    [[ "$ko_count" -gt 0 ]] || die "no kinsn modules staged under ${stage_dir}"
}

snapshot_kinsn_module_source_tree() {
    local arch_dir_rel="$1"
    local dest_dir="$2"
    local parent_dir
    parent_dir="$(dirname "$dest_dir")"
    rm -rf "$dest_dir" "$parent_dir/include"
    mkdir -p "$parent_dir"
    snapshot_git_subtree "$ROOT_DIR" "module/include" "$parent_dir/include"
    snapshot_git_subtree "$ROOT_DIR" "$arch_dir_rel" "$dest_dir"
}

x86_cached_kinsn_modules_dir() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/kinsn-modules/x86"
}

x86_cached_setup_config_fingerprint_path() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/config.sha256"
}

x86_setup_config_fingerprint() {
    require_local_path "$KERNEL_DIR/.config" "x86 kernel config"
    sha256sum "$KERNEL_DIR/.config" | awk '{print $1}'
}

x86_cached_setup_matches_config() {
    local cache_dir="$1"
    local expected_fingerprint="$2"
    local fingerprint_path actual_fingerprint
    fingerprint_path="$(x86_cached_setup_config_fingerprint_path "$cache_dir")"
    [[ -f "$fingerprint_path" ]] || return 1
    actual_fingerprint="$(<"$fingerprint_path")"
    [[ -n "$actual_fingerprint" && "$actual_fingerprint" == "$expected_fingerprint" ]]
}

x86_write_cached_setup_fingerprint() {
    local cache_dir="$1"
    local fingerprint="$2"
    printf '%s\n' "$fingerprint" >"$(x86_cached_setup_config_fingerprint_path "$cache_dir")"
}

x86_cached_setup_artifacts_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    local config_fingerprint="$4"
    cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" \
        && x86_cached_setup_matches_config "$cache_dir" "$config_fingerprint"
}

x86_reuse_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    local config_fingerprint="$4"
    x86_cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" "$config_fingerprint" \
        || return 1
    link_cached_setup_artifacts "$cache_dir" "$kernel_release" "$kernel_image_filename"
    BUILD_KERNEL_RELEASE="$kernel_release"
    return 0
}

x86_cached_kinsn_modules_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local module_dir module_path actual_release
    module_dir="$(x86_cached_kinsn_modules_dir "$cache_dir")"
    [[ -d "$module_dir" ]] || return 1
    find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print -quit 2>/dev/null | grep -q . || return 1
    while IFS= read -r -d '' module_path; do
        actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
        [[ "$actual_release" == "$kernel_release" ]] || return 1
    done < <(find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print0)
    return 0
}

build_x86_kinsn_modules_into_cache() {
    local cache_dir="$1"
    local cached_module_dir
    snapshot_kinsn_module_source_tree "module/x86" "$X86_KINSN_MODULE_BUILD_SRC"
    make -C "$X86_KINSN_MODULE_BUILD_SRC" KDIR="$KERNEL_DIR" clean >/dev/null
    make -C "$X86_KINSN_MODULE_BUILD_SRC" KDIR="$KERNEL_DIR" >/dev/null
    cached_module_dir="$(x86_cached_kinsn_modules_dir "$cache_dir")"
    stage_module_binaries "$X86_KINSN_MODULE_BUILD_SRC" "$cached_module_dir"
}

arm64_cached_kinsn_modules_dir() {
    local cache_dir="$1"
    printf '%s\n' "$cache_dir/kinsn-modules/arm64"
}

arm64_cached_kinsn_modules_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local module_dir module_path actual_release
    module_dir="$(arm64_cached_kinsn_modules_dir "$cache_dir")"
    [[ -d "$module_dir" ]] || return 1
    find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print -quit 2>/dev/null | grep -q . || return 1
    while IFS= read -r -d '' module_path; do
        actual_release="$(modinfo -F vermagic "$module_path" 2>/dev/null | awk '{print $1}')"
        [[ "$actual_release" == "$kernel_release" ]] || return 1
    done < <(find "$module_dir" -maxdepth 1 -type f -name '*.ko' -print0)
    return 0
}

cached_setup_artifacts_ready() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    [[ -f "$cache_dir/vmlinux-$kernel_release" ]] \
        && [[ -f "$cache_dir/$kernel_image_filename" ]] \
        && [[ -f "$cache_dir/modules-$kernel_release.tar.gz" ]]
}

link_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    rm -rf "$ARTIFACT_DIR"
    mkdir -p "$ARTIFACT_DIR"
    ln -sfn "$cache_dir/vmlinux-$kernel_release" "$ARTIFACT_DIR/vmlinux-$kernel_release"
    ln -sfn "$cache_dir/$kernel_image_filename" "$ARTIFACT_DIR/$kernel_image_filename"
    ln -sfn "$cache_dir/modules-$kernel_release.tar.gz" "$ARTIFACT_DIR/modules-$kernel_release.tar.gz"
}

reuse_cached_setup_artifacts() {
    local cache_dir="$1"
    local kernel_release="$2"
    local kernel_image_filename="$3"
    cached_setup_artifacts_ready "$cache_dir" "$kernel_release" "$kernel_image_filename" || return 1
    link_cached_setup_artifacts "$cache_dir" "$kernel_release" "$kernel_image_filename"
    BUILD_KERNEL_RELEASE="$kernel_release"
    return 0
}

ensure_dirs() {
    mkdir -p "$TARGET_CACHE_DIR" "$STATE_DIR" "$ARTIFACT_DIR" "$RESULTS_DIR" "$RUN_PREP_ROOT"
}

with_locked_file() {
    local lock_path="$1"
    local lock_fd
    local status=0
    shift
    mkdir -p "$(dirname "$lock_path")"
    exec {lock_fd}>"$lock_path"
    flock "$lock_fd"
    "$@" || status=$?
    exec {lock_fd}>&-
    return "$status"
}

with_x86_kernel_lock() {
    with_locked_file "$X86_KERNEL_BUILD_LOCK_FILE" "$@"
}

with_arm64_kernel_lock() {
    with_locked_file "$ARM64_KERNEL_BUILD_LOCK_FILE" "$@"
}

with_state_lock() {
    with_locked_file "$STATE_DIR/instance.lock" "$@"
}

with_remote_execution_lock() {
    with_locked_file "$SHARED_STATE_DIR/remote-exec.lock" "$@"
}

remote_prereq_dir() {
    printf '%s\n' "$RUN_REMOTE_STAGE_DIR/prereq/$RUN_TOKEN"
}

remote_prereq_stamp_path() {
    printf '%s\n' "$(remote_prereq_dir)/prereqs.ready"
}

remote_prereq_workload_tool_root() {
    printf '%s\n' "$(remote_prereq_dir)/workload-tools"
}

remote_prereq_workload_tool_bin() {
    printf '%s\n' "$(remote_prereq_workload_tool_root)/bin"
}

load_state() {
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
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
    local kernel_release="${4:-}"
    ensure_dirs
    cat >"$STATE_FILE" <<EOF
STATE_INSTANCE_ID=$(printf '%q' "$instance_id")
STATE_INSTANCE_IP=$(printf '%q' "$instance_ip")
STATE_REGION=$(printf '%q' "$region")
STATE_KERNEL_RELEASE=$(printf '%q' "$kernel_release")
EOF
}

clear_state() {
    rm -f "$STATE_FILE"
    unset \
        STATE_INSTANCE_ID \
        STATE_INSTANCE_IP \
        STATE_REGION \
        STATE_KERNEL_RELEASE
    STATE_INSTANCE_ID=""
    STATE_INSTANCE_IP=""
    STATE_REGION=""
    STATE_KERNEL_RELEASE=""
}

cleanup_local_run_prep_root() {
    [[ -n "${RUN_PREP_ROOT:-}" ]] || return 0
    [[ -e "$RUN_PREP_ROOT" ]] || return 0
    rm -rf "$RUN_PREP_ROOT" 2>/dev/null || true
    if [[ -e "$RUN_PREP_ROOT" ]]; then
        sudo rm -rf "$RUN_PREP_ROOT" || true
    fi
}

resolve_region() {
    [[ -n "$AWS_REGION_VALUE" ]] || die "manifest AWS region is empty for ${RUN_TARGET_NAME}"
    printf '%s\n' "$AWS_REGION_VALUE"
}

_aws() {
    [[ -n "$AWS_PROFILE_VALUE" ]] || die "manifest AWS profile is empty for ${RUN_TARGET_NAME}"
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
    local ami_id="$2"
    local key_name="$3"
    local security_group_id="$4"
    local subnet_id="$5"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Name,Values=${RUN_NAME_TAG}" \
            "Name=image-id,Values=${ami_id}" \
            "Name=instance-type,Values=${RUN_INSTANCE_TYPE}" \
            "Name=key-name,Values=${key_name}" \
            "Name=instance.group-id,Values=${security_group_id}" \
            "Name=subnet-id,Values=${subnet_id}" \
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

lookup_target_instance_ids() {
    local region="$1"
    aws_cmd "$region" ec2 describe-instances \
        --filters \
            "Name=tag:Project,Values=bpf-benchmark" \
            "Name=tag:Role,Values=${RUN_TARGET_NAME}" \
            "Name=instance-state-name,Values=pending,running,stopping,stopped" \
        --query 'Reservations[].Instances[].InstanceId' \
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

describe_instance_type() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query 'Reservations[0].Instances[0].InstanceType' \
        --output text 2>/dev/null || true
}

describe_instance_launch_contract() {
    local region="$1"
    local instance_id="$2"
    aws_cmd "$region" ec2 describe-instances \
        --instance-ids "$instance_id" \
        --query "Reservations[0].Instances[0].[ImageId,KeyName,SubnetId,join(',', sort_by(SecurityGroups,&GroupId)[].GroupId)]" \
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
        -i "${RUN_AWS_KEY_PATH}"
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

    local region key_path key_name security_group_id subnet_id instance_id="" instance_state="" instance_ip="" instance_type="" ami_id root_device_name current_image_id="" current_key_name="" current_subnet_id="" current_security_groups=""
    region="$(resolve_region)"
    key_name="${RUN_AWS_KEY_NAME:-}"
    key_path="${RUN_AWS_KEY_PATH:-}"
    security_group_id="${RUN_AWS_SECURITY_GROUP_ID:-}"
    subnet_id="${RUN_AWS_SUBNET_ID:-}"
    [[ -n "$key_name" ]] || die "AWS key name is unset for ${RUN_TARGET_NAME}"
    [[ -n "$key_path" ]] || die "AWS key path is unset for ${RUN_TARGET_NAME}"
    [[ -n "$security_group_id" ]] || die "AWS security group id is unset for ${RUN_TARGET_NAME}"
    [[ -n "$subnet_id" ]] || die "AWS subnet id is unset for ${RUN_TARGET_NAME}"
    [[ -f "$key_path" ]] || die "SSH key does not exist: $key_path"
    [[ "$RUN_ROOT_VOLUME_GB" =~ ^[0-9]+$ ]] || die "RUN_ROOT_VOLUME_GB must be a positive integer"
    (( RUN_ROOT_VOLUME_GB > 0 )) || die "RUN_ROOT_VOLUME_GB must be greater than zero"
    if [[ -n "${RUN_AMI_ID:-}" ]]; then
        ami_id="${RUN_AMI_ID}"
    else
        ami_id="$(aws_cmd "$region" ssm get-parameter --name "$RUN_AMI_PARAM" --query 'Parameter.Value' --output text)"
    fi

    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$STATE_INSTANCE_ID")"
        instance_type="$(describe_instance_type "$region" "$STATE_INSTANCE_ID")"
        read -r current_image_id current_key_name current_subnet_id current_security_groups <<<"$(describe_instance_launch_contract "$region" "$STATE_INSTANCE_ID")"
        case "$instance_state" in
            stopped|stopping)
                terminate_instance "${STATE_INSTANCE_ID}"
                instance_id=""
                instance_state=""
                instance_ip=""
                ;;
        esac
        if [[ -n "$instance_id" && "$instance_id" != "None" && "$instance_type" != "$RUN_INSTANCE_TYPE" ]]; then
            terminate_instance "${STATE_INSTANCE_ID}"
            instance_id=""
            instance_state=""
            instance_ip=""
        fi
        if [[ -n "$instance_id" && "$instance_id" != "None" ]] && { [[ "$current_image_id" != "$ami_id" ]] || [[ "$current_key_name" != "$key_name" ]] || [[ "$current_subnet_id" != "$subnet_id" ]] || [[ "$current_security_groups" != "$security_group_id" ]]; }; then
            terminate_instance "${STATE_INSTANCE_ID}"
            instance_id=""
            instance_state=""
            instance_ip=""
        fi
    fi
    if [[ -z "$instance_id" || "$instance_id" == "None" ]] || ! instance_state_is_reusable "$instance_state"; then
        read -r instance_id instance_state instance_ip <<<"$(lookup_existing_instance "$region" "$ami_id" "$key_name" "$security_group_id" "$subnet_id")"
        if [[ -n "$instance_id" && "$instance_id" != "None" ]]; then
            read -r current_image_id current_key_name current_subnet_id current_security_groups <<<"$(describe_instance_launch_contract "$region" "$instance_id")"
            if [[ "$current_image_id" != "$ami_id" || "$current_key_name" != "$key_name" || "$current_subnet_id" != "$subnet_id" || "$current_security_groups" != "$security_group_id" ]]; then
                instance_id=""
                instance_state=""
                instance_ip=""
            fi
        fi
    fi

    if [[ -z "$instance_id" || "$instance_id" == "None" ]]; then
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

    save_state "$instance_id" "${instance_ip:-}" "$region" "${STATE_KERNEL_RELEASE:-}"
    aws_cmd "$region" ec2 wait instance-running --instance-ids "$instance_id"
    aws_cmd "$region" ec2 wait instance-status-ok --instance-ids "$instance_id"
    read -r instance_id instance_state instance_ip <<<"$(describe_instance "$region" "$instance_id")"
    [[ -n "$instance_ip" && "$instance_ip" != "None" ]] || die "instance ${instance_id} has no public IP"
    save_state "$instance_id" "$instance_ip" "$region" "${STATE_KERNEL_RELEASE:-}"
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
    local kernel_release modules_root cached_dir cached_stage config_fingerprint
    BUILD_KERNEL_RELEASE=""
    prepare_x86_aws_config_locked
    config_fingerprint="$(x86_setup_config_fingerprint)"
    log "Building x86 AWS kernel image and modules"
    make -C "$KERNEL_DIR" -j"$(nproc)" bzImage modules_prepare >/dev/null
    if [[ -f "$KERNEL_DIR/vmlinux.symvers" ]]; then
        cp "$KERNEL_DIR/vmlinux.symvers" "$KERNEL_DIR/Module.symvers"
    fi

    kernel_release="$(<"$KERNEL_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "x86 kernel release is empty"
    cached_dir="$X86_SETUP_ARTIFACT_ROOT/$kernel_release"
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' \
            || rm -rf "$cached_dir"
    fi
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        x86_cached_kinsn_modules_ready "$cached_dir" "$kernel_release" || rm -rf "$cached_dir"
    fi
    if x86_reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release" "$config_fingerprint"; then
        return 0
    fi
    cached_stage="$cached_dir/modules-stage"
    rm -rf "$cached_dir"
    mkdir -p "$cached_dir" "$cached_stage"
    make -C "$KERNEL_DIR" -j"$(nproc)" modules >/dev/null
    make -C "$KERNEL_DIR" INSTALL_MOD_PATH="$cached_stage" modules_install >/dev/null
    rm -f "$cached_stage/lib/modules/$kernel_release/build" "$cached_stage/lib/modules/$kernel_release/source"
    modules_root="$cached_stage/lib/modules/$kernel_release"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme-core.ko" "x86 nvme-core module"
    require_local_path "$modules_root/kernel/drivers/nvme/host/nvme.ko" "x86 nvme module"
    require_local_path "$modules_root/kernel/fs/ext4/ext4.ko" "x86 ext4 module"
    require_local_path "$modules_root/kernel/fs/xfs/xfs.ko" "x86 xfs module"
    require_local_path "$modules_root/kernel/drivers/block/virtio_blk.ko" "x86 virtio_blk module"
    cp "$X86_VMLINUX" "$cached_dir/vmlinux-$kernel_release"
    cp "$X86_BZIMAGE" "$cached_dir/bzImage-$kernel_release"
    tar -C "$cached_stage" -czf "$cached_dir/modules-$kernel_release.tar.gz" lib/modules
    rm -rf "$cached_stage"
    modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' \
        || die "generated x86 modules archive is invalid"
    build_x86_kinsn_modules_into_cache "$cached_dir"
    x86_cached_kinsn_modules_ready "$cached_dir" "$kernel_release" \
        || die "generated x86 kinsn module cache is invalid"
    x86_write_cached_setup_fingerprint "$cached_dir" "$config_fingerprint"
    link_cached_setup_artifacts "$cached_dir" "$kernel_release" "bzImage-$kernel_release"
    BUILD_KERNEL_RELEASE="$kernel_release"
}

build_x86_kernel_artifacts() {
    ensure_dirs
    with_x86_kernel_lock build_x86_kernel_artifacts_locked
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
    tmp_config="$(mktemp "${TARGET_CACHE_DIR}/config-al2023-arm64.XXXXXX")"
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
    snapshot_kinsn_module_source_tree "module/arm64" "$ARM64_KINSN_MODULE_BUILD_SRC"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules_prepare >/dev/null
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        M="$ARM64_KINSN_MODULE_BUILD_SRC" modules >/dev/null
}

build_arm64_kinsn_modules_into_cache() {
    local cache_dir="$1"
    local cached_module_dir
    rebuild_arm64_kinsn_modules
    cached_module_dir="$(arm64_cached_kinsn_modules_dir "$cache_dir")"
    stage_module_binaries "$ARM64_KINSN_MODULE_BUILD_SRC" "$cached_module_dir"
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

build_arm64_kernel_artifacts_locked() {
    local kernel_release cached_dir cached_stage
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
    kernel_release="$(<"$ARM64_AWS_BUILD_DIR/include/config/kernel.release")"
    [[ -n "$kernel_release" ]] || die "ARM64 kernel release is empty"
    cached_dir="$ARM64_SETUP_ARTIFACT_ROOT/$kernel_release"
    if reuse_cached_setup_artifacts "$cached_dir" "$kernel_release" "vmlinuz-$kernel_release.efi"; then
        elf_has_btf "$cached_dir/vmlinux-$kernel_release" || die "cached ARM64 vmlinux is missing .BTF"
        efi_binary_is_valid "$cached_dir/vmlinuz-$kernel_release.efi" || die "cached ARM64 EFI kernel image is invalid"
        modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' || die "cached ARM64 modules archive is missing modules.dep"
        return 0
    fi
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        modules -j"$(nproc)" >/dev/null
    cached_stage="$cached_dir/modules-stage"
    rm -rf "$cached_dir"
    mkdir -p "$cached_dir" "$cached_stage"
    make -C "$ARM64_WORKTREE_DIR" O="$ARM64_AWS_BUILD_DIR" \
        ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE_PREFIX" \
        INSTALL_MOD_PATH="$cached_stage" modules_install >/dev/null
    rm -f "$cached_stage/lib/modules/$kernel_release/build" "$cached_stage/lib/modules/$kernel_release/source"
    require_local_path "$ARM64_AWS_BUILD_DIR/vmlinux" "ARM64 vmlinux"
    require_local_path "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "ARM64 EFI kernel image"
    cp "$ARM64_AWS_BUILD_DIR/vmlinux" "$cached_dir/vmlinux-$kernel_release"
    cp "$ARM64_AWS_BUILD_DIR/arch/arm64/boot/vmlinuz.efi" "$cached_dir/vmlinuz-$kernel_release.efi"
    tar -C "$cached_stage" -czf "$cached_dir/modules-$kernel_release.tar.gz" lib/modules
    rm -rf "$cached_stage"
    elf_has_btf "$cached_dir/vmlinux-$kernel_release" || die "generated ARM64 vmlinux is missing .BTF"
    efi_binary_is_valid "$cached_dir/vmlinuz-$kernel_release.efi" || die "generated ARM64 EFI kernel image is invalid"
    modules_tar_has_entry "$cached_dir/modules-$kernel_release.tar.gz" '/modules\.dep$' || die "generated ARM64 modules archive is missing modules.dep"
    link_cached_setup_artifacts "$cached_dir" "$kernel_release" "vmlinuz-$kernel_release.efi"
    BUILD_KERNEL_RELEASE="$kernel_release"
}

build_arm64_kernel_artifacts() {
    ensure_dirs
    with_arm64_kernel_lock build_arm64_kernel_artifacts_locked
}

ensure_x86_runner_ready() {
    make -C "$ROOT_DIR/runner" BUILD_DIR="$X86_RUNNER_BUILD_DIR" micro_exec >/dev/null
    file "$X86_RUNNER" | grep -F "x86-64" >/dev/null || die "x86 runner is not an x86_64 binary"
}

ensure_x86_daemon_ready() {
    make -C "$ROOT_DIR/runner" DAEMON_TARGET_DIR="$X86_DAEMON_TARGET_DIR" daemon-binary >/dev/null
    file "$X86_DAEMON" | grep -F "x86-64" >/dev/null || die "x86 daemon is not an x86_64 binary"
}

ensure_x86_kinsn_modules_ready_locked() {
    local expected_release cached_dir cached_module_dir config_fingerprint
    prepare_x86_aws_config_locked
    config_fingerprint="$(x86_setup_config_fingerprint)"
    expected_release="${STATE_KERNEL_RELEASE:-}"
    [[ -n "$expected_release" ]] || die "x86 kinsn module staging requires STATE_KERNEL_RELEASE"
    cached_dir="$X86_SETUP_ARTIFACT_ROOT/$expected_release"
    if ! x86_reuse_cached_setup_artifacts "$cached_dir" "$expected_release" "bzImage-$expected_release" "$config_fingerprint" >/dev/null \
        || ! x86_cached_kinsn_modules_ready "$cached_dir" "$expected_release"
    then
        rm -rf "$cached_dir"
        build_x86_kernel_artifacts_locked
    fi
    x86_cached_kinsn_modules_ready "$cached_dir" "$expected_release" \
        || die "x86 cached kinsn modules are missing or invalid for ${expected_release}"
    cached_module_dir="$(x86_cached_kinsn_modules_dir "$cached_dir")"
    stage_module_binaries "$cached_module_dir" "$X86_KINSN_MODULE_STAGE_DIR"
}

ensure_x86_kinsn_modules_ready() {
    with_x86_kernel_lock ensure_x86_kinsn_modules_ready_locked
    dir_has_entries "$X86_KINSN_MODULE_STAGE_DIR" || die "x86 kinsn module stage dir is empty: ${X86_KINSN_MODULE_STAGE_DIR}"
}

ensure_x86_selftest_outputs() {
    make -C "$ROOT_DIR/runner" \
        UNITTEST_BUILD_DIR="$X86_TEST_UNITTEST_BUILD_DIR" \
        NEGATIVE_BUILD_DIR="$X86_TEST_NEGATIVE_BUILD_DIR" \
        unittest-build negative-build >/dev/null
    file "$X86_TEST_UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "x86-64" >/dev/null || die "x86 unittest binary is not x86_64"
    file "$X86_TEST_NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "x86-64" >/dev/null || die "x86 negative binary is not x86_64"
}

ensure_x86_upstream_selftests_ready() {
    make -C "$ROOT_DIR/runner" UPSTREAM_SELFTEST_OUTPUT_DIR="$X86_UPSTREAM_SELFTEST_DIR" upstream-selftests-build >/dev/null
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_verifier" "x86 upstream test_verifier"
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_progs" "x86 upstream test_progs"
}

ensure_cross_arm64_runtime() {
    local require_llvmbpf="${1:-0}"
    local llvmbpf_setting="${ARM64_CROSSBUILD_ENABLE_LLVMBPF:-OFF}"
    local runtime_targets=()
    if [[ "$require_llvmbpf" == "1" ]]; then
        llvmbpf_setting=ON
    fi
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" && "${RUN_RUNNER_BINARY_MODE:-bundled}" == "bundled" ]]; then
        runtime_targets+=(runner)
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        runtime_targets+=(daemon)
    fi
    [[ "${#runtime_targets[@]}" -gt 0 ]] || return 0
    configure_arm64_sysroot_contract
    make -C "$ROOT_DIR" __cross-arm64 \
        ARM64_SOURCE_REPO_ROOT="$ARM64_SOURCE_REPO_ROOT" \
        ARM64_CROSSBUILD_OUTPUT_DIR="$ARM64_CROSSBUILD_OUTPUT_DIR" \
        ARM64_CROSSBUILD_BUILD_ROOT="$ARM64_CROSSBUILD_BUILD_ROOT" \
        ARM64_CROSSBUILD_CARGO_HOME="$ARM64_CROSSBUILD_CARGO_HOME" \
        ARM64_HOST_DAEMON_TARGET_DIR="$ARM64_HOST_DAEMON_TARGET_DIR" \
        ARM64_HOST_DAEMON_OUTPUT_DIR="$ARM64_HOST_DAEMON_OUTPUT_DIR" \
        ARM64_HOST_DAEMON_BINARY="$ARM64_HOST_DAEMON_BINARY" \
        ARM64_HOST_DAEMON_CARGO_HOME="$ARM64_HOST_DAEMON_CARGO_HOME" \
        ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
        ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
        ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
        ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
        ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
        ARM64_CROSSBUILD_RUNTIME_TARGETS="$(IFS=,; printf '%s' "${runtime_targets[*]}")" \
        ARM64_CROSSBUILD_ENABLE_LLVMBPF="$llvmbpf_setting" >/dev/null
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" && "${RUN_RUNNER_BINARY_MODE:-bundled}" == "bundled" ]]; then
        file "$ARM64_CROSS_RUNNER_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 runner is not an aarch64 binary"
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        file "$ARM64_CROSS_DAEMON_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 daemon is not an aarch64 binary"
    fi
    dir_has_entries "$ARM64_CROSS_LIB_DIR" || die "ARM64 runtime lib dir is empty: ${ARM64_CROSS_LIB_DIR}"
}

ensure_arm64_kinsn_modules_ready_locked() {
    local expected_release cached_dir cached_module_dir current_build_release
    expected_release="${STATE_KERNEL_RELEASE:-}"
    [[ -n "$expected_release" ]] || die "ARM64 kinsn module staging requires STATE_KERNEL_RELEASE"
    cached_dir="$ARM64_SETUP_ARTIFACT_ROOT/$expected_release"
    if ! reuse_cached_setup_artifacts "$cached_dir" "$expected_release" "vmlinuz-$expected_release.efi" >/dev/null; then
        rm -rf "$cached_dir"
        build_arm64_kernel_artifacts_locked
    fi
    if [[ -f "$ARM64_AWS_BASE_CONFIG" && ! arm64_build_config_matches_aws_base ]]; then
        build_arm64_kernel_artifacts_locked
    fi
    current_build_release="$(<"$ARM64_AWS_BUILD_DIR/include/config/kernel.release" 2>/dev/null || true)"
    if [[ "$current_build_release" != "$expected_release" ]]; then
        build_arm64_kernel_artifacts_locked
    fi
    if ! arm64_cached_kinsn_modules_ready "$cached_dir" "$expected_release"; then
        rm -rf "$(arm64_cached_kinsn_modules_dir "$cached_dir")"
        build_arm64_kinsn_modules_into_cache "$cached_dir"
    fi
    arm64_cached_kinsn_modules_ready "$cached_dir" "$expected_release" \
        || die "ARM64 cached kinsn modules are missing or invalid for ${expected_release}"
    cached_module_dir="$(arm64_cached_kinsn_modules_dir "$cached_dir")"
    stage_module_binaries "$cached_module_dir" "$ARM64_KINSN_MODULE_STAGE_DIR"
}

ensure_arm64_kinsn_modules_ready() {
    with_arm64_kernel_lock ensure_arm64_kinsn_modules_ready_locked
}

ensure_arm64_upstream_test_kmods_ready_locked() {
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

ensure_arm64_upstream_test_kmods_ready() {
    with_arm64_kernel_lock ensure_arm64_upstream_test_kmods_ready_locked
}

ensure_arm64_selftest_outputs() {
    [[ -f "$ARM64_AWS_BUILD_DIR/vmlinux" ]] || die "AWS ARM64 selftest build requires ${ARM64_AWS_BUILD_DIR}/vmlinux"
    configure_arm64_sysroot_contract
    make -C "$ROOT_DIR" __arm64-test-artifacts \
        VMLINUX_BTF="$ARM64_AWS_BUILD_DIR/vmlinux" \
        ARM64_TEST_MODE="${RUN_TEST_MODE:-test}" \
        ARM64_TEST_ARTIFACTS_ROOT="$ARM64_TEST_ARTIFACTS_ROOT" \
        ARM64_TEST_UNITTEST_BUILD_DIR="$ARM64_TEST_UNITTEST_BUILD_DIR" \
        ARM64_TEST_NEGATIVE_BUILD_DIR="$ARM64_TEST_NEGATIVE_BUILD_DIR" \
        ARM64_TEST_DAEMON_OUTPUT_DIR="$ARM64_TEST_ARTIFACTS_ROOT/daemon" \
        ARM64_HOST_DAEMON_TARGET_DIR="$ARM64_HOST_DAEMON_TARGET_DIR" \
        ARM64_HOST_DAEMON_OUTPUT_DIR="$ARM64_HOST_DAEMON_OUTPUT_DIR" \
        ARM64_HOST_DAEMON_BINARY="$ARM64_HOST_DAEMON_BINARY" \
        ARM64_HOST_DAEMON_CARGO_HOME="$ARM64_HOST_DAEMON_CARGO_HOME" \
        ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
        ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
        ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
        ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
        ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
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
    "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/fetch_corpus_repos.py" --repo-root "$LOCAL_REPO_ROOT" "${args[@]}" >/dev/null
}

ensure_x86_scx_artifacts_ready() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "scx"
    IFS=',' read -r -a _scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/build_scx_artifacts.py" \
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
    configure_arm64_sysroot_contract
    IFS=',' read -r -a _scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    make -C "$ROOT_DIR" __cross-arm64-scx \
        ARM64_SOURCE_REPO_ROOT="$LOCAL_REPO_ROOT" \
        ARM64_CROSSBUILD_OUTPUT_DIR="$ARM64_CROSSBUILD_OUTPUT_DIR" \
        ARM64_HOST_SCX_BUILD_ROOT="$ARM64_HOST_SCX_BUILD_ROOT" \
        ARM64_HOST_SCX_CARGO_HOME="$ARM64_HOST_SCX_CARGO_HOME" \
        ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
        ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
        ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
        ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
        ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
        ARM64_CROSSBUILD_SCX_PACKAGES="$RUN_SCX_PACKAGES_CSV" >/dev/null
    for package in "${_scx_packages[@]}"; do
        file "$ARM64_CROSSBUILD_OUTPUT_DIR/runner/repos/scx/target/release/$package" | grep -F "ARM aarch64" >/dev/null \
            || die "ARM64 scx binary is not aarch64: $package"
        require_local_path "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/scx/${package}_main.bpf.o" "ARM64 scx object ${package}_main.bpf.o"
    done
}

ensure_x86_native_repo_artifacts_ready() {
    local repo katran_input_root args=()
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "$RUN_BENCHMARK_REPOS_CSV"
    mkdir -p "$LOCAL_PROMOTE_ROOT/corpus/build"
    IFS=',' read -r -a _native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    for repo in "${_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    if [[ ",${RUN_NATIVE_REPOS_CSV:-}," == *",katran,"* ]]; then
        katran_input_root="$LOCAL_PROMOTE_ROOT/.inputs/katran"
        rm -rf "$katran_input_root"
        mkdir -p "$katran_input_root/bin" "$katran_input_root/lib"
        snapshot_git_subtree "$ROOT_DIR" "e2e/cases/katran/bin" "$katran_input_root/bin"
        snapshot_git_subtree "$ROOT_DIR" "e2e/cases/katran/lib" "$katran_input_root/lib"
        require_local_path "$katran_input_root/bin/katran_server_grpc" "sealed AWS x86 Katran server source bundle"
        require_nonempty_dir "$katran_input_root/lib" "sealed AWS x86 Katran lib dir"
        KATRAN_SERVER_BINARY="$katran_input_root/bin/katran_server_grpc" \
            KATRAN_SERVER_LIB_DIR="$katran_input_root/lib" \
            "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/build_corpus_native.py" \
                --jobs "$(nproc)" \
                --repo-root "$LOCAL_REPO_ROOT" \
                --build-root "$LOCAL_PROMOTE_ROOT/corpus/build" \
                "${args[@]}" >/dev/null
        return 0
    fi
    "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/build_corpus_native.py" \
        --jobs "$(nproc)" \
        --repo-root "$LOCAL_REPO_ROOT" \
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
    make -C "$ROOT_DIR" __cross-arm64-bench \
        ARM64_SOURCE_REPO_ROOT="$LOCAL_REPO_ROOT" \
        ARM64_CROSSBUILD_OUTPUT_DIR="$ARM64_CROSSBUILD_OUTPUT_DIR" \
        ARM64_CROSSBUILD_BUILD_ROOT="$ARM64_CROSSBUILD_BUILD_ROOT" \
        ARM64_CROSSBUILD_CARGO_HOME="$ARM64_CROSSBUILD_CARGO_HOME" \
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
    case "$RUN_SUITE_NAME" in
        micro)
            make -C "$ROOT_DIR/runner" MICRO_PROGRAM_OUTPUT_DIR="$MICRO_PROGRAMS_GENERATED_DIR" micro-programs >/dev/null
            require_nonempty_dir "$MICRO_PROGRAMS_GENERATED_DIR" "micro generated programs dir"
            case "$RUN_TARGET_NAME" in
                aws-arm64)
                    if [[ "${RUN_RUNNER_BINARY_MODE:-bundled}" == "bundled" ]]; then
                        ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
                    fi
                    ;;
                aws-x86)
                    ensure_x86_runner_ready
                    ;;
                *)
                    die "unsupported AWS micro target: ${RUN_TARGET_NAME}"
                    ;;
            esac
            ;;
        corpus|e2e)
            case "$RUN_TARGET_NAME" in
                aws-arm64)
                    ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
                    ensure_arm64_scx_artifacts_ready
                    ensure_arm64_kinsn_modules_ready
                    ensure_arm64_native_repo_artifacts_ready
                    ;;
                aws-x86)
                    ensure_x86_daemon_ready
                    ensure_x86_scx_artifacts_ready
                    ensure_x86_kinsn_modules_ready
                    ensure_x86_native_repo_artifacts_ready
                    ;;
                *)
                    die "unsupported AWS benchmark target: ${RUN_TARGET_NAME}"
                    ;;
            esac
            ;;
        *)
            die "unsupported benchmark suite for local artifact preparation: ${RUN_SUITE_NAME}"
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

prepare_local_bundle() {
    local stage_root bundle_tar bundle_inputs_path
    stage_root="$RUN_PREP_ROOT/workspace"
    bundle_tar="$RUN_PREP_ROOT/bundle.tar.gz"
    bundle_inputs_path="$RUN_PREP_ROOT/bundle-inputs.env"
    RUN_INPUT_STAGE_ROOT="$stage_root"
    RUN_BUNDLE_TAR="$bundle_tar"
    rm -rf "$stage_root"
    mkdir -p "$(dirname "$bundle_tar")"
    cat >"$bundle_inputs_path" <<EOF
RUN_LOCAL_PROMOTE_ROOT=$(printf '%q' "$LOCAL_PROMOTE_ROOT")
RUN_LOCAL_REPO_ROOT=$(printf '%q' "$LOCAL_REPO_ROOT")
MICRO_PROGRAMS_GENERATED_DIR=$(printf '%q' "$MICRO_PROGRAMS_GENERATED_DIR")
RUN_KINSN_MODULE_DIR=$(printf '%q' "$([[ "$RUN_TARGET_NAME" == "aws-arm64" ]] && printf '%s' "$ARM64_KINSN_MODULE_STAGE_DIR" || printf '%s' "$X86_KINSN_MODULE_STAGE_DIR")")
X86_RUNNER=$(printf '%q' "$X86_RUNNER")
X86_DAEMON=$(printf '%q' "$X86_DAEMON")
X86_TEST_UNITTEST_BUILD_DIR=$(printf '%q' "$X86_TEST_UNITTEST_BUILD_DIR")
X86_TEST_NEGATIVE_BUILD_DIR=$(printf '%q' "$X86_TEST_NEGATIVE_BUILD_DIR")
X86_UPSTREAM_SELFTEST_DIR=$(printf '%q' "$X86_UPSTREAM_SELFTEST_DIR")
ARM64_CROSSBUILD_OUTPUT_DIR=$(printf '%q' "$ARM64_CROSSBUILD_OUTPUT_DIR")
ARM64_CROSS_RUNNER=$(printf '%q' "$ARM64_CROSS_RUNNER")
ARM64_CROSS_RUNNER_REAL=$(printf '%q' "$ARM64_CROSS_RUNNER_REAL")
ARM64_CROSS_DAEMON=$(printf '%q' "$ARM64_CROSS_DAEMON")
ARM64_CROSS_DAEMON_REAL=$(printf '%q' "$ARM64_CROSS_DAEMON_REAL")
ARM64_CROSS_LIB_DIR=$(printf '%q' "$ARM64_CROSS_LIB_DIR")
ARM64_KATRAN_SERVER_BINARY=$(printf '%q' "$ARM64_KATRAN_SERVER_BINARY")
ARM64_KATRAN_SERVER_LIB_DIR=$(printf '%q' "$ARM64_KATRAN_SERVER_LIB_DIR")
ARM64_TEST_ARTIFACTS_ROOT=$(printf '%q' "$ARM64_TEST_ARTIFACTS_ROOT")
ARM64_TEST_UNITTEST_BUILD_DIR=$(printf '%q' "$ARM64_TEST_UNITTEST_BUILD_DIR")
ARM64_TEST_NEGATIVE_BUILD_DIR=$(printf '%q' "$ARM64_TEST_NEGATIVE_BUILD_DIR")
ARM64_UPSTREAM_SELFTEST_DIR=$(printf '%q' "$ARM64_UPSTREAM_SELFTEST_DIR")
ARM64_UPSTREAM_TEST_KMODS_DIR=$(printf '%q' "$ARM64_UPSTREAM_TEST_KMODS_DIR")
EOF
    "$ROOT_DIR/runner/scripts/build_remote_bundle.sh" "$MANIFEST_PATH" "$bundle_inputs_path" "$RUN_INPUT_STAGE_ROOT" "$RUN_BUNDLE_TAR"
}

prepare_local_inputs() {
    prepare_local_suite_artifacts
    prepare_local_bundle
}

setup_remote_runtime_prereqs() {
    local ip="$1"
    local remote_prereq_dir remote_stamp_path remote_tool_root
    remote_prereq_dir="$(remote_prereq_dir)"
    remote_stamp_path="$(remote_prereq_stamp_path)"
    remote_tool_root="$(remote_prereq_workload_tool_root)"
    local remote_helper="$remote_prereq_dir/aws_remote_prereqs.sh"
    local remote_prereq_contract="$remote_prereq_dir/prereq_contract.sh"
    local remote_manifest="$remote_prereq_dir/run-contract.env"
    ssh_bash "$ip" "$remote_prereq_dir" <<'EOF'
set -euo pipefail
mkdir -p "$1"
EOF
    scp_to "$ip" "$ROOT_DIR/runner/scripts/aws_remote_prereqs.sh" "$remote_helper"
    scp_to "$ip" "$ROOT_DIR/runner/scripts/prereq_contract.sh" "$remote_prereq_contract"
    scp_to "$ip" "$MANIFEST_PATH" "$remote_manifest"
    ssh_bash "$ip" "$remote_helper" "$remote_manifest" "$remote_stamp_path" "$remote_tool_root" <<'EOF'
set -euo pipefail
helper="$1"
manifest="$2"
stamp_path="$3"
tool_root="$4"
chmod +x "$helper"
sudo env PATH="$PATH" AWS_REMOTE_PREREQS_STAMP="$stamp_path" RUN_REMOTE_WORKLOAD_TOOL_ROOT="$tool_root" bash "$helper" "$manifest"
test -f "$stamp_path"
EOF
}

verify_remote_runtime_prereqs() {
    local ip="$1"
    ssh_bash "$ip" "$(remote_prereq_stamp_path)" <<'EOF'
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
    save_state "$instance_id" "$ip" "$region" "$kernel_release"
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
    save_state "$instance_id" "$ip" "$region" "$kernel_release"
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
    local stamp local_result_dir local_archive local_log remote_run_dir remote_archive remote_log remote_tool_bin remote_tool_root
    wait_for_ssh "$ip"
    verify_remote_runtime_prereqs "$ip" || die "remote prerequisites stamp is missing on ${ip}; run setup first"
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle path is unset; local bundle preparation did not run"
    [[ -f "${RUN_BUNDLE_TAR}" ]] || die "prepared remote bundle is missing: ${RUN_BUNDLE_TAR}"

    stamp="${RUN_SUITE_NAME}_${RUN_TOKEN}_$(date -u +%Y%m%d_%H%M%S)"
    local_result_dir="$RESULTS_DIR/$stamp"
    local_archive="$local_result_dir/results.tar.gz"
    local_log="$local_result_dir/remote.log"
    remote_run_dir="$RUN_REMOTE_STAGE_DIR/runs/$stamp"
    remote_tool_root="$(remote_prereq_workload_tool_root)"
    remote_tool_bin="$(remote_prereq_workload_tool_bin)"
    remote_archive="$remote_run_dir/results.tar.gz"
    remote_log="$remote_run_dir/remote.log"
    mkdir -p "$local_result_dir"

    ssh_bash "$ip" "$remote_run_dir" <<'EOF'
set -euo pipefail
run_dir="$1"
sudo rm -rf "$run_dir"
mkdir -p "$run_dir"
EOF
    scp_to "$ip" "$RUN_BUNDLE_TAR" "$remote_run_dir/bundle.tar.gz"
    local remote_status=0
    set +e
    ssh_bash "$ip" "$remote_run_dir" "$remote_archive" "$remote_log" "$remote_tool_root" "$remote_tool_bin" <<'EOF'
set -euo pipefail
run_dir="$1"
archive_path="$2"
log_path="$3"
tool_root="$4"
tool_bin="$5"
workspace="$run_dir/workspace"
bundle_path="$run_dir/bundle.tar.gz"
sudo rm -rf "$workspace"
mkdir -p "$workspace"
tar -xzf "$bundle_path" -C "$workspace"
rm -f "$bundle_path"
if [[ -d "$tool_root" ]]; then
    mkdir -p "$workspace/.cache"
    rm -rf "$workspace/.cache/workload-tools"
    cp -a "$tool_root" "$workspace/.cache/workload-tools"
fi
if [[ -d "$workspace/.cache/workload-tools/bin" ]]; then
    export PATH="$workspace/.cache/workload-tools/bin:$PATH"
elif [[ -d "$tool_bin" ]]; then
    export PATH="$tool_bin:$PATH"
fi
test -f "$workspace/run-contract.env"
# shellcheck disable=SC1090
source "$workspace/run-contract.env"
[[ -n "${RUN_SUITE_ENTRYPOINT:-}" ]] || exit 1
chmod +x "$workspace/$RUN_SUITE_ENTRYPOINT"
    sudo -E bash "$workspace/$RUN_SUITE_ENTRYPOINT" \
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
    ssh_bash "$ip" "$remote_run_dir" <<'EOF' >/dev/null 2>&1 || true
set -euo pipefail
sudo rm -rf "$1"
EOF
    log "Fetched ${RUN_TARGET_NAME}/${RUN_SUITE_NAME} results to ${local_result_dir}"
}

dedicated_instance_cleanup() {
    cleanup_local_run_prep_root
    if (( DEDICATED_RUN_ACTIVE == 0 )); then
        return 0
    fi
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        terminate_instance "${STATE_INSTANCE_ID}" || true
    fi
    rm -rf "$RUN_STATE_DIR"
}

run_shared_remote_execution() {
    with_state_lock ensure_instance_for_suite
    load_state
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || die "shared AWS run is missing STATE_INSTANCE_IP before remote execution"
    run_remote_suite "$STATE_INSTANCE_IP"
}

run_shared_suite_action() {
    trap cleanup_local_run_prep_root EXIT
    with_state_lock ensure_instance_for_suite
    prepare_local_inputs
    with_remote_execution_lock run_shared_remote_execution
    trap - EXIT
    cleanup_local_run_prep_root
}

run_suite_action() {
    local instance_ip=""
    if aws_instance_mode_is_shared; then
        run_shared_suite_action
        return 0
    fi

    DEDICATED_RUN_ACTIVE=1
    trap dedicated_instance_cleanup EXIT
    with_state_lock ensure_instance_for_suite
    load_state
    instance_ip="${STATE_INSTANCE_IP:-}"
    [[ -n "$instance_ip" ]] || die "dedicated AWS run is missing STATE_INSTANCE_IP before remote execution"
    prepare_local_inputs
    run_remote_suite "$instance_ip"
    cleanup_local_run_prep_root
    DEDICATED_RUN_ACTIVE=0
    trap - EXIT
    terminate_instance "${STATE_INSTANCE_ID:-}"
    rm -rf "$RUN_STATE_DIR"
}

ensure_instance_for_suite() {
    local current_kernel root_volume_gb current_instance_id="" current_instance_state="" current_instance_ip="" current_instance_type=""
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        read -r current_instance_id current_instance_state current_instance_ip <<<"$(describe_instance "${STATE_REGION:-$(resolve_region)}" "$STATE_INSTANCE_ID")"
        current_instance_type="$(describe_instance_type "${STATE_REGION:-$(resolve_region)}" "$STATE_INSTANCE_ID")"
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
        if [[ -n "${STATE_INSTANCE_ID:-}" && "$current_instance_type" != "$RUN_INSTANCE_TYPE" ]]; then
            terminate_instance "${STATE_INSTANCE_ID}"
            load_state
            STATE_INSTANCE_ID=""
            STATE_INSTANCE_IP=""
        fi
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
    local region explicit_instance_id="${1:-}" instance_id state
    local -a target_instance_ids=()
    region="$(resolve_region)"
    if [[ -z "$explicit_instance_id" || "$explicit_instance_id" == "None" ]]; then
        read -r -a target_instance_ids <<<"$(lookup_target_instance_ids "$region")"
        if [[ "${#target_instance_ids[@]}" -gt 0 ]]; then
            aws_cmd "$region" ec2 terminate-instances --instance-ids "${target_instance_ids[@]}" >/dev/null
            aws_cmd "$region" ec2 wait instance-terminated --instance-ids "${target_instance_ids[@]}"
        fi
        rm -rf "$SHARED_STATE_DIR" "$TARGET_CACHE_DIR/run-state"
        return 0
    fi
    instance_id="$explicit_instance_id"
    read -r _ state _ <<<"$(describe_instance "$region" "$instance_id")"
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
            run_suite_action
            ;;
        terminate)
            terminate_instance
            ;;
        *)
            die "unsupported aws executor action: ${ACTION}"
            ;;
    esac
}

main "$@"
