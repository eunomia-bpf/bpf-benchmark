#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
SYSROOT_SSH_PORT="${ARM64_SYSROOT_SSH_PORT:-22}"
SYSROOT_FINGERPRINT_FILE="$SYSROOT_ROOT/.package-fingerprint"
SYSROOT_SOURCE_FILE="$SYSROOT_ROOT/.source"

readonly REQUIRED_PATHS=(
    "$SYSROOT_ROOT/usr/lib/ld-linux-aarch64.so.1"
    "$SYSROOT_ROOT/usr/lib64/libc.so.6"
    "$SYSROOT_ROOT/usr/lib64/libm.so.6"
    "$SYSROOT_ROOT/usr/lib64/libpthread.so.0"
    "$SYSROOT_ROOT/lib64/libgcc_s.so.1"
    "$SYSROOT_ROOT/usr/include/libelf.h"
    "$SYSROOT_ROOT/usr/include/llvm/IR/LLVMContext.h"
    "$SYSROOT_ROOT/usr/include/yaml-cpp/yaml.h"
    "$SYSROOT_ROOT/usr/include/zlib.h"
    "$SYSROOT_ROOT/usr/include/zstd.h"
    "$SYSROOT_ROOT/usr/lib64/libelf.so"
    "$SYSROOT_ROOT/usr/lib64/libelf.so.1"
    "$SYSROOT_ROOT/usr/lib64/libLLVM-15.so"
    "$SYSROOT_ROOT/usr/lib64/libyaml-cpp.so"
    "$SYSROOT_ROOT/usr/lib64/libyaml-cpp.so.0.6"
    "$SYSROOT_ROOT/usr/lib64/libz.so"
    "$SYSROOT_ROOT/usr/lib64/libz.so.1"
    "$SYSROOT_ROOT/usr/lib64/libzstd.so"
    "$SYSROOT_ROOT/usr/lib64/libzstd.so.1"
    "$SYSROOT_ROOT/usr/lib64/libcrypto.so.3"
    "$SYSROOT_ROOT/usr/lib64/cmake/llvm/LLVMConfig.cmake"
    "$SYSROOT_ROOT/usr/lib64/pkgconfig/libelf.pc"
    "$SYSROOT_ROOT/usr/lib64/pkgconfig/yaml-cpp.pc"
    "$SYSROOT_ROOT/usr/lib64/pkgconfig/zlib.pc"
    "$SYSROOT_ROOT/usr/lib64/pkgconfig/libzstd.pc"
)

readonly REQUIRED_REMOTE_PACKAGES=(
    glibc
    glibc-devel
    elfutils-libelf
    libgcc
    libstdc++
    libstdc++-devel
    elfutils-libelf-devel
    llvm-libs
    llvm-devel
    yaml-cpp
    yaml-cpp-devel
    zlib
    zlib-devel
    libzstd
    libzstd-devel
    openssl-libs
    openssl-devel
)

log() {
    printf '[arm64-sysroot] %s\n' "$*" >&2
}

