# ARM64 build analysis: kernel + kop modules

Date: 2026-05-05

Scope: investigation only. No Docker build, VM run, AWS run, unit test, Makefile edit, Dockerfile edit, or `vendor/linux-framework` edit was performed.

Required context read:
- Root design rules: `CLAUDE.md`
- Plan hub: `docs/kernel-jit-optimization-plan.md`
- Recent commit context: `fe458eb9 Move ARM64 daemon/bpfopt build into Docker stage`

## Short answers

1. **kop module ARM64 build 是 Makefile 触发的 Docker-stage build.** `make aws-arm64-corpus` depends only on `$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)` for ARM64 (`Makefile:113`, `Makefile:122`). That image target is implemented by `runner/mk/build.mk` and runs `docker build --platform linux/arm64` (`runner/mk/build.mk:284`, `runner/mk/build.mk:288`). The actual `.ko` compilation happens in `runner-runtime.Dockerfile` stage `runner-runtime-kop-artifacts`, which runs `make -C /artifacts/headers ... M=/src/module/arm64 ... modules` (`runner/containers/runner-runtime.Dockerfile:387`, `runner/containers/runner-runtime.Dockerfile:440`).
2. **kernel-fork image does not build kop `.ko` files.** It builds the kernel image, in-tree kernel modules, and external-module header tree (`runner/containers/kernel-fork.Dockerfile:109`, `runner/containers/kernel-fork.Dockerfile:110`, `runner/containers/kernel-fork.Dockerfile:131`, `runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`). It exports only `/artifacts` from a scratch final stage (`runner/containers/kernel-fork.Dockerfile:157`, `runner/containers/kernel-fork.Dockerfile:159`).
3. **I do not see ARM64 double compilation in the current `aws-arm64-corpus` path.** ARM64 daemon/bpfopt/bpfprof are no longer Makefile prerequisites of the ARM64 runtime image (`runner/mk/build.mk:284`), and are built in ARM64 Docker stages instead (`runner/containers/runner-runtime.Dockerfile:463`, `runner/containers/runner-runtime.Dockerfile:481`, `runner/containers/runner-runtime.Dockerfile:503`, `runner/containers/runner-runtime.Dockerfile:518`). ARM64 kop is built once in `runner-runtime-kop-artifacts` (`runner/containers/runner-runtime.Dockerfile:387`, `runner/containers/runner-runtime.Dockerfile:440`).
4. **Host cross-build + COPY is feasible for kop `.ko`, but not a low-friction swap for the whole kernel+userspace set.** The host has the kernel source and ARM64 defconfig in the repo (`Makefile:10`, `Makefile:24`), but current kernel artifacts are produced in Docker under `/tmp/kernel-build` (`runner/containers/kernel-fork.Dockerfile:62`, `runner/containers/kernel-fork.Dockerfile:63`) and exported through Docker images (`runner/mk/build.mk:217`, `runner/mk/build.mk:224`, `runner/mk/build.mk:231`). Moving that to host would duplicate Dockerfile kernel packaging logic. Moving only kop `.ko` to host is medium complexity because it can reuse the kernel-fork header artifact, but needs new Makefile outputs and Docker `COPY` plumbing.

## Current build flow diagram

