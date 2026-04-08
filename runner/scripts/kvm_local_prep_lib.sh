#!/usr/bin/env bash
set -euo pipefail

# Internal KVM local-prep library.
# Callers must define:
# - ROOT_DIR
# - MANIFEST_PATH
# - HOST_PYTHON_BIN
# - die()
RUNNER_DIR="${RUNNER_DIR:-$ROOT_DIR/runner}"
#
# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/local_prep_common_lib.sh"

fetch_promoted_repos() {
    local promote_root="$1"
    local repo_csv="$2"
    local_prep_fetch_selected_repos "$promote_root/runner/repos" "$repo_csv" "$HOST_PYTHON_BIN" "$ROOT_DIR"
}

build_promoted_native_repos() {
    local promote_root="$1"
    local_prep_build_native_repo_artifacts \
        "$promote_root/runner/repos" \
        "$promote_root" \
        "${RUN_NATIVE_REPOS_CSV:-}" \
        "$HOST_PYTHON_BIN" \
        "$ROOT_DIR"
}

promote_micro_program_outputs() {
    local output_dir="$1"
    local_prep_build_micro_program_outputs "$RUNNER_DIR" "$output_dir" "$ROOT_DIR/micro/generated-inputs"
}

build_promoted_scx_artifacts() {
    local promote_root="$1"
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    fetch_promoted_repos "$promote_root" "scx"
    local_prep_build_scx_artifacts \
        "$promote_root/runner/repos" \
        "$promote_root" \
        "$RUN_SCX_PACKAGES_CSV" \
        "$HOST_PYTHON_BIN" \
        "$ROOT_DIR"
}

ensure_kvm_x86_workload_tools_ready() {
    local local_tool_root="$1"
    local_prep_stage_x86_workload_tools \
        "${RUN_WORKLOAD_TOOLS_CSV:-}" \
        "$local_tool_root" \
        RUN_BUNDLED_WORKLOAD_TOOLS_CSV \
        RUN_LOCAL_WORKLOAD_TOOL_ROOT
}

ensure_kvm_kernel_image_ready() {
    make -C "$RUNNER_DIR" kernel-image >/dev/null
}

prepare_kvm_runtime_artifacts() {
    if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
        local_prep_build_runner_binary "$RUNNER_DIR" "$KVM_PROMOTE_ROOT/runner/build"
    fi
    if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
        local_prep_build_daemon_binary "$RUNNER_DIR" "$KVM_PROMOTE_ROOT/daemon/target"
    fi
}

prepare_kvm_kinsn_modules() {
    make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$KVM_TEST_ARTIFACTS_ROOT/kinsn-modules/x86" kinsn-modules-build >/dev/null
}

prepare_kvm_test_outputs() {
    case "${RUN_TEST_MODE:-test}" in
        selftest|test)
            local_prep_build_x86_repo_tests \
                "$RUNNER_DIR" \
                "$KVM_TEST_ARTIFACTS_ROOT/unittest/build" \
                "$KVM_TEST_ARTIFACTS_ROOT/negative/build"
            ;;
        negative)
            make -C "$RUNNER_DIR" NEGATIVE_BUILD_DIR="$KVM_TEST_ARTIFACTS_ROOT/negative/build" negative-build >/dev/null
            ;;
        *)
            die "unsupported KVM test mode: ${RUN_TEST_MODE:-test}"
            ;;
    esac
}

prepare_kvm_upstream_selftests() {
    local_prep_build_x86_upstream_selftests \
        "$RUNNER_DIR" \
        "$KVM_TEST_ARTIFACTS_ROOT/upstream-bpf-selftests" \
        "$ROOT_DIR/vendor/linux-framework/vmlinux" \
        "$HOST_PYTHON_BIN" \
        "${RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
}

prepare_kvm_micro_programs() {
    promote_micro_program_outputs "$KVM_PROMOTE_ROOT/micro/programs"
}

prepare_kvm_fetch_repos() {
    fetch_promoted_repos "$KVM_PROMOTE_ROOT" "${RUN_FETCH_REPOS_CSV:-}"
}

