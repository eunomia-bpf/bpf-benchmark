#!/bin/bash
# Generate ARM64 kernel config with BPF + virtio options enabled.
# Usage: arm64-kernel-config.sh <WORKTREE> <BUILD_DIR> <CROSS_COMPILE>
set -eu -o pipefail

WORKTREE="$1"
BUILD_DIR="$2"
CROSS_COMPILE="${3:-aarch64-linux-gnu-}"

mkdir -p "$BUILD_DIR"
make -C "$WORKTREE" O="$BUILD_DIR" ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE" defconfig

"$WORKTREE/scripts/config" --file "$BUILD_DIR/.config" \
    -e BPF -e BPF_SYSCALL -e BPF_JIT \
    -e VIRTIO -e VIRTIO_BLK -e VIRTIO_NET \
    -e NET_9P -e 9P_FS -e NET_9P_VIRTIO \
    -e PCI -e VIRTIO_PCI -e VIRTIO_MMIO \
    -e BLK_DEV_INITRD -e DEVTMPFS -e DEVTMPFS_MOUNT \
    -e TMPFS -e TMPFS_POSIX_ACL \
    -e SERIAL_AMBA_PL011 -e SERIAL_AMBA_PL011_CONSOLE

make -C "$WORKTREE" O="$BUILD_DIR" ARCH=arm64 CROSS_COMPILE="$CROSS_COMPILE" olddefconfig
