#!/usr/bin/env bash
set -euo pipefail

# Internal AWS local-prep library.
# This file must be sourced only after aws_common_lib.sh so that shared
# lifecycle/state/setup helpers and manifest-derived paths are already defined.

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_kernel_artifacts_lib.sh"

LOCAL_PROMOTE_ROOT="${LOCAL_PROMOTE_ROOT:-$RUN_PREP_ROOT/bundle-inputs}"
LOCAL_REPO_ROOT="${LOCAL_REPO_ROOT:-$LOCAL_PROMOTE_ROOT/runner/repos}"
X86_TEST_ARTIFACTS_ROOT="${X86_TEST_ARTIFACTS_ROOT:-$LOCAL_PROMOTE_ROOT/test-artifacts}"
X86_PORTABLE_LIBBPF_ROOT="${X86_PORTABLE_LIBBPF_ROOT:-$LOCAL_PROMOTE_ROOT/portable-libbpf}"
X86_RUNNER_BUILD_DIR="${X86_RUNNER_BUILD_DIR:-$LOCAL_PROMOTE_ROOT/runner/build}"
X86_RUNNER="${X86_RUNNER:-$X86_RUNNER_BUILD_DIR/micro_exec}"
X86_DAEMON_TARGET_DIR="${X86_DAEMON_TARGET_DIR:-$LOCAL_PROMOTE_ROOT/daemon/target}"
X86_DAEMON="${X86_DAEMON:-$X86_DAEMON_TARGET_DIR/release/bpfrejit-daemon}"
X86_TEST_UNITTEST_BUILD_DIR="${X86_TEST_UNITTEST_BUILD_DIR:-$X86_TEST_ARTIFACTS_ROOT/unittest/build}"
X86_TEST_NEGATIVE_BUILD_DIR="${X86_TEST_NEGATIVE_BUILD_DIR:-$X86_TEST_ARTIFACTS_ROOT/negative/build}"
X86_UPSTREAM_SELFTEST_DIR="${X86_UPSTREAM_SELFTEST_DIR:-$X86_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests}"
if [[ "${X86_KINSN_MODULE_STAGE_DIR:-}" == "$RUN_PREP_ROOT/test-artifacts/kinsn-modules/x86" ]]; then
    X86_KINSN_MODULE_STAGE_DIR="$X86_TEST_ARTIFACTS_ROOT/kinsn-modules/x86"
fi
X86_KINSN_MODULE_STAGE_DIR="${X86_KINSN_MODULE_STAGE_DIR:-$X86_TEST_ARTIFACTS_ROOT/kinsn-modules/x86}"
MICRO_PROGRAMS_GENERATED_DIR="${MICRO_PROGRAMS_GENERATED_DIR:-$LOCAL_PROMOTE_ROOT/micro/programs}"
ARM64_CROSSBUILD_ROOT="${ARM64_CROSSBUILD_ROOT:-$RUN_PREP_ROOT/arm64-cross}"
ARM64_CROSSBUILD_OUTPUT_DIR="${ARM64_CROSSBUILD_OUTPUT_DIR:-$LOCAL_PROMOTE_ROOT}"
ARM64_CROSSBUILD_BUILD_ROOT="${ARM64_CROSSBUILD_BUILD_ROOT:-$ARM64_CROSSBUILD_ROOT/build}"
ARM64_CROSSBUILD_CARGO_HOME="${ARM64_CROSSBUILD_CARGO_HOME:-$ARM64_CROSSBUILD_ROOT/cargo-home}"
ARM64_TEST_ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-$LOCAL_PROMOTE_ROOT/test-artifacts}"
ARM64_KINSN_MODULE_STAGE_DIR="${ARM64_KINSN_MODULE_STAGE_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/kinsn-modules/arm64}"
ARM64_TEST_UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/unittest/build-arm64}"
ARM64_TEST_NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/negative/build-arm64}"
ARM64_UPSTREAM_SELFTEST_DIR="${ARM64_UPSTREAM_SELFTEST_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests}"
if [[ "${ARM64_UPSTREAM_TEST_KMODS_DIR:-}" == "$TARGET_CACHE_DIR/upstream-selftests-kmods-arm64" ]]; then
    ARM64_UPSTREAM_TEST_KMODS_DIR="$ARM64_TEST_ARTIFACTS_ROOT/upstream-selftests-kmods"
