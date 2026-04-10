# Benchmark Runtime Architecture

Date: 2026-04-10
Status: Active architecture

This document defines the active execution architecture for `micro`, `corpus`,
and `e2e`.

It replaces the old direction where the runner tried to synthesize build
toolchains, runtime loaders, and host setup from the middle layer.

## Problem

The current tree is too complex because one runner layer is doing all of the
following at once:

1. Building application artifacts.
2. Cross-building for `x86_64` and `arm64`.
3. Bundling runtime loaders and shared libraries by hand.
4. Preparing AWS or KVM hosts.
5. Launching the actual benchmark workload.

That leads to avoidable complexity:

- `runner/mk/build.mk` grows into a custom sysroot and runtime packager.
- `runner/libs` grows host-setup and transfer logic that should belong to image
  preparation or app-native launchers.
- artifact roots, scratch roots, runtime lib roots, and transfer roots all
  become different concepts.

## Target Architecture

The target architecture has a hard boundary:

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

Every app should be built inside a fixed build container for its target
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

After the host boots into the correct kernel, benchmark apps should run inside
privileged runtime containers wherever practical.

That means:

- the kernel stays on the VM or AWS host
- userspace loader and benchmark process run in a container
- the container mounts host resources that the app actually needs

For eBPF-heavy apps, that usually means:

- `--privileged`
- `--pid=host`
- `--network=host`
- bind mounts for `/sys`, `/proc`, `/sys/fs/bpf`, `/lib/modules`
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
- phony bundle readiness rules in the main path
- host-owned runtime dependency discovery for ELF trees
- runner-owned x86 sysroot wrappers as a permanent architecture
- result copy-back logic
- shared mutable output roots guarded by locks
- run-time package installation on KVM or AWS hosts

## What Gets Simpler

When the migration is complete:

- `build.mk` mostly dispatches into app-native `make`, `cmake`, `cargo`, or
  containerized equivalents
- `workspace_layout.py` describes final artifacts, not guessed bundle roots
- `suite_entrypoint.py` launches work and records result paths, but does not
  stage benchmark outputs
- `aws_remote_prep.py` prepares the host, but does not synthesize a userspace
  runtime bundle

## Current Implementation State

### Canonical Container Layout

- [x] Put the architecture decision in a stable design document.
- [x] Make the repository reference a canonical container location instead of an
  ad-hoc or missing Dockerfile path.
- [x] Create fixed build container definitions for every active target
  combination we build locally.
  Current state: `runner/containers/runner-build.Dockerfile` is the canonical
  build image definition. Make builds it for both `linux/amd64` and
  `linux/arm64`.

### Build in Containers

- [x] Convert `runner` ARM64 build to the canonical build container path.
- [x] Convert x86_64 runner build away from the host toolchain path.
- [x] Convert `daemon` x86_64/ARM64 builds to canonical build containers.
- [x] Convert kernel and module builds to canonical build containers.
- [x] Convert test and micro helper builds to canonical build containers.
- [x] Keep generated micro BPF objects out of `micro/programs` and build them
  under `.cache/micro-programs/<arch>` via Make.
- [x] Convert x86_64 `libbpf` runtime production to the canonical x86_64 build
  container.
- [x] Convert `scx`, `bcc`, `tracee`, `tetragon`, `katran`, and
  `workload-tools` to fixed distro build containers.
- [x] Build native repo artifacts from per-arch scratch source/build roots
  instead of writing into shared checkouts.
- [x] Stop producing shared AWS kernel transport packages. AWS prep now calls
  the canonical kernel image and `.cache/repo-artifacts/<arch>/kernel-modules`
  Make targets, then syncs that modules tree to the host staging directory.

### Runtime Packaging

- [~] Replace portable wrapper generation with runtime container images wherever
  possible.
  Current state: ELF wrapper generation is container-only and no longer has a
  host/sysroot fallback, but the long-term runtime-container replacement is not
  complete.
- [x] Stop resolving glibc and loader paths from the host runner layer.
- [ ] Treat final Make targets as app artifacts or OCI image tags, not handmade
  runtime bundles.

### Run in Host-Privileged Containers

- [ ] Define per-app run container contracts for `bcc`, `tracee`, `tetragon`,
  `katran`, `scx`, and `bpftrace`.
- [ ] Mount only the host paths each app actually needs.
- [ ] Keep attach and topology logic as close to the app-native launcher as
  possible.

### Thin Orchestration

- [ ] Make `run_target_suite.py` resolve final artifacts and host/run contracts
  only.
- [x] Keep AWS/KVM prep from installing userspace packages at run time.
- [ ] Remove remaining bundle-root assumptions from transfer and consumption
  paths.

## Explicit Non-Goals

This migration does not mean:

- replacing the host kernel with a container kernel
- hiding all eBPF attach semantics behind generic abstractions
- forcing every app into the exact same launcher

The goal is narrower:

- compile in fixed containers
- run userspace in fixed containers when practical
- keep kernel ownership with the host
- keep build ownership with Make

## Current Direction

The repository should keep moving in one direction:

- away from hand-built runtime packaging
- away from host-synthesized sysroots
- away from copy-back result handling
- toward app-native build logic inside fixed containers
- toward host kernel + privileged run container execution
