# Benchmark Runtime Architecture

Date: 2026-04-10
Status: Active architecture

This document defines the active execution architecture for `micro`, `corpus`,
and `e2e`.

It replaces the old direction where the runner tried to synthesize build
toolchains, runtime loaders, and host setup from the middle layer.

## Historical Problem

The old tree was too complex because one runner layer was doing all of the
following at once:

1. Building application artifacts.
2. Cross-building for `x86_64` and `arm64`.
3. Bundling runtime loaders and shared libraries by hand.
4. Preparing AWS or KVM hosts.
5. Launching the actual benchmark workload.

That led to avoidable complexity:

- `runner/mk/build.mk` grows into a custom sysroot and runtime packager.
- `runner/libs` grows host-setup and transfer logic that should belong to image
  preparation or app-native launchers.
- artifact roots, scratch roots, runtime lib roots, and transfer roots all
  become different concepts.

## Active Architecture

The active architecture has a hard boundary:

1. Host image owns the kernel and host capabilities.
2. Build container owns compilation.
3. Run container owns userspace runtime dependencies.
4. Make owns artifact production.
5. Suite drivers own result directory creation.

### Host Layer

The KVM guest or AWS instance is the real kernel host.

The host layer is responsible for:

- booting the exact target kernel
- exposing `/lib/modules`, `/sys`, `/proc`, `/sys/fs/bpf`, `bpffs`, cgroups,
  netns, and required privileges
- carrying small, stable base prerequisites only

The host layer is not responsible for:

- compiling benchmark applications
- discovering per-app runtime `.so` dependencies at run time
- acting as a second artifact cache

### Build Layer

Every app is built inside a fixed build container for its target
`arch + distro`.

The build container is responsible for:

- compiler toolchain
- headers and pkg-config environment
- app-native build commands

The build container is not responsible for:

- kernel installation
- result collection
- host network namespace policy

### Run Layer

After the host boots into the correct kernel, benchmark suites run inside one
privileged runtime container for the target architecture.

That means:

- the kernel stays on the VM or AWS host
- `runner.suites.*` entrypoints, daemon processes, app loaders, attach logic, workload
  tools, and benchmark processes run in that container
- the container mounts host resources that the app actually needs

For eBPF-heavy apps, that usually means:

- `--privileged`
- `--pid=host`
- `--network=host`
- bind mounts for `/sys`, `/sys/fs/bpf`, `/sys/kernel/debug`, `/lib/modules`,
  and the benchmark workspace
- bind mounts for `corpus/results`, `e2e/results`, or `micro/results`

This is still "running on the host kernel". The container only isolates
userspace.

### Results Layer

Benchmark results must be written directly into shared suite roots:

- `micro/results`
- `corpus/results`
- `e2e/results`

There is no second benchmark artifact directory, no "copy back latest result",
and no "find newest directory" logic.

Executor-specific cache directories may still exist for logs or transient
workspace state, but they are not benchmark results.

## Build and Packaging Rules

### Required Rules

1. All build and packaging steps are real Make targets.
2. Every run calls the final targets directly.
3. Cache behavior comes from Make and the downstream build system.
4. Normal runs do not `rm -rf` outputs.
5. Cleanup is explicit via `make clean` or narrowly scoped clean targets.

### Forbidden Patterns

These patterns are not allowed on the main path:

- hand-written `.ready` or stamp files for build reuse
- phony packaging readiness rules in the main path
- host-owned runtime dependency discovery for ELF trees
- runner-owned x86 sysroot adapter layers as a permanent architecture
- result copy-back logic
- shared mutable output roots guarded by locks
- run-time package installation on KVM or AWS hosts

## Current Simplification

The active implementation keeps these boundaries:

- `build.mk` mostly dispatches into app-native `make`, `cmake`, `cargo`, or
  containerized equivalents
- `workspace_layout.py` describes final artifacts, not guessed artifact roots
- each `runner.suites.*` entrypoint enters the runtime container once, then
  launches work and records result paths without staging benchmark outputs