```text
make aws-arm64-corpus
  -> _AWS_ARM64_SUITE_DEPS = ARM64_RUNNER_RUNTIME_IMAGE_TAR
     [Makefile:113, Makefile:122]

ARM64_RUNNER_RUNTIME_IMAGE_TAR
  -> depends on runner runtime inputs, ARM64 Katran artifact image, ARM64 kernel-fork image
     [runner/mk/build.mk:284]
  -> docker build --platform linux/arm64 --target runner-runtime
     [runner/mk/build.mk:288, runner/mk/build.mk:289]

ARM64_KERNEL_FORK_IMAGE_TAR
  -> docker pull GHCR image, else docker build --platform KERNEL_FORK_BUILD_PLATFORM
     [runner/mk/build.mk:217, runner/mk/build.mk:219, runner/mk/build.mk:224]
  -> KERNEL_FORK_BUILD_PLATFORM defaults to linux/amd64
     [runner/mk/build.mk:87]
  -> RUN_TARGET_ARCH=arm64 selects ARCH=arm64, CROSS_COMPILE=aarch64-linux-gnu-
     [runner/mk/build.mk:226, runner/mk/build.mk:227, runner/containers/kernel-fork.Dockerfile:78, runner/containers/kernel-fork.Dockerfile:81]
  -> builds Image/vmlinuz.efi/modules
     [runner/containers/kernel-fork.Dockerfile:84, runner/containers/kernel-fork.Dockerfile:109, runner/containers/kernel-fork.Dockerfile:110]
  -> installs in-tree modules and external-module headers
     [runner/containers/kernel-fork.Dockerfile:131, runner/containers/kernel-fork.Dockerfile:138, runner/containers/kernel-fork.Dockerfile:142]

runner-runtime-kernel-base
  -> imports bpf-benchmark/kernel-fork:arm64-<kernel commit>
     [runner/containers/runner-runtime.Dockerfile:320]

runner-runtime-artifacts
  -> copies /artifacts/kernel, /artifacts/modules, /artifacts/headers, manifest
     [runner/containers/runner-runtime.Dockerfile:328, runner/containers/runner-runtime.Dockerfile:329, runner/containers/runner-runtime.Dockerfile:330, runner/containers/runner-runtime.Dockerfile:331]

runner-runtime-kop-artifacts
  -> copies /artifacts from kernel-fork and source module/
     [runner/containers/runner-runtime.Dockerfile:395, runner/containers/runner-runtime.Dockerfile:396]
  -> RUN_TARGET_ARCH=arm64 selects module/arm64 and CROSS_COMPILE=aarch64-linux-gnu-
     [runner/containers/runner-runtime.Dockerfile:415, runner/containers/runner-runtime.Dockerfile:417, runner/containers/runner-runtime.Dockerfile:418]
  -> builds external kop modules against /artifacts/headers
     [runner/containers/runner-runtime.Dockerfile:440]
  -> installs .ko files into /artifacts/kop
     [runner/containers/runner-runtime.Dockerfile:441]

runner-runtime final
  -> copies /artifacts/kop from runner-runtime-kop-artifacts
     [runner/containers/runner-runtime.Dockerfile:546]
```

The module source list comes from `module/arm64/Makefile`: it declares 8 `obj-m` modules (`module/arm64/Makefile:8`, `module/arm64/Makefile:15`). Its `all` target is a normal out-of-tree wrapper (`module/arm64/Makefile:17`, `module/arm64/Makefile:18`), but the Docker stage bypasses that wrapper and calls kernel Kbuild directly with `M="${PWD}/module/${module_arch}"` (`runner/containers/runner-runtime.Dockerfile:440`).

## Where `fixdep` fails

The failing source location is the external-module compile command:

```text
make -C /artifacts/headers ${make_args} M="${PWD}/module/${module_arch}" MO=/tmp/kop-build modules -j"${IMAGE_BUILD_JOBS}"
```

Citation: `runner/containers/runner-runtime.Dockerfile:440`.

Kbuild invokes `fixdep` through `$(objtree)/scripts/basic/fixdep` when compiling objects (`vendor/linux-framework/scripts/Kbuild.include:206`, `vendor/linux-framework/scripts/Kbuild.include:208`). `fixdep` is a host program declared by the kernel scripts build (`vendor/linux-framework/scripts/basic/Makefile:3`, `vendor/linux-framework/scripts/basic/Makefile:5`), and `modules` requires `modules_prepare`, which prepares scripts (`vendor/linux-framework/Makefile:1632`, `vendor/linux-framework/Makefile:1635`, `vendor/linux-framework/Makefile:1636`).

