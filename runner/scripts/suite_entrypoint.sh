#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="${1:?usage: suite_entrypoint.sh <workspace> <manifest_path> [archive_path]}"
MANIFEST_PATH="${2:?usage: suite_entrypoint.sh <workspace> <manifest_path> [archive_path]}"
ARCHIVE_PATH="${3:-}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[suite-entrypoint][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

PYTHON_BIN="${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
FUZZ_ROUNDS="${RUN_TEST_FUZZ_ROUNDS:-}"
SCX_PROG_SHOW_RACE_MODE="${RUN_TEST_SCX_PROG_SHOW_RACE_MODE:-}"
SCX_PROG_SHOW_RACE_ITERATIONS="${RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS:-}"
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="${RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT:-}"
SCX_PROG_SHOW_RACE_SKIP_PROBE="${RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE:-}"
RESULT_ROOT="${WORKSPACE}/.cache/suite-results"
RUN_TOKEN="$(date -u +%Y%m%d_%H%M%S)"
ARTIFACT_DIR="${RESULT_ROOT}/${RUN_TARGET_NAME}_${RUN_SUITE_NAME}_${RUN_TOKEN}"

log() {
    printf '[suite-entrypoint] %s\n' "$*" >&2
}

die() {
    printf '[suite-entrypoint][ERROR] %s\n' "$*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "required command is missing: $1"
}

latest_result_dir() {
    local parent="$1"
    local prefix="$2"
    find "$parent" -maxdepth 1 -mindepth 1 -type d -name "${prefix}_*" | sort | tail -n1
}

copy_result_dir() {
    local source_dir="$1"
    local destination_dir="$2"
    [[ -d "$source_dir" ]] || die "result directory is missing: ${source_dir}"
    mkdir -p "$destination_dir"
    cp -a "$source_dir" "$destination_dir/"
}

cross_runtime_ld_library_path() {
    local entries=()
    [[ -d "$WORKSPACE/lib" ]] && entries+=("$WORKSPACE/lib")
    [[ -d "$WORKSPACE/tests/unittest/build-arm64/lib" ]] && entries+=("$WORKSPACE/tests/unittest/build-arm64/lib")
    [[ -d "$WORKSPACE/tests/unittest/build/lib" ]] && entries+=("$WORKSPACE/tests/unittest/build/lib")
    local joined=""
    local entry
    for entry in "${entries[@]}"; do
        if [[ -z "$joined" ]]; then
            joined="$entry"
        else
            joined="${joined}:$entry"
        fi
    done
    printf '%s\n' "$joined"
}

test_unittest_build_dir() {
    if [[ "$RUN_TARGET_ARCH" == "arm64" ]]; then
        printf '%s\n' "$WORKSPACE/tests/unittest/build-arm64"
    else
        printf '%s\n' "$WORKSPACE/tests/unittest/build"
    fi
}

test_negative_build_dir() {
    if [[ "$RUN_TARGET_ARCH" == "arm64" ]]; then
        printf '%s\n' "$WORKSPACE/tests/negative/build-arm64"
    else
        printf '%s\n' "$WORKSPACE/tests/negative/build"
    fi
}

test_kinsn_module_dir() {
    if [[ "$RUN_TARGET_ARCH" == "arm64" ]]; then
        printf '%s\n' "$WORKSPACE/module/arm64"
    else
        printf '%s\n' "$WORKSPACE/module/x86"
    fi
}

resolve_test_daemon() {
    local candidate="$WORKSPACE/daemon/target/release/bpfrejit-daemon"
    [[ -x "$candidate" ]] || die "test daemon is missing from the workspace: $candidate"
    printf '%s\n' "$candidate"
}

ensure_scx_artifacts() {
    local package
    [[ -n "${RUN_SCX_PACKAGES_CSV:-}" ]] || return 0
    IFS=',' read -r -a _run_scx_packages <<<"$RUN_SCX_PACKAGES_CSV"
    for package in "${_run_scx_packages[@]}"; do
        [[ -n "$package" ]] || continue
        [[ -x "$WORKSPACE/runner/repos/scx/target/release/$package" ]] \
            || die "bundled scx binary is missing: $WORKSPACE/runner/repos/scx/target/release/$package"
        [[ -f "$WORKSPACE/corpus/build/scx/${package}_main.bpf.o" ]] \
            || die "bundled scx object is missing: $WORKSPACE/corpus/build/scx/${package}_main.bpf.o"
    done
}

