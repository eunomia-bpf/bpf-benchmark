# AWS / KVM Runner Cleanup

## Goal

The canonical runner must support:

- `x86-kvm`
- `aws-x86`
- `aws-arm64`

And the canonical suites must remain:

- `test`
- `micro`
- `corpus`
- `e2e`

The cleanup rule is strict:

- build logic belongs to `Makefile` / `CMakeLists.txt` / `Cargo`
- Python stays for orchestration, contract parsing, remote execution, and result handling
- no second control plane
- root `Makefile` plus `runner/mk/*.mk` are the single active Make-side build surface
- no bundle-cache / version-cache design
- no patching third-party source trees

## Current Control Flow

The active path is:

`Makefile -> runner.libs.run_target_suite -> runner.libs.aws_remote_prep (AWS only) -> make __prepare-local -> executor -> runner.libs.execute_workspace -> runner.libs.suite_entrypoint`

What each layer owns:

- `Makefile`
  - thin public aliases
  - kernel build targets
  - the single `__prepare-local` entrypoint
  - includes `runner/mk/local_prep.mk` and `runner/mk/build.mk`
  - this is the only active Make-side control plane
  - no `runner/Makefile` second control plane
  - no ARM toolchain bootstrap target in the canonical run surface
- `run_target_suite.py`
  - per-run manifest and control directory
  - selects executor
  - runs remote prep before local prep for AWS
- `runner/mk/local_prep.mk`
  - the single local-prep orchestration layer
  - selects which build targets are needed by target/suite contract
- `runner/mk/build.mk`
  - concrete build recipes for daemon / runner / tests / repo artifacts
- `aws_remote_prep.py`
  - instance lifecycle
  - remote setup / reboot / prereq state
  - remote base prereqs via SSH shell only
  - no local build logic
- `aws_executor.py`
  - syncs selected fixed roots into the fixed remote stage root
  - uploads manifest
  - executes from the fixed remote stage root
  - fetches results
  - uploads the tracked helper `runner/libs/aws_remote_host.py`
- `kvm_executor.py`
  - launches local VM
  - runs the same repository workspace inside VM
- `suite_entrypoint.py`
  - runtime environment
  - launches suite drivers
  - collects result directories

## Deleted Architecture

The following are removed from the active path:

- old shell orchestration control planes
- bundle-cache logic
- versioned cache-key logic
- `RUN_BUNDLE*`
- `local-state` bundle handoff
- `workspace.tar.gz` bundle staging logic
- `runner/Makefile`
- Python build modules that owned concrete build recipes
- `runner.libs.aws_remote_prereqs`
- compat layers for upstream selftests

## Build Ownership

Concrete build logic now lives in the root `Makefile`, `runner/mk/*.mk`, and underlying repo-native build systems.

Examples:

- daemon: `daemon/Makefile`
- runner binary: CMake in `runner/`
- `micro/programs`: `micro/Makefile`
- repo tests: `tests/unittest/Makefile`, `tests/negative/Makefile`
- native repos:
  - `bcc`
  - `tracee`
  - `tetragon`
  - `katran`
  - `scx`

Python is no longer supposed to decide how those components compile.

## Source / Build / Install Rules

The design is:

- source trees stay in:
  - `vendor/*`
  - `runner/repos/*`
- build outputs are out-of-tree
- install/runtime outputs live under stable target-specific roots
- per-run state is small:
  - manifest
  - control state
  - results
- remote execution syncs selected fixed roots into a fixed remote workspace per suite
- there is no versioned bundle-cache layer

The canonical run path must not:

- compute user-visible cache keys
- maintain a separate versioned cache system

## What Still Needs Work

The remaining architecture debt is now narrower and explicit:

- build/install ownership must stay in `Makefile` / `runner/mk/*.mk` / repo-native build systems and not drift back into Python
- ARM toolchain prep must stay a single fixed out-of-tree root
  - canonical local prep only validates it
  - provisioning it is an explicit bootstrap step, not part of normal `corpus/e2e` runs
- Katran must stay on:
  - repo-native build from `runner/repos/katran`
  - original repo BPF build for `balancer.bpf.o`
  - original repo userspace server build for `katran_server_grpc`
  - no checked-in grpc helper bundle
- AWS remote transfer must stay explicit in the manifest:
  - suite config owns the base transfer roots
  - manifest carries `RUN_REMOTE_TRANSFER_ROOTS_CSV`
  - executor only consumes the contract
