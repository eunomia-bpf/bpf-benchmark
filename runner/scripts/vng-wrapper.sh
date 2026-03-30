#!/bin/bash
# Wrapper around vng that provides a PTY via script(1) when needed.
# vng requires /proc/self/fd/{0,1,2} to be O_RDWR (i.e., a real PTY).

set -euo pipefail

_self="$(realpath "$0")"
_repo_root="$(cd "$(dirname "$_self")/../.." && pwd)"
_repo_kernel_dir="$_repo_root/vendor/linux-framework"
_repo_kernel_image="$_repo_kernel_dir/arch/x86/boot/bzImage"

ensure_repo_modules_fresh() {
    local kernel_arg=""
    local args=("$@")
    local idx=0
    while [ "$idx" -lt "${#args[@]}" ]; do
        if [ "${args[$idx]}" = "--run" ]; then
            idx=$((idx + 1))
            if [ "$idx" -lt "${#args[@]}" ]; then
                kernel_arg="${args[$idx]}"
            fi
            break
        fi
        idx=$((idx + 1))
    done
    if [ -z "$kernel_arg" ]; then
        return 0
    fi

    local kernel_real
    kernel_real="$(realpath "$kernel_arg" 2>/dev/null || true)"
    if [ "$kernel_real" != "$_repo_kernel_image" ]; then
        return 0
    fi

    local hostfs_modules=(
        "$_repo_kernel_dir/drivers/block/null_blk/null_blk.ko"
        "$_repo_kernel_dir/drivers/net/veth.ko"
        "$_repo_kernel_dir/net/ipv4/ip_tunnel.ko"
        "$_repo_kernel_dir/net/ipv4/tunnel4.ko"
        "$_repo_kernel_dir/net/ipv4/ipip.ko"
        "$_repo_kernel_dir/net/sched/sch_netem.ko"
        "$_repo_kernel_dir/fs/netfs/netfs.ko"
        "$_repo_kernel_dir/net/9p/9pnet.ko"
        "$_repo_kernel_dir/net/9p/9pnet_virtio.ko"
        "$_repo_kernel_dir/fs/9p/9p.ko"
        "$_repo_kernel_dir/fs/fuse/virtiofs.ko"
        "$_repo_kernel_dir/fs/overlayfs/overlay.ko"
    )

    local rebuild_hostfs=0 module_path=""
    for module_path in "${hostfs_modules[@]}"; do
        if [ ! -f "$module_path" ] || [ "$module_path" -ot "$_repo_kernel_image" ]; then
            rebuild_hostfs=1
            break
        fi
    done

    local kinsn_dir="$_repo_root/module/x86"
    local rebuild_kinsn=0
    local kinsn_modules=()
    shopt -s nullglob
    kinsn_modules=("$kinsn_dir"/*.ko)
    shopt -u nullglob
    if [ "${#kinsn_modules[@]}" -eq 0 ]; then
        rebuild_kinsn=1
    else
        for module_path in "${kinsn_modules[@]}"; do
            if [ ! -f "$module_path" ] || [ "$module_path" -ot "$_repo_kernel_image" ]; then
                rebuild_kinsn=1
                break
            fi
        done
    fi

    if [ "$rebuild_hostfs" -eq 0 ] && [ "$rebuild_kinsn" -eq 0 ]; then
        return 0
    fi

    if [ "$rebuild_hostfs" -eq 1 ]; then
        echo "vng-wrapper: refreshing repo hostfs modules for $(basename "$_repo_kernel_image")" >&2
        make -C "$_repo_root" virtme-hostfs-modules BZIMAGE="$_repo_kernel_image" >&2
    fi
    if [ "$rebuild_kinsn" -eq 1 ]; then
        echo "vng-wrapper: refreshing repo kinsn modules for $(basename "$_repo_kernel_image")" >&2
        make -C "$_repo_root" kinsn-modules BZIMAGE="$_repo_kernel_image" >&2
    fi
}

# Sentinel: re-invoked under script with args saved in a temp file.
if [ "${__VNG_WRAP:-}" = "1" ]; then
    unset __VNG_WRAP
    mapfile -d '' -t args < "$1"
    rm -f "$1"
    ensure_repo_modules_fresh "${args[@]}"
    if [ "${VNG_WRAPPER_DEBUG:-0}" = "1" ]; then
        printf 'vng-wrapper exec: vng' >&2
        printf ' %q' "${args[@]}" >&2
        printf '\n' >&2
    fi
    vng "${args[@]}"
    _rc=$?
    if [ "${VNG_WRAPPER_DEBUG:-0}" = "1" ]; then
        printf 'vng-wrapper exit: %s\n' "$_rc" >&2
    fi
    exit "$_rc"
fi

# If all three fds are ttys, just run vng directly.
if test -t 0 && test -t 1 && test -t 2; then
    ensure_repo_modules_fresh "$@"
    exec vng "$@"
fi

# Save args as NUL-delimited to a temp file, then re-invoke under script(1).
# Capture the transcript so non-interactive callers still see virtme-ng output.
_tmpargs=$(mktemp /tmp/vng-wrapper.XXXXXX)
_tmplog=$(mktemp /tmp/vng-wrapper-log.XXXXXX)
printf '%s\0' "$@" > "$_tmpargs"
export __VNG_WRAP=1
set +e
script -qfec "$_self $_tmpargs" "$_tmplog"
_rc=$?
set -e
cat "$_tmplog"
rm -f "$_tmplog"
exit "$_rc"