ensure_benchmark_repos() {
    local repo
    [[ -n "${RUN_BENCHMARK_REPOS_CSV:-}" ]] || return 0
    IFS=',' read -r -a _run_benchmark_repos <<<"$RUN_BENCHMARK_REPOS_CSV"
    for repo in "${_run_benchmark_repos[@]}"; do
        [[ -n "$repo" ]] || continue
        [[ -d "$WORKSPACE/runner/repos/$repo" ]] || die "bundled repo is missing: $WORKSPACE/runner/repos/$repo"
    done
}

ensure_katran_bundle() {
    [[ "${RUN_NEEDS_KATRAN_BUNDLE:-0}" == "1" ]] || return 0
    [[ -x "$WORKSPACE/e2e/cases/katran/bin/katran_server_grpc" ]] \
        || die "bundled Katran server is missing"
    [[ -d "$WORKSPACE/e2e/cases/katran/lib" ]] \
        || die "bundled Katran runtime lib dir is missing"
    export KATRAN_SERVER_BINARY="$WORKSPACE/e2e/cases/katran/bin/katran_server_grpc"
    export KATRAN_SERVER_LIB_DIR="$WORKSPACE/e2e/cases/katran/lib"
}

ensure_upstream_selftests() {
    local output_dir="$WORKSPACE/.cache/upstream-bpf-selftests"
    [[ -x "$output_dir/test_verifier" ]] || die "bundled upstream test_verifier is missing: $output_dir/test_verifier"
    [[ -x "$output_dir/test_progs" ]] || die "bundled upstream test_progs is missing: $output_dir/test_progs"
    if [[ -d "$WORKSPACE/upstream-selftests-kmods" ]]; then
        cp "$WORKSPACE/upstream-selftests-kmods"/*.ko "$output_dir"/
    elif [[ "$RUN_TARGET_ARCH" == "arm64" ]]; then
        die "bundled upstream selftest kmods are missing from the workspace"
    fi
}

ensure_workload_tools() {
    local tool
    [[ -n "${RUN_WORKLOAD_TOOLS_CSV:-}" ]] || return 0
    IFS=',' read -r -a _run_workload_tools <<<"$RUN_WORKLOAD_TOOLS_CSV"
    for tool in "${_run_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        require_cmd "$tool"
    done
}

prepare_environment() {
    mkdir -p "$ARTIFACT_DIR"
    cd "$WORKSPACE"
    export PYTHONPATH="$WORKSPACE"
    export BPFTOOL_BIN="${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
    require_cmd "$BPFTOOL_BIN"
    require_cmd "$PYTHON_BIN"
}

validate_test_contract() {
    [[ -n "$FUZZ_ROUNDS" ]] || die "manifest test fuzz rounds is empty"
    [[ -n "$SCX_PROG_SHOW_RACE_MODE" ]] || die "manifest scx_prog_show_race mode is empty"
    [[ -n "$SCX_PROG_SHOW_RACE_ITERATIONS" ]] || die "manifest scx_prog_show_race iterations is empty"
    [[ -n "$SCX_PROG_SHOW_RACE_LOAD_TIMEOUT" ]] || die "manifest scx_prog_show_race load timeout is empty"
    [[ -n "$SCX_PROG_SHOW_RACE_SKIP_PROBE" ]] || die "manifest scx_prog_show_race skip-probe flag is empty"
}

run_selftest_mode() {
    local daemon_path unittest_build negative_build module_dir
    daemon_path="$(resolve_test_daemon)"
    unittest_build="$(test_unittest_build_dir)"
    negative_build="$(test_negative_build_dir)"
    module_dir="$(test_kinsn_module_dir)"
    BPFREJIT_PROGS_DIR="${unittest_build}/progs" \
    BPFREJIT_DAEMON_PATH="$daemon_path" \
        "$WORKSPACE/runner/scripts/vm-selftest.sh" \
        "$WORKSPACE" \
        "$WORKSPACE/tests/unittest" \
        "$module_dir" \
        "$WORKSPACE/tests/negative" \
        "$FUZZ_ROUNDS" \
        "$unittest_build" \
        "$negative_build"
}

run_negative_mode() {
    local negative_build runtime_ld
    negative_build="$(test_negative_build_dir)"
    runtime_ld="$(cross_runtime_ld_library_path)"
    ensure_scx_artifacts
    env LD_LIBRARY_PATH="$runtime_ld" "$negative_build/adversarial_rejit"
    env LD_LIBRARY_PATH="$runtime_ld" "$negative_build/fuzz_rejit" "$FUZZ_ROUNDS"
    env LD_LIBRARY_PATH="$runtime_ld" "$negative_build/scx_prog_show_race" \
        "$WORKSPACE" \
        --mode "${SCX_PROG_SHOW_RACE_MODE}" \
        --iterations "${SCX_PROG_SHOW_RACE_ITERATIONS}" \
        --load-timeout "${SCX_PROG_SHOW_RACE_LOAD_TIMEOUT}" \
        $(if [[ "${SCX_PROG_SHOW_RACE_SKIP_PROBE}" == "1" ]]; then printf '%s' '--skip-probe'; fi)
}

run_full_test_mode() {
    local daemon_path unittest_build negative_build module_dir runtime_ld upstream_bpftool
    daemon_path="$(resolve_test_daemon)"
    unittest_build="$(test_unittest_build_dir)"
    negative_build="$(test_negative_build_dir)"
    module_dir="$(test_kinsn_module_dir)"
    runtime_ld="$(cross_runtime_ld_library_path)"
    ensure_scx_artifacts
    ensure_upstream_selftests
    upstream_bpftool="$WORKSPACE/.cache/upstream-bpf-selftests/tools/sbin/bpftool"
    [[ -x "$upstream_bpftool" ]] || die "upstream selftests bpftool is missing: $upstream_bpftool"
    UNITTEST_BUILD_DIR="$unittest_build" \
    NEGATIVE_BUILD_DIR="$negative_build" \
    NEGATIVE_SKIP_BUILD=1 \
    BPFREJIT_MODULE_DIR="$module_dir" \
    BPFREJIT_DAEMON_PATH="$daemon_path" \
    BPFTOOL_BIN="$upstream_bpftool" \
    CROSS_RUNTIME_LD_LIBRARY_PATH="$runtime_ld" \
    SCX_PROG_SHOW_RACE_MODE="${SCX_PROG_SHOW_RACE_MODE}" \
    SCX_PROG_SHOW_RACE_ITERATIONS="${SCX_PROG_SHOW_RACE_ITERATIONS}" \
    SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="${SCX_PROG_SHOW_RACE_LOAD_TIMEOUT}" \
    SCX_PROG_SHOW_RACE_SKIP_PROBE="${SCX_PROG_SHOW_RACE_SKIP_PROBE}" \
        "$WORKSPACE/runner/scripts/run_all_tests.sh" "$WORKSPACE"
    copy_result_dir "$WORKSPACE/.cache/upstream-bpf-selftests" "$ARTIFACT_DIR"
}

run_test_suite() {
    validate_test_contract
    case "${RUN_TEST_MODE}" in
        selftest) run_selftest_mode ;;
        negative) run_negative_mode ;;
        test) run_full_test_mode ;;
        *) die "unsupported test mode: ${RUN_TEST_MODE}" ;;
    esac
}

run_micro_suite() {
    local runtime_ld output_json cmd=()
    runtime_ld="$(cross_runtime_ld_library_path)"
    output_json="$WORKSPACE/micro/results/${RUN_TARGET_NAME}_micro.json"
    cmd=(
        "$PYTHON_BIN" "$WORKSPACE/micro/driver.py"
        --runtime llvmbpf
        --runtime kernel
        --samples "${RUN_BENCH_SAMPLES:?RUN_BENCH_SAMPLES is required}"
        --warmups "${RUN_BENCH_WARMUPS:?RUN_BENCH_WARMUPS is required}"
        --inner-repeat "${RUN_BENCH_INNER_REPEAT:?RUN_BENCH_INNER_REPEAT is required}"
        --output "$output_json"
    )
    env LD_LIBRARY_PATH="$runtime_ld" "${cmd[@]}"
    copy_result_dir "$(latest_result_dir "$WORKSPACE/micro/results" "${RUN_TARGET_NAME}_micro")" "$ARTIFACT_DIR"
}

run_corpus_suite() {
    local runtime_ld output_json output_md cmd=() filter
    runtime_ld="$(cross_runtime_ld_library_path)"
    ensure_benchmark_repos
    ensure_scx_artifacts
    ensure_katran_bundle
    output_json="$WORKSPACE/corpus/results/${RUN_TARGET_NAME}_corpus.json"
    output_md="$WORKSPACE/corpus/results/${RUN_TARGET_NAME}_corpus.md"
    cmd=(
        "$PYTHON_BIN" "$WORKSPACE/corpus/driver.py"
        --daemon "$WORKSPACE/daemon/target/release/bpfrejit-daemon"
        --samples "${RUN_BENCH_SAMPLES:?RUN_BENCH_SAMPLES is required}"
        --output-json "$output_json"
        --output-md "$output_md"
    )
    if [[ -n "${RUN_CORPUS_WORKLOAD_SECONDS:-}" ]]; then
        cmd+=(--workload-seconds "$RUN_CORPUS_WORKLOAD_SECONDS")
    fi
    IFS=',' read -r -a _run_corpus_filters <<<"${RUN_CORPUS_FILTERS:-}"
    for filter in "${_run_corpus_filters[@]}"; do
        [[ -n "$filter" ]] || continue
        cmd+=(--filter "$filter")
    done
    if (( ${#RUN_CORPUS_ARGV[@]} )); then
        cmd+=("${RUN_CORPUS_ARGV[@]}")
    fi
    env LD_LIBRARY_PATH="$runtime_ld" "${cmd[@]}"
    copy_result_dir "$(latest_result_dir "$WORKSPACE/corpus/results" "${RUN_TARGET_NAME}_corpus")" "$ARTIFACT_DIR"
}

run_e2e_case() {
    local case_name="$1"
    local runtime_ld cmd=()
    runtime_ld="$(cross_runtime_ld_library_path)"
    cmd=(
        "$PYTHON_BIN" "$WORKSPACE/e2e/driver.py"
        "$case_name"
        --daemon "$WORKSPACE/daemon/target/release/bpfrejit-daemon"
    )
    if [[ "${RUN_E2E_SMOKE:?RUN_E2E_SMOKE is required}" == "1" ]]; then
        cmd+=(--smoke)
    fi
    if (( ${#RUN_E2E_ARGV[@]} )); then
        cmd+=("${RUN_E2E_ARGV[@]}")
    fi
    env LD_LIBRARY_PATH="$runtime_ld" "${cmd[@]}"
}

run_e2e_suite() {
    local case_name cases_csv
    ensure_benchmark_repos
    ensure_scx_artifacts
    cases_csv="${RUN_E2E_CASES:?RUN_E2E_CASES is required}"
    if [[ "$cases_csv" == "all" ]]; then
        ensure_katran_bundle
        run_e2e_case all
        for case_name in tracee tetragon bpftrace scx bcc katran; do
            copy_result_dir "$(latest_result_dir "$WORKSPACE/e2e/results" "$case_name")" "$ARTIFACT_DIR"
        done
        return 0
    fi
    IFS=',' read -r -a _run_e2e_cases <<<"$cases_csv"
    for case_name in "${_run_e2e_cases[@]}"; do
        [[ -n "$case_name" ]] || continue
        if [[ "$case_name" == "katran" ]]; then
            ensure_katran_bundle
        fi
        run_e2e_case "$case_name"
        copy_result_dir "$(latest_result_dir "$WORKSPACE/e2e/results" "$case_name")" "$ARTIFACT_DIR"
    done
}

main() {
    prepare_environment
    ensure_workload_tools
    case "${RUN_SUITE_NAME}" in
        test) run_test_suite ;;
        micro) run_micro_suite ;;
        corpus) run_corpus_suite ;;
        e2e) run_e2e_suite ;;
        *) die "unsupported suite: ${RUN_SUITE_NAME}" ;;
    esac
    if [[ -n "$ARCHIVE_PATH" ]]; then
        mkdir -p "$(dirname "$ARCHIVE_PATH")"
        tar -C "$WORKSPACE" -czf "$ARCHIVE_PATH" "${ARTIFACT_DIR#"$WORKSPACE/"}"
    fi
    printf 'ARTIFACT_DIR=%s\n' "${ARTIFACT_DIR#"$WORKSPACE/"}"
}

main "$@"