fi
ARM64_UPSTREAM_TEST_KMODS_DIR="${ARM64_UPSTREAM_TEST_KMODS_DIR:-$ARM64_TEST_ARTIFACTS_ROOT/upstream-selftests-kmods}"
ARM64_HOST_RUNNER_ROOT="${ARM64_HOST_RUNNER_ROOT:-$RUN_PREP_ROOT/arm64-runner-host-cross}"
ARM64_HOST_RUNNER_BUILD_DIR="${ARM64_HOST_RUNNER_BUILD_DIR:-$ARM64_HOST_RUNNER_ROOT/build}"
ARM64_HOST_RUNNER_OUTPUT_DIR="${ARM64_HOST_RUNNER_OUTPUT_DIR:-$ARM64_HOST_RUNNER_ROOT/output}"
ARM64_HOST_RUNNER_BINARY="${ARM64_HOST_RUNNER_BINARY:-$ARM64_HOST_RUNNER_OUTPUT_DIR/micro_exec}"
ARM64_HOST_DAEMON_ROOT="${ARM64_HOST_DAEMON_ROOT:-$RUN_PREP_ROOT/arm64-daemon-host-cross}"
ARM64_HOST_DAEMON_TARGET_DIR="${ARM64_HOST_DAEMON_TARGET_DIR:-$ARM64_HOST_DAEMON_ROOT/target}"
ARM64_HOST_DAEMON_OUTPUT_DIR="${ARM64_HOST_DAEMON_OUTPUT_DIR:-$ARM64_HOST_DAEMON_ROOT/output}"
ARM64_HOST_DAEMON_BINARY="${ARM64_HOST_DAEMON_BINARY:-$ARM64_HOST_DAEMON_OUTPUT_DIR/bpfrejit-daemon}"
ARM64_HOST_DAEMON_CARGO_HOME="${ARM64_HOST_DAEMON_CARGO_HOME:-$ARM64_HOST_DAEMON_ROOT/cargo-home}"
ARM64_HOST_SCX_ROOT="${ARM64_HOST_SCX_ROOT:-$RUN_PREP_ROOT/arm64-scx-host-cross}"
ARM64_HOST_SCX_BUILD_ROOT="${ARM64_HOST_SCX_BUILD_ROOT:-$ARM64_HOST_SCX_ROOT/build}"
ARM64_HOST_SCX_CARGO_HOME="${ARM64_HOST_SCX_CARGO_HOME:-$ARM64_HOST_SCX_ROOT/cargo-home}"
ARM64_SOURCE_REPO_ROOT="${ARM64_SOURCE_REPO_ROOT:-$LOCAL_REPO_ROOT}"
ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/runner/build/micro_exec.real}"
ARM64_CROSS_DAEMON="${ARM64_CROSS_DAEMON:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon}"
ARM64_CROSS_DAEMON_REAL="${ARM64_CROSS_DAEMON_REAL:-$ARM64_CROSSBUILD_OUTPUT_DIR/daemon/build/bpfrejit-daemon.real}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/lib}"
ARM64_KATRAN_SERVER_BINARY="${ARM64_KATRAN_SERVER_BINARY:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/bin/katran_server_grpc}"
ARM64_KATRAN_SERVER_LIB_DIR="${ARM64_KATRAN_SERVER_LIB_DIR:-$ARM64_CROSSBUILD_OUTPUT_DIR/katran/lib}"

configure_arm64_sysroot_contract() {
    [[ "${RUN_EXECUTOR:-}" == "aws-ssh" && "${RUN_TARGET_ARCH:-}" == "arm64" ]] || return 0
    if [[ -n "${ARM64_SYSROOT_REMOTE_HOST:-}" ]]; then
        [[ -n "${ARM64_SYSROOT_REMOTE_USER:-}" ]] || die "ARM64 sysroot source requires ARM64_SYSROOT_REMOTE_USER"
        [[ -n "${ARM64_SYSROOT_SSH_KEY_PATH:-}" ]] || die "ARM64 sysroot source requires ARM64_SYSROOT_SSH_KEY_PATH"
        return 0
    fi
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || return 0
    [[ -n "${RUN_REMOTE_USER:-}" ]] || die "ARM64 sysroot source requires RUN_REMOTE_USER"
    [[ -n "${RUN_AWS_KEY_PATH:-}" ]] || die "ARM64 sysroot source requires RUN_AWS_KEY_PATH"
    ARM64_SYSROOT_REMOTE_HOST="$STATE_INSTANCE_IP"
    ARM64_SYSROOT_REMOTE_USER="$RUN_REMOTE_USER"
    ARM64_SYSROOT_SSH_KEY_PATH="$RUN_AWS_KEY_PATH"
}

