#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
MANIFEST_PATH="${1:?usage: build_remote_bundle.sh <manifest_path> <bundle_inputs_path> <bundle_dir> <bundle_tar>}"
BUNDLE_INPUTS_PATH="${2:?usage: build_remote_bundle.sh <manifest_path> <bundle_inputs_path> <bundle_dir> <bundle_tar>}"
BUNDLE_DIR="${3:?usage: build_remote_bundle.sh <manifest_path> <bundle_inputs_path> <bundle_dir> <bundle_tar>}"
BUNDLE_TAR="${4:?usage: build_remote_bundle.sh <manifest_path> <bundle_inputs_path> <bundle_dir> <bundle_tar>}"

[[ -f "$MANIFEST_PATH" ]] || {
    printf '[build-remote-bundle][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
[[ -f "$BUNDLE_INPUTS_PATH" ]] || {
    printf '[build-remote-bundle][ERROR] bundle inputs are missing: %s\n' "$BUNDLE_INPUTS_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"
# shellcheck disable=SC1090
source "$BUNDLE_INPUTS_PATH"

ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-}"
ARM64_CROSS_DAEMON="${ARM64_CROSS_DAEMON:-}"
ARM64_CROSS_DAEMON_REAL="${ARM64_CROSS_DAEMON_REAL:-}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-}"
ARM64_NATIVE_BUILD_ROOT="${ARM64_NATIVE_BUILD_ROOT:-}"
ARM64_SCX_BINARY_ROOT="${ARM64_SCX_BINARY_ROOT:-}"
ARM64_SCX_OBJECT_ROOT="${ARM64_SCX_OBJECT_ROOT:-}"
ARM64_KATRAN_SERVER_BINARY="${ARM64_KATRAN_SERVER_BINARY:-}"
ARM64_KATRAN_SERVER_LIB_DIR="${ARM64_KATRAN_SERVER_LIB_DIR:-}"
ARM64_TEST_UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-}"
ARM64_TEST_NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-}"
ARM64_UPSTREAM_SELFTEST_DIR="${ARM64_UPSTREAM_SELFTEST_DIR:-}"
ARM64_UPSTREAM_TEST_KMODS_DIR="${ARM64_UPSTREAM_TEST_KMODS_DIR:-}"
X86_RUNNER="${X86_RUNNER:-}"
X86_DAEMON="${X86_DAEMON:-}"
X86_TEST_UNITTEST_BUILD_DIR="${X86_TEST_UNITTEST_BUILD_DIR:-}"
X86_TEST_NEGATIVE_BUILD_DIR="${X86_TEST_NEGATIVE_BUILD_DIR:-}"
X86_UPSTREAM_SELFTEST_DIR="${X86_UPSTREAM_SELFTEST_DIR:-}"
X86_PORTABLE_LIBBPF_ROOT="${X86_PORTABLE_LIBBPF_ROOT:-}"
X86_NATIVE_BUILD_ROOT="${X86_NATIVE_BUILD_ROOT:-}"
X86_SCX_BINARY_ROOT="${X86_SCX_BINARY_ROOT:-}"
X86_SCX_OBJECT_ROOT="${X86_SCX_OBJECT_ROOT:-}"
X86_KATRAN_SERVER_BINARY="${X86_KATRAN_SERVER_BINARY:-}"
X86_KATRAN_SERVER_LIB_DIR="${X86_KATRAN_SERVER_LIB_DIR:-}"
MICRO_PROGRAMS_GENERATED_DIR="${MICRO_PROGRAMS_GENERATED_DIR:-}"
RUN_KINSN_MODULE_DIR="${RUN_KINSN_MODULE_DIR:-}"
RUN_LOCAL_REPO_ROOT="${RUN_LOCAL_REPO_ROOT:-}"
RUN_LOCAL_WORKLOAD_TOOL_ROOT="${RUN_LOCAL_WORKLOAD_TOOL_ROOT:-}"
RUN_BUNDLED_WORKLOAD_TOOLS_CSV="${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}"

