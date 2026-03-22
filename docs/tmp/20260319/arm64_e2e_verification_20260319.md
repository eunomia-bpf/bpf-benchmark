# ARM64 E2E Verification

Date: 2026-03-19

## Summary

- Verified the ARM64 cross-build and QEMU smoke flow end-to-end in `/home/yunwei37/workspace/bpf-benchmark`.
- `make kernel-arm64` succeeded, and a forced rebuild with `make -B kernel-arm64` also succeeded after fixing one Makefile bug.
- `make vm-arm64-smoke` booted the rebuilt ARM64 kernel successfully under `qemu-system-aarch64`.
- Guest smoke commands passed:
  - `uname -a`
  - `cat /proc/version`
  - `cat /proc/sys/net/core/bpf_jit_enable`
- Observed `bpf_jit_enable=1` in the ARM64 guest.
- No package installation was needed; required host tooling was already present.

## Host Tooling

- Cross compiler: `aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0`
- QEMU: `QEMU emulator version 8.2.2 (Debian 1:8.2.2+ds-0ubuntu1.13)`
- `qemu-debootstrap` present at `/usr/sbin/qemu-debootstrap`

## What I Ran

Initial target verification:

```bash
make kernel-arm64
make vm-arm64-smoke
```

To ensure this was not just reusing an old artifact, I then forced the build path:

```bash
make -B kernel-arm64
make vm-arm64-smoke
```

## Issue Found And Fixed

### Symptom

The first forced rebuild attempt failed:

```text
*** Configuration file ".config" not found!
```

This happened in the recursive ARM64 kernel `make ... Image` invocation during:

```bash
make -B kernel-arm64
```

### Root Cause

Top-level `make -B` leaked `MAKEFLAGS=B` into the recursive kernel submakes. The out-of-tree ARM64 kernel build did not tolerate that combination during the `Image` phase.

### Fix

Updated the ARM64 recursive kernel invocations in `Makefile` to strip only `B` from `MAKEFLAGS` before calling the nested kernel `make`:

- `defconfig`
- `olddefconfig`
- `Image`

This preserves the normal ARM64 build flow while making `make -B kernel-arm64` work.

## Final Authoritative Build Result

Kernel source/build commit:

```text
cc0f4f6d35021d25dbc0386a6b60489b2d10d57b
```

Artifact:

- Path: `vendor/linux-framework/build-arm64/arch/arm64/boot/Image`
- File type: `Linux kernel ARM64 boot executable Image, little-endian, 4K pages`
- Size: `50481664` bytes
- mtime: `2026-03-19 15:42:26.822250931 -0700`
- sha256:

```text
71d252c202dfc9a38c130037cfc6b51064c683b09f1809f4b7695e4113bbf3e0
```

Verified ARM64 config contains the required options:

- `CONFIG_BPF=y`
- `CONFIG_BPF_SYSCALL=y`
- `CONFIG_BPF_JIT=y`
- `CONFIG_VIRTIO=y`
- `CONFIG_VIRTIO_BLK=y`
- `CONFIG_VIRTIO_NET=y`
- `CONFIG_9P_FS=y`
- `CONFIG_NET_9P_VIRTIO=y`
- `CONFIG_SERIAL_AMBA_PL011=y`
- `CONFIG_SERIAL_AMBA_PL011_CONSOLE=y`

## Final QEMU Smoke Result

Command:

```bash
make vm-arm64-smoke
```

Observed guest kernel version:

```text
Linux version 7.0.0-rc2-gcc0f4f6d3502 (yunwei37@lab) (aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0, GNU ld (GNU Binutils for Ubuntu) 2.42) #3 SMP PREEMPT Thu Mar 19 15:42:19 PDT 2026
```

Observed guest smoke output:

```text
Linux (none) 7.0.0-rc2-gcc0f4f6d3502 #3 SMP PREEMPT Thu Mar 19 15:42:19 PDT 2026 aarch64 aarch64 aarch64 GNU/Linux
Linux version 7.0.0-rc2-gcc0f4f6d3502 (yunwei37@lab) (aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0, GNU ld (GNU Binutils for Ubuntu) 2.42) #3 SMP PREEMPT Thu Mar 19 15:42:19 PDT 2026
1
```

Interpretation:

- ARM64 kernel booted successfully in raw QEMU
- Guest shell became available
- `/proc/sys/net/core/bpf_jit_enable` existed and reported `1`

## Scope Note About Selftests

`make vm-arm64-smoke` is a boot/JIT smoke target only. It does **not** run the existing kernel recompile selftest runner `tests/kernel/build/test_recompile`.

Current repo state:

- x86 selftest path exists: `make vm-selftest`
- ARM64 smoke path exists: `make vm-arm64-smoke`
- No existing ARM64 guest target runs `test_recompile`

So the verified end-to-end result for `#227` is:

- ARM64 cross-compilation works
- ARM64 QEMU boot works
- ARM64 guest JIT smoke works

But this is **not** yet an ARM64 execution of the current kernel selftest suite.

## Follow-Up Attempt Toward ARM64 Selftests

I made one direct attempt to push beyond smoke and cross-build the existing userspace selftest runner for ARM64:

```bash
make -C tests/kernel BUILD_DIR="$PWD/tests/kernel/build-arm64" \
  CC=aarch64-linux-gnu-gcc clean all
```

Result:

- `libbpf.a` cross-built successfully for ARM64
- final ARM64 link of `test_recompile` failed with:

```text
/usr/lib/gcc-cross/aarch64-linux-gnu/13/../../../../aarch64-linux-gnu/bin/ld: cannot find -lelf: No such file or directory
```

I then attempted to install the missing ARM64 development libraries on the host:

```bash
sudo apt-get install -y libelf-dev:arm64 zlib1g-dev:arm64
```

and with additional explicit dependencies:

```bash
sudo apt-get install -y libelf-dev:arm64 zlib1g-dev:arm64 libzstd-dev:arm64 libzstd1:arm64
```

But the host package resolver is currently in a conflicting state (`libzstd1`/`libsystemd0`/`apt` dependency breakage), so I did not force this further.

Conclusion:

- ARM64 smoke verification is complete
- ARM64 execution of `test_recompile` remains a separate follow-up task, blocked first by missing ARM64 user-space dependency packages on the host and then by the lack of an existing ARM64 guest selftest target