The kernel-fork image packages the external-module header tree by running `scripts/package/install-extmod-build` (`runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`). That script copies `scripts/` entries into the header tree (`vendor/linux-framework/scripts/package/install-extmod-build:12`, `vendor/linux-framework/scripts/package/install-extmod-build:28`, `vendor/linux-framework/scripts/package/install-extmod-build:44`, `vendor/linux-framework/scripts/package/install-extmod-build:49`). It only rebuilds host programs when `CC` and `HOSTCC` differ (`vendor/linux-framework/scripts/package/install-extmod-build:51`, `vendor/linux-framework/scripts/package/install-extmod-build:55`, `vendor/linux-framework/scripts/package/install-extmod-build:70`). The kernel-fork Dockerfile invokes it with `CC=gcc HOSTCC=gcc` (`runner/containers/kernel-fork.Dockerfile:141`), so no header-package host-tool rebuild is expected there.

Local image probe, no build run:
- `docker image inspect bpf-benchmark/kernel-fork:arm64-81cb884` reports `Architecture=amd64`.
- Copying `/artifacts/headers/scripts/basic` out of that image shows `scripts/basic/fixdep` exists.
- `file scripts/basic/fixdep` reports `ELF 64-bit LSB pie executable, x86-64`.

Conclusion: with the current local kernel-fork image, the path is present and `fixdep` is x86-64. Therefore the observed `/bin/sh: 1: /artifacts/headers/scripts/basic/fixdep: not found` is most consistent with the kop module `RUN` executing in an ARM64 rootfs that cannot load the x86-64 `fixdep` interpreter, or with a stale/mismatched kernel-fork image that lacks the packaged host tool. If the kop stage is truly linux/amd64, this exact local `fixdep` should be executable; if the effective kop stage is linux/arm64, Kbuild needs `scripts/basic/fixdep` rebuilt for that effective stage before `modules`.

## Double-compile audit

| Artifact | Current ARM64 path | Double compile? | Evidence |
|---|---|---:|---|
| daemon ARM64 | Built inside `runner-runtime-daemon-artifact-arm64` | No | ARM64 runtime image target has no `$(ARM64_DAEMON_BINARY)` prerequisite (`runner/mk/build.mk:284`); Docker stage builds with `TARGET_TRIPLE=aarch64-unknown-linux-gnu` (`runner/containers/runner-runtime.Dockerfile:463`, `runner/containers/runner-runtime.Dockerfile:481`). |
| bpfopt ARM64 | Built inside `runner-runtime-bpfopt-artifacts-arm64` | No | ARM64 runtime image target has no `$(ARM64_BPFOPT_BINARIES)` prerequisite (`runner/mk/build.mk:284`); Docker stage runs ARM64 cargo build for `bpfopt` and `bpfprof` (`runner/containers/runner-runtime.Dockerfile:503`, `runner/containers/runner-runtime.Dockerfile:518`, `runner/containers/runner-runtime.Dockerfile:519`). |
| bpfprof ARM64 | Built in the same Docker cargo command as bpfopt | No | Same cargo command lists `-p bpfopt -p bpfprof` (`runner/containers/runner-runtime.Dockerfile:518`, `runner/containers/runner-runtime.Dockerfile:519`). |
| kop modules ARM64 | Built in `runner-runtime-kop-artifacts` | No | Docker stage selects `module_arch=arm64`, `cross_compile=aarch64-linux-gnu-`, then runs external-module Kbuild once (`runner/containers/runner-runtime.Dockerfile:415`, `runner/containers/runner-runtime.Dockerfile:417`, `runner/containers/runner-runtime.Dockerfile:418`, `runner/containers/runner-runtime.Dockerfile:440`). Kernel-fork image builds kernel modules, not repo kop modules (`runner/containers/kernel-fork.Dockerfile:110`, `runner/containers/kernel-fork.Dockerfile:131`). |
| kernel headers ARM64 | Built/packaged in kernel-fork image | No | ARM64 kernel-fork target either pulls GHCR or builds one Docker image (`runner/mk/build.mk:217`, `runner/mk/build.mk:219`, `runner/mk/build.mk:224`); headers are produced by `headers_install` and `install-extmod-build` (`runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`). |
| runner C++ ARM64 | Built inside `runner-runtime-artifacts` via image-side Make rule | No | Docker stage calls `make image-runner-artifacts` (`runner/containers/runner-runtime.Dockerfile:365`); image-side target depends on `$(ACTIVE_RUNNER_BINARY)` (`runner/mk/build.mk:353`); ARM64 active build dir is selected from `RUN_TARGET_ARCH` (`runner/mk/build.mk:22`, `runner/mk/build.mk:48`). |