ensure_x86_runner_ready() {
    local_prep_build_runner_binary "$ROOT_DIR/runner" "$X86_RUNNER_BUILD_DIR"
    file "$X86_RUNNER" | grep -F "x86-64" >/dev/null || die "x86 runner is not an x86_64 binary"
}

ensure_x86_daemon_ready() {
    local_prep_build_daemon_binary "$ROOT_DIR/runner" "$X86_DAEMON_TARGET_DIR"
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
    local_prep_build_x86_repo_tests \
        "$ROOT_DIR/runner" \
        "$X86_TEST_UNITTEST_BUILD_DIR" \
        "$X86_TEST_NEGATIVE_BUILD_DIR"
    file "$X86_TEST_UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "x86-64" >/dev/null || die "x86 unittest binary is not x86_64"
    file "$X86_TEST_NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "x86-64" >/dev/null || die "x86 negative binary is not x86_64"
}

ensure_x86_upstream_selftests_ready() {
    local_prep_build_x86_upstream_selftests \
        "$ROOT_DIR/runner" \
        "$X86_UPSTREAM_SELFTEST_DIR" \
        "$ROOT_DIR/vendor/linux-framework/vmlinux" \
        "$HOST_PYTHON_BIN" \
        "${RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_verifier" "x86 upstream test_verifier"
    require_local_path "$X86_UPSTREAM_SELFTEST_DIR/test_progs" "x86 upstream test_progs"
}