die() {
    printf '[build-remote-bundle][ERROR] %s\n' "$*" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/local_prep_common_lib.sh"

target_arch_is_arm64() {
    [[ "$RUN_TARGET_ARCH" == "arm64" ]]
}

target_arch_is_x86() {
    [[ "$RUN_TARGET_ARCH" == "x86_64" ]]
}

test_mode_needs_unittest() {
    case "${RUN_TEST_MODE:-test}" in
        selftest|test) return 0 ;;
    esac
    return 1
}

test_mode_needs_negative() {
    case "${RUN_TEST_MODE:-test}" in
        selftest|negative|test) return 0 ;;
    esac
    return 1
}

test_mode_needs_upstream() {
    [[ "${RUN_TEST_MODE:-test}" == "test" ]]
}

bundle_copy_tree() {
    local src="$1"
    local dest="$2"
    mkdir -p "$(dirname "$dest")"
    cp -a "$src" "$dest"
}

bundle_copy_tracked_tree() {
    local src_rel="$1"
    local dest_root="$2"
    local rel_path
    mkdir -p "$dest_root"
    while IFS= read -r -d '' rel_path; do
        mkdir -p "$dest_root/$(dirname "$rel_path")"
        cp -a "$ROOT_DIR/$rel_path" "$dest_root/$rel_path"
    done < <(git -C "$ROOT_DIR" ls-files -z -- "$src_rel")
}

bundle_copy_repo_tracked_tree() {
    local repo_root="$1"
    local src_rel="$2"
    local dest_root="$3"
    git -C "$repo_root" rev-parse --verify HEAD >/dev/null 2>&1 \
        || die "expected git checkout for bundled repo subtree: ${repo_root}"
    git_path_is_clean "$repo_root" "$src_rel" \
        || die "bundled repo subtree has local modifications and cannot be sealed: ${repo_root}/${src_rel}"
    mkdir -p "$dest_root"
    git -C "$repo_root" archive --format=tar HEAD -- "$src_rel" \
        | tar -xf - -C "$dest_root"
}

bundle_copy_git_snapshot() {
    local src="$1"
    local dest="$2"
    if git -C "$src" rev-parse --verify HEAD >/dev/null 2>&1; then
        git_path_is_clean "$src" \
            || die "bundled repo snapshot has local modifications and cannot be sealed: ${src}"
        mkdir -p "$dest"
        git -C "$src" archive --format=tar HEAD | tar -xf - -C "$dest"
        find "$dest" -mindepth 1 -print -quit 2>/dev/null | grep -q . \
            || die "bundled repo snapshot is empty: ${src}"
        return 0
    fi
    require_nonempty_dir "$src" "bundled promoted snapshot dir"
    mkdir -p "$dest"
    cp -a "$src/." "$dest/"
}

materialize_library_soname_links() {
    local lib_dir="$1"
    local lib_path lib_name soname
    [[ -d "$lib_dir" ]] || return 0
    while IFS= read -r -d '' lib_path; do
        lib_name="$(basename "$lib_path")"
        soname="$(readelf -d "$lib_path" 2>/dev/null | sed -n 's/.*Library soname: \[\(.*\)\].*/\1/p' | head -n1)"
        if [[ -n "$soname" && "$soname" != "$lib_name" ]]; then
            ln -sfn "$lib_name" "$lib_dir/$soname"
        fi
    done < <(find "$lib_dir" -maxdepth 1 -type f -print0)
}

binary_requires_runtime_loader() {
    local binary="$1"
    readelf -l "$binary" 2>/dev/null | grep -F "Requesting program interpreter" >/dev/null
}

wrap_dynamic_executable_tree() {
    local root="$1"
    local loader_name="$2"
    local candidate
    [[ -d "$root" ]] || return 0
    mkdir -p "$BUNDLE_DIR/lib"
    while IFS= read -r -d '' candidate; do
        binary_requires_runtime_loader "$candidate" || continue
        stage_runtime_libs "$candidate" "$BUNDLE_DIR/lib"
        mv "$candidate" "${candidate}.bin"
        chmod a-x "${candidate}.bin"
        install_portable_runtime_wrapper "$candidate" "$loader_name"
    done < <(find "$root" -type f -executable -print0)
    materialize_library_soname_links "$BUNDLE_DIR/lib"
}