Specific `aws-arm64-corpus` check: the root target only depends on `_AWS_ARM64_SUITE_DEPS`, and that variable is only `$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)` (`Makefile:113`, `Makefile:122`). The ARM64 runtime image rule depends on runner inputs, ARM64 Katran image tar, and ARM64 kernel-fork image tar, but not host-built ARM64 daemon or bpfopt outputs (`runner/mk/build.mk:284`). The post-`fe458eb9` intent is also visible in the comment saying x86 Rust runtime binaries are host-built while ARM64 builds happen inside Docker because the host lacks a complete ARM64 userspace sysroot for libbpf dynamic libraries (`runner/mk/build.mk:334`, `runner/mk/build.mk:335`, `runner/mk/build.mk:336`).

Side note for x86: x86 Rust binaries are host-built and copied into the image, not rebuilt in Docker (`runner/mk/build.mk:267`, `runner/mk/build.mk:337`, `runner/mk/build.mk:341`, `runner/containers/runner-runtime.Dockerfile:449`, `runner/containers/runner-runtime.Dockerfile:455`, `runner/containers/runner-runtime.Dockerfile:490`, `runner/containers/runner-runtime.Dockerfile:496`). x86 kop modules are still built in the Docker kop stage by selecting `module_arch=x86` (`runner/containers/runner-runtime.Dockerfile:408`, `runner/containers/runner-runtime.Dockerfile:411`, `runner/containers/runner-runtime.Dockerfile:440`).

## Host cross-build + COPY feasibility

| Artifact | Feasibility | Complexity | Evidence and blockers |
|---|---|---:|---|
| daemon ARM64 | Possible, but not the best target for this fix | MED | The daemon depends on `kernel-sys` (`daemon/Cargo.toml:17`, `daemon/Cargo.toml:31`), and `kernel-sys` re-exports `libbpf-rs`/`libbpf-sys` (`bpfopt/crates/kernel-sys/Cargo.toml:9`, `bpfopt/crates/kernel-sys/Cargo.toml:10`, `bpfopt/crates/kernel-sys/src/lib.rs:19`, `bpfopt/crates/kernel-sys/src/lib.rs:22`). Current Makefile explicitly moved ARM64 Rust builds into Docker because the host lacks a complete ARM64 libbpf userspace sysroot (`runner/mk/build.mk:334`, `runner/mk/build.mk:335`, `runner/mk/build.mk:336`). Local probe found ARM64 glibc present but no ARM64 `libbpf.so` or `libelf.so`; that matches the Makefile comment. |
| bpfopt/bpfprof ARM64 | Possible, same sysroot issue as daemon | MED | `bpfopt` workspace depends on `libbpf-rs` and `libbpf-sys` (`bpfopt/Cargo.toml:53`, `bpfopt/Cargo.toml:54`), and the ARM64 Docker stage currently owns the build (`runner/containers/runner-runtime.Dockerfile:503`, `runner/containers/runner-runtime.Dockerfile:518`, `runner/containers/runner-runtime.Dockerfile:519`). Host cross-build needs ARM64 libbpf/libelf/pkg-config plumbing before it can replace the Docker stage. |
| kop `.ko` ARM64 | Feasible and narrower than moving Rust | MED | The source is already isolated under `module/arm64` and common headers (`runner/mk/build.mk:94`, `runner/mk/build.mk:95`, `runner/mk/build.mk:109`; `module/arm64/Makefile:8`, `module/arm64/Makefile:15`). The needed kernel external-module header tree is already exported by kernel-fork (`runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`). A host rule could extract or depend on that header artifact, run `make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- M=<module/arm64> MO=<out> modules`, and then the runtime Dockerfile could `COPY` `.ko` files from the build context. The non-trivial part is artifact plumbing without host bind mounts; design rules require Docker image layers, not mounting the host workspace into runtime containers (`CLAUDE.md:131`, `CLAUDE.md:132`). |
| kernel-fork ARM64 kernel + modules + headers | Possible, but large re-plumbing | HIGH | Current kernel build is intentionally inside `kernel-fork.Dockerfile`: it chooses target arch, defconfig, cross compiler, build targets, modules install, headers install, and header packaging in one Docker stage (`runner/containers/kernel-fork.Dockerfile:67`, `runner/containers/kernel-fork.Dockerfile:92`, `runner/containers/kernel-fork.Dockerfile:96`, `runner/containers/kernel-fork.Dockerfile:109`, `runner/containers/kernel-fork.Dockerfile:110`, `runner/containers/kernel-fork.Dockerfile:131`, `runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`). Moving this to host would duplicate that stage and require new Makefile artifact targets plus Docker context/COPY rules. |
| x86 kop `.ko` | Feasible but lower priority | MED | x86 follows the same kop Docker stage with `module_arch=x86` and no cross compiler (`runner/containers/runner-runtime.Dockerfile:408`, `runner/containers/runner-runtime.Dockerfile:411`, `runner/containers/runner-runtime.Dockerfile:412`, `runner/containers/runner-runtime.Dockerfile:440`). Host-building x86 `.ko` would need the same artifact plumbing as ARM64, but it does not address the ARM64 `fixdep` failure directly. |

