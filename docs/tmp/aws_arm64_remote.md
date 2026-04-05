# AWS Remote And Runner Refactor

Last updated: 2026-04-04

## 1. Purpose

This document is the single source of truth for:

- the runner refactor shape
- the current AWS ARM64 / AWS x86 / local x86 KVM entrypoints
- the important problems found while refactoring
- the ordered todo list that must be completed before full validation is considered done

This document intentionally combines:

- design
- progress log
- open issues

The goal is to keep one precise record instead of multiple drifting notes.

## 2. Product Goal

The desired end-state is:

- one canonical root-`Makefile` entrypoint family
- one target/suite contract
- one manifest-driven bundle path
- two executors only:
  - `kvm`
  - `aws-ssh`

The concrete supported targets are:

- `x86-kvm`
- `aws-x86`
- `aws-arm64`

The concrete suites are:

- `test`
- `micro`
- `corpus`
- `e2e`

The user-facing entrypoints remain:

- `make vm-test`
- `make vm-micro`
- `make vm-corpus`
- `make vm-e2e`
- `make aws-arm64-test`
- `make aws-arm64-benchmark`
- `make aws-arm64-terminate`
- `make aws-x86-test`
- `make aws-x86-benchmark`
- `make aws-x86-terminate`

These aliases must stay thin.

## 3. Non-Goals

Out of scope:

- local ARM64 QEMU as a product path
- patching third-party source trees
- duplicate result mirrors such as `latest.json` or `authoritative.json`
- a large orchestration framework with many helper layers
- dynamic fallback behavior when a required artifact or dependency is missing

## 4. Current In-Tree Shape

### 4.1 New contract files

The refactor now centers on:

- `runner/targets/aws-arm64.env`
- `runner/targets/aws-x86.env`
- `runner/targets/x86-kvm.env`
- `runner/suites/test.env`
- `runner/suites/micro.env`
- `runner/suites/corpus.env`
- `runner/suites/e2e.env`
- `runner/scripts/load_run_contract.sh`
- `runner/scripts/run_target_suite.sh`
- `runner/scripts/prepare_run_inputs.sh`
- `runner/scripts/kvm_executor.sh`
- `runner/scripts/aws_executor.sh`
- `runner/scripts/build_remote_bundle.sh`
- `runner/scripts/aws_remote_prereqs.sh`
- `runner/scripts/suite_entrypoint.sh`
- `runner/scripts/build-arm64-test-artifacts.sh`
- `runner/scripts/build_upstream_selftests.sh`
- `runner/compat/upstream_selftests/*`

For canonical local x86 execution, the manifest now carries explicit VM execution
fields instead of translating back to legacy machine profile names:

- `RUN_VM_BACKEND`
- `RUN_VM_EXECUTABLE`
- `RUN_VM_LOCK_SCOPE`
- `RUN_VM_MACHINE_NAME`
- `RUN_VM_MACHINE_ARCH`
- `RUN_VM_CPUS`
- `RUN_VM_MEM`
- `RUN_SUITE_ENTRYPOINT`

For canonical AWS execution, the manifest now also carries the resolved local
AWS launch contract instead of making `aws_executor.sh` branch on target names:

- `RUN_AWS_KEY_NAME`
- `RUN_AWS_KEY_PATH`
- `RUN_AWS_SECURITY_GROUP_ID`
- `RUN_AWS_SUBNET_ID`

The manifest also declares the shared suite entrypoint itself:

- `RUN_SUITE_ENTRYPOINT`

### 4.2 ARM kernel config split

ARM kernel config now has:

- one shared repo-owned fragment:
  - `runner/scripts/arm64_kernel_config_common.sh`
- one local-QEMU-specific script:
  - `runner/scripts/arm64-kernel-config.sh`
- one AWS-specific script:
  - `runner/scripts/aws_arm64_kernel_config.sh`

This removes the duplicated repo-required BPF/tracing option block.

### 4.3 Root `Makefile` state

The root `Makefile` now routes the main suite targets through the new contract:

