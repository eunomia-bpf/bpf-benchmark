# Runner Image Hard-Cut Design

Date: 2026-04-14
Status: implemented

## Design Goals

- Use Docker as the build boundary. Host Make calls `docker build`; it does not
  enter a runtime container to invoke build tools.
- Keep one runner image lineage. The image that builds user-space artifacts is
  the image that runs benchmark suites.
- Remove builder-to-runtime artifact handoff. No `COPY --from` for repo
  artifacts, workload tools, daemon, runner, or micro programs in the
  `runner-runtime` target.
- Keep vendor and third-party repository layers before local runner, daemon, and
  Python runtime layers. Python-only changes must not invalidate native repo
  artifact builds.
- Keep host `.cache` only for artifacts that must leave the image: image tars,
  kernel builds, exported kernel modules, executor logs, and AWS/KVM state.
- Use one x86 kernel/config for both `x86-kvm` and `aws-x86`; ARM64 remains a
  separate kernel family.
- Run suites from the host checkout path inside the image. Do not mount the
  whole host repo over that path.
- Export host-coupled kernel/module artifacts with
  `docker build --target runner-host-artifacts --output`.
- Bake target-arch kinsn `.ko` files into the runtime image instead of
  transferring `module/<arch>` to the target.
- Execute AWS host kernel installation through the loaded runtime image as a
  privileged Docker container. The container may mutate the target host, but it
  must not compile on the target.
- No alternate suite self-containerization path.

## Final Shape

User-space artifacts:

```text
host make
  -> docker build --target runner-runtime
       -> COPY stable vendor inputs
       -> COPY build rules
       -> COPY and build native repo artifacts one repo layer at a time
       -> COPY and build runner, micro, and test artifacts
       -> delete build-only source trees and make rules from the final filesystem
       -> COPY stable benchmark data
       -> COPY and build the daemon artifact
       -> COPY runtime Python scripts and config last
       -> COPY full kernel/module sources and build target-arch kinsn .ko
       -> delete Go toolchain files and build-only intermediates
       -> docker save .cache/container-images/<arch>-runner-runtime.image.tar
  -> docker run bpf-benchmark/runner-runtime:<arch> for benchmark suites
```

Host-coupled kernel image and `/lib/modules` artifacts:

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

AWS target installation:

```text
host python executor
  -> scp runtime image tar to AWS target
  -> ssh sudo docker load -i <runtime-image.tar>
  -> stream kernel image and /lib/modules into:
       sudo docker run --privileged -i -v /:/host bpf-benchmark/runner-runtime:<arch>
  -> installer container extracts into /host and runs chroot /host depmod/dracut/grubby
  -> reboot target host into the installed kernel
```

Runtime in-image artifact roots:

```text
/opt/bpf-benchmark/repo-artifacts/<arch>
/opt/bpf-benchmark/workload-tools/<arch>
/opt/bpf-benchmark/micro-programs/<arch>
```

Host-exported roots:

```text
.cache/container-images/<arch>-runner-runtime.image.tar
.cache/*-kernel-build/...
.cache/repo-artifacts/<arch>/kernel-modules/...
```

In-image kinsn root:

```text
<image-workspace>/module/<arch>/*.ko
```

## Completed Todo

- Deleted `runner/containers/runner-build.Dockerfile`.
- Removed bpftrace static build image handling from the runner pipeline.
- Moved user-space artifact builds into `runner-runtime.Dockerfile`.
- Removed host-side build `docker run` recipes from `Makefile` and
  `runner/mk/build.mk`.
- Removed host `.cache` user-space artifact roots from runtime consumption.
- Removed old suite self-container CLI args.
- Changed AWS/KVM suite execution to load and run the saved runtime image.
- Changed remote transfer roots to image tar only for suite execution.
- Moved AWS target kernel installation into a privileged runtime-image
  container, and removed the separate suite-time image load.
- Changed kinsn module handling to kernel `MO=` output inside the runtime image
  instead of source staging or target transfer.
- Unified `x86-kvm` and `aws-x86` onto one x86 kernel build/config path.
- Split runtime Dockerfile artifact builds into native repo, workload-tool,
  runner, micro-program, test, and daemon targets.
- Moved stable vendor inputs before build rules, and kept runtime Python files out
  of the early build-rule layer.
- Removed build-only `Makefile` and `runner/mk` from the final runtime
  filesystem after all image-side artifact targets finish.
- Removed `FORCE` from runtime image tar targets; source dependency lists now
  decide when the saved image needs to be rebuilt.
- Pruned Docker build context for unused repo checkouts, generated build trees,
  pycache, and stale vendor build outputs.
- Updated architecture docs to the new single-lineage design.

## Notes

- The runtime Dockerfile no longer uses `COPY .`. It copies only the source
  groups needed by each layer. Vendor inputs are copied before make rules,
  native artifacts are built before daemon and Python layers, and
  `IMAGE_WORKSPACE` is still passed from `ROOT_DIR`, so the image path matches
  the host checkout path.
- `cp <defconfig> <build-dir>/.config` remains as kernel config initialization
  inside the image-side kernel recipe; it is not an artifact transport path.
- AWS remote result collection uses tar-over-SSH. No directory-sync tool is
  required for build staging or result collection.
- AWS setup/suite staging sends the runtime image tar only; kinsn modules are
  already present in the image.
- The base image is Ubuntu 24.04 to match the host family. Compiler defaults are
  `/usr/bin/gcc` and `/usr/bin/g++`, LLVM defaults to
  `/usr/lib/llvm-18/lib/cmake/llvm`, and Katran system library paths are derived
  with `pkg-config` instead of hard-coded distro library directories.
