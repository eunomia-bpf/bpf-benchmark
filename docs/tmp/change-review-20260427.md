# Change Review - 2026-04-27

Scope: reviewed current uncommitted changes with `git diff HEAD`, focusing on the runtime image split, Katran artifact image, no host workspace bind mount, workload changes, and app discovery behavior.

Verification run:
- `docker build --platform linux/amd64 --target katran-artifacts --build-arg IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark --build-arg IMAGE_BUILD_JOBS=4 --build-arg RUN_TARGET_ARCH=x86_64 -t bpf-benchmark/katran-artifacts:review -f runner/containers/katran-artifacts.Dockerfile .`: OK.
- `python3 -m py_compile runner/libs/suite_commands.py runner/libs/kvm_executor.py runner/libs/aws_executor.py runner/libs/workload.py runner/libs/app_runners/bpftrace.py`: OK.
- `make -n -W corpus/driver.py -o /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-katran-artifacts.image.tar /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar RUN_TARGET_ARCH=x86_64`: PROBLEM, still schedules a runtime `docker build`.

## 1. runner/containers/runner-runtime.Dockerfile: PROBLEM

OK:
- Layer order mostly matches the intended frequency model: base OS and apt first; app artifact imports next; kernel and kinsn artifacts before native runner/micro/test builds; Rust daemon after native build; Python/config/corpus/e2e copied last.
- `KATRAN_IMAGE` is used through `FROM ${KATRAN_IMAGE} AS runner-runtime-katran-upstream`, and `COPY --from=runner-runtime-katran-upstream /artifacts/katran /artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran` matches the artifact image layout produced by `katran-artifacts.Dockerfile`.
- After removing Katran source compilation from runtime, `bpftool` is still built in the final runtime native layer through `make runner-build-bpftool BPFTOOL_OUTPUT=...`.
- `etcd-server` and `nftables` are in the unified base apt list, and the old later `apt-get install` block for those packages is gone.
- Kernel artifact copy paths match the artifact producer: `/artifacts/kernel`, `/artifacts/modules`, `/artifacts/kinsn`, and `/artifacts/manifest.json`.
- `otelcol-ebpf-profiler` download remains in the app-artifacts stage.
- Runtime Python, YAML/config, corpus, and e2e files are copied at the end of the Dockerfile.

PROBLEM:
- The base apt list still includes Katran build-only gRPC/protobuf packages: `libgrpc++-dev`, `libprotobuf-dev`, `protobuf-compiler`, and `protobuf-compiler-grpc`. The app-artifacts stage also still checks `command -v grpc_cpp_plugin`, even though Katran is no longer compiled in the runtime Dockerfile. These packages are not purged later, so the final runtime image keeps unnecessary dev/compiler tooling.
- Fix suggestion: remove the runtime `grpc_cpp_plugin` check and replace build-only gRPC/protobuf packages with the runtime shared-library packages needed by the prebuilt `katran_server_grpc`, or install those dev/compiler packages only in a build stage that does not survive into the final runtime image. Validate with `ldd` on `/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/bin/katran_server_grpc` inside the runtime image.

## 2. runner/containers/katran-artifacts.Dockerfile: OK

OK:
- The Katran artifact image builds successfully for `linux/amd64` with `RUN_TARGET_ARCH=x86_64`.
- `REPO_KATRAN_ROOT=/artifacts/katran` is accepted by the `build.mk` rules. The build produced `/artifacts/katran/bin/katran_server_grpc` and the expected BPF object files.
- System gRPC/protobuf packages are compatible with Katran's CMake path in this build. `grpc_cpp_plugin` resolves from the system package, and CMake found system `gRPC::grpc++`.
- The Dockerfile builds a local `bpftool` before invoking the Katran artifact make target, so the Katran build has the tool it needs without depending on runtime Dockerfile compilation.

Note:
- The apt package set is sufficient but broad. Packages such as `bpfcc-tools`, `bpftrace`, `python3-bpfcc`, and `libboost-all-dev` are probably larger than necessary for this artifact-only image. This is not a correctness blocker, but it is worth trimming after the image split is stable.

## 3. runner/mk/build.mk: PROBLEM

OK:
- `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` itself no longer directly includes the runtime Python tree as source input. It is limited to build rules, Dockerfile inputs, daemon/native/test/kernel-related source groups, and script source groups.
- Katran artifact image targets use the new `katran-artifacts.Dockerfile`, pass `KATRAN_IMAGE` into the runtime build, and save/load the architecture-specific Katran artifact image tar.

PROBLEM:
- The runtime image tar target depends on `RUNNER_RUNTIME_IMAGE_INPUT_FILES`, which includes `RUNNER_RUNTIME_IMAGE_LAYER_FILES`, and that includes `RUNNER_RUNTIME_SOURCE_FILES`, `CORPUS_RUNTIME_SOURCE_FILES`, and `E2E_RUNTIME_SOURCE_FILES`. In practice, touching Python still triggers a runtime `docker build`.
- Evidence: forcing `corpus/driver.py` newer with `make -n -W corpus/driver.py ... x86_64-runner-runtime.image.tar RUN_TARGET_ARCH=x86_64` schedules `docker build --target runner-runtime`.
- This conflicts with the stated check that changing Python should not trigger Docker build. With no host workspace bind mount, the image still needs some way to receive changed Python; if the requirement is literal, the build graph needs a separate lightweight Python/config data delivery mechanism or overlay image target that does not rebuild the heavy runtime image.
- Fix suggestion: split the expensive compiled runtime image from the top Python/config/corpus/e2e layer. For example, build and cache a heavy base runtime image from compile inputs only, then create a separate lightweight runtime overlay image or artifact containing only Python/config/data. The top layer may still be rebuilt, but the heavy Dockerfile stages must stay cached and should not depend on Python source timestamps.