ensure_cross_arm64_runtime() {
    local require_llvmbpf="${1:-0}"
    local llvmbpf_setting="${ARM64_CROSSBUILD_ENABLE_LLVMBPF:-OFF}"
    local runtime_targets=()
    local runtime_targets_csv=""
    local use_host_runner_cross="0"
    if [[ "$require_llvmbpf" == "1" ]]; then
        llvmbpf_setting=ON
    fi
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
        runtime_targets+=(runner)
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        runtime_targets+=(daemon)
    fi
    [[ "${#runtime_targets[@]}" -gt 0 ]] || return 0
    runtime_targets_csv="$(IFS=,; printf '%s' "${runtime_targets[*]}")"
    if [[ "$llvmbpf_setting" != "ON" ]]; then
        case ",${runtime_targets_csv}," in
            *,runner,*) use_host_runner_cross="1" ;;
        esac
    fi
    configure_arm64_sysroot_contract
    if [[ "${#runtime_targets[@]}" -eq 1 && "${runtime_targets[0]}" == "daemon" ]]; then
        make -C "$ROOT_DIR/runner" __arm64-daemon-host-cross \
            ARM64_HOST_DAEMON_TARGET_DIR="$ARM64_HOST_DAEMON_TARGET_DIR" \
            ARM64_HOST_DAEMON_OUTPUT_DIR="$ARM64_HOST_DAEMON_OUTPUT_DIR" \
            ARM64_HOST_DAEMON_BINARY="$ARM64_HOST_DAEMON_BINARY" \
            ARM64_HOST_DAEMON_CARGO_HOME="$ARM64_HOST_DAEMON_CARGO_HOME" \
            ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
            ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
            ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
            ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
            ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" >/dev/null
        bash "$ROOT_DIR/runner/scripts/build-arm64-portable-binary-host.sh" \
            "$ARM64_HOST_DAEMON_BINARY" \
            "$ARM64_CROSS_DAEMON_REAL" \
            "$ARM64_CROSS_DAEMON" \
            "$ARM64_CROSS_LIB_DIR" >/dev/null
        file "$ARM64_CROSS_DAEMON_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 daemon is not an aarch64 binary"
        [[ -d "$ARM64_CROSS_LIB_DIR" ]] || die "ARM64 runtime lib dir is missing: ${ARM64_CROSS_LIB_DIR}"
        return 0
    fi
    if [[ "$use_host_runner_cross" == "1" ]]; then
        make -C "$ROOT_DIR/runner" __arm64-runner-host-cross \
            ARM64_HOST_RUNNER_BUILD_DIR="$ARM64_HOST_RUNNER_BUILD_DIR" \
            ARM64_HOST_RUNNER_OUTPUT_DIR="$ARM64_HOST_RUNNER_OUTPUT_DIR" \
            ARM64_HOST_RUNNER_BINARY="$ARM64_HOST_RUNNER_BINARY" \
            ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
            ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
            ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
            ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
            ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
            MICRO_EXEC_ENABLE_LLVMBPF=OFF >/dev/null
        bash "$ROOT_DIR/runner/scripts/build-arm64-portable-binary-host.sh" \
            "$ARM64_HOST_RUNNER_BINARY" \
            "$ARM64_CROSS_RUNNER_REAL" \
            "$ARM64_CROSS_RUNNER" \
            "$ARM64_CROSS_LIB_DIR" >/dev/null
        file "$ARM64_CROSS_RUNNER_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 runner is not an aarch64 binary"
        case ",${runtime_targets_csv}," in
            *,daemon,*)
            make -C "$ROOT_DIR/runner" __arm64-daemon-host-cross \
                ARM64_HOST_DAEMON_TARGET_DIR="$ARM64_HOST_DAEMON_TARGET_DIR" \
                ARM64_HOST_DAEMON_OUTPUT_DIR="$ARM64_HOST_DAEMON_OUTPUT_DIR" \
                ARM64_HOST_DAEMON_BINARY="$ARM64_HOST_DAEMON_BINARY" \
                ARM64_HOST_DAEMON_CARGO_HOME="$ARM64_HOST_DAEMON_CARGO_HOME" \
                ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
                ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
                ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
                ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
                ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" >/dev/null
            bash "$ROOT_DIR/runner/scripts/build-arm64-portable-binary-host.sh" \
                "$ARM64_HOST_DAEMON_BINARY" \
                "$ARM64_CROSS_DAEMON_REAL" \
                "$ARM64_CROSS_DAEMON" \
                "$ARM64_CROSS_LIB_DIR" >/dev/null
            file "$ARM64_CROSS_DAEMON_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 daemon is not an aarch64 binary"
                ;;
        esac
        [[ -d "$ARM64_CROSS_LIB_DIR" ]] || die "ARM64 runtime lib dir is missing: ${ARM64_CROSS_LIB_DIR}"
        return 0
    fi
    make -C "$ROOT_DIR/runner" __cross-arm64 \
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
        ARM64_CROSSBUILD_RUNTIME_TARGETS="$runtime_targets_csv" \
        ARM64_CROSSBUILD_ENABLE_LLVMBPF="$llvmbpf_setting" >/dev/null
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
        file "$ARM64_CROSS_RUNNER_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 runner is not an aarch64 binary"
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        file "$ARM64_CROSS_DAEMON_REAL" | grep -F "ARM aarch64" >/dev/null || die "ARM64 daemon is not an aarch64 binary"
    fi
    [[ -d "$ARM64_CROSS_LIB_DIR" ]] || die "ARM64 runtime lib dir is missing: ${ARM64_CROSS_LIB_DIR}"
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
    make -C "$ROOT_DIR/runner" __arm64-test-artifacts \
        PYTHON="$HOST_PYTHON_BIN" \
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
        ARM64_HOST_PYTHON_BIN="$HOST_PYTHON_BIN" \
        ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
        ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
        ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
        ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
        ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
        ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX="${RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}" \
        ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR="$ARM64_UPSTREAM_SELFTEST_DIR" >/dev/null
    file "$ARM64_TEST_UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "ARM aarch64" >/dev/null || die "ARM64 unittest binary is not aarch64"
    file "$ARM64_TEST_NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "ARM aarch64" >/dev/null || die "ARM64 negative binary is not aarch64"
    file "$ARM64_UPSTREAM_SELFTEST_DIR/test_verifier" | grep -F "ARM aarch64" >/dev/null || die "ARM64 upstream test_verifier is not aarch64"
    file "$ARM64_UPSTREAM_SELFTEST_DIR/test_progs" | grep -F "ARM aarch64" >/dev/null || die "ARM64 upstream test_progs is not aarch64"
}

