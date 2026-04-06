#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RUNNER_DIR="$ROOT_DIR/runner"
MANIFEST_PATH="${1:?usage: prepare_local_inputs.sh <manifest_path>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[prepare-local-inputs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

die() {
    printf '[prepare-local-inputs][ERROR] %s\n' "$*" >&2
    exit 1
}

HOST_PYTHON_BIN="${RUN_HOST_PYTHON_BIN:-}"
[[ -n "$HOST_PYTHON_BIN" ]] || die "manifest host python is missing"

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

copy_tree_contents() {
    local src="$1"
    local dst="$2"
    require_local_path "$src" "copy source"
    mkdir -p "$dst"
    cp -a "$src/." "$dst/"
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

snapshot_git_tree() {
    local src="$1"
    local dest="$2"
    snapshot_git_subtree "$src" "" "$dest"
}

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
    local repo
    local args=()
    [[ -n "$repo_csv" ]] || return 0
    IFS=',' read -r -a _promote_fetch_repos <<<"$repo_csv"
    for repo in "${_promote_fetch_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    "$HOST_PYTHON_BIN" "$RUNNER_DIR/scripts/fetch_corpus_repos.py" \
        --repo-root "$promote_root/runner/repos" \
        "${args[@]}" >/dev/null
}

build_promoted_native_repos() {
    local promote_root="$1"
    local promoted_repos_root="$promote_root/runner/repos"
    local katran_input_root="$promote_root/.inputs/katran"
    local repo
    local args=()
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    [[ -d "$promoted_repos_root" ]] || die "promoted repo root missing for native repo build: ${promoted_repos_root}"
    IFS=',' read -r -a _promote_native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    for repo in "${_promote_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        args+=(--repo "$repo")
    done
    [[ "${#args[@]}" -gt 0 ]] || return 0
    if [[ ",${RUN_NATIVE_REPOS_CSV:-}," == *",katran,"* ]]; then
        rm -rf "$katran_input_root"
        mkdir -p "$katran_input_root/bin" "$katran_input_root/lib"
        snapshot_git_subtree "$ROOT_DIR" "e2e/cases/katran/bin" "$katran_input_root/bin"
        snapshot_git_subtree "$ROOT_DIR" "e2e/cases/katran/lib" "$katran_input_root/lib"
        require_local_path "$katran_input_root/bin/katran_server_grpc" "sealed KVM Katran server source bundle"
        require_nonempty_dir "$katran_input_root/lib" "sealed KVM Katran lib dir"
        KATRAN_SERVER_BINARY="$katran_input_root/bin/katran_server_grpc" \
            KATRAN_SERVER_LIB_DIR="$katran_input_root/lib" \
            "$HOST_PYTHON_BIN" "$RUNNER_DIR/scripts/build_corpus_native.py" \
                --jobs "$(nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)" \
                --repo-root "$promoted_repos_root" \
                --build-root "$promote_root/corpus/build" \
                "${args[@]}" >/dev/null
        return 0
    fi
    "$HOST_PYTHON_BIN" "$RUNNER_DIR/scripts/build_corpus_native.py" \
        --jobs "$(nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)" \
        --repo-root "$promoted_repos_root" \
        --build-root "$promote_root/corpus/build" \
        "${args[@]}" >/dev/null
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
    local package
    local scx_args=()
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    fetch_promoted_repos "$promote_root" "scx"
    IFS=',' read -r -a _promote_scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_promote_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        scx_args+=(--package "$package")
    done
    [[ "${#scx_args[@]}" -gt 0 ]] || die "manifest scx package contract is empty"
    "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/build_scx_artifacts.py" \
        --force \
        --repo-root "$promote_root/runner/repos" \
        --promote-root "$promote_root" \
        "${scx_args[@]}" >/dev/null
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

write_kvm_bundle_inputs() {
    local promote_root="$1"
    local bundle_inputs_path="$2"
    cat >"$bundle_inputs_path" <<EOF
RUN_LOCAL_PROMOTE_ROOT=$(printf '%q' "$promote_root")
RUN_LOCAL_REPO_ROOT=$(printf '%q' "$promote_root/runner/repos")
MICRO_PROGRAMS_GENERATED_DIR=$(printf '%q' "$promote_root/micro/programs")
RUN_KINSN_MODULE_DIR=$(printf '%q' "$promote_root/module/x86")
X86_RUNNER=$(printf '%q' "$promote_root/runner/build/micro_exec")
X86_DAEMON=$(printf '%q' "$promote_root/daemon/target/release/bpfrejit-daemon")
X86_TEST_UNITTEST_BUILD_DIR=$(printf '%q' "$promote_root/tests/unittest/build")
X86_TEST_NEGATIVE_BUILD_DIR=$(printf '%q' "$promote_root/tests/negative/build")
X86_UPSTREAM_SELFTEST_DIR=$(printf '%q' "$promote_root/.cache/upstream-bpf-selftests")
EOF
}

prepare_kvm_inputs() {
    local promote_root="$1"
    local native_repos="${RUN_NATIVE_REPOS_CSV:-}"
    local benchmark_repos="${RUN_BENCHMARK_REPOS_CSV:-}"
    local scx_packages="${RUN_SCX_PACKAGES_CSV:-}"
    local test_mode="${RUN_TEST_MODE:-test}"
    local repo
    rm -rf "$promote_root"
    mkdir -p "$promote_root"
    case "$RUN_SUITE_NAME" in
        test)
            make -C "$RUNNER_DIR" kernel-image >/dev/null
            if [[ "${RUN_NEEDS_DAEMON_BINARY:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" DAEMON_TARGET_DIR="$promote_root/daemon/target" daemon-binary >/dev/null
            fi
            if [[ "${RUN_NEEDS_KINSN_MODULES:-0}" == "1" ]]; then
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$promote_root/module/x86" kinsn-modules-build >/dev/null
            fi
            case "$test_mode" in
                selftest)
                    make -C "$RUNNER_DIR" UNITTEST_BUILD_DIR="$promote_root/tests/unittest/build" unittest-build >/dev/null
                    make -C "$RUNNER_DIR" NEGATIVE_BUILD_DIR="$promote_root/tests/negative/build" negative-build >/dev/null
                    ;;
                negative)
                    make -C "$RUNNER_DIR" NEGATIVE_BUILD_DIR="$promote_root/tests/negative/build" negative-build >/dev/null
                    build_promoted_scx_artifacts "$promote_root"
                    ;;
                test)
                    make -C "$RUNNER_DIR" UNITTEST_BUILD_DIR="$promote_root/tests/unittest/build" unittest-build >/dev/null
                    make -C "$RUNNER_DIR" NEGATIVE_BUILD_DIR="$promote_root/tests/negative/build" negative-build >/dev/null
                    make -C "$RUNNER_DIR" UPSTREAM_SELFTEST_OUTPUT_DIR="$promote_root/.cache/upstream-bpf-selftests" upstream-selftests-build >/dev/null
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
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$promote_root/module/x86" kinsn-modules-build >/dev/null
            fi
            if [[ -n "$benchmark_repos" ]]; then
                fetch_promoted_repos "$promote_root" "$benchmark_repos"
            fi
            build_promoted_scx_artifacts "$promote_root"
            build_promoted_native_repos "$promote_root"
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
                make -C "$RUNNER_DIR" KINSN_MODULE_OUTPUT_DIR="$promote_root/module/x86" kinsn-modules-build >/dev/null
            fi
            if [[ -n "$benchmark_repos" ]]; then
                fetch_promoted_repos "$promote_root" "$benchmark_repos"
            fi
            if [[ -n "$native_repos" ]]; then
                build_promoted_native_repos "$promote_root"
            fi
            if [[ -n "$scx_packages" ]]; then
                build_promoted_scx_artifacts "$promote_root"
            fi
            ;;
        *)
            die "unsupported KVM suite: ${RUN_SUITE_NAME}"
            ;;
    esac
}

case "${RUN_EXECUTOR}" in
    kvm)
        stage_kvm_workspace
        ;;
    aws-ssh)
        export AWS_EXECUTOR_ACTION=run
        export AWS_EXECUTOR_MANIFEST_PATH="$MANIFEST_PATH"
        # shellcheck disable=SC1090
        source "$ROOT_DIR/runner/scripts/aws_executor.sh"
        ensure_dirs
        with_state_lock ensure_instance_for_suite
        load_state
        prepare_local_inputs
        emit_local_state
        ;;
    *)
        die "unsupported executor for local prep: ${RUN_EXECUTOR}"
        ;;
esac
