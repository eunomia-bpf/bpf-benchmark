#!/bin/bash
# Generate a generic local ARM64/QEMU kernel config with the repo-required
# BPF/tracing bits plus the basic virtio/9p devices needed by the local VM.
# Usage: arm64-kernel-config.sh <WORKTREE> <BUILD_DIR> <CROSS_COMPILE>
set -eu -o pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# shellcheck source=runner/scripts/arm64_kernel_config_common.sh
source "$SCRIPT_DIR/arm64_kernel_config_common.sh"

WORKTREE="$1"
BUILD_DIR="$2"
CROSS_COMPILE="${3:-aarch64-linux-gnu-}"

mkdir -p "$BUILD_DIR"
make -C "$WORKTREE" O="$BUILD_DIR" ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE" defconfig

arm64_apply_repo_required_config "$WORKTREE" "$BUILD_DIR/.config"
"$WORKTREE/scripts/config" --file "$BUILD_DIR/.config" \
    -e VIRTIO -e VIRTIO_BLK -e VIRTIO_NET \
    -e NET_9P -e 9P_FS -e NET_9P_VIRTIO \
    -e PCI -e VIRTIO_PCI -e VIRTIO_MMIO \
    -e BLK_DEV_INITRD -e DEVTMPFS -e DEVTMPFS_MOUNT \
    -e TMPFS -e TMPFS_POSIX_ACL \
    -e SERIAL_AMBA_PL011 -e SERIAL_AMBA_PL011_CONSOLE

arm64_finalize_kernel_config "$WORKTREE" "$BUILD_DIR" "$CROSS_COMPILE"