- prereq handling must stay single-plane:
  - no fake `required_commands(mode=...)`
  - guest base prereqs and bundled workload tools must not be mixed
  - if `corpus/e2e` transfer `.cache/workload-tools`, AWS remote-prep must not try to install `wrk/sysbench/hackbench`
- whole-tree review must keep checking that no second control plane, fallback path, or dead build surface reappears

Latest focused cleanup applied on the current tree:

- `RUN_REMOTE_TRANSFER_ROOTS_CSV` is now treated as a sealed contract
  - the executor no longer silently drops missing listed roots
  - missing listed roots are now fatal local-prep errors
- Tracee runtime no longer writes signatures under `e2e/cases/tracee/bin/signatures`
  - signatures now live under `RUN_REPO_ARTIFACT_ROOT/tracee/signatures`
- ARM build rules are moving onto a single validated toolchain plane in `runner/mk/build.mk`
  - `__repo-test-binaries-arm64`
  - `__native-repo-bcc-arm64`
  - `__native-repo-tracee-arm64`
  - `__native-repo-tetragon-arm64`
  now require the validated toolchain root instead of ambient ad hoc compiler fallback
- x86 KVM kernel builds are now serialized at `__kernel`
  - parallel `vm-corpus` / `vm-e2e` no longer race in the same x86 kernel tree

Current status:

- ARM cross toolchain root now comes from explicit non-active bootstrap target `make -f runner/mk/bootstrap.mk bootstrap-arm64-toolchain`
  - fixed output root: `runner/build-arm64/toolchain`
  - canonical local prep no longer provisions it
  - no persistent `toolchain-debs` tree
- libbpf runtime now comes from explicit Make targets:
  - `__libbpf-runtime-x86_64`
  - `__libbpf-runtime-arm64`
- ARM native repos no longer run as one big containerized prep step:
  - `tracee`
  - `tetragon`
  - `katran`
  - `bcc`
  now build on the host Make path
- Katran active path no longer uses:
  - `e2e/cases/katran/bin/katran_server_grpc`
  - `e2e/cases/katran/lib/*`
  Canonical path is now:
  - Make-built `runner/repos/katran/katran/lib/Makefile-bpf` output for `balancer.bpf.o`
  - repo-native `build_katran.sh` + top-level CMake output for `katran_server_grpc`
- `runner/Makefile` is gone from the active path
- `runner/docker/arm64-crossbuild.Dockerfile` and the old crossbuild-image target are gone from the active path
- `run` path clone/checkout logic is gone from active code; source roots are the tracked repo trees plus existing cached source/build trees
- `aws_executor.py` no longer hardcodes the remote transfer roots or tar excludes; those now come from manifest contract
- `required_commands()` no longer pretends to have separate base/runtime modes
- local prep fanout now lives only in `runner/mk/local_prep.mk`; Python just calls `make __prepare-local`
- BCC native repo prep now requires the vendored `bpftool`; there is no host `bpftool` fallback
- Katran runtime now resolves only:
  - `RUN_REPO_ARTIFACT_ROOT/katran/bin/katran_server_grpc`
  - `RUN_REPO_ARTIFACT_ROOT/katran/balancer.bpf.o`
- `suite_entrypoint` now resolves `scx` and `katran` artifacts only from explicit `RUN_REPO_ARTIFACT_ROOT`
- `suite_entrypoint` now resolves libbpf only from explicit `RUN_LIBBPF_RUNTIME_PATH`
- `execute_workspace` no longer bulk-exports manifest `RUN_*` scalars into runtime env
- app-runner helpers no longer read ambient `RUN_*` contract names directly; runtime-only env now uses explicit `BPFREJIT_*` names prepared by `suite_entrypoint`
- runtime no longer inherits host `LD_LIBRARY_PATH` into bundled benchmark execution
- `aws_executor.py` no longer creates a per-run `workspace.tar.gz`; it syncs selected fixed roots directly into `RUN_REMOTE_STAGE_DIR`
- guest runtime PATH now prepends:
  - `workspace/.cache/workload-tools/<arch>/bin`
  when present, before fixed guest system directories
  - there is no generic `workspace/.cache/workload-tools/bin` fallback anymore
- `hackbench`, `sysbench`, and `wrk` are now explicit bundled workload-tool artifacts for `corpus/e2e`
  - transferred via `SUITE_REMOTE_TRANSFER_ROOTS=.cache/workload-tools`
  - validated by Make targets:
    - `__workload-tools-x86_64`
    - `__workload-tools-arm64`
  - filtered out of AWS remote-prep package installation when bundled