ensure_selected_repos_fetched() {
    local repo_csv="$1"
    local_prep_fetch_selected_repos "$LOCAL_REPO_ROOT" "$repo_csv" "$HOST_PYTHON_BIN" "$ROOT_DIR"
}

ensure_x86_scx_artifacts_ready() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "scx"
    local_prep_build_scx_artifacts \
        "$LOCAL_REPO_ROOT" \
        "$LOCAL_PROMOTE_ROOT" \
        "$RUN_SCX_PACKAGES_CSV" \
        "$HOST_PYTHON_BIN" \
        "$ROOT_DIR"
    IFS=',' read -r -a _aws_x86_scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_aws_x86_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
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
    make -C "$ROOT_DIR/runner" __cross-arm64-scx \
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
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "${RUN_FETCH_REPOS_CSV:-}"
    mkdir -p "$LOCAL_PROMOTE_ROOT/corpus/build"
    local_prep_build_native_repo_artifacts \
        "$LOCAL_REPO_ROOT" \
        "$LOCAL_PROMOTE_ROOT" \
        "$RUN_NATIVE_REPOS_CSV" \
        "$HOST_PYTHON_BIN" \
        "$ROOT_DIR"
}

ensure_x86_portable_libbpf_ready() {
    bash "$ROOT_DIR/runner/scripts/build-x86-portable-libbpf.sh" "$X86_PORTABLE_LIBBPF_ROOT" >/dev/null
    require_nonempty_dir "$X86_PORTABLE_LIBBPF_ROOT/lib" "portable x86 libbpf dir"
    require_local_path "$X86_PORTABLE_LIBBPF_ROOT/lib/libbpf.so.1" "portable x86 libbpf soname"
}

arm64_tool_should_be_bundled() {
    case "$1" in
        wrk|sysbench|hackbench) return 0 ;;
    esac
    return 1
}

ensure_x86_workload_tools_ready() {
    local local_tool_root="$LOCAL_PROMOTE_ROOT/workload-tools"
    local_prep_stage_x86_workload_tools \
        "${RUN_WORKLOAD_TOOLS_CSV:-}" \
        "$local_tool_root" \
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV \
        RUN_LOCAL_WORKLOAD_TOOL_ROOT
}

ensure_arm64_workload_tools_ready() {
    local tool bundled_csv="" local_tool_root
    [[ -n "${RUN_WORKLOAD_TOOLS_CSV:-}" ]] || {
        RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
        return 0
    }
    IFS=',' read -r -a _arm64_workload_tools <<<"$RUN_WORKLOAD_TOOLS_CSV"
    for tool in "${_arm64_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        arm64_tool_should_be_bundled "$tool" || continue
        bundled_csv="$(csv_append_unique "$bundled_csv" "$tool")"
    done
    [[ -n "$bundled_csv" ]] || {
        RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
        return 0
    }
    make -C "$ROOT_DIR/runner" __arm64-workload-tools-host-cross \
        ARM64_WORKLOAD_TOOLS_SOURCE_ROOT="$ARM64_HOST_CACHE_ROOT" \
        ARM64_WORKLOAD_TOOLS_BUILD_ROOT="$RUN_PREP_ROOT/arm64-workload-tools-host" \
        ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT="$ARM64_CROSSBUILD_OUTPUT_DIR" \
        ARM64_WORKLOAD_TOOLS_LIST="$bundled_csv" \
        ARM64_SYSROOT_ROOT="$ARM64_SYSROOT_ROOT" \
        ARM64_SYSROOT_LOCK_FILE="$ARM64_SYSROOT_LOCK_FILE" \
        ARM64_SYSROOT_REMOTE_HOST="$ARM64_SYSROOT_REMOTE_HOST" \
        ARM64_SYSROOT_REMOTE_USER="$ARM64_SYSROOT_REMOTE_USER" \
        ARM64_SYSROOT_SSH_KEY_PATH="$ARM64_SYSROOT_SSH_KEY_PATH" \
        CROSS_COMPILE_ARM64="$CROSS_COMPILE_PREFIX" >/dev/null
    local_tool_root="$ARM64_CROSSBUILD_OUTPUT_DIR/workload-tools"
    require_nonempty_dir "$local_tool_root/bin" "ARM64 bundled workload tool bin dir"
    for tool in "${_arm64_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        arm64_tool_should_be_bundled "$tool" || continue
        require_local_path "$local_tool_root/bin/$tool" "ARM64 bundled workload tool wrapper"
        require_local_path "$local_tool_root/bin/$tool.real" "ARM64 bundled workload tool binary"
        file "$local_tool_root/bin/$tool.real" | grep -F "ARM aarch64" >/dev/null \
            || die "ARM64 bundled workload tool is not an aarch64 binary: ${tool}"
    done
    RUN_LOCAL_WORKLOAD_TOOL_ROOT="$local_tool_root"
    RUN_BUNDLED_WORKLOAD_TOOLS_CSV="$bundled_csv"
}