die() {
    printf '[arm64-sysroot][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

ssh_base_args() {
    local -a args
    args=(-o BatchMode=yes -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -p "$SYSROOT_SSH_PORT")
    if [[ -n "$SYSROOT_SSH_KEY_PATH" ]]; then
        args+=(-i "$SYSROOT_SSH_KEY_PATH")
    fi
    printf '%q ' "${args[@]}"
}

remote_exec() {
    local script="$1"
    ssh $(ssh_base_args) "${SYSROOT_REMOTE_USER}@${SYSROOT_REMOTE_HOST}" "bash -seuo pipefail" <<<"$script"
}

have_sysroot() {
    local required
    [[ -f "$SYSROOT_FINGERPRINT_FILE" ]] || return 1
    [[ -f "$SYSROOT_SOURCE_FILE" ]] || return 1
    for required in "${REQUIRED_PATHS[@]}"; do
        [[ -e "$required" ]] || return 1
    done
    return 0
}

require_remote_contract() {
    [[ -n "$SYSROOT_REMOTE_HOST" ]] || die "ARM64_SYSROOT_REMOTE_HOST is required to populate the ARM64 sysroot"
    [[ -n "$SYSROOT_REMOTE_USER" ]] || die "ARM64_SYSROOT_REMOTE_USER is required to populate the ARM64 sysroot"
    [[ -n "$SYSROOT_SSH_KEY_PATH" ]] || die "ARM64_SYSROOT_SSH_KEY_PATH is required to populate the ARM64 sysroot"
    [[ -f "$SYSROOT_SSH_KEY_PATH" ]] || die "missing ARM64 sysroot SSH key: ${SYSROOT_SSH_KEY_PATH}"
}

remote_package_fingerprint() {
    local package_list
    package_list="$(printf "'%s' " "${REQUIRED_REMOTE_PACKAGES[@]}")"
    remote_exec "
packages=(${package_list})
rpm -q \"\${packages[@]}\"
"
}

ensure_remote_packages_installed() {
    local package_list
    package_list="$(printf "'%s' " "${REQUIRED_REMOTE_PACKAGES[@]}")"
    remote_exec "
packages=(${package_list})
missing=()
for pkg in \"\${packages[@]}\"; do
    rpm -q \"\$pkg\" >/dev/null 2>&1 || missing+=(\"\$pkg\")
done
if (( \${#missing[@]} )); then
    sudo dnf -y install \"\${missing[@]}\" >/dev/null
fi
"
}

populate_sysroot_from_remote() {
    local tmp_root remote_file_list_script remote_tar_script remote_packages_serialized fingerprint
    tmp_root="${SYSROOT_ROOT}.tmp"
    rm -rf "$tmp_root"
    mkdir -p "$tmp_root"
    remote_packages_serialized="$(printf "'%s' " "${REQUIRED_REMOTE_PACKAGES[@]}")"

    remote_file_list_script="
packages=(${remote_packages_serialized})
rpm -ql \"\${packages[@]}\" |
    while IFS= read -r path; do
        [[ -n \"\$path\" ]] || continue
        [[ -e \"\$path\" ]] || continue
        [[ -d \"\$path\" ]] && continue
        case \"\$path\" in
            /usr/include/*|/usr/lib/*|/usr/lib64/*|/lib64/*)
                printf '%s\\n' \"\$path\"
                ;;
        esac
    done |
    sort -u
"
    remote_tar_script="
packages=(${remote_packages_serialized})
rpm -ql \"\${packages[@]}\" |
    while IFS= read -r path; do
        [[ -n \"\$path\" ]] || continue
        [[ -e \"\$path\" ]] || continue
        [[ -d \"\$path\" ]] && continue
        case \"\$path\" in
            /usr/include/*|/usr/lib/*|/usr/lib64/*|/lib64/*)
                printf '%s\\0' \"\$path\"
                ;;
        esac
    done |
    sort -zu |
    tar --null -T - -chf -
"

    log "Syncing repo-local ARM64 sysroot from ${SYSROOT_REMOTE_USER}@${SYSROOT_REMOTE_HOST}"
    remote_exec "$remote_file_list_script" >/dev/null
    ssh $(ssh_base_args) "${SYSROOT_REMOTE_USER}@${SYSROOT_REMOTE_HOST}" "bash -seuo pipefail" <<<"$remote_tar_script" | tar -xf - -C "$tmp_root"
    mkdir -p "$tmp_root/lib" "$tmp_root/lib64"
    [[ -e "$tmp_root/lib/ld-linux-aarch64.so.1" ]] || ln -s ../usr/lib/ld-linux-aarch64.so.1 "$tmp_root/lib/ld-linux-aarch64.so.1"
    [[ -e "$tmp_root/lib64/libc.so.6" ]] || ln -s ../usr/lib64/libc.so.6 "$tmp_root/lib64/libc.so.6"
    [[ -e "$tmp_root/lib64/libm.so.6" ]] || ln -s ../usr/lib64/libm.so.6 "$tmp_root/lib64/libm.so.6"
    [[ -e "$tmp_root/lib64/libpthread.so.0" ]] || ln -s ../usr/lib64/libpthread.so.0 "$tmp_root/lib64/libpthread.so.0"
    [[ -e "$tmp_root/lib64/librt.so.1" ]] || ln -s ../usr/lib64/librt.so.1 "$tmp_root/lib64/librt.so.1"
    [[ -e "$tmp_root/lib64/libdl.so.2" ]] || ln -s ../usr/lib64/libdl.so.2 "$tmp_root/lib64/libdl.so.2"
    [[ -e "$tmp_root/lib64/libresolv.so.2" ]] || ln -s ../usr/lib64/libresolv.so.2 "$tmp_root/lib64/libresolv.so.2"
    [[ -e "$tmp_root/lib64/libutil.so.1" ]] || ln -s ../usr/lib64/libutil.so.1 "$tmp_root/lib64/libutil.so.1"

    fingerprint="$(remote_package_fingerprint)"
    printf '%s\n' "$fingerprint" >"$tmp_root/.package-fingerprint"
    printf '%s@%s\n' "$SYSROOT_REMOTE_USER" "$SYSROOT_REMOTE_HOST" >"$tmp_root/.source"

    rm -rf "$SYSROOT_ROOT"
    mv "$tmp_root" "$SYSROOT_ROOT"
}

ensure_sysroot_current() {
    local remote_fingerprint
    if have_sysroot; then
        require_remote_contract
        ensure_remote_packages_installed
        remote_fingerprint="$(remote_package_fingerprint)"
        if [[ "$(cat "$SYSROOT_FINGERPRINT_FILE")" == "$remote_fingerprint" ]]; then
            return 0
        fi
        log "Refreshing ARM64 sysroot because remote package fingerprint changed"
    else
        require_remote_contract
        ensure_remote_packages_installed
        log "Preparing repo-local ARM64 sysroot under $SYSROOT_ROOT"
    fi
    populate_sysroot_from_remote
    have_sysroot || die "failed to populate required ARM64 sysroot paths under ${SYSROOT_ROOT}"
}

require_command ssh
require_command tar

mkdir -p "$(dirname "$SYSROOT_LOCK_FILE")"
{
    flock 9
    ensure_sysroot_current
} 9>"$SYSROOT_LOCK_FILE"

printf '%s\n' "$SYSROOT_ROOT"
