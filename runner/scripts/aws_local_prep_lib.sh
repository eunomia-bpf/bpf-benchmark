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
    [[ "${RUN_TARGET_NAME:-}" == "aws-arm64" ]] || return 0
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
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
        runtime_targets+=(runner)
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        runtime_targets+=(daemon)
    fi
    [[ "${#runtime_targets[@]}" -gt 0 ]] || return 0
    configure_arm64_sysroot_contract
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
        ARM64_CROSSBUILD_RUNTIME_TARGETS="$(IFS=,; printf '%s' "${runtime_targets[*]}")" \
        ARM64_CROSSBUILD_ENABLE_LLVMBPF="$llvmbpf_setting" >/dev/null
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
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
    make -C "$ROOT_DIR/runner" __arm64-test-artifacts \
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

ensure_x86_portable_libbpf_ready() {
    bash "$ROOT_DIR/runner/scripts/build-x86-portable-libbpf.sh" "$X86_PORTABLE_LIBBPF_ROOT" >/dev/null
    require_nonempty_dir "$X86_PORTABLE_LIBBPF_ROOT/lib" "portable x86 libbpf dir"
    require_local_path "$X86_PORTABLE_LIBBPF_ROOT/lib/libbpf.so.1" "portable x86 libbpf soname"
}

x86_tool_should_be_bundled() {
    case "$1" in
        wrk|sysbench|hackbench|stress-ng|fio|bpftrace) return 0 ;;
    esac
    return 1
}

arm64_tool_should_be_bundled() {
    case "$1" in
        wrk|sysbench|hackbench) return 0 ;;
    esac
    return 1
}

ensure_x86_workload_tools_ready() {
    local tool bundled_csv="" local_tool_root tool_path
    [[ -n "${RUN_WORKLOAD_TOOLS_CSV:-}" ]] || {
        RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
        return 0
    }
    IFS=',' read -r -a _x86_workload_tools <<<"$RUN_WORKLOAD_TOOLS_CSV"
    for tool in "${_x86_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        x86_tool_should_be_bundled "$tool" || continue
        bundled_csv="$(csv_append_unique "$bundled_csv" "$tool")"
    done
    [[ -n "$bundled_csv" ]] || {
        RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
        return 0
    }
    local_tool_root="$LOCAL_PROMOTE_ROOT/workload-tools"
    rm -rf "$local_tool_root"
    mkdir -p "$local_tool_root/bin"
    for tool in "${_x86_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        x86_tool_should_be_bundled "$tool" || continue
        tool_path="$(command -v "$tool" 2>/dev/null || true)"
        [[ -n "$tool_path" && -x "$tool_path" ]] \
            || die "required x86 bundled workload tool is missing on the host: ${tool}"
        cp -L "$tool_path" "$local_tool_root/bin/$tool"
        chmod 0755 "$local_tool_root/bin/$tool"
        require_local_path "$local_tool_root/bin/$tool" "x86 bundled workload tool ${tool}"
    done
    RUN_LOCAL_WORKLOAD_TOOL_ROOT="$local_tool_root"
    RUN_BUNDLED_WORKLOAD_TOOLS_CSV="$bundled_csv"
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
        ARM64_WORKLOAD_TOOLS_SOURCE_ROOT="$LOCAL_REPO_ROOT" \
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
    ensure_selected_repos_fetched "$RUN_BENCHMARK_REPOS_CSV"
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

aws_prepare_local_test_artifacts() {
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

aws_prepare_local_benchmark_artifacts() {
    case "$RUN_SUITE_NAME" in
        micro)
            case "$RUN_TARGET_NAME" in
                aws-arm64)
                    ensure_cross_arm64_runtime "${RUN_SUITE_NEEDS_LLVMBPF:-0}"
                    make -C "$ROOT_DIR/runner" MICRO_PROGRAM_OUTPUT_DIR="$MICRO_PROGRAMS_GENERATED_DIR" micro-programs >/dev/null
                    require_nonempty_dir "$MICRO_PROGRAMS_GENERATED_DIR" "micro generated programs dir"
                    ;;
                aws-x86)
                    ensure_x86_runner_ready
                    make -C "$ROOT_DIR/runner" MICRO_PROGRAM_OUTPUT_DIR="$MICRO_PROGRAMS_GENERATED_DIR" micro-programs >/dev/null
                    require_nonempty_dir "$MICRO_PROGRAMS_GENERATED_DIR" "micro generated programs dir"
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
                    ensure_arm64_workload_tools_ready
                    ;;
                aws-x86)
                    ensure_x86_daemon_ready
                    ensure_x86_scx_artifacts_ready
                    ensure_x86_kinsn_modules_ready
                    ensure_x86_native_repo_artifacts_ready
                    ensure_x86_portable_libbpf_ready
                    ensure_x86_workload_tools_ready
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

aws_prepare_local_suite_artifacts() {
    case "$RUN_SUITE_NAME" in
        test) aws_prepare_local_test_artifacts ;;
        micro|corpus|e2e) aws_prepare_local_benchmark_artifacts ;;
        *) die "unsupported suite for local artifact preparation: ${RUN_SUITE_NAME}" ;;
    esac
}

aws_prepare_local_bundle() {
    local stage_root bundle_tar bundle_inputs_path
    stage_root="$RUN_PREP_ROOT/workspace"
    bundle_tar="$RUN_PREP_ROOT/bundle.tar.gz"
    bundle_inputs_path="$RUN_PREP_ROOT/bundle-inputs.env"
    RUN_INPUT_STAGE_ROOT="$stage_root"
    RUN_BUNDLE_TAR="$bundle_tar"
    rm -rf "$stage_root"
    mkdir -p "$(dirname "$bundle_tar")"
    : >"$bundle_inputs_path"
    write_bundle_input_var "$bundle_inputs_path" RUN_LOCAL_PROMOTE_ROOT "$LOCAL_PROMOTE_ROOT"
    write_bundle_input_var "$bundle_inputs_path" RUN_BUNDLED_WORKLOAD_TOOLS_CSV "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}"
    "$ROOT_DIR/runner/scripts/build_remote_bundle.sh" "$MANIFEST_PATH" "$bundle_inputs_path" "$RUN_INPUT_STAGE_ROOT" "$RUN_BUNDLE_TAR"
}

aws_emit_local_state() {
    [[ -n "${RUN_INPUT_STAGE_ROOT:-}" ]] || die "local stage root is unset"
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle tar is unset"
    printf 'RUN_LOCAL_STAGE_ROOT=%q\n' "$RUN_INPUT_STAGE_ROOT"
    printf 'RUN_LOCAL_STAGE_MANIFEST=%q\n' "$RUN_INPUT_STAGE_ROOT/run-contract.env"
    printf 'RUN_INPUT_STAGE_ROOT=%q\n' "$RUN_INPUT_STAGE_ROOT"
    printf 'RUN_BUNDLE_TAR=%q\n' "$RUN_BUNDLE_TAR"
    printf 'RUN_LOCAL_PROMOTE_ROOT=%q\n' "$LOCAL_PROMOTE_ROOT"
    printf 'RUN_BUNDLED_WORKLOAD_TOOLS_CSV=%q\n' "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}"
}

aws_prepare_local_action() {
    ensure_dirs
    load_state
    aws_prepare_local_suite_artifacts
    aws_prepare_local_bundle
    aws_emit_local_state
}
