#!/usr/bin/env bash

prereq_contract_die() {
    printf '[prereq-contract][ERROR] %s\n' "$*" >&2
    exit 1
}

prereq_append_unique() {
    local array_name="$1"
    local value="$2"
    local -n array_ref="$array_name"
    local existing
    for existing in "${array_ref[@]:-}"; do
        [[ "$existing" == "$value" ]] && return 0
    done
    array_ref+=("$value")
}

prereq_python_import_for_package() {
    case "$1" in
        PyYAML) printf '%s\n' yaml ;;
        pyelftools) printf '%s\n' elftools ;;
        *) prereq_contract_die "unsupported python package contract: $1" ;;
    esac
}

prereq_collect_commands_for_mode() {
    local -n out_ref="$1"
    local mode="${2:-runtime}"
    local token
    out_ref=()
    prereq_append_unique out_ref "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
    prereq_append_unique out_ref "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    IFS=',' read -r -a _run_remote_required <<<"${RUN_REMOTE_COMMANDS_CSV:-}"
    for token in "${_run_remote_required[@]}"; do
        [[ -n "$token" ]] || continue
        prereq_append_unique out_ref "$token"
    done
    [[ "$mode" == "runtime" ]] || return 0
    IFS=',' read -r -a _run_workload_tools <<<"${RUN_WORKLOAD_TOOLS_CSV:-}"
    for token in "${_run_workload_tools[@]}"; do
        [[ -n "$token" ]] || continue
        prereq_append_unique out_ref "$token"
    done
}

prereq_collect_required_commands() {
    prereq_collect_commands_for_mode "$1" runtime
}

prereq_collect_base_commands() {
    prereq_collect_commands_for_mode "$1" base
}

prereq_map_tool_packages() {
    local manager="$1"
    local tool="$2"
    case "${manager}:${tool}" in
        apt:bpftool) printf '%s\n' bpftool ;;
        dnf:bpftool) printf '%s\n' bpftool ;;
        apt:python3) printf '%s\n' python3 python3-pip ;;
        dnf:python3) printf '%s\n' python3 python3-pip ;;
        apt:python3.11) printf '%s\n' python3.11 python3-pip ;;
        dnf:python3.11) printf '%s\n' python3.11 python3.11-pip ;;
        apt:curl) printf '%s\n' curl ;;
        dnf:curl) printf '%s\n' curl-minimal ;;
        apt:file|dnf:file) printf '%s\n' file ;;
        apt:tar|dnf:tar) printf '%s\n' tar ;;
        apt:taskset|dnf:taskset) printf '%s\n' util-linux ;;
        apt:insmod|dnf:insmod) printf '%s\n' kmod ;;
        apt:ip) printf '%s\n' iproute2 ;;
        dnf:ip) printf '%s\n' iproute ;;
        apt:wrk|dnf:wrk) printf '%s\n' wrk ;;
        apt:sysbench|dnf:sysbench) printf '%s\n' sysbench ;;
        apt:hackbench|dnf:hackbench) printf '%s\n' rt-tests ;;
        apt:stress-ng|dnf:stress-ng) printf '%s\n' stress-ng ;;
        apt:fio|dnf:fio) printf '%s\n' fio ;;
        apt:bpftrace|dnf:bpftrace) printf '%s\n' bpftrace ;;
        *) prereq_contract_die "unsupported tool contract on ${manager}: ${tool}" ;;
    esac
}
