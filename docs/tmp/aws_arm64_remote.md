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
- no clone / checkout in the canonical run path
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
  - streams the repository workspace
  - uploads manifest
  - executes workspace remotely
  - fetches results
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
- there is no separate per-run workspace or tar-bundle layer
- there is no versioned bundle-cache layer

The canonical run path must not:

- clone repos
- checkout temporary source trees
- compute user-visible cache keys
- maintain a separate versioned cache system

## What Still Needs Work

The main remaining architecture debt is ARM benchmark prep.

Today:

- our own binaries and most local prep are Make-driven
- but ARM benchmark prep still has container / qemu-backed paths for some repo-native artifacts

That means the main remaining cleanup target is:

- move ARM benchmark artifact prep further toward Make-driven host-visible build roots
- keep Python as a thin caller only

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

Fresh live lanes are:

- `x86-kvm corpus`
- `aws-x86 corpus`
- `aws-x86 e2e`
- `aws-arm64 corpus`
- `aws-arm64 e2e`

Recent runtime fixes already applied:

- `kernelrelease` no longer comes from `make kernelrelease`; artifact packaging now reads `include/config/kernel.release` directly for x86 and ARM.
- KVM now clears `vendor/linux-framework/.virtme_mods` before each VM launch, so stale symlinks no longer abort `vm-corpus`.
- ARM kernel artifact packaging now runs `modules_install CONFIG_MODULE_SIG=n`, so AWS ARM setup is no longer blocked by module signing failures in `bpf_preload.ko`.

The current runtime focus remains:

- get `x86-kvm corpus` green
- let `aws-x86 corpus/e2e` finish on the repaired x86 kernel artifact path
- let `aws-arm64 corpus/e2e` finish on the repaired ARM kernel artifact path
- only then start `x86-kvm e2e`

## Current Todo

1. Delete the tracked `runner/Makefile` permanently and keep `runner/mk/*.mk` as the only Make-side auxiliary surface.
2. Remove any remaining direct build recipe from Python if one still exists in active code.
3. Keep deleting old/dead Make / Python / shell control surfaces instead of layering replacements.
4. Finish ARM benchmark prep cleanup so `corpus/e2e` no longer depend on avoidable qemu-heavy build steps.
5. Re-run whole-tree review and require a clean findings / no-findings result on the current active path.
6. Then run the full `corpus/e2e` matrix.


## Live Status 2026-04-09 00:11

Current fresh live benchmark lanes:
- aws-x86 corpus: `run.aws-x86.corpus.8ab8ea71` (front session 78354)
- aws-x86 e2e: `run.aws-x86.e2e.4bfb4857`
- aws-arm64 corpus: `run.aws-arm64.corpus.0fad18a2`
- aws-arm64 e2e: `run.aws-arm64.e2e.baecb423`

Notes:
- `aws_executor.py` now streams only selected top-level directories instead of tarring the entire repo root.
- Current tree still uses guest package manager for workload tools (`stress-ng/fio/hackbench/sysbench/bpftrace/wrk/tc`); there is no active bundled workload-tool build path in `runner/mk/build.mk`.
- Old ARM `sudo` logs from stale runs should not be treated as current blockers.


## Live Status 2026-04-09 00:20

Fresh active lanes after shared bundle fix:
- aws-x86 corpus: `run.aws-x86.corpus.36b2aa39`
- aws-x86 e2e: `run.aws-x86.e2e.8e2d285f`
- aws-arm64 corpus: `run.aws-arm64.corpus.245b78ac`
- aws-arm64 e2e: `run.aws-arm64.e2e.e9b50dec`

Shared bug fixed in this round:
- `aws_executor.py` no longer allows `runner/repos/**` into the streamed AWS workspace bundle. The previous behavior raced against live repo builds and failed with `tar: File removed before we read it`.

Runtime note:
- A previous `aws-arm64 e2e` rerun failed with `VcpuLimitExceeded`. Four stale dedicated benchmark instances were terminated before starting the fresh `e9b50dec` rerun.

## Live Status 2026-04-09 00:28

