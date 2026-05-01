# Katran Artifact Build Cache Fix

Date: 2026-04-30 America/Vancouver.

## Root Cause

`/tmp/vm-corpus.log` started with:

```text
Error response from daemon: manifest unknown
GHCR katran-artifacts image unavailable, building locally: bpf-benchmark/katran-artifacts:x86_64
```

The local fallback then rebuilt the full Katran stack in
`[katran-artifacts-build 19/19]`, including `facebookincubator/katran`,
folly, and the Katran CMake install.

Two separate issues combined:

1. The GHCR tags are not usable from this host. Direct pulls after
   `docker login ghcr.io` still fail with `manifest unknown` for both:
   - `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64`
   - `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136`
2. The Katran tar target used broad prerequisites:
   - `BUILD_RULE_FILES`, so any `runner/mk/build.mk` edit invalidated Katran.
   - `VENDOR_LINUX_RUNTIME_SOURCE_FILES`, so unrelated kernel runtime files
     such as `kernel/bpf/syscall.c` invalidated Katran even though Katran only
     needs bpftool plus Katran source.

`docker builder prune -af` removed the BuildKit layer cache, so once the target
entered the local fallback path there was no layer cache left to avoid the folly
rebuild.

## GHCR State

Commands run:

```bash
docker pull --platform linux/amd64 ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64
docker pull --platform linux/amd64 ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136
gh api '/orgs/eunomia-bpf/packages?package_type=container&per_page=100'
curl -L https://github.com/orgs/eunomia-bpf/packages/container/package/bpf-benchmark-katran-artifacts
```

Results:

- Docker pull returns `manifest unknown`.
- `gh api` cannot list packages with the current token because it lacks
  `read:packages`.
- The public GitHub package pages return `404`.
- The current repo workflows do not push these package tags; commit `a27b8100`
  added Make targets for push/pull, but no CI step runs them.

I did not push images to GHCR because this task explicitly says not to push
without authorization. The already built local image is tagged locally as both
`bpf-benchmark/katran-artifacts:x86_64` and
`ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64`, but that GHCR tag
is only local until someone runs `docker push`.

## Other Image Layers

- `kernel-fork`: affected by the same GHCR availability problem. The current
  tag `x86_64-ff4e136` returns `manifest unknown`, so a missing or stale local
  kernel-fork tar still falls back to a local kernel build. Its source
  dependency set is intentionally broad because the output is the kernel image,
  modules, and headers.
- `runner-runtime`: expected to rebuild when `runner/mk/build.mk`, daemon,
  bpfopt, C++ runner, tests, kinsn modules, or runtime Python/YAML change. The
  important behavior is that it depends on `x86_64-katran-artifacts.image.tar`
  and now loads that tar instead of scheduling a Katran artifact rebuild for
  daemon/bpfopt/kernel syscall edits.
- `runner-runtime-bpfopt-artifacts` and `runner-runtime-daemon-artifact`: these
  are supposed to rebuild for Rust changes and do not affect Katran artifacts.
- `runner-runtime-kinsn-artifacts`: supposed to rebuild for `module/` changes;
  it is separate from Katran and kernel-fork.

## Options Considered

1. Push the current Katran and kernel-fork images to GHCR now.
   This would fix cold pulls, but it requires explicit push authorization and a
   token with `write:packages`. Not done.

2. Keep the GHCR fallback and only document the miss.
   Rejected because it still hides an unavailable remote cache behind a
   10-20 minute local rebuild.

3. Narrow Katran image prerequisites.
   Selected. This prevents daemon, bpfopt, runner Python, and unrelated kernel
   BPF syscall edits from invalidating Katran artifacts.

4. Add BuildKit cache for the Katran build root.
   Selected as a second line of defense. If a real Katran rebuild is required
   and the builder cache has not been pruned, `build_katran.sh` can reuse the
   cached dependency/install tree instead of rebuilding folly from scratch.

## Changes

- Added `runner/mk/katran-artifacts.mk` and moved only the Katran artifact
  recipe into it.
- Changed `KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES` to depend on:
  - root `Makefile`
  - `runner/mk/katran-artifacts.mk`
  - `runner/containers/katran-artifacts.Dockerfile`
  - `.dockerignore`
  - sparse Katran source paths actually used by the Dockerfile
  - bpftool/libbpf inputs actually needed for the Katran BPF build
- Removed `runner/mk/build.mk` and broad `VENDOR_LINUX_RUNTIME_SOURCE_FILES`
  from Katran artifact invalidation.
- Changed `katran-artifacts.Dockerfile` to copy only
  `vendor/linux-framework/kernel/bpf/disasm.c` and `disasm.h` instead of the
  whole `kernel/bpf` directory.
- Added a BuildKit cache mount for `/tmp/bpf-benchmark-build` in the Katran
  artifact build stage. Both Katran's build root and cached install root live
  under that mount; the Docker layer copies the cached install root into
  `/artifacts/katran` at the end. This keeps `build_katran.sh` dependency
  marker files consistent with the installed folly/Katran artifacts.

## Current Local Cache Handling

After these source changes, the existing Katran tar is expected to be older than
the changed Dockerfile/rule file. To avoid a metadata-only rebuild of the same
already-built Katran artifact on this host, refresh the tar from the local image
without rebuilding:

```bash
tmp=.cache/container-images/x86_64-katran-artifacts.image.tar.$$.tmp
docker save -o "$tmp" bpf-benchmark/katran-artifacts:x86_64
mv -f "$tmp" .cache/container-images/x86_64-katran-artifacts.image.tar
```

This updates the tar timestamp but does not compile Katran or folly.

## Validation

Allowed validation only; no `make vm-corpus`, `make vm-e2e`, or `make vm-micro`
was run.

Use:

```bash
make --dry-run --debug=b image-katran-artifacts-image-tar RUN_TARGET_ARCH=x86_64
make --dry-run image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64
```

Expected after refreshing the local Katran tar:

- `image-katran-artifacts-image-tar` prints `Nothing to be done`.
- `image-runner-runtime-image-tar` may rebuild the runner runtime because
  `runner/mk/build.mk` changed, but it should not schedule the Katran pull/build
  recipe.

Dependency audit:

```bash
make --no-print-directory RUN_TARGET_ARCH=x86_64 \
  --eval 'print-%: ; @$(file >/tmp/$*.txt,$($*))' \
  print-KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES
tr ' ' '\n' </tmp/KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES.txt \
  | sed '/^$/d' \
  | rg '/(daemon|bpfopt|corpus|e2e|micro|runner/libs|runner/suites|runner/targets)/|/kernel/bpf/syscall\.c$|/kernel/bpf/verifier\.c$'
```

Expected: no matches.

## GHCR Follow-Up

To make cold builders skip Katran/folly without relying on host tar files, an
authorized operator still needs to publish the package tags:

```bash
gh auth refresh -h github.com -s read:packages -s write:packages
gh auth token | docker login ghcr.io -u yunwei37 --password-stdin
make image-push-katran-artifacts RUN_TARGET_ARCH=x86_64
make image-push-kernel-fork RUN_TARGET_ARCH=x86_64
```

If the packages should be usable without login, make them public after the first
push with the commands in `docs/ghcr-image-cache.md`.
