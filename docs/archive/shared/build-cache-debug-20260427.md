# Build Cache Debug: vm-corpus / vm-e2e Runtime Image Rebuilds

Date: 2026-04-27
Workspace: `/home/yunwei37/workspace/bpf-benchmark`

## Summary

The repeated Katran gRPC / runtime image rebuilds are caused by an overly broad Make dependency set for `.cache/container-images/x86_64-runner-runtime.image.tar`.

The runtime image tar target is a normal file target, not `.PHONY`, but it depends on `RUNNER_RUNTIME_IMAGE_SOURCE_FILES`. That variable includes not only Docker/build inputs, but also Python/runtime files under `runner`, `micro`, `corpus`, and `e2e`. Therefore a Python-only edit such as `runner/libs/workload.py`, `corpus/driver.py`, or `e2e/cases/katran/case.py` makes Make consider the whole runtime image tar stale and reruns `docker build`, which can recompile Katran.

Current local state is different: the x86 image tar is currently newer than the relevant source dependencies, so `make -n image-runner-runtime-image-tar` does not rebuild the image. However, KVM prep still wants to re-extract `.cache/runtime-kernel/x86_64/bzImage` because that file is older than the image tar.

## Dependency Chain

`make vm-corpus` / `make vm-e2e` call:

```text
Makefile vm-corpus/vm-e2e
  -> python -m runner.libs.run_target_suite run x86-kvm <suite>
  -> runner.libs.run_target_suite._run_local_prep()
  -> runner.libs.workspace_layout.local_prep_targets()
  -> make real targets:
       .cache/container-images/x86_64-runner-runtime.image.tar
       daemon/target/release/bpfrejit-daemon
       .cache/runtime-kernel/x86_64/bzImage
```

The image tar target is defined in `runner/mk/build.mk`:

```make
$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
	docker build --platform linux/amd64 ...
	docker save -o "$@" "$(X86_RUNNER_RUNTIME_IMAGE)"

.PHONY: image-runner-runtime-image-tar
image-runner-runtime-image-tar: $(ACTIVE_RUNNER_RUNTIME_IMAGE_TAR)
```

So the phony target is only an alias. The real stamp/cache file is:

```text
.cache/container-images/x86_64-runner-runtime.image.tar
```

and it rebuilds whenever any prerequisite in `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` is newer.

## Files That Currently Invalidate The Image

`RUNNER_RUNTIME_IMAGE_SOURCE_FILES` includes these groups:

- `Makefile`, `runner/mk/build.mk`
- `runner/containers/runner-runtime.Dockerfile`, `.dockerignore`
- daemon Rust sources and daemon build metadata
- runner C/C++ sources and `vendor/llvmbpf`
- tests under `tests/unittest` and `tests/negative`
- micro BPF program sources
- kernel module sources under `module`
- Katran source tree under `runner/repos/katran`, excluding `_build`, `deps`, `.git`
- `vendor/libbpf`
- selected `vendor/linux-framework` sources, scripts, bpftool inputs, and kernel BPF files
- runner runtime files:
  - `runner/**/*.py`
  - `runner/**/*.yaml`
  - `runner/**/*.env`
  - excluding `runner/repos`, `__pycache__`, and build dirs
- all non-excluded files under `micro`, `corpus`, and `e2e`
- defconfigs: `vendor/bpfrejit_x86_defconfig`, `vendor/bpfrejit_arm64_defconfig`

Yes, Python file changes trigger image rebuilds today. I verified with Make's `-W` option without touching files:

```text
make --debug=b -n -W /home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py \
  /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar

Prerequisite '.../runner/libs/workload.py' is newer than target '.../x86_64-runner-runtime.image.tar'.
Must remake target '.../x86_64-runner-runtime.image.tar'.
docker build --platform linux/amd64 ...
docker save -o ".../x86_64-runner-runtime.image.tar" "bpf-benchmark/runner-runtime:x86_64"
```