stage_runtime_libs() {
    local binary="$1"
    local dest_dir="$2"
    local ldd_output ldd_status dep binary_dir sibling_lib_dir sibling_lib64_dir runtime_ld_path
    mkdir -p "$dest_dir"
    binary_dir="$(dirname "$binary")"
    sibling_lib_dir="$(cd "$binary_dir/.." && pwd)/lib"
    sibling_lib64_dir="$(cd "$binary_dir/.." && pwd)/lib64"
    runtime_ld_path="$binary_dir"
    [[ -d "$sibling_lib_dir" ]] && runtime_ld_path="${runtime_ld_path}:$sibling_lib_dir"
    [[ -d "$sibling_lib64_dir" ]] && runtime_ld_path="${runtime_ld_path}:$sibling_lib64_dir"
    set +e
    ldd_output="$(env LD_LIBRARY_PATH="$runtime_ld_path" ldd "$binary" 2>&1)"
    ldd_status=$?
    set -e
    if [[ "$ldd_status" -ne 0 ]]; then
        if grep -Eq 'not a dynamic executable|statically linked' <<<"$ldd_output"; then
            return 0
        fi
        printf '%s\n' "$ldd_output" >&2
        die "failed to inspect runtime libraries for ${binary}"
    fi
    while IFS= read -r dep; do
        [[ -n "$dep" ]] || continue
        case "$dep" in
            not\ found:*)
                die "missing runtime library for ${binary}: ${dep#not found:}"
                ;;
        esac
        [[ -f "$dep" ]] || continue
        cp -L "$dep" "$dest_dir/"
    done < <(printf '%s\n' "$ldd_output" | awk '
        /=> not found/ { print "not found:" $1; next }
        /=>/ { print $3; next }
        /^[[:space:]]*\// { print $1 }
    ')
}

install_portable_runtime_wrapper() {
    local wrapper_path="$1"
    local loader_name="$2"
    cat >"$wrapper_path" <<EOF
#!/usr/bin/env bash
set -euo pipefail
script_path="\$(readlink -f "\$0")"
real_binary="\${script_path}.bin"
search_dir="\$(cd "\$(dirname "\$script_path")" && pwd)"
bundle_root=""
while [[ "\$search_dir" != "/" ]]; do
    if [[ -x "\$search_dir/lib/${loader_name}" ]]; then
        bundle_root="\$search_dir"
        break
    fi
    search_dir="\$(dirname "\$search_dir")"
done
[[ -n "\$bundle_root" ]] || {
    echo "portable runtime loader not found for \$script_path" >&2
    exit 1
}
script_dir="\$(cd "\$(dirname "\$script_path")" && pwd)"
bundle_lib_path="\$script_dir"
case_lib_dir="\$script_dir/../lib"
if [[ -d "\$case_lib_dir" ]]; then
    bundle_lib_path="\$bundle_lib_path:\$case_lib_dir"
fi
bundle_lib_path="\$bundle_lib_path:\$bundle_root/lib"
[[ -f "\$real_binary" ]] || {
    echo "wrapped binary is missing for \$script_path: \$real_binary" >&2
    exit 1
}
exec "\$bundle_root/lib/${loader_name}" --library-path "\$bundle_lib_path" "\$real_binary" "\$@"
EOF
    chmod +x "$wrapper_path"
}

install_passthrough_wrapper() {
    local wrapper_path="$1"
    cat >"$wrapper_path" <<EOF
#!/usr/bin/env bash
set -euo pipefail
script_path="\$(readlink -f "\$0")"
real_binary="\${script_path}.bin"
[[ -f "\$real_binary" ]] || {
    echo "wrapped binary is missing for \$script_path: \$real_binary" >&2
    exit 1
}
exec "\$real_binary" "\$@"
EOF
    chmod +x "$wrapper_path"
}

bundle_copy_runner_tree() {
    mkdir -p "$BUNDLE_DIR/runner"
    bundle_copy_tracked_tree "runner/__init__.py" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/CMakeLists.txt" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/Makefile" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/include" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/repos.yaml" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/libs" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/src" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/install_guest_prereqs.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/prereq_contract.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/suite_entrypoint.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/validate_guest_prereqs.sh" "$BUNDLE_DIR"
    rm -rf \
        "$BUNDLE_DIR/runner/__pycache__" \
        "$BUNDLE_DIR/runner/scripts/__pycache__" \
        "$BUNDLE_DIR/runner/libs/__pycache__" \
        "$BUNDLE_DIR/runner/libs/app_runners/__pycache__"
}