## 4. runner/libs/suite_commands.py: OK

OK:
- The runtime container command no longer bind-mounts the host workspace into the container.
- Python code is available because the Dockerfile bakes `runner/`, `corpus/`, `e2e/`, configs, and helper files into the runtime image under `IMAGE_WORKSPACE`. The container also runs with `PYTHONPATH=${IMAGE_WORKSPACE}`.
- Result directory bind mounts are still present through `host_results_dir:container_results_dir`.
- Runtime tmp bind mount remains available for local/AWS paths, and KVM can disable it with `mount_runtime_tmp=False`.

## 5. runner/libs/kvm_executor.py: PROBLEM

OK:
- Docker run inside the VM uses the loaded runtime image, so the container sees the code baked into the image rather than a mounted host workspace.
- `rwdirs` still mount host-side paths into the VM, which is needed for the image tar and install script flow. That is separate from the runtime container and does not violate the no host workspace bind-mount rule for the container.
- Result directories are still created outside the container and mounted into the container command.

PROBLEM:
- The default x86 KVM kernel path is inconsistent. `workspace_layout.kvm_kernel_image_path()` and `build.mk` now use `.cache/runtime-kernel/x86_64/bzImage`, but `runner/targets/x86-kvm.env` still defaults `TARGET_KVM_KERNEL_IMAGE_DEFAULT` to `.cache/x86-kernel-build/arch/x86/boot/bzImage`.
- `make vm-corpus` may mask this by exporting `BZIMAGE`, but direct use of the target env defaults points at the stale path. That conflicts with the "default config must work" rule.
- Fix suggestion: update `runner/targets/x86-kvm.env` to default to `.cache/runtime-kernel/x86_64/bzImage`, or derive the default from the same workspace layout helper used by the build rules.

## 6. runner/libs/aws_executor.py: OK

OK:
- Workspace sync was removed. The remote host receives code through the runtime Docker image tar, then loads that image with `docker load`.
- No remaining calls to the deleted workspace sync helpers were found.
- Remote result directories are still created under the remote workspace path and mounted into the runtime container as result output directories.
- The runtime container command uses the baked image code path and does not require a host workspace bind mount.

## 7. runner/libs/workload.py: OK

OK:
- Stress-ng class workloads now run one stressor per `stress-ng` invocation instead of combining the class into one command.
- Per-stressor ops limits are explicit and covered by the updated workload tests.
- Timeout is computed per stressor as `max(seconds + 15, seconds * 4)`. This means total wall-clock time can grow with the number of stressors, which matches the new independent-stressor execution model.
- Test coverage for command generation and selected stressor limits passes.

Note:
- `_STRESS_NG_STRESSOR_ARGS` and `_STRESS_NG_STRESSOR_OPS` still contain entries for `syscall`, while `_STRESS_NG_OS_STRESSORS` no longer selects it. This is stale but harmless. It can be removed for clarity.

## 8. runner/libs/app_runners/bpftrace.py: OK

OK:
- Removing the name-hint filter does not include pre-existing system BPF programs, because `start()` snapshots `before_ids` before launching bpftrace and discovery uses `programs_after(before_ids)`.
- `programs_after(before_ids)` returns only program IDs that appeared after the snapshot, so existing system programs are excluded by ID rather than by name/type.
- A concurrently loaded unrelated BPF program could still appear after the snapshot and be included. In the controlled benchmark flow this is acceptable, and it is consistent with the no ReJIT filtering rule.

## 9. Overall consistency: PROBLEM

OK:
- The no host workspace bind-mount direction is consistent across `suite_commands.py`, KVM container execution, and AWS remote execution.
- `.dockerignore` was updated for the new image split. It excludes large build/cache outputs and allows `runner/repos/katran/**`, so the Katran artifact Dockerfile can use vendored Katran source when present.
- Removed app inventory in `runner/repos.yaml` is consistent with the supported/removed app list in the repo instructions.

PROBLEM:
- Runtime image rebuild semantics do not match the stated Python-change expectation. Python changes still rebuild the runtime image target, even though they should not invalidate heavy app/kernel/daemon/native compile layers.
- KVM default kernel path is stale in `runner/targets/x86-kvm.env`.
- Runtime image apt packages still include Katran build-only gRPC/protobuf tooling after Katran compilation moved to the artifact image.

Fix priority:
1. Split heavy runtime image dependencies from Python/config/data layer dependencies in `build.mk`.
2. Fix `runner/targets/x86-kvm.env` kernel default path.
3. Trim or stage-isolate runtime gRPC/protobuf dev/compiler packages and remove the obsolete `grpc_cpp_plugin` runtime check.