Host probes run on 2026-05-05, without building:
- `command -v aarch64-linux-gnu-gcc` returned `/usr/bin/aarch64-linux-gnu-gcc`; `rustup target list --installed` included `aarch64-unknown-linux-gnu`.
- `/usr/aarch64-linux-gnu/lib/libc.so` exists, but `/usr/lib/aarch64-linux-gnu/libbpf.so` and `/usr/lib/aarch64-linux-gnu/libelf.so` do not.
- `.cache/arm64-kernel-build` and `.cache/x86-kernel-build` did not contain a prepared `Module.symvers`/`vmlinux` tree in this worktree.

## Options

### A. Fix `fixdep` inside Docker

Description: keep kop `.ko` compilation in `runner-runtime-kop-artifacts`, but ensure `/artifacts/headers/scripts/basic/fixdep` matches the effective stage platform before line 440 runs. If the effective stage is ARM64, run a small `make -C /artifacts/headers ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- HOSTCC=gcc scripts` or equivalent host-tool rebuild before the external-module compile. If the intended stage is amd64, make that platform selection effective before line 440.

Pros:
- Smallest behavior change.
- Preserves the current Docker-owned kernel/kop layer policy (`CLAUDE.md:134`, `CLAUDE.md:138`).
- Keeps ARM64 Rust builds in Docker, which matches the post-`fe458eb9` Makefile comment (`runner/mk/build.mk:334`, `runner/mk/build.mk:335`, `runner/mk/build.mk:336`).

Cons:
- Needs one careful Dockerfile change around the kop stage to avoid rebuilding more than host tools.
- Needs a validation build afterward, which was intentionally not run in this investigation.

LoC delta estimate: about 5-10 Dockerfile lines.

Blast radius: low. Only the kop artifact stage around `runner/containers/runner-runtime.Dockerfile:387` to `runner/containers/runner-runtime.Dockerfile:440`.

### B. Host cross-build kop `.ko` + COPY into image

Description: add a host Makefile artifact rule that uses ARM64 kernel-fork headers and `aarch64-linux-gnu-` to build `module/arm64/*.ko`, then replace or bypass the Dockerfile kop build with a `COPY` of those `.ko` files into `/artifacts/kop`.

Pros:
- Avoids executing kernel header host tools inside an ARM64 Docker stage.
- Keeps the expensive kernel-fork image as the source of truth for kernel release, `Module.symvers`, and external-module headers (`runner/containers/kernel-fork.Dockerfile:114`, `runner/containers/kernel-fork.Dockerfile:118`, `runner/containers/kernel-fork.Dockerfile:138`, `runner/containers/kernel-fork.Dockerfile:142`).
- Narrower than moving daemon/bpfopt/bpfprof back to host.

