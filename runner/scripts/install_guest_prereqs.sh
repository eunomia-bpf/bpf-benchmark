#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="${1:?usage: install_guest_prereqs.sh <workspace> <manifest_path>}"
MANIFEST_PATH="${2:?usage: install_guest_prereqs.sh <workspace> <manifest_path>}"

[[ -d "$WORKSPACE" ]] || {
    printf '[install-guest-prereqs][ERROR] workspace is missing: %s\n' "$WORKSPACE" >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[install-guest-prereqs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$MANIFEST_PATH"

die() {
    printf '[install-guest-prereqs][ERROR] %s\n' "$*" >&2
    exit 1
}

have_cmd() {
    command -v "$1" >/dev/null 2>&1
}

python_import_for_package() {
    case "$1" in
        PyYAML) printf '%s\n' yaml ;;
        pyelftools) printf '%s\n' elftools ;;
        *) die "unsupported python package contract: $1" ;;
    esac
}

append_unique() {
    local array_name="$1"
    local value="$2"
    local -n array_ref="$array_name"
    local existing
    for existing in "${array_ref[@]:-}"; do
        [[ "$existing" == "$value" ]] && return 0
    done
    array_ref+=("$value")
}

require_sudo() {
    if [[ "${EUID}" -eq 0 ]]; then
        return 0
    fi
    have_cmd sudo || die "guest package installation requires sudo or root"
}

map_package_apt() {
    case "$1" in
        bpftool) printf '%s\n' bpftool ;;
        python3) printf '%s\n' python3 python3-pip ;;
        python3.11) printf '%s\n' python3.11 python3-pip ;;
        curl) printf '%s\n' curl ;;
        file) printf '%s\n' file ;;
        tar) printf '%s\n' tar ;;
        taskset) printf '%s\n' util-linux ;;
        insmod) printf '%s\n' kmod ;;
        ip) printf '%s\n' iproute2 ;;
        wrk) printf '%s\n' wrk ;;
        sysbench) printf '%s\n' sysbench ;;
        hackbench) printf '%s\n' rt-tests ;;
        stress-ng) printf '%s\n' stress-ng ;;
        fio) printf '%s\n' fio ;;
        bpftrace) printf '%s\n' bpftrace ;;
        *) die "unsupported guest command/tool contract on apt guest: $1" ;;
    esac
}

map_package_dnf() {
    case "$1" in
        bpftool) printf '%s\n' bpftool ;;
        python3) printf '%s\n' python3 python3-pip ;;
        python3.11) printf '%s\n' python3.11 python3.11-pip ;;
        curl) printf '%s\n' curl-minimal ;;
        file) printf '%s\n' file ;;
        tar) printf '%s\n' tar ;;
        taskset) printf '%s\n' util-linux ;;
        insmod) printf '%s\n' kmod ;;
        ip) printf '%s\n' iproute ;;
        wrk) printf '%s\n' wrk ;;
        sysbench) printf '%s\n' sysbench ;;
        hackbench) printf '%s\n' rt-tests ;;
        stress-ng) printf '%s\n' stress-ng ;;
        fio) printf '%s\n' fio ;;
        bpftrace) printf '%s\n' bpftrace ;;
        *) die "unsupported guest command/tool contract on dnf guest: $1" ;;
    esac
}

collect_required_commands() {
    local -n out_ref="$1"
    local token
    out_ref=()
    append_unique out_ref "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
    append_unique out_ref "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    IFS=',' read -r -a _run_remote_required <<<"${RUN_REMOTE_COMMANDS_CSV:-}"
    for token in "${_run_remote_required[@]}"; do
        [[ -n "$token" ]] || continue
        append_unique out_ref "$token"
    done
    IFS=',' read -r -a _run_workload_tools <<<"${RUN_WORKLOAD_TOOLS_CSV:-}"
    for token in "${_run_workload_tools[@]}"; do
        [[ -n "$token" ]] || continue
        append_unique out_ref "$token"
    done
}

install_python_modules() {
    local package_csv="${RUN_REMOTE_PYTHON_MODULES_CSV:-}"
    local package_name
    [[ -n "$package_csv" ]] || return 0
    IFS=',' read -r -a _run_python_packages <<<"$package_csv"
    [[ "${#_run_python_packages[@]}" -gt 0 ]] || return 0
    if [[ "${EUID}" -eq 0 ]]; then
        "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" -m pip install --quiet "${_run_python_packages[@]}"
    else
        sudo "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" -m pip install --quiet "${_run_python_packages[@]}"
    fi
}

main() {
    local required_commands=() missing_commands=() packages=() command_name package_name pkg_manager=""
    cd "$WORKSPACE"
    collect_required_commands required_commands
    for command_name in "${required_commands[@]}"; do
        have_cmd "$command_name" || missing_commands+=("$command_name")
    done

    if [[ -n "${RUN_REMOTE_PYTHON_MODULES_CSV:-}" ]]; then
        append_unique missing_commands "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    fi
    if [[ "${#missing_commands[@]}" -eq 0 && -z "${RUN_REMOTE_PYTHON_MODULES_CSV:-}" ]]; then
        return 0
    fi

    require_sudo
    pkg_manager="${RUN_GUEST_PACKAGE_MANAGER:?RUN_GUEST_PACKAGE_MANAGER is required for guest provisioning}"
    case "$pkg_manager" in
        apt|dnf) ;;
        *) die "unsupported guest package manager contract: ${pkg_manager}" ;;
    esac

    for command_name in "${missing_commands[@]}"; do
        if [[ "$pkg_manager" == "apt" ]]; then
            while IFS= read -r package_name; do
                [[ -n "$package_name" ]] || continue
                append_unique packages "$package_name"
            done < <(map_package_apt "$command_name")
        else
            while IFS= read -r package_name; do
                [[ -n "$package_name" ]] || continue
                append_unique packages "$package_name"
            done < <(map_package_dnf "$command_name")
        fi
    done

    if [[ "${#packages[@]}" -gt 0 ]]; then
        if [[ "$pkg_manager" == "apt" ]]; then
            if [[ "${EUID}" -eq 0 ]]; then
                apt-get update
                DEBIAN_FRONTEND=noninteractive apt-get install -y "${packages[@]}"
            else
                sudo apt-get update
                sudo env DEBIAN_FRONTEND=noninteractive apt-get install -y "${packages[@]}"
            fi
        else
            if [[ "${EUID}" -eq 0 ]]; then
                dnf -y install "${packages[@]}"
            else
                sudo dnf -y install "${packages[@]}"
            fi
        fi
    fi
    install_python_modules
}

main "$@"