bundle_copy_test_runner_tree() {
    bundle_copy_tracked_tree "runner/scripts/run_all_tests.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/vm-selftest.sh" "$BUNDLE_DIR"
    if test_mode_needs_upstream; then
        bundle_copy_tracked_tree "runner/scripts/build_upstream_selftests.sh" "$BUNDLE_DIR"
        bundle_copy_tracked_tree "runner/config" "$BUNDLE_DIR"
    fi
}

bundle_stage_target_runtime() {
    local needs_runner="${RUN_NEEDS_RUNNER_BINARY:-0}"
    local needs_daemon="${RUN_NEEDS_DAEMON_BINARY:-0}"
    [[ "$needs_runner" == "1" || "$needs_daemon" == "1" ]] || return 0
    mkdir -p "$BUNDLE_DIR/lib"
    if [[ "$needs_runner" == "1" ]]; then
        mkdir -p "$BUNDLE_DIR/runner/build"
    fi
    if [[ "$needs_daemon" == "1" ]]; then
        mkdir -p "$BUNDLE_DIR/daemon/build" "$BUNDLE_DIR/daemon/target/release"
    fi
    if target_arch_is_arm64; then
            if [[ "$needs_runner" == "1" ]]; then
                [[ -n "$ARM64_CROSS_RUNNER" && -n "$ARM64_CROSS_RUNNER_REAL" ]] \
                    || die "bundled ARM64 runner inputs are missing"
                require_local_path "$ARM64_CROSS_RUNNER" "ARM64 runner wrapper"
                require_local_path "$ARM64_CROSS_RUNNER_REAL" "ARM64 runner binary"
                cp "$ARM64_CROSS_RUNNER" "$BUNDLE_DIR/runner/build/micro_exec"
                cp "$ARM64_CROSS_RUNNER_REAL" "$BUNDLE_DIR/runner/build/micro_exec.real"
            fi
            if [[ "$needs_runner" == "1" || "$needs_daemon" == "1" ]]; then
                [[ -n "$ARM64_CROSS_LIB_DIR" ]] || die "bundled ARM64 runtime lib dir is missing"
                require_local_path "$ARM64_CROSS_LIB_DIR" "ARM64 runtime lib dir"
                cp -a "$ARM64_CROSS_LIB_DIR/." "$BUNDLE_DIR/lib/"
                materialize_library_soname_links "$BUNDLE_DIR/lib"
            fi
            if [[ "$needs_daemon" == "1" ]]; then
                [[ -n "$ARM64_CROSS_DAEMON" && -n "$ARM64_CROSS_DAEMON_REAL" ]] \
                    || die "bundled ARM64 daemon inputs are missing"
                require_local_path "$ARM64_CROSS_DAEMON" "ARM64 daemon wrapper"
                require_local_path "$ARM64_CROSS_DAEMON_REAL" "ARM64 daemon binary"
                cp "$ARM64_CROSS_DAEMON" "$BUNDLE_DIR/daemon/build/bpfrejit-daemon"
                cp "$ARM64_CROSS_DAEMON_REAL" "$BUNDLE_DIR/daemon/build/bpfrejit-daemon.real"
                cp "$ARM64_CROSS_DAEMON_REAL" "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon"
            fi
    elif target_arch_is_x86; then
            if [[ "$needs_runner" == "1" ]]; then
                [[ -n "$X86_RUNNER" ]] || die "bundled x86 runner input is missing"
                require_local_path "$X86_RUNNER" "x86 runner binary"
                cp "$X86_RUNNER" "$BUNDLE_DIR/runner/build/micro_exec.bin"
                chmod a-x "$BUNDLE_DIR/runner/build/micro_exec.bin"
                stage_runtime_libs "$X86_RUNNER" "$BUNDLE_DIR/lib"
                if binary_requires_runtime_loader "$X86_RUNNER"; then
                    install_portable_runtime_wrapper "$BUNDLE_DIR/runner/build/micro_exec" "ld-linux-x86-64.so.2"
                else
                    install_passthrough_wrapper "$BUNDLE_DIR/runner/build/micro_exec"
                fi
            fi
            if [[ "$needs_daemon" == "1" ]]; then
                [[ -n "$X86_DAEMON" ]] || die "bundled x86 daemon input is missing"
                require_local_path "$X86_DAEMON" "x86 daemon binary"
                cp "$X86_DAEMON" "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon.bin"
                chmod a-x "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon.bin"
                stage_runtime_libs "$X86_DAEMON" "$BUNDLE_DIR/lib"
                if binary_requires_runtime_loader "$X86_DAEMON"; then
                    install_portable_runtime_wrapper "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon" "ld-linux-x86-64.so.2"
                else
                    install_passthrough_wrapper "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon"
                fi
            fi
            materialize_library_soname_links "$BUNDLE_DIR/lib"
    else
        die "unsupported remote target arch: ${RUN_TARGET_ARCH}"
    fi
}

