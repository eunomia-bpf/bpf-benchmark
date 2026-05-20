# Build Directory Contract

This repository keeps generated repo artifacts next to the subsystem that owns
them. `.cache` is only for external caches and transport artifacts.

## `.cache`

Allowed contents:
- downloaded or unpacked toolchain/sysroot caches, such as `aarch64-sysroot`
  and `sysroots/arm64-llvm15`
- downloaded package caches, such as `apt-arm64-debs`
- Go module/build caches
- saved container image tars under `container-images`
- per-run AWS/KVM state, logs, and result transport state

Forbidden contents:
- kernel `O=` build trees
- kinsn module build trees
- micro or stage2 BPF/native program outputs
- host-built corpus app binaries or BPF objects
- copied repo artifacts staged only for Docker

## Repo Build Outputs

- `vendor/build/x86` and `vendor/build/arm64`: host-built corpus app artifacts,
  bpftool, Katran BPF objects, and kernel `linux` build trees.
- `vendor/build/<app>-build-*` and `vendor/build/<app>-*.yaml`: vendor-owned
  app builder intermediates that should not enter the Docker context.
- `module/x86/build` and `module/arm64/build`: kinsn Kbuild `MO=` outputs.
- `micro/programs/build-x86` and `micro/programs/build-arm64`: micro BPF/native
  programs plus generated `kernel_offsets.h`.
- `native-sim/test/build-x86` and `native-sim/test/build-arm64`: stage2 helper
  and map test objects.
- `runner/build-llvmbpf` and `runner/build-arm64-llvmbpf`: C++ runner builds.
- `daemon/target`, `bpfopt/target`, and
  `native-sim/x86/native_lab/native_link/target`: Rust build outputs.
- `tests/unittest/build*` and `tests/negative/build*`: test artifacts consumed
  by the runtime image.

`bpfopt/loader`, `bpfopt/testbin`, and `bpfopt/testobject` are test-only local
assets and are not part of the runtime build cache contract.

## Docker Contract

Docker images consume already-built host artifacts directly from the owning
build directories or named build contexts. The Makefile must not copy artifacts
into a second staging directory just so Docker can copy them again.

The default Docker context should exclude heavyweight build trees. Runtime image
layers are ordered by change frequency: base packages, app artifacts, kernel and
kinsn modules, runner/test artifacts, Rust daemon/tools, then Python/config data.