prepare_kvm_scx_artifacts() {
    build_promoted_scx_artifacts "$KVM_PROMOTE_ROOT"
}

prepare_kvm_native_repo_artifacts() {
    build_promoted_native_repos "$KVM_PROMOTE_ROOT"
}

prepare_kvm_workload_tools() {
    ensure_kvm_x86_workload_tools_ready "$KVM_PROMOTE_ROOT/workload-tools"
}

write_kvm_bundle_inputs() {
    local promote_root="$1"
    local bundle_inputs_path="$2"
    local test_artifacts_root="$promote_root/test-artifacts"
    local repo_root="$promote_root/runner/repos"
    local native_build_root="$promote_root/corpus/build"
    local portable_libbpf_root=""
    write_common_bundle_inputs \
        "$bundle_inputs_path" \
        "$repo_root" \
        "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}" \
        "${RUN_LOCAL_WORKLOAD_TOOL_ROOT:-}" \
        "$promote_root/micro/programs"
    write_kinsn_bundle_input \
        "$bundle_inputs_path" \
        "${RUN_NEEDS_KINSN_MODULES:-0}" \
        "$test_artifacts_root/kinsn-modules/x86"
    if [[ -d "$promote_root/portable-libbpf/lib" ]]; then
        portable_libbpf_root="$promote_root/portable-libbpf"
    fi
    write_x86_bundle_inputs \
        "$bundle_inputs_path" \
        "$promote_root/runner/build/micro_exec" \
        "$promote_root/daemon/target/release/bpfrejit-daemon" \
        "$test_artifacts_root/unittest/build" \
        "$test_artifacts_root/negative/build" \
        "$test_artifacts_root/upstream-bpf-selftests" \
        "$portable_libbpf_root" \
        "$native_build_root" \
        "$repo_root/scx/target/release" \
        "$native_build_root/scx" \
        "$native_build_root/katran/bin/katran_server_grpc" \
        "$native_build_root/katran/lib"
}

kvm_set_local_prep_roots() {
    local promote_root="$1"
    KVM_PROMOTE_ROOT="$promote_root"
    KVM_TEST_ARTIFACTS_ROOT="$promote_root/test-artifacts"
    RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
    RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
}

kvm_prepare_local_init() {
    local promote_root="$ROOT_DIR/.cache/kvm-staged/${RUN_TOKEN}/prep"
    kvm_set_local_prep_roots "$promote_root"
    rm -rf "$promote_root"
    mkdir -p "$promote_root"
}

stage_kvm_workspace() {
    local stage_token stage_root bundle_tar promote_root bundle_inputs_path
    stage_token="${RUN_TOKEN:-}"
    [[ -n "$stage_token" ]] || die "manifest RUN_TOKEN is empty for KVM local prep"
    stage_root="$ROOT_DIR/.cache/kvm-staged/${stage_token}/workspace"
    bundle_tar="$ROOT_DIR/.cache/kvm-staged/${stage_token}.tar.gz"
    promote_root="$ROOT_DIR/.cache/kvm-staged/${stage_token}/prep"
    bundle_inputs_path="$ROOT_DIR/.cache/kvm-staged/${stage_token}/bundle-inputs.json"
    prepare_kvm_inputs "$promote_root"
    write_kvm_bundle_inputs "$promote_root" "$bundle_inputs_path"
    local_prep_build_workspace_bundle \
        "$ROOT_DIR" \
        "$MANIFEST_PATH" \
        "$bundle_inputs_path" \
        "$stage_root" \
        "$bundle_tar"
    [[ -f "$bundle_tar" ]] || die "staged KVM bundle tar is missing: ${bundle_tar}"
    [[ -n "${LOCAL_STATE_PATH:-}" ]] || die "LOCAL_STATE_PATH is required for KVM local prep"
    write_state_json "$LOCAL_STATE_PATH" "RUN_BUNDLE_TAR=$bundle_tar"
}

kvm_finalize_local_prep() {
    stage_kvm_workspace
}