bundle_stage_modules() {
    [[ "${RUN_NEEDS_KINSN_MODULES:-0}" == "1" ]] || return 0
    local module_subdir=""
    bundle_copy_tracked_tree "module" "$BUNDLE_DIR"
    case "$RUN_TARGET_ARCH" in
        arm64)
            module_subdir="arm64"
            rm -rf "$BUNDLE_DIR/module/x86" "$BUNDLE_DIR/module/arm64"
            ;;
        x86_64)
            module_subdir="x86"
            rm -rf "$BUNDLE_DIR/module/arm64" "$BUNDLE_DIR/module/x86"
            ;;
        *)
            die "unsupported target arch for bundled modules: ${RUN_TARGET_ARCH}"
            ;;
    esac
    [[ -n "$RUN_KINSN_MODULE_DIR" ]] || die "explicit module input is missing for ${RUN_TARGET_NAME}"
    require_local_path "$RUN_KINSN_MODULE_DIR" "selected kinsn module dir"
    bundle_copy_tree "$RUN_KINSN_MODULE_DIR" "$BUNDLE_DIR/module/$module_subdir"
}

bundle_stage_scx() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    mkdir -p "$BUNDLE_DIR/runner/repos/scx/target/release" "$BUNDLE_DIR/corpus/build/scx"
    IFS=',' read -r -a _run_scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_run_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        if target_arch_is_arm64; then
            [[ -n "$ARM64_SCX_BINARY_ROOT" ]] || die "manifest is missing ARM64_SCX_BINARY_ROOT"
            [[ -n "$ARM64_SCX_OBJECT_ROOT" ]] || die "manifest is missing ARM64_SCX_OBJECT_ROOT"
            cp "$ARM64_SCX_BINARY_ROOT/$package" \
                "$BUNDLE_DIR/runner/repos/scx/target/release/$package"
            cp "$ARM64_SCX_OBJECT_ROOT/${package}_main.bpf.o" \
                "$BUNDLE_DIR/corpus/build/scx/${package}_main.bpf.o"
        elif target_arch_is_x86; then
            [[ -n "$X86_SCX_BINARY_ROOT" ]] || die "manifest is missing X86_SCX_BINARY_ROOT"
            [[ -n "$X86_SCX_OBJECT_ROOT" ]] || die "manifest is missing X86_SCX_OBJECT_ROOT"
            cp "$X86_SCX_BINARY_ROOT/$package" \
                "$BUNDLE_DIR/runner/repos/scx/target/release/$package"
            cp "$X86_SCX_OBJECT_ROOT/${package}_main.bpf.o" \
                "$BUNDLE_DIR/corpus/build/scx/${package}_main.bpf.o"
        else
            die "unsupported target arch for scx bundle inputs: ${RUN_TARGET_ARCH}"
        fi
    done
    if target_arch_is_x86; then
        wrap_dynamic_executable_tree "$BUNDLE_DIR/runner/repos/scx/target/release" "ld-linux-x86-64.so.2"
    fi
}

