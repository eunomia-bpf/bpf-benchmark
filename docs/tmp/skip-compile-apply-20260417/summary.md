# Skip-Compile Apply Summary

## Patch apply

- Base: `main` at `0f29f61f Runtime Image Phase 2`.
- `docs/tmp/skip-compile-migration-20260416/build-mk-patch.diff` applied cleanly with `git apply`.
- `docs/tmp/skip-compile-migration-20260416/dockerfile-patch.diff` failed `git apply --check` against `runner/containers/runner-runtime.Dockerfile` because Phase 2 had already reshaped the runtime Dockerfile around the single `/artifacts` image layout. The Dockerfile changes were merged manually.

## Conflict resolution

- Kept the Phase 2 single-artifact layout in the final runtime image:
  - `/artifacts/kernel`
  - `/artifacts/modules`
  - `/artifacts/kinsn`
  - `/artifacts/manifest.json`
- Removed runtime-image source builds for BCC/libbpf-tools, bpftrace, Tracee, Tetragon, SCX, and workload tools from `runner/mk/build.mk`.
- Kept the Katran source build path because the benchmark still consumes Katran repo artifacts.
- Switched distro-provided tools to Ubuntu packages in the runtime image:
  - `bpfcc-tools`
  - `python3-bpfcc`
  - `bpftrace`
  - `rt-tests`
  - `sysbench`
  - `wrk`
- Removed `BPFREJIT_WORKLOAD_TOOL_BIN_DIR` from the runtime image environment so workload discovery uses `PATH`.
- Added compatibility symlinks under `/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}` for `tracee`, `tetragon`, and `scx`.

## Upstream binary extraction

- Tracee is copied from `docker.io/aquasec/tracee:0.24.1@sha256:cfbbfee972e64a644f6b1bac74ee26998e6e12442697be4c797ae563553a2a5b` with `FROM --platform=$TARGETPLATFORM`.
  - Installed `/tracee/tracee` and `/tracee/tracee-ebpf` into `/artifacts/tracee/bin/`.
- Tetragon is copied from `quay.io/cilium/tetragon:v1.6.1@sha256:ff96ace3e6a0166ba04ff3eecfaeee19b7e6deee2b7cdbe3245feda57df5015f` with `FROM --platform=$TARGETPLATFORM`.
  - Installed `/usr/bin/tetragon` into `/artifacts/tetragon/bin/`.
  - Copied `/var/lib/tetragon/*.o` into `/artifacts/tetragon/`.

## SCX fallback

- Checked the latest stable sched-ext/scx release: `v1.1.0`.
- The `v1.1.0` release has no prebuilt binary assets, so the Dockerfile uses the requested last-resort fallback:
  - clone `https://github.com/sched-ext/scx.git` at pinned tag `v1.1.0`
  - build `scx_rusty` for the target architecture
  - install `/artifacts/scx/bin/scx_rusty`
  - install `/artifacts/scx/scx_rusty_main.bpf.o`

## Image size

- Previous Phase 2 runtime image tar size: `8.8G`.
- New `x86_64` runtime image tar size: `8.7G`.
- Tar path: `.cache/container-images/x86_64-runner-runtime.image.tar`.

## Verification

- `make image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64`: passed.
- `docker load -i .cache/container-images/x86_64-runner-runtime.image.tar`: passed.
- Runtime artifact structure check:
  - `/artifacts/kernel`
  - `/artifacts/modules`
  - `/artifacts/kinsn`
  - `/artifacts/user`
  - `/artifacts/tracee`
  - `/artifacts/tetragon`
  - `/artifacts/scx`
- Runtime tool check passed for:
  - `sysbench`
  - `wrk`
  - `hackbench`
  - `bpftrace`
  - `execsnoop-bpfcc`
  - `scx_rusty`
  - `tracee`
  - `tetragon`
- `make vm-micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=50`: passed.
  - `simple` benchmark completed in the VM.
  - Output metadata: `micro/results/x86_kvm_micro_20260418_004726_916783/metadata.json`.

Full `make vm-micro` was not run in this apply pass; the known `bitcount/llvmbpf` generator/config mismatch remains out of scope.
