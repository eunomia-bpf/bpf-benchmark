#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
MANIFEST_PATH="${1:?usage: build_remote_bundle.sh <manifest_path> <bundle_dir> <bundle_tar>}"
BUNDLE_DIR="${2:?usage: build_remote_bundle.sh <manifest_path> <bundle_dir> <bundle_tar>}"
BUNDLE_TAR="${3:?usage: build_remote_bundle.sh <manifest_path> <bundle_dir> <bundle_tar>}"

[[ -f "$MANIFEST_PATH" ]] || {
    printf '[build-remote-bundle][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

ARM64_CROSSBUILD_OUTPUT_DIR="${ARM64_CROSSBUILD_OUTPUT_DIR:-}"
ARM64_CROSS_RUNNER="${ARM64_CROSS_RUNNER:-}"
ARM64_CROSS_RUNNER_REAL="${ARM64_CROSS_RUNNER_REAL:-}"
ARM64_CROSS_DAEMON="${ARM64_CROSS_DAEMON:-}"
ARM64_CROSS_DAEMON_REAL="${ARM64_CROSS_DAEMON_REAL:-}"
ARM64_CROSS_LIB_DIR="${ARM64_CROSS_LIB_DIR:-}"
ARM64_KATRAN_SERVER_BINARY="${ARM64_KATRAN_SERVER_BINARY:-}"
ARM64_KATRAN_SERVER_LIB_DIR="${ARM64_KATRAN_SERVER_LIB_DIR:-}"
ARM64_TEST_ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-}"
ARM64_TEST_UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-}"
ARM64_TEST_NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-}"
ARM64_UPSTREAM_SELFTEST_DIR="${ARM64_UPSTREAM_SELFTEST_DIR:-}"
ARM64_UPSTREAM_TEST_KMODS_DIR="${ARM64_UPSTREAM_TEST_KMODS_DIR:-}"
X86_RUNNER="${X86_RUNNER:-}"
X86_DAEMON="${X86_DAEMON:-}"
X86_UPSTREAM_SELFTEST_DIR="${X86_UPSTREAM_SELFTEST_DIR:-}"
RUNNER_REPOS_ROOT_OVERRIDE="${RUNNER_REPOS_ROOT_OVERRIDE:-}"
BUNDLE_PROMOTE_ROOT="${BUNDLE_PROMOTE_ROOT:-}"

die() {
    printf '[build-remote-bundle][ERROR] %s\n' "$*" >&2
    exit 1
}

if [[ -n "${RUN_INPUT_STAGE_ROOT:-}" && "$BUNDLE_DIR" != "$RUN_INPUT_STAGE_ROOT" ]]; then
    die "bundle dir does not match manifest RUN_INPUT_STAGE_ROOT: ${BUNDLE_DIR} != ${RUN_INPUT_STAGE_ROOT}"
fi
if [[ -n "${RUN_BUNDLE_TAR:-}" && "$BUNDLE_TAR" != "$RUN_BUNDLE_TAR" ]]; then
    die "bundle tar does not match manifest RUN_BUNDLE_TAR: ${BUNDLE_TAR} != ${RUN_BUNDLE_TAR}"
fi

