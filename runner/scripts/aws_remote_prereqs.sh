#!/usr/bin/env bash
set -euo pipefail

MANIFEST_PATH="${1:?usage: aws_remote_prereqs.sh <manifest>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-remote-prereqs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"
source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/prereq_contract.sh"

MANIFEST_DIR="$(cd "$(dirname "$MANIFEST_PATH")" && pwd)"
STAMP_PATH="${AWS_REMOTE_PREREQS_STAMP:-${MANIFEST_DIR}/prereqs.ready}"
WORKLOAD_TOOL_ROOT="${RUN_REMOTE_WORKLOAD_TOOL_ROOT:-${MANIFEST_DIR}/workload-tools}"
WORKLOAD_TOOL_BIN_DIR="${RUN_REMOTE_WORKLOAD_TOOL_BIN:-${WORKLOAD_TOOL_ROOT}/bin}"
PREREQ_MODE="${AWS_REMOTE_PREREQS_MODE:-runtime}"
export PATH="${WORKLOAD_TOOL_BIN_DIR}:${PATH}"

case "$PREREQ_MODE" in
    base|runtime) ;;
    *)
        printf '[aws-remote-prereqs][ERROR] unsupported AWS_REMOTE_PREREQS_MODE: %s\n' "$PREREQ_MODE" >&2
        exit 1
        ;;
esac

log() {
    printf '[aws-remote-prereqs] %s\n' "$*" >&2
}

die() {
    printf '[aws-remote-prereqs][ERROR] %s\n' "$*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "required command is missing: $1"
}

require_any_cmd() {
    local candidate
    for candidate in "$@"; do
        [[ -n "$candidate" ]] || continue
        if command -v "$candidate" >/dev/null 2>&1; then
            return 0
        fi
    done
    die "required command is missing: $*"
}

workload_tool_is_bundled() {
    local tool="$1"
    case ",${RUN_BUNDLED_WORKLOAD_TOOLS_CSV:-}," in
        *,"${tool}",*) return 0 ;;
    esac
    return 1
}

dnf_install() {
    sudo dnf -y install "$@"
}

dnf_has_package() {
    local package="$1"
    sudo dnf -q list --available "$package" >/dev/null 2>&1 \
        || sudo dnf -q list --installed "$package" >/dev/null 2>&1
}

ensure_workload_tool_bin_dir() {
    sudo mkdir -p "$WORKLOAD_TOOL_BIN_DIR"
}

stage_system_tool_into_run() {
    local tool="$1"
    local tool_path
    tool_path="$(command -v "$tool" 2>/dev/null || true)"
    [[ -n "$tool_path" ]] || die "required system tool is missing after install: ${tool}"
    ensure_workload_tool_bin_dir
    sudo ln -sfn "$tool_path" "${WORKLOAD_TOOL_BIN_DIR}/${tool}"
}

install_workload_tool() {
    local tool="$1"
    local -a packages=()
    local package

    [[ -x "${WORKLOAD_TOOL_BIN_DIR}/${tool}" ]] && return 0

    while IFS= read -r package; do
        [[ -n "$package" ]] || continue
        packages+=("$package")
    done < <(prereq_map_tool_packages dnf "$tool")

    if (( ${#packages[@]} > 0 )); then
        local all_available=1
        for package in "${packages[@]}"; do
            if ! dnf_has_package "$package"; then
                all_available=0
                break
            fi
        done
        if (( all_available )); then
            dnf_install "${packages[@]}"
            if command -v "$tool" >/dev/null 2>&1; then
                stage_system_tool_into_run "$tool"
                [[ -x "${WORKLOAD_TOOL_BIN_DIR}/${tool}" ]] && return 0
            fi
        fi
    fi
    die "required workload tool must be bundled during local prep or available via package manager: ${tool}"
}

install_base_packages() {
    log "Installing execution prerequisites for ${RUN_TARGET_NAME}/${RUN_SUITE_NAME}"
    dnf_install \
        curl-minimal \
        dracut \
        elfutils-libelf \
        file \
        grubby \
        gzip \
        iproute \
        kmod \
        ncurses-libs \
        procps-ng \
        tar \
        util-linux \
        which \
        zlib \
        zstd
}

python_runtime_packages() {
    prereq_map_tool_packages dnf "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
}

bpftool_runtime_packages() {
    prereq_map_tool_packages dnf "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
}

install_explicit_runtime_packages() {
    local -a packages=()
    while IFS= read -r package; do
        [[ -n "$package" ]] || continue
        packages+=("$package")
    done < <(bpftool_runtime_packages)
    while IFS= read -r package; do
        [[ -n "$package" ]] || continue
        packages+=("$package")
    done < <(python_runtime_packages)
    dnf_install "${packages[@]}"
}

install_optional_tool_packages() {
    local required_commands=() tool package packages=()
    if [[ "$PREREQ_MODE" == "runtime" ]]; then
        prereq_collect_required_commands required_commands
    else
        prereq_collect_base_commands required_commands
    fi
    for tool in "${required_commands[@]}"; do
        [[ "$tool" == "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}" ]] && continue
        [[ "$tool" == "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" ]] && continue
        workload_tool_is_bundled "$tool" && continue
        case "$tool" in
            wrk|sysbench|hackbench)
                continue
                ;;
        esac
        while IFS= read -r package; do
            [[ -n "$package" ]] || continue
            prereq_append_unique packages "$package"
        done < <(prereq_map_tool_packages dnf "$tool")
    done
    [[ "${#packages[@]}" -gt 0 ]] || return 0
    dnf_install "${packages[@]}"
    [[ "$PREREQ_MODE" == "runtime" ]] || return 0
    for tool in "${required_commands[@]}"; do
        [[ "$tool" == "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}" ]] && continue
        [[ "$tool" == "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" ]] && continue
        workload_tool_is_bundled "$tool" && continue
        case "$tool" in
            wrk|sysbench|hackbench)
                continue
                ;;
        esac
        command -v "$tool" >/dev/null 2>&1 || continue
        stage_system_tool_into_run "$tool"
    done
}

install_workload_tools() {
    local required_commands=() tool
    prereq_collect_required_commands required_commands
    for tool in "${required_commands[@]}"; do
        workload_tool_is_bundled "$tool" && continue
        case "$tool" in
            wrk|sysbench|hackbench)
                install_workload_tool "$tool"
                ;;
        esac
    done
}