- `vm-test` -> `run_target_suite.sh run x86-kvm test`
- `vm-micro` -> `run_target_suite.sh run x86-kvm micro`
- `vm-corpus` -> `run_target_suite.sh run x86-kvm corpus`
- `vm-e2e` -> `run_target_suite.sh run x86-kvm e2e`
- `aws-arm64-test` -> `run_target_suite.sh run aws-arm64 test`
- `aws-arm64-benchmark` -> sequential `micro|corpus|e2e` dispatch based on `AWS_ARM64_BENCH_MODE`
- `aws-arm64-terminate` -> `run_target_suite.sh terminate aws-arm64`
- `aws-x86-test` -> `run_target_suite.sh run aws-x86 test`
- `aws-x86-benchmark` -> sequential `micro|corpus|e2e` dispatch based on `AWS_X86_BENCH_MODE`
- `aws-x86-terminate` -> `run_target_suite.sh terminate aws-x86`

The canonical flow is now:

- `run_target_suite.sh` writes the manifest
- local KVM runs perform host-side build work via `prepare_run_inputs.sh`
- AWS runs perform machine prep first, then explicit local bundle preparation, then invoke one shared suite entrypoint
- the suite behavior itself lives in:
  - `runner/scripts/suite_entrypoint.sh`

For AWS runs, local bundle preparation is not a separate public action.
It remains an internal explicit step of `aws_executor.sh run` after machine and
kernel readiness are established.

The canonical run manifest is now immutable after creation.
Local-only bundle staging inputs are passed to `build_remote_bundle.sh` through
the executor process environment and are not appended back into
`run-contract.env`.

AWS launch parameters now also follow the same rule:

- the manifest carries the resolved SSH/AWS launch contract
- `aws_executor.sh` no longer falls back to cached key/subnet/security-group state
- target-specific AMI overrides must be represented in the manifest, not through
  a generic ambient `AWS_AMI_ID`
- guest-side Python selection is part of the manifest contract; executors do not
  inject `PYTHON_BIN` out-of-band
- AWS region/account selection is part of the manifest contract through
  `RUN_AWS_REGION` and `RUN_AWS_PROFILE`, with explicit `AWS_PROFILE` required for
  canonical AWS runs

### 4.4 Deleted legacy AWS control scripts

The old AWS monoliths and ARM64-specific helper chain have been deleted:

- `runner/scripts/aws_arm64.sh`
- `runner/scripts/aws_x86.sh`
- `runner/scripts/aws_arm64_bundle.sh`
- `runner/scripts/aws_arm64_manifest.sh`
- `runner/scripts/aws_arm64_remote_prereqs.sh`
- `runner/scripts/aws_arm64_remote_suite.sh`

### 4.5 Machine config cleanup

The legacy machine-table layer has been removed completely:

- `runner/machines.yaml` is deleted
- `runner/libs/machines.py` is deleted
- `runner/scripts/run_vm_shell.py` no longer accepts `--target`
- `runner/scripts/with_vm_lock.py` no longer resolves target aliases

The canonical `x86-kvm` path now carries its full machine contract directly in
the manifest:

- backend
- executable
- lock scope
- machine name
- machine arch
- cpu/memory sizing
- host Python launcher
- guest kernel image path
- suite timeout
- test-only knobs such as `FUZZ_ROUNDS` and `scx_prog_show_race_*`

`runner/scripts/kvm_executor.sh` passes that explicit contract into
`runner/scripts/run_vm_shell.py`.

`runner/Makefile` no longer exposes a second live `vm-test/vm-micro/vm-corpus/vm-e2e`
execution plane. The remaining direct runner targets are debug-only helpers
that still consume explicit `VM_*` variables:

- `vm-shell`
- `vm-selftest`
- `vm-negative-test`
- `vm-micro-smoke`

Canonical KVM suite execution now also performs an explicit guest-side prereq
validation step before entering the shared suite entrypoint:

- `runner/scripts/validate_guest_prereqs.sh`

## 5. Hard Constraints

These rules are now mandatory:

- Do not patch third-party source trees:
  - `vendor/linux-framework/**`
  - `runner/repos/**`
- Do not keep multiple control paths for the same target/suite pair.
- Do not silently fall back to a different artifact or environment shape.
- Do not let stale `.cache` contents leak into bundles outside the manifest-selected artifact set.
- Do not write bundled benchmark assets into machine-global locations on the remote host.
- Do not let cached AWS instance metadata act as a fallback control plane for
  required launch parameters.
- Do not proactively close reviewer subagents just because they are slow.
  Reviewer agents should be allowed to run longer unless the user explicitly
  asks to stop them or they have already produced a final result.
- For full-project review passes, do not reduce scope just because the reviewer is taking longer than expected.
  The default behavior is to wait longer and preserve full context.