The same happens for `corpus/driver.py` and `e2e/cases/katran/case.py`.

## Current Cache State

`ls -la .cache/container-images/`:

```text
total 33850220
drwxrwxr-x  2 yunwei37 yunwei37       4096 Apr 27 03:46 .
drwxr-xr-x 12 yunwei37 yunwei37       4096 Apr 27 17:02 ..
-rw-------  1 yunwei37 yunwei37 9235274752 Apr 17 20:38 .tmp-x86_64-runner-runtime.image.tar3026290143
-rw-------  1 yunwei37 yunwei37          0 Apr 15 02:01 .tmp-x86_64-runner-runtime.image.tar3159115983
-rw-------  1 yunwei37 yunwei37 9235130368 Apr 17 18:57 .tmp-x86_64-runner-runtime.image.tar3656680261
-rw-------  1 yunwei37 yunwei37          0 Apr 23 23:13 .tmp-x86_64-runner-runtime.image.tar819181616
-rw-------  1 yunwei37 yunwei37 7843557888 Apr 27 03:46 arm64-runner-runtime.image.tar
-rw-------  1 yunwei37 yunwei37 8348597760 Apr 27 19:08 x86_64-runner-runtime.image.tar
```

Relevant timestamps:

```text
2026-04-27 19:08:41.735195372 -0700 .cache/container-images/x86_64-runner-runtime.image.tar
2026-04-27 03:46:49.653218333 -0700 .cache/container-images/arm64-runner-runtime.image.tar
```

Newest relevant dependency candidates I checked are older than the x86 tar:

```text
2026-04-27 19:07:55 runner/libs/workload.py
2026-04-27 18:56:22 corpus/driver.py
2026-04-27 18:25:27 runner/libs/benchmark_catalog.py
2026-04-27 14:04:02 runner/containers/runner-runtime.Dockerfile
```

A pruned `find ... -newer .cache/container-images/x86_64-runner-runtime.image.tar` over the relevant runner/corpus/e2e/build inputs returned no source files. Newer `__pycache__` and result files exist, but those are excluded by the Make source lists and/or `.dockerignore`.

## Dry Run Results

`make -n vm-corpus` only prints the top-level Python command:

```text
"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "30"
```

That dry run does not execute Python, so it does not enter `_run_local_prep()` and cannot show the nested Make target decisions.

Direct image dry run:

```text
make -n image-runner-runtime-image-tar
make: Nothing to be done for 'image-runner-runtime-image-tar'.
```

Direct image target dry run:

```text
make -n /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar
make: '.../x86_64-runner-runtime.image.tar' is up to date.
```

Simulated KVM local prep dry run:

```text
make -n \
  /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar \
  /home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon \
  /home/yunwei37/workspace/bpf-benchmark/.cache/runtime-kernel/x86_64/bzImage

make: '.../x86_64-runner-runtime.image.tar' is up to date.
make: Nothing to be done for '.../daemon/target/release/bpfrejit-daemon'.
BPFREJIT_INSTALL_KERNEL_OUT_DIR=".../.cache/runtime-kernel/x86_64" \
  ".../runner/scripts/bpfrejit-install" --extract-kernel-only ".../.cache/container-images/x86_64-runner-runtime.image.tar"
```

The kernel extraction trigger is:

```text
Prerequisite '.../.cache/container-images/x86_64-runner-runtime.image.tar' is newer than target '.../.cache/runtime-kernel/x86_64/bzImage'.
```

Current timestamps:

```text
2026-04-27 19:08:41 .cache/container-images/x86_64-runner-runtime.image.tar
2026-04-26 21:05:45 .cache/runtime-kernel/x86_64/bzImage
2026-04-27 20:36:09 .cache/runtime-kernel/x86_64/manifest.json
2026-04-27 20:36:09 .cache/runtime-kernel/x86_64/kernel.release
```