Cons:
- Adds a new host artifact path and invalidation surface.
- Requires Docker context/COPY plumbing while preserving the no host bind-mount rule (`CLAUDE.md:131`, `CLAUDE.md:132`).
- Must ensure the `.ko` output is tied to the exact kernel-fork image tag derived from `$(KERNEL_FORK_COMMIT_ARM64)` (`runner/mk/build.mk:58`, `runner/mk/build.mk:60`, `runner/mk/build.mk:64`).

LoC delta estimate: 30-70 lines across Makefile/build.mk and Dockerfile.

Blast radius: medium. It changes the ownership boundary for kop artifacts but not the kernel-fork kernel build.

### C. Skip baked kop modules in ARM64 image and build/load on first run

Description: omit `/artifacts/kop` from the ARM64 runtime image and build kop modules inside the target VM/instance before loading them.

Pros:
- Can unblock one-off benchmarking if image build plumbing remains blocked.
- Uses the target kernel/userspace as the build environment, so host-tool architecture mismatch disappears.

Cons:
- Conflicts with the current container policy that kop modules are inside the runner image (`runner/containers/README.md:29`, `runner/containers/README.md:30`).
- Slows first boot/run and requires shipping build tools/source into runtime.
- Adds runtime failure modes to the benchmark path.

LoC delta estimate: 40-100 lines if implemented cleanly.

Blast radius: high. It moves a build step into runtime setup and changes artifact expectations in `bpfrejit-install`, which currently copies `/artifacts/kop` from the image (`runner/scripts/bpfrejit-install:138`, `runner/scripts/bpfrejit-install:139`, `runner/scripts/bpfrejit-install:148`, `runner/scripts/bpfrejit-install:150`).

## Recommended path

Recommended: **Option A, fix `fixdep` inside Docker.**

Reason: current architecture already puts kernel build in `kernel-fork.Dockerfile` and kop external-module build in `runner-runtime-kop-artifacts` (`runner/containers/kernel-fork.Dockerfile:109`, `runner/containers/kernel-fork.Dockerfile:142`, `runner/containers/runner-runtime.Dockerfile:387`, `runner/containers/runner-runtime.Dockerfile:440`). The failure is localized to the host-tool architecture used by that one external-module compile. Host-building kop `.ko` is feasible, but it changes artifact ownership and adds Makefile/COPY plumbing. Moving the full kernel build to host is substantially larger than the failure requires.

## Action items

1. In `runner/containers/runner-runtime.Dockerfile`, before the external-module compile at `runner/containers/runner-runtime.Dockerfile:440`, align `scripts/basic/fixdep` with the effective kop-stage platform. The relevant stage starts at `runner/containers/runner-runtime.Dockerfile:387`, copies `/artifacts` at `runner/containers/runner-runtime.Dockerfile:395`, and computes ARM64 `make_args` at `runner/containers/runner-runtime.Dockerfile:435` to `runner/containers/runner-runtime.Dockerfile:438`.
2. If Option A chooses to rebuild scripts, keep it scoped to host tools: Kbuild's `scripts` target is declared at `vendor/linux-framework/Makefile:1314` to `vendor/linux-framework/Makefile:1316`, and `fixdep` is the `scripts/basic` host program at `vendor/linux-framework/scripts/basic/Makefile:3` to `vendor/linux-framework/scripts/basic/Makefile:5`.
3. If Option B is chosen instead, add a Makefile artifact keyed by `$(KERNEL_FORK_COMMIT_ARM64)` (`runner/mk/build.mk:58`, `runner/mk/build.mk:60`) and the active kop source set (`runner/mk/build.mk:94`, `runner/mk/build.mk:95`, `runner/mk/build.mk:109`), then replace the Dockerfile module compile at `runner/containers/runner-runtime.Dockerfile:440` with a `COPY` into the same final path consumed at `runner/containers/runner-runtime.Dockerfile:546`.
4. Do not move ARM64 daemon/bpfopt/bpfprof back to host as part of this fix unless the ARM64 libbpf/libelf sysroot is made explicit. The current build rules deliberately keep ARM64 Rust artifacts inside Docker (`runner/mk/build.mk:334`, `runner/mk/build.mk:335`, `runner/mk/build.mk:336`; `runner/containers/runner-runtime.Dockerfile:463`, `runner/containers/runner-runtime.Dockerfile:503`).