arm64_local_katran_bundle_available() {
    [[ -x "$ARM64_KATRAN_SERVER_BINARY" ]] || return 1
    file "$ARM64_KATRAN_SERVER_BINARY" | grep -F "ARM aarch64" >/dev/null || return 1
    dir_has_entries "$ARM64_KATRAN_SERVER_LIB_DIR"
}

ensure_arm64_native_repo_artifacts_ready() {
    local repo
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    ensure_selected_repos_fetched "${RUN_FETCH_REPOS_CSV:-}"
    IFS=',' read -r -a _native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    make -C "$ROOT_DIR/runner" __cross-arm64-bench \
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

prepare_aws_runtime_artifacts() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
            ;;
        x86_64)
            if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
                ensure_x86_runner_ready
            fi
            if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
                ensure_x86_daemon_ready
            fi
            ;;
        *)
            die "unsupported AWS target arch for runtime prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_kinsn_modules() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_arm64_kinsn_modules_ready
            ;;
        x86_64)
            ensure_x86_kinsn_modules_ready
            ;;
        *)
            die "unsupported AWS target arch for kinsn prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_test_outputs() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_arm64_selftest_outputs
            ;;
        x86_64)
            ensure_x86_selftest_outputs
            ;;
        *)
            die "unsupported AWS target arch for test artifact prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_upstream_selftests() {
    case "$RUN_TARGET_ARCH" in
        arm64) ;;
        x86_64) ensure_x86_upstream_selftests_ready ;;
        *) die "unsupported AWS target arch for upstream selftest prep: ${RUN_TARGET_ARCH}" ;;
    esac
}

prepare_aws_upstream_test_kmods() {
    case "$RUN_TARGET_ARCH" in
        arm64) ensure_arm64_upstream_test_kmods_ready ;;
        x86_64) ;;
        *) die "unsupported AWS target arch for upstream test kmods prep: ${RUN_TARGET_ARCH}" ;;
    esac
}

prepare_aws_micro_programs() {
    local_prep_build_micro_program_outputs \
        "$ROOT_DIR/runner" \
        "$MICRO_PROGRAMS_GENERATED_DIR" \
        "$ROOT_DIR/micro/generated-inputs"
}

prepare_aws_fetch_repos() {
    ensure_selected_repos_fetched "${RUN_FETCH_REPOS_CSV:-}"
}

prepare_aws_scx_artifacts() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_arm64_scx_artifacts_ready
            ;;
        x86_64)
            ensure_x86_scx_artifacts_ready
            ;;
        *)
            die "unsupported AWS target arch for scx prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_native_repo_artifacts() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_arm64_native_repo_artifacts_ready
            ;;
        x86_64)
            ensure_x86_native_repo_artifacts_ready
            ;;
        *)
            die "unsupported AWS target arch for native repo prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_workload_tools() {
    case "$RUN_TARGET_ARCH" in
        arm64)
            ensure_arm64_workload_tools_ready
            ;;
        x86_64)
            ensure_x86_workload_tools_ready
            ;;
        *)
            die "unsupported AWS target arch for workload-tool prep: ${RUN_TARGET_ARCH}"
            ;;
    esac
}