require_local_path() {
    local path="$1"
    local description="$2"
    [[ -e "$path" ]] || die "${description} not found: ${path}"
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

bundle_copy_git_snapshot() {
    local src="$1"
    local dest="$2"
    local rel_path
    git -C "$src" rev-parse --is-inside-work-tree >/dev/null 2>&1 \
        || die "expected git checkout for bundled repo snapshot: ${src}"
    mkdir -p "$dest"
    while IFS= read -r -d '' rel_path; do
        mkdir -p "$dest/$(dirname "$rel_path")"
        cp -a "$src/$rel_path" "$dest/$rel_path"
    done < <(git -C "$src" ls-files -z --recurse-submodules)
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

stage_runtime_libs() {
    local binary="$1"
    local dest_dir="$2"
    local ldd_output ldd_status dep
    mkdir -p "$dest_dir"
    set +e
    ldd_output="$(ldd "$binary" 2>&1)"
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
    local real_binary="${wrapper_path}.bin"
    cat >"$wrapper_path" <<EOF
#!/usr/bin/env bash
set -euo pipefail
script_path="\$(readlink -f "\$0")"
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
case_lib_dir="\$script_dir/../lib"
bundle_lib_path="\$bundle_root/lib"
if [[ -d "\$case_lib_dir" ]]; then
    bundle_lib_path="\$case_lib_dir:\$bundle_lib_path"
fi
exec "\$bundle_root/lib/${loader_name}" --library-path "\$bundle_lib_path\${LD_LIBRARY_PATH:+:\$LD_LIBRARY_PATH}" "${real_binary}" "\$@"
EOF
    chmod +x "$wrapper_path"
}

install_passthrough_wrapper() {
    local wrapper_path="$1"
    local real_binary="${wrapper_path}.bin"
    cat >"$wrapper_path" <<EOF
#!/usr/bin/env bash
set -euo pipefail
script_path="\$(readlink -f "\$0")"
exec "${real_binary}" "\$@"
EOF
    chmod +x "$wrapper_path"
}

bundle_copy_runner_tree() {
    local dest_root="$1"
    mkdir -p "$dest_root"
    bundle_copy_tracked_tree "runner/__init__.py" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/repos.yaml" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/libs" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/suite_entrypoint.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/run_all_tests.sh" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "runner/scripts/vm-selftest.sh" "$BUNDLE_DIR"
    rm -rf \
        "$dest_root/__pycache__" \
        "$dest_root/scripts/__pycache__" \
        "$dest_root/libs/__pycache__" \
        "$dest_root/libs/app_runners/__pycache__"
}

bundle_stage_target_runtime() {
    mkdir -p "$BUNDLE_DIR/runner/build" "$BUNDLE_DIR/daemon/build" "$BUNDLE_DIR/daemon/target/release" "$BUNDLE_DIR/lib"
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            [[ -n "$ARM64_CROSS_RUNNER" && -n "$ARM64_CROSS_RUNNER_REAL" && -n "$ARM64_CROSS_DAEMON" && -n "$ARM64_CROSS_DAEMON_REAL" && -n "$ARM64_CROSS_LIB_DIR" ]] \
                || die "manifest is missing explicit ARM64 runtime inputs"
            require_local_path "$ARM64_CROSS_RUNNER" "ARM64 runner wrapper"
            require_local_path "$ARM64_CROSS_RUNNER_REAL" "ARM64 runner binary"
            require_local_path "$ARM64_CROSS_DAEMON" "ARM64 daemon wrapper"
            require_local_path "$ARM64_CROSS_DAEMON_REAL" "ARM64 daemon binary"
            require_local_path "$ARM64_CROSS_LIB_DIR" "ARM64 runtime lib dir"
            cp "$ARM64_CROSS_RUNNER" "$BUNDLE_DIR/runner/build/micro_exec"
            cp "$ARM64_CROSS_RUNNER_REAL" "$BUNDLE_DIR/runner/build/micro_exec.real"
            cp "$ARM64_CROSS_DAEMON" "$BUNDLE_DIR/daemon/build/bpfrejit-daemon"
            cp "$ARM64_CROSS_DAEMON_REAL" "$BUNDLE_DIR/daemon/build/bpfrejit-daemon.real"
            cp "$ARM64_CROSS_DAEMON_REAL" "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon"
            cp -a "$ARM64_CROSS_LIB_DIR/." "$BUNDLE_DIR/lib/"
            materialize_library_soname_links "$BUNDLE_DIR/lib"
            ;;
        aws-x86)
            [[ -n "$X86_RUNNER" && -n "$X86_DAEMON" ]] || die "manifest is missing explicit x86 runtime inputs"
            require_local_path "$X86_RUNNER" "x86 runner binary"
            require_local_path "$X86_DAEMON" "x86 daemon binary"
            cp "$X86_RUNNER" "$BUNDLE_DIR/runner/build/micro_exec.bin"
            cp "$X86_DAEMON" "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon.bin"
            stage_runtime_libs "$X86_RUNNER" "$BUNDLE_DIR/lib"
            stage_runtime_libs "$X86_DAEMON" "$BUNDLE_DIR/lib"
            if binary_requires_runtime_loader "$X86_RUNNER"; then
                install_portable_runtime_wrapper "$BUNDLE_DIR/runner/build/micro_exec" "ld-linux-x86-64.so.2"
            else
                install_passthrough_wrapper "$BUNDLE_DIR/runner/build/micro_exec"
            fi
            if binary_requires_runtime_loader "$X86_DAEMON"; then
                install_portable_runtime_wrapper "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon" "ld-linux-x86-64.so.2"
            else
                install_passthrough_wrapper "$BUNDLE_DIR/daemon/target/release/bpfrejit-daemon"
            fi
            materialize_library_soname_links "$BUNDLE_DIR/lib"
            ;;
        *)
            die "unsupported remote target: ${RUN_TARGET_NAME}"
            ;;
    esac
}

bundle_stage_modules() {
    bundle_copy_tree "$ROOT_DIR/module" "$BUNDLE_DIR/module"
    case "$RUN_TARGET_ARCH" in
        arm64)
            rm -rf "$BUNDLE_DIR/module/x86"
            ;;
        x86_64)
            rm -rf "$BUNDLE_DIR/module/arm64"
            ;;
    esac
}