- workload-tool source trees now come only from `runner/repos/workload-tools/*`
  - `.cache/workload-tool-sources` is no longer part of the active path
  - x86 workload tools now build from repo sources into:
    - `.cache/workload-tools-build/<arch>`
    - `.cache/workload-tools/<arch>`
  - there is no host-installed `hackbench/sysbench/wrk` fallback in active x86 prep
- app-runners no longer accept ambient runtime overrides for:
  - `BCC_TOOLS_DIR`
  - `TRACEE_BINARY`
  - `TETRAGON_BINARY`
  - `TETRAGON_BPF_LIB_DIR`
  - `KATRAN_SERVER_BINARY`
  - `KATRAN_SERVER_LIB_DIR`
- ARM sysroot bootstrap now lives outside the canonical control plane:
- `make -f runner/mk/bootstrap.mk bootstrap-arm64-toolchain`
  - output root: `runner/build-arm64/toolchain/.ready`
  - no `.cache/arm64-host/*` control plane
  - no inline cache-only short-circuit branch
  - active build targets now depend on `__require-arm64-toolchain`, which validates the fixed root instead of provisioning it
  - validated locally: `make -f runner/mk/bootstrap.mk bootstrap-arm64-toolchain` succeeds and materializes `runner/build-arm64/toolchain/usr/lib64/*`
- KVM kinsn modules are now normalized to the real `kernel_release` during Make-side prep; the executor no longer rewrites `.virtme_mods/lib/modules/0.0.0` at runtime
- KVM runtime kernel modules now come only from:
  - `RUN_KERNEL_MODULES_ROOT=.cache/repo-artifacts/x86_64/kernel-modules`
  - there is no `.virtme_mods` fallback in runtime code
- ARM `corpus/e2e` native repo prep no longer routes through a `linux/arm64` container
  - the remaining containerized path is only the arm64 runner binary for `micro`

The main remaining cleanup target is therefore:

- keep repo-managed runtime artifact roots explicit-only
- keep remaining workload/native-repo build recipes from drifting back out of Make-owned source/build/install roots
- keep `runner/mk/build.mk` from turning into a second ad hoc orchestration surface
- finish whole-tree review and only then restart `corpus/e2e`
- keep deleting source-tree/build-side intermediates that are not part of the final runtime contract

## Current TODO

1. keep deleting anything that is not part of the final control/data plane:
   - no deadcode
   - no fallback
   - no compat
   - no second control plane
2. keep deleting source-tree/build-side leftovers that are not part of the runtime contract
   - no `.cache/workload-tool-sources` active-path dependency
   - no checked-in Katran grpc bundle path
   - no old `corpus/build/<arch>` references in active docs/code
3. keep tightening the remaining architecture edges while the runtime matrix is running:
   - keep `RUN_REMOTE_TRANSFER_ROOTS_CSV` sealed
   - keep Tracee runtime on repo-artifact roots only
   - keep Katran on repo-native build only
   - keep workload tools on repo-source + build/install roots only
4. keep the fresh runtime matrix moving until all six paths pass:
   - `x86-kvm corpus`
   - `x86-kvm e2e`
   - `aws-x86 corpus`
   - `aws-x86 e2e`
   - `aws-arm64 corpus`
   - `aws-arm64 e2e`
5. keep pushing `corpus/e2e` toward “cache-hit means run, not rebuild”:
   - no per-run clone/checkout
   - no per-run heavy workspace staging
   - no rebuild when stable Make/CMake outputs are already warm
6. for each runtime failure:
   - capture the first real blocker
   - fix it without adding fallback/compat/new control planes
   - rerun the affected lane immediately

## Runtime Validation Goal

After architecture cleanup is clean and review passes, the runtime matrix to validate is:

- `x86-kvm corpus`
- `x86-kvm e2e`
- `aws-x86 corpus`
- `aws-x86 e2e`
- `aws-arm64 corpus`
- `aws-arm64 e2e`

The success rule is:

- all six paths run from the canonical path
- any runtime failure is fixed in-place
- no reintroduction of deleted control planes

## Current Runtime Status

Runtime reruns are active again on the current tree:

- `2026-04-09 12:26:32` fresh runtime matrix:
  - `x86-kvm`: `vm-corpus -> vm-e2e` single local sequence
  - `aws-x86 corpus`
  - `aws-x86 e2e`
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`

Recent runtime-relevant fixes already applied:

- `kernelrelease` no longer comes from `make kernelrelease`; artifact packaging now reads `include/config/kernel.release` directly for x86 and ARM.
- KVM kinsn modules no longer use the `vendor/linux-framework/.virtme_mods` staging tree.
  - Make-side prep now builds and installs them directly into `RUN_REPO_ARTIFACT_ROOT/kernel-modules`.
- ARM kernel artifact packaging now runs `modules_install CONFIG_MODULE_SIG=n`, so AWS ARM setup is no longer blocked by module signing failures in `bpf_preload.ko`.
- `corpus/e2e` now use a single guest runtime command contract plus an explicit bundled workload-tool root:
  - guest runtime discovers bundled tools through `workspace/.cache/workload-tools/<arch>/bin`
  - AWS remote-prep no longer tries to install `wrk/sysbench/hackbench` when `.cache/workload-tools` is part of transfer roots
- AWS remote base-prereq validation now uses a normalized remote PATH that includes `/usr/sbin` and `/sbin`.
  - this fixed the false `required command is missing: tc` failures on fresh AWS `corpus/e2e` runs
- current x86 Katran repo-native canary has already passed the previous Folly configure/compiler-flag crash.
  - the next active blocker is deeper in gRPC build/install and is being reduced from the current canary log
- ARM native repo prep for `bcc/tracee/tetragon/katran` now runs on the host Make path.
- ARM `scx` binaries now also run on the host Make path with an explicit ARM sysroot contract; the old `docker --platform linux/arm64` `scx` prep path is gone.
- ARM `corpus/e2e` no longer route native repo prep through an arm64 userspace container.
  - the remaining arm64 containerized path is the runner binary for `micro`
  - `corpus/e2e` themselves do not require `RUN_NEEDS_RUNNER_BINARY=1`
- `local_prep.mk` no longer encodes suite/target prep fanout with nested `if`/suite targets; target env files now declare `TARGET_LOCAL_PREP_TARGETS_<SUITE>` and the manifest just carries the explicit prep list.
- repo-managed runtime artifact roots are now explicit-only:
  - `RUN_REPO_ARTIFACT_ROOT` is required
  - there is no active-path fallback to `.cache/repo-artifacts/<arch>`
- BCC native repo prep no longer falls back to host `bpftool`.
- Katran runtime no longer carries the stale `lib`/`lib64` compat branch.
- bundled workload tools now use an explicit contract:
  - `SUITE_NEEDS_WORKLOAD_TOOLS=1` on `corpus/e2e`
  - `RUN_NEEDS_WORKLOAD_TOOLS` drives both local prep and guest prereq validation
  - the old implicit `RUN_REMOTE_TRANSFER_ROOTS_CSV contains .cache/workload-tools` control plane is gone
- `.cache/workload-tool-sources` is no longer part of the active path and has been removed locally.
- x86 Katran repo-native userland build now uses host `gcc/g++`; only BPF object build stays on `clang/llc`.
- kernel artifact tarballs now drop `lib/modules/<release>/{build,source}` before packaging.
  - this fixes the AWS ARM setup crash in `aws_remote_host.py` when Python `tarfile(filter="data")` rejects absolute symlinks
- Katran repo-native server build now requires C++20 explicitly on both x86 and arm64.
  - this fixes the current Folly `constinit` compile failure when building `katran_server_grpc`

The next runtime focus is:

- keep the current reruns moving while architecture review continues
- rerun any lane that started before a structural fix landed
- keep reducing runtime blockers one at a time until all six `corpus/e2e` lanes pass
- current live reruns:
  - `x86-kvm corpus`
  - `x86-kvm e2e`
  - `aws-x86 corpus`
  - `aws-x86 e2e`
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`
- current active structural/runtime cleanup just before these reruns:
  - `RUN_NEEDS_WORKLOAD_TOOLS` is now explicit in the manifest
  - the old implicit `RUN_REMOTE_TRANSFER_ROOTS_CSV contains .cache/workload-tools` control plane is gone
  - x86 Katran userland build switched from `clang/clang++` to `gcc/g++` to avoid the current gRPC/abseil compile failure on this host toolchain
  - `.cache/workload-tool-sources` was deleted locally and is no longer part of the active path
  - stale reruns that were still holding old x86 Katran build locks were terminated
  - the first arm64 rerun (`rerun5`) still reused a stale local setup artifact tar under `.cache/aws-arm64/setup-artifacts/arm64`
  - that tar still contained `lib/modules/<release>/build` as an absolute symlink, so remote safe extract failed with `tarfile.AbsoluteLinkError`
  - root `Makefile` now strips the `build` and `source` symlinks before packing the kernel modules tar
  - the stale arm64 setup artifact roots were deleted locally:
    - `.cache/aws-arm64/setup-artifacts/arm64`
    - `.cache/aws-arm64/setup-artifacts/7.0.0-rc2+`
  - fresh reruns are now:
    - `x86-kvm corpus`: `vm-corpus-20260409-rerun3.log`
    - `x86-kvm e2e`: `vm-e2e-20260409-rerun4.log`
    - `aws-x86 corpus`: `aws-x86-corpus-20260409-rerun5.log`
    - `aws-x86 e2e`: `aws-x86-e2e-20260409-rerun5.log`
    - `aws-arm64 corpus`: `aws-arm64-corpus-20260409-rerun6.log`
    - `aws-arm64 e2e`: `aws-arm64-e2e-20260409-rerun6.log`
  - the four AWS reruns are currently past launch and waiting in `aws_remote_prep` for `instance-status-ok`
  - the two KVM reruns are in `__prepare-local` behind the shared x86 kernel/local-prep path