Fresh current-code lanes now in flight:
- `aws-x86 corpus`: `run.aws-x86.corpus.472ecfb8`
- `aws-x86 e2e`: `run.aws-x86.e2e.5015db3a`
- `aws-arm64 corpus`: `run.aws-arm64.corpus.e39b65dc`
- `aws-arm64 e2e`: `run.aws-arm64.e2e.e6061297`
- `x86-kvm e2e`: `run.x86-kvm.e2e.936e8dca`

New runtime findings from the previous round:
- `aws-x86 e2e` hit a new workspace streaming race:
  - `tar: e2e/cases/katran/lib/liblzma.so: File removed before we read it`
  - root cause: repo-tree Katran helper artifacts under `e2e/cases/katran/bin|lib` were still present in the streamed AWS workspace even though runtime uses the bundled `corpus/build/<arch>/katran` artifacts
- both old ARM lanes (`245b78ac`, `e9b50dec`) confirmed the same repaired-arm setup bug:
  - `bash: line 7: /usr/bin/sudo: cannot execute: required file not found`
  - these failures happened before the new `aws_remote_prep.py` module-install fix was applied

Fixes applied before the current reruns:
- `aws_executor.py` now excludes `e2e/cases/katran/bin/*` and `e2e/cases/katran/lib/*` from streamed AWS workspaces
- `aws_remote_prep.py` no longer untars module artifacts directly into `/`; it now extracts into a temporary directory and copies only `lib/modules/<release>` into `/lib/modules/<release>`

Live evidence after the fix:
- `aws-arm64 e2e` has already progressed past the old immediate `sudo` failure point and is actively uploading `vmlinuz-7.0.0-rc2+.efi` and `modules-7.0.0-rc2+.tar.gz`
- all four AWS corpus/e2e lanes are running on dedicated benchmark-sized instances:
  - x86: `t3.large`
  - arm64: `t4g.large`

## Live Status 2026-04-09 00:40

Fresh runtime findings from the current round:
- the old `aws-x86 corpus` result `36b2aa39` was still failing in guest prereqs with:
  - `No match for argument: rt-tests`
  - `No match for argument: wrk`
  - `required guest command is missing: tc`
- root cause was not a missing guest package on fresh runs; it was a shared contract bug:
  - bundled workload tools already live under `workspace/.cache/workload-tools/bin`
  - but `guest_prereqs.runtime_path_value()` only searched system directories, so runtime provisioning kept trying to install `wrk` / `hackbench` instead of seeing the bundled copies
  - `dnf` mapping for `tc` was also wrong for AL2023; it pointed to `iproute-tc` instead of `iproute`

Fixes applied in this round:
- `guest_prereqs.py` now prepends `workspace/.cache/workload-tools/bin` to runtime `PATH`
- `prereq_contract.py` now maps `dnf + tc` to `iproute`

## Live Status 2026-04-09 00:48

New x86 parallel-runtime finding:
- fresh `aws-x86 e2e` run `5015db3a` progressed past the old Katran helper tar race, but failed later with:
  - `tar: corpus/build: file changed as we read it`
- root cause: `aws-x86 corpus` and `aws-x86 e2e` were sharing the same mutable `corpus/build/x86_64` tree
  - one lane was still rewriting stage files while the other lane streamed the workspace to AWS

Fixes applied in this round:
- `runner/mk/build.mk` now uses per-arch/per-repo host locks under `.cache/.../locks`
- shared `scx`, `bcc`, `tracee`, `tetragon`, and `katran` stage targets no longer `rm -rf` the shared stage roots on each invocation
- those stage targets now only overwrite staged files when the source content actually changed

Current fresh active lanes:
- `aws-x86 corpus`: `run.aws-x86.corpus.472ecfb8`
- `aws-x86 e2e`: `run.aws-x86.e2e.32840fdd`
- `aws-arm64 corpus`: `run.aws-arm64.corpus.c8300251`
- `aws-arm64 e2e`: `run.aws-arm64.e2e.0b0e2a77`
- `x86-kvm e2e`: `run.x86-kvm.e2e.936e8dca`