bundle_stage_scx() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    mkdir -p "$BUNDLE_DIR/runner/repos/scx/target/release" "$BUNDLE_DIR/corpus/build/scx"
    IFS=',' read -r -a _run_scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_run_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        case "$RUN_TARGET_NAME" in
            aws-arm64)
                [[ -n "$ARM64_CROSSBUILD_OUTPUT_DIR" ]] || die "manifest is missing ARM64_CROSSBUILD_OUTPUT_DIR"
                cp "$ARM64_CROSSBUILD_OUTPUT_DIR/runner/repos/scx/target/release/$package" \
                    "$BUNDLE_DIR/runner/repos/scx/target/release/$package"
                cp "$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/scx/${package}_main.bpf.o" \
                    "$BUNDLE_DIR/corpus/build/scx/${package}_main.bpf.o"
                ;;
            aws-x86)
                [[ -n "$RUNNER_REPOS_ROOT_OVERRIDE" && -n "$BUNDLE_PROMOTE_ROOT" ]] \
                    || die "manifest is missing explicit x86 scx inputs"
                cp "$RUNNER_REPOS_ROOT_OVERRIDE/scx/target/release/$package" \
                    "$BUNDLE_DIR/runner/repos/scx/target/release/$package"
                cp "$BUNDLE_PROMOTE_ROOT/corpus/build/scx/${package}_main.bpf.o" \
                    "$BUNDLE_DIR/corpus/build/scx/${package}_main.bpf.o"
                ;;
        esac
    done
}

bundle_stage_repo_build_dir() {
    local repo_name="$1"
    local source_dir=""
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            [[ -n "$ARM64_CROSSBUILD_OUTPUT_DIR" ]] || die "manifest is missing ARM64_CROSSBUILD_OUTPUT_DIR"
            source_dir="$ARM64_CROSSBUILD_OUTPUT_DIR/corpus/build/$repo_name"
            ;;
        aws-x86)
            [[ -n "$BUNDLE_PROMOTE_ROOT" ]] || die "manifest is missing BUNDLE_PROMOTE_ROOT"
            source_dir="$BUNDLE_PROMOTE_ROOT/corpus/build/$repo_name"
            ;;
    esac
    require_local_path "$source_dir" "bundled native repo build dir for ${repo_name}"
    mkdir -p "$BUNDLE_DIR/corpus/build/$repo_name"
    cp -a "$source_dir/." "$BUNDLE_DIR/corpus/build/$repo_name/"
}

bundle_stage_katran_server() {
    [[ "${RUN_NEEDS_KATRAN_BUNDLE:-0}" == "1" ]] || return 0
    mkdir -p "$BUNDLE_DIR/e2e/cases/katran/bin" "$BUNDLE_DIR/e2e/cases/katran/lib"
    case "$RUN_TARGET_NAME" in
        aws-arm64)
            [[ -n "$ARM64_KATRAN_SERVER_BINARY" && -n "$ARM64_KATRAN_SERVER_LIB_DIR" ]] \
                || die "manifest is missing explicit ARM64 Katran inputs"
            require_local_path "$ARM64_KATRAN_SERVER_BINARY" "ARM64 Katran server"
            require_local_path "$ARM64_KATRAN_SERVER_LIB_DIR" "ARM64 Katran lib dir"
            cp "$ARM64_KATRAN_SERVER_BINARY" "$BUNDLE_DIR/e2e/cases/katran/bin/katran_server_grpc"
            cp -a "$ARM64_KATRAN_SERVER_LIB_DIR/." "$BUNDLE_DIR/e2e/cases/katran/lib/"
            ;;
        aws-x86)
            [[ -n "$BUNDLE_PROMOTE_ROOT" ]] || die "manifest is missing BUNDLE_PROMOTE_ROOT"
            require_local_path "$BUNDLE_PROMOTE_ROOT/corpus/build/katran/bin/katran_server_grpc" "x86 Katran server"
            require_local_path "$BUNDLE_PROMOTE_ROOT/corpus/build/katran/lib" "x86 Katran lib dir"
            cp "$BUNDLE_PROMOTE_ROOT/corpus/build/katran/bin/katran_server_grpc" "$BUNDLE_DIR/e2e/cases/katran/bin/katran_server_grpc"
            cp -a "$BUNDLE_PROMOTE_ROOT/corpus/build/katran/lib/." "$BUNDLE_DIR/e2e/cases/katran/lib/"
            ;;
    esac
    materialize_library_soname_links "$BUNDLE_DIR/e2e/cases/katran/lib"
}