install_python_modules() {
    local package_csv="${RUN_REMOTE_PYTHON_MODULES_CSV:-}"
    [[ -n "$package_csv" ]] || return 0
    IFS=',' read -r -a _run_python_packages <<<"$package_csv"
    [[ "${#_run_python_packages[@]}" -gt 0 ]] || return 0
    sudo "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" -m pip install --quiet "${_run_python_packages[@]}" >/dev/null
}

ensure_swap() {
    local required_gb="${RUN_REMOTE_SWAP_SIZE_GB:-8}"
    local required_bytes current_bytes
    required_bytes=$((required_gb * 1024 * 1024 * 1024))
    current_bytes="$(swapon --show=SIZE --bytes --noheadings 2>/dev/null | awk '{sum += $1} END {print sum + 0}')"
    if [[ "$current_bytes" =~ ^[0-9]+$ ]] && (( current_bytes >= required_bytes )); then
        return 0
    fi
    log "Provisioning ${required_gb}G swap"
    if swapon --show=NAME --noheadings 2>/dev/null | grep -Fx '/swapfile' >/dev/null; then
        sudo swapoff /swapfile
    fi
    sudo rm -f /swapfile
    if ! sudo fallocate -l "${required_gb}G" /swapfile; then
        sudo dd if=/dev/zero of=/swapfile bs=1M count="$((required_gb * 1024))" status=none
    fi
    sudo chmod 600 /swapfile
    sudo mkswap /swapfile >/dev/null
    sudo swapon /swapfile
    sudo sed -i '\|^/swapfile |d' /etc/fstab
    printf '/swapfile swap swap defaults 0 0\n' | sudo tee -a /etc/fstab >/dev/null
}

verify_environment() {
    local command_name package_name imports=() import_name
    require_cmd "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}"
    require_cmd curl
    require_cmd dracut
    require_cmd file
    require_cmd grubby
    require_cmd insmod
    require_cmd ip
    require_cmd "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}"
    require_cmd taskset
    require_cmd tar
    IFS=',' read -r -a _run_python_packages <<<"${RUN_REMOTE_PYTHON_MODULES_CSV:-}"
    for package_name in "${_run_python_packages[@]}"; do
        [[ -n "$package_name" ]] || continue
        import_name="$(prereq_python_import_for_package "$package_name")"
        imports+=("$import_name")
    done
    if (( ${#imports[@]} )); then
        "${RUN_REMOTE_PYTHON_BIN}" - "${imports[@]}" >/dev/null <<'PY'
import importlib
import sys

for module_name in sys.argv[1:]:
    importlib.import_module(module_name)
PY
    fi
    [[ "$PREREQ_MODE" == "runtime" ]] || return 0
    local required_commands=()
    prereq_collect_required_commands required_commands
    for command_name in "${required_commands[@]}"; do
        [[ -n "$command_name" ]] || continue
        workload_tool_is_bundled "$command_name" && continue
        require_cmd "$command_name"
    done
}

main() {
    install_base_packages
    install_explicit_runtime_packages
    install_optional_tool_packages
    if [[ "$PREREQ_MODE" == "runtime" ]]; then
        install_python_modules
        ensure_swap
        install_workload_tools
    fi
    verify_environment
    sudo mkdir -p "$(dirname "$STAMP_PATH")"
    sudo touch "$STAMP_PATH"
}

main "$@"