bundle_stage_repo_build_dir() {
    local repo_name="$1"
    local source_dir=""
    if target_arch_is_arm64; then
        [[ -n "$ARM64_NATIVE_BUILD_ROOT" ]] || die "ARM64 native build root is missing"
        source_dir="$ARM64_NATIVE_BUILD_ROOT/$repo_name"
    elif target_arch_is_x86; then
        [[ -n "$X86_NATIVE_BUILD_ROOT" ]] || die "x86 native build root is missing"
        source_dir="$X86_NATIVE_BUILD_ROOT/$repo_name"
    else
        die "unsupported target arch for native repo bundle inputs: ${RUN_TARGET_ARCH}"
    fi
    require_nonempty_dir "$source_dir" "bundled native repo build dir for ${repo_name}"
    mkdir -p "$BUNDLE_DIR/corpus/build/$repo_name"
    cp -a "$source_dir/." "$BUNDLE_DIR/corpus/build/$repo_name/"
    if [[ -d "$BUNDLE_DIR/corpus/build/$repo_name/lib" ]]; then
        materialize_library_soname_links "$BUNDLE_DIR/corpus/build/$repo_name/lib"
    fi
}

bundle_stage_katran_server() {
    [[ "${RUN_NEEDS_KATRAN_BUNDLE:-0}" == "1" ]] || return 0
    mkdir -p "$BUNDLE_DIR/e2e/cases/katran/bin" "$BUNDLE_DIR/e2e/cases/katran/lib"
    if target_arch_is_arm64; then
        [[ -n "$ARM64_KATRAN_SERVER_BINARY" && -n "$ARM64_KATRAN_SERVER_LIB_DIR" ]] \
            || die "bundled ARM64 Katran inputs are missing"
        require_local_path "$ARM64_KATRAN_SERVER_BINARY" "ARM64 Katran server"
        require_local_path "$ARM64_KATRAN_SERVER_LIB_DIR" "ARM64 Katran lib dir"
        cp "$ARM64_KATRAN_SERVER_BINARY" "$BUNDLE_DIR/e2e/cases/katran/bin/katran_server_grpc"
        cp -a "$ARM64_KATRAN_SERVER_LIB_DIR/." "$BUNDLE_DIR/e2e/cases/katran/lib/"
    elif target_arch_is_x86; then
        [[ -n "$X86_KATRAN_SERVER_BINARY" && -n "$X86_KATRAN_SERVER_LIB_DIR" ]] \
            || die "bundled x86 Katran inputs are missing"
        require_local_path "$X86_KATRAN_SERVER_BINARY" "x86 Katran server"
        require_local_path "$X86_KATRAN_SERVER_LIB_DIR" "x86 Katran lib dir"
        cp "$X86_KATRAN_SERVER_BINARY" "$BUNDLE_DIR/e2e/cases/katran/bin/katran_server_grpc"
        cp -a "$X86_KATRAN_SERVER_LIB_DIR/." "$BUNDLE_DIR/e2e/cases/katran/lib/"
        wrap_dynamic_executable_tree "$BUNDLE_DIR/e2e/cases/katran/bin" "ld-linux-x86-64.so.2"
    else
        die "unsupported target arch for Katran bundle inputs: ${RUN_TARGET_ARCH}"
    fi
    materialize_library_soname_links "$BUNDLE_DIR/e2e/cases/katran/lib"
}

bundle_stage_selected_repos() {
    local repo
    [[ -n "${RUN_BUNDLED_REPOS_CSV:-}" ]] || return 0
    [[ -n "$RUN_LOCAL_REPO_ROOT" ]] || die "local repo root is missing"
    mkdir -p "$BUNDLE_DIR/runner/repos"
    IFS=',' read -r -a _run_bundled_repos <<<"$RUN_BUNDLED_REPOS_CSV"
    for repo in "${_run_bundled_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        bundle_copy_git_snapshot "$RUN_LOCAL_REPO_ROOT/$repo" "$BUNDLE_DIR/runner/repos/$repo"
    done
}