## Current Todo

1. Whole-tree review on the current active path:
   - no dead/fallback/compat logic
   - no second control plane
   - `corpus/e2e` bundled workload-tool contract is coherent end-to-end
   - Tracee runtime uses only repo-artifact/workspace paths
   - ARM sysroot/toolchain is a single plane
2. Keep build/install/cache in Make-side control:
   - no Python build recipe re-growth
   - no `runner/Makefile`
   - no hidden shell orchestration path
   - no reintroduction of ARM container/qemu-only benchmark prep
3. Keep source/build/install roots explicit and minimal:
   - no run-path clone/fetch/checkout
   - no bundle-cache/version-cache control plane
   - no heavy per-run workspace staging
   - per-run state remains only manifest/control/results
4. Keep running and rerunning the full `corpus/e2e` matrix until all six paths pass:
   - `x86-kvm corpus`
   - `x86-kvm e2e`
   - `aws-x86 corpus`
   - `aws-x86 e2e`
   - `aws-arm64 corpus`
   - `aws-arm64 e2e`
5. Keep runtime blockers narrow and explicit:
   - no guest package fallback for bundled workload tools
   - no stale local setup artifact reuse after kernel packaging fixes
   - no reintroduction of checked-in Katran bundle or second Katran runtime path

## Review Gate

Current static gate:

- `python3 -m pyflakes runner/libs runner/mk corpus e2e`
- `python3 -m compileall -q runner/libs runner/mk corpus e2e`
- `git diff --check`
- active-path grep for runtime env mutation is clean:
  - no `prepare_bpftool_environment()`
  - no active `os.environ[...]` mutation in `corpus/e2e`
  - `BPFREJIT_BENCH_PASSES` is injected only by `suite_entrypoint`
- `make -n aws-x86-benchmark AWS_X86_BENCH_MODE=e2e`
- `make -n aws-x86-benchmark AWS_X86_BENCH_MODE=corpus`
- `make -n aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus`
- `make -n aws-arm64-benchmark AWS_ARM64_BENCH_MODE=e2e`
- `make -n vm-corpus`
- `make -n vm-e2e`

Note:

- that is documentation state, not the current runtime gate
- whole-tree reviewer re-check is in progress
- real `corpus/e2e` reruns are active in parallel; review is used to keep deleting architecture debt while runtime blockers are reduced

## Latest 2026-04-09 Runtime Status

- active path no longer references:
  - `runner/Makefile`
  - `make -C runner`
  - `__bundle-cache`
  - `prepared-workspace`
  - `workload-tool-sources`
- `runner/repos/workload-tools` is now the only active workload-tool source root.
- current repo-native Katran x86 build blocker has been reduced:
  - first failure was Folly `FOLLY_XLOG_STRIP_PREFIXES` being passed as an unquoted path macro
  - current `runner/mk/build.mk` overrides this through `CXXFLAGS` on the Katran build invocation
  - current standalone Katran x86 canary is no longer dying in Folly and is progressing through later dependencies (`gtest`, then `grpc`)
- current repo-native Katran x86 build now passes the previous `katran_server_grpc` C++20/Folly blocker.
  - the next shared blocker that was fixed was the staged BPF object path
  - repo-native Katran BPF outputs are under `deps/bpfprog/bpf/*.o`
  - active Make staging now copies from that actual output directory instead of the stale `deps/bpfprog/katran/lib/bpf/*.o` path
