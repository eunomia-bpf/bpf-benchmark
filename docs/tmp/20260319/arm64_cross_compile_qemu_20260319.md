# ARM64 Cross-Compile + QEMU Smoke Report

Date: 2026-03-19

## Summary

- Installed ARM64 cross toolchain: `gcc-aarch64-linux-gnu`
- Reused existing host `qemu-system-aarch64` and `vng`
- Generated ARM64 kernel config from `defconfig` plus required BPF/JIT + virtio/9p options
- Built ARM64 kernel image successfully:
  - canonical build output: `vendor/linux-framework/build-arm64/arch/arm64/boot/Image`
  - convenience symlink maintained by `make kernel-arm64`: `vendor/linux-framework/arch/arm64/boot/Image`
  - config symlink maintained by `make kernel-arm64`: `vendor/linux-framework/.config.arm64`
- `vng --arch arm64` can boot the kernel, but cross-arch guest root setup failed before reaching a usable shell
- Raw `qemu-system-aarch64` boot succeeded with a minimal ARM64 Ubuntu rootfs over 9p, and reached `/bin/sh`

## Tooling

- Cross compiler:
  - `aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0`
- QEMU:
  - `/usr/bin/qemu-system-aarch64`
- virtme-ng:
  - `/home/yunwei37/.local/bin/vng`

## ARM64 Kernel Config

Generation flow used:

1. `make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- defconfig`
2. `scripts/config` forced these options on:
   - `CONFIG_BPF=y`
   - `CONFIG_BPF_SYSCALL=y`
   - `CONFIG_BPF_JIT=y`
   - `CONFIG_VIRTIO=y`
   - `CONFIG_VIRTIO_BLK=y`
   - `CONFIG_VIRTIO_NET=y`
   - `CONFIG_NET_9P=y`
   - `CONFIG_9P_FS=y`
   - `CONFIG_NET_9P_VIRTIO=y`
   - `CONFIG_PCI=y`
   - `CONFIG_VIRTIO_PCI=y`
   - `CONFIG_VIRTIO_MMIO=y`
   - `CONFIG_BLK_DEV_INITRD=y`
   - `CONFIG_DEVTMPFS=y`
   - `CONFIG_DEVTMPFS_MOUNT=y`
   - `CONFIG_TMPFS=y`
   - `CONFIG_TMPFS_POSIX_ACL=y`
   - `CONFIG_SERIAL_AMBA_PL011=y`
   - `CONFIG_SERIAL_AMBA_PL011_CONSOLE=y`
3. `make olddefconfig`

Verified in final ARM64 config:

- `CONFIG_BPF=y`
- `CONFIG_HAVE_EBPF_JIT=y`
- `CONFIG_BPF_SYSCALL=y`
- `CONFIG_BPF_JIT=y`
- `CONFIG_VIRTIO_BLK=y`
- `CONFIG_VIRTIO_NET=y`
- `CONFIG_9P_FS=y`
- `CONFIG_NET_9P_VIRTIO=y`

## Build Result

Build command:

```bash
make -C .worktrees/linux-framework-arm64-src \
  O=$PWD/vendor/linux-framework/build-arm64 \
  ARCH=arm64 \
  CROSS_COMPILE=aarch64-linux-gnu- \
  Image -j$(nproc)
```

Artifact:

- `vendor/linux-framework/build-arm64/arch/arm64/boot/Image`
- size: `49M`
- file type: `Linux kernel ARM64 boot executable Image, little-endian, 4K pages`
- sha256:

```text
76799c83689b9e7a7afcf7d09d78ca01d62a00ccd1d1230eb74a6605d9c25e4b
```

## Boot Validation

### Attempt 1: `vng --arch arm64`

Command pattern used:

```bash
vng --run vendor/linux-framework/build-arm64/arch/arm64/boot/Image \
  --arch arm64 \
  --cross-compile aarch64-linux-gnu- \
  --root <arm64-root> \
  --root-release noble \
  # cross-arch TCG-only boot
```

Observed behavior:

- ARM64 kernel booted successfully
- Reached init handoff
- Failed before usable shell because virtme-ng cross-arch guest root handling did not provide a working `/bin/sh`
- Relevant failure:

```text
Kernel panic - not syncing: Requested init /bin/sh failed (error -2).
```

Conclusion:

- `vng` ARM64 boot path is partially functional here
- Not reliable enough for the requested smoke test

### Attempt 2: raw `qemu-system-aarch64`

Prepared rootfs:

```bash
sudo qemu-debootstrap --arch=arm64 --variant=minbase noble \
  /home/yunwei37/.cache/bpf-benchmark/arm64-rootfs \
  http://ports.ubuntu.com/ubuntu-ports
```

Successful boot method:

- machine: `virt`
- cpu: `cortex-a72`
- rootfs: 9p read-only root at `/dev/root`
- init: `/bin/sh`
- console: `ttyAMA0`

Observed successful shell:

```text
Run /bin/sh as init process
/bin/sh: 0: can't access tty; job control turned off
#
```

Smoke commands run inside the ARM64 guest:

```sh
mount -t proc proc /proc
mount -t sysfs sysfs /sys
uname -a
cat /proc/version
cat /proc/sys/net/core/bpf_jit_enable
```

Observed guest output:

```text
Linux (none) 7.0.0-rc2-g53cd48080417 #1 SMP PREEMPT Thu Mar 19 13:05:39 PDT 2026 aarch64 aarch64 aarch64 GNU/Linux
Linux version 7.0.0-rc2-g53cd48080417 (yunwei37@lab) (aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0, GNU ld (GNU Binutils for Ubuntu) 2.42) #1 SMP PREEMPT Thu Mar 19 13:05:39 PDT 2026
1
```

Interpretation:

- Kernel booted successfully under raw QEMU
- Reached shell successfully
- `/proc/sys/net/core/bpf_jit_enable` exists and was `1`, confirming BPF JIT support is active in the booted guest

## Makefile Integration

Added targets:

- `make kernel-arm64`
  - ensures a clean ARM64 worktree
  - regenerates ARM64 config
  - builds `Image`
  - maintains:
    - `vendor/linux-framework/.config.arm64`
    - `vendor/linux-framework/arch/arm64/boot/Image`

- `make vm-arm64-smoke`
  - ensures a reusable ARM64 minbase rootfs under:
    - `/home/yunwei37/.cache/bpf-benchmark/arm64-rootfs`
  - boots the ARM64 kernel with `qemu-system-aarch64`
  - runs:
    - `uname -a`
    - `cat /proc/version`
    - `cat /proc/sys/net/core/bpf_jit_enable`

Implementation note:

- `vm-arm64-smoke` uses `scripts/arm64_qemu_smoke.py` to drive QEMU over stdio and terminate cleanly after the smoke commands complete.

## Notes

- I did not modify any kernel `.c` or `.h` source under `vendor/linux-framework`
- ARM64 build uses a clean auxiliary worktree plus separate output dir to avoid destroying the existing in-tree x86 build artifacts
- I did not attempt to run an additional ARM64 userspace BPF loader inside the guest because the minimal rootfs does not include one; the requested boot + JIT smoke verification succeeded without needing extra guest tooling
