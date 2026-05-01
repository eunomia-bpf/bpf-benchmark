# P89 Katran ARM64 Build Diagnosis

Date: 2026-04-30

## Current Flow

- `runner/mk/build.mk` sets `ARM64_KATRAN_ARTIFACTS_PULL_PLATFORM := linux/arm64`.
- If the GHCR image is unavailable, `$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR)` runs:
  - `docker build --platform linux/arm64`
  - `--target katran-artifacts`
  - `--build-arg RUN_TARGET_ARCH=arm64`
  - Dockerfile: `runner/containers/katran-artifacts.Dockerfile`
- `runner/containers/katran-artifacts.Dockerfile` currently starts the build stage with plain `FROM docker.io/library/ubuntu:24.04 AS katran-artifacts-build`. Because the make rule passes `--platform linux/arm64`, this stage is an ARM64 Ubuntu userspace.
- Inside that ARM64 userspace, the Dockerfile runs `make image-katran-artifacts RUN_TARGET_ARCH="${target_arch}" ...`.
- The `image-katran-artifacts` target expands to `$(ACTIVE_KATRAN_REQUIRED)` in `runner/mk/build.mk`.

## How `build_katran.sh` Runs

`runner/mk/build.mk` invokes upstream Katran's `build_katran.sh` directly inside the Docker build container:

1. It creates `$(KATRAN_BUILD_ROOT)` and `$(REPO_KATRAN_ROOT)`.
2. It touches `"$build_root/deps/grpc_installed"` so upstream `build_katran.sh` does not build gRPC from source.
3. It runs:
   - `KATRAN_SKIP_SYSTEM_PACKAGES=1`
   - `BUILD_EXAMPLE_GRPC=1`
   - `BUILD_DIR="$build_root"`
   - `INSTALL_DIR="$install_root"`
   - `INSTALL_DEPS_ONLY=1`
   - `./build_katran.sh`
4. It then runs the Katran top-level CMake configure/build/install itself.
5. It finally runs `./build_bpf_modules_opensource.sh` to emit BPF objects.

This means the build is not done by `docker exec`, but by `RUN make image-katran-artifacts` during image build. With `docker build --platform linux/arm64` on an x86 host, every ARM64 userspace command in that `RUN` step is intercepted by qemu-binfmt.

## Cross-Compile Variables

The current Katran recipe hard-codes native tool names:

- Dependency build: `CC=clang CXX=clang++ AR=ar RANLIB=ranlib`
- Final CMake configure: `CC=clang CXX=clang++ AR=ar RANLIB=ranlib`
- CMake flags: `-DCMAKE_C_COMPILER=clang`, `-DCMAKE_CXX_COMPILER=clang++`, `-DCMAKE_AR=/usr/bin/ar`, `-DCMAKE_RANLIB=/usr/bin/ranlib`

It does not set:

- `CROSS_COMPILE`
- `CC=aarch64-linux-gnu-gcc`
- `CXX=aarch64-linux-gnu-g++`
- `AR=aarch64-linux-gnu-ar`
- `RANLIB=aarch64-linux-gnu-ranlib`
- `CMAKE_TOOLCHAIN_FILE`
- target `PKG_CONFIG_LIBDIR`

## Upstream Notes

The upstream Katran README documents `build_katran.sh` as the normal build entry point and lists required dependencies such as folly, clang, glog, gtest, gflags, and elf libraries. `DEVELOPING.md` documents `build_bpf_modules_opensource.sh` as the BPF object build path. I did not find an upstream Katran-specific AArch64 cross-compilation recipe in README/DEVELOPING; the local fix therefore has to supply the CMake/GCC cross toolchain wiring around upstream's normal build entry points.

References checked:

- https://github.com/facebookincubator/katran
- https://raw.githubusercontent.com/facebookincubator/katran/main/README.md
- https://raw.githubusercontent.com/facebookincubator/katran/main/DEVELOPING.md
- https://raw.githubusercontent.com/facebookincubator/katran/main/build_katran.sh

## Root Cause

The ARM64 artifact build is configured as an ARM64 container build rather than an amd64-hosted cross build. Because `build_katran.sh` and the final Katran CMake invocation use native compiler names and no toolchain file, Docker/QEMU treats the whole build as native ARM64 userspace. On an x86 host this turns the dependency builds, CMake probes, compilers, make, and shell utilities into qemu-emulated ARM64 processes.
