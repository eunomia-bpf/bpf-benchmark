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

stage_matching_micro_sidecars() {
    local output_dir="$1"
    local source_dir="$ROOT_DIR/micro/generated-inputs"
    local generated_file program_name source_name staged_name
    while IFS= read -r -d '' generated_file; do
        program_name="$(basename "$generated_file" .bpf.o)"
        for source_name in directive.bin policy.bin; do
            [[ -f "$source_dir/${program_name}.${source_name}" ]] || continue
            staged_name="${program_name}.bpf.o.${source_name}"
            cp -a "$source_dir/${program_name}.${source_name}" "$output_dir/$staged_name"
        done
    done < <(find "$output_dir" -maxdepth 1 -type f -name '*.bpf.o' -print0)
}

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
    rm -rf "$output_dir"
    make -C "$RUNNER_DIR" MICRO_PROGRAM_OUTPUT_DIR="$output_dir" micro-programs >/dev/null
    stage_matching_micro_sidecars "$output_dir"
    touch "$output_dir/.build.stamp"
    require_nonempty_dir "$output_dir" "micro generated programs dir"
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

write_kvm_bundle_inputs() {
    local promote_root="$1"
    local bundle_inputs_path="$2"
    local test_artifacts_root="$promote_root/test-artifacts"
    local repo_root="$promote_root/runner/repos"
    local native_build_root="$promote_root/corpus/build"
    : >"$bundle_inputs_path"
    write_bundle_input_var "$bundle_inputs_path" RUN_LOCAL_REPO_ROOT "$repo_root"
    write_bundle_input_var "$bundle_inputs_path" RUN_BUNDLED_WORKLOAD_TOOLS_CSV "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}"
    write_bundle_input_var_if_set "$bundle_inputs_path" RUN_LOCAL_WORKLOAD_TOOL_ROOT "${RUN_LOCAL_WORKLOAD_TOOL_ROOT:-}"
    write_bundle_input_var_if_set "$bundle_inputs_path" MICRO_PROGRAMS_GENERATED_DIR "$promote_root/micro/programs"
    write_bundle_input_var_if_set "$bundle_inputs_path" RUN_KINSN_MODULE_DIR "$test_artifacts_root/kinsn-modules/x86"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_RUNNER "$promote_root/runner/build/micro_exec"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_DAEMON "$promote_root/daemon/target/release/bpfrejit-daemon"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_TEST_UNITTEST_BUILD_DIR "$test_artifacts_root/unittest/build"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_TEST_NEGATIVE_BUILD_DIR "$test_artifacts_root/negative/build"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_UPSTREAM_SELFTEST_DIR "$test_artifacts_root/upstream-bpf-selftests"
    if [[ -d "$promote_root/portable-libbpf/lib" ]]; then
        write_bundle_input_var "$bundle_inputs_path" X86_PORTABLE_LIBBPF_ROOT "$promote_root/portable-libbpf"
    fi
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_NATIVE_BUILD_ROOT "$native_build_root"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_SCX_BINARY_ROOT "$repo_root/scx/target/release"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_SCX_OBJECT_ROOT "$native_build_root/scx"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_KATRAN_SERVER_BINARY "$native_build_root/katran/bin/katran_server_grpc"
    write_bundle_input_var_if_set "$bundle_inputs_path" X86_KATRAN_SERVER_LIB_DIR "$native_build_root/katran/lib"
}

