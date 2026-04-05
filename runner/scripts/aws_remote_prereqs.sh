#!/usr/bin/env bash
set -euo pipefail

MANIFEST_PATH="${1:?usage: aws_remote_prereqs.sh <manifest>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-remote-prereqs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

STAMP_PATH="${AWS_REMOTE_PREREQS_STAMP:-/var/tmp/bpf-benchmark/prereqs.ready}"

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

python_import_for_package() {
    case "$1" in
        PyYAML) printf '%s\n' yaml ;;
        pyelftools) printf '%s\n' elftools ;;
        *) die "unsupported python package contract: $1" ;;
    esac
}

dnf_install() {
    sudo dnf -y install "$@"
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
    case "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" in
        python3.11)
            printf '%s\n' python3.11 python3.11-pip
            ;;
        python3)
            printf '%s\n' python3 python3-pip
            ;;
        *)
            die "unsupported remote python contract: ${RUN_REMOTE_PYTHON_BIN}"
            ;;
    esac
}

bpftool_runtime_packages() {
    case "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}" in
        bpftool)
            printf '%s\n' bpftool
            ;;
        *)
            die "unsupported remote bpftool contract: ${RUN_BPFTOOL_BIN}"
            ;;
    esac
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
    local tool_csv="${RUN_WORKLOAD_TOOLS_CSV:-}"
    local tool
    [[ -n "$tool_csv" ]] || return 0
    IFS=',' read -r -a _run_workload_tools <<<"$tool_csv"
    for tool in "${_run_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        case "$tool" in
            wrk)
                dnf_install wrk
                ;;
            sysbench)
                dnf_install sysbench
                ;;
            hackbench)
                dnf_install rt-tests
                ;;
            stress-ng|fio|bpftrace)
                dnf_install "$tool"
                ;;
            *)
                die "unsupported workload tool in manifest: ${tool}"
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
    local required_gb="${AWS_REMOTE_SWAP_SIZE_GB:-8}"
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
        import_name="$(python_import_for_package "$package_name")"
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
    IFS=',' read -r -a _run_remote_required <<<"${RUN_REMOTE_COMMANDS_CSV:-}"
    for command_name in "${_run_remote_required[@]}"; do
        [[ -n "$command_name" ]] || continue
        require_cmd "$command_name"
    done
}

main() {
    install_base_packages
    install_explicit_runtime_packages
    install_optional_tool_packages
    install_python_modules
    ensure_swap
    verify_environment
    sudo mkdir -p "$(dirname "$STAMP_PATH")"
    sudo touch "$STAMP_PATH"
}

main "$@"