bundle_stage_workload_tools() {
    [[ -n "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}" ]] || return 0
    [[ -n "$RUN_LOCAL_WORKLOAD_TOOL_ROOT" ]] || die "manifest is missing local bundled workload tool root"
    require_nonempty_dir "$RUN_LOCAL_WORKLOAD_TOOL_ROOT/bin" "bundled workload tool bin dir"
    mkdir -p "$BUNDLE_DIR/.cache/workload-tools"
    cp -a "$RUN_LOCAL_WORKLOAD_TOOL_ROOT/." "$BUNDLE_DIR/.cache/workload-tools/"
    if target_arch_is_x86; then
        mkdir -p "$BUNDLE_DIR/lib"
        wrap_dynamic_executable_tree "$BUNDLE_DIR/.cache/workload-tools/bin" "ld-linux-x86-64.so.2"
    fi
}

bundle_stage_x86_portable_libbpf() {
    target_arch_is_x86 || return 0
    [[ -n "$X86_PORTABLE_LIBBPF_ROOT" ]] || return 0
    require_nonempty_dir "$X86_PORTABLE_LIBBPF_ROOT/lib" "portable x86 libbpf dir"
    mkdir -p "$BUNDLE_DIR/.cache/portable-libbpf/lib"
    cp -a "$X86_PORTABLE_LIBBPF_ROOT/lib/." "$BUNDLE_DIR/.cache/portable-libbpf/lib/"
}

bundle_stage_native_repo_build_dirs() {
    local repo
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    IFS=',' read -r -a _run_native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    for repo in "${_run_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        bundle_stage_repo_build_dir "$repo"
        if target_arch_is_x86; then
            wrap_dynamic_executable_tree "$BUNDLE_DIR/corpus/build/$repo" "ld-linux-x86-64.so.2"
        fi
    done
}

prepare_common_bundle() {
    rm -rf "$BUNDLE_DIR"
    mkdir -p "$BUNDLE_DIR"
    cp "$MANIFEST_PATH" "$BUNDLE_DIR/run-contract.env"
    printf 'RUN_BUNDLED_WORKLOAD_TOOLS_CSV=%q\n' "${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}" >>"$BUNDLE_DIR/run-contract.env"
    bundle_copy_runner_tree
    bundle_stage_modules
    bundle_stage_target_runtime
    bundle_copy_git_snapshot "$ROOT_DIR/vendor/libbpf" "$BUNDLE_DIR/vendor/libbpf"
    bundle_copy_git_snapshot "$ROOT_DIR/vendor/bpftool" "$BUNDLE_DIR/vendor/bpftool"
    bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "include" "$BUNDLE_DIR/vendor/linux-framework"
    bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "scripts" "$BUNDLE_DIR/vendor/linux-framework"
    bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "arch" "$BUNDLE_DIR/vendor/linux-framework"
}