- current ARM blocker that was fixed:
  - `__kinsn-modules-arm64` now passes `ARM64_AWS_BASE_CONFIG` through to `__kernel-arm64-aws`
  - this removed the immediate local-prep crash in fresh AWS ARM64 `corpus/e2e` reruns

- current fresh reruns on the fixed tree:
  - `x86-kvm corpus`
  - `aws-x86 corpus`
  - `aws-x86 e2e`
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`

- new runtime blockers fixed before the current fresh reruns:
  - bundled workload tools are now explicit bundle contract, not guest-system fallback.
    - `guest_prereqs` now validates `hackbench/sysbench/wrk` directly under `workspace/.cache/workload-tools/<arch>/bin`
    - guest system `PATH` no longer counts as satisfying bundled-tool requirements
  - `corpus/e2e` remote transfer roots are no longer whole-tree copies.
    - `runner` is now transferred as `runner/__init__.py + runner/libs`
    - `corpus` is now transferred as `corpus/driver.py + corpus/config`
    - `e2e` is now transferred as `e2e/driver.py + e2e/cases`
    - this removes the previous `rsync` of `runner/repos/*` and old `corpus/e2e results/*` trees into the remote stage
  - `aws-x86 corpus/e2e` no longer transfer the whole `.cache/repo-artifacts/<arch>` tree to the remote instance.
    - manifests now transfer only the runtime subtrees actually needed by the selected suite (`bcc`, `tracee`, `tetragon`, `katran`, `scx`, `libbpf`, bundled workload tools)
    - this removes the old shared-instance `/var/tmp` exhaustion caused by repeatedly rsyncing full `kernel-modules`
  - the stale remote stage trees on the shared AWS instances were explicitly purged before the fresh reruns.
    - `aws-x86` recovered to `19G` free on `/var/tmp`
    - `aws-arm64` recovered to `28G` free on `/var/tmp`
  - `aws-arm64 corpus/e2e` no longer fail in local prep on `scx_rusty` linking with `-lelf`
    - `__scx-binaries-arm64` now uses the ARM sysroot/pkg-config/library/include contract explicitly
  - shared heavy prep targets now short-circuit inside their build locks instead of rebuilding on every run.
    - `bcc`
    - `tracee`
    - `tetragon`
    - `workload-tools x86`
    - `workload-tools arm64`
    - host `luajit`
  - `x86-kvm corpus` no longer uses broken x86 bundled workload wrappers
    - the portable `hackbench/sysbench/wrk` scripts now preserve runtime variables correctly
  - `x86-kvm corpus` kernel module staging now runs `depmod` and preserves `build/source` symlinks into the mounted workspace
    - this is required for `modprobe veth` and for bpftrace programs that need `/lib/modules/<release>/build/include/linux/kconfig.h`
  - all four AWS `corpus/e2e` reruns converged on the same shared runtime blocker:
    - `kernel bpf_stats_enabled sysctl is not writable`
    - `suite_entrypoint` now enables `kernel.bpf_stats_enabled=1` through `sudo sysctl` when not already root
    - this is now a shared contract fix instead of four target-specific failures
  - the next shared runtime blocker across AWS `corpus/e2e` was root-only module and bpftool operations.
    - `kinsn` module loading now uses `sudo insmod` when the suite is not already root
    - `bpftool -j -p prog show` now runs through `sudo` in shared runtime helpers instead of failing with `Operation not permitted`
  - the next shared `corpus` blocker across x86 and arm64 AWS was guest `libbpf` runtime incompatibility.
    - bundled host-built `libbpf.so` required guest-incompatible glibc symbols
    - shared runtime now prefers guest-native system `libbpf` and only uses an explicit bundled path when it is loadable

- current todo for the live matrix:
  1. keep all five fresh `corpus/e2e` reruns moving on the fixed tree until they either pass or expose the next real runtime blocker
  2. if x86 AWS still fails, capture the first fresh blocker from the new suite-specific remote stage and fix that shared contract
  3. if `x86-kvm corpus` still fails, keep fixing the shared runtime contract there before opening `x86-kvm e2e`
  4. once `corpus` is green on each target, keep `e2e` running on the same warmed/cached inputs rather than rebuilding
  5. continue deleting deadcode / fallback / second-control-plane drift while the reruns are active