prepare_kvm_inputs() {
    local promote_root="$1"
    local native_repos="${RUN_NATIVE_REPOS_CSV:-}"
    local fetch_repos="${RUN_FETCH_REPOS_CSV:-}"
    local scx_packages="${RUN_SCX_PACKAGES_CSV:-}"
    local test_mode="${RUN_TEST_MODE:-test}"
    local test_artifacts_root="$promote_root/test-artifacts"
    RUN_LOCAL_WORKLOAD_TOOL_ROOT=""
    RUN_BUNDLED_WORKLOAD_TOOLS_CSV=""
    rm -rf "$promote_root"
    mkdir -p "$promote_root"
    case "$RUN_SUITE_NAME" in
        test)
            make -C "$RUNNER_DIR" kernel-image >/dev/null
            if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" DAEMON_TARGET_DIR="$promote_root/daemon/target" daemon-binary >/dev/null
            fi
            if [[ "${RUN_NEEDS_KINSN_MODULES:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$test_artifacts_root/kinsn-modules/x86" kinsn-modules-build >/dev/null
            fi
            case "$test_mode" in
                selftest)
                    local_prep_build_x86_repo_tests \
                        "$RUNNER_DIR" \
                        "$test_artifacts_root/unittest/build" \
                        "$test_artifacts_root/negative/build"
                    ;;
                negative)
                    make -C "$RUNNER_DIR" NEGATIVE_BUILD_DIR="$test_artifacts_root/negative/build" negative-build >/dev/null
                    build_promoted_scx_artifacts "$promote_root"
                    ;;
                test)
                    local_prep_build_x86_repo_tests \
                        "$RUNNER_DIR" \
                        "$test_artifacts_root/unittest/build" \
                        "$test_artifacts_root/negative/build"
                    local_prep_build_x86_upstream_selftests \
                        "$RUNNER_DIR" \
                        "$test_artifacts_root/upstream-bpf-selftests" \
                        "$ROOT_DIR/vendor/linux-framework/vmlinux" \
                        "$HOST_PYTHON_BIN" \
                        "${RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
                    build_promoted_scx_artifacts "$promote_root"
                    ;;
                *)
                    die "unsupported KVM test mode: ${test_mode}"
                    ;;
            esac
            ;;
        micro)
            make -C "$RUNNER_DIR" kernel-image >/dev/null
            if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" BUILD_DIR="$promote_root/runner/build" micro_exec >/dev/null
            fi
            promote_micro_program_outputs "$promote_root/micro/programs"
            ;;
        corpus)
            make -C "$RUNNER_DIR" kernel-image >/dev/null
            if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" DAEMON_TARGET_DIR="$promote_root/daemon/target" daemon-binary >/dev/null
            fi
            if [[ "${RUN_NEEDS_KINSN_MODULES:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$test_artifacts_root/kinsn-modules/x86" kinsn-modules-build >/dev/null
            fi
            if [[ -n "$fetch_repos" ]]; then
                fetch_promoted_repos "$promote_root" "$fetch_repos"
            fi
            build_promoted_scx_artifacts "$promote_root"
            build_promoted_native_repos "$promote_root"
            ensure_kvm_x86_workload_tools_ready "$promote_root/workload-tools"
            ;;
        e2e)
            make -C "$RUNNER_DIR" kernel-image >/dev/null
            if [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" BUILD_DIR="$promote_root/runner/build" micro_exec >/dev/null
            fi
            if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" DAEMON_TARGET_DIR="$promote_root/daemon/target" daemon-binary >/dev/null
            fi
            if [[ "${RUN_NEEDS_KINSN_MODULES:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$test_artifacts_root/kinsn-modules/x86" kinsn-modules-build >/dev/null
            fi
            if [[ -n "$fetch_repos" ]]; then
                fetch_promoted_repos "$promote_root" "$fetch_repos"
            fi
            if [[ -n "$native_repos" ]]; then
                build_promoted_native_repos "$promote_root"
            fi
            if [[ -n "$scx_packages" ]]; then
                build_promoted_scx_artifacts "$promote_root"
            fi
            ensure_kvm_x86_workload_tools_ready "$promote_root/workload-tools"
            ;;
        *)
            die "unsupported KVM suite: ${RUN_SUITE_NAME}"
            ;;
    esac
}

stage_kvm_workspace() {
    local stage_token stage_root bundle_tar staged_manifest promote_root bundle_inputs_path
    stage_token="$(basename "$MANIFEST_PATH" .env)"
    stage_root="$ROOT_DIR/.cache/kvm-staged/${stage_token}/workspace"
    bundle_tar="$ROOT_DIR/.cache/kvm-staged/${stage_token}.tar.gz"
    promote_root="$ROOT_DIR/.cache/kvm-staged/${stage_token}/prep"
    bundle_inputs_path="$ROOT_DIR/.cache/kvm-staged/${stage_token}/bundle-inputs.env"
    prepare_kvm_inputs "$promote_root"
    rm -rf "$stage_root"
    mkdir -p "$(dirname "$bundle_tar")"
    write_kvm_bundle_inputs "$promote_root" "$bundle_inputs_path"
    bash "$ROOT_DIR/runner/scripts/build_remote_bundle.sh" \
        "$MANIFEST_PATH" \
        "$bundle_inputs_path" \
        "$stage_root" \
        "$bundle_tar"
    rm -f "$bundle_tar"
    staged_manifest="$stage_root/run-contract.env"
    [[ -f "$staged_manifest" ]] || die "staged KVM manifest is missing: ${staged_manifest}"
    printf 'RUN_LOCAL_STAGE_ROOT=%q\n' "$stage_root"
    printf 'RUN_LOCAL_STAGE_MANIFEST=%q\n' "$staged_manifest"
}

kvm_prepare_local_action() {
    stage_kvm_workspace
}
