# P75 Kernel Fork Image Tag

## Architecture

The vendor kernel fork now builds as a separate local Docker image:

```text
bpf-benchmark/kernel-fork:<arch>-<vendor-linux-framework-short-commit>
```

For the current submodule this is:

```text
bpf-benchmark/kernel-fork:x86_64-a1b8bade1
bpf-benchmark/kernel-fork:arm64-a1b8bade1
```

`runner/containers/kernel-fork.Dockerfile` is responsible for only the kernel fork:

- copies `vendor/bpfrejit_x86_defconfig`, `vendor/bpfrejit_arm64_defconfig`, and `vendor/linux-framework`;
- builds x86_64 with `ARCH=x86_64`;
- builds arm64 with `ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-` on a `linux/amd64` build container;
- installs kernel image, `System.map`, `Module.symvers`, `.config`, modules, and external module headers under `/artifacts`;
- does not build the benchmark `module/` tree.

`runner/containers/runner-runtime.Dockerfile` now imports the kernel fork image:

```dockerfile
FROM --platform=${KERNEL_FORK_IMAGE_PLATFORM} \
    bpf-benchmark/kernel-fork:${RUN_TARGET_ARCH}-${VENDOR_LINUX_FRAMEWORK_COMMIT} \
    AS runner-runtime-kernel-base
```

The runtime image copies `/artifacts/kernel`, `/artifacts/modules`, and `/artifacts/headers` from that image. The kinsn module build remains in an upper runtime stage and uses `/artifacts/headers` as the external module build tree, so changing `daemon/`, `bpfopt/`, runtime Python, or `module/` does not invalidate the kernel build.

`runner/mk/build.mk` adds `image-kernel-fork-image-tar`. The target checks for the local tag first, builds it only when the tag is absent, and saves it to the same local image tar flow used by AWS transfer. It intentionally does not push to a registry.

## Validation

All commands below ran in `/tmp/bpf-benchmark-p75` so the active P67/P72 worktree and images were not modified.

| Check | Command | Result |
| --- | --- | --- |
| x86_64 kernel fork image | `make image-kernel-fork-image-tar RUN_TARGET_ARCH=x86_64 IMAGE_BUILD_JOBS=12` | `real 516.21s` after a cancelled `-j4` warmup; combined elapsed was about `1154s`. Produced `.cache/container-images/x86_64-kernel-fork-a1b8bade1.image.tar`. |
| x86_64 runtime image | `make image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64` | `real 1211.42s`. Runtime build copied kernel artifacts from `kernel-fork`; no kernel compile stage ran. |
| daemon edit cache test | temporary `daemon/src/main.rs` comment, then runtime tar target | full target `real 369.87s`; Docker build reused kernel, kinsn, and bpfopt layers. Daemon Cargo rebuild finished in `10.76s`; remaining time was image load/save. |
| module edit cache test | temporary `module/x86/bpf_rotate.c` comment, then runtime tar target | full target `real 303.66s`; Docker build reused kernel and Rust layers. Only the kinsn stage reran, with external module make taking about `3.2s`; remaining time was image load/save. |
| Python edit cache test | temporary `runner/libs/run_contract.py` comment, then runtime tar target | full target `real 360.59s`; Docker build reused kernel, kinsn, daemon, and bpfopt layers. Only final Python/config copy layers reran; remaining time was image load/save. |
| arm64 kernel fork image | `make image-kernel-fork-image-tar RUN_TARGET_ARCH=arm64 IMAGE_BUILD_JOBS=12` | `real 1179.67s`. Produced `.cache/container-images/arm64-kernel-fork-a1b8bade1.image.tar`. |

The full `image-runner-runtime-image-tar` target includes `docker load` and `docker save` of a multi-GB runtime tar, so its wall time is dominated by tar import/export. The Docker build cache behavior matches the P75 goal: daemon, module, and Python edits do not recompile the vendor kernel.

## arm64 Cross-Compile Evidence

The arm64 kernel-fork build used a host-side cross compiler:

```text
docker build --platform linux/amd64
apt-get install ... gcc-aarch64-linux-gnu
aarch64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
target_cc=aarch64-linux-gnu-gcc
```

This avoids qemu-binfmt aarch64-native GCC for the kernel build.

## Submodule State

`vendor/linux-framework` stayed at:

```text
a1b8bade169fae6e174ef022fa96fb1c626d96df
```

No files inside `vendor/linux-framework` were changed.