- `aws_remote_prep.py` prepares the host, but does not synthesize a userspace
  runtime artifact tree

## Current Implementation State

### Canonical Container Layout

- [x] Put the architecture decision in a stable design document.
- [x] Make the repository reference a canonical container location instead of an
  ad-hoc or missing Dockerfile path.
- [x] Create fixed build container definitions for every active target
  combination we build locally.
  Current state: `runner/containers/runner-build.Dockerfile` is the canonical
  build image definition for runner, kernel, tests, workload tools, and most
  native repos. bpftrace uses its upstream `docker/Dockerfile.static` as a
  dedicated static build image. Make builds both image families for the target
  platform, including `linux/amd64` and `linux/arm64`.

### Build in Containers

- [x] Convert `runner` ARM64 build to the canonical build container path.
- [x] Convert x86_64 runner build away from the host toolchain path.
- [x] Convert `daemon` x86_64/ARM64 builds to canonical build containers.
- [x] Convert kernel and module builds to canonical build containers.
- [x] Convert test and micro helper builds to canonical build containers.
- [x] Keep generated micro BPF objects out of `micro/programs` and build them
  under `.cache/micro-programs/<arch>` via Make.
- [x] Convert `scx`, `bcc`, `tracee`, `tetragon`, `katran`, and
  `workload-tools` to fixed distro build containers.
- [x] Convert bpftrace to its upstream static build container and CMake install
  target. The runtime artifact is `.cache/repo-artifacts/<arch>/bpftrace/bin/bpftrace`
  and is fully static; the build disables optional BFD/opcodes discovery so the
  runtime container does not need `bcc`, `clang`, `libpcap`, musl, or hand-copied
  shared libraries.
- [x] Build native repo artifacts from per-arch scratch source/build roots
  instead of writing into shared checkouts.
- [x] Stop producing shared AWS kernel transport packages. AWS prep now calls
  the canonical kernel image and `.cache/repo-artifacts/<arch>/kernel-modules`
  Make targets, then syncs that modules tree to the host staging directory.

### Runtime Container

- [x] Replace host-side launcher generation with runtime container execution.
  Current state: Make builds `runner-runtime.Dockerfile` for the target arch,
  saves it as `.cache/container-images/<arch>-runner-runtime.image.tar`, and
  the host entrypoint loads that image before executing the suite inside it.
- [x] Stop resolving glibc and loader paths from the host runner layer.
- [x] Treat final Make targets as app artifacts or OCI image tars, not handmade
  runtime archives.

### Run in Host-Privileged Containers

- [x] Use one suite-level runtime container contract for `bcc`, `tracee`,
  `tetragon`, `katran`, `scx`, `bpftrace`, daemon, workload, and attach
  orchestration.
- [x] Keep app processes in the host PID namespace so BPF FD/PID discovery uses
  real loader PIDs.
- [x] Keep attach and topology logic in the existing app runner modules; the
  container is packaging/execution boundary, not a new app abstraction layer.

### Thin Orchestration

- [x] Keep `run_target_suite.py` as a thin contract/dispatch layer: it writes the
  manifest, asks `workspace_layout.py` for final Make targets, dispatches
  AWS/KVM execution, and delegates AWS failure cleanup to `aws_executor.py`.
- [x] Keep AWS/KVM prep from installing userspace packages at run time.
- [x] Remove remaining artifact-root assumptions from transfer and consumption
  paths.

## Explicit Non-Goals

This architecture does not mean:

- replacing the host kernel with a container kernel
- hiding all eBPF attach semantics behind generic abstractions
- forcing every app into a separate launcher

The goal is narrower:

- compile in fixed containers
- run suite userspace in fixed containers
- keep kernel ownership with the host
- keep build ownership with Make

## Current Invariants

The repository keeps these invariants:

- away from hand-built runtime packaging
- away from host-synthesized sysroots
- away from copy-back result handling
- app-native build logic inside fixed containers
- host kernel + privileged run container execution
