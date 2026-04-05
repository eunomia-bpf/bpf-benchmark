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

dnf_install() {
    sudo dnf -y install "$@"
}

install_base_packages() {
    log "Installing base packages for ${RUN_TARGET_NAME}/${RUN_SUITE_NAME}"
    dnf_install \
        bpftool \
        bpftrace \
        cargo \
        clang20 \
        cmake \
        curl-minimal \
        dracut \
        elfutils-libelf \
        elfutils-libelf-devel \
        file \
        fio \
        gcc \
        gcc-c++ \
        git \
        golang \
        grubby \
        gzip \
        iproute \
        kmod \
        llvm20 \
        llvm20-devel \
        lld20 \
        make \
        ncurses-libs \
        procps-ng \
        python3 \
        python3.11 \
        python3.11-pip \
        stress-ng \
        tar \
        util-linux \
        which \
        zlib \
        zlib-devel \
        zstd
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
                ;;
            *)
                ;;
        esac
    done
}

install_python_modules() {
    sudo python3.11 -m pip install --quiet PyYAML pyelftools >/dev/null
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
    local command_name
    require_cmd bpftool
    require_cmd cargo
    require_any_cmd clang clang-20 clang20
    require_cmd cmake
    require_cmd curl
    require_cmd dracut
    require_cmd file
    require_cmd fio
    require_cmd git
    require_cmd grubby
    require_cmd insmod
    require_cmd ip
    require_any_cmd llc llc-20 llc20
    require_any_cmd llvm-config llvm-config-20 llvm-config20
    require_any_cmd llvm-objcopy llvm-objcopy-20 llvm-objcopy20
    require_any_cmd llvm-strip llvm-strip-20 llvm-strip20
    require_cmd make
    require_cmd python3
    require_cmd python3.11
    require_cmd rustc
    require_cmd stress-ng
    require_cmd taskset
    python3.11 -c 'import yaml, elftools' >/dev/null
    IFS=',' read -r -a _run_remote_required <<<"${RUN_REMOTE_COMMANDS_CSV:-}"
    for command_name in "${_run_remote_required[@]}"; do
        [[ -n "$command_name" ]] || continue
        require_cmd "$command_name"
    done
}

main() {
    install_base_packages
    install_optional_tool_packages
    install_python_modules
    ensure_swap
    verify_environment
    sudo mkdir -p "$(dirname "$STAMP_PATH")"
    sudo touch "$STAMP_PATH"
}

main "$@"
