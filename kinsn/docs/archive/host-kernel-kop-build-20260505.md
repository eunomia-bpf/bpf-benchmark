# Host kernel and kop build via Makefile

Date: 2026-05-05

Context read:
- `CLAUDE.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/arm64-build-analysis-20260505.md`

## Per-file LoC delta

| File | Added | Deleted | Net |
| --- | ---: | ---: | ---: |
| `runner/mk/build.mk` | 176 | 4 | +172 |
| `runner/containers/runner-runtime.Dockerfile` | 16 | 2 | +14 |
| `docs/tmp/host-kernel-kop-build-20260505.md` | 121 | 0 | +121 |

## New Makefile/build.mk rules

Default switch:
- `USE_HOST_KERNEL_BUILD ?= 1`

New host output locations:
- `HOST_KERNEL_BUILD_DIR_X86`
- `HOST_KERNEL_BUILD_DIR_ARM64`
- `HOST_KERNEL_ARTIFACT_DIR_X86`
- `HOST_KERNEL_ARTIFACT_DIR_ARM64`
- `HOST_KOP_BUILD_DIR_X86`
- `HOST_KOP_BUILD_DIR_ARM64`
- `HOST_KOP_DIR_X86`
- `HOST_KOP_DIR_ARM64`

New build targets:
- `host-kernel`
- `host-kernel-x86`
- `host-kernel-arm64`
- `host-kop`
- `host-kop-x86`
- `host-kop-arm64`

Host kernel rules mirror `runner/containers/kernel-fork.Dockerfile`:
- copy `vendor/bpfrejit_x86_defconfig` or `vendor/bpfrejit_arm64_defconfig`
- enable `BLK_DEV_LOOP`, `VIRTIO_CONSOLE`, `EXT4_FS`, `JBD2`, `FS_MBCACHE`
- run `olddefconfig`
- build x86 `bzImage modules`
- build ARM64 `Image vmlinuz.efi modules`
- install kernel image, `System.map`, `Module.symvers`, `.config`, modules, external-module headers, `vmlinux`, and `manifest.json`

Host kop rules:
- build x86 modules from `module/x86` against the host x86 kernel build tree
- build ARM64 modules from `module/arm64` with `ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-`
- install clean `.ko` outputs to `.cache/repo-build/host/kop/<arch>`
- verify expected module count and `.BTF` section for every `.ko`

Runner-runtime image rules:
- host mode passes `runner-runtime-host-kernel-artifacts` and `runner-runtime-host-kop-artifacts` build contexts
- docker fallback mode is still available with `USE_HOST_KERNEL_BUILD=0`
- fallback uses `runner-runtime-kernel-artifacts-docker` and `runner-runtime-kop-artifacts-docker`

## Validation

Host x86 kernel:
- Command: `/usr/bin/time -p make host-kernel-x86`
- Result: succeeded
- Time: `real 255.24`
- Artifacts: `.cache/repo-build/host/kernel-artifacts/x86_64`
- Kernel image: `.cache/repo-build/host/kernel-artifacts/x86_64/kernel/bzImage`

Host x86 kop:
- Command: `/usr/bin/time -p make host-kop-x86`
- Result: succeeded
- Time: `real 3.84`
- Modules: 6
- `.BTF`: verified on every `.ko`

Host ARM64 kernel:
- Command: `/usr/bin/time -p make host-kernel-arm64`
- Result: succeeded
- Time: `real 262.26`
- Artifacts: `.cache/repo-build/host/kernel-artifacts/arm64`
- Kernel images: `.cache/repo-build/host/kernel-artifacts/arm64/kernel/Image`, `.cache/repo-build/host/kernel-artifacts/arm64/kernel/vmlinuz.efi`

Host ARM64 kop:
- Command: `/usr/bin/time -p make host-kop-arm64`
- Result: succeeded
- Time: `real 3.77`
- Modules: 8
- `.BTF`: verified on every `.ko`

Runner-runtime image sanity:
- Command: `/usr/bin/time -p make image-runner-runtime-image-tar`
- Result: succeeded for x86_64
- Time: `real 224.41`
- Image: `bpf-benchmark/runner-runtime:x86_64`
- Tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- Observed host artifact contexts: `runner-runtime-host-kernel-artifacts`, `runner-runtime-host-kop-artifacts`
- Built-in image checks passed for `/artifacts/kernel`, `/artifacts/modules`, `/artifacts/kop`, daemon, `bpfopt`, `bpfprof`, and runner artifacts

Docker fallback sanity:
- `USE_HOST_KERNEL_BUILD=0 make -n image-runner-runtime-image-tar` selected `docker load -i .cache/container-images/x86_64-kernel-fork-81cb884.image.tar`
- fallback args selected `runner-runtime-kernel-artifacts-docker` and `runner-runtime-kop-artifacts-docker`
- targeted fallback build succeeded:
  `docker build --platform linux/amd64 --target runner-runtime-kop-artifacts ...`
- Time: `real 7.90` with cached layers

Not run:
- `vm-corpus`, `vm-e2e`, `aws-*`, and KVM-starting targets
- full docker rebuild of `kernel-fork.Dockerfile`; the file was left unchanged and the existing docker artifact path was exercised through the fallback kop target

## Follow-up deletion candidates

After validation by Claude, the follow-up cleanup can remove:
- `runner/containers/kernel-fork.Dockerfile`
- `kernel-fork` image tar dependencies from runner-runtime builds
- `runner-runtime-kernel-artifacts-docker`
- `runner-runtime-kop-artifacts-docker`
- in-image kop module build logic

## Commit

Commit hash: pending before commit; final pushed hash is reported in the completion response.
