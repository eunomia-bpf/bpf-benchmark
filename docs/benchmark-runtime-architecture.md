# Benchmark Runtime Architecture

Date: 2026-04-14
Status: Active hard-cut architecture

This document defines the active execution architecture for `micro`, `corpus`,
and `e2e`.

## Boundaries

The active architecture has four boundaries:

1. Host owns the kernel, boot state, privileges, `/lib/modules`, `/sys`, bpffs,
   cgroups, and network namespaces.
2. `runner-runtime.Dockerfile` owns user-space artifact builds, runtime
   dependencies, and target-arch kinsn modules baked into the image.
3. `runner-host-artifacts` owns host-coupled kernel image and `/lib/modules`
   export through
   `docker build --output`.
4. AWS host kernel installation is executed by the already-loaded runtime image
   as a privileged installer container that mounts the host root at `/host` and
   chroots into it for `depmod`, `dracut`, and `grubby`.
5. Suite drivers own result directory creation and benchmark process
   orchestration.

There is one runner image lineage. There is no separate `runner-build`
Dockerfile, no bpftrace static build image in this pipeline, and no
builder-stage artifact handoff into the runtime stage.

## Runner Image

The normal image path is:

```text
host make
  -> docker build --target runner-runtime
       -> COPY stable vendor inputs
       -> COPY build rules
       -> COPY and build native repo artifacts one repo layer at a time
       -> COPY and build runner, micro, and test artifacts
       -> COPY stable benchmark data
       -> COPY and build the daemon artifact
       -> COPY runtime Python scripts and config last
       -> COPY full kernel/module sources and build in-image kinsn .ko
       -> delete kernel/module build inputs, Go toolchain files, and build
          intermediates
  -> docker save .cache/container-images/<arch>-runner-runtime.image.tar
```

User-space artifacts are built in place inside the final runtime image:

```text
<host-checkout>/daemon/target/...
<host-checkout>/runner/build-...
<host-checkout>/tests/unittest/build...
<host-checkout>/tests/negative/build...
/opt/bpf-benchmark/repo-artifacts/<arch>
/opt/bpf-benchmark/workload-tools/<arch>
/opt/bpf-benchmark/micro-programs/<arch>
```

The `/opt/bpf-benchmark` prefix is not a builder-to-runtime copy boundary. It is
the final in-image artifact prefix written by `make image-userspace-artifacts`.
The root `Makefile` and `runner/mk` are build-only inputs and are removed before
the final runtime Python/config layer is copied.

## Host-Coupled Exports

Kernel image and `/lib/modules` outputs must exist outside the runtime image
because the host or guest boots them. They use the same Dockerfile lineage:

```text
host make
      -> docker build --target runner-host-artifacts --output type=local,dest=<repo>
       -> FROM runner-runtime-userspace
       -> COPY build rules
       -> COPY full kernel sources
       -> RUN make image-host-artifacts
       -> write outputs under /image-output
       -> FROM scratch
       -> export only /image-output contents
```

BuildKit exports the scratch stage back to repository paths:

```text
.cache/x86-kernel-build/...
.cache/arm64-kernel-build/...
.cache/aws-arm64/kernel-build/...
.cache/repo-artifacts/<arch>/kernel-modules/...
```

Kinsn modules are built into the runtime image from the same kernel build tree:

```text
make -C <kernel> O=<kernel-build> M=<module-source> MO=<export-dir> modules
```

Module source is not mirrored or staged into a transfer directory. AWS transfers
the saved runner image tar for suite execution; kinsn `.ko` files are already in
that image.

AWS kernel installation still mutates the target host, but the mutation is
driven through Docker:

```text
ssh target
  -> docker load -i .cache/container-images/<arch>-runner-runtime.image.tar
  -> docker run --privileged -i -v /:/host bpf-benchmark/runner-runtime:<arch>
       -> tar -C /host -xpf - kernel image and /lib/modules
       -> chroot /host depmod/dracut/grubby
```

The installer container uses the host's own `depmod`, `dracut`, and `grubby`
through `chroot /host`. It is not a remote build path.

## Runtime Execution

After the host boots the target kernel, suites run in the already-loaded runner
image:

```text
docker run ... bpf-benchmark/runner-runtime:<arch> \
  python3 -m runner.suites.<suite> --workspace <host-checkout> ...
```

The runtime container is privileged because eBPF programs attach to the host
kernel. It mounts only explicit host resources such as:

```text
/sys
/sys/fs/bpf
/sys/kernel/debug
/lib/modules:ro
/boot:ro
micro/results
corpus/results
e2e/results
tests/results
```

The whole host repository is not mounted over the image workspace.

## Results

Benchmark results are written directly into shared suite roots:

```text
micro/results
corpus/results
e2e/results
tests/results
```

There is no second benchmark artifact directory, copy-back result path, or
"find newest directory" result handling.

## Forbidden Patterns

These patterns are not allowed on the main path:

- standalone `runner-build.Dockerfile`
- `COPY --from` builder-to-runtime artifact handoff into `runner-runtime`
- bpftrace static build image as a first-class pipeline image
- host-side runtime containers invoking build tools
- old suite self-container arguments
- host `.cache` user-space artifact roots inside the runtime image
- runtime bind mount of the whole host workspace over the image workspace
- runtime bind mount of host `module/` over the image workspace
- run-time package installation on KVM or AWS hosts for benchmark userspace

## Invariants

The repository keeps these invariants:

- Dockerfile owns the runner image build boundary.
- Make owns the image-side artifact graph.
- Host `.cache` remains only for exported host-coupled artifacts, image tars,
  logs, and transient executor state.
- Suite drivers run from the host checkout path baked into `runner-runtime`.
- Host kernel bootloader installation stays outside the Dockerfile build, but
  executes through the runtime image as a privileged Docker container; kernel
  compilation and `modules_install` staging also run in Docker.