prepare_test_bundle() {
    bundle_copy_test_runner_tree
    bundle_copy_tracked_tree "tests" "$BUNDLE_DIR"
    if target_arch_is_arm64; then
        if test_mode_needs_unittest; then
            [[ -n "$ARM64_TEST_UNITTEST_BUILD_DIR" ]] || die "bundled ARM64 unittest inputs are missing"
            bundle_copy_tree "$ARM64_TEST_UNITTEST_BUILD_DIR" "$BUNDLE_DIR/tests/unittest/build-arm64"
        fi
        if test_mode_needs_negative; then
            [[ -n "$ARM64_TEST_NEGATIVE_BUILD_DIR" ]] || die "bundled ARM64 negative inputs are missing"
            bundle_copy_tree "$ARM64_TEST_NEGATIVE_BUILD_DIR" "$BUNDLE_DIR/tests/negative/build-arm64"
        fi
        if test_mode_needs_upstream; then
            [[ -n "$ARM64_UPSTREAM_TEST_KMODS_DIR" ]] \
                || die "bundled ARM64 upstream selftest kmods are missing"
            [[ -n "$ARM64_UPSTREAM_SELFTEST_DIR" ]] \
                || die "bundled ARM64 upstream selftest inputs are missing"
            bundle_copy_tree "$ARM64_UPSTREAM_SELFTEST_DIR" "$BUNDLE_DIR/.cache/upstream-bpf-selftests"
            mkdir -p "$BUNDLE_DIR/upstream-selftests-kmods"
            cp "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.ko "$BUNDLE_DIR/upstream-selftests-kmods/"
        fi
    else
        if test_mode_needs_unittest; then
            [[ -n "$X86_TEST_UNITTEST_BUILD_DIR" ]] || die "bundled x86 unittest inputs are missing"
            bundle_copy_tree "$X86_TEST_UNITTEST_BUILD_DIR" "$BUNDLE_DIR/tests/unittest/build"
            wrap_dynamic_executable_tree "$BUNDLE_DIR/tests/unittest/build" "ld-linux-x86-64.so.2"
        fi
        if test_mode_needs_negative; then
            [[ -n "$X86_TEST_NEGATIVE_BUILD_DIR" ]] || die "bundled x86 negative inputs are missing"
            bundle_copy_tree "$X86_TEST_NEGATIVE_BUILD_DIR" "$BUNDLE_DIR/tests/negative/build"
            wrap_dynamic_executable_tree "$BUNDLE_DIR/tests/negative/build" "ld-linux-x86-64.so.2"
        fi
        if test_mode_needs_upstream; then
            [[ -n "$X86_UPSTREAM_SELFTEST_DIR" ]] || die "bundled x86 upstream selftest inputs are missing"
            require_local_path "$X86_UPSTREAM_SELFTEST_DIR" "x86 upstream selftest dir"
            bundle_copy_tree "$X86_UPSTREAM_SELFTEST_DIR" "$BUNDLE_DIR/.cache/upstream-bpf-selftests"
            wrap_dynamic_executable_tree "$BUNDLE_DIR/.cache/upstream-bpf-selftests" "ld-linux-x86-64.so.2"
        fi
    fi
    if test_mode_needs_upstream; then
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/build" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/bpf" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/include" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/lib" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/scripts" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "tools/testing" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "kernel/bpf/disasm.c" "$BUNDLE_DIR/vendor/linux-framework"
        bundle_copy_repo_tracked_tree "$ROOT_DIR/vendor/linux-framework" "kernel/bpf/disasm.h" "$BUNDLE_DIR/vendor/linux-framework"
    fi
    bundle_stage_scx
}

prepare_micro_bundle() {
    local generated_dir="${MICRO_PROGRAMS_GENERATED_DIR:-}"
    bundle_copy_tracked_tree "micro" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/micro/results"
    [[ -n "$generated_dir" ]] || die "explicit micro generated programs dir is missing"
    require_nonempty_dir "$generated_dir" "micro generated programs dir"
    mkdir -p "$BUNDLE_DIR/micro/programs"
    while IFS= read -r -d '' generated_file; do
        cp -a "$generated_file" "$BUNDLE_DIR/micro/programs/$(basename "$generated_file")"
    done < <(
        find "$generated_dir" -maxdepth 1 -type f \
            \( -name '*.bpf.o' -o -name '*.directive.bin' -o -name '*.policy.bin' -o -name '.build.stamp' \) \
            -print0
    )
}

prepare_corpus_bundle() {
    bundle_copy_tracked_tree "corpus" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "e2e/cases" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/corpus/results" "$BUNDLE_DIR/corpus/build"
    mkdir -p "$BUNDLE_DIR/corpus/build"
    bundle_stage_workload_tools
    bundle_stage_x86_portable_libbpf
    bundle_stage_selected_repos
    bundle_stage_scx
    bundle_stage_native_repo_build_dirs
    bundle_stage_katran_server
}

prepare_e2e_bundle() {
    bundle_copy_tracked_tree "e2e" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/e2e/results"
    bundle_copy_tracked_tree "corpus/config" "$BUNDLE_DIR"
    mkdir -p "$BUNDLE_DIR/corpus/build"
    bundle_stage_workload_tools
    bundle_stage_x86_portable_libbpf
    bundle_stage_selected_repos
    bundle_stage_scx
    bundle_stage_native_repo_build_dirs
    bundle_stage_katran_server
}

prepare_common_bundle
case "$RUN_SUITE_NAME" in
    test) prepare_test_bundle ;;
    micro) prepare_micro_bundle ;;
    corpus) prepare_corpus_bundle ;;
    e2e) prepare_e2e_bundle ;;
    *) die "unsupported suite for remote bundle: ${RUN_SUITE_NAME}" ;;
esac

tar -C "$BUNDLE_DIR" -czf "$BUNDLE_TAR" .