This is separate from the Katran rebuild issue. It can make every KVM run perform Docker load/create/copy kernel extraction even when the image tar is already cached.

## PHONY / FORCE Check

No `.PHONY` is attached to the real image tar files:

```make
$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
```

The only related phony target is:

```make
.PHONY: image-runner-runtime-image-tar
image-runner-runtime-image-tar: $(ACTIVE_RUNNER_RUNTIME_IMAGE_TAR)
```

`FORCE` exists but is not used by the image tar targets. So this is not a `.PHONY`/`FORCE` bug. It is a dependency-set bug.

## Recent Commits

Recent commits include one real Dockerfile change and several Python/workload changes that currently invalidate the image tar:

- `273a0894 Fix stress-ng workloads: use explicit VM-safe stressor lists`
  - changed `corpus/driver.py`, `runner/libs/benchmark_catalog.py`, `runner/libs/workload.py`, tests
- `986ec3eb Switch corpus workloads to standard benchmarks (stress-ng, fio)`
  - changed multiple `runner/libs/app_runners/*.py`, `runner/libs/benchmark_catalog.py`, `runner/libs/workload.py`
- `5edf29e4 Expand workloads to trigger more BPF programs (140→171+ coverage)`
  - changed Python workload/app runner files
- `8afb4331 Fix default build config: add ARG TARGETPLATFORM in Dockerfile, add AWS key/subnet defaults`
  - changed `runner/containers/runner-runtime.Dockerfile`, `runner/libs/run_contract.py`, `runner/targets/aws-*.env`
- `e5badc7e`, `53b12634`
  - changed Python under `corpus`, `e2e`, `runner/libs`

Only `8afb4331` is a clear Dockerfile/runtime-image build input change. The Python-only commits should not force Katran/runtime image rebuilds for normal KVM/AWS runs.

## Recommended Fix

Split "heavy image build inputs" from "runtime Python/workload inputs".

For the image tar target, stop depending on Python/runtime files that are bind-mounted into the container at run time. `runner/libs/suite_commands.py` runs the container with:

```text
-v <host_workspace>:/home/yunwei37/workspace/bpf-benchmark
```

That mount hides the Python files baked into the image and makes the container execute the current workspace copy. Therefore Python changes should be picked up by the bind mount, not by rebuilding the runtime image.

Concretely:

1. In `runner/mk/build.mk`, create a narrower dependency variable for the image tar, for example `RUNNER_RUNTIME_IMAGE_BUILD_SOURCE_FILES`.
2. Keep heavy build inputs in that variable:
   - Dockerfile, `.dockerignore`, `Makefile`, `runner/mk/build.mk`
   - daemon Rust sources
   - runner C/C++ sources
   - micro BPF program sources
   - tests that compile into image artifacts
   - module sources and defconfigs
   - `vendor/libbpf`, `vendor/llvmbpf`, selected `vendor/linux-framework` inputs
   - Katran source inputs, with generated caches excluded
3. Remove these from the image tar prerequisites:
   - `RUNNER_RUNTIME_SOURCE_FILES`
   - `MICRO_RUNTIME_SOURCE_FILES` except sources actually compiled into image artifacts
   - `CORPUS_RUNTIME_SOURCE_FILES`
   - `E2E_RUNTIME_SOURCE_FILES`
4. Optionally clean up the Dockerfile so it no longer copies runtime Python/corpus/e2e files into the final image if the supported execution model always bind-mounts the workspace.
5. Add a regression check, for example:

```text
make -n -W /home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py \
  /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar
```

Expected after the fix: no `docker build` / `docker save` output.

Also fix the separate KVM kernel extraction stamp issue. Either touch the copied kernel image after `docker cp` in `runner/scripts/bpfrejit-install`, or make `.cache/runtime-kernel/x86_64` use an explicit extraction stamp that is updated after `--extract-kernel-only`. Otherwise KVM prep can keep re-extracting the kernel even when the image tar is up to date.