prepare_aws_benchmark_extra() {
    case "$RUN_TARGET_ARCH" in
        arm64) ;;
        x86_64) ensure_x86_portable_libbpf_ready ;;
        *) die "unsupported AWS target arch for benchmark extra prep: ${RUN_TARGET_ARCH}" ;;
    esac
}

aws_prepare_local_init() {
    ensure_dirs
    load_remote_prep_state
}

aws_prepare_local_bundle() {
    local stage_root bundle_tar bundle_inputs_path
    stage_root="$RUN_PREP_ROOT/workspace"
    bundle_tar="$RUN_PREP_ROOT/bundle.tar.gz"
    bundle_inputs_path="$RUN_PREP_ROOT/bundle-inputs.json"
    RUN_BUNDLE_TAR="$bundle_tar"
    write_common_bundle_inputs \
        "$bundle_inputs_path" \
        "$LOCAL_REPO_ROOT" \
        "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}" \
        "${RUN_LOCAL_WORKLOAD_TOOL_ROOT:-}" \
        "$MICRO_PROGRAMS_GENERATED_DIR"
    case "${RUN_TARGET_ARCH}" in
        arm64)
            write_kinsn_bundle_input \
                "$bundle_inputs_path" \
                "${RUN_NEEDS_KINSN_MODULES:-0}" \
                "$ARM64_KINSN_MODULE_STAGE_DIR"
            ;;
        x86_64)
            write_kinsn_bundle_input \
                "$bundle_inputs_path" \
                "${RUN_NEEDS_KINSN_MODULES:-0}" \
                "$X86_KINSN_MODULE_STAGE_DIR"
            ;;
        *)
            die "unsupported target arch for bundled module inputs: ${RUN_TARGET_ARCH}"
            ;;
    esac
    write_x86_bundle_inputs \
        "$bundle_inputs_path" \
        "$X86_RUNNER" \
        "$X86_DAEMON" \
        "$X86_TEST_UNITTEST_BUILD_DIR" \
        "$X86_TEST_NEGATIVE_BUILD_DIR" \
        "$X86_UPSTREAM_SELFTEST_DIR" \
        "$X86_PORTABLE_LIBBPF_ROOT" \
        "$LOCAL_PROMOTE_ROOT/corpus/build" \
        "$LOCAL_REPO_ROOT/scx/target/release" \
        "$LOCAL_PROMOTE_ROOT/corpus/build/scx" \
        "$LOCAL_PROMOTE_ROOT/corpus/build/katran/bin/katran_server_grpc" \
        "$LOCAL_PROMOTE_ROOT/corpus/build/katran/lib"
    write_arm64_bundle_inputs \
        "$bundle_inputs_path" \
        "$ARM64_CROSS_RUNNER" \
        "$ARM64_CROSS_RUNNER_REAL" \
        "$ARM64_CROSS_DAEMON" \
        "$ARM64_CROSS_DAEMON_REAL" \
        "$ARM64_CROSS_LIB_DIR" \
        "$ARM64_TEST_UNITTEST_BUILD_DIR" \
        "$ARM64_TEST_NEGATIVE_BUILD_DIR" \
        "$ARM64_UPSTREAM_SELFTEST_DIR" \
        "$ARM64_UPSTREAM_TEST_KMODS_DIR" \
        "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build" \
        "$ARM64_CROSSBUILD_OUTPUT_DIR/runner/repos/scx/target/release" \
        "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/scx" \
        "$ARM64_KATRAN_SERVER_BINARY" \
        "$ARM64_KATRAN_SERVER_LIB_DIR"
    local_prep_build_workspace_bundle \
        "$ROOT_DIR" \
        "$MANIFEST_PATH" \
        "$bundle_inputs_path" \
        "$stage_root" \
        "$RUN_BUNDLE_TAR"
}

aws_emit_local_state() {
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle tar is unset"
    [[ -n "${LOCAL_STATE_PATH:-}" ]] || die "LOCAL_STATE_PATH is required for AWS local prep"
    write_state_json "$LOCAL_STATE_PATH" "RUN_BUNDLE_TAR=$RUN_BUNDLE_TAR"
}

aws_finalize_local_prep() {
    aws_prepare_local_bundle
    aws_emit_local_state
}
