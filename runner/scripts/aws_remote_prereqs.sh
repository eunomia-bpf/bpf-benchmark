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
WORKLOAD_TOOL_SRC_ROOT="${WORKLOAD_TOOL_ROOT}/src"
WORKLOAD_TOOL_BUILD_ROOT="${WORKLOAD_TOOL_ROOT}/build"
export PATH="${WORKLOAD_TOOL_BIN_DIR}:${PATH}"

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

dnf_has_package() {
    local package="$1"
    sudo dnf -q list --available "$package" >/dev/null 2>&1 \
        || sudo dnf -q list --installed "$package" >/dev/null 2>&1
}

install_workload_build_deps() {
    dnf_install \
        autoconf \
        automake \
        coreutils \
        diffutils \
        gcc \
        gcc-c++ \
        git \
        libaio-devel \
        libtool \
        make \
        numactl-devel \
        openssl-devel \
        perl \
        pkgconfig \
        which
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

workload_build_jobs() {
    nproc 2>/dev/null || echo 1
}

install_hackbench_from_source() {
    local src_root="${WORKLOAD_TOOL_SRC_ROOT}/rt-tests"
    local build_root="${WORKLOAD_TOOL_BUILD_ROOT}/rt-tests"
    local obj_root="${build_root}/obj"
    local jobs
    if [[ -x "${WORKLOAD_TOOL_BIN_DIR}/hackbench" ]]; then
        return 0
    fi
    log "Installing hackbench from source"
    install_workload_build_deps
    sudo rm -rf "$src_root" "$build_root"
    sudo mkdir -p "$WORKLOAD_TOOL_BIN_DIR" "$WORKLOAD_TOOL_SRC_ROOT" "$WORKLOAD_TOOL_BUILD_ROOT"
    sudo git clone --depth 1 https://git.kernel.org/pub/scm/utils/rt-tests/rt-tests.git "$src_root" >/dev/null
    sudo mkdir -p "$build_root"
    jobs="$(workload_build_jobs)"
    sudo make -C "$src_root" OBJDIR="$obj_root" -j"$jobs" hackbench >/dev/null
    [[ -x "${src_root}/hackbench" ]] || die "hackbench source build did not produce ${src_root}/hackbench"
    sudo install -m 0755 "${src_root}/hackbench" "${WORKLOAD_TOOL_BIN_DIR}/hackbench"
}

install_sysbench_from_source() {
    local src_root="${WORKLOAD_TOOL_SRC_ROOT}/sysbench"
    local build_root="${WORKLOAD_TOOL_BUILD_ROOT}/sysbench"
    local jobs
    if [[ -x "${WORKLOAD_TOOL_BIN_DIR}/sysbench" ]]; then
        return 0
    fi
    log "Installing sysbench from source"
    install_workload_build_deps
    sudo rm -rf "$src_root" "$build_root"
    sudo mkdir -p "$WORKLOAD_TOOL_BIN_DIR" "$WORKLOAD_TOOL_SRC_ROOT" "$WORKLOAD_TOOL_BUILD_ROOT"
    sudo git clone --depth 1 https://github.com/akopytov/sysbench.git "$src_root" >/dev/null
    jobs="$(workload_build_jobs)"
    sudo bash -lc "
        set -euo pipefail
        cd '$src_root'
        ./autogen.sh >/dev/null
        ./configure --without-mysql --without-pgsql --prefix='$build_root/install' >/dev/null
        make -j'$jobs' >/dev/null
        make install >/dev/null
    "
    [[ -x "${build_root}/install/bin/sysbench" ]] || die "sysbench source build did not produce ${build_root}/install/bin/sysbench"
    sudo install -m 0755 "${build_root}/install/bin/sysbench" "${WORKLOAD_TOOL_BIN_DIR}/sysbench"
}

install_wrk_from_source() {
    local src_root="${WORKLOAD_TOOL_SRC_ROOT}/wrk"
    local jobs
    if [[ -x "${WORKLOAD_TOOL_BIN_DIR}/wrk" ]]; then
        return 0
    fi
    log "Installing wrk from source"
    install_workload_build_deps
    sudo rm -rf "$src_root"
    sudo mkdir -p "$WORKLOAD_TOOL_BIN_DIR" "$WORKLOAD_TOOL_SRC_ROOT"
    sudo git clone --depth 1 https://github.com/wg/wrk.git "$src_root" >/dev/null
    jobs="$(workload_build_jobs)"
    sudo make -C "$src_root" -j"$jobs" >/dev/null
    [[ -x "${src_root}/wrk" ]] || die "wrk source build did not produce ${src_root}/wrk"
    sudo install -m 0755 "${src_root}/wrk" "${WORKLOAD_TOOL_BIN_DIR}/wrk"
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

    case "$tool" in
        hackbench)
            install_hackbench_from_source
            ;;
        sysbench)
            install_sysbench_from_source
            ;;
        wrk)
            install_wrk_from_source
            ;;
        *)
            die "required tool is unavailable via package manager and has no source-build fallback: ${tool}"
            ;;
    esac
    [[ -x "${WORKLOAD_TOOL_BIN_DIR}/${tool}" ]] || die "workload tool install did not produce command: ${WORKLOAD_TOOL_BIN_DIR}/${tool}"
}

