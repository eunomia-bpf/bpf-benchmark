# Runner Image Hard-Cut Design

Date: 2026-04-14
Status: implemented

## Design Goals

- Use Docker as the build boundary. Host Make calls `docker build`; it does not
  enter a build container with `docker run ... make`.
- Keep one runner image lineage. The image that builds user-space artifacts is
  the image that runs benchmark suites.
- Remove builder-to-runtime artifact handoff. No `COPY --from` for repo
  artifacts, workload tools, daemon, runner, or micro programs.
- Keep host `.cache` only for artifacts that must leave the image: image tars,
  kernel builds, exported kernel modules, executor logs, and AWS/KVM state.
- Run suites from the host checkout path inside the image. Do not mount the
  whole host repo over that path.
- Export host-coupled kernel/module artifacts with
  `docker build --target runner-host-artifacts --output`.
- No fallback or compatibility path for suite self-containerization.

## Final Shape

User-space artifacts:

```text
host make
  -> docker build --target runner-runtime
       -> COPY repo into the host checkout path inside the image
       -> RUN make image-userspace-artifacts
  -> docker save .cache/container-images/<arch>-runner-runtime.image.tar
  -> docker run bpf-benchmark/runner-runtime:<arch> for benchmark suites
```

Host-coupled kernel/module artifacts:

```text
host make
  -> docker build --target runner-host-artifacts --output type=local,dest=<repo>
       -> FROM runner-runtime
       -> RUN make image-host-artifacts
       -> write outputs under /image-output
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
module/<arch>/*.ko
.cache/aws-x86/module/x86/*.ko
```

## Completed Todo

- Deleted `runner/containers/runner-build.Dockerfile`.
- Removed bpftrace static build image handling from the runner pipeline.
- Moved user-space artifact builds into `runner-runtime.Dockerfile`.
- Removed host-side build `docker run` recipes from `Makefile` and
  `runner/mk/build.mk`.
- Removed host `.cache` user-space artifact roots from runtime consumption.
- Removed suite fallback CLI args and `run_in_runtime_container`.
- Changed AWS/KVM suite execution to load and run the saved runtime image.
- Changed remote transfer roots to image tar plus explicit module trees.
- Changed kinsn module export to kernel `MO=` output instead of source staging.
- Updated architecture docs to the new single-lineage design.

## Notes

- Dockerfile `COPY . ${IMAGE_WORKSPACE}` is still required to put the
  repository into the image. `IMAGE_WORKSPACE` is passed from `ROOT_DIR`, so the
  image path matches the host checkout path. The removed copy path is
  builder-to-runtime artifact copy and host `.cache` user-space artifact copy.
- `cp <defconfig> <build-dir>/.config` remains as kernel config initialization
  inside the image-side kernel recipe; it is not an artifact transport path.
- `rsync` remains only for AWS remote transport/results. It is no longer used as
  a local build staging mechanism.
- The base image is Ubuntu 24.04 to match the host family. Compiler defaults are
  `/usr/bin/gcc` and `/usr/bin/g++`, LLVM defaults to
  `/usr/lib/llvm-18/lib/cmake/llvm`, and Katran system library paths are derived
  with `pkg-config` instead of hard-coded distro library directories.
