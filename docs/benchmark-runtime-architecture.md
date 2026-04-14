# Benchmark Runtime Architecture

Date: 2026-04-14
Status: Active hard-cut architecture

This document defines the active execution architecture for `micro`, `corpus`,
and `e2e`.

## Boundaries

The active architecture has four boundaries:

1. Host owns the kernel, boot state, privileges, `/lib/modules`, `/sys`, bpffs,
   cgroups, and network namespaces.
2. `runner-runtime.Dockerfile` owns user-space artifact builds and user-space
   runtime dependencies.
3. `runner-host-artifacts` owns host-coupled kernel/module export through
   `docker build --output`.
4. Suite drivers own result directory creation and benchmark process
   orchestration.

There is one runner image lineage. There is no separate `runner-build`
Dockerfile, no bpftrace static build image in this pipeline, and no
builder-stage artifact handoff into the runtime stage.

## Runner Image

The normal image path is:

```text
host make
  -> docker build --target runner-runtime
       -> COPY repo into the host checkout path inside the image
       -> RUN make image-userspace-artifacts
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

## Host-Coupled Exports

Kernel and kinsn module outputs must exist outside the runtime image because the
host or guest boots and loads them. They use the same Dockerfile lineage:

```text
host make
  -> docker build --target runner-host-artifacts --output type=local,dest=<repo>
       -> FROM runner-runtime
       -> RUN make image-host-artifacts
       -> write outputs under /image-output
```

BuildKit exports `/image-output` back to repository paths:

```text
.cache/x86-kernel-build/...
.cache/arm64-kernel-build/...
.cache/aws-x86/kernel-build/...
.cache/aws-arm64/kernel-build/...
.cache/repo-artifacts/<arch>/kernel-modules/...
module/<arch>/*.ko
.cache/aws-x86/module/x86/*.ko
```

The kinsn module export uses kernel `MO=` support:

```text
make -C <kernel> O=<kernel-build> M=<module-source> MO=<export-dir> modules
```

Module source is not rsynced or staged into the output directory.

## Runtime Execution

After the host boots the target kernel, suites run in the saved runner image:

```text
docker load -i .cache/container-images/<arch>-runner-runtime.image.tar
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
module
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
- `COPY --from` builder-to-runtime artifact handoff
- bpftrace static build image as a first-class pipeline image
- host-side `docker run ... make/cmake/cargo` build recipes
- suite self-container fallback arguments
- host `.cache` user-space artifact roots inside the runtime image
- runtime bind mount of the whole host workspace over the image workspace
- run-time package installation on KVM or AWS hosts for benchmark userspace

## Invariants

The repository keeps these invariants:

- Dockerfile owns the runner image build boundary.
- Make owns the image-side artifact graph.
- Host `.cache` remains only for exported host-coupled artifacts, image tars,
  logs, and transient executor state.
- Suite drivers run from the host checkout path baked into `runner-runtime`.
- Host kernel ownership stays outside the container.