needs_remote_native_upstream_selftests() {
    [[ "${RUN_SUITE_NAME:-}" == "test" && "${RUN_TEST_MODE:-test}" == "test" && "${RUN_UPSTREAM_SELFTEST_EXEC_MODE:-bundled}" == "remote-native" ]]
}

needs_remote_native_runner_build() {
    [[ "${RUN_NEEDS_RUNNER_BINARY:-0}" == "1" && "${RUN_RUNNER_BINARY_MODE:-bundled}" == "remote-native" ]]
}

resolve_llvm_tool() {
    local base="$1"
    local suffix="${RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
    local candidate
    if [[ -n "$suffix" ]]; then
        for candidate in "${base}-${suffix}" "${base}${suffix}"; do
            if command -v "$candidate" >/dev/null 2>&1; then
                printf '%s\n' "$candidate"
                return 0
            fi
        done
    fi
    if command -v "$base" >/dev/null 2>&1; then
        printf '%s\n' "$base"
        return 0
    fi
    die "required LLVM tool is missing: ${base}"
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
    prereq_collect_required_commands required_commands
    for tool in "${required_commands[@]}"; do
        [[ "$tool" == "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}" ]] && continue
        [[ "$tool" == "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" ]] && continue
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
    for tool in "${required_commands[@]}"; do
        [[ "$tool" == "${RUN_BPFTOOL_BIN:?RUN_BPFTOOL_BIN is required}" ]] && continue
        [[ "$tool" == "${RUN_REMOTE_PYTHON_BIN:?RUN_REMOTE_PYTHON_BIN is required}" ]] && continue
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
        case "$tool" in
            wrk|sysbench|hackbench)
                install_workload_tool "$tool"
                ;;
        esac
    done
}

install_upstream_selftest_build_packages() {
    needs_remote_native_upstream_selftests || return 0
    dnf_install \
        clang20 \
        llvm20-devel \
        lld20 \
        gcc \
        gcc-c++ \
        make \
        elfutils-libelf-devel \
        zlib-devel \
        glibc-devel \
        libcap-devel \
        openssl-devel \
        kernel-headers
}

install_runner_build_packages() {
    needs_remote_native_runner_build || return 0
    dnf_install \
        clang20 \
        llvm20-devel \
        lld20 \
        cmake \
        gcc \
        gcc-c++ \
        git \
        make \
        pkgconfig \
        yaml-cpp-devel \
        elfutils-libelf-devel \
        zlib-devel
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
    if needs_remote_native_runner_build; then
        require_any_cmd clang-20 clang20 clang
        require_any_cmd clang++-20 clang++20 clang++
        require_any_cmd llvm-config-20 llvm-config20 llvm-config
        require_cmd cmake
        require_cmd make
        require_cmd git
    fi
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
    local required_commands=()
    prereq_collect_required_commands required_commands
    for command_name in "${required_commands[@]}"; do
        [[ -n "$command_name" ]] || continue
        require_cmd "$command_name"
    done
    if needs_remote_native_upstream_selftests; then
        require_cmd make
        require_cmd gcc
        require_cmd g++
        require_cmd "$(resolve_llvm_tool clang)"
        require_cmd "$(resolve_llvm_tool clang++)"
        require_cmd "$(resolve_llvm_tool ld.lld)"
        require_cmd "$(resolve_llvm_tool llvm-ar)"
        require_cmd "$(resolve_llvm_tool llc)"
        require_cmd "$(resolve_llvm_tool llvm-config)"
        require_cmd "$(resolve_llvm_tool llvm-objcopy)"
        require_cmd "$(resolve_llvm_tool llvm-strip)"
    fi
}

main() {
    install_base_packages
    install_explicit_runtime_packages
    install_optional_tool_packages
    install_workload_tools
    install_upstream_selftest_build_packages
    install_runner_build_packages
    install_python_modules
    ensure_swap
    verify_environment
    sudo mkdir -p "$(dirname "$STAMP_PATH")"
    sudo touch "$STAMP_PATH"
}

main "$@"