## 6. Problems Already Removed

The refactor has already removed these specific problems:

- AWS-specific suite policy living in a giant target-specific script
- separate AWS ARM64 bundle/prereq/remote-suite helper chain
- root `Makefile` dependence on positional `INSTANCE_IP` / `INSTANCE_ID`
- direct third-party source patching for Katran and upstream selftests
- duplicated ARM repo-required kernel config block
- `tetragon` strict bundled mode writing `.bpf.o` payloads into `/usr/local/lib/tetragon/bpf`
- the entire `runner/machines.yaml` / `runner.libs.machines` compatibility layer
- executor-specific suite logic split between KVM `vm-*` targets and AWS remote script entrypoints
- `runner/Makefile` carrying a second live `vm-test/vm-micro/vm-corpus/vm-e2e` execution plane
- root `validate` bypassing the canonical target/suite layer for VM micro smoke
- remote execution silently falling back from `python3.11` to `python3`
- requested remote workload tools being treated as optional installs
- AWS launch silently reusing cached key/subnet/security-group metadata outside the manifest
- generic ambient `AWS_AMI_ID` overriding the target-selected AMI outside the manifest
- bundle assembly copying the repo-root `module/` tree wholesale
- setup-script split between repo-managed artifact mode and fallback local-build mode for BCC / Tracee / Tetragon
- bundle assembly copying repo-owned source trees with broad directory copies instead of tracked-only snapshots
- Tracee runner picking up ambient `corpus/build/tracee` state before running setup
- Katran native staging picking up ambient `e2e/cases/katran/{bin,lib}` state without an explicit caller contract
- Tetragon runner picking up ambient `corpus/build/tetragon/bin/tetragon` state without setup or explicit parameters
- AWS ARM64 upstream selftests being compiled on the remote instance during `test`
- upstream selftest compatibility headers / stubs being embedded in the remote execution script
- corpus / case-common silently manufacturing per-program REJIT records when the daemon result omitted them

## 7. Remaining Design Gaps

The refactor is not finished yet.

### 7.1 `runner/scripts/aws_executor.sh` is still large

The new shape is better than the deleted monoliths, but `aws_executor.sh` still owns:

- AWS lifecycle
- state management
- kernel setup
- local artifact preparation
- bundle upload/run/fetch

This is better than before because suite behavior itself now lives in the shared
`suite_entrypoint.sh`, and host-side build/stage work is triggered explicitly
through `prepare_run_inputs.sh`. But the AWS executor is still larger than it
should be and needs another shrinking pass.

### 7.2 Third-party build compatibility still exists in isolated local builders

The remaining third-party compatibility handling is now isolated to local build
steps, not remote execution or source-tree patching:

- `runner/scripts/build_upstream_selftests.sh` still injects repo-owned
  compatibility assets from `runner/compat/upstream_selftests/*` into the
  *output directory* when building ARM64 upstream selftests locally
- `runner/scripts/build_corpus_native.py` still builds some `bpftrace`
  stdlib objects against a build-local filtered `vmlinux.h` compatibility
  header when the cached header contains declarations that collide with the
  checked-out third-party source

This is much cleaner than patching tracked third-party trees, but it is still
design debt and should be reviewed explicitly.

### 7.3 Manifest strictness still needs validation

The new flow now creates a per-run staged workspace before execution.
The staged bundle path is executor-local state and is not recorded back into the
canonical manifest.

However this still needs validation under real runs to prove:

- no stale `.cache/aws-arm64/binaries/*` outputs leak into unrelated suites
- no missing selected artifact is silently replaced by a system-installed equivalent

### 7.4 Direct runner debug paths now use explicit VM variables

The debug boundary is now:

- canonical product paths use `target + suite -> manifest -> executor`
- direct `make -C runner vm-*` uses explicit `VM_BACKEND/VM_EXECUTABLE/VM_LOCK_SCOPE/VM_MACHINE_*`

The old target-alias layer is gone; there is only one KVM machine contract path.

## 8. Tetragon Contract Change

`tetragon` strict bundled mode no longer installs `.bpf.o` files into `/usr/local/lib/tetragon/bpf`.

The new contract is:

- `e2e/cases/tetragon/setup.sh` resolves a bundled BPF directory
- it reports `TETRAGON_BPF_LIB_DIR=...`
- `runner/libs/app_runners/tetragon_support.py` parses that field
- `runner/libs/app_runners/tetragon.py` adds `--bpf-lib <dir>` when starting Tetragon