bundle_stage_selected_repos() {
    local repo
    [[ -n "${RUN_BENCHMARK_REPOS_CSV:-}" ]] || return 0
    [[ -n "$RUNNER_REPOS_ROOT_OVERRIDE" ]] || die "manifest is missing RUNNER_REPOS_ROOT_OVERRIDE"
    mkdir -p "$BUNDLE_DIR/runner/repos"
    IFS=',' read -r -a _run_benchmark_repos <<<"$RUN_BENCHMARK_REPOS_CSV"
    for repo in "${_run_benchmark_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        bundle_copy_git_snapshot "$RUNNER_REPOS_ROOT_OVERRIDE/$repo" "$BUNDLE_DIR/runner/repos/$repo"
    done
}

bundle_stage_native_repo_build_dirs() {
    local repo
    [[ -n "${RUN_NATIVE_REPOS_CSV:-}" ]] || return 0
    IFS=',' read -r -a _run_native_repos <<<"$RUN_NATIVE_REPOS_CSV"
    for repo in "${_run_native_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        bundle_stage_repo_build_dir "$repo"
    done
}

prepare_common_bundle() {
    rm -rf "$BUNDLE_DIR"
    mkdir -p "$BUNDLE_DIR"
    cp "$MANIFEST_PATH" "$BUNDLE_DIR/run-contract.env"
    bundle_copy_runner_tree "$BUNDLE_DIR/runner"
    bundle_stage_modules
    bundle_stage_target_runtime
    bundle_copy_tracked_tree "vendor/libbpf" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/bpftool" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/include" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/scripts" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/arch" "$BUNDLE_DIR"
}

prepare_test_bundle() {
    bundle_copy_tracked_tree "tests" "$BUNDLE_DIR"
    if [[ "$RUN_TARGET_NAME" == "aws-arm64" ]]; then
        [[ -n "$ARM64_TEST_UNITTEST_BUILD_DIR" && -n "$ARM64_TEST_NEGATIVE_BUILD_DIR" && -n "$ARM64_UPSTREAM_SELFTEST_DIR" && -n "$ARM64_UPSTREAM_TEST_KMODS_DIR" ]] \
            || die "manifest is missing explicit ARM64 test artifact inputs"
        bundle_copy_tree "$ARM64_TEST_UNITTEST_BUILD_DIR" "$BUNDLE_DIR/tests/unittest/build-arm64"
        bundle_copy_tree "$ARM64_TEST_NEGATIVE_BUILD_DIR" "$BUNDLE_DIR/tests/negative/build-arm64"
        bundle_copy_tree "$ARM64_UPSTREAM_SELFTEST_DIR" "$BUNDLE_DIR/.cache/upstream-bpf-selftests"
        mkdir -p "$BUNDLE_DIR/upstream-selftests-kmods"
        cp "$ARM64_UPSTREAM_TEST_KMODS_DIR"/*.ko "$BUNDLE_DIR/upstream-selftests-kmods/"
    else
        [[ -n "$X86_UPSTREAM_SELFTEST_DIR" ]] || die "manifest is missing explicit x86 upstream selftest dir"
        bundle_copy_tree "$ROOT_DIR/tests/unittest/build" "$BUNDLE_DIR/tests/unittest/build"
        bundle_copy_tree "$ROOT_DIR/tests/negative/build" "$BUNDLE_DIR/tests/negative/build"
        if [[ -d "$X86_UPSTREAM_SELFTEST_DIR" ]]; then
        bundle_copy_tree "$X86_UPSTREAM_SELFTEST_DIR" "$BUNDLE_DIR/.cache/upstream-bpf-selftests"
        fi
    fi
    bundle_copy_tracked_tree "vendor/linux-framework/tools/build" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/tools/bpf" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/tools/include" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/tools/lib" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/tools/scripts" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/tools/testing" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/kernel/bpf/disasm.c" "$BUNDLE_DIR"
    bundle_copy_tracked_tree "vendor/linux-framework/kernel/bpf/disasm.h" "$BUNDLE_DIR"
    bundle_stage_scx
}

prepare_benchmark_bundle() {
    bundle_copy_tracked_tree "micro" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/micro/results"
    bundle_copy_tracked_tree "corpus" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/corpus/results" "$BUNDLE_DIR/corpus/build"
    mkdir -p "$BUNDLE_DIR/corpus/build"
    bundle_copy_tracked_tree "e2e" "$BUNDLE_DIR"
    rm -rf "$BUNDLE_DIR/e2e/results"
    bundle_stage_selected_repos
    bundle_stage_scx
    bundle_stage_native_repo_build_dirs
    bundle_stage_katran_server
}

prepare_common_bundle
case "$RUN_SUITE_NAME" in
    test) prepare_test_bundle ;;
    micro|corpus|e2e) prepare_benchmark_bundle ;;
    *) die "unsupported suite for remote bundle: ${RUN_SUITE_NAME}" ;;
esac

tar -C "$BUNDLE_DIR" -czf "$BUNDLE_TAR" .
