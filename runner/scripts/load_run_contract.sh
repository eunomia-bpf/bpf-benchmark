#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
TARGETS_DIR="$ROOT_DIR/runner/targets"
SUITES_DIR="$ROOT_DIR/runner/suites"

run_contract_die() {
    printf '[run-contract][ERROR] %s\n' "$*" >&2
    exit 1
}

run_contract_require_file() {
    local path="$1"
    [[ -f "$path" ]] || run_contract_die "missing required file: $path"
}

run_contract_normalize_csv() {
    local raw="${1:-}"
    printf '%s\n' "${raw//[[:space:]]/}"
}

run_contract_env_or_default() {
    local env_name="$1"
    local default_value="${2:-}"
    if [[ -n "${!env_name:-}" ]]; then
        printf '%s\n' "${!env_name}"
        return 0
    fi
    printf '%s\n' "$default_value"
}

run_contract_prefixed_env_or_default() {
    local prefix="$1"
    local suffix="$2"
    local default_value="${3:-}"
    run_contract_env_or_default "${prefix}_${suffix}" "$default_value"
}

run_contract_resolve_repo_path() {
    local path="$1"
    if [[ -z "$path" ]]; then
        printf '%s\n' ""
    elif [[ "$path" = /* ]]; then
        printf '%s\n' "$path"
    else
        printf '%s\n' "$ROOT_DIR/$path"
    fi
}

run_contract_resolve_aws_region() {
    local region=""
    region="$(run_contract_env_or_default AWS_REGION "$(run_contract_env_or_default AWS_DEFAULT_REGION "")")"
    if [[ -n "$region" ]]; then
        printf '%s\n' "$region"
        return 0
    fi
    run_contract_die "AWS region is unset. Export AWS_REGION or AWS_DEFAULT_REGION explicitly."
}

run_contract_parse_shell_words() {
    local raw="$1"
    local out_name="$2"
    local -n out_ref="$out_name"
    out_ref=()
    [[ -n "$raw" ]] || return 0
    local token
    while IFS= read -r -d '' token; do
        out_ref+=("$token")
    done < <(
        python3 - "$raw" <<'PY'
import shlex
import sys

for item in shlex.split(sys.argv[1]):
    sys.stdout.buffer.write(item.encode())
    sys.stdout.buffer.write(b"\0")
PY
    )
}

run_contract_write_shell_array() {
    local manifest_path="$1"
    local var_name="$2"
    shift 2
    printf '%s=(' "$var_name" >>"$manifest_path"
    local arg
    for arg in "$@"; do
        printf ' %q' "$arg" >>"$manifest_path"
    done
    printf ' )\n' >>"$manifest_path"
}

run_contract_host_cpu_count() {
    nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1
}

run_contract_resolve_cpu_spec() {
    local spec="${1:-}"
    local host_cpus ratio resolved
    case "$spec" in
        auto:*)
            host_cpus="$(run_contract_host_cpu_count)"
            ratio="${spec#auto:}"
            resolved="$(awk -v cpus="$host_cpus" -v ratio="$ratio" 'BEGIN { value = int(cpus * ratio); if (value < 1) value = 1; print value }')"
            printf '%s\n' "$resolved"
            ;;
        ''|auto)
            printf '%s\n' "$(run_contract_host_cpu_count)"
            ;;
        *)
            printf '%s\n' "$spec"
            ;;
    esac
}

run_contract_load_target() {
    local target_name="$1"
    local target_file="$TARGETS_DIR/${target_name}.env"
    run_contract_require_file "$target_file"
    # shellcheck disable=SC1090
    source "$target_file"
}

run_contract_load_suite() {
    local suite_name="$1"
    local suite_file="$SUITES_DIR/${suite_name}.env"
    run_contract_require_file "$suite_file"
    # shellcheck disable=SC1090
    source "$suite_file"
}

run_contract_csv_has() {
    local csv="$1"
    local token="$2"
    case ",${csv}," in
        *,"${token}",*) return 0 ;;
    esac
    return 1
}

run_contract_append_csv() {
    local csv="$1"
    local token="$2"
    if [[ -z "$token" ]]; then
        printf '%s\n' "$csv"
        return 0
    fi
    if run_contract_csv_has "$csv" "$token"; then
        printf '%s\n' "$csv"
        return 0
    fi
    if [[ -z "$csv" ]]; then
        printf '%s\n' "$token"
    else
        printf '%s,%s\n' "$csv" "$token"
    fi
}

run_contract_append_csv_list() {
    local csv="$1"
    local extra_csv="$2"
    local token
    [[ -n "$extra_csv" ]] || {
        printf '%s\n' "$csv"
        return 0
    }
    IFS=',' read -r -a _run_contract_append_tokens <<<"$extra_csv"
    for token in "${_run_contract_append_tokens[@]}"; do
        [[ -n "$token" ]] || continue
        csv="$(run_contract_append_csv "$csv" "$token")"
    done
    printf '%s\n' "$csv"
}

run_contract_validate_test_mode() {
    local mode="$1"
    case "$mode" in
        selftest|negative|test) ;;
        *) run_contract_die "unsupported test mode: ${mode}" ;;
    esac
}

run_contract_validate_e2e_cases() {
    local cases_csv="$1"
    local token
    [[ -n "$cases_csv" ]] || run_contract_die "e2e cases must not be empty"
    if [[ "$cases_csv" == "all" ]]; then
        return 0
    fi
    IFS=',' read -r -a _run_contract_validate_cases <<<"$cases_csv"
    for token in "${_run_contract_validate_cases[@]}"; do
        case "$token" in
            tracee|tetragon|bpftrace|scx|bcc|katran) ;;
            "") ;;
            *) run_contract_die "unsupported e2e case: ${token}" ;;
        esac
    done
}

run_contract_suite_repos_for_e2e_cases() {
    local cases_csv="$1"
    local repo_csv=""
    local token
    if [[ "$cases_csv" == "all" ]]; then
        printf '%s\n' "tracee,tetragon,bpftrace,scx,bcc,katran"
        return 0
    fi
    IFS=',' read -r -a _run_contract_case_tokens <<<"$cases_csv"
    for token in "${_run_contract_case_tokens[@]}"; do
        [[ -n "$token" ]] || continue
        repo_csv="$(run_contract_append_csv "$repo_csv" "$token")"
    done
    printf '%s\n' "$repo_csv"
}

run_contract_native_repos_for_e2e_cases() {
    local cases_csv="$1"
    local repo_csv=""
    local token
    if [[ "$cases_csv" == "all" ]]; then
        printf '%s\n' "bcc,katran,tracee,tetragon"
        return 0
    fi
    IFS=',' read -r -a _run_contract_native_case_tokens <<<"$cases_csv"
    for token in "${_run_contract_native_case_tokens[@]}"; do
        case "$token" in
            bcc|katran|tracee|tetragon)
                repo_csv="$(run_contract_append_csv "$repo_csv" "$token")"
                ;;
        esac
    done
    printf '%s\n' "$repo_csv"
}

run_contract_write_manifest() {
    local target_name="$1"
    local suite_name="$2"
    local manifest_path="$3"
    local run_name_tag=""
    local run_instance_type=""
    local run_remote_user=""
    local run_remote_stage_dir=""
    local run_remote_kernel_stage_dir=""
    local run_ami_param=""
    local run_ami_id=""
    local run_root_volume_gb=""
    local run_test_mode="test"
    local run_e2e_cases="all"
    local run_benchmark_repos=""
    local run_native_repos=""
    local run_scx_packages=""
    local run_needs_sched_ext=""
    local run_remote_commands=""
    local run_workload_tools=""
    local run_needs_katran_bundle="0"
    local run_needs_llvmbpf="0"
    local run_bpftool_bin="bpftool"
    local run_aws_key_name=""
    local run_aws_key_path=""
    local run_aws_security_group_id=""
    local run_aws_subnet_id=""
    local run_aws_region=""
    local run_aws_profile=""
    local run_bench_samples=""
    local run_bench_warmups=""
    local run_bench_inner_repeat=""
    local run_corpus_filters=""
    local run_corpus_args=""
    local run_corpus_workload_seconds=""
    local run_e2e_args=""
    local run_e2e_smoke=""
    local run_vm_backend=""
    local run_vm_executable=""
    local run_vm_lock_scope=""
    local run_vm_machine_name=""
    local run_vm_machine_arch=""
    local run_vm_cpus=""
    local run_vm_mem=""
    local run_host_python_bin=""
    local run_vm_kernel_image=""
    local run_vm_timeout_seconds=""
    local run_remote_python_bin=""
    local run_test_fuzz_rounds=""
    local run_test_scx_prog_show_race_mode=""
    local run_test_scx_prog_show_race_iterations=""
    local run_test_scx_prog_show_race_load_timeout=""
    local run_test_scx_prog_show_race_skip_probe=""
    local -a run_corpus_argv=()
    local -a run_e2e_argv=()
    local run_suite_entrypoint="runner/scripts/suite_entrypoint.sh"

    run_contract_load_target "$target_name"
    run_contract_load_suite "$suite_name"
    run_needs_sched_ext="${SUITE_NEEDS_SCHED_EXT:-0}"
    run_needs_llvmbpf="${SUITE_NEEDS_LLVMBPF:-0}"
    run_benchmark_repos="${SUITE_DEFAULT_REPOS:-}"
    run_native_repos="${SUITE_DEFAULT_NATIVE_REPOS:-}"
    run_scx_packages="${SUITE_DEFAULT_SCX_PACKAGES:-}"
    run_remote_commands="${SUITE_DEFAULT_REMOTE_COMMANDS:-}"
    run_workload_tools="${SUITE_DEFAULT_WORKLOAD_TOOLS:-}"
    run_needs_katran_bundle="${SUITE_NEEDS_KATRAN_BUNDLE:-0}"
    run_remote_python_bin="${SUITE_DEFAULT_REMOTE_PYTHON_BIN:-}"
    if [[ "${TARGET_EXECUTOR:-}" == "aws-ssh" ]]; then
        local aws_env_prefix="${TARGET_AWS_ENV_PREFIX:-}"
        [[ -n "$aws_env_prefix" ]] || run_contract_die "AWS target ${target_name} is missing TARGET_AWS_ENV_PREFIX"
        run_name_tag="$(run_contract_prefixed_env_or_default "$aws_env_prefix" NAME_TAG "${TARGET_NAME_TAG_DEFAULT:-}")"
        run_instance_type="$(run_contract_prefixed_env_or_default "$aws_env_prefix" INSTANCE_TYPE "${TARGET_INSTANCE_TYPE_DEFAULT:-}")"
        run_remote_user="$(run_contract_prefixed_env_or_default "$aws_env_prefix" REMOTE_USER "${TARGET_REMOTE_USER_DEFAULT:-}")"
        run_remote_stage_dir="$(run_contract_prefixed_env_or_default "$aws_env_prefix" REMOTE_STAGE_DIR "${TARGET_REMOTE_STAGE_DIR_DEFAULT:-}")"
        run_remote_kernel_stage_dir="$(run_contract_prefixed_env_or_default "$aws_env_prefix" REMOTE_KERNEL_STAGE_DIR "${TARGET_REMOTE_KERNEL_STAGE_DIR_DEFAULT:-}")"
        run_ami_param="$(run_contract_prefixed_env_or_default "$aws_env_prefix" AMI_PARAM "${TARGET_AMI_PARAM_DEFAULT:-}")"
        run_ami_id="$(run_contract_prefixed_env_or_default "$aws_env_prefix" AMI_ID)"
        run_root_volume_gb="$(run_contract_prefixed_env_or_default "$aws_env_prefix" ROOT_VOLUME_GB "${TARGET_ROOT_VOLUME_GB_DEFAULT:-}")"
        run_test_mode="$(printf '%s' "$(run_contract_prefixed_env_or_default "$aws_env_prefix" TEST_MODE test)" | tr '[:upper:]' '[:lower:]')"
        run_bench_samples="$(run_contract_prefixed_env_or_default "$aws_env_prefix" BENCH_SAMPLES 1)"
        run_bench_warmups="$(run_contract_prefixed_env_or_default "$aws_env_prefix" BENCH_WARMUPS 0)"
        run_bench_inner_repeat="$(run_contract_prefixed_env_or_default "$aws_env_prefix" BENCH_INNER_REPEAT 10)"
        run_corpus_filters="$(run_contract_normalize_csv "$(run_contract_prefixed_env_or_default "$aws_env_prefix" CORPUS_FILTERS "")")"
        run_corpus_args="$(run_contract_prefixed_env_or_default "$aws_env_prefix" CORPUS_ARGS "")"
        run_corpus_workload_seconds="$(run_contract_prefixed_env_or_default "$aws_env_prefix" CORPUS_WORKLOAD_SECONDS "")"
        run_e2e_cases="$(run_contract_normalize_csv "$(run_contract_prefixed_env_or_default "$aws_env_prefix" E2E_CASES "${SUITE_DEFAULT_E2E_CASES:-all}")")"
        run_e2e_args="$(run_contract_prefixed_env_or_default "$aws_env_prefix" E2E_ARGS "")"
        run_e2e_smoke="$(run_contract_prefixed_env_or_default "$aws_env_prefix" E2E_SMOKE 0)"
        run_aws_key_name="$(run_contract_prefixed_env_or_default "$aws_env_prefix" KEY_NAME)"
        run_aws_key_path="$(run_contract_prefixed_env_or_default "$aws_env_prefix" KEY_PATH)"
        run_aws_security_group_id="$(run_contract_prefixed_env_or_default "$aws_env_prefix" SECURITY_GROUP_ID)"
        run_aws_subnet_id="$(run_contract_prefixed_env_or_default "$aws_env_prefix" SUBNET_ID)"
        run_aws_region="$(run_contract_resolve_aws_region)"
        run_aws_profile="$(run_contract_env_or_default AWS_PROFILE "")"
        [[ -n "$run_aws_profile" ]] || run_contract_die "AWS_PROFILE is required for AWS targets"
    fi

    case "$target_name" in
        aws-arm64|aws-x86)
            ;;
        x86-kvm)
            run_vm_backend="${TARGET_KVM_BACKEND:-}"
            run_vm_executable="${TARGET_KVM_EXECUTABLE:-}"
            run_vm_lock_scope="${TARGET_KVM_LOCK_SCOPE:-}"
            run_vm_machine_name="${TARGET_NAME:-$target_name}"
            run_vm_machine_arch="${TARGET_ARCH:-}"
            run_host_python_bin="$(run_contract_env_or_default PYTHON "${TARGET_KVM_HOST_PYTHON_DEFAULT:-python3}")"
            run_vm_kernel_image="$(run_contract_resolve_repo_path "$(run_contract_env_or_default BZIMAGE "${TARGET_KVM_KERNEL_IMAGE_DEFAULT:-vendor/linux-framework/arch/x86/boot/bzImage}")")"
            [[ -n "$run_vm_backend" ]] || run_contract_die "x86-kvm target is missing TARGET_KVM_BACKEND"
            [[ -n "$run_vm_executable" ]] || run_contract_die "x86-kvm target is missing TARGET_KVM_EXECUTABLE"
            [[ -n "$run_vm_lock_scope" ]] || run_contract_die "x86-kvm target is missing TARGET_KVM_LOCK_SCOPE"
            if [[ "$run_vm_executable" != /* ]]; then
                run_vm_executable="$ROOT_DIR/$run_vm_executable"
            fi
            run_test_mode="${TEST_MODE:-test}"
            run_bench_samples="${SAMPLES:-1}"
            run_bench_warmups="${WARMUPS:-0}"
            run_bench_inner_repeat="${INNER_REPEAT:-10}"
            run_corpus_filters="$(run_contract_normalize_csv "${FILTERS:-}")"
            run_corpus_args="${VM_CORPUS_ARGS:-}"
            run_corpus_workload_seconds="${VM_CORPUS_WORKLOAD_SECONDS:-}"
            run_e2e_cases="$(run_contract_normalize_csv "${E2E_CASE:-all}")"
            run_e2e_args="${E2E_ARGS:-}"
            run_e2e_smoke="${E2E_SMOKE:-0}"
            case "${SUITE_VM_CLASS:-}" in
                test)
                    run_vm_cpus="${VM_CPUS:-$(run_contract_resolve_cpu_spec "${TARGET_KVM_TEST_CPUS_SPEC:-auto:0.8}")}"
                    run_vm_mem="${VM_MEM:-${TARGET_KVM_TEST_MEM:-16G}}"
                    ;;
                benchmark)
                    run_vm_cpus="${VM_CPUS:-$(run_contract_resolve_cpu_spec "${TARGET_KVM_BENCH_CPUS_SPEC:-4}")}"
                    run_vm_mem="${VM_MEM:-${TARGET_KVM_BENCH_MEM:-16G}}"
                    ;;
                "")
                    ;;
                *)
                    run_contract_die "unsupported KVM suite class: ${SUITE_VM_CLASS}"
                    ;;
            esac
            ;;
        *)
            run_contract_die "unsupported target: ${target_name}"
            ;;
    esac

    run_vm_timeout_seconds="${SUITE_DEFAULT_VM_TIMEOUT_SECONDS:-7200}"
    case "$suite_name" in
        test)
            run_vm_timeout_seconds="$(run_contract_env_or_default VM_TEST_TIMEOUT "$run_vm_timeout_seconds")"
            run_test_fuzz_rounds="$(run_contract_env_or_default FUZZ_ROUNDS "${SUITE_DEFAULT_FUZZ_ROUNDS:-1000}")"
            run_test_scx_prog_show_race_mode="$(run_contract_env_or_default SCX_PROG_SHOW_RACE_MODE "${SUITE_DEFAULT_SCX_PROG_SHOW_RACE_MODE:-bpftool-loop}")"
            run_test_scx_prog_show_race_iterations="$(run_contract_env_or_default SCX_PROG_SHOW_RACE_ITERATIONS "${SUITE_DEFAULT_SCX_PROG_SHOW_RACE_ITERATIONS:-20}")"
            run_test_scx_prog_show_race_load_timeout="$(run_contract_env_or_default SCX_PROG_SHOW_RACE_LOAD_TIMEOUT "${SUITE_DEFAULT_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT:-20}")"
            run_test_scx_prog_show_race_skip_probe="$(run_contract_env_or_default SCX_PROG_SHOW_RACE_SKIP_PROBE "${SUITE_DEFAULT_SCX_PROG_SHOW_RACE_SKIP_PROBE:-0}")"
            ;;
        micro)
            run_vm_timeout_seconds="$(run_contract_env_or_default VM_MICRO_TIMEOUT "$run_vm_timeout_seconds")"
            ;;
        corpus)
            run_vm_timeout_seconds="$(run_contract_env_or_default VM_CORPUS_TIMEOUT "$run_vm_timeout_seconds")"
            ;;
        e2e)
            run_vm_timeout_seconds="$(run_contract_env_or_default VM_E2E_TIMEOUT "$run_vm_timeout_seconds")"
            ;;
    esac
    run_contract_validate_test_mode "$run_test_mode"
    [[ -n "$run_remote_python_bin" ]] || run_contract_die "suite ${suite_name} is missing SUITE_DEFAULT_REMOTE_PYTHON_BIN"
    [[ -n "$run_bpftool_bin" ]] || run_contract_die "suite ${suite_name} is missing RUN_BPFTOOL_BIN"
    run_contract_parse_shell_words "$run_corpus_args" run_corpus_argv
    run_contract_parse_shell_words "$run_e2e_args" run_e2e_argv

    case "$suite_name" in
        test)
            run_benchmark_repos=""
            run_native_repos=""
            run_workload_tools=""
            ;;
        micro)
            run_benchmark_repos=""
            run_native_repos=""
            run_scx_packages=""
            run_workload_tools=""
            ;;
        corpus)
            if [[ "$target_name" == "x86-kvm" && -z "${SAMPLES:-}" ]]; then
                run_bench_samples="${VM_CORPUS_SAMPLES:-30}"
            fi
            ;;
        e2e)
            if [[ -z "$run_e2e_cases" ]]; then
                run_e2e_cases="${SUITE_DEFAULT_E2E_CASES}"
            fi
            run_contract_validate_e2e_cases "$run_e2e_cases"
            run_benchmark_repos="$(run_contract_suite_repos_for_e2e_cases "$run_e2e_cases")"
            run_native_repos="$(run_contract_native_repos_for_e2e_cases "$run_e2e_cases")"
            run_scx_packages=""
            if run_contract_csv_has "$run_e2e_cases" "all" || run_contract_csv_has "$run_e2e_cases" "scx"; then
                run_scx_packages="${SUITE_DEFAULT_SCX_PACKAGES}"
                run_needs_sched_ext="1"
                run_workload_tools="$(run_contract_append_csv_list "$run_workload_tools" "${SUITE_E2E_SCX_WORKLOAD_TOOLS:-}")"
            else
                run_needs_sched_ext="0"
            fi
            if run_contract_csv_has "$run_e2e_cases" "all" || run_contract_csv_has "$run_e2e_cases" "tracee"; then
                run_workload_tools="$(run_contract_append_csv_list "$run_workload_tools" "${SUITE_E2E_TRACEE_WORKLOAD_TOOLS:-}")"
            fi
            if run_contract_csv_has "$run_e2e_cases" "all" || run_contract_csv_has "$run_e2e_cases" "bpftrace"; then
                run_workload_tools="$(run_contract_append_csv_list "$run_workload_tools" "${SUITE_E2E_BPFTRACE_WORKLOAD_TOOLS:-}")"
            fi
            if run_contract_csv_has "$run_e2e_cases" "all" || run_contract_csv_has "$run_e2e_cases" "katran"; then
                run_needs_katran_bundle="1"
            fi
            ;;
        *)
            run_contract_die "unsupported suite: ${suite_name}"
            ;;
    esac

    if [[ "${run_needs_sched_ext:-0}" == "1" && "${TARGET_SUPPORTS_SCHED_EXT:-0}" != "1" ]]; then
        run_contract_die "target ${target_name} does not support required sched_ext for suite ${suite_name}"
    fi

    mkdir -p "$(dirname "$manifest_path")"
    cat >"$manifest_path" <<EOF
RUN_TARGET_NAME=$(printf '%q' "$target_name")
RUN_TARGET_ARCH=$(printf '%q' "$TARGET_ARCH")
RUN_EXECUTOR=$(printf '%q' "$TARGET_EXECUTOR")
RUN_SUITE_NAME=$(printf '%q' "$suite_name")
RUN_SUITE_NEEDS_RUNTIME_BTF=$(printf '%q' "${SUITE_NEEDS_RUNTIME_BTF:-0}")
RUN_SUITE_NEEDS_SCHED_EXT=$(printf '%q' "$run_needs_sched_ext")
RUN_SUITE_NEEDS_LLVMBPF=$(printf '%q' "$run_needs_llvmbpf")
RUN_NAME_TAG=$(printf '%q' "$run_name_tag")
RUN_INSTANCE_TYPE=$(printf '%q' "$run_instance_type")
RUN_REMOTE_USER=$(printf '%q' "$run_remote_user")
RUN_REMOTE_STAGE_DIR=$(printf '%q' "$run_remote_stage_dir")
RUN_REMOTE_KERNEL_STAGE_DIR=$(printf '%q' "$run_remote_kernel_stage_dir")
RUN_AMI_PARAM=$(printf '%q' "$run_ami_param")
RUN_AMI_ID=$(printf '%q' "$run_ami_id")
RUN_ROOT_VOLUME_GB=$(printf '%q' "$run_root_volume_gb")
RUN_AWS_KEY_NAME=$(printf '%q' "$run_aws_key_name")
RUN_AWS_KEY_PATH=$(printf '%q' "$run_aws_key_path")
RUN_AWS_SECURITY_GROUP_ID=$(printf '%q' "$run_aws_security_group_id")
RUN_AWS_SUBNET_ID=$(printf '%q' "$run_aws_subnet_id")
RUN_AWS_REGION=$(printf '%q' "$run_aws_region")
RUN_AWS_PROFILE=$(printf '%q' "$run_aws_profile")
RUN_VM_BACKEND=$(printf '%q' "$run_vm_backend")
RUN_VM_EXECUTABLE=$(printf '%q' "$run_vm_executable")
RUN_VM_LOCK_SCOPE=$(printf '%q' "$run_vm_lock_scope")
RUN_VM_MACHINE_NAME=$(printf '%q' "$run_vm_machine_name")
RUN_VM_MACHINE_ARCH=$(printf '%q' "$run_vm_machine_arch")
RUN_VM_CPUS=$(printf '%q' "$run_vm_cpus")
RUN_VM_MEM=$(printf '%q' "$run_vm_mem")
RUN_HOST_PYTHON_BIN=$(printf '%q' "$run_host_python_bin")
RUN_VM_KERNEL_IMAGE=$(printf '%q' "$run_vm_kernel_image")
RUN_VM_TIMEOUT_SECONDS=$(printf '%q' "$run_vm_timeout_seconds")
RUN_REMOTE_PYTHON_BIN=$(printf '%q' "$run_remote_python_bin")
RUN_SUITE_ENTRYPOINT=$(printf '%q' "$run_suite_entrypoint")
RUN_TEST_MODE=$(printf '%q' "$run_test_mode")
RUN_TEST_FUZZ_ROUNDS=$(printf '%q' "$run_test_fuzz_rounds")
RUN_TEST_SCX_PROG_SHOW_RACE_MODE=$(printf '%q' "$run_test_scx_prog_show_race_mode")
RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS=$(printf '%q' "$run_test_scx_prog_show_race_iterations")
RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT=$(printf '%q' "$run_test_scx_prog_show_race_load_timeout")
RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE=$(printf '%q' "$run_test_scx_prog_show_race_skip_probe")
RUN_BENCH_SAMPLES=$(printf '%q' "$run_bench_samples")
RUN_BENCH_WARMUPS=$(printf '%q' "$run_bench_warmups")
RUN_BENCH_INNER_REPEAT=$(printf '%q' "$run_bench_inner_repeat")
RUN_CORPUS_FILTERS=$(printf '%q' "$run_corpus_filters")
RUN_CORPUS_WORKLOAD_SECONDS=$(printf '%q' "$run_corpus_workload_seconds")
RUN_E2E_CASES=$(printf '%q' "$run_e2e_cases")
RUN_E2E_SMOKE=$(printf '%q' "$run_e2e_smoke")
RUN_BENCHMARK_REPOS_CSV=$(printf '%q' "$run_benchmark_repos")
RUN_NATIVE_REPOS_CSV=$(printf '%q' "$run_native_repos")
RUN_SCX_PACKAGES_CSV=$(printf '%q' "$run_scx_packages")
RUN_REMOTE_COMMANDS_CSV=$(printf '%q' "$run_remote_commands")
RUN_WORKLOAD_TOOLS_CSV=$(printf '%q' "$run_workload_tools")
RUN_NEEDS_KATRAN_BUNDLE=$(printf '%q' "$run_needs_katran_bundle")
RUN_BPFTOOL_BIN=$(printf '%q' "$run_bpftool_bin")
EOF
    run_contract_write_shell_array "$manifest_path" RUN_CORPUS_ARGV "${run_corpus_argv[@]}"
    run_contract_write_shell_array "$manifest_path" RUN_E2E_ARGV "${run_e2e_argv[@]}"
}

run_contract_write_target_manifest() {
    local target_name="$1"
    local manifest_path="$2"
    run_contract_load_target "$target_name"
    mkdir -p "$(dirname "$manifest_path")"
    local run_name_tag=""
    local run_aws_region=""
    local run_aws_profile=""
    if [[ "${TARGET_EXECUTOR:-}" == "aws-ssh" ]]; then
        local aws_env_prefix="${TARGET_AWS_ENV_PREFIX:-}"
        [[ -n "$aws_env_prefix" ]] || run_contract_die "AWS target ${target_name} is missing TARGET_AWS_ENV_PREFIX"
        run_name_tag="$(run_contract_prefixed_env_or_default "$aws_env_prefix" NAME_TAG "${TARGET_NAME_TAG_DEFAULT:-}")"
        run_aws_region="$(run_contract_resolve_aws_region)"
        run_aws_profile="$(run_contract_env_or_default AWS_PROFILE "")"
        [[ -n "$run_aws_profile" ]] || run_contract_die "AWS_PROFILE is required for AWS targets"
    fi
    cat >"$manifest_path" <<EOF
RUN_TARGET_NAME=$(printf '%q' "$target_name")
RUN_TARGET_ARCH=$(printf '%q' "$TARGET_ARCH")
RUN_EXECUTOR=$(printf '%q' "$TARGET_EXECUTOR")
RUN_NAME_TAG=$(printf '%q' "$run_name_tag")
RUN_AWS_REGION=$(printf '%q' "$run_aws_region")
RUN_AWS_PROFILE=$(printf '%q' "$run_aws_profile")
EOF
}