This keeps Tetragon on workspace-local assets.

## 9. Ordered Todo List

This is the required order from this point onward.

### 9.1 Finish refactor cleanup

1. Static-check the new shell scripts and any touched Python modules.
2. Verify there are no remaining repo-tracked references to the deleted AWS monoliths in active code paths.
3. Review the new `aws_executor.sh` / `build_remote_bundle.sh` / `suite_entrypoint.sh` contract for unnecessary coupling.

### 9.2 Review before testing

1. Run subagent review on the current refactor shape only.
2. Fix review findings.
3. Do not start AWS/KVM runtime validation until that review pass is complete.

### 9.3 Validation order after review

1. `make aws-arm64-test`
2. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=micro`
3. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus`
4. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=e2e`
5. `make aws-x86-test`
6. `make aws-x86-benchmark AWS_X86_BENCH_MODE=micro`
7. `make aws-x86-benchmark AWS_X86_BENCH_MODE=corpus`
8. `make aws-x86-benchmark AWS_X86_BENCH_MODE=e2e`
9. `make vm-test`
10. `make vm-micro`
11. `make vm-corpus`
12. `make vm-e2e`

Performance suites must remain serialized.

## 10. Current Progress Log

### 10.1 Completed in this refactor round

- Introduced target profiles and suite plans.
- Added generic contract loader and entrypoint.
- Added explicit host-side KVM preflight via `prepare_run_inputs.sh`.
- Added `kvm` and `aws-ssh` executors.
- Rewired canonical root targets to the new contract.
- Deleted the legacy AWS ARM64/x86 monoliths.
- Removed the old AWS ARM64 helper-chain files.
- Replaced executor-specific suite entrypoints with one shared `suite_entrypoint.sh`.
- Made AWS local bundle preparation explicit before remote suite invocation, while
  keeping AWS machine/kernel setup ahead of ARM64 artifact preparation.
- Tightened bundle assembly so repo-owned source trees are staged from tracked
  files only, reducing untracked-file leakage into remote bundles.
- Removed the last hardcoded KVM `e2e` host setup path; KVM preflight now
  consumes only manifest-selected repos and native artifacts.
- Removed the duplicate runner-local `vm-test/vm-micro/vm-corpus/vm-e2e`
  execution plane; canonical KVM execution now lives only at the root target layer.
- Removed root-`Makefile` AWS machine defaults so target profiles are now the
  only source of truth for AWS launch and remote-stage defaults.
- Made AWS x86 test bundles consume explicit staged unittest/negative/upstream
  selftest inputs instead of ambient repo-root build directories.
- Slimmed AWS remote prereq installation and verification down to execution-host
  requirements; remote build-toolchain installation is no longer canonical.
- Stopped mutating the canonical AWS run manifest with local bundle paths; the
  executor now passes local-only staging inputs as process-local environment.
- Removed cached-state fallback for AWS key/subnet/security-group launch
  parameters; launch now fails unless the manifest already carries the full
  required AWS contract.
- Moved target-specific AMI override handling into the manifest contract via
  `RUN_AMI_ID`; ambient generic `AWS_AMI_ID` no longer bypasses the target layer.
- Added AWS instance-type reuse checks so cached/tagged instances that do not
  match the requested target contract are terminated and relaunched.
- Stopped bundling untracked module build output from the repo root; the remote
  bundle now stages the tracked `module/` tree plus the explicit selected built
  kinsn module directory for the target arch.
- Stopped reading the KVM host Python launcher, guest kernel image path, suite
  timeout, and test knobs from ambient executor state; canonical KVM execution
  now consumes those values from the manifest.
- Moved guest-side Python selection into `RUN_REMOTE_PYTHON_BIN`; KVM and AWS
  now use the same manifest-written interpreter contract instead of executor-side
  `PYTHON_BIN` injection.
- Moved AWS region/profile into the manifest and stopped resolving them from the
  executor host shell after manifest creation.
- Tightened AWS instance reuse so existing instances are reused only when the
  manifest-selected AMI/key/subnet/security-group contract still matches exactly.
- Extended AWS terminate manifests to carry the name-tag/region/profile contract,
  so `aws-*-terminate` no longer depends on ambient AWS CLI state.
- Moved native corpus vendor `bpftool` builds under the active build root instead
  of sharing repo-root `runner/build/vendor/bpftool`.
- Tightened AWS remote prereqs so Python/bpftool provisioning is driven by the
  explicit manifest runtime contract rather than a second hardcoded policy.
- Replaced repo-root module build outputs in canonical AWS bundle assembly with
  explicit staged `.ko` directories.
- Removed the last hardcoded `FUZZ_ROUNDS` / `scx_prog_show_race_*` fallback in
  `runner/scripts/run_all_tests.sh`; canonical test execution now consumes the
  manifest-written test contract end to end.
- Replaced shell-string `RUN_CORPUS_ARGS` / `RUN_E2E_ARGS` reconstruction with
  manifest argv arrays (`RUN_CORPUS_ARGV` / `RUN_E2E_ARGV`) parsed via `shlex`.
- Tightened AWS remote prereqs so unknown workload-tool tokens fail immediately
  instead of being ignored until later runtime failure.
- Moved ARM64 cross-build roots under repo-local cache paths instead of shared
  `/tmp/codex/...` directories.
- Added explicit KVM guest-side prereq validation before suite execution.
- Restored the old `vm-corpus` default sample semantics in the manifest layer:
  `VM_CORPUS_SAMPLES` remains the canonical default unless `SAMPLES` is
  explicitly overridden.
- Extracted shared ARM kernel config.
- Removed Tetragon’s machine-global bundled BPF install path.
- Made canonical `x86-kvm` a single explicit-machine-contract VM target with no
  legacy target alias layer underneath.
- Moved AWS ARM64 upstream selftests from remote build time to local
  prebuild-and-bundle time.
- Removed silent per-program REJIT fallback synthesis from `runner/libs/case_common.py`
  and `corpus/driver.py`.
- Removed Tetragon ambient binary fallback to `corpus/build/tetragon/bin/tetragon`.
- Removed the Tracee output-style compatibility branch; the runner now uses the
  repo-managed Tracee `json:` output contract directly.
- Removed the bpftrace `usdt` stdlib temporary-source rewrite; bpftrace now
  uses a build-local `vmlinux.h` contract instead.
- Removed the fallback local-build branches from BCC / Tracee / Tetragon setup scripts.
- Updated `runner/Makefile` `e2e-prep` so repo-managed native E2E artifacts are
  prepared explicitly instead of relying on setup-script fallback behavior.
- Deleted `runner/machines.yaml` and `runner/libs/machines.py`, removing the
  last legacy target-alias VM control plane.
- Removed `--target` support from `runner/scripts/run_vm_shell.py` and
  `runner/scripts/with_vm_lock.py`; both now consume only explicit machine data.
- Removed the dead `SUITE_NEEDS_DAEMON` knob from suite definitions.
- Removed the stale `runner.libs.vm.build_vm_shell_command()` compatibility
  helper and its test-only usage.
- Revalidated the explicit-machine-only KVM path with `python3 -m py_compile`
  on the touched VM helpers and `pytest -q tests/python/test_vm.py
  tests/python/test_case_common.py tests/python/test_corpus_driver.py
  tests/python/test_rejit.py` (`46 passed`).

### 10.2 Intentionally not done yet

- No full AWS ARM64 validation run after this refactor yet.
- No full AWS x86 validation run after this refactor yet.
- No full x86 KVM validation run after this refactor yet.
- No claim of green status should be made until the review pass and ordered validation pass complete.

## 11. Open Questions To Resolve In Review

The subagent review should focus on these points:

- Is `aws_executor.sh` still carrying target/suite policy that should live in the manifest instead?
- Is any remaining path still relying on ambient environment instead of explicit manifest data?
- Is bundle assembly truly manifest-driven, or are there still stale-output leak paths?
- Is any remote suite path still mutating machine-global state outside kernel install / package prereqs?
- Is the new x86 KVM wiring through `kvm_executor.sh` thin and correct, or does it still preserve too much old special-casing?
- Is the remaining third-party build compatibility handling
  (`suite_entrypoint.sh`, `build_corpus_native.py`) the minimum necessary shape, or
  can it be reduced further without reintroducing source patching or remote
  native build?

## 12. Known Historical Context

The minimal already-pushed bug-fix commit that stays independent from this large refactor is:

- `4ae9df0 Fix bundled tool resolution and portable hotswap tests`

That commit is not the runner refactor.
It remains valid and separate.
